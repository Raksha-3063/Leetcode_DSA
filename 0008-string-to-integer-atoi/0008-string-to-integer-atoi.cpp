class Solution {
public:
    int myAtoi(string s) {
    int n = s.size();
    int i=0;
    int sign = 1;
    long long num = 0;

    while(i<n && s[i]==' '){
        i++;
    }

    if(i<n && s[i]=='-'){
        sign = -1 ;i++;
    }else if(i<n && s[i]=='+'){
        i++;
    }

    while(i<n && isdigit(s[i])){
        int digit = s[i]-'0';
        num = num*10 + digit;

        if(sign*num <= INT_MIN) return INT_MIN;
        if(sign*num >= INT_MAX) return INT_MAX;
        i++;
    }
     return sign*num;

    }
};