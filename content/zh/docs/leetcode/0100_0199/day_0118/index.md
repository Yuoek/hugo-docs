---
title: "day_0118 "
date: 2025-09-21T10:22:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0118 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        f = [[1]]
        for i in range(numRows - 1):
            g = [1] + [a + b for a, b in pairwise(f[-1])] + [1]
            f.append(g)
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

## LeetCode_0118  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        f = [[1]]  # 初始化杨辉三角的第一行
        for i in range(numRows - 1):  # 循环生成剩余的行数
            g = [1] + [a + b for a, b in pairwise(f[-1])] + [1]  # 生成新行：首尾为1，中间为上一行相邻元素之和
            f.append(g)  # 将新行添加到结果列表中
        return f  # 返回完整的杨辉三角
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

## LeetCode_0118  数学解释

```python 
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        f = [[1]]
        for i in range(numRows - 1):
            g = [1] + [a + b for a, b in pairwise(f[-1])] + [1]
            f.append(g)
        return f 
```


这段代码使用了**动态规划**的数学思想来生成杨辉三角（帕斯卡三角）。

具体分析：

1. **状态定义**：`f[i]`表示第i行的数字列表（从0开始计数）

2. **初始状态**：第一行 `[1]`（`f = [[1]]`）

3. **状态转移方程**：
   - 每行的第一个和最后一个元素都是1
   - 中间元素：`g[j] = f[i-1][j-1] + f[i-1][j]`
   - 代码中通过`pairwise(f[-1])`实现相邻元素的配对求和

4. **数学原理**：利用组合数性质 C(n,k) = C(n-1,k-1) + C(n-1,k)

5. **递推关系**：基于前一行计算下一行，体现了动态规划的核心思想——利用已解决的子问题来构建更大问题的解

这种方法的数学优美之处在于：
- 时间复杂度：O(n²)，每个元素只计算一次
- 空间复杂度：O(n²)，存储整个三角形
- 充分利用了杨辉三角的对称性和递推性质


