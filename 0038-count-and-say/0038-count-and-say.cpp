class Solution {
public:
    string countAndSay(int n) {
        
        int h=n;
        string ans="1";
        while(n!=1)
        {

            //cout<<"value of ans is "<<ans<<endl;

            string h="";

            int i=0;

            while(i<ans.length())
            {
              


                int j=i;
                while(j<ans.length() && ans[j]==ans[i])
                {
                    j++;
                }

                int freq=j-i;
                h=h+to_string(freq)+ans[i];
                i=j;

            }

            ans=h;
            n--;

        


        }

        return ans;
        
    }
};