class Solution {
public:

   //ispossible(board,i,j,k)

   bool ispossible(vector<vector<char>>& board,int i,int j,char k)
   {

        //i am checking row

         int temp=i;



         while(temp<board.size())
         {
            if(board[temp][j]>='0' && board[temp][j]<='9')
            {
                if(board[temp][j]==k)
                {
                    return false;
                }
            }

            temp++;

         }

         //i am checking column

         temp=j;


         while(temp<board[i].size())
         {
            if(board[i][temp]>='0' && board[i][temp]<='9')
            {
                if(board[i][temp]==k)
                {
                    return false;
                }
            }

            temp++;

         }

         //now check 3*3 box

         int si = 3*(i/3);
         int sj = 3*(j/3);

         int li = si+3;
         int lj = sj+3;

         si+=1;
         sj+=1;

         while(si!=li && sj!=lj)
         {
            int tempi = si;
            while(tempi!=li)
            {
                if(board[tempi][sj]>='0' && board[tempi][sj]<='9')
                {
                    if(board[tempi][sj]==k)
                    {
                        return false;
                    }
                }

                tempi++;

            }

            int tempj=sj;

            while(tempj!=lj)
            {
                if(board[si][tempj]>='0' && board[si][tempj]<='9')
                {
                    if(board[si][tempj]==k)
                    {
                        return false;
                    }
                }

                tempj++;

            }

            

                si++;
                sj++;

        }


        return true; 




   }
   

    bool checkif(vector<vector<char>>& board,int i,int j)
    {
        if(i==board.size() && j==0)
        {
            return true;
        }

       

        if(board[i][j]>='0' && board[i][j]<='9')
        {
            if(j==board[i].size()-1)
            {
                if(checkif(board,i+1,0)==true)
                {
                    return true;
                }
            }else{

                if(checkif(board,i,j+1)==true)
                {
                    return true;
                }


            }



        }else{

            for(char k='1';k<='9';k++)
            {

                if(ispossible(board,i,j,k))
                {
                    board[i][j]=k;

                        if(j==board[i].size()-1)
                        {
                            if(checkif(board,i+1,0)==true)
                            {
                                return true;
                            }
                        }else{

                                if(checkif(board,i,j+1)==true)
                                {
                                    return true;
                                }


                            }


                    board[i][j]='.';
                }
                            

            }




        }

        return false;




    }


    bool isValidSudoku(vector<vector<char>>& board) {

        int i=0;
        int j=0;

        return checkif(board,i,j);
        
    }
};