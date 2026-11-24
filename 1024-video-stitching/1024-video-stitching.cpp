class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {

        //use minimum jumps wala approach

        vector<int> jump(time+1,0);

        for(int i=0;i<clips.size();i++)
        {
            int u = min(time,clips[i][0]);
            int v = min(time,clips[i][1]);

            jump[u]=max(jump[u],v);
        }


        int currentend=0;
        int ans=0;
        int farthest=0;

        for(int i=0;i<jump.size()-1;i++)
        {
            farthest=max(farthest,jump[i]);

            if(i==currentend)
            {
                currentend=farthest;
                if(currentend==i)
                {
                    return -1;
                }
                ans++;
            }


        }

        return ans; 
        
    }
};