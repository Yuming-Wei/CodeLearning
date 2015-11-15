//
//  main.h
//  HiC++
//
//  Created by My AD on 7/17/15.
//  Copyright (c) 2015 My AD. All rights reserved.
//

#ifndef HiC___main_h
#define HiC___main_h


#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

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


class Solution {
private:
    stack<int> myQueue,trans;
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        int median = root->val;
        return isValidBST_Left(root->left,median)&&isValidBST_Right(root->right,median);
    }
    
    bool isValidBST_Left(TreeNode* root, int median) {
        if(!root) return true;
        if(root->val >= median) return false;
        if(root->left) {
            if((root->left->val >= root->val)||(root->left->val >= median)) return false;
        }
        if(root->right) {
            if((root->right->val <= root->val||(root->right->val >= median))) return false;
        }
        return isValidBST_Left(root->left, median)&&isValidBST_Right(root->right, median);
    }
    
    bool isValidBST_Right(TreeNode* root, int median) {
        if(!root) return true;
        if(root->val <= median) return false;
        if(root->left) {
            if((root->left->val >= root->val)||(root->left->val <= median)) return false;
        }
        if(root->right) {
            if((root->right->val <= root->val||(root->right->val <= median))) return false;
        }
        return isValidBST_Left(root->left, median)&&isValidBST_Right(root->right, median);
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> treeQueue;
        if(root == NULL) return ans;
        treeQueue.push(root);
        int count = 0;
        while(treeQueue.size() != 0) {
            count = treeQueue.size();
            vector<int> line;
            for(int i = 0; i < count; ++i) {
                TreeNode *temp = treeQueue.front();
                treeQueue.pop();
                line.push_back(temp->val);
                if(temp->left != NULL) treeQueue.push(temp->left);
                if(temp->right != NULL) treeQueue.push(temp->right);
            }
            ans.push_back(line);
        }
        return ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int sum;
        sum = grid[0][0];
        int i = 0, j = 0;
        while((i != grid.size() - 1)||(j != grid[0].size() - 1)) {
            if(i < grid.size() - 1) {
                if(j < grid[0].size() - 1) {
                    if(grid[i + 1][j] >= grid[i][j + 1]) sum += grid[i][++j];
                    else sum += grid[++i][j];
                } else sum += grid[++i][j];
            } else sum += grid[i][++j];
        }
        return sum;
    }
    
    int robII(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> l1(nums.begin() + 1, nums.end());
        vector<int> l2(nums.begin(), nums.end() - 1);
        return max(rob(l1), rob(l2));
        
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        nums[1] = max(nums[0], nums[1]);
        
        int i = 2;
        while(i < nums.size()) {
            if(nums[i - 1] < (nums[i] + nums[i - 2])) nums[i] = nums[i] + nums[i- 2];
            else nums[i] = nums[i - 1];
            i++;
        }
        return nums[i - 1];
    }
    
    int numSquares(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers
        // which sum to i. Since cntPerfectSquares is a static vector, if
        // cntPerfectSquares.size() > n, we have already calculated the result
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
    
    
    int nthUglyNumber(int n) {
        
        return 0;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasV = {};
        vector<int> line;
        if(numRows == 0) return pasV;
        line.push_back(1);
        pasV.push_back(line);
        if(numRows == 1) return pasV;
        line.push_back(1);
        pasV.push_back(line);
        if(numRows == 2) return pasV;
        
        int lineIdx = 2;
        while(lineIdx < numRows) {
            vector<int> vec;
            vec.push_back(1);
            for(int i = 0; i < lineIdx - 1; i++) {
                int val = pasV[lineIdx - 1][i] + pasV[lineIdx - 1][i + 1];
                vec.push_back(val);
            }
            vec.push_back(1);
            lineIdx++;
            pasV.push_back(vec);
        }
        return pasV;
    }
    
    bool isAnagram(string s, string t) {
        int sum1 = 0, sum2 = 0;
        int len_s = s.length();
        int len_t = t.length();
        
        for(int i = 0; i < len_s; i++) {
            sum1 += s[i];
        }
        for(int j = 0; j < len_t; j++) {
            sum2 += t[j];
        }
        if(sum1 == sum2) return true;
        return false;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL, *curr = NULL;
        while((l1 != NULL)||(l2 != NULL)) {
            if(l3 == NULL) {
                if((l2 == NULL)||((l1 != NULL)&&(l1->val <= l2->val))) {
                    l3 = l1;
                    curr = l3;
                    l1 = l1->next;
                } else if((l1 == NULL)||((l2 != NULL)&&(l1->val >= l2->val))) {
                    l3 = l2;
                    curr = l3;
                    l2 = l2->next;
                }
            }
            
            if((l1 != NULL)&&(l2 != NULL)) {
                if(l1->val <= l2->val) {
                    curr->next = l1;
                    curr = curr->next;
                    l1 = l1->next;
                } else {
                    curr->next = l2;
                    curr = curr->next;
                    l2 = l2->next;
                }
            } else {
                if((l1 != NULL)||(l2 != NULL)) {
                    if(l1 == NULL) {
                        curr->next = l2;
                        curr = curr->next;
                        l2 = l2->next;
                    } else {
                        curr->next = l1;
                        curr = curr->next;
                        l1 = l1->next;
                    }
                }
            }
            
        }
        return l3;
    }
    
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(!len) return len;
        int count = 1, flag = 0;
        for(int i = 1; i < len; i++) {
            if(nums[i] == nums[i - 1]) {
                count++;
            } else count = 1;
            if(count < 3) nums[++flag] = nums[i];
        }
        return flag + 1;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        int dupval;
        ListNode *pre = NULL, *cur = head, *nxt = head->next;
        if((nxt != NULL)&&(cur->val == nxt->val)) {
            dupval = cur->val;
            while(cur) {
                if(cur->val == dupval) cur = cur->next;
                else break;
            }
            head = cur;
            if(cur) nxt = cur->next;
        }
        while((nxt != NULL)&&(cur != NULL)) {
            if(cur->val == nxt->val) {
                dupval = cur->val;
                while(cur) {
                    if(cur->val == dupval) cur = cur->next;
                    else break;
                }
                if(pre == NULL) head = cur;
                else pre->next = cur;
                if(cur) nxt = cur->next;
            } else {
                pre = cur;
                cur = nxt;
                nxt = nxt->next;
            }
        }
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0, num2 = 0, sum = 0, count = 0;
        vector<int> nums;
        while(l1) {
            num1 = num1 + l1->val*pow(10,count);
            l1 = l1->next;
            count++;
        }
        count = 0;
        while(l2) {
            num2 = num2 + l2->val*pow(10,count);
            l2 = l2->next;
            count++;
        }
        count = 0;
        sum = num1 + num2;
        do {
            count++;
            nums.push_back(sum%10);
            sum /= 10;
        } while(sum);
        
        ListNode *ans = new ListNode(nums[0]);
        ListNode *cur = ans;
        int i = 1;
        while(i < nums.size()) {
            cur->next = new ListNode(nums[i]);
            cur = cur->next;
            i++;
        }
        return ans;
    }
    
    bool isPalindrome(string s) {
        if(s == "") return true;
        int len = s.length();
        int i = 0, j = len - 1;
        while(i <= j) {
            while((!(((s[i] >= '0')&&(s[i] <= '9'))||((s[i] >= 'A')&&(s[i] <= 'Z'))||((s[i] >= 'a')&&(s[i] <= 'z'))))&&(i < len)) i++;
            while((!(((s[j] >= '0')&&(s[j] <= '9'))||((s[j] >= 'A')&&(s[j] <= 'Z'))||((s[j] >= 'a')&&(s[j] <= 'z'))))&&(j >= 0)) j--;
            if((s[i] != s[j])&&(abs(s[i] - s[j]) != 32)&&(i <len)&&(j >= 0)) return false;
           i++;
           j--;
        }
        return true;
    }
                  
    bool isPalindrome(ListNode* head) {
        if((!head)||(head->next == NULL)) return true;
        int count = 0;
        ListNode *fast = head->next, *slow = head;
        while(fast&&fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tail = reverse(slow->next);
        slow->next = NULL;
        while(head&&tail) {
            if(head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* oldhead) {
        ListNode *pre = NULL, *cur = oldhead, *nxt = oldhead->next;
        while(nxt != NULL) {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = nxt->next;
            cur->next = pre;
        }
        return cur;
    }
    
    /*bool isPalindrome(ListNode* head) {
        if(!head) return true;
        vector<int> valist;
        for(; head != NULL; head = head->next) {
            valist.push_back(head->val);
        }
        int len = valist.size();
        for(int i = 0; i < len / 2; i++) {
            if(valist[i] != valist[len - i - 1]) return false;
        }
        return true;
    }*/
    
    int maxArea(vector<int>& height) {
        int lft = 0, rgt = height.size() - 1;
        int maxarea = 0, h;
        while(lft < rgt) {
            h = min(height[lft], height[rgt]);
            maxarea = max((rgt - lft)*h, maxarea);
            while(height[lft] <= h) lft++;
            while(height[rgt] <= h) rgt--;
        }
        return maxarea;
    }
    
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int i, j;
        int ans = INT_MAX;
        for(i = 0, j  = 0; (i < len1)&&(j < len2); i++, j++) {
            vector<int> res1,res2;
            res1 = getnum(version1,i);
            res2 = getnum(version2,j);
            if(res1[0] > res2[0]) return 1;
            if(res1[0] < res2[0]) return -1;
            if(res1[0] == res2[0]) {
                i = res1[1];
                j = res2[1];
                if((i == len1)&&(j == len2)) return 0;
            }
        }
        if((j > len2)&&(i < len1)) {
            vector<int> res;
            res = getnum(version1, i);
            if(res[0] == 0) ans = 0;
            else ans = 1;
        }
        if((j < len2)&&(i > len1)) {
            vector<int> res;
            res = getnum(version2, j);
            if(res[0] == 0) ans = 0;
            else ans = -1;
        }
        if((j == len2)&&(i == len1)) ans = 0;
        return ans;
    }

    vector<int> getnum(string str, int pos) {
        bool flag = true;
        double sum = 0;
        vector<int> ans;
        int i = pos;
        for(i = pos; i < str.length(); i++) {
            if(str[i] == '.') break;
            sum = sum*10 + str[i] - '0';
        }
        ans.push_back(sum);
        ans.push_back(i);
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        if(abs(cntLvl(root->left) - cntLvl(root->right)) > 1) return false;
        else return isBalanced(root->left)&&isBalanced(root->right);
    }
    
    int cntLvl(TreeNode* root) {
        if (root != NULL) {
            return max(1 + cntLvl(root->left),  1 + cntLvl(root->right));
        } else return 0;
    }
    
    int minSubArrayLen(int s, vector<int>& nums) {
        int numlen = nums.size();
        int right = 0, left = 0, minlen = numlen + 1, total = 0;
        while(right < numlen) {
            do {
                total += nums[right++];
            } while ((right < numlen) && (total < s));
            while(((total - nums[left]) >= s) && (left < right)) total -= nums[left++];
            if((total >= s) && (minlen > right - left)) minlen = right - left;
        }
        return (minlen < numlen) ? minlen : 0;
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        myQueue.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        int lenq = myQueue.size();
        for(int i = 0; i < lenq - 1; i++) {
            trans.push(myQueue.top());
            myQueue.pop();
        }
        myQueue.pop();
        int lent = trans.size();
        for(int i = 0; i < lent; i++) {
            myQueue.push(trans.top());
            trans.pop();
        }
    }
    
    // Get the front element.
    int peek(void) {
        int lenq = myQueue.size();
        for(int i = 0; i < lenq; i++) {
            trans.push(myQueue.top());
            myQueue.pop();
        }
        int ans = trans.top();
        int lent = trans.size();
        for(int i = 0; i < lent; i++) {
            myQueue.push(trans.top());
            trans.pop();
        }
        return ans;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return myQueue.empty();
    }
    
    bool isValid(string s) {
        stack<char> stk;
        int i = 0;
        while(i < s.length()) {
            char ch = s[i];
            if((ch == '(')||(ch == '[')||(ch == '{')) {
                stk.push(ch);
                i++;
            } else if((stk.size() != 0)&&((stk.top() == ch - 1)||(stk.top() == ch - 2))) {
                stk.pop();
                i++;
            } else return false;
        }
        return stk.empty();
    }
    
    int calculate(string s) {
        if(!s.length()) return 0;
        vector<int> ans;
        ans = cal(s,0);
        return ans[0];
    }
    
    vector<int> cal(string str, int stpos) {
        long int subsum = 0;
        vector<int> ans;
        int i = 0;
        int currsign = 1;
        for(i = stpos; i < str.length(); i++) {
            char ch = str[i];
            switch(ch) {
                case ' ': {break;}
                case '+': {currsign = 1; break;}
                case '-': {currsign = -1; break;}
                case '(': {
                    vector<int> ans1;
                    ans1 = cal(str,i + 1);
                    subsum += ans1[0]*currsign;
                    i = ans1[1];
                    break;
                }
                case ')': {
                    vector<int> ans2;
                    ans2.push_back(subsum);
                    ans2.push_back(i);
                    return ans2; break;
                }
                default: {
                    if((ch >= '0')&&(ch <= '9')) {
                        int j = i;
                        long int currnum = ch - '0';
                        while((str[j + 1] >= '0')&&(str[j + 1] <= '9')) {
                            currnum = currnum * 10 + str[j + 1] - '0';
                            j++;
                        }
                        subsum += currnum * currsign;
                        i = j;
                    }
                }
            }
        }
        ans.push_back(subsum);
        ans.push_back(i);
        return ans;
    }
    
    int strStr(string haystack, string needle) {
        int lenh = haystack.length();
        int lenn = needle.length();
        //if((haystack == needle)||(needle == "")) return 0;
        //if(lenh < lenn) return -1;
        /*for(int i = 0; i < lenh - lenn + 1; i++) {
         if(haystack.compare(i,lenn,needle) == 0) return i;
         }*/
        bool flag = true;
        for(int i = 0; i < lenh - lenn + 1; i++) {
            if(haystack[i] == needle[0]) {
                for(int j = 0; j < lenn; j++) {
                    if(haystack[j + i] != needle[j]) {
                        flag = false;
                        break;
                    } else flag = true;
                }
                if(flag) return i;
            }
        }
        return -1;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans = {};
        if(matrix.size() == 0) return ans;
        
        int hLmt = matrix[0].size();
        int vLmt = matrix.size();
        
        int upb = 0, lowb = vLmt -1;
        int leftb = 0, rightb = hLmt - 1;
        bool right = true, down = false, left = false, up = false;
        int n = 0, m = 0;
        while(ans.size() != hLmt*vLmt) {
            if(right) {
                ans.push_back(matrix[m][n]);
                n++;
                if(n > rightb) {
                    right = false;
                    down = true;
                    left = false;
                    up = false;
                    n--;
                    m++;
                    upb++;
                }
                continue;
            }
            if(down) {
                ans.push_back(matrix[m][n]);
                m++;
                if(m > lowb) {
                    right = false;
                    down = false;
                    left = true;
                    up = false;
                    m--;
                    n--;
                    rightb--;
                }
                continue;
            }
            if(left) {
                ans.push_back(matrix[m][n]);
                n--;
                if(n < leftb) {
                    right = false;
                    down = false;
                    left = false;
                    up = true;
                    n++;
                    m--;
                    lowb--;
                }
                continue;
            }
            if(up) {
                ans.push_back(matrix[m][n]);
                m--;
                if(m < upb) {
                    right = true;
                    down = false;
                    left = false;
                    up = false;
                    m++;
                    
                    n++;
                    leftb++;
                }
                continue;
            }
        }
        return ans;
    }
    
    bool isPowerOfTwo(int n) {
        int count = 0;
        for(int i = 31; i >=0 ;i--) {
            if((1 << i)&n != 0) {
                count++;
                continue;
            }
        }
        if(count != 1) {
            return false;
        } else return true;
        
    }
    int myAtoi(string str) {
        if(str.length() == 0) return 0;
        vector<int> num;
        long long res = 0;
        bool sign = true, signFound = false;
        for(int i = 0; i < str.length(); i++) {
            if((str[i] == ' ')&&(signFound == false)) continue;
            if((str[i] == ' ')&&(signFound == true)) break;
            
            if((str[i] == '+')&&signFound == false) {
                signFound = true;
                continue;
            }
            if((str[i] == '+')&&signFound == true) return 0;
            
            if((str[i] == '-')&&signFound == false) {
                sign = false;
                signFound = true;
                continue;
            }
            if((str[i] == '-')&&signFound == true) return 0;
            if(((str[i] - '0') >= 0)&&((str[i] - '9') <= 0)) {
                num.push_back(str[i] - '0');
                signFound = true;
            } else break;
        }
        for(int j = num.size() - 1; j >= 0; j--) {
            res += num[j]*pow(10,num.size() - 1 - j);
            if(sign) if(res >= INT_MAX) return INT_MAX;
            if(!sign) if(-res <= INT_MIN) return INT_MIN;
            
        }
        if(sign) {
            //if(res >= INT_MAX) return INT_MAX;
            return res;
        } else {
            //if(-res <= INT_MIN) return INT_MIN;
            return -res;
        }
    }
    
    string convert(string s, int numRows) {
        int len = s.length();
        if((!len)||(numRows == 1)||(len <= numRows)) return s;
        int count = ceil(len * 1.0 / (2*numRows - 2));
        //string str[numRows] = {};
        vector<char> str;
        string ans = "";
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < count; j++) {
                if(((2*numRows - 2)*j + i) < len) {
                    if((i != 0)&&(i != numRows - 1)) {
                        str.push_back(s[(2*numRows - 2)*j + i]);
                        if(((2*numRows - 2)*j + 2*(numRows - i - 1) + i) < len) str.push_back(s[(2*numRows - 2)*j + 2*(numRows -i -1) + i]);
                    } else str.push_back(s[(2*numRows - 2)*j + i]);
                }
            }
        }
        for(int m = 0; m < str.size();m ++) {
            ans += str[m];
        }
        return ans;
    }
    
    string convertToTitle(int n) {
        if(!n) return NULL;
        vector<int> vec = {};
        string ans = "";
        while(n/26) {
            vec.push_back(n%26);
            n /= 26;
        }
        vec.push_back(n);
        for(int i = (vec.size() - 1); i >= 0; i--) {
            if(vec.size() != 1){
                if(vec[i - 1] != 0) {
                    ans += ((char) vec[i] - 1 + 'A');
                } else {
                    if(vec[i] > 1) ans += ((char) vec[i] - 2 + 'A');
                }
                
            } else {
                if(vec[i] == 0) ans += 'Z';
                ans += ((char) vec[i] - 1 + 'A');
            }
        }
        return ans;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans = {};
        unordered_map<int,int> mp;
        if(len == 2) {
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        for(int i = 0; i < len ; i++) {
            ++mp[nums[i]] = i;
        }
        for(int j = 0; j < len; j++) {
            if((mp.find(target - nums[j]) != mp.end())&&(mp.find(target - nums[j])->second != j)) {
                if(j < mp.find(target - nums[j])->second) {
                    ans.push_back(j + 1);
                    ans.push_back(mp.find(target - nums[j])->second + 1);
                } else {
                    ans.push_back(mp.find(target - nums[j])->second + 1);
                    ans.push_back(j + 1);
                }
                return ans;
            }
        }
        return ans;
    }
    
};

