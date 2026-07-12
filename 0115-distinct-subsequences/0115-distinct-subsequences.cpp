class Solution {
private:
    int f(int i, int j, string& s, string& t){
        if(j==0) return 1;
        if(i==0) return 0;

        if(s[i-1] == t[j-1]) return f(i-1, j-1, s, t) + f(i-1, j, s, t);
        else return f(i-1, j, s, t);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);
        // for(int i=0; i<=n; i++) dp[i][0] = 1;
        prev[0] = 1;
        // for(int j=1; j<=m; j++) dp[0][j] = 0;

        for(int i=1; i<=n; i++){
            // curr[0] = 1;
            prev[0] = 1;
            for(int j=m; j>=1; j--){
                if(s[i-1] == t[j-1]) prev[j] = (prev[j-1] >= INT_MAX - prev[j])? INT_MAX : prev[j-1] + prev[j];
                // else curr[j] = prev[j];
            }
        }

        return prev[m];
    }
};