class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c:s)
        {
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if(st.empty())
                    return false;
                char topelem = st.top();
                st.pop();

                if((c==')' && topelem != '(')||(c=='}' && topelem != '{')||(c==']' && topelem != '['))
                    return false;
            }
        }
        return st.empty();
    }
};
