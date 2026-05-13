class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> res(26,0);

        for(char c:s)
        {
            res[c-'a']++;
        }
        string answer;
        for(char c:order)
        {
            
            while(res[c-'a'] > 0)
            {
                answer += c;
                res[c-'a']--;
            }
        }

        for(int i=0;i<26;i++)
        {
           
            while(res[i]>0)
            {
                answer += 'a'+i;;
                res[i]--;
            }
        }
        return answer;
    }
};