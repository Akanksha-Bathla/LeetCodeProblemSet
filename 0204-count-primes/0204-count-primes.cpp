class Solution {
public:
    int countPrimes(int n) {
        vector<bool> sieve(n, true);
        int cnt = 0;
        if(n==3) return 1;
        if(n==4) return 2;
        for(int i=2; i*i<=n; i++){
            if(sieve[i] == true){
                for(int j=i*2; j<n; j+=i){
                    sieve[j] = false;
                }
            }
        }

        for(int i=2; i<n; i++){
            if(sieve[i] == true) cnt++;
        }
        return cnt;
    }
};