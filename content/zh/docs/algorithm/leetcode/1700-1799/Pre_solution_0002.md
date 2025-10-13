---
title: "1710_卡车上的最大单元数"
date: 2025-10-08T18:38:17+08:00
weight: 2
tags: [二分查找, 前缀和, 动态规划, 双指针, 哈希表, 回溯, 图, 字符串, 排序, 数学, 数据库, 数组, 栈, 树, 贪心]
---

{{< markmap >}}
### [1710_卡车上的最大单元数](#1710)
#### [贪心](#1710)
#### [数组](#1710)
#### [排序](#1710)
### [1711_大餐计数](#1711)
#### [数组](#1711)
#### [哈希表](#1711)
### [1712_将数组分成三个子数组的方案数](#1712)
#### [数组](#1712)
#### [双指针](#1712)
#### [二分查找](#1712)
#### [前缀和](#1712)
### [1713_得到子序列的最少操作次数](#1713)
#### [贪心](#1713)
#### [数组](#1713)
#### [哈希表](#1713)
#### [二分查找](#1713)
### [1714_数组中特殊等间距元素的和 🔒](#1714)
#### [数组](#1714)
#### [动态规划](#1714)
### [1715_苹果和橘子的个数 🔒](#1715)
#### [数据库](#1715)
### [1716_计算力扣银行的钱](#1716)
#### [数学](#1716)
### [1717_删除子字符串的最大得分](#1717)
#### [栈](#1717)
#### [贪心](#1717)
#### [字符串](#1717)
### [1718_构建字典序最大的可行序列](#1718)
#### [数组](#1718)
#### [回溯](#1718)
### [1719_重构一棵树的方案数](#1719)
#### [树](#1719)
#### [图](#1719)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1710_卡车上的最大单元数
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 1711_大餐计数
___
#### 数组
___
#### 哈希表
---
### 1712_将数组分成三个子数组的方案数
___
#### 数组
___
#### 双指针
___
#### 二分查找
___
#### 前缀和
---
### 1713_得到子序列的最少操作次数
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 二分查找
---
### 1714_数组中特殊等间距元素的和 🔒
___
#### 数组
___
#### 动态规划
---
### 1715_苹果和橘子的个数 🔒
___
#### 数据库
---
### 1716_计算力扣银行的钱
___
#### 数学
---
### 1717_删除子字符串的最大得分
___
#### 栈
___
#### 贪心
___
#### 字符串
---
### 1718_构建字典序最大的可行序列
___
#### 数组
___
#### 回溯
---
### 1719_重构一棵树的方案数
___
#### 树
___
#### 图
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 双指针 | 哈希表 | 回溯 |
| 图 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 树 | 贪心 |

# [1710. 卡车上的最大单元数](https://leetcode.cn/problems/maximum-units-on-a-truck){#1710}

