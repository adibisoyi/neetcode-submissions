class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s: strs)
        {
            ans += s + '/';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> dec_string;
        string temp = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] != '/')
                temp += s[i];
            else
                {
                    dec_string.push_back(temp);
                    temp = "";
                }

        }
        return dec_string;
    }
};
