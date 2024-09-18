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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, K;
    cin >> N >> K;
    vll D(K);
    rep(i, K) cin >> D[i];

    ll now = N;
    while (true) {
        string s = to_string(now);
        bool ok = true;
        for (char c : s) {
            for (ll d : D) {
                if (c - '0' == d) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) break;
        now++;
    }

    cout << now << endl;

    return 0;
}
