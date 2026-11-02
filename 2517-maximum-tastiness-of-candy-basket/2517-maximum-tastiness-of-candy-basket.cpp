class Solution {
public:
    
    //checkpossible(price,k,mid)

    bool checkpossible(vector<int>& price,int k,int mid)
    {

        int a = price[0];
        k=k-1;
        

        for(int i=1;i<price.size();i++)
        {

            if(price[i]-a>=mid)
            {
                a=price[i];
                k--;

                if(k==0)
                {
                    return true;
                }
            }


        }

        return false;


    }


    int maximumTastiness(vector<int>& price, int k) {

        sort(price.begin(),price.end());

        int low=0;
        int high=*max_element(price.begin(),price.end());
        int ans=0;


        while(high>=low)
        {
            int mid=low+(high-low)/2;

            if(checkpossible(price,k,mid))
            {
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }

        }

        return ans;


        
    }
};