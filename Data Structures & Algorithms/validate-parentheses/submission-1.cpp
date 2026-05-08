class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp = {
            {')','('},{']','['},{'}','{'}
        };

        for(auto x:s)
        {
            if(mp.count(x))
            {
                if(!(st.empty()) && st.top()== mp[x])
                    st.pop();
                else
                    return false;
            }
            else
                st.push(x);
        }
        return st.empty();
    }
};
