//
//  main.cpp
//  HiC++
//
//  Created by My AD on 5/27/15.
//  Copyright (c) 2015 My AD. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include <stack>
#include <fstream>
#include "main.h"
#include "sketch.h"
#include "Trie.h"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << " This is the test for C++ project coding in XCode! Seems it works!";
    cout << "Hello, World!\n";
        cout << " Please input your choice"<<endl;
    char CH;
    cin >> CH;
    //check(CH);
    
    switch (CH) {
        case '1':{
            string s = "A";
            int len = s.length();
            if(!len) return 0;
            int col = 0;
            for(char c : s) {
                col += (c - 'A' + 1) * 26 + c - 'A' + 1;
            }
            cout << col << endl;
            break;
        }
        case '3':{
            char* inputStr = new char[255];
            cout << " Please input a string:" << endl;
            cin >> inputStr;
            pointer(inputStr);
            break;
        }
        case '4':{
            StrMan();
            break;
        }
        case '5':{
            char* inputStr = new char[255];
            cout << "please input a string to calculate:" << endl;
            cin >> inputStr;
            //            Cal(in);
            double R;
            R = Add_Min(inputStr);
            cout << "Result = " << R << endl;
            break;
        }
        case '6':{
            string *pstr1 = new string ("Hello");
            cout << "Length of Hello is " << pstr1->length() << endl;
            string str = "Hello";
            cout << "Length of str is " << str.length() << endl;
            break;
        }
        case '7':{
            vector<int> v1d;
            vector<vector<int>> v2d;
            for (int i = 0; i < 10; i++) {
                v1d.push_back(i);
            }
            cout << "v1d = " << v1d[4] <<endl;
            cout << "size of v1d = " << v1d.size() << endl;
            
            for (int i = 0; i < 2; i++) {
                vector<int> row;
                for (int j = 0; j < 4; j++) {
                    row.push_back(j);
                }
                v2d.push_back(row);
                
            }
            cout << "size of v2d = " << v2d.size() << endl;
            cout << "size of v2d = " << v2d[1].size() << endl;
            //            cout << "sum of two vector elements is " << atoi(v2d[1][1]) << endl;
            char str = '1';
            cout << "str = " << int(str) - 48 << endl;
            for (int i = 0; i < v1d.size(); i++) {
                cout << "The last element is" << v1d[i] <<endl;
            }
        }
        case '8': {
            vector<string> summary;
            vector<int> list;
            for (int i = 0; i < 10; i++) {
                list.push_back(i);
            }
            int a = list[8];
            string b;
            b = to_string(a);
            string str = "12";
            str += b;
            summary.push_back(str);
            summary.push_back("34");
            cout << summary[0] << endl;
            cout << summary[1] << endl;
        }
        case '9':{
            /*vector<int> vec = {1,2,3,4,5};
             vec.pop_back();
             cout << vec.size() << endl;
             for (int i = 0; i < vec.size(); i++) {
             cout << vec[i] << endl;
             }*/
            int x;
            cout << "Please input a number" << endl;
            cin >> x;
            string str = to_string(x);
            if(str[0] != '-') for(int i = 0; i < str.size() - 1; i++) swap(str[i], str[str.size() - 1 - i]);
            if(str[0] == '-') for(int i = 1; i < str.size() - 1; i++) swap(str[i], str[str.size() - i]);
            cout << "The invert string is " << str << endl;
            cout << std::numeric_limits<int>::max() << endl;
        }
            
        case '2':{
            //printAZ09();
            //string str = "abcd";
            //cout << str.substr(0,2) << endl;
            
//            MinStack minst;
//            minst.push(-1412414);
//            cout << minst.getMin() << endl;
            /*Solution S;
            //string res = S.convert("ABCDE", 4);
            //cout << res << endl;
            vector<int> input;
            input.push_back(3);
            input.push_back(2);
            input.push_back(4);
            
            vector<int> s = S.twoSum(input, 6);
            for(int m = 0; m < s.size(); m++) cout << s[m] << ':' << endl;
             
            Stack st;
            st.push(1);
            st.push(2);
            cout << st.top() << endl;
             */
            
            Solution s;
            /*vector<vector<int>> matrix;
            for (int i = 0; i < 5; i++) {
                vector<int> temp;
                for (int j = 1; j <= 5; j++) {
                    temp.push_back(i*5 + j);
                }
                matrix.push_back(temp);
            }
             
            s.spiralOrder(matrix);*/
            //int index = s.strStr("mississippi", "pi");
            //cout << index << endl;
            
            //int ans = s.calculate(" 2-1 + 2 ");
            //cout << ans << endl;
            
            //if(s.isValid("[])")) cout << " is true" << endl;
            //else cout << " is false" << endl;
            
            //s.push(1);s.push(2);
            //cout << s.peek() << endl;;
            //vector<int> vec = {1,1};
            //cout << s.minSubArrayLen(3, vec) << endl;
            
            //TreeNode treeHead(1);
            //TreeNode treeHead2(2);
            //TreeNode treeHead3(3);
            //treeHead.right = &treeHead2;
            //treeHead2.right = &treeHead3;
            //if(s.isBalanced(&treeHead)) cout << "true balanced" <<endl;
            //else cout << "Not balanced" << endl;
            
            //cout << s.compareVersion("1", "1.0") << endl;;
            
//            ListNode node1(1);
//            ListNode node2(1);
//            ListNode node3(2);
//            ListNode node4(1);
//            node1.next = &node2;
//            node2.next = &node3;
//            node3.next = &node4;
//            if(s.isPalindrome(&node1)) cout << "True" << endl;
//            else cout << "false" << endl;
            
//            if(s.isPalindrome("'''''")) cout << "True" << endl;
//            else cout << "false" << endl;

//            ListNode node1(1);
//            ListNode node2(8);
//            ListNode node3(0);
//            node1.next = &node2;
//            s.addTwoNumbers(&node1, &node3);

//            ListNode *head = new ListNode(1);
//            ListNode node2(2);
//            ListNode node3(3);
//            ListNode node4(3);
//            head->next = &node2;
//            node2.next = &node3;
//            node3.next = &node4;
//            s.deleteDuplicates(head);

//            vector<int> nums = {1,1};
//            cout << s.removeDuplicates(nums);
//            ListNode *l1 = new ListNode(2);
//            ListNode *l2 = new ListNode(1);
//            ListNode *l3;
//            l3 = s.mergeTwoLists(l1,l2);

//            s.isAnagram("a", "b");
//            s.generate(3);
        
//            cout<<s.nthUglyNumber(5)<<endl;;
//            s.numSquares(12);
//            vector<int> t;
//            t.push_back(1);
//            t.push_back(2);
//            s.rob(t);
            
//            vector<vector<int>> g;
//            vector<int> l;
//            vector<int> l2;
//            l.push_back(1);
//            l.push_back(2);
//            l.push_back(3);
//            l2.push_back(4);
//            l2.push_back(5);
//            l2.push_back(6);
//            g.push_back(l);
//            g.push_back(l2);
//            s.minPathSum(g);
//            TreeNode* root = new TreeNode(3);
//            TreeNode l1(1);
//            TreeNode r1(5);
//            TreeNode l21(0);
//            TreeNode r21(2);
//            TreeNode l22(4);
//            TreeNode r22(6);
//            root->left = &l1;
//            root->right = &r1;
//            l1.left = &l21;
//            l1.right = &r21;
//            r1.left = &l22;
//            r1.right = &r22;
//            if(s.isValidBST(root)) cout<< "right!" <<endl;
            
//            TreeNode* root = new TreeNode(1);
//            vector<int> ans;
//            ans = s.inorderTraversal(root);
//            TreeNode* root = new TreeNode(1);
//            vector<int> ans;
//            ans = s.preorderTraversal(root);
//            vector<vector<int>> ans;
//            ans = s.combine(3,3);
            
//            vector<int> nums;
//            nums.push_back(1);
//            nums.push_back(3);
//            nums.push_back(2);
//            s.nextPermutation(nums);
//            cout<<s.bulbSwitch(7)<<endl;
            
//            string line;
//            while(getline(cin,line)) {
//            cout<<line<<endl;
//            }
            
//            bitset<65536> bs(0);
//            bs.flip();
//            if(bs.none()) cout<<"None!"<<endl;
//            else cout<<bs.count()<<endl;
            
//            vector<int> vec = {1,2,3};
//            vector<int>::const_iterator iter;
//            for(iter = vec.begin(); iter!=vec.end();++iter) {
//                cout<<*iter<<endl;
//            }
            
            
//            sketch sket;
//            sket.lastKline(10);
//            
//            test t;
//            t.lastKline(3);
//            t.say(1);
//            t.say2(1,2);
            
//            cout << getMax(1.0,2.123123) << endl;
            
//            ListNode l1(2);
//            ListNode l2(1);
//            l1.next = &l2;
//            s.sortList(&l1);
            
//            vector<int> nums(1);
//            
//            s.missingNumber(nums);

//            CountInversion CI;
//            CI.ReadTXT();
//            cout << CI.Count() << endl;

//            s.countBits(4);
//            break;
            
//            vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
//            s.threeSum2(nums);
            
//            s.generate2(3);
//            vector<vector<int>> ans = {{0},{1}};
//            s.setZeroes(ans);

//            vector<vector<int>> vec = {{1,1},{1,0}};
//            s.gameOfLife(vec);
            
//            string a = "11";
//            string b = "1";
//            s.addBinary(a, b);

//            string num1 = "123";
//            string num2 = "456";
//            cout << s.multiply(num1, num2) << endl;

//            s.countAndSay(3);
//            s.compareVersionII("1", "1.1");
            
//            ListNode l1(1);
//            ListNode l1_2(8);
//            l1.next = &l1_2;
//            
//            ListNode l2(0);
//            
//            s.addTwoNumbers(&l1, &l2);
//            vector<int> line = {3,2,6,5,0,3};
//            s.maxProfitIII(line);

//            Trie trie;
//            trie.insert("p");
//            trie.startsWith("pr");
//            trie.search("p");
//            trie.insert("pr");
//            trie.startsWith("pre");
//            trie.search("pr");
//            trie.insert("pre");
//            trie.startsWith("pre");
//            trie.search("pre");

//            vector<int> nums = {0,0};
//            s.moveZeroes(nums);
//            vector<int> nums = {1,1};
//            cout << s.removeDuplicates3(nums) << endl;
//            vector<int> preorder = {6, 2, 1, 4, 3, 5, 7, 9, 8};
//            vector<int> inorder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//            s.buildTree(preorder, inorder);

//            vector<int> inorder = {1,3,2};
//            vector<int> postorder = {3,2,1};
//            s.buildTree2(inorder, postorder);
//            vector<int> nums = {1,3};
//            s.sortedArrayToBST(nums);

            ListNode* head = new ListNode(1);
            ListNode* end = new ListNode(3);
            head->next = end;
            s.sortedListToBST(head);
            
        }
            
        default:
            break;
    }
    return 0;
}
