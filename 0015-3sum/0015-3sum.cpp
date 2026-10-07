class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int j=1, k=n-1;
        int sum = 0;
        for(int i=0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            j = i+1;
            k = n-1;
            while(j<k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1])
                        j++;

                    while(j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};