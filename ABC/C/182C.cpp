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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N;
    cin >> N;
    string s = to_string(N);

    map<ll, ll> mp;
    for (char c : s) {
        mp[(c - '0') % 3]++;
    }

    ll sum = 0;
    rep(i, 3) {
        sum += mp[i] * i;
        sum %= 3;
    }

    if (sum == 0) {
        cout << 0 << endl;
    } else if (sum == 1) {
        if (s.size() < 2) {
            cout << -1 << endl;
            return 0;
        }
        if (mp[1] >= 1) {
            cout << 1 << endl;
        } else if (mp[2] >= 2) {
            if (s.size() == 2) {
                cout << -1 << endl;
                return 0;
            }
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (s.size() < 2) {
            cout << -1 << endl;
            return 0;
        }
        if (mp[2] >= 1) {
            cout << 1 << endl;
        } else if (mp[1] >= 2) {
            if (s.size() == 2) {
                cout << -1 << endl;
                return 0;
            }
            cout << 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
