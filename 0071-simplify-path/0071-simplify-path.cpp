class Solution {
public:
    string simplifyPath(string path) {
        

        vector<string> v;

        int i=0;

        while(i<path.length())
        {

            if(path[i]=='/')
            {
                while(i<path.length() && path[i]=='/')
                {
                    i++;
                }

                continue;

            }


            if(path[i]=='.' && (i+1)<path.length() && path[i+1]=='/')
            {
                i++;
            }else if(path[i]=='.' && (i+1)<path.length() && path[i+1]=='.' && (i+2)<path.length() && path[i+2]=='/')
            {
                i=i+2;
                if(!v.empty())
                {
                    v.pop_back();
                }
            }else if(path[i]=='.' && (i+1)<path.length() && path[i+1]=='.' && (i+2)==path.length()){

                 i=i+2;
                if(!v.empty())
                {
                    v.pop_back();
                }
            
            
            }else if(path[i]=='.' && (i+1)==path.length())
            {

                    i+=1;
            
            
         }else
            {
                string h="";

                while(i<path.length() && path[i]!='/')
                {
                    h+=path[i];
                    i++;
                }

                v.push_back(h);

            }



        }


        string ans="";
        for(int i=0;i<v.size();i++)
        {

            cout<<v[i]<<" ";
            ans=ans+"/"+v[i];
        }


        return ans.length()==0?"/":ans;


    }
};