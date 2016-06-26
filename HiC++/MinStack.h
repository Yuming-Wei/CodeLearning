//
//  MinStack.h
//  HiC++
//
//  Created by My AD on 6/24/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef MinStack_h
#define MinStack_h

using namespace std;

class MinStack {
public:
    vector<int> stack;
    vector<int> stmin = {INT_MAX};
    void push(int x) {
        if(x <= stmin[stmin.size() - 1]) stmin.push_back(x);
        stack.push_back(x);
    }
    
    void pop() {
        if(stack[stack.size() - 1] == stmin[stmin.size() - 1]) stmin.pop_back();
        stack.pop_back();
    }
    
    int top() {
        if(stack.size() == 0) return 0;
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return stmin[stmin.size() - 1];
    }
};

#endif /* MinStack_h */
