---
title: "1720_解码异或后的数组"
date: 2025-10-08T18:38:17+08:00
weight: 3
tags: [位运算, 动态规划, 博弈, 双指针, 哈希表, 回溯, 图, 并查集, 拓扑排序, 排序, 数学, 数据库, 数组, 最小生成树, 深度优先搜索, 状态压缩, 矩阵, 计数, 记忆化搜索, 贪心, 链表]
---

{{< markmap >}}
### [1720_解码异或后的数组](#1720)
#### [位运算](#1720)
#### [数组](#1720)
### [1721_交换链表中的节点](#1721)
#### [链表](#1721)
#### [双指针](#1721)
### [1722_执行交换操作后的最小汉明距离](#1722)
#### [深度优先搜索](#1722)
#### [并查集](#1722)
#### [数组](#1722)
### [1723_完成所有工作的最短时间](#1723)
#### [位运算](#1723)
#### [数组](#1723)
#### [动态规划](#1723)
#### [回溯](#1723)
#### [状态压缩](#1723)
### [1724_检查边长度限制的路径是否存在 II 🔒](#1724)
#### [并查集](#1724)
#### [图](#1724)
#### [最小生成树](#1724)
### [1725_可以形成最大正方形的矩形数目](#1725)
#### [数组](#1725)
### [1726_同积元组](#1726)
#### [数组](#1726)
#### [哈希表](#1726)
#### [计数](#1726)
### [1727_重新排列后的最大子矩阵](#1727)
#### [贪心](#1727)
#### [数组](#1727)
#### [矩阵](#1727)
#### [排序](#1727)
### [1728_猫和老鼠 II](#1728)
#### [图](#1728)
#### [拓扑排序](#1728)
#### [记忆化搜索](#1728)
#### [数组](#1728)
#### [数学](#1728)
#### [动态规划](#1728)
#### [博弈](#1728)
#### [矩阵](#1728)
### [1729_求关注者的数量](#1729)
#### [数据库](#1729)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1720_解码异或后的数组
___
#### 位运算
___
#### 数组
---
### 1721_交换链表中的节点
___
#### 链表
___
#### 双指针
---
### 1722_执行交换操作后的最小汉明距离
___
#### 深度优先搜索
___
#### 并查集
___
#### 数组
---
### 1723_完成所有工作的最短时间
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 1724_检查边长度限制的路径是否存在 II 🔒
___
#### 并查集
___
#### 图
___
#### 最小生成树
---
### 1725_可以形成最大正方形的矩形数目
___
#### 数组
---
### 1726_同积元组
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 1727_重新排列后的最大子矩阵
___
#### 贪心
___
#### 数组
___
#### 矩阵
___
#### 排序
---
### 1728_猫和老鼠 II
___
#### 图
___
#### 拓扑排序
___
#### 记忆化搜索
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
___
#### 矩阵
---
### 1729_求关注者的数量
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 博弈 |
| 双指针 | 哈希表 | 回溯 |
| 图 | 并查集 | 拓扑排序 |
| 排序 | 数学 | 数据库 |
| 数组 | 最小生成树 | 深度优先搜索 |
| 状态压缩 | 矩阵 | 计数 |
| 记忆化搜索 | 贪心 | 链表 |

# [1720. 解码异或后的数组](https://leetcode.cn/problems/decode-xored-array){#1720}

{{< tabs "1720" >}}

{{% tab "python" %}}
```python
class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ans = [first]
        for e in encoded:
            ans.append(ans[-1] ^ e)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] decode(int[] encoded, int first) {
        int n = encoded.length;
        int[] ans = new int[n + 1];
        ans[0] = first;
        for (int i = 0; i < n; ++i) {
            ans[i + 1] = ans[i] ^ encoded[i];
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
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans = {{first}};
        for (int x : encoded) {
            ans.push_back(ans.back() ^ x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func decode(encoded []int, first int) []int {
	ans := []int{first}
	for i, x := range encoded {
		ans = append(ans, ans[i]^x)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decode(encoded: number[], first: number): number[] {
    const ans: number[] = [first];
    for (const x of encoded) {
        ans.push(ans.at(-1)! ^ x);
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>未知</strong> 整数数组 <code>arr</code> 由 <code>n</code> 个非负整数组成。</p>

<p>经编码后变为长度为 <code>n - 1</code> 的另一个整数数组 <code>encoded</code> ，其中 <code>encoded[i] = arr[i] XOR arr[i + 1]</code> 。例如，<code>arr = [1,0,2,1]</code> 经编码后得到 <code>encoded = [1,2,3]</code> 。</p>

<p>给你编码后的数组 <code>encoded</code> 和原数组 <code>arr</code> 的第一个元素 <code>first</code>（<code>arr[0]</code>）。</p>

<p>请解码返回原数组 <code>arr</code> 。可以证明答案存在并且是唯一的。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>encoded = [1,2,3], first = 1
<strong>输出：</strong>[1,0,2,1]
<strong>解释：</strong>若 arr = [1,0,2,1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>encoded = [6,2,7,3], first = 4
<strong>输出：</strong>[4,2,0,7,4]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= n <= 10<sup>4</sup></code></li>
	<li><code>encoded.length == n - 1</code></li>
	<li><code>0 <= encoded[i] <= 10<sup>5</sup></code></li>
	<li><code>0 <= first <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据题目描述，有：

$$
\textit{encoded}[i] = \textit{arr}[i] \oplus \textit{arr}[i + 1]
$$

如果我们将等式两边同时异或上 $\textit{arr}[i]$，那么就会得到：

$$
\textit{arr}[i] \oplus \textit{arr}[i] \oplus \textit{arr}[i + 1] = \textit{arr}[i] \oplus \textit{encoded}[i]
$$

即：

$$
\textit{arr}[i + 1] = \textit{arr}[i] \oplus \textit{encoded}[i]
$$

根据上述推导，我们可以从 $\textit{first}$ 开始，依次计算出数组 $\textit{arr}$ 的每一个元素。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ans = [first]
        for e in encoded:
            ans.append(ans[-1] ^ e)
        return ans
```

#### Java

```java
class Solution {
    public int[] decode(int[] encoded, int first) {
        int n = encoded.length;
        int[] ans = new int[n + 1];
        ans[0] = first;
        for (int i = 0; i < n; ++i) {
            ans[i + 1] = ans[i] ^ encoded[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans = {{first}};
        for (int x : encoded) {
            ans.push_back(ans.back() ^ x);
        }
        return ans;
    }
};
```

#### Go

```go
func decode(encoded []int, first int) []int {
	ans := []int{first}
	for i, x := range encoded {
		ans = append(ans, ans[i]^x)
	}
	return ans
}
```

#### TypeScript

