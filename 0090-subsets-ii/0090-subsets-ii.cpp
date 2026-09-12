class Solution {
private:
    void f(int i, vector<int>& arr, vector<int>& nums, set<vector<int>>& result){
        if(i == nums.size()){
            result.insert(arr);
            return;
        }

        f(i+1, arr, nums, result); //notTake

        arr.push_back(nums[i]);
        f(i+1, arr, nums, result); // take
        arr.pop_back();

        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        set<vector<int>> result;
        vector<int> arr;

        sort(nums.begin(), nums.end());

        f(0, arr, nums, result);
        ans.assign(result.begin(), result.end());
        return ans;
    }
};