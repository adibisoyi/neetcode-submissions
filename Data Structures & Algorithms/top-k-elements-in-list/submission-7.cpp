class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto n:nums)
        {
          freq[n]++;
        }

        vector<pair<int,int>> bucket;
        for(const auto& p:freq)
        {
          bucket.push_back({p.second,p.first});
        }
        sort(bucket.rbegin(),bucket.rend());
        vector<int> res;
        for(int i=0;i<k;i++)
        {
          res.push_back(bucket[i].second);
        }
        return res;
    }
};
