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
void outv(const vector<T>& v) {for (const auto& e : v) {cout << e << " ";}cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    vvll popcorns(N);
    rep(i, N) {
        string S;
        cin >> S;
        rep(j, M) {
            if (S[j] == 'o') {
                popcorns.at(i).push_back(j);
            }
        }
    }

    vector<vector<ll>> bitSearch;
    rep(i, 1 << N) {
        vector<ll> S;
        rep(bit, N) {
            if (i & (1 << bit)) {
                S.push_back(bit);
            }
        }
        bitSearch.push_back(S);
    }

    ll ans = INF;
    for (vll v : bitSearch) {
        ll res = v.size();
        set<ll> st;
        for (ll i : v) {
            for (ll j : popcorns.at(i)) {
                st.insert(j);
            }
        }
        if (st.size() == M) {
            ans = min(ans, res);
        }
    }
    cout << ans << endl;

    return 0;
}
