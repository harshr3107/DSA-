class Solution {
public:
    
    class compare
    {
        public:

        int getdigit(int a)
        {
            int sum=0;

            while(a!=0)
            {
                sum=sum+(a%10);
                a=a/10;
            }

            return sum;


        }



        bool operator()(pair<int,int>& a,pair<int,int>& b)
        {
            int digit1 = getdigit(a.first);
            int digit2 = getdigit(b.first);

            if(digit1==digit2)
            {
                return a>b;
            }

            return digit1>digit2;



        }

    };




    int minSwaps(vector<int>& nums) {

          priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;

          for(int i=0;i<nums.size();i++)
          {
             pq.push(make_pair(nums[i],i));
          }

         vector<int> order;

        while (!pq.empty()) {
            order.push_back(pq.top().second); // original index, in sorted order
            pq.pop();
        }

        vector<bool> visited(nums.size(), false);
        int ans = 0;

        for (int i = 0; i < order.size(); i++) {
            if (visited[i]) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = order[j];
                cycleSize++;
            }

            if (cycleSize > 1) {
                ans += cycleSize - 1;
            }
        }

        return ans;

          

          


          



          
        
    }
};