class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int l_sum =0,r_sum=0,max_sum=0;
      int n = cardPoints.size();

      for(int i=0;i<k;i++){
        l_sum += cardPoints[i];
      }
      max_sum = l_sum;
      int last_index = n-1;

      for(int i=k-1;i>=0;i--){
        l_sum = l_sum-cardPoints[i];
        r_sum = r_sum+cardPoints[last_index];
        last_index--;
        max_sum = max(max_sum,l_sum+r_sum);
      }
      return max_sum;
    }
     
};