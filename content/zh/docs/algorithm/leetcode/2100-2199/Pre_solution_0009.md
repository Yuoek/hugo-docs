---
title: "2180_统计各位数字之和为偶数的整数个数"
date: 2025-10-08T18:39:03+08:00
weight: 9
tags: [二分查找, 位运算, 动态规划, 哈希表, 堆（优先队列）, 字符串, 字符串匹配, 数学, 数组, 数论, 模拟, 状态压缩, 计数, 贪心, 链表]
---

{{< markmap >}}
### [2180_统计各位数字之和为偶数的整数个数](#2180)
#### [数学](#2180)
#### [模拟](#2180)
### [2181_合并零之间的节点](#2181)
#### [链表](#2181)
#### [模拟](#2181)
### [2182_构造限制重复的字符串](#2182)
#### [贪心](#2182)
#### [哈希表](#2182)
#### [字符串](#2182)
#### [计数](#2182)
#### [堆（优先队列）](#2182)
### [2183_统计可以被 K 整除的下标对数目](#2183)
#### [数组](#2183)
#### [数学](#2183)
#### [数论](#2183)
### [2184_建造坚实的砖墙的方法数 🔒](#2184)
#### [位运算](#2184)
#### [数组](#2184)
#### [动态规划](#2184)
#### [状态压缩](#2184)
### [2185_统计包含给定前缀的字符串](#2185)
#### [数组](#2185)
#### [字符串](#2185)
#### [字符串匹配](#2185)
### [2186_制造字母异位词的最小步骤数 II](#2186)
#### [哈希表](#2186)
#### [字符串](#2186)
#### [计数](#2186)
### [2187_完成旅途的最少时间](#2187)
#### [数组](#2187)
#### [二分查找](#2187)
### [2188_完成比赛的最少时间](#2188)
#### [数组](#2188)
#### [动态规划](#2188)
### [2189_建造纸牌屋的方法数 🔒](#2189)
#### [数学](#2189)
#### [动态规划](#2189)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2180_统计各位数字之和为偶数的整数个数
___
#### 数学
___
#### 模拟
---
### 2181_合并零之间的节点
___
#### 链表
___
#### 模拟
---
### 2182_构造限制重复的字符串
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 堆（优先队列）
---
### 2183_统计可以被 K 整除的下标对数目
___
#### 数组
___
#### 数学
___
#### 数论
---
### 2184_建造坚实的砖墙的方法数 🔒
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 2185_统计包含给定前缀的字符串
___
#### 数组
___
#### 字符串
___
#### 字符串匹配
---
### 2186_制造字母异位词的最小步骤数 II
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2187_完成旅途的最少时间
___
#### 数组
___
#### 二分查找
---
### 2188_完成比赛的最少时间
___
#### 数组
___
#### 动态规划
---
### 2189_建造纸牌屋的方法数 🔒
___
#### 数学
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 哈希表 | 堆（优先队列） | 字符串 |
| 字符串匹配 | 数学 | 数组 |
| 数论 | 模拟 | 状态压缩 |
| 计数 | 贪心 | 链表 |

# [2180. 统计各位数字之和为偶数的整数个数](https://leetcode.cn/problems/count-integers-with-even-digit-sum){#2180}

{{< tabs "2180" >}}

{{% tab "python" %}}
```python
class Solution:
    def countEven(self, num: int) -> int:
        ans = num // 10 * 5 - 1
        x, s = num // 10, 0
        while x:
            s += x % 10
            x //= 10
        ans += (num % 10 + 2 - (s & 1)) >> 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countEven(int num) {
        int ans = num / 10 * 5 - 1;
        int s = 0;
        for (int x = num / 10; x > 0; x /= 10) {
            s += x % 10;
        }
        ans += (num % 10 + 2 - (s & 1)) >> 1;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countEven(int num) {
        int ans = num / 10 * 5 - 1;
        int s = 0;
        for (int x = num / 10; x > 0; x /= 10) {
            s += x % 10;
        }
        ans += (num % 10 + 2 - (s & 1)) >> 1;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countEven(num int) (ans int) {
	ans = num/10*5 - 1
	s := 0
	for x := num / 10; x > 0; x /= 10 {
		s += x % 10
	}
	ans += (num%10 + 2 - (s & 1)) >> 1
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countEven(num: number): number {
    let ans = Math.floor(num / 10) * 5 - 1;
    let s = 0;
    for (let x = Math.floor(num / 10); x; x = Math.floor(x / 10)) {
        s += x % 10;
    }
    ans += ((num % 10) + 2 - (s & 1)) >> 1;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>num</code> ，请你统计并返回 <strong>小于或等于</strong> <code>num</code> 且各位数字之和为 <strong>偶数</strong> 的正整数的数目。</p>

<p>正整数的 <strong>各位数字之和</strong> 是其所有位上的对应数字相加的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = 4
<strong>输出：</strong>2
<strong>解释：</strong>
只有 2 和 4 满足小于等于 4 且各位数字之和为偶数。    
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = 30
<strong>输出：</strong>14
<strong>解释：</strong>
只有 14 个整数满足小于等于 30 且各位数字之和为偶数，分别是： 
2、4、6、8、11、13、15、17、19、20、22、24、26 和 28 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

一种最简单直接的方法是枚举 $[1,..num]$ 的所有整数 $x$，判断 $x$ 各位数字之和是否为偶数，是则答案加一。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(1)$。其中 $n$ 为 $num$ 的值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countEven(self, num: int) -> int:
        ans = 0
        for x in range(1, num + 1):
            s = 0
            while x:
                s += x % 10
                x //= 10
            ans += s % 2 == 0
        return ans
```

#### Java

```java
class Solution {
    public int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int s = 0;
            for (int x = i; x > 0; x /= 10) {
                s += x % 10;
            }
            if (s % 2 == 0) {
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
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int s = 0;
            for (int x = i; x; x /= 10) {
                s += x % 10;
            }
            ans += s % 2 == 0;
        }
        return ans;
    }
};
```

#### Go

```go
func countEven(num int) (ans int) {
	for i := 1; i <= num; i++ {
		s := 0
		for x := i; x > 0; x /= 10 {
			s += x % 10
		}
		if s%2 == 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countEven(num: number): number {
    let ans = 0;
    for (let i = 1; i <= num; ++i) {
        let s = 0;
        for (let x = i; x; x = Math.floor(x / 10)) {
            s += x % 10;
        }
        if (s % 2 == 0) {
            ++ans;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

我们观察发现，在 $[0,..x]$ 的所有数中，每 $10$ 个数中，就有 $5$ 个数的各位数字之和为偶数。例如，在 $[0,..9]$ 中，每 $10$ 个数中，就有 $5$ 个数的各位数字之和为偶数，分别是 $0,2,4,6,8$。

因此，我们可以先算出 $num$ 中有多少个 $10$ 的倍数，然后乘以 $5$ 再减去 $1$（排除 $0$ 这个偶数），可以得到初始答案 $ans=\left\lfloor \frac{num}{10} \right\rfloor \times 5 - 1$。

接下来，我们还需要考虑剩下的 $num \% 10 + 1$ 个数字中，有多少个数的各位数字之和为偶数。这些数字是否是偶数，跟数字的前面数字之和有关，因此，我们可以算出 $num$ 的前面数字之和 $s$，那么剩余的数字中，还有 $\left\lfloor \frac{num \% 10 + 2 - (s \& 1)}{2} \right\rfloor$ 个数的各位数字之和为偶数。累加到答案 $ans$ 中即可。

我们不妨举个例子，假设 $num$ 为 $123$，那么前面 $[0,..119]$ 中一共有 $12$ 个 $10$ 的倍数，每个 $10$ 的倍数中有 $5$ 个数的各位数字之和为偶数，因此，初始答案为 $ans=12 \times 5 - 1=59$。

剩下的数字分别是 $120,121,122,123$，每个数字的前两位数字之和为 $s = 1+2=3$，是奇数，因此，剩下的数字中，只有 $2$ 个数的各位数字之和为偶数，累加到答案 $ans$ 中，最终答案为 $ans+2=61$。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为 $num$ 的值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countEven(self, num: int) -> int:
        ans = num // 10 * 5 - 1
        x, s = num // 10, 0
        while x:
            s += x % 10
            x //= 10
        ans += (num % 10 + 2 - (s & 1)) >> 1
        return ans
```

#### Java

```java
class Solution {
    public int countEven(int num) {
        int ans = num / 10 * 5 - 1;
        int s = 0;
        for (int x = num / 10; x > 0; x /= 10) {
            s += x % 10;
        }
        ans += (num % 10 + 2 - (s & 1)) >> 1;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countEven(int num) {
        int ans = num / 10 * 5 - 1;
        int s = 0;
        for (int x = num / 10; x > 0; x /= 10) {
            s += x % 10;
        }
        ans += (num % 10 + 2 - (s & 1)) >> 1;
        return ans;
    }
};
```

#### Go

```go
func countEven(num int) (ans int) {
	ans = num/10*5 - 1
	s := 0
	for x := num / 10; x > 0; x /= 10 {
		s += x % 10
	}
	ans += (num%10 + 2 - (s & 1)) >> 1
	return
}
```

#### TypeScript

