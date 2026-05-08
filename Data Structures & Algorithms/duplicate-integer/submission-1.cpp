class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto n:nums)
        {
            freq[n]++;
        }
        for(auto [i,count]:freq)
        {
            if(count > 1)
                return true;
            
        }
        return false;
    }
};