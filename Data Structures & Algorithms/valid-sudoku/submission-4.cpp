class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       /* unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c] =='.')
                    continue;
                int value = board[r][c];
                int boxid = (r/3)*3 +(c/3);

                if(row[r].count(value) || col[c].count(value) || box[boxid].count(value))
                    return false;
                
                row[r].insert(value);
                col[c].insert(value);
                box[boxid].insert(value);
            }
        }
        return true;*/

        for(int row=0;row<9;row++)
        {
            unordered_set<char> seen;
            for(int i=0;i<9;i++)
            {
                if(board[row][i] =='.')
                    continue;
                if(seen.count(board[row][i]))
                    return false;
                seen.insert(board[row][i]);
            }
        }

        for(int col=0;col<9;col++)
        {
            unordered_set<char> seen;
            for(int i=0;i<9;i++)
            {
                if(board[i][col] =='.')
                    continue;
                if(seen.count(board[i][col]))
                    return false;
                seen.insert(board[i][col]);
            }
        }

        for(int square =0;square<9;square++)
        {
            unordered_set<char> seen;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    int row = (square/3)*3+i;
                    int col = (square%3)*3+j;

                    if(board[row][col] == '.')
                    {
                        continue;
                    }
                    if(seen.count(board[row][col]))
                        return false;
                    seen.insert(board[row][col]);
                }
            }   
        }
        return true;
    }
};
