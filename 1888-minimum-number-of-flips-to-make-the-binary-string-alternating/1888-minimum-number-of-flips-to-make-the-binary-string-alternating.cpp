class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        string s1, s2; //"010101"   s2 //"1010101"
        for(int i=0; i<2*n; i++){
            s1 += (i%2) ? '0' : '1';
            s2 += (i%2) ? '1' : '0';
        }

        //sliding window 
        int flip1 = 0;
        int flip2 = 0;
        int minFlips = INT_MAX;

        int i=0, j=0;
        while(j < 2*n){
            if(s[j%n] != s1[j]) flip1++;
            if(s[j%n] != s2[j]) flip2++;

            if(j-i+1 > n){ //shrink the window from left 
                if(s[i%n] != s1[i]) flip1--;
                if(s[i%n] != s2[i]) flip2--;

                i++;
            }

            if(j-i+1 == n){
                minFlips = min({flip1, flip2, minFlips});
            }

            j++;
        }
        return minFlips;
    }
};