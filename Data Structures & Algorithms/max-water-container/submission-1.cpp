class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = INT_MIN;

        for(int i=0;i<heights.size();i++)
        {
            for(int j=i+1;j<heights.size();j++)
            {
                int area = abs(j-i)*min(heights[i],heights[j]);
                maxarea = max(maxarea,area);
            }
        }
        return maxarea;
        /*
        int maxarea =0;
        int left=0;
        int right = heights.size()-1;

        while(left<right)
        {
            int area = min(heights[left],heights[right]) * (right-left);

            
            maxarea = max(maxarea,area);

            if(heights[left]<=heights[right])
                left++;
            else
                right--;
        }
        return maxarea;*/
    }
};
