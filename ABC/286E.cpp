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
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    vvll G(N);
    rep(i, N) {
        string s;
        cin >> s;
        rep(j, N) {
            if (s.at(j) == 'Y') {
                G.at(i).push_back(j);
            }
        }
    }
    vector<vpll> dist(N, vpll(N, {INF, -INF}));
    rep(i, N) {
        dist.at(i).at(i).first = 0;
        dist.at(i).at(i).second = A.at(i);
    }
    rep(i, N) {
        for (auto j : G.at(i)) {
            dist.at(i).at(j).first = 1;
            dist.at(i).at(j).second = A.at(i) + A.at(j);
        }
    }
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                if (dist.at(i).at(j).first == dist.at(i).at(k).first + dist.at(k).at(j).first) {
                    dist.at(i).at(j).second = max(dist.at(i).at(k).second + dist.at(k).at(j).second - A.at(k), dist.at(i).at(j).second);
                } else if (dist.at(i).at(j).first > dist.at(i).at(k).first + dist.at(k).at(j).first) {
                    dist.at(i).at(j).first = dist.at(i).at(k).first + dist.at(k).at(j).first;
                    dist.at(i).at(j).second = dist.at(i).at(k).second + dist.at(k).at(j).second - A.at(k);
                }
            }
        }
    }
    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        if (dist.at(x).at(y).first == INF) {
            cout << "Impossible" << endl;
        } else {
            cout << dist.at(x).at(y).first << " " << dist.at(x).at(y).second << endl;
        }
    }

    return 0;
}
