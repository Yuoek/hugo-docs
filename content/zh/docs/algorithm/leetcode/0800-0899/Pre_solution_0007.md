---
title: "0860_柠檬水找零"
date: 2025-10-08T18:36:34+08:00
weight: 7
tags: [二分查找, 二叉树, 位运算, 前缀和, 单调队列, 哈希表, 堆（优先队列）, 广度优先搜索, 排序, 数学, 数组, 数论, 枚举, 树, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 计数, 贪心, 队列]
---

{{< markmap >}}
### [0860_柠檬水找零](#860)
#### [贪心](#860)
#### [数组](#860)
### [0861_翻转矩阵后的得分](#861)
#### [贪心](#861)
#### [位运算](#861)
#### [数组](#861)
#### [矩阵](#861)
### [0862_和至少为 K 的最短子数组](#862)
#### [队列](#862)
#### [数组](#862)
#### [二分查找](#862)
#### [前缀和](#862)
#### [滑动窗口](#862)
#### [单调队列](#862)
#### [堆（优先队列）](#862)
### [0863_二叉树中所有距离为 K 的结点](#863)
#### [树](#863)
#### [深度优先搜索](#863)
#### [广度优先搜索](#863)
#### [哈希表](#863)
#### [二叉树](#863)
### [0864_获取所有钥匙的最短路径](#864)
#### [位运算](#864)
#### [广度优先搜索](#864)
#### [数组](#864)
#### [矩阵](#864)
### [0865_具有所有最深节点的最小子树](#865)
#### [树](#865)
#### [深度优先搜索](#865)
#### [广度优先搜索](#865)
#### [哈希表](#865)
#### [二叉树](#865)
### [0866_回文质数](#866)
#### [数学](#866)
#### [数论](#866)
### [0867_转置矩阵](#867)
#### [数组](#867)
#### [矩阵](#867)
#### [模拟](#867)
### [0868_二进制间距](#868)
#### [位运算](#868)
### [0869_重新排序得到 2 的幂](#869)
#### [哈希表](#869)
#### [数学](#869)
#### [计数](#869)
#### [枚举](#869)
#### [排序](#869)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0860_柠檬水找零
___
#### 贪心
___
#### 数组
---
### 0861_翻转矩阵后的得分
___
#### 贪心
___
#### 位运算
___
#### 数组
___
#### 矩阵
---
### 0862_和至少为 K 的最短子数组
___
#### 队列
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 滑动窗口
___
#### 单调队列
___
#### 堆（优先队列）
---
### 0863_二叉树中所有距离为 K 的结点
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 0864_获取所有钥匙的最短路径
___
#### 位运算
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0865_具有所有最深节点的最小子树
___
#### 树
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 哈希表
___
#### 二叉树
---
### 0866_回文质数
___
#### 数学
___
#### 数论
---
### 0867_转置矩阵
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 0868_二进制间距
___
#### 位运算
---
### 0869_重新排序得到 2 的幂
___
#### 哈希表
___
#### 数学
___
#### 计数
___
#### 枚举
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 位运算 |
| 前缀和 | 单调队列 | 哈希表 |
| 堆（优先队列） | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 枚举 | 树 | 模拟 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 计数 | 贪心 | 队列 |

# [860. 柠檬水找零](https://leetcode.cn/problems/lemonade-change){#860}

{{< tabs "860" >}}

{{% tab "python" %}}
```python
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = ten = 0
        for v in bills:
            if v == 5:
                five += 1
            elif v == 10:
                ten += 1
                five -= 1
            else:
                if ten:
                    ten -= 1
                    five -= 1
                else:
                    five -= 3
            if five < 0:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        for (int v : bills) {
            switch (v) {
                case 5 -> ++five;
                case 10 -> {
                    ++ten;
                    --five;
                }
                case 20 -> {
                    if (ten > 0) {
                        --ten;
                        --five;
                    } else {
                        five -= 3;
                    }
                }
            }
            if (five < 0) {
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
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 10;
        for (int v : bills) {
            if (v == 5) {
                ++five;
            } else if (v == 10) {
                ++ten;
                --five;
            } else {
                if (ten) {
                    --ten;
                    --five;
                } else {
                    five -= 3;
                }
            }
            if (five < 0) {
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
func lemonadeChange(bills []int) bool {
	five, ten := 0, 0
	for _, v := range bills {
		if v == 5 {
			five++
		} else if v == 10 {
			ten++
			five--
		} else {
			if ten > 0 {
				ten--
				five--
			} else {
				five -= 3
			}
		}
		if five < 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const lemonadeChange = (bills: number[], f = 0, t = 0): boolean =>
    bills.every(
        x => (
            (!(x ^ 5) && ++f) ||
                (!(x ^ 10) && (--f, ++t)) ||
                (!(x ^ 20) && (t ? (f--, t--) : (f -= 3), 1)),
            f >= 0
        ),
    );
```
{{% /tab %}}
{{% tab "js" %}}
```js
const lemonadeChange = (bills, f = 0, t = 0) =>
    bills.every(
        x => (
            (!(x ^ 5) && ++f) ||
                (!(x ^ 10) && (--f, ++t)) ||
                (!(x ^ 20) && (t ? (f--, t--) : (f -= 3), 1)),
            f >= 0
        ),
    );
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        let (mut five, mut ten) = (0, 0);
        for bill in bills.iter() {
            match bill {
                5 => {
                    five += 1;
                }
                10 => {
                    five -= 1;
                    ten += 1;
                }
                _ => {
                    if ten != 0 {
                        ten -= 1;
                        five -= 1;
                    } else {
                        five -= 3;
                    }
                }
            }

            if five < 0 {
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

<p>在柠檬水摊上，每一杯柠檬水的售价为&nbsp;<code>5</code>&nbsp;美元。顾客排队购买你的产品，（按账单 <code>bills</code> 支付的顺序）一次购买一杯。</p>

<p>每位顾客只买一杯柠檬水，然后向你付 <code>5</code> 美元、<code>10</code> 美元或 <code>20</code> 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 <code>5</code> 美元。</p>

<p>注意，一开始你手头没有任何零钱。</p>

<p>给你一个整数数组 <code>bills</code> ，其中 <code>bills[i]</code> 是第 <code>i</code> 位顾客付的账。如果你能给每位顾客正确找零，返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>bills = [5,5,5,10,20]
<strong>输出：</strong>true
<strong>解释：
</strong>前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>bills = [5,5,10,10,20]
<strong>输出：</strong>false
<strong>解释：</strong>
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= bills.length &lt;= 10<sup>5</sup></code></li>
	<li><code>bills[i]</code>&nbsp;不是&nbsp;<code>5</code>&nbsp;就是&nbsp;<code>10</code>&nbsp;或是&nbsp;<code>20</code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 模拟

我们从前往后遍历账单数组 $bills$，对于当前遍历到的账单：

-   如果是 $5$ 美元，那么直接收下即可；
-   如果是 $10$ 美元，那么需要找零 $5$ 美元；
-   如果是 $20$ 美元，那么需要找零 $15$ 美元，此时有两种找零方式：找零 $1$ 张 $10$ 美元 + $1$ 张 $5$ 美元；找零 $3$ 张 $5$ 美元。我们优先用第一种找零方式，如果没有足够的 $10$ 美元，那么用第二种方式；
-   如果发现 $5$ 美元的数量不够，直接返回 `false`。

遍历结束，说明我们没有遇到无法找零的情况，返回 `true` 即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为账单数组 $bills$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = ten = 0
        for v in bills:
            if v == 5:
                five += 1
            elif v == 10:
                ten += 1
                five -= 1
            else:
                if ten:
                    ten -= 1
                    five -= 1
                else:
                    five -= 3
            if five < 0:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        for (int v : bills) {
            switch (v) {
                case 5 -> ++five;
                case 10 -> {
                    ++ten;
                    --five;
                }
                case 20 -> {
                    if (ten > 0) {
                        --ten;
                        --five;
                    } else {
                        five -= 3;
                    }
                }
            }
            if (five < 0) {
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
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 10;
        for (int v : bills) {
            if (v == 5) {
                ++five;
            } else if (v == 10) {
                ++ten;
                --five;
            } else {
                if (ten) {
                    --ten;
                    --five;
                } else {
                    five -= 3;
                }
            }
            if (five < 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func lemonadeChange(bills []int) bool {
	five, ten := 0, 0
	for _, v := range bills {
		if v == 5 {
			five++
		} else if v == 10 {
			ten++
			five--
		} else {
			if ten > 0 {
				ten--
				five--
			} else {
				five -= 3
			}
		}
		if five < 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function lemonadeChange(bills: number[]): boolean {
    let [five, ten] = [0, 0];
    for (const x of bills) {
        switch (x) {
            case 5:
                five++;
                break;
            case 10:
                five--;
                ten++;
                break;
            case 20:
                if (ten) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                }
                break;
        }

        if (five < 0) {
            return false;
        }
    }
    return true;
}
```

#### JavaScript

