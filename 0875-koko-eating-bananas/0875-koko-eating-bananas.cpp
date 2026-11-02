class Solution {
private:
    bool possible(vector<int>& piles, int h, int k){
        int n = piles.size();

        long hrs = 0;
        for(int i=0; i<n; i++){
            hrs += piles[i]/k + (piles[i]%k!=0);
        }
        
        return (hrs <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(piles, h, mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return low;
    }
};