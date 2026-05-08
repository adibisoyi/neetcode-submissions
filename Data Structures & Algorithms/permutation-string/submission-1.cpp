class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        /*sort(s1.begin(),s1.end());
        for(int i=0;i<s2.length();i++)
        {
            for(int j=i;j<s2.length();j++)
            {
                string sbstr = s2.substr(i,j-i+1);
                sort(sbstr.begin(),sbstr.end());
                if(sbstr == s1)
                    return true;
            }
        }
        return false;*/
        
        if(s1.length()>s2.length())
            return false;
        vector<int> freq1(26,0),freq2(26,0);

        for(int i=0;i<s1.length();i++)
        {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        if(freq1 == freq2)
            return true;
        int window = s1.length();
        for(int i=window;i<s2.length();i++)
        {
            freq2[s2[i]-'a']++;
            freq2[s2[i-window]-'a']--;

            if(freq1 == freq2)
                return true;
        }
        return false;
        
    }
};
