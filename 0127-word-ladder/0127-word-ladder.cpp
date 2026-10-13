class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        


        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));

        unordered_set<string> visited;
        visited.insert(beginWord);

        unordered_set<string> words;

        for(auto it: wordList)
        {
            words.insert(it);
        }

        while(!q.empty())
        {
            auto it  = q.front();
            string h = it.first;
            int l = it.second;
            q.pop();

            cout<<"value of string is "<<h<<" at level "<<l<<endl;

            if(h==endWord)
            {
                return l;
            }



            for(int i=0;i<h.length();i++)
            {
                for(char a='a';a<='z';a++)
                {
                     string temp = h;
                     temp.at(i)=a;

                     if(visited.find(temp)==visited.end() && words.find(temp)!=words.end())
                     {
                        visited.insert(temp);
                        q.push(make_pair(temp,l+1));
                     }


                }


            }


        }


        return 0;

        
    }
};