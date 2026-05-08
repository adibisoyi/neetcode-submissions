class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(auto x:nums)
        {
            freq[x]++;
        }

        for(auto[x,y]:freq)
        {
            if(y>1)
                return true;
            continue;
        }
        return false;
    }
};