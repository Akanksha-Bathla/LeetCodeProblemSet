class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i = 0;
        int j = 0;
        vector<int> num;
        while(i<n && j<m){
            if(num1[j] <= num2[i]){
                num.push_back(num1[j]);
                j++;
            }else{
                num.push_back(num2[i]);
                i++;
            }
        }

        while(j<m){
            num.push_back(num1[j]);
            j++;
        }

        while(i<n){
            num.push_back(num2[i]);
            i++;
        }

        num1 = num;
    }
};