```js
function lemonadeChange(bills) {
    let [five, ten] = [0, 0];
    for (const x of bills) {
        switch (x) {
            case 5:
                five++;
                break;
            case 10:
                five--;
                ten++;
                break;
            case 20:
                if (ten) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                }
                break;
        }

        if (five < 0) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        let (mut five, mut ten) = (0, 0);
        for bill in bills.iter() {
            match bill {
                5 => {
                    five += 1;
                }
                10 => {
                    five -= 1;
                    ten += 1;
                }
                _ => {
                    if ten != 0 {
                        ten -= 1;
                        five -= 1;
                    } else {
                        five -= 3;
                    }
                }
            }

            if five < 0 {
                return false;
            }
        }
        true
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：一行

<!-- tabs:start -->

#### TypeScript

```ts
const lemonadeChange = (bills: number[], f = 0, t = 0): boolean =>
    bills.every(
        x => (
            (!(x ^ 5) && ++f) ||
                (!(x ^ 10) && (--f, ++t)) ||
                (!(x ^ 20) && (t ? (f--, t--) : (f -= 3), 1)),
            f >= 0
        ),
    );
```

#### JavaScript

```js
const lemonadeChange = (bills, f = 0, t = 0) =>
    bills.every(
        x => (
            (!(x ^ 5) && ++f) ||
                (!(x ^ 10) && (--f, ++t)) ||
                (!(x ^ 20) && (t ? (f--, t--) : (f -= 3), 1)),
            f >= 0
        ),
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [861. 翻转矩阵后的得分](https://leetcode.cn/problems/score-after-flipping-matrix){#861}

{{< tabs "861" >}}

{{% tab "python" %}}
```python
class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for i in range(m):
            if grid[i][0] == 0:
                for j in range(n):
                    grid[i][j] ^= 1
        ans = 0
        for j in range(n):
            cnt = sum(grid[i][j] for i in range(m))
            ans += max(cnt, m - cnt) * (1 << (n - j - 1))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += grid[i][j];
            }
            ans += Math.max(cnt, m - cnt) * (1 << (n - j - 1));
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
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += grid[i][j];
            }
            ans += max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matrixScore(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		if grid[i][0] == 0 {
			for j := 0; j < n; j++ {
				grid[i][j] ^= 1
			}
		}
	}
	ans := 0
	for j := 0; j < n; j++ {
		cnt := 0
		for i := 0; i < m; i++ {
			cnt += grid[i][j]
		}
		if cnt < m-cnt {
			cnt = m - cnt
		}
		ans += cnt * (1 << (n - j - 1))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function matrixScore(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    for (let i = 0; i < m; ++i) {
        if (grid[i][0] == 0) {
            for (let j = 0; j < n; ++j) {
                grid[i][j] ^= 1;
            }
        }
    }
    let ans = 0;
    for (let j = 0; j < n; ++j) {
        let cnt = 0;
        for (let i = 0; i < m; ++i) {
            cnt += grid[i][j];
        }
        ans += Math.max(cnt, m - cnt) * (1 << (n - j - 1));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MatrixScore(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) {
                    ++cnt;
                }
            }
            ans += Math.Max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的二元矩阵 <code>grid</code> ，矩阵中每个元素的值为 <code>0</code> 或 <code>1</code> 。</p>

<p>一次 <strong>移动</strong> 是指选择任一行或列，并转换该行或列中的每一个值：将所有 <code>0</code> 都更改为 <code>1</code>，将所有 <code>1</code> 都更改为 <code>0</code>。</p>

<p>在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的 <strong>得分</strong> 就是这些数字的总和。</p>

<p>在执行任意次 <strong>移动</strong> 后（含 0 次），返回可能的最高分数。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0861.Score%20After%20Flipping%20Matrix/images/lc-toogle1.jpg" style="width: 500px; height: 299px;" />
<pre>
<strong>输入：</strong>grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
<strong>输出：</strong>39
<strong>解释：</strong>0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们注意到，对于任意一个翻转方案，翻转的次序不影响最后的结果。因此我们可以先考虑所有的行翻转，再考虑所有的列翻转。

每一行的数字要尽可能大，因此，我们遍历每一行，若行首元素为 $0$，则将该行进行翻转。

接下来，对于每一列 $j$，我们统计该列中 $0$ 和 $1$ 的数量，令 $cnt$ 为其中的最大值，则该列的贡献为 $cnt \times 2^{n - j - 1}$。对所有列的贡献进行累加，即可得到答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(1)$。其中 $m$, $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matrixScore(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        for i in range(m):
            if grid[i][0] == 0:
                for j in range(n):
                    grid[i][j] ^= 1
        ans = 0
        for j in range(n):
            cnt = sum(grid[i][j] for i in range(m))
            ans += max(cnt, m - cnt) * (1 << (n - j - 1))
        return ans
```

#### Java

```java
class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += grid[i][j];
            }
            ans += Math.max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                cnt += grid[i][j];
            }
            ans += max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return ans;
    }
};
```

#### Go

```go
func matrixScore(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	for i := 0; i < m; i++ {
		if grid[i][0] == 0 {
			for j := 0; j < n; j++ {
				grid[i][j] ^= 1
			}
		}
	}
	ans := 0
	for j := 0; j < n; j++ {
		cnt := 0
		for i := 0; i < m; i++ {
			cnt += grid[i][j]
		}
		if cnt < m-cnt {
			cnt = m - cnt
		}
		ans += cnt * (1 << (n - j - 1))
	}
	return ans
}
```

#### TypeScript

```ts
function matrixScore(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    for (let i = 0; i < m; ++i) {
        if (grid[i][0] == 0) {
            for (let j = 0; j < n; ++j) {
                grid[i][j] ^= 1;
            }
        }
    }
    let ans = 0;
    for (let j = 0; j < n; ++j) {
        let cnt = 0;
        for (let i = 0; i < m; ++i) {
            cnt += grid[i][j];
        }
        ans += Math.max(cnt, m - cnt) * (1 << (n - j - 1));
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int MatrixScore(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] ^= 1;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == 1) {
                    ++cnt;
                }
            }
            ans += Math.Max(cnt, m - cnt) * (1 << (n - j - 1));
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

# [862. 和至少为 K 的最短子数组](https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k){#862}

{{< tabs "862" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        s = list(accumulate(nums, initial=0))
        q = deque()
        ans = inf
        for i, v in enumerate(s):
            while q and v - s[q[0]] >= k:
                ans = min(ans, i - q.popleft())
            while q and s[q[-1]] >= v:
                q.pop()
            q.append(i)
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        Deque<Integer> q = new ArrayDeque<>();
        int ans = n + 1;
        for (int i = 0; i <= n; ++i) {
            while (!q.isEmpty() && s[i] - s[q.peek()] >= k) {
                ans = Math.min(ans, i - q.poll());
            }
            while (!q.isEmpty() && s[q.peekLast()] >= s[i]) {
                q.pollLast();
            }
            q.offer(i);
        }
        return ans > n ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + nums[i];
        deque<int> q;
        int ans = n + 1;
        for (int i = 0; i <= n; ++i) {
            while (!q.empty() && s[i] - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && s[q.back()] >= s[i]) q.pop_back();
            q.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestSubarray(nums []int, k int) int {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	q := []int{}
	ans := n + 1
	for i, v := range s {
		for len(q) > 0 && v-s[q[0]] >= k {
			ans = min(ans, i-q[0])
			q = q[1:]
		}
		for len(q) > 0 && s[q[len(q)-1]] >= v {
			q = q[:len(q)-1]
		}
		q = append(q, i)
	}
	if ans > n {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function shortestSubarray(nums: number[], k: number): number {
    const [n, MAX] = [nums.length, Number.POSITIVE_INFINITY];
    const s = Array(n + 1).fill(0);
    const q: number[] = [];
    let ans = MAX;

    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }

    for (let i = 0; i < n + 1; i++) {
        while (q.length && s[i] - s[q[0]] >= k) {
            ans = Math.min(ans, i - q.shift()!);
        }

        while (q.length && s[i] <= s[q.at(-1)!]) {
            q.pop();
        }

        q.push(i);
    }

    return ans === MAX ? -1 : ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function shortestSubarray(nums, k) {
    const [n, MAX] = [nums.length, Number.POSITIVE_INFINITY];
    const s = Array(n + 1).fill(0);
    const q = [];
    let ans = MAX;

    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }

    for (let i = 0; i < n + 1; i++) {
        while (q.length && s[i] - s[q[0]] >= k) {
            ans = Math.min(ans, i - q.shift());
        }

        while (q.length && s[i] <= s[q.at(-1)]) {
            q.pop();
        }

        q.push(i);
    }

    return ans === MAX ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，找出 <code>nums</code> 中和至少为 <code>k</code> 的 <strong>最短非空子数组</strong> ，并返回该子数组的长度。如果不存在这样的 <strong>子数组</strong> ，返回 <code>-1</code> 。</p>

<p><strong>子数组</strong> 是数组中 <strong>连续</strong> 的一部分。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], k = 1
<strong>输出：</strong>1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2], k = 4
<strong>输出：</strong>-1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,-1,2], k = 3
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 单调队列

题目要求找到一个最短的子数组，使得子数组的和大于等于 $k$。不难想到，可以使用前缀和快速计算子数组的和。

我们用一个长度为 $n+1$ 的数组 $s[i]$ 表示数组 $nums$ 前 $i$ 个元素的和。另外，我们需要维护一个严格单调递增的队列 $q$，队列中存储的是前缀和数组 $s[i]$ 的下标。注意，这里的单调递增是指下标对应的前缀和的大小，而不是下标的大小。

为什么存的是下标呢？这是为了方便计算子数组的长度。那为什么队列严格单调递增？我们可以用反证法来说明。

假设队列元素非严格单调递增，也即是说，存在下标 $i$ 和 $j$，满足 $i < j$，且 $s[i] \geq s[j]$。

当遍历到下标 $k$，其中 $i \lt j \lt k \leq n$，此时 $s[k]-s[j] \geq s[k]-s[i]$，且 $nums[j..k-1]$ 的长度小于 $nums[i..k-1]$ 的长度。由于下标 $j$ 的存在，子数组 $nums[i..k-1]$ 一定不是最优解，队列中的下标 $i$ 是不必要的，需要将其移除。因此，队列中的元素一定严格单调递增。

回到这道题目上，我们遍历前缀和数组 $s$，对于遍历到的下标 $i$，如果 $s[i] - s[q.front] \geq k$，说明当前遇到了一个可行解，我们可以更新答案。此时，我们需要将队首元素出队，直到队列为空或者 $s[i] - s[q.front] \lt k$ 为止。

如果此时队列不为空，为了维持队列的严格单调递增，我们还需要判断队尾元素是否需要出队，如果 $s[q.back] \geq s[i]$，则需要循环将队尾元素出队，直到队列为空或者 $s[q.back] \lt s[i]$ 为止。然后，我们将下标 $i$ 入队。

遍历结束，如果我们没有找到可行解，那么返回 $-1$。否则，返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        s = list(accumulate(nums, initial=0))
        q = deque()
        ans = inf
        for i, v in enumerate(s):
            while q and v - s[q[0]] >= k:
                ans = min(ans, i - q.popleft())
            while q and s[q[-1]] >= v:
                q.pop()
            q.append(i)
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        Deque<Integer> q = new ArrayDeque<>();
        int ans = n + 1;
        for (int i = 0; i <= n; ++i) {
            while (!q.isEmpty() && s[i] - s[q.peek()] >= k) {
                ans = Math.min(ans, i - q.poll());
            }
            while (!q.isEmpty() && s[q.peekLast()] >= s[i]) {
                q.pollLast();
            }
            q.offer(i);
        }
        return ans > n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> s(n + 1);
        for (int i = 0; i < n; ++i) s[i + 1] = s[i] + nums[i];
        deque<int> q;
        int ans = n + 1;
        for (int i = 0; i <= n; ++i) {
            while (!q.empty() && s[i] - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && s[q.back()] >= s[i]) q.pop_back();
            q.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func shortestSubarray(nums []int, k int) int {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	q := []int{}
	ans := n + 1
	for i, v := range s {
		for len(q) > 0 && v-s[q[0]] >= k {
			ans = min(ans, i-q[0])
			q = q[1:]
		}
		for len(q) > 0 && s[q[len(q)-1]] >= v {
			q = q[:len(q)-1]
		}
		q = append(q, i)
	}
	if ans > n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function shortestSubarray(nums: number[], k: number): number {
    const [n, MAX] = [nums.length, Number.POSITIVE_INFINITY];
    const s = Array(n + 1).fill(0);
    const q: number[] = [];
    let ans = MAX;

    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }

    for (let i = 0; i < n + 1; i++) {
        while (q.length && s[i] - s[q[0]] >= k) {
            ans = Math.min(ans, i - q.shift()!);
        }

        while (q.length && s[i] <= s[q.at(-1)!]) {
            q.pop();
        }

        q.push(i);
    }

    return ans === MAX ? -1 : ans;
}
```

#### JavaScript

```js
function shortestSubarray(nums, k) {
    const [n, MAX] = [nums.length, Number.POSITIVE_INFINITY];
    const s = Array(n + 1).fill(0);
    const q = [];
    let ans = MAX;

    for (let i = 0; i < n; i++) {
        s[i + 1] = s[i] + nums[i];
    }

    for (let i = 0; i < n + 1; i++) {
        while (q.length && s[i] - s[q[0]] >= k) {
            ans = Math.min(ans, i - q.shift());
        }

        while (q.length && s[i] <= s[q.at(-1)]) {
            q.pop();
        }

        q.push(i);
    }

    return ans === MAX ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [863. 二叉树中所有距离为 K 的结点](https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree){#863}

{{< tabs "863" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        def dfs(root, fa):
            if root is None:
                return
            g[root] = fa
            dfs(root.left, root)
            dfs(root.right, root)

        def dfs2(root, fa, k):
            if root is None:
                return
            if k == 0:
                ans.append(root.val)
                return
            for nxt in (root.left, root.right, g[root]):
                if nxt != fa:
                    dfs2(nxt, root, k - 1)

        g = {}
        dfs(root, None)
        ans = []
        dfs2(target, None, k)
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private Map<TreeNode, TreeNode> g = new HashMap<>();
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        dfs(root, null);
        dfs2(target, null, k);
        return ans;
    }

    private void dfs(TreeNode root, TreeNode fa) {
        if (root == null) {
            return;
        }
        g.put(root, fa);
        dfs(root.left, root);
        dfs(root.right, root);
    }

    private void dfs2(TreeNode root, TreeNode fa, int k) {
        if (root == null) {
            return;
        }
        if (k == 0) {
            ans.add(root.val);
            return;
        }
        for (TreeNode nxt : new TreeNode[] {root.left, root.right, g.get(root)}) {
            if (nxt != fa) {
                dfs2(nxt, root, k - 1);
            }
        }
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> g;
        vector<int> ans;

        auto dfs = [&](this auto&& dfs, TreeNode* node, TreeNode* fa) {
            if (!node) return;
            g[node] = fa;
            dfs(node->left, node);
            dfs(node->right, node);
        };

        auto dfs2 = [&](this auto&& dfs2, TreeNode* node, TreeNode* fa, int k) {
            if (!node) return;
            if (k == 0) {
                ans.push_back(node->val);
                return;
            }
            for (auto&& nxt : {node->left, node->right, g[node]}) {
                if (nxt != fa) {
                    dfs2(nxt, node, k - 1);
                }
            }
        };

        dfs(root, nullptr);
        dfs2(target, nullptr, k);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	g := make(map[*TreeNode]*TreeNode)
	ans := []int{}

	var dfs func(node, fa *TreeNode)
	dfs = func(node, fa *TreeNode) {
		if node == nil {
			return
		}
		g[node] = fa
		dfs(node.Left, node)
		dfs(node.Right, node)
	}

	var dfs2 func(node, fa *TreeNode, k int)
	dfs2 = func(node, fa *TreeNode, k int) {
		if node == nil {
			return
		}
		if k == 0 {
			ans = append(ans, node.Val)
			return
		}
		for _, nxt := range []*TreeNode{node.Left, node.Right, g[node]} {
			if nxt != fa {
				dfs2(nxt, node, k-1)
			}
		}
	}

	dfs(root, nil)
	dfs2(target, nil, k)

	return ans
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

function distanceK(root: TreeNode | null, target: TreeNode | null, k: number): number[] {
    const g = new Map<TreeNode, TreeNode | null>();
    const ans: number[] = [];

    const dfs = (node: TreeNode | null, fa: TreeNode | null) => {
        if (!node) {
            return;
        }
        g.set(node, fa);
        dfs(node.left, node);
        dfs(node.right, node);
    };

    const dfs2 = (node: TreeNode | null, fa: TreeNode | null, k: number) => {
        if (!node) {
            return;
        }
        if (k === 0) {
            ans.push(node.val);
            return;
        }
        for (const nxt of [node.left, node.right, g.get(node) || null]) {
            if (nxt !== fa) {
                dfs2(nxt, node, k - 1);
            }
        }
    };

    dfs(root, null);
    dfs2(target, null, k);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二叉树（具有根结点&nbsp;<code>root</code>），&nbsp;一个目标结点&nbsp;<code>target</code>&nbsp;，和一个整数值 <code>k</code>&nbsp;，返回到目标结点 <code>target</code> 距离为 <code>k</code> 的所有结点的值的数组。</p>

<p>答案可以以 <strong>任何顺序</strong> 返回。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0863.All%20Nodes%20Distance%20K%20in%20Binary%20Tree/images/sketch0.png" style="height: 429px; width: 500px;" /></p>

<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
<strong>输出：</strong>[7,4,1]
<strong>解释：</strong>所求结点为与目标结点（值为 5）距离为 2 的结点，值分别为 7，4，以及 1
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> root = [1], target = 1, k = 3
<strong>输出:</strong> []
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li>节点数在&nbsp;<code>[1, 500]</code>&nbsp;范围内</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li><code>Node.val</code>&nbsp;中所有值 <strong>不同</strong></li>
	<li>目标结点&nbsp;<code>target</code>&nbsp;是树上的结点。</li>
	<li><code>0 &lt;= k &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 哈希表

我们先用 DFS 遍历整棵树，将每个节点的父节点保存到哈希表 $\textit{g}$ 中。

接下来，我们再次用 DFS，从 $\textit{target}$ 出发，向上向下搜索距离为 $k$ 的节点，添加到结果数组中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        def dfs(root, fa):
            if root is None:
                return
            g[root] = fa
            dfs(root.left, root)
            dfs(root.right, root)

        def dfs2(root, fa, k):
            if root is None:
                return
            if k == 0:
                ans.append(root.val)
                return
            for nxt in (root.left, root.right, g[root]):
                if nxt != fa:
                    dfs2(nxt, root, k - 1)

        g = {}
        dfs(root, None)
        ans = []
        dfs2(target, None, k)
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
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private Map<TreeNode, TreeNode> g = new HashMap<>();
    private List<Integer> ans = new ArrayList<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        dfs(root, null);
        dfs2(target, null, k);
        return ans;
    }

    private void dfs(TreeNode root, TreeNode fa) {
        if (root == null) {
            return;
        }
        g.put(root, fa);
        dfs(root.left, root);
        dfs(root.right, root);
    }

    private void dfs2(TreeNode root, TreeNode fa, int k) {
        if (root == null) {
            return;
        }
        if (k == 0) {
            ans.add(root.val);
            return;
        }
        for (TreeNode nxt : new TreeNode[] {root.left, root.right, g.get(root)}) {
            if (nxt != fa) {
                dfs2(nxt, root, k - 1);
            }
        }
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> g;
        vector<int> ans;

        auto dfs = [&](this auto&& dfs, TreeNode* node, TreeNode* fa) {
            if (!node) return;
            g[node] = fa;
            dfs(node->left, node);
            dfs(node->right, node);
        };

        auto dfs2 = [&](this auto&& dfs2, TreeNode* node, TreeNode* fa, int k) {
            if (!node) return;
            if (k == 0) {
                ans.push_back(node->val);
                return;
            }
            for (auto&& nxt : {node->left, node->right, g[node]}) {
                if (nxt != fa) {
                    dfs2(nxt, node, k - 1);
                }
            }
        };

        dfs(root, nullptr);
        dfs2(target, nullptr, k);
        return ans;
    }
};
```

#### Go

```go
func distanceK(root *TreeNode, target *TreeNode, k int) []int {
	g := make(map[*TreeNode]*TreeNode)
	ans := []int{}

	var dfs func(node, fa *TreeNode)
	dfs = func(node, fa *TreeNode) {
		if node == nil {
			return
		}
		g[node] = fa
		dfs(node.Left, node)
		dfs(node.Right, node)
	}

	var dfs2 func(node, fa *TreeNode, k int)
	dfs2 = func(node, fa *TreeNode, k int) {
		if node == nil {
			return
		}
		if k == 0 {
			ans = append(ans, node.Val)
			return
		}
		for _, nxt := range []*TreeNode{node.Left, node.Right, g[node]} {
			if nxt != fa {
				dfs2(nxt, node, k-1)
			}
		}
	}

	dfs(root, nil)
	dfs2(target, nil, k)

	return ans
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

function distanceK(root: TreeNode | null, target: TreeNode | null, k: number): number[] {
    const g = new Map<TreeNode, TreeNode | null>();
    const ans: number[] = [];

    const dfs = (node: TreeNode | null, fa: TreeNode | null) => {
        if (!node) {
            return;
        }
        g.set(node, fa);
        dfs(node.left, node);
        dfs(node.right, node);
    };

    const dfs2 = (node: TreeNode | null, fa: TreeNode | null, k: number) => {
        if (!node) {
            return;
        }
        if (k === 0) {
            ans.push(node.val);
            return;
        }
        for (const nxt of [node.left, node.right, g.get(node) || null]) {
            if (nxt !== fa) {
                dfs2(nxt, node, k - 1);
            }
        }
    };

    dfs(root, null);
    dfs2(target, null, k);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [864. 获取所有钥匙的最短路径](https://leetcode.cn/problems/shortest-path-to-get-all-keys){#864}

{{< tabs "864" >}}

{{% tab "python" %}}
```python
class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        # 找起点 (si, sj)
        si, sj = next((i, j) for i in range(m) for j in range(n) if grid[i][j] == '@')
        # 统计钥匙数量
        k = sum(v.islower() for row in grid for v in row)
        dirs = (-1, 0, 1, 0, -1)
        q = deque([(si, sj, 0)])
        vis = {(si, sj, 0)}
        ans = 0
        while q:
            for _ in range(len(q)):
                i, j, state = q.popleft()
                # 找到所有钥匙，返回当前步数
                if state == (1 << k) - 1:
                    return ans

                # 往四个方向搜索
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    nxt = state
                    # 在边界范围内
                    if 0 <= x < m and 0 <= y < n:
                        c = grid[x][y]
                        # 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (
                            c == '#'
                            or c.isupper()
                            and (state & (1 << (ord(c) - ord('A')))) == 0
                        ):
                            continue
                        # 是钥匙
                        if c.islower():
                            # 更新状态
                            nxt |= 1 << (ord(c) - ord('a'))
                        # 此状态未访问过，入队
                        if (x, y, nxt) not in vis:
                            vis.add((x, y, nxt))
                            q.append((x, y, nxt))
            # 步数加一
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};

    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length, n = grid[0].length();
        int k = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i].charAt(j);
                if (Character.isLowerCase(c)) {
                    // 累加钥匙数量
                    ++k;
                } else if (c == '@') {
                    // 起点
                    si = i;
                    sj = j;
                }
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {si, sj, 0});
        boolean[][][] vis = new boolean[m][n][1 << k];
        vis[si][sj][0] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                int i = p[0], j = p[1], state = p[2];
                // 找到所有钥匙，返回当前步数
                if (state == (1 << k) - 1) {
                    return ans;
                }
                // 往四个方向搜索
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    // 在边界范围内
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        char c = grid[x].charAt(y);
                        // 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (c == '#'
                            || (Character.isUpperCase(c) && ((state >> (c - 'A')) & 1) == 0)) {
                            continue;
                        }
                        int nxt = state;
                        // 是钥匙
                        if (Character.isLowerCase(c)) {
                            // 更新状态
                            nxt |= 1 << (c - 'a');
                        }
                        // 此状态未访问过，入队
                        if (!vis[x][y][nxt]) {
                            vis[x][y][nxt] = true;
                            q.offer(new int[] {x, y, nxt});
                        }
                    }
                }
            }
            // 步数加一
            ++ans;
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
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int k = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                // 累加钥匙数量
                if (islower(c)) ++k;
                // 起点
                else if (c == '@')
                    si = i, sj = j;
            }
        }
        queue<tuple<int, int, int>> q{{{si, sj, 0}}};
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << k)));
        vis[si][sj][0] = true;
        int ans = 0;
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                auto [i, j, state] = q.front();
                q.pop();
                // 找到所有钥匙，返回当前步数
                if (state == (1 << k) - 1) return ans;
                // 往四个方向搜索
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    // 在边界范围内
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        char c = grid[x][y];
                        // 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (c == '#' || (isupper(c) && (state >> (c - 'A') & 1) == 0)) continue;
                        int nxt = state;
                        // 是钥匙，更新状态
                        if (islower(c)) nxt |= 1 << (c - 'a');
                        // 此状态未访问过，入队
                        if (!vis[x][y][nxt]) {
                            vis[x][y][nxt] = true;
                            q.push({x, y, nxt});
                        }
                    }
                }
            }
            // 步数加一
            ++ans;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func shortestPathAllKeys(grid []string) int {
	m, n := len(grid), len(grid[0])
	var k, si, sj int
	for i, row := range grid {
		for j, c := range row {
			if c >= 'a' && c <= 'z' {
				// 累加钥匙数量
				k++
			} else if c == '@' {
				// 起点
				si, sj = i, j
			}
		}
	}
	type tuple struct{ i, j, state int }
	q := []tuple{tuple{si, sj, 0}}
	vis := map[tuple]bool{tuple{si, sj, 0}: true}
	dirs := []int{-1, 0, 1, 0, -1}
	ans := 0
	for len(q) > 0 {
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			i, j, state := p.i, p.j, p.state
			// 找到所有钥匙，返回当前步数
			if state == 1<<k-1 {
				return ans
			}
			// 往四个方向搜索
			for h := 0; h < 4; h++ {
				x, y := i+dirs[h], j+dirs[h+1]
				// 在边界范围内
				if x >= 0 && x < m && y >= 0 && y < n {
					c := grid[x][y]
					// 是墙，或者是锁，但此时没有对应的钥匙，无法通过
					if c == '#' || (c >= 'A' && c <= 'Z' && (state>>(c-'A')&1 == 0)) {
						continue
					}
					nxt := state
					// 是钥匙，更新状态
					if c >= 'a' && c <= 'z' {
						nxt |= 1 << (c - 'a')
					}
					// 此状态未访问过，入队
					if !vis[tuple{x, y, nxt}] {
						vis[tuple{x, y, nxt}] = true
						q = append(q, tuple{x, y, nxt})
					}
				}
			}
		}
		// 步数加一
		ans++
	}
	return -1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二维网格&nbsp;<code>grid</code>&nbsp;，其中：</p>

