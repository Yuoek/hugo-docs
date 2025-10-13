---
title: "2170_使数组变成交替数组的最少操作数"
date: 2025-10-08T18:39:03+08:00
weight: 8
tags: [二分查找, 位运算, 分治, 前缀和, 动态规划, 哈希表, 回溯, 广度优先搜索, 归并排序, 排序, 数学, 数据库, 数组, 有序集合, 枚举, 树状数组, 模拟, 状态压缩, 矩阵, 线段树, 计数, 贪心]
---

{{< markmap >}}
### [2170_使数组变成交替数组的最少操作数](#2170)
#### [贪心](#2170)
#### [数组](#2170)
#### [哈希表](#2170)
#### [计数](#2170)
### [2171_拿出最少数目的魔法豆](#2171)
#### [贪心](#2171)
#### [数组](#2171)
#### [枚举](#2171)
#### [前缀和](#2171)
#### [排序](#2171)
### [2172_数组的最大与和](#2172)
#### [位运算](#2172)
#### [数组](#2172)
#### [动态规划](#2172)
#### [状态压缩](#2172)
### [2173_最多连胜的次数 🔒](#2173)
#### [数据库](#2173)
### [2174_通过翻转行或列来去除所有的 1 II 🔒](#2174)
#### [位运算](#2174)
#### [广度优先搜索](#2174)
#### [数组](#2174)
#### [矩阵](#2174)
### [2175_世界排名的变化 🔒](#2175)
#### [数据库](#2175)
### [2176_统计数组中相等且可以被整除的数对](#2176)
#### [数组](#2176)
### [2177_找到和为给定整数的三个连续整数](#2177)
#### [数学](#2177)
#### [模拟](#2177)
### [2178_拆分成最多数目的正偶数之和](#2178)
#### [贪心](#2178)
#### [数学](#2178)
#### [回溯](#2178)
### [2179_统计数组中好三元组数目](#2179)
#### [树状数组](#2179)
#### [线段树](#2179)
#### [数组](#2179)
#### [二分查找](#2179)
#### [分治](#2179)
#### [有序集合](#2179)
#### [归并排序](#2179)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2170_使数组变成交替数组的最少操作数
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2171_拿出最少数目的魔法豆
___
#### 贪心
___
#### 数组
___
#### 枚举
___
#### 前缀和
___
#### 排序
---
### 2172_数组的最大与和
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
---
### 2173_最多连胜的次数 🔒
___
#### 数据库
---
### 2174_通过翻转行或列来去除所有的 1 II 🔒
___
#### 位运算
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 2175_世界排名的变化 🔒
___
#### 数据库
---
### 2176_统计数组中相等且可以被整除的数对
___
#### 数组
---
### 2177_找到和为给定整数的三个连续整数
___
#### 数学
___
#### 模拟
---
### 2178_拆分成最多数目的正偶数之和
___
#### 贪心
___
#### 数学
___
#### 回溯
---
### 2179_统计数组中好三元组数目
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 前缀和 | 动态规划 | 哈希表 |
| 回溯 | 广度优先搜索 | 归并排序 |
| 排序 | 数学 | 数据库 |
| 数组 | 有序集合 | 枚举 |
| 树状数组 | 模拟 | 状态压缩 |
| 矩阵 | 线段树 | 计数 |
| 贪心 |  |  |

# [2170. 使数组变成交替数组的最少操作数](https://leetcode.cn/problems/minimum-operations-to-make-the-array-alternating){#2170}

