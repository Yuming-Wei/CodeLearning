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
#include <fstream>
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
    vector<int> ans;
    vector<vector<int>> ans2;
    
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(depth(root->left) - depth(root->right)) > 1) return false;
        else return (isBalanced(root->left)&isBalanced(root->right));
    }
    
    int depth(TreeNode* root) {
        if(!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return (minDepth(root->right) + 1);
        if(!root->right) return (minDepth(root->left) + 1);
        return (min(minDepth(root->left),minDepth(root->right)) + 1);
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL) {
            TreeNode* temp;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->right);
            invertTree(root->left);
        }
        return root;
    }
    
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if(!len1||!len2) return 0;
        vector<int> line, ans;
        string ret = "";
        int carry = 0, mul1 = 0, mul2 = 0, temp;
        int m, n;
        int shift, check = 0;
        for(int i = len1 - 1; i >= 0 ; i--) {
            for(int j = len2 - 1; j >= 0; j--) {
                mul1 = num1[i] - '0';
                mul2 = num2[j] - '0';
                if(i == len1 - 1) {
                    line.push_back((mul1*mul2 + carry)%10);
                    carry = (mul1*mul2 + carry)/10;
                } else {
                    shift = (len1 - 1 - i) + (len2 - 1 - j);
                    if(shift < line.size()) {
                        temp = line[shift] + mul1*mul2 + carry;
                        line[shift] = temp%10;
                        carry = temp/10;
                    } else {
                        temp = mul1*mul2 + carry;
                        line.push_back(temp%10);
                        carry = temp/10;
                    }
                }
            }
            if(carry) {
                line.push_back(carry);
                carry = 0;
            }
        }
        
        for(int ii = line.size() - 1; ii >= 0; ii--) {
            ret = ret + (char)(line[ii] + 48);
            check += line[ii];
        }
        return (check == 0)?"0":ret;
    }
    
    string multiply2(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        if(!len1||!len2) return 0;
        vector<int> line, ans;
        string ret = "";
        int carry1 = 0, carry2 = 0, mul1 = 0, mul2 = 0, m, n, temp, check = 0;;
        for(int i = len1 - 1; i >= 0 ; i--) {
            for(int j = len2 - 1; j >= 0; j--) {
                mul1 = num1[i] - '0';
                mul2 = num2[j] - '0';
                line.push_back((mul1*mul2 + carry1)%10);
                carry1 = (mul1*mul2 + carry1)/10;
            }
            if(carry1) {
                line.push_back(carry1);
                carry1 = 0;
            }
            
            carry2 = 0;
            if(ans.size() == 0) ans = line;
            else {
                m = len1 - 1 - i; n = 0;
                while(n < line.size()) {
                    if(m < ans.size()) {
                        temp = ans[m] + line[n] + carry2;
                        ans[m] = temp%10;
                        carry2 = temp/10;
                    } else {
                        ans.push_back((line[n] + carry2)%10);
                        carry2 = (line[n] + carry2)/10;
                    }
                    m++;
                    n++;
                }
                if(carry2 != 0) ans.push_back(carry2);
            }
            line.clear();
        }
        for(int ii = ans.size() - 1; ii >=0; ii--) {
            ret = ret + (char)(ans[ii] + 48);
            check += ans[ii];
        }
        return (check == 0)?"0":ret;
    }
    
    
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int mark = 1;
        
        for(int i = len - 1; i >= 0; i--) {
            if((digits[i] + mark) <= 9) {
                digits[i] = digits[i] + mark;
                mark = 0;
            } else {
                digits[i] = 0;
                mark = 1;
            }
        }
        if(mark == 1) {
            digits.push_back(0);
            for(int i = 0; i < digits.size() - 1; i++) digits[i + 1] = digits[i];
            digits[0] = 1;
        }
        return digits;
    }
    
    string addBinary(string a, string b) {
        int lenA = a.length();
        int lenB = b.length();
        int mark = 0;
        string ans = "";
        int i = lenA - 1, j = lenB - 1;
        while((i >= 0)&&(j >= 0)) {
            if((a[i] - '0' + b[j] - '0' + mark) == 0) {
                ans = '0' + ans;
                mark = 0;
            } else if((a[i] - '0' + b[j] - '0' + mark) == 1) {
                ans = '1' + ans;
                mark = 0;
            } else if((a[i] - '0' + b[j] - '0' + mark) == 2) {
                ans = '0' + ans;
                mark = 1;
            } else if((a[i] - '0' + b[j] - '0' + mark) == 3) {
                ans = '1' + ans;
                mark = 1;
            }
            i--;
            j--;
        }
        if((i < 0)&&(j >= 0)) {
            for(int m = j; m >= 0; m--) {
                if((b[m] - '0' + mark) == 0) {
                    ans = '0' + ans;
                    mark = 0;
                } else if((b[m] - '0' + mark) == 1) {
                    ans = '1' + ans;
                    mark = 0;
                } else if((b[m] - '0' + mark) == 2) {
                    ans = '0' + ans;
                    mark = 1;
                }
            }
        } else if((j < 0)&&(i >= 0)) {
            for(int m = i; m >= 0; m--) {
                if((a[m] - '0' + mark) == 0) {
                    ans = '0' + ans;
                    mark = 0;
                } else if((a[m] - '0' + mark) == 1) {
                    ans = '1' + ans;
                    mark = 0;
                } else if((a[m] - '0' + mark) == 2) {
                    ans = '0' + ans;
                    mark = 1;
                }
            }
        }
        if(mark == 1) ans = '1' + ans;
        return ans;
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int nRow = board.size(), nCol = board[0].size();
        int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};    // x coordinator change around 8 cells
        int dirY[] = {-1, 0, 1, -1, 1, -1, 0, 1};    // y coordinator change around 8 cells
        int count = 0;
        
        // Refresh the board with transition state
        for(int i = 0; i < nRow; i++) {
            for(int j = 0; j < nCol; j++) {
                count = 0;
                // add value from 8 surrounding cells
                for(int m = 0; m < 8; m++) {
                    // make sure the index is within the scope
                    if(((i + dirX[m]) >= 0)&&((i + dirX[m]) < nRow)&&((j + dirY[m]) >= 0)&&((j + dirY[m]) < nCol)) {
                        // here the cell value may be original value or transitin value
                        if((board[i + dirX[m]][j + dirY[m]] == 1)||(board[i + dirX[m]][j + dirY[m]] == 3)) count++;
                    }
                }
                // Get the transition state
                board[i][j] = Count2Tran(board[i][j],count);
            }
        }
        
        // Refresh the board to the new value
        for(int i = 0; i < nRow; i++) {
            for(int j = 0; j < nCol; j++){
                board[i][j] = State2Value(board[i][j]);
            }
        }
    }
    
    // Get the original value in the cell from the current transition state
    int Tran2Ori(int state) {
        int origin;
        if(state == 0) origin = 0;        // state 0 means 0->0, then origin is 0
        else if(state == 1) origin = 1;   // state 1 means 1->1, then origin is 1
        else if(state == 2) origin = 0;   // state 2 means 0->1, then origin is 0
        else if(state == 3) origin = 1;   // state 3 means 1->0, then origin is 1
        return origin;
    }
    
    // Return the transition state from the origin cell state and the live cell count around it
    int Count2Tran(int origin, int count) {
        int state;
        if((origin == 0)&&(count == 3)) state = 2;        // 2 means from 0->1
        else if((origin == 0)&&(count != 3)) state = 0;   // 0 means remaining as 0, 0->0
        else if((origin == 1)&&(count < 2)) state = 3;    // 3 means 1->0
        else if((origin == 1)&&(count == 2)) state = 1;   // 1 mean remaining as 1, 1->1
        else if((origin == 1)&&(count == 3)) state = 1;   // 1 mean remaining as 1, 1->1
        else if((origin == 1)&&(count > 3)) state = 3;    // 3 means 1->0
        return state;
    }
    
    // Get the value after transition
    int State2Value(int state) {
        int value;
        if(state == 0) value = 0;   // state 0 means 0->0
        if(state == 1) value = 1;   // state 1 means 1->1
        if(state == 2) value = 1;   // state 2 means 0->1
        if(state == 3) value = 0;   // state 3 means 1->0
        return value;
        
    }
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        int i, j;
        bool firstC = false, firstR = false;
        
        for(i = 0; i < nRow; i++) {
            for(j = 0; j < nCol; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) firstR = true;
                    if(j == 0) firstC = true;
                    else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for(i = 1; i < nRow; i++) {
            if(matrix[i][0] == 0) {
                for(j = 1; j < nCol; j++) matrix[i][j] = 0;
            }
        }
        
        for(j = 1; j < nCol; j++) {
            if(matrix[0][j] == 0) for(i = 1; i < nRow; i++) matrix[i][j] = 0;
        }
        
        if(firstR) for(j = 0; j < nCol; j++) matrix[0][j] = 0;
        if(firstC) for(i = 0; i < nRow; i++) matrix[i][0] = 0;
    }
    

    
    vector<int> getRow(int rowIndex) {
        vector<int> line = {1};
        vector<int> temp = line;
        int loop = 1;
        while(loop <= rowIndex) {
            for(int i = 1; i < temp.size(); i++) {
                line[i] = temp[i] + temp[i - 1];
            }
            line.push_back(1);
            loop += 1;
            temp = line;
        }
        return line;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int sum = 0, minsum = 0;;
        int dif = INT_MAX;
        if(len < 3) {
            for(int i = 0; i < len; i++) sum += nums[i];
            return sum;
        }
        
        int left, right;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < (len - 2); i++) {
            left = i + 1;
            right = len - 1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) <= dif) {
                    dif = abs(sum - target);
                    minsum = sum;
                }
                if(sum > target) right--;
                if(sum < target) left++;
                if(sum == target) return minsum;
            }
        }
        return minsum;
    }
    
    vector<vector<int>> threeSum2(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        if(len < 3) return ans;
        int left, right, sum, target = 0;
        vector<int> line;
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len - 2;) {
            if(nums[i] > 0) break;
            left = i + 1;
            right = len - 1;
            if(nums[right] < 0) break;
            
            while(left < right) {
                if(nums[right] < 0) break;
                sum = nums[i] + nums[left] + nums[right];
                if(sum > target) {
                    do {
                        right--;
                    } while((nums[right] == nums[right + 1])&&(right > left + 1));
                } else if(sum < target){
                    do {
                        left++;
                    } while((nums[left] == nums[left - 1])&&(left < right - 1));
                } else {
                    line.clear();
                    line.push_back(nums[i]);
                    line.push_back(nums[left]);
                    line.push_back(nums[right]);
                    ans.push_back(line);
                    do {
                        left++;
                    } while((nums[left] == nums[left - 1])&&(left < right - 1));
                    
                    do {
                        right--;
                    } while((nums[right] == nums[right + 1])&&(right > left + 1));
                }
            }
            do {
                i++;
            } while ((i < len - 2) && nums[i] == nums[i - 1]);
        }
        return ans;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans = {};
        unordered_map<int,int> mp;
        for(int i = 0; i < len ; i++) {
            ++mp[nums[i]] = i;
        }
        for(int j = 0; j < len; j++) {
            if((mp.find(target - nums[j]) != mp.end()&&(mp.find(target - nums[j])->second != j))) {
                if(j < mp.find(target - nums[j])->second) {
                    ans.push_back(j);
                    ans.push_back(mp.find(target - nums[j])->second);
                } else {
                    ans.push_back(mp.find(target - nums[j])->second);
                    ans.push_back(j);
                }
                return ans;
            }
        }
               return ans;
    }
    
    vector<int> countBits(int num) {
        vector<int> ans(1,0);
        for(int i = 1; i <= num; i++) {
            ans.push_back(ans[i - pow(2,floor(log2(i)))] + 1);
        }
        return ans;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (root == p) || (root == q))  return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        return (left != NULL)?left:right;
    }
    
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
            if(p->val > root->val && q->val > root->val) root = root->right;
            else if(p->val < root->val && q->val < root->val) root = root->left;
            else break;
        }
        return root;
        /*if(root != NULL) {
         while((p->val-root->val)*(q->val-root->val) > 0) {
         root  = (root->val > p->val ? root->left:root->right);
         }
         }
         return root;*/
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        int temp = 0, a = 0, b = 0;
        for(int i = 0; i < len; i++) temp ^= nums[i];
        int mask = temp & (~temp + 1);
        for(int i = 0; i < len; i++) {
            if(nums[i] & mask) a ^= nums[i];
            else b ^= nums[i];
        }
        return vector<int> {a,b};
    }
    
    int missingNumber(vector<int>& nums) {
        /*int len = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i <= len; ++i) mp[i]++;
        for(int j = 0; j < len; ++j) mp[nums[j]]--;
        unordered_map<int,int>::iterator it;
        for(it = mp.begin(); it != mp.end(); ++it) {
            if(it->second == 1) break;
        }
        return it->first;
        */
        
        int len = nums.size();
        long sum1 = 0, sum2 = 0;
        for(int i = 0; i <= len; i++) {
            sum1 += i;
            if(i < len) sum2 += nums[i];
        }
        
        return sum1 - sum2;
    }
    
    ListNode* sortList(ListNode* head) {
        if((head == NULL) || (head->next == NULL)) return head;
        
        ListNode* fast = head->next, *slow = head;
        
        while((fast != NULL)&&(fast->next != NULL)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head),sortList(fast));
    }
    
    ListNode* merge(ListNode* head, ListNode* mid){
        ListNode* l1 = head, *l2 = mid;
        ListNode ans(0);
        ListNode* curr = &ans;
        
        while((l1 != NULL)&&(l2 != NULL)){
            if(l1->val > l2->val) {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            } else {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
        }
        if(l1 == NULL) curr->next = l2;
        if(l2 == NULL) curr->next = l1;
        
        return ans.next;
    }
    
    
    int addDigits(int num) {
        return (num - 9*((num - 1)/9));
    }
    
    int bulbSwitch(int n) {
        return sqrt(n);
    }
    
    /*
     Ternery System
      0 1 2
    0 0 1 2
    1 1 2 0
    2 2 0 1
     */
    int singleNumber2(vector<int>& nums) {
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < nums.size(); ++i) {
            two |= one & nums[i];
            one ^= nums[i];
            three = one & two;
            one = one ^ three;
            two = two ^ three;
        }
        return one;
    }
    
    int singleNumber1(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) res = res ^ nums[i];
        return res;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        
        int i;
        for(i = n - 1; i >= 1; i--) {
            if(nums[i] > nums[i - 1]) {
                int m = n - 1;
                while(m > i - 1) {
                    if(nums[m] > nums[i - 1]) {
                        swap(nums[m], nums[i - 1]);
                        break;
                    }
                    m--;
                }
                sort(nums.begin() + i, nums.end());
                break;
            }
        }
        if(i == 0) {
            for(int j = 0; j < n/2; j++) {
                int temp = nums[j];
                nums[j] = nums[n - 1 - j];
                nums[n - 1 - j] = temp;
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans2.push_back(nums);
        permute_helper(nums, 1);
        return ans2;
    }
    void permute_helper(vector<int>& nums, int begin) {
        if(begin >= nums.size()) return;
        permute_helper(nums, begin + 1);
        
        for(int i = 0; i< begin; i++) {
            swap(nums[i], nums[begin]);
            ans2.push_back(nums);
            permute_helper(nums, begin + 1);
            swap(nums[i], nums[begin]);
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> l(k,0);
        int i = 0;
        
        while(i >= 0) {
            l[i]++;
            if(l[i] > n) i--;
            else if(i == k - 1) ans.push_back(l);
            else {
                i++;
                l[i] = l[i - 1];
            }
        }
        return ans;
    }
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        stack<TreeNode*> treeStack;
        
        while(1) {
            if(root != NULL) {
                ans.push_back(root->val);
                if(root->right != NULL) treeStack.push(root->right);
                root = root->left;
            } else {
                if(treeStack.size() == 0) break;
                else {
                    root = treeStack.top();
                    treeStack.pop();
                }
            }
        }
        return ans;
    }
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        while((root != NULL)||(st.size() != 0)) {
            ans.push_back(root->val);
            if(root->right != NULL) st.push(root->right);
            if(root->left != NULL) root = root->left;
            else if(st.size() != 0) {
                root = st.top();
                st.pop();
            } else root = NULL;
        }
        return ans;
    }
    
    
    vector<int> inorderTraversal_Iter(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<TreeNode*> ord;
        TreeNode* node = root;
        while(node) {
            while(node) {
                if(node->right != NULL) ord.push(node->right);
                ord.push(node);
                node = node->left;
            }
            node = ord.top();
            ord.pop();
            
            while(!ord.empty()&&(node->right == NULL)) {
                ans.push_back(node->val);
                node = ord.top();
                ord.pop();
            }
            
            ans.push_back(node->val);
            
            if(!ord.empty()) {
                node = ord.top();
                ord.pop();
            } else node = NULL;
        }
        
        
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        tra(root);
        return ans;
    }
    
    void tra(TreeNode* root) {
        if(!root) return;
        TreeNode* leftOri = root;
        stack<TreeNode*> parentSt;
        parentSt.push(leftOri);
        while(leftOri->left) {
            parentSt.push(leftOri->left);
            leftOri = leftOri->left;
        }
        while(!parentSt.empty()) {
            TreeNode* tempParent = parentSt.top();
            ans.push_back(tempParent->val);
            if(tempParent->right) tra(tempParent->right);
            parentSt.pop();
        }
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left){
            TreeNode* p=root->left;
            while(p->right) p=p->right;
            if(p->val >= root->val) return false;
        }
        if(root->right){
            TreeNode* p=root->right;
            while(p->left) p=p->left;
            if(p->val <= root->val) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
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
        vector<vector<int>> pascalTri;
        if(numRows == 0) return pascalTri;
        vector<int> line(1,1);
        pascalTri.push_back(line);
        
        for(int i = 1; i < numRows; i++) {
            line = {1};
            for(int j = 1; j <= i; j++) {
                line.push_back(pascalTri[i - 1][j] + pascalTri[i - 1][j - 1] );
            }
            pascalTri.push_back(line);
        }
        return pascalTri;
    }
    vector<vector<int>> generate2(int numRows) {
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