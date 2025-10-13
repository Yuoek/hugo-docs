---
title: "2670_找出不同元素数目差数组"
date: 2025-10-08T18:39:28+08:00
weight: 8
tags: [JavaScript, 二叉树, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字符串, 排序, 数组, 树, 模拟, 矩阵, 设计, 贪心, 链表]
---

{{< markmap >}}
### [2670_找出不同元素数目差数组](#2670)
#### [数组](#2670)
#### [哈希表](#2670)
### [2671_频率跟踪器](#2671)
#### [设计](#2671)
#### [哈希表](#2671)
### [2672_有相同颜色的相邻元素数目](#2672)
#### [数组](#2672)
### [2673_使二叉树所有路径值相等的最小代价](#2673)
#### [贪心](#2673)
#### [树](#2673)
#### [数组](#2673)
#### [动态规划](#2673)
#### [二叉树](#2673)
### [2674_拆分循环链表 🔒](#2674)
#### [链表](#2674)
#### [双指针](#2674)
### [2675_将对象数组转换为矩阵 🔒](#2675)
#### [JavaScript](#2675)
### [2676_节流 🔒](#2676)
#### [JavaScript](#2676)
### [2677_分块数组](#2677)
#### [JavaScript](#2677)
### [2678_老人的数目](#2678)
#### [数组](#2678)
#### [字符串](#2678)
### [2679_矩阵中的和](#2679)
#### [数组](#2679)
#### [矩阵](#2679)
#### [排序](#2679)
#### [模拟](#2679)
#### [堆（优先队列）](#2679)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2670_找出不同元素数目差数组
___
#### 数组
___
#### 哈希表
---
### 2671_频率跟踪器
___
#### 设计
___
#### 哈希表
---
### 2672_有相同颜色的相邻元素数目
___
#### 数组
---
### 2673_使二叉树所有路径值相等的最小代价
___
#### 贪心
___
#### 树
___
#### 数组
___
#### 动态规划
___
#### 二叉树
---
### 2674_拆分循环链表 🔒
___
#### 链表
___
#### 双指针
---
### 2675_将对象数组转换为矩阵 🔒
___
#### JavaScript
---
### 2676_节流 🔒
___
#### JavaScript
---
### 2677_分块数组
___
#### JavaScript
---
### 2678_老人的数目
___
#### 数组
___
#### 字符串
---
### 2679_矩阵中的和
___
#### 数组
___
#### 矩阵
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 二叉树 | 动态规划 |
| 双指针 | 哈希表 | 堆（优先队列） |
| 字符串 | 排序 | 数组 |
| 树 | 模拟 | 矩阵 |
| 设计 | 贪心 | 链表 |

# [2670. 找出不同元素数目差数组](https://leetcode.cn/problems/find-the-distinct-difference-array){#2670}

{{< tabs "2670" >}}

{{% tab "python" %}}
```python
class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        suf = [0] * (n + 1)
        s = set()
        for i in range(n - 1, -1, -1):
            s.add(nums[i])
            suf[i] = len(s)
        s.clear()
        ans = [0] * n
        for i, x in enumerate(nums):
            s.add(x)
            ans[i] = len(s) - suf[i + 1]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] distinctDifferenceArray(int[] nums) {
        int n = nums.length;
        int[] suf = new int[n + 1];
        Set<Integer> s = new HashSet<>();
        for (int i = n - 1; i >= 0; --i) {
            s.add(nums[i]);
            suf[i] = s.size();
        }
        s.clear();
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            s.add(nums[i]);
            ans[i] = s.size() - suf[i + 1];
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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n + 1);
        unordered_set<int> s;
        for (int i = n - 1; i >= 0; --i) {
            s.insert(nums[i]);
            suf[i] = s.size();
        }
        s.clear();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
            ans[i] = s.size() - suf[i + 1];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distinctDifferenceArray(nums []int) []int {
	n := len(nums)
	suf := make([]int, n+1)
	s := map[int]bool{}
	for i := n - 1; i >= 0; i-- {
		s[nums[i]] = true
		suf[i] = len(s)
	}
	ans := make([]int, n)
	s = map[int]bool{}
	for i, x := range nums {
		s[x] = true
		ans[i] = len(s) - suf[i+1]
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distinctDifferenceArray(nums: number[]): number[] {
    const n = nums.length;
    const suf: number[] = Array(n + 1).fill(0);
    const s: Set<number> = new Set();
    for (let i = n - 1; i >= 0; --i) {
        s.add(nums[i]);
        suf[i] = s.size;
    }
    s.clear();
    const ans: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        s.add(nums[i]);
        ans[i] = s.size - suf[i + 1];
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;

impl Solution {
    pub fn distinct_difference_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut suf = vec![0; n + 1];
        let mut s = HashSet::new();

        for i in (0..n).rev() {
            s.insert(nums[i]);
            suf[i] = s.len();
        }

        let mut ans = Vec::new();
        s.clear();
        for i in 0..n {
            s.insert(nums[i]);
            ans.push((s.len() - suf[i + 1]) as i32);
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

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>nums</code> ，数组长度为 <code>n</code> 。</p>

<p><code>nums</code> 的 <strong>不同元素数目差</strong> 数组可以用一个长度为 <code>n</code> 的数组 <code>diff</code> 表示，其中 <code>diff[i]</code> 等于前缀 <code>nums[0, ..., i]</code> 中不同元素的数目 <strong>减去</strong> 后缀 <code>nums[i + 1, ..., n - 1]</code> 中不同元素的数目。</p>

<p>返回<em> </em><code>nums</code> 的 <strong>不同元素数目差</strong> 数组。</p>

<p>注意 <code>nums[i, ..., j]</code> 表示 <code>nums</code> 的一个从下标 <code>i</code> 开始到下标 <code>j</code> 结束的子数组（包含下标 <code>i</code> 和 <code>j</code> 对应元素）。特别需要说明的是，如果 <code>i &gt; j</code> ，则 <code>nums[i, ..., j]</code> 表示一个空子数组。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5]
<strong>输出：</strong>[-3,-1,1,3,5]
<strong>解释：
</strong>对于 i = 0，前缀中有 1 个不同的元素，而在后缀中有 4 个不同的元素。因此，diff[0] = 1 - 4 = -3 。
对于 i = 1，前缀中有 2 个不同的元素，而在后缀中有 3 个不同的元素。因此，diff[1] = 2 - 3 = -1 。
对于 i = 2，前缀中有 3 个不同的元素，而在后缀中有 2 个不同的元素。因此，diff[2] = 3 - 2 = 1 。
对于 i = 3，前缀中有 4 个不同的元素，而在后缀中有 1 个不同的元素。因此，diff[3] = 4 - 1 = 3 。
对于 i = 4，前缀中有 5 个不同的元素，而在后缀中有 0 个不同的元素。因此，diff[4] = 5 - 0 = 5 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,3,4,2]
<strong>输出：</strong>[-2,-1,0,2,3]
<strong>解释：</strong>
对于 i = 0，前缀中有 1 个不同的元素，而在后缀中有 3 个不同的元素。因此，diff[0] = 1 - 3 = -2 。
对于 i = 1，前缀中有 2 个不同的元素，而在后缀中有 3 个不同的元素。因此，diff[1] = 2 - 3 = -1 。
对于 i = 2，前缀中有 2 个不同的元素，而在后缀中有 2 个不同的元素。因此，diff[2] = 2 - 2 = 0 。
对于 i = 3，前缀中有 3 个不同的元素，而在后缀中有 1 个不同的元素。因此，diff[3] = 3 - 1 = 2 。
对于 i = 4，前缀中有 3 个不同的元素，而在后缀中有 0 个不同的元素。因此，diff[4] = 3 - 0 = 3 。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length&nbsp;&lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 预处理后缀

我们可以预处理出一个后缀数组 $suf$，其中 $suf[i]$ 表示后缀 $nums[i, ..., n - 1]$ 中不同元素的数目，在预处理过程中，我们使用一个哈希表 $s$ 来维护后缀中出现过的元素，这样我们就可以在 $O(1)$ 的时间内查询后缀中不同元素的数目。

预处理完后缀数组 $suf$ 后，我们清空哈希表 $s$，然后再次遍历数组 $nums$，用哈希表 $s$ 来维护前缀中出现过的元素，那么位置 $i$ 的答案就是 $s$ 中不同元素的数目减去 $suf[i + 1]$，即 $|s| - suf[i + 1]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        suf = [0] * (n + 1)
        s = set()
        for i in range(n - 1, -1, -1):
            s.add(nums[i])
            suf[i] = len(s)
        s.clear()
        ans = [0] * n
        for i, x in enumerate(nums):
            s.add(x)
            ans[i] = len(s) - suf[i + 1]
        return ans
```

