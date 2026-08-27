class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        for (int i = s.size() - 1; i >= 0; i--) {
            vector<int> curCount = count;
            
            int j = 0;
            while (j < i && --curCount[target[j] - 'a'] >= 0) {
                j++;
            }
            if (j < i) continue;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (curCount[c] > 0) {
                    string res = target.substr(0, i) + char('a' + c);
                    curCount[c]--;

                    for (int k = 0; k < 26; ++k) {
                        while (curCount[k]-- > 0) res += char('a' + k);
                    }
                    return res;
                }
            }
        }
        return "";
    }
};