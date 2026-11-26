class Solution {
public:
    bool canAliceWin(int n) {

        int y = 2*n;

        int i=1;

        while(i*(21-i)<=y)
        {
            i++;
        }

        if((i&1)==1)
        {
            return false;
        }

        return true;


        
    }
};