class Solution {
private:
    bool possible(vector<int>& piles, int h, int k){
        int n = piles.size();

        long hrs = 0;
        for(int i=0; i<n; i++){
            if(piles[i]%k == 0) hrs += piles[i]/k;
            else hrs += piles[i]/k + 1;
        }
        cout << "k: " << k<<endl;
        if(hrs <= h) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(piles, h, mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};