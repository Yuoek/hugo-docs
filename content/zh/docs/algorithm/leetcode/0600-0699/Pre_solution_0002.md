---
title: "0610_判断三角形"
date: 2025-10-08T18:36:23+08:00
weight: 2
tags: [二分查找, 二叉树, 双指针, 哈希表, 字典树, 字符串, 字符串匹配, 广度优先搜索, 排序, 数据库, 数组, 树, 深度优先搜索, 贪心]
---

{{< markmap >}}
### [0610_判断三角形](#610)
#### [数据库](#610)
### [0611_有效三角形的个数](#611)
#### [贪心](#611)
#### [数组](#611)
#### [双指针](#611)
#### [二分查找](#611)
#### [排序](#611)
### [0612_平面上的最近距离 🔒](#612)
#### [数据库](#612)
### [0613_直线上的最近距离 🔒](#613)
#### [数据库](#613)
### [0614_二级关注者 🔒](#614)
#### [数据库](#614)
### [0615_平均工资：部门与公司比较 🔒](#615)
#### [数据库](#615)
### [0616_给字符串添加加粗标签 🔒](#616)
#### [字典树](#616)
#### [数组](#616)
#### [哈希表](#616)
#### [字符串](#616)
#### [字符串匹配](#616)
### [0617_合并二叉树](#617)
#### [树](#617)
#### [深度优先搜索](#617)
#### [广度优先搜索](#617)
#### [二叉树](#617)
### [0618_学生地理信息报告 🔒](#618)
#### [数据库](#618)
### [0619_只出现一次的最大数字](#619)
#### [数据库](#619)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0610_判断三角形
___
#### 数据库
---
### 0611_有效三角形的个数
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 排序
---
### 0612_平面上的最近距离 🔒
___
#### 数据库
---
### 0613_直线上的最近距离 🔒
___
#### 数据库
---
### 0614_二级关注者 🔒
___
#### 数据库
---
### 0615_平均工资：部门与公司比较 🔒
___
#### 数据库
---
### 0616_给字符串添加加粗标签 🔒
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 字符串匹配
---
### 0617_合并二叉树
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 0618_学生地理信息报告 🔒
___
#### 数据库
---
### 0619_只出现一次的最大数字
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 双指针 |
| 哈希表 | 字典树 | 字符串 |
| 字符串匹配 | 广度优先搜索 | 排序 |
| 数据库 | 数组 | 树 |
| 深度优先搜索 | 贪心 |  |

# [610. 判断三角形](https://leetcode.cn/problems/triangle-judgement){#610}

