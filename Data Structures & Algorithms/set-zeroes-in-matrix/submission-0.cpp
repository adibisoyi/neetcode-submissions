class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<bool> row_vector(row,false);
        vector<bool> col_vector(col,false);

        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(matrix[r][c] == 0)
                {
                    row_vector[r]=true;
                    col_vector[c]=true;
                }
            }
        }
        for(int r=0;r<row;r++)
        {
            for(int c=0;c<col;c++)
            {
                if(row_vector[r]||col_vector[c])
                    matrix[r][c]=0;
            }
        }

    }
};
