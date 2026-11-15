class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {

        int i=0;
        int j=0;


        int csum=0;
        int mod=1e9+7;

        unordered_map<int,int> mp;
        mp[0]=1;
        int ans=0;

        for(int i=0;i<arr.size();i++)
        {
            csum+=arr[i];

            if((csum&1)==1)
            {
                ans=(ans+mp[0])%mod;

            }else{

                ans=(ans+mp[1])%mod;

            }

            mp[(csum&1)]++;

        }


        return ans;        
    }
};