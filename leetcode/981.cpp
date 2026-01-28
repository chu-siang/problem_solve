class TimeMap {
public:
unordered_map<string,map<int,string>>mp;
    TimeMap() {
    }
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    string get(string key, int timestamp) {
        if(mp[key].count())
        auto i = mp[key].lower_bound(timestamp);
        return i->second;
    }
};
/*
unordered_map<string, map<int, string>> m;
void set(string key, string value, int timestamp) {
  m[key].insert({ timestamp, value });
}
string get(string key, int timestamp) {
  auto it = m[key].upper_bound(timestamp);
  return it == m[key].begin() ? "" : prev(it)->second;
}
*/

/*
Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"

*/

/*
unordered_map<string, vector<pair<int, string>>> m;
void set(string key, string value, int timestamp) {
  m[key].push_back({ timestamp, value });
}
string get(string key, int timestamp) {
  auto it = upper_bound(begin(m[key]), end(m[key]), pair<int, string>(timestamp, ""), [](
    const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });
  return it == m[key].begin() ? "" : prev(it)->second;
}
*/

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */