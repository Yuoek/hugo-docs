---
title: "1070_产品销售分析 III"
date: 2025-10-08T18:36:50+08:00
weight: 8
tags: [前缀和, 哈希表, 回溯, 字符串, 数学, 数据库, 数组, 矩阵, 计数]
---

{{< markmap >}}
### [1070_产品销售分析 III](#1070)
#### [数据库](#1070)
### [1071_字符串的最大公因子](#1071)
#### [数学](#1071)
#### [字符串](#1071)
### [1072_按列翻转得到最大值等行数](#1072)
#### [数组](#1072)
#### [哈希表](#1072)
#### [矩阵](#1072)
### [1073_负二进制数相加](#1073)
#### [数组](#1073)
#### [数学](#1073)
### [1074_元素和为目标值的子矩阵数量](#1074)
#### [数组](#1074)
#### [哈希表](#1074)
#### [矩阵](#1074)
#### [前缀和](#1074)
### [1075_项目员工 I](#1075)
#### [数据库](#1075)
### [1076_项目员工II 🔒](#1076)
#### [数据库](#1076)
### [1077_项目员工 III 🔒](#1077)
#### [数据库](#1077)
### [1078_Bigram 分词](#1078)
#### [字符串](#1078)
### [1079_活字印刷](#1079)
#### [哈希表](#1079)
#### [字符串](#1079)
#### [回溯](#1079)
#### [计数](#1079)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1070_产品销售分析 III
___
#### 数据库
---
### 1071_字符串的最大公因子
___
#### 数学
___
#### 字符串
---
### 1072_按列翻转得到最大值等行数
___
#### 数组
___
#### 哈希表
___
#### 矩阵
---
### 1073_负二进制数相加
___
#### 数组
___
#### 数学
---
### 1074_元素和为目标值的子矩阵数量
___
#### 数组
___
#### 哈希表
___
#### 矩阵
___
#### 前缀和
---
### 1075_项目员工 I
___
#### 数据库
---
### 1076_项目员工II 🔒
___
#### 数据库
---
### 1077_项目员工 III 🔒
___
#### 数据库
---
### 1078_Bigram 分词
___
#### 字符串
---
### 1079_活字印刷
___
#### 哈希表
___
#### 字符串
___
#### 回溯
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 哈希表 | 回溯 |
| 字符串 | 数学 | 数据库 |
| 数组 | 矩阵 | 计数 |

# [1070. 产品销售分析 III](https://leetcode.cn/problems/product-sales-analysis-iii){#1070}

{{< tabs "1070" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY product_id
                ORDER BY year
            ) AS rk
        FROM Sales
    )
SELECT product_id, year AS first_year, quantity, price
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>销售表&nbsp;<code>Sales</code>：</p>

<pre>
+-------------+-------+
| Column Name | Type  |
+-------------+-------+
| sale_id     | int   |
| product_id  | int   |
| year        | int   |
| quantity    | int   |
| price       | int   |
+-------------+-------+
(sale_id, year) 是这张表的主键（具有唯一值的列的组合）。
product_id 是产品表的外键（reference 列）。
这张表的每一行都表示：编号 product_id 的产品在某一年的销售额。
一个产品可能在同一年内有多个销售条目。
请注意，价格是按每单位计的。
</pre>

<p>编写解决方案，选出每个售出过的产品&nbsp;<strong>第一年</strong> 销售的 <strong>产品 id</strong>、<strong>年份</strong>、<strong>数量&nbsp;</strong>和 <strong>价格</strong>。</p>

<ul>
	<li>对每个 <code>product_id</code>，找到其在Sales表中首次出现的最早年份。</li>
	<li>返回该产品在该年度的 <strong>所有</strong> 销售条目。</li>
</ul>

<p>返回一张有这些列的表：<strong>product_id</strong>，<strong>first_year</strong>，<strong>quantity&nbsp;</strong>和<strong>&nbsp;price</strong>。</p>

<p>结果表中的条目可以按 <strong>任意顺序</strong> 排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Sales 表：
+---------+------------+------+----------+-------+
| sale_id | product_id | year | quantity | price |
+---------+------------+------+----------+-------+ 
| 1       | 100        | 2008 | 10       | 5000  |
| 2       | 100        | 2009 | 12       | 5000  |
| 7       | 200        | 2011 | 15       | 9000  |
+---------+------------+------+----------+-------+
<strong>输出：</strong>
+------------+------------+----------+-------+
| product_id | first_year | quantity | price |
+------------+------------+----------+-------+ 
| 100        | 2008       | 10       | 5000  |
| 200        | 2011       | 15       | 9000  |
+------------+------------+----------+-------+</pre>

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
    product_id,
    year AS first_year,
    quantity,
    price
FROM Sales
WHERE
    (product_id, year) IN (
        SELECT
            product_id,
            MIN(year) AS year
        FROM Sales
        GROUP BY product_id
    );
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
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY product_id
                ORDER BY year
            ) AS rk
        FROM Sales
    )
