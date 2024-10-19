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
using ld = long double;
const ll inf = 1 << 30;
const ll INF = 1LL << 60;
const vector<pair<ll, ll>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vvld vector<vector<ld>>
#define vpll vector<pair<ll, ll>>
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll T;
    cin >> T;
    rep(i, T) {
        ll N, K;
        cin >> N >> K;
        vll A(N);
        rep(j, N) cin >> A[j];
        vll B(N);
        rep(j, N) cin >> B[j];

        vpll AB(N);
        // vpll BA(N);
        rep(j, N) {
            AB[j] = {A[j], B[j]};
            // BA[j] = {B[j], A[j]};
        }

        sort(AB.begin(), AB.end());
        // sort(BA.begin(), BA.end());
        
        ll res = INF;
        ll sum = 0;
        priority_queue<ll> pq;
        rep(j, N) {
            if (j < K - 1) {
                pq.push(AB[j].second);
                sum += AB[j].second;
                continue;
            }
            ll a = AB[j].first;
            ll MAX = a;
            ll b = AB[j].second;
            if (pq.size() == K && pq.top() > b) {
                sum -= pq.top();
                pq.pop();
                pq.push(b);
                sum += b;
            } else if (pq.size() < K) {
                pq.push(b);
                sum += b;
            }
            res = min(res, MAX * sum);
        }
        
        cout << res << endl;
    }

    return 0;
}
