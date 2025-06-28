vector<int> bfs(vector<vector<int>>& g, int v){
    vector<int> dis(g.size(),-1);
    queue<int> q;
    dis[v] = 0;
    q.push(v);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int x : g[node]){
            if(dis[x] == -1){
                dis[x] = dis[node] +1;
                q.push(x);
            }
        }
    }
}