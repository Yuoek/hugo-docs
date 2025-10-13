---
title: "2910_合法分组的最少组数"
date: 2025-10-08T18:39:48+08:00
weight: 2
tags: [位运算, 动态规划, 双指针, 哈希表, 字符串, 数学, 数组, 树状数组, 线段树, 组合数学, 贪心]
---

{{< markmap >}}
### [2910_合法分组的最少组数](#2910)
#### [贪心](#2910)
#### [数组](#2910)
#### [哈希表](#2910)
### [2911_得到 K 个半回文串的最少修改次数](#2911)
#### [双指针](#2911)
#### [字符串](#2911)
#### [动态规划](#2911)
### [2912_在网格上移动到目的地的方法数 🔒](#2912)
#### [数学](#2912)
#### [动态规划](#2912)
#### [组合数学](#2912)
### [2913_子数组不同元素数目的平方和 I](#2913)
#### [数组](#2913)
#### [哈希表](#2913)
### [2914_使二进制字符串变美丽的最少修改次数](#2914)
#### [字符串](#2914)
### [2915_和为目标值的最长子序列的长度](#2915)
#### [数组](#2915)
#### [动态规划](#2915)
### [2916_子数组不同元素数目的平方和 II](#2916)
#### [树状数组](#2916)
#### [线段树](#2916)
#### [数组](#2916)
#### [动态规划](#2916)
### [2917_找出数组中的 K-or 值](#2917)
#### [位运算](#2917)
#### [数组](#2917)
### [2918_数组的最小相等和](#2918)
#### [贪心](#2918)
#### [数组](#2918)
### [2919_使数组变美的最小增量运算数](#2919)
#### [数组](#2919)
#### [动态规划](#2919)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2910_合法分组的最少组数
___
#### 贪心
___
#### 数组
___
#### 哈希表
---
### 2911_得到 K 个半回文串的最少修改次数
___
#### 双指针
___
#### 字符串
___
#### 动态规划
---
### 2912_在网格上移动到目的地的方法数 🔒
___
#### 数学
___
#### 动态规划
___
#### 组合数学
---
### 2913_子数组不同元素数目的平方和 I
___
#### 数组
___
#### 哈希表
---
### 2914_使二进制字符串变美丽的最少修改次数
___
#### 字符串
---
### 2915_和为目标值的最长子序列的长度
___
#### 数组
___
#### 动态规划
---
### 2916_子数组不同元素数目的平方和 II
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 动态规划
---
### 2917_找出数组中的 K-or 值
___
#### 位运算
___
#### 数组
---
### 2918_数组的最小相等和
___
#### 贪心
___
#### 数组
---
### 2919_使数组变美的最小增量运算数
___
#### 数组
___
#### 动态规划
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 双指针 |
| 哈希表 | 字符串 | 数学 |
| 数组 | 树状数组 | 线段树 |
| 组合数学 | 贪心 |  |

# [2910. 合法分组的最少组数](https://leetcode.cn/problems/minimum-number-of-groups-to-create-a-valid-assignment){#2910}

{{< tabs "2910" >}}

{{% tab "python" %}}
```python
class Solution:
    def minGroupsForValidAssignment(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        for k in range(min(cnt.values()), 0, -1):
            ans = 0
            for v in cnt.values():
                if v // k < v % k:
                    ans = 0
                    break
                ans += (v + k) // (k + 1)
            if ans:
                return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minGroupsForValidAssignment(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int k = nums.length;
        for (int v : cnt.values()) {
            k = Math.min(k, v);
        }
        for (;; --k) {
            int ans = 0;
            for (int v : cnt.values()) {
                if (v / k < v % k) {
                    ans = 0;
                    break;
                }
                ans += (v + k) / (k + 1);
            }
            if (ans > 0) {
                return ans;
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
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        int k = 1e9;
        for (auto& [_, v] : cnt) {
            ans = min(ans, v);
        }
        for (;; --k) {
            int ans = 0;
            for (auto& [_, v] : cnt) {
                if (v / k < v % k) {
                    ans = 0;
                    break;
                }
                ans += (v + k) / (k + 1);
            }
            if (ans) {
                return ans;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minGroupsForValidAssignment(nums []int) int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	k := len(nums)
	for _, v := range cnt {
		k = min(k, v)
	}
	for ; ; k-- {
		ans := 0
		for _, v := range cnt {
			if v/k < v%k {
				ans = 0
				break
			}
			ans += (v + k) / (k + 1)
		}
		if ans > 0 {
			return ans
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minGroupsForValidAssignment(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    for (let k = Math.min(...cnt.values()); ; --k) {
        let ans = 0;
        for (const [_, v] of cnt) {
            if (((v / k) | 0) < v % k) {
                ans = 0;
                break;
            }
            ans += Math.ceil(v / (k + 1));
        }
        if (ans) {
            return ans;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_groups_for_valid_assignment(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();

        for x in nums.iter() {
            let count = cnt.entry(*x).or_insert(0);
            *count += 1;
        }

        let mut k = i32::MAX;

        for &v in cnt.values() {
            k = k.min(v);
        }

        for k in (1..=k).rev() {
            let mut ans = 0;

            for &v in cnt.values() {
                if v / k < v % k {
                    ans = 0;
                    break;
                }

                ans += (v + k) / (k + 1);
            }

            if ans > 0 {
                return ans;
            }
        }

        0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一组带编号的&nbsp;<code>balls</code> 并要求将它们分类到盒子里，以便均衡地分配。你必须遵守两条规则：</p>

<ul>
	<li>同一个盒子里的球必须具有相同的编号。但是，如果你有多个相同编号的球，你可以把它们放在不同的盒子里。</li>
	<li>最大的盒子只能比最小的盒子多一个球。</li>
</ul>

<p>返回遵循上述规则排列这些球所需要的盒子的最小数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>balls = [3,2,3,2,3]
<b>输出：</b>2
<b>解释：</b>一个得到 2 个分组的方案如下，中括号内的数字都是下标：
我们可以如下排列 balls 到盒子里：
- [3,3,3]
- [2,2]
两个盒子之间的大小差没有超过 1。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>balls = [10,10,10,3,1,1]
<b>输出：</b>4
<b>解释：</b>我们可以如下排列 balls 到盒子里：
- [10]
- [10,10]
- [3]
- [1,1]
无法得到一个遵循上述规则且小于 4 盒的答案。例如，把所有三个编号为 10 的球都放在一个盒子里，就会打破盒子之间最大尺寸差异的规则。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= balls.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= balls[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们用一个哈希表 $cnt$ 统计数组 $nums$ 中每个数字出现的次数，我们记数字次数的最小值为 $k$，那么我们可以在 $[k,..1]$ 的范围内枚举分组的大小。由于每个组的大小差值不超过 $1$，那么分组大小为 $k$ 或 $k+1$。

对于当前枚举到的分组大小 $k$，我们遍历哈希表中的每个次数 $v$，如果 $\lfloor \frac{v}{k} \rfloor < v \bmod k$，那么说明无法将这个次数 $v$ 分成 $k$ 个或 $k+1$ 个数值相同的组，因此我们可以直接跳过这个分组大小 $k$。否则，说明可以分组，我们只需要尽可能分出最多的分组大小 $k+1$，即可保证得到最小的分组数，因此我们可以将 $v$ 个数分成 $\lceil \frac{v}{k+1} \rceil$ 组，累加到当前枚举的答案中。由于我们是按照 $k$ 从大到小枚举的，因此只要找到了一个合法的分组方案，那么一定是最优的。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minGroupsForValidAssignment(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        for k in range(min(cnt.values()), 0, -1):
            ans = 0
            for v in cnt.values():
                if v // k < v % k:
                    ans = 0
                    break
                ans += (v + k) // (k + 1)
            if ans:
                return ans
```

#### Java

```java
class Solution {
    public int minGroupsForValidAssignment(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int k = nums.length;
        for (int v : cnt.values()) {
            k = Math.min(k, v);
        }
        for (;; --k) {
            int ans = 0;
            for (int v : cnt.values()) {
                if (v / k < v % k) {
                    ans = 0;
                    break;
                }
                ans += (v + k) / (k + 1);
            }
            if (ans > 0) {
                return ans;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        int k = 1e9;
        for (auto& [_, v] : cnt) {
            ans = min(ans, v);
        }
        for (;; --k) {
            int ans = 0;
            for (auto& [_, v] : cnt) {
                if (v / k < v % k) {
                    ans = 0;
                    break;
                }
                ans += (v + k) / (k + 1);
            }
            if (ans) {
                return ans;
            }
        }
    }
};
```

#### Go

