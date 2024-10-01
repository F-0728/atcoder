#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

// using mint = modint1000000007;
using mint = modint998244353;
using ll = long long;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template <typename T>
void outv(const vector<T>& v) {
    for (const auto& e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ll N;
    cin >> N;
    vll W(N);
    rep(i, N) cin >> W[i];
    vll B(N);
    rep(i, N) cin >> B[i];

    map<pll, ll> grundy;
    grundy[{0, 0}] = 0;
    grundy[{0, 1}] = 0;
    rep(i, 51) {
        rep(j, i * (i + 1) / 2 + 51) {
            set<ll> s;
            if (i != 0) {
                if (grundy.count({i - 1, j + i})) {
                    s.insert(grundy[{i - 1, j + i}]);
                }
            }
            if (j >= 2) {
                for (ll k = 1; k <= j / 2; k++) {
                    s.insert(grundy[{i, j - k}]);
                }
            }
            ll g = 0;
            while (s.count(g)) {
                g++;
            }
            grundy[{i, j}] = g;
        }
    }

    ll XOR = 0;
    rep(i, N) { XOR ^= grundy[{W[i], B[i]}]; }

    if (XOR == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }

    return 0;
}
