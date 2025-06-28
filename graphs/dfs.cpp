vector<bool> vis(tam);
void dfs(int node){
    vis[node] = 1;
    for(int x : g[node]){
        if(!vis[x]){
            dfs(x);
        }
    }
}