---
title: "3060_时间范围内的用户活动 🔒"
date: 2025-10-08T18:39:55+08:00
weight: 7
tags: [交互, 位运算, 动态规划, 哈希表, 堆（优先队列）, 排序, 数据库, 数组, 树, 模拟, 深度优先搜索, 计数, 贪心, 链表]
---

{{< markmap >}}
### [3060_时间范围内的用户活动 🔒](#3060)
#### [数据库](#3060)
### [3061_计算滞留雨水 🔒](#3061)
#### [数据库](#3061)
### [3062_链表游戏的获胜者 🔒](#3062)
#### [链表](#3062)
### [3063_链表频率 🔒](#3063)
#### [哈希表](#3063)
#### [链表](#3063)
#### [计数](#3063)
### [3064_使用按位查询猜测数字 I 🔒](#3064)
#### [位运算](#3064)
#### [交互](#3064)
### [3065_超过阈值的最少操作数 I](#3065)
#### [数组](#3065)
### [3066_超过阈值的最少操作数 II](#3066)
#### [数组](#3066)
#### [模拟](#3066)
#### [堆（优先队列）](#3066)
### [3067_在带权树网络中统计可连接服务器对数目](#3067)
#### [树](#3067)
#### [深度优先搜索](#3067)
#### [数组](#3067)
### [3068_最大节点价值之和](#3068)
#### [贪心](#3068)
#### [位运算](#3068)
#### [树](#3068)
#### [数组](#3068)
#### [动态规划](#3068)
#### [排序](#3068)
### [3069_将元素分配到两个数组中 I](#3069)
#### [数组](#3069)
#### [模拟](#3069)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3060_时间范围内的用户活动 🔒
___
#### 数据库
---
### 3061_计算滞留雨水 🔒
___
#### 数据库
---
### 3062_链表游戏的获胜者 🔒
___
#### 链表
---
### 3063_链表频率 🔒
___
#### 哈希表
___
#### 链表
___
#### 计数
---
### 3064_使用按位查询猜测数字 I 🔒
___
#### 位运算
___
#### 交互
---
### 3065_超过阈值的最少操作数 I
___
#### 数组
---
### 3066_超过阈值的最少操作数 II
___
#### 数组
___
#### 模拟
___
#### 堆（优先队列）
---
### 3067_在带权树网络中统计可连接服务器对数目
___
#### 树
___
#### 深度优先搜索
___
#### 数组
---
### 3068_最大节点价值之和
___
#### 贪心
___
#### 位运算
___
#### 树
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 3069_将元素分配到两个数组中 I
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 交互 | 位运算 | 动态规划 |
| 哈希表 | 堆（优先队列） | 排序 |
| 数据库 | 数组 | 树 |
| 模拟 | 深度优先搜索 | 计数 |
| 贪心 | 链表 |  |

# [3060. 时间范围内的用户活动 🔒](https://leetcode.cn/problems/user-activities-within-time-bounds){#3060}

{{< tabs "3060" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            session_start,
            LAG(session_end) OVER (
                PARTITION BY user_id, session_type
                ORDER BY session_end
            ) AS prev_session_end
        FROM Sessions
    )
SELECT DISTINCT
    user_id
FROM T
WHERE TIMESTAMPDIFF(HOUR, prev_session_end, session_start) <= 12;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def user_activities(sessions: pd.DataFrame) -> pd.DataFrame:
    sessions = sessions.sort_values(by=["user_id", "session_start"])
    sessions["prev_session_end"] = sessions.groupby(["user_id", "session_type"])[
        "session_end"
    ].shift(1)
    sessions_filtered = sessions[
        sessions["session_start"] - sessions["prev_session_end"]
        <= pd.Timedelta(hours=12)
    ]
    return pd.DataFrame({"user_id": sessions_filtered["user_id"].unique()})
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Sessions</code></p>

<pre>
+---------------+----------+
| Column Name   | Type     |
+---------------+----------+
| user_id       | int      |
| session_start | datetime |
| session_end   | datetime |
| session_id    | int      |
| session_type  | enum     |
+---------------+----------+
session_id 是这张表中有不同值的列。
session_type 是 (Viewer, Streamer) 的一个 ENUM (category) 类型。
这张表包含 user id, session start, session end, session id 和 session 类型。
</pre>

<p>编写一个解决方案，以查找 <strong>至少有一个相同</strong> 类型的 <strong>连续会话</strong>（无论是“<strong>Viewer</strong>”还是“<strong>Streamer</strong>”）的 <strong>用户</strong>，会话 <strong>之间</strong> 的 <strong>最大</strong> 间隔为 <code>12</code> 小时。</p>

<p>返回结果表，以<em>&nbsp;</em><code>user_id</code><em>&nbsp;<strong>升序</strong> 排序。</em></p>

<p>结果格式如下所述。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入:</strong> 
Sessions 表:
+---------+---------------------+---------------------+------------+--------------+
| user_id | session_start       | session_end         | session_id | session_type | 
+---------+---------------------+---------------------+------------+--------------+
| 101     | 2023-11-01 08:00:00 | 2023-11-01 09:00:00 | 1          | Viewer       |  
| 101     | 2023-11-01 10:00:00 | 2023-11-01 11:00:00 | 2          | Streamer     |   
| 102     | 2023-11-01 13:00:00 | 2023-11-01 14:00:00 | 3          | Viewer       | 
| 102     | 2023-11-01 15:00:00 | 2023-11-01 16:00:00 | 4          | Viewer       | 
| 101     | 2023-11-02 09:00:00 | 2023-11-02 10:00:00 | 5          | Viewer       | 
| 102     | 2023-11-02 12:00:00 | 2023-11-02 13:00:00 | 6          | Streamer     | 
| 101     | 2023-11-02 13:00:00 | 2023-11-02 14:00:00 | 7          | Streamer     | 
| 102     | 2023-11-02 16:00:00 | 2023-11-02 17:00:00 | 8          | Viewer       | 
| 103     | 2023-11-01 08:00:00 | 2023-11-01 09:00:00 | 9          | Viewer       | 
| 103     | 2023-11-02 20:00:00 | 2023-11-02 23:00:00 | 10         | Viewer       | 
| 103     | 2023-11-03 09:00:00 | 2023-11-03 10:00:00 | 11         | Viewer       | 
+---------+---------------------+---------------------+------------+--------------+
<strong>输出:</strong> 
+---------+
| user_id |
+---------+
| 102     |
| 103     |
+---------+
<strong>解释:</strong>
- 用户 ID 101 将不会包含在最终输出中，因为他们没有相同会话类型的连续回话。
- 用户 ID 102 将会包含在最终输出中，因为他们分别有两个 session ID 为 3 和 4 的 viewer 会话，并且时间间隔在 12 小时内。
- 用户 ID 103 参与了两次 viewer 会话，间隔不到 12 小时，会话 ID 为 10 和 11。因此，用户 103 将会被包含在最终输出中。
输出表根据 user_id 升序排列。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + 时间函数

我们先使用 `LAG` 窗口函数，找到每个用户相同类型的会话的上一个会话的结束时间，记为 `prev_session_end`。然后我们使用 `TIMESTAMPDIFF` 函数计算当前会话的开始时间与上一个会话的结束时间的时间差，如果时间差小于等于 12 小时，那么这个用户就符合题目要求。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            user_id,
            session_start,
            LAG(session_end) OVER (
                PARTITION BY user_id, session_type
                ORDER BY session_end
            ) AS prev_session_end
        FROM Sessions
    )
SELECT DISTINCT
    user_id
