---
title: "2840_判断通过操作能否让字符串相等 II"
date: 2025-10-08T18:39:37+08:00
weight: 5
tags: [前缀和, 哈希表, 图, 字符串, 强连通分量, 排序, 数学, 数组, 枚举, 树, 滑动窗口, 组合数学, 贪心]
---

{{< markmap >}}
### [2840_判断通过操作能否让字符串相等 II](#2840)
#### [哈希表](#2840)
#### [字符串](#2840)
#### [排序](#2840)
### [2841_几乎唯一子数组的最大和](#2841)
#### [数组](#2841)
#### [哈希表](#2841)
#### [滑动窗口](#2841)
### [2842_统计一个字符串的 k 子序列美丽值最大的数目](#2842)
#### [贪心](#2842)
#### [哈希表](#2842)
#### [数学](#2842)
#### [字符串](#2842)
#### [组合数学](#2842)
### [2843_统计对称整数的数目](#2843)
#### [数学](#2843)
#### [枚举](#2843)
### [2844_生成特殊数字的最少操作](#2844)
#### [贪心](#2844)
#### [数学](#2844)
#### [字符串](#2844)
#### [枚举](#2844)
### [2845_统计趣味子数组的数目](#2845)
#### [数组](#2845)
#### [哈希表](#2845)
#### [前缀和](#2845)
### [2846_边权重均等查询](#2846)
#### [树](#2846)
#### [图](#2846)
#### [数组](#2846)
#### [强连通分量](#2846)
### [2847_给定数字乘积的最小数字 🔒](#2847)
#### [贪心](#2847)
#### [数学](#2847)
### [2848_与车相交的点](#2848)
#### [数组](#2848)
#### [哈希表](#2848)
#### [前缀和](#2848)
### [2849_判断能否在给定时间到达单元格](#2849)
#### [数学](#2849)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2840_判断通过操作能否让字符串相等 II
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 2841_几乎唯一子数组的最大和
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2842_统计一个字符串的 k 子序列美丽值最大的数目
___
#### 贪心
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 组合数学
---
### 2843_统计对称整数的数目
___
#### 数学
___
#### 枚举
---
### 2844_生成特殊数字的最少操作
___
#### 贪心
___
#### 数学
___
#### 字符串
___
#### 枚举
---
### 2845_统计趣味子数组的数目
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 2846_边权重均等查询
___
#### 树
___
#### 图
___
#### 数组
___
#### 强连通分量
---
### 2847_给定数字乘积的最小数字 🔒
___
#### 贪心
___
#### 数学
---
### 2848_与车相交的点
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 2849_判断能否在给定时间到达单元格
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 哈希表 | 图 |
| 字符串 | 强连通分量 | 排序 |
| 数学 | 数组 | 枚举 |
| 树 | 滑动窗口 | 组合数学 |
| 贪心 |  |  |

# [2840. 判断通过操作能否让字符串相等 II](https://leetcode.cn/problems/check-if-strings-can-be-made-equal-with-operations-ii){#2840}

