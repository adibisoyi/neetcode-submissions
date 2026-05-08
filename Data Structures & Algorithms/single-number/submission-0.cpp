class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto x:nums)
        {
            freq[x]++;
        }
        for(auto pair:freq)
        {
            if(pair.second == 1)
                return pair.first;
            continue;
        }
        return 0;
    }
};
