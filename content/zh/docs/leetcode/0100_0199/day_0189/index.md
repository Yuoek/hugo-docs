---
title: "day_0189 "
date: 2025-09-21T08:08:15+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0189 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i: int, j: int):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1

        n = len(nums)
        k %= n
        reverse(0, n - 1)
        reverse(0, k - 1)
        reverse(k, n - 1) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int[] nums;

    public void rotate(int[] nums, int k) {
        this.nums = nums;
        int n = nums.length;
        k %= n;
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    private void reverse(int i, int j) {
        for (; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0189  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i: int, j: int):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]  # 交换数组两端的元素
                i, j = i + 1, j - 1  # 移动指针向中间靠拢

        n = len(nums)  # 获取数组长度
        k %= n  # 处理k大于数组长度的情况，取模运算
        reverse(0, n - 1)  # 第一步：反转整个数组
        reverse(0, k - 1)  # 第二步：反转前k个元素
        reverse(k, n - 1)  # 第三步：反转剩余的元素
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int[] nums;

    public void rotate(int[] nums, int k) {
        this.nums = nums;
        int n = nums.length;
        k %= n;
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    private void reverse(int i, int j) {
        for (; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0189  数学解释

```python 
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i: int, j: int):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1

        n = len(nums)
        k %= n
        reverse(0, n - 1)
        reverse(0, k - 1)
        reverse(k, n - 1) 
```


这段代码使用了**数组反转**的数学思想来解决数组旋转问题。具体来说：

**核心数学思想：**
1. **模运算**：`k %= n` 确保旋转次数k在数组长度n的范围内，避免不必要的重复旋转
2. **反转操作的组合性**：通过三次反转操作实现数组旋转的效果

**数学原理分解：**
- 原始数组：`[a₀, a₁, ..., aₙ₋₁]`
- 目标数组：`[aₙ₋ₖ, aₙ₋ₖ₊₁, ..., aₙ₋₁, a₀, a₁, ..., aₙ₋ₖ₋₁]`

**三步反转法的数学证明：**
1. `reverse(0, n-1)` → `[aₙ₋₁, aₙ₋₂, ..., a₀]`
2. `reverse(0, k-1)` → `[aₙ₋ₖ, aₙ₋ₖ₊₁, ..., aₙ₋₁, aₙ₋ₖ₋₁, ..., a₀]`
3. `reverse(k, n-1)` → `[aₙ₋ₖ, aₙ₋ₖ₊₁, ..., aₙ₋₁, a₀, a₁, ..., aₙ₋ₖ₋₁]`

**数学优势：**
- 时间复杂度：O(n) - 每个元素被交换约n/2次
- 空间复杂度：O(1) - 原地操作，只使用常数额外空间
- 避免了使用额外数组的O(n)空间复杂度

这种解法体现了**通过基本操作的组合来解决复杂问题**的数学思维，是分治思想和对称性原理的巧妙应用。

