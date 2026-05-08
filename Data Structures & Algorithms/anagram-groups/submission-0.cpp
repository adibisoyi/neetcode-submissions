class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> dict;

        for(auto x: strs)
        {
            string sorteds = x;
            sort(sorteds.begin(),sorteds.end());
            dict[sorteds].push_back(x);
        }
        
        
        vector<vector<string>> res;
        for(auto [x,y]: dict)
        {
            res.push_back(y);
        }
        return res;
        
    }
};
