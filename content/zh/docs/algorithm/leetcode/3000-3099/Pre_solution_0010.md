---
title: "3090_每个字符最多出现两次的最长子字符串"
date: 2025-10-08T18:39:55+08:00
weight: 10
tags: [交互, 位运算, 前缀和, 动态规划, 哈希表, 堆（优先队列）, 字典树, 字符串, 排序, 数学, 数组, 有序集合, 枚举, 滑动窗口, 贪心]
---

{{< markmap >}}
### [3090_每个字符最多出现两次的最长子字符串](#3090)
#### [哈希表](#3090)
#### [字符串](#3090)
#### [滑动窗口](#3090)
### [3091_执行操作使数据元素之和大于等于 K](#3091)
#### [贪心](#3091)
#### [数学](#3091)
#### [枚举](#3091)
### [3092_最高频率的 ID](#3092)
#### [数组](#3092)
#### [哈希表](#3092)
#### [有序集合](#3092)
#### [堆（优先队列）](#3092)
### [3093_最长公共后缀查询](#3093)
#### [字典树](#3093)
#### [数组](#3093)
#### [字符串](#3093)
### [3094_使用按位查询猜测数字 II 🔒](#3094)
#### [位运算](#3094)
#### [交互](#3094)
### [3095_或值至少 K 的最短子数组 I](#3095)
#### [位运算](#3095)
#### [数组](#3095)
#### [滑动窗口](#3095)
### [3096_得到更多分数的最少关卡数目](#3096)
#### [数组](#3096)
#### [前缀和](#3096)
### [3097_或值至少为 K 的最短子数组 II](#3097)
#### [位运算](#3097)
#### [数组](#3097)
#### [滑动窗口](#3097)
### [3098_求出所有子序列的能量和](#3098)
#### [数组](#3098)
#### [动态规划](#3098)
#### [排序](#3098)
### [3099_哈沙德数](#3099)
#### [数学](#3099)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3090_每个字符最多出现两次的最长子字符串
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 3091_执行操作使数据元素之和大于等于 K
___
#### 贪心
___
#### 数学
___
#### 枚举
---
### 3092_最高频率的 ID
___
#### 数组
___
#### 哈希表
___
#### 有序集合
___
#### 堆（优先队列）
---
### 3093_最长公共后缀查询
___
#### 字典树
___
#### 数组
___
#### 字符串
---
### 3094_使用按位查询猜测数字 II 🔒
___
#### 位运算
___
#### 交互
---
### 3095_或值至少 K 的最短子数组 I
___
#### 位运算
___
#### 数组
___
#### 滑动窗口
---
### 3096_得到更多分数的最少关卡数目
___
#### 数组
___
#### 前缀和
---
### 3097_或值至少为 K 的最短子数组 II
___
#### 位运算
___
#### 数组
___
#### 滑动窗口
---
### 3098_求出所有子序列的能量和
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 3099_哈沙德数
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 交互 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 堆（优先队列） |
| 字典树 | 字符串 | 排序 |
| 数学 | 数组 | 有序集合 |
| 枚举 | 滑动窗口 | 贪心 |

# [3090. 每个字符最多出现两次的最长子字符串](https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences){#3090}

