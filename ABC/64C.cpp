#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
using namespace atcoder;

using mint = modint1000000007;
// using mint = modint998244353;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    vector<ll> colors(9, 0);
    ll N;
    cin >> N;
    rep(i, N) {
        ll rating;
        cin >> rating;
        if (rating >= 3200) {
            colors[8]++;
        } else {
            colors[rating / 400]++;
        }
    }
    ll min = 0, max = 0;
    rep(i, 8) {
        if (colors[i] > 0) {
            min++;
            max++;
        }
    }
    max += colors[8];
    if (min == 0) {
        min = 1;
    }
    cout << min << " " << max << endl;


    return 0;
}
