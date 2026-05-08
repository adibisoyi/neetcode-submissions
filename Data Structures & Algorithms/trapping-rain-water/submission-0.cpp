class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())
            return 0;
        int res=0;

        for(int i=0;i<height.size();i++)
        {
            int leftmax=height[i];
            int rightmax=height[i];
            for(int j=0;j<i;j++)
            {
                leftmax = max(leftmax,height[j]);
            }
            for(int j=i+1;j<height.size();j++)
            {
                rightmax = max(rightmax,height[j]);
            }

            res += min(leftmax,rightmax)-height[i];
        }
        return res;
    }
};
