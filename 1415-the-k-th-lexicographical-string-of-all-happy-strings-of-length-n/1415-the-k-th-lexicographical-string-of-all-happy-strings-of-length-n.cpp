class Solution {
public:
    string getHappyString(int n, int k) {
        int happy_strings = (1<<(n-1)) * 3;
        if(k > happy_strings){
            return "";
        }
        k--;

        vector<char> ch = {'a', 'b', 'c'};
        string ans = "";
        for(int i=0; i<n; i++){
            int block = 1 << max(0, n-i-1);

            for(char c : ch){
                if(!ans.empty() && ans.back() == c) continue;

                if(k >= block) k-=block;
                else{
                    ans.push_back(c);
                    break;
                }
            }
        }
        return ans;
    }
};