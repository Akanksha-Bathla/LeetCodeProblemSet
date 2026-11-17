class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int h = letters.size()-1;

        if(letters[h] <= target) return letters[l];

        while(l<=h){
            int mid = (l+h)/2;

            if(letters[mid] <= target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return letters[l];
    }
};