class Solution {
public:
    int maxProduct(vector<string>& words) {

        //brute force would be my forst approach 
        unordered_set<char> s;
        int ans=0;

        for(int i=0;i<words.size()-1;i++)
        {
            s.clear();
            for(int k=0;k<words[i].length();k++)
            {
                s.insert(words[i][k]);
            }

            for(int j=i+1;j<words.size();j++)
            {
                
                int a=0;

                for(int l=0;l<words[j].length();l++)
                {
                    if(s.find(words[j][l])!=s.end())
                    {
                        a++;
                        break;
                    }

                }

                if(a==0)
                {
                    int len = words[i].length()*words[j].length();
                     ans=max(ans,len);
                }

            }
           
           

        }

        return ans;


        
    }
};