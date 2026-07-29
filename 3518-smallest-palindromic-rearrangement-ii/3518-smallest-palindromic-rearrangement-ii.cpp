class Solution {
public:

    long long nCr(int n, int r, long long limit) {
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;

         
            if (ans >= limit)
                return limit;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        int n = s.size();

        vector<int> freq(26, 0);

        char middle = '\0';

        
        for (char ch : s)
            freq[ch - 'a']++;

      
        if (n % 2 == 1) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] % 2 == 1) {
                    middle = char(i + 'a');
                    break;
                }
            }
        }

      
        for (int i = 0; i < 26; i++)
            freq[i] /= 2;

        string firstHalf = "";

        int halfLength = n / 2;

       
        for (int pos = 0; pos < halfLength; pos++) {

            bool found = false;

            for (int ch = 0; ch < 26; ch++) {

                if (freq[ch] == 0)
                    continue;

              
                freq[ch]--;

                int remaining = 0;

                for (int x : freq)
                    remaining += x;

                long long ways = 1;

                int left = remaining;

               
                for (int i = 0; i < 26; i++) {

                    if (freq[i] == 0)
                        continue;

                    ways *= nCr(left, freq[i], k);

                    if (ways >= k) {
                        ways = k;
                        break;
                    }

                    left -= freq[i];
                }

              
                if (ways >= k) {
                    firstHalf.push_back(char(ch + 'a'));
                    found = true;
                    break;
                }

                
                k -= ways;
                freq[ch]++;
            }

            if (!found)
                return "";
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (n % 2 == 1)
            return firstHalf + middle + secondHalf;

        return firstHalf + secondHalf;
    }
};