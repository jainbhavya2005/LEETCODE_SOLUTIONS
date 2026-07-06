class Solution {
    bool check(int i,vector<int>&color,vector<vector<int>>& graph){
    color[i]=0;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:graph[node]){
            if(color[it]!=-1){
                if(color[it]==color[node]) return false;
            }
            else{
                color[it]=!color[node];
                q.push(it);
            }
        }
    }
    return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
            {
                if(check(i,color,graph)==false){ return false;}
            }
        }
   
   return true;
    }
};