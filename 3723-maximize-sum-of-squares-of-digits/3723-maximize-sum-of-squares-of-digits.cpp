class Solution {
public:
    string maxSumOfSquares(int num, int sum)
    {
        if (num <= 0 || sum < 1 || 1LL * sum > 9LL * num)
        {
            return "";
        }

        string ans;
        ans.reserve(num);

        for (int i = 0; i < num; i++)
        {
            int digit = min(9, sum);

            if (i == 0 && digit == 0)
            {
                return "";
            }

            ans += char('0' + digit);
            sum -= digit;
        }

        return ans;
    }
};