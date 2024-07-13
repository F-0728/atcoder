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
    vll boxes(N);
    rep(i, N) {
        cin >> boxes.at(i);
    }
    vll friends(M);
    rep(i, M) {
        cin >> friends.at(i);
    }
    sort(boxes.begin(), boxes.end());
    sort(friends.begin(), friends.end());
    set<ll> S;
    map<ll, ll> mp;
    rep(i, N) {
        S.insert(boxes.at(i));
        mp[boxes.at(i)]++;
    }
    ll cost = 0;
    rep(i, M) {
        auto idx = S.lower_bound(friends.at(i));
        if (idx == S.end()) {
            cout << -1 << endl;
            return 0;
        }
        cost += *idx;
        if (mp[*idx] == 1) {
            S.erase(idx);
        } else {
            mp[*idx]--;
        }
    }
    cout << cost << endl;


    return 0;
}