```ts
function decode(encoded: number[], first: number): number[] {
    const ans: number[] = [first];
    for (const x of encoded) {
        ans.push(ans.at(-1)! ^ x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1721. 交换链表中的节点](https://leetcode.cn/problems/swapping-nodes-in-a-linked-list){#1721}

{{< tabs "1721" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        fast = slow = head
        for _ in range(k - 1):
            fast = fast.next
        p = fast
        while fast.next:
            fast, slow = fast.next, slow.next
        q = slow
        p.val, q.val = q.val, p.val
        return head
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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode fast = head;
        while (--k > 0) {
            fast = fast.next;
        }
        ListNode p = fast;
        ListNode slow = head;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode q = slow;
        int t = p.val;
        p.val = q.val;
        q.val = t;
        return head;
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        while (--k) {
            fast = fast->next;
        }
        ListNode* slow = head;
        ListNode* p = fast;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* q = slow;
        swap(p->val, q->val);
        return head;
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
func swapNodes(head *ListNode, k int) *ListNode {
	fast := head
	for ; k > 1; k-- {
		fast = fast.Next
	}
	p := fast
	slow := head
	for fast.Next != nil {
		fast, slow = fast.Next, slow.Next
	}
	q := slow
	p.Val, q.Val = q.Val, p.Val
	return head
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

function swapNodes(head: ListNode | null, k: number): ListNode | null {
    let [fast, slow] = [head, head];
    while (--k) {
        fast = fast.next;
    }
    const p = fast;
    while (fast.next) {
        fast = fast.next;
        slow = slow.next;
    }
    const q = slow;
    [p.val, q.val] = [q.val, p.val];
    return head;
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
    public ListNode SwapNodes(ListNode head, int k) {
        ListNode fast = head;
        while (--k > 0) {
            fast = fast.next;
        }
        ListNode p = fast;
        ListNode slow = head;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode q = slow;
        int t = p.val;
        p.val = q.val;
        q.val = t;
        return head;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你链表的头节点 <code>head</code> 和一个整数 <code>k</code> 。</p>

<p><strong>交换</strong> 链表正数第 <code>k</code> 个节点和倒数第 <code>k</code> 个节点的值后，返回链表的头节点（链表 <strong>从 1 开始索引</strong>）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1721.Swapping%20Nodes%20in%20a%20Linked%20List/images/linked1.jpg" style="width: 722px; height: 202px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 2
<strong>输出：</strong>[1,4,3,2,5]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [7,9,6,6,7,8,3,0,9,5], k = 5
<strong>输出：</strong>[7,9,6,6,8,7,3,0,9,5]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1], k = 1
<strong>输出：</strong>[1]
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>head = [1,2], k = 1
<strong>输出：</strong>[2,1]
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>head = [1,2,3], k = 2
<strong>输出：</strong>[1,2,3]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目是 <code>n</code></li>
	<li><code>1 <= k <= n <= 10<sup>5</sup></code></li>
	<li><code>0 <= Node.val <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

我们可以先用快指针 $fast$ 找到链表的第 $k$ 个节点，用指针 $p$ 指向它。然后我们再用慢指针 $slow$ 从链表的头节点出发，快慢指针同时向后移动，当快指针到达链表的最后一个节点时，慢指针 $slow$ 恰好指向倒数第 $k$ 个节点，用指针 $q$ 指向它。此时，我们只需要交换 $p$ 和 $q$ 的值即可。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        fast = slow = head
        for _ in range(k - 1):
            fast = fast.next
        p = fast
        while fast.next:
            fast, slow = fast.next, slow.next
        q = slow
        p.val, q.val = q.val, p.val
        return head
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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode fast = head;
        while (--k > 0) {
            fast = fast.next;
        }
        ListNode p = fast;
        ListNode slow = head;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode q = slow;
        int t = p.val;
        p.val = q.val;
        q.val = t;
        return head;
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        while (--k) {
            fast = fast->next;
        }
        ListNode* slow = head;
        ListNode* p = fast;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* q = slow;
        swap(p->val, q->val);
        return head;
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
func swapNodes(head *ListNode, k int) *ListNode {
	fast := head
	for ; k > 1; k-- {
		fast = fast.Next
	}
	p := fast
	slow := head
	for fast.Next != nil {
		fast, slow = fast.Next, slow.Next
	}
	q := slow
	p.Val, q.Val = q.Val, p.Val
	return head
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

function swapNodes(head: ListNode | null, k: number): ListNode | null {
    let [fast, slow] = [head, head];
    while (--k) {
        fast = fast.next;
    }
    const p = fast;
    while (fast.next) {
        fast = fast.next;
        slow = slow.next;
    }
    const q = slow;
    [p.val, q.val] = [q.val, p.val];
    return head;
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
    public ListNode SwapNodes(ListNode head, int k) {
        ListNode fast = head;
        while (--k > 0) {
            fast = fast.next;
        }
        ListNode p = fast;
        ListNode slow = head;
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        ListNode q = slow;
        int t = p.val;
        p.val = q.val;
        q.val = t;
        return head;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1722. 执行交换操作后的最小汉明距离](https://leetcode.cn/problems/minimize-hamming-distance-after-swap-operations){#1722}

{{< tabs "1722" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumHammingDistance(
        self, source: List[int], target: List[int], allowedSwaps: List[List[int]]
    ) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(source)
        p = list(range(n))
        for a, b in allowedSwaps:
            p[find(a)] = find(b)
        cnt = defaultdict(Counter)
        for i, x in enumerate(source):
            j = find(i)
            cnt[j][x] += 1
        ans = 0
        for i, x in enumerate(target):
            j = find(i)
            cnt[j][x] -= 1
            ans += cnt[j][x] < 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        for (int[] a : allowedSwaps) {
            p[find(a[0])] = find(a[1]);
        }
        Map<Integer, Map<Integer, Integer>> cnt = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int j = find(i);
            cnt.computeIfAbsent(j, k -> new HashMap<>()).merge(source[i], 1, Integer::sum);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = find(i);
            Map<Integer, Integer> t = cnt.get(j);
            if (t.merge(target[i], -1, Integer::sum) < 0) {
                ++ans;
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        for (auto& a : allowedSwaps) {
            p[find(a[0])] = find(a[1]);
        }
        unordered_map<int, unordered_map<int, int>> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[find(i)][source[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (--cnt[find(i)][target[i]] < 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumHammingDistance(source []int, target []int, allowedSwaps [][]int) (ans int) {
	n := len(source)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, a := range allowedSwaps {
		p[find(a[0])] = find(a[1])
	}
	cnt := map[int]map[int]int{}
	for i, x := range source {
		j := find(i)
		if cnt[j] == nil {
			cnt[j] = map[int]int{}
		}
		cnt[j][x]++
	}
	for i, x := range target {
		j := find(i)
		cnt[j][x]--
		if cnt[j][x] < 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumHammingDistance(
    source: number[],
    target: number[],
    allowedSwaps: number[][],
): number {
    const n = source.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (const [a, b] of allowedSwaps) {
        p[find(a)] = find(b);
    }
    const cnt: Map<number, Map<number, number>> = new Map();
    for (let i = 0; i < n; ++i) {
        const j = find(i);
        if (!cnt.has(j)) {
            cnt.set(j, new Map());
        }
        const m = cnt.get(j)!;
        m.set(source[i], (m.get(source[i]) ?? 0) + 1);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const j = find(i);
        const m = cnt.get(j)!;
        m.set(target[i], (m.get(target[i]) ?? 0) - 1);
        if (m.get(target[i])! < 0) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组 <code>source</code> 和 <code>target</code> ，长度都是 <code>n</code> 。还有一个数组 <code>allowedSwaps</code> ，其中每个 <code>allowedSwaps[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 表示你可以交换数组 <code>source</code> 中下标为 <code>a<sub>i</sub></code> 和 <code>b<sub>i</sub></code>（<strong>下标从 0 开始</strong>）的两个元素。注意，你可以按 <strong>任意</strong> 顺序 <strong>多次</strong> 交换一对特定下标指向的元素。</p>

<p>相同长度的两个数组 <code>source</code> 和 <code>target</code> 间的 <strong>汉明距离</strong> 是元素不同的下标数量。形式上，其值等于满足 <code>source[i] != target[i]</code> （<strong>下标从 0 开始</strong>）的下标 <code>i</code>（<code>0 &lt;= i &lt;= n-1</code>）的数量。</p>

<p>在对数组 <code>source</code> 执行 <strong>任意</strong> 数量的交换操作后，返回 <code>source</code> 和 <code>target</code> 间的 <strong>最小汉明距离</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
<strong>输出：</strong>1
<strong>解释：</strong>source 可以按下述方式转换：
- 交换下标 0 和 1 指向的元素：source = [<strong>2</strong>,<strong>1</strong>,3,4]
- 交换下标 2 和 3 指向的元素：source = [2,1,<strong>4</strong>,<strong>3</strong>]
source 和 target 间的汉明距离是 1 ，二者有 1 处元素不同，在下标 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
<strong>输出：</strong>2
<strong>解释：</strong>不能对 source 执行交换操作。
source 和 target 间的汉明距离是 2 ，二者有 2 处元素不同，在下标 1 和下标 2 。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == source.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= source[i], target[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= allowedSwaps.length &lt;= 10<sup>5</sup></code></li>
	<li><code>allowedSwaps[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>a<sub>i</sub> != b<sub>i</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集 + 哈希表

我们可以将每个下标看作一个节点，每个下标对应的元素看作节点的值，那么给定的 `allowedSwaps` 中的每个元素 `[a_i, b_i]` 就表示下标 `a_i` 和 `b_i` 之间存在一条边。因此，我们可以使用并查集来维护这些连通分量。

在得到每个连通分量之后，我们再用二维哈希表 $cnt$ 分别统计每个连通分量中每个元素出现的次数，最后对于数组 `target` 中的每个元素，如果其在对应的连通分量中出现的次数大于 0，则将其出现次数减 1，否则将答案加 1。

时间复杂度 $O(n \times \log n)$ 或 $O(n \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度，而 $\alpha$ 是阿克曼函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumHammingDistance(
        self, source: List[int], target: List[int], allowedSwaps: List[List[int]]
    ) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        n = len(source)
        p = list(range(n))
        for a, b in allowedSwaps:
            p[find(a)] = find(b)
        cnt = defaultdict(Counter)
        for i, x in enumerate(source):
            j = find(i)
            cnt[j][x] += 1
        ans = 0
        for i, x in enumerate(target):
            j = find(i)
            cnt[j][x] -= 1
            ans += cnt[j][x] < 0
        return ans
```

#### Java

```java
class Solution {
    private int[] p;

    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int n = source.length;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        for (int[] a : allowedSwaps) {
            p[find(a[0])] = find(a[1]);
        }
        Map<Integer, Map<Integer, Integer>> cnt = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            int j = find(i);
            cnt.computeIfAbsent(j, k -> new HashMap<>()).merge(source[i], 1, Integer::sum);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = find(i);
            Map<Integer, Integer> t = cnt.get(j);
            if (t.merge(target[i], -1, Integer::sum) < 0) {
                ++ans;
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            return x == p[x] ? x : p[x] = find(p[x]);
        };
        for (auto& a : allowedSwaps) {
            p[find(a[0])] = find(a[1]);
        }
        unordered_map<int, unordered_map<int, int>> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[find(i)][source[i]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (--cnt[find(i)][target[i]] < 0) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumHammingDistance(source []int, target []int, allowedSwaps [][]int) (ans int) {
	n := len(source)
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for _, a := range allowedSwaps {
		p[find(a[0])] = find(a[1])
	}
	cnt := map[int]map[int]int{}
	for i, x := range source {
		j := find(i)
		if cnt[j] == nil {
			cnt[j] = map[int]int{}
		}
		cnt[j][x]++
	}
	for i, x := range target {
		j := find(i)
		cnt[j][x]--
		if cnt[j][x] < 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumHammingDistance(
    source: number[],
    target: number[],
    allowedSwaps: number[][],
): number {
    const n = source.length;
    const p: number[] = Array.from({ length: n }, (_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (const [a, b] of allowedSwaps) {
        p[find(a)] = find(b);
    }
    const cnt: Map<number, Map<number, number>> = new Map();
    for (let i = 0; i < n; ++i) {
        const j = find(i);
        if (!cnt.has(j)) {
            cnt.set(j, new Map());
        }
        const m = cnt.get(j)!;
        m.set(source[i], (m.get(source[i]) ?? 0) + 1);
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        const j = find(i);
        const m = cnt.get(j)!;
        m.set(target[i], (m.get(target[i]) ?? 0) - 1);
        if (m.get(target[i])! < 0) {
            ++ans;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1723. 完成所有工作的最短时间](https://leetcode.cn/problems/find-minimum-time-to-finish-all-jobs){#1723}

{{< tabs "1723" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        def dfs(i):
            nonlocal ans
            if i == len(jobs):
                ans = min(ans, max(cnt))
                return
            for j in range(k):
                if cnt[j] + jobs[i] >= ans:
                    continue
                cnt[j] += jobs[i]
                dfs(i + 1)
                cnt[j] -= jobs[i]
                if cnt[j] == 0:
                    break

        cnt = [0] * k
        jobs.sort(reverse=True)
        ans = inf
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] cnt;
    private int ans;
    private int[] jobs;
    private int k;

    public int minimumTimeRequired(int[] jobs, int k) {
        this.k = k;
        Arrays.sort(jobs);
        for (int i = 0, j = jobs.length - 1; i < j; ++i, --j) {
            int t = jobs[i];
            jobs[i] = jobs[j];
            jobs[j] = t;
        }
        this.jobs = jobs;
        cnt = new int[k];
        ans = 0x3f3f3f3f;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == jobs.length) {
            int mx = 0;
            for (int v : cnt) {
                mx = Math.max(mx, v);
            }
            ans = Math.min(ans, mx);
            return;
        }
        for (int j = 0; j < k; ++j) {
            if (cnt[j] + jobs[i] >= ans) {
                continue;
            }
            cnt[j] += jobs[i];
            dfs(i + 1);
            cnt[j] -= jobs[i];
            if (cnt[j] == 0) {
                break;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int ans;

    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> cnt(k);
        ans = 0x3f3f3f3f;
        sort(jobs.begin(), jobs.end(), greater<int>());
        dfs(0, k, jobs, cnt);
        return ans;
    }

    void dfs(int i, int k, vector<int>& jobs, vector<int>& cnt) {
        if (i == jobs.size()) {
            ans = min(ans, *max_element(cnt.begin(), cnt.end()));
            return;
        }
        for (int j = 0; j < k; ++j) {
            if (cnt[j] + jobs[i] >= ans) continue;
            cnt[j] += jobs[i];
            dfs(i + 1, k, jobs, cnt);
            cnt[j] -= jobs[i];
            if (cnt[j] == 0) break;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTimeRequired(jobs []int, k int) int {
	cnt := make([]int, k)
	ans := 0x3f3f3f3f
	sort.Slice(jobs, func(i, j int) bool {
		return jobs[i] > jobs[j]
	})
	var dfs func(int)
	dfs = func(i int) {
		if i == len(jobs) {
			mx := slices.Max(cnt)
			ans = min(ans, mx)
			return
		}
		for j := 0; j < k; j++ {
			if cnt[j]+jobs[i] >= ans {
				continue
			}
			cnt[j] += jobs[i]
			dfs(i + 1)
			cnt[j] -= jobs[i]
			if cnt[j] == 0 {
				break
			}
		}
	}
	dfs(0)
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>jobs</code> ，其中 <code>jobs[i]</code> 是完成第 <code>i</code> 项工作要花费的时间。</p>

<p>请你将这些工作分配给 <code>k</code> 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 <strong>工作时间</strong> 是完成分配给他们的所有工作花费时间的总和。请你设计一套最佳的工作分配方案，使工人的 <strong>最大工作时间</strong> 得以 <strong>最小化</strong> 。</p>

<p>返回分配方案中尽可能 <strong>最小</strong> 的 <strong>最大工作时间</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>jobs = [3,2,3], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>给每位工人分配一项工作，最大工作时间是 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>jobs = [1,2,4,7,8], k = 2
<strong>输出：</strong>11
<strong>解释：</strong>按下述方式分配工作：
1 号工人：1、2、8（工作时间 = 1 + 2 + 8 = 11）
2 号工人：4、7（工作时间 = 4 + 7 = 11）
最大工作时间是 11 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= k <= jobs.length <= 12</code></li>
	<li><code>1 <= jobs[i] <= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 剪枝

本题与 [2305. 公平分发饼干](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2305.Fair%20Distribution%20of%20Cookies/README.md) 基本一致，不同的地方仅在于 $k$ 值的大小。

剪枝优化：优化分配花费时间较大的工作，因此可以先对 $jobs$ 按照降序排列。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTimeRequired(self, jobs: List[int], k: int) -> int:
        def dfs(i):
            nonlocal ans
            if i == len(jobs):
                ans = min(ans, max(cnt))
                return
            for j in range(k):
                if cnt[j] + jobs[i] >= ans:
                    continue
                cnt[j] += jobs[i]
                dfs(i + 1)
                cnt[j] -= jobs[i]
                if cnt[j] == 0:
                    break

        cnt = [0] * k
        jobs.sort(reverse=True)
        ans = inf
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private int[] cnt;
    private int ans;
    private int[] jobs;
    private int k;

    public int minimumTimeRequired(int[] jobs, int k) {
        this.k = k;
        Arrays.sort(jobs);
        for (int i = 0, j = jobs.length - 1; i < j; ++i, --j) {
            int t = jobs[i];
            jobs[i] = jobs[j];
            jobs[j] = t;
        }
        this.jobs = jobs;
        cnt = new int[k];
        ans = 0x3f3f3f3f;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i == jobs.length) {
            int mx = 0;
            for (int v : cnt) {
                mx = Math.max(mx, v);
            }
            ans = Math.min(ans, mx);
            return;
        }
        for (int j = 0; j < k; ++j) {
            if (cnt[j] + jobs[i] >= ans) {
                continue;
            }
            cnt[j] += jobs[i];
            dfs(i + 1);
            cnt[j] -= jobs[i];
            if (cnt[j] == 0) {
                break;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int ans;

    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> cnt(k);
        ans = 0x3f3f3f3f;
        sort(jobs.begin(), jobs.end(), greater<int>());
        dfs(0, k, jobs, cnt);
        return ans;
    }

    void dfs(int i, int k, vector<int>& jobs, vector<int>& cnt) {
        if (i == jobs.size()) {
            ans = min(ans, *max_element(cnt.begin(), cnt.end()));
            return;
        }
        for (int j = 0; j < k; ++j) {
            if (cnt[j] + jobs[i] >= ans) continue;
            cnt[j] += jobs[i];
            dfs(i + 1, k, jobs, cnt);
            cnt[j] -= jobs[i];
            if (cnt[j] == 0) break;
        }
    }
};
```

