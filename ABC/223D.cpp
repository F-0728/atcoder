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
template<typename T> void outv(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}

int main() {
    ll N, M;
    cin >> N >> M;
    vll indegree(N, 0);
    vvll G(N);
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        A--; B--;
        G.at(A).push_back(B);
        indegree.at(B)++;
    }

    priority_queue<ll, vll, greater<ll>> q;
    rep(i, N) {
        if (indegree.at(i) == 0) {
            q.push(i);
        }
    }
    vll ans;
    while (!q.empty()) {
        ll v = q.top();
        q.pop();
        ans.push_back(v);
        for (ll nv : G.at(v)) {
            indegree.at(nv)--;
            if (indegree.at(nv) == 0) {
                q.push(nv);
            }
        }
    }
    if (ans.size() != N) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, ans.size()){
        ans.at(i)++;
    }
    outv(ans);

    return 0;
}
