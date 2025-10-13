---
title: "1570_两个稀疏向量的点积 🔒"
date: 2025-10-08T18:37:33+08:00
weight: 8
tags: [二分查找, 动态规划, 单调栈, 双指针, 哈希表, 图, 字符串, 并查集, 数学, 数据库, 数组, 栈, 矩阵, 记忆化搜索, 设计, 贪心]
---

{{< markmap >}}
### [1570_两个稀疏向量的点积 🔒](#1570)
#### [设计](#1570)
#### [数组](#1570)
#### [哈希表](#1570)
#### [双指针](#1570)
### [1571_仓库经理 🔒](#1571)
#### [数据库](#1571)
### [1572_矩阵对角线元素的和](#1572)
#### [数组](#1572)
#### [矩阵](#1572)
### [1573_分割字符串的方案数](#1573)
#### [数学](#1573)
#### [字符串](#1573)
### [1574_删除最短的子数组使剩余数组有序](#1574)
#### [栈](#1574)
#### [数组](#1574)
#### [双指针](#1574)
#### [二分查找](#1574)
#### [单调栈](#1574)
### [1575_统计所有可行路径](#1575)
#### [记忆化搜索](#1575)
#### [数组](#1575)
#### [动态规划](#1575)
### [1576_替换所有的问号](#1576)
#### [字符串](#1576)
### [1577_数的平方等于两数乘积的方法数](#1577)
#### [数组](#1577)
#### [哈希表](#1577)
#### [数学](#1577)
#### [双指针](#1577)
### [1578_使绳子变成彩色的最短时间](#1578)
#### [贪心](#1578)
#### [数组](#1578)
#### [字符串](#1578)
#### [动态规划](#1578)
### [1579_保证图可完全遍历](#1579)
#### [并查集](#1579)
#### [图](#1579)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1570_两个稀疏向量的点积 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 双指针
---
### 1571_仓库经理 🔒
___
#### 数据库
---
### 1572_矩阵对角线元素的和
___
#### 数组
___
#### 矩阵
---
### 1573_分割字符串的方案数
___
#### 数学
___
#### 字符串
---
### 1574_删除最短的子数组使剩余数组有序
___
#### 栈
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 单调栈
---
### 1575_统计所有可行路径
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
---
### 1576_替换所有的问号
___
#### 字符串
---
### 1577_数的平方等于两数乘积的方法数
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 双指针
---
### 1578_使绳子变成彩色的最短时间
___
#### 贪心
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 1579_保证图可完全遍历
___
#### 并查集
___
#### 图
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 单调栈 |
| 双指针 | 哈希表 | 图 |
| 字符串 | 并查集 | 数学 |
| 数据库 | 数组 | 栈 |
| 矩阵 | 记忆化搜索 | 设计 |
| 贪心 |  |  |

# [1570. 两个稀疏向量的点积 🔒](https://leetcode.cn/problems/dot-product-of-two-sparse-vectors){#1570}

{{< tabs "1570" >}}

{{% tab "python" %}}
```python
class SparseVector:
    def __init__(self, nums: List[int]):
        self.d = {i: v for i, v in enumerate(nums) if v}

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: "SparseVector") -> int:
        a, b = self.d, vec.d
        if len(b) < len(a):
            a, b = b, a
        return sum(v * b.get(i, 0) for i, v in a.items())


# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class SparseVector {
    public Map<Integer, Integer> d = new HashMap<>(128);

    SparseVector(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                d.put(i, nums[i]);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        var a = d;
        var b = vec.d;
        if (b.size() < a.size()) {
            var t = a;
            a = b;
            b = t;
        }
        int ans = 0;
        for (var e : a.entrySet()) {
            int i = e.getKey(), v = e.getValue();
            ans += v * b.getOrDefault(i, 0);
        }
        return ans;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class SparseVector {
public:
    unordered_map<int, int> d;

    SparseVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                d[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto a = d;
        auto b = vec.d;
        if (a.size() > b.size()) {
            swap(a, b);
        }
        int ans = 0;
        for (auto& [i, v] : a) {
            if (b.count(i)) {
                ans += v * b[i];
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
```
{{% /tab %}}
{{% tab "go" %}}
```go
type SparseVector struct {
	d map[int]int
}

func Constructor(nums []int) SparseVector {
	d := map[int]int{}
	for i, x := range nums {
		if x != 0 {
			d[i] = x
		}
	}
	return SparseVector{d}
}

// Return the dotProduct of two sparse vectors
func (this *SparseVector) dotProduct(vec SparseVector) (ans int) {
	a, b := this.d, vec.d
	if len(a) > len(b) {
		a, b = b, a
	}
	for i, x := range a {
		if y, has := b[i]; has {
			ans += x * y
		}
	}
	return
}

/**
 * Your SparseVector object will be instantiated and called as such:
 * v1 := Constructor(nums1);
 * v2 := Constructor(nums2);
 * ans := v1.dotProduct(v2);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class SparseVector {
    d: Map<number, number>;

    constructor(nums: number[]) {
        this.d = new Map();
        for (let i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                this.d.set(i, nums[i]);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    dotProduct(vec: SparseVector): number {
        let a = this.d;
        let b = vec.d;
        if (a.size > b.size) {
            [a, b] = [b, a];
        }
        let ans = 0;
        for (const [i, x] of a) {
            if (b.has(i)) {
                ans += x * b.get(i)!;
            }
        }
        return ans;
    }
}

/**
 * Your SparseVector object will be instantiated and called as such:
 * var v1 = new SparseVector(nums1)
 * var v2 = new SparseVector(nums1)
 * var ans = v1.dotProduct(v2)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

#[derive(Clone)]
struct SparseVector {
    d: HashMap<usize, i32>,
}

impl SparseVector {
    fn new(nums: Vec<i32>) -> Self {
        let mut d = HashMap::new();
        for (i, &x) in nums.iter().enumerate() {
            if x != 0 {
                d.insert(i, x);
            }
        }
        SparseVector { d }
    }

    fn dot_product(&self, vec: SparseVector) -> i32 {
        let (a, b) = (&self.d, &vec.d);
        let mut ans = 0;

        if a.len() > b.len() {
            return vec.dot_product(self.clone());
        }

        for (&i, &x) in a.iter() {
            if let Some(&y) = b.get(&i) {
                ans += x * y;
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

<p>给定两个稀疏向量，计算它们的点积（数量积）。</p>

<p>实现类 <code>SparseVector</code>：</p>

<ul>
	<li><code>SparseVector(nums)</code> 以向量 <code>nums</code> 初始化对象。</li>
	<li><code>dotProduct(vec)</code> 计算此向量与 <code>vec</code> 的点积。</li>
</ul>

<p><strong>稀疏向量</strong> 是指绝大多数分量为 0 的向量。你需要 <strong>高效</strong> 地存储这个向量，并计算两个稀疏向量的点积。</p>

<p><strong>进阶：</strong>当其中只有一个向量是稀疏向量时，你该如何解决此问题？</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
<strong>输出：</strong>8
<strong>解释：</strong>v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
<strong>输出：</strong>0
<strong>解释：</strong>v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
<strong>输出：</strong>6
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 <= n <= 10^5</code></li>
	<li><code>0 <= nums1[i], nums2[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表 $d$ 来存储非零元素，其中键为下标，值为对应的值。我们遍历 $\textit{nums}$，如果 $\textit{nums}[i]$ 不为 $0$，我们就将 $(i, \textit{nums}[i])$ 加入到哈希表 $d$ 中。

在计算点积时，我们遍历非零元素较少的哈希表，并判断另一个哈希表中是否存在对应的键，如果存在就将对应的值相乘并累加到答案中。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class SparseVector:
    def __init__(self, nums: List[int]):
        self.d = {i: v for i, v in enumerate(nums) if v}

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: "SparseVector") -> int:
        a, b = self.d, vec.d
        if len(b) < len(a):
            a, b = b, a
        return sum(v * b.get(i, 0) for i, v in a.items())


# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)
```

#### Java

```java
class SparseVector {
    public Map<Integer, Integer> d = new HashMap<>(128);

    SparseVector(int[] nums) {
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                d.put(i, nums[i]);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        var a = d;
        var b = vec.d;
        if (b.size() < a.size()) {
            var t = a;
            a = b;
            b = t;
        }
        int ans = 0;
        for (var e : a.entrySet()) {
            int i = e.getKey(), v = e.getValue();
            ans += v * b.getOrDefault(i, 0);
        }
        return ans;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);
```

#### C++

```cpp
class SparseVector {
public:
    unordered_map<int, int> d;

    SparseVector(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                d[i] = nums[i];
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto a = d;
        auto b = vec.d;
        if (a.size() > b.size()) {
            swap(a, b);
        }
        int ans = 0;
        for (auto& [i, v] : a) {
            if (b.count(i)) {
                ans += v * b[i];
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
```

#### Go

```go
type SparseVector struct {
	d map[int]int
}

func Constructor(nums []int) SparseVector {
	d := map[int]int{}
	for i, x := range nums {
		if x != 0 {
			d[i] = x
		}
	}
	return SparseVector{d}
}

// Return the dotProduct of two sparse vectors
func (this *SparseVector) dotProduct(vec SparseVector) (ans int) {
	a, b := this.d, vec.d
	if len(a) > len(b) {
		a, b = b, a
	}
	for i, x := range a {
		if y, has := b[i]; has {
			ans += x * y
		}
	}
	return
}

/**
 * Your SparseVector object will be instantiated and called as such:
 * v1 := Constructor(nums1);
 * v2 := Constructor(nums2);
 * ans := v1.dotProduct(v2);
 */
```

#### TypeScript

```ts
class SparseVector {
    d: Map<number, number>;

    constructor(nums: number[]) {
        this.d = new Map();
        for (let i = 0; i < nums.length; ++i) {
            if (nums[i] != 0) {
                this.d.set(i, nums[i]);
            }
        }
    }

    // Return the dotProduct of two sparse vectors
    dotProduct(vec: SparseVector): number {
        let a = this.d;
        let b = vec.d;
        if (a.size > b.size) {
            [a, b] = [b, a];
        }
        let ans = 0;
        for (const [i, x] of a) {
            if (b.has(i)) {
                ans += x * b.get(i)!;
            }
        }
        return ans;
    }
}

/**
 * Your SparseVector object will be instantiated and called as such:
 * var v1 = new SparseVector(nums1)
 * var v2 = new SparseVector(nums1)
 * var ans = v1.dotProduct(v2)
 */
```

#### Rust

