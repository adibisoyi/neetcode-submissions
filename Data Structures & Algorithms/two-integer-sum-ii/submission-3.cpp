class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
/*  
      for(int i=0;i<nums.size();i++)
      { 
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[i]+nums[j]==target)
            {
                vector<int> answer= {i+1,j+1};
                return answer;
            }
        }
      }
      return {};
      
      */
      
      
      
      
        unordered_map<int,int> maap;

        for(int i=0;i<nums.size();i++)
        {
            if(maap.find(target-nums[i]) != maap.end())
                return{maap[target-nums[i]],i+1};
            maap[nums[i]] = i+1;
        }

        return {};
    }
};
