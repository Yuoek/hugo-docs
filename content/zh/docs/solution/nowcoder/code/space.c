
#include <stdio.h>
int main(){
    int n;
    while (scanf("%d", &n) != EOF){
  int l = n + 1;
  int m = n;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 2*(n - i)  ; j++){
      printf(" ");
    }
    for(int k = 1; k <= i; k++){
        printf("%d", n);
    }
    
    printf("\n");
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 2*i ; j++){
      printf(" ");
    }
    for(int k = n - i + 1; k > 0; k--){
        printf("%d", n);
    }
    
    printf("\n");
  }

    }
}
