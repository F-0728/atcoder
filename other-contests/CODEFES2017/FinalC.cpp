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
using ld = long double;
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
    vll D(N);
    rep(i, N) cin >> D[i];
    vll count(13, 0);
    for (ll d : D) {
        count[d]++;
    }
    count[0]++;

    ll ans = 0;
    rep(i, 1 << 13) {
        vll now(24, 0);
        rep(j, 13) {
            if (count[j] == 0) continue;
            if (count[j] >= 3) {
                cout << 0 << endl;
                return 0;
            }
            if (j == 0 || j == 12) {
                if (count[j] == 2) {
                    cout << 0 << endl;
                    return 0;
                }
                now[j] += count[j];
                continue;
            }
            if (count[j] == 2) {
                now[j]++;
                now[24 - j]++;
            } else {
                if (i & (1 << j)) {
                    now[j]++;
                } else {
                    now[24 - j]++;
                }
            }
        }
        ll minGap = INF;
        ll gap = 1;
        rep(j, 24) {
            if (j == 0) continue;
            if (now[j] > 0) {
                if (gap > 12) {
                    minGap = min(minGap, 24 - gap);
                } else {
                    minGap = min(minGap, gap);
                }
                gap = 1;
            } else {
                gap++;
            }
        }
        if (gap > 12) {
            minGap = min(minGap, 24 - gap);
        } else {
            minGap = min(minGap, gap);
        }
        ans = max(ans, minGap);
    }

    cout << ans << endl;

    return 0;
}
