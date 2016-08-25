//
//  Solution.hpp
//  HiC++
//
//  Created by My AD on 6/24/16.
//  Copyright © 2016 My AD. All rights reserved.
//

using namespace std;

#ifndef Solution_hpp
#define Solution_hpp

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include "MyStruct.h"
#include "MyStack.h"
#include "maxSlidingWindow.h"



class Solution {
private:
    stack<int> myQueue,trans;
    vector<int> ans;
    vector<vector<int>> ans2;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
    
    bool containsDuplicate(vector<int>& nums);
    
    bool containsNearbyDuplicate(vector<int>& nums, int k);
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
    
    int countNumbersWithUniqueDigits(int n);
    
    string getPermutation(int n, int k);
    
    vector<int> intersectII(vector<int>& nums1, vector<int>& nums2);
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    
    int mySqrt(int x);
    
    int divide(int dividend, int divisor);
    
    int integerBreak(int n);
    
    double myPow(double x, int n);
    
    TreeNode* sortedListToBST(ListNode* head);
    
    ListNode* getMidNode(ListNode* head, ListNode* end);
    
    TreeNode* sortedArrayToBST(vector<int>& nums);
    
    TreeNode* recurBuildBST(vector<int>& nums, int left, int right);
    
    TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder);
    
    TreeNode* recurBuildFromInAndPost(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int poLeft, int poRight);
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    
    TreeNode* recurBuildFromPreAndIn(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight);
    
    bool isValidSudoku(vector<vector<char>>& board);
    
    ListNode* removeElements(ListNode* head, int val);
    
    void moveZeroes(vector<int>& nums);
    
    int removeElement(vector<int>& nums, int val);
    
    int maxProfitIII(vector<int>& prices);
    
    vector<int> findMaxPro(vector<int>& prices);
    
    int maxProfitII(vector<int>& prices);
    
    int compareVersion(string version1, string version2);
    
    string countAndSay(int n);
    
    int maxProfit(vector<int>& prices);
    
    bool isBalanced(TreeNode* root);
    
    int depth(TreeNode* root);
    
    int minDepth(TreeNode* root);
    
    TreeNode* invertTree(TreeNode* root);
    
    string multiply(string num1, string num2);
    
    string multiply2(string num1, string num2);
    
    vector<int> plusOne(vector<int>& digits);
    
    string addBinary(string a, string b);
    
    void gameOfLife(vector<vector<int>>& board);
    
    // Get the original value in the cell from the current transition state
    int Tran2Ori(int state);
    
    // Return the transition state from the origin cell state and the live cell count around it
    int Count2Tran(int origin, int count);
    
    // Get the value after transition
    int State2Value(int state);
    
    void setZeroes(vector<vector<int>>& matrix);
    
    vector<int> getRow(int rowIndex);
    
    int threeSumClosest(vector<int>& nums, int target);
    
    vector<vector<int>> threeSum2(vector<int>& nums);
    
    vector<int> twoSum(vector<int>& nums, int target);
    
    vector<int> countBits(int num);
    
    vector<int> singleNumber(vector<int>& nums);
    
    int missingNumber(vector<int>& nums);
    
    ListNode* sortList(ListNode* head);
    
    ListNode* merge(ListNode* head, ListNode* mid);
    
    
    int addDigits(int num);
    
    int bulbSwitch(int n);
    
    /*
     Ternery System
     0 1 2
     0 0 1 2
     1 1 2 0
     2 2 0 1
     */
    int singleNumber2(vector<int>& nums);
    
    int singleNumber1(vector<int>& nums);
    
    void nextPermutation(vector<int>& nums);
    
    vector<vector<int>> permute(vector<int>& nums);
    
    void permute_helper(vector<int>& nums, vector<vector<int>>& ans, int start);
    
    vector<vector<int>> combine(int n, int k);
    
    vector<int> preorderTraversal(TreeNode* root);
    
    vector<int> preorderTraversal2(TreeNode* root);
    
    vector<int> inorderTraversal_Iter(TreeNode* root);
    
    vector<int> inorderTraversal(TreeNode* root);
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
    
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q);
    
    void tra(TreeNode* root);
    
    bool isValidBST(TreeNode* root);
    
    vector<vector<int>> levelOrder(TreeNode* root);
    
    int minPathSum(vector<vector<int>>& grid);
    
    int robII(vector<int>& nums);
    
    int rob(vector<int>& nums);
    
    int numSquares(int n);
    
    int nthUglyNumber(int n);
    
    vector<vector<int>> generate(int numRows);
    
    vector<vector<int>> generate2(int numRows);
    
    bool isAnagram(string s, string t);
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    
    int removeDuplicates(vector<int>& nums);
    
    ListNode* deleteDuplicates(ListNode* head);
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    
    bool isPalindrome(string s);
    
    bool isPalindrome(ListNode* head);
    
    ListNode* reverse(ListNode* oldhead);
    
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
    
    int maxArea(vector<int>& height);
    
    int minSubArrayLen(int s, vector<int>& nums);
    
    // Push element x to the back of queue.
    void push(int x);
    
    // Removes the element from in front of queue.
    void pop(void);
    
    // Get the front element.
    int peek(void);
    
    // Return whether the queue is empty.
    bool empty(void);
    
    bool isValid(string s);
    
    int calculate(string s);
    
    vector<int> cal(string str, int stpos);
    
    int strStr(string haystack, string needle);
    
    vector<int> spiralOrder(vector<vector<int>>& matrix);
    
    bool isPowerOfTwo(int n);
    
    int myAtoi(string str);
    
    string convert(string s, int numRows);
    
    string convertToTitle(int n);
    
    void printAZ09();
    
    double AddFun(char* in, int NumLen, double PreRst);
    
    double Cal(char* in);
    
    vector<vector<string>> partition(string s);
    void partition_helper(const string& s, int start, int end, vector<string>& line, vector<vector<string>>& ans);
    bool isPalindrome(const string& s, int left, int right);
    
    int minimumTotal(vector<vector<int>>& triangle);
    
    vector<int> productExceptSelf(vector<int>& nums);
    
    vector<vector<int>> subsets(vector<int>& nums);
    void subsets_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur, int begin);
    
    ListNode *detectCycle(ListNode *head);
    
    int findDuplicate(vector<int>& nums);
    
    ListNode* reverseBetween(ListNode* head, int m, int n);
    
    ListNode* partition(ListNode* head, int x);
    
    ListNode* swapPairs(ListNode* head);
    
    ListNode* rotateRight(ListNode* head, int k);
    
    string largestNumber(vector<int>& nums);
    
    bool isPowerOfFour(int num);
    
    int getSum(int a, int b);
    
    vector<string> findRepeatedDnaSequences(string s);
    
    vector<int> topKFrequent(vector<int> &nums, int k);
    
    int lengthOfLongestSubstring(string s);
    
    bool wordBreak(string s, unordered_set<string>& wordDict);
    bool wordBreakHelper(const string s, unordered_set<string>& wordDict, int begin);
    
};

