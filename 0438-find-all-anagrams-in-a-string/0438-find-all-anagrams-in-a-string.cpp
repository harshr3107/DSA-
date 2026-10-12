class Solution {
public:
     

     bool issame(map<char,int>& mp1,map<char,int>& mp2)
     {

        for(auto it: mp1)
        {
            if(mp2[it.first]<it.second)
            {
                return false;
            }

        }

        return true;

     }




    vector<int> findAnagrams(string s, string p) {

        int left=0;
        int right=0;

        map<char,int> mp1;

        //i would like to first store all the possible words which are part of the string
        for(auto it: p)
        {
            mp1[it]++;

        }

        map<char,int> mp2;

        vector<int> v;

        //
        while(right<s.length())
        {
            mp2[s.at(right)]++;

            while(issame(mp1,mp2))
            {

                if(mp1.size()==mp2.size())
                {
                    int a=0;

                    for(auto it: mp1)
                    {
                        if(mp2[it.first]!=it.second)
                        {
                                a++;
                                break;
                        }

                    }

                    if(a==0)
                    {
                        v.push_back(left);
                    }

                }

                mp2[s.at(left)]--;
                if(mp2[s.at(left)]==0)
                {
                    mp2.erase(s.at(left));
                }
                left++;
            

            }


            right++;   

        }

        return v;
        
    }
};