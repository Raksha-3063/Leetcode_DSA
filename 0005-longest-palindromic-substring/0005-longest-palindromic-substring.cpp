
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1)
            return s;

        string LPS = "";

        for (int i = 0; i < s.length(); i++) {

            // Consider odd length palindrome
            int low = i;
            int high = i;

            while (low >= 0 && high < s.length() &&
                   s[low] == s[high]) {
                low--;
                high++;
            }

            string palindrome = s.substr(low + 1, high - low - 1);

            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }

            // Consider even length palindrome
            low = i - 1;
            high = i;

            while (low >= 0 && high < s.length() &&
                   s[low] == s[high]) {
                low--;
                high++;
            }

            palindrome = s.substr(low + 1, high - low - 1);

            if (palindrome.length() > LPS.length()) {
                LPS = palindrome;
            }
        }

        return LPS;
    }
};