#### Java

```java
class Solution {
    public int[] distinctDifferenceArray(int[] nums) {
        int n = nums.length;
        int[] suf = new int[n + 1];
        Set<Integer> s = new HashSet<>();
        for (int i = n - 1; i >= 0; --i) {
            s.add(nums[i]);
            suf[i] = s.size();
        }
        s.clear();
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            s.add(nums[i]);
            ans[i] = s.size() - suf[i + 1];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> suf(n + 1);
        unordered_set<int> s;
        for (int i = n - 1; i >= 0; --i) {
            s.insert(nums[i]);
            suf[i] = s.size();
        }
        s.clear();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
            ans[i] = s.size() - suf[i + 1];
        }
        return ans;
    }
};
```

#### Go

```go
func distinctDifferenceArray(nums []int) []int {
	n := len(nums)
	suf := make([]int, n+1)
	s := map[int]bool{}
	for i := n - 1; i >= 0; i-- {
		s[nums[i]] = true
		suf[i] = len(s)
	}
	ans := make([]int, n)
	s = map[int]bool{}
	for i, x := range nums {
		s[x] = true
		ans[i] = len(s) - suf[i+1]
	}
	return ans
}
```

#### TypeScript

```ts
function distinctDifferenceArray(nums: number[]): number[] {
    const n = nums.length;
    const suf: number[] = Array(n + 1).fill(0);
    const s: Set<number> = new Set();
    for (let i = n - 1; i >= 0; --i) {
        s.add(nums[i]);
        suf[i] = s.size;
    }
    s.clear();
    const ans: number[] = Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        s.add(nums[i]);
        ans[i] = s.size - suf[i + 1];
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashSet;

impl Solution {
    pub fn distinct_difference_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut suf = vec![0; n + 1];
        let mut s = HashSet::new();

        for i in (0..n).rev() {
            s.insert(nums[i]);
            suf[i] = s.len();
        }

        let mut ans = Vec::new();
        s.clear();
        for i in 0..n {
            s.insert(nums[i]);
            ans.push((s.len() - suf[i + 1]) as i32);
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

# [2671. 频率跟踪器](https://leetcode.cn/problems/frequency-tracker){#2671}

{{< tabs "2671" >}}

{{% tab "python" %}}
```python
class FrequencyTracker:
    def __init__(self):
        self.cnt = defaultdict(int)
        self.freq = defaultdict(int)

    def add(self, number: int) -> None:
        self.freq[self.cnt[number]] -= 1
        self.cnt[number] += 1
        self.freq[self.cnt[number]] += 1

    def deleteOne(self, number: int) -> None:
        if self.cnt[number]:
            self.freq[self.cnt[number]] -= 1
            self.cnt[number] -= 1
            self.freq[self.cnt[number]] += 1

    def hasFrequency(self, frequency: int) -> bool:
        return self.freq[frequency] > 0


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class FrequencyTracker {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Map<Integer, Integer> freq = new HashMap<>();

    public FrequencyTracker() {
    }

    public void add(int number) {
        freq.merge(cnt.getOrDefault(number, 0), -1, Integer::sum);
        cnt.merge(number, 1, Integer::sum);
        freq.merge(cnt.get(number), 1, Integer::sum);
    }

    public void deleteOne(int number) {
        if (cnt.getOrDefault(number, 0) > 0) {
            freq.merge(cnt.get(number), -1, Integer::sum);
            cnt.merge(number, -1, Integer::sum);
            freq.merge(cnt.get(number), 1, Integer::sum);
        }
    }

    public boolean hasFrequency(int frequency) {
        return freq.getOrDefault(frequency, 0) > 0;
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker obj = new FrequencyTracker();
 * obj.add(number);
 * obj.deleteOne(number);
 * boolean param_3 = obj.hasFrequency(frequency);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class FrequencyTracker {
public:
    FrequencyTracker() {
    }

    void add(int number) {
        freq[cnt[number]]--;
        cnt[number]++;
        freq[cnt[number]]++;
    }

    void deleteOne(int number) {
        if (cnt[number]) {
            freq[cnt[number]]--;
            cnt[number]--;
            freq[cnt[number]]++;
        }
    }

    bool hasFrequency(int frequency) {
        return freq[frequency] > 0;
    }

private:
    unordered_map<int, int> cnt;
    unordered_map<int, int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type FrequencyTracker struct {
	cnt  map[int]int
	freq map[int]int
}

func Constructor() FrequencyTracker {
	return FrequencyTracker{map[int]int{}, map[int]int{}}
}

func (this *FrequencyTracker) Add(number int) {
	this.freq[this.cnt[number]]--
	this.cnt[number]++
	this.freq[this.cnt[number]]++
}

func (this *FrequencyTracker) DeleteOne(number int) {
	if this.cnt[number] > 0 {
		this.freq[this.cnt[number]]--
		this.cnt[number]--
		this.freq[this.cnt[number]]++
	}
}

func (this *FrequencyTracker) HasFrequency(frequency int) bool {
	return this.freq[frequency] > 0
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * obj.DeleteOne(number);
 * param_3 := obj.HasFrequency(frequency);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class FrequencyTracker {
    private cnt: Map<number, number>;
    private freq: Map<number, number>;

    constructor() {
        this.cnt = new Map();
        this.freq = new Map();
    }

    add(number: number): void {
        const f = this.cnt.get(number) || 0;
        this.freq.set(f, (this.freq.get(f) || 0) - 1);
        this.cnt.set(number, f + 1);
        this.freq.set(f + 1, (this.freq.get(f + 1) || 0) + 1);
    }

    deleteOne(number: number): void {
        const f = this.cnt.get(number) || 0;
        if (f > 0) {
            this.freq.set(f, (this.freq.get(f) || 0) - 1);
            this.cnt.set(number, f - 1);
            this.freq.set(f - 1, (this.freq.get(f - 1) || 0) + 1);
        }
    }

    hasFrequency(frequency: number): boolean {
        return (this.freq.get(frequency) || 0) > 0;
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * var obj = new FrequencyTracker()
 * obj.add(number)
 * obj.deleteOne(number)
 * var param_3 = obj.hasFrequency(frequency)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

struct FrequencyTracker {
    cnt: HashMap<i32, i32>,
    freq: HashMap<i32, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FrequencyTracker {
    fn new() -> Self {
        FrequencyTracker {
            cnt: HashMap::new(),
            freq: HashMap::new(),
        }
    }

    fn add(&mut self, number: i32) {
        let count = self.cnt.entry(number).or_insert(0);
        let prev_freq = self.freq.entry(*count).or_insert(0);
        *prev_freq -= 1;
        *count += 1;
        let new_freq = self.freq.entry(*count).or_insert(0);
        *new_freq += 1;
    }

    fn delete_one(&mut self, number: i32) {
        if let Some(count) = self.cnt.get_mut(&number) {
            if *count > 0 {
                if let Some(prev_freq) = self.freq.get_mut(count) {
                    *prev_freq -= 1;
                }
                *count -= 1;
                if let Some(new_freq) = self.freq.get_mut(count) {
                    *new_freq += 1;
                }
            }
        }
    }

    fn has_frequency(&self, frequency: i32) -> bool {
        self.freq.get(&frequency).map_or(false, |&freq| freq > 0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。</p>

<p>实现 <code>FrequencyTracker</code> 类：</p>

<ul>
	<li><code>FrequencyTracker()</code>：使用一个空数组初始化 <code>FrequencyTracker</code> 对象。</li>
	<li><code>void add(int number)</code>：添加一个 <code>number</code> 到数据结构中。</li>
	<li><code>void deleteOne(int number)</code>：从数据结构中删除一个 <code>number</code> 。数据结构 <strong>可能不包含</strong> <code>number</code> ，在这种情况下不删除任何内容。</li>
	<li><code>bool hasFrequency(int frequency)</code>: 如果数据结构中存在出现 <code>frequency</code> 次的数字，则返回 <code>true</code>，否则返回 <code>false</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
<strong>输出</strong>
[null, null, null, true]

<strong>解释</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.add(3); // 数据结构现在包含 [3, 3]
frequencyTracker.hasFrequency(2); // 返回 true ，因为 3 出现 2 次
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入</strong>
["FrequencyTracker", "add", "deleteOne", "hasFrequency"]
[[], [1], [1], [1]]
<strong>输出</strong>
[null, null, null, false]

<strong>解释</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(1); // 数据结构现在包含 [1]
frequencyTracker.deleteOne(1); // 数据结构现在为空 []
frequencyTracker.hasFrequency(1); // 返回 false ，因为数据结构为空
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入</strong>
["FrequencyTracker", "hasFrequency", "add", "hasFrequency"]
[[], [2], [3], [1]]
<strong>输出</strong>
[null, false, null, true]

<strong>解释</strong>
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.hasFrequency(2); // 返回 false ，因为数据结构为空
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.hasFrequency(1); // 返回 true ，因为 3 出现 1 次
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= number &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= frequency &lt;= 10<sup>5</sup></code></li>
	<li>最多调用 <code>add</code>、<code>deleteOne</code> 和 <code>hasFrequency</code> <strong>共计</strong> <code>2 *&nbsp;10<sup>5</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们定义两个哈希表，其中 $cnt$ 用于记录每个数字出现的次数，而 $freq$ 用于记录每个出现次数的数字的个数。

对于 `add` 操作，我们直接将哈希表 $freq$ 中 $cnt[number]$ 对应的值减一，然后将 $cnt[number]$ 加一，再将 $freq[cnt[number]]$ 对应的值加一。

对于 `deleteOne` 操作，我们首先判断 $cnt[number]$ 是否大于零，如果大于零，我们将哈希表 $freq$ 中 $cnt[number]$ 对应的值减一，然后将 $cnt[number]$ 减一，再将 $freq[cnt[number]]$ 对应的值加一。

对于 `hasFrequency` 操作，我们直接返回 $freq[frequency]$ 是否大于零。

时间复杂度方面，由于我们使用了哈希表，因此每个操作的时间复杂度均为 $O(1)$。空间复杂度 $O(n)$，其中 $n$ 为不同的数字的个数。

<!-- tabs:start -->

#### Python3

```python
class FrequencyTracker:
    def __init__(self):
        self.cnt = defaultdict(int)
        self.freq = defaultdict(int)

    def add(self, number: int) -> None:
        self.freq[self.cnt[number]] -= 1
        self.cnt[number] += 1
        self.freq[self.cnt[number]] += 1

    def deleteOne(self, number: int) -> None:
        if self.cnt[number]:
            self.freq[self.cnt[number]] -= 1
            self.cnt[number] -= 1
            self.freq[self.cnt[number]] += 1

    def hasFrequency(self, frequency: int) -> bool:
        return self.freq[frequency] > 0


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)
```

#### Java

```java
class FrequencyTracker {
    private Map<Integer, Integer> cnt = new HashMap<>();
    private Map<Integer, Integer> freq = new HashMap<>();

    public FrequencyTracker() {
    }

    public void add(int number) {
        freq.merge(cnt.getOrDefault(number, 0), -1, Integer::sum);
        cnt.merge(number, 1, Integer::sum);
        freq.merge(cnt.get(number), 1, Integer::sum);
    }

    public void deleteOne(int number) {
        if (cnt.getOrDefault(number, 0) > 0) {
            freq.merge(cnt.get(number), -1, Integer::sum);
            cnt.merge(number, -1, Integer::sum);
            freq.merge(cnt.get(number), 1, Integer::sum);
        }
    }

    public boolean hasFrequency(int frequency) {
        return freq.getOrDefault(frequency, 0) > 0;
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker obj = new FrequencyTracker();
 * obj.add(number);
 * obj.deleteOne(number);
 * boolean param_3 = obj.hasFrequency(frequency);
 */
```

#### C++

```cpp
class FrequencyTracker {
public:
    FrequencyTracker() {
    }

    void add(int number) {
        freq[cnt[number]]--;
        cnt[number]++;
        freq[cnt[number]]++;
    }

    void deleteOne(int number) {
        if (cnt[number]) {
            freq[cnt[number]]--;
            cnt[number]--;
            freq[cnt[number]]++;
        }
    }

    bool hasFrequency(int frequency) {
        return freq[frequency] > 0;
    }

private:
    unordered_map<int, int> cnt;
    unordered_map<int, int> freq;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
```

#### Go

```go
type FrequencyTracker struct {
	cnt  map[int]int
	freq map[int]int
}

func Constructor() FrequencyTracker {
	return FrequencyTracker{map[int]int{}, map[int]int{}}
}

func (this *FrequencyTracker) Add(number int) {
	this.freq[this.cnt[number]]--
	this.cnt[number]++
	this.freq[this.cnt[number]]++
}

func (this *FrequencyTracker) DeleteOne(number int) {
	if this.cnt[number] > 0 {
		this.freq[this.cnt[number]]--
		this.cnt[number]--
		this.freq[this.cnt[number]]++
	}
}

func (this *FrequencyTracker) HasFrequency(frequency int) bool {
	return this.freq[frequency] > 0
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(number);
 * obj.DeleteOne(number);
 * param_3 := obj.HasFrequency(frequency);
 */
```

#### TypeScript

```ts
class FrequencyTracker {
    private cnt: Map<number, number>;
    private freq: Map<number, number>;

    constructor() {
        this.cnt = new Map();
        this.freq = new Map();
    }

    add(number: number): void {
        const f = this.cnt.get(number) || 0;
        this.freq.set(f, (this.freq.get(f) || 0) - 1);
        this.cnt.set(number, f + 1);
        this.freq.set(f + 1, (this.freq.get(f + 1) || 0) + 1);
    }

    deleteOne(number: number): void {
        const f = this.cnt.get(number) || 0;
        if (f > 0) {
            this.freq.set(f, (this.freq.get(f) || 0) - 1);
            this.cnt.set(number, f - 1);
            this.freq.set(f - 1, (this.freq.get(f - 1) || 0) + 1);
        }
    }

    hasFrequency(frequency: number): boolean {
        return (this.freq.get(frequency) || 0) > 0;
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * var obj = new FrequencyTracker()
 * obj.add(number)
 * obj.deleteOne(number)
 * var param_3 = obj.hasFrequency(frequency)
 */
```

#### Rust

```rust
use std::collections::HashMap;

struct FrequencyTracker {
    cnt: HashMap<i32, i32>,
    freq: HashMap<i32, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FrequencyTracker {
    fn new() -> Self {
        FrequencyTracker {
            cnt: HashMap::new(),
            freq: HashMap::new(),
        }
    }

    fn add(&mut self, number: i32) {
        let count = self.cnt.entry(number).or_insert(0);
        let prev_freq = self.freq.entry(*count).or_insert(0);
        *prev_freq -= 1;
        *count += 1;
        let new_freq = self.freq.entry(*count).or_insert(0);
        *new_freq += 1;
    }

    fn delete_one(&mut self, number: i32) {
        if let Some(count) = self.cnt.get_mut(&number) {
            if *count > 0 {
                if let Some(prev_freq) = self.freq.get_mut(count) {
                    *prev_freq -= 1;
                }
                *count -= 1;
                if let Some(new_freq) = self.freq.get_mut(count) {
                    *new_freq += 1;
                }
            }
        }
    }

    fn has_frequency(&self, frequency: i32) -> bool {
        self.freq.get(&frequency).map_or(false, |&freq| freq > 0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2672. 有相同颜色的相邻元素数目](https://leetcode.cn/problems/number-of-adjacent-elements-with-the-same-color){#2672}

{{< tabs "2672" >}}

{{% tab "python" %}}
```python
class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        nums = [0] * n
        ans = [0] * len(queries)
        x = 0
        for k, (i, c) in enumerate(queries):
            if i > 0 and nums[i] and nums[i - 1] == nums[i]:
                x -= 1
            if i < n - 1 and nums[i] and nums[i + 1] == nums[i]:
                x -= 1
            if i > 0 and nums[i - 1] == c:
                x += 1
            if i < n - 1 and nums[i + 1] == c:
                x += 1
            ans[k] = x
            nums[i] = c
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] colorTheArray(int n, int[][] queries) {
        int m = queries.length;
        int[] nums = new int[n];
        int[] ans = new int[m];
        for (int k = 0, x = 0; k < m; ++k) {
            int i = queries[k][0], c = queries[k][1];
            if (i > 0 && nums[i] > 0 && nums[i - 1] == nums[i]) {
                --x;
            }
            if (i < n - 1 && nums[i] > 0 && nums[i + 1] == nums[i]) {
                --x;
            }
            if (i > 0 && nums[i - 1] == c) {
                ++x;
            }
            if (i < n - 1 && nums[i + 1] == c) {
                ++x;
            }
            ans[k] = x;
            nums[i] = c;
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
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n);
        vector<int> ans;
        int x = 0;
        for (auto& q : queries) {
            int i = q[0], c = q[1];
            if (i > 0 && nums[i] > 0 && nums[i - 1] == nums[i]) {
                --x;
            }
            if (i < n - 1 && nums[i] > 0 && nums[i + 1] == nums[i]) {
                --x;
            }
            if (i > 0 && nums[i - 1] == c) {
                ++x;
            }
            if (i < n - 1 && nums[i + 1] == c) {
                ++x;
            }
            ans.push_back(x);
            nums[i] = c;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func colorTheArray(n int, queries [][]int) (ans []int) {
	nums := make([]int, n)
	x := 0
	for _, q := range queries {
		i, c := q[0], q[1]
		if i > 0 && nums[i] > 0 && nums[i-1] == nums[i] {
			x--
		}
		if i < n-1 && nums[i] > 0 && nums[i+1] == nums[i] {
			x--
		}
		if i > 0 && nums[i-1] == c {
			x++
		}
		if i < n-1 && nums[i+1] == c {
			x++
		}
		ans = append(ans, x)
		nums[i] = c
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function colorTheArray(n: number, queries: number[][]): number[] {
    const nums: number[] = new Array(n).fill(0);
    const ans: number[] = [];
    let x = 0;
    for (const [i, c] of queries) {
        if (i > 0 && nums[i] > 0 && nums[i - 1] == nums[i]) {
            --x;
        }
        if (i < n - 1 && nums[i] > 0 && nums[i + 1] == nums[i]) {
            --x;
        }
        if (i > 0 && nums[i - 1] == c) {
            ++x;
        }
        if (i < n - 1 && nums[i + 1] == c) {
            ++x;
        }
        ans.push(x);
        nums[i] = c;
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

<p>给定一个整数&nbsp;<code>n</code>&nbsp;表示一个长度为&nbsp;<code>n</code> 的数组&nbsp; <code>colors</code>，初始所有元素均为 0 ，表示是 <strong>未染色 </strong>的。同时给定一个二维整数数组&nbsp;<code>queries</code>，其中&nbsp;<code>queries[i] = [index<sub>i</sub>, color<sub>i</sub>]</code>。对于第&nbsp;<code>i</code> 个&nbsp;<strong>查询</strong>：</p>

<ul>
	<li>将&nbsp;<code>colors[index<sub>i</sub>]</code>&nbsp;染色为 <code>color<sub>i</sub></code>。</li>
	<li>统计&nbsp;<code>colors</code>&nbsp;中颜色相同的相邻对的数量（无论 <code>color<sub>i</sub></code>）。</li>
</ul>

<p>请你返回一个长度与 <code>queries</code>&nbsp;相等的数组<em>&nbsp;</em><code>answer</code><em>&nbsp;</em>，其中<em>&nbsp;</em><code>answer[i]</code>是前 <code>i</code>&nbsp;个操作的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]</span></p>

<p><span class="example-io"><b>输出：</b>[0,1,1,0,2]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>一开始 colors = [0,0,0,0]，其中 0 表示数组中未染色的元素。</li>
	<li>在第 1 次查询后&nbsp;colors = [2,0,0,0]。颜色相同的相邻对的数量是 0。</li>
	<li>在第 2&nbsp;次查询后 colors = [2,2,0,0]。颜色相同的相邻对的数量是 1。</li>
	<li>在第 3&nbsp;次查询后 colors = [2,2,0,1]。颜色相同的相邻对的数量是 1。</li>
	<li>在第 4&nbsp;次查询后 colors = [2,1,0,1]。颜色相同的相邻对的数量是 0。</li>
	<li>在第 5&nbsp;次查询后 colors = [2,1,1,1]。颜色相同的相邻对的数量是 2。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 1, queries = [[0,100000]]</span></p>

<p><span class="example-io"><b>输出：</b>[0]</span></p>

<p><strong>解释：</strong></p>

<p>在第一次查询后&nbsp;colors = [100000]。颜色相同的相邻对的数量是 0。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length&nbsp;== 2</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>1 &lt;=&nbsp; color<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
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
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        nums = [0] * n
        ans = [0] * len(queries)
        x = 0
        for k, (i, c) in enumerate(queries):
            if i > 0 and nums[i] and nums[i - 1] == nums[i]:
                x -= 1
            if i < n - 1 and nums[i] and nums[i + 1] == nums[i]:
                x -= 1
            if i > 0 and nums[i - 1] == c:
                x += 1
            if i < n - 1 and nums[i + 1] == c:
                x += 1
            ans[k] = x
            nums[i] = c
        return ans
```

#### Java

```java
class Solution {
    public int[] colorTheArray(int n, int[][] queries) {
        int m = queries.length;
        int[] nums = new int[n];
        int[] ans = new int[m];
        for (int k = 0, x = 0; k < m; ++k) {
            int i = queries[k][0], c = queries[k][1];
            if (i > 0 && nums[i] > 0 && nums[i - 1] == nums[i]) {
                --x;
            }
            if (i < n - 1 && nums[i] > 0 && nums[i + 1] == nums[i]) {
                --x;
            }
            if (i > 0 && nums[i - 1] == c) {
                ++x;
            }
            if (i < n - 1 && nums[i + 1] == c) {
                ++x;
            }
            ans[k] = x;
            nums[i] = c;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n);
        vector<int> ans;
        int x = 0;
        for (auto& q : queries) {
            int i = q[0], c = q[1];
            if (i > 0 && nums[i] > 0 && nums[i - 1] == nums[i]) {
                --x;
            }
            if (i < n - 1 && nums[i] > 0 && nums[i + 1] == nums[i]) {
                --x;
            }
            if (i > 0 && nums[i - 1] == c) {
                ++x;
            }
            if (i < n - 1 && nums[i + 1] == c) {
                ++x;
            }
            ans.push_back(x);
            nums[i] = c;
        }
        return ans;
    }
};
```

#### Go

```go
func colorTheArray(n int, queries [][]int) (ans []int) {
	nums := make([]int, n)
	x := 0
	for _, q := range queries {
		i, c := q[0], q[1]
		if i > 0 && nums[i] > 0 && nums[i-1] == nums[i] {
			x--
		}
		if i < n-1 && nums[i] > 0 && nums[i+1] == nums[i] {
			x--
		}
		if i > 0 && nums[i-1] == c {
			x++
		}
		if i < n-1 && nums[i+1] == c {
			x++
		}
		ans = append(ans, x)
		nums[i] = c
	}
	return
}
```

#### TypeScript

```ts
function colorTheArray(n: number, queries: number[][]): number[] {
    const nums: number[] = new Array(n).fill(0);
    const ans: number[] = [];
    let x = 0;
    for (const [i, c] of queries) {
        if (i > 0 && nums[i] > 0 && nums[i - 1] == nums[i]) {
            --x;
        }
        if (i < n - 1 && nums[i] > 0 && nums[i + 1] == nums[i]) {
            --x;
        }
        if (i > 0 && nums[i - 1] == c) {
            ++x;
        }
        if (i < n - 1 && nums[i + 1] == c) {
            ++x;
        }
        ans.push(x);
        nums[i] = c;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2673. 使二叉树所有路径值相等的最小代价](https://leetcode.cn/problems/make-costs-of-paths-equal-in-a-binary-tree){#2673}

{{< tabs "2673" >}}

{{% tab "python" %}}
```python
class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans = 0
        for i in range(n >> 1, 0, -1):
            l, r = i << 1, i << 1 | 1
            ans += abs(cost[l - 1] - cost[r - 1])
            cost[i - 1] += max(cost[l - 1], cost[r - 1])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minIncrements(int n, int[] cost) {
        int ans = 0;
        for (int i = n >> 1; i > 0; --i) {
            int l = i << 1, r = i << 1 | 1;
            ans += Math.abs(cost[l - 1] - cost[r - 1]);
            cost[i - 1] += Math.max(cost[l - 1], cost[r - 1]);
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
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n >> 1; i > 0; --i) {
            int l = i << 1, r = i << 1 | 1;
            ans += abs(cost[l - 1] - cost[r - 1]);
            cost[i - 1] += max(cost[l - 1], cost[r - 1]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minIncrements(n int, cost []int) (ans int) {
	for i := n >> 1; i > 0; i-- {
		l, r := i<<1, i<<1|1
		ans += abs(cost[l-1] - cost[r-1])
		cost[i-1] += max(cost[l-1], cost[r-1])
	}
	return
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
function minIncrements(n: number, cost: number[]): number {
    let ans = 0;
    for (let i = n >> 1; i; --i) {
        const [l, r] = [i << 1, (i << 1) | 1];
        ans += Math.abs(cost[l - 1] - cost[r - 1]);
        cost[i - 1] += Math.max(cost[l - 1], cost[r - 1]);
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

<p>给你一个整数&nbsp;<code>n</code>&nbsp;表示一棵 <b>满二叉树</b>&nbsp;里面节点的数目，节点编号从 <code>1</code>&nbsp;到 <code>n</code>&nbsp;。根节点编号为 <code>1</code>&nbsp;，树中每个非叶子节点&nbsp;<code>i</code>&nbsp;都有两个孩子，分别是左孩子&nbsp;<code>2 * i</code>&nbsp;和右孩子&nbsp;<code>2 * i + 1</code>&nbsp;。</p>

<p>树中每个节点都有一个值，用下标从<b>&nbsp;0</b>&nbsp;开始、长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>cost</code>&nbsp;表示，其中&nbsp;<code>cost[i]</code>&nbsp;是第&nbsp;<code>i + 1</code>&nbsp;个节点的值。每次操作，你可以将树中&nbsp;<strong>任意</strong>&nbsp;节点的值&nbsp;<strong>增加</strong>&nbsp;<code>1</code>&nbsp;。你可以执行操作 <strong>任意</strong> 次。</p>

<p>你的目标是让根到每一个 <strong>叶子结点</strong>&nbsp;的路径值相等。请你返回 <strong>最少</strong>&nbsp;需要执行增加操作多少次。</p>

<p><b>注意：</b></p>

<ul>
	<li><strong>满二叉树</strong>&nbsp;指的是一棵树，它满足树中除了叶子节点外每个节点都恰好有 2 个子节点，且所有叶子节点距离根节点距离相同。</li>
	<li><strong>路径值</strong> 指的是路径上所有节点的值之和。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2673.Make%20Costs%20of%20Paths%20Equal%20in%20a%20Binary%20Tree/images/binaryytreeedrawio-4.png" /></p>

<pre>
<b>输入：</b>n = 7, cost = [1,5,2,2,3,3,1]
<b>输出：</b>6
<b>解释：</b>我们执行以下的增加操作：
- 将节点 4 的值增加一次。
- 将节点 3 的值增加三次。
- 将节点 7 的值增加两次。
从根到叶子的每一条路径值都为 9 。
总共增加次数为 1 + 3 + 2 = 6 。
这是最小的答案。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2673.Make%20Costs%20of%20Paths%20Equal%20in%20a%20Binary%20Tree/images/binaryytreee2drawio.png" style="width: 205px; height: 151px;" /></p>

<pre>
<b>输入：</b>n = 3, cost = [5,3,3]
<b>输出：</b>0
<b>解释：</b>两条路径已经有相等的路径值，所以不需要执行任何增加操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n + 1</code> 是&nbsp;<code>2</code>&nbsp;的幂</li>
	<li><code>cost.length == n</code></li>
	<li><code>1 &lt;= cost[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，我们需要计算最小的增加次数，使得根节点到每个叶子节点的路径值相等。

根节点到每个叶子节点的路径值相等，实际上等价于以任意节点为根节点的子树到该子树的每个叶子节点的路径值相等。

为什么呢？我们可以用反证法来证明。假设存在一个节点 $x$，以它为根节点的子树到某个叶子节点的路径值不相等，那么也就存在着根节点到叶子节点的路径值不相等的情况，这与“根节点到每个叶子节点的路径值相等”矛盾。因此假设不成立，以任意节点为根节点的子树到该子树的每个叶子节点的路径值相等。

我们可以从树的底部开始，逐层向上计算增加次数。对于每个非叶子节点，我们可以计算它的左右孩子节点的路径值，增加的次数为两者路径值的差值，然后将左右孩子节点的路径值更新为两者中的较大值。

最后返回总的增加的次数即可。

时间复杂度 $O(n)$，其中 $n$ 为节点数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans = 0
        for i in range(n >> 1, 0, -1):
            l, r = i << 1, i << 1 | 1
            ans += abs(cost[l - 1] - cost[r - 1])
            cost[i - 1] += max(cost[l - 1], cost[r - 1])
        return ans
```

#### Java

```java
class Solution {
    public int minIncrements(int n, int[] cost) {
        int ans = 0;
        for (int i = n >> 1; i > 0; --i) {
            int l = i << 1, r = i << 1 | 1;
            ans += Math.abs(cost[l - 1] - cost[r - 1]);
            cost[i - 1] += Math.max(cost[l - 1], cost[r - 1]);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for (int i = n >> 1; i > 0; --i) {
            int l = i << 1, r = i << 1 | 1;
            ans += abs(cost[l - 1] - cost[r - 1]);
            cost[i - 1] += max(cost[l - 1], cost[r - 1]);
        }
        return ans;
    }
};
```

#### Go

```go
func minIncrements(n int, cost []int) (ans int) {
	for i := n >> 1; i > 0; i-- {
		l, r := i<<1, i<<1|1
		ans += abs(cost[l-1] - cost[r-1])
		cost[i-1] += max(cost[l-1], cost[r-1])
	}
	return
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
function minIncrements(n: number, cost: number[]): number {
    let ans = 0;
    for (let i = n >> 1; i; --i) {
        const [l, r] = [i << 1, (i << 1) | 1];
        ans += Math.abs(cost[l - 1] - cost[r - 1]);
        cost[i - 1] += Math.max(cost[l - 1], cost[r - 1]);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2674. 拆分循环链表 🔒](https://leetcode.cn/problems/split-a-circular-linked-list){#2674}

{{< tabs "2674" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitCircularLinkedList(
        self, list: Optional[ListNode]
    ) -> List[Optional[ListNode]]:
        a = b = list
        while b.next != list and b.next.next != list:
            a = a.next
            b = b.next.next
        if b.next != list:
            b = b.next
        list2 = a.next
        b.next = list2
        a.next = list
        return [list, list2]
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitCircularLinkedList(ListNode list) {
        ListNode a = list, b = list;
        while (b.next != list && b.next.next != list) {
            a = a.next;
            b = b.next.next;
        }
        if (b.next != list) {
            b = b.next;
        }
        ListNode list2 = a.next;
        b.next = list2;
        a.next = list;
        return new ListNode[] {list, list2};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        ListNode* a = list;
        ListNode* b = list;
        while (b->next != list && b->next->next != list) {
            a = a->next;
            b = b->next->next;
        }
        if (b->next != list) {
            b = b->next;
        }
        ListNode* list2 = a->next;
        b->next = list2;
        a->next = list;
        return {list, list2};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitCircularLinkedList(list *ListNode) []*ListNode {
	a, b := list, list
	for b.Next != list && b.Next.Next != list {
		a = a.Next
		b = b.Next.Next
	}
	if b.Next != list {
		b = b.Next
	}
	list2 := a.Next
	b.Next = list2
	a.Next = list
	return []*ListNode{list, list2}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function splitCircularLinkedList(list: ListNode | null): Array<ListNode | null> {
    let a = list;
    let b = list;
    while (b.next !== list && b.next.next !== list) {
        a = a.next;
        b = b.next.next;
    }
    if (b.next !== list) {
        b = b.next;
    }
    const list2 = a.next;
    b.next = list2;
    a.next = list;
    return [list, list2];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个由正整数组成的 <strong>循环链表</strong> <code>list</code> ，你的任务是将其拆分为 2 个 <strong>循环链表</strong> ，使得第一个链表包含 <code>list</code> <strong>前半部分&nbsp;</strong>的节点（即 <code>ceil(list.length / 2)</code> 个节点），顺序与 list 中的顺序相同，而第二个链表包含 <code>list</code> 中 <strong>剩余</strong> 的节点，顺序也与 <code>list</code> 中的顺序相同。</p>

<p>返回一个长度为 2 的数组，其中第一个元素是表示 <strong>前半部分</strong> 链表的<strong> 循环链表</strong> ，第二个元素是表示 <strong>后半部分</strong> 链表的 <strong>循环链表</strong> 。</p>

<p><strong>循环链表</strong> 是一个普通的链表，唯一的区别是最后一个节点的下一个节点是头节点。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,5,7]
<b>输出：</b>[[1,5],[7]]
<b>解释：</b>初始链表有3个节点，因此前半部分是前两个元素，剩下的 1 个节点在后半部分。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,6,1,5]
<b>输出：</b>[[2,6],[1,5]]
<b>解释：</b>初始链表有4个节点，因此前半部分是前两个元素，剩下的 2 个节点在后半部分。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>list</code> 中的节点数范围为 <code>[2, 10<sup>5</sup>]</code></li>
	<li><code>0 &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><code>LastNode.next = FirstNode</code> ，其中 <code>LastNode</code> 是链表的最后一个节点，<code>FirstNode</code> 是第一个节点。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：快慢指针

我们定义两个指针 $a$ 和 $b$，初始时都指向链表的头节点。每次迭代时，指针 $a$ 向前移动一步，指针 $b$ 向前移动两步，直到指针 $b$ 到达链表的末尾。此时，指针 $a$ 指向链表节点数的一半，我们将链表从指针 $a$ 处断开，即可得到两个链表的头节点。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度。需要遍历链表一次。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitCircularLinkedList(
        self, list: Optional[ListNode]
    ) -> List[Optional[ListNode]]:
        a = b = list
        while b.next != list and b.next.next != list:
            a = a.next
            b = b.next.next
        if b.next != list:
            b = b.next
        list2 = a.next
        b.next = list2
        a.next = list
        return [list, list2]
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode[] splitCircularLinkedList(ListNode list) {
        ListNode a = list, b = list;
        while (b.next != list && b.next.next != list) {
            a = a.next;
            b = b.next.next;
        }
        if (b.next != list) {
            b = b.next;
        }
        ListNode list2 = a.next;
        b.next = list2;
        a.next = list;
        return new ListNode[] {list, list2};
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        ListNode* a = list;
        ListNode* b = list;
        while (b->next != list && b->next->next != list) {
            a = a->next;
            b = b->next->next;
        }
        if (b->next != list) {
            b = b->next;
        }
        ListNode* list2 = a->next;
        b->next = list2;
        a->next = list;
        return {list, list2};
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitCircularLinkedList(list *ListNode) []*ListNode {
	a, b := list, list
	for b.Next != list && b.Next.Next != list {
		a = a.Next
		b = b.Next.Next
	}
	if b.Next != list {
		b = b.Next
	}
	list2 := a.Next
	b.Next = list2
	a.Next = list
	return []*ListNode{list, list2}
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function splitCircularLinkedList(list: ListNode | null): Array<ListNode | null> {
    let a = list;
    let b = list;
    while (b.next !== list && b.next.next !== list) {
        a = a.next;
        b = b.next.next;
    }
    if (b.next !== list) {
        b = b.next;
    }
    const list2 = a.next;
    b.next = list2;
    a.next = list;
    return [list, list2];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2675. 将对象数组转换为矩阵 🔒](https://leetcode.cn/problems/array-of-objects-to-matrix){#2675}

{{< tabs "2675" >}}

{{% tab "ts" %}}
```ts
function jsonToMatrix(arr: any[]): (string | number | boolean | null)[] {
    const dfs = (key: string, obj: any) => {
        if (
            typeof obj === 'number' ||
            typeof obj === 'string' ||
            typeof obj === 'boolean' ||
            obj === null
        ) {
            return { [key]: obj };
        }
        const res: any[] = [];
        for (const [k, v] of Object.entries(obj)) {
            const newKey = key ? `${key}.${k}` : `${k}`;
            res.push(dfs(newKey, v));
        }
        return res.flat();
    };

    const kv = arr.map(obj => dfs('', obj));
    const keys = [
        ...new Set(
            kv
                .flat()
                .map(obj => Object.keys(obj))
                .flat(),
        ),
    ].sort();
    const ans: any[] = [keys];
    for (const row of kv) {
        const newRow: any[] = [];
        for (const key of keys) {
            const v = row.find(r => r.hasOwnProperty(key))?.[key];
            newRow.push(v === undefined ? '' : v);
        }
        ans.push(newRow);
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

<p>编写一个函数，将对象数组&nbsp;<code>arr</code>&nbsp;转换为矩阵&nbsp;<code>m</code>&nbsp;。</p>

<p><code>arr</code>&nbsp;是一个由对象组成的数组或一个数组。数组中的每个项都可以包含深层嵌套的子数组和子对象。它还可以包含数字、字符串、布尔值和空值。</p>

<p>矩阵&nbsp;<code>m</code>&nbsp;的第一行应该是列名。如果没有嵌套，列名是对象中的唯一键。如果存在嵌套，列名是对象中相应路径，以点号&nbsp;<code>"."</code>&nbsp;分隔。</p>

<p>剩余的每一行对应&nbsp;<code>arr</code>&nbsp;中的一个对象。矩阵中的每个值对应对象中的一个值。如果给定对象在给定列中没有值，则应该包含空字符串 <code>""</code> 。</p>

<p>矩阵中的列应按 <strong>字典序升序</strong> 排列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
arr = [
&nbsp; {"b": 1, "a": 2},
&nbsp; {"b": 3, "a": 4}
]
<strong>输出：</strong>
[
&nbsp; ["a", "b"],
&nbsp; [2, 1],
&nbsp; [4, 3]
]

<strong>解释：</strong>
两个对象中有两个唯一的列名："a"和"b"。 
"a"对应[2, 4]。 
"b"对应[1, 3]。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>
arr = [
&nbsp; {"a": 1, "b": 2},
&nbsp; {"c": 3, "d": 4},
&nbsp; {}
]
<strong>输出：</strong>
[
&nbsp; ["a", "b", "c", "d"],
&nbsp; [1, 2, "", ""],
&nbsp; ["", "", 3, 4],
&nbsp; ["", "", "", ""]
]

<strong>解释：</strong>
有四个唯一的列名："a"、"b"、"c"、"d"。 
 第一个对象具有与"a"和"b"关联的值。 
第二个对象具有与"c"和"d"关联的值。 
第三个对象没有键，因此只是一行空字符串。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>
arr = [
&nbsp; {"a": {"b": 1, "c": 2}},
&nbsp; {"a": {"b": 3, "d": 4}}
]
<strong>输出：</strong>
[
&nbsp; ["a.b", "a.c", "a.d"],
&nbsp; [1, 2, ""],
&nbsp; [3, "", 4]
]

<strong>解释：</strong>
在这个例子中，对象是嵌套的。键表示每个值的完整路径，路径之间用句点分隔。 
有三个路径："a.b"、"a.c"、"a.d"。
</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<strong>输入：</strong>
arr = [
&nbsp; [{"a": null}],
&nbsp; [{"b": true}],
&nbsp; [{"c": "x"}]
]
<strong>输出： </strong>
[
&nbsp; ["0.a", "0.b", "0.c"],
&nbsp; [null, "", ""],
&nbsp; ["", true, ""],
&nbsp; ["", "", "x"]
]

<strong>解释：</strong>
数组也被视为具有索引为键的对象。 
每个数组只有一个元素，所以键是"0.a"、"0.b"和"0.c"。
</pre>

<p><strong class="example">示例 5：</strong></p>

<pre>
<strong>输入：</strong>
arr = [
  {},
&nbsp; {},
&nbsp; {},
]
<strong>输出：</strong>
[
&nbsp; [],
&nbsp; [],
&nbsp; [],
&nbsp; []
]

<strong>解释：</strong>
没有键，所以每一行都是一个空数组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>arr</code> 是一个有效的 JSON 数组</li>
	<li><code>1 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>unique keys &lt;= 1000</code></li>
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

#### TypeScript

```ts
function jsonToMatrix(arr: any[]): (string | number | boolean | null)[] {
    const dfs = (key: string, obj: any) => {
        if (
            typeof obj === 'number' ||
            typeof obj === 'string' ||
            typeof obj === 'boolean' ||
            obj === null
        ) {
            return { [key]: obj };
        }
        const res: any[] = [];
        for (const [k, v] of Object.entries(obj)) {
            const newKey = key ? `${key}.${k}` : `${k}`;
            res.push(dfs(newKey, v));
        }
        return res.flat();
    };

    const kv = arr.map(obj => dfs('', obj));
    const keys = [
        ...new Set(
            kv
                .flat()
                .map(obj => Object.keys(obj))
                .flat(),
        ),
    ].sort();
    const ans: any[] = [keys];
    for (const row of kv) {
        const newRow: any[] = [];
        for (const key of keys) {
            const v = row.find(r => r.hasOwnProperty(key))?.[key];
            newRow.push(v === undefined ? '' : v);
        }
        ans.push(newRow);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2676. 节流 🔒](https://leetcode.cn/problems/throttle){#2676}

{{< tabs "2676" >}}

{{% tab "ts" %}}
```ts
type F = (...args: any[]) => void;

const throttle = (fn: F, t: number): F => {
    let pending = false;
    let nextArgs;
    const wrapper = (...args) => {
        nextArgs = args;
        if (!pending) {
            fn(...args);
            pending = true;
            nextArgs = undefined;
            setTimeout(() => {
                pending = false;
                if (nextArgs) wrapper(...nextArgs);
            }, t);
        }
    };
    return wrapper;
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现给定一个函数 <code>fn</code> 和一个以毫秒为单位的时间 <code>t</code> ，请你返回该函数的 <strong>节流</strong> 版本。</p>

<p><strong>节流</strong> 函数首先立即被调用，然后在 <code>t</code> 毫秒的时间间隔内不能再次执行，但应该存储最新的函数参数，以便在延迟结束后使用这些参数调用 <code>fn</code> 。</p>

<p>例如，<code>t = 50ms</code> ，并且函数在 <code>30ms</code> 、 <code>40ms</code> 和 <code>60ms</code> 时被调用。</p>

<p>在 <code>30ms</code>，<strong>节流</strong> 函数 <code>fn</code>&nbsp;会以这些函数调用，并且对 <strong>节流</strong> 函数&nbsp;<code>fn</code> 的调用在接下来的&nbsp;<code>t</code> 毫秒会被阻塞。</p>

<p>在 <code>40ms</code>，函数应当只是存储参数。</p>

<p>在 <code>60ms</code>，参数应该覆盖第二次调用中当前存储的参数，因为第二次和第三次调用是在 <code>80ms</code> 之前进行的。延迟结束后，应该使用延迟期间提供的最新参数来调用 <strong>节流</strong> 函数 <code>fn</code>，并且它还应该创建另一个 <code>80ms + t</code> 的延迟。</p>

<p><img alt="Throttle Diagram" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2600-2699/2676.Throttle/images/screen-shot-2023-04-08-at-120313-pm.png" style="width: 1156px; height: 372px;" />上面的图示展示了节流如何转换事件。每个矩形代表100毫秒，节流时间为400毫秒。每种颜色代表不同的输入集合。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>t = 100, 
calls = [
&nbsp; {"t":20,"inputs":[1]}
]
<b>输出：</b>[{"t":20,"inputs":[1]}]
<b>解释：</b>第一次调用总是立即执行，没有延迟。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>t = 50, 
calls = [
  {"t":50,"inputs":[1]},
  {"t":75,"inputs":[2]}
]
<b>输出：</b>[{"t":50,"inputs":[1]},{"t":100,"inputs":[2]}]
<b>解释：</b>
第一次调用立即执行带有参数 (1) 的函数。 
第二次调用发生在 75毫秒 时，在延迟期间内，因为 50毫秒 + 50毫秒 = 100毫秒，所以下一次调用可以在 100毫秒 时执行。因此，我们保存第二次调用的参数，以便在第一次调用的回调函数中使用。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>t = 70, 
calls = [
  {"t":50,"inputs":[1]},
  {"t":75,"inputs":[2]},
  {"t":90,"inputs":[8]},
  {"t": 140, "inputs":[5,7]},
  {"t": 300, "inputs": [9,4]}
]
<b>输出：</b>[{"t":50,"inputs":[1]},{"t":120,"inputs":[8]},{"t":190,"inputs":[5,7]},{"t":300,"inputs":[9,4]}]
<b>解释：</b>
第一次调用立即执行带有参数 (1) 的函数。 
第二次调用发生在 75毫秒 时，在延迟期间内，因为 50毫秒 + 70毫秒 = 120毫秒，所以它只应保存参数。 
第三次调用也在延迟期间内，因为我们只需要最新的函数参数，所以覆盖之前的参数。延迟期过后，在 120毫秒时进行回调，并使用保存的参数进行调用。该回调会创建另一个延迟期间，时长为 120毫秒 + 70毫秒 = 190毫秒，以便下一个函数可以在 190毫秒时调用。 
第四次调用发生在 140毫秒，在延迟期间内，因此应在190毫秒时作为回调进行调用。这将创建另一个延迟期间，时长为 190毫秒 + 70毫秒 = 260毫秒。 
第五次调用发生在 300毫秒，但它是在 260毫秒 之后，所以应立即调用，并创建另一个延迟期间，时长为 300毫秒 + 70毫秒 = 370毫秒。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= t &lt;= 1000</code></li>
	<li><code>1 &lt;= calls.length &lt;= 10</code></li>
	<li><code>0 &lt;= calls[i].t &lt;= 1000</code></li>
	<li><code>0 &lt;= calls[i].inputs[i], calls[i].inputs.length &lt;= 10</code></li>
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

#### TypeScript

```ts
type F = (...args: any[]) => void;

const throttle = (fn: F, t: number): F => {
    let pending = false;
    let nextArgs;
    const wrapper = (...args) => {
        nextArgs = args;
        if (!pending) {
            fn(...args);
            pending = true;
            nextArgs = undefined;
            setTimeout(() => {
                pending = false;
                if (nextArgs) wrapper(...nextArgs);
            }, t);
        }
    };
    return wrapper;
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2677. 分块数组](https://leetcode.cn/problems/chunk-array){#2677}

{{< tabs "2677" >}}

{{% tab "ts" %}}
```ts
function chunk(arr: any[], size: number): any[][] {
    const ans: any[][] = [];
    for (let i = 0, n = arr.length; i < n; i += size) {
        ans.push(arr.slice(i, i + size));
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function (arr, size) {
    const ans = [];
    for (let i = 0, n = arr.length; i < n; i += size) {
        ans.push(arr.slice(i, i + size));
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

<p>给定一个数组&nbsp;<code>arr</code>&nbsp;和一个块大小&nbsp;<code>size</code>&nbsp;，返回一个 <strong>分块</strong>&nbsp;的数组。</p>

<p><strong>分块</strong>&nbsp;的数组包含了&nbsp;<code>arr</code>&nbsp;中的原始元素，但是每个子数组的长度都是&nbsp;<code>size</code>&nbsp;。如果&nbsp;<code>arr.length</code>&nbsp;不能被&nbsp;<code>size</code>&nbsp;整除，那么最后一个子数组的长度可能小于&nbsp;<code>size</code>&nbsp;。</p>

<p>你可以假设该数组是&nbsp;<code>JSON.parse</code>&nbsp;的输出结果。换句话说，它是有效的JSON。</p>

<p>请你在不使用 lodash 的函数&nbsp;<code>_.chunk</code>&nbsp;的情况下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,3,4,5], size = 1
<b>输出：</b>[[1],[2],[3],[4],[5]]
<b>解释：</b>数组 <code>arr </code>被分割成了每个只有一个元素的子数组。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [1,9,6,3,2], size = 3
<b>输出：</b>[[1,9,6],[3,2]]
<b>解释：</b>数组 <code>arr </code>被分割成了每个有三个元素的子数组。然而，第二个子数组只有两个元素。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [8,5,3,2,6], size = 6
<b>输出：</b>[[8,5,3,2,6]]
<b>解释：</b><code>size </code>大于 <code>arr.length </code>，因此所有元素都在第一个子数组中。
</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<b>输入：</b>arr = [], size = 1
<b>输出：</b>[]
<b>解释：</b>没有元素需要分块，因此返回一个空数组。</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>arr</code>&nbsp;是表示数组的字符串。</li>
	<li><code>2 &lt;= JSON.stringify(arr).length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= size &lt;= arr.length + 1</code></li>
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

#### TypeScript

```ts
function chunk(arr: any[], size: number): any[][] {
    const ans: any[][] = [];
    for (let i = 0, n = arr.length; i < n; i += size) {
        ans.push(arr.slice(i, i + size));
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function (arr, size) {
    const ans = [];
    for (let i = 0, n = arr.length; i < n; i += size) {
        ans.push(arr.slice(i, i + size));
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2678. 老人的数目](https://leetcode.cn/problems/number-of-senior-citizens){#2678}

{{< tabs "2678" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(int(x[11:13]) > 60 for x in details)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSeniors(String[] details) {
        int ans = 0;
        for (var x : details) {
            int age = Integer.parseInt(x.substring(11, 13));
            if (age > 60) {
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
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& x : details) {
            int age = stoi(x.substr(11, 2));
            ans += age > 60;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSeniors(details []string) (ans int) {
	for _, x := range details {
		age, _ := strconv.Atoi(x[11:13])
		if age > 60 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSeniors(details: string[]): number {
    return details.filter(x => +x.slice(11, 13) > 60).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        details
            .iter()
            .filter_map(|s| s[11..13].parse::<i32>().ok())
            .filter(|&age| age > 60)
            .count() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>details</code>&nbsp;。<code>details</code>&nbsp;中每个元素都是一位乘客的信息，信息用长度为 <code>15</code>&nbsp;的字符串表示，表示方式如下：</p>

<ul>
	<li>前十个字符是乘客的手机号码。</li>
	<li>接下来的一个字符是乘客的性别。</li>
	<li>接下来两个字符是乘客的年龄。</li>
	<li>最后两个字符是乘客的座位号。</li>
</ul>

<p>请你返回乘客中年龄 <strong>严格大于 60 岁</strong>&nbsp;的人数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
<b>输出：</b>2
<b>解释：</b>下标为 0 ，1 和 2 的乘客年龄分别为 75 ，92 和 40 。所以有 2 人年龄大于 60 岁。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>details = ["1313579440F2036","2921522980M5644"]
<b>输出：</b>0
<b>解释：</b>没有乘客的年龄大于 60 岁。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= details.length &lt;= 100</code></li>
	<li><code>details[i].length == 15</code></li>
	<li><code>details[i]</code>&nbsp;中的数字只包含&nbsp;<code>'0'</code>&nbsp;到&nbsp;<code>'9'</code>&nbsp;。</li>
	<li><code>details[i][10]</code>&nbsp;是 <code>'M'</code>&nbsp;，<code>'F'</code>&nbsp;或者&nbsp;<code>'O'</code>&nbsp;之一。</li>
	<li>所有乘客的手机号码和座位号互不相同。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们可以遍历 `details` 中的每个字符串 $x$，并将 $x$ 的第 $12$ 和第 $13$ 个字符（下标为 $11$, $12$）转换为整数，判断是否大于 $60$，如果是则将答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是 `details` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return sum(int(x[11:13]) > 60 for x in details)
```

#### Java

```java
class Solution {
    public int countSeniors(String[] details) {
        int ans = 0;
        for (var x : details) {
            int age = Integer.parseInt(x.substring(11, 13));
            if (age > 60) {
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
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& x : details) {
            int age = stoi(x.substr(11, 2));
            ans += age > 60;
        }
        return ans;
    }
};
```

#### Go

```go
func countSeniors(details []string) (ans int) {
	for _, x := range details {
		age, _ := strconv.Atoi(x[11:13])
		if age > 60 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countSeniors(details: string[]): number {
    return details.filter(x => +x.slice(11, 13) > 60).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        details
            .iter()
            .filter_map(|s| s[11..13].parse::<i32>().ok())
            .filter(|&age| age > 60)
            .count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2679. 矩阵中的和](https://leetcode.cn/problems/sum-in-a-matrix){#2679}

{{< tabs "2679" >}}

{{% tab "python" %}}
```python
class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        for row in nums:
            row.sort()
        return sum(map(max, zip(*nums)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int matrixSum(int[][] nums) {
        for (var row : nums) {
            Arrays.sort(row);
        }
        int ans = 0;
        for (int j = 0; j < nums[0].length; ++j) {
            int mx = 0;
            for (var row : nums) {
                mx = Math.max(mx, row[j]);
            }
            ans += mx;
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
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }
        int ans = 0;
        for (int j = 0; j < nums[0].size(); ++j) {
            int mx = 0;
            for (auto& row : nums) {
                mx = max(mx, row[j]);
            }
            ans += mx;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func matrixSum(nums [][]int) (ans int) {
	for _, row := range nums {
		sort.Ints(row)
	}
	for i := 0; i < len(nums[0]); i++ {
		mx := 0
		for _, row := range nums {
			mx = max(mx, row[i])
		}
		ans += mx
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function matrixSum(nums: number[][]): number {
    for (const row of nums) {
        row.sort((a, b) => a - b);
    }
    let ans = 0;
    for (let j = 0; j < nums[0].length; ++j) {
        let mx = 0;
        for (const row of nums) {
            mx = Math.max(mx, row[j]);
        }
        ans += mx;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn matrix_sum(mut nums: Vec<Vec<i32>>) -> i32 {
        for row in &mut nums {
            row.sort();
        }
        (0..nums[0].len())
            .map(|col| nums.iter().map(|row| row[col]).max().unwrap())
            .sum()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>nums</code>&nbsp;。一开始你的分数为&nbsp;<code>0</code>&nbsp;。你需要执行以下操作直到矩阵变为空：</p>

<ol>
	<li>矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。</li>
	<li>在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 <strong>分数</strong>&nbsp;中。</li>
</ol>

<p>请你返回最后的 <strong>分数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [[7,2,1],[6,4,2],[6,5,3],[3,2,1]]
<b>输出：</b>15
<b>解释：</b>第一步操作中，我们删除 7 ，6 ，6 和 3 ，将分数增加 7 。下一步操作中，删除 2 ，4 ，5 和 2 ，将分数增加 5 。最后删除 1 ，2 ，3 和 1 ，将分数增加 3 。所以总得分为 7 + 5 + 3 = 15 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [[1]]
<b>输出：</b>1
<b>解释：</b>我们删除 1 并将分数增加 1 ，所以返回 1 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 300</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 500</code></li>
	<li><code>0 &lt;= nums[i][j] &lt;= 10<sup>3</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们可以先遍历矩阵的每一行，将每一行排序。

接下来，遍历矩阵的每一列，找到每一列的最大值，将这些最大值相加即可。

时间复杂度 $O(m \times n \times \log n)$，空间复杂度 $(\log n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        for row in nums:
            row.sort()
        return sum(map(max, zip(*nums)))
```

#### Java

```java
class Solution {
    public int matrixSum(int[][] nums) {
        for (var row : nums) {
            Arrays.sort(row);
        }
        int ans = 0;
        for (int j = 0; j < nums[0].length; ++j) {
            int mx = 0;
            for (var row : nums) {
                mx = Math.max(mx, row[j]);
            }
            ans += mx;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for (auto& row : nums) {
            sort(row.begin(), row.end());
        }
        int ans = 0;
        for (int j = 0; j < nums[0].size(); ++j) {
            int mx = 0;
            for (auto& row : nums) {
                mx = max(mx, row[j]);
            }
            ans += mx;
        }
        return ans;
    }
};
```

#### Go

```go
func matrixSum(nums [][]int) (ans int) {
	for _, row := range nums {
		sort.Ints(row)
	}
	for i := 0; i < len(nums[0]); i++ {
		mx := 0
		for _, row := range nums {
			mx = max(mx, row[i])
		}
		ans += mx
	}
	return
}
```

#### TypeScript

```ts
function matrixSum(nums: number[][]): number {
    for (const row of nums) {
        row.sort((a, b) => a - b);
    }
    let ans = 0;
    for (let j = 0; j < nums[0].length; ++j) {
        let mx = 0;
        for (const row of nums) {
            mx = Math.max(mx, row[j]);
        }
        ans += mx;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn matrix_sum(mut nums: Vec<Vec<i32>>) -> i32 {
        for row in &mut nums {
            row.sort();
        }
        (0..nums[0].len())
            .map(|col| nums.iter().map(|row| row[col]).max().unwrap())
            .sum()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
