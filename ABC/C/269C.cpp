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
    vll bit;
    rep(i, 60) {
        if (N & (1LL << i)) {
            bit.push_back(i);
        }
    }
    ll M = bit.size();

    vector<vector<ll>> bitSearch;
    rep(i, 1 << M) {
        vector<ll> S;
        rep(bit, M) {
            if (i & (1 << bit)) {
                S.push_back(bit);
            }
        }
        bitSearch.push_back(S);
    }

    for (auto& v : bitSearch) {
        ll ans = 0;
        for (auto& i : v) {
            ans += 1LL << bit[i];
        }
        cout << ans << endl;
    }



    return 0;
}
