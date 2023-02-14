#include <bits/stdc++.h>
using namespace std;
#define int long long

#define L 0
#define R 1
#define U 2
#define D 3

#define SIZE 20

bool isBlocked(set<pair<int, int>>& visited) {
    for (int i = 1; i <= 6; i++) {
        for (int r = i; r <= 6; r++) {
            if (visited.count(pair<int, int> {r, r-i}) == 0) {
                return false;
            }
        }
    }
    return true;
}

bool isBounded(pair<int, int> position, set<pair<int, int>>& visited) {
    return (position.first <= 6 && position.first >= 0 && position.second >= 0 && position.second <= 6 && (visited.count(position) == 0));
}

pair<int, int> move(pair<int, int> position, int move) {
    if (move == U) {
        return {position.first - 1, position.second};
    } else if (move == D) {
        return {position.first + 1, position.second};
    } else if (move == R) {
        return {position.first, position.second + 1};
    } else if (move == L) {
        return {position.first, position.second - 1};
    }
}
// ????????????????????????????????????????????????
int ct = 0;
void fill(string& grid, pair<int, int>& position, int (&moves)[4], int index, set<pair<int, int>>& visited) {

    if (index == SIZE) {
        if (position == pair<int, int> {6, 0}) {
            ct++;
        }
        if (ct == 88418){
            cout << "LUL";
        }
        return;
    }

    if (position == pair<int, int> {6, 0}) {
        return;
    }

    if (visited.count(pair<int, int> {5, 0}) == 1 && visited.count(pair<int, int> {6, 1}) == 1) {
        return;
    }

    if (isBlocked(visited)) {
        return;
    }

    if (grid[index] == '?') {
        if (isBounded(move(position, D), visited)) {
            position = move(position, D);
            grid[index] = 'D';
            moves[D]++;
            visited.insert(position);
            fill(grid, position, moves, index+1, visited);
            visited.erase(position);
            position = move(position, U);
            grid[index] = '?';
            moves[D]--;
        }

        if (isBounded(move(position, U), visited)) {
            position = move(position, U);
            grid[index] = 'U';
            moves[U]++;
            visited.insert(position);
            fill(grid, position, moves, index+1, visited);
            visited.erase(position);
            position = move(position, D);
            grid[index] = '?';
            moves[U]--;
        }

        if (isBounded(move(position, L), visited)) {
            position = move(position, L);
            grid[index] = 'L';
            moves[L]++;
            visited.insert(position);
            fill(grid, position, moves, index+1, visited);
            visited.erase(position);
            position = move(position, R);
            grid[index] = '?';
            moves[L]--;
        }

        if (isBounded(move(position, R), visited)) {
            position = move(position, R);
            grid[index] = 'R';
            moves[R]++;
            visited.insert(position);
            fill(grid, position, moves, index+1, visited);
            visited.erase(position);
            position = move(position, L);
            grid[index] = '?';
            moves[R]--;
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; getline(cin, s);
    pair<int, int> position = {0, 0};
    int moves[4] = {0};
    set<pair<int, int>> positions;
    fill(s, position, moves, 0, positions);
    cout << ct;
    return 0;
}