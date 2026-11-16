class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int i=0;
        int j=0;
        long long csum=0;
        long long  ans=0;

        while(j<nums.size())
        {
            csum+=nums[j];

            long long clen = (j-i+1);

            while(i<=j && (csum*clen)>=k)
            {
                csum-=nums[i];
                clen--;
                i++;

            }

            ans=ans+(j-i+1);
            j++;


        }

        return ans;
        
    }
};