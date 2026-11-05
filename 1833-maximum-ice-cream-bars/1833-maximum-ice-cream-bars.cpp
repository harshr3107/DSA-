class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(),costs.end());

        int i=0;
        for(i=0;i<costs.size();i++)
        {
            if(coins-costs[i]>=0)
            {
                coins-=costs[i];
            }else{
                break;
            }

        }

        return i;
        
    }
};