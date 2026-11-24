class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {

        //try for even index

        int i=1;
        int steps=0;

        while(i<nums.size())
        {
            int a = nums[i-1];
            
            if((i+1)<nums.size())
            {
                a=min(nums[i+1],a);
            }

            if(a>nums[i])
            {
                i+=2;
                continue;
            }else{
                steps+=(nums[i]-a+1);
                i+=2;
            }

        }

        int l = steps;

        steps=0;

        //try for odd indixes
        i=0;

        while(i<nums.size())
        {
            int a = INT_MAX;  

            if((i-1)>=0)
            {
                a=min(a,nums[i-1]);
            }

            if((i+1)<nums.size())
            {
                a=min(a,nums[i+1]);
            }

            if(a>nums[i])
            {
                i+=2;
                continue;
            }else{

                steps+=(nums[i]-a+1);
                i+=2;

            }


        }

        return min(steps,l);
        
    }
};