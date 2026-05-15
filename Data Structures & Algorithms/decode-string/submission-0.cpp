class Solution {
private:    
    string recurse(string& s, int& i)
    {
        string res;
        int k=0;

        while(i<s.length())
        {
            char c = s[i];

            if(isdigit(c))
                k = k*10+(c-'0');

            else if(c=='[')
                {
                    i++;
                    string subres = recurse(s,i);
                    while(k-- > 0)
                        res += subres;
                    k=0;
                }
            else if(c == ']')
            {
                return res;
            }
            else
                res += c;
            
            i++;
        }
        return res;
    }
public:
    string decodeString(string s) {
       int i=0;
       return recurse(s,i); 
    }
};