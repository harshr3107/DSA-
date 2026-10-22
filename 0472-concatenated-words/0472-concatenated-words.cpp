#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
public:
    node* links[26] = {};
    bool flag;

    node()
    {
        flag = false;
    }

    bool checkif(char h)
    {
        return links[h - 'a'] != nullptr;
    }

    void addletter(node* h, char a)
    {
        links[a - 'a'] = h;
    }

    void isend()
    {
        flag = true;
    }

    bool checkend()
    {
        return flag;
    }
};

class trie
{
public:
    node* root;

    trie()
    {
        root = new node();
    }

    void addword(string h)
    {
        node* temp = root;

        for (int i = 0; i < h.length(); i++)
        {
            if (temp->checkif(h.at(i)) == false)
            {
                node* l = new node();
                temp->addletter(l, h.at(i));
            }

            temp = temp->links[h.at(i) - 'a'];
        }

        temp->flag = true;
    }

    bool checkifcon(string& s, int i, int count,
                    vector<vector<int>>& dp)
    {
        if (i == s.length())
        {
            return count > 1;
        }

        count = min(count, 2);

        if (dp[i][count] != -1)
        {
            return dp[i][count];
        }

        node* temp = root;

        for (int j = i; j < s.length(); j++)
        {
            if (temp->checkif(s.at(j)) == false)
            {
                break;
            }

            temp = temp->links[s.at(j) - 'a'];

            if (temp->checkend())
            {
                if (checkifcon(s, j + 1, min(count + 1, 2), dp))
                {
                    return dp[i][count] = true;
                }
            }
        }

        return dp[i][count] = false;
    }
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
    {
        trie* t = new trie();

        for (auto& it : words)
        {
            t->addword(it);
        }

        vector<string> ans;

        for (auto& it : words)
        {
            vector<vector<int>> dp(it.length() + 1, vector<int>(3, -1));

            if (t->checkifcon(it, 0, 0, dp))
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};