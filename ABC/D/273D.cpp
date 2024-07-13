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
    ll H, W, rs, cs;
    cin >> H >> W >> rs >> cs;
    rs--;
    cs--;
    ll N;
    cin >> N;
    map<ll, vll> vertical, horizontal;
    rep(i, N) {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        vertical[c].push_back(r);
        horizontal[r].push_back(c);
    }
    for (auto& p : vertical) {
        sort(p.second.begin(), p.second.end());
    }
    for (auto& p : horizontal) {
        sort(p.second.begin(), p.second.end());
    }
    ll Q;
    cin >> Q;
    rep(i, Q) {
        char d;
        ll l;
        cin >> d >> l;
        if (d == 'R') {
            if (horizontal.count(rs) == 0) {
                cout << rs + 1 << " " << min(cs + l + 1, W) << endl;
                cs = min(cs + l, W - 1);
                continue;
            }
            ll idx = upper_bound(horizontal[rs].begin(),
                                 horizontal[rs].end(), cs) -
                     horizontal[rs].begin();
            ll ans = INF;
            if (idx < horizontal[rs].size()) {
                ans = horizontal[rs].at(idx);
            }
            ans = min(ans, cs + l + 1);
            ans = min(ans, W);
            cout << rs + 1 << " " << ans << endl;
            cs = ans - 1;
            continue;
        }
        if (d == 'L') {
            if (horizontal.count(rs) == 0) {
                cout << rs + 1 << " " << max(cs - l + 1, 1LL) << endl;
                cs = max(cs - l, 0LL);
                continue;
            }
            ll idx = lower_bound(horizontal[rs].begin(),
                                 horizontal[rs].end(), cs) -
                     horizontal[rs].begin() - 1;
            ll ans = 0;
            if (idx >= 0) {
                ans = horizontal[rs].at(idx) + 2;
            }
            ans = max(ans, cs - l + 1);
            ans = max(ans, 1LL);
            cout << rs + 1 << " " << ans << endl;
            cs = ans - 1;
            continue;
        }
        if (d == 'D') {
            if (vertical.count(cs) == 0) {
                cout << min(rs + l + 1, H) << " " << cs + 1 << endl;
                rs = min(rs + l, H - 1);
                continue;
            }
            ll idx = upper_bound(vertical[cs].begin(), vertical[cs].end(),
                                 rs) -
                     vertical[cs].begin();
            ll ans = INF;
            if (idx < vertical[cs].size()) {
                ans = vertical[cs].at(idx);
            }
            ans = min(ans, rs + l + 1);
            ans = min(ans, H);
            cout << ans << " " << cs + 1 << endl;
            rs = ans - 1;
            continue;
        }
        if (d == 'U') {
            if (vertical.count(cs) == 0) {
                cout << max(rs - l + 1, 1LL) << " " << cs + 1 << endl;
                rs = max(rs - l, 0LL);
                continue;
            }
            ll idx = lower_bound(vertical[cs].begin(), vertical[cs].end(),
                                 rs) -
                     vertical[cs].begin() - 1;
            // outv(vertical[cs]);
            // cout << "rs: " << rs << endl;
            // cout << "idx: " << idx << endl;
            ll ans = 0;
            if (idx >= 0) {
                ans = vertical[cs].at(idx) + 2;
            }
            ans = max(ans, rs - l + 1);
            ans = max(ans, 1LL);
            cout << ans << " " << cs + 1 << endl;
            rs = ans - 1;
            continue;
        }
    }

    return 0;
}
