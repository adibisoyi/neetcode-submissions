class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> lookup(nums.begin(),nums.end());

        for(int num:nums)
        {
            if(lookup.find(num) == lookup.end())
                continue;
            
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
