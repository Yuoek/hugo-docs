---
title: "2870_使数组为空的最少操作次数"
date: 2025-10-08T18:39:37+08:00
weight: 8
tags: [Pandas, 位运算, 前缀和, 动态规划, 哈希表, 图, 数组, 树, 深度优先搜索, 滑动窗口, 计数, 记忆化搜索, 贪心]
---

{{< markmap >}}
### [2870_使数组为空的最少操作次数](#2870)
#### [贪心](#2870)
#### [数组](#2870)
#### [哈希表](#2870)
#### [计数](#2870)
### [2871_将数组分割成最多数目的子数组](#2871)
#### [贪心](#2871)
#### [位运算](#2871)
#### [数组](#2871)
### [2872_可以被 K 整除连通块的最大数目](#2872)
#### [树](#2872)
#### [深度优先搜索](#2872)
### [2873_有序三元组中的最大值 I](#2873)
#### [数组](#2873)
### [2874_有序三元组中的最大值 II](#2874)
#### [数组](#2874)
### [2875_无限数组的最短子数组](#2875)
#### [数组](#2875)
#### [哈希表](#2875)
#### [前缀和](#2875)
#### [滑动窗口](#2875)
### [2876_有向图访问计数](#2876)
#### [图](#2876)
#### [记忆化搜索](#2876)
#### [动态规划](#2876)
### [2877_从表中创建 DataFrame](#2877)
#### [Pandas](#2877)
### [2878_获取 DataFrame 的大小](#2878)
#### [Pandas](#2878)
### [2879_显示前三行](#2879)
#### [Pandas](#2879)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2870_使数组为空的最少操作次数
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2871_将数组分割成最多数目的子数组
___
#### 贪心
___
#### 位运算
___
#### 数组
---
### 2872_可以被 K 整除连通块的最大数目
___
#### 树
___
#### 深度优先搜索
---
### 2873_有序三元组中的最大值 I
___
#### 数组
---
### 2874_有序三元组中的最大值 II
___
#### 数组
---
### 2875_无限数组的最短子数组
___
#### 数组
___
#### 哈希表
___
#### 前缀和
___
#### 滑动窗口
---
### 2876_有向图访问计数
___
#### 图
___
#### 记忆化搜索
___
#### 动态规划
---
### 2877_从表中创建 DataFrame
___
#### Pandas
---
### 2878_获取 DataFrame 的大小
___
#### Pandas
---
### 2879_显示前三行
___
#### Pandas
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| Pandas | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 图 |
| 数组 | 树 | 深度优先搜索 |
| 滑动窗口 | 计数 | 记忆化搜索 |
| 贪心 |  |  |

# [2870. 使数组为空的最少操作次数](https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-empty){#2870}

