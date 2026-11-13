class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        int i = source[0];
        int j = source[1];

        int ti=target[0];
        int tj=target[1];

        if(i==ti && j==tj)
        {
            return 0;
        }

        if(i==ti || j==tj || (abs(i-ti)==abs(j-tj)))
        {
            return 1;
        }

        return 2;


        
    }
};