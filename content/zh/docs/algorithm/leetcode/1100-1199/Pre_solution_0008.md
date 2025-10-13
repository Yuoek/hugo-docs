---
title: "1170_比较字符串最小字母出现频次"
date: 2025-10-08T18:36:57+08:00
weight: 8
tags: [二分查找, 位运算, 前缀和, 哈希表, 堆（优先队列）, 字典树, 字符串, 排序, 数学, 数据库, 数组, 栈, 滑动窗口, 设计, 链表]
---

{{< markmap >}}
### [1170_比较字符串最小字母出现频次](#1170)
#### [数组](#1170)
#### [哈希表](#1170)
#### [字符串](#1170)
#### [二分查找](#1170)
#### [排序](#1170)
### [1171_从链表中删去总和值为零的连续节点](#1171)
#### [哈希表](#1171)
#### [链表](#1171)
### [1172_餐盘栈](#1172)
#### [栈](#1172)
#### [设计](#1172)
#### [哈希表](#1172)
#### [堆（优先队列）](#1172)
### [1173_即时食物配送 I 🔒](#1173)
#### [数据库](#1173)
### [1174_即时食物配送 II](#1174)
#### [数据库](#1174)
### [1175_质数排列](#1175)
#### [数学](#1175)
### [1176_健身计划评估 🔒](#1176)
#### [数组](#1176)
#### [滑动窗口](#1176)
### [1177_构建回文串检测](#1177)
#### [位运算](#1177)
#### [数组](#1177)
#### [哈希表](#1177)
#### [字符串](#1177)
#### [前缀和](#1177)
### [1178_猜字谜](#1178)
#### [位运算](#1178)
#### [字典树](#1178)
#### [数组](#1178)
#### [哈希表](#1178)
#### [字符串](#1178)
### [1179_重新格式化部门表](#1179)
#### [数据库](#1179)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1170_比较字符串最小字母出现频次
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
___
#### 排序
---
### 1171_从链表中删去总和值为零的连续节点
___
#### 哈希表
___
#### 链表
---
### 1172_餐盘栈
___
#### 栈
___
#### 设计
___
#### 哈希表
___
#### 堆（优先队列）
---
### 1173_即时食物配送 I 🔒
___
#### 数据库
---
### 1174_即时食物配送 II
___
#### 数据库
---
### 1175_质数排列
___
#### 数学
---
### 1176_健身计划评估 🔒
___
#### 数组
___
#### 滑动窗口
---
### 1177_构建回文串检测
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 前缀和
---
### 1178_猜字谜
___
#### 位运算
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 1179_重新格式化部门表
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 哈希表 | 堆（优先队列） | 字典树 |
| 字符串 | 排序 | 数学 |
| 数据库 | 数组 | 栈 |
| 滑动窗口 | 设计 | 链表 |

# [1170. 比较字符串最小字母出现频次](https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character){#1170}

