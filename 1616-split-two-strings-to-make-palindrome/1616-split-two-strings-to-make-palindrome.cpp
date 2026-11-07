class Solution {
public:
    bool checkpalindrome(const string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    bool check(string& a, string& b)
    {
        int i = 0;
        int j = a.length() - 1;

        // Match the outer characters using a's prefix and b's suffix.
        while (i < j && a[i] == b[j])
        {
            i++;
            j--;
        }

        // The unmatched middle must be a palindrome in either string.
        return checkpalindrome(a, i, j) ||
               checkpalindrome(b, i, j);
    }

    bool checkPalindromeFormation(string a, string b)
    {
        return check(a, b) || check(b, a);
    }
};