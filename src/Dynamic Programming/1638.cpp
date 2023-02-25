#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 1000000007;

int32_t main() {
    int n; cin >> n;
    int numberOfPathsTo[n][n];
    for (int i = 0; i < n; i++) {
        numberOfPathsTo[i][0] = 1;
        numberOfPathsTo[0][i] = 1;
    }
    
    string line;
    getline(cin, line);
    bool f1 = true, f2 = true;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        for (int j = 0; j < n; j++) {   
            if (i != 0 && j != 0) {
                numberOfPathsTo[i][j] = (numberOfPathsTo[i-1][j] + numberOfPathsTo[i][j-1]) % M;
            }
            
            if (line[j] == '*') {
                if (i == 0 && f1) {
                    for (int k = j; k < n; k++) {
                        numberOfPathsTo[0][k] = 0;
                    }
                    f1 = false;
                }
                if (j == 0 && f2) {
                    for (int k = i; k < n; k++) {
                        numberOfPathsTo[k][0] = 0;
                    }
                    f2 = false;
                }
                numberOfPathsTo[i][j] = 0;
            }
        }
    }

    cout << numberOfPathsTo[n-1][n-1] << "\n";
}

