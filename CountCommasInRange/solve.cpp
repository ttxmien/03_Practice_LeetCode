class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;
        
        int commas = 0;
        if (n <= 9999) commas = n - 1000 + 1;
        else {
            commas = 9000;
            commas += n - 10000 + 1;
        }
        
        return commas;
    }
};