---
title: "0845_LongestMountaininArray"
date: 2025-10-06T00:42:37+08:00
weight: 0845
tags: [Array, Two Pointers, Dynamic Programming, Enumeration]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [845. Longest Mountain in Array](https://leetcode.com/problems/longest-mountain-in-array)

[中文文档](/solution/0800-0899/0845.Longest%20Mountain%20in%20Array/README.md)

## Description

<!-- description:start -->

<p>You may recall that an array <code>arr</code> is a <strong>mountain array</strong> if and only if:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some index <code>i</code> (<strong>0-indexed</strong>) with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>Given an integer array <code>arr</code>, return <em>the length of the longest subarray, which is a mountain</em>. Return <code>0</code> if there is no mountain subarray.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,1,4,7,3,2,5]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The largest mountain is [1,4,7,3,2] which has length 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [2,2,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no mountain.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>Can you solve it using only one pass?</li>
	<li>Can you solve it in <code>O(1)</code> space?</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        ans = l = 0
        while l + 2 < n:
            r = l + 1
            if arr[l] < arr[r]:
                while r + 1 < n and arr[r] < arr[r + 1]:
                    r += 1
                if r < n - 1 and arr[r] > arr[r + 1]:
                    while r < n - 1 and arr[r] > arr[r + 1]:
                        r += 1
                    ans = max(ans, r - l + 1)
                else:
                    r += 1
            l = r
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = Math.max(ans, r - l + 1);
                } else {
                    ++r;
                }
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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = max(ans, r - l + 1);
                } else {
                    ++r;
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestMountain(arr []int) (ans int) {
	n := len(arr)
	for l, r := 0, 0; l+2 < n; l = r {
		r = l + 1
		if arr[l] < arr[r] {
			for r+1 < n && arr[r] < arr[r+1] {
				r++
			}
			if r+1 < n && arr[r] > arr[r+1] {
				for r+1 < n && arr[r] > arr[r+1] {
					r++
				}
				ans = max(ans, r-l+1)
			} else {
				r++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        ans = l = 0
        while l + 2 < n:
            r = l + 1
            if arr[l] < arr[r]:
                while r + 1 < n and arr[r] < arr[r + 1]:
                    r += 1
                if r < n - 1 and arr[r] > arr[r + 1]:
                    while r < n - 1 and arr[r] > arr[r + 1]:
                        r += 1
                    ans = max(ans, r - l + 1)
                else:
                    r += 1
            l = r
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestMountain(int[] arr) {
        int n = arr.length;
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = Math.max(ans, r - l + 1);
                } else {
                    ++r;
                }
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
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int l = 0, r = 0; l + 2 < n; l = r) {
            r = l + 1;
            if (arr[l] < arr[r]) {
                while (r + 1 < n && arr[r] < arr[r + 1]) {
                    ++r;
                }
                if (r + 1 < n && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) {
                        ++r;
                    }
                    ans = max(ans, r - l + 1);
                } else {
                    ++r;
                }
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}