class Solution {
public:
    int maxArea(vector<int>& nums) {

       int i=0;
       int j=nums.size()-1;
       int ans=INT_MIN;

       while(j>=i)
       { 

          int h = min(nums[i],nums[j])*(j-i);
          ans=max(ans,h);

          if(nums[i]>nums[j])
          {
            j--;
          }else
          {
            i++;
          }





       }




        return ans;
        
    }
};