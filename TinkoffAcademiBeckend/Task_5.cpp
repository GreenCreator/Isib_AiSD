#include <iostream>
#include <vector>
#include <queue>

std::vector<int> topologicalSort(std::vector<std::vector<int>> &graph, std::vector<int> &in_degree) {
    int N = graph.size() - 1;
    std::vector<int> result;
    std::queue<int> q;

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor: graph[node]) {
            if (--in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> graph(N + 1);
    std::vector<int> in_degree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int A, B;
        std::cin >> A >> B;
        graph[A].push_back(B);
        ++in_degree[B];
    }

    auto result = topologicalSort(graph, in_degree);

    if (result.empty()) {
        std::cout << "No";
    } else {
        std::cout << "Yes" << std::endl;
        for (int i = 0; i < N; ++i) {
            std::cout << result[i] << " ";
        }
    }

    return 0;
}