```go
func minGroupsForValidAssignment(nums []int) int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	k := len(nums)
	for _, v := range cnt {
		k = min(k, v)
	}
	for ; ; k-- {
		ans := 0
		for _, v := range cnt {
			if v/k < v%k {
				ans = 0
				break
			}
			ans += (v + k) / (k + 1)
		}
		if ans > 0 {
			return ans
		}
	}
}
```

#### TypeScript

```ts
function minGroupsForValidAssignment(nums: number[]): number {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    for (let k = Math.min(...cnt.values()); ; --k) {
        let ans = 0;
        for (const [_, v] of cnt) {
            if (((v / k) | 0) < v % k) {
                ans = 0;
                break;
            }
            ans += Math.ceil(v / (k + 1));
        }
        if (ans) {
            return ans;
        }
    }
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_groups_for_valid_assignment(nums: Vec<i32>) -> i32 {
        let mut cnt: HashMap<i32, i32> = HashMap::new();

        for x in nums.iter() {
            let count = cnt.entry(*x).or_insert(0);
            *count += 1;
        }

        let mut k = i32::MAX;

        for &v in cnt.values() {
            k = k.min(v);
        }

        for k in (1..=k).rev() {
            let mut ans = 0;

            for &v in cnt.values() {
                if v / k < v % k {
                    ans = 0;
                    break;
                }

                ans += (v + k) / (k + 1);
            }

            if ans > 0 {
                return ans;
            }
        }

        0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2911. 得到 K 个半回文串的最少修改次数](https://leetcode.cn/problems/minimum-changes-to-make-k-semi-palindromes){#2911}

{{< tabs "2911" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        g = [[inf] * (n + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                m = j - i + 1
                for d in range(1, m):
                    if m % d == 0:
                        cnt = 0
                        for l in range(m):
                            r = (m // d - 1 - l // d) * d + l % d
                            if l >= r:
                                break
                            if s[i - 1 + l] != s[i - 1 + r]:
                                cnt += 1
                        g[i][j] = min(g[i][j], cnt)

        f = [[inf] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                for h in range(i - 1):
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h + 1][i])
        return f[n][k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    static int inf = 200;
    List<Integer>[] factorLists;
    int n;
    int k;
    char[] ch;
    Integer[][] cost;
    public int minimumChanges(String s, int k) {
        this.k = k;
        n = s.length();
        ch = s.toCharArray();

        factorLists = getFactorLists(n);
        cost = new Integer[n + 1][n + 1];
        return calcDP();
    }
    static List<Integer>[] getFactorLists(int n) {
        List<Integer>[] l = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            l[i] = new ArrayList<>();
            l[i].add(1);
        }
        for (int factor = 2; factor < n; factor++) {
            for (int num = factor + factor; num <= n; num += factor) {
                l[num].add(factor);
            }
        }
        return l;
    }
    int calcDP() {
        int[] dp = new int[n];
        for (int i = n - k * 2 + 1; i >= 1; i--) {
            dp[i] = getCost(0, i);
        }
        int bound = 0;
        for (int subs = 2; subs <= k; subs++) {
            bound = subs * 2;
            for (int i = n - 1 - k * 2 + subs * 2; i >= bound - 1; i--) {
                dp[i] = inf;
                for (int prev = bound - 3; prev < i - 1; prev++) {
                    dp[i] = Math.min(dp[i], dp[prev] + getCost(prev + 1, i));
                }
            }
        }
        return dp[n - 1];
    }
    int getCost(int l, int r) {
        if (l >= r) {
            return inf;
        }
        if (cost[l][r] != null) {
            return cost[l][r];
        }
        cost[l][r] = inf;
        for (int factor : factorLists[r - l + 1]) {
            cost[l][r] = Math.min(cost[l][r], getStepwiseCost(l, r, factor));
        }
        return cost[l][r];
    }
    int getStepwiseCost(int l, int r, int stepsize) {
        if (l >= r) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        for (int i = 0; i < stepsize; i++) {
            left = l + i;
            right = r - stepsize + 1 + i;
            while (left + stepsize <= right) {
                if (ch[left] != ch[right]) {
                    count++;
                }
                left += stepsize;
                right -= stepsize;
            }
        }
        return count;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        int g[n + 1][n + 1];
        int f[n + 1][k + 1];
        memset(g, 0x3f, sizeof(g));
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int m = j - i + 1;
                for (int d = 1; d < m; ++d) {
                    if (m % d == 0) {
                        int cnt = 0;
                        for (int l = 0; l < m; ++l) {
                            int r = (m / d - 1 - l / d) * d + l % d;
                            if (l >= r) {
                                break;
                            }
                            if (s[i - 1 + l] != s[i - 1 + r]) {
                                ++cnt;
                            }
                        }
                        g[i][j] = min(g[i][j], cnt);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i - 1; ++h) {
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h + 1][i]);
                }
            }
        }
        return f[n][k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumChanges(s string, k int) int {
	n := len(s)
	g := make([][]int, n+1)
	f := make([][]int, n+1)
	const inf int = 1 << 30
	for i := range g {
		g[i] = make([]int, n+1)
		f[i] = make([]int, k+1)
		for j := range g[i] {
			g[i][j] = inf
		}
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			m := j - i + 1
			for d := 1; d < m; d++ {
				if m%d == 0 {
					cnt := 0
					for l := 0; l < m; l++ {
						r := (m/d-1-l/d)*d + l%d
						if l >= r {
							break
						}
						if s[i-1+l] != s[i-1+r] {
							cnt++
						}
					}
					g[i][j] = min(g[i][j], cnt)
				}
			}
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			for h := 0; h < i-1; h++ {
				f[i][j] = min(f[i][j], f[h][j-1]+g[h+1][i])
			}
		}
	}
	return f[n][k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumChanges(s: string, k: number): number {
    const n = s.length;
    const g = Array.from({ length: n + 1 }, () => Array.from({ length: n + 1 }, () => Infinity));
    const f = Array.from({ length: n + 1 }, () => Array.from({ length: k + 1 }, () => Infinity));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= n; ++j) {
            const m = j - i + 1;
            for (let d = 1; d < m; ++d) {
                if (m % d === 0) {
                    let cnt = 0;
                    for (let l = 0; l < m; ++l) {
                        const r = (((m / d) | 0) - 1 - ((l / d) | 0)) * d + (l % d);
                        if (l >= r) {
                            break;
                        }
                        if (s[i - 1 + l] !== s[i - 1 + r]) {
                            ++cnt;
                        }
                    }
                    g[i][j] = Math.min(g[i][j], cnt);
                }
            }
        }
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            for (let h = 0; h < i - 1; ++h) {
                f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h + 1][i]);
            }
        }
    }
    return f[n][k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，请你将&nbsp;<code>s</code> 分成&nbsp;<code>k</code>&nbsp;个<strong>&nbsp;子字符串</strong>&nbsp;，使得每个 <strong>子字符串</strong>&nbsp;变成&nbsp;<strong>半回文串</strong>&nbsp;需要修改的字符数目最少。</p>

<p>请你返回一个整数，表示需要修改的 <strong>最少</strong>&nbsp;字符数目。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果一个字符串从左往右和从右往左读是一样的，那么它是一个 <strong>回文串</strong>&nbsp;。</li>
	<li>如果长度为 <code>len</code>&nbsp;的字符串存在一个满足&nbsp;<code>1 &lt;= d &lt; len</code>&nbsp;的正整数&nbsp;<code>d</code>&nbsp;，<code>len % d == 0</code>&nbsp;成立且所有对 <code>d</code>&nbsp;做除法余数相同的下标对应的字符连起来得到的字符串都是 <strong>回文串</strong>&nbsp;，那么我们说这个字符串是 <strong>半回文串</strong>&nbsp;。比方说&nbsp;<code>"aa"</code>&nbsp;，<code>"aba"</code> ，<code>"adbgad"</code>&nbsp;和&nbsp;<code>"abab"</code>&nbsp;都是 <strong>半回文串</strong>&nbsp;，而&nbsp;<code>"a"</code>&nbsp;，<code>"ab"</code>&nbsp;和&nbsp;<code>"abca"</code>&nbsp;不是。</li>
	<li><strong>子字符串</strong>&nbsp;指的是一个字符串中一段连续的字符序列。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "abcac", k = 2
<b>输出：</b>1
<b>解释：</b>我们可以将 s 分成子字符串 "ab" 和 "cac" 。子字符串 "cac" 已经是半回文串。如果我们将 "ab" 变成 "aa" ，它也会变成一个 d = 1 的半回文串。
该方案是将 s 分成 2 个子字符串的前提下，得到 2 个半回文子字符串需要的最少修改次数。所以答案为 1 。</pre>

<p><strong class="example">示例 2:</strong></p>

<pre>
<b>输入：</b>s = "abcdef", k = 2
<b>输出：</b>2
<b>解释：</b>我们可以将 s 分成子字符串 "abc" 和 "def" 。子字符串 "abc" 和 "def" 都需要修改一个字符得到半回文串，所以我们总共需要 2 次字符修改使所有子字符串变成半回文串。
该方案是将 s 分成 2 个子字符串的前提下，得到 2 个半回文子字符串需要的最少修改次数。所以答案为 2 。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>s = "aabbaa", k = 3
<b>输出：</b>0
<b>解释：</b>我们可以将 s 分成子字符串 "aa" ，"bb" 和 "aa" 。
字符串 "aa" 和 "bb" 都已经是半回文串了。所以答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 200</code></li>
	<li><code>1 &lt;= k &lt;= s.length / 2</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
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
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        g = [[inf] * (n + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                m = j - i + 1
                for d in range(1, m):
                    if m % d == 0:
                        cnt = 0
                        for l in range(m):
                            r = (m // d - 1 - l // d) * d + l % d
                            if l >= r:
                                break
                            if s[i - 1 + l] != s[i - 1 + r]:
                                cnt += 1
                        g[i][j] = min(g[i][j], cnt)

        f = [[inf] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                for h in range(i - 1):
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h + 1][i])
        return f[n][k]
```

