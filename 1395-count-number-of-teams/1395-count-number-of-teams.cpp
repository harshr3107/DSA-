class Solution {
public:
    int numTeams(vector<int>& rating) {

        vector<int> leftgreater(rating.size(),0);
        vector<int> leftsmaller(rating.size(),0);

        for(int i=0;i<rating.size();i++)
        {
            int a=0;
            int b=0;
            for(int j=0;j<i;j++)
            {
                if(rating[j]>rating[i])
                {
                    a++;
                }else if(rating[j]<rating[i])
                {
                    b++;
                }

            }

            leftgreater[i]=a;
            leftsmaller[i]=b;

        }

        vector<int> rightgreater(rating.size(),0);
        vector<int> rightsmaller(rating.size(),0);


        for(int i=rating.size()-1;i>=0;i--)
        {
            int a=0;
            int b=0;
            for(int j=rating.size()-1;j>i;j--)
            {
                if(rating[i]>rating[j])
                {
                    b++;
                }else if(rating[j]>rating[i])
                {
                    a++;
                }

            }

            rightsmaller[i] = b;
            rightgreater[i] = a;


        }

        int ans=0;


        for(int i=0;i<rating.size();i++)
        {
            ans+= leftsmaller[i]*rightgreater[i];
            ans+= leftgreater[i]*rightsmaller[i];
            

        }

        return ans;
        
    }
};