#### Go

```go
func minimumTimeRequired(jobs []int, k int) int {
	cnt := make([]int, k)
	ans := 0x3f3f3f3f
	sort.Slice(jobs, func(i, j int) bool {
		return jobs[i] > jobs[j]
	})
	var dfs func(int)
	dfs = func(i int) {
		if i == len(jobs) {
			mx := slices.Max(cnt)
			ans = min(ans, mx)
			return
		}
		for j := 0; j < k; j++ {
			if cnt[j]+jobs[i] >= ans {
				continue
			}
			cnt[j] += jobs[i]
			dfs(i + 1)
			cnt[j] -= jobs[i]
			if cnt[j] == 0 {
				break
			}
		}
	}
	dfs(0)
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1724. 检查边长度限制的路径是否存在 II 🔒](https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths-ii){#1724}

{{< tabs "1724" >}}

{{% tab "python" %}}
```python
class PersistentUnionFind:
    def __init__(self, n):
        self.rank = [0] * n
        self.p = list(range(n))
        self.version = [inf] * n

    def find(self, x, t=inf):
        if self.p[x] == x or self.version[x] >= t:
            return x
        return self.find(self.p[x], t)

    def union(self, a, b, t):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] > self.rank[pb]:
            self.version[pb] = t
            self.p[pb] = pa
        else:
            self.version[pa] = t
            self.p[pa] = pb
            if self.rank[pa] == self.rank[pb]:
                self.rank[pb] += 1
        return True


class DistanceLimitedPathsExist:
    def __init__(self, n: int, edgeList: List[List[int]]):
        self.puf = PersistentUnionFind(n)
        edgeList.sort(key=lambda x: x[2])
        for u, v, dis in edgeList:
            self.puf.union(u, v, dis)

    def query(self, p: int, q: int, limit: int) -> bool:
        return self.puf.find(p, limit) == self.puf.find(q, limit)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class PersistentUnionFind {
    private final int inf = 1 << 30;
    private int[] rank;
    private int[] parent;
    private int[] version;

    public PersistentUnionFind(int n) {
        rank = new int[n];
        parent = new int[n];
        version = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            version[i] = inf;
        }
    }

    public int find(int x, int t) {
        if (parent[x] == x || version[x] >= t) {
            return x;
        }
        return find(parent[x], t);
    }

    public boolean union(int a, int b, int t) {
        int pa = find(a, inf);
        int pb = find(b, inf);
        if (pa == pb) {
            return false;
        }
        if (rank[pa] > rank[pb]) {
            version[pb] = t;
            parent[pb] = pa;
        } else {
            version[pa] = t;
            parent[pa] = pb;
            if (rank[pa] == rank[pb]) {
                rank[pb]++;
            }
        }
        return true;
    }
}

public class DistanceLimitedPathsExist {
    private PersistentUnionFind puf;

    public DistanceLimitedPathsExist(int n, int[][] edgeList) {
        puf = new PersistentUnionFind(n);
        Arrays.sort(edgeList, (a, b) -> a[2] - b[2]);
        for (var e : edgeList) {
            puf.union(e[0], e[1], e[2]);
        }
    }

    public boolean query(int p, int q, int limit) {
        return puf.find(p, limit) == puf.find(q, limit);
    }
}

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist obj = new DistanceLimitedPathsExist(n, edgeList);
 * boolean param_1 = obj.query(p,q,limit);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class PersistentUnionFind {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> version;

public:
    PersistentUnionFind(int n)
        : rank(n, 0)
        , parent(n)
        , version(n, INT_MAX) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x, int t) {
        if (parent[x] == x || version[x] >= t) {
            return x;
        }
        return find(parent[x], t);
    }

    bool unionSet(int a, int b, int t) {
        int pa = find(a, INT_MAX);
        int pb = find(b, INT_MAX);
        if (pa == pb) {
            return false;
        }
        if (rank[pa] > rank[pb]) {
            version[pb] = t;
            parent[pb] = pa;
        } else {
            version[pa] = t;
            parent[pa] = pb;
            if (rank[pa] == rank[pb]) {
                rank[pb]++;
            }
        }
        return true;
    }
};

class DistanceLimitedPathsExist {
private:
    PersistentUnionFind puf;

public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList)
        : puf(n) {
        sort(edgeList.begin(), edgeList.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });

        for (const auto& edge : edgeList) {
            puf.unionSet(edge[0], edge[1], edge[2]);
        }
    }

    bool query(int p, int q, int limit) {
        return puf.find(p, limit) == puf.find(q, limit);
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type PersistentUnionFind struct {
	rank    []int
	parent  []int
	version []int
}

func NewPersistentUnionFind(n int) *PersistentUnionFind {
	rank := make([]int, n)
	parent := make([]int, n)
	version := make([]int, n)

	for i := 0; i < n; i++ {
		parent[i] = i
	}

	return &PersistentUnionFind{
		rank:    rank,
		parent:  parent,
		version: version,
	}
}

func (uf *PersistentUnionFind) find(x int, t int) int {
	if uf.parent[x] == x || uf.version[x] >= t {
		return x
	}
	return uf.find(uf.parent[x], t)
}

func (uf *PersistentUnionFind) union(a, b, t int) bool {
	pa := uf.find(a, int(^uint(0)>>1))
	pb := uf.find(b, int(^uint(0)>>1))

	if pa == pb {
		return false
	}

	if uf.rank[pa] > uf.rank[pb] {
		uf.version[pb] = t
		uf.parent[pb] = pa
	} else {
		uf.version[pa] = t
		uf.parent[pa] = pb
		if uf.rank[pa] == uf.rank[pb] {
			uf.rank[pb]++
		}
	}

	return true
}

type DistanceLimitedPathsExist struct {
	puf *PersistentUnionFind
}

func Constructor(n int, edgeList [][]int) DistanceLimitedPathsExist {
	sort.Slice(edgeList, func(i, j int) bool {
		return edgeList[i][2] < edgeList[j][2]
	})

	puf := NewPersistentUnionFind(n)

	for _, edge := range edgeList {
		puf.union(edge[0], edge[1], edge[2])
	}

	return DistanceLimitedPathsExist{
		puf: puf,
	}
}

func (dle *DistanceLimitedPathsExist) Query(p, q, limit int) bool {
	return dle.puf.find(p, limit) == dle.puf.find(q, limit)
}

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * obj := Constructor(n, edgeList);
 * param_1 := obj.Query(p,q,limit);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class PersistentUnionFind {
    private rank: number[];
    private parent: number[];
    private version: number[];

    constructor(n: number) {
        this.rank = Array(n).fill(0);
        this.parent = Array.from({ length: n }, (_, i) => i);
        this.version = Array(n).fill(Infinity);
    }

    find(x: number, t: number): number {
        if (this.parent[x] === x || this.version[x] >= t) {
            return x;
        }
        return this.find(this.parent[x], t);
    }

    union(a: number, b: number, t: number): boolean {
        const pa = this.find(a, Infinity);
        const pb = this.find(b, Infinity);

        if (pa === pb) {
            return false;
        }

        if (this.rank[pa] > this.rank[pb]) {
            this.version[pb] = t;
            this.parent[pb] = pa;
        } else {
            this.version[pa] = t;
            this.parent[pa] = pb;
            if (this.rank[pa] === this.rank[pb]) {
                this.rank[pb]++;
            }
        }

        return true;
    }
}

class DistanceLimitedPathsExist {
    private puf: PersistentUnionFind;

    constructor(n: number, edgeList: number[][]) {
        this.puf = new PersistentUnionFind(n);
        edgeList.sort((a, b) => a[2] - b[2]);
        for (const [u, v, dis] of edgeList) {
            this.puf.union(u, v, dis);
        }
    }

    query(p: number, q: number, limit: number): boolean {
        return this.puf.find(p, limit) === this.puf.find(q, limit);
    }
}

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * var obj = new DistanceLimitedPathsExist(n, edgeList)
 * var param_1 = obj.query(p,q,limit)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一张有&nbsp;<code>n</code>&nbsp;个节点的无向图以边的列表&nbsp;<code>edgeList</code>&nbsp;的形式定义，其中&nbsp;<code>edgeList[i] = [u<sub>i</sub>, v<sub>i</sub>, dis<sub>i</sub>]</code>&nbsp;表示一条连接&nbsp;<code>u<sub>i</sub></code>&nbsp;和&nbsp;<code>v<sub>i</sub></code>&nbsp;，距离为&nbsp;<code>dis<sub>i</sub></code>&nbsp;的边。注意，同一对节点间可能有<strong>多条</strong>边，且该图可能不是连通的。</p>

<p>实现&nbsp;<code>DistanceLimitedPathsExist</code>&nbsp;类：</p>

<ul>
	<li><code>DistanceLimitedPathsExist(int n, int[][] edgeList)</code>&nbsp;以给定的无向图初始化对象。</li>
	<li><code>boolean query(int p, int q, int limit)</code>&nbsp;当存在一条从&nbsp;<code>p</code>&nbsp;到 <code>q</code> 的路径，且路径中每条边的距离都<strong>严格小于</strong> <code>limit</code> 时，返回 <code>true</code> ，否则返回 <code>false</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1724.Checking%20Existence%20of%20Edge%20Length%20Limited%20Paths%20II/images/1693449815-oSOAxI-%E6%88%AA%E5%B1%8F2023-08-31%2010.43.30.png){:width=400}" style="width: 400px;" /><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1724.Checking%20Existence%20of%20Edge%20Length%20Limited%20Paths%20II/images/1693449815-oSOAxI-%E6%88%AA%E5%B1%8F2023-08-31%2010.43.30.png" style="width: 400px; height: 352px;" /></p>

