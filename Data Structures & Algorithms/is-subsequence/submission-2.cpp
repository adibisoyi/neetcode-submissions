class Solution {
private:
    bool recurse(string s,string t,int i,int j)
    {
        if(i==s.length())
            return true;
        if(j == t.length())
            return false;
        if(s[i] == t[j])
            return recurse(s,t,i+1,j+1);
        
        return recurse(s,t,i,j+1);
    }
public:
    bool isSubsequence(string s, string t) {
        return recurse(s,t,0,0);
    }
};