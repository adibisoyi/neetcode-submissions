class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int size = nums.size();

       for(int i=0;i<=size;i++)
       {
            if(std::find(nums.begin(),nums.end(),i)!= nums.end())
                continue;
            else
                return i;
       } 
       return -1;
    }
};
