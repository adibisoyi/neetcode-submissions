class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> lookup(nums.begin(),nums.end());

        int longest=0;

        for(auto num:nums)
        {
            int prev = num-1;
            int next = num+1;
            int length =1;
            while(lookup.count(prev))
            {
                length++;
                prev--;
            }

            while(lookup.count(next))
            {
                length++;
                next++;
            }
            longest = max(longest,length);
        }
        return longest;
    }
};
