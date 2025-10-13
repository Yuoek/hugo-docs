---
title: "2700_两个对象之间的差异 🔒"
date: 2025-10-08T18:39:33+08:00
weight: 1
tags: [JavaScript, 二分查找, 位运算, 动态规划, 哈希表, 回溯, 字典树, 字符串, 并查集, 排序, 数学, 数据库, 数组, 数论, 枚举, 贪心]
---

{{< markmap >}}
### [2700_两个对象之间的差异 🔒](#2700)
#### [JavaScript](#2700)
### [2701_连续递增交易 🔒](#2701)
#### [数据库](#2701)
### [2702_使数字变为非正数的最小操作次数 🔒](#2702)
#### [数组](#2702)
#### [二分查找](#2702)
### [2703_返回传递的参数的长度](#2703)
#### [JavaScript](#2703)
### [2704_相等还是不相等](#2704)
#### [JavaScript](#2704)
### [2705_精简对象](#2705)
#### [JavaScript](#2705)
### [2706_购买两块巧克力](#2706)
#### [贪心](#2706)
#### [数组](#2706)
#### [排序](#2706)
### [2707_字符串中的额外字符](#2707)
#### [字典树](#2707)
#### [数组](#2707)
#### [哈希表](#2707)
#### [字符串](#2707)
#### [动态规划](#2707)
### [2708_一个小组的最大实力值](#2708)
#### [贪心](#2708)
#### [位运算](#2708)
#### [数组](#2708)
#### [动态规划](#2708)
#### [回溯](#2708)
#### [枚举](#2708)
#### [排序](#2708)
### [2709_最大公约数遍历](#2709)
#### [并查集](#2709)
#### [数组](#2709)
#### [数学](#2709)
#### [数论](#2709)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2700_两个对象之间的差异 🔒
___
#### JavaScript
---
### 2701_连续递增交易 🔒
___
#### 数据库
---
### 2702_使数字变为非正数的最小操作次数 🔒
___
#### 数组
___
#### 二分查找
---
### 2703_返回传递的参数的长度
___
#### JavaScript
---
### 2704_相等还是不相等
___
#### JavaScript
---
### 2705_精简对象
___
#### JavaScript
---
### 2706_购买两块巧克力
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2707_字符串中的额外字符
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
---
### 2708_一个小组的最大实力值
___
#### 贪心
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 回溯
___
#### 枚举
___
#### 排序
---
### 2709_最大公约数遍历
___
#### 并查集
___
#### 数组
___
#### 数学
___
#### 数论
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 位运算 |
| 动态规划 | 哈希表 | 回溯 |
| 字典树 | 字符串 | 并查集 |
| 排序 | 数学 | 数据库 |
| 数组 | 数论 | 枚举 |
| 贪心 |  |  |

# [2700. 两个对象之间的差异 🔒](https://leetcode.cn/problems/differences-between-two-objects){#2700}

{{< tabs "2700" >}}

{{% tab "ts" %}}
```ts
function objDiff(obj1: any, obj2: any): any {
    if (type(obj1) !== type(obj2)) return [obj1, obj2];
    if (!isObject(obj1)) return obj1 === obj2 ? {} : [obj1, obj2];
    const diff: Record<string, unknown> = {};
    const sameKeys = Object.keys(obj1).filter(key => key in obj2);
    sameKeys.forEach(key => {
        const subDiff = objDiff(obj1[key], obj2[key]);
        if (Object.keys(subDiff).length) diff[key] = subDiff;
    });
    return diff;
}

function type(obj: unknown): string {
    return Object.prototype.toString.call(obj).slice(8, -1);
}

function isObject(obj: unknown): obj is Record<string, unknown> {
    return typeof obj === 'object' && obj !== null;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，它接收两个深度嵌套的对象或数组 <code>obj1</code> 和 <code>obj2</code> ，并返回一个新对象表示它们之间差异。</p>

<p>该函数应该比较这两个对象的属性，并识别任何变化。返回的对象应仅包含从 <code>obj1</code> 到 <code>obj2</code> 的值不同的键。</p>

<p>对于每个变化的键，值应表示为一个数组 <code>[obj1 value, obj2 value]</code> 。不存在于一个对象中但存在于另一个对象中的键不应包含在返回的对象中。在比较两个数组时，数组的索引被视为它们的键。最终结果应是一个深度嵌套的对象，其中每个叶子的值都是一个差异数组。</p>

<p>你可以假设这两个对象都是 <code>JSON.parse</code> 的输出结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
obj1 = {}
obj2 = {
&nbsp; "a": 1, 
  "b": 2
}
<b>输出：</b>{}
<b>解释：</b>obj1没有进行任何修改。obj2中出现了新的键 "a" 和 "b" ，但添加或删除的键应该被忽略。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>
obj1 = {
&nbsp; "a": 1,
&nbsp; "v": 3,
&nbsp; "x": [],
&nbsp; "z": {
&nbsp; &nbsp; "a": null
&nbsp; }
}
obj2 = {
&nbsp; "a": 2,
&nbsp; "v": 4,
&nbsp; "x": [],
&nbsp; "z": {
&nbsp; &nbsp; "a": 2
&nbsp; }
}
<b>输出：</b>
{
&nbsp; "a": [1, 2],
  "v": [3, 4],
&nbsp; "z": {
&nbsp;   "a": [null, 2]
&nbsp; }
}
<b>解释：</b>键 "a"、"v" 和 "z" 都有变化。"a" 从 1 变为 2，"v" 从 3 变为 4 ，"z" 的子对象 "a" 从 null 变为 2。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>
obj1 = {
&nbsp; "a": 5, 
&nbsp; "v": 6, 
&nbsp; "z": [1, 2, 4, [2, 5, 7]]
}
obj2 = {
&nbsp; "a": 5, 
&nbsp; "v": 7, 
&nbsp; "z": [1, 2, 3, [1]]
}
<b>输出：</b>
{
&nbsp; "v": [6, 7],
&nbsp; "z": {
&nbsp;   "2": [4, 3],
&nbsp;   "3": {
&nbsp;     "0": [2, 1]
&nbsp;   }
&nbsp; }
}
<b>解释：</b>在 obj1 和 obj2 中，键 "v" 和 "z" 的值不同。"a" 被忽略，因为值没有变化。在键 "z" 中，有一个嵌套的数组。数组被视为对象，其中索引被视为键。数组发生了两处变化：z[2] 和 z[3][0]。z[0] 和 z[1] 没有变化，因此没有包含在结果中。z[3][1] 和 z[3][2] 被删除，因此也没有包含在结果中。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>
obj1 = {
&nbsp; "a": {"b": 1}, 
}
obj2 = {
&nbsp; "a": [5],
}
<b>输出：</b>
{
  "a": [{"b": 1}, [5]]
}
<b>解释：</b>键 "a" 在两个对象中都存在。但由于两个相关值具有不同的类型，所以它们被放置在差异数组中。</pre>

<p><strong>示例 5：</strong></p>

<pre>
<b>输入：</b>
obj1 = {
&nbsp; "a": [1, 2, {}], 
&nbsp; "b": false
}
obj2 = { &nbsp; 
&nbsp; "b": false,
&nbsp; "a": [1, 2, {}]
}
<b>输出：</b>
{}
<b>解释：</b>除了键的顺序不同之外，两个对象是相同的，因此返回一个空对象。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obj1</code> 和 <code>obj2</code> 都是有效的 JSON 对象或数组</li>
	<li><code>2 &lt;= JSON.stringify(obj1).length &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= JSON.stringify(obj2).length &lt;= 10<sup>4</sup></code></li>
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

#### TypeScript

```ts
function objDiff(obj1: any, obj2: any): any {
    if (type(obj1) !== type(obj2)) return [obj1, obj2];
    if (!isObject(obj1)) return obj1 === obj2 ? {} : [obj1, obj2];
    const diff: Record<string, unknown> = {};
    const sameKeys = Object.keys(obj1).filter(key => key in obj2);
    sameKeys.forEach(key => {
        const subDiff = objDiff(obj1[key], obj2[key]);
        if (Object.keys(subDiff).length) diff[key] = subDiff;
    });
    return diff;
}