class Stack {
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

enum choice {
    A,B,C
};

void printAZ09() {
    char Letter = 'a' - 1 ,Number = '0';
    int lenL = 26,lenN = 10;
    for (int i = 1; i <= lenL; i++) {
        cout << char(Letter + i) << ":" <<int(Letter + i) << "  ";
        if (i % 3 == 0) {
            cout << endl;
        }
        
    }
    cout << endl;
    
    for (int i = 0; i < lenN; i++) {
        cout << char(Number + i) << ":" << hex <<(Number + i) << "  ";
    }
    
}

void pointer(char *p){
    int len = strlen(p);
    int tempCnt = 0;
    for (int i = 0; i <= len - 2; i++) {
        for (int j = 0; j <= len - 2; j++) {
            if (p[i] == p[i + j]) {
                if (p[i + 1] ==p[i + 1 + j]) {
                    tempCnt ++;
                }
            }
        }
        if (tempCnt > 1) {
            cout << p[i] <<p[i+1] << " Shows more than 1 time, shows " << tempCnt << " times." << endl;
        }
        tempCnt = 0;
    }
}


void StrMan() {
    char p1[] = "ab\n";
    char *p2 = p1;
    cout << p1 << endl;
    cout << p2 << endl;
    
    int LL = strlen(p2);
    
    cout << "Size of string is " << LL<< endl;
    
    if (p2[LL - 1] == '\n') {
        cout << "Found enter" << endl;
    }
    
    if (p2[LL] == 0) {
        cout << "Found end" << endl;
    }
    
}

double AddFun(char* in, int NumLen, double PreRst){
    double AddRst;
    char* lstP = in;
    char* CurrNum;
    for (int i = 0; i < NumLen; i++) {
        lstP--;
    }
    strlcpy(lstP, CurrNum, NumLen);
    AddRst = PreRst + double(*CurrNum);
    return AddRst;
}

double Cal(char* in){
    double rst = 0;
    int NumLen = 0;
    char* pl;
    for (pl = in; *pl!=0; pl++) {
        switch (*pl) {
            case '+':
                rst = AddFun(in, NumLen,rst);
                NumLen = 0;
                break;
            case '-':
                rst = AddFun(in,NumLen,rst);
                NumLen = 0;
                break;
            default:
                NumLen++;
                break;
        }
    }
    return rst;
}

double Add_Min(char* in){
    double Left_Rst = 0;
    int NumLen = 0;
    char* CurrNum;
    char* expr;
    bool flag = true;
    for (expr = in; flag; expr++) {
        NumLen++;
        switch (*expr) {
            case '+':{
                flag = false;
                break;
            }
            case '-':{
                flag = false;
                break;
            }
            default:
                break;
        }
    }
    
    NumLen = 0;
    for (; *expr!=0; expr++) {
        NumLen++;
        switch (*expr) {
            case '+':{
                Left_Rst += double(strlcpy(in, CurrNum, NumLen));
                NumLen = 0;
                break;
            }
            case '-':{
                Left_Rst -= double(strlcpy(in, CurrNum, NumLen));
                NumLen = 0;
                break;
            }
            default:
                break;
        }
    }
    return Left_Rst;
}

#endif