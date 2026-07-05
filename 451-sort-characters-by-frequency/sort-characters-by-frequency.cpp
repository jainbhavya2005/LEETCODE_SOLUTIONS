class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(char x:s){
            m[x]++;
        }
         string  ans="";
        vector<pair<int,char>>v;
        for(auto it:m){
          v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].first;j++){
            ans+=v[i].second;}
        }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};