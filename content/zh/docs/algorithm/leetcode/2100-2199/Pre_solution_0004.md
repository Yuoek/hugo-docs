---
title: "2130_链表最大孪生和"
date: 2025-10-08T18:39:03+08:00
weight: 4
tags: [二分查找, 位运算, 前缀和, 双指针, 哈希表, 字符串, 排序, 数学, 数组, 栈, 模拟, 滑动窗口, 矩阵, 计数, 贪心, 链表]
---

{{< markmap >}}
### [2130_链表最大孪生和](#2130)
#### [栈](#2130)
#### [链表](#2130)
#### [双指针](#2130)
### [2131_连接两字母单词得到的最长回文串](#2131)
#### [贪心](#2131)
#### [数组](#2131)
#### [哈希表](#2131)
#### [字符串](#2131)
#### [计数](#2131)
### [2132_用邮票贴满网格图](#2132)
#### [贪心](#2132)
#### [数组](#2132)
#### [矩阵](#2132)
#### [前缀和](#2132)
### [2133_检查是否每一行每一列都包含全部整数](#2133)
#### [数组](#2133)
#### [哈希表](#2133)
#### [矩阵](#2133)
### [2134_最少交换次数来组合所有的 1 II](#2134)
#### [数组](#2134)
#### [滑动窗口](#2134)
### [2135_统计追加字母可以获得的单词数](#2135)
#### [位运算](#2135)
#### [数组](#2135)
#### [哈希表](#2135)
#### [字符串](#2135)
#### [排序](#2135)
### [2136_全部开花的最早一天](#2136)
#### [贪心](#2136)
#### [数组](#2136)
#### [排序](#2136)
### [2137_通过倒水操作让所有的水桶所含水量相等 🔒](#2137)
#### [数组](#2137)
#### [二分查找](#2137)
### [2138_将字符串拆分为若干长度为 k 的组](#2138)
#### [字符串](#2138)
#### [模拟](#2138)
### [2139_得到目标值的最少行动次数](#2139)
#### [贪心](#2139)
#### [数学](#2139)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2130_链表最大孪生和
___
#### 栈
___
#### 链表
___
#### 双指针
---
### 2131_连接两字母单词得到的最长回文串
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2132_用邮票贴满网格图
___
#### 贪心
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 2133_检查是否每一行每一列都包含全部整数
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 2134_最少交换次数来组合所有的 1 II
___
#### 数组
___
#### 滑动窗口
---
### 2135_统计追加字母可以获得的单词数
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 2136_全部开花的最早一天
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2137_通过倒水操作让所有的水桶所含水量相等 🔒
___
#### 数组
___
#### 二分查找
---
### 2138_将字符串拆分为若干长度为 k 的组
___
#### 字符串
___
#### 模拟
---
### 2139_得到目标值的最少行动次数
___
#### 贪心
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 双指针 | 哈希表 | 字符串 |
| 排序 | 数学 | 数组 |
| 栈 | 模拟 | 滑动窗口 |
| 矩阵 | 计数 | 贪心 |
| 链表 |  |  |

# [2130. 链表最大孪生和](https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list){#2130}

