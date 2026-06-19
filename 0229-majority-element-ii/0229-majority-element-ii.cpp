class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0, cnt2=0;
        int el1, el2;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                el1 = nums[i];
                cnt1 = 1;
            }else if(cnt2 == 0 && nums[i] != el1){
                el2 = nums[i];
                cnt2 = 1;
            }else if(el1 == nums[i]){
                cnt1++;
            }else if(el2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        int mini = n/3 +1;
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
        }

        if(cnt1 >= mini) ans.push_back(el1);
        if(cnt2 >= mini && el1 != el2) ans.push_back(el2);

        return ans;
    }
};