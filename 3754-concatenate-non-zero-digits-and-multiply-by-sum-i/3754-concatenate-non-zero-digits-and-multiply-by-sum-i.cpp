class Solution {
public:
    long long sumAndMultiply(int n) {
    vector<int> nums;
    int sum =0;

    while(n>0){
        int digit = n%10;
        if(digit != 0){
            sum += digit;
            nums.push_back(digit);
        }
        n = n/10;
    }
    reverse(nums.begin(),nums.end());
    long long  x=0;

    for(int digit : nums){
        x = x*10+digit;
    }

      return sum*x;
    }
};