```rust
use std::collections::HashMap;

#[derive(Clone)]
struct SparseVector {
    d: HashMap<usize, i32>,
}

impl SparseVector {
    fn new(nums: Vec<i32>) -> Self {
        let mut d = HashMap::new();
        for (i, &x) in nums.iter().enumerate() {
            if x != 0 {
                d.insert(i, x);
            }
        }
        SparseVector { d }
    }

    fn dot_product(&self, vec: SparseVector) -> i32 {
        let (a, b) = (&self.d, &vec.d);
        let mut ans = 0;

        if a.len() > b.len() {
            return vec.dot_product(self.clone());
        }

        for (&i, &x) in a.iter() {
            if let Some(&y) = b.get(&i) {
                ans += x * y;
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

# [1571. 仓库经理 🔒](https://leetcode.cn/problems/warehouse-manager){#1571}

{{< tabs "1571" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    name AS warehouse_name,
    SUM(width * length * height * units) AS volume
FROM
    Warehouse
    JOIN Products USING (product_id)
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Warehouse</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| name         | varchar |
| product_id   | int     |
| units        | int     |
+--------------+---------+
(name, product_id) 是该表主键(具有唯一值的列的组合).
该表的行包含了每个仓库的所有商品信息.
</pre>

<p>&nbsp;</p>

<p>表: <code>Products</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| Width         | int     |
| Length        | int     |
| Height        | int     |
+---------------+---------+
product_id 是该表主键(具有唯一值的列).
该表的行包含了每件商品以英尺为单位的尺寸(宽度, 长度和高度)信息.
</pre>

<p>&nbsp;</p>

<p>编写解决方案报告每个仓库的存货量是多少立方英尺。</p>

<p>返回结果没有顺序要求。</p>

<p>返回结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<code><strong>输入：</strong>
Warehouse 表</code>:
+------------+--------------+-------------+
| name       | product_id   | units       |
+------------+--------------+-------------+
| LCHouse1   | 1            | 1           |
| LCHouse1   | 2            | 10          |
| LCHouse1   | 3            | 5           |
| LCHouse2   | 1            | 2           |
| LCHouse2   | 2            | 2           |
| LCHouse3   | 4            | 1           |
+------------+--------------+-------------+
Products 表:
+------------+--------------+------------+----------+-----------+
| product_id | product_name | Width      | Length   | Height    |
+------------+--------------+------------+----------+-----------+
| 1          | LC-TV        | 5          | 50       | 40        |
| 2          | LC-KeyChain  | 5          | 5        | 5         |
| 3          | LC-Phone     | 2          | 10       | 10        |
| 4          | LC-T-Shirt   | 4          | 10       | 20        |
+------------+--------------+------------+----------+-----------+
<strong>输出：</strong>
+----------------+------------+
| warehouse_name<code> </code>| volume<code>   </code>  | 
+----------------+------------+
| LCHouse1       | 12250      | 
| LCHouse2       | 20250      |
| LCHouse3       | 800        |
+----------------+------------+
<strong>解释：</strong>
Id为1的商品(LC-TV)的存货量为 5x50x40 = 10000
Id为2的商品(LC-KeyChain)的存货量为 5x5x5 = 125 
Id为3的商品(LC-Phone)的存货量为 2x10x10 = 200
Id为4的商品(LC-T-Shirt)的存货量为 4x10x20 = 800
仓库LCHouse1: 1个单位的LC-TV + 10个单位的LC-KeyChain + 5个单位的LC-Phone.
&nbsp;         总存货量为: 1*10000 + 10*125  + 5*200 = 12250 立方英尺
仓库LCHouse2: 2个单位的LC-TV + 2个单位的LC-KeyChain.
&nbsp;         总存货量为: 2*10000 + 2*125 = 20250 立方英尺
仓库LCHouse3: 1个单位的LC-T-Shirt.
          总存货量为: 1*800 = 800 立方英尺.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 分组求和

我们可以使用等值连接将 `Warehouse` 表和 `Products` 表按照 `product_id` 进行连接，并按照仓库名称进行分组，然后使用 `SUM` 函数计算每个仓库的存货量。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    name AS warehouse_name,
    SUM(width * length * height * units) AS volume
FROM
    Warehouse
    JOIN Products USING (product_id)
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1572. 矩阵对角线元素的和](https://leetcode.cn/problems/matrix-diagonal-sum){#1572}

{{< tabs "1572" >}}

{{% tab "python" %}}
```python
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        ans = 0
        n = len(mat)
        for i, row in enumerate(mat):
            j = n - i - 1
            ans += row[i] + (0 if j == i else row[j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int diagonalSum(int[][] mat) {
        int ans = 0;
        int n = mat.length;
        for (int i = 0; i < n; ++i) {
            int j = n - i - 1;
            ans += mat[i][i] + (i == j ? 0 : mat[i][j]);
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
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            int j = n - i - 1;
            ans += mat[i][i] + (i == j ? 0 : mat[i][j]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func diagonalSum(mat [][]int) (ans int) {
	n := len(mat)
	for i, row := range mat {
		ans += row[i]
		if j := n - i - 1; j != i {
			ans += row[j]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function diagonalSum(mat: number[][]): number {
    let ans = 0;
    const n = mat.length;
    for (let i = 0; i < n; ++i) {
        const j = n - i - 1;
        ans += mat[i][i] + (i === j ? 0 : mat[i][j]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let n = mat.len();
        let mut ans = 0;

        for i in 0..n {
            ans += mat[i][i];
            let j = n - i - 1;
            if j != i {
                ans += mat[i][j];
            }
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int diagonalSum(int** mat, int matSize, int* matColSize) {
    int ans = 0;
    for (int i = 0; i < matSize; ++i) {
        ans += mat[i][i];
        int j = matSize - i - 1;
        if (j != i) {
            ans += mat[i][j];
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

<p>给你一个正方形矩阵 <code>mat</code>，请你返回矩阵对角线元素的和。</p>

<p>请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp; 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1572.Matrix%20Diagonal%20Sum/images/sample_1911.png" style="height:174px; width:336px" /></p>

<pre>
<strong>输入：</strong>mat = [[<strong>1</strong>,2,<strong>3</strong>],
&nbsp;           [4,<strong>5</strong>,6],
&nbsp;           [<strong>7</strong>,8,<strong>9</strong>]]
<strong>输出：</strong>25
<strong>解释：</strong>对角线的和为：1 + 5 + 9 + 3 + 7 = 25
请注意，元素 mat[1][1] = 5 只会被计算一次。
</pre>

<p><strong>示例&nbsp; 2：</strong></p>

<pre>
<strong>输入：</strong>mat = [[<strong>1</strong>,1,1,<strong>1</strong>],
&nbsp;           [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;           [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;           [<strong>1</strong>,1,1,<strong>1</strong>]]
<strong>输出：</strong>8
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>mat = [[<strong>5</strong>]]
<strong>输出：</strong>5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == mat.length == mat[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：逐行遍历

我们可以遍历矩阵的每一行 $\textit{row}[i]$，对于每一行，我们可以计算出两个对角线上的元素，即 $\textit{row}[i][i]$ 和 $\textit{row}[i][n - i - 1]$，其中 $n$ 是矩阵的行数。如果 $i = n - i - 1$，则说明当前行的对角线上只有一个元素，否则有两个元素。我们将其加到答案中即可。
遍历完所有行后，即可得到答案。

时间复杂度 $O(n)$，其中 $n$ 是矩阵的行数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        ans = 0
        n = len(mat)
        for i, row in enumerate(mat):
            j = n - i - 1
            ans += row[i] + (0 if j == i else row[j])
        return ans
```

#### Java

```java
class Solution {
    public int diagonalSum(int[][] mat) {
        int ans = 0;
        int n = mat.length;
        for (int i = 0; i < n; ++i) {
            int j = n - i - 1;
            ans += mat[i][i] + (i == j ? 0 : mat[i][j]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        for (int i = 0; i < n; ++i) {
            int j = n - i - 1;
            ans += mat[i][i] + (i == j ? 0 : mat[i][j]);
        }
        return ans;
    }
};
```

#### Go

```go
func diagonalSum(mat [][]int) (ans int) {
	n := len(mat)
	for i, row := range mat {
		ans += row[i]
		if j := n - i - 1; j != i {
			ans += row[j]
		}
	}
	return
}
```

#### TypeScript

```ts
function diagonalSum(mat: number[][]): number {
    let ans = 0;
    const n = mat.length;
    for (let i = 0; i < n; ++i) {
        const j = n - i - 1;
        ans += mat[i][i] + (i === j ? 0 : mat[i][j]);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let n = mat.len();
        let mut ans = 0;

        for i in 0..n {
            ans += mat[i][i];
            let j = n - i - 1;
            if j != i {
                ans += mat[i][j];
            }
        }

        ans
    }
}
```

#### C

```c
int diagonalSum(int** mat, int matSize, int* matColSize) {
    int ans = 0;
    for (int i = 0; i < matSize; ++i) {
        ans += mat[i][i];
        int j = matSize - i - 1;
        if (j != i) {
            ans += mat[i][j];
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

# [1573. 分割字符串的方案数](https://leetcode.cn/problems/number-of-ways-to-split-a-string){#1573}

{{< tabs "1573" >}}

{{% tab "python" %}}
```python
class Solution:
    def numWays(self, s: str) -> int:
        def find(x):
            t = 0
            for i, c in enumerate(s):
                t += int(c == '1')
                if t == x:
                    return i

        cnt, m = divmod(sum(c == '1' for c in s), 3)
        if m:
            return 0
        n = len(s)
        mod = 10**9 + 7
        if cnt == 0:
            return ((n - 1) * (n - 2) // 2) % mod
        i1, i2 = find(cnt), find(cnt + 1)
        j1, j2 = find(cnt * 2), find(cnt * 2 + 1)
        return (i2 - i1) * (j2 - j1) % (10**9 + 7)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;

    public int numWays(String s) {
        this.s = s;
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++cnt;
            }
        }
        int m = cnt % 3;
        if (m != 0) {
            return 0;
        }
        final int mod = (int) 1e9 + 7;
        if (cnt == 0) {
            return (int) (((n - 1L) * (n - 2) / 2) % mod);
        }
        cnt /= 3;
        long i1 = find(cnt), i2 = find(cnt + 1);
        long j1 = find(cnt * 2), j2 = find(cnt * 2 + 1);
        return (int) ((i2 - i1) * (j2 - j1) % mod);
    }

    private int find(int x) {
        int t = 0;
        for (int i = 0;; ++i) {
            t += s.charAt(i) == '1' ? 1 : 0;
            if (t == x) {
                return i;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numWays(string s) {
        int cnt = 0;
        for (char& c : s) {
            cnt += c == '1';
        }
        int m = cnt % 3;
        if (m) {
            return 0;
        }
        const int mod = 1e9 + 7;
        int n = s.size();
        if (cnt == 0) {
            return (n - 1LL) * (n - 2) / 2 % mod;
        }
        cnt /= 3;
        auto find = [&](int x) {
            int t = 0;
            for (int i = 0;; ++i) {
                t += s[i] == '1';
                if (t == x) {
                    return i;
                }
            }
        };
        int i1 = find(cnt), i2 = find(cnt + 1);
        int j1 = find(cnt * 2), j2 = find(cnt * 2 + 1);
        return (1LL * (i2 - i1) * (j2 - j1)) % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numWays(s string) int {
	cnt := 0
	for _, c := range s {
		if c == '1' {
			cnt++
		}
	}
	m := cnt % 3
	if m != 0 {
		return 0
	}
	const mod = 1e9 + 7
	n := len(s)
	if cnt == 0 {
		return (n - 1) * (n - 2) / 2 % mod
	}
	cnt /= 3
	find := func(x int) int {
		t := 0
		for i := 0; ; i++ {
			if s[i] == '1' {
				t++
				if t == x {
					return i
				}
			}
		}
	}
	i1, i2 := find(cnt), find(cnt+1)
	j1, j2 := find(cnt*2), find(cnt*2+1)
	return (i2 - i1) * (j2 - j1) % mod
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二进制串&nbsp;<code>s</code>&nbsp; （一个只包含 0 和 1 的字符串），我们可以将 <code>s</code>&nbsp;分割成 3 个 <strong>非空</strong>&nbsp;字符串 s1, s2, s3 （s1 + s2 + s3 = s）。</p>

<p>请你返回分割&nbsp;<code>s</code>&nbsp;的方案数，满足 s1，s2 和 s3 中字符 &#39;1&#39; 的数目相同。</p>

<p>由于答案可能很大，请将它对 10^9 + 7 取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;10101&quot;
<strong>输出：</strong>4
<strong>解释：</strong>总共有 4 种方法将 s 分割成含有 &#39;1&#39; 数目相同的三个子字符串。
&quot;1|010|1&quot;
&quot;1|01|01&quot;
&quot;10|10|1&quot;
&quot;10|1|01&quot;
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;1001&quot;
<strong>输出：</strong>0
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;0000&quot;
<strong>输出：</strong>3
<strong>解释：</strong>总共有 3 种分割 s 的方法。
&quot;0|0|00&quot;
&quot;0|00|0&quot;
&quot;00|0|0&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>s = &quot;100100010100110&quot;
<strong>输出：</strong>12
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s[i] == &#39;0&#39;</code>&nbsp;或者&nbsp;<code>s[i] == &#39;1&#39;</code></li>
	<li><code>3 &lt;= s.length &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们先遍历字符串 $s$，统计其中字符 $1$ 的个数 $cnt$，如果 $cnt$ 不能被 $3$ 整除，那么无法分割，直接返回 $0$。如果 $cnt$ 为 $0$，说明字符串中没有字符 $1$，我们可以在 $n-1$ 个位置中任意选择两个位置，将字符串分割成三个子串，那么方案数就是 $C_{n-1}^2$。

如果 $cnt \gt 0$，我们将 $cnt$ 更新为 $\frac{cnt}{3}$，即每个子串中字符 $1$ 的个数。

接下来我们找到第一个子字符串的右边界的最小下标，记为 $i_1$，第一个子字符串的右边界的最大下标（不包含），记为 $i_2$；第二个子字符串的右边界的最小下标，记为 $j_1$，第二个子字符串的右边界的最大下标（不包含），记为 $j_2$。那么方案数就是 $(i_2-i_1) \times (j_2-j_1)$。

注意答案可能很大，需要对 $10^9+7$ 取模。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为字符串 $s$ 的长度。

相似题目：

-   [927. 三等分](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0927.Three%20Equal%20Parts/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numWays(self, s: str) -> int:
        def find(x):
            t = 0
            for i, c in enumerate(s):
                t += int(c == '1')
                if t == x:
                    return i

        cnt, m = divmod(sum(c == '1' for c in s), 3)
        if m:
            return 0
        n = len(s)
        mod = 10**9 + 7
        if cnt == 0:
            return ((n - 1) * (n - 2) // 2) % mod
        i1, i2 = find(cnt), find(cnt + 1)
        j1, j2 = find(cnt * 2), find(cnt * 2 + 1)
        return (i2 - i1) * (j2 - j1) % (10**9 + 7)
```

#### Java

```java
class Solution {
    private String s;

    public int numWays(String s) {
        this.s = s;
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++cnt;
            }
        }
        int m = cnt % 3;
        if (m != 0) {
            return 0;
        }
        final int mod = (int) 1e9 + 7;
        if (cnt == 0) {
            return (int) (((n - 1L) * (n - 2) / 2) % mod);
        }
        cnt /= 3;
        long i1 = find(cnt), i2 = find(cnt + 1);
        long j1 = find(cnt * 2), j2 = find(cnt * 2 + 1);
        return (int) ((i2 - i1) * (j2 - j1) % mod);
    }

    private int find(int x) {
        int t = 0;
        for (int i = 0;; ++i) {
            t += s.charAt(i) == '1' ? 1 : 0;
            if (t == x) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numWays(string s) {
        int cnt = 0;
        for (char& c : s) {
            cnt += c == '1';
        }
        int m = cnt % 3;
        if (m) {
            return 0;
        }
        const int mod = 1e9 + 7;
        int n = s.size();
        if (cnt == 0) {
            return (n - 1LL) * (n - 2) / 2 % mod;
        }
        cnt /= 3;
        auto find = [&](int x) {
            int t = 0;
            for (int i = 0;; ++i) {
                t += s[i] == '1';
                if (t == x) {
                    return i;
                }
            }
        };
        int i1 = find(cnt), i2 = find(cnt + 1);
        int j1 = find(cnt * 2), j2 = find(cnt * 2 + 1);
        return (1LL * (i2 - i1) * (j2 - j1)) % mod;
    }
};
```

#### Go

```go
func numWays(s string) int {
	cnt := 0
	for _, c := range s {
		if c == '1' {
			cnt++
		}
	}
	m := cnt % 3
	if m != 0 {
		return 0
	}
	const mod = 1e9 + 7
	n := len(s)
	if cnt == 0 {
		return (n - 1) * (n - 2) / 2 % mod
	}
	cnt /= 3
	find := func(x int) int {
		t := 0
		for i := 0; ; i++ {
			if s[i] == '1' {
				t++
				if t == x {
					return i
				}
			}
		}
	}
	i1, i2 := find(cnt), find(cnt+1)
	j1, j2 := find(cnt*2), find(cnt*2+1)
	return (i2 - i1) * (j2 - j1) % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1574. 删除最短的子数组使剩余数组有序](https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted){#1574}

{{< tabs "1574" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        i, j = 0, n - 1
        while i + 1 < n and arr[i] <= arr[i + 1]:
            i += 1
        while j - 1 >= 0 and arr[j - 1] <= arr[j]:
            j -= 1
        if i >= j:
            return 0
        ans = min(n - i - 1, j)
        r = j
        for l in range(i + 1):
            while r < n and arr[r] < arr[l]:
                r += 1
            ans = min(ans, r - l - 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            --j;
        }
        if (i >= j) {
            return 0;
        }
        int ans = Math.min(n - i - 1, j);
        for (int l = 0, r = j; l <= i; ++l) {
            while (r < n && arr[r] < arr[l]) {
                ++r;
            }
            ans = Math.min(ans, r - l - 1);
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
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            --j;
        }
        if (i >= j) {
            return 0;
        }
        int ans = min(n - 1 - i, j);
        for (int l = 0, r = j; l <= i; ++l) {
            while (r < n && arr[r] < arr[l]) {
                ++r;
            }
            ans = min(ans, r - l - 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLengthOfShortestSubarray(arr []int) int {
	n := len(arr)
	i, j := 0, n-1
	for i+1 < n && arr[i] <= arr[i+1] {
		i++
	}
	for j-1 >= 0 && arr[j-1] <= arr[j] {
		j--
	}
	if i >= j {
		return 0
	}
	ans := min(n-i-1, j)
	r := j
	for l := 0; l <= i; l++ {
		for r < n && arr[r] < arr[l] {
			r += 1
		}
		ans = min(ans, r-l-1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLengthOfShortestSubarray(arr: number[]): number {
    let [l, r, n] = [0, arr.length - 1, arr.length];

    while (r && arr[r - 1] <= arr[r]) r--;
    if (r === 0) return 0;

    let ans = r;
    while (l < r && (!l || arr[l - 1] <= arr[l])) {
        while (r < n && arr[l] > arr[r]) r++;
        ans = Math.min(ans, r - l - 1);
        l++;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function findLengthOfShortestSubarray(arr) {
    let [l, r, n] = [0, arr.length - 1, arr.length];

    while (r && arr[r - 1] <= arr[r]) r--;
    if (r === 0) return 0;

    let ans = r;
    while (l < r && (!l || arr[l - 1] <= arr[l])) {
        while (r < n && arr[l] > arr[r]) r++;
        ans = Math.min(ans, r - l - 1);
        l++;
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

<p>给你一个整数数组 <code>arr</code>&nbsp;，请你删除一个子数组（可以为空），使得 <code>arr</code>&nbsp;中剩下的元素是 <strong>非递减</strong> 的。</p>

<p>一个子数组指的是原数组中连续的一个子序列。</p>

<p>请你返回满足题目要求的最短子数组的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3,10,4,2,3,5]
<strong>输出：</strong>3
<strong>解释：</strong>我们需要删除的最短子数组是 [10,4,2] ，长度为 3 。剩余元素形成非递减数组 [1,2,3,3,5] 。
另一个正确的解为删除子数组 [3,10,4] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [5,4,3,2,1]
<strong>输出：</strong>4
<strong>解释：</strong>由于数组是严格递减的，我们只能保留一个元素。所以我们需要删除长度为 4 的子数组，要么删除 [5,4,3,2]，要么删除 [4,3,2,1]。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>arr = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>数组已经是非递减的了，我们不需要删除任何元素。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>arr = [1]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 二分查找

我们先找出数组的最长非递减前缀和最长非递减后缀，分别记为 $\textit{nums}[0..i]$ 和 $\textit{nums}[j..n-1]$。

如果 $i \geq j$，说明数组本身就是非递减的，返回 $0$。

否则，我们可以选择删除右侧后缀，也可以选择删除左侧前缀，因此初始时答案为 $\min(n - i - 1, j)$。

接下来，我们枚举左侧前缀的最右端点 $l$，对于每个 $l$，我们可以通过二分查找，在 $\textit{nums}[j..n-1]$ 中找到第一个大于等于 $\textit{nums}[l]$ 的位置，记为 $r$，此时我们可以删除 $\textit{nums}[l+1..r-1]$，并且更新答案 $\textit{ans} = \min(\textit{ans}, r - l - 1)$。继续枚举 $l$，最终得到答案。

时间复杂度 $O(n \times \log n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        i, j = 0, n - 1
        while i + 1 < n and arr[i] <= arr[i + 1]:
            i += 1
        while j - 1 >= 0 and arr[j - 1] <= arr[j]:
            j -= 1
        if i >= j:
            return 0
        ans = min(n - i - 1, j)
        for l in range(i + 1):
            r = bisect_left(arr, arr[l], lo=j)
            ans = min(ans, r - l - 1)
        return ans
```

#### Java

```java
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            --j;
        }
        if (i >= j) {
            return 0;
        }
        int ans = Math.min(n - i - 1, j);
        for (int l = 0; l <= i; ++l) {
            int r = search(arr, arr[l], j);
            ans = Math.min(ans, r - l - 1);
        }
        return ans;
    }

    private int search(int[] arr, int x, int left) {
        int right = arr.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            --j;
        }
        if (i >= j) {
            return 0;
        }
        int ans = min(n - 1 - i, j);
        for (int l = 0; l <= i; ++l) {
            int r = lower_bound(arr.begin() + j, arr.end(), arr[l]) - arr.begin();
            ans = min(ans, r - l - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func findLengthOfShortestSubarray(arr []int) int {
	n := len(arr)
	i, j := 0, n-1
	for i+1 < n && arr[i] <= arr[i+1] {
		i++
	}
	for j-1 >= 0 && arr[j-1] <= arr[j] {
		j--
	}
	if i >= j {
		return 0
	}
	ans := min(n-i-1, j)
	for l := 0; l <= i; l++ {
		r := j + sort.SearchInts(arr[j:], arr[l])
		ans = min(ans, r-l-1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：双指针

与方法一类似，我们先找出数组的最长非递减前缀和最长非递减后缀，分别记为 $\textit{nums}[0..i]$ 和 $\textit{nums}[j..n-1]$。

如果 $i \geq j$，说明数组本身就是非递减的，返回 $0$。

否则，我们可以选择删除右侧后缀，也可以选择删除左侧前缀，因此初始时答案为 $\min(n - i - 1, j)$。

接下来，我们枚举左侧前缀的最右端点 $l$，对于每个 $l$，我们直接利用双指针找到第一个大于等于 $\textit{nums}[l]$ 的位置，记为 $r$，此时我们可以删除 $\textit{nums}[l+1..r-1]$，并且更新答案 $\textit{ans} = \min(\textit{ans}, r - l - 1)$。继续枚举 $l$，最终得到答案。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        i, j = 0, n - 1
        while i + 1 < n and arr[i] <= arr[i + 1]:
            i += 1
        while j - 1 >= 0 and arr[j - 1] <= arr[j]:
            j -= 1
        if i >= j:
            return 0
        ans = min(n - i - 1, j)
        r = j
        for l in range(i + 1):
            while r < n and arr[r] < arr[l]:
                r += 1
            ans = min(ans, r - l - 1)
        return ans
```

#### Java

```java
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            --j;
        }
        if (i >= j) {
            return 0;
        }
        int ans = Math.min(n - i - 1, j);
        for (int l = 0, r = j; l <= i; ++l) {
            while (r < n && arr[r] < arr[l]) {
                ++r;
            }
            ans = Math.min(ans, r - l - 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        while (i + 1 < n && arr[i] <= arr[i + 1]) {
            ++i;
        }
        while (j - 1 >= 0 && arr[j - 1] <= arr[j]) {
            --j;
        }
        if (i >= j) {
            return 0;
        }
        int ans = min(n - 1 - i, j);
        for (int l = 0, r = j; l <= i; ++l) {
            while (r < n && arr[r] < arr[l]) {
                ++r;
            }
            ans = min(ans, r - l - 1);
        }
        return ans;
    }
};
```

#### Go

```go
func findLengthOfShortestSubarray(arr []int) int {
	n := len(arr)
	i, j := 0, n-1
	for i+1 < n && arr[i] <= arr[i+1] {
		i++
	}
	for j-1 >= 0 && arr[j-1] <= arr[j] {
		j--
	}
	if i >= j {
		return 0
	}
	ans := min(n-i-1, j)
	r := j
	for l := 0; l <= i; l++ {
		for r < n && arr[r] < arr[l] {
			r += 1
		}
		ans = min(ans, r-l-1)
	}
	return ans
}
```

#### TypeScript

```ts
function findLengthOfShortestSubarray(arr: number[]): number {
    let [l, r, n] = [0, arr.length - 1, arr.length];

    while (r && arr[r - 1] <= arr[r]) r--;
    if (r === 0) return 0;

    let ans = r;
    while (l < r && (!l || arr[l - 1] <= arr[l])) {
        while (r < n && arr[l] > arr[r]) r++;
        ans = Math.min(ans, r - l - 1);
        l++;
    }

    return ans;
}
```

#### JavaScript

```js
function findLengthOfShortestSubarray(arr) {
    let [l, r, n] = [0, arr.length - 1, arr.length];

    while (r && arr[r - 1] <= arr[r]) r--;
    if (r === 0) return 0;

    let ans = r;
    while (l < r && (!l || arr[l - 1] <= arr[l])) {
        while (r < n && arr[l] > arr[r]) r++;
        ans = Math.min(ans, r - l - 1);
        l++;
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1575. 统计所有可行路径](https://leetcode.cn/problems/count-all-possible-routes){#1575}

{{< tabs "1575" >}}

{{% tab "python" %}}
```python
class Solution:
    def countRoutes(
        self, locations: List[int], start: int, finish: int, fuel: int
    ) -> int:
        mod = 10**9 + 7
        n = len(locations)
        f = [[0] * (fuel + 1) for _ in range(n)]
        for k in range(fuel + 1):
            f[finish][k] = 1
        for k in range(fuel + 1):
            for i in range(n):
                for j in range(n):
                    if j != i and abs(locations[i] - locations[j]) <= k:
                        f[i][k] = (
                            f[i][k] + f[j][k - abs(locations[i] - locations[j])]
                        ) % mod
        return f[start][fuel]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        final int mod = (int) 1e9 + 7;
        int n = locations.length;
        int[][] f = new int[n][fuel + 1];
        for (int k = 0; k <= fuel; ++k) {
            f[finish][k] = 1;
        }
        for (int k = 0; k <= fuel; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j != i && Math.abs(locations[i] - locations[j]) <= k) {
                        f[i][k] = (f[i][k] + f[j][k - Math.abs(locations[i] - locations[j])]) % mod;
                    }
                }
            }
        }
        return f[start][fuel];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int mod = 1e9 + 7;
        int n = locations.size();
        int f[n][fuel + 1];
        memset(f, 0, sizeof(f));
        for (int k = 0; k <= fuel; ++k) {
            f[finish][k] = 1;
        }
        for (int k = 0; k <= fuel; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j != i && abs(locations[i] - locations[j]) <= k) {
                        f[i][k] = (f[i][k] + f[j][k - abs(locations[i] - locations[j])]) % mod;
                    }
                }
            }
        }
        return f[start][fuel];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countRoutes(locations []int, start int, finish int, fuel int) int {
	n := len(locations)
	const mod = 1e9 + 7
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, fuel+1)
	}
	for k := 0; k <= fuel; k++ {
		f[finish][k] = 1
	}
	for k := 0; k <= fuel; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if j != i && abs(locations[i]-locations[j]) <= k {
					f[i][k] = (f[i][k] + f[j][k-abs(locations[i]-locations[j])]) % mod
				}
			}
		}
	}
	return f[start][fuel]
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
function countRoutes(locations: number[], start: number, finish: number, fuel: number): number {
    const n = locations.length;
    const f = Array.from({ length: n }, () => Array(fuel + 1).fill(0));
    for (let k = 0; k <= fuel; ++k) {
        f[finish][k] = 1;
    }
    const mod = 1e9 + 7;
    for (let k = 0; k <= fuel; ++k) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                if (j !== i && Math.abs(locations[i] - locations[j]) <= k) {
                    f[i][k] = (f[i][k] + f[j][k - Math.abs(locations[i] - locations[j])]) % mod;
                }
            }
        }
    }
    return f[start][fuel];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>互不相同</strong>&nbsp;的整数数组，其中&nbsp;<code>locations[i]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个城市的位置。同时给你&nbsp;<code>start</code>，<code>finish</code>&nbsp;和&nbsp;<code>fuel</code>&nbsp;分别表示出发城市、目的地城市和你初始拥有的汽油总量</p>

<p>每一步中，如果你在城市 <code>i</code>&nbsp;，你可以选择任意一个城市 <code>j</code>&nbsp;，满足 &nbsp;<code>j != i</code>&nbsp;且&nbsp;<code>0 &lt;= j &lt; locations.length</code>&nbsp;，并移动到城市&nbsp;<code>j</code>&nbsp;。从城市&nbsp;<code>i</code>&nbsp;移动到&nbsp;<code>j</code>&nbsp;消耗的汽油量为&nbsp;<code>|locations[i] - locations[j]|</code>，<code>|x|</code>&nbsp;表示&nbsp;<code>x</code>&nbsp;的绝对值。</p>

<p>请注意，&nbsp;<code>fuel</code>&nbsp;任何时刻都&nbsp;<strong>不能</strong>&nbsp;为负，且你&nbsp;<strong>可以</strong>&nbsp;经过任意城市超过一次（包括&nbsp;<code>start</code>&nbsp;和&nbsp;<code>finish</code>&nbsp;）。</p>

<p>请你返回从<em>&nbsp;</em><code>start</code>&nbsp;到&nbsp;<code>finish</code>&nbsp;所有可能路径的数目。</p>

<p>由于答案可能很大， 请将它对&nbsp;<code>10^9 + 7</code>&nbsp;取余后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>locations = [2,3,6,8,4], start = 1, finish = 3, fuel = 5
<strong>输出：</strong>4
<strong>解释：</strong>以下为所有可能路径，每一条都用了 5 单位的汽油：
1 -&gt; 3
1 -&gt; 2 -&gt; 3
1 -&gt; 4 -&gt; 3
1 -&gt; 4 -&gt; 2 -&gt; 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>locations = [4,3,1], start = 1, finish = 0, fuel = 6
<strong>输出：</strong>5
<strong>解释：</strong>以下为所有可能的路径：
1 -&gt; 0，使用汽油量为 fuel = 1
1 -&gt; 2 -&gt; 0，使用汽油量为 fuel = 5
1 -&gt; 2 -&gt; 1 -&gt; 0，使用汽油量为 fuel = 5
1 -&gt; 0 -&gt; 1 -&gt; 0，使用汽油量为 fuel = 3
1 -&gt; 0 -&gt; 1 -&gt; 0 -&gt; 1 -&gt; 0，使用汽油量为 fuel = 5
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>locations = [5,2,1], start = 0, finish = 2, fuel = 3
<strong>输出：</strong>0
<strong>解释：</strong>没有办法只用 3 单位的汽油从 0 到达 2 。因为最短路径需要 4 单位的汽油。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= locations.length &lt;= 100</code></li>
	<li><code>1 &lt;= locations[i] &lt;= 10<sup>9</sup></code></li>
	<li>所有&nbsp;<code>locations</code>&nbsp;中的整数 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>0 &lt;= start, finish &lt;&nbsp;locations.length</code></li>
	<li><code>1 &lt;= fuel &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, k)$，表示从城市 $i$ 出发，剩余汽油量为 $k$ 时，到达目的地 $finish$ 的路径数。那么答案就是 $dfs(start, fuel)$。

函数 $dfs(i, k)$ 的计算过程如下：

-   如果 $k \lt |locations[i] - locations[finish]|$，那么返回 $0$。
-   如果 $i = finish$，那么答案路径数初始时为 $1$，否则为 $0$。
-   然后，我们遍历所有城市 $j$，如果 $j \ne i$，那么我们可以从城市 $i$ 移动到城市 $j$，此时剩余汽油量为 $k - |locations[i] - locations[j]|$，那么我们可以将答案路径数加上 $dfs(j, k - |locations[i] - locations[j]|)$。
-   最后，我们返回答案路径数。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(n^2 \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别是数组 $locations$ 和 $fuel$ 的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countRoutes(
        self, locations: List[int], start: int, finish: int, fuel: int
    ) -> int:
        @cache
        def dfs(i: int, k: int) -> int:
            if k < abs(locations[i] - locations[finish]):
                return 0
            ans = int(i == finish)
            for j, x in enumerate(locations):
                if j != i:
                    ans = (ans + dfs(j, k - abs(locations[i] - x))) % mod
            return ans

        mod = 10**9 + 7
        return dfs(start, fuel)
```

#### Java

```java
class Solution {
    private int[] locations;
    private int finish;
    private int n;
    private Integer[][] f;
    private final int mod = (int) 1e9 + 7;

    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        n = locations.length;
        this.locations = locations;
        this.finish = finish;
        f = new Integer[n][fuel + 1];
        return dfs(start, fuel);
    }

    private int dfs(int i, int k) {
        if (k < Math.abs(locations[i] - locations[finish])) {
            return 0;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        int ans = i == finish ? 1 : 0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                ans = (ans + dfs(j, k - Math.abs(locations[i] - locations[j]))) % mod;
            }
        }
        return f[i][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int f[n][fuel + 1];
        memset(f, -1, sizeof(f));
        const int mod = 1e9 + 7;
        function<int(int, int)> dfs = [&](int i, int k) -> int {
            if (k < abs(locations[i] - locations[finish])) {
                return 0;
            }
            if (f[i][k] != -1) {
                return f[i][k];
            }
            int ans = i == finish;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    ans = (ans + dfs(j, k - abs(locations[i] - locations[j]))) % mod;
                }
            }
            return f[i][k] = ans;
        };
        return dfs(start, fuel);
    }
};
```

#### Go

```go
func countRoutes(locations []int, start int, finish int, fuel int) int {
	n := len(locations)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, fuel+1)
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	const mod = 1e9 + 7
	var dfs func(int, int) int
	dfs = func(i, k int) (ans int) {
		if k < abs(locations[i]-locations[finish]) {
			return 0
		}
		if f[i][k] != -1 {
			return f[i][k]
		}
		if i == finish {
			ans = 1
		}
		for j, x := range locations {
			if j != i {
				ans = (ans + dfs(j, k-abs(locations[i]-x))) % mod
			}
		}
		f[i][k] = ans
		return
	}
	return dfs(start, fuel)
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
function countRoutes(locations: number[], start: number, finish: number, fuel: number): number {
    const n = locations.length;
    const f = Array.from({ length: n }, () => Array(fuel + 1).fill(-1));
    const mod = 1e9 + 7;
    const dfs = (i: number, k: number): number => {
        if (k < Math.abs(locations[i] - locations[finish])) {
            return 0;
        }
        if (f[i][k] !== -1) {
            return f[i][k];
        }
        let ans = i === finish ? 1 : 0;
        for (let j = 0; j < n; ++j) {
            if (j !== i) {
                const x = Math.abs(locations[i] - locations[j]);
                ans = (ans + dfs(j, k - x)) % mod;
            }
        }
        return (f[i][k] = ans);
    };
    return dfs(start, fuel);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以将方法一的记忆化搜索转换为动态规划。

我们定义 $f[i][k]$ 表示从城市 $i$ 出发，剩余汽油量为 $k$ 时，到达目的地 $finish$ 的路径数。那么答案就是 $f[start][fuel]$。初始时 $f[finish][k]=1$，其余均为 $0$。

接下来，我们从小到大枚举剩余汽油量 $k$，然后枚举所有的城市 $i$，对于每个城市 $i$，我们枚举所有的城市 $j$，如果 $j \ne i$，并且 $|locations[i] - locations[j]| \le k$，那么我们可以从城市 $i$ 移动到城市 $j$，此时剩余汽油量为 $k - |locations[i] - locations[j]|$，那么我们可以将答案路径数加上 $f[j][k - |locations[i] - locations[j]|]$。

最后，我们返回答案路径数 $f[start][fuel]$ 即可。

时间复杂度 $O(n^2 \times m)$，空间复杂度 $O(n \times m)$。其中 $n$ 和 $m$ 分别是数组 $locations$ 和 $fuel$ 的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countRoutes(
        self, locations: List[int], start: int, finish: int, fuel: int
    ) -> int:
        mod = 10**9 + 7
        n = len(locations)
        f = [[0] * (fuel + 1) for _ in range(n)]
        for k in range(fuel + 1):
            f[finish][k] = 1
        for k in range(fuel + 1):
            for i in range(n):
                for j in range(n):
                    if j != i and abs(locations[i] - locations[j]) <= k:
                        f[i][k] = (
                            f[i][k] + f[j][k - abs(locations[i] - locations[j])]
                        ) % mod
        return f[start][fuel]
```

#### Java

```java
class Solution {
    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        final int mod = (int) 1e9 + 7;
        int n = locations.length;
        int[][] f = new int[n][fuel + 1];
        for (int k = 0; k <= fuel; ++k) {
            f[finish][k] = 1;
        }
        for (int k = 0; k <= fuel; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j != i && Math.abs(locations[i] - locations[j]) <= k) {
                        f[i][k] = (f[i][k] + f[j][k - Math.abs(locations[i] - locations[j])]) % mod;
                    }
                }
            }
        }
        return f[start][fuel];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        const int mod = 1e9 + 7;
        int n = locations.size();
        int f[n][fuel + 1];
        memset(f, 0, sizeof(f));
        for (int k = 0; k <= fuel; ++k) {
            f[finish][k] = 1;
        }
        for (int k = 0; k <= fuel; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j != i && abs(locations[i] - locations[j]) <= k) {
                        f[i][k] = (f[i][k] + f[j][k - abs(locations[i] - locations[j])]) % mod;
                    }
                }
            }
        }
        return f[start][fuel];
    }
};
```

#### Go

```go
func countRoutes(locations []int, start int, finish int, fuel int) int {
	n := len(locations)
	const mod = 1e9 + 7
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, fuel+1)
	}
	for k := 0; k <= fuel; k++ {
		f[finish][k] = 1
	}
	for k := 0; k <= fuel; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if j != i && abs(locations[i]-locations[j]) <= k {
					f[i][k] = (f[i][k] + f[j][k-abs(locations[i]-locations[j])]) % mod
				}
			}
		}
	}
	return f[start][fuel]
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
function countRoutes(locations: number[], start: number, finish: number, fuel: number): number {
    const n = locations.length;
    const f = Array.from({ length: n }, () => Array(fuel + 1).fill(0));
    for (let k = 0; k <= fuel; ++k) {
        f[finish][k] = 1;
    }
    const mod = 1e9 + 7;
    for (let k = 0; k <= fuel; ++k) {
        for (let i = 0; i < n; ++i) {
            for (let j = 0; j < n; ++j) {
                if (j !== i && Math.abs(locations[i] - locations[j]) <= k) {
                    f[i][k] = (f[i][k] + f[j][k - Math.abs(locations[i] - locations[j])]) % mod;
                }
            }
        }
    }
    return f[start][fuel];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1576. 替换所有的问号](https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters){#1576}

{{< tabs "1576" >}}

{{% tab "python" %}}
```python
class Solution:
    def modifyString(self, s: str) -> str:
        s = list(s)
        n = len(s)
        for i in range(n):
            if s[i] == "?":
                for c in "abc":
                    if (i and s[i - 1] == c) or (i + 1 < n and s[i + 1] == c):
                        continue
                    s[i] = c
                    break
        return "".join(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String modifyString(String s) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        for (int i = 0; i < n; ++i) {
            if (cs[i] == '?') {
                for (char c = 'a'; c <= 'c'; ++c) {
                    if ((i > 0 && cs[i - 1] == c) || (i + 1 < n && cs[i + 1] == c)) {
                        continue;
                    }
                    cs[i] = c;
                    break;
                }
            }
        }
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char c : "abc") {
                    if ((i && s[i - 1] == c) || (i + 1 < n && s[i + 1] == c)) {
                        continue;
                    }
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func modifyString(s string) string {
	n := len(s)
	cs := []byte(s)
	for i := range s {
		if cs[i] == '?' {
			for c := byte('a'); c <= byte('c'); c++ {
				if (i > 0 && cs[i-1] == c) || (i+1 < n && cs[i+1] == c) {
					continue
				}
				cs[i] = c
				break
			}
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function modifyString(s: string): string {
    const cs = s.split('');
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        if (cs[i] === '?') {
            for (const c of 'abc') {
                if ((i > 0 && cs[i - 1] === c) || (i + 1 < n && cs[i + 1] === c)) {
                    continue;
                }
                cs[i] = c;
                break;
            }
        }
    }
    return cs.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个仅包含小写英文字母和 <code>'?'</code> 字符的字符串 <code>s</code>，请你将所有的 <code>'?'</code> 转换为若干小写字母，使最终的字符串不包含任何 <strong>连续重复</strong> 的字符。</p>

<p>注意：你 <strong>不能</strong> 修改非 <code>'?'</code> 字符。</p>

<p>题目测试用例保证 <strong>除</strong> <code>'?'</code> 字符 <strong>之外</strong>，不存在连续重复的字符。</p>

<p>在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "?zs"
<strong>输出：</strong>"azs"
<strong>解释：</strong>该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ubv?w"
<strong>输出：</strong>"ubvaw"
<strong>解释：</strong>该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>
	<p><code>1 &lt;= s.length&nbsp;&lt;= 100</code></p>
	</li>
	<li>
	<p><code>s</code> 仅包含小写英文字母和 <code>'?'</code> 字符</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历字符串，对于每个位置，如果该位置是 `?`，则枚举字符 `'a'`、`'b'`、`'c'`，如果该字符 $c$ 与前后字符都不相同，则将该位置替换为该字符，否则继续枚举下一个字符。

遍历结束后，返回字符串即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串的长度。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def modifyString(self, s: str) -> str:
        s = list(s)
        n = len(s)
        for i in range(n):
            if s[i] == "?":
                for c in "abc":
                    if (i and s[i - 1] == c) or (i + 1 < n and s[i + 1] == c):
                        continue
                    s[i] = c
                    break
        return "".join(s)
```

#### Java

```java
class Solution {
    public String modifyString(String s) {
        char[] cs = s.toCharArray();
        int n = cs.length;
        for (int i = 0; i < n; ++i) {
            if (cs[i] == '?') {
                for (char c = 'a'; c <= 'c'; ++c) {
                    if ((i > 0 && cs[i - 1] == c) || (i + 1 < n && cs[i + 1] == c)) {
                        continue;
                    }
                    cs[i] = c;
                    break;
                }
            }
        }
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char c : "abc") {
                    if ((i && s[i - 1] == c) || (i + 1 < n && s[i + 1] == c)) {
                        continue;
                    }
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};
```

#### Go

```go
func modifyString(s string) string {
	n := len(s)
	cs := []byte(s)
	for i := range s {
		if cs[i] == '?' {
			for c := byte('a'); c <= byte('c'); c++ {
				if (i > 0 && cs[i-1] == c) || (i+1 < n && cs[i+1] == c) {
					continue
				}
				cs[i] = c
				break
			}
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function modifyString(s: string): string {
    const cs = s.split('');
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        if (cs[i] === '?') {
            for (const c of 'abc') {
                if ((i > 0 && cs[i - 1] === c) || (i + 1 < n && cs[i + 1] === c)) {
                    continue;
                }
                cs[i] = c;
                break;
            }
        }
    }
    return cs.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1577. 数的平方等于两数乘积的方法数](https://leetcode.cn/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers){#1577}

{{< tabs "1577" >}}

{{% tab "python" %}}
```python
class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        def cal(nums: List[int], cnt: Counter) -> int:
            ans = 0
            for x in nums:
                for y, v1 in cnt.items():
                    z = x * x // y
                    if y * z == x * x:
                        v2 = cnt[z]
                        ans += v1 * (v2 - int(y == z))
            return ans // 2

        cnt1 = Counter(nums1)
        cnt2 = Counter(nums2)
        return cal(nums1, cnt2) + cal(nums2, cnt1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        var cnt1 = count(nums1);
        var cnt2 = count(nums2);
        return cal(cnt1, nums2) + cal(cnt2, nums1);
    }

    private Map<Integer, Integer> count(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        return cnt;
    }

    private int cal(Map<Integer, Integer> cnt, int[] nums) {
        long ans = 0;
        for (int x : nums) {
            for (var e : cnt.entrySet()) {
                int y = e.getKey(), v1 = e.getValue();
                int z = (int) (1L * x * x / y);
                if (y * z == x * x) {
                    int v2 = cnt.getOrDefault(z, 0);
                    ans += v1 * (y == z ? v2 - 1 : v2);
                }
            }
        }
        return (int) (ans / 2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        auto cnt1 = count(nums1);
        auto cnt2 = count(nums2);
        return cal(cnt1, nums2) + cal(cnt2, nums1);
    }

    unordered_map<long long, int> count(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                cnt[(long long) nums[i] * nums[j]]++;
            }
        }
        return cnt;
    }

    int cal(unordered_map<long long, int>& cnt, vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans += cnt[(long long) x * x];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numTriplets(nums1 []int, nums2 []int) int {
	cnt1 := count(nums1)
	cnt2 := count(nums2)
	return cal(cnt1, nums2) + cal(cnt2, nums1)
}

func count(nums []int) map[int]int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	return cnt
}

