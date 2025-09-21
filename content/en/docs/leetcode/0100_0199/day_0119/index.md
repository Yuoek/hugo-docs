---
title: "day_0119 "
date: 2025-09-21T10:21:01+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0119 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        f = [1] * (rowIndex + 1)
        for i in range(2, rowIndex + 1):
            for j in range(i - 1, 0, -1):
                f[j] += f[j - 1]
        return f 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0119  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        f = [1] * (rowIndex + 1)  # 初始化长度为rowIndex+1的数组，所有元素初始值为1
        for i in range(2, rowIndex + 1):  # 从第2行开始遍历到目标行
            for j in range(i - 1, 0, -1):  # 从后往前更新数组元素，避免覆盖前一个值
                f[j] += f[j - 1]  # 当前元素等于前一个元素加上当前元素的值
        return f  # 返回杨辉三角的第rowIndex行
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0119  数学解释

```python 
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        f = [1] * (rowIndex + 1)
        for i in range(2, rowIndex + 1):
            for j in range(i - 1, 0, -1):
                f[j] += f[j - 1]
        return f 
```


这段代码使用了**动态规划**的数学思想来生成杨辉三角的第rowIndex行。具体来说：

1. **状态定义**：f[j] 表示当前行第j个位置的值
2. **状态转移方程**：f[j] = f[j] + f[j-1]（即当前值等于上一行同位置值加上前一个位置值）
3. **空间优化**：通过从右向左遍历，避免了使用额外空间存储上一行的数据
4. **数学原理**：利用了组合数公式 C(n,k) = C(n,k-1) + C(n-1,k-1)

**关键数学洞察**：
- 杨辉三角的每个数都是其上方两个数之和
- 通过反向遍历（从右向左），可以在原地更新数组，确保计算当前值时使用的f[j-1]来自上一行（未更新的值）
- 时间复杂度：O(n²)，空间复杂度：O(n)

这种解法巧妙地利用了组合数的递推关系和动态规划的空间优化技巧。