int subConnectedCells(vector<vector<int>>& grid, int x, int y, int row, int col) {
    // Not a cell, return count 0
    if(grid[x][y] == 0) return 0;
    // If it’s the bottom right lot, return 1 since no more sub lot.
    if(x == row - 1 && y == col - 1) return 1;
    // If reach the bottom row, just search the lot on the right
    if(x == row - 1) return subConnectedCells(grid, x, y + 1, row, col) + 1;
    // If reach the rightmost row, just search the lot below
    if(y == col - 1) return subConnectedCells(grid, x + 1, y, row, col) + 1;
    // Return sum of cell count from right, below and right below lots.
    return subConnectedCells(grid, x + 1, y, row, col) + subConnectedCells(grid, x + 1, y + 1, row, col) + subConnectedCells(grid, x, y + 1, row, col) + 1;
}

int connectedCells(vector<vector<int>>& grid) {
    int row, col, maxCount = 0;
    if((row = grid.size()) == 0) return 0;
    if((col = grid[0].size()) == 0) return 0;
    for(int i = 0; i < row - 1; ++i) {
        for(int j = 0; j < col - 1; ++j) {
            if(grid[i][j] != 0 ) {
                grid[i][j] = subConnectedCells(grid, i, j, row, col);
            }
        }
    }
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            maxCount = max(maxCount, grid[i][j]);
        }
    }
    return maxCount;
}


bool Solution::wordBreak(string s, unordered_set<string>& wordDict) {
    if(s.length() == 0) return false;
    return wordBreakHelper(s, wordDict, 0);
}
bool Solution::wordBreakHelper(const string s, unordered_set<string>& wordDict, int begin) {
    if(begin < s.length()) {
        for(int i = 0; i <= s.length() - begin; ++i) {
            if(wordDict.find(s.substr(begin, i)) != wordDict.end()) {
                return wordBreakHelper(s, wordDict, begin + i);
            }
        }
        return false;
    } else return true;
}

int maxPoints(vector<Point>& points) {
    unordered_map<int,int> xMp, yMp;
    int maxCount = 0;
    for(int i = 0; i < points.size(); ++i) {
        xMp[points[i].x]++;
        yMp[points[i].y]++;
    }
    
    for(auto it = xMp.begin(); it !=xMp.end(); ++it) {
        maxCount = max(maxCount, it->second);
    }
    for(auto it = yMp.begin(); it !=yMp.end(); ++it) {
        maxCount = max(maxCount, it->second);
    }
    return maxCount;
}

