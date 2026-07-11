class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size();

        string s2 = s1;
        reverse(s1.begin(), s1.end());

        // vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        vector<int> prev(n+1, 0);
        for(int i=1; i<=n; i++){
            vector<int> curr(n+1, 0);
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        // cout << s1 << endl;
        // cout << s2 << endl;

        // int index = dp[n][n]-1;

        // string ans = "";
        // for(int i=0; i<=index; i++) ans += '$';

        // int i=n, j=n;
        // while(i>0 && j>0){
        //     if(s1[i-1] == s2[j-1]){
        //         ans[index] = s1[i-1];
        //         index--;
        //         j--;
        //         i--;
        //     }else if(dp[i-1][j] > dp[i][j-1]) i--;
        //     else j--;
        // }
        // cout << ans << endl;


        return prev[n];
    }
};