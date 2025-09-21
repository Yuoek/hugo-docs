---
title: "day_0169 "
date: 2025-09-21T08:52:14+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0169 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = m = 0
        for x in nums:
            if cnt == 0:
                m, cnt = x, 1
            else:
                cnt += 1 if m == x else -1
        return m 
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

## LeetCode_0169  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = m = 0  # 初始化计数器和候选众数
        for x in nums:  # 遍历数组中的每个元素
            if cnt == 0:  # 如果计数器为0，选择当前元素作为候选众数
                m, cnt = x, 1  # 设置候选众数并将计数器设为1
            else:
                cnt += 1 if m == x else -1  # 如果当前元素等于候选众数，计数器加1，否则减1
        return m  # 返回找到的众数
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

## LeetCode_0169  数学解释

```python 
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnt = m = 0
        for x in nums:
            if cnt == 0:
                m, cnt = x, 1
            else:
                cnt += 1 if m == x else -1
        return m 
```


这段代码实现了**摩尔投票算法（Boyer-Moore Voting Algorithm）**，用于在O(n)时间复杂度和O(1)空间复杂度内找到数组中的多数元素（出现次数超过n/2的元素）。

## 数学思想解释：

### 1. **对消原理（Cancellation Principle）**
算法基于一个核心思想：**多数元素的数量优势不会被其他元素完全抵消**。

- 将数组看作两军对垒：多数元素为一军，其他所有元素为另一军
- 每次遇到不同元素就相当于一次"对消"
- 由于多数元素的数量超过总数的一半，最终剩下的必然是多数元素

### 2. **数学建模**
设：
- `m`：当前候选多数元素
- `cnt`：当前候选元素的净优势（正数表示优势）

遍历过程：
- 当`cnt == 0`时，说明前面的元素已经相互抵消，重新选择候选
- 遇到相同元素：`cnt += 1`（增强优势）
- 遇到不同元素：`cnt -= 1`（削弱优势）

### 3. **数学证明**
假设多数元素出现k次，其他元素出现n-k次，且k > n/2。

最坏情况下，多数元素每次遇到不同元素都会被抵消一次，但最终剩余的优势为：
`剩余优势 = k - (n - k) = 2k - n > 0`（因为k > n/2）

因此算法一定能正确找到多数元素。

### 4. **算法特点**
- **时间复杂度**：O(n) - 单次遍历
- **空间复杂度**：O(1) - 只使用常数空间
- **正确性**：数学上严格保证，只要存在多数元素就一定能找到

这种算法巧妙地将计数问题转化为优势积累问题，体现了数学中"抵消"和"优势积累"的思想。
