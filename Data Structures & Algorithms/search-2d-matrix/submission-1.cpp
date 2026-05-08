class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size(),COL=matrix[0].size();

        int left=0,right= ROW*COL -1;

        while(left<=right)
        {
            int mid= left+(right-left)/2;
            int row = mid/COL;
            int col = mid%COL;

            if(target  > matrix[row][col])
                left=mid+1;
            else if(target < matrix[row][col])
                right = mid-1;
            else
                return true;
        }
        return false;
    }
};
