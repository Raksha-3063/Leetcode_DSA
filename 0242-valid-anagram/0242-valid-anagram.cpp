class Solution {
public:
    bool isAnagram(string s, string t) {
    //     int n = s.size();
    //     if(s.length() != t.length()) return false;
    //     unordered_map<char,int> map1;

    // for(int i =0;i<n;i++){
    //     map1[s[i]]++;
    //      }
    // for(int i =0;i<n;i++){
    //     map1[t[i]]--;
    // }         
    // for(auto it:map1){
    //     if(it.second != 0) return false;
    // }
    // return true;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s==t) return true;
    else return false;
    }
};