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
    ll N, M;
    cin >> N >> M;
    vll ans(N);
    priority_queue<vll, vvll, greater<vll>> pq;
    set<ll> online;
    rep(i, N) {
        online.insert(i);
    }
    vvll somen(M);
    rep(i, M){
        ll t, w, s;
        cin >> t >> w >> s;
        somen.at(i) = {t, w, s};
        pq.push({t, 1, w, s});
    }
    while(!pq.empty()){
        auto v = pq.top();
        // cout << "top: " << v.at(0) << " " << v.at(1) << " " << v.at(2) << endl;
        ll t = v.at(0);
        ll type = v.at(1);
        ll w = v.at(2);
        pq.pop();
        if (type == 1) {
            // outv(v);
            ll s = v.at(3);
            if (online.empty()) {
                continue;
            }
            ll top = *online.begin();
            ans.at(top) += w;
            online.erase(top);
            pq.push({t + s, 0, top});
        } else {
            online.insert(w);
        }
    }
    rep(i, N) {
        cout << ans.at(i) << endl;
    }

    return 0;
}