<ul>
	<li><font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'.'</span></span></font></font> 代表一个空房间</li>
	<li><font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'#'</span></span></font></font> 代表一堵墙</li>
	<li><font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'@'</span></span></font></font>&nbsp;是起点</li>
	<li>小写字母代表钥匙</li>
	<li>大写字母代表锁</li>
</ul>

<p>我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。</p>

<p>假设 k&nbsp;为 钥匙/锁 的个数，且满足&nbsp;<code>1 &lt;= k&nbsp;&lt;= 6</code>，字母表中的前 <code>k</code>&nbsp;个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。</p>

<p>返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0864.Shortest%20Path%20to%20Get%20All%20Keys/images/lc-keys2.jpg" /></p>

<pre>
<strong>输入：</strong>grid = ["@.a..","###.#","b.A.B"]
<strong>输出：</strong>8
<strong>解释：</strong>目标是获得所有钥匙，而不是打开所有锁。
</pre>

<p><strong>示例 2：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0864.Shortest%20Path%20to%20Get%20All%20Keys/images/lc-key2.jpg" /></p>

<pre>
<strong>输入：</strong>grid = ["@..aA","..B#.","....b"]
<strong>输出：</strong>6
</pre>

<p><strong>示例 3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0864.Shortest%20Path%20to%20Get%20All%20Keys/images/lc-keys3.jpg" />
<pre>
<strong>输入:</strong> grid = ["@Aa"]
<strong>输出:</strong> -1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 30</code></li>
	<li><code>grid[i][j]</code>&nbsp;只含有&nbsp;<code>'.'</code>,&nbsp;<code>'#'</code>,&nbsp;<code>'@'</code>,&nbsp;<code>'a'-</code><code>'f</code><code>'</code>&nbsp;以及&nbsp;<code>'A'-'F'</code></li>
	<li>钥匙的数目范围是&nbsp;<code>[1, 6]</code>&nbsp;</li>
	<li>每个钥匙都对应一个 <strong>不同</strong> 的字母</li>
	<li>每个钥匙正好打开一个对应的锁</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + BFS