func cal(cnt map[int]int, nums []int) (ans int) {
	for _, x := range nums {
		for y, v1 := range cnt {
			z := x * x / y
			if y*z == x*x {
				if v2, ok := cnt[z]; ok {
					if y == z {
						v2--
					}
					ans += v1 * v2
				}
			}
		}
	}
	ans /= 2
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numTriplets(nums1: number[], nums2: number[]): number {
    const cnt1 = count(nums1);
    const cnt2 = count(nums2);
    return cal(cnt1, nums2) + cal(cnt2, nums1);
}

function count(nums: number[]): Map<number, number> {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    return cnt;
}

function cal(cnt: Map<number, number>, nums: number[]): number {
    let ans: number = 0;
    for (const x of nums) {
        for (const [y, v1] of cnt) {
            const z = Math.floor((x * x) / y);
            if (y * z == x * x) {
                const v2 = cnt.get(z) || 0;
                ans += v1 * (y === z ? v2 - 1 : v2);
            }
        }
    }
    return ans / 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code> ，请你返回根据以下规则形成的三元组的数目（类型 1 和类型 2 ）：</p>

<ul>
	<li>类型 1：三元组 <code>(i, j, k)</code> ，如果 <code>nums1[i]<sup>2</sup>&nbsp;== nums2[j] * nums2[k]</code> 其中 <code>0 &lt;= i &lt; nums1.length</code> 且 <code>0 &lt;= j &lt; k &lt; nums2.length</code></li>
	<li>类型 2：三元组 <code>(i, j, k)</code> ，如果 <code>nums2[i]<sup>2</sup>&nbsp;== nums1[j] * nums1[k]</code> 其中 <code>0 &lt;= i &lt; nums2.length</code> 且 <code>0 &lt;= j &lt; k &lt; nums1.length</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums1 = [7,4], nums2 = [5,2,8,9]
<strong>输出：</strong>1
<strong>解释：</strong>类型 1：(1,1,2), nums1[1]^2 = nums2[1] * nums2[2] (4^2 = 2 * 8)</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums1 = [1,1], nums2 = [1,1,1]
<strong>输出：</strong>9
<strong>解释：</strong>所有三元组都符合题目要求，因为 1^2 = 1 * 1
类型 1：(0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2), nums1[i]^2 = nums2[j] * nums2[k]
类型 2：(0,0,1), (1,0,1), (2,0,1), nums2[i]^2 = nums1[j] * nums1[k]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums1 = [7,7,8,3], nums2 = [1,2,9,7]
<strong>输出：</strong>2
<strong>解释：</strong>有两个符合题目要求的三元组
类型 1：(3,0,2), nums1[3]^2 = nums2[0] * nums2[2]
类型 2：(3,0,1), nums2[3]^2 = nums1[0] * nums1[1]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>nums1 = [4,7,9,11,23], nums2 = [3,5,1024,12,18]
<strong>输出：</strong>0
<strong>解释：</strong>不存在符合题目要求的三元组
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10^5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们用哈希表 $\textit{cnt1}$ 统计 $\textit{nums1}$ 中每个数对 $(\textit{nums}[j], \textit{nums}[k])$ 出现的次数，其中 $0 \leq j \lt k < m$，其中 $m$ 为数组 $\textit{nums1}$ 的长度。用哈希表 $\textit{cnt2}$ 统计 $\textit{nums2}$ 中每个数对 $(\textit{nums}[j], \textit{nums}[k])$ 出现的次数，其中 $0 \leq j \lt k < n$，其中 $n$ 为数组 $\textit{nums2}$ 的长度。

接下来，我们枚举数组 $\textit{nums1}$ 中的每个数 $x$，计算 $\textit{cnt2}[x^2]$ 的值，即 $\textit{nums2}$ 中有多少对数 $(\textit{nums}[j], \textit{nums}[k])$ 满足 $\textit{nums}[j] \times \textit{nums}[k] = x^2$。同理，我们枚举数组 $\textit{nums2}$ 中的每个数 $x$，计算 $\textit{cnt1}[x^2]$ 的值，即 $\textit{nums1}$ 中有多少对数 $(\textit{nums}[j], \textit{nums}[k])$ 满足 $\textit{nums}[j] \times \textit{nums}[k] = x^2$，最后将两者相加返回即可。

时间复杂度 $O(m^2 + n^2 + m + n)$，空间复杂度 $O(m^2 + n^2)$。其中 $m$ 和 $n$ 分别为数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        def count(nums: List[int]) -> Counter:
            cnt = Counter()
            for j in range(len(nums)):
                for k in range(j + 1, len(nums)):
                    cnt[nums[j] * nums[k]] += 1
            return cnt

        def cal(nums: List[int], cnt: Counter) -> int:
            return sum(cnt[x * x] for x in nums)

        cnt1 = count(nums1)
        cnt2 = count(nums2)
        return cal(nums1, cnt2) + cal(nums2, cnt1)
```

#### Java

```java
class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        var cnt1 = count(nums1);
        var cnt2 = count(nums2);
        return cal(cnt1, nums2) + cal(cnt2, nums1);
    }

    private Map<Long, Integer> count(int[] nums) {
        Map<Long, Integer> cnt = new HashMap<>();
        int n = nums.length;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                long x = (long) nums[j] * nums[k];
                cnt.merge(x, 1, Integer::sum);
            }
        }
        return cnt;
    }

    private int cal(Map<Long, Integer> cnt, int[] nums) {
        int ans = 0;
        for (int x : nums) {
            long y = (long) x * x;
            ans += cnt.getOrDefault(y, 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        auto cnt1 = count(nums1);
        auto cnt2 = count(nums2);
        return cal(cnt1, nums2) + cal(cnt2, nums1);
    }

    unordered_map<long long, int> count(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                cnt[(long long) nums[i] * nums[j]]++;
            }
        }
        return cnt;
    }

    int cal(unordered_map<long long, int>& cnt, vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            ans += cnt[(long long) x * x];
        }
        return ans;
    }
};
```

#### Go

```go
func numTriplets(nums1 []int, nums2 []int) int {
	cnt1 := count(nums1)
	cnt2 := count(nums2)
	return cal(cnt1, nums2) + cal(cnt2, nums1)
}

