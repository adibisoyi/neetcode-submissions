class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> freq;
      int l=0,res=0;

      for(int r=0;r<s.length();r++)
      {
        if(freq.find(s[r]) != freq.end())
            l = max(freq[s[r]]+1,l);
        freq[s[r]]=r;
        res = max(res,r-l+1);
      }
      return res;
    }
};