int Solution::lengthOfLongestSubstring(string s) {
    vector<int> dict(256,-1);
    int start = -1, maxLen = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(dict[s[i]] > -1) {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

vector<int> Solution::topKFrequent(vector<int> &nums, int k) {
    unordered_map<int,int> myMap;
    priority_queue<pair<int,int>> pq;
    vector<int> ans;
    for(auto e : nums) myMap[e]++;
    for(auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        pq.emplace(iter->second, iter->first);
    }
    while(k) {
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return ans;
}

vector<string> Solution::findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.length() < 11) return ans;
    unordered_map<int,int> hashMap;
    int hashKey = 0;
    for(int i = 0; i < 9; ++i) hashKey = (hashKey << 2) | ((s[i] - 'A' + 1) % 5);
    for(int j = 9; j < s.length(); ++j) {
        hashKey = ((hashKey << 2) | ((s[j] - 'A' + 1) % 5)) & 0xfffff;
        if(hashMap[hashKey]++ == 1) {
            ans.push_back(s.substr(j - 9, 10));
        }
    }
    return ans;
}


int Solution::getSum(int a, int b) {
    int carry = 0, sum = 0, bitA, bitB;
    for(int i = 0; i < 32; ++i) {
        bitA = a & (1 << i);
        bitB = b & (1 << i);
        carry = carry << i;
        sum = sum + bitA^bitB^carry;
        if((bitA&bitB)||(bitB&carry)||(bitA&carry)) carry = 1;
        else carry = 0;
    }
    return sum;
}

bool Solution::isPowerOfFour(int num) {
    if(num <= 0) return false;
    if(num == 1) return true;
    if(num%4 != 0) return false;
    return isPowerOfFour(num/4);
}

static bool compareFunction(int x, int y) {
//    string strX = to_string(x), strY = to_string(y);
//    return strX + strY > strY + strX;
     int xLen = 0, yLen = 0;
     int tmp1 = x, tmp2 = y;
     deque<int> xDigit, yDigit;
     while(tmp1) {
         xLen++;
         xDigit.push_back(tmp1%10);
         tmp1 /= 10;
     }
     while(tmp2) {
         yLen++;
         yDigit.push_back(tmp2%10);
         tmp2 /= 10;
     }
     
     if(xLen > yLen) {
         for(int i = xLen - 1; i >= yLen; --i) {
             yDigit.push_back(xDigit[i]);
         }
     } else if(xLen < yLen) {
         for(int i = yLen - 1; i >= xLen; --i) {
             xDigit.push_back(yDigit[i]);
         }
     }
     
     for(int j = 0; j < max(xLen, yLen); ++j) {
         if(xDigit[j] < yDigit[j]) return true;
         if(xDigit[j] > yDigit[j]) return false;
     }
     return false;
}

string Solution::largestNumber(vector<int>& nums) {
    string ans = "";
    sort(nums.begin(), nums.end(), compareFunction);
    if(nums[0] == 0) return "0";
    for(int i = 0; i < nums.size(); ++i) {
        ans += to_string(nums[i]);
    }
    return ans;
}

void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL) return;
    ListNode *slow = head, *fast = head;
    ListNode *pre = NULL, *cur, *next;
    ListNode *revHead, *tempLeft, *tempRight;
    
    // Find the midpoint
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the List from slow
    cur = slow;
    while(cur && cur->next) {
        next = cur->next;;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    cur->next = pre;
    revHead = cur;
    
    // Reorder the list
    cur = head;
    while(cur != NULL && revHead != NULL) {
        tempLeft = cur->next;
        tempRight = revHead->next;
        cur->next = revHead;
        revHead->next = tempLeft;
        cur = tempLeft;
        revHead = tempRight;
    }
    return;
}

ListNode* Solution::rotateRight(ListNode* head, int k) {
    ListNode newHead(0);
    newHead.next = head;
    ListNode newhead(0), *fast = head, *slow;
    if(head == NULL || head->next == NULL) return head;
    int count = 1, len = 1;
    // Find the length of the ListNode in case the rotate place is very large
    while(fast->next) {
        len++;
        fast = fast->next;
    }
    // Find the relative place shift based on the ListNode length
    k = len - k%len;
    if(k == 0) return head;
    fast = head;
    count = 1;
    // Find the node ready to rotate
    while(count < k) {
        fast = fast->next;
        count++;
    }
    slow = fast;
    // Find the end of ListNode
    while(fast&&fast->next) fast = fast->next;
    fast->next = newHead.next;
    newHead.next = slow->next;
    slow->next = NULL;
    return newHead.next;
}

ListNode* Solution::swapPairs(ListNode* head) {
    ListNode newHead(0);
    newHead.next = head;
    ListNode *pre = &newHead, *cur = head, *next, *temp = NULL;
    while(cur && cur->next) {
        next = cur->next;
        temp = next->next;
        pre->next = next;
        cur->next = temp;
        next->next = cur;
        pre = cur;
        cur = cur->next;
    }
    return newHead.next;
}

ListNode* Solution::partition(ListNode* head, int x) {
    ListNode newHead(INT_MIN);
    newHead.next = head;
    ListNode *cur = head, *small = &newHead, *pre = &newHead;
    while(cur) {
        if(small->next && small->next->val < x) small = small->next;
        if(cur->val < x && pre->val >= x) {
            pre->next = cur->next;
            cur->next = small->next;
            small->next = cur;
            cur = pre->next;
            small = small->next;
        } else {
            cur = cur->next;
            pre = pre->next;
        }
    }
    return newHead.next;
}

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL||head->next == NULL) return head;
    ListNode newHead(0);
    newHead.next = head;
    ListNode *pre = &newHead, *cur = head, *next;
    int count = 1;
    if(m == n) return head;
    while(count < n) {
        while(count++ < m) {
            pre = pre->next;
            cur = cur->next;
        }
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return newHead.next;
}


