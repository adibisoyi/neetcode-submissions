class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> dict;

        for(string& word : strs)
        {
            vector<int> count(26,0);

            for(char c: word)
                count[c-'a']++;

            string res = to_string(count[0]);
            for(int i=1;i<26;i++)
            {
                res += ','+to_string(count[i]);
            }

            dict[res].push_back(word);
        }

        vector<vector<string>> answer;
        for(auto [k,v]:dict)
        {
            answer.push_back(v);
        }
        return answer;
    }
};
