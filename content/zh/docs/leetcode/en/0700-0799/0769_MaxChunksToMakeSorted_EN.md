---
title: "0769_MaxChunksToMakeSorted"
date: 2025-10-06T00:42:37+08:00
weight: 0769
tags: [Stack, Greedy, Array, Sorting, Monotonic Stack]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [769. Max Chunks To Make Sorted](https://leetcode.com/problems/max-chunks-to-make-sorted)

[中文文档](/solution/0700-0799/0769.Max%20Chunks%20To%20Make%20Sorted/README.md)

## Description

<!-- description:start -->

<p>You are given an integer array <code>arr</code> of length <code>n</code> that represents a permutation of the integers in the range <code>[0, n - 1]</code>.</p>

<p>We split <code>arr</code> into some number of <strong>chunks</strong> (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.</p>

<p>Return <em>the largest number of chunks we can make to sort the array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [4,3,2,1,0]
<strong>Output:</strong> 1
<strong>Explanation:</strong>
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn&#39;t sorted.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,0,2,3,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>0 &lt;= arr[i] &lt; n</code></li>
	<li>All the elements of <code>arr</code> are <strong>unique</strong>.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Greedy + One Pass

Since $\textit{arr}$ is a permutation of $[0,..,n-1]$, if the maximum value $\textit{mx}$ among the numbers traversed so far is equal to the current index $i$, it means a split can be made, and the answer is incremented.

Time complexity is $O(n)$, and space complexity is $O(1)$. Where $n$ is the length of the array $\textit{arr}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Monotonic Stack

The solution of method one has certain limitations. If there are duplicate elements in the array, the correct answer cannot be obtained.

According to the problem, we can find that from left to right, each chunk has a maximum value, and these maximum values are monotonically increasing. We can use a stack to store these maximum values of the chunks. The size of the final stack is the maximum number of chunks that can be sorted.

This solution can not only solve this problem but also solve the problem 768. Max Chunks To Make Sorted II. You can try it yourself.

Time complexity is $O(n)$, and space complexity is $O(n)$. Where $n$ is the length of the array $\textit{arr}$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stk = []
        for v in arr:
            if not stk or v >= stk[-1]:
                stk.append(v)
            else:
                mx = stk.pop()
                while stk and stk[-1] > v:
                    stk.pop()
                stk.append(mx)
        return len(stk)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : arr) {
            if (stk.isEmpty() || v >= stk.peek()) {
                stk.push(v);
            } else {
                int mx = stk.pop();
                while (!stk.isEmpty() && stk.peek() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int v : arr) {
            if (stk.empty() || v >= stk.top()) {
                stk.push(v);
            } else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxChunksToSorted(arr []int) int {
	stk := []int{}
	for _, v := range arr {
		if len(stk) == 0 || v >= stk[len(stk)-1] {
			stk = append(stk, v)
		} else {
			mx := stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			for len(stk) > 0 && stk[len(stk)-1] > v {
				stk = stk[:len(stk)-1]
			}
			stk = append(stk, mx)
		}
	}
	return len(stk)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxChunksToSorted(arr: number[]): number {
    const stk: number[] = [];

    for (const x of arr) {
        if (stk.at(-1)! > x) {
            const top = stk.pop()!;
            while (stk.length && stk.at(-1)! > x) stk.pop();
            stk.push(top);
        } else stk.push(x);
    }

    return stk.length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut mx = 0;
        for i in 0..arr.len() {
            mx = mx.max(arr[i]);
            if mx == (i as i32) {
                ans += 1;
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxChunksToSorted(int* arr, int arrSize) {
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < arrSize; i++) {
        mx = max(mx, arr[i]);
        if (mx == i) {
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function maxChunksToSorted(arr) {
    const stk = [];

    for (const x of arr) {
        if (stk.at(-1) > x) {
            const top = stk.pop();
            while (stk.length && stk.at(-1) > x) stk.pop();
            stk.push(top);
        } else stk.push(x);
    }

    return stk.length;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        stk = []
        for v in arr:
            if not stk or v >= stk[-1]:
                stk.append(v)
            else:
                mx = stk.pop()
                while stk and stk[-1] > v:
                    stk.pop()
                stk.append(mx)
        return len(stk)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        for (int v : arr) {
            if (stk.isEmpty() || v >= stk.peek()) {
                stk.push(v);
            } else {
                int mx = stk.pop();
                while (!stk.isEmpty() && stk.peek() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxChunksToSorted(int* arr, int arrSize) {
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < arrSize; i++) {
        mx = max(mx, arr[i]);
        if (mx == i) {
            ans++;
        }
    }
    return ans;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (int v : arr) {
            if (stk.empty() || v >= stk.top()) {
                stk.push(v);
            } else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > v) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}