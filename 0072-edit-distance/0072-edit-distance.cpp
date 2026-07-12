class Solution {
// private:
//     int f(int i, int j, string& s1, string& s2){
//         if(i<0) return j+1;
//         if(j<0) return i+1;

//         if(s1[i] == s2[j]) return f(i-1, j-1, s1, s2);
//         else return 1 + min(f(i,j-1, s1, s2), min(f(i-1, j-1, s1, s2), f(i-1, j, s1, s2)));
//     }
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=1; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }

        return dp[n][m];
    }
};