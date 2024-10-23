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
#define vld vector<ld>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, K;
    cin >> N >> K;
    vvll a(N, vll(N));
    rep(i, N) {
        rep(j, N) {
            cin >> a.at(i).at(j);
        }
    }

    vmint fact(N + 1);
    fact.at(0) = 1;
    rep(i, N) {
        fact.at(i + 1) = fact.at(i) * (i + 1);
    }

    dsu row(N), col(N);
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            bool ok = true;
            rep(k, N) {
                if (a.at(i).at(k) + a.at(j).at(k) > K) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                row.merge(i, j);
            }
        }
    }

    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            bool ok = true;
            rep(k, N) {
                if (a.at(k).at(i) + a.at(k).at(j) > K) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                col.merge(i, j);
            }
        }
    }

    mint ans = 1;
    auto rowGroups = row.groups();
    auto colGroups = col.groups();
    for (auto& group : rowGroups) {
        ans *= fact.at(group.size());
    }
    for (auto& group : colGroups) {
        ans *= fact.at(group.size());
    }

    cout << ans.val() << endl;


    return 0;
}
