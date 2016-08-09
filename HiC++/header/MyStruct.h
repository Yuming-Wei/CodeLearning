//
//  myStruct.h
//  HiC++
//
//  Created by My AD on 6/25/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef MyStruct_h
#define MyStruct_h

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a single link list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


#endif /* MyStruct_h */
