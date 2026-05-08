class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        /*int maxelem=0;
        vector<int> res;
        for(int i=0;i+k<=nums.size();i++)
        {
                maxelem = *max_element(nums.begin()+i,nums.begin()+(i+k));
                res.push_back(maxelem);
            
        }
        return res;*/

        deque<int> dq;
        vector<int> res;

        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k)
                dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
