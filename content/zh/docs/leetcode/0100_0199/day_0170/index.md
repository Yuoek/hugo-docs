---
title: "day_0170 "
date: 2025-09-21T08:47:16+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0170 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class TwoSum:

    def __init__(self):
        self.cnt = defaultdict(int)

    def add(self, number: int) -> None:
        self.cnt[number] += 1

    def find(self, value: int) -> bool:
        for x, v in self.cnt.items():
            y = value - x
            if y in self.cnt and (x != y or v > 1):
                return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value) 
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

## LeetCode_0170  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class TwoSum:

    def __init__(self):
        self.cnt = defaultdict(int)  # 初始化一个默认值为0的字典，用于存储数字及其出现次数

    def add(self, number: int) -> None:
        self.cnt[number] += 1  # 将数字添加到字典中，并增加其计数

    def find(self, value: int) -> bool:
        for x, v in self.cnt.items():  # 遍历字典中的所有数字及其计数
            y = value - x  # 计算目标值与当前数字的差值
            if y in self.cnt and (x != y or v > 1):  # 如果差值存在且满足条件（两个不同数字或同一个数字但出现多次）
                return True  # 找到满足条件的数字对
        return False  # 未找到满足条件的数字对


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value) 
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

## LeetCode_0170  数学解释

```python 
class TwoSum:

    def __init__(self):
        self.cnt = defaultdict(int)

    def add(self, number: int) -> None:
        self.cnt[number] += 1

    def find(self, value: int) -> bool:
        for x, v in self.cnt.items():
            y = value - x
            if y in self.cnt and (x != y or v > 1):
                return True
        return False


# Your TwoSum object will be instantiated and called as such:
# obj = TwoSum()
# obj.add(number)
# param_2 = obj.find(value) 
```


这个代码实现了一个"两数之和"的数据结构，其数学思想基于**补数原理**和**集合论**：

## 核心数学思想

1. **补数原理**：对于任意目标值 `value`，寻找是否存在两个数 `x` 和 `y` 满足 `x + y = value`，这等价于对于每个已存储的数 `x`，检查其补数 `y = value - x` 是否也存在

2. **集合论**：使用字典 `cnt` 作为多重集合（允许重复元素的集合），记录每个数字的出现次数

## 数学细节

- **唯一性约束**：当 `x = y` 时，需要确保该数字至少出现两次（`v > 1`），否则不能使用同一个元素两次
- **存在性检查**：对于每个 `x`，检查其补数 `y` 是否存在于集合中，且满足 `x ≠ y` 或 `x = y` 但出现次数 ≥ 2

## 数学表示

设集合 S = {数字及其出现次数}，对于目标值 T：
∃ x ∈ S, ∃ y ∈ S 使得 x + y = T，且满足：
- 如果 x ≠ y，则 x 和 y 各至少出现一次
- 如果 x = y，则 x 至少出现两次

## 时间复杂度
- add操作：O(1) - 常数时间插入
- find操作：O(n) - 需要遍历所有元素检查补数

这种实现巧妙地利用了哈希表的高效查找特性，将两数之和问题转化为补数存在性检查问题。

