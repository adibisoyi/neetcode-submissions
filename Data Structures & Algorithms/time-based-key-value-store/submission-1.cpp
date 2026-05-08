class TimeMap {
    private:
        unordered_map<string,vector<pair<int,string>>> keystore;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
      keystore[key].emplace_back(timestamp,value);  
    }
    
    string get(string key, int timestamp) {
        auto& value = keystore[key];
        int left =0 ,right = value.size()-1;
        string res = "";

        while(left <= right)
        {
            int mid = left +(right-left)/2;

            if(value[mid].first <= timestamp)
            {
                res = value[mid].second;
                left = mid+1;
            }
            else
                right=mid-1;
        }
        return res;
    }
};
