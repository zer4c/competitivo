#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
#define fore(i, a, b) for(int i = (a); i <(b); i++)
#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<char, int> mp;
typedef priority_queue<int> pq;
const int MOD = 10e7;
const ll INF = 9223372036854775807LL;
/*Te dan un grafo no dirigido simple con N vértices y M aristas. 
  Cada arista conecta dos vértices dados.
  EL objetivo es  determinar Si este grafo es un grafo 
  camino == secuencia lineal.
  */
void dfs(int i, vector<vi>& adj, vi& vis) {
    vis[i] = 1;
    for (int x : adj[i]) {
        if (!vis[x]) {
            dfs(x, adj, vis);
        }
    }
}

signed main(){
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    vi vis(n + 1);
    vi grado(n + 1);
    if(m != n-1){
        cout << "No" << endl;
        return 0;
    }
    forn(i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        grado[a]++;
        grado[b]++;
    }

    int g1 = 0, g2 = 0;
    fore(i, 1, n + 1) {
        if (grado[i] == 1) g1++;
        else if (grado[i] == 2) g2++;
        else if (grado[i] > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    if (g1 != 2 || g1 + g2 != n) {
        cout << "No" << endl;
        return 0;
    }
        
    for (int i = 1; i <= n; i++) {
        if (grado[i] > 0) {
            dfs(i, adj, vis);
            break;
        }
    }
    fore(i, 1, n + 1) {
        if (grado[i] > 0 && !vis[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}