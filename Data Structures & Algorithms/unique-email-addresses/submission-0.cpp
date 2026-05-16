class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> record;
        for(string s:emails)
        {
            string hostname = s.substr(0,s.find('@'));
            hostname = hostname.substr(0,hostname.find('+'));
            hostname.erase(remove(hostname.begin(),hostname.end(),'.'),hostname.end());

            record.insert(hostname + s.substr(s.find('@')));
        }
        return record.size();
    }
};