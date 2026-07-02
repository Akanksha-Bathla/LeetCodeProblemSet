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

        // vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> prev(m, 0);
        for(int i=0; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0 && obstacleGrid[i][j] != 1) curr[j] = 1;
                else{
                    int up=0, left=0;
                    if((i>0 || j>0) && obstacleGrid[i][j] == 1) continue;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left; 
                } 
            }
            prev = curr;
        }
        return prev[m-1];
    }
};