class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       

    /*   for(int num:nums)
       {
            int res = abs(num)-1;
            if(nums[res] < 0)
                return abs(num);
            nums[res] *= -1;
       } 
       return -1;*/

    int slow=nums[0],fast =nums[nums[0]];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    
    fast=0;
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
    }
};
