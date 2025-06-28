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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef map<char, int> mp;
typedef priority_queue<int> pq;
const int MOD = 1000000007;
const ll INF = 9223372036854775807LL;
/*A partir del grafo “copito de nieve” dado, 
  identificar cuántos vértices están conectados 
  directamente al centro (x) y cuántos vértices 
  están conectados a cada uno de esos vértices (y).*/
signed main(){
    int  t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vector<vector<int>> adj(n+1);
        vi vis(n+1);
        fore(i,1,m+1){
            int a,b; cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        
        int centro = -1;
        fore(i, 1, n+1) {
            if(sz(adj[i]) > 1){
                bool esCentro = true;
                for(int x : adj[i]){
                    if(sz(adj[x]) == 1){
                        esCentro = false;
                        break;
                    }
                }
                if(esCentro){
                    centro = i;
                    break;
                }
            }
        }
        cout << sz(adj[centro]) << " " << sz(adj[adj[centro][0]]) -1 << endl;
    }
    return 0;
}
