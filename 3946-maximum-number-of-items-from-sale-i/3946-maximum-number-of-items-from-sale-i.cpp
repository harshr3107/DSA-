class Solution {
public:
    // getall(items,budget,free);

    int getall(vector<vector<int>>& items,int i,int prev,int budget,vector<int>& free,vector<vector<vector<int>>>& dp)
    {
        if(budget<0)
        {
            return -1e9+7;
        }

        if(i==items.size())
        {
            return 0;
        }

        int alreadyBought = (prev == i);
        int& answer = dp[alreadyBought][i][budget];

        if (answer != -1)
        {
            return answer;
        }

        //take an item

        int take=-1e9+7;

        if(prev!=i)
        {
                 take = 1+free[i]+getall(items,i,i,budget-items[i][1],free,dp);
        }else{
                 take = 1+getall(items,i,prev,budget-items[i][1],free,dp);
        }
        int nottake = getall(items,i+1,prev,budget,free,dp);

        return answer=max(take,nottake);

    }


    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        //we need to find free wala array which has list of number of free items availaible 
       /* vector<int> free(items.size(),0); 

       sort(items.begin(),items.end());

        //cout<<"first checkpoint\n";

        int a=0;

         for(int i=0;i<items.size();i++)
         {
            if(i>0 && items[i]==items[i-1])
            {
                    free[i]=a;
                    continue;
            }

            a=0;
            

            for(int j=i+1;j<items.size();j++)
            {
                if((items[j][0]%items[i][0])==0)
                {
                    a++;
                }


            }

            free[i]=a;

         }

        

         //cout<<"i am okay till now\n";

         //now we know the free items availaible as well
         
         int i=0;
         int prev=-1;
         return getall(items,i,prev,budget,free);*/

         int n = items.size();
        vector<int> free(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i && items[j][0] % items[i][0] == 0)
                {
                    free[i]++;
                }
            }
        }

        vector<vector<vector<int>>> dp(2,vector<vector<int>>(items.size(),vector<int>(budget+1,-1)));

        return getall(items, 0, -1, budget, free,dp);
        
    }
};