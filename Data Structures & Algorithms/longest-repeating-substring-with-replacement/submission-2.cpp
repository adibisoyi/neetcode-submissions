class Solution {
public:
    int characterReplacement(string s, int k) {
        /*int maxlen=0;
        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int> freq;
            int maxfreq =0;
            for(int j=i;j<s.length();j++)
            {
                freq[s[j]]++;
                maxfreq = max(maxfreq,freq[s[j]]);
                if((j-i+1)-maxfreq <= k)
                {
                    maxlen = max(maxlen,(j-i+1));
                }
            }
        }
        return maxlen;*/
    
        int maxlen =0 ;
        unordered_set<char> charset(s.begin(),s.end());

        for(char c:charset)
        {
            int l=0,count=0;
            for(int r=0;r<s.length();r++)
            {
                if(s[r] == c)
                    count++;
                while((r-l+1)-count >k)
                {
                    if(s[l] == c)
                        count--;
                    l++;
                }
                maxlen = max(maxlen,(r-l+1));

            }
        }
        return maxlen;
    
    }
};
