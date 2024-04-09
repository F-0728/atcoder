#include <atcoder/all>
#include <iostream>
#include <set>
using namespace std;
using namespace atcoder;

int main() {
    set<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        s.insert(d);
    }
    cout << s.size() << endl;
    return 0;
}
