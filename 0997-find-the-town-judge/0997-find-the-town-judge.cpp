class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<pair<int, int>> adj(n+1, {0, 0}); //indegree, outdegree

        for(auto it: trust){
            int u = it[0];
            int v = it[1];
            
            adj[u].second++;
            adj[v].first++;
        }
        int ind = -1;
        for(int i=1; i<=n; i++){
            if(adj[i].first == n-1 && adj[i].second == 0){
                ind = i;
                break;
            }
        }

        return ind;

    }
};