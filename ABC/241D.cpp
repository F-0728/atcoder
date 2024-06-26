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
    ll Q;
    cin >> Q;
    vvll query(Q);
    rep(i, Q) {
        ll q;
        cin >> q;
        query[i].push_back(q);
        if (q == 1) {
            ll x;
            cin >> x;
            query[i].push_back(x);
        } else {
            ll x, k;
            cin >> x >> k;
            query[i].push_back(x);
            query[i].push_back(k);
        }
    }
    multiset<ll> s;
    rep(i, Q) {
        ll q = query[i][0];
        if (q == 1) {
            s.insert(query[i][1]);
        } else if (q == 2) {
            auto it = s.upper_bound(query[i][1]);
            rep(j, query[i][2] - 1) {
                if (it == s.begin()) {
                    break;
                } else {
                    it--;
                }
            }
            if (it == s.begin()) {
                cout << -1 << endl;
            } else {
                it--;
                cout << *it << endl;
            }
        } else {
            auto it = s.lower_bound(query[i][1]);
            ll k = query[i][2];
            rep(j, query[i][2] - 1) {
                if (it == s.end()) {
                    break;
                } else {
                    it++;
                }
            }
            if (it == s.end()) {
                cout << -1 << endl;
            } else {
                cout << *it << endl;
            }
        }
    }

    return 0;
}
