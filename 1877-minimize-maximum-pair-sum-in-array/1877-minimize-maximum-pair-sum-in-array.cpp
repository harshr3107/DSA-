
class compare
{
    public:
    bool operator()(int& a,int& b)
    {
        return a>b;
    }

};




class Solution {
public:
    int minPairSum(vector<int>& nums) {

        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,compare> minheap;

        for(int i=0;i<nums.size();i++)
        {
            maxheap.push(nums[i]);
            minheap.push(nums[i]);
        }

        priority_queue<int> pq;

        while(!maxheap.empty())
        {

            pq.push(maxheap.top()+minheap.top());
            maxheap.pop();
            minheap.pop();
               
        }



        return pq.top();

        
    }
};