int Solution::findDuplicate(vector<int>& nums) {
    
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


ListNode* Solution::detectCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode *fast = head, *slow = head, *entry = head;
    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            while(slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return nullptr;
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    if(nums.empty()) return ans;
    vector<int> cur;
    ans.push_back(cur);
    subsets_helper(nums, ans, cur, 0);
    return ans;
}

void Solution::subsets_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur, int begin) {
    if(begin >= nums.size()) return;
    for(int i = begin; i < nums.size(); ++i) {
        cur.push_back(nums[i]);
        ans.push_back(cur);
        subsets_helper(nums, ans, cur, i + 1);
        cur.pop_back();
    }
}

vector<int> Solution::productExceptSelf(vector<int>& nums) {
//    if(nums.size() == 0) return vector<int> ();
//    vector<int> ans(nums.size());
//    int backProduct = 1;
//    ans[0] = 1;
//    for(int i = 1; i < nums.size(); ++i) ans[i] = ans[i - 1] *nums[i - 1];
//    
//    for(int i  = nums.size() - 2; i >= 0; --i) {
//        backProduct *= nums[i + 1];
//        ans[i] *= backProduct;
//    }
//    return ans;
    if(nums.empty()) return vector<int> ();
    vector<int> ans(nums.size(),1);
    int left = 1, right = 1;
    for(int i = 0; i < nums.size(); ++i) {
        ans[i] *= left;
        left *= nums[i];
        ans[nums.size() - i - 1] *= right;
        right *= nums[nums.size() - i - 1];
    }
    return ans;
    
}

int Solution::minimumTotal(vector<vector<int>>& triangle) {
    vector<int> dp(triangle.size(),0);
    int mark = 0;
    dp[0] = triangle[0][0];
    // for(int i = 1; i < triangle.size(); i++) {
    //     dp[1] = dp[0] + max(triangle[i][mark], triangle[i][mark + 1]);
    // }
    return dp[dp.size() - 1];
}

vector<vector<string>> Solution::partition(string s) {
    vector<vector<string>> ans = {};
    vector<string> line = {};
    partition_helper(s, 0, s.length(), line, ans);
    
    return ans;
}

void Solution::partition_helper(const string& s, int start, int len, vector<string>& line, vector<vector<string>>& ans) {
    if(len <= 0) {
        ans.push_back(line);
        return;
    }
    
    for(int i = 0; i < len; i++) {
        if(isPalindrome(s, start, start + i)) {
            string ss = s.substr(start, i + 1);
            line.push_back(ss);
            partition_helper(s, start + i + 1, len - i -1, line, ans);
            line.pop_back();
        }
    }
}

bool Solution::isPalindrome(const string& s, int left, int right) {
    while(left <= right) {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}



bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<long long> mySet;
    for(int i = 0; i < nums.size(); i++) {
        if(i > k) mySet.erase(nums[i - k - 1]);
        auto it = mySet.lower_bound(nums[i] - t);
        if((it != mySet.end())&&(*it - nums[i] <=t)) return true;
        mySet.insert(nums[i]);
    }
    return false;
}

bool Solution::containsDuplicate(vector<int>& nums) {
    if((nums.size() == 0) || (nums.size() == 1)) return false;
    
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) return true;;
    }
    return false;
}

bool Solution::containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int,int> myMap;
    for(int i = 0; i < nums.size(); i++) {
        if(myMap.find(nums[i]) != myMap.end()) if(i - myMap[nums[i]] <= k) return true;
        myMap[nums[i]] = i;
    }
    return false;
}

vector<Interval> Solution::insert(vector<Interval>& intervals, Interval newInterval) {
    // Insert the newInterval into right position according to start
    int i = 0;
    for(i = 0; i < intervals.size(); i++) {
        if(newInterval.start < intervals[i].start) {
            intervals.insert(intervals.begin() + i, newInterval);
            break;
        }
    }
    if(i == intervals.size()) intervals.push_back(newInterval);
    
    // Merge the overlap Interval
    Interval* temp = &intervals[0];
    for(int j = 1; j < intervals.size(); j++) {
        // Find the interval that need to merge
        if(temp->end < intervals[j].start) temp = &intervals[j];
        else if((temp->end >= intervals[j].start)&&(temp->end <=intervals[j].end)) {
            // If the end of the interval we want to merge is within one of the interval, merge
            // these two into the first one and mark the second interval.
            temp->end = intervals[j].end;
            intervals[j].start = -1;
            intervals[j].end = -1;
        } else if(temp->end > intervals[j].end) {
            // If an interval is within the range of the interval we want to merge, marker it.
            intervals[j].start = -1;
            intervals[j].end = -1;
        }
    }
    
    // Get result
    vector<Interval> res;
    // Get the intervals without marks.
    for(int n = 0; n < intervals.size(); n++) {
        if(intervals[n].start != -1) res.push_back(intervals[n]);
    }
    return res;
}

int Solution::countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        int temp = 9;
        for(int j = 1; j < i; j++) {
            temp *= (10 - j);
        }
        ans += temp;
    }
    return ans;
}

string Solution::getPermutation(int n, int k) {
    int total = 1;
    for(int i = 1; i <= n; i++) total *= i;
    
    int d = k - 1;
    string ans = "", charPool = "123456789";
    
    for(int j = n; j > 0; j--) {
        total /= j;
        ans += charPool[d/total];
        charPool.erase(d/total,1);
        d = d%total;
    }
    return ans;
}

