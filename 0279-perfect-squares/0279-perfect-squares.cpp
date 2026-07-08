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

        // vector<vector<int>> dp(sz, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0);
        for(int sum=0; sum<=n; sum++) prev[sum] = sum;

        for(int ind=1; ind<sz; ind++){
            for(int sum=0; sum<=n; sum++){
                int notTake = prev[sum];
                int take = 1e9;
                if(arr[ind] <= sum) take = 1 + prev[sum-arr[ind]];

                prev[sum] = min(take, notTake);
            }
        }

        return prev[n];

    }
};