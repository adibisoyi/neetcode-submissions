class Solution {
public:
    string minRemoveToMakeValid(string s) {
      int bcount=0;
      vector<char> arr(s.begin(),s.end());

      for(int i=0;i<s.size();i++)
      {
        if(s[i] == '(')
            bcount++;
        else if(s[i] == ')' && bcount >0)
            bcount--;
        else if(s[i] == ')')
            arr[i]='\0';
      }
        string res;
      for(int i=arr.size()-1;i>=0;i--)
      {
        if(arr[i]=='(' && bcount>0)
            bcount--;
        else if(arr[i] != '\0')
            res.push_back(arr[i]);
      }
        reverse(res.begin(),res.end());
      return res;
    }
};
