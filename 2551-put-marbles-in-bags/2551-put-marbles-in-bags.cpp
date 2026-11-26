
class compare
{
    public:

    bool operator()(long long& a,long long& b)
    {
        return a>b;
    }

};









class Solution {
public:
   


    long long putMarbles(vector<int>& weights, int k) {

        priority_queue<long long> maxheap;
        priority_queue<long long,vector<long long>,compare> minheap;


          for(int i=0;i<weights.size()-1;i++)
          {
            maxheap.push(weights[i]+weights[i+1]);
            minheap.push(weights[i]+weights[i+1]);

          }

          long long mini=0;
          long long maxi=0;

          for(int i=0;i<k-1;i++)
          {
            mini+=minheap.top();
            maxi+=maxheap.top();
            minheap.pop();
            maxheap.pop();

          }

          return maxi-mini;
        
    }
};