{{< tabs "1710" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        cnt = [0] * 1001
        for a, b in boxTypes:
            cnt[b] += a
        ans = 0
        for b in range(1000, 0, -1):
            a = cnt[b]
            if a:
                ans += b * min(truckSize, a)
                truckSize -= a
                if truckSize <= 0:
                    break
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        int[] cnt = new int[1001];
        for (var e : boxTypes) {
            int a = e[0], b = e[1];
            cnt[b] += a;
        }
        int ans = 0;
        for (int b = 1000; b > 0 && truckSize > 0; --b) {
            int a = cnt[b];
            if (a > 0) {
                ans += b * Math.min(truckSize, a);
                truckSize -= a;
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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int cnt[1001] = {0};
        for (auto& e : boxTypes) {
            int a = e[0], b = e[1];
            cnt[b] += a;
        }
        int ans = 0;
        for (int b = 1000; b > 0 && truckSize > 0; --b) {
            int a = cnt[b];
            if (a) {
                ans += b * min(truckSize, a);
                truckSize -= a;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumUnits(boxTypes [][]int, truckSize int) (ans int) {
	cnt := [1001]int{}
	for _, e := range boxTypes {
		a, b := e[0], e[1]
		cnt[b] += a
	}
	for b := 1000; b > 0 && truckSize > 0; b-- {
		a := cnt[b]
		if a > 0 {
			ans += b * min(truckSize, a)
			truckSize -= a
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumUnits(boxTypes: number[][], truckSize: number): number {
    boxTypes.sort(([_, a], [__, b]) => b - a);
    let ans = 0;
    for (const [count, size] of boxTypes) {
        ans += Math.min(truckSize, count) * size;
        truckSize -= count;
        if (truckSize < 0) {
            break;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_units(mut box_types: Vec<Vec<i32>>, truck_size: i32) -> i32 {
        box_types.sort_by(|a, b| b[1].cmp(&a[1]));
        let mut sum = 0;
        let mut ans = 0;
        for box_type in box_types.iter() {
            if sum + box_type[0] < truck_size {
                sum += box_type[0];
                ans += box_type[0] * box_type[1];
            } else {
                ans += (truck_size - sum) * box_type[1];
                break;
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

<p>请你将一些箱子装在 <strong>一辆卡车</strong> 上。给你一个二维数组 <code>boxTypes</code> ，其中 <code>boxTypes[i] = [numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub>]</code> ：</p>

<ul>
	<li><code>numberOfBoxes<sub>i</sub></code> 是类型 <code>i</code> 的箱子的数量。</li>
	<li><code>numberOfUnitsPerBox<sub>i</sub></code><sub> </sub>是类型 <code>i</code> 每个箱子可以装载的单元数量。</li>
</ul>

<p>整数 <code>truckSize</code> 表示卡车上可以装载 <strong>箱子</strong> 的 <strong>最大数量</strong> 。只要箱子数量不超过 <code>truckSize</code> ，你就可以选择任意箱子装到卡车上。</p>

<p>返回卡车可以装载 <strong>单元</strong> 的 <strong>最大</strong> 总数<em>。</em></p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
<strong>输出：</strong>8
<strong>解释：</strong>箱子的情况如下：
- 1 个第一类的箱子，里面含 3 个单元。
- 2 个第二类的箱子，每个里面含 2 个单元。
- 3 个第三类的箱子，每个里面含 1 个单元。
可以选择第一类和第二类的所有箱子，以及第三类的一个箱子。
单元总数 = (1 * 3) + (2 * 2) + (1 * 1) = 8</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
<strong>输出：</strong>91
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= boxTypes.length <= 1000</code></li>
	<li><code>1 <= numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub> <= 1000</code></li>
	<li><code>1 <= truckSize <= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

根据题意，我们应该选择尽可能多的单元数，因此，我们先对 `boxTypes` 按照单元数从大到小的顺序排列。

然后从前往后遍历 `boxTypes`，选择最多 `truckSize` 个箱子，累加单元数。

时间复杂度 $O(n \times \log n)$，其中 $n$ 表示二维数组 `boxTypes` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        ans = 0
        for a, b in sorted(boxTypes, key=lambda x: -x[1]):
            ans += b * min(truckSize, a)
            truckSize -= a
            if truckSize <= 0:
                break
        return ans
```

#### Java

```java
class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a, b) -> b[1] - a[1]);
        int ans = 0;
        for (var e : boxTypes) {
            int a = e[0], b = e[1];
            ans += b * Math.min(truckSize, a);
            truckSize -= a;
            if (truckSize <= 0) {
                break;
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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
        int ans = 0;
        for (auto& e : boxTypes) {
            int a = e[0], b = e[1];
            ans += b * min(truckSize, a);
            truckSize -= a;
            if (truckSize <= 0) break;
        }
        return ans;
    }
};
```

#### Go

```go
func maximumUnits(boxTypes [][]int, truckSize int) (ans int) {
	sort.Slice(boxTypes, func(i, j int) bool { return boxTypes[i][1] > boxTypes[j][1] })
	for _, e := range boxTypes {
		a, b := e[0], e[1]
		ans += b * min(truckSize, a)
		truckSize -= a
		if truckSize <= 0 {
			break
		}
	}
	return
}
```

#### TypeScript

```ts
export function maximumUnits(boxTypes: number[][], truckSize: number): number {
    boxTypes.sort(([_, a], [__, b]) => b - a);
    let ans = 0;
    for (const [count, size] of boxTypes) {
        ans += Math.min(truckSize, count) * size;
        truckSize -= count;
        if (truckSize < 0) break;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_units(mut box_types: Vec<Vec<i32>>, truck_size: i32) -> i32 {
        box_types.sort_by(|a, b| b[1].cmp(&a[1]));
        let mut sum = 0;
        let mut ans = 0;
        for box_type in box_types.iter() {
            if sum + box_type[0] < truck_size {
                sum += box_type[0];
                ans += box_type[0] * box_type[1];
            } else {
                ans += (truck_size - sum) * box_type[1];
                break;
            }
        }
        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：计数排序

我们还可以利用计数排序的思想，开一个长度为 $1001$ 的数组 $cnt$，其中 $cnt[b]$ 表示单元数为 $b$ 的箱子的数量。

然后从单元数最大的箱子开始，选择最多 `truckSize` 个箱子，累加单元数。

时间复杂度 $O(M)$，其中 $M$ 是单元数的最大值。本题中 $M=1000$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        cnt = [0] * 1001
        for a, b in boxTypes:
            cnt[b] += a
        ans = 0
        for b in range(1000, 0, -1):
            a = cnt[b]
            if a:
                ans += b * min(truckSize, a)
                truckSize -= a
                if truckSize <= 0:
                    break
        return ans
```

#### Java

```java
class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        int[] cnt = new int[1001];
        for (var e : boxTypes) {
            int a = e[0], b = e[1];
            cnt[b] += a;
        }
        int ans = 0;
        for (int b = 1000; b > 0 && truckSize > 0; --b) {
            int a = cnt[b];
            if (a > 0) {
                ans += b * Math.min(truckSize, a);
                truckSize -= a;
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
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int cnt[1001] = {0};
        for (auto& e : boxTypes) {
            int a = e[0], b = e[1];
            cnt[b] += a;
        }
        int ans = 0;
        for (int b = 1000; b > 0 && truckSize > 0; --b) {
            int a = cnt[b];
            if (a) {
                ans += b * min(truckSize, a);
                truckSize -= a;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maximumUnits(boxTypes [][]int, truckSize int) (ans int) {
	cnt := [1001]int{}
	for _, e := range boxTypes {
		a, b := e[0], e[1]
		cnt[b] += a
	}
	for b := 1000; b > 0 && truckSize > 0; b-- {
		a := cnt[b]
		if a > 0 {
			ans += b * min(truckSize, a)
			truckSize -= a
		}
	}
	return
}
```

#### TypeScript

```ts
function maximumUnits(boxTypes: number[][], truckSize: number): number {
    boxTypes.sort(([_, a], [__, b]) => b - a);
    let ans = 0;
    for (const [count, size] of boxTypes) {
        ans += Math.min(truckSize, count) * size;
        truckSize -= count;
        if (truckSize < 0) {
            break;
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

# [1711. 大餐计数](https://leetcode.cn/problems/count-good-meals){#1711}

{{< tabs "1711" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        mod = 10**9 + 7
        cnt = Counter(deliciousness)
        ans = 0
        for i in range(22):
            s = 1 << i
            for a, m in cnt.items():
                if (b := s - a) in cnt:
                    ans += m * (m - 1) if a == b else m * cnt[b]
        return (ans >> 1) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPairs(int[] deliciousness) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int d : deliciousness) {
            cnt.put(d, cnt.getOrDefault(d, 0) + 1);
        }
        long ans = 0;
        for (int i = 0; i < 22; ++i) {
            int s = 1 << i;
            for (var x : cnt.entrySet()) {
                int a = x.getKey(), m = x.getValue();
                int b = s - a;
                if (!cnt.containsKey(b)) {
                    continue;
                }
                ans += 1L * m * (a == b ? m - 1 : cnt.get(b));
            }
        }
        ans >>= 1;
        return (int) (ans % MOD);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> cnt;
        for (int& d : deliciousness) ++cnt[d];
        long long ans = 0;
        for (int i = 0; i < 22; ++i) {
            int s = 1 << i;
            for (auto& [a, m] : cnt) {
                int b = s - a;
                if (!cnt.count(b)) continue;
                ans += 1ll * m * (a == b ? (m - 1) : cnt[b]);
            }
        }
        ans >>= 1;
        return ans % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPairs(deliciousness []int) (ans int) {
	cnt := map[int]int{}
	for _, d := range deliciousness {
		cnt[d]++
	}
	const mod int = 1e9 + 7
	for i := 0; i < 22; i++ {
		s := 1 << i
		for a, m := range cnt {
			b := s - a
			if n, ok := cnt[b]; ok {
				if a == b {
					ans += m * (m - 1)
				} else {
					ans += m * n
				}
			}
		}
	}
	ans >>= 1
	return ans % mod
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>大餐</strong> 是指 <strong>恰好包含两道不同餐品</strong> 的一餐，其美味程度之和等于 2 的幂。</p>

<p>你可以搭配 <strong>任意</strong> 两道餐品做一顿大餐。</p>

<p>给你一个整数数组 <code>deliciousness</code> ，其中 <code>deliciousness[i]</code> 是第 <code>i<sup>​​​​​​</sup>​​​​</code>​​​​ 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 <strong>大餐</strong> 的数量。结果需要对 <code>10<sup>9</sup> + 7</code> 取余。</p>

<p>注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>deliciousness = [1,3,5,7,9]
<strong>输出：</strong>4
<strong>解释：</strong>大餐的美味程度组合为 (1,3) 、(1,7) 、(3,5) 和 (7,9) 。
它们各自的美味程度之和分别为 4 、8 、8 和 16 ，都是 2 的幂。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>deliciousness = [1,1,1,3,3,3,7]
<strong>输出：</strong>15
<strong>解释：</strong>大餐的美味程度组合为 3 种 (1,1) ，9 种 (1,3) ，和 3 种 (1,7) 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= deliciousness.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= deliciousness[i] <= 2<sup>20</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举二的幂

根据题意，我们需要统计数组中两个数的和为 $2$ 的幂的组合数。直接暴力枚举所有的组合数，时间复杂度为 $O(n^2)$ ，肯定会超时。

我们可以遍历数组，用哈希表 $cnt$ 维护数组中每个元素 $d$ 出现的次数。

对于每个元素，我们从小到大枚举二的幂次方 $s$ 作为两数之和，将哈希表中 $s - d$ 出现的次数累加到答案中。然后将当前元素 $d$ 出现的次数加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n\times \log M)$，其中 $n$ 是数组 `deliciousness` 的长度，而 $M$ 是元素的上限，对于本题，上限 $M=2^{20}$。

我们也可以先用哈希表 $cnt$ 统计数组中每个元素出现的次数。

然后从小到大枚举二的幂次方 $s$ 作为两数之和，对于每个 $s$，遍历哈希表每个键值对 $(a, m)$，如果 $s - a$ 也在哈希表中，且 $s - a \neq a$，则答案加上 $m \times cnt[s - a]$；如果 $s - a = a$，则答案加上 $m \times (m - 1)$。

最后，将答案除以 $2$ 之后，模 $10^9 + 7$，返回即可。

时间复杂度与上面的方法相同。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        mod = 10**9 + 7
        mx = max(deliciousness) << 1
        cnt = Counter()
        ans = 0
        for d in deliciousness:
            s = 1
            while s <= mx:
                ans = (ans + cnt[s - d]) % mod
                s <<= 1
            cnt[d] += 1
        return ans
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPairs(int[] deliciousness) {
        int mx = Arrays.stream(deliciousness).max().getAsInt() << 1;
        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int d : deliciousness) {
            for (int s = 1; s <= mx; s <<= 1) {
                ans = (ans + cnt.getOrDefault(s - d, 0)) % MOD;
            }
            cnt.merge(d, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPairs(vector<int>& deliciousness) {
        int mx = *max_element(deliciousness.begin(), deliciousness.end()) << 1;
        unordered_map<int, int> cnt;
        int ans = 0;
        for (auto& d : deliciousness) {
            for (int s = 1; s <= mx; s <<= 1) {
                ans = (ans + cnt[s - d]) % mod;
            }
            ++cnt[d];
        }
        return ans;
    }
};
```

#### Go

```go
func countPairs(deliciousness []int) (ans int) {
	mx := slices.Max(deliciousness) << 1
	const mod int = 1e9 + 7
	cnt := map[int]int{}
	for _, d := range deliciousness {
		for s := 1; s <= mx; s <<= 1 {
			ans = (ans + cnt[s-d]) % mod
		}
		cnt[d]++
	}
	return
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
    def countPairs(self, deliciousness: List[int]) -> int:
        mod = 10**9 + 7
        cnt = Counter(deliciousness)
        ans = 0
        for i in range(22):
            s = 1 << i
            for a, m in cnt.items():
                if (b := s - a) in cnt:
                    ans += m * (m - 1) if a == b else m * cnt[b]
        return (ans >> 1) % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countPairs(int[] deliciousness) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int d : deliciousness) {
            cnt.put(d, cnt.getOrDefault(d, 0) + 1);
        }
        long ans = 0;
        for (int i = 0; i < 22; ++i) {
            int s = 1 << i;
            for (var x : cnt.entrySet()) {
                int a = x.getKey(), m = x.getValue();
                int b = s - a;
                if (!cnt.containsKey(b)) {
                    continue;
                }
                ans += 1L * m * (a == b ? m - 1 : cnt.get(b));
            }
        }
        ans >>= 1;
        return (int) (ans % MOD);
    }
}
```

#### C++

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> cnt;
        for (int& d : deliciousness) ++cnt[d];
        long long ans = 0;
        for (int i = 0; i < 22; ++i) {
            int s = 1 << i;
            for (auto& [a, m] : cnt) {
                int b = s - a;
                if (!cnt.count(b)) continue;
                ans += 1ll * m * (a == b ? (m - 1) : cnt[b]);
            }
        }
        ans >>= 1;
        return ans % mod;
    }
};
```

#### Go

```go
func countPairs(deliciousness []int) (ans int) {
	cnt := map[int]int{}
	for _, d := range deliciousness {
		cnt[d]++
	}
	const mod int = 1e9 + 7
	for i := 0; i < 22; i++ {
		s := 1 << i
		for a, m := range cnt {
			b := s - a
			if n, ok := cnt[b]; ok {
				if a == b {
					ans += m * (m - 1)
				} else {
					ans += m * n
				}
			}
		}
	}
	ans >>= 1
	return ans % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1712. 将数组分成三个子数组的方案数](https://leetcode.cn/problems/ways-to-split-array-into-three-subarrays){#1712}

{{< tabs "1712" >}}

{{% tab "python" %}}
```python
class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        s = list(accumulate(nums))
        ans, n = 0, len(nums)
        for i in range(n - 2):
            j = bisect_left(s, s[i] << 1, i + 1, n - 1)
            k = bisect_right(s, (s[-1] + s[i]) >> 1, j, n - 1)
            ans += k - j
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int waysToSplit(int[] nums) {
        int n = nums.length;
        int[] s = new int[n];
        s[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            int j = search(s, s[i] << 1, i + 1, n - 1);
            int k = search(s, ((s[n - 1] + s[i]) >> 1) + 1, j, n - 1);
            ans = (ans + k - j) % MOD;
        }
        return ans;
    }

    private int search(int[] s, int x, int left, int right) {
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n, nums[0]);
        for (int i = 1; i < n; ++i) s[i] = s[i - 1] + nums[i];
        int ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            int j = lower_bound(s.begin() + i + 1, s.begin() + n - 1, s[i] << 1) - s.begin();
            int k = upper_bound(s.begin() + j, s.begin() + n - 1, (s[n - 1] + s[i]) >> 1) - s.begin();
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func waysToSplit(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	s := make([]int, n)
	s[0] = nums[0]
	for i := 1; i < n; i++ {
		s[i] = s[i-1] + nums[i]
	}
	for i := 0; i < n-2; i++ {
		j := sort.Search(n-1, func(h int) bool { return h > i && s[h] >= (s[i]<<1) })
		k := sort.Search(n-1, func(h int) bool { return h >= j && s[h] > (s[n-1]+s[i])>>1 })
		ans = (ans + k - j) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplit = function (nums) {
    const mod = 1e9 + 7;
    const n = nums.length;
    const s = new Array(n).fill(nums[0]);
    for (let i = 1; i < n; ++i) {
        s[i] = s[i - 1] + nums[i];
    }
    function search(s, x, left, right) {
        while (left < right) {
            const mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    let ans = 0;
    for (let i = 0; i < n - 2; ++i) {
        const j = search(s, s[i] << 1, i + 1, n - 1);
        const k = search(s, ((s[n - 1] + s[i]) >> 1) + 1, j, n - 1);
        ans = (ans + k - j) % mod;
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

<p>我们称一个分割整数数组的方案是 <strong>好的</strong> ，当它满足：</p>

<ul>
	<li>数组被分成三个 <strong>非空</strong> 连续子数组，从左至右分别命名为 <code>left</code> ， <code>mid</code> ， <code>right</code> 。</li>
	<li><code>left</code> 中元素和小于等于 <code>mid</code> 中元素和，<code>mid</code> 中元素和小于等于 <code>right</code> 中元素和。</li>
</ul>

<p>给你一个 <strong>非负</strong> 整数数组 <code>nums</code> ，请你返回 <strong>好的</strong> 分割 <code>nums</code> 方案数目。由于答案可能会很大，请你将结果对 <code>10<sup>9 </sup>+ 7</code> 取余后返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,1]
<b>输出：</b>1
<b>解释：</b>唯一一种好的分割方案是将 nums 分成 [1] [1] [1] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,2,2,5,0]
<b>输出：</b>3
<b>解释：</b>nums 总共有 3 种好的分割方案：
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,1]
<b>输出：</b>0
<b>解释：</b>没有好的分割方案。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>0 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 二分查找

我们先预处理出数组 $nums$ 的前缀和数组 $s$，其中 $s[i]$ 表述数组 $nums$ 前 $i+1$ 个元素之和。

由于数组 $nums$ 的元素都是非负整数，因此前缀和数组 $s$ 是一个单调递增数组。

我们在 $[0,..n-2)$ 的范围内枚举 `left` 子数组所能到达的下标 $i$，然后利用前缀和数组单调递增的特性，通过二分查找的方式找到 `mid` 子数组分割的合理范围，记为 $[j, k)$，累加方案数 $k-j$。

二分细节上，子数组分割必须满足 $s[j] \geq s[i]$，并且 $s[n - 1] - s[k] \geq s[k] - s[i]$。即 $s[j] \geq s[i]$，且 $s[k] \leq \frac{s[n - 1] + s[i]}{2}$。

最后，将方案数对 $10^9+7$ 取模后返回即可。

时间复杂度 $O(n \times \log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        s = list(accumulate(nums))
        ans, n = 0, len(nums)
        for i in range(n - 2):
            j = bisect_left(s, s[i] << 1, i + 1, n - 1)
            k = bisect_right(s, (s[-1] + s[i]) >> 1, j, n - 1)
            ans += k - j
        return ans % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int waysToSplit(int[] nums) {
        int n = nums.length;
        int[] s = new int[n];
        s[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            s[i] = s[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            int j = search(s, s[i] << 1, i + 1, n - 1);
            int k = search(s, ((s[n - 1] + s[i]) >> 1) + 1, j, n - 1);
            ans = (ans + k - j) % MOD;
        }
        return ans;
    }

    private int search(int[] s, int x, int left, int right) {
        while (left < right) {
            int mid = (left + right) >> 1;
            if (s[mid] >= x) {
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
    const int mod = 1e9 + 7;

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> s(n, nums[0]);
        for (int i = 1; i < n; ++i) s[i] = s[i - 1] + nums[i];
        int ans = 0;
        for (int i = 0; i < n - 2; ++i) {
            int j = lower_bound(s.begin() + i + 1, s.begin() + n - 1, s[i] << 1) - s.begin();
            int k = upper_bound(s.begin() + j, s.begin() + n - 1, (s[n - 1] + s[i]) >> 1) - s.begin();
            ans = (ans + k - j) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func waysToSplit(nums []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(nums)
	s := make([]int, n)
	s[0] = nums[0]
	for i := 1; i < n; i++ {
		s[i] = s[i-1] + nums[i]
	}
	for i := 0; i < n-2; i++ {
		j := sort.Search(n-1, func(h int) bool { return h > i && s[h] >= (s[i]<<1) })
		k := sort.Search(n-1, func(h int) bool { return h >= j && s[h] > (s[n-1]+s[i])>>1 })
		ans = (ans + k - j) % mod
	}
	return
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplit = function (nums) {
    const mod = 1e9 + 7;
    const n = nums.length;
    const s = new Array(n).fill(nums[0]);
    for (let i = 1; i < n; ++i) {
        s[i] = s[i - 1] + nums[i];
    }
    function search(s, x, left, right) {
        while (left < right) {
            const mid = (left + right) >> 1;
            if (s[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    let ans = 0;
    for (let i = 0; i < n - 2; ++i) {
        const j = search(s, s[i] << 1, i + 1, n - 1);
        const k = search(s, ((s[n - 1] + s[i]) >> 1) + 1, j, n - 1);
        ans = (ans + k - j) % mod;
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1713. 得到子序列的最少操作次数](https://leetcode.cn/problems/minimum-operations-to-make-a-subsequence){#1713}

{{< tabs "1713" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        res = 0
        while x:
            res = max(res, self.c[x])
            x -= x & -x
        return res


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        d = {x: i for i, x in enumerate(target, 1)}
        nums = [d[x] for x in arr if x in d]
        m = len(target)
        tree = BinaryIndexedTree(m)
        ans = 0
        for x in nums:
            v = tree.query(x - 1) + 1
            ans = max(ans, v)
            tree.update(x, v)
        return len(target) - ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] = Math.max(c[x], v);
        }
    }

    public int query(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) {
            ans = Math.max(ans, c[x]);
        }
        return ans;
    }
}

class Solution {
    public int minOperations(int[] target, int[] arr) {
        int m = target.length;
        Map<Integer, Integer> d = new HashMap<>(m);
        for (int i = 0; i < m; i++) {
            d.put(target[i], i + 1);
        }
        List<Integer> nums = new ArrayList<>();
        for (int x : arr) {
            if (d.containsKey(x)) {
                nums.add(d.get(x));
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        int ans = 0;
        for (int x : nums) {
            int v = tree.query(x - 1) + 1;
            ans = Math.max(ans, v);
            tree.update(x, v);
        }
        return m - ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] = max(c[x], v);
        }
    }

    int query(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) {
            ans = max(ans, c[x]);
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = target.size();
        unordered_map<int, int> d;
        for (int i = 0; i < m; ++i) {
            d[target[i]] = i + 1;
        }
        vector<int> nums;
        for (int x : arr) {
            if (d.contains(x)) {
                nums.push_back(d[x]);
            }
        }
        BinaryIndexedTree tree(m);
        int ans = 0;
        for (int x : nums) {
            int v = tree.query(x - 1) + 1;
            ans = max(ans, v);
            tree.update(x, v);
        }
        return m - ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	return BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) Update(x, v int) {
	for ; x <= bit.n; x += x & -x {
		if v > bit.c[x] {
			bit.c[x] = v
		}
	}
}

func (bit *BinaryIndexedTree) Query(x int) int {
	ans := 0
	for ; x > 0; x -= x & -x {
		if bit.c[x] > ans {
			ans = bit.c[x]
		}
	}
	return ans
}

func minOperations(target []int, arr []int) int {
	m := len(target)
	d := make(map[int]int)
	for i, x := range target {
		d[x] = i + 1
	}
	var nums []int
	for _, x := range arr {
		if pos, exists := d[x]; exists {
			nums = append(nums, pos)
		}
	}
	tree := NewBinaryIndexedTree(m)
	ans := 0
	for _, x := range nums {
		v := tree.Query(x-1) + 1
		if v > ans {
			ans = v
		}
		tree.Update(x, v)
	}
	return m - ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] = Math.max(this.c[x], v);
        }
    }

    query(x: number): number {
        let ans = 0;
        for (; x > 0; x -= x & -x) {
            ans = Math.max(ans, this.c[x]);
        }
        return ans;
    }
}

function minOperations(target: number[], arr: number[]): number {
    const m = target.length;
    const d: Map<number, number> = new Map();
    target.forEach((x, i) => d.set(x, i + 1));
    const nums: number[] = [];
    arr.forEach(x => {
        if (d.has(x)) {
            nums.push(d.get(x)!);
        }
    });
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    nums.forEach(x => {
        const v = tree.query(x - 1) + 1;
        ans = Math.max(ans, v);
        tree.update(x, v);
    });
    return m - ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>target</code> ，包含若干 <strong>互不相同</strong> 的整数，以及另一个整数数组 <code>arr</code> ，<code>arr</code> <strong>可能</strong> 包含重复元素。</p>

<p>每一次操作中，你可以在 <code>arr</code> 的任意位置插入任一整数。比方说，如果 <code>arr = [1,4,1,2]</code> ，那么你可以在中间添加 <code>3</code> 得到 <code>[1,4,<strong>3</strong>,1,2]</code> 。你可以在数组最开始或最后面添加整数。</p>

<p>请你返回 <strong>最少</strong> 操作次数，使得<em> </em><code>target</code><em> </em>成为 <code>arr</code> 的一个子序列。</p>

<p>一个数组的 <strong>子序列</strong> 指的是删除原数组的某些元素（可能一个元素都不删除），同时不改变其余元素的相对顺序得到的数组。比方说，<code>[2,7,4]</code> 是 <code>[4,<strong>2</strong>,3,<strong>7</strong>,2,1,<strong>4</strong>]</code> 的子序列（加粗元素），但 <code>[2,4,2]</code> 不是子序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>target = [5,1,3], <code>arr</code> = [9,4,2,3,4]
<b>输出：</b>2
<b>解释：</b>你可以添加 5 和 1 ，使得 arr 变为 [<strong>5</strong>,9,4,<strong>1</strong>,2,3,4] ，target 为 arr 的子序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>target = [6,4,8,1,3,2], <code>arr</code> = [4,7,6,2,3,8,6,1]
<b>输出：</b>3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= target.length, arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= target[i], arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>target</code> 不包含任何重复元素。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：最长递增子序列 + 树状数组

根据题意，`target` 和 `arr` 这两个数组的公共子序列越长，需要添加的元素就越少。因此，最少添加的元素个数等于 `target` 的长度减去 `target` 和 `arr` 的最长公共子序列的长度。

但是，[求最长公共子序列](https://github.com/doocs/leetcode/blob/main/solution/1100-1199/1143.Longest%20Common%20Subsequence/README.md)的时间复杂度为 $O(m \times n)$，无法通过本题，需要转变思路。

我们可以用一个哈希表记录 `target` 数组中每个元素的下标，然后遍历 `arr` 数组，对于 `arr` 数组中的每个元素，如果哈希表中存在该元素，则将该元素的下标加入到一个数组中，这样就得到了一个新的数组 `nums`，该数组是 `arr` 中的元素在 `target` 数组中的下标（去掉了不在 `target` 中的元素），该数组的最长递增子序列的长度就是 `target` 和 `arr` 的最长公共子序列的长度。

因此，问题转化为求 `nums` 数组的最长递增子序列的长度。参考 [300. 最长递增子序列](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0300.Longest%20Increasing%20Subsequence/README.md)。

时间复杂度 $O(n \times \log m)$，空间复杂度 $O(m)$。其中 $m$ 和 $n$ 分别为 `target` 和 `arr` 的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] = max(self.c[x], v)
            x += x & -x

    def query(self, x: int) -> int:
        res = 0
        while x:
            res = max(res, self.c[x])
            x -= x & -x
        return res


class Solution:
    def minOperations(self, target: List[int], arr: List[int]) -> int:
        d = {x: i for i, x in enumerate(target, 1)}
        nums = [d[x] for x in arr if x in d]
        m = len(target)
        tree = BinaryIndexedTree(m)
        ans = 0
        for x in nums:
            v = tree.query(x - 1) + 1
            ans = max(ans, v)
            tree.update(x, v)
        return len(target) - ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] = Math.max(c[x], v);
        }
    }

    public int query(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) {
            ans = Math.max(ans, c[x]);
        }
        return ans;
    }
}

class Solution {
    public int minOperations(int[] target, int[] arr) {
        int m = target.length;
        Map<Integer, Integer> d = new HashMap<>(m);
        for (int i = 0; i < m; i++) {
            d.put(target[i], i + 1);
        }
        List<Integer> nums = new ArrayList<>();
        for (int x : arr) {
            if (d.containsKey(x)) {
                nums.add(d.get(x));
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        int ans = 0;
        for (int x : nums) {
            int v = tree.query(x - 1) + 1;
            ans = Math.max(ans, v);
            tree.update(x, v);
        }
        return m - ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int v) {
        for (; x <= n; x += x & -x) {
            c[x] = max(c[x], v);
        }
    }

    int query(int x) {
        int ans = 0;
        for (; x > 0; x -= x & -x) {
            ans = max(ans, c[x]);
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = target.size();
        unordered_map<int, int> d;
        for (int i = 0; i < m; ++i) {
            d[target[i]] = i + 1;
        }
        vector<int> nums;
        for (int x : arr) {
            if (d.contains(x)) {
                nums.push_back(d[x]);
            }
        }
        BinaryIndexedTree tree(m);
        int ans = 0;
        for (int x : nums) {
            int v = tree.query(x - 1) + 1;
            ans = max(ans, v);
            tree.update(x, v);
        }
        return m - ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) BinaryIndexedTree {
	return BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) Update(x, v int) {
	for ; x <= bit.n; x += x & -x {
		if v > bit.c[x] {
			bit.c[x] = v
		}
	}
}

func (bit *BinaryIndexedTree) Query(x int) int {
	ans := 0
	for ; x > 0; x -= x & -x {
		if bit.c[x] > ans {
			ans = bit.c[x]
		}
	}
	return ans
}

func minOperations(target []int, arr []int) int {
	m := len(target)
	d := make(map[int]int)
	for i, x := range target {
		d[x] = i + 1
	}
	var nums []int
	for _, x := range arr {
		if pos, exists := d[x]; exists {
			nums = append(nums, pos)
		}
	}
	tree := NewBinaryIndexedTree(m)
	ans := 0
	for _, x := range nums {
		v := tree.Query(x-1) + 1
		if v > ans {
			ans = v
		}
		tree.Update(x, v)
	}
	return m - ans
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] = Math.max(this.c[x], v);
        }
    }

    query(x: number): number {
        let ans = 0;
        for (; x > 0; x -= x & -x) {
            ans = Math.max(ans, this.c[x]);
        }
        return ans;
    }
}

function minOperations(target: number[], arr: number[]): number {
    const m = target.length;
    const d: Map<number, number> = new Map();
    target.forEach((x, i) => d.set(x, i + 1));
    const nums: number[] = [];
    arr.forEach(x => {
        if (d.has(x)) {
            nums.push(d.get(x)!);
        }
    });
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    nums.forEach(x => {
        const v = tree.query(x - 1) + 1;
        ans = Math.max(ans, v);
        tree.update(x, v);
    });
    return m - ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1714. 数组中特殊等间距元素的和 🔒](https://leetcode.cn/problems/sum-of-special-evenly-spaced-elements-in-array){#1714}

{{< tabs "1714" >}}

{{% tab "python" %}}
```python
class Solution:
    def solve(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7
        n = len(nums)
        m = int(sqrt(n))
        suf = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(n - 1, -1, -1):
                suf[i][j] = suf[i][min(n, j + i)] + nums[j]
        ans = []
        for x, y in queries:
            if y <= m:
                ans.append(suf[y][x] % mod)
            else:
                ans.append(sum(nums[x::y]) % mod)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] solve(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = (int) Math.sqrt(n);
        final int mod = (int) 1e9 + 7;
        int[][] suf = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                suf[i][j] = (suf[i][Math.min(n, j + i)] + nums[j]) % mod;
            }
        }
        int k = queries.length;
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (y <= m) {
                ans[i] = suf[y][x];
            } else {
                int s = 0;
                for (int j = x; j < n; j += y) {
                    s = (s + nums[j]) % mod;
                }
                ans[i] = s;
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
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = (int) sqrt(n);
        const int mod = 1e9 + 7;
        int suf[m + 1][n + 1];
        memset(suf, 0, sizeof(suf));
        for (int i = 1; i <= m; ++i) {
            for (int j = n - 1; ~j; --j) {
                suf[i][j] = (suf[i][min(n, j + i)] + nums[j]) % mod;
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            if (y <= m) {
                ans.push_back(suf[y][x]);
            } else {
                int s = 0;
                for (int i = x; i < n; i += y) {
                    s = (s + nums[i]) % mod;
                }
                ans.push_back(s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func solve(nums []int, queries [][]int) (ans []int) {
	n := len(nums)
	m := int(math.Sqrt(float64(n)))
	const mod int = 1e9 + 7
	suf := make([][]int, m+1)
	for i := range suf {
		suf[i] = make([]int, n+1)
		for j := n - 1; j >= 0; j-- {
			suf[i][j] = (suf[i][min(n, j+i)] + nums[j]) % mod
		}
	}
	for _, q := range queries {
		x, y := q[0], q[1]
		if y <= m {
			ans = append(ans, suf[y][x])
		} else {
			s := 0
			for i := x; i < n; i += y {
				s = (s + nums[i]) % mod
			}
			ans = append(ans, s)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function solve(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const m = Math.floor(Math.sqrt(n));
    const mod = 10 ** 9 + 7;
    const suf: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = n - 1; j >= 0; --j) {
            suf[i][j] = (suf[i][Math.min(n, j + i)] + nums[j]) % mod;
        }
    }
    const ans: number[] = [];
    for (const [x, y] of queries) {
        if (y <= m) {
            ans.push(suf[y][x]);
        } else {
            let s = 0;
            for (let i = x; i < n; i += y) {
                s = (s + nums[i]) % mod;
            }
            ans.push(s);
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

<p>给定一个<strong>索引从 0 开始</strong>的整数类型数组 <code>nums</code> ，包含 <code>n</code> 个非负整数。</p>

<p>另外给定一个（包含查询指令的）数组 <code>queries</code> ，其中 <code>queries[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>。 第 <code>i</code> 个查询指令的答案是 <code>nums[j]</code> 中满足该条件的所有元素的和： <code>x<sub>i</sub> &lt;= j &lt; n</code> 且 <code>(j - x<sub>i</sub>)</code> 能被 <code>y<sub>i</sub></code> 整除。</p>

<p>返回一个数组<em> </em><code>answer</code>，其中<em>  </em><code>answer.length == queries.length</code> 且 <code>answer[i]</code> 是第 <code>i</code> 个查询指令的答案对 <code>10<sup>9 </sup>+ 7</code> 取模。</p>

<p> </p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> nums = [0,1,2,3,4,5,6,7], queries = [[0,3],[5,1],[4,2]]
<strong>输出:</strong> [9,18,10]
<strong>解释:</strong> 每次查询的答案如下：
1) 符合查询条件的索引 j 有 0、 3 和 6。 nums[0] + nums[3] + nums[6] = 9
2) 符合查询条件的索引 j 有 5、 6 和 7。 nums[5] + nums[6] + nums[7] = 18
3) 符合查询条件的索引 j 有 4 和 6。 nums[4] + nums[6] = 10
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> nums = [100,200,101,201,102,202,103,203], queries = [[0,7]]
<strong>输出:</strong> [303]
</pre>

<p> </p>

<p><b>提示：</b></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 1.5 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= x<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= y<sub>i</sub> &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分块

这道题是一道比较典型的分块题目，对于步长较大的查询，我们可以直接暴力求解；对于步长较小的查询，我们可以预处理出每个位置的后缀和，然后直接查询。

本题中，我们将步长较大的查询的步长限制为 $\sqrt{n}$，这样就可以保证每个查询的时间复杂度为 $O(\sqrt{n})$。

我们定义一个二维数组 $suf$，其中 $suf[i][j]$ be 表示从位置 $j$ 开始，步长为 $i$ 的后缀和。那么对于每个查询 $[x, y]$，我们可以分为两种情况：

-   如果 $y \le \sqrt{n}$，那么我们可以直接查询 $suf[y][x]$；
-   如果 $y \gt \sqrt{n}$，那么我们可以直接暴力求解。

时间复杂度 $O((n +  m) \times \sqrt{n})$，空间复杂度 $O(n \times \sqrt{n})$。其中 $n$ 是数组的长度，而 $m$ 是查询的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def solve(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        mod = 10**9 + 7
        n = len(nums)
        m = int(sqrt(n))
        suf = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(n - 1, -1, -1):
                suf[i][j] = suf[i][min(n, j + i)] + nums[j]
        ans = []
        for x, y in queries:
            if y <= m:
                ans.append(suf[y][x] % mod)
            else:
                ans.append(sum(nums[x::y]) % mod)
        return ans
```

#### Java

```java
class Solution {
    public int[] solve(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = (int) Math.sqrt(n);
        final int mod = (int) 1e9 + 7;
        int[][] suf = new int[m + 1][n + 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                suf[i][j] = (suf[i][Math.min(n, j + i)] + nums[j]) % mod;
            }
        }
        int k = queries.length;
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (y <= m) {
                ans[i] = suf[y][x];
            } else {
                int s = 0;
                for (int j = x; j < n; j += y) {
                    s = (s + nums[j]) % mod;
                }
                ans[i] = s;
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
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = (int) sqrt(n);
        const int mod = 1e9 + 7;
        int suf[m + 1][n + 1];
        memset(suf, 0, sizeof(suf));
        for (int i = 1; i <= m; ++i) {
            for (int j = n - 1; ~j; --j) {
                suf[i][j] = (suf[i][min(n, j + i)] + nums[j]) % mod;
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            if (y <= m) {
                ans.push_back(suf[y][x]);
            } else {
                int s = 0;
                for (int i = x; i < n; i += y) {
                    s = (s + nums[i]) % mod;
                }
                ans.push_back(s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func solve(nums []int, queries [][]int) (ans []int) {
	n := len(nums)
	m := int(math.Sqrt(float64(n)))
	const mod int = 1e9 + 7
	suf := make([][]int, m+1)
	for i := range suf {
		suf[i] = make([]int, n+1)
		for j := n - 1; j >= 0; j-- {
			suf[i][j] = (suf[i][min(n, j+i)] + nums[j]) % mod
		}
	}
	for _, q := range queries {
		x, y := q[0], q[1]
		if y <= m {
			ans = append(ans, suf[y][x])
		} else {
			s := 0
			for i := x; i < n; i += y {
				s = (s + nums[i]) % mod
			}
			ans = append(ans, s)
		}
	}
	return
}
```

#### TypeScript

```ts
function solve(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    const m = Math.floor(Math.sqrt(n));
    const mod = 10 ** 9 + 7;
    const suf: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    for (let i = 1; i <= m; ++i) {
        for (let j = n - 1; j >= 0; --j) {
            suf[i][j] = (suf[i][Math.min(n, j + i)] + nums[j]) % mod;
        }
    }
    const ans: number[] = [];
    for (const [x, y] of queries) {
        if (y <= m) {
            ans.push(suf[y][x]);
        } else {
            let s = 0;
            for (let i = x; i < n; i += y) {
                s = (s + nums[i]) % mod;
            }
            ans.push(s);
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

# [1715. 苹果和橘子的个数 🔒](https://leetcode.cn/problems/count-apples-and-oranges){#1715}

{{< tabs "1715" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    SUM(IFNULL(b.apple_count, 0) + IFNULL(c.apple_count, 0)) AS apple_count,
    SUM(IFNULL(b.orange_count, 0) + IFNULL(c.orange_count, 0)) AS orange_count
FROM
    Boxes AS b
    LEFT JOIN Chests AS c USING (chest_id);
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def count_apples_and_oranges(boxes: pd.DataFrame, chests: pd.DataFrame) -> pd.DataFrame:
    merged_df = boxes.merge(
        chests, on="chest_id", how="left", suffixes=("_box", "_chest")
    )
    apple_count = (
        merged_df["apple_count_box"].fillna(0)
        + merged_df["apple_count_chest"].fillna(0)
    ).sum()
    orange_count = (
        merged_df["orange_count_box"].fillna(0)
        + merged_df["orange_count_chest"].fillna(0)
    ).sum()
    return pd.DataFrame({"apple_count": [apple_count], "orange_count": [orange_count]})
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Boxes</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| box_id       | int  |
| chest_id     | int  |
| apple_count  | int  |
| orange_count | int  |
+--------------+------+
box_id 是该表的主键。
chest_id 是 chests 表的外键。
该表包含大箱子 (box) 中包含的苹果和橘子的个数。每个大箱子中可能包含一个小盒子 (chest) ，小盒子中也包含若干苹果和橘子。</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Chests</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| chest_id     | int  |
| apple_count  | int  |
| orange_count | int  |
+--------------+------+
chest_id 是该表的主键。
该表包含小盒子的信息，以及小盒子中包含的苹果和橘子的个数。</pre>

<p>&nbsp;</p>

<p>编写 SQL 语句，查询每个大箱子中苹果和橘子的个数。如果大箱子中包含小盒子，还应当包含小盒子中苹果和橘子的个数。</p>

<p>以任意顺序返回结果表。</p>

<p>查询结果的格式如下示例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<strong>输入：</strong>
Boxes 表：
+--------+----------+-------------+--------------+
| box_id | chest_id | apple_count | orange_count |
+--------+----------+-------------+--------------+
| 2      | null     | 6           | 15           |
| 18     | 14       | 4           | 15           |
| 19     | 3        | 8           | 4            |
| 12     | 2        | 19          | 20           |
| 20     | 6        | 12          | 9            |
| 8      | 6        | 9           | 9            |
| 3      | 14       | 16          | 7            |
+--------+----------+-------------+--------------+
Chests 表：
+----------+-------------+--------------+
| chest_id | apple_count | orange_count |
+----------+-------------+--------------+
| 6        | 5           | 6            |
| 14       | 20          | 10           |
| 2        | 8           | 8            |
| 3        | 19          | 4            |
| 16       | 19          | 19           |
+----------+-------------+--------------+
<strong>输出：</strong>
+-------------+--------------+
| apple_count | orange_count |
+-------------+--------------+
| 151         | 123          |
+-------------+--------------+
<strong>解释：</strong>
大箱子 2 中有 6 个苹果和 15 个橘子。
大箱子 18 中有 4 + 20 (在小盒子中) = 24 个苹果和 15 + 10 (在小盒子中) = 25 个橘子。
大箱子 19 中有 8 + 19 (在小盒子中) = 27 个苹果和 4 + 4 (在小盒子中) = 8 个橘子。
大箱子 12 中有 19 + 8 (在小盒子中) = 27 个苹果和 20 + 8 (在小盒子中) = 28 个橘子。
大箱子 20 中有 12 + 5 (在小盒子中) = 17 个苹果和 9 + 6 (在小盒子中) = 15 个橘子。
大箱子 8 中有 9 + 5 (在小盒子中) = 14 个苹果和 9 + 6 (在小盒子中) = 15 个橘子。
大箱子 3 中有 16 + 20 (在小盒子中) = 36 个苹果和 7 + 10 (在小盒子中) = 17 个橘子。
苹果的总个数 = 6 + 24 + 27 + 27 + 17 + 14 + 36 = 151
橘子的总个数 = 15 + 25 + 8 + 28 + 15 + 15 + 17 = 123</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 求和

我们可以将 `Boxes` 表和 `Chests` 表按照 `chest_id` 进行左连接，然后分别求出苹果和橘子的总个数。注意，如果某个箱子中没有小盒子，那么对应的 `chest_id` 为 `null`，此时我们需要认为该箱子中的小盒子中苹果和橘子的个数为 0。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    SUM(IFNULL(b.apple_count, 0) + IFNULL(c.apple_count, 0)) AS apple_count,
    SUM(IFNULL(b.orange_count, 0) + IFNULL(c.orange_count, 0)) AS orange_count
FROM
    Boxes AS b
    LEFT JOIN Chests AS c USING (chest_id);
```

#### Pandas

```python
import pandas as pd


def count_apples_and_oranges(boxes: pd.DataFrame, chests: pd.DataFrame) -> pd.DataFrame:
    merged_df = boxes.merge(
        chests, on="chest_id", how="left", suffixes=("_box", "_chest")
    )
    apple_count = (
        merged_df["apple_count_box"].fillna(0)
        + merged_df["apple_count_chest"].fillna(0)
    ).sum()
    orange_count = (
        merged_df["orange_count_box"].fillna(0)
        + merged_df["orange_count_chest"].fillna(0)
    ).sum()
    return pd.DataFrame({"apple_count": [apple_count], "orange_count": [orange_count]})
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1716. 计算力扣银行的钱](https://leetcode.cn/problems/calculate-money-in-leetcode-bank){#1716}

{{< tabs "1716" >}}

{{% tab "python" %}}
```python
class Solution:
    def totalMoney(self, n: int) -> int:
        a, b = divmod(n, 7)
        return (28 + 28 + 7 * (a - 1)) * a // 2 + (a * 2 + b + 1) * b // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalMoney(n int) int {
	a, b := n/7, n%7
	return (28+28+7*(a-1))*a/2 + (a*2+b+1)*b/2
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Hercy 想要为购买第一辆车存钱。他 <strong>每天</strong> 都往力扣银行里存钱。</p>

<p>最开始，他在周一的时候存入 <code>1</code> 块钱。从周二到周日，他每天都比前一天多存入 <code>1</code> 块钱。在接下来每一个周一，他都会比 <strong>前一个周一</strong> 多存入 <code>1</code> 块钱。<span style=""> </span></p>

<p>给你 <code>n</code> ，请你返回在第 <code>n</code> 天结束的时候他在力扣银行总共存了多少块钱。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 4
<b>输出：</b>10
<b>解释：</b>第 4 天后，总额为 1 + 2 + 3 + 4 = 10 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 10
<b>输出：</b>37
<b>解释：</b>第 10 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37 。注意到第二个星期一，Hercy 存入 2 块钱。
</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>n = 20
<b>输出：</b>96
<b>解释：</b>第 20 天后，总额为 (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96 。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
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
    def totalMoney(self, n: int) -> int:
        a, b = divmod(n, 7)
        return (28 + 28 + 7 * (a - 1)) * a // 2 + (a * 2 + b + 1) * b // 2
```

#### Java

```java
class Solution {
    public int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int totalMoney(int n) {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
};
```

#### Go

```go
func totalMoney(n int) int {
	a, b := n/7, n%7
	return (28+28+7*(a-1))*a/2 + (a*2+b+1)*b/2
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1717. 删除子字符串的最大得分](https://leetcode.cn/problems/maximum-score-from-removing-substrings){#1717}

{{< tabs "1717" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        a, b = "a", "b"
        if x < y:
            x, y = y, x
            a, b = b, a
        ans = cnt1 = cnt2 = 0
        for c in s:
            if c == a:
                cnt1 += 1
            elif c == b:
                if cnt1:
                    ans += x
                    cnt1 -= 1
                else:
                    cnt2 += 1
            else:
                ans += min(cnt1, cnt2) * y
                cnt1 = cnt2 = 0
        ans += min(cnt1, cnt2) * y
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumGain(String s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            int t = x;
            x = y;
            y = t;
            char c = a;
            a = b;
            b = c;
        }
        int ans = 0, cnt1 = 0, cnt2 = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == a) {
                cnt1++;
            } else if (c == b) {
                if (cnt1 > 0) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += Math.min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += Math.min(cnt1, cnt2) * y;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }

        int ans = 0, cnt1 = 0, cnt2 = 0;
        for (char c : s) {
            if (c == a) {
                cnt1++;
            } else if (c == b) {
                if (cnt1) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += min(cnt1, cnt2) * y;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumGain(s string, x int, y int) (ans int) {
	a, b := 'a', 'b'
	if x < y {
		x, y = y, x
		a, b = b, a
	}

	var cnt1, cnt2 int
	for _, c := range s {
		if c == a {
			cnt1++
		} else if c == b {
			if cnt1 > 0 {
				ans += x
				cnt1--
			} else {
				cnt2++
			}
		} else {
			ans += min(cnt1, cnt2) * y
			cnt1, cnt2 = 0, 0
		}
	}
	ans += min(cnt1, cnt2) * y
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumGain(s: string, x: number, y: number): number {
    let [a, b] = ['a', 'b'];
    if (x < y) {
        [x, y] = [y, x];
        [a, b] = [b, a];
    }

    let [ans, cnt1, cnt2] = [0, 0, 0];
    for (let c of s) {
        if (c === a) {
            cnt1++;
        } else if (c === b) {
            if (cnt1) {
                ans += x;
                cnt1--;
            } else {
                cnt2++;
            }
        } else {
            ans += Math.min(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    ans += Math.min(cnt1, cnt2) * y;
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn maximum_gain(s: String, mut x: i32, mut y: i32) -> i32 {
        let (mut a, mut b) = ('a', 'b');
        if x < y {
            std::mem::swap(&mut x, &mut y);
            std::mem::swap(&mut a, &mut b);
        }

        let mut ans = 0;
        let mut cnt1 = 0;
        let mut cnt2 = 0;

        for c in s.chars() {
            if c == a {
                cnt1 += 1;
            } else if c == b {
                if cnt1 > 0 {
                    ans += x;
                    cnt1 -= 1;
                } else {
                    cnt2 += 1;
                }
            } else {
                ans += cnt1.min(cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        ans += cnt1.min(cnt2) * y;
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function maximumGain(s, x, y) {
    let [a, b] = ['a', 'b'];
    if (x < y) {
        [x, y] = [y, x];
        [a, b] = [b, a];
    }

    let [ans, cnt1, cnt2] = [0, 0, 0];
    for (let c of s) {
        if (c === a) {
            cnt1++;
        } else if (c === b) {
            if (cnt1) {
                ans += x;
                cnt1--;
            } else {
                cnt2++;
            }
        } else {
            ans += Math.min(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    ans += Math.min(cnt1, cnt2) * y;
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            (x, y) = (y, x);
            (a, b) = (b, a);
        }

        int ans = 0, cnt1 = 0, cnt2 = 0;
        foreach (char c in s) {
            if (c == a) {
                cnt1++;
            } else if (c == b) {
                if (cnt1 > 0) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += Math.Min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        ans += Math.Min(cnt1, cnt2) * y;
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

<p>给你一个字符串 <code>s</code> 和两个整数 <code>x</code> 和 <code>y</code> 。你可以执行下面两种操作任意次。</p>

<ul>
	<li>删除子字符串 <code>"ab"</code> 并得到 <code>x</code> 分。

    <ul>
    	<li>比方说，从 <code>"c<strong>ab</strong>xbae"</code> 删除 <code>ab</code> ，得到 <code>"cxbae"</code> 。</li>
    </ul>
    </li>
    <li>删除子字符串<code>"ba"</code> 并得到 <code>y</code> 分。
    <ul>
    	<li>比方说，从 <code>"cabx<strong>ba</strong>e"</code> 删除 <code>ba</code> ，得到 <code>"cabxe"</code> 。</li>
    </ul>
    </li>

</ul>

<p>请返回对 <code>s</code> 字符串执行上面操作若干次能得到的最大得分。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "cdbcbbaaabab", x = 4, y = 5
<b>输出：</b>19
<strong>解释：</strong>
- 删除 "cdbcbbaaa<strong>ba</strong>b" 中加粗的 "ba" ，得到 s = "cdbcbbaaab" ，加 5 分。
- 删除 "cdbcbbaa<strong>ab</strong>" 中加粗的 "ab" ，得到 s = "cdbcbbaa" ，加 4 分。
- 删除 "cdbcb<strong>ba</strong>a" 中加粗的 "ba" ，得到 s = "cdbcba" ，加 5 分。
- 删除 "cdbc<strong>ba</strong>" 中加粗的 "ba" ，得到 s = "cdbc" ，加 5 分。
总得分为 5 + 4 + 5 + 5 = 19 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "aabbaaxybbaabb", x = 5, y = 4
<b>输出：</b>20
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= x, y &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们不妨假设子字符串 "ab" 的得分总是不低于子字符串 "ba" 的得分，如果不是，我们可以交换 "a" 和 "b"，同时交换 $x$ 和 $y$。

接下来，我们只需要考虑字符串中只包含 "a" 和 "b" 的情况。如果字符串中包含其他字符，我们可以将其视为一个分割点，将字符串分割成若干个只包含 "a" 和 "b" 的子字符串，然后分别计算每个子字符串的得分。

我们观察发现，对于一个只包含 "a" 和 "b" 的子字符串，无论采取什么样的操作，最后一定只剩下一种字符，或者空串。由于每次操作都会同时删除一个 "a" 和一个 "b"，因此总的操作次数一定是固定的。我们可以贪心地先删除 "ab"，再删除 "ba"，这样可以保证得分最大。

因此，我们可以使用两个变量 $\textit{cnt1}$ 和 $\textit{cnt2}$ 分别记录 "a" 和 "b" 的数量，然后遍历字符串，根据当前字符的不同情况更新 $\textit{cnt1}$ 和 $\textit{cnt2}$，并计算得分。

对于当前遍历到的字符 $c$：

-   如果 $c$ 是 "a"，由于要先删除 "ab"，因此此时我们不消除该字符，只增加 $\textit{cnt1}$；
-   如果 $c$ 是 "b"，如果此时 $\textit{cnt1} > 0$，我们可以消除一个 "ab"，并增加 $x$ 分，否则我们只能增加 $\textit{cnt2}$；
-   如果 $c$ 是其他字符，那么对于该子字符串，我们剩下了 $\textit{cnt2}$ 个 "b" 和 $\textit{cnt1}$ 个 "a"，我们可以消除 $\min(\textit{cnt1}, \textit{cnt2})$ 个 "ba"，并增加若干个 $y$ 分。

遍历结束后，我们还需要额外处理一下剩余的 "ba"，增加若干个 $y$ 分。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        a, b = "a", "b"
        if x < y:
            x, y = y, x
            a, b = b, a
        ans = cnt1 = cnt2 = 0
        for c in s:
            if c == a:
                cnt1 += 1
            elif c == b:
                if cnt1:
                    ans += x
                    cnt1 -= 1
                else:
                    cnt2 += 1
            else:
                ans += min(cnt1, cnt2) * y
                cnt1 = cnt2 = 0
        ans += min(cnt1, cnt2) * y
        return ans
```

#### Java

```java
class Solution {
    public int maximumGain(String s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            int t = x;
            x = y;
            y = t;
            char c = a;
            a = b;
            b = c;
        }
        int ans = 0, cnt1 = 0, cnt2 = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == a) {
                cnt1++;
            } else if (c == b) {
                if (cnt1 > 0) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += Math.min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += Math.min(cnt1, cnt2) * y;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }

        int ans = 0, cnt1 = 0, cnt2 = 0;
        for (char c : s) {
            if (c == a) {
                cnt1++;
            } else if (c == b) {
                if (cnt1) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += min(cnt1, cnt2) * y;
        return ans;
    }
};
```

#### Go

```go
func maximumGain(s string, x int, y int) (ans int) {
	a, b := 'a', 'b'
	if x < y {
		x, y = y, x
		a, b = b, a
	}

	var cnt1, cnt2 int
	for _, c := range s {
		if c == a {
			cnt1++
		} else if c == b {
			if cnt1 > 0 {
				ans += x
				cnt1--
			} else {
				cnt2++
			}
		} else {
			ans += min(cnt1, cnt2) * y
			cnt1, cnt2 = 0, 0
		}
	}
	ans += min(cnt1, cnt2) * y
	return
}
```

#### TypeScript

```ts
function maximumGain(s: string, x: number, y: number): number {
    let [a, b] = ['a', 'b'];
    if (x < y) {
        [x, y] = [y, x];
        [a, b] = [b, a];
    }

    let [ans, cnt1, cnt2] = [0, 0, 0];
    for (let c of s) {
        if (c === a) {
            cnt1++;
        } else if (c === b) {
            if (cnt1) {
                ans += x;
                cnt1--;
            } else {
                cnt2++;
            }
        } else {
            ans += Math.min(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    ans += Math.min(cnt1, cnt2) * y;
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn maximum_gain(s: String, mut x: i32, mut y: i32) -> i32 {
        let (mut a, mut b) = ('a', 'b');
        if x < y {
            std::mem::swap(&mut x, &mut y);
            std::mem::swap(&mut a, &mut b);
        }

        let mut ans = 0;
        let mut cnt1 = 0;
        let mut cnt2 = 0;

        for c in s.chars() {
            if c == a {
                cnt1 += 1;
            } else if c == b {
                if cnt1 > 0 {
                    ans += x;
                    cnt1 -= 1;
                } else {
                    cnt2 += 1;
                }
            } else {
                ans += cnt1.min(cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        ans += cnt1.min(cnt2) * y;
        ans
    }
}
```

#### JavaScript

```js
function maximumGain(s, x, y) {
    let [a, b] = ['a', 'b'];
    if (x < y) {
        [x, y] = [y, x];
        [a, b] = [b, a];
    }

    let [ans, cnt1, cnt2] = [0, 0, 0];
    for (let c of s) {
        if (c === a) {
            cnt1++;
        } else if (c === b) {
            if (cnt1) {
                ans += x;
                cnt1--;
            } else {
                cnt2++;
            }
        } else {
            ans += Math.min(cnt1, cnt2) * y;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    ans += Math.min(cnt1, cnt2) * y;
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int MaximumGain(string s, int x, int y) {
        char a = 'a', b = 'b';
        if (x < y) {
            (x, y) = (y, x);
            (a, b) = (b, a);
        }

        int ans = 0, cnt1 = 0, cnt2 = 0;
        foreach (char c in s) {
            if (c == a) {
                cnt1++;
            } else if (c == b) {
                if (cnt1 > 0) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += Math.Min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        ans += Math.Min(cnt1, cnt2) * y;
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1718. 构建字典序最大的可行序列](https://leetcode.cn/problems/construct-the-lexicographically-largest-valid-sequence){#1718}

{{< tabs "1718" >}}

{{% tab "python" %}}
```python
class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        def dfs(u):
            if u == n * 2:
                return True
            if path[u]:
                return dfs(u + 1)
            for i in range(n, 1, -1):
                if cnt[i] and u + i < n * 2 and path[u + i] == 0:
                    cnt[i] = 0
                    path[u] = path[u + i] = i
                    if dfs(u + 1):
                        return True
                    path[u] = path[u + i] = 0
                    cnt[i] = 2
            if cnt[1]:
                cnt[1], path[u] = 0, 1
                if dfs(u + 1):
                    return True
                path[u], cnt[1] = 0, 1
            return False

        path = [0] * (n * 2)
        cnt = [2] * (n * 2)
        cnt[1] = 1
        dfs(1)
        return path[1:]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] path;
    private int[] cnt;
    private int n;

    public int[] constructDistancedSequence(int n) {
        this.n = n;
        path = new int[n * 2];
        cnt = new int[n * 2];
        Arrays.fill(cnt, 2);
        cnt[1] = 1;
        dfs(1);
        int[] ans = new int[n * 2 - 1];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = path[i + 1];
        }
        return ans;
    }

    private boolean dfs(int u) {
        if (u == n * 2) {
            return true;
        }
        if (path[u] > 0) {
            return dfs(u + 1);
        }
        for (int i = n; i > 1; --i) {
            if (cnt[i] > 0 && u + i < n * 2 && path[u + i] == 0) {
                cnt[i] = 0;
                path[u] = i;
                path[u + i] = i;
                if (dfs(u + 1)) {
                    return true;
                }
                cnt[i] = 2;
                path[u] = 0;
                path[u + i] = 0;
            }
        }
        if (cnt[1] > 0) {
            path[u] = 1;
            cnt[1] = 0;
            if (dfs(u + 1)) {
                return true;
            }
            cnt[1] = 1;
            path[u] = 0;
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
    int n;
    vector<int> cnt, path;

    vector<int> constructDistancedSequence(int _n) {
        n = _n;
        cnt.resize(n * 2, 2);
        path.resize(n * 2);
        cnt[1] = 1;
        dfs(1);
        vector<int> ans;
        for (int i = 1; i < n * 2; ++i) ans.push_back(path[i]);
        return ans;
    }

    bool dfs(int u) {
        if (u == n * 2) return 1;
        if (path[u]) return dfs(u + 1);
        for (int i = n; i > 1; --i) {
            if (cnt[i] && u + i < n * 2 && !path[u + i]) {
                path[u] = path[u + i] = i;
                cnt[i] = 0;
                if (dfs(u + 1)) return 1;
                cnt[i] = 2;
                path[u] = path[u + i] = 0;
            }
        }
        if (cnt[1]) {
            path[u] = 1;
            cnt[1] = 0;
            if (dfs(u + 1)) return 1;
            cnt[1] = 1;
            path[u] = 0;
        }
        return 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func constructDistancedSequence(n int) []int {
	path := make([]int, n*2)
	cnt := make([]int, n*2)
	for i := range cnt {
		cnt[i] = 2
	}
	cnt[1] = 1
	var dfs func(u int) bool
	dfs = func(u int) bool {
		if u == n*2 {
			return true
		}
		if path[u] > 0 {
			return dfs(u + 1)
		}
		for i := n; i > 1; i-- {
			if cnt[i] > 0 && u+i < n*2 && path[u+i] == 0 {
				cnt[i] = 0
				path[u], path[u+i] = i, i
				if dfs(u + 1) {
					return true
				}
				cnt[i] = 2
				path[u], path[u+i] = 0, 0
			}
		}
		if cnt[1] > 0 {
			cnt[1] = 0
			path[u] = 1
			if dfs(u + 1) {
				return true
			}
			cnt[1] = 1
			path[u] = 0
		}
		return false
	}
	dfs(1)
	return path[1:]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数 <code>n</code> ，请你找到满足下面条件的一个序列：</p>

<ul>
	<li>整数 <code>1</code> 在序列中只出现一次。</li>
	<li><code>2</code> 到 <code>n</code> 之间每个整数都恰好出现两次。</li>
	<li>对于每个 <code>2</code> 到 <code>n</code> 之间的整数 <code>i</code> ，两个 <code>i</code> 之间出现的距离恰好为 <code>i</code> 。</li>
</ul>

<p>序列里面两个数 <code>a[i]</code> 和 <code>a[j]</code> 之间的 <strong>距离</strong> ，我们定义为它们下标绝对值之差 <code>|j - i|</code> 。</p>

<p>请你返回满足上述条件中 <strong>字典序最大</strong> 的序列。题目保证在给定限制条件下，一定存在解。</p>

<p>一个序列 <code>a</code> 被认为比序列 <code>b</code> （两者长度相同）字典序更大的条件是： <code>a</code> 和 <code>b</code> 中第一个不一样的数字处，<code>a</code> 序列的数字比 <code>b</code> 序列的数字大。比方说，<code>[0,1,9,0]</code> 比 <code>[0,1,5,6]</code> 字典序更大，因为第一个不同的位置是第三个数字，且 <code>9</code> 比 <code>5</code> 大。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 3
<b>输出：</b>[3,1,2,3,2]
<b>解释：</b>[2,3,2,1,3] 也是一个可行的序列，但是 [3,1,2,3,2] 是字典序最大的序列。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 5
<b>输出：</b>[5,3,1,4,3,5,2,4,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 20</code></li>
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
    def constructDistancedSequence(self, n: int) -> List[int]:
        def dfs(u):
            if u == n * 2:
                return True
            if path[u]:
                return dfs(u + 1)
            for i in range(n, 1, -1):
                if cnt[i] and u + i < n * 2 and path[u + i] == 0:
                    cnt[i] = 0
                    path[u] = path[u + i] = i
                    if dfs(u + 1):
                        return True
                    path[u] = path[u + i] = 0
                    cnt[i] = 2
            if cnt[1]:
                cnt[1], path[u] = 0, 1
                if dfs(u + 1):
                    return True
                path[u], cnt[1] = 0, 1
            return False

        path = [0] * (n * 2)
        cnt = [2] * (n * 2)
        cnt[1] = 1
        dfs(1)
        return path[1:]
```

#### Java

```java
class Solution {
    private int[] path;
    private int[] cnt;
    private int n;

    public int[] constructDistancedSequence(int n) {
        this.n = n;
        path = new int[n * 2];
        cnt = new int[n * 2];
        Arrays.fill(cnt, 2);
        cnt[1] = 1;
        dfs(1);
        int[] ans = new int[n * 2 - 1];
        for (int i = 0; i < ans.length; ++i) {
            ans[i] = path[i + 1];
        }
        return ans;
    }

    private boolean dfs(int u) {
        if (u == n * 2) {
            return true;
        }
        if (path[u] > 0) {
            return dfs(u + 1);
        }
        for (int i = n; i > 1; --i) {
            if (cnt[i] > 0 && u + i < n * 2 && path[u + i] == 0) {
                cnt[i] = 0;
                path[u] = i;
                path[u + i] = i;
                if (dfs(u + 1)) {
                    return true;
                }
                cnt[i] = 2;
                path[u] = 0;
                path[u + i] = 0;
            }
        }
        if (cnt[1] > 0) {
            path[u] = 1;
            cnt[1] = 0;
            if (dfs(u + 1)) {
                return true;
            }
            cnt[1] = 1;
            path[u] = 0;
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int n;
    vector<int> cnt, path;

    vector<int> constructDistancedSequence(int _n) {
        n = _n;
        cnt.resize(n * 2, 2);
        path.resize(n * 2);
        cnt[1] = 1;
        dfs(1);
        vector<int> ans;
        for (int i = 1; i < n * 2; ++i) ans.push_back(path[i]);
        return ans;
    }

    bool dfs(int u) {
        if (u == n * 2) return 1;
        if (path[u]) return dfs(u + 1);
        for (int i = n; i > 1; --i) {
            if (cnt[i] && u + i < n * 2 && !path[u + i]) {
                path[u] = path[u + i] = i;
                cnt[i] = 0;
                if (dfs(u + 1)) return 1;
                cnt[i] = 2;
                path[u] = path[u + i] = 0;
            }
        }
        if (cnt[1]) {
            path[u] = 1;
            cnt[1] = 0;
            if (dfs(u + 1)) return 1;
            cnt[1] = 1;
            path[u] = 0;
        }
        return 0;
    }
};
```

#### Go

```go
func constructDistancedSequence(n int) []int {
	path := make([]int, n*2)
	cnt := make([]int, n*2)
	for i := range cnt {
		cnt[i] = 2
	}
	cnt[1] = 1
	var dfs func(u int) bool
	dfs = func(u int) bool {
		if u == n*2 {
			return true
		}
		if path[u] > 0 {
			return dfs(u + 1)
		}
		for i := n; i > 1; i-- {
			if cnt[i] > 0 && u+i < n*2 && path[u+i] == 0 {
				cnt[i] = 0
				path[u], path[u+i] = i, i
				if dfs(u + 1) {
					return true
				}
				cnt[i] = 2
				path[u], path[u+i] = 0, 0
			}
		}
		if cnt[1] > 0 {
			cnt[1] = 0
			path[u] = 1
			if dfs(u + 1) {
				return true
			}
			cnt[1] = 1
			path[u] = 0
		}
		return false
	}
	dfs(1)
	return path[1:]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1719. 重构一棵树的方案数](https://leetcode.cn/problems/number-of-ways-to-reconstruct-a-tree){#1719}

{{< tabs "1719" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkWays(self, pairs: List[List[int]]) -> int:
        g = [[False] * 510 for _ in range(510)]
        v = defaultdict(list)
        for x, y in pairs:
            g[x][y] = g[y][x] = True
            v[x].append(y)
            v[y].append(x)
        nodes = []
        for i in range(510):
            if v[i]:
                nodes.append(i)
                g[i][i] = True
        nodes.sort(key=lambda x: len(v[x]))
        equal = False
        root = 0
        for i, x in enumerate(nodes):
            j = i + 1
            while j < len(nodes) and not g[x][nodes[j]]:
                j += 1
            if j < len(nodes):
                y = nodes[j]
                if len(v[x]) == len(v[y]):
                    equal = True
                for z in v[x]:
                    if not g[y][z]:
                        return 0
            else:
                root += 1
        if root > 1:
            return 0
        return 2 if equal else 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int checkWays(int[][] pairs) {
        boolean[][] g = new boolean[510][510];
        List<Integer>[] v = new List[510];
        Arrays.setAll(v, k -> new ArrayList<>());
        for (int[] p : pairs) {
            int x = p[0], y = p[1];
            g[x][y] = true;
            g[y][x] = true;
            v[x].add(y);
            v[y].add(x);
        }
        List<Integer> nodes = new ArrayList<>();
        for (int i = 0; i < 510; ++i) {
            if (!v[i].isEmpty()) {
                nodes.add(i);
                g[i][i] = true;
            }
        }
        nodes.sort(Comparator.comparingInt(a -> v[a].size()));
        boolean equal = false;
        int root = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            int x = nodes.get(i);
            int j = i + 1;
            for (; j < nodes.size() && !g[x][nodes.get(j)]; ++j)
                ;
            if (j < nodes.size()) {
                int y = nodes.get(j);
                if (v[x].size() == v[y].size()) {
                    equal = true;
                }
                for (int z : v[x]) {
                    if (!g[y][z]) {
                        return 0;
                    }
                }
            } else {
                ++root;
            }
        }
        if (root > 1) {
            return 0;
        }
        return equal ? 2 : 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        vector<vector<bool>> g(510, vector<bool>(510));
        vector<vector<int>> v(510);
        for (auto& p : pairs) {
            int x = p[0], y = p[1];
            g[x][y] = g[y][x] = 1;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> nodes;
        for (int i = 1; i <= 500; ++i) {
            if (v[i].size()) {
                nodes.push_back(i);
                g[i][i] = 1;
            }
        }
        sort(nodes.begin(), nodes.end(), [&](int x, int y) -> bool { return v[x].size() < v[y].size(); });
        bool equal = 0;
        int root = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            int x = nodes[i];
            int j = i + 1;
            for (; j < nodes.size() && !g[x][nodes[j]]; ++j)
                ;
            if (j < nodes.size()) {
                int y = nodes[j];
                if (v[x].size() == v[y].size()) equal = 1;
                for (int z : v[x])
                    if (!g[y][z])
                        return 0;
            } else
                ++root;
        }
        if (root > 1) return 0;
        if (equal) return 2;
        return 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkWays(pairs [][]int) int {
	g := make([][]bool, 510)
	v := make([][]int, 510)
	for i := range g {
		g[i] = make([]bool, 510)
	}
	for _, p := range pairs {
		x, y := p[0], p[1]
		g[x][y] = true
		g[y][x] = true
		v[x] = append(v[x], y)
		v[y] = append(v[y], x)
	}
	var nodes []int
	for i := 1; i <= 500; i++ {
		if len(v[i]) > 0 {
			nodes = append(nodes, i)
			g[i][i] = true
		}
	}
	sort.Slice(nodes, func(i, j int) bool {
		return len(v[nodes[i]]) < len(v[nodes[j]])
	})
	equal := false
	root := 0
	for i, x := range nodes {
		j := i + 1
		for ; j < len(nodes) && !g[x][nodes[j]]; j++ {
		}
		if j < len(nodes) {
			y := nodes[j]
			if len(v[x]) == len(v[y]) {
				equal = true
			}
			for _, z := range v[x] {
				if !g[y][z] {
					return 0
				}
			}
		} else {
			root++
		}
	}
	if root > 1 {
		return 0
	}
	if equal {
		return 2
	}
	return 1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>pairs</code> ，其中 <code>pairs[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> ，并且满足：</p>

<ul>
	<li><code>pairs</code> 中没有重复元素</li>
	<li><code>x<sub>i</sub> < y<sub>i</sub></code></li>
</ul>

<p>令 <code>ways</code> 为满足下面条件的有根树的方案数：</p>

<ul>
	<li>树所包含的所有节点值都在 <code>pairs</code> 中。</li>
	<li>一个数对 <code>[x<sub>i</sub>, y<sub>i</sub>]</code> 出现在 <code>pairs</code> 中 <strong>当且仅当</strong><strong> </strong><code>x<sub>i</sub></code> 是 <code>y<sub>i</sub></code> 的祖先或者 <code>y<sub>i</sub></code> 是 <code>x<sub>i</sub></code><sub> </sub>的祖先。</li>
	<li><strong>注意：</strong>构造出来的树不一定是二叉树。</li>
</ul>

<p>两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。</p>

<p>请你返回：</p>

<ul>
	<li>如果 <code>ways == 0</code> ，返回 <code>0</code> 。</li>
	<li>如果 <code>ways == 1</code> ，返回 <code>1</code> 。</li>
	<li>如果 <code>ways > 1</code> ，返回 <code>2</code> 。</li>
</ul>

<p>一棵 <strong>有根树</strong> 指的是只有一个根节点的树，所有边都是从根往外的方向。</p>

<p>我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 <strong>祖先</strong> 。根节点没有祖先。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1719.Number%20Of%20Ways%20To%20Reconstruct%20A%20Tree/images/trees2.png" style="width: 208px; height: 221px;" />
<pre>
<b>输入：</b>pairs = [[1,2],[2,3]]
<b>输出：</b>1
<b>解释：</b>如上图所示，有且只有一个符合规定的有根树。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1700-1799/1719.Number%20Of%20Ways%20To%20Reconstruct%20A%20Tree/images/tree.png" style="width: 234px; height: 241px;" />
<pre>
<b>输入：</b>pairs = [[1,2],[2,3],[1,3]]
<b>输出：</b>2
<b>解释：</b>有多个符合规定的有根树，其中三个如上图所示。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>pairs = [[1,2],[2,3],[2,4],[1,5]]
<b>输出：</b>0
<b>解释：</b>没有符合规定的有根树。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= pairs.length <= 10<sup>5</sup></code></li>
	<li><code>1 <= x<sub>i </sub>< y<sub>i</sub> <= 500</code></li>
	<li><code>pairs</code> 中的元素互不相同。</li>
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
    def checkWays(self, pairs: List[List[int]]) -> int:
        g = [[False] * 510 for _ in range(510)]
        v = defaultdict(list)
        for x, y in pairs:
            g[x][y] = g[y][x] = True
            v[x].append(y)
            v[y].append(x)
        nodes = []
        for i in range(510):
            if v[i]:
                nodes.append(i)
                g[i][i] = True
        nodes.sort(key=lambda x: len(v[x]))
        equal = False
        root = 0
        for i, x in enumerate(nodes):
            j = i + 1
            while j < len(nodes) and not g[x][nodes[j]]:
                j += 1
            if j < len(nodes):
                y = nodes[j]
                if len(v[x]) == len(v[y]):
                    equal = True
                for z in v[x]:
                    if not g[y][z]:
                        return 0
            else:
                root += 1
        if root > 1:
            return 0
        return 2 if equal else 1
```

#### Java

```java
class Solution {
    public int checkWays(int[][] pairs) {
        boolean[][] g = new boolean[510][510];
        List<Integer>[] v = new List[510];
        Arrays.setAll(v, k -> new ArrayList<>());
        for (int[] p : pairs) {
            int x = p[0], y = p[1];
            g[x][y] = true;
            g[y][x] = true;
            v[x].add(y);
            v[y].add(x);
        }
        List<Integer> nodes = new ArrayList<>();
        for (int i = 0; i < 510; ++i) {
            if (!v[i].isEmpty()) {
                nodes.add(i);
                g[i][i] = true;
            }
        }
        nodes.sort(Comparator.comparingInt(a -> v[a].size()));
        boolean equal = false;
        int root = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            int x = nodes.get(i);
            int j = i + 1;
            for (; j < nodes.size() && !g[x][nodes.get(j)]; ++j)
                ;
            if (j < nodes.size()) {
                int y = nodes.get(j);
                if (v[x].size() == v[y].size()) {
                    equal = true;
                }
                for (int z : v[x]) {
                    if (!g[y][z]) {
                        return 0;
                    }
                }
            } else {
                ++root;
            }
        }
        if (root > 1) {
            return 0;
        }
        return equal ? 2 : 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        vector<vector<bool>> g(510, vector<bool>(510));
        vector<vector<int>> v(510);
        for (auto& p : pairs) {
            int x = p[0], y = p[1];
            g[x][y] = g[y][x] = 1;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector<int> nodes;
        for (int i = 1; i <= 500; ++i) {
            if (v[i].size()) {
                nodes.push_back(i);
                g[i][i] = 1;
            }
        }
        sort(nodes.begin(), nodes.end(), [&](int x, int y) -> bool { return v[x].size() < v[y].size(); });
        bool equal = 0;
        int root = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            int x = nodes[i];
            int j = i + 1;
            for (; j < nodes.size() && !g[x][nodes[j]]; ++j)
                ;
            if (j < nodes.size()) {
                int y = nodes[j];
                if (v[x].size() == v[y].size()) equal = 1;
                for (int z : v[x])
                    if (!g[y][z])
                        return 0;
            } else
                ++root;
        }
        if (root > 1) return 0;
        if (equal) return 2;
        return 1;
    }
};
```

#### Go

```go
func checkWays(pairs [][]int) int {
	g := make([][]bool, 510)
	v := make([][]int, 510)
	for i := range g {
		g[i] = make([]bool, 510)
	}
	for _, p := range pairs {
		x, y := p[0], p[1]
		g[x][y] = true
		g[y][x] = true
		v[x] = append(v[x], y)
		v[y] = append(v[y], x)
	}
	var nodes []int
	for i := 1; i <= 500; i++ {
		if len(v[i]) > 0 {
			nodes = append(nodes, i)
			g[i][i] = true
		}
	}
	sort.Slice(nodes, func(i, j int) bool {
		return len(v[nodes[i]]) < len(v[nodes[j]])
	})
	equal := false
	root := 0
	for i, x := range nodes {
		j := i + 1
		for ; j < len(nodes) && !g[x][nodes[j]]; j++ {
		}
		if j < len(nodes) {
			y := nodes[j]
			if len(v[x]) == len(v[y]) {
				equal = true
			}
			for _, z := range v[x] {
				if !g[y][z] {
					return 0
				}
			}
		} else {
			root++
		}
	}
	if root > 1 {
		return 0
	}
	if equal {
		return 2
	}
	return 1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
