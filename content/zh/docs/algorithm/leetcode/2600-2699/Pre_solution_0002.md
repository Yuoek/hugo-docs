---
title: "2610_转换二维数组"
date: 2025-10-08T18:39:28+08:00
weight: 2
tags: [JavaScript, 二分查找, 几何, 分治, 前缀和, 动态规划, 单调栈, 哈希表, 堆（优先队列）, 并查集, 广度优先搜索, 排序, 数学, 数组, 数论, 有序集合, 栈, 矩阵, 贪心]
---

{{< markmap >}}
### [2610_转换二维数组](#2610)
#### [数组](#2610)
#### [哈希表](#2610)
### [2611_老鼠和奶酪](#2611)
#### [贪心](#2611)
#### [数组](#2611)
#### [排序](#2611)
#### [堆（优先队列）](#2611)
### [2612_最少翻转操作数](#2612)
#### [广度优先搜索](#2612)
#### [数组](#2612)
#### [有序集合](#2612)
### [2613_美数对 🔒](#2613)
#### [几何](#2613)
#### [数组](#2613)
#### [数学](#2613)
#### [分治](#2613)
#### [有序集合](#2613)
#### [排序](#2613)
### [2614_对角线上的质数](#2614)
#### [数组](#2614)
#### [数学](#2614)
#### [矩阵](#2614)
#### [数论](#2614)
### [2615_等值距离和](#2615)
#### [数组](#2615)
#### [哈希表](#2615)
#### [前缀和](#2615)
### [2616_最小化数对的最大差值](#2616)
#### [贪心](#2616)
#### [数组](#2616)
#### [二分查找](#2616)
#### [动态规划](#2616)
#### [排序](#2616)
### [2617_网格图中最少访问的格子数](#2617)
#### [栈](#2617)
#### [广度优先搜索](#2617)
#### [并查集](#2617)
#### [数组](#2617)
#### [动态规划](#2617)
#### [矩阵](#2617)
#### [单调栈](#2617)
#### [堆（优先队列）](#2617)
### [2618_检查是否是类的对象实例](#2618)
#### [JavaScript](#2618)
### [2619_数组原型对象的最后一个元素](#2619)
#### [JavaScript](#2619)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2610_转换二维数组
___
#### 数组
___
#### 哈希表
---
### 2611_老鼠和奶酪
___
#### 贪心
___
#### 数组
___
#### 排序
___
#### 堆（优先队列）
---
### 2612_最少翻转操作数
___
#### 广度优先搜索
___
#### 数组
___
#### 有序集合
---
### 2613_美数对 🔒
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 分治
___
#### 有序集合
___
#### 排序
---
### 2614_对角线上的质数
___
#### 数组
___
#### 数学
___
#### 矩阵
___
#### 数论
---
### 2615_等值距离和
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 2616_最小化数对的最大差值
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 排序
---
### 2617_网格图中最少访问的格子数
___
#### 栈
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 动态规划
___
#### 矩阵
___
#### 单调栈
___
#### 堆（优先队列）
---
### 2618_检查是否是类的对象实例
___
#### JavaScript
---
### 2619_数组原型对象的最后一个元素
___
#### JavaScript
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二分查找 | 几何 |
| 分治 | 前缀和 | 动态规划 |
| 单调栈 | 哈希表 | 堆（优先队列） |
| 并查集 | 广度优先搜索 | 排序 |
| 数学 | 数组 | 数论 |
| 有序集合 | 栈 | 矩阵 |
| 贪心 |  |  |

# [2610. 转换二维数组](https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions){#2610}

