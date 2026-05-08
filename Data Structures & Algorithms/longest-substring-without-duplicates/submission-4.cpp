class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       /* int maxlen =0 ;

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
        return maxlen;*/


        unordered_map<char,int> mp;
        int l=0,maxlen=0;

        for(int r=0;r<s.length();r++)
        {
            if(mp.find(s[r]) != mp.end())
            {
                l=max(mp[s[r]]+1,l);
            }
            mp[s[r]]=r;
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
