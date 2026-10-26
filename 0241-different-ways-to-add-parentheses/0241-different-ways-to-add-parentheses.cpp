class Solution {
public:


    vector<int> getans(string& s,int start,int end)
    {
        if(start>end)
        {
            return {};
        }


        vector<int> result;
        int a=0;


        for(int i=start;i<=end;i++)
        {
            if(s.at(i)=='+' || s.at(i)=='-' || s.at(i)=='*')
            {
                a++;

                vector<int> left = getans(s,start,i-1);
                vector<int> right = getans(s,i+1,end);



                for(auto it: left)
                {
                    for(auto it2: right)
                    {
                         if(s.at(i)=='+')
                         {
                            result.push_back(it+it2);

                         }else if(s.at(i)=='-')
                         {
                            result.push_back(it-it2);

                         }else{

                            result.push_back(it*it2);


                         }

                    }

                }



            }





            

        }


        if(a==0)
        {
            int h=0;
            //cout<<"value of start is "<<start<<" and the end is "<<end<<endl;

            while(start<=end)
            {
                h=h*10+(s.at(start)-'0');
                start++;
            }

            //cout<<"value of h is "<<h<<endl;

            result.push_back(h);

        }


        return result; 
        
        
    }


    vector<int> diffWaysToCompute(string expression) {

        //it is a question very similar to flatten a binary tree
        int start=0;
        int end=expression.length()-1;
        return getans(expression,start,end);


        



        
    }
};