#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <chrono>
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
#define vld vector<ld>
#define vbool vector<bool>
#define vmint vector<mint>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vvbool vector<vector<bool>>
#define vvmint vector<vector<mint>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
ll power(ll x, ll y) {ll res = 1; while(y > 0){if (y % 2 == 1) {res *= x;} x *= x; y >>= 1;}return res;}
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

using S = long long;
using F = long long;

S op(S a, S b){ return std::max(a, b); }
S e(){ return 0; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    ll Q;
    cin >> Q;
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(200001);
    ll count = 0;
    rep(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            count++;
        } else if (t == 2) {
            ll T;
            cin >> T;
            seg.apply(0, count, T);
        } else {
            vll trees;
            rep(i, count) {
                trees.push_back(seg.get(i));
            }
            sort(trees.begin(), trees.end());
            ll H;
            cin >> H;
            ll lb = lower_bound(trees.begin(), trees.end(), H) - trees.begin();
            cout << count - lb << endl;
            rep(i, count) {
                seg.set(i, 0);
            }
            count = lb;
            rep(i, count) {
                seg.set(i, trees[i]);
            }
        }
    }

    // vll trees;
    // map<ll, ll> mp;
    // rep(i, Q) {
    //     ll t;
    //     cin >> t;
    //     if (t == 1) {
    //         trees.push_back(0);
    //     } else if (t == 2) {
    //         ll T;
    //         cin >> T;
    //         mp[trees.size()] = T;
    //     } else {
    //         ll H;
    //         cin >> H;
    //         ll ans = 0;
    //         vpll mpv;
    //         vll next;
    //         for (auto [k, v] : mp) {
    //             mpv.push_back({k, v});
    //         }
    //         reverse(mpv.begin(), mpv.end());
    //         ll sum = 0;

    //         if (mpv.size() == 0) {
    //             sort(trees.begin(), trees.end());
    //             ll lb = lower_bound(trees.begin(), trees.end(), H) - trees.begin();
    //             cout << trees.size() - lb << endl;

    //             rep(i, lb) {
    //                 next.push_back(trees[i]);
    //             }
    //             continue;
    //         }

    //         ll now = trees.size();
    //         sort(trees.begin() + mpv[0].first, trees.end());
    //         ll lb = lower_bound(trees.begin() + mpv[0].first, trees.end(), H) - trees.begin();
    //         ans += trees.size() - lb;
    //         now = mpv[0].first;
    //         sum += mpv[0].second;
    //         for (ll i = mpv[0].first; i < lb; i++) {
    //             next.push_back(trees[i] + sum);
    //         }

    //         for (auto [k, v] : mpv) {
    //             sort(trees.begin() + k, trees.begin() + now);
    //             lb = lower_bound(trees.begin() + k, trees.begin() + now, H - sum) - trees.begin();
    //             ans += now - lb;
    //             now = k;
    //             sum += v;
    //             for (ll i = k; i < lb; i++) {
    //                 next.push_back(trees[i] + sum);
    //             }
    //         }

    //         sort(trees.begin(), trees.begin() + now);
    //         lb = lower_bound(trees.begin(), trees.begin() + now, H - sum) - trees.begin();
    //         ans += now - lb;
    //         for (ll i = 0; i < lb; i++) {
    //             next.push_back(trees[i] + sum);
    //         }

    //         trees = next;
    //         mp.clear();

    //         cout << ans << endl;
        // }
    // }

    return 0;
}
