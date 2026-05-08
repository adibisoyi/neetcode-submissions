class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);

        for(auto n: nums)
            count[n]++;
        
        for(auto& pair : count)
        {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for(int i = freq.size()-1;i>0;i--)
        {
            for(int n:freq[i])
            {
                res.push_back(n);
                if(res.size() == k)
                    return res;
            }
        }
        return res;*/
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;

        for(auto x:nums)
            freq[x]++;

        for(auto& entry:freq)
        {
            heap.push({entry.second,entry.first});
            if(heap.size()>k)
                heap.pop();
        }

        vector<int> res;
        for(int i=0;i<k;i++)
        {
            res.push_back(heap.top().second);
            heap.pop();
        }

        return res;
    }
};
