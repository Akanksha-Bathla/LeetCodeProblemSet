class Solution {
private:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        //explore all paths
        dp[i][j1][j2] = INT_MIN;
        for(int dj1=-1; dj1<2; dj1++){
            for(int dj2=-1; dj2<2; dj2++){
                if(j1==j2) dp[i][j1][j2] = max(dp[i][j1][j2], grid[i][j1] + f(i+1, j1+dj1, j2+dj2, grid, m, n, dp));
                else dp[i][j1][j2] = max(dp[i][j1][j2], grid[i][j1] + grid[i][j2] + f(i+1, j1+dj1, j2+dj2, grid, m, n, dp));
            }
        }

        return dp[i][j1][j2];

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prev (m, vector<int>(m, 0));

        for(int j1=0; j1<m; j1++){
            for(int j2=0; j2<m; j2++){
                if(j1==j2) prev[j1][j2] = grid[n-1][j1];
                else prev[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2; i>=0; i--){
            vector<vector<int>>curr (m, vector<int>(m, 0));
            for(int j1=0; j1<m; j1++){
                for(int j2=0; j2<m; j2++){
                    curr[j1][j2] = INT_MIN;
                    for(int dj1=-1; dj1<2; dj1++){
                        for(int dj2=-1; dj2<2; dj2++){
                            int value = -1e9;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            if(j1+dj1 >=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m) value += prev[j1+dj1][j2+dj2];
                            curr[j1][j2] = max(curr[j1][j2], value);
                        }
                    }
                }
            }
            prev = curr;
        }

        return prev[0][m-1];
        // return f(0, 0, m-1, grid, m, n, dp);
    }
};