#### Java

```java
class Solution {
    public int minimumChanges(String s, int k) {
        int n = s.length();
        int[][] g = new int[n + 1][n + 1];
        int[][] f = new int[n + 1][k + 1];
        final int inf = 1 << 30;
        for (int i = 0; i <= n; ++i) {
            Arrays.fill(g[i], inf);
            Arrays.fill(f[i], inf);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int m = j - i + 1;
                for (int d = 1; d < m; ++d) {
                    if (m % d == 0) {
                        int cnt = 0;
                        for (int l = 0; l < m; ++l) {
                            int r = (m / d - 1 - l / d) * d + l % d;
                            if (l >= r) {
                                break;
                            }
                            if (s.charAt(i - 1 + l) != s.charAt(i - 1 + r)) {
                                ++cnt;
                            }
                        }
                        g[i][j] = Math.min(g[i][j], cnt);
                    }
                }
            }
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i - 1; ++h) {
                    f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h + 1][i]);
                }
            }
        }
        return f[n][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        int g[n + 1][n + 1];
        int f[n + 1][k + 1];
        memset(g, 0x3f, sizeof(g));
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int m = j - i + 1;
                for (int d = 1; d < m; ++d) {
                    if (m % d == 0) {
                        int cnt = 0;
                        for (int l = 0; l < m; ++l) {
                            int r = (m / d - 1 - l / d) * d + l % d;
                            if (l >= r) {
                                break;
                            }
                            if (s[i - 1 + l] != s[i - 1 + r]) {
                                ++cnt;
                            }
                        }
                        g[i][j] = min(g[i][j], cnt);
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int h = 0; h < i - 1; ++h) {
                    f[i][j] = min(f[i][j], f[h][j - 1] + g[h + 1][i]);
                }
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func minimumChanges(s string, k int) int {
	n := len(s)
	g := make([][]int, n+1)
	f := make([][]int, n+1)
	const inf int = 1 << 30
	for i := range g {
		g[i] = make([]int, n+1)
		f[i] = make([]int, k+1)
		for j := range g[i] {
			g[i][j] = inf
		}
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		for j := i; j <= n; j++ {
			m := j - i + 1
			for d := 1; d < m; d++ {
				if m%d == 0 {
					cnt := 0
					for l := 0; l < m; l++ {
						r := (m/d-1-l/d)*d + l%d
						if l >= r {
							break
						}
						if s[i-1+l] != s[i-1+r] {
							cnt++
						}
					}
					g[i][j] = min(g[i][j], cnt)
				}
			}
		}
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= k; j++ {
			for h := 0; h < i-1; h++ {
				f[i][j] = min(f[i][j], f[h][j-1]+g[h+1][i])
			}
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function minimumChanges(s: string, k: number): number {
    const n = s.length;
    const g = Array.from({ length: n + 1 }, () => Array.from({ length: n + 1 }, () => Infinity));
    const f = Array.from({ length: n + 1 }, () => Array.from({ length: k + 1 }, () => Infinity));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= n; ++j) {
            const m = j - i + 1;
            for (let d = 1; d < m; ++d) {
                if (m % d === 0) {
                    let cnt = 0;
                    for (let l = 0; l < m; ++l) {
                        const r = (((m / d) | 0) - 1 - ((l / d) | 0)) * d + (l % d);
                        if (l >= r) {
                            break;
                        }
                        if (s[i - 1 + l] !== s[i - 1 + r]) {
                            ++cnt;
                        }
                    }
                    g[i][j] = Math.min(g[i][j], cnt);
                }
            }
        }
    }
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= k; ++j) {
            for (let h = 0; h < i - 1; ++h) {
                f[i][j] = Math.min(f[i][j], f[h][j - 1] + g[h + 1][i]);
            }
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Solution {
    static int inf = 200;
    List<Integer>[] factorLists;
    int n;
    int k;
    char[] ch;
    Integer[][] cost;
    public int minimumChanges(String s, int k) {
        this.k = k;
        n = s.length();
        ch = s.toCharArray();

        factorLists = getFactorLists(n);
        cost = new Integer[n + 1][n + 1];
        return calcDP();
    }
    static List<Integer>[] getFactorLists(int n) {
        List<Integer>[] l = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            l[i] = new ArrayList<>();
            l[i].add(1);
        }
        for (int factor = 2; factor < n; factor++) {
            for (int num = factor + factor; num <= n; num += factor) {
                l[num].add(factor);
            }
        }
        return l;
    }
    int calcDP() {
        int[] dp = new int[n];
        for (int i = n - k * 2 + 1; i >= 1; i--) {
            dp[i] = getCost(0, i);
        }
        int bound = 0;
        for (int subs = 2; subs <= k; subs++) {
            bound = subs * 2;
            for (int i = n - 1 - k * 2 + subs * 2; i >= bound - 1; i--) {
                dp[i] = inf;
                for (int prev = bound - 3; prev < i - 1; prev++) {
                    dp[i] = Math.min(dp[i], dp[prev] + getCost(prev + 1, i));
                }
            }
        }
        return dp[n - 1];
    }
    int getCost(int l, int r) {
        if (l >= r) {
            return inf;
        }
        if (cost[l][r] != null) {
            return cost[l][r];
        }
        cost[l][r] = inf;
        for (int factor : factorLists[r - l + 1]) {
            cost[l][r] = Math.min(cost[l][r], getStepwiseCost(l, r, factor));
        }
        return cost[l][r];
    }
    int getStepwiseCost(int l, int r, int stepsize) {
        if (l >= r) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        for (int i = 0; i < stepsize; i++) {
            left = l + i;
            right = r - stepsize + 1 + i;
            while (left + stepsize <= right) {
                if (ch[left] != ch[right]) {
                    count++;
                }
                left += stepsize;
                right -= stepsize;
            }
        }
        return count;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2912. 在网格上移动到目的地的方法数 🔒](https://leetcode.cn/problems/number-of-ways-to-reach-destination-in-the-grid){#2912}

{{< tabs "2912" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWays(
        self, n: int, m: int, k: int, source: List[int], dest: List[int]
    ) -> int:
        mod = 10**9 + 7
        f = [1, 0, 0, 0]
        for _ in range(k):
            g = [0] * 4
            g[0] = ((n - 1) * f[1] + (m - 1) * f[2]) % mod
            g[1] = (f[0] + (n - 2) * f[1] + (m - 1) * f[3]) % mod
            g[2] = (f[0] + (m - 2) * f[2] + (n - 1) * f[3]) % mod
            g[3] = (f[1] + f[2] + (n - 2) * f[3] + (m - 2) * f[3]) % mod
            f = g
        if source[0] == dest[0]:
            return f[0] if source[1] == dest[1] else f[2]
        return f[1] if source[1] == dest[1] else f[3]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfWays(int n, int m, int k, int[] source, int[] dest) {
        final int mod = 1000000007;
        long[] f = new long[4];
        f[0] = 1;
        while (k-- > 0) {
            long[] g = new long[4];
            g[0] = ((n - 1) * f[1] + (m - 1) * f[2]) % mod;
            g[1] = (f[0] + (n - 2) * f[1] + (m - 1) * f[3]) % mod;
            g[2] = (f[0] + (m - 2) * f[2] + (n - 1) * f[3]) % mod;
            g[3] = (f[1] + f[2] + (n - 2) * f[3] + (m - 2) * f[3]) % mod;
            f = g;
        }
        if (source[0] == dest[0]) {
            return source[1] == dest[1] ? (int) f[0] : (int) f[2];
        }
        return source[1] == dest[1] ? (int) f[1] : (int) f[3];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        const int mod = 1e9 + 7;
        vector<long long> f(4);
        f[0] = 1;
        while (k--) {
            vector<long long> g(4);
            g[0] = ((n - 1) * f[1] + (m - 1) * f[2]) % mod;
            g[1] = (f[0] + (n - 2) * f[1] + (m - 1) * f[3]) % mod;
            g[2] = (f[0] + (m - 2) * f[2] + (n - 1) * f[3]) % mod;
            g[3] = (f[1] + f[2] + (n - 2) * f[3] + (m - 2) * f[3]) % mod;
            f = move(g);
        }
        if (source[0] == dest[0]) {
            return source[1] == dest[1] ? f[0] : f[2];
        }
        return source[1] == dest[1] ? f[1] : f[3];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(n int, m int, k int, source []int, dest []int) int {
	const mod int = 1e9 + 7
	f := []int{1, 0, 0, 0}
	for i := 0; i < k; i++ {
		g := make([]int, 4)
		g[0] = ((n-1)*f[1] + (m-1)*f[2]) % mod
		g[1] = (f[0] + (n-2)*f[1] + (m-1)*f[3]) % mod
		g[2] = (f[0] + (m-2)*f[2] + (n-1)*f[3]) % mod
		g[3] = (f[1] + f[2] + (n-2)*f[3] + (m-2)*f[3]) % mod
		f = g
	}

	if source[0] == dest[0] {
		if source[1] == dest[1] {
			return f[0]
		}
		return f[2]
	}

	if source[1] == dest[1] {
		return f[1]
	}
	return f[3]
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个整数 <code>n</code> 和 <code>m</code>，它们表示一个 <strong>下标从 1 开始&nbsp;</strong>的网格的大小。还给定一个整数 <code>k</code>，以及两个 <b>下标从 1 开始</b>&nbsp;的整数数组 <code>source</code> 和 <code>dest</code>。这两个数组 <code>source</code> 和 <code>dest</code> 形如 <code>[x, y]</code>，表示网格上的一个单元格。</p>

<p>你可以按照以下方式在网格上移动：</p>

<ul>
	<li>你可以从单元格 <code>[x1, y1]</code> 移动到 <code>[x2, y2]</code>，只要 <code>x1 == x2</code> 或 <code>y1 == y2</code>。</li>
	<li>注意，你 <strong>不能</strong> 移动到当前所在的单元格，即 <code>x1 == x2</code> 且 <code>y1 == y2</code>。</li>
</ul>

<p>请返回你在网格上从 <code>source</code> 到 <code>dest</code>&nbsp;移动 <code>k</code> 次一共可以有&nbsp;<strong>多少种 </strong>方法。</p>

<p>由于答案可能非常大，因此请对&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取模</strong> 后返回。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b> n = 3, m = 2, k = 2, source = [1,1], dest = [2,2]
<b>输出：</b> 2
<b>解释： </b>有两种可能的方式从 [1,1] 到达 [2,2]：
- [1,1] -&gt; [1,2] -&gt; [2,2]
- [1,1] -&gt; [2,1] -&gt; [2,2]
</pre>

<p><b>示例 2:</b></p>

<pre>
<b>输入：</b> n = 3, m = 4, k = 3, source = [1,2], dest = [2,3]
<b>输出：</b> 9
<b>解释：</b> 有 9 种可能的方式从 [1,2] 到达 [2,3]：:
- [1,2] -&gt; [1,1] -&gt; [1,3] -&gt; [2,3]
- [1,2] -&gt; [1,1] -&gt; [2,1] -&gt; [2,3]
- [1,2] -&gt; [1,3] -&gt; [3,3] -&gt; [2,3]
- [1,2] -&gt; [1,4] -&gt; [1,3] -&gt; [2,3]
- [1,2] -&gt; [1,4] -&gt; [2,4] -&gt; [2,3]
- [1,2] -&gt; [2,2] -&gt; [2,1] -&gt; [2,3]
- [1,2] -&gt; [2,2] -&gt; [2,4] -&gt; [2,3]
- [1,2] -&gt; [3,2] -&gt; [2,2] -&gt; [2,3]
- [1,2] -&gt; [3,2] -&gt; [3,3] -&gt; [2,3]
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>2 &lt;= n, m &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k&nbsp;&lt;= 10<sup>5</sup></code></li>
	<li><code>source.length == dest.length == 2</code></li>
	<li><code>1 &lt;= source[1], dest[1] &lt;= n</code></li>
	<li><code>1 &lt;= source[2], dest[2] &lt;= m</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义以下几个状态，其中：

-   $f[0]$ 表示从 $source$ 到 $source$ 本身的方法数；
-   $f[1]$ 表示从 $source$ 移动到同一列其它行的方法数；
-   $f[2]$ 表示从 $source$ 移动到同一行其它列的方法数；
-   $f[3]$ 表示从 $source$ 移动到其它行其它列的方法数。

初始时，$f[0] = 1$，其余状态均为 $0$。

对于每个状态，我们可以根据上一次的状态计算出当前的状态，具体如下：

$$
\begin{aligned}
g[0] &= (n - 1) \times f[1] + (m - 1) \times f[2] \\
g[1] &= f[0] + (n - 2) \times f[1] + (m - 1) \times f[3] \\
g[2] &= f[0] + (m - 2) \times f[2] + (n - 1) \times f[3] \\
g[3] &= f[1] + f[2] + (n - 2) \times f[3] + (m - 2) \times f[3]
\end{aligned}
$$

我们循环 $k$ 次，最后判断 $source$ 和 $dest$ 是否在同一行或同一列，返回对应的状态即可。

时间复杂度 $O(k)$，其中 $k$ 为移动次数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(
        self, n: int, m: int, k: int, source: List[int], dest: List[int]
    ) -> int:
        mod = 10**9 + 7
        a, b, c, d = 1, 0, 0, 0
        for _ in range(k):
            aa = ((n - 1) * b + (m - 1) * c) % mod
            bb = (a + (n - 2) * b + (m - 1) * d) % mod
            cc = (a + (m - 2) * c + (n - 1) * d) % mod
            dd = (b + c + (n - 2) * d + (m - 2) * d) % mod
            a, b, c, d = aa, bb, cc, dd
        if source[0] == dest[0]:
            return a if source[1] == dest[1] else c
        return b if source[1] == dest[1] else d
```

