class Solution {
private:
    bool isPrime(int n){
        if(n == 1) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }

public:
    int countPrimeSetBits(int left, int right) {

        int cntPrimes = 0;

        for(int i=left; i<=right; i++){

            int cntSetbits = __builtin_popcount(i);
            // int x = i;
            // while(x>0){
            //     if(x&1==1) cntSetbits++;
            //     x>>=1;
            // }
            if(isPrime(cntSetbits)) cntPrimes++;
        }

        return cntPrimes;
    }
};