根据题意，我们需要从起点出发，往上下左右四个方向走，获取所有钥匙，最后返回获取所有钥匙所需要的移动的最少次数。若无法获取所有钥匙，返回 $-1$。

首先，我们遍历二维网格，找到起点位置 $(si, sj)$，并统计钥匙的个数 $k$。

然后，我们可以使用广度优先搜索 $BFS$ 来解决本题。由于钥匙的个数范围是 $[1, 6]$，我们可以用一个二进制数来表示钥匙的状态，其中第 $i$ 位为 $1$ 表示第 $i$ 把钥匙已经获取到了，为 $0$ 表示第 $i$ 把钥匙还没有获取到。

比如，以下例子中，共有 $4$ 个二进制位为 $1$，也就表示有 `'b', 'c', 'd', 'f'` $4$ 把钥匙已经获取到了。

```
1 0 1 1 1 0
^   ^ ^ ^
f   d c b
```

我们定义一个队列 $q$ 来存储当前位置以及当前拥有的钥匙的状态，即 $(i, j, \textit{state})$，其中 $(i, j)$ 表示当前位置，$\textit{state}$ 表示当前拥有的钥匙的状态，即 $\textit{state}$ 的第 $i$ 位为 $1$ 表示当前拥有第 $i$ 把钥匙，否则表示当前没有第 $i$ 把钥匙。

