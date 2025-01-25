bool isBipartiteBFS(vector<vector<int>>& graph, vector<int>& color, int source) {
    queue<int> q;
    q.push(source);
    color[source] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto child : graph[node]) {
            if (color[child] == -1) {
                color[child] = !color[node];
                q.push(child);
            } else if (color[child] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), -1);

    for (int i = 0; i < graph.size(); i++) {
        if (color[i] != -1) continue;
        if (!isBipartiteBFS(graph, color, i)) return false;
    }

    return true;
}