#### Python3

```python
class Solution:
    def numberOfWays(
        self, n: int, m: int, k: int, source: List[int], dest: List[int]
    ) -> int:
        mod = 10**9 + 7
        f = [1, 0, 0, 0]
        for _ in range(k):
            g = [0] * 4
            g[0] = ((n - 1) * f[1] + (m - 1) * f[2]) % mod
            g[1] = (f[0] + (n - 2) * f[1] + (m - 1) * f[3]) % mod
            g[2] = (f[0] + (m - 2) * f[2] + (n - 1) * f[3]) % mod
            g[3] = (f[1] + f[2] + (n - 2) * f[3] + (m - 2) * f[3]) % mod
            f = g
        if source[0] == dest[0]:
            return f[0] if source[1] == dest[1] else f[2]
        return f[1] if source[1] == dest[1] else f[3]
```

#### Java

```java
class Solution {
    public int numberOfWays(int n, int m, int k, int[] source, int[] dest) {
        final int mod = 1000000007;
        long[] f = new long[4];
        f[0] = 1;
        while (k-- > 0) {
            long[] g = new long[4];
            g[0] = ((n - 1) * f[1] + (m - 1) * f[2]) % mod;
            g[1] = (f[0] + (n - 2) * f[1] + (m - 1) * f[3]) % mod;
            g[2] = (f[0] + (m - 2) * f[2] + (n - 1) * f[3]) % mod;
            g[3] = (f[1] + f[2] + (n - 2) * f[3] + (m - 2) * f[3]) % mod;
            f = g;
        }
        if (source[0] == dest[0]) {
            return source[1] == dest[1] ? (int) f[0] : (int) f[2];
        }
        return source[1] == dest[1] ? (int) f[1] : (int) f[3];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        const int mod = 1e9 + 7;
        vector<long long> f(4);
        f[0] = 1;
        while (k--) {
            vector<long long> g(4);
            g[0] = ((n - 1) * f[1] + (m - 1) * f[2]) % mod;
            g[1] = (f[0] + (n - 2) * f[1] + (m - 1) * f[3]) % mod;
            g[2] = (f[0] + (m - 2) * f[2] + (n - 1) * f[3]) % mod;
            g[3] = (f[1] + f[2] + (n - 2) * f[3] + (m - 2) * f[3]) % mod;
            f = move(g);
        }
        if (source[0] == dest[0]) {
            return source[1] == dest[1] ? f[0] : f[2];
        }
        return source[1] == dest[1] ? f[1] : f[3];
    }
};
```

