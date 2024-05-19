#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

ll xorSum(ll x) {
    if (x % 2 == 0) {
        ll one = (x / 2) % 2;
        return one ^ x;
    }
    return xorSum(x - 1) ^ x;
}

int main() {
    ll A, B;
    cin >> A >> B;
    if (A == 0) {
        cout << XOR(B) << endl;
        return 0;
    }
    A--;
    cout << (XOR(A) ^ XOR(B)) << endl;
    return 0;
}
