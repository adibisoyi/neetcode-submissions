class Solution {
private:
    vector<vector<string>> result;
    bool ispalindrome(string& s, int l, int r)
    {
        while(l<r)
        {
            if(s[l] != s[r])
                return false;
            
            l++;
            r--;
        }
        return true;
    }

    void dfs(int i,int j, string& s, vector<string>& part)
    {
        if(j >= s.size())
        {
            if(j==i)
                result.push_back(part);
        
            return;
        }

        if(ispalindrome(s,i,j))
        {
            part.push_back(s.substr(i,j-i+1));
            dfs(j+1,j+1,s,part);
            part.pop_back();
        }

        dfs(i,j+1,s,part);
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0,0,s,part);
        return result;
    }
};
