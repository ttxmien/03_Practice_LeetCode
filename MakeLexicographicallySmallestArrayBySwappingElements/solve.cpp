class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        vector<int> grID(n);
        vector<int> pos;
        int cur = 0;
        pos.push_back(0);

        for (int i = 0; i < n; ++i) {
            if (i > 0 && arr[i].first - arr[i - 1].first > limit) {
                cur++;
                pos.push_back(i);
            }
            grID[arr[i].second] = cur;
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            int g = grID[i]; 
            int idx = pos[g]++;
            res[i] = arr[idx].first;
        }

        return res;
    }
};