```ts
function countEven(num: number): number {
    let ans = Math.floor(num / 10) * 5 - 1;
    let s = 0;
    for (let x = Math.floor(num / 10); x; x = Math.floor(x / 10)) {
        s += x % 10;
    }
    ans += ((num % 10) + 2 - (s & 1)) >> 1;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2181. 合并零之间的节点](https://leetcode.cn/problems/merge-nodes-in-between-zeros){#2181}

{{< tabs "2181" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = tail = ListNode()
        s = 0
        cur = head.next
        while cur:
            if cur.val:
                s += cur.val
            else:
                tail.next = ListNode(s)
                tail = tail.next
                s = 0
            cur = cur.next
        return dummy.next
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
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode();
        int s = 0;
        ListNode tail = dummy;
        for (ListNode cur = head.next; cur != null; cur = cur.next) {
            if (cur.val != 0) {
                s += cur.val;
            } else {
                tail.next = new ListNode(s);
                tail = tail.next;
                s = 0;
            }
        }
        return dummy.next;
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int s = 0;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            if (cur->val) {
                s += cur->val;
            } else {
                tail->next = new ListNode(s);
                tail = tail->next;
                s = 0;
            }
        }
        return dummy->next;
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
func mergeNodes(head *ListNode) *ListNode {
	dummy := &ListNode{}
	tail := dummy
	s := 0
	for cur := head.Next; cur != nil; cur = cur.Next {
		if cur.Val != 0 {
			s += cur.Val
		} else {
			tail.Next = &ListNode{Val: s}
			tail = tail.Next
			s = 0
		}
	}
	return dummy.Next
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

function mergeNodes(head: ListNode | null): ListNode | null {
    const dummy = new ListNode();
    let tail = dummy;
    let s = 0;
    for (let cur = head.next; cur; cur = cur.next) {
        if (cur.val) {
            s += cur.val;
        } else {
            tail.next = new ListNode(s);
            tail = tail.next;
            s = 0;
        }
    }
    return dummy.next;
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
    pub fn merge_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut tail = &mut dummy;
        let mut s = 0;
        let mut cur = head.unwrap().next;

        while let Some(mut node) = cur {
            if node.val != 0 {
                s += node.val;
            } else {
                tail.next = Some(Box::new(ListNode::new(s)));
                tail = tail.next.as_mut().unwrap();
                s = 0;
            }
            cur = node.next.take();
        }

        dummy.next
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    int sum = 0;
    while (head) {
        if (head->val == 0 && sum != 0) {
            cur->next = malloc(sizeof(struct ListNode));
            cur->next->val = sum;
            cur->next->next = NULL;
            cur = cur->next;
            sum = 0;
        }
        sum += head->val;
        head = head->next;
    }
    return dummy.next;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头节点 <code>head</code> ，该链表包含由 <code>0</code> 分隔开的一连串整数。链表的 <strong>开端</strong> 和 <strong>末尾</strong> 的节点都满足 <code>Node.val == 0</code> 。</p>

<p>对于每两个相邻的 <code>0</code> ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 <code>0</code> 移除，修改后的链表不应该含有任何 <code>0</code> 。</p>

<p>&nbsp;返回修改后链表的头节点 <code>head</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2181.Merge%20Nodes%20in%20Between%20Zeros/images/ex1-1.png" style="width: 600px; height: 41px;" /></strong></p>

<pre>
<strong>输入：</strong>head = [0,3,1,0,4,5,2,0]
<strong>输出：</strong>[4,11]
<strong>解释：</strong>
上图表示输入的链表。修改后的链表包含：
- 标记为绿色的节点之和：3 + 1 = 4
- 标记为红色的节点之和：4 + 5 + 2 = 11
</pre>

<p><strong>示例 2：<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2181.Merge%20Nodes%20in%20Between%20Zeros/images/ex2-1.png" style="width: 600px; height: 41px;" /></strong></p>

<pre>
<strong>输入：</strong>head = [0,1,0,3,0,2,2,0]
<strong>输出：</strong>[1,3,4]
<strong>解释：</strong>
上图表示输入的链表。修改后的链表包含：
- 标记为绿色的节点之和：1 = 1
- 标记为红色的节点之和：3 = 3
- 标记为黄色的节点之和：2 + 2 = 4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>列表中的节点数目在范围 <code>[3, 2 * 10<sup>5</sup>]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li><strong>不</strong> 存在连续两个&nbsp;<code>Node.val == 0</code> 的节点</li>
	<li>链表的 <strong>开端</strong> 和 <strong>末尾</strong> 节点都满足 <code>Node.val == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个虚拟头节点 $\textit{dummy}$，以及一个指向当前节点的指针 $\textit{tail}$，一个变量 $\textit{s}$ 用来记录当前节点的值之和。

接下来，我们从链表的第二个节点开始遍历，如果当前节点的值不为 0，我们将其加到 $\textit{s}$ 上，否则我们将 $\textit{s}$ 加到 $\textit{tail}$ 的后面，并将 $\textit{s}$ 置为 0，更新 $\textit{tail}$ 为 $\textit{tail}$ 的下一个节点。

最后，我们返回 $\textit{dummy}$ 的下一个节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = tail = ListNode()
        s = 0
        cur = head.next
        while cur:
            if cur.val:
                s += cur.val
            else:
                tail.next = ListNode(s)
                tail = tail.next
                s = 0
            cur = cur.next
        return dummy.next
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
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode();
        int s = 0;
        ListNode tail = dummy;
        for (ListNode cur = head.next; cur != null; cur = cur.next) {
            if (cur.val != 0) {
                s += cur.val;
            } else {
                tail.next = new ListNode(s);
                tail = tail.next;
                s = 0;
            }
        }
        return dummy.next;
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int s = 0;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            if (cur->val) {
                s += cur->val;
            } else {
                tail->next = new ListNode(s);
                tail = tail->next;
                s = 0;
            }
        }
        return dummy->next;
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
func mergeNodes(head *ListNode) *ListNode {
	dummy := &ListNode{}
	tail := dummy
	s := 0
	for cur := head.Next; cur != nil; cur = cur.Next {
		if cur.Val != 0 {
			s += cur.Val
		} else {
			tail.Next = &ListNode{Val: s}
			tail = tail.Next
			s = 0
		}
	}
	return dummy.Next
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

function mergeNodes(head: ListNode | null): ListNode | null {
    const dummy = new ListNode();
    let tail = dummy;
    let s = 0;
    for (let cur = head.next; cur; cur = cur.next) {
        if (cur.val) {
            s += cur.val;
        } else {
            tail.next = new ListNode(s);
            tail = tail.next;
            s = 0;
        }
    }
    return dummy.next;
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
    pub fn merge_nodes(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new(ListNode::new(0));
        let mut tail = &mut dummy;
        let mut s = 0;
        let mut cur = head.unwrap().next;

        while let Some(mut node) = cur {
            if node.val != 0 {
                s += node.val;
            } else {
                tail.next = Some(Box::new(ListNode::new(s)));
                tail = tail.next.as_mut().unwrap();
                s = 0;
            }
            cur = node.next.take();
        }

        dummy.next
    }
}
```

