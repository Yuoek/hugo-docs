---
title: "2010_职员招聘人数 II 🔒"
date: 2025-10-08T18:38:57+08:00
weight: 2
tags: [前缀和, 动态规划, 哈希表, 回溯, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 枚举, 栈, 模拟, 矩阵, 计数, 记忆化搜索, 设计, 贪心]
---

{{< markmap >}}
### [2010_职员招聘人数 II 🔒](#2010)
#### [数据库](#2010)
### [2011_执行操作后的变量值](#2011)
#### [数组](#2011)
#### [字符串](#2011)
#### [模拟](#2011)
### [2012_数组美丽值求和](#2012)
#### [数组](#2012)
### [2013_检测正方形](#2013)
#### [设计](#2013)
#### [数组](#2013)
#### [哈希表](#2013)
#### [计数](#2013)
### [2014_重复 K 次的最长子序列](#2014)
#### [贪心](#2014)
#### [字符串](#2014)
#### [回溯](#2014)
#### [计数](#2014)
#### [枚举](#2014)
### [2015_每段建筑物的平均高度 🔒](#2015)
#### [贪心](#2015)
#### [数组](#2015)
#### [排序](#2015)
#### [堆（优先队列）](#2015)
### [2016_增量元素之间的最大差值](#2016)
#### [数组](#2016)
### [2017_网格游戏](#2017)
#### [数组](#2017)
#### [矩阵](#2017)
#### [前缀和](#2017)
### [2018_判断单词是否能放入填字游戏内](#2018)
#### [数组](#2018)
#### [枚举](#2018)
#### [矩阵](#2018)
### [2019_解出数学表达式的学生分数](#2019)
#### [栈](#2019)
#### [记忆化搜索](#2019)
#### [数组](#2019)
#### [哈希表](#2019)
#### [数学](#2019)
#### [字符串](#2019)
#### [动态规划](#2019)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2010_职员招聘人数 II 🔒
___
#### 数据库
---
### 2011_执行操作后的变量值
___
#### 数组
___
#### 字符串
___
#### 模拟
---
### 2012_数组美丽值求和
___
#### 数组
---
### 2013_检测正方形
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2014_重复 K 次的最长子序列
___
#### 贪心
___
#### 字符串
___
#### 回溯
___
#### 计数
___
#### 枚举
---
### 2015_每段建筑物的平均高度 🔒
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2016_增量元素之间的最大差值
___
#### 数组
---
### 2017_网格游戏
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 2018_判断单词是否能放入填字游戏内
___
#### 数组
___
#### 枚举
___
#### 矩阵
---
### 2019_解出数学表达式的学生分数
___
#### 栈
___
#### 记忆化搜索
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 回溯 | 堆（优先队列） | 字符串 |
| 排序 | 数学 | 数据库 |
| 数组 | 枚举 | 栈 |
| 模拟 | 矩阵 | 计数 |
| 记忆化搜索 | 设计 | 贪心 |

# [2010. 职员招聘人数 II 🔒](https://leetcode.cn/problems/the-number-of-seniors-and-juniors-to-join-the-company-ii){#2010}

