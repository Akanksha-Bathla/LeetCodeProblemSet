class Solution {
// private:
//     bool f(int i, int j, string& s, string& t){
//         if(i==0 && j==0) return true;
//         if(i==0 && j>0) return false;
//         if(j==0 && i>0){
//             for(int ii=1; ii<=i; ii++){
//                 if(s[ii-1] != '*') return false;
//             }
//             return true;
//         }

//         if(s[i-1] == t[j-1] || s[i-1] == '?') return f(i-1, j-1, s, t);
//         else if(s[i-1] == '*') {
//             return f(i-1, j, s, t) | f(i, j-1, s, t);
//         }; 
//         return false;
//     }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for(int j=1; j<=n; j++) dp[0][j] = false;
        for(int i=1; i<=m; i++){
            int flag = true;
            for(int ii=1; ii<=i; ii++){
                if(p[ii-1] != '*'){
                    flag = false;
                    break;
                } 
            }
            dp[i][0] = flag;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] | dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};