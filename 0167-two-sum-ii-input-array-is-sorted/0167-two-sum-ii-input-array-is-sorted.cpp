class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int n = numbers.size();

       vector<pair<int,int>>temp;
       for(int i=0;i<n;i++){
        temp.push_back({numbers[i],i});
       }

       int low =0,high=n-1;

       while(low<high){
        int sum = temp[low].first+temp[high].first;

        if(sum==target) return {temp[low].second+1,temp[high].second+1};
        else if(sum < target) low++;
        else high--;
       }
       return {};
    }
};