<pre>
<b>输入：</b>
["DistanceLimitedPathsExist", "query", "query", "query", "query"]
[[6, [[0, 2, 4], [0, 3, 2], [1, 2, 3], [2, 3, 1], [4, 5, 5]]], [2, 3, 2], [1, 3, 3], [2, 0, 3], [0, 5, 6]]
<b>输出：</b>
[null, true, false, true, false]

<b>解释：</b>
DistanceLimitedPathsExist distanceLimitedPathsExist = new DistanceLimitedPathsExist(6, [[0, 2, 4], [0, 3, 2], [1, 2, 3], [2, 3, 1], [4, 5, 5]]);
distanceLimitedPathsExist.query(2, 3, 2); // 返回 true。存在一条从 2 到 3 ，距离为 1 的边，
&nbsp;                                         // 这条边的距离小于 2。
distanceLimitedPathsExist.query(1, 3, 3); // 返回 false。从 1 到 3 之间不存在每条边的距离都
                                          // <strong>严格</strong>小于 3 的路径。
distanceLimitedPathsExist.query(2, 0, 3); // 返回 true。存在一条从 2 到 0 的路径，使得每条边的
                                          // 距离 &lt; 3：从 2 到 3 到 0 行进即可。
distanceLimitedPathsExist.query(0, 5, 6); // 返回 false。从 0 到 5 之间不存在路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= edgeList.length &lt;= 10<sup>4</sup></code></li>
	<li><code>edgeList[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub>, p, q &lt;= n-1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>p != q</code></li>
	<li><code>1 &lt;= dis<sub>i</sub>, limit &lt;= 10<sup>9</sup></code></li>
	<li>最多调用&nbsp;<code>10<sup>4</sup></code>&nbsp;次&nbsp;<code>query</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：可持久化并查集

<!-- tabs:start -->

#### Python3

```python
class PersistentUnionFind:
    def __init__(self, n):
        self.rank = [0] * n
        self.p = list(range(n))
        self.version = [inf] * n

    def find(self, x, t=inf):
        if self.p[x] == x or self.version[x] >= t:
            return x
        return self.find(self.p[x], t)

    def union(self, a, b, t):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.rank[pa] > self.rank[pb]:
            self.version[pb] = t
            self.p[pb] = pa
        else:
            self.version[pa] = t
            self.p[pa] = pb
            if self.rank[pa] == self.rank[pb]:
                self.rank[pb] += 1
        return True


class DistanceLimitedPathsExist:
    def __init__(self, n: int, edgeList: List[List[int]]):
        self.puf = PersistentUnionFind(n)
        edgeList.sort(key=lambda x: x[2])
        for u, v, dis in edgeList:
            self.puf.union(u, v, dis)

    def query(self, p: int, q: int, limit: int) -> bool:
        return self.puf.find(p, limit) == self.puf.find(q, limit)
```

#### Java

```java
class PersistentUnionFind {
    private final int inf = 1 << 30;
    private int[] rank;
    private int[] parent;
    private int[] version;

    public PersistentUnionFind(int n) {
        rank = new int[n];
        parent = new int[n];
        version = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            version[i] = inf;
        }
    }

    public int find(int x, int t) {
        if (parent[x] == x || version[x] >= t) {
            return x;
        }
        return find(parent[x], t);
    }

    public boolean union(int a, int b, int t) {
        int pa = find(a, inf);
        int pb = find(b, inf);
        if (pa == pb) {
            return false;
        }
        if (rank[pa] > rank[pb]) {
            version[pb] = t;
            parent[pb] = pa;
        } else {
            version[pa] = t;
            parent[pa] = pb;
            if (rank[pa] == rank[pb]) {
                rank[pb]++;
            }
        }
        return true;
    }
}

public class DistanceLimitedPathsExist {
    private PersistentUnionFind puf;

    public DistanceLimitedPathsExist(int n, int[][] edgeList) {
        puf = new PersistentUnionFind(n);
        Arrays.sort(edgeList, (a, b) -> a[2] - b[2]);
        for (var e : edgeList) {
            puf.union(e[0], e[1], e[2]);
        }
    }

    public boolean query(int p, int q, int limit) {
        return puf.find(p, limit) == puf.find(q, limit);
    }
}

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist obj = new DistanceLimitedPathsExist(n, edgeList);
 * boolean param_1 = obj.query(p,q,limit);
 */
```

#### C++

```cpp
class PersistentUnionFind {
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> version;

public:
    PersistentUnionFind(int n)
        : rank(n, 0)
        , parent(n)
        , version(n, INT_MAX) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x, int t) {
        if (parent[x] == x || version[x] >= t) {
            return x;
        }
        return find(parent[x], t);
    }

    bool unionSet(int a, int b, int t) {
        int pa = find(a, INT_MAX);
        int pb = find(b, INT_MAX);
        if (pa == pb) {
            return false;
        }
        if (rank[pa] > rank[pb]) {
            version[pb] = t;
            parent[pb] = pa;
        } else {
            version[pa] = t;
            parent[pa] = pb;
            if (rank[pa] == rank[pb]) {
                rank[pb]++;
            }
        }
        return true;
    }
};

class DistanceLimitedPathsExist {
private:
    PersistentUnionFind puf;

public:
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList)
        : puf(n) {
        sort(edgeList.begin(), edgeList.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            });

        for (const auto& edge : edgeList) {
            puf.unionSet(edge[0], edge[1], edge[2]);
        }
    }

    bool query(int p, int q, int limit) {
        return puf.find(p, limit) == puf.find(q, limit);
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */
```

#### Go

```go
type PersistentUnionFind struct {
	rank    []int
	parent  []int
	version []int
}

func NewPersistentUnionFind(n int) *PersistentUnionFind {
	rank := make([]int, n)
	parent := make([]int, n)
	version := make([]int, n)

	for i := 0; i < n; i++ {
		parent[i] = i
	}

	return &PersistentUnionFind{
		rank:    rank,
		parent:  parent,
		version: version,
	}
}

func (uf *PersistentUnionFind) find(x int, t int) int {
	if uf.parent[x] == x || uf.version[x] >= t {
		return x
	}
	return uf.find(uf.parent[x], t)
}

func (uf *PersistentUnionFind) union(a, b, t int) bool {
	pa := uf.find(a, int(^uint(0)>>1))
	pb := uf.find(b, int(^uint(0)>>1))

	if pa == pb {
		return false
	}

	if uf.rank[pa] > uf.rank[pb] {
		uf.version[pb] = t
		uf.parent[pb] = pa
	} else {
		uf.version[pa] = t
		uf.parent[pa] = pb
		if uf.rank[pa] == uf.rank[pb] {
			uf.rank[pb]++
		}
	}

	return true
}

type DistanceLimitedPathsExist struct {
	puf *PersistentUnionFind
}

func Constructor(n int, edgeList [][]int) DistanceLimitedPathsExist {
	sort.Slice(edgeList, func(i, j int) bool {
		return edgeList[i][2] < edgeList[j][2]
	})

	puf := NewPersistentUnionFind(n)

	for _, edge := range edgeList {
		puf.union(edge[0], edge[1], edge[2])
	}

	return DistanceLimitedPathsExist{
		puf: puf,
	}
}

func (dle *DistanceLimitedPathsExist) Query(p, q, limit int) bool {
	return dle.puf.find(p, limit) == dle.puf.find(q, limit)
}

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * obj := Constructor(n, edgeList);
 * param_1 := obj.Query(p,q,limit);
 */
```

#### TypeScript

```ts
class PersistentUnionFind {
    private rank: number[];
    private parent: number[];
    private version: number[];

    constructor(n: number) {
        this.rank = Array(n).fill(0);
        this.parent = Array.from({ length: n }, (_, i) => i);
        this.version = Array(n).fill(Infinity);
    }

    find(x: number, t: number): number {
        if (this.parent[x] === x || this.version[x] >= t) {
            return x;
        }
        return this.find(this.parent[x], t);
    }

    union(a: number, b: number, t: number): boolean {
        const pa = this.find(a, Infinity);
        const pb = this.find(b, Infinity);

        if (pa === pb) {
            return false;
        }

        if (this.rank[pa] > this.rank[pb]) {
            this.version[pb] = t;
            this.parent[pb] = pa;
        } else {
            this.version[pa] = t;
            this.parent[pa] = pb;
            if (this.rank[pa] === this.rank[pb]) {
                this.rank[pb]++;
            }
        }

        return true;
    }
}

class DistanceLimitedPathsExist {
    private puf: PersistentUnionFind;

    constructor(n: number, edgeList: number[][]) {
        this.puf = new PersistentUnionFind(n);
        edgeList.sort((a, b) => a[2] - b[2]);
        for (const [u, v, dis] of edgeList) {
            this.puf.union(u, v, dis);
        }
    }

    query(p: number, q: number, limit: number): boolean {
        return this.puf.find(p, limit) === this.puf.find(q, limit);
    }
}

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * var obj = new DistanceLimitedPathsExist(n, edgeList)
 * var param_1 = obj.query(p,q,limit)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1725. 可以形成最大正方形的矩形数目](https://leetcode.cn/problems/number-of-rectangles-that-can-form-the-largest-square){#1725}

{{< tabs "1725" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        ans = mx = 0
        for l, w in rectangles:
            x = min(l, w)
            if mx < x:
                ans = 1
                mx = x
            elif mx == x:
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int ans = 0, mx = 0;
        for (var e : rectangles) {
            int x = Math.min(e[0], e[1]);
            if (mx < x) {
                mx = x;
                ans = 1;
            } else if (mx == x) {
                ++ans;
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
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0, mx = 0;
        for (auto& e : rectangles) {
            int x = min(e[0], e[1]);
            if (mx < x) {
                mx = x;
                ans = 1;
            } else if (mx == x) {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countGoodRectangles(rectangles [][]int) (ans int) {
	mx := 0
	for _, e := range rectangles {
		x := min(e[0], e[1])
		if mx < x {
			mx = x
			ans = 1
		} else if mx == x {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGoodRectangles(rectangles: number[][]): number {
    let [ans, mx] = [0, 0];
    for (const [l, w] of rectangles) {
        const x = Math.min(l, w);
        if (mx < x) {
            mx = x;
            ans = 1;
        } else if (mx === x) {
            ++ans;
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>rectangles</code> ，其中 <code>rectangles[i] = [l<sub>i</sub>, w<sub>i</sub>]</code> 表示第 <code>i</code> 个矩形的长度为 <code>l<sub>i</sub></code> 、宽度为 <code>w<sub>i</sub></code> 。</p>

<p>如果存在 <code>k</code> 同时满足 <code>k <= l<sub>i</sub></code> 和 <code>k <= w<sub>i</sub></code> ，就可以将第 <code>i</code> 个矩形切成边长为 <code>k</code> 的正方形。例如，矩形 <code>[4,6]</code> 可以切成边长最大为 <code>4</code> 的正方形。</p>

<p>设 <code>maxLen</code> 为可以从矩形数组 <code>rectangles</code> 切分得到的 <strong>最大正方形</strong> 的边长。</p>

<p>请你统计有多少个矩形能够切出边长为<em> </em><code>maxLen</code> 的正方形，并返回矩形 <strong>数目</strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rectangles = [[5,8],[3,9],[5,12],[16,5]]
<strong>输出：</strong>3
<strong>解释：</strong>能从每个矩形中切出的最大正方形边长分别是 [5,3,5,5] 。
最大正方形的边长为 5 ，可以由 3 个矩形切分得到。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rectangles = [[2,3],[3,7],[4,3],[3,7]]
<strong>输出：</strong>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= rectangles.length <= 1000</code></li>
	<li><code>rectangles[i].length == 2</code></li>
	<li><code>1 <= l<sub>i</sub>, w<sub>i</sub> <= 10<sup>9</sup></code></li>
	<li><code>l<sub>i</sub> != w<sub>i</sub></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们定义一个变量 $ans$ 来记录当前最大边长的正方形的个数，定义另一个变量 $mx$ 来记录当前最大的边长。

遍历数组 $rectangles$，对于每个矩形 $[l, w]$，我们取 $x = \min(l, w)$，如果 $mx < x$，说明我们找到了一个更大的边长，此时我们将 $mx$ 更新为 $x$，并将 $ans$ 更新为 $1$；如果 $mx = x$，说明我们找到了一个和当前最大边长相同的边长，此时我们将 $ans$ 增加 $1$。

最后返回 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $rectangles$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        ans = mx = 0
        for l, w in rectangles:
            x = min(l, w)
            if mx < x:
                ans = 1
                mx = x
            elif mx == x:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countGoodRectangles(int[][] rectangles) {
        int ans = 0, mx = 0;
        for (var e : rectangles) {
            int x = Math.min(e[0], e[1]);
            if (mx < x) {
                mx = x;
                ans = 1;
            } else if (mx == x) {
                ++ans;
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans = 0, mx = 0;
        for (auto& e : rectangles) {
            int x = min(e[0], e[1]);
            if (mx < x) {
                mx = x;
                ans = 1;
            } else if (mx == x) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countGoodRectangles(rectangles [][]int) (ans int) {
	mx := 0
	for _, e := range rectangles {
		x := min(e[0], e[1])
		if mx < x {
			mx = x
			ans = 1
		} else if mx == x {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countGoodRectangles(rectangles: number[][]): number {
    let [ans, mx] = [0, 0];
    for (const [l, w] of rectangles) {
        const x = Math.min(l, w);
        if (mx < x) {
            mx = x;
            ans = 1;
        } else if (mx === x) {
            ++ans;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1726. 同积元组](https://leetcode.cn/problems/tuple-with-same-product){#1726}

{{< tabs "1726" >}}

{{% tab "python" %}}
```python
class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        for i in range(1, len(nums)):
            for j in range(i):
                x = nums[i] * nums[j]
                cnt[x] += 1
        return sum(v * (v - 1) // 2 for v in cnt.values()) << 3
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                int x = nums[i] * nums[j];
                cnt.merge(x, 1, Integer::sum);
            }
        }
        int ans = 0;
        for (int v : cnt.values()) {
            ans += v * (v - 1) / 2;
        }
        return ans << 3;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int x = nums[i] * nums[j];
                ++cnt[x];
            }
        }
        int ans = 0;
        for (auto& [_, v] : cnt) {
            ans += v * (v - 1) / 2;
        }
        return ans << 3;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func tupleSameProduct(nums []int) int {
	cnt := map[int]int{}
	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			x := nums[i] * nums[j]
			cnt[x]++
		}
	}
	ans := 0
	for _, v := range cnt {
		ans += v * (v - 1) / 2
	}
	return ans << 3
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function tupleSameProduct(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (let i = 1; i < nums.length; ++i) {
        for (let j = 0; j < i; ++j) {
            const x = nums[i] * nums[j];
            cnt.set(x, (cnt.get(x) ?? 0) + 1);
        }
    }
    let ans = 0;
    for (const [_, v] of cnt) {
        ans += (v * (v - 1)) / 2;
    }
    return ans << 3;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        let mut ans = 0;

        for i in 1..nums.len() {
            for j in 0..i {
                let x = nums[i] * nums[j];
                *cnt.entry(x).or_insert(0) += 1;
            }
        }

        for v in cnt.values() {
            ans += (v * (v - 1)) / 2;
        }

        ans << 3
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <strong>不同</strong> 正整数组成的数组 <code>nums</code> ，请你返回满足&nbsp;<code>a * b = c * d</code> 的元组<em> </em><code>(a, b, c, d)</code><em> </em>的数量。其中 <code>a</code>、<code>b</code>、<code>c</code> 和 <code>d</code> 都是 <code>nums</code> 中的元素，且 <code>a != b != c != d</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,4,6]
<strong>输出：</strong>8
<strong>解释：</strong>存在 8 个满足题意的元组：
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,4,5,10]
<strong>输出：</strong>16
<strong>解释：</strong>存在 16 个满足题意的元组：
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 中的所有元素 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：组合数 + 哈希表

