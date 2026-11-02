class Solution {
private:
    static bool comp(string a, string b) {
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        int n = nums.size();
        vector<string> ls;
        for(int i: nums){
            string str = to_string(i);
            cout << str << endl;
            ls.push_back(str);
        }
        sort(ls.begin(), ls.end(), comp);
        
        for(string i: ls){
            ans += i;
        }
        if (ans[0] == '0') return "0";
        return ans;
    }
};