FROM T
WHERE TIMESTAMPDIFF(HOUR, prev_session_end, session_start) <= 12;
```

#### Python3

```python
import pandas as pd


def user_activities(sessions: pd.DataFrame) -> pd.DataFrame:
    sessions = sessions.sort_values(by=["user_id", "session_start"])
    sessions["prev_session_end"] = sessions.groupby(["user_id", "session_type"])[
        "session_end"
    ].shift(1)
    sessions_filtered = sessions[
        sessions["session_start"] - sessions["prev_session_end"]
        <= pd.Timedelta(hours=12)
    ]
    return pd.DataFrame({"user_id": sessions_filtered["user_id"].unique()})
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3061. 计算滞留雨水 🔒](https://leetcode.cn/problems/calculate-trapping-rain-water){#3061}

{{< tabs "3061" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            MAX(height) OVER (ORDER BY id) AS l,
            MAX(height) OVER (ORDER BY id DESC) AS r
        FROM Heights
    )
SELECT SUM(LEAST(l, r) - height) AS total_trapped_water
FROM T;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def calculate_trapped_rain_water(heights: pd.DataFrame) -> pd.DataFrame:
    heights["l"] = heights["height"].cummax()
    heights["r"] = heights["height"][::-1].cummax()[::-1]
    heights["trapped_water"] = heights[["l", "r"]].min(axis=1) - heights["height"]
    return pd.DataFrame({"total_trapped_water": [heights["trapped_water"].sum()]})
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<font face="monospace">Heights</font></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| height      | int  |
+-------------+------+
id 是这张表的主键（值互不相同的列），并且保证有序。
这张表的每一行都包含 id 和 height。
</pre>

<p>编写一个解决方案来计算景观中 <strong>沙洲之间</strong> 可以滞留的雨水量，认为每个沙洲的 <strong>宽度</strong> 为 <code>1</code> 个单位。</p>

<p>以 <strong>任何</strong> 顺序返回结果表。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>输入:</strong> 
Heights table:
+-----+--------+
| id  | height |
+-----+--------+
| 1   | 0      |
| 2   | 1      |
| 3   | 0      |
| 4   | 2      |
| 5   | 1      |
| 6   | 0      |
| 7   | 1      |
| 8   | 3      |
| 9   | 2      |
| 10  | 1      |
| 11  | 2      |
| 12  | 1      |
+-----+--------+
<strong>输出:</strong> 
+---------------------+
| total_trapped_water | 
+---------------------+
| 6                   | 
+---------------------+
<strong>解释:</strong> 
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3061.Calculate%20Trapping%20Rain%20Water/images/1709609248-wtdiVm-image.png" style="width: 500px; height: 202px;" />

上面描绘的高度图(在黑色部分)以图形表示，x 轴表示 id，y 轴表示 heights [0,1,0,2,1,0,1,3,2,1,2,1]。在这个场景中，在蓝色部分滞留了 6 个单位的雨水。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + 求和

我们使用窗口函数 `MAX(height) OVER (ORDER BY id)` 来计算每个位置及其左边的最大高度，使用 `MAX(height) OVER (ORDER BY id DESC)` 来计算每个位置及其右边的最大高度，分别记为 `l` 和 `r`。那么每个位置上的蓄水量就是 `min(l, r) - height`，最后求和即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            MAX(height) OVER (ORDER BY id) AS l,
            MAX(height) OVER (ORDER BY id DESC) AS r
        FROM Heights
    )
SELECT SUM(LEAST(l, r) - height) AS total_trapped_water
FROM T;
```

#### Python3

```python
import pandas as pd


def calculate_trapped_rain_water(heights: pd.DataFrame) -> pd.DataFrame:
    heights["l"] = heights["height"].cummax()
    heights["r"] = heights["height"][::-1].cummax()[::-1]
    heights["trapped_water"] = heights[["l", "r"]].min(axis=1) - heights["height"]
    return pd.DataFrame({"total_trapped_water": [heights["trapped_water"].sum()]})
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3062. 链表游戏的获胜者 🔒](https://leetcode.cn/problems/winner-of-the-linked-list-game){#3062}

{{< tabs "3062" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def gameResult(self, head: Optional[ListNode]) -> str:
        odd = even = 0
        while head:
            a = head.val
            b = head.next.val
            odd += a < b
            even += a > b
            head = head.next.next
        if odd > even:
            return "Odd"
        if odd < even:
            return "Even"
        return "Tie"
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
    public String gameResult(ListNode head) {
        int odd = 0, even = 0;
        for (; head != null; head = head.next.next) {
            int a = head.val;
            int b = head.next.val;
            odd += a < b ? 1 : 0;
            even += a > b ? 1 : 0;
        }
        if (odd > even) {
            return "Odd";
        }
        if (odd < even) {
            return "Even";
        }
        return "Tie";
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
    string gameResult(ListNode* head) {
        int odd = 0, even = 0;
        for (; head != nullptr; head = head->next->next) {
            int a = head->val;
            int b = head->next->val;
            odd += a < b;
            even += a > b;
        }
        if (odd > even) {
            return "Odd";
        }
        if (odd < even) {
            return "Even";
        }
        return "Tie";
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
func gameResult(head *ListNode) string {
	var odd, even int
	for ; head != nil; head = head.Next.Next {
		a, b := head.Val, head.Next.Val
		if a < b {
			odd++
		}
		if a > b {
			even++
		}
	}
	if odd > even {
		return "Odd"
	}
	if odd < even {
		return "Even"
	}
	return "Tie"
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

function gameResult(head: ListNode | null): string {
    let [odd, even] = [0, 0];
    for (; head; head = head.next.next) {
        const [a, b] = [head.val, head.next.val];
        odd += a < b ? 1 : 0;
        even += a > b ? 1 : 0;
    }
    if (odd > even) {
        return 'Odd';
    }
    if (odd < even) {
        return 'Even';
    }
    return 'Tie';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定长度为 <strong>偶数</strong>&nbsp;，包含整数的链表的&nbsp;<code>head</code>&nbsp;节点。</p>

<p>每个 <strong>奇数编号</strong> 的节点包含一个奇数，并且每个 <strong>偶数编号</strong> 的节点包含一个偶数。</p>

<p>我们把每个偶数编号的节点和它的下一个节点叫做一个 <strong>对</strong>，例如编号为&nbsp;<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;的节点是一对，编号为 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">2</span></font>&nbsp;和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">3</span></font>&nbsp;的节点是一对，以此类推。</p>

<p>对于每个 <strong>对</strong>，我们比较对中节点的值：</p>

<ul>
	<li>如果奇数节点更大，<code>"Odd"</code>&nbsp;队得一分。</li>
	<li>如果偶数节点更大，<code>"Even"</code>&nbsp;队得一分。</li>
</ul>

<p>返回分数更 <strong>高</strong> 的队名，如果分数相同，返回&nbsp;<code>"Tie"</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>head = [2,1]
<strong>输出：</strong>"Even"
<strong>解释：</strong>链表中只有一个对 (2,1)。因为 2 &gt; 1，偶数队得分。
因此，答案是 "Even"。
</pre>

<p>&nbsp;</p>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = [2,5,4,7,20,5] 
<strong>输出：</strong>"Odd" 
<strong>解释：</strong>此链表中有 3 对。让我们分别对每一对进行分析： 
(2,5) -&gt; 因为 2 &lt; 5，奇数队得分。
(4,7) -&gt; 因为 4 &lt; 7，奇数队得分。 
(20,5) -&gt; 因为 20 &gt; 5，偶数队得分。 
奇数队得 2 分，偶数队得 1 分，奇数队得分更高。 
因此，答案是 "Odd"。
</pre>

<p>&nbsp;</p>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [4,5,2,1]
<strong>输出：</strong>"Tie"
<strong>解释：</strong>此链表中有 2 对。让我们分别对每一对进行分析：
(4,5) -&gt; 因为 4 &lt; 5，奇数队得分。
(2,1) -&gt; 因为 2 &gt; 1，偶数队得分。
每队得 1 分。
因此，答案是 "Tie"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数字在范围&nbsp;<code>[2, 100]</code>&nbsp;内。</li>
	<li>链表中的节点数为偶数。</li>
	<li><code>1 &lt;= Node.val &lt;= 100</code></li>
	<li>每个奇数编号节点的值都是奇数。</li>
	<li>每个偶数编号节点的值都是偶数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

遍历链表，每次取出两个节点，比较它们的值，然后根据比较结果更新奇数和偶数的得分。最后比较奇数和偶数的得分，返回结果。

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
    def gameResult(self, head: Optional[ListNode]) -> str:
        odd = even = 0
        while head:
            a = head.val
            b = head.next.val
            odd += a < b
            even += a > b
            head = head.next.next
        if odd > even:
            return "Odd"
        if odd < even:
            return "Even"
        return "Tie"
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
    public String gameResult(ListNode head) {
        int odd = 0, even = 0;
        for (; head != null; head = head.next.next) {
            int a = head.val;
            int b = head.next.val;
            odd += a < b ? 1 : 0;
            even += a > b ? 1 : 0;
        }
        if (odd > even) {
            return "Odd";
        }
        if (odd < even) {
            return "Even";
        }
        return "Tie";
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
    string gameResult(ListNode* head) {
        int odd = 0, even = 0;
        for (; head != nullptr; head = head->next->next) {
            int a = head->val;
            int b = head->next->val;
            odd += a < b;
            even += a > b;
        }
        if (odd > even) {
            return "Odd";
        }
        if (odd < even) {
            return "Even";
        }
        return "Tie";
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
func gameResult(head *ListNode) string {
	var odd, even int
	for ; head != nil; head = head.Next.Next {
		a, b := head.Val, head.Next.Val
		if a < b {
			odd++
		}
		if a > b {
			even++
		}
	}
	if odd > even {
		return "Odd"
	}
	if odd < even {
		return "Even"
	}
	return "Tie"
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

function gameResult(head: ListNode | null): string {
    let [odd, even] = [0, 0];
    for (; head; head = head.next.next) {
        const [a, b] = [head.val, head.next.val];
        odd += a < b ? 1 : 0;
        even += a > b ? 1 : 0;
    }
    if (odd > even) {
        return 'Odd';
    }
    if (odd < even) {
        return 'Even';
    }
    return 'Tie';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3063. 链表频率 🔒](https://leetcode.cn/problems/linked-list-frequency){#3063}

{{< tabs "3063" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = Counter()
        while head:
            cnt[head.val] += 1
            head = head.next
        dummy = ListNode()
        for val in cnt.values():
            dummy.next = ListNode(val, dummy.next)
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
    public ListNode frequenciesOfElements(ListNode head) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (; head != null; head = head.next) {
            cnt.merge(head.val, 1, Integer::sum);
        }
        ListNode dummy = new ListNode();
        for (int val : cnt.values()) {
            dummy.next = new ListNode(val, dummy.next);
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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> cnt;
        for (; head; head = head->next) {
            cnt[head->val]++;
        }
        ListNode* dummy = new ListNode();
        for (auto& [_, val] : cnt) {
            dummy->next = new ListNode(val, dummy->next);
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
func frequenciesOfElements(head *ListNode) *ListNode {
	cnt := map[int]int{}
	for ; head != nil; head = head.Next {
		cnt[head.Val]++
	}
	dummy := &ListNode{}
	for _, val := range cnt {
		dummy.Next = &ListNode{val, dummy.Next}
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

function frequenciesOfElements(head: ListNode | null): ListNode | null {
    const cnt: Map<number, number> = new Map();
    for (; head; head = head.next) {
        cnt.set(head.val, (cnt.get(head.val) || 0) + 1);
    }
    const dummy = new ListNode();
    for (const val of cnt.values()) {
        dummy.next = new ListNode(val, dummy.next);
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

<p>给定包含 <code>k</code> 个&nbsp;<strong>不同&nbsp;</strong>元素的链表的&nbsp;<code>head</code>&nbsp;节点，创建一个长度为&nbsp;<code>k</code>&nbsp;的链表，以 <strong>任何顺序</strong> 返回链表中所有 <strong>不同元素</strong> 出现的 <strong>频率</strong>。返回这个链表的头节点。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1: </strong></p>

<pre>
输入：head = [1,1,2,1,2,3]

输出：[3,2,1]

解释：列表中有 3 个不同的元素。1 的频率是 3，2 的频率是 2，3 的频率是 1。因此，我们返回 3 -&gt; 2 -&gt; 1。

注意 1 -&gt; 2 -&gt; 3，1 -&gt; 3 -&gt; 2，2 -&gt; 1 -&gt; 3，2 -&gt; 3 -&gt; 1，和 3 -&gt; 1 -&gt; 2 都是合法的答案。
</pre>

<p><strong class="example">示例 2: </strong></p>

<pre>
输入：head = [1,1,2,2,2]

输出：[2,3]

解释：列表中有 2 个不同的元素。1 和 2 出现的频率是 2 和 3。因此，我们返回 2 -&gt; 3。
</pre>

<p><strong class="example">示例 3: </strong></p>

<pre>
输入：head = [6,5,4,3,2,1]

输出：[1,1,1,1,1,1]

解释：列表中有 6 个不同的元素。每个元素的频率是 1。因此，我们返回 1 -&gt; 1 -&gt; 1 -&gt; 1 -&gt; 1 -&gt; 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中的节点数字范围在&nbsp;<code>[1, 10<sup>5</sup>]</code>之间。</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $cnt$ 记录链表中每个元素值出现的次数，然后再遍历哈希表的值构造新的链表即可。

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
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = Counter()
        while head:
            cnt[head.val] += 1
            head = head.next
        dummy = ListNode()
        for val in cnt.values():
            dummy.next = ListNode(val, dummy.next)
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
    public ListNode frequenciesOfElements(ListNode head) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (; head != null; head = head.next) {
            cnt.merge(head.val, 1, Integer::sum);
        }
        ListNode dummy = new ListNode();
        for (int val : cnt.values()) {
            dummy.next = new ListNode(val, dummy.next);
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
    ListNode* frequenciesOfElements(ListNode* head) {
        unordered_map<int, int> cnt;
        for (; head; head = head->next) {
            cnt[head->val]++;
        }
        ListNode* dummy = new ListNode();
        for (auto& [_, val] : cnt) {
            dummy->next = new ListNode(val, dummy->next);
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
func frequenciesOfElements(head *ListNode) *ListNode {
	cnt := map[int]int{}
	for ; head != nil; head = head.Next {
		cnt[head.Val]++
	}
	dummy := &ListNode{}
	for _, val := range cnt {
		dummy.Next = &ListNode{val, dummy.Next}
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

function frequenciesOfElements(head: ListNode | null): ListNode | null {
    const cnt: Map<number, number> = new Map();
    for (; head; head = head.next) {
        cnt.set(head.val, (cnt.get(head.val) || 0) + 1);
    }
    const dummy = new ListNode();
    for (const val of cnt.values()) {
        dummy.next = new ListNode(val, dummy.next);
    }
    return dummy.next;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3064. 使用按位查询猜测数字 I 🔒](https://leetcode.cn/problems/guess-the-number-using-bitwise-questions-i){#3064}

{{< tabs "3064" >}}

{{% tab "python" %}}
```python
# Definition of commonSetBits API.
# def commonSetBits(num: int) -> int:


class Solution:
    def findNumber(self) -> int:
        return sum(1 << i for i in range(32) if commonSetBits(1 << i))
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i) > 0) {
                n |= 1 << i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i)) {
                n |= 1 << i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition of commonSetBits API.
 * func commonSetBits(num int) int;
 */

func findNumber() (n int) {
	for i := 0; i < 32; i++ {
		if commonSetBits(1<<i) > 0 {
			n |= 1 << i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition of commonSetBits API.
 * var commonSetBits = function(num: number): number {}
 */

function findNumber(): number {
    let n = 0;
    for (let i = 0; i < 32; ++i) {
        if (commonSetBits(1 << i)) {
            n |= 1 << i;
        }
    }
    return n;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要找到一个数字&nbsp;<code>n</code>。</p>

<p>这里有一个预定义的 API&nbsp;<code>int commonSetBits(int num)</code>，它返回&nbsp;<code>n</code> 和 <code>num</code> 在二进制表示的同一位置上都是 1 的位数。换句话说，它返回&nbsp;<code>n &amp; num</code>&nbsp;的 <span data-keyword="set-bit">设置位</span> 数量，其中&nbsp;<code>&amp;</code>&nbsp;是按位&nbsp;<code>AND</code>&nbsp;运算符。</p>

<p>返回数字&nbsp;<code>n</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 31

<strong>输出：</strong>31

<strong>解释：</strong>能够证明使用给定的 API 找到 31 是可能的。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 33

<strong>输出：</strong>33

<strong>解释：</strong>能够证明使用给定的 API 找到 33 是可能的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>30</sup> - 1</code></li>
	<li><code>0 &lt;= num &lt;= 2<sup>30</sup> - 1</code></li>
	<li>如果你查询的&nbsp;<code>num</code>&nbsp;超出了给定的范围，输出就不可靠。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举 $2$ 的幂次方，然后调用 `commonSetBits` 方法，如果返回值大于 $0$，则说明 $n$ 的二进制表示中的对应位是 $1$。

时间复杂度 $O(\log n)$，本题中 $n \le 2^{30}$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition of commonSetBits API.
# def commonSetBits(num: int) -> int:


class Solution:
    def findNumber(self) -> int:
        return sum(1 << i for i in range(32) if commonSetBits(1 << i))
```

#### Java

```java
/**
 * Definition of commonSetBits API (defined in the parent class Problem).
 * int commonSetBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i) > 0) {
                n |= 1 << i;
            }
        }
        return n;
    }
}
```

#### C++

```cpp
/**
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            if (commonSetBits(1 << i)) {
                n |= 1 << i;
            }
        }
        return n;
    }
};
```

#### Go

```go
/**
 * Definition of commonSetBits API.
 * func commonSetBits(num int) int;
 */

func findNumber() (n int) {
	for i := 0; i < 32; i++ {
		if commonSetBits(1<<i) > 0 {
			n |= 1 << i
		}
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition of commonSetBits API.
 * var commonSetBits = function(num: number): number {}
 */

function findNumber(): number {
    let n = 0;
    for (let i = 0; i < 32; ++i) {
        if (commonSetBits(1 << i)) {
            n |= 1 << i;
        }
    }
    return n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3065. 超过阈值的最少操作数 I](https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-i){#3065}

{{< tabs "3065" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(x < k for x in nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        for (int x : nums) {
            if (x < k) {
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
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int x : nums) {
            if (x < k) {
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
func minOperations(nums []int, k int) (ans int) {
	for _, x := range nums {
		if x < k {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], k: number): number {
    return nums.filter(x => x < k).length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <b>0</b>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一次操作中，你可以删除 <code>nums</code>&nbsp;中的最小元素。</p>

<p>你需要使数组中的所有元素都大于或等于 <code>k</code>&nbsp;，请你返回需要的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,11,10,1,3], k = 10
<b>输出：</b>3
<b>解释：</b>第一次操作后，nums 变为 [2, 11, 10, 3] 。
第二次操作后，nums 变为 [11, 10, 3] 。
第三次操作后，nums 变为 [11, 10] 。
此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。
使数组中所有元素都大于等于 10 需要的最少操作次数为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,2,4,9], k = 1
<b>输出：</b>0
<b>解释：</b>数组中的所有元素都大于等于 1 ，所以不需要对 nums 做任何操作。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,2,4,9], k = 9
<b>输出：</b>4
<b>解释：</b>nums 中只有一个元素大于等于 9 ，所以需要执行 4 次操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>输入保证至少有一个满足&nbsp;<code>nums[i] &gt;= k</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;存在。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们只需要遍历一遍数组，统计小于 $k$ 的元素个数即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(x < k for x in nums)
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int k) {
        int ans = 0;
        for (int x : nums) {
            if (x < k) {
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
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int x : nums) {
            if (x < k) {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int, k int) (ans int) {
	for _, x := range nums {
		if x < k {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minOperations(nums: number[], k: number): number {
    return nums.filter(x => x < k).length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3066. 超过阈值的最少操作数 II](https://leetcode.cn/problems/minimum-operations-to-exceed-threshold-value-ii){#3066}

{{< tabs "3066" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapify(nums)
        ans = 0
        while len(nums) > 1 and nums[0] < k:
            x, y = heappop(nums), heappop(nums)
            heappush(nums, x * 2 + y)
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int x : nums) {
            pq.offer((long) x);
        }
        int ans = 0;
        for (; pq.size() > 1 && pq.peek() < k; ++ans) {
            long x = pq.poll(), y = pq.poll();
            pq.offer(x * 2 + y);
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
    int minOperations(vector<int>& nums, int k) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        int ans = 0;
        for (; pq.size() > 1 && pq.top() < k; ++ans) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            pq.push(x * 2 + y);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, k int) (ans int) {
	pq := &hp{nums}
	heap.Init(pq)
	for ; pq.Len() > 1 && pq.IntSlice[0] < k; ans++ {
		x, y := heap.Pop(pq).(int), heap.Pop(pq).(int)
		heap.Push(pq, x*2+y)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Pop() interface{} {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[0 : n-1]
	return x
}
func (h *hp) Push(x interface{}) {
	h.IntSlice = append(h.IntSlice, x.(int))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], k: number): number {
    const pq = new MinPriorityQueue();
    for (const x of nums) {
        pq.enqueue(x);
    }
    let ans = 0;
    for (; pq.size() > 1 && pq.front().element < k; ++ans) {
        const x = pq.dequeue().element;
        const y = pq.dequeue().element;
        pq.enqueue(x * 2 + y);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut pq = BinaryHeap::new();

        for &x in &nums {
            pq.push(-(x as i64));
        }

        let mut ans = 0;

        while pq.len() > 1 && -pq.peek().unwrap() < k as i64 {
            let x = -pq.pop().unwrap();
            let y = -pq.pop().unwrap();
            pq.push(-(x * 2 + y));
            ans += 1;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以对&nbsp;<code>nums</code>&nbsp;执行一些操作，在一次操作中，你可以：</p>

<ul>
	<li>选择 <code>nums</code>&nbsp;中 <strong>最小</strong> 的两个整数&nbsp;<code>x</code> 和&nbsp;<code>y</code>&nbsp;。</li>
	<li>将&nbsp;<code>x</code> 和&nbsp;<code>y</code> 从&nbsp;<code>nums</code>&nbsp;中删除。</li>
	<li>将&nbsp;<code>min(x, y) * 2 + max(x, y)</code>&nbsp;添加到数组中的任意位置。</li>
</ul>

<p><b>注意，</b>只有当&nbsp;<code>nums</code>&nbsp;<strong>至少</strong> 包含两个元素时，你才可以执行以上操作。</p>

<p>你需要使数组中的所有元素都 <strong>大于或等于</strong>&nbsp;<code>k</code>&nbsp;，请你返回需要的&nbsp;<strong>最少</strong>&nbsp;操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><b>输入：</b>nums = [2,11,10,1,3], k = 10</p>

<p><b>输出：</b>2</p>

<p><b>解释：</b></p>

<ol>
	<li>第一次操作中，我们删除元素 1 和 2 ，然后添加 <code>1 * 2 + 2</code> 到 <code>nums</code> 中，<code>nums</code> 变为 <code>[4, 11, 10, 3]</code> 。</li>
	<li>第二次操作中，我们删除元素 3 和 4 ，然后添加 <code>3 * 2 + 4</code> 到 <code>nums</code> 中，<code>nums</code> 变为 <code>[10, 11, 10]</code> 。</li>
</ol>

<p>此时，数组中的所有元素都大于等于 10 ，所以我们停止操作。</p>

<p>可以证明使数组中所有元素都大于等于 10 需要的最少操作次数为 2 。</p>

<p>&nbsp;</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><b>输入：</b>nums = [1,1,2,4,9], k = 20</p>

<p><b>输出：</b>4</p>

<p><b>解释：</b></p>

<ol>
	<li>第一次操作后，<code>nums</code> 变为 <code>[2, 4, 9, 3]</code>。</li>
	<li>第二次操作后，<code>nums</code> 变为 <code>[7, 4, 9]</code>。</li>
	<li>第三次操作后，<code>nums</code> 变为 <code>[15, 9]</code>。</li>
	<li>第四次操作后，<code>nums</code> 变为 <code>[33]</code>。</li>
</ol>

<p>此时，<code>nums</code> 中的所有元素都大于等于 20 ，所以我们停止操作。</p>

<p>可以证明使数组中所有元素都大于等于 20 需要的最少操作次数为 4 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li>输入保证答案一定存在，也就是说，在进行某些次数的操作后，数组中所有元素都大于等于&nbsp;<code>k</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们可以使用优先队列（小根堆）来模拟这个过程。

具体地，我们先将数组中的元素加入优先队列 $pq$ 中。然后我们不断地从优先队列中取出两个最小的元素 $x$ 和 $y$，将 $\min(x, y) \times 2 + \max(x, y)$ 放回优先队列中。每次操作后，我们将操作次数加一。当队列中的元素个数小于 $2$ 或者队列中的最小元素大于等于 $k$ 时，我们停止操作。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapify(nums)
        ans = 0
        while len(nums) > 1 and nums[0] < k:
            x, y = heappop(nums), heappop(nums)
            heappush(nums, x * 2 + y)
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for (int x : nums) {
            pq.offer((long) x);
        }
        int ans = 0;
        for (; pq.size() > 1 && pq.peek() < k; ++ans) {
            long x = pq.poll(), y = pq.poll();
            pq.offer(x * 2 + y);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        using ll = long long;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int x : nums) {
            pq.push(x);
        }
        int ans = 0;
        for (; pq.size() > 1 && pq.top() < k; ++ans) {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            pq.push(x * 2 + y);
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int, k int) (ans int) {
	pq := &hp{nums}
	heap.Init(pq)
	for ; pq.Len() > 1 && pq.IntSlice[0] < k; ans++ {
		x, y := heap.Pop(pq).(int), heap.Pop(pq).(int)
		heap.Push(pq, x*2+y)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h *hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Pop() interface{} {
	old := h.IntSlice
	n := len(old)
	x := old[n-1]
	h.IntSlice = old[0 : n-1]
	return x
}
func (h *hp) Push(x interface{}) {
	h.IntSlice = append(h.IntSlice, x.(int))
}
```

#### TypeScript

```ts
function minOperations(nums: number[], k: number): number {
    const pq = new MinPriorityQueue();
    for (const x of nums) {
        pq.enqueue(x);
    }
    let ans = 0;
    for (; pq.size() > 1 && pq.front().element < k; ++ans) {
        const x = pq.dequeue().element;
        const y = pq.dequeue().element;
        pq.enqueue(x * 2 + y);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut pq = BinaryHeap::new();

        for &x in &nums {
            pq.push(-(x as i64));
        }

        let mut ans = 0;

        while pq.len() > 1 && -pq.peek().unwrap() < k as i64 {
            let x = -pq.pop().unwrap();
            let y = -pq.pop().unwrap();
            pq.push(-(x * 2 + y));
            ans += 1;
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

# [3067. 在带权树网络中统计可连接服务器对数目](https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network){#3067}

{{< tabs "3067" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairsOfConnectableServers(
        self, edges: List[List[int]], signalSpeed: int
    ) -> List[int]:
        def dfs(a: int, fa: int, ws: int) -> int:
            cnt = 0 if ws % signalSpeed else 1
            for b, w in g[a]:
                if b != fa:
                    cnt += dfs(b, a, ws + w)
            return cnt

        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for a, b, w in edges:
            g[a].append((b, w))
            g[b].append((a, w))
        ans = [0] * n
        for a in range(n):
            s = 0
            for b, w in g[a]:
                t = dfs(b, a, w)
                ans[a] += s * t
                s += t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int signalSpeed;
    private List<int[]>[] g;

    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length + 1;
        g = new List[n];
        this.signalSpeed = signalSpeed;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].add(new int[] {b, w});
            g[b].add(new int[] {a, w});
        }
        int[] ans = new int[n];
        for (int a = 0; a < n; ++a) {
            int s = 0;
            for (var e : g[a]) {
                int b = e[0], w = e[1];
                int t = dfs(b, a, w);
                ans[a] += s * t;
                s += t;
            }
        }
        return ans;
    }

    private int dfs(int a, int fa, int ws) {
        int cnt = ws % signalSpeed == 0 ? 1 : 0;
        for (var e : g[a]) {
            int b = e[0], w = e[1];
            if (b != fa) {
                cnt += dfs(b, a, ws + w);
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<pair<int, int>> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }
        function<int(int, int, int)> dfs = [&](int a, int fa, int ws) {
            int cnt = ws % signalSpeed == 0;
            for (auto& [b, w] : g[a]) {
                if (b != fa) {
                    cnt += dfs(b, a, ws + w);
                }
            }
            return cnt;
        };
        vector<int> ans(n);
        for (int a = 0; a < n; ++a) {
            int s = 0;
            for (auto& [b, w] : g[a]) {
                int t = dfs(b, a, w);
                ans[a] += s * t;
                s += t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairsOfConnectableServers(edges [][]int, signalSpeed int) []int {
	n := len(edges) + 1
	type pair struct{ x, w int }
	g := make([][]pair, n)
	for _, e := range edges {
		a, b, w := e[0], e[1], e[2]
		g[a] = append(g[a], pair{b, w})
		g[b] = append(g[b], pair{a, w})
	}
	var dfs func(a, fa, ws int) int
	dfs = func(a, fa, ws int) int {
		cnt := 0
		if ws%signalSpeed == 0 {
			cnt++
		}
		for _, e := range g[a] {
			b, w := e.x, e.w
			if b != fa {
				cnt += dfs(b, a, ws+w)
			}
		}
		return cnt
	}
	ans := make([]int, n)
	for a := 0; a < n; a++ {
		s := 0
		for _, e := range g[a] {
			b, w := e.x, e.w
			t := dfs(b, a, w)
			ans[a] += s * t
			s += t
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairsOfConnectableServers(edges: number[][], signalSpeed: number): number[] {
    const n = edges.length + 1;
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b, w] of edges) {
        g[a].push([b, w]);
        g[b].push([a, w]);
    }
    const dfs = (a: number, fa: number, ws: number): number => {
        let cnt = ws % signalSpeed === 0 ? 1 : 0;
        for (const [b, w] of g[a]) {
            if (b != fa) {
                cnt += dfs(b, a, ws + w);
            }
        }
        return cnt;
    };
    const ans: number[] = Array(n).fill(0);
    for (let a = 0; a < n; ++a) {
        let s = 0;
        for (const [b, w] of g[a]) {
            const t = dfs(b, a, w);
            ans[a] += s * t;
            s += t;
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

<p>给你一棵无根带权树，树中总共有 <code>n</code>&nbsp;个节点，分别表示 <code>n</code>&nbsp;个服务器，服务器从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号。同时给你一个数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, weight<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条双向边，边的权值为&nbsp;<code>weight<sub>i</sub></code>&nbsp;。再给你一个整数&nbsp;<code>signalSpeed</code>&nbsp;。</p>

<p>如果两台服务器 <code>a</code>&nbsp;和 <code>b</code>&nbsp;是通过服务器 <code>c</code>&nbsp;<strong>可连接的</strong>，则：</p>

<ul>
	<li><code>a &lt; b</code>&nbsp;，<code>a != c</code> 且&nbsp;<code>b != c</code>&nbsp;。</li>
	<li>从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>a</code>&nbsp;的距离是可以被&nbsp;<code>signalSpeed</code>&nbsp;整除的。</li>
	<li>从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>b</code>&nbsp;的距离是可以被&nbsp;<code>signalSpeed</code>&nbsp;整除的。</li>
	<li>从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>b</code>&nbsp;的路径与从&nbsp;<code>c</code>&nbsp;到&nbsp;<code>a</code>&nbsp;的路径没有任何公共边。</li>
</ul>

<p>请你返回一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>count</code>&nbsp;，其中&nbsp;<code>count[i]</code> 表示通过服务器&nbsp;<code>i</code>&nbsp;<strong>可连接</strong>&nbsp;的服务器对的&nbsp;<strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3067.Count%20Pairs%20of%20Connectable%20Servers%20in%20a%20Weighted%20Tree%20Network/images/example22.png" style="width: 438px; height: 243px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
<b>输出：</b>[0,4,6,6,4,0]
<b>解释：</b>由于 signalSpeed 等于 1 ，count[c] 等于所有从 c 开始且没有公共边的路径对数目。
在输入图中，count[c] 等于服务器 c 左边服务器数目乘以右边服务器数目。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3067.Count%20Pairs%20of%20Connectable%20Servers%20in%20a%20Weighted%20Tree%20Network/images/example11.png" style="width: 495px; height: 484px; padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
<b>输出：</b>[2,0,0,0,0,0,2]
<b>解释：</b>通过服务器 0 ，有 2 个可连接服务器对(4, 5) 和 (4, 6) 。
通过服务器 6 ，有 2 个可连接服务器对 (4, 5) 和 (0, 5) 。
所有服务器对都必须通过服务器 0 或 6 才可连接，所以其他服务器对应的可连接服务器对数目都为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>, weight<sub>i</sub>]</code><!-- notionvc: a2623897-1bb1-4c07-84b6-917ffdcd83ec --></li>
	<li><code>1 &lt;= weight<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= signalSpeed &lt;= 10<sup>6</sup></code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;构成一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + DFS

我们先根据题目给定的边构建出一个邻接表 $g$，其中 $g[a]$ 表示节点 $a$ 的所有邻居节点以及对应的边权。

然后，我们可以枚举每一个节点 $a$ 作为连接的中间节点，通过深度优先搜索计算出从 $a$ 的邻居节点 $b$ 出发的，且到节点 $a$ 的距离可以被 $signalSpeed$ 整除的节点数 $t$。那么，节点 $a$ 的可连接节点对数目增加了 $s \times t$，其中 $s$ 表示节点 $a$ 的邻居节点 $b$ 出发的，且到节点 $a$ 的距离不可以被 $signalSpeed$ 整除的累计节点数。然后我们更新 $s$ 为 $s + t$。

枚举完所有节点 $a$ 之后，我们就可以得到所有节点的可连接节点对数目。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 表示节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairsOfConnectableServers(
        self, edges: List[List[int]], signalSpeed: int
    ) -> List[int]:
        def dfs(a: int, fa: int, ws: int) -> int:
            cnt = 0 if ws % signalSpeed else 1
            for b, w in g[a]:
                if b != fa:
                    cnt += dfs(b, a, ws + w)
            return cnt

        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for a, b, w in edges:
            g[a].append((b, w))
            g[b].append((a, w))
        ans = [0] * n
        for a in range(n):
            s = 0
            for b, w in g[a]:
                t = dfs(b, a, w)
                ans[a] += s * t
                s += t
        return ans
```

#### Java

```java
class Solution {
    private int signalSpeed;
    private List<int[]>[] g;

    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length + 1;
        g = new List[n];
        this.signalSpeed = signalSpeed;
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].add(new int[] {b, w});
            g[b].add(new int[] {a, w});
        }
        int[] ans = new int[n];
        for (int a = 0; a < n; ++a) {
            int s = 0;
            for (var e : g[a]) {
                int b = e[0], w = e[1];
                int t = dfs(b, a, w);
                ans[a] += s * t;
                s += t;
            }
        }
        return ans;
    }

    private int dfs(int a, int fa, int ws) {
        int cnt = ws % signalSpeed == 0 ? 1 : 0;
        for (var e : g[a]) {
            int b = e[0], w = e[1];
            if (b != fa) {
                cnt += dfs(b, a, ws + w);
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<pair<int, int>> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }
        function<int(int, int, int)> dfs = [&](int a, int fa, int ws) {
            int cnt = ws % signalSpeed == 0;
            for (auto& [b, w] : g[a]) {
                if (b != fa) {
                    cnt += dfs(b, a, ws + w);
                }
            }
            return cnt;
        };
        vector<int> ans(n);
        for (int a = 0; a < n; ++a) {
            int s = 0;
            for (auto& [b, w] : g[a]) {
                int t = dfs(b, a, w);
                ans[a] += s * t;
                s += t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPairsOfConnectableServers(edges [][]int, signalSpeed int) []int {
	n := len(edges) + 1
	type pair struct{ x, w int }
	g := make([][]pair, n)
	for _, e := range edges {
		a, b, w := e[0], e[1], e[2]
		g[a] = append(g[a], pair{b, w})
		g[b] = append(g[b], pair{a, w})
	}
	var dfs func(a, fa, ws int) int
	dfs = func(a, fa, ws int) int {
		cnt := 0
		if ws%signalSpeed == 0 {
			cnt++
		}
		for _, e := range g[a] {
			b, w := e.x, e.w
			if b != fa {
				cnt += dfs(b, a, ws+w)
			}
		}
		return cnt
	}
	ans := make([]int, n)
	for a := 0; a < n; a++ {
		s := 0
		for _, e := range g[a] {
			b, w := e.x, e.w
			t := dfs(b, a, w)
			ans[a] += s * t
			s += t
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countPairsOfConnectableServers(edges: number[][], signalSpeed: number): number[] {
    const n = edges.length + 1;
    const g: [number, number][][] = Array.from({ length: n }, () => []);
    for (const [a, b, w] of edges) {
        g[a].push([b, w]);
        g[b].push([a, w]);
    }
    const dfs = (a: number, fa: number, ws: number): number => {
        let cnt = ws % signalSpeed === 0 ? 1 : 0;
        for (const [b, w] of g[a]) {
            if (b != fa) {
                cnt += dfs(b, a, ws + w);
            }
        }
        return cnt;
    };
    const ans: number[] = Array(n).fill(0);
    for (let a = 0; a < n; ++a) {
        let s = 0;
        for (const [b, w] of g[a]) {
            const t = dfs(b, a, w);
            ans[a] += s * t;
            s += t;
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

# [3068. 最大节点价值之和](https://leetcode.cn/problems/find-the-maximum-sum-of-node-values){#3068}

{{< tabs "3068" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        f0, f1 = 0, -inf
        for x in nums:
            f0, f1 = max(f0 + x, f1 + (x ^ k)), max(f1 + x, f0 + (x ^ k))
        return f0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long f0 = 0, f1 = -0x3f3f3f3f;
        for (int x : nums) {
            long tmp = f0;
            f0 = Math.max(f0 + x, f1 + (x ^ k));
            f1 = Math.max(f1 + x, tmp + (x ^ k));
        }
        return f0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long f0 = 0, f1 = -0x3f3f3f3f;
        for (int x : nums) {
            long long tmp = f0;
            f0 = max(f0 + x, f1 + (x ^ k));
            f1 = max(f1 + x, tmp + (x ^ k));
        }
        return f0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumValueSum(nums []int, k int, edges [][]int) int64 {
	f0, f1 := 0, -0x3f3f3f3f
	for _, x := range nums {
		f0, f1 = max(f0+x, f1+(x^k)), max(f1+x, f0+(x^k))
	}
	return int64(f0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumValueSum(nums: number[], k: number, edges: number[][]): number {
    let [f0, f1] = [0, -Infinity];
    for (const x of nums) {
        [f0, f1] = [Math.max(f0 + x, f1 + (x ^ k)), Math.max(f1 + x, f0 + (x ^ k))];
    }
    return f0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        let mut f0: i64 = 0;
        let mut f1: i64 = i64::MIN;

        for &x in &nums {
            let tmp = f0;
            f0 = std::cmp::max(f0 + x as i64, f1 + (x ^ k) as i64);
            f1 = std::cmp::max(f1 + x as i64, tmp + (x ^ k) as i64);
        }

        f0
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public long MaximumValueSum(int[] nums, int k, int[][] edges) {
        long f0 = 0, f1 = -0x3f3f3f3f;
        foreach (int x in nums) {
            long tmp = f0;
            f0 = Math.Max(f0 + x, f1 + (x ^ k));
            f1 = Math.Max(f1 + x, tmp + (x ^ k));
        }
        return f0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <code>n</code>&nbsp;个节点的 <strong>无向</strong>&nbsp;树，节点从 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;编号。树以长度为 <code>n - 1</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的二维整数数组 <code>edges</code>&nbsp;的形式给你，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>u<sub>i</sub></code>&nbsp;和&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条边。同时给你一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;和一个长度为 <code>n</code>&nbsp;下标从&nbsp;<strong>0</strong>&nbsp;开始的&nbsp;<strong>非负</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;，其中&nbsp;<code>nums[i]</code>&nbsp;表示节点 <code>i</code>&nbsp;的 <strong>价值</strong>&nbsp;。</p>

<p>Alice&nbsp;想 <strong>最大化</strong>&nbsp;树中所有节点价值之和。为了实现这一目标，Alice 可以执行以下操作 <strong>任意</strong>&nbsp;次（<strong>包括</strong><strong>&nbsp;0 次</strong>）：</p>

<ul>
	<li>选择连接节点&nbsp;<code>u</code>&nbsp;和&nbsp;<code>v</code>&nbsp;的边&nbsp;<code>[u, v]</code>&nbsp;，并将它们的值更新为：

    <ul>
    	<li><code>nums[u] = nums[u] XOR k</code></li>
    	<li><code>nums[v] = nums[v] XOR k</code></li>
    </ul>
    </li>

</ul>

<p>请你返回 Alice 通过执行以上操作 <strong>任意次</strong>&nbsp;后，可以得到所有节点 <strong>价值之和</strong>&nbsp;的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3068.Find%20the%20Maximum%20Sum%20of%20Node%20Values/images/screenshot-2023-11-10-012513.png" style="width: 300px; height: 277px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
<b>输出：</b>6
<b>解释：</b>Alice 可以通过一次操作得到最大价值和 6 ：
- 选择边 [0,2] 。nums[0] 和 nums[2] 都变为：1 XOR 3 = 2 ，数组 nums 变为：[1,2,1] -&gt; [2,2,2] 。
所有节点价值之和为 2 + 2 + 2 = 6 。
6 是可以得到最大的价值之和。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3068.Find%20the%20Maximum%20Sum%20of%20Node%20Values/images/screenshot-2024-01-09-220017.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 300px; height: 239px;" /></p>

<pre>
<b>输入：</b>nums = [2,3], k = 7, edges = [[0,1]]
<b>输出：</b>9
<b>解释：</b>Alice 可以通过一次操作得到最大和 9 ：
- 选择边 [0,1] 。nums[0] 变为：2 XOR 7 = 5 ，nums[1] 变为：3 XOR 7 = 4 ，数组 nums 变为：[2,3] -&gt; [5,4] 。
所有节点价值之和为 5 + 4 = 9 。
9 是可以得到最大的价值之和。
</pre>

<p><strong class="example">示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3068.Find%20the%20Maximum%20Sum%20of%20Node%20Values/images/screenshot-2023-11-10-012641.png" style="width: 600px; height: 233px;padding: 10px; background: #fff; border-radius: .5rem;" /></p>

<pre>
<b>输入：</b>nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]
<b>输出：</b>42
<b>解释：</b>Alice 不需要执行任何操作，就可以得到最大价值之和 42 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= edges[i][0], edges[i][1] &lt;= n - 1</code></li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;构成一棵合法的树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

对于任意一个数 $x$，与 $k$ 异或偶数次后，值不变。所以，对于一棵树的任意一条路径，我们将路径上所有的边都进行操作，那么该路径上除了起点和终点外，其他节点的值都不会改变。

另外，无论进行了多少次操作，总会有偶数个元素异或了 $k$，其余元素不变。

因此，问题转化为：对于数组 $\textit{nums}$，任选其中偶数个元素异或 $k$，使得和最大。

我们可以使用动态规划解决这个问题。设 $f_0$ 表示当前有偶数个元素异或了 $k$ 时的最大和，而 $f_1$ 表示当前有奇数个元素异或了 $k$ 时的最大和。那么状态转移方程为：

$$
\begin{aligned}
f_0 &= \max(f_0 + x, f_1 + (x \oplus k)) \\
f_1 &= \max(f_1 + x, f_0 + (x \oplus k))
\end{aligned}
$$

其中 $x$ 表示当前元素的值。

我们遍历数组 $\textit{nums}$，根据上述状态转移方程更新 $f_0$ 和 $f_1$，最后返回 $f_0$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        f0, f1 = 0, -inf
        for x in nums:
            f0, f1 = max(f0 + x, f1 + (x ^ k)), max(f1 + x, f0 + (x ^ k))
        return f0
```

#### Java

```java
class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        long f0 = 0, f1 = -0x3f3f3f3f;
        for (int x : nums) {
            long tmp = f0;
            f0 = Math.max(f0 + x, f1 + (x ^ k));
            f1 = Math.max(f1 + x, tmp + (x ^ k));
        }
        return f0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long f0 = 0, f1 = -0x3f3f3f3f;
        for (int x : nums) {
            long long tmp = f0;
            f0 = max(f0 + x, f1 + (x ^ k));
            f1 = max(f1 + x, tmp + (x ^ k));
        }
        return f0;
    }
};
```

#### Go

```go
func maximumValueSum(nums []int, k int, edges [][]int) int64 {
	f0, f1 := 0, -0x3f3f3f3f
	for _, x := range nums {
		f0, f1 = max(f0+x, f1+(x^k)), max(f1+x, f0+(x^k))
	}
	return int64(f0)
}
```

#### TypeScript

```ts
function maximumValueSum(nums: number[], k: number, edges: number[][]): number {
    let [f0, f1] = [0, -Infinity];
    for (const x of nums) {
        [f0, f1] = [Math.max(f0 + x, f1 + (x ^ k)), Math.max(f1 + x, f0 + (x ^ k))];
    }
    return f0;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        let mut f0: i64 = 0;
        let mut f1: i64 = i64::MIN;

        for &x in &nums {
            let tmp = f0;
            f0 = std::cmp::max(f0 + x as i64, f1 + (x ^ k) as i64);
            f1 = std::cmp::max(f1 + x as i64, tmp + (x ^ k) as i64);
        }

        f0
    }
}
```

#### C#

```cs
public class Solution {
    public long MaximumValueSum(int[] nums, int k, int[][] edges) {
        long f0 = 0, f1 = -0x3f3f3f3f;
        foreach (int x in nums) {
            long tmp = f0;
            f0 = Math.Max(f0 + x, f1 + (x ^ k));
            f1 = Math.Max(f1 + x, tmp + (x ^ k));
        }
        return f0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3069. 将元素分配到两个数组中 I](https://leetcode.cn/problems/distribute-elements-into-two-arrays-i){#3069}

{{< tabs "3069" >}}

{{% tab "python" %}}
```python
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        for x in nums[2:]:
            if arr1[-1] > arr2[-1]:
                arr1.append(x)
            else:
                arr2.append(x)
        return arr1 + arr2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        int i = 0, j = 0;
        for (int k = 2; k < n; ++k) {
            if (arr1[i] > arr2[j]) {
                arr1[++i] = nums[k];
            } else {
                arr2[++j] = nums[k];
            }
        }
        for (int k = 0; k <= j; ++k) {
            arr1[++i] = arr2[k];
        }
        return arr1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        for (int k = 2; k < n; ++k) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[k]);
            } else {
                arr2.push_back(nums[k]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func resultArray(nums []int) []int {
	arr1 := []int{nums[0]}
	arr2 := []int{nums[1]}
	for _, x := range nums[2:] {
		if arr1[len(arr1)-1] > arr2[len(arr2)-1] {
			arr1 = append(arr1, x)
		} else {
			arr2 = append(arr2, x)
		}
	}
	return append(arr1, arr2...)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function resultArray(nums: number[]): number[] {
    const arr1: number[] = [nums[0]];
    const arr2: number[] = [nums[1]];
    for (const x of nums.slice(2)) {
        if (arr1.at(-1)! > arr2.at(-1)!) {
            arr1.push(x);
        } else {
            arr2.push(x);
        }
    }
    return arr1.concat(arr2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>1</strong> 开始、包含<strong> 不同 </strong>整数的数组 <code>nums</code> ，数组长度为 <code>n</code> 。</p>

<p>你需要通过 <code>n</code> 次操作，将 <code>nums</code> 中的所有元素分配到两个数组 <code>arr1</code> 和 <code>arr2</code> 中。在第一次操作中，将 <code>nums[1]</code> 追加到 <code>arr1</code> 。在第二次操作中，将 <code>nums[2]</code> 追加到 <code>arr2</code> 。之后，在第 <code>i</code> 次操作中：</p>

<ul>
	<li>如果 <code>arr1</code> 的最后一个元素 <strong>大于 </strong><code>arr2</code> 的最后一个元素，就将 <code>nums[i]</code> 追加到 <code>arr1</code> 。否则，将 <code>nums[i]</code> 追加到 <code>arr2</code> 。</li>
</ul>

<p>通过连接数组 <code>arr1</code> 和 <code>arr2</code> 形成数组 <code>result</code> 。例如，如果 <code>arr1 == [1,2,3]</code> 且 <code>arr2 == [4,5,6]</code> ，那么 <code>result = [1,2,3,4,5,6]</code> 。</p>

<p>返回数组 <code>result</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,1,3]
<strong>输出：</strong>[2,3,1]
<strong>解释：</strong>在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，由于 arr1 的最后一个元素大于 arr2 的最后一个元素（2 &gt; 1），将 nums[3] 追加到 arr1 。
3 次操作后，arr1 = [2,3] ，arr2 = [1] 。
因此，连接形成的数组 result 是 [2,3,1] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,4,3,8]
<strong>输出：</strong>[5,3,4,8]
<strong>解释：</strong>在前两次操作后，arr1 = [5] ，arr2 = [4] 。
在第 3 次操作中，由于 arr1 的最后一个元素大于 arr2 的最后一个元素（5 &gt; 4），将 nums[3] 追加到 arr1 ，因此 arr1 变为 [5,3] 。
在第 4 次操作中，由于 arr2 的最后一个元素大于 arr1 的最后一个元素（4 &gt; 3），将 nums[4] 追加到 arr2 ，因此 arr2 变为 [4,8] 。
4 次操作后，arr1 = [5,3] ，arr2 = [4,8] 。
因此，连接形成的数组 result 是 [5,3,4,8] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>nums</code>中的所有元素都互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们创建两个数组 `arr1` 和 `arr2`，分别存放 `nums` 中的元素，初始时 `arr1` 中只有 `nums[0]`，`arr2` 中只有 `nums[1]`。

然后遍历 `nums` 下标从 $2$ 开始的元素，如果 `arr1` 的最后一个元素大于 `arr2` 的最后一个元素，就将当前元素追加到 `arr1`，否则追加到 `arr2`。

最后将 `arr2` 中的元素追加到 `arr1` 中，返回 `arr1`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        for x in nums[2:]:
            if arr1[-1] > arr2[-1]:
                arr1.append(x)
            else:
                arr2.append(x)
        return arr1 + arr2
```

#### Java

```java
class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        arr1[0] = nums[0];
        arr2[0] = nums[1];
        int i = 0, j = 0;
        for (int k = 2; k < n; ++k) {
            if (arr1[i] > arr2[j]) {
                arr1[++i] = nums[k];
            } else {
                arr2[++j] = nums[k];
            }
        }
        for (int k = 0; k <= j; ++k) {
            arr1[++i] = arr2[k];
        }
        return arr1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        for (int k = 2; k < n; ++k) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[k]);
            } else {
                arr2.push_back(nums[k]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};
```

#### Go

```go
func resultArray(nums []int) []int {
	arr1 := []int{nums[0]}
	arr2 := []int{nums[1]}
	for _, x := range nums[2:] {
		if arr1[len(arr1)-1] > arr2[len(arr2)-1] {
			arr1 = append(arr1, x)
		} else {
			arr2 = append(arr2, x)
		}
	}
	return append(arr1, arr2...)
}
```

#### TypeScript

```ts
function resultArray(nums: number[]): number[] {
    const arr1: number[] = [nums[0]];
    const arr2: number[] = [nums[1]];
    for (const x of nums.slice(2)) {
        if (arr1.at(-1)! > arr2.at(-1)!) {
            arr1.push(x);
        } else {
            arr2.push(x);
        }
    }
    return arr1.concat(arr2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
