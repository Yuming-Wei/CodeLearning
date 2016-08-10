//
//  ListClass.h
//  HiC++
//
//  Created by My AD on 8/10/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef ListClass_h
#define ListClass_h

#include "MyStruct.h"

class ListClass {
public:
    ListNode *makeList(vector<int>& nums) {
        ListNode head(0);
        ListNode* pre = &head, *cur;
        for(int i = 0; i < nums.size(); ++i) {
            cur = new ListNode(nums[i]);
            pre->next = cur;
            pre = cur;
        }
        return head.next;
    }
};

#endif /* ListClass_h */