另外，定义哈希表或数组 $vis$ 记录当前位置以及当前拥有的钥匙的状态是否已经被访问过，如果访问过，则不需要再次访问。$vis[i][j][\textit{state}]$ 表示当前位置为 $(i, j)$，当前拥有的钥匙的状态为 $state$ 时，是否已经被访问过。

我们从起点 $(si, sj)$ 出发，将其加入队列 $q$，并将 $vis[si][sj][0]$ 置为 $true$，表示起点位置以及拥有的钥匙的状态为 $0$ 时已经被访问过。

在广度优先搜索的过程中，我们每次从队首取出一个位置 $(i, j, \textit{state})$，并判断当前位置是否为终点，即当前位置是否拥有所有的钥匙，即 $state$ 的二进制表示中的 $1$ 的个数是否为 $k$。如果是，将当前步数作为答案返回。

否则，我们从当前位置出发，往上下左右四个方向走，如果可以走到下一个位置 $(x, y)$，则将 $(x, y, nxt)$ 加入队列 $q$，其中 $nxt$ 表示下一个位置的钥匙的状态。

这里 $(x, y)$ 首先需要满足在网格范围内，即 $0 \leq x < m$ 且 $0 \leq y < n$。其次，如果 $(x, y)$ 位置是墙壁，即 `grid[x][y] == '#'`，或者 $(x, y)$ 位置是锁，但我们没有对应的钥匙，即 `grid[x][y] >= 'A' && grid[x][y] <= 'F' && (state >> (grid[x][y] - 'A') & 1) == 0)`，则不能走到位置 $(x, y)$。否则，我们可以走到位置 $(x, y)$。

搜索结束，没能找到所有的钥匙，返回 $-1$。

