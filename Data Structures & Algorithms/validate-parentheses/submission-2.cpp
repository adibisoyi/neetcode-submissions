class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c:s)
        {
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else
            {   
                 if(st.empty())
                    return false;
            
            char topelement = st.top();
            st.pop();

            if((c==')' && topelement != '(') ||
               (c=='}' && topelement != '{') ||
               (c==']' && topelement != '['))
                 return false;
            }
        }
        return st.empty();
    }
};
