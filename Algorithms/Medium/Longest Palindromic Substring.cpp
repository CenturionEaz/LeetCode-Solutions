class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string t = preprocess(s);
        int n = t.size();
        vector<int> P(n);

        int C = 0, R = 0;
        int maxLen = 0, start = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * C - i;

            if (i < R) P[i] = min(R - i, P[mirror]);

            while (t[i + (1 + P[i])] == t[i - (1 + P[i])]) P[i]++;

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }

            if (P[i] > maxLen) {
                maxLen = P[i];
                start = (i - maxLen) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

    string preprocess(const string& s) {
        string res = "^#";
        for (char c : s) {
            res += c;
            res += '#';
        }
        res += "$";
        return res;
    }
};
