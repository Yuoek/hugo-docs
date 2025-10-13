---
title: "0910_最小差值 II"
date: 2025-10-08T18:36:43+08:00
weight: 2
tags: [二分查找, 二叉树, 分治, 动态规划, 单调队列, 博弈, 双指针, 哈希表, 图, 基数排序, 堆（优先队列）, 字符串, 广度优先搜索, 归并排序, 拓扑排序, 排序, 数学, 数组, 数论, 树, 桶排序, 计数, 计数排序, 记忆化搜索, 设计, 贪心, 队列]
---

{{< markmap >}}
### [0910_最小差值 II](#910)
#### [贪心](#910)
#### [数组](#910)
#### [数学](#910)
#### [排序](#910)
### [0911_在线选举](#911)
#### [设计](#911)
#### [数组](#911)
#### [哈希表](#911)
#### [二分查找](#911)
### [0912_排序数组](#912)
#### [数组](#912)
#### [分治](#912)
#### [桶排序](#912)
#### [计数排序](#912)
#### [基数排序](#912)
#### [排序](#912)
#### [堆（优先队列）](#912)
#### [归并排序](#912)
### [0913_猫和老鼠](#913)
#### [图](#913)
#### [拓扑排序](#913)
#### [记忆化搜索](#913)
#### [数学](#913)
#### [动态规划](#913)
#### [博弈](#913)
### [0914_卡牌分组](#914)
#### [数组](#914)
#### [哈希表](#914)
#### [数学](#914)
#### [计数](#914)
#### [数论](#914)
### [0915_分割数组](#915)
#### [数组](#915)
### [0916_单词子集](#916)
#### [数组](#916)
#### [哈希表](#916)
#### [字符串](#916)
### [0917_仅仅反转字母](#917)
#### [双指针](#917)
#### [字符串](#917)
### [0918_环形子数组的最大和](#918)
#### [队列](#918)
#### [数组](#918)
#### [分治](#918)
#### [动态规划](#918)
#### [单调队列](#918)
### [0919_完全二叉树插入器](#919)
#### [树](#919)
#### [广度优先搜索](#919)
#### [设计](#919)
#### [二叉树](#919)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0910_最小差值 II
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 排序
---
### 0911_在线选举
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 二分查找
---
### 0912_排序数组
___
#### 数组
___
#### 分治
___
#### 桶排序
___
#### 计数排序
___
#### 基数排序
___
#### 排序
___
#### 堆（优先队列）
___
#### 归并排序
---
### 0913_猫和老鼠
___
#### 图
___
#### 拓扑排序
___
#### 记忆化搜索
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 0914_卡牌分组
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 计数
___
#### 数论
---
### 0915_分割数组
___
#### 数组
---
### 0916_单词子集
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0917_仅仅反转字母
___
#### 双指针
___
#### 字符串
---
### 0918_环形子数组的最大和
___
#### 队列
___
#### 数组
___
#### 分治
___
#### 动态规划
___
#### 单调队列
---
### 0919_完全二叉树插入器
___
#### 树
___
#### 广度优先搜索
___
#### 设计
___
#### 二叉树
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 二叉树 | 分治 |
| 动态规划 | 单调队列 | 博弈 |
| 双指针 | 哈希表 | 图 |
| 基数排序 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 归并排序 | 拓扑排序 |
| 排序 | 数学 | 数组 |
| 数论 | 树 | 桶排序 |
| 计数 | 计数排序 | 记忆化搜索 |
| 设计 | 贪心 | 队列 |

# [910. 最小差值 II](https://leetcode.cn/problems/smallest-range-ii){#910}

