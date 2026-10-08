class Solution {
public:

//getmaxans(matrix,i,s,mp,k)

    int getmaxans(vector<vector<int>>& matrix,int i,vector<int>& v,map<int,vector<int>>& mp,int k)
    {

        if (k == 0) {
            set<int> uncovered;

            for (int col = 0; col < matrix[0].size(); col++) {
                if (find(v.begin(), v.end(), col) == v.end()) { // col is unselected
                    for (int row : mp[col]) {
                        uncovered.insert(row);
                    }
                }
            }

    return matrix.size() - uncovered.size();
}

        if(i==matrix[0].size())
        {
            return INT_MIN;
        }

        //select a col

        v.push_back(i);
        int h = getmaxans(matrix,i+1,v,mp,k-1);
        v.pop_back();
        int r = getmaxans(matrix,i+1,v,mp,k);


        return max(h,r);

    }
   

    int maximumRows(vector<vector<int>>& matrix, int k) {


            //let me try dynamic programming in it 

            map<int,vector<int>> mp;

            for(int i=0;i<matrix.size();i++)
            {
                for(int j=0;j<matrix[0].size();j++)
                {
                    if(matrix[i][j]==1)
                    {
                       
                            mp[j].push_back(i);
                    }

                }

            } 

            int i=0;
             vector<int> v;

            return getmaxans(matrix,i,v,mp,k);




    
        
    }
};