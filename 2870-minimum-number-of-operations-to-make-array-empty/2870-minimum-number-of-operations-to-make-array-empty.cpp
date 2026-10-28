class Solution {
public:
    int minOperations(vector<int>& nums) {

        map<int,int> mp;

        for(auto it: nums)
        {
            mp[it]++;
        }


        int oper=0;

        for(auto it: mp)
        {
            int h = it.second;

            if(h==1)
            {
                return -1;
            }

            if(h==2)
            {
                oper+=1;
                continue;
            }


            while(h%3!=0)
            {
                oper+=1;
                h-=2;
                if(h==2)
                {
                    oper+=1;
                    h-=2;
                    break;
                }else if(h==1)
                {
                    return -1;
                }
            }

            oper=oper+h/3;

        }


        return oper;
        
    }
};