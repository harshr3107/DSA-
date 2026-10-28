class Solution {
public:
   //getans(adjlist,src,dst,k);


   class compare
   {
       public:

       bool operator()(vector<int>& a,vector<int>& b)
       {
           return a[0]>b[0];
       }



   };


   int getans(vector<vector<pair<int,int>>>& adjlist,int& src,int& dst,int k)
   {

       priority_queue<vector<int>,vector<vector<int>>,compare> pq;

       vector<vector<int>> distance(adjlist.size(),vector<int>(k+2,INT_MAX));

       vector<int> v;
       v.push_back(0);
       v.push_back(src);
       v.push_back(0);

       pq.push(v);


       while(!pq.empty())
       {

          auto it = pq.top();
          pq.pop();

          int cost = it[0];
          int cst = it[1];
          int cstp=it[2];

         //cout<<"i am here for "<<cst<<" current cost is "<<cost<<" and stop number is "<<cstp<<endl;

          if(cst==dst)
          {
            return cost;
          }

          if(cstp==k+1)
          {
            continue;
          }

          for(auto it: adjlist[cst])
          {
              auto nsta = it.first;
              auto ncost = it.second;
             
              if(distance[nsta][cstp+1]>cost+ncost)
              {
                distance[nsta][cstp+1]=cost+ncost;
                v.clear();
                v.push_back(cost+ncost);
                v.push_back(nsta);
                v.push_back(cstp+1);

                pq.push(v);
              }

          }

       }



       return -1;

        

   }



    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> adjlist(n);

        for(int i=0;i<flights.size();i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adjlist[u].push_back(make_pair(v,w));

        }


        return getans(adjlist,src,dst,k);


        
    }
};