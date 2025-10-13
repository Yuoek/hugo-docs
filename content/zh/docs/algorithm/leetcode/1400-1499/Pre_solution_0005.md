---
title: "1440_计算布尔表达式的值 🔒"
date: 2025-10-08T18:37:18+08:00
weight: 5
tags: [二叉树, 位运算, 前缀和, 动态规划, 哈希表, 字符串, 广度优先搜索, 数学, 数据库, 数组, 数论, 栈, 树, 模拟, 深度优先搜索, 矩阵, 记忆化搜索]
---

{{< markmap >}}
### [1440_计算布尔表达式的值 🔒](#1440)
#### [数据库](#1440)
### [1441_用栈操作构建数组](#1441)
#### [栈](#1441)
#### [数组](#1441)
#### [模拟](#1441)
### [1442_形成两个异或相等数组的三元组数目](#1442)
#### [位运算](#1442)
#### [数组](#1442)
#### [哈希表](#1442)
#### [数学](#1442)
#### [前缀和](#1442)
### [1443_收集树上所有苹果的最少时间](#1443)
#### [树](#1443)
#### [深度优先搜索](#1443)
#### [广度优先搜索](#1443)
#### [哈希表](#1443)
### [1444_切披萨的方案数](#1444)
#### [记忆化搜索](#1444)
#### [数组](#1444)
#### [动态规划](#1444)
#### [矩阵](#1444)
#### [前缀和](#1444)
### [1445_苹果和桔子 🔒](#1445)
#### [数据库](#1445)
### [1446_连续字符](#1446)
#### [字符串](#1446)
### [1447_最简分数](#1447)
#### [数学](#1447)
#### [字符串](#1447)
#### [数论](#1447)
### [1448_统计二叉树中好节点的数目](#1448)
#### [树](#1448)
#### [深度优先搜索](#1448)
#### [广度优先搜索](#1448)
#### [二叉树](#1448)
### [1449_数位成本和为目标值的最大数字](#1449)
#### [数组](#1449)
#### [动态规划](#1449)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1440_计算布尔表达式的值 🔒
___
#### 数据库
---
### 1441_用栈操作构建数组
___
#### 栈
___
#### 数组
___
#### 模拟
---
### 1442_形成两个异或相等数组的三元组数目
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 前缀和
---
### 1443_收集树上所有苹果的最少时间
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
---
### 1444_切披萨的方案数
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
___
#### 前缀和
---
### 1445_苹果和桔子 🔒
___
#### 数据库
---
### 1446_连续字符
___
#### 字符串
---
### 1447_最简分数
___
#### 数学
___
#### 字符串
___
#### 数论
---
### 1448_统计二叉树中好节点的数目
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 二叉树
---
### 1449_数位成本和为目标值的最大数字
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 字符串 |
| 广度优先搜索 | 数学 | 数据库 |
| 数组 | 数论 | 栈 |
| 树 | 模拟 | 深度优先搜索 |
| 矩阵 | 记忆化搜索 |  |

# [1440. 计算布尔表达式的值 🔒](https://leetcode.cn/problems/evaluate-boolean-expression){#1440}