vector<int> Solution::intersectII(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans = {};
    if(nums1.size() == 0 && nums2.size() == 0) return ans;
    
    unordered_map<int,int> map;
    
    for(int i = 0; i < nums1.size(); i++) map[nums1[i]]++;
    
    for(int j = 0; j < nums2.size(); j++) {
        if(map.find(nums2[j]) != map.end() && map.find(nums2[j])->second > 0) {
            ans.push_back(nums2[j]);
            map[nums2[j]]--;
        }
    }
    
    return ans;
}

vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans = {};
    if((nums1.size() == 0) || (nums2.size() == 0)) return ans;
    
    unordered_map<int,int> map;
    for(int i = 0; i < nums1.size();i++) map[nums1[i]] = 0;
    
    for(int j = 0; j < nums2.size(); j++) {
        if(map.find(nums2[j]) != map.end() && map.find(nums2[j])->second == 0) {
            ans.push_back(nums2[j]);
            map[nums2[j]] = 1;
        }
    }
    return ans;
}

int Solution::mySqrt(int x) {
    if(x < 2) return x;
    long int i = x/2;
    while(i*i > x) i = (i + x/i)/2;
    return i;
}

int Solution::divide(int dividend, int divisor) {
    if((divisor == 0)||(dividend == INT_MIN && divisor == -1)) return INT_MAX;
    bool positive;
    long long count = 0, power;
    if((dividend > 0) ^ (divisor > 0)) positive = false;
    else positive = true;
    long long a = abs((long long) dividend);
    long long b = abs((long long) divisor), c = abs((long long) divisor);
    
    while(b <= a) {
        power = 1;
        c = b;
        while(c<<1 < a) {
            c <<= 1;
            power <<= 1;
        }
        count += power;
        a -= c;
    }
    if(!positive) count = -count;
    return count;
}

int Solution::integerBreak(int n) {
    if(n < 4) return (n/2)*(n - n/2);
    if(n%3 == 0) return pow(3,n/3);
    else if(n%3 == 2) return pow(3,n/3)*2;
    return pow(3,n/3 - 1)*4;
}

double myPow(double x, int n) {
    if(n == 0 || x == 1) return 1.0;
    if(n == INT_MIN) return (double) 1/(x*myPow(x,INT_MAX));
    if(n < 0) return (double) 1/myPow(x,0-n);
    if(n%2 == 0) return myPow(x*x, n/2);
    return x*myPow(x,n-1);
}

TreeNode* Solution::sortedListToBST(ListNode* head) {
    if(!head) return nullptr;
    if(head->next == nullptr) return new TreeNode(head->val);
    
    TreeNode* root = new TreeNode(getMidNode(head, nullptr)->val);
    root->left = new TreeNode(getMidNode(head, getMidNode(head, nullptr))->val);
    root->right = new TreeNode(getMidNode(getMidNode(head, nullptr)->next, nullptr)->val);
    
    return root;
}


ListNode* Solution::getMidNode(ListNode* head, ListNode* end) {
    if(!head) return nullptr;
    if(head == end) return head;
    ListNode* fast = head->next, *slow = head;
    
    while((fast != end)&&(fast->next != end)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
    //        if(nums.size() == 0) return nullptr;
    //        if(nums.size() == 1) {
    //            TreeNode* cur = new TreeNode(nums[0]);
    //            return cur;
    //        }
    //
    //        TreeNode* cur = new TreeNode(nums[nums.size()/2]);
    //        vector<int> numLeft = vector<int>(nums.begin(), nums.begin() + nums.size()/2);
    //        vector<int> numRight = vector<int>(nums.begin()+ nums.size()/2 + 1, nums.end());
    //        cur->left = sortedArrayToBST(numLeft);
    //        cur->right = sortedArrayToBST(numRight);
    //        return cur;
    
    if(nums.size() == 0) return nullptr;
    TreeNode* cur = recurBuildBST(nums, 0 , nums.size() - 1);
    return cur;
}
TreeNode* Solution::recurBuildBST(vector<int>& nums, int left, int right) {
    if(left > right) return nullptr;
    if(left == right) return new TreeNode(nums[(left + right)/2]);
    
    TreeNode* cur = new TreeNode(nums[(left + right)/2]);
    cur->left = recurBuildBST(nums, left, (left + right)/2 - 1);
    cur->right = recurBuildBST(nums, (left + right)/2 + 1, right);
    return cur;
}

TreeNode* Solution::buildTree2(vector<int>& inorder, vector<int>& postorder) {
    int inLen = inorder.size(), poLen = postorder.size();
    if(inLen != poLen) return NULL;
    TreeNode* root = recurBuildFromInAndPost(inorder, 0, inLen - 1, postorder, 0, poLen - 1);
    return root;
}

TreeNode* Solution::recurBuildFromInAndPost(vector<int>& inorder, int inLeft, int inRight, vector<int>& postorder, int poLeft, int poRight) {
    if((inLeft > inRight)||(poLeft > poRight)) return NULL;
    
    TreeNode* cur = new TreeNode(postorder[poRight]);
    int i = inRight;
    for(;i >= 0; i--) {
        if(inorder[i] == cur->val)
            break;
    }
    cur->left = recurBuildFromInAndPost(inorder, inLeft, i - 1, postorder, poLeft, poRight - (inRight - i) - 1);
    cur->right = recurBuildFromInAndPost(inorder, i + 1, inRight, postorder, poRight - (inRight - i), poRight - 1);
    return cur;
}


TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preLen = preorder.size(), inLen = inorder.size();
    TreeNode* root = NULL;
    if((preLen != inLen)||!preLen||!inLen) return root;
    
    root = recurBuildFromPreAndIn(preorder, 0, preLen - 1, inorder, 0, inLen - 1);
    
    return root;
}

