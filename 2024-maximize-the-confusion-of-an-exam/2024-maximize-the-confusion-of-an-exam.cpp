class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {

        int i=0;
        int j=0;
        int maxi=0;

        map<char,int> mp;

        while(j<s.length())
        {

            mp[s.at(j)]++;

            while(mp['T']>k && mp['F']>k)
            {
                mp[s.at(i)]--;
                i++;

            }

            maxi=max(maxi,j-i+1);
            j++;
            
        }

        return maxi;


        
    }
};