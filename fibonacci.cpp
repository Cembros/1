#include <iostream>
using namespace std;
int fibonacci(int numb) {
    if (numb == 0) {
        return 0;
    } else if (numb == 1) {
        return 1;
    } else {

        return fibonacci(numb - 1) + fibonacci(numb - 2);
    }
}
int main() {
    for (int i = 0; i < 20; i++) {
        cout << "fib(" << i << ") = " << fibonacci(i) << endl;
    }
    return 0;
}