{{< tabs "2870" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = Counter(nums)
        ans = 0
        for c in count.values():
            if c == 1:
                return -1
            ans += (c + 2) // 3
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            // count.put(num, count.getOrDefault(num, 0) + 1);
            count.merge(num, 1, Integer::sum);
        }
        int ans = 0;
        for (int c : count.values()) {
            if (c < 2) {
                return -1;
            }
            int r = c % 3;
            int d = c / 3;
            switch (r) {
                case (0) -> {
                    ans += d;
                }
                default -> {
                    ans += d + 1;
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
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        int ans = 0;
        for (auto& [_, c] : count) {
            if (c < 2) {
                return -1;
            }
            ans += (c + 2) / 3;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(nums []int) (ans int) {
	count := map[int]int{}
	for _, num := range nums {
		count[num]++
	}
	for _, c := range count {
		if c < 2 {
			return -1
		}
		ans += (c + 2) / 3
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(nums: number[]): number {
    const count: Map<number, number> = new Map();
    for (const num of nums) {
        count.set(num, (count.get(num) ?? 0) + 1);
    }
    let ans = 0;
    for (const [_, c] of count) {
        if (c < 2) {
            return -1;
        }
        ans += ((c + 2) / 3) | 0;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的正整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以对数组执行以下两种操作 <strong>任意次</strong>&nbsp;：</p>

<ul>
	<li>从数组中选择 <strong>两个</strong>&nbsp;值 <strong>相等</strong>&nbsp;的元素，并将它们从数组中 <strong>删除</strong>&nbsp;。</li>
	<li>从数组中选择 <strong>三个</strong>&nbsp;值 <strong>相等</strong>&nbsp;的元素，并将它们从数组中 <strong>删除</strong>&nbsp;。</li>
</ul>

<p>请你返回使数组为空的 <strong>最少</strong>&nbsp;操作次数，如果无法达成，请返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,3,2,2,4,2,3,4]
<b>输出：</b>4
<b>解释：</b>我们可以执行以下操作使数组为空：
- 对下标为 0 和 3 的元素执行第一种操作，得到 nums = [3,3,2,4,2,3,4] 。
- 对下标为 2 和 4 的元素执行第一种操作，得到 nums = [3,3,4,3,4] 。
- 对下标为 0 ，1 和 3 的元素执行第二种操作，得到 nums = [4,4] 。
- 对下标为 0 和 1 的元素执行第一种操作，得到 nums = [] 。
至少需要 4 步操作使数组为空。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,2,2,3,3]
<b>输出：</b>-1
<b>解释：</b>无法使数组为空。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 贪心

我们用一个哈希表 $count$ 统计数组中每个元素出现的次数，然后遍历哈希表，对于每个元素 $x$，如果 $x$ 出现的次数为 $c$，那么我们可以进行 $\lfloor \frac{c+2}{3} \rfloor$ 次操作，将 $x$ 删除，最后我们返回所有元素的操作次数之和即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = Counter(nums)
        ans = 0
        for c in count.values():
            if c == 1:
                return -1
            ans += (c + 2) // 3
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            // count.put(num, count.getOrDefault(num, 0) + 1);
            count.merge(num, 1, Integer::sum);
        }
        int ans = 0;
        for (int c : count.values()) {
            if (c < 2) {
                return -1;
            }
            int r = c % 3;
            int d = c / 3;
            switch (r) {
                case (0) -> {
                    ans += d;
                }
                default -> {
                    ans += d + 1;
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
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        int ans = 0;
        for (auto& [_, c] : count) {
            if (c < 2) {
                return -1;
            }
            ans += (c + 2) / 3;
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(nums []int) (ans int) {
	count := map[int]int{}
	for _, num := range nums {
		count[num]++
	}
	for _, c := range count {
		if c < 2 {
			return -1
		}
		ans += (c + 2) / 3
	}
	return
}
```

#### TypeScript

```ts
function minOperations(nums: number[]): number {
    const count: Map<number, number> = new Map();
    for (const num of nums) {
        count.set(num, (count.get(num) ?? 0) + 1);
    }
    let ans = 0;
    for (const [_, c] of count) {
        if (c < 2) {
            return -1;
        }
        ans += ((c + 2) / 3) | 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2871. 将数组分割成最多数目的子数组](https://leetcode.cn/problems/split-array-into-maximum-number-of-subarrays){#2871}

{{< tabs "2871" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubarrays(self, nums: List[int]) -> int:
        score, ans = -1, 1
        for num in nums:
            score &= num
            if score == 0:
                score = -1
                ans += 1
        return 1 if ans == 1 else ans - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubarrays(int[] nums) {
        int score = -1;
        int ans = 1;
        for (int num : nums) {
            score &= num;
            if (score == 0) {
                ans++;
                score = -1;
            }
        }
        return ans == 1 ? 1 : ans - 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int score = -1, ans = 1;
        for (int num : nums) {
            score &= num;
            if (score == 0) {
                --score;
                ++ans;
            }
        }
        return ans == 1 ? 1 : ans - 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubarrays(nums []int) int {
	ans, score := 1, -1
	for _, num := range nums {
		score &= num
		if score == 0 {
			score--
			ans++
		}
	}
	if ans == 1 {
		return 1
	}
	return ans - 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubarrays(nums: number[]): number {
    let [ans, score] = [1, -1];
    for (const num of nums) {
        score &= num;
        if (score === 0) {
            --score;
            ++ans;
        }
    }
    return ans == 1 ? 1 : ans - 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个只包含 <strong>非负</strong>&nbsp;整数的数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>我们定义满足 <code>l &lt;= r</code>&nbsp;的子数组&nbsp;<code>nums[l..r]</code>&nbsp;的分数为&nbsp;<code>nums[l] AND nums[l + 1] AND ... AND nums[r]</code>&nbsp;，其中&nbsp;<strong>AND</strong>&nbsp;是按位与运算。</p>

<p>请你将数组分割成一个或者更多子数组，满足：</p>

<ul>
	<li><strong>每个</strong> 元素都&nbsp;<strong>只</strong>&nbsp;属于一个子数组。</li>
	<li>子数组分数之和尽可能<strong>&nbsp;小</strong>&nbsp;。</li>
</ul>

<p>请你在满足以上要求的条件下，返回<strong>&nbsp;最多</strong>&nbsp;可以得到多少个子数组。</p>

<p>一个 <strong>子数组</strong>&nbsp;是一个数组中一段连续的元素。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,0,2,0,1,2]
<b>输出：</b>3
<strong>解释：</strong>我们可以将数组分割成以下子数组：
- [1,0] 。子数组分数为 1 AND 0 = 0 。
- [2,0] 。子数组分数为 2 AND 0 = 0 。
- [1,2] 。子数组分数为 1 AND 2 = 0 。
分数之和为 0 + 0 + 0 = 0 ，是我们可以得到的最小分数之和。
在分数之和为 0 的前提下，最多可以将数组分割成 3 个子数组。所以返回 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,7,1,3]
<b>输出：</b>1
<b>解释：</b>我们可以将数组分割成一个子数组：[5,7,1,3] ，分数为 1 ，这是可以得到的最小总分数。
在总分数为 1 的前提下，最多可以将数组分割成 1 个子数组。所以返回 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 位运算

我们初始化一个变量 $score$，用来记录当前子数组的分数，初始时 $score = -1$。然后我们遍历数组，对于每个元素 $num$，我们将 $score$ 与 $num$ 进行按位与运算，然后将结果赋值给 $score$。如果 $score = 0$，说明当前子数组的分数为 $0$，我们就可以将当前子数组分割出来，然后将 $score$ 重置为 $-1$。最后我们返回分割出的子数组的个数。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubarrays(self, nums: List[int]) -> int:
        score, ans = -1, 1
        for num in nums:
            score &= num
            if score == 0:
                score = -1
                ans += 1
        return 1 if ans == 1 else ans - 1
```

#### Java

```java
class Solution {
    public int maxSubarrays(int[] nums) {
        int score = -1;
        int ans = 1;
        for (int num : nums) {
            score &= num;
            if (score == 0) {
                ans++;
                score = -1;
            }
        }
        return ans == 1 ? 1 : ans - 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int score = -1, ans = 1;
        for (int num : nums) {
            score &= num;
            if (score == 0) {
                --score;
                ++ans;
            }
        }
        return ans == 1 ? 1 : ans - 1;
    }
};
```

#### Go

```go
func maxSubarrays(nums []int) int {
	ans, score := 1, -1
	for _, num := range nums {
		score &= num
		if score == 0 {
			score--
			ans++
		}
	}
	if ans == 1 {
		return 1
	}
	return ans - 1
}
```

#### TypeScript

```ts
function maxSubarrays(nums: number[]): number {
    let [ans, score] = [1, -1];
    for (const num of nums) {
        score &= num;
        if (score === 0) {
            --score;
            ++ans;
        }
    }
    return ans == 1 ? 1 : ans - 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2872. 可以被 K 整除连通块的最大数目](https://leetcode.cn/problems/maximum-number-of-k-divisible-components){#2872}

{{< tabs "2872" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        def dfs(i: int, fa: int) -> int:
            s = values[i]
            for j in g[i]:
                if j != fa:
                    s += dfs(j, i)
            nonlocal ans
            ans += s % k == 0
            return s

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int ans;
    private List<Integer>[] g;
    private int[] values;
    private int k;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        this.values = values;
        this.k = k;
        dfs(0, -1);
        return ans;
    }

    private long dfs(int i, int fa) {
        long s = values[i];
        for (int j : g[i]) {
            if (j != fa) {
                s += dfs(j, i);
            }
        }
        ans += s % k == 0 ? 1 : 0;
        return s;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans = 0;
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<long long(int, int)> dfs = [&](int i, int fa) {
            long long s = values[i];
            for (int j : g[i]) {
                if (j != fa) {
                    s += dfs(j, i);
                }
            }
            ans += s % k == 0;
            return s;
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) int
	dfs = func(i, fa int) int {
		s := values[i]
		for _, j := range g[i] {
			if j != fa {
				s += dfs(j, i)
			}
		}
		if s%k == 0 {
			ans++
		}
		return s
	}
	dfs(0, -1)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxKDivisibleComponents(
    n: number,
    edges: number[][],
    values: number[],
    k: number,
): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let ans = 0;
    const dfs = (i: number, fa: number): number => {
        let s = values[i];
        for (const j of g[i]) {
            if (j !== fa) {
                s += dfs(j, i);
            }
        }
        if (s % k === 0) {
            ++ans;
        }
        return s;
    };
    dfs(0, -1);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵 <code>n</code>&nbsp;个节点的无向树，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。给你整数&nbsp;<code>n</code>&nbsp;和一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;有一条边。</p>

<p>同时给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>values</code>&nbsp;，其中&nbsp;<code>values[i]</code>&nbsp;是第 <code>i</code>&nbsp;个节点的 <strong>值</strong>&nbsp;。再给你一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以从树中删除一些边，也可以一条边也不删，得到若干连通块。一个 <strong>连通块的值</strong> 定义为连通块中所有节点值之和。如果所有连通块的值都可以被 <code>k</code>&nbsp;整除，那么我们说这是一个 <strong>合法分割</strong>&nbsp;。</p>

<p>请你返回所有合法分割中，<b>连通块数目的最大值</b>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2872.Maximum%20Number%20of%20K-Divisible%20Components/images/example12-cropped2svg.jpg" style="width: 1024px; height: 453px;" /></p>

<pre>
<b>输入：</b>n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
<b>输出：</b>2
<b>解释：</b>我们删除节点 1 和 2 之间的边。这是一个合法分割，因为：
- 节点 1 和 3 所在连通块的值为 values[1] + values[3] = 12 。
- 节点 0 ，2 和 4 所在连通块的值为 values[0] + values[2] + values[4] = 6 。
最多可以得到 2 个连通块的合法分割。</pre>

<p><strong class="example">示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2872.Maximum%20Number%20of%20K-Divisible%20Components/images/example21svg-1.jpg" style="width: 999px; height: 338px;" /></p>

<pre>
<b>输入：</b>n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
<b>输出：</b>3
<b>解释：</b>我们删除节点 0 和 2 ，以及节点 0 和 1 之间的边。这是一个合法分割，因为：
- 节点 0 的连通块的值为 values[0] = 3 。
- 节点 2 ，5 和 6 所在连通块的值为 values[2] + values[5] + values[6] = 9 。
- 节点 1 ，3 和 4 的连通块的值为 values[1] + values[3] + values[4] = 6 。
最多可以得到 3 个连通块的合法分割。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li><code>values.length == n</code></li>
	<li><code>0 &lt;= values[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
	<li><code>values</code>&nbsp;之和可以被 <code>k</code>&nbsp;整除。</li>
	<li>输入保证&nbsp;<code>edges</code>&nbsp;是一棵无向树。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们注意到，题目保证了整棵树的节点值之和可以被 $k$ 整除，因此，如果我们删除一棵元素和能被 $k$ 整除的边，那么剩下的每个连通块的节点值之和也一定可以被 $k$ 整除。

因此，我们可以使用深度优先搜索的方法，从根节点开始遍历整棵树，对于每个节点，我们计算其子树中所有节点值之和，如果该和能被 $k$ 整除，那么我们就将答案加一。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是树中的节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxKDivisibleComponents(
        self, n: int, edges: List[List[int]], values: List[int], k: int
    ) -> int:
        def dfs(i: int, fa: int) -> int:
            s = values[i]
            for j in g[i]:
                if j != fa:
                    s += dfs(j, i)
            nonlocal ans
            ans += s % k == 0
            return s

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        ans = 0
        dfs(0, -1)
        return ans
```

#### Java

```java
class Solution {
    private int ans;
    private List<Integer>[] g;
    private int[] values;
    private int k;

    public int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        for (int[] e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        this.values = values;
        this.k = k;
        dfs(0, -1);
        return ans;
    }

    private long dfs(int i, int fa) {
        long s = values[i];
        for (int j : g[i]) {
            if (j != fa) {
                s += dfs(j, i);
            }
        }
        ans += s % k == 0 ? 1 : 0;
        return s;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans = 0;
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        function<long long(int, int)> dfs = [&](int i, int fa) {
            long long s = values[i];
            for (int j : g[i]) {
                if (j != fa) {
                    s += dfs(j, i);
                }
            }
            ans += s % k == 0;
            return s;
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func maxKDivisibleComponents(n int, edges [][]int, values []int, k int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	var dfs func(int, int) int
	dfs = func(i, fa int) int {
		s := values[i]
		for _, j := range g[i] {
			if j != fa {
				s += dfs(j, i)
			}
		}
		if s%k == 0 {
			ans++
		}
		return s
	}
	dfs(0, -1)
	return
}
```

#### TypeScript

```ts
function maxKDivisibleComponents(
    n: number,
    edges: number[][],
    values: number[],
    k: number,
): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    let ans = 0;
    const dfs = (i: number, fa: number): number => {
        let s = values[i];
        for (const j of g[i]) {
            if (j !== fa) {
                s += dfs(j, i);
            }
        }
        if (s % k === 0) {
            ++ans;
        }
        return s;
    };
    dfs(0, -1);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2873. 有序三元组中的最大值 I](https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i){#2873}

{{< tabs "2873" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans = mx = mx_diff = 0
        for x in nums:
            ans = max(ans, mx_diff * x)
            mx_diff = max(mx_diff, mx - x)
            mx = max(mx, x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = Math.max(ans, mxDiff * x);
            mxDiff = Math.max(mxDiff, mx - x);
            mx = Math.max(mx, x);
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
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = max(ans, mxDiff * x);
            mxDiff = max(mxDiff, 1LL * mx - x);
            mx = max(mx, x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTripletValue(nums []int) int64 {
	ans, mx, mxDiff := 0, 0, 0
	for _, x := range nums {
		ans = max(ans, mxDiff*x)
		mxDiff = max(mxDiff, mx-x)
		mx = max(mx, x)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumTripletValue(nums: number[]): number {
    let [ans, mx, mxDiff] = [0, 0, 0];
    for (const x of nums) {
        ans = Math.max(ans, mxDiff * x);
        mxDiff = Math.max(mxDiff, mx - x);
        mx = Math.max(mx, x);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut mx: i32 = 0;
        let mut mx_diff: i32 = 0;

        for &x in &nums {
            ans = ans.max(mx_diff as i64 * x as i64);
            mx_diff = mx_diff.max(mx - x);
            mx = mx.max(x);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。</p>

<p>请你从所有满足&nbsp;<code>i &lt; j &lt; k</code> 的下标三元组 <code>(i, j, k)</code> 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 <code>0</code> 。</p>

<p><strong>下标三元组</strong> <code>(i, j, k)</code> 的值等于 <code>(nums[i] - nums[j]) * nums[k]</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [12,6,1,2,7]
<strong>输出：</strong>77
<strong>解释：</strong>下标三元组 (0, 2, 4) 的值是 (nums[0] - nums[2]) * nums[4] = 77 。
可以证明不存在值大于 77 的有序下标三元组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,10,3,4,19]
<strong>输出：</strong>133
<strong>解释：</strong>下标三元组 (1, 2, 4) 的值是 (nums[1] - nums[2]) * nums[4] = 133 。
可以证明不存在值大于 133 的有序下标三元组。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>唯一的下标三元组 (0, 1, 2) 的值是一个负数，(nums[0] - nums[1]) * nums[2] = -3 。因此，答案是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护前缀最大值和最大差值

我们用两个变量 $\textit{mx}$ 和 $\textit{mxDiff}$ 分别维护前缀最大值和最大差值，用一个变量 $\textit{ans}$ 维护答案。初始时，这些变量都为 $0$。

接下来，我们枚举数组的每个元素 $x$ 作为 $\textit{nums}[k]$，首先更新答案 $\textit{ans} = \max(\textit{ans}, \textit{mxDiff} \times x)$，然后我们更新最大差值 $\textit{mxDiff} = \max(\textit{mxDiff}, \textit{mx} - x)$，最后更新前缀最大值 $\textit{mx} = \max(\textit{mx}, x)$。

枚举完所有元素后，返回答案 $\textit{ans}$。

时间复杂度 $O(n)$，其中 $n$ 是数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans = mx = mx_diff = 0
        for x in nums:
            ans = max(ans, mx_diff * x)
            mx_diff = max(mx_diff, mx - x)
            mx = max(mx, x)
        return ans
```

#### Java

```java
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = Math.max(ans, mxDiff * x);
            mxDiff = Math.max(mxDiff, mx - x);
            mx = Math.max(mx, x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = max(ans, mxDiff * x);
            mxDiff = max(mxDiff, 1LL * mx - x);
            mx = max(mx, x);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumTripletValue(nums []int) int64 {
	ans, mx, mxDiff := 0, 0, 0
	for _, x := range nums {
		ans = max(ans, mxDiff*x)
		mxDiff = max(mxDiff, mx-x)
		mx = max(mx, x)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maximumTripletValue(nums: number[]): number {
    let [ans, mx, mxDiff] = [0, 0, 0];
    for (const x of nums) {
        ans = Math.max(ans, mxDiff * x);
        mxDiff = Math.max(mxDiff, mx - x);
        mx = Math.max(mx, x);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut mx: i32 = 0;
        let mut mx_diff: i32 = 0;

        for &x in &nums {
            ans = ans.max(mx_diff as i64 * x as i64);
            mx_diff = mx_diff.max(mx - x);
            mx = mx.max(x);
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

# [2874. 有序三元组中的最大值 II](https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-ii){#2874}

{{< tabs "2874" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans = mx = mx_diff = 0
        for x in nums:
            ans = max(ans, mx_diff * x)
            mx_diff = max(mx_diff, mx - x)
            mx = max(mx, x)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = Math.max(ans, mxDiff * x);
            mxDiff = Math.max(mxDiff, mx - x);
            mx = Math.max(mx, x);
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
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = max(ans, mxDiff * x);
            mxDiff = max(mxDiff, 1LL * mx - x);
            mx = max(mx, x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumTripletValue(nums []int) int64 {
	ans, mx, mxDiff := 0, 0, 0
	for _, x := range nums {
		ans = max(ans, mxDiff*x)
		mxDiff = max(mxDiff, mx-x)
		mx = max(mx, x)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumTripletValue(nums: number[]): number {
    let [ans, mx, mxDiff] = [0, 0, 0];
    for (const x of nums) {
        ans = Math.max(ans, mxDiff * x);
        mxDiff = Math.max(mxDiff, mx - x);
        mx = Math.max(mx, x);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut mx: i32 = 0;
        let mut mx_diff: i32 = 0;

        for &x in &nums {
            ans = ans.max(mx_diff as i64 * x as i64);
            mx_diff = mx_diff.max(mx - x);
            mx = mx.max(x);
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。</p>

<p>请你从所有满足&nbsp;<code>i &lt; j &lt; k</code> 的下标三元组 <code>(i, j, k)</code> 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 <code>0</code> 。</p>

<p><strong>下标三元组</strong> <code>(i, j, k)</code> 的值等于 <code>(nums[i] - nums[j]) * nums[k]</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [12,6,1,2,7]
<strong>输出：</strong>77
<strong>解释：</strong>下标三元组 (0, 2, 4) 的值是 (nums[0] - nums[2]) * nums[4] = 77 。
可以证明不存在值大于 77 的有序下标三元组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,10,3,4,19]
<strong>输出：</strong>133
<strong>解释：</strong>下标三元组 (1, 2, 4) 的值是 (nums[1] - nums[2]) * nums[4] = 133 。
可以证明不存在值大于 133 的有序下标三元组。 
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3]
<strong>输出：</strong>0
<strong>解释：</strong>唯一的下标三元组 (0, 1, 2) 的值是一个负数，(nums[0] - nums[1]) * nums[2] = -3 。因此，答案是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护前缀最大值和最大差值

我们用两个变量 $\textit{mx}$ 和 $\textit{mxDiff}$ 分别维护前缀最大值和最大差值，用一个变量 $\textit{ans}$ 维护答案。初始时，这些变量都为 $0$。

接下来，我们枚举数组的每个元素 $x$ 作为 $\textit{nums}[k]$，首先更新答案 $\textit{ans} = \max(\textit{ans}, \textit{mxDiff} \times x)$，然后我们更新最大差值 $\textit{mxDiff} = \max(\textit{mxDiff}, \textit{mx} - x)$，最后更新前缀最大值 $\textit{mx} = \max(\textit{mx}, x)$。

枚举完所有元素后，返回答案 $\textit{ans}$。

时间复杂度 $O(n)$，其中 $n$ 是数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans = mx = mx_diff = 0
        for x in nums:
            ans = max(ans, mx_diff * x)
            mx_diff = max(mx_diff, mx - x)
            mx = max(mx, x)
        return ans
```

#### Java

```java
class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = Math.max(ans, mxDiff * x);
            mxDiff = Math.max(mxDiff, mx - x);
            mx = Math.max(mx, x);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, mxDiff = 0;
        int mx = 0;
        for (int x : nums) {
            ans = max(ans, mxDiff * x);
            mxDiff = max(mxDiff, 1LL * mx - x);
            mx = max(mx, x);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumTripletValue(nums []int) int64 {
	ans, mx, mxDiff := 0, 0, 0
	for _, x := range nums {
		ans = max(ans, mxDiff*x)
		mxDiff = max(mxDiff, mx-x)
		mx = max(mx, x)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maximumTripletValue(nums: number[]): number {
    let [ans, mx, mxDiff] = [0, 0, 0];
    for (const x of nums) {
        ans = Math.max(ans, mxDiff * x);
        mxDiff = Math.max(mxDiff, mx - x);
        mx = Math.max(mx, x);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut mx: i32 = 0;
        let mut mx_diff: i32 = 0;

        for &x in &nums {
            ans = ans.max(mx_diff as i64 * x as i64);
            mx_diff = mx_diff.max(mx - x);
            mx = mx.max(x);
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

# [2875. 无限数组的最短子数组](https://leetcode.cn/problems/minimum-size-subarray-in-infinite-array){#2875}

{{< tabs "2875" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSizeSubarray(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        n = len(nums)
        a = 0
        if target > s:
            a = n * (target // s)
            target -= target // s * s
        if target == s:
            return n
        pos = {0: -1}
        pre = 0
        b = inf
        for i, x in enumerate(nums):
            pre += x
            if (t := pre - target) in pos:
                b = min(b, i - pos[t])
            if (t := pre - (s - target)) in pos:
                b = min(b, n - (i - pos[t]))
            pos[pre] = i
        return -1 if b == inf else a + b
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        long s = Arrays.stream(nums).sum();
        int n = nums.length;
        int a = 0;
        if (target > s) {
            a = n * (target / (int) s);
            target -= target / s * s;
        }
        if (target == s) {
            return n;
        }
        Map<Long, Integer> pos = new HashMap<>();
        pos.put(0L, -1);
        long pre = 0;
        int b = 1 << 30;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            if (pos.containsKey(pre - target)) {
                b = Math.min(b, i - pos.get(pre - target));
            }
            if (pos.containsKey(pre - (s - target))) {
                b = Math.min(b, n - (i - pos.get(pre - (s - target))));
            }
            pos.put(pre, i);
        }
        return b == 1 << 30 ? -1 : a + b;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();
        int a = 0;
        if (target > s) {
            a = n * (target / s);
            target -= target / s * s;
        }
        if (target == s) {
            return n;
        }
        unordered_map<int, int> pos{{0, -1}};
        long long pre = 0;
        int b = 1 << 30;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            if (pos.count(pre - target)) {
                b = min(b, i - pos[pre - target]);
            }
            if (pos.count(pre - (s - target))) {
                b = min(b, n - (i - pos[pre - (s - target)]));
            }
            pos[pre] = i;
        }
        return b == 1 << 30 ? -1 : a + b;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSizeSubarray(nums []int, target int) int {
	s := 0
	for _, x := range nums {
		s += x
	}
	n := len(nums)
	a := 0
	if target > s {
		a = n * (target / s)
		target -= target / s * s
	}
	if target == s {
		return n
	}
	pos := map[int]int{0: -1}
	pre := 0
	b := 1 << 30
	for i, x := range nums {
		pre += x
		if j, ok := pos[pre-target]; ok {
			b = min(b, i-j)
		}
		if j, ok := pos[pre-(s-target)]; ok {
			b = min(b, n-(i-j))
		}
		pos[pre] = i
	}
	if b == 1<<30 {
		return -1
	}
	return a + b
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSizeSubarray(nums: number[], target: number): number {
    const s = nums.reduce((a, b) => a + b);
    const n = nums.length;
    let a = 0;
    if (target > s) {
        a = n * ((target / s) | 0);
        target -= ((target / s) | 0) * s;
    }
    if (target === s) {
        return n;
    }
    const pos: Map<number, number> = new Map();
    let pre = 0;
    pos.set(0, -1);
    let b = Infinity;
    for (let i = 0; i < n; ++i) {
        pre += nums[i];
        if (pos.has(pre - target)) {
            b = Math.min(b, i - pos.get(pre - target)!);
        }
        if (pos.has(pre - (s - target))) {
            b = Math.min(b, n - (i - pos.get(pre - (s - target))!));
        }
        pos.set(pre, i);
    }
    return b === Infinity ? -1 : a + b;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> 和一个整数 <code>target</code> 。</p>

<p>下标从 <strong>0</strong> 开始的数组 <code>infinite_nums</code> 是通过无限地将 nums 的元素追加到自己之后生成的。</p>

<p>请你从 <code>infinite_nums</code> 中找出满足 <strong>元素和</strong> 等于&nbsp;<code>target</code> 的 <strong>最短</strong> 子数组，并返回该子数组的长度。如果不存在满足条件的子数组，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3], target = 5
<strong>输出：</strong>2
<strong>解释：</strong>在这个例子中 infinite_nums = [1,2,3,1,2,3,1,2,...] 。
区间 [1,2] 内的子数组的元素和等于 target = 5 ，且长度 length = 2 。
可以证明，当元素和等于目标值 target = 5 时，2 是子数组的最短长度。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,2,3], target = 4
<strong>输出：</strong>2
<strong>解释：</strong>在这个例子中 infinite_nums = [1,1,1,2,3,1,1,1,2,3,1,1,...].
区间 [4,5] 内的子数组的元素和等于 target = 4 ，且长度 length = 2 。
可以证明，当元素和等于目标值 target = 4 时，2 是子数组的最短长度。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,6,8], target = 3
<strong>输出：</strong>-1
<strong>解释：</strong>在这个例子中 infinite_nums = [2,4,6,8,2,4,6,8,...] 。
可以证明，不存在元素和等于目标值 target = 3 的子数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

我们先算出数组 $nums$ 的元素总和，记为 $s$。

如果 $target \gt s$，那么我们可以将 $target$ 减去 $\lfloor \frac{target}{s} \rfloor \times s$，这样就可以将 $target$ 减小到 $[0, s)$ 的范围内。那么此时子数组的长度为 $a = \lfloor \frac{target}{s} \rfloor \times n$，其中 $n$ 是数组 $nums$ 的长度。

接下来，我们只需要在数组 $nums$ 中，找出长度最短的且元素和等于 $target$ 的子数组，或者长度最短的且前缀和加上后缀和等于 $target$，即子数组元素和等于 $s - target$ 的子数组，记长度为 $b$。我们可以通过前缀和加哈希表的方法，找出这样的子数组。

如果找到了这样的子数组，那么最终的答案就是 $a + b$。否则，答案就是 $-1$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSizeSubarray(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        n = len(nums)
        a = 0
        if target > s:
            a = n * (target // s)
            target -= target // s * s
        if target == s:
            return n
        pos = {0: -1}
        pre = 0
        b = inf
        for i, x in enumerate(nums):
            pre += x
            if (t := pre - target) in pos:
                b = min(b, i - pos[t])
            if (t := pre - (s - target)) in pos:
                b = min(b, n - (i - pos[t]))
            pos[pre] = i
        return -1 if b == inf else a + b
```

#### Java

```java
class Solution {
    public int minSizeSubarray(int[] nums, int target) {
        long s = Arrays.stream(nums).sum();
        int n = nums.length;
        int a = 0;
        if (target > s) {
            a = n * (target / (int) s);
            target -= target / s * s;
        }
        if (target == s) {
            return n;
        }
        Map<Long, Integer> pos = new HashMap<>();
        pos.put(0L, -1);
        long pre = 0;
        int b = 1 << 30;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            if (pos.containsKey(pre - target)) {
                b = Math.min(b, i - pos.get(pre - target));
            }
            if (pos.containsKey(pre - (s - target))) {
                b = Math.min(b, n - (i - pos.get(pre - (s - target))));
            }
            pos.put(pre, i);
        }
        return b == 1 << 30 ? -1 : a + b;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        int n = nums.size();
        int a = 0;
        if (target > s) {
            a = n * (target / s);
            target -= target / s * s;
        }
        if (target == s) {
            return n;
        }
        unordered_map<int, int> pos{{0, -1}};
        long long pre = 0;
        int b = 1 << 30;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            if (pos.count(pre - target)) {
                b = min(b, i - pos[pre - target]);
            }
            if (pos.count(pre - (s - target))) {
                b = min(b, n - (i - pos[pre - (s - target)]));
            }
            pos[pre] = i;
        }
        return b == 1 << 30 ? -1 : a + b;
    }
};
```

#### Go

```go
func minSizeSubarray(nums []int, target int) int {
	s := 0
	for _, x := range nums {
		s += x
	}
	n := len(nums)
	a := 0
	if target > s {
		a = n * (target / s)
		target -= target / s * s
	}
	if target == s {
		return n
	}
	pos := map[int]int{0: -1}
	pre := 0
	b := 1 << 30
	for i, x := range nums {
		pre += x
		if j, ok := pos[pre-target]; ok {
			b = min(b, i-j)
		}
		if j, ok := pos[pre-(s-target)]; ok {
			b = min(b, n-(i-j))
		}
		pos[pre] = i
	}
	if b == 1<<30 {
		return -1
	}
	return a + b
}
```

#### TypeScript

```ts
function minSizeSubarray(nums: number[], target: number): number {
    const s = nums.reduce((a, b) => a + b);
    const n = nums.length;
    let a = 0;
    if (target > s) {
        a = n * ((target / s) | 0);
        target -= ((target / s) | 0) * s;
    }
    if (target === s) {
        return n;
    }
    const pos: Map<number, number> = new Map();
    let pre = 0;
    pos.set(0, -1);
    let b = Infinity;
    for (let i = 0; i < n; ++i) {
        pre += nums[i];
        if (pos.has(pre - target)) {
            b = Math.min(b, i - pos.get(pre - target)!);
        }
        if (pos.has(pre - (s - target))) {
            b = Math.min(b, n - (i - pos.get(pre - (s - target))!));
        }
        pos.set(pre, i);
    }
    return b === Infinity ? -1 : a + b;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2876. 有向图访问计数](https://leetcode.cn/problems/count-visited-nodes-in-a-directed-graph){#2876}

{{< tabs "2876" >}}

{{% tab "python" %}}
```python
class Solution:
    def countVisitedNodes(self, edges: List[int]) -> List[int]:
        n = len(edges)
        ans = [0] * n
        vis = [0] * n
        for i in range(n):
            if not ans[i]:
                cnt, j = 0, i
                while not vis[j]:
                    cnt += 1
                    vis[j] = cnt
                    j = edges[j]
                cycle, total = 0, cnt + ans[j]
                if not ans[j]:
                    cycle = cnt - vis[j] + 1
                    total = cnt
                j = i
                while not ans[j]:
                    ans[j] = max(total, cycle)
                    total -= 1
                    j = edges[j]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] countVisitedNodes(List<Integer> edges) {
        int n = edges.size();
        int[] ans = new int[n];
        int[] vis = new int[n];
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                int cnt = 0, j = i;
                while (vis[j] == 0) {
                    vis[j] = ++cnt;
                    j = edges.get(j);
                }
                int cycle = 0, total = cnt + ans[j];
                if (ans[j] == 0) {
                    cycle = cnt - vis[j] + 1;
                }
                j = i;
                while (ans[j] == 0) {
                    ans[j] = Math.max(total--, cycle);
                    j = edges.get(j);
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
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n), vis(n);
        for (int i = 0; i < n; ++i) {
            if (!ans[i]) {
                int cnt = 0, j = i;
                while (vis[j] == 0) {
                    vis[j] = ++cnt;
                    j = edges[j];
                }
                int cycle = 0, total = cnt + ans[j];
                if (ans[j] == 0) {
                    cycle = cnt - vis[j] + 1;
                }
                j = i;
                while (ans[j] == 0) {
                    ans[j] = max(total--, cycle);
                    j = edges[j];
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
func countVisitedNodes(edges []int) []int {
	n := len(edges)
	ans := make([]int, n)
	vis := make([]int, n)
	for i := range ans {
		if ans[i] == 0 {
			cnt, j := 0, i
			for vis[j] == 0 {
				cnt++
				vis[j] = cnt
				j = edges[j]
			}
			cycle, total := 0, cnt+ans[j]
			if ans[j] == 0 {
				cycle = cnt - vis[j] + 1
			}
			j = i
			for ans[j] == 0 {
				ans[j] = max(total, cycle)
				total--
				j = edges[j]
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countVisitedNodes(edges: number[]): number[] {
    const n = edges.length;
    const ans: number[] = Array(n).fill(0);
    const vis: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        if (ans[i] === 0) {
            let [cnt, j] = [0, i];
            while (vis[j] === 0) {
                vis[j] = ++cnt;
                j = edges[j];
            }
            let [cycle, total] = [0, cnt + ans[j]];
            if (ans[j] === 0) {
                cycle = cnt - vis[j] + 1;
            }
            j = i;
            while (ans[j] === 0) {
                ans[j] = Math.max(total--, cycle);
                j = edges[j];
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

<p>现有一个有向图，其中包含 <code>n</code> 个节点，节点编号从 <code>0</code> 到 <code>n - 1</code> 。此外，该图还包含了 <code>n</code> 条有向边。</p>

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>edges</code> ，其中 <code>edges[i]</code> 表示存在一条从节点 <code>i</code> 到节点 <code>edges[i]</code> 的边。</p>

<p>想象在图上发生以下过程：</p>

<ul>
	<li>你从节点 <code>x</code> 开始，通过边访问其他节点，直到你在<strong> 此过程 </strong>中再次访问到之前已经访问过的节点。</li>
</ul>

<p>返回数组 <code>answer</code> 作为答案，其中 <code>answer[i]</code> 表示如果从节点 <code>i</code> 开始执行该过程，你可以访问到的不同节点数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2876.Count%20Visited%20Nodes%20in%20a%20Directed%20Graph/images/graaphdrawio-1.png" />
<pre>
<strong>输入：</strong>edges = [1,2,0,0]
<strong>输出：</strong>[3,3,3,4]
<strong>解释：</strong>从每个节点开始执行该过程，记录如下：
- 从节点 0 开始，访问节点 0 -&gt; 1 -&gt; 2 -&gt; 0 。访问的不同节点数是 3 。
- 从节点 1 开始，访问节点 1 -&gt; 2 -&gt; 0 -&gt; 1 。访问的不同节点数是 3 。
- 从节点 2 开始，访问节点 2 -&gt; 0 -&gt; 1 -&gt; 2 。访问的不同节点数是 3 。
- 从节点 3 开始，访问节点 3 -&gt; 0 -&gt; 1 -&gt; 2 -&gt; 0 。访问的不同节点数是 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2876.Count%20Visited%20Nodes%20in%20a%20Directed%20Graph/images/graaph2drawio.png" style="width: 191px; height: 251px;" />
<pre>
<strong>输入：</strong>edges = [1,2,3,4,0]
<strong>输出：</strong>[5,5,5,5,5]
<strong>解释：</strong>无论从哪个节点开始，在这个过程中，都可以访问到图中的每一个节点。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == edges.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges[i] &lt;= n - 1</code></li>
	<li><code>edges[i] != i</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：基环树 + 遍历搜索

我们可以用一个数组 $ans$ 记录每个节点的答案，用一个数组 $vis$ 记录每个节点的访问次序。

遍历每个节点 $i$，如果当前节点 $i$ 未被访问，我们就从节点 $i$ 开始遍历，此时有两种情况：

1. 如果遍历过程中，遇到了当前节点出发时走过的节点，那么此次遍历，一定是先走到了环内，然后沿着环走了一圈。对于环外的节点，其答案就是环的长度加上节点到环的距离；对于环内的节点，其答案就是环的长度。
1. 如果遍历过程中，遇到了此前节点出发时走过的节点，那么对于每个走过的节点，其答案就是当前节点到此节点的距离，加上此节点的答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $edges$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countVisitedNodes(self, edges: List[int]) -> List[int]:
        n = len(edges)
        ans = [0] * n
        vis = [0] * n
        for i in range(n):
            if not ans[i]:
                cnt, j = 0, i
                while not vis[j]:
                    cnt += 1
                    vis[j] = cnt
                    j = edges[j]
                cycle, total = 0, cnt + ans[j]
                if not ans[j]:
                    cycle = cnt - vis[j] + 1
                    total = cnt
                j = i
                while not ans[j]:
                    ans[j] = max(total, cycle)
                    total -= 1
                    j = edges[j]
        return ans
```

#### Java

```java
class Solution {
    public int[] countVisitedNodes(List<Integer> edges) {
        int n = edges.size();
        int[] ans = new int[n];
        int[] vis = new int[n];
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                int cnt = 0, j = i;
                while (vis[j] == 0) {
                    vis[j] = ++cnt;
                    j = edges.get(j);
                }
                int cycle = 0, total = cnt + ans[j];
                if (ans[j] == 0) {
                    cycle = cnt - vis[j] + 1;
                }
                j = i;
                while (ans[j] == 0) {
                    ans[j] = Math.max(total--, cycle);
                    j = edges.get(j);
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
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> ans(n), vis(n);
        for (int i = 0; i < n; ++i) {
            if (!ans[i]) {
                int cnt = 0, j = i;
                while (vis[j] == 0) {
                    vis[j] = ++cnt;
                    j = edges[j];
                }
                int cycle = 0, total = cnt + ans[j];
                if (ans[j] == 0) {
                    cycle = cnt - vis[j] + 1;
                }
                j = i;
                while (ans[j] == 0) {
                    ans[j] = max(total--, cycle);
                    j = edges[j];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countVisitedNodes(edges []int) []int {
	n := len(edges)
	ans := make([]int, n)
	vis := make([]int, n)
	for i := range ans {
		if ans[i] == 0 {
			cnt, j := 0, i
			for vis[j] == 0 {
				cnt++
				vis[j] = cnt
				j = edges[j]
			}
			cycle, total := 0, cnt+ans[j]
			if ans[j] == 0 {
				cycle = cnt - vis[j] + 1
			}
			j = i
			for ans[j] == 0 {
				ans[j] = max(total, cycle)
				total--
				j = edges[j]
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function countVisitedNodes(edges: number[]): number[] {
    const n = edges.length;
    const ans: number[] = Array(n).fill(0);
    const vis: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        if (ans[i] === 0) {
            let [cnt, j] = [0, i];
            while (vis[j] === 0) {
                vis[j] = ++cnt;
                j = edges[j];
            }
            let [cycle, total] = [0, cnt + ans[j]];
            if (ans[j] === 0) {
                cycle = cnt - vis[j] + 1;
            }
            j = i;
            while (ans[j] === 0) {
                ans[j] = Math.max(total--, cycle);
                j = edges[j];
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

# [2877. 从表中创建 DataFrame](https://leetcode.cn/problems/create-a-dataframe-from-list){#2877}

{{< tabs "2877" >}}

{{% tab "python" %}}
```python
import pandas as pd


def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个解决方案，基于名为&nbsp;&nbsp;<code>student_data</code>&nbsp;的二维列表&nbsp;<b>创建 </b>一个 DataFrame 。这个二维列表包含一些学生的 ID 和年龄信息。</p>

<p>DataFrame 应该有两列，&nbsp;<code>student_id</code>&nbsp;和&nbsp;<code>age</code>，并且与原始二维列表的顺序相同。</p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：
</strong>student_data:<strong>
</strong><code>[
  [1, 15],
  [2, 11],
  [3, 11],
  [4, 20]
]</code>
<b>输出：</b>
+------------+-----+
| student_id | age |
+------------+-----+
| 1          | 15  |
| 2          | 11  |
| 3          | 11  |
| 4          | 20  |
+------------+-----+
<b>解释：</b>
基于 student_data 创建了一个 DataFrame，包含 student_id 和 age 两列。
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

#### Python3

```python
import pandas as pd


def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2878. 获取 DataFrame 的大小](https://leetcode.cn/problems/get-the-size-of-a-dataframe){#2878}

{{< tabs "2878" >}}

{{% tab "python" %}}
```python
import pandas as pd


def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame <code>players:</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| player_id   | int    |
| name        | object |
| age         | int    |
| position    | object |
| ...         | ...    |
+-------------+--------+
</pre>

<p>编写一个解决方案，计算并显示&nbsp;<code>players</code>&nbsp;的&nbsp;<strong>行数和列数</strong>。</p>

<p>将结果返回为一个数组：</p>

<p><code>[number of rows, number of columns]</code></p>

<p>返回结果格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：
</strong>+-----------+----------+-----+-------------+--------------------+
| player_id | name     | age | position    | team               |
+-----------+----------+-----+-------------+--------------------+
| 846       | Mason    | 21  | Forward     | RealMadrid         |
| 749       | Riley    | 30  | Winger      | Barcelona          |
| 155       | Bob      | 28  | Striker     | ManchesterUnited   |
| 583       | Isabella | 32  | Goalkeeper  | Liverpool          |
| 388       | Zachary  | 24  | Midfielder  | BayernMunich       |
| 883       | Ava      | 23  | Defender    | Chelsea            |
| 355       | Violet   | 18  | Striker     | Juventus           |
| 247       | Thomas   | 27  | Striker     | ParisSaint-Germain |
| 761       | Jack     | 33  | Midfielder  | ManchesterCity     |
| 642       | Charlie  | 36  | Center-back | Arsenal            |
+-----------+----------+-----+-------------+--------------------+<strong>
输出：
</strong>[10, 5]
<b>解释：</b>
这个 DataFrame 包含 10 行和 5 列。
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

#### Python3

```python
import pandas as pd


def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2879. 显示前三行](https://leetcode.cn/problems/display-the-first-three-rows){#2879}

{{< tabs "2879" >}}

{{% tab "python" %}}
```python
import pandas as pd


def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<pre>
DataFrame: <code>employees</code>
+-------------+--------+
| Column Name | Type   |
+-------------+--------+
| employee_id | int    |
| name        | object |
| department  | object |
| salary      | int    |
+-------------+--------+
</pre>

<p>编写一个解决方案，显示这个 DataFrame 的<strong> 前&nbsp;&nbsp;<code>3</code>&nbsp;</strong>行。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<strong>输入：
</strong>DataFrame employees
+-------------+-----------+-----------------------+--------+
| employee_id | name      | department            | salary |
+-------------+-----------+-----------------------+--------+
| 3           | Bob       | Operations            | 48675  |
| 90          | Alice     | Sales                 | 11096  |
| 9           | Tatiana   | Engineering           | 33805  |
| 60          | Annabelle | InformationTechnology | 37678  |
| 49          | Jonathan  | HumanResources        | 23793  |
| 43          | Khaled    | Administration        | 40454  |
+-------------+-----------+-----------------------+--------+
<b>输出：</b>
+-------------+---------+-------------+--------+
| employee_id | name    | department  | salary |
+-------------+---------+-------------+--------+
| 3           | Bob     | Operations  | 48675  |
| 90          | Alice   | Sales       | 11096  |
| 9           | Tatiana | Engineering | 33805  |
+-------------+---------+-------------+--------+
<b>解释：</b>
只有前 3 行被显示。</pre>

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
import pandas as pd


def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
