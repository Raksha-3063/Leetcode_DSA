class Solution {
public:
    bool isPalindrome(string s) {
        string result;
        int j =  0;

    for(int i=0;i<s.size();i++){
        s[i] = tolower(s[i]);
     
     if(isalnum(s[i])){
        result +=s[i];
     }
    }

    while(j<result.size()/2){
        if(result[j] != result[result.size()-j-1]){
            return false;
        }
        j++;
    }
  return true;
    
}     

};