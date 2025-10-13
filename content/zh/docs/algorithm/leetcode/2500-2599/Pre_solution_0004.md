---
title: "2530_执行 K 次操作后的最大分数"
date: 2025-10-08T18:39:23+08:00
weight: 4
tags: [前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 数学, 数组, 树, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 组合数学, 计数, 贪心, 队列]
---

{{< markmap >}}
### [2530_执行 K 次操作后的最大分数](#2530)
#### [贪心](#2530)
#### [数组](#2530)
#### [堆（优先队列）](#2530)
### [2531_使字符串中不同字符的数目相等](#2531)
#### [哈希表](#2531)
#### [字符串](#2531)
#### [计数](#2531)
### [2532_过桥的时间](#2532)
#### [数组](#2532)
#### [模拟](#2532)
#### [堆（优先队列）](#2532)
### [2533_好二进制字符串的数量 🔒](#2533)
#### [动态规划](#2533)
### [2534_通过门的时间 🔒](#2534)
#### [队列](#2534)
#### [数组](#2534)
#### [模拟](#2534)
### [2535_数组元素和与数字和的绝对差](#2535)
#### [数组](#2535)
#### [数学](#2535)
### [2536_子矩阵元素加 1](#2536)
#### [数组](#2536)
#### [矩阵](#2536)
#### [前缀和](#2536)
### [2537_统计好子数组的数目](#2537)
#### [数组](#2537)
#### [哈希表](#2537)
#### [滑动窗口](#2537)
### [2538_最大价值和与最小价值和的差值](#2538)
#### [树](#2538)
#### [深度优先搜索](#2538)
#### [数组](#2538)
#### [动态规划](#2538)
### [2539_好子序列的个数 🔒](#2539)
#### [哈希表](#2539)
#### [数学](#2539)
#### [字符串](#2539)
#### [组合数学](#2539)
#### [计数](#2539)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2530_执行 K 次操作后的最大分数
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
---
### 2531_使字符串中不同字符的数目相等
___
#### 哈希表
___
#### 字符串
___
#### 计数
---
### 2532_过桥的时间
___
#### 数组
___
#### 模拟
___
#### 堆（优先队列）
---
### 2533_好二进制字符串的数量 🔒
___
#### 动态规划
---
### 2534_通过门的时间 🔒
___
#### 队列
___
#### 数组
___
#### 模拟
---
### 2535_数组元素和与数字和的绝对差
___
#### 数组
___
#### 数学
---
### 2536_子矩阵元素加 1
___
#### 数组
___
#### 矩阵
___
#### 前缀和
---
### 2537_统计好子数组的数目
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 2538_最大价值和与最小价值和的差值
___
#### 树
___
#### 深度优先搜索
___
#### 数组
___
#### 动态规划
---
### 2539_好子序列的个数 🔒
___
#### 哈希表
___
#### 数学
___
#### 字符串
___
#### 组合数学
___
#### 计数
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 堆（优先队列） | 字符串 | 数学 |
| 数组 | 树 | 模拟 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |
| 组合数学 | 计数 | 贪心 |
| 队列 |  |  |

# [2530. 执行 K 次操作后的最大分数](https://leetcode.cn/problems/maximal-score-after-applying-k-operations){#2530}

