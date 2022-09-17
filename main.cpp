#include <iostream>
#include "timercpp.h"

using namespace std;

int main() {
    Timer t = Timer();
    int count = 1;
    // 固定延遲循環
    t.setInterval([&]() {
        cout << "Hey.. After each 1s... " << count++ << endl;
    }, 1000);
    while(true); // Keep main thread active  
}