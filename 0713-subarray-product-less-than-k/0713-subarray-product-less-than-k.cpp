class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int i=0;
        int j=0;
        long long cprod=1;
        int ans=0;

         while(j<nums.size())
         {
            cprod=cprod*nums[j];

            while(i<=j && cprod>=k)
            {
                cprod=cprod/nums[i];
                i++;
            }

            ans=ans+(j-i+1);

            j++;

         }


         return ans;
        
    }
};