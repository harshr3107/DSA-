class Solution {
public:
    
    void display(vector<int>& v)
    {
        for(auto it: v)
        {
            cout<<it<<" ";
        }

        cout<<endl;
    }

    int minOperations(vector<int>& nums) {

        //i feel being greedy would work here

        int i=0;
        int ans=0;

        while(i<nums.size()-2)
        {
            //display(nums);

            if(nums[i]==1)
            {
                i++;
                continue;
            }else{
                
                ans++;
                nums[i]=1;
                nums[i+1]=nums[i+1]==0?1:0;
                nums[i+2]=nums[i+2]==0?1:0;

            }

            

            i++;

        }

        if(nums[i]==0 || nums[i+1]==0)
        {
            return -1;
        }

        return ans;
        
    }
};