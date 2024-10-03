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
    vll A(N);
    rep(i, N) {
        ll a;
        cin >> a;
        A[i] = a % 200;
    }

    vector<vvll> mod200(200);
    vvll bitSearch;
    ll n = min(N, 8LL);
    rep(i, 1 << n) {
        vll bit;
        rep(j, n) {
            if (i & (1 << j)) {
                bit.push_back(j);
            }
        }
        bitSearch.push_back(bit);
    }
    for (vll v : bitSearch) {
        if (v.size() == 0) continue;
        ll sum = 0;
        for (ll i : v) {
            sum += A[i];
        }
        sum %= 200;
        mod200[sum].push_back(v);
    }

    rep(i, 200) {
        if (mod200[i].size() >= 2) {
            Yes;
            cout << mod200[i][0].size() << " ";
            for (ll j : mod200[i][0]) {
                cout << j + 1 << " ";
            }
            cout << endl;
            cout << mod200[i][1].size() << " ";
            for (ll j : mod200[i][1]) {
                cout << j + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    No;


    return 0;
}
