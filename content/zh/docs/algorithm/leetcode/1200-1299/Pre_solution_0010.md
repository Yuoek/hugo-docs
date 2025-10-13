---
title: "1290_二进制链表转整数"
date: 2025-10-08T18:37:06+08:00
weight: 10
tags: [二分查找, 前缀和, 哈希表, 图, 字符串, 广度优先搜索, 排序, 数学, 数据库, 数组, 枚举, 滑动窗口, 矩阵, 贪心, 链表]
---

{{< markmap >}}
### [1290_二进制链表转整数](#1290)
#### [链表](#1290)
#### [数学](#1290)
### [1291_顺次数](#1291)
#### [枚举](#1291)
### [1292_元素和小于等于阈值的正方形的最大边长](#1292)
#### [数组](#1292)
#### [二分查找](#1292)
#### [矩阵](#1292)
#### [前缀和](#1292)
### [1293_网格中的最短路径](#1293)
#### [广度优先搜索](#1293)
#### [数组](#1293)
#### [矩阵](#1293)
### [1294_不同国家的天气类型 🔒](#1294)
#### [数据库](#1294)
### [1295_统计位数为偶数的数字](#1295)
#### [数组](#1295)
#### [数学](#1295)
### [1296_划分数组为连续数字的集合](#1296)
#### [贪心](#1296)
#### [数组](#1296)
#### [哈希表](#1296)
#### [排序](#1296)
### [1297_子串的最大出现次数](#1297)
#### [哈希表](#1297)
#### [字符串](#1297)
#### [滑动窗口](#1297)
### [1298_你能从盒子里获得的最大糖果数](#1298)
#### [广度优先搜索](#1298)
#### [图](#1298)
#### [数组](#1298)
### [1299_将每个元素替换为右侧最大元素](#1299)
#### [数组](#1299)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1290_二进制链表转整数
___
#### 链表
___
#### 数学
---
### 1291_顺次数
___
#### 枚举
---
### 1292_元素和小于等于阈值的正方形的最大边长
___
#### 数组
___
#### 二分查找
___
#### 矩阵
___
#### 前缀和
---
### 1293_网格中的最短路径
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 1294_不同国家的天气类型 🔒
___
#### 数据库
---
### 1295_统计位数为偶数的数字
___
#### 数组
___
#### 数学
---
### 1296_划分数组为连续数字的集合
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 1297_子串的最大出现次数
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 1298_你能从盒子里获得的最大糖果数
___
#### 广度优先搜索
___
#### 图
___
#### 数组
---
### 1299_将每个元素替换为右侧最大元素
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 哈希表 |
| 图 | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数据库 |
| 数组 | 枚举 | 滑动窗口 |
| 矩阵 | 贪心 | 链表 |

# [1290. 二进制链表转整数](https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer){#1290}

