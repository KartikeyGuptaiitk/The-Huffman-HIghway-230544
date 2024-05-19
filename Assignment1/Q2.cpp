#include <iostream>
using namespace std;
int main() {
    int examScores[10];
    int highest, lowest;
    double average;
    int sum=0;
    cout << "Please enter 10 exam scores:" << endl;
    for (int i = 0; i < 10; i++) 
    {
        cin >> examScores[i];
        sum = sum + examScores[i];
        if (i == 0) {
            highest = lowest = examScores[i];
        } else {
         if (examScores[i] > highest) {
           highest = examScores[i]; }
         if (examScores[i] < lowest) {
           lowest = examScores[i];  }
        }
    }
    average = static_cast<double>(sum)/10;
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        if (examScores[i] > average) {
         a++;}
         else if (examScores[i] < average) {
         b++;}
    }
    cout << "Average exam score: "<< average << endl;
    cout << "Highest exam score: "<< highest << endl;
    cout << "Lowest exam score: "<< lowest << endl;
    cout << "Number of scores above the average: "<< a << endl;
    cout << "Number of scores below the average: "<< b << endl;
    return 0;
}
