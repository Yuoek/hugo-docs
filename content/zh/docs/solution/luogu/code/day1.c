// #include <stdio.h> 
// int main(){
//   int m, n;
//   int cnt1 = 0, cnt2 = 0;
//   int sum1 = 0, sum2 = 0;
//   while(scanf("%d%d", &m, &n) != 0){
//     for(int i = 1; i <= m; i++){
//       if(i % n == 0){
//         cnt1++;
//         sum1 += i;
//
//       }
//       else {
//         cnt2++;
//         sum2 += i;
//       }
//     }
//     printf("%.1f %.1f", (double)sum1 / cnt1, (double)sum2 / cnt2);
//
//   }
// }


#include <stdio.h> 
int main(){
  int m, n;
  int cnt1 = 0, cnt2 = 0;
  int sum1 = 0, sum2 = 0;
  scanf("%d%d", &m, &n);
  for(int i = 1; i <= m; i++){
    if(i % n == 0){
      cnt1++;
      sum1 += i;

    }
    else {
      cnt2++;
      sum2 += i;
    }
  }
  printf("%.1f %.1f", (double)sum1 / cnt1, (double)sum2 / cnt2);

}