{{< tabs "2530" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        for i, v in enumerate(nums):
            nums[i] = -v
        heapify(nums)
        ans = 0
        for _ in range(k):
            ans -= heapreplace(nums, -ceil(-nums[0] / 3))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int v : nums) {
            pq.offer(v);
        }
        long ans = 0;
        while (k-- > 0) {
            int v = pq.poll();
            ans += v;
            pq.offer((v + 2) / 3);
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
    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        long long ans = 0;
        while (k--) {
            int v = nums[0];
            ans += v;
            pop_heap(nums.begin(), nums.end());
            nums.back() = (v + 2) / 3;
            push_heap(nums.begin(), nums.end());
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxKelements(nums []int, k int) (ans int64) {
	h := hp{nums}
	heap.Init(&h)
	for ; k > 0; k-- {
		ans += int64(h.IntSlice[0])
		h.IntSlice[0] = (h.IntSlice[0] + 2) / 3
		heap.Fix(&h, 0)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (hp) Push(any)             {}
func (hp) Pop() (_ any)         { return }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxKelements(nums: number[], k: number): number {
    const pq = new MaxPriorityQueue();
    nums.forEach(num => pq.enqueue(num));
    let ans = 0;
    while (k > 0) {
        const v = pq.dequeue()!.element;
        ans += v;
        pq.enqueue(Math.floor((v + 2) / 3));
        k--;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn max_kelements(nums: Vec<i32>, k: i32) -> i64 {
        let mut pq = BinaryHeap::from(nums);
        let mut ans = 0;
        let mut k = k;
        while k > 0 {
            if let Some(v) = pq.pop() {
                ans += v as i64;
                pq.push((v + 2) / 3);
                k -= 1;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。你的 <strong>起始分数</strong> 为 <code>0</code> 。</p>

<p>在一步 <strong>操作</strong> 中：</p>

<ol>
	<li>选出一个满足 <code>0 &lt;= i &lt; nums.length</code> 的下标 <code>i</code> ，</li>
	<li>将你的 <strong>分数</strong> 增加 <code>nums[i]</code> ，并且</li>
	<li>将 <code>nums[i]</code> 替换为 <code>ceil(nums[i] / 3)</code> 。</li>
</ol>

<p>返回在 <strong>恰好</strong> 执行 <code>k</code> 次操作后，你可能获得的最大分数。</p>

<p>向上取整函数 <code>ceil(val)</code> 的结果是大于或等于 <code>val</code> 的最小整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,10,10,10,10], k = 5
<strong>输出：</strong>50
<strong>解释：</strong>对数组中每个元素执行一次操作。最后分数是 10 + 10 + 10 + 10 + 10 = 50 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,10,3,3,3], k = 3
<strong>输出：</strong>17
<strong>解释：</strong>可以执行下述操作：
第 1 步操作：选中 i = 1 ，nums 变为 [1,<em><strong>4</strong></em>,3,3,3] 。分数增加 10 。
第 2 步操作：选中 i = 1 ，nums 变为 [1,<em><strong>2</strong></em>,3,3,3] 。分数增加 4 。
第 3 步操作：选中 i = 2 ，nums 变为 [1,2,<em><strong>1</strong></em>,3,3] 。分数增加 3 。
最后分数是 10 + 4 + 3 = 17 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, k &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大根堆）

要使得分数最大化，我们需要在每一步操作中，选择元素值最大的元素进行操作。因此，我们可以使用优先队列（大根堆）来维护当前元素值最大的元素。

每次从优先队列中取出元素值最大的元素 $v$，将答案加上 $v$，并将 $v$ 替换为 $\lceil \frac{v}{3} \rceil$，加入优先队列。重复 $k$ 次后，将答案返回即可。

时间复杂度 $O(n + k \times \log n)$，空间复杂度 $O(n)$ 或 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        h = [-v for v in nums]
        heapify(h)
        ans = 0
        for _ in range(k):
            v = -heappop(h)
            ans += v
            heappush(h, -(ceil(v / 3)))
        return ans
```

#### Java

```java
class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int v : nums) {
            pq.offer(v);
        }
        long ans = 0;
        while (k-- > 0) {
            int v = pq.poll();
            ans += v;
            pq.offer((v + 2) / 3);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        while (k--) {
            int v = pq.top();
            pq.pop();
            ans += v;
            pq.push((v + 2) / 3);
        }
        return ans;
    }
};
```

#### Go

```go
func maxKelements(nums []int, k int) (ans int64) {
	h := &hp{nums}
	heap.Init(h)
	for ; k > 0; k-- {
		v := h.pop()
		ans += int64(v)
		h.push((v + 2) / 3)
	}
	return
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
func (h *hp) push(v int) { heap.Push(h, v) }
func (h *hp) pop() int   { return heap.Pop(h).(int) }
```

#### TypeScript

```ts
function maxKelements(nums: number[], k: number): number {
    const pq = new MaxPriorityQueue();
    nums.forEach(num => pq.enqueue(num));
    let ans = 0;
    while (k > 0) {
        const v = pq.dequeue()!.element;
        ans += v;
        pq.enqueue(Math.floor((v + 2) / 3));
        k--;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::BinaryHeap;

impl Solution {
    pub fn max_kelements(nums: Vec<i32>, k: i32) -> i64 {
        let mut pq = BinaryHeap::from(nums);
        let mut ans = 0;
        let mut k = k;
        while k > 0 {
            if let Some(v) = pq.pop() {
                ans += v as i64;
                pq.push((v + 2) / 3);
                k -= 1;
            }
        }
        ans
    }
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
    def maxKelements(self, nums: List[int], k: int) -> int:
        for i, v in enumerate(nums):
            nums[i] = -v
        heapify(nums)
        ans = 0
        for _ in range(k):
            ans -= heapreplace(nums, -ceil(-nums[0] / 3))
        return ans
```

#### C++

```cpp
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        long long ans = 0;
        while (k--) {
            int v = nums[0];
            ans += v;
            pop_heap(nums.begin(), nums.end());
            nums.back() = (v + 2) / 3;
            push_heap(nums.begin(), nums.end());
        }
        return ans;
    }
};
```

#### Go

```go
func maxKelements(nums []int, k int) (ans int64) {
	h := hp{nums}
	heap.Init(&h)
	for ; k > 0; k-- {
		ans += int64(h.IntSlice[0])
		h.IntSlice[0] = (h.IntSlice[0] + 2) / 3
		heap.Fix(&h, 0)
	}
	return
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] > h.IntSlice[j] }
func (hp) Push(any)             {}
func (hp) Pop() (_ any)         { return }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2531. 使字符串中不同字符的数目相等](https://leetcode.cn/problems/make-number-of-distinct-characters-equal){#2531}

{{< tabs "2531" >}}

{{% tab "python" %}}
```python
class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        cnt1 = Counter(word1)
        cnt2 = Counter(word2)
        x, y = len(cnt1), len(cnt2)
        for c1, v1 in cnt1.items():
            for c2, v2 in cnt2.items():
                if c1 == c2:
                    if x == y:
                        return True
                else:
                    a = x - (v1 == 1) + (cnt1[c2] == 0)
                    b = y - (v2 == 1) + (cnt2[c1] == 0)
                    if a == b:
                        return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isItPossible(String word1, String word2) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        int x = 0, y = 0;
        for (int i = 0; i < word1.length(); ++i) {
            if (++cnt1[word1.charAt(i) - 'a'] == 1) {
                ++x;
            }
        }
        for (int i = 0; i < word2.length(); ++i) {
            if (++cnt2[word2.charAt(i) - 'a'] == 1) {
                ++y;
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt1[i] > 0 && cnt2[j] > 0) {
                    if (i == j) {
                        if (x == y) {
                            return true;
                        }
                    } else {
                        int a = x - (cnt1[i] == 1 ? 1 : 0) + (cnt1[j] == 0 ? 1 : 0);
                        int b = y - (cnt2[j] == 1 ? 1 : 0) + (cnt2[i] == 0 ? 1 : 0);
                        if (a == b) {
                            return true;
                        }
                    }
                }
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
    bool isItPossible(string word1, string word2) {
        int cnt1[26]{};
        int cnt2[26]{};
        int x = 0, y = 0;
        for (char& c : word1) {
            if (++cnt1[c - 'a'] == 1) {
                ++x;
            }
        }
        for (char& c : word2) {
            if (++cnt2[c - 'a'] == 1) {
                ++y;
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt1[i] > 0 && cnt2[j] > 0) {
                    if (i == j) {
                        if (x == y) {
                            return true;
                        }
                    } else {
                        int a = x - (cnt1[i] == 1 ? 1 : 0) + (cnt1[j] == 0 ? 1 : 0);
                        int b = y - (cnt2[j] == 1 ? 1 : 0) + (cnt2[i] == 0 ? 1 : 0);
                        if (a == b) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isItPossible(word1 string, word2 string) bool {
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	x, y := 0, 0
	for _, c := range word1 {
		cnt1[c-'a']++
		if cnt1[c-'a'] == 1 {
			x++
		}
	}
	for _, c := range word2 {
		cnt2[c-'a']++
		if cnt2[c-'a'] == 1 {
			y++
		}
	}
	for i := range cnt1 {
		for j := range cnt2 {
			if cnt1[i] > 0 && cnt2[j] > 0 {
				if i == j {
					if x == y {
						return true
					}
				} else {
					a := x
					if cnt1[i] == 1 {
						a--
					}
					if cnt1[j] == 0 {
						a++
					}

					b := y
					if cnt2[j] == 1 {
						b--
					}
					if cnt2[i] == 0 {
						b++
					}

					if a == b {
						return true
					}
				}
			}
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isItPossible(word1: string, word2: string): boolean {
    const cnt1: number[] = Array(26).fill(0);
    const cnt2: number[] = Array(26).fill(0);
    let [x, y] = [0, 0];

    for (const c of word1) {
        if (++cnt1[c.charCodeAt(0) - 'a'.charCodeAt(0)] === 1) {
            ++x;
        }
    }

    for (const c of word2) {
        if (++cnt2[c.charCodeAt(0) - 'a'.charCodeAt(0)] === 1) {
            ++y;
        }
    }

    for (let i = 0; i < 26; ++i) {
        for (let j = 0; j < 26; ++j) {
            if (cnt1[i] > 0 && cnt2[j] > 0) {
                if (i === j) {
                    if (x === y) {
                        return true;
                    }
                } else {
                    const a = x - (cnt1[i] === 1 ? 1 : 0) + (cnt1[j] === 0 ? 1 : 0);
                    const b = y - (cnt2[j] === 1 ? 1 : 0) + (cnt2[i] === 0 ? 1 : 0);
                    if (a === b) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个下标从 <strong>0</strong> 开始的字符串 <code>word1</code> 和 <code>word2</code> 。</p>

<p>一次 <strong>移动</strong> 由以下两个步骤组成：</p>

<ul>
	<li>选中两个下标&nbsp;<code>i</code> 和 <code>j</code> ，分别满足 <code>0 &lt;= i &lt; word1.length</code> 和 <code>0 &lt;= j &lt; word2.length</code> ，</li>
	<li>交换 <code>word1[i]</code> 和 <code>word2[j]</code> 。</li>
</ul>

<p>如果可以通过 <strong>恰好一次</strong> 移动，使 <code>word1</code> 和 <code>word2</code> 中不同字符的数目相等，则返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>word1 = "ac", word2 = "b"
<strong>输出：</strong>false
<strong>解释：</strong>交换任何一组下标都会导致第一个字符串中有 2 个不同的字符，而在第二个字符串中只有 1 个不同字符。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>word1 = "abcc", word2 = "aab"
<strong>输出：</strong>true
<strong>解释：</strong>交换第一个字符串的下标 2 和第二个字符串的下标 0 。之后得到 word1 = "abac" 和 word2 = "cab" ，各有 3 个不同字符。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>word1 = "abcde", word2 = "fghij"
<strong>输出：</strong>true
<strong>解释：</strong>无论交换哪一组下标，两个字符串中都会有 5 个不同字符。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word1</code> 和 <code>word2</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们先用两个长度为 $26$ 的数组 $\textit{cnt1}$ 和 $\textit{cnt2}$ 分别记录字符串 $\textit{word1}$ 和 $\textit{word2}$ 中每个字符的出现次数。

然后我们分别统计 $\textit{word1}$ 和 $\textit{word2}$ 中不同字符的个数，分别记为 $x$ 和 $y$。

接下来我们枚举 $\textit{word1}$ 中的每个字符 $c1$ 和 $\textit{word2}$ 中的每个字符 $c2$，如果 $c1 = c2$，那么我们只需要判断 $x$ 和 $y$ 是否相等；否则，我们需要判断 $x - (\textit{cnt1}[c1] = 1) + (\textit{cnt1}[c2] = 0)$ 和 $y - (\textit{cnt2}[c2] = 1) + (\textit{cnt2}[c1] = 0)$ 是否相等。如果相等，那么我们就找到了一种方案，返回 $\text{true}$。

如果我们枚举完所有的字符都没有找到合适的方案，那么我们就返回 $\text{false}$。

时间复杂度 $O(m + n + |\Sigma|^2)$，其中 $m$ 和 $n$ 分别是字符串 $\textit{word1}$ 和 $\textit{word2}$ 的长度，而 $\Sigma$ 是字符集，本题中字符集为小写字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        cnt1 = Counter(word1)
        cnt2 = Counter(word2)
        x, y = len(cnt1), len(cnt2)
        for c1, v1 in cnt1.items():
            for c2, v2 in cnt2.items():
                if c1 == c2:
                    if x == y:
                        return True
                else:
                    a = x - (v1 == 1) + (cnt1[c2] == 0)
                    b = y - (v2 == 1) + (cnt2[c1] == 0)
                    if a == b:
                        return True
        return False
```

#### Java

```java
class Solution {
    public boolean isItPossible(String word1, String word2) {
        int[] cnt1 = new int[26];
        int[] cnt2 = new int[26];
        int x = 0, y = 0;
        for (int i = 0; i < word1.length(); ++i) {
            if (++cnt1[word1.charAt(i) - 'a'] == 1) {
                ++x;
            }
        }
        for (int i = 0; i < word2.length(); ++i) {
            if (++cnt2[word2.charAt(i) - 'a'] == 1) {
                ++y;
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt1[i] > 0 && cnt2[j] > 0) {
                    if (i == j) {
                        if (x == y) {
                            return true;
                        }
                    } else {
                        int a = x - (cnt1[i] == 1 ? 1 : 0) + (cnt1[j] == 0 ? 1 : 0);
                        int b = y - (cnt2[j] == 1 ? 1 : 0) + (cnt2[i] == 0 ? 1 : 0);
                        if (a == b) {
                            return true;
                        }
                    }
                }
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
    bool isItPossible(string word1, string word2) {
        int cnt1[26]{};
        int cnt2[26]{};
        int x = 0, y = 0;
        for (char& c : word1) {
            if (++cnt1[c - 'a'] == 1) {
                ++x;
            }
        }
        for (char& c : word2) {
            if (++cnt2[c - 'a'] == 1) {
                ++y;
            }
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt1[i] > 0 && cnt2[j] > 0) {
                    if (i == j) {
                        if (x == y) {
                            return true;
                        }
                    } else {
                        int a = x - (cnt1[i] == 1 ? 1 : 0) + (cnt1[j] == 0 ? 1 : 0);
                        int b = y - (cnt2[j] == 1 ? 1 : 0) + (cnt2[i] == 0 ? 1 : 0);
                        if (a == b) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
```

#### Go

```go
func isItPossible(word1 string, word2 string) bool {
	cnt1 := [26]int{}
	cnt2 := [26]int{}
	x, y := 0, 0
	for _, c := range word1 {
		cnt1[c-'a']++
		if cnt1[c-'a'] == 1 {
			x++
		}
	}
	for _, c := range word2 {
		cnt2[c-'a']++
		if cnt2[c-'a'] == 1 {
			y++
		}
	}
	for i := range cnt1 {
		for j := range cnt2 {
			if cnt1[i] > 0 && cnt2[j] > 0 {
				if i == j {
					if x == y {
						return true
					}
				} else {
					a := x
					if cnt1[i] == 1 {
						a--
					}
					if cnt1[j] == 0 {
						a++
					}

					b := y
					if cnt2[j] == 1 {
						b--
					}
					if cnt2[i] == 0 {
						b++
					}

					if a == b {
						return true
					}
				}
			}
		}
	}
	return false
}
```

#### TypeScript

```ts
function isItPossible(word1: string, word2: string): boolean {
    const cnt1: number[] = Array(26).fill(0);
    const cnt2: number[] = Array(26).fill(0);
    let [x, y] = [0, 0];

    for (const c of word1) {
        if (++cnt1[c.charCodeAt(0) - 'a'.charCodeAt(0)] === 1) {
            ++x;
        }
    }

    for (const c of word2) {
        if (++cnt2[c.charCodeAt(0) - 'a'.charCodeAt(0)] === 1) {
            ++y;
        }
    }

    for (let i = 0; i < 26; ++i) {
        for (let j = 0; j < 26; ++j) {
            if (cnt1[i] > 0 && cnt2[j] > 0) {
                if (i === j) {
                    if (x === y) {
                        return true;
                    }
                } else {
                    const a = x - (cnt1[i] === 1 ? 1 : 0) + (cnt1[j] === 0 ? 1 : 0);
                    const b = y - (cnt2[j] === 1 ? 1 : 0) + (cnt2[i] === 0 ? 1 : 0);
                    if (a === b) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2532. 过桥的时间](https://leetcode.cn/problems/time-to-cross-a-bridge){#2532}

{{< tabs "2532" >}}

{{% tab "python" %}}
```python
class Solution:
    def findCrossingTime(self, n: int, k: int, time: List[List[int]]) -> int:
        time.sort(key=lambda x: x[0] + x[2])
        cur = 0
        wait_in_left, wait_in_right = [], []
        work_in_left, work_in_right = [], []
        for i in range(k):
            heappush(wait_in_left, -i)
        while 1:
            while work_in_left:
                t, i = work_in_left[0]
                if t > cur:
                    break
                heappop(work_in_left)
                heappush(wait_in_left, -i)
            while work_in_right:
                t, i = work_in_right[0]
                if t > cur:
                    break
                heappop(work_in_right)
                heappush(wait_in_right, -i)
            left_to_go = n > 0 and wait_in_left
            right_to_go = bool(wait_in_right)
            if not left_to_go and not right_to_go:
                nxt = inf
                if work_in_left:
                    nxt = min(nxt, work_in_left[0][0])
                if work_in_right:
                    nxt = min(nxt, work_in_right[0][0])
                cur = nxt
                continue
            if right_to_go:
                i = -heappop(wait_in_right)
                cur += time[i][2]
                if n == 0 and not wait_in_right and not work_in_right:
                    return cur
                heappush(work_in_left, (cur + time[i][3], i))
            else:
                i = -heappop(wait_in_left)
                cur += time[i][0]
                n -= 1
                heappush(work_in_right, (cur + time[i][1], i))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findCrossingTime(int n, int k, int[][] time) {
        int[][] t = new int[k][5];
        for (int i = 0; i < k; ++i) {
            int[] x = time[i];
            t[i] = new int[] {x[0], x[1], x[2], x[3], i};
        }
        Arrays.sort(t, (a, b) -> {
            int x = a[0] + a[2], y = b[0] + b[2];
            return x == y ? a[4] - b[4] : x - y;
        });
        int cur = 0;
        PriorityQueue<Integer> waitInLeft = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<Integer> waitInRight = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<int[]> workInLeft = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> workInRight = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < k; ++i) {
            waitInLeft.offer(i);
        }
        while (true) {
            while (!workInLeft.isEmpty()) {
                int[] p = workInLeft.peek();
                if (p[0] > cur) {
                    break;
                }
                waitInLeft.offer(workInLeft.poll()[1]);
            }
            while (!workInRight.isEmpty()) {
                int[] p = workInRight.peek();
                if (p[0] > cur) {
                    break;
                }
                waitInRight.offer(workInRight.poll()[1]);
            }
            boolean leftToGo = n > 0 && !waitInLeft.isEmpty();
            boolean rightToGo = !waitInRight.isEmpty();
            if (!leftToGo && !rightToGo) {
                int nxt = 1 << 30;
                if (!workInLeft.isEmpty()) {
                    nxt = Math.min(nxt, workInLeft.peek()[0]);
                }
                if (!workInRight.isEmpty()) {
                    nxt = Math.min(nxt, workInRight.peek()[0]);
                }
                cur = nxt;
                continue;
            }
            if (rightToGo) {
                int i = waitInRight.poll();
                cur += t[i][2];
                if (n == 0 && waitInRight.isEmpty() && workInRight.isEmpty()) {
                    return cur;
                }
                workInLeft.offer(new int[] {cur + t[i][3], i});
            } else {
                int i = waitInLeft.poll();
                cur += t[i][0];
                --n;
                workInRight.offer(new int[] {cur + t[i][1], i});
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
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        using pii = pair<int, int>;
        for (int i = 0; i < k; ++i) {
            time[i].push_back(i);
        }
        sort(time.begin(), time.end(), [](auto& a, auto& b) {
            int x = a[0] + a[2], y = b[0] + b[2];
            return x == y ? a[4] < b[4] : x < y;
        });
        int cur = 0;
        priority_queue<int> waitInLeft, waitInRight;
        priority_queue<pii, vector<pii>, greater<pii>> workInLeft, workInRight;
        for (int i = 0; i < k; ++i) {
            waitInLeft.push(i);
        }
        while (true) {
            while (!workInLeft.empty()) {
                auto [t, i] = workInLeft.top();
                if (t > cur) {
                    break;
                }
                workInLeft.pop();
                waitInLeft.push(i);
            }
            while (!workInRight.empty()) {
                auto [t, i] = workInRight.top();
                if (t > cur) {
                    break;
                }
                workInRight.pop();
                waitInRight.push(i);
            }
            bool leftToGo = n > 0 && !waitInLeft.empty();
            bool rightToGo = !waitInRight.empty();
            if (!leftToGo && !rightToGo) {
                int nxt = 1 << 30;
                if (!workInLeft.empty()) {
                    nxt = min(nxt, workInLeft.top().first);
                }
                if (!workInRight.empty()) {
                    nxt = min(nxt, workInRight.top().first);
                }
                cur = nxt;
                continue;
            }
            if (rightToGo) {
                int i = waitInRight.top();
                waitInRight.pop();
                cur += time[i][2];
                if (n == 0 && waitInRight.empty() && workInRight.empty()) {
                    return cur;
                }
                workInLeft.push({cur + time[i][3], i});
            } else {
                int i = waitInLeft.top();
                waitInLeft.pop();
                cur += time[i][0];
                --n;
                workInRight.push({cur + time[i][1], i});
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findCrossingTime(n int, k int, time [][]int) int {
	sort.SliceStable(time, func(i, j int) bool { return time[i][0]+time[i][2] < time[j][0]+time[j][2] })
	waitInLeft := hp{}
	waitInRight := hp{}
	workInLeft := hp2{}
	workInRight := hp2{}
	for i := range time {
		heap.Push(&waitInLeft, i)
	}
	cur := 0
	for {
		for len(workInLeft) > 0 {
			if workInLeft[0].t > cur {
				break
			}
			heap.Push(&waitInLeft, heap.Pop(&workInLeft).(pair).i)
		}
		for len(workInRight) > 0 {
			if workInRight[0].t > cur {
				break
			}
			heap.Push(&waitInRight, heap.Pop(&workInRight).(pair).i)
		}
		leftToGo := n > 0 && waitInLeft.Len() > 0
		rightToGo := waitInRight.Len() > 0
		if !leftToGo && !rightToGo {
			nxt := 1 << 30
			if len(workInLeft) > 0 {
				nxt = min(nxt, workInLeft[0].t)
			}
			if len(workInRight) > 0 {
				nxt = min(nxt, workInRight[0].t)
			}
			cur = nxt
			continue
		}
		if rightToGo {
			i := heap.Pop(&waitInRight).(int)
			cur += time[i][2]
			if n == 0 && waitInRight.Len() == 0 && len(workInRight) == 0 {
				return cur
			}
			heap.Push(&workInLeft, pair{cur + time[i][3], i})
		} else {
			i := heap.Pop(&waitInLeft).(int)
			cur += time[i][0]
			n--
			heap.Push(&workInRight, pair{cur + time[i][1], i})
		}
	}
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

type pair struct{ t, i int }
type hp2 []pair

func (h hp2) Len() int           { return len(h) }
func (h hp2) Less(i, j int) bool { return h[i].t < h[j].t }
func (h hp2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>共有 <code>k</code> 位工人计划将 <code>n</code> 个箱子从右侧的（旧）仓库移动到左侧的（新）仓库。给你两个整数 <code>n</code> 和 <code>k</code>，以及一个二维整数数组 <code>time</code> ，数组的大小为 <code>k x 4</code> ，其中 <code>time[i] = [right<sub>i</sub>, pick<sub>i</sub>, left<sub>i</sub>, put<sub>i</sub>]</code> 。</p>

<p>一条河将两座仓库分隔，只能通过一座桥通行。旧仓库位于河的右岸，新仓库在河的左岸。开始时，所有 <code>k</code> 位工人都在桥的左侧等待。为了移动这些箱子，第 <code>i</code> 位工人（下标从 <strong>0</strong> 开始）可以：</p>

<ul>
	<li>从左岸（新仓库）跨过桥到右岸（旧仓库），用时 <code>right<sub>i</sub></code> 分钟。</li>
	<li>从旧仓库选择一个箱子，并返回到桥边，用时 <code>pick<sub>i</sub></code> 分钟。不同工人可以同时搬起所选的箱子。</li>
	<li>从右岸（旧仓库）跨过桥到左岸（新仓库），用时 <code>left<sub>i</sub></code> 分钟。</li>
	<li>将箱子放入新仓库，并返回到桥边，用时 <code>put<sub>i</sub></code> 分钟。不同工人可以同时放下所选的箱子。</li>
</ul>

<p>如果满足下面任一条件，则认为工人 <code>i</code> 的 <strong>效率低于</strong> 工人 <code>j</code> ：</p>

<ul>
	<li><code>left<sub>i</sub> + right<sub>i</sub> &gt; left<sub>j</sub> + right<sub>j</sub></code></li>
	<li><code>left<sub>i</sub> + right<sub>i</sub> == left<sub>j</sub> + right<sub>j</sub></code> 且 <code>i &gt; j</code></li>
</ul>

<p>工人通过桥时需要遵循以下规则：</p>

<ul>
	<li>同时只能有一名工人过桥。</li>
	<li>当桥梁未被使用时，优先让右侧 <strong>效率最低</strong> 的工人（已经拿起盒子的工人）过桥。如果不是，优先让左侧 <strong>效率最低</strong> 的工人通过。</li>
	<li>如果左侧已经派出足够的工人来拾取所有剩余的箱子，则 <strong>不会</strong> 再从左侧派出工人。</li>
</ul>

<p><span class="text-only" data-eleid="8" style="white-space: pre;">请你返回最后一个箱子 </span><strong><span class="text-only" data-eleid="9" style="white-space: pre;">到达桥左侧</span></strong><span class="text-only" data-eleid="10" style="white-space: pre;"> 的时间。</span></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]</span></p>

<p><span class="example-io"><b>输出：</b>6</span></p>

<p><b>解释：</b></p>

<pre>
从 0 到 1 分钟：工人 2 通过桥到达右侧。
从 1 到 2 分钟：工人 2 从右侧仓库拿起箱子。
从 2 到 6 分钟：工人 2 通过桥到达左侧。
从 6 到 7 分钟：工人 2 向左侧仓库放下箱子。
整个过程在 7 分钟后结束。我们返回 6 因为该问题要求的是最后一名工人到达桥梁左侧的时间。
</pre>
</div>

<p><strong class="example">示例&nbsp;2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 3, k = 2, time =</span> [[1,5,1,8],[10,10,10,10]]</p>

<p><b>输出：</b>37</p>

<p><strong>解释：</strong></p>

<pre>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2532.Time%20to%20Cross%20a%20Bridge/images/378539249-c6ce3c73-40e7-4670-a8b5-7ddb9abede11.png" style="width: 450px; height: 176px;" />
</pre>

<p>最后一个盒子在37秒时到达左侧。请注意，我们并 <strong>没有</strong> 放下最后一个箱子，因为那样会花费更多时间，而且它们已经和工人们一起在左边。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 10<sup>4</sup></code></li>
	<li><code>time.length == k</code></li>
	<li><code>time[i].length == 4</code></li>
	<li><code>1 &lt;= left<sub>i</sub>, pick<sub>i</sub>, right<sub>i</sub>, put<sub>i</sub> &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（大小根堆） + 模拟

我们先将工人按照效率从高到底排序，这样，下标越大的工人，效率越低。

接下来，我们用四个优先队列模拟工人的状态：

-   `wait_in_left`：大根堆，存储当前在左岸等待的工人的下标；
-   `wait_in_right`：大根堆，存储当前在右岸等待的工人的下标；
-   `work_in_left`：小根堆，存储当前在左岸工作的工人放好箱子的时间以及工人的下标；
-   `work_in_right`：小根堆，存储当前在右岸工作的工人拿好箱子的时间以及工人的下标。

初始时，所有工人都在左岸，因此 `wait_in_left` 中存储所有工人的下标。用变量 `cur` 记录当前时间。

然后，我们模拟整个过程。我们先判断当前时刻，`work_in_left` 是否有工人已经放好箱子，如果有，我们将工人放入 `wait_in_left` 中，然后将工人从 `work_in_left` 中移除。同理，我们再判断 `work_in_right` 是否有工人已经放好箱子，如果有，我们将工人放入 `wait_in_right` 中，然后将工人从 `work_in_right` 中移除。

接着，我们判断当前时刻是否有工人在左岸等待，记为 `left_to_go`，同时，我们判断当前时刻是否有工人在右岸等待，记为 `right_to_go`。如果不存在等待过岸的工人，我们直接将 `cur` 更新为下一个工人放好箱子的时间，然后继续模拟过程。

如果 `right_to_go` 为 `true`，我们从 `wait_in_right` 中取出一个工人，更新 `cur` 为当前时间加上该工人从右岸过左岸的时间，如果此时所有工人都已经过了右岸，我们直接将 `cur` 作为答案返回；否则，我们将该工人放入 `work_in_left` 中。

如果 `left_to_go` 为 `true`，我们从 `wait_in_left` 中取出一个工人，更新 `cur` 为当前时间加上该工人从左岸过右岸的时间，然后将该工人放入 `work_in_right` 中，并且将箱子数量减一。

循环上述过程，直到箱子数量为零，此时 `cur` 即为答案。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(k)$。其中 $n$ 和 $k$ 分别为工人数量和箱子数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findCrossingTime(self, n: int, k: int, time: List[List[int]]) -> int:
        time.sort(key=lambda x: x[0] + x[2])
        cur = 0
        wait_in_left, wait_in_right = [], []
        work_in_left, work_in_right = [], []
        for i in range(k):
            heappush(wait_in_left, -i)
        while 1:
            while work_in_left:
                t, i = work_in_left[0]
                if t > cur:
                    break
                heappop(work_in_left)
                heappush(wait_in_left, -i)
            while work_in_right:
                t, i = work_in_right[0]
                if t > cur:
                    break
                heappop(work_in_right)
                heappush(wait_in_right, -i)
            left_to_go = n > 0 and wait_in_left
            right_to_go = bool(wait_in_right)
            if not left_to_go and not right_to_go:
                nxt = inf
                if work_in_left:
                    nxt = min(nxt, work_in_left[0][0])
                if work_in_right:
                    nxt = min(nxt, work_in_right[0][0])
                cur = nxt
                continue
            if right_to_go:
                i = -heappop(wait_in_right)
                cur += time[i][2]
                if n == 0 and not wait_in_right and not work_in_right:
                    return cur
                heappush(work_in_left, (cur + time[i][3], i))
            else:
                i = -heappop(wait_in_left)
                cur += time[i][0]
                n -= 1
                heappush(work_in_right, (cur + time[i][1], i))
```

#### Java

```java
class Solution {
    public int findCrossingTime(int n, int k, int[][] time) {
        int[][] t = new int[k][5];
        for (int i = 0; i < k; ++i) {
            int[] x = time[i];
            t[i] = new int[] {x[0], x[1], x[2], x[3], i};
        }
        Arrays.sort(t, (a, b) -> {
            int x = a[0] + a[2], y = b[0] + b[2];
            return x == y ? a[4] - b[4] : x - y;
        });
        int cur = 0;
        PriorityQueue<Integer> waitInLeft = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<Integer> waitInRight = new PriorityQueue<>((a, b) -> b - a);
        PriorityQueue<int[]> workInLeft = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> workInRight = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < k; ++i) {
            waitInLeft.offer(i);
        }
        while (true) {
            while (!workInLeft.isEmpty()) {
                int[] p = workInLeft.peek();
                if (p[0] > cur) {
                    break;
                }
                waitInLeft.offer(workInLeft.poll()[1]);
            }
            while (!workInRight.isEmpty()) {
                int[] p = workInRight.peek();
                if (p[0] > cur) {
                    break;
                }
                waitInRight.offer(workInRight.poll()[1]);
            }
            boolean leftToGo = n > 0 && !waitInLeft.isEmpty();
            boolean rightToGo = !waitInRight.isEmpty();
            if (!leftToGo && !rightToGo) {
                int nxt = 1 << 30;
                if (!workInLeft.isEmpty()) {
                    nxt = Math.min(nxt, workInLeft.peek()[0]);
                }
                if (!workInRight.isEmpty()) {
                    nxt = Math.min(nxt, workInRight.peek()[0]);
                }
                cur = nxt;
                continue;
            }
            if (rightToGo) {
                int i = waitInRight.poll();
                cur += t[i][2];
                if (n == 0 && waitInRight.isEmpty() && workInRight.isEmpty()) {
                    return cur;
                }
                workInLeft.offer(new int[] {cur + t[i][3], i});
            } else {
                int i = waitInLeft.poll();
                cur += t[i][0];
                --n;
                workInRight.offer(new int[] {cur + t[i][1], i});
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        using pii = pair<int, int>;
        for (int i = 0; i < k; ++i) {
            time[i].push_back(i);
        }
        sort(time.begin(), time.end(), [](auto& a, auto& b) {
            int x = a[0] + a[2], y = b[0] + b[2];
            return x == y ? a[4] < b[4] : x < y;
        });
        int cur = 0;
        priority_queue<int> waitInLeft, waitInRight;
        priority_queue<pii, vector<pii>, greater<pii>> workInLeft, workInRight;
        for (int i = 0; i < k; ++i) {
            waitInLeft.push(i);
        }
        while (true) {
            while (!workInLeft.empty()) {
                auto [t, i] = workInLeft.top();
                if (t > cur) {
                    break;
                }
                workInLeft.pop();
                waitInLeft.push(i);
            }
            while (!workInRight.empty()) {
                auto [t, i] = workInRight.top();
                if (t > cur) {
                    break;
                }
                workInRight.pop();
                waitInRight.push(i);
            }
            bool leftToGo = n > 0 && !waitInLeft.empty();
            bool rightToGo = !waitInRight.empty();
            if (!leftToGo && !rightToGo) {
                int nxt = 1 << 30;
                if (!workInLeft.empty()) {
                    nxt = min(nxt, workInLeft.top().first);
                }
                if (!workInRight.empty()) {
                    nxt = min(nxt, workInRight.top().first);
                }
                cur = nxt;
                continue;
            }
            if (rightToGo) {
                int i = waitInRight.top();
                waitInRight.pop();
                cur += time[i][2];
                if (n == 0 && waitInRight.empty() && workInRight.empty()) {
                    return cur;
                }
                workInLeft.push({cur + time[i][3], i});
            } else {
                int i = waitInLeft.top();
                waitInLeft.pop();
                cur += time[i][0];
                --n;
                workInRight.push({cur + time[i][1], i});
            }
        }
    }
};
```

#### Go

```go
func findCrossingTime(n int, k int, time [][]int) int {
	sort.SliceStable(time, func(i, j int) bool { return time[i][0]+time[i][2] < time[j][0]+time[j][2] })
	waitInLeft := hp{}
	waitInRight := hp{}
	workInLeft := hp2{}
	workInRight := hp2{}
	for i := range time {
		heap.Push(&waitInLeft, i)
	}
	cur := 0
	for {
		for len(workInLeft) > 0 {
			if workInLeft[0].t > cur {
				break
			}
			heap.Push(&waitInLeft, heap.Pop(&workInLeft).(pair).i)
		}
		for len(workInRight) > 0 {
			if workInRight[0].t > cur {
				break
			}
			heap.Push(&waitInRight, heap.Pop(&workInRight).(pair).i)
		}
		leftToGo := n > 0 && waitInLeft.Len() > 0
		rightToGo := waitInRight.Len() > 0
		if !leftToGo && !rightToGo {
			nxt := 1 << 30
			if len(workInLeft) > 0 {
				nxt = min(nxt, workInLeft[0].t)
			}
			if len(workInRight) > 0 {
				nxt = min(nxt, workInRight[0].t)
			}
			cur = nxt
			continue
		}
		if rightToGo {
			i := heap.Pop(&waitInRight).(int)
			cur += time[i][2]
			if n == 0 && waitInRight.Len() == 0 && len(workInRight) == 0 {
				return cur
			}
			heap.Push(&workInLeft, pair{cur + time[i][3], i})
		} else {
			i := heap.Pop(&waitInLeft).(int)
			cur += time[i][0]
			n--
			heap.Push(&workInRight, pair{cur + time[i][1], i})
		}
	}
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

type pair struct{ t, i int }
type hp2 []pair

func (h hp2) Len() int           { return len(h) }
func (h hp2) Less(i, j int) bool { return h[i].t < h[j].t }
func (h hp2) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp2) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp2) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2533. 好二进制字符串的数量 🔒](https://leetcode.cn/problems/number-of-good-binary-strings){#2533}

{{< tabs "2533" >}}

{{% tab "python" %}}
```python
class Solution:
    def goodBinaryStrings(
        self, minLength: int, maxLength: int, oneGroup: int, zeroGroup: int
    ) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * maxLength
        for i in range(1, len(f)):
            if i - oneGroup >= 0:
                f[i] += f[i - oneGroup]
            if i - zeroGroup >= 0:
                f[i] += f[i - zeroGroup]
            f[i] %= mod
        return sum(f[minLength:]) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[maxLength + 1];
        f[0] = 1;
        for (int i = 1; i <= maxLength; ++i) {
            if (i - oneGroup >= 0) {
                f[i] = (f[i] + f[i - oneGroup]) % mod;
            }
            if (i - zeroGroup >= 0) {
                f[i] = (f[i] + f[i - zeroGroup]) % mod;
            }
        }
        int ans = 0;
        for (int i = minLength; i <= maxLength; ++i) {
            ans = (ans + f[i]) % mod;
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
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        const int mod = 1e9 + 7;
        int f[maxLength + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= maxLength; ++i) {
            if (i - oneGroup >= 0) {
                f[i] = (f[i] + f[i - oneGroup]) % mod;
            }
            if (i - zeroGroup >= 0) {
                f[i] = (f[i] + f[i - zeroGroup]) % mod;
            }
        }
        int ans = 0;
        for (int i = minLength; i <= maxLength; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func goodBinaryStrings(minLength int, maxLength int, oneGroup int, zeroGroup int) (ans int) {
	const mod int = 1e9 + 7
	f := make([]int, maxLength+1)
	f[0] = 1
	for i := 1; i <= maxLength; i++ {
		if i-oneGroup >= 0 {
			f[i] += f[i-oneGroup]
		}
		if i-zeroGroup >= 0 {
			f[i] += f[i-zeroGroup]
		}
		f[i] %= mod
	}
	for _, v := range f[minLength:] {
		ans = (ans + v) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function goodBinaryStrings(
    minLength: number,
    maxLength: number,
    oneGroup: number,
    zeroGroup: number,
): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(maxLength + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= maxLength; ++i) {
        if (i >= oneGroup) {
            f[i] += f[i - oneGroup];
        }
        if (i >= zeroGroup) {
            f[i] += f[i - zeroGroup];
        }
        f[i] %= mod;
    }
    return f.slice(minLength).reduce((a, b) => a + b, 0) % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><span style="">给你四个整数 </span><code>minLength</code>、<code>maxLength</code>、<code>oneGroup</code><span style=""> 和 </span><code>zeroGroup</code><span style=""> 。</span></p>

<p><strong>好 </strong>二进制字符串满足下述条件：</p>

<ul>
	<li>字符串的长度在 <code>[minLength, maxLength]</code> 之间。</li>
	<li>每块连续 <code>1</code> 的个数是 <code>oneGroup</code> 的整数倍
	<ul>
		<li>例如在二进制字符串 <code>00<em><strong>11</strong></em>0<em><strong>1111</strong></em>00</code> 中，每块连续 <code>1</code> 的个数分别是<code>[2,4]</code> 。</li>
	</ul>
	</li>
	<li>每块连续 <code>0</code> 的个数是 <code>zeroGroup</code> 的整数倍
	<ul>
		<li>例如在二进制字符串 <code><em><strong>00</strong></em>11<em><strong>0</strong></em>1111<em><strong>00</strong></em></code> 中，每块连续 <code>0</code> 的个数分别是 <code>[2,1,2]</code> 。</li>
	</ul>
	</li>
</ul>

<p>请返回 <strong>好</strong> 二进制字符串的个数。答案可能很大<strong>，</strong>请返回对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 后的结果。</p>

<p><strong>注意：</strong><code>0</code> 可以被认为是所有数字的倍数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>minLength = 2, maxLength = 3, oneGroup = 1, zeroGroup = 2
<strong>输出：</strong>5
<strong>解释：</strong>在本示例中有 5 个好二进制字符串: "00", "11", "001", "100", 和 "111" 。
可以证明只有 5 个好二进制字符串满足所有的条件。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>minLength = 4, maxLength = 4, oneGroup = 4, zeroGroup = 3
<strong>输出：</strong>1
<strong>解释：</strong>在本示例中有 1 个好二进制字符串: "1111" 。
可以证明只有 1 个好字符串满足所有的条件。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= minLength &lt;= maxLength &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= oneGroup, zeroGroup &lt;= maxLength</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示长度为 $i$ 的字符串中满足条件的个数。状态转移方程为：

$$
f[i] = \begin{cases}
1 & i = 0 \\
f[i - oneGroup] + f[i - zeroGroup] & i \geq 1
\end{cases}
$$

最终答案为 $f[minLength] + f[minLength + 1] + \cdots + f[maxLength]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n=maxLength$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def goodBinaryStrings(
        self, minLength: int, maxLength: int, oneGroup: int, zeroGroup: int
    ) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * maxLength
        for i in range(1, len(f)):
            if i - oneGroup >= 0:
                f[i] += f[i - oneGroup]
            if i - zeroGroup >= 0:
                f[i] += f[i - zeroGroup]
            f[i] %= mod
        return sum(f[minLength:]) % mod
```

#### Java

```java
class Solution {
    public int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[maxLength + 1];
        f[0] = 1;
        for (int i = 1; i <= maxLength; ++i) {
            if (i - oneGroup >= 0) {
                f[i] = (f[i] + f[i - oneGroup]) % mod;
            }
            if (i - zeroGroup >= 0) {
                f[i] = (f[i] + f[i - zeroGroup]) % mod;
            }
        }
        int ans = 0;
        for (int i = minLength; i <= maxLength; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        const int mod = 1e9 + 7;
        int f[maxLength + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= maxLength; ++i) {
            if (i - oneGroup >= 0) {
                f[i] = (f[i] + f[i - oneGroup]) % mod;
            }
            if (i - zeroGroup >= 0) {
                f[i] = (f[i] + f[i - zeroGroup]) % mod;
            }
        }
        int ans = 0;
        for (int i = minLength; i <= maxLength; ++i) {
            ans = (ans + f[i]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func goodBinaryStrings(minLength int, maxLength int, oneGroup int, zeroGroup int) (ans int) {
	const mod int = 1e9 + 7
	f := make([]int, maxLength+1)
	f[0] = 1
	for i := 1; i <= maxLength; i++ {
		if i-oneGroup >= 0 {
			f[i] += f[i-oneGroup]
		}
		if i-zeroGroup >= 0 {
			f[i] += f[i-zeroGroup]
		}
		f[i] %= mod
	}
	for _, v := range f[minLength:] {
		ans = (ans + v) % mod
	}
	return
}
```

#### TypeScript

```ts
function goodBinaryStrings(
    minLength: number,
    maxLength: number,
    oneGroup: number,
    zeroGroup: number,
): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(maxLength + 1).fill(0);
    f[0] = 1;
    for (let i = 1; i <= maxLength; ++i) {
        if (i >= oneGroup) {
            f[i] += f[i - oneGroup];
        }
        if (i >= zeroGroup) {
            f[i] += f[i - zeroGroup];
        }
        f[i] %= mod;
    }
    return f.slice(minLength).reduce((a, b) => a + b, 0) % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2534. 通过门的时间 🔒](https://leetcode.cn/problems/time-taken-to-cross-the-door){#2534}

{{< tabs "2534" >}}

{{% tab "python" %}}
```python
class Solution:
    def timeTaken(self, arrival: List[int], state: List[int]) -> List[int]:
        q = [deque(), deque()]
        n = len(arrival)
        t = i = 0
        st = 1
        ans = [0] * n
        while i < n or q[0] or q[1]:
            while i < n and arrival[i] <= t:
                q[state[i]].append(i)
                i += 1
            if q[0] and q[1]:
                ans[q[st].popleft()] = t
            elif q[0] or q[1]:
                st = 0 if q[0] else 1
                ans[q[st].popleft()] = t
            else:
                st = 1
            t += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] timeTaken(int[] arrival, int[] state) {
        Deque<Integer>[] q = new Deque[2];
        Arrays.setAll(q, i -> new ArrayDeque<>());
        int n = arrival.length;
        int t = 0, i = 0, st = 1;
        int[] ans = new int[n];
        while (i < n || !q[0].isEmpty() || !q[1].isEmpty()) {
            while (i < n && arrival[i] <= t) {
                q[state[i]].add(i++);
            }
            if (!q[0].isEmpty() && !q[1].isEmpty()) {
                ans[q[st].poll()] = t;
            } else if (!q[0].isEmpty() || !q[1].isEmpty()) {
                st = q[0].isEmpty() ? 1 : 0;
                ans[q[st].poll()] = t;
            } else {
                st = 1;
            }
            ++t;
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
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        queue<int> q[2];
        int t = 0, i = 0, st = 1;
        vector<int> ans(n);

        while (i < n || !q[0].empty() || !q[1].empty()) {
            while (i < n && arrival[i] <= t) {
                q[state[i]].push(i++);
            }

            if (!q[0].empty() && !q[1].empty()) {
                ans[q[st].front()] = t;
                q[st].pop();
            } else if (!q[0].empty() || !q[1].empty()) {
                st = q[0].empty() ? 1 : 0;
                ans[q[st].front()] = t;
                q[st].pop();
            } else {
                st = 1;
            }

            ++t;
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func timeTaken(arrival []int, state []int) []int {
	n := len(arrival)
	q := [2][]int{}
	t, i, st := 0, 0, 1
	ans := make([]int, n)

	for i < n || len(q[0]) > 0 || len(q[1]) > 0 {
		for i < n && arrival[i] <= t {
			q[state[i]] = append(q[state[i]], i)
			i++
		}

		if len(q[0]) > 0 && len(q[1]) > 0 {
			ans[q[st][0]] = t
			q[st] = q[st][1:]
		} else if len(q[0]) > 0 || len(q[1]) > 0 {
			if len(q[0]) == 0 {
				st = 1
			} else {
				st = 0
			}
			ans[q[st][0]] = t
			q[st] = q[st][1:]
		} else {
			st = 1
		}

		t++
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function timeTaken(arrival: number[], state: number[]): number[] {
    const n = arrival.length;
    const q: number[][] = [[], []];
    let [t, i, st] = [0, 0, 1];
    const ans: number[] = Array(n).fill(0);

    while (i < n || q[0].length || q[1].length) {
        while (i < n && arrival[i] <= t) {
            q[state[i]].push(i++);
        }

        if (q[0].length && q[1].length) {
            ans[q[st][0]] = t;
            q[st].shift();
        } else if (q[0].length || q[1].length) {
            st = q[0].length ? 0 : 1;
            ans[q[st][0]] = t;
            q[st].shift();
        } else {
            st = 1;
        }

        t++;
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn time_taken(arrival: Vec<i32>, state: Vec<i32>) -> Vec<i32> {
        let n = arrival.len();
        let mut q = vec![VecDeque::new(), VecDeque::new()];
        let mut t = 0;
        let mut i = 0;
        let mut st = 1;
        let mut ans = vec![-1; n];

        while i < n || !q[0].is_empty() || !q[1].is_empty() {
            while i < n && arrival[i] <= t {
                q[state[i] as usize].push_back(i);
                i += 1;
            }

            if !q[0].is_empty() && !q[1].is_empty() {
                ans[*q[st].front().unwrap()] = t;
                q[st].pop_front();
            } else if !q[0].is_empty() || !q[1].is_empty() {
                st = if q[0].is_empty() { 1 } else { 0 };
                ans[*q[st].front().unwrap()] = t;
                q[st].pop_front();
            } else {
                st = 1;
            }

            t += 1;
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

<p><code>n</code> 个人，按从 <code>0</code> 到 <code>n - 1</code> 编号。现在有一扇门，每个人只能通过门进入或离开一次，耗时一秒。</p>

<p>给你一个 <strong>非递减顺序</strong> 排列的整数数组 <code>arrival</code> ，数组长度为 <code>n</code> ，其中 <code>arrival[i]</code> 是第 <code>i</code> 个人到达门前的时间。另给你一个长度为 <code>n</code> 的数组 <code>state</code> ，其中 <code>state[i]</code> 是 <code>0</code> 则表示第 <code>i</code> 个人希望进入这扇门，是 <code>1</code> 则表示 TA 想要离开这扇门。</p>

<p>如果 <strong>同时</strong> 有两个或更多人想要使用这扇门，则必须遵循以下规则：</p>

<ul>
	<li>如果前一秒 <strong>没有</strong> 使用门，那么想要 <strong>离开</strong> 的人会先离开。</li>
	<li>如果前一秒使用门 <strong>进入</strong> ，那么想要 <strong>进入</strong> 的人会先进入。</li>
	<li>如果前一秒使用门 <strong>离开</strong> ，那么想要 <strong>离开</strong> 的人会先离开。</li>
	<li>如果多个人都想朝同一方向走（都进入或都离开），编号最小的人会先通过门。</li>
</ul>

<p>返回一个长度为 <code>n</code> 的数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer[i]</code><em> </em>是第 <code>i</code> 个人通过门的时刻（秒）。</p>
<strong>注意：</strong>

<ul>
	<li>每秒只有一个人可以通过门。</li>
	<li>为遵循上述规则，一个人可以在到达门附近后等待，而不通过门进入或离开。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arrival = [0,1,1,2,4], state = [0,1,0,0,1]
<strong>输出：</strong>[0,3,1,2,4]
<strong>解释：</strong>每秒发生的情况如下：
- t = 0 ：第 0 个人是唯一一个想要进入的人，所以 TA 可以直接进入。
- t = 1 ：第 1 个人想要离开，第 2 个人想要进入。因为前一秒有人使用门进入，所以第 2 个人先进入。
- t = 2 ：第 1 个人还是想要离开，第 3 个人想要进入。因为前一秒有人使用门进入，所以第 3 个人先进入。
- t = 3 ：第 1 个人是唯一一个想要离开的人，所以 TA 可以直接离开。
- t = 4 ：第 4 个人是唯一一个想要进入的人，所以 TA 可以直接离开。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arrival = [0,0,0], state = [1,0,1]
<strong>输出：</strong>[0,2,1]
<strong>解释：</strong>每秒发生的情况如下：
- t = 0 ：第 1 个人想要进入，但是第 0 个人和第 2 个人都想要离开。因为前一秒没有使用门，所以想要离开的人会先离开。又因为第 0 个人的编号更小，所以 TA 先离开。
- t = 1 ：第 1 个人想要进入，第 2 个人想要离开。因为前一秒有人使用门离开，所以第 2 个人先离开。
- t = 2 ：第 1 个人是唯一一个想要进入的人，所以 TA 可以直接进入。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == arrival.length == state.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= arrival[i] &lt;= n</code></li>
	<li><code>arrival</code> 按 <strong>非递减顺序</strong> 排列</li>
	<li><code>state[i]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：队列 + 模拟

我们定义两个队列，其中 $q[0]$ 存放想要进入的人的编号，而 $q[1]$ 存放想要离开的人的编号。

我们维护一个时间 $t$，表示当前时间，一个状态 $st$，表示当前门的状态，当 $st = 1$ 表示门没使用或者上一秒有人离开，当 $st = 0$ 表示上一秒有人进入。初始时 $t = 0$，而 $st = 1$。

我们遍历数组 $\textit{arrival}$，对于每个人，如果当前时间 $t$ 小于等于该人到达门前的时间 $arrival[i]$，我们将该人的编号加入对应的队列 $q[\text{state}[i]]$ 中。

然后我们判断当前队列 $q[0]$ 和 $q[1]$ 是否都不为空，如果都不为空，我们将 $q[st]$ 队列的队首元素出队，并将当前时间 $t$ 赋值给该人的通过时间；如果只有一个队列不为空，我们根据哪个队列不为空，更新 $st$ 的值，然后将该队列的队首元素出队，并将当前时间 $t$ 赋值给该人的通过时间；如果两个队列都为空，我们将 $st$ 的值更新为 $1$，表示门没使用。

接下来，我们将时间 $t$ 自增 $1$，继续遍历数组 $\textit{arrival}$，直到所有人都通过门。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 表示数组 $\textit{arrival}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def timeTaken(self, arrival: List[int], state: List[int]) -> List[int]:
        q = [deque(), deque()]
        n = len(arrival)
        t = i = 0
        st = 1
        ans = [0] * n
        while i < n or q[0] or q[1]:
            while i < n and arrival[i] <= t:
                q[state[i]].append(i)
                i += 1
            if q[0] and q[1]:
                ans[q[st].popleft()] = t
            elif q[0] or q[1]:
                st = 0 if q[0] else 1
                ans[q[st].popleft()] = t
            else:
                st = 1
            t += 1
        return ans
```

#### Java

```java
class Solution {
    public int[] timeTaken(int[] arrival, int[] state) {
        Deque<Integer>[] q = new Deque[2];
        Arrays.setAll(q, i -> new ArrayDeque<>());
        int n = arrival.length;
        int t = 0, i = 0, st = 1;
        int[] ans = new int[n];
        while (i < n || !q[0].isEmpty() || !q[1].isEmpty()) {
            while (i < n && arrival[i] <= t) {
                q[state[i]].add(i++);
            }
            if (!q[0].isEmpty() && !q[1].isEmpty()) {
                ans[q[st].poll()] = t;
            } else if (!q[0].isEmpty() || !q[1].isEmpty()) {
                st = q[0].isEmpty() ? 1 : 0;
                ans[q[st].poll()] = t;
            } else {
                st = 1;
            }
            ++t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
        int n = arrival.size();
        queue<int> q[2];
        int t = 0, i = 0, st = 1;
        vector<int> ans(n);

        while (i < n || !q[0].empty() || !q[1].empty()) {
            while (i < n && arrival[i] <= t) {
                q[state[i]].push(i++);
            }

            if (!q[0].empty() && !q[1].empty()) {
                ans[q[st].front()] = t;
                q[st].pop();
            } else if (!q[0].empty() || !q[1].empty()) {
                st = q[0].empty() ? 1 : 0;
                ans[q[st].front()] = t;
                q[st].pop();
            } else {
                st = 1;
            }

            ++t;
        }

        return ans;
    }
};
```

#### Go

```go
func timeTaken(arrival []int, state []int) []int {
	n := len(arrival)
	q := [2][]int{}
	t, i, st := 0, 0, 1
	ans := make([]int, n)

	for i < n || len(q[0]) > 0 || len(q[1]) > 0 {
		for i < n && arrival[i] <= t {
			q[state[i]] = append(q[state[i]], i)
			i++
		}

		if len(q[0]) > 0 && len(q[1]) > 0 {
			ans[q[st][0]] = t
			q[st] = q[st][1:]
		} else if len(q[0]) > 0 || len(q[1]) > 0 {
			if len(q[0]) == 0 {
				st = 1
			} else {
				st = 0
			}
			ans[q[st][0]] = t
			q[st] = q[st][1:]
		} else {
			st = 1
		}

		t++
	}

	return ans
}
```

#### TypeScript

```ts
function timeTaken(arrival: number[], state: number[]): number[] {
    const n = arrival.length;
    const q: number[][] = [[], []];
    let [t, i, st] = [0, 0, 1];
    const ans: number[] = Array(n).fill(0);

    while (i < n || q[0].length || q[1].length) {
        while (i < n && arrival[i] <= t) {
            q[state[i]].push(i++);
        }

        if (q[0].length && q[1].length) {
            ans[q[st][0]] = t;
            q[st].shift();
        } else if (q[0].length || q[1].length) {
            st = q[0].length ? 0 : 1;
            ans[q[st][0]] = t;
            q[st].shift();
        } else {
            st = 1;
        }

        t++;
    }

    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn time_taken(arrival: Vec<i32>, state: Vec<i32>) -> Vec<i32> {
        let n = arrival.len();
        let mut q = vec![VecDeque::new(), VecDeque::new()];
        let mut t = 0;
        let mut i = 0;
        let mut st = 1;
        let mut ans = vec![-1; n];

        while i < n || !q[0].is_empty() || !q[1].is_empty() {
            while i < n && arrival[i] <= t {
                q[state[i] as usize].push_back(i);
                i += 1;
            }

            if !q[0].is_empty() && !q[1].is_empty() {
                ans[*q[st].front().unwrap()] = t;
                q[st].pop_front();
            } else if !q[0].is_empty() || !q[1].is_empty() {
                st = if q[0].is_empty() { 1 } else { 0 };
                ans[*q[st].front().unwrap()] = t;
                q[st].pop_front();
            } else {
                st = 1;
            }

            t += 1;
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

# [2535. 数组元素和与数字和的绝对差](https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array){#2535}

{{< tabs "2535" >}}

{{% tab "python" %}}
```python
class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        x = y = 0
        for v in nums:
            x += v
            while v:
                y += v % 10
                v //= 10
        return x - y
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int differenceOfSum(int[] nums) {
        int x = 0, y = 0;
        for (int v : nums) {
            x += v;
            for (; v > 0; v /= 10) {
                y += v % 10;
            }
        }
        return x - y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x = 0, y = 0;
        for (int v : nums) {
            x += v;
            for (; v; v /= 10) {
                y += v % 10;
            }
        }
        return x - y;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func differenceOfSum(nums []int) int {
	var x, y int
	for _, v := range nums {
		x += v
		for ; v > 0; v /= 10 {
			y += v % 10
		}
	}
	return x - y
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function differenceOfSum(nums: number[]): number {
    let [x, y] = [0, 0];
    for (let v of nums) {
        x += v;
        for (; v; v = Math.floor(v / 10)) {
            y += v % 10;
        }
    }
    return x - y;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
        let mut x = 0;
        let mut y = 0;

        for &v in &nums {
            x += v;
            let mut num = v;
            while num > 0 {
                y += num % 10;
                num /= 10;
            }
        }

        x - y
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int differenceOfSum(int* nums, int numsSize) {
    int x = 0, y = 0;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        x += v;
        while (v > 0) {
            y += v % 10;
            v /= 10;
        }
    }
    return x - y;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组 <code>nums</code> 。</p>

<ul>
	<li><strong>元素和</strong> 是 <code>nums</code> 中的所有元素相加求和。</li>
	<li><strong>数字和</strong> 是&nbsp;<code>nums</code> 中每一个元素的每一数位（重复数位需多次求和）相加求和。</li>
</ul>

<p>返回 <strong>元素和</strong> 与 <strong>数字和</strong> 的绝对差。</p>

<p><strong>注意：</strong>两个整数 <code>x</code> 和 <code>y</code> 的绝对差定义为 <code>|x - y|</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,15,6,3]
<strong>输出：</strong>9
<strong>解释：</strong>
nums 的元素和是 1 + 15 + 6 + 3 = 25 。
nums 的数字和是 1 + 1 + 5 + 6 + 3 = 16 。
元素和与数字和的绝对差是 |25 - 16| = 9 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>0
<strong>解释：</strong>
nums 的元素和是 1 + 2 + 3 + 4 = 10 。
nums 的数字和是 1 + 2 + 3 + 4 = 10 。
元素和与数字和的绝对差是 |10 - 10| = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 2000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历数组 $\textit{nums}$，计算元素和 $x$ 和数字和 $y$，最后返回 $|x - y|$ 即可。由于 $x$ 一定大于等于 $y$，所以我们也可以直接返回 $x - y$。

时间复杂度 $O(n \times \log_{10} M)$，其中 $n$ 和 $M$ 分别是数组 $\textit{nums}$ 的长度和数组中元素的最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        x = y = 0
        for v in nums:
            x += v
            while v:
                y += v % 10
                v //= 10
        return x - y
```

#### Java

```java
class Solution {
    public int differenceOfSum(int[] nums) {
        int x = 0, y = 0;
        for (int v : nums) {
            x += v;
            for (; v > 0; v /= 10) {
                y += v % 10;
            }
        }
        return x - y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int x = 0, y = 0;
        for (int v : nums) {
            x += v;
            for (; v; v /= 10) {
                y += v % 10;
            }
        }
        return x - y;
    }
};
```

#### Go

```go
func differenceOfSum(nums []int) int {
	var x, y int
	for _, v := range nums {
		x += v
		for ; v > 0; v /= 10 {
			y += v % 10
		}
	}
	return x - y
}
```

#### TypeScript

```ts
function differenceOfSum(nums: number[]): number {
    let [x, y] = [0, 0];
    for (let v of nums) {
        x += v;
        for (; v; v = Math.floor(v / 10)) {
            y += v % 10;
        }
    }
    return x - y;
}
```

#### Rust

```rust
impl Solution {
    pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
        let mut x = 0;
        let mut y = 0;

        for &v in &nums {
            x += v;
            let mut num = v;
            while num > 0 {
                y += num % 10;
                num /= 10;
            }
        }

        x - y
    }
}
```

#### C

```c
int differenceOfSum(int* nums, int numsSize) {
    int x = 0, y = 0;
    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        x += v;
        while (v > 0) {
            y += v % 10;
            v /= 10;
        }
    }
    return x - y;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2536. 子矩阵元素加 1](https://leetcode.cn/problems/increment-submatrices-by-one){#2536}

{{< tabs "2536" >}}

{{% tab "python" %}}
```python
class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        mat = [[0] * n for _ in range(n)]
        for x1, y1, x2, y2 in queries:
            mat[x1][y1] += 1
            if x2 + 1 < n:
                mat[x2 + 1][y1] -= 1
            if y2 + 1 < n:
                mat[x1][y2 + 1] -= 1
            if x2 + 1 < n and y2 + 1 < n:
                mat[x2 + 1][y2 + 1] += 1

        for i in range(n):
            for j in range(n):
                if i:
                    mat[i][j] += mat[i - 1][j]
                if j:
                    mat[i][j] += mat[i][j - 1]
                if i and j:
                    mat[i][j] -= mat[i - 1][j - 1]
        return mat
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] mat = new int[n][n];
        for (var q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            mat[x1][y1]++;
            if (x2 + 1 < n) {
                mat[x2 + 1][y1]--;
            }
            if (y2 + 1 < n) {
                mat[x1][y2 + 1]--;
            }
            if (x2 + 1 < n && y2 + 1 < n) {
                mat[x2 + 1][y2 + 1]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }
        return mat;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n));
        for (auto& q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            mat[x1][y1]++;
            if (x2 + 1 < n) {
                mat[x2 + 1][y1]--;
            }
            if (y2 + 1 < n) {
                mat[x1][y2 + 1]--;
            }
            if (x2 + 1 < n && y2 + 1 < n) {
                mat[x2 + 1][y2 + 1]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }
        return mat;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rangeAddQueries(n int, queries [][]int) [][]int {
	mat := make([][]int, n)
	for i := range mat {
		mat[i] = make([]int, n)
	}
	for _, q := range queries {
		x1, y1, x2, y2 := q[0], q[1], q[2], q[3]
		mat[x1][y1]++
		if x2+1 < n {
			mat[x2+1][y1]--
		}
		if y2+1 < n {
			mat[x1][y2+1]--
		}
		if x2+1 < n && y2+1 < n {
			mat[x2+1][y2+1]++
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i > 0 {
				mat[i][j] += mat[i-1][j]
			}
			if j > 0 {
				mat[i][j] += mat[i][j-1]
			}
			if i > 0 && j > 0 {
				mat[i][j] -= mat[i-1][j-1]
			}
		}
	}
	return mat
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数 <code>n</code> ，表示最初有一个 <code>n x n</code> 、下标从 <strong>0</strong> 开始的整数矩阵 <code>mat</code> ，矩阵中填满了 0 。</p>

<p>另给你一个二维整数数组 <code>query</code> 。针对每个查询 <code>query[i] = [row1<sub>i</sub>, col1<sub>i</sub>, row2<sub>i</sub>, col2<sub>i</sub>]</code> ，请你执行下述操作：</p>

<ul>
	<li>找出 <strong>左上角</strong> 为 <code>(row1<sub>i</sub>, col1<sub>i</sub>)</code> 且 <strong>右下角</strong> 为 <code>(row2<sub>i</sub>, col2<sub>i</sub>)</code> 的子矩阵，将子矩阵中的 <strong>每个元素</strong> 加 <code>1</code> 。也就是给所有满足 <code>row1<sub>i</sub> &lt;= x &lt;= row2<sub>i</sub></code> 和 <code>col1<sub>i</sub> &lt;= y &lt;= col2<sub>i</sub></code> 的 <code>mat[x][y]</code> 加 <code>1</code> 。</li>
</ul>

<p>返回执行完所有操作后得到的矩阵 <code>mat</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2536.Increment%20Submatrices%20by%20One/images/p2example11.png" style="width: 531px; height: 121px;" /></p>

<pre>
<strong>输入：</strong>n = 3, queries = [[1,1,2,2],[0,0,1,1]]
<strong>输出：</strong>[[1,1,0],[1,2,1],[0,1,1]]
<strong>解释：</strong>上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵、执行完第二个操作后的矩阵。
- 第一个操作：将左上角为 (1, 1) 且右下角为 (2, 2) 的子矩阵中的每个元素加 1 。 
- 第二个操作：将左上角为 (0, 0) 且右下角为 (1, 1) 的子矩阵中的每个元素加 1 。 
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2536.Increment%20Submatrices%20by%20One/images/p2example22.png" style="width: 261px; height: 82px;" /></p>

<pre>
<strong>输入：</strong>n = 2, queries = [[0,0,1,1]]
<strong>输出：</strong>[[1,1],[1,1]]
<strong>解释：</strong>上图所展示的分别是：初始矩阵、执行完第一个操作后的矩阵。 
- 第一个操作：将矩阵中的每个元素加 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 500</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= row1<sub>i</sub> &lt;= row2<sub>i</sub> &lt; n</code></li>
	<li><code>0 &lt;= col1<sub>i</sub> &lt;= col2<sub>i</sub> &lt; n</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二维差分

二维差分模板题。

```python
mat = [[0] * (n + 1) for _ in range(n + 1)]


def insert(x1, y1, x2, y2, c):
    mat[x1][y1] += c
    mat[x1][y2 + 1] -= c
    mat[x2 + 1][y1] -= c
    mat[x2 + 1][y2 + 1] += c


for i in range(1, n + 1):
    for j in range(1, n + 1):
        mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1]
```

时间复杂度 $O(m + n^2)$，其中 $m$ 和 $n$ 分别是 `queries` 的长度和给定的 $n$。忽略答案的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        mat = [[0] * n for _ in range(n)]
        for x1, y1, x2, y2 in queries:
            mat[x1][y1] += 1
            if x2 + 1 < n:
                mat[x2 + 1][y1] -= 1
            if y2 + 1 < n:
                mat[x1][y2 + 1] -= 1
            if x2 + 1 < n and y2 + 1 < n:
                mat[x2 + 1][y2 + 1] += 1

        for i in range(n):
            for j in range(n):
                if i:
                    mat[i][j] += mat[i - 1][j]
                if j:
                    mat[i][j] += mat[i][j - 1]
                if i and j:
                    mat[i][j] -= mat[i - 1][j - 1]
        return mat
```

#### Java

```java
class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] mat = new int[n][n];
        for (var q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            mat[x1][y1]++;
            if (x2 + 1 < n) {
                mat[x2 + 1][y1]--;
            }
            if (y2 + 1 < n) {
                mat[x1][y2 + 1]--;
            }
            if (x2 + 1 < n && y2 + 1 < n) {
                mat[x2 + 1][y2 + 1]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }
        return mat;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n));
        for (auto& q : queries) {
            int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
            mat[x1][y1]++;
            if (x2 + 1 < n) {
                mat[x2 + 1][y1]--;
            }
            if (y2 + 1 < n) {
                mat[x1][y2 + 1]--;
            }
            if (x2 + 1 < n && y2 + 1 < n) {
                mat[x2 + 1][y2 + 1]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) {
                    mat[i][j] += mat[i - 1][j];
                }
                if (j > 0) {
                    mat[i][j] += mat[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    mat[i][j] -= mat[i - 1][j - 1];
                }
            }
        }
        return mat;
    }
};
```

#### Go

```go
func rangeAddQueries(n int, queries [][]int) [][]int {
	mat := make([][]int, n)
	for i := range mat {
		mat[i] = make([]int, n)
	}
	for _, q := range queries {
		x1, y1, x2, y2 := q[0], q[1], q[2], q[3]
		mat[x1][y1]++
		if x2+1 < n {
			mat[x2+1][y1]--
		}
		if y2+1 < n {
			mat[x1][y2+1]--
		}
		if x2+1 < n && y2+1 < n {
			mat[x2+1][y2+1]++
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i > 0 {
				mat[i][j] += mat[i-1][j]
			}
			if j > 0 {
				mat[i][j] += mat[i][j-1]
			}
			if i > 0 && j > 0 {
				mat[i][j] -= mat[i-1][j-1]
			}
		}
	}
	return mat
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2537. 统计好子数组的数目](https://leetcode.cn/problems/count-the-number-of-good-subarrays){#2537}

{{< tabs "2537" >}}

{{% tab "python" %}}
```python
class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        cnt = Counter()
        ans = cur = 0
        i = 0
        for x in nums:
            cur += cnt[x]
            cnt[x] += 1
            while cur - cnt[nums[i]] + 1 >= k:
                cnt[nums[i]] -= 1
                cur -= cnt[nums[i]]
                i += 1
            if cur >= k:
                ans += i + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0, cur = 0;
        int i = 0;
        for (int x : nums) {
            cur += cnt.merge(x, 1, Integer::sum) - 1;
            while (cur - cnt.get(nums[i]) + 1 >= k) {
                cur -= cnt.merge(nums[i++], -1, Integer::sum);
            }
            if (cur >= k) {
                ans += i + 1;
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
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        long long cur = 0;
        int i = 0;
        for (int& x : nums) {
            cur += cnt[x]++;
            while (cur - cnt[nums[i]] + 1 >= k) {
                cur -= --cnt[nums[i++]];
            }
            if (cur >= k) {
                ans += i + 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countGood(nums []int, k int) int64 {
	cnt := map[int]int{}
	ans, cur := 0, 0
	i := 0
	for _, x := range nums {
		cur += cnt[x]
		cnt[x]++
		for cur-cnt[nums[i]]+1 >= k {
			cnt[nums[i]]--
			cur -= cnt[nums[i]]
			i++
		}
		if cur >= k {
			ans += i + 1
		}
	}
	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countGood(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    let [ans, cur, i] = [0, 0, 0];

    for (const x of nums) {
        const count = cnt.get(x) || 0;
        cur += count;
        cnt.set(x, count + 1);

        while (cur - (cnt.get(nums[i])! - 1) >= k) {
            const countI = cnt.get(nums[i])!;
            cnt.set(nums[i], countI - 1);
            cur -= countI - 1;
            i += 1;
        }

        if (cur >= k) {
            ans += i + 1;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let mut cnt = HashMap::new();
        let (mut ans, mut cur, mut i) = (0i64, 0i64, 0);

        for &x in &nums {
            cur += *cnt.get(&x).unwrap_or(&0);
            *cnt.entry(x).or_insert(0) += 1;

            while cur - (cnt[&nums[i]] - 1) >= k as i64 {
                *cnt.get_mut(&nums[i]).unwrap() -= 1;
                cur -= cnt[&nums[i]];
                i += 1;
            }

            if cur >= k as i64 {
                ans += (i + 1) as i64;
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

<p>给你一个整数数组 <code>nums</code>&nbsp;和一个整数 <code>k</code>&nbsp;，请你返回 <code>nums</code>&nbsp;中 <strong>好</strong>&nbsp;子数组的数目。</p>

<p>一个子数组 <code>arr</code>&nbsp;如果有 <strong>至少</strong>&nbsp;<code>k</code>&nbsp;对下标 <code>(i, j)</code>&nbsp;满足 <code>i &lt; j</code>&nbsp;且 <code>arr[i] == arr[j]</code>&nbsp;，那么称它是一个 <strong>好</strong>&nbsp;子数组。</p>

<p><strong>子数组</strong>&nbsp;是原数组中一段连续 <strong>非空</strong>&nbsp;的元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,1,1,1,1], k = 10
<b>输出：</b>1
<b>解释：</b>唯一的好子数组是这个数组本身。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [3,1,4,3,2,2,4], k = 2
<b>输出：</b>4
<b>解释：</b>总共有 4 个不同的好子数组：
- [3,1,4,3,2,2] 有 2 对。
- [3,1,4,3,2,2,4] 有 3 对。
- [1,4,3,2,2,4] 有 2 对。
- [4,3,2,2,4] 有 2 对。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 双指针

如果一个子数组中包含 $k$ 对相同的元素，那么这个子数组一定包含至少 $k$ 对相同的元素。

我们用一个哈希表 $\textit{cnt}$ 统计窗口内数组元素出现的次数，用 $\textit{cur}$ 统计窗口内相同元素的对数，用 $i$ 维护窗口的左端点。

遍历数组 $\textit{nums}$，我们将当前元素 $x$ 作为右端点，那么窗口内相同元素的对数将增加 $\textit{cnt}[x]$，同时将 $x$ 的出现次数加一，即 $\textit{cnt}[x] \leftarrow \textit{cnt}[x] + 1$。接下来，我们循环判断移出左端点后窗口内相同元素的对数是否大于等于 $k$，如果大于等于 $k$，那么我们将左端点元素的出现次数减一，即 $\textit{cnt}[\textit{nums}[i]] \leftarrow \textit{cnt}[\textit{nums}[i]] - 1$，同时将窗口内相同元素的对数减去 $\textit{cnt}[\textit{nums}[i]]$，即 $\textit{cur} \leftarrow \textit{cur} - \textit{cnt}[\textit{nums}[i]]$，同时将左端点右移，即 $i \leftarrow i + 1$。此时窗口左端点以及左侧的所有元素都可以作为当前右端点的左端点，因此答案加上 $i + 1$。

最后，我们返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        cnt = Counter()
        ans = cur = 0
        i = 0
        for x in nums:
            cur += cnt[x]
            cnt[x] += 1
            while cur - cnt[nums[i]] + 1 >= k:
                cnt[nums[i]] -= 1
                cur -= cnt[nums[i]]
                i += 1
            if cur >= k:
                ans += i + 1
        return ans
```

#### Java

```java
class Solution {
    public long countGood(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        long ans = 0, cur = 0;
        int i = 0;
        for (int x : nums) {
            cur += cnt.merge(x, 1, Integer::sum) - 1;
            while (cur - cnt.get(nums[i]) + 1 >= k) {
                cur -= cnt.merge(nums[i++], -1, Integer::sum);
            }
            if (cur >= k) {
                ans += i + 1;
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
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        long long cur = 0;
        int i = 0;
        for (int& x : nums) {
            cur += cnt[x]++;
            while (cur - cnt[nums[i]] + 1 >= k) {
                cur -= --cnt[nums[i++]];
            }
            if (cur >= k) {
                ans += i + 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countGood(nums []int, k int) int64 {
	cnt := map[int]int{}
	ans, cur := 0, 0
	i := 0
	for _, x := range nums {
		cur += cnt[x]
		cnt[x]++
		for cur-cnt[nums[i]]+1 >= k {
			cnt[nums[i]]--
			cur -= cnt[nums[i]]
			i++
		}
		if cur >= k {
			ans += i + 1
		}
	}
	return int64(ans)
}
```

#### TypeScript

```ts
function countGood(nums: number[], k: number): number {
    const cnt: Map<number, number> = new Map();
    let [ans, cur, i] = [0, 0, 0];

    for (const x of nums) {
        const count = cnt.get(x) || 0;
        cur += count;
        cnt.set(x, count + 1);

        while (cur - (cnt.get(nums[i])! - 1) >= k) {
            const countI = cnt.get(nums[i])!;
            cnt.set(nums[i], countI - 1);
            cur -= countI - 1;
            i += 1;
        }

        if (cur >= k) {
            ans += i + 1;
        }
    }

    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn count_good(nums: Vec<i32>, k: i32) -> i64 {
        let mut cnt = HashMap::new();
        let (mut ans, mut cur, mut i) = (0i64, 0i64, 0);

        for &x in &nums {
            cur += *cnt.get(&x).unwrap_or(&0);
            *cnt.entry(x).or_insert(0) += 1;

            while cur - (cnt[&nums[i]] - 1) >= k as i64 {
                *cnt.get_mut(&nums[i]).unwrap() -= 1;
                cur -= cnt[&nums[i]];
                i += 1;
            }

            if cur >= k as i64 {
                ans += (i + 1) as i64;
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

# [2538. 最大价值和与最小价值和的差值](https://leetcode.cn/problems/difference-between-maximum-and-minimum-price-sum){#2538}

{{< tabs "2538" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:
        def dfs(i, fa):
            a, b = price[i], 0
            for j in g[i]:
                if j != fa:
                    c, d = dfs(j, i)
                    nonlocal ans
                    ans = max(ans, a + d, b + c)
                    a = max(a, price[i] + c)
                    b = max(b, price[i] + d)
            return a, b

        g = defaultdict(list)
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
    private List<Integer>[] g;
    private long ans;
    private int[] price;

    public long maxOutput(int n, int[][] edges, int[] price) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        this.price = price;
        dfs(0, -1);
        return ans;
    }

    private long[] dfs(int i, int fa) {
        long a = price[i], b = 0;
        for (int j : g[i]) {
            if (j != fa) {
                var e = dfs(j, i);
                long c = e[0], d = e[1];
                ans = Math.max(ans, Math.max(a + d, b + c));
                a = Math.max(a, price[i] + c);
                b = Math.max(b, price[i] + d);
            }
        }
        return new long[] {a, b};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        using ll = long long;
        using pll = pair<ll, ll>;
        ll ans = 0;
        function<pll(int, int)> dfs = [&](int i, int fa) {
            ll a = price[i], b = 0;
            for (int j : g[i]) {
                if (j != fa) {
                    auto [c, d] = dfs(j, i);
                    ans = max({ans, a + d, b + c});
                    a = max(a, price[i] + c);
                    b = max(b, price[i] + d);
                }
            }
            return pll{a, b};
        };
        dfs(0, -1);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxOutput(n int, edges [][]int, price []int) int64 {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	type pair struct{ a, b int }
	ans := 0
	var dfs func(i, fa int) pair
	dfs = func(i, fa int) pair {
		a, b := price[i], 0
		for _, j := range g[i] {
			if j != fa {
				e := dfs(j, i)
				c, d := e.a, e.b
				ans = max(ans, max(a+d, b+c))
				a = max(a, price[i]+c)
				b = max(b, price[i]+d)
			}
		}
		return pair{a, b}
	}
	dfs(0, -1)
	return int64(ans)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code>&nbsp;个节点的无向无根图，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;。给你一个整数&nbsp;<code>n</code>&nbsp;和一个长度为 <code>n - 1</code>&nbsp;的二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示树中节点&nbsp;<code>a<sub>i</sub></code> 和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。</p>

<p>每个节点都有一个价值。给你一个整数数组&nbsp;<code>price</code>&nbsp;，其中&nbsp;<code>price[i]</code>&nbsp;是第 <code>i</code>&nbsp;个节点的价值。</p>

<p>一条路径的 <strong>价值和</strong>&nbsp;是这条路径上所有节点的价值之和。</p>

<p>你可以选择树中任意一个节点作为根节点&nbsp;<code>root</code>&nbsp;。选择 <code>root</code>&nbsp;为根的 <strong>开销</strong>&nbsp;是以 <code>root</code>&nbsp;为起点的所有路径中，<strong>价值和</strong>&nbsp;最大的一条路径与最小的一条路径的差值。</p>

<p>请你返回所有节点作为根节点的选择中，<strong>最大</strong>&nbsp;的 <strong>开销</strong>&nbsp;为多少。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2538.Difference%20Between%20Maximum%20and%20Minimum%20Price%20Sum/images/example14.png" style="width: 556px; height: 231px;" /></p>

<pre>
<b>输入：</b>n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
<b>输出：</b>24
<b>解释：</b>上图展示了以节点 2 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
- 第一条路径节点为 [2,1,3,4]：价值为 [7,8,6,10] ，价值和为 31 。
- 第二条路径节点为 [2] ，价值为 [7] 。
最大路径和与最小路径和的差值为 24 。24 是所有方案中的最大开销。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2538.Difference%20Between%20Maximum%20and%20Minimum%20Price%20Sum/images/p1_example2.png" style="width: 352px; height: 184px;" /></p>

<pre>
<b>输入：</b>n = 3, edges = [[0,1],[1,2]], price = [1,1,1]
<b>输出：</b>2
<b>解释：</b>上图展示了以节点 0 为根的树。左图（红色的节点）是最大价值和路径，右图（蓝色的节点）是最小价值和路径。
- 第一条路径包含节点 [0,1,2]：价值为 [1,1,1] ，价值和为 3 。
- 第二条路径节点为 [0] ，价值为 [1] 。
最大路径和与最小路径和的差值为 2 。2 是所有方案中的最大开销。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>edges</code> 表示一棵符合题面要求的树。</li>
	<li><code>price.length == n</code></li>
	<li><code>1 &lt;= price[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP

由于每个节点价值均为正整数，因此，以节点 $root$ 作为根节点的最小的一条路径就是 $root$ 节点本身，那么价值和最大的一条路径与最小的一条路径的差值就等价于去掉路径的一个端点。

我们设计一个函数 $dfs(i, fa)$，表示以节点 $i$ 为根节点的子树中，不去掉端点的最大路径和以及去掉端点的最大路径和。其中，$fa$ 表示节点 $i$ 的父节点。

函数 $dfs(i, fa)$ 的实现逻辑如下：

初始化 $a = price[i]$, $b = 0$，表示初始只有一个节点，不去掉端点的最大路径和为 $price[i]$，去掉端点的最大路径和为 $0$。

对于节点 $i$ 的每个子节点 $j$，如果 $j \ne fa$，则递归调用函数 $dfs(j, i)$，这里返回了以节点 $j$ 为根节点的子树中，不去掉端点的最大路径和以及去掉端点的最大路径和，记为 $c$ 和 $d$。此时答案有两种情况：

-   前面不去掉端点的最大路径和加上当前节点去掉端点的最大路径和，即 $a + d$；
-   前面去掉端点的最大路径和加上当前节点不去掉端点的最大路径和，即 $b + c$。

我们更新答案的最大值，即 $ans = \max(ans, a + d, b + c)$。

然后更新 $a$ 和 $b$，即 $a = \max(a, price[i] + c)$, $b = \max(b, price[i] + d)$，最后返回。

时间复杂度为 $O(n)$，空间复杂度为 $O(n)$。其中 $n$ 为节点个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:
        def dfs(i, fa):
            a, b = price[i], 0
            for j in g[i]:
                if j != fa:
                    c, d = dfs(j, i)
                    nonlocal ans
                    ans = max(ans, a + d, b + c)
                    a = max(a, price[i] + c)
                    b = max(b, price[i] + d)
            return a, b

        g = defaultdict(list)
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
    private List<Integer>[] g;
    private long ans;
    private int[] price;

    public long maxOutput(int n, int[][] edges, int[] price) {
        g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        this.price = price;
        dfs(0, -1);
        return ans;
    }

    private long[] dfs(int i, int fa) {
        long a = price[i], b = 0;
        for (int j : g[i]) {
            if (j != fa) {
                var e = dfs(j, i);
                long c = e[0], d = e[1];
                ans = Math.max(ans, Math.max(a + d, b + c));
                a = Math.max(a, price[i] + c);
                b = Math.max(b, price[i] + d);
            }
        }
        return new long[] {a, b};
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        using ll = long long;
        using pll = pair<ll, ll>;
        ll ans = 0;
        function<pll(int, int)> dfs = [&](int i, int fa) {
            ll a = price[i], b = 0;
            for (int j : g[i]) {
                if (j != fa) {
                    auto [c, d] = dfs(j, i);
                    ans = max({ans, a + d, b + c});
                    a = max(a, price[i] + c);
                    b = max(b, price[i] + d);
                }
            }
            return pll{a, b};
        };
        dfs(0, -1);
        return ans;
    }
};
```

#### Go

```go
func maxOutput(n int, edges [][]int, price []int) int64 {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	type pair struct{ a, b int }
	ans := 0
	var dfs func(i, fa int) pair
	dfs = func(i, fa int) pair {
		a, b := price[i], 0
		for _, j := range g[i] {
			if j != fa {
				e := dfs(j, i)
				c, d := e.a, e.b
				ans = max(ans, max(a+d, b+c))
				a = max(a, price[i]+c)
				b = max(b, price[i]+d)
			}
		}
		return pair{a, b}
	}
	dfs(0, -1)
	return int64(ans)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2539. 好子序列的个数 🔒](https://leetcode.cn/problems/count-the-number-of-good-subsequences){#2539}

{{< tabs "2539" >}}

{{% tab "python" %}}
```python
N = 10001
MOD = 10**9 + 7
f = [1] * N
g = [1] * N
for i in range(1, N):
    f[i] = f[i - 1] * i % MOD
    g[i] = pow(f[i], MOD - 2, MOD)


def comb(n, k):
    return f[n] * g[k] * g[n - k] % MOD


class Solution:
    def countGoodSubsequences(self, s: str) -> int:
        cnt = Counter(s)
        ans = 0
        for i in range(1, max(cnt.values()) + 1):
            x = 1
            for v in cnt.values():
                if v >= i:
                    x = x * (comb(v, i) + 1) % MOD
            ans = (ans + x - 1) % MOD
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int N = 10001;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] F = new long[N];
    private static final long[] G = new long[N];

    static {
        F[0] = 1;
        G[0] = 1;
        for (int i = 1; i < N; ++i) {
            F[i] = F[i - 1] * i % MOD;
            G[i] = qmi(F[i], MOD - 2, MOD);
        }
    }

    public static long qmi(long a, long k, long p) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = res * a % p;
            }
            k >>= 1;
            a = a * a % p;
        }
        return res;
    }

    public static long comb(int n, int k) {
        return (F[n] * G[k] % MOD) * G[n - k] % MOD;
    }

    public int countGoodSubsequences(String s) {
        int[] cnt = new int[26];
        int mx = 1;
        for (int i = 0; i < s.length(); ++i) {
            mx = Math.max(mx, ++cnt[s.charAt(i) - 'a']);
        }
        long ans = 0;
        for (int i = 1; i <= mx; ++i) {
            long x = 1;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] >= i) {
                    x = x * (comb(cnt[j], i) + 1) % MOD;
                }
            }
            ans = (ans + x - 1) % MOD;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
int N = 10001;
int MOD = 1e9 + 7;
long f[10001];
long g[10001];

long qmi(long a, long k, long p) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

int init = []() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2, MOD);
    }
    return 0;
}();

int comb(int n, int k) {
    return (f[n] * g[k] % MOD) * g[n - k] % MOD;
}

class Solution {
public:
    int countGoodSubsequences(string s) {
        int cnt[26]{};
        int mx = 1;
        for (char& c : s) {
            mx = max(mx, ++cnt[c - 'a']);
        }
        long ans = 0;
        for (int i = 1; i <= mx; ++i) {
            long x = 1;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] >= i) {
                    x = (x * (comb(cnt[j], i) + 1)) % MOD;
                }
            }
            ans = (ans + x - 1) % MOD;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const n = 1e4 + 1
const mod = 1e9 + 7

var f = make([]int, n)
var g = make([]int, n)

func qmi(a, k, p int) int {
	res := 1
	for k != 0 {
		if k&1 == 1 {
			res = res * a % p
		}
		k >>= 1
		a = a * a % p
	}
	return res
}

func init() {
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
		g[i] = qmi(f[i], mod-2, mod)
	}
}

func comb(n, k int) int {
	return (f[n] * g[k] % mod) * g[n-k] % mod
}

func countGoodSubsequences(s string) (ans int) {
	cnt := [26]int{}
	mx := 1
	for _, c := range s {
		cnt[c-'a']++
		mx = max(mx, cnt[c-'a'])
	}
	for i := 1; i <= mx; i++ {
		x := 1
		for _, v := range cnt {
			if v >= i {
				x = (x * (comb(v, i) + 1)) % mod
			}
		}
		ans = (ans + x - 1) % mod
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

<p>如果字符串的某个 <strong>子序列</strong> 不为空，且其中每一个字符出现的频率都相同，就认为该子序列是一个好子序列。</p>

<p>给你一个字符串&nbsp;<code>s</code> ，请你统计并返回它的好子序列的个数。由于答案的值可能非常大，请返回对 <code>10<sup>9</sup> + 7</code> 取余的结果作为答案。</p>

<p>字符串的 <strong>子序列</strong> 是指，通过删除一些（也可以不删除）字符且不改变剩余字符相对位置所组成的新字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aabb"
<strong>输出：</strong>11
<strong>解释：</strong>s 的子序列的总数为 <code>2<sup>4 </sup>= 16 。其中，有 5 个子序列不是好子序列，分别是 </code>"<em><strong>aab</strong></em>b"，"a<em><strong>abb</strong></em>"，"<strong><em>a</em></strong>a<em><strong>bb</strong></em>"，"<em><strong>aa</strong></em>b<em><strong>b</strong></em>" 以及空字符串。因此，好子序列的个数为 16 <code>- 5 = 11</code> 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "leet"
<strong>输出：</strong>12
<strong>解释：</strong>s 的子序列的总数为 <code>2<sup>4 </sup>= 16 。</code>其中，<code>有 4 个子序列不是好子序列，分别是 </code>"<em><strong>lee</strong></em>t"，"l<em><strong>eet</strong></em>"，"<em><strong>leet</strong></em>" 以及空字符串。因此，好子序列的个数为 16 <code>- 4 = 12</code> 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcd"
<strong>输出：</strong>15
<strong>解释：</strong>s 所有非空子序列均为好子序列。因此，好子序列的个数为 16<code> - 1 = 15</code> 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 组合计数

由于题目说的是子序列中字母出现的次数，因此，我们可以先用一个数组 $cnt$ 统计字符串 $s$ 中每个字母出现的次数，记最大的次数为 $mx$。

接下来，我们在 $[1,2..mx]$ 范围内枚举子序列中字母出现的次数 $i$，然后枚举所有出现过的字母，如果该字母 $c$ 的出现次数 $cnt[c]$ 大于等于 $i$，那么我们可以从这 $cnt[c]$ 个相同字母中选择其中 $i$ 个，也可以一个都不选，那么当前字母的可选方案数就是 $comb(cnt[c], i) + 1$，将所有可选方案数相乘，可以得到当前次数的所有子序列次数，将次数减去 $1$ 累加到答案中。

那么问题的关键在于如何快速求出 $comb(n, k)$，我们可以用逆元来求解，具体实现见代码。

时间复杂度 $O(n \times C)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 是字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
N = 10001
MOD = 10**9 + 7
f = [1] * N
g = [1] * N
for i in range(1, N):
    f[i] = f[i - 1] * i % MOD
    g[i] = pow(f[i], MOD - 2, MOD)


def comb(n, k):
    return f[n] * g[k] * g[n - k] % MOD


class Solution:
    def countGoodSubsequences(self, s: str) -> int:
        cnt = Counter(s)
        ans = 0
        for i in range(1, max(cnt.values()) + 1):
            x = 1
            for v in cnt.values():
                if v >= i:
                    x = x * (comb(v, i) + 1) % MOD
            ans = (ans + x - 1) % MOD
        return ans
```

#### Java

```java
class Solution {
    private static final int N = 10001;
    private static final int MOD = (int) 1e9 + 7;
    private static final long[] F = new long[N];
    private static final long[] G = new long[N];

    static {
        F[0] = 1;
        G[0] = 1;
        for (int i = 1; i < N; ++i) {
            F[i] = F[i - 1] * i % MOD;
            G[i] = qmi(F[i], MOD - 2, MOD);
        }
    }

    public static long qmi(long a, long k, long p) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) == 1) {
                res = res * a % p;
            }
            k >>= 1;
            a = a * a % p;
        }
        return res;
    }

    public static long comb(int n, int k) {
        return (F[n] * G[k] % MOD) * G[n - k] % MOD;
    }

    public int countGoodSubsequences(String s) {
        int[] cnt = new int[26];
        int mx = 1;
        for (int i = 0; i < s.length(); ++i) {
            mx = Math.max(mx, ++cnt[s.charAt(i) - 'a']);
        }
        long ans = 0;
        for (int i = 1; i <= mx; ++i) {
            long x = 1;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] >= i) {
                    x = x * (comb(cnt[j], i) + 1) % MOD;
                }
            }
            ans = (ans + x - 1) % MOD;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
int N = 10001;
int MOD = 1e9 + 7;
long f[10001];
long g[10001];

long qmi(long a, long k, long p) {
    long res = 1;
    while (k != 0) {
        if ((k & 1) == 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = a * a % p;
    }
    return res;
}

int init = []() {
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i % MOD;
        g[i] = qmi(f[i], MOD - 2, MOD);
    }
    return 0;
}();

int comb(int n, int k) {
    return (f[n] * g[k] % MOD) * g[n - k] % MOD;
}

class Solution {
public:
    int countGoodSubsequences(string s) {
        int cnt[26]{};
        int mx = 1;
        for (char& c : s) {
            mx = max(mx, ++cnt[c - 'a']);
        }
        long ans = 0;
        for (int i = 1; i <= mx; ++i) {
            long x = 1;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] >= i) {
                    x = (x * (comb(cnt[j], i) + 1)) % MOD;
                }
            }
            ans = (ans + x - 1) % MOD;
        }
        return ans;
    }
};
```

#### Go

```go
const n = 1e4 + 1
const mod = 1e9 + 7

var f = make([]int, n)
var g = make([]int, n)

func qmi(a, k, p int) int {
	res := 1
	for k != 0 {
		if k&1 == 1 {
			res = res * a % p
		}
		k >>= 1
		a = a * a % p
	}
	return res
}

func init() {
	f[0], g[0] = 1, 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
		g[i] = qmi(f[i], mod-2, mod)
	}
}

func comb(n, k int) int {
	return (f[n] * g[k] % mod) * g[n-k] % mod
}

func countGoodSubsequences(s string) (ans int) {
	cnt := [26]int{}
	mx := 1
	for _, c := range s {
		cnt[c-'a']++
		mx = max(mx, cnt[c-'a'])
	}
	for i := 1; i <= mx; i++ {
		x := 1
		for _, v := range cnt {
			if v >= i {
				x = (x * (comb(v, i) + 1)) % mod
			}
		}
		ans = (ans + x - 1) % mod
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
