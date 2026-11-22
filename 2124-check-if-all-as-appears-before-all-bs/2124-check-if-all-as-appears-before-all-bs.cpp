class Solution {
public:
    bool checkString(string s) 
    {

        int i=0;
        while(i<s.length() && s.at(i)=='a')
        {
            i++;
        }

        while(i<s.length() && s.at(i)=='b')
        {
            i++;
        }

        return i==s.length();

        
    }
};