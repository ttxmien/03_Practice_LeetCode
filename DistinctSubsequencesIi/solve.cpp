class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;
        long long result = 0;
        vector<long long> dp(26, 0);
        
        for (char c : s) {
            int idx = c - 'a';
            long long total = 1;
            for (int i = 0; i < 26; ++i) {
                total = (total + dp[i]) % MOD;
            }
            dp[idx] = total;
        }

        for (int i = 0; i < 26; ++i) {
            result = (result + dp[i]) % MOD;
        }
        
        return result;
    }
};