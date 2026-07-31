class Solution {
public:
    int goodSubarray(vector<int>& nums,int k){
        int n= nums.size(),l=0,r=0,len=0;
        unordered_map<int,int>mp;

        while(r<n){
            mp[nums[r]]++;

           while(mp.size()>k){
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
           } 

           r++;
           len += r-l+1;
        }
        return len;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return goodSubarray(nums,k)-goodSubarray(nums,k-1); 
    }
};