{{< tabs "2170" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        def f(i: int) -> Tuple[int, int, int, int]:
            k1 = k2 = 0
            cnt = Counter(nums[i::2])
            for k, v in cnt.items():
                if cnt[k1] < v:
                    k2, k1 = k1, k
                elif cnt[k2] < v:
                    k2 = k
            return k1, cnt[k1], k2, cnt[k2]

        a, b = f(0), f(1)
        n = len(nums)
        if a[0] != b[0]:
            return n - (a[1] + b[1])
        return n - max(a[1] + b[3], a[3] + b[1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumOperations(int[] nums) {
        int[] a = f(nums, 0);
        int[] b = f(nums, 1);
        int n = nums.length;
        if (a[0] != b[0]) {
            return n - (a[1] + b[1]);
        }
        return n - Math.max(a[1] + b[3], a[3] + b[1]);
    }

    private int[] f(int[] nums, int i) {
        int k1 = 0, k2 = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (; i < nums.length; i += 2) {
            cnt.merge(nums[i], 1, Integer::sum);
        }
        for (var e : cnt.entrySet()) {
            int k = e.getKey(), v = e.getValue();
            if (cnt.getOrDefault(k1, 0) < v) {
                k2 = k1;
                k1 = k;
            } else if (cnt.getOrDefault(k2, 0) < v) {
                k2 = k;
            }
        }
        return new int[] {k1, cnt.getOrDefault(k1, 0), k2, cnt.getOrDefault(k2, 0)};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto f = [&](int i) -> vector<int> {
            int k1 = 0, k2 = 0;
            unordered_map<int, int> cnt;
            for (; i < nums.size(); i += 2) {
                cnt[nums[i]]++;
            }
            for (auto& [k, v] : cnt) {
                if (!k1 || cnt[k1] < v) {
                    k2 = k1;
                    k1 = k;
                } else if (!k2 || cnt[k2] < v) {
                    k2 = k;
                }
            }
            return {k1, !k1 ? 0 : cnt[k1], k2, !k2 ? 0 : cnt[k2]};
        };
        vector<int> a = f(0);
        vector<int> b = f(1);
        int n = nums.size();
        if (a[0] != b[0]) {
            return n - (a[1] + b[1]);
        }
        return n - max(a[1] + b[3], a[3] + b[1]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int) int {
	f := func(i int) [4]int {
		cnt := make(map[int]int)
		for ; i < len(nums); i += 2 {
			cnt[nums[i]]++
		}

		k1, k2 := 0, 0
		for k, v := range cnt {
			if cnt[k1] < v {
				k2, k1 = k1, k
			} else if cnt[k2] < v {
				k2 = k
			}
		}
		return [4]int{k1, cnt[k1], k2, cnt[k2]}
	}

	a := f(0)
	b := f(1)
	n := len(nums)
	if a[0] != b[0] {
		return n - (a[1] + b[1])
	}
	return n - max(a[1]+b[3], a[3]+b[1])
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(nums: number[]): number {
    const f = (i: number): [number, number, number, number] => {
        const cnt: Map<number, number> = new Map();
        for (; i < nums.length; i += 2) {
            cnt.set(nums[i], (cnt.get(nums[i]) || 0) + 1);
        }

        let [k1, k2] = [0, 0];
        for (const [k, v] of cnt) {
            if ((cnt.get(k1) || 0) < v) {
                k2 = k1;
                k1 = k;
            } else if ((cnt.get(k2) || 0) < v) {
                k2 = k;
            }
        }
        return [k1, cnt.get(k1) || 0, k2, cnt.get(k2) || 0];
    };

    const a = f(0);
    const b = f(1);
    const n = nums.length;
    if (a[0] !== b[0]) {
        return n - (a[1] + b[1]);
    }
    return n - Math.max(a[1] + b[3], a[3] + b[1]);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，该数组由 <code>n</code> 个正整数组成。</p>

<p>如果满足下述条件，则数组 <code>nums</code> 是一个 <strong>交替数组</strong> ：</p>

<ul>
	<li><code>nums[i - 2] == nums[i]</code> ，其中 <code>2 &lt;= i &lt;= n - 1</code> 。</li>
	<li><code>nums[i - 1] != nums[i]</code> ，其中 <code>1 &lt;= i &lt;= n - 1</code> 。</li>
</ul>

<p>在一步 <strong>操作</strong> 中，你可以选择下标 <code>i</code> 并将 <code>nums[i]</code> <strong>更改</strong> 为 <strong>任一</strong> 正整数。</p>

<p>返回使数组变成交替数组的 <strong>最少操作数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,3,2,4,3]
<strong>输出：</strong>3
<strong>解释：</strong>
使数组变成交替数组的方法之一是将该数组转换为 [3,1,3,<em><strong>1</strong></em>,<em><strong>3</strong></em>,<em><strong>1</strong></em>] 。
在这种情况下，操作数为 3 。
可以证明，操作数少于 3 的情况下，无法使数组变成交替数组。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,2,2]
<strong>输出：</strong>2
<strong>解释：</strong>
使数组变成交替数组的方法之一是将该数组转换为 [1,2,<em><strong>1</strong></em>,2,<em><strong>1</strong></em>].
在这种情况下，操作数为 2 。
注意，数组不能转换成 [<em><strong>2</strong></em>,2,2,2,2] 。因为在这种情况下，nums[0] == nums[1]，不满足交替数组的条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护奇偶位置的计数

根据题目描述，我们可以知道，如果数组 $\textit{nums}$ 是一个交替数组，那么数组中的奇数位置和偶数位置的元素一定是不同的，且奇数位置的元素相同，偶数位置的元素也相同。

要使得数组 $\textit{nums}$ 变成交替数组的操作数最少，我们可以通过统计奇数位置和偶数位置的元素的出现次数，找到偶数位置出现次数最多的两个元素 $a_0$ 和 $a_2$，以及对应的出现次数 $a_1$ 和 $a_3$；再找到奇数位置出现次数最多的两个元素 $b_0$ 和 $b_2$，以及对应的出现次数 $b_1$ 和 $b_3$。

如果 $a_0 \neq b_0$，那么我们可以将数组 $\textit{nums}$ 中偶数位置的元素全部变成 $a_0$，奇数位置的元素全部变成 $b_0$，这样操作数为 $n - (a_1 + b_1)$；如果 $a_0 = b_0$，那么我们可以将数组 $\textit{nums}$ 中偶数位置的元素全部变成 $a_0$，奇数位置的元素全部变成 $b_2$，或者将数组 $\textit{nums}$ 中偶数位置的元素全部变成 $a_2$，奇数位置的元素全部变成 $b_0$，这样操作数为 $n - \max(a_1 + b_3, a_3 + b_1)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        def f(i: int) -> Tuple[int, int, int, int]:
            k1 = k2 = 0
            cnt = Counter(nums[i::2])
            for k, v in cnt.items():
                if cnt[k1] < v:
                    k2, k1 = k1, k
                elif cnt[k2] < v:
                    k2 = k
            return k1, cnt[k1], k2, cnt[k2]

        a, b = f(0), f(1)
        n = len(nums)
        if a[0] != b[0]:
            return n - (a[1] + b[1])
        return n - max(a[1] + b[3], a[3] + b[1])
```

#### Java

```java
class Solution {
    public int minimumOperations(int[] nums) {
        int[] a = f(nums, 0);
        int[] b = f(nums, 1);
        int n = nums.length;
        if (a[0] != b[0]) {
            return n - (a[1] + b[1]);
        }
        return n - Math.max(a[1] + b[3], a[3] + b[1]);
    }

    private int[] f(int[] nums, int i) {
        int k1 = 0, k2 = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (; i < nums.length; i += 2) {
            cnt.merge(nums[i], 1, Integer::sum);
        }
        for (var e : cnt.entrySet()) {
            int k = e.getKey(), v = e.getValue();
            if (cnt.getOrDefault(k1, 0) < v) {
                k2 = k1;
                k1 = k;
            } else if (cnt.getOrDefault(k2, 0) < v) {
                k2 = k;
            }
        }
        return new int[] {k1, cnt.getOrDefault(k1, 0), k2, cnt.getOrDefault(k2, 0)};
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        auto f = [&](int i) -> vector<int> {
            int k1 = 0, k2 = 0;
            unordered_map<int, int> cnt;
            for (; i < nums.size(); i += 2) {
                cnt[nums[i]]++;
            }
            for (auto& [k, v] : cnt) {
                if (!k1 || cnt[k1] < v) {
                    k2 = k1;
                    k1 = k;
                } else if (!k2 || cnt[k2] < v) {
                    k2 = k;
                }
            }
            return {k1, !k1 ? 0 : cnt[k1], k2, !k2 ? 0 : cnt[k2]};
        };
        vector<int> a = f(0);
        vector<int> b = f(1);
        int n = nums.size();
        if (a[0] != b[0]) {
            return n - (a[1] + b[1]);
        }
        return n - max(a[1] + b[3], a[3] + b[1]);
    }
};
```

#### Go

```go
func minimumOperations(nums []int) int {
	f := func(i int) [4]int {
		cnt := make(map[int]int)
		for ; i < len(nums); i += 2 {
			cnt[nums[i]]++
		}

		k1, k2 := 0, 0
		for k, v := range cnt {
			if cnt[k1] < v {
				k2, k1 = k1, k
			} else if cnt[k2] < v {
				k2 = k
			}
		}
		return [4]int{k1, cnt[k1], k2, cnt[k2]}
	}

	a := f(0)
	b := f(1)
	n := len(nums)
	if a[0] != b[0] {
		return n - (a[1] + b[1])
	}
	return n - max(a[1]+b[3], a[3]+b[1])
}
```

#### TypeScript

```ts
function minimumOperations(nums: number[]): number {
    const f = (i: number): [number, number, number, number] => {
        const cnt: Map<number, number> = new Map();
        for (; i < nums.length; i += 2) {
            cnt.set(nums[i], (cnt.get(nums[i]) || 0) + 1);
        }

        let [k1, k2] = [0, 0];
        for (const [k, v] of cnt) {
            if ((cnt.get(k1) || 0) < v) {
                k2 = k1;
                k1 = k;
            } else if ((cnt.get(k2) || 0) < v) {
                k2 = k;
            }
        }
        return [k1, cnt.get(k1) || 0, k2, cnt.get(k2) || 0];
    };

    const a = f(0);
    const b = f(1);
    const n = nums.length;
    if (a[0] !== b[0]) {
        return n - (a[1] + b[1]);
    }
    return n - Math.max(a[1] + b[3], a[3] + b[1]);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2171. 拿出最少数目的魔法豆](https://leetcode.cn/problems/removing-minimum-number-of-magic-beans){#2171}

{{< tabs "2171" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        s, n = sum(beans), len(beans)
        return min(s - x * (n - i) for i, x in enumerate(beans))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumRemoval(int[] beans) {
        Arrays.sort(beans);
        long s = 0;
        for (int x : beans) {
            s += x;
        }
        long ans = s;
        int n = beans.length;
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, s - (long) beans[i] * (n - i));
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
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long s = accumulate(beans.begin(), beans.end(), 0ll);
        long long ans = s;
        int n = beans.size();
        for (int i = 0; i < n; ++i) {
            ans = min(ans, s - 1ll * beans[i] * (n - i));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumRemoval(beans []int) int64 {
	sort.Ints(beans)
	s := 0
	for _, x := range beans {
		s += x
	}
	ans := s
	n := len(beans)
	for i, x := range beans {
		ans = min(ans, s-x*(n-i))
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumRemoval(beans: number[]): number {
    beans.sort((a, b) => a - b);
    const s = beans.reduce((a, b) => a + b, 0);
    const n = beans.length;
    let ans = s;
    for (let i = 0; i < n; ++i) {
        ans = Math.min(ans, s - beans[i] * (n - i));
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

<p>给定一个 <strong>正整数&nbsp;</strong>数组&nbsp;<code>beans</code>&nbsp;，其中每个整数表示一个袋子里装的魔法豆的数目。</p>

<p>请你从每个袋子中&nbsp;<strong>拿出</strong>&nbsp;一些豆子（也可以<strong>&nbsp;不拿出</strong>），使得剩下的 <strong>非空</strong> 袋子中（即 <strong>至少还有一颗</strong>&nbsp;魔法豆的袋子）魔法豆的数目&nbsp;<strong>相等</strong>。一旦把魔法豆从袋子中取出，你不能再将它放到任何袋子中。</p>

<p>请返回你需要拿出魔法豆的 <strong>最少数目</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>beans = [4,1,6,5]
<b>输出：</b>4
<b>解释：</b>
- 我们从有 1 个魔法豆的袋子中拿出 1 颗魔法豆。
  剩下袋子中魔法豆的数目为：[4,<u><strong>0</strong></u>,6,5]
- 然后我们从有 6 个魔法豆的袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,<u><strong>4</strong></u>,5]
- 然后我们从有 5 个魔法豆的袋子中拿出 1 个魔法豆。
  剩下袋子中魔法豆的数目为：[4,0,4,<u><strong>4</strong></u>]
总共拿出了 1 + 2 + 1 = 4 个魔法豆，剩下非空袋子中魔法豆的数目相等。
没有比取出 4 个魔法豆更少的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>beans = [2,10,3,2]
<b>输出：</b>7
<strong>解释：</strong>
- 我们从有 2 个魔法豆的其中一个袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[<u><strong>0</strong></u>,10,3,2]
- 然后我们从另一个有 2 个魔法豆的袋子中拿出 2 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,3,<u><strong>0</strong></u>]
- 然后我们从有 3 个魔法豆的袋子中拿出 3 个魔法豆。
  剩下袋子中魔法豆的数目为：[0,10,<u><strong>0</strong></u>,0]
总共拿出了 2 + 2 + 3 = 7 个魔法豆，剩下非空袋子中魔法豆的数目相等。
没有比取出 7 个魔法豆更少的方案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= beans.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= beans[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 枚举

我们可以将所有袋子中的魔法豆按照从小到大的顺序排列，然后枚举每个袋子的魔法豆数目 $beans[i]$ 作为最终袋子中魔法豆数目，那么一共剩余的魔法豆数目为 $beans[i] \times (n - i)$，因此需要拿出的魔法豆数目为 $s - beans[i] \times (n - i)$，其中 $s$ 为所有袋子中魔法豆的总数。我们求出所有方案中需要拿出的魔法豆数目的最小值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为袋子的数目。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        beans.sort()
        s, n = sum(beans), len(beans)
        return min(s - x * (n - i) for i, x in enumerate(beans))
```

#### Java

```java
class Solution {
    public long minimumRemoval(int[] beans) {
        Arrays.sort(beans);
        long s = 0;
        for (int x : beans) {
            s += x;
        }
        long ans = s;
        int n = beans.length;
        for (int i = 0; i < n; ++i) {
            ans = Math.min(ans, s - (long) beans[i] * (n - i));
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long s = accumulate(beans.begin(), beans.end(), 0ll);
        long long ans = s;
        int n = beans.size();
        for (int i = 0; i < n; ++i) {
            ans = min(ans, s - 1ll * beans[i] * (n - i));
        }
        return ans;
    }
};
```

#### Go

```go
func minimumRemoval(beans []int) int64 {
	sort.Ints(beans)
	s := 0
	for _, x := range beans {
		s += x
	}
	ans := s
	n := len(beans)
	for i, x := range beans {
		ans = min(ans, s-x*(n-i))
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function minimumRemoval(beans: number[]): number {
    beans.sort((a, b) => a - b);
    const s = beans.reduce((a, b) => a + b, 0);
    const n = beans.length;
    let ans = s;
    for (let i = 0; i < n; ++i) {
        ans = Math.min(ans, s - beans[i] * (n - i));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2172. 数组的最大与和](https://leetcode.cn/problems/maximum-and-sum-of-array){#2172}

{{< tabs "2172" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        n = len(nums)
        m = numSlots << 1
        f = [0] * (1 << m)
        for i in range(1 << m):
            cnt = i.bit_count()
            if cnt > n:
                continue
            for j in range(m):
                if i >> j & 1:
                    f[i] = max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & (j // 2 + 1)))
        return max(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumANDSum(int[] nums, int numSlots) {
        int n = nums.length;
        int m = numSlots << 1;
        int[] f = new int[1 << m];
        int ans = 0;
        for (int i = 0; i < 1 << m; ++i) {
            int cnt = Integer.bitCount(i);
            if (cnt > n) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                if ((i >> j & 1) == 1) {
                    f[i] = Math.max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & (j / 2 + 1)));
                }
            }
            ans = Math.max(ans, f[i]);
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
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int m = numSlots << 1;
        int f[1 << m];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 1 << m; ++i) {
            int cnt = __builtin_popcount(i);
            if (cnt > n) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    f[i] = max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & (j / 2 + 1)));
                }
            }
        }
        return *max_element(f, f + (1 << m));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumANDSum(nums []int, numSlots int) int {
	n := len(nums)
	m := numSlots << 1
	f := make([]int, 1<<m)
	for i := range f {
		cnt := bits.OnesCount(uint(i))
		if cnt > n {
			continue
		}
		for j := 0; j < m; j++ {
			if i>>j&1 == 1 {
				f[i] = max(f[i], f[i^(1<<j)]+(nums[cnt-1]&(j/2+1)))
			}
		}
	}
	return slices.Max(f)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumANDSum(nums: number[], numSlots: number): number {
    const n = nums.length;
    const m = numSlots << 1;
    const f: number[] = new Array(1 << m).fill(0);
    for (let i = 0; i < 1 << m; ++i) {
        const cnt = i
            .toString(2)
            .split('')
            .filter(c => c === '1').length;
        if (cnt > n) {
            continue;
        }
        for (let j = 0; j < m; ++j) {
            if (((i >> j) & 1) === 1) {
                f[i] = Math.max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & ((j >> 1) + 1)));
            }
        }
    }
    return Math.max(...f);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为&nbsp;<code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>numSlots</code>&nbsp;，满足<code>2 * numSlots &gt;= n</code>&nbsp;。总共有&nbsp;<code>numSlots</code>&nbsp;个篮子，编号为&nbsp;<code>1</code>&nbsp;到&nbsp;<code>numSlots</code>&nbsp;。</p>

<p>你需要把所有&nbsp;<code>n</code>&nbsp;个整数分到这些篮子中，且每个篮子 <strong>至多</strong>&nbsp;有 2 个整数。一种分配方案的 <strong>与和</strong>&nbsp;定义为每个数与它所在篮子编号的 <strong>按位与运算</strong>&nbsp;结果之和。</p>

<ul>
	<li>比方说，将数字&nbsp;<code>[1, 3]</code>&nbsp;放入篮子&nbsp;<strong><em><code>1</code></em></strong>&nbsp;中，<code>[4, 6]</code> 放入篮子&nbsp;<strong><em><code>2</code></em></strong>&nbsp;中，这个方案的与和为&nbsp;<code>(1 AND <strong><em>1</em></strong>) + (3 AND <strong><em>1</em></strong>) + (4 AND <em><strong>2</strong></em>) + (6 AND <em><strong>2</strong></em>) = 1 + 1 + 0 + 2 = 4</code>&nbsp;。</li>
</ul>

<p>请你返回将 <code>nums</code>&nbsp;中所有数放入<em>&nbsp;</em><code>numSlots</code>&nbsp;个篮子中的最大与和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4,5,6], numSlots = 3
<b>输出：</b>9
<b>解释：</b>一个可行的方案是 [1, 4] 放入篮子 <em><strong>1</strong></em>&nbsp;中，[2, 6] 放入篮子 <strong><em>2</em></strong>&nbsp;中，[3, 5] 放入篮子 <strong><em>3</em></strong> 中。
最大与和为 (1 AND <strong><em>1</em></strong>) + (4 AND <strong><em>1</em></strong>) + (2 AND <strong><em>2</em></strong>) + (6 AND <strong><em>2</em></strong>) + (3 AND <strong><em>3</em></strong>) + (5 AND <em><strong>3</strong></em>) = 1 + 0 + 2 + 2 + 3 + 1 = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,3,10,4,7,1], numSlots = 9
<b>输出：</b>24
<b>解释：</b>一个可行的方案是 [1, 1] 放入篮子 <em><strong>1</strong></em> 中，[3] 放入篮子 <em><strong>3</strong></em> 中，[4] 放入篮子 <strong><em>4</em></strong> 中，[7] 放入篮子 <strong><em>7</em></strong> 中，[10] 放入篮子 <strong><em>9</em></strong>&nbsp;中。
最大与和为 (1 AND <strong><em>1</em></strong>) + (1 AND <strong><em>1</em></strong>) + (3 AND <strong><em>3</em></strong>) + (4 AND <strong><em>4</em></strong>) + (7 AND <strong><em>7</em></strong>) + (10 AND <strong><em>9</em></strong>) = 1 + 1 + 3 + 4 + 7 + 8 = 24 。
注意，篮子 2 ，5 ，6 和 8 是空的，这是允许的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= numSlots &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 2 * numSlots</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 15</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 动态规划

由于每个篮子最多只能放两个数，我们不妨将篮子数乘以 $2$，这样每个篮子最多只能放一个数。

接下来，我们定义 $f[i]$ 表示篮子状态为 $i$ 时的最大与和，其中 $i$ 是一个二进制数，表示每个篮子是否放了数。初始时 $f[0]=0$。

接下来，我们考虑 $f[i]$ 如何进行状态转移。

我们可以枚举 $i$，记 $i$ 的二进制表示中 $1$ 的个数为 $cnt$。如果 $cnt \gt n$，那么 $i$ 不是一个合法的状态，我们可以直接跳过。否则，我们可以枚举 $i$ 的二进制表示中的每一位 $j$，如果 $i$ 的第 $j$ 位为 $1$，那么我们可以将第 $(cnt-1)$ 个数 $nums[cnt-1]$ 放入第 $j$ 个篮子中，此时有：

$$
f[i] = \max\{f[i], f[i \oplus (1 << j)] + (nums[cnt-1] \wedge  (j / 2 + 1))\}
$$

其中 $\oplus$ 表示异或运算，而 $\wedge$ 表示按位与运算。

答案为 $\max\{f[i]\}$。

时间复杂度 $O(4^k \times k \times 2)$，空间复杂度 $O(4^k)$。其中 $k$ 表示篮子的数量，即题目中的 $numSlots$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumANDSum(self, nums: List[int], numSlots: int) -> int:
        n = len(nums)
        m = numSlots << 1
        f = [0] * (1 << m)
        for i in range(1 << m):
            cnt = i.bit_count()
            if cnt > n:
                continue
            for j in range(m):
                if i >> j & 1:
                    f[i] = max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & (j // 2 + 1)))
        return max(f)
```

#### Java

```java
class Solution {
    public int maximumANDSum(int[] nums, int numSlots) {
        int n = nums.length;
        int m = numSlots << 1;
        int[] f = new int[1 << m];
        int ans = 0;
        for (int i = 0; i < 1 << m; ++i) {
            int cnt = Integer.bitCount(i);
            if (cnt > n) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                if ((i >> j & 1) == 1) {
                    f[i] = Math.max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & (j / 2 + 1)));
                }
            }
            ans = Math.max(ans, f[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        int m = numSlots << 1;
        int f[1 << m];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 1 << m; ++i) {
            int cnt = __builtin_popcount(i);
            if (cnt > n) {
                continue;
            }
            for (int j = 0; j < m; ++j) {
                if (i >> j & 1) {
                    f[i] = max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & (j / 2 + 1)));
                }
            }
        }
        return *max_element(f, f + (1 << m));
    }
};
```

#### Go

```go
func maximumANDSum(nums []int, numSlots int) int {
	n := len(nums)
	m := numSlots << 1
	f := make([]int, 1<<m)
	for i := range f {
		cnt := bits.OnesCount(uint(i))
		if cnt > n {
			continue
		}
		for j := 0; j < m; j++ {
			if i>>j&1 == 1 {
				f[i] = max(f[i], f[i^(1<<j)]+(nums[cnt-1]&(j/2+1)))
			}
		}
	}
	return slices.Max(f)
}
```

#### TypeScript

```ts
function maximumANDSum(nums: number[], numSlots: number): number {
    const n = nums.length;
    const m = numSlots << 1;
    const f: number[] = new Array(1 << m).fill(0);
    for (let i = 0; i < 1 << m; ++i) {
        const cnt = i
            .toString(2)
            .split('')
            .filter(c => c === '1').length;
        if (cnt > n) {
            continue;
        }
        for (let j = 0; j < m; ++j) {
            if (((i >> j) & 1) === 1) {
                f[i] = Math.max(f[i], f[i ^ (1 << j)] + (nums[cnt - 1] & ((j >> 1) + 1)));
            }
        }
    }
    return Math.max(...f);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2173. 最多连胜的次数 🔒](https://leetcode.cn/problems/longest-winning-streak){#2173}

{{< tabs "2173" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY player_id
                ORDER BY match_day
            ) - ROW_NUMBER() OVER (
                PARTITION BY player_id, result
                ORDER BY match_day
            ) AS rk
        FROM Matches
    ),
    T AS (
        SELECT player_id, SUM(result = 'Win') AS s
        FROM S
        GROUP BY player_id, rk
    )
SELECT player_id, MAX(s) AS longest_streak
FROM T
GROUP BY player_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Matches</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| player_id   | int  |
| match_day   | date |
| result      | enum |
+-------------+------+
(player_id, match_day) 是该表的主键（具有唯一值的列的组合）。
每一行包括了：参赛选手 id、 比赛时间、 比赛结果。
比赛结果（result）的枚举类型为 ('Win', 'Draw', 'Lose')。</pre>

<p>&nbsp;</p>

<p>选手的&nbsp;<strong>连胜数</strong> 是指连续获胜的次数，且没有被平局或输球中断。</p>

<p>编写解决方案来计算每个参赛选手最多的<strong>连胜数</strong>。</p>

<p>结果可以以 <strong>任何顺序</strong> 返回。</p>

<p>结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Matches 表:
+-----------+------------+--------+
| player_id | match_day  | result |
+-----------+------------+--------+
| 1         | 2022-01-17 | Win    |
| 1         | 2022-01-18 | Win    |
| 1         | 2022-01-25 | Win    |
| 1         | 2022-01-31 | Draw   |
| 1         | 2022-02-08 | Win    |
| 2         | 2022-02-06 | Lose   |
| 2         | 2022-02-08 | Lose   |
| 3         | 2022-03-30 | Win    |
+-----------+------------+--------+
<strong>输出:</strong> 
+-----------+----------------+
| player_id | longest_streak |
+-----------+----------------+
| 1         | 3              |
| 2         | 0              |
| 3         | 1              |
+-----------+----------------+
<strong>解释:</strong> 
Player 1:
从 2022-01-17 到 2022-01-25, player 1连续赢了三场比赛。
2022-01-31, player 1 平局.
2022-02-08, player 1 赢了一场比赛。
最多连胜了三场比赛。

Player 2:
从 2022-02-06 到 2022-02-08, player 2 输了两场比赛。
最多连赢了0场比赛。

Player 3:
2022-03-30, player 3 赢了一场比赛。
最多连赢了一场比赛。
</pre>

<p>&nbsp;</p>

<p><strong>进阶:</strong> 如果我们想计算最长的连续不输的次数（即获胜或平局），你将如何调整？</p>

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
    S AS (
        SELECT
            *,
            ROW_NUMBER() OVER (
                PARTITION BY player_id
                ORDER BY match_day
            ) - ROW_NUMBER() OVER (
                PARTITION BY player_id, result
                ORDER BY match_day
            ) AS rk
        FROM Matches
    ),
    T AS (
        SELECT player_id, SUM(result = 'Win') AS s
        FROM S
        GROUP BY player_id, rk
    )
SELECT player_id, MAX(s) AS longest_streak
FROM T
GROUP BY player_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2174. 通过翻转行或列来去除所有的 1 II 🔒](https://leetcode.cn/problems/remove-all-ones-with-row-and-column-flips-ii){#2174}

{{< tabs "2174" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        state = sum(1 << (i * n + j) for i in range(m) for j in range(n) if grid[i][j])
        q = deque([state])
        vis = {state}
        ans = 0
        while q:
            for _ in range(len(q)):
                state = q.popleft()
                if state == 0:
                    return ans
                for i in range(m):
                    for j in range(n):
                        if grid[i][j] == 0:
                            continue
                        nxt = state
                        for r in range(m):
                            nxt &= ~(1 << (r * n + j))
                        for c in range(n):
                            nxt &= ~(1 << (i * n + c))
                        if nxt not in vis:
                            vis.add(nxt)
                            q.append(nxt)
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int removeOnes(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int state = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    state |= 1 << (i * n + j);
                }
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(state);
        Set<Integer> vis = new HashSet<>();
        vis.add(state);
        int ans = 0;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                state = q.poll();
                if (state == 0) {
                    return ans;
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 0) {
                            continue;
                        }
                        int nxt = state;
                        for (int r = 0; r < m; ++r) {
                            nxt &= ~(1 << (r * n + j));
                        }
                        for (int c = 0; c < n; ++c) {
                            nxt &= ~(1 << (i * n + c));
                        }
                        if (!vis.contains(nxt)) {
                            vis.add(nxt);
                            q.offer(nxt);
                        }
                    }
                }
            }
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
    int removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int state = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    state |= (1 << (i * n + j));
        queue<int> q{{state}};
        unordered_set<int> vis{{state}};
        int ans = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                state = q.front();
                q.pop();
                if (state == 0) return ans;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 0) continue;
                        int nxt = state;
                        for (int r = 0; r < m; ++r) nxt &= ~(1 << (r * n + j));
                        for (int c = 0; c < n; ++c) nxt &= ~(1 << (i * n + c));
                        if (!vis.count(nxt)) {
                            vis.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeOnes(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	state := 0
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				state |= 1 << (i*n + j)
			}
		}
	}
	q := []int{state}
	vis := map[int]bool{state: true}
	ans := 0
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			state = q[0]
			if state == 0 {
				return ans
			}
			q = q[1:]
			for i, row := range grid {
				for j, v := range row {
					if v == 0 {
						continue
					}
					nxt := state
					for r := 0; r < m; r++ {
						nxt &= ^(1 << (r*n + j))
					}
					for c := 0; c < n; c++ {
						nxt &= ^(1 << (i*n + c))
					}
					if !vis[nxt] {
						vis[nxt] = true
						q = append(q, nxt)
					}
				}
			}
		}
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

<p>给定&nbsp;<strong>下标从 0 开始&nbsp;</strong>的 <code>m x n</code> <strong>二进制&nbsp;</strong>矩阵 <code>grid</code>。</p>

<p>在一次操作中，可以选择满足以下条件的任意 <code>i</code> 和 <code>j</code>:</p>

<ul>
	<li><code>0 &lt;= i &lt; m</code></li>
	<li><code>0 &lt;= j &lt; n</code></li>
	<li><code>grid[i][j] == 1</code></li>
</ul>

<p>并将第 <code>i</code> 行和第 <code>j</code> 列中的&nbsp;<strong>所有&nbsp;</strong>单元格的值更改为零。</p>

<p>返回<em>从&nbsp;</em><code>grid</code><em> 中删除所有 <code>1</code> 所需的最小操作数。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2174.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips%20II/images/image-20220213162716-1.png" style="width: 709px; height: 200px;" />
<pre>
<strong>输入:</strong> grid = [[1,1,1],[1,1,1],[0,1,0]]
<strong>输出:</strong> 2
<strong>解释:</strong>
在第一个操作中，将第 1 行和第 1 列的所有单元格值更改为 0。
在第二个操作中，将第 0 行和第 0 列的所有单元格值更改为 0。
</pre>

<p><strong class="example">示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2174.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips%20II/images/image-20220213162737-2.png" style="width: 734px; height: 200px;" />
<pre>
<strong>输入:</strong> grid = [[0,1,0],[1,0,1],[0,1,0]]
<strong>输出:</strong> 2
<strong>解释:</strong>
在第一个操作中，将第 1 行和第 0 列的所有单元格值更改为 0。
在第二个操作中，将第 2 行和第 1 列的所有单元格值更改为 0。
注意，我们不能使用行 1 和列 1 执行操作，因为 grid[1][1]!= 1。
</pre>

<p><strong class="example">示例 3:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2174.Remove%20All%20Ones%20With%20Row%20and%20Column%20Flips%20II/images/image-20220213162752-3.png" style="width: 156px; height: 150px;" />
<pre>
<strong>输入:</strong> grid = [[0,0],[0,0]]
<strong>输出:</strong> 0
<strong>解释:</strong>
没有 1 可以移除，所以返回0。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 15</code></li>
	<li><code>1 &lt;= m * n &lt;= 15</code></li>
	<li><code>grid[i][j]</code> 为&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + BFS

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        state = sum(1 << (i * n + j) for i in range(m) for j in range(n) if grid[i][j])
        q = deque([state])
        vis = {state}
        ans = 0
        while q:
            for _ in range(len(q)):
                state = q.popleft()
                if state == 0:
                    return ans
                for i in range(m):
                    for j in range(n):
                        if grid[i][j] == 0:
                            continue
                        nxt = state
                        for r in range(m):
                            nxt &= ~(1 << (r * n + j))
                        for c in range(n):
                            nxt &= ~(1 << (i * n + c))
                        if nxt not in vis:
                            vis.add(nxt)
                            q.append(nxt)
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int removeOnes(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int state = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    state |= 1 << (i * n + j);
                }
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(state);
        Set<Integer> vis = new HashSet<>();
        vis.add(state);
        int ans = 0;
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                state = q.poll();
                if (state == 0) {
                    return ans;
                }
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 0) {
                            continue;
                        }
                        int nxt = state;
                        for (int r = 0; r < m; ++r) {
                            nxt &= ~(1 << (r * n + j));
                        }
                        for (int c = 0; c < n; ++c) {
                            nxt &= ~(1 << (i * n + c));
                        }
                        if (!vis.contains(nxt)) {
                            vis.add(nxt);
                            q.offer(nxt);
                        }
                    }
                }
            }
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
    int removeOnes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int state = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    state |= (1 << (i * n + j));
        queue<int> q{{state}};
        unordered_set<int> vis{{state}};
        int ans = 0;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                state = q.front();
                q.pop();
                if (state == 0) return ans;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 0) continue;
                        int nxt = state;
                        for (int r = 0; r < m; ++r) nxt &= ~(1 << (r * n + j));
                        for (int c = 0; c < n; ++c) nxt &= ~(1 << (i * n + c));
                        if (!vis.count(nxt)) {
                            vis.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};
```

#### Go

```go
func removeOnes(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	state := 0
	for i, row := range grid {
		for j, v := range row {
			if v == 1 {
				state |= 1 << (i*n + j)
			}
		}
	}
	q := []int{state}
	vis := map[int]bool{state: true}
	ans := 0
	for len(q) > 0 {
		for k := len(q); k > 0; k-- {
			state = q[0]
			if state == 0 {
				return ans
			}
			q = q[1:]
			for i, row := range grid {
				for j, v := range row {
					if v == 0 {
						continue
					}
					nxt := state
					for r := 0; r < m; r++ {
						nxt &= ^(1 << (r*n + j))
					}
					for c := 0; c < n; c++ {
						nxt &= ^(1 << (i*n + c))
					}
					if !vis[nxt] {
						vis[nxt] = true
						q = append(q, nxt)
					}
				}
			}
		}
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

# [2175. 世界排名的变化 🔒](https://leetcode.cn/problems/the-change-in-global-rankings){#2175}

{{< tabs "2175" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT team_id, SUM(points_change) AS delta
        FROM PointsChange
        GROUP BY team_id
    )
SELECT
    team_id,
    name,
    CAST(RANK() OVER (ORDER BY points DESC, name) AS SIGNED) - CAST(
        RANK() OVER (ORDER BY (points + delta) DESC, name) AS SIGNED
    ) AS 'rank_diff'
FROM
    TeamPoints
    JOIN P USING (team_id);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>TeamPoints</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| team_id     | int     |
| name        | varchar |
| points      | int     |
+-------------+---------+
team_id 包含唯一值。
这张表的每一行均包含了一支国家队的 ID，它所代表的国家，以及它在全球排名中的得分。没有两支队伍代表同一个国家。
</pre>

<p>&nbsp;</p>

<p>表：<code>PointsChange</code></p>

<pre>
+---------------+------+
| Column Name   | Type |
+---------------+------+
| team_id       | int  |
| points_change | int  |
+---------------+------+
team_id 包含唯一值。
这张表的每一行均包含了一支国家队的 ID 以及它在世界排名中的得分的变化。
分数的变化分以下情况：
- 0:代表分数没有改变
- 正数:代表分数增加
- 负数:代表分数降低
TeamPoints 表中出现的每一个 team_id 均会在这张表中出现。
</pre>

<p>&nbsp;</p>

<p>国家队的全球排名是按<strong> 降序排列</strong> 所有队伍的得分后所得出的排名。如果两支队伍得分相同，我们将按其名称的 <strong>字典顺序 </strong>排列以打破平衡。</p>

<p>每支国家队的分数应根据其相应的 <code>points_change</code> 进行更新。</p>

<p>编写解决方案来计算在分数更新后，每个队伍的全球排名的变化。</p>

<p>以<strong> 任意顺序 </strong>返回结果。</p>

<p>查询结果的格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
TeamPoints 表：
+---------+-------------+--------+
| team_id | name        | points |
+---------+-------------+--------+
| 3       | Algeria     | 1431   |
| 1       | Senegal     | 2132   |
| 2       | New Zealand | 1402   |
| 4       | Croatia     | 1817   |
+---------+-------------+--------+
PointsChange 表：
+---------+---------------+
| team_id | points_change |
+---------+---------------+
| 3       | 399           |
| 2       | 0             |
| 4       | 13            |
| 1       | -22           |
+---------+---------------+
<strong>输出：</strong>
+---------+-------------+-----------+
| team_id | name        | rank_diff |
+---------+-------------+-----------+
| 1       | Senegal     | 0         |
| 4       | Croatia     | -1        |
| 3       | Algeria     | 1         |
| 2       | New Zealand | 0         |
+---------+-------------+-----------+
<strong>解释：</strong>
世界排名如下所示：
+---------+-------------+--------+------+
| team_id | name        | points | rank |
+---------+-------------+--------+------+
| 1       | Senegal     | 2132   | 1    |
| 4       | Croatia     | 1817   | 2    |
| 3       | Algeria     | 1431   | 3    |
| 2       | New Zealand | 1402   | 4    |
+---------+-------------+--------+------+
在更新分数后，世界排名变为下表：
+---------+-------------+--------+------+
| team_id | name        | points | rank |
+---------+-------------+--------+------+
| 1       | Senegal     | 2110   | 1    |
| 3       | Algeria     | 1830   | 2    |
| 4       | Croatia     | 1830   | 3    |
| 2       | New Zealand | 1402   | 4    |
+---------+-------------+--------+------+
由于在更新分数后，Algeria 和 Croatia 的得分相同，因此根据字典顺序对它们进行排序。
Senegal 丢失了22分但他们的排名没有改变。
Croatia 获得了13分但是他们的排名下降了1名。
Algeria 获得399分，排名上升了1名。
New Zealand 没有获得或丢失分数，他们的排名也没有发生变化。
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：窗口函数

利用 `rank()` 函数求出新老排名，然后用 `CAST` 将字段类型改为 `signed`，保证两个排名可以进行减法操作。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT team_id, SUM(points_change) AS delta
        FROM PointsChange
        GROUP BY team_id
    )
SELECT
    team_id,
    name,
    CAST(RANK() OVER (ORDER BY points DESC, name) AS SIGNED) - CAST(
        RANK() OVER (ORDER BY (points + delta) DESC, name) AS SIGNED
    ) AS 'rank_diff'
FROM
    TeamPoints
    JOIN P USING (team_id);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2176. 统计数组中相等且可以被整除的数对](https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array){#2176}

{{< tabs "2176" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        ans = 0
        for j, y in enumerate(nums):
            for i, x in enumerate(nums[:j]):
                ans += int(x == y and i * j % k == 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPairs(int[] nums, int k) {
        int ans = 0;
        for (int j = 1; j < nums.length; ++j) {
            for (int i = 0; i < j; ++i) {
                ans += nums[i] == nums[j] && (i * j % k) == 0 ? 1 : 0;
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
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (int j = 1; j < nums.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                ans += nums[i] == nums[j] && (i * j % k) == 0;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(nums []int, k int) (ans int) {
	for j, y := range nums {
		for i, x := range nums[:j] {
			if x == y && (i*j%k) == 0 {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPairs(nums: number[], k: number): number {
    let ans = 0;
    for (let j = 1; j < nums.length; ++j) {
        for (let i = 0; i < j; ++i) {
            if (nums[i] === nums[j] && (i * j) % k === 0) {
                ++ans;
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
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        for j in 1..nums.len() {
            for (i, &x) in nums[..j].iter().enumerate() {
                if x == nums[j] && (i * j) as i32 % k == 0 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int countPairs(int* nums, int numsSize, int k) {
    int ans = 0;
    for (int j = 1; j < numsSize; ++j) {
        for (int i = 0; i < j; ++i) {
            ans += (nums[i] == nums[j] && (i * j % k) == 0);
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你返回满足&nbsp;<code>0 &lt;= i &lt; j &lt; n</code>&nbsp;，<code>nums[i] == nums[j]</code> 且&nbsp;<code>(i * j)</code>&nbsp;能被&nbsp;<code>k</code>&nbsp;整除的数对&nbsp;<code>(i, j)</code>&nbsp;的&nbsp;<strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [3,1,2,2,2,1,3], k = 2
<b>输出：</b>4
<strong>解释：</strong>
总共有 4 对数符合所有要求：
- nums[0] == nums[6] 且 0 * 6 == 0 ，能被 2 整除。
- nums[2] == nums[3] 且 2 * 3 == 6 ，能被 2 整除。
- nums[2] == nums[4] 且 2 * 4 == 8 ，能被 2 整除。
- nums[3] == nums[4] 且 3 * 4 == 12 ，能被 2 整除。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4], k = 1
<b>输出：</b>0
<b>解释：</b>由于数组中没有重复数值，所以没有数对 (i,j) 符合所有要求。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们先在 $[0, n)$ 的范围内枚举下标 $j$，然后在 $[0, j)$ 的范围内枚举下标 $i$，统计满足 $\textit{nums}[i] = \textit{nums}[j]$ 且 $(i \times j) \bmod k = 0$ 的数对个数。

时间复杂度 $O(n^2)$，其中 $n$ 是数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        ans = 0
        for j, y in enumerate(nums):
            for i, x in enumerate(nums[:j]):
                ans += int(x == y and i * j % k == 0)
        return ans
```

#### Java

```java
class Solution {
    public int countPairs(int[] nums, int k) {
        int ans = 0;
        for (int j = 1; j < nums.length; ++j) {
            for (int i = 0; i < j; ++i) {
                ans += nums[i] == nums[j] && (i * j % k) == 0 ? 1 : 0;
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
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (int j = 1; j < nums.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                ans += nums[i] == nums[j] && (i * j % k) == 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(nums []int, k int) (ans int) {
	for j, y := range nums {
		for i, x := range nums[:j] {
			if x == y && (i*j%k) == 0 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countPairs(nums: number[], k: number): number {
    let ans = 0;
    for (let j = 1; j < nums.length; ++j) {
        for (let i = 0; i < j; ++i) {
            if (nums[i] === nums[j] && (i * j) % k === 0) {
                ++ans;
            }
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut ans = 0;
        for j in 1..nums.len() {
            for (i, &x) in nums[..j].iter().enumerate() {
                if x == nums[j] && (i * j) as i32 % k == 0 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
```

#### C

```c
int countPairs(int* nums, int numsSize, int k) {
    int ans = 0;
    for (int j = 1; j < numsSize; ++j) {
        for (int i = 0; i < j; ++i) {
            ans += (nums[i] == nums[j] && (i * j % k) == 0);
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

# [2177. 找到和为给定整数的三个连续整数](https://leetcode.cn/problems/find-three-consecutive-integers-that-sum-to-a-given-number){#2177}

{{< tabs "2177" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        x, mod = divmod(num, 3)
        return [] if mod else [x - 1, x, x + 1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] sumOfThree(long num) {
        if (num % 3 != 0) {
            return new long[] {};
        }
        long x = num / 3;
        return new long[] {x - 1, x, x + 1};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3) {
            return {};
        }
        long long x = num / 3;
        return {x - 1, x, x + 1};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfThree(num int64) []int64 {
	if num%3 != 0 {
		return []int64{}
	}
	x := num / 3
	return []int64{x - 1, x, x + 1}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfThree(num: number): number[] {
    if (num % 3) {
        return [];
    }
    const x = Math.floor(num / 3);
    return [x - 1, x, x + 1];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sum_of_three(num: i64) -> Vec<i64> {
        if num % 3 != 0 {
            return Vec::new();
        }
        let x = num / 3;
        vec![x - 1, x, x + 1]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} num
 * @return {number[]}
 */
var sumOfThree = function (num) {
    if (num % 3) {
        return [];
    }
    const x = Math.floor(num / 3);
    return [x - 1, x, x + 1];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>num</code>&nbsp;，请你返回三个连续的整数，它们的&nbsp;<strong>和</strong>&nbsp;为<em>&nbsp;</em><code>num</code>&nbsp;。如果&nbsp;<code>num</code>&nbsp;无法被表示成三个连续整数的和，请你返回一个 <strong>空</strong>&nbsp;数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>num = 33
<b>输出：</b>[10,11,12]
<b>解释：</b>33 可以表示为 10 + 11 + 12 = 33 。
10, 11, 12 是 3 个连续整数，所以返回 [10, 11, 12] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>num = 4
<b>输出：</b>[]
<b>解释：</b>没有办法将 4 表示成 3 个连续整数的和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>15</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们假设三个连续的整数分别为 $x-1$, $x$, $x+1$，则它们的和为 $3x$，因此 $\textit{num}$ 必须是 $3$ 的倍数。如果 $\textit{num}$ 不是 $3$ 的倍数，则无法表示成三个连续整数的和，返回空数组。否则，令 $x = \frac{\textit{num}}{3}$，则 $x-1$, $x$, $x+1$ 就是三个连续整数，它们的和为 $\textit{num}$。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        x, mod = divmod(num, 3)
        return [] if mod else [x - 1, x, x + 1]
```

#### Java

```java
class Solution {
    public long[] sumOfThree(long num) {
        if (num % 3 != 0) {
            return new long[] {};
        }
        long x = num / 3;
        return new long[] {x - 1, x, x + 1};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3) {
            return {};
        }
        long long x = num / 3;
        return {x - 1, x, x + 1};
    }
};
```

#### Go

```go
func sumOfThree(num int64) []int64 {
	if num%3 != 0 {
		return []int64{}
	}
	x := num / 3
	return []int64{x - 1, x, x + 1}
}
```

#### TypeScript

```ts
function sumOfThree(num: number): number[] {
    if (num % 3) {
        return [];
    }
    const x = Math.floor(num / 3);
    return [x - 1, x, x + 1];
}
```

#### Rust

```rust
impl Solution {
    pub fn sum_of_three(num: i64) -> Vec<i64> {
        if num % 3 != 0 {
            return Vec::new();
        }
        let x = num / 3;
        vec![x - 1, x, x + 1]
    }
}
```

#### JavaScript

```js
/**
 * @param {number} num
 * @return {number[]}
 */
var sumOfThree = function (num) {
    if (num % 3) {
        return [];
    }
    const x = Math.floor(num / 3);
    return [x - 1, x, x + 1];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2178. 拆分成最多数目的正偶数之和](https://leetcode.cn/problems/maximum-split-of-positive-even-integers){#2178}

{{< tabs "2178" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum & 1:
            return []
        ans = []
        i = 2
        while i <= finalSum:
            finalSum -= i
            ans.append(i)
            i += 2
        ans[-1] += finalSum
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> ans = new ArrayList<>();
        if (finalSum % 2 == 1) {
            return ans;
        }
        for (long i = 2; i <= finalSum; i += 2) {
            ans.add(i);
            finalSum -= i;
        }
        ans.add(ans.remove(ans.size() - 1) + finalSum);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum % 2) {
            return ans;
        }
        for (long long i = 2; i <= finalSum; i += 2) {
            ans.push_back(i);
            finalSum -= i;
        }
        ans.back() += finalSum;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumEvenSplit(finalSum int64) (ans []int64) {
	if finalSum%2 == 1 {
		return
	}
	for i := int64(2); i <= finalSum; i += 2 {
		ans = append(ans, i)
		finalSum -= i
	}
	ans[len(ans)-1] += finalSum
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumEvenSplit(finalSum: number): number[] {
    const ans: number[] = [];
    if (finalSum % 2 === 1) {
        return ans;
    }
    for (let i = 2; i <= finalSum; i += 2) {
        ans.push(i);
        finalSum -= i;
    }
    ans[ans.length - 1] += finalSum;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_even_split(mut final_sum: i64) -> Vec<i64> {
        let mut ans = Vec::new();
        if final_sum % 2 != 0 {
            return ans;
        }
        let mut i = 2;
        while i <= final_sum {
            ans.push(i);
            final_sum -= i;
            i += 2;
        }
        if let Some(last) = ans.last_mut() {
            *last += final_sum;
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<long> MaximumEvenSplit(long finalSum) {
        IList<long> ans = new List<long>();
        if (finalSum % 2 == 1) {
            return ans;
        }
        for (long i = 2; i <= finalSum; i += 2) {
            ans.Add(i);
            finalSum -= i;
        }
        ans[ans.Count - 1] += finalSum;
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

<p>给你一个整数&nbsp;<code>finalSum</code>&nbsp;。请你将它拆分成若干个&nbsp;<strong>互不相同</strong> 的正偶数之和，且拆分出来的正偶数数目&nbsp;<strong>最多</strong>&nbsp;。</p>

<ul>
	<li>比方说，给你&nbsp;<code>finalSum = 12</code>&nbsp;，那么这些拆分是&nbsp;<strong>符合要求</strong> 的（互不相同的正偶数且和为&nbsp;<code>finalSum</code>）：<code>(2 + 10)</code>&nbsp;，<code>(2 + 4 + 6)</code>&nbsp;和&nbsp;<code>(4 + 8)</code>&nbsp;。它们中，<code>(2 + 4 + 6)</code>&nbsp;包含最多数目的整数。注意&nbsp;<code>finalSum</code>&nbsp;不能拆分成&nbsp;<code>(2 + 2 + 4 + 4)</code>&nbsp;，因为拆分出来的整数必须互不相同。</li>
</ul>

<p>请你返回一个整数数组，表示将整数拆分成 <strong>最多</strong> 数目的正偶数数组。如果没有办法将&nbsp;<code>finalSum</code>&nbsp;进行拆分，请你返回一个&nbsp;<strong>空</strong>&nbsp;数组。你可以按 <b>任意</b>&nbsp;顺序返回这些整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>finalSum = 12
<b>输出：</b>[2,4,6]
<b>解释：</b>以下是一些符合要求的拆分：<code>(2 + 10)<span style="">，</span></code><code>(2 + 4 + 6) </code>和 <code>(4 + 8) 。</code>
(2 + 4 + 6) 为最多数目的整数，数目为 3 ，所以我们返回 [2,4,6] 。
[2,6,4] ，[6,2,4] 等等也都是可行的解。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>finalSum = 7
<b>输出：</b>[]
<b>解释：</b>没有办法将 finalSum 进行拆分。
所以返回空数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>finalSum = 28
<b>输出：</b>[6,8,2,12]
<b>解释：</b>以下是一些符合要求的拆分：<code>(2 + 26)<span style="">，</span></code><code>(6 + 8 + 2 + 12)</code> 和 <code>(4 + 24) 。</code>
<code>(6 + 8 + 2 + 12)</code> 有最多数目的整数，数目为 4 ，所以我们返回 [6,8,2,12] 。
[10,2,4,12] ，[6,2,4,16] 等等也都是可行的解。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= finalSum &lt;= 10<sup>10</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

如果 $\textit{finalSum}$ 是奇数，那么无法拆分成若干个互不相同的正偶数之和，直接返回空数组。

否则，我们可以贪心地按照 $2, 4, 6, \cdots$ 的顺序拆分 $\textit{finalSum}$，直到 $\textit{finalSum}$ 无法再拆分出一个不同的正偶数为止，此时我们将剩余的 $\textit{finalSum}$ 加到最后一个正偶数上即可。

时间复杂度 $O(\sqrt{\textit{finalSum}})$，忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum & 1:
            return []
        ans = []
        i = 2
        while i <= finalSum:
            finalSum -= i
            ans.append(i)
            i += 2
        ans[-1] += finalSum
        return ans
```

#### Java

```java
class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> ans = new ArrayList<>();
        if (finalSum % 2 == 1) {
            return ans;
        }
        for (long i = 2; i <= finalSum; i += 2) {
            ans.add(i);
            finalSum -= i;
        }
        ans.add(ans.remove(ans.size() - 1) + finalSum);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if (finalSum % 2) {
            return ans;
        }
        for (long long i = 2; i <= finalSum; i += 2) {
            ans.push_back(i);
            finalSum -= i;
        }
        ans.back() += finalSum;
        return ans;
    }
};
```

#### Go

```go
func maximumEvenSplit(finalSum int64) (ans []int64) {
	if finalSum%2 == 1 {
		return
	}
	for i := int64(2); i <= finalSum; i += 2 {
		ans = append(ans, i)
		finalSum -= i
	}
	ans[len(ans)-1] += finalSum
	return
}
```

#### TypeScript

```ts
function maximumEvenSplit(finalSum: number): number[] {
    const ans: number[] = [];
    if (finalSum % 2 === 1) {
        return ans;
    }
    for (let i = 2; i <= finalSum; i += 2) {
        ans.push(i);
        finalSum -= i;
    }
    ans[ans.length - 1] += finalSum;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_even_split(mut final_sum: i64) -> Vec<i64> {
        let mut ans = Vec::new();
        if final_sum % 2 != 0 {
            return ans;
        }
        let mut i = 2;
        while i <= final_sum {
            ans.push(i);
            final_sum -= i;
            i += 2;
        }
        if let Some(last) = ans.last_mut() {
            *last += final_sum;
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public IList<long> MaximumEvenSplit(long finalSum) {
        IList<long> ans = new List<long>();
        if (finalSum % 2 == 1) {
            return ans;
        }
        for (long i = 2; i <= finalSum; i += 2) {
            ans.Add(i);
            finalSum -= i;
        }
        ans[ans.Count - 1] += finalSum;
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2179. 统计数组中好三元组数目](https://leetcode.cn/problems/count-good-triplets-in-an-array){#2179}

{{< tabs "2179" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ("l", "r", "v")

    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        pos = {v: i for i, v in enumerate(nums2, 1)}
        ans = 0
        n = len(nums1)
        tree = SegmentTree(n)
        for num in nums1:
            p = pos[num]
            left = tree.query(1, 1, p)
            right = n - p - (tree.query(1, 1, n) - tree.query(1, 1, p))
            ans += left * right
            tree.modify(1, p, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] pos = new int[n];
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i + 1;
        }
        long ans = 0;
        for (int num : nums1) {
            int p = pos[num];
            long left = tree.query(1, 1, p);
            long right = n - p - (tree.query(1, 1, n) - tree.query(1, 1, p));
            ans += left * right;
            tree.modify(1, p, 1);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v += v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v += v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[nums2[i]] = i + 1;
        SegmentTree* tree = new SegmentTree(n);
        long long ans = 0;
        for (int& num : nums1) {
            int p = pos[num];
            int left = tree->query(1, 1, p);
            int right = n - p - (tree->query(1, 1, n) - tree->query(1, 1, p));
            ans += 1ll * left * right;
            tree->modify(1, p, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Node struct {
	l, r, v int
}

type SegmentTree struct {
	tr []Node
}

func NewSegmentTree(n int) *SegmentTree {
	tr := make([]Node, 4*n)
	st := &SegmentTree{tr: tr}
	st.build(1, 1, n)
	return st
}

func (st *SegmentTree) build(u, l, r int) {
	st.tr[u].l = l
	st.tr[u].r = r
	if l == r {
		return
	}
	mid := (l + r) >> 1
	st.build(u<<1, l, mid)
	st.build(u<<1|1, mid+1, r)
}

func (st *SegmentTree) modify(u, x, v int) {
	if st.tr[u].l == x && st.tr[u].r == x {
		st.tr[u].v += v
		return
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	if x <= mid {
		st.modify(u<<1, x, v)
	} else {
		st.modify(u<<1|1, x, v)
	}
	st.pushup(u)
}

func (st *SegmentTree) pushup(u int) {
	st.tr[u].v = st.tr[u<<1].v + st.tr[u<<1|1].v
}

func (st *SegmentTree) query(u, l, r int) int {
	if st.tr[u].l >= l && st.tr[u].r <= r {
		return st.tr[u].v
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	res := 0
	if l <= mid {
		res += st.query(u<<1, l, r)
	}
	if r > mid {
		res += st.query(u<<1|1, l, r)
	}
	return res
}

func goodTriplets(nums1 []int, nums2 []int) int64 {
	n := len(nums1)
	pos := make(map[int]int)
	for i, v := range nums2 {
		pos[v] = i + 1
	}

	tree := NewSegmentTree(n)
	var ans int64

	for _, num := range nums1 {
		p := pos[num]
		left := tree.query(1, 1, p)
		right := n - p - (tree.query(1, 1, n) - tree.query(1, 1, p))
		ans += int64(left * right)
		tree.modify(1, p, 1)
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Node {
    l: number = 0;
    r: number = 0;
    v: number = 0;
}

class SegmentTree {
    private tr: Node[];

    constructor(n: number) {
        this.tr = Array(4 * n);
        for (let i = 0; i < 4 * n; i++) {
            this.tr[i] = new Node();
        }
        this.build(1, 1, n);
    }

    private build(u: number, l: number, r: number): void {
        this.tr[u].l = l;
        this.tr[u].r = r;
        if (l === r) return;
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
    }

    modify(u: number, x: number, v: number): void {
        if (this.tr[u].l === x && this.tr[u].r === x) {
            this.tr[u].v += v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    private pushup(u: number): void {
        this.tr[u].v = this.tr[u << 1].v + this.tr[(u << 1) | 1].v;
    }

    query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].v;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let res = 0;
        if (l <= mid) {
            res += this.query(u << 1, l, r);
        }
        if (r > mid) {
            res += this.query((u << 1) | 1, l, r);
        }
        return res;
    }
}

function goodTriplets(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const pos = new Map<number, number>();
    nums2.forEach((v, i) => pos.set(v, i + 1));

    const tree = new SegmentTree(n);
    let ans = 0;

    for (const num of nums1) {
        const p = pos.get(num)!;
        const left = tree.query(1, 1, p);
        const total = tree.query(1, 1, n);
        const right = n - p - (total - left);
        ans += left * right;
        tree.modify(1, p, 1);
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

<p>给你两个下标从 <strong>0</strong>&nbsp;开始且长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;，两者都是&nbsp;<code>[0, 1, ..., n - 1]</code>&nbsp;的&nbsp;<strong>排列</strong>&nbsp;。</p>

<p><strong>好三元组&nbsp;</strong>指的是&nbsp;<code>3</code>&nbsp;个&nbsp;<strong>互不相同</strong>&nbsp;的值，且它们在数组&nbsp;<code>nums1</code> 和&nbsp;<code>nums2</code>&nbsp;中出现顺序保持一致。换句话说，如果我们将&nbsp;<code>pos1<sub>v</sub></code> 记为值&nbsp;<code>v</code>&nbsp;在&nbsp;<code>nums1</code>&nbsp;中出现的位置，<code>pos2<sub>v</sub></code>&nbsp;为值&nbsp;<code>v</code>&nbsp;在&nbsp;<code>nums2</code>&nbsp;中的位置，那么一个好三元组定义为&nbsp;<code>0 &lt;= x, y, z &lt;= n - 1</code>&nbsp;，且&nbsp;<code>pos1<sub>x</sub> &lt; pos1<sub>y</sub> &lt; pos1<sub>z</sub></code> 和&nbsp;<code>pos2<sub>x</sub> &lt; pos2<sub>y</sub> &lt; pos2<sub>z</sub></code>&nbsp;都成立的&nbsp;<code>(x, y, z)</code>&nbsp;。</p>

<p>请你返回好三元组的 <strong>总数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums1 = [2,0,1,3], nums2 = [0,1,2,3]
<b>输出：</b>1
<b>解释：</b>
总共有 4 个三元组 (x,y,z) 满足 pos1<sub>x</sub> &lt; pos1<sub>y</sub> &lt; pos1<sub>z&nbsp;</sub>，分别是 (2,0,1) ，(2,0,3) ，(2,1,3) 和 (0,1,3) 。
这些三元组中，只有 (0,1,3) 满足 pos2<sub>x</sub> &lt; pos2<sub>y</sub> &lt; pos2<sub>z</sub>&nbsp;。所以只有 1 个好三元组。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
<b>输出：</b>4
<b>解释：</b>总共有 4 个好三元组 (4,0,3) ，(4,0,2) ，(4,1,3) 和 (4,1,2) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= n - 1</code></li>
	<li><code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;是&nbsp;<code>[0, 1, ..., n - 1]</code> 的排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

对于本题，我们先用 pos 记录每个数在 nums2 中的位置，然后依次对 nums1 中的每个元素进行处理。

考虑**以当前数字作为三元组中间数字**的好三元组的数目。第一个数字需要是之前已经遍历过的，并且在 nums2 中的位置比当前数字更靠前的；第三个数字需要是当前还没有遍历过的，并且在 nums2 中的位置比当前数字更靠后的。

以 `nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]`为例，考虑我们的遍历过程：

1. 首先处理 4，此时 nums2 中出现情况为 `[4,X,X,X,X]`，4 之前有值的个数是 0，4 之后没有值的个数有 4 个。因此以 4 为中间数字能形成 0 个好三元组。
1. 接下来是 0，此时 nums2 中出现情况为 `[4,X,0,X,X]`，0 之前有值的个数是 1，0 之后没有值的个数有 2 个。因此以 0 为中间数字能形成 2 个好三元组。
1. 接下来是 1，此时 nums2 中出现情况为 `[4,1,0,X,X]`，1 之前有值的个数是 1，0 之后没有值的个数有 2 个。因此以 1 为中间数字能形成 2 个好三元组。
1. ...
1. 最后是 2，此时 nums2 中出现情况为 `[4,1,0,2,3]`，2 之前有值的个数是 4，2 之后没有值的个数是 0。因此以 2 为中间数字能形成 0 个好三元组。

我们可以用**树状数组**来更新 nums2 中各个位置数字的出现情况，快速算出每个数字左侧 1 的个数，以及右侧 0 的个数。

树状数组，也称作“二叉索引树”（Binary Indexed Tree）或 Fenwick 树。 它可以高效地实现如下两个操作：

1. **单点更新** `update(x, delta)`： 把序列 x 位置的数加上一个值 delta；
1. **前缀和查询** `query(x)`：查询序列 `[1,...x]` 区间的区间和，即位置 x 的前缀和。

这两个操作的时间复杂度均为 $O(\log n)$。因此，整体的时间复杂度为 $O(n \log n)$，其中 $n$ 为数组 $\textit{nums1}$ 的长度。空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    @staticmethod
    def lowbit(x):
        return x & -x

    def update(self, x, delta):
        while x <= self.n:
            self.c[x] += delta
            x += BinaryIndexedTree.lowbit(x)

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= BinaryIndexedTree.lowbit(x)
        return s


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        pos = {v: i for i, v in enumerate(nums2, 1)}
        ans = 0
        n = len(nums1)
        tree = BinaryIndexedTree(n)
        for num in nums1:
            p = pos[num]
            left = tree.query(p)
            right = n - p - (tree.query(n) - tree.query(p))
            ans += left * right
            tree.update(p, 1)
        return ans
```

#### Java

```java
class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] pos = new int[n];
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i + 1;
        }
        long ans = 0;
        for (int num : nums1) {
            int p = pos[num];
            long left = tree.query(p);
            long right = n - p - (tree.query(n) - tree.query(p));
            ans += left * right;
            tree.update(p, 1);
        }
        return ans;
    }
}

class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        c = new int[n + 1];
    }

    public void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    public static int lowbit(int x) {
        return x & -x;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    int n;
    vector<int> c;

    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= lowbit(x);
        }
        return s;
    }

    int lowbit(int x) {
        return x & -x;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[nums2[i]] = i + 1;
        BinaryIndexedTree* tree = new BinaryIndexedTree(n);
        long long ans = 0;
        for (int& num : nums1) {
            int p = pos[num];
            int left = tree->query(p);
            int right = n - p - (tree->query(n) - tree->query(p));
            ans += 1ll * left * right;
            tree->update(p, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) lowbit(x int) int {
	return x & -x
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += this.lowbit(x)
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= this.lowbit(x)
	}
	return s
}

func goodTriplets(nums1 []int, nums2 []int) int64 {
	n := len(nums1)
	pos := make([]int, n)
	for i, v := range nums2 {
		pos[v] = i + 1
	}
	tree := newBinaryIndexedTree(n)
	var ans int64
	for _, num := range nums1 {
		p := pos[num]
		left := tree.query(p)
		right := n - p - (tree.query(n) - tree.query(p))
		ans += int64(left) * int64(right)
		tree.update(p, 1)
	}
	return ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private c: number[];
    private n: number;

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    private static lowbit(x: number): number {
        return x & -x;
    }

    update(x: number, delta: number): void {
        while (x <= this.n) {
            this.c[x] += delta;
            x += BinaryIndexedTree.lowbit(x);
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= BinaryIndexedTree.lowbit(x);
        }
        return s;
    }
}

function goodTriplets(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const pos = new Map<number, number>();
    nums2.forEach((v, i) => pos.set(v, i + 1));

    const tree = new BinaryIndexedTree(n);
    let ans = 0;

    for (const num of nums1) {
        const p = pos.get(num)!;
        const left = tree.query(p);
        const total = tree.query(n);
        const right = n - p - (total - left);
        ans += left * right;
        tree.update(p, 1);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：线段树

我们也可以用线段树来实现。线段树是一种数据结构，能够高效地进行区间查询和更新操作。它的基本思想是将一个区间划分为多个子区间，并且每个子区间都可以用一个节点来表示。

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 `log(width)`。更新某个元素的值，只需要更新 `log(width)` 个区间，并且这些区间都包含在一个包含该元素的大区间内。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 `[1, N]`；
-   线段树的每个叶子节点代表一个长度为 1 的元区间 `[x, x]`；
-   对于每个内部节点 `[l, r]`，它的左儿子是 `[l, mid]`，右儿子是 `[mid + 1, r]`, 其中 `mid = ⌊(l + r) / 2⌋` (即向下取整)。

时间复杂度 $O(n \log n)$，其中 $n$ 为数组 $\textit{nums1}$ 的长度。空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ("l", "r", "v")

    def __init__(self):
        self.l = 0
        self.r = 0
        self.v = 0


class SegmentTree:
    def __init__(self, n):
        self.tr = [Node() for _ in range(4 * n)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l = l
        self.tr[u].r = r
        if l == r:
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)

    def modify(self, u, x, v):
        if self.tr[u].l == x and self.tr[u].r == x:
            self.tr[u].v += v
            return
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if x <= mid:
            self.modify(u << 1, x, v)
        else:
            self.modify(u << 1 | 1, x, v)
        self.pushup(u)

    def pushup(self, u):
        self.tr[u].v = self.tr[u << 1].v + self.tr[u << 1 | 1].v

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].v
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        v = 0
        if l <= mid:
            v += self.query(u << 1, l, r)
        if r > mid:
            v += self.query(u << 1 | 1, l, r)
        return v


class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        pos = {v: i for i, v in enumerate(nums2, 1)}
        ans = 0
        n = len(nums1)
        tree = SegmentTree(n)
        for num in nums1:
            p = pos[num]
            left = tree.query(1, 1, p)
            right = n - p - (tree.query(1, 1, n) - tree.query(1, 1, p))
            ans += left * right
            tree.modify(1, p, 1)
        return ans
```

#### Java

```java
class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] pos = new int[n];
        SegmentTree tree = new SegmentTree(n);
        for (int i = 0; i < n; ++i) {
            pos[nums2[i]] = i + 1;
        }
        long ans = 0;
        for (int num : nums1) {
            int p = pos[num];
            long left = tree.query(1, 1, p);
            long right = n - p - (tree.query(1, 1, n) - tree.query(1, 1, p));
            ans += left * right;
            tree.modify(1, p, 1);
        }
        return ans;
    }
}

class Node {
    int l;
    int r;
    int v;
}

class SegmentTree {
    private Node[] tr;

    public SegmentTree(int n) {
        tr = new Node[4 * n];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    public void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    public void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x) {
            tr[u].v += v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) {
            modify(u << 1, x, v);
        } else {
            modify(u << 1 | 1, x, v);
        }
        pushup(u);
    }

    public void pushup(int u) {
        tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
    }

    public int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return tr[u].v;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = 0;
        if (l <= mid) {
            v += query(u << 1, l, r);
        }
        if (r > mid) {
            v += query(u << 1 | 1, l, r);
        }
        return v;
    }
}
```

#### C++

```cpp
class Node {
public:
    int l;
    int r;
    int v;
};

class SegmentTree {
public:
    vector<Node*> tr;

    SegmentTree(int n) {
        tr.resize(4 * n);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 1, n);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }

    void modify(int u, int x, int v) {
        if (tr[u]->l == x && tr[u]->r == x) {
            tr[u]->v += v;
            return;
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }

    void pushup(int u) {
        tr[u]->v = tr[u << 1]->v + tr[u << 1 | 1]->v;
    }

    int query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) return tr[u]->v;
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        int v = 0;
        if (l <= mid) v += query(u << 1, l, r);
        if (r > mid) v += query(u << 1 | 1, l, r);
        return v;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) pos[nums2[i]] = i + 1;
        SegmentTree* tree = new SegmentTree(n);
        long long ans = 0;
        for (int& num : nums1) {
            int p = pos[num];
            int left = tree->query(1, 1, p);
            int right = n - p - (tree->query(1, 1, n) - tree->query(1, 1, p));
            ans += 1ll * left * right;
            tree->modify(1, p, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type Node struct {
	l, r, v int
}

type SegmentTree struct {
	tr []Node
}

func NewSegmentTree(n int) *SegmentTree {
	tr := make([]Node, 4*n)
	st := &SegmentTree{tr: tr}
	st.build(1, 1, n)
	return st
}

func (st *SegmentTree) build(u, l, r int) {
	st.tr[u].l = l
	st.tr[u].r = r
	if l == r {
		return
	}
	mid := (l + r) >> 1
	st.build(u<<1, l, mid)
	st.build(u<<1|1, mid+1, r)
}

func (st *SegmentTree) modify(u, x, v int) {
	if st.tr[u].l == x && st.tr[u].r == x {
		st.tr[u].v += v
		return
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	if x <= mid {
		st.modify(u<<1, x, v)
	} else {
		st.modify(u<<1|1, x, v)
	}
	st.pushup(u)
}

func (st *SegmentTree) pushup(u int) {
	st.tr[u].v = st.tr[u<<1].v + st.tr[u<<1|1].v
}

func (st *SegmentTree) query(u, l, r int) int {
	if st.tr[u].l >= l && st.tr[u].r <= r {
		return st.tr[u].v
	}
	mid := (st.tr[u].l + st.tr[u].r) >> 1
	res := 0
	if l <= mid {
		res += st.query(u<<1, l, r)
	}
	if r > mid {
		res += st.query(u<<1|1, l, r)
	}
	return res
}

func goodTriplets(nums1 []int, nums2 []int) int64 {
	n := len(nums1)
	pos := make(map[int]int)
	for i, v := range nums2 {
		pos[v] = i + 1
	}

	tree := NewSegmentTree(n)
	var ans int64

	for _, num := range nums1 {
		p := pos[num]
		left := tree.query(1, 1, p)
		right := n - p - (tree.query(1, 1, n) - tree.query(1, 1, p))
		ans += int64(left * right)
		tree.modify(1, p, 1)
	}

	return ans
}
```

#### TypeScript

```ts
class Node {
    l: number = 0;
    r: number = 0;
    v: number = 0;
}

class SegmentTree {
    private tr: Node[];

    constructor(n: number) {
        this.tr = Array(4 * n);
        for (let i = 0; i < 4 * n; i++) {
            this.tr[i] = new Node();
        }
        this.build(1, 1, n);
    }

    private build(u: number, l: number, r: number): void {
        this.tr[u].l = l;
        this.tr[u].r = r;
        if (l === r) return;
        const mid = (l + r) >> 1;
        this.build(u << 1, l, mid);
        this.build((u << 1) | 1, mid + 1, r);
    }

    modify(u: number, x: number, v: number): void {
        if (this.tr[u].l === x && this.tr[u].r === x) {
            this.tr[u].v += v;
            return;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        if (x <= mid) {
            this.modify(u << 1, x, v);
        } else {
            this.modify((u << 1) | 1, x, v);
        }
        this.pushup(u);
    }

    private pushup(u: number): void {
        this.tr[u].v = this.tr[u << 1].v + this.tr[(u << 1) | 1].v;
    }

    query(u: number, l: number, r: number): number {
        if (this.tr[u].l >= l && this.tr[u].r <= r) {
            return this.tr[u].v;
        }
        const mid = (this.tr[u].l + this.tr[u].r) >> 1;
        let res = 0;
        if (l <= mid) {
            res += this.query(u << 1, l, r);
        }
        if (r > mid) {
            res += this.query((u << 1) | 1, l, r);
        }
        return res;
    }
}

function goodTriplets(nums1: number[], nums2: number[]): number {
    const n = nums1.length;
    const pos = new Map<number, number>();
    nums2.forEach((v, i) => pos.set(v, i + 1));

    const tree = new SegmentTree(n);
    let ans = 0;

    for (const num of nums1) {
        const p = pos.get(num)!;
        const left = tree.query(1, 1, p);
        const total = tree.query(1, 1, n);
        const right = n - p - (total - left);
        ans += left * right;
        tree.modify(1, p, 1);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