{{< tabs "1170" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def f(s: str) -> int:
            cnt = Counter(s)
            return next(cnt[c] for c in ascii_lowercase if cnt[c])

        n = len(words)
        nums = sorted(f(w) for w in words)
        return [n - bisect_right(nums, f(q)) for q in queries]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int n = words.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = f(words[i]);
        }
        Arrays.sort(nums);
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int x = f(queries[i]);
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (nums[mid] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = n - l;
        }
        return ans;
    }

    private int f(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int x : cnt) {
            if (x > 0) {
                return x;
            }
        }
        return 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](string s) {
            int cnt[26] = {0};
            for (char c : s) {
                cnt[c - 'a']++;
            }
            for (int x : cnt) {
                if (x) {
                    return x;
                }
            }
            return 0;
        };
        int n = words.size();
        int nums[n];
        for (int i = 0; i < n; i++) {
            nums[i] = f(words[i]);
        }
        sort(nums, nums + n);
        vector<int> ans;
        for (auto& q : queries) {
            int x = f(q);
            ans.push_back(n - (upper_bound(nums, nums + n, x) - nums));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSmallerByFrequency(queries []string, words []string) (ans []int) {
	f := func(s string) int {
		cnt := [26]int{}
		for _, c := range s {
			cnt[c-'a']++
		}
		for _, x := range cnt {
			if x > 0 {
				return x
			}
		}
		return 0
	}
	n := len(words)
	nums := make([]int, n)
	for i, w := range words {
		nums[i] = f(w)
	}
	sort.Ints(nums)
	for _, q := range queries {
		x := f(q)
		ans = append(ans, n-sort.SearchInts(nums, x+1))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSmallerByFrequency(queries: string[], words: string[]): number[] {
    const f = (s: string): number => {
        const cnt = new Array(26).fill(0);
        for (const c of s) {
            cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        return cnt.find(x => x > 0);
    };
    const nums = words.map(f).sort((a, b) => a - b);
    const ans: number[] = [];
    for (const q of queries) {
        const x = f(q);
        let l = 0,
            r = nums.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans.push(nums.length - l);
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

<p>定义一个函数 <code>f(s)</code>，统计 <code>s</code>  中<strong>（按字典序比较）最小字母的出现频次</strong> ，其中 <code>s</code> 是一个非空字符串。</p>

<p>例如，若 <code>s = "dcce"</code>，那么 <code>f(s) = 2</code>，因为字典序最小字母是 <code>"c"</code>，它出现了 2 次。</p>

<p>现在，给你两个字符串数组待查表 <code>queries</code> 和词汇表 <code>words</code> 。对于每次查询 <code>queries[i]</code> ，需统计 <code>words</code> 中满足 <code>f(queries[i])</code> < <code>f(W)</code> 的<strong> 词的数目</strong> ，<code>W</code> 表示词汇表 <code>words</code> 中的每个词。</p>

<p>请你返回一个整数数组 <code>answer</code> 作为答案，其中每个 <code>answer[i]</code> 是第 <code>i</code> 次查询的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>queries = ["cbd"], words = ["zaaaz"]
<strong>输出：</strong>[1]
<strong>解释：</strong>查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
<strong>输出：</strong>[1,2]
<strong>解释：</strong>第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= queries.length <= 2000</code></li>
	<li><code>1 <= words.length <= 2000</code></li>
	<li><code>1 <= queries[i].length, words[i].length <= 10</code></li>
	<li><code>queries[i][j]</code>、<code>words[i][j]</code> 都由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们先按照题目描述，实现函数 $f(s)$，函数返回字符串 $s$ 中按字典序比较最小字母的出现频次。

接下来，我们将 $words$ 中的每个字符串 $w$ 都计算出 $f(w)$，并将其排序，存放在数组 $nums$ 中。

然后，我们遍历 $queries$ 中的每个字符串 $q$，在 $nums$ 中二分查找第一个大于 $f(q)$ 的位置 $i$，则 $nums$ 中下标 $i$ 及其后面的元素都满足 $f(q) < f(W)$，那么当前查询的答案就是 $n - i$。

时间复杂度 $O((n + q) \times M)$，空间复杂度 $O(n)$。其中 $n$ 和 $q$ 分别是数组 $words$ 和 $queries$ 的长度，而 $M$ 是字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        def f(s: str) -> int:
            cnt = Counter(s)
            return next(cnt[c] for c in ascii_lowercase if cnt[c])

        n = len(words)
        nums = sorted(f(w) for w in words)
        return [n - bisect_right(nums, f(q)) for q in queries]
```

#### Java

```java
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int n = words.length;
        int[] nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = f(words[i]);
        }
        Arrays.sort(nums);
        int m = queries.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int x = f(queries[i]);
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (nums[mid] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            ans[i] = n - l;
        }
        return ans;
    }

    private int f(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        for (int x : cnt) {
            if (x > 0) {
                return x;
            }
        }
        return 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto f = [](string s) {
            int cnt[26] = {0};
            for (char c : s) {
                cnt[c - 'a']++;
            }
            for (int x : cnt) {
                if (x) {
                    return x;
                }
            }
            return 0;
        };
        int n = words.size();
        int nums[n];
        for (int i = 0; i < n; i++) {
            nums[i] = f(words[i]);
        }
        sort(nums, nums + n);
        vector<int> ans;
        for (auto& q : queries) {
            int x = f(q);
            ans.push_back(n - (upper_bound(nums, nums + n, x) - nums));
        }
        return ans;
    }
};
```

#### Go

```go
func numSmallerByFrequency(queries []string, words []string) (ans []int) {
	f := func(s string) int {
		cnt := [26]int{}
		for _, c := range s {
			cnt[c-'a']++
		}
		for _, x := range cnt {
			if x > 0 {
				return x
			}
		}
		return 0
	}
	n := len(words)
	nums := make([]int, n)
	for i, w := range words {
		nums[i] = f(w)
	}
	sort.Ints(nums)
	for _, q := range queries {
		x := f(q)
		ans = append(ans, n-sort.SearchInts(nums, x+1))
	}
	return
}
```

#### TypeScript

```ts
function numSmallerByFrequency(queries: string[], words: string[]): number[] {
    const f = (s: string): number => {
        const cnt = new Array(26).fill(0);
        for (const c of s) {
            cnt[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        return cnt.find(x => x > 0);
    };
    const nums = words.map(f).sort((a, b) => a - b);
    const ans: number[] = [];
    for (const q of queries) {
        const x = f(q);
        let l = 0,
            r = nums.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] > x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans.push(nums.length - l);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1171. 从链表中删去总和值为零的连续节点](https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list){#1171}

{{< tabs "1171" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        last = {}
        s, cur = 0, dummy
        while cur:
            s += cur.val
            last[s] = cur
            cur = cur.next
        s, cur = 0, dummy
        while cur:
            s += cur.val
            cur.next = last[s].next
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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        Map<Integer, ListNode> last = new HashMap<>();
        int s = 0;
        ListNode cur = dummy;
        while (cur != null) {
            s += cur.val;
            last.put(s, cur);
            cur = cur.next;
        }
        s = 0;
        cur = dummy;
        while (cur != null) {
            s += cur.val;
            cur.next = last.get(s).next;
            cur = cur.next;
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> last;
        ListNode* cur = dummy;
        int s = 0;
        while (cur) {
            s += cur->val;
            last[s] = cur;
            cur = cur->next;
        }
        s = 0;
        cur = dummy;
        while (cur) {
            s += cur->val;
            cur->next = last[s]->next;
            cur = cur->next;
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
func removeZeroSumSublists(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	last := map[int]*ListNode{}
	cur := dummy
	s := 0
	for cur != nil {
		s += cur.Val
		last[s] = cur
		cur = cur.Next
	}
	s = 0
	cur = dummy
	for cur != nil {
		s += cur.Val
		cur.Next = last[s].Next
		cur = cur.Next
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

function removeZeroSumSublists(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    const last = new Map<number, ListNode>();
    let s = 0;
    for (let cur = dummy; cur; cur = cur.next) {
        s += cur.val;
        last.set(s, cur);
    }
    s = 0;
    for (let cur = dummy; cur; cur = cur.next) {
        s += cur.val;
        cur.next = last.get(s)!.next;
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
    pub fn remove_zero_sum_sublists(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut last = std::collections::HashMap::new();
        let mut s = 0;
        let mut p = dummy.as_ref();
        while let Some(node) = p {
            s += node.val;
            last.insert(s, node);
            p = node.next.as_ref();
        }

        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut q = dummy.as_mut();
        s = 0;
        while let Some(cur) = q {
            s += cur.val;
            if let Some(node) = last.get(&s) {
                cur.next = node.next.clone();
            }
            q = cur.next.as_mut();
        }
        dummy.unwrap().next
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表的头节点&nbsp;<code>head</code>，请你编写代码，反复删去链表中由 <strong>总和</strong>&nbsp;值为 <code>0</code> 的连续节点组成的序列，直到不存在这样的序列为止。</p>

<p>删除完毕后，请你返回最终结果链表的头节点。</p>

<p>&nbsp;</p>

<p>你可以返回任何满足题目要求的答案。</p>

<p>（注意，下面示例中的所有序列，都是对&nbsp;<code>ListNode</code>&nbsp;对象序列化的表示。）</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [1,2,-3,3,1]
<strong>输出：</strong>[3,1]
<strong>提示：</strong>答案 [1,2,1] 也是正确的。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>head = [1,2,3,-3,4]
<strong>输出：</strong>[1,2,4]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1,2,3,-3,-2]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>给你的链表中可能有 <code>1</code> 到&nbsp;<code>1000</code>&nbsp;个节点。</li>
	<li>对于链表中的每个节点，节点的值：<code>-1000 &lt;= node.val &lt;= 1000</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

若链表节点的两个前缀和相等，说明两个前缀和之间的连续节点序列的和为 $0$，那么可以消去这部分连续节点。

我们第一次遍历链表，用哈希表 $last$ 记录前缀和以及对应的链表节点，对于同一前缀和 $s$，后面出现的节点覆盖前面的节点。

接下来，我们再次遍历链表，若当前节点 $cur$ 的前缀和 $s$ 在 $last$ 出现，说明 $cur$ 与 $last[s]$ 之间的所有节点和为 $0$，我们直接修改 $cur$ 的指向，即 $cur.next = last[s].next$，这样就删去了这部分和为 $0$ 的连续节点。继续往后遍历，删除所有和为 $0$ 的连续节点。

最后返回链表的头节点 $dummy.next$。

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
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        last = {}
        s, cur = 0, dummy
        while cur:
            s += cur.val
            last[s] = cur
            cur = cur.next
        s, cur = 0, dummy
        while cur:
            s += cur.val
            cur.next = last[s].next
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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        Map<Integer, ListNode> last = new HashMap<>();
        int s = 0;
        ListNode cur = dummy;
        while (cur != null) {
            s += cur.val;
            last.put(s, cur);
            cur = cur.next;
        }
        s = 0;
        cur = dummy;
        while (cur != null) {
            s += cur.val;
            cur.next = last.get(s).next;
            cur = cur.next;
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> last;
        ListNode* cur = dummy;
        int s = 0;
        while (cur) {
            s += cur->val;
            last[s] = cur;
            cur = cur->next;
        }
        s = 0;
        cur = dummy;
        while (cur) {
            s += cur->val;
            cur->next = last[s]->next;
            cur = cur->next;
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
func removeZeroSumSublists(head *ListNode) *ListNode {
	dummy := &ListNode{0, head}
	last := map[int]*ListNode{}
	cur := dummy
	s := 0
	for cur != nil {
		s += cur.Val
		last[s] = cur
		cur = cur.Next
	}
	s = 0
	cur = dummy
	for cur != nil {
		s += cur.Val
		cur.Next = last[s].Next
		cur = cur.Next
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

function removeZeroSumSublists(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    const last = new Map<number, ListNode>();
    let s = 0;
    for (let cur = dummy; cur; cur = cur.next) {
        s += cur.val;
        last.set(s, cur);
    }
    s = 0;
    for (let cur = dummy; cur; cur = cur.next) {
        s += cur.val;
        cur.next = last.get(s)!.next;
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
    pub fn remove_zero_sum_sublists(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut last = std::collections::HashMap::new();
        let mut s = 0;
        let mut p = dummy.as_ref();
        while let Some(node) = p {
            s += node.val;
            last.insert(s, node);
            p = node.next.as_ref();
        }

        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut q = dummy.as_mut();
        s = 0;
        while let Some(cur) = q {
            s += cur.val;
            if let Some(node) = last.get(&s) {
                cur.next = node.next.clone();
            }
            q = cur.next.as_mut();
        }
        dummy.unwrap().next
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1172. 餐盘栈](https://leetcode.cn/problems/dinner-plate-stacks){#1172}

{{< tabs "1172" >}}

{{% tab "python" %}}
```python
class DinnerPlates:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.stacks = []
        self.not_full = SortedSet()

    def push(self, val: int) -> None:
        if not self.not_full:
            self.stacks.append([val])
            if self.capacity > 1:
                self.not_full.add(len(self.stacks) - 1)
        else:
            index = self.not_full[0]
            self.stacks[index].append(val)
            if len(self.stacks[index]) == self.capacity:
                self.not_full.discard(index)

    def pop(self) -> int:
        return self.popAtStack(len(self.stacks) - 1)

    def popAtStack(self, index: int) -> int:
        if index < 0 or index >= len(self.stacks) or not self.stacks[index]:
            return -1
        val = self.stacks[index].pop()
        if index == len(self.stacks) - 1 and not self.stacks[-1]:
            while self.stacks and not self.stacks[-1]:
                self.not_full.discard(len(self.stacks) - 1)
                self.stacks.pop()
        else:
            self.not_full.add(index)
        return val


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class DinnerPlates {
    private int capacity;
    private List<Deque<Integer>> stacks = new ArrayList<>();
    private TreeSet<Integer> notFull = new TreeSet<>();

    public DinnerPlates(int capacity) {
        this.capacity = capacity;
    }

    public void push(int val) {
        if (notFull.isEmpty()) {
            stacks.add(new ArrayDeque<>());
            stacks.get(stacks.size() - 1).push(val);
            if (capacity > 1) {
                notFull.add(stacks.size() - 1);
            }
        } else {
            int index = notFull.first();
            stacks.get(index).push(val);
            if (stacks.get(index).size() == capacity) {
                notFull.pollFirst();
            }
        }
    }

    public int pop() {
        return popAtStack(stacks.size() - 1);
    }

    public int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks.get(index).isEmpty()) {
            return -1;
        }
        int val = stacks.get(index).pop();
        if (index == stacks.size() - 1 && stacks.get(stacks.size() - 1).isEmpty()) {
            while (!stacks.isEmpty() && stacks.get(stacks.size() - 1).isEmpty()) {
                notFull.remove(stacks.size() - 1);
                stacks.remove(stacks.size() - 1);
            }
        } else {
            notFull.add(index);
        }
        return val;
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (notFull.empty()) {
            stacks.emplace_back(stack<int>());
            stacks.back().push(val);
            if (capacity > 1) {
                notFull.insert(stacks.size() - 1);
            }
        } else {
            int index = *notFull.begin();
            stacks[index].push(val);
            if (stacks[index].size() == capacity) {
                notFull.erase(index);
            }
        }
    }

    int pop() {
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty()) {
            return -1;
        }
        int val = stacks[index].top();
        stacks[index].pop();
        if (index == stacks.size() - 1 && stacks[index].empty()) {
            while (!stacks.empty() && stacks.back().empty()) {
                notFull.erase(stacks.size() - 1);
                stacks.pop_back();
            }
        } else {
            notFull.insert(index);
        }
        return val;
    }

private:
    int capacity;
    vector<stack<int>> stacks;
    set<int> notFull;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type DinnerPlates struct {
	capacity int
	stacks   [][]int
	notFull  *redblacktree.Tree
}

func Constructor(capacity int) DinnerPlates {
	return DinnerPlates{capacity: capacity, notFull: redblacktree.NewWithIntComparator()}
}

func (this *DinnerPlates) Push(val int) {
	if this.notFull.Size() == 0 {
		this.stacks = append(this.stacks, []int{val})
		if this.capacity > 1 {
			this.notFull.Put(len(this.stacks)-1, nil)
		}
	} else {
		index, _ := this.notFull.Left().Key.(int)
		this.stacks[index] = append(this.stacks[index], val)
		if len(this.stacks[index]) == this.capacity {
			this.notFull.Remove(index)
		}
	}
}

func (this *DinnerPlates) Pop() int {
	return this.PopAtStack(len(this.stacks) - 1)
}

func (this *DinnerPlates) PopAtStack(index int) int {
	if index < 0 || index >= len(this.stacks) || len(this.stacks[index]) == 0 {
		return -1
	}
	val := this.stacks[index][len(this.stacks[index])-1]
	this.stacks[index] = this.stacks[index][:len(this.stacks[index])-1]
	if index == len(this.stacks)-1 && len(this.stacks[index]) == 0 {
		for len(this.stacks) > 0 && len(this.stacks[len(this.stacks)-1]) == 0 {
			this.notFull.Remove(len(this.stacks) - 1)
			this.stacks = this.stacks[:len(this.stacks)-1]
		}
	} else {
		this.notFull.Put(index, nil)
	}
	return val
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * obj.Push(val);
 * param_2 := obj.Pop();
 * param_3 := obj.PopAtStack(index);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class DinnerPlates {
    capacity: number;
    stacks: number[][];
    notFull: TreeSet<number>;

    constructor(capacity: number) {
        this.capacity = capacity;
        this.stacks = [];
        this.notFull = new TreeSet<number>();
    }

    push(val: number): void {
        if (this.notFull.size() === 0) {
            this.stacks.push([val]);
            if (this.capacity > 1) {
                this.notFull.add(this.stacks.length - 1);
            }
        } else {
            const index = this.notFull.first()!;
            this.stacks[index].push(val);
            if (this.stacks[index].length === this.capacity) {
                this.notFull.delete(index);
            }
        }
    }

    pop(): number {
        return this.popAtStack(this.stacks.length - 1);
    }

    popAtStack(index: number): number {
        if (index < 0 || index >= this.stacks.length || this.stacks[index].length === 0) {
            return -1;
        }
        const val = this.stacks[index].pop()!;
        if (index === this.stacks.length - 1 && this.stacks[index].length === 0) {
            while (this.stacks.length > 0 && this.stacks[this.stacks.length - 1].length === 0) {
                this.notFull.delete(this.stacks.length - 1);
                this.stacks.pop();
            }
        } else {
            this.notFull.add(index);
        }
        return val;
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * var obj = new DinnerPlates(capacity)
 * obj.push(val)
 * var param_2 = obj.pop()
 * var param_3 = obj.popAtStack(index)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们把无限数量 &infin; 的栈排成一行，按从左到右的次序从 0 开始编号。每个栈的的最大容量&nbsp;<code>capacity</code> 都相同。</p>

<p>实现一个叫「餐盘」的类&nbsp;<code>DinnerPlates</code>：</p>

<ul>
	<li><code>DinnerPlates(int capacity)</code>&nbsp;- 给出栈的最大容量&nbsp;<code>capacity</code>。</li>
	<li><code>void push(int val)</code>&nbsp;- 将给出的正整数&nbsp;<code>val</code>&nbsp;推入&nbsp;<strong>从左往右第一个&nbsp;</strong>没有满的栈。</li>
	<li><code>int pop()</code>&nbsp;- 返回&nbsp;<strong>从右往左第一个&nbsp;</strong>非空栈顶部的值，并将其从栈中删除；如果所有的栈都是空的，请返回&nbsp;<code>-1</code>。</li>
	<li><code>int popAtStack(int index)</code>&nbsp;- 返回编号&nbsp;<code>index</code>&nbsp;的栈顶部的值，并将其从栈中删除；如果编号&nbsp;<code>index</code>&nbsp;的栈是空的，请返回 <code>-1</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入： </strong>
[&quot;DinnerPlates&quot;,&quot;push&quot;,&quot;push&quot;,&quot;push&quot;,&quot;push&quot;,&quot;push&quot;,&quot;popAtStack&quot;,&quot;push&quot;,&quot;push&quot;,&quot;popAtStack&quot;,&quot;popAtStack&quot;,&quot;pop&quot;,&quot;pop&quot;,&quot;pop&quot;,&quot;pop&quot;,&quot;pop&quot;]
[[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
<strong>输出：</strong>
[null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]

<strong>解释：</strong>
DinnerPlates D = DinnerPlates(2);  // 初始化，栈最大容量 capacity = 2
D.push(1);
D.push(2);
D.push(3);
D.push(4);
D.push(5);         // 栈的现状为：    2 &nbsp;4
&nbsp;                                   1 &nbsp;3 &nbsp;5
                                    ﹈ ﹈ ﹈
D.popAtStack(0);   // 返回 2。栈的现状为：     &nbsp;4
            &nbsp;                             1 &nbsp;3 &nbsp;5
                                          ﹈ ﹈ ﹈
D.push(20);        // 栈的现状为：  20  4
&nbsp;                                  1 &nbsp;3 &nbsp;5
                                   ﹈ ﹈ ﹈
D.push(21);        // 栈的现状为：  20  4 21
&nbsp;                                  1 &nbsp;3 &nbsp;5
                                   ﹈ ﹈ ﹈
D.popAtStack(0);   // 返回 20。栈的现状为：       4 21
             &nbsp;                              1 &nbsp;3 &nbsp;5
                                            ﹈ ﹈ ﹈
D.popAtStack(2);   // 返回 21。栈的现状为：       4
             &nbsp;                              1 &nbsp;3 &nbsp;5
                                            ﹈ ﹈ ﹈ 
D.pop()            // 返回 5。栈的现状为：        4
             &nbsp;                              1 &nbsp;3 
                                            ﹈ ﹈  
D.pop()            // 返回 4。栈的现状为：    1  3 
                                           ﹈ ﹈   
D.pop()            // 返回 3。栈的现状为：    1 
                                           ﹈   
D.pop()            // 返回 1。现在没有栈。
D.pop()            // 返回 -1。仍然没有栈。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= capacity&nbsp;&lt;= 20000</code></li>
	<li><code>1 &lt;= val&nbsp;&lt;= 20000</code></li>
	<li><code>0 &lt;= index&nbsp;&lt;= 100000</code></li>
	<li>最多会对&nbsp;<code>push</code>，<code>pop</code>，和&nbsp;<code>popAtStack</code>&nbsp;进行 <code>200000</code> 次调用。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈数组 + 有序集合

我们定义以下数据结构或变量：

-   `capacity`：每个栈的容量；
-   `stacks`：栈数组，用于存储所有的栈，其中每个栈的最大容量都是 `capacity`；
-   `not_full`：有序集合，用于存储所有未满的栈在栈数组中的下标。

对于 `push(val)` 操作：

-   我们首先判断 `not_full` 是否为空，如果为空，则说明没有未满的栈，需要新建一个栈，然后将 `val` 压入该栈中，此时判断容量 `capacity` 是否大于 $1$，如果大于 $1$，则将该栈的下标加入 `not_full` 中。
-   如果 `not_full` 不为空，则说明有未满的栈，我们取出 `not_full` 中最小的下标 `index`，将 `val` 压入 `stacks[index]` 中，此时如果 `stacks[index]` 的容量等于 `capacity`，则将 `index` 从 `not_full` 中删除。

对于 `popAtStack(index)` 操作：

-   我们首先判断 `index` 是否在 `stacks` 的下标范围内，如果不在，则直接返回 $-1$。如果 `stacks[index]` 为空，同样直接返回 $-1$。
-   如果 `stacks[index]` 不为空，则弹出 `stacks[index]` 的栈顶元素 `val`。如果 `index` 等于 `stacks` 的长度减 $1$，则说明 `stacks[index]` 是最后一个栈，如果为空，我们循环将最后一个栈的下标从 `not_full` 中移出，并且在栈数组 `stacks` 中移除最后一个栈，直到最后一个栈不为空、或者栈数组 `stacks` 为空为止。否则，如果 `stacks[index]` 不是最后一个栈，我们将 `index` 加入 `not_full` 中。
-   最后返回 `val`。

对于 `pop()` 操作：

-   我们直接调用 `popAtStack(stacks.length - 1)` 即可。

时间复杂度 $(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为操作次数。

<!-- tabs:start -->

#### Python3

```python
class DinnerPlates:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.stacks = []
        self.not_full = SortedSet()

    def push(self, val: int) -> None:
        if not self.not_full:
            self.stacks.append([val])
            if self.capacity > 1:
                self.not_full.add(len(self.stacks) - 1)
        else:
            index = self.not_full[0]
            self.stacks[index].append(val)
            if len(self.stacks[index]) == self.capacity:
                self.not_full.discard(index)

    def pop(self) -> int:
        return self.popAtStack(len(self.stacks) - 1)

    def popAtStack(self, index: int) -> int:
        if index < 0 or index >= len(self.stacks) or not self.stacks[index]:
            return -1
        val = self.stacks[index].pop()
        if index == len(self.stacks) - 1 and not self.stacks[-1]:
            while self.stacks and not self.stacks[-1]:
                self.not_full.discard(len(self.stacks) - 1)
                self.stacks.pop()
        else:
            self.not_full.add(index)
        return val


# Your DinnerPlates object will be instantiated and called as such:
# obj = DinnerPlates(capacity)
# obj.push(val)
# param_2 = obj.pop()
# param_3 = obj.popAtStack(index)
```

#### Java

```java
class DinnerPlates {
    private int capacity;
    private List<Deque<Integer>> stacks = new ArrayList<>();
    private TreeSet<Integer> notFull = new TreeSet<>();

    public DinnerPlates(int capacity) {
        this.capacity = capacity;
    }

    public void push(int val) {
        if (notFull.isEmpty()) {
            stacks.add(new ArrayDeque<>());
            stacks.get(stacks.size() - 1).push(val);
            if (capacity > 1) {
                notFull.add(stacks.size() - 1);
            }
        } else {
            int index = notFull.first();
            stacks.get(index).push(val);
            if (stacks.get(index).size() == capacity) {
                notFull.pollFirst();
            }
        }
    }

    public int pop() {
        return popAtStack(stacks.size() - 1);
    }

    public int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks.get(index).isEmpty()) {
            return -1;
        }
        int val = stacks.get(index).pop();
        if (index == stacks.size() - 1 && stacks.get(stacks.size() - 1).isEmpty()) {
            while (!stacks.isEmpty() && stacks.get(stacks.size() - 1).isEmpty()) {
                notFull.remove(stacks.size() - 1);
                stacks.remove(stacks.size() - 1);
            }
        } else {
            notFull.add(index);
        }
        return val;
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */
```

#### C++

```cpp
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }

    void push(int val) {
        if (notFull.empty()) {
            stacks.emplace_back(stack<int>());
            stacks.back().push(val);
            if (capacity > 1) {
                notFull.insert(stacks.size() - 1);
            }
        } else {
            int index = *notFull.begin();
            stacks[index].push(val);
            if (stacks[index].size() == capacity) {
                notFull.erase(index);
            }
        }
    }

    int pop() {
        return popAtStack(stacks.size() - 1);
    }

    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty()) {
            return -1;
        }
        int val = stacks[index].top();
        stacks[index].pop();
        if (index == stacks.size() - 1 && stacks[index].empty()) {
            while (!stacks.empty() && stacks.back().empty()) {
                notFull.erase(stacks.size() - 1);
                stacks.pop_back();
            }
        } else {
            notFull.insert(index);
        }
        return val;
    }

private:
    int capacity;
    vector<stack<int>> stacks;
    set<int> notFull;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
```

#### Go

```go
type DinnerPlates struct {
	capacity int
	stacks   [][]int
	notFull  *redblacktree.Tree
}

func Constructor(capacity int) DinnerPlates {
	return DinnerPlates{capacity: capacity, notFull: redblacktree.NewWithIntComparator()}
}

func (this *DinnerPlates) Push(val int) {
	if this.notFull.Size() == 0 {
		this.stacks = append(this.stacks, []int{val})
		if this.capacity > 1 {
			this.notFull.Put(len(this.stacks)-1, nil)
		}
	} else {
		index, _ := this.notFull.Left().Key.(int)
		this.stacks[index] = append(this.stacks[index], val)
		if len(this.stacks[index]) == this.capacity {
			this.notFull.Remove(index)
		}
	}
}

func (this *DinnerPlates) Pop() int {
	return this.PopAtStack(len(this.stacks) - 1)
}

func (this *DinnerPlates) PopAtStack(index int) int {
	if index < 0 || index >= len(this.stacks) || len(this.stacks[index]) == 0 {
		return -1
	}
	val := this.stacks[index][len(this.stacks[index])-1]
	this.stacks[index] = this.stacks[index][:len(this.stacks[index])-1]
	if index == len(this.stacks)-1 && len(this.stacks[index]) == 0 {
		for len(this.stacks) > 0 && len(this.stacks[len(this.stacks)-1]) == 0 {
			this.notFull.Remove(len(this.stacks) - 1)
			this.stacks = this.stacks[:len(this.stacks)-1]
		}
	} else {
		this.notFull.Put(index, nil)
	}
	return val
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * obj.Push(val);
 * param_2 := obj.Pop();
 * param_3 := obj.PopAtStack(index);
 */
```

#### TypeScript

```ts
class DinnerPlates {
    capacity: number;
    stacks: number[][];
    notFull: TreeSet<number>;

    constructor(capacity: number) {
        this.capacity = capacity;
        this.stacks = [];
        this.notFull = new TreeSet<number>();
    }

    push(val: number): void {
        if (this.notFull.size() === 0) {
            this.stacks.push([val]);
            if (this.capacity > 1) {
                this.notFull.add(this.stacks.length - 1);
            }
        } else {
            const index = this.notFull.first()!;
            this.stacks[index].push(val);
            if (this.stacks[index].length === this.capacity) {
                this.notFull.delete(index);
            }
        }
    }

    pop(): number {
        return this.popAtStack(this.stacks.length - 1);
    }

    popAtStack(index: number): number {
        if (index < 0 || index >= this.stacks.length || this.stacks[index].length === 0) {
            return -1;
        }
        const val = this.stacks[index].pop()!;
        if (index === this.stacks.length - 1 && this.stacks[index].length === 0) {
            while (this.stacks.length > 0 && this.stacks[this.stacks.length - 1].length === 0) {
                this.notFull.delete(this.stacks.length - 1);
                this.stacks.pop();
            }
        } else {
            this.notFull.add(index);
        }
        return val;
    }
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * var obj = new DinnerPlates(capacity)
 * obj.push(val)
 * var param_2 = obj.pop()
 * var param_3 = obj.popAtStack(index)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1173. 即时食物配送 I 🔒](https://leetcode.cn/problems/immediate-food-delivery-i){#1173}

{{< tabs "1173" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    ROUND(SUM(order_date = customer_pref_delivery_date) / COUNT(1) * 100, 2) AS immediate_percentage
FROM Delivery;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>配送表: <code>Delivery</code></p>

<pre>
+-----------------------------+---------+
| Column Name                 | Type    |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id 是表的主键(具有唯一值的列)。
该表保存着顾客的食物配送信息，顾客在某个日期下了订单，并指定了一个期望的配送日期（和下单日期相同或者在那之后）。
</pre>

<p>&nbsp;</p>

<p>如果顾客期望的配送日期和下单日期相同，则该订单称为 「即时订单」，否则称为「计划订单」。</p>

<p>编写解决方案统计即时订单所占的百分比，&nbsp;<strong>保留两位小数。</strong></p>

<p>返回结果如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Delivery 表:
+-------------+-------------+------------+-----------------------------+
| delivery_id | customer_id | order_date | customer_pref_delivery_date |
+-------------+-------------+------------+-----------------------------+
| 1           | 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 5           | 2019-08-02 | 2019-08-02                  |
| 3           | 1           | 2019-08-11 | 2019-08-11                  |
| 4           | 3           | 2019-08-24 | 2019-08-26                  |
| 5           | 4           | 2019-08-21 | 2019-08-22                  |
| 6           | 2           | 2019-08-11 | 2019-08-13                  |
+-------------+-------------+------------+-----------------------------+
<strong>输出：</strong>
+----------------------+
| immediate_percentage |
+----------------------+
| 33.33                |
+----------------------+
<strong>解释：</strong>2 和 3 号订单为即时订单，其他的为计划订单。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：求和

我们可以用 `sum` 函数来统计即时订单的数量，然后除以总订单数即可。由于题目求的是百分比，所以需要乘以 100，最后我们用 `round` 函数保留两位小数。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    ROUND(SUM(order_date = customer_pref_delivery_date) / COUNT(1) * 100, 2) AS immediate_percentage
FROM Delivery;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1174. 即时食物配送 II](https://leetcode.cn/problems/immediate-food-delivery-ii){#1174}

{{< tabs "1174" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY customer_id
                ORDER BY order_date
            ) AS rk
        FROM Delivery
    )
SELECT
    ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>配送表: <code>Delivery</code></p>

<pre>
+-----------------------------+---------+
| Column Name                 | Type    |
+-----------------------------+---------+
| delivery_id                 | int     |
| customer_id                 | int     |
| order_date                  | date    |
| customer_pref_delivery_date | date    |
+-----------------------------+---------+
delivery_id 是该表中具有唯一值的列。
该表保存着顾客的食物配送信息，顾客在某个日期下了订单，并指定了一个期望的配送日期（和下单日期相同或者在那之后）。
</pre>

<p>&nbsp;</p>

<p>如果顾客期望的配送日期和下单日期相同，则该订单称为 「<strong>即时订单</strong>」，否则称为「<strong>计划订单</strong>」。</p>

<p>「<strong>首次订单</strong>」是顾客最早创建的订单。我们保证一个顾客只会有一个「首次订单」。</p>

<p>编写解决方案以获取即时订单在所有用户的首次订单中的比例。<strong>保留两位小数。</strong></p>

<p>结果示例如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Delivery 表：
+-------------+-------------+------------+-----------------------------+
| delivery_id | customer_id | order_date | customer_pref_delivery_date |
+-------------+-------------+------------+-----------------------------+
| 1           | 1           | 2019-08-01 | 2019-08-02                  |
| 2           | 2           | 2019-08-02 | 2019-08-02                  |
| 3           | 1           | 2019-08-11 | 2019-08-12                  |
| 4           | 3           | 2019-08-24 | 2019-08-24                  |
| 5           | 3           | 2019-08-21 | 2019-08-22                  |
| 6           | 2           | 2019-08-11 | 2019-08-13                  |
| 7           | 4           | 2019-08-09 | 2019-08-09                  |
+-------------+-------------+------------+-----------------------------+
<strong>输出：</strong>
+----------------------+
| immediate_percentage |
+----------------------+
| 50.00                |
+----------------------+
<strong>解释：</strong>
1 号顾客的 1 号订单是首次订单，并且是计划订单。
2 号顾客的 2 号订单是首次订单，并且是即时订单。
3 号顾客的 5 号订单是首次订单，并且是计划订单。
4 号顾客的 7 号订单是首次订单，并且是即时订单。
因此，一半顾客的首次订单是即时的。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：子查询

我们可以使用子查询，先找到每个用户的首次订单，然后再计算即时订单的比例。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM Delivery
WHERE
    (customer_id, order_date) IN (
        SELECT customer_id, MIN(order_date)
        FROM Delivery
        GROUP BY 1
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们可以使用 `RANK()` 窗口函数，按照每个用户的订单日期升序排列，获取到每个用户的订单排名，然后我们筛选出排名为 $1$ 的订单，即为首次订单，再计算即时订单的比例。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY customer_id
                ORDER BY order_date
            ) AS rk
        FROM Delivery
    )
SELECT
    ROUND(AVG(order_date = customer_pref_delivery_date) * 100, 2) AS immediate_percentage
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1175. 质数排列](https://leetcode.cn/problems/prime-arrangements){#1175}

{{< tabs "1175" >}}

{{% tab "python" %}}
```python
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def count(n):
            cnt = 0
            primes = [True] * (n + 1)
            for i in range(2, n + 1):
                if primes[i]:
                    cnt += 1
                    for j in range(i + i, n + 1, i):
                        primes[j] = False
            return cnt

        cnt = count(n)
        ans = factorial(cnt) * factorial(n - cnt)
        return ans % (10**9 + 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numPrimeArrangements(int n) {
        int cnt = count(n);
        long ans = f(cnt) * f(n - cnt);
        return (int) (ans % MOD);
    }

    private long f(int n) {
        long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }

    private int count(int n) {
        int cnt = 0;
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                ++cnt;
                for (int j = i + i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numPrimeArrangements(int n) {
        int cnt = count(n);
        ll ans = f(cnt) * f(n - cnt);
        return (int) (ans % MOD);
    }

    ll f(int n) {
        ll ans = 1;
        for (int i = 2; i <= n; ++i) ans = (ans * i) % MOD;
        return ans;
    }

    int count(int n) {
        vector<bool> primes(n + 1, true);
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                ++cnt;
                for (int j = i + i; j <= n; j += i) primes[j] = false;
            }
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numPrimeArrangements(n int) int {
	count := func(n int) int {
		cnt := 0
		primes := make([]bool, n+1)
		for i := range primes {
			primes[i] = true
		}
		for i := 2; i <= n; i++ {
			if primes[i] {
				cnt++
				for j := i + i; j <= n; j += i {
					primes[j] = false
				}
			}
		}
		return cnt
	}

	mod := int(1e9) + 7
	f := func(n int) int {
		ans := 1
		for i := 2; i <= n; i++ {
			ans = (ans * i) % mod
		}
		return ans
	}

	cnt := count(n)
	ans := f(cnt) * f(n-cnt)
	return ans % mod
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你帮忙给从 <code>1</code> 到 <code>n</code>&nbsp;的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。</p>

<p>让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。</p>

<p>由于答案可能会很大，所以请你返回答案 <strong>模 mod&nbsp;<code>10^9 + 7</code></strong>&nbsp;之后的结果即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 5
<strong>输出：</strong>12
<strong>解释：</strong>举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1 的位置上。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 100
<strong>输出：</strong>682289015
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

先统计 $[1,n]$ 范围内的质数个数，我们记为 $cnt$。然后求 $cnt$ 以及 $n-cnt$ 阶乘的乘积得到答案，注意取模操作。

这里我们用“埃氏筛”统计质数。

如果 $x$ 是质数，那么大于 $x$ 的 $x$ 的倍数 $2x$,$3x$,… 一定不是质数，因此我们可以从这里入手。

设 $primes[i]$ 表示数 $i$ 是不是质数，如果是质数则为 $true$，否则为 $false$。

我们在 $[2,n]$ 范围内顺序遍历每个数 $i$，如果这个数为质数，质数个数增 $1$，然后将其所有的倍数 $j$ 都标记为合数（除了该质数本身），即 $primes[j]=false$，这样在运行结束的时候我们即能知道质数的个数。

时间复杂度 $O(n \times \log \log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def count(n):
            cnt = 0
            primes = [True] * (n + 1)
            for i in range(2, n + 1):
                if primes[i]:
                    cnt += 1
                    for j in range(i + i, n + 1, i):
                        primes[j] = False
            return cnt

        cnt = count(n)
        ans = factorial(cnt) * factorial(n - cnt)
        return ans % (10**9 + 7)
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int numPrimeArrangements(int n) {
        int cnt = count(n);
        long ans = f(cnt) * f(n - cnt);
        return (int) (ans % MOD);
    }

    private long f(int n) {
        long ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans = (ans * i) % MOD;
        }
        return ans;
    }

    private int count(int n) {
        int cnt = 0;
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                ++cnt;
                for (int j = i + i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numPrimeArrangements(int n) {
        int cnt = count(n);
        ll ans = f(cnt) * f(n - cnt);
        return (int) (ans % MOD);
    }

    ll f(int n) {
        ll ans = 1;
        for (int i = 2; i <= n; ++i) ans = (ans * i) % MOD;
        return ans;
    }

    int count(int n) {
        vector<bool> primes(n + 1, true);
        int cnt = 0;
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                ++cnt;
                for (int j = i + i; j <= n; j += i) primes[j] = false;
            }
        }
        return cnt;
    }
};
```

#### Go

```go
func numPrimeArrangements(n int) int {
	count := func(n int) int {
		cnt := 0
		primes := make([]bool, n+1)
		for i := range primes {
			primes[i] = true
		}
		for i := 2; i <= n; i++ {
			if primes[i] {
				cnt++
				for j := i + i; j <= n; j += i {
					primes[j] = false
				}
			}
		}
		return cnt
	}

	mod := int(1e9) + 7
	f := func(n int) int {
		ans := 1
		for i := 2; i <= n; i++ {
			ans = (ans * i) % mod
		}
		return ans
	}

	cnt := count(n)
	ans := f(cnt) * f(n-cnt)
	return ans % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1176. 健身计划评估 🔒](https://leetcode.cn/problems/diet-plan-performance){#1176}

{{< tabs "1176" >}}

{{% tab "python" %}}
```python
class Solution:
    def dietPlanPerformance(
        self, calories: List[int], k: int, lower: int, upper: int
    ) -> int:
        def check(s):
            if s < lower:
                return -1
            if s > upper:
                return 1
            return 0

        s, n = sum(calories[:k]), len(calories)
        ans = check(s)
        for i in range(k, n):
            s += calories[i] - calories[i - k]
            ans += check(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int s = 0, n = calories.length;
        for (int i = 0; i < k; ++i) {
            s += calories[i];
        }
        int ans = 0;
        if (s < lower) {
            --ans;
        } else if (s > upper) {
            ++ans;
        }
        for (int i = k; i < n; ++i) {
            s += calories[i] - calories[i - k];
            if (s < lower) {
                --ans;
            } else if (s > upper) {
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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int s = accumulate(calories.begin(), calories.begin() + k, 0);
        int ans = 0;
        if (s < lower) {
            --ans;
        } else if (s > upper) {
            ++ans;
        }
        for (int i = k; i < n; ++i) {
            s += calories[i] - calories[i - k];
            if (s < lower) {
                --ans;
            } else if (s > upper) {
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
func dietPlanPerformance(calories []int, k int, lower int, upper int) (ans int) {
	n := len(calories)
	s := 0
	for _, x := range calories[:k] {
		s += x
	}
	if s < lower {
		ans--
	} else if s > upper {
		ans++
	}
	for i := k; i < n; i++ {
		s += calories[i] - calories[i-k]
		if s < lower {
			ans--
		} else if s > upper {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function dietPlanPerformance(calories: number[], k: number, lower: number, upper: number): number {
    const n = calories.length;
    let s = calories.slice(0, k).reduce((a, b) => a + b);
    let ans = 0;
    if (s < lower) {
        --ans;
    } else if (s > upper) {
        ++ans;
    }
    for (let i = k; i < n; ++i) {
        s += calories[i] - calories[i - k];
        if (s < lower) {
            --ans;
        } else if (s > upper) {
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

<p>你的好友是一位健身爱好者。前段日子，他给自己制定了一份健身计划。现在想请你帮他评估一下这份计划是否合理。</p>

<p>他会有一份计划消耗的卡路里表，其中&nbsp;<code>calories[i]</code>&nbsp;给出了你的这位好友在第&nbsp;<code>i</code>&nbsp;天需要消耗的卡路里总量。</p>

<p>为了更好地评估这份计划，对于卡路里表中的每一天，你都需要计算他 「这一天以及之后的连续几天」 （共&nbsp;<code>k</code> 天）内消耗的总卡路里 <em>T：</em></p>

<ul>
	<li>如果&nbsp;<code>T &lt; lower</code>，那么这份计划相对糟糕，并失去 1 分；&nbsp;</li>
	<li>如果 <code>T &gt; upper</code>，那么这份计划相对优秀，并获得 1 分；</li>
	<li>否则，这份计划普普通通，分值不做变动。</li>
</ul>

<p>请返回统计完所有&nbsp;<code>calories.length</code>&nbsp;天后得到的总分作为评估结果。</p>

<p>注意：总分可能是负数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>calories = [1,2,3,4,5], k = 1, lower = 3, upper = 3
<strong>输出：</strong>0
<strong>解释：</strong>calories[0], calories[1] &lt; lower 而 calories[3], calories[4] &gt; upper, 总分 = 0.</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>calories = [3,2], k = 2, lower = 0, upper = 1
<strong>输出：</strong>1
<strong>解释：</strong>calories[0] + calories[1] &gt; upper, 总分 = 1.
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>calories = [6,5,0,0], k = 2, lower = 1, upper = 5
<strong>输出：</strong>0
<strong>解释：</strong>calories[0] + calories[1] &gt; upper, calories[2] + calories[3] &lt; lower, 总分 = 0.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= calories.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= calories[i] &lt;= 20000</code></li>
	<li><code>0 &lt;= lower &lt;= upper</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们先预处理出长度为 $n+1$ 的前缀和数组 $s$，其中 $s[i]$ 表示前 $i$ 天的卡路里总和。

然后遍历前缀和数组 $s$，对于每个位置 $i$，计算 $s[i+k]-s[i]$，即为第 $i$ 天开始的连续 $k$ 天的卡路里总和。根据题意，对于每个 $s[i+k]-s[i]$，判断值与 $lower$ 和 $upper$ 的关系，更新答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `calories` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dietPlanPerformance(
        self, calories: List[int], k: int, lower: int, upper: int
    ) -> int:
        s = list(accumulate(calories, initial=0))
        ans, n = 0, len(calories)
        for i in range(n - k + 1):
            t = s[i + k] - s[i]
            if t < lower:
                ans -= 1
            elif t > upper:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int n = calories.length;
        int[] s = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + calories[i];
        }
        int ans = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            int t = s[i + k] - s[i];
            if (t < lower) {
                --ans;
            } else if (t > upper) {
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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + calories[i];
        }
        int ans = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            int t = s[i + k] - s[i];
            if (t < lower) {
                --ans;
            } else if (t > upper) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func dietPlanPerformance(calories []int, k int, lower int, upper int) (ans int) {
	n := len(calories)
	s := make([]int, n+1)
	for i, x := range calories {
		s[i+1] = s[i] + x
	}
	for i := 0; i < n-k+1; i++ {
		t := s[i+k] - s[i]
		if t < lower {
			ans--
		} else if t > upper {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function dietPlanPerformance(calories: number[], k: number, lower: number, upper: number): number {
    const n = calories.length;
    const s: number[] = new Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + calories[i];
    }
    let ans = 0;
    for (let i = 0; i < n - k + 1; ++i) {
        const t = s[i + k] - s[i];
        if (t < lower) {
            --ans;
        } else if (t > upper) {
            ++ans;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：滑动窗口

我们维护一个长度为 $k$ 的滑动窗口，窗口内元素之和记为 $s$。如果 $s \lt lower$，则分数减 $1$；如果 $ s \gt upper$，则分数加 $1$。

时间复杂度 $O(n)$，其中 $n$ 为数组 `calories` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dietPlanPerformance(
        self, calories: List[int], k: int, lower: int, upper: int
    ) -> int:
        def check(s):
            if s < lower:
                return -1
            if s > upper:
                return 1
            return 0

        s, n = sum(calories[:k]), len(calories)
        ans = check(s)
        for i in range(k, n):
            s += calories[i] - calories[i - k]
            ans += check(s)
        return ans
```

#### Java

```java
class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int s = 0, n = calories.length;
        for (int i = 0; i < k; ++i) {
            s += calories[i];
        }
        int ans = 0;
        if (s < lower) {
            --ans;
        } else if (s > upper) {
            ++ans;
        }
        for (int i = k; i < n; ++i) {
            s += calories[i] - calories[i - k];
            if (s < lower) {
                --ans;
            } else if (s > upper) {
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
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int s = accumulate(calories.begin(), calories.begin() + k, 0);
        int ans = 0;
        if (s < lower) {
            --ans;
        } else if (s > upper) {
            ++ans;
        }
        for (int i = k; i < n; ++i) {
            s += calories[i] - calories[i - k];
            if (s < lower) {
                --ans;
            } else if (s > upper) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func dietPlanPerformance(calories []int, k int, lower int, upper int) (ans int) {
	n := len(calories)
	s := 0
	for _, x := range calories[:k] {
		s += x
	}
	if s < lower {
		ans--
	} else if s > upper {
		ans++
	}
	for i := k; i < n; i++ {
		s += calories[i] - calories[i-k]
		if s < lower {
			ans--
		} else if s > upper {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function dietPlanPerformance(calories: number[], k: number, lower: number, upper: number): number {
    const n = calories.length;
    let s = calories.slice(0, k).reduce((a, b) => a + b);
    let ans = 0;
    if (s < lower) {
        --ans;
    } else if (s > upper) {
        ++ans;
    }
    for (let i = k; i < n; ++i) {
        s += calories[i] - calories[i - k];
        if (s < lower) {
            --ans;
        } else if (s > upper) {
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

# [1177. 构建回文串检测](https://leetcode.cn/problems/can-make-palindrome-from-substring){#1177}

{{< tabs "1177" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        n = len(s)
        ss = [[0] * 26 for _ in range(n + 1)]
        for i, c in enumerate(s, 1):
            ss[i] = ss[i - 1][:]
            ss[i][ord(c) - ord("a")] += 1
        ans = []
        for l, r, k in queries:
            cnt = sum((ss[r + 1][j] - ss[l][j]) & 1 for j in range(26))
            ans.append(cnt // 2 <= k)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int n = s.length();
        int[][] ss = new int[n + 1][26];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ss[i][j] = ss[i - 1][j];
            }
            ss[i][s.charAt(i - 1) - 'a']++;
        }
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int x = 0;
            for (int j = 0; j < 26; ++j) {
                x += (ss[r + 1][j] - ss[l][j]) & 1;
            }
            ans.add(x / 2 <= k);
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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ss[n + 1][26];
        memset(ss, 0, sizeof(ss));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ss[i][j] = ss[i - 1][j];
            }
            ss[i][s[i - 1] - 'a']++;
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int x = 0;
            for (int j = 0; j < 26; ++j) {
                x += (ss[r + 1][j] - ss[l][j]) & 1;
            }
            ans.emplace_back(x / 2 <= k);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canMakePaliQueries(s string, queries [][]int) (ans []bool) {
	n := len(s)
	ss := make([][26]int, n+1)
	for i := 1; i <= n; i++ {
		for j := 0; j < 26; j++ {
			ss[i][j] = ss[i-1][j]
		}
		ss[i][s[i-1]-'a']++
	}
	for _, q := range queries {
		l, r, k := q[0], q[1], q[2]
		x := 0
		for j := 0; j < 26; j++ {
			x += (ss[r+1][j] - ss[l][j]) & 1
		}
		ans = append(ans, x/2 <= k)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canMakePaliQueries(s: string, queries: number[][]): boolean[] {
    const n = s.length;
    const ss: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(26).fill(0));
    for (let i = 1; i <= n; ++i) {
        ss[i] = ss[i - 1].slice();
        ++ss[i][s.charCodeAt(i - 1) - 97];
    }
    const ans: boolean[] = [];
    for (const [l, r, k] of queries) {
        let x = 0;
        for (let j = 0; j < 26; ++j) {
            x += (ss[r + 1][j] - ss[l][j]) & 1;
        }
        ans.push(x >> 1 <= k);
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

<p>给你一个字符串&nbsp;<code>s</code>，请你对&nbsp;<code>s</code>&nbsp;的子串进行检测。</p>

<p>每次检测，待检子串都可以表示为&nbsp;<code>queries[i] = [left, right, k]</code>。我们可以 <strong>重新排列</strong> 子串&nbsp;<code>s[left], ..., s[right]</code>，并从中选择 <strong>最多</strong> <code>k</code>&nbsp;项替换成任何小写英文字母。&nbsp;</p>

<p>如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为&nbsp;<code>true</code>，否则结果为&nbsp;<code>false</code>。</p>

<p>返回答案数组&nbsp;<code>answer[]</code>，其中&nbsp;<code>answer[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个待检子串&nbsp;<code>queries[i]</code>&nbsp;的检测结果。</p>

<p>注意：在替换时，子串中的每个字母都必须作为 <strong>独立的</strong> 项进行计数，也就是说，如果&nbsp;<code>s[left..right] = &quot;aaa&quot;</code>&nbsp;且&nbsp;<code>k = 2</code>，我们只能替换其中的两个字母。（另外，任何检测都不会修改原始字符串 <code>s</code>，可以认为每次检测都是独立的）</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>s = &quot;abcda&quot;, queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
<strong>输出：</strong>[true,false,false,true,true]
<strong>解释：</strong>
queries[0] : 子串 = &quot;d&quot;，回文。
queries[1] :&nbsp;子串 = &quot;bc&quot;，不是回文。
queries[2] :&nbsp;子串 = &quot;abcd&quot;，只替换 1 个字符是变不成回文串的。
queries[3] :&nbsp;子串 = &quot;abcd&quot;，可以变成回文的 &quot;abba&quot;。 也可以变成 &quot;baab&quot;，先重新排序变成 &quot;bacd&quot;，然后把 &quot;cd&quot; 替换为 &quot;ab&quot;。
queries[4] :&nbsp;子串 = &quot;abcda&quot;，可以变成回文的 &quot;abcba&quot;。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length,&nbsp;queries.length&nbsp;&lt;= 10^5</code></li>
	<li><code>0 &lt;= queries[i][0] &lt;= queries[i][1] &lt;&nbsp;s.length</code></li>
	<li><code>0 &lt;= queries[i][2] &lt;= s.length</code></li>
	<li><code>s</code> 中只有小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们先考虑一个子串能否在经过最多 $k$ 次替换后变成回文串，显然，我们需要统计子串中每个字符出现的次数，这可以通过前缀和来实现。对于出现偶数次的字符，我们不需要进行替换，对于出现奇数次的字符，我们需要进行替换，替换的次数为 $\lfloor \frac{x}{2} \rfloor$，其中 $x$ 为出现奇数次的字符的个数。如果 $\lfloor \frac{x}{2} \rfloor \leq k$，那么这个子串就可以变成回文串。

因此，我们定义一个前缀和数组 $ss$，其中 $ss[i][j]$ 表示字符串 $s$ 的前 $i$ 个字符中，字符 $j$ 出现的次数。那么对于一个子串 $s[l..r]$，我们可以通过 $ss[r + 1][j] - ss[l][j]$ 得到子串中字符 $j$ 出现的次数。我们遍历所有的查询，对于每个查询 $[l, r, k]$，我们统计子串 $s[l..r]$ 中出现奇数次的字符的个数 $x$，如果 $\lfloor \frac{x}{2} \rfloor \leq k$，那么这个子串就可以变成回文串。

时间复杂度 $O((n + m) \times C)$，空间复杂度 $O(n \times C)$，其中 $n$ 和 $m$ 分别为字符串 $s$ 和查询数组的长度；而 $C$ 为字符集的大小，本题中字符集为小写英文字母，因此 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        n = len(s)
        ss = [[0] * 26 for _ in range(n + 1)]
        for i, c in enumerate(s, 1):
            ss[i] = ss[i - 1][:]
            ss[i][ord(c) - ord("a")] += 1
        ans = []
        for l, r, k in queries:
            cnt = sum((ss[r + 1][j] - ss[l][j]) & 1 for j in range(26))
            ans.append(cnt // 2 <= k)
        return ans
```

#### Java

```java
class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int n = s.length();
        int[][] ss = new int[n + 1][26];
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ss[i][j] = ss[i - 1][j];
            }
            ss[i][s.charAt(i - 1) - 'a']++;
        }
        List<Boolean> ans = new ArrayList<>();
        for (var q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int x = 0;
            for (int j = 0; j < 26; ++j) {
                x += (ss[r + 1][j] - ss[l][j]) & 1;
            }
            ans.add(x / 2 <= k);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ss[n + 1][26];
        memset(ss, 0, sizeof(ss));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                ss[i][j] = ss[i - 1][j];
            }
            ss[i][s[i - 1] - 'a']++;
        }
        vector<bool> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int x = 0;
            for (int j = 0; j < 26; ++j) {
                x += (ss[r + 1][j] - ss[l][j]) & 1;
            }
            ans.emplace_back(x / 2 <= k);
        }
        return ans;
    }
};
```

#### Go

```go
func canMakePaliQueries(s string, queries [][]int) (ans []bool) {
	n := len(s)
	ss := make([][26]int, n+1)
	for i := 1; i <= n; i++ {
		for j := 0; j < 26; j++ {
			ss[i][j] = ss[i-1][j]
		}
		ss[i][s[i-1]-'a']++
	}
	for _, q := range queries {
		l, r, k := q[0], q[1], q[2]
		x := 0
		for j := 0; j < 26; j++ {
			x += (ss[r+1][j] - ss[l][j]) & 1
		}
		ans = append(ans, x/2 <= k)
	}
	return
}
```

#### TypeScript

```ts
function canMakePaliQueries(s: string, queries: number[][]): boolean[] {
    const n = s.length;
    const ss: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(26).fill(0));
    for (let i = 1; i <= n; ++i) {
        ss[i] = ss[i - 1].slice();
        ++ss[i][s.charCodeAt(i - 1) - 97];
    }
    const ans: boolean[] = [];
    for (const [l, r, k] of queries) {
        let x = 0;
        for (let j = 0; j < 26; ++j) {
            x += (ss[r + 1][j] - ss[l][j]) & 1;
        }
        ans.push(x >> 1 <= k);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1178. 猜字谜](https://leetcode.cn/problems/number-of-valid-words-for-each-puzzle){#1178}

{{< tabs "1178" >}}

{{% tab "python" %}}
```python
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        cnt = Counter()
        for w in words:
            mask = 0
            for c in w:
                mask |= 1 << (ord(c) - ord("a"))
            cnt[mask] += 1

        ans = []
        for p in puzzles:
            mask = 0
            for c in p:
                mask |= 1 << (ord(c) - ord("a"))
            x, i, j = 0, ord(p[0]) - ord("a"), mask
            while j:
                if j >> i & 1:
                    x += cnt[j]
                j = (j - 1) & mask
            ans.append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> cnt = new HashMap<>(words.length);
        for (var w : words) {
            int mask = 0;
            for (int i = 0; i < w.length(); ++i) {
                mask |= 1 << (w.charAt(i) - 'a');
            }
            cnt.merge(mask, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        for (var p : puzzles) {
            int mask = 0;
            for (int i = 0; i < p.length(); ++i) {
                mask |= 1 << (p.charAt(i) - 'a');
            }
            int x = 0;
            int i = p.charAt(0) - 'a';
            for (int j = mask; j > 0; j = (j - 1) & mask) {
                if ((j >> i & 1) == 1) {
                    x += cnt.getOrDefault(j, 0);
                }
            }
            ans.add(x);
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
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> cnt;
        for (auto& w : words) {
            int mask = 0;
            for (char& c : w) {
                mask |= 1 << (c - 'a');
            }
            cnt[mask]++;
        }
        vector<int> ans;
        for (auto& p : puzzles) {
            int mask = 0;
            for (char& c : p) {
                mask |= 1 << (c - 'a');
            }
            int x = 0;
            int i = p[0] - 'a';
            for (int j = mask; j; j = (j - 1) & mask) {
                if (j >> i & 1) {
                    x += cnt[j];
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findNumOfValidWords(words []string, puzzles []string) (ans []int) {
	cnt := map[int]int{}
	for _, w := range words {
		mask := 0
		for _, c := range w {
			mask |= 1 << (c - 'a')
		}
		cnt[mask]++
	}
	for _, p := range puzzles {
		mask := 0
		for _, c := range p {
			mask |= 1 << (c - 'a')
		}
		x, i := 0, p[0]-'a'
		for j := mask; j > 0; j = (j - 1) & mask {
			if j>>i&1 > 0 {
				x += cnt[j]
			}
		}
		ans = append(ans, x)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findNumOfValidWords(words: string[], puzzles: string[]): number[] {
    const cnt: Map<number, number> = new Map();
    for (const w of words) {
        let mask = 0;
        for (const c of w) {
            mask |= 1 << (c.charCodeAt(0) - 97);
        }
        cnt.set(mask, (cnt.get(mask) || 0) + 1);
    }
    const ans: number[] = [];
    for (const p of puzzles) {
        let mask = 0;
        for (const c of p) {
            mask |= 1 << (c.charCodeAt(0) - 97);
        }
        let x = 0;
        const i = p.charCodeAt(0) - 97;
        for (let j = mask; j; j = (j - 1) & mask) {
            if ((j >> i) & 1) {
                x += cnt.get(j) || 0;
            }
        }
        ans.push(x);
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

<p>外国友人仿照中国字谜设计了一个英文版猜字谜小游戏，请你来猜猜看吧。</p>

<p>字谜的迷面 <code>puzzle</code> 按字符串形式给出，如果一个单词 <code>word</code> 符合下面两个条件，那么它就可以算作谜底：</p>

<ul>
	<li>单词 <code>word</code> 中包含谜面 <code>puzzle</code> 的第一个字母。</li>
	<li>单词 <code>word</code> 中的每一个字母都可以在谜面 <code>puzzle</code> 中找到。<br />
	例如，如果字谜的谜面是 "abcdefg"，那么可以作为谜底的单词有 "faced", "cabbage", 和 "baggage"；而 "beefed"（不含字母 "a"）以及 "based"（其中的 "s" 没有出现在谜面中）都不能作为谜底。</li>
</ul>

<p>返回一个答案数组 <code>answer</code>，数组中的每个元素 <code>answer[i]</code> 是在给出的单词列表 <code>words</code> 中可以作为字谜迷面 <code>puzzles[i]</code> 所对应的谜底的单词数目。</p>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
<strong>输出：</strong>[1,1,3,2,4,0]
<strong>解释：</strong>
1 个单词可以作为 "aboveyz" 的谜底 : "aaaa" 
1 个单词可以作为 "abrodyz" 的谜底 : "aaaa"
3 个单词可以作为 "abslute" 的谜底 : "aaaa", "asas", "able"
2 个单词可以作为 "absoryz" 的谜底 : "aaaa", "asas"
4 个单词可以作为 "actresz" 的谜底 : "aaaa", "asas", "actt", "access"
没有单词可以作为 "gaswxyz" 的谜底，因为列表中的单词都不含字母 'g'。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= words.length <= 10^5</code></li>
	<li><code>4 <= words[i].length <= 50</code></li>
	<li><code>1 <= puzzles.length <= 10^4</code></li>
	<li><code>puzzles[i].length == 7</code></li>
	<li><code>words[i][j]</code>, <code>puzzles[i][j]</code> 都是小写英文字母。</li>
	<li>每个 <code>puzzles[i]</code> 所包含的字符都不重复。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 哈希表 + 子集枚举

根据题目描述，对于字谜数组 $puzzles$ 中的每一个字谜 $p$，我们需要统计有多少个单词 $w$ 包含了字谜 $p$ 的第一个字母，且 $w$ 的每一个字母都可以在 $p$ 中找到。

由于每个单词重复的字母只需要统计一次，因此，我们可以使用二进制状态压缩的方法，将每个单词 $w$ 转换成一个二进制数 $mask$，其中 $mask$ 的第 $i$ 位为 $1$，当且仅当字母 $i$ 在单词 $w$ 中出现过。我们用哈希表 $cnt$ 统计所有单词的状态压缩后的值出现的次数。

接下来，遍历字谜数组 $puzzles$，对于每一个字谜 $p$，我们注意到其长度固定为 $7$，因此我们只需要枚举 $p$ 的子集，如果该子集包含 $p$ 的第一个字母，那么我们查找其在哈希表中对应的值并累加到当前字谜的答案中。

遍历结束后，我们就可以得到字谜数组 $puzzles$ 中每个字谜对应的谜底数量，将其返回即可。

时间复杂度 $O(m \times |w| + n \times 2^{|p|})$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别为数组 $words$ 和 $puzzles$ 的长度，而 $|w|$ 和 $|p|$ 分别为数组 $words$ 中单词的最大长度和数组 $puzzles$ 中字谜的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        cnt = Counter()
        for w in words:
            mask = 0
            for c in w:
                mask |= 1 << (ord(c) - ord("a"))
            cnt[mask] += 1

        ans = []
        for p in puzzles:
            mask = 0
            for c in p:
                mask |= 1 << (ord(c) - ord("a"))
            x, i, j = 0, ord(p[0]) - ord("a"), mask
            while j:
                if j >> i & 1:
                    x += cnt[j]
                j = (j - 1) & mask
            ans.append(x)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> cnt = new HashMap<>(words.length);
        for (var w : words) {
            int mask = 0;
            for (int i = 0; i < w.length(); ++i) {
                mask |= 1 << (w.charAt(i) - 'a');
            }
            cnt.merge(mask, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        for (var p : puzzles) {
            int mask = 0;
            for (int i = 0; i < p.length(); ++i) {
                mask |= 1 << (p.charAt(i) - 'a');
            }
            int x = 0;
            int i = p.charAt(0) - 'a';
            for (int j = mask; j > 0; j = (j - 1) & mask) {
                if ((j >> i & 1) == 1) {
                    x += cnt.getOrDefault(j, 0);
                }
            }
            ans.add(x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> cnt;
        for (auto& w : words) {
            int mask = 0;
            for (char& c : w) {
                mask |= 1 << (c - 'a');
            }
            cnt[mask]++;
        }
        vector<int> ans;
        for (auto& p : puzzles) {
            int mask = 0;
            for (char& c : p) {
                mask |= 1 << (c - 'a');
            }
            int x = 0;
            int i = p[0] - 'a';
            for (int j = mask; j; j = (j - 1) & mask) {
                if (j >> i & 1) {
                    x += cnt[j];
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};
```

#### Go

```go
func findNumOfValidWords(words []string, puzzles []string) (ans []int) {
	cnt := map[int]int{}
	for _, w := range words {
		mask := 0
		for _, c := range w {
			mask |= 1 << (c - 'a')
		}
		cnt[mask]++
	}
	for _, p := range puzzles {
		mask := 0
		for _, c := range p {
			mask |= 1 << (c - 'a')
		}
		x, i := 0, p[0]-'a'
		for j := mask; j > 0; j = (j - 1) & mask {
			if j>>i&1 > 0 {
				x += cnt[j]
			}
		}
		ans = append(ans, x)
	}
	return
}
```

#### TypeScript

```ts
function findNumOfValidWords(words: string[], puzzles: string[]): number[] {
    const cnt: Map<number, number> = new Map();
    for (const w of words) {
        let mask = 0;
        for (const c of w) {
            mask |= 1 << (c.charCodeAt(0) - 97);
        }
        cnt.set(mask, (cnt.get(mask) || 0) + 1);
    }
    const ans: number[] = [];
    for (const p of puzzles) {
        let mask = 0;
        for (const c of p) {
            mask |= 1 << (c.charCodeAt(0) - 97);
        }
        let x = 0;
        const i = p.charCodeAt(0) - 97;
        for (let j = mask; j; j = (j - 1) & mask) {
            if ((j >> i) & 1) {
                x += cnt.get(j) || 0;
            }
        }
        ans.push(x);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1179. 重新格式化部门表](https://leetcode.cn/problems/reformat-department-table){#1179}

{{< tabs "1179" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    id,
    SUM(
        CASE month
            WHEN 'Jan' THEN revenue
        END
    ) AS Jan_Revenue,
    SUM(
        CASE month
            WHEN 'Feb' THEN revenue
        END
    ) AS Feb_Revenue,
    SUM(
        CASE month
            WHEN 'Mar' THEN revenue
        END
    ) AS Mar_Revenue,
    SUM(
        CASE month
            WHEN 'Apr' THEN revenue
        END
    ) AS Apr_Revenue,
    SUM(
        CASE month
            WHEN 'May' THEN revenue
        END
    ) AS May_Revenue,
    SUM(
        CASE month
            WHEN 'Jun' THEN revenue
        END
    ) AS Jun_Revenue,
    SUM(
        CASE month
            WHEN 'Jul' THEN revenue
        END
    ) AS Jul_Revenue,
    SUM(
        CASE month
            WHEN 'Aug' THEN revenue
        END
    ) AS Aug_Revenue,
    SUM(
        CASE month
            WHEN 'Sep' THEN revenue
        END
    ) AS Sep_Revenue,
    SUM(
        CASE month
            WHEN 'Oct' THEN revenue
        END
    ) AS Oct_Revenue,
    SUM(
        CASE month
            WHEN 'Nov' THEN revenue
        END
    ) AS Nov_Revenue,
    SUM(
        CASE month
            WHEN 'Dec' THEN revenue
        END
    ) AS Dec_Revenue
FROM Department
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表&nbsp;<code>Department</code>：</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| revenue       | int     |
| month         | varchar |
+---------------+---------+
在 SQL 中，(id, month) 是表的联合主键。
这个表格有关于每个部门每月收入的信息。
月份（month）可以取下列值 ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"]。
</pre>

<p>&nbsp;</p>

<p>重新格式化表格，使得&nbsp;<strong>每个月&nbsp;</strong>都有一个部门 id 列和一个收入列。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如以下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Department table:
+------+---------+-------+
| id   | revenue | month |
+------+---------+-------+
| 1    | 8000    | Jan   |
| 2    | 9000    | Jan   |
| 3    | 10000   | Feb   |
| 1    | 7000    | Feb   |
| 1    | 6000    | Mar   |
+------+---------+-------+
<b>输出：</b>
+------+-------------+-------------+-------------+-----+-------------+
| id   | Jan_Revenue | Feb_Revenue | Mar_Revenue | ... | Dec_Revenue |
+------+-------------+-------------+-------------+-----+-------------+
| 1    | 8000        | 7000        | 6000        | ... | null        |
| 2    | 9000        | null        | null        | ... | null        |
| 3    | null        | 10000       | null        | ... | null        |
+------+-------------+-------------+-------------+-----+-------------+
<b>解释：</b>四月到十二月的收入为空。 
请注意，结果表共有 13 列（1 列用于部门 ID，其余 12 列用于各个月份）。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    id,
    SUM(
        CASE month
            WHEN 'Jan' THEN revenue
        END
    ) AS Jan_Revenue,
    SUM(
        CASE month
            WHEN 'Feb' THEN revenue
        END
    ) AS Feb_Revenue,
    SUM(
        CASE month
            WHEN 'Mar' THEN revenue
        END
    ) AS Mar_Revenue,
    SUM(
        CASE month
            WHEN 'Apr' THEN revenue
        END
    ) AS Apr_Revenue,
    SUM(
        CASE month
            WHEN 'May' THEN revenue
        END
    ) AS May_Revenue,
    SUM(
        CASE month
            WHEN 'Jun' THEN revenue
        END
    ) AS Jun_Revenue,
    SUM(
        CASE month
            WHEN 'Jul' THEN revenue
        END
    ) AS Jul_Revenue,
    SUM(
        CASE month
            WHEN 'Aug' THEN revenue
        END
    ) AS Aug_Revenue,
    SUM(
        CASE month
            WHEN 'Sep' THEN revenue
        END
    ) AS Sep_Revenue,
    SUM(
        CASE month
            WHEN 'Oct' THEN revenue
        END
    ) AS Oct_Revenue,
    SUM(
        CASE month
            WHEN 'Nov' THEN revenue
        END
    ) AS Nov_Revenue,
    SUM(
        CASE month
            WHEN 'Dec' THEN revenue
        END
    ) AS Dec_Revenue
FROM Department
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
