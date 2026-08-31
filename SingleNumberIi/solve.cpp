class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0;
        int twice = 0;

        for (int n : nums) {
            twice = twice | (once & n);
            once = once ^ n;

            int thrice = once & twice;
            once = once & ~thrice;
            twice = twice & ~thrice;
        }

        return once;
    }
};