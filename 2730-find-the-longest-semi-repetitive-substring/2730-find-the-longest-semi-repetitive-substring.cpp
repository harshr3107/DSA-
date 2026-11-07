class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {

        int i=0;
        int j=1;

        int l=-1;
        int ans=1;

        while(j<s.length())
        {
            

            if(s.at(j)==s.at(j-1))
            {
                int h = s.at(j)-'0';

                if(l!=-1)
                {
                    i=l;
                }
                
                l=j;
            }

            ans=max(ans,j-i+1);

            j++;

            



        }


        return ans;
        
    }
};