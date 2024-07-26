bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }
int myAtoi(string s) {

        int n = s.length();

        if (n == 0) {
            return 0;
        }

        int index = 0;

        // skipping white spaces
        while (index < n && s[index] == ' ') {
            index++;
        }

        // to handle sign cases
        bool isNegative = false;

        if (index < n) {

            if (s[index] == '-') {
                isNegative = true;
                index++;
            } else if (s[index] == '+') {
                index++;
            }
        }

        int result = 0;

        while (index < n && isDigit(s[index])) {

            int digit = s[index] - '0';
            // to avoid integer overflow
            if (result > (INT_MAX / 10) ||
                (result == (INT_MAX / 10) && digit > 7)) {
                return isNegative ? INT_MIN : INT_MAX;
            }

            result = (result * 10) + digit;

            ++index;
    }

    return isNegative ? -result : result;
}
