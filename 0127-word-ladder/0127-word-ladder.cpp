class compare
{
      public: 

      bool operator()(pair<int,string>& a,pair<int,string>& b)
      {
          return a.first>b.first;
      }


};




class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

           unordered_set<string> s;

           for(auto it: wordList)
           {
              s.insert(it);
           }

           priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;

           pq.push(make_pair(1,beginWord));
           s.erase(beginWord);

           while(!pq.empty())
           {

              auto it = pq.top();
              pq.pop();
              string cword = it.second;
              int cstep = it.first;

              if(cword==endWord)
              {
                return cstep;
              }

              for(int i=0;i<cword.length();i++)
              {
                 for(char a='a';a<='z';a++)
                 {
                     string temp = cword;
                     temp.at(i)=a;
                     if(s.find(temp)!=s.end())
                     {
                        s.erase(temp);
                        pq.push(make_pair(cstep+1,temp));
                     }


                 }

              }



           }

           return 0;
        
    }
};