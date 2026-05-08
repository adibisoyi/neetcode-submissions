class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto c:strs)
        {
            ans += c+'~';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string temp = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != '~')
                temp += s[i];
            else
            {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
};
