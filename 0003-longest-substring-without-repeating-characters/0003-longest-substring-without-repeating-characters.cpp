class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> c_set;
       int n = s.size();
       int l=0,max_len =0;

       for(int r=0;r<n;r++){
          while(c_set.count(s[r])){
            c_set.erase(s[l]);
            l++;
          }
            c_set.insert(s[r]);
            max_len = max(max_len,r-l+1);
          }
       
       return max_len;
    }
};