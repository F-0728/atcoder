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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, Q;
    cin >> N >> Q;
    dsu d(N);
    vll sum(N - 1, -INF);
    vll A(N, 0);
    vvll query(Q, vll(4, 0));
    rep(i, Q) {
        ll t, x, y, v;
        cin >> t >> x >> y >> v;
        x--; y--;
        query.at(i) = {t, x, y, v};
    }
    rep(i, Q) {
        if (query.at(i).at(0) == 0) {
            sum.at(query.at(i).at(1)) = query.at(i).at(3);
        }
    }
    rep(i, N - 1) {
        if (sum.at(i) != INF) A.at(i + 1) = sum.at(i) - A.at(i);
    }

    rep(i, Q) {
        ll T, X, Y, V;
        T = query.at(i).at(0);
        X = query.at(i).at(1);
        Y = query.at(i).at(2);
        V = query.at(i).at(3);

        if (T == 0) {
            d.merge(X, Y);
        } else {
            if (!d.same(X, Y)) {
                cout << "Ambiguous" << endl;
            } else {
                if ((X + Y) % 2 == 0) {
                    cout << A.at(Y) - A.at(X) + V << endl;
                    // outv(A);
                } else {
                    cout << A.at(Y) + A.at(X) - V << endl;
                    // outv(A);
                }
            }
        }
    }

    return 0;
}
