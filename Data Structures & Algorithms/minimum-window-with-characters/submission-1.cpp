class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty())
            return "";

        unordered_map<char,int> countT;
        for(auto c:t)
            countT[c]++;

        
        int reslen = INT_MAX;
        pair<int,int> res = {-1,-1};

        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int> countS;
            for(int j=i;j<s.length();j++)
            {
                countS[s[j]]++;
            
            bool flag=true;

            for(auto [c,cnt]:countT)
            {
                if(countS[c]<cnt)
                {
                    flag=false;
                    break;
                }
            }

            if(flag && (j-i+1)<reslen)
            {
                reslen =(j-i+1);
                res ={i,j};
            }
            }
        }
        return reslen == INT_MAX ? "" : s.substr(res.first,reslen);
    }
};
