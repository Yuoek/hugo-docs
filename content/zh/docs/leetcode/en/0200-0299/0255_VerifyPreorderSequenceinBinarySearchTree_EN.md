---
title: "0255_VerifyPreorderSequenceinBinarySearchTree"
date: 2025-10-06T00:42:37+08:00
weight: 0255
tags: [Stack, Tree, Binary Search Tree, Recursion, Array, Binary Tree, Monotonic Stack]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [255. Verify Preorder Sequence in Binary Search Tree 🔒](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree)

[中文文档](/solution/0200-0299/0255.Verify%20Preorder%20Sequence%20in%20Binary%20Search%20Tree/README.md)

## Description

<!-- description:start -->

<p>Given an array of <strong>unique</strong> integers <code>preorder</code>, return <code>true</code> <em>if it is the correct preorder traversal sequence of a binary search tree</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0255.Verify%20Preorder%20Sequence%20in%20Binary%20Search%20Tree/images/preorder-tree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>Input:</strong> preorder = [5,2,1,3,6]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> preorder = [5,2,6,1,3]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= preorder.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= preorder[i] &lt;= 10<sup>4</sup></code></li>
	<li>All the elements of <code>preorder</code> are <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do it using only constant space complexity?</p>

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

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        stk = []
        last = -inf
        for x in preorder:
            if x < last:
                return False
            while stk and stk[-1] < x:
                last = stk.pop()
            stk.append(x)
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        Deque<Integer> stk = new ArrayDeque<>();
        int last = Integer.MIN_VALUE;
        for (int x : preorder) {
            if (x < last) {
                return false;
            }
            while (!stk.isEmpty() && stk.peek() < x) {
                last = stk.poll();
            }
            stk.push(x);
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int last = INT_MIN;
        for (int x : preorder) {
            if (x < last) return false;
            while (!stk.empty() && stk.top() < x) {
                last = stk.top();
                stk.pop();
            }
            stk.push(x);
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func verifyPreorder(preorder []int) bool {
	var stk []int
	last := math.MinInt32
	for _, x := range preorder {
		if x < last {
			return false
		}
		for len(stk) > 0 && stk[len(stk)-1] < x {
			last = stk[len(stk)-1]
			stk = stk[0 : len(stk)-1]
		}
		stk = append(stk, x)
	}
	return true
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        stk = []
        last = -inf
        for x in preorder:
            if x < last:
                return False
            while stk and stk[-1] < x:
                last = stk.pop()
            stk.append(x)
        return True
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean verifyPreorder(int[] preorder) {
        Deque<Integer> stk = new ArrayDeque<>();
        int last = Integer.MIN_VALUE;
        for (int x : preorder) {
            if (x < last) {
                return false;
            }
            while (!stk.isEmpty() && stk.peek() < x) {
                last = stk.poll();
            }
            stk.push(x);
        }
        return true;
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
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int last = INT_MIN;
        for (int x : preorder) {
            if (x < last) return false;
            while (!stk.empty() && stk.top() < x) {
                last = stk.top();
                stk.pop();
            }
            stk.push(x);
        }
        return true;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}