class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned long long> dp(t.size() + 1, 0);     // tránh overflow
        dp[0] = 1;
        
        for (int i = 1; i <= s.size(); i++) {
            for (int j = t.size(); j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return static_cast<int>(dp[t.size()]);
    }
};