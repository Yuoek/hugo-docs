---
title: "2260_必须拿起的最小连续卡牌数"
date: 2025-10-08T18:39:07+08:00
weight: 7
tags: [二叉树, 动态规划, 哈希函数, 哈希表, 字典树, 字符串, 排序, 数学, 数组, 枚举, 树, 深度优先搜索, 滑动窗口, 滚动哈希, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [2260_必须拿起的最小连续卡牌数](#2260)
#### [数组](#2260)
#### [哈希表](#2260)
#### [滑动窗口](#2260)
### [2261_含最多 K 个可整除元素的子数组](#2261)
#### [字典树](#2261)
#### [数组](#2261)
#### [哈希表](#2261)
#### [枚举](#2261)
#### [哈希函数](#2261)
#### [滚动哈希](#2261)
### [2262_字符串的总引力](#2262)
#### [哈希表](#2262)
#### [字符串](#2262)
#### [动态规划](#2262)
### [2263_数组变为有序的最小操作次数 🔒](#2263)
#### [贪心](#2263)
#### [动态规划](#2263)
### [2264_字符串中最大的 3 位相同数字](#2264)
#### [字符串](#2264)
### [2265_统计值等于子树平均值的节点数](#2265)
#### [树](#2265)
#### [深度优先搜索](#2265)
#### [二叉树](#2265)
### [2266_统计打字方案数](#2266)
#### [哈希表](#2266)
#### [数学](#2266)
#### [字符串](#2266)
#### [动态规划](#2266)
### [2267_检查是否有合法括号字符串路径](#2267)
#### [数组](#2267)
#### [动态规划](#2267)
#### [矩阵](#2267)
### [2268_最少按键次数 🔒](#2268)
#### [贪心](#2268)
#### [哈希表](#2268)
#### [字符串](#2268)
#### [计数](#2268)
#### [排序](#2268)
### [2269_找到一个数字的 K 美丽值](#2269)
#### [数学](#2269)
#### [字符串](#2269)
#### [滑动窗口](#2269)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2260_必须拿起的最小连续卡牌数
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2261_含最多 K 个可整除元素的子数组
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 枚举
___
#### 哈希函数
___
#### 滚动哈希
---
### 2262_字符串的总引力
___
#### 哈希表
___
#### 字符串
___
#### 动态规划
---
### 2263_数组变为有序的最小操作次数 🔒
___
#### 贪心
___
#### 动态规划
---
### 2264_字符串中最大的 3 位相同数字
___
#### 字符串
---
### 2265_统计值等于子树平均值的节点数
___
#### 树
___
#### 深度优先搜索
___
#### 二叉树
---
### 2266_统计打字方案数
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 动态规划
---
### 2267_检查是否有合法括号字符串路径
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 2268_最少按键次数 🔒
___
#### 贪心
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
---
### 2269_找到一个数字的 K 美丽值
___
#### 数学
___
#### 字符串
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 动态规划 | 哈希函数 |
| 哈希表 | 字典树 | 字符串 |
| 排序 | 数学 | 数组 |
| 枚举 | 树 | 深度优先搜索 |
| 滑动窗口 | 滚动哈希 | 矩阵 |
| 计数 | 贪心 |  |

# [2260. 必须拿起的最小连续卡牌数](https://leetcode.cn/problems/minimum-consecutive-cards-to-pick-up){#2260}

{{< tabs "2260" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last = {}
        ans = inf
        for i, x in enumerate(cards):
            if x in last:
                ans = min(ans, i - last[x] + 1)
            last[x] = i
        return -1 if ans == inf else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCardPickup(int[] cards) {
        Map<Integer, Integer> last = new HashMap<>();
        int n = cards.length;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            if (last.containsKey(cards[i])) {
                ans = Math.min(ans, i - last.get(cards[i]) + 1);
            }
            last.put(cards[i], i);
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
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last;
        int n = cards.size();
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            if (last.count(cards[i])) {
                ans = min(ans, i - last[cards[i]] + 1);
            }
            last[cards[i]] = i;
        }
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCardPickup(cards []int) int {
	last := map[int]int{}
	n := len(cards)
	ans := n + 1
	for i, x := range cards {
		if j, ok := last[x]; ok && ans > i-j+1 {
			ans = i - j + 1
		}
		last[x] = i
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
function minimumCardPickup(cards: number[]): number {
    const n = cards.length;
    const last = new Map<number, number>();
    let ans = n + 1;
    for (let i = 0; i < n; ++i) {
        if (last.has(cards[i])) {
            ans = Math.min(ans, i - last.get(cards[i]) + 1);
        }
        last.set(cards[i], i);
    }
    return ans > n ? -1 : ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>cards</code> ，其中 <code>cards[i]</code> 表示第 <code>i</code> 张卡牌的 <strong>值</strong> 。如果两张卡牌的值相同，则认为这一对卡牌 <strong>匹配</strong> 。</p>

<p>返回你必须拿起的最小连续卡牌数，以使在拿起的卡牌中有一对匹配的卡牌。如果无法得到一对匹配的卡牌，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>cards = [3,4,2,3,4,7]
<strong>输出：</strong>4
<strong>解释：</strong>拿起卡牌 [3,4,2,3] 将会包含一对值为 3 的匹配卡牌。注意，拿起 [4,2,3,4] 也是最优方案。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>cards = [1,0,5,3]
<strong>输出：</strong>-1
<strong>解释：</strong>无法找出含一对匹配卡牌的一组连续卡牌。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= cards.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= cards[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们初始化答案为 $+\infty$，遍历数组，对于每个数字 $x$，如果 $\textit{last}[x]$ 存在，则表示 $x$ 有一对匹配卡牌，此时更新答案为 $\textit{ans} = \min(\textit{ans}, i - \textit{last}[x] + 1)$，最后如果答案为 $+\infty$，则返回 $-1$，否则返回答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        last = {}
        ans = inf
        for i, x in enumerate(cards):
            if x in last:
                ans = min(ans, i - last[x] + 1)
            last[x] = i
        return -1 if ans == inf else ans
```

#### Java

```java
class Solution {
    public int minimumCardPickup(int[] cards) {
        Map<Integer, Integer> last = new HashMap<>();
        int n = cards.length;
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            if (last.containsKey(cards[i])) {
                ans = Math.min(ans, i - last.get(cards[i]) + 1);
            }
            last.put(cards[i], i);
        }
        return ans > n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> last;
        int n = cards.size();
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            if (last.count(cards[i])) {
                ans = min(ans, i - last[cards[i]] + 1);
            }
            last[cards[i]] = i;
        }
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func minimumCardPickup(cards []int) int {
	last := map[int]int{}
	n := len(cards)
	ans := n + 1
	for i, x := range cards {
		if j, ok := last[x]; ok && ans > i-j+1 {
			ans = i - j + 1
		}
		last[x] = i
	}
	if ans > n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumCardPickup(cards: number[]): number {
    const n = cards.length;
    const last = new Map<number, number>();
    let ans = n + 1;
    for (let i = 0; i < n; ++i) {
        if (last.has(cards[i])) {
            ans = Math.min(ans, i - last.get(cards[i]) + 1);
        }
        last.set(cards[i], i);
    }
    return ans > n ? -1 : ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2261. 含最多 K 个可整除元素的子数组](https://leetcode.cn/problems/k-divisible-elements-subarrays){#2261}

{{< tabs "2261" >}}

{{% tab "python" %}}
```python
class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        n = len(nums)
        s = set()
        for i in range(n):
            cnt = 0
            t = ""
            for x in nums[i:]:
                cnt += x % p == 0
                if cnt > k:
                    break
                t += str(x) + ","
                s.add(t)
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countDistinct(int[] nums, int k, int p) {
        Set<Long> s = new HashSet<>();
        int n = nums.length;
        int base1 = 131, base2 = 13331;
        int mod1 = (int) 1e9 + 7, mod2 = (int) 1e9 + 9;
        for (int i = 0; i < n; ++i) {
            long h1 = 0, h2 = 0;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += nums[j] % p == 0 ? 1 : 0;
                if (cnt > k) {
                    break;
                }
                h1 = (h1 * base1 + nums[j]) % mod1;
                h2 = (h2 * base2 + nums[j]) % mod2;
                s.add(h1 << 32 | h2);
            }
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<long long> s;
        int n = nums.size();
        int base1 = 131, base2 = 13331;
        int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
        for (int i = 0; i < n; ++i) {
            long long h1 = 0, h2 = 0;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += nums[j] % p == 0;
                if (cnt > k) {
                    break;
                }
                h1 = (h1 * base1 + nums[j]) % mod1;
                h2 = (h2 * base2 + nums[j]) % mod2;
                s.insert(h1 << 32 | h2);
            }
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countDistinct(nums []int, k int, p int) int {
	s := map[int]bool{}
	base1, base2 := 131, 13331
	mod1, mod2 := 1000000007, 1000000009
	for i := range nums {
		h1, h2, cnt := 0, 0, 0
		for j := i; j < len(nums); j++ {
			if nums[j]%p == 0 {
				cnt++
				if cnt > k {
					break
				}
			}
			h1 = (h1*base1 + nums[j]) % mod1
			h2 = (h2*base2 + nums[j]) % mod2
			s[h1<<32|h2] = true
		}
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countDistinct(nums: number[], k: number, p: number): number {
    const s = new Set<bigint>();
    const [base1, base2] = [131, 13331];
    const [mod1, mod2] = [1000000007, 1000000009];
    for (let i = 0; i < nums.length; i++) {
        let [h1, h2, cnt] = [0, 0, 0];
        for (let j = i; j < nums.length; j++) {
            if (nums[j] % p === 0) {
                cnt++;
                if (cnt > k) {
                    break;
                }
            }
            h1 = (h1 * base1 + nums[j]) % mod1;
            h2 = (h2 * base2 + nums[j]) % mod2;
            s.add((BigInt(h1) << 32n) | BigInt(h2));
        }
    }
    return s.size;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和两个整数 <code>k</code> 和 <code>p</code> ，找出并返回满足要求的不同的子数组数，要求子数组中最多 <code>k</code> 个可被 <code>p</code> 整除的元素。</p>

<p>如果满足下述条件之一，则认为数组 <code>nums1</code> 和 <code>nums2</code> 是 <strong>不同</strong> 数组：</p>

<ul>
	<li>两数组长度 <strong>不同</strong> ，或者</li>
	<li>存在 <strong>至少 </strong>一个下标 <code>i</code> 满足 <code>nums1[i] != nums2[i]</code> 。</li>
</ul>

<p><strong>子数组</strong> 定义为：数组中的连续元素组成的一个 <strong>非空</strong> 序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [<em><strong>2</strong></em>,3,3,<em><strong>2</strong></em>,<em><strong>2</strong></em>], k = 2, p = 2
<strong>输出：</strong>11
<strong>解释：</strong>
位于下标 0、3 和 4 的元素都可以被 p = 2 整除。
共计 11 个不同子数组都满足最多含 k = 2 个可以被 2 整除的元素：
[2]、[2,3]、[2,3,3]、[2,3,3,2]、[3]、[3,3]、[3,3,2]、[3,3,2,2]、[3,2]、[3,2,2] 和 [2,2] 。
注意，尽管子数组 [2] 和 [3] 在 nums 中出现不止一次，但统计时只计数一次。
子数组 [2,3,3,2,2] 不满足条件，因为其中有 3 个元素可以被 2 整除。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4], k = 4, p = 1
<strong>输出：</strong>10
<strong>解释：</strong>
nums 中的所有元素都可以被 p = 1 整除。
此外，nums 中的每个子数组都满足最多 4 个元素可以被 1 整除。
因为所有子数组互不相同，因此满足所有限制条件的子数组总数为 10 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i], p &lt;= 200</code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<p>你可以设计并实现时间复杂度为 <code>O(n<sup>2</sup>)</code> 的算法解决此问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 字符串哈希

我们可以枚举子数组的左端点 $i$，再在 $[i, n)$ 的范围内枚举子数组的右端点 $j$，在枚举右端点的过程中，我们通过双哈希的方式，将子数组的哈希值存入集合中，最后返回集合的大小即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        s = set()
        n = len(nums)
        base1, base2 = 131, 13331
        mod1, mod2 = 10**9 + 7, 10**9 + 9
        for i in range(n):
            h1 = h2 = cnt = 0
            for j in range(i, n):
                cnt += nums[j] % p == 0
                if cnt > k:
                    break
                h1 = (h1 * base1 + nums[j]) % mod1
                h2 = (h2 * base2 + nums[j]) % mod2
                s.add(h1 << 32 | h2)
        return len(s)
```

#### Java

```java
class Solution {
    public int countDistinct(int[] nums, int k, int p) {
        Set<Long> s = new HashSet<>();
        int n = nums.length;
        int base1 = 131, base2 = 13331;
        int mod1 = (int) 1e9 + 7, mod2 = (int) 1e9 + 9;
        for (int i = 0; i < n; ++i) {
            long h1 = 0, h2 = 0;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += nums[j] % p == 0 ? 1 : 0;
                if (cnt > k) {
                    break;
                }
                h1 = (h1 * base1 + nums[j]) % mod1;
                h2 = (h2 * base2 + nums[j]) % mod2;
                s.add(h1 << 32 | h2);
            }
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<long long> s;
        int n = nums.size();
        int base1 = 131, base2 = 13331;
        int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
        for (int i = 0; i < n; ++i) {
            long long h1 = 0, h2 = 0;
            int cnt = 0;
            for (int j = i; j < n; ++j) {
                cnt += nums[j] % p == 0;
                if (cnt > k) {
                    break;
                }
                h1 = (h1 * base1 + nums[j]) % mod1;
                h2 = (h2 * base2 + nums[j]) % mod2;
                s.insert(h1 << 32 | h2);
            }
        }
        return s.size();
    }
};
```

#### Go

```go
func countDistinct(nums []int, k int, p int) int {
	s := map[int]bool{}
	base1, base2 := 131, 13331
	mod1, mod2 := 1000000007, 1000000009
	for i := range nums {
		h1, h2, cnt := 0, 0, 0
		for j := i; j < len(nums); j++ {
			if nums[j]%p == 0 {
				cnt++
				if cnt > k {
					break
				}
			}
			h1 = (h1*base1 + nums[j]) % mod1
			h2 = (h2*base2 + nums[j]) % mod2
			s[h1<<32|h2] = true
		}
	}
	return len(s)
}
```

#### TypeScript

```ts
function countDistinct(nums: number[], k: number, p: number): number {
    const s = new Set<bigint>();
    const [base1, base2] = [131, 13331];
    const [mod1, mod2] = [1000000007, 1000000009];
    for (let i = 0; i < nums.length; i++) {
        let [h1, h2, cnt] = [0, 0, 0];
        for (let j = i; j < nums.length; j++) {
            if (nums[j] % p === 0) {
                cnt++;
                if (cnt > k) {
                    break;
                }
            }
            h1 = (h1 * base1 + nums[j]) % mod1;
            h2 = (h2 * base2 + nums[j]) % mod2;
            s.add((BigInt(h1) << 32n) | BigInt(h2));
        }
    }
    return s.size;
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
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        n = len(nums)
        s = set()
        for i in range(n):
            cnt = 0
            t = ""
            for x in nums[i:]:
                cnt += x % p == 0
                if cnt > k:
                    break
                t += str(x) + ","
                s.add(t)
        return len(s)
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2262. 字符串的总引力](https://leetcode.cn/problems/total-appeal-of-a-string){#2262}

{{< tabs "2262" >}}

{{% tab "python" %}}
```python
class Solution:
    def appealSum(self, s: str) -> int:
        ans = t = 0
        pos = [-1] * 26
        for i, c in enumerate(s):
            c = ord(c) - ord('a')
            t += i - pos[c]
            ans += t
            pos[c] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long appealSum(String s) {
        long ans = 0;
        long t = 0;
        int[] pos = new int[26];
        Arrays.fill(pos, -1);
        for (int i = 0; i < s.length(); ++i) {
            int c = s.charAt(i) - 'a';
            t += i - pos[c];
            ans += t;
            pos[c] = i;
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
    long long appealSum(string s) {
        long long ans = 0, t = 0;
        vector<int> pos(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            t += i - pos[c];
            ans += t;
            pos[c] = i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func appealSum(s string) int64 {
	var ans, t int64
	pos := make([]int, 26)
	for i := range pos {
		pos[i] = -1
	}
	for i, c := range s {
		c -= 'a'
		t += int64(i - pos[c])
		ans += t
		pos[c] = i
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function appealSum(s: string): number {
    const pos: number[] = Array(26).fill(-1);
    const n = s.length;
    let ans = 0;
    let t = 0;
    for (let i = 0; i < n; ++i) {
        const c = s.charCodeAt(i) - 97;
        t += i - pos[c];
        ans += t;
        pos[c] = i;
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

<p>字符串的 <strong>引力</strong> 定义为：字符串中 <strong>不同</strong> 字符的数量。</p>

<ul>
	<li>例如，<code>"abbca"</code> 的引力为 <code>3</code> ，因为其中有 <code>3</code> 个不同字符 <code>'a'</code>、<code>'b'</code> 和 <code>'c'</code> 。</li>
</ul>

<p>给你一个字符串 <code>s</code> ，返回 <strong>其所有子字符串的总引力</strong> <strong>。</strong></p>

<p><strong>子字符串</strong> 定义为：字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abbca"
<strong>输出：</strong>28
<strong>解释：</strong>"abbca" 的子字符串有：
- 长度为 1 的子字符串："a"、"b"、"b"、"c"、"a" 的引力分别为 1、1、1、1、1，总和为 5 。
- 长度为 2 的子字符串："ab"、"bb"、"bc"、"ca" 的引力分别为 2、1、2、2 ，总和为 7 。
- 长度为 3 的子字符串："abb"、"bbc"、"bca" 的引力分别为 2、2、3 ，总和为 7 。
- 长度为 4 的子字符串："abbc"、"bbca" 的引力分别为 3、3 ，总和为 6 。
- 长度为 5 的子字符串："abbca" 的引力为 3 ，总和为 3 。
引力总和为 5 + 7 + 7 + 6 + 3 = 28 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "code"
<strong>输出：</strong>20
<strong>解释：</strong>"code" 的子字符串有：
- 长度为 1 的子字符串："c"、"o"、"d"、"e" 的引力分别为 1、1、1、1 ，总和为 4 。
- 长度为 2 的子字符串："co"、"od"、"de" 的引力分别为 2、2、2 ，总和为 6 。
- 长度为 3 的子字符串："cod"、"ode" 的引力分别为 3、3 ，总和为 6 。
- 长度为 4 的子字符串："code" 的引力为 4 ，总和为 4 。
引力总和为 4 + 6 + 6 + 4 = 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举以每个字符 $s[i]$ 结尾的字符串，计算其引力值之和 $t$，最后将所有 $t$ 相加即可。

考虑遍历到 $s[i]$ 时，即把 $s[i]$ 添加到以 $s[i-1]$ 结尾的子字符串的后面，其引力值之和 $t$ 的变化情况：

1. 如果 $s[i]$ 在之前没出现过，那么所有以 $s[i-1]$ 结尾的子字符串的引力值都会增加 $1$，共有 $i$ 个，所以 $t$ 增加 $i$，再加上 $s[i]$ 自身的引力值 $1$，所以 $t$ 一共增加 $i+1$；
1. 如果 $s[i]$ 在之前出现过，不妨记上次出现的的位置为 $j$，那么我们向子字符串 $s[0..i-1]$, $[1..i-1]$, $s[2..i-1]$, $\cdots$, $s[j..i-1]$ 后面添加 $s[i]$，这些子字符串的引力值不会发生变化，因为 $s[i]$ 已经在这些子字符串中出现过了；而子字符串 $s[j+1..i-1]$, $s[j+2..i-1]$, $\cdots$, $s[i-1]$ 的引力值都会增加 $1$，共有 $i-j-1$ 个，所以 $t$ 增加 $i-j-1$，再加上 $s[i]$ 自身的引力值 $1$，所以 $t$ 一共增加 $i-j$。

综上，我们可以用一个数组 $pos$ 记录每个字符上次出现的位置，初始时所有位置都为 $-1$，

接下来，我们遍历字符串，每一次我们更新以当前字符结尾的子字符串的引力值之和 $t = t + i - pos[c]$，其中 $c$ 是当前字符，累加 $t$ 到答案中。然后我们更新 $pos[c]$ 为当前位置 $i$。继续遍历直到字符串结束。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 $s$ 的长度；而 $|\Sigma|$ 是字符集的大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def appealSum(self, s: str) -> int:
        ans = t = 0
        pos = [-1] * 26
        for i, c in enumerate(s):
            c = ord(c) - ord('a')
            t += i - pos[c]
            ans += t
            pos[c] = i
        return ans
```

#### Java

```java
class Solution {
    public long appealSum(String s) {
        long ans = 0;
        long t = 0;
        int[] pos = new int[26];
        Arrays.fill(pos, -1);
        for (int i = 0; i < s.length(); ++i) {
            int c = s.charAt(i) - 'a';
            t += i - pos[c];
            ans += t;
            pos[c] = i;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long appealSum(string s) {
        long long ans = 0, t = 0;
        vector<int> pos(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int c = s[i] - 'a';
            t += i - pos[c];
            ans += t;
            pos[c] = i;
        }
        return ans;
    }
};
```

#### Go

```go
func appealSum(s string) int64 {
	var ans, t int64
	pos := make([]int, 26)
	for i := range pos {
		pos[i] = -1
	}
	for i, c := range s {
		c -= 'a'
		t += int64(i - pos[c])
		ans += t
		pos[c] = i
	}
	return ans
}
```

#### TypeScript

```ts
function appealSum(s: string): number {
    const pos: number[] = Array(26).fill(-1);
    const n = s.length;
    let ans = 0;
    let t = 0;
    for (let i = 0; i < n; ++i) {
        const c = s.charCodeAt(i) - 97;
        t += i - pos[c];
        ans += t;
        pos[c] = i;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2263. 数组变为有序的最小操作次数 🔒](https://leetcode.cn/problems/make-array-non-decreasing-or-non-increasing){#2263}

{{< tabs "2263" >}}

{{% tab "python" %}}
```python
class Solution:
    def convertArray(self, nums: List[int]) -> int:
        def solve(nums):
            n = len(nums)
            f = [[0] * 1001 for _ in range(n + 1)]
            for i, x in enumerate(nums, 1):
                mi = inf
                for j in range(1001):
                    if mi > f[i - 1][j]:
                        mi = f[i - 1][j]
                    f[i][j] = mi + abs(x - j)
            return min(f[n])

        return min(solve(nums), solve(nums[::-1]))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int convertArray(int[] nums) {
        return Math.min(solve(nums), solve(reverse(nums)));
    }

    private int solve(int[] nums) {
        int n = nums.length;
        int[][] f = new int[n + 1][1001];
        for (int i = 1; i <= n; ++i) {
            int mi = 1 << 30;
            for (int j = 0; j <= 1000; ++j) {
                mi = Math.min(mi, f[i - 1][j]);
                f[i][j] = mi + Math.abs(j - nums[i - 1]);
            }
        }
        int ans = 1 << 30;
        for (int x : f[n]) {
            ans = Math.min(ans, x);
        }
        return ans;
    }

    private int[] reverse(int[] nums) {
        for (int i = 0, j = nums.length - 1; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        return nums;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int convertArray(vector<int>& nums) {
        int a = solve(nums);
        reverse(nums.begin(), nums.end());
        int b = solve(nums);
        return min(a, b);
    }

    int solve(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1][1001];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int mi = 1 << 30;
            for (int j = 0; j <= 1000; ++j) {
                mi = min(mi, f[i - 1][j]);
                f[i][j] = mi + abs(nums[i - 1] - j);
            }
        }
        return *min_element(f[n], f[n] + 1001);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func convertArray(nums []int) int {
	return min(solve(nums), solve(reverse(nums)))
}

func solve(nums []int) int {
	n := len(nums)
	f := make([][1001]int, n+1)
	for i := 1; i <= n; i++ {
		mi := 1 << 30
		for j := 0; j <= 1000; j++ {
			mi = min(mi, f[i-1][j])
			f[i][j] = mi + abs(nums[i-1]-j)
		}
	}
	ans := 1 << 30
	for _, x := range f[n] {
		ans = min(ans, x)
	}
	return ans
}

func reverse(nums []int) []int {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return nums
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 。在一步操作中，你可以：</p>

<ul>
	<li>在范围&nbsp;<code>0 &lt;= i &lt; nums.length</code> 内选出一个下标 <code>i</code></li>
	<li>将 <code>nums[i]</code> 的值变为 <code>nums[i] + 1</code> <strong>或</strong> <code>nums[i] - 1</code></li>
</ul>

<p>返回将数组 <code>nums</code> 变为 <strong>非递增</strong> 或<strong> 非递减 </strong>所需的 <strong>最小</strong> 操作次数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,4,5,0]
<strong>输出：</strong>4
<strong>解释：</strong>
一种可行的操作顺序，能够将 nums 变为非递增排列：
- nums[1] 加 1 一次，使其变为 3 。
- nums[2] 减 1 一次，使其变为 3 。
- nums[3] 减 1 两次，使其变为 3 。
经过 4 次操作后，nums 变为 [3,3,3,3,0] ，按非递增顺序排列。
注意，也可以用 4 步操作将 nums 变为 [4,4,4,4,0] ，同样满足题目要求。
可以证明最少需要 4 步操作才能将数组变为非递增或非递减排列。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,3,4]
<strong>输出：</strong>0
<strong>解释：</strong>数组已经是按非递减顺序排列了，无需执行任何操作，返回 0 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>0
<strong>解释：</strong>数组已经是按非递减顺序排列了，无需执行任何操作，返回 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计并实现时间复杂度为 <code>O(n*log(n))</code> 的解法吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示将数组 $nums$ 的前 $i$ 个元素变为非递减序列，且第 $i$ 个元素的值为 $j$ 所需的最小操作次数。由于数组 $nums$ 元素的取值范围为 $[0, 1000]$，因此我们可以将 $f$ 数组的第二维定义为 $1001$。

状态转移方程如下：

$$
f[i][j] = \min_{0 \leq k \leq j} f[i - 1][k] + \left| j - nums[i - 1] \right|
$$

时间复杂度 $O(n \times M)$，空间复杂度 $O(n \times M)$。其中 $n$ 和 $M$ 分别为数组 $nums$ 的长度和数组 $nums$ 元素的取值范围。本题中 $M = 1001$。

由于我们定义的是非递减序列的最小操作次数，因此我们可以将数组 $nums$ 翻转，然后求出非递减序列的最小操作次数，也即是非递增序列的最小操作次数。最后取两者的最小值即可。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def convertArray(self, nums: List[int]) -> int:
        def solve(nums):
            n = len(nums)
            f = [[0] * 1001 for _ in range(n + 1)]
            for i, x in enumerate(nums, 1):
                mi = inf
                for j in range(1001):
                    if mi > f[i - 1][j]:
                        mi = f[i - 1][j]
                    f[i][j] = mi + abs(x - j)
            return min(f[n])

        return min(solve(nums), solve(nums[::-1]))
```

#### Java

```java
class Solution {
    public int convertArray(int[] nums) {
        return Math.min(solve(nums), solve(reverse(nums)));
    }

    private int solve(int[] nums) {
        int n = nums.length;
        int[][] f = new int[n + 1][1001];
        for (int i = 1; i <= n; ++i) {
            int mi = 1 << 30;
            for (int j = 0; j <= 1000; ++j) {
                mi = Math.min(mi, f[i - 1][j]);
                f[i][j] = mi + Math.abs(j - nums[i - 1]);
            }
        }
        int ans = 1 << 30;
        for (int x : f[n]) {
            ans = Math.min(ans, x);
        }
        return ans;
    }

    private int[] reverse(int[] nums) {
        for (int i = 0, j = nums.length - 1; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int convertArray(vector<int>& nums) {
        int a = solve(nums);
        reverse(nums.begin(), nums.end());
        int b = solve(nums);
        return min(a, b);
    }

    int solve(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1][1001];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; ++i) {
            int mi = 1 << 30;
            for (int j = 0; j <= 1000; ++j) {
                mi = min(mi, f[i - 1][j]);
                f[i][j] = mi + abs(nums[i - 1] - j);
            }
        }
        return *min_element(f[n], f[n] + 1001);
    }
};
```

#### Go

```go
func convertArray(nums []int) int {
	return min(solve(nums), solve(reverse(nums)))
}

func solve(nums []int) int {
	n := len(nums)
	f := make([][1001]int, n+1)
	for i := 1; i <= n; i++ {
		mi := 1 << 30
		for j := 0; j <= 1000; j++ {
			mi = min(mi, f[i-1][j])
			f[i][j] = mi + abs(nums[i-1]-j)
		}
	}
	ans := 1 << 30
	for _, x := range f[n] {
		ans = min(ans, x)
	}
	return ans
}

func reverse(nums []int) []int {
	for i, j := 0, len(nums)-1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
	return nums
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

# [2264. 字符串中最大的 3 位相同数字](https://leetcode.cn/problems/largest-3-same-digit-number-in-string){#2264}

{{< tabs "2264" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        for i in range(9, -1, -1):
            if (s := str(i) * 3) in num:
                return s
        return ""
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String largestGoodInteger(String num) {
        for (int i = 9; i >= 0; i--) {
            String s = String.valueOf(i).repeat(3);
            if (num.contains(s)) {
                return s;
            }
        }
        return "";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string largestGoodInteger(string num) {
        for (char i = '9'; i >= '0'; --i) {
            string s(3, i);
            if (num.find(s) != string::npos) {
                return s;
            }
        }
        return "";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largestGoodInteger(num string) string {
	for c := '9'; c >= '0'; c-- {
		if s := strings.Repeat(string(c), 3); strings.Contains(num, s) {
			return s
		}
	}
	return ""
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largestGoodInteger(num: string): string {
    for (let i = 9; i >= 0; i--) {
        const s = String(i).repeat(3);
        if (num.includes(s)) {
            return s;
        }
    }
    return '';
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>num</code> ，表示一个大整数。如果一个整数满足下述所有条件，则认为该整数是一个 <strong>优质整数</strong> ：</p>

<ul>
	<li>该整数是 <code>num</code> 的一个长度为 <code>3</code> 的 <strong>子字符串</strong> 。</li>
	<li>该整数由唯一一个数字重复 <code>3</code> 次组成。</li>
</ul>

<p>以字符串形式返回 <strong>最大的优质整数</strong> 。如果不存在满足要求的整数，则返回一个空字符串 <code>""</code> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><strong>子字符串</strong> 是字符串中的一个连续字符序列。</li>
	<li><code>num</code> 或优质整数中可能存在 <strong>前导零</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "6<em><strong>777</strong></em>133339"
<strong>输出：</strong>"777"
<strong>解释：</strong>num 中存在两个优质整数："777" 和 "333" 。
"777" 是最大的那个，所以返回 "777" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "23<em><strong>000</strong></em>19"
<strong>输出：</strong>"000"
<strong>解释：</strong>"000" 是唯一一个优质整数。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = "42352338"
<strong>输出：</strong>""
<strong>解释：</strong>不存在长度为 3 且仅由一个唯一数字组成的整数。因此，不存在优质整数。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= num.length &lt;= 1000</code></li>
	<li><code>num</code> 仅由数字（<code>0</code> - <code>9</code>）组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以从大到小枚举每个数字 $i$，其中 $0 \le i \le 9$，然后判断连续的三个 $i$ 构成的字符串 $s$ 是否是 $num$ 的子串，若是，直接返回 $s$ 即可。

若枚举完所有的 $i$ 都没有找到满足条件的字符串，则返回空字符串。

时间复杂度 $O(10 \times n)$，其中 $n$ 是字符串 $num$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        for i in range(9, -1, -1):
            if (s := str(i) * 3) in num:
                return s
        return ""
```

#### Java

```java
class Solution {
    public String largestGoodInteger(String num) {
        for (int i = 9; i >= 0; i--) {
            String s = String.valueOf(i).repeat(3);
            if (num.contains(s)) {
                return s;
            }
        }
        return "";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string largestGoodInteger(string num) {
        for (char i = '9'; i >= '0'; --i) {
            string s(3, i);
            if (num.find(s) != string::npos) {
                return s;
            }
        }
        return "";
    }
};
```

#### Go

```go
func largestGoodInteger(num string) string {
	for c := '9'; c >= '0'; c-- {
		if s := strings.Repeat(string(c), 3); strings.Contains(num, s) {
			return s
		}
	}
	return ""
}
```

#### TypeScript

```ts
function largestGoodInteger(num: string): string {
    for (let i = 9; i >= 0; i--) {
        const s = String(i).repeat(3);
        if (num.includes(s)) {
            return s;
        }
    }
    return '';
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2265. 统计值等于子树平均值的节点数](https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree){#2265}

{{< tabs "2265" >}}

{{% tab "python" %}}
```python
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(root) -> tuple:
            if not root:
                return 0, 0
            ls, ln = dfs(root.left)
            rs, rn = dfs(root.right)
            s = ls + rs + root.val
            n = ln + rn + 1
            nonlocal ans
            ans += int(s // n == root.val)
            return s, n

        ans = 0
        dfs(root)
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
    private int ans;

    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[2];
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int s = l[0] + r[0] + root.val;
        int n = l[1] + r[1] + 1;
        if (s / n == root.val) {
            ++ans;
        }
        return new int[] {s, n};
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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {0, 0};
            }
            auto [ls, ln] = dfs(root->left);
            auto [rs, rn] = dfs(root->right);
            int s = ls + rs + root->val;
            int n = ln + rn + 1;
            if (s / n == root->val) {
                ++ans;
            }
            return {s, n};
        };
        dfs(root);
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
func averageOfSubtree(root *TreeNode) (ans int) {
	var dfs func(root *TreeNode) (int, int)
	dfs = func(root *TreeNode) (int, int) {
		if root == nil {
			return 0, 0
		}
		ls, ln := dfs(root.Left)
		rs, rn := dfs(root.Right)
		s, n := ls+rs+root.Val, ln+rn+1
		if s/n == root.Val {
			ans++
		}
		return s, n
	}
	dfs(root)
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

function averageOfSubtree(root: TreeNode | null): number {
    let ans: number = 0;
    const dfs = (root: TreeNode | null): [number, number] => {
        if (!root) {
            return [0, 0];
        }
        const [ls, ln] = dfs(root.left);
        const [rs, rn] = dfs(root.right);
        const s = ls + rs + root.val;
        const n = ln + rn + 1;
        if (Math.floor(s / n) === root.val) {
            ++ans;
        }
        return [s, n];
    };
    dfs(root);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一棵二叉树的根节点 <code>root</code> ，找出并返回满足要求的节点数，要求节点的值等于其 <strong>子树</strong> 中值的 <strong>平均值</strong> 。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>n</code> 个元素的平均值可以由 <code>n</code> 个元素 <strong>求和</strong> 然后再除以 <code>n</code> ，并 <strong>向下舍入</strong> 到最近的整数。</li>
	<li><code>root</code> 的 <strong>子树</strong> 由 <code>root</code> 和它的所有后代组成。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2265.Count%20Nodes%20Equal%20to%20Average%20of%20Subtree/images/image-20220315203925-1.png" style="width: 300px; height: 212px;">
<pre><strong>输入：</strong>root = [4,8,5,0,1,null,6]
<strong>输出：</strong>5
<strong>解释：</strong>
对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
对值为 0 的节点：子树的平均值 0 / 1 = 0 。
对值为 1 的节点：子树的平均值 1 / 1 = 1 。
对值为 6 的节点：子树的平均值 6 / 1 = 6 。
</pre>

<p><strong>示例 2：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2265.Count%20Nodes%20Equal%20to%20Average%20of%20Subtree/images/image-20220326133920-1.png" style="width: 80px; height: 76px;">
<pre><strong>输入：</strong>root = [1]
<strong>输出：</strong>1
<strong>解释：</strong>对值为 1 的节点：子树的平均值 1 / 1 = 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数目在范围 <code>[1, 1000]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $\textit{dfs}$，它的作用是计算以当前节点为根的子树的和以及节点个数。

函数 $\textit{dfs}$ 的执行过程如下：

-   如果当前节点为空，返回 $(0, 0)$。
-   否则，我们递归计算左右子树的和以及节点个数，分别记为 $(\textit{ls}, \textit{ln})$ 和 $(\textit{rs}, \textit{rn})$。那么，以当前节点为根的子树的和 $\textit{s}$ 和节点个数 $\textit{n}$ 分别为 $\textit{ls} + \textit{rs} + \textit{root.val}$ 和 $\textit{ln} + \textit{rn} + 1$。如果 $\textit{s} / \textit{n} = \textit{root.val}$，则说明当前节点满足题目要求，我们将答案 $\textit{ans}$ 自增 $1$。
-   最后，函数 $\textit{dfs}$ 返回 $\textit{s}$ 和 $\textit{n}$。

我们初始化答案 $\textit{ans}$ 为 $0$，然后调用 $\textit{dfs}$ 函数，最后返回答案 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示二叉树的节点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        def dfs(root) -> tuple:
            if not root:
                return 0, 0
            ls, ln = dfs(root.left)
            rs, rn = dfs(root.right)
            s = ls + rs + root.val
            n = ln + rn + 1
            nonlocal ans
            ans += int(s // n == root.val)
            return s, n

        ans = 0
        dfs(root)
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
    private int ans;

    public int averageOfSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode root) {
        if (root == null) {
            return new int[2];
        }
        var l = dfs(root.left);
        var r = dfs(root.right);
        int s = l[0] + r[0] + root.val;
        int n = l[1] + r[1] + 1;
        if (s / n == root.val) {
            ++ans;
        }
        return new int[] {s, n};
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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> pair<int, int> {
            if (!root) {
                return {0, 0};
            }
            auto [ls, ln] = dfs(root->left);
            auto [rs, rn] = dfs(root->right);
            int s = ls + rs + root->val;
            int n = ln + rn + 1;
            if (s / n == root->val) {
                ++ans;
            }
            return {s, n};
        };
        dfs(root);
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
func averageOfSubtree(root *TreeNode) (ans int) {
	var dfs func(root *TreeNode) (int, int)
	dfs = func(root *TreeNode) (int, int) {
		if root == nil {
			return 0, 0
		}
		ls, ln := dfs(root.Left)
		rs, rn := dfs(root.Right)
		s, n := ls+rs+root.Val, ln+rn+1
		if s/n == root.Val {
			ans++
		}
		return s, n
	}
	dfs(root)
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

function averageOfSubtree(root: TreeNode | null): number {
    let ans: number = 0;
    const dfs = (root: TreeNode | null): [number, number] => {
        if (!root) {
            return [0, 0];
        }
        const [ls, ln] = dfs(root.left);
        const [rs, rn] = dfs(root.right);
        const s = ls + rs + root.val;
        const n = ln + rn + 1;
        if (Math.floor(s / n) === root.val) {
            ++ans;
        }
        return [s, n];
    };
    dfs(root);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2266. 统计打字方案数](https://leetcode.cn/problems/count-number-of-texts){#2266}

{{< tabs "2266" >}}

{{% tab "python" %}}
```python
mod = 10**9 + 7
f = [1, 1, 2, 4]
g = [1, 1, 2, 4]
for _ in range(100000):
    f.append((f[-1] + f[-2] + f[-3]) % mod)
    g.append((g[-1] + g[-2] + g[-3] + g[-4]) % mod)


class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        ans = 1
        for c, s in groupby(pressedKeys):
            m = len(list(s))
            ans = ans * (g[m] if c in "79" else f[m]) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int N = 100010;
    private static final int MOD = (int) 1e9 + 7;
    private static long[] f = new long[N];
    private static long[] g = new long[N];
    static {
        f[0] = f[1] = 1;
        f[2] = 2;
        f[3] = 4;
        g[0] = g[1] = 1;
        g[2] = 2;
        g[3] = 4;
        for (int i = 4; i < N; ++i) {
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
        }
    }

    public int countTexts(String pressedKeys) {
        long ans = 1;
        for (int i = 0, n = pressedKeys.length(); i < n; ++i) {
            char c = pressedKeys.charAt(i);
            int j = i;
            while (j + 1 < n && pressedKeys.charAt(j + 1) == c) {
                ++j;
            }
            int cnt = j - i + 1;
            ans = c == '7' || c == '9' ? ans * g[cnt] : ans * f[cnt];
            ans %= MOD;
            i = j;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int mod = 1e9 + 7;
const int n = 1e5 + 10;
long long f[n], g[n];

int init = []() {
    f[0] = g[0] = 1;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = g[3] = 4;
    for (int i = 4; i < n; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod;
        g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % mod;
    }
    return 0;
}();

class Solution {
public:
    int countTexts(string pressedKeys) {
        long long ans = 1;
        for (int i = 0, n = pressedKeys.length(); i < n; ++i) {
            char c = pressedKeys[i];
            int j = i;
            while (j + 1 < n && pressedKeys[j + 1] == c) {
                ++j;
            }
            int cnt = j - i + 1;
            ans = c == '7' || c == '9' ? ans * g[cnt] : ans * f[cnt];
            ans %= mod;
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const mod int = 1e9 + 7
const n int = 1e5 + 10

var f = [n]int{1, 1, 2, 4}
var g = f

func init() {
	for i := 4; i < n; i++ {
		f[i] = (f[i-1] + f[i-2] + f[i-3]) % mod
		g[i] = (g[i-1] + g[i-2] + g[i-3] + g[i-4]) % mod
	}
}

func countTexts(pressedKeys string) int {
	ans := 1
	for i, j, n := 0, 0, len(pressedKeys); i < n; i++ {
		c := pressedKeys[i]
		j = i
		for j+1 < n && pressedKeys[j+1] == c {
			j++
		}
		cnt := j - i + 1
		if c == '7' || c == '9' {
			ans = ans * g[cnt] % mod
		} else {
			ans = ans * f[cnt] % mod
		}
		i = j
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

<p>Alice 在给 Bob 用手机打字。数字到字母的 <strong>对应</strong>&nbsp;如下图所示。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2266.Count%20Number%20of%20Texts/images/1722224025-gsUAIv-image.png" style="width: 200px; height: 162px;" /></p>

<p>为了 <strong>打出</strong>&nbsp;一个字母，Alice 需要 <strong>按</strong>&nbsp;对应字母 <code>i</code>&nbsp;次，<code>i</code>&nbsp;是该字母在这个按键上所处的位置。</p>

<ul>
	<li>比方说，为了按出字母&nbsp;<code>'s'</code>&nbsp;，Alice 需要按&nbsp;<code>'7'</code>&nbsp;四次。类似的， Alice 需要按&nbsp;<code>'5'</code>&nbsp;两次得到字母&nbsp;&nbsp;<code>'k'</code>&nbsp;。</li>
	<li>注意，数字&nbsp;<code>'0'</code> 和&nbsp;<code>'1'</code>&nbsp;不映射到任何字母，所以&nbsp;Alice <strong>不</strong>&nbsp;使用它们。</li>
</ul>

<p>但是，由于传输的错误，Bob 没有收到 Alice 打字的字母信息，反而收到了 <strong>按键的字符串信息</strong>&nbsp;。</p>

<ul>
	<li>比方说，Alice 发出的信息为&nbsp;<code>"bob"</code>&nbsp;，Bob 将收到字符串&nbsp;<code>"2266622"</code>&nbsp;。</li>
</ul>

<p>给你一个字符串&nbsp;<code>pressedKeys</code>&nbsp;，表示 Bob 收到的字符串，请你返回 Alice <strong>总共可能发出多少种文字信息</strong>&nbsp;。</p>

<p>由于答案可能很大，将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong> 后返回。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>pressedKeys = "22233"
<b>输出：</b>8
<strong>解释：</strong>
Alice 可能发出的文字信息包括：
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae" 和 "ce" 。
由于总共有 8 种可能的信息，所以我们返回 8 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>pressedKeys = "222222222222222222222222222222222222"
<b>输出：</b>82876089
<strong>解释：</strong>
总共有 2082876103 种 Alice 可能发出的文字信息。
由于我们需要将答案对 10<sup>9</sup> + 7 取余，所以我们返回 2082876103 % (10<sup>9</sup> + 7) = 82876089 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pressedKeys.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pressedKeys</code> 只包含数字&nbsp;<code>'2'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 动态规划

根据题目描述，对于字符串 $\textit{pressedKeys}$ 中连续的相同字符，可以将其分为一组，然后分别计算每组的方案数，最后将所有组的方案数相乘即可。

问题的关键在于如何计算每组的方案数。

如果一组字符为 '7' 或 '9'，我们可以分别将该组的末尾 $1$, $2$, $3$, $4$ 个字符视为一个字母，然后将该组字符规模缩小，转化为规模更小的子问题。

同样地，如果一组字符为 '2', '3', '4', '5', '6', '8'，我们可以将该组的末尾 $1$, $2$, $3$ 个字符视为一个字母，然后将该组字符规模缩小，转化为规模更小的子问题。

因此，我们定义 $f[i]$ 表示长度为 $i$ 的连续相同字符，且字符不为 '7' 或 '9' 的方案数，定义 $g[i]$ 表示长度为 $i$ 的连续相同字符，且字符为 '7' 或 '9' 的方案数。

初始时 $f[0] = f[1] = 1$, $f[2] = 2$, $f[3] = 4$, $g[0] = g[1] = 1$, $g[2] = 2$, $g[3] = 4$。

对于 $i \ge 4$，有：

$$
\begin{aligned}
f[i] & = f[i-1] + f[i-2] + f[i-3] \\
g[i] & = g[i-1] + g[i-2] + g[i-3] + g[i-4]
\end{aligned}
$$

最后，我们遍历 $\textit{pressedKeys}$，将连续相同字符分组，然后计算每组的方案数，最后将所有组的方案数相乘即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{pressedKeys}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
mod = 10**9 + 7
f = [1, 1, 2, 4]
g = [1, 1, 2, 4]
for _ in range(100000):
    f.append((f[-1] + f[-2] + f[-3]) % mod)
    g.append((g[-1] + g[-2] + g[-3] + g[-4]) % mod)


class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        ans = 1
        for c, s in groupby(pressedKeys):
            m = len(list(s))
            ans = ans * (g[m] if c in "79" else f[m]) % mod
        return ans
```

#### Java

```java
class Solution {
    private static final int N = 100010;
    private static final int MOD = (int) 1e9 + 7;
    private static long[] f = new long[N];
    private static long[] g = new long[N];
    static {
        f[0] = f[1] = 1;
        f[2] = 2;
        f[3] = 4;
        g[0] = g[1] = 1;
        g[2] = 2;
        g[3] = 4;
        for (int i = 4; i < N; ++i) {
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
        }
    }

    public int countTexts(String pressedKeys) {
        long ans = 1;
        for (int i = 0, n = pressedKeys.length(); i < n; ++i) {
            char c = pressedKeys.charAt(i);
            int j = i;
            while (j + 1 < n && pressedKeys.charAt(j + 1) == c) {
                ++j;
            }
            int cnt = j - i + 1;
            ans = c == '7' || c == '9' ? ans * g[cnt] : ans * f[cnt];
            ans %= MOD;
            i = j;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
const int mod = 1e9 + 7;
const int n = 1e5 + 10;
long long f[n], g[n];

int init = []() {
    f[0] = g[0] = 1;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = g[3] = 4;
    for (int i = 4; i < n; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod;
        g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % mod;
    }
    return 0;
}();

class Solution {
public:
    int countTexts(string pressedKeys) {
        long long ans = 1;
        for (int i = 0, n = pressedKeys.length(); i < n; ++i) {
            char c = pressedKeys[i];
            int j = i;
            while (j + 1 < n && pressedKeys[j + 1] == c) {
                ++j;
            }
            int cnt = j - i + 1;
            ans = c == '7' || c == '9' ? ans * g[cnt] : ans * f[cnt];
            ans %= mod;
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
const mod int = 1e9 + 7
const n int = 1e5 + 10

var f = [n]int{1, 1, 2, 4}
var g = f

func init() {
	for i := 4; i < n; i++ {
		f[i] = (f[i-1] + f[i-2] + f[i-3]) % mod
		g[i] = (g[i-1] + g[i-2] + g[i-3] + g[i-4]) % mod
	}
}

func countTexts(pressedKeys string) int {
	ans := 1
	for i, j, n := 0, 0, len(pressedKeys); i < n; i++ {
		c := pressedKeys[i]
		j = i
		for j+1 < n && pressedKeys[j+1] == c {
			j++
		}
		cnt := j - i + 1
		if c == '7' || c == '9' {
			ans = ans * g[cnt] % mod
		} else {
			ans = ans * f[cnt] % mod
		}
		i = j
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2267. 检查是否有合法括号字符串路径](https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path){#2267}

{{< tabs "2267" >}}

{{% tab "python" %}}
```python
class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        @cache
        def dfs(i: int, j: int, k: int) -> bool:
            d = 1 if grid[i][j] == "(" else -1
            k += d
            if k < 0 or k > m - i + n - j:
                return False
            if i == m - 1 and j == n - 1:
                return k == 0
            for a, b in pairwise((0, 1, 0)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and dfs(x, y, k):
                    return True
            return False

        m, n = len(grid), len(grid[0])
        if (m + n - 1) % 2 or grid[0][0] == ")" or grid[m - 1][n - 1] == "(":
            return False
        return dfs(0, 0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m, n;
    private char[][] grid;
    private boolean[][][] vis;

    public boolean hasValidPath(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        if ((m + n - 1) % 2 == 1 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        this.grid = grid;
        vis = new boolean[m][n][m + n];
        return dfs(0, 0, 0);
    }

    private boolean dfs(int i, int j, int k) {
        if (vis[i][j][k]) {
            return false;
        }
        vis[i][j][k] = true;
        k += grid[i][j] == '(' ? 1 : -1;
        if (k < 0 || k > m - i + n - j) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return k == 0;
        }
        final int[] dirs = {1, 0, 1};
        for (int d = 0; d < 2; ++d) {
            int x = i + dirs[d], y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
                return true;
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
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        bool vis[m][n][m + n];
        memset(vis, false, sizeof(vis));
        int dirs[3] = {1, 0, 1};
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool {
            if (vis[i][j][k]) {
                return false;
            }
            vis[i][j][k] = true;
            k += grid[i][j] == '(' ? 1 : -1;
            if (k < 0 || k > m - i + n - j) {
                return false;
            }
            if (i == m - 1 && j == n - 1) {
                return k == 0;
            }
            for (int d = 0; d < 2; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0, 0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hasValidPath(grid [][]byte) bool {
	m, n := len(grid), len(grid[0])
	if (m+n-1)%2 == 1 || grid[0][0] == ')' || grid[m-1][n-1] == '(' {
		return false
	}
	vis := make([][][]bool, m)
	for i := range vis {
		vis[i] = make([][]bool, n)
		for j := range vis[i] {
			vis[i][j] = make([]bool, m+n)
		}
	}
	dirs := [3]int{1, 0, 1}
	var dfs func(i, j, k int) bool
	dfs = func(i, j, k int) bool {
		if vis[i][j][k] {
			return false
		}
		vis[i][j][k] = true
		if grid[i][j] == '(' {
			k++
		} else {
			k--
		}
		if k < 0 || k > m-i+n-j {
			return false
		}
		if i == m-1 && j == n-1 {
			return k == 0
		}
		for d := 0; d < 2; d++ {
			x, y := i+dirs[d], j+dirs[d+1]
			if x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k) {
				return true
			}
		}
		return false
	}
	return dfs(0, 0, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hasValidPath(grid: string[][]): boolean {
    const m = grid.length,
        n = grid[0].length;

    if ((m + n - 1) % 2 || grid[0][0] === ')' || grid[m - 1][n - 1] === '(') {
        return false;
    }

    const vis: boolean[][][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(m + n).fill(false)),
    );
    const dirs = [1, 0, 1];

    const dfs = (i: number, j: number, k: number): boolean => {
        if (vis[i][j][k]) {
            return false;
        }

        vis[i][j][k] = true;
        k += grid[i][j] === '(' ? 1 : -1;

        if (k < 0 || k > m - i + n - j) {
            return false;
        }

        if (i === m - 1 && j === n - 1) {
            return k === 0;
        }

        for (let d = 0; d < 2; ++d) {
            const x = i + dirs[d],
                y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
                return true;
            }
        }

        return false;
    };

    return dfs(0, 0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>一个括号字符串是一个 <strong>非空</strong>&nbsp;且只包含&nbsp;<code>'('</code>&nbsp;和&nbsp;<code>')'</code>&nbsp;的字符串。如果下面&nbsp;<strong>任意</strong>&nbsp;条件为&nbsp;<strong>真</strong>&nbsp;，那么这个括号字符串就是&nbsp;<strong>合法的</strong>&nbsp;。</p>

<ul>
	<li>字符串是&nbsp;<code>()</code>&nbsp;。</li>
	<li>字符串可以表示为&nbsp;<code>AB</code>（<code>A</code>&nbsp;连接&nbsp;<code>B</code>），<code>A</code> 和&nbsp;<code>B</code>&nbsp;都是合法括号序列。</li>
	<li>字符串可以表示为&nbsp;<code>(A)</code>&nbsp;，其中&nbsp;<code>A</code>&nbsp;是合法括号序列。</li>
</ul>

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的括号网格图矩阵&nbsp;<code>grid</code>&nbsp;。网格图中一个&nbsp;<strong>合法括号路径</strong>&nbsp;是满足以下所有条件的一条路径：</p>

<ul>
	<li>路径开始于左上角格子&nbsp;<code>(0, 0)</code>&nbsp;。</li>
	<li>路径结束于右下角格子&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。</li>
	<li>路径每次只会向 <strong>下</strong>&nbsp;或者向 <strong>右</strong>&nbsp;移动。</li>
	<li>路径经过的格子组成的括号字符串是<strong>&nbsp;合法</strong>&nbsp;的。</li>
</ul>

<p>如果网格图中存在一条 <strong>合法括号路径</strong>&nbsp;，请返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2267.Check%20if%20There%20Is%20a%20Valid%20Parentheses%20String%20Path/images/example1drawio.png" style="width: 521px; height: 300px;" /></p>

<pre>
<b>输入：</b>grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
<b>输出：</b>true
<b>解释：</b>上图展示了两条路径，它们都是合法括号字符串路径。
第一条路径得到的合法字符串是 "()(())" 。
第二条路径得到的合法字符串是 "((()))" 。
注意可能有其他的合法括号字符串路径。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2267.Check%20if%20There%20Is%20a%20Valid%20Parentheses%20String%20Path/images/example2drawio.png" style="width: 165px; height: 165px;" /></p>

<pre>
<b>输入：</b>grid = [[")",")"],["(","("]]
<b>输出：</b>false
<b>解释：</b>两条可行路径分别得到 "))(" 和 ")((" 。由于它们都不是合法括号字符串，我们返回 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是&nbsp;<code>'('</code>&nbsp;，要么是&nbsp;<code>')'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 剪枝

我们记矩阵的行数为 $m$，列数为 $n$。

如果 $m + n - 1$ 为奇数，或者左上角和右下角的括号不匹配，那么一定不存在合法路径，直接返回 $\text{false}$。

否则，我们设计一个函数 $\textit{dfs}(i, j, k)$，表示从 $(i, j)$ 出发，且当前括号的平衡度为 $k$，是否存在合法路径。其中，平衡度 $k$ 的定义为：从 $(0, 0)$ 到 $(i, j)$ 的路径中，左括号的个数减去右括号的个数。

如果平衡度 $k$ 小于 $0$ 或者大于 $m + n - i - j$，那么一定不存在合法路径，直接返回 $\text{false}$。如果 $(i, j)$ 正好是右下角的格子，那么只有当 $k = 0$ 时才存在合法路径。否则，我们枚举 $(i, j)$ 的下一个格子 $(x, y)$，如果 $(x, y)$ 是合法的格子且 $\textit{dfs}(x, y, k)$ 为 $\text{true}$，那么就存在合法路径。

时间复杂度 $O(m \times n \times (m + n))$，空间复杂度 $O(m \times n \times (m + n))$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasValidPath(self, grid: List[List[str]]) -> bool:
        @cache
        def dfs(i: int, j: int, k: int) -> bool:
            d = 1 if grid[i][j] == "(" else -1
            k += d
            if k < 0 or k > m - i + n - j:
                return False
            if i == m - 1 and j == n - 1:
                return k == 0
            for a, b in pairwise((0, 1, 0)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and dfs(x, y, k):
                    return True
            return False

        m, n = len(grid), len(grid[0])
        if (m + n - 1) % 2 or grid[0][0] == ")" or grid[m - 1][n - 1] == "(":
            return False
        return dfs(0, 0, 0)
```

#### Java

```java
class Solution {
    private int m, n;
    private char[][] grid;
    private boolean[][][] vis;

    public boolean hasValidPath(char[][] grid) {
        m = grid.length;
        n = grid[0].length;
        if ((m + n - 1) % 2 == 1 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        this.grid = grid;
        vis = new boolean[m][n][m + n];
        return dfs(0, 0, 0);
    }

    private boolean dfs(int i, int j, int k) {
        if (vis[i][j][k]) {
            return false;
        }
        vis[i][j][k] = true;
        k += grid[i][j] == '(' ? 1 : -1;
        if (k < 0 || k > m - i + n - j) {
            return false;
        }
        if (i == m - 1 && j == n - 1) {
            return k == 0;
        }
        final int[] dirs = {1, 0, 1};
        for (int d = 0; d < 2; ++d) {
            int x = i + dirs[d], y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
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
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }
        bool vis[m][n][m + n];
        memset(vis, false, sizeof(vis));
        int dirs[3] = {1, 0, 1};
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool {
            if (vis[i][j][k]) {
                return false;
            }
            vis[i][j][k] = true;
            k += grid[i][j] == '(' ? 1 : -1;
            if (k < 0 || k > m - i + n - j) {
                return false;
            }
            if (i == m - 1 && j == n - 1) {
                return k == 0;
            }
            for (int d = 0; d < 2; ++d) {
                int x = i + dirs[d], y = j + dirs[d + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
                    return true;
                }
            }
            return false;
        };
        return dfs(0, 0, 0);
    }
};
```

#### Go

```go
func hasValidPath(grid [][]byte) bool {
	m, n := len(grid), len(grid[0])
	if (m+n-1)%2 == 1 || grid[0][0] == ')' || grid[m-1][n-1] == '(' {
		return false
	}
	vis := make([][][]bool, m)
	for i := range vis {
		vis[i] = make([][]bool, n)
		for j := range vis[i] {
			vis[i][j] = make([]bool, m+n)
		}
	}
	dirs := [3]int{1, 0, 1}
	var dfs func(i, j, k int) bool
	dfs = func(i, j, k int) bool {
		if vis[i][j][k] {
			return false
		}
		vis[i][j][k] = true
		if grid[i][j] == '(' {
			k++
		} else {
			k--
		}
		if k < 0 || k > m-i+n-j {
			return false
		}
		if i == m-1 && j == n-1 {
			return k == 0
		}
		for d := 0; d < 2; d++ {
			x, y := i+dirs[d], j+dirs[d+1]
			if x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k) {
				return true
			}
		}
		return false
	}
	return dfs(0, 0, 0)
}
```

#### TypeScript

```ts
function hasValidPath(grid: string[][]): boolean {
    const m = grid.length,
        n = grid[0].length;

    if ((m + n - 1) % 2 || grid[0][0] === ')' || grid[m - 1][n - 1] === '(') {
        return false;
    }

    const vis: boolean[][][] = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(m + n).fill(false)),
    );
    const dirs = [1, 0, 1];

    const dfs = (i: number, j: number, k: number): boolean => {
        if (vis[i][j][k]) {
            return false;
        }

        vis[i][j][k] = true;
        k += grid[i][j] === '(' ? 1 : -1;

        if (k < 0 || k > m - i + n - j) {
            return false;
        }

        if (i === m - 1 && j === n - 1) {
            return k === 0;
        }

        for (let d = 0; d < 2; ++d) {
            const x = i + dirs[d],
                y = j + dirs[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && dfs(x, y, k)) {
                return true;
            }
        }

        return false;
    };

    return dfs(0, 0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2268. 最少按键次数 🔒](https://leetcode.cn/problems/minimum-number-of-keypresses){#2268}

{{< tabs "2268" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumKeypresses(self, s: str) -> int:
        cnt = Counter(s)
        ans, k = 0, 1
        for i, x in enumerate(sorted(cnt.values(), reverse=True), 1):
            ans += k * x
            if i % 9 == 0:
                k += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumKeypresses(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0, k = 1;
        for (int i = 1; i <= 26; ++i) {
            ans += k * cnt[26 - i];
            if (i % 9 == 0) {
                ++k;
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
    int minimumKeypresses(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        sort(begin(cnt), end(cnt), greater<int>());
        int ans = 0, k = 1;
        for (int i = 1; i <= 26; ++i) {
            ans += k * cnt[i - 1];
            if (i % 9 == 0) {
                ++k;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumKeypresses(s string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	sort.Ints(cnt)
	k := 1
	for i := 1; i <= 26; i++ {
		ans += k * cnt[26-i]
		if i%9 == 0 {
			k++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumKeypresses(s: string): number {
    const cnt: number[] = Array(26).fill(0);
    const a = 'a'.charCodeAt(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - a];
    }
    cnt.sort((a, b) => b - a);
    let [ans, k] = [0, 1];
    for (let i = 1; i <= 26; ++i) {
        ans += k * cnt[i - 1];
        if (i % 9 === 0) {
            ++k;
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

<p>你有一个 9 键键盘，按键按 1 到 9 编号，每个按键对应着几个英文小写字母。你可以决定每个按键对应哪些英文字母，但要满足如下条件：</p>

<ul>
	<li>26 个英文小写字母必须全部映射到这 9 个按键上。</li>
	<li>每个英文字母只能映射到 <strong>恰好</strong> 一个按键上。</li>
	<li>每个按键 <strong>最多</strong> 对应 3 个英文字母。</li>
</ul>

<p>如果想打出按键上的第一个字母，只需要按一次。如果想打出按键上的第二个字母，则需要按两次，依次类推。</p>

<p>给你一个字符串 <code>s</code> ，返回基于你设计的键盘打出 <code>s</code> 需要的<strong> 最少</strong> 按键次数。</p>

<p><b>注意：</b>字母映射到每个按键上，映射的顺序无法进行更改。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2268.Minimum%20Number%20of%20Keypresses/images/image-20220505184346-1.png" style="width: 300px; height: 293px;" />
<pre>
<strong>输入：</strong>s = "apple"
<strong>输出：</strong>5
<strong>解释：</strong>上图所示为设置键盘的最佳方法之一。
按按键 1 一次输入 'a' 。
按按键 6 一次输入 'p' 。
按按键 6 一次输入 'p' 。
按按键 5 一次输入 'l' 。
按按键 3 一次输入 'e' 。
总共按按键 5 次，所以返回 5 。</pre>

<p><strong>示例 2 ：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2268.Minimum%20Number%20of%20Keypresses/images/image-20220505203823-1.png" style="width: 300px; height: 288px;" />
<pre>
<strong>输入：</strong>s = "abcdefghijkl"
<strong>输出：</strong>15
<strong>解释：</strong>上图所示为设置键盘的最佳方法之一。
字母 'a' 到 'i' 每个只需要按一次按键。
按按键 1 两次输入 'j' 。
按按键 2 两次输入 'k' 。
按按键 3 两次输入 'l' 。
总共按按键 15 次，所以返回 15 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 贪心

我们首先统计字符串 $s$ 中每个字符出现的次数，记录在数组或者哈希表 $\textit{cnt}$ 中。

题目要求按键次数最少，那么出现最多的 $9$ 个字符应该对应按键 $1$ 到按键 $9$，出现次数第 $10$ 到第 $18$ 多的字符再次对应按键 $1$ 到按键 $9$，以此类推。

因此，我们可以将 $\textit{cnt}$ 中的值按照从大到小的顺序排序，然后按照 $1$ 到 $9$ 的顺序依次分配给按键，每次分配完 $9$ 个字符后，按键次数加 $1$。

时间复杂度 $O(n + |\Sigma| \times \log |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度，而 $\Sigma$ 是字符串 $s$ 中出现的字符集合，本题中 $\Sigma$ 是小写字母集合，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumKeypresses(self, s: str) -> int:
        cnt = Counter(s)
        ans, k = 0, 1
        for i, x in enumerate(sorted(cnt.values(), reverse=True), 1):
            ans += k * x
            if i % 9 == 0:
                k += 1
        return ans
```

#### Java

```java
class Solution {
    public int minimumKeypresses(String s) {
        int[] cnt = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        Arrays.sort(cnt);
        int ans = 0, k = 1;
        for (int i = 1; i <= 26; ++i) {
            ans += k * cnt[26 - i];
            if (i % 9 == 0) {
                ++k;
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
    int minimumKeypresses(string s) {
        int cnt[26]{};
        for (char& c : s) {
            ++cnt[c - 'a'];
        }
        sort(begin(cnt), end(cnt), greater<int>());
        int ans = 0, k = 1;
        for (int i = 1; i <= 26; ++i) {
            ans += k * cnt[i - 1];
            if (i % 9 == 0) {
                ++k;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumKeypresses(s string) (ans int) {
	cnt := make([]int, 26)
	for _, c := range s {
		cnt[c-'a']++
	}
	sort.Ints(cnt)
	k := 1
	for i := 1; i <= 26; i++ {
		ans += k * cnt[26-i]
		if i%9 == 0 {
			k++
		}
	}
	return
}
```

#### TypeScript

```ts
function minimumKeypresses(s: string): number {
    const cnt: number[] = Array(26).fill(0);
    const a = 'a'.charCodeAt(0);
    for (const c of s) {
        ++cnt[c.charCodeAt(0) - a];
    }
    cnt.sort((a, b) => b - a);
    let [ans, k] = [0, 1];
    for (let i = 1; i <= 26; ++i) {
        ans += k * cnt[i - 1];
        if (i % 9 === 0) {
            ++k;
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

# [2269. 找到一个数字的 K 美丽值](https://leetcode.cn/problems/find-the-k-beauty-of-a-number){#2269}

{{< tabs "2269" >}}

{{% tab "python" %}}
```python
class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        x, p = 0, 1
        t = num
        for _ in range(k):
            t, v = divmod(t, 10)
            x = p * v + x
            p *= 10
        ans = int(x != 0 and num % x == 0)
        p //= 10
        while t:
            x //= 10
            t, v = divmod(t, 10)
            x = p * v + x
            ans += int(x != 0 and num % x == 0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int divisorSubstrings(int num, int k) {
        int x = 0, p = 1;
        int t = num;
        for (; k > 0; --k) {
            int v = t % 10;
            t /= 10;
            x = p * v + x;
            p *= 10;
        }
        int ans = x != 0 && num % x == 0 ? 1 : 0;
        for (p /= 10; t > 0; t /= 10) {
            x /= 10;
            int v = t % 10;
            x = p * v + x;
            ans += (x != 0 && num % x == 0 ? 1 : 0);
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
    int divisorSubstrings(int num, int k) {
        int x = 0;
        long long p = 1;
        int t = num;
        for (; k > 0; --k) {
            int v = t % 10;
            t /= 10;
            x = p * v + x;
            p *= 10;
        }
        int ans = x != 0 && num % x == 0 ? 1 : 0;
        for (p /= 10; t > 0; t /= 10) {
            x /= 10;
            int v = t % 10;
            x = p * v + x;
            ans += (x != 0 && num % x == 0 ? 1 : 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divisorSubstrings(num int, k int) (ans int) {
	x, p, t := 0, 1, num
	for ; k > 0; k-- {
		v := t % 10
		t /= 10
		x = p*v + x
		p *= 10
	}
	if x != 0 && num%x == 0 {
		ans++
	}
	for p /= 10; t > 0; t /= 10 {
		x /= 10
		v := t % 10
		x = p*v + x
		if x != 0 && num%x == 0 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divisorSubstrings(num: number, k: number): number {
    let [x, p, t] = [0, 1, num];
    for (; k > 0; k--) {
        const v = t % 10;
        t = Math.floor(t / 10);
        x = p * v + x;
        p *= 10;
    }
    let ans = x !== 0 && num % x === 0 ? 1 : 0;
    for (p = Math.floor(p / 10); t > 0; t = Math.floor(t / 10)) {
        x = Math.floor(x / 10);
        x = p * (t % 10) + x;
        ans += x !== 0 && num % x === 0 ? 1 : 0;
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

<p>一个整数 <code>num</code>&nbsp;的&nbsp;<strong>k&nbsp;</strong>美丽值定义为&nbsp;<code>num</code>&nbsp;中符合以下条件的&nbsp;<strong>子字符串</strong>&nbsp;数目：</p>

<ul>
	<li>子字符串长度为&nbsp;<code>k</code>&nbsp;。</li>
	<li>子字符串能整除 <code>num</code> 。</li>
</ul>

<p>给你整数&nbsp;<code>num</code> 和&nbsp;<code>k</code>&nbsp;，请你返回<em>&nbsp;</em><code>num</code>&nbsp;的 k 美丽值。</p>

<p>注意：</p>

<ul>
	<li>允许有&nbsp;<strong>前缀</strong>&nbsp;<strong>0</strong>&nbsp;。</li>
	<li><code>0</code>&nbsp;不能整除任何值。</li>
</ul>

<p>一个 <strong>子字符串</strong>&nbsp;是一个字符串里的连续一段字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>num = 240, k = 2
<b>输出：</b>2
<b>解释：</b>以下是 num 里长度为 k 的子字符串：
- "<em><strong>24</strong></em>0" 中的 "24" ：24 能整除 240 。
- "2<em><strong>40</strong></em>" 中的 "40" ：40 能整除 240 。
所以，k 美丽值为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>num = 430043, k = 2
<b>输出：</b>2
<b>解释：</b>以下是 num 里长度为 k 的子字符串：
- "<em><strong>43</strong></em>0043" 中的 "43" ：43 能整除 430043 。
- "4<em><strong>30</strong></em>043" 中的 "30" ：30 不能整除 430043 。
- "43<em><strong>00</strong></em>43" 中的 "00" ：0 不能整除 430043 。
- "430<em><strong>04</strong></em>3" 中的 "04" ：4 不能整除 430043 。
- "4300<em><strong>43</strong></em>" 中的 "43" ：43 能整除 430043 。
所以，k 美丽值为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= num.length</code>&nbsp;（将&nbsp;<code>num</code>&nbsp;视为字符串）</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以将 $num$ 转换为字符串 $s$，然后枚举 $s$ 的所有长度为 $k$ 的子字符串，将其转换为整数 $t$，判断 $t$ 是否能整除 $num$，如果能则答案加一。

时间复杂度 $O(\log num \times k)$，空间复杂度 $O(\log num + k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        ans = 0
        s = str(num)
        for i in range(len(s) - k + 1):
            t = int(s[i : i + k])
            if t and num % t == 0:
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int divisorSubstrings(int num, int k) {
        int ans = 0;
        String s = "" + num;
        for (int i = 0; i < s.length() - k + 1; ++i) {
            int t = Integer.parseInt(s.substring(i, i + k));
            if (t != 0 && num % t == 0) {
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
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        string s = to_string(num);
        for (int i = 0; i < s.size() - k + 1; ++i) {
            int t = stoi(s.substr(i, k));
            ans += t && num % t == 0;
        }
        return ans;
    }
};
```

#### Go

```go
func divisorSubstrings(num int, k int) int {
	ans := 0
	s := strconv.Itoa(num)
	for i := 0; i < len(s)-k+1; i++ {
		t, _ := strconv.Atoi(s[i : i+k])
		if t > 0 && num%t == 0 {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function divisorSubstrings(num: number, k: number): number {
    let ans = 0;
    const s = num.toString();
    for (let i = 0; i < s.length - k + 1; ++i) {
        const t = parseInt(s.substring(i, i + k));
        if (t !== 0 && num % t === 0) {
            ++ans;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：滑动窗口

我们可以维护一个长度为 $k$ 的滑动窗口，初始时窗口中包含 $num$ 的最低 $k$ 位数字，然后每次向右移动一位，更新窗口中的数字，判断窗口中的数字是否能整除 $num$，如果能则答案加一。

时间复杂度 $O(\log num)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        x, p = 0, 1
        t = num
        for _ in range(k):
            t, v = divmod(t, 10)
            x = p * v + x
            p *= 10
        ans = int(x != 0 and num % x == 0)
        p //= 10
        while t:
            x //= 10
            t, v = divmod(t, 10)
            x = p * v + x
            ans += int(x != 0 and num % x == 0)
        return ans
```

#### Java

```java
class Solution {
    public int divisorSubstrings(int num, int k) {
        int x = 0, p = 1;
        int t = num;
        for (; k > 0; --k) {
            int v = t % 10;
            t /= 10;
            x = p * v + x;
            p *= 10;
        }
        int ans = x != 0 && num % x == 0 ? 1 : 0;
        for (p /= 10; t > 0; t /= 10) {
            x /= 10;
            int v = t % 10;
            x = p * v + x;
            ans += (x != 0 && num % x == 0 ? 1 : 0);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int x = 0;
        long long p = 1;
        int t = num;
        for (; k > 0; --k) {
            int v = t % 10;
            t /= 10;
            x = p * v + x;
            p *= 10;
        }
        int ans = x != 0 && num % x == 0 ? 1 : 0;
        for (p /= 10; t > 0; t /= 10) {
            x /= 10;
            int v = t % 10;
            x = p * v + x;
            ans += (x != 0 && num % x == 0 ? 1 : 0);
        }
        return ans;
    }
};
```

#### Go

```go
func divisorSubstrings(num int, k int) (ans int) {
	x, p, t := 0, 1, num
	for ; k > 0; k-- {
		v := t % 10
		t /= 10
		x = p*v + x
		p *= 10
	}
	if x != 0 && num%x == 0 {
		ans++
	}
	for p /= 10; t > 0; t /= 10 {
		x /= 10
		v := t % 10
		x = p*v + x
		if x != 0 && num%x == 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function divisorSubstrings(num: number, k: number): number {
    let [x, p, t] = [0, 1, num];
    for (; k > 0; k--) {
        const v = t % 10;
        t = Math.floor(t / 10);
        x = p * v + x;
        p *= 10;
    }
    let ans = x !== 0 && num % x === 0 ? 1 : 0;
    for (p = Math.floor(p / 10); t > 0; t = Math.floor(t / 10)) {
        x = Math.floor(x / 10);
        x = p * (t % 10) + x;
        ans += x !== 0 && num % x === 0 ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
