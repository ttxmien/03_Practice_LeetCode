class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<char> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        
        int limit = sqrt(n);
        for (int p = 2; p <= limit; p++) {
            if (isPrime[p]) {
                for (int i = p*p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) count++;
        }
        
        return count;
    }
};