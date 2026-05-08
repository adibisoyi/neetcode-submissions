class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen =0 ;

        for(int i=0;i<s.length();i++)
        {
            unordered_set<char> record;
            for(int j=i;j<s.length();j++)
            {
                if(record.find(s[j]) != record.end())
                {
                    break;
                }
                record.insert(s[j]);
            }
            maxlen = max(maxlen,(int)record.size());
        }
        return maxlen;
    }
};
