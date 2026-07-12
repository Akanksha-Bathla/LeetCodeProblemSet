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

        // vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), curr(m+1, 0);
        // for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=1; j<=m; j++) prev[j] = j;

        for(int i=1; i<=n; i++){
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(prev[j-1], min(curr[j-1], prev[j]));
            }
            prev = curr;
        }

        return prev[m];
    }
};