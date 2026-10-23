class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        for(auto it: nums)
        {
            cout<<it<<" ";
        }


         int low=0;
         int high=nums.size()-1;
          int a=0;

          int ind=-1;

         while(high>=low)
         {
            int mid = low+(high-low)/2;

            if(nums[mid]==target)
            {
                ind=mid;
                high=mid-1;
                continue;
                


            }

            if(nums[mid]>target)
            {

                high=mid-1;


            }else{

                low=mid+1;
                
            }



         }


        vector<int> ans;

         if(ind==-1)
         {
            return ans;
         }

         

         while(ind<nums.size() && nums[ind]==target)
         {
            ans.push_back(ind);
            ind++;
         }


         return ans;
        
    }
};