class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cSet;
        int l=0,n=s.length(),max_len = 0;

        for(int r=0;r<n;r++){
            while(cSet.count(s[r])){
                cSet.erase(s[l]);
                l++;
            }
            cSet.insert(s[r]);
            max_len = max(max_len , r-l+1);
        }
      return max_len;
    }
};