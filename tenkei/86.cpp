#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
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
    ll N, Q;
    cin >> N >> Q;
    vector<vvll> query(60);
    rep(i, Q) {
        ll x, y, z, w;
        cin >> x >> y >> z >> w;
        x--;
        y--;
        z--;
        rep(j, 60) {
            query.at(j).push_back({x, y, z, w & 1});
            w >>= 1;
        }
    }
    mint ans = 1;
    rep(i, 60) {
        mint res = 0;
        vvll bitSearch;
        rep(j, 1 << N) {
            vll S;
            rep(k, N) {
                if (j & (1 << k)) {
                    S.push_back(k);
                }
            }
            bitSearch.push_back(S);
        }
        for (vll bits : bitSearch) {
            bool flag = true;
            for (vll q : query.at(i)) {
                ll x = q.at(0);
                ll y = q.at(1);
                ll z = q.at(2);
                ll w = q.at(3);
                if (w == 1) {
                    if (lower_bound(bits.begin(), bits.end(), x) !=
                            upper_bound(bits.begin(), bits.end(), x) ||
                        lower_bound(bits.begin(), bits.end(), y) !=
                            upper_bound(bits.begin(), bits.end(), y) ||
                        lower_bound(bits.begin(), bits.end(), z) !=
                            upper_bound(bits.begin(), bits.end(), z)) {
                        continue;
                    } else flag = false;
                } else {
                    if (lower_bound(bits.begin(), bits.end(), x) ==
                            upper_bound(bits.begin(), bits.end(), x) &&
                        lower_bound(bits.begin(), bits.end(), y) ==
                            upper_bound(bits.begin(), bits.end(), y) &&
                        lower_bound(bits.begin(), bits.end(), z) ==
                            upper_bound(bits.begin(), bits.end(), z)) {
                        continue;
                    } else flag = false;
                }
                if (!flag) break;
            }
            if (flag) res += 1;
        }
        ans *= res;
        // cout << res.val() << endl;
    }
    cout << ans.val() << endl;

    return 0;
}
