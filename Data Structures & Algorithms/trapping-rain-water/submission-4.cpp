class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())
            return 0;
        int res=0;
        int n= height.size();

        int l= 0,r=n-1;
        int leftmax = height[l],rightmax = height[r];

        while(l<r)
        {
            if(leftmax<rightmax)
            {
                l++;
                leftmax = max(leftmax,height[l]);
                res+= leftmax - height[l];
            }

            else
            {
                r--;
                rightmax = max(rightmax,height[r]);
                res+= rightmax-height[r];
            }
        }
        return res;
        /*vector<int> leftmax(n);
        vector<int> rightmax(n);
        
        leftmax[0] = height[0];
        for(int i=1;i<n;i++)
        {
            leftmax[i] = max(leftmax[i-1],height[i]);
        }

        rightmax[n-1] = height[n-1];
        for(int j=n-2;j>=0;j--)
        {
            rightmax[j] = max(rightmax[j+1],height[j]);
        }

        for(int i=0;i<n;i++)
        {
            res += min(leftmax[i],rightmax[i])-height[i];
        }
        return res;*/

        /*for(int i=0;i<height.size();i++)
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
        return res;*/
    }
};
