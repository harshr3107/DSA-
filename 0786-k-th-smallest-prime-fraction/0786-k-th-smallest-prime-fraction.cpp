
class compare
{
    public:
       
       bool operator()(pair<int,int>& a,pair<int,int>& b)
       {
          double l1 = (double)a.first/(double)a.second;
          double l2 = (double)b.first/(double)b.second;


          return l1<l2;
         

       }



};




class Solution {
public:


    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                pq.push(make_pair(arr[i],arr[j]));

                if(pq.size()>k)
                {
                    pq.pop();
                }

            }

        }

        vector<int> ans;
        auto it = pq.top();

        ans.push_back(it.first);
        ans.push_back(it.second);

        return ans;
        
    }
};