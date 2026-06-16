class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int ind=-1;
        for(int i=n-2; i>=0; i--){
            if(arr[i+1] > arr[i]){
                ind = i;
                break;
            } 
        }
        if(ind == -1){
            reverse(arr.begin(), arr.end());
            return;
        }
        for(int j=n-1; j>ind; j--){
            if(arr[j] > arr[ind]) {
                swap(arr[j], arr[ind]);
                break;
            }
        } 
        reverse(arr.begin()+ind+1, arr.end());
    }
};