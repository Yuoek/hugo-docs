---
title: "day_0004 "
date: 2025-09-14T11:42:50+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0004 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def f(i: int, j: int, k: int) -> int:
            if i >= m:
                return nums2[j + k - 1]
            if j >= n:
                return nums1[i + k - 1]
            if k == 1:
                return min(nums1[i], nums2[j])
            p = k // 2
            x = nums1[i + p - 1] if i + p - 1 < m else inf
            y = nums2[j + p - 1] if j + p - 1 < n else inf
            return f(i + p, j, k - p) if x < y else f(i, j + p, k - p)

        m, n = len(nums1), len(nums2)
        a = f(0, 0, (m + n + 1) // 2)
        b = f(0, 0, (m + n + 2) // 2)
        return (a + b) / 2 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        function<int(int, int, int)> f = [&](int i, int j, int k) {
            if (i >= m) {
                return nums2[j + k - 1];
            }
            if (j >= n) {
                return nums1[i + k - 1];
            }
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }
            int p = k / 2;
            int x = i + p - 1 < m ? nums1[i + p - 1] : 1 << 30;
            int y = j + p - 1 < n ? nums2[j + p - 1] : 1 << 30;
            return x < y ? f(i + p, j, k - p) : f(i, j + p, k - p);
        };
        int a = f(0, 0, (m + n + 1) / 2);
        int b = f(0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int m;
    private int n;
    private int[] nums1;
    private int[] nums2;

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        m = nums1.length;
        n = nums2.length;
        this.nums1 = nums1;
        this.nums2 = nums2;
        int a = f(0, 0, (m + n + 1) / 2);
        int b = f(0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }

    private int f(int i, int j, int k) {
        if (i >= m) {
            return nums2[j + k - 1];
        }
        if (j >= n) {
            return nums1[i + k - 1];
        }
        if (k == 1) {
            return Math.min(nums1[i], nums2[j]);
        }
        int p = k / 2;
        int x = i + p - 1 < m ? nums1[i + p - 1] : 1 << 30;
        int y = j + p - 1 < n ? nums2[j + p - 1] : 1 << 30;
        return x < y ? f(i + p, j, k - p) : f(i, j + p, k - p);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0004  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def f(i: int, j: int, k: int) -> int:
            # 如果nums1已经遍历完，直接从nums2中取第k个元素
            if i >= m:
                return nums2[j + k - 1]
            # 如果nums2已经遍历完，直接从nums1中取第k个元素
            if j >= n:
                return nums1[i + k - 1]
            # 当k=1时，取两个数组当前元素的最小值
            if k == 1:
                return min(nums1[i], nums2[j])
            p = k // 2  # 每次比较k/2位置的元素
            # 获取nums1在i+p-1位置的元素，如果越界则设为无穷大
            x = nums1[i + p - 1] if i + p - 1 < m else inf
            # 获取nums2在j+p-1位置的元素，如果越界则设为无穷大
            y = nums2[j + p - 1] if j + p - 1 < n else inf
            # 比较两个数组的中间元素，舍弃较小元素所在数组的前半部分
            return f(i + p, j, k - p) if x < y else f(i, j + p, k - p)

        m, n = len(nums1), len(nums2)  # 获取两个数组的长度
        # 计算中位数的两个候选值（处理奇偶长度的情况）
        a = f(0, 0, (m + n + 1) // 2)  # 第一个中位数候选
        b = f(0, 0, (m + n + 2) // 2)  # 第二个中位数候选
        return (a + b) / 2  # 返回两个中位数的平均值
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        function<int(int, int, int)> f = [&](int i, int j, int k) {
            if (i >= m) {
                return nums2[j + k - 1];
            }
            if (j >= n) {
                return nums1[i + k - 1];
            }
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }
            int p = k / 2;
            int x = i + p - 1 < m ? nums1[i + p - 1] : 1 << 30;
            int y = j + p - 1 < n ? nums2[j + p - 1] : 1 << 30;
            return x < y ? f(i + p, j, k - p) : f(i, j + p, k - p);
        };
        int a = f(0, 0, (m + n + 1) / 2);
        int b = f(0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    private int m;
    private int n;
    private int[] nums1;
    private int[] nums2;

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        m = nums1.length;
        n = nums2.length;
        this.nums1 = nums1;
        this.nums2 = nums2;
        int a = f(0, 0, (m + n + 1) / 2);
        int b = f(0, 0, (m + n + 2) / 2);
        return (a + b) / 2.0;
    }

    private int f(int i, int j, int k) {
        if (i >= m) {
            return nums2[j + k - 1];
        }
        if (j >= n) {
            return nums1[i + k - 1];
        }
        if (k == 1) {
            return Math.min(nums1[i], nums2[j]);
        }
        int p = k / 2;
        int x = i + p - 1 < m ? nums1[i + p - 1] : 1 << 30;
        int y = j + p - 1 < n ? nums2[j + p - 1] : 1 << 30;
        return x < y ? f(i + p, j, k - p) : f(i, j + p, k - p);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0004  数学解释

```python 
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        def f(i: int, j: int, k: int) -> int:
            if i >= m:
                return nums2[j + k - 1]
            if j >= n:
                return nums1[i + k - 1]
            if k == 1:
                return min(nums1[i], nums2[j])
            p = k // 2
            x = nums1[i + p - 1] if i + p - 1 < m else inf
            y = nums2[j + p - 1] if j + p - 1 < n else inf
            return f(i + p, j, k - p) if x < y else f(i, j + p, k - p)

        m, n = len(nums1), len(nums2)
        a = f(0, 0, (m + n + 1) // 2)
        b = f(0, 0, (m + n + 2) // 2)
        return (a + b) / 2 
```


这段代码使用了**分治思想**和**二分查找**的数学思想来解决两个有序数组的中位数问题。

## 核心数学思想：

### 1. 分治思想 (Divide and Conquer)
- 将寻找第k小元素的问题分解为更小的子问题
- 每次递归调用处理规模减半的问题

### 2. 二分查找的变体
- 不是对单个数组进行二分，而是同时对两个数组进行"二分"
- 每次比较两个数组中第k/2位置的元素，排除不可能包含第k小元素的那一半

### 3. 数学归纳法
- 基础情况：当k=1时，直接比较两个数组当前的最小元素
- 递归步骤：通过比较两个数组的第k/2元素，确定下一步搜索的方向

## 具体数学原理：

设我们要找两个有序数组的第k小元素：
1. 比较nums1[i + k//2 - 1]和nums2[j + k//2 - 1]
2. 如果nums1的值较小，说明nums1的前k//2个元素都不可能是第k小元素，可以排除
3. 反之亦然，排除nums2的前k//2个元素
4. 在剩余部分中继续寻找第(k - k//2)小的元素

## 时间复杂度分析：
- 每次递归k值减半：O(logk)
- k最多为(m+n)/2：O(log(m+n))
- 空间复杂度：O(log(m+n))（递归栈深度）

这种解法巧妙地利用了有序数组的性质，通过二分排除大量不可能的元素，实现了高效的中位数查找。


