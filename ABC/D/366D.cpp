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
    vector<vvll> A(N, vvll(N, vll(N)));
    rep(i, N) rep(j, N) rep(k, N) { cin >> A.at(i).at(j).at(k); }
    ll Q;
    cin >> Q;
    vvll query(Q, vll(6));
    rep(i, Q) {
        rep(j, 6) {
            ll t;
            cin >> t;
            query.at(i).at(j) = t - 1;
        }
    }

    vector<vvll> cSum(N + 1, vvll(N + 1, vll(N + 1)));
    rep(i, N) {
        cSum.at(i + 1) = cSum.at(i);
        rep(j, N) {
            rep(k, N) { cSum.at(i + 1).at(j + 1).at(k + 1) += A.at(i).at(j).at(k); }
        }
    }
    rep(i, N + 1) {
        rep(j, N) {
            rep(k, N) { cSum.at(i).at(j + 1).at(k + 1) += cSum.at(i).at(j).at(k + 1); }
        }
    }
    rep(i, N + 1) {
        rep(j, N + 1) {
            rep(k, N) { cSum.at(i).at(j).at(k + 1) += cSum.at(i).at(j).at(k); }
        }
    }

    rep(i, Q) {
        ll lx = query.at(i).at(0);
        ll rx = query.at(i).at(1);
        ll ly = query.at(i).at(2);
        ll ry = query.at(i).at(3);
        ll lz = query.at(i).at(4);
        ll rz = query.at(i).at(5);
        rx++;
        ry++;
        rz++;
        ll ans = cSum.at(rx).at(ry).at(rz) - cSum.at(lx).at(ry).at(rz) -
                 cSum.at(rx).at(ly).at(rz) - cSum.at(rx).at(ry).at(lz) +
                 cSum.at(lx).at(ly).at(rz) + cSum.at(lx).at(ry).at(lz) +
                 cSum.at(rx).at(ly).at(lz) - cSum.at(lx).at(ly).at(lz);
        cout << ans << endl;
    }

    // rep(i, N + 1) {
    //     rep(j, N + 1) {
    //         outv(cSum.at(i).at(j));
    //     }
    // }

    return 0;
}
