
#include <stdio.h> 
int main(){
    int s, i, fact, n;
    scanf("%d", &n);
    for(i = 1, fact = 1, s = 0; i<= n; i++){
        fact *= i;
        s += fact;
    }
    printf("%d,%d\n", n, s);
    return 0;
}
