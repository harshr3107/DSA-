class Solution {
public:
    int fillCups(vector<int>& amount) {

        priority_queue<int> pq;

        for(auto it: amount)
        {
            if(it!=0)
            {
                pq.push(it);
            }
        }

        int ans=0;


        while(pq.size()>1)
        {

            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans++;

            if(a-1>0)
            {
                pq.push(a-1);
            }

            if(b-1>0)
            {
                pq.push(b-1);
            }

            

        }

        if(!pq.empty())
        {
            ans+=pq.top();
        }

        return ans;
          
    }
};