时间复杂度 $O(m\times n\times 2^k)$，空间复杂度 $O(m\times n\times 2^k)$。其中 $m$ 和 $n$ 分别为网格的行数和列数，而 $k$ 为钥匙的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        m, n = len(grid), len(grid[0])
        # 找起点 (si, sj)
        si, sj = next((i, j) for i in range(m) for j in range(n) if grid[i][j] == '@')
        # 统计钥匙数量
        k = sum(v.islower() for row in grid for v in row)
        dirs = (-1, 0, 1, 0, -1)
        q = deque([(si, sj, 0)])
        vis = {(si, sj, 0)}
        ans = 0
        while q:
            for _ in range(len(q)):
                i, j, state = q.popleft()
                # 找到所有钥匙，返回当前步数
                if state == (1 << k) - 1:
                    return ans

                # 往四个方向搜索
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    nxt = state
                    # 在边界范围内
                    if 0 <= x < m and 0 <= y < n:
                        c = grid[x][y]
                        # 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (
                            c == '#'
                            or c.isupper()
                            and (state & (1 << (ord(c) - ord('A')))) == 0
                        ):
                            continue
                        # 是钥匙
                        if c.islower():
                            # 更新状态
                            nxt |= 1 << (ord(c) - ord('a'))
                        # 此状态未访问过，入队
                        if (x, y, nxt) not in vis:
                            vis.add((x, y, nxt))
                            q.append((x, y, nxt))
            # 步数加一
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};

    public int shortestPathAllKeys(String[] grid) {
        int m = grid.length, n = grid[0].length();
        int k = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i].charAt(j);
                if (Character.isLowerCase(c)) {
                    // 累加钥匙数量
                    ++k;
                } else if (c == '@') {
                    // 起点
                    si = i;
                    sj = j;
                }
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {si, sj, 0});
        boolean[][][] vis = new boolean[m][n][1 << k];
        vis[si][sj][0] = true;
        int ans = 0;
        while (!q.isEmpty()) {
            for (int t = q.size(); t > 0; --t) {
                var p = q.poll();
                int i = p[0], j = p[1], state = p[2];
                // 找到所有钥匙，返回当前步数
                if (state == (1 << k) - 1) {
                    return ans;
                }
                // 往四个方向搜索
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    // 在边界范围内
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        char c = grid[x].charAt(y);
                        // 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (c == '#'
                            || (Character.isUpperCase(c) && ((state >> (c - 'A')) & 1) == 0)) {
                            continue;
                        }
                        int nxt = state;
                        // 是钥匙
                        if (Character.isLowerCase(c)) {
                            // 更新状态
                            nxt |= 1 << (c - 'a');
                        }
                        // 此状态未访问过，入队
                        if (!vis[x][y][nxt]) {
                            vis[x][y][nxt] = true;
                            q.offer(new int[] {x, y, nxt});
                        }
                    }
                }
            }
            // 步数加一
            ++ans;
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const static inline vector<int> dirs = {-1, 0, 1, 0, -1};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int k = 0;
        int si = 0, sj = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                // 累加钥匙数量
                if (islower(c)) ++k;
                // 起点
                else if (c == '@')
                    si = i, sj = j;
            }
        }
        queue<tuple<int, int, int>> q{{{si, sj, 0}}};
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << k)));
        vis[si][sj][0] = true;
        int ans = 0;
        while (!q.empty()) {
            for (int t = q.size(); t; --t) {
                auto [i, j, state] = q.front();
                q.pop();
                // 找到所有钥匙，返回当前步数
                if (state == (1 << k) - 1) return ans;
                // 往四个方向搜索
                for (int h = 0; h < 4; ++h) {
                    int x = i + dirs[h], y = j + dirs[h + 1];
                    // 在边界范围内
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        char c = grid[x][y];
                        // 是墙，或者是锁，但此时没有对应的钥匙，无法通过
                        if (c == '#' || (isupper(c) && (state >> (c - 'A') & 1) == 0)) continue;
                        int nxt = state;
                        // 是钥匙，更新状态
                        if (islower(c)) nxt |= 1 << (c - 'a');
                        // 此状态未访问过，入队
                        if (!vis[x][y][nxt]) {
                            vis[x][y][nxt] = true;
                            q.push({x, y, nxt});
                        }
                    }
                }
            }
            // 步数加一
            ++ans;
        }
        return -1;
    }
};
```

#### Go

```go
func shortestPathAllKeys(grid []string) int {
	m, n := len(grid), len(grid[0])
	var k, si, sj int
	for i, row := range grid {
		for j, c := range row {
			if c >= 'a' && c <= 'z' {
				// 累加钥匙数量
				k++
			} else if c == '@' {
				// 起点
				si, sj = i, j
			}
		}
	}
	type tuple struct{ i, j, state int }
	q := []tuple{tuple{si, sj, 0}}
	vis := map[tuple]bool{tuple{si, sj, 0}: true}
	dirs := []int{-1, 0, 1, 0, -1}
	ans := 0
	for len(q) > 0 {
		for t := len(q); t > 0; t-- {
			p := q[0]
			q = q[1:]
			i, j, state := p.i, p.j, p.state
			// 找到所有钥匙，返回当前步数
			if state == 1<<k-1 {
				return ans
			}
			// 往四个方向搜索
			for h := 0; h < 4; h++ {
				x, y := i+dirs[h], j+dirs[h+1]
				// 在边界范围内
				if x >= 0 && x < m && y >= 0 && y < n {
					c := grid[x][y]
					// 是墙，或者是锁，但此时没有对应的钥匙，无法通过
					if c == '#' || (c >= 'A' && c <= 'Z' && (state>>(c-'A')&1 == 0)) {
						continue
					}
					nxt := state
					// 是钥匙，更新状态
					if c >= 'a' && c <= 'z' {
						nxt |= 1 << (c - 'a')
					}
					// 此状态未访问过，入队
					if !vis[tuple{x, y, nxt}] {
						vis[tuple{x, y, nxt}] = true
						q = append(q, tuple{x, y, nxt})
					}
				}
			}
		}
		// 步数加一
		ans++
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [865. 具有所有最深节点的最小子树](https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes){#865}

{{< tabs "865" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root: Optional[TreeNode]) -> Tuple[Optional[TreeNode], int]:
            if root is None:
                return None, 0
            l, ld = dfs(root.left)
            r, rd = dfs(root.right)
            if ld > rd:
                return l, ld + 1
            if ld < rd:
                return r, rd + 1
            return root, ld + 1

        return dfs(root)[0]
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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).getKey();
    }

    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if (root == null) {
            return new Pair<>(null, 0);
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int ld = l.getValue(), rd = r.getValue();
        if (ld > rd) {
            return new Pair<>(l.getKey(), ld + 1);
        }
        if (ld < rd) {
            return new Pair<>(r.getKey(), rd + 1);
        }
        return new Pair<>(root, ld + 1);
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        using pti = pair<TreeNode*, int>;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pti {
            if (!root) {
                return {nullptr, 0};
            }
            auto [l, ld] = dfs(root->left);
            auto [r, rd] = dfs(root->right);
            if (ld > rd) {
                return {l, ld + 1};
            }
            if (ld < rd) {
                return {r, rd + 1};
            }
            return {root, ld + 1};
        };
        return dfs(root).first;
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
func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	type pair struct {
		node  *TreeNode
		depth int
	}
	var dfs func(*TreeNode) pair
	dfs = func(root *TreeNode) pair {
		if root == nil {
			return pair{nil, 0}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ld, rd := l.depth, r.depth
		if ld > rd {
			return pair{l.node, ld + 1}
		}
		if ld < rd {
			return pair{r.node, rd + 1}
		}
		return pair{root, ld + 1}
	}
	return dfs(root).node
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

function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
    const dfs = (root: TreeNode | null): [TreeNode, number] => {
        if (!root) {
            return [null, 0];
        }
        const [l, ld] = dfs(root.left);
        const [r, rd] = dfs(root.right);
        if (ld > rd) {
            return [l, ld + 1];
        }
        if (ld < rd) {
            return [r, rd + 1];
        }
        return [root, ld + 1];
    };
    return dfs(root)[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个根为&nbsp;<code>root</code>&nbsp;的二叉树，每个节点的深度是 <strong>该节点到根的最短距离</strong> 。</p>

<p>返回包含原始树中所有 <strong>最深节点</strong> 的 <em>最小子树</em> 。</p>

<p>如果一个节点在 <strong>整个树 </strong>的任意节点之间具有最大的深度，则该节点是 <strong>最深的</strong> 。</p>

<p>一个节点的 <strong>子树</strong> 是该节点加上它的所有后代的集合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0865.Smallest%20Subtree%20with%20all%20the%20Deepest%20Nodes/images/sketch1.png" style="width: 300px;" /></p>

<pre>
<strong>输入：</strong>root = [3,5,1,6,2,0,8,null,null,7,4]
<strong>输出：</strong>[2,7,4]
<strong>解释：</strong>
我们返回值为 2 的节点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的节点。
注意，节点 5、3 和 2 包含树中最深的节点，但节点 2 的子树最小，因此我们返回它。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>root = [1]
<strong>输出：</strong>[1]
<strong>解释：</strong>根节点是树中最深的节点。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>root = [0,1,3,null,2]
<strong>输出：</strong>[2]
<strong>解释：</strong>树中最深的节点为 2 ，有效子树为节点 2、1 和 0 的子树，但节点 2 的子树最小。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点的数量在<meta charset="UTF-8" />&nbsp;<code>[1, 500]</code>&nbsp;范围内。</li>
	<li><code>0 &lt;= Node.val &lt;= 500</code></li>
	<li>每个节点的值都是 <strong>独一无二</strong> 的。</li>
</ul>

<p>&nbsp;</p>

<p><strong>注意：</strong>本题与力扣 1123 重复：<a href="https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/" target="_blank">https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves</a></p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们设计一个函数 $\textit{dfs}(\textit{root})$，返回以 $\textit{root}$ 为根的子树中，包含所有最深节点的最小子树，以及以 $\textit{root}$ 为根的子树的深度。

函数 $\textit{dfs}(\textit{root})$ 的执行过程如下：

-   如果 $\textit{root}$ 为空，返回 $\text{null}$ 和 $0$。
-   否则，递归计算 $\textit{root}$ 的左子树和右子树的最小子树以及深度，分别为 $l$ 和 $l_d$ 以及 $r$ 和 $r_d$。如果 $l_d > r_d$，则以 $\textit{root}$ 的左孩子为根的子树中包含所有最深节点的最小子树就是 $l$，深度为 $l_d + 1$；如果 $l_d < r_d$，则以 $\textit{root}$ 的右孩子为根的子树中包含所有最深节点的最小子树就是 $r$，深度为 $r_d + 1$；如果 $l_d = r_d$，则 $\textit{root}$ 就是包含所有最深节点的最小子树，深度为 $l_d + 1$。

最后，返回 $\textit{dfs}(\textit{root})$ 的结果的第一个元素即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为二叉树的节点个数。

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
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root: Optional[TreeNode]) -> Tuple[Optional[TreeNode], int]:
            if root is None:
                return None, 0
            l, ld = dfs(root.left)
            r, rd = dfs(root.right)
            if ld > rd:
                return l, ld + 1
            if ld < rd:
                return r, rd + 1
            return root, ld + 1

        return dfs(root)[0]
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
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).getKey();
    }

    private Pair<TreeNode, Integer> dfs(TreeNode root) {
        if (root == null) {
            return new Pair<>(null, 0);
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int ld = l.getValue(), rd = r.getValue();
        if (ld > rd) {
            return new Pair<>(l.getKey(), ld + 1);
        }
        if (ld < rd) {
            return new Pair<>(r.getKey(), rd + 1);
        }
        return new Pair<>(root, ld + 1);
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        using pti = pair<TreeNode*, int>;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pti {
            if (!root) {
                return {nullptr, 0};
            }
            auto [l, ld] = dfs(root->left);
            auto [r, rd] = dfs(root->right);
            if (ld > rd) {
                return {l, ld + 1};
            }
            if (ld < rd) {
                return {r, rd + 1};
            }
            return {root, ld + 1};
        };
        return dfs(root).first;
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
func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	type pair struct {
		node  *TreeNode
		depth int
	}
	var dfs func(*TreeNode) pair
	dfs = func(root *TreeNode) pair {
		if root == nil {
			return pair{nil, 0}
		}
		l, r := dfs(root.Left), dfs(root.Right)
		ld, rd := l.depth, r.depth
		if ld > rd {
			return pair{l.node, ld + 1}
		}
		if ld < rd {
			return pair{r.node, rd + 1}
		}
		return pair{root, ld + 1}
	}
	return dfs(root).node
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

function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
    const dfs = (root: TreeNode | null): [TreeNode, number] => {
        if (!root) {
            return [null, 0];
        }
        const [l, ld] = dfs(root.left);
        const [r, rd] = dfs(root.right);
        if (ld > rd) {
            return [l, ld + 1];
        }
        if (ld < rd) {
            return [r, rd + 1];
        }
        return [root, ld + 1];
    };
    return dfs(root)[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [866. 回文质数](https://leetcode.cn/problems/prime-palindrome){#866}

{{< tabs "866" >}}

{{% tab "python" %}}
```python
class Solution:
    def primePalindrome(self, n: int) -> int:
        def is_prime(x):
            if x < 2:
                return False
            v = 2
            while v * v <= x:
                if x % v == 0:
                    return False
                v += 1
            return True

        def reverse(x):
            res = 0
            while x:
                res = res * 10 + x % 10
                x //= 10
            return res

        while 1:
            if reverse(n) == n and is_prime(n):
                return n
            if 10**7 < n < 10**8:
                n = 10**8
            n += 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int primePalindrome(int n) {
        while (true) {
            if (reverse(n) == n && isPrime(n)) {
                return n;
            }
            if (n > 10000000 && n < 100000000) {
                n = 100000000;
            }
            ++n;
        }
    }

    private boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int v = 2; v * v <= x; ++v) {
            if (x % v == 0) {
                return false;
            }
        }
        return true;
    }

    private int reverse(int x) {
        int res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
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
    int primePalindrome(int n) {
        while (1) {
            if (reverse(n) == n && isPrime(n)) return n;
            if (n > 10000000 && n < 100000000) n = 100000000;
            ++n;
        }
    }

    bool isPrime(int x) {
        if (x < 2) return false;
        for (int v = 2; v * v <= x; ++v)
            if (x % v == 0)
                return false;
        return true;
    }

    int reverse(int x) {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func primePalindrome(n int) int {
	isPrime := func(x int) bool {
		if x < 2 {
			return false
		}
		for v := 2; v*v <= x; v++ {
			if x%v == 0 {
				return false
			}
		}
		return true
	}

	reverse := func(x int) int {
		res := 0
		for x != 0 {
			res = res*10 + x%10
			x /= 10
		}
		return res
	}
	for {
		if reverse(n) == n && isPrime(n) {
			return n
		}
		if n > 10000000 && n < 100000000 {
			n = 100000000
		}
		n++
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，返回大于或等于 <code>n</code> 的最小&nbsp;<stron><strong>回文质数</strong></stron>。</p>
<!-- 一个整数是素数的定义，以及1不是素数的说明 -->

<p>一个整数如果恰好有两个除数：<code>1</code> 和它本身，那么它是 <strong>质数</strong> 。注意，<code>1</code> 不是质数。</p>

<ul>
	<li>例如，<code>2</code>、<code>3</code>、<code>5</code>、<code>7</code>、<code>11</code> 和 <code>13</code> 都是质数。</li>
</ul>

<p>一个整数如果从左向右读和从右向左读是相同的，那么它是<strong> 回文数 </strong>。</p>

<ul>
	<li>例如，<code>101</code> 和 <code>12321</code> 都是回文数。</li>
</ul>

<p>测试用例保证答案总是存在，并且在 <code>[2, 2 * 10<sup>8</sup>]</code> 范围内。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>7
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>11
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 13
<strong>输出：</strong>101
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>8</sup></code></li>
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
    def primePalindrome(self, n: int) -> int:
        def is_prime(x):
            if x < 2:
                return False
            v = 2
            while v * v <= x:
                if x % v == 0:
                    return False
                v += 1
            return True

        def reverse(x):
            res = 0
            while x:
                res = res * 10 + x % 10
                x //= 10
            return res

        while 1:
            if reverse(n) == n and is_prime(n):
                return n
            if 10**7 < n < 10**8:
                n = 10**8
            n += 1
```

#### Java

```java
class Solution {
    public int primePalindrome(int n) {
        while (true) {
            if (reverse(n) == n && isPrime(n)) {
                return n;
            }
            if (n > 10000000 && n < 100000000) {
                n = 100000000;
            }
            ++n;
        }
    }

    private boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int v = 2; v * v <= x; ++v) {
            if (x % v == 0) {
                return false;
            }
        }
        return true;
    }

    private int reverse(int x) {
        int res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int primePalindrome(int n) {
        while (1) {
            if (reverse(n) == n && isPrime(n)) return n;
            if (n > 10000000 && n < 100000000) n = 100000000;
            ++n;
        }
    }

    bool isPrime(int x) {
        if (x < 2) return false;
        for (int v = 2; v * v <= x; ++v)
            if (x % v == 0)
                return false;
        return true;
    }

    int reverse(int x) {
        int res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
```

#### Go

```go
func primePalindrome(n int) int {
	isPrime := func(x int) bool {
		if x < 2 {
			return false
		}
		for v := 2; v*v <= x; v++ {
			if x%v == 0 {
				return false
			}
		}
		return true
	}

	reverse := func(x int) int {
		res := 0
		for x != 0 {
			res = res*10 + x%10
			x /= 10
		}
		return res
	}
	for {
		if reverse(n) == n && isPrime(n) {
			return n
		}
		if n > 10000000 && n < 100000000 {
			n = 100000000
		}
		n++
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [867. 转置矩阵](https://leetcode.cn/problems/transpose-matrix){#867}

{{< tabs "867" >}}

{{% tab "python" %}}
```python
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return list(zip(*matrix))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] transpose(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] ans = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[j][i];
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
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func transpose(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
		for j := range ans[i] {
			ans[i][j] = matrix[j][i]
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function transpose(matrix: number[][]): number[][] {
    const [m, n] = [matrix.length, matrix[0].length];
    const ans: number[][] = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function (matrix) {
    const [m, n] = [matrix.length, matrix[0].length];
    const ans = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            ans[i][j] = matrix[j][i];
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

<p>给你一个二维整数数组 <code>matrix</code>， 返回 <code>matrix</code> 的 <strong>转置矩阵</strong> 。</p>

<p>矩阵的 <strong>转置</strong> 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0867.Transpose%20Matrix/images/hint_transpose.png" style="width: 600px; height: 197px;" /></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>输出：</strong>[[1,4,7],[2,5,8],[3,6,9]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1,2,3],[4,5,6]]
<strong>输出：</strong>[[1,4],[2,5],[3,6]]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 1000</code></li>
	<li><code>1 <= m * n <= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> <= matrix[i][j] <= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们记矩阵 $\textit{matrix}$ 的行数为 $m$，列数为 $n$。根据转置的定义，转置后的矩阵 $\textit{ans}$ 的行数为 $n$，列数为 $m$。

对于 $\textit{ans}$ 中的任意位置 $(i,j)$，其对应于矩阵 $\textit{matrix}$ 中的位置 $(j,i)$。因此，我们遍历矩阵 $\textit{matrix}$ 中的每个元素，将其转置到 $\textit{ans}$ 中相应的位置。

遍历结束后，返回 $\textit{ans}$ 即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵 $\textit{matrix}$ 的行数和列数。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        return list(zip(*matrix))
```

#### Java

```java
class Solution {
    public int[][] transpose(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[][] ans = new int[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[j][i];
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
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = matrix[j][i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func transpose(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	ans := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
		for j := range ans[i] {
			ans[i][j] = matrix[j][i]
		}
	}
	return ans
}
```

#### TypeScript

```ts
function transpose(matrix: number[][]): number[][] {
    const [m, n] = [matrix.length, matrix[0].length];
    const ans: number[][] = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function (matrix) {
    const [m, n] = [matrix.length, matrix[0].length];
    const ans = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            ans[i][j] = matrix[j][i];
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

# [868. 二进制间距](https://leetcode.cn/problems/binary-gap){#868}

{{< tabs "868" >}}

{{% tab "python" %}}
```python
class Solution:
    def binaryGap(self, n: int) -> int:
        ans = 0
        pre, cur = inf, 0
        while n:
            if n & 1:
                ans = max(ans, cur - pre)
                pre = cur
            cur += 1
            n >>= 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int binaryGap(int n) {
        int ans = 0;
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n % 2 == 1) {
                ans = Math.max(ans, cur - pre);
                pre = cur;
            }
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
    int binaryGap(int n) {
        int ans = 0;
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n & 1) {
                ans = max(ans, cur - pre);
                pre = cur;
            }
            ++cur;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func binaryGap(n int) (ans int) {
	for pre, cur := 100, 0; n != 0; n >>= 1 {
		if n&1 == 1 {
			ans = max(ans, cur-pre)
			pre = cur
		}
		cur++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function binaryGap(n: number): number {
    let ans = 0;
    for (let pre = 100, cur = 0; n; n >>= 1) {
        if (n & 1) {
            ans = Math.max(ans, cur - pre);
            pre = cur;
        }
        ++cur;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn binary_gap(mut n: i32) -> i32 {
        let mut ans = 0;
        let mut pre = 100;
        let mut cur = 0;
        while n != 0 {
            if n % 2 == 1 {
                ans = ans.max(cur - pre);
                pre = cur;
            }
            cur += 1;
            n >>= 1;
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

<p>给定一个正整数 <code>n</code>，找到并返回 <code>n</code> 的二进制表示中两个 <strong>相邻</strong> 1 之间的<strong> 最长距离 </strong>。如果不存在两个相邻的 1，返回 <code>0</code> 。</p>

<p>如果只有 <code>0</code> 将两个 <code>1</code> 分隔开（可能不存在 <code>0</code> ），则认为这两个 1 彼此 <strong>相邻</strong> 。两个 <code>1</code> 之间的距离是它们的二进制表示中位置的绝对差。例如，<code>"1001"</code> 中的两个 <code>1</code> 的距离为 3 。</p>

<p>&nbsp;</p>

<ul>
</ul>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 22
<strong>输出：</strong>2
<strong>解释：</strong>22 的二进制是 "10110" 。
在 22 的二进制表示中，有三个 1，组成两对相邻的 1 。
第一对相邻的 1 中，两个 1 之间的距离为 2 。
第二对相邻的 1 中，两个 1 之间的距离为 1 。
答案取两个距离之中最大的，也就是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>0
<strong>解释：</strong>8 的二进制是 "1000" 。
在 8 的二进制表示中没有相邻的两个 1，所以返回 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>2
<strong>解释：</strong>5 的二进制是 "101" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

我们用两个指针 $\textit{pre}$ 和 $\textit{cur}$ 分别表示上一个和当前的 $1$ 的位置，初始时 $\textit{pre} = 100$, $\textit{cur} = 0$，然后遍历 $n$ 的二进制表示，当遇到 $1$ 时，计算当前位置和上一个 $1$ 的位置之间的距离，并更新答案。

时间复杂度 $O(\log n)$，其中 $n$ 是题目给定的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def binaryGap(self, n: int) -> int:
        ans = 0
        pre, cur = inf, 0
        while n:
            if n & 1:
                ans = max(ans, cur - pre)
                pre = cur
            cur += 1
            n >>= 1
        return ans
```

#### Java

```java
class Solution {
    public int binaryGap(int n) {
        int ans = 0;
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n % 2 == 1) {
                ans = Math.max(ans, cur - pre);
                pre = cur;
            }
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
    int binaryGap(int n) {
        int ans = 0;
        for (int pre = 100, cur = 0; n != 0; n >>= 1) {
            if (n & 1) {
                ans = max(ans, cur - pre);
                pre = cur;
            }
            ++cur;
        }
        return ans;
    }
};
```

#### Go

```go
func binaryGap(n int) (ans int) {
	for pre, cur := 100, 0; n != 0; n >>= 1 {
		if n&1 == 1 {
			ans = max(ans, cur-pre)
			pre = cur
		}
		cur++
	}
	return
}
```

#### TypeScript

```ts
function binaryGap(n: number): number {
    let ans = 0;
    for (let pre = 100, cur = 0; n; n >>= 1) {
        if (n & 1) {
            ans = Math.max(ans, cur - pre);
            pre = cur;
        }
        ++cur;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn binary_gap(mut n: i32) -> i32 {
        let mut ans = 0;
        let mut pre = 100;
        let mut cur = 0;
        while n != 0 {
            if n % 2 == 1 {
                ans = ans.max(cur - pre);
                pre = cur;
            }
            cur += 1;
            n >>= 1;
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

# [869. 重新排序得到 2 的幂](https://leetcode.cn/problems/reordered-power-of-2){#869}

{{< tabs "869" >}}

{{% tab "python" %}}
```python
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def f(x: int) -> List[int]:
            cnt = [0] * 10
            while x:
                x, v = divmod(x, 10)
                cnt[v] += 1
            return cnt

        target = f(n)
        i = 1
        while i <= 10**9:
            if f(i) == target:
                return True
            i <<= 1
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean reorderedPowerOf2(int n) {
        String target = f(n);
        for (int i = 1; i <= 1000000000; i <<= 1) {
            if (target.equals(f(i))) {
                return true;
            }
        }
        return false;
    }

    private String f(int x) {
        char[] cnt = new char[10];
        for (; x > 0; x /= 10) {
            cnt[x % 10]++;
        }
        return new String(cnt);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = f(n);
        for (int i = 1; i <= 1000000000; i <<= 1) {
            if (target == f(i)) {
                return true;
            }
        }
        return false;
    }

private:
    string f(int x) {
        char cnt[10] = {};
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        return string(cnt, cnt + 10);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reorderedPowerOf2(n int) bool {
	target := f(n)
	for i := 1; i <= 1000000000; i <<= 1 {
		if bytes.Equal(target, f(i)) {
			return true
		}
	}
	return false
}

func f(x int) []byte {
	cnt := make([]byte, 10)
	for x > 0 {
		cnt[x%10]++
		x /= 10
	}
	return cnt
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reorderedPowerOf2(n: number): boolean {
    const f = (x: number) => {
        const cnt = Array(10).fill(0);
        while (x > 0) {
            cnt[x % 10]++;
            x = (x / 10) | 0;
        }
        return cnt.join(',');
    };
    const target = f(n);
    for (let i = 1; i <= 1_000_000_000; i <<= 1) {
        if (target === f(i)) {
            return true;
        }
    }
    return false;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reordered_power_of2(n: i32) -> bool {
        fn f(mut x: i32) -> [u8; 10] {
            let mut cnt = [0u8; 10];
            while x > 0 {
                cnt[(x % 10) as usize] += 1;
                x /= 10;
            }
            cnt
        }

        let target = f(n);
        let mut i = 1i32;
        while i <= 1_000_000_000 {
            if target == f(i) {
                return true;
            }
            i <<= 1;
        }
        false
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定正整数&nbsp;<code>n</code>&nbsp;，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。</p>

<p>如果我们可以通过上述方式得到&nbsp;2 的幂，返回 <code>true</code>；否则，返回 <code>false</code>。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 10
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以在 $[1, 10^9]$ 的范围内枚举所有的 $2$ 的幂，判断它们的数字组成是否与给定的数字相同。

定义一个函数 $f(x)$，表示数字 $x$ 的数字组成。我们可以将数字 $x$ 转换为一个长度为 $10$ 的数组，或者一个按数字大小排序的字符串。

首先，我们计算给定数字 $n$ 的数字组成 $\text{target} = f(n)$。然后，我们枚举 $i$ 从 1 开始，每次将 $i$ 左移一位（相当于乘以 $2$），直到 $i$ 超过 $10^9$。对于每个 $i$，我们计算它的数字组成，并与 $\text{target}$ 进行比较。如果相同，则返回 $\text{true}$；如果枚举结束仍未找到相同的数字组成，则返回 $\text{false}$。

时间复杂度 $O(\log^2 M)$，空间复杂度 $O(\log M)$。其中 $M$ 是本题的输入范围上限 ${10}^9$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def f(x: int) -> List[int]:
            cnt = [0] * 10
            while x:
                x, v = divmod(x, 10)
                cnt[v] += 1
            return cnt

        target = f(n)
        i = 1
        while i <= 10**9:
            if f(i) == target:
                return True
            i <<= 1
        return False
```

#### Java

```java
class Solution {
    public boolean reorderedPowerOf2(int n) {
        String target = f(n);
        for (int i = 1; i <= 1000000000; i <<= 1) {
            if (target.equals(f(i))) {
                return true;
            }
        }
        return false;
    }

    private String f(int x) {
        char[] cnt = new char[10];
        for (; x > 0; x /= 10) {
            cnt[x % 10]++;
        }
        return new String(cnt);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = f(n);
        for (int i = 1; i <= 1000000000; i <<= 1) {
            if (target == f(i)) {
                return true;
            }
        }
        return false;
    }

private:
    string f(int x) {
        char cnt[10] = {};
        while (x > 0) {
            cnt[x % 10]++;
            x /= 10;
        }
        return string(cnt, cnt + 10);
    }
};
```

#### Go

```go
func reorderedPowerOf2(n int) bool {
	target := f(n)
	for i := 1; i <= 1000000000; i <<= 1 {
		if bytes.Equal(target, f(i)) {
			return true
		}
	}
	return false
}

func f(x int) []byte {
	cnt := make([]byte, 10)
	for x > 0 {
		cnt[x%10]++
		x /= 10
	}
	return cnt
}
```

#### TypeScript

```ts
function reorderedPowerOf2(n: number): boolean {
    const f = (x: number) => {
        const cnt = Array(10).fill(0);
        while (x > 0) {
            cnt[x % 10]++;
            x = (x / 10) | 0;
        }
        return cnt.join(',');
    };
    const target = f(n);
    for (let i = 1; i <= 1_000_000_000; i <<= 1) {
        if (target === f(i)) {
            return true;
        }
    }
    return false;
}
```

#### Rust

```rust
impl Solution {
    pub fn reordered_power_of2(n: i32) -> bool {
        fn f(mut x: i32) -> [u8; 10] {
            let mut cnt = [0u8; 10];
            while x > 0 {
                cnt[(x % 10) as usize] += 1;
                x /= 10;
            }
            cnt
        }

        let target = f(n);
        let mut i = 1i32;
        while i <= 1_000_000_000 {
            if target == f(i) {
                return true;
            }
            i <<= 1;
        }
        false
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
