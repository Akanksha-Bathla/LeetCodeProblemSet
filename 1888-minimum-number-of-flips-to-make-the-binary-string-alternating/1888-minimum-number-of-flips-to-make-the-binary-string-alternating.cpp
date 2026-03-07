class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        s = s+s;
        string s1 = ""; //"010101"
        string s2 = ""; //"1010101"
        for(int i=0; i<2*n; i++){
            if(i%2==0){
                s1.push_back('0');
                s2.push_back('1');
            }else{
                s2.push_back('0');
                s1.push_back('1');
            }
        }

        //sliding window 
        int flip1 = 0;
        int flip2 = 0;
        int minFlips = INT_MAX;

        int i=0, j=0;
        while(j < 2*n){
            if(s[j] != s1[j]) flip1++;
            if(s[j] != s2[j]) flip2++;

            if(j-i+1 > n){ //shrink the window from left 
                if(s[i] != s1[i]) flip1--;
                if(s[i] != s2[i]) flip2--;

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