{{< tabs "1290" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = 0
        while head:
            ans = ans << 1 | head.val
            head = head.next
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
    public int getDecimalValue(ListNode head) {
        int ans = 0;
        for (; head != null; head = head.next) {
            ans = ans << 1 | head.val;
        }
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        for (; head; head = head->next) {
            ans = ans << 1 | head->val;
        }
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
func getDecimalValue(head *ListNode) (ans int) {
	for ; head != nil; head = head.Next {
		ans = ans<<1 | head.Val
	}
	return
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

function getDecimalValue(head: ListNode | null): number {
    let ans = 0;
    for (; head; head = head.next) {
        ans = (ans << 1) | head.val;
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
    pub fn get_decimal_value(mut head: Option<Box<ListNode>>) -> i32 {
        let mut ans = 0;
        while let Some(node) = head {
            ans = (ans << 1) | node.val;
            head = node.next;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var getDecimalValue = function (head) {
    let ans = 0;
    for (; head; head = head.next) {
        ans = (ans << 1) | head.val;
    }
    return ans;
};
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
    public int GetDecimalValue(ListNode head) {
        int ans = 0;
        for (; head != null; head = head.next) {
            ans = ans << 1 | head.val;
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @return Integer
     */
    function getDecimalValue($head) {
        $ans = 0;
        while ($head !== null) {
            $ans = ($ans << 1) | $head->val;
            $head = $head->next;
        }
        return $ans;
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

int getDecimalValue(struct ListNode* head) {
    int ans = 0;
    struct ListNode* cur = head;
    while (cur) {
        ans = (ans << 1) | cur->val;
        cur = cur->next;
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

<p>给你一个单链表的引用结点&nbsp;<code>head</code>。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。</p>

<p>请你返回该链表所表示数字的 <strong>十进制值</strong> 。</p>

<p><strong>最高位</strong> 在链表的头部。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1290.Convert%20Binary%20Number%20in%20a%20Linked%20List%20to%20Integer/images/graph-1.png" style="height: 108px; width: 426px;" /></p>

<pre>
<strong>输入：</strong>head = [1,0,1]
<strong>输出：</strong>5
<strong>解释：</strong>二进制数 (101) 转化为十进制数 (5)
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [0]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表不为空。</li>
	<li>链表的结点总数不超过&nbsp;<code>30</code>。</li>
	<li>每个结点的值不是&nbsp;<code>0</code> 就是 <code>1</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历链表

我们用变量 $\textit{ans}$ 记录当前的十进制值，初始值为 $0$。

遍历链表，对于每个结点，将 $\textit{ans}$ 左移一位，然后再或上当前结点的值。遍历结束后，$\textit{ans}$ 即为十进制值。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        ans = 0
        while head:
            ans = ans << 1 | head.val
            head = head.next
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
    public int getDecimalValue(ListNode head) {
        int ans = 0;
        for (; head != null; head = head.next) {
            ans = ans << 1 | head.val;
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        for (; head; head = head->next) {
            ans = ans << 1 | head->val;
        }
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
func getDecimalValue(head *ListNode) (ans int) {
	for ; head != nil; head = head.Next {
		ans = ans<<1 | head.Val
	}
	return
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

function getDecimalValue(head: ListNode | null): number {
    let ans = 0;
    for (; head; head = head.next) {
        ans = (ans << 1) | head.val;
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
    pub fn get_decimal_value(mut head: Option<Box<ListNode>>) -> i32 {
        let mut ans = 0;
        while let Some(node) = head {
            ans = (ans << 1) | node.val;
            head = node.next;
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var getDecimalValue = function (head) {
    let ans = 0;
    for (; head; head = head.next) {
        ans = (ans << 1) | head.val;
    }
    return ans;
};
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
    public int GetDecimalValue(ListNode head) {
        int ans = 0;
        for (; head != null; head = head.next) {
            ans = ans << 1 | head.val;
        }
        return ans;
    }
}
```

#### PHP

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @return Integer
     */
    function getDecimalValue($head) {
        $ans = 0;
        while ($head !== null) {
            $ans = ($ans << 1) | $head->val;
            $head = $head->next;
        }
        return $ans;
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

int getDecimalValue(struct ListNode* head) {
    int ans = 0;
    struct ListNode* cur = head;
    while (cur) {
        ans = (ans << 1) | cur->val;
        cur = cur->next;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1291. 顺次数](https://leetcode.cn/problems/sequential-digits){#1291}

{{< tabs "1291" >}}

{{% tab "python" %}}
```python
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for i in range(1, 9):
            x = i
            for j in range(i + 1, 10):
                x = x * 10 + j
                if low <= x <= high:
                    ans.append(x)
        return sorted(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < 9; ++i) {
            int x = i;
            for (int j = i + 1; j < 10; ++j) {
                x = x * 10 + j;
                if (x >= low && x <= high) {
                    ans.add(x);
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 9; ++i) {
            int x = i;
            for (int j = i + 1; j < 10; ++j) {
                x = x * 10 + j;
                if (x >= low && x <= high) {
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sequentialDigits(low int, high int) (ans []int) {
	for i := 1; i < 9; i++ {
		x := i
		for j := i + 1; j < 10; j++ {
			x = x*10 + j
			if low <= x && x <= high {
				ans = append(ans, x)
			}
		}
	}
	sort.Ints(ans)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sequentialDigits(low: number, high: number): number[] {
    const ans: number[] = [];
    for (let i = 1; i < 9; ++i) {
        let x = i;
        for (let j = i + 1; j < 10; ++j) {
            x = x * 10 + j;
            if (x >= low && x <= high) {
                ans.push(x);
            }
        }
    }
    ans.sort((a, b) => a - b);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们定义「顺次数」为：每一位上的数字都比前一位上的数字大 <code>1</code> 的整数。</p>

<p>请你返回由&nbsp;<code>[low, high]</code>&nbsp;范围内所有顺次数组成的 <strong>有序</strong> 列表（从小到大排序）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输出：</strong>low = 100, high = 300
<strong>输出：</strong>[123,234]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输出：</strong>low = 1000, high = 13000
<strong>输出：</strong>[1234,2345,3456,4567,5678,6789,12345]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>10 &lt;= low &lt;= high &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举数字的第一位 $i$，然后枚举数字的最后一位 $j$，那么这个数字就是 $i,i+1,\cdots,j$ 这 $j-i+1$ 个数字组成的。我们可以通过不断地将数字乘以 $10$ 并加上下一个数字 $j+1$ 来得到下一个数字，如果数字在 $[low, high]$ 的范围内，我们就将它加入答案中。

枚举结束后，我们将答案数组排序并返回即可。

时间复杂度近似 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for i in range(1, 9):
            x = i
            for j in range(i + 1, 10):
                x = x * 10 + j
                if low <= x <= high:
                    ans.append(x)
        return sorted(ans)
```

#### Java

```java
class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < 9; ++i) {
            int x = i;
            for (int j = i + 1; j < 10; ++j) {
                x = x * 10 + j;
                if (x >= low && x <= high) {
                    ans.add(x);
                }
            }
        }
        Collections.sort(ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i < 9; ++i) {
            int x = i;
            for (int j = i + 1; j < 10; ++j) {
                x = x * 10 + j;
                if (x >= low && x <= high) {
                    ans.push_back(x);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func sequentialDigits(low int, high int) (ans []int) {
	for i := 1; i < 9; i++ {
		x := i
		for j := i + 1; j < 10; j++ {
			x = x*10 + j
			if low <= x && x <= high {
				ans = append(ans, x)
			}
		}
	}
	sort.Ints(ans)
	return
}
```

#### TypeScript

```ts
function sequentialDigits(low: number, high: number): number[] {
    const ans: number[] = [];
    for (let i = 1; i < 9; ++i) {
        let x = i;
        for (let j = i + 1; j < 10; ++j) {
            x = x * 10 + j;
            if (x >= low && x <= high) {
                ans.push(x);
            }
        }
    }
    ans.sort((a, b) => a - b);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1292. 元素和小于等于阈值的正方形的最大边长](https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold){#1292}

{{< tabs "1292" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        def check(k: int) -> bool:
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    v = s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j]
                    if v <= threshold:
                        return True
            return False

        m, n = len(mat), len(mat[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(mat, 1):
            for j, x in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x
        l, r = 0, min(m, n)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int threshold;
    private int[][] s;

    public int maxSideLength(int[][] mat, int threshold) {
        m = mat.length;
        n = mat[0].length;
        this.threshold = threshold;
        s = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int l = 0, r = Math.min(m, n);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int k) {
        for (int i = 0; i < m - k + 1; ++i) {
            for (int j = 0; j < n - k + 1; ++j) {
                if (s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        auto check = [&](int k) {
            for (int i = 0; i < m - k + 1; ++i) {
                for (int j = 0; j < n - k + 1; ++j) {
                    if (s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };
        int l = 0, r = min(m, n);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSideLength(mat [][]int, threshold int) int {
	m, n := len(mat), len(mat[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + mat[i-1][j-1]
		}
	}
	check := func(k int) bool {
		for i := 0; i < m-k+1; i++ {
			for j := 0; j < n-k+1; j++ {
				if s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j] <= threshold {
					return true
				}
			}
		}
		return false
	}
	l, r := 0, min(m, n)
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length;
    const n = mat[0].length;
    const s: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    const check = (k: number): boolean => {
        for (let i = 0; i < m - k + 1; ++i) {
            for (let j = 0; j < n - k + 1; ++j) {
                if (s[i + k][j + k] - s[i + k][j] - s[i][j + k] + s[i][j] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    };

    let l = 0;
    let r = Math.min(m, n);
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
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

<p>给你一个大小为&nbsp;<code>m x n</code>&nbsp;的矩阵&nbsp;<code>mat</code>&nbsp;和一个整数阈值&nbsp;<code>threshold</code>。</p>

<p>请你返回元素总和小于或等于阈值的正方形区域的最大边长；如果没有这样的正方形区域，则返回 <strong>0&nbsp;</strong>。<br />
&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1292.Maximum%20Side%20Length%20of%20a%20Square%20with%20Sum%20Less%20than%20or%20Equal%20to%20Threshold/images/e1.png" style="height: 186px; width: 335px;" /></p>

<pre>
<strong>输入：</strong>mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
<strong>输出：</strong>2
<strong>解释：</strong>总和小于或等于 4 的正方形的最大边长为 2，如图所示。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>0 &lt;= mat[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= threshold &lt;= 10<sup>5</sup></code><sup>&nbsp;</sup></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀和 + 二分查找

我们可以先预处理得到二维前缀和数组 $s$，其中 $s[i + 1][j + 1]$ 表示矩阵 $mat$ 中从 $(0, 0)$ 到 $(i, j)$ 的元素和，那么对于任意的正方形区域，我们都可以在 $O(1)$ 的时间内得到其元素和。

接下来，我们可以使用二分查找的方法得到最大的边长。我们枚举正方形的边长 $k$，然后枚举正方形的左上角位置 $(i, j)$，那么我们可以得到正方形的元素和 $v$，如果 $v \leq threshold$，那么说明存在边长为 $k$ 的正方形区域的元素和小于或等于阈值，否则不存在。

时间复杂度 $O(m \times n \times \log \min(m, n))$，空间复杂度 $O(m \times n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        def check(k: int) -> bool:
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    v = s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j]
                    if v <= threshold:
                        return True
            return False

        m, n = len(mat), len(mat[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(mat, 1):
            for j, x in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x
        l, r = 0, min(m, n)
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int threshold;
    private int[][] s;

    public int maxSideLength(int[][] mat, int threshold) {
        m = mat.length;
        n = mat[0].length;
        this.threshold = threshold;
        s = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int l = 0, r = Math.min(m, n);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int k) {
        for (int i = 0; i < m - k + 1; ++i) {
            for (int j = 0; j < n - k + 1; ++j) {
                if (s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        auto check = [&](int k) {
            for (int i = 0; i < m - k + 1; ++i) {
                for (int j = 0; j < n - k + 1; ++j) {
                    if (s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j] <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };
        int l = 0, r = min(m, n);
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maxSideLength(mat [][]int, threshold int) int {
	m, n := len(mat), len(mat[0])
	s := make([][]int, m+1)
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + mat[i-1][j-1]
		}
	}
	check := func(k int) bool {
		for i := 0; i < m-k+1; i++ {
			for j := 0; j < n-k+1; j++ {
				if s[i+k][j+k]-s[i][j+k]-s[i+k][j]+s[i][j] <= threshold {
					return true
				}
			}
		}
		return false
	}
	l, r := 0, min(m, n)
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length;
    const n = mat[0].length;
    const s: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }
    const check = (k: number): boolean => {
        for (let i = 0; i < m - k + 1; ++i) {
            for (let j = 0; j < n - k + 1; ++j) {
                if (s[i + k][j + k] - s[i + k][j] - s[i][j + k] + s[i][j] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    };

    let l = 0;
    let r = Math.min(m, n);
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
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

# [1293. 网格中的最短路径](https://leetcode.cn/problems/shortest-path-in-a-grid-with-obstacles-elimination){#1293}

{{< tabs "1293" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if k >= m + n - 3:
            return m + n - 2
        q = deque([(0, 0, k)])
        vis = {(0, 0, k)}
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j, k = q.popleft()
                for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n:
                        if x == m - 1 and y == n - 1:
                            return ans
                        if grid[x][y] == 0 and (x, y, k) not in vis:
                            q.append((x, y, k))
                            vis.add((x, y, k))
                        if grid[x][y] == 1 and k > 0 and (x, y, k - 1) not in vis:
                            q.append((x, y, k - 1))
                            vis.add((x, y, k - 1))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestPath(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        if (k >= m + n - 3) {
            return m + n - 2;
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, k});
        boolean[][][] vis = new boolean[m][n][k + 1];
        vis[0][0][k] = true;
        int ans = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                int[] p = q.poll();
                k = p[2];
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + dirs[j];
                    int y = p[1] + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (x == m - 1 && y == n - 1) {
                            return ans;
                        }
                        if (grid[x][y] == 0 && !vis[x][y][k]) {
                            q.offer(new int[] {x, y, k});
                            vis[x][y][k] = true;
                        } else if (grid[x][y] == 1 && k > 0 && !vis[x][y][k - 1]) {
                            q.offer(new int[] {x, y, k - 1});
                            vis[x][y][k - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 3) return m + n - 2;
        queue<vector<int>> q;
        q.push({0, 0, k});
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k + 1)));
        vis[0][0][k] = true;
        int ans = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                auto p = q.front();
                k = p[2];
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + dirs[j], y = p[1] + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (x == m - 1 && y == n - 1) return ans;
                        if (grid[x][y] == 0 && !vis[x][y][k]) {
                            q.push({x, y, k});
                            vis[x][y][k] = true;
                        } else if (grid[x][y] == 1 && k > 0 && !vis[x][y][k - 1]) {
                            q.push({x, y, k - 1});
                            vis[x][y][k - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPath(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])
	if k >= m+n-3 {
		return m + n - 2
	}
	q := [][]int{[]int{0, 0, k}}
	vis := make([][][]bool, m)
	for i := range vis {
		vis[i] = make([][]bool, n)
		for j := range vis[i] {
			vis[i][j] = make([]bool, k+1)
		}
	}
	vis[0][0][k] = true
	dirs := []int{-1, 0, 1, 0, -1}
	ans := 0
	for len(q) > 0 {
		ans++
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			k = p[2]
			for j := 0; j < 4; j++ {
				x, y := p[0]+dirs[j], p[1]+dirs[j+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					if x == m-1 && y == n-1 {
						return ans
					}
					if grid[x][y] == 0 && !vis[x][y][k] {
						q = append(q, []int{x, y, k})
						vis[x][y][k] = true
					} else if grid[x][y] == 1 && k > 0 && !vis[x][y][k-1] {
						q = append(q, []int{x, y, k - 1})
						vis[x][y][k-1] = true
					}
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestPath(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0].length;
    if (k >= m + n - 3) {
        return m + n - 2;
    }

    let q: Point[] = [[0, 0, k]];
    const vis = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array.from({ length: k + 1 }, () => false)),
    );
    vis[0][0][k] = true;
    const dirs = [0, 1, 0, -1, 0];
    let ans = 0;

    while (q.length) {
        const nextQ: Point[] = [];
        ++ans;

        for (const [i, j, k] of q) {
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (x === m - 1 && y === n - 1) {
                    return ans;
                }
                const v = grid[x]?.[y];
                if (v === 0 && !vis[x][y][k]) {
                    nextQ.push([x, y, k]);
                    vis[x][y][k] = true;
                } else if (v === 1 && k > 0 && !vis[x][y][k - 1]) {
                    nextQ.push([x, y, k - 1]);
                    vis[x][y][k - 1] = true;
                }
            }
        }
        q = nextQ;
    }
    return -1;
}

type Point = [number, number, number];
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m * n</code>&nbsp;的网格，其中每个单元格不是&nbsp;<code>0</code>（空）就是&nbsp;<code>1</code>（障碍物）。每一步，您都可以在空白单元格中上、下、左、右移动。</p>

<p>如果您 <strong>最多</strong> 可以消除 <code>k</code> 个障碍物，请找出从左上角 <code>(0, 0)</code> 到右下角 <code>(m-1, n-1)</code> 的最短路径，并返回通过该路径所需的步数。如果找不到这样的路径，则返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1293.Shortest%20Path%20in%20a%20Grid%20with%20Obstacles%20Elimination/images/1700710956-kcxqcC-img_v3_025f_d55a658c-8f40-464b-800f-22ccd27cc9fg.jpg" style="width: 243px; height: 404px;" /></p>

<pre>
<strong>输入：</strong> grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
<strong>输出：</strong>6
<strong>解释：
</strong>不消除任何障碍的最短路径是 10。
消除位置 (3,2) 处的障碍后，最短路径是 6 。该路径是 <code>(0,0) -&gt; (0,1) -&gt; (0,2) -&gt; (1,2) -&gt; (2,2) -&gt; <strong>(3,2)</strong> -&gt; (4,2)</code>.
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1200-1299/1293.Shortest%20Path%20in%20a%20Grid%20with%20Obstacles%20Elimination/images/1700710701-uPqkZe-img_v3_025f_0edd50fb-8a70-4a42-add0-f602caaad35g.jpg" style="width: 243px; height: 244px;" /></p>

<pre>
<strong>输入：</strong>grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
<strong>输出：</strong>-1
<strong>解释：</strong>我们至少需要消除两个障碍才能找到这样的路径。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>grid.length&nbsp;== m</code></li>
	<li><code>grid[0].length&nbsp;== n</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= m*n</code></li>
	<li><code>grid[i][j]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;或<strong>&nbsp;</strong><code>1</code></li>
	<li><code>grid[0][0] == grid[m-1][n-1] == 0</code></li>
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
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if k >= m + n - 3:
            return m + n - 2
        q = deque([(0, 0, k)])
        vis = {(0, 0, k)}
        ans = 0
        while q:
            ans += 1
            for _ in range(len(q)):
                i, j, k = q.popleft()
                for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n:
                        if x == m - 1 and y == n - 1:
                            return ans
                        if grid[x][y] == 0 and (x, y, k) not in vis:
                            q.append((x, y, k))
                            vis.add((x, y, k))
                        if grid[x][y] == 1 and k > 0 and (x, y, k - 1) not in vis:
                            q.append((x, y, k - 1))
                            vis.add((x, y, k - 1))
        return -1
```

#### Java

```java
class Solution {
    public int shortestPath(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        if (k >= m + n - 3) {
            return m + n - 2;
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0, k});
        boolean[][][] vis = new boolean[m][n][k + 1];
        vis[0][0][k] = true;
        int ans = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                int[] p = q.poll();
                k = p[2];
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + dirs[j];
                    int y = p[1] + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (x == m - 1 && y == n - 1) {
                            return ans;
                        }
                        if (grid[x][y] == 0 && !vis[x][y][k]) {
                            q.offer(new int[] {x, y, k});
                            vis[x][y][k] = true;
                        } else if (grid[x][y] == 1 && k > 0 && !vis[x][y][k - 1]) {
                            q.offer(new int[] {x, y, k - 1});
                            vis[x][y][k - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 3) return m + n - 2;
        queue<vector<int>> q;
        q.push({0, 0, k});
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(k + 1)));
        vis[0][0][k] = true;
        int ans = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            ++ans;
            for (int i = q.size(); i > 0; --i) {
                auto p = q.front();
                k = p[2];
                q.pop();
                for (int j = 0; j < 4; ++j) {
                    int x = p[0] + dirs[j], y = p[1] + dirs[j + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        if (x == m - 1 && y == n - 1) return ans;
                        if (grid[x][y] == 0 && !vis[x][y][k]) {
                            q.push({x, y, k});
                            vis[x][y][k] = true;
                        } else if (grid[x][y] == 1 && k > 0 && !vis[x][y][k - 1]) {
                            q.push({x, y, k - 1});
                            vis[x][y][k - 1] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func shortestPath(grid [][]int, k int) int {
	m, n := len(grid), len(grid[0])
	if k >= m+n-3 {
		return m + n - 2
	}
	q := [][]int{[]int{0, 0, k}}
	vis := make([][][]bool, m)
	for i := range vis {
		vis[i] = make([][]bool, n)
		for j := range vis[i] {
			vis[i][j] = make([]bool, k+1)
		}
	}
	vis[0][0][k] = true
	dirs := []int{-1, 0, 1, 0, -1}
	ans := 0
	for len(q) > 0 {
		ans++
		for i := len(q); i > 0; i-- {
			p := q[0]
			q = q[1:]
			k = p[2]
			for j := 0; j < 4; j++ {
				x, y := p[0]+dirs[j], p[1]+dirs[j+1]
				if x >= 0 && x < m && y >= 0 && y < n {
					if x == m-1 && y == n-1 {
						return ans
					}
					if grid[x][y] == 0 && !vis[x][y][k] {
						q = append(q, []int{x, y, k})
						vis[x][y][k] = true
					} else if grid[x][y] == 1 && k > 0 && !vis[x][y][k-1] {
						q = append(q, []int{x, y, k - 1})
						vis[x][y][k-1] = true
					}
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function shortestPath(grid: number[][], k: number): number {
    const m = grid.length;
    const n = grid[0].length;
    if (k >= m + n - 3) {
        return m + n - 2;
    }

    let q: Point[] = [[0, 0, k]];
    const vis = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array.from({ length: k + 1 }, () => false)),
    );
    vis[0][0][k] = true;
    const dirs = [0, 1, 0, -1, 0];
    let ans = 0;

    while (q.length) {
        const nextQ: Point[] = [];
        ++ans;

        for (const [i, j, k] of q) {
            for (let d = 0; d < 4; ++d) {
                const [x, y] = [i + dirs[d], j + dirs[d + 1]];
                if (x === m - 1 && y === n - 1) {
                    return ans;
                }
                const v = grid[x]?.[y];
                if (v === 0 && !vis[x][y][k]) {
                    nextQ.push([x, y, k]);
                    vis[x][y][k] = true;
                } else if (v === 1 && k > 0 && !vis[x][y][k - 1]) {
                    nextQ.push([x, y, k - 1]);
                    vis[x][y][k - 1] = true;
                }
            }
        }
        q = nextQ;
    }
    return -1;
}

type Point = [number, number, number];
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1294. 不同国家的天气类型 🔒](https://leetcode.cn/problems/weather-type-in-each-country){#1294}

{{< tabs "1294" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    country_name,
    CASE
        WHEN AVG(weather_state) <= 15 THEN 'Cold'
        WHEN AVG(weather_state) >= 25 THEN 'Hot'
        ELSE 'Warm'
    END AS weather_type
FROM
    Weather AS w
    JOIN Countries USING (country_id)
WHERE DATE_FORMAT(day, '%Y-%m') = '2019-11'
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Countries</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| country_id    | int     |
| country_name  | varchar |
+---------------+---------+
country_id 是这张表的主键(具有唯一值的列)。
该表的每行有 country_id 和 country_name 两列。
</pre>

<p>&nbsp;</p>

<p>表：<code>Weather</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| country_id    | int  |
| weather_state | int  |
| day           | date |
+---------------+------+
(country_id, day) 是该表的复合主键(具有唯一值的列)。
该表的每一行记录了某个国家某一天的天气情况。
</pre>

<p>&nbsp;</p>

<p>编写解决方案找到表中每个国家在 2019 年 11 月的天气类型。</p>

<p>天气类型的定义如下：</p>

<ul>
	<li>当 <code>weather_state</code> 的平均值小于或等于 <code>15</code> 返回 <strong>Cold</strong>，</li>
	<li>当 <code>weather_state</code> 的平均值大于或等于 <code>25</code> 返回 <strong>Hot</strong>，</li>
	<li>否则返回&nbsp;<strong>Warm</strong>。</li>
</ul>

<p>以 <strong>任意顺序</strong> 返回你的查询结果。</p>

<p>返回结果格式如下所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Countries table:
+------------+--------------+
| country_id | country_name |
+------------+--------------+
| 2          | USA          |
| 3          | Australia    |
| 7          | Peru         |
| 5          | China        |
| 8          | Morocco      |
| 9          | Spain        |
+------------+--------------+
Weather table:
+------------+---------------+------------+
| country_id | weather_state | day        |
+------------+---------------+------------+
| 2          | 15            | 2019-11-01 |
| 2          | 12            | 2019-10-28 |
| 2          | 12            | 2019-10-27 |
| 3          | -2            | 2019-11-10 |
| 3          | 0             | 2019-11-11 |
| 3          | 3             | 2019-11-12 |
| 5          | 16            | 2019-11-07 |
| 5          | 18            | 2019-11-09 |
| 5          | 21            | 2019-11-23 |
| 7          | 25            | 2019-11-28 |
| 7          | 22            | 2019-12-01 |
| 7          | 20            | 2019-12-02 |
| 8          | 25            | 2019-11-05 |
| 8          | 27            | 2019-11-15 |
| 8          | 31            | 2019-11-25 |
| 9          | 7             | 2019-10-23 |
| 9          | 3             | 2019-12-23 |
+------------+---------------+------------+
<strong>输出：</strong>
+--------------+--------------+
| country_name | weather_type |
+--------------+--------------+
| USA          | Cold         |
| Austraila    | Cold         |
| Peru         | Hot          |
| China        | Warm         |
| Morocco      | Hot          |
+--------------+--------------+
<strong>解释：</strong>
USA 11 月的平均 weather_state 为 (15) / 1 = 15 所以天气类型为 Cold。
Australia 11 月的平均 weather_state 为 (-2 + 0 + 3) / 3 = 0.333 所以天气类型为 Cold。
Peru 11 月的平均 weather_state 为 (25) / 1 = 25 所以天气类型为 Hot。
China 11 月的平均 weather_state 为 (16 + 18 + 21) / 3 = 18.333 所以天气类型为 Warm。
Morocco 11 月的平均 weather_state 为 (25 + 27 + 31) / 3 = 27.667 所以天气类型为 Hot。
我们并不知道 Spain 在 11 月的 weather_state 情况所以无需将他包含在结果中。
</pre>

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
    country_name,
    CASE
        WHEN AVG(weather_state) <= 15 THEN 'Cold'
        WHEN AVG(weather_state) >= 25 THEN 'Hot'
        ELSE 'Warm'
    END AS weather_type
FROM
    Weather AS w
    JOIN Countries USING (country_id)
WHERE DATE_FORMAT(day, '%Y-%m') = '2019-11'
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1295. 统计位数为偶数的数字](https://leetcode.cn/problems/find-numbers-with-even-number-of-digits){#1295}

{{< tabs "1295" >}}

{{% tab "python" %}}
```python
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(len(str(x)) % 2 == 0 for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            if (String.valueOf(x).length() % 2 == 0) {
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
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            ans += to_string(x).size() % 2 == 0;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findNumbers(nums []int) (ans int) {
	for _, x := range nums {
		if len(strconv.Itoa(x))%2 == 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findNumbers(nums: number[]): number {
    return nums.filter(x => x.toString().length % 2 === 0).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        nums.iter().filter(|&x| x.to_string().len() % 2 == 0).count() as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function (nums) {
    return nums.filter(x => x.toString().length % 2 === 0).length;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FindNumbers(int[] nums) {
        return nums.Count(x => x.ToString().Length % 2 == 0);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，请你返回其中包含&nbsp;<strong>偶数</strong>&nbsp;个数位的数字的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [12,345,2,6,7896]
<strong>输出：</strong>2
<strong>解释：
</strong>12 是 2 位数字（位数为偶数）&nbsp;
345 是 3 位数字（位数为奇数）&nbsp;&nbsp;
2 是 1 位数字（位数为奇数）&nbsp;
6 是 1 位数字 位数为奇数）&nbsp;
7896 是 4 位数字（位数为偶数）&nbsp;&nbsp;
因此只有 12 和 7896 是位数为偶数的数字
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [555,901,482,1771]
<strong>输出：</strong>1 
<strong>解释： </strong>
只有 1771 是位数为偶数的数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历数组 $\textit{nums}$ 中的每个元素，对于当前遍历到的元素 $x$，我们直接将其转换为字符串，然后判断其长度是否为偶数即可。若是则将答案加一。

遍历结束后，我们返回答案即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$。其中 $n$ 是数组 $\textit{nums}$ 的长度，而 $M$ 是数组 $\textit{nums}$ 中的元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(len(str(x)) % 2 == 0 for x in nums)
```

#### Java

```java
class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            if (String.valueOf(x).length() % 2 == 0) {
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
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int& x : nums) {
            ans += to_string(x).size() % 2 == 0;
        }
        return ans;
    }
};
```

#### Go

```go
func findNumbers(nums []int) (ans int) {
	for _, x := range nums {
		if len(strconv.Itoa(x))%2 == 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function findNumbers(nums: number[]): number {
    return nums.filter(x => x.toString().length % 2 === 0).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        nums.iter().filter(|&x| x.to_string().len() % 2 == 0).count() as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function (nums) {
    return nums.filter(x => x.toString().length % 2 === 0).length;
};
```

#### C#

```cs
public class Solution {
    public int FindNumbers(int[] nums) {
        return nums.Count(x => x.ToString().Length % 2 == 0);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1296. 划分数组为连续数字的集合](https://leetcode.cn/problems/divide-array-in-sets-of-k-consecutive-numbers){#1296}

{{< tabs "1296" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k:
            return False
        cnt = Counter(nums)
        sd = SortedDict(cnt)
        while sd:
            x = next(iter(sd))
            for y in range(x, x + k):
                if y not in sd:
                    return False
                if sd[y] == 1:
                    del sd[y]
                else:
                    sd[y] -= 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) {
            return false;
        }
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int x : nums) {
            tm.merge(x, 1, Integer::sum);
        }
        while (!tm.isEmpty()) {
            int x = tm.firstKey();
            for (int y = x; y < x + k; ++y) {
                int t = tm.merge(y, -1, Integer::sum);
                if (t < 0) {
                    return false;
                }
                if (t == 0) {
                    tm.remove(y);
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
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) {
            return false;
        }
        map<int, int> mp;
        for (int x : nums) {
            ++mp[x];
        }
        while (!mp.empty()) {
            int x = mp.begin()->first;
            for (int y = x; y < x + k; ++y) {
                if (!mp.contains(y)) {
                    return false;
                }
                if (--mp[y] == 0) {
                    mp.erase(y);
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
func isPossibleDivide(nums []int, k int) bool {
	if len(nums)%k != 0 {
		return false
	}
	tm := treemap.NewWithIntComparator()
	for _, x := range nums {
		if v, ok := tm.Get(x); ok {
			tm.Put(x, v.(int)+1)
		} else {
			tm.Put(x, 1)
		}
	}
	for !tm.Empty() {
		x, _ := tm.Min()
		for y := x.(int); y < x.(int)+k; y++ {
			if v, ok := tm.Get(y); ok {
				if v.(int) == 1 {
					tm.Remove(y)
				} else {
					tm.Put(y, v.(int)-1)
				}
			} else {
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
function isPossibleDivide(nums: number[], k: number): boolean {
    if (nums.length % k !== 0) {
        return false;
    }
    const tm = new TreeMap<number, number>();
    for (const x of nums) {
        tm.set(x, (tm.get(x) || 0) + 1);
    }
    while (tm.size()) {
        const x = tm.first()![0];
        for (let y = x; y < x + k; ++y) {
            if (!tm.has(y)) {
                return false;
            }
            if (tm.get(y)! === 1) {
                tm.delete(y);
            } else {
                tm.set(y, tm.get(y)! - 1);
            }
        }
    }
    return true;
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

    search(predicate: (val: T) => boolean, direction: 'left' | 'right'): T | undefined {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result?.data;
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

    count(data: T): number {
        const node = this.find(data);
        return node ? node.count : 0;
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

class TreeMap<K = number, V = unknown> {
    _size: number;
    tree: RBTree<K>;
    map: Map<K, V> = new Map();
    compare: Compare<K>;
    constructor(
        collection: Array<[K, V]> | Compare<K> = [],
        compare: Compare<K> = (l: K, r: K) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }

    size(): number {
        return this._size;
    }

    has(key: K): boolean {
        return !!this.tree.find(key);
    }

    get(key: K): V | undefined {
        return this.map.get(key);
    }

    set(key: K, val: V): boolean {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }

    delete(key: K): boolean {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }

    floor(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }

    higher(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }

    lower(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }

    first(): [K, V] | undefined {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }

    last(): [K, V] | undefined {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }

    shift(): [K, V] | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first[0]);
        return first;
    }

    pop(): [K, V] | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last[0]);
        return last;
    }

    toKeyValue(key: K): [K, V];
    toKeyValue(key: undefined): undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined {
        return key != null ? [key, this.map.get(key)!] : undefined;
    }

    *[Symbol.iterator](): Generator<[K, V], void, void> {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }

    *keys(): Generator<K, void, void> {
        for (const key of this.tree.inOrder()) yield key;
    }

    *values(): Generator<V, undefined, void> {
        for (const key of this.keys()) yield this.map.get(key)!;
        return undefined;
    }

    *rkeys(): Generator<K, undefined, void> {
        for (const key of this.tree.reverseInOrder()) yield key;
        return undefined;
    }

    *rvalues(): Generator<V, undefined, void> {
        for (const key of this.rkeys()) yield this.map.get(key)!;
        return undefined;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>k</code>，请你判断是否可以把这个数组划分成一些由&nbsp;<code>k</code>&nbsp;个连续数字组成的集合。<br />
如果可以，请返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,3,4,4,5,6], k = 4
<strong>输出：</strong>true
<strong>解释：</strong>数组可以分成 [1,2,3,4] 和 [3,4,5,6]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
<strong>输出：</strong>true
<strong>解释：</strong>数组可以分成 [1,2,3] , [2,3,4] , [3,4,5] 和 [9,10,11]。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], k = 3
<strong>输出：</strong>false
<strong>解释：</strong>数组不能分成几个大小为 3 的子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>此题目与 846 重复：<a href="https://leetcode.cn/problems/hand-of-straights/" target="_blank">https://leetcode.cn/problems/hand-of-straights/</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们首先判断数组 $\textit{nums}$ 的长度是否能被 $\textit{k}$ 整除，如果不能整除，说明无法将数组划分成若干个长度为 $\textit{k}$ 的子数组，直接返回 $\text{false}$。

接下来，我们用一个哈希表 $\textit{cnt}$ 统计数组 $\textit{nums}$ 中每个数字出现的次数，然后对数组 $\textit{nums}$ 进行排序。

然后，我们遍历排序后的数组 $\textit{nums}$，对于每个数字 $x$，如果 $\textit{cnt}[x]$ 不为 $0$，我们枚举 $x$ 到 $x+\textit{k}-1$ 的每个数字 $y$，如果 $\textit{cnt}[y]$ 为 $0$，说明无法将数组划分成若干个长度为 $\textit{k}$ 的子数组，直接返回 $\text{false}$。否则，我们将 $\textit{cnt}[y]$ 减 $1$。

遍历结束后，说明可以将数组划分成若干个长度为 $\textit{k}$ 的子数组，返回 $\text{true}$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k:
            return False
        cnt = Counter(nums)
        for x in sorted(nums):
            if cnt[x]:
                for y in range(x, x + k):
                    if cnt[y] == 0:
                        return False
                    cnt[y] -= 1
        return True
```

#### Java

```java
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) {
            return false;
        }
        Arrays.sort(nums);
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        for (int x : nums) {
            if (cnt.getOrDefault(x, 0) > 0) {
                for (int y = x; y < x + k; ++y) {
                    if (cnt.merge(y, -1, Integer::sum) < 0) {
                        return false;
                    }
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
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) {
            return false;
        }
        ranges::sort(nums);
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        for (int x : nums) {
            if (cnt.contains(x)) {
                for (int y = x; y < x + k; ++y) {
                    if (!cnt.contains(y)) {
                        return false;
                    }
                    if (--cnt[y] == 0) {
                        cnt.erase(y);
                    }
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func isPossibleDivide(nums []int, k int) bool {
	if len(nums)%k != 0 {
		return false
	}
	sort.Ints(nums)
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for _, x := range nums {
		if cnt[x] > 0 {
			for y := x; y < x+k; y++ {
				if cnt[y] == 0 {
					return false
				}
				cnt[y]--
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function isPossibleDivide(nums: number[], k: number): boolean {
    if (nums.length % k !== 0) {
        return false;
    }
    const cnt = new Map<number, number>();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    nums.sort((a, b) => a - b);
    for (const x of nums) {
        if (cnt.get(x)! > 0) {
            for (let y = x; y < x + k; y++) {
                if ((cnt.get(y) || 0) === 0) {
                    return false;
                }
                cnt.set(y, cnt.get(y)! - 1);
            }
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：有序集合

与方法一类似，我们首先判断数组 $\textit{nums}$ 的长度是否能被 $\textit{k}$ 整除，如果不能整除，说明无法将数组划分成若干个长度为 $\textit{k}$ 的子数组，直接返回 $\text{false}$。

接下来，我们用一个有序集合 $\textit{sd}$ 统计数组 $\textit{nums}$ 中每个数字出现的次数。

然后，我们循环取出有序集合中的最小值 $x$，然后枚举 $x$ 到 $x+\textit{k}-1$ 的每个数字 $y$，如果这些数字在有序集合中出现的次数都不为 $0$，则我们将这些数字的出现次数减 $1$，如果出现次数减 $1$ 后为 $0$，则将该数字从有序集合中删除，否则说明无法将数组划分成若干个长度为 $\textit{k}$ 的子数组，返回 $\text{false}$。如果可以将数组划分成若干个长度为 $\textit{k}$ 的子数组，则遍历结束后返回 $\text{true}$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k:
            return False
        cnt = Counter(nums)
        sd = SortedDict(cnt)
        while sd:
            x = next(iter(sd))
            for y in range(x, x + k):
                if y not in sd:
                    return False
                if sd[y] == 1:
                    del sd[y]
                else:
                    sd[y] -= 1
        return True
```

#### Java

```java
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        if (nums.length % k != 0) {
            return false;
        }
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        for (int x : nums) {
            tm.merge(x, 1, Integer::sum);
        }
        while (!tm.isEmpty()) {
            int x = tm.firstKey();
            for (int y = x; y < x + k; ++y) {
                int t = tm.merge(y, -1, Integer::sum);
                if (t < 0) {
                    return false;
                }
                if (t == 0) {
                    tm.remove(y);
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
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k) {
            return false;
        }
        map<int, int> mp;
        for (int x : nums) {
            ++mp[x];
        }
        while (!mp.empty()) {
            int x = mp.begin()->first;
            for (int y = x; y < x + k; ++y) {
                if (!mp.contains(y)) {
                    return false;
                }
                if (--mp[y] == 0) {
                    mp.erase(y);
                }
            }
        }
        return true;
    }
};
```

#### Go

```go
func isPossibleDivide(nums []int, k int) bool {
	if len(nums)%k != 0 {
		return false
	}
	tm := treemap.NewWithIntComparator()
	for _, x := range nums {
		if v, ok := tm.Get(x); ok {
			tm.Put(x, v.(int)+1)
		} else {
			tm.Put(x, 1)
		}
	}
	for !tm.Empty() {
		x, _ := tm.Min()
		for y := x.(int); y < x.(int)+k; y++ {
			if v, ok := tm.Get(y); ok {
				if v.(int) == 1 {
					tm.Remove(y)
				} else {
					tm.Put(y, v.(int)-1)
				}
			} else {
				return false
			}
		}
	}
	return true
}
```

#### TypeScript

```ts
function isPossibleDivide(nums: number[], k: number): boolean {
    if (nums.length % k !== 0) {
        return false;
    }
    const tm = new TreeMap<number, number>();
    for (const x of nums) {
        tm.set(x, (tm.get(x) || 0) + 1);
    }
    while (tm.size()) {
        const x = tm.first()![0];
        for (let y = x; y < x + k; ++y) {
            if (!tm.has(y)) {
                return false;
            }
            if (tm.get(y)! === 1) {
                tm.delete(y);
            } else {
                tm.set(y, tm.get(y)! - 1);
            }
        }
    }
    return true;
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

    search(predicate: (val: T) => boolean, direction: 'left' | 'right'): T | undefined {
        let p = this.root;
        let result = null;
        while (p) {
            if (predicate(p.data)) {
                result = p;
                p = p[direction];
            } else {
                p = p[direction === 'left' ? 'right' : 'left'];
            }
        }
        return result?.data;
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

    count(data: T): number {
        const node = this.find(data);
        return node ? node.count : 0;
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

class TreeMap<K = number, V = unknown> {
    _size: number;
    tree: RBTree<K>;
    map: Map<K, V> = new Map();
    compare: Compare<K>;
    constructor(
        collection: Array<[K, V]> | Compare<K> = [],
        compare: Compare<K> = (l: K, r: K) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const [key, val] of collection) this.set(key, val);
    }

    size(): number {
        return this._size;
    }

    has(key: K): boolean {
        return !!this.tree.find(key);
    }

    get(key: K): V | undefined {
        return this.map.get(key);
    }

    set(key: K, val: V): boolean {
        const successful = this.tree.insert(key);
        this._size += successful ? 1 : 0;
        this.map.set(key, val);
        return successful;
    }

    delete(key: K): boolean {
        const deleted = this.tree.deleteAll(key);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) >= 0, 'left'));
    }

    floor(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) <= 0, 'right'));
    }

    higher(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) > 0, 'left'));
    }

    lower(target: K): [K, V] | undefined {
        return this.toKeyValue(this.tree.search(key => this.compare(key, target) < 0, 'right'));
    }

    first(): [K, V] | undefined {
        return this.toKeyValue(this.tree.inOrder().next().value);
    }

    last(): [K, V] | undefined {
        return this.toKeyValue(this.tree.reverseInOrder().next().value);
    }

    shift(): [K, V] | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first[0]);
        return first;
    }

    pop(): [K, V] | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last[0]);
        return last;
    }

    toKeyValue(key: K): [K, V];
    toKeyValue(key: undefined): undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined;
    toKeyValue(key: K | undefined): [K, V] | undefined {
        return key != null ? [key, this.map.get(key)!] : undefined;
    }

    *[Symbol.iterator](): Generator<[K, V], void, void> {
        for (const key of this.keys()) yield this.toKeyValue(key);
    }

    *keys(): Generator<K, void, void> {
        for (const key of this.tree.inOrder()) yield key;
    }

    *values(): Generator<V, undefined, void> {
        for (const key of this.keys()) yield this.map.get(key)!;
        return undefined;
    }

    *rkeys(): Generator<K, undefined, void> {
        for (const key of this.tree.reverseInOrder()) yield key;
        return undefined;
    }

    *rvalues(): Generator<V, undefined, void> {
        for (const key of this.rkeys()) yield this.map.get(key)!;
        return undefined;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1297. 子串的最大出现次数](https://leetcode.cn/problems/maximum-number-of-occurrences-of-a-substring){#1297}

{{< tabs "1297" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        ans = 0
        cnt = Counter()
        for i in range(len(s) - minSize + 1):
            t = s[i : i + minSize]
            ss = set(t)
            if len(ss) <= maxLetters:
                cnt[t] += 1
                ans = max(ans, cnt[t])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        Map<String, Integer> cnt = new HashMap<>();
        for (int i = 0; i < s.length() - minSize + 1; ++i) {
            String t = s.substring(i, i + minSize);
            Set<Character> ss = new HashSet<>();
            for (int j = 0; j < minSize; ++j) {
                ss.add(t.charAt(j));
            }
            if (ss.size() <= maxLetters) {
                cnt.put(t, cnt.getOrDefault(t, 0) + 1);
                ans = Math.max(ans, cnt.get(t));
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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map<string, int> cnt;
        for (int i = 0; i < s.size() - minSize + 1; ++i) {
            string t = s.substr(i, minSize);
            unordered_set<char> ss(t.begin(), t.end());
            if (ss.size() <= maxLetters) {
                ans = max(ans, ++cnt[t]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxFreq(s string, maxLetters int, minSize int, maxSize int) (ans int) {
	cnt := map[string]int{}
	for i := 0; i < len(s)-minSize+1; i++ {
		t := s[i : i+minSize]
		ss := map[rune]bool{}
		for _, c := range t {
			ss[c] = true
		}
		if len(ss) <= maxLetters {
			cnt[t]++
			if ans < cnt[t] {
				ans = cnt[t]
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxFreq(s: string, maxLetters: number, minSize: number, maxSize: number): number {
    const cnt = new Map<string, number>();
    let ans = 0;
    for (let i = 0; i < s.length - minSize + 1; ++i) {
        const t = s.slice(i, i + minSize);
        const ss = new Set(t.split(''));
        if (ss.size <= maxLetters) {
            cnt.set(t, (cnt.get(t) || 0) + 1);
            ans = Math.max(ans, cnt.get(t)!);
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

<p>给你一个字符串&nbsp;<code>s</code> ，请你返回满足以下条件且出现次数最大的&nbsp;<strong>任意</strong>&nbsp;子串的出现次数：</p>

<ul>
	<li>子串中不同字母的数目必须小于等于 <code>maxLetters</code> 。</li>
	<li>子串的长度必须大于等于&nbsp;<code>minSize</code> 且小于等于&nbsp;<code>maxSize</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;aababcaab&quot;, maxLetters = 2, minSize = 3, maxSize = 4
<strong>输出：</strong>2
<strong>解释：</strong>子串 &quot;aab&quot; 在原字符串中出现了 2 次。
它满足所有的要求：2 个不同的字母，长度为 3 （在 minSize 和 maxSize 范围内）。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aaaa&quot;, maxLetters = 1, minSize = 3, maxSize = 3
<strong>输出：</strong>2
<strong>解释：</strong>子串 &quot;aaa&quot; 在原字符串中出现了 2 次，且它们有重叠部分。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;aabcabcab&quot;, maxLetters = 2, minSize = 2, maxSize = 3
<strong>输出：</strong>3
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;abcde&quot;, maxLetters = 2, minSize = 3, maxSize = 3
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= maxLetters &lt;= 26</code></li>
	<li><code>1 &lt;= minSize &lt;= maxSize &lt;= min(26, s.length)</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

根据题目描述，如果一个长串满足条件，那么这个长串的长度为 $\textit{minSize}$ 的子串也一定满足条件。因此，我们只需要枚举 $s$ 中所有长度为 $\textit{minSize}$ 的子串，然后利用哈希表记录所有子串的出现次数，找出最大的次数作为答案即可。

时间复杂度 $O(n \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别为字符串 $s$ 的长度以及 $\textit{minSize}$ 的大小。本题中 $m$ 不超过 $26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        ans = 0
        cnt = Counter()
        for i in range(len(s) - minSize + 1):
            t = s[i : i + minSize]
            ss = set(t)
            if len(ss) <= maxLetters:
                cnt[t] += 1
                ans = max(ans, cnt[t])
        return ans
```

#### Java

```java
class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        Map<String, Integer> cnt = new HashMap<>();
        for (int i = 0; i < s.length() - minSize + 1; ++i) {
            String t = s.substring(i, i + minSize);
            Set<Character> ss = new HashSet<>();
            for (int j = 0; j < minSize; ++j) {
                ss.add(t.charAt(j));
            }
            if (ss.size() <= maxLetters) {
                cnt.put(t, cnt.getOrDefault(t, 0) + 1);
                ans = Math.max(ans, cnt.get(t));
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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int ans = 0;
        unordered_map<string, int> cnt;
        for (int i = 0; i < s.size() - minSize + 1; ++i) {
            string t = s.substr(i, minSize);
            unordered_set<char> ss(t.begin(), t.end());
            if (ss.size() <= maxLetters) {
                ans = max(ans, ++cnt[t]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxFreq(s string, maxLetters int, minSize int, maxSize int) (ans int) {
	cnt := map[string]int{}
	for i := 0; i < len(s)-minSize+1; i++ {
		t := s[i : i+minSize]
		ss := map[rune]bool{}
		for _, c := range t {
			ss[c] = true
		}
		if len(ss) <= maxLetters {
			cnt[t]++
			if ans < cnt[t] {
				ans = cnt[t]
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function maxFreq(s: string, maxLetters: number, minSize: number, maxSize: number): number {
    const cnt = new Map<string, number>();
    let ans = 0;
    for (let i = 0; i < s.length - minSize + 1; ++i) {
        const t = s.slice(i, i + minSize);
        const ss = new Set(t.split(''));
        if (ss.size <= maxLetters) {
            cnt.set(t, (cnt.get(t) || 0) + 1);
            ans = Math.max(ans, cnt.get(t)!);
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

# [1298. 你能从盒子里获得的最大糖果数](https://leetcode.cn/problems/maximum-candies-you-can-get-from-boxes){#1298}

{{< tabs "1298" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxCandies(
        self,
        status: List[int],
        candies: List[int],
        keys: List[List[int]],
        containedBoxes: List[List[int]],
        initialBoxes: List[int],
    ) -> int:
        q = deque()
        has, took = set(initialBoxes), set()
        ans = 0

        for box in initialBoxes:
            if status[box]:
                q.append(box)
                took.add(box)
                ans += candies[box]
        while q:
            box = q.popleft()
            for k in keys[box]:
                if not status[k]:
                    status[k] = 1
                    if k in has and k not in took:
                        q.append(k)
                        took.add(k)
                        ans += candies[k]

            for b in containedBoxes[box]:
                has.add(b)
                if status[b] and b not in took:
                    q.append(b)
                    took.add(b)
                    ans += candies[b]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxCandies(
        int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Deque<Integer> q = new ArrayDeque<>();
        Set<Integer> has = new HashSet<>();
        Set<Integer> took = new HashSet<>();
        int ans = 0;
        for (int box : initialBoxes) {
            has.add(box);
            if (status[box] == 1) {
                q.offer(box);
                took.add(box);
                ans += candies[box];
            }
        }
        while (!q.isEmpty()) {
            int box = q.poll();
            for (int k : keys[box]) {
                if (status[k] == 0) {
                    status[k] = 1;
                    if (has.contains(k) && !took.contains(k)) {
                        q.offer(k);
                        took.add(k);
                        ans += candies[k];
                    }
                }
            }
            for (int b : containedBoxes[box]) {
                has.add(b);
                if (status[b] == 1 && !took.contains(b)) {
                    q.offer(b);
                    took.add(b);
                    ans += candies[b];
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
    int maxCandies(
        vector<int>& status,
        vector<int>& candies,
        vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes,
        vector<int>& initialBoxes) {
        queue<int> q;
        unordered_set<int> has, took;
        int ans = 0;

        for (int box : initialBoxes) {
            has.insert(box);
            if (status[box]) {
                q.push(box);
                took.insert(box);
                ans += candies[box];
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            for (int k : keys[box]) {
                if (!status[k]) {
                    status[k] = 1;
                    if (has.count(k) && !took.count(k)) {
                        q.push(k);
                        took.insert(k);
                        ans += candies[k];
                    }
                }
            }

            for (int b : containedBoxes[box]) {
                has.insert(b);
                if (status[b] && !took.count(b)) {
                    q.push(b);
                    took.insert(b);
                    ans += candies[b];
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
func maxCandies(status []int, candies []int, keys [][]int, containedBoxes [][]int, initialBoxes []int) (ans int) {
	q := []int{}
	has := make(map[int]bool)
	took := make(map[int]bool)
	for _, box := range initialBoxes {
		has[box] = true
		if status[box] == 1 {
			q = append(q, box)
			took[box] = true
			ans += candies[box]
		}
	}
	for len(q) > 0 {
		box := q[0]
		q = q[1:]
		for _, k := range keys[box] {
			if status[k] == 0 {
				status[k] = 1
				if has[k] && !took[k] {
					q = append(q, k)
					took[k] = true
					ans += candies[k]
				}
			}
		}
		for _, b := range containedBoxes[box] {
			has[b] = true
			if status[b] == 1 && !took[b] {
				q = append(q, b)
				took[b] = true
				ans += candies[b]
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxCandies(
    status: number[],
    candies: number[],
    keys: number[][],
    containedBoxes: number[][],
    initialBoxes: number[],
): number {
    const q: number[] = [];
    const has: Set<number> = new Set();
    const took: Set<number> = new Set();
    let ans = 0;

    for (const box of initialBoxes) {
        has.add(box);
        if (status[box] === 1) {
            q.push(box);
            took.add(box);
            ans += candies[box];
        }
    }

    while (q.length > 0) {
        const box = q.pop()!;

        for (const k of keys[box]) {
            if (status[k] === 0) {
                status[k] = 1;
                if (has.has(k) && !took.has(k)) {
                    q.push(k);
                    took.add(k);
                    ans += candies[k];
                }
            }
        }

        for (const b of containedBoxes[box]) {
            has.add(b);
            if (status[b] === 1 && !took.has(b)) {
                q.push(b);
                took.add(b);
                ans += candies[b];
            }
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn max_candies(
        mut status: Vec<i32>,
        candies: Vec<i32>,
        keys: Vec<Vec<i32>>,
        contained_boxes: Vec<Vec<i32>>,
        initial_boxes: Vec<i32>,
    ) -> i32 {
        let mut q: VecDeque<i32> = VecDeque::new();
        let mut has: HashSet<i32> = HashSet::new();
        let mut took: HashSet<i32> = HashSet::new();
        let mut ans = 0;

        for &box_ in &initial_boxes {
            has.insert(box_);
            if status[box_ as usize] == 1 {
                q.push_back(box_);
                took.insert(box_);
                ans += candies[box_ as usize];
            }
        }

        while let Some(box_) = q.pop_front() {
            for &k in &keys[box_ as usize] {
                if status[k as usize] == 0 {
                    status[k as usize] = 1;
                    if has.contains(&k) && !took.contains(&k) {
                        q.push_back(k);
                        took.insert(k);
                        ans += candies[k as usize];
                    }
                }
            }

            for &b in &contained_boxes[box_ as usize] {
                has.insert(b);
                if status[b as usize] == 1 && !took.contains(&b) {
                    q.push_back(b);
                    took.insert(b);
                    ans += candies[b as usize];
                }
            }
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

<p>给你&nbsp;<code>n</code>&nbsp;个盒子，每个盒子的格式为&nbsp;<code>[status, candies, keys, containedBoxes]</code>&nbsp;，其中：</p>

<ul>
	<li>状态字&nbsp;<code>status[i]</code>：整数，如果&nbsp;<code>box[i]</code>&nbsp;是开的，那么是 <strong>1&nbsp;</strong>，否则是 <strong>0&nbsp;</strong>。</li>
	<li>糖果数&nbsp;<code>candies[i]</code>: 整数，表示&nbsp;<code>box[i]</code> 中糖果的数目。</li>
	<li>钥匙&nbsp;<code>keys[i]</code>：数组，表示你打开&nbsp;<code>box[i]</code>&nbsp;后，可以得到一些盒子的钥匙，每个元素分别为该钥匙对应盒子的下标。</li>
	<li>内含的盒子&nbsp;<code>containedBoxes[i]</code>：整数，表示放在&nbsp;<code>box[i]</code>&nbsp;里的盒子所对应的下标。</li>
</ul>

<p>给你一个整数数组&nbsp;<code>initialBoxes</code>，包含你最初拥有的盒子。你可以拿走每个&nbsp;<strong>已打开盒子&nbsp;</strong>里的所有糖果，并且可以使用其中的钥匙去开启新的盒子，并且可以使用在其中发现的其他盒子。</p>

<p>请你按照上述规则，返回可以获得糖果的 <strong>最大数目&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>status = [1,0,1,0], candies = [7,5,4,100], keys = [[],[],[1],[]], containedBoxes = [[1,2],[3],[],[]], initialBoxes = [0]
<strong>输出：</strong>16
<strong>解释：
</strong>一开始你有盒子 0 。你将获得它里面的 7 个糖果和盒子 1 和 2。
盒子 1 目前状态是关闭的，而且你还没有对应它的钥匙。所以你将会打开盒子 2 ，并得到里面的 4 个糖果和盒子 1 的钥匙。
在盒子 1 中，你会获得 5 个糖果和盒子 3 ，但是你没法获得盒子 3 的钥匙所以盒子 3 会保持关闭状态。
你总共可以获得的糖果数目 = 7 + 4 + 5 = 16 个。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>status = [1,0,0,0,0,0], candies = [1,1,1,1,1,1], keys = [[1,2,3,4,5],[],[],[],[],[]], containedBoxes = [[1,2,3,4,5],[],[],[],[],[]], initialBoxes = [0]
<strong>输出：</strong>6
<strong>解释：
</strong>你一开始拥有盒子 0 。打开它你可以找到盒子 1,2,3,4,5 和它们对应的钥匙。
打开这些盒子，你将获得所有盒子的糖果，所以总糖果数为 6 个。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>status = [1,1,1], candies = [100,1,100], keys = [[],[0,2],[]], containedBoxes = [[],[],[]], initialBoxes = [1]
<strong>输出：</strong>1
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>status = [1], candies = [100], keys = [[]], containedBoxes = [[]], initialBoxes = []
<strong>输出：</strong>0
</pre>

<p><strong>示例 5：</strong></p>

<pre>
<strong>输入：</strong>status = [1,1,1], candies = [2,3,2], keys = [[],[],[]], containedBoxes = [[],[],[]], initialBoxes = [2,1,0]
<strong>输出：</strong>7
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= status.length &lt;= 1000</code></li>
	<li><code>status.length == candies.length == keys.length == containedBoxes.length == n</code></li>
	<li><code>status[i]</code> 要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code> 。</li>
	<li><code>1 &lt;= candies[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= keys[i].length &lt;= status.length</code></li>
	<li><code>0 &lt;= keys[i][j] &lt; status.length</code></li>
	<li><code>keys[i]</code>&nbsp;中的值都是互不相同的。</li>
	<li><code>0 &lt;= containedBoxes[i].length &lt;= status.length</code></li>
	<li><code>0 &lt;= containedBoxes[i][j] &lt; status.length</code></li>
	<li><code>containedBoxes[i]</code>&nbsp;中的值都是互不相同的。</li>
	<li>每个盒子最多被一个盒子包含。</li>
	<li><code>0 &lt;= initialBoxes.length&nbsp;&lt;= status.length</code></li>
	<li><code>0 &lt;= initialBoxes[i] &lt; status.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 哈希集合

题目给定一批盒子，每个盒子可能有状态（开/关）、糖果、钥匙、以及其他盒子。我们的目标是通过初始给定的一些盒子，尽可能多地打开更多盒子，并收集其中的糖果。可以通过获得钥匙来解锁新盒子，通过盒子中嵌套的盒子来获取更多资源。

我们采用 BFS 的方式模拟整个探索过程。

我们用一个队列 $q$ 表示当前可以访问的、**已经开启** 的盒子；用两个集合 $\textit{has}$ 和 $\textit{took}$ 分别记录**我们拥有的所有盒子**和**已经处理过的盒子**，防止重复。

初始时，将所有 $\textit{initialBoxes}$ 添加到 $\textit{has}$ 中，如果初始盒子状态为开启，立即加入队列 $\textit{q}$ 并累计糖果；

然后进行 BFS，依次从 $\textit{q}$ 中取出盒子：

-   获取盒子中的钥匙 $\textit{keys[box]}$，将能解锁的盒子加入队列；
-   收集盒子中包含的其他盒子 $\textit{containedBoxes[box]}$，如果状态是开启的且未处理过，则立即处理；

每个盒子最多处理一次，糖果累计一次，最终返回总糖果数 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是盒子的总数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxCandies(
        self,
        status: List[int],
        candies: List[int],
        keys: List[List[int]],
        containedBoxes: List[List[int]],
        initialBoxes: List[int],
    ) -> int:
        q = deque()
        has, took = set(initialBoxes), set()
        ans = 0

        for box in initialBoxes:
            if status[box]:
                q.append(box)
                took.add(box)
                ans += candies[box]
        while q:
            box = q.popleft()
            for k in keys[box]:
                if not status[k]:
                    status[k] = 1
                    if k in has and k not in took:
                        q.append(k)
                        took.add(k)
                        ans += candies[k]

            for b in containedBoxes[box]:
                has.add(b)
                if status[b] and b not in took:
                    q.append(b)
                    took.add(b)
                    ans += candies[b]
        return ans
```

#### Java

```java
class Solution {
    public int maxCandies(
        int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Deque<Integer> q = new ArrayDeque<>();
        Set<Integer> has = new HashSet<>();
        Set<Integer> took = new HashSet<>();
        int ans = 0;
        for (int box : initialBoxes) {
            has.add(box);
            if (status[box] == 1) {
                q.offer(box);
                took.add(box);
                ans += candies[box];
            }
        }
        while (!q.isEmpty()) {
            int box = q.poll();
            for (int k : keys[box]) {
                if (status[k] == 0) {
                    status[k] = 1;
                    if (has.contains(k) && !took.contains(k)) {
                        q.offer(k);
                        took.add(k);
                        ans += candies[k];
                    }
                }
            }
            for (int b : containedBoxes[box]) {
                has.add(b);
                if (status[b] == 1 && !took.contains(b)) {
                    q.offer(b);
                    took.add(b);
                    ans += candies[b];
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
    int maxCandies(
        vector<int>& status,
        vector<int>& candies,
        vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes,
        vector<int>& initialBoxes) {
        queue<int> q;
        unordered_set<int> has, took;
        int ans = 0;

        for (int box : initialBoxes) {
            has.insert(box);
            if (status[box]) {
                q.push(box);
                took.insert(box);
                ans += candies[box];
            }
        }

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            for (int k : keys[box]) {
                if (!status[k]) {
                    status[k] = 1;
                    if (has.count(k) && !took.count(k)) {
                        q.push(k);
                        took.insert(k);
                        ans += candies[k];
                    }
                }
            }

            for (int b : containedBoxes[box]) {
                has.insert(b);
                if (status[b] && !took.count(b)) {
                    q.push(b);
                    took.insert(b);
                    ans += candies[b];
                }
            }
        }

        return ans;
    }
};
```

#### Go

```go
func maxCandies(status []int, candies []int, keys [][]int, containedBoxes [][]int, initialBoxes []int) (ans int) {
	q := []int{}
	has := make(map[int]bool)
	took := make(map[int]bool)
	for _, box := range initialBoxes {
		has[box] = true
		if status[box] == 1 {
			q = append(q, box)
			took[box] = true
			ans += candies[box]
		}
	}
	for len(q) > 0 {
		box := q[0]
		q = q[1:]
		for _, k := range keys[box] {
			if status[k] == 0 {
				status[k] = 1
				if has[k] && !took[k] {
					q = append(q, k)
					took[k] = true
					ans += candies[k]
				}
			}
		}
		for _, b := range containedBoxes[box] {
			has[b] = true
			if status[b] == 1 && !took[b] {
				q = append(q, b)
				took[b] = true
				ans += candies[b]
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function maxCandies(
    status: number[],
    candies: number[],
    keys: number[][],
    containedBoxes: number[][],
    initialBoxes: number[],
): number {
    const q: number[] = [];
    const has: Set<number> = new Set();
    const took: Set<number> = new Set();
    let ans = 0;

    for (const box of initialBoxes) {
        has.add(box);
        if (status[box] === 1) {
            q.push(box);
            took.add(box);
            ans += candies[box];
        }
    }

    while (q.length > 0) {
        const box = q.pop()!;

        for (const k of keys[box]) {
            if (status[k] === 0) {
                status[k] = 1;
                if (has.has(k) && !took.has(k)) {
                    q.push(k);
                    took.add(k);
                    ans += candies[k];
                }
            }
        }

        for (const b of containedBoxes[box]) {
            has.add(b);
            if (status[b] === 1 && !took.has(b)) {
                q.push(b);
                took.add(b);
                ans += candies[b];
            }
        }
    }

    return ans;
}
```

#### Rust

```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn max_candies(
        mut status: Vec<i32>,
        candies: Vec<i32>,
        keys: Vec<Vec<i32>>,
        contained_boxes: Vec<Vec<i32>>,
        initial_boxes: Vec<i32>,
    ) -> i32 {
        let mut q: VecDeque<i32> = VecDeque::new();
        let mut has: HashSet<i32> = HashSet::new();
        let mut took: HashSet<i32> = HashSet::new();
        let mut ans = 0;

        for &box_ in &initial_boxes {
            has.insert(box_);
            if status[box_ as usize] == 1 {
                q.push_back(box_);
                took.insert(box_);
                ans += candies[box_ as usize];
            }
        }

        while let Some(box_) = q.pop_front() {
            for &k in &keys[box_ as usize] {
                if status[k as usize] == 0 {
                    status[k as usize] = 1;
                    if has.contains(&k) && !took.contains(&k) {
                        q.push_back(k);
                        took.insert(k);
                        ans += candies[k as usize];
                    }
                }
            }

            for &b in &contained_boxes[box_ as usize] {
                has.insert(b);
                if status[b as usize] == 1 && !took.contains(&b) {
                    q.push_back(b);
                    took.insert(b);
                    ans += candies[b as usize];
                }
            }
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

# [1299. 将每个元素替换为右侧最大元素](https://leetcode.cn/problems/replace-elements-with-greatest-element-on-right-side){#1299}

{{< tabs "1299" >}}

{{% tab "python" %}}
```python
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        mx = -1
        for i in reversed(range(len(arr))):
            x = arr[i]
            arr[i] = mx
            mx = max(mx, x)
        return arr
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] replaceElements(int[] arr) {
        for (int i = arr.length - 1, mx = -1; i >= 0; --i) {
            int x = arr[i];
            arr[i] = mx;
            mx = Math.max(mx, x);
        }
        return arr;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = arr.size() - 1, mx = -1; ~i; --i) {
            int x = arr[i];
            arr[i] = mx;
            mx = max(mx, x);
        }
        return arr;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func replaceElements(arr []int) []int {
	for i, mx := len(arr)-1, -1; i >= 0; i-- {
		x := arr[i]
		arr[i] = mx
		mx = max(mx, x)
	}
	return arr
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function replaceElements(arr: number[]): number[] {
    for (let i = arr.length - 1, mx = -1; ~i; --i) {
        const x = arr[i];
        arr[i] = mx;
        mx = Math.max(mx, x);
    }
    return arr;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>arr</code> ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 <code>-1</code> 替换。</p>

<p>完成所有替换操作后，请你返回这个数组。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [17,18,5,4,6,1]
<strong>输出：</strong>[18,6,6,6,1,-1]
<strong>解释：</strong>
- 下标 0 的元素 --> 右侧最大元素是下标 1 的元素 (18)
- 下标 1 的元素 --> 右侧最大元素是下标 4 的元素 (6)
- 下标 2 的元素 --> 右侧最大元素是下标 4 的元素 (6)
- 下标 3 的元素 --> 右侧最大元素是下标 4 的元素 (6)
- 下标 4 的元素 --> 右侧最大元素是下标 5 的元素 (1)
- 下标 5 的元素 --> 右侧没有其他元素，替换为 -1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [400]
<strong>输出：</strong>[-1]
<strong>解释：</strong>下标<strong> </strong>0 的元素右侧没有其他元素。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= arr[i] <= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逆序遍历

我们用一个变量 $mx$ 记录当前位置右侧的最大值，初始时 $mx = -1$。

然后我们从右向左遍历数组，对于每个位置 $i$，我们记当前位置的值为 $x$，将当前位置的值更新为 $mx$，然后更新 $mx = \max(mx, x)$。

最后返回原数组即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        mx = -1
        for i in reversed(range(len(arr))):
            x = arr[i]
            arr[i] = mx
            mx = max(mx, x)
        return arr
```

#### Java

```java
class Solution {
    public int[] replaceElements(int[] arr) {
        for (int i = arr.length - 1, mx = -1; i >= 0; --i) {
            int x = arr[i];
            arr[i] = mx;
            mx = Math.max(mx, x);
        }
        return arr;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for (int i = arr.size() - 1, mx = -1; ~i; --i) {
            int x = arr[i];
            arr[i] = mx;
            mx = max(mx, x);
        }
        return arr;
    }
};
```

#### Go

```go
func replaceElements(arr []int) []int {
	for i, mx := len(arr)-1, -1; i >= 0; i-- {
		x := arr[i]
		arr[i] = mx
		mx = max(mx, x)
	}
	return arr
}
```

#### TypeScript

```ts
function replaceElements(arr: number[]): number[] {
    for (let i = arr.length - 1, mx = -1; ~i; --i) {
        const x = arr[i];
        arr[i] = mx;
        mx = Math.max(mx, x);
    }
    return arr;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