假设存在 $n$ 组数，对于其中任意两组数 $a, b$ 和 $c, d$，均满足 $a \times b = c \times d$ 的条件，则这样的组合一共有 $\mathrm{C}_n^2 = \frac{n \times (n-1)}{2}$ 个。

根据题意每一组满足上述条件的组合可以构成 $8$ 个满足题意的元组，故将各个相同乘积的组合数乘以 $8$ 相加（等价于：左移 $3$ 位）即可得到结果。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        for i in range(1, len(nums)):
            for j in range(i):
                x = nums[i] * nums[j]
                cnt[x] += 1
        return sum(v * (v - 1) // 2 for v in cnt.values()) << 3
```

#### Java

```java
class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = 1; i < nums.length; ++i) {
            for (int j = 0; j < i; ++j) {
                int x = nums[i] * nums[j];
                cnt.merge(x, 1, Integer::sum);
            }
        }
        int ans = 0;
        for (int v : cnt.values()) {
            ans += v * (v - 1) / 2;
        }
        return ans << 3;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int x = nums[i] * nums[j];
                ++cnt[x];
            }
        }
        int ans = 0;
        for (auto& [_, v] : cnt) {
            ans += v * (v - 1) / 2;
        }
        return ans << 3;
    }
};
```

#### Go

```go
func tupleSameProduct(nums []int) int {
	cnt := map[int]int{}
	for i := 1; i < len(nums); i++ {
		for j := 0; j < i; j++ {
			x := nums[i] * nums[j]
			cnt[x]++
		}
	}
	ans := 0
	for _, v := range cnt {
		ans += v * (v - 1) / 2
	}
	return ans << 3
}
```

#### TypeScript

```ts
function tupleSameProduct(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (let i = 1; i < nums.length; ++i) {
        for (let j = 0; j < i; ++j) {
            const x = nums[i] * nums[j];
            cnt.set(x, (cnt.get(x) ?? 0) + 1);
        }
    }
    let ans = 0;
    for (const [_, v] of cnt) {
        ans += (v * (v - 1)) / 2;
    }
    return ans << 3;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();
        let mut ans = 0;

        for i in 1..nums.len() {
            for j in 0..i {
                let x = nums[i] * nums[j];
                *cnt.entry(x).or_insert(0) += 1;
            }
        }

        for v in cnt.values() {
            ans += (v * (v - 1)) / 2;
        }

        ans << 3
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1727. 重新排列后的最大子矩阵](https://leetcode.cn/problems/largest-submatrix-with-rearrangements){#1727}

{{< tabs "1727" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        for i in range(1, len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]:
                    matrix[i][j] = matrix[i - 1][j] + 1
        ans = 0
        for row in matrix:
            row.sort(reverse=True)
            for j, v in enumerate(row, 1):
                ans = max(ans, j * v)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (var row : matrix) {
            Arrays.sort(row);
            for (int j = n - 1, k = 1; j >= 0 && row[j] > 0; --j, ++k) {
                int s = row[j] * k;
                ans = Math.max(ans, s);
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
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (auto& row : matrix) {
            sort(row.rbegin(), row.rend());
            for (int j = 0; j < n; ++j) {
                ans = max(ans, (j + 1) * row[j]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestSubmatrix(matrix [][]int) int {
	m, n := len(matrix), len(matrix[0])
	for i := 1; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 1 {
				matrix[i][j] = matrix[i-1][j] + 1
			}
		}
	}
	ans := 0
	for _, row := range matrix {
		sort.Ints(row)
		for j, k := n-1, 1; j >= 0 && row[j] > 0; j, k = j-1, k+1 {
			ans = max(ans, row[j]*k)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestSubmatrix(matrix: number[][]): number {
    for (let column = 0; column < matrix[0].length; column++) {
        for (let row = 0; row < matrix.length; row++) {
            let tempRow = row;
            let count = 0;

            while (tempRow < matrix.length && matrix[tempRow][column] === 1) {
                count++;
                tempRow++;
            }

            while (count !== 0) {
                matrix[row][column] = count;
                count--;
                row++;
            }
        }
    }

    for (let row = 0; row < matrix.length; row++) {
        matrix[row].sort((a, b) => a - b);
    }

    let maxSubmatrixArea = 0;

    for (let row = 0; row < matrix.length; row++) {
        for (let col = matrix[row].length - 1; col >= 0; col--) {
            maxSubmatrixArea = Math.max(
                maxSubmatrixArea,
                matrix[row][col] * (matrix[row].length - col),
            );
        }
    }

    return maxSubmatrixArea;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制矩阵 <code>matrix</code> ，它的大小为 <code>m x n</code> ，你可以将 <code>matrix</code> 中的 <strong>列</strong> 按任意顺序重新排列。</p>

<p>请你返回最优方案下将 <code>matrix</code> 重新排列后，全是 <code>1</code> 的子矩阵面积。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1727.Largest%20Submatrix%20With%20Rearrangements/images/screenshot-2020-12-30-at-40536-pm.png" style="width: 300px; height: 144px;" /></strong></p>

<pre>
<b>输入：</b>matrix = [[0,0,1],[1,1,1],[1,0,1]]
<b>输出：</b>4
<b>解释：</b>你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 4 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1727.Largest%20Submatrix%20With%20Rearrangements/images/screenshot-2020-12-30-at-40852-pm.png" style="width: 500px; height: 62px;" /></p>

<pre>
<b>输入：</b>matrix = [[1,0,1,0,1]]
<b>输出：</b>3
<b>解释：</b>你可以按照上图方式重新排列矩阵的每一列。
最大的全 1 子矩阵是上图中加粗的部分，面积为 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>matrix = [[1,1,0],[1,0,1]]
<b>输出：</b>2
<b>解释：</b>由于你只能整列整列重新排布，所以没有比面积为 2 更大的全 1 子矩形。</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>matrix = [[0,0],[0,0]]
<b>输出：</b>0
<b>解释：</b>由于矩阵中没有 1 ，没有任何全 1 的子矩阵，所以面积为 0 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m * n <= 10<sup>5</sup></code></li>
	<li><code>matrix[i][j]</code> 要么是 <code>0</code> ，要么是 <code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 排序

由于题目中矩阵是按列进行重排，因此，我们可以先对矩阵的每一列进行预处理。

对于每个值为 $1$ 的元素，我们更新其值为该元素向上的最大连续的 $1$ 的个数，即 $matrix[i][j]=matrix[i-1][j]+1$。

接下来，我们可以对更新后的矩阵的每一行进行排序。然后遍历每一行，计算以该行作为底边的最大全 $1$ 子矩阵的面积。具体计算逻辑如下：

对于矩阵的某一行，我们记第 $k$ 大元素的值为 $val_k$，其中 $k \geq 1$，那么该行至少有 $k$ 个元素不小于 $val_k$，组成的全 $1$ 子矩阵面积为 $val_k \times k$。从大到小遍历矩阵该行的每个元素，取 $val_k \times k$ 的最大值，更新答案。

时间复杂度 $O(m \times n \times \log n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        for i in range(1, len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j]:
                    matrix[i][j] = matrix[i - 1][j] + 1
        ans = 0
        for row in matrix:
            row.sort(reverse=True)
            for j, v in enumerate(row, 1):
                ans = max(ans, j * v)
        return ans
```

#### Java

```java
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (var row : matrix) {
            Arrays.sort(row);
            for (int j = n - 1, k = 1; j >= 0 && row[j] > 0; --j, ++k) {
                int s = row[j] * k;
                ans = Math.max(ans, s);
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (auto& row : matrix) {
            sort(row.rbegin(), row.rend());
            for (int j = 0; j < n; ++j) {
                ans = max(ans, (j + 1) * row[j]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestSubmatrix(matrix [][]int) int {
	m, n := len(matrix), len(matrix[0])
	for i := 1; i < m; i++ {
		for j := 0; j < n; j++ {
			if matrix[i][j] == 1 {
				matrix[i][j] = matrix[i-1][j] + 1
			}
		}
	}
	ans := 0
	for _, row := range matrix {
		sort.Ints(row)
		for j, k := n-1, 1; j >= 0 && row[j] > 0; j, k = j-1, k+1 {
			ans = max(ans, row[j]*k)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function largestSubmatrix(matrix: number[][]): number {
    for (let column = 0; column < matrix[0].length; column++) {
        for (let row = 0; row < matrix.length; row++) {
            let tempRow = row;
            let count = 0;

            while (tempRow < matrix.length && matrix[tempRow][column] === 1) {
                count++;
                tempRow++;
            }

            while (count !== 0) {
                matrix[row][column] = count;
                count--;
                row++;
            }
        }
    }

    for (let row = 0; row < matrix.length; row++) {
        matrix[row].sort((a, b) => a - b);
    }

    let maxSubmatrixArea = 0;

    for (let row = 0; row < matrix.length; row++) {
        for (let col = matrix[row].length - 1; col >= 0; col--) {
            maxSubmatrixArea = Math.max(
                maxSubmatrixArea,
                matrix[row][col] * (matrix[row].length - col),
            );
        }
    }

    return maxSubmatrixArea;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1728. 猫和老鼠 II](https://leetcode.cn/problems/cat-and-mouse-ii){#1728}

{{< tabs "1728" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        m, n = len(grid), len(grid[0])
        cat_start = mouse_start = food = 0
        dirs = (-1, 0, 1, 0, -1)
        g_mouse = [[] for _ in range(m * n)]
        g_cat = [[] for _ in range(m * n)]

        for i, row in enumerate(grid):
            for j, c in enumerate(row):
                if c == "#":
                    continue
                v = i * n + j
                if c == "C":
                    cat_start = v
                elif c == "M":
                    mouse_start = v
                elif c == "F":
                    food = v
                for a, b in pairwise(dirs):
                    for k in range(mouseJump + 1):
                        x, y = i + k * a, j + k * b
                        if not (0 <= x < m and 0 <= y < n and grid[x][y] != "#"):
                            break
                        g_mouse[v].append(x * n + y)
                    for k in range(catJump + 1):
                        x, y = i + k * a, j + k * b
                        if not (0 <= x < m and 0 <= y < n and grid[x][y] != "#"):
                            break
                        g_cat[v].append(x * n + y)
        return self.calc(g_mouse, g_cat, mouse_start, cat_start, food) == 1

    def calc(
        self,
        g_mouse: List[List[int]],
        g_cat: List[List[int]],
        mouse_start: int,
        cat_start: int,
        hole: int,
    ) -> int:
        def get_prev_states(state):
            m, c, t = state
            pt = t ^ 1
            pre = []
            if pt == 1:
                for pc in g_cat[c]:
                    if ans[m][pc][1] == 0:
                        pre.append((m, pc, pt))
            else:
                for pm in g_mouse[m]:
                    if ans[pm][c][0] == 0:
                        pre.append((pm, c, 0))
            return pre

        n = len(g_mouse)
        degree = [[[0, 0] for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                degree[i][j][0] = len(g_mouse[i])
                degree[i][j][1] = len(g_cat[j])

        ans = [[[0, 0] for _ in range(n)] for _ in range(n)]
        q = deque()
        for i in range(n):
            ans[hole][i][1] = 1
            ans[i][hole][0] = 2
            ans[i][i][1] = ans[i][i][0] = 2
            q.append((hole, i, 1))
            q.append((i, hole, 0))
            q.append((i, i, 0))
            q.append((i, i, 1))
        while q:
            state = q.popleft()
            t = ans[state[0]][state[1]][state[2]]
            for prev_state in get_prev_states(state):
                pm, pc, pt = prev_state
                if pt == t - 1:
                    ans[pm][pc][pt] = t
                    q.append(prev_state)
                else:
                    degree[pm][pc][pt] -= 1
                    if degree[pm][pc][pt] == 0:
                        ans[pm][pc][pt] = t
                        q.append(prev_state)
        return ans[mouse_start][cat_start][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public boolean canMouseWin(String[] grid, int catJump, int mouseJump) {
        int m = grid.length;
        int n = grid[0].length();
        int catStart = 0, mouseStart = 0, food = 0;
        List<Integer>[] gMouse = new List[m * n];
        List<Integer>[] gCat = new List[m * n];
        Arrays.setAll(gMouse, i -> new ArrayList<>());
        Arrays.setAll(gCat, i -> new ArrayList<>());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i].charAt(j);
                if (c == '#') {
                    continue;
                }
                int v = i * n + j;
                if (c == 'C') {
                    catStart = v;
                } else if (c == 'M') {
                    mouseStart = v;
                } else if (c == 'F') {
                    food = v;
                }

                for (int d = 0; d < 4; ++d) {
                    for (int k = 0; k <= mouseJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x].charAt(y) == '#') {
                            break;
                        }
                        gMouse[v].add(x * n + y);
                    }
                    for (int k = 0; k <= catJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x].charAt(y) == '#') {
                            break;
                        }
                        gCat[v].add(x * n + y);
                    }
                }
            }
        }

        return calc(gMouse, gCat, mouseStart, catStart, food) == 1;
    }

    private int calc(
        List<Integer>[] gMouse, List<Integer>[] gCat, int mouseStart, int catStart, int hole) {
        int n = gMouse.length;
        int[][][] degree = new int[n][n][2];
        int[][][] ans = new int[n][n][2];
        Deque<int[]> q = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][0] = gMouse[i].size();
                degree[i][j][1] = gCat[j].size();
            }
        }

        for (int i = 0; i < n; i++) {
            ans[hole][i][1] = 1;
            ans[i][hole][0] = 2;
            ans[i][i][1] = 2;
            ans[i][i][0] = 2;
            q.offer(new int[] {hole, i, 1});
            q.offer(new int[] {i, hole, 0});
            q.offer(new int[] {i, i, 0});
            q.offer(new int[] {i, i, 1});
        }

        while (!q.isEmpty()) {
            int[] state = q.poll();
            int m = state[0], c = state[1], t = state[2];
            int result = ans[m][c][t];
            for (int[] prevState : getPrevStates(gMouse, gCat, state, ans)) {
                int pm = prevState[0], pc = prevState[1], pt = prevState[2];
                if (pt == result - 1) {
                    ans[pm][pc][pt] = result;
                    q.offer(prevState);
                } else {
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        ans[pm][pc][pt] = result;
                        q.offer(prevState);
                    }
                }
            }
        }

        return ans[mouseStart][catStart][0];
    }

    private List<int[]> getPrevStates(
        List<Integer>[] gMouse, List<Integer>[] gCat, int[] state, int[][][] ans) {
        int m = state[0], c = state[1], t = state[2];
        int pt = t ^ 1;
        List<int[]> pre = new ArrayList<>();
        if (pt == 1) {
            for (int pc : gCat[c]) {
                if (ans[m][pc][1] == 0) {
                    pre.add(new int[] {m, pc, pt});
                }
            }
        } else {
            for (int pm : gMouse[m]) {
                if (ans[pm][c][0] == 0) {
                    pre.add(new int[] {pm, c, 0});
                }
            }
        }
        return pre;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
private:
    const int dirs[5] = {-1, 0, 1, 0, -1};

    int calc(vector<vector<int>>& gMouse, vector<vector<int>>& gCat, int mouseStart, int catStart, int hole) {
        int n = gMouse.size();
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2)));
        vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(2)));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][0] = gMouse[i].size();
                degree[i][j][1] = gCat[j].size();
            }
        }

        for (int i = 0; i < n; i++) {
            ans[hole][i][1] = 1;
            ans[i][hole][0] = 2;
            ans[i][i][1] = 2;
            ans[i][i][0] = 2;
            q.push(make_tuple(hole, i, 1));
            q.push(make_tuple(i, hole, 0));
            q.push(make_tuple(i, i, 0));
            q.push(make_tuple(i, i, 1));
        }

        while (!q.empty()) {
            auto state = q.front();
            q.pop();
            int m = get<0>(state), c = get<1>(state), t = get<2>(state);
            int result = ans[m][c][t];
            for (auto& prevState : getPrevStates(gMouse, gCat, state, ans)) {
                int pm = get<0>(prevState), pc = get<1>(prevState), pt = get<2>(prevState);
                if (pt == result - 1) {
                    ans[pm][pc][pt] = result;
                    q.push(prevState);
                } else {
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        ans[pm][pc][pt] = result;
                        q.push(prevState);
                    }
                }
            }
        }

        return ans[mouseStart][catStart][0];
    }

    vector<tuple<int, int, int>> getPrevStates(vector<vector<int>>& gMouse, vector<vector<int>>& gCat, tuple<int, int, int>& state, vector<vector<vector<int>>>& ans) {
        int m = get<0>(state), c = get<1>(state), t = get<2>(state);
        int pt = t ^ 1;
        vector<tuple<int, int, int>> pre;
        if (pt == 1) {
            for (int pc : gCat[c]) {
                if (ans[m][pc][1] == 0) {
                    pre.push_back(make_tuple(m, pc, pt));
                }
            }
        } else {
            for (int pm : gMouse[m]) {
                if (ans[pm][c][0] == 0) {
                    pre.push_back(make_tuple(pm, c, 0));
                }
            }
        }
        return pre;
    }

public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int m = grid.size();
        int n = grid[0].length();
        int catStart = 0, mouseStart = 0, food = 0;
        vector<vector<int>> gMouse(m * n);
        vector<vector<int>> gCat(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '#') {
                    continue;
                }
                int v = i * n + j;
                if (c == 'C') {
                    catStart = v;
                } else if (c == 'M') {
                    mouseStart = v;
                } else if (c == 'F') {
                    food = v;
                }

                for (int d = 0; d < 4; ++d) {
                    for (int k = 0; k <= mouseJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                            break;
                        }
                        gMouse[v].push_back(x * n + y);
                    }
                    for (int k = 0; k <= catJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                            break;
                        }
                        gCat[v].push_back(x * n + y);
                    }
                }
            }
        }

        return calc(gMouse, gCat, mouseStart, catStart, food) == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canMouseWin(grid []string, catJump int, mouseJump int) bool {
	m, n := len(grid), len(grid[0])
	catStart, mouseStart, food := 0, 0, 0
	dirs := []int{-1, 0, 1, 0, -1}
	gMouse := make([][]int, m*n)
	gCat := make([][]int, m*n)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			c := grid[i][j]
			if c == '#' {
				continue
			}
			v := i*n + j
			if c == 'C' {
				catStart = v
			} else if c == 'M' {
				mouseStart = v
			} else if c == 'F' {
				food = v
			}
			for d := 0; d < 4; d++ {
				a, b := dirs[d], dirs[d+1]
				for k := 0; k <= mouseJump; k++ {
					x, y := i+k*a, j+k*b
					if !(0 <= x && x < m && 0 <= y && y < n && grid[x][y] != '#') {
						break
					}
					gMouse[v] = append(gMouse[v], x*n+y)
				}
				for k := 0; k <= catJump; k++ {
					x, y := i+k*a, j+k*b
					if !(0 <= x && x < m && 0 <= y && y < n && grid[x][y] != '#') {
						break
					}
					gCat[v] = append(gCat[v], x*n+y)
				}
			}
		}
	}
	return calc(gMouse, gCat, mouseStart, catStart, food) == 1
}

