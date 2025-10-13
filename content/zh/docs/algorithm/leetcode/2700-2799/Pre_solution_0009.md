---
title: "2780_合法分割的最小下标"
date: 2025-10-08T18:39:33+08:00
weight: 9
tags: [交互, 动态规划, 哈希表, 字符串, 并查集, 排序, 数据库, 数组, 滑动窗口, 计数, 贪心]
---

{{< markmap >}}
### [2780_合法分割的最小下标](#2780)
#### [数组](#2780)
#### [哈希表](#2780)
#### [排序](#2780)
### [2781_最长合法子字符串的长度](#2781)
#### [数组](#2781)
#### [哈希表](#2781)
#### [字符串](#2781)
#### [滑动窗口](#2781)
### [2782_唯一类别的数量 🔒](#2782)
#### [并查集](#2782)
#### [计数](#2782)
#### [交互](#2782)
### [2783_航班入座率和等待名单分析 🔒](#2783)
#### [数据库](#2783)
### [2784_检查数组是否是好的](#2784)
#### [数组](#2784)
#### [哈希表](#2784)
#### [排序](#2784)
### [2785_将字符串中的元音字母排序](#2785)
#### [字符串](#2785)
#### [排序](#2785)
### [2786_访问数组中的位置使分数最大](#2786)
#### [数组](#2786)
#### [动态规划](#2786)
### [2787_将一个数字表示成幂的和的方案数](#2787)
#### [动态规划](#2787)
### [2788_按分隔符拆分字符串](#2788)
#### [数组](#2788)
#### [字符串](#2788)
### [2789_合并后数组中的最大元素](#2789)
#### [贪心](#2789)
#### [数组](#2789)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2780_合法分割的最小下标
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 2781_最长合法子字符串的长度
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 2782_唯一类别的数量 🔒
___
#### 并查集
___
#### 计数
___
#### 交互
---
### 2783_航班入座率和等待名单分析 🔒
___
#### 数据库
---
### 2784_检查数组是否是好的
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 2785_将字符串中的元音字母排序
___
#### 字符串
___
#### 排序
---
### 2786_访问数组中的位置使分数最大
___
#### 数组
___
#### 动态规划
---
### 2787_将一个数字表示成幂的和的方案数
___
#### 动态规划
---
### 2788_按分隔符拆分字符串
___
#### 数组
___
#### 字符串
---
### 2789_合并后数组中的最大元素
___
#### 贪心
___
#### 数组
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 交互 | 动态规划 | 哈希表 |
| 字符串 | 并查集 | 排序 |
| 数据库 | 数组 | 滑动窗口 |
| 计数 | 贪心 |  |

# [2780. 合法分割的最小下标](https://leetcode.cn/problems/minimum-index-of-a-valid-split){#2780}

