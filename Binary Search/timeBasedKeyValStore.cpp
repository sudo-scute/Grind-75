// implementation is main here
class TimeMap {
public:

    unordered_map<string, vector<pair<int,string>> >mapi;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mapi[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // not even the key is present in map
        if (mapi.find(key) == mapi.end()){
            return "";
        }
        // else key present and looking for last occurence of value 
        // binary search
        int s = 0;
        int e = mapi[key].size() - 1 ; // vector instead of timestamp
        int mid = s + (e - s) / 2;
        string ans = "";
        while (s <= e) {
            if (mapi[key][mid].first <= timestamp) {
                ans = mapi[key][mid].second;
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
