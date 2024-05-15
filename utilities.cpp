#include <atcoder/all>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
using namespace atcoder;

using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

string baseNtoM(string &s, int n, int m) {
    if (s == "0") {
        return "0";
    }
    long long t = 0;
    for (char c : s) {
        t = t * n + c - '0';
    }
    string r;
    while (t) {
        r += t % m + '0';
        t /= m;
    }
    std::reverse(r.begin(), r.end());
    return r;
}

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

ll powMod(ll x, ll y, ll MOD) {
    ll res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

ll factors(ll x) {
    ll f = 0;
    ll i = 2;
    while (x > 1) {
        while (i * i <= x) {
            if (x % i == 0) {
                f++;
                x /= i;
            } else {
                i++;
            }
        }
        if (x > 1) {
            f++;
            x = 1;
        }
    }
    return f;
}

vector<ll> divisors(ll x) {
    vector<ll> divs;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (i * i != x) {
                divs.push_back(x / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

// 0-nの数について素数かどうかのbool配列を返す
vector<bool> furui(ll n) {
    vector<bool> res(n+1, true);
    res[0] = false;
    res[1] = false;
    rep(i, 2) res.push_back(false);
    for (ll i = 2; i <= n; i++) {
        if (res[i]) {
            for (ll j = 2 * i; j <= n; j += i) {
                res[j] = false;
            }
        }   
    }
    return res;
}
