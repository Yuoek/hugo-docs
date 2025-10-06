---
title: "1122_RelativeSortArray"
date: 2025-10-06T00:42:37+08:00
weight: 1122
tags: [Array, Hash Table, Counting Sort, Sorting]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [1122. Relative Sort Array](https://leetcode.com/problems/relative-sort-array)

[中文文档](/solution/1100-1199/1122.Relative%20Sort%20Array/README.md)

## Description

<!-- description:start -->

<p>Given two arrays <code>arr1</code> and <code>arr2</code>, the elements of <code>arr2</code> are distinct, and all elements in <code>arr2</code> are also in <code>arr1</code>.</p>

<p>Sort the elements of <code>arr1</code> such that the relative ordering of items in <code>arr1</code> are the same as in <code>arr2</code>. Elements that do not appear in <code>arr2</code> should be placed at the end of <code>arr1</code> in <strong>ascending</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
<strong>Output:</strong> [2,2,2,1,4,3,3,9,6,7,19]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
<strong>Output:</strong> [22,28,8,6,17,44]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr1.length, arr2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr1[i], arr2[i] &lt;= 1000</code></li>
	<li>All the elements of <code>arr2</code> are <strong>distinct</strong>.</li>
	<li>Each&nbsp;<code>arr2[i]</code> is in <code>arr1</code>.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Custom Sorting

First, we use a hash table $pos$ to record the position of each element in array $arr2$. Then, we map each element in array $arr1$ to a tuple $(pos.get(x, 1000 + x), x)$, and sort these tuples. Finally, we take out the second element of all tuples and return it.

The time complexity is $O(n \times \log n + m)$, and the space complexity is $O(n + m)$. Here, $n$ and $m$ are the lengths of arrays $arr1$ and $arr2$, respectively.

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

### Solution 2: Counting Sort

We can use the idea of counting sort. First, count the occurrence of each element in array $arr1$. Then, according to the order in array $arr2$, put the elements in $arr1$ into the answer array $ans$ according to their occurrence. Finally, we traverse all elements in $arr1$ and put the elements that do not appear in $arr2$ in ascending order at the end of the answer array $ans$.

The time complexity is $O(n + m)$, and the space complexity is $O(n)$. Where $n$ and $m$ are the lengths of arrays $arr1$ and $arr2$ respectively.

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