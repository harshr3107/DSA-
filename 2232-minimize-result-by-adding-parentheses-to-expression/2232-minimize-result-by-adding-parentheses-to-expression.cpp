class Solution {
public:
    int getint(string s, int start, int end) {
        if (start > end) {
            return 1;
        }

        int h = 0;

        while (start <= end) {
            h = h * 10 + (s.at(start) - '0');
            start++;
        }

        return h;
    }

    int getans(string s, int start, int end, int exp) {
        int l = getint(s, start, exp - 1);
        int r = getint(s, exp + 1, end);

        return l + r;
    }

    string minimizeResult(string expression) {
        int lind = 0;
        int rind = 0;

        int cans = INT_MAX;

        int right = find(expression.begin(), expression.end(), '+')
                    - expression.begin();

        for (int i = 0; i < right; i++) {
            for (int j = right; j < expression.length() - 1; j++) {
                int lside = getint(expression, 0, i - 1);
                int midpart = getans(expression, i, j + 1, right);
                int rside = getint(expression, j + 2,
                                   expression.length() - 1);

                int cval = lside * midpart * rside;

                if (cans > cval) {
                    cans = cval;
                    lind = i;
                    rind = j + 1;
                }
            }
        }

        return expression.substr(0, lind) + "("
             + expression.substr(lind, rind - lind + 1) + ")"
             + expression.substr(rind + 1);
    }
};