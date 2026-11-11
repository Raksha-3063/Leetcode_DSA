class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp_s1;
        unordered_map<char,int>mp_s2;

        if(s1.size() > s2.size()) return false;

        for(int i=0;i<s1.size();i++){
            mp_s1[s1[i]]++;
        }
        for(int i=0;i<s1.size();i++){
           mp_s2[s2[i]]++;
        }

        if(mp_s1 == mp_s2) return true;

        int i = 0;
       for(int j=s1.size();j<s2.size();j++){
            mp_s2[s2[i]]--;

            if(mp_s2[s2[i]]==0){
                mp_s2.erase(s2[i]);
            }
             mp_s2[s2[j]]++;
             i++;

              if(mp_s1 == mp_s2)  return true;
       }
       return false;
    }
};