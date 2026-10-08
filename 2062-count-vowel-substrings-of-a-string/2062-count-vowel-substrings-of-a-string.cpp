class Solution {
public:
    
    bool hasallvowel(map<char,int>& mp)
    {
        if(mp.find('a')!=mp.end() && mp.find('e')!=mp.end() && mp.find('i')!=mp.end() && mp.find('o')!=mp.end() && mp.find('u')!=mp.end())
        {
            return true;
        }

        return false;

    }


    bool isvowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
        {
            return true;
        }

        return false;

    }

    int countVowelSubstrings(string s) {


        int i=0;
        int j=0;

        map<char,int> mp;
        int ans=0;

        while(j<s.length())
        {
            if(isvowel(s.at(j))==false)
            {
                j++;
                i=j;
                mp.clear();
                continue;
            }

            mp[s.at(j)]++;


            while(hasallvowel(mp))
            {
                int k=j+1;

                while(k<s.length() && isvowel(s.at(k)))
                {
                    k++;
                }

                ans+=(k-j);
                cout<<"the string which we have now complete "<<i<<" "<<k<<endl;
                //cout<<"curretn value of ans is "<<ans<<endl;

                mp[s.at(i)]--;
                if(mp[s.at(i)]==0)
                {
                    mp.erase(s.at(i));
                }
                i++;
                //continue;
                



            }


            j++;








        }


        return ans;
        
    }
};