{{< tabs "3090" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        cnt = Counter()
        ans = i = 0
        for j, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 2:
                cnt[s[i]] -= 1
                i += 1
            ans = max(ans, j - i + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumLengthSubstring(String s) {
        int[] cnt = new int[26];
        int ans = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            int idx = s.charAt(j) - 'a';
            ++cnt[idx];
            while (cnt[idx] > 2) {
                --cnt[s.charAt(i++) - 'a'];
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
    int maximumLengthSubstring(string s) {
        int cnt[26]{};
        int ans = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            int idx = s[j] - 'a';
            ++cnt[idx];
            while (cnt[idx] > 2) {
                --cnt[s[i++] - 'a'];
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
func maximumLengthSubstring(s string) (ans int) {
	cnt := [26]int{}
	i := 0
	for j, c := range s {
		idx := c - 'a'
		cnt[idx]++
		for cnt[idx] > 2 {
			cnt[s[i]-'a']--
			i++
		}
		ans = max(ans, j-i+1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumLengthSubstring(s: string): number {
    let ans = 0;
    const cnt: number[] = Array(26).fill(0);
    for (let i = 0, j = 0; j < s.length; ++j) {
        const idx = s[j].charCodeAt(0) - 'a'.charCodeAt(0);
        ++cnt[idx];
        while (cnt[idx] > 2) {
            --cnt[s[i++].charCodeAt(0) - 'a'.charCodeAt(0)];
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

<p>给你一个字符串 <code>s</code> ，请找出满足每个字符最多出现两次的最长子字符串，并返回该<span data-keyword="substring">子字符串</span>的<strong> 最大 </strong>长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "bcbbbcba"</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>以下子字符串长度为 4，并且每个字符最多出现两次：<code>"bcbb<u>bcba</u>"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">s = "aaaa"</span></p>

<p><strong>输出：</strong> <span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>以下子字符串长度为 2，并且每个字符最多出现两次：<code>"<u>aa</u>aa"</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul><!-- 字符串 s 的长度在 2 到 100 之间 -->
	<li><code>2 &lt;= s.length &lt;= 100</code></li>
	<!-- 字符串 s 仅包含小写英文字母 -->
	<li><code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$ 来维护一个滑动窗口，用一个数组 $cnt$ 来记录窗口中每个字符的出现次数。

每一次，我们将指针 $j$ 对应的字符 $c$ 加入窗口，然后判断 $cnt[c]$ 是否大于 $2$，如果大于 $2$，则将指针 $i$ 循环右移，直到 $cnt[c]$ 小于等于 $2$。此时，我们更新答案 $ans = \max(ans, j - i + 1)$。

最终，我们返回答案 $ans$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 为字符集，本题中 $\Sigma = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        cnt = Counter()
        ans = i = 0
        for j, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 2:
                cnt[s[i]] -= 1
                i += 1
            ans = max(ans, j - i + 1)
        return ans
```

#### Java

```java
class Solution {
    public int maximumLengthSubstring(String s) {
        int[] cnt = new int[26];
        int ans = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            int idx = s.charAt(j) - 'a';
            ++cnt[idx];
            while (cnt[idx] > 2) {
                --cnt[s.charAt(i++) - 'a'];
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
    int maximumLengthSubstring(string s) {
        int cnt[26]{};
        int ans = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            int idx = s[j] - 'a';
            ++cnt[idx];
            while (cnt[idx] > 2) {
                --cnt[s[i++] - 'a'];
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func maximumLengthSubstring(s string) (ans int) {
	cnt := [26]int{}
	i := 0
	for j, c := range s {
		idx := c - 'a'
		cnt[idx]++
		for cnt[idx] > 2 {
			cnt[s[i]-'a']--
			i++
		}
		ans = max(ans, j-i+1)
	}
	return
}
```

#### TypeScript

```ts
function maximumLengthSubstring(s: string): number {
    let ans = 0;
    const cnt: number[] = Array(26).fill(0);
    for (let i = 0, j = 0; j < s.length; ++j) {
        const idx = s[j].charCodeAt(0) - 'a'.charCodeAt(0);
        ++cnt[idx];
        while (cnt[idx] > 2) {
            --cnt[s[i++].charCodeAt(0) - 'a'.charCodeAt(0)];
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

# [3091. 执行操作使数据元素之和大于等于 K](https://leetcode.cn/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k){#3091}

{{< tabs "3091" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, k: int) -> int:
        ans = k
        for a in range(k):
            x = a + 1
            b = (k + x - 1) // x - 1
            ans = min(ans, a + b)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(int k) {
        int ans = k;
        for (int a = 0; a < k; ++a) {
            int x = a + 1;
            int b = (k + x - 1) / x - 1;
            ans = Math.min(ans, a + b);
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
    int minOperations(int k) {
        int ans = k;
        for (int a = 0; a < k; ++a) {
            int x = a + 1;
            int b = (k + x - 1) / x - 1;
            ans = min(ans, a + b);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(k int) int {
	ans := k
	for a := 0; a < k; a++ {
		x := a + 1
		b := (k+x-1)/x - 1
		ans = min(ans, a+b)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(k: number): number {
    let ans = k;
    for (let a = 0; a < k; ++a) {
        const x = a + 1;
        const b = Math.ceil(k / x) - 1;
        ans = Math.min(ans, a + b);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(k: i32) -> i32 {
        let mut ans = k;
        for a in 0..k {
            let x = a + 1;
            let b = (k + x - 1) / x - 1;
            ans = ans.min(a + b);
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

<p>给你一个<strong>正整数</strong> <code>k</code> 。最初，你有一个数组 <code>nums = [1]</code> 。</p>

<p>你可以对数组执行以下 <strong>任意 </strong>操作 <strong>任意 </strong>次数（<strong>可能为零</strong>）：</p>

<ul>
	<li>选择数组中的任何一个元素，然后将它的值<strong> 增加</strong> <code>1</code> 。</li>
	<li>复制数组中的任何一个元素，然后将它附加到数组的末尾。</li>
</ul>

<p>返回使得最终数组元素之<strong> 和 </strong>大于或等于 <code>k</code> 所需的 <strong>最少 </strong>操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">k = 11</span></p>

<p><strong>输出：</strong><span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>可以对数组 <code>nums = [1]</code> 执行以下操作：</p>

<ul>
	<li>将元素的值增加 <code>1</code> 三次。结果数组为 <code>nums = [4]</code> 。</li>
	<li>复制元素两次。结果数组为 <code>nums = [4,4,4]</code> 。</li>
</ul>

<p>最终数组的和为 <code>4 + 4 + 4 = 12</code> ，大于等于 <code>k = 11</code> 。<br />
执行的总操作次数为 <code>3 + 2 = 5</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">k = 1</span></p>

<p><strong>输出：</strong><span class="example-io">0</span></p>

<p><strong>解释：</strong></p>

<p>原始数组的和已经大于等于 <code>1</code> ，因此不需要执行操作。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们应该将复制的操作（即操作 $2$）放后面，这样可以减少操作次数。

因此，我们在 $[0, k]$ 的范围内枚举操作 $1$ 的次数 $a$，那么操作 $2$ 的次数 $b = \left\lceil \frac{k}{a+1} \right\rceil - 1$。取最小的 $a+b$ 即可。

时间复杂度 $O(k)$，其中 $k$ 为输入的正整数 $k$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, k: int) -> int:
        ans = k
        for a in range(k):
            x = a + 1
            b = (k + x - 1) // x - 1
            ans = min(ans, a + b)
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(int k) {
        int ans = k;
        for (int a = 0; a < k; ++a) {
            int x = a + 1;
            int b = (k + x - 1) / x - 1;
            ans = Math.min(ans, a + b);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minOperations(int k) {
        int ans = k;
        for (int a = 0; a < k; ++a) {
            int x = a + 1;
            int b = (k + x - 1) / x - 1;
            ans = min(ans, a + b);
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(k int) int {
	ans := k
	for a := 0; a < k; a++ {
		x := a + 1
		b := (k+x-1)/x - 1
		ans = min(ans, a+b)
	}
	return ans
}
```

#### TypeScript

```ts
function minOperations(k: number): number {
    let ans = k;
    for (let a = 0; a < k; ++a) {
        const x = a + 1;
        const b = Math.ceil(k / x) - 1;
        ans = Math.min(ans, a + b);
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(k: i32) -> i32 {
        let mut ans = k;
        for a in 0..k {
            let x = a + 1;
            let b = (k + x - 1) / x - 1;
            ans = ans.min(a + b);
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

# [3092. 最高频率的 ID](https://leetcode.cn/problems/most-frequent-ids){#3092}

{{< tabs "3092" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        cnt = Counter()
        lazy = Counter()
        ans = []
        pq = []
        for x, f in zip(nums, freq):
            lazy[cnt[x]] += 1
            cnt[x] += f
            heappush(pq, -cnt[x])
            while pq and lazy[-pq[0]] > 0:
                lazy[-pq[0]] -= 1
                heappop(pq)
            ans.append(0 if not pq else -pq[0])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        Map<Integer, Long> cnt = new HashMap<>();
        Map<Long, Integer> lazy = new HashMap<>();
        int n = nums.length;
        long[] ans = new long[n];
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; ++i) {
            int x = nums[i], f = freq[i];
            lazy.merge(cnt.getOrDefault(x, 0L), 1, Integer::sum);
            cnt.merge(x, (long) f, Long::sum);
            pq.add(cnt.get(x));
            while (!pq.isEmpty() && lazy.getOrDefault(pq.peek(), 0) > 0) {
                lazy.merge(pq.poll(), -1, Integer::sum);
            }
            ans[i] = pq.isEmpty() ? 0 : pq.peek();
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
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> cnt;
        unordered_map<long long, int> lazy;
        int n = nums.size();
        vector<long long> ans(n);
        priority_queue<long long> pq;

        for (int i = 0; i < n; ++i) {
            int x = nums[i], f = freq[i];
            lazy[cnt[x]]++;
            cnt[x] += f;
            pq.push(cnt[x]);
            while (!pq.empty() && lazy[pq.top()] > 0) {
                lazy[pq.top()]--;
                pq.pop();
            }
            ans[i] = pq.empty() ? 0 : pq.top();
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostFrequentIDs(nums []int, freq []int) []int64 {
	n := len(nums)
	cnt := map[int]int{}
	lazy := map[int]int{}
	ans := make([]int64, n)
	pq := hp{}
	heap.Init(&pq)
	for i, x := range nums {
		f := freq[i]
		lazy[cnt[x]]++
		cnt[x] += f
		heap.Push(&pq, cnt[x])
		for pq.Len() > 0 && lazy[pq.IntSlice[0]] > 0 {
			lazy[pq.IntSlice[0]]--
			heap.Pop(&pq)
		}
		if pq.Len() > 0 {
			ans[i] = int64(pq.IntSlice[0])
		}
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你需要在一个集合里动态记录 ID 的出现频率。给你两个长度都为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code> 和&nbsp;<code>freq</code>&nbsp;，<code>nums</code>&nbsp;中每一个元素表示一个 ID ，对应的 <code>freq</code>&nbsp;中的元素表示这个 ID 在集合中此次操作后需要增加或者减少的数目。</p>

<ul>
	<li><strong>增加 ID 的数目：</strong>如果&nbsp;<code>freq[i]</code>&nbsp;是正数，那么&nbsp;<code>freq[i]</code>&nbsp;个 ID 为&nbsp;<code>nums[i]</code>&nbsp;的元素在第 <code>i</code>&nbsp;步操作后会添加到集合中。</li>
	<li><strong>减少 ID 的数目：</strong>如果&nbsp;<code>freq[i]</code>&nbsp;是负数，那么&nbsp;<code>-freq[i]</code>&nbsp;个 ID 为&nbsp;<code>nums[i]</code>&nbsp;的元素在第 <code>i</code>&nbsp;步操作后会从集合中删除。</li>
</ul>

<p>请你返回一个长度为 <code>n</code>&nbsp;的数组 <code>ans</code>&nbsp;，其中&nbsp;<code>ans[i]</code>&nbsp;表示第 <code>i</code>&nbsp;步操作后出现频率最高的 ID <strong>数目</strong>&nbsp;，如果在某次操作后集合为空，那么 <code>ans[i]</code>&nbsp;为 0 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,3,2,1], freq = [3,2,-3,1]</span></p>

<p><span class="example-io"><b>输出：</b>[3,3,2,2]</span></p>

<p><strong>解释：</strong></p>

<p>第 0 步操作后，有 3 个 ID 为 2 的元素，所以&nbsp;<code>ans[0] = 3</code>&nbsp;。<br />
第 1 步操作后，有 3 个 ID 为 2 的元素和 2 个 ID 为 3 的元素，所以&nbsp;<code>ans[1] = 3</code>&nbsp;。<br />
第 2 步操作后，有 2 个 ID 为 3 的元素，所以&nbsp;<code>ans[2] = 2</code>&nbsp;。<br />
第 3 步操作后，有 2 个 ID 为 3 的元素和 1 个 ID 为 1 的元素，所以&nbsp;<code>ans[3] = 2</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [5,5,3], freq = [2,-2,1]</span></p>

<p><span class="example-io"><b>输出：</b>[2,0,1]</span></p>

<p><strong>解释：</strong></p>

<p>第 0 步操作后，有 2 个 ID 为 5 的元素，所以&nbsp;<code>ans[0] = 2</code>&nbsp;。<br />
第 1 步操作后，集合中没有任何元素，所以&nbsp;<code>ans[1] = 0</code>&nbsp;。<br />
第 2 步操作后，有 1 个 ID 为 3 的元素，所以&nbsp;<code>ans[2] = 1</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == freq.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= freq[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>freq[i] != 0</code></li>
	<li>输入保证任何操作后，集合中的元素出现次数不会为负数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 优先队列（大根堆）

我们用一个哈希表 $cnt$ 来记录每个 ID 的出现次数，用一个哈希表 $lazy$ 来记录每个次数需要被删除的个数。用一个优先队列 $pq$ 来维护出现次数的最大值。

每一次操作 $(x, f)$，我们需要更新 $x$ 的出现次数 $cnt[x]$，这意味着 $cnt[x]$ 在 $lazy$ 中的值需要增加 $1$，表示该次数需要删除的个数增加 $1$。然后我们更新 $cnt[x]$ 的值，将 $cnt[x]$ 加上 $f$。然后我们更新后的 $cnt[x]$ 的值加入优先队列 $pq$ 中。然后我们检查优先队列 $pq$ 的堆顶元素，如果 $lazy$ 中对应的次数需要删除的个数大于 $0$，我们就将堆顶元素弹出。最后，我们判断优先队列是否为空，如果不为空，堆顶元素就是出现次数的最大值，我们将其加入答案数组中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostFrequentIDs(self, nums: List[int], freq: List[int]) -> List[int]:
        cnt = Counter()
        lazy = Counter()
        ans = []
        pq = []
        for x, f in zip(nums, freq):
            lazy[cnt[x]] += 1
            cnt[x] += f
            heappush(pq, -cnt[x])
            while pq and lazy[-pq[0]] > 0:
                lazy[-pq[0]] -= 1
                heappop(pq)
            ans.append(0 if not pq else -pq[0])
        return ans
```

#### Java

```java
class Solution {
    public long[] mostFrequentIDs(int[] nums, int[] freq) {
        Map<Integer, Long> cnt = new HashMap<>();
        Map<Long, Integer> lazy = new HashMap<>();
        int n = nums.length;
        long[] ans = new long[n];
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; ++i) {
            int x = nums[i], f = freq[i];
            lazy.merge(cnt.getOrDefault(x, 0L), 1, Integer::sum);
            cnt.merge(x, (long) f, Long::sum);
            pq.add(cnt.get(x));
            while (!pq.isEmpty() && lazy.getOrDefault(pq.peek(), 0) > 0) {
                lazy.merge(pq.poll(), -1, Integer::sum);
            }
            ans[i] = pq.isEmpty() ? 0 : pq.peek();
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> cnt;
        unordered_map<long long, int> lazy;
        int n = nums.size();
        vector<long long> ans(n);
        priority_queue<long long> pq;

        for (int i = 0; i < n; ++i) {
            int x = nums[i], f = freq[i];
            lazy[cnt[x]]++;
            cnt[x] += f;
            pq.push(cnt[x]);
            while (!pq.empty() && lazy[pq.top()] > 0) {
                lazy[pq.top()]--;
                pq.pop();
            }
            ans[i] = pq.empty() ? 0 : pq.top();
        }

        return ans;
    }
};
```

#### Go

```go
func mostFrequentIDs(nums []int, freq []int) []int64 {
	n := len(nums)
	cnt := map[int]int{}
	lazy := map[int]int{}
	ans := make([]int64, n)
	pq := hp{}
	heap.Init(&pq)
	for i, x := range nums {
		f := freq[i]
		lazy[cnt[x]]++
		cnt[x] += f
		heap.Push(&pq, cnt[x])
		for pq.Len() > 0 && lazy[pq.IntSlice[0]] > 0 {
			lazy[pq.IntSlice[0]]--
			heap.Pop(&pq)
		}
		if pq.Len() > 0 {
			ans[i] = int64(pq.IntSlice[0])
		}
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3093. 最长公共后缀查询](https://leetcode.cn/problems/longest-common-suffix-queries){#3093}

{{< tabs "3093" >}}

{{% tab "python" %}}
```python
class Trie:
    __slots__ = ("children", "length", "idx")

    def __init__(self):
        self.children = [None] * 26
        self.length = inf
        self.idx = inf

    def insert(self, w: str, i: int):
        node = self
        if node.length > len(w):
            node.length = len(w)
            node.idx = i
        for c in w[::-1]:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            if node.length > len(w):
                node.length = len(w)
                node.idx = i

    def query(self, w: str) -> int:
        node = self
        for c in w[::-1]:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                break
            node = node.children[idx]
        return node.idx


class Solution:
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        trie = Trie()
        for i, w in enumerate(wordsContainer):
            trie.insert(w, i)
        return [trie.query(w) for w in wordsQuery]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private final int inf = 1 << 30;
    private Trie[] children = new Trie[26];
    private int length = inf;
    private int idx = inf;

    public void insert(String w, int i) {
        Trie node = this;
        if (node.length > w.length()) {
            node.length = w.length();
            node.idx = i;
        }
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w.charAt(k) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            if (node.length > w.length()) {
                node.length = w.length();
                node.idx = i;
            }
        }
    }

    public int query(String w) {
        Trie node = this;
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w.charAt(k) - 'a';
            if (node.children[idx] == null) {
                break;
            }
            node = node.children[idx];
        }
        return node.idx;
    }
}

class Solution {
    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        Trie trie = new Trie();
        for (int i = 0; i < wordsContainer.length; ++i) {
            trie.insert(wordsContainer[i], i);
        }
        int n = wordsQuery.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = trie.query(wordsQuery[i]);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    const int inf = 1 << 30;
    Trie* children[26];
    int length = inf;
    int idx = inf;

public:
    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    void insert(string w, int i) {
        Trie* node = this;
        if (node->length > w.length()) {
            node->length = w.length();
            node->idx = i;
        }
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w[k] - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            if (node->length > w.length()) {
                node->length = w.length();
                node->idx = i;
            }
        }
    }

    int query(string w) {
        Trie* node = this;
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w[k] - 'a';
            if (node->children[idx] == nullptr) {
                break;
            }
            node = node->children[idx];
        }
        return node->idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* trie = new Trie();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            trie->insert(wordsContainer[i], i);
        }
        int n = wordsQuery.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = trie->query(wordsQuery[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const inf = 1 << 30

type Trie struct {
	children [26]*Trie
	length   int
	idx      int
}

func newTrie() *Trie {
	return &Trie{length: inf, idx: inf}
}

func (t *Trie) insert(w string, i int) {
	node := t
	if node.length > len(w) {
		node.length = len(w)
		node.idx = i
	}
	for k := len(w) - 1; k >= 0; k-- {
		idx := int(w[k] - 'a')
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
		if node.length > len(w) {
			node.length = len(w)
			node.idx = i
		}
	}
}

func (t *Trie) query(w string) int {
	node := t
	for k := len(w) - 1; k >= 0; k-- {
		idx := int(w[k] - 'a')
		if node.children[idx] == nil {
			break
		}
		node = node.children[idx]
	}
	return node.idx
}

func stringIndices(wordsContainer []string, wordsQuery []string) (ans []int) {
	trie := newTrie()
	for i, w := range wordsContainer {
		trie.insert(w, i)
	}
	for _, w := range wordsQuery {
		ans = append(ans, trie.query(w))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Trie {
    private children: Trie[] = new Array<Trie>(26);
    private length: number = Infinity;
    private idx: number = Infinity;

    public insert(w: string, i: number): void {
        let node: Trie = this;
        if (node.length > w.length) {
            node.length = w.length;
            node.idx = i;
        }
        for (let k: number = w.length - 1; k >= 0; --k) {
            let idx: number = w.charCodeAt(k) - 'a'.charCodeAt(0);
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            if (node.length > w.length) {
                node.length = w.length;
                node.idx = i;
            }
        }
    }

    public query(w: string): number {
        let node: Trie = this;
        for (let k: number = w.length - 1; k >= 0; --k) {
            let idx: number = w.charCodeAt(k) - 'a'.charCodeAt(0);
            if (node.children[idx] == null) {
                break;
            }
            node = node.children[idx];
        }
        return node.idx;
    }
}

function stringIndices(wordsContainer: string[], wordsQuery: string[]): number[] {
    const trie: Trie = new Trie();
    for (let i: number = 0; i < wordsContainer.length; ++i) {
        trie.insert(wordsContainer[i], i);
    }
    const n: number = wordsQuery.length;
    const ans: number[] = new Array<number>(n);
    for (let i: number = 0; i < n; ++i) {
        ans[i] = trie.query(wordsQuery[i]);
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

<p>给你两个字符串数组&nbsp;<code>wordsContainer</code> 和&nbsp;<code>wordsQuery</code>&nbsp;。</p>

<p>对于每个&nbsp;<code>wordsQuery[i]</code>&nbsp;，你需要从&nbsp;<code>wordsContainer</code>&nbsp;中找到一个与&nbsp;<code>wordsQuery[i]</code>&nbsp;有&nbsp;<strong>最长公共后缀</strong>&nbsp;的字符串。如果 <code>wordsContainer</code>&nbsp;中有两个或者更多字符串有最长公共后缀，那么答案为长度<strong>&nbsp;最短</strong>&nbsp;的。如果有超过两个字符串有&nbsp;<strong>相同</strong>&nbsp;最短长度，那么答案为它们在&nbsp;<code>wordsContainer</code>&nbsp;中出现&nbsp;<strong>更早</strong>&nbsp;的一个。</p>

<p>请你返回一个整数数组<em>&nbsp;</em><code>ans</code>&nbsp;，其中<em>&nbsp;</em><code>ans[i]</code>是<em>&nbsp;</em><code>wordsContainer</code>中与&nbsp;<code>wordsQuery[i]</code>&nbsp;有&nbsp;<strong>最长公共后缀</strong>&nbsp;字符串的下标。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]</span></p>

<p><span class="example-io"><b>输出：</b>[1,1,1]</span></p>

<p><strong>解释：</strong></p>

<p>我们分别来看每一个&nbsp;<code>wordsQuery[i]</code>&nbsp;：</p>

<ul>
	<li>对于&nbsp;<code>wordsQuery[0] = "cd"</code>&nbsp;，<code>wordsContainer</code>&nbsp;中有最长公共后缀&nbsp;<code>"cd"</code>&nbsp;的字符串下标分别为&nbsp;0 ，1 和&nbsp;2 。这些字符串中，答案是下标为 1 的字符串，因为它的长度为 3 ，是最短的字符串。</li>
	<li>对于&nbsp;<code>wordsQuery[1] = "bcd"</code>&nbsp;，<code>wordsContainer</code>&nbsp;中有最长公共后缀&nbsp;<code>"bcd"</code>&nbsp;的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 1 的字符串，因为它的长度为 3 ，是最短的字符串。</li>
	<li>对于&nbsp;<code>wordsQuery[2] = "xyz"</code>&nbsp;，<code>wordsContainer</code>&nbsp;中没有字符串跟它有公共后缀，所以最长公共后缀为&nbsp;<code>""</code>&nbsp;，下标为&nbsp;0 ，1 和 2 的字符串都得到这一公共后缀。这些字符串中，&nbsp;答案是下标为 1 的字符串，因为它的长度为 3 ，是最短的字符串。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]</span></p>

<p><span class="example-io"><b>输出：</b>[2,0,2]</span></p>

<p><strong>解释：</strong></p>

<p>我们分别来看每一个&nbsp;<code>wordsQuery[i]</code>&nbsp;：</p>

<ul>
	<li>对于&nbsp;<code>wordsQuery[0] = "gh"</code>&nbsp;，<code>wordsContainer</code>&nbsp;中有最长公共后缀&nbsp;<code>"gh"</code>&nbsp;的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 2 的字符串，因为它的长度为 6 ，是最短的字符串。</li>
	<li>对于&nbsp;<code>wordsQuery[1] = "acbfgh"</code>&nbsp;，只有下标为 0 的字符串有最长公共后缀&nbsp;<code>"fgh"</code>&nbsp;。所以尽管下标为 2 的字符串是最短的字符串，但答案是 0 。</li>
	<li>对于&nbsp;<code>wordsQuery[2] = "acbfegh"</code>&nbsp;，<code>wordsContainer</code>&nbsp;中有最长公共后缀&nbsp;<code>"gh"</code>&nbsp;的字符串下标分别为 0 ，1 和 2 。这些字符串中，答案是下标为 2 的字符串，因为它的长度为 6 ，是最短的字符串。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= wordsContainer.length, wordsQuery.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= wordsContainer[i].length &lt;= 5 * 10<sup>3</sup></code></li>
	<li><code>1 &lt;= wordsQuery[i].length &lt;= 5 * 10<sup>3</sup></code></li>
	<li><code>wordsContainer[i]</code>&nbsp;只包含小写英文字母。</li>
	<li><code>wordsQuery[i]</code>&nbsp;只包含小写英文字母。</li>
	<li><code>wordsContainer[i].length</code>&nbsp;的和至多为&nbsp;<code>5 * 10<sup>5</sup></code>&nbsp;。</li>
	<li><code>wordsQuery[i].length</code>&nbsp;的和至多为&nbsp;<code>5 * 10<sup>5</sup></code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字典树

题目需要我们找到最长公共后缀，我们可以考虑使用字典树。

我们定义字典树的节点结构如下：

-   `children`：一个长度为 26 的数组，用于存储子节点。
-   `length`：当前节点的最短字符串长度。
-   `idx`：当前节点的字符串下标。

我们遍历字符串数组 `wordsContainer`，将每个字符串倒序插入字典树中。在插入的过程中，我们更新每个节点的 `length` 和 `idx`。

接下来，我们遍历字符串数组 `wordsQuery`，对于每个字符串，我们从字典树中查找最长公共后缀的字符串下标，在寻找的过程中，如果遇到空节点，说明往后没有公共后缀了，我们可以直接返回当前节点的 `idx`。

时间复杂度 $(L_1 \times |\Sigma| + L_2)$，空间复杂度 $O(L_1 \times |\Sigma|)$，其中 $L_1$ 和 $L_2$ 分别是 `wordsContainer` 和 `wordsQuery` 的字符串长度之和；而 $\Sigma$ 是字符集大小，本题中 $\Sigma = 26$。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    __slots__ = ("children", "length", "idx")

    def __init__(self):
        self.children = [None] * 26
        self.length = inf
        self.idx = inf

    def insert(self, w: str, i: int):
        node = self
        if node.length > len(w):
            node.length = len(w)
            node.idx = i
        for c in w[::-1]:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
            if node.length > len(w):
                node.length = len(w)
                node.idx = i

    def query(self, w: str) -> int:
        node = self
        for c in w[::-1]:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                break
            node = node.children[idx]
        return node.idx


class Solution:
    def stringIndices(
        self, wordsContainer: List[str], wordsQuery: List[str]
    ) -> List[int]:
        trie = Trie()
        for i, w in enumerate(wordsContainer):
            trie.insert(w, i)
        return [trie.query(w) for w in wordsQuery]
```

#### Java

```java
class Trie {
    private final int inf = 1 << 30;
    private Trie[] children = new Trie[26];
    private int length = inf;
    private int idx = inf;

    public void insert(String w, int i) {
        Trie node = this;
        if (node.length > w.length()) {
            node.length = w.length();
            node.idx = i;
        }
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w.charAt(k) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            if (node.length > w.length()) {
                node.length = w.length();
                node.idx = i;
            }
        }
    }

    public int query(String w) {
        Trie node = this;
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w.charAt(k) - 'a';
            if (node.children[idx] == null) {
                break;
            }
            node = node.children[idx];
        }
        return node.idx;
    }
}

class Solution {
    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        Trie trie = new Trie();
        for (int i = 0; i < wordsContainer.length; ++i) {
            trie.insert(wordsContainer[i], i);
        }
        int n = wordsQuery.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = trie.query(wordsQuery[i]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Trie {
private:
    const int inf = 1 << 30;
    Trie* children[26];
    int length = inf;
    int idx = inf;

public:
    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    void insert(string w, int i) {
        Trie* node = this;
        if (node->length > w.length()) {
            node->length = w.length();
            node->idx = i;
        }
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w[k] - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
            if (node->length > w.length()) {
                node->length = w.length();
                node->idx = i;
            }
        }
    }

    int query(string w) {
        Trie* node = this;
        for (int k = w.length() - 1; k >= 0; --k) {
            int idx = w[k] - 'a';
            if (node->children[idx] == nullptr) {
                break;
            }
            node = node->children[idx];
        }
        return node->idx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie* trie = new Trie();
        for (int i = 0; i < wordsContainer.size(); ++i) {
            trie->insert(wordsContainer[i], i);
        }
        int n = wordsQuery.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = trie->query(wordsQuery[i]);
        }
        return ans;
    }
};
```

#### Go

```go
const inf = 1 << 30

type Trie struct {
	children [26]*Trie
	length   int
	idx      int
}

func newTrie() *Trie {
	return &Trie{length: inf, idx: inf}
}

func (t *Trie) insert(w string, i int) {
	node := t
	if node.length > len(w) {
		node.length = len(w)
		node.idx = i
	}
	for k := len(w) - 1; k >= 0; k-- {
		idx := int(w[k] - 'a')
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
		if node.length > len(w) {
			node.length = len(w)
			node.idx = i
		}
	}
}

func (t *Trie) query(w string) int {
	node := t
	for k := len(w) - 1; k >= 0; k-- {
		idx := int(w[k] - 'a')
		if node.children[idx] == nil {
			break
		}
		node = node.children[idx]
	}
	return node.idx
}

func stringIndices(wordsContainer []string, wordsQuery []string) (ans []int) {
	trie := newTrie()
	for i, w := range wordsContainer {
		trie.insert(w, i)
	}
	for _, w := range wordsQuery {
		ans = append(ans, trie.query(w))
	}
	return
}
```

#### TypeScript

```ts
class Trie {
    private children: Trie[] = new Array<Trie>(26);
    private length: number = Infinity;
    private idx: number = Infinity;

    public insert(w: string, i: number): void {
        let node: Trie = this;
        if (node.length > w.length) {
            node.length = w.length;
            node.idx = i;
        }
        for (let k: number = w.length - 1; k >= 0; --k) {
            let idx: number = w.charCodeAt(k) - 'a'.charCodeAt(0);
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
            if (node.length > w.length) {
                node.length = w.length;
                node.idx = i;
            }
        }
    }

    public query(w: string): number {
        let node: Trie = this;
        for (let k: number = w.length - 1; k >= 0; --k) {
            let idx: number = w.charCodeAt(k) - 'a'.charCodeAt(0);
            if (node.children[idx] == null) {
                break;
            }
            node = node.children[idx];
        }
        return node.idx;
    }
}

function stringIndices(wordsContainer: string[], wordsQuery: string[]): number[] {
    const trie: Trie = new Trie();
    for (let i: number = 0; i < wordsContainer.length; ++i) {
        trie.insert(wordsContainer[i], i);
    }
    const n: number = wordsQuery.length;
    const ans: number[] = new Array<number>(n);
    for (let i: number = 0; i < n; ++i) {
        ans[i] = trie.query(wordsQuery[i]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3094. 使用按位查询猜测数字 II 🔒](https://leetcode.cn/problems/guess-the-number-using-bitwise-questions-ii){#3094}

{{< tabs "3094" >}}

{{% tab "python" %}}
```python
# Definition of commonBits API.
# def commonBits(num: int) -> int:


class Solution:
    def findNumber(self) -> int:
        n = 0
        for i in range(32):
            count1 = commonBits(1 << i)
            count2 = commonBits(1 << i)
            if count1 > count2:
                n |= 1 << i
        return n
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition of commonBits API (defined in the parent class Problem).
 * int commonBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            int count1 = commonBits(1 << i);
            int count2 = commonBits(1 << i);
            if (count1 > count2) {
                n |= 1 << i;
            }
        }
        return n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            int count1 = commonBits(1 << i);
            int count2 = commonBits(1 << i);
            if (count1 > count2) {
                n |= 1 << i;
            }
        }
        return n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition of commonBits API.
 * func commonBits(num int) int;
 */

func findNumber() (n int) {
	for i := 0; i < 32; i++ {
		count1 := commonBits(1 << i)
		count2 := commonBits(1 << i)
		if count1 > count2 {
			n |= 1 << i
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

<p>你需要找到一个在 <code>0</code> 和&nbsp;<code>2<sup>30</sup> - 1</code>&nbsp;（均包含）之间的数字 <code>n</code>。</p>

<p>有一个预定义的 API <code>int commonBits(int num)</code>&nbsp;能帮助你完成任务。但挑战是每次你调用这个函数，<code>n</code>&nbsp;都会以某种方式改变。但是记住，你需要找到的是<strong>&nbsp;</strong><code>n</code>&nbsp;的 <strong>初始值</strong>。</p>

<p><code>commonBits(int num)</code> 的操作如下：</p>

<ul>
	<li>计算&nbsp;<code>n</code>&nbsp;和&nbsp;<code>num</code>&nbsp;的二进制表示中值相同的二进制位的位的数量&nbsp;<code>count</code>。</li>
	<li><code>n = n XOR num</code></li>
	<li>返回&nbsp;<code>count</code>。</li>
</ul>

<p>返回数字&nbsp;<code>n</code>。</p>

<p><strong>注意：</strong>在这个世界中，所有数字都在&nbsp;<code>0</code>&nbsp;和&nbsp;<code>2<sup>30</sup> - 1</code>&nbsp;之间（均包含），因此在计算公共二进制位时，我们只看那些数字的前 30 个二进制位。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 2<sup>30</sup> - 1</code></li>
	<li><code>0 &lt;= num &lt;= 2<sup>30</sup> - 1</code></li>
	<li>如果你查询的&nbsp;<code>num</code>&nbsp;超出了给定的范围，输出将会是不可靠的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

根据题目描述，我们观察到：

-   如果我们对同一个数调用两次 `commonBits` 函数，那么 $n$ 的值将不会发生变化。
-   如果我们调用 `commonBits(1 << i)`，那么 $n$ 的第 $i$ 位将会被翻转，即 $n$ 的第 $i$ 位为 $1$ 时，调用后变为 $0$，反之亦然。

因此，对于每一位 $i$，我们可以调用 `commonBits(1 << i)` 两次，分别记为 `count1` 和 `count2`，如果 `count1 > count2`，那么说明 $n$ 的第 $i$ 位为 $1$，否则为 $0$。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition of commonBits API.
# def commonBits(num: int) -> int:


class Solution:
    def findNumber(self) -> int:
        n = 0
        for i in range(32):
            count1 = commonBits(1 << i)
            count2 = commonBits(1 << i)
            if count1 > count2:
                n |= 1 << i
        return n
```

#### Java

```java
/**
 * Definition of commonBits API (defined in the parent class Problem).
 * int commonBits(int num);
 */

public class Solution extends Problem {
    public int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            int count1 = commonBits(1 << i);
            int count2 = commonBits(1 << i);
            if (count1 > count2) {
                n |= 1 << i;
            }
        }
        return n;
    }
}
```

#### C++

```cpp
/**
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int n = 0;
        for (int i = 0; i < 32; ++i) {
            int count1 = commonBits(1 << i);
            int count2 = commonBits(1 << i);
            if (count1 > count2) {
                n |= 1 << i;
            }
        }
        return n;
    }
};
```

#### Go

```go
/**
 * Definition of commonBits API.
 * func commonBits(num int) int;
 */

func findNumber() (n int) {
	for i := 0; i < 32; i++ {
		count1 := commonBits(1 << i)
		count2 := commonBits(1 << i)
		if count1 > count2 {
			n |= 1 << i
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

# [3095. 或值至少 K 的最短子数组 I](https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-i){#3095}

{{< tabs "3095" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = [0] * 32
        ans = n + 1
        s = i = 0
        for j, x in enumerate(nums):
            s |= x
            for h in range(32):
                if x >> h & 1:
                    cnt[h] += 1
            while s >= k and i <= j:
                ans = min(ans, j - i + 1)
                y = nums[i]
                for h in range(32):
                    if y >> h & 1:
                        cnt[h] -= 1
                        if cnt[h] == 0:
                            s ^= 1 << h
                i += 1
        return -1 if ans > n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[32];
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = Math.min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
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
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt[32]{};
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSubarrayLength(nums []int, k int) int {
	n := len(nums)
	cnt := [32]int{}
	ans := n + 1
	s, i := 0, 0
	for j, x := range nums {
		s |= x
		for h := 0; h < 32; h++ {
			if x>>h&1 == 1 {
				cnt[h]++
			}
		}
		for ; s >= k && i <= j; i++ {
			ans = min(ans, j-i+1)
			for h := 0; h < 32; h++ {
				if nums[i]>>h&1 == 1 {
					cnt[h]--
					if cnt[h] == 0 {
						s ^= 1 << h
					}
				}
			}
		}
	}
	if ans == n+1 {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSubarrayLength(nums: number[], k: number): number {
    const n = nums.length;
    let ans = n + 1;
    const cnt: number[] = new Array<number>(32).fill(0);
    for (let i = 0, j = 0, s = 0; j < n; ++j) {
        s |= nums[j];
        for (let h = 0; h < 32; ++h) {
            if (((nums[j] >> h) & 1) === 1) {
                ++cnt[h];
            }
        }
        for (; s >= k && i <= j; ++i) {
            ans = Math.min(ans, j - i + 1);
            for (let h = 0; h < 32; ++h) {
                if (((nums[i] >> h) & 1) === 1 && --cnt[h] === 0) {
                    s ^= 1 << h;
                }
            }
        }
    }
    return ans === n + 1 ? -1 : ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut cnt = vec![0; 32];
        let mut ans = n as i32 + 1;
        let mut s = 0;
        let mut i = 0;

        for (j, &x) in nums.iter().enumerate() {
            s |= x;
            for h in 0..32 {
                if (x >> h) & 1 == 1 {
                    cnt[h] += 1;
                }
            }

            while s >= k && i <= j {
                ans = ans.min((j - i + 1) as i32);
                let y = nums[i];
                for h in 0..32 {
                    if (y >> h) & 1 == 1 {
                        cnt[h] -= 1;
                        if cnt[h] == 0 {
                            s ^= 1 << h;
                        }
                    }
                }
                i += 1;
            }
        }
        if ans > n as i32 { -1 } else { ans }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非负</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个数组中所有元素的按位或运算 <code>OR</code>&nbsp;的值 <strong>至少</strong>&nbsp;为 <code>k</code>&nbsp;，那么我们称这个数组是 <strong>特别的</strong>&nbsp;。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>最短特别非空</strong>&nbsp;<span data-keyword="subarray-nonempty">子数组</span>的长度，如果特别子数组不存在，那么返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[3]</code>&nbsp;的按位&nbsp;<code>OR</code> 值为&nbsp;<code>3</code>&nbsp;，所以我们返回 <code>1</code>&nbsp;。</p>

<p>注意，<code>[2]</code> 也是一个特别子数组。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,8], k = 10</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[2,1,8]</code> 的按位&nbsp;<code>OR</code>&nbsp;值为 <code>11</code>&nbsp;，所以我们返回 <code>3</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>子数组&nbsp;<code>[1]</code>&nbsp;的按位&nbsp;<code>OR</code>&nbsp;值为&nbsp;<code>1</code>&nbsp;，所以我们返回&nbsp;<code>1</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= k &lt; 64</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 计数

我们可以发现，如果我们固定子数组的左端点，随着右端点向右移动，子数组的按位或值只会增大，不会减小。因此我们可以使用双指针的方法，维护一个满足条件的子数组。

具体地，我们使用两个指针 $i$ 和 $j$ 分别表示子数组的左右端点，初始时两个指针都位于数组的第一个元素。用一个变量 $s$ 表示子数组的按位或值，初始时 $s$ 的值为 $0$。我们还需要维护一个长度为 $32$ 的数组 $cnt$，表示子数组中每个元素的二进制表示中每一位的出现次数。

在每一步操作中，我们将 $j$ 向右移动一位，更新 $s$ 和 $cnt$。如果 $s$ 的值大于等于 $k$，我们不断更新子数组的最小长度，并将 $i$ 向右移动一位，直到 $s$ 的值小于 $k$。在这个过程中，我们也需要更新 $s$ 和 $cnt$。

最后，我们返回最小长度，如果不存在满足条件的子数组，则返回 $-1$。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$，其中 $n$ 和 $M$ 分别是数组的长度和数组中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = [0] * 32
        ans = n + 1
        s = i = 0
        for j, x in enumerate(nums):
            s |= x
            for h in range(32):
                if x >> h & 1:
                    cnt[h] += 1
            while s >= k and i <= j:
                ans = min(ans, j - i + 1)
                y = nums[i]
                for h in range(32):
                    if y >> h & 1:
                        cnt[h] -= 1
                        if cnt[h] == 0:
                            s ^= 1 << h
                i += 1
        return -1 if ans > n else ans
```

#### Java

```java
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[32];
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = Math.min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt[32]{};
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func minimumSubarrayLength(nums []int, k int) int {
	n := len(nums)
	cnt := [32]int{}
	ans := n + 1
	s, i := 0, 0
	for j, x := range nums {
		s |= x
		for h := 0; h < 32; h++ {
			if x>>h&1 == 1 {
				cnt[h]++
			}
		}
		for ; s >= k && i <= j; i++ {
			ans = min(ans, j-i+1)
			for h := 0; h < 32; h++ {
				if nums[i]>>h&1 == 1 {
					cnt[h]--
					if cnt[h] == 0 {
						s ^= 1 << h
					}
				}
			}
		}
	}
	if ans == n+1 {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumSubarrayLength(nums: number[], k: number): number {
    const n = nums.length;
    let ans = n + 1;
    const cnt: number[] = new Array<number>(32).fill(0);
    for (let i = 0, j = 0, s = 0; j < n; ++j) {
        s |= nums[j];
        for (let h = 0; h < 32; ++h) {
            if (((nums[j] >> h) & 1) === 1) {
                ++cnt[h];
            }
        }
        for (; s >= k && i <= j; ++i) {
            ans = Math.min(ans, j - i + 1);
            for (let h = 0; h < 32; ++h) {
                if (((nums[i] >> h) & 1) === 1 && --cnt[h] === 0) {
                    s ^= 1 << h;
                }
            }
        }
    }
    return ans === n + 1 ? -1 : ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut cnt = vec![0; 32];
        let mut ans = n as i32 + 1;
        let mut s = 0;
        let mut i = 0;

        for (j, &x) in nums.iter().enumerate() {
            s |= x;
            for h in 0..32 {
                if (x >> h) & 1 == 1 {
                    cnt[h] += 1;
                }
            }

            while s >= k && i <= j {
                ans = ans.min((j - i + 1) as i32);
                let y = nums[i];
                for h in 0..32 {
                    if (y >> h) & 1 == 1 {
                        cnt[h] -= 1;
                        if cnt[h] == 0 {
                            s ^= 1 << h;
                        }
                    }
                }
                i += 1;
            }
        }
        if ans > n as i32 { -1 } else { ans }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3096. 得到更多分数的最少关卡数目](https://leetcode.cn/problems/minimum-levels-to-gain-more-points){#3096}

{{< tabs "3096" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        s = sum(-1 if x == 0 else 1 for x in possible)
        t = 0
        for i, x in enumerate(possible[:-1], 1):
            t += -1 if x == 0 else 1
            if t > s - t:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumLevels(int[] possible) {
        int s = 0;
        for (int x : possible) {
            s += x == 0 ? -1 : 1;
        }
        int t = 0;
        for (int i = 1; i < possible.length; ++i) {
            t += possible[i - 1] == 0 ? -1 : 1;
            if (t > s - t) {
                return i;
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
    int minimumLevels(vector<int>& possible) {
        int s = 0;
        for (int x : possible) {
            s += x == 0 ? -1 : 1;
        }
        int t = 0;
        for (int i = 1; i < possible.size(); ++i) {
            t += possible[i - 1] == 0 ? -1 : 1;
            if (t > s - t) {
                return i;
            }
        }
        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumLevels(possible []int) int {
	s := 0
	for _, x := range possible {
		if x == 0 {
			x = -1
		}
		s += x
	}
	t := 0
	for i, x := range possible[:len(possible)-1] {
		if x == 0 {
			x = -1
		}
		t += x
		if t > s-t {
			return i + 1
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumLevels(possible: number[]): number {
    const s = possible.reduce((acc, x) => acc + (x === 0 ? -1 : 1), 0);
    let t = 0;
    for (let i = 1; i < possible.length; ++i) {
        t += possible[i - 1] === 0 ? -1 : 1;
        if (t > s - t) {
            return i;
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

<p>给你一个长度为 <code>n</code>&nbsp;的二进制数组&nbsp;<code>possible</code>&nbsp;。</p>

<p>Alice 和 Bob 正在玩一个有 <code>n</code> 个关卡的游戏，游戏中有一些关卡是 <strong>困难</strong>&nbsp;模式，其他的关卡是 <strong>简单</strong>&nbsp;模式。如果&nbsp;<code>possible[i] == 0</code>&nbsp;，那么第&nbsp;<code>i</code> 个关卡是 <strong>困难</strong>&nbsp;模式，两个玩家&nbsp;<strong>都不可能</strong> 通过。一个玩家通过一个简单模式的关卡可以获得 <code>1</code>&nbsp;分，遇到困难模式的关卡将失去 <code>1</code>&nbsp;分。</p>

<p>游戏的一开始，Alice 将从第 <code>0</code>&nbsp;级开始 <strong>按顺序</strong> 完成一些关卡，然后 Bob 会完成剩下的所有关卡。</p>

<p>假设两名玩家都采取最优策略，目的是&nbsp;<strong>最大化</strong>&nbsp;自己的得分，Alice 想知道自己&nbsp;<strong>最少</strong> 需要完成多少个关卡，才能获得比 Bob 更多的分数。</p>

<p>请你返回 Alice 获得比 Bob 更多的分数所需要完成的 <strong>最少</strong> 关卡数目，如果 <strong>无法</strong>&nbsp;达成，那么返回 <code>-1</code>&nbsp;。</p>

<p><strong>注意</strong>，每个玩家都至少需要完成&nbsp;<code>1</code> 个关卡。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>possible = [1,0,1,0]</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>我们来看一下 Alice 可以完成的关卡数目：</p>

<ul>
	<li>如果 Alice 只完成关卡 0 ，Bob 完成剩下的所有关卡，那么 Alice 获得 1 分，Bob 获得 -1 + 1 - 1 = -1 分。</li>
	<li>如果 Alice 完成到关卡 1 ，Bob 完成剩下的所有关卡，那么 Alice 获得&nbsp;1 - 1 = 0 分，Bob 获得 1 - 1 = 0 分。</li>
	<li>如果 Alice 完成到关卡 2 ，Bob 完成剩下的所有关卡，那么 Alice 获得&nbsp;1 - 1 + 1 = 1 分，Bob 获得 -1 分。</li>
</ul>

<p>Alice 需要完成至少一个关卡获得更多的分数。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>possible = [1,1,1,1,1]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>我们来看一下 Alice 可以完成的关卡数目：</p>

<ul>
	<li>如果 Alice 只完成关卡 0 ，Bob 完成剩下的所有关卡，那么 Alice 获得 1 分，Bob 获得 4 分。</li>
	<li>如果 Alice 完成到关卡 1 ，Bob 完成剩下的所有关卡，那么 Alice 获得&nbsp;2 分，Bob 获得 3 分。</li>
	<li>如果 Alice 完成到关卡 2 ，Bob 完成剩下的所有关卡，那么 Alice 获得&nbsp;3 分，Bob 获得 2&nbsp;分。</li>
	<li>如果 Alice 完成到关卡 3&nbsp;，Bob 完成剩下的所有关卡，那么 Alice 获得 4&nbsp;分，Bob 获得 1&nbsp;分。</li>
</ul>

<p>Alice 需要完成至少三个关卡获得更多的分数。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>possible = [0,0]</span></p>

<p><span class="example-io"><b>输出：</b>-1</span></p>

<p><strong>解释：</strong></p>

<p>两名玩家只能各完成 1 个关卡，Alice 完成关卡 0 得到 -1 分，Bob 完成关卡 1 得到 -1 分。两名玩家得分相同，所以 Alice 无法得到更多分数。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == possible.length &lt;= 10<sup>5</sup></code></li>
	<li><code>possible[i]</code>&nbsp;要么是&nbsp;<code>0</code>&nbsp;要么是&nbsp;<code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们先计算得到两个玩家能得到的分数和，记为 $s$。

然后我们从小到大枚举玩家 $1$ 能完成的关卡数目 $i$，计算玩家 $1$ 得到的分数和 $t$，如果 $t > s - t$，那么玩家 $1$ 需要完成的关卡数目就是 $i$。

如果枚举完前 $n - 1$ 个关卡都没有找到满足条件的 $i$，那么就返回 $-1$。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        s = sum(-1 if x == 0 else 1 for x in possible)
        t = 0
        for i, x in enumerate(possible[:-1], 1):
            t += -1 if x == 0 else 1
            if t > s - t:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int minimumLevels(int[] possible) {
        int s = 0;
        for (int x : possible) {
            s += x == 0 ? -1 : 1;
        }
        int t = 0;
        for (int i = 1; i < possible.length; ++i) {
            t += possible[i - 1] == 0 ? -1 : 1;
            if (t > s - t) {
                return i;
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
    int minimumLevels(vector<int>& possible) {
        int s = 0;
        for (int x : possible) {
            s += x == 0 ? -1 : 1;
        }
        int t = 0;
        for (int i = 1; i < possible.size(); ++i) {
            t += possible[i - 1] == 0 ? -1 : 1;
            if (t > s - t) {
                return i;
            }
        }
        return -1;
    }
};
```

#### Go

```go
func minimumLevels(possible []int) int {
	s := 0
	for _, x := range possible {
		if x == 0 {
			x = -1
		}
		s += x
	}
	t := 0
	for i, x := range possible[:len(possible)-1] {
		if x == 0 {
			x = -1
		}
		t += x
		if t > s-t {
			return i + 1
		}
	}
	return -1
}
```

#### TypeScript

```ts
function minimumLevels(possible: number[]): number {
    const s = possible.reduce((acc, x) => acc + (x === 0 ? -1 : 1), 0);
    let t = 0;
    for (let i = 1; i < possible.length; ++i) {
        t += possible[i - 1] === 0 ? -1 : 1;
        if (t > s - t) {
            return i;
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

# [3097. 或值至少为 K 的最短子数组 II](https://leetcode.cn/problems/shortest-subarray-with-or-at-least-k-ii){#3097}

{{< tabs "3097" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = [0] * 32
        ans = n + 1
        s = i = 0
        for j, x in enumerate(nums):
            s |= x
            for h in range(32):
                if x >> h & 1:
                    cnt[h] += 1
            while s >= k and i <= j:
                ans = min(ans, j - i + 1)
                y = nums[i]
                for h in range(32):
                    if y >> h & 1:
                        cnt[h] -= 1
                        if cnt[h] == 0:
                            s ^= 1 << h
                i += 1
        return -1 if ans > n else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[32];
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = Math.min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
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
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt[32]{};
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumSubarrayLength(nums []int, k int) int {
	n := len(nums)
	cnt := [32]int{}
	ans := n + 1
	s, i := 0, 0
	for j, x := range nums {
		s |= x
		for h := 0; h < 32; h++ {
			if x>>h&1 == 1 {
				cnt[h]++
			}
		}
		for ; s >= k && i <= j; i++ {
			ans = min(ans, j-i+1)
			for h := 0; h < 32; h++ {
				if nums[i]>>h&1 == 1 {
					cnt[h]--
					if cnt[h] == 0 {
						s ^= 1 << h
					}
				}
			}
		}
	}
	if ans == n+1 {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumSubarrayLength(nums: number[], k: number): number {
    const n = nums.length;
    let ans = n + 1;
    const cnt: number[] = new Array<number>(32).fill(0);
    for (let i = 0, j = 0, s = 0; j < n; ++j) {
        s |= nums[j];
        for (let h = 0; h < 32; ++h) {
            if (((nums[j] >> h) & 1) === 1) {
                ++cnt[h];
            }
        }
        for (; s >= k && i <= j; ++i) {
            ans = Math.min(ans, j - i + 1);
            for (let h = 0; h < 32; ++h) {
                if (((nums[i] >> h) & 1) === 1 && --cnt[h] === 0) {
                    s ^= 1 << h;
                }
            }
        }
    }
    return ans === n + 1 ? -1 : ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut cnt = vec![0; 32];
        let mut ans = n as i32 + 1;
        let mut s = 0;
        let mut i = 0;

        for (j, &x) in nums.iter().enumerate() {
            s |= x;
            for h in 0..32 {
                if (x >> h) & 1 == 1 {
                    cnt[h] += 1;
                }
            }

            while s >= k && i <= j {
                ans = ans.min((j - i + 1) as i32);
                let y = nums[i];
                for h in 0..32 {
                    if (y >> h) & 1 == 1 {
                        cnt[h] -= 1;
                        if cnt[h] == 0 {
                            s ^= 1 << h;
                        }
                    }
                }
                i += 1;
            }
        }
        if ans > n as i32 { -1 } else { ans }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非负</strong>&nbsp;整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>如果一个数组中所有元素的按位或运算 <code>OR</code>&nbsp;的值 <strong>至少</strong>&nbsp;为 <code>k</code>&nbsp;，那么我们称这个数组是 <strong>特别的</strong>&nbsp;。</p>

<p>请你返回&nbsp;<code>nums</code>&nbsp;中&nbsp;<strong>最短特别非空</strong>&nbsp;<span data-keyword="subarray-nonempty">子数组</span>的长度，如果特别子数组不存在，那么返回 <code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[3]</code>&nbsp;的按位&nbsp;<code>OR</code> 值为&nbsp;<code>3</code>&nbsp;，所以我们返回 <code>1</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,1,8], k = 10</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p>子数组&nbsp;<code>[2,1,8]</code> 的按位&nbsp;<code>OR</code>&nbsp;值为 <code>11</code>&nbsp;，所以我们返回 <code>3</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2], k = 0</span></p>

<p><span class="example-io"><b>输出：</b>1</span></p>

<p><b>解释：</b></p>

<p>子数组&nbsp;<code>[1]</code>&nbsp;的按位&nbsp;<code>OR</code>&nbsp;值为&nbsp;<code>1</code>&nbsp;，所以我们返回&nbsp;<code>1</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup><font size="1">9</font></sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针 + 计数

我们可以发现，如果我们固定子数组的左端点，随着右端点向右移动，子数组的按位或值只会增大，不会减小。因此我们可以使用双指针的方法，维护一个满足条件的子数组。

具体地，我们使用两个指针 $i$ 和 $j$ 分别表示子数组的左右端点，初始时两个指针都位于数组的第一个元素。用一个变量 $s$ 表示子数组的按位或值，初始时 $s$ 的值为 $0$。我们还需要维护一个长度为 $32$ 的数组 $cnt$，表示子数组中每个元素的二进制表示中每一位的出现次数。

在每一步操作中，我们将 $j$ 向右移动一位，更新 $s$ 和 $cnt$。如果 $s$ 的值大于等于 $k$，我们不断更新子数组的最小长度，并将 $i$ 向右移动一位，直到 $s$ 的值小于 $k$。在这个过程中，我们也需要更新 $s$ 和 $cnt$。

最后，我们返回最小长度，如果不存在满足条件的子数组，则返回 $-1$。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(\log M)$，其中 $n$ 和 $M$ 分别是数组的长度和数组中元素的最大值。

相似题目：

-   [3171. 找到按位与最接近 K 的子数组](https://github.com/doocs/leetcode/blob/main/solution/3100-3199/3171.Find%20Subarray%20With%20Bitwise%20AND%20Closest%20to%20K/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cnt = [0] * 32
        ans = n + 1
        s = i = 0
        for j, x in enumerate(nums):
            s |= x
            for h in range(32):
                if x >> h & 1:
                    cnt[h] += 1
            while s >= k and i <= j:
                ans = min(ans, j - i + 1)
                y = nums[i]
                for h in range(32):
                    if y >> h & 1:
                        cnt[h] -= 1
                        if cnt[h] == 0:
                            s ^= 1 << h
                i += 1
        return -1 if ans > n else ans
```

#### Java

```java
class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        int[] cnt = new int[32];
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = Math.min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt[32]{};
        int ans = n + 1;
        for (int i = 0, j = 0, s = 0; j < n; ++j) {
            s |= nums[j];
            for (int h = 0; h < 32; ++h) {
                if ((nums[j] >> h & 1) == 1) {
                    ++cnt[h];
                }
            }
            for (; s >= k && i <= j; ++i) {
                ans = min(ans, j - i + 1);
                for (int h = 0; h < 32; ++h) {
                    if ((nums[i] >> h & 1) == 1) {
                        if (--cnt[h] == 0) {
                            s ^= 1 << h;
                        }
                    }
                }
            }
        }
        return ans > n ? -1 : ans;
    }
};
```

#### Go

```go
func minimumSubarrayLength(nums []int, k int) int {
	n := len(nums)
	cnt := [32]int{}
	ans := n + 1
	s, i := 0, 0
	for j, x := range nums {
		s |= x
		for h := 0; h < 32; h++ {
			if x>>h&1 == 1 {
				cnt[h]++
			}
		}
		for ; s >= k && i <= j; i++ {
			ans = min(ans, j-i+1)
			for h := 0; h < 32; h++ {
				if nums[i]>>h&1 == 1 {
					cnt[h]--
					if cnt[h] == 0 {
						s ^= 1 << h
					}
				}
			}
		}
	}
	if ans == n+1 {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minimumSubarrayLength(nums: number[], k: number): number {
    const n = nums.length;
    let ans = n + 1;
    const cnt: number[] = new Array<number>(32).fill(0);
    for (let i = 0, j = 0, s = 0; j < n; ++j) {
        s |= nums[j];
        for (let h = 0; h < 32; ++h) {
            if (((nums[j] >> h) & 1) === 1) {
                ++cnt[h];
            }
        }
        for (; s >= k && i <= j; ++i) {
            ans = Math.min(ans, j - i + 1);
            for (let h = 0; h < 32; ++h) {
                if (((nums[i] >> h) & 1) === 1 && --cnt[h] === 0) {
                    s ^= 1 << h;
                }
            }
        }
    }
    return ans === n + 1 ? -1 : ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut cnt = vec![0; 32];
        let mut ans = n as i32 + 1;
        let mut s = 0;
        let mut i = 0;

        for (j, &x) in nums.iter().enumerate() {
            s |= x;
            for h in 0..32 {
                if (x >> h) & 1 == 1 {
                    cnt[h] += 1;
                }
            }

            while s >= k && i <= j {
                ans = ans.min((j - i + 1) as i32);
                let y = nums[i];
                for h in 0..32 {
                    if (y >> h) & 1 == 1 {
                        cnt[h] -= 1;
                        if cnt[h] == 0 {
                            s ^= 1 << h;
                        }
                    }
                }
                i += 1;
            }
        }
        if ans > n as i32 { -1 } else { ans }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3098. 求出所有子序列的能量和](https://leetcode.cn/problems/find-the-sum-of-subsequence-powers){#3098}

{{< tabs "3098" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        @cache
        def dfs(i: int, j: int, k: int, mi: int) -> int:
            if i >= n:
                return mi if k == 0 else 0
            if n - i < k:
                return 0
            ans = dfs(i + 1, j, k, mi)
            if j == n:
                ans += dfs(i + 1, i, k - 1, mi)
            else:
                ans += dfs(i + 1, i, k - 1, min(mi, nums[i] - nums[j]))
            ans %= mod
            return ans

        mod = 10**9 + 7
        n = len(nums)
        nums.sort()
        return dfs(0, n, k, inf)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private final int mod = (int) 1e9 + 7;
    private int[] nums;

    public int sumOfPowers(int[] nums, int k) {
        Arrays.sort(nums);
        this.nums = nums;
        return dfs(0, nums.length, k, Integer.MAX_VALUE);
    }

    private int dfs(int i, int j, int k, int mi) {
        if (i >= nums.length) {
            return k == 0 ? mi : 0;
        }
        if (nums.length - i < k) {
            return 0;
        }
        long key = (1L * mi) << 18 | (i << 12) | (j << 6) | k;
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int ans = dfs(i + 1, j, k, mi);
        if (j == nums.length) {
            ans += dfs(i + 1, i, k - 1, mi);
        } else {
            ans += dfs(i + 1, i, k - 1, Math.min(mi, nums[i] - nums[j]));
        }
        ans %= mod;
        f.put(key, ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        unordered_map<long long, int> f;
        const int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto dfs = [&](this auto&& dfs, int i, int j, int k, int mi) -> int {
            if (i >= n) {
                return k == 0 ? mi : 0;
            }
            if (n - i < k) {
                return 0;
            }
            long long key = (1LL * mi) << 18 | (i << 12) | (j << 6) | k;
            if (f.contains(key)) {
                return f[key];
            }
            long long ans = dfs(i + 1, j, k, mi);
            if (j == n) {
                ans += dfs(i + 1, i, k - 1, mi);
            } else {
                ans += dfs(i + 1, i, k - 1, min(mi, nums[i] - nums[j]));
            }
            ans %= mod;
            f[key] = ans;
            return f[key];
        };
        return dfs(0, n, k, INT_MAX);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfPowers(nums []int, k int) int {
	const mod int = 1e9 + 7
	sort.Ints(nums)
	n := len(nums)
	f := map[int]int{}
	var dfs func(i, j, k, mi int) int
	dfs = func(i, j, k, mi int) int {
		if i >= n {
			if k == 0 {
				return mi
			}
			return 0
		}
		if n-i < k {
			return 0
		}
		key := mi<<18 | (i << 12) | (j << 6) | k
		if v, ok := f[key]; ok {
			return v
		}
		ans := dfs(i+1, j, k, mi)
		if j == n {
			ans += dfs(i+1, i, k-1, mi)
		} else {
			ans += dfs(i+1, i, k-1, min(mi, nums[i]-nums[j]))
		}
		ans %= mod
		f[key] = ans
		return ans
	}
	return dfs(0, n, k, math.MaxInt)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfPowers(nums: number[], k: number): number {
    const mod = BigInt(1e9 + 7);
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: Map<bigint, bigint> = new Map();
    function dfs(i: number, j: number, k: number, mi: number): bigint {
        if (i >= n) {
            if (k === 0) {
                return BigInt(mi);
            }
            return BigInt(0);
        }
        if (n - i < k) {
            return BigInt(0);
        }
        const key =
            (BigInt(mi) << BigInt(18)) |
            (BigInt(i) << BigInt(12)) |
            (BigInt(j) << BigInt(6)) |
            BigInt(k);
        if (f.has(key)) {
            return f.get(key)!;
        }
        let ans = dfs(i + 1, j, k, mi);
        if (j === n) {
            ans += dfs(i + 1, i, k - 1, mi);
        } else {
            ans += dfs(i + 1, i, k - 1, Math.min(mi, nums[i] - nums[j]));
        }
        ans %= mod;
        f.set(key, ans);
        return ans;
    }

    return Number(dfs(0, n, k, Number.MAX_SAFE_INTEGER));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一个 <span data-keyword="subsequence-array">子序列</span> 的 <strong>能量</strong>&nbsp;定义为子序列中&nbsp;<strong>任意</strong>&nbsp;两个元素的差值绝对值的 <strong>最小值</strong>&nbsp;。</p>

<p>请你返回 <code>nums</code>&nbsp;中长度 <strong>等于</strong>&nbsp;<code>k</code>&nbsp;的 <strong>所有</strong>&nbsp;子序列的 <strong>能量和</strong>&nbsp;。</p>

<p>由于答案可能会很大，将答案对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4], k = 3</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中总共有 4 个长度为 3 的子序列：<code>[1,2,3]</code>&nbsp;，<code>[1,3,4]</code>&nbsp;，<code>[1,2,4]</code>&nbsp;和&nbsp;<code>[2,3,4]</code>&nbsp;。能量和为 <code>|2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,2], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;中唯一一个长度为 2 的子序列是&nbsp;<code>[2,2]</code>&nbsp;。能量和为&nbsp;<code>|2 - 2| = 0</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [4,3,-1], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>10</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code>&nbsp;总共有 3 个长度为 2 的子序列：<code>[4,3]</code>&nbsp;，<code>[4,-1]</code>&nbsp;和&nbsp;<code>[3,-1]</code>&nbsp;。能量和为&nbsp;<code>|4 - 3| + |4 - (-1)| + |3 - (-1)| = 10</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 50</code></li>
	<li><code>-10<sup>8</sup> &lt;= nums[i] &lt;= 10<sup>8</sup> </code></li>
	<li><code>2 &lt;= k &lt;= n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

由于题目涉及子序列元素的最小差值，我们不妨对数组 $\textit{nums}$ 进行排序，这样可以方便我们计算子序列元素的最小差值。

接下来，我们设计一个函数 $dfs(i, j, k, mi)$，表示当前处理到第 $i$ 个元素，上一个选取的是第 $j$ 个元素，还需要选取 $k$ 个元素，当前的最小差值为 $mi$ 时，能量和的值。那么答案就是 $dfs(0, n, k, +\infty)$。（若上一个选取的是第 $n$ 个元素，表示之前没有选取过元素）

函数 $dfs(i, j, k, mi)$ 的执行过程如下：

-   如果 $i \geq n$，表示已经处理完了所有的元素，如果 $k = 0$，返回 $mi$，否则返回 $0$；
-   如果剩余的元素个数 $n - i$ 不足 $k$ 个，返回 $0$；
-   否则，我们可以选择不选取第 $i$ 个元素，可以获得的能量和为 $dfs(i + 1, j, k, mi)$；
-   也可以选择选取第 $i$ 个元素。如果 $j = n$，表示之前没有选取过元素，那么可以获得的能量和为 $dfs(i + 1, i, k - 1, mi)$；否则，可以获得的能量和为 $dfs(i + 1, i, k - 1, \min(mi, \textit{nums}[i] - \textit{nums}[j]))$。
-   我们累加上述结果，并对 $10^9 + 7$ 取模后返回。

为了避免重复计算，我们可以使用记忆化搜索的方法，将已经计算过的结果保存起来。

时间复杂度 $O(n^4 \times k)$，空间复杂度 $O(n^4 \times k)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        @cache
        def dfs(i: int, j: int, k: int, mi: int) -> int:
            if i >= n:
                return mi if k == 0 else 0
            if n - i < k:
                return 0
            ans = dfs(i + 1, j, k, mi)
            if j == n:
                ans += dfs(i + 1, i, k - 1, mi)
            else:
                ans += dfs(i + 1, i, k - 1, min(mi, nums[i] - nums[j]))
            ans %= mod
            return ans

        mod = 10**9 + 7
        n = len(nums)
        nums.sort()
        return dfs(0, n, k, inf)
```

#### Java

```java
class Solution {
    private Map<Long, Integer> f = new HashMap<>();
    private final int mod = (int) 1e9 + 7;
    private int[] nums;

    public int sumOfPowers(int[] nums, int k) {
        Arrays.sort(nums);
        this.nums = nums;
        return dfs(0, nums.length, k, Integer.MAX_VALUE);
    }

    private int dfs(int i, int j, int k, int mi) {
        if (i >= nums.length) {
            return k == 0 ? mi : 0;
        }
        if (nums.length - i < k) {
            return 0;
        }
        long key = (1L * mi) << 18 | (i << 12) | (j << 6) | k;
        if (f.containsKey(key)) {
            return f.get(key);
        }
        int ans = dfs(i + 1, j, k, mi);
        if (j == nums.length) {
            ans += dfs(i + 1, i, k - 1, mi);
        } else {
            ans += dfs(i + 1, i, k - 1, Math.min(mi, nums[i] - nums[j]));
        }
        ans %= mod;
        f.put(key, ans);
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        unordered_map<long long, int> f;
        const int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        auto dfs = [&](this auto&& dfs, int i, int j, int k, int mi) -> int {
            if (i >= n) {
                return k == 0 ? mi : 0;
            }
            if (n - i < k) {
                return 0;
            }
            long long key = (1LL * mi) << 18 | (i << 12) | (j << 6) | k;
            if (f.contains(key)) {
                return f[key];
            }
            long long ans = dfs(i + 1, j, k, mi);
            if (j == n) {
                ans += dfs(i + 1, i, k - 1, mi);
            } else {
                ans += dfs(i + 1, i, k - 1, min(mi, nums[i] - nums[j]));
            }
            ans %= mod;
            f[key] = ans;
            return f[key];
        };
        return dfs(0, n, k, INT_MAX);
    }
};
```

#### Go

```go
func sumOfPowers(nums []int, k int) int {
	const mod int = 1e9 + 7
	sort.Ints(nums)
	n := len(nums)
	f := map[int]int{}
	var dfs func(i, j, k, mi int) int
	dfs = func(i, j, k, mi int) int {
		if i >= n {
			if k == 0 {
				return mi
			}
			return 0
		}
		if n-i < k {
			return 0
		}
		key := mi<<18 | (i << 12) | (j << 6) | k
		if v, ok := f[key]; ok {
			return v
		}
		ans := dfs(i+1, j, k, mi)
		if j == n {
			ans += dfs(i+1, i, k-1, mi)
		} else {
			ans += dfs(i+1, i, k-1, min(mi, nums[i]-nums[j]))
		}
		ans %= mod
		f[key] = ans
		return ans
	}
	return dfs(0, n, k, math.MaxInt)
}
```

#### TypeScript

```ts
function sumOfPowers(nums: number[], k: number): number {
    const mod = BigInt(1e9 + 7);
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const f: Map<bigint, bigint> = new Map();
    function dfs(i: number, j: number, k: number, mi: number): bigint {
        if (i >= n) {
            if (k === 0) {
                return BigInt(mi);
            }
            return BigInt(0);
        }
        if (n - i < k) {
            return BigInt(0);
        }
        const key =
            (BigInt(mi) << BigInt(18)) |
            (BigInt(i) << BigInt(12)) |
            (BigInt(j) << BigInt(6)) |
            BigInt(k);
        if (f.has(key)) {
            return f.get(key)!;
        }
        let ans = dfs(i + 1, j, k, mi);
        if (j === n) {
            ans += dfs(i + 1, i, k - 1, mi);
        } else {
            ans += dfs(i + 1, i, k - 1, Math.min(mi, nums[i] - nums[j]));
        }
        ans %= mod;
        f.set(key, ans);
        return ans;
    }

    return Number(dfs(0, n, k, Number.MAX_SAFE_INTEGER));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3099. 哈沙德数](https://leetcode.cn/problems/harshad-number){#3099}

{{< tabs "3099" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s, y = 0, x
        while y:
            s += y % 10
            y //= 10
        return s if x % s == 0 else -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfTheDigitsOfHarshadNumber(x int) int {
	s := 0
	for y := x; y > 0; y /= 10 {
		s += y % 10
	}
	if x%s == 0 {
		return s
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfTheDigitsOfHarshadNumber(x: number): number {
    let s = 0;
    for (let y = x; y; y = Math.floor(y / 10)) {
        s += y % 10;
    }
    return x % s === 0 ? s : -1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果一个整数能够被其各个数位上的数字之和整除，则称之为<strong> 哈沙德数</strong>（Harshad number）。给你一个整数 <code>x</code> 。如果 <code>x</code> 是 <strong>哈沙德数 </strong>，则返回<em> </em><code>x</code> 各个数位上的数字之和，否则，返回<em> </em><code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 18</span></p>

<p><strong>输出：</strong> <span class="example-io">9</span></p>

<p><strong>解释：</strong></p>

<p><code>x</code> 各个数位上的数字之和为 <code>9</code> 。<code>18</code> 能被 <code>9</code> 整除。因此 <code>18</code> 是哈沙德数，答案是 <code>9</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">x = 23</span></p>

<p><strong>输出：</strong> <span class="example-io">-1</span></p>

<p><strong>解释：</strong></p>

<p><code>x</code> 各个数位上的数字之和为 <code>5</code> 。<code>23</code> 不能被 <code>5</code> 整除。因此 <code>23</code> 不是哈沙德数，答案是 <code>-1</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= x &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以通过模拟的方法，计算出 $x$ 的各个数位上的数字之和，记为 $s$。如果 $x$ 能被 $s$ 整除，则返回 $s$，否则返回 $-1$。

时间复杂度 $O(\log x)$，其中 $x$ 是输入的整数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
        s, y = 0, x
        while y:
            s += y % 10
            y //= 10
        return s if x % s == 0 else -1
```

#### Java

```java
class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int s = 0;
        for (int y = x; y > 0; y /= 10) {
            s += y % 10;
        }
        return x % s == 0 ? s : -1;
    }
};
```

#### Go

```go
func sumOfTheDigitsOfHarshadNumber(x int) int {
	s := 0
	for y := x; y > 0; y /= 10 {
		s += y % 10
	}
	if x%s == 0 {
		return s
	}
	return -1
}
```

#### TypeScript

```ts
function sumOfTheDigitsOfHarshadNumber(x: number): number {
    let s = 0;
    for (let y = x; y; y = Math.floor(y / 10)) {
        s += y % 10;
    }
    return x % s === 0 ? s : -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
