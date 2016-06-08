//
//  Trie.h
//  HiC++
//
//  Created by My AD on 5/16/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef Trie_h
#define Trie_h

#include <iostream>
#include <unordered_map>
#include <map>

class TrieNode {
public:
    char charValue;
    map<char,TrieNode*> child;
    bool isEnd;
    bool hasChild;
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
        hasChild = false;
    }
    TrieNode(char ch) {
        charValue = ch;
        isEnd = false;
        hasChild = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* head = root;
        for(int i = 0; i < word.length(); i++) {
            if(head->child[word[i]] == NULL) {
                TrieNode* ch = new TrieNode(word[i]);
                head->child[word[i]] = ch;
            }
            head->hasChild = true;
            head = head->child[word[i]];
            if(i == word.length() - 1) head->isEnd = true;
        }
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* head = root;
        for(int i = 0; i< word.length(); i++) {
            if(head->child[word[i]] == NULL) return false;
            if(head->isEnd && (i < word.length() - 1)) {
                if(head->hasChild) {
                    head = head->child[word[i]];
                    continue;
                }
                return false;
            }
            head = head->child[word[i]];
        }
        if(head->isEnd == false) return false;
        return true;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* head = root;
        for(int i = 0; i< prefix.length(); i++) {
            if(head->child[prefix[i]] == NULL) return false;
            if(head->isEnd && (i < prefix.length() - 1)) {
                if(head->hasChild) {
                    head = head->child[prefix[i]];
                    continue;
                }
                return false;
            }
            head = head->child[prefix[i]];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

/*//////////////////////////////////////////////////////////////////////////////////////////
 class TrieNode {
 private:
 char charValue;
 map<char,TrieNode*> child;
 bool isEnd;
 bool hasChild;
 public:
 // Initialize your data structure here.
 TrieNode() {
 isEnd = false;
 hasChild = false;
 }
 TrieNode(char ch) {
 charValue = ch;
 isEnd = false;
 hasChild = false;
 }
 void setChild(TrieNode* chl, char childValue) {
 child[childValue] = chl;
 hasChild = true;
 }
 bool getChild(char childValue) {
 if(child[childValue] == NULL) return false;
 return true;
 }
 TrieNode* getChildNode(char childValue) {
 return child[childValue];
 }
 bool setEnd() {
 isEnd = true;
 return isEnd;
 }
 bool getEnd() {
 return isEnd;
 }
 bool hasChildBehind() {
 return hasChild;
 }
 };
 
 class Trie {
 public:
 Trie() {
 root = new TrieNode();
 }
 
 // Inserts a word into the trie.
 void insert(string word) {
 TrieNode* head = root;
 for(int i = 0; i < word.length(); i++) {
 if(head->getChildNode(word[i]) == NULL) {
 TrieNode* ch = new TrieNode(word[i]);
 head->setChild(ch,word[i]);
 head = ch;
 if(i == word.length() - 1) ch->setEnd();
 } else {
 head = head->getChildNode(word[i]);
 if(i == word.length() - 1) head->setEnd();
 }
 }
 }
 
 // Returns if the word is in the trie.
 bool search(string word) {
 TrieNode* head = root;
 for(int i = 0; i< word.length(); i++) {
 if(head->getChild(word[i]) == false) return false;
 if(head->getEnd() && (i < word.length() - 1)) {
 if(head->hasChildBehind()) {
 head = head->getChildNode(word[i]);
 continue;
 }
 return false;
 }
 head = head->getChildNode(word[i]);
 }
 if(head->getEnd() == false) return false;
 return true;
 }
 
 // Returns if there is any word in the trie
 // that starts with the given prefix.
 bool startsWith(string prefix) {
 TrieNode* head = root;
 for(int i = 0; i< prefix.length(); i++) {
 if(head->getChild(prefix[i]) == false) return false;
 if(head->getEnd() && (i < prefix.length() - 1)) {
 if(head->hasChildBehind()) {
 head = head->getChildNode(prefix[i]);
 continue;
 }
 return false;
 }
 head = head->getChildNode(prefix[i]);
 
 }
 return true;
 }
 
 private:
 TrieNode* root;
 };
 
 *//////////////////////////////////////////////////////////////////////////////////////////


#endif /* Trie_h */
