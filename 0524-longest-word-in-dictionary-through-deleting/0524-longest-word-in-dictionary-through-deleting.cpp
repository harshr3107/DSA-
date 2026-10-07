class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        sort(dictionary.begin(), dictionary.end());

        for (const string& word : dictionary) {
            int i = 0;
            int j = 0;

            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    j++;
                }
                i++;
            }

            if (j == word.length() && word.length() > ans.length()) {
                ans = word;
            }
        }

        return ans;
    }
};