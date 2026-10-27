class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string> ans(m);

        string s;
        for(int i=0;i<n;i++)
        {
            s+=".";
        }

        for(int i=0;i<m;i++)
        {
            ans[i]=s;
        }

        int i=0;
        int j=0;

        while(i!=m-1 && j!=n-1)
        {

            bool gotit=true;

            if((i+1)<m && ans[i+1][j]=='.')
            {
                gotit=false;
                //it is moving right so down option is blocked
                if((j+1)<n)
                {
                    ans[i][j+1]='#';
                }

                i=i+1;


            }

            if(gotit)
            {
                if((j+1)<n && ans[i][j+1]=='.')
                {
                   
                    //it is moving right so down option is blocked
                    if((i+1)<m)
                    {
                        ans[i+1][j]='#';
                    }

                    j=j+1;


                }

            }



        }

        return ans;
        
    }
};