func count(nums []int) map[int]int {
	cnt := map[int]int{}
	for j, x := range nums {
		for _, y := range nums[j+1:] {
			cnt[x*y]++
		}
	}
	return cnt
}

func cal(cnt map[int]int, nums []int) (ans int) {
	for _, x := range nums {
		ans += cnt[x*x]
	}
	return
}
```

#### TypeScript

```ts
function numTriplets(nums1: number[], nums2: number[]): number {
    const cnt1 = count(nums1);
    const cnt2 = count(nums2);
    return cal(cnt1, nums2) + cal(cnt2, nums1);
}

function count(nums: number[]): Map<number, number> {
    const cnt: Map<number, number> = new Map();
    for (let j = 0; j < nums.length; ++j) {
        for (let k = j + 1; k < nums.length; ++k) {
            const x = nums[j] * nums[k];
            cnt.set(x, (cnt.get(x) || 0) + 1);
        }
    }
    return cnt;
}

function cal(cnt: Map<number, number>, nums: number[]): number {
    return nums.reduce((acc, x) => acc + (cnt.get(x * x) || 0), 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 枚举优化

我们用哈希表 $\textit{cnt1}$ 统计 $\textit{nums1}$ 中每个数出现的次数，用哈希表 $\textit{cnt2}$ 统计 $\textit{nums2}$ 中每个数出现的次数。

接下来，我们枚举数组 $\textit{nums1}$ 中的每个数 $x$，然后枚举 $\textit{cnt2}$ 中的每个数对 $(y, v1)$，其中 $y$ 为 $\textit{cnt2}$ 的键，$v1$ 为 $\textit{cnt2}$ 的值。我们计算 $z = x^2 / y$，如果 $y \times z = x^2$，此时如果 $y = z$，说明 $y$ 和 $z$ 是同一个数，那么 $v1 = v2$，从 $v1$ 个数中任选两个数的方案数为 $v1 \times (v1 - 1) = v1 \times (v2 - 1)$；如果 $y \neq z$，那么 $v1$ 个数中任选两个数的方案数为 $v1 \times v2$。最后将所有方案数相加并除以 $2$ 即可。这里除以 $2$ 是因为我们统计的是对数对 $(j, k)$ 的方案数，而实际上 $(j, k)$ 和 $(k, j)$ 是同一种方案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为数组 $\textit{nums1}$ 和 $\textit{nums2}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        def cal(nums: List[int], cnt: Counter) -> int:
            ans = 0
            for x in nums:
                for y, v1 in cnt.items():
                    z = x * x // y
                    if y * z == x * x:
                        v2 = cnt[z]
                        ans += v1 * (v2 - int(y == z))
            return ans // 2

        cnt1 = Counter(nums1)
        cnt2 = Counter(nums2)
        return cal(nums1, cnt2) + cal(nums2, cnt1)
```

#### Java

```java
class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        var cnt1 = count(nums1);
        var cnt2 = count(nums2);
        return cal(cnt1, nums2) + cal(cnt2, nums1);
    }

    private Map<Integer, Integer> count(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        return cnt;
    }

    private int cal(Map<Integer, Integer> cnt, int[] nums) {
        long ans = 0;
        for (int x : nums) {
            for (var e : cnt.entrySet()) {
                int y = e.getKey(), v1 = e.getValue();
                int z = (int) (1L * x * x / y);
                if (y * z == x * x) {
                    int v2 = cnt.getOrDefault(z, 0);
                    ans += v1 * (y == z ? v2 - 1 : v2);
                }
            }
        }
        return (int) (ans / 2);
    }
}
```

#### Go

```go
func numTriplets(nums1 []int, nums2 []int) int {
	cnt1 := count(nums1)
	cnt2 := count(nums2)
	return cal(cnt1, nums2) + cal(cnt2, nums1)
}

