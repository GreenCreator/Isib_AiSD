#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int v, const std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::vector<int> &component) {
    visited[v] = true;
    component.push_back(v);
    for (int u: graph[v]) {
        if (!visited[u]) {
            dfs(u, graph, visited, component);
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<bool> visited(N + 1, false);
    std::vector<int> component;

    dfs(1, graph, visited, component);

    sort(component.begin(), component.end());

    std::cout << component.size() << std::endl;

    for (int v: component) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