{{< tabs "910" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(1, len(nums)):
            mi = min(nums[0] + k, nums[i] - k)
            mx = max(nums[i - 1] + k, nums[-1] - k)
            ans = min(ans, mx - mi)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; ++i) {
            int mi = Math.min(nums[0] + k, nums[i] - k);
            int mx = Math.max(nums[i - 1] + k, nums[n - 1] - k);
            ans = Math.min(ans, mx - mi);
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
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; ++i) {
            int mi = min(nums[0] + k, nums[i] - k);
            int mx = max(nums[i - 1] + k, nums[n - 1] - k);
            ans = min(ans, mx - mi);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestRangeII(nums []int, k int) int {
	sort.Ints(nums)
	n := len(nums)
	ans := nums[n-1] - nums[0]
	for i := 1; i < n; i++ {
		mi := min(nums[0]+k, nums[i]-k)
		mx := max(nums[i-1]+k, nums[n-1]-k)
		ans = min(ans, mx-mi)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestRangeII(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = nums.at(-1)! - nums[0];
    for (let i = 1; i < nums.length; ++i) {
        const mi = Math.min(nums[0] + k, nums[i] - k);
        const mx = Math.max(nums.at(-1)! - k, nums[i - 1] + k);
        ans = Math.min(ans, mx - mi);
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

<p>给你一个整数数组 <code>nums</code>，和一个整数&nbsp;<code>k</code> 。</p>

<p>对于每个下标 <code>i</code>（<code>0 &lt;= i &lt; nums.length</code>），将 <code>nums[i]</code> 变成<strong> </strong> <code>nums[i] + k</code> 或 <code>nums[i] - k</code> 。</p>

<p><code>nums</code> 的 <strong>分数</strong> 是 <code>nums</code> 中最大元素和最小元素的差值。</p>

<p>在更改每个下标对应的值之后，返回 <code>nums</code> 的最小 <strong>分数</strong> 。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], k = 0
<strong>输出：</strong>0
<strong>解释：</strong>分数 = max(nums) - min(nums) = 1 - 1 = 0 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,10], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>将数组变为 [2, 8] 。分数 = max(nums) - min(nums) = 8 - 2 = 6 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,6], k = 3
<strong>输出：</strong>3
<strong>解释：</strong>将数组变为 [4, 6, 3] 。分数 = max(nums) - min(nums) = 6 - 3 = 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 枚举

根据题目要求，我们需要求数组中的元素最大值与最小值差值的最小值。每个元素可以加上或者减去 $k$，因此我们可以将数组中的元素分为两部分，一部分加上 $k$，一部分减去 $k$。那么，我们应该将数组中的较大值减去 $k$，较小值加上 $k$，这样才能保证最大值与最小值的差值最小。

因此，我们可以先将数组排序，然后枚举数组中的每个元素，将其分为两部分，一部分加上 $k$，一部分减去 $k$，并计算最大值与最小值的差值。最后，取所有差值中的最小值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(1, len(nums)):
            mi = min(nums[0] + k, nums[i] - k)
            mx = max(nums[i - 1] + k, nums[-1] - k)
            ans = min(ans, mx - mi)
        return ans
```

#### Java

```java
class Solution {
    public int smallestRangeII(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; ++i) {
            int mi = Math.min(nums[0] + k, nums[i] - k);
            int mx = Math.max(nums[i - 1] + k, nums[n - 1] - k);
            ans = Math.min(ans, mx - mi);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        for (int i = 1; i < n; ++i) {
            int mi = min(nums[0] + k, nums[i] - k);
            int mx = max(nums[i - 1] + k, nums[n - 1] - k);
            ans = min(ans, mx - mi);
        }
        return ans;
    }
};
```

#### Go

```go
func smallestRangeII(nums []int, k int) int {
	sort.Ints(nums)
	n := len(nums)
	ans := nums[n-1] - nums[0]
	for i := 1; i < n; i++ {
		mi := min(nums[0]+k, nums[i]-k)
		mx := max(nums[i-1]+k, nums[n-1]-k)
		ans = min(ans, mx-mi)
	}
	return ans
}
```

#### TypeScript

```ts
function smallestRangeII(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    let ans = nums.at(-1)! - nums[0];
    for (let i = 1; i < nums.length; ++i) {
        const mi = Math.min(nums[0] + k, nums[i] - k);
        const mx = Math.max(nums.at(-1)! - k, nums[i - 1] + k);
        ans = Math.min(ans, mx - mi);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [911. 在线选举](https://leetcode.cn/problems/online-election){#911}

{{< tabs "911" >}}

{{% tab "python" %}}
```python
class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        cnt = Counter()
        self.times = times
        self.wins = []
        cur = 0
        for p in persons:
            cnt[p] += 1
            if cnt[cur] <= cnt[p]:
                cur = p
            self.wins.append(cur)

    def q(self, t: int) -> int:
        i = bisect_right(self.times, t) - 1
        return self.wins[i]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TopVotedCandidate {
    private int[] times;
    private int[] wins;

    public TopVotedCandidate(int[] persons, int[] times) {
        int n = persons.length;
        wins = new int[n];
        this.times = times;
        int[] cnt = new int[n];
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            ++cnt[p];
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            wins[i] = cur;
        }
    }

    public int q(int t) {
        int i = Arrays.binarySearch(times, t + 1);
        i = i < 0 ? -i - 2 : i - 1;
        return wins[i];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        this->times = times;
        wins.resize(n);
        vector<int> cnt(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            ++cnt[p];
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            wins[i] = cur;
        }
    }

    int q(int t) {
        int i = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return wins[i];
    }

private:
    vector<int> times;
    vector<int> wins;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type TopVotedCandidate struct {
	times []int
	wins  []int
}

func Constructor(persons []int, times []int) TopVotedCandidate {
	n := len(persons)
	wins := make([]int, n)
	cnt := make([]int, n)
	cur := 0
	for i, p := range persons {
		cnt[p]++
		if cnt[cur] <= cnt[p] {
			cur = p
		}
		wins[i] = cur
	}
	return TopVotedCandidate{times, wins}
}

func (this *TopVotedCandidate) Q(t int) int {
	i := sort.SearchInts(this.times, t+1) - 1
	return this.wins[i]
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * obj := Constructor(persons, times);
 * param_1 := obj.Q(t);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class TopVotedCandidate {
    private times: number[];
    private wins: number[];

    constructor(persons: number[], times: number[]) {
        const n = persons.length;
        this.times = times;
        this.wins = new Array<number>(n).fill(0);
        const cnt: Array<number> = new Array<number>(n).fill(0);
        let cur = 0;
        for (let i = 0; i < n; ++i) {
            const p = persons[i];
            cnt[p]++;
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            this.wins[i] = cur;
        }
    }

    q(t: number): number {
        const search = (t: number): number => {
            let l = 0,
                r = this.times.length;
            while (l < r) {
                const mid = (l + r) >> 1;
                if (this.times[mid] > t) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        const i = search(t) - 1;
        return this.wins[i];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * var obj = new TopVotedCandidate(persons, times)
 * var param_1 = obj.q(t)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数数组 <code>persons</code> 和 <code>times</code> 。在选举中，第&nbsp;<code>i</code>&nbsp;张票是在时刻为&nbsp;<code>times[i]</code>&nbsp;时投给候选人 <code>persons[i]</code>&nbsp;的。</p>

<p>对于发生在时刻 <code>t</code> 的每个查询，需要找出在&nbsp;<code>t</code> 时刻在选举中领先的候选人的编号。</p>

<p>在&nbsp;<code>t</code> 时刻投出的选票也将被计入我们的查询之中。在平局的情况下，最近获得投票的候选人将会获胜。</p>

<p>实现 <code>TopVotedCandidate</code> 类：</p>

<ul>
	<li><code>TopVotedCandidate(int[] persons, int[] times)</code> 使用&nbsp;<code>persons</code> 和 <code>times</code> 数组初始化对象。</li>
	<li><code>int q(int t)</code> 根据前面描述的规则，返回在时刻 <code>t</code> 在选举中领先的候选人的编号。</li>
</ul>
&nbsp;

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
<strong>输出：</strong>
[null, 0, 1, 1, 0, 0, 1]

<strong>解释：</strong>
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // 返回 0 ，在时刻 3 ，票数分布为 [0] ，编号为 0 的候选人领先。
topVotedCandidate.q(12); // 返回 1 ，在时刻 12 ，票数分布为 [0,1,1] ，编号为 1 的候选人领先。
topVotedCandidate.q(25); // 返回 1 ，在时刻 25 ，票数分布为 [0,1,1,0,0,1] ，编号为 1 的候选人领先。（在平局的情况下，1 是最近获得投票的候选人）。
topVotedCandidate.q(15); // 返回 0
topVotedCandidate.q(24); // 返回 0
topVotedCandidate.q(8); // 返回 1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= persons.length &lt;= 5000</code></li>
	<li><code>times.length == persons.length</code></li>
	<li><code>0 &lt;= persons[i] &lt; persons.length</code></li>
	<li><code>0 &lt;= times[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>times</code> 是一个严格递增的有序数组</li>
	<li><code>times[0] &lt;= t &lt;= 10<sup>9</sup></code></li>
	<li>每个测试用例最多调用 <code>10<sup>4</sup></code> 次 <code>q</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们可以在初始化时，记录每个时刻的胜者，然后在查询时，使用二分查找找到小于等于 $t$ 的最大时刻，返回该时刻的胜者。

初始化时，我们使用一个计数器 $cnt$ 记录每个候选人的票数，用一个变量 $cur$ 记录当前领先的候选人。然后遍历每个时刻，更新 $cnt$ 和 $cur$，并记录每个时刻的胜者。

查询时，我们使用二分查找找到小于等于 $t$ 的最大时刻，返回该时刻的胜者。

时间复杂度方面，初始化时，我们需要 $O(n)$ 的时间，查询时，我们需要 $O(\log n)$ 的时间。空间复杂度为 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        cnt = Counter()
        self.times = times
        self.wins = []
        cur = 0
        for p in persons:
            cnt[p] += 1
            if cnt[cur] <= cnt[p]:
                cur = p
            self.wins.append(cur)

    def q(self, t: int) -> int:
        i = bisect_right(self.times, t) - 1
        return self.wins[i]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
```

#### Java

```java
class TopVotedCandidate {
    private int[] times;
    private int[] wins;

    public TopVotedCandidate(int[] persons, int[] times) {
        int n = persons.length;
        wins = new int[n];
        this.times = times;
        int[] cnt = new int[n];
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            ++cnt[p];
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            wins[i] = cur;
        }
    }

    public int q(int t) {
        int i = Arrays.binarySearch(times, t + 1);
        i = i < 0 ? -i - 2 : i - 1;
        return wins[i];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
```

#### C++

```cpp
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        this->times = times;
        wins.resize(n);
        vector<int> cnt(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            ++cnt[p];
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            wins[i] = cur;
        }
    }

    int q(int t) {
        int i = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return wins[i];
    }

private:
    vector<int> times;
    vector<int> wins;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
```

#### Go

```go
type TopVotedCandidate struct {
	times []int
	wins  []int
}

func Constructor(persons []int, times []int) TopVotedCandidate {
	n := len(persons)
	wins := make([]int, n)
	cnt := make([]int, n)
	cur := 0
	for i, p := range persons {
		cnt[p]++
		if cnt[cur] <= cnt[p] {
			cur = p
		}
		wins[i] = cur
	}
	return TopVotedCandidate{times, wins}
}

func (this *TopVotedCandidate) Q(t int) int {
	i := sort.SearchInts(this.times, t+1) - 1
	return this.wins[i]
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * obj := Constructor(persons, times);
 * param_1 := obj.Q(t);
 */
```

#### TypeScript

```ts
class TopVotedCandidate {
    private times: number[];
    private wins: number[];

    constructor(persons: number[], times: number[]) {
        const n = persons.length;
        this.times = times;
        this.wins = new Array<number>(n).fill(0);
        const cnt: Array<number> = new Array<number>(n).fill(0);
        let cur = 0;
        for (let i = 0; i < n; ++i) {
            const p = persons[i];
            cnt[p]++;
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            this.wins[i] = cur;
        }
    }

    q(t: number): number {
        const search = (t: number): number => {
            let l = 0,
                r = this.times.length;
            while (l < r) {
                const mid = (l + r) >> 1;
                if (this.times[mid] > t) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        const i = search(t) - 1;
        return this.wins[i];
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * var obj = new TopVotedCandidate(persons, times)
 * var param_1 = obj.q(t)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [912. 排序数组](https://leetcode.cn/problems/sort-an-array){#912}

{{< tabs "912" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(l, r):
            if l >= r:
                return
            mid = (l + r) >> 1
            merge_sort(l, mid)
            merge_sort(mid + 1, r)
            i, j = l, mid + 1
            tmp = []
            while i <= mid and j <= r:
                if nums[i] <= nums[j]:
                    tmp.append(nums[i])
                    i += 1
                else:
                    tmp.append(nums[j])
                    j += 1
            if i <= mid:
                tmp.extend(nums[i : mid + 1])
            if j <= r:
                tmp.extend(nums[j : r + 1])
            for i in range(l, r + 1):
                nums[i] = tmp[i - l]

        merge_sort(0, len(nums) - 1)
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;

    public int[] sortArray(int[] nums) {
        this.nums = nums;
        mergeSort(0, nums.length - 1);
        return nums;
    }

    private void mergeSort(int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        int[] tmp = new int[r - l + 1];
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l; i <= r; ++i) {
            nums[i] = tmp[i - l];
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> merge_sort = [&](int l, int r) {
            if (l >= r) {
                return;
            }
            int mid = (l + r) >> 1;
            merge_sort(l, mid);
            merge_sort(mid + 1, r);
            int i = l, j = mid + 1, k = 0;
            int tmp[r - l + 1];
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    tmp[k++] = nums[i++];
                } else {
                    tmp[k++] = nums[j++];
                }
            }
            while (i <= mid) {
                tmp[k++] = nums[i++];
            }
            while (j <= r) {
                tmp[k++] = nums[j++];
            }
            for (i = l; i <= r; ++i) {
                nums[i] = tmp[i - l];
            }
        };
        merge_sort(0, nums.size() - 1);
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortArray(nums []int) []int {
	mergeSort(nums, 0, len(nums)-1)
	return nums
}

func mergeSort(nums []int, l, r int) {
	if l >= r {
		return
	}
	mid := (l + r) >> 1
	mergeSort(nums, l, mid)
	mergeSort(nums, mid+1, r)
	i, j, k := l, mid+1, 0
	tmp := make([]int, r-l+1)
	for i <= mid && j <= r {
		if nums[i] <= nums[j] {
			tmp[k] = nums[i]
			i++
		} else {
			tmp[k] = nums[j]
			j++
		}
		k++
	}
	for ; i <= mid; i++ {
		tmp[k] = nums[i]
		k++
	}
	for ; j <= r; j++ {
		tmp[k] = nums[j]
		k++
	}
	for i = l; i <= r; i++ {
		nums[i] = tmp[i-l]
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortArray(nums: number[]): number[] {
    function mergetSort(l: number, r: number) {
        if (l >= r) {
            return;
        }
        const mid = (l + r) >> 1;
        mergetSort(l, mid);
        mergetSort(mid + 1, r);
        let [i, j, k] = [l, mid + 1, 0];
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l, j = 0; i <= r; ++i, ++j) {
            nums[i] = tmp[j];
        }
    }
    const n = nums.length;
    let tmp = new Array(n).fill(0);
    mergetSort(0, n - 1);
    return nums;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function (nums) {
    function mergetSort(l, r) {
        if (l >= r) {
            return;
        }
        const mid = (l + r) >> 1;
        mergetSort(l, mid);
        mergetSort(mid + 1, r);
        let [i, j, k] = [l, mid + 1, 0];
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l, j = 0; i <= r; ++i, ++j) {
            nums[i] = tmp[j];
        }
    }
    const n = nums.length;
    let tmp = new Array(n).fill(0);
    mergetSort(0, n - 1);
    return nums;
};
```
{{% /tab %}}
{{% tab "rs" %}}
```rs
impl Solution {
    pub fn sort_array(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        Self::quick_sort(&mut nums, 0, n - 1);
        return nums;
    }

    fn quick_sort(nums: &mut Vec<i32>, left: usize, right: usize) {
        if left >= right {
            return;
        }
        let mut i = left as i32 - 1;
        let mut j = right as i32 + 1;
        let pivot = nums[left];
        while i < j {
            loop {
                i += 1;
                if nums[i as usize] >= pivot {
                    break;
                }
            }
            loop {
                j -= 1;
                if nums[j as usize] <= pivot {
                    break;
                }
            }
            if i < j {
                nums.swap(i as usize, j as usize);
            }
        }
        Self::quick_sort(nums, left, j as usize);
        Self::quick_sort(nums, j as usize + 1, right);
    }
}
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun sortArray(nums: IntArray): IntArray {
        fun quickSort(left: Int, right: Int) {
            if (left >= right) {
                return
            }
            var i = left - 1
            var j = right + 1
            val pivot = nums[left]
            while (i < j) {
                while (nums[++i] < pivot) ;
                while (nums[--j] > pivot) ;
                if (i < j) {
                    val temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
                }
            }
            quickSort(left, j)
            quickSort(j + 1, right)
        }
        quickSort(0, nums.size - 1)
        return nums
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>nums</code>，请你将该数组升序排列。</p>

<p>你必须在 <strong>不使用任何内置函数</strong> 的情况下解决问题，时间复杂度为 <code>O(nlog(n))</code>，并且空间复杂度尽可能小。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,2,3,1]
<strong>输出：</strong>[1,2,3,5]
<strong>解释：</strong>数组排序后，某些数字的位置没有改变（例如，2 和 3），而其他数字的位置发生了改变（例如，1 和 5）。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,1,1,2,0,0]
<strong>输出：</strong>[0,0,1,1,2,5]
<strong>解释：</strong>请注意，nums 的值不一定唯一。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-5 * 10<sup>4</sup> &lt;= nums[i] &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快速排序

快速排序是一种高效的排序算法。它的基本思想是通过一趟排序将待排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quick_sort(l, r):
            if l >= r:
                return
            x = nums[randint(l, r)]
            i, j, k = l - 1, r + 1, l
            while k < j:
                if nums[k] < x:
                    nums[i + 1], nums[k] = nums[k], nums[i + 1]
                    i, k = i + 1, k + 1
                elif nums[k] > x:
                    j -= 1
                    nums[j], nums[k] = nums[k], nums[j]
                else:
                    k = k + 1
            quick_sort(l, i)
            quick_sort(j, r)

        quick_sort(0, len(nums) - 1)
        return nums
```

#### Java

```java
class Solution {
    private int[] nums;

    public int[] sortArray(int[] nums) {
        this.nums = nums;
        quikcSort(0, nums.length - 1);
        return nums;
    }

    private void quikcSort(int l, int r) {
        if (l >= r) {
            return;
        }
        int x = nums[(l + r) >> 1];
        int i = l - 1, j = r + 1;
        while (i < j) {
            while (nums[++i] < x) {
            }
            while (nums[--j] > x) {
            }
            if (i < j) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
        }
        quikcSort(l, j);
        quikcSort(j + 1, r);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> quick_sort = [&](int l, int r) {
            if (l >= r) {
                return;
            }
            int i = l - 1, j = r + 1;
            int x = nums[(l + r) >> 1];
            while (i < j) {
                while (nums[++i] < x) {
                }
                while (nums[--j] > x) {
                }
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
            quick_sort(l, j);
            quick_sort(j + 1, r);
        };
        quick_sort(0, nums.size() - 1);
        return nums;
    }
};
```

#### Go

```go
func sortArray(nums []int) []int {
	quickSort(nums, 0, len(nums)-1)
	return nums
}

func quickSort(nums []int, l, r int) {
	if l >= r {
		return
	}
	i, j := l-1, r+1
	x := nums[(l+r)>>1]
	for i < j {
		for {
			i++
			if nums[i] >= x {
				break
			}
		}
		for {
			j--
			if nums[j] <= x {
				break
			}
		}
		if i < j {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	quickSort(nums, l, j)
	quickSort(nums, j+1, r)
}
```

#### TypeScript

```ts
function sortArray(nums: number[]): number[] {
    function quickSort(l: number, r: number) {
        if (l >= r) {
            return;
        }
        let i = l - 1;
        let j = r + 1;
        const x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) {
                [nums[i], nums[j]] = [nums[j], nums[i]];
            }
        }
        quickSort(l, j);
        quickSort(j + 1, r);
    }
    const n = nums.length;
    quickSort(0, n - 1);
    return nums;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function (nums) {
    function quickSort(l, r) {
        if (l >= r) {
            return;
        }
        let i = l - 1;
        let j = r + 1;
        const x = nums[(l + r) >> 1];
        while (i < j) {
            while (nums[++i] < x);
            while (nums[--j] > x);
            if (i < j) {
                [nums[i], nums[j]] = [nums[j], nums[i]];
            }
        }
        quickSort(l, j);
        quickSort(j + 1, r);
    }
    const n = nums.length;
    quickSort(0, n - 1);
    return nums;
};
```

#### Rust

```rs
impl Solution {
    pub fn sort_array(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        Self::quick_sort(&mut nums, 0, n - 1);
        return nums;
    }

    fn quick_sort(nums: &mut Vec<i32>, left: usize, right: usize) {
        if left >= right {
            return;
        }
        let mut i = left as i32 - 1;
        let mut j = right as i32 + 1;
        let pivot = nums[left];
        while i < j {
            loop {
                i += 1;
                if nums[i as usize] >= pivot {
                    break;
                }
            }
            loop {
                j -= 1;
                if nums[j as usize] <= pivot {
                    break;
                }
            }
            if i < j {
                nums.swap(i as usize, j as usize);
            }
        }
        Self::quick_sort(nums, left, j as usize);
        Self::quick_sort(nums, j as usize + 1, right);
    }
}
```

#### Kotlin

```kotlin
class Solution {
    fun sortArray(nums: IntArray): IntArray {
        fun quickSort(left: Int, right: Int) {
            if (left >= right) {
                return
            }
            var i = left - 1
            var j = right + 1
            val pivot = nums[left]
            while (i < j) {
                while (nums[++i] < pivot) ;
                while (nums[--j] > pivot) ;
                if (i < j) {
                    val temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
                }
            }
            quickSort(left, j)
            quickSort(j + 1, right)
        }
        quickSort(0, nums.size - 1)
        return nums
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：归并排序

归并排序是一种分治算法，其思想是将待排序的数据序列不断地折半拆分，直到每个数据块只有一个元素为止，然后再按照拆分的顺序将每个数据块两两合并，在合并的过程中进行排序，最终得到一个有序的数据序列。

归并排序是一种稳定的排序算法，时间复杂度为 $O(n \times \log n)$，空间复杂度为 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge_sort(l, r):
            if l >= r:
                return
            mid = (l + r) >> 1
            merge_sort(l, mid)
            merge_sort(mid + 1, r)
            i, j = l, mid + 1
            tmp = []
            while i <= mid and j <= r:
                if nums[i] <= nums[j]:
                    tmp.append(nums[i])
                    i += 1
                else:
                    tmp.append(nums[j])
                    j += 1
            if i <= mid:
                tmp.extend(nums[i : mid + 1])
            if j <= r:
                tmp.extend(nums[j : r + 1])
            for i in range(l, r + 1):
                nums[i] = tmp[i - l]

        merge_sort(0, len(nums) - 1)
        return nums
```

#### Java

```java
class Solution {
    private int[] nums;

    public int[] sortArray(int[] nums) {
        this.nums = nums;
        quickSort(0, nums.length - 1);
        return nums;
    }

    private void quickSort(int l, int r) {
        if (l >= r) {
            return;
        }
        int i = l - 1, j = r + 1, k = l;
        int x = nums[(l + r) >> 1];
        while (k < j) {
            if (nums[k] < x) {
                swap(++i, k++);
            } else if (nums[k] > x) {
                swap(--j, k);
            } else {
                ++k;
            }
        }
        quickSort(l, i);
        quickSort(j, r);
    }

    private void swap(int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        function<void(int, int)> merge_sort = [&](int l, int r) {
            if (l >= r) {
                return;
            }
            int mid = (l + r) >> 1;
            merge_sort(l, mid);
            merge_sort(mid + 1, r);
            int i = l, j = mid + 1, k = 0;
            int tmp[r - l + 1];
            while (i <= mid && j <= r) {
                if (nums[i] <= nums[j]) {
                    tmp[k++] = nums[i++];
                } else {
                    tmp[k++] = nums[j++];
                }
            }
            while (i <= mid) {
                tmp[k++] = nums[i++];
            }
            while (j <= r) {
                tmp[k++] = nums[j++];
            }
            for (i = l; i <= r; ++i) {
                nums[i] = tmp[i - l];
            }
        };
        merge_sort(0, nums.size() - 1);
        return nums;
    }
};
```

#### Go

```go
func sortArray(nums []int) []int {
	mergeSort(nums, 0, len(nums)-1)
	return nums
}

func mergeSort(nums []int, l, r int) {
	if l >= r {
		return
	}
	mid := (l + r) >> 1
	mergeSort(nums, l, mid)
	mergeSort(nums, mid+1, r)
	i, j, k := l, mid+1, 0
	tmp := make([]int, r-l+1)
	for i <= mid && j <= r {
		if nums[i] <= nums[j] {
			tmp[k] = nums[i]
			i++
		} else {
			tmp[k] = nums[j]
			j++
		}
		k++
	}
	for ; i <= mid; i++ {
		tmp[k] = nums[i]
		k++
	}
	for ; j <= r; j++ {
		tmp[k] = nums[j]
		k++
	}
	for i = l; i <= r; i++ {
		nums[i] = tmp[i-l]
	}
}
```

#### TypeScript

```ts
function sortArray(nums: number[]): number[] {
    function mergetSort(l: number, r: number) {
        if (l >= r) {
            return;
        }
        const mid = (l + r) >> 1;
        mergetSort(l, mid);
        mergetSort(mid + 1, r);
        let [i, j, k] = [l, mid + 1, 0];
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l, j = 0; i <= r; ++i, ++j) {
            nums[i] = tmp[j];
        }
    }
    const n = nums.length;
    let tmp = new Array(n).fill(0);
    mergetSort(0, n - 1);
    return nums;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function (nums) {
    function mergetSort(l, r) {
        if (l >= r) {
            return;
        }
        const mid = (l + r) >> 1;
        mergetSort(l, mid);
        mergetSort(mid + 1, r);
        let [i, j, k] = [l, mid + 1, 0];
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l, j = 0; i <= r; ++i, ++j) {
            nums[i] = tmp[j];
        }
    }
    const n = nums.length;
    let tmp = new Array(n).fill(0);
    mergetSort(0, n - 1);
    return nums;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Java

```java
class Solution {
    private int[] nums;

    public int[] sortArray(int[] nums) {
        this.nums = nums;
        mergeSort(0, nums.length - 1);
        return nums;
    }

    private void mergeSort(int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) >> 1;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        int[] tmp = new int[r - l + 1];
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l; i <= r; ++i) {
            nums[i] = tmp[i - l];
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [913. 猫和老鼠](https://leetcode.cn/problems/cat-and-mouse){#913}

{{< tabs "913" >}}

{{% tab "python" %}}
```python
HOLE, MOUSE_START, CAT_START = 0, 1, 2
MOUSE_TURN, CAT_TURN = 0, 1
MOUSE_WIN, CAT_WIN, TIE = 1, 2, 0


class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        def get_prev_states(state):
            m, c, t = state
            pt = t ^ 1
            pre = []
            if pt == CAT_TURN:
                for pc in graph[c]:
                    if pc != HOLE:
                        pre.append((m, pc, pt))
            else:
                for pm in graph[m]:
                    pre.append((pm, c, pt))
            return pre

        n = len(graph)
        ans = [[[0, 0] for _ in range(n)] for _ in range(n)]
        degree = [[[0, 0] for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(1, n):
                degree[i][j][MOUSE_TURN] = len(graph[i])
                degree[i][j][CAT_TURN] = len(graph[j])
            for j in graph[HOLE]:
                degree[i][j][CAT_TURN] -= 1
        q = deque()
        for j in range(1, n):
            ans[0][j][MOUSE_TURN] = ans[0][j][CAT_TURN] = MOUSE_WIN
            q.append((0, j, MOUSE_TURN))
            q.append((0, j, CAT_TURN))
        for i in range(1, n):
            ans[i][i][MOUSE_TURN] = ans[i][i][CAT_TURN] = CAT_WIN
            q.append((i, i, MOUSE_TURN))
            q.append((i, i, CAT_TURN))
        while q:
            state = q.popleft()
            t = ans[state[0]][state[1]][state[2]]
            for prev_state in get_prev_states(state):
                pm, pc, pt = prev_state
                if ans[pm][pc][pt] == TIE:
                    win = (t == MOUSE_WIN and pt == MOUSE_TURN) or (
                        t == CAT_WIN and pt == CAT_TURN
                    )
                    if win:
                        ans[pm][pc][pt] = t
                        q.append(prev_state)
                    else:
                        degree[pm][pc][pt] -= 1
                        if degree[pm][pc][pt] == 0:
                            ans[pm][pc][pt] = t
                            q.append(prev_state)
        return ans[MOUSE_START][CAT_START][MOUSE_TURN]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[][] g;
    private int[][][] ans;
    private int[][][] degree;

    private static final int HOLE = 0, MOUSE_START = 1, CAT_START = 2;
    private static final int MOUSE_TURN = 0, CAT_TURN = 1;
    private static final int MOUSE_WIN = 1, CAT_WIN = 2, TIE = 0;

    public int catMouseGame(int[][] graph) {
        n = graph.length;
        g = graph;
        ans = new int[n][n][2];
        degree = new int[n][n][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                degree[i][j][MOUSE_TURN] = g[i].length;
                degree[i][j][CAT_TURN] = g[j].length;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j : g[HOLE]) {
                --degree[i][j][CAT_TURN];
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        for (int j = 1; j < n; ++j) {
            ans[0][j][MOUSE_TURN] = MOUSE_WIN;
            ans[0][j][CAT_TURN] = MOUSE_WIN;
            q.offer(new int[] {0, j, MOUSE_TURN});
            q.offer(new int[] {0, j, CAT_TURN});
        }
        for (int i = 1; i < n; ++i) {
            ans[i][i][MOUSE_TURN] = CAT_WIN;
            ans[i][i][CAT_TURN] = CAT_WIN;
            q.offer(new int[] {i, i, MOUSE_TURN});
            q.offer(new int[] {i, i, CAT_TURN});
        }
        while (!q.isEmpty()) {
            int[] state = q.poll();
            int t = ans[state[0]][state[1]][state[2]];
            List<int[]> prevStates = getPrevStates(state);
            for (var prevState : prevStates) {
                int pm = prevState[0], pc = prevState[1], pt = prevState[2];
                if (ans[pm][pc][pt] == TIE) {
                    boolean win
                        = (t == MOUSE_WIN && pt == MOUSE_TURN) || (t == CAT_WIN && pt == CAT_TURN);
                    if (win) {
                        ans[pm][pc][pt] = t;
                        q.offer(prevState);
                    } else {
                        if (--degree[pm][pc][pt] == 0) {
                            ans[pm][pc][pt] = t;
                            q.offer(prevState);
                        }
                    }
                }
            }
        }
        return ans[MOUSE_START][CAT_START][MOUSE_TURN];
    }

    private List<int[]> getPrevStates(int[] state) {
        List<int[]> pre = new ArrayList<>();
        int m = state[0], c = state[1], t = state[2];
        int pt = t ^ 1;
        if (pt == CAT_TURN) {
            for (int pc : g[c]) {
                if (pc != HOLE) {
                    pre.add(new int[] {m, pc, pt});
                }
            }
        } else {
            for (int pm : g[m]) {
                pre.add(new int[] {pm, c, pt});
            }
        }
        return pre;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
const int HOLE = 0;
const int MOUSE_START = 1;
const int CAT_START = 2;
const int MOUSE_TURN = 0;
const int CAT_TURN = 1;
const int MOUSE_WIN = 1;
const int CAT_WIN = 2;
const int TIE = 0;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans[n][n][2];
        int degree[n][n][2];
        memset(ans, 0, sizeof ans);
        memset(degree, 0, sizeof degree);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                degree[i][j][MOUSE_TURN] = graph[i].size();
                degree[i][j][CAT_TURN] = graph[j].size();
            }
            for (int j : graph[HOLE]) {
                --degree[i][j][CAT_TURN];
            }
        }
        auto getPrevStates = [&](int m, int c, int t) {
            int pt = t ^ 1;
            vector<tuple<int, int, int>> pre;
            if (pt == CAT_TURN) {
                for (int pc : graph[c]) {
                    if (pc != HOLE) {
                        pre.emplace_back(m, pc, pt);
                    }
                }
            } else {
                for (int pm : graph[m]) {
                    pre.emplace_back(pm, c, pt);
                }
            }
            return pre;
        };
        queue<tuple<int, int, int>> q;
        for (int j = 1; j < n; ++j) {
            ans[0][j][MOUSE_TURN] = ans[0][j][CAT_TURN] = MOUSE_WIN;
            q.emplace(0, j, MOUSE_TURN);
            q.emplace(0, j, CAT_TURN);
        }
        for (int i = 1; i < n; ++i) {
            ans[i][i][MOUSE_TURN] = ans[i][i][CAT_TURN] = CAT_WIN;
            q.emplace(i, i, MOUSE_TURN);
            q.emplace(i, i, CAT_TURN);
        }
        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int x = ans[m][c][t];
            for (auto [pm, pc, pt] : getPrevStates(m, c, t)) {
                if (ans[pm][pc][pt] == TIE) {
                    bool win = (x == MOUSE_WIN && pt == MOUSE_TURN) || (x == CAT_WIN && pt == CAT_TURN);
                    if (win) {
                        ans[pm][pc][pt] = x;
                        q.emplace(pm, pc, pt);
                    } else {
                        if (--degree[pm][pc][pt] == 0) {
                            ans[pm][pc][pt] = x;
                            q.emplace(pm, pc, pt);
                        }
                    }
                }
            }
        }
        return ans[MOUSE_START][CAT_START][MOUSE_TURN];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
const (
	hole       = 0
	mouseStart = 1
	catStart   = 2
	mouseTurn  = 0
	catTurn    = 1
	mouseWin   = 1
	catWin     = 2
	tie        = 0
)

func catMouseGame(graph [][]int) int {
	ans := [50][50][2]int{}
	degree := [50][50][2]int{}
	n := len(graph)
	for i := 0; i < n; i++ {
		for j := 1; j < n; j++ {
			degree[i][j][mouseTurn] = len(graph[i])
			degree[i][j][catTurn] = len(graph[j])
		}
		for _, j := range graph[hole] {
			degree[i][j][catTurn]--
		}
	}
	type tuple struct{ m, c, t int }
	q := []tuple{}
	for j := 1; j < n; j++ {
		ans[0][j][mouseTurn], ans[0][j][catTurn] = mouseWin, mouseWin
		q = append(q, tuple{0, j, mouseTurn})
		q = append(q, tuple{0, j, catTurn})
	}
	for i := 1; i < n; i++ {
		ans[i][i][mouseTurn], ans[i][i][catTurn] = catWin, catWin
		q = append(q, tuple{i, i, mouseTurn})
		q = append(q, tuple{i, i, catTurn})
	}
	getPrevStates := func(m, c, t int) []tuple {
		pre := []tuple{}
		pt := t ^ 1
		if pt == catTurn {
			for _, pc := range graph[c] {
				if pc != hole {
					pre = append(pre, tuple{m, pc, pt})
				}
			}
		} else {
			for _, pm := range graph[m] {
				pre = append(pre, tuple{pm, c, pt})
			}
		}
		return pre
	}
	for len(q) > 0 {
		state := q[0]
		m, c, t := state.m, state.c, state.t
		q = q[1:]
		x := ans[m][c][t]
		for _, prevState := range getPrevStates(m, c, t) {
			pm, pc, pt := prevState.m, prevState.c, prevState.t
			if ans[pm][pc][pt] == tie {
				win := (x == mouseWin && pt == mouseTurn) || (x == catWin && pt == catTurn)
				if win {
					ans[pm][pc][pt] = x
					q = append(q, tuple{pm, pc, pt})
				} else {
					degree[pm][pc][pt]--
					if degree[pm][pc][pt] == 0 {
						ans[pm][pc][pt] = x
						q = append(q, tuple{pm, pc, pt})
					}
				}
			}
		}
	}
	return ans[mouseStart][catStart][mouseTurn]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function catMouseGame(graph: number[][]): number {
    const [HOLE, MOUSE_START, CAT_START] = [0, 1, 2];
    const [MOUSE_TURN, CAT_TURN] = [0, 1];
    const [MOUSE_WIN, CAT_WIN, TIE] = [1, 2, 0];

    function get_prev_states(state: [number, number, number]): [number, number, number][] {
        const [m, c, t] = state;
        const pt = t ^ 1;
        const pre = [] as [number, number, number][];

        if (pt === CAT_TURN) {
            for (const pc of graph[c]) {
                if (pc !== HOLE) {
                    pre.push([m, pc, pt]);
                }
            }
        } else {
            for (const pm of graph[m]) {
                pre.push([pm, c, pt]);
            }
        }
        return pre;
    }

    const n = graph.length;
    const ans: number[][][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => [TIE, TIE]),
    );
    const degree: number[][][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => [0, 0]),
    );

    for (let i = 0; i < n; i++) {
        for (let j = 1; j < n; j++) {
            degree[i][j][MOUSE_TURN] = graph[i].length;
            degree[i][j][CAT_TURN] = graph[j].length;
        }
        for (const j of graph[HOLE]) {
            degree[i][j][CAT_TURN] -= 1;
        }
    }

    const q: [number, number, number][] = [];

    for (let j = 1; j < n; j++) {
        ans[0][j][MOUSE_TURN] = ans[0][j][CAT_TURN] = MOUSE_WIN;
        q.push([0, j, MOUSE_TURN], [0, j, CAT_TURN]);
    }
    for (let i = 1; i < n; i++) {
        ans[i][i][MOUSE_TURN] = ans[i][i][CAT_TURN] = CAT_WIN;
        q.push([i, i, MOUSE_TURN], [i, i, CAT_TURN]);
    }

    while (q.length > 0) {
        const state = q.shift()!;
        const [m, c, t] = state;
        const result = ans[m][c][t];

        for (const prev_state of get_prev_states(state)) {
            const [pm, pc, pt] = prev_state;
            if (ans[pm][pc][pt] === TIE) {
                const win =
                    (result === MOUSE_WIN && pt === MOUSE_TURN) ||
                    (result === CAT_WIN && pt === CAT_TURN);
                if (win) {
                    ans[pm][pc][pt] = result;
                    q.push(prev_state);
                } else {
                    degree[pm][pc][pt] -= 1;
                    if (degree[pm][pc][pt] === 0) {
                        ans[pm][pc][pt] = result;
                        q.push(prev_state);
                    }
                }
            }
        }
    }

    return ans[MOUSE_START][CAT_START][MOUSE_TURN];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int n;
    private int[][] g;
    private int[,,] ans;
    private int[,,] degree;

    private const int HOLE = 0, MOUSE_START = 1, CAT_START = 2;
    private const int MOUSE_TURN = 0, CAT_TURN = 1;
    private const int MOUSE_WIN = 1, CAT_WIN = 2, TIE = 0;

    public int CatMouseGame(int[][] graph) {
        n = graph.Length;
        g = graph;
        ans = new int[n, n, 2];
        degree = new int[n, n, 2];

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                degree[i, j, MOUSE_TURN] = g[i].Length;
                degree[i, j, CAT_TURN] = g[j].Length;
            }
        }

        for (int i = 0; i < n; i++) {
            foreach (int j in g[HOLE]) {
                degree[i, j, CAT_TURN]--;
            }
        }

        Queue<int[]> q = new Queue<int[]>();

        for (int j = 1; j < n; j++) {
            ans[0, j, MOUSE_TURN] = MOUSE_WIN;
            ans[0, j, CAT_TURN] = MOUSE_WIN;
            q.Enqueue(new int[] { 0, j, MOUSE_TURN });
            q.Enqueue(new int[] { 0, j, CAT_TURN });
        }

        for (int i = 1; i < n; i++) {
            ans[i, i, MOUSE_TURN] = CAT_WIN;
            ans[i, i, CAT_TURN] = CAT_WIN;
            q.Enqueue(new int[] { i, i, MOUSE_TURN });
            q.Enqueue(new int[] { i, i, CAT_TURN });
        }

        while (q.Count > 0) {
            int[] state = q.Dequeue();
            int t = ans[state[0], state[1], state[2]];
            List<int[]> prevStates = GetPrevStates(state);

            foreach (var prevState in prevStates) {
                int pm = prevState[0], pc = prevState[1], pt = prevState[2];
                if (ans[pm, pc, pt] == TIE) {
                    bool win = (t == MOUSE_WIN && pt == MOUSE_TURN) || (t == CAT_WIN && pt == CAT_TURN);
                    if (win) {
                        ans[pm, pc, pt] = t;
                        q.Enqueue(prevState);
                    } else {
                        if (--degree[pm, pc, pt] == 0) {
                            ans[pm, pc, pt] = t;
                            q.Enqueue(prevState);
                        }
                    }
                }
            }
        }

        return ans[MOUSE_START, CAT_START, MOUSE_TURN];
    }

    private List<int[]> GetPrevStates(int[] state) {
        List<int[]> pre = new List<int[]>();
        int m = state[0], c = state[1], t = state[2];
        int pt = t ^ 1;

        if (pt == CAT_TURN) {
            foreach (int pc in g[c]) {
                if (pc != HOLE) {
                    pre.Add(new int[] { m, pc, pt });
                }
            }
        } else {
            foreach (int pm in g[m]) {
                pre.Add(new int[] { pm, c, pt });
            }
        }

        return pre;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>两位玩家分别扮演猫和老鼠，在一张 <strong>无向</strong> 图上进行游戏，两人轮流行动。</p>

<p>图的形式是：<code>graph[a]</code> 是一个列表，由满足&nbsp;<code>ab</code> 是图中的一条边的所有节点 <code>b</code> 组成。</p>

<p>老鼠从节点 <code>1</code> 开始，第一个出发；猫从节点 <code>2</code> 开始，第二个出发。在节点 <code>0</code> 处有一个洞。</p>

<p>在每个玩家的行动中，他们 <strong>必须</strong> 沿着图中与所在当前位置连通的一条边移动。例如，如果老鼠在节点 <code>1</code> ，那么它必须移动到 <code>graph[1]</code> 中的任一节点。</p>

<p>此外，猫无法移动到洞中（节点 <code>0</code>）。</p>

<p>然后，游戏在出现以下三种情形之一时结束：</p>

<ul>
	<li>如果猫和老鼠出现在同一个节点，猫获胜。</li>
	<li>如果老鼠到达洞中，老鼠获胜。</li>
	<li>如果某一位置重复出现（即，玩家的位置和移动顺序都与上一次行动相同），游戏平局。</li>
</ul>

<p>给你一张图 <code>graph</code> ，并假设两位玩家都都以最佳状态参与游戏：</p>

<ul>
	<li>如果老鼠获胜，则返回&nbsp;<code>1</code>；</li>
	<li>如果猫获胜，则返回 <code>2</code>；</li>
	<li>如果平局，则返回 <code>0</code> 。</li>
</ul>
&nbsp;

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0913.Cat%20and%20Mouse/images/cat1.jpg" style="width: 300px; height: 300px;" />
<pre>
<strong>输入：</strong>graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
<strong>输出：</strong>0
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0913.Cat%20and%20Mouse/images/cat2.jpg" style="width: 200px; height: 200px;" />
<pre>
<strong>输入：</strong>graph = [[1,3],[0],[3],[0,2]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= graph.length &lt;= 50</code></li>
	<li><code>1&nbsp;&lt;= graph[i].length &lt; graph.length</code></li>
	<li><code>0 &lt;= graph[i][j] &lt; graph.length</code></li>
	<li><code>graph[i][j] != i</code></li>
	<li><code>graph[i]</code> 互不相同</li>
	<li>猫和老鼠在游戏中总是可以移动</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

根据题目描述，游戏中的状态由老鼠的位置、猫的位置和移动方决定。当状态为以下情况，可以直接确定胜负：

-   当猫和老鼠的位置相同时，猫获胜，这是猫的必胜状态，老鼠的必败状态。
-   当老鼠位于洞时，老鼠获胜，这是老鼠的必胜状态，猫的必败状态。

为了得到初始状态的游戏结果，需要从边界状态开始遍历所有的状态。每个状态包含老鼠的位置、猫的位置和移动方，根据当前状态可以得到上一轮的所有可能状态，上一轮状态的移动方和当前状态的移动方相反，上一轮状态的移动方在上一轮状态的位置和当前状态的位置不同。

我们用元组 $(m, c, t)$ 表示本轮的状态，用 $(pm, pc, pt)$ 表示上一轮可能的状态，那么上一轮的所有可能状态有：

-   如果本轮的移动方是老鼠，那么上一轮的移动方是猫，上一轮的老鼠位置是本轮老鼠位置，上一轮的猫位置是本轮猫位置的所有邻接点。
-   如果本轮的移动方是猫，那么上一轮的移动方是老鼠，上一轮的猫位置是本轮猫位置，上一轮的老鼠位置是本轮老鼠位置的所有邻接点。

初始时，除了边界状态以外，其他所有状态的结果都是未知的。我们从边界状态开始，对于每个状态，得到上一轮的所有可能状态并更新结果，更新的逻辑如下：

1. 如果上一轮的移动方与本轮的获胜方相同，那么上一轮的移动方可以到达当前状态并获胜，直接更新上一轮的状态为本轮的获胜方。
1. 如果上一轮的移动方与本轮的获胜方不同，且上一轮的移动方可以到达的所有状态都是上一轮的移动方的必败状态，那么我们将上一轮的状态更新为本轮的获胜方。

对于第 $2$ 个更新逻辑，我们需要记录每个状态的度。初始时，每个状态的度表示该状态的移动方可以移动到的结点数，即移动方所在节点的相邻结点数，如果移动方是猫且所在结点与洞相邻则需要将该状态的度减 $1$。

当所有状态的结果都更新完毕时，初始状态的结果即为最终结果。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 是图中的结点数。

<!-- tabs:start -->

#### Python3

```python
HOLE, MOUSE_START, CAT_START = 0, 1, 2
MOUSE_TURN, CAT_TURN = 0, 1
MOUSE_WIN, CAT_WIN, TIE = 1, 2, 0


class Solution:
    def catMouseGame(self, graph: List[List[int]]) -> int:
        def get_prev_states(state):
            m, c, t = state
            pt = t ^ 1
            pre = []
            if pt == CAT_TURN:
                for pc in graph[c]:
                    if pc != HOLE:
                        pre.append((m, pc, pt))
            else:
                for pm in graph[m]:
                    pre.append((pm, c, pt))
            return pre

        n = len(graph)
        ans = [[[0, 0] for _ in range(n)] for _ in range(n)]
        degree = [[[0, 0] for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(1, n):
                degree[i][j][MOUSE_TURN] = len(graph[i])
                degree[i][j][CAT_TURN] = len(graph[j])
            for j in graph[HOLE]:
                degree[i][j][CAT_TURN] -= 1
        q = deque()
        for j in range(1, n):
            ans[0][j][MOUSE_TURN] = ans[0][j][CAT_TURN] = MOUSE_WIN
            q.append((0, j, MOUSE_TURN))
            q.append((0, j, CAT_TURN))
        for i in range(1, n):
            ans[i][i][MOUSE_TURN] = ans[i][i][CAT_TURN] = CAT_WIN
            q.append((i, i, MOUSE_TURN))
            q.append((i, i, CAT_TURN))
        while q:
            state = q.popleft()
            t = ans[state[0]][state[1]][state[2]]
            for prev_state in get_prev_states(state):
                pm, pc, pt = prev_state
                if ans[pm][pc][pt] == TIE:
                    win = (t == MOUSE_WIN and pt == MOUSE_TURN) or (
                        t == CAT_WIN and pt == CAT_TURN
                    )
                    if win:
                        ans[pm][pc][pt] = t
                        q.append(prev_state)
                    else:
                        degree[pm][pc][pt] -= 1
                        if degree[pm][pc][pt] == 0:
                            ans[pm][pc][pt] = t
                            q.append(prev_state)
        return ans[MOUSE_START][CAT_START][MOUSE_TURN]
```

#### Java

```java
class Solution {
    private int n;
    private int[][] g;
    private int[][][] ans;
    private int[][][] degree;

    private static final int HOLE = 0, MOUSE_START = 1, CAT_START = 2;
    private static final int MOUSE_TURN = 0, CAT_TURN = 1;
    private static final int MOUSE_WIN = 1, CAT_WIN = 2, TIE = 0;

    public int catMouseGame(int[][] graph) {
        n = graph.length;
        g = graph;
        ans = new int[n][n][2];
        degree = new int[n][n][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                degree[i][j][MOUSE_TURN] = g[i].length;
                degree[i][j][CAT_TURN] = g[j].length;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j : g[HOLE]) {
                --degree[i][j][CAT_TURN];
            }
        }
        Deque<int[]> q = new ArrayDeque<>();
        for (int j = 1; j < n; ++j) {
            ans[0][j][MOUSE_TURN] = MOUSE_WIN;
            ans[0][j][CAT_TURN] = MOUSE_WIN;
            q.offer(new int[] {0, j, MOUSE_TURN});
            q.offer(new int[] {0, j, CAT_TURN});
        }
        for (int i = 1; i < n; ++i) {
            ans[i][i][MOUSE_TURN] = CAT_WIN;
            ans[i][i][CAT_TURN] = CAT_WIN;
            q.offer(new int[] {i, i, MOUSE_TURN});
            q.offer(new int[] {i, i, CAT_TURN});
        }
        while (!q.isEmpty()) {
            int[] state = q.poll();
            int t = ans[state[0]][state[1]][state[2]];
            List<int[]> prevStates = getPrevStates(state);
            for (var prevState : prevStates) {
                int pm = prevState[0], pc = prevState[1], pt = prevState[2];
                if (ans[pm][pc][pt] == TIE) {
                    boolean win
                        = (t == MOUSE_WIN && pt == MOUSE_TURN) || (t == CAT_WIN && pt == CAT_TURN);
                    if (win) {
                        ans[pm][pc][pt] = t;
                        q.offer(prevState);
                    } else {
                        if (--degree[pm][pc][pt] == 0) {
                            ans[pm][pc][pt] = t;
                            q.offer(prevState);
                        }
                    }
                }
            }
        }
        return ans[MOUSE_START][CAT_START][MOUSE_TURN];
    }

    private List<int[]> getPrevStates(int[] state) {
        List<int[]> pre = new ArrayList<>();
        int m = state[0], c = state[1], t = state[2];
        int pt = t ^ 1;
        if (pt == CAT_TURN) {
            for (int pc : g[c]) {
                if (pc != HOLE) {
                    pre.add(new int[] {m, pc, pt});
                }
            }
        } else {
            for (int pm : g[m]) {
                pre.add(new int[] {pm, c, pt});
            }
        }
        return pre;
    }
}
```

#### C++

```cpp
const int HOLE = 0;
const int MOUSE_START = 1;
const int CAT_START = 2;
const int MOUSE_TURN = 0;
const int CAT_TURN = 1;
const int MOUSE_WIN = 1;
const int CAT_WIN = 2;
const int TIE = 0;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int ans[n][n][2];
        int degree[n][n][2];
        memset(ans, 0, sizeof ans);
        memset(degree, 0, sizeof degree);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                degree[i][j][MOUSE_TURN] = graph[i].size();
                degree[i][j][CAT_TURN] = graph[j].size();
            }
            for (int j : graph[HOLE]) {
                --degree[i][j][CAT_TURN];
            }
        }
        auto getPrevStates = [&](int m, int c, int t) {
            int pt = t ^ 1;
            vector<tuple<int, int, int>> pre;
            if (pt == CAT_TURN) {
                for (int pc : graph[c]) {
                    if (pc != HOLE) {
                        pre.emplace_back(m, pc, pt);
                    }
                }
            } else {
                for (int pm : graph[m]) {
                    pre.emplace_back(pm, c, pt);
                }
            }
            return pre;
        };
        queue<tuple<int, int, int>> q;
        for (int j = 1; j < n; ++j) {
            ans[0][j][MOUSE_TURN] = ans[0][j][CAT_TURN] = MOUSE_WIN;
            q.emplace(0, j, MOUSE_TURN);
            q.emplace(0, j, CAT_TURN);
        }
        for (int i = 1; i < n; ++i) {
            ans[i][i][MOUSE_TURN] = ans[i][i][CAT_TURN] = CAT_WIN;
            q.emplace(i, i, MOUSE_TURN);
            q.emplace(i, i, CAT_TURN);
        }
        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int x = ans[m][c][t];
            for (auto [pm, pc, pt] : getPrevStates(m, c, t)) {
                if (ans[pm][pc][pt] == TIE) {
                    bool win = (x == MOUSE_WIN && pt == MOUSE_TURN) || (x == CAT_WIN && pt == CAT_TURN);
                    if (win) {
                        ans[pm][pc][pt] = x;
                        q.emplace(pm, pc, pt);
                    } else {
                        if (--degree[pm][pc][pt] == 0) {
                            ans[pm][pc][pt] = x;
                            q.emplace(pm, pc, pt);
                        }
                    }
                }
            }
        }
        return ans[MOUSE_START][CAT_START][MOUSE_TURN];
    }
};
```

#### Go

```go
const (
	hole       = 0
	mouseStart = 1
	catStart   = 2
	mouseTurn  = 0
	catTurn    = 1
	mouseWin   = 1
	catWin     = 2
	tie        = 0
)

func catMouseGame(graph [][]int) int {
	ans := [50][50][2]int{}
	degree := [50][50][2]int{}
	n := len(graph)
	for i := 0; i < n; i++ {
		for j := 1; j < n; j++ {
			degree[i][j][mouseTurn] = len(graph[i])
			degree[i][j][catTurn] = len(graph[j])
		}
		for _, j := range graph[hole] {
			degree[i][j][catTurn]--
		}
	}
	type tuple struct{ m, c, t int }
	q := []tuple{}
	for j := 1; j < n; j++ {
		ans[0][j][mouseTurn], ans[0][j][catTurn] = mouseWin, mouseWin
		q = append(q, tuple{0, j, mouseTurn})
		q = append(q, tuple{0, j, catTurn})
	}
	for i := 1; i < n; i++ {
		ans[i][i][mouseTurn], ans[i][i][catTurn] = catWin, catWin
		q = append(q, tuple{i, i, mouseTurn})
		q = append(q, tuple{i, i, catTurn})
	}
	getPrevStates := func(m, c, t int) []tuple {
		pre := []tuple{}
		pt := t ^ 1
		if pt == catTurn {
			for _, pc := range graph[c] {
				if pc != hole {
					pre = append(pre, tuple{m, pc, pt})
				}
			}
		} else {
			for _, pm := range graph[m] {
				pre = append(pre, tuple{pm, c, pt})
			}
		}
		return pre
	}
	for len(q) > 0 {
		state := q[0]
		m, c, t := state.m, state.c, state.t
		q = q[1:]
		x := ans[m][c][t]
		for _, prevState := range getPrevStates(m, c, t) {
			pm, pc, pt := prevState.m, prevState.c, prevState.t
			if ans[pm][pc][pt] == tie {
				win := (x == mouseWin && pt == mouseTurn) || (x == catWin && pt == catTurn)
				if win {
					ans[pm][pc][pt] = x
					q = append(q, tuple{pm, pc, pt})
				} else {
					degree[pm][pc][pt]--
					if degree[pm][pc][pt] == 0 {
						ans[pm][pc][pt] = x
						q = append(q, tuple{pm, pc, pt})
					}
				}
			}
		}
	}
	return ans[mouseStart][catStart][mouseTurn]
}
```

#### TypeScript

```ts
function catMouseGame(graph: number[][]): number {
    const [HOLE, MOUSE_START, CAT_START] = [0, 1, 2];
    const [MOUSE_TURN, CAT_TURN] = [0, 1];
    const [MOUSE_WIN, CAT_WIN, TIE] = [1, 2, 0];

    function get_prev_states(state: [number, number, number]): [number, number, number][] {
        const [m, c, t] = state;
        const pt = t ^ 1;
        const pre = [] as [number, number, number][];

        if (pt === CAT_TURN) {
            for (const pc of graph[c]) {
                if (pc !== HOLE) {
                    pre.push([m, pc, pt]);
                }
            }
        } else {
            for (const pm of graph[m]) {
                pre.push([pm, c, pt]);
            }
        }
        return pre;
    }

    const n = graph.length;
    const ans: number[][][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => [TIE, TIE]),
    );
    const degree: number[][][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => [0, 0]),
    );

    for (let i = 0; i < n; i++) {
        for (let j = 1; j < n; j++) {
            degree[i][j][MOUSE_TURN] = graph[i].length;
            degree[i][j][CAT_TURN] = graph[j].length;
        }
        for (const j of graph[HOLE]) {
            degree[i][j][CAT_TURN] -= 1;
        }
    }

    const q: [number, number, number][] = [];

    for (let j = 1; j < n; j++) {
        ans[0][j][MOUSE_TURN] = ans[0][j][CAT_TURN] = MOUSE_WIN;
        q.push([0, j, MOUSE_TURN], [0, j, CAT_TURN]);
    }
    for (let i = 1; i < n; i++) {
        ans[i][i][MOUSE_TURN] = ans[i][i][CAT_TURN] = CAT_WIN;
        q.push([i, i, MOUSE_TURN], [i, i, CAT_TURN]);
    }

    while (q.length > 0) {
        const state = q.shift()!;
        const [m, c, t] = state;
        const result = ans[m][c][t];

        for (const prev_state of get_prev_states(state)) {
            const [pm, pc, pt] = prev_state;
            if (ans[pm][pc][pt] === TIE) {
                const win =
                    (result === MOUSE_WIN && pt === MOUSE_TURN) ||
                    (result === CAT_WIN && pt === CAT_TURN);
                if (win) {
                    ans[pm][pc][pt] = result;
                    q.push(prev_state);
                } else {
                    degree[pm][pc][pt] -= 1;
                    if (degree[pm][pc][pt] === 0) {
                        ans[pm][pc][pt] = result;
                        q.push(prev_state);
                    }
                }
            }
        }
    }

    return ans[MOUSE_START][CAT_START][MOUSE_TURN];
}
```

#### C#

```cs
public class Solution {
    private int n;
    private int[][] g;
    private int[,,] ans;
    private int[,,] degree;

    private const int HOLE = 0, MOUSE_START = 1, CAT_START = 2;
    private const int MOUSE_TURN = 0, CAT_TURN = 1;
    private const int MOUSE_WIN = 1, CAT_WIN = 2, TIE = 0;

    public int CatMouseGame(int[][] graph) {
        n = graph.Length;
        g = graph;
        ans = new int[n, n, 2];
        degree = new int[n, n, 2];

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                degree[i, j, MOUSE_TURN] = g[i].Length;
                degree[i, j, CAT_TURN] = g[j].Length;
            }
        }

        for (int i = 0; i < n; i++) {
            foreach (int j in g[HOLE]) {
                degree[i, j, CAT_TURN]--;
            }
        }

        Queue<int[]> q = new Queue<int[]>();

        for (int j = 1; j < n; j++) {
            ans[0, j, MOUSE_TURN] = MOUSE_WIN;
            ans[0, j, CAT_TURN] = MOUSE_WIN;
            q.Enqueue(new int[] { 0, j, MOUSE_TURN });
            q.Enqueue(new int[] { 0, j, CAT_TURN });
        }

        for (int i = 1; i < n; i++) {
            ans[i, i, MOUSE_TURN] = CAT_WIN;
            ans[i, i, CAT_TURN] = CAT_WIN;
            q.Enqueue(new int[] { i, i, MOUSE_TURN });
            q.Enqueue(new int[] { i, i, CAT_TURN });
        }

        while (q.Count > 0) {
            int[] state = q.Dequeue();
            int t = ans[state[0], state[1], state[2]];
            List<int[]> prevStates = GetPrevStates(state);

            foreach (var prevState in prevStates) {
                int pm = prevState[0], pc = prevState[1], pt = prevState[2];
                if (ans[pm, pc, pt] == TIE) {
                    bool win = (t == MOUSE_WIN && pt == MOUSE_TURN) || (t == CAT_WIN && pt == CAT_TURN);
                    if (win) {
                        ans[pm, pc, pt] = t;
                        q.Enqueue(prevState);
                    } else {
                        if (--degree[pm, pc, pt] == 0) {
                            ans[pm, pc, pt] = t;
                            q.Enqueue(prevState);
                        }
                    }
                }
            }
        }

        return ans[MOUSE_START, CAT_START, MOUSE_TURN];
    }

    private List<int[]> GetPrevStates(int[] state) {
        List<int[]> pre = new List<int[]>();
        int m = state[0], c = state[1], t = state[2];
        int pt = t ^ 1;

        if (pt == CAT_TURN) {
            foreach (int pc in g[c]) {
                if (pc != HOLE) {
                    pre.Add(new int[] { m, pc, pt });
                }
            }
        } else {
            foreach (int pm in g[m]) {
                pre.Add(new int[] { pm, c, pt });
            }
        }

        return pre;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [914. 卡牌分组](https://leetcode.cn/problems/x-of-a-kind-in-a-deck-of-cards){#914}

{{< tabs "914" >}}

{{% tab "python" %}}
```python
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cnt = Counter(deck)
        return reduce(gcd, cnt.values()) >= 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : deck) {
            cnt.merge(x, 1, Integer::sum);
        }
        int g = cnt.get(deck[0]);
        for (int x : cnt.values()) {
            g = gcd(g, x);
        }
        return g >= 2;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (int x : deck) {
            ++cnt[x];
        }
        int g = cnt[deck[0]];
        for (auto& [_, x] : cnt) {
            g = gcd(g, x);
        }
        return g >= 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hasGroupsSizeX(deck []int) bool {
	cnt := map[int]int{}
	for _, x := range deck {
		cnt[x]++
	}
	g := cnt[deck[0]]
	for _, x := range cnt {
		g = gcd(g, x)
	}
	return g >= 2
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function hasGroupsSizeX(deck: number[]): boolean {
    const cnt: Record<number, number> = {};
    for (const x of deck) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const gcd = (a: number, b: number): number => (b === 0 ? a : gcd(b, a % b));
    let g = cnt[deck[0]];
    for (const [_, x] of Object.entries(cnt)) {
        g = gcd(g, x);
    }
    return g >= 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一副牌，每张牌上都写着一个整数。</p>

<p>此时，你需要选定一个数字 <code>X</code>，使我们可以将整副牌按下述规则分成 1 组或更多组：</p>

<ul>
	<li>每组都有&nbsp;<code>X</code>&nbsp;张牌。</li>
	<li>组内所有的牌上都写着相同的整数。</li>
</ul>

<p>仅当你可选的 <code>X &gt;= 2</code> 时返回&nbsp;<code>true</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>deck = [1,2,3,4,4,3,2,1]
<strong>输出：</strong>true
<strong>解释：</strong>可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>deck = [1,1,1,2,2,2,3,3]
<strong>输出：</strong>false
<strong>解释：</strong>没有满足要求的分组。
</pre>

<p><br />
<strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= deck.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= deck[i] &lt; 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：最大公约数

我们先用数组或哈希表 `cnt` 统计每个数字出现的次数，只有当 $X$ 是所有数字出现次数的约数时，即 $X$ 是所有 `cnt[i]` 的最大公约数的约数时，才能满足题意。

因此，我们求出所有数字出现次数的最大公约数 $g$，然后判断其是否大于等于 $2$ 即可。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n + \log M)$。其中 $n$ 和 $M$ 分别是数组 `deck` 的长度和数组 `deck` 中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        cnt = Counter(deck)
        return reduce(gcd, cnt.values()) >= 2
```

#### Java

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : deck) {
            cnt.merge(x, 1, Integer::sum);
        }
        int g = cnt.get(deck[0]);
        for (int x : cnt.values()) {
            g = gcd(g, x);
        }
        return g >= 2;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        for (int x : deck) {
            ++cnt[x];
        }
        int g = cnt[deck[0]];
        for (auto& [_, x] : cnt) {
            g = gcd(g, x);
        }
        return g >= 2;
    }
};
```

#### Go

```go
func hasGroupsSizeX(deck []int) bool {
	cnt := map[int]int{}
	for _, x := range deck {
		cnt[x]++
	}
	g := cnt[deck[0]]
	for _, x := range cnt {
		g = gcd(g, x)
	}
	return g >= 2
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function hasGroupsSizeX(deck: number[]): boolean {
    const cnt: Record<number, number> = {};
    for (const x of deck) {
        cnt[x] = (cnt[x] || 0) + 1;
    }
    const gcd = (a: number, b: number): number => (b === 0 ? a : gcd(b, a % b));
    let g = cnt[deck[0]];
    for (const [_, x] of Object.entries(cnt)) {
        g = gcd(g, x);
    }
    return g >= 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [915. 分割数组](https://leetcode.cn/problems/partition-array-into-disjoint-intervals){#915}

{{< tabs "915" >}}

{{% tab "python" %}}
```python
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        mi = [inf] * (n + 1)
        for i in range(n - 1, -1, -1):
            mi[i] = min(nums[i], mi[i + 1])
        mx = 0
        for i, v in enumerate(nums, 1):
            mx = max(mx, v)
            if mx <= mi[i]:
                return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int partitionDisjoint(int[] nums) {
        int n = nums.length;
        int[] mi = new int[n + 1];
        mi[n] = nums[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            mi[i] = Math.min(nums[i], mi[i + 1]);
        }
        int mx = 0;
        for (int i = 1;; ++i) {
            int v = nums[i - 1];
            mx = Math.max(mx, v);
            if (mx <= mi[i]) {
                return i;
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
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> mi(n + 1, INT_MAX);
        for (int i = n - 1; ~i; --i) {
            mi[i] = min(nums[i], mi[i + 1]);
        }
        int mx = 0;
        for (int i = 1;; ++i) {
            int v = nums[i - 1];
            mx = max(mx, v);
            if (mx <= mi[i]) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func partitionDisjoint(nums []int) int {
	n := len(nums)
	mi := make([]int, n+1)
	mi[n] = nums[n-1]
	for i := n - 1; i >= 0; i-- {
		mi[i] = min(nums[i], mi[i+1])
	}
	mx := 0
	for i := 1; ; i++ {
		v := nums[i-1]
		mx = max(mx, v)
		if mx <= mi[i] {
			return i
		}
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个数组&nbsp;<code>nums</code>&nbsp;，将其划分为两个连续子数组&nbsp;<code>left</code>&nbsp;和&nbsp;<code>right</code>，&nbsp;使得：</p>

<ul>
	<li><code>left</code>&nbsp;中的每个元素都小于或等于&nbsp;<code>right</code>&nbsp;中的每个元素。</li>
	<li><code>left</code> 和&nbsp;<code>right</code>&nbsp;都是非空的。</li>
	<li><code>left</code> 的长度要尽可能小。</li>
</ul>

<p><em>在完成这样的分组后返回&nbsp;<code>left</code>&nbsp;的&nbsp;<strong>长度&nbsp;</strong></em>。</p>

<p>用例可以保证存在这样的划分方法。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,0,3,8,6]
<strong>输出：</strong>3
<strong>解释：</strong>left = [5,0,3]，right = [8,6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,0,6,12]
<strong>输出：</strong>4
<strong>解释：</strong>left = [1,1,1,0]，right = [6,12]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li>可以保证至少有一种方法能够按题目所描述的那样对 <code>nums</code> 进行划分。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀最大值 + 后缀最小值

划分后的两个子数组要满足题目要求，需要保证“数组前缀最大值”小于等于“数组后缀最小值”。

因此，我们可以先预处理出数组的后缀最小值，记录在 `mi` 数组中。

然后从前往后遍历数组，维护数组前缀的最大值 `mx`，当遍历到某个位置时，如果数组前缀最大值小于等于数组后缀最小值，那么当前位置就是划分的分界点，直接返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def partitionDisjoint(self, nums: List[int]) -> int:
        n = len(nums)
        mi = [inf] * (n + 1)
        for i in range(n - 1, -1, -1):
            mi[i] = min(nums[i], mi[i + 1])
        mx = 0
        for i, v in enumerate(nums, 1):
            mx = max(mx, v)
            if mx <= mi[i]:
                return i
```

#### Java

```java
class Solution {
    public int partitionDisjoint(int[] nums) {
        int n = nums.length;
        int[] mi = new int[n + 1];
        mi[n] = nums[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            mi[i] = Math.min(nums[i], mi[i + 1]);
        }
        int mx = 0;
        for (int i = 1;; ++i) {
            int v = nums[i - 1];
            mx = Math.max(mx, v);
            if (mx <= mi[i]) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> mi(n + 1, INT_MAX);
        for (int i = n - 1; ~i; --i) {
            mi[i] = min(nums[i], mi[i + 1]);
        }
        int mx = 0;
        for (int i = 1;; ++i) {
            int v = nums[i - 1];
            mx = max(mx, v);
            if (mx <= mi[i]) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func partitionDisjoint(nums []int) int {
	n := len(nums)
	mi := make([]int, n+1)
	mi[n] = nums[n-1]
	for i := n - 1; i >= 0; i-- {
		mi[i] = min(nums[i], mi[i+1])
	}
	mx := 0
	for i := 1; ; i++ {
		v := nums[i-1]
		mx = max(mx, v)
		if mx <= mi[i] {
			return i
		}
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [916. 单词子集](https://leetcode.cn/problems/word-subsets){#916}

{{< tabs "916" >}}

{{% tab "python" %}}
```python
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        cnt = Counter()
        for b in words2:
            t = Counter(b)
            for c, v in t.items():
                cnt[c] = max(cnt[c], v)
        ans = []
        for a in words1:
            t = Counter(a)
            if all(v <= t[c] for c, v in cnt.items()):
                ans.append(a)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] cnt = new int[26];
        for (var b : words2) {
            int[] t = new int[26];
            for (int i = 0; i < b.length(); ++i) {
                t[b.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = Math.max(cnt[i], t[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        for (var a : words1) {
            int[] t = new int[26];
            for (int i = 0; i < a.length(); ++i) {
                t[a.charAt(i) - 'a']++;
            }
            boolean ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(a);
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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt[26] = {0};
        int t[26];
        for (auto& b : words2) {
            memset(t, 0, sizeof t);
            for (auto& c : b) {
                t[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = max(cnt[i], t[i]);
            }
        }
        vector<string> ans;
        for (auto& a : words1) {
            memset(t, 0, sizeof t);
            for (auto& c : a) {
                t[c - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.emplace_back(a);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wordSubsets(words1 []string, words2 []string) (ans []string) {
	cnt := [26]int{}
	for _, b := range words2 {
		t := [26]int{}
		for _, c := range b {
			t[c-'a']++
		}
		for i := range cnt {
			cnt[i] = max(cnt[i], t[i])
		}
	}
	for _, a := range words1 {
		t := [26]int{}
		for _, c := range a {
			t[c-'a']++
		}
		ok := true
		for i, v := range cnt {
			if v > t[i] {
				ok = false
				break
			}
		}
		if ok {
			ans = append(ans, a)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wordSubsets(words1: string[], words2: string[]): string[] {
    const cnt: number[] = Array(26).fill(0);
    for (const b of words2) {
        const t: number[] = Array(26).fill(0);
        for (const c of b) {
            t[c.charCodeAt(0) - 97]++;
        }
        for (let i = 0; i < 26; i++) {
            cnt[i] = Math.max(cnt[i], t[i]);
        }
    }

    const ans: string[] = [];
    for (const a of words1) {
        const t: number[] = Array(26).fill(0);
        for (const c of a) {
            t[c.charCodeAt(0) - 97]++;
        }

        let ok = true;
        for (let i = 0; i < 26; i++) {
            if (cnt[i] > t[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans.push(a);
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function (words1, words2) {
    const cnt = Array(26).fill(0);

    for (const b of words2) {
        const t = Array(26).fill(0);

        for (const c of b) {
            t[c.charCodeAt(0) - 97]++;
        }

        for (let i = 0; i < 26; i++) {
            cnt[i] = Math.max(cnt[i], t[i]);
        }
    }

    const ans = [];

    for (const a of words1) {
        const t = Array(26).fill(0);

        for (const c of a) {
            t[c.charCodeAt(0) - 97]++;
        }

        let ok = true;
        for (let i = 0; i < 26; i++) {
            if (cnt[i] > t[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans.push(a);
        }
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

<p>给你两个字符串数组 <code>words1</code>&nbsp;和&nbsp;<code>words2</code>。</p>

<p>现在，如果&nbsp;<code>b</code> 中的每个字母都出现在 <code>a</code> 中，<strong>包括重复出现的字母</strong>，那么称字符串 <code>b</code> 是字符串 <code>a</code> 的 <strong>子集</strong> 。</p>

<ul>
	<li>例如，<code>"wrr"</code> 是 <code>"warrior"</code> 的子集，但不是 <code>"world"</code> 的子集。</li>
</ul>

<p>如果对 <code>words2</code> 中的每一个单词&nbsp;<code>b</code>，<code>b</code> 都是 <code>a</code> 的子集，那么我们称&nbsp;<code>words1</code> 中的单词 <code>a</code> 是<em> </em><strong>通用单词</strong><em> </em>。</p>

<p>以数组形式返回&nbsp;<code>words1</code> 中所有的 <strong>通用</strong> 单词。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]</span></p>

<p><span class="example-io"><b>输出：</b>["facebook","google","leetcode"]</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">["leetcode"]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">["cccbb"]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words1.length, words2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words1[i].length, words2[i].length &lt;= 10</code></li>
	<li><code>words1[i]</code> 和 <code>words2[i]</code> 仅由小写英文字母组成</li>
	<li><code>words1</code> 中的所有字符串 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

遍历 `words2` 中的每个单词 `b`，统计每个字母出现的最大次数，记为 `cnt`。

然后遍历 `words1` 中的每个单词 `a`，统计每个字母出现的次数，记为 `t`。如果 `cnt` 中的每个字母的出现次数都不大于 `t` 中的出现次数，则 `a` 是通用单词，将其加入答案。

时间复杂度 $O(L)$，其中 $L$ 为 `words1` 和 `words2` 中所有单词的长度之和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        cnt = Counter()
        for b in words2:
            t = Counter(b)
            for c, v in t.items():
                cnt[c] = max(cnt[c], v)
        ans = []
        for a in words1:
            t = Counter(a)
            if all(v <= t[c] for c, v in cnt.items()):
                ans.append(a)
        return ans
```

#### Java

```java
class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] cnt = new int[26];
        for (var b : words2) {
            int[] t = new int[26];
            for (int i = 0; i < b.length(); ++i) {
                t[b.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = Math.max(cnt[i], t[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        for (var a : words1) {
            int[] t = new int[26];
            for (int i = 0; i < a.length(); ++i) {
                t[a.charAt(i) - 'a']++;
            }
            boolean ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(a);
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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt[26] = {0};
        int t[26];
        for (auto& b : words2) {
            memset(t, 0, sizeof t);
            for (auto& c : b) {
                t[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = max(cnt[i], t[i]);
            }
        }
        vector<string> ans;
        for (auto& a : words1) {
            memset(t, 0, sizeof t);
            for (auto& c : a) {
                t[c - 'a']++;
            }
            bool ok = true;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > t[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.emplace_back(a);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func wordSubsets(words1 []string, words2 []string) (ans []string) {
	cnt := [26]int{}
	for _, b := range words2 {
		t := [26]int{}
		for _, c := range b {
			t[c-'a']++
		}
		for i := range cnt {
			cnt[i] = max(cnt[i], t[i])
		}
	}
	for _, a := range words1 {
		t := [26]int{}
		for _, c := range a {
			t[c-'a']++
		}
		ok := true
		for i, v := range cnt {
			if v > t[i] {
				ok = false
				break
			}
		}
		if ok {
			ans = append(ans, a)
		}
	}
	return
}
```

#### TypeScript

```ts
function wordSubsets(words1: string[], words2: string[]): string[] {
    const cnt: number[] = Array(26).fill(0);
    for (const b of words2) {
        const t: number[] = Array(26).fill(0);
        for (const c of b) {
            t[c.charCodeAt(0) - 97]++;
        }
        for (let i = 0; i < 26; i++) {
            cnt[i] = Math.max(cnt[i], t[i]);
        }
    }

    const ans: string[] = [];
    for (const a of words1) {
        const t: number[] = Array(26).fill(0);
        for (const c of a) {
            t[c.charCodeAt(0) - 97]++;
        }

        let ok = true;
        for (let i = 0; i < 26; i++) {
            if (cnt[i] > t[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans.push(a);
        }
    }

    return ans;
}
```

#### JavaScript

```js
/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {string[]}
 */
var wordSubsets = function (words1, words2) {
    const cnt = Array(26).fill(0);

    for (const b of words2) {
        const t = Array(26).fill(0);

        for (const c of b) {
            t[c.charCodeAt(0) - 97]++;
        }

        for (let i = 0; i < 26; i++) {
            cnt[i] = Math.max(cnt[i], t[i]);
        }
    }

    const ans = [];

    for (const a of words1) {
        const t = Array(26).fill(0);

        for (const c of a) {
            t[c.charCodeAt(0) - 97]++;
        }

        let ok = true;
        for (let i = 0; i < 26; i++) {
            if (cnt[i] > t[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans.push(a);
        }
    }

    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [917. 仅仅反转字母](https://leetcode.cn/problems/reverse-only-letters){#917}

{{< tabs "917" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        cs = list(s)
        i, j = 0, len(cs) - 1
        while i < j:
            while i < j and not cs[i].isalpha():
                i += 1
            while i < j and not cs[j].isalpha():
                j -= 1
            if i < j:
                cs[i], cs[j] = cs[j], cs[i]
                i, j = i + 1, j - 1
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] cs = s.toCharArray();
        int i = 0, j = cs.length - 1;
        while (i < j) {
            while (i < j && !Character.isLetter(cs[i])) {
                ++i;
            }
            while (i < j && !Character.isLetter(cs[j])) {
                --j;
            }
            if (i < j) {
                char t = cs[i];
                cs[i] = cs[j];
                cs[j] = t;
                ++i;
                --j;
            }
        }
        return new String(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseOnlyLetters(s string) string {
	cs := []rune(s)
	i, j := 0, len(s)-1
	for i < j {
		for i < j && !unicode.IsLetter(cs[i]) {
			i++
		}
		for i < j && !unicode.IsLetter(cs[j]) {
			j--
		}
		if i < j {
			cs[i], cs[j] = cs[j], cs[i]
			i++
			j--
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reverseOnlyLetters(s: string): string {
    const cs = [...s];
    let [i, j] = [0, cs.length - 1];
    while (i < j) {
        while (!/[a-zA-Z]/.test(cs[i]) && i < j) {
            i++;
        }
        while (!/[a-zA-Z]/.test(cs[j]) && i < j) {
            j--;
        }
        [cs[i], cs[j]] = [cs[j], cs[i]];
        i++;
        j--;
    }
    return cs.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        let mut cs: Vec<char> = s.chars().collect();
        let n = cs.len();
        let mut l = 0;
        let mut r = n - 1;
        while l < r {
            if !cs[l].is_ascii_alphabetic() {
                l += 1;
            } else if !cs[r].is_ascii_alphabetic() {
                r -= 1;
            } else {
                cs.swap(l, r);
                l += 1;
                r -= 1;
            }
        }
        cs.iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，根据下述规则反转字符串：</p>

<ul>
	<li>所有非英文字母保留在原有位置。</li>
	<li>所有英文字母（小写或大写）位置反转。</li>
</ul>

<p>返回反转后的 <code>s</code><em> 。</em></p>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "ab-cd"
<strong>输出：</strong>"dc-ba"
</pre>

<ol>
</ol>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "a-bC-dEf-ghIj"
<strong>输出：</strong>"j-Ih-gfE-dCba"
</pre>

<ol>
</ol>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "Test1ng-Leet=code-Q!"
<strong>输出：</strong>"Qedo1ct-eeLg=ntse-T!"
</pre>

<p>&nbsp;</p>

<p><strong>提示</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> 仅由 ASCII 值在范围 <code>[33, 122]</code> 的字符组成</li>
	<li><code>s</code> 不含 <code>'\"'</code> 或 <code>'\\'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$ 分别指向字符串的头部和尾部。当 $i < j$ 时，我们不断地移动 $i$ 和 $j$，直到 $i$ 指向一个英文字母，并且 $j$ 指向一个英文字母，然后交换 $s[i]$ 和 $s[j]$。最后返回字符串即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        cs = list(s)
        i, j = 0, len(cs) - 1
        while i < j:
            while i < j and not cs[i].isalpha():
                i += 1
            while i < j and not cs[j].isalpha():
                j -= 1
            if i < j:
                cs[i], cs[j] = cs[j], cs[i]
                i, j = i + 1, j - 1
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] cs = s.toCharArray();
        int i = 0, j = cs.length - 1;
        while (i < j) {
            while (i < j && !Character.isLetter(cs[i])) {
                ++i;
            }
            while (i < j && !Character.isLetter(cs[j])) {
                --j;
            }
            if (i < j) {
                char t = cs[i];
                cs[i] = cs[j];
                cs[j] = t;
                ++i;
                --j;
            }
        }
        return new String(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(s[i])) {
                ++i;
            }
            while (i < j && !isalpha(s[j])) {
                --j;
            }
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
```

#### Go

```go
func reverseOnlyLetters(s string) string {
	cs := []rune(s)
	i, j := 0, len(s)-1
	for i < j {
		for i < j && !unicode.IsLetter(cs[i]) {
			i++
		}
		for i < j && !unicode.IsLetter(cs[j]) {
			j--
		}
		if i < j {
			cs[i], cs[j] = cs[j], cs[i]
			i++
			j--
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function reverseOnlyLetters(s: string): string {
    const cs = [...s];
    let [i, j] = [0, cs.length - 1];
    while (i < j) {
        while (!/[a-zA-Z]/.test(cs[i]) && i < j) {
            i++;
        }
        while (!/[a-zA-Z]/.test(cs[j]) && i < j) {
            j--;
        }
        [cs[i], cs[j]] = [cs[j], cs[i]];
        i++;
        j--;
    }
    return cs.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn reverse_only_letters(s: String) -> String {
        let mut cs: Vec<char> = s.chars().collect();
        let n = cs.len();
        let mut l = 0;
        let mut r = n - 1;
        while l < r {
            if !cs[l].is_ascii_alphabetic() {
                l += 1;
            } else if !cs[r].is_ascii_alphabetic() {
                r -= 1;
            } else {
                cs.swap(l, r);
                l += 1;
                r -= 1;
            }
        }
        cs.iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [918. 环形子数组的最大和](https://leetcode.cn/problems/maximum-sum-circular-subarray){#918}

{{< tabs "918" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        pmi, pmx = 0, -inf
        ans, s, smi = -inf, 0, inf
        for x in nums:
            s += x
            ans = max(ans, s - pmi)
            smi = min(smi, s - pmx)
            pmi = min(pmi, s)
            pmx = max(pmx, s)
        return max(ans, s - smi)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        final int inf = 1 << 30;
        int pmi = 0, pmx = -inf;
        int ans = -inf, s = 0, smi = inf;
        for (int x : nums) {
            s += x;
            ans = Math.max(ans, s - pmi);
            smi = Math.min(smi, s - pmx);
            pmi = Math.min(pmi, s);
            pmx = Math.max(pmx, s);
        }
        return Math.max(ans, s - smi);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int inf = 1 << 30;
        int pmi = 0, pmx = -inf;
        int ans = -inf, s = 0, smi = inf;
        for (int x : nums) {
            s += x;
            ans = max(ans, s - pmi);
            smi = min(smi, s - pmx);
            pmi = min(pmi, s);
            pmx = max(pmx, s);
        }
        return max(ans, s - smi);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubarraySumCircular(nums []int) int {
	const inf = 1 << 30
	pmi, pmx := 0, -inf
	ans, s, smi := -inf, 0, inf
	for _, x := range nums {
		s += x
		ans = max(ans, s-pmi)
		smi = min(smi, s-pmx)
		pmi = min(pmi, s)
		pmx = max(pmx, s)
	}
	return max(ans, s-smi)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubarraySumCircular(nums: number[]): number {
    let [pmi, pmx] = [0, -Infinity];
    let [ans, s, smi] = [-Infinity, 0, Infinity];
    for (const x of nums) {
        s += x;
        ans = Math.max(ans, s - pmi);
        smi = Math.min(smi, s - pmx);
        pmi = Math.min(pmi, s);
        pmx = Math.max(pmx, s);
    }
    return Math.max(ans, s - smi);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 <code>n</code> 的<strong>环形整数数组</strong>&nbsp;<code>nums</code>&nbsp;，返回<em>&nbsp;<code>nums</code>&nbsp;的非空 <strong>子数组</strong> 的最大可能和&nbsp;</em>。</p>

<p><strong>环形数组</strong><em>&nbsp;</em>意味着数组的末端将会与开头相连呈环状。形式上， <code>nums[i]</code> 的下一个元素是 <code>nums[(i + 1) % n]</code> ， <code>nums[i]</code>&nbsp;的前一个元素是 <code>nums[(i - 1 + n) % n]</code> 。</p>

<p><strong>子数组</strong> 最多只能包含固定缓冲区&nbsp;<code>nums</code>&nbsp;中的每个元素一次。形式上，对于子数组&nbsp;<code>nums[i], nums[i + 1], ..., nums[j]</code>&nbsp;，不存在&nbsp;<code>i &lt;= k1, k2 &lt;= j</code>&nbsp;其中&nbsp;<code>k1 % n == k2 % n</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,-2,3,-2]
<strong>输出：</strong>3
<strong>解释：</strong>从子数组 [3] 得到最大和 3
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,-3,5]
<strong>输出：</strong>10
<strong>解释：</strong>从子数组 [5,5] 得到最大和 5 + 5 = 10
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,-2,2,-3]
<strong>输出：</strong>3
<strong>解释：</strong>从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 3 * 10<sup>4</sup></code>​​​​​​​</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护前缀最值

求环形子数组的最大和，可以分为两种情况：

-   情况一：最大和的子数组不包含环形部分，即为普通的最大子数组和；
-   情况二：最大和的子数组包含环形部分，我们可以转换为：求数组总和减去最小子数组和。

因此，我们维护以下几个变量：

-   前缀和最小值 $pmi$，初始值为 $0$；
-   前缀和最大值 $pmx$，初始值为 $-\infty$；
-   前缀和 $s$，初始值为 $0$；
-   最小子数组和 $smi$，初始值为 $\infty$；
-   答案 $ans$，初始值为 $-\infty$。

接下来，我们只需要遍历数组 $nums$，对于当前遍历到的元素 $x$，我们做以下更新操作：

-   更新前缀和 $s = s + x$；
-   更新答案 $ans = \max(ans, s - pmi)$，即为情况一的答案（前缀和 $s$ 减去最小前缀和 $pmi$，可以得到最大子数组和）；
-   更新 $smi = \min(smi, s - pmx)$，即为情况二的最小子数组和；
-   更新 $pmi = \min(pmi, s)$，即为最小前缀和；
-   更新 $pmx = \max(pmx, s)$，即为最大前缀和。

遍历结束，我们取 $ans$ 以及 $s - smi$ 的最大值作为答案返回即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        pmi, pmx = 0, -inf
        ans, s, smi = -inf, 0, inf
        for x in nums:
            s += x
            ans = max(ans, s - pmi)
            smi = min(smi, s - pmx)
            pmi = min(pmi, s)
            pmx = max(pmx, s)
        return max(ans, s - smi)
```

#### Java

```java
class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        final int inf = 1 << 30;
        int pmi = 0, pmx = -inf;
        int ans = -inf, s = 0, smi = inf;
        for (int x : nums) {
            s += x;
            ans = Math.max(ans, s - pmi);
            smi = Math.min(smi, s - pmx);
            pmi = Math.min(pmi, s);
            pmx = Math.max(pmx, s);
        }
        return Math.max(ans, s - smi);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int inf = 1 << 30;
        int pmi = 0, pmx = -inf;
        int ans = -inf, s = 0, smi = inf;
        for (int x : nums) {
            s += x;
            ans = max(ans, s - pmi);
            smi = min(smi, s - pmx);
            pmi = min(pmi, s);
            pmx = max(pmx, s);
        }
        return max(ans, s - smi);
    }
};
```

#### Go

```go
func maxSubarraySumCircular(nums []int) int {
	const inf = 1 << 30
	pmi, pmx := 0, -inf
	ans, s, smi := -inf, 0, inf
	for _, x := range nums {
		s += x
		ans = max(ans, s-pmi)
		smi = min(smi, s-pmx)
		pmi = min(pmi, s)
		pmx = max(pmx, s)
	}
	return max(ans, s-smi)
}
```

#### TypeScript

```ts
function maxSubarraySumCircular(nums: number[]): number {
    let [pmi, pmx] = [0, -Infinity];
    let [ans, s, smi] = [-Infinity, 0, Infinity];
    for (const x of nums) {
        s += x;
        ans = Math.max(ans, s - pmi);
        smi = Math.min(smi, s - pmx);
        pmi = Math.min(pmi, s);
        pmx = Math.max(pmx, s);
    }
    return Math.max(ans, s - smi);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [919. 完全二叉树插入器](https://leetcode.cn/problems/complete-binary-tree-inserter){#919}

{{< tabs "919" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:

    def __init__(self, root: Optional[TreeNode]):
        self.tree = []
        q = deque([root])
        while q:
            for _ in range(len(q)):
                node = q.popleft()
                self.tree.append(node)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

    def insert(self, val: int) -> int:
        p = self.tree[(len(self.tree) - 1) // 2]
        node = TreeNode(val)
        self.tree.append(node)
        if p.left is None:
            p.left = node
        else:
            p.right = node
        return p.val

    def get_root(self) -> Optional[TreeNode]:
        return self.tree[0]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()
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
class CBTInserter {
    private List<TreeNode> tree = new ArrayList<>();

    public CBTInserter(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                TreeNode node = q.poll();
                tree.add(node);
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
        }
    }

    public int insert(int val) {
        TreeNode p = tree.get((tree.size() - 1) / 2);
        TreeNode node = new TreeNode(val);
        tree.add(node);
        if (p.left == null) {
            p.left = node;
        } else {
            p.right = node;
        }
        return p.val;
    }

    public TreeNode get_root() {
        return tree.get(0);
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(val);
 * TreeNode param_2 = obj.get_root();
 */
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            for (int i = q.size(); i; --i) {
                auto node = q.front();
                q.pop();
                tree.push_back(node);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }

    int insert(int val) {
        auto p = tree[(tree.size() - 1) / 2];
        auto node = new TreeNode(val);
        tree.push_back(node);
        if (!p->left) {
            p->left = node;
        } else {
            p->right = node;
        }
        return p->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }

private:
    vector<TreeNode*> tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
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
type CBTInserter struct {
	tree []*TreeNode
}

func Constructor(root *TreeNode) CBTInserter {
	q := []*TreeNode{root}
	tree := []*TreeNode{}
	for len(q) > 0 {
		for i := len(q); i > 0; i-- {
			node := q[0]
			q = q[1:]
			tree = append(tree, node)
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
	}
	return CBTInserter{tree}
}

func (this *CBTInserter) Insert(val int) int {
	p := this.tree[(len(this.tree)-1)/2]
	node := &TreeNode{val, nil, nil}
	this.tree = append(this.tree, node)
	if p.Left == nil {
		p.Left = node
	} else {
		p.Right = node
	}
	return p.Val
}

func (this *CBTInserter) Get_root() *TreeNode {
	return this.tree[0]
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(val);
 * param_2 := obj.Get_root();
 */
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

class CBTInserter {
    private tree: TreeNode[] = [];

    constructor(root: TreeNode | null) {
        if (root === null) {
            return;
        }
        const q: TreeNode[] = [root];
        while (q.length) {
            const t: TreeNode[] = [];
            for (const node of q) {
                this.tree.push(node);
                node.left !== null && t.push(node.left);
                node.right !== null && t.push(node.right);
            }
            q.splice(0, q.length, ...t);
        }
    }

    insert(val: number): number {
        const p = this.tree[(this.tree.length - 1) >> 1];
        const node = new TreeNode(val);
        this.tree.push(node);
        if (p.left === null) {
            p.left = node;
        } else {
            p.right = node;
        }
        return p.val;
    }

    get_root(): TreeNode | null {
        return this.tree[0];
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * var obj = new CBTInserter(root)
 * var param_1 = obj.insert(val)
 * var param_2 = obj.get_root()
 */
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var CBTInserter = function (root) {
    this.tree = [];
    if (root === null) {
        return;
    }
    const q = [root];
    while (q.length) {
        const t = [];
        for (const node of q) {
            this.tree.push(node);
            node.left !== null && t.push(node.left);
            node.right !== null && t.push(node.right);
        }
        q.splice(0, q.length, ...t);
    }
};

/**
 * @param {number} val
 * @return {number}
 */
CBTInserter.prototype.insert = function (val) {
    const p = this.tree[(this.tree.length - 1) >> 1];
    const node = new TreeNode(val);
    this.tree.push(node);
    if (p.left === null) {
        p.left = node;
    } else {
        p.right = node;
    }
    return p.val;
};

/**
 * @return {TreeNode}
 */
CBTInserter.prototype.get_root = function () {
    return this.tree[0];
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * var obj = new CBTInserter(root)
 * var param_1 = obj.insert(val)
 * var param_2 = obj.get_root()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>完全二叉树</strong> 是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。</p>

<p>设计一种算法，将一个新节点插入到一棵完全二叉树中，并在插入后保持其完整。</p>

<p>实现 <code>CBTInserter</code> 类:</p>

<ul>
	<li><code>CBTInserter(TreeNode root)</code>&nbsp;使用头节点为&nbsp;<code>root</code>&nbsp;的给定树初始化该数据结构；</li>
	<li><code>CBTInserter.insert(int v)</code>&nbsp; 向树中插入一个值为&nbsp;<code>Node.val == val</code>的新节点&nbsp;<code>TreeNode</code>。使树保持完全二叉树的状态，<strong>并返回插入节点</strong>&nbsp;<code>TreeNode</code>&nbsp;<strong>的父节点的值</strong>；</li>
	<li><code>CBTInserter.get_root()</code> 将返回树的头节点。</li>
</ul>

<p>&nbsp;</p>

<ol>
</ol>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0919.Complete%20Binary%20Tree%20Inserter/images/lc-treeinsert.jpg" style="height: 143px; width: 500px;" /></p>

<pre>
<strong>输入</strong>
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
<strong>输出</strong>
[null, 1, 2, [1, 2, 3, 4]]

<strong>解释</strong>
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // 返回 1
cBTInserter.insert(4);  // 返回 2
cBTInserter.get_root(); // 返回 [1, 2, 3, 4]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>树中节点数量范围为&nbsp;<code>[1, 1000]</code>&nbsp;</li>
	<li><code>0 &lt;= Node.val &lt;= 5000</code></li>
	<li><code>root</code>&nbsp;是完全二叉树</li>
	<li><code>0 &lt;= val &lt;= 5000</code>&nbsp;</li>
	<li>每个测试用例最多调用&nbsp;<code>insert</code>&nbsp;和&nbsp;<code>get_root</code>&nbsp;操作&nbsp;<code>10<sup>4</sup></code>&nbsp;次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用一个数组 $tree$ 来存储完全二叉树的所有节点。在初始化时，我们使用一个队列 $q$ 来层序遍历给定的树，并将所有节点存储到数组 $tree$ 中。

在插入节点时，我们可以通过数组 $tree$ 来找到新节点的父节点 $p$。然后我们创建一个新节点 $node$，将其插入到数组 $tree$ 中，并将 $node$ 作为 $p$ 的左子节点或右子节点。最后返回 $p$ 的值。

在获取根节点时，我们直接返回数组 $tree$ 的第一个元素。

时间复杂度方面，初始化时需要 $O(n)$ 的时间，插入节点和获取根节点的时间复杂度均为 $O(1)$。空间复杂度为 $O(n)$。其中 $n$ 为树中节点的数量。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:

    def __init__(self, root: Optional[TreeNode]):
        self.tree = []
        q = deque([root])
        while q:
            for _ in range(len(q)):
                node = q.popleft()
                self.tree.append(node)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

    def insert(self, val: int) -> int:
        p = self.tree[(len(self.tree) - 1) // 2]
        node = TreeNode(val)
        self.tree.append(node)
        if p.left is None:
            p.left = node
        else:
            p.right = node
        return p.val

    def get_root(self) -> Optional[TreeNode]:
        return self.tree[0]


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()
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
class CBTInserter {
    private List<TreeNode> tree = new ArrayList<>();

    public CBTInserter(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                TreeNode node = q.poll();
                tree.add(node);
                if (node.left != null) {
                    q.offer(node.left);
                }
                if (node.right != null) {
                    q.offer(node.right);
                }
            }
        }
    }

    public int insert(int val) {
        TreeNode p = tree.get((tree.size() - 1) / 2);
        TreeNode node = new TreeNode(val);
        tree.add(node);
        if (p.left == null) {
            p.left = node;
        } else {
            p.right = node;
        }
        return p.val;
    }

    public TreeNode get_root() {
        return tree.get(0);
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(val);
 * TreeNode param_2 = obj.get_root();
 */
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
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q{{root}};
        while (q.size()) {
            for (int i = q.size(); i; --i) {
                auto node = q.front();
                q.pop();
                tree.push_back(node);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }

    int insert(int val) {
        auto p = tree[(tree.size() - 1) / 2];
        auto node = new TreeNode(val);
        tree.push_back(node);
        if (!p->left) {
            p->left = node;
        } else {
            p->right = node;
        }
        return p->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }

private:
    vector<TreeNode*> tree;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
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
type CBTInserter struct {
	tree []*TreeNode
}

func Constructor(root *TreeNode) CBTInserter {
	q := []*TreeNode{root}
	tree := []*TreeNode{}
	for len(q) > 0 {
		for i := len(q); i > 0; i-- {
			node := q[0]
			q = q[1:]
			tree = append(tree, node)
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
	}
	return CBTInserter{tree}
}

func (this *CBTInserter) Insert(val int) int {
	p := this.tree[(len(this.tree)-1)/2]
	node := &TreeNode{val, nil, nil}
	this.tree = append(this.tree, node)
	if p.Left == nil {
		p.Left = node
	} else {
		p.Right = node
	}
	return p.Val
}

func (this *CBTInserter) Get_root() *TreeNode {
	return this.tree[0]
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(val);
 * param_2 := obj.Get_root();
 */
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

class CBTInserter {
    private tree: TreeNode[] = [];

    constructor(root: TreeNode | null) {
        if (root === null) {
            return;
        }
        const q: TreeNode[] = [root];
        while (q.length) {
            const t: TreeNode[] = [];
            for (const node of q) {
                this.tree.push(node);
                node.left !== null && t.push(node.left);
                node.right !== null && t.push(node.right);
            }
            q.splice(0, q.length, ...t);
        }
    }

    insert(val: number): number {
        const p = this.tree[(this.tree.length - 1) >> 1];
        const node = new TreeNode(val);
        this.tree.push(node);
        if (p.left === null) {
            p.left = node;
        } else {
            p.right = node;
        }
        return p.val;
    }

    get_root(): TreeNode | null {
        return this.tree[0];
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * var obj = new CBTInserter(root)
 * var param_1 = obj.insert(val)
 * var param_2 = obj.get_root()
 */
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */
var CBTInserter = function (root) {
    this.tree = [];
    if (root === null) {
        return;
    }
    const q = [root];
    while (q.length) {
        const t = [];
        for (const node of q) {
            this.tree.push(node);
            node.left !== null && t.push(node.left);
            node.right !== null && t.push(node.right);
        }
        q.splice(0, q.length, ...t);
    }
};

/**
 * @param {number} val
 * @return {number}
 */
CBTInserter.prototype.insert = function (val) {
    const p = this.tree[(this.tree.length - 1) >> 1];
    const node = new TreeNode(val);
    this.tree.push(node);
    if (p.left === null) {
        p.left = node;
    } else {
        p.right = node;
    }
    return p.val;
};

/**
 * @return {TreeNode}
 */
CBTInserter.prototype.get_root = function () {
    return this.tree[0];
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * var obj = new CBTInserter(root)
 * var param_1 = obj.insert(val)
 * var param_2 = obj.get_root()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