{{< tabs "2780" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        x, cnt = Counter(nums).most_common(1)[0]
        cur = 0
        for i, v in enumerate(nums, 1):
            if v == x:
                cur += 1
                if cur * 2 > i and (cnt - cur) * 2 > len(nums) - i:
                    return i - 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumIndex(List<Integer> nums) {
        int x = 0, cnt = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int v : nums) {
            int t = freq.merge(v, 1, Integer::sum);
            if (cnt < t) {
                cnt = t;
                x = v;
            }
        }
        int cur = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums.get(i - 1) == x) {
                ++cur;
                if (cur * 2 > i && (cnt - cur) * 2 > nums.size() - i) {
                    return i - 1;
                }
            }
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
    int minimumIndex(vector<int>& nums) {
        int x = 0, cnt = 0;
        unordered_map<int, int> freq;
        for (int v : nums) {
            ++freq[v];
            if (freq[v] > cnt) {
                cnt = freq[v];
                x = v;
            }
        }
        int cur = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] == x) {
                ++cur;
                if (cur * 2 > i && (cnt - cur) * 2 > nums.size() - i) {
                    return i - 1;
                }
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumIndex(nums []int) int {
	x, cnt := 0, 0
	freq := map[int]int{}
	for _, v := range nums {
		freq[v]++
		if freq[v] > cnt {
			x, cnt = v, freq[v]
		}
	}
	cur := 0
	for i, v := range nums {
		i++
		if v == x {
			cur++
			if cur*2 > i && (cnt-cur)*2 > len(nums)-i {
				return i - 1
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumIndex(nums: number[]): number {
    let [x, cnt] = [0, 0];
    const freq: Map<number, number> = new Map();
    for (const v of nums) {
        freq.set(v, (freq.get(v) ?? 0) + 1);
        if (freq.get(v)! > cnt) {
            [x, cnt] = [v, freq.get(v)!];
        }
    }
    let cur = 0;
    for (let i = 1; i <= nums.length; ++i) {
        if (nums[i - 1] === x) {
            ++cur;
            if (cur * 2 > i && (cnt - cur) * 2 > nums.length - i) {
                return i - 1;
            }
        }
    }
    return -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果在长度为 <code>m</code>&nbsp;的整数数组 <code>arr</code>&nbsp;中 <strong>超过一半</strong> 的元素值为&nbsp;<code>x</code>，那么我们称 <code>x</code>&nbsp;是 <strong>支配元素</strong>&nbsp;。</p>

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，数据保证它含有一个 <strong>支配</strong> 元素。</p>

<p>你需要在下标 <code>i</code>&nbsp;处将&nbsp;<code>nums</code>&nbsp;分割成两个数组&nbsp;<code>nums[0, ..., i]</code> 和&nbsp;<code>nums[i + 1, ..., n - 1]</code>&nbsp;，如果一个分割满足以下条件，我们称它是&nbsp;<strong>合法</strong>&nbsp;的：</p>

<ul>
	<li><code>0 &lt;= i &lt; n - 1</code></li>
	<li><code>nums[0, ..., i]</code>&nbsp;和&nbsp;<code>nums[i + 1, ..., n - 1]</code>&nbsp;的支配元素相同。</li>
</ul>

<p>这里，&nbsp;<code>nums[i, ..., j]</code>&nbsp;表示 <code>nums</code>&nbsp;的一个子数组，它开始于下标&nbsp;<code>i</code>&nbsp;，结束于下标&nbsp;<code>j</code>&nbsp;，两个端点都包含在子数组内。特别地，如果&nbsp;<code>j &lt; i</code>&nbsp;，那么&nbsp;<code>nums[i, ..., j]</code>&nbsp;表示一个空数组。</p>

<p>请你返回一个 <strong>合法分割</strong>&nbsp;的 <strong>最小</strong>&nbsp;下标。如果合法分割不存在，返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,2,2]
<b>输出：</b>2
<b>解释：</b>我们将数组在下标 2 处分割，得到 [1,2,2] 和 [2] 。
数组 [1,2,2] 中，元素 2 是支配元素，因为它在数组中出现了 2 次，且 2 * 2 &gt; 3 。
数组 [2] 中，元素 2 是支配元素，因为它在数组中出现了 1 次，且 1 * 2 &gt; 1 。
两个数组 [1,2,2] 和 [2] 都有与 nums 一样的支配元素，所以这是一个合法分割。
下标 2 是合法分割中的最小下标。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,3,1,1,1,7,1,2,1]
<b>输出：</b>4
<b>解释：</b>我们将数组在下标 4 处分割，得到 [2,1,3,1,1] 和 [1,7,1,2,1] 。
数组 [2,1,3,1,1] 中，元素 1 是支配元素，因为它在数组中出现了 3 次，且 3 * 2 &gt; 5 。
数组 [1,7,1,2,1] 中，元素 1 是支配元素，因为它在数组中出现了 3 次，且 3 * 2 &gt; 5 。
两个数组 [2,1,3,1,1] 和 [1,7,1,2,1] 都有与 nums 一样的支配元素，所以这是一个合法分割。
下标 4 是所有合法分割中的最小下标。</pre>

<p><strong>示例 3：</strong></p>

<pre>
<b>输入：</b>nums = [3,3,3,3,7,2,2]
<b>输出：</b>-1
<b>解释：</b>没有合法分割。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code>&nbsp;有且只有一个支配元素。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用哈希表统计每个元素出现的次数，然后找出出现次数最多的元素 $x$，即为支配元素。要使得分割后的两个数组中都有支配元素，且支配元素相同，那么支配元素一定是 $x$。

接下来，我们只需要遍历数组 $nums$，累加前缀中 $x$ 的出现次数 $cur$，并判断 $x$ 在后缀中出现的次数是否满足要求即可。如果满足要求，那么当前下标 $i$ 就是一个可行的分割下标，我们只需要选择所有可行分割下标中最小的那个即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        x, cnt = Counter(nums).most_common(1)[0]
        cur = 0
        for i, v in enumerate(nums, 1):
            if v == x:
                cur += 1
                if cur * 2 > i and (cnt - cur) * 2 > len(nums) - i:
                    return i - 1
        return -1
```

#### Java

```java
class Solution {
    public int minimumIndex(List<Integer> nums) {
        int x = 0, cnt = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int v : nums) {
            int t = freq.merge(v, 1, Integer::sum);
            if (cnt < t) {
                cnt = t;
                x = v;
            }
        }
        int cur = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums.get(i - 1) == x) {
                ++cur;
                if (cur * 2 > i && (cnt - cur) * 2 > nums.size() - i) {
                    return i - 1;
                }
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x = 0, cnt = 0;
        unordered_map<int, int> freq;
        for (int v : nums) {
            ++freq[v];
            if (freq[v] > cnt) {
                cnt = freq[v];
                x = v;
            }
        }
        int cur = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (nums[i - 1] == x) {
                ++cur;
                if (cur * 2 > i && (cnt - cur) * 2 > nums.size() - i) {
                    return i - 1;
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumIndex(nums []int) int {
	x, cnt := 0, 0
	freq := map[int]int{}
	for _, v := range nums {
		freq[v]++
		if freq[v] > cnt {
			x, cnt = v, freq[v]
		}
	}
	cur := 0
	for i, v := range nums {
		i++
		if v == x {
			cur++
			if cur*2 > i && (cnt-cur)*2 > len(nums)-i {
				return i - 1
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumIndex(nums: number[]): number {
    let [x, cnt] = [0, 0];
    const freq: Map<number, number> = new Map();
    for (const v of nums) {
        freq.set(v, (freq.get(v) ?? 0) + 1);
        if (freq.get(v)! > cnt) {
            [x, cnt] = [v, freq.get(v)!];
        }
    }
    let cur = 0;
    for (let i = 1; i <= nums.length; ++i) {
        if (nums[i - 1] === x) {
            ++cur;
            if (cur * 2 > i && (cnt - cur) * 2 > nums.length - i) {
                return i - 1;
            }
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2781. 最长合法子字符串的长度](https://leetcode.cn/problems/length-of-the-longest-valid-substring){#2781}

{{< tabs "2781" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        s = set(forbidden)
        ans = i = 0
        for j in range(len(word)):
            for k in range(j, max(j - 10, i - 1), -1):
                if word[k : j + 1] in s:
                    i = k + 1
                    break
            ans = max(ans, j - i + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestValidSubstring(String word, List<String> forbidden) {
        var s = new HashSet<>(forbidden);
        int ans = 0, n = word.length();
        for (int i = 0, j = 0; j < n; ++j) {
            for (int k = j; k > Math.max(j - 10, i - 1); --k) {
                if (s.contains(word.substring(k, j + 1))) {
                    i = k + 1;
                    break;
                }
            }
            ans = Math.max(ans, j - i + 1);
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
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> s(forbidden.begin(), forbidden.end());
        int ans = 0, n = word.size();
        for (int i = 0, j = 0; j < n; ++j) {
            for (int k = j; k > max(j - 10, i - 1); --k) {
                if (s.count(word.substr(k, j - k + 1))) {
                    i = k + 1;
                    break;
                }
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestValidSubstring(word string, forbidden []string) (ans int) {
	s := map[string]bool{}
	for _, x := range forbidden {
		s[x] = true
	}
	n := len(word)
	for i, j := 0, 0; j < n; j++ {
		for k := j; k > max(j-10, i-1); k-- {
			if s[word[k:j+1]] {
				i = k + 1
				break
			}
		}
		ans = max(ans, j-i+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestValidSubstring(word: string, forbidden: string[]): number {
    const s: Set<string> = new Set(forbidden);
    const n = word.length;
    let ans = 0;
    for (let i = 0, j = 0; j < n; ++j) {
        for (let k = j; k > Math.max(j - 10, i - 1); --k) {
            if (s.has(word.substring(k, j + 1))) {
                i = k + 1;
                break;
            }
        }
        ans = Math.max(ans, j - i + 1);
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

<p>给你一个字符串&nbsp;<code>word</code>&nbsp;和一个字符串数组&nbsp;<code>forbidden</code>&nbsp;。</p>

<p>如果一个字符串不包含&nbsp;<code>forbidden</code>&nbsp;中的任何字符串，我们称这个字符串是&nbsp;<strong>合法</strong>&nbsp;的。</p>

<p>请你返回字符串 <code>word</code>&nbsp;的一个 <strong>最长合法子字符串</strong>&nbsp;的长度。</p>

<p><strong>子字符串</strong> 指的是一个字符串中一段连续的字符，它可以为空。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>word = "cbaaaabc", forbidden = ["aaa","cb"]
<b>输出：</b>4
<b>解释：</b>总共有 11 个合法子字符串："c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" 和 "aabc"。最长合法子字符串的长度为 4 。
其他子字符串都要么包含 "aaa" ，要么包含 "cb" 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>word = "leetcode", forbidden = ["de","le","e"]
<strong>输出：</strong>4
<b>解释：</b>总共有 11 个合法子字符串："l" ，"t" ，"c" ，"o" ，"d" ，"tc" ，"co" ，"od" ，"tco" ，"cod" 和 "tcod" 。最长合法子字符串的长度为 4 。
所有其他子字符串都至少包含 "de" ，"le" 和 "e" 之一。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code>&nbsp;只包含小写英文字母。</li>
	<li><code>1 &lt;= forbidden.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= forbidden[i].length &lt;= 10</code></li>
	<li><code>forbidden[i]</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双指针

我们用哈希表 $s$ 记录所有禁止的字符串，然后用双指针 $i$ 和 $j$ 遍历字符串 $word$，其中 $i$ 和 $j$ 分别表示当前合法子字符串的左右边界。

接下来，我们枚举子字符串的右端点 $j$，判断此时 $word[k..j]$ 是否合法，如果不合法，那么我们更新 $i = k + 1$。接下来更新答案 $ans = \max(ans, j - i + 1)$。

时间复杂度 $O(n \times \max(|forbidden[i]|^2) + m)$，空间复杂度 $O(m)$。其中 $n$ 和 $m$ 分别表示字符串 $word$ 和 $forbidden$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        s = set(forbidden)
        ans = i = 0
        for j in range(len(word)):
            for k in range(j, max(j - 10, i - 1), -1):
                if word[k : j + 1] in s:
                    i = k + 1
                    break
            ans = max(ans, j - i + 1)
        return ans
```

#### Java

```java
class Solution {
    public int longestValidSubstring(String word, List<String> forbidden) {
        var s = new HashSet<>(forbidden);
        int ans = 0, n = word.length();
        for (int i = 0, j = 0; j < n; ++j) {
            for (int k = j; k > Math.max(j - 10, i - 1); --k) {
                if (s.contains(word.substring(k, j + 1))) {
                    i = k + 1;
                    break;
                }
            }
            ans = Math.max(ans, j - i + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> s(forbidden.begin(), forbidden.end());
        int ans = 0, n = word.size();
        for (int i = 0, j = 0; j < n; ++j) {
            for (int k = j; k > max(j - 10, i - 1); --k) {
                if (s.count(word.substr(k, j - k + 1))) {
                    i = k + 1;
                    break;
                }
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func longestValidSubstring(word string, forbidden []string) (ans int) {
	s := map[string]bool{}
	for _, x := range forbidden {
		s[x] = true
	}
	n := len(word)
	for i, j := 0, 0; j < n; j++ {
		for k := j; k > max(j-10, i-1); k-- {
			if s[word[k:j+1]] {
				i = k + 1
				break
			}
		}
		ans = max(ans, j-i+1)
	}
	return
}
```

#### TypeScript

```ts
function longestValidSubstring(word: string, forbidden: string[]): number {
    const s: Set<string> = new Set(forbidden);
    const n = word.length;
    let ans = 0;
    for (let i = 0, j = 0; j < n; ++j) {
        for (let k = j; k > Math.max(j - 10, i - 1); --k) {
            if (s.has(word.substring(k, j + 1))) {
                i = k + 1;
                break;
            }
        }
        ans = Math.max(ans, j - i + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2782. 唯一类别的数量 🔒](https://leetcode.cn/problems/number-of-unique-categories){#2782}

{{< tabs "2782" >}}

{{% tab "python" %}}
```python
# Definition for a category handler.
# class CategoryHandler:
#     def haveSameCategory(self, a: int, b: int) -> bool:
#         pass
class Solution:
    def numberOfCategories(
        self, n: int, categoryHandler: Optional['CategoryHandler']
    ) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        for a in range(n):
            for b in range(a + 1, n):
                if categoryHandler.haveSameCategory(a, b):
                    p[find(a)] = find(b)
        return sum(i == x for i, x in enumerate(p))
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a category handler.
 * class CategoryHandler {
 *     public CategoryHandler(int[] categories);
 *     public boolean haveSameCategory(int a, int b);
 * };
 */
class Solution {
    private int[] p;

    public int numberOfCategories(int n, CategoryHandler categoryHandler) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                if (categoryHandler.haveSameCategory(a, b)) {
                    p[find(a)] = find(b);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i == p[i]) {
                ++ans;
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                if (categoryHandler->haveSameCategory(a, b)) {
                    p[find(a)] = find(b);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i == p[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a category handler.
 * type CategoryHandler interface {
 *  HaveSameCategory(int, int) bool
 * }
 */
func numberOfCategories(n int, categoryHandler CategoryHandler) (ans int) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for a := 0; a < n; a++ {
		for b := a + 1; b < n; b++ {
			if categoryHandler.HaveSameCategory(a, b) {
				p[find(a)] = find(b)
			}
		}
	}
	for i, x := range p {
		if i == x {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a category handler.
 * class CategoryHandler {
 *     constructor(categories: number[]);
 *     public haveSameCategory(a: number, b: number): boolean;
 * }
 */
function numberOfCategories(n: number, categoryHandler: CategoryHandler): number {
    const p: number[] = new Array(n).fill(0).map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let a = 0; a < n; ++a) {
        for (let b = a + 1; b < n; ++b) {
            if (categoryHandler.haveSameCategory(a, b)) {
                p[find(a)] = find(b);
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (i === p[i]) {
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

<p>现给定一个整数 <code>n</code> 和一个 <code>CategoryHandler</code> 类的对象 <code>categoryHandler</code> 。</p>

<p>有 <code>n&nbsp;</code> 个元素，编号从 <code>0</code> 到 <code>n - 1</code>。每个元素都有一个类别，你的任务是找出唯一类别的数量。</p>

<p><code>CategoryHandler</code> 类包含以下方法，可能对你有帮助：</p>

<ul>
	<li><code>boolean haveSameCategory(integer a, integer b)</code>：如果 <code>a</code> 和 <code>b</code> 属于相同的类别，则返回 <code>true</code>，否则返回 <code>false</code>。同时，如果 <code>a</code> 或 <code>b</code> 不是有效的数字（即大于等于 <code>n</code> 或小于 <code>0</code>），它也会返回 <code>false</code>。</li>
</ul>

<p>返回&nbsp;<em>唯一类别的数量</em>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>n = 6, categoryHandler = [1,1,2,2,3,3]
<strong>输出：</strong>3
<b>解释：</b>这个示例中有 6 个元素。前两个元素属于类别 1，接下来两个属于类别 2，最后两个元素属于类别 3。所以有 3 个唯一类别。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>n = 5, categoryHandler = [1,2,3,4,5]
<b>输出：</b>5
<b>解释：</b>这个示例中有 5 个元素。每个元素属于一个唯一的类别。所以有 5 个唯一类别。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>n = 3, categoryHandler = [1,1,1]
<b>输出：</b>1
<b>解释：</b>这个示例中有 3 个元素。它们全部属于同一个类别。所以只有 1 个唯一类别。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们用并查集来维护相同类别的元素，接下来枚举所有的元素对，如果两个元素属于相同的类别，那么就将它们合并到同一个集合中。最后统计并查集中有多少个集合，就是答案。

时间复杂度 $(n^2 \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 是元素的个数，而 $\alpha$ 是阿克曼函数的反函数。

<!-- tabs:start -->

#### Python3

```python
# Definition for a category handler.
# class CategoryHandler:
#     def haveSameCategory(self, a: int, b: int) -> bool:
#         pass
class Solution:
    def numberOfCategories(
        self, n: int, categoryHandler: Optional['CategoryHandler']
    ) -> int:
        def find(x: int) -> int:
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        p = list(range(n))
        for a in range(n):
            for b in range(a + 1, n):
                if categoryHandler.haveSameCategory(a, b):
                    p[find(a)] = find(b)
        return sum(i == x for i, x in enumerate(p))
```

#### Java

```java
/**
 * Definition for a category handler.
 * class CategoryHandler {
 *     public CategoryHandler(int[] categories);
 *     public boolean haveSameCategory(int a, int b);
 * };
 */
class Solution {
    private int[] p;

    public int numberOfCategories(int n, CategoryHandler categoryHandler) {
        p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                if (categoryHandler.haveSameCategory(a, b)) {
                    p[find(a)] = find(b);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i == p[i]) {
                ++ans;
            }
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }
}
```

#### C++

```cpp
/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        for (int a = 0; a < n; ++a) {
            for (int b = a + 1; b < n; ++b) {
                if (categoryHandler->haveSameCategory(a, b)) {
                    p[find(a)] = find(b);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += i == p[i];
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a category handler.
 * type CategoryHandler interface {
 *  HaveSameCategory(int, int) bool
 * }
 */
func numberOfCategories(n int, categoryHandler CategoryHandler) (ans int) {
	p := make([]int, n)
	for i := range p {
		p[i] = i
	}
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	for a := 0; a < n; a++ {
		for b := a + 1; b < n; b++ {
			if categoryHandler.HaveSameCategory(a, b) {
				p[find(a)] = find(b)
			}
		}
	}
	for i, x := range p {
		if i == x {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition for a category handler.
 * class CategoryHandler {
 *     constructor(categories: number[]);
 *     public haveSameCategory(a: number, b: number): boolean;
 * }
 */
function numberOfCategories(n: number, categoryHandler: CategoryHandler): number {
    const p: number[] = new Array(n).fill(0).map((_, i) => i);
    const find = (x: number): number => {
        if (p[x] !== x) {
            p[x] = find(p[x]);
        }
        return p[x];
    };
    for (let a = 0; a < n; ++a) {
        for (let b = a + 1; b < n; ++b) {
            if (categoryHandler.haveSameCategory(a, b)) {
                p[find(a)] = find(b);
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        if (i === p[i]) {
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

# [2783. 航班入座率和等待名单分析 🔒](https://leetcode.cn/problems/flight-occupancy-and-waitlist-analysis){#2783}

{{< tabs "2783" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    flight_id,
    LEAST(COUNT(passenger_id), capacity) AS booked_cnt,
    GREATEST(COUNT(passenger_id) - capacity, 0) AS waitlist_cnt
FROM
    Flights
    LEFT JOIN Passengers USING (flight_id)
GROUP BY 1
ORDER BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code><font face="monospace">Flights</font></code>表</p>

<pre>
+-------------+------+
| 列名         | 类型 |
+-------------+------+
| flight_id   | int  |
| capacity    | int  |
+-------------+------+
flight_id 是该表中具有唯一值的列。 
该表的每一行包含航班ID和它的座位容量。
</pre>

<p><code>Passengers</code>表</p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| passenger_id | int  |
| flight_id    | int  |
+--------------+------+
passenger_id 是该表中具有唯一值的列。
该表的每一行包含乘客ID和航班ID。
</pre>

<p>乘客提前预订航班机票。如果乘客预订了某个航班的机票，并且该航班还有空座位，乘客的机票将会得到 <strong>确认</strong> 。然而，如果航班已经满员，乘客将会进入 <strong>等待名单</strong> 。</p>

<p>编写解决方案，报告每个航班已成功预订（获得座位）的乘客数以及处于等待名单上的乘客数。</p>

<p>按照 <code>flight_id</code> <strong>升序排序&nbsp;</strong>返回结果表。</p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Flights table:
+-----------+----------+
| flight_id | capacity |
+-----------+----------+
| 1         | 2        |
| 2         | 2        |
| 3         | 1        |
+-----------+----------+
Passengers table:
+--------------+-----------+
| passenger_id | flight_id |
+--------------+-----------+
| 101          | 1         |
| 102          | 1         |
| 103          | 1         |
| 104          | 2         |
| 105          | 2         |
| 106          | 3         |
| 107          | 3         |
+--------------+-----------+
<b>输出：</b>
+-----------+------------+--------------+
| flight_id | booked_cnt | waitlist_cnt |
+-----------+------------+--------------+
| 1         | 2          | 1            |
| 2         | 2          | 0            |
| 3         | 1          | 1            |
+-----------+------------+--------------+
<b>解释：</b>
- 航班 1 的座位容量为 2。由于有 3 名乘客预订了机票，只有 2 名乘客可以获得座位。因此，有 2 名乘客成功预订，并且有 1 名乘客在等待名单上。
- 航班 2 的座位容量为 2。由于有 2 名乘客预订了机票，每个人都可以获得座位。结果是，有 2 名乘客成功预订了座位，且没有乘客在等待名单上。
- 航班 3 的座位容量为 1。由于有 2 名乘客预订了机票，只有 1 名乘客可以获得座位。因此，有 1 名乘客成功预订，并且有 1 名乘客在等待名单上。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：左连接 + 分组

我们可以使用左连接将 `Flights` 和 `Passengers` 表连接起来，然后按照 `flight_id` 分组，统计每个航班的乘客数量。

对于每个航班，我们可以使用 `count(passenger_id)` 统计乘客数量，取 `capacity` 和 `count(passenger_id)` 的最小值作为已预订的乘客数量，取 `count(passenger_id) - capacity` 和 $0$ 的最大值作为等待名单上的乘客数量。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    flight_id,
    LEAST(COUNT(passenger_id), capacity) AS booked_cnt,
    GREATEST(COUNT(passenger_id) - capacity, 0) AS waitlist_cnt
FROM
    Flights
    LEFT JOIN Passengers USING (flight_id)
GROUP BY 1
ORDER BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2784. 检查数组是否是好的](https://leetcode.cn/problems/check-if-array-is-good){#2784}

{{< tabs "2784" >}}

{{% tab "python" %}}
```python
class Solution:
    def isGood(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        n = len(nums) - 1
        return cnt[n] == 2 and all(cnt[i] for i in range(1, n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isGood(int[] nums) {
        int n = nums.length - 1;
        int[] cnt = new int[201];
        for (int x : nums) {
            ++cnt[x];
        }
        if (cnt[n] != 2) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (cnt[i] != 1) {
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
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        int cnt[201]{};
        for (int x : nums) {
            ++cnt[x];
        }
        if (cnt[n] != 2) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (cnt[i] != 1) {
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
func isGood(nums []int) bool {
	n := len(nums) - 1
	cnt := [201]int{}
	for _, x := range nums {
		cnt[x]++
	}
	if cnt[n] != 2 {
		return false
	}
	for i := 1; i < n; i++ {
		if cnt[i] != 1 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isGood(nums: number[]): boolean {
    const n = nums.length - 1;
    const cnt: number[] = Array(201).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    if (cnt[n] !== 2) {
        return false;
    }
    for (let i = 1; i < n; ++i) {
        if (cnt[i] !== 1) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsGood(int[] nums) {
        int n = nums.Length - 1;
        int[] cnt = new int[201];
        foreach (int x in nums) {
            ++cnt[x];
        }
        if (cnt[n] != 2) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，如果它是数组&nbsp;<code>base[n]</code>&nbsp;的一个排列，我们称它是个&nbsp;<strong>好</strong>&nbsp;数组。</p>

<p><code>base[n] = [1, 2, ..., n - 1, n, n]</code>&nbsp;（换句话说，它是一个长度为 <code>n + 1</code>&nbsp;且包含&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;恰好各一次，包含 <code>n</code>&nbsp; 两次的一个数组）。比方说，<code>base[1] = [1, 1]</code>&nbsp;，<code>base[3] = [1, 2, 3, 3]</code>&nbsp;。</p>

<p>如果数组是一个好数组，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p><strong>注意：</strong>数组的排列是这些数字按任意顺序排布后重新得到的数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2, 1, 3]
<b>输出：</b>false
<b>解释：</b>因为数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 。但是 base[3] 有 4 个元素，但数组 nums 只有 3 个元素，所以无法得到 base[3] = [1, 2, 3, 3] 的排列，所以答案为 false 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1, 3, 3, 2]
<b>输出：</b>true
<b>解释：因为</b>数组的最大元素是 3 ，唯一可以构成这个数组的 base[n] 对应的 n = 3 ，可以看出数组是 base[3] = [1, 2, 3, 3] 的一个排列（交换 nums 中第二个和第四个元素）。所以答案为 true 。</pre>

<p><strong>示例 3：</strong></p>

<pre><b>输入：</b>nums = [1, 1]
<b>输出：</b>true
<b>解释：</b>因为数组的最大元素是 1 ，唯一可以构成这个数组的 base[n] 对应的 n = 1，可以看出数组是 base[1] = [1, 1] 的一个排列。所以答案为 true 。</pre>

<p><strong>示例 4：</strong></p>

<pre><b>输入：</b>nums = [3, 4, 4, 1, 2, 1]
<b>输出：</b>false
<b>解释：</b>因为数组的最大元素是 4 ，唯一可以构成这个数组的 base[n] 对应的 n = 4 。但是 base[n] 有 5 个元素而 nums 有 6 个元素。所以答案为 false 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= num[i] &lt;= 200</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个哈希表或数组 $cnt$ 记录数组 $nums$ 中每个元素出现的次数。然后我们判断是否满足以下条件：

1. $cnt[n] = 2$，即数组中最大的元素出现了两次；
2. 对于 $1 \leq i \leq n-1$，均满足 $cnt[i] = 1$，即数组中除了最大的元素外，其他元素都只出现了一次。

如果满足以上两个条件，那么数组 $nums$ 是一个好数组，否则不是。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isGood(self, nums: List[int]) -> bool:
        cnt = Counter(nums)
        n = len(nums) - 1
        return cnt[n] == 2 and all(cnt[i] for i in range(1, n))
```

#### Java

```java
class Solution {
    public boolean isGood(int[] nums) {
        int n = nums.length - 1;
        int[] cnt = new int[201];
        for (int x : nums) {
            ++cnt[x];
        }
        if (cnt[n] != 2) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (cnt[i] != 1) {
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
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        int cnt[201]{};
        for (int x : nums) {
            ++cnt[x];
        }
        if (cnt[n] != 2) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func isGood(nums []int) bool {
	n := len(nums) - 1
	cnt := [201]int{}
	for _, x := range nums {
		cnt[x]++
	}
	if cnt[n] != 2 {
		return false
	}
	for i := 1; i < n; i++ {
		if cnt[i] != 1 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function isGood(nums: number[]): boolean {
    const n = nums.length - 1;
    const cnt: number[] = Array(201).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    if (cnt[n] !== 2) {
        return false;
    }
    for (let i = 1; i < n; ++i) {
        if (cnt[i] !== 1) {
            return false;
        }
    }
    return true;
}
```

#### C#

```cs
public class Solution {
    public bool IsGood(int[] nums) {
        int n = nums.Length - 1;
        int[] cnt = new int[201];
        foreach (int x in nums) {
            ++cnt[x];
        }
        if (cnt[n] != 2) {
            return false;
        }
        for (int i = 1; i < n; ++i) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return true;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2785. 将字符串中的元音字母排序](https://leetcode.cn/problems/sort-vowels-in-a-string){#2785}

{{< tabs "2785" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortVowels(self, s: str) -> str:
        vs = [c for c in s if c.lower() in "aeiou"]
        vs.sort()
        cs = list(s)
        j = 0
        for i, c in enumerate(cs):
            if c.lower() in "aeiou":
                cs[i] = vs[j]
                j += 1
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String sortVowels(String s) {
        List<Character> vs = new ArrayList<>();
        char[] cs = s.toCharArray();
        for (char c : cs) {
            char d = Character.toLowerCase(c);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                vs.add(c);
            }
        }
        Collections.sort(vs);
        for (int i = 0, j = 0; i < cs.length; ++i) {
            char d = Character.toLowerCase(cs[i]);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                cs[i] = vs.get(j++);
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
    string sortVowels(string s) {
        string vs;
        for (auto c : s) {
            char d = tolower(c);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                vs.push_back(c);
            }
        }
        ranges::sort(vs);
        for (int i = 0, j = 0; i < s.size(); ++i) {
            char d = tolower(s[i]);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                s[i] = vs[j++];
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortVowels(s string) string {
	cs := []byte(s)
	vs := []byte{}
	for _, c := range cs {
		d := c | 32
		if d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' {
			vs = append(vs, c)
		}
	}
	sort.Slice(vs, func(i, j int) bool { return vs[i] < vs[j] })
	j := 0
	for i, c := range cs {
		d := c | 32
		if d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' {
			cs[i] = vs[j]
			j++
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortVowels(s: string): string {
    const vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    const vs = s
        .split('')
        .filter(c => vowels.includes(c))
        .sort();
    const ans: string[] = [];
    let j = 0;
    for (const c of s) {
        ans.push(vowels.includes(c) ? vs[j++] : c);
    }
    return ans.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_vowels(s: String) -> String {
        fn is_vowel(c: char) -> bool {
            matches!(c.to_ascii_lowercase(), 'a' | 'e' | 'i' | 'o' | 'u')
        }

        let mut vs: Vec<char> = s.chars().filter(|&c| is_vowel(c)).collect();
        vs.sort_unstable();

        let mut cs: Vec<char> = s.chars().collect();
        let mut j = 0;

        for (i, c) in cs.clone().into_iter().enumerate() {
            if is_vowel(c) {
                cs[i] = vs[j];
                j += 1;
            }
        }

        cs.into_iter().collect()
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public string SortVowels(string s) {
        List<char> vs = new List<char>();
        char[] cs = s.ToCharArray();
        foreach (char c in cs) {
            if (IsVowel(c)) {
                vs.Add(c);
            }
        }
        vs.Sort();
        for (int i = 0, j = 0; i < cs.Length; ++i) {
            if (IsVowel(cs[i])) {
                cs[i] = vs[j++];
            }
        }
        return new string(cs);
    }

    public bool IsVowel(char c) {
        c = char.ToLower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;，将&nbsp;<code>s</code>&nbsp;中的元素重新 <b>排列</b>&nbsp;得到新的字符串&nbsp;<code>t</code>&nbsp;，它满足：</p>

<ul>
	<li>所有辅音字母都在原来的位置上。更正式的，如果满足&nbsp;<code>0 &lt;= i &lt; s.length</code>&nbsp;的下标 <code>i</code>&nbsp;处的&nbsp;<code>s[i]</code>&nbsp;是个辅音字母，那么&nbsp;<code>t[i] = s[i]</code>&nbsp;。</li>
	<li>元音字母都必须以他们的 <strong>ASCII</strong>&nbsp;值按 <strong>非递减</strong>&nbsp;顺序排列。更正式的，对于满足&nbsp;<code>0 &lt;= i &lt; j &lt; s.length</code>&nbsp;的下标 <code>i</code>&nbsp;和 <code>j</code>&nbsp; ，如果&nbsp;<code>s[i]</code> 和&nbsp;<code>s[j]</code>&nbsp;都是元音字母，那么&nbsp;<code>t[i]</code>&nbsp;的 ASCII 值不能大于&nbsp;<code>t[j]</code>&nbsp;的 ASCII 值。</li>
</ul>

<p>请你返回结果字母串。</p>

<p>元音字母为&nbsp;<code>'a'</code>&nbsp;，<code>'e'</code>&nbsp;，<code>'i'</code>&nbsp;，<code>'o'</code>&nbsp;和&nbsp;<code>'u'</code>&nbsp;，它们可能是小写字母也可能是大写字母，辅音字母是除了这 5 个字母以外的所有字母。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>s = "lEetcOde"
<b>输出：</b>"lEOtcede"
<b>解释：</b>'E' ，'O' 和 'e' 是 s 中的元音字母，'l' ，'t' ，'c' 和 'd' 是所有的辅音。将元音字母按照 ASCII 值排序，辅音字母留在原地。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>s = "lYmpH"
<b>输出：</b>"lYmpH"
<b>解释：</b>s 中没有元音字母（s 中都为辅音字母），所以我们返回 "lYmpH" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含英语字母表中的 <strong>大写&nbsp;</strong>和 <strong>小写&nbsp;</strong>字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先将字符串中的所有元音字母存到数组或列表 $vs$ 中，然后我们对 $vs$ 进行排序。

接下来，我们遍历字符串 $s$，保持辅音字母不变，如果是元音字母，则依次按顺序替换为 $vs$ 数组中的字母。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortVowels(self, s: str) -> str:
        vs = [c for c in s if c.lower() in "aeiou"]
        vs.sort()
        cs = list(s)
        j = 0
        for i, c in enumerate(cs):
            if c.lower() in "aeiou":
                cs[i] = vs[j]
                j += 1
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String sortVowels(String s) {
        List<Character> vs = new ArrayList<>();
        char[] cs = s.toCharArray();
        for (char c : cs) {
            char d = Character.toLowerCase(c);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                vs.add(c);
            }
        }
        Collections.sort(vs);
        for (int i = 0, j = 0; i < cs.length; ++i) {
            char d = Character.toLowerCase(cs[i]);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                cs[i] = vs.get(j++);
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
    string sortVowels(string s) {
        string vs;
        for (auto c : s) {
            char d = tolower(c);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                vs.push_back(c);
            }
        }
        ranges::sort(vs);
        for (int i = 0, j = 0; i < s.size(); ++i) {
            char d = tolower(s[i]);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                s[i] = vs[j++];
            }
        }
        return s;
    }
};
```

#### Go

```go
func sortVowels(s string) string {
	cs := []byte(s)
	vs := []byte{}
	for _, c := range cs {
		d := c | 32
		if d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' {
			vs = append(vs, c)
		}
	}
	sort.Slice(vs, func(i, j int) bool { return vs[i] < vs[j] })
	j := 0
	for i, c := range cs {
		d := c | 32
		if d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u' {
			cs[i] = vs[j]
			j++
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function sortVowels(s: string): string {
    const vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    const vs = s
        .split('')
        .filter(c => vowels.includes(c))
        .sort();
    const ans: string[] = [];
    let j = 0;
    for (const c of s) {
        ans.push(vowels.includes(c) ? vs[j++] : c);
    }
    return ans.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn sort_vowels(s: String) -> String {
        fn is_vowel(c: char) -> bool {
            matches!(c.to_ascii_lowercase(), 'a' | 'e' | 'i' | 'o' | 'u')
        }

        let mut vs: Vec<char> = s.chars().filter(|&c| is_vowel(c)).collect();
        vs.sort_unstable();

        let mut cs: Vec<char> = s.chars().collect();
        let mut j = 0;

        for (i, c) in cs.clone().into_iter().enumerate() {
            if is_vowel(c) {
                cs[i] = vs[j];
                j += 1;
            }
        }

        cs.into_iter().collect()
    }
}
```

#### C#

```cs
public class Solution {
    public string SortVowels(string s) {
        List<char> vs = new List<char>();
        char[] cs = s.ToCharArray();
        foreach (char c in cs) {
            if (IsVowel(c)) {
                vs.Add(c);
            }
        }
        vs.Sort();
        for (int i = 0, j = 0; i < cs.Length; ++i) {
            if (IsVowel(cs[i])) {
                cs[i] = vs[j++];
            }
        }
        return new string(cs);
    }

    public bool IsVowel(char c) {
        c = char.ToLower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2786. 访问数组中的位置使分数最大](https://leetcode.cn/problems/visit-array-positions-to-maximize-score){#2786}

{{< tabs "2786" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        f = [-inf] * 2
        f[nums[0] & 1] = nums[0]
        for v in nums[1:]:
            f[v & 1] = max(f[v & 1], f[v & 1 ^ 1] - x) + v
        return max(f)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxScore(int[] nums, int x) {
        long[] f = new long[2];
        Arrays.fill(f, -(1L << 60));
        f[nums[0] & 1] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int v = nums[i];
            f[v & 1] = Math.max(f[v & 1], f[v & 1 ^ 1] - x) + v;
        }
        return Math.max(f[0], f[1]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        const long long inf = 1LL << 60;
        vector<long long> f(2, -inf);
        f[nums[0] & 1] = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int v = nums[i];
            f[v & 1] = max(f[v & 1], f[v & 1 ^ 1] - x) + v;
        }
        return max(f[0], f[1]);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScore(nums []int, x int) int64 {
	const inf int = 1 << 40
	f := [2]int{-inf, -inf}
	f[nums[0]&1] = nums[0]
	for _, v := range nums[1:] {
		f[v&1] = max(f[v&1], f[v&1^1]-x) + v
	}
	return int64(max(f[0], f[1]))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScore(nums: number[], x: number): number {
    const f: number[] = Array(2).fill(-Infinity);
    f[nums[0] & 1] = nums[0];
    for (let i = 1; i < nums.length; ++i) {
        const v = nums[i];
        f[v & 1] = Math.max(f[v & 1], f[(v & 1) ^ 1] - x) + v;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个正整数&nbsp;<code>x</code>&nbsp;。</p>

<p>你 <strong>一开始</strong>&nbsp;在数组的位置 <code>0</code>&nbsp;处，你可以按照下述规则访问数组中的其他位置：</p>

<ul>
	<li>如果你当前在位置&nbsp;<code>i</code>&nbsp;，那么你可以移动到满足&nbsp;<code>i &lt; j</code>&nbsp;的&nbsp;<strong>任意</strong>&nbsp;位置&nbsp;<code>j</code>&nbsp;。</li>
	<li>对于你访问的位置 <code>i</code>&nbsp;，你可以获得分数&nbsp;<code>nums[i]</code>&nbsp;。</li>
	<li>如果你从位置 <code>i</code>&nbsp;移动到位置 <code>j</code>&nbsp;且&nbsp;<code>nums[i]</code> 和&nbsp;<code>nums[j]</code>&nbsp;的 <strong>奇偶性</strong>&nbsp;不同，那么你将失去分数&nbsp;<code>x</code>&nbsp;。</li>
</ul>

<p>请你返回你能得到的 <strong>最大</strong>&nbsp;得分之和。</p>

<p><strong>注意</strong>&nbsp;，你一开始的分数为&nbsp;<code>nums[0]</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,3,6,1,9,2], x = 5
<b>输出：</b>13
<b>解释：</b>我们可以按顺序访问数组中的位置：0 -&gt; 2 -&gt; 3 -&gt; 4 。
对应位置的值为 2 ，6 ，1 和 9 。因为 6 和 1 的奇偶性不同，所以下标从 2 -&gt; 3 让你失去 x = 5 分。
总得分为：2 + 6 + 1 + 9 - 5 = 13 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,4,6,8], x = 3
<b>输出：</b>20
<b>解释：</b>数组中的所有元素奇偶性都一样，所以我们可以将每个元素都访问一次，而且不会失去任何分数。
总得分为：2 + 4 + 6 + 8 = 20 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], x &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

根据题目描述，我们可以得到以下结论：

1. 从位置 $i$ 移动到位置 $j$ 时，如果 $nums[i]$ 和 $nums[j]$ 的奇偶性不同，那么会损失 $x$ 分；
2. 从位置 $i$ 移动到位置 $j$ 时，如果 $nums[i]$ 和 $nums[j]$ 的奇偶性相同，那么不会损失分数。

因此，我们可以用一个长度为 $2$ 的数组 $f$ 来表示当前位置的奇偶性为 $0$ 和 $1$ 时的最大得分。初始时 $f$ 的值为 $-\infty$，然后我们再初始化 $f[nums[0] \& 1] = nums[0]$，表示初始位置的得分。

接下来，我们从位置 $1$ 开始遍历数组 $nums$，对于每个位置 $i$ 对应的值 $v$，我们更新 $f[v \& 1]$ 的值为 $f[v \& 1]$ 和 $f[v \& 1 \oplus 1] - x$ 的较大值再加上 $v$，即 $f[v \& 1] = \max(f[v \& 1], f[v \& 1 \oplus 1] - x) + v$。

答案为 $f[0]$ 和 $f[1]$ 中的较大值。

时间复杂度 $O(n)$，其中 $n$ 为数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        f = [-inf] * 2
        f[nums[0] & 1] = nums[0]
        for v in nums[1:]:
            f[v & 1] = max(f[v & 1], f[v & 1 ^ 1] - x) + v
        return max(f)
```

#### Java

```java
class Solution {
    public long maxScore(int[] nums, int x) {
        long[] f = new long[2];
        Arrays.fill(f, -(1L << 60));
        f[nums[0] & 1] = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            int v = nums[i];
            f[v & 1] = Math.max(f[v & 1], f[v & 1 ^ 1] - x) + v;
        }
        return Math.max(f[0], f[1]);
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        const long long inf = 1LL << 60;
        vector<long long> f(2, -inf);
        f[nums[0] & 1] = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int v = nums[i];
            f[v & 1] = max(f[v & 1], f[v & 1 ^ 1] - x) + v;
        }
        return max(f[0], f[1]);
    }
};
```

#### Go

```go
func maxScore(nums []int, x int) int64 {
	const inf int = 1 << 40
	f := [2]int{-inf, -inf}
	f[nums[0]&1] = nums[0]
	for _, v := range nums[1:] {
		f[v&1] = max(f[v&1], f[v&1^1]-x) + v
	}
	return int64(max(f[0], f[1]))
}
```

#### TypeScript

```ts
function maxScore(nums: number[], x: number): number {
    const f: number[] = Array(2).fill(-Infinity);
    f[nums[0] & 1] = nums[0];
    for (let i = 1; i < nums.length; ++i) {
        const v = nums[i];
        f[v & 1] = Math.max(f[v & 1], f[(v & 1) ^ 1] - x) + v;
    }
    return Math.max(...f);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2787. 将一个数字表示成幂的和的方案数](https://leetcode.cn/problems/ways-to-express-an-integer-as-sum-of-powers){#2787}

{{< tabs "2787" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (n + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            k = pow(i, x)
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if k <= j:
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod
        return f[n][n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfWays(int n, int x) {
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            long k = (long) Math.pow(i, x);
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (k <= j) {
                    f[i][j] = (f[i][j] + f[i - 1][j - (int) k]) % mod;
                }
            }
        }
        return f[n][n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            long long k = (long long) pow(i, x);
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (k <= j) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                }
            }
        }
        return f[n][n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfWays(n int, x int) int {
	const mod int = 1e9 + 7
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		k := int(math.Pow(float64(i), float64(x)))
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if k <= j {
				f[i][j] = (f[i][j] + f[i-1][j-k]) % mod
			}
		}
	}
	return f[n][n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfWays(n: number, x: number): number {
    const mod = 10 ** 9 + 7;
    const f = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        const k = Math.pow(i, x);
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (k <= j) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    return f[n][n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let x = x as u32;
        let mut f = vec![vec![0; n + 1]; n + 1];
        f[0][0] = 1;
        for i in 1..=n {
            let k = (i as i64).pow(x);
            for j in 0..=n {
                f[i][j] = f[i - 1][j];
                if j >= k as usize {
                    f[i][j] = (f[i][j] + f[i - 1][j - k as usize]) % MOD;
                }
            }
        }
        f[n][n] as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number} x
 * @return {number}
 */
var numberOfWays = function (n, x) {
    const mod = 10 ** 9 + 7;
    const f = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        const k = Math.pow(i, x);
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (k <= j) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    return f[n][n];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int NumberOfWays(int n, int x) {
        const int mod = 1000000007;
        int[,] f = new int[n + 1, n + 1];
        f[0, 0] = 1;
        for (int i = 1; i <= n; ++i) {
            long k = (long)Math.Pow(i, x);
            for (int j = 0; j <= n; ++j) {
                f[i, j] = f[i - 1, j];
                if (k <= j) {
                    f[i, j] = (f[i, j] + f[i - 1, j - (int)k]) % mod;
                }
            }
        }
        return f[n, n];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个 <strong>正</strong>&nbsp;整数&nbsp;<code>n</code> 和&nbsp;<code>x</code>&nbsp;。</p>

<p>请你返回将<em>&nbsp;</em><code>n</code>&nbsp;表示成一些&nbsp;<strong>互不相同</strong>&nbsp;正整数的<em>&nbsp;</em><code>x</code>&nbsp;次幂之和的方案数。换句话说，你需要返回互不相同整数&nbsp;<code>[n<sub>1</sub>, n<sub>2</sub>, ..., n<sub>k</sub>]</code>&nbsp;的集合数目，满足&nbsp;<code>n = n<sub>1</sub><sup>x</sup> + n<sub>2</sub><sup>x</sup> + ... + n<sub>k</sub><sup>x</sup></code>&nbsp;。</p>

<p>由于答案可能非常大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;取余后返回。</p>

<p>比方说，<code>n = 160</code> 且&nbsp;<code>x = 3</code>&nbsp;，一个表示&nbsp;<code>n</code>&nbsp;的方法是&nbsp;<code>n = 2<sup>3</sup> + 3<sup>3</sup> + 5<sup>3</sup></code><sup>&nbsp;</sup>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>n = 10, x = 2
<b>输出：</b>1
<b>解释：</b>我们可以将 n 表示为：n = 3<sup>2</sup> + 1<sup>2</sup> = 10 。
这是唯一将 10 表达成不同整数 2 次方之和的方案。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>n = 4, x = 1
<b>输出：</b>2
<b>解释：</b>我们可以将 n 按以下方案表示：
- n = 4<sup>1</sup> = 4 。
- n = 3<sup>1</sup> + 1<sup>1</sup> = 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>1 &lt;= x &lt;= 5</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示在前 $i$ 个正整数中选取一些数的 $x$ 次幂之和等于 $j$ 的方案数，初始时 $f[0][0] = 1$，其余均为 $0$。答案为 $f[n][n]$。

对于每个正整数 $i$，我们可以选择不选它或者选它：

-   不选它：此时方案数为 $f[i-1][j]$；
-   选它：此时方案数为 $f[i-1][j-i^x]$（前提是 $j \geq i^x$）。

因此状态转移方程为：

$$
f[i][j] = f[i-1][j] + (j \geq i^x ? f[i-1][j-i^x] : 0)
$$

注意到答案可能非常大，我们需要对 $10^9 + 7$ 取余。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是题目中给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10**9 + 7
        f = [[0] * (n + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i in range(1, n + 1):
            k = pow(i, x)
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if k <= j:
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod
        return f[n][n]
```

#### Java

```java
class Solution {
    public int numberOfWays(int n, int x) {
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            long k = (long) Math.pow(i, x);
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (k <= j) {
                    f[i][j] = (f[i][j] + f[i - 1][j - (int) k]) % mod;
                }
            }
        }
        return f[n][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfWays(int n, int x) {
        const int mod = 1e9 + 7;
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            long long k = (long long) pow(i, x);
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (k <= j) {
                    f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
                }
            }
        }
        return f[n][n];
    }
};
```

#### Go

```go
func numberOfWays(n int, x int) int {
	const mod int = 1e9 + 7
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		k := int(math.Pow(float64(i), float64(x)))
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if k <= j {
				f[i][j] = (f[i][j] + f[i-1][j-k]) % mod
			}
		}
	}
	return f[n][n]
}
```

#### TypeScript

```ts
function numberOfWays(n: number, x: number): number {
    const mod = 10 ** 9 + 7;
    const f = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        const k = Math.pow(i, x);
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (k <= j) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    return f[n][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_ways(n: i32, x: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let x = x as u32;
        let mut f = vec![vec![0; n + 1]; n + 1];
        f[0][0] = 1;
        for i in 1..=n {
            let k = (i as i64).pow(x);
            for j in 0..=n {
                f[i][j] = f[i - 1][j];
                if j >= k as usize {
                    f[i][j] = (f[i][j] + f[i - 1][j - k as usize]) % MOD;
                }
            }
        }
        f[n][n] as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number} x
 * @return {number}
 */
var numberOfWays = function (n, x) {
    const mod = 10 ** 9 + 7;
    const f = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        const k = Math.pow(i, x);
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (k <= j) {
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % mod;
            }
        }
    }
    return f[n][n];
};
```

#### C#

```cs
public class Solution {
    public int NumberOfWays(int n, int x) {
        const int mod = 1000000007;
        int[,] f = new int[n + 1, n + 1];
        f[0, 0] = 1;
        for (int i = 1; i <= n; ++i) {
            long k = (long)Math.Pow(i, x);
            for (int j = 0; j <= n; ++j) {
                f[i, j] = f[i - 1, j];
                if (k <= j) {
                    f[i, j] = (f[i, j] + f[i - 1, j - (int)k]) % mod;
                }
            }
        }
        return f[n, n];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2788. 按分隔符拆分字符串](https://leetcode.cn/problems/split-strings-by-separator){#2788}

{{< tabs "2788" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        return [s for w in words for s in w.split(separator) if s]
```
{{% /tab %}}
{{% tab "java" %}}
```java
import java.util.regex.Pattern;

class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> ans = new ArrayList<>();
        for (var w : words) {
            for (var s : w.split(Pattern.quote(String.valueOf(separator)))) {
                if (s.length() > 0) {
                    ans.add(s);
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
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (const auto& w : words) {
            istringstream ss(w);
            string s;
            while (getline(ss, s, separator)) {
                if (!s.empty()) {
                    ans.push_back(s);
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
func splitWordsBySeparator(words []string, separator byte) (ans []string) {
	for _, w := range words {
		for _, s := range strings.Split(w, string(separator)) {
			if s != "" {
				ans = append(ans, s)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function splitWordsBySeparator(words: string[], separator: string): string[] {
    return words.flatMap(w => w.split(separator).filter(s => s.length > 0));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组 <code>words</code> 和一个字符 <code>separator</code> ，请你按 <code>separator</code> 拆分 <code>words</code> 中的每个字符串。</p>

<p>返回一个由拆分后的新字符串组成的字符串数组，<strong>不包括空字符串</strong> 。</p>

<p><strong>注意</strong></p>

<ul>
	<li><code>separator</code> 用于决定拆分发生的位置，但它不包含在结果字符串中。</li>
	<li>拆分可能形成两个以上的字符串。</li>
	<li>结果字符串必须保持初始相同的先后顺序。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["one.two.three","four.five","six"], separator = "."
<strong>输出：</strong>["one","two","three","four","five","six"]
<strong>解释：</strong>在本示例中，我们进行下述拆分：

"one.two.three" 拆分为 "one", "two", "three"
"four.five" 拆分为 "four", "five"
"six" 拆分为 "six" 

因此，结果数组为 ["one","two","three","four","five","six"] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["$easy$","$problem$"], separator = "$"
<strong>输出：</strong>["easy","problem"]
<strong>解释：</strong>在本示例中，我们进行下述拆分：

"$easy$" 拆分为 "easy"（不包括空字符串）
"$problem$" 拆分为 "problem"（不包括空字符串）

因此，结果数组为 ["easy","problem"] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["|||"], separator = "|"
<strong>输出：</strong>[]
<strong>解释：</strong>在本示例中，"|||" 的拆分结果将只包含一些空字符串，所以我们返回一个空数组 [] 。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 20</code></li>
	<li><code>words[i]</code> 中的字符要么是小写英文字母，要么就是字符串 <code>".,|$#@"</code> 中的字符（不包括引号）</li>
	<li><code>separator</code> 是字符串 <code>".,|$#@"</code> 中的某个字符（不包括引号）</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历字符串数组 $words$，对于每个字符串 $w$，我们使用 `separator` 作为分隔符进行拆分，如果拆分后的字符串不为空，则将其加入答案数组。

时间复杂度 $O(n \times m)$，空间复杂度 $O(m)$，其中 $n$ 是字符串数组 $words$ 的长度，而 $m$ 是字符串数组 $words$ 中字符串的最大长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        return [s for w in words for s in w.split(separator) if s]
```

#### Java

```java
import java.util.regex.Pattern;

class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> ans = new ArrayList<>();
        for (var w : words) {
            for (var s : w.split(Pattern.quote(String.valueOf(separator)))) {
                if (s.length() > 0) {
                    ans.add(s);
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
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (const auto& w : words) {
            istringstream ss(w);
            string s;
            while (getline(ss, s, separator)) {
                if (!s.empty()) {
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func splitWordsBySeparator(words []string, separator byte) (ans []string) {
	for _, w := range words {
		for _, s := range strings.Split(w, string(separator)) {
			if s != "" {
				ans = append(ans, s)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function splitWordsBySeparator(words: string[], separator: string): string[] {
    return words.flatMap(w => w.split(separator).filter(s => s.length > 0));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2789. 合并后数组中的最大元素](https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations){#2789}

{{< tabs "2789" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                nums[i] += nums[i + 1]
        return max(nums)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxArrayValue(int[] nums) {
        int n = nums.length;
        long ans = nums[n - 1], t = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= t) {
                t += nums[i];
            } else {
                t = nums[i];
            }
            ans = Math.max(ans, t);
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
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[n - 1], t = nums[n - 1];
        for (int i = n - 2; ~i; --i) {
            if (nums[i] <= t) {
                t += nums[i];
            } else {
                t = nums[i];
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxArrayValue(nums []int) int64 {
	n := len(nums)
	ans, t := nums[n-1], nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if nums[i] <= t {
			t += nums[i]
		} else {
			t = nums[i]
		}
		ans = max(ans, t)
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxArrayValue(nums: number[]): number {
    for (let i = nums.length - 2; i >= 0; --i) {
        if (nums[i] <= nums[i + 1]) {
            nums[i] += nums[i + 1];
        }
    }
    return Math.max(...nums);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、由正整数组成的数组 <code>nums</code> 。</p>

<p>你可以在数组上执行下述操作 <strong>任意</strong> 次：</p>

<ul>
	<li>选中一个同时满足&nbsp;<code>0 &lt;= i &lt; nums.length - 1</code> 和 <code>nums[i] &lt;= nums[i + 1]</code> 的整数 <code>i</code> 。将元素 <code>nums[i + 1]</code> 替换为 <code>nums[i] + nums[i + 1]</code> ，并从数组中删除元素 <code>nums[i]</code> 。</li>
</ul>

<p>返回你可以从最终数组中获得的 <strong>最大</strong> 元素的值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [2,3,7,9,3]
<strong>输出：</strong>21
<strong>解释：</strong>我们可以在数组上执行下述操作：
- 选中 i = 0 ，得到数组 nums = [<strong><em>5</em></strong>,7,9,3] 。
- 选中 i = 1 ，得到数组 nums = [5,<em><strong>16</strong></em>,3] 。
- 选中 i = 0 ，得到数组 nums = [<em><strong>21</strong></em>,3] 。
最终数组中的最大元素是 21 。可以证明我们无法获得更大的元素。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,3,3]
<strong>输出：</strong>11
<strong>解释：</strong>我们可以在数组上执行下述操作：
- 选中 i = 1 ，得到数组 nums = [5,<em><strong>6</strong></em>] 。
- 选中 i = 0 ，得到数组 nums = [<em><strong>11</strong></em>] 。
最终数组中只有一个元素，即 11 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：倒序合并

根据题目描述，为了最大化合并后的数组中的最大元素，我们应该先合并右侧的元素，使得右侧的元素尽可能大，从而尽可能多地执行合并操作，最终得到最大的元素。

因此，我们可以从右向左遍历数组，对于每个位置 $i$，其中 $i \in [0, n - 2]$，如果 $nums[i] \leq nums[i + 1]$，我们就将 $nums[i]$ 更新为 $nums[i] + nums[i + 1]$。这样做，相当于将 $nums[i]$ 与 $nums[i + 1]$ 合并，并且删掉 $nums[i]$。

最终，数组中的最大元素就是合并后的数组中的最大元素。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                nums[i] += nums[i + 1]
        return max(nums)
```

#### Java

```java
class Solution {
    public long maxArrayValue(int[] nums) {
        int n = nums.length;
        long ans = nums[n - 1], t = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= t) {
                t += nums[i];
            } else {
                t = nums[i];
            }
            ans = Math.max(ans, t);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[n - 1], t = nums[n - 1];
        for (int i = n - 2; ~i; --i) {
            if (nums[i] <= t) {
                t += nums[i];
            } else {
                t = nums[i];
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
```

#### Go

```go
func maxArrayValue(nums []int) int64 {
	n := len(nums)
	ans, t := nums[n-1], nums[n-1]
	for i := n - 2; i >= 0; i-- {
		if nums[i] <= t {
			t += nums[i]
		} else {
			t = nums[i]
		}
		ans = max(ans, t)
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function maxArrayValue(nums: number[]): number {
    for (let i = nums.length - 2; i >= 0; --i) {
        if (nums[i] <= nums[i + 1]) {
            nums[i] += nums[i + 1];
        }
    }
    return Math.max(...nums);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
