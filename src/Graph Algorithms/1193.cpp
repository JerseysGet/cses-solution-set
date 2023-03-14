#include <bits/stdc++.h>
using namespace std;
// #define int long long

string grid[1000];
int n, m;
bool visited[1000][1000] = {0};
int targetR, targetC;
int moves[2][4] = {{0, 0, -1, 1}, {-1, 1, 0, 0}};
char moveChar[4] = {'L', 'R', 'U', 'D'}; 
unordered_map<int, pair<int, int>> previous;
char paths[1000][1000];
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


queue<pair<int, int>> q;
void BFS(int r, int c) {
    q.push({r, c});
    paths[r][c];
    visited[r][c] = true;
    while (!q.empty()) {
        int currR = q.front().first;
        int currC = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newR = currR + moves[0][i];
            int newC = currC + moves[1][i];
            if (boundCheck(newR, newC) && !visited[newR][newC]) {
                visited[newR][newC] = true;
                q.push({newR, newC});
                paths[newR][newC] = moveChar[i];
                previous[1000*newR + newC] = {currR, currC};
                if (newR == targetR && newC == targetC) {
                    return;
                }
            }
        }
    }
}


int32_t main() {
    cin >> n >> m;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
            }

            if (grid[i][j] == 'B') {
                targetR = i;
                targetC = j;
            }
        }
    }

    BFS(start.first, start.second);
    if (visited[targetR][targetC]) {
        cout << "YES\n";
        string path = "";
        pair<int, int> current = {targetR, targetC};
        while (current != start) {
            path = paths[current.first][current.second] + path;
            current = previous[1000*current.first + current.second];
        }
        cout << path.length() << "\n" << path << "\n";
    } else {
        cout << "NO\n";
    }
}