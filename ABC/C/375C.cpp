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
using ld = long double;
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

ll N;

pll rotate90(pll p) {
    return {N - 1 - p.second, p.first};
}

int main() {
    cin >> N;
    vector<string> S(N);
    rep(i, N) { cin >> S[i]; }

    vector<vector<char>> ans(N, vector<char>(N));
    rep(i, N) {
        rep(j, N) {
            ll mod = min(min(i, N - 1 - i), min(j, N - 1 - j)) % 4;
            pll prev;
            pll p = {i, j};
            if (mod == 0) {
                prev = rotate90(p);
                ans[i][j] = S[prev.first][prev.second];
            } else if (mod == 1) {
                prev = rotate90(rotate90(p));
                ans[i][j] = S[prev.first][prev.second];
            } else if (mod == 2) {
                prev = rotate90(rotate90(rotate90(p)));
                ans[i][j] = S[prev.first][prev.second];
            } else {
                prev = p;
                ans[i][j] = S[prev.first][prev.second];
            }
        }
    }

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