#### Go

```go
func numberOfWays(n int, m int, k int, source []int, dest []int) int {
	const mod int = 1e9 + 7
	f := []int{1, 0, 0, 0}
	for i := 0; i < k; i++ {
		g := make([]int, 4)
		g[0] = ((n-1)*f[1] + (m-1)*f[2]) % mod
		g[1] = (f[0] + (n-2)*f[1] + (m-1)*f[3]) % mod
		g[2] = (f[0] + (m-2)*f[2] + (n-1)*f[3]) % mod
		g[3] = (f[1] + f[2] + (n-2)*f[3] + (m-2)*f[3]) % mod
		f = g
	}

	if source[0] == dest[0] {
		if source[1] == dest[1] {
			return f[0]
		}
		return f[2]
	}

	if source[1] == dest[1] {
		return f[1]
	}
	return f[3]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2913. 子数组不同元素数目的平方和 I](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-i){#2913}

{{< tabs "2913" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                ans += len(s) * len(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumCounts(List<Integer> nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int[] s = new int[101];
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (++s[nums.get(j)] == 1) {
                    ++cnt;
                }
                ans += cnt * cnt;
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
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int s[101]{};
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (++s[nums[j]] == 1) {
                    ++cnt;
                }
                ans += cnt * cnt;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumCounts(nums []int) (ans int) {
	for i := range nums {
		s := [101]int{}
		cnt := 0
		for _, x := range nums[i:] {
			s[x]++
			if s[x] == 1 {
				cnt++
			}
			ans += cnt * cnt
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumCounts(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        const s: number[] = Array(101).fill(0);
        let cnt = 0;
        for (const x of nums.slice(i)) {
            if (++s[x] === 1) {
                ++cnt;
            }
            ans += cnt * cnt;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>定义 <code>nums</code>&nbsp;一个子数组的 <strong>不同计数</strong>&nbsp;值如下：</p>

<ul>
	<li>令&nbsp;<code>nums[i..j]</code>&nbsp;表示 <code>nums</code> 中所有下标在 <code>i</code> 到 <code>j</code> 范围内的元素构成的子数组（满足 <code>0 &lt;= i &lt;= j &lt; nums.length</code> ），那么我们称子数组&nbsp;<code>nums[i..j]</code>&nbsp;中不同值的数目为&nbsp;<code>nums[i..j]</code>&nbsp;的不同计数。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中所有子数组的 <strong>不同计数</strong>&nbsp;的 <strong>平方</strong>&nbsp;和。</p>

<p>由于答案可能会很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>子数组指的是一个数组里面一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1]
<b>输出：</b>15
<b>解释：</b>六个子数组分别为：
[1]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[1]: 1 个互不相同的元素。
[1,2]: 2 个互不相同的元素。
[2,1]: 2 个互不相同的元素。
[1,2,1]: 2 个互不相同的元素。
所有不同计数的平方和为 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> = 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,2]
<b>输出：3</b>
<strong>解释：</strong>三个子数组分别为：
[2]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[2,2]: 1 个互不相同的元素。
所有不同计数的平方和为 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举子数组的左端点下标 $i$，对于每个 $i$，我们在 $[i, n)$ 的范围内枚举子数组的右端点下标 $j$，并统计 $nums[j]$ 的值，将其加入到集合 $s$ 中，记 $s$ 的大小为 $cnt$，那么 $nums[i..j]$ 的不同计数为 $cnt$，将其平方后加入到答案中。

枚举结束后，返回答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        for i in range(n):
            s = set()
            for j in range(i, n):
                s.add(nums[j])
                ans += len(s) * len(s)
        return ans
```

#### Java

```java
class Solution {
    public int sumCounts(List<Integer> nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int[] s = new int[101];
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (++s[nums.get(j)] == 1) {
                    ++cnt;
                }
                ans += cnt * cnt;
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
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int s[101]{};
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                if (++s[nums[j]] == 1) {
                    ++cnt;
                }
                ans += cnt * cnt;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func sumCounts(nums []int) (ans int) {
	for i := range nums {
		s := [101]int{}
		cnt := 0
		for _, x := range nums[i:] {
			s[x]++
			if s[x] == 1 {
				cnt++
			}
			ans += cnt * cnt
		}
	}
	return
}
```

#### TypeScript

