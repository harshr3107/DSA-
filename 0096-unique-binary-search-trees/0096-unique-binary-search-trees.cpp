class Solution {
public:
    
    int getans(int n)
    {

        if(n<=1)
        {
            return 1;
        }

        int ans=0;

        for(int i=1;i<=n;i++)
        {
                ans+=(getans(i-1)*getans(n-i));
        }

        return ans;

    }

    int numTrees(int n) {

            return getans(n);
       
    }
};