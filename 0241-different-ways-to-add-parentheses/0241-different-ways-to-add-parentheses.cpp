class Solution {
public:
    vector<int> getans(string& expression, int start, int end) {
        vector<int> results;
        bool hasOperator = false;

        for (int j = start; j <= end; j++) {
            if (expression[j] == '+' || expression[j] == '-' || expression[j] == '*') {

                hasOperator = true;

                vector<int> left = getans(expression, start, j - 1);
                vector<int> right = getans(expression, j + 1, end);

                for (int it1 : left) {
                    for (int it2 : right) {
                        if (expression[j] == '*') {
                            results.push_back(it1 * it2);
                        } else if (expression[j] == '-') {
                            results.push_back(it1 - it2);
                        } else {
                            results.push_back(it1 + it2);
                        }
                    }
                }
            }
        }

        // This part contains only a number.
        if (!hasOperator) {
            int number = 0;
            for (int j = start; j <= end; j++) {
                number = number * 10 + (expression[j] - '0');
            }
            results.push_back(number);
        }

        return results;
    }

    vector<int> diffWaysToCompute(string expression) {
        return getans(expression, 0, expression.length() - 1);
    }
};