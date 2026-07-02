class Solution {
// private:
//     int f(int i, int j, vector<vector<int>>& arr){
//         if((i>0 || j>0) && arr[i][j] == 1) return 0;
//         if(i==0 && j==0) return 1;
//         if(i<0 || j<0) return 0;

//         int up = 0, left = 0;
//         if(i>0) up = f(i-1, j, arr);
//         if(j>0) left = f(i, j-1, arr);

//         return up + left;
//     }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0 && obstacleGrid[i][j] != 1) dp[i][j] = 1;
                else{
                    int up=0, left=0;
                    if((i>0 || j>0) && obstacleGrid[i][j] == 1) continue;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                    cout << dp[i][j] << " "<< i<< " "<< j<< endl; 
                } 
            }
        }
        return dp[n-1][m-1];
    }
};