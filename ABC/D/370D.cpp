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
    ll H, W, Q;
    cin >> H >> W >> Q;

    vpll query(Q);
    rep(i, Q) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        query[i] = {r, c};
    }

    vector<set<ll>> row(H), col(W);
    rep(i, H) {
        rep(j, W) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    rep(i, Q) {
        ll r = query[i].first;
        ll c = query[i].second;

        if (row[r].find(c) != row[r].end()) {
            row[r].erase(c);
            col[c].erase(r);
            continue;
        }

        ll left = -1;
        ll right = -1;
        ll up = -1;
        ll down = -1;

        auto Rright = row[r].lower_bound(c);
        if (Rright != row[r].end()) {
            right = *Rright;
        }

        if (Rright != row[r].begin()) {
            Rright--;
            left = *Rright;
        }

        auto Cdown = col[c].lower_bound(r);
        if (Cdown != col[c].end()) {
            down = *Cdown;
        }

        Cdown = col[c].lower_bound(r);
        if (Cdown != col[c].begin()) {
            Cdown--;
            up = *Cdown;
        }

        if (left != -1) {
            col[left].erase(r);
            row[r].erase(left);
        }
        if (right != -1) {
            col[right].erase(r);
            row[r].erase(right);
        }
        if (up != -1) {
            row[up].erase(c);
            col[c].erase(up);
        }
        if (down != -1) {
            row[down].erase(c);
            col[c].erase(down);
        }
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (row[i].find(j) != row[i].end()) {
                if (col[j].find(i) != col[j].end()) {
                    // cout << i << " " << j << endl;
                    ans++;
                }
            }
        }
        // if (row[i].size() > 0) {
        //     // cout << i << ": ";
        //     // for (auto s : row[i]) {
        //     //     cout << s << " ";
        //     // }
        //     // cout << endl;
        //     ans += row[i].size();
        // }
    }

    cout << ans << endl;

    return 0;
}
