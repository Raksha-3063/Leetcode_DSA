class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int i = 0;
        int high = nums.size() - 1;

        while(i <= high) {

            if(nums[i] == 0) {
                swap(nums[low], nums[i]);
                low++;
                i++;
            }

            else if(nums[i] == 1) {
                i++;
            }

            else {
                swap(nums[i], nums[high]);
                high--;
            }
        }
}
         
};