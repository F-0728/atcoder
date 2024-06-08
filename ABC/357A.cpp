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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

int main() {
    ll N, M;
    cin >> N >> M;
    vll H(N);
    rep(i, N) cin >> H[i];
    if (N == 1) {
        if (M >= H[0]) {
            cout << 1 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }
    ll pointer = 0;
    while (M > 0) {
        if (pointer == N - 1) {
            cout << N << endl;
            return 0;
        }
        M -= H.at(pointer);
        pointer++;
    }
    if (M == 0) {
        cout << pointer << endl;
    } else {
        cout << pointer - 1 << endl;
    }

    return 0;
}
