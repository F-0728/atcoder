#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll N;
    cin >> N;
    vector<vector<pair<ll, ll>>> testimony(N);
    rep(i, N) {
        ll A;
        cin >> A;
        rep(j, A) {
            ll x, y;
            cin >> x >> y;
            testimony.at(i).push_back(make_pair(x - 1, y));
        }
    }

    vector<vector<ll>> bitSearch;
    rep(i, 1 << N) {
        vector<ll> S;
        rep(j, N) {
            if (i & (1 << j)) {
                S.push_back(j);
            }
        }
        bitSearch.push_back(S);
    }

    ll ans = 0;
    for (vll honests : bitSearch) {
        bool flag = true;
        for (ll honest : honests) {
            for (pair<ll, ll> test : testimony.at(honest)) {
                if ((honests.end() ==
                         find(honests.begin(), honests.end(), test.first) &&
                     test.second == 1) ||
                    (honests.end() !=
                         find(honests.begin(), honests.end(), test.first) &&
                     test.second == 0)) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            ans = max(ans, (ll)honests.size());
        }
    }
    cout << ans << endl;
    return 0;
}
