class Solution {
public:
    int binaryGap(int n) {
        int right = -1, left = -1, pos = 0;
        int maxDist = 0, dist=0;
        while(n>0){
            if(n&1){
                if(right == -1){
                    right = pos;
                } 
                else if(left == -1){
                    left = pos;
                    dist = left - right;
                } 
                else{
                    right = left;
                    left = pos;
                    dist = left - right;
                }
            }
            maxDist = max(dist, maxDist);
            pos++;
            n>>=1;
        }
        return maxDist;
    }
};