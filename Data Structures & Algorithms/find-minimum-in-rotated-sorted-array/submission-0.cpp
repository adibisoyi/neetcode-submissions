class Solution {
public:
    int findMin(vector<int> &nums) {
      int l=0,r=nums.size()-1;
      int minval = INT_MAX;
      while(l<=r)
      {
        while(nums[l] < nums[r])
        {
            minval = min(minval,nums[l]);
            break;
        }
        int mid = l + (r-l)/2;
        minval = min(minval,nums[mid]);

        if(nums[mid] >= nums[l])
            l=mid+1;
        else
            r=mid-1;
      }
      return minval;
    }
};
