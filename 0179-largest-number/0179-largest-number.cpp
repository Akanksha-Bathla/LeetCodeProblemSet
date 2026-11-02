class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        vector<string> ls;
        for(int i: nums){
            ls.push_back(to_string(i));
        }
        sort(ls.begin(), ls.end(), [](const string &a, const string &b){
            return a+b > b+a;
        });
        
        for(string i: ls){
            ans += i;
        }
        if (ans[0] == '0') return "0";
        return ans;
    }
};