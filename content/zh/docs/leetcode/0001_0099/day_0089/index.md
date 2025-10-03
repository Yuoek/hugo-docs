---
title: "day_0089 "
date: 2025-09-13T21:53:44+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0089 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [i ^ (i >> 1) for i in range(1 << n)] 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < 1 << n; ++i) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            ans.add(i ^ (i >> 1));
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0089  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def grayCode(self, n: int) -> List[int]:
        # 使用列表推导生成 Gray Code 序列。
        # Gray Code 是一种二进制编码，其中相邻两个数的二进制表示只有一位不同。
        # `1 << n` 表示 2 的 n 次方，用于生成从 0 到 2^n - 1 的整数。
        # `i ^ (i >> 1)` 是生成 Gray Code 的公式，`i` 是当前整数，`i >> 1` 是将 `i` 的二进制右移一位。
        # 使用按位异或运算 `^` 可以得到 Gray Code。
        return [i ^ (i >> 1) for i in range(1 << n)]  # 返回长度为 2^n 的 Gray Code 序列。
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < 1 << n; ++i) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            ans.add(i ^ (i >> 1));
        }
        return ans;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0089  数学解释

```python 
class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [i ^ (i >> 1) for i in range(1 << n)] 
```


这段代码生成了一个长度为 \\(2^n\\) 的格雷码序列（Gray Code）。格雷码是一种特殊的二进制编码，其中相邻的两个数只有一位二进制位不同。我们可以用数学思想来解释这段代码的逻辑。

### 数学思想解析

#### 1. **格雷码的定义**
格雷码是一种二进制编码，它满足：
- 两个相邻的数之间只有一位不同。
- 它可以通过公式 \\(G(i) = i \oplus (i \gg 1)\\) 生成，其中：
  - \\(i\\) 是当前数字的普通二进制表示。
  - \\(\oplus\\) 是按位异或运算。
  - \\(i \gg 1\\) 表示将 \\(i\\) 的二进制向右移动一位。

#### 2. **生成格雷码的数学原理**
格雷码的生成公式 \\\(G(i) = i \oplus (i \gg 1)\\\) 是基于以下数学思想：
- \\(i \gg 1\\) 将二进制数 \\(i\\) 的每一位向右移动一位。
- 按位异或操作 \\(\oplus\\) 会比较两个数的二进制位：
  - 如果两个位相同，结果为 0。
  - 如果两个位不同，结果为 1。
- 因此，通过异或操作，我们可以确保相邻的数只有一位不同。

#### 3. **代码分步解析**
```python
return [i ^ (i >> 1) for i in range(1 << n)]
```
- `range(1 << n)`:
  - \\(1 << n\\) 是 \\(2^n\\)，表示我们需要生成 \\(2^n\\) 个格雷码。
  - `range(1 << n)` 生成从 0 到 \\(2^n - 1\\) 的所有整数。
- `[i ^ (i >> 1) for i in range(1 << n)]`:
  - 对每个整数 \\(i\\)，计算 \\(i \oplus (i \gg 1)\\)，得到对应的格雷码。
  - 通过列表推导式生成一个长度为 \\(2^n\\) 的格雷码序列。

#### 4. **数学上的格雷码性质**
对于任意整数 \\(i\\)，通过公式 \\(G(i) = i \oplus (i \gg 1)\\) 生成的格雷码具有以下性质：
- 如果 \\(i\\) 和 \\(i+1\\) 是两个连续的整数，则 \\(G(i)\\) 和 \\(G(i+1)\\) 的二进制表示只有一位不同。
- 格雷码是一种循环序列：对于 \\(G(0)\\) 和 \\(G(2^n - 1)\\)，它们的二进制表示也只有一位不同。

### 示例计算
假设 \\(n = 2\\)，我们需要生成 \\(2^2 = 4\\) 个格雷码。
- \\(i = 0\\): \\(G(0) = 0 \oplus (0 \gg 1) = 0 \oplus 0 = 0\\)
- \\(i = 1\\): \\(G(1) = 1 \oplus (1 \gg 1) = 1 \oplus 0 = 1\\)
- \\(i = 2\\): \\(G(2) = 2 \oplus (2 \gg 1) = 10 \oplus 01 = 11 = 3\\)
- \\(i = 3\\): \\(G(3) = 3 \oplus (3 \gg 1) = 11 \oplus 01 = 10 = 2\\)

结果格雷码序列为 \\([0, 1, 3, 2]\\)。

### 总结
这段代码利用数学公式 \\(G(i) = i \oplus (i \gg 1)\\) 高效地生成了格雷码序列，体现了数学与编程的结合。格雷码在数字电路设计和编码理论中有广泛应用。

