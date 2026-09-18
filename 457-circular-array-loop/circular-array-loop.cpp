class Solution {
public:bool dfs(int idx,vector<int>&vis,vector<vector<int>>&adj){
    vis[idx]=1;
    for(int i=0;i<adj[idx].size();i++){
if(vis[adj[idx][i]]==1)return true;
if(vis[adj[idx][i]]==0)if( dfs(adj[idx][i],vis,adj))return 1;
    }
    vis[idx]=2;
    return 0;
}
    bool circularArrayLoop(vector<int>&v) {
        int n=v.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
int idx=((i+v[i])%n+n)%n;
if(idx!=i&&v[i]*v[idx]>0){

adj[i].push_back(idx);}

        }

        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
if(vis[i]==0)if(dfs(i,vis,adj))return 1;
        }
        return 0;
    }
};