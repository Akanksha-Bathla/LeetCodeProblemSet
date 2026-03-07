class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        //sliding window 
        int flip1 = 0;
        int flip2 = 0;
        int minFlips = INT_MAX;

        int i=0, j=0;
        while(j < 2*n){
            char expectedS1 = (j%2)? '0' : '1';
            char expectedS2 = (j%2)? '1' : '0';


            if(s[j%n] != expectedS1) flip1++;
            if(s[j%n] != expectedS2) flip2++;

            if(j-i+1 > n){ //shrink the window from left 
                expectedS1 = (i%2)? '0' : '1';
                expectedS2 = (i%2)? '1' : '0';

                if(s[i%n] != expectedS1) flip1--;
                if(s[i%n] != expectedS2) flip2--;

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