{{< tabs "2130" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        def reverse(head):
            dummy = ListNode()
            curr = head
            while curr:
                next = curr.next
                curr.next = dummy.next
                dummy.next = curr
                curr = next
            return dummy.next

        slow, fast = head, head.next
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        pa = head
        q = slow.next
        slow.next = None
        pb = reverse(q)
        ans = 0
        while pa and pb:
            ans = max(ans, pa.val + pb.val)
            pa = pa.next
            pb = pb.next
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
    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode pa = head;
        ListNode q = slow.next;
        slow.next = null;
        ListNode pb = reverse(q);
        int ans = 0;
        while (pa != null) {
            ans = Math.max(ans, pa.val + pb.val);
            pa = pa.next;
            pb = pb.next;
        }
        return ans;
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = dummy.next;
            dummy.next = curr;
            curr = next;
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pa = head;
        ListNode* q = slow->next;
        slow->next = nullptr;
        ListNode* pb = reverse(q);
        int ans = 0;
        while (pa) {
            ans = max(ans, pa->val + pb->val);
            pa = pa->next;
            pb = pb->next;
        }
        return ans;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            curr = next;
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
func pairSum(head *ListNode) int {
	reverse := func(head *ListNode) *ListNode {
		dummy := &ListNode{}
		curr := head
		for curr != nil {
			next := curr.Next
			curr.Next = dummy.Next
			dummy.Next = curr
			curr = next
		}
		return dummy.Next
	}
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	pa := head
	q := slow.Next
	slow.Next = nil
	pb := reverse(q)
	ans := 0
	for pa != nil {
		ans = max(ans, pa.Val+pb.Val)
		pa = pa.Next
		pb = pb.Next
	}
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

function pairSum(head: ListNode | null): number {
    let fast = head;
    let slow = head;
    while (fast) {
        fast = fast.next.next;
        slow = slow.next;
    }
    let prev = null;
    while (slow) {
        const next = slow.next;
        slow.next = prev;
        prev = slow;
        slow = next;
    }
    let left = head;
    let right = prev;
    let ans = 0;
    while (left && right) {
        ans = Math.max(ans, left.val + right.val);
        left = left.next;
        right = right.next;
    }
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
    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        let mut arr = Vec::new();
        let mut node = &head;
        while node.is_some() {
            let t = node.as_ref().unwrap();
            arr.push(t.val);
            node = &t.next;
        }
        let n = arr.len();
        let mut ans = 0;
        for i in 0..n >> 1 {
            ans = ans.max(arr[i] + arr[n - 1 - i]);
        }
        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在一个大小为&nbsp;<code>n</code>&nbsp;且 <code>n</code>&nbsp;为&nbsp;<strong>偶数</strong> 的链表中，对于&nbsp;<code>0 &lt;= i &lt;= (n / 2) - 1</code>&nbsp;的 <code>i</code>&nbsp;，第&nbsp;<code>i</code>&nbsp;个节点（下标从 <strong>0</strong>&nbsp;开始）的孪生节点为第&nbsp;<code>(n-1-i)</code>&nbsp;个节点 。</p>

<ul>
	<li>比方说，<code>n = 4</code>&nbsp;那么节点&nbsp;<code>0</code>&nbsp;是节点 <code>3</code>&nbsp;的孪生节点，节点 <code>1</code>&nbsp;是节点 <code>2</code>&nbsp;的孪生节点。这是长度为 <code><span style="">n = 4</span></code>&nbsp;的链表中所有的孪生节点。</li>
</ul>

<p><strong>孪生和</strong>&nbsp;定义为一个节点和它孪生节点两者值之和。</p>

<p>给你一个长度为偶数的链表的头节点&nbsp;<code>head</code>&nbsp;，请你返回链表的 <strong>最大孪生和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2130.Maximum%20Twin%20Sum%20of%20a%20Linked%20List/images/eg1drawio.png" style="width: 250px; height: 70px;"></p>

<pre><b>输入：</b>head = [5,4,2,1]
<b>输出：</b>6
<strong>解释：</strong>
节点 0 和节点 1 分别是节点 3 和 2 的孪生节点。孪生和都为 6 。
链表中没有其他孪生节点。
所以，链表的最大孪生和是 6 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2130.Maximum%20Twin%20Sum%20of%20a%20Linked%20List/images/eg2drawio.png" style="width: 250px; height: 70px;"></p>

<pre><b>输入：</b>head = [4,2,2,3]
<b>输出：</b>7
<strong>解释：</strong>
链表中的孪生节点为：
- 节点 0 是节点 3 的孪生节点，孪生和为 4 + 3 = 7 。
- 节点 1 是节点 2 的孪生节点，孪生和为 2 + 2 = 4 。
所以，最大孪生和为 max(7, 4) = 7 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2130.Maximum%20Twin%20Sum%20of%20a%20Linked%20List/images/eg3drawio.png" style="width: 200px; height: 88px;"></p>

<pre><b>输入：</b>head = [1,100000]
<b>输出：</b>100001
<strong>解释：</strong>
链表中只有一对孪生节点，孪生和为 1 + 100000 = 100001 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表的节点数目是&nbsp;<code>[2, 10<sup>5</sup>]</code>&nbsp;中的&nbsp;<strong>偶数</strong>&nbsp;。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：链表转成列表（数组）求解

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        s = []
        while head:
            s.append(head.val)
            head = head.next
        n = len(s)
        return max(s[i] + s[-(i + 1)] for i in range(n >> 1))
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
    public int pairSum(ListNode head) {
        List<Integer> s = new ArrayList<>();
        for (; head != null; head = head.next) {
            s.add(head.val);
        }
        int ans = 0, n = s.size();
        for (int i = 0; i < (n >> 1); ++i) {
            ans = Math.max(ans, s.get(i) + s.get(n - 1 - i));
        }
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
    int pairSum(ListNode* head) {
        vector<int> s;
        for (; head != nullptr; head = head->next) s.push_back(head->val);
        int ans = 0, n = s.size();
        for (int i = 0; i < (n >> 1); ++i) ans = max(ans, s[i] + s[n - i - 1]);
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
func pairSum(head *ListNode) int {
	var s []int
	for ; head != nil; head = head.Next {
		s = append(s, head.Val)
	}
	ans, n := 0, len(s)
	for i := 0; i < (n >> 1); i++ {
		if ans < s[i]+s[n-i-1] {
			ans = s[i] + s[n-i-1]
		}
	}
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

function pairSum(head: ListNode | null): number {
    const arr = [];
    let node = head;
    while (node) {
        arr.push(node.val);
        node = node.next;
    }
    const n = arr.length;
    let ans = 0;
    for (let i = 0; i < n >> 1; i++) {
        ans = Math.max(ans, arr[i] + arr[n - 1 - i]);
    }
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
    pub fn pair_sum(head: Option<Box<ListNode>>) -> i32 {
        let mut arr = Vec::new();
        let mut node = &head;
        while node.is_some() {
            let t = node.as_ref().unwrap();
            arr.push(t.val);
            node = &t.next;
        }
        let n = arr.len();
        let mut ans = 0;
        for i in 0..n >> 1 {
            ans = ans.max(arr[i] + arr[n - 1 - i]);
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：快慢指针 + 反转链表 + 双指针

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        def reverse(head):
            dummy = ListNode()
            curr = head
            while curr:
                next = curr.next
                curr.next = dummy.next
                dummy.next = curr
                curr = next
            return dummy.next

        slow, fast = head, head.next
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        pa = head
        q = slow.next
        slow.next = None
        pb = reverse(q)
        ans = 0
        while pa and pb:
            ans = max(ans, pa.val + pb.val)
            pa = pa.next
            pb = pb.next
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
    public int pairSum(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode pa = head;
        ListNode q = slow.next;
        slow.next = null;
        ListNode pb = reverse(q);
        int ans = 0;
        while (pa != null) {
            ans = Math.max(ans, pa.val + pb.val);
            pa = pa.next;
            pb = pb.next;
        }
        return ans;
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = dummy.next;
            dummy.next = curr;
            curr = next;
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pa = head;
        ListNode* q = slow->next;
        slow->next = nullptr;
        ListNode* pb = reverse(q);
        int ans = 0;
        while (pa) {
            ans = max(ans, pa->val + pb->val);
            pa = pa->next;
            pb = pb->next;
        }
        return ans;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            curr = next;
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
func pairSum(head *ListNode) int {
	reverse := func(head *ListNode) *ListNode {
		dummy := &ListNode{}
		curr := head
		for curr != nil {
			next := curr.Next
			curr.Next = dummy.Next
			dummy.Next = curr
			curr = next
		}
		return dummy.Next
	}
	slow, fast := head, head.Next
	for fast != nil && fast.Next != nil {
		slow, fast = slow.Next, fast.Next.Next
	}
	pa := head
	q := slow.Next
	slow.Next = nil
	pb := reverse(q)
	ans := 0
	for pa != nil {
		ans = max(ans, pa.Val+pb.Val)
		pa = pa.Next
		pb = pb.Next
	}
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

function pairSum(head: ListNode | null): number {
    let fast = head;
    let slow = head;
    while (fast) {
        fast = fast.next.next;
        slow = slow.next;
    }
    let prev = null;
    while (slow) {
        const next = slow.next;
        slow.next = prev;
        prev = slow;
        slow = next;
    }
    let left = head;
    let right = prev;
    let ans = 0;
    while (left && right) {
        ans = Math.max(ans, left.val + right.val);
        left = left.next;
        right = right.next;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2131. 连接两字母单词得到的最长回文串](https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words){#2131}

{{< tabs "2131" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = Counter(words)
        ans = x = 0
        for k, v in cnt.items():
            if k[0] == k[1]:
                x += v & 1
                ans += v // 2 * 2 * 2
            else:
                ans += min(v, cnt[k[::-1]]) * 2
        ans += 2 if x else 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (var w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        int ans = 0, x = 0;
        for (var e : cnt.entrySet()) {
            var k = e.getKey();
            var rk = new StringBuilder(k).reverse().toString();
            int v = e.getValue();
            if (k.charAt(0) == k.charAt(1)) {
                x += v & 1;
                ans += v / 2 * 2 * 2;
            } else {
                ans += Math.min(v, cnt.getOrDefault(rk, 0)) * 2;
            }
        }
        ans += x > 0 ? 2 : 0;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto& w : words) cnt[w]++;
        int ans = 0, x = 0;
        for (auto& [k, v] : cnt) {
            string rk = k;
            reverse(rk.begin(), rk.end());
            if (k[0] == k[1]) {
                x += v & 1;
                ans += v / 2 * 2 * 2;
            } else if (cnt.count(rk)) {
                ans += min(v, cnt[rk]) * 2;
            }
        }
        ans += x ? 2 : 0;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestPalindrome(words []string) int {
	cnt := map[string]int{}
	for _, w := range words {
		cnt[w]++
	}
	ans, x := 0, 0
	for k, v := range cnt {
		if k[0] == k[1] {
			x += v & 1
			ans += v / 2 * 2 * 2
		} else {
			rk := string([]byte{k[1], k[0]})
			if y, ok := cnt[rk]; ok {
				ans += min(v, y) * 2
			}
		}
	}
	if x > 0 {
		ans += 2
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestPalindrome(words: string[]): number {
    const cnt = new Map<string, number>();
    for (const w of words) cnt.set(w, (cnt.get(w) || 0) + 1);
    let [ans, x] = [0, 0];
    for (const [k, v] of cnt.entries()) {
        if (k[0] === k[1]) {
            x += v & 1;
            ans += Math.floor(v / 2) * 2 * 2;
        } else {
            ans += Math.min(v, cnt.get(k[1] + k[0]) || 0) * 2;
        }
    }
    ans += x ? 2 : 0;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组&nbsp;<code>words</code>&nbsp;。<code>words</code>&nbsp;中每个元素都是一个包含 <strong>两个</strong>&nbsp;小写英文字母的单词。</p>

<p>请你从 <code>words</code>&nbsp;中选择一些元素并按 <b>任意顺序</b>&nbsp;连接它们，并得到一个 <strong>尽可能长的回文串</strong>&nbsp;。每个元素 <strong>至多</strong>&nbsp;只能使用一次。</p>

<p>请你返回你能得到的最长回文串的 <strong>长度</strong>&nbsp;。如果没办法得到任何一个回文串，请你返回 <code>0</code>&nbsp;。</p>

<p><strong>回文串</strong>&nbsp;指的是从前往后和从后往前读一样的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>words = ["lc","cl","gg"]
<b>输出：</b>6
<b>解释：</b>一个最长的回文串为 "lc" + "gg" + "cl" = "lcggcl" ，长度为 6 。
"clgglc" 是另一个可以得到的最长回文串。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>words = ["ab","ty","yt","lc","cl","ab"]
<b>输出：</b>8
<strong>解释：</strong>最长回文串是 "ty" + "lc" + "cl" + "yt" = "tylcclyt" ，长度为 8 。
"lcyttycl" 是另一个可以得到的最长回文串。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>words = ["cc","ll","xx"]
<b>输出：</b>2
<b>解释：</b>最长回文串是 "cc" ，长度为 2 。
"ll" 是另一个可以得到的最长回文串。"xx" 也是。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10<sup>5</sup></code></li>
	<li><code>words[i].length == 2</code></li>
	<li><code>words[i]</code>&nbsp;仅包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 哈希表

我们先用一个哈希表 $\textit{cnt}$ 统计每个单词出现的次数。

遍历 $\textit{cnt}$ 中的每个单词 $k$ 以及其出现次数 $v$：

-   如果 $k$ 中两个字母相同，那么我们可以将 $\left \lfloor \frac{v}{2}  \right \rfloor \times 2$ 个 $k$ 连接到回文串的前后，此时如果 $k$ 还剩余一个，那么我们可以先记录到 $x$ 中。

-   如果 $k$ 中两个字母不同，那么我们要找到一个单词 $k'$，使得 $k'$ 中的两个字母与 $k$ 相反，即 $k' = k[1] + k[0]$。如果 $k'$ 存在，那么我们可以将 $\min(v, \textit{cnt}[k'])$ 个 $k$ 连接到回文串的前后。

遍历结束后，如果 $x$ 不为空，那么我们还可以将一个单词连接到回文串的中间。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为单词的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        cnt = Counter(words)
        ans = x = 0
        for k, v in cnt.items():
            if k[0] == k[1]:
                x += v & 1
                ans += v // 2 * 2 * 2
            else:
                ans += min(v, cnt[k[::-1]]) * 2
        ans += 2 if x else 0
        return ans
```

#### Java

```java
class Solution {
    public int longestPalindrome(String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (var w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        int ans = 0, x = 0;
        for (var e : cnt.entrySet()) {
            var k = e.getKey();
            var rk = new StringBuilder(k).reverse().toString();
            int v = e.getValue();
            if (k.charAt(0) == k.charAt(1)) {
                x += v & 1;
                ans += v / 2 * 2 * 2;
            } else {
                ans += Math.min(v, cnt.getOrDefault(rk, 0)) * 2;
            }
        }
        ans += x > 0 ? 2 : 0;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for (auto& w : words) cnt[w]++;
        int ans = 0, x = 0;
        for (auto& [k, v] : cnt) {
            string rk = k;
            reverse(rk.begin(), rk.end());
            if (k[0] == k[1]) {
                x += v & 1;
                ans += v / 2 * 2 * 2;
            } else if (cnt.count(rk)) {
                ans += min(v, cnt[rk]) * 2;
            }
        }
        ans += x ? 2 : 0;
        return ans;
    }
};
```

#### Go

```go
func longestPalindrome(words []string) int {
	cnt := map[string]int{}
	for _, w := range words {
		cnt[w]++
	}
	ans, x := 0, 0
	for k, v := range cnt {
		if k[0] == k[1] {
			x += v & 1
			ans += v / 2 * 2 * 2
		} else {
			rk := string([]byte{k[1], k[0]})
			if y, ok := cnt[rk]; ok {
				ans += min(v, y) * 2
			}
		}
	}
	if x > 0 {
		ans += 2
	}
	return ans
}
```

#### TypeScript

```ts
function longestPalindrome(words: string[]): number {
    const cnt = new Map<string, number>();
    for (const w of words) cnt.set(w, (cnt.get(w) || 0) + 1);
    let [ans, x] = [0, 0];
    for (const [k, v] of cnt.entries()) {
        if (k[0] === k[1]) {
            x += v & 1;
            ans += Math.floor(v / 2) * 2 * 2;
        } else {
            ans += Math.min(v, cnt.get(k[1] + k[0]) || 0) * 2;
        }
    }
    ans += x ? 2 : 0;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2132. 用邮票贴满网格图](https://leetcode.cn/problems/stamping-the-grid){#2132}

{{< tabs "2132" >}}

{{% tab "python" %}}
```python
class Solution:
    def possibleToStamp(
        self, grid: List[List[int]], stampHeight: int, stampWidth: int
    ) -> bool:
        m, n = len(grid), len(grid[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(grid, 1):
            for j, v in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v
        d = [[0] * (n + 2) for _ in range(m + 2)]
        for i in range(1, m - stampHeight + 2):
            for j in range(1, n - stampWidth + 2):
                x, y = i + stampHeight - 1, j + stampWidth - 1
                if s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == 0:
                    d[i][j] += 1
                    d[i][y + 1] -= 1
                    d[x + 1][j] -= 1
                    d[x + 1][y + 1] += 1
        for i, row in enumerate(grid, 1):
            for j, v in enumerate(row, 1):
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1]
                if v == 0 and d[i][j] == 0:
                    return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean possibleToStamp(int[][] grid, int stampHeight, int stampWidth) {
        int m = grid.length, n = grid[0].length;
        int[][] s = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        int[][] d = new int[m + 2][n + 2];
        for (int i = 1; i + stampHeight - 1 <= m; ++i) {
            for (int j = 1; j + stampWidth - 1 <= n; ++j) {
                int x = i + stampHeight - 1, y = j + stampWidth - 1;
                if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == 0) {
                    d[i][j]++;
                    d[i][y + 1]--;
                    d[x + 1][j]--;
                    d[x + 1][y + 1]++;
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 0 && d[i][j] == 0) {
                    return false;
                }
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
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        vector<vector<int>> d(m + 2, vector<int>(n + 2));
        for (int i = 1; i + stampHeight - 1 <= m; ++i) {
            for (int j = 1; j + stampWidth - 1 <= n; ++j) {
                int x = i + stampHeight - 1, y = j + stampWidth - 1;
                if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == 0) {
                    d[i][j]++;
                    d[i][y + 1]--;
                    d[x + 1][j]--;
                    d[x + 1][y + 1]++;
                }
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 0 && d[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func possibleToStamp(grid [][]int, stampHeight int, stampWidth int) bool {
	m, n := len(grid), len(grid[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + grid[i-1][j-1]
		}
	}

	d := make([][]int, m+2)
	for i := range d {
		d[i] = make([]int, n+2)
	}

	for i := 1; i+stampHeight-1 <= m; i++ {
		for j := 1; j+stampWidth-1 <= n; j++ {
			x, y := i+stampHeight-1, j+stampWidth-1
			if s[x][y]-s[x][j-1]-s[i-1][y]+s[i-1][j-1] == 0 {
				d[i][j]++
				d[i][y+1]--
				d[x+1][j]--
				d[x+1][y+1]++
			}
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1]
			if grid[i-1][j-1] == 0 && d[i][j] == 0 {
				return false
			}
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function possibleToStamp(grid: number[][], stampHeight: number, stampWidth: number): boolean {
    const m = grid.length;
    const n = grid[0].length;
    const s: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    const d: number[][] = Array.from({ length: m + 2 }, () => Array(n + 2).fill(0));
    for (let i = 1; i + stampHeight - 1 <= m; ++i) {
        for (let j = 1; j + stampWidth - 1 <= n; ++j) {
            const [x, y] = [i + stampHeight - 1, j + stampWidth - 1];
            if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] === 0) {
                d[i][j]++;
                d[i][y + 1]--;
                d[x + 1][j]--;
                d[x + 1][y + 1]++;
            }
        }
    }

    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (grid[i - 1][j - 1] === 0 && d[i][j] === 0) {
                return false;
            }
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn possible_to_stamp(grid: Vec<Vec<i32>>, stamp_height: i32, stamp_width: i32) -> bool {
        let n: usize = grid.len();
        let m: usize = grid[0].len();

        let mut prefix_vec: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Initialize the prefix vector
        for i in 0..n {
            for j in 0..m {
                prefix_vec[i + 1][j + 1] =
                    prefix_vec[i][j + 1] + prefix_vec[i + 1][j] - prefix_vec[i][j] + grid[i][j];
            }
        }

        let mut diff_vec: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Construct the difference vector based on prefix sum vector
        for i in 0..n {
            for j in 0..m {
                // If the value of the cell is one, just bypass this
                if grid[i][j] == 1 {
                    continue;
                }
                // Otherwise, try stick the stamp
                let x: usize = i + (stamp_height as usize);
                let y: usize = j + (stamp_width as usize);
                // Check the bound
                if x <= n && y <= m {
                    // If the region can be sticked (All cells are empty, which means the sum will be zero)
                    if prefix_vec[x][y] - prefix_vec[x][j] - prefix_vec[i][y] + prefix_vec[i][j]
                        == 0
                    {
                        // Update the difference vector
                        diff_vec[i][j] += 1;
                        diff_vec[x][y] += 1;

                        diff_vec[x][j] -= 1;
                        diff_vec[i][y] -= 1;
                    }
                }
            }
        }

        let mut check_vec: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Check the prefix sum of difference vector, to determine if there is any empty cell left
        for i in 0..n {
            for j in 0..m {
                // If the value of the cell is one, just bypass this
                if grid[i][j] == 1 {
                    continue;
                }
                // Otherwise, check if the region is empty, by calculating the prefix sum of difference vector
                check_vec[i + 1][j + 1] =
                    check_vec[i][j + 1] + check_vec[i + 1][j] - check_vec[i][j] + diff_vec[i][j];
                if check_vec[i + 1][j + 1] == 0 {
                    return false;
                }
            }
        }

        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} grid
 * @param {number} stampHeight
 * @param {number} stampWidth
 * @return {boolean}
 */
var possibleToStamp = function (grid, stampHeight, stampWidth) {
    const m = grid.length;
    const n = grid[0].length;
    const s = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    const d = Array.from({ length: m + 2 }, () => Array(n + 2).fill(0));
    for (let i = 1; i + stampHeight - 1 <= m; ++i) {
        for (let j = 1; j + stampWidth - 1 <= n; ++j) {
            const [x, y] = [i + stampHeight - 1, j + stampWidth - 1];
            if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] === 0) {
                d[i][j]++;
                d[i][y + 1]--;
                d[x + 1][j]--;
                d[x + 1][y + 1]++;
            }
        }
    }

    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (grid[i - 1][j - 1] === 0 && d[i][j] === 0) {
                return false;
            }
        }
    }
    return true;
};
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun possibleToStamp(grid: Array<IntArray>, stampHeight: Int, stampWidth: Int): Boolean {
        val m = grid.size
        val n = grid[0].size

        var prefix_sums_matrix = Array(m + 1) { IntArray(n + 1) }
        var diff_matrix = Array(m + 1) { IntArray(n + 1) }
        var sum_matrix = Array(m + 1) { IntArray(n + 1) }

        for (i in 0..<m) {
            for (j in 0..<n) {
                prefix_sums_matrix[i + 1][j + 1] =
                    prefix_sums_matrix[i + 1][j] +
                    prefix_sums_matrix[i][j + 1] -
                    prefix_sums_matrix[i][j] +
                    grid[i][j]
            }
        }

        for (i in 0..<m) {
            for (j in 0..<n) {
                if (grid[i][j] != 0) {
                    continue
                }

                val bottom = i + stampHeight
                val right = j + stampWidth

                if (bottom > m || right > n) {
                    continue
                }

                val sum = prefix_sums_matrix[bottom][right] -
                    prefix_sums_matrix[bottom][j] -
                    prefix_sums_matrix[i][right] +
                    prefix_sums_matrix[i][j]

                if (sum == 0) {
                    diff_matrix[i][j] += 1
                    diff_matrix[bottom][right] += 1

                    diff_matrix[i][right] -= 1
                    diff_matrix[bottom][j] -= 1
                }
            }
        }

        for (i in 0..<m) {
            for (j in 0..<n) {
                if (grid[i][j] != 0) {
                    continue
                }

                val sum = sum_matrix[i][j + 1] +
                    sum_matrix[i + 1][j] -
                    sum_matrix[i][j] +
                    diff_matrix[i][j]

                if (sum == 0) {
                    return false
                }

                sum_matrix[i + 1][j + 1] = sum
            }
        }

        return true
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩阵&nbsp;<code>grid</code>&nbsp;，每个格子要么为&nbsp;<code>0</code>&nbsp;（空）要么为&nbsp;<code>1</code>&nbsp;（被占据）。</p>

<p>给你邮票的尺寸为&nbsp;<code>stampHeight x stampWidth</code>&nbsp;。我们想将邮票贴进二进制矩阵中，且满足以下&nbsp;<strong>限制</strong>&nbsp;和&nbsp;<strong>要求</strong>&nbsp;：</p>

<ol>
	<li>覆盖所有 <strong>空</strong>&nbsp;格子。</li>
	<li>不覆盖任何 <strong>被占据&nbsp;</strong>的格子。</li>
	<li>我们可以放入任意数目的邮票。</li>
	<li>邮票可以相互有 <strong>重叠</strong>&nbsp;部分。</li>
	<li>邮票不允许 <strong>旋转</strong>&nbsp;。</li>
	<li>邮票必须完全在矩阵 <strong>内</strong>&nbsp;。</li>
</ol>

<p>如果在满足上述要求的前提下，可以放入邮票，请返回&nbsp;<code>true</code>&nbsp;，否则返回<i>&nbsp;</i><code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2132.Stamping%20the%20Grid/images/ex1.png" style="width: 180px; height: 237px;"></p>

<pre><b>输入：</b>grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
<b>输出：</b>true
<b>解释：</b>我们放入两个有重叠部分的邮票（图中标号为 1 和 2），它们能覆盖所有与空格子。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2132.Stamping%20the%20Grid/images/ex2.png" style="width: 170px; height: 179px;"></p>

<pre><b>输入：</b>grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
<b>输出：</b>false 
<b>解释：</b>没办法放入邮票覆盖所有的空格子，且邮票不超出网格图以外。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>grid[r][c]</code> 要么是&nbsp;<code>0</code>&nbsp;，要么是&nbsp;<code>1</code> 。</li>
	<li><code>1 &lt;= stampHeight, stampWidth &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀和 + 二维差分

根据题目描述，每一个空格子都必须被邮票覆盖，而且不能覆盖任何被占据的格子。因此，我们可以遍历二维矩阵，对于每个格子，如果以该格子为左上角的 $stampHeight \times stampWidth$ 的区域内的所有格子都是空格子（即没有被占据），那么我们就可以在该格子处放置一个邮票。

为了快速判断一个区域内的所有格子是否都是空格子，我们可以使用二维前缀和。我们用 $s_{i,j}$ 表示二维矩阵中从 $(1,1)$ 到 $(i,j)$ 的子矩阵中被占据的格子的数量。即 $s_{i, j} = s_{i - 1, j} + s_{i, j - 1} - s_{i - 1, j - 1} + grid_{i-1, j-1}$。

那么以 $(i, j)$ 为左上角，且高度和宽度分别为 $stampHeight$ 和 $stampWidth$ 的子矩阵的右下角坐标为 $(x, y) = (i + stampHeight - 1, j + stampWidth - 1)$，我们可以通过 $s_{x, y} - s_{x, j - 1} - s_{i - 1, y} + s_{i - 1, j - 1}$ 来计算出该子矩阵中被占据的格子的数量。如果该子矩阵中被占据的格子的数量为 $0$，那么我们就可以在 $(i, j)$ 处放置一个邮票，放置邮票后，这 $stampHeight \times stampWidth$ 的区域内的所有格子都会变成被占据的格子，我们可以用二维差分数组 $d$ 来记录这一变化。即：

$$
\begin{aligned}
d_{i, j} &\leftarrow d_{i, j} + 1 \\
d_{i, y + 1} &\leftarrow d_{i, y + 1} - 1 \\
d_{x + 1, j} &\leftarrow d_{x + 1, j} - 1 \\
d_{x + 1, y + 1} &\leftarrow d_{x + 1, y + 1} + 1
\end{aligned}
$$

最后，我们对二维差分数组 $d$ 进行前缀和运算，可以得出每个格子被邮票覆盖的次数。如果某个格子没有被占据，且被邮票覆盖的次数为 $0$，那么我们就无法将邮票放置在该格子处，因此我们需要返回 $\texttt{false}$。如果所有“没被占据的格子”都成功被邮票覆盖，返回 $\texttt{true}$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是二维矩阵的高度和宽度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def possibleToStamp(
        self, grid: List[List[int]], stampHeight: int, stampWidth: int
    ) -> bool:
        m, n = len(grid), len(grid[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(grid, 1):
            for j, v in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v
        d = [[0] * (n + 2) for _ in range(m + 2)]
        for i in range(1, m - stampHeight + 2):
            for j in range(1, n - stampWidth + 2):
                x, y = i + stampHeight - 1, j + stampWidth - 1
                if s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == 0:
                    d[i][j] += 1
                    d[i][y + 1] -= 1
                    d[x + 1][j] -= 1
                    d[x + 1][y + 1] += 1
        for i, row in enumerate(grid, 1):
            for j, v in enumerate(row, 1):
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1]
                if v == 0 and d[i][j] == 0:
                    return False
        return True
```

#### Java

```java
class Solution {
    public boolean possibleToStamp(int[][] grid, int stampHeight, int stampWidth) {
        int m = grid.length, n = grid[0].length;
        int[][] s = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        int[][] d = new int[m + 2][n + 2];
        for (int i = 1; i + stampHeight - 1 <= m; ++i) {
            for (int j = 1; j + stampWidth - 1 <= n; ++j) {
                int x = i + stampHeight - 1, y = j + stampWidth - 1;
                if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == 0) {
                    d[i][j]++;
                    d[i][y + 1]--;
                    d[x + 1][j]--;
                    d[x + 1][y + 1]++;
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 0 && d[i][j] == 0) {
                    return false;
                }
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
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }

        vector<vector<int>> d(m + 2, vector<int>(n + 2));
        for (int i = 1; i + stampHeight - 1 <= m; ++i) {
            for (int j = 1; j + stampWidth - 1 <= n; ++j) {
                int x = i + stampHeight - 1, y = j + stampWidth - 1;
                if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] == 0) {
                    d[i][j]++;
                    d[i][y + 1]--;
                    d[x + 1][j]--;
                    d[x + 1][y + 1]++;
                }
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 0 && d[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func possibleToStamp(grid [][]int, stampHeight int, stampWidth int) bool {
	m, n := len(grid), len(grid[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + grid[i-1][j-1]
		}
	}

	d := make([][]int, m+2)
	for i := range d {
		d[i] = make([]int, n+2)
	}

	for i := 1; i+stampHeight-1 <= m; i++ {
		for j := 1; j+stampWidth-1 <= n; j++ {
			x, y := i+stampHeight-1, j+stampWidth-1
			if s[x][y]-s[x][j-1]-s[i-1][y]+s[i-1][j-1] == 0 {
				d[i][j]++
				d[i][y+1]--
				d[x+1][j]--
				d[x+1][y+1]++
			}
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			d[i][j] += d[i-1][j] + d[i][j-1] - d[i-1][j-1]
			if grid[i-1][j-1] == 0 && d[i][j] == 0 {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function possibleToStamp(grid: number[][], stampHeight: number, stampWidth: number): boolean {
    const m = grid.length;
    const n = grid[0].length;
    const s: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    const d: number[][] = Array.from({ length: m + 2 }, () => Array(n + 2).fill(0));
    for (let i = 1; i + stampHeight - 1 <= m; ++i) {
        for (let j = 1; j + stampWidth - 1 <= n; ++j) {
            const [x, y] = [i + stampHeight - 1, j + stampWidth - 1];
            if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] === 0) {
                d[i][j]++;
                d[i][y + 1]--;
                d[x + 1][j]--;
                d[x + 1][y + 1]++;
            }
        }
    }

    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (grid[i - 1][j - 1] === 0 && d[i][j] === 0) {
                return false;
            }
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn possible_to_stamp(grid: Vec<Vec<i32>>, stamp_height: i32, stamp_width: i32) -> bool {
        let n: usize = grid.len();
        let m: usize = grid[0].len();

        let mut prefix_vec: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Initialize the prefix vector
        for i in 0..n {
            for j in 0..m {
                prefix_vec[i + 1][j + 1] =
                    prefix_vec[i][j + 1] + prefix_vec[i + 1][j] - prefix_vec[i][j] + grid[i][j];
            }
        }

        let mut diff_vec: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Construct the difference vector based on prefix sum vector
        for i in 0..n {
            for j in 0..m {
                // If the value of the cell is one, just bypass this
                if grid[i][j] == 1 {
                    continue;
                }
                // Otherwise, try stick the stamp
                let x: usize = i + (stamp_height as usize);
                let y: usize = j + (stamp_width as usize);
                // Check the bound
                if x <= n && y <= m {
                    // If the region can be sticked (All cells are empty, which means the sum will be zero)
                    if prefix_vec[x][y] - prefix_vec[x][j] - prefix_vec[i][y] + prefix_vec[i][j]
                        == 0
                    {
                        // Update the difference vector
                        diff_vec[i][j] += 1;
                        diff_vec[x][y] += 1;

                        diff_vec[x][j] -= 1;
                        diff_vec[i][y] -= 1;
                    }
                }
            }
        }

        let mut check_vec: Vec<Vec<i32>> = vec![vec![0; m + 1]; n + 1];

        // Check the prefix sum of difference vector, to determine if there is any empty cell left
        for i in 0..n {
            for j in 0..m {
                // If the value of the cell is one, just bypass this
                if grid[i][j] == 1 {
                    continue;
                }
                // Otherwise, check if the region is empty, by calculating the prefix sum of difference vector
                check_vec[i + 1][j + 1] =
                    check_vec[i][j + 1] + check_vec[i + 1][j] - check_vec[i][j] + diff_vec[i][j];
                if check_vec[i + 1][j + 1] == 0 {
                    return false;
                }
            }
        }

        true
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} grid
 * @param {number} stampHeight
 * @param {number} stampWidth
 * @return {boolean}
 */
var possibleToStamp = function (grid, stampHeight, stampWidth) {
    const m = grid.length;
    const n = grid[0].length;
    const s = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    const d = Array.from({ length: m + 2 }, () => Array(n + 2).fill(0));
    for (let i = 1; i + stampHeight - 1 <= m; ++i) {
        for (let j = 1; j + stampWidth - 1 <= n; ++j) {
            const [x, y] = [i + stampHeight - 1, j + stampWidth - 1];
            if (s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1] === 0) {
                d[i][j]++;
                d[i][y + 1]--;
                d[x + 1][j]--;
                d[x + 1][y + 1]++;
            }
        }
    }

    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (grid[i - 1][j - 1] === 0 && d[i][j] === 0) {
                return false;
            }
        }
    }
    return true;
};
```

#### Kotlin

```kotlin
class Solution {
    fun possibleToStamp(grid: Array<IntArray>, stampHeight: Int, stampWidth: Int): Boolean {
        val m = grid.size
        val n = grid[0].size

        var prefix_sums_matrix = Array(m + 1) { IntArray(n + 1) }
        var diff_matrix = Array(m + 1) { IntArray(n + 1) }
        var sum_matrix = Array(m + 1) { IntArray(n + 1) }

        for (i in 0..<m) {
            for (j in 0..<n) {
                prefix_sums_matrix[i + 1][j + 1] =
                    prefix_sums_matrix[i + 1][j] +
                    prefix_sums_matrix[i][j + 1] -
                    prefix_sums_matrix[i][j] +
                    grid[i][j]
            }
        }

        for (i in 0..<m) {
            for (j in 0..<n) {
                if (grid[i][j] != 0) {
                    continue
                }

                val bottom = i + stampHeight
                val right = j + stampWidth

                if (bottom > m || right > n) {
                    continue
                }

                val sum = prefix_sums_matrix[bottom][right] -
                    prefix_sums_matrix[bottom][j] -
                    prefix_sums_matrix[i][right] +
                    prefix_sums_matrix[i][j]

                if (sum == 0) {
                    diff_matrix[i][j] += 1
                    diff_matrix[bottom][right] += 1

                    diff_matrix[i][right] -= 1
                    diff_matrix[bottom][j] -= 1
                }
            }
        }

        for (i in 0..<m) {
            for (j in 0..<n) {
                if (grid[i][j] != 0) {
                    continue
                }

                val sum = sum_matrix[i][j + 1] +
                    sum_matrix[i + 1][j] -
                    sum_matrix[i][j] +
                    diff_matrix[i][j]

                if (sum == 0) {
                    return false
                }

                sum_matrix[i + 1][j + 1] = sum
            }
        }

        return true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2133. 检查是否每一行每一列都包含全部整数](https://leetcode.cn/problems/check-if-every-row-and-column-contains-all-numbers){#2133}

{{< tabs "2133" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        return all(len(set(row)) == n for row in chain(matrix, zip(*matrix)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;
        boolean[] vis = new boolean[n + 1];
        for (var row : matrix) {
            Arrays.fill(vis, false);
            for (int x : row) {
                if (vis[x]) {
                    return false;
                }
                vis[x] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            Arrays.fill(vis, false);
            for (int i = 0; i < n; ++i) {
                if (vis[matrix[i][j]]) {
                    return false;
                }
                vis[matrix[i][j]] = true;
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
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        bool vis[n + 1];
        for (const auto& row : matrix) {
            memset(vis, false, sizeof(vis));
            for (int x : row) {
                if (vis[x]) {
                    return false;
                }
                vis[x] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            memset(vis, false, sizeof(vis));
            for (int i = 0; i < n; ++i) {
                if (vis[matrix[i][j]]) {
                    return false;
                }
                vis[matrix[i][j]] = true;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkValid(matrix [][]int) bool {
	n := len(matrix)
	for _, row := range matrix {
		vis := make([]bool, n+1)
		for _, x := range row {
			if vis[x] {
				return false
			}
			vis[x] = true
		}
	}
	for j := 0; j < n; j++ {
		vis := make([]bool, n+1)
		for i := 0; i < n; i++ {
			if vis[matrix[i][j]] {
				return false
			}
			vis[matrix[i][j]] = true
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkValid(matrix: number[][]): boolean {
    const n = matrix.length;
    const vis: boolean[] = Array(n + 1).fill(false);
    for (const row of matrix) {
        vis.fill(false);
        for (const x of row) {
            if (vis[x]) {
                return false;
            }
            vis[x] = true;
        }
    }
    for (let j = 0; j < n; ++j) {
        vis.fill(false);
        for (let i = 0; i < n; ++i) {
            if (vis[matrix[i][j]]) {
                return false;
            }
            vis[matrix[i][j]] = true;
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对一个大小为 <code>n x n</code> 的矩阵而言，如果其每一行和每一列都包含从 <code>1</code> 到 <code>n</code> 的 <strong>全部</strong> 整数（含 <code>1</code> 和 <code>n</code>），则认为该矩阵是一个 <strong>有效</strong> 矩阵。</p>

<p>给你一个大小为 <code>n x n</code> 的整数矩阵 <code>matrix</code> ，请你判断矩阵是否为一个有效矩阵：如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2133.Check%20if%20Every%20Row%20and%20Column%20Contains%20All%20Numbers/images/example1drawio.png" style="width: 250px; height: 251px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[1,2,3],[3,1,2],[2,3,1]]
<strong>输出：</strong>true
<strong>解释：</strong>在此例中，n = 3 ，每一行和每一列都包含数字 1、2、3 。
因此，返回 true 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2133.Check%20if%20Every%20Row%20and%20Column%20Contains%20All%20Numbers/images/example2drawio.png" style="width: 250px; height: 251px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[1,1,1],[1,2,3],[1,2,3]]
<strong>输出：</strong>false
<strong>解释：</strong>在此例中，n = 3 ，但第一行和第一列不包含数字 2 和 3 。
因此，返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == matrix.length == matrix[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= matrix[i][j] &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

遍历矩阵的每一行和每一列，使用哈希表记录每个数字是否出现过，如果某一行或某一列中有数字重复出现，则返回 `false`，否则返回 `true`。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为矩阵的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        return all(len(set(row)) == n for row in chain(matrix, zip(*matrix)))
```

#### Java

```java
class Solution {
    public boolean checkValid(int[][] matrix) {
        int n = matrix.length;
        boolean[] vis = new boolean[n + 1];
        for (var row : matrix) {
            Arrays.fill(vis, false);
            for (int x : row) {
                if (vis[x]) {
                    return false;
                }
                vis[x] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            Arrays.fill(vis, false);
            for (int i = 0; i < n; ++i) {
                if (vis[matrix[i][j]]) {
                    return false;
                }
                vis[matrix[i][j]] = true;
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
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        bool vis[n + 1];
        for (const auto& row : matrix) {
            memset(vis, false, sizeof(vis));
            for (int x : row) {
                if (vis[x]) {
                    return false;
                }
                vis[x] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            memset(vis, false, sizeof(vis));
            for (int i = 0; i < n; ++i) {
                if (vis[matrix[i][j]]) {
                    return false;
                }
                vis[matrix[i][j]] = true;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkValid(matrix [][]int) bool {
	n := len(matrix)
	for _, row := range matrix {
		vis := make([]bool, n+1)
		for _, x := range row {
			if vis[x] {
				return false
			}
			vis[x] = true
		}
	}
	for j := 0; j < n; j++ {
		vis := make([]bool, n+1)
		for i := 0; i < n; i++ {
			if vis[matrix[i][j]] {
				return false
			}
			vis[matrix[i][j]] = true
		}
	}
	return true
}
```

#### TypeScript

```ts
function checkValid(matrix: number[][]): boolean {
    const n = matrix.length;
    const vis: boolean[] = Array(n + 1).fill(false);
    for (const row of matrix) {
        vis.fill(false);
        for (const x of row) {
            if (vis[x]) {
                return false;
            }
            vis[x] = true;
        }
    }
    for (let j = 0; j < n; ++j) {
        vis.fill(false);
        for (let i = 0; i < n; ++i) {
            if (vis[matrix[i][j]]) {
                return false;
            }
            vis[matrix[i][j]] = true;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2134. 最少交换次数来组合所有的 1 II](https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together-ii){#2134}

{{< tabs "2134" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        k = nums.count(1)
        mx = cnt = sum(nums[:k])
        n = len(nums)
        for i in range(k, n + k):
            cnt += nums[i % n]
            cnt -= nums[(i - k + n) % n]
            mx = max(mx, cnt)
        return k - mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSwaps(int[] nums) {
        int k = Arrays.stream(nums).sum();
        int n = nums.length;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += nums[i];
        }
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = Math.max(mx, cnt);
        }
        return k - mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = max(mx, cnt);
        }
        return k - mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwaps(nums []int) int {
	k := 0
	for _, x := range nums {
		k += x
	}
	cnt := 0
	for i := 0; i < k; i++ {
		cnt += nums[i]
	}
	mx := cnt
	n := len(nums)
	for i := k; i < n+k; i++ {
		cnt += nums[i%n] - nums[(i-k+n)%n]
		mx = max(mx, cnt)
	}
	return k - mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSwaps(nums: number[]): number {
    const n = nums.length;

    const getMin = (x: 0 | 1) => {
        const prefixSum = Array(n + 1).fill(0);
        for (let i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (nums[i - 1] === x);
        }

        const length = prefixSum[n];
        let ans = Number.POSITIVE_INFINITY;
        for (let l = 0, r = length; r <= n; l++, r++) {
            const min = length - (prefixSum[r] - prefixSum[l]);
            ans = Math.min(ans, min);
        }

        return ans;
    };

    return Math.min(getMin(0), getMin(1));
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function minSwaps(nums) {
    const n = nums.length;

    const getMin = x => {
        const prefixSum = Array(n + 1).fill(0);
        for (let i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (nums[i - 1] === x);
        }

        const length = prefixSum[n];
        let ans = Number.POSITIVE_INFINITY;
        for (let l = 0, r = length; r <= n; l++, r++) {
            const min = length - (prefixSum[r] - prefixSum[l]);
            ans = Math.min(ans, min);
        }

        return ans;
    };

    return Math.min(getMin(0), getMin(1));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let k: i32 = nums.iter().sum();
        let n: usize = nums.len();
        let mut cnt: i32 = 0;
        for i in 0..k {
            cnt += nums[i as usize];
        }
        let mut mx: i32 = cnt;
        for i in k..(n as i32) + k {
            cnt += nums[(i % (n as i32)) as usize]
                - nums[((i - k + (n as i32)) % (n as i32)) as usize];
            mx = mx.max(cnt);
        }
        return k - mx;
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinSwaps(int[] nums) {
        int k = nums.Sum();
        int n = nums.Length;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += nums[i];
        }
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = Math.Max(mx, cnt);
        }
        return k - mx;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>交换</strong> 定义为选中一个数组中的两个 <strong>互不相同</strong> 的位置并交换二者的值。</p>

<p><strong>环形</strong> 数组是一个数组，可以认为 <strong>第一个</strong> 元素和 <strong>最后一个</strong> 元素 <strong>相邻</strong> 。</p>

<p>给你一个 <strong>二进制环形</strong> 数组 <code>nums</code> ，返回在 <strong>任意位置</strong> 将数组中的所有 <code>1</code> 聚集在一起需要的最少交换次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,0,1,1,0,0]
<strong>输出：</strong>1
<strong>解释：</strong>这里列出一些能够将所有 1 聚集在一起的方案：
[0,<strong><em>0</em></strong>,<em><strong>1</strong></em>,1,1,0,0] 交换 1 次。
[0,1,<em><strong>1</strong></em>,1,<em><strong>0</strong></em>,0,0] 交换 1 次。
[1,1,0,0,0,0,1] 交换 2 次（利用数组的环形特性）。
无法在交换 0 次的情况下将数组中的所有 1 聚集在一起。
因此，需要的最少交换次数为 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,1,1,0,0,1,1,0]
<strong>输出：</strong>2
<strong>解释：</strong>这里列出一些能够将所有 1 聚集在一起的方案：
[1,1,1,0,0,0,0,1,1] 交换 2 次（利用数组的环形特性）。
[1,1,1,1,1,0,0,0,0] 交换 2 次。
无法在交换 0 次或 1 次的情况下将数组中的所有 1 聚集在一起。
因此，需要的最少交换次数为 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1,0,0,1]
<strong>输出：</strong>0
<strong>解释：</strong>得益于数组的环形特性，所有的 1 已经聚集在一起。
因此，需要的最少交换次数为 0 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 为 <code>0</code> 或者 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们先统计数组中 $1$ 的个数，记为 $k$，那么题目实际上就是求一个长度为 $k$ 的环形子数组，使得子数组中 $1$ 的个数最多，那么最少交换次数就是 $k$ 减去子数组中 $1$ 的个数最多的那个子数组中 $1$ 的个数。

我们可以使用滑动窗口来解决这个问题，首先统计数组中前 $k$ 个元素中 $1$ 的个数，记为 $cnt$，然后我们维护一个长度为 $k$ 的滑动窗口，每次向右移动一个位置，更新 $cnt$，同时更新最大的 $cnt$ 值，即 $mx = \max(mx, cnt)$，最后答案就是 $k - mx$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        k = nums.count(1)
        mx = cnt = sum(nums[:k])
        n = len(nums)
        for i in range(k, n + k):
            cnt += nums[i % n]
            cnt -= nums[(i - k + n) % n]
            mx = max(mx, cnt)
        return k - mx
```

#### Java

```java
class Solution {
    public int minSwaps(int[] nums) {
        int k = Arrays.stream(nums).sum();
        int n = nums.length;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += nums[i];
        }
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = Math.max(mx, cnt);
        }
        return k - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int cnt = accumulate(nums.begin(), nums.begin() + k, 0);
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = max(mx, cnt);
        }
        return k - mx;
    }
};
```

#### Go

```go
func minSwaps(nums []int) int {
	k := 0
	for _, x := range nums {
		k += x
	}
	cnt := 0
	for i := 0; i < k; i++ {
		cnt += nums[i]
	}
	mx := cnt
	n := len(nums)
	for i := k; i < n+k; i++ {
		cnt += nums[i%n] - nums[(i-k+n)%n]
		mx = max(mx, cnt)
	}
	return k - mx
}
```

#### TypeScript

```ts
function minSwaps(nums: number[]): number {
    const n = nums.length;
    const k = nums.reduce((a, b) => a + b, 0);
    let cnt = k - nums.slice(0, k).reduce((a, b) => a + b, 0);
    let min = cnt;

    for (let i = k; i < n + k; i++) {
        cnt += nums[i - k] - nums[i % n];
        min = Math.min(min, cnt);
    }

    return min;
}
```

#### JavaScript

```js
function minSwaps(nums) {
    const n = nums.length;
    const k = nums.reduce((a, b) => a + b, 0);
    let cnt = k - nums.slice(0, k).reduce((a, b) => a + b, 0);
    let min = cnt;

    for (let i = k; i < n + k; i++) {
        cnt += nums[i - k] - nums[i % n];
        min = Math.min(min, cnt);
    }

    return min;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let k: i32 = nums.iter().sum();
        let n: usize = nums.len();
        let mut cnt: i32 = 0;
        for i in 0..k {
            cnt += nums[i as usize];
        }
        let mut mx: i32 = cnt;
        for i in k..(n as i32) + k {
            cnt += nums[(i % (n as i32)) as usize]
                - nums[((i - k + (n as i32)) % (n as i32)) as usize];
            mx = mx.max(cnt);
        }
        return k - mx;
    }
}
```

#### C#

```cs
public class Solution {
    public int MinSwaps(int[] nums) {
        int k = nums.Sum();
        int n = nums.Length;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            cnt += nums[i];
        }
        int mx = cnt;
        for (int i = k; i < n + k; ++i) {
            cnt += nums[i % n] - nums[(i - k + n) % n];
            mx = Math.Max(mx, cnt);
        }
        return k - mx;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：前缀和

<!-- tabs:start -->

#### TypeScript

```ts
function minSwaps(nums: number[]): number {
    const n = nums.length;

    const getMin = (x: 0 | 1) => {
        const prefixSum = Array(n + 1).fill(0);
        for (let i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (nums[i - 1] === x);
        }

        const length = prefixSum[n];
        let ans = Number.POSITIVE_INFINITY;
        for (let l = 0, r = length; r <= n; l++, r++) {
            const min = length - (prefixSum[r] - prefixSum[l]);
            ans = Math.min(ans, min);
        }

        return ans;
    };

    return Math.min(getMin(0), getMin(1));
}
```

#### JavaScript

```js
function minSwaps(nums) {
    const n = nums.length;

    const getMin = x => {
        const prefixSum = Array(n + 1).fill(0);
        for (let i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (nums[i - 1] === x);
        }

        const length = prefixSum[n];
        let ans = Number.POSITIVE_INFINITY;
        for (let l = 0, r = length; r <= n; l++, r++) {
            const min = length - (prefixSum[r] - prefixSum[l]);
            ans = Math.min(ans, min);
        }

        return ans;
    };

    return Math.min(getMin(0), getMin(1));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2135. 统计追加字母可以获得的单词数](https://leetcode.cn/problems/count-words-obtained-after-adding-a-letter){#2135}

{{< tabs "2135" >}}

{{% tab "python" %}}
```python
class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        s = {sum(1 << (ord(c) - 97) for c in w) for w in startWords}
        ans = 0
        for w in targetWords:
            x = sum(1 << (ord(c) - 97) for c in w)
            for c in w:
                if x ^ (1 << (ord(c) - 97)) in s:
                    ans += 1
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int wordCount(String[] startWords, String[] targetWords) {
        Set<Integer> s = new HashSet<>();
        for (var w : startWords) {
            int x = 0;
            for (var c : w.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            s.add(x);
        }
        int ans = 0;
        for (var w : targetWords) {
            int x = 0;
            for (var c : w.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            for (var c : w.toCharArray()) {
                if (s.contains(x ^ (1 << (c - 'a')))) {
                    ++ans;
                    break;
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
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> s;
        for (auto& w : startWords) {
            int x = 0;
            for (char c : w) {
                x |= 1 << (c - 'a');
            }
            s.insert(x);
        }
        int ans = 0;
        for (auto& w : targetWords) {
            int x = 0;
            for (char c : w) {
                x |= 1 << (c - 'a');
            }
            for (char c : w) {
                if (s.contains(x ^ (1 << (c - 'a')))) {
                    ++ans;
                    break;
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
func wordCount(startWords []string, targetWords []string) (ans int) {
	s := map[int]bool{}
	for _, w := range startWords {
		x := 0
		for _, c := range w {
			x |= 1 << (c - 'a')
		}
		s[x] = true
	}
	for _, w := range targetWords {
		x := 0
		for _, c := range w {
			x |= 1 << (c - 'a')
		}
		for _, c := range w {
			if s[x^(1<<(c-'a'))] {
				ans++
				break
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wordCount(startWords: string[], targetWords: string[]): number {
    const s = new Set<number>();
    for (const w of startWords) {
        let x = 0;
        for (const c of w) {
            x ^= 1 << (c.charCodeAt(0) - 97);
        }
        s.add(x);
    }
    let ans = 0;
    for (const w of targetWords) {
        let x = 0;
        for (const c of w) {
            x ^= 1 << (c.charCodeAt(0) - 97);
        }
        for (const c of w) {
            if (s.has(x ^ (1 << (c.charCodeAt(0) - 97)))) {
                ++ans;
                break;
            }
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

<p>给你两个下标从 <strong>0</strong> 开始的字符串数组 <code>startWords</code> 和 <code>targetWords</code> 。每个字符串都仅由 <strong>小写英文字母</strong> 组成。</p>

<p>对于 <code>targetWords</code> 中的每个字符串，检查是否能够从 <code>startWords</code> 中选出一个字符串，执行一次 <strong>转换操作</strong>&nbsp;，得到的结果与当前&nbsp;<code>targetWords</code> 字符串相等。</p>

<p><strong>转换操作</strong> 如下面两步所述：</p>

<ol>
	<li><strong>追加</strong> 任何 <strong>不存在</strong> 于当前字符串的任一小写字母到当前字符串的末尾。

    <ul>
    	<li>例如，如果字符串为 <code>"abc"</code> ，那么字母 <code>'d'</code>、<code>'e'</code> 或 <code>'y'</code> 都可以加到该字符串末尾，但 <code>'a'</code> 就不行。如果追加的是 <code>'d'</code> ，那么结果字符串为 <code>"abcd"</code> 。</li>
    </ul>
    </li>
    <li><strong>重排</strong> 新字符串中的字母，可以按 <strong>任意</strong> 顺序重新排布字母。
    <ul>
    	<li>例如，<code>"abcd"</code> 可以重排为 <code>"acbd"</code>、<code>"bacd"</code>、<code>"cbda"</code>，以此类推。注意，它也可以重排为 <code>"abcd"</code> 自身。</li>
    </ul>
    </li>

</ol>

<p>找出 <code>targetWords</code> 中有多少字符串能够由&nbsp;<code>startWords</code> 中的 <strong>任一</strong> 字符串执行上述转换操作获得。返回<em> </em><code>targetWords</code><em> </em>中这类 <strong>字符串的数目</strong> 。</p>

<p><strong>注意：</strong>你仅能验证 <code>targetWords</code> 中的字符串是否可以由 <code>startWords</code> 中的某个字符串经执行操作获得。<code>startWords</code>&nbsp; 中的字符串在这一过程中 <strong>不</strong> 发生实际变更。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>startWords = ["ant","act","tack"], targetWords = ["tack","act","acti"]
<strong>输出：</strong>2
<strong>解释：</strong>
- 为了形成 targetWords[0] = "tack" ，可以选用 startWords[1] = "act" ，追加字母 'k' ，并重排 "actk" 为 "tack" 。
- startWords 中不存在可以用于获得 targetWords[1] = "act" 的字符串。
  注意 "act" 确实存在于 startWords ，但是 <strong>必须</strong> 在重排前给这个字符串追加一个字母。
- 为了形成 targetWords[2] = "acti" ，可以选用 startWords[1] = "act" ，追加字母 'i' ，并重排 "acti" 为 "acti" 自身。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>startWords = ["ab","a"], targetWords = ["abc","abcd"]
<strong>输出：</strong>1
<strong>解释：</strong>
- 为了形成 targetWords[0] = "abc" ，可以选用 startWords[0] = "ab" ，追加字母 'c' ，并重排为 "abc" 。
- startWords 中不存在可以用于获得 targetWords[1] = "abcd" 的字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= startWords.length, targetWords.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= startWords[i].length, targetWords[j].length &lt;= 26</code></li>
	<li><code>startWords</code> 和 <code>targetWords</code> 中的每个字符串都仅由小写英文字母组成</li>
	<li>在 <code>startWords</code> 或 <code>targetWords</code> 的任一字符串中，每个字母至多出现一次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 位运算

我们注意到，题目中给定的字符串只包含小写字母，并且每个字符串的字母至多出现一次。因此，我们可以用一个长度为 $26$ 的二进制数表示一个字符串，其中第 $i$ 位为 $1$ 表示字符串中包含第 $i$ 个小写字母，为 $0$ 表示字符串中不包含第 $i$ 个小写字母。

我们可以将字符串数组 $\textit{startWords}$ 中的每个字符串转换为一个二进制数，并将这些二进制数存储到一个集合 $\textit{s}$ 中。对于字符串数组 $\textit{targetWords}$ 中的每个字符串，我们首先将其转换为一个二进制数，然后枚举这个字符串中的每个字母，将这个字母从二进制数中去掉，再检查是否存在一个二进制数在集合 $\textit{s}$ 中，使得这个二进制数与去掉的字母的二进制数的异或结果在集合 $\textit{s}$ 中，如果存在，那么这个字符串可以由 $\textit{startWords}$ 中的某个字符串执行转换操作获得，答案加一。然后我们跳过这个字符串，继续处理下一个字符串。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(n)$。其中 $n$ 为字符串数组 $\textit{targetWords}$ 的长度，而 $|\Sigma|$ 为字符串中的字符集大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        s = {sum(1 << (ord(c) - 97) for c in w) for w in startWords}
        ans = 0
        for w in targetWords:
            x = sum(1 << (ord(c) - 97) for c in w)
            for c in w:
                if x ^ (1 << (ord(c) - 97)) in s:
                    ans += 1
                    break
        return ans
```

#### Java

```java
class Solution {
    public int wordCount(String[] startWords, String[] targetWords) {
        Set<Integer> s = new HashSet<>();
        for (var w : startWords) {
            int x = 0;
            for (var c : w.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            s.add(x);
        }
        int ans = 0;
        for (var w : targetWords) {
            int x = 0;
            for (var c : w.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            for (var c : w.toCharArray()) {
                if (s.contains(x ^ (1 << (c - 'a')))) {
                    ++ans;
                    break;
                }
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
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> s;
        for (auto& w : startWords) {
            int x = 0;
            for (char c : w) {
                x |= 1 << (c - 'a');
            }
            s.insert(x);
        }
        int ans = 0;
        for (auto& w : targetWords) {
            int x = 0;
            for (char c : w) {
                x |= 1 << (c - 'a');
            }
            for (char c : w) {
                if (s.contains(x ^ (1 << (c - 'a')))) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func wordCount(startWords []string, targetWords []string) (ans int) {
	s := map[int]bool{}
	for _, w := range startWords {
		x := 0
		for _, c := range w {
			x |= 1 << (c - 'a')
		}
		s[x] = true
	}
	for _, w := range targetWords {
		x := 0
		for _, c := range w {
			x |= 1 << (c - 'a')
		}
		for _, c := range w {
			if s[x^(1<<(c-'a'))] {
				ans++
				break
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function wordCount(startWords: string[], targetWords: string[]): number {
    const s = new Set<number>();
    for (const w of startWords) {
        let x = 0;
        for (const c of w) {
            x ^= 1 << (c.charCodeAt(0) - 97);
        }
        s.add(x);
    }
    let ans = 0;
    for (const w of targetWords) {
        let x = 0;
        for (const c of w) {
            x ^= 1 << (c.charCodeAt(0) - 97);
        }
        for (const c of w) {
            if (s.has(x ^ (1 << (c.charCodeAt(0) - 97)))) {
                ++ans;
                break;
            }
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

# [2136. 全部开花的最早一天](https://leetcode.cn/problems/earliest-possible-day-of-full-bloom){#2136}

{{< tabs "2136" >}}

{{% tab "python" %}}
```python
class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        ans = t = 0
        for pt, gt in sorted(zip(plantTime, growTime), key=lambda x: -x[1]):
            t += pt
            ans = max(ans, t + gt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        int n = plantTime.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> growTime[j] - growTime[i]);
        int ans = 0, t = 0;
        for (int i : idx) {
            t += plantTime[i];
            ans = Math.max(ans, t + growTime[i]);
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
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return growTime[j] < growTime[i]; });
        int ans = 0, t = 0;
        for (int i : idx) {
            t += plantTime[i];
            ans = max(ans, t + growTime[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func earliestFullBloom(plantTime []int, growTime []int) (ans int) {
	n := len(plantTime)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return growTime[idx[j]] < growTime[idx[i]] })
	t := 0
	for _, i := range idx {
		t += plantTime[i]
		ans = max(ans, t+growTime[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function earliestFullBloom(plantTime: number[], growTime: number[]): number {
    const n = plantTime.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => growTime[j] - growTime[i]);
    let [ans, t] = [0, 0];
    for (const i of idx) {
        t += plantTime[i];
        ans = Math.max(ans, t + growTime[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
        let mut idx: Vec<usize> = (0..plant_time.len()).collect();
        idx.sort_by_key(|&i| -&grow_time[i]);
        let mut ans = 0;
        let mut t = 0;
        for &i in &idx {
            t += plant_time[i];
            ans = ans.max(t + grow_time[i]);
        }
        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有 <code>n</code> 枚花的种子。每枚种子必须先种下，才能开始生长、开花。播种需要时间，种子的生长也是如此。给你两个下标从 <strong>0</strong> 开始的整数数组 <code>plantTime</code> 和 <code>growTime</code> ，每个数组的长度都是 <code>n</code> ：</p>

<ul>
	<li><code>plantTime[i]</code> 是 <strong>播种</strong> 第 <code>i</code> 枚种子所需的 <strong>完整天数</strong> 。每天，你只能为播种某一枚种子而劳作。<strong>无须</strong> 连续几天都在种同一枚种子，但是种子播种必须在你工作的天数达到 <code>plantTime[i]</code> 之后才算完成。</li>
	<li><code>growTime[i]</code> 是第 <code>i</code> 枚种子完全种下后生长所需的 <strong>完整天数 </strong>。在它生长的最后一天 <strong>之后</strong> ，将会开花并且永远 <strong>绽放</strong> 。</li>
</ul>

<p>从第 <code>0</code> 开始，你可以按 <strong>任意</strong> 顺序播种种子。</p>

<p>返回所有种子都开花的 <strong>最早</strong> 一天是第几天。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2136.Earliest%20Possible%20Day%20of%20Full%20Bloom/images/1.png" style="width: 453px; height: 149px;">
<pre><strong>输入：</strong>plantTime = [1,4,3], growTime = [2,3,1]
<strong>输出：</strong>9
<strong>解释：</strong>灰色的花盆表示播种的日子，彩色的花盆表示生长的日子，花朵表示开花的日子。
一种最优方案是：
第 0 天，播种第 0 枚种子，种子生长 2 整天。并在第 3 天开花。
第 1、2、3、4 天，播种第 1 枚种子。种子生长 3 整天，并在第 8 天开花。
第 5、6、7 天，播种第 2 枚种子。种子生长 1 整天，并在第 9 天开花。
因此，在第 9 天，所有种子都开花。 
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2136.Earliest%20Possible%20Day%20of%20Full%20Bloom/images/2.png" style="width: 454px; height: 184px;">
<pre><strong>输入：</strong>plantTime = [1,2,3,2], growTime = [2,1,2,1]
<strong>输出：</strong>9
<strong>解释：</strong>灰色的花盆表示播种的日子，彩色的花盆表示生长的日子，花朵表示开花的日子。 
一种最优方案是：
第 1 天，播种第 0 枚种子，种子生长 2 整天。并在第 4 天开花。
第 0、3 天，播种第 1 枚种子。种子生长 1 整天，并在第 5 天开花。
第 2、4、5 天，播种第 2 枚种子。种子生长 2 整天，并在第 8 天开花。
第 6、7 天，播种第 3 枚种子。种子生长 1 整天，并在第 9 天开花。
因此，在第 9 天，所有种子都开花。 
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>plantTime = [1], growTime = [1]
<strong>输出：</strong>2
<strong>解释：</strong>第 0 天，播种第 0 枚种子。种子需要生长 1 整天，然后在第 2 天开花。
因此，在第 2 天，所有种子都开花。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == plantTime.length == growTime.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= plantTime[i], growTime[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

根据题目描述，我们知道，每一天只能为一枚种子进行播种，因此不管什么播种顺序，所有种子的播种时间之和总是等于 $\sum_{i=0}^{n-1} plantTime[i]$。那么，为了让尽快让所有种子开花，我们应该尽快播种生长时间最长的种子。因此，我们可以对所有种子按照生长时间从大到小进行排序，然后依次进行播种。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是种子的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        ans = t = 0
        for pt, gt in sorted(zip(plantTime, growTime), key=lambda x: -x[1]):
            t += pt
            ans = max(ans, t + gt)
        return ans
```

#### Java

```java
class Solution {
    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        int n = plantTime.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, (i, j) -> growTime[j] - growTime[i]);
        int ans = 0, t = 0;
        for (int i : idx) {
            t += plantTime[i];
            ans = Math.max(ans, t + growTime[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return growTime[j] < growTime[i]; });
        int ans = 0, t = 0;
        for (int i : idx) {
            t += plantTime[i];
            ans = max(ans, t + growTime[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func earliestFullBloom(plantTime []int, growTime []int) (ans int) {
	n := len(plantTime)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return growTime[idx[j]] < growTime[idx[i]] })
	t := 0
	for _, i := range idx {
		t += plantTime[i]
		ans = max(ans, t+growTime[i])
	}
	return
}
```

#### TypeScript

```ts
function earliestFullBloom(plantTime: number[], growTime: number[]): number {
    const n = plantTime.length;
    const idx: number[] = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => growTime[j] - growTime[i]);
    let [ans, t] = [0, 0];
    for (const i of idx) {
        t += plantTime[i];
        ans = Math.max(ans, t + growTime[i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn earliest_full_bloom(plant_time: Vec<i32>, grow_time: Vec<i32>) -> i32 {
        let mut idx: Vec<usize> = (0..plant_time.len()).collect();
        idx.sort_by_key(|&i| -&grow_time[i]);
        let mut ans = 0;
        let mut t = 0;
        for &i in &idx {
            t += plant_time[i];
            ans = ans.max(t + grow_time[i]);
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2137. 通过倒水操作让所有的水桶所含水量相等 🔒](https://leetcode.cn/problems/pour-water-between-buckets-to-make-water-levels-equal){#2137}

{{< tabs "2137" >}}

{{% tab "python" %}}
```python
class Solution:
    def equalizeWater(self, buckets: List[int], loss: int) -> float:
        def check(v):
            a = b = 0
            for x in buckets:
                if x >= v:
                    a += x - v
                else:
                    b += (v - x) * 100 / (100 - loss)
            return a >= b

        l, r = 0, max(buckets)
        while r - l > 1e-5:
            mid = (l + r) / 2
            if check(mid):
                l = mid
            else:
                r = mid
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double equalizeWater(int[] buckets, int loss) {
        double l = 0, r = Arrays.stream(buckets).max().getAsInt();
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            if (check(buckets, loss, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private boolean check(int[] buckets, int loss, double v) {
        double a = 0;
        double b = 0;
        for (int x : buckets) {
            if (x > v) {
                a += x - v;
            } else {
                b += (v - x) * 100 / (100 - loss);
            }
        }
        return a >= b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double equalizeWater(vector<int>& buckets, int loss) {
        double l = 0, r = *max_element(buckets.begin(), buckets.end());
        auto check = [&](double v) {
            double a = 0, b = 0;
            for (int x : buckets) {
                if (x > v) {
                    a += x - v;
                } else {
                    b += (v - x) * 100 / (100 - loss);
                }
            }
            return a >= b;
        };
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func equalizeWater(buckets []int, loss int) float64 {
	check := func(v float64) bool {
		var a, b float64
		for _, x := range buckets {
			if float64(x) >= v {
				a += float64(x) - v
			} else {
				b += (v - float64(x)) * 100 / float64(100-loss)
			}
		}
		return a >= b
	}

	l, r := float64(0), float64(slices.Max(buckets))
	for r-l > 1e-5 {
		mid := (l + r) / 2
		if check(mid) {
			l = mid
		} else {
			r = mid
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function equalizeWater(buckets: number[], loss: number): number {
    let l = 0;
    let r = Math.max(...buckets);
    const check = (v: number): boolean => {
        let [a, b] = [0, 0];
        for (const x of buckets) {
            if (x >= v) {
                a += x - v;
            } else {
                b += ((v - x) * 100) / (100 - loss);
            }
        }
        return a >= b;
    };
    while (r - l > 1e-5) {
        const mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有 <code>n</code> 个水桶，每个水桶中所含的水量用一个 <b>下标从 0 开始</b>&nbsp;的数组 <code>buckets</code> 给出，第 <code>i</code> 个水桶中有 <code>buckets[i]</code> 升水。</p>

<p>你想让所有的水桶中所含的水量相同。你可以从一个水桶向其它任意一个水桶倒任意数量的水（可以不是整数）。但是，你每倒 <code>k</code> 升水，<strong>百分之</strong> <code>loss</code> 的水会洒掉。</p>

<p>请返回经过倒水操作，所有水桶中的水量相同时，每个水桶中的 <strong>最大</strong> 水量。如果你的答案和标准答案的误差不超过 <code>10<sup>-5</sup></code>，那么答案将被通过。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> buckets = [1,2,7], loss = 80
<strong>输出:</strong> 2.00000
<strong>解释:</strong> 从水桶 2 向水桶 0 倒 5 升水。
5 * 80% = 4 升水会洒掉，水桶 0 只会获得 5 - 4 = 1 升水。
此时所有的水桶中都含有 2 升水，所以返回 2。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> buckets = [2,4,6], loss = 50
<strong>输出:</strong> 3.50000
<strong>解释:</strong> 从水桶 1 向水桶 0 倒 0.5 升水。
0.5 * 50% = 0.25 升水会洒掉，水桶 0 只会获得 0.5 - 0.25 = 0.25 升水。
此时, buckets = [2.25, 3.5, 6].

从水桶 2 向水桶 0 倒 2.5 升水。
2.5 * 50% = 1.25 升水会洒掉，水桶 0 只会获得 2.5 - 1.25 = 1.25 升水。
此时所有的水桶中都含有 3.5 升水，所以返回 3.5。
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> buckets = [3,3,3,3], loss = 40
<strong>输出:</strong> 3.00000
<strong>解释:</strong> 所有的水桶已经含有相同的水量。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= buckets.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= buckets[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= loss &lt;= 99</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找（浮点数二分）

我们注意到，如果一个水量 $x$ 满足条件，那么所有小于 $x$ 的水量也满足条件。因此我们可以使用二分查找的方法找到最大的满足条件的水量。

我们定义二分查找的左边界 $l=0$，右边界 $r=\max(buckets)$。每次二分查找时，我们取 $l$ 和 $r$ 的中点 $mid$，判断 $mid$ 是否满足条件。如果满足条件，那么我们将 $l$ 更新为 $mid$，否则我们将 $r$ 更新为 $m$。在二分查找结束后，最大的满足条件的水量即为 $l$。

问题的关键转换为如果判断一个水量 $v$ 是否满足条件。我们可以遍历所有水桶，对于每个水桶，如果其水量大于 $v$，那么需要倒出 $x-v$ 的水量；如果其水量小于 $v$，那么需要向其中倒入 $(v-x)\times\frac{100}{100-\textit{loss}}$ 的水量。如果倒出的水量大于等于倒入的水量，那么说明 $v$ 满足条件。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 $buckets$ 的长度和最大值。二分查找的时间复杂度为 $O(\log M)$，每次二分查找需要遍历数组 $buckets$，时间复杂度为 $O(n)$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def equalizeWater(self, buckets: List[int], loss: int) -> float:
        def check(v):
            a = b = 0
            for x in buckets:
                if x >= v:
                    a += x - v
                else:
                    b += (v - x) * 100 / (100 - loss)
            return a >= b

        l, r = 0, max(buckets)
        while r - l > 1e-5:
            mid = (l + r) / 2
            if check(mid):
                l = mid
            else:
                r = mid
        return l
```

#### Java

```java
class Solution {
    public double equalizeWater(int[] buckets, int loss) {
        double l = 0, r = Arrays.stream(buckets).max().getAsInt();
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            if (check(buckets, loss, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private boolean check(int[] buckets, int loss, double v) {
        double a = 0;
        double b = 0;
        for (int x : buckets) {
            if (x > v) {
                a += x - v;
            } else {
                b += (v - x) * 100 / (100 - loss);
            }
        }
        return a >= b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double equalizeWater(vector<int>& buckets, int loss) {
        double l = 0, r = *max_element(buckets.begin(), buckets.end());
        auto check = [&](double v) {
            double a = 0, b = 0;
            for (int x : buckets) {
                if (x > v) {
                    a += x - v;
                } else {
                    b += (v - x) * 100 / (100 - loss);
                }
            }
            return a >= b;
        };
        while (r - l > 1e-5) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```

#### Go

```go
func equalizeWater(buckets []int, loss int) float64 {
	check := func(v float64) bool {
		var a, b float64
		for _, x := range buckets {
			if float64(x) >= v {
				a += float64(x) - v
			} else {
				b += (v - float64(x)) * 100 / float64(100-loss)
			}
		}
		return a >= b
	}

	l, r := float64(0), float64(slices.Max(buckets))
	for r-l > 1e-5 {
		mid := (l + r) / 2
		if check(mid) {
			l = mid
		} else {
			r = mid
		}
	}
	return l
}
```

#### TypeScript

```ts
function equalizeWater(buckets: number[], loss: number): number {
    let l = 0;
    let r = Math.max(...buckets);
    const check = (v: number): boolean => {
        let [a, b] = [0, 0];
        for (const x of buckets) {
            if (x >= v) {
                a += x - v;
            } else {
                b += ((v - x) * 100) / (100 - loss);
            }
        }
        return a >= b;
    };
    while (r - l > 1e-5) {
        const mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2138. 将字符串拆分为若干长度为 k 的组](https://leetcode.cn/problems/divide-a-string-into-groups-of-size-k){#2138}

{{< tabs "2138" >}}

{{% tab "python" %}}
```python
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [s[i : i + k].ljust(k, fill) for i in range(0, len(s), k)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        String[] ans = new String[(n + k - 1) / k];
        if (n % k != 0) {
            s += String.valueOf(fill).repeat(k - n % k);
        }
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = s.substring(i * k, (i + 1) * k);
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
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        if (n % k) {
            s += string(k - n % k, fill);
        }
        vector<string> ans;
        for (int i = 0; i < s.size() / k; ++i) {
            ans.push_back(s.substr(i * k, k));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divideString(s string, k int, fill byte) (ans []string) {
	n := len(s)
	if n%k != 0 {
		s += strings.Repeat(string(fill), k-n%k)
	}
	for i := 0; i < len(s)/k; i++ {
		ans = append(ans, s[i*k:(i+1)*k])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divideString(s: string, k: number, fill: string): string[] {
    const ans: string[] = [];
    for (let i = 0; i < s.length; i += k) {
        ans.push(s.slice(i, i + k).padEnd(k, fill));
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

<p>字符串 <code>s</code> 可以按下述步骤划分为若干长度为 <code>k</code> 的组：</p>

<ul>
	<li>第一组由字符串中的前 <code>k</code> 个字符组成，第二组由接下来的 <code>k</code> 个字符串组成，依此类推。每个字符都能够成为 <strong>某一个</strong> 组的一部分。</li>
	<li>对于最后一组，如果字符串剩下的字符 <strong>不足</strong> <code>k</code> 个，需使用字符 <code>fill</code> 来补全这一组字符。</li>
</ul>

<p>注意，在去除最后一个组的填充字符 <code>fill</code>（如果存在的话）并按顺序连接所有的组后，所得到的字符串应该是 <code>s</code> 。</p>

<p>给你一个字符串 <code>s</code> ，以及每组的长度 <code>k</code> 和一个用于填充的字符 <code>fill</code> ，按上述步骤处理之后，返回一个字符串数组，该数组表示 <code>s</code> 分组后 <strong>每个组的组成情况</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdefghi", k = 3, fill = 'x'
<strong>输出：</strong>["abc","def","ghi"]
<strong>解释：</strong>
前 3 个字符是 "abc" ，形成第一组。
接下来 3 个字符是 "def" ，形成第二组。
最后 3 个字符是 "ghi" ，形成第三组。
由于所有组都可以由字符串中的字符完全填充，所以不需要使用填充字符。
因此，形成 3 组，分别是 "abc"、"def" 和 "ghi" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdefghij", k = 3, fill = 'x'
<strong>输出：</strong>["abc","def","ghi","jxx"]
<strong>解释：</strong>
与前一个例子类似，形成前三组 "abc"、"def" 和 "ghi" 。
对于最后一组，字符串中仅剩下字符 'j' 可以用。为了补全这一组，使用填充字符 'x' 两次。
因此，形成 4 组，分别是 "abc"、"def"、"ghi" 和 "jxx" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>fill</code> 是一个小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以直接模拟题目描述的过程，将字符串 $s$ 按照长度 $k$ 进行分组，然后对于最后一组不足 $k$ 个字符的情况，使用字符 $\textit{fill}$ 进行填充。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [s[i : i + k].ljust(k, fill) for i in range(0, len(s), k)]
```

#### Java

```java
class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        String[] ans = new String[(n + k - 1) / k];
        if (n % k != 0) {
            s += String.valueOf(fill).repeat(k - n % k);
        }
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = s.substring(i * k, (i + 1) * k);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        if (n % k) {
            s += string(k - n % k, fill);
        }
        vector<string> ans;
        for (int i = 0; i < s.size() / k; ++i) {
            ans.push_back(s.substr(i * k, k));
        }
        return ans;
    }
};
```

#### Go

```go
func divideString(s string, k int, fill byte) (ans []string) {
	n := len(s)
	if n%k != 0 {
		s += strings.Repeat(string(fill), k-n%k)
	}
	for i := 0; i < len(s)/k; i++ {
		ans = append(ans, s[i*k:(i+1)*k])
	}
	return
}
```

#### TypeScript

```ts
function divideString(s: string, k: number, fill: string): string[] {
    const ans: string[] = [];
    for (let i = 0; i < s.length; i += k) {
        ans.push(s.slice(i, i + k).padEnd(k, fill));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2139. 得到目标值的最少行动次数](https://leetcode.cn/problems/minimum-moves-to-reach-target-score){#2139}

{{< tabs "2139" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        while maxDoubles and target > 1:
            ans += 1
            if target % 2 == 1:
                target -= 1
            else:
                maxDoubles -= 1
                target >>= 1
        ans += target - 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMoves(target int, maxDoubles int) (ans int) {
	for maxDoubles > 0 && target > 1 {
		ans++
		if target&1 == 1 {
			target--
		} else {
			maxDoubles--
			target >>= 1
		}
	}
	ans += target - 1
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minMoves(target: number, maxDoubles: number): number {
    let ans = 0;
    while (maxDoubles && target > 1) {
        ++ans;
        if (target & 1) {
            --target;
        } else {
            --maxDoubles;
            target >>= 1;
        }
    }
    ans += target - 1;
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在玩一个整数游戏。从整数 <code>1</code> 开始，期望得到整数 <code>target</code> 。</p>

<p>在一次行动中，你可以做下述两种操作之一：</p>

<ul>
	<li><strong>递增</strong>，将当前整数的值加 1（即， <code>x = x + 1</code>）。</li>
	<li><strong>加倍</strong>，使当前整数的值翻倍（即，<code>x = 2 * x</code>）。</li>
</ul>

<p>在整个游戏过程中，你可以使用 <strong>递增</strong> 操作 <strong>任意</strong> 次数。但是只能使用 <strong>加倍</strong> 操作 <strong>至多</strong> <code>maxDoubles</code> 次。</p>

<p>给你两个整数 <code>target</code> 和 <code>maxDoubles</code> ，返回从 1 开始得到<em> </em><code>target</code><em> </em>需要的最少行动次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>target = 5, maxDoubles = 0
<strong>输出：</strong>4
<strong>解释：</strong>一直递增 1 直到得到 target 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>target = 19, maxDoubles = 2
<strong>输出：</strong>7
<strong>解释：</strong>最初，x = 1 。
递增 3 次，x = 4 。
加倍 1 次，x = 8 。
递增 1 次，x = 9 。
加倍 1 次，x = 18 。
递增 1 次，x = 19 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>target = 10, maxDoubles = 4
<strong>输出：</strong>4
<strong>解释：</strong>
最初，x = 1 。 
递增 1 次，x = 2 。 
加倍 1 次，x = 4 。 
递增 1 次，x = 5 。 
加倍 1 次，x = 10 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= maxDoubles &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：倒推 + 贪心

我们不妨从最终的状态开始倒推，假设最终的状态为 $target$，那么我们可以得到 $target$ 的前一个状态为 $target - 1$ 或者 $target / 2$，这取决于 $target$ 的奇偶性以及 $maxDoubles$ 的值。

如果 $target=1$，那么不需要任何操作，直接返回 $0$ 即可。

如果 $maxDoubles=0$，那么我们只能使用递增操作，因此我们需要 $target-1$ 次操作。

如果 $target$ 是偶数且 $maxDoubles>0$，那么我们可以使用加倍操作，因此我们需要 $1$ 次操作，然后递归求解 $target/2$ 和 $maxDoubles-1$。

如果 $target$ 是奇数，那么我们只能使用递增操作，因此我们需要 $1$ 次操作，然后递归求解 $target-1$ 和 $maxDoubles$。

时间复杂度 $O(\min(\log target, maxDoubles))$，空间复杂度 $O(\min(\log target, maxDoubles))$。

我们也可以将上述过程改为迭代的方式，这样可以避免递归的空间开销。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMoves(self, target: int, maxDoubles: int) -> int:
        if target == 1:
            return 0
        if maxDoubles == 0:
            return target - 1
        if target % 2 == 0 and maxDoubles:
            return 1 + self.minMoves(target >> 1, maxDoubles - 1)
        return 1 + self.minMoves(target - 1, maxDoubles)
```

#### Java

```java
class Solution {
    public int minMoves(int target, int maxDoubles) {
        if (target == 1) {
            return 0;
        }
        if (maxDoubles == 0) {
            return target - 1;
        }
        if (target % 2 == 0 && maxDoubles > 0) {
            return 1 + minMoves(target >> 1, maxDoubles - 1);
        }
        return 1 + minMoves(target - 1, maxDoubles);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if (target == 1) {
            return 0;
        }
        if (maxDoubles == 0) {
            return target - 1;
        }
        if (target % 2 == 0 && maxDoubles > 0) {
            return 1 + minMoves(target >> 1, maxDoubles - 1);
        }
        return 1 + minMoves(target - 1, maxDoubles);
    }
};
```

#### Go

```go
func minMoves(target int, maxDoubles int) int {
	if target == 1 {
		return 0
	}
	if maxDoubles == 0 {
		return target - 1
	}
	if target%2 == 0 && maxDoubles > 0 {
		return 1 + minMoves(target>>1, maxDoubles-1)
	}
	return 1 + minMoves(target-1, maxDoubles)
}
```

#### TypeScript

```ts
function minMoves(target: number, maxDoubles: number): number {
    if (target === 1) {
        return 0;
    }
    if (maxDoubles === 0) {
        return target - 1;
    }
    if (target % 2 === 0 && maxDoubles) {
        return 1 + minMoves(target >> 1, maxDoubles - 1);
    }
    return 1 + minMoves(target - 1, maxDoubles);
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
    def minMoves(self, target: int, maxDoubles: int) -> int:
        ans = 0
        while maxDoubles and target > 1:
            ans += 1
            if target % 2 == 1:
                target -= 1
            else:
                maxDoubles -= 1
                target >>= 1
        ans += target - 1
        return ans
```

#### Java

```java
class Solution {
    public int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while (maxDoubles > 0 && target > 1) {
            ++ans;
            if (target % 2 == 1) {
                --target;
            } else {
                --maxDoubles;
                target >>= 1;
            }
        }
        ans += target - 1;
        return ans;
    }
};
```

#### Go

```go
func minMoves(target int, maxDoubles int) (ans int) {
	for maxDoubles > 0 && target > 1 {
		ans++
		if target&1 == 1 {
			target--
		} else {
			maxDoubles--
			target >>= 1
		}
	}
	ans += target - 1
	return
}
```

#### TypeScript

```ts
function minMoves(target: number, maxDoubles: number): number {
    let ans = 0;
    while (maxDoubles && target > 1) {
        ++ans;
        if (target & 1) {
            --target;
        } else {
            --maxDoubles;
            target >>= 1;
        }
    }
    ans += target - 1;
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
