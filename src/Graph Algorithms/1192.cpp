#include <bits/stdc++.h>
using namespace std;
// #define int long long

string grid[1000];
int n, m;
bool visited[1000][1000] = {0};

int moves[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
bool boundCheck(int r, int c) {
    if (r < 0 || r >= n) {
        return false;
    }

    if (c < 0 || c >= m) {
        return false;
    }

    if (grid[r][c] == '#') {
        return false;
    }

    return true;
}

void BFS(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty()) {
        int R = q.front().first;
        int C = q.front().second;
        for (int i = 0; i < 4; i++) { // adjacent to (r, c)
            if (boundCheck(R + moves[0][i], C + moves[1][i]) && !visited[R + moves[0][i]][C + moves[1][i]]) {
                visited[R + moves[0][i]][C + moves[1][i]] = true;
                q.push({R + moves[0][i], C + moves[1][i]});
            }
        }
        q.pop();
    }
}

int32_t main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                continue;
            }

            if (!visited[i][j]) {
                ans++;
                BFS(i, j);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}