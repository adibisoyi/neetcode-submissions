class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char,int> records;
        unordered_map<char,int> recordt;

        for(int i=0;i<s.length();i++)
        {
            records[s[i]]++;
            recordt[t[i]]++;
        }

        return records == recordt ? true:false;
    }
};
