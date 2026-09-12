class Solution {
private:
    void f(int i, vector<int>& arr, int target, vector<int>& ds,vector<vector<int>>& result){
        if(target == 0){
            result.push_back(ds);
            return;
        }
        if(target < 0 || i==arr.size()) return;

        for(int j=i; j<arr.size(); j++){
            if(j>i && arr[j] == arr[j-1]) continue;

            ds.push_back(arr[j]);
            f(j+1, arr, target-arr[j], ds, result);
            ds.pop_back();
            target+arr[j];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        f(0, candidates, target, ds, result);
        return result;
    }
};