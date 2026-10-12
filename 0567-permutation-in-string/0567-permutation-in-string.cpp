class Solution {
public:
    

     bool ismatch(map<char,int>& mp1,map<char,int>& mp2)
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


    bool checkInclusion(string s1, string s2) {

        int left=0;
        int right=0;

        map<char,int> mp1;
        map<char,int> mp2;

        for(auto it: s1)
        {
            mp1[it]++;
        }

        while(right<s2.length())
        {
            mp2[s2.at(right)]++;
            //cout<<"left = "<<left<<" right = "<<right<<endl;

            while(ismatch(mp1,mp2))
            {
                //cout<<"i enetered here for left right  = "<<left<<" "<<right<<endl;

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
                        return true;
                    }
                   
                }

                mp2[s2.at(left)]--;
                if(mp2[s2.at(left)]==0)
                {
                    mp2.erase(s2.at(left));
                }

                left++;


            }


            right++;


        }



        return false;


        
    }
};