#### C

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode* cur = &dummy;
    int sum = 0;
    while (head) {
        if (head->val == 0 && sum != 0) {
            cur->next = malloc(sizeof(struct ListNode));
            cur->next->val = sum;
            cur->next->next = NULL;
            cur = cur->next;
            sum = 0;
        }
        sum += head->val;
        head = head->next;
    }
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2182. 构造限制重复的字符串](https://leetcode.cn/problems/construct-string-with-repeat-limit){#2182}

{{< tabs "2182" >}}

{{% tab "python" %}}
```python
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord("a")] += 1
        ans = []
        j = 24
        for i in range(25, -1, -1):
            j = min(i - 1, j)
            while 1:
                x = min(repeatLimit, cnt[i])
                cnt[i] -= x
                ans.append(ascii_lowercase[i] * x)
                if cnt[i] == 0:
                    break
                while j >= 0 and cnt[j] == 0:
                    j -= 1
                if j < 0:
                    break
                cnt[j] -= 1
                ans.append(ascii_lowercase[j])
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 25, j = 24; i >= 0; --i) {
            j = Math.min(j, i - 1);
            while (true) {
                for (int k = Math.min(cnt[i], repeatLimit); k > 0; --k) {
                    ans.append((char) ('a' + i));
                    --cnt[i];
                }
                if (cnt[i] == 0) {
                    break;
                }
                while (j >= 0 && cnt[j] == 0) {
                    --j;
                }
                if (j < 0) {
                    break;
                }
                ans.append((char) ('a' + j));
                --cnt[j];
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        string ans;
        for (int i = 25, j = 24; ~i; --i) {
            j = min(j, i - 1);
            while (1) {
                for (int k = min(cnt[i], repeatLimit); k; --k) {
                    ans += 'a' + i;
                    --cnt[i];
                }
                if (cnt[i] == 0) {
                    break;
                }
                while (j >= 0 && cnt[j] == 0) {
                    --j;
                }
                if (j < 0) {
                    break;
                }
                ans += 'a' + j;
                --cnt[j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repeatLimitedString(s string, repeatLimit int) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	var ans []byte
	for i, j := 25, 24; i >= 0; i-- {
		j = min(j, i-1)
		for {
			for k := min(cnt[i], repeatLimit); k > 0; k-- {
				ans = append(ans, byte(i+'a'))
				cnt[i]--
			}
			if cnt[i] == 0 {
				break
			}
			for j >= 0 && cnt[j] == 0 {
				j--
			}
			if j < 0 {
				break
			}
			ans = append(ans, byte(j+'a'))
			cnt[j]--
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repeatLimitedString(s: string, repeatLimit: number): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        cnt[c.charCodeAt(0) - 97]++;
    }
    const ans: string[] = [];
    for (let i = 25, j = 24; ~i; --i) {
        j = Math.min(j, i - 1);
        while (true) {
            for (let k = Math.min(cnt[i], repeatLimit); k; --k) {
                ans.push(String.fromCharCode(97 + i));
                --cnt[i];
            }
            if (!cnt[i]) {
                break;
            }
            while (j >= 0 && !cnt[j]) {
                --j;
            }
            if (j < 0) {
                break;
            }
            ans.push(String.fromCharCode(97 + j));
            --cnt[j];
        }
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个整数 <code>repeatLimit</code> ，用 <code>s</code> 中的字符构造一个新字符串 <code>repeatLimitedString</code> ，使任何字母 <strong>连续</strong> 出现的次数都不超过 <code>repeatLimit</code> 次。你不必使用 <code>s</code> 中的全部字符。</p>

<p>返回 <strong>字典序最大的</strong><em> </em><code>repeatLimitedString</code> 。</p>

<p>如果在字符串 <code>a</code> 和 <code>b</code> 不同的第一个位置，字符串 <code>a</code> 中的字母在字母表中出现时间比字符串 <code>b</code> 对应的字母晚，则认为字符串 <code>a</code> 比字符串 <code>b</code> <strong>字典序更大</strong> 。如果字符串中前 <code>min(a.length, b.length)</code> 个字符都相同，那么较长的字符串字典序更大。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "cczazcc", repeatLimit = 3
<strong>输出：</strong>"zzcccac"
<strong>解释：</strong>使用 s 中的所有字符来构造 repeatLimitedString "zzcccac"。
字母 'a' 连续出现至多 1 次。
字母 'c' 连续出现至多 3 次。
字母 'z' 连续出现至多 2 次。
因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。
该字符串是字典序最大的 repeatLimitedString ，所以返回 "zzcccac" 。
注意，尽管 "zzcccca" 字典序更大，但字母 'c' 连续出现超过 3 次，所以它不是一个有效的 repeatLimitedString 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "aababab", repeatLimit = 2
<strong>输出：</strong>"bbabaa"
<strong>解释：</strong>
使用 s 中的一些字符来构造 repeatLimitedString "bbabaa"。 
字母 'a' 连续出现至多 2 次。 
字母 'b' 连续出现至多 2 次。 
因此，没有字母连续出现超过 repeatLimit 次，字符串是一个有效的 repeatLimitedString 。 
该字符串是字典序最大的 repeatLimitedString ，所以返回 "bbabaa" 。 
注意，尽管 "bbabaaa" 字典序更大，但字母 'a' 连续出现超过 2 次，所以它不是一个有效的 repeatLimitedString 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= repeatLimit &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们先用一个长度为 $26$ 的数组 $cnt$ 统计字符串 $s$ 中每个字符出现的次数，然后从大到小枚举字母表的第 $i$ 个字母，每次取出最多 $\min(cnt[i], repeatLimit)$ 个字母 $i$，如果取完后 $cnt[i]$ 还大于 $0$，则继续取字母表中第 $j$ 个字母，其中 $j$ 是最大的满足 $j < i$ 且 $cnt[j] > 0$ 的下标，直到取完所有字母。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度，而 $\Sigma$ 是字符集，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord("a")] += 1
        ans = []
        j = 24
        for i in range(25, -1, -1):
            j = min(i - 1, j)
            while 1:
                x = min(repeatLimit, cnt[i])
                cnt[i] -= x
                ans.append(ascii_lowercase[i] * x)
                if cnt[i] == 0:
                    break
                while j >= 0 and cnt[j] == 0:
                    j -= 1
                if j < 0:
                    break
                cnt[j] -= 1
                ans.append(ascii_lowercase[j])
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 25, j = 24; i >= 0; --i) {
            j = Math.min(j, i - 1);
            while (true) {
                for (int k = Math.min(cnt[i], repeatLimit); k > 0; --k) {
                    ans.append((char) ('a' + i));
                    --cnt[i];
                }
                if (cnt[i] == 0) {
                    break;
                }
                while (j >= 0 && cnt[j] == 0) {
                    --j;
                }
                if (j < 0) {
                    break;
                }
                ans.append((char) ('a' + j));
                --cnt[j];
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        string ans;
        for (int i = 25, j = 24; ~i; --i) {
            j = min(j, i - 1);
            while (1) {
                for (int k = min(cnt[i], repeatLimit); k; --k) {
                    ans += 'a' + i;
                    --cnt[i];
                }
                if (cnt[i] == 0) {
                    break;
                }
                while (j >= 0 && cnt[j] == 0) {
                    --j;
                }
                if (j < 0) {
                    break;
                }
                ans += 'a' + j;
                --cnt[j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func repeatLimitedString(s string, repeatLimit int) string {
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
	}
	var ans []byte
	for i, j := 25, 24; i >= 0; i-- {
		j = min(j, i-1)
		for {
			for k := min(cnt[i], repeatLimit); k > 0; k-- {
				ans = append(ans, byte(i+'a'))
				cnt[i]--
			}
			if cnt[i] == 0 {
				break
			}
			for j >= 0 && cnt[j] == 0 {
				j--
			}
			if j < 0 {
				break
			}
			ans = append(ans, byte(j+'a'))
			cnt[j]--
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function repeatLimitedString(s: string, repeatLimit: number): string {
    const cnt: number[] = Array(26).fill(0);
    for (const c of s) {
        cnt[c.charCodeAt(0) - 97]++;
    }
    const ans: string[] = [];
    for (let i = 25, j = 24; ~i; --i) {
        j = Math.min(j, i - 1);
        while (true) {
            for (let k = Math.min(cnt[i], repeatLimit); k; --k) {
                ans.push(String.fromCharCode(97 + i));
                --cnt[i];
            }
            if (!cnt[i]) {
                break;
            }
            while (j >= 0 && !cnt[j]) {
                --j;
            }
            if (j < 0) {
                break;
            }
            ans.push(String.fromCharCode(97 + j));
            --cnt[j];
        }
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2183. 统计可以被 K 整除的下标对数目](https://leetcode.cn/problems/count-array-pairs-divisible-by-k){#2183}

{{< tabs "2183" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> 和一个整数 <code>k</code> ，返回满足下述条件的下标对 <code>(i, j)</code> 的数目：</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt;= n - 1</code> 且</li>
	<li><code>nums[i] * nums[j]</code> 能被 <code>k</code> 整除。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4,5], k = 2
<strong>输出：</strong>7
<strong>解释：</strong>
共有 7 对下标的对应积可以被 2 整除：
(0, 1)、(0, 3)、(1, 2)、(1, 3)、(1, 4)、(2, 3) 和 (3, 4)
它们的积分别是 2、4、6、8、10、12 和 20 。
其他下标对，例如 (0, 2) 和 (2, 4) 的乘积分别是 3 和 15 ，都无法被 2 整除。    
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4], k = 5
<strong>输出：</strong>0
<strong>解释：</strong>不存在对应积可以被 5 整除的下标对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2184. 建造坚实的砖墙的方法数 🔒](https://leetcode.cn/problems/number-of-ways-to-build-sturdy-brick-wall){#2184}

{{< tabs "2184" >}}

{{% tab "python" %}}
```python
class Solution:
    def buildWall(self, height: int, width: int, bricks: List[int]) -> int:
        def dfs(v):
            if v > width:
                return
            if v == width:
                s.append(t[:])
                return
            for x in bricks:
                t.append(x)
                dfs(v + x)
                t.pop()

        def check(a, b):
            s1, s2 = a[0], b[0]
            i = j = 1
            while i < len(a) and j < len(b):
                if s1 == s2:
                    return False
                if s1 < s2:
                    s1 += a[i]
                    i += 1
                else:
                    s2 += b[j]
                    j += 1
            return True

        mod = 10**9 + 7
        s = []
        t = []
        dfs(0)
        g = defaultdict(list)
        n = len(s)
        for i in range(n):
            if check(s[i], s[i]):
                g[i].append(i)
            for j in range(i + 1, n):
                if check(s[i], s[j]):
                    g[i].append(j)
                    g[j].append(i)
        dp = [[0] * n for _ in range(height)]
        for j in range(n):
            dp[0][j] = 1
        for i in range(1, height):
            for j in range(n):
                for k in g[j]:
                    dp[i][j] += dp[i - 1][k]
                    dp[i][j] %= mod
        return sum(dp[-1]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private static final int MOD = (int) 1e9 + 7;
    private int width;
    private int[] bricks;

    public int buildWall(int height, int width, int[] bricks) {
        this.width = width;
        this.bricks = bricks;
        dfs(0);
        int n = res.size();
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            if (check(res.get(i), res.get(i))) {
                g[i].add(i);
            }
            for (int j = i + 1; j < n; ++j) {
                if (check(res.get(i), res.get(j))) {
                    g[i].add(j);
                    g[j].add(i);
                }
            }
        }
        int[][] dp = new int[height][n];
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = (ans + dp[height - 1][j]) % MOD;
        }
        return ans;
    }

    private boolean check(List<Integer> a, List<Integer> b) {
        int s1 = a.get(0);
        int s2 = b.get(0);
        int i = 1, j = 1;
        while (i < a.size() && j < b.size()) {
            if (s1 == s2) {
                return false;
            }
            if (s1 < s2) {
                s1 += a.get(i++);
            } else {
                s2 += b.get(j++);
            }
        }
        return true;
    }

    private void dfs(int v) {
        if (v > width) {
            return;
        }
        if (v == width) {
            res.add(new ArrayList<>(t));
            return;
        }
        for (int x : bricks) {
            t.add(x);
            dfs(v + x);
            t.remove(t.size() - 1);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> bricks;
    int width;
    int mod = 1e9 + 7;
    vector<vector<int>> res;
    vector<int> t;

    int buildWall(int height, int width, vector<int>& bricks) {
        this->width = width;
        this->bricks = bricks;
        dfs(0);
        t.resize(0);
        int n = res.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (check(res[i], res[i])) {
                g[i].push_back(i);
            }
            for (int j = i + 1; j < n; ++j) {
                if (check(res[i], res[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<vector<int>> dp(height, vector<int>(n));
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= mod;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans += dp[height - 1][j];
            ans %= mod;
        }
        return ans;
    }

    bool check(vector<int>& a, vector<int>& b) {
        int s1 = a[0], s2 = b[0];
        int i = 1, j = 1;
        while (i < a.size() && j < b.size()) {
            if (s1 == s2) return false;
            if (s1 < s2)
                s1 += a[i++];
            else
                s2 += b[j++];
        }
        return true;
    }

    void dfs(int v) {
        if (v > width) return;
        if (v == width) {
            res.push_back(t);
            return;
        }
        for (int x : bricks) {
            t.push_back(x);
            dfs(v + x);
            t.pop_back();
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func buildWall(height int, width int, bricks []int) int {
	mod := int(1e9) + 7
	res := [][]int{}
	t := []int{}
	var dfs func(int)
	dfs = func(v int) {
		if v > width {
			return
		}
		if v == width {
			res = append(res, slices.Clone(t))
			return
		}
		for _, x := range bricks {
			t = append(t, x)
			dfs(v + x)
			t = t[:len(t)-1]
		}
	}
	check := func(a, b []int) bool {
		s1, s2 := a[0], b[0]
		i, j := 1, 1
		for i < len(a) && j < len(b) {
			if s1 == s2 {
				return false
			}
			if s1 < s2 {
				s1 += a[i]
				i++
			} else {
				s2 += b[j]
				j++
			}
		}
		return true
	}
	dfs(0)
	n := len(res)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		if check(res[i], res[i]) {
			g[i] = append(g[i], i)
		}
		for j := i + 1; j < n; j++ {
			if check(res[i], res[j]) {
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}
		}
	}
	dp := make([][]int, height)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for j := 0; j < n; j++ {
		dp[0][j] = 1
	}
	for i := 1; i < height; i++ {
		for j := 0; j < n; j++ {
			for _, k := range g[j] {
				dp[i][j] += dp[i-1][k]
				dp[i][j] %= mod
			}
		}
	}
	ans := 0
	for j := 0; j < n; j++ {
		ans += dp[height-1][j]
		ans %= mod
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数&nbsp;<code>height</code>&nbsp;与<code>width</code>&nbsp;，表示你要建造的砖墙的高和宽。再给你一个下标从 <strong>0</strong> 开始的数组 <code>bricks</code> ，其中第 <code>i</code> 块砖的高度是 <code>1</code> ，宽度为 <code>bricks[i]</code> 。每种砖的数量都是 <strong>无限 </strong>的，并且砖 <strong>不可以</strong> 进行旋转。</p>

<p>墙的每一行必须正好&nbsp;<code>width</code> 单位长。为了让墙体<strong> 坚实 </strong>，除了在首尾的位置，相邻的行砖缝<strong> 不能 </strong>在同一个位置。</p>

<p>请你返回建造坚实的砖墙的方法数，由于答案可能很大，需要对 <code>10<sup>9</sup> + 7</code><strong> 取余</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2184.Number%20of%20Ways%20to%20Build%20Sturdy%20Brick%20Wall/images/image-20220220190749-1.png" style="width: 919px; height: 250px;" />
<pre>
<strong>输入：</strong>height = 2, width = 3, bricks = [1,2]
<strong>输出：</strong>2
<strong>解释：</strong>前两图中的两种方法是建造一座坚实砖墙的唯二的方法。注意，第三幅图所展示的不是坚实的砖墙，因为相邻的行在中间的连接点位置相同。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>height = 1, width = 1, bricks = [5]
<strong>输出：</strong>0
<strong>解释：</strong>无法建造符合题目要求的砖墙，因为仅有的砖的长度比墙还要长。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= height &lt;= 100</code></li>
	<li><code>1 &lt;= width &lt;= 10</code></li>
	<li><code>1 &lt;= bricks.length &lt;= 10</code></li>
	<li><code>1 &lt;= bricks[i] &lt;= 10</code></li>
	<li><code>bricks</code>&nbsp;中所有数字<strong> 互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 动态规划

首先通过 DFS 构造出所有合法的排列。然后所有排列进行两两比较，找出每种排列相邻的合法排列，记录在 `g` 数组中。

然后进行动态规划。

过程是这样的：计算以某种排列结束的所有方案数。

初始化第一排每种排列的方案数为 1；每一排选取某种排列的总方案数为上一排能与自己相邻的排列的方案数之和。

答案为最后一排的方案数之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def buildWall(self, height: int, width: int, bricks: List[int]) -> int:
        def dfs(v):
            if v > width:
                return
            if v == width:
                s.append(t[:])
                return
            for x in bricks:
                t.append(x)
                dfs(v + x)
                t.pop()

        def check(a, b):
            s1, s2 = a[0], b[0]
            i = j = 1
            while i < len(a) and j < len(b):
                if s1 == s2:
                    return False
                if s1 < s2:
                    s1 += a[i]
                    i += 1
                else:
                    s2 += b[j]
                    j += 1
            return True

        mod = 10**9 + 7
        s = []
        t = []
        dfs(0)
        g = defaultdict(list)
        n = len(s)
        for i in range(n):
            if check(s[i], s[i]):
                g[i].append(i)
            for j in range(i + 1, n):
                if check(s[i], s[j]):
                    g[i].append(j)
                    g[j].append(i)
        dp = [[0] * n for _ in range(height)]
        for j in range(n):
            dp[0][j] = 1
        for i in range(1, height):
            for j in range(n):
                for k in g[j]:
                    dp[i][j] += dp[i - 1][k]
                    dp[i][j] %= mod
        return sum(dp[-1]) % mod
```

#### Java

```java
class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> t = new ArrayList<>();
    private static final int MOD = (int) 1e9 + 7;
    private int width;
    private int[] bricks;

    public int buildWall(int height, int width, int[] bricks) {
        this.width = width;
        this.bricks = bricks;
        dfs(0);
        int n = res.size();
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int i = 0; i < n; ++i) {
            if (check(res.get(i), res.get(i))) {
                g[i].add(i);
            }
            for (int j = i + 1; j < n; ++j) {
                if (check(res.get(i), res.get(j))) {
                    g[i].add(j);
                    g[j].add(i);
                }
            }
        }
        int[][] dp = new int[height][n];
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = (ans + dp[height - 1][j]) % MOD;
        }
        return ans;
    }

    private boolean check(List<Integer> a, List<Integer> b) {
        int s1 = a.get(0);
        int s2 = b.get(0);
        int i = 1, j = 1;
        while (i < a.size() && j < b.size()) {
            if (s1 == s2) {
                return false;
            }
            if (s1 < s2) {
                s1 += a.get(i++);
            } else {
                s2 += b.get(j++);
            }
        }
        return true;
    }

    private void dfs(int v) {
        if (v > width) {
            return;
        }
        if (v == width) {
            res.add(new ArrayList<>(t));
            return;
        }
        for (int x : bricks) {
            t.add(x);
            dfs(v + x);
            t.remove(t.size() - 1);
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> bricks;
    int width;
    int mod = 1e9 + 7;
    vector<vector<int>> res;
    vector<int> t;

    int buildWall(int height, int width, vector<int>& bricks) {
        this->width = width;
        this->bricks = bricks;
        dfs(0);
        t.resize(0);
        int n = res.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            if (check(res[i], res[i])) {
                g[i].push_back(i);
            }
            for (int j = i + 1; j < n; ++j) {
                if (check(res[i], res[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        vector<vector<int>> dp(height, vector<int>(n));
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        for (int i = 1; i < height; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k : g[j]) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= mod;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans += dp[height - 1][j];
            ans %= mod;
        }
        return ans;
    }

    bool check(vector<int>& a, vector<int>& b) {
        int s1 = a[0], s2 = b[0];
        int i = 1, j = 1;
        while (i < a.size() && j < b.size()) {
            if (s1 == s2) return false;
            if (s1 < s2)
                s1 += a[i++];
            else
                s2 += b[j++];
        }
        return true;
    }

    void dfs(int v) {
        if (v > width) return;
        if (v == width) {
            res.push_back(t);
            return;
        }
        for (int x : bricks) {
            t.push_back(x);
            dfs(v + x);
            t.pop_back();
        }
    }
};
```

#### Go

```go
func buildWall(height int, width int, bricks []int) int {
	mod := int(1e9) + 7
	res := [][]int{}
	t := []int{}
	var dfs func(int)
	dfs = func(v int) {
		if v > width {
			return
		}
		if v == width {
			res = append(res, slices.Clone(t))
			return
		}
		for _, x := range bricks {
			t = append(t, x)
			dfs(v + x)
			t = t[:len(t)-1]
		}
	}
	check := func(a, b []int) bool {
		s1, s2 := a[0], b[0]
		i, j := 1, 1
		for i < len(a) && j < len(b) {
			if s1 == s2 {
				return false
			}
			if s1 < s2 {
				s1 += a[i]
				i++
			} else {
				s2 += b[j]
				j++
			}
		}
		return true
	}
	dfs(0)
	n := len(res)
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		if check(res[i], res[i]) {
			g[i] = append(g[i], i)
		}
		for j := i + 1; j < n; j++ {
			if check(res[i], res[j]) {
				g[i] = append(g[i], j)
				g[j] = append(g[j], i)
			}
		}
	}
	dp := make([][]int, height)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for j := 0; j < n; j++ {
		dp[0][j] = 1
	}
	for i := 1; i < height; i++ {
		for j := 0; j < n; j++ {
			for _, k := range g[j] {
				dp[i][j] += dp[i-1][k]
				dp[i][j] %= mod
			}
		}
	}
	ans := 0
	for j := 0; j < n; j++ {
		ans += dp[height-1][j]
		ans %= mod
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2185. 统计包含给定前缀的字符串](https://leetcode.cn/problems/counting-words-with-a-given-prefix){#2185}

{{< tabs "2185" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    def insert(self, w):
        node = self
        for c in w:
            i = ord(c) - ord('a')
            if node.children[i] is None:
                node.children[i] = Trie()
            node = node.children[i]
            node.cnt += 1

    def search(self, pref):
        node = self
        for c in pref:
            i = ord(c) - ord('a')
            if node.children[i] is None:
                return 0
            node = node.children[i]
        return node.cnt


class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        tree = Trie()
        for w in words:
            tree.insert(w)
        return tree.search(pref)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private int cnt;

    public void insert(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
            ++node.cnt;
        }
    }

    public int search(String pref) {
        Trie node = this;
        for (int i = 0; i < pref.length(); ++i) {
            int j = pref.charAt(i) - 'a';
            if (node.children[j] == null) {
                return 0;
            }
            node = node.children[j];
        }
        return node.cnt;
    }
}

class Solution {
    public int prefixCount(String[] words, String pref) {
        Trie tree = new Trie();
        for (String w : words) {
            tree.insert(w);
        }
        return tree.search(pref);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    Trie()
        : children(26)
        , cnt(0) {}

    void insert(string w) {
        Trie* node = this;
        for (auto& c : w) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
            ++node->cnt;
        }
    }

    int search(string pref) {
        Trie* node = this;
        for (auto& c : pref) {
            int i = c - 'a';
            if (!node->children[i]) {
                return 0;
            }
            node = node->children[i];
        }
        return node->cnt;
    }

private:
    vector<Trie*> children;
    int cnt;
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* tree = new Trie();
        for (auto& w : words) {
            tree->insert(w);
        }
        return tree->search(pref);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(w string) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		node.cnt++
	}
}

func (this *Trie) search(pref string) int {
	node := this
	for _, c := range pref {
		c -= 'a'
		if node.children[c] == nil {
			return 0
		}
		node = node.children[c]
	}
	return node.cnt
}

func prefixCount(words []string, pref string) int {
	tree := newTrie()
	for _, w := range words {
		tree.insert(w)
	}
	return tree.search(pref)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function prefixCount(words: string[], pref: string): number {
    return words.reduce((r, s) => (r += s.startsWith(pref) ? 1 : 0), 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        words.iter().filter(|s| s.starts_with(&pref)).count() as i32
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int prefixCount(char** words, int wordsSize, char* pref) {
    int ans = 0;
    int n = strlen(pref);
    for (int i = 0; i < wordsSize; i++) {
        if (strncmp(words[i], pref, n) == 0) {
            ans++;
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

<p>给你一个字符串数组 <code>words</code> 和一个字符串 <code>pref</code> 。</p>

<p>返回 <code>words</code><em> </em>中以 <code>pref</code> 作为 <strong>前缀</strong> 的字符串的数目。</p>

<p>字符串 <code>s</code> 的 <strong>前缀</strong> 就是&nbsp; <code>s</code> 的任一前导连续字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>words = ["pay","<em><strong>at</strong></em>tention","practice","<em><strong>at</strong></em>tend"], <code>pref </code>= "at"
<strong>输出：</strong>2
<strong>解释：</strong>以 "at" 作为前缀的字符串有两个，分别是："<em><strong>at</strong></em>tention" 和 "<em><strong>at</strong></em>tend" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>words = ["leetcode","win","loops","success"], <code>pref </code>= "code"
<strong>输出：</strong>0
<strong>解释：</strong>不存在以 "code" 作为前缀的字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length, pref.length &lt;= 100</code></li>
	<li><code>words[i]</code> 和 <code>pref</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

根据题目描述，我们遍历字符串数组 `words` 中的每个字符串 $w$，判断其是否以 $pref$ 作为前缀，如果是，则答案加一。

时间复杂度 $O(n \times m)$，空间复杂度 $O(1)$。其中 $n$ 和 $m$ 分别是字符串数组 `words` 和字符串 $pref$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(w.startswith(pref) for w in words)
```

#### Java

```java
class Solution {
    public int prefixCount(String[] words, String pref) {
        int ans = 0;
        for (String w : words) {
            if (w.startsWith(pref)) {
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
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto& w : words) ans += w.find(pref) == 0;
        return ans;
    }
};
```

#### Go

```go
func prefixCount(words []string, pref string) (ans int) {
	for _, w := range words {
		if strings.HasPrefix(w, pref) {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function prefixCount(words: string[], pref: string): number {
    return words.reduce((r, s) => (r += s.startsWith(pref) ? 1 : 0), 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        words.iter().filter(|s| s.starts_with(&pref)).count() as i32
    }
}
```

#### C

```c
int prefixCount(char** words, int wordsSize, char* pref) {
    int ans = 0;
    int n = strlen(pref);
    for (int i = 0; i < wordsSize; i++) {
        if (strncmp(words[i], pref, n) == 0) {
            ans++;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀树

我们还可以使用前缀树来查询答案。

定义前缀树的每个节点结构如下：

-   `children`：长度为 $26$ 的数组，用于存储当前节点的所有子节点，其中 `children[i]` 表示当前节点的子节点；
-   `cnt`：所有以当前节点为前缀的字符串的数量。

另外，我们还需要定义两个函数：

-   其中一个函数 $insert(w)$ 用于将字符串 $w$ 插入前缀树中；
-   另一个函数 $search(pref)$ 用于查询以字符串 $pref$ 作为前缀的字符串的数量。查询时，我们从前缀树的根节点开始，遍历字符串 $pref$，如果当前节点的子节点中不存在 $pref[i]$，则说明 $pref$ 不是任何字符串的前缀，直接返回 $0$。否则，我们继续遍历 $pref$ 的下一个字符，直到遍历完 $pref$，返回当前节点的 `cnt` 即可。

有了上述函数，我们就可以查询答案了。

遍历字符串数组 `words`，对于每个字符串 $w$，调用 $insert(w)$ 函数将其插入前缀树中。最后调用 $search(pref)$ 函数作为答案返回即可。

时间复杂度 $O(L)$，空间复杂度 $O(L)$。其中 $L$ 是字符串数组 `words` 中所有字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.cnt = 0

    def insert(self, w):
        node = self
        for c in w:
            i = ord(c) - ord('a')
            if node.children[i] is None:
                node.children[i] = Trie()
            node = node.children[i]
            node.cnt += 1

    def search(self, pref):
        node = self
        for c in pref:
            i = ord(c) - ord('a')
            if node.children[i] is None:
                return 0
            node = node.children[i]
        return node.cnt


class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        tree = Trie()
        for w in words:
            tree.insert(w)
        return tree.search(pref)
```

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private int cnt;

    public void insert(String w) {
        Trie node = this;
        for (int i = 0; i < w.length(); ++i) {
            int j = w.charAt(i) - 'a';
            if (node.children[j] == null) {
                node.children[j] = new Trie();
            }
            node = node.children[j];
            ++node.cnt;
        }
    }

    public int search(String pref) {
        Trie node = this;
        for (int i = 0; i < pref.length(); ++i) {
            int j = pref.charAt(i) - 'a';
            if (node.children[j] == null) {
                return 0;
            }
            node = node.children[j];
        }
        return node.cnt;
    }
}

class Solution {
    public int prefixCount(String[] words, String pref) {
        Trie tree = new Trie();
        for (String w : words) {
            tree.insert(w);
        }
        return tree.search(pref);
    }
}
```

#### C++

```cpp
class Trie {
public:
    Trie()
        : children(26)
        , cnt(0) {}

    void insert(string w) {
        Trie* node = this;
        for (auto& c : w) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
            ++node->cnt;
        }
    }

    int search(string pref) {
        Trie* node = this;
        for (auto& c : pref) {
            int i = c - 'a';
            if (!node->children[i]) {
                return 0;
            }
            node = node->children[i];
        }
        return node->cnt;
    }

private:
    vector<Trie*> children;
    int cnt;
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* tree = new Trie();
        for (auto& w : words) {
            tree->insert(w);
        }
        return tree->search(pref);
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	cnt      int
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(w string) {
	node := this
	for _, c := range w {
		c -= 'a'
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
		node.cnt++
	}
}

func (this *Trie) search(pref string) int {
	node := this
	for _, c := range pref {
		c -= 'a'
		if node.children[c] == nil {
			return 0
		}
		node = node.children[c]
	}
	return node.cnt
}

func prefixCount(words []string, pref string) int {
	tree := newTrie()
	for _, w := range words {
		tree.insert(w)
	}
	return tree.search(pref)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2186. 制造字母异位词的最小步骤数 II](https://leetcode.cn/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii){#2186}

{{< tabs "2186" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = Counter(s)
        for c in t:
            cnt[c] -= 1
        return sum(abs(v) for v in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSteps(String s, String t) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        for (char c : t.toCharArray()) {
            --cnt[c - 'a'];
        }
        int ans = 0;
        for (int v : cnt) {
            ans += Math.abs(v);
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
    int minSteps(string s, string t) {
        vector<int> cnt(26);
        for (char& c : s) ++cnt[c - 'a'];
        for (char& c : t) --cnt[c - 'a'];
        int ans = 0;
        for (int& v : cnt) ans += abs(v);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSteps(s string, t string) int {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, c := range t {
		cnt[c-'a']--
	}
	ans := 0
	for _, v := range cnt {
		ans += abs(v)
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSteps(s: string, t: string): number {
    let cnt = new Array(128).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0)];
    }
    for (const c of t) {
        --cnt[c.charCodeAt(0)];
    }
    let ans = 0;
    for (const v of cnt) {
        ans += Math.abs(v);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function (s, t) {
    let cnt = new Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt() - 'a'.charCodeAt()];
    }
    for (const c of t) {
        --cnt[c.charCodeAt() - 'a'.charCodeAt()];
    }
    let ans = 0;
    for (const v of cnt) {
        ans += Math.abs(v);
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个字符串 <code>s</code> 和 <code>t</code> 。在一步操作中，你可以给 <code>s</code> 或者 <code>t</code> 追加 <strong>任一字符</strong> 。</p>

<p>返回使 <code>s</code> 和 <code>t</code> 互为 <strong>字母异位词</strong> 所需的最少步骤数<em>。</em></p>

<p><strong>字母异位词 </strong>指字母相同但是顺序不同（或者相同）的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "<em><strong>lee</strong>t</em>co<em><strong>de</strong></em>", t = "co<em><strong>a</strong></em>t<em><strong>s</strong></em>"
<strong>输出：</strong>7
<strong>解释：</strong>
- 执行 2 步操作，将 "as" 追加到 s = "leetcode" 中，得到 s = "leetcode<em><strong>as</strong></em>" 。
- 执行 5 步操作，将 "leede" 追加到 t = "coats" 中，得到 t = "coats<em><strong>leede</strong></em>" 。
"leetcodeas" 和 "coatsleede" 互为字母异位词。
总共用去 2 + 5 = 7 步。
可以证明，无法用少于 7 步操作使这两个字符串互为字母异位词。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "night", t = "thing"
<strong>输出：</strong>0
<strong>解释：</strong>给出的字符串已经互为字母异位词。因此，不需要任何进一步操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>s</code> 和 <code>t</code> 由小写英文字符组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = Counter(s)
        for c in t:
            cnt[c] -= 1
        return sum(abs(v) for v in cnt.values())
```

#### Java

```java
class Solution {
    public int minSteps(String s, String t) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            ++cnt[c - 'a'];
        }
        for (char c : t.toCharArray()) {
            --cnt[c - 'a'];
        }
        int ans = 0;
        for (int v : cnt) {
            ans += Math.abs(v);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26);
        for (char& c : s) ++cnt[c - 'a'];
        for (char& c : t) --cnt[c - 'a'];
        int ans = 0;
        for (int& v : cnt) ans += abs(v);
        return ans;
    }
};
```

#### Go

```go
func minSteps(s string, t string) int {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	for _, c := range t {
		cnt[c-'a']--
	}
	ans := 0
	for _, v := range cnt {
		ans += abs(v)
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function minSteps(s: string, t: string): number {
    let cnt = new Array(128).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0)];
    }
    for (const c of t) {
        --cnt[c.charCodeAt(0)];
    }
    let ans = 0;
    for (const v of cnt) {
        ans += Math.abs(v);
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function (s, t) {
    let cnt = new Array(26).fill(0);
    for (const c of s) {
        ++cnt[c.charCodeAt() - 'a'.charCodeAt()];
    }
    for (const c of t) {
        --cnt[c.charCodeAt() - 'a'.charCodeAt()];
    }
    let ans = 0;
    for (const v of cnt) {
        ans += Math.abs(v);
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2187. 完成旅途的最少时间](https://leetcode.cn/problems/minimum-time-to-complete-trips){#2187}

{{< tabs "2187" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        mx = min(time) * totalTrips
        return bisect_left(
            range(mx), totalTrips, key=lambda x: sum(x // v for v in time)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        int mi = time[0];
        for (int v : time) {
            mi = Math.min(mi, v);
        }
        long left = 1, right = (long) mi * totalTrips;
        while (left < right) {
            long cnt = 0;
            long mid = (left + right) >> 1;
            for (int v : time) {
                cnt += mid / v;
            }
            if (cnt >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mi = *min_element(time.begin(), time.end());
        long long left = 1, right = 1LL * mi * totalTrips;
        while (left < right) {
            long long cnt = 0;
            long long mid = (left + right) >> 1;
            for (int v : time) {
                cnt += mid / v;
            }
            if (cnt >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumTime(time []int, totalTrips int) int64 {
	mx := slices.Min(time) * totalTrips
	return int64(sort.Search(mx, func(x int) bool {
		cnt := 0
		for _, v := range time {
			cnt += x / v
		}
		return cnt >= totalTrips
	}))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumTime(time: number[], totalTrips: number): number {
    let left = 1n;
    let right = BigInt(Math.min(...time)) * BigInt(totalTrips);
    while (left < right) {
        const mid = (left + right) >> 1n;
        const cnt = time.reduce((acc, v) => acc + mid / BigInt(v), 0n);
        if (cnt >= BigInt(totalTrips)) {
            right = mid;
        } else {
            left = mid + 1n;
        }
    }
    return Number(left);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组&nbsp;<code>time</code>&nbsp;，其中&nbsp;<code>time[i]</code>&nbsp;表示第 <code>i</code>&nbsp;辆公交车完成 <strong>一趟</strong><strong>旅途</strong>&nbsp;所需要花费的时间。</p>

<p>每辆公交车可以 <strong>连续</strong> 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 <strong>立马开始</strong>&nbsp;下一趟旅途。每辆公交车 <strong>独立</strong>&nbsp;运行，也就是说可以同时有多辆公交车在运行且互不影响。</p>

<p>给你一个整数&nbsp;<code>totalTrips</code>&nbsp;，表示所有公交车&nbsp;<strong>总共</strong>&nbsp;需要完成的旅途数目。请你返回完成 <strong>至少</strong>&nbsp;<code>totalTrips</code>&nbsp;趟旅途需要花费的 <strong>最少</strong>&nbsp;时间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>time = [1,2,3], totalTrips = 5
<b>输出：</b>3
<strong>解释：</strong>
- 时刻 t = 1 ，每辆公交车完成的旅途数分别为 [1,0,0] 。
  已完成的总旅途数为 1 + 0 + 0 = 1 。
- 时刻 t = 2 ，每辆公交车完成的旅途数分别为 [2,1,0] 。
  已完成的总旅途数为 2 + 1 + 0 = 3 。
- 时刻 t = 3 ，每辆公交车完成的旅途数分别为 [3,1,1] 。
  已完成的总旅途数为 3 + 1 + 1 = 5 。
所以总共完成至少 5 趟旅途的最少时间为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>time = [2], totalTrips = 1
<b>输出：</b>2
<strong>解释：</strong>
只有一辆公交车，它将在时刻 t = 2 完成第一趟旅途。
所以完成 1 趟旅途的最少时间为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= time.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= time[i], totalTrips &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果我们能在 $t$ 时间内至少完成 $totalTrips$ 趟旅途，那么在 $t' > t$ 时间内也能至少完成 $totalTrips$ 趟旅途。因此我们可以使用二分查找的方法来找到最小的 $t$。

我们定义二分查找的左边界 $l = 1$，右边界 $r = \min(time) \times \textit{totalTrips}$。每一次二分查找，我们计算中间值 $\textit{mid} = \frac{l + r}{2}$，然后计算在 $\textit{mid}$ 时间内能完成的旅途数目。如果这个数目大于等于 $\textit{totalTrips}$，那么我们将右边界缩小到 $\textit{mid}$，否则我们将左边界扩大到 $\textit{mid} + 1$。

最后返回左边界即可。

时间复杂度 $O(n \times \log(m \times k))$，其中 $n$ 和 $k$ 分别是数组 $time$ 的长度和 $totalTrips$，而 $m$ 是数组 $time$ 中的最小值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        mx = min(time) * totalTrips
        return bisect_left(
            range(mx), totalTrips, key=lambda x: sum(x // v for v in time)
        )
```

#### Java

```java
class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        int mi = time[0];
        for (int v : time) {
            mi = Math.min(mi, v);
        }
        long left = 1, right = (long) mi * totalTrips;
        while (left < right) {
            long cnt = 0;
            long mid = (left + right) >> 1;
            for (int v : time) {
                cnt += mid / v;
            }
            if (cnt >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int mi = *min_element(time.begin(), time.end());
        long long left = 1, right = 1LL * mi * totalTrips;
        while (left < right) {
            long long cnt = 0;
            long long mid = (left + right) >> 1;
            for (int v : time) {
                cnt += mid / v;
            }
            if (cnt >= totalTrips) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func minimumTime(time []int, totalTrips int) int64 {
	mx := slices.Min(time) * totalTrips
	return int64(sort.Search(mx, func(x int) bool {
		cnt := 0
		for _, v := range time {
			cnt += x / v
		}
		return cnt >= totalTrips
	}))
}
```

#### TypeScript

```ts
function minimumTime(time: number[], totalTrips: number): number {
    let left = 1n;
    let right = BigInt(Math.min(...time)) * BigInt(totalTrips);
    while (left < right) {
        const mid = (left + right) >> 1n;
        const cnt = time.reduce((acc, v) => acc + mid / BigInt(v), 0n);
        if (cnt >= BigInt(totalTrips)) {
            right = mid;
        } else {
            left = mid + 1n;
        }
    }
    return Number(left);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2188. 完成比赛的最少时间](https://leetcode.cn/problems/minimum-time-to-finish-the-race){#2188}

{{< tabs "2188" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumFinishTime(
        self, tires: List[List[int]], changeTime: int, numLaps: int
    ) -> int:
        cost = [inf] * 18
        for f, r in tires:
            i, s, t = 1, 0, f
            while t <= changeTime + f:
                s += t
                cost[i] = min(cost[i], s)
                t *= r
                i += 1
        f = [inf] * (numLaps + 1)
        f[0] = -changeTime
        for i in range(1, numLaps + 1):
            for j in range(1, min(18, i + 1)):
                f[i] = min(f[i], f[i - j] + cost[j])
            f[i] += changeTime
        return f[numLaps]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumFinishTime(int[][] tires, int changeTime, int numLaps) {
        final int inf = 1 << 30;
        int[] cost = new int[18];
        Arrays.fill(cost, inf);
        for (int[] e : tires) {
            int f = e[0], r = e[1];
            int s = 0, t = f;
            for (int i = 1; t <= changeTime + f; ++i) {
                s += t;
                cost[i] = Math.min(cost[i], s);
                t *= r;
            }
        }
        int[] f = new int[numLaps + 1];
        Arrays.fill(f, inf);
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j < Math.min(18, i + 1); ++j) {
                f[i] = Math.min(f[i], f[i - j] + cost[j]);
            }
            f[i] += changeTime;
        }
        return f[numLaps];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int cost[18];
        memset(cost, 0x3f, sizeof(cost));
        for (auto& e : tires) {
            int f = e[0], r = e[1];
            int s = 0;
            long long t = f;
            for (int i = 1; t <= changeTime + f; ++i) {
                s += t;
                cost[i] = min(cost[i], s);
                t *= r;
            }
        }
        int f[numLaps + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j < min(18, i + 1); ++j) {
                f[i] = min(f[i], f[i - j] + cost[j]);
            }
            f[i] += changeTime;
        }
        return f[numLaps];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumFinishTime(tires [][]int, changeTime int, numLaps int) int {
	const inf = 1 << 30
	cost := [18]int{}
	for i := range cost {
		cost[i] = inf
	}
	for _, e := range tires {
		f, r := e[0], e[1]
		s, t := 0, f
		for i := 1; t <= changeTime+f; i++ {
			s += t
			cost[i] = min(cost[i], s)
			t *= r
		}
	}
	f := make([]int, numLaps+1)
	for i := range f {
		f[i] = inf
	}
	f[0] = -changeTime
	for i := 1; i <= numLaps; i++ {
		for j := 1; j < min(18, i+1); j++ {
			f[i] = min(f[i], f[i-j]+cost[j])
		}
		f[i] += changeTime
	}
	return f[numLaps]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumFinishTime(tires: number[][], changeTime: number, numLaps: number): number {
    const cost: number[] = Array(18).fill(Infinity);
    for (const [f, r] of tires) {
        let s = 0;
        let t = f;
        for (let i = 1; t <= changeTime + f; ++i) {
            s += t;
            cost[i] = Math.min(cost[i], s);
            t *= r;
        }
    }
    const f: number[] = Array(numLaps + 1).fill(Infinity);
    f[0] = -changeTime;
    for (let i = 1; i <= numLaps; ++i) {
        for (let j = 1; j < Math.min(18, i + 1); ++j) {
            f[i] = Math.min(f[i], f[i - j] + cost[j]);
        }
        f[i] += changeTime;
    }
    return f[numLaps];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>tires</code>&nbsp;，其中&nbsp;<code>tires[i] = [f<sub>i</sub>, r<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;种轮胎如果连续使用，第&nbsp;<code>x</code>&nbsp;圈需要耗时&nbsp;<code>f<sub>i</sub> * r<sub>i</sub><sup>(x-1)</sup></code>&nbsp;秒。</p>

<ul>
	<li>比方说，如果&nbsp;<code>f<sub>i</sub> = 3</code>&nbsp;且&nbsp;<code>r<sub>i</sub> = 2</code>&nbsp;，且一直使用这种类型的同一条轮胎，那么该轮胎完成第&nbsp;<code>1</code>&nbsp;圈赛道耗时 <code>3</code>&nbsp;秒，完成第 <code>2</code>&nbsp;圈耗时&nbsp;<code>3 * 2 = 6</code>&nbsp;秒，完成第 <code>3</code>&nbsp;圈耗时&nbsp;<code>3 * 2<sup>2</sup> = 12</code>&nbsp;秒，依次类推。</li>
</ul>

<p>同时给你一个整数&nbsp;<code>changeTime</code>&nbsp;和一个整数&nbsp;<code>numLaps</code>&nbsp;。</p>

<p>比赛总共包含&nbsp;<code>numLaps</code>&nbsp;圈，你可以选择 <strong>任意</strong>&nbsp;一种轮胎开始比赛。每一种轮胎都有 <strong>无数条</strong>&nbsp;。每一圈后，你可以选择耗费 <code>changeTime</code>&nbsp;秒 <strong>换成</strong>&nbsp;任意一种轮胎（也可以换成当前种类的新轮胎）。</p>

<p>请你返回完成比赛需要耗费的 <strong>最少</strong>&nbsp;时间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
<b>输出：</b>21
<b>解释：</b>
第 1 圈：使用轮胎 0 ，耗时 2 秒。
第 2 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
第 3 圈：耗费 5 秒换一条新的轮胎 0 ，然后耗时 2 秒完成这一圈。
第 4 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
总耗时 = 2 + 6 + 5 + 2 + 6 = 21 秒。
完成比赛的最少时间为 21 秒。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
<b>输出：</b>25
<b>解释：</b>
第 1 圈：使用轮胎 1 ，耗时 2 秒。
第 2 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
第 3 圈：耗时 6 秒换一条新的轮胎 1 ，然后耗时 2 秒完成这一圈。
第 4 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
第 5 圈：耗时 6 秒换成轮胎 0 ，然后耗时 1 秒完成这一圈。
总耗时 = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 秒。
完成比赛的最少时间为 25 秒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tires.length &lt;= 10<sup>5</sup></code></li>
	<li><code>tires[i].length == 2</code></li>
	<li><code>1 &lt;= f<sub>i</sub>, changeTime &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= r<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= numLaps &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 动态规划

我们注意到，连续使用同一个轮胎 $(f, r)$ 跑 $i$ 圈，那么第 $i$ 圈的耗时不应该超过 $changeTime + f$，否则我们可以在第 $i$ 圈的时候换轮胎，这样总耗时会更少。即：

$$
f \times r^{i-1} \leq changeTime + f
$$

我们可以求出满足上式的最大的 $i$，要使得 $i$ 最大，那么 $f$ 和 $r$ 应该尽可能小，根据题目的数据范围，我们取 $f=1$, $r=2$，那么 $2^{i-1} \leq changeTime + 1$，即 $i \leq \log_2(changeTime + 1) + 1$。根据这个结论，以及题目中 $changeTime$ 的数据范围，我们可以知道 $i$ 最大为 $17$。

我们定义 $cost[i]$ 表示使用同一个轮胎跑 $i$ 圈的最小耗时，那么我们可以预处理出 $cost$ 数组，然后使用动态规划求解即可。定义 $f[i]$ 表示跑 $i$ 圈的最小耗时，那么我们可以得到状态转移方程：

$$
f[i] = (\min_{1 \leq j \leq \min(17, i)} f[i-j] + cost[j]) + changeTime
$$

初始时 $f[0] = -changeTime$，最终答案为 $f[numLaps]$。

时间复杂度 $O((n + numLaps) \times \log T_{max})$，空间复杂度 $O(n + \log T_{max})$，其中 $T_{max}$ 是题目中 $f_i$, $r_i$ 和 $changeTime$ 的最大值。本题中 $\log T_{max} \approx 17$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumFinishTime(
        self, tires: List[List[int]], changeTime: int, numLaps: int
    ) -> int:
        cost = [inf] * 18
        for f, r in tires:
            i, s, t = 1, 0, f
            while t <= changeTime + f:
                s += t
                cost[i] = min(cost[i], s)
                t *= r
                i += 1
        f = [inf] * (numLaps + 1)
        f[0] = -changeTime
        for i in range(1, numLaps + 1):
            for j in range(1, min(18, i + 1)):
                f[i] = min(f[i], f[i - j] + cost[j])
            f[i] += changeTime
        return f[numLaps]
```

#### Java

```java
class Solution {
    public int minimumFinishTime(int[][] tires, int changeTime, int numLaps) {
        final int inf = 1 << 30;
        int[] cost = new int[18];
        Arrays.fill(cost, inf);
        for (int[] e : tires) {
            int f = e[0], r = e[1];
            int s = 0, t = f;
            for (int i = 1; t <= changeTime + f; ++i) {
                s += t;
                cost[i] = Math.min(cost[i], s);
                t *= r;
            }
        }
        int[] f = new int[numLaps + 1];
        Arrays.fill(f, inf);
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j < Math.min(18, i + 1); ++j) {
                f[i] = Math.min(f[i], f[i - j] + cost[j]);
            }
            f[i] += changeTime;
        }
        return f[numLaps];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int cost[18];
        memset(cost, 0x3f, sizeof(cost));
        for (auto& e : tires) {
            int f = e[0], r = e[1];
            int s = 0;
            long long t = f;
            for (int i = 1; t <= changeTime + f; ++i) {
                s += t;
                cost[i] = min(cost[i], s);
                t *= r;
            }
        }
        int f[numLaps + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = -changeTime;
        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j < min(18, i + 1); ++j) {
                f[i] = min(f[i], f[i - j] + cost[j]);
            }
            f[i] += changeTime;
        }
        return f[numLaps];
    }
};
```

#### Go

```go
func minimumFinishTime(tires [][]int, changeTime int, numLaps int) int {
	const inf = 1 << 30
	cost := [18]int{}
	for i := range cost {
		cost[i] = inf
	}
	for _, e := range tires {
		f, r := e[0], e[1]
		s, t := 0, f
		for i := 1; t <= changeTime+f; i++ {
			s += t
			cost[i] = min(cost[i], s)
			t *= r
		}
	}
	f := make([]int, numLaps+1)
	for i := range f {
		f[i] = inf
	}
	f[0] = -changeTime
	for i := 1; i <= numLaps; i++ {
		for j := 1; j < min(18, i+1); j++ {
			f[i] = min(f[i], f[i-j]+cost[j])
		}
		f[i] += changeTime
	}
	return f[numLaps]
}
```

#### TypeScript

```ts
function minimumFinishTime(tires: number[][], changeTime: number, numLaps: number): number {
    const cost: number[] = Array(18).fill(Infinity);
    for (const [f, r] of tires) {
        let s = 0;
        let t = f;
        for (let i = 1; t <= changeTime + f; ++i) {
            s += t;
            cost[i] = Math.min(cost[i], s);
            t *= r;
        }
    }
    const f: number[] = Array(numLaps + 1).fill(Infinity);
    f[0] = -changeTime;
    for (let i = 1; i <= numLaps; ++i) {
        for (let j = 1; j < Math.min(18, i + 1); ++j) {
            f[i] = Math.min(f[i], f[i - j] + cost[j]);
        }
        f[i] += changeTime;
    }
    return f[numLaps];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2189. 建造纸牌屋的方法数 🔒](https://leetcode.cn/problems/number-of-ways-to-build-house-of-cards){#2189}

{{< tabs "2189" >}}

{{% tab "python" %}}
```python
class Solution:
    def houseOfCards(self, n: int) -> int:
        @cache
        def dfs(n: int, k: int) -> int:
            x = 3 * k + 2
            if x > n:
                return 0
            if x == n:
                return 1
            return dfs(n - x, k + 1) + dfs(n, k + 1)

        return dfs(n, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;

    public int houseOfCards(int n) {
        f = new Integer[n + 1][n / 3];
        return dfs(n, 0);
    }

    private int dfs(int n, int k) {
        int x = 3 * k + 2;
        if (x > n) {
            return 0;
        }
        if (x == n) {
            return 1;
        }
        if (f[n][k] != null) {
            return f[n][k];
        }
        return f[n][k] = dfs(n - x, k + 1) + dfs(n, k + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int houseOfCards(int n) {
        int f[n + 1][n / 3 + 1];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int n, int k) -> int {
            int x = 3 * k + 2;
            if (x > n) {
                return 0;
            }
            if (x == n) {
                return 1;
            }
            if (f[n][k] != -1) {
                return f[n][k];
            }
            return f[n][k] = dfs(n - x, k + 1) + dfs(n, k + 1);
        };
        return dfs(n, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func houseOfCards(n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n/3+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(n, k int) int
	dfs = func(n, k int) int {
		x := 3*k + 2
		if x > n {
			return 0
		}
		if x == n {
			return 1
		}
		if f[n][k] == -1 {
			f[n][k] = dfs(n-x, k+1) + dfs(n, k+1)
		}
		return f[n][k]
	}
	return dfs(n, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function houseOfCards(n: number): number {
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(Math.floor(n / 3) + 1).fill(-1));
    const dfs = (n: number, k: number): number => {
        const x = k * 3 + 2;
        if (x > n) {
            return 0;
        }
        if (x === n) {
            return 1;
        }
        if (f[n][k] === -1) {
            f[n][k] = dfs(n - x, k + 1) + dfs(n, k + 1);
        }
        return f[n][k];
    };
    return dfs(n, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code>，代表你拥有牌的数量。一个&nbsp;<strong>纸牌屋&nbsp;</strong>满足以下条件:</p>

<ul>
	<li>一个<strong> 纸牌屋&nbsp;</strong>由一行或多行&nbsp;<strong>三角形</strong> 和水平纸牌组成。</li>
	<li><strong>三角形&nbsp;</strong>是由两张纸牌相互靠在一起形成的。</li>
	<li>一张纸牌必须水平放置在一行中&nbsp;<strong>所有相邻&nbsp;</strong>的三角形之间。</li>
	<li>比第一行高的任何三角形都必须放在前一行的水平纸牌上。</li>
	<li>每个三角形都被放置在行中&nbsp;<strong>最左边&nbsp;</strong>的可用位置。</li>
</ul>

<p>返回<em>使用所有 <code>n</code> 张</em>纸牌<em>可以构建的不同纸牌屋的数量</em>。如果存在一行两个纸牌屋包含不同数量的纸牌，那么两个纸牌屋被认为是不同的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2189.Number%20of%20Ways%20to%20Build%20House%20of%20Cards/images/image-20220227213243-1.png" style="width: 726px; height: 150px;" />
<pre>
<strong>输入:</strong> n = 16
<strong>输出:</strong> 2
<strong>解释:</strong> 有两种有效的纸牌屋摆法。
图中的第三个纸牌屋无效，因为第一行最右边的三角形没有放在水平纸牌的顶部。
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2189.Number%20of%20Ways%20to%20Build%20House%20of%20Cards/images/image-20220227213306-2.png" style="width: 96px; height: 80px;" />
<pre>
<strong>输入:</strong> n = 2
<strong>输出:</strong> 1
<strong>解释:</strong> 这是唯一可行的纸牌屋。</pre>

<p><strong class="example">Example 3:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2189.Number%20of%20Ways%20to%20Build%20House%20of%20Cards/images/image-20220227213331-3.png" style="width: 330px; height: 85px;" />
<pre>
<strong>输入:</strong> n = 4
<strong>输出:</strong> 0
<strong>解释:</strong> 图中的三种纸牌都是无效的。
第一个纸牌屋需要在两个三角形之间放置一张水平纸牌。
第二个纸牌屋使用 5 张纸牌。
第三个纸牌屋使用 2 张纸牌。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们注意到，每一层的卡片数量为 $3 \times k + 2$，并且每一层的卡片数量都不相同。因此，问题可以转化为：整数 $n$ 可以由多少种 $3 \times k + 2$ 的数相加得到。这是一个经典的背包问题，可以使用记忆化搜索解决。

我们设计一个函数 $\text{dfs}(n, k)$，表示当前剩余卡片数量为 $n$，且当前层为 $k$ 时，可以构建多少不同的纸牌屋。那么答案就是 $\text{dfs}(n, 0)$。

函数 $\text{dfs}(n, k)$ 的执行逻辑如下：

-   如果 $3 \times k + 2 \gt n$，那么当前层无法放置任何卡片，返回 $0$；
-   如果 $3 \times k + 2 = n$，那么当前层可以放置卡片，放置完毕后，整个纸牌屋已经构建完毕，返回 $1$；
-   否则，我们可以选择不放置卡片，或者放置卡片。如果选择不放置卡片，那么剩余卡片数量不变，层数增加 $1$，即 $\text{dfs}(n, k + 1)$；如果选择放置卡片，那么剩余卡片数量减少 $3 \times k + 2$，层数增加 $1$，即 $\text{dfs}(n - (3 \times k + 2), k + 1)$。两者相加即为答案。

过程中，我们可以使用记忆化搜索，避免重复计算。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为卡片数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def houseOfCards(self, n: int) -> int:
        @cache
        def dfs(n: int, k: int) -> int:
            x = 3 * k + 2
            if x > n:
                return 0
            if x == n:
                return 1
            return dfs(n - x, k + 1) + dfs(n, k + 1)

        return dfs(n, 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;

    public int houseOfCards(int n) {
        f = new Integer[n + 1][n / 3];
        return dfs(n, 0);
    }

    private int dfs(int n, int k) {
        int x = 3 * k + 2;
        if (x > n) {
            return 0;
        }
        if (x == n) {
            return 1;
        }
        if (f[n][k] != null) {
            return f[n][k];
        }
        return f[n][k] = dfs(n - x, k + 1) + dfs(n, k + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int houseOfCards(int n) {
        int f[n + 1][n / 3 + 1];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int n, int k) -> int {
            int x = 3 * k + 2;
            if (x > n) {
                return 0;
            }
            if (x == n) {
                return 1;
            }
            if (f[n][k] != -1) {
                return f[n][k];
            }
            return f[n][k] = dfs(n - x, k + 1) + dfs(n, k + 1);
        };
        return dfs(n, 0);
    }
};
```

#### Go

```go
func houseOfCards(n int) int {
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n/3+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(n, k int) int
	dfs = func(n, k int) int {
		x := 3*k + 2
		if x > n {
			return 0
		}
		if x == n {
			return 1
		}
		if f[n][k] == -1 {
			f[n][k] = dfs(n-x, k+1) + dfs(n, k+1)
		}
		return f[n][k]
	}
	return dfs(n, 0)
}
```

#### TypeScript

```ts
function houseOfCards(n: number): number {
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(Math.floor(n / 3) + 1).fill(-1));
    const dfs = (n: number, k: number): number => {
        const x = k * 3 + 2;
        if (x > n) {
            return 0;
        }
        if (x === n) {
            return 1;
        }
        if (f[n][k] === -1) {
            f[n][k] = dfs(n - x, k + 1) + dfs(n, k + 1);
        }
        return f[n][k];
    };
    return dfs(n, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
