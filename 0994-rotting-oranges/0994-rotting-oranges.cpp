class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>>q;
        int freshcnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    freshcnt++;
                }
            }
        }

        int minutes = -1;
        int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto &d : dirs){
                    int dr = d[0];
                    int dc = d[1];
                    if((r+dr)>=0 && (r+dr)<m && (c+dc)>=0 && (c+dc)<n && grid[r+dr][c+dc] == 1){
                        q.push({r+dr, c+dc});
                        freshcnt--;
                        grid[r+dr][c+dc] = 2;
                    }
                }
            }
            minutes++;    
        }

        if(freshcnt>0) return -1;
        return minutes == -1 ? 0 : minutes;
    }
};