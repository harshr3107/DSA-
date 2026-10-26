class Solution {
public:
    void funcall(vector<int>&arr){
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
    }
    vector<int>func(int i,int j,string &s,unordered_map<long long,vector<int>>&dp){
        if(i==j)return {s[i]-'0'};
        long long key=1LL*i*100+j;
        if(dp.count(key))return dp[key];
        vector<int>ans;
        for(int k=i+1;k<j;k+=2){
            if(s[k]=='*'){
                vector<int>arr1=func(i,k-1,s,dp);
                vector<int>arr2=func(k+1,j,s,dp);
                for(auto it:arr1){
                    for(auto itt:arr2){
                        if(it*itt<=1000){
                        ans.push_back(it*itt);
                        }
                    }
                }
            }
            if(s[k]=='+'){
                vector<int>arr1=func(i,k-1,s,dp);
                vector<int>arr2=func(k+1,j,s,dp);
                for(auto it:arr1){
                    for(auto itt:arr2){
                        if(it+itt<=1000){
                        ans.push_back(it+itt);
                        }
                    }
                }
            }
        }
        funcall(ans);
        return dp[key]=ans;
    }
    int evaluate(string s){
    stack<int>st;
    int n=s.size();
    st.push(s[0]-'0');
    for(int i=1;i<n;i+=2){
        char op=s[i];
        int num=s[i+1]-'0';
        if(op=='+'){
           st.push(num);
        }
        else if(op=='*'){
            int top=st.top();
            st.pop();
            st.push(top*num);
        }
    }
    int ans=0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
    int scoreOfStudents(string s, vector<int>& answers) {
        int n=s.size();
        unordered_map<long long,vector<int>>dp;
        unordered_map<int,int>mpp;
        for(auto it:answers)mpp[it]++;
        int ans=0;
        int correctans=evaluate(s);
        vector<int>arr=func(0,n-1,s,dp);
        funcall(arr);
        for(auto it:arr){
            if(mpp.count(it)&&it==correctans)ans+=mpp[it]*5;
            else if(mpp.count(it)&&it!=correctans)ans+=mpp[it]*2;
        }
        return ans;
    }
};