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

// 0-nの数について素数かどうかのbool配列を返す(篩)
vector<bool> furui(ll n) {
    vector<bool> res(n + 1, true);
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

// BFSテンプレ
void bfs(ll H, ll W, vector<string> s) {
    queue<vector<ll>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    q.push({0, 0, 1});
    ll ans = 1e8;
    while (!q.empty()) {
        vector<ll> p = q.front();
        // cout << p[0] << " " << p[1] << " " << p[2] << endl;
        q.pop();
        ll r = p[0];
        ll c = p[1];
        if (r >= H || c >= W || r < 0 || c < 0) continue;
        if (s[r][c] == '#') continue;
        if (visited[r][c]) continue;
        visited[r][c] = true;
        if (r == H - 1 && c == W - 1) {
            ans = min(ans, p[2]);
        }
        q.push({r + 1, c, p[2] + 1});
        q.push({r, c + 1, p[2] + 1});
        q.push({r - 1, c, p[2] + 1});
        q.push({r, c - 1, p[2] + 1});
    }
}

// 0からxまでのXORの総和
ll xorSum(ll x) {
    if (x % 2 == 0) {
        ll one = (x / 2) % 2;
        return one ^ x;
    }
    return xorSum(x - 1) ^ x;
}

// combination
vvll comb(int n, int r) {
    vvll v(n + 1, vll(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

// nPr, nCr mod p

const ll MAX = 2000005;
mint fact[MAX], factInv[MAX], inv[MAX];

void init() {
    ll MOD = mint::mod();
    fact[0] = fact[1] = 1;
    factInv[0] = factInv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fact[i] = fact[i - 1] * i;
        inv[i] = MOD - inv[MOD%i] * (MOD / i);
        factInv[i] = factInv[i - 1] * inv[i];
    }
}

mint nPr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[n - r];
}

mint nCr(ll n, ll r){
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fact[n] * factInv[r] * factInv[n - r];
}

// nPr, nCr mod p おわり

//bit全探索
vector<vector<ll>> bitSearch;
rep(i, 1 << 10) {
    vector<ll> S;
    rep(bit, 10) {
        if (i & (1 << bit)) {
            S.push_back(bit);
        }
    }
    bitSearch.push_back(S);
}

// nCrでnが大きい場合 (O(n)が無理だけどO(r)ならいける場合)
vector<mint> nCx(r + 1);
nCx.at(0) = 1;
rep(i, r) {
    nCx.at(i + 1) = nCx.at(i) * (N - i) / (i + 1);
}

