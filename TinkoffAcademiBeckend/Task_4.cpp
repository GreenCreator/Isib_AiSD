#include <iostream>
#include <queue>
#include <set>

struct State {
    std::vector<int> positions;
    int moves;
};

int FindPath(std::vector<int> &init, std::vector<std::pair<int, int>> &tracks, int n, int m) {
    std::queue<State> q;
    std::set<std::vector<int>> visited;
    q.push({init, 0});
    visited.insert(init);

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        bool connected = true;
        for (int i = 0; i < m - 1; ++i) {
            if (current.positions[i] > current.positions[i + 1] ||
                current.positions[i] + (tracks[i].second - tracks[i].first) < current.positions[i + 1]) {
                connected = false;
                break;
            }
        }

        if (connected) {
            return current.moves;
        }

        for (int i = 0; i < m; ++i) {
            if (current.positions[i] > 1) { // Move left
                std::vector<int> new_positions = current.positions;
                --new_positions[i];
                if (visited.find(new_positions) == visited.end()) {
                    q.push({new_positions, current.moves + 1});
                    visited.insert(new_positions);
                }
            }
            if (current.positions[i] + (tracks[i].second - tracks[i].first) < n) { // Move right
                std::vector<int> new_positions = current.positions;
                ++new_positions[i];
                if (visited.find(new_positions) == visited.end()) {
                    q.push({new_positions, current.moves + 1});
                    visited.insert(new_positions);
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> tracks(m);

    for (int i = 0; i < m; ++i) {
        int s, t;
        std::cin >> s >> t;
        tracks[i] = {s, t};
    }

    std::vector<int> init(m);
    for (int i = 0; i < m; ++i) {
        init[i] = tracks[i].first;
    }

    std::cout << FindPath(init, tracks, n, m);

    return 0;
}
