class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long long result = 0;

        // Ignore leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        // Convert digits to integer
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            // Check for out-of-range
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return result * sign;
    }
};