TreeNode* Solution::recurBuildFromPreAndIn(vector<int>& preorder, int preLeft, int preRight, vector<int>& inorder, int inLeft, int inRight){
    if((preLeft > preRight)||(inLeft > inRight)) return NULL;
    
    TreeNode* cur = new TreeNode(preorder[preLeft]);
    
    int i = inLeft;
    for(;i <= inRight; i++) {
        if(inorder[i] == cur->val) break;
    }
    
    TreeNode* leftNode = recurBuildFromPreAndIn(preorder, preLeft + 1, preLeft + i - inLeft, inorder, inLeft, i - 1);
    TreeNode* rightNode = recurBuildFromPreAndIn(preorder, preLeft + i - inLeft + 1, preRight, inorder, i + 1, inRight);
    cur->left = leftNode;
    cur->right = rightNode;
    return cur;
}

bool Solution::isValidSudoku(vector<vector<char>>& board) {
    /*if(!board.size()) return 0;
     
     map<char,int> mp;
     for(int i = 0; i < board.size(); i++) {
     mp.clear();
     for(int j = 0; j < board[0].size(); j++) {
     if(board[i][j] != '.') {
     mp[board[i][j]]++;
     if(mp[board[i][j]] > 1) return false;
     }
     }
     }
     for(int i = 0; i < board[0].size(); i++) {
     mp.clear();
     for(int j = 0; j < board.size(); j++) {
     if(board[j][i] != '.') {
     mp[board[j][i]]++;
     if(mp[board[j][i]] > 1) return false;
     }
     }
     }
     
     vector<int> dirX = {-1, 0, 1, -1, 1, -1, 0, 1};
     vector<int> dirY = {-1, -1, -1, 0, 0, 1, 1, 1};
     for(int i = 1; i < 8; i += 3) {
     mp.clear();
     for(int j = 1; j < 8; j += 3) {
     mp.clear();
     for(int m = 0; m < 9; m++) {
     if(board[i + dirX[m]][j + dirY[m]] != '.') {
     mp[board[i + dirX[m]][j + dirY[m]]]++;
     if(mp[board[i + dirX[m]][j + dirY[m]]] > 1) return false;
     }
     }
     }
     }
     
     return true;
     */
    if(board.size() == 0){
        return true;
    }
    vector<int> row(10, 0);
    vector<int> col(10, 0);
    vector<int> block(10,0);
    //fill one by one when it`s valid.
    //No need to check all the numbers in one point on the board.
    for(int i = 0;i < 9; ++i){
        for(int j = 0;j < 9; ++j){
            if(board[i][j] != '.'){
                int num = board[i][j] - '0';
                int bit = 1 << num;
                if( (row[i] & bit) || (col[j] & bit) || (block[i / 3 * 3 + j / 3] & bit) ){
                    return false;
                }
                row[i] |= bit;
                col[j] |= bit;
                block[i / 3 * 3 + j / 3] |= bit;
            }
        }
    }
    return true;
}

ListNode* Solution::removeElements(ListNode* head, int val) {
    ListNode* curr = head;
    ListNode root(0);
    root.next = head;
    head = &root;
    
    while(curr) {
        if(curr->val == val) {
            head->next = curr->next;
            curr = curr->next;
        } else {
            head = curr;
            curr = curr->next;
        }
    }
    return root.next;
}

void Solution::moveZeroes(vector<int>& nums) {
    int left = 0, right = 0;
    while(nums[right] != 0) right++;
    while(left <= right) {
        while((nums[right] == 0)&&(right < nums.size())) right++;
        if(right >= nums.size()) right--;
        if(nums[left] == 0) {
            nums[left] = nums[right];
            nums[right] = 0;
        }
        left++;
    }
}

int Solution::removeElement(vector<int>& nums, int val) {
    int left = 0, right = nums.size() - 1;
    while(left <= right) {
        if(nums[left] == val) {
            nums[left] = nums[right];
            right--;
        } else {
            left++;
        }
    }
    return right + 1;
    
    /*int len = nums.size();
     if(!len) return 0;
     int temp;
     int count = 0;
     int swap_pos = 0;
     for(int i = 0; i < len; i++) {
     if(nums[i] == val) {
     while((nums[len - swap_pos - 1] == val)&&(len - swap_pos - 1 > i)) swap_pos++;
     temp = nums[len - swap_pos - 1];
     nums[len - swap_pos - 1] = nums[i];
     nums[i] = temp;
     swap_pos = 0;
     }
     }
     while((nums[len - count - 1] == val) && ((len - count - 1) >= 0)) count++;
     for(int n = 0; n < count; n++) {
     nums.pop_back();
     }
     return nums.size();
     */
}

