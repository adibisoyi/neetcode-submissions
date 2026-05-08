class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> result={{}};
        sort(nums.begin(),nums.end());
        int previdx =0;
        int idx =0;

       for(int i=0;i<nums.size();i++)
       {
            idx = (i>=1 && nums[i] == nums[i-1])? previdx : 0;
            previdx = result.size();
            for(int j=idx;j<previdx;j++)
            {
                    vector<int> subset = result[j];
                    subset.push_back(nums[i]);
                    result.push_back(subset);
            }
       } 
       return result;
    }
};
