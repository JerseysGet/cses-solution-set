#include <bits/stdc++.h>
using namespace std;
#define int long long

int bSearchJustGreater(vector<int>& wt, int val, int Lp, int Rp) {
    int L = Lp, R = Rp;
    int M;
    while (R - L > 1) {
        M = (R + L) / 2;
        if (wt[M] > val) {
            R = M;
        } else {
            L = M;
        }
    }

    if (wt[R] <= val) {
        return R;
    } else if (wt[L] <= val) {
        return L;
    }

    return -1;
}

int32_t main() {
    int n, x; cin >> n >> x;
    vector<int> wt;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        wt.push_back(k);
    }

    sort(wt.begin(), wt.end());
    int Lp = 0, Rp = wt.size() - 1;
    int ans = 0;
    while (Lp <= Rp) {
        int k = bSearchJustGreater(wt, x - wt[Lp], Lp, Rp);
        ans += (k == -1) ? (Rp - Lp + 1) : (Rp - k);
        Rp = (k == -1) ? (Rp) : (k);
        if (k == -1) {
            break;
        }
        Lp++;
        Rp--;
        ans++;
    }  

    cout << ans << "\n";
}