int Solution::maxProfitIII(vector<int>& prices) {
    vector<int> firstAns, secondAns, seg1, seg2;
    firstAns = findMaxPro(prices);
    if(firstAns[1] - 1 > 0) {
        for(int i = 0; i < firstAns[1] - 1; i++) seg1.push_back(prices[i]);
    }
    if(firstAns[2] + 1 < prices.size()) {
        for(int i = firstAns[2] + 1; i < prices.size(); i++) seg2.push_back(prices[i]);
    }
    
    secondAns  = max(findMaxPro(seg1),findMaxPro(seg2));
    return (firstAns[0] + secondAns[0]);
}

vector<int> Solution::findMaxPro(vector<int>& prices) {
    int maxProfit = 0, minPrice = INT_MAX;
    int minIdx = 0, maxIdx = 0, tempMinIdx = 0;
    vector<int> ans;
    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];
            tempMinIdx = i;
        }
        if(maxProfit < (prices[i] - minPrice)) {
            maxProfit = (prices[i] - minPrice);
            minIdx = tempMinIdx;
            maxIdx = i;
        }
    }
    ans.push_back(maxProfit);
    ans.push_back(minIdx);
    ans.push_back(maxIdx);
    return ans;
}

int Solution::maxProfitII(vector<int>& prices) {
    int maxProfit = 0;
    for( int i = 1; i < prices.size(); i++) {
        if(prices[i] > prices[i - 1]) maxProfit += (prices[i] - prices[i - 1]);
    }
    return maxProfit;
}

int Solution::compareVersion(string version1, string version2) {
    int len1 = version1.length();
    int len2 = version2.length();
    int i = 0, j = 0;
    string strVer1 = "", strVer2 = "";
    while((i < len1)||(j < len2)) {
        while((i < len1)&&(version1[i] != '.')) {
            strVer1 += version1[i];
            i++;
        }
        while((j < len2)&&(version2[j] != '.')) {
            strVer2 += version2[j];
            j++;
        }
        if(strVer1 == "") {
            if(stoi(strVer2) > 0) return -1;
        } else if(strVer2 == "") {
            if(stoi(strVer1) > 0) return 1;
        } else {
            if(stoi(strVer1) > stoi(strVer2)) return 1;
            else if(stoi(strVer1) < stoi(strVer2)) return -1;
        }
        strVer1 = "";
        strVer2 = "";
        i++;j++;
    }
    return 0;
}

string Solution::countAndSay(int n) {
    string ans = "1";
    if(n == 0) return "";
    string num;
    char digit;
    int count = 1;
    int i = 0;
    while(--n) {
        while(i < ans.length()) {
            digit = ans[i];
            while(ans[i] == ans[i + 1]) {
                count++;
                i++;
            }
            i++;
            num = num + (char)(count + 48) + digit;
            count = 1;
        }
        ans = num;
        num = "";
        
        i = 0;
    }
    return ans;
}

int Solution::maxProfit(vector<int>& prices) {
    int maxPro = 0, minPri = INT_MAX;
    for(int i = 0; i < prices.size();i++) {
        minPri = min(minPri, prices[i]);
        maxPro = max(maxPro, prices[i] - minPri);
    }
    return maxPro;
}

bool Solution::isBalanced(TreeNode* root) {
    if(!root) return true;
    if(abs(depth(root->left) - depth(root->right)) > 1) return false;
    else return (isBalanced(root->left)&isBalanced(root->right));
}

int Solution::depth(TreeNode* root) {
    if(!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

int Solution::minDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left) return (minDepth(root->right) + 1);
    if(!root->right) return (minDepth(root->left) + 1);
    return (min(minDepth(root->left),minDepth(root->right)) + 1);
    
}

