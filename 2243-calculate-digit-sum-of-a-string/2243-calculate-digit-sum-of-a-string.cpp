class Solution {
public:
    string digitSum(string s, int k) {

        string cstr="";

        int i=0;
        string ans="";

        while(s.length()>k)
        {
            //cout<<"the curret value of string is "<<s<<endl;

            
            ans="";

            i=0;
            int csum=0;
            int l=0;

            while(i<s.length())
            {
                csum=csum+(s.at(i)-'0');
                l++;
                if(l==k)
                {
                    ans=ans+to_string(csum);
                    csum=0;
                    l=0;
                }

                i++;


            }

            if(l!=0)
            {
                ans=ans+to_string(csum); 
            }

            s=ans;

        }

        return s;
        
    }
};