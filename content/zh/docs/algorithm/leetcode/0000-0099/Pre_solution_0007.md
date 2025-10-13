---
title: "0061_旋转链表"
date: 2025-10-08T18:34:13+08:00
weight: 7
tags: [二分查找, 位运算, 动态规划, 双指针, 字符串, 数学, 数组, 模拟, 矩阵, 组合数学, 记忆化搜索, 链表]
---

{{< markmap >}}
### [0061_旋转链表](#61)
#### [链表](#61)
#### [双指针](#61)
### [0062_不同路径](#62)
#### [数学](#62)
#### [动态规划](#62)
#### [组合数学](#62)
### [0063_不同路径 II](#63)
#### [数组](#63)
#### [动态规划](#63)
#### [矩阵](#63)
### [0064_最小路径和](#64)
#### [数组](#64)
#### [动态规划](#64)
#### [矩阵](#64)
### [0065_有效数字](#65)
#### [字符串](#65)
### [0066_加一](#66)
#### [数组](#66)
#### [数学](#66)
### [0067_二进制求和](#67)
#### [位运算](#67)
#### [数学](#67)
#### [字符串](#67)
#### [模拟](#67)
### [0068_文本左右对齐](#68)
#### [数组](#68)
#### [字符串](#68)
#### [模拟](#68)
### [0069_x 的平方根](#69)
#### [数学](#69)
#### [二分查找](#69)
### [0070_爬楼梯](#70)
#### [记忆化搜索](#70)
#### [数学](#70)
#### [动态规划](#70)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0061_旋转链表
___
#### 链表
___
#### 双指针
---
### 0062_不同路径
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 0063_不同路径 II
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0064_最小路径和
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 0065_有效数字
___
#### 字符串
---
### 0066_加一
___
#### 数组
___
#### 数学
---
### 0067_二进制求和
___
#### 位运算
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0068_文本左右对齐
___
#### 数组
___
#### 字符串
___
#### 模拟
---
### 0069_x 的平方根
___
#### 数学
___
#### 二分查找
---
### 0070_爬楼梯
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 字符串 | 数学 |
| 数组 | 模拟 | 矩阵 |
| 组合数学 | 记忆化搜索 | 链表 |

# [61. 旋转链表](https://leetcode.cn/problems/rotate-list){#61}

