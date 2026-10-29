class Solution {
public:
     
     int getlongest(vector<int>& nums,int i,int prevind,int sign,vector<vector<vector<int>>>& dp)
     {
        if(i==nums.size())
        {
            return 0;
        }

        if(dp[prevind+1][i][sign]!=-1)
        {
            return dp[prevind+1][i][sign];
        }

        int take=0;
        int nottake=0;

        int og = sign;


        if(prevind==-1)
        {
            take=1+getlongest(nums,i+1,i,sign,dp);
            nottake = getlongest(nums,i+1,prevind,sign,dp);
            
        }else{

         nottake = getlongest(nums,i+1,prevind,sign,dp);

         int diff= nums[i]-nums[prevind];


          if(diff!=0 && (sign==0 || (sign==1 && (nums[i]-nums[prevind])<0) || (sign==2 && (nums[i]-nums[prevind])>0)))
          {
              

               if(sign==0)
               {

                     sign = nums[i]-nums[prevind]>0?1:2;
                 
               }else{

               sign = (sign == 1 ? 2 : 1);



               }

               take=1+getlongest(nums,i+1,i,sign,dp);

          }

          



        }

        return dp[prevind+1][i][og]=max(take,nottake);


     }


    int wiggleMaxLength(vector<int>& nums) {

        int i=0;
        int sign=0;
        int prevind=-1;

        vector<vector<vector<int>>> dp(nums.size()+1,vector<vector<int>>(nums.size(),vector<int>(3,-1)));

        return getlongest(nums,i,prevind,sign,dp);


        
    }
};