class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(const string& w : details)
        {
            if(stoi(w.substr(11,2))>60)
                res++;
        }
        return res;
    }
};