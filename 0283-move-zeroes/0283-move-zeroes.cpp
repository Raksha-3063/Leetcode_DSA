class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int i=0,j=1;
    int n = nums.size();

    while(i < n && j < n){
        if(nums[i] == 0){
            swap(nums[i],nums[j]);
        }
        if(nums[i] != 0){
            i++;
        }
        j++;
    }
     }
     
};