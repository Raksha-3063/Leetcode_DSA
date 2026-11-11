class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char, int> mp;
        unordered_map<char, int> windowMap;
        vector<int> store;

        if(p.size() > s.size()) {
            return store;
        }

        for(int i = 0; i < p.size(); i++) {
            mp[p[i]]++;
        }

        for(int i = 0; i < p.size(); i++) {
            windowMap[s[i]]++;
        }

        if(mp == windowMap) {
            store.push_back(0);
        }

    
        int i = 0;

        for(int j = p.size(); j < s.size(); j++) {
            windowMap[s[i]]--;

            if(windowMap[s[i]] == 0) {
                windowMap.erase(s[i]);
            }
            windowMap[s[j]]++;

            i++;

            if(mp == windowMap) {
                store.push_back(i);
            }
        }

        return store;
    }
};