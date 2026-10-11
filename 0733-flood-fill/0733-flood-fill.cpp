class Solution {
public:
     
    void getall(vector<vector<int>>& image,int sr,int sc,int color,int ogcol)
    {
        image[sr][sc]=color;

        //check for left

        if((sc-1)>=0 && image[sr][sc-1]==ogcol)
        {
            getall(image,sr,sc-1,color,ogcol);
        }

        if((sc+1)<image[0].size() && image[sr][sc+1]==ogcol)
        {
            getall(image,sr,sc+1,color,ogcol);
        }

        if((sr-1)>=0 && image[sr-1][sc]==ogcol)
        {
            getall(image,sr-1,sc,color,ogcol);
        }

        if((sr+1)<image.size() && image[sr+1][sc]==ogcol)
        {
            getall(image,sr+1,sc,color,ogcol);
        }





    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


        int ogcol = image[sr][sc];

        if(ogcol==color)
        {
            return image;
        }

        getall(image,sr,sc,color,ogcol);


        return image;
        
    }
};