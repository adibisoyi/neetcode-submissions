class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num:nums)
        {
            freq[num]++;
        }

        for(auto [i,j]:freq)
        {
            if(j > 1)
                return true;
        }
        return false;
    }
};