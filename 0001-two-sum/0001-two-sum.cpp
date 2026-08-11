class Solution {
public: 
 vector<int> twoSum(vector<int>& num, int target) {
   int n = num.size();

   vector<pair<int,int>> temp;
   for(int i=0;i<n;i++){
    temp.push_back({num[i],i});
   }

   sort(temp.begin(),temp.end());
   int low=0;
   int high=n-1;
   int sum =0;

   while(low<high){
     sum = temp[low].first+temp[high].first;

     if(sum==target) return {temp[low].second,temp[high].second};
     else if(sum>target) high--;
     else low++;
   }
   return {};

}
 
};