SELECT product_id, year AS first_year, quantity, price
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1071. 字符串的最大公因子](https://leetcode.cn/problems/greatest-common-divisor-of-strings){#1071}

{{< tabs "1071" >}}

{{% tab "python" %}}
```python
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ''
        n = gcd(len(str1), len(str2))
        return str1[:n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        int len = gcd(str1.length(), str2.length());
        return str1.substring(0, len);
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int n = __gcd(str1.size(), str2.size());
        return str1.substr(0, n);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func gcdOfStrings(str1 string, str2 string) string {
	if str1+str2 != str2+str1 {
		return ""
	}
	n := gcd(len(str1), len(str2))
	return str1[:n]
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        if str1.clone() + &str2 != str2.clone() + &str1 {
            return String::from("");
        }
        fn gcd(a: usize, b: usize) -> usize {
            if b == 0 {
                return a;
            }
            gcd(b, a % b)
        }

        let (m, n) = (str1.len().max(str2.len()), str1.len().min(str2.len()));
        str1[..gcd(m, n)].to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对于字符串&nbsp;<code>s</code> 和&nbsp;<code>t</code>，只有在&nbsp;<code>s = t + t + t + ... + t + t</code>（<code>t</code> 自身连接 1 次或多次）时，我们才认定&nbsp;“<code>t</code> 能除尽 <code>s</code>”。</p>

<p>给定两个字符串&nbsp;<code>str1</code>&nbsp;和&nbsp;<code>str2</code>&nbsp;。返回 <em>最长字符串&nbsp;<code>x</code>，要求满足&nbsp;<code>x</code> 能除尽 <code>str1</code> 且 <code>x</code> 能除尽 <code>str2</code></em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>str1 = "ABCABC", str2 = "ABC"
<strong>输出：</strong>"ABC"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>str1 = "ABABAB", str2 = "ABAB"
<strong>输出：</strong>"AB"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>str1 = "LEET", str2 = "CODE"
<strong>输出：</strong>""
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code>&nbsp;和&nbsp;<code>str2</code>&nbsp;由大写英文字母组成</li>
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
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def check(a, b):
            c = ""
            while len(c) < len(b):
                c += a
            return c == b

        for i in range(min(len(str1), len(str2)), 0, -1):
            t = str1[:i]
            if check(t, str1) and check(t, str2):
                return t
        return ''
```

#### Java

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        int len = gcd(str1.length(), str2.length());
        return str1.substring(0, len);
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int n = __gcd(str1.size(), str2.size());
        return str1.substr(0, n);
    }
};
```

#### Go

```go
func gcdOfStrings(str1 string, str2 string) string {
	if str1+str2 != str2+str1 {
		return ""
	}
	n := gcd(len(str1), len(str2))
	return str1[:n]
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### Rust

```rust
impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        if str1.clone() + &str2 != str2.clone() + &str1 {
            return String::from("");
        }
        fn gcd(a: usize, b: usize) -> usize {
            if b == 0 {
                return a;
            }
            gcd(b, a % b)
        }

        let (m, n) = (str1.len().max(str2.len()), str1.len().min(str2.len()));
        str1[..gcd(m, n)].to_string()
    }
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
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ''
        n = gcd(len(str1), len(str2))
        return str1[:n]
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1072. 按列翻转得到最大值等行数](https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows){#1072}

{{< tabs "1072" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        cnt = Counter()
        for row in matrix:
            t = tuple(row) if row[0] == 0 else tuple(x ^ 1 for x in row)
            cnt[t] += 1
        return max(cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> cnt = new HashMap<>();
        int ans = 0, n = matrix[0].length;
        for (var row : matrix) {
            char[] cs = new char[n];
            for (int i = 0; i < n; ++i) {
                cs[i] = (char) (row[0] ^ row[i]);
            }
            ans = Math.max(ans, cnt.merge(String.valueOf(cs), 1, Integer::sum));
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
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> cnt;
        int ans = 0;
        for (auto& row : matrix) {
            string s;
            for (int x : row) {
                s.push_back('0' + (row[0] == 0 ? x : x ^ 1));
            }
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxEqualRowsAfterFlips(matrix [][]int) (ans int) {
	cnt := map[string]int{}
	for _, row := range matrix {
		s := []byte{}
		for _, x := range row {
			if row[0] == 1 {
				x ^= 1
			}
			s = append(s, byte(x)+'0')
		}
		t := string(s)
		cnt[t]++
		ans = max(ans, cnt[t])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxEqualRowsAfterFlips(matrix: number[][]): number {
    const cnt = new Map<string, number>();
    let ans = 0;
    for (const row of matrix) {
        if (row[0] === 1) {
            for (let i = 0; i < row.length; i++) {
                row[i] ^= 1;
            }
        }
        const s = row.join('');
        cnt.set(s, (cnt.get(s) || 0) + 1);
        ans = Math.max(ans, cnt.get(s)!);
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

<p>给定&nbsp;<code>m x n</code>&nbsp;矩阵&nbsp;<code>matrix</code>&nbsp;。</p>

<p>你可以从中选出任意数量的列并翻转其上的&nbsp;<strong>每个&nbsp;</strong>单元格。（即翻转后，单元格的值从 <code>0</code> 变成 <code>1</code>，或者从 <code>1</code> 变为 <code>0</code> 。）</p>

<p>返回 <em>经过一些翻转后，行内所有值都相等的最大行数</em>&nbsp;。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[0,1],[1,1]]
<strong>输出：</strong>1
<strong>解释：</strong>不进行翻转，有 1 行所有值都相等。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[0,1],[1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>翻转第一列的值之后，这两行都由相等的值组成。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[0,0,0],[0,0,1],[1,1,0]]
<strong>输出：</strong>2
<strong>解释：</strong>翻转前两列的值之后，后两行由相等的值组成。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 300</code></li>
	<li><code>matrix[i][j] == 0</code> 或&nbsp;<code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们观察发现，如果矩阵中的两行满足以下条件之一，则它们可以通过翻转某些列的方式得到相等的行：

1. 两行的对应位置元素相等，即如果其中一行元素为 $1,0,0,1$，则另一行元素也为 $1,0,0,1$；
1. 两行的对应位置元素相反，即如果其中一行元素为 $1,0,0,1$，则另一行元素为 $0,1,1,0$。

我们称满足以上条件之一的两行元素为“等价行”，那么题目所求的答案即为矩阵中最多包含等价行的行数。

因此，我们可以遍历矩阵的每一行，将每一行转换成第一个元素为 $0$ 的“等价行”。具体做法如下：

-   如果当前行的第一个元素为 $0$，那么当前行的元素保持不变；
-   如果当前行的第一个元素为 $1$，那么我们将当前行的每个元素进行翻转，即 $0$ 变成 $1$, $1$ 变成 $0$。也就是说，我们将以 $1$ 开头的行翻转成以 $0$ 开头的“等价行”。

这样一来，我们只需要用一个哈希表来统计转换后的每一行的出现次数，其中键为转换后的行（可以将所有数字拼接成一个字符串），值为该行出现的次数。最后，哈希表中值的最大值即为矩阵中最多包含等价行的行数。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

相似题目：

-   [2128. 通过翻转行或列来去除所有的 1](https://github.com/doocs/leetcode/blob/main/solution/2100-2199/2128.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        cnt = Counter()
        for row in matrix:
            t = tuple(row) if row[0] == 0 else tuple(x ^ 1 for x in row)
            cnt[t] += 1
        return max(cnt.values())
```

#### Java

```java
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String, Integer> cnt = new HashMap<>();
        int ans = 0, n = matrix[0].length;
        for (var row : matrix) {
            char[] cs = new char[n];
            for (int i = 0; i < n; ++i) {
                cs[i] = (char) (row[0] ^ row[i]);
            }
            ans = Math.max(ans, cnt.merge(String.valueOf(cs), 1, Integer::sum));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> cnt;
        int ans = 0;
        for (auto& row : matrix) {
            string s;
            for (int x : row) {
                s.push_back('0' + (row[0] == 0 ? x : x ^ 1));
            }
            ans = max(ans, ++cnt[s]);
        }
        return ans;
    }
};
```

#### Go

```go
func maxEqualRowsAfterFlips(matrix [][]int) (ans int) {
	cnt := map[string]int{}
	for _, row := range matrix {
		s := []byte{}
		for _, x := range row {
			if row[0] == 1 {
				x ^= 1
			}
			s = append(s, byte(x)+'0')
		}
		t := string(s)
		cnt[t]++
		ans = max(ans, cnt[t])
	}
	return
}
```

#### TypeScript

```ts
function maxEqualRowsAfterFlips(matrix: number[][]): number {
    const cnt = new Map<string, number>();
    let ans = 0;
    for (const row of matrix) {
        if (row[0] === 1) {
            for (let i = 0; i < row.length; i++) {
                row[i] ^= 1;
            }
        }
        const s = row.join('');
        cnt.set(s, (cnt.get(s) || 0) + 1);
        ans = Math.max(ans, cnt.get(s)!);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1073. 负二进制数相加](https://leetcode.cn/problems/adding-two-negabinary-numbers){#1073}

{{< tabs "1073" >}}

{{% tab "python" %}}
```python
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        i, j = len(arr1) - 1, len(arr2) - 1
        c = 0
        ans = []
        while i >= 0 or j >= 0 or c:
            a = 0 if i < 0 else arr1[i]
            b = 0 if j < 0 else arr2[j]
            x = a + b + c
            c = 0
            if x >= 2:
                x -= 2
                c -= 1
            elif x == -1:
                x = 1
                c += 1
            ans.append(x)
            i, j = i - 1, j - 1
        while len(ans) > 1 and ans[-1] == 0:
            ans.pop()
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int i = arr1.length - 1, j = arr2.length - 1;
        List<Integer> ans = new ArrayList<>();
        for (int c = 0; i >= 0 || j >= 0 || c != 0; --i, --j) {
            int a = i < 0 ? 0 : arr1[i];
            int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c += 1;
            }
            ans.add(x);
        }
        while (ans.size() > 1 && ans.get(ans.size() - 1) == 0) {
            ans.remove(ans.size() - 1);
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(x -> x).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        vector<int> ans;
        for (int c = 0; i >= 0 || j >= 0 || c; --i, --j) {
            int a = i < 0 ? 0 : arr1[i];
            int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c += 1;
            }
            ans.push_back(x);
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addNegabinary(arr1 []int, arr2 []int) (ans []int) {
	i, j := len(arr1)-1, len(arr2)-1
	for c := 0; i >= 0 || j >= 0 || c != 0; i, j = i-1, j-1 {
		x := c
		if i >= 0 {
			x += arr1[i]
		}
		if j >= 0 {
			x += arr2[j]
		}
		c = 0
		if x >= 2 {
			x -= 2
			c -= 1
		} else if x == -1 {
			x = 1
			c += 1
		}
		ans = append(ans, x)
	}
	for len(ans) > 1 && ans[len(ans)-1] == 0 {
		ans = ans[:len(ans)-1]
	}
	for i, j = 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addNegabinary(arr1: number[], arr2: number[]): number[] {
    let i = arr1.length - 1,
        j = arr2.length - 1;
    const ans: number[] = [];
    for (let c = 0; i >= 0 || j >= 0 || c; --i, --j) {
        const a = i < 0 ? 0 : arr1[i];
        const b = j < 0 ? 0 : arr2[j];
        let x = a + b + c;
        c = 0;
        if (x >= 2) {
            x -= 2;
            c -= 1;
        } else if (x === -1) {
            x = 1;
            c += 1;
        }
        ans.push(x);
    }
    while (ans.length > 1 && ans[ans.length - 1] === 0) {
        ans.pop();
    }
    return ans.reverse();
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] AddNegabinary(int[] arr1, int[] arr2) {
        int i = arr1.Length - 1, j = arr2.Length - 1;
        List<int> ans = new List<int>();
        for (int c = 0; i >= 0 || j >= 0 || c != 0; --i, --j) {
            int a = i < 0 ? 0 : arr1[i];
            int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c = 1;
            }
            ans.Add(x);
        }
        while (ans.Count > 1 && ans[ans.Count - 1] == 0) {
            ans.RemoveAt(ans.Count - 1);
        }
        ans.Reverse();
        return ans.ToArray();
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出基数为 <strong>-2</strong>&nbsp;的两个数&nbsp;<code>arr1</code> 和&nbsp;<code>arr2</code>，返回两数相加的结果。</p>

<p>数字以&nbsp;<em>数组形式</em><strong>&nbsp;</strong>给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。例如，<code>arr&nbsp;= [1,1,0,1]</code>&nbsp;表示数字&nbsp;<code>(-2)^3&nbsp;+ (-2)^2 + (-2)^0 = -3</code>。<em>数组形式</em>&nbsp;中的数字 <code>arr</code> 也同样不含前导零：即&nbsp;<code>arr == [0]</code>&nbsp;或&nbsp;<code>arr[0] == 1</code>。</p>

<p>返回相同表示形式的 <code>arr1</code> 和 <code>arr2</code> 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [1,1,1,1,1], arr2 = [1,0,1]
<strong>输出：</strong>[1,0,0,0,0]
<strong>解释：</strong>arr1 表示 11，arr2 表示 5，输出表示 16 。
</pre>

<p><meta charset="UTF-8" /></p>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [0], arr2 = [0]
<strong>输出：</strong>[0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr1 = [0], arr2 = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= arr1.length,&nbsp;arr2.length &lt;= 1000</code></li>
	<li><code>arr1[i]</code>&nbsp;和&nbsp;<code>arr2[i]</code>&nbsp;都是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code></li>
	<li><code>arr1</code>&nbsp;和&nbsp;<code>arr2</code>&nbsp;都没有前导0</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历两个数组，从最低位开始，记两个数组当前位的数字为 $a$ 和 $b$，进位为 $c$，三个数相加的结果为 $x$。

-   先将进位 $c$ 置为 $0$。
-   如果 $x \geq 2$，由于 $(-2)^{i} + (-2)^{i} = -(-2)^{i+1}$，所以我们可以将 $x$ 减去 $2$，并向高位进位 $-1$。
-   如果 $x = -1$，由于 $-(-2)^{i} = (-2)^{i} + (-2)^{i+1}$，所以我们可以将 $x$ 置为 $1$，并向高位进位 $1$。

然后，我们将 $x$ 加入到答案数组中，然后继续处理下一位。

遍历结束后，去除答案数组中末尾的 $0$，并将数组反转，即可得到最终的答案。

时间复杂度 $O(\max(n, m))$，其中 $n$ 和 $m$ 分别是两个数组的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

相似题目：

-   [1017. 负二进制转换](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1017.Convert%20to%20Base%20-2/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        i, j = len(arr1) - 1, len(arr2) - 1
        c = 0
        ans = []
        while i >= 0 or j >= 0 or c:
            a = 0 if i < 0 else arr1[i]
            b = 0 if j < 0 else arr2[j]
            x = a + b + c
            c = 0
            if x >= 2:
                x -= 2
                c -= 1
            elif x == -1:
                x = 1
                c += 1
            ans.append(x)
            i, j = i - 1, j - 1
        while len(ans) > 1 and ans[-1] == 0:
            ans.pop()
        return ans[::-1]
```

#### Java

```java
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int i = arr1.length - 1, j = arr2.length - 1;
        List<Integer> ans = new ArrayList<>();
        for (int c = 0; i >= 0 || j >= 0 || c != 0; --i, --j) {
            int a = i < 0 ? 0 : arr1[i];
            int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c += 1;
            }
            ans.add(x);
        }
        while (ans.size() > 1 && ans.get(ans.size() - 1) == 0) {
            ans.remove(ans.size() - 1);
        }
        Collections.reverse(ans);
        return ans.stream().mapToInt(x -> x).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        vector<int> ans;
        for (int c = 0; i >= 0 || j >= 0 || c; --i, --j) {
            int a = i < 0 ? 0 : arr1[i];
            int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c += 1;
            }
            ans.push_back(x);
        }
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func addNegabinary(arr1 []int, arr2 []int) (ans []int) {
	i, j := len(arr1)-1, len(arr2)-1
	for c := 0; i >= 0 || j >= 0 || c != 0; i, j = i-1, j-1 {
		x := c
		if i >= 0 {
			x += arr1[i]
		}
		if j >= 0 {
			x += arr2[j]
		}
		c = 0
		if x >= 2 {
			x -= 2
			c -= 1
		} else if x == -1 {
			x = 1
			c += 1
		}
		ans = append(ans, x)
	}
	for len(ans) > 1 && ans[len(ans)-1] == 0 {
		ans = ans[:len(ans)-1]
	}
	for i, j = 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return ans
}
```

#### TypeScript

```ts
function addNegabinary(arr1: number[], arr2: number[]): number[] {
    let i = arr1.length - 1,
        j = arr2.length - 1;
    const ans: number[] = [];
    for (let c = 0; i >= 0 || j >= 0 || c; --i, --j) {
        const a = i < 0 ? 0 : arr1[i];
        const b = j < 0 ? 0 : arr2[j];
        let x = a + b + c;
        c = 0;
        if (x >= 2) {
            x -= 2;
            c -= 1;
        } else if (x === -1) {
            x = 1;
            c += 1;
        }
        ans.push(x);
    }
    while (ans.length > 1 && ans[ans.length - 1] === 0) {
        ans.pop();
    }
    return ans.reverse();
}
```

#### C#

```cs
public class Solution {
    public int[] AddNegabinary(int[] arr1, int[] arr2) {
        int i = arr1.Length - 1, j = arr2.Length - 1;
        List<int> ans = new List<int>();
        for (int c = 0; i >= 0 || j >= 0 || c != 0; --i, --j) {
            int a = i < 0 ? 0 : arr1[i];
            int b = j < 0 ? 0 : arr2[j];
            int x = a + b + c;
            c = 0;
            if (x >= 2) {
                x -= 2;
                c -= 1;
            } else if (x == -1) {
                x = 1;
                c = 1;
            }
            ans.Add(x);
        }
        while (ans.Count > 1 && ans[ans.Count - 1] == 0) {
            ans.RemoveAt(ans.Count - 1);
        }
        ans.Reverse();
        return ans.ToArray();
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1074. 元素和为目标值的子矩阵数量](https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target){#1074}

{{< tabs "1074" >}}

{{% tab "python" %}}
```python
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        def f(nums: List[int]) -> int:
            d = defaultdict(int)
            d[0] = 1
            cnt = s = 0
            for x in nums:
                s += x
                cnt += d[s - target]
                d[s] += 1
            return cnt

        m, n = len(matrix), len(matrix[0])
        ans = 0
        for i in range(m):
            col = [0] * n
            for j in range(i, m):
                for k in range(n):
                    col[k] += matrix[j][k]
                ans += f(col)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int[] col = new int[n];
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    col[k] += matrix[j][k];
                }
                ans += f(col, target);
            }
        }
        return ans;
    }

    private int f(int[] nums, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, 1);
        int s = 0, cnt = 0;
        for (int x : nums) {
            s += x;
            cnt += d.getOrDefault(s - target, 0);
            d.merge(s, 1, Integer::sum);
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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> col(n);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    col[k] += matrix[j][k];
                }
                ans += f(col, target);
            }
        }
        return ans;
    }

    int f(vector<int>& nums, int target) {
        unordered_map<int, int> d{{0, 1}};
        int cnt = 0, s = 0;
        for (int& x : nums) {
            s += x;
            if (d.count(s - target)) {
                cnt += d[s - target];
            }
            ++d[s];
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numSubmatrixSumTarget(matrix [][]int, target int) (ans int) {
	m, n := len(matrix), len(matrix[0])
	for i := 0; i < m; i++ {
		col := make([]int, n)
		for j := i; j < m; j++ {
			for k := 0; k < n; k++ {
				col[k] += matrix[j][k]
			}
			ans += f(col, target)
		}
	}
	return
}

func f(nums []int, target int) (cnt int) {
	d := map[int]int{0: 1}
	s := 0
	for _, x := range nums {
		s += x
		if v, ok := d[s-target]; ok {
			cnt += v
		}
		d[s]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numSubmatrixSumTarget(matrix: number[][], target: number): number {
    const m = matrix.length;
    const n = matrix[0].length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        const col: number[] = new Array(n).fill(0);
        for (let j = i; j < m; ++j) {
            for (let k = 0; k < n; ++k) {
                col[k] += matrix[j][k];
            }
            ans += f(col, target);
        }
    }
    return ans;
}

function f(nums: number[], target: number): number {
    const d: Map<number, number> = new Map();
    d.set(0, 1);
    let cnt = 0;
    let s = 0;
    for (const x of nums) {
        s += x;
        if (d.has(s - target)) {
            cnt += d.get(s - target)!;
        }
        d.set(s, (d.get(s) || 0) + 1);
    }
    return cnt;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出矩阵&nbsp;<code>matrix</code>&nbsp;和目标值&nbsp;<code>target</code>，返回元素总和等于目标值的非空子矩阵的数量。</p>

<p>子矩阵&nbsp;<code>x1, y1, x2, y2</code>&nbsp;是满足 <code>x1 &lt;= x &lt;= x2</code>&nbsp;且&nbsp;<code>y1 &lt;= y &lt;= y2</code>&nbsp;的所有单元&nbsp;<code>matrix[x][y]</code>&nbsp;的集合。</p>

<p>如果&nbsp;<code>(x1, y1, x2, y2)</code> 和&nbsp;<code>(x1', y1', x2', y2')</code>&nbsp;两个子矩阵中部分坐标不同（如：<code>x1 != x1'</code>），那么这两个子矩阵也不同。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1000-1099/1074.Number%20of%20Submatrices%20That%20Sum%20to%20Target/images/mate1.jpg" style="width: 242px; height: 242px;" /></p>

<pre>
<strong>输入：</strong>matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
<strong>输出：</strong>4
<strong>解释：</strong>四个只含 0 的 1x1 子矩阵。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,-1],[-1,1]], target = 0
<strong>输出：</strong>5
<strong>解释：</strong>两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[904]], target = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong><strong>提示：</strong></strong></p>

<ul>
	<li><code>1 &lt;= matrix.length &lt;= 100</code></li>
	<li><code>1 &lt;= matrix[0].length &lt;= 100</code></li>
	<li><code>-1000 &lt;= matrix[i][j] &lt;= 1000</code></li>
	<li><code>-10^8 &lt;= target &lt;= 10^8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举上下边界 + 前缀和 + 哈希表

我们可以枚举矩阵的上下边界 $i$ 和 $j$，每次算出当前上下边界内每列的元素和，记为数组 $col$，然后问题就转换为如何在数组 $col$ 中寻找和为目标值 $target$ 的子数组个数。我们累加这些子数组的个数，就是题目要求的答案。

那么题目就变成了：给定一个数组 $nums$ 和目标值 $target$，计算有多少个子数组的和为 $target$，我们可以通过函数 $f(nums, target)$ 来求解。

函数 $f(nums, target)$ 的计算方法如下：

-   定义一个哈希表 $d$，用来记录出现过的前缀和以及其出现次数，初始时 $d[0] = 1$；
-   初始化变量 $s = 0, cnt = 0$，其中 $s$ 表示前缀和，而 $cnt$ 表示和为 $target$ 的子数组个数；
-   从左到右遍历数组 $nums$，对于当前遍历到的元素 $x$，更新前缀和 $s = s + x$，如果 $d[s - target]$ 的值存在，那么更新 $cnt = cnt + d[s - target]$，即子数组个数增加 $d[s - target]$。然后更新哈希表中元素 $d[s]$ 的值，即 $d[s] = d[s] + 1$；继续遍历下一个元素；
-   遍历结束之后，返回子数组个数 $cnt$。

时间复杂度 $O(m^2 \times n)$，空间复杂度 $O(n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        def f(nums: List[int]) -> int:
            d = defaultdict(int)
            d[0] = 1
            cnt = s = 0
            for x in nums:
                s += x
                cnt += d[s - target]
                d[s] += 1
            return cnt

        m, n = len(matrix), len(matrix[0])
        ans = 0
        for i in range(m):
            col = [0] * n
            for j in range(i, m):
                for k in range(n):
                    col[k] += matrix[j][k]
                ans += f(col)
        return ans
```

#### Java

```java
class Solution {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int[] col = new int[n];
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    col[k] += matrix[j][k];
                }
                ans += f(col, target);
            }
        }
        return ans;
    }

    private int f(int[] nums, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        d.put(0, 1);
        int s = 0, cnt = 0;
        for (int x : nums) {
            s += x;
            cnt += d.getOrDefault(s - target, 0);
            d.merge(s, 1, Integer::sum);
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> col(n);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k) {
                    col[k] += matrix[j][k];
                }
                ans += f(col, target);
            }
        }
        return ans;
    }

    int f(vector<int>& nums, int target) {
        unordered_map<int, int> d{{0, 1}};
        int cnt = 0, s = 0;
        for (int& x : nums) {
            s += x;
            if (d.count(s - target)) {
                cnt += d[s - target];
            }
            ++d[s];
        }
        return cnt;
    }
};
```

#### Go

```go
func numSubmatrixSumTarget(matrix [][]int, target int) (ans int) {
	m, n := len(matrix), len(matrix[0])
	for i := 0; i < m; i++ {
		col := make([]int, n)
		for j := i; j < m; j++ {
			for k := 0; k < n; k++ {
				col[k] += matrix[j][k]
			}
			ans += f(col, target)
		}
	}
	return
}

func f(nums []int, target int) (cnt int) {
	d := map[int]int{0: 1}
	s := 0
	for _, x := range nums {
		s += x
		if v, ok := d[s-target]; ok {
			cnt += v
		}
		d[s]++
	}
	return
}
```

#### TypeScript

```ts
function numSubmatrixSumTarget(matrix: number[][], target: number): number {
    const m = matrix.length;
    const n = matrix[0].length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        const col: number[] = new Array(n).fill(0);
        for (let j = i; j < m; ++j) {
            for (let k = 0; k < n; ++k) {
                col[k] += matrix[j][k];
            }
            ans += f(col, target);
        }
    }
    return ans;
}

function f(nums: number[], target: number): number {
    const d: Map<number, number> = new Map();
    d.set(0, 1);
    let cnt = 0;
    let s = 0;
    for (const x of nums) {
        s += x;
        if (d.has(s - target)) {
            cnt += d.get(s - target)!;
        }
        d.set(s, (d.get(s) || 0) + 1);
    }
    return cnt;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1075. 项目员工 I](https://leetcode.cn/problems/project-employees-i){#1075}

{{< tabs "1075" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement
SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM
    Project
    JOIN Employee USING (employee_id)
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>项目表&nbsp;<code>Project</code>：&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
主键为 (project_id, employee_id)。
employee_id 是员工表 <code>Employee</code> 表的外键。
这张表的每一行表示 employee_id 的员工正在 project_id 的项目上工作。
</pre>

<p>&nbsp;</p>

<p>员工表&nbsp;<code>Employee</code>：</p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
主键是 employee_id。数据保证 experience_years 非空。
这张表的每一行包含一个员工的信息。</pre>

<p>&nbsp;</p>

<p>请写一个 SQL&nbsp;语句，查询每一个项目中员工的&nbsp;<strong>平均&nbsp;</strong>工作年限，<strong>精确到小数点后两位</strong>。</p>

<p>以 <strong>任意</strong> 顺序返回结果表。</p>

<p>查询结果的格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Project 表：
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+

Employee 表：
+-------------+--------+------------------+
| employee_id | name   | experience_years |
+-------------+--------+------------------+
| 1           | Khaled | 3                |
| 2           | Ali    | 2                |
| 3           | John   | 1                |
| 4           | Doe    | 2                |
+-------------+--------+------------------+

<strong>输出：</strong>
+-------------+---------------+
| project_id  | average_years |
+-------------+---------------+
| 1           | 2.00          |
| 2           | 2.50          |
+-------------+---------------+
<strong>解释：</strong>第一个项目中，员工的平均工作年限是 (3 + 2 + 1) / 3 = 2.00；第二个项目中，员工的平均工作年限是 (3 + 2) / 2 = 2.50
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：内连接 + `GROUP BY` 分组

我们可以通过内连接将两张表连接起来，然后通过 `GROUP BY` 分组，最后使用 `AVG` 函数求工作年限的平均值。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement
SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM
    Project
    JOIN Employee USING (employee_id)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1076. 项目员工II 🔒](https://leetcode.cn/problems/project-employees-ii){#1076}

{{< tabs "1076" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            project_id,
            RANK() OVER (ORDER BY COUNT(employee_id) DESC) AS rk
        FROM Project
        GROUP BY 1
    )
SELECT project_id
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Project</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) 是该表的主键(具有唯一值的列的组合)。
employee_id 是该表的外键(reference 列)。
该表的每一行都表明 employee_id 的雇员正在处理 Project 表中 project_id 的项目。
</pre>

<p>表：<code>Employee</code></p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id 是该表的主键(具有唯一值的列)。
该表的每一行都包含一名雇员的信息。</pre>

<p>&nbsp;</p>

<p>编写一个解决方案来报告所有拥有最多员工的 <strong>项目</strong>。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Project table:
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+
Employee table:
+-------------+--------+------------------+
| employee_id | name   | experience_years |
+-------------+--------+------------------+
| 1           | Khaled | 3                |
| 2           | Ali    | 2                |
| 3           | John   | 1                |
| 4           | Doe    | 2                |
+-------------+--------+------------------+
<strong>输出：</strong>
+-------------+
| project_id  |
+-------------+
| 1           |
+-------------+
<strong>解释：</strong>
第一个项目有3名员工，第二个项目有2名员工。</pre>

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
SELECT project_id
FROM Project
GROUP BY 1
HAVING
    COUNT(1) >= all(
        SELECT COUNT(1)
        FROM Project
        GROUP BY project_id
    );
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
    T AS (
        SELECT
            project_id,
            RANK() OVER (ORDER BY COUNT(employee_id) DESC) AS rk
        FROM Project
        GROUP BY 1
    )
SELECT project_id
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1077. 项目员工 III 🔒](https://leetcode.cn/problems/project-employees-iii){#1077}

{{< tabs "1077" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY project_id
                ORDER BY experience_years DESC
            ) AS rk
        FROM
            Project
            JOIN Employee USING (employee_id)
    )
SELECT project_id, employee_id
FROM T
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>项目表&nbsp;<code>Project</code>：</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| project_id  | int     |
| employee_id | int     |
+-------------+---------+
(project_id, employee_id) 是这个表的主键（具有唯一值的列的组合）
employee_id 是员工表 Employee 的外键（reference 列）
该表的每一行都表明具有 employee_id 的雇员正在处理具有 project_id 的项目。
</pre>

<p>员工表&nbsp;<code>Employee</code>：</p>

<pre>
+------------------+---------+
| Column Name      | Type    |
+------------------+---------+
| employee_id      | int     |
| name             | varchar |
| experience_years | int     |
+------------------+---------+
employee_id 是这个表的主键（具有唯一值的列）
该表的每一行都包含一名雇员的信息。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告在每一个项目中 <strong>经验最丰富</strong> 的雇员是谁。如果出现经验年数相同的情况，请报告所有具有最大经验年数的员工。</p>

<p>返回结果表 <strong>无顺序要求 。</strong></p>

<p>结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Project 表：
+-------------+-------------+
| project_id  | employee_id |
+-------------+-------------+
| 1           | 1           |
| 1           | 2           |
| 1           | 3           |
| 2           | 1           |
| 2           | 4           |
+-------------+-------------+

Employee 表：
+-------------+--------+------------------+
| employee_id | name   | experience_years |
+-------------+--------+------------------+
| 1           | Khaled | 3                |
| 2           | Ali    | 2                |
| 3           | John   | 3                |
| 4           | Doe    | 2                |
+-------------+--------+------------------+
<strong>输出：</strong>
+-------------+---------------+
| project_id  | employee_id   |
+-------------+---------------+
| 1           | 1             |
| 1           | 3             |
| 2           | 1             |
+-------------+---------------+
<strong>解释：</strong>employee_id 为 1 和 3 的员工在 project_id 为 1 的项目中拥有最丰富的经验。在 project_id 为 2 的项目中，employee_id 为 1 的员工拥有最丰富的经验。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：内连接 + 窗口函数

我们先将 `Project` 表和 `Employee` 表进行内连接，然后使用窗口函数 `rank()` 对 `Project` 表进行分组，按照 `experience_years` 降序排列，最后取出每个项目中经验最丰富的雇员。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            RANK() OVER (
                PARTITION BY project_id
                ORDER BY experience_years DESC
            ) AS rk
        FROM
            Project
            JOIN Employee USING (employee_id)
    )
SELECT project_id, employee_id
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1078. Bigram 分词](https://leetcode.cn/problems/occurrences-after-bigram){#1078}

{{< tabs "1078" >}}

{{% tab "python" %}}
```python
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words = text.split()
        ans = []
        for i in range(len(words) - 2):
            a, b, c = words[i : i + 3]
            if a == first and b == second:
                ans.append(c)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public String[] findOcurrences(String text, String first, String second) {
        String[] words = text.split(" ");
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length - 2; ++i) {
            if (first.equals(words[i]) && second.equals(words[i + 1])) {
                ans.add(words[i + 2]);
            }
        }
        return ans.toArray(new String[0]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream is(text);
        vector<string> words;
        string word;
        while (is >> word) {
            words.emplace_back(word);
        }
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n - 2; ++i) {
            if (words[i] == first && words[i + 1] == second) {
                ans.emplace_back(words[i + 2]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findOcurrences(text string, first string, second string) (ans []string) {
	words := strings.Split(text, " ")
	n := len(words)
	for i := 0; i < n-2; i++ {
		if words[i] == first && words[i+1] == second {
			ans = append(ans, words[i+2])
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findOcurrences(text: string, first: string, second: string): string[] {
    const words = text.split(' ');
    const n = words.length;
    const ans: string[] = [];
    for (let i = 0; i < n - 2; i++) {
        if (words[i] === first && words[i + 1] === second) {
            ans.push(words[i + 2]);
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

<p>给出第一个词&nbsp;<code>first</code> 和第二个词&nbsp;<code>second</code>，考虑在某些文本&nbsp;<code>text</code>&nbsp;中可能以 <code>"first second third"</code> 形式出现的情况，其中&nbsp;<code>second</code>&nbsp;紧随&nbsp;<code>first</code>&nbsp;出现，<code>third</code>&nbsp;紧随&nbsp;<code>second</code>&nbsp;出现。</p>

<p>对于每种这样的情况，将第三个词 "<code>third</code>" 添加到答案中，并返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>text = "alice is a good girl she is a good student", first = "a", second = "good"
<strong>输出：</strong>["girl","student"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>text = "we will we will rock you", first = "we", second = "will"
<strong>输出：</strong>["we","rock"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 1000</code></li>
	<li><code>text</code>&nbsp;由小写英文字母和空格组成</li>
	<li><code>text</code> 中的所有单词之间都由 <strong>单个空格字符</strong> 分隔</li>
	<li><code>1 &lt;= first.length, second.length &lt;= 10</code></li>
	<li><code>first</code> 和&nbsp;<code>second</code>&nbsp;由小写英文字母组成</li>
	<li><code>text</code>&nbsp;不包含任何前缀或尾随空格。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串分割

我们可以将字符串 $text$ 按照空格分割成字符串数组 $words$，然后遍历 $words$，如果 $words[i]$ 和 $words[i+1]$ 分别等于 $first$ 和 $second$，那么就将 $words[i+2]$ 添加到答案中。

遍历结束后，返回答案列表。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 是 $text$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words = text.split()
        ans = []
        for i in range(len(words) - 2):
            a, b, c = words[i : i + 3]
            if a == first and b == second:
                ans.append(c)
        return ans
```

#### Java

```java
class Solution {

    public String[] findOcurrences(String text, String first, String second) {
        String[] words = text.split(" ");
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length - 2; ++i) {
            if (first.equals(words[i]) && second.equals(words[i + 1])) {
                ans.add(words[i + 2]);
            }
        }
        return ans.toArray(new String[0]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream is(text);
        vector<string> words;
        string word;
        while (is >> word) {
            words.emplace_back(word);
        }
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n - 2; ++i) {
            if (words[i] == first && words[i + 1] == second) {
                ans.emplace_back(words[i + 2]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findOcurrences(text string, first string, second string) (ans []string) {
	words := strings.Split(text, " ")
	n := len(words)
	for i := 0; i < n-2; i++ {
		if words[i] == first && words[i+1] == second {
			ans = append(ans, words[i+2])
		}
	}
	return
}
```

#### TypeScript

```ts
function findOcurrences(text: string, first: string, second: string): string[] {
    const words = text.split(' ');
    const n = words.length;
    const ans: string[] = [];
    for (let i = 0; i < n - 2; i++) {
        if (words[i] === first && words[i + 1] === second) {
            ans.push(words[i + 2]);
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

# [1079. 活字印刷](https://leetcode.cn/problems/letter-tile-possibilities){#1079}

{{< tabs "1079" >}}

{{% tab "python" %}}
```python
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def dfs(cnt: Counter) -> int:
            ans = 0
            for i, x in cnt.items():
                if x > 0:
                    ans += 1
                    cnt[i] -= 1
                    ans += dfs(cnt)
                    cnt[i] += 1
            return ans

        cnt = Counter(tiles)
        return dfs(cnt)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numTilePossibilities(String tiles) {
        int[] cnt = new int[26];
        for (char c : tiles.toCharArray()) {
            ++cnt[c - 'A'];
        }
        return dfs(cnt);
    }

    private int dfs(int[] cnt) {
        int res = 0;
        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] > 0) {
                ++res;
                --cnt[i];
                res += dfs(cnt);
                ++cnt[i];
            }
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int cnt[26]{};
        for (char c : tiles) {
            ++cnt[c - 'A'];
        }
        function<int(int* cnt)> dfs = [&](int* cnt) -> int {
            int res = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    ++res;
                    --cnt[i];
                    res += dfs(cnt);
                    ++cnt[i];
                }
            }
            return res;
        };
        return dfs(cnt);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numTilePossibilities(tiles string) int {
	cnt := [26]int{}
	for _, c := range tiles {
		cnt[c-'A']++
	}
	var dfs func(cnt [26]int) int
	dfs = func(cnt [26]int) (res int) {
		for i, x := range cnt {
			if x > 0 {
				res++
				cnt[i]--
				res += dfs(cnt)
				cnt[i]++
			}
		}
		return
	}
	return dfs(cnt)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numTilePossibilities(tiles: string): number {
    const cnt: number[] = new Array(26).fill(0);
    for (const c of tiles) {
        ++cnt[c.charCodeAt(0) - 'A'.charCodeAt(0)];
    }
    const dfs = (cnt: number[]): number => {
        let res = 0;
        for (let i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                ++res;
                --cnt[i];
                res += dfs(cnt);
                ++cnt[i];
            }
        }
        return res;
    };
    return dfs(cnt);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一套活字字模&nbsp;<code>tiles</code>，其中每个字模上都刻有一个字母&nbsp;<code>tiles[i]</code>。返回你可以印出的非空字母序列的数目。</p>

<p><strong>注意：</strong>本题中，每个活字字模只能使用一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>"AAB"
<strong>输出：</strong>8
<strong>解释：</strong>可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>"AAABBC"
<strong>输出：</strong>188
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>"V"
<strong>输出：</strong>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= tiles.length &lt;= 7</code></li>
	<li><code>tiles</code> 由大写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 回溯

我们先用一个哈希表或数组 $cnt$ 统计每个字母出现的次数。

接下来定义一个函数 $dfs(cnt)$，表示当前剩余字母的计数为 $cnt$ 时，能够组成的不同序列的个数。

在 $dfs$ 中，我们枚举 $cnt$ 中每个大于 $0$ 的值 $cnt[i]$，将 $cnt[i]$ 减 $1$ 表示使用了这个字母，序列个数加 $1$，然后进行下一层搜索，在搜索结束后，累加返回的序列个数，然后将 $cnt[i]$ 加 $1$。最后返回序列个数。

时间复杂度 $O(n \times n!)$，空间复杂度 $O(n)$。其中 $n$ 为字母种类数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        def dfs(cnt: Counter) -> int:
            ans = 0
            for i, x in cnt.items():
                if x > 0:
                    ans += 1
                    cnt[i] -= 1
                    ans += dfs(cnt)
                    cnt[i] += 1
            return ans

        cnt = Counter(tiles)
        return dfs(cnt)
```

#### Java

```java
class Solution {
    public int numTilePossibilities(String tiles) {
        int[] cnt = new int[26];
        for (char c : tiles.toCharArray()) {
            ++cnt[c - 'A'];
        }
        return dfs(cnt);
    }

    private int dfs(int[] cnt) {
        int res = 0;
        for (int i = 0; i < cnt.length; ++i) {
            if (cnt[i] > 0) {
                ++res;
                --cnt[i];
                res += dfs(cnt);
                ++cnt[i];
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
    int numTilePossibilities(string tiles) {
        int cnt[26]{};
        for (char c : tiles) {
            ++cnt[c - 'A'];
        }
        function<int(int* cnt)> dfs = [&](int* cnt) -> int {
            int res = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    ++res;
                    --cnt[i];
                    res += dfs(cnt);
                    ++cnt[i];
                }
            }
            return res;
        };
        return dfs(cnt);
    }
};
```

#### Go

```go
func numTilePossibilities(tiles string) int {
	cnt := [26]int{}
	for _, c := range tiles {
		cnt[c-'A']++
	}
	var dfs func(cnt [26]int) int
	dfs = func(cnt [26]int) (res int) {
		for i, x := range cnt {
			if x > 0 {
				res++
				cnt[i]--
				res += dfs(cnt)
				cnt[i]++
			}
		}
		return
	}
	return dfs(cnt)
}
```

#### TypeScript

```ts
function numTilePossibilities(tiles: string): number {
    const cnt: number[] = new Array(26).fill(0);
    for (const c of tiles) {
        ++cnt[c.charCodeAt(0) - 'A'.charCodeAt(0)];
    }
    const dfs = (cnt: number[]): number => {
        let res = 0;
        for (let i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                ++res;
                --cnt[i];
                res += dfs(cnt);
                ++cnt[i];
            }
        }
        return res;
    };
    return dfs(cnt);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
