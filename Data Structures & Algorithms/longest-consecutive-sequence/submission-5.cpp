class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_set<int> lookup(nums.begin(),nums.end());
        int longest=1;
        for(auto num:nums)
        {
            if(!lookup.count(num-1))
            {
                int cur = num,length=1;
                while(lookup.count(cur+1))
                {
                    cur++;
                    length++;
                }
                longest=max(longest,length);
            }
        }
        return longest;
    }
};