TreeNode* Solution::invertTree(TreeNode* root) {
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

string Solution::multiply(string num1, string num2) {
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

string Solution::multiply2(string num1, string num2) {
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

vector<int> Solution::plusOne(vector<int>& digits) {
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

string Solution::addBinary(string a, string b) {
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

void Solution::gameOfLife(vector<vector<int>>& board) {
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
int Solution::Tran2Ori(int state) {
    int origin;
    if(state == 0) origin = 0;        // state 0 means 0->0, then origin is 0
    else if(state == 1) origin = 1;   // state 1 means 1->1, then origin is 1
    else if(state == 2) origin = 0;   // state 2 means 0->1, then origin is 0
    else if(state == 3) origin = 1;   // state 3 means 1->0, then origin is 1
    return origin;
}

// Return the transition state from the origin cell state and the live cell count around it
int Solution::Count2Tran(int origin, int count) {
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
int Solution::State2Value(int state) {
    int value;
    if(state == 0) value = 0;   // state 0 means 0->0
    if(state == 1) value = 1;   // state 1 means 1->1
    if(state == 2) value = 1;   // state 2 means 0->1
    if(state == 3) value = 0;   // state 3 means 1->0
    return value;
    
}

void Solution::setZeroes(vector<vector<int>>& matrix) {
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

vector<int> Solution::getRow(int rowIndex) {
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

int Solution::threeSumClosest(vector<int>& nums, int target) {
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

vector<vector<int>> Solution::threeSum2(vector<int>& nums) {
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

vector<int> Solution::twoSum(vector<int>& nums, int target) {
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

vector<int> Solution::countBits(int num) {
    vector<int> ans(1,0);
    for(int i = 1; i <= num; i++) {
        ans.push_back(ans[i - pow(2,floor(log2(i)))] + 1);
    }
    return ans;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
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

vector<int> Solution::singleNumber(vector<int>& nums) {
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

int Solution::missingNumber(vector<int>& nums) {
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

ListNode* Solution::sortList(ListNode* head) {
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

ListNode* Solution::merge(ListNode* head, ListNode* mid){
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

int Solution::addDigits(int num) {
    return (num - 9*((num - 1)/9));
}

int Solution::bulbSwitch(int n) {
    return sqrt(n);
}

/*
 Ternery System
 0 1 2
 0 0 1 2
 1 1 2 0
 2 2 0 1
 */
int Solution::singleNumber2(vector<int>& nums) {
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

int Solution::singleNumber1(vector<int>& nums) {
    int res = 0;
    for(int i = 0; i < nums.size(); i++) res = res ^ nums[i];
    return res;
}

void Solution::nextPermutation(vector<int>& nums) {
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

vector<vector<int>> Solution::permute(vector<int>& nums) {
    vector<vector<int>> ans = {};
    permute_helper(nums, ans, 0);
    return ans;
}

void Solution::permute_helper(vector<int>& nums, vector<vector<int>>& ans, int start) {
    if(start >= nums.size()) ans.push_back(nums);
    
    for(int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute_helper(nums, ans, start + 1);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> Solution::combine(int n, int k) {
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

vector<int> Solution::preorderTraversal(TreeNode* root) {
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

vector<int> Solution::preorderTraversal2(TreeNode* root) {
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

vector<int> Solution::inorderTraversal_Iter(TreeNode* root) {
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

vector<int> Solution::inorderTraversal(TreeNode* root) {
    tra(root);
    return Solution::ans;
}

void Solution::tra(TreeNode* root) {
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
        Solution::ans.push_back(tempParent->val);
        if(tempParent->right) tra(tempParent->right);
        parentSt.pop();
    }
    
}

bool Solution::isValidBST(TreeNode* root) {
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

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
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

int Solution::minPathSum(vector<vector<int>>& grid) {
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

int Solution::robII(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    vector<int> l1(nums.begin() + 1, nums.end());
    vector<int> l2(nums.begin(), nums.end() - 1);
    return max(rob(l1), rob(l2));
    
}

int Solution::rob(vector<int>& nums) {
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

int Solution::numSquares(int n){
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

int Solution::nthUglyNumber(int n) {
    
    return 0;
}

vector<vector<int>> Solution::generate(int numRows) {
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

vector<vector<int>> Solution::generate2(int numRows) {
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

bool Solution::isAnagram(string s, string t) {
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

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) {
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

int Solution::removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int count = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1]) continue;
        nums[count++] = nums[i];
    }
    return count;
    
}

ListNode* Solution::deleteDuplicates(ListNode* head) {
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

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l2 == NULL) return l1;
    if(l1 == NULL) return l2;
    ListNode* root = l1;
    ListNode* l1Last;
    int carry = 0;
    while((l1 != NULL)&&(l2 != NULL)) {
        l1->val += (l2->val + carry);
        carry = l1->val / 10;
        l1->val %= 10;
        l1Last = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if((l1 == NULL)&&(l2 != NULL)) {
        l1Last->next = l2;
        ListNode* l2Last;
        while(l2) {
            l2->val += carry;
            carry = l2->val / 10;
            l2->val %= 10;
            l2Last = l2;
            l2 = l2->next;
        }
        if(carry) l2Last->next = new ListNode(carry);
    } else if((l1 != NULL)&&(l2 == NULL)) {
        while(l1) {
            l1->val += carry;
            carry = l1->val / 10;
            l1->val %= 10;
            l1Last = l1;
            l1 = l1 ->next;
        }
        if(carry) l1Last->next = new ListNode(carry);
    } else if((l1 == NULL)&&(l2 == NULL)) if(carry) l1Last->next = new ListNode(carry);
    return root;
}

bool Solution::isPalindrome(string s) {
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

bool Solution::isPalindrome(ListNode* head) {
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

ListNode* Solution::reverse(ListNode* oldhead) {
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
int Solution::maxArea(vector<int>& height) {
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

int Solution::minSubArrayLen(int s, vector<int>& nums) {
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
void Solution::push(int x) {
    myQueue.push(x);
}

// Removes the element from in front of queue.
void Solution::pop(void) {
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
int Solution::peek(void) {
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
bool Solution::empty(void) {
    return myQueue.empty();
}

bool Solution::isValid(string s) {
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

int Solution::calculate(string s) {
    if(!s.length()) return 0;
    vector<int> ans;
    ans = cal(s,0);
    return ans[0];
}

vector<int> Solution::cal(string str, int stpos) {
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

int Solution::strStr(string haystack, string needle) {
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

vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
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

bool Solution::isPowerOfTwo(int n) {
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
int Solution::myAtoi(string str) {
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

string Solution::convert(string s, int numRows) {
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

string Solution::convertToTitle(int n) {
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

void Solution::printAZ09() {
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

double Solution::AddFun(char* in, int NumLen, double PreRst){
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

double Solution::Cal(char* in){
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

enum choice {
    A,B,C
};

#endif /* Solution_hpp */
