class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto x : words) {
            m[x]++;
        }
        // map->(string,frequency)
        vector<pair<int, string>> v;
        // vector->(frequency,string)
        for (auto it : m) {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(), v.end(),
             [](pair<int, string>& a, pair<int, string>& b) {
                 if (a.first == b.first)
                     return a.second < b.second;      // lexicographically smaller first
                 return a.first > b.first; // higher frequency first
             });
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};