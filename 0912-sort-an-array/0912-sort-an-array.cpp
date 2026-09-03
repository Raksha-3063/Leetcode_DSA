class Solution {
public:
    void mergeSort(vector<int>& nums,int low,int mid,int high ){
        int left = low;
        int right = mid+1;
        vector<int> temp;

        while(left<= mid && right <= high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }

        int x = 0;
        for(int i=low;i<=high;i++){
            nums[i] = temp[x++];
        }
            
    }
    void ms(vector<int>& nums,int low,int high){
        if(low>=high) return;
        int mid = (low+high)/2;

        ms(nums,low,mid);
        ms(nums,mid+1,high);
        mergeSort(nums,low,mid,high);

    }
    vector<int> sortArray(vector<int>& nums) {
        ms(nums,0,nums.size()-1);
        return nums;
    }
};