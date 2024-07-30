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
    ll N;
    cin >> N;
    map<ll, ll> prev;
    map<ll, ll> next;
    vll A(N);
    rep(i, N) { cin >> A.at(i); }
    rep(i, N) {
        if (i != 0) {
            prev[A.at(i)] = A.at(i - 1);
        }
        if (i != N - 1) {
            next[A.at(i)] = A.at(i + 1);
        }
    }

    ll first = A.at(0);
    ll last = A.at(N - 1);

    ll Q;
    cin >> Q;
    rep(i, Q) {
        ll q;
        cin >> q;
        if (q == 1) {
            ll x, y;
            cin >> x >> y;
            if (x != last) {
                ll n = next[x];
                prev[n] = y;
                next[y] = n;
            } else {
                last = y;
            }
            next[x] = y;
            prev[y] = x;
        } else {
            ll x;
            cin >> x;
            if (x == first) {
                ll n = next[x];
                first = n;
                next.erase(x);
                prev.erase(n);
            } else if (x == last) {
                ll p = prev[x];
                last = p;
                next.erase(p);
                prev.erase(x);
            } 
            else {
                ll p = prev[x];
                ll n = next[x];
                next[p] = n;
                prev[n] = p;
                next.erase(x);
                prev.erase(x);
            }
        }
    }
    vll ans;
    ll now = first;
    while (1) {
        if (next.count(now) == 0) {
            ans.push_back(now);
            break;
        }
        ans.push_back(now);
        now = next[now];
    };
    outv(ans);

    return 0;
}
