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

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main() {
    ll N;
    string S;
    ll Q;
    cin >> N >> S >> Q;

    vector<segtree<ll, op, e>> seg(26, segtree<ll, op, e>(N));
    rep(i, N) { seg[S[i] - 'a'].set(i, 1); }
    // rep(i, 26) {
    //     rep(j, N) { cout << seg[i].get(j) << " "; }
    //     cout << endl;
    // }

    vll count(26);
    rep(i, 26) { count[i] = seg[i].all_prod(); }

    rep(i, Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll x;
            char c;
            cin >> x >> c;
            x--;
            seg[S[x] - 'a'].set(x, 0);
            count[S[x] - 'a']--;
            S[x] = c;
            seg[S[x] - 'a'].set(x, 1);
            count[S[x] - 'a']++;
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            bool ok = true;
            bool edge = false;
            ll now = l;
            rep(j, 26) {
                if (count[j] == 0) continue;
                if (j + 'a' == S[l] || j + 'a' == S[r]) edge = true;
                // cout << j << " " << count[j] << " " << seg[j].prod(l, r + 1) << endl;
                if (!edge && count[j] != seg[j].prod(l, r + 1)) {
                    if (S[l] - 'a' < j && j < S[r] - 'a') {
                        ok = false;
                        break;
                    }
                }
                if (seg[j].prod(now, r + 1) == seg[j].prod(l, r + 1)) {
                    now += seg[j].prod(now, r + 1);
                } else {
                    ok = false;
                    break;
                }
                edge = false;
            }
            if (ok) {
                Yes;
            } else {
                No;
            }
        }
    }

    return 0;
}
