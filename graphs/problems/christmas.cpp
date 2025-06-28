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

/* Hay n árboles de Navidad ubicados en posiciones enteras 
   distintas sobre una línea numérica infinita. 
   Se desea colocar m personas en posiciones también enteras, 
   distintas entre sí y distintas de los árboles.
   El objetivo es:
   Ubicar a las m personas en posiciones enteras no ocupadas,
   de forma que se minimice la suma de las distancias desde 
   cada persona hasta el árbol de Navidad más cercano.
   imput                                
    3 5                      3 5
    0 3 1                    0 3 1
   output
    8                        7
    -1 2 6 4 0 3             5 -2 4 -1 2 
   */ 

signed main(){
    int n, m; cin >>n >> m;
    vi arb(n);
    mp vis;
    queue<pii> cola;
    forn(i,n){
        cin >> arb[i];
        vis[arb[i]] = 1;
    }
    sort(all(arb));
    forn(i,n){
        cola.push({arb[i]-1, 1});
        cola.push({arb[i]+1, 1});
    }
    int dist= 0;
    int vec = 0;
    vi pers;
    while(vec < m && !cola.empty()){
        pii p = cola.front();
        cola.pop();
        if(!vis[p.F]){
            vis[p.F] = 1;
            pers.pb(p.F);
            dist += p.S;
            vec++;
            cola.push({p.F -1,p.S +1});
            cola.push({p.F +1,p.S + 1});
        }
    }

    cout << dist << endl;
    forn(i,m){
        cout  << pers[i] << " ";
    }
    cout << endl;
}