```ts
function sumCounts(nums: number[]): number {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        const s: number[] = Array(101).fill(0);
        let cnt = 0;
        for (const x of nums.slice(i)) {
            if (++s[x] === 1) {
                ++cnt;
            }
            ans += cnt * cnt;
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

# [2914. 使二进制字符串变美丽的最少修改次数](https://leetcode.cn/problems/minimum-number-of-changes-to-make-binary-string-beautiful){#2914}

{{< tabs "2914" >}}

{{% tab "python" %}}
```python
class Solution:
    def minChanges(self, s: str) -> int:
        return sum(s[i] != s[i - 1] for i in range(1, len(s), 2))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i += 2) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ++ans;
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
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minChanges(s string) (ans int) {
	for i := 1; i < len(s); i += 2 {
		if s[i] != s[i-1] {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minChanges(s: string): number {
    let ans = 0;
    for (let i = 1; i < s.length; i += 2) {
        if (s[i] !== s[i - 1]) {
            ++ans;
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

<p>给你一个长度为偶数下标从 <strong>0</strong>&nbsp;开始的二进制字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>如果可以将一个字符串分割成一个或者更多满足以下条件的子字符串，那么我们称这个字符串是 <strong>美丽的</strong>&nbsp;：</p>

<ul>
	<li>每个子字符串的长度都是 <strong>偶数</strong>&nbsp;。</li>
	<li>每个子字符串都 <strong>只</strong>&nbsp;包含 <code>1</code>&nbsp;或 <strong>只</strong>&nbsp;包含 <code>0</code>&nbsp;。</li>
</ul>

<p>你可以将 <code>s</code>&nbsp;中任一字符改成&nbsp;<code>0</code>&nbsp;或者&nbsp;<code>1</code>&nbsp;。</p>

<p>请你返回让字符串 <code>s</code>&nbsp;美丽的<strong>&nbsp;最少</strong>&nbsp;字符修改次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "1001"
<b>输出：</b>2
<b>解释：</b>我们将 s[1] 改为 1 ，且将 s[3] 改为 0 ，得到字符串 "1100" 。
字符串 "1100" 是美丽的，因为我们可以将它分割成 "11|00" 。
将字符串变美丽最少需要 2 次修改。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "10"
<b>输出：</b>1
<b>解释：</b>我们将 s[1] 改为 1 ，得到字符串 "11" 。
字符串 "11" 是美丽的，因为它已经是美丽的。
将字符串变美丽最少需要 1 次修改。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>s = "0000"
<b>输出：</b>0
<b>解释：</b>不需要进行任何修改，字符串 "0000" 已经是美丽字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;的长度为偶数。</li>
	<li><code>s[i]</code>&nbsp;要么是&nbsp;<code>'0'</code>&nbsp;，要么是&nbsp;<code>'1'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们只需要遍历字符串 $s$ 的所有奇数下标 $1, 3, 5, \cdots$，如果当前奇数下标与前一个下标的字符不同，即 $s[i] \ne s[i - 1]$，那么就需要修改当前字符，使得 $s[i] = s[i - 1]$。因此，此时答案需要加 $1$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minChanges(self, s: str) -> int:
        return sum(s[i] != s[i - 1] for i in range(1, len(s), 2))
```

#### Java

```java
class Solution {
    public int minChanges(String s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i += 2) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                ++ans;
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
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i += 2) {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }
};
```

#### Go

```go
func minChanges(s string) (ans int) {
	for i := 1; i < len(s); i += 2 {
		if s[i] != s[i-1] {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function minChanges(s: string): number {
    let ans = 0;
    for (let i = 1; i < s.length; i += 2) {
        if (s[i] !== s[i - 1]) {
            ++ans;
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

# [2915. 和为目标值的最长子序列的长度](https://leetcode.cn/problems/length-of-the-longest-subsequence-that-sums-to-target){#2915}

{{< tabs "2915" >}}

{{% tab "python" %}}
```python
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        f = [0] + [-inf] * target
        for x in nums:
            for j in range(target, x - 1, -1):
                f[j] = max(f[j], f[j - x] + 1)
        return -1 if f[-1] <= 0 else f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int[] f = new int[target + 1];
        final int inf = 1 << 30;
        Arrays.fill(f, -inf);
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = Math.max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int f[target + 1];
        memset(f, -0x3f, sizeof(f));
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lengthOfLongestSubsequence(nums []int, target int) int {
	f := make([]int, target+1)
	for i := range f {
		f[i] = -(1 << 30)
	}
	f[0] = 0
	for _, x := range nums {
		for j := target; j >= x; j-- {
			f[j] = max(f[j], f[j-x]+1)
		}
	}
	if f[target] <= 0 {
		return -1
	}
	return f[target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lengthOfLongestSubsequence(nums: number[], target: number): number {
    const f: number[] = Array(target + 1).fill(-Infinity);
    f[0] = 0;
    for (const x of nums) {
        for (let j = target; j >= x; --j) {
            f[j] = Math.max(f[j], f[j - x] + 1);
        }
    }
    return f[target] <= 0 ? -1 : f[target];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>target</code>&nbsp;。</p>

<p>返回和为 <code>target</code>&nbsp;的 <code>nums</code>&nbsp;子序列中，子序列&nbsp;<strong>长度的最大值&nbsp;</strong>。如果不存在和为 <code>target</code>&nbsp;的子序列，返回 <code>-1</code>&nbsp;。</p>

<p><strong>子序列</strong> 指的是从原数组中删除一些或者不删除任何元素后，剩余元素保持原来的顺序构成的数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5], target = 9
<b>输出：</b>3
<b>解释：</b>总共有 3 个子序列的和为 9 ：[4,5] ，[1,3,5] 和 [2,3,4] 。最长的子序列是 [1,3,5] 和 [2,3,4] 。所以答案为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [4,1,3,2,1,5], target = 7
<b>输出：</b>4
<strong>解释：</strong>总共有 5 个子序列的和为 7 ：[4,3] ，[4,1,2] ，[4,2,1] ，[1,1,5] 和 [1,3,2,1] 。最长子序列为 [1,3,2,1] 。所以答案为 4 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,1,5,4,5], target = 3
<b>输出：</b>-1
<b>解释：</b>无法得到和为 3 的子序列。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示前 $i$ 个数中选取若干个数，使得这若干个数的和恰好为 $j$ 的最长子序列的长度。初始时 $f[0][0]=0$，其余位置均为 $-\infty$。

对于 $f[i][j]$，我们考虑第 $i$ 个数 $x$，如果不选取 $x$，那么 $f[i][j]=f[i-1][j]$；如果选取 $x$，那么 $f[i][j]=f[i-1][j-x]+1$，其中 $j\ge x$。因此我们有状态转移方程：

$$
f[i][j]=\max\{f[i-1][j],f[i-1][j-x]+1\}
$$

最终答案为 $f[n][target]$，如果 $f[n][target]\le0$，则不存在和为 $target$ 的子序列，返回 $-1$。

时间复杂度 $O(n\times target)$，空间复杂度 $O(n\times target)$。其中 $n$ 为数组长度，而 $target$ 为目标值。

我们注意到 $f[i][j]$ 的状态只与 $f[i-1][\cdot]$ 有关，因此我们可以优化掉第一维，将空间复杂度优化到 $O(target)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        n = len(nums)
        f = [[-inf] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i, x in enumerate(nums, 1):
            for j in range(target + 1):
                f[i][j] = f[i - 1][j]
                if j >= x:
                    f[i][j] = max(f[i][j], f[i - 1][j - x] + 1)
        return -1 if f[n][target] <= 0 else f[n][target]
```

#### Java

```java
class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int n = nums.size();
        int[][] f = new int[n + 1][target + 1];
        final int inf = 1 << 30;
        for (int[] g : f) {
            Arrays.fill(g, -inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            int x = nums.get(i - 1);
            for (int j = 0; j <= target; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= x) {
                    f[i][j] = Math.max(f[i][j], f[i - 1][j - x] + 1);
                }
            }
        }
        return f[n][target] <= 0 ? -1 : f[n][target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        int f[n + 1][target + 1];
        memset(f, -0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            for (int j = 0; j <= target; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= x) {
                    f[i][j] = max(f[i][j], f[i - 1][j - x] + 1);
                }
            }
        }
        return f[n][target] <= 0 ? -1 : f[n][target];
    }
};
```

#### Go

```go
func lengthOfLongestSubsequence(nums []int, target int) int {
	n := len(nums)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, target+1)
		for j := range f[i] {
			f[i][j] = -(1 << 30)
		}
	}
	f[0][0] = 0
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		for j := 0; j <= target; j++ {
			f[i][j] = f[i-1][j]
			if j >= x {
				f[i][j] = max(f[i][j], f[i-1][j-x]+1)
			}
		}
	}
	if f[n][target] <= 0 {
		return -1
	}
	return f[n][target]
}
```

#### TypeScript

```ts
function lengthOfLongestSubsequence(nums: number[], target: number): number {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(target + 1).fill(-Infinity));
    f[0][0] = 0;
    for (let i = 1; i <= n; ++i) {
        const x = nums[i - 1];
        for (let j = 0; j <= target; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= x) {
                f[i][j] = Math.max(f[i][j], f[i - 1][j - x] + 1);
            }
        }
    }
    return f[n][target] <= 0 ? -1 : f[n][target];
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
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        f = [0] + [-inf] * target
        for x in nums:
            for j in range(target, x - 1, -1):
                f[j] = max(f[j], f[j - x] + 1)
        return -1 if f[-1] <= 0 else f[-1]
```

#### Java

```java
class Solution {
    public int lengthOfLongestSubsequence(List<Integer> nums, int target) {
        int[] f = new int[target + 1];
        final int inf = 1 << 30;
        Arrays.fill(f, -inf);
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = Math.max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int f[target + 1];
        memset(f, -0x3f, sizeof(f));
        f[0] = 0;
        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                f[j] = max(f[j], f[j - x] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
};
```

#### Go

```go
func lengthOfLongestSubsequence(nums []int, target int) int {
	f := make([]int, target+1)
	for i := range f {
		f[i] = -(1 << 30)
	}
	f[0] = 0
	for _, x := range nums {
		for j := target; j >= x; j-- {
			f[j] = max(f[j], f[j-x]+1)
		}
	}
	if f[target] <= 0 {
		return -1
	}
	return f[target]
}
```

#### TypeScript

```ts
function lengthOfLongestSubsequence(nums: number[], target: number): number {
    const f: number[] = Array(target + 1).fill(-Infinity);
    f[0] = 0;
    for (const x of nums) {
        for (let j = target; j >= x; --j) {
            f[j] = Math.max(f[j], f[j - x] + 1);
        }
    }
    return f[target] <= 0 ? -1 : f[target];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2916. 子数组不同元素数目的平方和 II](https://leetcode.cn/problems/subarrays-distinct-element-sum-of-squares-ii){#2916}

{{< tabs "2916" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>定义 <code>nums</code>&nbsp;一个子数组的 <strong>不同计数</strong>&nbsp;值如下：</p>

<ul>
	<li>令&nbsp;<code>nums[i..j]</code>&nbsp;表示 <code>nums</code> 中所有下标在 <code>i</code> 到 <code>j</code> 范围内的元素构成的子数组（满足 <code>0 &lt;= i &lt;= j &lt; nums.length</code> ），那么我们称子数组&nbsp;<code>nums[i..j]</code>&nbsp;中不同值的数目为&nbsp;<code>nums[i..j]</code>&nbsp;的不同计数。</li>
</ul>

<p>请你返回 <code>nums</code>&nbsp;中所有子数组的 <strong>不同计数</strong>&nbsp;的 <strong>平方</strong>&nbsp;和。</p>

<p>由于答案可能会很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>子数组指的是一个数组里面一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1]
<b>输出：</b>15
<b>解释：</b>六个子数组分别为：
[1]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[1]: 1 个互不相同的元素。
[1,2]: 2 个互不相同的元素。
[2,1]: 2 个互不相同的元素。
[1,2,1]: 2 个互不相同的元素。
所有不同计数的平方和为 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> + 2<sup>2</sup> = 15 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,2]
<b>输出：3</b>
<strong>解释：</strong>三个子数组分别为：
[2]: 1 个互不相同的元素。
[2]: 1 个互不相同的元素。
[2,2]: 1 个互不相同的元素。
所有不同计数的平方和为 1<sup>2</sup> + 1<sup>2</sup> + 1<sup>2</sup> = 3 。
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

### 方法一

<!-- tabs:start -->

#### Python3

```python

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2917. 找出数组中的 K-or 值](https://leetcode.cn/problems/find-the-k-or-of-an-array){#2917}

{{< tabs "2917" >}}

{{% tab "python" %}}
```python
class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(32):
            cnt = sum(x >> i & 1 for x in nums)
            if cnt >= k:
                ans |= 1 << i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findKOr(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= 1 << i;
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
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findKOr(nums []int, k int) (ans int) {
	for i := 0; i < 32; i++ {
		cnt := 0
		for _, x := range nums {
			cnt += (x >> i & 1)
		}
		if cnt >= k {
			ans |= 1 << i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findKOr(nums: number[], k: number): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        let cnt = 0;
        for (const x of nums) {
            cnt += (x >> i) & 1;
        }
        if (cnt >= k) {
            ans |= 1 << i;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int FindKOr(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            foreach (int x in nums) {
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。让我们通过扩展标准的按位或来介绍 <strong>K-or</strong> 操作。在 K-or 操作中，如果在 <code>nums</code> 中，至少存在 <code>k</code> 个元素的第 <code>i</code> 位值为 1 ，那么 K-or 中的第 <code>i</code> 位的值是 1 。</p>

<p>返回 <code>nums</code> 的 <strong>K-or</strong> 值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,12,9,8,9,15], k = 4
<strong>输出：</strong>9
<strong>解释：</strong>
用二进制表示 numbers：
</pre>

<table style="text-indent:10px; margin-bottom=20px;">
	<tbody>
		<tr>
			<th><b>Number</b></th>
			<th>Bit 3</th>
			<th>Bit 2</th>
			<th>Bit 1</th>
			<th>Bit 0</th>
		</tr>
		<tr>
			<td><b>7</b></td>
			<td>0</td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>12</b></td>
			<td>1</td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td><b>9</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>8</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>0</td>
		</tr>
		<tr>
			<td><b>9</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>15</b></td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td><b>Result = 9</b></td>
			<td>1</td>
			<td>0</td>
			<td>0</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<pre>
位 0 在 7, 9, 9, 15 中为 1。位 3 在 12, 9, 8, 9, 15 中为 1。 只有位 0 和 3 满足。结果是 (1001)<sub>2</sub> = 9。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,12,1,11,4,5], k = 6
<strong>输出：</strong>0
<strong>解释：</strong>没有位在所有 6 个数字中都为 1，如 k = 6 所需要的。所以，答案为 0。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,8,5,9,11,6,8], k = 1
<strong>输出：</strong>15
<strong>解释：</strong>因为 k == 1 ，数组的 1-or 等于其中所有元素按位或运算的结果。因此，答案为 10 OR 8 OR 5 OR 9 OR 11 OR 6 OR 8 = 15 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt; 2<sup>31</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以在 $[0, 32)$ 范围内枚举每一位 $i$，统计数组 $nums$ 有多少个数的第 $i$ 位为 $1$，记为 $cnt$。如果 $cnt \ge k$，那么我们就将 $2^i$ 次方加到答案中。

枚举结束后，返回答案即可。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度以及 $nums$ 的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(32):
            cnt = sum(x >> i & 1 for x in nums)
            if cnt >= k:
                ans |= 1 << i
        return ans
```

#### Java

```java
class Solution {
    public int findKOr(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= 1 << i;
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
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findKOr(nums []int, k int) (ans int) {
	for i := 0; i < 32; i++ {
		cnt := 0
		for _, x := range nums {
			cnt += (x >> i & 1)
		}
		if cnt >= k {
			ans |= 1 << i
		}
	}
	return
}
```

#### TypeScript

```ts
function findKOr(nums: number[], k: number): number {
    let ans = 0;
    for (let i = 0; i < 32; ++i) {
        let cnt = 0;
        for (const x of nums) {
            cnt += (x >> i) & 1;
        }
        if (cnt >= k) {
            ans |= 1 << i;
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int FindKOr(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            foreach (int x in nums) {
                cnt += (x >> i & 1);
            }
            if (cnt >= k) {
                ans |= 1 << i;
            }
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

# [2918. 数组的最小相等和](https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros){#2918}

{{< tabs "2918" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = sum(nums1) + nums1.count(0)
        s2 = sum(nums2) + nums2.count(0)
        if s1 > s2:
            return self.minSum(nums2, nums1)
        if s1 == s2:
            return s1
        return -1 if nums1.count(0) == 0 else s2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0;
        boolean hasZero = false;
        for (int x : nums1) {
            hasZero |= x == 0;
            s1 += Math.max(x, 1);
        }
        for (int x : nums2) {
            s2 += Math.max(x, 1);
        }
        if (s1 > s2) {
            return minSum(nums2, nums1);
        }
        if (s1 == s2) {
            return s1;
        }
        return hasZero ? s2 : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        bool hasZero = false;
        for (int x : nums1) {
            hasZero |= x == 0;
            s1 += max(x, 1);
        }
        for (int x : nums2) {
            s2 += max(x, 1);
        }
        if (s1 > s2) {
            return minSum(nums2, nums1);
        }
        if (s1 == s2) {
            return s1;
        }
        return hasZero ? s2 : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSum(nums1 []int, nums2 []int) int64 {
	s1, s2 := 0, 0
	hasZero := false
	for _, x := range nums1 {
		if x == 0 {
			hasZero = true
		}
		s1 += max(x, 1)
	}
	for _, x := range nums2 {
		s2 += max(x, 1)
	}
	if s1 > s2 {
		return minSum(nums2, nums1)
	}
	if s1 == s2 {
		return int64(s1)
	}
	if hasZero {
		return int64(s2)
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSum(nums1: number[], nums2: number[]): number {
    let [s1, s2] = [0, 0];
    let hasZero = false;
    for (const x of nums1) {
        if (x === 0) {
            hasZero = true;
        }
        s1 += Math.max(x, 1);
    }
    for (const x of nums2) {
        s2 += Math.max(x, 1);
    }
    if (s1 > s2) {
        return minSum(nums2, nums1);
    }
    if (s1 === s2) {
        return s1;
    }
    return hasZero ? s2 : -1;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public long MinSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0;
        bool hasZero = false;
        foreach (int x in nums1) {
            hasZero |= x == 0;
            s1 += Math.Max(x, 1);
        }
        foreach (int x in nums2) {
            s2 += Math.Max(x, 1);
        }
        if (s1 > s2) {
            return MinSum(nums2, nums1);
        }
        if (s1 == s2) {
            return s1;
        }
        return hasZero ? s2 : -1;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个由正整数和 <code>0</code> 组成的数组 <code>nums1</code> 和 <code>nums2</code> 。</p>

<p>你必须将两个数组中的<strong> 所有</strong> <code>0</code> 替换为 <strong>严格</strong> 正整数，并且满足两个数组中所有元素的和 <strong>相等</strong> 。</p>

<p>返回 <strong>最小</strong> 相等和 ，如果无法使两数组相等，则返回 <code>-1</code><em> </em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,2,0,1,0], nums2 = [6,5,0]
<strong>输出：</strong>12
<strong>解释：</strong>可以按下述方式替换数组中的 0 ：
- 用 2 和 4 替换 nums1 中的两个 0 。得到 nums1 = [3,2,2,1,4] 。
- 用 1 替换 nums2 中的一个 0 。得到 nums2 = [6,5,1] 。
两个数组的元素和相等，都等于 12 。可以证明这是可以获得的最小相等和。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [2,0,2,0], nums2 = [1,4]
<strong>输出：</strong>-1
<strong>解释：</strong>无法使两个数组的和相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

我们记把数组中的 $0$ 视为 $1$，统计两个数组的和，分别记为 $s_1$ 和 $s_2$。不妨设 $s_1 \le s_2$。

-   如果 $s_1 = s_2$，那么答案就是 $s_1$。
-   如果 $s_1 \lt s_2$，那么 $nums1$ 中必须存在 $0$，才能使得两个数组的和相等，此时的答案就是 $s_2$。否则，说明无法使两个数组的和相等，返回 $-1$。

时间复杂度 $O(n + m)$，其中 $n$ 和 $m$ 分别是数组 $nums1$ 和 $nums2$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1 = sum(nums1) + nums1.count(0)
        s2 = sum(nums2) + nums2.count(0)
        if s1 > s2:
            return self.minSum(nums2, nums1)
        if s1 == s2:
            return s1
        return -1 if nums1.count(0) == 0 else s2
```

#### Java

```java
class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0;
        boolean hasZero = false;
        for (int x : nums1) {
            hasZero |= x == 0;
            s1 += Math.max(x, 1);
        }
        for (int x : nums2) {
            s2 += Math.max(x, 1);
        }
        if (s1 > s2) {
            return minSum(nums2, nums1);
        }
        if (s1 == s2) {
            return s1;
        }
        return hasZero ? s2 : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        bool hasZero = false;
        for (int x : nums1) {
            hasZero |= x == 0;
            s1 += max(x, 1);
        }
        for (int x : nums2) {
            s2 += max(x, 1);
        }
        if (s1 > s2) {
            return minSum(nums2, nums1);
        }
        if (s1 == s2) {
            return s1;
        }
        return hasZero ? s2 : -1;
    }
};
```

#### Go

```go
func minSum(nums1 []int, nums2 []int) int64 {
	s1, s2 := 0, 0
	hasZero := false
	for _, x := range nums1 {
		if x == 0 {
			hasZero = true
		}
		s1 += max(x, 1)
	}
	for _, x := range nums2 {
		s2 += max(x, 1)
	}
	if s1 > s2 {
		return minSum(nums2, nums1)
	}
	if s1 == s2 {
		return int64(s1)
	}
	if hasZero {
		return int64(s2)
	}
	return -1
}
```

#### TypeScript

```ts
function minSum(nums1: number[], nums2: number[]): number {
    let [s1, s2] = [0, 0];
    let hasZero = false;
    for (const x of nums1) {
        if (x === 0) {
            hasZero = true;
        }
        s1 += Math.max(x, 1);
    }
    for (const x of nums2) {
        s2 += Math.max(x, 1);
    }
    if (s1 > s2) {
        return minSum(nums2, nums1);
    }
    if (s1 === s2) {
        return s1;
    }
    return hasZero ? s2 : -1;
}
```

#### C#

```cs
public class Solution {
    public long MinSum(int[] nums1, int[] nums2) {
        long s1 = 0, s2 = 0;
        bool hasZero = false;
        foreach (int x in nums1) {
            hasZero |= x == 0;
            s1 += Math.Max(x, 1);
        }
        foreach (int x in nums2) {
            s2 += Math.Max(x, 1);
        }
        if (s1 > s2) {
            return MinSum(nums2, nums1);
        }
        if (s1 == s2) {
            return s1;
        }
        return hasZero ? s2 : -1;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2919. 使数组变美的最小增量运算数](https://leetcode.cn/problems/minimum-increment-operations-to-make-array-beautiful){#2919}

{{< tabs "2919" >}}

{{% tab "python" %}}
```python
class Solution:
    def minIncrementOperations(self, nums: List[int], k: int) -> int:
        f = g = h = 0
        for x in nums:
            f, g, h = g, h, min(f, g, h) + max(k - x, 0)
        return min(f, g, h)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minIncrementOperations(int[] nums, int k) {
        long f = 0, g = 0, h = 0;
        for (int x : nums) {
            long hh = Math.min(Math.min(f, g), h) + Math.max(k - x, 0);
            f = g;
            g = h;
            h = hh;
        }
        return Math.min(Math.min(f, g), h);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long f = 0, g = 0, h = 0;
        for (int x : nums) {
            long long hh = min({f, g, h}) + max(k - x, 0);
            f = g;
            g = h;
            h = hh;
        }
        return min({f, g, h});
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minIncrementOperations(nums []int, k int) int64 {
	var f, g, h int
	for _, x := range nums {
		f, g, h = g, h, min(f, g, h)+max(k-x, 0)
	}
	return int64(min(f, g, h))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minIncrementOperations(nums: number[], k: number): number {
    let [f, g, h] = [0, 0, 0];
    for (const x of nums) {
        [f, g, h] = [g, h, Math.min(f, g, h) + Math.max(k - x, 0)];
    }
    return Math.min(f, g, h);
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public long MinIncrementOperations(int[] nums, int k) {
        long f = 0, g = 0, h = 0;
        foreach (int x in nums) {
            long hh = Math.Min(Math.Min(f, g), h) + Math.Max(k - x, 0);
            f = g;
            g = h;
            h = hh;
        }
        return Math.Min(Math.Min(f, g), h);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、长度为 <code>n</code> 的整数数组 <code>nums</code> ，和一个整数 <code>k</code> 。</p>

<p>你可以执行下述 <strong>递增</strong> 运算 <strong>任意</strong> 次（可以是 <strong>0</strong> 次）：</p>

<ul>
	<li>从范围&nbsp;<code>[0, n - 1]</code> 中选择一个下标 <code>i</code> ，并将 <code>nums[i]</code> 的值加 <code>1</code> 。</li>
</ul>

<p>如果数组中任何长度 <strong>大于或等于 3</strong> 的子数组，其 <strong>最大</strong> 元素都大于或等于 <code>k</code> ，则认为数组是一个 <strong>美丽数组</strong> 。</p>

<p>以整数形式返回使数组变为 <strong>美丽数组</strong> 需要执行的 <strong>最小</strong> 递增运算数。</p>

<p>子数组是数组中的一个连续 <strong>非空</strong> 元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,3,0,0,2], k = 4
<strong>输出：</strong>3
<strong>解释：</strong>可以执行下述递增运算，使 nums 变为美丽数组：
选择下标 i = 1 ，并且将 nums[1] 的值加 1 -&gt; [2,4,0,0,2] 。
选择下标 i = 4 ，并且将 nums[4] 的值加 1 -&gt; [2,4,0,0,3] 。
选择下标 i = 4 ，并且将 nums[4] 的值加 1 -&gt; [2,4,0,0,4] 。
长度大于或等于 3 的子数组为 [2,4,0], [4,0,0], [0,0,4], [2,4,0,0], [4,0,0,4], [2,4,0,0,4] 。
在所有子数组中，最大元素都等于 k = 4 ，所以 nums 现在是美丽数组。
可以证明无法用少于 3 次递增运算使 nums 变为美丽数组。
因此，答案为 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,3,3], k = 5
<strong>输出：</strong>2
<strong>解释：</strong>可以执行下述递增运算，使 nums 变为美丽数组：
选择下标 i = 2 ，并且将 nums[2] 的值加 1 -&gt; [0,1,4,3] 。
选择下标 i = 2 ，并且将 nums[2] 的值加 1 -&gt; [0,1,5,3] 。
长度大于或等于 3 的子数组为 [0,1,5]、[1,5,3]、[0,1,5,3] 。
在所有子数组中，最大元素都等于 k = 5 ，所以 nums 现在是美丽数组。
可以证明无法用少于 2 次递增运算使 nums 变为美丽数组。 
因此，答案为 2 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2], k = 1
<strong>输出：</strong>0
<strong>解释：</strong>在这个示例中，只有一个长度大于或等于 3 的子数组 [1,1,2] 。
其最大元素 2 已经大于 k = 1 ，所以无需执行任何增量运算。
因此，答案为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f$, $g$, $h$ 表示前 $i$ 项中，分别以最后三项作为子数组的最大值所需要的最小增量运算数，初始时 $f = 0$, $g = 0$, $h = 0$。

接下来，我们遍历数组 $nums$，对于每个 $x$，我们需要更新 $f$, $g$, $h$ 的值，使其满足题目要求，即：

$$
\begin{aligned}
f' &= g \\
g' &= h \\
h' &= \min(f, g, h) + \max(k - x, 0)
\end{aligned}
$$

最后，我们只需要返回 $f$, $g$, $h$ 中的最小值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minIncrementOperations(self, nums: List[int], k: int) -> int:
        f = g = h = 0
        for x in nums:
            f, g, h = g, h, min(f, g, h) + max(k - x, 0)
        return min(f, g, h)
```

#### Java

```java
class Solution {
    public long minIncrementOperations(int[] nums, int k) {
        long f = 0, g = 0, h = 0;
        for (int x : nums) {
            long hh = Math.min(Math.min(f, g), h) + Math.max(k - x, 0);
            f = g;
            g = h;
            h = hh;
        }
        return Math.min(Math.min(f, g), h);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long f = 0, g = 0, h = 0;
        for (int x : nums) {
            long long hh = min({f, g, h}) + max(k - x, 0);
            f = g;
            g = h;
            h = hh;
        }
        return min({f, g, h});
    }
};
```

#### Go

```go
func minIncrementOperations(nums []int, k int) int64 {
	var f, g, h int
	for _, x := range nums {
		f, g, h = g, h, min(f, g, h)+max(k-x, 0)
	}
	return int64(min(f, g, h))
}
```

#### TypeScript

```ts
function minIncrementOperations(nums: number[], k: number): number {
    let [f, g, h] = [0, 0, 0];
    for (const x of nums) {
        [f, g, h] = [g, h, Math.min(f, g, h) + Math.max(k - x, 0)];
    }
    return Math.min(f, g, h);
}
```

#### C#

```cs
public class Solution {
    public long MinIncrementOperations(int[] nums, int k) {
        long f = 0, g = 0, h = 0;
        foreach (int x in nums) {
            long hh = Math.Min(Math.Min(f, g), h) + Math.Max(k - x, 0);
            f = g;
            g = h;
            h = hh;
        }
        return Math.Min(Math.Min(f, g), h);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
