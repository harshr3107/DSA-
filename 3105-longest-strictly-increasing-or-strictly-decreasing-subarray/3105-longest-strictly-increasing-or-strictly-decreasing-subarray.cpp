class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int i=0;
        int j=1;
        int increasing=-1;
        int ans=1;

        while(j<nums.size())
        {

            if(increasing==-1 || nums[j]==nums[j-1])
            {
                if(nums[j]>nums[j-1])
                {
                    increasing=1;
                }else if(nums[j]<nums[j-1])
                {
                    increasing=0;
                }else{
                    i=j;
                    increasing=-1;
                }

                ans=max(ans,j-i+1);
                j++;
                
                continue;

            }



            if(increasing==1)
            {

                if(nums[j]>nums[j-1])
                {


                }else{
                    i=j-1;
                    increasing=0;
                }




            }else{


                if(nums[j]<nums[j-1])
                {


                }else{
                    i=j-1;
                    increasing=1;
                }



            }

            ans=max(ans,j-i+1);
            j++;



        }


        return ans;
        
    }
};