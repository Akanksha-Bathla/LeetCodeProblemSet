class Solution {
private:
    bool solve(int i, string s, vector<string>& wordDict, vector<int>& dp){
        if(i == s.size()) return dp[i] = true;
        if(dp[i] != -1) return dp[i];

        for(string it: wordDict){
            int n = it.size();
            if (s.substr(i, n) == it) {
                if (solve(i + n, s, wordDict, dp)) {
                    cout << s.substr(i, n) << endl;
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        bool ans = solve(0, s, wordDict, dp);
        return dp[0];
    }
};