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
    ll N, K;
    cin >> N >> K;
    queue<ll> P;
    rep(i, N) {
        ll p;
        cin >> p;
        p--;
        P.push(p);
    }
    set<pll> S;
    vll ans(N, -1);

    if (K == 1) {
        rep(i, N) {
            ll p = P.front();
            P.pop();
            ans.at(p) = i + 1;
        }
        rep(i, N) {
            cout << ans.at(i) << endl;
        }
        return 0;
    }

    vll G(N, -1);
    // dsu d(N);
    rep(i, N) {
        ll p = P.front();
        P.pop();
        if (S.size() == 0) {
            S.insert({p, 0});
        } else {
            auto itr = S.lower_bound({p, 0});
            if (itr == S.end()) {
                S.insert({p, 0});
            } else {
                ll v = itr->first;
                ll cnt = itr->second;
                S.erase(itr);
                G.at(p) = v;
                if (cnt + 2 == K) {
                    while (G.at(p) != -1) {
                        ans.at(p) = i + 1;
                        p = G.at(p);
                    }
                    ans.at(p) = i + 1;
                } else {
                    S.insert({p, cnt + 1});
                    G.at(p) = v;
                }
            }
        }
    }
    rep(i, N) {
        cout << ans.at(i) << endl;
    }

    

    return 0;
}
