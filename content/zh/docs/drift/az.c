
#include <stdio.h> 

void az();
int main(){
    int a=10;
    int b=10;
    int c=10;
    char num = 'a';
    printf("a=%d, b=%d, c=%d\n", a, b, c);
    printf("%d\n", num);
    az();
    return 0;
}

void az(){
    int i;
    int n=127;
    for (i=-128;i<n;i++){
        printf("%d = %c\n", i, i);
    }
}
