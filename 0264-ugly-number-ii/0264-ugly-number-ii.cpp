
class compare
{
    public:

    bool operator()(long long& a,long long& b)
    {
        return a>b;
    }


};









class Solution {
public:




    int nthUglyNumber(int n) {


        priority_queue<long long,vector<long long>,compare> pq;

        pq.push(1);
        pq.push(2);
        pq.push(3);
        pq.push(5);

        unordered_set<long long> st;
        st.insert(1);
        st.insert(2);
        st.insert(3);
        st.insert(5);

        int h=1;

        while(h<=n)
        {
            long long a = pq.top();
            pq.pop();

            //cout<<"the "<<h<<" th number is "<<a<<endl;

            if(h==n)
            {
                return a;
            }

            if(st.find(a*2)==st.end())
            {
                pq.push(a*2);
                st.insert(a*2);
            }

            if(st.find(a*3)==st.end())
            {
                pq.push(a*3);
                st.insert(a*3);
            }


            if(st.find(a*5)==st.end())
            {
                pq.push(a*5);
                st.insert(a*5);
            }

            h++;


        }


        return -1;
        
    }
};