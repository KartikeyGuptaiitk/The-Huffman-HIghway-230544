#include <iostream>
using namespace std;

void printPattern(int n) {
    for (int line = 1; line <= n; ++line) {
        for (int repeat = 0; repeat < n; ++repeat){
            if (repeat % 2 == 0) {
                for (int num = 1; num <= line; ++num){
                    cout << num;
                }
            } else {
                for (int num = line; num >= 1; --num){
                    cout << num;
                }
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
    int input;
    cout << "Enter a number: ";
    cin >> input;
    printPattern(input);
    return 0;
}

