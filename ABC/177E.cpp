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
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

vll spf(ll n) {
    vll res(n + 1);
    rep(i, n + 1) res.at(i) = i;
    for (ll i = 2; i * i <= n; i++) {
        if (res.at(i) == i) {
            for (ll j = i * i; j <= n; j += i) {
                if (res.at(j) == j) {
                    res.at(j) = i;
                }
            }
        }
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    ll gcdCheck = gcd(A.at(0), A.at(1));
    for (ll i = 2; i < N; i++) {
        gcdCheck = gcd(gcdCheck, A.at(i));
    }
    if (gcdCheck != 1) {
        cout << "not coprime" << endl;
        return 0;
    }
    vll spfCheck = spf(1000005);
    map<ll, ll> included;
    rep(i, N) {
        ll a = A.at(i);
        while (a != 1) {
            ll p = spfCheck.at(a);
            if (included.count(p) == 1) {
                cout << "setwise coprime" << endl;
                return 0;
            }
            included[p] = 1;
            while (a % p == 0) {
                a /= p;
            }
        }
    }
    cout << "pairwise coprime" << endl;

    return 0;
}
