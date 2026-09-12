class Solution {
private:
    void f(int i, vector<int>& arr, int target, vector<int>& sum, vector<vector<int>>& result){
        if(target == 0){
            result.push_back(sum);
            return;
        }
        if(target < 0 || i == arr.size()) return;

        f(i+1, arr, target, sum, result);
        sum.push_back(arr[i]);
        f(i, arr, target-arr[i], sum, result);
        sum.pop_back();
        target+=arr[i];

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        vector<int> sum;
        f(0, candidates, target, sum, result);
        return result;
    }
};