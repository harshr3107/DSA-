class Solution {
public:
   
   int getstatevalue(string& s)
   {
      int i=0;
      int state=0;
      while(i<s.length())
      {
            int index = s.at(i)-'a';
            state=(state|1<<index);
            i++;

      }

      return state;



   }


    int maxProduct(vector<string>& words) {

        vector<int> state(words.size(),0);

        for(int i=0;i<words.size();i++)
        {
            state[i]=getstatevalue(words[i]);
        }

        int ans=0;

        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((state[i]&state[j])==0)
                {
                    int l = words[i].length()*words[j].length();
                    ans=max(ans,l);
                }
            

            }

        }


       return ans;
        
    }
};