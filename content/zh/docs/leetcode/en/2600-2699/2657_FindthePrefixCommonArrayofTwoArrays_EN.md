---
title: "2657_FindthePrefixCommonArrayofTwoArrays"
date: 2025-10-06T00:42:37+08:00
weight: 2657
tags: [Bit Manipulation, Array, Hash Table]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [2657. Find the Prefix Common Array of Two Arrays](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays)

[中文文档](/solution/2600-2699/2657.Find%20the%20Prefix%20Common%20Array%20of%20Two%20Arrays/README.md)

## Description

<!-- description:start -->

<p>You are given two <strong>0-indexed </strong>integer<strong> </strong>permutations <code>A</code> and <code>B</code> of length <code>n</code>.</p>

<p>A <strong>prefix common array</strong> of <code>A</code> and <code>B</code> is an array <code>C</code> such that <code>C[i]</code> is equal to the count of numbers that are present at or before the index <code>i</code> in both <code>A</code> and <code>B</code>.</p>

<p>Return <em>the <strong>prefix common array</strong> of </em><code>A</code><em> and </em><code>B</code>.</p>

<p>A sequence of <code>n</code> integers is called a&nbsp;<strong>permutation</strong> if it contains all integers from <code>1</code> to <code>n</code> exactly once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> A = [1,3,2,4], B = [3,1,2,4]
<strong>Output:</strong> [0,2,3,4]
<strong>Explanation:</strong> At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> A = [2,3,1], B = [3,1,2]
<strong>Output:</strong> [0,1,3]
<strong>Explanation:</strong> At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= A.length == B.length == n &lt;= 50</code></li>
	<li><code>1 &lt;= A[i], B[i] &lt;= n</code></li>
	<li><code>It is guaranteed that A and B are both a permutation of n integers.</code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Counting

We can use two arrays $cnt1$ and $cnt2$ to record the occurrence times of each element in arrays $A$ and $B$ respectively, and use an array $ans$ to record the answer.

Traverse arrays $A$ and $B$, increment the occurrence times of $A[i]$ in $cnt1$, and increment the occurrence times of $B[i]$ in $cnt2$. Then enumerate $j \in [1,n]$, calculate the minimum occurrence times of each element $j$ in $cnt1$ and $cnt2$, and accumulate them into $ans[i]$.

After the traversal, return the answer array $ans$.

The time complexity is $O(n^2)$, and the space complexity is $O(n)$. Here, $n$ is the length of arrays $A$ and $B$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: Bit Operation (XOR Operation)

We can use an array $vis$ of length $n+1$ to record the occurrence situation of each element in arrays $A$ and $B$, the initial value of array $vis$ is $1$. In addition, we use a variable $s$ to record the current number of common elements.

Next, we traverse arrays $A$ and $B$, update $vis[A[i]] = vis[A[i]] \oplus 1$, and update $vis[B[i]] = vis[B[i]] \oplus 1$, where $\oplus$ represents XOR operation.

If at the current position, the element $A[i]$ has appeared twice (i.e., it has appeared in both arrays $A$ and $B$), then the value of $vis[A[i]]$ will be $1$, and we increment $s$. Similarly, if the element $B[i]$ has appeared twice, then the value of $vis[B[i]]$ will be $1$, and we increment $s$. Then add the value of $s$ to the answer array $ans$.

After the traversal, return the answer array $ans$.

The time complexity is $O(n)$, and the space complexity is $O(n)$. Here, $n$ is the length of arrays $A$ and $B$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3: Bit Manipulation (Space Optimization)

Since the elements of arrays $A$ and $B$ are in the range $[1, n]$ and do not exceed $50$, we can use an integer $x$ and an integer $y$ to represent the occurrence of each element in arrays $A$ and $B$, respectively. Specifically, we use the $i$-th bit of integer $x$ to indicate whether element $i$ has appeared in array $A$, and the $i$-th bit of integer $y$ to indicate whether element $i$ has appeared in array $B$.

The time complexity of this solution is $O(n)$, where $n$ is the length of arrays $A$ and $B$. The space complexity is $O(1)$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        x = y = 0
        for a, b in zip(A, B):
            x |= 1 << a
            y |= 1 << b
            ans.append((x & y).bit_count())
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            x |= 1L << A[i];
            y |= 1L << B[i];
            ans[i] = Long.bitCount(x & y);
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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        long long x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x |= (1LL << A[i]);
            y |= (1LL << B[i]);
            ans[i] = __builtin_popcountll(x & y);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findThePrefixCommonArray(A []int, B []int) []int {
	n := len(A)
	ans := make([]int, n)
	var x, y int
	for i := 0; i < n; i++ {
		x |= 1 << A[i]
		y |= 1 << B[i]
		ans[i] = bits.OnesCount(uint(x & y))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findThePrefixCommonArray(A: number[], B: number[]): number[] {
    const n = A.length;
    const ans: number[] = [];
    let [x, y] = [0n, 0n];
    for (let i = 0; i < n; i++) {
        x |= 1n << BigInt(A[i]);
        y |= 1n << BigInt(B[i]);
        ans.push(bitCount64(x & y));
    }
    return ans;
}

function bitCount64(i: bigint): number {
    i = i - ((i >> 1n) & 0x5555555555555555n);
    i = (i & 0x3333333333333333n) + ((i >> 2n) & 0x3333333333333333n);
    i = (i + (i >> 4n)) & 0x0f0f0f0f0f0f0f0fn;
    i = i + (i >> 8n);
    i = i + (i >> 16n);
    i = i + (i >> 32n);
    return Number(i & 0x7fn);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        ans = []
        x = y = 0
        for a, b in zip(A, B):
            x |= 1 << a
            y |= 1 << b
            ans.append((x & y).bit_count())
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n];
        long x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            x |= 1L << A[i];
            y |= 1L << B[i];
            ans[i] = Long.bitCount(x & y);
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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        long long x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            x |= (1LL << A[i]);
            y |= (1LL << B[i]);
            ans[i] = __builtin_popcountll(x & y);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}