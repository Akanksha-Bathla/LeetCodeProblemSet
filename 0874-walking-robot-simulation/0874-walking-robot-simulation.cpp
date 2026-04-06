class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // north, east, south, west 
        vector<pair<int, int>> dxn = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<int, int> curPos = {0, 0};
        int res = 0;
        int curdir = 0;
        // 🔥 obstacle storage
        set <pair<int, int>> obstacleSet;

        for(auto &obs : obstacles){
            obstacleSet.insert({obs[0], obs[1]});
        }

        for(auto command : commands){
            if(command == -1){  //right
                curdir = (curdir + 1) % 4;
                continue;
            }

            if(command == -2){ //left
                curdir = curdir-1;
                if(curdir == -1) curdir = 3;
                continue;
            }

            for(int i=0; i<command; i++){
                int nextx = curPos.first + dxn[curdir].first;
                int nexty = curPos.second + dxn[curdir].second;

                if(obstacleSet.count({nextx, nexty})) break;

                curPos.first = nextx;
                curPos.second = nexty;

                
            }
            res = max(res, curPos.first*curPos.first + curPos.second*curPos.second);
        }

        return res;
    }
};