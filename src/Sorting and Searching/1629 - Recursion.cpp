#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Recursive exponential solution, fails test #4 and #6
    Still very cool
*/

void movieSelection(map<int, int>& movies, set<int>::iterator currTime, set<int>& startTimes, int currMovieCount, int& maxMovies) {
    if (currTime == startTimes.end() || *currTime > *(startTimes.rbegin())) {
        maxMovies = max(maxMovies, currMovieCount);
        return;
    }

    // find new movie
        auto nextMovieStart = startTimes.upper_bound(*currTime);
    int currTimeValue = *(currTime);
    int nextMovieValue = *(nextMovieStart);
    // include this movie
    movieSelection(movies, startTimes.lower_bound(movies[currTimeValue]), startTimes, currMovieCount+1, maxMovies);

    // exclude this movie
    movieSelection(movies, nextMovieStart, startTimes, currMovieCount, maxMovies);
}

int32_t main() {
    int n; cin >> n;
    map<int, int> movies;
    set<int> startTimes;
    int k, v;
    for (int i = 0; i < n; i++) {
        cin >> k;
        cin >> v;
        movies[k] = (movies[k] == 0) ? (v) : (min(movies[k], v));
        startTimes.insert(k);
    }

    int maxMovies = 0;
    movieSelection(movies, (startTimes.begin()), startTimes, 0, maxMovies);
    cout << maxMovies << "\n";
}