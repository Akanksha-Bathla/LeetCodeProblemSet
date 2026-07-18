class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx+1, 0);
        //freq array;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }


        //counting no of elements divisible by i ;
        vector<long long> exact(mx+1, 0);
        exact[0] = 0;
        for(int i=1; i<=mx; i++){
            for(int j=i; j<=mx; j+=i){
                exact[i] += freq[j];
            }
        }

        // counting the pairs and finding exact no. of elemnt divisible by d;
        // vector<long long> exact(mx+1, 0);
        for(int d=mx; d>=1; d--){
            exact[d] = 1LL * exact[d] * (exact[d] - 1) / 2;
            for(int multiple = 2*d; multiple <= mx; multiple += d){
                exact[d] -= exact[multiple];
            }
        }


        vector<long long> pref(mx+1, 0);
        pref[0] = 0;
        for(int i=1; i<=mx; i++){
            pref[i] = exact[i];
        }

        for(int i=1; i<=mx; i++){
            pref[i] += pref[i-1];
        }


        int sz = queries.size();
        vector<int> answer(sz, 0);
        for(int i=0; i<sz; i++){
            int s=0, e=pref.size()-1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(pref[mid] >= queries[i]+1){
                    e = mid-1;
                    answer[i] = mid;
                }else{
                    s = mid+1;
                }
            }
        }
        return answer;
    }
};