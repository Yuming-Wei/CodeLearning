//
//  FindDuplicateArray.h
//  HiC++
//
//  Created by My AD on 8/4/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef FindDuplicateArray_h
#define FindDuplicateArray_h

class FindDuplicateArray : public SolutionClass {
public:
    int findDuplicate(vector<int>& nums) {
        //    int low = 1, high = nums.size(), mid, count = 0;
        //
        //    while(low < high) {
        //        mid = (low + high) / 2;
        //        count = 0;
        //        for(int i = 0; i < nums.size(); ++i) {
        //            if(nums[i] >= low && nums[i] <= mid) count++;
        //        }
        //        if(count <= mid - low + 1) low = mid + 1;
        //        else high = mid;
        //    }
        //    return low;
        
        if(nums.size() > 0) {
            int slow = nums[0];
            int fast = nums[nums[0]];
            
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            fast = 0;
            while(slow != fast) {
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        } else return -1;
    }
    
};

#endif /* FindDuplicateArray_h */
