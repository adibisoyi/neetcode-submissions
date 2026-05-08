class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,mlength=0;
        unordered_map<char,int> position;
        for(int right=0;right<s.length();right++)
        {
            if(position.find(s[right])!=position.end())
                left = max(left,position[s[right]]+1);
            
            position[s[right]] = right;

            mlength = max(mlength,right-left+1);
        }
        return mlength;
    }
};
