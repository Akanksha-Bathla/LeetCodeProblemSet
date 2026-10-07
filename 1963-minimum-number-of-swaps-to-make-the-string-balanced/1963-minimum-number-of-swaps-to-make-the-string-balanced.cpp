class Solution {
public:
    int minSwaps(string s) {
        int maxImbal = 0;
        int bal = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '['){
                bal++;
            }else{
                bal--;
            }

            maxImbal = max(maxImbal, -bal);
        }
        return (maxImbal+1)/2;
    }
};