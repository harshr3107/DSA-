class Solution {
public:
    bool judgeSquareSum(int c) {

        int low = 0;
        int high = sqrt(c);


        while(high>=low)
        {
            long long a = pow(low,2)+pow(high,2);

            if(a==c)
            {
                return true;
            }

            if(a>c)
            {
                high--;
            }else{
                low++;
            }
            


        }


        return false;


        
    }
};