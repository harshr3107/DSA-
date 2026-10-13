
class compare
{
    public:

    bool operator()(int& a,int& b)
    {
        return abs(a)<abs(b);
    }
};





class Solution {
public:
    




    long long maxAlternatingSum(vector<int>& nums) {

        priority_queue<int,vector<int>,compare> pq;

        for(auto it: nums)
        {
            pq.push(it);
        }

        int n = nums.size();

        int a = n/2;

        if((n&1)==1)
        {
            a+=1;
        }



        long long ans=0;

        while(a!=0)
        {
            int h = pq.top();
            pq.pop();
            ans=ans+1LL*h*h;
            a--;

        }


        while(!pq.empty())
        {
            int h = pq.top();
            ans=ans-1LL*h*h;
            pq.pop();
        }

        return ans;
        
    }
};