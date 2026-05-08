class Solution {
public:
    string minWindow(string s, string t) {
        /*if(t.empty())
            return "";

        unordered_map<char,int> countT;
        for(auto c:t)
        {
            countT[c]++;
        }

        pair<int,int> res = {-1,-1};
        int reslen =INT_MAX;

        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int> countS;
            for(int j=i;j<s.length();j++)
            {
                countS[s[j]]++;

                bool flag =true;

                for(auto [c,cnt]:countT)
                {
                    if(countS[c]<cnt)
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag && (j-i+1) < reslen)
                {
                    reslen = (j-i+1);
                    res={i,j};
                }
            }
        }
        return reslen == INT_MAX ? "": s.substr(res.first,reslen);*/


        if(t.empty())
            return "";
        
        unordered_map<char,int> countT,window;
        for(auto s:t)
            countT[s]++;

        int reslen = INT_MAX;
        pair<int,int> res = {-1,-1};
        int i=0;
        int have =0,need = countT.size();

        for(int j=0;j<s.length();j++)
        {   
            char c = s[j];
            window[s[j]]++;

            if(countT.count(c) && window[c]==countT[c])
                have++;
            
            while(have==need)
            {
                if((j-i+1) < reslen)
                {
                    reslen = j-i+1;
                    res = {i,j};
                }

                window[s[i]]--;
                if(countT.count(s[i]) && window[s[i]] < countT[s[i]])
                {
                    have--;
                }
                i++;
            }

        }
        return reslen == INT_MAX ? "" : s.substr(res.first,reslen);
    }
};
