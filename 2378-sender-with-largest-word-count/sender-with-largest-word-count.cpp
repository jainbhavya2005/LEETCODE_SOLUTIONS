class Solution {
    int wordcount( string x){
        int count=0;
        for(int i=0;i<x.size();i++){
            if(x[i]==' '){
                count++;
            }
        }
    return count+1;
    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>m;
       for( int i=0;i<senders.size();i++){
        m[senders[i]]+=wordcount(messages[i]);
       }

vector<pair<int,string>>v;
for(auto it:m){
    v.push_back({it.second,it.first});
}
sort(v.begin(),v.end(),[](pair<int,string> &a, pair<int,string> &b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first > b.first;
        });
    
    return v[0].second;
    }
};