class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int longest=0;
        unordered_set<int> hashset(nums.begin(),nums.end());

        for(int num:hashset)
        {
            if(hashset.find(num) == hashset.end())
                continue;
            int prev = num-1;
            int next = num+1;
            int length=1;

            while(hashset.count(prev))
            {
                hashset.erase(prev);
                prev--;
                length++;
            }

            while(hashset.count(next))
            {
                hashset.erase(next);
                next++;
                length++;
            }
            longest = max(longest,length);
        }
        return longest;
    }
};
