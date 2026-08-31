class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int n : nums) xorr ^= n;

        int shift = 0;
        while (((xorr >> shift) & 1) == 0) shift++;

        int first = 0;
        for (int n : nums) {
            if ((n >> shift) & 1) {
                first ^= n;
            }
        }
        int second = first ^ xorr;

        return {first, second};
    }
};