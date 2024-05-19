#include <iostream>
using namespace std;

void Pattern(int n) {
    for (int line = 1; line <= n; line++) {
        for (int repeat = 0; repeat < n; repeat++){
            if (repeat % 2 == 0) {
                for (int i = 1; num <=line;num++){
                    cout << i;
                }
            } else {
                for (int i= line; num >= 1;i--){
                    cout << i;}
                    }
            if (repeat % 2 == 0 && repeat < n){
                int spaces = 2 * (n - line);
                cout << string(spaces, ' ');
            } else if (repeat % 2 != 0 && repeat < n){
                cout << "";
            }
        }
        cout << endl;
    }
}
int main() {
    int val;
    cin >> val;
    Pattern(val);
    return 0;
}

