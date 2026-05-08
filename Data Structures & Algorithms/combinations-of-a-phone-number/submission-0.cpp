class Solution {
private:
    vector<string> result;
    vector<string> digittochar = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void backtrack(int i,string curstr,string& digits)
    {
        if(curstr.size() == digits.size())
        {
            result.push_back(curstr);
            return;
        }

        string chars = digittochar[digits[i]-'0'];
        for(char c:chars)
        {
            backtrack(i+1,curstr+c,digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return result;
        backtrack(0,"",digits);
        return result;
    }
};
