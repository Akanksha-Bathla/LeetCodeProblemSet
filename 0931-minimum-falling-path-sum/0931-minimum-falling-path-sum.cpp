class Solution {
// private:
//     int f(int i, int j, vector<vector<int>>& matrix, int m){
//         if(j<0 || j>=m) return 1e9;
//         if(i==0) return matrix[i][j];

//         int s = matrix[i][j] + f(i-1, j, matrix, m);
//         int ld = 1e9, rd = 1e9;
//         if(j>0) ld = matrix[i][j] + f(i-1, j-1, matrix, m);
//         if(j<m-1) rd = matrix[i][j] + f(i-1, j+1, matrix, m);

//         return min(s, min(ld, rd));
//     }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = 1e9;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int s = matrix[i][j] + dp[i-1][j];
                int ld = 1e9, rd = 1e9;
                if(j>0) ld = matrix[i][j] + dp[i-1][j-1];
                if(j<m-1) rd = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(s, min(ld, rd));
            }
        }

        for(int j=0; j<m; j++){
            mini = min(dp[n-1][j], mini);
        }

        return mini;
    }
};