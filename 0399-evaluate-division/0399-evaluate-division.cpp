class Solution {
public:


   //checkdfs(numerator,a,b,cprod,result,visited,mp);


   bool checkdfs(  map<string,unordered_set<string>>& numerator,string start,string target,double& cprod,double& result,unordered_set<string>& visited, map<pair<string,string>,double>& mp)
   {
          

          if(start==target)
          {
             result=cprod;
             return true;
          }


          visited.insert(start);

          for(auto it: numerator[start])
          {
            if(visited.find(it)!=visited.end())
            {
                continue;
            }

            double temp = cprod*mp[make_pair(start,it)];
            if(checkdfs(numerator,it,target,temp,result,visited,mp))
            {
                return true;
            }

            

          }

          return false;

   }



    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<pair<string,string>,double> mp;
        map<string,unordered_set<string>> numerator;

        for(int i=0;i<equations.size();i++)
        {
            string a = equations[i][0];
            string b = equations[i][1];
            numerator[a].insert(b);
            numerator[b].insert(a);




            pair<string,string> p1 = make_pair(a,b);
            pair<string,string> p2 = make_pair(b,a);

            mp[p1]=values[i];
            mp[p2]=(double)1/values[i];
           

        }

        vector<double> ans;

        for(auto it: queries)
        {
            string a = it[0];
            string b = it[1];

            pair<string,string> temp = make_pair(a,b);

            if(mp.find(temp)!=mp.end())
            {
                ans.push_back(mp[temp]);
            }else{

                 if(numerator.find(a)==numerator.end() || numerator.find(b)==numerator.end())
                    {
                        ans.push_back(-1.0);
                        continue;
                    }

                if(a==b)
                {
                    ans.push_back((double)1);
                }else{

                   


                    double result = -1.0;
                    double cprod=1.0;
                    unordered_set<string> visited;
                    checkdfs(numerator,a,b,cprod,result,visited,mp);
                    ans.push_back(result);

                   
                }

            }

        }



        return ans;


        


        
    }
};