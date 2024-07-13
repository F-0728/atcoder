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
    string S;
    cin >> S;
    ll N;
    cin >> N;
    string n;
    while (N >= 1) {
        n += (N & 1) ? '1' : '0';
        N >>= 1;
    }
    reverse(n.begin(), n.end());
    ll Ssize = S.size();
    ll Nsize = n.size();
    if (Ssize > Nsize) {
        rep(i, Ssize - Nsize) {
            n = '0' + n;
        }
    }
    Nsize = n.size();
    if (Ssize < Nsize) {
        ll res = 0;
        rep(i, Ssize) {
            if (S.at(i) != '0') {
                res += 1;
            }
            if (i == Ssize - 1) {
                cout << res << endl;
                return 0;
            }
            res <<= 1;
        }
    }
    if (S == n) {
        ll res = 0;
        rep(i, Ssize) {
            res += S.at(i) - '0';
            if (i == Ssize - 1) {
                cout << res << endl;
                return 0;
            }
            res <<= 1;
        }
    }
    string ans = "";
    ll current = 0;
    ll idx = -1;
    while (current < S.size()) {
        if (S.at(current) != '?' && S.at(current) != n.at(current)) {
            idx = current;
            break;
        }
        current++;
    }
    if (idx == -1) {
        ll res = 0;
        rep(i, Nsize) {
            res += n.at(i) - '0';
            if (i == Nsize - 1) {
                cout << res << endl;
                return 0;
            }
            res <<= 1;
        }
    }
    for (ll i = idx; i >= 0; i--) {
        if (S.at(i) == '1') continue;
        if (n.at(i) == '0') continue;
        ll ans = 0;
        rep(j, i) {
            ans += n.at(j) - '0';
            ans <<= 1;
        }
        if (i != S.size() - 1) {
            ans <<= 1;
        }
        for (ll j = i + 1; j < S.size(); j++) {
            if (S.at(j) == '?') {
                ans += 1;
            } else {
                ans += S.at(j) - '0';
            }
            ans <<= 1;
        }
       if (i == S.size() - 1) {
            cout << ans << endl;
            return 0;
        }
        ans >>= 1;
        cout << ans << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