func calc(gMouse, gCat [][]int, mouseStart, catStart, hole int) int {
	n := len(gMouse)
	degree := make([][][]int, n)
	ans := make([][][]int, n)
	for i := 0; i < n; i++ {
		degree[i] = make([][]int, n)
		ans[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			degree[i][j] = make([]int, 2)
			ans[i][j] = make([]int, 2)
			degree[i][j][0] = len(gMouse[i])
			degree[i][j][1] = len(gCat[j])
		}
	}

	q := list.New()
	for i := 0; i < n; i++ {
		ans[hole][i][1] = 1
		ans[i][hole][0] = 2
		ans[i][i][1] = 2
		ans[i][i][0] = 2
		q.PushBack([]int{hole, i, 1})
		q.PushBack([]int{i, hole, 0})
		q.PushBack([]int{i, i, 0})
		q.PushBack([]int{i, i, 1})
	}

	for q.Len() > 0 {
		front := q.Front()
		q.Remove(front)
		state := front.Value.([]int)
		m, c, t := state[0], state[1], state[2]
		currentAns := ans[m][c][t]
		for _, prevState := range getPrevStates(gMouse, gCat, m, c, t, ans) {
			pm, pc, pt := prevState[0], prevState[1], prevState[2]
			if pt == currentAns-1 {
				ans[pm][pc][pt] = currentAns
				q.PushBack([]int{pm, pc, pt})
			} else {
				degree[pm][pc][pt]--
				if degree[pm][pc][pt] == 0 {
					ans[pm][pc][pt] = currentAns
					q.PushBack([]int{pm, pc, pt})
				}
			}
		}
	}
	return ans[mouseStart][catStart][0]
}

