#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;

    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

int kruskal(int m, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    UnionFind uf(m);

    int totalCost = 0;
    for (const Edge& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unite(edge.u, edge.v);
            totalCost += edge.w;
        }
    }

    return totalCost;
}

int main() {
    int m, n;
    while (cin >> m >> n && (m != 0 || n != 0)) {
        vector<Edge> edges;
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.emplace_back(x, y, z);
        }

        int originalCost = 0;
        for (const Edge& edge : edges) {
            originalCost += edge.w;
        }

        int mstCost = kruskal(m, edges);

        cout << originalCost - mstCost << endl;
    }

    return 0;
}