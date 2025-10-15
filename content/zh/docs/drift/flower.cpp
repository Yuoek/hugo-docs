#include <iostream>

using namespace std;

int main(){

  int n, m;
  int a, b, c;
  cin >> n >> m;
  for(int i = 0; i < 10; i++){
    cout << i;
    for(int j = 0; j < 10; j++){
      cout << j;
      for(int k = 0; k < 10; k++)
        if(i*i*i + j*j*j + k*k*k == i*100 + j*10 + k){
          cout << i << j << k;
        }
    }
  }

  return 0;
}
