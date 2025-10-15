---
title: "草稿备忘"
bookFlatSection: false
date: 2025-09-02T09:11:26+08:00
---

## README 

-[ ] TODO


```cpp 
#include <iostream>
using namespace std;
int main(){
    int N = 15;
    int M = 0;
    int sum
    for(int i=1;i<=N;i++){

        M += M
    }
        cout << i  endl;
    

    
    cout << M;

    return 0;


}

```



```cpp 
#include <iostream>
using namespace std; 
int main(){
    float a=402, b=530, c=320, temp = 0;

    // cin >> a;
    // cin >> b;
    // cin >> c;
    if(a>b) temp = b;
    else temp = a; 
    if(temp>c) temp = c;
    cout << "最小的数为：" << temp;

    return 0;
    
}

```

以下是识别到的文字：
用 c++ 实现 
给出一个百分制成绩，要求输出成绩等级A、B、C、D、E。90分以上为A，80-89分为B，70-79分为C，60-69分为D，60分以下为E。要求：至少输入3个分数段的成绩并打印出对应的等级制成绩，并用switch与if语句分别完成。
 
输入格式：
输入3个分数段的成绩。
 
输出格式：
输出3个分数段的等级制成绩。
 
输入样例：
88
77
66
 
输出样例：
B
C
D


### LeetCode CN 

```c 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int arry[2] = {0};
    for(int i = 0;i < numsSize;i++){
        for(int j = 0;j < i;j++){
            //printf("nums[i]: %d, nums[j]:%d", nums[i], nums[j]);
            if(target == nums[i] + nums[j]){
                arry[] = {nums[i], nums[j]};
            }
               
        }
        
    }
    
    returna arry;
}

```
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(target == nums[i] + nums[j]) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    return NULL;
}
