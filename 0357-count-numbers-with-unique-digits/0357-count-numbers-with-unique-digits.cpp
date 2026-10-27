class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {

        //i feel we need to find number of numbers with no unique digit;

        if(n==0)
        {
            return 1; 
        }

        int current=9;
        int start=9;
        int ans=10;


        while(n!=1 && start>0)
        {
             current = current*start;
             start--;
             ans+=current;
             n--;

        }


        return ans;




        
        
    }
};