class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == s[n-j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // int ind = dp[n][n] - 1;

        // int i=n, j=n;
        // string ans = "";
        // for(int i=0; i<=ind; i++) ans += '$';

        // while(i>0 && j>0){
        //     if(s[i-1] == s[n-j]){
        //         ans[ind] = s[i-1];
        //         i--;
        //         j--;
        //         ind--;
        //     }else if(dp[i-1][j] > dp[i][j-1]) i--;
        //     else j--;
        // }
        // cout << ans << endl;

        return n - dp[n][n];
    }
};