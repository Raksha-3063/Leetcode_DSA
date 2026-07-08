class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<int> prefixSum;
    vector<int> prefixCount;
    vector<long long> prefixValue;
    vector<long long> power10;

    long long stringManip(int l, int r) {
        int sum = prefixSum[r + 1] - prefixSum[l];
        int cnt = prefixCount[r + 1] - prefixCount[l];

        if (cnt == 0)
            return 0;

        long long x =
            (prefixValue[r + 1] -
             (prefixValue[l] * power10[cnt]) % MOD +
             MOD) %
            MOD;

        return (x * sum) % MOD;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        prefixSum.assign(n + 1, 0);
        prefixCount.assign(n + 1, 0);
        prefixValue.assign(n + 1, 0);
        power10.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            power10[i] = (power10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {

            int digit = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i] + digit;
            prefixCount[i + 1] = prefixCount[i] + (digit != 0);

            if (digit != 0)
                prefixValue[i + 1] =
                    (prefixValue[i] * 10 + digit) % MOD;
            else
                prefixValue[i + 1] = prefixValue[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            ans.push_back(stringManip(q[0], q[1]));
        }

        return ans;
    }
};