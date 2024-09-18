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
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    map<char, ll> mp;
    for (char c : S1) mp[c]++;
    for (char c : S2) mp[c]++;
    for (char c : S3) mp[c]++;

    ll m = mp.size();

    if (m > 10) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vll num(10);
    rep(i, 10) num[i] = i;

    do {
        map<char, ll> mp2;
        ll index = 0;
        for (auto [key, value] : mp) {
            mp2[key] = num[index];
            index++;
        }

        ll x1 = 0, x2 = 0, x3 = 0;
        for (char c : S1) x1 = x1 * 10 + mp2[c];
        for (char c : S2) x2 = x2 * 10 + mp2[c];
        for (char c : S3) x3 = x3 * 10 + mp2[c];

        if (x1 == 0 || x2 == 0 || x3 == 0) continue;

        ll digit1 = 0;
        ll c1 = x1;
        while (c1 > 0) {
            c1 /= 10;
            digit1++;
        }
        ll digit2 = 0;
        ll c2 = x2;
        while (c2 > 0) {
            c2 /= 10;
            digit2++;
        }
        ll digit3 = 0;
        ll c3 = x3;
        while (c3 > 0) {
            c3 /= 10;
            digit3++;
        }
        if (digit1 != S1.size() || digit2 != S2.size() || digit3 != S3.size()) continue;
        if (x1 + x2 == x3) {
            cout << x1 << endl;
            cout << x2 << endl;
            cout << x3 << endl;
            return 0;
        }
    } while (next_permutation(num.begin(), num.end()));

    cout << "UNSOLVABLE" << endl;

    return 0;
}
