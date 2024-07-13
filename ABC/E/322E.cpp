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
    ll N, K, P;
    cin >> N >> K >> P;
    vll costs(N);
    vvll values(N);
    rep(i, N) {
        cin >> costs.at(i);
        rep(j, K) {
            ll v;
            cin >> v;
            values.at(i).push_back(v);
        }
    }
    map<vll, ll> mp;
    vll start, end;
    rep(i, K) {
        start.push_back(0);
        end.push_back(P);
    }
    mp[start] = 0;
    rep(i, N) {
        map<vll, ll> tmp = mp;
        for (auto v : mp) {
            vll key = v.first;
            ll value = v.second;
            rep(j, K) {
                key.at(j) += values.at(i).at(j);
                key.at(j) = min(key.at(j), P);
            }
            // outv(key);
            // cout << value << endl;
            if (tmp.find(key) == tmp.end()) {
                tmp[key] = value + costs.at(i);
            } else {
                tmp[key] = min(tmp[key], value + costs.at(i));
            }
        }
        mp = tmp;
    }
    if (mp.find(end) == mp.end()) {
        cout << -1 << endl;
    } else {
        cout << mp[end] << endl;
    }

    return 0;
}