{{< tabs "2840" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return sorted(s1[::2]) == sorted(s2[::2]) and sorted(s1[1::2]) == sorted(
            s2[1::2]
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkStrings(String s1, String s2) {
        int[][] cnt = new int[2][26];
        for (int i = 0; i < s1.length(); ++i) {
            ++cnt[i & 1][s1.charAt(i) - 'a'];
            --cnt[i & 1][s2.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] != 0 || cnt[1][i] != 0) {
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
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[i & 1][s1[i] - 'a'];
            --cnt[i & 1][s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) {
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
func checkStrings(s1 string, s2 string) bool {
	cnt := [2][26]int{}
	for i := 0; i < len(s1); i++ {
		cnt[i&1][s1[i]-'a']++
		cnt[i&1][s2[i]-'a']--
	}
	for i := 0; i < 26; i++ {
		if cnt[0][i] != 0 || cnt[1][i] != 0 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkStrings(s1: string, s2: string): boolean {
    const cnt: number[][] = Array.from({ length: 2 }, () => Array.from({ length: 26 }, () => 0));
    for (let i = 0; i < s1.length; ++i) {
        ++cnt[i & 1][s1.charCodeAt(i) - 97];
        --cnt[i & 1][s2.charCodeAt(i) - 97];
    }
    for (let i = 0; i < 26; ++i) {
        if (cnt[0][i] || cnt[1][i]) {
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

<p>给你两个字符串&nbsp;<code>s1</code>&nbsp;和&nbsp;<code>s2</code>&nbsp;，两个字符串长度都为&nbsp;<code>n</code>&nbsp;，且只包含&nbsp;<strong>小写&nbsp;</strong>英文字母。</p>

<p>你可以对两个字符串中的 <strong>任意一个</strong>&nbsp;执行以下操作 <strong>任意</strong>&nbsp;次：</p>

<ul>
	<li>选择两个下标&nbsp;<code>i</code> 和&nbsp;<code>j</code>&nbsp;，满足 <code>i &lt; j</code>&nbsp;且 <code>j - i</code>&nbsp;是 <strong>偶数</strong>，然后 <strong>交换</strong> 这个字符串中两个下标对应的字符。</li>
</ul>

<p>&nbsp;</p>

<p>如果你可以让字符串<em>&nbsp;</em><code>s1</code><em> </em>和<em>&nbsp;</em><code>s2</code>&nbsp;相等，那么返回 <code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s1 = "abcdba", s2 = "cabdab"
<b>输出：</b>true
<b>解释：</b>我们可以对 s1 执行以下操作：
- 选择下标 i = 0 ，j = 2 ，得到字符串 s1 = "cbadba" 。
- 选择下标 i = 2 ，j = 4 ，得到字符串 s1 = "cbbdaa" 。
- 选择下标 i = 1 ，j = 5 ，得到字符串 s1 = "cabdab" = s2 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s1 = "abe", s2 = "bea"
<b>输出：</b>false
<b>解释：</b>无法让两个字符串相等。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s1</code> 和&nbsp;<code>s2</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们观察题目中的操作，可以发现，如果字符串的两个下标 $i$ 和 $j$ 的奇偶性相同，那么它们可以通过交换改变顺序。

因此，我们可以统计两个字符串中奇数下标的字符的出现次数，以及偶数下标的字符的出现次数，如果两个字符串的统计结果相同，那么我们就可以通过操作使得两个字符串相等。

时间复杂度 $O(n + |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串的长度，而 $\Sigma$ 是字符集。

相似题目：

-   [2839. 判断通过操作能否让字符串相等 I](https://github.com/doocs/leetcode/blob/main/solution/2800-2899/2839.Check%20if%20Strings%20Can%20be%20Made%20Equal%20With%20Operations%20I/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return sorted(s1[::2]) == sorted(s2[::2]) and sorted(s1[1::2]) == sorted(
            s2[1::2]
        )
```

#### Java

```java
class Solution {
    public boolean checkStrings(String s1, String s2) {
        int[][] cnt = new int[2][26];
        for (int i = 0; i < s1.length(); ++i) {
            ++cnt[i & 1][s1.charAt(i) - 'a'];
            --cnt[i & 1][s2.charAt(i) - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] != 0 || cnt[1][i] != 0) {
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
    bool checkStrings(string s1, string s2) {
        vector<vector<int>> cnt(2, vector<int>(26, 0));
        for (int i = 0; i < s1.size(); ++i) {
            ++cnt[i & 1][s1[i] - 'a'];
            --cnt[i & 1][s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkStrings(s1 string, s2 string) bool {
	cnt := [2][26]int{}
	for i := 0; i < len(s1); i++ {
		cnt[i&1][s1[i]-'a']++
		cnt[i&1][s2[i]-'a']--
	}
	for i := 0; i < 26; i++ {
		if cnt[0][i] != 0 || cnt[1][i] != 0 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function checkStrings(s1: string, s2: string): boolean {
    const cnt: number[][] = Array.from({ length: 2 }, () => Array.from({ length: 26 }, () => 0));
    for (let i = 0; i < s1.length; ++i) {
        ++cnt[i & 1][s1.charCodeAt(i) - 97];
        --cnt[i & 1][s2.charCodeAt(i) - 97];
    }
    for (let i = 0; i < 26; ++i) {
        if (cnt[0][i] || cnt[1][i]) {
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

# [2841. 几乎唯一子数组的最大和](https://leetcode.cn/problems/maximum-sum-of-almost-unique-subarray){#2841}

{{< tabs "2841" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        cnt = Counter(nums[:k])
        s = sum(nums[:k])
        ans = s if len(cnt) >= m else 0
        for i in range(k, len(nums)):
            cnt[nums[i]] += 1
            cnt[nums[i - k]] -= 1
            s += nums[i] - nums[i - k]
            if cnt[nums[i - k]] == 0:
                cnt.pop(nums[i - k])
            if len(cnt) >= m:
                ans = max(ans, s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxSum(List<Integer> nums, int m, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int n = nums.size();
        long s = 0;
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums.get(i), 1, Integer::sum);
            s += nums.get(i);
        }
        long ans = cnt.size() >= m ? s : 0;
        for (int i = k; i < n; ++i) {
            cnt.merge(nums.get(i), 1, Integer::sum);
            if (cnt.merge(nums.get(i - k), -1, Integer::sum) == 0) {
                cnt.remove(nums.get(i - k));
            }
            s += nums.get(i) - nums.get(i - k);
            if (cnt.size() >= m) {
                ans = Math.max(ans, s);
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
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> cnt;
        long long s = 0;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            cnt[nums[i]]++;
            s += nums[i];
        }
        long long ans = cnt.size() >= m ? s : 0;
        for (int i = k; i < n; ++i) {
            cnt[nums[i]]++;
            if (--cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            s += nums[i] - nums[i - k];
            if (cnt.size() >= m) {
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSum(nums []int, m int, k int) int64 {
	cnt := map[int]int{}
	var s int64
	for _, x := range nums[:k] {
		cnt[x]++
		s += int64(x)
	}
	var ans int64
	if len(cnt) >= m {
		ans = s
	}
	for i := k; i < len(nums); i++ {
		cnt[nums[i]]++
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			delete(cnt, nums[i-k])
		}
		s += int64(nums[i]) - int64(nums[i-k])
		if len(cnt) >= m {
			ans = max(ans, s)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSum(nums: number[], m: number, k: number): number {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    let s = 0;
    for (let i = 0; i < k; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) || 0) + 1);
        s += nums[i];
    }
    let ans = cnt.size >= m ? s : 0;
    for (let i = k; i < n; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) || 0) + 1);
        cnt.set(nums[i - k], cnt.get(nums[i - k])! - 1);
        if (cnt.get(nums[i - k]) === 0) {
            cnt.delete(nums[i - k]);
        }
        s += nums[i] - nums[i - k];
        if (cnt.size >= m) {
            ans = Math.max(ans, s);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public long MaxSum(IList<int> nums, int m, int k) {
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        int n = nums.Count;
        long s = 0;

        for (int i = 0; i < k; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            s += nums[i];
        }

        long ans = cnt.Count >= m ? s : 0;

        for (int i = k; i < n; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            if (cnt.ContainsKey(nums[i - k])) {
                cnt[nums[i - k]]--;
                if (cnt[nums[i - k]] == 0) {
                    cnt.Remove(nums[i - k]);
                }
            }

            s += nums[i] - nums[i - k];

            if (cnt.Count >= m) {
                ans = Math.Max(ans, s);
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和两个正整数&nbsp;<code>m</code>&nbsp;和&nbsp;<code>k</code>&nbsp;。</p>

<p>请你返回 <code>nums</code>&nbsp;中长度为 <code>k</code>&nbsp;的&nbsp;<strong>几乎唯一</strong>&nbsp;子数组的 <strong>最大和</strong>&nbsp;，如果不存在几乎唯一子数组，请你返回 <code>0</code>&nbsp;。</p>

<p>如果 <code>nums</code>&nbsp;的一个子数组有至少 <code>m</code>&nbsp;个互不相同的元素，我们称它是 <strong>几乎唯一</strong>&nbsp;子数组。</p>

<p>子数组指的是一个数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,6,7,3,1,7], m = 3, k = 4
<b>输出：</b>18
<b>解释：</b>总共有 3 个长度为 k = 4 的几乎唯一子数组。分别为 [2, 6, 7, 3] ，[6, 7, 3, 1] 和 [7, 3, 1, 7] 。这些子数组中，和最大的是 [2, 6, 7, 3] ，和为 18 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [5,9,9,2,4,5,4], m = 1, k = 3
<b>输出：</b>23
<b>解释：</b>总共有 5 个长度为 k = 3 的几乎唯一子数组。分别为 [5, 9, 9] ，[9, 9, 2] ，[9, 2, 4] ，[2, 4, 5] 和 [4, 5, 4] 。这些子数组中，和最大的是 [5, 9, 9] ，和为 23 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,1,2,1,2,1], m = 3, k = 3
<b>输出：</b>0
<b>解释：</b>输入数组中不存在长度为 <code>k = 3</code> 的子数组含有至少  <code>m = 3</code> 个互不相同元素的子数组。所以不存在几乎唯一子数组，最大和为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= m &lt;= k &lt;= nums.length</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 哈希表

我们可以遍历数组 $nums$，维护一个大小为 $k$ 的窗口，用哈希表 $cnt$ 统计窗口中每个元素的出现次数，用变量 $s$ 统计窗口中所有元素的和。如果 $cnt$ 中不同元素的个数大于等于 $m$，那么我们就更新答案 $ans = \max(ans, s)$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        cnt = Counter(nums[:k])
        s = sum(nums[:k])
        ans = s if len(cnt) >= m else 0
        for i in range(k, len(nums)):
            cnt[nums[i]] += 1
            cnt[nums[i - k]] -= 1
            s += nums[i] - nums[i - k]
            if cnt[nums[i - k]] == 0:
                cnt.pop(nums[i - k])
            if len(cnt) >= m:
                ans = max(ans, s)
        return ans
```

#### Java

```java
class Solution {
    public long maxSum(List<Integer> nums, int m, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int n = nums.size();
        long s = 0;
        for (int i = 0; i < k; ++i) {
            cnt.merge(nums.get(i), 1, Integer::sum);
            s += nums.get(i);
        }
        long ans = cnt.size() >= m ? s : 0;
        for (int i = k; i < n; ++i) {
            cnt.merge(nums.get(i), 1, Integer::sum);
            if (cnt.merge(nums.get(i - k), -1, Integer::sum) == 0) {
                cnt.remove(nums.get(i - k));
            }
            s += nums.get(i) - nums.get(i - k);
            if (cnt.size() >= m) {
                ans = Math.max(ans, s);
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
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> cnt;
        long long s = 0;
        int n = nums.size();
        for (int i = 0; i < k; ++i) {
            cnt[nums[i]]++;
            s += nums[i];
        }
        long long ans = cnt.size() >= m ? s : 0;
        for (int i = k; i < n; ++i) {
            cnt[nums[i]]++;
            if (--cnt[nums[i - k]] == 0) {
                cnt.erase(nums[i - k]);
            }
            s += nums[i] - nums[i - k];
            if (cnt.size() >= m) {
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSum(nums []int, m int, k int) int64 {
	cnt := map[int]int{}
	var s int64
	for _, x := range nums[:k] {
		cnt[x]++
		s += int64(x)
	}
	var ans int64
	if len(cnt) >= m {
		ans = s
	}
	for i := k; i < len(nums); i++ {
		cnt[nums[i]]++
		cnt[nums[i-k]]--
		if cnt[nums[i-k]] == 0 {
			delete(cnt, nums[i-k])
		}
		s += int64(nums[i]) - int64(nums[i-k])
		if len(cnt) >= m {
			ans = max(ans, s)
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxSum(nums: number[], m: number, k: number): number {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    let s = 0;
    for (let i = 0; i < k; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) || 0) + 1);
        s += nums[i];
    }
    let ans = cnt.size >= m ? s : 0;
    for (let i = k; i < n; ++i) {
        cnt.set(nums[i], (cnt.get(nums[i]) || 0) + 1);
        cnt.set(nums[i - k], cnt.get(nums[i - k])! - 1);
        if (cnt.get(nums[i - k]) === 0) {
            cnt.delete(nums[i - k]);
        }
        s += nums[i] - nums[i - k];
        if (cnt.size >= m) {
            ans = Math.max(ans, s);
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public long MaxSum(IList<int> nums, int m, int k) {
        Dictionary<int, int> cnt = new Dictionary<int, int>();
        int n = nums.Count;
        long s = 0;

        for (int i = 0; i < k; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            s += nums[i];
        }

        long ans = cnt.Count >= m ? s : 0;

        for (int i = k; i < n; ++i) {
            if (!cnt.ContainsKey(nums[i])) {
                cnt[nums[i]] = 1;
            }
            else {
                cnt[nums[i]]++;
            }
            if (cnt.ContainsKey(nums[i - k])) {
                cnt[nums[i - k]]--;
                if (cnt[nums[i - k]] == 0) {
                    cnt.Remove(nums[i - k]);
                }
            }

            s += nums[i] - nums[i - k];

            if (cnt.Count >= m) {
                ans = Math.Max(ans, s);
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

# [2842. 统计一个字符串的 k 子序列美丽值最大的数目](https://leetcode.cn/problems/count-k-subsequences-of-a-string-with-maximum-beauty){#2842}

{{< tabs "2842" >}}

{{% tab "python" %}}
```python
class Solution:
    def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:
        f = Counter(s)
        if len(f) < k:
            return 0
        mod = 10**9 + 7
        vs = sorted(f.values(), reverse=True)
        val = vs[k - 1]
        x = vs.count(val)
        ans = 1
        for v in vs:
            if v == val:
                break
            k -= 1
            ans = ans * v % mod
        ans = ans * comb(x, k) * pow(val, k, mod) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int countKSubsequencesWithMaxBeauty(String s, int k) {
        int[] f = new int[26];
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (++f[s.charAt(i) - 'a'] == 1) {
                ++cnt;
            }
        }
        if (cnt < k) {
            return 0;
        }
        Integer[] vs = new Integer[cnt];
        for (int i = 0, j = 0; i < 26; ++i) {
            if (f[i] > 0) {
                vs[j++] = f[i];
            }
        }
        Arrays.sort(vs, (a, b) -> b - a);
        long ans = 1;
        int val = vs[k - 1];
        int x = 0;
        for (int v : vs) {
            if (v == val) {
                ++x;
            }
        }
        for (int v : vs) {
            if (v == val) {
                break;
            }
            --k;
            ans = ans * v % mod;
        }
        int[][] c = new int[x + 1][x + 1];
        for (int i = 0; i <= x; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
        ans = ((ans * c[x][k]) % mod) * qpow(val, k) % mod;
        return (int) ans;
    }

    private long qpow(long a, int n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
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
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int f[26]{};
        int cnt = 0;
        for (char& c : s) {
            if (++f[c - 'a'] == 1) {
                ++cnt;
            }
        }
        if (cnt < k) {
            return 0;
        }
        vector<int> vs(cnt);
        for (int i = 0, j = 0; i < 26; ++i) {
            if (f[i]) {
                vs[j++] = f[i];
            }
        }
        sort(vs.rbegin(), vs.rend());
        const int mod = 1e9 + 7;
        long long ans = 1;
        int val = vs[k - 1];
        int x = 0;
        for (int v : vs) {
            x += v == val;
        }
        for (int v : vs) {
            if (v == val) {
                break;
            }
            --k;
            ans = ans * v % mod;
        }
        int c[x + 1][x + 1];
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= x; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        auto qpow = [&](long long a, int n) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        ans = (ans * c[x][k] % mod) * qpow(val, k) % mod;
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countKSubsequencesWithMaxBeauty(s string, k int) int {
	f := [26]int{}
	cnt := 0
	for _, c := range s {
		f[c-'a']++
		if f[c-'a'] == 1 {
			cnt++
		}
	}
	if cnt < k {
		return 0
	}
	vs := []int{}
	for _, x := range f {
		if x > 0 {
			vs = append(vs, x)
		}
	}
	sort.Slice(vs, func(i, j int) bool {
		return vs[i] > vs[j]
	})
	const mod int = 1e9 + 7
	ans := 1
	val := vs[k-1]
	x := 0
	for _, v := range vs {
		if v == val {
			x++
		}
	}
	for _, v := range vs {
		if v == val {
			break
		}
		k--
		ans = ans * v % mod
	}
	c := make([][]int, x+1)
	for i := range c {
		c[i] = make([]int, x+1)
		c[i][0] = 1
		for j := 1; j <= i; j++ {
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod
		}
	}
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	ans = (ans * c[x][k] % mod) * qpow(val, k) % mod
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countKSubsequencesWithMaxBeauty(s: string, k: number): number {
    const f: number[] = new Array(26).fill(0);
    let cnt = 0;
    for (const c of s) {
        const i = c.charCodeAt(0) - 97;
        if (++f[i] === 1) {
            ++cnt;
        }
    }
    if (cnt < k) {
        return 0;
    }
    const mod = BigInt(10 ** 9 + 7);
    const vs: number[] = f.filter(v => v > 0).sort((a, b) => b - a);
    const val = vs[k - 1];
    const x = vs.filter(v => v === val).length;
    let ans = 1n;
    for (const v of vs) {
        if (v === val) {
            break;
        }
        --k;
        ans = (ans * BigInt(v)) % mod;
    }
    const c: number[][] = new Array(x + 1).fill(0).map(() => new Array(k + 1).fill(0));
    for (let i = 0; i <= x; ++i) {
        c[i][0] = 1;
        for (let j = 1; j <= Math.min(i, k); ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Number(mod);
        }
    }
    const qpow = (a: bigint, n: number): bigint => {
        let ans = 1n;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans = (ans * a) % BigInt(mod);
            }
            a = (a * a) % BigInt(mod);
        }
        return ans;
    };
    ans = (((ans * BigInt(c[x][k])) % mod) * qpow(BigInt(val), k)) % mod;
    return Number(ans);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p><strong>k 子序列</strong>指的是 <code>s</code>&nbsp;的一个长度为 <code>k</code>&nbsp;的 <strong>子序列</strong>&nbsp;，且所有字符都是 <strong>唯一</strong>&nbsp;的，也就是说每个字符在子序列里只出现过一次。</p>

<p>定义&nbsp;<code>f(c)</code>&nbsp;为字符 <code>c</code>&nbsp;在 <code>s</code>&nbsp;中出现的次数。</p>

<p>k 子序列的 <strong>美丽值</strong>&nbsp;定义为这个子序列中每一个字符 <code>c</code>&nbsp;的&nbsp;<code>f(c)</code>&nbsp;之 <strong>和</strong>&nbsp;。</p>

<p>比方说，<code>s = "abbbdd"</code>&nbsp;和&nbsp;<code>k = 2</code>&nbsp;，我们有：</p>

<ul>
	<li><code>f('a') = 1</code>, <code>f('b') = 3</code>, <code>f('d') = 2</code></li>
	<li><code>s</code>&nbsp;的部分 k 子序列为：
	<ul>
		<li><code>"<em><strong>ab</strong></em>bbdd"</code> -&gt; <code>"ab"</code>&nbsp;，美丽值为&nbsp;<code>f('a') + f('b') = 4</code></li>
		<li><code>"<em><strong>a</strong></em>bbb<em><strong>d</strong></em>d"</code> -&gt; <code>"ad"</code>&nbsp;，美丽值为&nbsp;<code>f('a') + f('d') = 3</code></li>
		<li><code>"a<em><strong>b</strong></em>bb<em><strong>d</strong></em>d"</code> -&gt; <code>"bd"</code>&nbsp;，美丽值为&nbsp;<code>f('b') + f('d') = 5</code></li>
	</ul>
	</li>
</ul>

<p>请你返回一个整数，表示所有 <strong>k 子序列&nbsp;</strong>里面 <strong>美丽值 </strong>是&nbsp;<strong>最大值</strong>&nbsp;的子序列数目。由于答案可能很大，将结果对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后返回。</p>

<p>一个字符串的子序列指的是从原字符串里面删除一些字符（也可能一个字符也不删除），不改变剩下字符顺序连接得到的新字符串。</p>

<p><strong>注意：</strong></p>

<ul>
	<li><code>f(c)</code> 指的是字符&nbsp;<code>c</code>&nbsp;在字符串&nbsp;<code>s</code>&nbsp;的出现次数，不是在 k 子序列里的出现次数。</li>
	<li>两个 k 子序列如果有任何一个字符在原字符串中的下标不同，则它们是两个不同的子序列。所以两个不同的 k 子序列可能产生相同的字符串。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "bcca", k = 2
<b>输出：</b>4
<b>解释：</b><span style="white-space: normal">s 中我们有 f('a') = 1 ，f('b') = 1 和 f('c') = 2 。</span>
s 的 k 子序列为：
<em><strong>bc</strong></em>ca ，美丽值为 f('b') + f('c') = 3
<em><strong>b</strong></em>c<em><strong>c</strong></em>a ，美丽值为 f('b') + f('c') = 3
<em><strong>b</strong></em>cc<em><strong>a</strong></em> ，美丽值为 f('b') + f('a') = 2
b<em><strong>c</strong></em>c<em><strong>a</strong></em><strong> </strong>，美丽值为 f('c') + f('a') = 3
bc<em><strong>ca</strong></em> ，美丽值为 f('c') + f('a') = 3
总共有 4 个 k 子序列美丽值为最大值 3 。
所以答案为 4 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abbcd", k = 4
<b>输出：</b>2
<b>解释：</b><span style="white-space: normal">s 中我们有 f('a') = 1 ，f('b') = 2&nbsp;，f('c') = 1&nbsp;和</span> f('d') = 1 。
s 的 k 子序列为：
<em><strong>ab</strong></em>b<em><strong>cd</strong></em> ，美丽值为 f('a') + f('b') + f('c') + f('d') = 5
<span style="white-space: normal;"><b><i>a</i></b></span>b<em><strong>bcd</strong></em> ，美丽值为 f('a') + f('b') + f('c') + f('d') = 5 
总共有 2 个 k 子序列美丽值为最大值 5 。
所以答案为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 组合数学

我们先用哈希表 $f$ 统计字符串 $s$ 中每个字符的出现次数，即 $f[c]$ 表示字符 $c$ 在字符串 $s$ 中出现的次数。

由于 $k$ 子序列是字符串 $s$ 中一个长度为 $k$ 的子序列，且字符唯一，因此，如果 $f$ 中不同字符的个数小于 $k$，那么不存在 $k$ 子序列，直接返回 $0$ 即可。

否则，要使得 $k$ 子序列的美丽值最大，我们需要尽可能地让美丽值大的字符尽可能地多地出现在 $k$ 子序列中。因此，我们可以对 $f$ 中的值进行倒序排序，得到一个数组 $vs$。

我们记数组 $vs$ 第 $k$ 个字符的出现次数为 $val$，一共有 $x$ 个字符出现的次数为 $val$。

那么我们先找出出现次数大于 $val$ 的字符，将每个字符出现的次数相乘，得到初始答案 $ans$，剩余的需要选取的字符个数更新为 $k$。我们需要从 $x$ 个字符中选取 $k$ 个字符，因此答案需要乘上组合数 $C_x^k$，最后再乘上 $val^k$，即 $ans = ans \times C_x^k \times val^k$。

注意，这里需要用到快速幂，以及取模操作。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串的长度，而 $\Sigma$ 是字符集。本题中字符集为小写字母，因此 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countKSubsequencesWithMaxBeauty(self, s: str, k: int) -> int:
        f = Counter(s)
        if len(f) < k:
            return 0
        mod = 10**9 + 7
        vs = sorted(f.values(), reverse=True)
        val = vs[k - 1]
        x = vs.count(val)
        ans = 1
        for v in vs:
            if v == val:
                break
            k -= 1
            ans = ans * v % mod
        ans = ans * comb(x, k) * pow(val, k, mod) % mod
        return ans
```

#### Java

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public int countKSubsequencesWithMaxBeauty(String s, int k) {
        int[] f = new int[26];
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (++f[s.charAt(i) - 'a'] == 1) {
                ++cnt;
            }
        }
        if (cnt < k) {
            return 0;
        }
        Integer[] vs = new Integer[cnt];
        for (int i = 0, j = 0; i < 26; ++i) {
            if (f[i] > 0) {
                vs[j++] = f[i];
            }
        }
        Arrays.sort(vs, (a, b) -> b - a);
        long ans = 1;
        int val = vs[k - 1];
        int x = 0;
        for (int v : vs) {
            if (v == val) {
                ++x;
            }
        }
        for (int v : vs) {
            if (v == val) {
                break;
            }
            --k;
            ans = ans * v % mod;
        }
        int[][] c = new int[x + 1][x + 1];
        for (int i = 0; i <= x; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            }
        }
        ans = ((ans * c[x][k]) % mod) * qpow(val, k) % mod;
        return (int) ans;
    }

    private long qpow(long a, int n) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int f[26]{};
        int cnt = 0;
        for (char& c : s) {
            if (++f[c - 'a'] == 1) {
                ++cnt;
            }
        }
        if (cnt < k) {
            return 0;
        }
        vector<int> vs(cnt);
        for (int i = 0, j = 0; i < 26; ++i) {
            if (f[i]) {
                vs[j++] = f[i];
            }
        }
        sort(vs.rbegin(), vs.rend());
        const int mod = 1e9 + 7;
        long long ans = 1;
        int val = vs[k - 1];
        int x = 0;
        for (int v : vs) {
            x += v == val;
        }
        for (int v : vs) {
            if (v == val) {
                break;
            }
            --k;
            ans = ans * v % mod;
        }
        int c[x + 1][x + 1];
        memset(c, 0, sizeof(c));
        for (int i = 0; i <= x; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
        auto qpow = [&](long long a, int n) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return ans;
        };
        ans = (ans * c[x][k] % mod) * qpow(val, k) % mod;
        return ans;
    }
};
```

#### Go

```go
func countKSubsequencesWithMaxBeauty(s string, k int) int {
	f := [26]int{}
	cnt := 0
	for _, c := range s {
		f[c-'a']++
		if f[c-'a'] == 1 {
			cnt++
		}
	}
	if cnt < k {
		return 0
	}
	vs := []int{}
	for _, x := range f {
		if x > 0 {
			vs = append(vs, x)
		}
	}
	sort.Slice(vs, func(i, j int) bool {
		return vs[i] > vs[j]
	})
	const mod int = 1e9 + 7
	ans := 1
	val := vs[k-1]
	x := 0
	for _, v := range vs {
		if v == val {
			x++
		}
	}
	for _, v := range vs {
		if v == val {
			break
		}
		k--
		ans = ans * v % mod
	}
	c := make([][]int, x+1)
	for i := range c {
		c[i] = make([]int, x+1)
		c[i][0] = 1
		for j := 1; j <= i; j++ {
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod
		}
	}
	qpow := func(a, n int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	ans = (ans * c[x][k] % mod) * qpow(val, k) % mod
	return ans
}
```

#### TypeScript

```ts
function countKSubsequencesWithMaxBeauty(s: string, k: number): number {
    const f: number[] = new Array(26).fill(0);
    let cnt = 0;
    for (const c of s) {
        const i = c.charCodeAt(0) - 97;
        if (++f[i] === 1) {
            ++cnt;
        }
    }
    if (cnt < k) {
        return 0;
    }
    const mod = BigInt(10 ** 9 + 7);
    const vs: number[] = f.filter(v => v > 0).sort((a, b) => b - a);
    const val = vs[k - 1];
    const x = vs.filter(v => v === val).length;
    let ans = 1n;
    for (const v of vs) {
        if (v === val) {
            break;
        }
        --k;
        ans = (ans * BigInt(v)) % mod;
    }
    const c: number[][] = new Array(x + 1).fill(0).map(() => new Array(k + 1).fill(0));
    for (let i = 0; i <= x; ++i) {
        c[i][0] = 1;
        for (let j = 1; j <= Math.min(i, k); ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Number(mod);
        }
    }
    const qpow = (a: bigint, n: number): bigint => {
        let ans = 1n;
        for (; n; n >>>= 1) {
            if (n & 1) {
                ans = (ans * a) % BigInt(mod);
            }
            a = (a * a) % BigInt(mod);
        }
        return ans;
    };
    ans = (((ans * BigInt(c[x][k])) % mod) * qpow(BigInt(val), k)) % mod;
    return Number(ans);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2843. 统计对称整数的数目](https://leetcode.cn/problems/count-symmetric-integers){#2843}

{{< tabs "2843" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        def f(x: int) -> bool:
            s = str(x)
            if len(s) & 1:
                return False
            n = len(s) // 2
            return sum(map(int, s[:n])) == sum(map(int, s[n:]))

        return sum(f(x) for x in range(low, high + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }

    private int f(int x) {
        String s = "" + x;
        int n = s.length();
        if (n % 2 == 1) {
            return 0;
        }
        int a = 0, b = 0;
        for (int i = 0; i < n / 2; ++i) {
            a += s.charAt(i) - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            b += s.charAt(i) - '0';
        }
        return a == b ? 1 : 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        auto f = [](int x) {
            string s = to_string(x);
            int n = s.size();
            if (n & 1) {
                return 0;
            }
            int a = 0, b = 0;
            for (int i = 0; i < n / 2; ++i) {
                a += s[i] - '0';
                b += s[n / 2 + i] - '0';
            }
            return a == b ? 1 : 0;
        };
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSymmetricIntegers(low int, high int) (ans int) {
	f := func(x int) int {
		s := strconv.Itoa(x)
		n := len(s)
		if n&1 == 1 {
			return 0
		}
		a, b := 0, 0
		for i := 0; i < n/2; i++ {
			a += int(s[i] - '0')
			b += int(s[n/2+i] - '0')
		}
		if a == b {
			return 1
		}
		return 0
	}
	for x := low; x <= high; x++ {
		ans += f(x)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSymmetricIntegers(low: number, high: number): number {
    let ans = 0;
    const f = (x: number): number => {
        const s = x.toString();
        const n = s.length;
        if (n & 1) {
            return 0;
        }
        let a = 0;
        let b = 0;
        for (let i = 0; i < n >> 1; ++i) {
            a += Number(s[i]);
            b += Number(s[(n >> 1) + i]);
        }
        return a === b ? 1 : 0;
    };
    for (let x = low; x <= high; ++x) {
        ans += f(x);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut ans = 0;
        for x in low..=high {
            ans += Self::f(x);
        }
        ans
    }

    fn f(x: i32) -> i32 {
        let s = x.to_string();
        let n = s.len();
        if n % 2 == 1 {
            return 0;
        }
        let bytes = s.as_bytes();
        let mut a = 0;
        let mut b = 0;
        for i in 0..n / 2 {
            a += (bytes[i] - b'0') as i32;
        }
        for i in n / 2..n {
            b += (bytes[i] - b'0') as i32;
        }
        if a == b { 1 } else { 0 }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }

    private int f(int x) {
        string s = x.ToString();
        int n = s.Length;
        if (n % 2 == 1) {
            return 0;
        }
        int a = 0, b = 0;
        for (int i = 0; i < n / 2; ++i) {
            a += s[i] - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            b += s[i] - '0';
        }
        return a == b ? 1 : 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个正整数 <code>low</code> 和 <code>high</code> 。</p>

<p>对于一个由 <code>2 * n</code> 位数字组成的整数 <code>x</code> ，如果其前 <code>n</code> 位数字之和与后 <code>n</code> 位数字之和相等，则认为这个数字是一个对称整数。</p>

<p>返回在 <code>[low, high]</code> 范围内的 <strong>对称整数的数目</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>low = 1, high = 100
<strong>输出：</strong>9
<strong>解释：</strong>在 1 到 100 范围内共有 9 个对称整数：11、22、33、44、55、66、77、88 和 99 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>low = 1200, high = 1230
<strong>输出：</strong>4
<strong>解释：</strong>在 1200 到 1230 范围内共有 4 个对称整数：1203、1212、1221 和 1230 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= low &lt;= high &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们枚举 $[low, high]$ 中的每个整数 $x$，判断其是否是对称整数。如果是，那么答案 $ans$ 增加 $1$。

时间复杂度 $O(n \times \log m)$，空间复杂度 $O(\log m)$。其中 $n$ 是 $[low, high]$ 中整数的个数，而 $m$ 是题目中给出的最大整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        def f(x: int) -> bool:
            s = str(x)
            if len(s) & 1:
                return False
            n = len(s) // 2
            return sum(map(int, s[:n])) == sum(map(int, s[n:]))

        return sum(f(x) for x in range(low, high + 1))
```

#### Java

```java
class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }

    private int f(int x) {
        String s = "" + x;
        int n = s.length();
        if (n % 2 == 1) {
            return 0;
        }
        int a = 0, b = 0;
        for (int i = 0; i < n / 2; ++i) {
            a += s.charAt(i) - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            b += s.charAt(i) - '0';
        }
        return a == b ? 1 : 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        auto f = [](int x) {
            string s = to_string(x);
            int n = s.size();
            if (n & 1) {
                return 0;
            }
            int a = 0, b = 0;
            for (int i = 0; i < n / 2; ++i) {
                a += s[i] - '0';
                b += s[n / 2 + i] - '0';
            }
            return a == b ? 1 : 0;
        };
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }
};
```

#### Go

```go
func countSymmetricIntegers(low int, high int) (ans int) {
	f := func(x int) int {
		s := strconv.Itoa(x)
		n := len(s)
		if n&1 == 1 {
			return 0
		}
		a, b := 0, 0
		for i := 0; i < n/2; i++ {
			a += int(s[i] - '0')
			b += int(s[n/2+i] - '0')
		}
		if a == b {
			return 1
		}
		return 0
	}
	for x := low; x <= high; x++ {
		ans += f(x)
	}
	return
}
```

#### TypeScript

```ts
function countSymmetricIntegers(low: number, high: number): number {
    let ans = 0;
    const f = (x: number): number => {
        const s = x.toString();
        const n = s.length;
        if (n & 1) {
            return 0;
        }
        let a = 0;
        let b = 0;
        for (let i = 0; i < n >> 1; ++i) {
            a += Number(s[i]);
            b += Number(s[(n >> 1) + i]);
        }
        return a === b ? 1 : 0;
    };
    for (let x = low; x <= high; ++x) {
        ans += f(x);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut ans = 0;
        for x in low..=high {
            ans += Self::f(x);
        }
        ans
    }

    fn f(x: i32) -> i32 {
        let s = x.to_string();
        let n = s.len();
        if n % 2 == 1 {
            return 0;
        }
        let bytes = s.as_bytes();
        let mut a = 0;
        let mut b = 0;
        for i in 0..n / 2 {
            a += (bytes[i] - b'0') as i32;
        }
        for i in n / 2..n {
            b += (bytes[i] - b'0') as i32;
        }
        if a == b { 1 } else { 0 }
    }
}
```

#### C#

```cs
public class Solution {
    public int CountSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int x = low; x <= high; ++x) {
            ans += f(x);
        }
        return ans;
    }

    private int f(int x) {
        string s = x.ToString();
        int n = s.Length;
        if (n % 2 == 1) {
            return 0;
        }
        int a = 0, b = 0;
        for (int i = 0; i < n / 2; ++i) {
            a += s[i] - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            b += s[i] - '0';
        }
        return a == b ? 1 : 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2844. 生成特殊数字的最少操作](https://leetcode.cn/problems/minimum-operations-to-make-a-special-number){#2844}

{{< tabs "2844" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, num: str) -> int:
        @cache
        def dfs(i: int, k: int) -> int:
            if i == n:
                return 0 if k == 0 else n
            ans = dfs(i + 1, k) + 1
            ans = min(ans, dfs(i + 1, (k * 10 + int(num[i])) % 25))
            return ans

        n = len(num)
        return dfs(0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][] f;
    private String num;
    private int n;

    public int minimumOperations(String num) {
        n = num.length();
        this.num = num;
        f = new Integer[n][25];
        return dfs(0, 0);
    }

    private int dfs(int i, int k) {
        if (i == n) {
            return k == 0 ? 0 : n;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        f[i][k] = dfs(i + 1, k) + 1;
        f[i][k] = Math.min(f[i][k], dfs(i + 1, (k * 10 + num.charAt(i) - '0') % 25));
        return f[i][k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int f[n][25];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int k) -> int {
            if (i == n) {
                return k == 0 ? 0 : n;
            }
            if (f[i][k] != -1) {
                return f[i][k];
            }
            f[i][k] = dfs(i + 1, k) + 1;
            f[i][k] = min(f[i][k], dfs(i + 1, (k * 10 + num[i] - '0') % 25));
            return f[i][k];
        };
        return dfs(0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(num string) int {
	n := len(num)
	f := make([][25]int, n)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, k int) int
	dfs = func(i, k int) int {
		if i == n {
			if k == 0 {
				return 0
			}
			return n
		}
		if f[i][k] != -1 {
			return f[i][k]
		}
		f[i][k] = dfs(i+1, k) + 1
		f[i][k] = min(f[i][k], dfs(i+1, (k*10+int(num[i]-'0'))%25))
		return f[i][k]
	}
	return dfs(0, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(num: string): number {
    const n = num.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: 25 }, () => -1));
    const dfs = (i: number, k: number): number => {
        if (i === n) {
            return k === 0 ? 0 : n;
        }
        if (f[i][k] !== -1) {
            return f[i][k];
        }
        f[i][k] = dfs(i + 1, k) + 1;
        f[i][k] = Math.min(f[i][k], dfs(i + 1, (k * 10 + Number(num[i])) % 25));
        return f[i][k];
    };
    return dfs(0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>num</code> ，表示一个非负整数。</p>

<p>在一次操作中，您可以选择 <code>num</code> 的任意一位数字并将其删除。请注意，如果你删除 <code>num</code> 中的所有数字，则 <code>num</code> 变为 <code>0</code>。</p>

<p>返回最少需要多少次操作可以使 <code>num</code> 变成特殊数字。</p>

<p>如果整数 <code>x</code> 能被 <code>25</code> 整除，则该整数 <code>x</code> 被认为是特殊数字。</p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num = "2245047"
<strong>输出：</strong>2
<strong>解释：</strong>删除数字 num[5] 和 num[6] ，得到数字 "22450" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 2 位数字。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num = "2908305"
<strong>输出：</strong>3
<strong>解释：</strong>删除 num[3]、num[4] 和 num[6] ，得到数字 "2900" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 3 位数字。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num = "10"
<strong>输出：</strong>1
<strong>解释：</strong>删除 num[0] ，得到数字 "0" ，可以被 25 整除。
可以证明要使数字变成特殊数字，最少需要删除 1 位数字。
</pre>

<p>&nbsp;</p>

<p><strong>提示</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 100</code></li>
	<li><code>num</code> 仅由数字 <code>'0'</code> 到 <code>'9'</code> 组成</li>
	<li><code>num</code> 不含任何前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们注意到，整数 $x$ 要能被 $25$ 整除，即 $x \bmod 25 = 0$。因此，我们可以设计一个函数 $dfs(i, k)$，表示从字符串 $num$ 的第 $i$ 位开始，且当前数字模 $25$ 的结果为 $k$ 的情况下，要使得数字变成特殊数字，最少需要删除多少位数字。那么答案为 $dfs(0, 0)$。

函数 $dfs(i, k)$ 的执行逻辑如下：

-   如果 $i = n$，即已经处理完字符串 $num$ 的所有位，那么如果 $k = 0$，则当前数字可以被 $25$ 整除，返回 $0$，否则返回 $n$；
-   否则，第 $i$ 位可以被删除，此时需要删除一位，即 $dfs(i + 1, k) + 1$；第 $i$ 位不删除，那么 $k$ 的值变为 $(k \times 10 + \textit{num}[i]) \bmod 25$，即 $dfs(i + 1, (k \times 10 + \textit{num}[i]) \bmod 25)$。取这两者的最小值即可。

为了防止重复计算，我们可以使用记忆化的方法优化时间复杂度。

时间复杂度 $O(n \times 25)$，空间复杂度 $O(n \times 25)$。其中 $n$ 是字符串 $num$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumOperations(self, num: str) -> int:
        @cache
        def dfs(i: int, k: int) -> int:
            if i == n:
                return 0 if k == 0 else n
            ans = dfs(i + 1, k) + 1
            ans = min(ans, dfs(i + 1, (k * 10 + int(num[i])) % 25))
            return ans

        n = len(num)
        return dfs(0, 0)
```

#### Java

```java
class Solution {
    private Integer[][] f;
    private String num;
    private int n;

    public int minimumOperations(String num) {
        n = num.length();
        this.num = num;
        f = new Integer[n][25];
        return dfs(0, 0);
    }

    private int dfs(int i, int k) {
        if (i == n) {
            return k == 0 ? 0 : n;
        }
        if (f[i][k] != null) {
            return f[i][k];
        }
        f[i][k] = dfs(i + 1, k) + 1;
        f[i][k] = Math.min(f[i][k], dfs(i + 1, (k * 10 + num.charAt(i) - '0') % 25));
        return f[i][k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int f[n][25];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, int k) -> int {
            if (i == n) {
                return k == 0 ? 0 : n;
            }
            if (f[i][k] != -1) {
                return f[i][k];
            }
            f[i][k] = dfs(i + 1, k) + 1;
            f[i][k] = min(f[i][k], dfs(i + 1, (k * 10 + num[i] - '0') % 25));
            return f[i][k];
        };
        return dfs(0, 0);
    }
};
```

#### Go

```go
func minimumOperations(num string) int {
	n := len(num)
	f := make([][25]int, n)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(i, k int) int
	dfs = func(i, k int) int {
		if i == n {
			if k == 0 {
				return 0
			}
			return n
		}
		if f[i][k] != -1 {
			return f[i][k]
		}
		f[i][k] = dfs(i+1, k) + 1
		f[i][k] = min(f[i][k], dfs(i+1, (k*10+int(num[i]-'0'))%25))
		return f[i][k]
	}
	return dfs(0, 0)
}
```

#### TypeScript

```ts
function minimumOperations(num: string): number {
    const n = num.length;
    const f: number[][] = Array.from({ length: n }, () => Array.from({ length: 25 }, () => -1));
    const dfs = (i: number, k: number): number => {
        if (i === n) {
            return k === 0 ? 0 : n;
        }
        if (f[i][k] !== -1) {
            return f[i][k];
        }
        f[i][k] = dfs(i + 1, k) + 1;
        f[i][k] = Math.min(f[i][k], dfs(i + 1, (k * 10 + Number(num[i])) % 25));
        return f[i][k];
    };
    return dfs(0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2845. 统计趣味子数组的数目](https://leetcode.cn/problems/count-of-interesting-subarrays){#2845}

{{< tabs "2845" >}}

{{% tab "python" %}}
```python
class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        arr = [int(x % modulo == k) for x in nums]
        cnt = Counter()
        cnt[0] = 1
        ans = s = 0
        for x in arr:
            s += x
            ans += cnt[(s - k) % modulo]
            cnt[s % modulo] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int n = nums.size();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums.get(i) % modulo == k ? 1 : 0;
        }
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        long ans = 0;
        int s = 0;
        for (int x : arr) {
            s += x;
            ans += cnt.getOrDefault((s - k + modulo) % modulo, 0);
            cnt.merge(s % modulo, 1, Integer::sum);
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
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = int(nums[i] % modulo == k);
        }
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        int s = 0;
        for (int x : arr) {
            s += x;
            ans += cnt[(s - k + modulo) % modulo];
            cnt[s % modulo]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countInterestingSubarrays(nums []int, modulo int, k int) (ans int64) {
	arr := make([]int, len(nums))
	for i, x := range nums {
		if x%modulo == k {
			arr[i] = 1
		}
	}
	cnt := map[int]int{}
	cnt[0] = 1
	s := 0
	for _, x := range arr {
		s += x
		ans += int64(cnt[(s-k+modulo)%modulo])
		cnt[s%modulo]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countInterestingSubarrays(nums: number[], modulo: number, k: number): number {
    const arr: number[] = [];
    for (const x of nums) {
        arr.push(x % modulo === k ? 1 : 0);
    }
    const cnt: Map<number, number> = new Map();
    cnt.set(0, 1);
    let ans = 0;
    let s = 0;
    for (const x of arr) {
        s += x;
        ans += cnt.get((s - k + modulo) % modulo) || 0;
        cnt.set(s % modulo, (cnt.get(s % modulo) || 0) + 1);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_interesting_subarrays(nums: Vec<i32>, modulo: i32, k: i32) -> i64 {
        let mut arr: Vec<i32> = nums
            .iter()
            .map(|&x| if x % modulo == k { 1 } else { 0 })
            .collect();
        let mut cnt: HashMap<i32, i64> = HashMap::new();
        cnt.insert(0, 1);

        let mut ans: i64 = 0;
        let mut s: i32 = 0;

        for x in arr {
            s += x;
            let key = (s - k).rem_euclid(modulo);
            ans += *cnt.get(&key).unwrap_or(&0);
            *cnt.entry(s % modulo).or_insert(0) += 1;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> ，以及整数 <code>modulo</code> 和整数 <code>k</code> 。</p>

<p>请你找出并统计数组中 <strong>趣味子数组</strong> 的数目。</p>

<p>如果 <strong>子数组</strong> <code>nums[l..r]</code> 满足下述条件，则称其为 <strong>趣味子数组</strong> ：</p>

<ul>
	<li>在范围 <code>[l, r]</code> 内，设 <code>cnt</code> 为满足 <code>nums[i] % modulo == k</code> 的索引 <code>i</code> 的数量。并且 <code>cnt % modulo == k</code> 。</li>
</ul>

<p>以整数形式表示并返回趣味子数组的数目。<em> </em></p>

<p><span><strong>注意：</strong>子数组是数组中的一个连续非空的元素序列。</span></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,4], modulo = 2, k = 1
<strong>输出：</strong>3
<strong>解释：</strong>在这个示例中，趣味子数组分别是： 
子数组 nums[0..0] ，也就是 [3] 。 
- 在范围 [0, 0] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
子数组 nums[0..1] ，也就是 [3,2] 。
- 在范围 [0, 1] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
子数组 nums[0..2] ，也就是 [3,2,4] 。
- 在范围 [0, 2] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
- 因此 cnt = 1 ，且 cnt % modulo == k 。
可以证明不存在其他趣味子数组。因此，答案为 3 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,9,6], modulo = 3, k = 0
<strong>输出：</strong>2
<strong>解释：</strong>在这个示例中，趣味子数组分别是： 
子数组 nums[0..3] ，也就是 [3,1,9,6] 。
- 在范围 [0, 3] 内，只存在 3 个下标 i = 0, 2, 3 满足 nums[i] % modulo == k 。
- 因此 cnt = 3 ，且 cnt % modulo == k 。
子数组 nums[1..1] ，也就是 [1] 。
- 在范围 [1, 1] 内，不存在下标满足 nums[i] % modulo == k 。
- 因此 cnt = 0 ，且 cnt % modulo == k 。
可以证明不存在其他趣味子数组，因此答案为 2 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5 </sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= modulo &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt; modulo</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

题目要求一个区间内满足 $nums[i] \bmod modulo = k$ 的索引 $i$ 的数量，我们可以将数组 $nums$ 转换为一个 $0-1$ 数组 $arr$，其中 $arr[i] = 1$ 表示 $nums[i] \bmod modulo = k$，否则 $arr[i] = 0$。

那么对于一个区间 $[l, r]$，我们可以通过前缀和数组 $s$ 来计算 $arr[l..r]$ 中 $1$ 的数量，即 $s[r] - s[l - 1]$，其中 $s[0] = 0$。

我们用哈希表 $cnt$ 记录前缀和 $s \bmod modulo$ 出现的次数，初始时 $cnt[0]=1$。

接下来，我们遍历数组 $arr$，计算前缀和 $s$，将 $(s-k) \bmod modulo$ 出现的次数累加到答案中，然后将 $s \bmod modulo$ 出现的次数加 $1$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        arr = [int(x % modulo == k) for x in nums]
        cnt = Counter()
        cnt[0] = 1
        ans = s = 0
        for x in arr:
            s += x
            ans += cnt[(s - k) % modulo]
            cnt[s % modulo] += 1
        return ans
```

#### Java

```java
class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int n = nums.size();
        int[] arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = nums.get(i) % modulo == k ? 1 : 0;
        }
        Map<Integer, Integer> cnt = new HashMap<>();
        cnt.put(0, 1);
        long ans = 0;
        int s = 0;
        for (int x : arr) {
            s += x;
            ans += cnt.getOrDefault((s - k + modulo) % modulo, 0);
            cnt.merge(s % modulo, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = int(nums[i] % modulo == k);
        }
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        int s = 0;
        for (int x : arr) {
            s += x;
            ans += cnt[(s - k + modulo) % modulo];
            cnt[s % modulo]++;
        }
        return ans;
    }
};
```

#### Go

```go
func countInterestingSubarrays(nums []int, modulo int, k int) (ans int64) {
	arr := make([]int, len(nums))
	for i, x := range nums {
		if x%modulo == k {
			arr[i] = 1
		}
	}
	cnt := map[int]int{}
	cnt[0] = 1
	s := 0
	for _, x := range arr {
		s += x
		ans += int64(cnt[(s-k+modulo)%modulo])
		cnt[s%modulo]++
	}
	return
}
```

#### TypeScript

```ts
function countInterestingSubarrays(nums: number[], modulo: number, k: number): number {
    const arr: number[] = [];
    for (const x of nums) {
        arr.push(x % modulo === k ? 1 : 0);
    }
    const cnt: Map<number, number> = new Map();
    cnt.set(0, 1);
    let ans = 0;
    let s = 0;
    for (const x of arr) {
        s += x;
        ans += cnt.get((s - k + modulo) % modulo) || 0;
        cnt.set(s % modulo, (cnt.get(s % modulo) || 0) + 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_interesting_subarrays(nums: Vec<i32>, modulo: i32, k: i32) -> i64 {
        let mut arr: Vec<i32> = nums
            .iter()
            .map(|&x| if x % modulo == k { 1 } else { 0 })
            .collect();
        let mut cnt: HashMap<i32, i64> = HashMap::new();
        cnt.insert(0, 1);

        let mut ans: i64 = 0;
        let mut s: i32 = 0;

        for x in arr {
            s += x;
            let key = (s - k).rem_euclid(modulo);
            ans += *cnt.get(&key).unwrap_or(&0);
            *cnt.entry(s % modulo).or_insert(0) += 1;
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

# [2846. 边权重均等查询](https://leetcode.cn/problems/minimum-edge-weight-equilibrium-queries-in-a-tree){#2846}

{{< tabs "2846" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperationsQueries(
        self, n: int, edges: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        m = n.bit_length()
        g = [[] for _ in range(n)]
        f = [[0] * m for _ in range(n)]
        p = [0] * n
        cnt = [None] * n
        depth = [0] * n
        for u, v, w in edges:
            g[u].append((v, w - 1))
            g[v].append((u, w - 1))
        cnt[0] = [0] * 26
        q = deque([0])
        while q:
            i = q.popleft()
            f[i][0] = p[i]
            for j in range(1, m):
                f[i][j] = f[f[i][j - 1]][j - 1]
            for j, w in g[i]:
                if j != p[i]:
                    p[j] = i
                    cnt[j] = cnt[i][:]
                    cnt[j][w] += 1
                    depth[j] = depth[i] + 1
                    q.append(j)
        ans = []
        for u, v in queries:
            x, y = u, v
            if depth[x] < depth[y]:
                x, y = y, x
            for j in reversed(range(m)):
                if depth[x] - depth[y] >= (1 << j):
                    x = f[x][j]
            for j in reversed(range(m)):
                if f[x][j] != f[y][j]:
                    x, y = f[x][j], f[y][j]
            if x != y:
                x = p[x]
            mx = max(cnt[u][j] + cnt[v][j] - 2 * cnt[x][j] for j in range(26))
            ans.append(depth[u] + depth[v] - 2 * depth[x] - mx)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] minOperationsQueries(int n, int[][] edges, int[][] queries) {
        int m = 32 - Integer.numberOfLeadingZeros(n);
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        int[][] f = new int[n][m];
        int[] p = new int[n];
        int[][] cnt = new int[n][0];
        int[] depth = new int[n];
        for (var e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1;
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        cnt[0] = new int[26];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        while (!q.isEmpty()) {
            int i = q.poll();
            f[i][0] = p[i];
            for (int j = 1; j < m; ++j) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
            for (var nxt : g[i]) {
                int j = nxt[0], w = nxt[1];
                if (j != p[i]) {
                    p[j] = i;
                    cnt[j] = cnt[i].clone();
                    cnt[j][w]++;
                    depth[j] = depth[i] + 1;
                    q.offer(j);
                }
            }
        }
        int k = queries.length;
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            int u = queries[i][0], v = queries[i][1];
            int x = u, y = v;
            if (depth[x] < depth[y]) {
                int t = x;
                x = y;
                y = t;
            }
            for (int j = m - 1; j >= 0; --j) {
                if (depth[x] - depth[y] >= (1 << j)) {
                    x = f[x][j];
                }
            }
            for (int j = m - 1; j >= 0; --j) {
                if (f[x][j] != f[y][j]) {
                    x = f[x][j];
                    y = f[y][j];
                }
            }
            if (x != y) {
                x = p[x];
            }
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                mx = Math.max(mx, cnt[u][j] + cnt[v][j] - 2 * cnt[x][j]);
            }
            ans[i] = depth[u] + depth[v] - 2 * depth[x] - mx;
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
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = 32 - __builtin_clz(n);
        vector<pair<int, int>> g[n];
        int f[n][m];
        int p[n];
        int cnt[n][26];
        int depth[n];
        memset(f, 0, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        memset(depth, 0, sizeof(depth));
        memset(p, 0, sizeof(p));
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            f[i][0] = p[i];
            for (int j = 1; j < m; ++j) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
            for (auto& [j, w] : g[i]) {
                if (j != p[i]) {
                    p[j] = i;
                    memcpy(cnt[j], cnt[i], sizeof(cnt[i]));
                    cnt[j][w]++;
                    depth[j] = depth[i] + 1;
                    q.push(j);
                }
            }
        }
        vector<int> ans;
        for (auto& qq : queries) {
            int u = qq[0], v = qq[1];
            int x = u, y = v;
            if (depth[x] < depth[y]) {
                swap(x, y);
            }
            for (int j = m - 1; ~j; --j) {
                if (depth[x] - depth[y] >= (1 << j)) {
                    x = f[x][j];
                }
            }
            for (int j = m - 1; ~j; --j) {
                if (f[x][j] != f[y][j]) {
                    x = f[x][j];
                    y = f[y][j];
                }
            }
            if (x != y) {
                x = p[x];
            }
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                mx = max(mx, cnt[u][j] + cnt[v][j] - 2 * cnt[x][j]);
            }
            ans.push_back(depth[u] + depth[v] - 2 * depth[x] - mx);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperationsQueries(n int, edges [][]int, queries [][]int) []int {
	m := bits.Len(uint(n))
	g := make([][][2]int, n)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m)
	}
	p := make([]int, n)
	cnt := make([][26]int, n)
	cnt[0] = [26]int{}
	depth := make([]int, n)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]-1
		g[u] = append(g[u], [2]int{v, w})
		g[v] = append(g[v], [2]int{u, w})
	}
	q := []int{0}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		f[i][0] = p[i]
		for j := 1; j < m; j++ {
			f[i][j] = f[f[i][j-1]][j-1]
		}
		for _, nxt := range g[i] {
			j, w := nxt[0], nxt[1]
			if j != p[i] {
				p[j] = i
				cnt[j] = [26]int{}
				for k := 0; k < 26; k++ {
					cnt[j][k] = cnt[i][k]
				}
				cnt[j][w]++
				depth[j] = depth[i] + 1
				q = append(q, j)
			}
		}
	}
	ans := make([]int, len(queries))
	for i, qq := range queries {
		u, v := qq[0], qq[1]
		x, y := u, v
		if depth[x] < depth[y] {
			x, y = y, x
		}
		for j := m - 1; j >= 0; j-- {
			if depth[x]-depth[y] >= (1 << j) {
				x = f[x][j]
			}
		}
		for j := m - 1; j >= 0; j-- {
			if f[x][j] != f[y][j] {
				x, y = f[x][j], f[y][j]
			}
		}
		if x != y {
			x = p[x]
		}
		mx := 0
		for j := 0; j < 26; j++ {
			mx = max(mx, cnt[u][j]+cnt[v][j]-2*cnt[x][j])
		}
		ans[i] = depth[u] + depth[v] - 2*depth[x] - mx
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

<p>现有一棵由 <code>n</code> 个节点组成的无向树，节点按从 <code>0</code> 到 <code>n - 1</code> 编号。给你一个整数 <code>n</code> 和一个长度为 <code>n - 1</code> 的二维整数数组 <code>edges</code> ，其中 <code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code> 表示树中存在一条位于节点 <code>u<sub>i</sub></code> 和节点 <code>v<sub>i</sub></code> 之间、权重为 <code>w<sub>i</sub></code> 的边。</p>

<p>另给你一个长度为 <code>m</code> 的二维整数数组 <code>queries</code> ，其中 <code>queries[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> 。对于每条查询，请你找出使从 <code>a<sub>i</sub></code> 到 <code>b<sub>i</sub></code> 路径上每条边的权重相等所需的 <strong>最小操作次数</strong> 。在一次操作中，你可以选择树上的任意一条边，并将其权重更改为任意值。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>查询之间 <strong>相互独立</strong> 的，这意味着每条新的查询时，树都会回到 <strong>初始状态</strong> 。</li>
	<li>从 <code>a<sub>i</sub></code> 到 <code>b<sub>i</sub></code>的路径是一个由 <strong>不同</strong> 节点组成的序列，从节点 <code>a<sub>i</sub></code> 开始，到节点 <code>b<sub>i</sub></code> 结束，且序列中相邻的两个节点在树中共享一条边。</li>
</ul>

<p>返回一个长度为 <code>m</code> 的数组 <code>answer</code> ，其中 <code>answer[i]</code> 是第 <code>i</code> 条查询的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2846.Minimum%20Edge%20Weight%20Equilibrium%20Queries%20in%20a%20Tree/images/graph-6-1.png" style="width: 339px; height: 344px;" />
<pre>
<strong>输入：</strong>n = 7, edges = [[0,1,1],[1,2,1],[2,3,1],[3,4,2],[4,5,2],[5,6,2]], queries = [[0,3],[3,6],[2,6],[0,6]]
<strong>输出：</strong>[0,0,1,3]
<strong>解释：</strong>第 1 条查询，从节点 0 到节点 3 的路径中的所有边的权重都是 1 。因此，答案为 0 。
第 2 条查询，从节点 3 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 0 。
第 3 条查询，将边 [2,3] 的权重变更为 2 。在这次操作之后，从节点 2 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 1 。
第 4 条查询，将边 [0,1]、[1,2]、[2,3] 的权重变更为 2 。在这次操作之后，从节点 0 到节点 6 的路径中的所有边的权重都是 2 。因此，答案为 3 。
对于每条查询 queries[i] ，可以证明 answer[i] 是使从 a<sub>i</sub> 到 b<sub>i</sub> 的路径中的所有边的权重相等的最小操作次数。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2846.Minimum%20Edge%20Weight%20Equilibrium%20Queries%20in%20a%20Tree/images/graph-9-1.png" style="width: 472px; height: 370px;" />
<pre>
<strong>输入：</strong>n = 8, edges = [[1,2,6],[1,3,4],[2,4,6],[2,5,3],[3,6,6],[3,0,8],[7,0,2]], queries = [[4,6],[0,4],[6,5],[7,4]]
<strong>输出：</strong>[1,2,2,3]
<strong>解释：</strong>第 1 条查询，将边 [1,3] 的权重变更为 6 。在这次操作之后，从节点 4 到节点 6 的路径中的所有边的权重都是 6 。因此，答案为 1 。
第 2 条查询，将边 [0,3]、[3,1] 的权重变更为 6 。在这次操作之后，从节点 0 到节点 4 的路径中的所有边的权重都是 6 。因此，答案为 2 。
第 3 条查询，将边 [1,3]、[5,2] 的权重变更为 6 。在这次操作之后，从节点 6 到节点 5 的路径中的所有边的权重都是 6 。因此，答案为 2 。
第 4 条查询，将边 [0,7]、[0,3]、[1,3] 的权重变更为 6 。在这次操作之后，从节点 7 到节点 4 的路径中的所有边的权重都是 6 。因此，答案为 3 。
对于每条查询 queries[i] ，可以证明 answer[i] 是使从 a<sub>i</sub> 到 b<sub>i</sub> 的路径中的所有边的权重相等的最小操作次数。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt; n</code></li>
	<li><code>1 &lt;= w<sub>i</sub> &lt;= 26</code></li>
	<li>生成的输入满足 <code>edges</code> 表示一棵有效的树</li>
	<li><code>1 &lt;= queries.length == m &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：倍增法求 LCA

题目求的是任意两点的路径上，将其所有边的权重变成相同值的最小操作次数。实际上就是求这两点之间的路径长度，减去路径上出现次数最多的边的次数。

而求两点间的路径长度，可以通过倍增法求 LCA 来实现。我们记两点分别为 $u$ 和 $v$，最近公共祖先为 $x$，那么 $u$ 到 $v$ 的路径长度就是 $depth(u) + depth(v) - 2 \times depth(x)$。

另外，我们可以用一个数组 $cnt[n][26]$ 记录根节点到每个节点上，每个边权重出现的次数。那么 $u$ 到 $v$ 的路径上，出现次数最多的边的次数就是 $\max_{0 \leq j < 26} cnt[u][j] + cnt[v][j] - 2 \times cnt[x][j]$。其中 $x$ 为 $u$ 和 $v$ 的最近公共祖先。

倍增法求 LCA 的过程如下：

我们记每个节点的深度为 $depth$，父节点为 $p$，而 $f[i][j]$ 表示节点 $i$ 的第 $2^j$ 个祖先。那么，对于任意两点 $x$ 和 $y$，我们可以通过以下方式求出它们的最近公共祖先：

1. 如果 $depth(x) < depth(y)$，那么交换 $x$ 和 $y$，即保证 $x$ 的深度不小于 $y$ 的深度；
2. 接下来，我们将 $x$ 的深度不断向上提升，直到 $x$ 和 $y$ 的深度相同，此时 $x$ 和 $y$ 的深度都为 $depth(x)$；
3. 然后，我们将 $x$ 和 $y$ 的深度同时向上提升，直到 $x$ 和 $y$ 的父节点相同，此时 $x$ 和 $y$ 的父节点都为 $f[x][0]$，即为 $x$ 和 $y$ 的最近公共祖先。

最后，节点 $u$ 到节点 $v$ 的最小操作次数就是 $depth(u) + depth(v) - 2 \times depth(x) - \max_{0 \leq j < 26} cnt[u][j] + cnt[v][j] - 2 \times cnt[x][j]$。

时间复杂度 $O((n + q) \times C \times \log n)$，空间复杂度 $O(n \times C \times \log n)$，其中 $C$ 为边权重的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperationsQueries(
        self, n: int, edges: List[List[int]], queries: List[List[int]]
    ) -> List[int]:
        m = n.bit_length()
        g = [[] for _ in range(n)]
        f = [[0] * m for _ in range(n)]
        p = [0] * n
        cnt = [None] * n
        depth = [0] * n
        for u, v, w in edges:
            g[u].append((v, w - 1))
            g[v].append((u, w - 1))
        cnt[0] = [0] * 26
        q = deque([0])
        while q:
            i = q.popleft()
            f[i][0] = p[i]
            for j in range(1, m):
                f[i][j] = f[f[i][j - 1]][j - 1]
            for j, w in g[i]:
                if j != p[i]:
                    p[j] = i
                    cnt[j] = cnt[i][:]
                    cnt[j][w] += 1
                    depth[j] = depth[i] + 1
                    q.append(j)
        ans = []
        for u, v in queries:
            x, y = u, v
            if depth[x] < depth[y]:
                x, y = y, x
            for j in reversed(range(m)):
                if depth[x] - depth[y] >= (1 << j):
                    x = f[x][j]
            for j in reversed(range(m)):
                if f[x][j] != f[y][j]:
                    x, y = f[x][j], f[y][j]
            if x != y:
                x = p[x]
            mx = max(cnt[u][j] + cnt[v][j] - 2 * cnt[x][j] for j in range(26))
            ans.append(depth[u] + depth[v] - 2 * depth[x] - mx)
        return ans
```

#### Java

```java
class Solution {
    public int[] minOperationsQueries(int n, int[][] edges, int[][] queries) {
        int m = 32 - Integer.numberOfLeadingZeros(n);
        List<int[]>[] g = new List[n];
        Arrays.setAll(g, i -> new ArrayList<>());
        int[][] f = new int[n][m];
        int[] p = new int[n];
        int[][] cnt = new int[n][0];
        int[] depth = new int[n];
        for (var e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1;
            g[u].add(new int[] {v, w});
            g[v].add(new int[] {u, w});
        }
        cnt[0] = new int[26];
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        while (!q.isEmpty()) {
            int i = q.poll();
            f[i][0] = p[i];
            for (int j = 1; j < m; ++j) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
            for (var nxt : g[i]) {
                int j = nxt[0], w = nxt[1];
                if (j != p[i]) {
                    p[j] = i;
                    cnt[j] = cnt[i].clone();
                    cnt[j][w]++;
                    depth[j] = depth[i] + 1;
                    q.offer(j);
                }
            }
        }
        int k = queries.length;
        int[] ans = new int[k];
        for (int i = 0; i < k; ++i) {
            int u = queries[i][0], v = queries[i][1];
            int x = u, y = v;
            if (depth[x] < depth[y]) {
                int t = x;
                x = y;
                y = t;
            }
            for (int j = m - 1; j >= 0; --j) {
                if (depth[x] - depth[y] >= (1 << j)) {
                    x = f[x][j];
                }
            }
            for (int j = m - 1; j >= 0; --j) {
                if (f[x][j] != f[y][j]) {
                    x = f[x][j];
                    y = f[y][j];
                }
            }
            if (x != y) {
                x = p[x];
            }
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                mx = Math.max(mx, cnt[u][j] + cnt[v][j] - 2 * cnt[x][j]);
            }
            ans[i] = depth[u] + depth[v] - 2 * depth[x] - mx;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = 32 - __builtin_clz(n);
        vector<pair<int, int>> g[n];
        int f[n][m];
        int p[n];
        int cnt[n][26];
        int depth[n];
        memset(f, 0, sizeof(f));
        memset(cnt, 0, sizeof(cnt));
        memset(depth, 0, sizeof(depth));
        memset(p, 0, sizeof(p));
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2] - 1;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            f[i][0] = p[i];
            for (int j = 1; j < m; ++j) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
            for (auto& [j, w] : g[i]) {
                if (j != p[i]) {
                    p[j] = i;
                    memcpy(cnt[j], cnt[i], sizeof(cnt[i]));
                    cnt[j][w]++;
                    depth[j] = depth[i] + 1;
                    q.push(j);
                }
            }
        }
        vector<int> ans;
        for (auto& qq : queries) {
            int u = qq[0], v = qq[1];
            int x = u, y = v;
            if (depth[x] < depth[y]) {
                swap(x, y);
            }
            for (int j = m - 1; ~j; --j) {
                if (depth[x] - depth[y] >= (1 << j)) {
                    x = f[x][j];
                }
            }
            for (int j = m - 1; ~j; --j) {
                if (f[x][j] != f[y][j]) {
                    x = f[x][j];
                    y = f[y][j];
                }
            }
            if (x != y) {
                x = p[x];
            }
            int mx = 0;
            for (int j = 0; j < 26; ++j) {
                mx = max(mx, cnt[u][j] + cnt[v][j] - 2 * cnt[x][j]);
            }
            ans.push_back(depth[u] + depth[v] - 2 * depth[x] - mx);
        }
        return ans;
    }
};
```

#### Go

```go
func minOperationsQueries(n int, edges [][]int, queries [][]int) []int {
	m := bits.Len(uint(n))
	g := make([][][2]int, n)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, m)
	}
	p := make([]int, n)
	cnt := make([][26]int, n)
	cnt[0] = [26]int{}
	depth := make([]int, n)
	for _, e := range edges {
		u, v, w := e[0], e[1], e[2]-1
		g[u] = append(g[u], [2]int{v, w})
		g[v] = append(g[v], [2]int{u, w})
	}
	q := []int{0}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		f[i][0] = p[i]
		for j := 1; j < m; j++ {
			f[i][j] = f[f[i][j-1]][j-1]
		}
		for _, nxt := range g[i] {
			j, w := nxt[0], nxt[1]
			if j != p[i] {
				p[j] = i
				cnt[j] = [26]int{}
				for k := 0; k < 26; k++ {
					cnt[j][k] = cnt[i][k]
				}
				cnt[j][w]++
				depth[j] = depth[i] + 1
				q = append(q, j)
			}
		}
	}
	ans := make([]int, len(queries))
	for i, qq := range queries {
		u, v := qq[0], qq[1]
		x, y := u, v
		if depth[x] < depth[y] {
			x, y = y, x
		}
		for j := m - 1; j >= 0; j-- {
			if depth[x]-depth[y] >= (1 << j) {
				x = f[x][j]
			}
		}
		for j := m - 1; j >= 0; j-- {
			if f[x][j] != f[y][j] {
				x, y = f[x][j], f[y][j]
			}
		}
		if x != y {
			x = p[x]
		}
		mx := 0
		for j := 0; j < 26; j++ {
			mx = max(mx, cnt[u][j]+cnt[v][j]-2*cnt[x][j])
		}
		ans[i] = depth[u] + depth[v] - 2*depth[x] - mx
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2847. 给定数字乘积的最小数字 🔒](https://leetcode.cn/problems/smallest-number-with-given-digit-product){#2847}

{{< tabs "2847" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestNumber(self, n: int) -> str:
        cnt = [0] * 10
        for i in range(9, 1, -1):
            while n % i == 0:
                n //= i
                cnt[i] += 1
        if n > 1:
            return "-1"
        ans = "".join(str(i) * cnt[i] for i in range(2, 10))
        return ans if ans else "1"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String smallestNumber(long n) {
        int[] cnt = new int[10];
        for (int i = 9; i > 1; --i) {
            while (n % i == 0) {
                ++cnt[i];
                n /= i;
            }
        }
        if (n > 1) {
            return "-1";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 2; i < 10; ++i) {
            while (cnt[i] > 0) {
                sb.append(i);
                --cnt[i];
            }
        }
        String ans = sb.toString();
        return ans.isEmpty() ? "1" : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string smallestNumber(long long n) {
        int cnt[10]{};
        for (int i = 9; i > 1; --i) {
            while (n % i == 0) {
                n /= i;
                ++cnt[i];
            }
        }
        if (n > 1) {
            return "-1";
        }
        string ans;
        for (int i = 2; i < 10; ++i) {
            ans += string(cnt[i], '0' + i);
        }
        return ans == "" ? "1" : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestNumber(n int64) string {
	cnt := [10]int{}
	for i := 9; i > 1; i-- {
		for n%int64(i) == 0 {
			cnt[i]++
			n /= int64(i)
		}
	}
	if n != 1 {
		return "-1"
	}
	sb := &strings.Builder{}
	for i := 2; i < 10; i++ {
		for j := 0; j < cnt[i]; j++ {
			sb.WriteByte(byte(i) + '0')
		}
	}
	ans := sb.String()
	if len(ans) > 0 {
		return ans
	}
	return "1"
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <strong>正</strong> 整数 <code>n</code>，返回一个字符串，表示使其各位数字的乘积等于 <code>n</code>&nbsp;的 <strong>最小正整数</strong>，如果不存在这样的数字，则返回 <code>"-1"</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<strong>输入：</strong>n = 105
<b>输出：</b>"357"
<b>解释：</b>3 * 5 * 7 = 105。可以证明，357 是各位数字的乘积等于 105 的最小数字。因此答案为 "357"。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 7
<b>输出：</b>"7"
<b>解释：</b>由于 7 只有一位数字，其各位数字的乘积为 7。由于数字 1 到 6 的乘积分别为 1 到 6，所以答案为 "7"。可以证明 7 是乘积等于 7 的最小数字。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 44
<b>输出：</b>"-1"
<b>解释：</b>可以证明，没有数字的各位数字乘积等于 44。因此答案为 "-1"。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>18</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：质因数分解 + 贪心

我们考虑对数字 $n$ 进行质因数分解，如果 $n$ 的质因数中存在大于 $9$ 的质数，那么一定无法找到符合条件的数字，因为大于 $9$ 的质数无法通过 $1$ 到 $9$ 的数字相乘得到，例如 $11$ 无法通过 $1$ 到 $9$ 的数字相乘得到，因此我们只需要考虑 $n$ 的质因数中是否存在大于 $9$ 的质数即可，如果存在，直接返回 $-1$。

否则，如果质因数中包含 $7$ 和 $5$，那么数字 $n$ 首先可以拆分为若干个 $7$ 和 $5$，两个数字 $3$ 可以合成一个数字 $9$，三个数字 $2$ 可以合成一个数字 $8$，数字 $2$ 和数字 $3$ 可以合成一个数字 $6$，因此我们只需要将数字拆分为 $[2,..9]$ 的数字即可，我们可以使用贪心的方法，优先拆分出数字 $9$，然后拆分出数字 $8$，依次类推。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestNumber(self, n: int) -> str:
        cnt = [0] * 10
        for i in range(9, 1, -1):
            while n % i == 0:
                n //= i
                cnt[i] += 1
        if n > 1:
            return "-1"
        ans = "".join(str(i) * cnt[i] for i in range(2, 10))
        return ans if ans else "1"
```

#### Java

```java
class Solution {
    public String smallestNumber(long n) {
        int[] cnt = new int[10];
        for (int i = 9; i > 1; --i) {
            while (n % i == 0) {
                ++cnt[i];
                n /= i;
            }
        }
        if (n > 1) {
            return "-1";
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 2; i < 10; ++i) {
            while (cnt[i] > 0) {
                sb.append(i);
                --cnt[i];
            }
        }
        String ans = sb.toString();
        return ans.isEmpty() ? "1" : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string smallestNumber(long long n) {
        int cnt[10]{};
        for (int i = 9; i > 1; --i) {
            while (n % i == 0) {
                n /= i;
                ++cnt[i];
            }
        }
        if (n > 1) {
            return "-1";
        }
        string ans;
        for (int i = 2; i < 10; ++i) {
            ans += string(cnt[i], '0' + i);
        }
        return ans == "" ? "1" : ans;
    }
};
```

#### Go

```go
func smallestNumber(n int64) string {
	cnt := [10]int{}
	for i := 9; i > 1; i-- {
		for n%int64(i) == 0 {
			cnt[i]++
			n /= int64(i)
		}
	}
	if n != 1 {
		return "-1"
	}
	sb := &strings.Builder{}
	for i := 2; i < 10; i++ {
		for j := 0; j < cnt[i]; j++ {
			sb.WriteByte(byte(i) + '0')
		}
	}
	ans := sb.String()
	if len(ans) > 0 {
		return ans
	}
	return "1"
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2848. 与车相交的点](https://leetcode.cn/problems/points-that-intersect-with-cars){#2848}

{{< tabs "2848" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        d = defaultdict(int)
        for start, end in nums:
            d[start] += 1
            d[end + 1] -= 1
        ans = s = last = 0
        for cur, v in sorted(d.items()):
            if s > 0:
                ans += cur - last
            s += v
            last = cur
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (var e : nums) {
            int start = e.get(0), end = e.get(1);
            d.merge(start, 1, Integer::sum);
            d.merge(end + 1, -1, Integer::sum);
        }
        int ans = 0, s = 0, last = 0;
        for (var e : d.entrySet()) {
            int cur = e.getKey(), v = e.getValue();
            if (s > 0) {
                ans += cur - last;
            }
            s += v;
            last = cur;
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
    int numberOfPoints(vector<vector<int>>& nums) {
        map<int, int> d;
        for (const auto& e : nums) {
            int start = e[0], end = e[1];
            ++d[start];
            --d[end + 1];
        }
        int ans = 0, s = 0, last = 0;
        for (const auto& [cur, v] : d) {
            if (s > 0) {
                ans += cur - last;
            }
            s += v;
            last = cur;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfPoints(nums [][]int) (ans int) {
	d := map[int]int{}
	for _, e := range nums {
		start, end := e[0], e[1]
		d[start]++
		d[end+1]--
	}
	keys := []int{}
	for k := range d {
		keys = append(keys, k)
	}
	s, last := 0, 0
	sort.Ints(keys)
	for _, cur := range keys {
		if s > 0 {
			ans += cur - last
		}
		s += d[cur]
		last = cur
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfPoints(nums: number[][]): number {
    const d = new Map<number, number>();
    for (const [start, end] of nums) {
        d.set(start, (d.get(start) || 0) + 1);
        d.set(end + 1, (d.get(end + 1) || 0) - 1);
    }
    const keys = [...d.keys()].sort((a, b) => a - b);
    let [ans, s, last] = [0, 0, 0];
    for (const cur of keys) {
        if (s > 0) {
            ans += cur - last;
        }
        s += d.get(cur)!;
        last = cur;
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

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>nums</code> 表示汽车停放在数轴上的坐标。对于任意下标 <code>i</code>，<code>nums[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> ，其中 <code>start<sub>i</sub></code> 是第 <code>i</code> 辆车的起点，<code>end<sub>i</sub></code> 是第 <code>i</code> 辆车的终点。</p>

<p>返回数轴上被车 <strong>任意部分</strong> 覆盖的整数点的数目。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [[3,6],[1,5],[4,7]]
<strong>输出：</strong>7
<strong>解释：</strong>从 1 到 7 的所有点都至少与一辆车相交，因此答案为 7 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [[1,3],[5,8]]
<strong>输出：</strong>7
<strong>解释：</strong>1、2、3、5、6、7、8 共计 7 个点满足至少与一辆车相交，因此答案为 7 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums[i].length == 2</code></li>
	<li><code><font face="monospace">1 &lt;= start<sub>i</sub>&nbsp;&lt;= end<sub>i</sub>&nbsp;&lt;= 100</font></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：差分数组

根据题目描述，我们需要给每个区间 $[\textit{start}_i, \textit{end}_i]$ 增加一个车辆，我们可以使用差分数组来实现。

我们定义一个长度为 $102$ 的数组 $d$，对于每个区间 $[\textit{start}_i, \textit{end}_i]$，我们将 $d[\textit{start}_i]$ 加 $1$，将 $d[\textit{end}_i + 1]$ 减 $1$。

最后，我们对 $d$ 进行前缀和运算，统计前缀和大于 $0$ 的个数即可。

时间复杂度 $O(n + m)$，空间复杂度 $O(m)$，其中 $n$ 是给定数组的长度，而 $m$ 是数组中的最大值，本题中 $m \leq 102$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        m = 102
        d = [0] * m
        for start, end in nums:
            d[start] += 1
            d[end + 1] -= 1
        return sum(s > 0 for s in accumulate(d))
```

#### Java

```java
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        int[] d = new int[102];
        for (var e : nums) {
            int start = e.get(0), end = e.get(1);
            ++d[start];
            --d[end + 1];
        }
        int ans = 0, s = 0;
        for (int x : d) {
            s += x;
            if (s > 0) {
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
    int numberOfPoints(vector<vector<int>>& nums) {
        int d[102]{};
        for (const auto& e : nums) {
            int start = e[0], end = e[1];
            ++d[start];
            --d[end + 1];
        }
        int ans = 0, s = 0;
        for (int x : d) {
            s += x;
            ans += s > 0;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfPoints(nums [][]int) (ans int) {
	d := [102]int{}
	for _, e := range nums {
		start, end := e[0], e[1]
		d[start]++
		d[end+1]--
	}
	s := 0
	for _, x := range d {
		s += x
		if s > 0 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function numberOfPoints(nums: number[][]): number {
    const d: number[] = Array(102).fill(0);
    for (const [start, end] of nums) {
        ++d[start];
        --d[end + 1];
    }
    let ans = 0;
    let s = 0;
    for (const x of d) {
        s += x;
        ans += s > 0 ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表 + 差分 + 排序

如果题目的区间范围较大，我们可以使用哈希表来存储区间的起点和终点，然后对哈希表的键进行排序，再进行前缀和统计。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为给定数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        d = defaultdict(int)
        for start, end in nums:
            d[start] += 1
            d[end + 1] -= 1
        ans = s = last = 0
        for cur, v in sorted(d.items()):
            if s > 0:
                ans += cur - last
            s += v
            last = cur
        return ans
```

#### Java

```java
class Solution {
    public int numberOfPoints(List<List<Integer>> nums) {
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (var e : nums) {
            int start = e.get(0), end = e.get(1);
            d.merge(start, 1, Integer::sum);
            d.merge(end + 1, -1, Integer::sum);
        }
        int ans = 0, s = 0, last = 0;
        for (var e : d.entrySet()) {
            int cur = e.getKey(), v = e.getValue();
            if (s > 0) {
                ans += cur - last;
            }
            s += v;
            last = cur;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        map<int, int> d;
        for (const auto& e : nums) {
            int start = e[0], end = e[1];
            ++d[start];
            --d[end + 1];
        }
        int ans = 0, s = 0, last = 0;
        for (const auto& [cur, v] : d) {
            if (s > 0) {
                ans += cur - last;
            }
            s += v;
            last = cur;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfPoints(nums [][]int) (ans int) {
	d := map[int]int{}
	for _, e := range nums {
		start, end := e[0], e[1]
		d[start]++
		d[end+1]--
	}
	keys := []int{}
	for k := range d {
		keys = append(keys, k)
	}
	s, last := 0, 0
	sort.Ints(keys)
	for _, cur := range keys {
		if s > 0 {
			ans += cur - last
		}
		s += d[cur]
		last = cur
	}
	return
}
```

#### TypeScript

```ts
function numberOfPoints(nums: number[][]): number {
    const d = new Map<number, number>();
    for (const [start, end] of nums) {
        d.set(start, (d.get(start) || 0) + 1);
        d.set(end + 1, (d.get(end + 1) || 0) - 1);
    }
    const keys = [...d.keys()].sort((a, b) => a - b);
    let [ans, s, last] = [0, 0, 0];
    for (const cur of keys) {
        if (s > 0) {
            ans += cur - last;
        }
        s += d.get(cur)!;
        last = cur;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2849. 判断能否在给定时间到达单元格](https://leetcode.cn/problems/determine-if-a-cell-is-reachable-at-a-given-time){#2849}

{{< tabs "2849" >}}

{{% tab "python" %}}
```python
class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        if sx == fx and sy == fy:
            return t != 1
        dx = abs(sx - fx)
        dy = abs(sy - fy)
        return max(dx, dy) <= t
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        int dx = Math.abs(sx - fx);
        int dy = Math.abs(sy - fy);
        return Math.max(dx, dy) <= t;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        int dx = abs(fx - sx), dy = abs(fy - sy);
        return max(dx, dy) <= t;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isReachableAtTime(sx int, sy int, fx int, fy int, t int) bool {
	if sx == fx && sy == fy {
		return t != 1
	}
	dx := abs(sx - fx)
	dy := abs(sy - fy)
	return max(dx, dy) <= t
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
function isReachableAtTime(sx: number, sy: number, fx: number, fy: number, t: number): boolean {
    if (sx === fx && sy === fy) {
        return t !== 1;
    }
    const dx = Math.abs(sx - fx);
    const dy = Math.abs(sy - fy);
    return Math.max(dx, dy) <= t;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        return Math.Max(Math.Abs(sx - fx), Math.Abs(sy - fy)) <= t;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你四个整数 <code>sx</code>、<code>sy</code>、<code>fx</code>、<code>fy</code>&nbsp; 以及一个 <strong>非负整数</strong> <code>t</code> 。</p>

<p>在一个无限的二维网格中，你从单元格 <code>(sx, sy)</code> 开始出发。每一秒，你 <strong>必须</strong> 移动到任一与之前所处单元格相邻的单元格中。</p>

<p>如果你能在 <strong>恰好 </strong><code>t</code><strong> 秒</strong> 后到达单元格<em> </em><code>(fx, fy)</code> ，返回 <code>true</code> ；否则，返回&nbsp; <code>false</code> 。</p>

<p>单元格的 <strong>相邻单元格</strong> 是指该单元格周围与其至少共享一个角的 8 个单元格。你可以多次访问同一个单元格。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2849.Determine%20if%20a%20Cell%20Is%20Reachable%20at%20a%20Given%20Time/images/example2.svg" style="width: 443px; height: 243px;" />
<pre>
<strong>输入：</strong>sx = 2, sy = 4, fx = 7, fy = 7, t = 6
<strong>输出：</strong>true
<strong>解释：</strong>从单元格 (2, 4) 开始出发，穿过上图标注的单元格，可以在恰好 6 秒后到达单元格 (7, 7) 。 
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2800-2899/2849.Determine%20if%20a%20Cell%20Is%20Reachable%20at%20a%20Given%20Time/images/example1.svg" style="width: 383px; height: 202px;" />
<pre>
<strong>输入：</strong>sx = 3, sy = 1, fx = 7, fy = 3, t = 3
<strong>输出：</strong>false
<strong>解释：</strong>从单元格 (3, 1) 开始出发，穿过上图标注的单元格，至少需要 4 秒后到达单元格 (7, 3) 。 因此，无法在 3 秒后到达单元格 (7, 3) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sx, sy, fx, fy &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= t &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分情况讨论

如果起点和终点相同，那么只有当 $t \neq 1$ 时，才能在给定时间到达终点。

否则，我们可以计算出起点和终点的横纵坐标之差，然后取最大值，如果最大值小于等于给定时间，那么就可以在给定时间到达终点。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        if sx == fx and sy == fy:
            return t != 1
        dx = abs(sx - fx)
        dy = abs(sy - fy)
        return max(dx, dy) <= t
```

#### Java

```java
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        int dx = Math.abs(sx - fx);
        int dy = Math.abs(sy - fy);
        return Math.max(dx, dy) <= t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        int dx = abs(fx - sx), dy = abs(fy - sy);
        return max(dx, dy) <= t;
    }
};
```

#### Go

```go
func isReachableAtTime(sx int, sy int, fx int, fy int, t int) bool {
	if sx == fx && sy == fy {
		return t != 1
	}
	dx := abs(sx - fx)
	dy := abs(sy - fy)
	return max(dx, dy) <= t
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
function isReachableAtTime(sx: number, sy: number, fx: number, fy: number, t: number): boolean {
    if (sx === fx && sy === fy) {
        return t !== 1;
    }
    const dx = Math.abs(sx - fx);
    const dy = Math.abs(sy - fy);
    return Math.max(dx, dy) <= t;
}
```

#### C#

```cs
public class Solution {
    public bool IsReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            return t != 1;
        }
        return Math.Max(Math.Abs(sx - fx), Math.Abs(sy - fy)) <= t;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
