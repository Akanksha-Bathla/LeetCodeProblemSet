class Solution {
private:
    void f(int i, vector<int>& arr, vector<int>& nums, vector<vector<int>>& result){
        result.push_back(arr);

        for(int j = i; j < nums.size(); j++){
            if(j>i && nums[j] == nums[j-1]) continue;

            arr.push_back(nums[j]);
            f(j+1, arr, nums, result); // take
            arr.pop_back();
        }
        // f(i+1, arr, nums, result); //notTake

        // arr.push_back(nums[i]);
        // f(i+1, arr, nums, result); // take
        // arr.pop_back();

        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        // set<vector<int>> result;
        vector<int> arr;

        sort(nums.begin(), nums.end());

        f(0, arr, nums, ans);
        // ans.assign(result.begin(), result.end());
        return ans;
    }
};