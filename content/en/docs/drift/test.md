

## Cpp Test 

### 1 M=11+22+33+...+NN

```cpp
#include <iostream>

using namespace std;

// 1 ,2, 3, 4, ...,14  ,15
// 11,22,33,44,...,1414,1515
// 1*10^1+1,2*10^1+2, 1*10^2*4*10^1+n,
// 11,33,66,110,..,
int main(){
    int sum=0;
    for(int i=1;i<=15;i++){
        cout << i << i << endl;
        int j = (i/10)==1 ? 10 : 1;
        sum += i*10*j + i; 
        cout << sum<< endl;
    }

    return 0;
}

```
