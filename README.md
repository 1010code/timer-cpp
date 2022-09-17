# C++ 實現定時器功能

- setInterval() 是固定延遲了某段時間之後，執行對應的程式碼，並且不斷地重複定時被執行。

```c
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
```

- setTimeout() 的功能是在延遲了某段時間 (單位為毫秒) 之後，才去執行一次。

```c
#include <iostream>
#include "timercpp.h"

using namespace std;

int main() {
    Timer t = Timer();
    // 定時倒數
    t.setTimeout([&]() {
        cout << "Hey.. After 3s. But I will stop the timer!" << endl;
        t.stop();
    }, 3000);
    while(true); // Keep main thread active  
}
```


編譯時需要使用 `-pthread` flag。pthread 是 POSIX 下的執行緒標準，定義了創建和操縱執行緒的一套API。

```sh
g++ -o main ./main.cpp -pthread 
```

## Reference
- [c++ 實現一個js語法的定時器](https://www.jianshu.com/p/d0bf314f4f3b)
- [[GitHub] 99x/timercpp](https://github.com/99x/timercpp)