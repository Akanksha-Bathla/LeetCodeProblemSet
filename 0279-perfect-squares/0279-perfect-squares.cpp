class Solution {
private: 
    int f(int ind, int sum, vector<int>& arr){
        if(ind == 0){
            return sum;
        }

        int notTake = f(ind-1, sum, arr);
        int take = 1e9;
        if(arr[ind] <= sum) take = 1 + f(ind, sum-arr[ind], arr);

        return min(take, notTake);
    }
public:
    int numSquares(int n) {
        vector<int> arr;

        for(int i=1; i*i<=n; i++){
            arr.push_back(i*i);
        }

        int sz = arr.size();

        vector<vector<int>> dp(sz, vector<int>(n+1, 0));
        for(int sum=0; sum<=n; sum++) dp[0][sum] = sum;

        for(int ind=1; ind<sz; ind++){
            for(int sum=0; sum<=n; sum++){
                int notTake = dp[ind-1][sum];
                int take = 1e9;
                if(arr[ind] <= sum) take = 1 + dp[ind][sum-arr[ind]];

                dp[ind][sum] = min(take, notTake);
            }
        }

        return dp[sz-1][n];

    }
};