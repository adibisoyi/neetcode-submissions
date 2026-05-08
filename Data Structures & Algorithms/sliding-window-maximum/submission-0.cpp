class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int maxelem=0;
        vector<int> res;
        for(int i=0;i+k<=nums.size();i++)
        {
                maxelem = *max_element(nums.begin()+i,nums.begin()+(i+k));
                res.push_back(maxelem);
            
        }
        return res;
    }
};
