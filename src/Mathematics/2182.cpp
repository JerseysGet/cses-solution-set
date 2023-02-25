#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 1000000007;
const int twoInverse = 500000004;

int multiply(int x, int y) {
    return ((x % M) * (y % M)) % M;
}

int multiply(int x, int y, int m) {
    return ((x % m) * (y % m)) % m;
}

int exponent(int a, int b) {
    if (b == 0) {
        return 1;
    }

    if (b % 2 == 0) {
        int f1 = exponent(a, b/2);
        return multiply(f1, f1);
    }

    if (b % 2 == 1) {
        return multiply(a, exponent(a, b - 1));
    }

    return 1;
}

// a^-1 mod M
int inverse(int a) {
    return exponent(a, M-2);
}

int32_t main() {
    int n; cin >> n;
    unordered_map<int, int> primeFactorization;
    int x, k;
    int numberOfFactors = 1, sumOfFactors = 1;
    int numberOfFactorsM = 1;
    int number = 1;
    bool isPerfectSquare = true;
    int rootNumber = 1;
    for (int i = 0; i < n; i++) {
        cin >> x >> k;
        primeFactorization[x] = k;
        numberOfFactors = multiply(numberOfFactors, 1 + k); 
        if (k % 2 == 1 && isPerfectSquare) {
            isPerfectSquare = false;
            numberOfFactorsM = multiply(numberOfFactorsM, (1 + k)/2, M - 1); 

        } else {
            numberOfFactorsM = multiply(numberOfFactorsM, 1 + k, M - 1); 
        }
        sumOfFactors = multiply(sumOfFactors, multiply(exponent(x, k+1) - 1, inverse(x - 1)));
        number = multiply(exponent(x, k), number);
        rootNumber = multiply(exponent(x, k/2), rootNumber);
    }
    
    cout << numberOfFactors << " " << sumOfFactors << " ";
    if (isPerfectSquare) {
        cout << exponent(rootNumber, numberOfFactorsM) << "\n";
    } else {
        cout << exponent(number, numberOfFactorsM) << "\n";
    }

}