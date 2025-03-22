// @DSU by RANK
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int child) {
        if (parent[child] == child) return child;
        return parent[child] = findParent(parent[child]);
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void connect(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
};

// @DSU by SIZE
class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int child) {
        if (parent[child] == child) return child;
        return parent[child] = findParent(parent[child]);
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void connect(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u != v) {
            if (size[u] > size[v]) {
                parent[v] = u;
                size[u] += size[v];
            } else {
                parent[u] = v;
                size[v] += size[u];
            }
        }
    }

    int getSize(int node) {
        return size[findParent(node)];
    }
};

// int main() {
//     DSU dsu(8);
//     dsu.connect(1,3);
//     dsu.connect(2,4);
//     dsu.connect(7,8);
//     dsu.connect(2,3);

//     if (dsu.isConnected(1, 4)) {
//         cout << "1-4 connected" << endl;
//     } else {
//         cout << "1-4 not connected" << endl;
//     }
//     if (dsu.isConnected(1, 7)) {
//         cout << "1-7 connected" << endl;
//     } else {
//         cout << "1-7 not connected" << endl;
//     }
//     return 0;
// }
