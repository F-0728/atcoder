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
ll mex(ll a, ll b, ll c) {
    set<ll> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    rep(i, 4) {
        if (s.count(i) == 0) {
            return i;
        }
    }
}

int main() {
    ll N;
    cin >> N;
    vll A(N);
    rep(i, N) cin >> A.at(i);
    string S;
    cin >> S;
    vvll Mcount(N, vll(3, 0));
    vll Eidx;
    vvll Xcount(N, vll(3, 0));
    rep(i, N) {
        if (i == 0) {
            if (S.at(i) == 'M') {
                Mcount.at(i).at(A.at(i))++;
            } else if (S.at(i) == 'E') {
                Eidx.push_back(i);
            } else {
                Xcount.at(i).at(A.at(i))++;
            }
            continue;
        }
        Mcount.at(i) = Mcount.at(i - 1);
        Xcount.at(i) = Xcount.at(i - 1);
        if (S.at(i) == 'M') {
            Mcount.at(i).at(A.at(i))++;
        } else if (S.at(i) == 'E') {
            Eidx.push_back(i);
        } else {
            Xcount.at(i).at(A.at(i))++;
        }
    }
    ll ans = 0;
    rep(i, Eidx.size()) {
        ll Aj = A.at(Eidx.at(i));
        rep(j, 3) {
            rep(k, 3) {
                ll AiCount = Mcount.at(Eidx.at(i)).at(j);
                ll AkCount = Xcount.at(N - 1).at(k) - Xcount.at(Eidx.at(i)).at(k);
                // cout << "Ai: " << j << " Aj: " << Aj << " Ak: " << k << " AiCount: " << AiCount << " AkCount: " << AkCount << endl;
                ll res = mex(j, Aj, k) * AiCount * AkCount;
                ans += res;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
