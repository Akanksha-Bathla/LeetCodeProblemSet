class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        int cnt = 0;
        for(int i=2; i<n; i++){
            if(sieve[i] == true){
                cnt++;
                for(int j=i; j<n; j+=i){
                    sieve[j] = false;
                }
            }
        }
        return cnt;
    }
};