{{< tabs "61" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        cur, n = head, 0
        while cur:
            n += 1
            cur = cur.next
        k %= n
        if k == 0:
            return head
        fast = slow = head
        for _ in range(k):
            fast = fast.next
        while fast.next:
            fast, slow = fast.next, slow.next

        ans = slow.next
        slow.next = None
        fast.next = head
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cur = head;
        int n = 0;
        for (; cur != null; cur = cur.next) {
            n++;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (k-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode ans = slow.next;
        slow.next = null;
        fast.next = head;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	cur := head
	n := 0
	for cur != nil {
		cur = cur.Next
		n++
	}
	k %= n
	if k == 0 {
		return head
	}
	fast, slow := head, head
	for i := 0; i < k; i++ {
		fast = fast.Next
	}
	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}
	ans := slow.Next
	slow.Next = nil
	fast.Next = head
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if (!head || !head.next) {
        return head;
    }
    let cur = head;
    let n = 0;
    while (cur) {
        cur = cur.next;
        ++n;
    }
    k %= n;
    if (k === 0) {
        return head;
    }
    let fast = head;
    let slow = head;
    while (k--) {
        fast = fast.next;
    }
    while (fast.next) {
        fast = fast.next;
        slow = slow.next;
    }
    const ans = slow.next;
    slow.next = null;
    fast.next = head;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn rotate_right(mut head: Option<Box<ListNode>>, mut k: i32) -> Option<Box<ListNode>> {
        if head.is_none() || k == 0 {
            return head;
        }
        let n = {
            let mut cur = &head;
            let mut res = 0;
            while cur.is_some() {
                cur = &cur.as_ref().unwrap().next;
                res += 1;
            }
            res
        };
        k = k % n;
        if k == 0 {
            return head;
        }

        let mut cur = &mut head;
        for _ in 0..n - k - 1 {
            cur = &mut cur.as_mut().unwrap().next;
        }
        let mut res = cur.as_mut().unwrap().next.take();
        cur = &mut res;
        while cur.is_some() {
            cur = &mut cur.as_mut().unwrap().next;
        }
        *cur = head.take();
        res
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        var cur = head;
        int n = 0;
        while (cur != null) {
            cur = cur.next;
            ++n;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        var fast = head;
        var slow = head;
        while (k-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        var ans = slow.next;
        slow.next = null;
        fast.next = head;
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头节点 <code>head</code> ，旋转链表，将链表每个节点向右移动&nbsp;<code>k</code><em>&nbsp;</em>个位置。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0061.Rotate%20List/images/rotate1.jpg" style="width: 450px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 2
<strong>输出：</strong>[4,5,1,2,3]
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0061.Rotate%20List/images/roate2.jpg" style="width: 305px; height: 350px;" />
<pre>
<strong>输入：</strong>head = [0,1,2], k = 4
<strong>输出：</strong>[2,0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 500]</code> 内</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针 + 链表拼接

我们先判断链表节点数是否小于 $2$，如果是，直接返回 $head$ 即可。

否则，我们先统计链表节点数 $n$，然后将 $k$ 对 $n$ 取模，得到 $k$ 的有效值。

如果 $k$ 的有效值为 $0$，说明链表不需要旋转，直接返回 $head$ 即可。

否则，我们用快慢指针，让快指针先走 $k$ 步，然后快慢指针同时走，直到快指针走到链表尾部，此时慢指针的下一个节点就是新的链表头节点。

最后，我们将链表拼接起来即可。

时间复杂度 $O(n)$，其中 $n$ 是链表节点数，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        cur, n = head, 0
        while cur:
            n += 1
            cur = cur.next
        k %= n
        if k == 0:
            return head
        fast = slow = head
        for _ in range(k):
            fast = fast.next
        while fast.next:
            fast, slow = fast.next, slow.next

        ans = slow.next
        slow.next = None
        fast.next = head
        return ans
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode cur = head;
        int n = 0;
        for (; cur != null; cur = cur.next) {
            n++;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (k-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode ans = slow.next;
        slow.next = null;
        fast.next = head;
        return ans;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        int n = 0;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (k--) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	cur := head
	n := 0
	for cur != nil {
		cur = cur.Next
		n++
	}
	k %= n
	if k == 0 {
		return head
	}
	fast, slow := head, head
	for i := 0; i < k; i++ {
		fast = fast.Next
	}
	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}
	ans := slow.Next
	slow.Next = nil
	fast.Next = head
	return ans
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function rotateRight(head: ListNode | null, k: number): ListNode | null {
    if (!head || !head.next) {
        return head;
    }
    let cur = head;
    let n = 0;
    while (cur) {
        cur = cur.next;
        ++n;
    }
    k %= n;
    if (k === 0) {
        return head;
    }
    let fast = head;
    let slow = head;
    while (k--) {
        fast = fast.next;
    }
    while (fast.next) {
        fast = fast.next;
        slow = slow.next;
    }
    const ans = slow.next;
    slow.next = null;
    fast.next = head;
    return ans;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn rotate_right(mut head: Option<Box<ListNode>>, mut k: i32) -> Option<Box<ListNode>> {
        if head.is_none() || k == 0 {
            return head;
        }
        let n = {
            let mut cur = &head;
            let mut res = 0;
            while cur.is_some() {
                cur = &cur.as_ref().unwrap().next;
                res += 1;
            }
            res
        };
        k = k % n;
        if k == 0 {
            return head;
        }

        let mut cur = &mut head;
        for _ in 0..n - k - 1 {
            cur = &mut cur.as_mut().unwrap().next;
        }
        let mut res = cur.as_mut().unwrap().next.take();
        cur = &mut res;
        while cur.is_some() {
            cur = &mut cur.as_mut().unwrap().next;
        }
        *cur = head.take();
        res
    }
}
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode RotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        var cur = head;
        int n = 0;
        while (cur != null) {
            cur = cur.next;
            ++n;
        }
        k %= n;
        if (k == 0) {
            return head;
        }
        var fast = head;
        var slow = head;
        while (k-- > 0) {
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        var ans = slow.next;
        slow.next = null;
        fast.next = head;
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [62. 不同路径](https://leetcode.cn/problems/unique-paths){#62}

{{< tabs "62" >}}

{{% tab "python" %}}
```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [1] * n
        for _ in range(1, m):
            for j in range(1, n):
                f[j] += f[j - 1]
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func uniquePaths(m int, n int) int {
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			f[j] += f[j-1]
		}
	}
	return f[n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function uniquePaths(m: number, n: number): number {
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[j] += f[j - 1];
        }
    }
    return f[n - 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let (m, n) = (m as usize, n as usize);
        let mut f = vec![1; n];
        for i in 1..m {
            for j in 1..n {
                f[j] += f[j - 1];
            }
        }
        f[n - 1]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function (m, n) {
    const f = Array(n).fill(1);
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[j] += f[j - 1];
        }
    }
    return f[n - 1];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个机器人位于一个 <code>m x n</code><em>&nbsp;</em>网格的左上角 （起始点在下图中标记为 “Start” ）。</p>

<p>机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。</p>

<p>问总共有多少条不同的路径？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0062.Unique%20Paths/images/1697422740-adxmsI-image.png" style="width: 400px; height: 183px;" />
<pre>
<strong>输入：</strong>m = 3, n = 7
<strong>输出：</strong>28</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 2
<strong>输出：</strong>3
<strong>解释：</strong>
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -&gt; 向下 -&gt; 向下
2. 向下 -&gt; 向下 -&gt; 向右
3. 向下 -&gt; 向右 -&gt; 向下
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>m = 7, n = 3
<strong>输出：</strong>28
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>m = 3, n = 3
<strong>输出：</strong>6</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li>题目数据保证答案小于等于 <code>2 * 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示从左上角走到 $(i, j)$ 的路径数量，初始时 $f[0][0] = 1$，答案为 $f[m - 1][n - 1]$。

考虑 $f[i][j]$：

-   如果 $i \gt 0$，那么 $f[i][j]$ 可以从 $f[i - 1][j]$ 走一步到达，因此 $f[i][j] = f[i][j] + f[i - 1][j]$；
-   如果 $j \gt 0$，那么 $f[i][j]$ 可以从 $f[i][j - 1]$ 走一步到达，因此 $f[i][j] = f[i][j] + f[i][j - 1]$。

因此，我们有如下的状态转移方程：

$$
f[i][j] = \begin{cases}
1 & i = 0, j = 0 \\
f[i - 1][j] + f[i][j - 1] & \textit{otherwise}
\end{cases}
$$

最终的答案即为 $f[m - 1][n - 1]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

我们注意到 $f[i][j]$ 仅与 $f[i - 1][j]$ 和 $f[i][j - 1]$ 有关，因此我们优化掉第一维空间，仅保留第二维空间，得到时间复杂度 $O(m \times n)$，空间复杂度 $O(n)$ 的实现。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[0] * n for _ in range(m)]
        f[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i:
                    f[i][j] += f[i - 1][j]
                if j:
                    f[i][j] += f[i][j - 1]
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int uniquePaths(int m, int n) {
        var f = new int[m][n];
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    f[i][j] += f[i - 1][j];
                }
                if (j > 0) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        f[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i) {
                    f[i][j] += f[i - 1][j];
                }
                if (j) {
                    f[i][j] += f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
```

#### Go

```go
func uniquePaths(m int, n int) int {
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	f[0][0] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i > 0 {
				f[i][j] += f[i-1][j]
			}
			if j > 0 {
				f[i][j] += f[i][j-1]
			}
		}
	}
	return f[m-1][n-1]
}
```

#### TypeScript

```ts
function uniquePaths(m: number, n: number): number {
    const f: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    f[0][0] = 1;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i > 0) {
                f[i][j] += f[i - 1][j];
            }
            if (j > 0) {
                f[i][j] += f[i][j - 1];
            }
        }
    }
    return f[m - 1][n - 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let (m, n) = (m as usize, n as usize);
        let mut f = vec![1; n];
        for i in 1..m {
            for j in 1..n {
                f[j] += f[j - 1];
            }
        }
        f[n - 1]
    }
}
```

#### JavaScript

```js
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function (m, n) {
    const f = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    f[0][0] = 1;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i > 0) {
                f[i][j] += f[i - 1][j];
            }
            if (j > 0) {
                f[i][j] += f[i][j - 1];
            }
        }
    }
    return f[m - 1][n - 1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[1] * n for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = f[i - 1][j] + f[i][j - 1]
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int uniquePaths(int m, int n) {
        var f = new int[m][n];
        for (var g : f) {
            Arrays.fill(g, 1);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; j++) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[m - 1][n - 1];
    }
};
```

#### Go

```go
func uniquePaths(m int, n int) int {
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = 1
		}
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			f[i][j] = f[i-1][j] + f[i][j-1]
		}
	}
	return f[m-1][n-1]
}
```

#### TypeScript

```ts
function uniquePaths(m: number, n: number): number {
    const f: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(1));
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}
```

#### JavaScript

```js
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function (m, n) {
    const f = Array(m)
        .fill(0)
        .map(() => Array(n).fill(1));
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [1] * n
        for _ in range(1, m):
            for j in range(1, n):
                f[j] += f[j - 1]
        return f[-1]
```

#### Java

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[j] += f[j - 1];
            }
        }
        return f[n - 1];
    }
};
```

#### Go

```go
func uniquePaths(m int, n int) int {
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			f[j] += f[j-1]
		}
	}
	return f[n-1]
}
```

#### TypeScript

```ts
function uniquePaths(m: number, n: number): number {
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[j] += f[j - 1];
        }
    }
    return f[n - 1];
}
```

#### JavaScript

```js
/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function (m, n) {
    const f = Array(n).fill(1);
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[j] += f[j - 1];
        }
    }
    return f[n - 1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [63. 不同路径 II](https://leetcode.cn/problems/unique-paths-ii){#63}

{{< tabs "63" >}}

{{% tab "python" %}}
```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        f = [[0] * n for _ in range(m)]
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                break
            f[i][0] = 1
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                break
            f[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    f[i][j] = f[i - 1][j] + f[i][j - 1]
        return f[-1][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[][] f = new int[m][n];
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	f := make([][]int, m)
	for i := 0; i < m; i++ {
		f[i] = make([]int, n)
	}
	for i := 0; i < m && obstacleGrid[i][0] == 0; i++ {
		f[i][0] = 1
	}
	for j := 0; j < n && obstacleGrid[0][j] == 0; j++ {
		f[0][j] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 0 {
				f[i][j] = f[i-1][j] + f[i][j-1]
			}
		}
	}
	return f[m-1][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        if (obstacleGrid[i][0] === 1) {
            break;
        }
        f[i][0] = 1;
    }
    for (let i = 0; i < n; i++) {
        if (obstacleGrid[0][i] === 1) {
            break;
        }
        f[0][i] = 1;
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        let mut f = vec![vec![0; n]; m];
        for i in 0..n {
            if obstacle_grid[0][i] == 1 {
                break;
            }
            f[0][i] = 1;
        }
        for i in 0..m {
            if obstacle_grid[i][0] == 1 {
                break;
            }
            f[i][0] = 1;
        }
        for i in 1..m {
            for j in 1..n {
                if obstacle_grid[i][j] == 1 {
                    continue;
                }
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        f[m - 1][n - 1]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function (obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        if (obstacleGrid[i][0] === 1) {
            break;
        }
        f[i][0] = 1;
    }
    for (let i = 0; i < n; i++) {
        if (obstacleGrid[0][i] === 1) {
            break;
        }
        f[0][i] = 1;
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个&nbsp;<code>m x n</code>&nbsp;的整数数组&nbsp;<code>grid</code>。一个机器人初始位于 <strong>左上角</strong>（即 <code>grid[0][0]</code>）。机器人尝试移动到 <strong>右下角</strong>（即 <code>grid[m - 1][n - 1]</code>）。机器人每次只能向下或者向右移动一步。</p>

<p>网格中的障碍物和空位置分别用 <code>1</code> 和 <code>0</code> 来表示。机器人的移动路径中不能包含 <strong>任何</strong>&nbsp;有障碍物的方格。</p>

<p>返回机器人能够到达右下角的不同路径数量。</p>

<p>测试用例保证答案小于等于 <code>2 * 10<sup>9</sup></code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0063.Unique%20Paths%20II/images/robot1.jpg" />
<pre>
<strong>输入：</strong>obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
<strong>输出：</strong>2
<strong>解释：</strong>3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 <code>2</code> 条不同的路径：
1. 向右 -&gt; 向右 -&gt; 向下 -&gt; 向下
2. 向下 -&gt; 向下 -&gt; 向右 -&gt; 向右
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0063.Unique%20Paths%20II/images/robot2.jpg" />
<pre>
<strong>输入：</strong>obstacleGrid = [[0,1],[0,0]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m ==&nbsp;obstacleGrid.length</code></li>
	<li><code>n ==&nbsp;obstacleGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>obstacleGrid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, j)$ 表示从网格 $(i, j)$ 到网格 $(m - 1, n - 1)$ 的路径数。其中 $m$ 和 $n$ 分别是网格的行数和列数。

函数 $\textit{dfs}(i, j)$ 的执行过程如下：

-   如果 $i \ge m$ 或者 $j \ge n$，或者 $\textit{obstacleGrid}[i][j] = 1$，则路径数为 $0$；
-   如果 $i = m - 1$ 且 $j = n - 1$，则路径数为 $1$；
-   否则，路径数为 $\textit{dfs}(i + 1, j) + \textit{dfs}(i, j + 1)$。

为了避免重复计算，我们可以使用记忆化搜索的方法。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            if i >= m or j >= n or obstacleGrid[i][j]:
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            return dfs(i + 1, j) + dfs(i, j + 1)

        m, n = len(obstacleGrid), len(obstacleGrid[0])
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private int[][] obstacleGrid;
    private int m;
    private int n;

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        m = obstacleGrid.length;
        n = obstacleGrid[0].length;
        this.obstacleGrid = obstacleGrid;
        f = new Integer[m][n];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (f[i][j] == null) {
            f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        }
        return f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n, -1));
        auto dfs = [&](this auto&& dfs, int i, int j) {
            if (i >= m || j >= n || obstacleGrid[i][j]) {
                return 0;
            }
            if (i == m - 1 && j == n - 1) {
                return 1;
            }
            if (f[i][j] == -1) {
                f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
            }
            return f[i][j];
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i >= m || j >= n || obstacleGrid[i][j] == 1 {
			return 0
		}
		if i == m-1 && j == n-1 {
			return 1
		}
		if f[i][j] == -1 {
			f[i][j] = dfs(i+1, j) + dfs(i, j+1)
		}
		return f[i][j]
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const f: number[][] = Array.from({ length: m }, () => Array(n).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i >= m || j >= n || obstacleGrid[i][j] === 1) {
            return 0;
        }
        if (i === m - 1 && j === n - 1) {
            return 1;
        }
        if (f[i][j] === -1) {
            f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        }
        return f[i][j];
    };
    return dfs(0, 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        let mut f = vec![vec![-1; n]; m];
        Self::dfs(0, 0, &obstacle_grid, &mut f)
    }

    fn dfs(i: usize, j: usize, obstacle_grid: &Vec<Vec<i32>>, f: &mut Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        if i >= m || j >= n || obstacle_grid[i][j] == 1 {
            return 0;
        }
        if i == m - 1 && j == n - 1 {
            return 1;
        }
        if f[i][j] != -1 {
            return f[i][j];
        }
        let down = Self::dfs(i + 1, j, obstacle_grid, f);
        let right = Self::dfs(i, j + 1, obstacle_grid, f);
        f[i][j] = down + right;
        f[i][j]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function (obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(-1));
    const dfs = (i, j) => {
        if (i >= m || j >= n || obstacleGrid[i][j] === 1) {
            return 0;
        }
        if (i === m - 1 && j === n - 1) {
            return 1;
        }
        if (f[i][j] === -1) {
            f[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
        }
        return f[i][j];
    };
    return dfs(0, 0);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以使用动态规划的方法，定义一个二维数组 $f$，其中 $f[i][j]$ 表示从网格 $(0,0)$ 到网格 $(i,j)$ 的路径数。

我们首先初始化 $f$ 的第一列和第一行的所有值，然后遍历其它行和列，有两种情况：

-   若 $\textit{obstacleGrid}[i][j] = 1$，说明路径数为 $0$，那么 $f[i][j] = 0$；
-   若 $\textit{obstacleGrid}[i][j] = 0$，则 $f[i][j] = f[i - 1][j] + f[i][j - 1]$。

最后返回 $f[m - 1][n - 1]$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        f = [[0] * n for _ in range(m)]
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                break
            f[i][0] = 1
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                break
            f[0][j] = 1
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    f[i][j] = f[i - 1][j] + f[i][j - 1]
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        int[][] f = new int[m][n];
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
            f[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
            f[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
```

#### Go

```go
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	m, n := len(obstacleGrid), len(obstacleGrid[0])
	f := make([][]int, m)
	for i := 0; i < m; i++ {
		f[i] = make([]int, n)
	}
	for i := 0; i < m && obstacleGrid[i][0] == 0; i++ {
		f[i][0] = 1
	}
	for j := 0; j < n && obstacleGrid[0][j] == 0; j++ {
		f[0][j] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if obstacleGrid[i][j] == 0 {
				f[i][j] = f[i-1][j] + f[i][j-1]
			}
		}
	}
	return f[m-1][n-1]
}
```

#### TypeScript

```ts
function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        if (obstacleGrid[i][0] === 1) {
            break;
        }
        f[i][0] = 1;
    }
    for (let i = 0; i < n; i++) {
        if (obstacleGrid[0][i] === 1) {
            break;
        }
        f[0][i] = 1;
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        let mut f = vec![vec![0; n]; m];
        for i in 0..n {
            if obstacle_grid[0][i] == 1 {
                break;
            }
            f[0][i] = 1;
        }
        for i in 0..m {
            if obstacle_grid[i][0] == 1 {
                break;
            }
            f[i][0] = 1;
        }
        for i in 1..m {
            for j in 1..n {
                if obstacle_grid[i][j] == 1 {
                    continue;
                }
                f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        f[m - 1][n - 1]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function (obstacleGrid) {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const f = Array.from({ length: m }, () => Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        if (obstacleGrid[i][0] === 1) {
            break;
        }
        f[i][0] = 1;
    }
    for (let i = 0; i < n; i++) {
        if (obstacleGrid[0][i] === 1) {
            break;
        }
        f[0][i] = 1;
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (obstacleGrid[i][j] === 1) {
                continue;
            }
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[m - 1][n - 1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [64. 最小路径和](https://leetcode.cn/problems/minimum-path-sum){#64}

{{< tabs "64" >}}

{{% tab "python" %}}
```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[0] * n for _ in range(m)]
        f[0][0] = grid[0][0]
        for i in range(1, m):
            f[i][0] = f[i - 1][0] + grid[i][0]
        for j in range(1, n):
            f[0][j] = f[0][j - 1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j]
        return f[-1][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minPathSum(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	f[0][0] = grid[0][0]
	for i := 1; i < m; i++ {
		f[i][0] = f[i-1][0] + grid[i][0]
	}
	for j := 1; j < n; j++ {
		f[0][j] = f[0][j-1] + grid[0][j]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
		}
	}
	return f[m-1][n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minPathSum(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    f[0][0] = grid[0][0];
    for (let i = 1; i < m; ++i) {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }
    for (let j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + grid[0][j];
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }
    return f[m - 1][n - 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_path_sum(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        for i in 1..m {
            grid[i][0] += grid[i - 1][0];
        }
        for i in 1..n {
            grid[0][i] += grid[0][i - 1];
        }
        for i in 1..m {
            for j in 1..n {
                grid[i][j] += grid[i][j - 1].min(grid[i - 1][j]);
            }
        }
        grid[m - 1][n - 1]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const f = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    f[0][0] = grid[0][0];
    for (let i = 1; i < m; ++i) {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }
    for (let j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + grid[0][j];
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }
    return f[m - 1][n - 1];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinPathSum(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[,] f = new int[m, n];
        f[0, 0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i, 0] = f[i - 1, 0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0, j] = f[0, j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i, j] = Math.Min(f[i - 1, j], f[i, j - 1]) + grid[i][j];
            }
        }
        return f[m - 1, n - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含非负整数的 <code><em>m</em>&nbsp;x&nbsp;<em>n</em></code>&nbsp;网格&nbsp;<code>grid</code> ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。</p>

<p><strong>说明：</strong>每次只能向下或者向右移动一步。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0064.Minimum%20Path%20Sum/images/minpath.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>grid = [[1,3,1],[1,5,1],[4,2,1]]
<strong>输出：</strong>7
<strong>解释：</strong>因为路径 1→3→1→1→1 的总和最小。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,2,3],[4,5,6]]
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示从左上角走到 $(i, j)$ 位置的最小路径和。初始时 $f[0][0] = grid[0][0]$，答案为 $f[m - 1][n - 1]$。

考虑 $f[i][j]$：

-   如果 $j = 0$，那么 $f[i][j] = f[i - 1][j] + grid[i][j]$；
-   如果 $i = 0$，那么 $f[i][j] = f[i][j - 1] + grid[i][j]$；
-   如果 $i \gt 0$ 且 $j \gt 0$，那么 $f[i][j] = \min(f[i - 1][j], f[i][j - 1]) + grid[i][j]$。

最后返回 $f[m - 1][n - 1]$ 即可。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[0] * n for _ in range(m)]
        f[0][0] = grid[0][0]
        for i in range(1, m):
            f[i][0] = f[i - 1][0] + grid[i][0]
        for j in range(1, n):
            f[0][j] = f[0][j - 1] + grid[0][j]
        for i in range(1, m):
            for j in range(1, n):
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j]
        return f[-1][-1]
```

#### Java

```java
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] f = new int[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int f[m][n];
        f[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[m - 1][n - 1];
    }
};
```

#### Go

```go
func minPathSum(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	f[0][0] = grid[0][0]
	for i := 1; i < m; i++ {
		f[i][0] = f[i-1][0] + grid[i][0]
	}
	for j := 1; j < n; j++ {
		f[0][j] = f[0][j-1] + grid[0][j]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j]
		}
	}
	return f[m-1][n-1]
}
```

#### TypeScript

```ts
function minPathSum(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const f: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    f[0][0] = grid[0][0];
    for (let i = 1; i < m; ++i) {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }
    for (let j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + grid[0][j];
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }
    return f[m - 1][n - 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn min_path_sum(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        for i in 1..m {
            grid[i][0] += grid[i - 1][0];
        }
        for i in 1..n {
            grid[0][i] += grid[0][i - 1];
        }
        for i in 1..m {
            for j in 1..n {
                grid[i][j] += grid[i][j - 1].min(grid[i - 1][j]);
            }
        }
        grid[m - 1][n - 1]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const f = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    f[0][0] = grid[0][0];
    for (let i = 1; i < m; ++i) {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }
    for (let j = 1; j < n; ++j) {
        f[0][j] = f[0][j - 1] + grid[0][j];
    }
    for (let i = 1; i < m; ++i) {
        for (let j = 1; j < n; ++j) {
            f[i][j] = Math.min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }
    return f[m - 1][n - 1];
};
```

#### C#

```cs
public class Solution {
    public int MinPathSum(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        int[,] f = new int[m, n];
        f[0, 0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            f[i, 0] = f[i - 1, 0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            f[0, j] = f[0, j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i, j] = Math.Min(f[i - 1, j], f[i, j - 1]) + grid[i][j];
            }
        }
        return f[m - 1, n - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [65. 有效数字](https://leetcode.cn/problems/valid-number){#65}

{{< tabs "65" >}}

{{% tab "python" %}}
```python
class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        i = 0
        if s[i] in '+-':
            i += 1
        if i == n:
            return False
        if s[i] == '.' and (i + 1 == n or s[i + 1] in 'eE'):
            return False
        dot = e = 0
        j = i
        while j < n:
            if s[j] == '.':
                if e or dot:
                    return False
                dot += 1
            elif s[j] in 'eE':
                if e or j == i or j == n - 1:
                    return False
                e += 1
                if s[j + 1] in '+-':
                    j += 1
                    if j == n - 1:
                        return False
            elif not s[j].isnumeric():
                return False
            j += 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isNumber(String s) {
        int n = s.length();
        int i = 0;
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            ++i;
        }
        if (i == n) {
            return false;
        }
        if (s.charAt(i) == '.'
            && (i + 1 == n || s.charAt(i + 1) == 'e' || s.charAt(i + 1) == 'E')) {
            return false;
        }
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s.charAt(j) == '.') {
                if (e > 0 || dot > 0) {
                    return false;
                }
                ++dot;
            } else if (s.charAt(j) == 'e' || s.charAt(j) == 'E') {
                if (e > 0 || j == i || j == n - 1) {
                    return false;
                }
                ++e;
                if (s.charAt(j + 1) == '+' || s.charAt(j + 1) == '-') {
                    if (++j == n - 1) {
                        return false;
                    }
                }
            } else if (s.charAt(j) < '0' || s.charAt(j) > '9') {
                return false;
            }
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
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == n) return false;
        if (s[i] == '.' && (i + 1 == n || s[i + 1] == 'e' || s[i + 1] == 'E')) return false;
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '.') {
                if (e || dot) return false;
                ++dot;
            } else if (s[j] == 'e' || s[j] == 'E') {
                if (e || j == i || j == n - 1) return false;
                ++e;
                if (s[j + 1] == '+' || s[j + 1] == '-') {
                    if (++j == n - 1) return false;
                }
            } else if (s[j] < '0' || s[j] > '9')
                return false;
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isNumber(s string) bool {
	i, n := 0, len(s)
	if s[i] == '+' || s[i] == '-' {
		i++
	}
	if i == n {
		return false
	}
	if s[i] == '.' && (i+1 == n || s[i+1] == 'e' || s[i+1] == 'E') {
		return false
	}
	var dot, e int
	for j := i; j < n; j++ {
		if s[j] == '.' {
			if e > 0 || dot > 0 {
				return false
			}
			dot++
		} else if s[j] == 'e' || s[j] == 'E' {
			if e > 0 || j == i || j == n-1 {
				return false
			}
			e++
			if s[j+1] == '+' || s[j+1] == '-' {
				j++
				if j == n-1 {
					return false
				}
			}
		} else if s[j] < '0' || s[j] > '9' {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_number(s: String) -> bool {
        let mut i = 0;
        let n = s.len();

        if let Some(c) = s.chars().nth(i) {
            if c == '+' || c == '-' {
                i += 1;
                if i == n {
                    return false;
                }
            }
        }
        if let Some(x) = s.chars().nth(i) {
            if x == '.'
                && (i + 1 == n
                    || (if let Some(m) = s.chars().nth(i + 1) {
                        m == 'e' || m == 'E'
                    } else {
                        false
                    }))
            {
                return false;
            }
        }

        let mut dot = 0;
        let mut e = 0;
        let mut j = i;

        while j < n {
            if let Some(c) = s.chars().nth(j) {
                if c == '.' {
                    if e > 0 || dot > 0 {
                        return false;
                    }
                    dot += 1;
                } else if c == 'e' || c == 'E' {
                    if e > 0 || j == i || j == n - 1 {
                        return false;
                    }
                    e += 1;
                    if let Some(x) = s.chars().nth(j + 1) {
                        if x == '+' || x == '-' {
                            j += 1;
                            if j == n - 1 {
                                return false;
                            }
                        }
                    }
                } else if !c.is_ascii_digit() {
                    return false;
                }
            }
            j += 1;
        }

        true
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Text.RegularExpressions;

public class Solution {
    private readonly Regex _isNumber_Regex = new Regex(@"^\s*[+-]?(\d+(\.\d*)?|\.\d+)([Ee][+-]?\d+)?\s*$");

    public bool IsNumber(string s) {
        return _isNumber_Regex.IsMatch(s);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>s</code>&nbsp;，返回&nbsp;<code>s</code>&nbsp;是否是一个 <strong>有效数字</strong>。</p>

<p>例如，下面的都是有效数字：<code>"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"</code>，而接下来的不是：<code>"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"</code>。</p>

<p>一般的，一个 <strong>有效数字</strong>&nbsp;可以用以下的规则之一定义：</p>

<ol>
	<li>一个 <strong>整数</strong> 后面跟着一个 <strong>可选指数</strong>。</li>
	<li>一个 <strong>十进制数</strong> 后面跟着一个&nbsp;<strong>可选指数</strong>。</li>
</ol>

<p>一个 <strong>整数</strong> 定义为一个&nbsp;<strong>可选符号</strong>&nbsp;<code>'-'</code>&nbsp;或&nbsp;<code>'+'</code>&nbsp;后面跟着 <strong>数字</strong>。</p>

<p>一个 <strong>十进制数</strong>&nbsp;定义为一个&nbsp;<strong>可选符号&nbsp;</strong><code>'-'</code>&nbsp;或&nbsp;<code>'+'</code>&nbsp;后面跟着下述规则：</p>

<ol>
	<li><strong>数字&nbsp;</strong>后跟着一个 <strong>小数点&nbsp;<code>.</code></strong>。</li>
	<li><strong>数字&nbsp;</strong>后跟着一个 <strong>小数点&nbsp;<code>.</code>&nbsp;</strong>再跟着<strong> 数位</strong>。</li>
	<li>一个 <strong>小数点&nbsp;<code>.</code>&nbsp;</strong>后跟着<strong> 数位</strong>。</li>
</ol>

<p><strong>指数</strong> 定义为指数符号 <code>'e'</code> 或 <code>'E'</code>，后面跟着一个 <b>整数</b>。</p>

<p><strong>数字</strong>&nbsp;定义为一个或多个数位。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "0"</span></p>

<p><strong>输出：</strong><span class="example-io">true</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "e"</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "."</span></p>

<p><strong>输出：</strong><span class="example-io">false</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> 仅含英文字母（大写和小写），数字（<code>0-9</code>），加号 <code>'+'</code> ，减号 <code>'-'</code> ，或者点 <code>'.'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

首先，我们判断字符串是否以正负号开头，如果是，将指针 $i$ 向后移动一位。如果此时指针 $i$ 已经到达字符串末尾，说明字符串只有一个正负号，返回 `false`。

如果当前指针 $i$ 指向的字符是小数点，并且小数点后面没有数字，或者小数点后是一个 `e` 或 `E`，返回 `false`。

接着，我们用两个变量 $dot$ 和 $e$ 分别记录小数点和 `e` 或 `E` 的个数。

用指针 $j$ 指向当前字符：

-   如果当前字符是小数点，并且此前出现过小数点或者 `e` 或 `E`，返回 `false`。否则，我们将 $dot$ 加一；
-   如果当前字符是 `e` 或 `E`，并且此前出现过 `e` 或 `E`，或者当前字符是开头或结尾，返回 `false`。否则，我们将 $e$ 加一；然后判断下一个字符是否是正负号，如果是，将指针 $j$ 向后移动一位。如果此时指针 $j$ 已经到达字符串末尾，返回 `false`；
-   如果当前字符不是数字，返回 `false`。

遍历完字符串后，返回 `true`。

时间复杂度 $O(n)$，其中 $n$ 为字符串长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        n = len(s)
        i = 0
        if s[i] in '+-':
            i += 1
        if i == n:
            return False
        if s[i] == '.' and (i + 1 == n or s[i + 1] in 'eE'):
            return False
        dot = e = 0
        j = i
        while j < n:
            if s[j] == '.':
                if e or dot:
                    return False
                dot += 1
            elif s[j] in 'eE':
                if e or j == i or j == n - 1:
                    return False
                e += 1
                if s[j + 1] in '+-':
                    j += 1
                    if j == n - 1:
                        return False
            elif not s[j].isnumeric():
                return False
            j += 1
        return True
```

#### Java

```java
class Solution {
    public boolean isNumber(String s) {
        int n = s.length();
        int i = 0;
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            ++i;
        }
        if (i == n) {
            return false;
        }
        if (s.charAt(i) == '.'
            && (i + 1 == n || s.charAt(i + 1) == 'e' || s.charAt(i + 1) == 'E')) {
            return false;
        }
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s.charAt(j) == '.') {
                if (e > 0 || dot > 0) {
                    return false;
                }
                ++dot;
            } else if (s.charAt(j) == 'e' || s.charAt(j) == 'E') {
                if (e > 0 || j == i || j == n - 1) {
                    return false;
                }
                ++e;
                if (s.charAt(j + 1) == '+' || s.charAt(j + 1) == '-') {
                    if (++j == n - 1) {
                        return false;
                    }
                }
            } else if (s.charAt(j) < '0' || s.charAt(j) > '9') {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == n) return false;
        if (s[i] == '.' && (i + 1 == n || s[i + 1] == 'e' || s[i + 1] == 'E')) return false;
        int dot = 0, e = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '.') {
                if (e || dot) return false;
                ++dot;
            } else if (s[j] == 'e' || s[j] == 'E') {
                if (e || j == i || j == n - 1) return false;
                ++e;
                if (s[j + 1] == '+' || s[j + 1] == '-') {
                    if (++j == n - 1) return false;
                }
            } else if (s[j] < '0' || s[j] > '9')
                return false;
        }
        return true;
    }
};
```

#### Go

```go
func isNumber(s string) bool {
	i, n := 0, len(s)
	if s[i] == '+' || s[i] == '-' {
		i++
	}
	if i == n {
		return false
	}
	if s[i] == '.' && (i+1 == n || s[i+1] == 'e' || s[i+1] == 'E') {
		return false
	}
	var dot, e int
	for j := i; j < n; j++ {
		if s[j] == '.' {
			if e > 0 || dot > 0 {
				return false
			}
			dot++
		} else if s[j] == 'e' || s[j] == 'E' {
			if e > 0 || j == i || j == n-1 {
				return false
			}
			e++
			if s[j+1] == '+' || s[j+1] == '-' {
				j++
				if j == n-1 {
					return false
				}
			}
		} else if s[j] < '0' || s[j] > '9' {
			return false
		}
	}
	return true
}
```

#### Rust

```rust
impl Solution {
    pub fn is_number(s: String) -> bool {
        let mut i = 0;
        let n = s.len();

        if let Some(c) = s.chars().nth(i) {
            if c == '+' || c == '-' {
                i += 1;
                if i == n {
                    return false;
                }
            }
        }
        if let Some(x) = s.chars().nth(i) {
            if x == '.'
                && (i + 1 == n
                    || (if let Some(m) = s.chars().nth(i + 1) {
                        m == 'e' || m == 'E'
                    } else {
                        false
                    }))
            {
                return false;
            }
        }

        let mut dot = 0;
        let mut e = 0;
        let mut j = i;

        while j < n {
            if let Some(c) = s.chars().nth(j) {
                if c == '.' {
                    if e > 0 || dot > 0 {
                        return false;
                    }
                    dot += 1;
                } else if c == 'e' || c == 'E' {
                    if e > 0 || j == i || j == n - 1 {
                        return false;
                    }
                    e += 1;
                    if let Some(x) = s.chars().nth(j + 1) {
                        if x == '+' || x == '-' {
                            j += 1;
                            if j == n - 1 {
                                return false;
                            }
                        }
                    }
                } else if !c.is_ascii_digit() {
                    return false;
                }
            }
            j += 1;
        }

        true
    }
}
```

#### C#

```cs
using System.Text.RegularExpressions;

public class Solution {
    private readonly Regex _isNumber_Regex = new Regex(@"^\s*[+-]?(\d+(\.\d*)?|\.\d+)([Ee][+-]?\d+)?\s*$");

    public bool IsNumber(string s) {
        return _isNumber_Regex.IsMatch(s);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [66. 加一](https://leetcode.cn/problems/plus-one){#66}

{{< tabs "66" >}}

{{% tab "python" %}}
```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            digits[i] += 1
            digits[i] %= 10
            if digits[i] != 0:
                return digits
        return [1] + digits
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for (int i = n - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func plusOne(digits []int) []int {
	n := len(digits)
	for i := n - 1; i >= 0; i-- {
		digits[i]++
		digits[i] %= 10
		if digits[i] != 0 {
			return digits
		}
	}
	return append([]int{1}, digits...)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function plusOne(digits: number[]): number[] {
    const n = digits.length;
    for (let i = n - 1; i >= 0; i--) {
        if (10 > ++digits[i]) {
            return digits;
        }
        digits[i] %= 10;
    }
    return [1, ...digits];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let n = digits.len();
        for i in (0..n).rev() {
            digits[i] += 1;
            if 10 > digits[i] {
                return digits;
            }
            digits[i] %= 10;
        }
        digits.insert(0, 1);
        digits
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    for (let i = digits.length - 1; i >= 0; --i) {
        ++digits[i];
        digits[i] %= 10;
        if (digits[i] != 0) {
            return digits;
        }
    }
    return [1, ...digits];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表示 <strong>大整数</strong> 的整数数组 <code>digits</code>，其中 <code>digits[i]</code> 是整数的第 <code>i</code> 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 <code>0</code>。</p>

<p>将大整数加 1，并返回结果的数字数组。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>digits = [1,2,3]
<strong>输出：</strong>[1,2,4]
<strong>解释：</strong>输入数组表示数字 123。
加 1 后得到 123 + 1 = 124。
因此，结果应该是 [1,2,4]。
</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>digits = [4,3,2,1]
<strong>输出：</strong>[4,3,2,2]
<strong>解释：</strong>输入数组表示数字 4321。
加 1 后得到 4321 + 1 = 4322。
因此，结果应该是 [4,3,2,2]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>digits = [9]
<strong>输出：</strong>[1,0]
<strong>解释：</strong>输入数组表示数字 9。
加 1 得到了 9 + 1 = 10。
因此，结果应该是 [1,0]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
	<li><code>digits</code>&nbsp;不包含任何前导 <code>0</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们从数组的最后一个元素开始遍历，将当前元素加一，然后对 $10$ 取模，如果取模后的结果不为 $0$，说明当前元素没有进位，直接返回数组即可。否则，当前元素为 $0$，需要进位，继续遍历前一个元素，重复上述操作。如果遍历完数组后，仍然没有返回，说明数组中所有元素都为 $0$，需要在数组的头部插入一个 $1$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n = len(digits)
        for i in range(n - 1, -1, -1):
            digits[i] += 1
            digits[i] %= 10
            if digits[i] != 0:
                return digits
        return [1] + digits
```

#### Java

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        for (int i = n - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        digits = new int[n + 1];
        digits[0] = 1;
        return digits;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

#### Go

```go
func plusOne(digits []int) []int {
	n := len(digits)
	for i := n - 1; i >= 0; i-- {
		digits[i]++
		digits[i] %= 10
		if digits[i] != 0 {
			return digits
		}
	}
	return append([]int{1}, digits...)
}
```

#### TypeScript

```ts
function plusOne(digits: number[]): number[] {
    const n = digits.length;
    for (let i = n - 1; i >= 0; i--) {
        if (10 > ++digits[i]) {
            return digits;
        }
        digits[i] %= 10;
    }
    return [1, ...digits];
}
```

#### Rust

```rust
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let n = digits.len();
        for i in (0..n).rev() {
            digits[i] += 1;
            if 10 > digits[i] {
                return digits;
            }
            digits[i] %= 10;
        }
        digits.insert(0, 1);
        digits
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
    for (let i = digits.length - 1; i >= 0; --i) {
        ++digits[i];
        digits[i] %= 10;
        if (digits[i] != 0) {
            return digits;
        }
    }
    return [1, ...digits];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [67. 二进制求和](https://leetcode.cn/problems/add-binary){#67}

{{< tabs "67" >}}

{{% tab "python" %}}
```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = []
        i, j, carry = len(a) - 1, len(b) - 1, 0
        while i >= 0 or j >= 0 or carry:
            carry += (0 if i < 0 else int(a[i])) + (0 if j < 0 else int(b[j]))
            carry, v = divmod(carry, 2)
            ans.append(str(v))
            i, j = i - 1, j - 1
        return ''.join(ans[::-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String addBinary(String a, String b) {
        var sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            carry += (i >= 0 ? a.charAt(i) - '0' : 0) + (j >= 0 ? b.charAt(j) - '0' : 0);
            sb.append(carry % 2);
            carry /= 2;
        }
        return sb.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addBinary(a string, b string) string {
	i, j := len(a)-1, len(b)-1
	ans := []byte{}
	for carry := 0; i >= 0 || j >= 0 || carry > 0; i, j = i-1, j-1 {
		if i >= 0 {
			carry += int(a[i] - '0')
		}
		if j >= 0 {
			carry += int(b[j] - '0')
		}
		ans = append(ans, byte(carry%2+'0'))
		carry /= 2
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addBinary(a: string, b: string): string {
    let i = a.length - 1;
    let j = b.length - 1;
    let ans: number[] = [];
    for (let carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
        carry += (i >= 0 ? a[i] : '0').charCodeAt(0) - '0'.charCodeAt(0);
        carry += (j >= 0 ? b[j] : '0').charCodeAt(0) - '0'.charCodeAt(0);
        ans.push(carry % 2);
        carry >>= 1;
    }
    return ans.reverse().join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut i = (a.len() as i32) - 1;
        let mut j = (b.len() as i32) - 1;
        let mut carry = 0;
        let mut ans = String::new();
        let a = a.as_bytes();
        let b = b.as_bytes();
        while i >= 0 || j >= 0 || carry > 0 {
            if i >= 0 {
                carry += a[i as usize] - b'0';
                i -= 1;
            }
            if j >= 0 {
                carry += b[j as usize] - b'0';
                j -= 1;
            }
            ans.push_str(&(carry % 2).to_string());
            carry /= 2;
        }
        ans.chars().rev().collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string AddBinary(string a, string b) {
        int i = a.Length - 1;
        int j = b.Length - 1;
        var sb = new StringBuilder();
        for (int carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            carry += i >= 0 ? a[i] - '0' : 0;
            carry += j >= 0 ? b[j] - '0' : 0;
            sb.Append(carry % 2);
            carry /= 2;
        }
        var ans = sb.ToString().ToCharArray();
        Array.Reverse(ans);
        return new string(ans);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个二进制字符串 <code>a</code> 和 <code>b</code> ，以二进制字符串的形式返回它们的和。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入:</strong>a = "11", b = "1"
<strong>输出：</strong>"100"</pre>

<p><strong>示例&nbsp;2：</strong></p>

<pre>
<strong>输入：</strong>a = "1010", b = "1011"
<strong>输出：</strong>"10101"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length &lt;= 10<sup>4</sup></code></li>
	<li><code>a</code> 和 <code>b</code> 仅由字符 <code>'0'</code> 或 <code>'1'</code> 组成</li>
	<li>字符串如果不是 <code>"0"</code> ，就不含前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们用一个变量 $carry$ 记录当前的进位，用两个指针 $i$ 和 $j$ 分别指向 $a$ 和 $b$ 的末尾，从末尾到开头逐位相加即可。

时间复杂度 $O(\max(m, n))$，其中 $m$ 和 $n$ 分别为字符串 $a$ 和 $b$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]
```

#### Java

```java
class Solution {
    public String addBinary(String a, String b) {
        var sb = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            carry += (i >= 0 ? a.charAt(i) - '0' : 0) + (j >= 0 ? b.charAt(j) - '0' : 0);
            sb.append(carry % 2);
            carry /= 2;
        }
        return sb.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func addBinary(a string, b string) string {
	i, j := len(a)-1, len(b)-1
	ans := []byte{}
	for carry := 0; i >= 0 || j >= 0 || carry > 0; i, j = i-1, j-1 {
		if i >= 0 {
			carry += int(a[i] - '0')
		}
		if j >= 0 {
			carry += int(b[j] - '0')
		}
		ans = append(ans, byte(carry%2+'0'))
		carry /= 2
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function addBinary(a: string, b: string): string {
    return (BigInt('0b' + a) + BigInt('0b' + b)).toString(2);
}
```

#### Rust

```rust
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut i = (a.len() as i32) - 1;
        let mut j = (b.len() as i32) - 1;
        let mut carry = 0;
        let mut ans = String::new();
        let a = a.as_bytes();
        let b = b.as_bytes();
        while i >= 0 || j >= 0 || carry > 0 {
            if i >= 0 {
                carry += a[i as usize] - b'0';
                i -= 1;
            }
            if j >= 0 {
                carry += b[j as usize] - b'0';
                j -= 1;
            }
            ans.push_str(&(carry % 2).to_string());
            carry /= 2;
        }
        ans.chars().rev().collect()
    }
}
```

#### C#

```cs
public class Solution {
    public string AddBinary(string a, string b) {
        int i = a.Length - 1;
        int j = b.Length - 1;
        var sb = new StringBuilder();
        for (int carry = 0; i >= 0 || j >= 0 || carry > 0; --i, --j) {
            carry += i >= 0 ? a[i] - '0' : 0;
            carry += j >= 0 ? b[j] - '0' : 0;
            sb.Append(carry % 2);
            carry /= 2;
        }
        var ans = sb.ToString().ToCharArray();
        Array.Reverse(ans);
        return new string(ans);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        ans = []
        i, j, carry = len(a) - 1, len(b) - 1, 0
        while i >= 0 or j >= 0 or carry:
            carry += (0 if i < 0 else int(a[i])) + (0 if j < 0 else int(b[j]))
            carry, v = divmod(carry, 2)
            ans.append(str(v))
            i, j = i - 1, j - 1
        return ''.join(ans[::-1])
```

#### TypeScript

```ts
function addBinary(a: string, b: string): string {
    let i = a.length - 1;
    let j = b.length - 1;
    let ans: number[] = [];
    for (let carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
        carry += (i >= 0 ? a[i] : '0').charCodeAt(0) - '0'.charCodeAt(0);
        carry += (j >= 0 ? b[j] : '0').charCodeAt(0) - '0'.charCodeAt(0);
        ans.push(carry % 2);
        carry >>= 1;
    }
    return ans.reverse().join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [68. 文本左右对齐](https://leetcode.cn/problems/text-justification){#68}

{{< tabs "68" >}}

{{% tab "python" %}}
```python
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        i, n = 0, len(words)
        while i < n:
            t = []
            cnt = len(words[i])
            t.append(words[i])
            i += 1
            while i < n and cnt + 1 + len(words[i]) <= maxWidth:
                cnt += 1 + len(words[i])
                t.append(words[i])
                i += 1
            if i == n or len(t) == 1:
                left = ' '.join(t)
                right = ' ' * (maxWidth - len(left))
                ans.append(left + right)
                continue
            space_width = maxWidth - (cnt - len(t) + 1)
            w, m = divmod(space_width, len(t) - 1)
            row = []
            for j, s in enumerate(t[:-1]):
                row.append(s)
                row.append(' ' * (w + (1 if j < m else 0)))
            row.append(t[-1])
            ans.append(''.join(row))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        for (int i = 0, n = words.length; i < n;) {
            List<String> t = new ArrayList<>();
            t.add(words[i]);
            int cnt = words[i].length();
            ++i;
            while (i < n && cnt + 1 + words[i].length() <= maxWidth) {
                cnt += 1 + words[i].length();
                t.add(words[i++]);
            }
            if (i == n || t.size() == 1) {
                String left = String.join(" ", t);
                String right = " ".repeat(maxWidth - left.length());
                ans.add(left + right);
                continue;
            }
            int spaceWidth = maxWidth - (cnt - t.size() + 1);
            int w = spaceWidth / (t.size() - 1);
            int m = spaceWidth % (t.size() - 1);
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < t.size() - 1; ++j) {
                row.append(t.get(j));
                row.append(" ".repeat(w + (j < m ? 1 : 0)));
            }
            row.append(t.get(t.size() - 1));
            ans.add(row.toString());
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
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for (int i = 0, n = words.size(); i < n;) {
            vector<string> t = {words[i]};
            int cnt = words[i].size();
            ++i;
            while (i < n && cnt + 1 + words[i].size() <= maxWidth) {
                cnt += 1 + words[i].size();
                t.emplace_back(words[i++]);
            }
            if (i == n || t.size() == 1) {
                string left = t[0];
                for (int j = 1; j < t.size(); ++j) {
                    left += " " + t[j];
                }
                string right = string(maxWidth - left.size(), ' ');
                ans.emplace_back(left + right);
                continue;
            }
            int spaceWidth = maxWidth - (cnt - t.size() + 1);
            int w = spaceWidth / (t.size() - 1);
            int m = spaceWidth % (t.size() - 1);
            string row;
            for (int j = 0; j < t.size() - 1; ++j) {
                row += t[j] + string(w + (j < m ? 1 : 0), ' ');
            }
            row += t.back();
            ans.emplace_back(row);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fullJustify(words []string, maxWidth int) (ans []string) {
	for i, n := 0, len(words); i < n; {
		t := []string{words[i]}
		cnt := len(words[i])
		i++
		for i < n && cnt+1+len(words[i]) <= maxWidth {
			cnt += 1 + len(words[i])
			t = append(t, words[i])
			i++
		}
		if i == n || len(t) == 1 {
			left := strings.Join(t, " ")
			right := strings.Repeat(" ", maxWidth-len(left))
			ans = append(ans, left+right)
			continue
		}
		spaceWidth := maxWidth - (cnt - len(t) + 1)
		w := spaceWidth / (len(t) - 1)
		m := spaceWidth % (len(t) - 1)
		row := strings.Builder{}
		for j, s := range t[:len(t)-1] {
			row.WriteString(s)
			row.WriteString(strings.Repeat(" ", w))
			if j < m {
				row.WriteString(" ")
			}
		}
		row.WriteString(t[len(t)-1])
		ans = append(ans, row.String())
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fullJustify(words: string[], maxWidth: number): string[] {
    const ans: string[] = [];
    for (let i = 0, n = words.length; i < n; ) {
        const t: string[] = [words[i]];
        let cnt = words[i++].length;
        while (i < n && cnt + 1 + words[i].length <= maxWidth) {
            t.push(words[i]);
            cnt += 1 + words[i++].length;
        }
        if (i === n || t.length === 1) {
            const left: string = t.join(' ');
            const right: string = ' '.repeat(maxWidth - left.length);
            ans.push(left + right);
            continue;
        }
        const spaceWidth: number = maxWidth - (cnt - t.length + 1);
        const w: number = Math.floor(spaceWidth / (t.length - 1));
        const m: number = spaceWidth % (t.length - 1);
        const row: string[] = [];
        for (let j = 0; j < t.length - 1; ++j) {
            row.push(t[j]);
            row.push(' '.repeat(w + (j < m ? 1 : 0)));
        }
        row.push(t[t.length - 1]);
        ans.push(row.join(''));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<string> FullJustify(string[] words, int maxWidth) {
        var ans = new List<string>();
        for (int i = 0, n = words.Length; i < n;) {
            var t = new List<string>();
            t.Add(words[i]);
            int cnt = words[i].Length;
            ++i;
            while (i < n && cnt + 1 + words[i].Length <= maxWidth) {
                t.Add(words[i]);
                cnt += 1 + words[i].Length;
                ++i;
            }
            if (i == n || t.Count == 1) {
                string left = string.Join(" ", t);
                string right = new string(' ', maxWidth - left.Length);
                ans.Add(left + right);
                continue;
            }
            int spaceWidth = maxWidth - (cnt - t.Count + 1);
            int w = spaceWidth / (t.Count - 1);
            int m = spaceWidth % (t.Count - 1);
            var row = new StringBuilder();
            for (int j = 0; j < t.Count - 1; ++j) {
                row.Append(t[j]);
                row.Append(new string(' ', w + (j < m ? 1 : 0)));
            }
            row.Append(t[t.Count - 1]);
            ans.Add(row.ToString());
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个单词数组&nbsp;<code>words</code> 和一个长度&nbsp;<code>maxWidth</code>&nbsp;，重新排版单词，使其成为每行恰好有&nbsp;<code>maxWidth</code>&nbsp;个字符，且左右两端对齐的文本。</p>

<p>你应该使用 “<strong>贪心算法</strong>” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格&nbsp;<code>' '</code>&nbsp;填充，使得每行恰好有 <em>maxWidth</em>&nbsp;个字符。</p>

<p>要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。</p>

<p>文本的最后一行应为左对齐，且单词之间不插入<strong>额外的</strong>空格。</p>

<p><strong>注意:</strong></p>

<ul>
	<li>单词是指由非空格字符组成的字符序列。</li>
	<li>每个单词的长度大于 0，小于等于&nbsp;<em>maxWidth</em>。</li>
	<li>输入单词数组 <code>words</code>&nbsp;至少包含一个单词。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
<strong>输出:</strong>
[
&nbsp; &nbsp;"This &nbsp; &nbsp;is &nbsp; &nbsp;an",
&nbsp; &nbsp;"example &nbsp;of text",
&nbsp; &nbsp;"justification. &nbsp;"
]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong>words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
<strong>输出:</strong>
[
&nbsp; "What &nbsp; must &nbsp; be",
&nbsp; "acknowledgment &nbsp;",
&nbsp; "shall be &nbsp; &nbsp; &nbsp; &nbsp;"
]
<strong>解释: </strong>注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
&nbsp;    因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
</pre>

<p><strong>示例&nbsp;3:</strong></p>

<pre>
<strong>输入:</strong>words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
<strong>输出:</strong>
[
&nbsp; "Science &nbsp;is &nbsp;what we",
  "understand &nbsp; &nbsp; &nbsp;well",
&nbsp; "enough to explain to",
&nbsp; "a &nbsp;computer. &nbsp;Art is",
&nbsp; "everything &nbsp;else &nbsp;we",
&nbsp; "do &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;"
]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 300</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>words[i]</code>&nbsp;由小写英文字母和符号组成</li>
	<li><code>1 &lt;= maxWidth &lt;= 100</code></li>
	<li><code>words[i].length &lt;= maxWidth</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题意模拟即可，注意，如果是最后一行，或者这一行只有一个单词，那么要左对齐，否则要均匀分配空格。

时间复杂度 $O(L)$，空间复杂度 $O(L)$。其中 $L$ 为所有单词的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        i, n = 0, len(words)
        while i < n:
            t = []
            cnt = len(words[i])
            t.append(words[i])
            i += 1
            while i < n and cnt + 1 + len(words[i]) <= maxWidth:
                cnt += 1 + len(words[i])
                t.append(words[i])
                i += 1
            if i == n or len(t) == 1:
                left = ' '.join(t)
                right = ' ' * (maxWidth - len(left))
                ans.append(left + right)
                continue
            space_width = maxWidth - (cnt - len(t) + 1)
            w, m = divmod(space_width, len(t) - 1)
            row = []
            for j, s in enumerate(t[:-1]):
                row.append(s)
                row.append(' ' * (w + (1 if j < m else 0)))
            row.append(t[-1])
            ans.append(''.join(row))
        return ans
```

#### Java

```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        for (int i = 0, n = words.length; i < n;) {
            List<String> t = new ArrayList<>();
            t.add(words[i]);
            int cnt = words[i].length();
            ++i;
            while (i < n && cnt + 1 + words[i].length() <= maxWidth) {
                cnt += 1 + words[i].length();
                t.add(words[i++]);
            }
            if (i == n || t.size() == 1) {
                String left = String.join(" ", t);
                String right = " ".repeat(maxWidth - left.length());
                ans.add(left + right);
                continue;
            }
            int spaceWidth = maxWidth - (cnt - t.size() + 1);
            int w = spaceWidth / (t.size() - 1);
            int m = spaceWidth % (t.size() - 1);
            StringBuilder row = new StringBuilder();
            for (int j = 0; j < t.size() - 1; ++j) {
                row.append(t.get(j));
                row.append(" ".repeat(w + (j < m ? 1 : 0)));
            }
            row.append(t.get(t.size() - 1));
            ans.add(row.toString());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for (int i = 0, n = words.size(); i < n;) {
            vector<string> t = {words[i]};
            int cnt = words[i].size();
            ++i;
            while (i < n && cnt + 1 + words[i].size() <= maxWidth) {
                cnt += 1 + words[i].size();
                t.emplace_back(words[i++]);
            }
            if (i == n || t.size() == 1) {
                string left = t[0];
                for (int j = 1; j < t.size(); ++j) {
                    left += " " + t[j];
                }
                string right = string(maxWidth - left.size(), ' ');
                ans.emplace_back(left + right);
                continue;
            }
            int spaceWidth = maxWidth - (cnt - t.size() + 1);
            int w = spaceWidth / (t.size() - 1);
            int m = spaceWidth % (t.size() - 1);
            string row;
            for (int j = 0; j < t.size() - 1; ++j) {
                row += t[j] + string(w + (j < m ? 1 : 0), ' ');
            }
            row += t.back();
            ans.emplace_back(row);
        }
        return ans;
    }
};
```

#### Go

```go
func fullJustify(words []string, maxWidth int) (ans []string) {
	for i, n := 0, len(words); i < n; {
		t := []string{words[i]}
		cnt := len(words[i])
		i++
		for i < n && cnt+1+len(words[i]) <= maxWidth {
			cnt += 1 + len(words[i])
			t = append(t, words[i])
			i++
		}
		if i == n || len(t) == 1 {
			left := strings.Join(t, " ")
			right := strings.Repeat(" ", maxWidth-len(left))
			ans = append(ans, left+right)
			continue
		}
		spaceWidth := maxWidth - (cnt - len(t) + 1)
		w := spaceWidth / (len(t) - 1)
		m := spaceWidth % (len(t) - 1)
		row := strings.Builder{}
		for j, s := range t[:len(t)-1] {
			row.WriteString(s)
			row.WriteString(strings.Repeat(" ", w))
			if j < m {
				row.WriteString(" ")
			}
		}
		row.WriteString(t[len(t)-1])
		ans = append(ans, row.String())
	}
	return
}
```

#### TypeScript

```ts
function fullJustify(words: string[], maxWidth: number): string[] {
    const ans: string[] = [];
    for (let i = 0, n = words.length; i < n; ) {
        const t: string[] = [words[i]];
        let cnt = words[i++].length;
        while (i < n && cnt + 1 + words[i].length <= maxWidth) {
            t.push(words[i]);
            cnt += 1 + words[i++].length;
        }
        if (i === n || t.length === 1) {
            const left: string = t.join(' ');
            const right: string = ' '.repeat(maxWidth - left.length);
            ans.push(left + right);
            continue;
        }
        const spaceWidth: number = maxWidth - (cnt - t.length + 1);
        const w: number = Math.floor(spaceWidth / (t.length - 1));
        const m: number = spaceWidth % (t.length - 1);
        const row: string[] = [];
        for (let j = 0; j < t.length - 1; ++j) {
            row.push(t[j]);
            row.push(' '.repeat(w + (j < m ? 1 : 0)));
        }
        row.push(t[t.length - 1]);
        ans.push(row.join(''));
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public IList<string> FullJustify(string[] words, int maxWidth) {
        var ans = new List<string>();
        for (int i = 0, n = words.Length; i < n;) {
            var t = new List<string>();
            t.Add(words[i]);
            int cnt = words[i].Length;
            ++i;
            while (i < n && cnt + 1 + words[i].Length <= maxWidth) {
                t.Add(words[i]);
                cnt += 1 + words[i].Length;
                ++i;
            }
            if (i == n || t.Count == 1) {
                string left = string.Join(" ", t);
                string right = new string(' ', maxWidth - left.Length);
                ans.Add(left + right);
                continue;
            }
            int spaceWidth = maxWidth - (cnt - t.Count + 1);
            int w = spaceWidth / (t.Count - 1);
            int m = spaceWidth % (t.Count - 1);
            var row = new StringBuilder();
            for (int j = 0; j < t.Count - 1; ++j) {
                row.Append(t[j]);
                row.Append(new string(' ', w + (j < m ? 1 : 0)));
            }
            row.Append(t[t.Count - 1]);
            ans.Add(row.ToString());
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [69. x 的平方根](https://leetcode.cn/problems/sqrtx){#69}

{{< tabs "69" >}}

{{% tab "python" %}}
```python
class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        while l < r:
            mid = (l + r + 1) >> 1
            if mid > x // mid:
                r = mid - 1
            else:
                l = mid
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1ll) >> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mySqrt(x int) int {
	return sort.Search(x+1, func(i int) bool { return i*i > x }) - 1
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut l = 0;
        let mut r = x;

        while l < r {
            let mid = (l + r + 1) / 2;

            if mid > x / mid {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        l
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
    let [l, r] = [0, x];
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (mid > x / mid) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非负整数 <code>x</code> ，计算并返回&nbsp;<code>x</code>&nbsp;的 <strong>算术平方根</strong> 。</p>

<p>由于返回类型是整数，结果只保留 <strong>整数部分 </strong>，小数部分将被 <strong>舍去 。</strong></p>

<p><strong>注意：</strong>不允许使用任何内置指数函数和算符，例如 <code>pow(x, 0.5)</code> 或者 <code>x ** 0.5</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>x = 4
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>x = 8
<strong>输出：</strong>2
<strong>解释：</strong>8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= x &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们定义二分查找的左边界 $l = 0$，右边界 $r = x$，然后在 $[l, r]$ 范围内查找平方根。

在每一步查找中，我们找出中间值 $mid = (l + r + 1) / 2$，如果 $mid > x / mid$，说明平方根在 $[l, mid - 1]$ 范围内，我们令 $r = mid - 1$；否则说明平方根在 $[mid, r]$ 范围内，我们令 $l = mid$。

查找结束后，返回 $l$ 即可。

时间复杂度 $O(\log x)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        l, r = 0, x
        while l < r:
            mid = (l + r + 1) >> 1
            if mid > x // mid:
                r = mid - 1
            else:
                l = mid
        return l
```

#### Java

```java
class Solution {
    public int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1ll) >> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};
```

#### Go

```go
func mySqrt(x int) int {
	return sort.Search(x+1, func(i int) bool { return i*i > x }) - 1
}
```

#### Rust

```rust
impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let mut l = 0;
        let mut r = x;

        while l < r {
            let mid = (l + r + 1) / 2;

            if mid > x / mid {
                r = mid - 1;
            } else {
                l = mid;
            }
        }

        l
    }
}
```

#### JavaScript

```js
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
    let [l, r] = [0, x];
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (mid > x / mid) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
};
```

#### C#

```cs
public class Solution {
    public int MySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [70. 爬楼梯](https://leetcode.cn/problems/climbing-stairs){#70}

{{< tabs "70" >}}

{{% tab "python" %}}
```python
import numpy as np


class Solution:
    def climbStairs(self, n: int) -> int:
        res = np.asmatrix([(1, 1)], np.dtype("O"))
        factor = np.asmatrix([(1, 1), (1, 0)], np.dtype("O"))
        n -= 1
        while n:
            if n & 1:
                res *= factor
            factor *= factor
            n >>= 1
        return res[0, 0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int[][] a = {{1, 1}, {1, 0}};

    public int climbStairs(int n) {
        return pow(a, n - 1)[0][0];
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < a[0].length; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = {{1, 1}, {0, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            n >>= 1;
            a = mul(a, a);
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<vector<long long>> a = {{1, 1}, {1, 0}};
        return pow(a, n - 1)[0][0];
    }

private:
    vector<vector<long long>> mul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<long long>> res(m, vector<long long>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }

    vector<vector<long long>> pow(vector<vector<long long>>& a, int n) {
        vector<vector<long long>> res = {{1, 1}, {0, 0}};
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type matrix [2][2]int

func climbStairs(n int) int {
	a := matrix{{1, 1}, {1, 0}}
	return pow(a, n-1)[0][0]
}

func mul(a, b matrix) (c matrix) {
	m, n := len(a), len(b[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(a[0]); k++ {
				c[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return
}

func pow(a matrix, n int) matrix {
	res := matrix{{1, 1}, {0, 0}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function climbStairs(n: number): number {
    const a = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n - 1)[0][0];
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < a[0].length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res = [
        [1, 1],
        [0, 0],
    ];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let (mut p, mut q) = (1, 1);
        for i in 1..n {
            let t = p + q;
            p = q;
            q = t;
        }
        q
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    const a = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n - 1)[0][0];
};

function mul(a, b) {
    const [m, n] = [a.length, b[0].length];
    const c = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < a[0].length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [
        [1, 1],
        [0, 0],
    ];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function climbStairs($n) {
        if ($n <= 2) {
            return $n;
        }
        $dp = [0, 1, 2];
        for ($i = 3; $i <= $n; $i++) {
            $dp[$i] = $dp[$i - 2] + $dp[$i - 1];
        }
        return $dp[$n];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>假设你正在爬楼梯。需要 <code>n</code>&nbsp;阶你才能到达楼顶。</p>

<p>每次你可以爬 <code>1</code> 或 <code>2</code> 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>2
<strong>解释：</strong>有两种方法可以爬到楼顶。
1. 1 阶 + 1 阶
2. 2 阶</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>3
<strong>解释：</strong>有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

我们定义 $f[i]$ 表示爬到第 $i$ 阶楼梯的方法数，那么 $f[i]$ 可以由 $f[i - 1]$ 和 $f[i - 2]$ 转移而来，即：

$$
f[i] = f[i - 1] + f[i - 2]
$$

初始条件为 $f[0] = 1$，$f[1] = 1$，即爬到第 0 阶楼梯的方法数为 1，爬到第 1 阶楼梯的方法数也为 1。

答案即为 $f[n]$。

由于 $f[i]$ 只与 $f[i - 1]$ 和 $f[i - 2]$ 有关，因此我们可以只用两个变量 $a$ 和 $b$ 来维护当前的方法数，空间复杂度降低为 $O(1)$。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return b
```

#### Java

```java
class Solution {
    public int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
```

#### Go

```go
func climbStairs(n int) int {
	a, b := 0, 1
	for i := 0; i < n; i++ {
		a, b = b, a+b
	}
	return b
}
```

#### TypeScript

```ts
function climbStairs(n: number): number {
    let p = 1;
    let q = 1;
    for (let i = 1; i < n; i++) {
        [p, q] = [q, p + q];
    }
    return q;
}
```

#### Rust

```rust
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let (mut p, mut q) = (1, 1);
        for i in 1..n {
            let t = p + q;
            p = q;
            q = t;
        }
        q
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    let a = 0,
        b = 1;
    for (let i = 0; i < n; ++i) {
        const c = a + b;
        a = b;
        b = c;
    }
    return b;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return Integer
     */
    function climbStairs($n) {
        if ($n <= 2) {
            return $n;
        }
        $dp = [0, 1, 2];
        for ($i = 3; $i <= $n; $i++) {
            $dp[$i] = $dp[$i - 2] + $dp[$i - 1];
        }
        return $dp[$n];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：矩阵快速幂加速递推

我们设 $Fib(n)$ 表示一个 $1 \times 2$ 的矩阵 $\begin{bmatrix} F_n & F_{n - 1} \end{bmatrix}$，其中 $F_n$ 和 $F_{n - 1}$ 分别是第 $n$ 个和第 $n - 1$ 个斐波那契数。

我们希望根据 $Fib(n-1) = \begin{bmatrix} F_{n - 1} & F_{n - 2} \end{bmatrix}$ 推出 $Fib(n)$。也即是说，我们需要一个矩阵 $base$，使得 $Fib(n - 1) \times base = Fib(n)$，即：

$$
\begin{bmatrix}
F_{n - 1} & F_{n - 2}
\end{bmatrix} \times base = \begin{bmatrix} F_n & F_{n - 1} \end{bmatrix}
$$

由于 $F_n = F_{n - 1} + F_{n - 2}$，所以矩阵 $base$ 的第一列为：

$$
\begin{bmatrix}
1 \\
1
\end{bmatrix}
$$

第二列为：

$$
\begin{bmatrix}
1 \\
0
\end{bmatrix}
$$

因此有：

$$
\begin{bmatrix} F_{n - 1} & F_{n - 2} \end{bmatrix} \times \begin{bmatrix}1 & 1 \\ 1 & 0\end{bmatrix} = \begin{bmatrix} F_n & F_{n - 1} \end{bmatrix}
$$

我们定义初始矩阵 $res = \begin{bmatrix} 1 & 1 \end{bmatrix}$，那么 $F_n$ 等于 $res$ 乘以 $base^{n - 1}$ 的结果矩阵中第一行的第一个元素。使用矩阵快速幂求解即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
import numpy as np


class Solution:
    def climbStairs(self, n: int) -> int:
        res = np.asmatrix([(1, 1)], np.dtype("O"))
        factor = np.asmatrix([(1, 1), (1, 0)], np.dtype("O"))
        n -= 1
        while n:
            if n & 1:
                res *= factor
            factor *= factor
            n >>= 1
        return res[0, 0]
```

#### Java

```java
class Solution {
    private final int[][] a = {{1, 1}, {1, 0}};

    public int climbStairs(int n) {
        return pow(a, n - 1)[0][0];
    }

    private int[][] mul(int[][] a, int[][] b) {
        int m = a.length, n = b[0].length;
        int[][] c = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < a[0].length; ++k) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }

    private int[][] pow(int[][] a, int n) {
        int[][] res = {{1, 1}, {0, 0}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = mul(res, a);
            }
            n >>= 1;
            a = mul(a, a);
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<vector<long long>> a = {{1, 1}, {1, 0}};
        return pow(a, n - 1)[0][0];
    }

private:
    vector<vector<long long>> mul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        int m = a.size(), n = b[0].size();
        vector<vector<long long>> res(m, vector<long long>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < a[0].size(); ++k) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }

    vector<vector<long long>> pow(vector<vector<long long>>& a, int n) {
        vector<vector<long long>> res = {{1, 1}, {0, 0}};
        while (n) {
            if (n & 1) {
                res = mul(res, a);
            }
            a = mul(a, a);
            n >>= 1;
        }
        return res;
    }
};
```

#### Go

```go
type matrix [2][2]int

func climbStairs(n int) int {
	a := matrix{{1, 1}, {1, 0}}
	return pow(a, n-1)[0][0]
}

func mul(a, b matrix) (c matrix) {
	m, n := len(a), len(b[0])
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < len(a[0]); k++ {
				c[i][j] += a[i][k] * b[k][j]
			}
		}
	}
	return
}

func pow(a matrix, n int) matrix {
	res := matrix{{1, 1}, {0, 0}}
	for n > 0 {
		if n&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		n >>= 1
	}
	return res
}
```

#### TypeScript

```ts
function climbStairs(n: number): number {
    const a = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n - 1)[0][0];
}

function mul(a: number[][], b: number[][]): number[][] {
    const [m, n] = [a.length, b[0].length];
    const c = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < a[0].length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a: number[][], n: number): number[][] {
    let res = [
        [1, 1],
        [0, 0],
    ];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function (n) {
    const a = [
        [1, 1],
        [1, 0],
    ];
    return pow(a, n - 1)[0][0];
};

function mul(a, b) {
    const [m, n] = [a.length, b[0].length];
    const c = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            for (let k = 0; k < a[0].length; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

function pow(a, n) {
    let res = [
        [1, 1],
        [0, 0],
    ];
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
