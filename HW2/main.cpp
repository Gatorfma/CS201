//Created By Furkan Mert Aksakal 22003191
#include <iostream>
#include "ctime"
using namespace std;

unsigned long long int itfibo(long num) {
    unsigned long long int a = 1;
    unsigned long long int b = 1;
    unsigned long long int c = 1;
    for (int i = 3; i <= num; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

unsigned long long int recfibo(long num){
    if( num < 2)
        return num;
    else
        return (recfibo(num - 1) + recfibo(num - 2));
}
void durationf(long _itnum, long _recnum){
    cout << "\nnth number in the Fibonacci series(iterative) : " << itfibo(_itnum) << endl;
    cout << "\nnth number in the Fibonacci series(recursive) : " << recfibo(_recnum) << endl;
}

    int main() {
        long itnum;
        long recnum;
        cout << "Enter the nth number you want to find in Fibonacci by iteration: " << endl;
        cin >> itnum;
        cout << "Enter the nth number you want to find in Fibonacci by recursion: " << endl;
        cin >> recnum;
        double duration;
        clock_t startTime = clock();
        for (int i = 0; i < 1; ++i) {
            durationf(itnum, recnum);
        }

        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Execution took for iteration " << duration << " milliseconds." << endl;
        cout << "Execution took for recursion " << duration << " milliseconds." << endl;
        return 0;
    }