func getPrevStates(gMouse, gCat [][]int, m, c, t int, ans [][][]int) [][]int {
	pt := t ^ 1
	pre := [][]int{}
	if pt == 1 {
		for _, pc := range gCat[c] {
			if ans[m][pc][1] == 0 {
				pre = append(pre, []int{m, pc, pt})
			}
		}
	} else {
		for _, pm := range gMouse[m] {
			if ans[pm][c][0] == 0 {
				pre = append(pre, []int{pm, c, pt})
			}
		}
	}
	return pre
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一只猫和一只老鼠在玩一个叫做猫和老鼠的游戏。</p>

<p>它们所处的环境设定是一个 <code>rows x cols</code> 的方格 <code>grid</code> ，其中每个格子可能是一堵墙、一块地板、一位玩家（猫或者老鼠）或者食物。</p>

<ul>
	<li>玩家由字符 <code>'C'</code> （代表猫）和 <code>'M'</code> （代表老鼠）表示。</li>
	<li>地板由字符 <code>'.'</code> 表示，玩家可以通过这个格子。</li>
	<li>墙用字符 <code>'#'</code> 表示，玩家不能通过这个格子。</li>
	<li>食物用字符 <code>'F'</code> 表示，玩家可以通过这个格子。</li>
	<li>字符 <code>'C'</code> ， <code>'M'</code> 和 <code>'F'</code> 在 <code>grid</code> 中都只会出现一次。</li>
</ul>

<p>猫和老鼠按照如下规则移动：</p>

<ul>
	<li>老鼠 <strong>先移动</strong> ，然后两名玩家轮流移动。</li>
	<li>每一次操作时，猫和老鼠可以跳到上下左右四个方向之一的格子，他们不能跳过墙也不能跳出 <code>grid</code> 。</li>
	<li><code>catJump</code> 和 <code>mouseJump</code> 是猫和老鼠分别跳一次能到达的最远距离，它们也可以跳小于最大距离的长度。</li>
	<li>它们可以停留在原地。</li>
	<li>老鼠可以跳跃过猫的位置。</li>
</ul>

<p>游戏有 4 种方式会结束：</p>

<ul>
	<li>如果猫跟老鼠处在相同的位置，那么猫获胜。</li>
	<li>如果猫先到达食物，那么猫获胜。</li>
	<li>如果老鼠先到达食物，那么老鼠获胜。</li>
	<li>如果老鼠不能在 1000 次操作以内到达食物，那么猫获胜。</li>
</ul>

<p>给你 <code>rows x cols</code> 的矩阵 <code>grid</code> 和两个整数 <code>catJump</code> 和 <code>mouseJump</code> ，双方都采取最优策略，如果老鼠获胜，那么请你返回 <code>true</code> ，否则返回 <code>false</code> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1728.Cat%20and%20Mouse%20II/images/sample_111_1955.png" style="width: 580px; height: 239px;" /></strong></p>

<pre>
<b>输入：</b>grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
<b>输出：</b>true
<b>解释：</b>猫无法抓到老鼠，也没法比老鼠先到达食物。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1728.Cat%20and%20Mouse%20II/images/sample_2_1955.png" style="width: 580px; height: 175px;" /></p>

<pre>
<b>输入：</b>grid = ["M.C...F"], catJump = 1, mouseJump = 4
<b>输出：</b>true
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>grid = ["M.C...F"], catJump = 1, mouseJump = 3
<b>输出：</b>false
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>grid = ["C...#","...#F","....#","M...."], catJump = 2, mouseJump = 5
<b>输出：</b>false
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<b>输入：</b>grid = [".M...","..#..","#..#.","C#.#.","...#F"], catJump = 3, mouseJump = 1
<b>输出：</b>true
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rows == grid.length</code></li>
	<li><code>cols = grid[i].length</code></li>
	<li><code>1 <= rows, cols <= 8</code></li>
	<li><code>grid[i][j]</code> 只包含字符 <code>'C'</code> ，<code>'M'</code> ，<code>'F'</code> ，<code>'.'</code> 和 <code>'#'</code> 。</li>
	<li><code>grid</code> 中只包含一个 <code>'C'</code> ，<code>'M'</code> 和 <code>'F'</code> 。</li>
	<li><code>1 <= catJump, mouseJump <= 8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

根据题目描述，游戏中的状态由老鼠的位置、猫的位置和移动方决定。当状态为以下情况，可以直接确定胜负：

-   当猫和老鼠的位置相同时，猫获胜，这是猫的必胜状态，老鼠的必败状态。
-   当猫先到达食物时，猫获胜，这是猫的必胜状态，老鼠的必败状态。
-   当老鼠先到达食物时，老鼠获胜，这是老鼠的必胜状态，猫的必败状态。

为了得到初始状态的游戏结果，需要从边界状态开始遍历所有的状态。每个状态包含老鼠的位置、猫的位置和移动方，根据当前状态可以得到上一轮的所有可能状态，上一轮状态的移动方和当前状态的移动方相反，上一轮状态的移动方在上一轮状态的位置和当前状态的位置不同。

我们用元组 $(m, c, t)$ 表示本轮的状态，用 $(pm, pc, pt)$ 表示上一轮可能的状态，那么上一轮的所有可能状态有：

-   如果本轮的移动方是老鼠，那么上一轮的移动方是猫，上一轮的老鼠位置是本轮老鼠位置，上一轮的猫位置是本轮猫位置的所有邻接点。
-   如果本轮的移动方是猫，那么上一轮的移动方是老鼠，上一轮的猫位置是本轮猫位置，上一轮的老鼠位置是本轮老鼠位置的所有邻接点。

初始时，除了边界状态以外，其他所有状态的结果都是未知的。我们从边界状态开始，对于每个状态，得到上一轮的所有可能状态并更新结果，更新的逻辑如下：

1. 如果上一轮的移动方与本轮的获胜方相同，那么上一轮的移动方可以到达当前状态并获胜，直接更新上一轮的状态为本轮的获胜方。
1. 如果上一轮的移动方与本轮的获胜方不同，且上一轮的移动方可以到达的所有状态都是上一轮的移动方的必败状态，那么我们将上一轮的状态更新为本轮的获胜方。

对于第 $2$ 个更新逻辑，我们需要记录每个状态的度。初始时，每个状态的度表示该状态的移动方可以移动到的结点数，即移动方所在节点的相邻结点数，如果移动方是猫且所在结点与洞相邻则需要将该状态的度减 $1$。

当所有状态的结果都更新完毕时，初始状态的结果即为最终结果。

时间复杂度 $O(m^2 \times n^2 \times (m + n)$，空间复杂度 $O(m^2 \times n^2)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        m, n = len(grid), len(grid[0])
        cat_start = mouse_start = food = 0
        dirs = (-1, 0, 1, 0, -1)
        g_mouse = [[] for _ in range(m * n)]
        g_cat = [[] for _ in range(m * n)]

        for i, row in enumerate(grid):
            for j, c in enumerate(row):
                if c == "#":
                    continue
                v = i * n + j
                if c == "C":
                    cat_start = v
                elif c == "M":
                    mouse_start = v
                elif c == "F":
                    food = v
                for a, b in pairwise(dirs):
                    for k in range(mouseJump + 1):
                        x, y = i + k * a, j + k * b
                        if not (0 <= x < m and 0 <= y < n and grid[x][y] != "#"):
                            break
                        g_mouse[v].append(x * n + y)
                    for k in range(catJump + 1):
                        x, y = i + k * a, j + k * b
                        if not (0 <= x < m and 0 <= y < n and grid[x][y] != "#"):
                            break
                        g_cat[v].append(x * n + y)
        return self.calc(g_mouse, g_cat, mouse_start, cat_start, food) == 1

    def calc(
        self,
        g_mouse: List[List[int]],
        g_cat: List[List[int]],
        mouse_start: int,
        cat_start: int,
        hole: int,
    ) -> int:
        def get_prev_states(state):
            m, c, t = state
            pt = t ^ 1
            pre = []
            if pt == 1:
                for pc in g_cat[c]:
                    if ans[m][pc][1] == 0:
                        pre.append((m, pc, pt))
            else:
                for pm in g_mouse[m]:
                    if ans[pm][c][0] == 0:
                        pre.append((pm, c, 0))
            return pre

        n = len(g_mouse)
        degree = [[[0, 0] for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                degree[i][j][0] = len(g_mouse[i])
                degree[i][j][1] = len(g_cat[j])

        ans = [[[0, 0] for _ in range(n)] for _ in range(n)]
        q = deque()
        for i in range(n):
            ans[hole][i][1] = 1
            ans[i][hole][0] = 2
            ans[i][i][1] = ans[i][i][0] = 2
            q.append((hole, i, 1))
            q.append((i, hole, 0))
            q.append((i, i, 0))
            q.append((i, i, 1))
        while q:
            state = q.popleft()
            t = ans[state[0]][state[1]][state[2]]
            for prev_state in get_prev_states(state):
                pm, pc, pt = prev_state
                if pt == t - 1:
                    ans[pm][pc][pt] = t
                    q.append(prev_state)
                else:
                    degree[pm][pc][pt] -= 1
                    if degree[pm][pc][pt] == 0:
                        ans[pm][pc][pt] = t
                        q.append(prev_state)
        return ans[mouse_start][cat_start][0]
```

#### Java

```java
class Solution {
    private final int[] dirs = {-1, 0, 1, 0, -1};

    public boolean canMouseWin(String[] grid, int catJump, int mouseJump) {
        int m = grid.length;
        int n = grid[0].length();
        int catStart = 0, mouseStart = 0, food = 0;
        List<Integer>[] gMouse = new List[m * n];
        List<Integer>[] gCat = new List[m * n];
        Arrays.setAll(gMouse, i -> new ArrayList<>());
        Arrays.setAll(gCat, i -> new ArrayList<>());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i].charAt(j);
                if (c == '#') {
                    continue;
                }
                int v = i * n + j;
                if (c == 'C') {
                    catStart = v;
                } else if (c == 'M') {
                    mouseStart = v;
                } else if (c == 'F') {
                    food = v;
                }

                for (int d = 0; d < 4; ++d) {
                    for (int k = 0; k <= mouseJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x].charAt(y) == '#') {
                            break;
                        }
                        gMouse[v].add(x * n + y);
                    }
                    for (int k = 0; k <= catJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x].charAt(y) == '#') {
                            break;
                        }
                        gCat[v].add(x * n + y);
                    }
                }
            }
        }

        return calc(gMouse, gCat, mouseStart, catStart, food) == 1;
    }

    private int calc(
        List<Integer>[] gMouse, List<Integer>[] gCat, int mouseStart, int catStart, int hole) {
        int n = gMouse.length;
        int[][][] degree = new int[n][n][2];
        int[][][] ans = new int[n][n][2];
        Deque<int[]> q = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][0] = gMouse[i].size();
                degree[i][j][1] = gCat[j].size();
            }
        }

        for (int i = 0; i < n; i++) {
            ans[hole][i][1] = 1;
            ans[i][hole][0] = 2;
            ans[i][i][1] = 2;
            ans[i][i][0] = 2;
            q.offer(new int[] {hole, i, 1});
            q.offer(new int[] {i, hole, 0});
            q.offer(new int[] {i, i, 0});
            q.offer(new int[] {i, i, 1});
        }

        while (!q.isEmpty()) {
            int[] state = q.poll();
            int m = state[0], c = state[1], t = state[2];
            int result = ans[m][c][t];
            for (int[] prevState : getPrevStates(gMouse, gCat, state, ans)) {
                int pm = prevState[0], pc = prevState[1], pt = prevState[2];
                if (pt == result - 1) {
                    ans[pm][pc][pt] = result;
                    q.offer(prevState);
                } else {
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        ans[pm][pc][pt] = result;
                        q.offer(prevState);
                    }
                }
            }
        }

        return ans[mouseStart][catStart][0];
    }

    private List<int[]> getPrevStates(
        List<Integer>[] gMouse, List<Integer>[] gCat, int[] state, int[][][] ans) {
        int m = state[0], c = state[1], t = state[2];
        int pt = t ^ 1;
        List<int[]> pre = new ArrayList<>();
        if (pt == 1) {
            for (int pc : gCat[c]) {
                if (ans[m][pc][1] == 0) {
                    pre.add(new int[] {m, pc, pt});
                }
            }
        } else {
            for (int pm : gMouse[m]) {
                if (ans[pm][c][0] == 0) {
                    pre.add(new int[] {pm, c, 0});
                }
            }
        }
        return pre;
    }
}
```

#### C++

```cpp
class Solution {
private:
    const int dirs[5] = {-1, 0, 1, 0, -1};

