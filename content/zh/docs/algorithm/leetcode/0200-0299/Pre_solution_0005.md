---
title: "0240_搜索二维矩阵 II"
date: 2025-10-08T18:35:28+08:00
weight: 5
tags: [二分查找, 分治, 动态规划, 双指针, 哈希表, 字符串, 排序, 数学, 数组, 矩阵, 记忆化搜索, 设计, 递归]
---

{{< markmap >}}
### [0240_搜索二维矩阵 II](#240)
#### [数组](#240)
#### [二分查找](#240)
#### [分治](#240)
#### [矩阵](#240)
### [0241_为运算表达式设计优先级](#241)
#### [递归](#241)
#### [记忆化搜索](#241)
#### [数学](#241)
#### [字符串](#241)
#### [动态规划](#241)
### [0242_有效的字母异位词](#242)
#### [哈希表](#242)
#### [字符串](#242)
#### [排序](#242)
### [0243_最短单词距离 🔒](#243)
#### [数组](#243)
#### [字符串](#243)
### [0244_最短单词距离 II 🔒](#244)
#### [设计](#244)
#### [数组](#244)
#### [哈希表](#244)
#### [双指针](#244)
#### [字符串](#244)
### [0245_最短单词距离 III 🔒](#245)
#### [数组](#245)
#### [字符串](#245)
### [0246_中心对称数 🔒](#246)
#### [哈希表](#246)
#### [双指针](#246)
#### [字符串](#246)
### [0247_中心对称数 II 🔒](#247)
#### [递归](#247)
#### [数组](#247)
#### [字符串](#247)
### [0248_中心对称数 III 🔒](#248)
#### [递归](#248)
#### [数组](#248)
#### [字符串](#248)
### [0249_移位字符串分组 🔒](#249)
#### [数组](#249)
#### [哈希表](#249)
#### [字符串](#249)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0240_搜索二维矩阵 II
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 矩阵
---
### 0241_为运算表达式设计优先级
___
#### 递归
___
#### 记忆化搜索
___
#### 数学
___
#### 字符串
___
#### 动态规划
---
### 0242_有效的字母异位词
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0243_最短单词距离 🔒
___
#### 数组
___
#### 字符串
---
### 0244_最短单词距离 II 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 字符串
---
### 0245_最短单词距离 III 🔒
___
#### 数组
___
#### 字符串
---
### 0246_中心对称数 🔒
___
#### 哈希表
___
#### 双指针
___
#### 字符串
---
### 0247_中心对称数 II 🔒
___
#### 递归
___
#### 数组
___
#### 字符串
---
### 0248_中心对称数 III 🔒
___
#### 递归
___
#### 数组
___
#### 字符串
---
### 0249_移位字符串分组 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 分治 | 动态规划 |
| 双指针 | 哈希表 | 字符串 |
| 排序 | 数学 | 数组 |
| 矩阵 | 记忆化搜索 | 设计 |
| 递归 |  |  |

# [240. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii){#240}

{{< tabs "240" >}}

