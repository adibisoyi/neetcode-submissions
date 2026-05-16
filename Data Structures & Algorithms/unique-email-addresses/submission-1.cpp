class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
       unordered_set<string> record;

       for(string s: emails)
       {
            string email;
            bool after_at = false;
            bool after_plus = false;

            for(char c:s)
            {
                if(c == '@')
                {
                    email += c;
                    after_at= true;   
                }
                else if(after_at)
                {
                    email += c;
                }
                else if(after_plus)
                    continue;

                else if(c == '+')
                    after_plus = true;
                
                else if(c == '.')
                    continue;
                else
                    email += c;

            }
            record.insert(email);
       } 
       return record.size();
    }
};