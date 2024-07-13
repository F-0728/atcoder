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
    ll N, M;
    cin >> N >> M;
    vvll switches(M);
    rep(i, M) {
        ll k;
        cin >> k;
        rep(j, k) {
            ll s;
            cin >> s;
            switches[i].push_back(s);
        }
    }
    vll p(M);
    rep(i, M) cin >> p[i];

    vvll bitSearch;
    rep(i, 1 << N) {
        vll S;
        rep(j, N) {
            if (i & (1 << j)) {
                S.push_back(j);
            }
        }
        bitSearch.push_back(S);
    }

    ll ans = 0;
    rep(i, 1 << N) {
        bool flag = true;
        rep(j, M) {
            ll cnt = 0;
            for (ll s : switches[j]) {
                if (find(bitSearch[i].begin(), bitSearch[i].end(), s - 1) != bitSearch[i].end()) {
                    cnt++;
                }
            }
            if (cnt % 2 != p[j]) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}
