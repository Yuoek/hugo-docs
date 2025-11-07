#include <stdio.h>
int main(){
  int n;
  int t = 0; scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    int cnt = 1;
    int s = 1;
    int z = i;
    while(z != 0){  // 奇 !=0, 偶 ==0 ?   cnt ?= 0;
      int y = z % 10;
      if(y % 2 == cnt % 2){
        cnt++;
        s = s;
        z = z / 10;
      }
      else{
        s = -s;
        break;
      }
    }
    if(s == 1)
      t++;
  }
  printf("%d\n", t);

  return 0;
}
