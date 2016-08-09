//
//  MyStack.h
//  HiC++
//
//  Created by My AD on 6/24/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef MyStack_h
#define MyStack_h

using namespace std;

class MyStack {
public:
    // Push element x onto stack.
    void push(int x) {
        myStack.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        int len = myStack.size();
        for(int i = 0; i < len - 1; i++) {
            myStack.push(myStack.front());
            myStack.pop();
        }
        myStack.pop();
    }
    
    // Get the top element.
    int top() {
        //if(myStack.size() != 0) return myStack.back();
        /*int len = myStack.size();
         if(!len) {
         for(int i = 0; i < len - 1; i++) {
         myStack.push(myStack.front());
         myStack.pop();
         }
         }
         int ans = myStack.front();
         myStack.push(ans);
         myStack.pop();
         return ans;*/
        return myStack.size() != 0? myStack.back():NULL;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return myStack.empty();
    }
private:
    std::queue<int> myStack;
};

#endif /* MyStack_h */