func count(nums []int) map[int]int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	return cnt
}

func cal(cnt map[int]int, nums []int) (ans int) {
	for _, x := range nums {
		for y, v1 := range cnt {
			z := x * x / y
			if y*z == x*x {
				if v2, ok := cnt[z]; ok {
					if y == z {
						v2--
					}
					ans += v1 * v2
				}
			}
		}
	}
	ans /= 2
	return
}
```

#### TypeScript

```ts
function numTriplets(nums1: number[], nums2: number[]): number {
    const cnt1 = count(nums1);
    const cnt2 = count(nums2);
    return cal(cnt1, nums2) + cal(cnt2, nums1);
}

function count(nums: number[]): Map<number, number> {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    return cnt;
}

function cal(cnt: Map<number, number>, nums: number[]): number {
    let ans: number = 0;
    for (const x of nums) {
        for (const [y, v1] of cnt) {
            const z = Math.floor((x * x) / y);
            if (y * z == x * x) {
                const v2 = cnt.get(z) || 0;
                ans += v1 * (y === z ? v2 - 1 : v2);
            }
        }
    }
    return ans / 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1578. 使绳子变成彩色的最短时间](https://leetcode.cn/problems/minimum-time-to-make-rope-colorful){#1578}

{{< tabs "1578" >}}

{{% tab "python" %}}
```python
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans = i = 0
        n = len(colors)
        while i < n:
            j = i
            s = mx = 0
            while j < n and colors[j] == colors[i]:
                s += neededTime[j]
                if mx < neededTime[j]:
                    mx = neededTime[j]
                j += 1
            if j - i > 1:
                ans += s - mx
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minCost(String colors, int[] neededTime) {
        int ans = 0;
        int n = neededTime.length;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            int s = 0, mx = 0;
            while (j < n && colors.charAt(j) == colors.charAt(i)) {
                s += neededTime[j];
                mx = Math.max(mx, neededTime[j]);
                ++j;
            }
            if (j - i > 1) {
                ans += s - mx;
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
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            int s = 0, mx = 0;
            while (j < n && colors[j] == colors[i]) {
                s += neededTime[j];
                mx = max(mx, neededTime[j]);
                ++j;
            }
            if (j - i > 1) {
                ans += s - mx;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minCost(colors string, neededTime []int) (ans int) {
	n := len(colors)
	for i, j := 0, 0; i < n; i = j {
		j = i
		s, mx := 0, 0
		for j < n && colors[j] == colors[i] {
			s += neededTime[j]
			if mx < neededTime[j] {
				mx = neededTime[j]
			}
			j++
		}
		if j-i > 1 {
			ans += s - mx
		}
	}
	return
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Alice 把 <code>n</code> 个气球排列在一根绳子上。给你一个下标从 <strong>0</strong> 开始的字符串 <code>colors</code> ，其中 <code>colors[i]</code> 是第 <code>i</code> 个气球的颜色。</p>

<p>Alice 想要把绳子装扮成 <b>五颜六色的</b>&nbsp;，且她不希望两个连续的气球涂着相同的颜色，所以她喊来 Bob 帮忙。Bob 可以从绳子上移除一些气球使绳子变成 <strong>彩色</strong> 。给你一个 <strong>下标从 0 开始&nbsp;</strong>的整数数组 <code>neededTime</code> ，其中 <code>neededTime[i]</code> 是 Bob 从绳子上移除第 <code>i</code> 个气球需要的时间（以秒为单位）。</p>

<p>返回 Bob 使绳子变成 <strong>彩色</strong> 需要的 <strong>最少时间</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1578.Minimum%20Time%20to%20Make%20Rope%20Colorful/images/ballon1.jpg" style="width: 404px; height: 243px;" />
<pre>
<strong>输入：</strong>colors = "abaac", neededTime = [1,2,3,4,5]
<strong>输出：</strong>3
<strong>解释：</strong>在上图中，'a' 是蓝色，'b' 是红色且 'c' 是绿色。
Bob 可以移除下标 2 的蓝色气球。这将花费 3 秒。
移除后，不存在两个连续的气球涂着相同的颜色。总时间 = 3 。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1578.Minimum%20Time%20to%20Make%20Rope%20Colorful/images/balloon2.jpg" style="width: 244px; height: 243px;" />
<pre>
<strong>输入：</strong>colors = "abc", neededTime = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>绳子已经是彩色的，Bob 不需要从绳子上移除任何气球。
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1578.Minimum%20Time%20to%20Make%20Rope%20Colorful/images/balloon3.jpg" style="width: 404px; height: 243px;" />
<pre>
<strong>输入：</strong>colors = "aabaa", neededTime = [1,2,3,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>Bob 会移除下标 0 和下标 4 处的气球。这两个气球各需要 1 秒来移除。
移除后，不存在两个连续的气球涂着相同的颜色。总时间 = 1 + 1 = 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == colors.length == neededTime.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= neededTime[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>colors</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 贪心

我们可以用双指针指向当前连续相同颜色的气球的首尾，然后计算出当前连续相同颜色的气球的总时间 $s$，以及最大的时间 $mx$。如果当前连续相同颜色的气球个数大于 $1$，那么我们可以贪心地选择保留时间最大的气球，然后移除其它相同颜色的气球，耗时 $s - mx$，累加到答案中。接下来继续遍历，直到遍历完所有气球。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为气球的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans = i = 0
        n = len(colors)
        while i < n:
            j = i
            s = mx = 0
            while j < n and colors[j] == colors[i]:
                s += neededTime[j]
                if mx < neededTime[j]:
                    mx = neededTime[j]
                j += 1
            if j - i > 1:
                ans += s - mx
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int minCost(String colors, int[] neededTime) {
        int ans = 0;
        int n = neededTime.length;
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            int s = 0, mx = 0;
            while (j < n && colors.charAt(j) == colors.charAt(i)) {
                s += neededTime[j];
                mx = Math.max(mx, neededTime[j]);
                ++j;
            }
            if (j - i > 1) {
                ans += s - mx;
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
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        for (int i = 0, j = 0; i < n; i = j) {
            j = i;
            int s = 0, mx = 0;
            while (j < n && colors[j] == colors[i]) {
                s += neededTime[j];
                mx = max(mx, neededTime[j]);
                ++j;
            }
            if (j - i > 1) {
                ans += s - mx;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minCost(colors string, neededTime []int) (ans int) {
	n := len(colors)
	for i, j := 0, 0; i < n; i = j {
		j = i
		s, mx := 0, 0
		for j < n && colors[j] == colors[i] {
			s += neededTime[j]
			if mx < neededTime[j] {
				mx = neededTime[j]
			}
			j++
		}
		if j-i > 1 {
			ans += s - mx
		}
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1579. 保证图可完全遍历](https://leetcode.cn/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable){#1579}

{{< tabs "1579" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n
        self.cnt = n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a - 1), self.find(b - 1)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        self.cnt -= 1
        return True


class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        ufa = UnionFind(n)
        ufb = UnionFind(n)
        ans = 0
        for t, u, v in edges:
            if t == 3:
                if ufa.union(u, v):
                    ufb.union(u, v)
                else:
                    ans += 1
        for t, u, v in edges:
            if t == 1:
                ans += not ufa.union(u, v)
            if t == 2:
                ans += not ufb.union(u, v)
        return ans if ufa.cnt == 1 and ufb.cnt == 1 else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private int[] p;
    private int[] size;
    public int cnt;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        cnt = n;
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a - 1), pb = find(b - 1);
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
        --cnt;
        return true;
    }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind ufa = new UnionFind(n);
        UnionFind ufb = new UnionFind(n);
        int ans = 0;
        for (var e : edges) {
            int t = e[0], u = e[1], v = e[2];
            if (t == 3) {
                if (ufa.union(u, v)) {
                    ufb.union(u, v);
                } else {
                    ++ans;
                }
            }
        }
        for (var e : edges) {
            int t = e[0], u = e[1], v = e[2];
            if (t == 1 && !ufa.union(u, v)) {
                ++ans;
            }
            if (t == 2 && !ufb.union(u, v)) {
                ++ans;
            }
        }
        return ufa.cnt == 1 && ufb.cnt == 1 ? ans : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    int cnt;

    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
        cnt = n;
    }

    bool unite(int a, int b) {
        int pa = find(a - 1), pb = find(b - 1);
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
        --cnt;
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n);
        UnionFind ufb(n);
        int ans = 0;
        for (auto& e : edges) {
            int t = e[0], u = e[1], v = e[2];
            if (t == 3) {
                if (ufa.unite(u, v)) {
                    ufb.unite(u, v);
                } else {
                    ++ans;
                }
            }
        }
        for (auto& e : edges) {
            int t = e[0], u = e[1], v = e[2];
            ans += t == 1 && !ufa.unite(u, v);
            ans += t == 2 && !ufb.unite(u, v);
        }
        return ufa.cnt == 1 && ufb.cnt == 1 ? ans : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
	cnt     int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size, n}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a-1), uf.find(b-1)
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
	uf.cnt--
	return true
}

func maxNumEdgesToRemove(n int, edges [][]int) (ans int) {
	ufa := newUnionFind(n)
	ufb := newUnionFind(n)
	for _, e := range edges {
		t, u, v := e[0], e[1], e[2]
		if t == 3 {
			if ufa.union(u, v) {
				ufb.union(u, v)
			} else {
				ans++
			}
		}
	}
	for _, e := range edges {
		t, u, v := e[0], e[1], e[2]
		if t == 1 && !ufa.union(u, v) {
			ans++
		}
		if t == 2 && !ufb.union(u, v) {
			ans++
		}
	}
	if ufa.cnt == 1 && ufb.cnt == 1 {
		return
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

<p>Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3&nbsp; 种类型的边：</p>

<ul>
	<li>类型 1：只能由 Alice 遍历。</li>
	<li>类型 2：只能由 Bob 遍历。</li>
	<li>类型 3：Alice 和 Bob 都可以遍历。</li>
</ul>

<p>给你一个数组 <code>edges</code> ，其中 <code>edges[i] = [type<sub>i</sub>, u<sub>i</sub>, v<sub>i</sub>]</code>&nbsp;表示节点 <code>u<sub>i</sub></code> 和 <code>v<sub>i</sub></code> 之间存在类型为 <code>type<sub>i</sub></code> 的双向边。请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。</p>

<p>返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1579.Remove%20Max%20Number%20of%20Edges%20to%20Keep%20Graph%20Fully%20Traversable/images/5510ex1.png" style="height: 191px; width: 179px;"></strong></p>

<pre><strong>输入：</strong>n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
<strong>输出：</strong>2
<strong>解释：</strong>如果删除<strong> </strong>[1,1,2] 和 [1,1,3] 这两条边，Alice 和 Bob 仍然可以完全遍历这个图。再删除任何其他的边都无法保证图可以完全遍历。所以可以删除的最大边数是 2 。
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1579.Remove%20Max%20Number%20of%20Edges%20to%20Keep%20Graph%20Fully%20Traversable/images/5510ex2.png" style="height: 190px; width: 178px;"></strong></p>

<pre><strong>输入：</strong>n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
<strong>输出：</strong>0
<strong>解释：</strong>注意，删除任何一条边都会使 Alice 和 Bob 无法完全遍历这个图。
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1579.Remove%20Max%20Number%20of%20Edges%20to%20Keep%20Graph%20Fully%20Traversable/images/5510ex3.png" style="height: 190px; width: 178px;"></strong></p>

<pre><strong>输入：</strong>n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
<strong>输出：</strong>-1
<strong>解释：</strong>在当前图中，Alice 无法从其他节点到达节点 4 。类似地，Bob 也不能达到节点 1 。因此，图无法完全遍历。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= edges.length &lt;= min(10^5, 3 * n * (n-1) / 2)</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>1 &lt;= edges[i][0] &lt;= 3</code></li>
	<li><code>1 &lt;= edges[i][1] &lt; edges[i][2] &lt;= n</code></li>
	<li>所有元组 <code>(type<sub>i</sub>, u<sub>i</sub>, v<sub>i</sub>)</code> 互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 并查集

题目要求我们删除最多数目的边，使得 Alice 和 Bob 都可以遍历整个图。也即是说，我们需要保留尽可能少的边，并且要求这些边能够使得 Alice 和 Bob 都可以遍历整个图。

我们可以用两个并查集 $ufa$ 和 $ufb$ 分别维护 Alice 和 Bob 的遍历情况。

接下来，我们优先遍历公共边，即 $type=3$ 的边。对于每一条公共边的两个端点 $u$ 和 $v$，如果这两个点已经在同一个连通分量中，那么我们就可以删去这条边，因此答案加一；否则我们就将这两个点合并，即执行 $ufa.union(u, v)$ 和 $ufb.union(u, v)$。

然后，我们再遍历 Alice 独有的边，即 $type=1$ 的边。对于每一条 Alice 独有的边的两个端点 $u$ 和 $v$，如果这两个点已经在同一个连通分量中，那么我们就可以删去这条边，答案加一；否则我们就将这两个点合并，即执行 $ufa.union(u, v)$。同理，对于 Bob 独有的边，我们也可以执行相同的操作。

最后，如果 Alice 和 Bob 都可以遍历整个图，那么答案就是我们删除的边数；否则答案就是 $-1$。

时间复杂度 $O(m \times \alpha(n))$，空间复杂度 $O(n)$。其中 $m$ 是边数，而 $\alpha(n)$ 是阿克曼函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n
        self.cnt = n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a - 1), self.find(b - 1)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        self.cnt -= 1
        return True


class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        ufa = UnionFind(n)
        ufb = UnionFind(n)
        ans = 0
        for t, u, v in edges:
            if t == 3:
                if ufa.union(u, v):
                    ufb.union(u, v)
                else:
                    ans += 1
        for t, u, v in edges:
            if t == 1:
                ans += not ufa.union(u, v)
            if t == 2:
                ans += not ufb.union(u, v)
        return ans if ufa.cnt == 1 and ufb.cnt == 1 else -1
```

#### Java

```java
class UnionFind {
    private int[] p;
    private int[] size;
    public int cnt;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        cnt = n;
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a - 1), pb = find(b - 1);
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
        --cnt;
        return true;
    }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind ufa = new UnionFind(n);
        UnionFind ufb = new UnionFind(n);
        int ans = 0;
        for (var e : edges) {
            int t = e[0], u = e[1], v = e[2];
            if (t == 3) {
                if (ufa.union(u, v)) {
                    ufb.union(u, v);
                } else {
                    ++ans;
                }
            }
        }
        for (var e : edges) {
            int t = e[0], u = e[1], v = e[2];
            if (t == 1 && !ufa.union(u, v)) {
                ++ans;
            }
            if (t == 2 && !ufb.union(u, v)) {
                ++ans;
            }
        }
        return ufa.cnt == 1 && ufb.cnt == 1 ? ans : -1;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    int cnt;

    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
        cnt = n;
    }

    bool unite(int a, int b) {
        int pa = find(a - 1), pb = find(b - 1);
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
        --cnt;
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind ufa(n);
        UnionFind ufb(n);
        int ans = 0;
        for (auto& e : edges) {
            int t = e[0], u = e[1], v = e[2];
            if (t == 3) {
                if (ufa.unite(u, v)) {
                    ufb.unite(u, v);
                } else {
                    ++ans;
                }
            }
        }
        for (auto& e : edges) {
            int t = e[0], u = e[1], v = e[2];
            ans += t == 1 && !ufa.unite(u, v);
            ans += t == 2 && !ufb.unite(u, v);
        }
        return ufa.cnt == 1 && ufb.cnt == 1 ? ans : -1;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
	cnt     int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size, n}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a-1), uf.find(b-1)
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
	uf.cnt--
	return true
}

func maxNumEdgesToRemove(n int, edges [][]int) (ans int) {
	ufa := newUnionFind(n)
	ufb := newUnionFind(n)
	for _, e := range edges {
		t, u, v := e[0], e[1], e[2]
		if t == 3 {
			if ufa.union(u, v) {
				ufb.union(u, v)
			} else {
				ans++
			}
		}
	}
	for _, e := range edges {
		t, u, v := e[0], e[1], e[2]
		if t == 1 && !ufa.union(u, v) {
			ans++
		}
		if t == 2 && !ufb.union(u, v) {
			ans++
		}
	}
	if ufa.cnt == 1 && ufb.cnt == 1 {
		return
	}
	return -1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
