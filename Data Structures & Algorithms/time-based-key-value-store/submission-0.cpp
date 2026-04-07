class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
        return ;
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto &vec = mp[key];
        auto itr = lower_bound(vec.begin(), vec.end(), make_pair(timestamp, string("")));
        if (itr != vec.end() && itr -> first == timestamp) return itr -> second;
        if (itr == vec.begin()) return "";

        --itr;
        return itr ->second;

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */