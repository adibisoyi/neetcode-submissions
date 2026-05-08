class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length() != t.length())
        return false;
      unordered_map<char,int> freq;

      for(auto x:s)
      {
        freq[x]++;
      }  

      for(int i=0;i<t.length();i++)
      {
        if(freq.find(t[i]) != freq.end() && freq[t[i]]!=0)
            freq[t[i]]--;
        else
            return false;
        
      }
      return true;
    }
};
