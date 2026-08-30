class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);

        int opt1 = j + 1;               // Xóa hết từ bên trái
        int opt2 = n - i;               // Xóa hết từ bên phải
        int opt3 = (i + 1) + (n - j);   // Xóa từ cả 2 đầu

        return min({opt1, opt2, opt3});
    }
};