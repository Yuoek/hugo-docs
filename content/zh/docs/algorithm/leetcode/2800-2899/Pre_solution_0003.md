---
title: "2820_选举结果 🔒"
date: 2025-10-08T18:39:37+08:00
weight: 3
tags: [JavaScript, 二分查找, 动态规划, 双指针, 字符串, 排序, 数学, 数据库, 数组, 贪心]
---

{{< markmap >}}
### [2820_选举结果 🔒](#2820)
#### [数据库](#2820)
### [2821_延迟每个 Promise 对象的解析 🔒](#2821)
#### [JavaScript](#2821)
### [2822_对象反转 🔒](#2822)
#### [JavaScript](#2822)
### [2823_深度对象筛选 🔒](#2823)
#### [JavaScript](#2823)
### [2824_统计和小于目标的下标对数目](#2824)
#### [数组](#2824)
#### [双指针](#2824)
#### [二分查找](#2824)
#### [排序](#2824)
### [2825_循环增长使字符串子序列等于另一个字符串](#2825)
#### [双指针](#2825)
#### [字符串](#2825)
### [2826_将三个组排序](#2826)
#### [数组](#2826)
#### [二分查找](#2826)
#### [动态规划](#2826)
### [2827_范围中美丽整数的数目](#2827)
#### [数学](#2827)
#### [动态规划](#2827)
### [2828_判别首字母缩略词](#2828)
#### [数组](#2828)
#### [字符串](#2828)
### [2829_k-avoiding 数组的最小总和](#2829)
#### [贪心](#2829)
#### [数学](#2829)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2820_选举结果 🔒
___
#### 数据库
---
### 2821_延迟每个 Promise 对象的解析 🔒
___
#### JavaScript
---
### 2822_对象反转 🔒
___
#### JavaScript
---
### 2823_深度对象筛选 🔒
___
#### JavaScript
---
### 2824_统计和小于目标的下标对数目
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 2825_循环增长使字符串子序列等于另一个字符串
___
#### 双指针
___
#### 字符串
---
### 2826_将三个组排序
___
#### 数组
___
#### 二分查找
___
#### 动态规划
---
### 2827_范围中美丽整数的数目
___
#### 数学
___
#### 动态规划
---
### 2828_判别首字母缩略词
___
#### 数组
___
#### 字符串
---
### 2829_k-avoiding 数组的最小总和
___
#### 贪心
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 动态规划 |
| 双指针 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 贪心 |  |  |

# [2820. 选举结果 🔒](https://leetcode.cn/problems/election-results){#2820}

{{< tabs "2820" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT candidate, SUM(vote) AS tot
        FROM
            (
                SELECT
                    candidate,
                    1 / (COUNT(candidate) OVER (PARTITION BY voter)) AS vote
                FROM Votes
                WHERE candidate IS NOT NULL
            ) AS t
        GROUP BY 1
    ),
    P AS (
        SELECT
            candidate,
            RANK() OVER (ORDER BY tot DESC) AS rk
        FROM T
    )
SELECT candidate
FROM P
WHERE rk = 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code><font face="monospace">Votes</font></code></p>

<pre>
+-------------+---------+ 
| Column Name | Type    | 
+-------------+---------+ 
| voter       | varchar | 
| candidate   | varchar |
+-------------+---------+
(voter, candidate) 是该表的主键（具有唯一值的列）。
该表的每一行都包含选民及其候选人的姓名。
</pre>

<p>选举在一个城市进行，每个人都可以投票给 <strong>一个或多个</strong> 候选人，也可以选择 <strong>不</strong> 投票。每个人都有 <code>1</code> 票，所以如果他们投票给多个候选人，他们的选票会被平均分配。例如，如果一个人投票给 <code>2</code> 个候选人，这些候选人每人获得&nbsp;<code>0.5</code> 张选票。</p>

<p>编写一个解决方案来查找获得最多选票并赢得选举的候选人&nbsp;<code>candidate</code> 。输出 <strong>候选人</strong> 的姓名，或者如果多个候选人的票数 <strong>相等</strong> ，则输出所有候选人的姓名。</p>

<p>返回按 <code>candidate</code>&nbsp;<strong>升序排序&nbsp;</strong>的结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong> 
Votes table:
+----------+-----------+
| voter    | candidate |
+----------+-----------+
| Kathy    | null      |
| Charles  | Ryan      |
| Charles  | Christine |
| Charles  | Kathy     |
| Benjamin | Christine |
| Anthony  | Ryan      |
| Edward   | Ryan      |
| Terry    | null      |
| Evelyn   | Kathy     |
| Arthur   | Christine |
+----------+-----------+
<b>输出：</b>
+-----------+
| candidate | 
+-----------+
| Christine |  
| Ryan      |  
+-----------+
<b>解释：</b>
- Kathy 和 Terry 选择不投票，导致他们的投票被记录为 0。 Charles 将他的选票分配给了三位候选人，相当于每位候选人得到 0.33 票。另一方面，Benjamin, Arthur, Anthony, Edward, 和 Evely 各自把票投给了一位候选人。
- Ryan 和 Christine 总共获得了2.33票，而 Kathy 总共获得了 1.33 票。
由于 Ryan 和 Christine 获得的票数相等，我们将按升序显示他们的名字。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + 分组统计

我们可以使用窗口函数 `count` 计算每个投票人投给的候选人的票数，然后再使用分组统计函数 `sum` 计算每个候选人的总票数，最后使用窗口函数 `rank` 计算每个候选人的排名，最后筛选出排名第一的候选人即可。

注意，结果集中可能会有多个排名第一的候选人，因此我们需要使用 `order by` 对候选人进行排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT candidate, SUM(vote) AS tot
        FROM
            (
                SELECT
                    candidate,
                    1 / (COUNT(candidate) OVER (PARTITION BY voter)) AS vote
                FROM Votes
                WHERE candidate IS NOT NULL
            ) AS t
        GROUP BY 1
    ),
    P AS (
        SELECT
            candidate,
            RANK() OVER (ORDER BY tot DESC) AS rk
        FROM T
    )
