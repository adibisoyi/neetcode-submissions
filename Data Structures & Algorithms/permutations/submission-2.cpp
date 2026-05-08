class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> cur,vector<bool> picked,vector<int>& nums)
    {
        if(cur.size()==nums.size())
        {
            res.push_back(cur);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(!picked[i])
            {
                cur.push_back(nums[i]);
                picked[i]=true;
                dfs(cur,picked,nums);
                cur.pop_back();
                picked[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> picked(nums.size(),false);
        dfs({},picked,nums);
        return res;

    }
};
