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
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<pair<char, ll>> query(Q);
    rep(i, Q) {
        cin >> query[i].first >> query[i].second;
    }

    ll ans = 0;
    ll nowL = 1;
    ll nowR = 2;

    rep(i, Q) {
        char c = query[i].first;
        ll x = query[i].second;
        ll res = INF;
        if (c == 'L') {
            ll now = nowL;
            ll count = 0;
            bool meetR = false;
            while (now != x) {
                now++;
                if (now == N + 1) now = 1;
                count++;
                if (now == nowR) {
                    meetR = true;
                    break;
                }
            }
            if (!meetR) {
                res = count;
            }
            now = nowL;
            count = 0;
            meetR = false;
            while (now != x) {
                now--;
                if (now == 0) now = N;
                count++;
                if (now == nowR) {
                    meetR = true;
                    break;
                }
            }
            if (!meetR) {
                res = min(res, count);
            }
            nowL = x;
        } else {
            ll now = nowR;
            ll count = 0;
            bool meetL = false;
            while (now != x) {
                now++;
                if (now == N + 1) now = 1;
                count++;
                if (now == nowL) {
                    meetL = true;
                    break;
                }
            }
            if (!meetL) {
                res = count;
            }
            now = nowR;
            count = 0;
            meetL = false;
            while (now != x) {
                now--;
                if (now == 0) now = N;
                count++;
                if (now == nowL) {
                    meetL = true;
                    break;
                }
            }
            if (!meetL) {
                res = min(res, count);
            }
            nowR = x;
        }
        ans += res;
    }

    cout << ans << endl;

    return 0;
}