SELECT candidate
FROM P
WHERE rk = 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2821. 延迟每个 Promise 对象的解析 🔒](https://leetcode.cn/problems/delay-the-resolution-of-each-promise){#2821}

{{< tabs "2821" >}}

{{% tab "ts" %}}
```ts
function delayAll(functions: Function[], ms: number): Function[] {
    return functions.map(fn => {
        return async function () {
            await new Promise(resolve => setTimeout(resolve, ms));
            return fn();
        };
    });
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个函数数组 <code>functions</code> 和一个数字 <code>ms</code>，返回一个新的函数数组。</p>

<ul>
	<li><code>functions</code> 是一个返回 Promise 对象的函数数组。</li>
	<li><code>ms</code> 表示延迟的时间，以毫秒为单位。它决定了在新数组中的每个函数返回的 Promise 在解析之前等待的时间。</li>
</ul>

<p>新数组中的每个函数应该返回一个 Promise 对象，在延迟了 <code>ms</code> 毫秒后解析，保持原始 <code>functions</code> 数组中的顺序。<code>delayAll</code> 函数应确保从 <code>functions</code> 中的每个 Promise 都被延迟执行，形成返回延迟的 Promise 的函数的新数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
functions = [
&nbsp;  () =&gt; new Promise((resolve) =&gt; setTimeout(resolve, 30))
], 
ms = 50
<b>输出：</b>[80]
<b>解释：</b>数组中的 Promise 在 30 毫秒后解析，但被延迟了 50 毫秒，所以总共延迟了 30 毫秒 + 50 毫秒 = 80 毫秒。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
functions = [
&nbsp;   () =&gt; new Promise((resolve) =&gt; setTimeout(resolve, 50)),
&nbsp;   () =&gt; new Promise((resolve) =&gt; setTimeout(resolve, 80))
], 
ms = 70
<b>输出：</b>[120,150]
<b>解释：</b>数组中的 Promise 在 50 毫秒和 80 毫秒后解析，但它们被延迟了 70 毫秒，所以总共延迟了 50 毫秒 + 70 毫秒 = 120 毫秒 和 80 毫秒 + 70 毫秒 = 150 毫秒。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>functions</code>&nbsp;是一个返回 Promise 对象的函数数组</li>
	<li><code>10 &lt;= ms &lt;= 500</code></li>
	<li><code>1 &lt;= functions.length &lt;= 10</code></li>
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
function delayAll(functions: Function[], ms: number): Function[] {
    return functions.map(fn => {
        return async function () {
            await new Promise(resolve => setTimeout(resolve, ms));
            return fn();
        };
    });
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2822. 对象反转 🔒](https://leetcode.cn/problems/inversion-of-object){#2822}

{{< tabs "2822" >}}

{{% tab "ts" %}}
```ts
function invertObject(obj: Record<any, any>): Record<any, any> {
    const ans: Record<any, any> = {};
    for (const key in obj) {
        if (ans.hasOwnProperty(obj[key])) {
            if (Array.isArray(ans[obj[key]])) {
                ans[obj[key]].push(key);
            } else {
                ans[obj[key]] = [ans[obj[key]], key];
            }
        } else {
            ans[obj[key]] = key;
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

<p>给定一个对象 <code>obj</code>，返回一个反转的对象 <code>invertedObj</code>。</p>

<p><code>invertedObj</code> 应该以 <code>obj</code> 的键作为值，以 <code>obj</code> 的值作为键。题目保证 <code>obj</code> 中的值仅为字符串。该函数应该处理重复值，也就是说，如果在 <code>obj</code> 中有多个具有相同值的键，那么 <code>invertedObj</code> 应该将该值映射到一个包含所有相应键的数组中。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>obj = {"a": "1", "b": "2", "c": "3", "d": "4"}
<b>输出：</b>invertedObj = {"1": "a", "2": "b", "3": "c", "4": "d"}
<b>解释：</b>obj 中的键变成 invertedObj 中的值，而 obj 中的值变成 invertedObj 中的键。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>obj = {"a": "1", "b": "2", "c": "2", "d": "4"}
<b>输出：</b>invertedObj = {"1": "a", "2": ["b", "c"], "4": "d"}
<b>解释：</b>在 obj 中有两个具有相同值的键，invertedObj 将该值映射到一个包含所有对应键的数组中。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>obj = ["1", "2", "3", "4"]
<b>输出：</b>invertedObj = {"1": "0", "2": "1", "3": "2", "4": "3"}
<b>解释：</b>数组也是对象，因此数组已经转换为一个对象，obj 中的键（索引）变成了 invertedObj 中的值，而 obj 中的值变成了 invertedObj 中的键。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obj</code> 是一个有效的 JSON 对象</li>
	<li><code>typeof obj[key] === "string"</code></li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10**5</code></li>
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
function invertObject(obj: Record<any, any>): Record<any, any> {
    const ans: Record<any, any> = {};
    for (const key in obj) {
        if (ans.hasOwnProperty(obj[key])) {
            if (Array.isArray(ans[obj[key]])) {
                ans[obj[key]].push(key);
            } else {
                ans[obj[key]] = [ans[obj[key]], key];
            }
        } else {
            ans[obj[key]] = key;
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

# [2823. 深度对象筛选 🔒](https://leetcode.cn/problems/deep-object-filter){#2823}

{{< tabs "2823" >}}

{{% tab "ts" %}}
```ts
function deepFilter(obj: Record<string, any>, fn: Function): Record<string, any> | undefined {
    const dfs = (data: any): any => {
        if (Array.isArray(data)) {
            const res = data.map(dfs).filter((item: any) => item !== undefined);
            return res.length > 0 ? res : undefined;
        }
        if (typeof data === 'object' && data !== null) {
            const res: Record<string, any> = {};
            for (const key in data) {
                if (data.hasOwnProperty(key)) {
                    const filteredValue = dfs(data[key]);
                    if (filteredValue !== undefined) {
                        res[key] = filteredValue;
                    }
                }
            }
            return Object.keys(res).length > 0 ? res : undefined;
        }
        return fn(data) ? data : undefined;
    };

    return dfs(obj);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个对象 <code>obj</code> 和一个函数 <code>fn</code>，返回一个经过筛选的对象 <code>filteredObject</code>。</p>

<p>函数 <code>deepFilter</code> 应该在对象 <code>obj</code> 上执行深度筛选操作。深度筛选操作应该移除筛选函数 <code>fn</code> 输出为 <code>false</code> 的属性，以及在键被移除后仍然存在的任何空对象或数组。</p>

<p>如果深度筛选操作导致对象或数组为空，没有剩余属性，<code>deepFilter</code> 应该返回 <code>undefined</code>，表示在 <code>filteredObject</code> 中没有有效数据。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
obj = [-5, -4, -3, -2, -1, 0, 1], 
fn = (x) =&gt; x &gt; 0
<strong>输出：</strong>[1]
<b>解释：</b>所有不大于 0 的值都被移除。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
obj = {"a": 1, "b": "2", "c": 3, "d": "4", "e": 5, "f": 6, "g": {"a": 1}}, 
fn = (x) =&gt; typeof x === "string"
<b>输出：</b>{"b":"2","d":"4"}
<b>解释：</b>所有值不是字符串的键都被移除。在筛选过程中移除键后，任何导致为空的对象也被移除。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>
obj = [-1, [-1, -1, 5, -1, 10], -1, [-1], [-5]], 
fn = (x) =&gt; x &gt; 0
<b>输出：</b>[[5,10]]
<b>解释：</b>所有不大于 0 的值都被移除。在筛选过程中移除值后，任何导致为空的数组也被移除。</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<b>输入：</b>
obj = [[[[5]]]], 
fn = (x) =&gt; Array.isArray(x)
<b>输出：</b>undefined
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>fn</code> 是一个返回布尔值的函数</li>
	<li><code>obj</code> 是一个有效的 JSON 对象</li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10**5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们先判断当前对象是否为数组，如果是数组，我们就对数组中的每一个元素进行递归调用，然后过滤掉返回值为 `undefined` 的元素，最后返回过滤后的数组。

如果当前对象不是数组，我们就判断当前对象是否为对象，如果是对象，我们就对对象中的每一个属性值进行递归调用，然后过滤掉返回值为 `undefined` 的属性值，最后返回过滤后的对象。

如果当前对象既不是数组也不是对象，我们就直接返回 `fn(obj) ? obj : undefined`。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为对象中的元素个数。

<!-- tabs:start -->

#### TypeScript

```ts
function deepFilter(obj: Record<string, any>, fn: Function): Record<string, any> | undefined {
    const dfs = (data: any): any => {
        if (Array.isArray(data)) {
            const res = data.map(dfs).filter((item: any) => item !== undefined);
            return res.length > 0 ? res : undefined;
        }
        if (typeof data === 'object' && data !== null) {
            const res: Record<string, any> = {};
            for (const key in data) {
                if (data.hasOwnProperty(key)) {
                    const filteredValue = dfs(data[key]);
                    if (filteredValue !== undefined) {
                        res[key] = filteredValue;
                    }
                }
            }
            return Object.keys(res).length > 0 ? res : undefined;
        }
        return fn(data) ? data : undefined;
    };

    return dfs(obj);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2824. 统计和小于目标的下标对数目](https://leetcode.cn/problems/count-pairs-whose-sum-is-less-than-target){#2824}

{{< tabs "2824" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = 0
        for j, x in enumerate(nums):
            i = bisect_left(nums, target - x, hi=j)
            ans += i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums);
        int ans = 0;
        for (int j = 0; j < nums.size(); ++j) {
            int x = nums.get(j);
            int i = search(nums, target - x, j);
            ans += i;
        }
        return ans;
    }

    private int search(List<Integer> nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums.get(mid) >= x) {
                r = mid;
            } else {
                l = mid + 1;
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
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int j = 0; j < nums.size(); ++j) {
            int i = lower_bound(nums.begin(), nums.begin() + j, target - nums[j]) - nums.begin();
            ans += i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(nums []int, target int) (ans int) {
	sort.Ints(nums)
	for j, x := range nums {
		i := sort.SearchInts(nums[:j], target-x)
		ans += i
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const search = (x: number, r: number): number => {
        let l = 0;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let j = 0; j < nums.length; ++j) {
        const i = search(target - nums[j], j);
        ans += i;
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

给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;，请你返回满足&nbsp;<code>0 &lt;= i &lt; j &lt; n</code> 且 <code>nums[i] + nums[j] &lt; target</code>&nbsp;的下标对&nbsp;<code>(i, j)</code>&nbsp;的数目。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [-1,1,2,3,1], target = 2
<b>输出：</b>3
<b>解释：</b>总共有 3 个下标对满足题目描述：
- (0, 1) ，0 &lt; 1 且 nums[0] + nums[1] = 0 &lt; target
- (0, 2) ，0 &lt; 2 且 nums[0] + nums[2] = 1 &lt; target 
- (0, 4) ，0 &lt; 4 且 nums[0] + nums[4] = 0 &lt; target
注意 (0, 3) 不计入答案因为 nums[0] + nums[3] 不是严格小于 target 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [-6,2,5,-2,-7,-1,3], target = -2
<b>输出：</b>10
<b>解释：</b>总共有 10 个下标对满足题目描述：
- (0, 1) ，0 &lt; 1 且 nums[0] + nums[1] = -4 &lt; target
- (0, 3) ，0 &lt; 3 且 nums[0] + nums[3] = -8 &lt; target
- (0, 4) ，0 &lt; 4 且 nums[0] + nums[4] = -13 &lt; target
- (0, 5) ，0 &lt; 5 且 nums[0] + nums[5] = -7 &lt; target
- (0, 6) ，0 &lt; 6 且 nums[0] + nums[6] = -3 &lt; target
- (1, 4) ，1 &lt; 4 且 nums[1] + nums[4] = -5 &lt; target
- (3, 4) ，3 &lt; 4 且 nums[3] + nums[4] = -9 &lt; target
- (3, 5) ，3 &lt; 5 且 nums[3] + nums[5] = -3 &lt; target
- (4, 5) ，4 &lt; 5 且 nums[4] + nums[5] = -8 &lt; target
- (4, 6) ，4 &lt; 6 且 nums[4] + nums[6] = -4 &lt; target
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == n &lt;= 50</code></li>
	<li><code>-50 &lt;= nums[i], target &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们先对数组 $nums$ 进行排序，然后枚举 $j$，在 $[0, j)$ 的范围内使用二分查找第一个大于等于 $target - nums[j]$ 的下标 $i$，那么 $[0, i)$ 的范围内的所有下标 $k$ 都满足条件，因此答案增加 $i$。

遍历结束后，我们返回答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = 0
        for j, x in enumerate(nums):
            i = bisect_left(nums, target - x, hi=j)
            ans += i
        return ans
```

#### Java

```java
class Solution {
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums);
        int ans = 0;
        for (int j = 0; j < nums.size(); ++j) {
            int x = nums.get(j);
            int i = search(nums, target - x, j);
            ans += i;
        }
        return ans;
    }

    private int search(List<Integer> nums, int x, int r) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums.get(mid) >= x) {
                r = mid;
            } else {
                l = mid + 1;
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
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int j = 0; j < nums.size(); ++j) {
            int i = lower_bound(nums.begin(), nums.begin() + j, target - nums[j]) - nums.begin();
            ans += i;
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(nums []int, target int) (ans int) {
	sort.Ints(nums)
	for j, x := range nums {
		i := sort.SearchInts(nums[:j], target-x)
		ans += i
	}
	return
}
```

#### TypeScript

```ts
function countPairs(nums: number[], target: number): number {
    nums.sort((a, b) => a - b);
    let ans = 0;
    const search = (x: number, r: number): number => {
        let l = 0;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    for (let j = 0; j < nums.length; ++j) {
        const i = search(target - nums[j], j);
        ans += i;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2825. 循环增长使字符串子序列等于另一个字符串](https://leetcode.cn/problems/make-string-a-subsequence-using-cyclic-increments){#2825}

{{< tabs "2825" >}}

{{% tab "python" %}}
```python
class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i = 0
        for c in str1:
            d = "a" if c == "z" else chr(ord(c) + 1)
            if i < len(str2) and str2[i] in (c, d):
                i += 1
        return i == len(str2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int i = 0, n = str2.length();
        for (char c : str1.toCharArray()) {
            char d = c == 'z' ? 'a' : (char) (c + 1);
            if (i < n && (str2.charAt(i) == c || str2.charAt(i) == d)) {
                ++i;
            }
        }
        return i == n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, n = str2.size();
        for (char c : str1) {
            char d = c == 'z' ? 'a' : c + 1;
            if (i < n && (str2[i] == c || str2[i] == d)) {
                ++i;
            }
        }
        return i == n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canMakeSubsequence(str1 string, str2 string) bool {
	i, n := 0, len(str2)
	for _, c := range str1 {
		d := byte('a')
		if c != 'z' {
			d = byte(c + 1)
		}
		if i < n && (str2[i] == byte(c) || str2[i] == d) {
			i++
		}
	}
	return i == n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canMakeSubsequence(str1: string, str2: string): boolean {
    let i = 0;
    const n = str2.length;
    for (const c of str1) {
        const d = c === 'z' ? 'a' : String.fromCharCode(c.charCodeAt(0) + 1);
        if (i < n && (str2[i] === c || str2[i] === d)) {
            ++i;
        }
    }
    return i === n;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>str1</code> 和&nbsp;<code>str2</code>&nbsp;。</p>

<p>一次操作中，你选择&nbsp;<code>str1</code>&nbsp;中的若干下标。对于选中的每一个下标&nbsp;<code>i</code>&nbsp;，你将&nbsp;<code>str1[i]</code>&nbsp;<strong>循环</strong>&nbsp;递增，变成下一个字符。也就是说&nbsp;<code>'a'</code>&nbsp;变成&nbsp;<code>'b'</code>&nbsp;，<code>'b'</code> 变成&nbsp;<code>'c'</code>&nbsp;，以此类推，<code>'z'</code> 变成&nbsp;<code>'a'</code>&nbsp;。</p>

<p>如果执行以上操作 <strong>至多一次</strong>&nbsp;，可以让 <code>str2</code>&nbsp;成为 <code>str1</code>&nbsp;的子序列，请你返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p><b>注意：</b>一个字符串的子序列指的是从原字符串中删除一些（可以一个字符也不删）字符后，剩下字符按照原本先后顺序组成的新字符串。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>str1 = "abc", str2 = "ad"
<b>输出：</b>true
<b>解释：</b>选择 str1 中的下标 2 。
将 str1[2] 循环递增，得到 'd' 。
因此，str1 变成 "abd" 且 str2 现在是一个子序列。所以返回 true 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>str1 = "zc", str2 = "ad"
<b>输出：</b>true
<b>解释：</b>选择 str1 中的下标 0 和 1 。
将 str1[0] 循环递增得到 'a' 。
将 str1[1] 循环递增得到 'd' 。
因此，str1 变成 "ad" 且 str2 现在是一个子序列。所以返回 true 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>str1 = "ab", str2 = "d"
<b>输出：</b>false
<b>解释：</b>这个例子中，没法在执行一次操作的前提下，将 str2 变为 str1 的子序列。
所以返回 false 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= str1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= str2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>str1</code>&nbsp;和&nbsp;<code>str2</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

本题实际上需要我们判断一个字符串 $s$ 是否为另一个字符串 $t$ 的子序列，只不过字符之间可以不完全匹配，如果两个字符相同，或者一个字符是另一个字符的下一个字符，就可以匹配。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是字符串 $str1$ 和 $str2$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        i = 0
        for c in str1:
            d = "a" if c == "z" else chr(ord(c) + 1)
            if i < len(str2) and str2[i] in (c, d):
                i += 1
        return i == len(str2)
```

#### Java

```java
class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int i = 0, n = str2.length();
        for (char c : str1.toCharArray()) {
            char d = c == 'z' ? 'a' : (char) (c + 1);
            if (i < n && (str2.charAt(i) == c || str2.charAt(i) == d)) {
                ++i;
            }
        }
        return i == n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, n = str2.size();
        for (char c : str1) {
            char d = c == 'z' ? 'a' : c + 1;
            if (i < n && (str2[i] == c || str2[i] == d)) {
                ++i;
            }
        }
        return i == n;
    }
};
```

#### Go

```go
func canMakeSubsequence(str1 string, str2 string) bool {
	i, n := 0, len(str2)
	for _, c := range str1 {
		d := byte('a')
		if c != 'z' {
			d = byte(c + 1)
		}
		if i < n && (str2[i] == byte(c) || str2[i] == d) {
			i++
		}
	}
	return i == n
}
```

#### TypeScript

```ts
function canMakeSubsequence(str1: string, str2: string): boolean {
    let i = 0;
    const n = str2.length;
    for (const c of str1) {
        const d = c === 'z' ? 'a' : String.fromCharCode(c.charCodeAt(0) + 1);
        if (i < n && (str2[i] === c || str2[i] === d)) {
            ++i;
        }
    }
    return i === n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2826. 将三个组排序](https://leetcode.cn/problems/sorting-three-groups){#2826}

{{< tabs "2826" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        f = [0] * 3
        for x in nums:
            g = [0] * 3
            if x == 1:
                g[0] = f[0]
                g[1] = min(f[:2]) + 1
                g[2] = min(f) + 1
            elif x == 2:
                g[0] = f[0] + 1
                g[1] = min(f[:2])
                g[2] = min(f) + 1
            else:
                g[0] = f[0] + 1
                g[1] = min(f[:2]) + 1
                g[2] = min(f)
            f = g
        return min(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperations(List<Integer> nums) {
        int[] f = new int[3];
        for (int x : nums) {
            int[] g = new int[3];
            if (x == 1) {
                g[0] = f[0];
                g[1] = Math.min(f[0], f[1]) + 1;
                g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
            } else if (x == 2) {
                g[0] = f[0] + 1;
                g[1] = Math.min(f[0], f[1]);
                g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
            } else {
                g[0] = f[0] + 1;
                g[1] = Math.min(f[0], f[1]) + 1;
                g[2] = Math.min(f[0], Math.min(f[1], f[2]));
            }
            f = g;
        }
        return Math.min(f[0], Math.min(f[1], f[2]));
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> f(3);
        for (int x : nums) {
            vector<int> g(3);
            if (x == 1) {
                g[0] = f[0];
                g[1] = min(f[0], f[1]) + 1;
                g[2] = min({f[0], f[1], f[2]}) + 1;
            } else if (x == 2) {
                g[0] = f[0] + 1;
                g[1] = min(f[0], f[1]);
                g[2] = min(f[0], min(f[1], f[2])) + 1;
            } else {
                g[0] = f[0] + 1;
                g[1] = min(f[0], f[1]) + 1;
                g[2] = min(f[0], min(f[1], f[2]));
            }
            f = move(g);
        }
        return min({f[0], f[1], f[2]});
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int) int {
	f := make([]int, 3)
	for _, x := range nums {
		g := make([]int, 3)
		if x == 1 {
			g[0] = f[0]
			g[1] = min(f[0], f[1]) + 1
			g[2] = min(f[0], min(f[1], f[2])) + 1
		} else if x == 2 {
			g[0] = f[0] + 1
			g[1] = min(f[0], f[1])
			g[2] = min(f[0], min(f[1], f[2])) + 1
		} else {
			g[0] = f[0] + 1
			g[1] = min(f[0], f[1]) + 1
			g[2] = min(f[0], min(f[1], f[2]))
		}
		f = g
	}
	return min(f[0], min(f[1], f[2]))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(nums: number[]): number {
    let f: number[] = new Array(3).fill(0);
    for (const x of nums) {
        const g: number[] = new Array(3).fill(0);
        if (x === 1) {
            g[0] = f[0];
            g[1] = Math.min(f[0], f[1]) + 1;
            g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
        } else if (x === 2) {
            g[0] = f[0] + 1;
            g[1] = Math.min(f[0], f[1]);
            g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
        } else {
            g[0] = f[0] + 1;
            g[1] = Math.min(f[0], f[1]) + 1;
            g[2] = Math.min(f[0], Math.min(f[1], f[2]));
        }
        f = g;
    }
    return Math.min(...f);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;。<code>nums</code>&nbsp;的每个元素是 1，2 或 3。在每次操作中，你可以删除&nbsp;<code>nums</code>&nbsp;中的一个元素。返回使 nums 成为 <strong>非递减</strong>&nbsp;顺序所需操作数的 <strong>最小值</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,3,2,1]
<b>输出：</b>3
<b>解释：</b>
其中一个最优方案是删除 nums[0]，nums[2] 和 nums[3]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,3,2,1,3,3]
<b>输出：</b>2
<b>解释：</b>
其中一个最优方案是删除 nums[1] 和 nums[2]。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [2,2,2,2,3,3]
<b>输出：</b>0
<b>解释：</b>
nums 已是非递减顺序的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 3</code></li>
</ul>

<p><strong>进阶：</strong>你可以使用&nbsp;<code>O(n)</code>&nbsp;时间复杂度以内的算法解决吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示将前 $i$ 个数变成美丽数组，并且第 $i$ 个数变成 $j+1$ 的最少操作次数。那么答案就是 $\min(f[n][0], f[n][1], f[n][2])$。

我们可以枚举第 $i$ 个数变成 $j+1$ 的所有情况，然后取最小值。这里我们可以用滚动数组优化空间复杂度。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        f = [0] * 3
        for x in nums:
            g = [0] * 3
            if x == 1:
                g[0] = f[0]
                g[1] = min(f[:2]) + 1
                g[2] = min(f) + 1
            elif x == 2:
                g[0] = f[0] + 1
                g[1] = min(f[:2])
                g[2] = min(f) + 1
            else:
                g[0] = f[0] + 1
                g[1] = min(f[:2]) + 1
                g[2] = min(f)
            f = g
        return min(f)
```

#### Java

```java
class Solution {
    public int minimumOperations(List<Integer> nums) {
        int[] f = new int[3];
        for (int x : nums) {
            int[] g = new int[3];
            if (x == 1) {
                g[0] = f[0];
                g[1] = Math.min(f[0], f[1]) + 1;
                g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
            } else if (x == 2) {
                g[0] = f[0] + 1;
                g[1] = Math.min(f[0], f[1]);
                g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
            } else {
                g[0] = f[0] + 1;
                g[1] = Math.min(f[0], f[1]) + 1;
                g[2] = Math.min(f[0], Math.min(f[1], f[2]));
            }
            f = g;
        }
        return Math.min(f[0], Math.min(f[1], f[2]));
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> f(3);
        for (int x : nums) {
            vector<int> g(3);
            if (x == 1) {
                g[0] = f[0];
                g[1] = min(f[0], f[1]) + 1;
                g[2] = min({f[0], f[1], f[2]}) + 1;
            } else if (x == 2) {
                g[0] = f[0] + 1;
                g[1] = min(f[0], f[1]);
                g[2] = min(f[0], min(f[1], f[2])) + 1;
            } else {
                g[0] = f[0] + 1;
                g[1] = min(f[0], f[1]) + 1;
                g[2] = min(f[0], min(f[1], f[2]));
            }
            f = move(g);
        }
        return min({f[0], f[1], f[2]});
    }
};
```

#### Go

```go
func minimumOperations(nums []int) int {
	f := make([]int, 3)
	for _, x := range nums {
		g := make([]int, 3)
		if x == 1 {
			g[0] = f[0]
			g[1] = min(f[0], f[1]) + 1
			g[2] = min(f[0], min(f[1], f[2])) + 1
		} else if x == 2 {
			g[0] = f[0] + 1
			g[1] = min(f[0], f[1])
			g[2] = min(f[0], min(f[1], f[2])) + 1
		} else {
			g[0] = f[0] + 1
			g[1] = min(f[0], f[1]) + 1
			g[2] = min(f[0], min(f[1], f[2]))
		}
		f = g
	}
	return min(f[0], min(f[1], f[2]))
}
```

#### TypeScript

```ts
function minimumOperations(nums: number[]): number {
    let f: number[] = new Array(3).fill(0);
    for (const x of nums) {
        const g: number[] = new Array(3).fill(0);
        if (x === 1) {
            g[0] = f[0];
            g[1] = Math.min(f[0], f[1]) + 1;
            g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
        } else if (x === 2) {
            g[0] = f[0] + 1;
            g[1] = Math.min(f[0], f[1]);
            g[2] = Math.min(f[0], Math.min(f[1], f[2])) + 1;
        } else {
            g[0] = f[0] + 1;
            g[1] = Math.min(f[0], f[1]) + 1;
            g[2] = Math.min(f[0], Math.min(f[1], f[2]));
        }
        f = g;
    }
    return Math.min(...f);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2827. 范围中美丽整数的数目](https://leetcode.cn/problems/number-of-beautiful-integers-in-the-range){#2827}

{{< tabs "2827" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfBeautifulIntegers(self, low: int, high: int, k: int) -> int:
        @cache
        def dfs(pos: int, mod: int, diff: int, lead: int, limit: int) -> int:
            if pos >= len(s):
                return mod == 0 and diff == 10
            up = int(s[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if i == 0 and lead:
                    ans += dfs(pos + 1, mod, diff, 1, limit and i == up)
                else:
                    nxt = diff + (1 if i % 2 == 1 else -1)
                    ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, 0, limit and i == up)
            return ans

        s = str(high)
        a = dfs(0, 0, 10, 1, 1)
        dfs.cache_clear()
        s = str(low - 1)
        b = dfs(0, 0, 10, 1, 1)
        return a - b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private int k;
    private Integer[][][] f = new Integer[11][21][21];

    public int numberOfBeautifulIntegers(int low, int high, int k) {
        this.k = k;
        s = String.valueOf(high);
        int a = dfs(0, 0, 10, true, true);
        s = String.valueOf(low - 1);
        f = new Integer[11][21][21];
        int b = dfs(0, 0, 10, true, true);
        return a - b;
    }

    private int dfs(int pos, int mod, int diff, boolean lead, boolean limit) {
        if (pos >= s.length()) {
            return mod == 0 && diff == 10 ? 1 : 0;
        }
        if (!lead && !limit && f[pos][mod][diff] != null) {
            return f[pos][mod][diff];
        }
        int ans = 0;
        int up = limit ? s.charAt(pos) - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos + 1, mod, diff, true, limit && i == up);
            } else {
                int nxt = diff + (i % 2 == 1 ? 1 : -1);
                ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, false, limit && i == up);
            }
        }
        if (!lead && !limit) {
            f[pos][mod][diff] = ans;
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
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int f[11][21][21];
        memset(f, -1, sizeof(f));
        string s = to_string(high);

        function<int(int, int, int, bool, bool)> dfs = [&](int pos, int mod, int diff, bool lead, bool limit) {
            if (pos >= s.size()) {
                return mod == 0 && diff == 10 ? 1 : 0;
            }
            if (!lead && !limit && f[pos][mod][diff] != -1) {
                return f[pos][mod][diff];
            }
            int ans = 0;
            int up = limit ? s[pos] - '0' : 9;
            for (int i = 0; i <= up; ++i) {
                if (i == 0 && lead) {
                    ans += dfs(pos + 1, mod, diff, true, limit && i == up);
                } else {
                    int nxt = diff + (i % 2 == 1 ? 1 : -1);
                    ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, false, limit && i == up);
                }
            }
            if (!lead && !limit) {
                f[pos][mod][diff] = ans;
            }
            return ans;
        };

        int a = dfs(0, 0, 10, true, true);
        memset(f, -1, sizeof(f));
        s = to_string(low - 1);
        int b = dfs(0, 0, 10, true, true);
        return a - b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfBeautifulIntegers(low int, high int, k int) int {
	s := strconv.Itoa(high)
	f := g(len(s), k, 21)

	var dfs func(pos, mod, diff int, lead, limit bool) int
	dfs = func(pos, mod, diff int, lead, limit bool) int {
		if pos >= len(s) {
			if mod == 0 && diff == 10 {
				return 1
			}
			return 0
		}
		if !lead && !limit && f[pos][mod][diff] != -1 {
			return f[pos][mod][diff]
		}
		up := 9
		if limit {
			up = int(s[pos] - '0')
		}
		ans := 0
		for i := 0; i <= up; i++ {
			if i == 0 && lead {
				ans += dfs(pos+1, mod, diff, true, limit && i == up)
			} else {
				nxt := diff + 1
				if i%2 == 0 {
					nxt -= 2
				}
				ans += dfs(pos+1, (mod*10+i)%k, nxt, false, limit && i == up)
			}
		}
		if !lead && !limit {
			f[pos][mod][diff] = ans
		}
		return ans
	}

	a := dfs(0, 0, 10, true, true)
	s = strconv.Itoa(low - 1)
	f = g(len(s), k, 21)
	b := dfs(0, 0, 10, true, true)
	return a - b
}

func g(m, n, k int) [][][]int {
	f := make([][][]int, m)
	for i := 0; i < m; i++ {
		f[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			f[i][j] = make([]int, k)
			for d := 0; d < k; d++ {
				f[i][j][d] = -1
			}
		}
	}
	return f
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfBeautifulIntegers(low: number, high: number, k: number): number {
    let s = String(high);
    let f: number[][][] = Array(11)
        .fill(0)
        .map(() =>
            Array(21)
                .fill(0)
                .map(() => Array(21).fill(-1)),
        );
    const dfs = (pos: number, mod: number, diff: number, lead: boolean, limit: boolean): number => {
        if (pos >= s.length) {
            return mod == 0 && diff == 10 ? 1 : 0;
        }
        if (!lead && !limit && f[pos][mod][diff] != -1) {
            return f[pos][mod][diff];
        }
        let ans = 0;
        const up = limit ? Number(s[pos]) : 9;
        for (let i = 0; i <= up; ++i) {
            if (i === 0 && lead) {
                ans += dfs(pos + 1, mod, diff, true, limit && i === up);
            } else {
                const nxt = diff + (i % 2 ? 1 : -1);
                ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, false, limit && i === up);
            }
        }
        if (!lead && !limit) {
            f[pos][mod][diff] = ans;
        }
        return ans;
    };
    const a = dfs(0, 0, 10, true, true);
    s = String(low - 1);
    f = Array(11)
        .fill(0)
        .map(() =>
            Array(21)
                .fill(0)
                .map(() => Array(21).fill(-1)),
        );
    const b = dfs(0, 0, 10, true, true);
    return a - b;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你正整数&nbsp;<code>low</code>&nbsp;，<code>high</code>&nbsp;和&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个数满足以下两个条件，那么它是 <strong>美丽的</strong>&nbsp;：</p>

<ul>
	<li>偶数数位的数目与奇数数位的数目相同。</li>
	<li>这个整数可以被&nbsp;<code>k</code>&nbsp;整除。</li>
</ul>

<p>请你返回范围&nbsp;<code>[low, high]</code>&nbsp;中美丽整数的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>low = 10, high = 20, k = 3
<b>输出：</b>2
<b>解释：</b>给定范围中有 2 个美丽数字：[12,18]
- 12 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3 整除。
- 18 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 3 整除。
以下是一些不是美丽整数的例子：
- 16 不是美丽整数，因为它不能被 k = 3 整除。
- 15 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
给定范围内总共有 2 个美丽整数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>low = 1, high = 10, k = 1
<b>输出：</b>1
<b>解释：</b>给定范围中有 1 个美丽数字：[10]
- 10 是美丽整数，因为它有 1 个奇数数位和 1 个偶数数位，而且可以被 k = 1 整除。
给定范围内总共有 1 个美丽整数。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>low = 5, high = 5, k = 2
<b>输出：</b>0
<b>解释：</b>给定范围中有 0 个美丽数字。
- 5 不是美丽整数，因为它的奇数数位和偶数数位的数目不相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt; low &lt;= high &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt; k &lt;= 20</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

我们注意到，题目求的是区间 $[low, high]$ 内的美丽整数的个数，对于这种区间 $[l,..r]$ 的问题，我们通常可以考虑转化为求 $[1, r]$ 和 $[1, l-1]$ 的答案，然后相减即可。另外，题目中只涉及到不同数位之间的关系，而不涉及具体的数值，因此我们可以考虑使用数位 DP 来解决。

我们设计一个函数 $dfs(pos, mod, diff, lead, limit)$，表示当前处理到第 $pos$ 位，当前数字模 $k$ 的结果为 $mod$，当前数字的奇偶数位差为 $diff$，当前数字是否有前导零为 $lead$，当前数字是否达到上界为 $limit$ 时的方案数。

函数 $dfs(pos, mod, diff, lead, limit)$ 的执行逻辑如下：

如果 $pos$ 超出了 $num$ 的长度，说明我们已经处理完了所有数位，如果此时 $mod=0$，并且 $diff=0$，说明当前数字满足题目要求，我们返回 $1$，否则返回 $0$。

否则，我们计算得到当前数位的上界 $up$，然后在 $[0,..up]$ 范围内枚举当前数位的数字 $i$：

-   如果 $i=0$ 且 $lead$ 为真，说明当前数字只包含前导零，我们递归计算 $dfs(pos + 1, mod, diff, 1, limit\ and\ i=up)$ 的值并累加到答案中；
-   否则，我们根据 $i$ 的奇偶性更新 $diff$ 的值，然后递归计算 $dfs(pos + 1, (mod \times 10 + i) \bmod k, diff, 0, limit\ and\ i=up)$ 的值并累加到答案中。

最终我们返回答案。

在主函数中，我们分别计算 $[1, high]$ 和 $[1, low-1]$ 的答案 $a$ 和 $b$，最终答案为 $a-b$。

时间复杂度 $O((\log M)^2 \times k \times |\Sigma|)$，空间复杂度 $O((\log M)^2 \times k \times)$，其中 $M$ 表示 $high$ 数字的大小，而 $|\Sigma|$ 表示数字集合。

相似题目：

-   [2719. 统计整数数目](https://github.com/doocs/leetcode/blob/main/solution/2700-2799/2719.Count%20of%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfBeautifulIntegers(self, low: int, high: int, k: int) -> int:
        @cache
        def dfs(pos: int, mod: int, diff: int, lead: int, limit: int) -> int:
            if pos >= len(s):
                return mod == 0 and diff == 10
            up = int(s[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if i == 0 and lead:
                    ans += dfs(pos + 1, mod, diff, 1, limit and i == up)
                else:
                    nxt = diff + (1 if i % 2 == 1 else -1)
                    ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, 0, limit and i == up)
            return ans

        s = str(high)
        a = dfs(0, 0, 10, 1, 1)
        dfs.cache_clear()
        s = str(low - 1)
        b = dfs(0, 0, 10, 1, 1)
        return a - b
```

#### Java

```java
class Solution {
    private String s;
    private int k;
    private Integer[][][] f = new Integer[11][21][21];

    public int numberOfBeautifulIntegers(int low, int high, int k) {
        this.k = k;
        s = String.valueOf(high);
        int a = dfs(0, 0, 10, true, true);
        s = String.valueOf(low - 1);
        f = new Integer[11][21][21];
        int b = dfs(0, 0, 10, true, true);
        return a - b;
    }

    private int dfs(int pos, int mod, int diff, boolean lead, boolean limit) {
        if (pos >= s.length()) {
            return mod == 0 && diff == 10 ? 1 : 0;
        }
        if (!lead && !limit && f[pos][mod][diff] != null) {
            return f[pos][mod][diff];
        }
        int ans = 0;
        int up = limit ? s.charAt(pos) - '0' : 9;
        for (int i = 0; i <= up; ++i) {
            if (i == 0 && lead) {
                ans += dfs(pos + 1, mod, diff, true, limit && i == up);
            } else {
                int nxt = diff + (i % 2 == 1 ? 1 : -1);
                ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, false, limit && i == up);
            }
        }
        if (!lead && !limit) {
            f[pos][mod][diff] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        int f[11][21][21];
        memset(f, -1, sizeof(f));
        string s = to_string(high);

        function<int(int, int, int, bool, bool)> dfs = [&](int pos, int mod, int diff, bool lead, bool limit) {
            if (pos >= s.size()) {
                return mod == 0 && diff == 10 ? 1 : 0;
            }
            if (!lead && !limit && f[pos][mod][diff] != -1) {
                return f[pos][mod][diff];
            }
            int ans = 0;
            int up = limit ? s[pos] - '0' : 9;
            for (int i = 0; i <= up; ++i) {
                if (i == 0 && lead) {
                    ans += dfs(pos + 1, mod, diff, true, limit && i == up);
                } else {
                    int nxt = diff + (i % 2 == 1 ? 1 : -1);
                    ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, false, limit && i == up);
                }
            }
            if (!lead && !limit) {
                f[pos][mod][diff] = ans;
            }
            return ans;
        };

        int a = dfs(0, 0, 10, true, true);
        memset(f, -1, sizeof(f));
        s = to_string(low - 1);
        int b = dfs(0, 0, 10, true, true);
        return a - b;
    }
};
```

#### Go

```go
func numberOfBeautifulIntegers(low int, high int, k int) int {
	s := strconv.Itoa(high)
	f := g(len(s), k, 21)

	var dfs func(pos, mod, diff int, lead, limit bool) int
	dfs = func(pos, mod, diff int, lead, limit bool) int {
		if pos >= len(s) {
			if mod == 0 && diff == 10 {
				return 1
			}
			return 0
		}
		if !lead && !limit && f[pos][mod][diff] != -1 {
			return f[pos][mod][diff]
		}
		up := 9
		if limit {
			up = int(s[pos] - '0')
		}
		ans := 0
		for i := 0; i <= up; i++ {
			if i == 0 && lead {
				ans += dfs(pos+1, mod, diff, true, limit && i == up)
			} else {
				nxt := diff + 1
				if i%2 == 0 {
					nxt -= 2
				}
				ans += dfs(pos+1, (mod*10+i)%k, nxt, false, limit && i == up)
			}
		}
		if !lead && !limit {
			f[pos][mod][diff] = ans
		}
		return ans
	}

	a := dfs(0, 0, 10, true, true)
	s = strconv.Itoa(low - 1)
	f = g(len(s), k, 21)
	b := dfs(0, 0, 10, true, true)
	return a - b
}

func g(m, n, k int) [][][]int {
	f := make([][][]int, m)
	for i := 0; i < m; i++ {
		f[i] = make([][]int, n)
		for j := 0; j < n; j++ {
			f[i][j] = make([]int, k)
			for d := 0; d < k; d++ {
				f[i][j][d] = -1
			}
		}
	}
	return f
}
```

#### TypeScript

```ts
function numberOfBeautifulIntegers(low: number, high: number, k: number): number {
    let s = String(high);
    let f: number[][][] = Array(11)
        .fill(0)
        .map(() =>
            Array(21)
                .fill(0)
                .map(() => Array(21).fill(-1)),
        );
    const dfs = (pos: number, mod: number, diff: number, lead: boolean, limit: boolean): number => {
        if (pos >= s.length) {
            return mod == 0 && diff == 10 ? 1 : 0;
        }
        if (!lead && !limit && f[pos][mod][diff] != -1) {
            return f[pos][mod][diff];
        }
        let ans = 0;
        const up = limit ? Number(s[pos]) : 9;
        for (let i = 0; i <= up; ++i) {
            if (i === 0 && lead) {
                ans += dfs(pos + 1, mod, diff, true, limit && i === up);
            } else {
                const nxt = diff + (i % 2 ? 1 : -1);
                ans += dfs(pos + 1, (mod * 10 + i) % k, nxt, false, limit && i === up);
            }
        }
        if (!lead && !limit) {
            f[pos][mod][diff] = ans;
        }
        return ans;
    };
    const a = dfs(0, 0, 10, true, true);
    s = String(low - 1);
    f = Array(11)
        .fill(0)
        .map(() =>
            Array(21)
                .fill(0)
                .map(() => Array(21).fill(-1)),
        );
    const b = dfs(0, 0, 10, true, true);
    return a - b;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2828. 判别首字母缩略词](https://leetcode.cn/problems/check-if-a-string-is-an-acronym-of-words){#2828}

{{< tabs "2828" >}}

{{% tab "python" %}}
```python
class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        return len(words) == len(s) and all(w[0] == c for w, c in zip(words, s))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isAcronym(List<String> words, String s) {
        if (words.size() != s.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (words.get(i).charAt(0) != s.charAt(i)) {
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
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isAcronym(words []string, s string) bool {
	if len(words) != len(s) {
		return false
	}
	for i := range s {
		if words[i][0] != s[i] {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isAcronym(words: string[], s: string): boolean {
    if (words.length !== s.length) {
        return false;
    }
    for (let i = 0; i < words.length; i++) {
        if (words[i][0] !== s[i]) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_acronym(words: Vec<String>, s: String) -> bool {
        if words.len() != s.len() {
            return false;
        }
        for (i, w) in words.iter().enumerate() {
            if w.chars().next().unwrap_or_default() != s.chars().nth(i).unwrap_or_default() {
                return false;
            }
        }
        true
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组&nbsp;<code>words</code> 和一个字符串 <code>s</code> ，请你判断 <code>s</code> 是不是 <code>words</code> 的 <strong>首字母缩略词</strong> 。</p>

<p>如果可以按顺序串联 <code>words</code> 中每个字符串的第一个字符形成字符串 <code>s</code> ，则认为 <code>s</code> 是 <code>words</code> 的首字母缩略词。例如，<code>"ab"</code> 可以由 <code>["apple", "banana"]</code> 形成，但是无法从 <code>["bear", "aardvark"]</code> 形成。</p>

<p>如果 <code>s</code> 是 <code>words</code> 的首字母缩略词，返回 <code>true</code><em> </em>；否则，返回<em> </em><code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["alice","bob","charlie"], s = "abc"
<strong>输出：</strong>true
<strong>解释：</strong>words 中 "alice"、"bob" 和 "charlie" 的第一个字符分别是 'a'、'b' 和 'c'。因此，s = "abc" 是首字母缩略词。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["an","apple"], s = "a"
<strong>输出：</strong>false
<strong>解释：</strong>words 中 "an" 和 "apple" 的第一个字符分别是 'a' 和 'a'。
串联这些字符形成的首字母缩略词是 "aa" 。
因此，s = "a" 不是首字母缩略词。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["never","gonna","give","up","on","you"], s = "ngguoy"
<strong>输出：</strong>true
<strong>解释：</strong>串联数组 words 中每个字符串的第一个字符，得到字符串 "ngguoy" 。
因此，s = "ngguoy" 是首字母缩略词。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>words[i]</code> 和 <code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以遍历数组 $words$ 中的每个字符串，将其首字母拼接起来，得到一个新的字符串 $t$，然后判断 $t$ 是否等于 $s$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $words$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        return "".join(w[0] for w in words) == s
```

#### Java

```java
class Solution {
    public boolean isAcronym(List<String> words, String s) {
        StringBuilder t = new StringBuilder();
        for (var w : words) {
            t.append(w.charAt(0));
        }
        return t.toString().equals(s);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        for (auto& w : words) {
            t += w[0];
        }
        return t == s;
    }
};
```

#### Go

```go
func isAcronym(words []string, s string) bool {
	t := []byte{}
	for _, w := range words {
		t = append(t, w[0])
	}
	return string(t) == s
}
```

#### TypeScript

```ts
function isAcronym(words: string[], s: string): boolean {
    return words.map(w => w[0]).join('') === s;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_acronym(words: Vec<String>, s: String) -> bool {
        words
            .iter()
            .map(|w| w.chars().next().unwrap_or_default())
            .collect::<String>()
            == s
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：模拟（空间优化）

我们首先判断 $words$ 中的字符串个数是否等于 $s$ 的长度，如果不等于，那么 $s$ 一定不是 $words$ 的首字母缩略词，直接返回 $false$。

然后我们遍历 $s$ 的每个字符，判断其是否等于 $words$ 中对应字符串的首字母，如果不等于，那么 $s$ 一定不是 $words$ 的首字母缩略词，直接返回 $false$。

遍历结束后，如果没有返回 $false$，那么 $s$ 就是 $words$ 的首字母缩略词，返回 $true$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $words$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        return len(words) == len(s) and all(w[0] == c for w, c in zip(words, s))
```

#### Java

```java
class Solution {
    public boolean isAcronym(List<String> words, String s) {
        if (words.size() != s.length()) {
            return false;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (words.get(i).charAt(0) != s.charAt(i)) {
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
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isAcronym(words []string, s string) bool {
	if len(words) != len(s) {
		return false
	}
	for i := range s {
		if words[i][0] != s[i] {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isAcronym(words: string[], s: string): boolean {
    if (words.length !== s.length) {
        return false;
    }
    for (let i = 0; i < words.length; i++) {
        if (words[i][0] !== s[i]) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_acronym(words: Vec<String>, s: String) -> bool {
        if words.len() != s.len() {
            return false;
        }
        for (i, w) in words.iter().enumerate() {
            if w.chars().next().unwrap_or_default() != s.chars().nth(i).unwrap_or_default() {
                return false;
            }
        }
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2829. k-avoiding 数组的最小总和](https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array){#2829}

{{< tabs "2829" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        s, i = 0, 1
        vis = set()
        for _ in range(n):
            while i in vis:
                i += 1
            vis.add(k - i)
            s += i
            i += 1
        return s
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSum(int n, int k) {
        int s = 0, i = 1;
        boolean[] vis = new boolean[n + k + 1];
        while (n-- > 0) {
            while (vis[i]) {
                ++i;
            }
            if (k >= i) {
                vis[k - i] = true;
            }
            s += i++;
        }
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumSum(int n, int k) {
        int s = 0, i = 1;
        bool vis[n + k + 1];
        memset(vis, false, sizeof(vis));
        while (n--) {
            while (vis[i]) {
                ++i;
            }
            if (k >= i) {
                vis[k - i] = true;
            }
            s += i++;
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSum(n int, k int) int {
	s, i := 0, 1
	vis := make([]bool, n+k+1)
	for ; n > 0; n-- {
		for vis[i] {
			i++
		}
		if k >= i {
			vis[k-i] = true
		}
		s += i
		i++
	}
	return s
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSum(n: number, k: number): number {
    let s = 0;
    let i = 1;
    const vis: boolean[] = Array(n + k + 1).fill(false);
    while (n--) {
        while (vis[i]) {
            ++i;
        }
        if (k >= i) {
            vis[k - i] = true;
        }
        s += i++;
    }
    return s;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_sum(n: i32, k: i32) -> i32 {
        let (mut s, mut i) = (0, 1);
        let mut vis = std::collections::HashSet::new();

        for _ in 0..n {
            while vis.contains(&i) {
                i += 1;
            }
            vis.insert(k - i);
            s += i;
            i += 1;
        }

        s
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数 <code>n</code> 和 <code>k</code> 。</p>

<p>对于一个由 <strong>不同</strong> 正整数组成的数组，如果其中不存在任何求和等于 k 的不同元素对，则称其为 <strong>k-avoiding</strong> 数组。</p>

<p>返回长度为 <code>n</code> 的 <strong>k-avoiding</strong> 数组的可能的最小总和。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 5, k = 4
<strong>输出：</strong>18
<strong>解释：</strong>设若 k-avoiding 数组为 [1,2,4,5,6] ，其元素总和为 18 。
可以证明不存在总和小于 18 的 k-avoiding 数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 6
<strong>输出：</strong>3
<strong>解释：</strong>可以构造数组 [1,2] ，其元素总和为 3 。
可以证明不存在总和小于 3 的 k-avoiding 数组。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 模拟

我们从正整数 $i = 1$ 开始，依次判断 $i$ 是否可以加入数组中，如果可以加入，则将 $i$ 加入数组中，累加到答案中，然后将 $k - i$ 置为已访问，表示 $k-i$ 不能加入数组中。循环直到数组长度为 $n$。

时间复杂度 $O(n + k)$，空间复杂度 $O(n + k)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        s, i = 0, 1
        vis = set()
        for _ in range(n):
            while i in vis:
                i += 1
            vis.add(k - i)
            s += i
            i += 1
        return s
```

#### Java

```java
class Solution {
    public int minimumSum(int n, int k) {
        int s = 0, i = 1;
        boolean[] vis = new boolean[n + k + 1];
        while (n-- > 0) {
            while (vis[i]) {
                ++i;
            }
            if (k >= i) {
                vis[k - i] = true;
            }
            s += i++;
        }
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSum(int n, int k) {
        int s = 0, i = 1;
        bool vis[n + k + 1];
        memset(vis, false, sizeof(vis));
        while (n--) {
            while (vis[i]) {
                ++i;
            }
            if (k >= i) {
                vis[k - i] = true;
            }
            s += i++;
        }
        return s;
    }
};
```

#### Go

```go
func minimumSum(n int, k int) int {
	s, i := 0, 1
	vis := make([]bool, n+k+1)
	for ; n > 0; n-- {
		for vis[i] {
			i++
		}
		if k >= i {
			vis[k-i] = true
		}
		s += i
		i++
	}
	return s
}
```

#### TypeScript

```ts
function minimumSum(n: number, k: number): number {
    let s = 0;
    let i = 1;
    const vis: boolean[] = Array(n + k + 1).fill(false);
    while (n--) {
        while (vis[i]) {
            ++i;
        }
        if (k >= i) {
            vis[k - i] = true;
        }
        s += i++;
    }
    return s;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_sum(n: i32, k: i32) -> i32 {
        let (mut s, mut i) = (0, 1);
        let mut vis = std::collections::HashSet::new();

        for _ in 0..n {
            while vis.contains(&i) {
                i += 1;
            }
            vis.insert(k - i);
            s += i;
            i += 1;
        }

        s
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
