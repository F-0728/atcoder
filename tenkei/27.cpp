#include <atcoder/all>
#include <iostream>
using namespace std;
using namespace atcoder;

int main() {
    int N;
    cin >> N;
    unordered_map<string, int> users;
    for (int i = 1; i <= N; i++) {
        string S;
        cin >> S;
        if (users.find(S) == users.end()) {
            users[S] = 1;
            cout << i << endl;
        } else {
            continue;
        }
    }

    return 0;
}
