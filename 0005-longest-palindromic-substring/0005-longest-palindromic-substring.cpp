
class Solution {
public:
    string longestPalindrome(string s) {
       if(s.size()<=1) return s;
       string LPS = "";

       for(int i=0;i<s.size();i++){

           int low = i;
           int high = i;

           while(low >=0 && high < s.size() && s[low]==s[high]){
            low--;high++;
           }
           string palin = s.substr(low+1,high-low-1);

           if(palin.size() > LPS.size()){
            LPS = palin;
           }
 

           low = i-1;
            high = i;

           while(low >=0 && high < s.size() && s[low]==s[high]){
            low--;high++;
           }
           palin = s.substr(low+1,high-low-1);

           if(palin.size() > LPS.size()){
            LPS = palin;
           }

       }

       return LPS;
    }
};
