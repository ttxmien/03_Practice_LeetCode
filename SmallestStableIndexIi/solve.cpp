// Your code here
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // Refer to https://leetcode.com/problems/smallest-stable-index-i/
        int n = nums.size();

        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        vector<int> rightMin(n);
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (leftMax[i] - rightMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};