{{< tabs "610" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    *,
    IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') AS triangle
FROM Triangle;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Triangle</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
在 SQL 中，(x, y, z)是该表的主键列。
该表的每一行包含三个线段的长度。
</pre>

<p>&nbsp;</p>

<p>对每三个线段报告它们是否可以形成一个三角形。</p>

<p>以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Triangle 表:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
<strong>输出:</strong> 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：IF 语句 + 三角形判断条件

三条边能否构成三角形的条件是：任意两边之和大于第三边。因此，我们可以使用 `IF` 语句来判断是否满足这个条件，如果满足则返回 `Yes`，否则返回 `No`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    *,
    IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No') AS triangle
FROM Triangle;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [611. 有效三角形的个数](https://leetcode.cn/problems/valid-triangle-number){#611}

{{< tabs "611" >}}

{{% tab "python" %}}
```python
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans, n = 0, len(nums)
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                k = bisect_left(nums, nums[i] + nums[j], lo=j + 1) - 1
                ans += k - j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0, n = nums.length; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int left = j + 1, right = n;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (nums[mid] >= nums[i] + nums[j]) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                ans += left - j - 1;
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
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                ans += k - j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func triangleNumber(nums []int) int {
	sort.Ints(nums)
	ans := 0
	for i, n := 0, len(nums); i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			left, right := j+1, n
			for left < right {
				mid := (left + right) >> 1
				if nums[mid] >= nums[i]+nums[j] {
					right = mid
				} else {
					left = mid + 1
				}
			}
			ans += left - j - 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function triangleNumber(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let n = nums.length;
    let ans = 0;
    for (let i = n - 1; i >= 2; i--) {
        let left = 0,
            right = i - 1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                ans += right - left;
                right--;
            } else {
                left++;
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn triangle_number(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let n = nums.len();
        let mut res = 0;
        for i in (2..n).rev() {
            let mut left = 0;
            let mut right = i - 1;
            while left < right {
                if nums[left] + nums[right] > nums[i] {
                    res += right - left;
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }
        res as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个包含非负整数的数组&nbsp;<code>nums</code> ，返回其中可以组成三角形三条边的三元组个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [2,2,3,4]
<strong>输出:</strong> 3
<strong>解释:</strong>有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,2,3,4]
<strong>输出:</strong> 4</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

一个有效三角形需要满足：**任意两边之和大于第三边**。即：`a + b > c`①, `a + c > b`②, `b + c > a`③。

如果我们将边按从小到大顺序排列，即 `a < b < c`，那么显然 ②③ 成立，我们只需要确保 ① 也成立，就可以形成一个有效三角形。

我们在 `[0, n - 3]` 范围内枚举 i，在 `[i + 1, n - 2]` 范围内枚举 j，在 `[j + 1, n - 1]` 范围内进行二分查找，找出第一个大于等于 `nums[i] + nums[j]` 的下标 left，那么在 `[j + 1, left - 1]` 范围内的 k 满足条件，将其累加到结果 ans。

时间复杂度：$O(n^2\log n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans, n = 0, len(nums)
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                k = bisect_left(nums, nums[i] + nums[j], lo=j + 1) - 1
                ans += k - j
        return ans
```

#### Java

```java
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int res = 0;
        for (int i = n - 1; i >= 2; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    res += r - l;
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                ans += k - j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func triangleNumber(nums []int) int {
	sort.Ints(nums)
	ans := 0
	for i, n := 0, len(nums); i < n-2; i++ {
		for j := i + 1; j < n-1; j++ {
			left, right := j+1, n
			for left < right {
				mid := (left + right) >> 1
				if nums[mid] >= nums[i]+nums[j] {
					right = mid
				} else {
					left = mid + 1
				}
			}
			ans += left - j - 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function triangleNumber(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let n = nums.length;
    let ans = 0;
    for (let i = n - 1; i >= 2; i--) {
        let left = 0,
            right = i - 1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                ans += right - left;
                right--;
            } else {
                left++;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn triangle_number(mut nums: Vec<i32>) -> i32 {
        nums.sort();
        let n = nums.len();
        let mut res = 0;
        for i in (2..n).rev() {
            let mut left = 0;
            let mut right = i - 1;
            while left < right {
                if nums[left] + nums[right] > nums[i] {
                    res += right - left;
                    right -= 1;
                } else {
                    left += 1;
                }
            }
        }
        res as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0, n = nums.length; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int left = j + 1, right = n;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (nums[mid] >= nums[i] + nums[j]) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                ans += left - j - 1;
            }
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

# [612. 平面上的最近距离 🔒](https://leetcode.cn/problems/shortest-distance-in-a-plane){#612}

{{< tabs "612" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT ROUND(SQRT(POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2)), 2) AS shortest
FROM
    Point2D AS p1
    JOIN Point2D AS p2 ON p1.x != p2.x OR p1.y != p2.y
ORDER BY 1
LIMIT 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Point2D</code> 表：</p>

<div class="original__bRMd">
<div>
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
+-------------+------+
(x, y) 是该表的主键列(具有唯一值的列的组合)。
这张表的每一行表示 X-Y 平面上一个点的位置
</pre>

<p>&nbsp;</p>

<p><code>p<sub>1</sub>(x<sub>1</sub>, y<sub>1</sub>)</code> 和 <code>p<sub>2</sub>(x<sub>2</sub>, y<sub>2</sub>)</code> 这两点之间的距离是 <code>sqrt((x<sub>2</sub> - x<sub>1</sub>)<sup>2</sup> + (y<sub>2</sub> - y<sub>1</sub>)<sup>2</sup>)</code> 。</p>

<p>编写解决方案，报告 <code>Point2D</code> 表中任意两点之间的最短距离。保留 <strong>2 位小数</strong> 。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Point2D table:
+----+----+
| x  | y  |
+----+----+
| -1 | -1 |
| 0  | 0  |
| -1 | -2 |
+----+----+
<strong>输出：</strong>
+----------+
| shortest |
+----------+
| 1.00     |
+----------+
<strong>解释：</strong>最短距离是 1.00 ，从点 (-1, -1) 到点 (-1, 2) 。
</pre>
</div>
</div>

<p>&nbsp;</p>

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
SELECT ROUND(SQRT(POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2)), 2) AS shortest
FROM
    Point2D AS p1
    JOIN Point2D AS p2 ON p1.x != p2.x OR p1.y != p2.y
ORDER BY 1
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [613. 直线上的最近距离 🔒](https://leetcode.cn/problems/shortest-distance-in-a-line){#613}

{{< tabs "613" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT x - LAG(x) OVER (ORDER BY x) AS shortest
FROM Point
ORDER BY 1
LIMIT 1, 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Point</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
+-------------+------+
在SQL中，x是该表的主键列。
该表的每一行表示X轴上一个点的位置。
</pre>

<p>&nbsp;</p>

<p>找到 <code>Point</code> 表中任意两点之间的最短距离。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Point 表:
+----+
| x  |
+----+
| -1 |
| 0  |
| 2  |
+----+
<b>输出：</b>
+----------+
| shortest |
+----------+
| 1        |
+----------+
<b>解释：</b>点 -1 和 0 之间的最短距离为 |(-1) - 0| = 1。
</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果 <code>Point</code> 表按 <strong>升序排列</strong>，如何优化你的解决方案？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接

我们可以使用自连接，将表中的每个点与其他更大的点进行连接，然后计算两点之间的距离，最后取最小值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT MIN(p2.x - p1.x) AS shortest
FROM
    Point AS p1
    JOIN Point AS p2 ON p1.x < p2.x;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们也可以使用窗口函数，将表中的点按照 $x$ 排序，然后计算相邻两点之间的距离，最后取最小值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT x - LAG(x) OVER (ORDER BY x) AS shortest
FROM Point
ORDER BY 1
LIMIT 1, 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [614. 二级关注者 🔒](https://leetcode.cn/problems/second-degree-follower){#614}

{{< tabs "614" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT f1.follower AS follower, f2.follower AS followee
        FROM
            Follow AS f1
            JOIN Follow AS f2 ON f1.follower = f2.followee
    )
SELECT follower, COUNT(DISTINCT followee) AS num
FROM T
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Follow</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| followee    | varchar |
| follower    | varchar |
+-------------+---------+
(followee, follower) 是该表的主键(具有唯一值的列的组合)。
该表的每一行表示关注者关注了社交网络上的被关注者。
不会有用户关注他们自己。
</pre>

<p>&nbsp;</p>

<p><strong>二级关注者</strong> 是指满足以下条件的用户:</p>

<ul>
	<li>关注至少一个用户，</li>
	<li>被至少一个用户关注。</li>
</ul>

<p>编写一个解决方案来报告 <strong>二级用户</strong> 及其关注者的数量。</p>

<p>返回按 <code>follower</code> <strong>字典序排序&nbsp;</strong>的结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Follow table:
+----------+----------+
| followee | follower |
+----------+----------+
| Alice    | Bob      |
| Bob      | Cena     |
| Bob      | Donald   |
| Donald   | Edward   |
+----------+----------+
<b>输出：</b>
+----------+-----+
| follower | num |
+----------+-----+
| Bob      | 2   |
| Donald   | 1   |
+----------+-----+
<b>解释：</b>
用户 Bob 有 2 个关注者。Bob 是二级关注者，因为他关注了 Alice，所以我们把他包括在结果表中。
用户 Donald 有 1 个关注者。Donald 是二级关注者，因为他关注了 Bob，所以我们把他包括在结果表中。
用户 Alice 有 1 个关注者。Alice 不是二级关注者，但是她不关注任何人，所以我们不把她包括在结果表中。</pre>

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
        SELECT f1.follower AS follower, f2.follower AS followee
        FROM
            Follow AS f1
            JOIN Follow AS f2 ON f1.follower = f2.followee
    )
SELECT follower, COUNT(DISTINCT followee) AS num
FROM T
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [615. 平均工资：部门与公司比较 🔒](https://leetcode.cn/problems/average-salary-departments-vs-company){#615}

{{< tabs "615" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT *
        FROM
            Salary
            JOIN Employee USING (employee_id)
    ),
    T AS (
        SELECT
            DATE_FORMAT(pay_date, '%Y-%m') AS pay_month,
            department_id,
            AVG(amount) OVER (PARTITION BY pay_date, department_id) AS department_avg,
            AVG(amount) OVER (PARTITION BY pay_date) AS company_avg
        FROM S
    )
SELECT
    pay_month,
    department_id,
    CASE
        WHEN AVG(department_avg) > AVG(company_avg) THEN 'higher'
        WHEN AVG(department_avg) < AVG(company_avg) THEN 'lower'
        ELSE 'same'
    END AS comparison
FROM T
GROUP BY 1, 2;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Salary</code></p>

<pre>
+-------------+------+
| 列名        | 类型 |
+-------------+------+
| id          | int  |
| employee_id | int  |
| amount      | int  |
| pay_date    | date |
+-------------+------+
在 SQL 中，id 是该表的主键列。
该表的每一行表示一个员工一个月的薪资。
employee_id 是来自 Employee 表的外键（reference 列）。</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Employee</code></p>

<pre>
+---------------+------+
| 列名          | 类型 |
+---------------+------+
| employee_id   | int  |
| department_id | int  |
+---------------+------+
在 SQL 中，employee_id 是该表的主键列。
该表的每一行表示一个员工所属的部门。</pre>

<p>&nbsp;</p>

<p>找出各个部门员工的平均薪资与公司平均薪资之间的比较结果（<strong>更高 / 更低 / 相同</strong>）。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Salary 表:
+----+-------------+--------+------------+
| id | employee_id | amount | pay_date   |
+----+-------------+--------+------------+
| 1  | 1           | 9000   | 2017/03/31 |
| 2  | 2           | 6000   | 2017/03/31 |
| 3  | 3           | 10000  | 2017/03/31 |
| 4  | 1           | 7000   | 2017/02/28 |
| 5  | 2           | 6000   | 2017/02/28 |
| 6  | 3           | 8000   | 2017/02/28 |
+----+-------------+--------+------------+
Employee 表:
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 2             |
| 3           | 2             |
+-------------+---------------+
<strong>输出：</strong>
+-----------+---------------+------------+
| pay_month | department_id | comparison |
+-----------+---------------+------------+
| 2017-02   | 1             | same       |
| 2017-03   | 1             | higher     |
| 2017-02   | 2             | same       |
| 2017-03   | 2             | lower      |
+-----------+---------------+------------+
<strong>解释：
</strong>在三月，公司的平均工资是 (9000+6000+10000)/3 = 8333.33...
部门 '1' 的平均薪资是 9000，因为该部门只有一个员工，其员工号为 '1'。因为 9000 &gt; 8333.33，所以比较结果为 'higher'
部门 '2' 的平均薪资是（6000 + 10000）/ 2 = 8000，该平均薪资是员工号 '2' 和 '3' 的薪资的平均值。因为 8000 &lt; 8333.33，比较结果为 'lower'。

根据同样的公式，对于二月份的平均薪资比较，结果为 'same'，因为部门 '1' 和 '2' 都与公司的平均薪资相同，即为 7000。</pre>

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
    t AS (
        SELECT
            DATE_FORMAT(pay_date, '%Y-%m') AS pay_month,
            department_id,
            AVG(amount) OVER (PARTITION BY pay_date) AS company_avg_amount,
            AVG(amount) OVER (PARTITION BY pay_date, department_id) AS department_avg_amount
        FROM
            Salary AS s
            JOIN Employee AS e ON s.employee_id = e.employee_id
    )
SELECT DISTINCT
    pay_month,
    department_id,
    CASE
        WHEN company_avg_amount = department_avg_amount THEN 'same'
        WHEN company_avg_amount < department_avg_amount THEN 'higher'
        ELSE 'lower'
    END AS comparison
FROM t;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT *
        FROM
            Salary
            JOIN Employee USING (employee_id)
    ),
    T AS (
        SELECT
            DATE_FORMAT(pay_date, '%Y-%m') AS pay_month,
            department_id,
            AVG(amount) OVER (PARTITION BY pay_date, department_id) AS department_avg,
            AVG(amount) OVER (PARTITION BY pay_date) AS company_avg
        FROM S
    )
SELECT
    pay_month,
    department_id,
    CASE
        WHEN AVG(department_avg) > AVG(company_avg) THEN 'higher'
        WHEN AVG(department_avg) < AVG(company_avg) THEN 'lower'
        ELSE 'same'
    END AS comparison
FROM T
GROUP BY 1, 2;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [616. 给字符串添加加粗标签 🔒](https://leetcode.cn/problems/add-bold-tag-in-string){#616}

{{< tabs "616" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 128
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c)
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def addBoldTag(self, s: str, words: List[str]) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(s)
        pairs = []
        for i in range(n):
            node = trie
            for j in range(i, n):
                idx = ord(s[j])
                if node.children[idx] is None:
                    break
                node = node.children[idx]
                if node.is_end:
                    pairs.append([i, j])
        if not pairs:
            return s
        st, ed = pairs[0]
        t = []
        for a, b in pairs[1:]:
            if ed + 1 < a:
                t.append([st, ed])
                st, ed = a, b
            else:
                ed = max(ed, b)
        t.append([st, ed])

        ans = []
        i = j = 0
        while i < n:
            if j == len(t):
                ans.append(s[i:])
                break
            st, ed = t[j]
            if i < st:
                ans.append(s[i:st])
            ans.append('<b>')
            ans.append(s[st : ed + 1])
            ans.append('</b>')
            j += 1
            i = ed + 1

        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[128];
    boolean isEnd;

    public void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    public String addBoldTag(String s, String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        List<int[]> pairs = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s.charAt(j);
                if (node.children[idx] == null) {
                    break;
                }
                node = node.children[idx];
                if (node.isEnd) {
                    pairs.add(new int[] {i, j});
                }
            }
        }
        if (pairs.isEmpty()) {
            return s;
        }
        List<int[]> t = new ArrayList<>();
        int st = pairs.get(0)[0], ed = pairs.get(0)[1];
        for (int j = 1; j < pairs.size(); ++j) {
            int a = pairs.get(j)[0], b = pairs.get(j)[1];
            if (ed + 1 < a) {
                t.add(new int[] {st, ed});
                st = a;
                ed = b;
            } else {
                ed = Math.max(ed, b);
            }
        }
        t.add(new int[] {st, ed});
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < n) {
            if (j == t.size()) {
                ans.append(s.substring(i));
                break;
            }
            st = t.get(j)[0];
            ed = t.get(j)[1];
            if (i < st) {
                ans.append(s.substring(i, st));
            }
            ++j;
            ans.append("<b>");
            ans.append(s.substring(st, ed + 1));
            ans.append("</b>");
            i = ed + 1;
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie() {
        children.resize(128);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        Trie* trie = new Trie();
        for (string w : words) trie->insert(w);
        int n = s.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s[j];
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) pairs.push_back({i, j});
            }
        }
        if (pairs.empty()) return s;
        vector<pair<int, int>> t;
        int st = pairs[0].first, ed = pairs[0].second;
        for (int i = 1; i < pairs.size(); ++i) {
            int a = pairs[i].first, b = pairs[i].second;
            if (ed + 1 < a) {
                t.push_back({st, ed});
                st = a, ed = b;
            } else
                ed = max(ed, b);
        }
        t.push_back({st, ed});
        string ans = "";
        int i = 0, j = 0;
        while (i < n) {
            if (j == t.size()) {
                ans += s.substr(i);
                break;
            }
            st = t[j].first, ed = t[j].second;
            if (i < st) ans += s.substr(i, st - i);
            ans += "<b>";
            ans += s.substr(st, ed - st + 1);
            ans += "</b>";
            i = ed + 1;
            ++j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [128]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func addBoldTag(s string, words []string) string {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	n := len(s)
	var pairs [][]int
	for i := range s {
		node := trie
		for j := i; j < n; j++ {
			if node.children[s[j]] == nil {
				break
			}
			node = node.children[s[j]]
			if node.isEnd {
				pairs = append(pairs, []int{i, j})
			}
		}
	}
	if len(pairs) == 0 {
		return s
	}
	var t [][]int
	st, ed := pairs[0][0], pairs[0][1]
	for i := 1; i < len(pairs); i++ {
		a, b := pairs[i][0], pairs[i][1]
		if ed+1 < a {
			t = append(t, []int{st, ed})
			st, ed = a, b
		} else {
			ed = max(ed, b)
		}
	}
	t = append(t, []int{st, ed})
	var ans strings.Builder
	i, j := 0, 0
	for i < n {
		if j == len(t) {
			ans.WriteString(s[i:])
			break
		}
		st, ed = t[j][0], t[j][1]
		if i < st {
			ans.WriteString(s[i:st])
		}
		ans.WriteString("<b>")
		ans.WriteString(s[st : ed+1])
		ans.WriteString("</b>")
		i = ed + 1
		j++
	}
	return ans.String()
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定字符串 <code>s</code> 和字符串数组 <code>words</code>。</p>

<p>对于 <code>s</code> 内部的子字符串，若其存在于 <code>words</code> 数组中， 则通过添加闭合的粗体标签<meta charset="UTF-8" />&nbsp;<code>&lt;b&gt;</code>&nbsp;和&nbsp;<code>&lt;/b&gt;</code>&nbsp;进行加粗标记。</p>

<ul>
	<li>如果两个这样的子字符串重叠，你应该仅使用一对闭合的粗体标签将它们包围起来。</li>
	<li>如果被粗体标签包围的两个子字符串是连续的，你应该将它们合并。</li>
</ul>

<p>返回添加加粗标签后的字符串 <code>s</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> s = "abcxyz123", words = ["abc","123"]
<strong>输出：</strong>"&lt;b&gt;abc&lt;/b&gt;xyz&lt;b&gt;123&lt;/b&gt;"
<strong>解释：</strong>两个单词字符串是 s 的子字符串，如下所示: "abcxyz123"。
我们在每个子字符串之前添加&lt;b&gt;，在每个子字符串之后添加&lt;/b&gt;。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabbb", words = ["aa","b"]
<strong>输出：</strong>"&lt;b&gt;aaabbb&lt;/b&gt;"
<strong>解释：</strong>
"aa"作为子字符串出现了两次: "<u>aa</u>abbb" 和 "a<u>aa</u>bbb"。
"b"作为子字符串出现了三次: "aaa<u>b</u>bb"、"aaab<u>b</u>b" 和 "aaabb<u>b</u>"。
我们在每个子字符串之前添加&lt;b&gt;，在每个子字符串之后添加&lt;/b&gt;: "&lt;b&gt;a&lt;b&gt;a&lt;/b&gt;a&lt;/b&gt;&lt;b&gt;b&lt;/b&gt;&lt;b&gt;b&lt;/b&gt;&lt;b&gt;b&lt;/b&gt;"。
由于前两个&lt;b&gt;重叠，把它们合并得到: "&lt;b&gt;aaa&lt;/b&gt;&lt;b&gt;b&lt;/b&gt;&lt;b&gt;b&lt;/b&gt;&lt;b&gt;b&lt;/b&gt;"。
由于现在这四个&lt;b&gt;是连续的，把它们合并得到: "&lt;b&gt;aaabbb&lt;/b&gt;"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>0 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
	<li><code>s</code> 和 <code>words[i]</code> 由英文字母和数字组成</li>
	<li><code>words</code> 中的所有值 <strong>互不相同</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>注：</strong>此题与「758 - 字符串中的加粗单词」相同 - <a href="https://leetcode.cn/problems/bold-words-in-string">https://leetcode.cn/problems/bold-words-in-string</a></p>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + 区间合并

相似题目：

-   [1065. 字符串的索引对](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1065.Index%20Pairs%20of%20a%20String/README.md)
-   [758. 字符串中的加粗单词](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0758.Bold%20Words%20in%20String/README.md)

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 128
        self.is_end = False

    def insert(self, word):
        node = self
        for c in word:
            idx = ord(c)
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.is_end = True


class Solution:
    def addBoldTag(self, s: str, words: List[str]) -> str:
        trie = Trie()
        for w in words:
            trie.insert(w)
        n = len(s)
        pairs = []
        for i in range(n):
            node = trie
            for j in range(i, n):
                idx = ord(s[j])
                if node.children[idx] is None:
                    break
                node = node.children[idx]
                if node.is_end:
                    pairs.append([i, j])
        if not pairs:
            return s
        st, ed = pairs[0]
        t = []
        for a, b in pairs[1:]:
            if ed + 1 < a:
                t.append([st, ed])
                st, ed = a, b
            else:
                ed = max(ed, b)
        t.append([st, ed])

        ans = []
        i = j = 0
        while i < n:
            if j == len(t):
                ans.append(s[i:])
                break
            st, ed = t[j]
            if i < st:
                ans.append(s[i:st])
            ans.append('<b>')
            ans.append(s[st : ed + 1])
            ans.append('</b>')
            j += 1
            i = ed + 1

        return ''.join(ans)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[128];
    boolean isEnd;

    public void insert(String word) {
        Trie node = this;
        for (char c : word.toCharArray()) {
            if (node.children[c] == null) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
        }
        node.isEnd = true;
    }
}

class Solution {
    public String addBoldTag(String s, String[] words) {
        Trie trie = new Trie();
        for (String w : words) {
            trie.insert(w);
        }
        List<int[]> pairs = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            Trie node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s.charAt(j);
                if (node.children[idx] == null) {
                    break;
                }
                node = node.children[idx];
                if (node.isEnd) {
                    pairs.add(new int[] {i, j});
                }
            }
        }
        if (pairs.isEmpty()) {
            return s;
        }
        List<int[]> t = new ArrayList<>();
        int st = pairs.get(0)[0], ed = pairs.get(0)[1];
        for (int j = 1; j < pairs.size(); ++j) {
            int a = pairs.get(j)[0], b = pairs.get(j)[1];
            if (ed + 1 < a) {
                t.add(new int[] {st, ed});
                st = a;
                ed = b;
            } else {
                ed = Math.max(ed, b);
            }
        }
        t.add(new int[] {st, ed});
        int i = 0, j = 0;
        StringBuilder ans = new StringBuilder();
        while (i < n) {
            if (j == t.size()) {
                ans.append(s.substring(i));
                break;
            }
            st = t.get(j)[0];
            ed = t.get(j)[1];
            if (i < st) {
                ans.append(s.substring(i, st));
            }
            ++j;
            ans.append("<b>");
            ans.append(s.substring(st, ed + 1));
            ans.append("</b>");
            i = ed + 1;
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Trie {
public:
    vector<Trie*> children;
    bool isEnd;

    Trie() {
        children.resize(128);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (!node->children[c]) node->children[c] = new Trie();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        Trie* trie = new Trie();
        for (string w : words) trie->insert(w);
        int n = s.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            Trie* node = trie;
            for (int j = i; j < n; ++j) {
                int idx = s[j];
                if (!node->children[idx]) break;
                node = node->children[idx];
                if (node->isEnd) pairs.push_back({i, j});
            }
        }
        if (pairs.empty()) return s;
        vector<pair<int, int>> t;
        int st = pairs[0].first, ed = pairs[0].second;
        for (int i = 1; i < pairs.size(); ++i) {
            int a = pairs[i].first, b = pairs[i].second;
            if (ed + 1 < a) {
                t.push_back({st, ed});
                st = a, ed = b;
            } else
                ed = max(ed, b);
        }
        t.push_back({st, ed});
        string ans = "";
        int i = 0, j = 0;
        while (i < n) {
            if (j == t.size()) {
                ans += s.substr(i);
                break;
            }
            st = t[j].first, ed = t[j].second;
            if (i < st) ans += s.substr(i, st - i);
            ans += "<b>";
            ans += s.substr(st, ed - st + 1);
            ans += "</b>";
            i = ed + 1;
            ++j;
        }
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [128]*Trie
	isEnd    bool
}

func newTrie() *Trie {
	return &Trie{}
}

func (this *Trie) insert(word string) {
	node := this
	for _, c := range word {
		if node.children[c] == nil {
			node.children[c] = newTrie()
		}
		node = node.children[c]
	}
	node.isEnd = true
}

func addBoldTag(s string, words []string) string {
	trie := newTrie()
	for _, w := range words {
		trie.insert(w)
	}
	n := len(s)
	var pairs [][]int
	for i := range s {
		node := trie
		for j := i; j < n; j++ {
			if node.children[s[j]] == nil {
				break
			}
			node = node.children[s[j]]
			if node.isEnd {
				pairs = append(pairs, []int{i, j})
			}
		}
	}
	if len(pairs) == 0 {
		return s
	}
	var t [][]int
	st, ed := pairs[0][0], pairs[0][1]
	for i := 1; i < len(pairs); i++ {
		a, b := pairs[i][0], pairs[i][1]
		if ed+1 < a {
			t = append(t, []int{st, ed})
			st, ed = a, b
		} else {
			ed = max(ed, b)
		}
	}
	t = append(t, []int{st, ed})
	var ans strings.Builder
	i, j := 0, 0
	for i < n {
		if j == len(t) {
			ans.WriteString(s[i:])
			break
		}
		st, ed = t[j][0], t[j][1]
		if i < st {
			ans.WriteString(s[i:st])
		}
		ans.WriteString("<b>")
		ans.WriteString(s[st : ed+1])
		ans.WriteString("</b>")
		i = ed + 1
		j++
	}
	return ans.String()
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees){#617}

{{< tabs "617" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        if root1 is None:
            return root2
        if root2 is None:
            return root1
        node = TreeNode(root1.val + root2.val)
        node.left = self.mergeTrees(root1.left, root2.left)
        node.right = self.mergeTrees(root1.right, root2.right)
        return node
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null) {
            return root2;
        }
        if (root2 == null) {
            return root1;
        }
        TreeNode node = new TreeNode(root1.val + root2.val);
        node.left = mergeTrees(root1.left, root2.left);
        node.right = mergeTrees(root1.right, root2.right);
        return node;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode* node = new TreeNode(root1->val + root2->val);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil {
		return root2
	}
	if root2 == nil {
		return root1
	}
	node := &TreeNode{Val: root1.Val + root2.Val}
	node.Left = mergeTrees(root1.Left, root2.Left)
	node.Right = mergeTrees(root1.Right, root2.Right)
	return node
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function mergeTrees(root1: TreeNode | null, root2: TreeNode | null): TreeNode | null {
    if (root1 === null && root2 === null) return null;
    if (root1 === null) return root2;
    if (root2 === null) return root1;
    const left = mergeTrees(root1.left, root2.left);
    const right = mergeTrees(root1.right, root2.right);
    return new TreeNode(root1.val + root2.val, left, right);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn merge_trees(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match (root1.is_some(), root2.is_some()) {
            (false, false) => None,
            (true, false) => root1,
            (false, true) => root2,
            (true, true) => {
                {
                    let mut r1 = root1.as_ref().unwrap().borrow_mut();
                    let mut r2 = root2.as_ref().unwrap().borrow_mut();
                    r1.val += r2.val;
                    r1.left = Self::merge_trees(r1.left.take(), r2.left.take());
                    r1.right = Self::merge_trees(r1.right.take(), r2.right.take());
                }
                root1
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */
var mergeTrees = function (root1, root2) {
    if (!root1) {
        return root2;
    }
    if (!root2) {
        return root1;
    }
    const node = new TreeNode(root1.val + root2.val);
    node.left = mergeTrees(root1.left, root2.left);
    node.right = mergeTrees(root1.right, root2.right);
    return node;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两棵二叉树： <code>root1</code> 和 <code>root2</code> 。</p>

<p>想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，<strong>不为</strong> null 的节点将直接作为新二叉树的节点。</p>

<p>返回合并后的二叉树。</p>

<p><strong>注意:</strong> 合并过程必须从两个树的根节点开始。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0600-0699/0617.Merge%20Two%20Binary%20Trees/images/merge.jpg" style="height: 163px; width: 600px;" />
<pre>
<strong>输入：</strong>root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
<strong>输出：</strong>[3,4,5,5,4,null,7]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root1 = [1], root2 = [1,2]
<strong>输出：</strong>[2,2]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>两棵树中的节点数目在范围 <code>[0, 2000]</code> 内</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

递归合并两棵树的节点。

-   如果其中一棵树的当前节点为空，则返回另一棵树的当前节点作为合并后节点。
-   如果两棵树的当前节点都不为空，则将它们的值相加作为合并后节点的新值，然后递归合并它们的左右子节点。

时间复杂度 $O(m)$，空间复杂度 $O(m)$。其中 $m$ 是两棵树的节点数的最小值。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(
        self, root1: Optional[TreeNode], root2: Optional[TreeNode]
    ) -> Optional[TreeNode]:
        if root1 is None:
            return root2
        if root2 is None:
            return root1
        node = TreeNode(root1.val + root2.val)
        node.left = self.mergeTrees(root1.left, root2.left)
        node.right = self.mergeTrees(root1.right, root2.right)
        return node
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        if (root1 == null) {
            return root2;
        }
        if (root2 == null) {
            return root1;
        }
        TreeNode node = new TreeNode(root1.val + root2.val);
        node.left = mergeTrees(root1.left, root2.left);
        node.right = mergeTrees(root1.right, root2.right);
        return node;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode* node = new TreeNode(root1->val + root2->val);
        node->left = mergeTrees(root1->left, root2->left);
        node->right = mergeTrees(root1->right, root2->right);
        return node;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil {
		return root2
	}
	if root2 == nil {
		return root1
	}
	node := &TreeNode{Val: root1.Val + root2.Val}
	node.Left = mergeTrees(root1.Left, root2.Left)
	node.Right = mergeTrees(root1.Right, root2.Right)
	return node
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function mergeTrees(root1: TreeNode | null, root2: TreeNode | null): TreeNode | null {
    if (root1 === null && root2 === null) return null;
    if (root1 === null) return root2;
    if (root2 === null) return root1;
    const left = mergeTrees(root1.left, root2.left);
    const right = mergeTrees(root1.right, root2.right);
    return new TreeNode(root1.val + root2.val, left, right);
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn merge_trees(
        root1: Option<Rc<RefCell<TreeNode>>>,
        root2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        match (root1.is_some(), root2.is_some()) {
            (false, false) => None,
            (true, false) => root1,
            (false, true) => root2,
            (true, true) => {
                {
                    let mut r1 = root1.as_ref().unwrap().borrow_mut();
                    let mut r2 = root2.as_ref().unwrap().borrow_mut();
                    r1.val += r2.val;
                    r1.left = Self::merge_trees(r1.left.take(), r2.left.take());
                    r1.right = Self::merge_trees(r1.right.take(), r2.right.take());
                }
                root1
            }
        }
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {TreeNode}
 */
var mergeTrees = function (root1, root2) {
    if (!root1) {
        return root2;
    }
    if (!root2) {
        return root1;
    }
    const node = new TreeNode(root1.val + root2.val);
    node.left = mergeTrees(root1.left, root2.left);
    node.right = mergeTrees(root1.right, root2.right);
    return node;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [618. 学生地理信息报告 🔒](https://leetcode.cn/problems/students-report-by-geography){#618}

{{< tabs "618" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY continent
                ORDER BY name
            ) AS rk
        FROM Student
    )
SELECT
    MAX(IF(continent = 'America', name, NULL)) AS 'America',
    MAX(IF(continent = 'Asia', name, NULL)) AS 'Asia',
    MAX(IF(continent = 'Europe', name, NULL)) AS 'Europe'
FROM T
GROUP BY rk;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>student</code>&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
+-------------+---------+
该表可能包含重复的行。
该表的每一行表示学生的名字和他们来自的大陆。
</pre>

<p>&nbsp;</p>

<p>一所学校有来自亚洲、欧洲和美洲的学生。</p>

<p>编写解决方案实现对大洲（continent）列的&nbsp;<a href="https://zh.wikipedia.org/wiki/%E9%80%8F%E8%A7%86%E8%A1%A8" target="_blank">透视表</a> 操作，使得每个<code>学生</code>按照姓名的<strong>字母顺序</strong>依次排列在对应的大洲下面。输出的标题应依次为<code>美洲（America）、亚洲（Asia）和欧洲（Europe）。</code></p>

<p>测试用例的生成保证来自美国的学生人数不少于亚洲或欧洲的学生人数。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Student table:
+--------+-----------+
| name   | continent |
+--------+-----------+
| Jane   | America   |
| Pascal | Europe    |
| Xi     | Asia      |
| Jack   | America   |
+--------+-----------+
<strong>输出:</strong> 
+---------+------+--------+
| America | Asia | Europe |
+---------+------+--------+
| Jack    | Xi   | Pascal |
| Jane    | null | null   |
+---------+------+--------+</pre>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果不能确定哪个大洲的学生数最多，你可以写出一个查询去生成上述学生报告吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数 + GROUP BY

我们可以使用窗口函数 `row_number()` 来为每个大洲的学生编号，然后使用 `GROUP BY` 来将同一编号的学生聚合到一行中。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY continent
                ORDER BY name
            ) AS rk
        FROM Student
    )
SELECT
    MAX(IF(continent = 'America', name, NULL)) AS 'America',
    MAX(IF(continent = 'Asia', name, NULL)) AS 'Asia',
    MAX(IF(continent = 'Europe', name, NULL)) AS 'Europe'
FROM T
GROUP BY rk;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [619. 只出现一次的最大数字](https://leetcode.cn/problems/biggest-single-number){#619}

{{< tabs "619" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN COUNT(1) = 1 THEN num
        ELSE NULL
    END AS num
FROM MyNumbers
GROUP BY num
ORDER BY 1 DESC
LIMIT 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>MyNumbers</code> 表：</p>

<div class="original__bRMd">
<div>
<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| num         | int  |
+-------------+------+
该表可能包含重复项（换句话说，在SQL中，该表没有主键）。
这张表的每一行都含有一个整数。
</pre>

<p>&nbsp;</p>

<p><strong>单一数字</strong> 是在 <code>MyNumbers</code> 表中只出现一次的数字。</p>

<p>找出最大的 <strong>单一数字</strong> 。如果不存在 <strong>单一数字</strong> ，则返回&nbsp;<code>null</code> 。</p>

<p>查询结果如下例所示。</p>
<ptable> </ptable>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
MyNumbers 表：
+-----+
| num |
+-----+
| 8   |
| 8   |
| 3   |
| 3   |
| 1   |
| 4   |
| 5   |
| 6   |
+-----+
<strong>输出：</strong>
+-----+
| num |
+-----+
| 6   |
+-----+
<strong>解释：</strong>单一数字有 1、4、5 和 6 。
6 是最大的单一数字，返回 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>
MyNumbers table:
+-----+
| num |
+-----+
| 8   |
| 8   |
| 7   |
| 7   |
| 3   |
| 3   |
| 3   |
+-----+
<strong>输出：</strong>
+------+
| num  |
+------+
| null |
+------+
<strong>解释：</strong>输入的表中不存在单一数字，所以返回 null 。
</pre>
</div>
</div>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 子查询

我们可以先将 `MyNumbers` 表按照 `num` 进行分组统计，找出只出现一次的数字，然后使用子查询找出最大的数字即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM
    (
        SELECT num
        FROM MyNumbers
        GROUP BY 1
        HAVING COUNT(1) = 1
    ) AS t;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：分组 + `CASE` 表达式

与方法一类似，我们可以先将 `MyNumbers` 表按照 `num` 进行分组统计，然后使用 `CASE` 表达式，找出只出现一次的数字，然后按数字降序排序，取第一个即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    CASE
        WHEN COUNT(1) = 1 THEN num
        ELSE NULL
    END AS num
FROM MyNumbers
GROUP BY num
ORDER BY 1 DESC
LIMIT 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