{{% tab "python" %}}
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        i, j = m - 1, 0
        while i >= 0 and j < n:
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	i, j := m-1, 0
	for i >= 0 && j < n {
		if matrix[i][j] == target {
			return true
		}
		if matrix[i][j] > target {
			i--
		} else {
			j++
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function searchMatrix(matrix: number[][], target: number): boolean {
    const [m, n] = [matrix.length, matrix[0].length];
    let [i, j] = [m - 1, 0];
    while (i >= 0 && j < n) {
        if (matrix[i][j] === target) {
            return true;
        }
        if (matrix[i][j] > target) {
            --i;
        } else {
            ++j;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut i = m - 1;
        let mut j = 0;
        while i >= 0 && j < n {
            if matrix[i][j] == target {
                return true;
            }
            if matrix[i][j] > target {
                if i == 0 {
                    break;
                }
                i -= 1;
            } else {
                j += 1;
            }
        }
        false
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
    const n = matrix[0].length;
    for (const row of matrix) {
        const j = _.sortedIndex(row, target);
        if (j < n && row[j] == target) {
            return true;
        }
    }
    return false;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int m = matrix.Length, n = matrix[0].Length;
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个高效的算法来搜索&nbsp;<code><em>m</em>&nbsp;x&nbsp;<em>n</em></code>&nbsp;矩阵 <code>matrix</code> 中的一个目标值 <code>target</code> 。该矩阵具有以下特性：</p>

<ul>
	<li>每行的元素从左到右升序排列。</li>
	<li>每列的元素从上到下升序排列。</li>
</ul>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0240.Search%20a%202D%20Matrix%20II/images/searchgrid2.jpg" />
<pre>
<b>输入：</b>matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
<b>输出：</b>true
</pre>

<p><b>示例 2：</b></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0200-0299/0240.Search%20a%202D%20Matrix%20II/images/searchgrid.jpg" />
<pre>
<b>输入：</b>matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
<b>输出：</b>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 300</code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>每行的所有元素从左到右升序排列</li>
	<li>每列的所有元素从上到下升序排列</li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

由于每一行的所有元素升序排列，因此，对于每一行，我们可以使用二分查找找到第一个大于等于 $\textit{target}$ 的元素，然后判断该元素是否等于 $\textit{target}$。如果等于 $\textit{target}$，说明找到了目标值，直接返回 $\text{true}$。如果不等于 $\textit{target}$，说明这一行的所有元素都小于 $\textit{target}$，应该继续搜索下一行。

如果所有行都搜索完了，都没有找到目标值，说明目标值不存在，返回 $\text{false}$。

时间复杂度 $O(m \times \log n)$，其中 $m$ 和 $n$ 分别为矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for row in matrix:
            j = bisect_left(row, target)
            if j < len(matrix[0]) and row[j] == target:
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for (var row : matrix) {
            int j = Arrays.binarySearch(row, target);
            if (j >= 0) {
                return true;
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix) {
            int j = lower_bound(row.begin(), row.end(), target) - row.begin();
            if (j < matrix[0].size() && row[j] == target) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func searchMatrix(matrix [][]int, target int) bool {
	for _, row := range matrix {
		j := sort.SearchInts(row, target)
		if j < len(matrix[0]) && row[j] == target {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function searchMatrix(matrix: number[][], target: number): boolean {
    const n = matrix[0].length;
    for (const row of matrix) {
        const j = _.sortedIndex(row, target);
        if (j < n && row[j] === target) {
            return true;
        }
    }
    return false;
}
```

#### Rust

```rust
use std::cmp::Ordering;

impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut i = 0;
        let mut j = n;
        while i < m && j > 0 {
            match target.cmp(&matrix[i][j - 1]) {
                Ordering::Less => {
                    j -= 1;
                }
                Ordering::Greater => {
                    i += 1;
                }
                Ordering::Equal => {
                    return true;
                }
            }
        }
        false
    }
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
    const n = matrix[0].length;
    for (const row of matrix) {
        const j = _.sortedIndex(row, target);
        if (j < n && row[j] == target) {
            return true;
        }
    }
    return false;
};
```

#### C#

```cs
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        foreach (int[] row in matrix) {
            int j = Array.BinarySearch(row, target);
            if (j >= 0) {
                return true;
            }
        }
        return false;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：从左下角或右上角搜索

这里我们以左下角或右上角作为起始搜索点，往右上或左下方向开始搜索。比较当前元素 $\textit{matrix}[i][j]$ 与 $\textit{target}$ 的大小关系：

-   若 $\textit{matrix}[i][j] = \textit{target}$，说明找到了目标值，直接返回 $\text{true}$。
-   若 $\textit{matrix}[i][j] > \textit{target}$，说明这一列从当前位置开始往上的所有元素均大于 $\textit{target}$，应该让 $i$ 指针往上移动，即 $i \leftarrow i - 1$。
-   若 $\textit{matrix}[i][j] < \textit{target}$，说明这一行从当前位置开始往右的所有元素均小于 $\textit{target}$，应该让 $j$ 指针往右移动，即 $j \leftarrow j + 1$。

若搜索结束依然找不到 $\textit{target}$，返回 $\text{false}$。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别为矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        i, j = m - 1, 0
        while i >= 0 and j < n:
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False
```

#### Java

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }
};
```

#### Go

```go
func searchMatrix(matrix [][]int, target int) bool {
	m, n := len(matrix), len(matrix[0])
	i, j := m-1, 0
	for i >= 0 && j < n {
		if matrix[i][j] == target {
			return true
		}
		if matrix[i][j] > target {
			i--
		} else {
			j++
		}
	}
	return false
}
```

#### TypeScript

```ts
function searchMatrix(matrix: number[][], target: number): boolean {
    const [m, n] = [matrix.length, matrix[0].length];
    let [i, j] = [m - 1, 0];
    while (i >= 0 && j < n) {
        if (matrix[i][j] === target) {
            return true;
        }
        if (matrix[i][j] > target) {
            --i;
        } else {
            ++j;
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn search_matrix(matrix: Vec<Vec<i32>>, target: i32) -> bool {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut i = m - 1;
        let mut j = 0;
        while i >= 0 && j < n {
            if matrix[i][j] == target {
                return true;
            }
            if matrix[i][j] > target {
                if i == 0 {
                    break;
                }
                i -= 1;
            } else {
                j += 1;
            }
        }
        false
    }
}
```

#### C#

```cs
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int m = matrix.Length, n = matrix[0].Length;
        int i = m - 1, j = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] > target) {
                --i;
            } else {
                ++j;
            }
        }
        return false;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [241. 为运算表达式设计优先级](https://leetcode.cn/problems/different-ways-to-add-parentheses){#241}

{{< tabs "241" >}}

{{% tab "python" %}}
```python
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        @cache
        def dfs(exp):
            if exp.isdigit():
                return [int(exp)]
            ans = []
            for i, c in enumerate(exp):
                if c in '-+*':
                    left, right = dfs(exp[:i]), dfs(exp[i + 1 :])
                    for a in left:
                        for b in right:
                            if c == '-':
                                ans.append(a - b)
                            elif c == '+':
                                ans.append(a + b)
                            else:
                                ans.append(a * b)
            return ans

        return dfs(expression)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static Map<String, List<Integer>> memo = new HashMap<>();

    public List<Integer> diffWaysToCompute(String expression) {
        return dfs(expression);
    }

    private List<Integer> dfs(String exp) {
        if (memo.containsKey(exp)) {
            return memo.get(exp);
        }
        List<Integer> ans = new ArrayList<>();
        if (exp.length() < 3) {
            ans.add(Integer.parseInt(exp));
            return ans;
        }
        for (int i = 0; i < exp.length(); ++i) {
            char c = exp.charAt(i);
            if (c == '-' || c == '+' || c == '*') {
                List<Integer> left = dfs(exp.substring(0, i));
                List<Integer> right = dfs(exp.substring(i + 1));
                for (int a : left) {
                    for (int b : right) {
                        if (c == '-') {
                            ans.add(a - b);
                        } else if (c == '+') {
                            ans.add(a + b);
                        } else {
                            ans.add(a * b);
                        }
                    }
                }
            }
        }
        memo.put(exp, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }

    vector<int> dfs(string exp) {
        if (memo.count(exp)) return memo[exp];
        if (exp.size() < 3) return {stoi(exp)};
        vector<int> ans;
        int n = exp.size();
        for (int i = 0; i < n; ++i) {
            char c = exp[i];
            if (c == '-' || c == '+' || c == '*') {
                vector<int> left = dfs(exp.substr(0, i));
                vector<int> right = dfs(exp.substr(i + 1, n - i - 1));
                for (int& a : left) {
                    for (int& b : right) {
                        if (c == '-')
                            ans.push_back(a - b);
                        else if (c == '+')
                            ans.push_back(a + b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }
        memo[exp] = ans;
        return ans;
    }

private:
    unordered_map<string, vector<int>> memo;
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
var memo = map[string][]int{}

func diffWaysToCompute(expression string) []int {
	return dfs(expression)
}

func dfs(exp string) []int {
	if v, ok := memo[exp]; ok {
		return v
	}
	if len(exp) < 3 {
		v, _ := strconv.Atoi(exp)
		return []int{v}
	}
	ans := []int{}
	for i, c := range exp {
		if c == '-' || c == '+' || c == '*' {
			left, right := dfs(exp[:i]), dfs(exp[i+1:])
			for _, a := range left {
				for _, b := range right {
					if c == '-' {
						ans = append(ans, a-b)
					} else if c == '+' {
						ans = append(ans, a+b)
					} else {
						ans = append(ans, a*b)
					}
				}
			}
		}
	}
	memo[exp] = ans
	return ans
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
using System.Collections.Generic;

public class Solution {
    public IList<int> DiffWaysToCompute(string input) {
        var values = new List<int>();
        var operators = new List<char>();
        var sum = 0;
        foreach (var ch in input)
        {
            if (ch == '+' || ch == '-' || ch == '*')
            {
                values.Add(sum);
                operators.Add(ch);
                sum = 0;
            }
            else
            {
                sum = sum * 10 + ch - '0';
            }
        }
        values.Add(sum);

        var f = new List<int>[values.Count, values.Count];
        for (var i = 0; i < values.Count; ++i)
        {
            f[i, i] = new List<int> { values[i] };
        }

        for (var diff = 1; diff < values.Count; ++diff)
        {
            for (var left = 0; left + diff < values.Count; ++left)
            {
                var right = left + diff;
                f[left, right] = new List<int>();
                for (var i = left; i < right; ++i)
                {
                    foreach (var leftValue in f[left, i])
                    {
                        foreach (var rightValue in f[i + 1, right])
                        {
                            switch (operators[i])
                            {
                                case '+':
                                    f[left, right].Add(leftValue + rightValue);
                                    break;
                                case '-':
                                    f[left, right].Add(leftValue - rightValue);
                                    break;
                                case '*':
                                    f[left, right].Add(leftValue * rightValue);
                                    break;
                            }
                        }
                    }
                }
            }
        }

        return f[0, values.Count - 1];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由数字和运算符组成的字符串&nbsp;<code>expression</code> ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 <strong>按任意顺序</strong> 返回答案。</p>

<p>生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 <code>10<sup>4</sup></code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>expression = "2-1-1"
<strong>输出：</strong>[0,2]
<strong>解释：</strong>
((2-1)-1) = 0 
(2-(1-1)) = 2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>expression = "2*3-4*5"
<strong>输出：</strong>[-34,-14,-10,-10,10]
<strong>解释：</strong>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20</code></li>
	<li><code>expression</code> 由数字和算符 <code>'+'</code>、<code>'-'</code> 和 <code>'*'</code> 组成。</li>
	<li>输入表达式中的所有整数值在范围 <code>[0, 99]</code>&nbsp;</li>
	<li>输入表达式中的所有整数都没有前导&nbsp;<code>'-'</code>&nbsp;或&nbsp;<code>'+'</code> 表示符号。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        @cache
        def dfs(exp):
            if exp.isdigit():
                return [int(exp)]
            ans = []
            for i, c in enumerate(exp):
                if c in '-+*':
                    left, right = dfs(exp[:i]), dfs(exp[i + 1 :])
                    for a in left:
                        for b in right:
                            if c == '-':
                                ans.append(a - b)
                            elif c == '+':
                                ans.append(a + b)
                            else:
                                ans.append(a * b)
            return ans

        return dfs(expression)
```

#### Java

```java
class Solution {
    private static Map<String, List<Integer>> memo = new HashMap<>();

    public List<Integer> diffWaysToCompute(String expression) {
        return dfs(expression);
    }

    private List<Integer> dfs(String exp) {
        if (memo.containsKey(exp)) {
            return memo.get(exp);
        }
        List<Integer> ans = new ArrayList<>();
        if (exp.length() < 3) {
            ans.add(Integer.parseInt(exp));
            return ans;
        }
        for (int i = 0; i < exp.length(); ++i) {
            char c = exp.charAt(i);
            if (c == '-' || c == '+' || c == '*') {
                List<Integer> left = dfs(exp.substring(0, i));
                List<Integer> right = dfs(exp.substring(i + 1));
                for (int a : left) {
                    for (int b : right) {
                        if (c == '-') {
                            ans.add(a - b);
                        } else if (c == '+') {
                            ans.add(a + b);
                        } else {
                            ans.add(a * b);
                        }
                    }
                }
            }
        }
        memo.put(exp, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression);
    }

    vector<int> dfs(string exp) {
        if (memo.count(exp)) return memo[exp];
        if (exp.size() < 3) return {stoi(exp)};
        vector<int> ans;
        int n = exp.size();
        for (int i = 0; i < n; ++i) {
            char c = exp[i];
            if (c == '-' || c == '+' || c == '*') {
                vector<int> left = dfs(exp.substr(0, i));
                vector<int> right = dfs(exp.substr(i + 1, n - i - 1));
                for (int& a : left) {
                    for (int& b : right) {
                        if (c == '-')
                            ans.push_back(a - b);
                        else if (c == '+')
                            ans.push_back(a + b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }
        memo[exp] = ans;
        return ans;
    }

private:
    unordered_map<string, vector<int>> memo;
};
```

#### Go

```go
var memo = map[string][]int{}

func diffWaysToCompute(expression string) []int {
	return dfs(expression)
}

func dfs(exp string) []int {
	if v, ok := memo[exp]; ok {
		return v
	}
	if len(exp) < 3 {
		v, _ := strconv.Atoi(exp)
		return []int{v}
	}
	ans := []int{}
	for i, c := range exp {
		if c == '-' || c == '+' || c == '*' {
			left, right := dfs(exp[:i]), dfs(exp[i+1:])
			for _, a := range left {
				for _, b := range right {
					if c == '-' {
						ans = append(ans, a-b)
					} else if c == '+' {
						ans = append(ans, a+b)
					} else {
						ans = append(ans, a*b)
					}
				}
			}
		}
	}
	memo[exp] = ans
	return ans
}
```

#### C#

```cs
using System.Collections.Generic;

public class Solution {
    public IList<int> DiffWaysToCompute(string input) {
        var values = new List<int>();
        var operators = new List<char>();
        var sum = 0;
        foreach (var ch in input)
        {
            if (ch == '+' || ch == '-' || ch == '*')
            {
                values.Add(sum);
                operators.Add(ch);
                sum = 0;
            }
            else
            {
                sum = sum * 10 + ch - '0';
            }
        }
        values.Add(sum);

        var f = new List<int>[values.Count, values.Count];
        for (var i = 0; i < values.Count; ++i)
        {
            f[i, i] = new List<int> { values[i] };
        }

        for (var diff = 1; diff < values.Count; ++diff)
        {
            for (var left = 0; left + diff < values.Count; ++left)
            {
                var right = left + diff;
                f[left, right] = new List<int>();
                for (var i = left; i < right; ++i)
                {
                    foreach (var leftValue in f[left, i])
                    {
                        foreach (var rightValue in f[i + 1, right])
                        {
                            switch (operators[i])
                            {
                                case '+':
                                    f[left, right].Add(leftValue + rightValue);
                                    break;
                                case '-':
                                    f[left, right].Add(leftValue - rightValue);
                                    break;
                                case '*':
                                    f[left, right].Add(leftValue * rightValue);
                                    break;
                            }
                        }
                    }
                }
            }
        }

        return f[0, values.Count - 1];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram){#242}

{{< tabs "242" >}}

{{% tab "python" %}}
```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
            --cnt[t.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) {
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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        return all_of(cnt.begin(), cnt.end(), [](int x) { return x == 0; });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	cnt := [26]int{}
	for i := 0; i < len(s); i++ {
		cnt[s[i]-'a']++
		cnt[t[i]-'a']--
	}
	for _, v := range cnt {
		if v != 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isAnagram(s: string, t: string): boolean {
    if (s.length !== t.length) {
        return false;
    }
    const cnt = new Array(26).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ++cnt[s.charCodeAt(i) - 'a'.charCodeAt(0)];
        --cnt[t.charCodeAt(i) - 'a'.charCodeAt(0)];
    }
    return cnt.every(x => x === 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let n = s.len();
        let m = t.len();
        if n != m {
            return false;
        }
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let mut count = [0; 26];
        for i in 0..n {
            count[(s[i] - b'a') as usize] += 1;
            count[(t[i] - b'a') as usize] -= 1;
        }
        count.iter().all(|&c| c == 0)
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) {
        return false;
    }
    const cnt = new Array(26).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ++cnt[s.charCodeAt(i) - 'a'.charCodeAt(0)];
        --cnt[t.charCodeAt(i) - 'a'.charCodeAt(0)];
    }
    return cnt.every(x => x === 0);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsAnagram(string s, string t) {
        if (s.Length != t.Length) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.Length; ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        return cnt.All(x => x == 0);
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool isAnagram(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    if (n != m) {
        return 0;
    }
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i]) {
            return 0;
        }
    }
    return 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串 <code>s</code> 和 <code>t</code> ，编写一个函数来判断 <code>t</code> 是否是 <code>s</code> 的 <span data-keyword="anagram">字母异位词</span>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> s = "anagram", t = "nagaram"
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "rat", t = "car"
<strong>输出: </strong>false</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 和 <code>t</code>&nbsp;仅包含小写字母</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶:&nbsp;</strong>如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们先判断两个字符串的长度是否相等，如果不相等，说明两个字符串中的字符肯定不同，返回 `false`。

否则，我们用哈希表或者一个长度为 $26$ 的数组来记录字符串 $s$ 中每个字符出现的次数，然后遍历另一个字符串 $t$，每遍历到一个字符，就将哈希表中对应的字符次数减一，如果减一后的次数小于 $0$，说明该字符在两个字符串中出现的次数不同，返回 `false`。如果遍历完两个字符串后，哈希表中的所有字符次数都为 $0$，说明两个字符串中的字符出现次数相同，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(C)$，其中 $n$ 是字符串的长度；而 $C$ 是字符集的大小，本题中 $C=26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        cnt = Counter(s)
        for c in t:
            cnt[c] -= 1
            if cnt[c] < 0:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
            --cnt[t.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) {
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
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        return all_of(cnt.begin(), cnt.end(), [](int x) { return x == 0; });
    }
};
```

#### Go

```go
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	cnt := [26]int{}
	for i := 0; i < len(s); i++ {
		cnt[s[i]-'a']++
		cnt[t[i]-'a']--
	}
	for _, v := range cnt {
		if v != 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isAnagram(s: string, t: string): boolean {
    if (s.length !== t.length) {
        return false;
    }
    const cnt = new Array(26).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ++cnt[s.charCodeAt(i) - 'a'.charCodeAt(0)];
        --cnt[t.charCodeAt(i) - 'a'.charCodeAt(0)];
    }
    return cnt.every(x => x === 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let n = s.len();
        let m = t.len();
        if n != m {
            return false;
        }
        let mut s = s.chars().collect::<Vec<char>>();
        let mut t = t.chars().collect::<Vec<char>>();
        s.sort();
        t.sort();
        for i in 0..n {
            if s[i] != t[i] {
                return false;
            }
        }
        true
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
    if (s.length !== t.length) {
        return false;
    }
    const cnt = new Array(26).fill(0);
    for (let i = 0; i < s.length; ++i) {
        ++cnt[s.charCodeAt(i) - 'a'.charCodeAt(0)];
        --cnt[t.charCodeAt(i) - 'a'.charCodeAt(0)];
    }
    return cnt.every(x => x === 0);
};
```

#### C#

```cs
public class Solution {
    public bool IsAnagram(string s, string t) {
        if (s.Length != t.Length) {
            return false;
        }
        int[] cnt = new int[26];
        for (int i = 0; i < s.Length; ++i) {
            ++cnt[s[i] - 'a'];
            --cnt[t[i] - 'a'];
        }
        return cnt.All(x => x == 0);
    }
}
```

#### C

```c
int cmp(const void* a, const void* b) {
    return *(char*) a - *(char*) b;
}

bool isAnagram(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    if (n != m) {
        return 0;
    }
    qsort(s, n, sizeof(char), cmp);
    qsort(t, n, sizeof(char), cmp);
    return !strcmp(s, t);
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
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
```

#### Rust

```rust
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let n = s.len();
        let m = t.len();
        if n != m {
            return false;
        }
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let mut count = [0; 26];
        for i in 0..n {
            count[(s[i] - b'a') as usize] += 1;
            count[(t[i] - b'a') as usize] -= 1;
        }
        count.iter().all(|&c| c == 0)
    }
}
```

#### C

```c
bool isAnagram(char* s, char* t) {
    int n = strlen(s);
    int m = strlen(t);
    if (n != m) {
        return 0;
    }
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i]) {
            return 0;
        }
    }
    return 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [243. 最短单词距离 🔒](https://leetcode.cn/problems/shortest-word-distance){#243}

{{< tabs "243" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        i = j = -1
        ans = inf
        for k, w in enumerate(wordsDict):
            if w == word1:
                i = k
            if w == word2:
                j = k
            if i != -1 and j != -1:
                ans = min(ans, abs(i - j))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestDistance(String[] wordsDict, String word1, String word2) {
        int ans = 0x3f3f3f3f;
        for (int k = 0, i = -1, j = -1; k < wordsDict.length; ++k) {
            if (wordsDict[k].equals(word1)) {
                i = k;
            }
            if (wordsDict[k].equals(word2)) {
                j = k;
            }
            if (i != -1 && j != -1) {
                ans = Math.min(ans, Math.abs(i - j));
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
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        for (int k = 0, i = -1, j = -1; k < wordsDict.size(); ++k) {
            if (wordsDict[k] == word1) {
                i = k;
            }
            if (wordsDict[k] == word2) {
                j = k;
            }
            if (i != -1 && j != -1) {
                ans = min(ans, abs(i - j));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestDistance(wordsDict []string, word1 string, word2 string) int {
	ans := 0x3f3f3f3f
	i, j := -1, -1
	for k, w := range wordsDict {
		if w == word1 {
			i = k
		}
		if w == word2 {
			j = k
		}
		if i != -1 && j != -1 {
			ans = min(ans, abs(i-j))
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串数组&nbsp;<code>wordDict</code>&nbsp;和两个已经存在于该数组中的不同的字符串&nbsp;<code>word1</code> 和 <code>word2</code> 。返回列表中这两个单词之间的最短距离。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "coding", word2 = "practice"
<strong>输出:</strong> 3
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
<strong>输出:</strong> 1</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= wordsDict.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= wordsDict[i].length &lt;= 10</code></li>
	<li><code>wordsDict[i]</code>&nbsp;由小写英文字母组成</li>
	<li><code>word1</code>&nbsp;和&nbsp;<code>word2</code>&nbsp;在&nbsp;<code>wordsDict</code> 中</li>
	<li><code>word1 != word2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

遍历数组 `wordsDict`，找到 `word1` 和 `word2` 的下标 $i$ 和 $j$，求 $i-j$ 的最小值。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 `wordsDict` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        i = j = -1
        ans = inf
        for k, w in enumerate(wordsDict):
            if w == word1:
                i = k
            if w == word2:
                j = k
            if i != -1 and j != -1:
                ans = min(ans, abs(i - j))
        return ans
```

#### Java

```java
class Solution {
    public int shortestDistance(String[] wordsDict, String word1, String word2) {
        int ans = 0x3f3f3f3f;
        for (int k = 0, i = -1, j = -1; k < wordsDict.length; ++k) {
            if (wordsDict[k].equals(word1)) {
                i = k;
            }
            if (wordsDict[k].equals(word2)) {
                j = k;
            }
            if (i != -1 && j != -1) {
                ans = Math.min(ans, Math.abs(i - j));
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
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        for (int k = 0, i = -1, j = -1; k < wordsDict.size(); ++k) {
            if (wordsDict[k] == word1) {
                i = k;
            }
            if (wordsDict[k] == word2) {
                j = k;
            }
            if (i != -1 && j != -1) {
                ans = min(ans, abs(i - j));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shortestDistance(wordsDict []string, word1 string, word2 string) int {
	ans := 0x3f3f3f3f
	i, j := -1, -1
	for k, w := range wordsDict {
		if w == word1 {
			i = k
		}
		if w == word2 {
			j = k
		}
		if i != -1 && j != -1 {
			ans = min(ans, abs(i-j))
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [244. 最短单词距离 II 🔒](https://leetcode.cn/problems/shortest-word-distance-ii){#244}

{{< tabs "244" >}}

{{% tab "python" %}}
```python
class WordDistance:
    def __init__(self, wordsDict: List[str]):
        self.d = defaultdict(list)
        for i, w in enumerate(wordsDict):
            self.d[w].append(i)

    def shortest(self, word1: str, word2: str) -> int:
        a, b = self.d[word1], self.d[word2]
        ans = inf
        i = j = 0
        while i < len(a) and j < len(b):
            ans = min(ans, abs(a[i] - b[j]))
            if a[i] <= b[j]:
                i += 1
            else:
                j += 1
        return ans


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(wordsDict)
# param_1 = obj.shortest(word1,word2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class WordDistance {
    private Map<String, List<Integer>> d = new HashMap<>();

    public WordDistance(String[] wordsDict) {
        for (int i = 0; i < wordsDict.length; ++i) {
            d.computeIfAbsent(wordsDict[i], k -> new ArrayList<>()).add(i);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> a = d.get(word1), b = d.get(word2);
        int ans = 0x3f3f3f3f;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            ans = Math.min(ans, Math.abs(a.get(i) - b.get(j)));
            if (a.get(i) <= b.get(j)) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(wordsDict);
 * int param_1 = obj.shortest(word1,word2);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            d[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto a = d[word1], b = d[word2];
        int i = 0, j = 0;
        int ans = INT_MAX;
        while (i < a.size() && j < b.size()) {
            ans = min(ans, abs(a[i] - b[j]));
            if (a[i] <= b[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }

private:
    unordered_map<string, vector<int>> d;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type WordDistance struct {
	d map[string][]int
}

func Constructor(wordsDict []string) WordDistance {
	d := map[string][]int{}
	for i, w := range wordsDict {
		d[w] = append(d[w], i)
	}
	return WordDistance{d}
}

func (this *WordDistance) Shortest(word1 string, word2 string) int {
	a, b := this.d[word1], this.d[word2]
	ans := 0x3f3f3f3f
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		ans = min(ans, abs(a[i]-b[j]))
		if a[i] <= b[j] {
			i++
		} else {
			j++
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * obj := Constructor(wordsDict);
 * param_1 := obj.Shortest(word1,word2);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请设计一个类，使该类的构造函数能够接收一个字符串数组。然后再实现一个方法，该方法能够分别接收两个单词<em>，</em>并返回列表中这两个单词之间的最短距离。</p>

<p>实现&nbsp;<code>WordDistanc</code>&nbsp;类:</p>

<ul>
	<li><code>WordDistance(String[] wordsDict)</code>&nbsp;用字符串数组 <code>wordsDict</code> 初始化对象。</li>
	<li><code>int shortest(String word1, String word2)</code>&nbsp;返回数组 <code>worddict</code> 中 <code>word1</code> 和 <code>word2</code> 之间的最短距离。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
<strong>输出:</strong>
[null, 3, 1]

<b>解释：</b>
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // 返回 3
wordDistance.shortest("makes", "coding");    // 返回 1</pre>

<p>&nbsp;</p>

<p><strong>注意:</strong><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= wordsDict.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= wordsDict[i].length &lt;= 10</code></li>
	<li><code>wordsDict[i]</code>&nbsp;由小写英文字母组成</li>
	<li><code>word1</code>&nbsp;和&nbsp;<code>word2</code>&nbsp;在数组&nbsp;<code>wordsDict</code>&nbsp;中</li>
	<li><code>word1 != word2</code></li>
	<li>&nbsp;<code>shortest</code>&nbsp;操作次数不大于&nbsp;<code>5000</code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双指针

我们用哈希表 $d$ 存储每个单词在数组中出现的所有下标，然后用双指针 $i$ 和 $j$ 分别指向两个单词在数组中出现的下标列表 $a$ 和 $b$，每次更新下标差值的最小值，然后移动下标较小的指针，直到其中一个指针遍历完下标列表。

初始化的时间复杂度为 $O(n)$，其中 $n$ 为数组的长度。每次调用 `shortest` 方法的时间复杂度为 $O(m + n)$，其中 $m$ 为两个单词在数组中出现的下标列表的长度之和。

<!-- tabs:start -->

#### Python3

```python
class WordDistance:
    def __init__(self, wordsDict: List[str]):
        self.d = defaultdict(list)
        for i, w in enumerate(wordsDict):
            self.d[w].append(i)

    def shortest(self, word1: str, word2: str) -> int:
        a, b = self.d[word1], self.d[word2]
        ans = inf
        i = j = 0
        while i < len(a) and j < len(b):
            ans = min(ans, abs(a[i] - b[j]))
            if a[i] <= b[j]:
                i += 1
            else:
                j += 1
        return ans


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(wordsDict)
# param_1 = obj.shortest(word1,word2)
```

#### Java

```java
class WordDistance {
    private Map<String, List<Integer>> d = new HashMap<>();

    public WordDistance(String[] wordsDict) {
        for (int i = 0; i < wordsDict.length; ++i) {
            d.computeIfAbsent(wordsDict[i], k -> new ArrayList<>()).add(i);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> a = d.get(word1), b = d.get(word2);
        int ans = 0x3f3f3f3f;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            ans = Math.min(ans, Math.abs(a.get(i) - b.get(j)));
            if (a.get(i) <= b.get(j)) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(wordsDict);
 * int param_1 = obj.shortest(word1,word2);
 */
```

#### C++

```cpp
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            d[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto a = d[word1], b = d[word2];
        int i = 0, j = 0;
        int ans = INT_MAX;
        while (i < a.size() && j < b.size()) {
            ans = min(ans, abs(a[i] - b[j]));
            if (a[i] <= b[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }

private:
    unordered_map<string, vector<int>> d;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
```

#### Go

```go
type WordDistance struct {
	d map[string][]int
}

func Constructor(wordsDict []string) WordDistance {
	d := map[string][]int{}
	for i, w := range wordsDict {
		d[w] = append(d[w], i)
	}
	return WordDistance{d}
}

func (this *WordDistance) Shortest(word1 string, word2 string) int {
	a, b := this.d[word1], this.d[word2]
	ans := 0x3f3f3f3f
	i, j := 0, 0
	for i < len(a) && j < len(b) {
		ans = min(ans, abs(a[i]-b[j]))
		if a[i] <= b[j] {
			i++
		} else {
			j++
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * obj := Constructor(wordsDict);
 * param_1 := obj.Shortest(word1,word2);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [245. 最短单词距离 III 🔒](https://leetcode.cn/problems/shortest-word-distance-iii){#245}

{{< tabs "245" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans = len(wordsDict)
        if word1 == word2:
            j = -1
            for i, w in enumerate(wordsDict):
                if w == word1:
                    if j != -1:
                        ans = min(ans, i - j)
                    j = i
        else:
            i = j = -1
            for k, w in enumerate(wordsDict):
                if w == word1:
                    i = k
                if w == word2:
                    j = k
                if i != -1 and j != -1:
                    ans = min(ans, abs(i - j))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        int ans = wordsDict.length;
        if (word1.equals(word2)) {
            for (int i = 0, j = -1; i < wordsDict.length; ++i) {
                if (wordsDict[i].equals(word1)) {
                    if (j != -1) {
                        ans = Math.min(ans, i - j);
                    }
                    j = i;
                }
            }
        } else {
            for (int k = 0, i = -1, j = -1; k < wordsDict.length; ++k) {
                if (wordsDict[k].equals(word1)) {
                    i = k;
                }
                if (wordsDict[k].equals(word2)) {
                    j = k;
                }
                if (i != -1 && j != -1) {
                    ans = Math.min(ans, Math.abs(i - j));
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
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int ans = n;
        if (word1 == word2) {
            for (int i = 0, j = -1; i < n; ++i) {
                if (wordsDict[i] == word1) {
                    if (j != -1) {
                        ans = min(ans, i - j);
                    }
                    j = i;
                }
            }
        } else {
            for (int k = 0, i = -1, j = -1; k < n; ++k) {
                if (wordsDict[k] == word1) {
                    i = k;
                }
                if (wordsDict[k] == word2) {
                    j = k;
                }
                if (i != -1 && j != -1) {
                    ans = min(ans, abs(i - j));
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
func shortestWordDistance(wordsDict []string, word1 string, word2 string) int {
	ans := len(wordsDict)
	if word1 == word2 {
		j := -1
		for i, w := range wordsDict {
			if w == word1 {
				if j != -1 {
					ans = min(ans, i-j)
				}
				j = i
			}
		}
	} else {
		i, j := -1, -1
		for k, w := range wordsDict {
			if w == word1 {
				i = k
			}
			if w == word2 {
				j = k
			}
			if i != -1 && j != -1 {
				ans = min(ans, abs(i-j))
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestWordDistance(wordsDict: string[], word1: string, word2: string): number {
    let ans = wordsDict.length;
    if (word1 === word2) {
        let j = -1;
        for (let i = 0; i < wordsDict.length; i++) {
            if (wordsDict[i] === word1) {
                if (j !== -1) {
                    ans = Math.min(ans, i - j);
                }
                j = i;
            }
        }
    } else {
        let i = -1,
            j = -1;
        for (let k = 0; k < wordsDict.length; k++) {
            if (wordsDict[k] === word1) {
                i = k;
            }
            if (wordsDict[k] === word2) {
                j = k;
            }
            if (i !== -1 && j !== -1) {
                ans = Math.min(ans, Math.abs(i - j));
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

<p>给定一个字符串数组&nbsp;<code>wordsDict</code> 和两个字符串 <code>word1</code> 和 <code>word2</code> ，返回这两个单词在列表中出现的最短距离。</p>

<p>注意：<code>word1</code> 和 <code>word2</code>&nbsp;是有可能相同的，并且它们将分别表示为列表中 <strong>两个独立的单词</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
<strong>输出：</strong>1
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= wordsDict.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= wordsDict[i].length &lt;= 10</code></li>
	<li><code>wordsDict[i]</code> 由小写英文字母组成</li>
	<li><code>word1</code> 和 <code>word2</code> 都在 <code>wordsDict</code> 中</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

我们首先判断 $\textit{word1}$ 和 $\textit{word2}$ 是否相等：

-   如果相等，遍历数组 $\textit{wordsDict}$，找到两个 $\textit{word1}$ 的下标 $i$ 和 $j$，求 $i-j$ 的最小值。
-   如果不相等，遍历数组 $\textit{wordsDict}$，找到 $\textit{word1}$ 和 $\textit{word2}$ 的下标 $i$ 和 $j$，求 $i-j$ 的最小值。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{wordsDict}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestWordDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        ans = len(wordsDict)
        if word1 == word2:
            j = -1
            for i, w in enumerate(wordsDict):
                if w == word1:
                    if j != -1:
                        ans = min(ans, i - j)
                    j = i
        else:
            i = j = -1
            for k, w in enumerate(wordsDict):
                if w == word1:
                    i = k
                if w == word2:
                    j = k
                if i != -1 and j != -1:
                    ans = min(ans, abs(i - j))
        return ans
```

#### Java

```java
class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        int ans = wordsDict.length;
        if (word1.equals(word2)) {
            for (int i = 0, j = -1; i < wordsDict.length; ++i) {
                if (wordsDict[i].equals(word1)) {
                    if (j != -1) {
                        ans = Math.min(ans, i - j);
                    }
                    j = i;
                }
            }
        } else {
            for (int k = 0, i = -1, j = -1; k < wordsDict.length; ++k) {
                if (wordsDict[k].equals(word1)) {
                    i = k;
                }
                if (wordsDict[k].equals(word2)) {
                    j = k;
                }
                if (i != -1 && j != -1) {
                    ans = Math.min(ans, Math.abs(i - j));
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
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int ans = n;
        if (word1 == word2) {
            for (int i = 0, j = -1; i < n; ++i) {
                if (wordsDict[i] == word1) {
                    if (j != -1) {
                        ans = min(ans, i - j);
                    }
                    j = i;
                }
            }
        } else {
            for (int k = 0, i = -1, j = -1; k < n; ++k) {
                if (wordsDict[k] == word1) {
                    i = k;
                }
                if (wordsDict[k] == word2) {
                    j = k;
                }
                if (i != -1 && j != -1) {
                    ans = min(ans, abs(i - j));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func shortestWordDistance(wordsDict []string, word1 string, word2 string) int {
	ans := len(wordsDict)
	if word1 == word2 {
		j := -1
		for i, w := range wordsDict {
			if w == word1 {
				if j != -1 {
					ans = min(ans, i-j)
				}
				j = i
			}
		}
	} else {
		i, j := -1, -1
		for k, w := range wordsDict {
			if w == word1 {
				i = k
			}
			if w == word2 {
				j = k
			}
			if i != -1 && j != -1 {
				ans = min(ans, abs(i-j))
			}
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function shortestWordDistance(wordsDict: string[], word1: string, word2: string): number {
    let ans = wordsDict.length;
    if (word1 === word2) {
        let j = -1;
        for (let i = 0; i < wordsDict.length; i++) {
            if (wordsDict[i] === word1) {
                if (j !== -1) {
                    ans = Math.min(ans, i - j);
                }
                j = i;
            }
        }
    } else {
        let i = -1,
            j = -1;
        for (let k = 0; k < wordsDict.length; k++) {
            if (wordsDict[k] === word1) {
                i = k;
            }
            if (wordsDict[k] === word2) {
                j = k;
            }
            if (i !== -1 && j !== -1) {
                ans = Math.min(ans, Math.abs(i - j));
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

# [246. 中心对称数 🔒](https://leetcode.cn/problems/strobogrammatic-number){#246}

{{< tabs "246" >}}

{{% tab "python" %}}
```python
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6]
        i, j = 0, len(num) - 1
        while i <= j:
            a, b = int(num[i]), int(num[j])
            if d[a] != b:
                return False
            i, j = i + 1, j - 1
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isStrobogrammatic(String num) {
        int[] d = new int[] {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        for (int i = 0, j = num.length() - 1; i <= j; ++i, --j) {
            int a = num.charAt(i) - '0', b = num.charAt(j) - '0';
            if (d[a] != b) {
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
    bool isStrobogrammatic(string num) {
        vector<int> d = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        for (int i = 0, j = num.size() - 1; i <= j; ++i, --j) {
            int a = num[i] - '0', b = num[j] - '0';
            if (d[a] != b) {
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
func isStrobogrammatic(num string) bool {
	d := []int{0, 1, -1, -1, -1, -1, 9, -1, 8, 6}
	for i, j := 0, len(num)-1; i <= j; i, j = i+1, j-1 {
		a, b := int(num[i]-'0'), int(num[j]-'0')
		if d[a] != b {
			return false
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>中心对称数是指一个数字在旋转了&nbsp;180 度之后看起来依旧相同的数字（或者上下颠倒地看）。</p>

<p>请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> num = &quot;69&quot;
<strong>输出:</strong> true
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> num = &quot;88&quot;
<strong>输出:</strong> true</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入:</strong> num = &quot;962&quot;
<strong>输出:</strong> false</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>num = &quot;1&quot;
<strong>输出：</strong>true
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针模拟

我们定义一个数组 $d$，其中 $d[i]$ 表示数字 $i$ 旋转 180° 之后的数字。如果 $d[i]$ 为 $-1$，表示数字 $i$ 不能旋转 180° 得到一个数字。

定义两个指针 $i$ 和 $j$，分别指向字符串的左右两端，然后不断向中间移动指针，判断 $d[num[i]]$ 和 $num[j]$ 是否相等，如果不相等，说明该字符串不是中心对称数，直接返回 $false$ 即可。如果 $i \gt j$，说明遍历完了字符串，返回 $true$。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        d = [0, 1, -1, -1, -1, -1, 9, -1, 8, 6]
        i, j = 0, len(num) - 1
        while i <= j:
            a, b = int(num[i]), int(num[j])
            if d[a] != b:
                return False
            i, j = i + 1, j - 1
        return True
```

#### Java

```java
class Solution {
    public boolean isStrobogrammatic(String num) {
        int[] d = new int[] {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        for (int i = 0, j = num.length() - 1; i <= j; ++i, --j) {
            int a = num.charAt(i) - '0', b = num.charAt(j) - '0';
            if (d[a] != b) {
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
    bool isStrobogrammatic(string num) {
        vector<int> d = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        for (int i = 0, j = num.size() - 1; i <= j; ++i, --j) {
            int a = num[i] - '0', b = num[j] - '0';
            if (d[a] != b) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isStrobogrammatic(num string) bool {
	d := []int{0, 1, -1, -1, -1, -1, 9, -1, 8, 6}
	for i, j := 0, len(num)-1; i <= j; i, j = i+1, j-1 {
		a, b := int(num[i]-'0'), int(num[j]-'0')
		if d[a] != b {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [247. 中心对称数 II 🔒](https://leetcode.cn/problems/strobogrammatic-number-ii){#247}

{{< tabs "247" >}}

{{% tab "python" %}}
```python
class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        def dfs(u):
            if u == 0:
                return ['']
            if u == 1:
                return ['0', '1', '8']
            ans = []
            for v in dfs(u - 2):
                for l, r in ('11', '88', '69', '96'):
                    ans.append(l + v + r)
                if u != n:
                    ans.append('0' + v + '0')
            return ans

        return dfs(n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int[][] PAIRS = {{1, 1}, {8, 8}, {6, 9}, {9, 6}};
    private int n;

    public List<String> findStrobogrammatic(int n) {
        this.n = n;
        return dfs(n);
    }

    private List<String> dfs(int u) {
        if (u == 0) {
            return Collections.singletonList("");
        }
        if (u == 1) {
            return Arrays.asList("0", "1", "8");
        }
        List<String> ans = new ArrayList<>();
        for (String v : dfs(u - 2)) {
            for (var p : PAIRS) {
                ans.add(p[0] + v + p[1]);
            }
            if (u != n) {
                ans.add(0 + v + 0);
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
    const vector<pair<char, char>> pairs = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

    vector<string> findStrobogrammatic(int n) {
        function<vector<string>(int)> dfs = [&](int u) {
            if (u == 0) return vector<string>{""};
            if (u == 1) return vector<string>{"0", "1", "8"};
            vector<string> ans;
            for (auto& v : dfs(u - 2)) {
                for (auto& [l, r] : pairs) ans.push_back(l + v + r);
                if (u != n) ans.push_back('0' + v + '0');
            }
            return ans;
        };
        return dfs(n);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findStrobogrammatic(n int) []string {
	var dfs func(int) []string
	dfs = func(u int) []string {
		if u == 0 {
			return []string{""}
		}
		if u == 1 {
			return []string{"0", "1", "8"}
		}
		var ans []string
		pairs := [][]string{{"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}}
		for _, v := range dfs(u - 2) {
			for _, p := range pairs {
				ans = append(ans, p[0]+v+p[1])
			}
			if u != n {
				ans = append(ans, "0"+v+"0")
			}
		}
		return ans
	}
	return dfs(n)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数&nbsp;<code>n</code>&nbsp;，返回所有长度为&nbsp;<code>n</code>&nbsp;的 <strong>中心对称数</strong>&nbsp;。你可以以 <strong>任何顺序</strong> 返回答案。</p>

<p><strong>中心对称数&nbsp;</strong>是一个数字在旋转了&nbsp;<code>180</code> 度之后看起来依旧相同的数字（或者上下颠倒地看）。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入：</b>n = 2
<b>输出：</b>["11","69","88","96"]
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<b>输入：</b>n = 1
<b>输出：</b>["0","1","8"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 14</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

若长度为 $1$，则中心对称数只有 $0, 1, 8$；若长度为 $2$，则中心对称数只有 $11, 69, 88, 96$。

我们设计递归函数 $dfs(u)$，其返回长度为 $u$ 的中心对称数。答案为 $dfs(n)$。

若 $u$ 为 $0$，返回包含一个空串的列表，即 `[""]`；若 $u$ 为 $1$，返回列表 `["0", "1", "8"]`。

若 $u$ 大于 $1$，我们对长度为 $u - 2$ 的所有中心对称数进行遍历，对于每个中心对称数 $v$，在其左右两侧分别添加 $1, 8, 6, 9$，即可得到长度为 `u` 的中心对称数。

注意，如果 $u\neq n$，我们还可以在中心对称数的左右两侧分别添加 $0$。

最终，我们将所有长度为 $n$ 的中心对称数返回即可。

时间复杂度为 $O(2^{n+2})$。

相似题目：

-   [248. 中心对称数 III 🔒](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0248.Strobogrammatic%20Number%20III/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findStrobogrammatic(self, n: int) -> List[str]:
        def dfs(u):
            if u == 0:
                return ['']
            if u == 1:
                return ['0', '1', '8']
            ans = []
            for v in dfs(u - 2):
                for l, r in ('11', '88', '69', '96'):
                    ans.append(l + v + r)
                if u != n:
                    ans.append('0' + v + '0')
            return ans

        return dfs(n)
```

#### Java

```java
class Solution {
    private static final int[][] PAIRS = {{1, 1}, {8, 8}, {6, 9}, {9, 6}};
    private int n;

    public List<String> findStrobogrammatic(int n) {
        this.n = n;
        return dfs(n);
    }

    private List<String> dfs(int u) {
        if (u == 0) {
            return Collections.singletonList("");
        }
        if (u == 1) {
            return Arrays.asList("0", "1", "8");
        }
        List<String> ans = new ArrayList<>();
        for (String v : dfs(u - 2)) {
            for (var p : PAIRS) {
                ans.add(p[0] + v + p[1]);
            }
            if (u != n) {
                ans.add(0 + v + 0);
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
    const vector<pair<char, char>> pairs = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

    vector<string> findStrobogrammatic(int n) {
        function<vector<string>(int)> dfs = [&](int u) {
            if (u == 0) return vector<string>{""};
            if (u == 1) return vector<string>{"0", "1", "8"};
            vector<string> ans;
            for (auto& v : dfs(u - 2)) {
                for (auto& [l, r] : pairs) ans.push_back(l + v + r);
                if (u != n) ans.push_back('0' + v + '0');
            }
            return ans;
        };
        return dfs(n);
    }
};
```

#### Go

```go
func findStrobogrammatic(n int) []string {
	var dfs func(int) []string
	dfs = func(u int) []string {
		if u == 0 {
			return []string{""}
		}
		if u == 1 {
			return []string{"0", "1", "8"}
		}
		var ans []string
		pairs := [][]string{{"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}}
		for _, v := range dfs(u - 2) {
			for _, p := range pairs {
				ans = append(ans, p[0]+v+p[1])
			}
			if u != n {
				ans = append(ans, "0"+v+"0")
			}
		}
		return ans
	}
	return dfs(n)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [248. 中心对称数 III 🔒](https://leetcode.cn/problems/strobogrammatic-number-iii){#248}

{{< tabs "248" >}}

{{% tab "python" %}}
```python
class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        def dfs(u):
            if u == 0:
                return ['']
            if u == 1:
                return ['0', '1', '8']
            ans = []
            for v in dfs(u - 2):
                for l, r in ('11', '88', '69', '96'):
                    ans.append(l + v + r)
                if u != n:
                    ans.append('0' + v + '0')
            return ans

        a, b = len(low), len(high)
        low, high = int(low), int(high)
        ans = 0
        for n in range(a, b + 1):
            for s in dfs(n):
                if low <= int(s) <= high:
                    ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int[][] PAIRS = {{1, 1}, {8, 8}, {6, 9}, {9, 6}};
    private int n;

    public int strobogrammaticInRange(String low, String high) {
        int a = low.length(), b = high.length();
        long l = Long.parseLong(low), r = Long.parseLong(high);
        int ans = 0;
        for (n = a; n <= b; ++n) {
            for (String s : dfs(n)) {
                long v = Long.parseLong(s);
                if (l <= v && v <= r) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private List<String> dfs(int u) {
        if (u == 0) {
            return Collections.singletonList("");
        }
        if (u == 1) {
            return Arrays.asList("0", "1", "8");
        }
        List<String> ans = new ArrayList<>();
        for (String v : dfs(u - 2)) {
            for (var p : PAIRS) {
                ans.add(p[0] + v + p[1]);
            }
            if (u != n) {
                ans.add(0 + v + 0);
            }
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
    const vector<pair<char, char>> pairs = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

    int strobogrammaticInRange(string low, string high) {
        int n;
        function<vector<string>(int)> dfs = [&](int u) {
            if (u == 0) return vector<string>{""};
            if (u == 1) return vector<string>{"0", "1", "8"};
            vector<string> ans;
            for (auto& v : dfs(u - 2)) {
                for (auto& [l, r] : pairs) ans.push_back(l + v + r);
                if (u != n) ans.push_back('0' + v + '0');
            }
            return ans;
        };

        int a = low.size(), b = high.size();
        int ans = 0;
        ll l = stoll(low), r = stoll(high);
        for (n = a; n <= b; ++n) {
            for (auto& s : dfs(n)) {
                ll v = stoll(s);
                if (l <= v && v <= r) {
                    ++ans;
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
func strobogrammaticInRange(low string, high string) int {
	n := 0
	var dfs func(int) []string
	dfs = func(u int) []string {
		if u == 0 {
			return []string{""}
		}
		if u == 1 {
			return []string{"0", "1", "8"}
		}
		var ans []string
		pairs := [][]string{{"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}}
		for _, v := range dfs(u - 2) {
			for _, p := range pairs {
				ans = append(ans, p[0]+v+p[1])
			}
			if u != n {
				ans = append(ans, "0"+v+"0")
			}
		}
		return ans
	}
	a, b := len(low), len(high)
	l, _ := strconv.Atoi(low)
	r, _ := strconv.Atoi(high)
	ans := 0
	for n = a; n <= b; n++ {
		for _, s := range dfs(n) {
			v, _ := strconv.Atoi(s)
			if l <= v && v <= r {
				ans++
			}
		}
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串 low 和 high 表示两个整数 <code>low</code>&nbsp;和 <code>high</code> ，其中&nbsp;<code>low &lt;= high</code>&nbsp;，返回 范围 <code>[low, high]</code>&nbsp;内的 <strong>「中心对称数」</strong>总数&nbsp;&nbsp;。</p>

<p><strong>中心对称数&nbsp;</strong>是一个数字在旋转了&nbsp;<code>180</code> 度之后看起来依旧相同的数字（或者上下颠倒地看）。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> low = "50", high = "100"
<strong>输出:</strong> 3 
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> low = "0", high = "0"
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong><meta charset="UTF-8" /></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>1 &lt;= low.length, high.length &lt;= 15</code></li>
	<li><code>low</code>&nbsp;和&nbsp;<code>high</code>&nbsp;只包含数字</li>
	<li><code>low &lt;= high</code></li>
	<li><code>low</code>&nbsp;and&nbsp;<code>high</code>&nbsp;不包含任何前导零，除了零本身。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

若长度为 $1$，则中心对称数只有 $0, 1, 8$；若长度为 $2$，则中心对称数只有 $11, 69, 88, 96$。

我们设计递归函数 $dfs(u)$，其返回长度为 $u$ 的中心对称数。

若 $u$ 为 $0$，返回包含一个空串的列表，即 `[""]`；若 $u$ 为 $1$，返回列表 `["0", "1", "8"]`。

若 $u$ 大于 $1$，我们对长度为 $u - 2$ 的所有中心对称数进行遍历，对于每个中心对称数 $v$，在其左右两侧分别添加 $1, 8, 6, 9$，即可得到长度为 $u$ 的中心对称数。

注意，如果 $u\neq n$，我们还可以在中心对称数的左右两侧分别添加 $0$。

设 $low$ 和 $high$ 的长度分别为 $a$ 和 $b$。

接下来，我们在 $[a,..b]$ 范围内遍历所有长度，对于每个长度 $n$，我们获取所有中心对称数 $dfs(n)$，然后判断是否在 $[low, high]$ 范围内，若在，答案加一。

时间复杂度为 $O(2^{n+2}\times \log n)$。

相似题目：

-   [247. 中心对称数 II](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0247.Strobogrammatic%20Number%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        def dfs(u):
            if u == 0:
                return ['']
            if u == 1:
                return ['0', '1', '8']
            ans = []
            for v in dfs(u - 2):
                for l, r in ('11', '88', '69', '96'):
                    ans.append(l + v + r)
                if u != n:
                    ans.append('0' + v + '0')
            return ans

        a, b = len(low), len(high)
        low, high = int(low), int(high)
        ans = 0
        for n in range(a, b + 1):
            for s in dfs(n):
                if low <= int(s) <= high:
                    ans += 1
        return ans
```

#### Java

```java
class Solution {
    private static final int[][] PAIRS = {{1, 1}, {8, 8}, {6, 9}, {9, 6}};
    private int n;

    public int strobogrammaticInRange(String low, String high) {
        int a = low.length(), b = high.length();
        long l = Long.parseLong(low), r = Long.parseLong(high);
        int ans = 0;
        for (n = a; n <= b; ++n) {
            for (String s : dfs(n)) {
                long v = Long.parseLong(s);
                if (l <= v && v <= r) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    private List<String> dfs(int u) {
        if (u == 0) {
            return Collections.singletonList("");
        }
        if (u == 1) {
            return Arrays.asList("0", "1", "8");
        }
        List<String> ans = new ArrayList<>();
        for (String v : dfs(u - 2)) {
            for (var p : PAIRS) {
                ans.add(p[0] + v + p[1]);
            }
            if (u != n) {
                ans.add(0 + v + 0);
            }
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
    const vector<pair<char, char>> pairs = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

    int strobogrammaticInRange(string low, string high) {
        int n;
        function<vector<string>(int)> dfs = [&](int u) {
            if (u == 0) return vector<string>{""};
            if (u == 1) return vector<string>{"0", "1", "8"};
            vector<string> ans;
            for (auto& v : dfs(u - 2)) {
                for (auto& [l, r] : pairs) ans.push_back(l + v + r);
                if (u != n) ans.push_back('0' + v + '0');
            }
            return ans;
        };

        int a = low.size(), b = high.size();
        int ans = 0;
        ll l = stoll(low), r = stoll(high);
        for (n = a; n <= b; ++n) {
            for (auto& s : dfs(n)) {
                ll v = stoll(s);
                if (l <= v && v <= r) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func strobogrammaticInRange(low string, high string) int {
	n := 0
	var dfs func(int) []string
	dfs = func(u int) []string {
		if u == 0 {
			return []string{""}
		}
		if u == 1 {
			return []string{"0", "1", "8"}
		}
		var ans []string
		pairs := [][]string{{"1", "1"}, {"8", "8"}, {"6", "9"}, {"9", "6"}}
		for _, v := range dfs(u - 2) {
			for _, p := range pairs {
				ans = append(ans, p[0]+v+p[1])
			}
			if u != n {
				ans = append(ans, "0"+v+"0")
			}
		}
		return ans
	}
	a, b := len(low), len(high)
	l, _ := strconv.Atoi(low)
	r, _ := strconv.Atoi(high)
	ans := 0
	for n = a; n <= b; n++ {
		for _, s := range dfs(n) {
			v, _ := strconv.Atoi(s)
			if l <= v && v <= r {
				ans++
			}
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [249. 移位字符串分组 🔒](https://leetcode.cn/problems/group-shifted-strings){#249}

{{< tabs "249" >}}

{{% tab "python" %}}
```python
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        g = defaultdict(list)
        for s in strings:
            diff = ord(s[0]) - ord("a")
            t = []
            for c in s:
                c = ord(c) - diff
                if c < ord("a"):
                    c += 26
                t.append(chr(c))
            g["".join(t)].append(s)
        return list(g.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> g = new HashMap<>();
        for (var s : strings) {
            char[] t = s.toCharArray();
            int diff = t[0] - 'a';
            for (int i = 0; i < t.length; ++i) {
                t[i] = (char) (t[i] - diff);
                if (t[i] < 'a') {
                    t[i] += 26;
                }
            }
            g.computeIfAbsent(new String(t), k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(g.values());
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> g;
        for (auto& s : strings) {
            string t;
            int diff = s[0] - 'a';
            for (int i = 0; i < s.size(); ++i) {
                char c = s[i] - diff;
                if (c < 'a') {
                    c += 26;
                }
                t.push_back(c);
            }
            g[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& p : g) {
            ans.emplace_back(move(p.second));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func groupStrings(strings []string) [][]string {
	g := make(map[string][]string)
	for _, s := range strings {
		t := []byte(s)
		diff := t[0] - 'a'
		for i := range t {
			t[i] -= diff
			if t[i] < 'a' {
				t[i] += 26
			}
		}
		g[string(t)] = append(g[string(t)], s)
	}
	ans := make([][]string, 0, len(g))
	for _, v := range g {
		ans = append(ans, v)
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>对字符串进行 “移位” 的操作：</p>

<ul>
	<li><strong>右移</strong>：将字符串中每个字母都变为其在字母表中 <strong>后续</strong> 的字母，其中用 'a' 替换 'z'。比如，<code>"abc"</code>&nbsp;能够右移为&nbsp;<code>"bcd"</code>，<code>"xyz"</code>&nbsp;能够右移为&nbsp;<code>"yza"</code>。</li>
	<li><strong>左移</strong>：将字符串中每个字母都变为其在字母表中 <b>之前</b>&nbsp;的字母，其中用 'z' 替换 'a'。比如，<code>"bcd"</code>&nbsp;能够左移为&nbsp;<code>"abc"</code>，<code>"yza"</code>&nbsp;能够左移为&nbsp;<code>"xyz"</code>。</li>
</ul>

<p>我们可以不断地向两个方向移动字符串，形成 <strong>无限的移位序列</strong>。</p>

<ul>
	<li>例如，移动&nbsp;<code>"abc"</code>&nbsp;来形成序列：<code>... &lt;-&gt; "abc" &lt;-&gt; "bcd" &lt;-&gt; ... &lt;-&gt; "xyz" &lt;-&gt; "yza" &lt;-&gt; ... &lt;-&gt; "zab" &lt;-&gt; "abc" &lt;-&gt; ...</code></li>
</ul>

<p>给定一个字符串数组&nbsp;<code>strings</code>，将属于相同移位序列的所有&nbsp;<code>strings[i]</code>&nbsp;进行分组。你可以以 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">strings = ["abc","bcd","acef","xyz","az","ba","a","z"]</span></p>

<p><strong>输出：</strong><span class="example-io">[["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]</span></p>

<p>&nbsp;</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">strings = ["a"]</span></p>

<p><strong>输出：</strong><span class="example-io">[["a"]]</span></p>

<p>&nbsp;</p>
</div>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strings.length &lt;= 200</code></li>
	<li><code>1 &lt;= strings[i].length &lt;= 50</code></li>
	<li><code>strings[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $g$ 来存储每个字符串移位后且首位为 '`a`' 的字符串。即 $g[t]$ 表示所有字符串移位后字符串为 $t$ 的字符串集合。

我们遍历每个字符串，对于每个字符串，我们计算其移位后的字符串 $t$，然后将其加入到 $g[t]$ 中。

最后，我们将 $g$ 中的所有值取出来，即为答案。

时间复杂度 $O(L)$，空间复杂度 $O(L)$，其中 $L$ 为所有字符串的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        g = defaultdict(list)
        for s in strings:
            diff = ord(s[0]) - ord("a")
            t = []
            for c in s:
                c = ord(c) - diff
                if c < ord("a"):
                    c += 26
                t.append(chr(c))
            g["".join(t)].append(s)
        return list(g.values())
```

#### Java

```java
class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> g = new HashMap<>();
        for (var s : strings) {
            char[] t = s.toCharArray();
            int diff = t[0] - 'a';
            for (int i = 0; i < t.length; ++i) {
                t[i] = (char) (t[i] - diff);
                if (t[i] < 'a') {
                    t[i] += 26;
                }
            }
            g.computeIfAbsent(new String(t), k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(g.values());
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> g;
        for (auto& s : strings) {
            string t;
            int diff = s[0] - 'a';
            for (int i = 0; i < s.size(); ++i) {
                char c = s[i] - diff;
                if (c < 'a') {
                    c += 26;
                }
                t.push_back(c);
            }
            g[t].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto& p : g) {
            ans.emplace_back(move(p.second));
        }
        return ans;
    }
};
```

#### Go

```go
func groupStrings(strings []string) [][]string {
	g := make(map[string][]string)
	for _, s := range strings {
		t := []byte(s)
		diff := t[0] - 'a'
		for i := range t {
			t[i] -= diff
			if t[i] < 'a' {
				t[i] += 26
			}
		}
		g[string(t)] = append(g[string(t)], s)
	}
	ans := make([][]string, 0, len(g))
	for _, v := range g {
		ans = append(ans, v)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