    int calc(vector<vector<int>>& gMouse, vector<vector<int>>& gCat, int mouseStart, int catStart, int hole) {
        int n = gMouse.size();
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(2)));
        vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(2)));
        queue<tuple<int, int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                degree[i][j][0] = gMouse[i].size();
                degree[i][j][1] = gCat[j].size();
            }
        }

        for (int i = 0; i < n; i++) {
            ans[hole][i][1] = 1;
            ans[i][hole][0] = 2;
            ans[i][i][1] = 2;
            ans[i][i][0] = 2;
            q.push(make_tuple(hole, i, 1));
            q.push(make_tuple(i, hole, 0));
            q.push(make_tuple(i, i, 0));
            q.push(make_tuple(i, i, 1));
        }

        while (!q.empty()) {
            auto state = q.front();
            q.pop();
            int m = get<0>(state), c = get<1>(state), t = get<2>(state);
            int result = ans[m][c][t];
            for (auto& prevState : getPrevStates(gMouse, gCat, state, ans)) {
                int pm = get<0>(prevState), pc = get<1>(prevState), pt = get<2>(prevState);
                if (pt == result - 1) {
                    ans[pm][pc][pt] = result;
                    q.push(prevState);
                } else {
                    degree[pm][pc][pt]--;
                    if (degree[pm][pc][pt] == 0) {
                        ans[pm][pc][pt] = result;
                        q.push(prevState);
                    }
                }
            }
        }

        return ans[mouseStart][catStart][0];
    }

    vector<tuple<int, int, int>> getPrevStates(vector<vector<int>>& gMouse, vector<vector<int>>& gCat, tuple<int, int, int>& state, vector<vector<vector<int>>>& ans) {
        int m = get<0>(state), c = get<1>(state), t = get<2>(state);
        int pt = t ^ 1;
        vector<tuple<int, int, int>> pre;
        if (pt == 1) {
            for (int pc : gCat[c]) {
                if (ans[m][pc][1] == 0) {
                    pre.push_back(make_tuple(m, pc, pt));
                }
            }
        } else {
            for (int pm : gMouse[m]) {
                if (ans[pm][c][0] == 0) {
                    pre.push_back(make_tuple(pm, c, 0));
                }
            }
        }
        return pre;
    }

public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int m = grid.size();
        int n = grid[0].length();
        int catStart = 0, mouseStart = 0, food = 0;
        vector<vector<int>> gMouse(m * n);
        vector<vector<int>> gCat(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '#') {
                    continue;
                }
                int v = i * n + j;
                if (c == 'C') {
                    catStart = v;
                } else if (c == 'M') {
                    mouseStart = v;
                } else if (c == 'F') {
                    food = v;
                }

                for (int d = 0; d < 4; ++d) {
                    for (int k = 0; k <= mouseJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                            break;
                        }
                        gMouse[v].push_back(x * n + y);
                    }
                    for (int k = 0; k <= catJump; k++) {
                        int x = i + k * dirs[d];
                        int y = j + k * dirs[d + 1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#') {
                            break;
                        }
                        gCat[v].push_back(x * n + y);
                    }
                }
            }
        }

        return calc(gMouse, gCat, mouseStart, catStart, food) == 1;
    }
};
```

#### Go

```go
func canMouseWin(grid []string, catJump int, mouseJump int) bool {
	m, n := len(grid), len(grid[0])
	catStart, mouseStart, food := 0, 0, 0
	dirs := []int{-1, 0, 1, 0, -1}
	gMouse := make([][]int, m*n)
	gCat := make([][]int, m*n)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			c := grid[i][j]
			if c == '#' {
				continue
			}
			v := i*n + j
			if c == 'C' {
				catStart = v
			} else if c == 'M' {
				mouseStart = v
			} else if c == 'F' {
				food = v
			}
			for d := 0; d < 4; d++ {
				a, b := dirs[d], dirs[d+1]
				for k := 0; k <= mouseJump; k++ {
					x, y := i+k*a, j+k*b
					if !(0 <= x && x < m && 0 <= y && y < n && grid[x][y] != '#') {
						break
					}
					gMouse[v] = append(gMouse[v], x*n+y)
				}
				for k := 0; k <= catJump; k++ {
					x, y := i+k*a, j+k*b
					if !(0 <= x && x < m && 0 <= y && y < n && grid[x][y] != '#') {
						break
					}
					gCat[v] = append(gCat[v], x*n+y)
				}
			}
		}
	}
	return calc(gMouse, gCat, mouseStart, catStart, food) == 1
}

func calc(gMouse, gCat [][]int, mouseStart, catStart, hole int) int {
	n := len(gMouse)
	degree := make([][][]int, n)
	ans := make([][][]int, n)
	for i := 0; i < n; i++ {
		degree[i] = make([][]int, n)
		ans[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			degree[i][j] = make([]int, 2)
			ans[i][j] = make([]int, 2)
			degree[i][j][0] = len(gMouse[i])
			degree[i][j][1] = len(gCat[j])
		}
	}

	q := list.New()
	for i := 0; i < n; i++ {
		ans[hole][i][1] = 1
		ans[i][hole][0] = 2
		ans[i][i][1] = 2
		ans[i][i][0] = 2
		q.PushBack([]int{hole, i, 1})
		q.PushBack([]int{i, hole, 0})
		q.PushBack([]int{i, i, 0})
		q.PushBack([]int{i, i, 1})
	}

	for q.Len() > 0 {
		front := q.Front()
		q.Remove(front)
		state := front.Value.([]int)
		m, c, t := state[0], state[1], state[2]
		currentAns := ans[m][c][t]
		for _, prevState := range getPrevStates(gMouse, gCat, m, c, t, ans) {
			pm, pc, pt := prevState[0], prevState[1], prevState[2]
			if pt == currentAns-1 {
				ans[pm][pc][pt] = currentAns
				q.PushBack([]int{pm, pc, pt})
			} else {
				degree[pm][pc][pt]--
				if degree[pm][pc][pt] == 0 {
					ans[pm][pc][pt] = currentAns
					q.PushBack([]int{pm, pc, pt})
				}
			}
		}
	}
	return ans[mouseStart][catStart][0]
}

func getPrevStates(gMouse, gCat [][]int, m, c, t int, ans [][][]int) [][]int {
	pt := t ^ 1
	pre := [][]int{}
	if pt == 1 {
		for _, pc := range gCat[c] {
			if ans[m][pc][1] == 0 {
				pre = append(pre, []int{m, pc, pt})
			}
		}
	} else {
		for _, pm := range gMouse[m] {
			if ans[pm][c][0] == 0 {
				pre = append(pre, []int{pm, c, pt})
			}
		}
	}
	return pre
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1729. 求关注者的数量](https://leetcode.cn/problems/find-followers-count){#1729}

{{< tabs "1729" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT user_id, COUNT(1) AS followers_count
FROM Followers
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Followers</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) 是这个表的主键（具有唯一值的列的组合）。
该表包含一个关注关系中关注者和用户的编号，其中关注者关注用户。</pre>

<p>&nbsp;</p>

<p>编写解决方案，对于每一个用户，返回该用户的关注者数量。</p>

<p>按&nbsp;<code>user_id</code>&nbsp;的顺序返回结果表。</p>

<p>查询结果的格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Followers 表：
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 0       | 1           |
| 1       | 0           |
| 2       | 0           |
| 2       | 1           |
+---------+-------------+
<strong>输出：</strong>
+---------+----------------+
| user_id | followers_count|
+---------+----------------+
| 0       | 1              |
| 1       | 1              |
| 2       | 2              |
+---------+----------------+
<strong>解释：</strong>
0 的关注者有 {1}
1 的关注者有 {0}
2 的关注者有 {0,1}</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们可以直接对 `Followers` 表按照 `user_id` 进行分组，然后使用 `COUNT` 函数统计每个用户的关注者数量即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT user_id, COUNT(1) AS followers_count
FROM Followers
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