{{< tabs "1440" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    left_operand,
    operator,
    right_operand,
    CASE
        WHEN (
            (operator = '=' AND v1.value = v2.value)
            OR (operator = '>' AND v1.value > v2.value)
            OR (operator = '<' AND v1.value < v2.value)
        ) THEN 'true'
        ELSE 'false'
    END AS value
FROM
    Expressions AS e
    JOIN Variables AS v1 ON e.left_operand = v1.name
    JOIN Variables AS v2 ON e.right_operand = v2.name;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表 <code>Variables</code>:</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| name          | varchar |
| value         | int     |
+---------------+---------+
在 SQL 中，name 是该表主键.
该表包含了存储的变量及其对应的值.
</pre>

<p>&nbsp;</p>

<p>表 <code>Expressions</code>:</p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| left_operand  | varchar |
| operator      | enum    |
| right_operand | varchar |
+---------------+---------+
在 SQL 中，(left_operand, operator, right_operand) 是该表主键.
该表包含了需要计算的布尔表达式.
operator 是枚举类型, 取值于('&lt;', '&gt;', '=')
left_operand 和 right_operand 的值保证存在于 Variables 表单中.
</pre>

<p>&nbsp;</p>

<p>计算表 <code>Expressions</code>&nbsp;中的布尔表达式。</p>

<p>返回的结果表 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Variables 表:
+------+-------+
| name | value |
+------+-------+
| x    | 66    |
| y    | 77    |
+------+-------+

Expressions 表:
+--------------+----------+---------------+
| left_operand | operator | right_operand |
+--------------+----------+---------------+
| x            | &gt;        | y             |
| x            | &lt;        | y             |
| x            | =        | y             |
| y            | &gt;        | x             |
| y            | &lt;        | x             |
| x            | =        | x             |
+--------------+----------+---------------+

<strong>输出:</strong>
+--------------+----------+---------------+-------+
| left_operand | operator | right_operand | value |
+--------------+----------+---------------+-------+
| x            | &gt;        | y             | false |
| x            | &lt;        | y             | true  |
| x            | =        | y             | false |
| y            | &gt;        | x             | true  |
| y            | &lt;        | x             | false |
| x            | =        | x             | true  |
+--------------+----------+---------------+-------+
<strong>解释：</strong>
如上所示, 你需要通过使用 Variables 表来找到 Expressions 表中的每一个布尔表达式的值.
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + CASE 表达式

我们可以通过等值连接，将 `Expressions` 表中的每一行与 `Variables` 表中的两行进行关联，关联的条件是 `left_operand = name` 和 `right_operand = name`，然后通过 `CASE` 表达式来判断布尔表达式的值。如果 `operator` 为 `=`，则判断两个值是否相等；如果 `operator` 为 `>`，则判断左值是否大于右值；如果 `operator` 为 `<`，则判断左值是否小于右值。若是，那么布尔表达式的值为 `true`，否则为 `false`。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    left_operand,
    operator,
    right_operand,
    CASE
        WHEN (
            (operator = '=' AND v1.value = v2.value)
            OR (operator = '>' AND v1.value > v2.value)
            OR (operator = '<' AND v1.value < v2.value)
        ) THEN 'true'
        ELSE 'false'
    END AS value
FROM
    Expressions AS e
    JOIN Variables AS v1 ON e.left_operand = v1.name
    JOIN Variables AS v2 ON e.right_operand = v2.name;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1441. 用栈操作构建数组](https://leetcode.cn/problems/build-an-array-with-stack-operations){#1441}

{{< tabs "1441" >}}

{{% tab "python" %}}
```python
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        cur = 1
        for x in target:
            while cur < x:
                ans.extend(["Push", "Pop"])
                cur += 1
            ans.append("Push")
            cur += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        int cur = 1;
        for (int x : target) {
            while (cur < x) {
                ans.addAll(List.of("Push", "Pop"));
                ++cur;
            }
            ans.add("Push");
            ++cur;
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
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 1;
        for (int x : target) {
            while (cur < x) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++cur;
            }
            ans.push_back("Push");
            ++cur;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func buildArray(target []int, n int) (ans []string) {
	cur := 1
	for _, x := range target {
		for ; cur < x; cur++ {
			ans = append(ans, "Push", "Pop")
		}
		ans = append(ans, "Push")
		cur++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function buildArray(target: number[], n: number): string[] {
    const ans: string[] = [];
    let cur: number = 1;
    for (const x of target) {
        for (; cur < x; ++cur) {
            ans.push('Push', 'Pop');
        }
        ans.push('Push');
        ++cur;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut ans = Vec::new();
        let mut cur = 1;
        for &x in &target {
            while cur < x {
                ans.push("Push".to_string());
                ans.push("Pop".to_string());
                cur += 1;
            }
            ans.push("Push".to_string());
            cur += 1;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** ans = (char**) malloc(sizeof(char*) * (2 * n));
    *returnSize = 0;
    int cur = 1;
    for (int i = 0; i < targetSize; i++) {
        while (cur < target[i]) {
            ans[(*returnSize)++] = "Push";
            ans[(*returnSize)++] = "Pop";
            cur++;
        }
        ans[(*returnSize)++] = "Push";
        cur++;
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

<p>给你一个数组 <code>target</code> 和一个整数 <code>n</code>。</p>

<p>给你一个空栈和两种操作：</p>

<ul>
	<li><code>"Push"</code>：将一个整数加到栈顶。</li>
	<li><code>"Pop"</code>：从栈顶删除一个整数。</li>
</ul>

<p>同时给定一个范围 <code>[1, n]</code> 中的整数流。</p>

<p>使用两个栈操作使栈中的数字（从底部到顶部）等于 <code>target</code>。你应该遵循以下规则：</p>

<ul>
	<li>如果整数流不为空，从流中选取下一个整数并将其推送到栈顶。</li>
	<li>如果栈不为空，弹出栈顶的整数。</li>
	<li>如果，在任何时刻，栈中的元素（从底部到顶部）等于 <code>target</code>，则不要从流中读取新的整数，也不要对栈进行更多操作。</li>
</ul>

<p>请返回遵循上述规则构建&nbsp;<code>target</code> 所用的操作序列。如果存在多个合法答案，返回 <strong>任一</strong> 即可。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = [1,3], n = 3
<strong>输出：</strong>["Push","Push","Pop","Push"]
<strong>解释：</strong>一开始栈为空。最后一个元素是栈顶。<strong>
</strong>从流中读取 1 并推入数组。s = [1]。
从流中读取 2 并推入数组。s = [1,2]。
从栈顶删除整数。s = [1]。
从流中读取 3 并推入数组。s = [1,3]。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = [1,2,3], n = 3
<strong>输出：</strong>["Push","Push","Push"]
<strong>解释：</strong>一开始栈为空。最后一个元素是栈顶。
从流中读取 1 并推入数组。s = [1]。
从流中读取 2 并推入数组。s = [1,2]。
从流中读取 3 并推入数组。s = [1,2,3]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>target = [1,2], n = 4
<strong>输出：</strong>["Push","Push"]
<strong>解释：</strong>一开始栈为空。最后一个元素是栈顶。
从流中读取 1 并推入数组。s = [1]。
从流中读取 2 并推入数组。s = [1,2]。
由于栈（从底部到顶部）等于 target，我们停止栈操作。
从流中读取整数 3 的答案不被接受。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= target[i] &lt;= n</code></li>
	<li><code>target</code> 严格递增</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义一个变量 $\textit{cur}$ 表示当前待读取的数字，初始时 $\textit{cur} = 1$，用一个数组 $\textit{ans}$ 存储答案。

接下来，我们遍历数组 $\textit{target}$ 中的每个数字 $x$：

-   如果 $\textit{cur} < x$，我们将 $\textit{Push}$ 和 $\textit{Pop}$ 依次加入答案，直到 $\textit{cur} = x$；
-   然后我们将 $\textit{Push}$ 加入答案，表示读取数字 $x$；
-   接着，我们将 $\textit{cur}$ 加一，继续处理下一个数字。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{target}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        ans = []
        cur = 1
        for x in target:
            while cur < x:
                ans.extend(["Push", "Pop"])
                cur += 1
            ans.append("Push")
            cur += 1
        return ans
```

#### Java

```java
class Solution {
    public List<String> buildArray(int[] target, int n) {
        List<String> ans = new ArrayList<>();
        int cur = 1;
        for (int x : target) {
            while (cur < x) {
                ans.addAll(List.of("Push", "Pop"));
                ++cur;
            }
            ans.add("Push");
            ++cur;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 1;
        for (int x : target) {
            while (cur < x) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++cur;
            }
            ans.push_back("Push");
            ++cur;
        }
        return ans;
    }
};
```

#### Go

```go
func buildArray(target []int, n int) (ans []string) {
	cur := 1
	for _, x := range target {
		for ; cur < x; cur++ {
			ans = append(ans, "Push", "Pop")
		}
		ans = append(ans, "Push")
		cur++
	}
	return
}
```

#### TypeScript

```ts
function buildArray(target: number[], n: number): string[] {
    const ans: string[] = [];
    let cur: number = 1;
    for (const x of target) {
        for (; cur < x; ++cur) {
            ans.push('Push', 'Pop');
        }
        ans.push('Push');
        ++cur;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
        let mut ans = Vec::new();
        let mut cur = 1;
        for &x in &target {
            while cur < x {
                ans.push("Push".to_string());
                ans.push("Pop".to_string());
                cur += 1;
            }
            ans.push("Push".to_string());
            cur += 1;
        }
        ans
    }
}
```

#### C

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** buildArray(int* target, int targetSize, int n, int* returnSize) {
    char** ans = (char**) malloc(sizeof(char*) * (2 * n));
    *returnSize = 0;
    int cur = 1;
    for (int i = 0; i < targetSize; i++) {
        while (cur < target[i]) {
            ans[(*returnSize)++] = "Push";
            ans[(*returnSize)++] = "Pop";
            cur++;
        }
        ans[(*returnSize)++] = "Push";
        cur++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1442. 形成两个异或相等数组的三元组数目](https://leetcode.cn/problems/count-triplets-that-can-form-two-arrays-of-equal-xor){#1442}

{{< tabs "1442" >}}

{{% tab "python" %}}
```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans, n = 0, len(arr)
        for i, x in enumerate(arr):
            s = x
            for k in range(i + 1, n):
                s ^= arr[k]
                if s == 0:
                    ans += k - i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countTriplets(int[] arr) {
        int ans = 0, n = arr.length;
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
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
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
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
func countTriplets(arr []int) (ans int) {
	for i, x := range arr {
		s := x
		for k := i + 1; k < len(arr); k++ {
			s ^= arr[k]
			if s == 0 {
				ans += k - i
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTriplets(arr: number[]): number {
    const n = arr.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let s = arr[i];
        for (let k = i + 1; k < n; ++k) {
            s ^= arr[k];
            if (s === 0) {
                ans += k - i;
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
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = arr.len();

        for i in 0..n {
            let mut s = arr[i];
            for k in (i + 1)..n {
                s ^= arr[k];
                if s == 0 {
                    ans += (k - i) as i32;
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

<p>给你一个整数数组 <code>arr</code> 。</p>

<p>现需要从数组中取三个下标 <code>i</code>、<code>j</code> 和 <code>k</code> ，其中 <code>(0 &lt;= i &lt; j &lt;= k &lt; arr.length)</code> 。</p>

<p><code>a</code> 和 <code>b</code> 定义如下：</p>

<ul>
	<li><code>a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]</code></li>
	<li><code>b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]</code></li>
</ul>

<p>注意：<strong>^</strong> 表示 <strong>按位异或</strong> 操作。</p>

<p>请返回能够令 <code>a == b</code> 成立的三元组 (<code>i</code>, <code>j</code> , <code>k</code>) 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>arr = [2,3,1,6,7]
<strong>输出：</strong>4
<strong>解释：</strong>满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>arr = [1,1,1,1,1]
<strong>输出：</strong>10
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>arr = [2,3]
<strong>输出：</strong>0
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>arr = [1,3,5,7,9]
<strong>输出：</strong>3
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>arr = [7,11,12,9,5,2,7,17,22]
<strong>输出：</strong>8
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 300</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10^8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

根据题目描述，要找到满足 $a = b$ 的三元组 $(i, j, k)$，即满足 $s = a \oplus b = 0$，我们只需要枚举左端点 $i$，然后计算以 $k$ 为右端点的区间 $[i, k]$ 的前缀异或和 $s$，如果 $s = 0$，那么对于任意 $j \in [i + 1, k]$，都满足 $a = b$，即 $(i, j, k)$ 是一个满足条件的三元组，一共有 $k - i$ 个，我们将其累加到答案中即可。

枚举结束后，返回答案即可。

时间复杂度 $O(n^2)$，其中 $n$ 是数组 $\textit{arr}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans, n = 0, len(arr)
        for i, x in enumerate(arr):
            s = x
            for k in range(i + 1, n):
                s ^= arr[k]
                if s == 0:
                    ans += k - i
        return ans
```

#### Java

```java
class Solution {
    public int countTriplets(int[] arr) {
        int ans = 0, n = arr.length;
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
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
    int countTriplets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        for (int i = 0; i < n; ++i) {
            int s = arr[i];
            for (int k = i + 1; k < n; ++k) {
                s ^= arr[k];
                if (s == 0) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countTriplets(arr []int) (ans int) {
	for i, x := range arr {
		s := x
		for k := i + 1; k < len(arr); k++ {
			s ^= arr[k]
			if s == 0 {
				ans += k - i
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countTriplets(arr: number[]): number {
    const n = arr.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        let s = arr[i];
        for (let k = i + 1; k < n; ++k) {
            s ^= arr[k];
            if (s === 0) {
                ans += k - i;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_triplets(arr: Vec<i32>) -> i32 {
        let mut ans = 0;
        let n = arr.len();

        for i in 0..n {
            let mut s = arr[i];
            for k in (i + 1)..n {
                s ^= arr[k];
                if s == 0 {
                    ans += (k - i) as i32;
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

# [1443. 收集树上所有苹果的最少时间](https://leetcode.cn/problems/minimum-time-to-collect-all-apples-in-a-tree){#1443}

{{< tabs "1443" >}}

{{% tab "python" %}}
```python
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        def dfs(u, cost):
            if vis[u]:
                return 0
            vis[u] = True
            nxt_cost = 0
            for v in g[u]:
                nxt_cost += dfs(v, 2)
            if not hasApple[u] and nxt_cost == 0:
                return 0
            return cost + nxt_cost

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        vis = [False] * n
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        boolean[] vis = new boolean[n];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        return dfs(0, 0, g, hasApple, vis);
    }

    private int dfs(int u, int cost, List<Integer>[] g, List<Boolean> hasApple, boolean[] vis) {
        if (vis[u]) {
            return 0;
        }
        vis[u] = true;
        int nxtCost = 0;
        for (int v : g[u]) {
            nxtCost += dfs(v, 2, g, hasApple, vis);
        }
        if (!hasApple.get(u) && nxtCost == 0) {
            return 0;
        }
        return cost + nxtCost;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return dfs(0, 0, g, hasApple, vis);
    }

    int dfs(int u, int cost, vector<vector<int>>& g, vector<bool>& hasApple, vector<bool>& vis) {
        if (vis[u]) return 0;
        vis[u] = true;
        int nxt = 0;
        for (int& v : g[u]) nxt += dfs(v, 2, g, hasApple, vis);
        if (!hasApple[u] && !nxt) return 0;
        return cost + nxt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minTime(n int, edges [][]int, hasApple []bool) int {
	vis := make([]bool, n)
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	var dfs func(int, int) int
	dfs = func(u, cost int) int {
		if vis[u] {
			return 0
		}
		vis[u] = true
		nxt := 0
		for _, v := range g[u] {
			nxt += dfs(v, 2)
		}
		if !hasApple[u] && nxt == 0 {
			return 0
		}
		return cost + nxt
	}
	return dfs(0, 0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵有&nbsp;<code>n</code>&nbsp;个节点的无向树，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n-1</code>&nbsp;，它们中有一些节点有苹果。通过树上的一条边，需要花费 1 秒钟。你从&nbsp;<strong>节点 0&nbsp;</strong>出发，请你返回最少需要多少秒，可以收集到所有苹果，并回到节点 0 。</p>

<p>无向树的边由&nbsp;<code>edges</code>&nbsp;给出，其中&nbsp;<code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;，表示有一条边连接&nbsp;<code>from</code>&nbsp;和&nbsp;<code>to<sub>i</sub></code> 。除此以外，还有一个布尔数组&nbsp;<code>hasApple</code> ，其中&nbsp;<code>hasApple[i] = true</code>&nbsp;代表节点&nbsp;<code>i</code>&nbsp;有一个苹果，否则，节点&nbsp;<code>i</code>&nbsp;没有苹果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1443.Minimum%20Time%20to%20Collect%20All%20Apples%20in%20a%20Tree/images/min_time_collect_apple_1.png" style="height: 212px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
<strong>输出：</strong>8 
<strong>解释：</strong>上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
</pre>

<p><strong class="example">示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1443.Minimum%20Time%20to%20Collect%20All%20Apples%20in%20a%20Tree/images/min_time_collect_apple_2.png" style="height: 212px; width: 300px;" /></strong></p>

<pre>
<strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
<strong>输出：</strong>6
<strong>解释：</strong>上图展示了给定的树，其中红色节点表示有苹果。一个能收集到所有苹果的最优方案由绿色箭头表示。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>&nbsp;&lt; b<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>hasApple.length == n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        def dfs(u, cost):
            if vis[u]:
                return 0
            vis[u] = True
            nxt_cost = 0
            for v in g[u]:
                nxt_cost += dfs(v, 2)
            if not hasApple[u] and nxt_cost == 0:
                return 0
            return cost + nxt_cost

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        vis = [False] * n
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        boolean[] vis = new boolean[n];
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            g[u].add(v);
            g[v].add(u);
        }
        return dfs(0, 0, g, hasApple, vis);
    }

    private int dfs(int u, int cost, List<Integer>[] g, List<Boolean> hasApple, boolean[] vis) {
        if (vis[u]) {
            return 0;
        }
        vis[u] = true;
        int nxtCost = 0;
        for (int v : g[u]) {
            nxtCost += dfs(v, 2, g, hasApple, vis);
        }
        if (!hasApple.get(u) && nxtCost == 0) {
            return 0;
        }
        return cost + nxtCost;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> vis(n);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return dfs(0, 0, g, hasApple, vis);
    }

    int dfs(int u, int cost, vector<vector<int>>& g, vector<bool>& hasApple, vector<bool>& vis) {
        if (vis[u]) return 0;
        vis[u] = true;
        int nxt = 0;
        for (int& v : g[u]) nxt += dfs(v, 2, g, hasApple, vis);
        if (!hasApple[u] && !nxt) return 0;
        return cost + nxt;
    }
};
```

#### Go

```go
func minTime(n int, edges [][]int, hasApple []bool) int {
	vis := make([]bool, n)
	g := make([][]int, n)
	for _, e := range edges {
		u, v := e[0], e[1]
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	var dfs func(int, int) int
	dfs = func(u, cost int) int {
		if vis[u] {
			return 0
		}
		vis[u] = true
		nxt := 0
		for _, v := range g[u] {
			nxt += dfs(v, 2)
		}
		if !hasApple[u] && nxt == 0 {
			return 0
		}
		return cost + nxt
	}
	return dfs(0, 0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1444. 切披萨的方案数](https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza){#1444}

{{< tabs "1444" >}}

{{% tab "python" %}}
```python
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if k == 0:
                return int(s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0)
            ans = 0
            for x in range(i + 1, m):
                if s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0:
                    ans += dfs(x, j, k - 1)
            for y in range(j + 1, n):
                if s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0:
                    ans += dfs(i, y, k - 1)
            return ans % mod

        mod = 10**9 + 7
        m, n = len(pizza), len(pizza[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(pizza, 1):
            for j, c in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + int(c == 'A')
        return dfs(0, 0, k - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] s;
    private Integer[][][] f;
    private final int mod = (int) 1e9 + 7;

    public int ways(String[] pizza, int k) {
        m = pizza.length;
        n = pizza[0].length();
        s = new int[m + 1][n + 1];
        f = new Integer[m][n][k];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = pizza[i - 1].charAt(j - 1) == 'A' ? 1 : 0;
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
            }
        }
        return dfs(0, 0, k - 1);
    }

    private int dfs(int i, int j, int k) {
        if (k == 0) {
            return s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0 ? 1 : 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = 0;
        for (int x = i + 1; x < m; ++x) {
            if (s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0) {
                ans = (ans + dfs(x, j, k - 1)) % mod;
            }
        }
        for (int y = j + 1; y < n; ++y) {
            if (s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0) {
                ans = (ans + dfs(i, y, k - 1)) % mod;
            }
        }
        return f[i][j][k] = ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(k, -1)));
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = pizza[i - 1][j - 1] == 'A' ? 1 : 0;
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
            }
        }
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (k == 0) {
                return s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0 ? 1 : 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = 0;
            for (int x = i + 1; x < m; ++x) {
                if (s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0) {
                    ans = (ans + dfs(x, j, k - 1)) % mod;
                }
            }
            for (int y = j + 1; y < n; ++y) {
                if (s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0) {
                    ans = (ans + dfs(i, y, k - 1)) % mod;
                }
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, 0, k - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func ways(pizza []string, k int) int {
	const mod = 1e9 + 7
	m, n := len(pizza), len(pizza[0])
	f := make([][][]int, m)
	s := make([][]int, m+1)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, k)
			for h := range f[i][j] {
				f[i][j][h] = -1
			}
		}
	}
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1]
			if pizza[i-1][j-1] == 'A' {
				s[i][j]++
			}
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		if k == 0 {
			if s[m][n]-s[m][j]-s[i][n]+s[i][j] > 0 {
				return 1
			}
			return 0
		}
		ans := 0
		for x := i + 1; x < m; x++ {
			if s[x][n]-s[x][j]-s[i][n]+s[i][j] > 0 {
				ans = (ans + dfs(x, j, k-1)) % mod
			}
		}
		for y := j + 1; y < n; y++ {
			if s[m][y]-s[m][j]-s[i][y]+s[i][j] > 0 {
				ans = (ans + dfs(i, y, k-1)) % mod
			}
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, 0, k-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function ways(pizza: string[], k: number): number {
    const mod = 1e9 + 7;
    const m = pizza.length;
    const n = pizza[0].length;
    const f = new Array(m).fill(0).map(() => new Array(n).fill(0).map(() => new Array(k).fill(-1)));
    const s = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const x = pizza[i - 1][j - 1] === 'A' ? 1 : 0;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }
    const dfs = (i: number, j: number, k: number): number => {
        if (f[i][j][k] !== -1) {
            return f[i][j][k];
        }
        if (k === 0) {
            return s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0 ? 1 : 0;
        }
        let ans = 0;
        for (let x = i + 1; x < m; ++x) {
            if (s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0) {
                ans = (ans + dfs(x, j, k - 1)) % mod;
            }
        }
        for (let y = j + 1; y < n; ++y) {
            if (s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0) {
                ans = (ans + dfs(i, y, k - 1)) % mod;
            }
        }
        return (f[i][j][k] = ans);
    };
    return dfs(0, 0, k - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>rows x cols</code>&nbsp;大小的矩形披萨和一个整数 <code>k</code>&nbsp;，矩形包含两种字符：&nbsp;<code>&#39;A&#39;</code> （表示苹果）和&nbsp;<code>&#39;.&#39;</code>&nbsp;（表示空白格子）。你需要切披萨 <code>k-1</code> 次，得到&nbsp;<code>k</code>&nbsp;块披萨并送给别人。</p>

<p>切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。</p>

<p>请你返回确保每一块披萨包含&nbsp;<strong>至少</strong>&nbsp;一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1444.Number%20of%20Ways%20of%20Cutting%20a%20Pizza/images/ways_to_cut_apple_1.png" style="height: 378px; width: 500px;"></strong></p>

<pre><strong>输入：</strong>pizza = [&quot;A..&quot;,&quot;AAA&quot;,&quot;...&quot;], k = 3
<strong>输出：</strong>3 
<strong>解释：</strong>上图展示了三种切披萨的方案。注意每一块披萨都至少包含一个苹果。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>pizza = [&quot;A..&quot;,&quot;AA.&quot;,&quot;...&quot;], k = 3
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>pizza = [&quot;A..&quot;,&quot;A..&quot;,&quot;...&quot;], k = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rows, cols &lt;= 50</code></li>
	<li><code>rows ==&nbsp;pizza.length</code></li>
	<li><code>cols ==&nbsp;pizza[i].length</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>pizza</code>&nbsp;只包含字符&nbsp;<code>&#39;A&#39;</code>&nbsp;和&nbsp;<code>&#39;.&#39;</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维前缀和 + 记忆化搜索

我们可以使用二维前缀和来快速计算出每个子矩形中苹果的数量，定义 $s[i][j]$ 表示矩形前 $i$ 行，前 $j$ 列的子矩形中苹果的数量，那么 $s[i][j]$ 可以由 $s[i-1][j]$, $s[i][j-1]$, $s[i-1][j-1]$ 三个子矩形的苹果数量求得，具体的计算方法如下：

$$
s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + \textit{int}(pizza[i-1][j-1] == 'A')
$$

其中 $pizza[i-1][j-1]$ 表示矩形中第 $i$ 行，第 $j$ 列的字符，如果是苹果，则为 $1$，否则为 $0$。

接下来，我们设计一个函数 $dfs(i, j, k)$，表示将矩形 $(i, j, m-1, n-1)$ 切 $k$ 刀，得到 $k+1$ 块披萨的方案数，其中 $(i, j)$ 和 $(m-1, n-1)$ 分别是矩形的左上角和右下角的坐标。函数 $dfs(i, j, k)$ 的计算方法如下：

-   如果 $k = 0$，表示没有可以切了，那么我们需要判断矩形中是否有苹果，如果有苹果，则返回 $1$，否则返回 $0$；
-   如果 $k \gt 0$，我们需要枚举最后一刀的切法，如果最后一刀是水平切，那么我们需要枚举切的位置 $x$，其中 $i \lt x \lt m$，如果 $s[x][n] - s[i][n] - s[x][j] + s[i][j] \gt 0$，说明切出来的上面一块披萨中有苹果，我们累加 $dfs(x, j, k-1)$ 的值到答案中；如果最后一刀是垂直切，那么我们需要枚举切的位置 $y$，其中 $j \lt y \lt n$，如果 $s[m][y] - s[i][y] - s[m][j] + s[i][j] \gt 0$，说明切出来的左边一块披萨中有苹果，我们累加 $dfs(i, y, k-1)$ 的值到答案中。

最终的答案即为 $dfs(0, 0, k-1)$ 的值。

为了避免重复计算，我们可以使用记忆化搜索的方法，用一个三维数组 $f$ 来记录 $dfs(i, j, k)$ 的值。当我们需要计算 $dfs(i, j, k)$ 的值时，如果 $f[i][j][k]$ 不为 $-1$，说明我们之前已经计算过了，直接返回 $f[i][j][k]$ 即可，否则我们按照上面的方法计算 $dfs(i, j, k)$ 的值，并将结果保存到 $f[i][j][k]$ 中。

时间复杂度 $O(m \times n \times k \times (m + n))$，空间复杂度 $O(m \times n \times k)$。其中 $m$, $n$ 分别是矩形的行数和列数。

相似题目：

-   [2312. 卖木头块](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2312.Selling%20Pieces%20of%20Wood/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if k == 0:
                return int(s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0)
            ans = 0
            for x in range(i + 1, m):
                if s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0:
                    ans += dfs(x, j, k - 1)
            for y in range(j + 1, n):
                if s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0:
                    ans += dfs(i, y, k - 1)
            return ans % mod

        mod = 10**9 + 7
        m, n = len(pizza), len(pizza[0])
        s = [[0] * (n + 1) for _ in range(m + 1)]
        for i, row in enumerate(pizza, 1):
            for j, c in enumerate(row, 1):
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + int(c == 'A')
        return dfs(0, 0, k - 1)
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] s;
    private Integer[][][] f;
    private final int mod = (int) 1e9 + 7;

    public int ways(String[] pizza, int k) {
        m = pizza.length;
        n = pizza[0].length();
        s = new int[m + 1][n + 1];
        f = new Integer[m][n][k];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = pizza[i - 1].charAt(j - 1) == 'A' ? 1 : 0;
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
            }
        }
        return dfs(0, 0, k - 1);
    }

    private int dfs(int i, int j, int k) {
        if (k == 0) {
            return s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0 ? 1 : 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = 0;
        for (int x = i + 1; x < m; ++x) {
            if (s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0) {
                ans = (ans + dfs(x, j, k - 1)) % mod;
            }
        }
        for (int y = j + 1; y < n; ++y) {
            if (s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0) {
                ans = (ans + dfs(i, y, k - 1)) % mod;
            }
        }
        return f[i][j][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod = 1e9 + 7;
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(k, -1)));
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int x = pizza[i - 1][j - 1] == 'A' ? 1 : 0;
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
            }
        }
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (k == 0) {
                return s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0 ? 1 : 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = 0;
            for (int x = i + 1; x < m; ++x) {
                if (s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0) {
                    ans = (ans + dfs(x, j, k - 1)) % mod;
                }
            }
            for (int y = j + 1; y < n; ++y) {
                if (s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0) {
                    ans = (ans + dfs(i, y, k - 1)) % mod;
                }
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, 0, k - 1);
    }
};
```

#### Go

```go
func ways(pizza []string, k int) int {
	const mod = 1e9 + 7
	m, n := len(pizza), len(pizza[0])
	f := make([][][]int, m)
	s := make([][]int, m+1)
	for i := range f {
		f[i] = make([][]int, n)
		for j := range f[i] {
			f[i][j] = make([]int, k)
			for h := range f[i][j] {
				f[i][j][h] = -1
			}
		}
	}
	for i := range s {
		s[i] = make([]int, n+1)
	}
	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1]
			if pizza[i-1][j-1] == 'A' {
				s[i][j]++
			}
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		if k == 0 {
			if s[m][n]-s[m][j]-s[i][n]+s[i][j] > 0 {
				return 1
			}
			return 0
		}
		ans := 0
		for x := i + 1; x < m; x++ {
			if s[x][n]-s[x][j]-s[i][n]+s[i][j] > 0 {
				ans = (ans + dfs(x, j, k-1)) % mod
			}
		}
		for y := j + 1; y < n; y++ {
			if s[m][y]-s[m][j]-s[i][y]+s[i][j] > 0 {
				ans = (ans + dfs(i, y, k-1)) % mod
			}
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, 0, k-1)
}
```

#### TypeScript

```ts
function ways(pizza: string[], k: number): number {
    const mod = 1e9 + 7;
    const m = pizza.length;
    const n = pizza[0].length;
    const f = new Array(m).fill(0).map(() => new Array(n).fill(0).map(() => new Array(k).fill(-1)));
    const s = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= n; ++j) {
            const x = pizza[i - 1][j - 1] === 'A' ? 1 : 0;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }
    const dfs = (i: number, j: number, k: number): number => {
        if (f[i][j][k] !== -1) {
            return f[i][j][k];
        }
        if (k === 0) {
            return s[m][n] - s[i][n] - s[m][j] + s[i][j] > 0 ? 1 : 0;
        }
        let ans = 0;
        for (let x = i + 1; x < m; ++x) {
            if (s[x][n] - s[i][n] - s[x][j] + s[i][j] > 0) {
                ans = (ans + dfs(x, j, k - 1)) % mod;
            }
        }
        for (let y = j + 1; y < n; ++y) {
            if (s[m][y] - s[i][y] - s[m][j] + s[i][j] > 0) {
                ans = (ans + dfs(i, y, k - 1)) % mod;
            }
        }
        return (f[i][j][k] = ans);
    };
    return dfs(0, 0, k - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1445. 苹果和桔子 🔒](https://leetcode.cn/problems/apples-oranges){#1445}

{{< tabs "1445" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    sale_date,
    SUM(IF(fruit = 'apples', sold_num, -sold_num)) AS diff
FROM Sales
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Sales</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| sale_date     | date    |
| fruit         | enum    | 
| sold_num      | int     | 
+---------------+---------+
(sale_date, fruit) 是该表主键(具有唯一值的列的组合)。
该表包含了每一天中"苹果" 和 "桔子"的销售情况。
</pre>

<p>&nbsp;</p>

<p>编写解决方案报告每一天&nbsp;<strong>苹果</strong>&nbsp;和&nbsp;<strong>桔子</strong>&nbsp;销售的数目的差异.</p>

<p>返回的结果表,&nbsp;按照格式为&nbsp;('YYYY-MM-DD') 的 <code>sale_date</code> 排序.</p>

<p>返回结果表如下例所示:</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Sales</code> 表:
+------------+------------+-------------+
| sale_date  | fruit      | sold_num    |
+------------+------------+-------------+
| 2020-05-01 | apples     | 10          |
| 2020-05-01 | oranges    | 8           |
| 2020-05-02 | apples     | 15          |
| 2020-05-02 | oranges    | 15          |
| 2020-05-03 | apples     | 20          |
| 2020-05-03 | oranges    | 0           |
| 2020-05-04 | apples     | 15          |
| 2020-05-04 | oranges    | 16          |
+------------+------------+-------------+
<strong>输出：</strong>
+------------+--------------+
| sale_date  | diff         |
+------------+--------------+
| 2020-05-01 | 2            |
| 2020-05-02 | 0            |
| 2020-05-03 | 20           |
| 2020-05-04 | -1           |
+------------+--------------+
<strong>解释：</strong>
在 2020-05-01, 卖了 10 个苹果 和 8 个桔子 (差异为 10 - 8 = 2).
在 2020-05-02, 卖了 15 个苹果 和 15 个桔子 (差异为 15 - 15 = 0).
在 2020-05-03, 卖了 20 个苹果 和 0 个桔子 (差异为 20 - 0 = 20).
在 2020-05-04, 卖了 15 个苹果 和 16 个桔子 (差异为 15 - 16 = -1).
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组求和

我们可以将数据按照日期分组，然后用 `sum` 函数求出每天苹果和桔子 🔒 的销售差异。如果是苹果，我们就用正数表示，如果是桔子，我们就用负数表示。最后我们按照日期排序即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    sale_date,
    SUM(IF(fruit = 'apples', sold_num, -sold_num)) AS diff
FROM Sales
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1446. 连续字符](https://leetcode.cn/problems/consecutive-characters){#1446}

{{< tabs "1446" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPower(self, s: str) -> int:
        ans = t = 1
        for a, b in pairwise(s):
            if a == b:
                t += 1
                ans = max(ans, t)
            else:
                t = 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxPower(String s) {
        int ans = 1, t = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
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
    int maxPower(string s) {
        int ans = 1, t = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ans = max(ans, ++t);
            } else {
                t = 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPower(s string) int {
	ans, t := 1, 1
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			t++
			ans = max(ans, t)
		} else {
			t = 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPower(s: string): number {
    let ans = 1;
    let t = 1;
    for (let i = 1; i < s.length; ++i) {
        if (s[i] === s[i - 1]) {
            ans = Math.max(ans, ++t);
        } else {
            t = 1;
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;，字符串的<strong>「能量」</strong>定义为：只包含一种字符的最长非空子字符串的长度。</p>

<p>请你返回字符串 <code>s</code> 的 <strong>能量</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "leetcode"
<strong>输出：</strong>2
<strong>解释：</strong>子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abbcccddddeeeeedcba"
<strong>输出：</strong>5
<strong>解释：</strong>子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们定义一个变量 $\textit{t}$，表示当前连续字符的长度，初始时 $\textit{t}=1$。

接下来，我们从字符串 $s$ 的第二个字符开始遍历，如果当前字符与上一个字符相同，那么 $\textit{t} = \textit{t} + 1$，然后更新答案 $\textit{ans} = \max(\textit{ans}, \textit{t})$；否则 $\textit{t} = 1$。

最后返回答案 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPower(self, s: str) -> int:
        ans = t = 1
        for a, b in pairwise(s):
            if a == b:
                t += 1
                ans = max(ans, t)
            else:
                t = 1
        return ans
```

#### Java

```java
class Solution {
    public int maxPower(String s) {
        int ans = 1, t = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
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
    int maxPower(string s) {
        int ans = 1, t = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ans = max(ans, ++t);
            } else {
                t = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxPower(s string) int {
	ans, t := 1, 1
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			t++
			ans = max(ans, t)
		} else {
			t = 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxPower(s: string): number {
    let ans = 1;
    let t = 1;
    for (let i = 1; i < s.length; ++i) {
        if (s[i] === s[i - 1]) {
            ans = Math.max(ans, ++t);
        } else {
            t = 1;
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

# [1447. 最简分数](https://leetcode.cn/problems/simplified-fractions){#1447}

{{< tabs "1447" >}}

{{% tab "python" %}}
```python
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        return [
            f'{i}/{j}'
            for i in range(1, n)
            for j in range(i + 1, n + 1)
            if gcd(i, j) == 1
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> ans = new ArrayList<>();
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if (gcd(i, j) == 1) {
                    ans.add(i + "/" + j);
                }
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if (__gcd(i, j) == 1) {
                    ans.push_back(to_string(i) + "/" + to_string(j));
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
func simplifiedFractions(n int) (ans []string) {
	for i := 1; i < n; i++ {
		for j := i + 1; j < n+1; j++ {
			if gcd(i, j) == 1 {
				ans = append(ans, strconv.Itoa(i)+"/"+strconv.Itoa(j))
			}
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function simplifiedFractions(n: number): string[] {
    const ans: string[] = [];
    for (let i = 1; i < n; ++i) {
        for (let j = i + 1; j < n + 1; ++j) {
            if (gcd(i, j) === 1) {
                ans.push(`${i}/${j}`);
            }
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        match b {
            0 => a,
            _ => Solution::gcd(b, a % b),
        }
    }

    pub fn simplified_fractions(n: i32) -> Vec<String> {
        let mut res = vec![];
        for i in 1..n {
            for j in i + 1..=n {
                if Solution::gcd(i, j) == 1 {
                    res.push(format!("{}/{}", i, j));
                }
            }
        }
        res
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>n</code>&nbsp;，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于&nbsp;&nbsp;<code>n</code>&nbsp;的 <strong>最简&nbsp;</strong>分数&nbsp;。分数可以以 <strong>任意&nbsp;</strong>顺序返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>n = 2
<strong>输出：</strong>[&quot;1/2&quot;]
<strong>解释：</strong>&quot;1/2&quot; 是唯一一个分母小于等于 2 的最简分数。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>n = 3
<strong>输出：</strong>[&quot;1/2&quot;,&quot;1/3&quot;,&quot;2/3&quot;]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>n = 4
<strong>输出：</strong>[&quot;1/2&quot;,&quot;1/3&quot;,&quot;1/4&quot;,&quot;2/3&quot;,&quot;3/4&quot;]
<strong>解释：</strong>&quot;2/4&quot; 不是最简分数，因为它可以化简为 &quot;1/2&quot; 。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>n = 1
<strong>输出：</strong>[]
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

### 方法一：枚举分子分母

我们可以枚举分子 $i$ 和分母 $j$，其中 $1 \leq i < j \leq n$，并判断 $i$ 和 $j$ 的最大公约数是否为 $1$，如果是则 $i/j$ 是一个最简分数。

时间复杂度 $O(n^2 \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是给定的参数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        return [
            f'{i}/{j}'
            for i in range(1, n)
            for j in range(i + 1, n + 1)
            if gcd(i, j) == 1
        ]
```

#### Java

```java
class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> ans = new ArrayList<>();
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if (gcd(i, j) == 1) {
                    ans.add(i + "/" + j);
                }
            }
        }
        return ans;
    }

    private int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n + 1; ++j) {
                if (__gcd(i, j) == 1) {
                    ans.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func simplifiedFractions(n int) (ans []string) {
	for i := 1; i < n; i++ {
		for j := i + 1; j < n+1; j++ {
			if gcd(i, j) == 1 {
				ans = append(ans, strconv.Itoa(i)+"/"+strconv.Itoa(j))
			}
		}
	}
	return ans
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function simplifiedFractions(n: number): string[] {
    const ans: string[] = [];
    for (let i = 1; i < n; ++i) {
        for (let j = i + 1; j < n + 1; ++j) {
            if (gcd(i, j) === 1) {
                ans.push(`${i}/${j}`);
            }
        }
    }
    return ans;
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
```

#### Rust

```rust
impl Solution {
    fn gcd(a: i32, b: i32) -> i32 {
        match b {
            0 => a,
            _ => Solution::gcd(b, a % b),
        }
    }

    pub fn simplified_fractions(n: i32) -> Vec<String> {
        let mut res = vec![];
        for i in 1..n {
            for j in i + 1..=n {
                if Solution::gcd(i, j) == 1 {
                    res.push(format!("{}/{}", i, j));
                }
            }
        }
        res
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1448. 统计二叉树中好节点的数目](https://leetcode.cn/problems/count-good-nodes-in-binary-tree){#1448}

{{< tabs "1448" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, mx: int):
            if root is None:
                return
            nonlocal ans
            if mx <= root.val:
                ans += 1
                mx = root.val
            dfs(root.left, mx)
            dfs(root.right, mx)

        ans = 0
        dfs(root, -1000000)
        return ans
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
    private int ans = 0;

    public int goodNodes(TreeNode root) {
        dfs(root, -100000);
        return ans;
    }

    private void dfs(TreeNode root, int mx) {
        if (root == null) {
            return;
        }
        if (mx <= root.val) {
            ++ans;
            mx = root.val;
        }
        dfs(root.left, mx);
        dfs(root.right, mx);
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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int mx) {
            if (!root) {
                return;
            }
            if (mx <= root->val) {
                ++ans;
                mx = root->val;
            }
            dfs(root->left, mx);
            dfs(root->right, mx);
        };
        dfs(root, -1e6);
        return ans;
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
func goodNodes(root *TreeNode) (ans int) {
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, mx int) {
		if root == nil {
			return
		}
		if mx <= root.Val {
			ans++
			mx = root.Val
		}
		dfs(root.Left, mx)
		dfs(root.Right, mx)
	}
	dfs(root, -10001)
	return
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

function goodNodes(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null, mx: number) => {
        if (!root) {
            return;
        }
        if (mx <= root.val) {
            ++ans;
            mx = root.val;
        }
        dfs(root.left, mx);
        dfs(root.right, mx);
    };
    dfs(root, -1e6);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵根为&nbsp;<code>root</code>&nbsp;的二叉树，请你返回二叉树中好节点的数目。</p>

<p>「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1448.Count%20Good%20Nodes%20in%20Binary%20Tree/images/test_sample_1.png" style="height: 156px; width: 263px;"></strong></p>

<pre><strong>输入：</strong>root = [3,1,4,3,null,1,5]
<strong>输出：</strong>4
<strong>解释：</strong>图中蓝色节点为好节点。
根节点 (3) 永远是个好节点。
节点 4 -&gt; (3,4) 是路径中的最大值。
节点 5 -&gt; (3,4,5) 是路径中的最大值。
节点 3 -&gt; (3,1,3) 是路径中的最大值。</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1400-1499/1448.Count%20Good%20Nodes%20in%20Binary%20Tree/images/test_sample_2.png" style="height: 161px; width: 157px;"></strong></p>

<pre><strong>输入：</strong>root = [3,3,null,4,2]
<strong>输出：</strong>3
<strong>解释：</strong>节点 2 -&gt; (3, 3, 2) 不是好节点，因为 &quot;3&quot; 比它大。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>root = [1]
<strong>输出：</strong>1
<strong>解释：</strong>根节点是好节点。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>二叉树中节点数目范围是&nbsp;<code>[1, 10^5]</code>&nbsp;。</li>
	<li>每个节点权值的范围是&nbsp;<code>[-10^4, 10^4]</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(root, mx)$，表示从当前节点 $root$ 开始搜索好节点，其中 $mx$ 表示从根节点到当前节点的路径（不包括当前节点）上的最大值。

函数 $dfs(root, mx)$ 的执行逻辑如下：

如果 $root$ 为空，说明搜索结束，直接返回；

否则，我们判断 $root.val$ 与 $mx$ 的大小关系。如果 $mx \leq root.val$，说明 $root$ 是好节点，答案加一，并且我们需要更新 $mx$ 的值为 $root.val$。

接下来，我们递归调用 $dfs(root.left, mx)$ 和 $dfs(root.right, mx)$。

在主函数中，我们调用 $dfs(root, -10^6)$，其中 $-10^6$ 表示负无穷，因为题目中说明了每个节点权值的范围是 $[-10^4, 10^4]$，所以 $-10^6$ 肯定是一个比所有节点权值都小的值，这样就能保证 $dfs(root, -10^6)$ 一定会把根节点 $root$ 算作好节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是二叉树的节点数。

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
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(root: TreeNode, mx: int):
            if root is None:
                return
            nonlocal ans
            if mx <= root.val:
                ans += 1
                mx = root.val
            dfs(root.left, mx)
            dfs(root.right, mx)

        ans = 0
        dfs(root, -1000000)
        return ans
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
    private int ans = 0;

    public int goodNodes(TreeNode root) {
        dfs(root, -100000);
        return ans;
    }

    private void dfs(TreeNode root, int mx) {
        if (root == null) {
            return;
        }
        if (mx <= root.val) {
            ++ans;
            mx = root.val;
        }
        dfs(root.left, mx);
        dfs(root.right, mx);
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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int mx) {
            if (!root) {
                return;
            }
            if (mx <= root->val) {
                ++ans;
                mx = root->val;
            }
            dfs(root->left, mx);
            dfs(root->right, mx);
        };
        dfs(root, -1e6);
        return ans;
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
func goodNodes(root *TreeNode) (ans int) {
	var dfs func(*TreeNode, int)
	dfs = func(root *TreeNode, mx int) {
		if root == nil {
			return
		}
		if mx <= root.Val {
			ans++
			mx = root.Val
		}
		dfs(root.Left, mx)
		dfs(root.Right, mx)
	}
	dfs(root, -10001)
	return
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

function goodNodes(root: TreeNode | null): number {
    let ans = 0;
    const dfs = (root: TreeNode | null, mx: number) => {
        if (!root) {
            return;
        }
        if (mx <= root.val) {
            ++ans;
            mx = root.val;
        }
        dfs(root.left, mx);
        dfs(root.right, mx);
    };
    dfs(root, -1e6);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1449. 数位成本和为目标值的最大数字](https://leetcode.cn/problems/form-largest-integer-with-digits-that-add-up-to-target){#1449}

{{< tabs "1449" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        f = [[-inf] * (target + 1) for _ in range(10)]
        f[0][0] = 0
        g = [[0] * (target + 1) for _ in range(10)]
        for i, c in enumerate(cost, 1):
            for j in range(target + 1):
                if j < c or f[i][j - c] + 1 < f[i - 1][j]:
                    f[i][j] = f[i - 1][j]
                    g[i][j] = j
                else:
                    f[i][j] = f[i][j - c] + 1
                    g[i][j] = j - c
        if f[9][target] < 0:
            return "0"
        ans = []
        i, j = 9, target
        while i:
            if j == g[i][j]:
                i -= 1
            else:
                ans.append(str(i))
                j = g[i][j]
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestNumber(int[] cost, int target) {
        final int inf = 1 << 30;
        int[][] f = new int[10][target + 1];
        int[][] g = new int[10][target + 1];
        for (var e : f) {
            Arrays.fill(e, -inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= 9; ++i) {
            int c = cost[i - 1];
            for (int j = 0; j <= target; ++j) {
                if (j < c || f[i][j - c] + 1 < f[i - 1][j]) {
                    f[i][j] = f[i - 1][j];
                    g[i][j] = j;
                } else {
                    f[i][j] = f[i][j - c] + 1;
                    g[i][j] = j - c;
                }
            }
        }
        if (f[9][target] < 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 9, j = target; i > 0;) {
            if (j == g[i][j]) {
                --i;
            } else {
                sb.append(i);
                j = g[i][j];
            }
        }
        return sb.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        const int inf = 1 << 30;
        vector<vector<int>> f(10, vector<int>(target + 1, -inf));
        vector<vector<int>> g(10, vector<int>(target + 1));
        f[0][0] = 0;
        for (int i = 1; i <= 9; ++i) {
            int c = cost[i - 1];
            for (int j = 0; j <= target; ++j) {
                if (j < c || f[i][j - c] + 1 < f[i - 1][j]) {
                    f[i][j] = f[i - 1][j];
                    g[i][j] = j;
                } else {
                    f[i][j] = f[i][j - c] + 1;
                    g[i][j] = j - c;
                }
            }
        }
        if (f[9][target] < 0) {
            return "0";
        }
        string ans;
        for (int i = 9, j = target; i;) {
            if (g[i][j] == j) {
                --i;
            } else {
                ans += '0' + i;
                j = g[i][j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestNumber(cost []int, target int) string {
	const inf = 1 << 30
	f := make([][]int, 10)
	g := make([][]int, 10)
	for i := range f {
		f[i] = make([]int, target+1)
		g[i] = make([]int, target+1)
		for j := range f[i] {
			f[i][j] = -inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= 9; i++ {
		c := cost[i-1]
		for j := 0; j <= target; j++ {
			if j < c || f[i][j-c]+1 < f[i-1][j] {
				f[i][j] = f[i-1][j]
				g[i][j] = j
			} else {
				f[i][j] = f[i][j-c] + 1
				g[i][j] = j - c
			}
		}
	}
	if f[9][target] < 0 {
		return "0"
	}
	ans := []byte{}
	for i, j := 9, target; i > 0; {
		if g[i][j] == j {
			i--
		} else {
			ans = append(ans, '0'+byte(i))
			j = g[i][j]
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestNumber(cost: number[], target: number): string {
    const inf = 1 << 30;
    const f: number[][] = Array(10)
        .fill(0)
        .map(() => Array(target + 1).fill(-inf));
    const g: number[][] = Array(10)
        .fill(0)
        .map(() => Array(target + 1).fill(0));
    f[0][0] = 0;
    for (let i = 1; i <= 9; ++i) {
        const c = cost[i - 1];
        for (let j = 0; j <= target; ++j) {
            if (j < c || f[i][j - c] + 1 < f[i - 1][j]) {
                f[i][j] = f[i - 1][j];
                g[i][j] = j;
            } else {
                f[i][j] = f[i][j - c] + 1;
                g[i][j] = j - c;
            }
        }
    }
    if (f[9][target] < 0) {
        return '0';
    }
    const ans: number[] = [];
    for (let i = 9, j = target; i; ) {
        if (g[i][j] === j) {
            --i;
        } else {
            ans.push(i);
            j = g[i][j];
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

<p>给你一个整数数组 <code>cost</code> 和一个整数 <code>target</code> 。请你返回满足如下规则可以得到的 <strong>最大</strong> 整数：</p>

<ul>
	<li>给当前结果添加一个数位（<code>i + 1</code>）的成本为 <code>cost[i]</code> （<code>cost</code> 数组下标从 0 开始）。</li>
	<li>总成本必须恰好等于 <code>target</code> 。</li>
	<li>添加的数位中没有数字 0 。</li>
</ul>

<p>由于答案可能会很大，请你以字符串形式返回。</p>

<p>如果按照上述要求无法得到任何整数，请你返回 "0" 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>cost = [4,3,2,5,6,7,2,5,5], target = 9
<strong>输出：</strong>"7772"
<strong>解释：</strong>添加数位 '7' 的成本为 2 ，添加数位 '2' 的成本为 3 。所以 "7772" 的代价为 2*3+ 3*1 = 9 。 "977" 也是满足要求的数字，但 "7772" 是较大的数字。
<strong> 数字     成本</strong>
  1  ->   4
  2  ->   3
  3  ->   2
  4  ->   5
  5  ->   6
  6  ->   7
  7  ->   2
  8  ->   5
  9  ->   5
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>cost = [7,6,5,5,5,6,8,7,8], target = 12
<strong>输出：</strong>"85"
<strong>解释：</strong>添加数位 '8' 的成本是 7 ，添加数位 '5' 的成本是 5 。"85" 的成本为 7 + 5 = 12 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>cost = [2,4,6,2,4,6,4,4,4], target = 5
<strong>输出：</strong>"0"
<strong>解释：</strong>总成本是 target 的条件下，无法生成任何整数。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>cost = [6,10,15,40,40,40,40,40,40], target = 47
<strong>输出：</strong>"32211"
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>cost.length == 9</code></li>
	<li><code>1 <= cost[i] <= 5000</code></li>
	<li><code>1 <= target <= 5000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划（背包问题）

我们定义 $f[i][j]$ 表示使用前 $i$ 个数位，花费恰好为 $j$ 的情况下，能够得到的最大位数。初始时，$f[0][0]=0$，其余为 $-\infty$。

考虑 $f[i][j]$，第 $i$ 个数的花费为 $c = cost[i-1]$，如果 $j \lt c$，那么我们无法选取第 $i$ 个数位，此时有 $f[i][j]=f[i-1][j]$；否则我们可以选取第 $i$ 个数位，此时有 $f[i][j]=f[i][j-c]+1$。

如果 $f[9][target] \lt 0$，那么说明无法得到满足要求的整数，返回 "0" 即可。

否则，我们需要从 $f[9][target]$ 开始，倒推出每一位的数字。我们可以使用一个数组 $g[i][j]$ 记录 $f[i][j]$ 的上一个状态，从而倒推出每一位的数字。

具体地，在状态转移时，如果 $j \lt c$，或者 $f[i][j-c]+1 \lt f[i-1][j]$，那么我们不选取第 $i$ 个数位，此时有 $g[i][j]=j$；否则我们选取第 $i$ 个数位，此时有 $g[i][j]=j-c$。

最后，我们定义 $i = 9$, $j = target$，从 $g[i][j]$ 开始不断地倒推，如果 $g[i][j]=j$，说明数字 $i$ 没有被选取，我们令 $i = i - 1$；否则说明数字 $i$ 被选取，我们令 $j = g[i][j]$，并将数字 $i$ 加入答案中。重复上述操作，直到 $i = 0$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为数组 $cost$ 和 $target$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        f = [[-inf] * (target + 1) for _ in range(10)]
        f[0][0] = 0
        g = [[0] * (target + 1) for _ in range(10)]
        for i, c in enumerate(cost, 1):
            for j in range(target + 1):
                if j < c or f[i][j - c] + 1 < f[i - 1][j]:
                    f[i][j] = f[i - 1][j]
                    g[i][j] = j
                else:
                    f[i][j] = f[i][j - c] + 1
                    g[i][j] = j - c
        if f[9][target] < 0:
            return "0"
        ans = []
        i, j = 9, target
        while i:
            if j == g[i][j]:
                i -= 1
            else:
                ans.append(str(i))
                j = g[i][j]
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String largestNumber(int[] cost, int target) {
        final int inf = 1 << 30;
        int[][] f = new int[10][target + 1];
        int[][] g = new int[10][target + 1];
        for (var e : f) {
            Arrays.fill(e, -inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= 9; ++i) {
            int c = cost[i - 1];
            for (int j = 0; j <= target; ++j) {
                if (j < c || f[i][j - c] + 1 < f[i - 1][j]) {
                    f[i][j] = f[i - 1][j];
                    g[i][j] = j;
                } else {
                    f[i][j] = f[i][j - c] + 1;
                    g[i][j] = j - c;
                }
            }
        }
        if (f[9][target] < 0) {
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 9, j = target; i > 0;) {
            if (j == g[i][j]) {
                --i;
            } else {
                sb.append(i);
                j = g[i][j];
            }
        }
        return sb.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        const int inf = 1 << 30;
        vector<vector<int>> f(10, vector<int>(target + 1, -inf));
        vector<vector<int>> g(10, vector<int>(target + 1));
        f[0][0] = 0;
        for (int i = 1; i <= 9; ++i) {
            int c = cost[i - 1];
            for (int j = 0; j <= target; ++j) {
                if (j < c || f[i][j - c] + 1 < f[i - 1][j]) {
                    f[i][j] = f[i - 1][j];
                    g[i][j] = j;
                } else {
                    f[i][j] = f[i][j - c] + 1;
                    g[i][j] = j - c;
                }
            }
        }
        if (f[9][target] < 0) {
            return "0";
        }
        string ans;
        for (int i = 9, j = target; i;) {
            if (g[i][j] == j) {
                --i;
            } else {
                ans += '0' + i;
                j = g[i][j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func largestNumber(cost []int, target int) string {
	const inf = 1 << 30
	f := make([][]int, 10)
	g := make([][]int, 10)
	for i := range f {
		f[i] = make([]int, target+1)
		g[i] = make([]int, target+1)
		for j := range f[i] {
			f[i][j] = -inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= 9; i++ {
		c := cost[i-1]
		for j := 0; j <= target; j++ {
			if j < c || f[i][j-c]+1 < f[i-1][j] {
				f[i][j] = f[i-1][j]
				g[i][j] = j
			} else {
				f[i][j] = f[i][j-c] + 1
				g[i][j] = j - c
			}
		}
	}
	if f[9][target] < 0 {
		return "0"
	}
	ans := []byte{}
	for i, j := 9, target; i > 0; {
		if g[i][j] == j {
			i--
		} else {
			ans = append(ans, '0'+byte(i))
			j = g[i][j]
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function largestNumber(cost: number[], target: number): string {
    const inf = 1 << 30;
    const f: number[][] = Array(10)
        .fill(0)
        .map(() => Array(target + 1).fill(-inf));
    const g: number[][] = Array(10)
        .fill(0)
        .map(() => Array(target + 1).fill(0));
    f[0][0] = 0;
    for (let i = 1; i <= 9; ++i) {
        const c = cost[i - 1];
        for (let j = 0; j <= target; ++j) {
            if (j < c || f[i][j - c] + 1 < f[i - 1][j]) {
                f[i][j] = f[i - 1][j];
                g[i][j] = j;
            } else {
                f[i][j] = f[i][j - c] + 1;
                g[i][j] = j - c;
            }
        }
    }
    if (f[9][target] < 0) {
        return '0';
    }
    const ans: number[] = [];
    for (let i = 9, j = target; i; ) {
        if (g[i][j] === j) {
            --i;
        } else {
            ans.push(i);
            j = g[i][j];
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
