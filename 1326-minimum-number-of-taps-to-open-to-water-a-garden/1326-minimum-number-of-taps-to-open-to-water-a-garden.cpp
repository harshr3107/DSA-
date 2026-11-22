




class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

       

        vector<int> jump(ranges.size(),0);

        
        for(int i=0;i<ranges.size();i++)
        {
            int low = max(0,i-ranges[i]);
            int high = min(n,i+ranges[i]);

            jump[low]=max(jump[low],high);



        }


        for(auto it: jump)
        {
            cout<<it<<" ";
        }

        int cend=0;
        int ans=0;
        int farthest=0;

        for(int i=0;i<jump.size()-1;i++)
        {
            farthest=max(farthest,jump[i]);

            if(cend==i)
            {
                cend=farthest;
                ans++;
            }


        }

        return cend==jump.size()-1?ans:-1;


        




       



        
    }
};