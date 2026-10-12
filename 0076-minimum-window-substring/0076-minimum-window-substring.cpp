class Solution {
public:
    //issame(mp2,mp1)


    bool issame(unordered_map<char,int>& mp1,unordered_map<char,int>& mp2)
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


    string minWindow(string s, string t) {

        int left=0;
        int right=0;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(auto it: t)
        {
            mp1[it]++;
        }

      

        int ans=INT_MAX;
        int lind=0;
       



        while(right<s.length())
        {
            //cout<<"i entered here for left and right is "<<left<<" "<<right<<endl;

            mp2[s.at(right)]++;

            while(issame(mp1,mp2))
            {
                //cout<<"mai ander aayay\n";

                //cout<<"value of left and right is "<<left<<" "<<right<<endl;

               

                if(ans==0 || ans>(right-left+1))
                {
                    ans=right-left+1;
                    lind=left;
                    

                }

                mp2[s.at(left)]--;

               
                left++;

            }

            //cout<<"current value of ans is "<<ans<<endl;


            right++;

            







        }

        return ans==INT_MAX?"":s.substr(lind,ans);
        
    }
};