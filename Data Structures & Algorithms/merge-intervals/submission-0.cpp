class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int,int> mp;

        for(auto interval:intervals)
        {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }

        vector<vector<int>> res;
        vector<int> interval;
        int overall_count=0;

        for(auto [i,count]:mp)
        {
            if(interval.empty())
                interval.push_back(i);
            
            overall_count += count;

            if(overall_count == 0)
            {
                interval.push_back(i);
                res.push_back(interval);
                interval.clear();
            }
        }
        return res;
    }
};
