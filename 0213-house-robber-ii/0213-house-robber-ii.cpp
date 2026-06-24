class Solution {
private: 
    int solve(int s, int e, vector<int>& nums){
        int prev = 0, prev2 = nums[0];
        for(int i=s; i<=e; i++){
            int pick = nums[i];
            if(i > 1){
                pick = nums[i] + prev2;
            }
            int notPick = 0 + prev;

            int curr = max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(solve(0, n-2, nums), solve(1, n-1, nums));
        
    }
};