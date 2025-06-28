#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]); // path compression
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false; // ya están unidos

        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while (q--) {
        string tipo;
        int a, b;
        cin >> tipo >> a >> b;

        if (tipo == "union") {
            dsu.unite(a, b);
        } else if (tipo == "connected") {
            cout << (dsu.connected(a, b) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
