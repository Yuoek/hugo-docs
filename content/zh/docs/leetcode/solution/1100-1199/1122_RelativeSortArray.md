---
title: "1122_RelativeSortArray"
date: 2025-10-06T00:42:37+08:00
weight: 1122
tags: [数组, 哈希表, 计数排序, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1122. 数组的相对排序](https://leetcode.cn/problems/relative-sort-array)

[English Version](../en/1122-22/1122_RelativeSortArray)

## 题目描述

<!-- description:start -->

<p>给你两个数组，<code>arr1</code> 和&nbsp;<code>arr2</code>，<code>arr2</code>&nbsp;中的元素各不相同，<code>arr2</code> 中的每个元素都出现在&nbsp;<code>arr1</code>&nbsp;中。</p>

<p>对 <code>arr1</code>&nbsp;中的元素进行排序，使 <code>arr1</code> 中项的相对顺序和&nbsp;<code>arr2</code>&nbsp;中的相对顺序相同。未在&nbsp;<code>arr2</code>&nbsp;中出现过的元素需要按照升序放在&nbsp;<code>arr1</code>&nbsp;的末尾。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
<strong>输出：</strong>[2,2,2,1,4,3,3,9,6,7,19]
</pre>

<p><strong>示例 &nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
<strong>输出：</strong>[22,28,8,6,17,44]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 1000</code></li>
	<li><code>arr2</code>&nbsp;中的元素&nbsp;<code>arr2[i]</code>&nbsp;&nbsp;<strong>各不相同</strong>&nbsp;</li>
	<li><code>arr2</code> 中的每个元素&nbsp;<code>arr2[i]</code>&nbsp;都出现在&nbsp;<code>arr1</code>&nbsp;中</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们先用哈希表 $pos$ 记录数组 $arr2$ 中每个元素的位置。然后，我们将数组 $arr1$ 中的每个元素映射成一个二元组 $(pos.get(x, 1000 + x), x)$，并对二元组进行排序。最后我们取出所有二元组的第二个元素并返回即可。

时间复杂度 $O(n \times \log n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是数组 $arr1$ 和 $arr2$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Swift



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数排序

我们可以使用计数排序的思想，首先统计数组 $arr1$ 中每个元素的出现次数，然后按照数组 $arr2$ 中的顺序，将 $arr1$ 中的元素按照出现次数放入答案数组 $ans$ 中。最后，我们遍历 $arr1$ 中的所有元素，将未在 $arr2$ 中出现的元素按照升序放入答案数组 $ans$ 的末尾。

时间复杂度 $O(n + m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $arr1$ 和 $arr2$ 的长度。

<!-- solution:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Swift



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cnt = Counter(arr1)
        ans = []
        for x in arr2:
            ans.extend([x] * cnt[x])
            cnt.pop(x)
        mi, mx = min(arr1), max(arr1)
        for x in range(mi, mx + 1):
            ans.extend([x] * cnt[x])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt = new int[1001];
        int mi = 1001, mx = 0;
        for (int x : arr1) {
            ++cnt[x];
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        int m = arr1.length;
        int[] ans = new int[m];
        int i = 0;
        for (int x : arr2) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        for (int x = mi; x <= mx; ++x) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001);
        for (int x : arr1) {
            ++cnt[x];
        }
        auto [mi, mx] = minmax_element(arr1.begin(), arr1.end());
        vector<int> ans;
        for (int x : arr2) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        for (int x = *mi; x <= *mx; ++x) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func relativeSortArray(arr1 []int, arr2 []int) []int {
	cnt := make([]int, 1001)
	mi, mx := 1001, 0
	for _, x := range arr1 {
		cnt[x]++
		mi = min(mi, x)
		mx = max(mx, x)
	}
	ans := make([]int, 0, len(arr1))
	for _, x := range arr2 {
		for cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	for x := mi; x <= mx; x++ {
		for cnt[x] > 0 {
			ans = append(ans, x)
			cnt[x]--
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function relativeSortArray(arr1: number[], arr2: number[]): number[] {
    const cnt = Array(1001).fill(0);
    let mi = Number.POSITIVE_INFINITY;
    let mx = Number.NEGATIVE_INFINITY;

    for (const x of arr1) {
        cnt[x]++;
        mi = Math.min(mi, x);
        mx = Math.max(mx, x);
    }

    const ans: number[] = [];
    for (const x of arr2) {
        while (cnt[x]) {
            cnt[x]--;
            ans.push(x);
        }
    }

    for (let i = mi; i <= mx; i++) {
        while (cnt[i]) {
            cnt[i]--;
            ans.push(i);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func relativeSortArray(_ arr1: [Int], _ arr2: [Int]) -> [Int] {
        var cnt = [Int](repeating: 0, count: 1001)
        for x in arr1 {
            cnt[x] += 1
        }

        guard let mi = arr1.min(), let mx = arr1.max() else {
            return []
        }

        var ans = [Int]()
        for x in arr2 {
            while cnt[x] > 0 {
                ans.append(x)
                cnt[x] -= 1
            }
        }

        for x in mi...mx {
            while cnt[x] > 0 {
                ans.append(x)
                cnt[x] -= 1
            }
        }

        return ans
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        cnt = Counter(arr1)
        ans = []
        for x in arr2:
            ans.extend([x] * cnt[x])
            cnt.pop(x)
        mi, mx = min(arr1), max(arr1)
        for x in range(mi, mx + 1):
            ans.extend([x] * cnt[x])
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] cnt = new int[1001];
        int mi = 1001, mx = 0;
        for (int x : arr1) {
            ++cnt[x];
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        int m = arr1.length;
        int[] ans = new int[m];
        int i = 0;
        for (int x : arr2) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        for (int x = mi; x <= mx; ++x) {
            while (cnt[x] > 0) {
                --cnt[x];
                ans[i++] = x;
            }
        }
        return ans;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> cnt(1001);
        for (int x : arr1) {
            ++cnt[x];
        }
        auto [mi, mx] = minmax_element(arr1.begin(), arr1.end());
        vector<int> ans;
        for (int x : arr2) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        for (int x = *mi; x <= *mx; ++x) {
            while (cnt[x]) {
                ans.push_back(x);
                --cnt[x];
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}