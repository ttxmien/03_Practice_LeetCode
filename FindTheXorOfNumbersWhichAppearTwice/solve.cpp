class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        bool seen[51] = {false};
        int result = 0;

        for (int n : nums) {
            if (seen[n]) result ^= n;
            else seen[n] = true;
        }

        return result;
    }
};