function type(obj: unknown): string {
    return Object.prototype.toString.call(obj).slice(8, -1);
}

function isObject(obj: unknown): obj is Record<string, unknown> {
    return typeof obj === 'object' && obj !== null;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2701. 连续递增交易 🔒](https://leetcode.cn/problems/consecutive-transactions-with-increasing-amounts){#2701}

{{< tabs "2701" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            t1.*,
            SUM(
                CASE
                    WHEN t2.customer_id IS NULL THEN 1
                    ELSE 0
                END
            ) OVER (ORDER BY customer_id, transaction_date) AS s
        FROM
            Transactions AS t1
            LEFT JOIN Transactions AS t2
                ON t1.customer_id = t2.customer_id
                AND t1.amount > t2.amount
                AND DATEDIFF(t1.transaction_date, t2.transaction_date) = 1
    )
SELECT
    customer_id,
    MIN(transaction_date) AS consecutive_start,
    MAX(transaction_date) AS consecutive_end
FROM T
GROUP BY customer_id, s
HAVING COUNT(1) >= 3
ORDER BY customer_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Transactions</code></p>

<pre>
+------------------+------+
| 字段名            | 类型 |
+------------------+------+
| transaction_id   | int  |
| customer_id      | int  |
| transaction_date | date |
| amount           | int  |
+------------------+------+
transaction_id 是该表的主键。 
每行包含有关交易的信息，包括唯一的 (customer_id, transaction_date)，以及相应的 customer_id 和 amount。 
</pre>

<p>编写一个 SQL 查询，找出至少连续三天 <code>amount</code> 递增的客户。并包括 <code>customer_id</code>&nbsp;、连续交易期的起始日期和结束日期。一个客户可以有多个连续的交易。</p>

<p>返回结果并按照 <code>customer_id, consecutive_start, consecutive_end</code>&nbsp;<strong>升序&nbsp;</strong>排列。</p>

<p>查询结果的格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Transactions 表:
+----------------+-------------+------------------+--------+
| transaction_id | customer_id | transaction_date | amount |
+----------------+-------------+------------------+--------+
| 1 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 101 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-01 &nbsp; &nbsp; &nbsp; | 100 &nbsp; &nbsp;|
| 2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 101 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-02 &nbsp; &nbsp; &nbsp; | 150 &nbsp; &nbsp;|
| 3 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 101 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-03 &nbsp; &nbsp; &nbsp; | 200 &nbsp; &nbsp;|
| 4 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 102 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-01 &nbsp; &nbsp; &nbsp; | 50 &nbsp; &nbsp; |
| 5 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 102 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-03 &nbsp; &nbsp; &nbsp; | 100 &nbsp; &nbsp;|
| 6 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 102 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-04 &nbsp; &nbsp; &nbsp; | 200 &nbsp; &nbsp;|
| 7 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-01 &nbsp; &nbsp; &nbsp; | 100 &nbsp; &nbsp;|
| 8 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-02 &nbsp; &nbsp; &nbsp; | 150 &nbsp; &nbsp;|
| 9 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;| 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-03 &nbsp; &nbsp; &nbsp; | 200 &nbsp; &nbsp;|
| 10 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-04 &nbsp; &nbsp; &nbsp; | 300 &nbsp; &nbsp;|
| 11 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-12 &nbsp; &nbsp; &nbsp; | 250 &nbsp; &nbsp;|
| 12 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-13 &nbsp; &nbsp; &nbsp; | 260 &nbsp; &nbsp;|
| 13 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; | 105 &nbsp; &nbsp; &nbsp; &nbsp; | 2023-05-14 &nbsp; &nbsp; &nbsp; | 270 &nbsp; &nbsp;|
+----------------+-------------+------------------+--------+
<b>输出：</b>
+-------------+-------------------+-----------------+
| customer_id | consecutive_start | consecutive_end |&nbsp;
+-------------+-------------------+-----------------+
| 101 &nbsp; &nbsp; &nbsp; &nbsp; |&nbsp; 2023-05-01 &nbsp; &nbsp; &nbsp; |&nbsp;2023-05-03 &nbsp; &nbsp; &nbsp;|&nbsp;
| 105 &nbsp; &nbsp; &nbsp; &nbsp; |&nbsp; 2023-05-01 &nbsp; &nbsp; &nbsp; |&nbsp;2023-05-04 &nbsp; &nbsp; &nbsp;|
| 105 &nbsp; &nbsp; &nbsp; &nbsp; |&nbsp; 2023-05-12 &nbsp; &nbsp; &nbsp; |&nbsp;2023-05-14 &nbsp; &nbsp; &nbsp;|&nbsp;
+-------------+-------------------+-----------------+
<strong>解释：</strong>&nbsp;
- customer_id 为 101 的客户在 2023年5月1日 至 2023年5月3日 期间进行了连续递增金额的交易。
- customer_id 为 102 的客户没有至少连续三天的交易。
- customer_id 为 105 的客户有两组连续交易：从 2023年5月1日 至 2023年5月4日，以及 2023年5月12日 至 2023年5月14日。
结果按 customer_id 升序排序
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
WITH
    T AS (
        SELECT
            t1.*,
            SUM(
                CASE
                    WHEN t2.customer_id IS NULL THEN 1
                    ELSE 0
                END
            ) OVER (ORDER BY customer_id, transaction_date) AS s
        FROM
            Transactions AS t1
            LEFT JOIN Transactions AS t2
                ON t1.customer_id = t2.customer_id
                AND t1.amount > t2.amount
                AND DATEDIFF(t1.transaction_date, t2.transaction_date) = 1
    )
SELECT
    customer_id,
    MIN(transaction_date) AS consecutive_start,
    MAX(transaction_date) AS consecutive_end
FROM T
GROUP BY customer_id, s
HAVING COUNT(1) >= 3
ORDER BY customer_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2702. 使数字变为非正数的最小操作次数 🔒](https://leetcode.cn/problems/minimum-operations-to-make-numbers-non-positive){#2702}

{{< tabs "2702" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int], x: int, y: int) -> int:
        def check(t: int) -> bool:
            cnt = 0
            for v in nums:
                if v > t * y:
                    cnt += ceil((v - t * y) / (x - y))
            return cnt <= t

        l, r = 0, max(nums)
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private int x;
    private int y;

    public int minOperations(int[] nums, int x, int y) {
        this.nums = nums;
        this.x = x;
        this.y = y;
        int l = 0, r = 0;
        for (int v : nums) {
            r = Math.max(r, v);
        }
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int t) {
        long cnt = 0;
        for (int v : nums) {
            if (v > (long) t * y) {
                cnt += (v - (long) t * y + x - y - 1) / (x - y);
            }
        }
        return cnt <= t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        auto check = [&](int t) {
            long long cnt = 0;
            for (int v : nums) {
                if (v > 1LL * t * y) {
                    cnt += (v - 1LL * t * y + x - y - 1) / (x - y);
                }
            }
            return cnt <= t;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int, x int, y int) int {
	check := func(t int) bool {
		cnt := 0
		for _, v := range nums {
			if v > t*y {
				cnt += (v - t*y + x - y - 1) / (x - y)
			}
		}
		return cnt <= t
	}

	l, r := 0, slices.Max(nums)
	for l < r {
		mid := (l + r) >> 1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[], x: number, y: number): number {
    let l = 0;
    let r = Math.max(...nums);
    const check = (t: number): boolean => {
        let cnt = 0;
        for (const v of nums) {
            if (v > t * y) {
                cnt += Math.ceil((v - t * y) / (x - y));
            }
        }
        return cnt <= t;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
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

<p>给定一个 <strong>下标从0开始</strong> 的整数数组 <code>nums</code>，以及两个整数 <code>x</code> 和 <code>y</code>。在每一次操作中，你需要选择一个满足条件 <code>0 &lt;= i &lt; nums.length</code> 的下标 <code>i</code>&nbsp;，并执行以下操作：</p>

<ul>
	<li>将 <code>nums[i]</code> 减去 <code>x</code>。</li>
	<li>将除了下标为 <code>i</code> 的位置外，其他位置的值都减去 <code>y</code>。</li>
</ul>

<p>返回使得 <code>nums</code> 中的所有整数都 <strong>小于等于零&nbsp;</strong>所需的最小操作次数。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>nums = [3,4,1,7,6], x = 4, y = 2
<b>输出：</b>3
<b>解释：</b>你需要进行三次操作。其中一种最优操作序列如下：
操作 1: 选择 i = 3。 然后, nums = [1,2,-1,3,4]. 
操作 2: 选择 i = 3。 然后, nums = [-1,0,-3,-1,2].
操作 3: 选择 i = 4。 然后, nums = [-3,-2,-5,-3,-2].
现在，<code>nums</code> 中的所有数字都是非正数。因此，返回 3。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1], x = 2, y = 1
<b>输出：</b>1
<b>解释：</b>我们可以在 <code>i = 1</code> 处执行一次操作，得到 <code>nums = [0,0,0]</code>。所有正数都被移除，因此返回 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= y &lt; x &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果一个操作次数 $t$ 能够使得所有的数都小于等于 $0$，那么对于任意 $t' > t$，操作次数 $t'$ 也能够使得所有的数都小于等于 $0$。因此我们可以使用二分查找的方法找到最小的操作次数。

我们定义二分查找的左边界 $l=0$，右边界 $r=\max(nums)$。每一次二分查找，我们找到中间值 $mid=\lfloor\frac{l+r}{2}\rfloor$，然后判断是否存在一种操作方法使得操作次数不超过 $mid$，使得所有的数都小于等于 $0$。如果存在，那么我们就更新右边界 $r = mid$，否则我们就更新左边界 $l = mid + 1$。最终当 $l=r$ 时，我们就找到了最小的操作次数，返回 $l$ 即可。

问题的关键在于如何判断是否存在一种操作方法使得操作次数不超过 $t$，使得所有的数都小于等于 $0$。我们可以使用贪心的方法来判断是否存在这样的操作方法。

我们遍历数组中的每一个数 $v$，如果 $v \leq t \times y$，那么我们不需要进行任何操作。否则，我们需要的操作次数为 $\lceil\frac{v - t \times y}{x - y}\rceil$。我们将所有的操作次数相加，如果小于等于 $t$，那么就说明存在一种操作方法使得操作次数不超过 $t$，使得所有的数都小于等于 $0$。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组的长度和数组中的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int], x: int, y: int) -> int:
        def check(t: int) -> bool:
            cnt = 0
            for v in nums:
                if v > t * y:
                    cnt += ceil((v - t * y) / (x - y))
            return cnt <= t

        l, r = 0, max(nums)
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l
```

#### Java

```java
class Solution {
    private int[] nums;
    private int x;
    private int y;

    public int minOperations(int[] nums, int x, int y) {
        this.nums = nums;
        this.x = x;
        this.y = y;
        int l = 0, r = 0;
        for (int v : nums) {
            r = Math.max(r, v);
        }
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(int t) {
        long cnt = 0;
        for (int v : nums) {
            if (v > (long) t * y) {
                cnt += (v - (long) t * y + x - y - 1) / (x - y);
            }
        }
        return cnt <= t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        auto check = [&](int t) {
            long long cnt = 0;
            for (int v : nums) {
                if (v > 1LL * t * y) {
                    cnt += (v - 1LL * t * y + x - y - 1) / (x - y);
                }
            }
            return cnt <= t;
        };
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func minOperations(nums []int, x int, y int) int {
	check := func(t int) bool {
		cnt := 0
		for _, v := range nums {
			if v > t*y {
				cnt += (v - t*y + x - y - 1) / (x - y)
			}
		}
		return cnt <= t
	}

	l, r := 0, slices.Max(nums)
	for l < r {
		mid := (l + r) >> 1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function minOperations(nums: number[], x: number, y: number): number {
    let l = 0;
    let r = Math.max(...nums);
    const check = (t: number): boolean => {
        let cnt = 0;
        for (const v of nums) {
            if (v > t * y) {
                cnt += Math.ceil((v - t * y) / (x - y));
            }
        }
        return cnt <= t;
    };
    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
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

# [2703. 返回传递的参数的长度](https://leetcode.cn/problems/return-length-of-arguments-passed){#2703}

{{< tabs "2703" >}}

{{% tab "ts" %}}
```ts
function argumentsLength(...args: any[]): number {
    return args.length;
}

/**
 * argumentsLength(1, 2, 3); // 3
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

请你编写一个函数 <code>argumentsLength</code>，返回传递给该函数的参数数量。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>args = [5]
<b>输出：</b>1
<strong>解释：</strong>
argumentsLength(5); // 1

只传递了一个值给函数，因此它应返回 1。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>args = [{}, null, "3"]
<b>输出：</b>3
<b>解释：</b>
argumentsLength({}, null, "3"); // 3

传递了三个值给函数，因此它应返回 3。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>args</code>&nbsp;是一个有效的 JSON 数组</li>
	<li><code>0 &lt;= args.length &lt;= 100</code></li>
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

#### TypeScript

```ts
function argumentsLength(...args: any[]): number {
    return args.length;
}

/**
 * argumentsLength(1, 2, 3); // 3
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2704. 相等还是不相等](https://leetcode.cn/problems/to-be-or-not-to-be){#2704}

{{< tabs "2704" >}}

{{% tab "ts" %}}
```ts
type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    return {
        toBe: (toBeVal: any) => {
            if (val !== toBeVal) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe: (notToBeVal: any) => {
            if (val === notToBeVal) {
                throw new Error('Equal');
            }
            return true;
        },
    };
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    return {
        toBe: function (expected) {
            if (val !== expected) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe: function (expected) {
            if (val === expected) {
                throw new Error('Equal');
            }
            return true;
        },
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个名为 <code>expect</code> 的函数，用于帮助开发人员测试他们的代码。它应该接受任何值 <code>val</code> 并返回一个包含以下两个函数的对象。</p>

<ul>
	<li><code>toBe(val)</code> 接受另一个值并在两个值相等（ <code>===</code> ）时返回 <code>true</code> 。如果它们不相等，则应抛出错误 <code>"Not Equal"</code> 。</li>
	<li><code>notToBe(val)</code> 接受另一个值并在两个值不相等（ <code>!==</code> ）时返回 <code>true</code> 。如果它们相等，则应抛出错误 <code>"Equal"</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; expect(5).toBe(5)
<b>输出：</b>{"value": true}
<b>解释：</b>5 === 5 因此该表达式返回 true。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; expect(5).toBe(null)
<b>输出：</b>{"error": "Not Equal"}
<b>解释：</b>5 !== null 因此抛出错误 "Not Equal".
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; expect(5).notToBe(null)
<b>输出：</b>{"value": true}
<b>解释：</b>5 !== null 因此该表达式返回 true.
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

#### TypeScript

```ts
type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    return {
        toBe: (toBeVal: any) => {
            if (val !== toBeVal) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe: (notToBeVal: any) => {
            if (val === notToBeVal) {
                throw new Error('Equal');
            }
            return true;
        },
    };
}

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```

#### JavaScript

```js
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
    return {
        toBe: function (expected) {
            if (val !== expected) {
                throw new Error('Not Equal');
            }
            return true;
        },
        notToBe: function (expected) {
            if (val === expected) {
                throw new Error('Equal');
            }
            return true;
        },
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2705. 精简对象](https://leetcode.cn/problems/compact-object){#2705}

{{< tabs "2705" >}}

{{% tab "ts" %}}
```ts
type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    return Object.entries(obj).reduce((acc, [key, value]) => {
        if (value) {
            acc[key] = compactObject(value);
        }
        return acc;
    }, {} as Obj);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    return Object.entries(obj).reduce((acc, [key, value]) => {
        if (value) {
            acc[key] = compactObject(value);
        }
        return acc;
    }, {});
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个对象或数组 <code>obj</code>，返回一个 <strong>精简对象</strong> 。</p>

<p><strong>精简对象</strong> 与原始对象相同，只是将包含 <strong>假</strong> 值的键移除。该操作适用于对象及其嵌套对象。数组被视为索引作为键的对象。当 <code>Boolean(value)</code> 返回 <code>false</code> 时，值被视为 <strong>假</strong> 值。</p>

<p>你可以假设 <code>obj</code> 是 <code>JSON.parse</code> 的输出结果。换句话说，它是有效的 JSON。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>obj = [null, 0, false, 1]
<b>输出：</b>[1]
<b>解释：</b>数组中的所有假值已被移除。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>obj = {"a": null, "b": [false, 1]}
<b>输出：</b>{"b": [1]}
<b>解释：</b>obj["a"] 和 obj["b"][0] 包含假值，因此被移除。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>obj = [null, 0, 5, [0], [false, 16]]
<b>输出：</b>[5, [], [16]]
<b>解释：</b>obj[0], obj[1], obj[3][0], 和 obj[4][0] 包含假值，因此被移除。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obj</code> 是一个有效的 JSON 对象</li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

如果 `obj` 不是对象或为空，函数会原封不动地返回，因为无需检查非对象值中的键。

如果 `obj` 是一个数组，它会使用 `obj.filter(Boolean)` 过滤掉虚假值（如 `null`、`undefined`、`false`、0、""），然后使用 `map(compactObject)` 对每个元素递归调用 `compactObject`。这样可以确保嵌套数组也被压缩。

如果 `obj` 是一个对象，则会创建一个新的空对象 `compactedObj`。它会遍历 `obj` 的所有键，并对每个键在相应的值上递归调用 `compactObject`，然后将结果存储在值变量中。如果值是真实的（即不是虚假的），它就会将其赋值给具有相应键的压缩对象。

时间复杂度 $O(n)$, 空间复杂度 $O(n)$。

<!-- tabs:start -->

#### TypeScript

```ts
type Obj = Record<any, any>;

function compactObject(obj: Obj): Obj {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    return Object.entries(obj).reduce((acc, [key, value]) => {
        if (value) {
            acc[key] = compactObject(value);
        }
        return acc;
    }, {} as Obj);
}
```

#### JavaScript

```js
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function (obj) {
    if (!obj || typeof obj !== 'object') {
        return obj;
    }
    if (Array.isArray(obj)) {
        return obj.filter(Boolean).map(compactObject);
    }
    return Object.entries(obj).reduce((acc, [key, value]) => {
        if (value) {
            acc[key] = compactObject(value);
        }
        return acc;
    }, {});
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2706. 购买两块巧克力](https://leetcode.cn/problems/buy-two-chocolates){#2706}

{{< tabs "2706" >}}

{{% tab "python" %}}
```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        a = b = inf
        for x in prices:
            if x < a:
                a, b = x, a
            elif x < b:
                b = x
        cost = a + b
        return money if money < cost else money - cost
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        int a = 1000, b = 1000;
        for (int x : prices) {
            if (x < a) {
                b = a;
                a = x;
            } else if (x < b) {
                b = x;
            }
        }
        int cost = a + b;
        return money < cost ? money : money - cost;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = 1000, b = 1000;
        for (int x : prices) {
            if (x < a) {
                b = a;
                a = x;
            } else if (x < b) {
                b = x;
            }
        }
        int cost = a + b;
        return money < cost ? money : money - cost;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func buyChoco(prices []int, money int) int {
	a, b := 1001, 1001
	for _, x := range prices {
		if x < a {
			a, b = x, a
		} else if x < b {
			b = x
		}
	}
	cost := a + b
	if money < cost {
		return money
	}
	return money - cost
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function buyChoco(prices: number[], money: number): number {
    let [a, b] = [1000, 1000];
    for (const x of prices) {
        if (x < a) {
            b = a;
            a = x;
        } else if (x < b) {
            b = x;
        }
    }
    const cost = a + b;
    return money < cost ? money : money - cost;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn buy_choco(prices: Vec<i32>, money: i32) -> i32 {
        let mut a = 1000;
        let mut b = 1000;
        for &x in prices.iter() {
            if x < a {
                b = a;
                a = x;
            } else if x < b {
                b = x;
            }
        }
        let cost = a + b;
        if money < cost {
            money
        } else {
            money - cost
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>prices</code>&nbsp;，它表示一个商店里若干巧克力的价格。同时给你一个整数&nbsp;<code>money</code>&nbsp;，表示你一开始拥有的钱数。</p>

<p>你必须购买 <strong>恰好&nbsp;</strong>两块巧克力，而且剩余的钱数必须是 <strong>非负数</strong>&nbsp;。同时你想最小化购买两块巧克力的总花费。</p>

<p>请你返回在购买两块巧克力后，最多能剩下多少钱。如果购买任意两块巧克力都超过了你拥有的钱，请你返回 <code>money</code>&nbsp;。注意剩余钱数必须是非负数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>prices = [1,2,2], money = 3
<b>输出：</b>0
<b>解释：</b>分别购买价格为 1 和 2 的巧克力。你剩下 3 - 3 = 0 块钱。所以我们返回 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>prices = [3,2,3], money = 3
<b>输出：</b>3
<b>解释：</b>购买任意 2 块巧克力都会超过你拥有的钱数，所以我们返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= prices.length &lt;= 50</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 100</code></li>
	<li><code>1 &lt;= money &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以将巧克力的价格从小到大排序，然后取前两个价格相加，就是我们购买两块巧克力的最小花费 $cost$。如果这个花费大于我们拥有的钱数，那么我们就返回 `money`，否则返回 `money - cost`。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 `prices` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        cost = prices[0] + prices[1]
        return money if money < cost else money - cost
```

#### Java

```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        Arrays.sort(prices);
        int cost = prices[0] + prices[1];
        return money < cost ? money : money - cost;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int cost = prices[0] + prices[1];
        return money < cost ? money : money - cost;
    }
};
```

#### Go

```go
func buyChoco(prices []int, money int) int {
	sort.Ints(prices)
	cost := prices[0] + prices[1]
	if money < cost {
		return money
	}
	return money - cost
}
```

#### TypeScript

```ts
function buyChoco(prices: number[], money: number): number {
    prices.sort((a, b) => a - b);
    const cost = prices[0] + prices[1];
    return money < cost ? money : money - cost;
}
```

#### Rust

```rust
impl Solution {
    pub fn buy_choco(mut prices: Vec<i32>, money: i32) -> i32 {
        prices.sort();
        let cost = prices[0] + prices[1];
        if cost > money {
            return money;
        }
        money - cost
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：一次遍历

我们可以在一次遍历中找到最小的两个价格，然后计算花费。

时间复杂度 $O(n)$，其中 $n$ 是数组 `prices` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        a = b = inf
        for x in prices:
            if x < a:
                a, b = x, a
            elif x < b:
                b = x
        cost = a + b
        return money if money < cost else money - cost
```

#### Java

```java
class Solution {
    public int buyChoco(int[] prices, int money) {
        int a = 1000, b = 1000;
        for (int x : prices) {
            if (x < a) {
                b = a;
                a = x;
            } else if (x < b) {
                b = x;
            }
        }
        int cost = a + b;
        return money < cost ? money : money - cost;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = 1000, b = 1000;
        for (int x : prices) {
            if (x < a) {
                b = a;
                a = x;
            } else if (x < b) {
                b = x;
            }
        }
        int cost = a + b;
        return money < cost ? money : money - cost;
    }
};
```

#### Go

```go
func buyChoco(prices []int, money int) int {
	a, b := 1001, 1001
	for _, x := range prices {
		if x < a {
			a, b = x, a
		} else if x < b {
			b = x
		}
	}
	cost := a + b
	if money < cost {
		return money
	}
	return money - cost
}
```

#### TypeScript

```ts
function buyChoco(prices: number[], money: number): number {
    let [a, b] = [1000, 1000];
    for (const x of prices) {
        if (x < a) {
            b = a;
            a = x;
        } else if (x < b) {
            b = x;
        }
    }
    const cost = a + b;
    return money < cost ? money : money - cost;
}
```

#### Rust

```rust
impl Solution {
    pub fn buy_choco(prices: Vec<i32>, money: i32) -> i32 {
        let mut a = 1000;
        let mut b = 1000;
        for &x in prices.iter() {
            if x < a {
                b = a;
                a = x;
            } else if x < b {
                b = x;
            }
        }
        let cost = a + b;
        if money < cost {
            money
        } else {
            money - cost
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2707. 字符串中的额外字符](https://leetcode.cn/problems/extra-characters-in-a-string){#2707}

{{< tabs "2707" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ['children', 'is_end']

    def __init__(self):
        self.children: List[Node | None] = [None] * 26
        self.is_end = False


class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        root = Node()
        for w in dictionary:
            node = root
            for c in w[::-1]:
                i = ord(c) - ord('a')
                if node.children[i] is None:
                    node.children[i] = Node()
                node = node.children[i]
            node.is_end = True

        n = len(s)
        f = [0] * (n + 1)
        for i in range(1, n + 1):
            f[i] = f[i - 1] + 1
            node = root
            for j in range(i - 1, -1, -1):
                node = node.children[ord(s[j]) - ord('a')]
                if node is None:
                    break
                if node.is_end and f[j] < f[i]:
                    f[i] = f[j]
        return f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Node[] children = new Node[26];
    boolean isEnd;
}

class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        Node root = new Node();
        for (String w : dictionary) {
            Node node = root;
            for (int k = w.length() - 1; k >= 0; --k) {
                int i = w.charAt(k) - 'a';
                if (node.children[i] == null) {
                    node.children[i] = new Node();
                }
                node = node.children[i];
            }
            node.isEnd = true;
        }
        int n = s.length();
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            Node node = root;
            for (int j = i - 1; j >= 0; --j) {
                node = node.children[s.charAt(j) - 'a'];
                if (node == null) {
                    break;
                }
                if (node.isEnd && f[j] < f[i]) {
                    f[i] = f[j];
                }
            }
        }
        return f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    Node* children[26];
    bool isEnd = false;
    Node() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Node* root = new Node();
        for (const string& w : dictionary) {
            Node* node = root;
            for (int k = w.length() - 1; k >= 0; --k) {
                int i = w[k] - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Node();
                }
                node = node->children[i];
            }
            node->isEnd = true;
        }

        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            Node* node = root;
            for (int j = i - 1; ~j; --j) {
                node = node->children[s[j] - 'a'];
                if (node == nullptr) {
                    break;
                }
                if (node->isEnd && f[j] < f[i]) {
                    f[i] = f[j];
                }
            }
        }
        return f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	children [26]*Node
	isEnd    bool
}

func minExtraChar(s string, dictionary []string) int {
	root := &Node{}
	for _, w := range dictionary {
		node := root
		for k := len(w) - 1; k >= 0; k-- {
			i := int(w[k] - 'a')
			if node.children[i] == nil {
				node.children[i] = &Node{}
			}
			node = node.children[i]
		}
		node.isEnd = true
	}

	n := len(s)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] + 1
		node := root
		for j := i - 1; j >= 0; j-- {
			node = node.children[int(s[j]-'a')]
			if node == nil {
				break
			}
			if node.isEnd && f[j] < f[i] {
				f[i] = f[j]
			}
		}
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    children: (Node | null)[] = Array(26).fill(null);
    isEnd: boolean = false;
}

function minExtraChar(s: string, dictionary: string[]): number {
    const root = new Node();
    for (const w of dictionary) {
        let node = root;
        for (let k = w.length - 1; ~k; --k) {
            const i = w.charCodeAt(k) - 'a'.charCodeAt(0);
            if (node.children[i] === null) {
                node.children[i] = new Node();
            }
            node = node.children[i] as Node;
        }
        node.isEnd = true;
    }

    const n = s.length;
    const f: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + 1;
        let node = root;
        for (let j = i - 1; ~j; --j) {
            node = (node.children[s.charCodeAt(j) - 'a'.charCodeAt(0)] as Node) || null;
            if (node === null) {
                break;
            }
            if (node.isEnd && f[j] < f[i]) {
                f[i] = f[j];
            }
        }
    }

    return f[n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn min_extra_char(s: String, dictionary: Vec<String>) -> i32 {
        let ss: HashSet<String> = dictionary.into_iter().collect();
        let n = s.len();
        let mut f = vec![0; n + 1];
        for i in 1..=n {
            f[i] = f[i - 1] + 1;
            for j in 0..i {
                if ss.contains(&s[j..i]) {
                    f[i] = f[i].min(f[j]);
                }
            }
        }
        f[n]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
var minExtraChar = function (s, dictionary) {
    const ss = new Set(dictionary);
    const n = s.length;
    const f = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + 1;
        for (let j = 0; j < i; ++j) {
            if (ss.has(s.slice(j, i))) {
                f[i] = Math.min(f[i], f[j]);
            }
        }
    }
    return f[n];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;和一个单词字典&nbsp;<code>dictionary</code>&nbsp;。你需要将&nbsp;<code>s</code>&nbsp;分割成若干个 <strong>互不重叠</strong>&nbsp;的子字符串，每个子字符串都在&nbsp;<code>dictionary</code>&nbsp;中出现过。<code>s</code>&nbsp;中可能会有一些&nbsp;<strong>额外的字符</strong>&nbsp;不在任何子字符串中。</p>

<p>请你采取最优策略分割 <code>s</code>&nbsp;，使剩下的字符 <strong>最少</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "leetscode", dictionary = ["leet","code","leetcode"]
<b>输出：</b>1
<b>解释：</b>将 s 分成两个子字符串：下标从 0 到 3 的 "leet" 和下标从 5 到 8 的 "code" 。只有 1 个字符没有使用（下标为 4），所以我们返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "sayhelloworld", dictionary = ["hello","world"]
<b>输出：</b>3
<b>解释：</b>将 s 分成两个子字符串：下标从 3 到 7 的 "hello" 和下标从 8 到 12 的 "world" 。下标为 0 ，1 和 2 的字符没有使用，所以我们返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 50</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 50</code></li>
	<li><code>dictionary[i]</code>&nbsp;和&nbsp;<code>s</code>&nbsp;只包含小写英文字母。</li>
	<li><code>dictionary</code>&nbsp;中的单词互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 动态规划

我们可以用一个哈希表 $ss$ 记录字段中的所有单词，方便我们快速判断一个字符串是否在字典中。

接下来，我们定义 $f[i]$ 表示字符串 $s$ 的前 $i$ 个字符的最小额外字符数，初始时 $f[0] = 0$。

当 $i \ge 1$ 时，第 $i$ 个字符 $s[i - 1]$ 可以作为一个额外字符，此时 $f[i] = f[i - 1] + 1$，如果在 $j \in [0, i - 1]$ 中存在一个下标 $j$，使得 $s[j..i)$ 在哈希表 $ss$ 中，那么我们可以将 $s[j..i)$ 作为一个单词，此时 $f[i] = f[j]$。

综上，我们可以得到状态转移方程：

$$
f[i] = \min \{ f[i - 1] + 1, \min_{j \in [0, i - 1]} f[j] \}
$$

其中 $i \ge 1$，而 $j \in [0, i - 1]$ 且 $s[j..i)$ 在哈希表 $ss$ 中。

最终答案为 $f[n]$。

时间复杂度 $O(n^3 + L)$，空间复杂度 $O(n + L)$。其中 $n$ 是字符串 $s$ 的长度，而 $L$ 是字典中所有单词的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        ss = set(dictionary)
        n = len(s)
        f = [0] * (n + 1)
        for i in range(1, n + 1):
            f[i] = f[i - 1] + 1
            for j in range(i):
                if s[j:i] in ss and f[j] < f[i]:
                    f[i] = f[j]
        return f[n]
```

#### Java

```java
class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        Set<String> ss = new HashSet<>();
        for (String w : dictionary) {
            ss.add(w);
        }
        int n = s.length();
        int[] f = new int[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                if (ss.contains(s.substring(j, i))) {
                    f[i] = Math.min(f[i], f[j]);
                }
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> ss(dictionary.begin(), dictionary.end());
        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                if (ss.count(s.substr(j, i - j))) {
                    f[i] = min(f[i], f[j]);
                }
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func minExtraChar(s string, dictionary []string) int {
	ss := map[string]bool{}
	for _, w := range dictionary {
		ss[w] = true
	}
	n := len(s)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] + 1
		for j := 0; j < i; j++ {
			if ss[s[j:i]] && f[j] < f[i] {
				f[i] = f[j]
			}
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function minExtraChar(s: string, dictionary: string[]): number {
    const ss = new Set(dictionary);
    const n = s.length;
    const f = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + 1;
        for (let j = 0; j < i; ++j) {
            if (ss.has(s.substring(j, i))) {
                f[i] = Math.min(f[i], f[j]);
            }
        }
    }
    return f[n];
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn min_extra_char(s: String, dictionary: Vec<String>) -> i32 {
        let ss: HashSet<String> = dictionary.into_iter().collect();
        let n = s.len();
        let mut f = vec![0; n + 1];
        for i in 1..=n {
            f[i] = f[i - 1] + 1;
            for j in 0..i {
                if ss.contains(&s[j..i]) {
                    f[i] = f[i].min(f[j]);
                }
            }
        }
        f[n]
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
var minExtraChar = function (s, dictionary) {
    const ss = new Set(dictionary);
    const n = s.length;
    const f = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + 1;
        for (let j = 0; j < i; ++j) {
            if (ss.has(s.slice(j, i))) {
                f[i] = Math.min(f[i], f[j]);
            }
        }
    }
    return f[n];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：字典树 + 动态规划

我们可以借助字典树来优化方法一的时间复杂度。

具体地，我们首先将字典中的每个单词逆序插入到字典树 $root$ 中，然后我们定义 $f[i]$ 表示字符串 $s$ 的前 $i$ 个字符的最小额外字符数，初始时 $f[0] = 0$。

当 $i \ge 1$ 时，第 $i$ 个字符 $s[i - 1]$ 可以作为一个额外字符，此时 $f[i] = f[i - 1] + 1$；我们也可以在 $[0..i-1]$ 的范围内逆序枚举下标 $j$，判断 $s[j..i)$ 是否在字典树 $root$ 中，如果存在，那么我们可以将 $s[j..i)$ 作为一个单词，此时 $f[i] = f[j]$。

时间复杂度 $O(n^2 + L)$，空间复杂度 $O(n + L \times |\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度，而 $L$ 是字典中所有单词的长度之和，另外 $|\Sigma|$ 是字符集的大小，本题中字符集为小写英文字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ['children', 'is_end']

    def __init__(self):
        self.children: List[Node | None] = [None] * 26
        self.is_end = False


class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        root = Node()
        for w in dictionary:
            node = root
            for c in w[::-1]:
                i = ord(c) - ord('a')
                if node.children[i] is None:
                    node.children[i] = Node()
                node = node.children[i]
            node.is_end = True

        n = len(s)
        f = [0] * (n + 1)
        for i in range(1, n + 1):
            f[i] = f[i - 1] + 1
            node = root
            for j in range(i - 1, -1, -1):
                node = node.children[ord(s[j]) - ord('a')]
                if node is None:
                    break
                if node.is_end and f[j] < f[i]:
                    f[i] = f[j]
        return f[n]
```

#### Java

```java
class Node {
    Node[] children = new Node[26];
    boolean isEnd;
}

class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        Node root = new Node();
        for (String w : dictionary) {
            Node node = root;
            for (int k = w.length() - 1; k >= 0; --k) {
                int i = w.charAt(k) - 'a';
                if (node.children[i] == null) {
                    node.children[i] = new Node();
                }
                node = node.children[i];
            }
            node.isEnd = true;
        }
        int n = s.length();
        int[] f = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            Node node = root;
            for (int j = i - 1; j >= 0; --j) {
                node = node.children[s.charAt(j) - 'a'];
                if (node == null) {
                    break;
                }
                if (node.isEnd && f[j] < f[i]) {
                    f[i] = f[j];
                }
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Node {
public:
    Node* children[26];
    bool isEnd = false;
    Node() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Node* root = new Node();
        for (const string& w : dictionary) {
            Node* node = root;
            for (int k = w.length() - 1; k >= 0; --k) {
                int i = w[k] - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Node();
                }
                node = node->children[i];
            }
            node->isEnd = true;
        }

        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            Node* node = root;
            for (int j = i - 1; ~j; --j) {
                node = node->children[s[j] - 'a'];
                if (node == nullptr) {
                    break;
                }
                if (node->isEnd && f[j] < f[i]) {
                    f[i] = f[j];
                }
            }
        }
        return f[n];
    }
};
```

#### Go

```go
type Node struct {
	children [26]*Node
	isEnd    bool
}

func minExtraChar(s string, dictionary []string) int {
	root := &Node{}
	for _, w := range dictionary {
		node := root
		for k := len(w) - 1; k >= 0; k-- {
			i := int(w[k] - 'a')
			if node.children[i] == nil {
				node.children[i] = &Node{}
			}
			node = node.children[i]
		}
		node.isEnd = true
	}

	n := len(s)
	f := make([]int, n+1)
	for i := 1; i <= n; i++ {
		f[i] = f[i-1] + 1
		node := root
		for j := i - 1; j >= 0; j-- {
			node = node.children[int(s[j]-'a')]
			if node == nil {
				break
			}
			if node.isEnd && f[j] < f[i] {
				f[i] = f[j]
			}
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
class Node {
    children: (Node | null)[] = Array(26).fill(null);
    isEnd: boolean = false;
}

function minExtraChar(s: string, dictionary: string[]): number {
    const root = new Node();
    for (const w of dictionary) {
        let node = root;
        for (let k = w.length - 1; ~k; --k) {
            const i = w.charCodeAt(k) - 'a'.charCodeAt(0);
            if (node.children[i] === null) {
                node.children[i] = new Node();
            }
            node = node.children[i] as Node;
        }
        node.isEnd = true;
    }

    const n = s.length;
    const f: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; ++i) {
        f[i] = f[i - 1] + 1;
        let node = root;
        for (let j = i - 1; ~j; --j) {
            node = (node.children[s.charCodeAt(j) - 'a'.charCodeAt(0)] as Node) || null;
            if (node === null) {
                break;
            }
            if (node.isEnd && f[j] < f[i]) {
                f[i] = f[j];
            }
        }
    }

    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2708. 一个小组的最大实力值](https://leetcode.cn/problems/maximum-strength-of-a-group){#2708}

{{< tabs "2708" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if n == 1:
            return nums[0]
        if nums[1] == nums[-1] == 0:
            return 0
        ans, i = 1, 0
        while i < n:
            if nums[i] < 0 and i + 1 < n and nums[i + 1] < 0:
                ans *= nums[i] * nums[i + 1]
                i += 2
            elif nums[i] <= 0:
                i += 1
            else:
                ans *= nums[i]
                i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxStrength(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        if (nums[1] == 0 && nums[n - 1] == 0) {
            return 0;
        }
        long ans = 1;
        int i = 0;
        while (i < n) {
            if (nums[i] < 0 && i + 1 < n && nums[i + 1] < 0) {
                ans *= nums[i] * nums[i + 1];
                i += 2;
            } else if (nums[i] <= 0) {
                i += 1;
            } else {
                ans *= nums[i];
                i += 1;
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
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (nums[1] == 0 && nums[n - 1] == 0) {
            return 0;
        }
        long long ans = 1;
        int i = 0;
        while (i < n) {
            if (nums[i] < 0 && i + 1 < n && nums[i + 1] < 0) {
                ans *= nums[i] * nums[i + 1];
                i += 2;
            } else if (nums[i] <= 0) {
                i += 1;
            } else {
                ans *= nums[i];
                i += 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxStrength(nums []int) int64 {
	sort.Ints(nums)
	n := len(nums)
	if n == 1 {
		return int64(nums[0])
	}
	if nums[1] == 0 && nums[n-1] == 0 {
		return 0
	}
	ans := int64(1)
	for i := 0; i < n; i++ {
		if nums[i] < 0 && i+1 < n && nums[i+1] < 0 {
			ans *= int64(nums[i] * nums[i+1])
			i++
		} else if nums[i] > 0 {
			ans *= int64(nums[i])
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxStrength(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    if (n === 1) {
        return nums[0];
    }
    if (nums[1] === 0 && nums[n - 1] === 0) {
        return 0;
    }
    let ans = 1;
    for (let i = 0; i < n; ++i) {
        if (nums[i] < 0 && i + 1 < n && nums[i + 1] < 0) {
            ans *= nums[i] * nums[i + 1];
            ++i;
        } else if (nums[i] > 0) {
            ans *= nums[i];
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 <strong>非空</strong>&nbsp;小组，且这个小组的 <strong>实力值</strong>&nbsp;最大，如果这个小组里的学生下标为&nbsp;<code>i<sub>0</sub></code>, <code>i<sub>1</sub></code>, <code>i<sub>2</sub></code>, ... , <code>i<sub>k</sub></code>&nbsp;，那么这个小组的实力值定义为&nbsp;<code>nums[i<sub>0</sub>] * nums[i<sub>1</sub>] * nums[i<sub>2</sub>] * ... * nums[i<sub>k</sub>​]</code>&nbsp;。</p>

<p>请你返回老师创建的小组能得到的最大实力值为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,-1,-5,2,5,-9]
<strong>输出：</strong>1350
<b>解释：</b>一种构成最大实力值小组的方案是选择下标为 [0,2,3,4,5] 的学生。实力值为 3 * (-5) * 2 * 5 * (-9) = 1350 ，这是可以得到的最大实力值。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [-4,-5,-4]
<b>输出：</b>20
<b>解释：</b>选择下标为 [0, 1] 的学生。得到的实力值为 20 。我们没法得到更大的实力值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 13</code></li>
	<li><code>-9 &lt;= nums[i] &lt;= 9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

题目实际上是求所有子集的乘积的最大值，由于数组长度不超过 $13$，我们可以考虑使用二进制枚举的方法。

我们在 $[1, 2^n)$ 的范围内枚举所有的子集，对于每个子集，我们计算其乘积，最后返回最大值即可。

时间复杂度 $O(2^n \times n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        ans = -inf
        for i in range(1, 1 << len(nums)):
            t = 1
            for j, x in enumerate(nums):
                if i >> j & 1:
                    t *= x
            ans = max(ans, t)
        return ans
```

#### Java

```java
class Solution {
    public long maxStrength(int[] nums) {
        long ans = (long) -1e14;
        int n = nums.length;
        for (int i = 1; i < 1 << n; ++i) {
            long t = 1;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    t *= nums[j];
                }
            }
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = -1e14;
        int n = nums.size();
        for (int i = 1; i < 1 << n; ++i) {
            long long t = 1;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    t *= nums[j];
                }
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maxStrength(nums []int) int64 {
	ans := int64(-1e14)
	for i := 1; i < 1<<len(nums); i++ {
		var t int64 = 1
		for j, x := range nums {
			if i>>j&1 == 1 {
				t *= int64(x)
			}
		}
		ans = max(ans, t)
	}
	return ans
}
```

#### TypeScript

```ts
function maxStrength(nums: number[]): number {
    let ans = -Infinity;
    const n = nums.length;
    for (let i = 1; i < 1 << n; ++i) {
        let t = 1;
        for (let j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                t *= nums[j];
            }
        }
        ans = Math.max(ans, t);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序 + 贪心

我们可以先对数组进行排序，然后根据数组的特点，我们可以得到以下结论：

-   如果数组中只有一个元素，那么最大实力值就是这个元素；
-   如果数组中有两个及以上的元素，且数组中 $nums[1] = nums[n - 1] = 0$，那么最大实力值就是 $0$；
-   否则，我们从小到大遍历数组，如果当前元素小于 $0$，且下一个元素也小于 $0$，那么我们将这两个元素相乘，累乘到答案中；否则，如果当前元素小于等于 $0$，我们直接跳过；如果当前元素大于 $0$，我们将这个元素累乘到答案中，最后返回答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if n == 1:
            return nums[0]
        if nums[1] == nums[-1] == 0:
            return 0
        ans, i = 1, 0
        while i < n:
            if nums[i] < 0 and i + 1 < n and nums[i + 1] < 0:
                ans *= nums[i] * nums[i + 1]
                i += 2
            elif nums[i] <= 0:
                i += 1
            else:
                ans *= nums[i]
                i += 1
        return ans
```

#### Java

```java
class Solution {
    public long maxStrength(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        if (nums[1] == 0 && nums[n - 1] == 0) {
            return 0;
        }
        long ans = 1;
        int i = 0;
        while (i < n) {
            if (nums[i] < 0 && i + 1 < n && nums[i + 1] < 0) {
                ans *= nums[i] * nums[i + 1];
                i += 2;
            } else if (nums[i] <= 0) {
                i += 1;
            } else {
                ans *= nums[i];
                i += 1;
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
    long long maxStrength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (nums[1] == 0 && nums[n - 1] == 0) {
            return 0;
        }
        long long ans = 1;
        int i = 0;
        while (i < n) {
            if (nums[i] < 0 && i + 1 < n && nums[i + 1] < 0) {
                ans *= nums[i] * nums[i + 1];
                i += 2;
            } else if (nums[i] <= 0) {
                i += 1;
            } else {
                ans *= nums[i];
                i += 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxStrength(nums []int) int64 {
	sort.Ints(nums)
	n := len(nums)
	if n == 1 {
		return int64(nums[0])
	}
	if nums[1] == 0 && nums[n-1] == 0 {
		return 0
	}
	ans := int64(1)
	for i := 0; i < n; i++ {
		if nums[i] < 0 && i+1 < n && nums[i+1] < 0 {
			ans *= int64(nums[i] * nums[i+1])
			i++
		} else if nums[i] > 0 {
			ans *= int64(nums[i])
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxStrength(nums: number[]): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    if (n === 1) {
        return nums[0];
    }
    if (nums[1] === 0 && nums[n - 1] === 0) {
        return 0;
    }
    let ans = 1;
    for (let i = 0; i < n; ++i) {
        if (nums[i] < 0 && i + 1 < n && nums[i + 1] < 0) {
            ans *= nums[i] * nums[i + 1];
            ++i;
        } else if (nums[i] > 0) {
            ans *= nums[i];
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

# [2709. 最大公约数遍历](https://leetcode.cn/problems/greatest-common-divisor-traversal){#2709}

{{< tabs "2709" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


mx = 100010
p = defaultdict(list)
for x in range(1, mx + 1):
    v = x
    i = 2
    while i <= v // i:
        if v % i == 0:
            p[x].append(i)
            while v % i == 0:
                v //= i
        i += 1
    if v > 1:
        p[x].append(v)


class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        m = max(nums)
        uf = UnionFind(n + m + 1)
        for i, x in enumerate(nums):
            for j in p[x]:
                uf.union(i, j + n)
        return len(set(uf.find(i) for i in range(n))) == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    private static final int MX = 100010;
    private static final List<Integer>[] P = new List[MX];

    static {
        Arrays.setAll(P, k -> new ArrayList<>());
        for (int x = 1; x < MX; ++x) {
            int v = x;
            int i = 2;
            while (i <= v / i) {
                if (v % i == 0) {
                    P[x].add(i);
                    while (v % i == 0) {
                        v /= i;
                    }
                }
                ++i;
            }
            if (v > 1) {
                P[x].add(v);
            }
        }
    }

    public boolean canTraverseAllPairs(int[] nums) {
        int m = Arrays.stream(nums).max().getAsInt();
        int n = nums.length;
        UnionFind uf = new UnionFind(n + m + 1);
        for (int i = 0; i < n; ++i) {
            for (int j : P[nums[i]]) {
                uf.union(i, j + n);
            }
        }
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            s.add(uf.find(i));
        }
        return s.size() == 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
int MX = 100010;
vector<int> P[100010];

int init = []() {
    for (int x = 1; x < MX; ++x) {
        int v = x;
        int i = 2;
        while (i <= v / i) {
            if (v % i == 0) {
                P[x].push_back(i);
                while (v % i == 0) {
                    v /= i;
                }
            }
            ++i;
        }
        if (v > 1) {
            P[x].push_back(v);
        }
    }
    return 0;
}();

class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        UnionFind uf(m + n + 1);
        for (int i = 0; i < n; ++i) {
            for (int j : P[nums[i]]) {
                uf.unite(i, j + n);
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(uf.find(i));
        }
        return s.size() == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mx = 100010

var p = make([][]int, mx)

func init() {
	for x := 1; x < mx; x++ {
		v := x
		i := 2
		for i <= v/i {
			if v%i == 0 {
				p[x] = append(p[x], i)
				for v%i == 0 {
					v /= i
				}
			}
			i++
		}
		if v > 1 {
			p[x] = append(p[x], v)
		}
	}
}

type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func canTraverseAllPairs(nums []int) bool {
	m := slices.Max(nums)
	n := len(nums)
	uf := newUnionFind(m + n + 1)
	for i, x := range nums {
		for _, j := range p[x] {
			uf.union(i, j+n)
		}
	}
	s := map[int]bool{}
	for i := 0; i < n; i++ {
		s[uf.find(i)] = true
	}
	return len(s) == 1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，你可以在一些下标之间遍历。对于两个下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>（<code>i != j</code>），当且仅当&nbsp;<code>gcd(nums[i], nums[j]) &gt; 1</code>&nbsp;时，我们可以在两个下标之间通行，其中&nbsp;<code>gcd</code>&nbsp;是两个数的 <strong>最大公约数</strong>&nbsp;。</p>

<p>你需要判断 <code>nums</code>&nbsp;数组中&nbsp;<strong>任意&nbsp;</strong>两个满足 <code>i &lt; j</code>&nbsp;的下标&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code> ，是否存在若干次通行可以从 <code>i</code>&nbsp;遍历到 <code>j</code>&nbsp;。</p>

<p>如果任意满足条件的下标对都可以遍历，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,6]
<b>输出：</b>true
<b>解释：</b>这个例子中，总共有 3 个下标对：(0, 1) ，(0, 2) 和 (1, 2) 。
从下标 0 到下标 1 ，我们可以遍历 0 -&gt; 2 -&gt; 1 ，我们可以从下标 0 到 2 是因为 gcd(nums[0], nums[2]) = gcd(2, 6) = 2 &gt; 1 ，从下标 2 到 1 是因为 gcd(nums[2], nums[1]) = gcd(6, 3) = 3 &gt; 1 。
从下标 0 到下标 2 ，我们可以直接遍历，因为 gcd(nums[0], nums[2]) = gcd(2, 6) = 2 &gt; 1 。同理，我们也可以从下标 1 到 2 因为 gcd(nums[1], nums[2]) = gcd(3, 6) = 3 &gt; 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,9,5]
<b>输出：</b>false
<b>解释：</b>我们没法从下标 0 到 2 ，所以返回 false 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [4,3,12,8]
<b>输出：</b>true
<b>解释：</b>总共有 6 个下标对：(0, 1) ，(0, 2) ，(0, 3) ，(1, 2) ，(1, 3) 和 (2, 3) 。所有下标对之间都存在可行的遍历，所以返回 true 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
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
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


mx = 100010
p = defaultdict(list)
for x in range(1, mx + 1):
    v = x
    i = 2
    while i <= v // i:
        if v % i == 0:
            p[x].append(i)
            while v % i == 0:
                v //= i
        i += 1
    if v > 1:
        p[x].append(v)


class Solution:
    def canTraverseAllPairs(self, nums: List[int]) -> bool:
        n = len(nums)
        m = max(nums)
        uf = UnionFind(n + m + 1)
        for i, x in enumerate(nums):
            for j in p[x]:
                uf.union(i, j + n)
        return len(set(uf.find(i) for i in range(n))) == 1
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    private static final int MX = 100010;
    private static final List<Integer>[] P = new List[MX];

    static {
        Arrays.setAll(P, k -> new ArrayList<>());
        for (int x = 1; x < MX; ++x) {
            int v = x;
            int i = 2;
            while (i <= v / i) {
                if (v % i == 0) {
                    P[x].add(i);
                    while (v % i == 0) {
                        v /= i;
                    }
                }
                ++i;
            }
            if (v > 1) {
                P[x].add(v);
            }
        }
    }

    public boolean canTraverseAllPairs(int[] nums) {
        int m = Arrays.stream(nums).max().getAsInt();
        int n = nums.length;
        UnionFind uf = new UnionFind(n + m + 1);
        for (int i = 0; i < n; ++i) {
            for (int j : P[nums[i]]) {
                uf.union(i, j + n);
            }
        }
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < n; ++i) {
            s.add(uf.find(i));
        }
        return s.size() == 1;
    }
}
```

#### C++

```cpp
int MX = 100010;
vector<int> P[100010];

int init = []() {
    for (int x = 1; x < MX; ++x) {
        int v = x;
        int i = 2;
        while (i <= v / i) {
            if (v % i == 0) {
                P[x].push_back(i);
                while (v % i == 0) {
                    v /= i;
                }
            }
            ++i;
        }
        if (v > 1) {
            P[x].push_back(v);
        }
    }
    return 0;
}();

class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        UnionFind uf(m + n + 1);
        for (int i = 0; i < n; ++i) {
            for (int j : P[nums[i]]) {
                uf.unite(i, j + n);
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(uf.find(i));
        }
        return s.size() == 1;
    }
};
```

#### Go

```go
const mx = 100010

var p = make([][]int, mx)

func init() {
	for x := 1; x < mx; x++ {
		v := x
		i := 2
		for i <= v/i {
			if v%i == 0 {
				p[x] = append(p[x], i)
				for v%i == 0 {
					v /= i
				}
			}
			i++
		}
		if v > 1 {
			p[x] = append(p[x], v)
		}
	}
}

type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func canTraverseAllPairs(nums []int) bool {
	m := slices.Max(nums)
	n := len(nums)
	uf := newUnionFind(m + n + 1)
	for i, x := range nums {
		for _, j := range p[x] {
			uf.union(i, j+n)
		}
	}
	s := map[int]bool{}
	for i := 0; i < n; i++ {
		s[uf.find(i)] = true
	}
	return len(s) == 1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
