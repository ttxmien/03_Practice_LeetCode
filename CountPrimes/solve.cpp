class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        int count = 0;
        
        for (int p = 2; p < n; p++) {
            if (isPrime[p]) {
                count++;
                long long i = (long long)p * p;
                while (i < n) {
                    isPrime[i] = false;
                    i += p;
                }
            }
        }
        
        return count;
    }
};