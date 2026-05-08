class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        vector<vector<string>> answer;
        for(const string& s: strs)
        {
            string sortstr = s;
            sort(sortstr.begin(),sortstr.end());
            res[sortstr].push_back(s);
        }

        for(auto [x,y]:res)
        {
            answer.push_back(y);
        }
        return answer;
    }
};
