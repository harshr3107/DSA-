class Solution {
public:

   long long getcost(vector<int>& nums,vector<int>& cost,int val)
   {

        int i=0;
        long long h=1LL;

        while(i<nums.size())
        {
            

            long long l = abs(nums[i]-val);
            long long k = cost[i];

            h=h+(l*k);
            i++;

        }


        return h;

   }


    long long minCost(vector<int>& nums, vector<int>& cost) {

        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());


         long long ans=0;

         while(high>=low)
         {

            int mid = low+(high-low)/2;

            long long a = getcost(nums,cost,mid);
            long long b = getcost(nums,cost,mid+1);

            if(a<b)
            {
                ans=a;
                high=mid-1;

            }else{

                low=mid+1;
                
            }


         }

         return ans-1;


        
    }
};