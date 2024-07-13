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
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;

int main() {
    ll K;
    cin >> K;
    queue<ll> lunlun;
    for (ll i = 1; i <= 9; i++) {
        lunlun.push(i);
    }
    while (K > 1) {
        ll l = lunlun.front();
        lunlun.pop();
        K--;
        if (l % 10 == 9) {
            lunlun.push(l * 10 + 8);
            lunlun.push(l * 10 + 9);
        } else if (l % 10 == 0) {
            lunlun.push(l * 10);
            lunlun.push(l * 10 + 1);
        } else {
            lunlun.push(l * 10 + l % 10 - 1);
            lunlun.push(l * 10 + l % 10);
            lunlun.push(l * 10 + l % 10 + 1);
        }
    }
    cout << lunlun.front() << endl;

    return 0;
}