{{< tabs "2610" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        cnt = Counter(nums)
        ans = []
        for x, v in cnt.items():
            for i in range(v):
                if len(ans) <= i:
                    ans.append([])
                ans[i].append(x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        int[] cnt = new int[n + 1];
        for (int x : nums) {
            ++cnt[x];
        }
        for (int x = 1; x <= n; ++x) {
            int v = cnt[x];
            for (int j = 0; j < v; ++j) {
                if (ans.size() <= j) {
                    ans.add(new ArrayList<>());
                }
                ans.get(j).add(x);
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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cnt(n + 1);
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = 1; x <= n; ++x) {
            int v = cnt[x];
            for (int j = 0; j < v; ++j) {
                if (ans.size() <= j) {
                    ans.push_back({});
                }
                ans[j].push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMatrix(nums []int) (ans [][]int) {
	n := len(nums)
	cnt := make([]int, n+1)
	for _, x := range nums {
		cnt[x]++
	}
	for x, v := range cnt {
		for j := 0; j < v; j++ {
			if len(ans) <= j {
				ans = append(ans, []int{})
			}
			ans[j] = append(ans[j], x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMatrix(nums: number[]): number[][] {
    const ans: number[][] = [];
    const n = nums.length;
    const cnt: number[] = Array(n + 1).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let x = 1; x <= n; ++x) {
        for (let j = 0; j < cnt[x]; ++j) {
            if (ans.length <= j) {
                ans.push([]);
            }
            ans[j].push(x);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut cnt = vec![0; n + 1];
        let mut ans: Vec<Vec<i32>> = Vec::new();

        for &x in &nums {
            cnt[x as usize] += 1;
        }

        for x in 1..=n as i32 {
            for j in 0..cnt[x as usize] {
                if ans.len() <= j {
                    ans.push(Vec::new());
                }
                ans[j].push(x);
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

<p>给你一个整数数组 <code>nums</code> 。请你创建一个满足以下条件的二维数组：</p>

<ul>
	<li>二维数组应该 <strong>只</strong> 包含数组 <code>nums</code> 中的元素。</li>
	<li>二维数组中的每一行都包含 <strong>不同</strong> 的整数。</li>
	<li>二维数组的行数应尽可能 <strong>少</strong> 。</li>
</ul>

<p>返回结果数组。如果存在多种答案，则返回其中任何一种。</p>

<p>请注意，二维数组的每一行上可以存在不同数量的元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,4,1,2,3,1]
<strong>输出：</strong>[[1,3,4,2],[1,3],[1]]
<strong>解释：</strong>根据题目要求可以创建包含以下几行元素的二维数组：
- 1,3,4,2
- 1,3
- 1
nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
可以证明无法创建少于三行且符合题目要求的二维数组。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>[[4,3,2,1]]
<strong>解释：</strong>nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组或哈希表

我们先用一个数组或者哈希表 $\textit{cnt}$ 统计数组 $\textit{nums}$ 中每个元素出现的次数。

然后遍历 $\textit{cnt}$，对于每个元素 $x$，我们将其添加到答案列表中的第 $0$ 行，第 $1$ 行，第 $2$ 行，...，第 $\textit{cnt}[x]-1$ 行。

最后返回答案列表即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        cnt = Counter(nums)
        ans = []
        for x, v in cnt.items():
            for i in range(v):
                if len(ans) <= i:
                    ans.append([])
                ans[i].append(x)
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        int[] cnt = new int[n + 1];
        for (int x : nums) {
            ++cnt[x];
        }
        for (int x = 1; x <= n; ++x) {
            int v = cnt[x];
            for (int j = 0; j < v; ++j) {
                if (ans.size() <= j) {
                    ans.add(new ArrayList<>());
                }
                ans.get(j).add(x);
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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> cnt(n + 1);
        for (int& x : nums) {
            ++cnt[x];
        }
        for (int x = 1; x <= n; ++x) {
            int v = cnt[x];
            for (int j = 0; j < v; ++j) {
                if (ans.size() <= j) {
                    ans.push_back({});
                }
                ans[j].push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMatrix(nums []int) (ans [][]int) {
	n := len(nums)
	cnt := make([]int, n+1)
	for _, x := range nums {
		cnt[x]++
	}
	for x, v := range cnt {
		for j := 0; j < v; j++ {
			if len(ans) <= j {
				ans = append(ans, []int{})
			}
			ans[j] = append(ans[j], x)
		}
	}
	return
}
```

#### TypeScript

```ts
function findMatrix(nums: number[]): number[][] {
    const ans: number[][] = [];
    const n = nums.length;
    const cnt: number[] = Array(n + 1).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    for (let x = 1; x <= n; ++x) {
        for (let j = 0; j < cnt[x]; ++j) {
            if (ans.length <= j) {
                ans.push([]);
            }
            ans[j].push(x);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_matrix(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut cnt = vec![0; n + 1];
        let mut ans: Vec<Vec<i32>> = Vec::new();

        for &x in &nums {
            cnt[x as usize] += 1;
        }

        for x in 1..=n as i32 {
            for j in 0..cnt[x as usize] {
                if ans.len() <= j {
                    ans.push(Vec::new());
                }
                ans[j].push(x);
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

# [2611. 老鼠和奶酪](https://leetcode.cn/problems/mice-and-cheese){#2611}

{{< tabs "2611" >}}

{{% tab "python" %}}
```python
class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        for i, x in enumerate(reward2):
            reward1[i] -= x
        reward1.sort(reverse=True)
        return sum(reward2) + sum(reward1[:k])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int ans = 0;
        int n = reward1.length;
        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            reward1[i] -= reward2[i];
        }
        Arrays.sort(reward1);
        for (int i = 0; i < k; ++i) {
            ans += reward1[n - i - 1];
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
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            reward1[i] -= reward2[i];
        }
        sort(reward1.rbegin(), reward1.rend());
        ans += accumulate(reward1.begin(), reward1.begin() + k, 0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func miceAndCheese(reward1 []int, reward2 []int, k int) (ans int) {
	for i, x := range reward2 {
		ans += x
		reward1[i] -= x
	}
	sort.Ints(reward1)
	n := len(reward1)
	for i := 0; i < k; i++ {
		ans += reward1[n-i-1]
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function miceAndCheese(reward1: number[], reward2: number[], k: number): number {
    const n = reward1.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += reward2[i];
        reward1[i] -= reward2[i];
    }
    reward1.sort((a, b) => b - a);
    for (let i = 0; i < k; ++i) {
        ans += reward1[i];
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

<p>有两只老鼠和&nbsp;<code>n</code>&nbsp;块不同类型的奶酪，每块奶酪都只能被其中一只老鼠吃掉。</p>

<p>下标为 <code>i</code>&nbsp;处的奶酪被吃掉的得分为：</p>

<ul>
	<li>如果第一只老鼠吃掉，则得分为&nbsp;<code>reward1[i]</code>&nbsp;。</li>
	<li>如果第二只老鼠吃掉，则得分为&nbsp;<code>reward2[i]</code>&nbsp;。</li>
</ul>

<p>给你一个正整数数组&nbsp;<code>reward1</code>&nbsp;，一个正整数数组&nbsp;<code>reward2</code>&nbsp;，和一个非负整数&nbsp;<code>k</code>&nbsp;。</p>

<p>请你返回第一只老鼠恰好吃掉 <code>k</code>&nbsp;块奶酪的情况下，<strong>最大</strong>&nbsp;得分为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>reward1 = [1,1,3,4], reward2 = [4,4,1,1], k = 2
<b>输出：</b>15
<b>解释：</b>这个例子中，第一只老鼠吃掉第 2&nbsp;和 3 块奶酪（下标从 0 开始），第二只老鼠吃掉第 0 和 1 块奶酪。
总得分为 4 + 4 + 3 + 4 = 15 。
15 是最高得分。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>reward1 = [1,1], reward2 = [1,1], k = 2
<b>输出：</b>2
<b>解释：</b>这个例子中，第一只老鼠吃掉第 0 和 1 块奶酪（下标从 0 开始），第二只老鼠不吃任何奶酪。
总得分为 1 + 1 = 2 。
2 是最高得分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == reward1.length == reward2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= reward1[i],&nbsp;reward2[i] &lt;= 1000</code></li>
	<li><code>0 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们可以先将所有奶酪分给第二只老鼠，因此初始得分为 $\sum_{i=0}^{n-1} reward2[i]$。

接下来，考虑将其中 $k$ 块奶酪分给第一只老鼠，那么我们应该如何选择这 $k$ 块奶酪呢？显然，将第 $i$ 块奶酪从第二只老鼠分给第一只老鼠，得分的变化量为 $reward1[i] - reward2[i]$，我们希望这个变化量尽可能大，这样才能使得总得分最大。

因此，我们将奶酪按照 $reward1[i] - reward2[i]$ 从大到小排序，前 $k$ 块奶酪由第一只老鼠吃掉，剩下的奶酪由第二只老鼠吃掉，即可得到最大得分。也即是说，我们将初始得分加上 $\sum_{i=0}^{k-1} (reward1[i] - reward2[i])$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为奶酪的数量。

相似题目：

-   [1029. 两地调度](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1029.Two%20City%20Scheduling/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        n = len(reward1)
        idx = sorted(range(n), key=lambda i: reward1[i] - reward2[i], reverse=True)
        return sum(reward1[i] for i in idx[:k]) + sum(reward2[i] for i in idx[k:])
```

#### Java

```java
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n = reward1.length;
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> reward1[j] - reward2[j] - (reward1[i] - reward2[i]));
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += reward1[idx[i]];
        }
        for (int i = k; i < n; ++i) {
            ans += reward2[idx[i]];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return reward1[j] - reward2[j] < reward1[i] - reward2[i]; });
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += reward1[idx[i]];
        }
        for (int i = k; i < n; ++i) {
            ans += reward2[idx[i]];
        }
        return ans;
    }
};
```

#### Go

```go
func miceAndCheese(reward1 []int, reward2 []int, k int) (ans int) {
	n := len(reward1)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		i, j = idx[i], idx[j]
		return reward1[j]-reward2[j] < reward1[i]-reward2[i]
	})
	for i := 0; i < k; i++ {
		ans += reward1[idx[i]]
	}
	for i := k; i < n; i++ {
		ans += reward2[idx[i]]
	}
	return
}
```

#### TypeScript

```ts
function miceAndCheese(reward1: number[], reward2: number[], k: number): number {
    const n = reward1.length;
    const idx = Array.from({ length: n }, (_, i) => i);
    idx.sort((i, j) => reward1[j] - reward2[j] - (reward1[i] - reward2[i]));
    let ans = 0;
    for (let i = 0; i < k; ++i) {
        ans += reward1[idx[i]];
    }
    for (let i = k; i < n; ++i) {
        ans += reward2[idx[i]];
    }
    return ans;
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
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        for i, x in enumerate(reward2):
            reward1[i] -= x
        reward1.sort(reverse=True)
        return sum(reward2) + sum(reward1[:k])
```

#### Java

```java
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int ans = 0;
        int n = reward1.length;
        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            reward1[i] -= reward2[i];
        }
        Arrays.sort(reward1);
        for (int i = 0; i < k; ++i) {
            ans += reward1[n - i - 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            reward1[i] -= reward2[i];
        }
        sort(reward1.rbegin(), reward1.rend());
        ans += accumulate(reward1.begin(), reward1.begin() + k, 0);
        return ans;
    }
};
```

#### Go

```go
func miceAndCheese(reward1 []int, reward2 []int, k int) (ans int) {
	for i, x := range reward2 {
		ans += x
		reward1[i] -= x
	}
	sort.Ints(reward1)
	n := len(reward1)
	for i := 0; i < k; i++ {
		ans += reward1[n-i-1]
	}
	return
}
```

#### TypeScript

```ts
function miceAndCheese(reward1: number[], reward2: number[], k: number): number {
    const n = reward1.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        ans += reward2[i];
        reward1[i] -= reward2[i];
    }
    reward1.sort((a, b) => b - a);
    for (let i = 0; i < k; ++i) {
        ans += reward1[i];
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2612. 最少翻转操作数](https://leetcode.cn/problems/minimum-reverse-operations){#2612}

{{< tabs "2612" >}}

{{% tab "python" %}}
```python
class Solution:
    def minReverseOperations(
        self, n: int, p: int, banned: List[int], k: int
    ) -> List[int]:
        ans = [-1] * n
        ans[p] = 0
        ts = [SortedSet() for _ in range(2)]
        for i in range(n):
            ts[i % 2].add(i)
        ts[p % 2].remove(p)
        for i in banned:
            ts[i % 2].remove(i)
        ts[0].add(n)
        ts[1].add(n)
        q = deque([p])
        while q:
            i = q.popleft()
            mi = max(i - k + 1, k - i - 1)
            mx = min(i + k - 1, n * 2 - k - i - 1)
            s = ts[mi % 2]
            j = s.bisect_left(mi)
            while s[j] <= mx:
                q.append(s[j])
                ans[s[j]] = ans[i] + 1
                s.remove(s[j])
                j = s.bisect_left(mi)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] minReverseOperations(int n, int p, int[] banned, int k) {
        int[] ans = new int[n];
        TreeSet<Integer>[] ts = new TreeSet[] {new TreeSet<>(), new TreeSet<>()};
        for (int i = 0; i < n; ++i) {
            ts[i % 2].add(i);
            ans[i] = i == p ? 0 : -1;
        }
        ts[p % 2].remove(p);
        for (int i : banned) {
            ts[i % 2].remove(i);
        }
        ts[0].add(n);
        ts[1].add(n);
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(p);
        while (!q.isEmpty()) {
            int i = q.poll();
            int mi = Math.max(i - k + 1, k - i - 1);
            int mx = Math.min(i + k - 1, n * 2 - k - i - 1);
            var s = ts[mi % 2];
            for (int j = s.ceiling(mi); j <= mx; j = s.ceiling(mi)) {
                q.offer(j);
                ans[j] = ans[i] + 1;
                s.remove(j);
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
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        ans[p] = 0;
        set<int> ts[2];
        for (int i = 0; i < n; ++i) {
            ts[i % 2].insert(i);
        }
        ts[p % 2].erase(p);
        for (int i : banned) {
            ts[i % 2].erase(i);
        }
        ts[0].insert(n);
        ts[1].insert(n);
        queue<int> q{{p}};
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int mi = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            auto& s = ts[mi % 2];
            auto it = s.lower_bound(mi);
            while (*it <= mx) {
                int j = *it;
                ans[j] = ans[i] + 1;
                q.push(j);
                it = s.erase(it);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minReverseOperations(n int, p int, banned []int, k int) []int {
	ans := make([]int, n)
	ts := [2]*redblacktree.Tree{redblacktree.NewWithIntComparator(), redblacktree.NewWithIntComparator()}
	for i := 0; i < n; i++ {
		ts[i%2].Put(i, struct{}{})
		ans[i] = -1
	}
	ans[p] = 0
	ts[p%2].Remove(p)
	for _, i := range banned {
		ts[i%2].Remove(i)
	}
	ts[0].Put(n, struct{}{})
	ts[1].Put(n, struct{}{})
	q := []int{p}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		mi := max(i-k+1, k-i-1)
		mx := min(i+k-1, n*2-k-i-1)
		s := ts[mi%2]
		for x, _ := s.Ceiling(mi); x.Key.(int) <= mx; x, _ = s.Ceiling(mi) {
			j := x.Key.(int)
			s.Remove(j)
			ans[j] = ans[i] + 1
			q = append(q, j)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minReverseOperations(n: number, p: number, banned: number[], k: number): number[] {
    const ans: number[] = Array(n).fill(-1);
    const ts = [new TreeSet<number>(), new TreeSet<number>()];
    for (let i = 0; i < n; ++i) {
        ts[i % 2].add(i);
    }
    ans[p] = 0;
    ts[p % 2].delete(p);
    for (const i of banned) {
        ts[i % 2].delete(i);
    }
    ts[0].add(n);
    ts[1].add(n);
    let q = [p];
    while (q.length) {
        const t: number[] = [];
        for (const i of q) {
            const mi = Math.max(i - k + 1, k - i - 1);
            const mx = Math.min(i + k - 1, n * 2 - k - i - 1);
            const s = ts[mi % 2];
            for (let j = s.ceil(mi)!; j <= mx; j = s.ceil(j)!) {
                t.push(j);
                ans[j] = ans[i] + 1;
                s.delete(j);
            }
        }
        q = t;
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{BTreeSet, VecDeque};

impl Solution {
    pub fn min_reverse_operations(n: i32, p: i32, banned: Vec<i32>, k: i32) -> Vec<i32> {
        let mut ans = vec![-1; n as usize];
        let mut ts = [BTreeSet::new(), BTreeSet::new()];

        for i in 0..n {
            ts[(i % 2) as usize].insert(i);
        }
        ans[p as usize] = 0;
        ts[(p % 2) as usize].remove(&p);

        for &b in &banned {
            ts[(b % 2) as usize].remove(&b);
        }

        ts[0].insert(n);
        ts[1].insert(n);
        let mut q = VecDeque::new();
        q.push_back(p);

        while let Some(i) = q.pop_front() {
            let mi = (i - k + 1).max(k - i - 1);
            let mx = (i + k - 1).min(2 * n - k - i - 1);
            let s = &mut ts[(mi % 2) as usize];

            while let Some(&j) = s.range(mi..=mx).next() {
                q.push_back(j);
                ans[j as usize] = ans[i as usize] + 1;
                s.remove(&j);
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

<p>给定一个整数&nbsp;<code>n</code>&nbsp;和一个整数&nbsp;<code>p</code>，它们表示一个长度为 <code>n</code> 且除了下标为&nbsp;<code>p</code>&nbsp;处是 <code>1</code>&nbsp;以外，其他所有数都是 <code>0</code>&nbsp;的数组&nbsp;<code>arr</code>。同时给定一个整数数组&nbsp;<code>banned</code>&nbsp;，它包含数组中的一些限制位置。在&nbsp;<code>arr</code>&nbsp;上进行下列操作：</p>

<ul>
	<li>如果单个 1 不在&nbsp;<code>banned</code>&nbsp;中的位置上，反转大小为 <code>k</code> 的 <strong><span data-keyword="subarray-nonempty">子数组</span></strong>。</li>
</ul>

<p>返回一个包含&nbsp;<code>n</code>&nbsp;个结果的整数数组&nbsp;<code>answer</code>，其中第&nbsp;<code>i</code>&nbsp;个结果是将&nbsp;<code>1</code>&nbsp;放到位置&nbsp;<code>i</code>&nbsp;处所需的&nbsp;<strong>最少</strong>&nbsp;翻转操作次数，如果无法放到位置&nbsp;<code>i</code>&nbsp;处，此数为&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 4, p = 0, banned = [1,2], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>[0,-1,-1,1]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>一开始 1 位于位置 0，因此我们需要在位置 0 上的操作数是 0。</li>
	<li>我们不能将 1 放置在被禁止的位置上，所以位置 1 和 2 的答案是 -1。</li>
	<li>执行大小为 4 的操作以反转整个数组。</li>
	<li>在一次操作后，1 位于位置 3，因此位置 3 的答案是 1。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, p = 0, banned = [2,4], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>[0,-1,-1,-1,-1]</span></p>

<p><b>解释：</b></p>

<ul>
	<li>一开始 1 位于位置 0，因此我们需要在位置 0 上的操作数是 0。</li>
	<li>我们不能在&nbsp;<code>[0, 2]</code>&nbsp;的子数组位置上执行操作，因为位置 2 在 banned 中。</li>
	<li>由于 1 不能够放置在位置 2 上，使用更多操作将 1 放置在其它位置上是不可能的。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 4, p = 2, banned = [0,1,3], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>[-1,-1,0,-1]</span></p>

<p><strong>解释：</strong></p>

<p>执行大小为 1 的操作，且 1 永远不会改变位置。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= p &lt;= n - 1</code></li>
	<li><code>0 &lt;= banned.length &lt;= n - 1</code></li>
	<li><code>0 &lt;= banned[i] &lt;= n - 1</code></li>
	<li><code>1 &lt;= k &lt;= n&nbsp;</code></li>
	<li><code>banned[i] != p</code></li>
	<li><code>banned</code>&nbsp;中的值 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合 + BFS

我们注意到，对于一个子数组区间 $[l,..r]$ 中的任意一个下标 $i$，翻转后的下标 $j = l + r - i$。

如果子数组向右移动一个位置，那么 $j = l + 1 + r + 1 - i = l + r - i + 2$，即 $j$ 会增加 $2$。

同理，如果子数组向左移动一个位置，那么 $j = l - 1 + r - 1 - i = l + r - i - 2$，即 $j$ 会减少 $2$。

因此，对于一个特定的下标 $i$，其翻转后的所有位置构成了一个公差为 $2$ 的等差数列，也即是说，翻转后的所有下标，奇偶性都是相同的。

接下来，我们考虑下标 $i$ 翻转后的位置 $j$ 的取值范围。

-   如果不考虑边界的情况，那么 $j$ 的取值范围为 $[i - k + 1, i + k - 1]$。
-   如果子数组在最左边，那么 $[l, r] = [0, k - 1]$，因此 $i$ 翻转后的下标 $j = 0 + k - 1 - i$，即 $j = k - i - 1$，因此 $j$ 的左边界 $mi = max(i - k + 1, k - i - 1)$。
-   如果子数组在最右边，那么 $[l, r] = [n - k, n - 1]$，因此 $i$ 翻转后的下标 $j= n - k + n - 1 - i$，即 $j = n \times 2 - k - i - 1$，因此 $j$ 的右边界 $mx = min(i + k - 1, n \times 2 - k - i - 1)$。

我们用两个有序集合分别存储所有待搜索的奇数下标和偶数下标，这里需要排除数组 $banned$ 中的下标，以及下标 $p$。

接下来，我们使用 BFS 搜索，每次搜索当前下标 $i$ 所有翻转后的下标 $j$，即 $j = mi, mi + 2, mi + 4, \dots, mx$，更新下标 $j$ 的答案，并将下标 $j$ 加入到待搜索的队列中，同时将下标 $j$ 从对应的有序集合中移除。

当搜索结束时，即可得到所有下标的答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 题目中给定的数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minReverseOperations(
        self, n: int, p: int, banned: List[int], k: int
    ) -> List[int]:
        ans = [-1] * n
        ans[p] = 0
        ts = [SortedSet() for _ in range(2)]
        for i in range(n):
            ts[i % 2].add(i)
        ts[p % 2].remove(p)
        for i in banned:
            ts[i % 2].remove(i)
        ts[0].add(n)
        ts[1].add(n)
        q = deque([p])
        while q:
            i = q.popleft()
            mi = max(i - k + 1, k - i - 1)
            mx = min(i + k - 1, n * 2 - k - i - 1)
            s = ts[mi % 2]
            j = s.bisect_left(mi)
            while s[j] <= mx:
                q.append(s[j])
                ans[s[j]] = ans[i] + 1
                s.remove(s[j])
                j = s.bisect_left(mi)
        return ans
```

#### Java

```java
class Solution {
    public int[] minReverseOperations(int n, int p, int[] banned, int k) {
        int[] ans = new int[n];
        TreeSet<Integer>[] ts = new TreeSet[] {new TreeSet<>(), new TreeSet<>()};
        for (int i = 0; i < n; ++i) {
            ts[i % 2].add(i);
            ans[i] = i == p ? 0 : -1;
        }
        ts[p % 2].remove(p);
        for (int i : banned) {
            ts[i % 2].remove(i);
        }
        ts[0].add(n);
        ts[1].add(n);
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(p);
        while (!q.isEmpty()) {
            int i = q.poll();
            int mi = Math.max(i - k + 1, k - i - 1);
            int mx = Math.min(i + k - 1, n * 2 - k - i - 1);
            var s = ts[mi % 2];
            for (int j = s.ceiling(mi); j <= mx; j = s.ceiling(mi)) {
                q.offer(j);
                ans[j] = ans[i] + 1;
                s.remove(j);
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
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        ans[p] = 0;
        set<int> ts[2];
        for (int i = 0; i < n; ++i) {
            ts[i % 2].insert(i);
        }
        ts[p % 2].erase(p);
        for (int i : banned) {
            ts[i % 2].erase(i);
        }
        ts[0].insert(n);
        ts[1].insert(n);
        queue<int> q{{p}};
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int mi = max(i - k + 1, k - i - 1);
            int mx = min(i + k - 1, n * 2 - k - i - 1);
            auto& s = ts[mi % 2];
            auto it = s.lower_bound(mi);
            while (*it <= mx) {
                int j = *it;
                ans[j] = ans[i] + 1;
                q.push(j);
                it = s.erase(it);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minReverseOperations(n int, p int, banned []int, k int) []int {
	ans := make([]int, n)
	ts := [2]*redblacktree.Tree{redblacktree.NewWithIntComparator(), redblacktree.NewWithIntComparator()}
	for i := 0; i < n; i++ {
		ts[i%2].Put(i, struct{}{})
		ans[i] = -1
	}
	ans[p] = 0
	ts[p%2].Remove(p)
	for _, i := range banned {
		ts[i%2].Remove(i)
	}
	ts[0].Put(n, struct{}{})
	ts[1].Put(n, struct{}{})
	q := []int{p}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		mi := max(i-k+1, k-i-1)
		mx := min(i+k-1, n*2-k-i-1)
		s := ts[mi%2]
		for x, _ := s.Ceiling(mi); x.Key.(int) <= mx; x, _ = s.Ceiling(mi) {
			j := x.Key.(int)
			s.Remove(j)
			ans[j] = ans[i] + 1
			q = append(q, j)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minReverseOperations(n: number, p: number, banned: number[], k: number): number[] {
    const ans: number[] = Array(n).fill(-1);
    const ts = [new TreeSet<number>(), new TreeSet<number>()];
    for (let i = 0; i < n; ++i) {
        ts[i % 2].add(i);
    }
    ans[p] = 0;
    ts[p % 2].delete(p);
    for (const i of banned) {
        ts[i % 2].delete(i);
    }
    ts[0].add(n);
    ts[1].add(n);
    let q = [p];
    while (q.length) {
        const t: number[] = [];
        for (const i of q) {
            const mi = Math.max(i - k + 1, k - i - 1);
            const mx = Math.min(i + k - 1, n * 2 - k - i - 1);
            const s = ts[mi % 2];
            for (let j = s.ceil(mi)!; j <= mx; j = s.ceil(j)!) {
                t.push(j);
                ans[j] = ans[i] + 1;
                s.delete(j);
            }
        }
        q = t;
    }
    return ans;
}

type Compare<T> = (lhs: T, rhs: T) => number;

class RBTreeNode<T = number> {
    data: T;
    count: number;
    left: RBTreeNode<T> | null;
    right: RBTreeNode<T> | null;
    parent: RBTreeNode<T> | null;
    color: number;
    constructor(data: T) {
        this.data = data;
        this.left = this.right = this.parent = null;
        this.color = 0;
        this.count = 1;
    }

    sibling(): RBTreeNode<T> | null {
        if (!this.parent) return null; // sibling null if no parent
        return this.isOnLeft() ? this.parent.right : this.parent.left;
    }

    isOnLeft(): boolean {
        return this === this.parent!.left;
    }

    hasRedChild(): boolean {
        return (
            Boolean(this.left && this.left.color === 0) ||
            Boolean(this.right && this.right.color === 0)
        );
    }
}

class RBTree<T> {
    root: RBTreeNode<T> | null;
    lt: (l: T, r: T) => boolean;
    constructor(compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0)) {
        this.root = null;
        this.lt = (l: T, r: T) => compare(l, r) < 0;
    }

    rotateLeft(pt: RBTreeNode<T>): void {
        const right = pt.right!;
        pt.right = right.left;

        if (pt.right) pt.right.parent = pt;
        right.parent = pt.parent;

        if (!pt.parent) this.root = right;
        else if (pt === pt.parent.left) pt.parent.left = right;
        else pt.parent.right = right;

        right.left = pt;
        pt.parent = right;
    }

    rotateRight(pt: RBTreeNode<T>): void {
        const left = pt.left!;
        pt.left = left.right;

        if (pt.left) pt.left.parent = pt;
        left.parent = pt.parent;

        if (!pt.parent) this.root = left;
        else if (pt === pt.parent.left) pt.parent.left = left;
        else pt.parent.right = left;

        left.right = pt;
        pt.parent = left;
    }

    swapColor(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.color;
        p1.color = p2.color;
        p2.color = tmp;
    }

    swapData(p1: RBTreeNode<T>, p2: RBTreeNode<T>): void {
        const tmp = p1.data;
        p1.data = p2.data;
        p2.data = tmp;
    }

    fixAfterInsert(pt: RBTreeNode<T>): void {
        let parent = null;
        let grandParent = null;

        while (pt !== this.root && pt.color !== 1 && pt.parent?.color === 0) {
            parent = pt.parent;
            grandParent = pt.parent.parent;

            /*  Case : A
                Parent of pt is left child of Grand-parent of pt */
            if (parent === grandParent?.left) {
                const uncle = grandParent.right;

                /* Case : 1
                   The uncle of pt is also red
                   Only Recoloring required */
                if (uncle && uncle.color === 0) {
                    grandParent.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent;
                } else {
                    /* Case : 2
                       pt is right child of its parent
                       Left-rotation required */
                    if (pt === parent.right) {
                        this.rotateLeft(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is left child of its parent
                       Right-rotation required */
                    this.rotateRight(grandParent);
                    this.swapColor(parent!, grandParent);
                    pt = parent!;
                }
            } else {
                /* Case : B
               Parent of pt is right child of Grand-parent of pt */
                const uncle = grandParent!.left;

                /*  Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if (uncle != null && uncle.color === 0) {
                    grandParent!.color = 0;
                    parent.color = 1;
                    uncle.color = 1;
                    pt = grandParent!;
                } else {
                    /* Case : 2
                       pt is left child of its parent
                       Right-rotation required */
                    if (pt === parent.left) {
                        this.rotateRight(parent);
                        pt = parent;
                        parent = pt.parent;
                    }

                    /* Case : 3
                       pt is right child of its parent
                       Left-rotation required */
                    this.rotateLeft(grandParent!);
                    this.swapColor(parent!, grandParent!);
                    pt = parent!;
                }
            }
        }
        this.root!.color = 1;
    }

    delete(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        node.count--;
        if (!node.count) this.deleteNode(node);
        return true;
    }

    deleteAll(val: T): boolean {
        const node = this.find(val);
        if (!node) return false;
        this.deleteNode(node);
        return true;
    }

    deleteNode(v: RBTreeNode<T>): void {
        const u = BSTreplace(v);

        // True when u and v are both black
        const uvBlack = (u === null || u.color === 1) && v.color === 1;
        const parent = v.parent!;

        if (!u) {
            // u is null therefore v is leaf
            if (v === this.root) this.root = null;
            // v is root, making root null
            else {
                if (uvBlack) {
                    // u and v both black
                    // v is leaf, fix double black at v
                    this.fixDoubleBlack(v);
                } else {
                    // u or v is red
                    if (v.sibling()) {
                        // sibling is not null, make it red"
                        v.sibling()!.color = 0;
                    }
                }
                // delete v from the tree
                if (v.isOnLeft()) parent.left = null;
                else parent.right = null;
            }
            return;
        }

        if (!v.left || !v.right) {
            // v has 1 child
            if (v === this.root) {
                // v is root, assign the value of u to v, and delete u
                v.data = u.data;
                v.left = v.right = null;
            } else {
                // Detach v from tree and move u up
                if (v.isOnLeft()) parent.left = u;
                else parent.right = u;
                u.parent = parent;
                if (uvBlack) this.fixDoubleBlack(u);
                // u and v both black, fix double black at u
                else u.color = 1; // u or v red, color u black
            }
            return;
        }

        // v has 2 children, swap data with successor and recurse
        this.swapData(u, v);
        this.deleteNode(u);

        // find node that replaces a deleted node in BST
        function BSTreplace(x: RBTreeNode<T>): RBTreeNode<T> | null {
            // when node have 2 children
            if (x.left && x.right) return successor(x.right);
            // when leaf
            if (!x.left && !x.right) return null;
            // when single child
            return x.left ?? x.right;
        }
        // find node that do not have a left child
        // in the subtree of the given node
        function successor(x: RBTreeNode<T>): RBTreeNode<T> {
            let temp = x;
            while (temp.left) temp = temp.left;
            return temp;
        }
    }

    fixDoubleBlack(x: RBTreeNode<T>): void {
        if (x === this.root) return; // Reached root

        const sibling = x.sibling();
        const parent = x.parent!;
        if (!sibling) {
            // No sibiling, double black pushed up
            this.fixDoubleBlack(parent);
        } else {
            if (sibling.color === 0) {
                // Sibling red
                parent.color = 0;
                sibling.color = 1;
                if (sibling.isOnLeft()) this.rotateRight(parent);
                // left case
                else this.rotateLeft(parent); // right case
                this.fixDoubleBlack(x);
            } else {
                // Sibling black
                if (sibling.hasRedChild()) {
                    // at least 1 red children
                    if (sibling.left && sibling.left.color === 0) {
                        if (sibling.isOnLeft()) {
                            // left left
                            sibling.left.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateRight(parent);
                        } else {
                            // right left
                            sibling.left.color = parent.color;
                            this.rotateRight(sibling);
                            this.rotateLeft(parent);
                        }
                    } else {
                        if (sibling.isOnLeft()) {
                            // left right
                            sibling.right!.color = parent.color;
                            this.rotateLeft(sibling);
                            this.rotateRight(parent);
                        } else {
                            // right right
                            sibling.right!.color = sibling.color;
                            sibling.color = parent.color;
                            this.rotateLeft(parent);
                        }
                    }
                    parent.color = 1;
                } else {
                    // 2 black children
                    sibling.color = 0;
                    if (parent.color === 1) this.fixDoubleBlack(parent);
                    else parent.color = 1;
                }
            }
        }
    }

    insert(data: T): boolean {
        // search for a position to insert
        let parent = this.root;
        while (parent) {
            if (this.lt(data, parent.data)) {
                if (!parent.left) break;
                else parent = parent.left;
            } else if (this.lt(parent.data, data)) {
                if (!parent.right) break;
                else parent = parent.right;
            } else break;
        }

        // insert node into parent
        const node = new RBTreeNode(data);
        if (!parent) this.root = node;
        else if (this.lt(node.data, parent.data)) parent.left = node;
        else if (this.lt(parent.data, node.data)) parent.right = node;
        else {
            parent.count++;
            return false;
        }
        node.parent = parent;
        this.fixAfterInsert(node);
        return true;
    }

    find(data: T): RBTreeNode<T> | null {
        let p = this.root;
        while (p) {
            if (this.lt(data, p.data)) {
                p = p.left;
            } else if (this.lt(p.data, data)) {
                p = p.right;
            } else break;
        }
        return p ?? null;
    }

    *inOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.inOrder(root.left!)) yield v;
        yield root.data;
        for (const v of this.inOrder(root.right!)) yield v;
    }

    *reverseInOrder(root: RBTreeNode<T> = this.root!): Generator<T, undefined, void> {
        if (!root) return;
        for (const v of this.reverseInOrder(root.right!)) yield v;
        yield root.data;
        for (const v of this.reverseInOrder(root.left!)) yield v;
    }
}

class TreeSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size += successful ? 1 : 0;
        return successful;
    }

    delete(val: T): boolean {
        const deleted = this.tree.deleteAll(val);
        this._size -= deleted ? 1 : 0;
        return deleted;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) yield val;
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) yield val;
        return undefined;
    }
}

class TreeMultiSet<T = number> {
    _size: number;
    tree: RBTree<T>;
    compare: Compare<T>;
    constructor(
        collection: T[] | Compare<T> = [],
        compare: Compare<T> = (l: T, r: T) => (l < r ? -1 : l > r ? 1 : 0),
    ) {
        if (typeof collection === 'function') {
            compare = collection;
            collection = [];
        }
        this._size = 0;
        this.compare = compare;
        this.tree = new RBTree(compare);
        for (const val of collection) this.add(val);
    }

    size(): number {
        return this._size;
    }

    has(val: T): boolean {
        return !!this.tree.find(val);
    }

    add(val: T): boolean {
        const successful = this.tree.insert(val);
        this._size++;
        return successful;
    }

    delete(val: T): boolean {
        const successful = this.tree.delete(val);
        if (!successful) return false;
        this._size--;
        return true;
    }

    count(val: T): number {
        const node = this.tree.find(val);
        return node ? node.count : 0;
    }

    ceil(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(p.data, val) >= 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    floor(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(val, p.data) >= 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    higher(val: T): T | undefined {
        let p = this.tree.root;
        let higher = null;
        while (p) {
            if (this.compare(val, p.data) < 0) {
                higher = p;
                p = p.left;
            } else {
                p = p.right;
            }
        }
        return higher?.data;
    }

    lower(val: T): T | undefined {
        let p = this.tree.root;
        let lower = null;
        while (p) {
            if (this.compare(p.data, val) < 0) {
                lower = p;
                p = p.right;
            } else {
                p = p.left;
            }
        }
        return lower?.data;
    }

    first(): T | undefined {
        return this.tree.inOrder().next().value;
    }

    last(): T | undefined {
        return this.tree.reverseInOrder().next().value;
    }

    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    pop(): T | undefined {
        const last = this.last();
        if (last === undefined) return undefined;
        this.delete(last);
        return last;
    }

    *[Symbol.iterator](): Generator<T, void, void> {
        yield* this.values();
    }

    *keys(): Generator<T, void, void> {
        for (const val of this.values()) yield val;
    }

    *values(): Generator<T, undefined, void> {
        for (const val of this.tree.inOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }

    /**
     * Return a generator for reverse order traversing the multi-set
     */
    *rvalues(): Generator<T, undefined, void> {
        for (const val of this.tree.reverseInOrder()) {
            let count = this.count(val);
            while (count--) yield val;
        }
        return undefined;
    }
}
```

#### Rust

```rust
use std::collections::{BTreeSet, VecDeque};

impl Solution {
    pub fn min_reverse_operations(n: i32, p: i32, banned: Vec<i32>, k: i32) -> Vec<i32> {
        let mut ans = vec![-1; n as usize];
        let mut ts = [BTreeSet::new(), BTreeSet::new()];

        for i in 0..n {
            ts[(i % 2) as usize].insert(i);
        }
        ans[p as usize] = 0;
        ts[(p % 2) as usize].remove(&p);

        for &b in &banned {
            ts[(b % 2) as usize].remove(&b);
        }

        ts[0].insert(n);
        ts[1].insert(n);
        let mut q = VecDeque::new();
        q.push_back(p);

        while let Some(i) = q.pop_front() {
            let mi = (i - k + 1).max(k - i - 1);
            let mx = (i + k - 1).min(2 * n - k - i - 1);
            let s = &mut ts[(mi % 2) as usize];

            while let Some(&j) = s.range(mi..=mx).next() {
                q.push_back(j);
                ans[j as usize] = ans[i as usize] + 1;
                s.remove(&j);
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

# [2613. 美数对 🔒](https://leetcode.cn/problems/beautiful-pairs){#2613}

{{< tabs "2613" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulPair(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def dist(x1: int, y1: int, x2: int, y2: int) -> int:
            return abs(x1 - x2) + abs(y1 - y2)

        def dfs(l: int, r: int):
            if l >= r:
                return inf, -1, -1
            m = (l + r) >> 1
            x = points[m][0]
            d1, pi1, pj1 = dfs(l, m)
            d2, pi2, pj2 = dfs(m + 1, r)
            if d1 > d2 or (d1 == d2 and (pi1 > pi2 or (pi1 == pi2 and pj1 > pj2))):
                d1, pi1, pj1 = d2, pi2, pj2
            t = [p for p in points[l : r + 1] if abs(p[0] - x) <= d1]
            t.sort(key=lambda x: x[1])
            for i in range(len(t)):
                for j in range(i + 1, len(t)):
                    if t[j][1] - t[i][1] > d1:
                        break
                    pi, pj = sorted([t[i][2], t[j][2]])
                    d = dist(t[i][0], t[i][1], t[j][0], t[j][1])
                    if d < d1 or (d == d1 and (pi < pi1 or (pi == pi1 and pj < pj1))):
                        d1, pi1, pj1 = d, pi, pj
            return d1, pi1, pj1

        pl = defaultdict(list)
        for i, (x, y) in enumerate(zip(nums1, nums2)):
            pl[(x, y)].append(i)
        points = []
        for i, (x, y) in enumerate(zip(nums1, nums2)):
            if len(pl[(x, y)]) > 1:
                return [i, pl[(x, y)][1]]
            points.append((x, y, i))
        points.sort()
        _, pi, pj = dfs(0, len(points) - 1)
        return [pi, pj]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<int[]> points = new ArrayList<>();

    public int[] beautifulPair(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Map<Long, List<Integer>> pl = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            long z = f(nums1[i], nums2[i]);
            pl.computeIfAbsent(z, k -> new ArrayList<>()).add(i);
        }
        for (int i = 0; i < n; ++i) {
            long z = f(nums1[i], nums2[i]);
            if (pl.get(z).size() > 1) {
                return new int[] {i, pl.get(z).get(1)};
            }
            points.add(new int[] {nums1[i], nums2[i], i});
        }
        points.sort((a, b) -> a[0] - b[0]);
        int[] ans = dfs(0, points.size() - 1);
        return new int[] {ans[1], ans[2]};
    }

    private long f(int x, int y) {
        return x * 100000L + y;
    }

    private int dist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    private int[] dfs(int l, int r) {
        if (l >= r) {
            return new int[] {1 << 30, -1, -1};
        }
        int m = (l + r) >> 1;
        int x = points.get(m)[0];
        int[] t1 = dfs(l, m);
        int[] t2 = dfs(m + 1, r);
        if (t1[0] > t2[0]
            || (t1[0] == t2[0] && (t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2])))) {
            t1 = t2;
        }
        List<int[]> t = new ArrayList<>();
        for (int i = l; i <= r; ++i) {
            if (Math.abs(points.get(i)[0] - x) <= t1[0]) {
                t.add(points.get(i));
            }
        }
        t.sort((a, b) -> a[1] - b[1]);
        for (int i = 0; i < t.size(); ++i) {
            for (int j = i + 1; j < t.size(); ++j) {
                if (t.get(j)[1] - t.get(i)[1] > t1[0]) {
                    break;
                }
                int pi = Math.min(t.get(i)[2], t.get(j)[2]);
                int pj = Math.max(t.get(i)[2], t.get(j)[2]);
                int d = dist(t.get(i)[0], t.get(i)[1], t.get(j)[0], t.get(j)[1]);
                if (d < t1[0] || (d == t1[0] && (pi < t1[1] || (pi == t1[1] && pj < t1[2])))) {
                    t1 = new int[] {d, pi, pj};
                }
            }
        }
        return t1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<long long, vector<int>> pl;
        for (int i = 0; i < n; ++i) {
            pl[f(nums1[i], nums2[i])].push_back(i);
        }
        vector<tuple<int, int, int>> points;
        for (int i = 0; i < n; ++i) {
            long long z = f(nums1[i], nums2[i]);
            if (pl[z].size() > 1) {
                return {i, pl[z][1]};
            }
            points.emplace_back(nums1[i], nums2[i], i);
        }

        function<tuple<int, int, int>(int, int)> dfs = [&](int l, int r) -> tuple<int, int, int> {
            if (l >= r) {
                return {1 << 30, -1, -1};
            }
            int m = (l + r) >> 1;
            int x = get<0>(points[m]);
            auto t1 = dfs(l, m);
            auto t2 = dfs(m + 1, r);
            if (get<0>(t1) > get<0>(t2) || (get<0>(t1) == get<0>(t2) && (get<1>(t1) > get<1>(t2) || (get<1>(t1) == get<1>(t2) && get<2>(t1) > get<2>(t2))))) {
                swap(t1, t2);
            }
            vector<tuple<int, int, int>> t;
            for (int i = l; i <= r; ++i) {
                if (abs(get<0>(points[i]) - x) <= get<0>(t1)) {
                    t.emplace_back(points[i]);
                }
            }
            sort(t.begin(), t.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
                return get<1>(a) < get<1>(b);
            });
            for (int i = 0; i < t.size(); ++i) {
                for (int j = i + 1; j < t.size(); ++j) {
                    if (get<1>(t[j]) - get<1>(t[i]) > get<0>(t1)) {
                        break;
                    }
                    int pi = min(get<2>(t[i]), get<2>(t[j]));
                    int pj = max(get<2>(t[i]), get<2>(t[j]));
                    int d = dist(get<0>(t[i]), get<1>(t[i]), get<0>(t[j]), get<1>(t[j]));
                    if (d < get<0>(t1) || (d == get<0>(t1) && (pi < get<1>(t1) || (pi == get<1>(t1) && pj < get<2>(t1))))) {
                        t1 = {d, pi, pj};
                    }
                }
            }
            return t1;
        };

        sort(points.begin(), points.end());
        auto [_, pi, pj] = dfs(0, points.size() - 1);
        return {pi, pj};
    }

    long long f(int x, int y) {
        return x * 100000LL + y;
    }

    int dist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulPair(nums1 []int, nums2 []int) []int {
	n := len(nums1)
	pl := map[[2]int][]int{}
	for i := 0; i < n; i++ {
		k := [2]int{nums1[i], nums2[i]}
		pl[k] = append(pl[k], i)
	}
	points := [][3]int{}
	for i := 0; i < n; i++ {
		k := [2]int{nums2[i], nums1[i]}
		if len(pl[k]) > 1 {
			return []int{pl[k][0], pl[k][1]}
		}
		points = append(points, [3]int{nums1[i], nums2[i], i})
	}
	sort.Slice(points, func(i, j int) bool { return points[i][0] < points[j][0] })

	var dfs func(l, r int) [3]int
	dfs = func(l, r int) [3]int {
		if l >= r {
			return [3]int{1 << 30, -1, -1}
		}
		m := (l + r) >> 1
		x := points[m][0]
		t1 := dfs(l, m)
		t2 := dfs(m+1, r)
		if t1[0] > t2[0] || (t1[0] == t2[0] && (t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2]))) {
			t1 = t2
		}
		t := [][3]int{}
		for i := l; i <= r; i++ {
			if abs(points[i][0]-x) <= t1[0] {
				t = append(t, points[i])
			}
		}
		sort.Slice(t, func(i, j int) bool { return t[i][1] < t[j][1] })
		for i := 0; i < len(t); i++ {
			for j := i + 1; j < len(t); j++ {
				if t[j][1]-t[i][1] > t1[0] {
					break
				}
				pi := min(t[i][2], t[j][2])
				pj := max(t[i][2], t[j][2])
				d := dist(t[i][0], t[i][1], t[j][0], t[j][1])
				if d < t1[0] || (d == t1[0] && (pi < t1[1] || (pi == t1[1] && pj < t1[2]))) {
					t1 = [3]int{d, pi, pj}
				}
			}
		}
		return t1
	}
	ans := dfs(0, n-1)
	return []int{ans[1], ans[2]}
}

func dist(x1, y1, x2, y2 int) int {
	return abs(x1-x2) + abs(y1-y2)
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
function beautifulPair(nums1: number[], nums2: number[]): number[] {
    const pl: Map<number, number[]> = new Map();
    const n = nums1.length;
    for (let i = 0; i < n; ++i) {
        const z = f(nums1[i], nums2[i]);
        if (!pl.has(z)) {
            pl.set(z, []);
        }
        pl.get(z)!.push(i);
    }
    const points: number[][] = [];
    for (let i = 0; i < n; ++i) {
        const z = f(nums1[i], nums2[i]);
        if (pl.get(z)!.length > 1) {
            return [i, pl.get(z)![1]];
        }
        points.push([nums1[i], nums2[i], i]);
    }
    points.sort((a, b) => a[0] - b[0]);

    const dfs = (l: number, r: number): number[] => {
        if (l >= r) {
            return [1 << 30, -1, -1];
        }
        const m = (l + r) >> 1;
        const x = points[m][0];
        let t1 = dfs(l, m);
        let t2 = dfs(m + 1, r);
        if (
            t1[0] > t2[0] ||
            (t1[0] == t2[0] && (t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2])))
        ) {
            t1 = t2;
        }
        const t: number[][] = [];
        for (let i = l; i <= r; ++i) {
            if (Math.abs(points[i][0] - x) <= t1[0]) {
                t.push(points[i]);
            }
        }
        t.sort((a, b) => a[1] - b[1]);
        for (let i = 0; i < t.length; ++i) {
            for (let j = i + 1; j < t.length; ++j) {
                if (t[j][1] - t[i][1] > t1[0]) {
                    break;
                }
                const pi = Math.min(t[i][2], t[j][2]);
                const pj = Math.max(t[i][2], t[j][2]);
                const d = dist(t[i][0], t[i][1], t[j][0], t[j][1]);
                if (d < t1[0] || (d == t1[0] && (pi < t1[1] || (pi == t1[1] && pj < t1[2])))) {
                    t1 = [d, pi, pj];
                }
            }
        }
        return t1;
    };
    return dfs(0, n - 1).slice(1);
}

function dist(x1: number, y1: number, x2: number, y2: number): number {
    return Math.abs(x1 - x2) + Math.abs(y1 - y2);
}

function f(x: number, y: number): number {
    return x * 100000 + y;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个长度相同的 <strong>下标从 0 开始</strong> 的整数数组 <code>nums1</code> 和 <code>nums2</code>&nbsp;，如果 <code>|nums1[i] - nums1[j]| + |nums2[i] - nums2[j]|</code> 在所有可能的下标对中是最小的，其中 <code>i &lt; j</code> ，则称下标对 <code>(i,j)</code> 为 <strong>美</strong> 数对，</p>

<p>返回美数对。如果有多个美数对，则返回字典序最小的美数对。</p>

<p>注意：</p>

<ul>
	<li><code>|x|</code> 表示 <code>x</code> 的绝对值。</li>
	<li>一对索引 <code>(i1, j1)</code> 在字典序意义下小于 <code>(i2, j2)</code> ，当且仅当 <code>i1 &lt; i2</code> 或 <code>i1 == i2</code> 且 <code>j1 &lt; j2</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,2,3,2,4], nums2 = [2,3,1,2,3]
<b>输出：</b>[0,3]
<b>解释：</b>取下标为 0 和下标为 3 的数对，计算出 |nums1[0]-nums1[3]| + |nums2[0]-nums2[3]| 的值为 1 ，这是我们能够得到的最小值。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>nums1 = [1,2,4,3,2,5], nums2 = [1,4,2,3,5,1]
<b>输出：</b>[1,4]
<b>解释：</b>取下标为 1 和下标为 4 的数对，计算出 |nums1[1]-nums1[4]| + |nums2[1]-nums2[4]| 的值为 1，这是我们可以达到的最小值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums1.length == nums2.length</code></li>
	<li><code>0 &lt;= nums1<sub>i</sub><sub>&nbsp;</sub>&lt;= nums1.length</code></li>
	<li><code>0 &lt;= nums2<sub>i</sub>&nbsp;&lt;= nums2.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 分治

本题相当于找出平面中两个点，使得它们的曼哈顿距离最小，如果有多个点满足条件，则返回下标字典序最小的点。

我们先处理重复点的情况，找出每个点对应的下标列表，如果某个点的下标列表长度大于 $1$，那么它的前两个下标可作为候选答案，我们找出最小的下标对即可。

如果没有重复点，我们将所有点按照 $x$ 坐标排序，然后分治求解。

对于每个区间 $[l, r]$，我们先求出 $x$ 坐标的中位数 $m$，然后递归求解左右两个区间，分别得到 $d_1, (pi_1, pj_1)$ 和 $d_2, (pi_2, pj_2)$，其中 $d_1$ 和 $d_2$ 分别表示左右两个区间的最小曼哈顿距离，而 $(pi_1, pj_1)$ 和 $(pi_2, pj_2)$ 分别表示左右两个区间的最小曼哈顿距离的两个点的下标。我们取 $d_1$ 和 $d_2$ 中较小的一个，如果 $d_1 = d_2$，则取下标字典序较小的一个，将其作为当前区间的最小曼哈顿距离，同时将对应的两个点的下标作为答案。

以上考虑的是两个点位于同一侧的情况，如果两个点位于不同侧，那么我们以中间点，即下标为 $m = \lfloor (l + r) / 2 \rfloor$ 的点为标准，划分出一个新的区域，区域的范围为中间点向左右两侧分别扩展 $d_1$ 的范围。然后我们将这些范围内的点按照 $y$ 坐标排序，然后遍历排序后的每个点对，如果两个点的 $y$ 坐标之差大于当前的最小曼哈顿距离，那么后面的点对都不用考虑了，因为它们的 $y$ 坐标之差更大，所以曼哈顿距离更大，不会比当前的最小曼哈顿距离更小。否则，我们更新最小曼哈顿距离，同时更新答案。

最后，我们返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautifulPair(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def dist(x1: int, y1: int, x2: int, y2: int) -> int:
            return abs(x1 - x2) + abs(y1 - y2)

        def dfs(l: int, r: int):
            if l >= r:
                return inf, -1, -1
            m = (l + r) >> 1
            x = points[m][0]
            d1, pi1, pj1 = dfs(l, m)
            d2, pi2, pj2 = dfs(m + 1, r)
            if d1 > d2 or (d1 == d2 and (pi1 > pi2 or (pi1 == pi2 and pj1 > pj2))):
                d1, pi1, pj1 = d2, pi2, pj2
            t = [p for p in points[l : r + 1] if abs(p[0] - x) <= d1]
            t.sort(key=lambda x: x[1])
            for i in range(len(t)):
                for j in range(i + 1, len(t)):
                    if t[j][1] - t[i][1] > d1:
                        break
                    pi, pj = sorted([t[i][2], t[j][2]])
                    d = dist(t[i][0], t[i][1], t[j][0], t[j][1])
                    if d < d1 or (d == d1 and (pi < pi1 or (pi == pi1 and pj < pj1))):
                        d1, pi1, pj1 = d, pi, pj
            return d1, pi1, pj1

        pl = defaultdict(list)
        for i, (x, y) in enumerate(zip(nums1, nums2)):
            pl[(x, y)].append(i)
        points = []
        for i, (x, y) in enumerate(zip(nums1, nums2)):
            if len(pl[(x, y)]) > 1:
                return [i, pl[(x, y)][1]]
            points.append((x, y, i))
        points.sort()
        _, pi, pj = dfs(0, len(points) - 1)
        return [pi, pj]
```

#### Java

```java
class Solution {
    private List<int[]> points = new ArrayList<>();

    public int[] beautifulPair(int[] nums1, int[] nums2) {
        int n = nums1.length;
        Map<Long, List<Integer>> pl = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            long z = f(nums1[i], nums2[i]);
            pl.computeIfAbsent(z, k -> new ArrayList<>()).add(i);
        }
        for (int i = 0; i < n; ++i) {
            long z = f(nums1[i], nums2[i]);
            if (pl.get(z).size() > 1) {
                return new int[] {i, pl.get(z).get(1)};
            }
            points.add(new int[] {nums1[i], nums2[i], i});
        }
        points.sort((a, b) -> a[0] - b[0]);
        int[] ans = dfs(0, points.size() - 1);
        return new int[] {ans[1], ans[2]};
    }

    private long f(int x, int y) {
        return x * 100000L + y;
    }

    private int dist(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    private int[] dfs(int l, int r) {
        if (l >= r) {
            return new int[] {1 << 30, -1, -1};
        }
        int m = (l + r) >> 1;
        int x = points.get(m)[0];
        int[] t1 = dfs(l, m);
        int[] t2 = dfs(m + 1, r);
        if (t1[0] > t2[0]
            || (t1[0] == t2[0] && (t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2])))) {
            t1 = t2;
        }
        List<int[]> t = new ArrayList<>();
        for (int i = l; i <= r; ++i) {
            if (Math.abs(points.get(i)[0] - x) <= t1[0]) {
                t.add(points.get(i));
            }
        }
        t.sort((a, b) -> a[1] - b[1]);
        for (int i = 0; i < t.size(); ++i) {
            for (int j = i + 1; j < t.size(); ++j) {
                if (t.get(j)[1] - t.get(i)[1] > t1[0]) {
                    break;
                }
                int pi = Math.min(t.get(i)[2], t.get(j)[2]);
                int pj = Math.max(t.get(i)[2], t.get(j)[2]);
                int d = dist(t.get(i)[0], t.get(i)[1], t.get(j)[0], t.get(j)[1]);
                if (d < t1[0] || (d == t1[0] && (pi < t1[1] || (pi == t1[1] && pj < t1[2])))) {
                    t1 = new int[] {d, pi, pj};
                }
            }
        }
        return t1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> beautifulPair(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<long long, vector<int>> pl;
        for (int i = 0; i < n; ++i) {
            pl[f(nums1[i], nums2[i])].push_back(i);
        }
        vector<tuple<int, int, int>> points;
        for (int i = 0; i < n; ++i) {
            long long z = f(nums1[i], nums2[i]);
            if (pl[z].size() > 1) {
                return {i, pl[z][1]};
            }
            points.emplace_back(nums1[i], nums2[i], i);
        }

        function<tuple<int, int, int>(int, int)> dfs = [&](int l, int r) -> tuple<int, int, int> {
            if (l >= r) {
                return {1 << 30, -1, -1};
            }
            int m = (l + r) >> 1;
            int x = get<0>(points[m]);
            auto t1 = dfs(l, m);
            auto t2 = dfs(m + 1, r);
            if (get<0>(t1) > get<0>(t2) || (get<0>(t1) == get<0>(t2) && (get<1>(t1) > get<1>(t2) || (get<1>(t1) == get<1>(t2) && get<2>(t1) > get<2>(t2))))) {
                swap(t1, t2);
            }
            vector<tuple<int, int, int>> t;
            for (int i = l; i <= r; ++i) {
                if (abs(get<0>(points[i]) - x) <= get<0>(t1)) {
                    t.emplace_back(points[i]);
                }
            }
            sort(t.begin(), t.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
                return get<1>(a) < get<1>(b);
            });
            for (int i = 0; i < t.size(); ++i) {
                for (int j = i + 1; j < t.size(); ++j) {
                    if (get<1>(t[j]) - get<1>(t[i]) > get<0>(t1)) {
                        break;
                    }
                    int pi = min(get<2>(t[i]), get<2>(t[j]));
                    int pj = max(get<2>(t[i]), get<2>(t[j]));
                    int d = dist(get<0>(t[i]), get<1>(t[i]), get<0>(t[j]), get<1>(t[j]));
                    if (d < get<0>(t1) || (d == get<0>(t1) && (pi < get<1>(t1) || (pi == get<1>(t1) && pj < get<2>(t1))))) {
                        t1 = {d, pi, pj};
                    }
                }
            }
            return t1;
        };

        sort(points.begin(), points.end());
        auto [_, pi, pj] = dfs(0, points.size() - 1);
        return {pi, pj};
    }

    long long f(int x, int y) {
        return x * 100000LL + y;
    }

    int dist(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};
```

#### Go

```go
func beautifulPair(nums1 []int, nums2 []int) []int {
	n := len(nums1)
	pl := map[[2]int][]int{}
	for i := 0; i < n; i++ {
		k := [2]int{nums1[i], nums2[i]}
		pl[k] = append(pl[k], i)
	}
	points := [][3]int{}
	for i := 0; i < n; i++ {
		k := [2]int{nums2[i], nums1[i]}
		if len(pl[k]) > 1 {
			return []int{pl[k][0], pl[k][1]}
		}
		points = append(points, [3]int{nums1[i], nums2[i], i})
	}
	sort.Slice(points, func(i, j int) bool { return points[i][0] < points[j][0] })

	var dfs func(l, r int) [3]int
	dfs = func(l, r int) [3]int {
		if l >= r {
			return [3]int{1 << 30, -1, -1}
		}
		m := (l + r) >> 1
		x := points[m][0]
		t1 := dfs(l, m)
		t2 := dfs(m+1, r)
		if t1[0] > t2[0] || (t1[0] == t2[0] && (t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2]))) {
			t1 = t2
		}
		t := [][3]int{}
		for i := l; i <= r; i++ {
			if abs(points[i][0]-x) <= t1[0] {
				t = append(t, points[i])
			}
		}
		sort.Slice(t, func(i, j int) bool { return t[i][1] < t[j][1] })
		for i := 0; i < len(t); i++ {
			for j := i + 1; j < len(t); j++ {
				if t[j][1]-t[i][1] > t1[0] {
					break
				}
				pi := min(t[i][2], t[j][2])
				pj := max(t[i][2], t[j][2])
				d := dist(t[i][0], t[i][1], t[j][0], t[j][1])
				if d < t1[0] || (d == t1[0] && (pi < t1[1] || (pi == t1[1] && pj < t1[2]))) {
					t1 = [3]int{d, pi, pj}
				}
			}
		}
		return t1
	}
	ans := dfs(0, n-1)
	return []int{ans[1], ans[2]}
}

func dist(x1, y1, x2, y2 int) int {
	return abs(x1-x2) + abs(y1-y2)
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
function beautifulPair(nums1: number[], nums2: number[]): number[] {
    const pl: Map<number, number[]> = new Map();
    const n = nums1.length;
    for (let i = 0; i < n; ++i) {
        const z = f(nums1[i], nums2[i]);
        if (!pl.has(z)) {
            pl.set(z, []);
        }
        pl.get(z)!.push(i);
    }
    const points: number[][] = [];
    for (let i = 0; i < n; ++i) {
        const z = f(nums1[i], nums2[i]);
        if (pl.get(z)!.length > 1) {
            return [i, pl.get(z)![1]];
        }
        points.push([nums1[i], nums2[i], i]);
    }
    points.sort((a, b) => a[0] - b[0]);

    const dfs = (l: number, r: number): number[] => {
        if (l >= r) {
            return [1 << 30, -1, -1];
        }
        const m = (l + r) >> 1;
        const x = points[m][0];
        let t1 = dfs(l, m);
        let t2 = dfs(m + 1, r);
        if (
            t1[0] > t2[0] ||
            (t1[0] == t2[0] && (t1[1] > t2[1] || (t1[1] == t2[1] && t1[2] > t2[2])))
        ) {
            t1 = t2;
        }
        const t: number[][] = [];
        for (let i = l; i <= r; ++i) {
            if (Math.abs(points[i][0] - x) <= t1[0]) {
                t.push(points[i]);
            }
        }
        t.sort((a, b) => a[1] - b[1]);
        for (let i = 0; i < t.length; ++i) {
            for (let j = i + 1; j < t.length; ++j) {
                if (t[j][1] - t[i][1] > t1[0]) {
                    break;
                }
                const pi = Math.min(t[i][2], t[j][2]);
                const pj = Math.max(t[i][2], t[j][2]);
                const d = dist(t[i][0], t[i][1], t[j][0], t[j][1]);
                if (d < t1[0] || (d == t1[0] && (pi < t1[1] || (pi == t1[1] && pj < t1[2])))) {
                    t1 = [d, pi, pj];
                }
            }
        }
        return t1;
    };
    return dfs(0, n - 1).slice(1);
}

function dist(x1: number, y1: number, x2: number, y2: number): number {
    return Math.abs(x1 - x2) + Math.abs(y1 - y2);
}

function f(x: number, y: number): number {
    return x * 100000 + y;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2614. 对角线上的质数](https://leetcode.cn/problems/prime-in-diagonal){#2614}

{{< tabs "2614" >}}

{{% tab "python" %}}
```python
class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            return all(x % i for i in range(2, int(sqrt(x)) + 1))

        n = len(nums)
        ans = 0
        for i, row in enumerate(nums):
            if is_prime(row[i]):
                ans = max(ans, row[i])
            if is_prime(row[n - i - 1]):
                ans = max(ans, row[n - i - 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int diagonalPrime(int[][] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime(nums[i][i])) {
                ans = Math.max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                ans = Math.max(ans, nums[i][n - i - 1]);
            }
        }
        return ans;
    }

    private boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i <= x / i; ++i) {
            if (x % i == 0) {
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
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                ans = max(ans, nums[i][n - i - 1]);
            }
        }
        return ans;
    }

    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i <= x / i; ++i) {
            if (x % i == 0) {
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
func diagonalPrime(nums [][]int) (ans int) {
	n := len(nums)
	for i, row := range nums {
		if isPrime(row[i]) {
			ans = max(ans, row[i])
		}
		if isPrime(row[n-i-1]) {
			ans = max(ans, row[n-i-1])
		}
	}
	return
}

func isPrime(x int) bool {
	if x < 2 {
		return false
	}
	for i := 2; i <= x/i; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function diagonalPrime(nums: number[][]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (isPrime(nums[i][i])) {
            ans = Math.max(ans, nums[i][i]);
        }
        if (isPrime(nums[i][n - i - 1])) {
            ans = Math.max(ans, nums[i][n - i - 1]);
        }
    }
    return ans;
}

function isPrime(x: number): boolean {
    if (x < 2) {
        return false;
    }
    for (let i = 2; i <= Math.floor(x / i); ++i) {
        if (x % i === 0) {
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
    pub fn diagonal_prime(nums: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let n = nums.len();

        for (i, row) in nums.iter().enumerate() {
            if Self::is_prime(row[i]) && row[i] > ans {
                ans = row[i];
            }
            if Self::is_prime(row[n - i - 1]) && row[n - i - 1] > ans {
                ans = row[n - i - 1];
            }
        }

        ans
    }

    fn is_prime(n: i32) -> bool {
        if n < 2 {
            return false;
        }

        let upper = (n as f64).sqrt() as i32;
        for i in 2..=upper {
            if n % i == 0 {
                return false;
            }
        }

        true
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} nums
 * @return {number}
 */
var diagonalPrime = function (nums) {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        if (isPrime(nums[i][i])) {
            ans = Math.max(ans, nums[i][i]);
        }
        if (isPrime(nums[i][n - i - 1])) {
            ans = Math.max(ans, nums[i][n - i - 1]);
        }
    }
    return ans;
};

function isPrime(x) {
    if (x < 2) {
        return false;
    }
    for (let i = 2; i * i <= x; i++) {
        if (x % i === 0) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>nums</code> 。</p>

<p>返回位于 <code>nums</code> 至少一条 <strong>对角线</strong> 上的最大 <strong>质数</strong> 。如果任一对角线上均不存在质数，返回<em> 0 。</em></p>

<p>注意：</p>

<ul>
	<li>如果某个整数大于 <code>1</code> ，且不存在除 <code>1</code> 和自身之外的正整数因子，则认为该整数是一个质数。</li>
	<li>如果存在整数 <code>i</code> ，使得&nbsp;<code>nums[i][i] = val</code> 或者&nbsp;<code>nums[i][nums.length - i - 1]= val</code> ，则认为整数 <code>val</code> 位于 <code>nums</code> 的一条对角线上。</li>
</ul>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2614.Prime%20In%20Diagonal/images/screenshot-2023-03-06-at-45648-pm.png" style="width: 181px; height: 121px;" /></p>

<p>在上图中，一条对角线是 <strong>[1,5,9]</strong> ，而另一条对角线是<strong> [3,5,7]</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[5,6,7],[9,10,11]]
<strong>输出：</strong>11
<strong>解释：</strong>数字 1、3、6、9 和 11 是所有 "位于至少一条对角线上" 的数字。由于 11 是最大的质数，故返回 11 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,2,3],[5,17,7],[9,11,10]]
<strong>输出：</strong>17
<strong>解释：</strong>数字 1、3、9、10 和 17 是所有满足"位于至少一条对角线上"的数字。由于 17 是最大的质数，故返回 17 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 300</code></li>
	<li><code>nums.length == nums<sub>i</sub>.length</code></li>
	<li><code>1 &lt;= nums<span style="">[i][j]</span>&nbsp;&lt;= 4*10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学 + 模拟

我们实现一个函数 `is_prime`，判断一个数是否为质数。

然后遍历数组，判断对角线上的数是否为质数，如果是，更新答案。

时间复杂度 $O(n \times \sqrt{M})$，其中 $n$ 和 $M$ 分别为数组的行数和数组中的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        def is_prime(x: int) -> bool:
            if x < 2:
                return False
            return all(x % i for i in range(2, int(sqrt(x)) + 1))

        n = len(nums)
        ans = 0
        for i, row in enumerate(nums):
            if is_prime(row[i]):
                ans = max(ans, row[i])
            if is_prime(row[n - i - 1]):
                ans = max(ans, row[n - i - 1])
        return ans
```

#### Java

```java
class Solution {
    public int diagonalPrime(int[][] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime(nums[i][i])) {
                ans = Math.max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                ans = Math.max(ans, nums[i][n - i - 1]);
            }
        }
        return ans;
    }

    private boolean isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i <= x / i; ++i) {
            if (x % i == 0) {
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
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime(nums[i][i])) {
                ans = max(ans, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1])) {
                ans = max(ans, nums[i][n - i - 1]);
            }
        }
        return ans;
    }

    bool isPrime(int x) {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i <= x / i; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func diagonalPrime(nums [][]int) (ans int) {
	n := len(nums)
	for i, row := range nums {
		if isPrime(row[i]) {
			ans = max(ans, row[i])
		}
		if isPrime(row[n-i-1]) {
			ans = max(ans, row[n-i-1])
		}
	}
	return
}

func isPrime(x int) bool {
	if x < 2 {
		return false
	}
	for i := 2; i <= x/i; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function diagonalPrime(nums: number[][]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (isPrime(nums[i][i])) {
            ans = Math.max(ans, nums[i][i]);
        }
        if (isPrime(nums[i][n - i - 1])) {
            ans = Math.max(ans, nums[i][n - i - 1]);
        }
    }
    return ans;
}

function isPrime(x: number): boolean {
    if (x < 2) {
        return false;
    }
    for (let i = 2; i <= Math.floor(x / i); ++i) {
        if (x % i === 0) {
            return false;
        }
    }
    return true;
}
```

#### Rust

```rust
impl Solution {
    pub fn diagonal_prime(nums: Vec<Vec<i32>>) -> i32 {
        let mut ans = 0;
        let n = nums.len();

        for (i, row) in nums.iter().enumerate() {
            if Self::is_prime(row[i]) && row[i] > ans {
                ans = row[i];
            }
            if Self::is_prime(row[n - i - 1]) && row[n - i - 1] > ans {
                ans = row[n - i - 1];
            }
        }

        ans
    }

    fn is_prime(n: i32) -> bool {
        if n < 2 {
            return false;
        }

        let upper = (n as f64).sqrt() as i32;
        for i in 2..=upper {
            if n % i == 0 {
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
 * @param {number[][]} nums
 * @return {number}
 */
var diagonalPrime = function (nums) {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        if (isPrime(nums[i][i])) {
            ans = Math.max(ans, nums[i][i]);
        }
        if (isPrime(nums[i][n - i - 1])) {
            ans = Math.max(ans, nums[i][n - i - 1]);
        }
    }
    return ans;
};

function isPrime(x) {
    if (x < 2) {
        return false;
    }
    for (let i = 2; i * i <= x; i++) {
        if (x % i === 0) {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2615. 等值距离和](https://leetcode.cn/problems/sum-of-distances){#2615}

{{< tabs "2615" >}}

{{% tab "python" %}}
```python
class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        ans = [0] * len(nums)
        for idx in d.values():
            left, right = 0, sum(idx) - len(idx) * idx[0]
            for i in range(len(idx)):
                ans[idx[i]] = left + right
                if i + 1 < len(idx):
                    left += (idx[i + 1] - idx[i]) * (i + 1)
                    right -= (idx[i + 1] - idx[i]) * (len(idx) - i - 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        Map<Integer, List<Integer>> d = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            d.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        for (var idx : d.values()) {
            int m = idx.size();
            long left = 0;
            long right = -1L * m * idx.get(0);
            for (int i : idx) {
                right += i;
            }
            for (int i = 0; i < m; ++i) {
                ans[idx.get(i)] = left + right;
                if (i + 1 < m) {
                    left += (idx.get(i + 1) - idx.get(i)) * (i + 1L);
                    right -= (idx.get(i + 1) - idx.get(i)) * (m - i - 1L);
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
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> d;
        for (int i = 0; i < n; ++i) {
            d[nums[i]].push_back(i);
        }
        for (auto& [_, idx] : d) {
            int m = idx.size();
            long long left = 0;
            long long right = -1LL * m * idx[0];
            for (int i : idx) {
                right += i;
            }
            for (int i = 0; i < m; ++i) {
                ans[idx[i]] = left + right;
                if (i + 1 < m) {
                    left += (idx[i + 1] - idx[i]) * (i + 1);
                    right -= (idx[i + 1] - idx[i]) * (m - i - 1);
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
func distance(nums []int) []int64 {
	n := len(nums)
	ans := make([]int64, n)
	d := map[int][]int{}
	for i, x := range nums {
		d[x] = append(d[x], i)
	}
	for _, idx := range d {
		m := len(idx)
		left, right := 0, -m*idx[0]
		for _, i := range idx {
			right += i
		}
		for i := range idx {
			ans[idx[i]] = int64(left + right)
			if i+1 < m {
				left += (idx[i+1] - idx[i]) * (i + 1)
				right -= (idx[i+1] - idx[i]) * (m - i - 1)
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。现有一个长度等于 <code>nums.length</code> 的数组 <code>arr</code> 。对于满足 <code>nums[j] == nums[i]</code> 且 <code>j != i</code> 的所有 <code>j</code> ，<code>arr[i]</code> 等于所有 <code>|i - j|</code> 之和。如果不存在这样的 <code>j</code> ，则令 <code>arr[i]</code> 等于 <code>0</code> 。</p>

<p>返回数组<em> </em><code>arr</code><em> 。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,1,1,2]
<strong>输出：</strong>[5,0,3,4,0]
<strong>解释：</strong>
i = 0 ，nums[0] == nums[2] 且 nums[0] == nums[3] 。因此，arr[0] = |0 - 2| + |0 - 3| = 5 。 
i = 1 ，arr[1] = 0 因为不存在值等于 3 的其他下标。
i = 2 ，nums[2] == nums[0] 且 nums[2] == nums[3] 。因此，arr[2] = |2 - 0| + |2 - 3| = 3 。
i = 3 ，nums[3] == nums[0] 且 nums[3] == nums[2] 。因此，arr[3] = |3 - 0| + |3 - 2| = 4 。 
i = 4 ，arr[4] = 0 因为不存在值等于 2 的其他下标。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,5,3]
<strong>输出：</strong>[0,0,0]
<strong>解释：</strong>因为 nums 中的元素互不相同，对于所有 i ，都有 arr[i] = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

我们先用哈希表 $d$ 记录数组 $nums$ 中每个元素对应的下标列表，即 $d[x]$ 表示数组 $nums$ 中所有值为 $x$ 的下标列表。

对于哈希表 $d$ 中的每个值列表 $idx$，我们可以计算出 $idx$ 中每个下标 $i$ 对应的 $arr[i]$ 的值。对于第一个下标 $idx[0]$，右边所有下标距离 $idx[0]$ 的和 $right=\sum_{i=0}^{m-1} - idx[0] \times m$。接下来我们遍历 $idx$，每一次计算得到 $ans[idx[i]] = left + right$，然后更新 $left$ 和 $right$，即 $left = left + (idx[i+1] - idx[i]) \times (i+1)$，而 $right = right - (idx[i+1] - idx[i]) \times (m-i-1)$。

遍历结束后，我们得到了数组 $nums$ 中每个元素对应的 $arr$ 的值，即 $ans$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        d = defaultdict(list)
        for i, x in enumerate(nums):
            d[x].append(i)
        ans = [0] * len(nums)
        for idx in d.values():
            left, right = 0, sum(idx) - len(idx) * idx[0]
            for i in range(len(idx)):
                ans[idx[i]] = left + right
                if i + 1 < len(idx):
                    left += (idx[i + 1] - idx[i]) * (i + 1)
                    right -= (idx[i + 1] - idx[i]) * (len(idx) - i - 1)
        return ans
```

#### Java

```java
class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        Map<Integer, List<Integer>> d = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            d.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        for (var idx : d.values()) {
            int m = idx.size();
            long left = 0;
            long right = -1L * m * idx.get(0);
            for (int i : idx) {
                right += i;
            }
            for (int i = 0; i < m; ++i) {
                ans[idx.get(i)] = left + right;
                if (i + 1 < m) {
                    left += (idx.get(i + 1) - idx.get(i)) * (i + 1L);
                    right -= (idx.get(i + 1) - idx.get(i)) * (m - i - 1L);
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
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> d;
        for (int i = 0; i < n; ++i) {
            d[nums[i]].push_back(i);
        }
        for (auto& [_, idx] : d) {
            int m = idx.size();
            long long left = 0;
            long long right = -1LL * m * idx[0];
            for (int i : idx) {
                right += i;
            }
            for (int i = 0; i < m; ++i) {
                ans[idx[i]] = left + right;
                if (i + 1 < m) {
                    left += (idx[i + 1] - idx[i]) * (i + 1);
                    right -= (idx[i + 1] - idx[i]) * (m - i - 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func distance(nums []int) []int64 {
	n := len(nums)
	ans := make([]int64, n)
	d := map[int][]int{}
	for i, x := range nums {
		d[x] = append(d[x], i)
	}
	for _, idx := range d {
		m := len(idx)
		left, right := 0, -m*idx[0]
		for _, i := range idx {
			right += i
		}
		for i := range idx {
			ans[idx[i]] = int64(left + right)
			if i+1 < m {
				left += (idx[i+1] - idx[i]) * (i + 1)
				right -= (idx[i+1] - idx[i]) * (m - i - 1)
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

# [2616. 最小化数对的最大差值](https://leetcode.cn/problems/minimize-the-maximum-difference-of-pairs){#2616}

{{< tabs "2616" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        def check(diff: int) -> bool:
            cnt = i = 0
            while i < len(nums) - 1:
                if nums[i + 1] - nums[i] <= diff:
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt >= p

        nums.sort()
        return bisect_left(range(nums[-1] - nums[0] + 1), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length;
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (count(nums, mid) >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private int count(int[] nums, int diff) {
        int cnt = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i + 1] - nums[i] <= diff) {
                ++cnt;
                ++i;
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
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        auto check = [&](int diff) -> bool {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i + 1] - nums[i] <= diff) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
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
func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	n := len(nums)
	r := nums[n-1] - nums[0] + 1
	return sort.Search(r, func(diff int) bool {
		cnt := 0
		for i := 0; i < n-1; i++ {
			if nums[i+1]-nums[i] <= diff {
				cnt++
				i++
			}
		}
		return cnt >= p
	})
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimizeMax(nums: number[], p: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let l = 0,
        r = nums[n - 1] - nums[0] + 1;
    const check = (diff: number): boolean => {
        let cnt = 0;
        for (let i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= diff) {
                ++cnt;
                ++i;
            }
        }
        return cnt >= p;
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
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
        nums.sort();
        let n = nums.len();
        let (mut l, mut r) = (0, nums[n - 1] - nums[0] + 1);

        let check = |diff: i32| -> bool {
            let mut cnt = 0;
            let mut i = 0;
            while i < n - 1 {
                if nums[i + 1] - nums[i] <= diff {
                    cnt += 1;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            cnt >= p
        };

        while l < r {
            let mid = (l + r) / 2;
            if check(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        l
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinimizeMax(int[] nums, int p) {
        Array.Sort(nums);
        int n = nums.Length;
        int l = 0, r = nums[n - 1] - nums[0] + 1;

        bool check(int diff) {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i + 1] - nums[i] <= diff) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
        }

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
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $p
     * @return Integer
     */
    function minimizeMax($nums, $p) {
        sort($nums);
        $n = count($nums);
        $l = 0;
        $r = $nums[$n - 1] - $nums[0] + 1;

        $check = function ($diff) use ($nums, $n, $p) {
            $cnt = 0;
            for ($i = 0; $i < $n - 1; ++$i) {
                if ($nums[$i + 1] - $nums[$i] <= $diff) {
                    ++$cnt;
                    ++$i;
                }
            }
            return $cnt >= $p;
        };

        while ($l < $r) {
            $mid = intdiv($l + $r, 2);
            if ($check($mid)) {
                $r = $mid;
            } else {
                $l = $mid + 1;
            }
        }

        return $l;
    }
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func minimizeMax(_ nums: [Int], _ p: Int) -> Int {
        var nums = nums.sorted()
        let n = nums.count
        var l = 0
        var r = nums[n - 1] - nums[0] + 1

        func check(_ diff: Int) -> Bool {
            var cnt = 0
            var i = 0
            while i < n - 1 {
                if nums[i + 1] - nums[i] <= diff {
                    cnt += 1
                    i += 2
                } else {
                    i += 1
                }
            }
            return cnt >= p
        }

        while l < r {
            let mid = (l + r) >> 1
            if check(mid) {
                r = mid
            } else {
                l = mid + 1
            }
        }

        return l
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>p</code>&nbsp;。请你从&nbsp;<code>nums</code>&nbsp;中找到&nbsp;<code>p</code> 个下标对，每个下标对对应数值取差值，你需要使得这 <code>p</code> 个差值的&nbsp;<strong>最大值</strong>&nbsp;<strong>最小</strong>。同时，你需要确保每个下标在这&nbsp;<code>p</code>&nbsp;个下标对中最多出现一次。</p>

<p>对于一个下标对&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;，这一对的差值为&nbsp;<code>|nums[i] - nums[j]|</code>&nbsp;，其中&nbsp;<code>|x|</code>&nbsp;表示 <code>x</code>&nbsp;的 <strong>绝对值</strong>&nbsp;。</p>

<p>请你返回 <code>p</code>&nbsp;个下标对对应数值 <strong>最大差值</strong>&nbsp;的 <strong>最小值</strong>&nbsp;。我们定义空集的最大值为零。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [10,1,2,7,1,3], p = 2
<b>输出：</b>1
<b>解释：</b>第一个下标对选择 1 和 4 ，第二个下标对选择 2 和 5 。
最大差值为 max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1 。所以我们返回 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,2,1,2], p = 1
<b>输出：</b>0
<b>解释：</b>选择下标 1 和 3 构成下标对。差值为 |2 - 2| = 0 ，这是最大差值的最小值。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= p &lt;= (nums.length)/2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + 贪心

我们注意到，最大差值具备单调性，即如果最大差值 $x$ 满足条件，那么 $x-1$ 也一定满足条件。因此我们可以使用二分查找的方法，找到最小的满足条件的最大差值。

我们可以将数组 $\textit{nums}$ 排序，然后枚举最大差值 $x$，判断是否存在 $p$ 个下标对，每个下标对对应数值取差值的最大值不超过 $x$。如果存在，那么我们就可以将 $x$ 减小，否则我们就将 $x$ 增大。

判断是否存在 $p$ 个下标对，每个下标对对应数值取差值的最大值不超过 $x$，可以使用贪心的方法。我们从左到右遍历数组 $\textit{nums}$，对于当前遍历到的下标 $i$，如果 $i+1$ 位置的数与 $i$ 位置的数的差值不超过 $x$，那么我们就可以将 $i$ 和 $i+1$ 位置的数作为一个下标对，更新下标对的数量 $cnt$，然后将 $i$ 的值增加 $2$。否则，我们就将 $i$ 的值增加 $1$。遍历结束，如果 $cnt$ 的值大于等于 $p$，那么就说明存在 $p$ 个下标对，每个下标对对应数值取差值的最大值不超过 $x$，否则就说明不存在。

时间复杂度 $O(n \times (\log n + \log m))$，其中 $n$ 是数组 $\textit{nums}$ 的长度，而 $m$ 是数组 $\textit{nums}$ 中的最大值与最小值的差值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        def check(diff: int) -> bool:
            cnt = i = 0
            while i < len(nums) - 1:
                if nums[i + 1] - nums[i] <= diff:
                    cnt += 1
                    i += 2
                else:
                    i += 1
            return cnt >= p

        nums.sort()
        return bisect_left(range(nums[-1] - nums[0] + 1), True, key=check)
```

#### Java

```java
class Solution {
    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length;
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        while (l < r) {
            int mid = (l + r) >>> 1;
            if (count(nums, mid) >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private int count(int[] nums, int diff) {
        int cnt = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i + 1] - nums[i] <= diff) {
                ++cnt;
                ++i;
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
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        auto check = [&](int diff) -> bool {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i + 1] - nums[i] <= diff) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
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
func minimizeMax(nums []int, p int) int {
	sort.Ints(nums)
	n := len(nums)
	r := nums[n-1] - nums[0] + 1
	return sort.Search(r, func(diff int) bool {
		cnt := 0
		for i := 0; i < n-1; i++ {
			if nums[i+1]-nums[i] <= diff {
				cnt++
				i++
			}
		}
		return cnt >= p
	})
}
```

#### TypeScript

```ts
function minimizeMax(nums: number[], p: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let l = 0,
        r = nums[n - 1] - nums[0] + 1;
    const check = (diff: number): boolean => {
        let cnt = 0;
        for (let i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= diff) {
                ++cnt;
                ++i;
            }
        }
        return cnt >= p;
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

#### Rust

```rust
impl Solution {
    pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
        nums.sort();
        let n = nums.len();
        let (mut l, mut r) = (0, nums[n - 1] - nums[0] + 1);

        let check = |diff: i32| -> bool {
            let mut cnt = 0;
            let mut i = 0;
            while i < n - 1 {
                if nums[i + 1] - nums[i] <= diff {
                    cnt += 1;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            cnt >= p
        };

        while l < r {
            let mid = (l + r) / 2;
            if check(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        l
    }
}
```

#### C#

```cs
public class Solution {
    public int MinimizeMax(int[] nums, int p) {
        Array.Sort(nums);
        int n = nums.Length;
        int l = 0, r = nums[n - 1] - nums[0] + 1;

        bool check(int diff) {
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (nums[i + 1] - nums[i] <= diff) {
                    ++cnt;
                    ++i;
                }
            }
            return cnt >= p;
        }

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
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $p
     * @return Integer
     */
    function minimizeMax($nums, $p) {
        sort($nums);
        $n = count($nums);
        $l = 0;
        $r = $nums[$n - 1] - $nums[0] + 1;

        $check = function ($diff) use ($nums, $n, $p) {
            $cnt = 0;
            for ($i = 0; $i < $n - 1; ++$i) {
                if ($nums[$i + 1] - $nums[$i] <= $diff) {
                    ++$cnt;
                    ++$i;
                }
            }
            return $cnt >= $p;
        };

        while ($l < $r) {
            $mid = intdiv($l + $r, 2);
            if ($check($mid)) {
                $r = $mid;
            } else {
                $l = $mid + 1;
            }
        }

        return $l;
    }
}
```

#### Swift

```swift
class Solution {
    func minimizeMax(_ nums: [Int], _ p: Int) -> Int {
        var nums = nums.sorted()
        let n = nums.count
        var l = 0
        var r = nums[n - 1] - nums[0] + 1

        func check(_ diff: Int) -> Bool {
            var cnt = 0
            var i = 0
            while i < n - 1 {
                if nums[i + 1] - nums[i] <= diff {
                    cnt += 1
                    i += 2
                } else {
                    i += 1
                }
            }
            return cnt >= p
        }

        while l < r {
            let mid = (l + r) >> 1
            if check(mid) {
                r = mid
            } else {
                l = mid + 1
            }
        }

        return l
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2617. 网格图中最少访问的格子数](https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid){#2617}

{{< tabs "2617" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumVisitedCells(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dist = [[-1] * n for _ in range(m)]
        dist[0][0] = 1
        row = [[] for _ in range(m)]
        col = [[] for _ in range(n)]
        for i in range(m):
            for j in range(n):
                while row[i] and grid[i][row[i][0][1]] + row[i][0][1] < j:
                    heappop(row[i])
                if row[i] and (dist[i][j] == -1 or dist[i][j] > row[i][0][0] + 1):
                    dist[i][j] = row[i][0][0] + 1
                while col[j] and grid[col[j][0][1]][j] + col[j][0][1] < i:
                    heappop(col[j])
                if col[j] and (dist[i][j] == -1 or dist[i][j] > col[j][0][0] + 1):
                    dist[i][j] = col[j][0][0] + 1
                if dist[i][j] != -1:
                    heappush(row[i], (dist[i][j], j))
                    heappush(col[j], (dist[i][j], i))
        return dist[-1][-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumVisitedCells(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        PriorityQueue<int[]>[] row = new PriorityQueue[m];
        PriorityQueue<int[]>[] col = new PriorityQueue[n];
        for (int i = 0; i < m; ++i) {
            Arrays.fill(dist[i], -1);
            row[i] = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        }
        for (int i = 0; i < n; ++i) {
            col[i] = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        }
        dist[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!row[i].isEmpty() && grid[i][row[i].peek()[1]] + row[i].peek()[1] < j) {
                    row[i].poll();
                }
                if (!row[i].isEmpty() && (dist[i][j] == -1 || row[i].peek()[0] + 1 < dist[i][j])) {
                    dist[i][j] = row[i].peek()[0] + 1;
                }
                while (!col[j].isEmpty() && grid[col[j].peek()[1]][j] + col[j].peek()[1] < i) {
                    col[j].poll();
                }
                if (!col[j].isEmpty() && (dist[i][j] == -1 || col[j].peek()[0] + 1 < dist[i][j])) {
                    dist[i][j] = col[j].peek()[0] + 1;
                }
                if (dist[i][j] != -1) {
                    row[i].offer(new int[] {dist[i][j], j});
                    col[j].offer(new int[] {dist[i][j], i});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> row[m];
        priority_queue<pii, vector<pii>, greater<pii>> col[n];
        dist[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!row[i].empty() && grid[i][row[i].top().second] + row[i].top().second < j) {
                    row[i].pop();
                }
                if (!row[i].empty() && (dist[i][j] == -1 || row[i].top().first + 1 < dist[i][j])) {
                    dist[i][j] = row[i].top().first + 1;
                }
                while (!col[j].empty() && grid[col[j].top().second][j] + col[j].top().second < i) {
                    col[j].pop();
                }
                if (!col[j].empty() && (dist[i][j] == -1 || col[j].top().first + 1 < dist[i][j])) {
                    dist[i][j] = col[j].top().first + 1;
                }
                if (dist[i][j] != -1) {
                    row[i].emplace(dist[i][j], j);
                    col[j].emplace(dist[i][j], i);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumVisitedCells(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dist := make([][]int, m)
	row := make([]hp, m)
	col := make([]hp, n)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = -1
		}
	}
	dist[0][0] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for len(row[i]) > 0 && grid[i][row[i][0].second]+row[i][0].second < j {
				heap.Pop(&row[i])
			}
			if len(row[i]) > 0 && (dist[i][j] == -1 || row[i][0].first+1 < dist[i][j]) {
				dist[i][j] = row[i][0].first + 1
			}
			for len(col[j]) > 0 && grid[col[j][0].second][j]+col[j][0].second < i {
				heap.Pop(&col[j])
			}
			if len(col[j]) > 0 && (dist[i][j] == -1 || col[j][0].first+1 < dist[i][j]) {
				dist[i][j] = col[j][0].first + 1
			}
			if dist[i][j] != -1 {
				heap.Push(&row[i], pair{dist[i][j], j})
				heap.Push(&col[j], pair{dist[i][j], i})
			}
		}
	}
	return dist[m-1][n-1]
}

type pair struct {
	first  int
	second int
}

type hp []pair

func (a hp) Len() int      { return len(a) }
func (a hp) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool {
	return a[i].first < a[j].first || (a[i].first == a[j].first && a[i].second < a[j].second)
}
func (a *hp) Push(x any) { *a = append(*a, x.(pair)) }
func (a *hp) Pop() any   { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;整数矩阵&nbsp;<code>grid</code>&nbsp;。你一开始的位置在&nbsp;<strong>左上角</strong>&nbsp;格子&nbsp;<code>(0, 0)</code>&nbsp;。</p>

<p>当你在格子&nbsp;<code>(i, j)</code>&nbsp;的时候，你可以移动到以下格子之一：</p>

<ul>
	<li>满足 <code>j &lt; k &lt;= grid[i][j] + j</code>&nbsp;的格子&nbsp;<code>(i, k)</code>&nbsp;（向右移动），或者</li>
	<li>满足 <code>i &lt; k &lt;= grid[i][j] + i</code>&nbsp;的格子&nbsp;<code>(k, j)</code>&nbsp;（向下移动）。</li>
</ul>

<p>请你返回到达 <strong>右下角</strong>&nbsp;格子&nbsp;<code>(m - 1, n - 1)</code>&nbsp;需要经过的最少移动格子数，如果无法到达右下角格子，请你返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2617.Minimum%20Number%20of%20Visited%20Cells%20in%20a%20Grid/images/ex1.png" style="width: 271px; height: 171px;"></p>

<pre><b>输入：</b>grid = [[3,4,2,1],[4,2,3,1],[2,1,0,0],[2,4,0,0]]
<b>输出：</b>4
<b>解释：</b>上图展示了到达右下角格子经过的 4 个格子。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2617.Minimum%20Number%20of%20Visited%20Cells%20in%20a%20Grid/images/ex2.png" style="width: 271px; height: 171px;"></p>

<pre><b>输入：</b>grid = [[3,4,2,1],[4,2,1,1],[2,1,1,0],[3,4,1,0]]
<b>输出：</b>3
<strong>解释：</strong>上图展示了到达右下角格子经过的 3 个格子。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2617.Minimum%20Number%20of%20Visited%20Cells%20in%20a%20Grid/images/ex3.png" style="width: 181px; height: 81px;"></p>

<pre><b>输入：</b>grid = [[2,1,0],[1,0,0]]
<b>输出：</b>-1
<b>解释：</b>无法到达右下角格子。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= grid[i][j] &lt; m * n</code></li>
	<li><code>grid[m - 1][n - 1] == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列

我们记网格的行数为 $m$，列数为 $n$，定义 $dist[i][j]$ 表示从坐标 $(0, 0)$ 移动到坐标 $(i, j)$ 的最短距离，初始时 $dist[0][0] = 1$，其它 $dist[i][j]=-1$。

对于每个格子 $(i, j)$，它可以从上边或者左边的格子移动过来。如果是从上边的格子 $(i', j)$ 移动过来，其中 $0 \leq i' \lt i$，那么 $(i', j)$ 需要满足 $grid[i'][j] + i' \geq i$，我们要从这些格子中选择一个距离最近的格子。

因此，我们可以对每一列 $j$ 维护一个优先队列（小根堆），优先队列中每个元素是一个二元组 $(dist[i][j], i)$，表示从坐标 $(0, 0)$ 移动到坐标 $(i, j)$ 的最短距离为 $dist[i][j]$。当我们考虑坐标 $(i, j)$ 时，我们只需要从优先队列中取出队头元素 $(dist[i'][j], i')$，如果 $grid[i'][j] + i' \geq i$，那么就可以从坐标 $(i', j)$ 移动到坐标 $(i, j)$，此时我们就可以更新 $dist[i][j]$ 的值，即 $dist[i][j] = dist[i'][j] + 1$，并将 $(dist[i][j], i)$ 加入到优先队列中。

同理，我们可以对每一行 $i$ 维护一个优先队列，然后进行与上述类似的操作。

最终，我们可以得到从坐标 $(0, 0)$ 移动到坐标 $(m - 1, n - 1)$ 的最短距离 $dist[m - 1][n - 1]$，即为答案。

时间复杂度 $O(m \times n \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumVisitedCells(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dist = [[-1] * n for _ in range(m)]
        dist[0][0] = 1
        row = [[] for _ in range(m)]
        col = [[] for _ in range(n)]
        for i in range(m):
            for j in range(n):
                while row[i] and grid[i][row[i][0][1]] + row[i][0][1] < j:
                    heappop(row[i])
                if row[i] and (dist[i][j] == -1 or dist[i][j] > row[i][0][0] + 1):
                    dist[i][j] = row[i][0][0] + 1
                while col[j] and grid[col[j][0][1]][j] + col[j][0][1] < i:
                    heappop(col[j])
                if col[j] and (dist[i][j] == -1 or dist[i][j] > col[j][0][0] + 1):
                    dist[i][j] = col[j][0][0] + 1
                if dist[i][j] != -1:
                    heappush(row[i], (dist[i][j], j))
                    heappush(col[j], (dist[i][j], i))
        return dist[-1][-1]
```

#### Java

```java
class Solution {
    public int minimumVisitedCells(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] dist = new int[m][n];
        PriorityQueue<int[]>[] row = new PriorityQueue[m];
        PriorityQueue<int[]>[] col = new PriorityQueue[n];
        for (int i = 0; i < m; ++i) {
            Arrays.fill(dist[i], -1);
            row[i] = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        }
        for (int i = 0; i < n; ++i) {
            col[i] = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        }
        dist[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!row[i].isEmpty() && grid[i][row[i].peek()[1]] + row[i].peek()[1] < j) {
                    row[i].poll();
                }
                if (!row[i].isEmpty() && (dist[i][j] == -1 || row[i].peek()[0] + 1 < dist[i][j])) {
                    dist[i][j] = row[i].peek()[0] + 1;
                }
                while (!col[j].isEmpty() && grid[col[j].peek()[1]][j] + col[j].peek()[1] < i) {
                    col[j].poll();
                }
                if (!col[j].isEmpty() && (dist[i][j] == -1 || col[j].peek()[0] + 1 < dist[i][j])) {
                    dist[i][j] = col[j].peek()[0] + 1;
                }
                if (dist[i][j] != -1) {
                    row[i].offer(new int[] {dist[i][j], j});
                    col[j].offer(new int[] {dist[i][j], i});
                }
            }
        }
        return dist[m - 1][n - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> row[m];
        priority_queue<pii, vector<pii>, greater<pii>> col[n];
        dist[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                while (!row[i].empty() && grid[i][row[i].top().second] + row[i].top().second < j) {
                    row[i].pop();
                }
                if (!row[i].empty() && (dist[i][j] == -1 || row[i].top().first + 1 < dist[i][j])) {
                    dist[i][j] = row[i].top().first + 1;
                }
                while (!col[j].empty() && grid[col[j].top().second][j] + col[j].top().second < i) {
                    col[j].pop();
                }
                if (!col[j].empty() && (dist[i][j] == -1 || col[j].top().first + 1 < dist[i][j])) {
                    dist[i][j] = col[j].top().first + 1;
                }
                if (dist[i][j] != -1) {
                    row[i].emplace(dist[i][j], j);
                    col[j].emplace(dist[i][j], i);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
```

#### Go

```go
func minimumVisitedCells(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dist := make([][]int, m)
	row := make([]hp, m)
	col := make([]hp, n)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = -1
		}
	}
	dist[0][0] = 1
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for len(row[i]) > 0 && grid[i][row[i][0].second]+row[i][0].second < j {
				heap.Pop(&row[i])
			}
			if len(row[i]) > 0 && (dist[i][j] == -1 || row[i][0].first+1 < dist[i][j]) {
				dist[i][j] = row[i][0].first + 1
			}
			for len(col[j]) > 0 && grid[col[j][0].second][j]+col[j][0].second < i {
				heap.Pop(&col[j])
			}
			if len(col[j]) > 0 && (dist[i][j] == -1 || col[j][0].first+1 < dist[i][j]) {
				dist[i][j] = col[j][0].first + 1
			}
			if dist[i][j] != -1 {
				heap.Push(&row[i], pair{dist[i][j], j})
				heap.Push(&col[j], pair{dist[i][j], i})
			}
		}
	}
	return dist[m-1][n-1]
}

type pair struct {
	first  int
	second int
}

type hp []pair

func (a hp) Len() int      { return len(a) }
func (a hp) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a hp) Less(i, j int) bool {
	return a[i].first < a[j].first || (a[i].first == a[j].first && a[i].second < a[j].second)
}
func (a *hp) Push(x any) { *a = append(*a, x.(pair)) }
func (a *hp) Pop() any   { l := len(*a); t := (*a)[l-1]; *a = (*a)[:l-1]; return t }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2618. 检查是否是类的对象实例](https://leetcode.cn/problems/check-if-object-instance-of-class){#2618}

{{< tabs "2618" >}}

{{% tab "ts" %}}
```ts
function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (classFunction === null || classFunction === undefined) {
        return false;
    }
    while (obj !== null && obj !== undefined) {
        const proto = Object.getPrototypeOf(obj);
        if (proto === classFunction.prototype) {
            return true;
        }
        obj = proto;
    }
    return false;
}

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个函数，检查给定的值是否是给定类或超类的实例。</p>

<p>可以传递给函数的数据类型没有限制。例如，值或类可能是&nbsp; <code>undefined</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; checkIfInstance(new Date(), Date)
<b>输出：</b>true
<strong>解释：</strong>根据定义，Date 构造函数返回的对象是 Date 的一个实例。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; { class Animal {}; class Dog extends Animal {}; return checkIfInstance(new Dog(), Animal); }
<b>输出：</b>true
<strong>解释：</strong>
class Animal {};
class Dog extends Animal {};
checkIfInstanceOf(new Dog(), Animal); // true

Dog 是 Animal 的子类。因此，Dog 对象同时是 Dog 和 Animal 的实例。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; checkIfInstance(Date, Date)
<b>输出：</b>false
<strong>解释：</strong>日期的构造函数在逻辑上不能是其自身的实例。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<b>输入：</b>func = () =&gt; checkIfInstance(5, Number)
<b>输出：</b>true
<strong>解释：</strong>5 是一个 Number。注意，"instanceof" 关键字将返回 false。</pre>

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
function checkIfInstanceOf(obj: any, classFunction: any): boolean {
    if (classFunction === null || classFunction === undefined) {
        return false;
    }
    while (obj !== null && obj !== undefined) {
        const proto = Object.getPrototypeOf(obj);
        if (proto === classFunction.prototype) {
            return true;
        }
        obj = proto;
    }
    return false;
}

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2619. 数组原型对象的最后一个元素](https://leetcode.cn/problems/array-prototype-last){#2619}

{{< tabs "2619" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function () {
    return this.length ? this.at(-1) : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */

export {};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一段代码实现一个数组方法，使任何数组都可以调用 <code>array.last()</code> 方法，这个方法将返回数组最后一个元素。如果数组中没有元素，则返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>你可以假设数组是 <code>JSON.parse</code> 的输出结果。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre>
<b>输入：</b>nums = [null, {}, 3]
<b>输出：</b>3
<b>解释</b>：调用 nums.last() 后返回最后一个元素： 3。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<b>输入：</b>nums = []
<b>输出：</b>-1
<strong>解释：</strong>因为此数组没有元素，所以应该返回 -1。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>arr</code> 是一个有效的 JSON 数组</li>
	<li><code>0 &lt;= arr.length &lt;= 1000</code></li>
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
declare global {
    interface Array<T> {
        last(): T | -1;
    }
}

Array.prototype.last = function () {
    return this.length ? this.at(-1) : -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */

export {};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
