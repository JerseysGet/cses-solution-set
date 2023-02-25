#include <bits/stdc++.h>
#define int long long
using namespace std;

// returns sum n/product(S), over all subsets S of primes of size k
int sum = 0;
int inclusionExclusion(vector<int>& primes, int currIndex, int n, int currTerm, int currSize) {
    if (currIndex == primes.size()) {
        if (currSize == 0) {
            return 0;
        }
        sum += currTerm * ((currSize % 2 == 0)? (-1) : (1));
        return sum;
    }
    
    inclusionExclusion(primes, currIndex + 1, n, currTerm/primes[currIndex], currSize + 1);

    inclusionExclusion(primes, currIndex + 1, n, currTerm, currSize);

    return sum;
}

int32_t main() {
    int n, k; cin >> n >> k;
    vector<int> primes(k); for (int& v : primes) cin >> v;
    cout << inclusionExclusion(primes, 0, n, n, 0) << "\n";
}