{{< tabs "2010" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    s AS (
        SELECT
            employee_id,
            SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Senior'
    ),
    j AS (
        SELECT
            employee_id,
            IFNULL(
                SELECT
                    MAX(cur)
                FROM s
                WHERE cur <= 70000,
                0
            ) + SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Junior'
    )
SELECT
    employee_id
FROM s
WHERE cur <= 70000
UNION
SELECT
    employee_id
FROM j
WHERE cur <= 70000;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Candidates</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| employee_id | int  |
| experience  | enum |
| salary      | int  |
+-------------+------+
employee_id 是该表中具有唯一值的列。
经验是一个枚举，其中包含一个值（“高级”、“初级”）。
此表的每一行都显示候选人的id、月薪和经验。
每个候选人的工资保证是 <strong>唯一</strong> 的。</pre>

<p>&nbsp;</p>

<p>一家公司想雇佣新员工。公司的工资预算是 <code>$70000</code> 。公司的招聘标准是：</p>

<ol>
	<li>继续雇佣薪水最低的高级职员，直到你不能再雇佣更多的高级职员。</li>
	<li>用剩下的预算雇佣薪水最低的初级职员。</li>
	<li>继续以最低的工资雇佣初级职员，直到你不能再雇佣更多的初级职员。</li>
</ol>

<p>编写一个解决方案，查找根据上述条件雇用职员的 ID。<br />
按 <strong>任意顺序 </strong>返回结果表。<br />
返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong>
Candidates table:
+-------------+------------+--------+
| employee_id | experience | salary |
+-------------+------------+--------+
| 1           | Junior     | 10000  |
| 9           | Junior     | 15000  |
| 2           | Senior     | 20000  |
| 11          | Senior     | 16000  |
| 13          | Senior     | 50000  |
| 4           | Junior     | 40000  |
+-------------+------------+--------+
<strong>输出:</strong> 
+-------------+
| employee_id |
+-------------+
| 11          |
| 2           |
| 1           |
| 9           |
+-------------+
<strong>解释:</strong> 
我们可以雇佣2名具有ID（11,2）的高级员工。由于预算是7万美元，他们的工资总额是3.6万美元，我们还有3.4万美元，但他们不足以雇佣ID为 13 的高级职员。
我们可以雇佣2名ID为（1,9）的初级员工。由于剩余预算为3.4万美元，他们的工资总额为2.5万美元，我们还有9000美元，但他们不足以雇佣ID为 4 的初级员工。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong>
Candidates table:
+-------------+------------+--------+
| employee_id | experience | salary |
+-------------+------------+--------+
| 1           | Junior     | 25000  |
| 9           | Junior     | 10000  |
| 2           | Senior     | 85000  |
| 11          | Senior     | 80000  |
| 13          | Senior     | 90000  |
| 4           | Junior     | 30000  |
+-------------+------------+--------+
<strong>输出:</strong> 
+-------------+
| employee_id |
+-------------+
| 9           |
| 1           |
| 4           |
+-------------+
<strong>解释:</strong> 
我们不能用目前的预算雇佣任何高级员工，因为我们需要至少 80000 美元来雇佣一名高级员工。
我们可以用剩下的预算雇佣三名初级员工。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

相似题目：

-   [2004. 职员招聘人数](https://github.com/doocs/leetcode/blob/main/solution/2000-2099/2004.The%20Number%20of%20Seniors%20and%20Juniors%20to%20Join%20the%20Company/README.md)

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    s AS (
        SELECT
            employee_id,
            SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Senior'
    ),
    j AS (
        SELECT
            employee_id,
            IFNULL(
                SELECT
                    MAX(cur)
                FROM s
                WHERE cur <= 70000,
                0
            ) + SUM(salary) OVER (ORDER BY salary) AS cur
        FROM Candidates
        WHERE experience = 'Junior'
    )
SELECT
    employee_id
FROM s
WHERE cur <= 70000
UNION
SELECT
    employee_id
FROM j
WHERE cur <= 70000;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2011. 执行操作后的变量值](https://leetcode.cn/problems/final-value-of-variable-after-performing-operations){#2011}

{{< tabs "2011" >}}

{{% tab "python" %}}
```python
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if s[1] == '+' else -1 for s in operations)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (var s : operations) {
            ans += (s.charAt(1) == '+' ? 1 : -1);
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
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& s : operations) {
            ans += s[1] == '+' ? 1 : -1;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func finalValueAfterOperations(operations []string) (ans int) {
	for _, s := range operations {
		if s[1] == '+' {
			ans += 1
		} else {
			ans -= 1
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function finalValueAfterOperations(operations: string[]): number {
    return operations.reduce((acc, op) => acc + (op[1] === '+' ? 1 : -1), 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut ans = 0;
        for s in operations.iter() {
            ans += if s.as_bytes()[1] == b'+' { 1 } else { -1 };
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function (operations) {
    return operations.reduce((acc, op) => acc + (op[1] === '+' ? 1 : -1), 0);
};
```
{{% /tab %}}
{{% tab "c" %}}
```c
int finalValueAfterOperations(char** operations, int operationsSize) {
    int ans = 0;
    for (int i = 0; i < operationsSize; i++) {
        ans += operations[i][1] == '+' ? 1 : -1;
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

<p>存在一种仅支持 4 种操作和 1 个变量 <code>X</code> 的编程语言：</p>

<ul>
	<li><code>++X</code> 和 <code>X++</code> 使变量 <code>X</code> 的值 <strong>加</strong> <code>1</code></li>
	<li><code>--X</code> 和 <code>X--</code> 使变量 <code>X</code> 的值 <strong>减</strong> <code>1</code></li>
</ul>

<p>最初，<code>X</code> 的值是 <code>0</code></p>

<p>给你一个字符串数组 <code>operations</code> ，这是由操作组成的一个列表，返回执行所有操作后，<em> </em><code>X</code> 的 <strong>最终值</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>operations = ["--X","X++","X++"]
<strong>输出：</strong>1
<strong>解释：</strong>操作按下述步骤执行：
最初，X = 0
--X：X 减 1 ，X =  0 - 1 = -1
X++：X 加 1 ，X = -1 + 1 =  0
X++：X 加 1 ，X =  0 + 1 =  1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>operations = ["++X","++X","X++"]
<strong>输出：</strong>3
<strong>解释：</strong>操作按下述步骤执行： 
最初，X = 0
++X：X 加 1 ，X = 0 + 1 = 1
++X：X 加 1 ，X = 1 + 1 = 2
X++：X 加 1 ，X = 2 + 1 = 3
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>operations = ["X++","++X","--X","X--"]
<strong>输出：</strong>0
<strong>解释：</strong>操作按下述步骤执行：
最初，X = 0
X++：X 加 1 ，X = 0 + 1 = 1
++X：X 加 1 ，X = 1 + 1 = 2
--X：X 减 1 ，X = 2 - 1 = 1
X--：X 减 1 ，X = 1 - 1 = 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= operations.length &lt;= 100</code></li>
	<li><code>operations[i]</code> 将会是 <code>"++X"</code>、<code>"X++"</code>、<code>"--X"</code> 或 <code>"X--"</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们遍历数组 $\textit{operations}$，对于每个操作 $\textit{operations}[i]$，如果包含 `'+'`，那么答案加 $1$，否则答案减 $1$。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{operations}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return sum(1 if s[1] == '+' else -1 for s in operations)
```

#### Java

```java
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (var s : operations) {
            ans += (s.charAt(1) == '+' ? 1 : -1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& s : operations) {
            ans += s[1] == '+' ? 1 : -1;
        }
        return ans;
    }
};
```

#### Go

```go
func finalValueAfterOperations(operations []string) (ans int) {
	for _, s := range operations {
		if s[1] == '+' {
			ans += 1
		} else {
			ans -= 1
		}
	}
	return
}
```

#### TypeScript

```ts
function finalValueAfterOperations(operations: string[]): number {
    return operations.reduce((acc, op) => acc + (op[1] === '+' ? 1 : -1), 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut ans = 0;
        for s in operations.iter() {
            ans += if s.as_bytes()[1] == b'+' { 1 } else { -1 };
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function (operations) {
    return operations.reduce((acc, op) => acc + (op[1] === '+' ? 1 : -1), 0);
};
```

#### C

```c
int finalValueAfterOperations(char** operations, int operationsSize) {
    int ans = 0;
    for (int i = 0; i < operationsSize; i++) {
        ans += operations[i][1] == '+' ? 1 : -1;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2012. 数组美丽值求和](https://leetcode.cn/problems/sum-of-beauty-in-the-array){#2012}

{{< tabs "2012" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        right = [nums[-1]] * n
        for i in range(n - 2, -1, -1):
            right[i] = min(right[i + 1], nums[i])
        ans = 0
        l = nums[0]
        for i in range(1, n - 1):
            r = right[i + 1]
            if l < nums[i] < r:
                ans += 2
            elif nums[i - 1] < nums[i] < nums[i + 1]:
                ans += 1
            l = max(l, nums[i])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length;
        int[] right = new int[n];
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; --i) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = 0;
        int l = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            int r = right[i + 1];
            if (l < nums[i] && nums[i] < r) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            l = Math.max(l, nums[i]);
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
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, nums[n - 1]);
        for (int i = n - 2; i; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int ans = 0;
        for (int i = 1, l = nums[0]; i < n - 1; ++i) {
            int r = right[i + 1];
            if (l < nums[i] && nums[i] < r) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            l = max(l, nums[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfBeauties(nums []int) (ans int) {
	n := len(nums)
	right := make([]int, n)
	right[n-1] = nums[n-1]
	for i := n - 2; i > 0; i-- {
		right[i] = min(right[i+1], nums[i])
	}
	for i, l := 1, nums[0]; i < n-1; i++ {
		r := right[i+1]
		if l < nums[i] && nums[i] < r {
			ans += 2
		} else if nums[i-1] < nums[i] && nums[i] < nums[i+1] {
			ans++
		}
		l = max(l, nums[i])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfBeauties(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n).fill(nums[n - 1]);
    for (let i = n - 2; i; --i) {
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    let ans = 0;
    for (let i = 1, l = nums[0]; i < n - 1; ++i) {
        const r = right[i + 1];
        if (l < nums[i] && nums[i] < r) {
            ans += 2;
        } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            ans += 1;
        }
        l = Math.max(l, nums[i]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut right: Vec<i32> = vec![0; n];
        right[n - 1] = nums[n - 1];
        for i in (1..n - 1).rev() {
            right[i] = right[i + 1].min(nums[i]);
        }
        let mut ans = 0;
        let mut l = nums[0];
        for i in 1..n - 1 {
            let r = right[i + 1];
            if l < nums[i] && nums[i] < r {
                ans += 2;
            } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
                ans += 1;
            }
            l = l.max(nums[i]);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。对于每个下标 <code>i</code>（<code>1 &lt;= i &lt;= nums.length - 2</code>），<code>nums[i]</code> 的 <strong>美丽值</strong> 等于：</p>

<ul>
	<li><code>2</code>，对于所有 <code>0 &lt;= j &lt; i</code> 且 <code>i &lt; k &lt;= nums.length - 1</code> ，满足 <code>nums[j] &lt; nums[i] &lt; nums[k]</code></li>
	<li><code>1</code>，如果满足 <code>nums[i - 1] &lt; nums[i] &lt; nums[i + 1]</code> ，且不满足前面的条件</li>
	<li><code>0</code>，如果上述条件全部不满足</li>
</ul>

<p>返回符合 <code>1 &lt;= i &lt;= nums.length - 2</code> 的所有<em> </em><code>nums[i]</code><em> </em>的 <strong>美丽值的总和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>对于每个符合范围 1 &lt;= i &lt;= 1 的下标 i :
- nums[1] 的美丽值等于 2
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [2,4,6,4]
<strong>输出：</strong>1
<strong>解释：</strong>对于每个符合范围 1 &lt;= i &lt;= 2 的下标 i :
- nums[1] 的美丽值等于 1
- nums[2] 的美丽值等于 0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [3,2,1]
<strong>输出：</strong>0
<strong>解释：</strong>对于每个符合范围 1 &lt;= i &lt;= 1 的下标 i :
- nums[1] 的美丽值等于 0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理右侧最小值 + 遍历维护左侧最大值

我们可以预处理出右侧最小值数组 $right$，其中 $right[i]$ 表示 $nums[i..n-1]$ 中的最小值。

然后我们从左到右遍历数组 $nums$，同时维护左侧最大值 $l$。对于每个位置 $i$，我们判断 $l < nums[i] < right[i + 1]$ 是否成立，如果成立则将 $2$ 累加至答案，否则判断 $nums[i - 1] < nums[i] < nums[i + 1]$ 是否成立，如果成立则将 $1$ 累加至答案。

遍历结束后即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        right = [nums[-1]] * n
        for i in range(n - 2, -1, -1):
            right[i] = min(right[i + 1], nums[i])
        ans = 0
        l = nums[0]
        for i in range(1, n - 1):
            r = right[i + 1]
            if l < nums[i] < r:
                ans += 2
            elif nums[i - 1] < nums[i] < nums[i + 1]:
                ans += 1
            l = max(l, nums[i])
        return ans
```

#### Java

```java
class Solution {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length;
        int[] right = new int[n];
        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 0; --i) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = 0;
        int l = nums[0];
        for (int i = 1; i < n - 1; ++i) {
            int r = right[i + 1];
            if (l < nums[i] && nums[i] < r) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            l = Math.max(l, nums[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, nums[n - 1]);
        for (int i = n - 2; i; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int ans = 0;
        for (int i = 1, l = nums[0]; i < n - 1; ++i) {
            int r = right[i + 1];
            if (l < nums[i] && nums[i] < r) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
            l = max(l, nums[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func sumOfBeauties(nums []int) (ans int) {
	n := len(nums)
	right := make([]int, n)
	right[n-1] = nums[n-1]
	for i := n - 2; i > 0; i-- {
		right[i] = min(right[i+1], nums[i])
	}
	for i, l := 1, nums[0]; i < n-1; i++ {
		r := right[i+1]
		if l < nums[i] && nums[i] < r {
			ans += 2
		} else if nums[i-1] < nums[i] && nums[i] < nums[i+1] {
			ans++
		}
		l = max(l, nums[i])
	}
	return
}
```

#### TypeScript

```ts
function sumOfBeauties(nums: number[]): number {
    const n = nums.length;
    const right: number[] = Array(n).fill(nums[n - 1]);
    for (let i = n - 2; i; --i) {
        right[i] = Math.min(right[i + 1], nums[i]);
    }
    let ans = 0;
    for (let i = 1, l = nums[0]; i < n - 1; ++i) {
        const r = right[i + 1];
        if (l < nums[i] && nums[i] < r) {
            ans += 2;
        } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            ans += 1;
        }
        l = Math.max(l, nums[i]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut right: Vec<i32> = vec![0; n];
        right[n - 1] = nums[n - 1];
        for i in (1..n - 1).rev() {
            right[i] = right[i + 1].min(nums[i]);
        }
        let mut ans = 0;
        let mut l = nums[0];
        for i in 1..n - 1 {
            let r = right[i + 1];
            if l < nums[i] && nums[i] < r {
                ans += 2;
            } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
                ans += 1;
            }
            l = l.max(nums[i]);
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

# [2013. 检测正方形](https://leetcode.cn/problems/detect-squares){#2013}

{{< tabs "2013" >}}

{{% tab "python" %}}
```python
class DetectSquares:
    def __init__(self):
        self.cnt = defaultdict(Counter)

    def add(self, point: List[int]) -> None:
        x, y = point
        self.cnt[x][y] += 1

    def count(self, point: List[int]) -> int:
        x1, y1 = point
        if x1 not in self.cnt:
            return 0
        ans = 0
        for x2 in self.cnt.keys():
            if x2 != x1:
                d = x2 - x1
                ans += self.cnt[x2][y1] * self.cnt[x1][y1 + d] * self.cnt[x2][y1 + d]
                ans += self.cnt[x2][y1] * self.cnt[x1][y1 - d] * self.cnt[x2][y1 - d]
        return ans


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class DetectSquares {
    private Map<Integer, Map<Integer, Integer>> cnt = new HashMap<>();

    public DetectSquares() {
    }

    public void add(int[] point) {
        int x = point[0], y = point[1];
        cnt.computeIfAbsent(x, k -> new HashMap<>()).merge(y, 1, Integer::sum);
    }

    public int count(int[] point) {
        int x1 = point[0], y1 = point[1];
        if (!cnt.containsKey(x1)) {
            return 0;
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            int x2 = e.getKey();
            if (x2 != x1) {
                int d = x2 - x1;
                var cnt1 = cnt.get(x1);
                var cnt2 = e.getValue();
                ans += cnt2.getOrDefault(y1, 0) * cnt1.getOrDefault(y1 + d, 0)
                    * cnt2.getOrDefault(y1 + d, 0);
                ans += cnt2.getOrDefault(y1, 0) * cnt1.getOrDefault(y1 - d, 0)
                    * cnt2.getOrDefault(y1 - d, 0);
            }
        }
        return ans;
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class DetectSquares {
public:
    DetectSquares() {
    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ++cnt[x][y];
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        if (!cnt.count(x1)) {
            return 0;
        }
        int ans = 0;
        for (auto& [x2, cnt2] : cnt) {
            if (x2 != x1) {
                int d = x2 - x1;
                auto& cnt1 = cnt[x1];
                ans += cnt2[y1] * cnt1[y1 + d] * cnt2[y1 + d];
                ans += cnt2[y1] * cnt1[y1 - d] * cnt2[y1 - d];
            }
        }
        return ans;
    }

private:
    unordered_map<int, unordered_map<int, int>> cnt;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type DetectSquares struct {
	cnt map[int]map[int]int
}

func Constructor() DetectSquares {
	return DetectSquares{map[int]map[int]int{}}
}

func (this *DetectSquares) Add(point []int) {
	x, y := point[0], point[1]
	if _, ok := this.cnt[x]; !ok {
		this.cnt[x] = map[int]int{}
	}
	this.cnt[x][y]++
}

func (this *DetectSquares) Count(point []int) (ans int) {
	x1, y1 := point[0], point[1]
	if cnt1, ok := this.cnt[x1]; ok {
		for x2, cnt2 := range this.cnt {
			if x2 != x1 {
				d := x2 - x1
				ans += cnt2[y1] * cnt1[y1+d] * cnt2[y1+d]
				ans += cnt2[y1] * cnt1[y1-d] * cnt2[y1-d]
			}
		}
	}
	return
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(point);
 * param_2 := obj.Count(point);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个在 X-Y 平面上的点构成的数据流。设计一个满足下述要求的算法：</p>

<ul>
	<li><strong>添加</strong> 一个在数据流中的新点到某个数据结构中<strong>。</strong>可以添加 <strong>重复</strong> 的点，并会视作不同的点进行处理。</li>
	<li>给你一个查询点，请你从数据结构中选出三个点，使这三个点和查询点一同构成一个 <strong>面积为正</strong> 的 <strong>轴对齐正方形</strong> ，<strong>统计</strong> 满足该要求的方案数目<strong>。</strong></li>
</ul>

<p><strong>轴对齐正方形</strong> 是一个正方形，除四条边长度相同外，还满足每条边都与 x-轴 或 y-轴 平行或垂直。</p>

<p>实现 <code>DetectSquares</code> 类：</p>

<ul>
	<li><code>DetectSquares()</code> 使用空数据结构初始化对象</li>
	<li><code>void add(int[] point)</code> 向数据结构添加一个新的点 <code>point = [x, y]</code></li>
	<li><code>int count(int[] point)</code> 统计按上述方式与点 <code>point = [x, y]</code> 共同构造 <strong>轴对齐正方形</strong> 的方案数。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2013.Detect%20Squares/images/image.png" style="width: 869px; height: 504px;" />
<pre>
<strong>输入：</strong>
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
<strong>输出：</strong>
[null, null, null, null, 1, 0, null, 2]

<strong>解释：</strong>
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // 返回 1 。你可以选择：
// - 第一个，第二个，和第三个点
detectSquares.count([14, 8]); // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
detectSquares.add([11, 2]); // 允许添加重复的点。
detectSquares.count([11, 10]); // 返回 2 。你可以选择：
// - 第一个，第二个，和第三个点
// - 第一个，第三个，和第四个点

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>point.length == 2</code></li>
	<li><code>0 &lt;= x, y &lt;= 1000</code></li>
	<li>调用&nbsp;<code>add</code> 和 <code>count</code> 的 <strong>总次数</strong> 最多为 <code>5000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $cnt$ 维护所有点的信息，其中 $cnt[x][y]$ 表示点 $(x, y)$ 的个数。

当调用 $add(x, y)$ 方法时，我们将 $cnt[x][y]$ 的值加 $1$。

当调用 $count(x_1, y_1)$ 方法时，我们需要获取另外的三个点，构成一个轴对齐正方形。我们可以枚举平行于 $x$ 轴且与 $(x_1, y_1)$ 的距离为 $d$ 的点 $(x_2, y_1)$，如果存在这样的点，根据这两个点，我们可以确定另外两个点为 $(x_1, y_1 + d)$ 和 $(x_2, y_1 + d)$，或者 $(x_1, y_1 - d)$ 和 $(x_2, y_1 - d)$。我们将这两种情况的方案数累加即可。

时间复杂度方面，调用 $add(x, y)$ 方法的时间复杂度为 $O(1)$，调用 $count(x_1, y_1)$ 方法的时间复杂度为 $O(n)$；空间复杂度为 $O(n)$。其中 $n$ 为数据流中的点的个数。

<!-- tabs:start -->

#### Python3

```python
class DetectSquares:
    def __init__(self):
        self.cnt = defaultdict(Counter)

    def add(self, point: List[int]) -> None:
        x, y = point
        self.cnt[x][y] += 1

    def count(self, point: List[int]) -> int:
        x1, y1 = point
        if x1 not in self.cnt:
            return 0
        ans = 0
        for x2 in self.cnt.keys():
            if x2 != x1:
                d = x2 - x1
                ans += self.cnt[x2][y1] * self.cnt[x1][y1 + d] * self.cnt[x2][y1 + d]
                ans += self.cnt[x2][y1] * self.cnt[x1][y1 - d] * self.cnt[x2][y1 - d]
        return ans


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
```

#### Java

```java
class DetectSquares {
    private Map<Integer, Map<Integer, Integer>> cnt = new HashMap<>();

    public DetectSquares() {
    }

    public void add(int[] point) {
        int x = point[0], y = point[1];
        cnt.computeIfAbsent(x, k -> new HashMap<>()).merge(y, 1, Integer::sum);
    }

    public int count(int[] point) {
        int x1 = point[0], y1 = point[1];
        if (!cnt.containsKey(x1)) {
            return 0;
        }
        int ans = 0;
        for (var e : cnt.entrySet()) {
            int x2 = e.getKey();
            if (x2 != x1) {
                int d = x2 - x1;
                var cnt1 = cnt.get(x1);
                var cnt2 = e.getValue();
                ans += cnt2.getOrDefault(y1, 0) * cnt1.getOrDefault(y1 + d, 0)
                    * cnt2.getOrDefault(y1 + d, 0);
                ans += cnt2.getOrDefault(y1, 0) * cnt1.getOrDefault(y1 - d, 0)
                    * cnt2.getOrDefault(y1 - d, 0);
            }
        }
        return ans;
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */
```

#### C++

```cpp
class DetectSquares {
public:
    DetectSquares() {
    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        ++cnt[x][y];
    }

    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        if (!cnt.count(x1)) {
            return 0;
        }
        int ans = 0;
        for (auto& [x2, cnt2] : cnt) {
            if (x2 != x1) {
                int d = x2 - x1;
                auto& cnt1 = cnt[x1];
                ans += cnt2[y1] * cnt1[y1 + d] * cnt2[y1 + d];
                ans += cnt2[y1] * cnt1[y1 - d] * cnt2[y1 - d];
            }
        }
        return ans;
    }

private:
    unordered_map<int, unordered_map<int, int>> cnt;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
```

#### Go

```go
type DetectSquares struct {
	cnt map[int]map[int]int
}

func Constructor() DetectSquares {
	return DetectSquares{map[int]map[int]int{}}
}

func (this *DetectSquares) Add(point []int) {
	x, y := point[0], point[1]
	if _, ok := this.cnt[x]; !ok {
		this.cnt[x] = map[int]int{}
	}
	this.cnt[x][y]++
}

func (this *DetectSquares) Count(point []int) (ans int) {
	x1, y1 := point[0], point[1]
	if cnt1, ok := this.cnt[x1]; ok {
		for x2, cnt2 := range this.cnt {
			if x2 != x1 {
				d := x2 - x1
				ans += cnt2[y1] * cnt1[y1+d] * cnt2[y1+d]
				ans += cnt2[y1] * cnt1[y1-d] * cnt2[y1-d]
			}
		}
	}
	return
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(point);
 * param_2 := obj.Count(point);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2014. 重复 K 次的最长子序列](https://leetcode.cn/problems/longest-subsequence-repeated-k-times){#2014}

{{< tabs "2014" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        def check(t: str, k: int) -> bool:
            i = 0
            for c in s:
                if c == t[i]:
                    i += 1
                    if i == len(t):
                        k -= 1
                        if k == 0:
                            return True
                        i = 0
            return False

        cnt = Counter(s)
        cs = [c for c in ascii_lowercase if cnt[c] >= k]
        q = deque([""])
        ans = ""
        while q:
            cur = q.popleft()
            for c in cs:
                nxt = cur + c
                if check(nxt, k):
                    ans = nxt
                    q.append(nxt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private char[] s;

    public String longestSubsequenceRepeatedK(String s, int k) {
        this.s = s.toCharArray();
        int[] cnt = new int[26];
        for (char c : this.s) {
            cnt[c - 'a']++;
        }

        List<Character> cs = new ArrayList<>();
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c - 'a'] >= k) {
                cs.add(c);
            }
        }
        Deque<String> q = new ArrayDeque<>();
        q.offer("");
        String ans = "";
        while (!q.isEmpty()) {
            String cur = q.poll();
            for (char c : cs) {
                String nxt = cur + c;
                if (check(nxt, k)) {
                    ans = nxt;
                    q.offer(nxt);
                }
            }
        }
        return ans;
    }

    private boolean check(String t, int k) {
        int i = 0;
        for (char c : s) {
            if (c == t.charAt(i)) {
                i++;
                if (i == t.length()) {
                    if (--k == 0) {
                        return true;
                    }
                    i = 0;
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
    string longestSubsequenceRepeatedK(string s, int k) {
        auto check = [&](const string& t, int k) -> bool {
            int i = 0;
            for (char c : s) {
                if (c == t[i]) {
                    i++;
                    if (i == t.size()) {
                        if (--k == 0) {
                            return true;
                        }
                        i = 0;
                    }
                }
            }
            return false;
        };
        int cnt[26] = {};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        vector<char> cs;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c - 'a'] >= k) {
                cs.push_back(c);
            }
        }

        queue<string> q;
        q.push("");
        string ans;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (char c : cs) {
                string nxt = cur + c;
                if (check(nxt, k)) {
                    ans = nxt;
                    q.push(nxt);
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
func longestSubsequenceRepeatedK(s string, k int) string {
	check := func(t string, k int) bool {
		i := 0
		for _, c := range s {
			if byte(c) == t[i] {
				i++
				if i == len(t) {
					k--
					if k == 0 {
						return true
					}
					i = 0
				}
			}
		}
		return false
	}

	cnt := [26]int{}
	for i := 0; i < len(s); i++ {
		cnt[s[i]-'a']++
	}

	cs := []byte{}
	for c := byte('a'); c <= 'z'; c++ {
		if cnt[c-'a'] >= k {
			cs = append(cs, c)
		}
	}

	q := []string{""}
	ans := ""
	for len(q) > 0 {
		cur := q[0]
		q = q[1:]
		for _, c := range cs {
			nxt := cur + string(c)
			if check(nxt, k) {
				ans = nxt
				q = append(q, nxt)
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubsequenceRepeatedK(s: string, k: number): string {
    const check = (t: string, k: number): boolean => {
        let i = 0;
        for (const c of s) {
            if (c === t[i]) {
                i++;
                if (i === t.length) {
                    k--;
                    if (k === 0) {
                        return true;
                    }
                    i = 0;
                }
            }
        }
        return false;
    };

    const cnt = new Array(26).fill(0);
    for (const c of s) {
        cnt[c.charCodeAt(0) - 97]++;
    }

    const cs: string[] = [];
    for (let i = 0; i < 26; ++i) {
        if (cnt[i] >= k) {
            cs.push(String.fromCharCode(97 + i));
        }
    }

    const q: string[] = [''];
    let ans = '';
    while (q.length > 0) {
        const cur = q.shift()!;
        for (const c of cs) {
            const nxt = cur + c;
            if (check(nxt, k)) {
                ans = nxt;
                q.push(nxt);
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

<p>给你一个长度为 <code>n</code> 的字符串 <code>s</code> ，和一个整数 <code>k</code> 。请你找出字符串 <code>s</code> 中 <strong>重复</strong> <code>k</code> 次的 <strong>最长子序列</strong> 。</p>

<p><strong>子序列</strong> 是由其他字符串删除某些（或不删除）字符派生而来的一个字符串。</p>

<p>如果&nbsp;<code>seq * k</code> 是 <code>s</code> 的一个子序列，其中 <code>seq * k</code> 表示一个由 <code>seq</code> 串联 <code>k</code>&nbsp;次构造的字符串，那么就称 <code>seq</code><strong> </strong>是字符串 <code>s</code> 中一个 <strong>重复 <code>k</code> 次</strong> 的子序列。</p>

<ul>
	<li>举个例子，<code>"bba"</code> 是字符串 <code>"bababcba"</code> 中的一个重复 <code>2</code> 次的子序列，因为字符串 <code>"bbabba"</code> 是由 <code>"bba"</code> 串联 <code>2</code> 次构造的，而&nbsp;<code>"bbabba"</code> 是字符串 <code>"<em><strong>b</strong></em>a<em><strong>bab</strong></em>c<em><strong>ba</strong></em>"</code> 的一个子序列。</li>
</ul>

<p>返回字符串 <code>s</code> 中 <strong>重复 k 次的最长子序列</strong>&nbsp; 。如果存在多个满足的子序列，则返回 <strong>字典序最大</strong> 的那个。如果不存在这样的子序列，返回一个 <strong>空</strong> 字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="example 1" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2014.Longest%20Subsequence%20Repeated%20k%20Times/images/longest-subsequence-repeat-k-times.png" style="width: 457px; height: 99px;" /></p>

<pre>
<strong>输入：</strong>s = "letsleetcode", k = 2
<strong>输出：</strong>"let"
<strong>解释：</strong>存在两个最长子序列重复 2 次：let" 和 "ete" 。
"let" 是其中字典序最大的一个。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "bb", k = 2
<strong>输出：</strong>"b"
<strong>解释：</strong>重复 2 次的最长子序列是 "b" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "ab", k = 2
<strong>输出：</strong>""
<strong>解释：</strong>不存在重复 2 次的最长子序列。返回空字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= k &lt;= 2000</code></li>
	<li><code>2 &lt;= n &lt; min(2001, k * 8)</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以先统计字符串中每个字符出现的次数，然后将出现次数大于等于 $k$ 的字符按从小到大的顺序存入一个列表 $\textit{cs}$ 中。接下来，我们可以使用 BFS 来枚举所有可能的子序列。

我们定义一个队列 $\textit{q}$，初始时将空字符串放入队列中。然后，我们从队列中取出一个字符串 $\textit{cur}$，并尝试将每个字符 $c \in \textit{cs}$ 添加到 $\textit{cur}$ 的末尾，形成一个新的字符串 $\textit{nxt}$。如果 $\textit{nxt}$ 是一个重复 $k$ 次的子序列，我们就将其加入到答案中，并将 $\textit{nxt}$ 放入队列中继续处理。

我们需要一个辅助函数 $\textit{check(t, k)}$ 来判断字符串 $\textit{t}$ 是否是字符串 $s$ 的一个重复 $k$ 次的子序列。具体地，我们可以使用两个指针来遍历字符串 $s$ 和 $\textit{t}$，如果在遍历过程中能够找到 $\textit{t}$ 的所有字符，并且能够重复 $k$ 次，那么就返回 $\textit{true}$，否则返回 $\textit{false}$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        def check(t: str, k: int) -> bool:
            i = 0
            for c in s:
                if c == t[i]:
                    i += 1
                    if i == len(t):
                        k -= 1
                        if k == 0:
                            return True
                        i = 0
            return False

        cnt = Counter(s)
        cs = [c for c in ascii_lowercase if cnt[c] >= k]
        q = deque([""])
        ans = ""
        while q:
            cur = q.popleft()
            for c in cs:
                nxt = cur + c
                if check(nxt, k):
                    ans = nxt
                    q.append(nxt)
        return ans
```

#### Java

```java
class Solution {
    private char[] s;

    public String longestSubsequenceRepeatedK(String s, int k) {
        this.s = s.toCharArray();
        int[] cnt = new int[26];
        for (char c : this.s) {
            cnt[c - 'a']++;
        }

        List<Character> cs = new ArrayList<>();
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c - 'a'] >= k) {
                cs.add(c);
            }
        }
        Deque<String> q = new ArrayDeque<>();
        q.offer("");
        String ans = "";
        while (!q.isEmpty()) {
            String cur = q.poll();
            for (char c : cs) {
                String nxt = cur + c;
                if (check(nxt, k)) {
                    ans = nxt;
                    q.offer(nxt);
                }
            }
        }
        return ans;
    }

    private boolean check(String t, int k) {
        int i = 0;
        for (char c : s) {
            if (c == t.charAt(i)) {
                i++;
                if (i == t.length()) {
                    if (--k == 0) {
                        return true;
                    }
                    i = 0;
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
    string longestSubsequenceRepeatedK(string s, int k) {
        auto check = [&](const string& t, int k) -> bool {
            int i = 0;
            for (char c : s) {
                if (c == t[i]) {
                    i++;
                    if (i == t.size()) {
                        if (--k == 0) {
                            return true;
                        }
                        i = 0;
                    }
                }
            }
            return false;
        };
        int cnt[26] = {};
        for (char c : s) {
            cnt[c - 'a']++;
        }

        vector<char> cs;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c - 'a'] >= k) {
                cs.push_back(c);
            }
        }

        queue<string> q;
        q.push("");
        string ans;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (char c : cs) {
                string nxt = cur + c;
                if (check(nxt, k)) {
                    ans = nxt;
                    q.push(nxt);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestSubsequenceRepeatedK(s string, k int) string {
	check := func(t string, k int) bool {
		i := 0
		for _, c := range s {
			if byte(c) == t[i] {
				i++
				if i == len(t) {
					k--
					if k == 0 {
						return true
					}
					i = 0
				}
			}
		}
		return false
	}

	cnt := [26]int{}
	for i := 0; i < len(s); i++ {
		cnt[s[i]-'a']++
	}

	cs := []byte{}
	for c := byte('a'); c <= 'z'; c++ {
		if cnt[c-'a'] >= k {
			cs = append(cs, c)
		}
	}

	q := []string{""}
	ans := ""
	for len(q) > 0 {
		cur := q[0]
		q = q[1:]
		for _, c := range cs {
			nxt := cur + string(c)
			if check(nxt, k) {
				ans = nxt
				q = append(q, nxt)
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestSubsequenceRepeatedK(s: string, k: number): string {
    const check = (t: string, k: number): boolean => {
        let i = 0;
        for (const c of s) {
            if (c === t[i]) {
                i++;
                if (i === t.length) {
                    k--;
                    if (k === 0) {
                        return true;
                    }
                    i = 0;
                }
            }
        }
        return false;
    };

    const cnt = new Array(26).fill(0);
    for (const c of s) {
        cnt[c.charCodeAt(0) - 97]++;
    }

    const cs: string[] = [];
    for (let i = 0; i < 26; ++i) {
        if (cnt[i] >= k) {
            cs.push(String.fromCharCode(97 + i));
        }
    }

    const q: string[] = [''];
    let ans = '';
    while (q.length > 0) {
        const cur = q.shift()!;
        for (const c of cs) {
            const nxt = cur + c;
            if (check(nxt, k)) {
                ans = nxt;
                q.push(nxt);
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

# [2015. 每段建筑物的平均高度 🔒](https://leetcode.cn/problems/average-height-of-buildings-in-each-segment){#2015}

{{< tabs "2015" >}}

{{% tab "python" %}}
```python
class Solution:
    def averageHeightOfBuildings(self, buildings: List[List[int]]) -> List[List[int]]:
        cnt = defaultdict(int)
        d = defaultdict(int)
        for start, end, height in buildings:
            cnt[start] += 1
            cnt[end] -= 1
            d[start] += height
            d[end] -= height
        s = m = 0
        last = -1
        ans = []
        for k, v in sorted(d.items()):
            if m:
                avg = s // m
                if ans and ans[-1][2] == avg and ans[-1][1] == last:
                    ans[-1][1] = k
                else:
                    ans.append([last, k, avg])
            s += v
            m += cnt[k]
            last = k
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] averageHeightOfBuildings(int[][] buildings) {
        Map<Integer, Integer> cnt = new HashMap<>();
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (var e : buildings) {
            int start = e[0], end = e[1], height = e[2];
            cnt.merge(start, 1, Integer::sum);
            cnt.merge(end, -1, Integer::sum);
            d.merge(start, height, Integer::sum);
            d.merge(end, -height, Integer::sum);
        }
        int s = 0, m = 0;
        int last = -1;
        List<int[]> ans = new ArrayList<>();
        for (var e : d.entrySet()) {
            int k = e.getKey(), v = e.getValue();
            if (m > 0) {
                int avg = s / m;
                if (!ans.isEmpty() && ans.get(ans.size() - 1)[2] == avg
                    && ans.get(ans.size() - 1)[1] == last) {
                    ans.get(ans.size() - 1)[1] = k;
                } else {
                    ans.add(new int[] {last, k, avg});
                }
            }
            s += v;
            m += cnt.get(k);
            last = k;
        }
        return ans.toArray(new int[0][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        unordered_map<int, int> cnt;
        map<int, int> d;

        for (const auto& e : buildings) {
            int start = e[0], end = e[1], height = e[2];
            cnt[start]++;
            cnt[end]--;
            d[start] += height;
            d[end] -= height;
        }

        int s = 0, m = 0;
        int last = -1;
        vector<vector<int>> ans;

        for (const auto& [k, v] : d) {
            if (m > 0) {
                int avg = s / m;
                if (!ans.empty() && ans.back()[2] == avg && ans.back()[1] == last) {
                    ans.back()[1] = k;
                } else {
                    ans.push_back({last, k, avg});
                }
            }
            s += v;
            m += cnt[k];
            last = k;
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func averageHeightOfBuildings(buildings [][]int) [][]int {
	cnt := make(map[int]int)
	d := make(map[int]int)

	for _, e := range buildings {
		start, end, height := e[0], e[1], e[2]
		cnt[start]++
		cnt[end]--
		d[start] += height
		d[end] -= height
	}

	s, m := 0, 0
	last := -1
	var ans [][]int

	keys := make([]int, 0, len(d))
	for k := range d {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	for _, k := range keys {
		v := d[k]
		if m > 0 {
			avg := s / m
			if len(ans) > 0 && ans[len(ans)-1][2] == avg && ans[len(ans)-1][1] == last {
				ans[len(ans)-1][1] = k
			} else {
				ans = append(ans, []int{last, k, avg})
			}
		}
		s += v
		m += cnt[k]
		last = k
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function averageHeightOfBuildings(buildings: number[][]): number[][] {
    const cnt = new Map<number, number>();
    const d = new Map<number, number>();
    for (const [start, end, height] of buildings) {
        cnt.set(start, (cnt.get(start) || 0) + 1);
        cnt.set(end, (cnt.get(end) || 0) - 1);
        d.set(start, (d.get(start) || 0) + height);
        d.set(end, (d.get(end) || 0) - height);
    }
    let [s, m] = [0, 0];
    let last = -1;
    const ans: number[][] = [];
    const sortedKeys = Array.from(d.keys()).sort((a, b) => a - b);
    for (const k of sortedKeys) {
        const v = d.get(k)!;
        if (m > 0) {
            const avg = Math.floor(s / m);
            if (ans.length > 0 && ans.at(-1)![2] === avg && ans.at(-1)![1] === last) {
                ans[ans.length - 1][1] = k;
            } else {
                ans.push([last, k, avg]);
            }
        }
        s += v;
        m += cnt.get(k)!;
        last = k;
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

<p>一条完全笔直的街道由一条数字线表示。街道上有建筑物，由二维整数阵列&nbsp;<code>buildings</code> 表示，其中 <code>buildings[i] = [start<sub>i</sub>, end<sub>i</sub>, height<sub>i</sub>]</code>。这意味着在 <strong>半封闭的位置</strong><code>[starti，endi)</code>&nbsp;有一座高度为&nbsp;<code>height<sub>i</sub></code>&nbsp;的建筑。<br />
你想用 <strong>最少</strong> 数量的非重叠 <strong>部分</strong> 来 <strong>描述</strong> 街道上建筑物的高度。街道可以用2D整数数组&nbsp;<code>street</code>&nbsp;来表示，其中&nbsp;<code>street[j] = [left<sub>j</sub>, right<sub>j</sub>, average<sub>j</sub>]</code>&nbsp;描述了道路的 <strong>半封闭区域</strong>&nbsp;<code>[left<sub>j</sub>, right<sub>j</sub>)</code>&nbsp;，该段中建筑物的 <strong>平均</strong> 高度为&nbsp;<code>average<sub>j</sub></code> 。</p>

<ul>
	<li>例如，如果&nbsp;<code>buildings = [[1,5,2],[3,10,4]]</code>&nbsp;，&nbsp;<code>street = [[1,3,2],[3,5,3],[5,10,4]]</code>&nbsp;可以表示街道，因为：

    <ul>
    	<li>从 1 到 3 ，只有第一栋建筑的平均高度为 <code>2 / 1 = 2</code> 。</li>
    	<li>从 3 到 5 ，第一和第二栋建筑的平均高度均为&nbsp;<code>（2+4） / 2 = 3 </code>。</li>
    	<li>从 5 到 10 ，只有第二栋建筑的平均高度为 <code>4 / 1 = 4</code> 。</li>
    </ul>
    </li>

</ul>

<p>给定&nbsp;<code>buildings</code> ，返回如上所述的二维整数矩阵<em>&nbsp;</em><code>street</code><em>&nbsp;</em>（ <strong>不包括</strong> 街道上没有建筑物的任何区域）。您可以按 <strong>任何顺序</strong> 返回数组。<br />
<code>n</code> 个元素的 <strong>平均值</strong> 是 <code>n</code> 个元素除以&nbsp;<code>n</code> 的 <strong>总和</strong> （<strong>整数除法</strong>）。<br />
<strong>半闭合段</strong>&nbsp;<code>[a, b)</code>&nbsp;是点&nbsp;<code>a</code>&nbsp;和 <code>b</code> 之间的数字线的截面，<strong>包括</strong> 点 <code>a</code> ，<strong>不包括&nbsp;</strong>点 <code>b</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2015.Average%20Height%20of%20Buildings%20in%20Each%20Segment/images/image-20210921224001-2.png" />
<pre>
<strong>输入:</strong> buildings = [[1,4,2],[3,9,4]]
<strong>输出:</strong> [[1,3,2],[3,4,3],[4,9,4]]
<strong>解释:</strong>
从 1 到 3 ，只有第一栋建筑的平均高度为 2 / 1 = 2。
从 3 到 4 ，第一和第二栋建筑的平均高度均为（2+4）/ 2 = 3。
从 4 到 9 ，只有第二栋建筑的平均高度为 4 / 1 = 4。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> buildings = [[1,3,2],[2,5,3],[2,8,3]]
<strong>输出:</strong> [[1,3,2],[3,8,3]]
<strong>解释:</strong>
从 1 到 2 ，只有第一栋建筑的平均高度为 2 / 1 = 2。
从 2 到 3 ，这三座建筑的平均高度均为 （2+3+3） / 3 = 2。
从 3 到 5 ，第二和第三栋楼都在那里，平均高度为 （3+3） / 2 = 3。
从 5 到 8 ，只有最后一栋建筑的平均高度为 3 / 1 = 3。
从 1 到 3 的平均高度是相同的，所以我们可以把它们分成一个部分。
从 3 到 8 的平均高度是相同的，所以我们可以把它们分成一个部分。
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> buildings = [[1,2,1],[5,6,1]]
<strong>输出:</strong> [[1,2,1],[5,6,1]]
<strong>解释:</strong>
从 1 到 2 ，只有第一栋建筑的平均高度为 1 / 1 = 1。
从 2 到 5 ，没有建筑物，因此不包括在输出中。
从 5 到 6 ，只有第二栋建筑的平均高度为 1 / 1 = 1。
我们无法将这些部分组合在一起，因为没有建筑的空白空间将这些部分隔开。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= buildings.length &lt;= 10<sup>5</sup></code></li>
	<li><code>buildings[i].length == 3</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 10<sup>8</sup></code></li>
	<li><code>1 &lt;= height<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分思想 + 哈希表

我们可以利用差分思想，用一个哈希表 $\textit{cnt}$ 记录每个位置的建筑物数量变化，用另一个哈希表 $\textit{d}$ 记录每个位置的高度变化。

接下来，我们对哈希表 $\textit{d}$ 按照键值进行排序，用一个变量 $\textit{s}$ 记录当前位置的高度和，用一个变量 $\textit{m}$ 记录当前位置的建筑物数量。

然后遍历哈希表 $\textit{d}$，对于每个位置，如果 $\textit{m}$ 不为 0，说明此前有建筑物，我们计算出平均高度，如果当前位置的建筑物与上个建筑物的平均高度相同，则合并，否则加入结果集。

最后返回结果集即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为建筑物数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def averageHeightOfBuildings(self, buildings: List[List[int]]) -> List[List[int]]:
        cnt = defaultdict(int)
        d = defaultdict(int)
        for start, end, height in buildings:
            cnt[start] += 1
            cnt[end] -= 1
            d[start] += height
            d[end] -= height
        s = m = 0
        last = -1
        ans = []
        for k, v in sorted(d.items()):
            if m:
                avg = s // m
                if ans and ans[-1][2] == avg and ans[-1][1] == last:
                    ans[-1][1] = k
                else:
                    ans.append([last, k, avg])
            s += v
            m += cnt[k]
            last = k
        return ans
```

#### Java

```java
class Solution {
    public int[][] averageHeightOfBuildings(int[][] buildings) {
        Map<Integer, Integer> cnt = new HashMap<>();
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (var e : buildings) {
            int start = e[0], end = e[1], height = e[2];
            cnt.merge(start, 1, Integer::sum);
            cnt.merge(end, -1, Integer::sum);
            d.merge(start, height, Integer::sum);
            d.merge(end, -height, Integer::sum);
        }
        int s = 0, m = 0;
        int last = -1;
        List<int[]> ans = new ArrayList<>();
        for (var e : d.entrySet()) {
            int k = e.getKey(), v = e.getValue();
            if (m > 0) {
                int avg = s / m;
                if (!ans.isEmpty() && ans.get(ans.size() - 1)[2] == avg
                    && ans.get(ans.size() - 1)[1] == last) {
                    ans.get(ans.size() - 1)[1] = k;
                } else {
                    ans.add(new int[] {last, k, avg});
                }
            }
            s += v;
            m += cnt.get(k);
            last = k;
        }
        return ans.toArray(new int[0][]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        unordered_map<int, int> cnt;
        map<int, int> d;

        for (const auto& e : buildings) {
            int start = e[0], end = e[1], height = e[2];
            cnt[start]++;
            cnt[end]--;
            d[start] += height;
            d[end] -= height;
        }

        int s = 0, m = 0;
        int last = -1;
        vector<vector<int>> ans;

        for (const auto& [k, v] : d) {
            if (m > 0) {
                int avg = s / m;
                if (!ans.empty() && ans.back()[2] == avg && ans.back()[1] == last) {
                    ans.back()[1] = k;
                } else {
                    ans.push_back({last, k, avg});
                }
            }
            s += v;
            m += cnt[k];
            last = k;
        }

        return ans;
    }
};
```

#### Go

```go
func averageHeightOfBuildings(buildings [][]int) [][]int {
	cnt := make(map[int]int)
	d := make(map[int]int)

	for _, e := range buildings {
		start, end, height := e[0], e[1], e[2]
		cnt[start]++
		cnt[end]--
		d[start] += height
		d[end] -= height
	}

	s, m := 0, 0
	last := -1
	var ans [][]int

	keys := make([]int, 0, len(d))
	for k := range d {
		keys = append(keys, k)
	}
	sort.Ints(keys)

	for _, k := range keys {
		v := d[k]
		if m > 0 {
			avg := s / m
			if len(ans) > 0 && ans[len(ans)-1][2] == avg && ans[len(ans)-1][1] == last {
				ans[len(ans)-1][1] = k
			} else {
				ans = append(ans, []int{last, k, avg})
			}
		}
		s += v
		m += cnt[k]
		last = k
	}

	return ans
}
```

#### TypeScript

```ts
function averageHeightOfBuildings(buildings: number[][]): number[][] {
    const cnt = new Map<number, number>();
    const d = new Map<number, number>();
    for (const [start, end, height] of buildings) {
        cnt.set(start, (cnt.get(start) || 0) + 1);
        cnt.set(end, (cnt.get(end) || 0) - 1);
        d.set(start, (d.get(start) || 0) + height);
        d.set(end, (d.get(end) || 0) - height);
    }
    let [s, m] = [0, 0];
    let last = -1;
    const ans: number[][] = [];
    const sortedKeys = Array.from(d.keys()).sort((a, b) => a - b);
    for (const k of sortedKeys) {
        const v = d.get(k)!;
        if (m > 0) {
            const avg = Math.floor(s / m);
            if (ans.length > 0 && ans.at(-1)![2] === avg && ans.at(-1)![1] === last) {
                ans[ans.length - 1][1] = k;
            } else {
                ans.push([last, k, avg]);
            }
        }
        s += v;
        m += cnt.get(k)!;
        last = k;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2016. 增量元素之间的最大差值](https://leetcode.cn/problems/maximum-difference-between-increasing-elements){#2016}

{{< tabs "2016" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        mi = inf
        ans = -1
        for x in nums:
            if x > mi:
                ans = max(ans, x - mi)
            else:
                mi = x
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumDifference(int[] nums) {
        int mi = 1 << 30;
        int ans = -1;
        for (int x : nums) {
            if (x > mi) {
                ans = Math.max(ans, x - mi);
            } else {
                mi = x;
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
    int maximumDifference(vector<int>& nums) {
        int mi = 1 << 30;
        int ans = -1;
        for (int& x : nums) {
            if (x > mi) {
                ans = max(ans, x - mi);
            } else {
                mi = x;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumDifference(nums []int) int {
	mi := 1 << 30
	ans := -1
	for _, x := range nums {
		if mi < x {
			ans = max(ans, x-mi)
		} else {
			mi = x
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumDifference(nums: number[]): number {
    let [ans, mi] = [-1, Infinity];
    for (const x of nums) {
        if (x > mi) {
            ans = Math.max(ans, x - mi);
        } else {
            mi = x;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut mi = i32::MAX;
        let mut ans = -1;

        for &x in &nums {
            if x > mi {
                ans = ans.max(x - mi);
            } else {
                mi = x;
            }
        }

        ans
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
var maximumDifference = function (nums) {
    let [ans, mi] = [-1, Infinity];
    for (const x of nums) {
        if (x > mi) {
            ans = Math.max(ans, x - mi);
        } else {
            mi = x;
        }
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，该数组的大小为 <code>n</code> ，请你计算 <code>nums[j] - nums[i]</code> 能求得的 <strong>最大差值 </strong>，其中 <code>0 &lt;= i &lt; j &lt; n</code> 且 <code>nums[i] &lt; nums[j]</code> 。</p>

<p>返回 <strong>最大差值</strong> 。如果不存在满足要求的 <code>i</code> 和 <code>j</code> ，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [7,<em><strong>1</strong></em>,<em><strong>5</strong></em>,4]
<strong>输出：</strong>4
<strong>解释：</strong>
最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 &gt; 4 ，但 i &gt; j 不满足题面要求，所以 6 不是有效的答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [9,4,3,2]
<strong>输出：</strong>-1
<strong>解释：</strong>
不存在同时满足 i &lt; j 和 nums[i] &lt; nums[j] 这两个条件的 i, j 组合。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [<em><strong>1</strong></em>,5,2,<em><strong>10</strong></em>]
<strong>输出：</strong>9
<strong>解释：</strong>
最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护前缀最小值

我们用一个变量 $\textit{mi}$ 表示当前遍历到的元素中的最小值，用一个变量 $\textit{ans}$ 表示最大差值，初始时 $\textit{mi}$ 为 $+\infty$，而 $\textit{ans}$ 为 $-1$。

遍历数组，对于当前遍历到的元素 $x$，如果 $x \gt \textit{mi}$，则更新 $\textit{ans}$ 为 $\max(\textit{ans}, x - \textit{mi})$，否则更新 $\textit{mi} = x$。

遍历结束后，返回 $\textit{ans}$。

遍历结束后，返回 $ans$。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        mi = inf
        ans = -1
        for x in nums:
            if x > mi:
                ans = max(ans, x - mi)
            else:
                mi = x
        return ans
```

#### Java

```java
class Solution {
    public int maximumDifference(int[] nums) {
        int mi = 1 << 30;
        int ans = -1;
        for (int x : nums) {
            if (x > mi) {
                ans = Math.max(ans, x - mi);
            } else {
                mi = x;
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
    int maximumDifference(vector<int>& nums) {
        int mi = 1 << 30;
        int ans = -1;
        for (int& x : nums) {
            if (x > mi) {
                ans = max(ans, x - mi);
            } else {
                mi = x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumDifference(nums []int) int {
	mi := 1 << 30
	ans := -1
	for _, x := range nums {
		if mi < x {
			ans = max(ans, x-mi)
		} else {
			mi = x
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maximumDifference(nums: number[]): number {
    let [ans, mi] = [-1, Infinity];
    for (const x of nums) {
        if (x > mi) {
            ans = Math.max(ans, x - mi);
        } else {
            mi = x;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut mi = i32::MAX;
        let mut ans = -1;

        for &x in &nums {
            if x > mi {
                ans = ans.max(x - mi);
            } else {
                mi = x;
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumDifference = function (nums) {
    let [ans, mi] = [-1, Infinity];
    for (const x of nums) {
        if (x > mi) {
            ans = Math.max(ans, x - mi);
        } else {
            mi = x;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2017. 网格游戏](https://leetcode.cn/problems/grid-game){#2017}

{{< tabs "2017" >}}

{{% tab "python" %}}
```python
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        ans = inf
        s1, s2 = sum(grid[0]), 0
        for j, v in enumerate(grid[0]):
            s1 -= v
            ans = min(ans, max(s1, s2))
            s2 += grid[1][j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long gridGame(int[][] grid) {
        long ans = Long.MAX_VALUE;
        long s1 = 0, s2 = 0;
        for (int v : grid[0]) {
            s1 += v;
        }
        int n = grid[0].length;
        for (int j = 0; j < n; ++j) {
            s1 -= grid[0][j];
            ans = Math.min(ans, Math.max(s1, s2));
            s2 += grid[1][j];
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll ans = LONG_MAX;
        int n = grid[0].size();
        ll s1 = 0, s2 = 0;
        for (int& v : grid[0]) s1 += v;
        for (int j = 0; j < n; ++j) {
            s1 -= grid[0][j];
            ans = min(ans, max(s1, s2));
            s2 += grid[1][j];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func gridGame(grid [][]int) int64 {
	ans := math.MaxInt64
	s1, s2 := 0, 0
	for _, v := range grid[0] {
		s1 += v
	}
	for j, v := range grid[0] {
		s1 -= v
		ans = min(ans, max(s1, s2))
		s2 += grid[1][j]
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function gridGame(grid: number[][]): number {
    let ans = Number.MAX_SAFE_INTEGER;
    let s1 = grid[0].reduce((a, b) => a + b, 0);
    let s2 = 0;
    for (let j = 0; j < grid[0].length; ++j) {
        s1 -= grid[0][j];
        ans = Math.min(ans, Math.max(s1, s2));
        s2 += grid[1][j];
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

<p>给你一个下标从 <strong>0</strong> 开始的二维数组 <code>grid</code> ，数组大小为 <code>2 x n</code> ，其中 <code>grid[r][c]</code> 表示矩阵中 <code>(r, c)</code> 位置上的点数。现在有两个机器人正在矩阵上参与一场游戏。</p>

<p>两个机器人初始位置都是 <code>(0, 0)</code> ，目标位置是 <code>(1, n-1)</code> 。每个机器人只会 <strong>向右</strong> (<code>(r, c)</code> 到 <code>(r, c + 1)</code>) 或 <strong>向下 </strong>(<code>(r, c)</code> 到 <code>(r + 1, c)</code>) 。</p>

<p>游戏开始，<strong>第一个</strong> 机器人从 <code>(0, 0)</code> 移动到 <code>(1, n-1)</code> ，并收集路径上单元格的全部点数。对于路径上所有单元格 <code>(r, c)</code> ，途经后 <code>grid[r][c]</code> 会重置为 <code>0</code> 。然后，<strong>第二个</strong> 机器人从 <code>(0, 0)</code> 移动到 <code>(1, n-1)</code> ，同样收集路径上单元的全部点数。注意，它们的路径可能会存在相交的部分。</p>

<p><strong>第一个</strong> 机器人想要打击竞争对手，使 <strong>第二个</strong> 机器人收集到的点数 <strong>最小化</strong> 。与此相对，<strong>第二个</strong> 机器人想要 <strong>最大化</strong> 自己收集到的点数。两个机器人都发挥出自己的 <strong>最佳水平</strong>&nbsp;的前提下，返回 <strong>第二个</strong> 机器人收集到的 <strong>点数</strong> <em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2017.Grid%20Game/images/a1.png" style="width: 388px; height: 103px;" /></p>

<pre>
<strong>输入：</strong>grid = [[2,5,4],[1,5,1]]
<strong>输出：</strong>4
<strong>解释：</strong>第一个机器人的最佳路径如红色所示，第二个机器人的最佳路径如蓝色所示。
第一个机器人访问过的单元格将会重置为 0 。
第二个机器人将会收集到 0 + 0 + 4 + 0 = 4 个点。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2017.Grid%20Game/images/a2.png" style="width: 384px; height: 105px;" />
<pre>
<strong>输入：</strong>grid = [[3,3,1],[8,5,2]]
<strong>输出：</strong>4
<strong>解释：</strong>第一个机器人的最佳路径如红色所示，第二个机器人的最佳路径如蓝色所示。 
第一个机器人访问过的单元格将会重置为 0 。
第二个机器人将会收集到 0 + 3 + 1 + 0 = 4 个点。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2017.Grid%20Game/images/a3.png" style="width: 493px; height: 103px;" />
<pre>
<strong>输入：</strong>grid = [[1,3,1,15],[1,3,3,1]]
<strong>输出：</strong>7
<strong>解释：</strong>第一个机器人的最佳路径如红色所示，第二个机器人的最佳路径如蓝色所示。
第一个机器人访问过的单元格将会重置为 0 。
第二个机器人将会收集到 0 + 1 + 3 + 3 + 0 = 7 个点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>grid.length == 2</code></li>
	<li><code>n == grid[r].length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= grid[r][c] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们注意到，如果确定了第一个机器人拐头向下的位置 $j$，那么第二个机器人的最优路径也就确定了，第二个机器人的最优路径就是第一行从 $j+1$ 到 $n-1$ 的前缀和，或者第二行从 $0$ 到 $j-1$ 的前缀和，取两者的最大值。

我们先计算第一行的后缀点数和，记为 $s_1$，第二行的前缀点数和记为 $s_2$，初始时 $s_1 = \sum_{j=0}^{n-1} grid[0][j]$, $s_2 = 0$。

然后我们枚举第一个机器人拐头向下的位置 $j$，此时更新 $s_1 = s_1 - grid[0][j]$, 那么第二个机器人的最优路径和就是 $max(s_1, s_2)$，我们取所有 $j$ 对应的 $max(s_1, s_2)$ 的最小值即可。然后更新 $s_2 = s_2 + grid[1][j]$。

枚举结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是网格的列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        ans = inf
        s1, s2 = sum(grid[0]), 0
        for j, v in enumerate(grid[0]):
            s1 -= v
            ans = min(ans, max(s1, s2))
            s2 += grid[1][j]
        return ans
```

#### Java

```java
class Solution {
    public long gridGame(int[][] grid) {
        long ans = Long.MAX_VALUE;
        long s1 = 0, s2 = 0;
        for (int v : grid[0]) {
            s1 += v;
        }
        int n = grid[0].length;
        for (int j = 0; j < n; ++j) {
            s1 -= grid[0][j];
            ans = Math.min(ans, Math.max(s1, s2));
            s2 += grid[1][j];
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll ans = LONG_MAX;
        int n = grid[0].size();
        ll s1 = 0, s2 = 0;
        for (int& v : grid[0]) s1 += v;
        for (int j = 0; j < n; ++j) {
            s1 -= grid[0][j];
            ans = min(ans, max(s1, s2));
            s2 += grid[1][j];
        }
        return ans;
    }
};
```

#### Go

```go
func gridGame(grid [][]int) int64 {
	ans := math.MaxInt64
	s1, s2 := 0, 0
	for _, v := range grid[0] {
		s1 += v
	}
	for j, v := range grid[0] {
		s1 -= v
		ans = min(ans, max(s1, s2))
		s2 += grid[1][j]
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function gridGame(grid: number[][]): number {
    let ans = Number.MAX_SAFE_INTEGER;
    let s1 = grid[0].reduce((a, b) => a + b, 0);
    let s2 = 0;
    for (let j = 0; j < grid[0].length; ++j) {
        s1 -= grid[0][j];
        ans = Math.min(ans, Math.max(s1, s2));
        s2 += grid[1][j];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2018. 判断单词是否能放入填字游戏内](https://leetcode.cn/problems/check-if-word-can-be-placed-in-crossword){#2018}

{{< tabs "2018" >}}

{{% tab "python" %}}
```python
class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        def check(i, j, a, b):
            x, y = i + a * k, j + b * k
            if 0 <= x < m and 0 <= y < n and board[x][y] != '#':
                return False
            for c in word:
                if (
                    i < 0
                    or i >= m
                    or j < 0
                    or j >= n
                    or (board[i][j] != ' ' and board[i][j] != c)
                ):
                    return False
                i, j = i + a, j + b
            return True

        m, n = len(board), len(board[0])
        k = len(word)
        for i in range(m):
            for j in range(n):
                left_to_right = (j == 0 or board[i][j - 1] == '#') and check(i, j, 0, 1)
                right_to_left = (j == n - 1 or board[i][j + 1] == '#') and check(
                    i, j, 0, -1
                )
                up_to_down = (i == 0 or board[i - 1][j] == '#') and check(i, j, 1, 0)
                down_to_up = (i == m - 1 or board[i + 1][j] == '#') and check(
                    i, j, -1, 0
                )
                if left_to_right or right_to_left or up_to_down or down_to_up:
                    return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private char[][] board;
    private String word;
    private int k;

    public boolean placeWordInCrossword(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        this.board = board;
        this.word = word;
        k = word.length();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                boolean leftToRight = (j == 0 || board[i][j - 1] == '#') && check(i, j, 0, 1);
                boolean rightToLeft = (j == n - 1 || board[i][j + 1] == '#') && check(i, j, 0, -1);
                boolean upToDown = (i == 0 || board[i - 1][j] == '#') && check(i, j, 1, 0);
                boolean downToUp = (i == m - 1 || board[i + 1][j] == '#') && check(i, j, -1, 0);
                if (leftToRight || rightToLeft || upToDown || downToUp) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean check(int i, int j, int a, int b) {
        int x = i + a * k, y = j + b * k;
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
            return false;
        }
        for (int p = 0; p < k; ++p) {
            if (i < 0 || i >= m || j < 0 || j >= n
                || (board[i][j] != ' ' && board[i][j] != word.charAt(p))) {
                return false;
            }
            i += a;
            j += b;
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
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int k = word.size();
        auto check = [&](int i, int j, int a, int b) {
            int x = i + a * k, y = j + b * k;
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
                return false;
            }
            for (char& c : word) {
                if (i < 0 || i >= m || j < 0 || j >= n || (board[i][j] != ' ' && board[i][j] != c)) {
                    return false;
                }
                i += a;
                j += b;
            }
            return true;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool leftToRight = (j == 0 || board[i][j - 1] == '#') && check(i, j, 0, 1);
                bool rightToLeft = (j == n - 1 || board[i][j + 1] == '#') && check(i, j, 0, -1);
                bool upToDown = (i == 0 || board[i - 1][j] == '#') && check(i, j, 1, 0);
                bool downToUp = (i == m - 1 || board[i + 1][j] == '#') && check(i, j, -1, 0);
                if (leftToRight || rightToLeft || upToDown || downToUp) {
                    return true;
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func placeWordInCrossword(board [][]byte, word string) bool {
	m, n := len(board), len(board[0])
	k := len(word)
	check := func(i, j, a, b int) bool {
		x, y := i+a*k, j+b*k
		if x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#' {
			return false
		}
		for _, c := range word {
			if i < 0 || i >= m || j < 0 || j >= n || (board[i][j] != ' ' && board[i][j] != byte(c)) {
				return false
			}
			i, j = i+a, j+b
		}
		return true
	}
	for i := range board {
		for j := range board[i] {
			leftToRight := (j == 0 || board[i][j-1] == '#') && check(i, j, 0, 1)
			rightToLeft := (j == n-1 || board[i][j+1] == '#') && check(i, j, 0, -1)
			upToDown := (i == 0 || board[i-1][j] == '#') && check(i, j, 1, 0)
			downToUp := (i == m-1 || board[i+1][j] == '#') && check(i, j, -1, 0)
			if leftToRight || rightToLeft || upToDown || downToUp {
				return true
			}
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的矩阵&nbsp;<code>board</code>&nbsp;，它代表一个填字游戏&nbsp;<strong>当前</strong>&nbsp;的状态。填字游戏格子中包含小写英文字母（已填入的单词），表示&nbsp;<strong>空</strong>&nbsp;格的&nbsp;<code>' '</code>&nbsp;和表示&nbsp;<strong>障碍</strong>&nbsp;格子的&nbsp;<code>'#'</code>&nbsp;。</p>

<p>如果满足以下条件，那么我们可以 <strong>水平</strong>&nbsp;（从左到右 <strong>或者</strong>&nbsp;从右到左）或 <strong>竖直</strong>&nbsp;（从上到下 <strong>或者</strong>&nbsp;从下到上）填入一个单词：</p>

<ul>
	<li>该单词不占据任何&nbsp;<code>'#'</code>&nbsp;对应的格子。</li>
	<li>每个字母对应的格子要么是&nbsp;<code>' '</code>&nbsp;（空格）要么与 <code>board</code>&nbsp;中已有字母 <strong>匹配</strong>&nbsp;。</li>
	<li>如果单词是 <strong>水平</strong>&nbsp;放置的，那么该单词左边和右边 <strong>相邻</strong>&nbsp;格子不能为&nbsp;<code>' '</code>&nbsp;或小写英文字母。</li>
	<li>如果单词是&nbsp;<strong>竖直</strong>&nbsp;放置的，那么该单词上边和下边&nbsp;<strong>相邻</strong><strong>&nbsp;</strong>格子不能为&nbsp;<code>' '</code>&nbsp;或小写英文字母。</li>
</ul>

<p>给你一个字符串&nbsp;<code>word</code>&nbsp;，如果&nbsp;<code>word</code>&nbsp;可以被放入&nbsp;<code>board</code>&nbsp;中，请你返回&nbsp;<code>true</code>&nbsp;，否则请返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2018.Check%20if%20Word%20Can%20Be%20Placed%20In%20Crossword/images/crossword-1.png" style="width: 170px; height: 150px;" /></p>

<pre>
<b>输入：</b>board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
<b>输出：</b>true
<b>解释：</b>单词 "abc" 可以如上图放置（从上往下）。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2018.Check%20if%20Word%20Can%20Be%20Placed%20In%20Crossword/images/c2.png" style="width: 170px; height: 151px;" /></p>

<pre>
<b>输入：</b>board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
<b>输出：</b>false
<b>解释：</b>无法放置单词，因为放置该单词后上方或者下方相邻格会有空格。</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2018.Check%20if%20Word%20Can%20Be%20Placed%20In%20Crossword/images/crossword-2.png" style="width: 171px; height: 146px;" /></p>

<pre>
<b>输入：</b>board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
<b>输出：</b>true
<b>解释：</b>单词 "ca" 可以如上图放置（从右到左）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>board[i][j]</code>&nbsp;可能为&nbsp;<code>' '</code>&nbsp;，<code>'#'</code>&nbsp;或者一个小写英文字母。</li>
	<li><code>1 &lt;= word.length &lt;= max(m, n)</code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举矩阵的每个位置 $(i, j)$，判断是否能以该位置为起点，从左到右或从右到左放置单词 `word`，或者从上到下或从下到上放置单词 `word`。

该位置能作为起点需要满足以下条件：

1. 如果要从从左到右放置单词 `word`，那么该位置必须是左边界，或者该位置左边的格子 `board[i][j - 1]` 是 `'#'`；
2. 如果要从从右到左放置单词 `word`，那么该位置必须是右边界，或者该位置右边的格子 `board[i][j + 1]` 是 `'#'`；
3. 如果要从从上到下放置单词 `word`，那么该位置必须是上边界，或者该位置上边的格子 `board[i - 1][j]` 是 `'#'`；
4. 如果要从从下到上放置单词 `word`，那么该位置必须是下边界，或者该位置下边的格子 `board[i + 1][j]` 是 `'#'`。

在满足上述条件的情况下，我们可以从该位置开始，判断是否能放置单词 `word`。我们设计一个函数 $check(i, j, a, b)$，表示从位置 $(i, j)$ 开始，沿着方向 $(a, b)$ 放置单词 `word` 是否合法。如果合法，返回 `true`，否则返回 `false`。

函数 $check(i, j, a, b)$ 的实现如下：

我们先获取当前方向的另一个边界位置 $(x, y)$，即 $(x, y) = (i + a \times k, j + b \times k)$，其中 $k$ 为单词 `word` 的长度。如果 $(x, y)$ 在矩阵内，并且 $(x, y)$ 的格子不是 `'#'`，则说明当前方向的另一个边界位置不是 `'#'`，因此不能放置单词 `word`，返回 `false`。

否则，我们从位置 $(i, j)$ 开始，沿着方向 $(a, b)$ 遍历单词 `word`，如果遇到格子 `board[i][j]` 不是空格或者不是单词 `word` 的当前字符，说明不能放置单词 `word`，返回 `false`。如果遍历完单词 `word`，说明能放置单词 `word`，返回 `true`。

时间复杂度 $O(m \times n)$，空间复杂度 $O(1)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        def check(i, j, a, b):
            x, y = i + a * k, j + b * k
            if 0 <= x < m and 0 <= y < n and board[x][y] != '#':
                return False
            for c in word:
                if (
                    i < 0
                    or i >= m
                    or j < 0
                    or j >= n
                    or (board[i][j] != ' ' and board[i][j] != c)
                ):
                    return False
                i, j = i + a, j + b
            return True

        m, n = len(board), len(board[0])
        k = len(word)
        for i in range(m):
            for j in range(n):
                left_to_right = (j == 0 or board[i][j - 1] == '#') and check(i, j, 0, 1)
                right_to_left = (j == n - 1 or board[i][j + 1] == '#') and check(
                    i, j, 0, -1
                )
                up_to_down = (i == 0 or board[i - 1][j] == '#') and check(i, j, 1, 0)
                down_to_up = (i == m - 1 or board[i + 1][j] == '#') and check(
                    i, j, -1, 0
                )
                if left_to_right or right_to_left or up_to_down or down_to_up:
                    return True
        return False
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private char[][] board;
    private String word;
    private int k;

    public boolean placeWordInCrossword(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        this.board = board;
        this.word = word;
        k = word.length();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                boolean leftToRight = (j == 0 || board[i][j - 1] == '#') && check(i, j, 0, 1);
                boolean rightToLeft = (j == n - 1 || board[i][j + 1] == '#') && check(i, j, 0, -1);
                boolean upToDown = (i == 0 || board[i - 1][j] == '#') && check(i, j, 1, 0);
                boolean downToUp = (i == m - 1 || board[i + 1][j] == '#') && check(i, j, -1, 0);
                if (leftToRight || rightToLeft || upToDown || downToUp) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean check(int i, int j, int a, int b) {
        int x = i + a * k, y = j + b * k;
        if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
            return false;
        }
        for (int p = 0; p < k; ++p) {
            if (i < 0 || i >= m || j < 0 || j >= n
                || (board[i][j] != ' ' && board[i][j] != word.charAt(p))) {
                return false;
            }
            i += a;
            j += b;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int k = word.size();
        auto check = [&](int i, int j, int a, int b) {
            int x = i + a * k, y = j + b * k;
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#') {
                return false;
            }
            for (char& c : word) {
                if (i < 0 || i >= m || j < 0 || j >= n || (board[i][j] != ' ' && board[i][j] != c)) {
                    return false;
                }
                i += a;
                j += b;
            }
            return true;
        };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool leftToRight = (j == 0 || board[i][j - 1] == '#') && check(i, j, 0, 1);
                bool rightToLeft = (j == n - 1 || board[i][j + 1] == '#') && check(i, j, 0, -1);
                bool upToDown = (i == 0 || board[i - 1][j] == '#') && check(i, j, 1, 0);
                bool downToUp = (i == m - 1 || board[i + 1][j] == '#') && check(i, j, -1, 0);
                if (leftToRight || rightToLeft || upToDown || downToUp) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func placeWordInCrossword(board [][]byte, word string) bool {
	m, n := len(board), len(board[0])
	k := len(word)
	check := func(i, j, a, b int) bool {
		x, y := i+a*k, j+b*k
		if x >= 0 && x < m && y >= 0 && y < n && board[x][y] != '#' {
			return false
		}
		for _, c := range word {
			if i < 0 || i >= m || j < 0 || j >= n || (board[i][j] != ' ' && board[i][j] != byte(c)) {
				return false
			}
			i, j = i+a, j+b
		}
		return true
	}
	for i := range board {
		for j := range board[i] {
			leftToRight := (j == 0 || board[i][j-1] == '#') && check(i, j, 0, 1)
			rightToLeft := (j == n-1 || board[i][j+1] == '#') && check(i, j, 0, -1)
			upToDown := (i == 0 || board[i-1][j] == '#') && check(i, j, 1, 0)
			downToUp := (i == m-1 || board[i+1][j] == '#') && check(i, j, -1, 0)
			if leftToRight || rightToLeft || upToDown || downToUp {
				return true
			}
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2019. 解出数学表达式的学生分数](https://leetcode.cn/problems/the-score-of-students-solving-math-expression){#2019}

{{< tabs "2019" >}}

{{% tab "python" %}}
```python
class Solution:
    def scoreOfStudents(self, s: str, answers: List[int]) -> int:
        def cal(s: str) -> int:
            res, pre = 0, int(s[0])
            for i in range(1, n, 2):
                if s[i] == "*":
                    pre *= int(s[i + 1])
                else:
                    res += pre
                    pre = int(s[i + 1])
            res += pre
            return res

        n = len(s)
        x = cal(s)
        m = (n + 1) >> 1
        f = [[set() for _ in range(m)] for _ in range(m)]
        for i in range(m):
            f[i][i] = {int(s[i << 1])}
        for i in range(m - 1, -1, -1):
            for j in range(i, m):
                for k in range(i, j):
                    for l in f[i][k]:
                        for r in f[k + 1][j]:
                            if s[k << 1 | 1] == "+" and l + r <= 1000:
                                f[i][j].add(l + r)
                            elif s[k << 1 | 1] == "*" and l * r <= 1000:
                                f[i][j].add(l * r)
        cnt = Counter(answers)
        ans = cnt[x] * 5
        for k, v in cnt.items():
            if k != x and k in f[0][m - 1]:
                ans += v << 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int scoreOfStudents(String s, int[] answers) {
        int n = s.length();
        int x = cal(s);
        int m = (n + 1) >> 1;
        Set<Integer>[][] f = new Set[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i][j] = new HashSet<>();
            }
            f[i][i].add(s.charAt(i << 1) - '0');
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = i; j < m; ++j) {
                for (int k = i; k < j; ++k) {
                    for (int l : f[i][k]) {
                        for (int r : f[k + 1][j]) {
                            char op = s.charAt(k << 1 | 1);
                            if (op == '+' && l + r <= 1000) {
                                f[i][j].add(l + r);
                            } else if (op == '*' && l * r <= 1000) {
                                f[i][j].add(l * r);
                            }
                        }
                    }
                }
            }
        }
        int[] cnt = new int[1001];
        for (int ans : answers) {
            ++cnt[ans];
        }
        int ans = 5 * cnt[x];
        for (int i = 0; i <= 1000; ++i) {
            if (i != x && f[0][m - 1].contains(i)) {
                ans += 2 * cnt[i];
            }
        }
        return ans;
    }

    private int cal(String s) {
        int res = 0, pre = s.charAt(0) - '0';
        for (int i = 1; i < s.length(); i += 2) {
            char op = s.charAt(i);
            int cur = s.charAt(i + 1) - '0';
            if (op == '*') {
                pre *= cur;
            } else {
                res += pre;
                pre = cur;
            }
        }
        res += pre;
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.size();
        int x = cal(s);
        int m = (n + 1) >> 1;
        unordered_set<int> f[m][m];
        for (int i = 0; i < m; ++i) {
            f[i][i] = {s[i * 2] - '0'};
        }
        for (int i = m - 1; ~i; --i) {
            for (int j = i; j < m; ++j) {
                for (int k = i; k < j; ++k) {
                    for (int l : f[i][k]) {
                        for (int r : f[k + 1][j]) {
                            char op = s[k << 1 | 1];
                            if (op == '+' && l + r <= 1000) {
                                f[i][j].insert(l + r);
                            } else if (op == '*' && l * r <= 1000) {
                                f[i][j].insert(l * r);
                            }
                        }
                    }
                }
            }
        }
        int cnt[1001]{};
        for (int t : answers) {
            ++cnt[t];
        }
        int ans = 5 * cnt[x];
        for (int i = 0; i <= 1000; ++i) {
            if (i != x && f[0][m - 1].count(i)) {
                ans += cnt[i] << 1;
            }
        }
        return ans;
    }

    int cal(string& s) {
        int res = 0;
        int pre = s[0] - '0';
        for (int i = 1; i < s.size(); i += 2) {
            int cur = s[i + 1] - '0';
            if (s[i] == '*') {
                pre *= cur;
            } else {
                res += pre;
                pre = cur;
            }
        }
        res += pre;
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func scoreOfStudents(s string, answers []int) int {
	n := len(s)
	x := cal(s)
	m := (n + 1) >> 1
	f := make([][]map[int]bool, m)
	for i := range f {
		f[i] = make([]map[int]bool, m)
		for j := range f[i] {
			f[i][j] = make(map[int]bool)
		}
		f[i][i][int(s[i<<1]-'0')] = true
	}
	for i := m - 1; i >= 0; i-- {
		for j := i; j < m; j++ {
			for k := i; k < j; k++ {
				for l := range f[i][k] {
					for r := range f[k+1][j] {
						op := s[k<<1|1]
						if op == '+' && l+r <= 1000 {
							f[i][j][l+r] = true
						} else if op == '*' && l*r <= 1000 {
							f[i][j][l*r] = true
						}
					}
				}
			}
		}
	}
	cnt := [1001]int{}
	for _, v := range answers {
		cnt[v]++
	}
	ans := cnt[x] * 5
	for k, v := range cnt {
		if k != x && f[0][m-1][k] {
			ans += v << 1
		}
	}
	return ans
}

func cal(s string) int {
	res, pre := 0, int(s[0]-'0')
	for i := 1; i < len(s); i += 2 {
		cur := int(s[i+1] - '0')
		if s[i] == '+' {
			res += pre
			pre = cur
		} else {
			pre *= cur
		}
	}
	res += pre
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function scoreOfStudents(s: string, answers: number[]): number {
    const n = s.length;
    const cal = (s: string): number => {
        let res = 0;
        let pre = s.charCodeAt(0) - '0'.charCodeAt(0);
        for (let i = 1; i < s.length; i += 2) {
            const cur = s.charCodeAt(i + 1) - '0'.charCodeAt(0);
            if (s[i] === '+') {
                res += pre;
                pre = cur;
            } else {
                pre *= cur;
            }
        }
        res += pre;
        return res;
    };
    const x = cal(s);
    const m = (n + 1) >> 1;
    const f: Set<number>[][] = Array(m)
        .fill(0)
        .map(() =>
            Array(m)
                .fill(0)
                .map(() => new Set()),
        );
    for (let i = 0; i < m; ++i) {
        f[i][i].add(s[i << 1].charCodeAt(0) - '0'.charCodeAt(0));
    }
    for (let i = m - 1; i >= 0; --i) {
        for (let j = i; j < m; ++j) {
            for (let k = i; k < j; ++k) {
                for (const l of f[i][k]) {
                    for (const r of f[k + 1][j]) {
                        const op = s[(k << 1) + 1];
                        if (op === '+' && l + r <= 1000) {
                            f[i][j].add(l + r);
                        } else if (op === '*' && l * r <= 1000) {
                            f[i][j].add(l * r);
                        }
                    }
                }
            }
        }
    }
    const cnt: number[] = Array(1001).fill(0);
    for (const v of answers) {
        ++cnt[v];
    }
    let ans = cnt[x] * 5;
    for (let i = 0; i <= 1000; ++i) {
        if (i !== x && f[0][m - 1].has(i)) {
            ans += cnt[i] << 1;
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，它 <strong>只</strong> 包含数字&nbsp;<code>0-9</code>&nbsp;，加法运算符&nbsp;<code>'+'</code>&nbsp;和乘法运算符&nbsp;<code>'*'</code>&nbsp;，这个字符串表示一个&nbsp;<strong>合法</strong>&nbsp;的只含有&nbsp;<strong>个位数</strong><strong>数字</strong>&nbsp;的数学表达式（比方说&nbsp;<code>3+5*2</code>）。有 <code>n</code>&nbsp;位小学生将计算这个数学表达式，并遵循如下 <strong>运算顺序</strong>&nbsp;：</p>

<ol>
	<li>按照 <strong>从左到右</strong>&nbsp;的顺序计算 <strong>乘法</strong>&nbsp;，然后</li>
	<li>按照 <strong>从左到右</strong>&nbsp;的顺序计算 <strong>加法</strong>&nbsp;。</li>
</ol>

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>answers</code>&nbsp;，表示每位学生提交的答案。你的任务是给 <code>answer</code>&nbsp;数组按照如下 <strong>规则</strong>&nbsp;打分：</p>

<ul>
	<li>如果一位学生的答案 <strong>等于</strong>&nbsp;表达式的正确结果，这位学生将得到 <code>5</code>&nbsp;分。</li>
	<li>否则，如果答案由&nbsp;<strong>一处或多处错误的运算顺序</strong>&nbsp;计算得到，那么这位学生能得到 <code>2</code>&nbsp;分。</li>
	<li>否则，这位学生将得到 <code>0</code>&nbsp;分。</li>
</ul>

<p>请你返回所有学生的分数和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2000-2099/2019.The%20Score%20of%20Students%20Solving%20Math%20Expression/images/student_solving_math.png" style="width: 678px; height: 109px;" /></p>

<pre>
<b>输入：</b>s = "7+3*1*2", answers = [20,13,42]
<b>输出：</b>7
<b>解释：</b>如上图所示，正确答案为 13 ，因此有一位学生得分为 5 分：[20,<em><strong>13</strong></em>,42] 。
一位学生可能通过错误的运算顺序得到结果 20 ：7+3=10，10*1=10，10*2=20 。所以这位学生得分为 2 分：[<em><strong>20</strong></em>,13,42] 。
所有学生得分分别为：[2,5,0] 。所有得分之和为 2+5+0=7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "3+5*2", answers = [13,0,10,13,13,16,16]
<b>输出：</b>19
<b>解释：</b>表达式的正确结果为 13 ，所以有 3 位学生得到 5 分：[<em><strong>13</strong></em>,0,10,<em><strong>13</strong></em>,<em><strong>13</strong></em>,16,16] 。
学生可能通过错误的运算顺序得到结果 16 ：3+5=8，8*2=16 。所以两位学生得到 2 分：[13,0,10,13,13,<em><strong>16</strong></em>,<em><strong>16</strong></em>] 。
所有学生得分分别为：[5,0,0,5,5,2,2] 。所有得分之和为 5+0+0+5+5+2+2=19 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>s = "6+0*1", answers = [12,9,6,4,8,6]
<b>输出：</b>10
<b>解释：</b>表达式的正确结果为 6 。
如果一位学生通过错误的运算顺序计算该表达式，结果仍为 6 。
根据打分规则，运算顺序错误的学生也将得到 5 分（因为他们仍然得到了正确的结果），而不是 2 分。
所有学生得分分别为：[0,0,5,0,0,5] 。所有得分之和为 10 分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 31</code></li>
	<li><code>s</code>&nbsp;表示一个只包含&nbsp;<code>0-9</code>&nbsp;，<code>'+'</code>&nbsp;和&nbsp;<code>'*'</code>&nbsp;的合法表达式。</li>
	<li>表达式中所有整数运算数字都在闭区间&nbsp;<code>[0, 9]</code>&nbsp;以内。</li>
	<li><code>1 &lt;=</code>&nbsp;数学表达式中所有运算符数目（<code>'+'</code> 和&nbsp;<code>'*'</code>）&nbsp;<code>&lt;= 15</code></li>
	<li>测试数据保证正确表达式结果在范围&nbsp;<code>[0, 1000]</code>&nbsp;以内。</li>
	<li>测试用例保证乘法中间步骤中的值永远不会超过 <code>10<sup>9</sup></code>。</li>
	<li><code>n == answers.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= answers[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（区间 DP）

我们先设计一个函数 $cal(s)$，用于计算一个合法的只含有个位数数字的数学表达式的结果。那么正确答案就是 $x = cal(s)$。

我们记字符串 $s$ 的长度为 $n$，那么 $s$ 中的数字个数为 $m = \frac{n+1}{2}$。

我们定义 $f[i][j]$ 表示选择 $s$ 中的第 $i$ 个数字到第 $j$ 个数字（下标从 $0$ 开始）这一段数字，计算出的结果可能的取值。初始时 $f[i][i]$ 表示选择第 $i$ 个数字，结果只能是这个数字本身，即 $f[i][i] = \{s[i \times 2]\}$（即第 $i$ 个数字映射到字符串 $s$ 中的下标为 $i \times 2$ 的字符）。

接下来，我们从大到小枚举 $i$，然后从小到大枚举 $j$，我们需要求出区间 $[i, j]$ 所有数字运算的结果可能的取值。我们在区间 $[i, j]$ 中枚举分界点 $k$，那么 $f[i][j]$ 可以由 $f[i][k]$ 和 $f[k+1][j]$ 通过运算符 $s[k \times 2 + 1]$ 得到。因此我们可以得到如下状态转移方程：

$$
f[i][j] = \begin{cases}
\{s[i \times 2]\}, & i = j \\
\bigcup\limits_{k=i}^{j-1} \{f[i][k] \otimes f[k+1][j]\}, & i < j
\end{cases}
$$

其中 $\otimes$ 表示运算符，即 $s[k \times 2 + 1]$。

那么字符串 $s$ 所有数字运算的结果可能的取值就是 $f[0][m-1]$。

最后，我们统计答案。我们用一个数组 $cnt$ 统计答案数组 $answers$ 中每个答案出现的次数。如果答案等于 $x$，那么这个学生得到 $5$ 分，否则如果答案在 $f[0][m-1]$ 中，那么这个学生得到 $2$ 分。遍历 $cnt$，统计答案即可。

时间复杂度 $O(n^3 \times M^2)$，空间复杂度 $O(n^2 \times M^2)$。其中 $M$ 是答案可能的最大值，而 $n$ 是字符串 $s$ 的长度中数字的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def scoreOfStudents(self, s: str, answers: List[int]) -> int:
        def cal(s: str) -> int:
            res, pre = 0, int(s[0])
            for i in range(1, n, 2):
                if s[i] == "*":
                    pre *= int(s[i + 1])
                else:
                    res += pre
                    pre = int(s[i + 1])
            res += pre
            return res

        n = len(s)
        x = cal(s)
        m = (n + 1) >> 1
        f = [[set() for _ in range(m)] for _ in range(m)]
        for i in range(m):
            f[i][i] = {int(s[i << 1])}
        for i in range(m - 1, -1, -1):
            for j in range(i, m):
                for k in range(i, j):
                    for l in f[i][k]:
                        for r in f[k + 1][j]:
                            if s[k << 1 | 1] == "+" and l + r <= 1000:
                                f[i][j].add(l + r)
                            elif s[k << 1 | 1] == "*" and l * r <= 1000:
                                f[i][j].add(l * r)
        cnt = Counter(answers)
        ans = cnt[x] * 5
        for k, v in cnt.items():
            if k != x and k in f[0][m - 1]:
                ans += v << 1
        return ans
```

#### Java

```java
class Solution {
    public int scoreOfStudents(String s, int[] answers) {
        int n = s.length();
        int x = cal(s);
        int m = (n + 1) >> 1;
        Set<Integer>[][] f = new Set[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                f[i][j] = new HashSet<>();
            }
            f[i][i].add(s.charAt(i << 1) - '0');
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = i; j < m; ++j) {
                for (int k = i; k < j; ++k) {
                    for (int l : f[i][k]) {
                        for (int r : f[k + 1][j]) {
                            char op = s.charAt(k << 1 | 1);
                            if (op == '+' && l + r <= 1000) {
                                f[i][j].add(l + r);
                            } else if (op == '*' && l * r <= 1000) {
                                f[i][j].add(l * r);
                            }
                        }
                    }
                }
            }
        }
        int[] cnt = new int[1001];
        for (int ans : answers) {
            ++cnt[ans];
        }
        int ans = 5 * cnt[x];
        for (int i = 0; i <= 1000; ++i) {
            if (i != x && f[0][m - 1].contains(i)) {
                ans += 2 * cnt[i];
            }
        }
        return ans;
    }

    private int cal(String s) {
        int res = 0, pre = s.charAt(0) - '0';
        for (int i = 1; i < s.length(); i += 2) {
            char op = s.charAt(i);
            int cur = s.charAt(i + 1) - '0';
            if (op == '*') {
                pre *= cur;
            } else {
                res += pre;
                pre = cur;
            }
        }
        res += pre;
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int n = s.size();
        int x = cal(s);
        int m = (n + 1) >> 1;
        unordered_set<int> f[m][m];
        for (int i = 0; i < m; ++i) {
            f[i][i] = {s[i * 2] - '0'};
        }
        for (int i = m - 1; ~i; --i) {
            for (int j = i; j < m; ++j) {
                for (int k = i; k < j; ++k) {
                    for (int l : f[i][k]) {
                        for (int r : f[k + 1][j]) {
                            char op = s[k << 1 | 1];
                            if (op == '+' && l + r <= 1000) {
                                f[i][j].insert(l + r);
                            } else if (op == '*' && l * r <= 1000) {
                                f[i][j].insert(l * r);
                            }
                        }
                    }
                }
            }
        }
        int cnt[1001]{};
        for (int t : answers) {
            ++cnt[t];
        }
        int ans = 5 * cnt[x];
        for (int i = 0; i <= 1000; ++i) {
            if (i != x && f[0][m - 1].count(i)) {
                ans += cnt[i] << 1;
            }
        }
        return ans;
    }

    int cal(string& s) {
        int res = 0;
        int pre = s[0] - '0';
        for (int i = 1; i < s.size(); i += 2) {
            int cur = s[i + 1] - '0';
            if (s[i] == '*') {
                pre *= cur;
            } else {
                res += pre;
                pre = cur;
            }
        }
        res += pre;
        return res;
    }
};
```

#### Go

```go
func scoreOfStudents(s string, answers []int) int {
	n := len(s)
	x := cal(s)
	m := (n + 1) >> 1
	f := make([][]map[int]bool, m)
	for i := range f {
		f[i] = make([]map[int]bool, m)
		for j := range f[i] {
			f[i][j] = make(map[int]bool)
		}
		f[i][i][int(s[i<<1]-'0')] = true
	}
	for i := m - 1; i >= 0; i-- {
		for j := i; j < m; j++ {
			for k := i; k < j; k++ {
				for l := range f[i][k] {
					for r := range f[k+1][j] {
						op := s[k<<1|1]
						if op == '+' && l+r <= 1000 {
							f[i][j][l+r] = true
						} else if op == '*' && l*r <= 1000 {
							f[i][j][l*r] = true
						}
					}
				}
			}
		}
	}
	cnt := [1001]int{}
	for _, v := range answers {
		cnt[v]++
	}
	ans := cnt[x] * 5
	for k, v := range cnt {
		if k != x && f[0][m-1][k] {
			ans += v << 1
		}
	}
	return ans
}

func cal(s string) int {
	res, pre := 0, int(s[0]-'0')
	for i := 1; i < len(s); i += 2 {
		cur := int(s[i+1] - '0')
		if s[i] == '+' {
			res += pre
			pre = cur
		} else {
			pre *= cur
		}
	}
	res += pre
	return res
}
```

#### TypeScript

```ts
function scoreOfStudents(s: string, answers: number[]): number {
    const n = s.length;
    const cal = (s: string): number => {
        let res = 0;
        let pre = s.charCodeAt(0) - '0'.charCodeAt(0);
        for (let i = 1; i < s.length; i += 2) {
            const cur = s.charCodeAt(i + 1) - '0'.charCodeAt(0);
            if (s[i] === '+') {
                res += pre;
                pre = cur;
            } else {
                pre *= cur;
            }
        }
        res += pre;
        return res;
    };
    const x = cal(s);
    const m = (n + 1) >> 1;
    const f: Set<number>[][] = Array(m)
        .fill(0)
        .map(() =>
            Array(m)
                .fill(0)
                .map(() => new Set()),
        );
    for (let i = 0; i < m; ++i) {
        f[i][i].add(s[i << 1].charCodeAt(0) - '0'.charCodeAt(0));
    }
    for (let i = m - 1; i >= 0; --i) {
        for (let j = i; j < m; ++j) {
            for (let k = i; k < j; ++k) {
                for (const l of f[i][k]) {
                    for (const r of f[k + 1][j]) {
                        const op = s[(k << 1) + 1];
                        if (op === '+' && l + r <= 1000) {
                            f[i][j].add(l + r);
                        } else if (op === '*' && l * r <= 1000) {
                            f[i][j].add(l * r);
                        }
                    }
                }
            }
        }
    }
    const cnt: number[] = Array(1001).fill(0);
    for (const v of answers) {
        ++cnt[v];
    }
    let ans = cnt[x] * 5;
    for (let i = 0; i <= 1000; ++i) {
        if (i !== x && f[0][m - 1].has(i)) {
            ans += cnt[i] << 1;
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
