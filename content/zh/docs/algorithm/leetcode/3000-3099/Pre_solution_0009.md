---
title: "3080_执行操作标记数组中的元素"
date: 2025-10-08T18:39:55+08:00
weight: 9
tags: [前缀和, 动态规划, 哈希表, 堆（优先队列）, 字符串, 排序, 数学, 数据库, 数组, 模拟, 滑动窗口, 计数, 计数排序, 贪心]
---

{{< markmap >}}
### [3080_执行操作标记数组中的元素](#3080)
#### [数组](#3080)
#### [哈希表](#3080)
#### [排序](#3080)
#### [模拟](#3080)
#### [堆（优先队列）](#3080)
### [3081_替换字符串中的问号使分数最小](#3081)
#### [贪心](#3081)
#### [哈希表](#3081)
#### [字符串](#3081)
#### [计数](#3081)
#### [排序](#3081)
#### [堆（优先队列）](#3081)
### [3082_求出所有子序列的能量和](#3082)
#### [数组](#3082)
#### [动态规划](#3082)
### [3083_字符串及其反转中是否存在同一子字符串](#3083)
#### [哈希表](#3083)
#### [字符串](#3083)
### [3084_统计以给定字符开头和结尾的子字符串总数](#3084)
#### [数学](#3084)
#### [字符串](#3084)
#### [计数](#3084)
### [3085_成为 K 特殊字符串需要删除的最少字符数](#3085)
#### [贪心](#3085)
#### [哈希表](#3085)
#### [字符串](#3085)
#### [计数](#3085)
#### [排序](#3085)
### [3086_拾起 K 个 1 需要的最少行动次数](#3086)
#### [贪心](#3086)
#### [数组](#3086)
#### [前缀和](#3086)
#### [滑动窗口](#3086)
### [3087_查找热门话题标签 🔒](#3087)
#### [数据库](#3087)
### [3088_使字符串反回文 🔒](#3088)
#### [贪心](#3088)
#### [字符串](#3088)
#### [计数排序](#3088)
#### [排序](#3088)
### [3089_查找突发行为 🔒](#3089)
#### [数据库](#3089)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3080_执行操作标记数组中的元素
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 3081_替换字符串中的问号使分数最小
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
___
#### 堆（优先队列）
---
### 3082_求出所有子序列的能量和
___
#### 数组
___
#### 动态规划
---
### 3083_字符串及其反转中是否存在同一子字符串
___
#### 哈希表
___
#### 字符串
---
### 3084_统计以给定字符开头和结尾的子字符串总数
___
#### 数学
___
#### 字符串
___
#### 计数
---
### 3085_成为 K 特殊字符串需要删除的最少字符数
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
### 3086_拾起 K 个 1 需要的最少行动次数
___
#### 贪心
___
#### 数组
___
#### 前缀和
___
#### 滑动窗口
---
### 3087_查找热门话题标签 🔒
___
#### 数据库
---
### 3088_使字符串反回文 🔒
___
#### 贪心
___
#### 字符串
___
#### 计数排序
___
#### 排序
---
### 3089_查找突发行为 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 前缀和 | 动态规划 | 哈希表 |
| 堆（优先队列） | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 模拟 | 滑动窗口 | 计数 |
| 计数排序 | 贪心 |  |

# [3080. 执行操作标记数组中的元素](https://leetcode.cn/problems/mark-elements-on-array-by-performing-queries){#3080}

{{< tabs "3080" >}}

{{% tab "python" %}}
```python
class Solution:
    def unmarkedSumArray(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        s = sum(nums)
        mark = [False] * n
        arr = sorted((x, i) for i, x in enumerate(nums))
        j = 0
        ans = []
        for index, k in queries:
            if not mark[index]:
                mark[index] = True
                s -= nums[index]
            while k and j < n:
                if not mark[arr[j][1]]:
                    mark[arr[j][1]] = True
                    s -= arr[j][0]
                    k -= 1
                j += 1
            ans.append(s)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long[] unmarkedSumArray(int[] nums, int[][] queries) {
        int n = nums.length;
        long s = Arrays.stream(nums).asLongStream().sum();
        boolean[] mark = new boolean[n];
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[]{nums[i], i};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int m = queries.length;
        long[] ans = new long[m];
        for (int i = 0, j = 0; i < m; ++i) {
            int index = queries[i][0], k = queries[i][1];
            if (!mark[index]) {
                mark[index] = true;
                s -= nums[index];
            }
            for (; k > 0 && j < n; ++j) {
                if (!mark[arr[j][1]]) {
                    mark[arr[j][1]] = true;
                    s -= arr[j][0];
                    --k;
                }
            }
            ans[i] = s;
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
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        vector<bool> mark(n);
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(nums[i], i);
        }
        sort(arr.begin(), arr.end());
        vector<long long> ans;
        int m = queries.size();
        for (int i = 0, j = 0; i < m; ++i) {
            int index = queries[i][0], k = queries[i][1];
            if (!mark[index]) {
                mark[index] = true;
                s -= nums[index];
            }
            for (; k && j < n; ++j) {
                if (!mark[arr[j].second]) {
                    mark[arr[j].second] = true;
                    s -= arr[j].first;
                    --k;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func unmarkedSumArray(nums []int, queries [][]int) []int64 {
	n := len(nums)
	var s int64
	for _, x := range nums {
		s += int64(x)
	}
	mark := make([]bool, n)
	arr := make([][2]int, 0, n)
	for i, x := range nums {
		arr = append(arr, [2]int{x, i})
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i][0] == arr[j][0] {
			return arr[i][1] < arr[j][1]
		}
		return arr[i][0] < arr[j][0]
	})
	ans := make([]int64, len(queries))
	j := 0
	for i, q := range queries {
		index, k := q[0], q[1]
		if !mark[index] {
			mark[index] = true
			s -= int64(nums[index])
		}
		for ; k > 0 && j < n; j++ {
			if !mark[arr[j][1]] {
				mark[arr[j][1]] = true
				s -= int64(arr[j][0])
				k--
			}
		}
		ans[i] = s
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function unmarkedSumArray(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    let s = nums.reduce((acc, x) => acc + x, 0);
    const mark: boolean[] = Array(n).fill(false);
    const arr = nums.map((x, i) => [x, i]);
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    let j = 0;
    const ans: number[] = [];
    for (let [index, k] of queries) {
        if (!mark[index]) {
            mark[index] = true;
            s -= nums[index];
        }
        for (; k && j < n; ++j) {
            if (!mark[arr[j][1]]) {
                mark[arr[j][1]] = true;
                s -= arr[j][0];
                --k;
            }
        }
        ans.push(s);
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

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的正整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>同时给你一个长度为 <code>m</code>&nbsp;的二维操作数组&nbsp;<code>queries</code>&nbsp;，其中&nbsp;<code>queries[i] = [index<sub>i</sub>, k<sub>i</sub>]</code>&nbsp;。</p>

<p>一开始，数组中的所有元素都 <strong>未标记</strong>&nbsp;。</p>

<p>你需要依次对数组执行 <code>m</code>&nbsp;次操作，第 <code>i</code>&nbsp;次操作中，你需要执行：</p>

<ul>
	<li>如果下标&nbsp;<code>index<sub>i</sub></code>&nbsp;对应的元素还没标记，那么标记这个元素。</li>
	<li>然后标记&nbsp;<code>k<sub>i</sub></code>&nbsp;个数组中还没有标记的&nbsp;<strong>最小</strong>&nbsp;元素。如果有元素的值相等，那么优先标记它们中下标较小的。如果少于&nbsp;<code>k<sub>i</sub></code>&nbsp;个未标记元素存在，那么将它们全部标记。</li>
</ul>

<p>请你返回一个长度为 <code>m</code>&nbsp;的数组 <code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;次操作后数组中还没标记元素的&nbsp;<strong>和</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">nums = [1,2,2,1,2,3,1], queries = [[1,2],[3,3],[4,2]]</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">[8,3,0]</span></p>

<p><strong>解释：</strong></p>

<p>我们依次对数组做以下操作：</p>

<ul>
	<li>标记下标为&nbsp;<code>1</code>&nbsp;的元素，同时标记&nbsp;<code>2</code>&nbsp;个未标记的最小元素。标记完后数组为&nbsp;<code>nums = [<em><strong>1</strong></em>,<em><strong>2</strong></em>,2,<em><strong>1</strong></em>,2,3,1]</code>&nbsp;。未标记元素的和为&nbsp;<code>2 + 2 + 3 + 1 = 8</code>&nbsp;。</li>
	<li>标记下标为&nbsp;<code>3</code>&nbsp;的元素，由于它已经被标记过了，所以我们忽略这次标记，同时标记最靠前的&nbsp;<code>3</code>&nbsp;个未标记的最小元素。标记完后数组为&nbsp;<code>nums = [<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>2</strong></em>,<em><strong>1</strong></em>,<em><strong>2</strong></em>,3,<em><strong>1</strong></em>]</code>&nbsp;。未标记元素的和为&nbsp;<code>3</code>&nbsp;。</li>
	<li>标记下标为 <code>4</code>&nbsp;的元素，由于它已经被标记过了，所以我们忽略这次标记，同时标记最靠前的 <code>2</code>&nbsp;个未标记的最小元素。标记完后数组为&nbsp;<code>nums = [<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>2</strong></em>,<em><strong>1</strong></em>,<em><strong>2</strong></em>,<em><strong>3</strong></em>,<em><strong>1</strong></em>]</code>&nbsp;。未标记元素的和为&nbsp;<code>0</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">nums = [1,4,2,3], queries = [[0,1]]</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">[7]</span></p>

<p><strong>解释：</strong>我们执行一次操作，将下标为&nbsp;<code>0</code>&nbsp;处的元素标记，并且标记最靠前的&nbsp;<code>1</code>&nbsp;个未标记的最小元素。标记完后数组为&nbsp;<code>nums = [<em><strong>1</strong></em>,4,<em><strong>2</strong></em>,3]</code>&nbsp;。未标记元素的和为&nbsp;<code>4 + 3 = 7</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>m == queries.length</code></li>
	<li><code>1 &lt;= m &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>0 &lt;= index<sub>i</sub>, k<sub>i</sub> &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 模拟

我们先计算出数组 $nums$ 的总和 $s$，定义一个数组 $mark$ 用来标记数组中的元素是否被标记过，初始化所有元素都未被标记。

然后我们创建一个数组 $arr$，数组中的每个元素是一个二元组 $(x, i)$，表示数组中的第 $i$ 个元素的值为 $x$。我们对数组 $arr$ 按照元素的值进行排序，如果元素的值相等，我们按照下标从小到大的顺序进行排序。

接下来我们遍历数组 $queries$，对于每个查询 $[index, k]$，我们首先判断下标 $index$ 对应的元素是否被标记过，如果没有被标记过，我们将其标记，并且将 $s$ 减去下标 $index$ 对应的元素的值。然后我们遍历数组 $arr$，对于每个元素 $(x, i)$，如果元素 $i$ 没有被标记过，我们将其标记，并且将 $s$ 减去元素 $i$ 对应的值 $x$，直到 $k$ 为 $0$ 或者数组 $arr$ 遍历完。然后我们将 $s$ 加入答案数组中。

遍历完所有的查询后，我们就得到了答案数组。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def unmarkedSumArray(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        s = sum(nums)
        mark = [False] * n
        arr = sorted((x, i) for i, x in enumerate(nums))
        j = 0
        ans = []
        for index, k in queries:
            if not mark[index]:
                mark[index] = True
                s -= nums[index]
            while k and j < n:
                if not mark[arr[j][1]]:
                    mark[arr[j][1]] = True
                    s -= arr[j][0]
                    k -= 1
                j += 1
            ans.append(s)
        return ans
```

#### Java

```java
class Solution {
    public long[] unmarkedSumArray(int[] nums, int[][] queries) {
        int n = nums.length;
        long s = Arrays.stream(nums).asLongStream().sum();
        boolean[] mark = new boolean[n];
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[]{nums[i], i};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int m = queries.length;
        long[] ans = new long[m];
        for (int i = 0, j = 0; i < m; ++i) {
            int index = queries[i][0], k = queries[i][1];
            if (!mark[index]) {
                mark[index] = true;
                s -= nums[index];
            }
            for (; k > 0 && j < n; ++j) {
                if (!mark[arr[j][1]]) {
                    mark[arr[j][1]] = true;
                    s -= arr[j][0];
                    --k;
                }
            }
            ans[i] = s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        vector<bool> mark(n);
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(nums[i], i);
        }
        sort(arr.begin(), arr.end());
        vector<long long> ans;
        int m = queries.size();
        for (int i = 0, j = 0; i < m; ++i) {
            int index = queries[i][0], k = queries[i][1];
            if (!mark[index]) {
                mark[index] = true;
                s -= nums[index];
            }
            for (; k && j < n; ++j) {
                if (!mark[arr[j].second]) {
                    mark[arr[j].second] = true;
                    s -= arr[j].first;
                    --k;
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```

#### Go

```go
func unmarkedSumArray(nums []int, queries [][]int) []int64 {
	n := len(nums)
	var s int64
	for _, x := range nums {
		s += int64(x)
	}
	mark := make([]bool, n)
	arr := make([][2]int, 0, n)
	for i, x := range nums {
		arr = append(arr, [2]int{x, i})
	}
	sort.Slice(arr, func(i, j int) bool {
		if arr[i][0] == arr[j][0] {
			return arr[i][1] < arr[j][1]
		}
		return arr[i][0] < arr[j][0]
	})
	ans := make([]int64, len(queries))
	j := 0
	for i, q := range queries {
		index, k := q[0], q[1]
		if !mark[index] {
			mark[index] = true
			s -= int64(nums[index])
		}
		for ; k > 0 && j < n; j++ {
			if !mark[arr[j][1]] {
				mark[arr[j][1]] = true
				s -= int64(arr[j][0])
				k--
			}
		}
		ans[i] = s
	}
	return ans
}
```

#### TypeScript

```ts
function unmarkedSumArray(nums: number[], queries: number[][]): number[] {
    const n = nums.length;
    let s = nums.reduce((acc, x) => acc + x, 0);
    const mark: boolean[] = Array(n).fill(false);
    const arr = nums.map((x, i) => [x, i]);
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    let j = 0;
    const ans: number[] = [];
    for (let [index, k] of queries) {
        if (!mark[index]) {
            mark[index] = true;
            s -= nums[index];
        }
        for (; k && j < n; ++j) {
            if (!mark[arr[j][1]]) {
                mark[arr[j][1]] = true;
                s -= arr[j][0];
                --k;
            }
        }
        ans.push(s);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3081. 替换字符串中的问号使分数最小](https://leetcode.cn/problems/replace-question-marks-in-string-to-minimize-its-value){#3081}

{{< tabs "3081" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimizeStringValue(self, s: str) -> str:
        cnt = Counter(s)
        pq = [(cnt[c], c) for c in ascii_lowercase]
        heapify(pq)
        t = []
        for _ in range(s.count("?")):
            v, c = pq[0]
            t.append(c)
            heapreplace(pq, (v + 1, c))
        t.sort()
        cs = list(s)
        j = 0
        for i, c in enumerate(s):
            if c == "?":
                cs[i] = t[j]
                j += 1
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String minimizeStringValue(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        int k = 0;
        char[] cs = s.toCharArray();
        for (char c : cs) {
            if (c == '?') {
                ++k;
            } else {
                ++cnt[c - 'a'];
            }
        }
        PriorityQueue<int[]> pq
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < 26; ++i) {
            pq.offer(new int[] {cnt[i], i});
        }
        int[] t = new int[k];
        for (int j = 0; j < k; ++j) {
            int[] p = pq.poll();
            t[j] = p[1];
            pq.offer(new int[] {p[0] + 1, p[1]});
        }
        Arrays.sort(t);

        for (int i = 0, j = 0; i < n; ++i) {
            if (cs[i] == '?') {
                cs[i] = (char) (t[j++] + 'a');
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
    string minimizeStringValue(string s) {
        int cnt[26]{};
        int k = 0;
        for (char& c : s) {
            if (c == '?') {
                ++k;
            } else {
                ++cnt[c - 'a'];
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < 26; ++i) {
            pq.push({cnt[i], i});
        }
        vector<int> t(k);
        for (int i = 0; i < k; ++i) {
            auto [v, c] = pq.top();
            pq.pop();
            t[i] = c;
            pq.push({v + 1, c});
        }
        sort(t.begin(), t.end());
        int j = 0;
        for (char& c : s) {
            if (c == '?') {
                c = t[j++] + 'a';
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimizeStringValue(s string) string {
	cnt := [26]int{}
	k := 0
	for _, c := range s {
		if c == '?' {
			k++
		} else {
			cnt[c-'a']++
		}
	}
	pq := hp{}
	for i, c := range cnt {
		heap.Push(&pq, pair{c, i})
	}
	t := make([]int, k)
	for i := 0; i < k; i++ {
		p := heap.Pop(&pq).(pair)
		t[i] = p.c
		p.v++
		heap.Push(&pq, p)
	}
	sort.Ints(t)
	cs := []byte(s)
	j := 0
	for i, c := range cs {
		if c == '?' {
			cs[i] = byte(t[j] + 'a')
			j++
		}
	}
	return string(cs)
}

type pair struct{ v, c int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v || h[i].v == h[j].v && h[i].c < h[j].c }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。<code>s[i]</code>&nbsp;要么是小写英文字母，要么是问号&nbsp;<code>'?'</code>&nbsp;。</p>

<p>对于长度为 <code>m</code>&nbsp;且 <strong>只</strong>&nbsp;含有小写英文字母的字符串 <code>t</code>&nbsp;，我们定义函数&nbsp;<code>cost(i)</code>&nbsp;为下标 <code>i</code>&nbsp;之前（也就是范围 <code>[0, i - 1]</code>&nbsp;中）出现过与&nbsp;<code>t[i]</code>&nbsp;<strong>相同</strong>&nbsp;字符出现的次数。</p>

<p>字符串 <code>t</code>&nbsp;的&nbsp;<strong>分数</strong>&nbsp;为所有下标&nbsp;<code>i</code>&nbsp;的&nbsp;<code>cost(i)</code>&nbsp;之 <strong>和</strong>&nbsp;。</p>

<p>比方说，字符串&nbsp;<code>t = "aab"</code>&nbsp;：</p>

<ul>
	<li><code>cost(0) = 0</code></li>
	<li><code>cost(1) = 1</code></li>
	<li><code>cost(2) = 0</code></li>
	<li>所以，字符串&nbsp;<code>"aab"</code>&nbsp;的分数为&nbsp;<code>0 + 1 + 0 = 1</code>&nbsp;。</li>
</ul>

<p>你的任务是用小写英文字母&nbsp;<strong>替换</strong> <code>s</code>&nbsp;中 <strong>所有</strong> 问号，使 <code>s</code>&nbsp;的 <strong>分数</strong><strong>最小&nbsp;</strong>。</p>

<p>请你返回替换所有问号<em>&nbsp;</em><code>'?'</code>&nbsp;之后且分数最小的字符串。如果有多个字符串的&nbsp;<strong>分数最小</strong>&nbsp;，那么返回字典序最小的一个。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "???" </span></p>

<p><strong>输出：</strong>&nbsp;<span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">"abc" </span></p>

<p><strong>解释：</strong>这个例子中，我们将 <code>s</code>&nbsp;中的问号&nbsp;<code>'?'</code>&nbsp;替换得到&nbsp;<code>"abc"</code>&nbsp;。</p>

<p>对于字符串&nbsp;<code>"abc"</code>&nbsp;，<code>cost(0) = 0</code>&nbsp;，<code>cost(1) = 0</code>&nbsp;和&nbsp;<code>cost(2) = 0</code>&nbsp;。</p>

<p><code>"abc"</code>&nbsp;的分数为&nbsp;<code>0</code>&nbsp;。</p>

<p>其他修改 <code>s</code>&nbsp;得到分数 <code>0</code>&nbsp;的字符串为&nbsp;<code>"cba"</code>&nbsp;，<code>"abz"</code>&nbsp;和&nbsp;<code>"hey"</code>&nbsp;。</p>

<p>这些字符串中，我们返回字典序最小的。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "a?a?"</span></p>

<p><strong>输出：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">"abac"</span></p>

<p><strong>解释：</strong>这个例子中，我们将&nbsp;<code>s</code>&nbsp;中的问号&nbsp;<code>'?'</code>&nbsp;替换得到&nbsp;<code>"abac"</code>&nbsp;。</p>

<p>对于字符串&nbsp;<code>"abac"</code>&nbsp;，<code>cost(0) = 0</code>&nbsp;，<code>cost(1) = 0</code>&nbsp;，<code>cost(2) = 1</code>&nbsp;和&nbsp;<code>cost(3) = 0</code>&nbsp;。</p>

<p><code>"abac"</code>&nbsp;的分数为&nbsp;<code>1</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;要么是小写英文字母，要么是&nbsp;<code>'?'</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列

根据题目，我们可以发现，如果一个字母 $c$ 出现的次数为 $v$，那么它对答案贡献的分数为 $1 + 2 + \cdots + (v - 1) = \frac{v \times (v - 1)}{2}$。为了使得答案尽可能小，我们应该尽量替换问号为那些出现次数较少的字母。

因此，我们可以使用优先队列（小根堆）来维护每个字母的出现次数，每次取出出现次数最少的字母，将其记录到数组 $t$ 中，然后将其出现次数加一，再放回优先队列中。最后，我们将数组 $t$ 排序，然后遍历字符串 $s$，将每个问号依次替换为数组 $t$ 中的字母即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimizeStringValue(self, s: str) -> str:
        cnt = Counter(s)
        pq = [(cnt[c], c) for c in ascii_lowercase]
        heapify(pq)
        t = []
        for _ in range(s.count("?")):
            v, c = pq[0]
            t.append(c)
            heapreplace(pq, (v + 1, c))
        t.sort()
        cs = list(s)
        j = 0
        for i, c in enumerate(s):
            if c == "?":
                cs[i] = t[j]
                j += 1
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String minimizeStringValue(String s) {
        int[] cnt = new int[26];
        int n = s.length();
        int k = 0;
        char[] cs = s.toCharArray();
        for (char c : cs) {
            if (c == '?') {
                ++k;
            } else {
                ++cnt[c - 'a'];
            }
        }
        PriorityQueue<int[]> pq
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < 26; ++i) {
            pq.offer(new int[] {cnt[i], i});
        }
        int[] t = new int[k];
        for (int j = 0; j < k; ++j) {
            int[] p = pq.poll();
            t[j] = p[1];
            pq.offer(new int[] {p[0] + 1, p[1]});
        }
        Arrays.sort(t);

        for (int i = 0, j = 0; i < n; ++i) {
            if (cs[i] == '?') {
                cs[i] = (char) (t[j++] + 'a');
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
    string minimizeStringValue(string s) {
        int cnt[26]{};
        int k = 0;
        for (char& c : s) {
            if (c == '?') {
                ++k;
            } else {
                ++cnt[c - 'a'];
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < 26; ++i) {
            pq.push({cnt[i], i});
        }
        vector<int> t(k);
        for (int i = 0; i < k; ++i) {
            auto [v, c] = pq.top();
            pq.pop();
            t[i] = c;
            pq.push({v + 1, c});
        }
        sort(t.begin(), t.end());
        int j = 0;
        for (char& c : s) {
            if (c == '?') {
                c = t[j++] + 'a';
            }
        }
        return s;
    }
};
```

#### Go

```go
func minimizeStringValue(s string) string {
	cnt := [26]int{}
	k := 0
	for _, c := range s {
		if c == '?' {
			k++
		} else {
			cnt[c-'a']++
		}
	}
	pq := hp{}
	for i, c := range cnt {
		heap.Push(&pq, pair{c, i})
	}
	t := make([]int, k)
	for i := 0; i < k; i++ {
		p := heap.Pop(&pq).(pair)
		t[i] = p.c
		p.v++
		heap.Push(&pq, p)
	}
	sort.Ints(t)
	cs := []byte(s)
	j := 0
	for i, c := range cs {
		if c == '?' {
			cs[i] = byte(t[j] + 'a')
			j++
		}
	}
	return string(cs)
}

type pair struct{ v, c int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].v < h[j].v || h[i].v == h[j].v && h[i].c < h[j].c }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3082. 求出所有子序列的能量和](https://leetcode.cn/problems/find-the-sum-of-the-power-of-all-subsequences){#3082}

{{< tabs "3082" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfPower(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * k
        for x in nums:
            for j in range(k, -1, -1):
                f[j] = (f[j] * 2 + (0 if j < x else f[j - x])) % mod
        return f[k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumOfPower(int[] nums, int k) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[k + 1];
        f[0] = 1;
        for (int x : nums) {
            for (int j = k; j >= 0; --j) {
                f[j] = (f[j] * 2 % mod + (j >= x ? f[j - x] : 0)) % mod;
            }
        }
        return f[k];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int f[k + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : nums) {
            for (int j = k; j >= 0; --j) {
                f[j] = (f[j] * 2 % mod + (j >= x ? f[j - x] : 0)) % mod;
            }
        }
        return f[k];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfPower(nums []int, k int) int {
	const mod int = 1e9 + 7
	f := make([]int, k+1)
	f[0] = 1
	for _, x := range nums {
		for j := k; j >= 0; j-- {
			f[j] = f[j] * 2 % mod
			if j >= x {
				f[j] = (f[j] + f[j-x]) % mod
			}
		}
	}
	return f[k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfPower(nums: number[], k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(k + 1).fill(0);
    f[0] = 1;
    for (const x of nums) {
        for (let j = k; ~j; --j) {
            f[j] = (f[j] * 2) % mod;
            if (j >= x) {
                f[j] = (f[j] + f[j - x]) % mod;
            }
        }
    }
    return f[k];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。</p>

<p>一个整数数组的 <strong>能量</strong>&nbsp;定义为和 <strong>等于</strong>&nbsp;<code>k</code>&nbsp;的子序列的数目。</p>

<p>请你返回 <code>nums</code>&nbsp;中所有子序列的 <strong>能量和</strong>&nbsp;。</p>

<p>由于答案可能很大，请你将它对&nbsp;<code>10<sup>9</sup> + 7</code>&nbsp;<strong>取余</strong>&nbsp;后返回。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> nums = [1,2,3], k = 3 </span></p>

<p><strong>输出：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 6 </span></p>

<p><strong>解释：</strong></p>

<p>总共有&nbsp;<code>5</code>&nbsp;个能量不为 0 的子序列：</p>

<ul>
	<li>子序列&nbsp;<code>[<u><em><strong>1</strong></em></u>,<u><em><strong>2</strong></em></u>,<u><em><strong>3</strong></em></u>]</code> 有&nbsp;<code>2</code>&nbsp;个和为&nbsp;<code>3</code>&nbsp;的子序列：<code>[1,2,<u><strong><em>3</em></strong></u>]</code> 和 <code>[<u><strong><em>1</em></strong></u>,<u><strong><em>2</em></strong></u>,3]</code>&nbsp;。</li>
	<li>子序列&nbsp;<code>[<u><em><strong>1</strong></em></u>,2,<u><em><strong>3</strong></em></u>]</code>&nbsp;有 <code>1</code>&nbsp;个和为&nbsp;<code>3</code>&nbsp;的子序列：<code>[1,2,<u><strong><em>3</em></strong></u>]</code>&nbsp;。</li>
	<li>子序列&nbsp;<code>[1,<u><em><strong>2</strong></em></u>,<u><em><strong>3</strong></em></u>]</code> 有&nbsp;<code>1</code>&nbsp;个和为&nbsp;<code>3</code>&nbsp;的子序列：<code>[1,2,<u><strong><em>3</em></strong></u>]</code>&nbsp;。</li>
	<li>子序列&nbsp;<code>[<u><em><strong>1</strong></em></u>,<u><em><strong>2</strong></em></u>,3]</code>&nbsp;有&nbsp;<code>1</code>&nbsp;个和为&nbsp;<code>3</code>&nbsp;的子序列：<code>[<u><strong><em>1</em></strong></u>,<u><strong><em>2</em></strong></u>,3]</code>&nbsp;。</li>
	<li>子序列&nbsp;<code>[1,2,<u><em><strong>3</strong></em></u>]</code>&nbsp;有&nbsp;<code>1</code>&nbsp;个和为&nbsp;<code>3</code>&nbsp;的子序列：<code>[1,2,<u><strong><em>3</em></strong></u>]</code>&nbsp;。</li>
</ul>

<p>所以答案为&nbsp;<code>2 + 1 + 1 + 1 + 1 = 6</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> nums = [2,3,3], k = 5 </span></p>

<p><strong>输出：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 4 </span></p>

<p><strong>解释：</strong></p>

<p>总共有&nbsp;<code>3</code>&nbsp;个能量不为 0 的子序列：</p>

<ul>
	<li>子序列&nbsp;<code>[<u><em><strong>2</strong></em></u>,<u><em><strong>3</strong></em></u>,<u><em><strong>3</strong></em></u>]</code>&nbsp;有 2 个子序列和为&nbsp;<code>5</code>&nbsp;：<code>[<u><strong><em>2</em></strong></u>,3,<u><strong><em>3</em></strong></u>]</code> 和&nbsp;<code>[<u><strong><em>2</em></strong></u>,<u><strong><em>3</em></strong></u>,3]</code>&nbsp;。</li>
	<li>子序列&nbsp;<code>[<u><em><strong>2</strong></em></u>,3,<u><em><strong>3</strong></em></u>]</code>&nbsp;有 1 个子序列和为&nbsp;<code>5</code>&nbsp;：<code>[<u><strong><em>2</em></strong></u>,3,<u><strong><em>3</em></strong></u>]</code>&nbsp;。</li>
	<li>子序列&nbsp;<code>[<u><em><strong>2</strong></em></u>,<u><em><strong>3</strong></em></u>,3]</code>&nbsp;有 1 个子序列和为 <code>5</code>&nbsp;：<code>[<u><strong><em>2</em></strong></u>,<u><strong><em>3</em></strong></u>,3]</code>&nbsp;。</li>
</ul>

<p>所以答案为&nbsp;<code>2 + 1 + 1 = 4</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> nums = [1,2,3], k = 7 </span></p>

<p><strong>输出：</strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> 0 </span></p>

<p><strong>解释：</strong>不存在和为 <code>7</code>&nbsp;的子序列，所以 <code>nums</code>&nbsp;的能量和为&nbsp;<code>0</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

题目需要我们在给定数组 $\textit{nums}$ 中找到所有子序列 $\textit{S}$，然后计算每个 $\textit{S}$ 的每个子序列 $\textit{T}$ 的和等于 $\textit{k}$ 的方案数。

我们定义 $f[i][j]$ 表示前 $i$ 个数构成的若干个子序列中，每个子序列的子序列和等于 $j$ 的方案数。初始时 $f[0][0] = 1$，其余位置均为 $0$。

对于第 $i$ 个数 $x$，有以下三种情况：

1. 不在子序列 $\textit{S}$ 中，此时 $f[i][j] = f[i-1][j]$；
1. 在子序列 $\textit{S}$，但不在子序列 $\textit{T}$ 中，此时 $f[i][j] = f[i-1][j]$；
1. 在子序列 $\textit{S}$，且在子序列 $\textit{T}$ 中，此时 $f[i][j] = f[i-1][j-x]$。

综上，状态转移方程为：

$$
f[i][j] = f[i-1][j] \times 2 + f[i-1][j-x]
$$

最终答案为 $f[n][k]$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $k$ 为给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfPower(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        n = len(nums)
        f = [[0] * (k + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i, x in enumerate(nums, 1):
            for j in range(k + 1):
                f[i][j] = f[i - 1][j] * 2 % mod
                if j >= x:
                    f[i][j] = (f[i][j] + f[i - 1][j - x]) % mod
        return f[n][k]
```

#### Java

```java
class Solution {
    public int sumOfPower(int[] nums, int k) {
        final int mod = (int) 1e9 + 7;
        int n = nums.length;
        int[][] f = new int[n + 1][k + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = (f[i - 1][j] * 2) % mod;
                if (j >= nums[i - 1]) {
                    f[i][j] = (f[i][j] + f[i - 1][j - nums[i - 1]]) % mod;
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
    int sumOfPower(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        int f[n + 1][k + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i][j] = (f[i - 1][j] * 2) % mod;
                if (j >= nums[i - 1]) {
                    f[i][j] = (f[i][j] + f[i - 1][j - nums[i - 1]]) % mod;
                }
            }
        }
        return f[n][k];
    }
};
```

#### Go

```go
func sumOfPower(nums []int, k int) int {
	const mod int = 1e9 + 7
	n := len(nums)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, k+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := 0; j <= k; j++ {
			f[i][j] = (f[i-1][j] * 2) % mod
			if j >= nums[i-1] {
				f[i][j] = (f[i][j] + f[i-1][j-nums[i-1]]) % mod
			}
		}
	}
	return f[n][k]
}
```

#### TypeScript

```ts
function sumOfPower(nums: number[], k: number): number {
    const mod = 10 ** 9 + 7;
    const n = nums.length;
    const f: number[][] = Array.from({ length: n + 1 }, () => Array(k + 1).fill(0));
    f[0][0] = 1;
    for (let i = 1; i <= n; ++i) {
        for (let j = 0; j <= k; ++j) {
            f[i][j] = (f[i - 1][j] * 2) % mod;
            if (j >= nums[i - 1]) {
                f[i][j] = (f[i][j] + f[i - 1][j - nums[i - 1]]) % mod;
            }
        }
    }
    return f[n][k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（优化）

方法一中的状态转移方程中，$f[i][j]$ 的值只与 $f[i-1][j]$ 和 $f[i-1][j-x]$ 有关，因此我们可以优化第一维空间，从而将空间复杂度优化为 $O(k)$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $\textit{nums}$ 的长度，而 $k$ 为给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfPower(self, nums: List[int], k: int) -> int:
        mod = 10**9 + 7
        f = [1] + [0] * k
        for x in nums:
            for j in range(k, -1, -1):
                f[j] = (f[j] * 2 + (0 if j < x else f[j - x])) % mod
        return f[k]
```

#### Java

```java
class Solution {
    public int sumOfPower(int[] nums, int k) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[k + 1];
        f[0] = 1;
        for (int x : nums) {
            for (int j = k; j >= 0; --j) {
                f[j] = (f[j] * 2 % mod + (j >= x ? f[j - x] : 0)) % mod;
            }
        }
        return f[k];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int f[k + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int x : nums) {
            for (int j = k; j >= 0; --j) {
                f[j] = (f[j] * 2 % mod + (j >= x ? f[j - x] : 0)) % mod;
            }
        }
        return f[k];
    }
};
```

#### Go

```go
func sumOfPower(nums []int, k int) int {
	const mod int = 1e9 + 7
	f := make([]int, k+1)
	f[0] = 1
	for _, x := range nums {
		for j := k; j >= 0; j-- {
			f[j] = f[j] * 2 % mod
			if j >= x {
				f[j] = (f[j] + f[j-x]) % mod
			}
		}
	}
	return f[k]
}
```

#### TypeScript

```ts
function sumOfPower(nums: number[], k: number): number {
    const mod = 10 ** 9 + 7;
    const f: number[] = Array(k + 1).fill(0);
    f[0] = 1;
    for (const x of nums) {
        for (let j = k; ~j; --j) {
            f[j] = (f[j] * 2) % mod;
            if (j >= x) {
                f[j] = (f[j] + f[j - x]) % mod;
            }
        }
    }
    return f[k];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3083. 字符串及其反转中是否存在同一子字符串](https://leetcode.cn/problems/existence-of-a-substring-in-a-string-and-its-reverse){#3083}

{{< tabs "3083" >}}

{{% tab "python" %}}
```python
class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        st = {(a, b) for a, b in pairwise(s[::-1])}
        return any((a, b) in st for a, b in pairwise(s))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isSubstringPresent(String s) {
        boolean[][] st = new boolean[26][26];
        int n = s.length();
        for (int i = 0; i < n - 1; ++i) {
            st[s.charAt(i + 1) - 'a'][s.charAt(i) - 'a'] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (st[s.charAt(i) - 'a'][s.charAt(i + 1) - 'a']) {
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
    bool isSubstringPresent(string s) {
        bool st[26][26]{};
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            st[s[i + 1] - 'a'][s[i] - 'a'] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (st[s[i] - 'a'][s[i + 1] - 'a']) {
                return true;
            }
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isSubstringPresent(s string) bool {
	st := [26][26]bool{}
	for i := 0; i < len(s)-1; i++ {
		st[s[i+1]-'a'][s[i]-'a'] = true
	}
	for i := 0; i < len(s)-1; i++ {
		if st[s[i]-'a'][s[i+1]-'a'] {
			return true
		}
	}
	return false
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isSubstringPresent(s: string): boolean {
    const st: boolean[][] = Array.from({ length: 26 }, () => Array(26).fill(false));
    for (let i = 0; i < s.length - 1; ++i) {
        st[s.charCodeAt(i + 1) - 97][s.charCodeAt(i) - 97] = true;
    }
    for (let i = 0; i < s.length - 1; ++i) {
        if (st[s.charCodeAt(i) - 97][s.charCodeAt(i + 1) - 97]) {
            return true;
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

<p>给你一个字符串 <code>s</code> ，请你判断字符串 <code>s</code> 是否存在一个长度为 <code>2</code> 的子字符串，在 <code>s</code> 反转后的字符串中也出现。</p>

<p>如果存在这样的子字符串，返回 <code>true</code>；如果不存在，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "leetcode"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">true</span></p>

<p><strong>解释：</strong>子字符串 <code>"ee"</code> 的长度为 <code>2</code>，它也出现在 <code>reverse(s) == "edocteel"</code> 中。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "abcba"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">true</span></p>

<p><strong>解释：</strong>所有长度为 <code>2</code> 的子字符串 <code>"ab"</code>、<code>"bc"</code>、<code>"cb"</code>、<code>"ba"</code> 也都出现在 <code>reverse(s) == "abcba"</code> 中。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "abcd"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">false</span></p>

<p><strong>解释：</strong>字符串 <code>s</code> 中不存在满足「在其反转后的字符串中也出现」且长度为 <code>2</code> 的子字符串。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li>字符串 <code>s</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们可以用一个哈希表或者二维数组 $st$ 来存储字符串 $s$ 反转后的所有长度为 $2$ 的子字符串。

然后我们遍历字符串 $s$，对于每一个长度为 $2$ 的子字符串，我们判断它是否在 $st$ 中出现过，是则返回 `true`。否则，遍历结束后返回 `false`。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|^2)$。其中 $n$ 为字符串 $s$ 的长度；而 $\Sigma$ 为字符串 $s$ 的字符集，本题中 $\Sigma$ 为小写英文字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        st = {(a, b) for a, b in pairwise(s[::-1])}
        return any((a, b) in st for a, b in pairwise(s))
```

#### Java

```java
class Solution {
    public boolean isSubstringPresent(String s) {
        boolean[][] st = new boolean[26][26];
        int n = s.length();
        for (int i = 0; i < n - 1; ++i) {
            st[s.charAt(i + 1) - 'a'][s.charAt(i) - 'a'] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (st[s.charAt(i) - 'a'][s.charAt(i + 1) - 'a']) {
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
    bool isSubstringPresent(string s) {
        bool st[26][26]{};
        int n = s.size();
        for (int i = 0; i < n - 1; ++i) {
            st[s[i + 1] - 'a'][s[i] - 'a'] = true;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (st[s[i] - 'a'][s[i + 1] - 'a']) {
                return true;
            }
        }
        return false;
    }
};
```

#### Go

```go
func isSubstringPresent(s string) bool {
	st := [26][26]bool{}
	for i := 0; i < len(s)-1; i++ {
		st[s[i+1]-'a'][s[i]-'a'] = true
	}
	for i := 0; i < len(s)-1; i++ {
		if st[s[i]-'a'][s[i+1]-'a'] {
			return true
		}
	}
	return false
}
```

#### TypeScript

```ts
function isSubstringPresent(s: string): boolean {
    const st: boolean[][] = Array.from({ length: 26 }, () => Array(26).fill(false));
    for (let i = 0; i < s.length - 1; ++i) {
        st[s.charCodeAt(i + 1) - 97][s.charCodeAt(i) - 97] = true;
    }
    for (let i = 0; i < s.length - 1; ++i) {
        if (st[s.charCodeAt(i) - 97][s.charCodeAt(i + 1) - 97]) {
            return true;
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

# [3084. 统计以给定字符开头和结尾的子字符串总数](https://leetcode.cn/problems/count-substrings-starting-and-ending-with-given-character){#3084}

{{< tabs "3084" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        cnt = s.count(c)
        return cnt + cnt * (cnt - 1) // 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countSubstrings(String s, char c) {
        long cnt = s.chars().filter(ch -> ch == c).count();
        return cnt + cnt * (cnt - 1) / 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = ranges::count(s, c);
        return cnt + cnt * (cnt - 1) / 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubstrings(s string, c byte) int64 {
	cnt := int64(strings.Count(s, string(c)))
	return cnt + cnt*(cnt-1)/2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubstrings(s: string, c: string): number {
    const cnt = s.split('').filter(ch => ch === c).length;
    return cnt + Math.floor((cnt * (cnt - 1)) / 2);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个字符 <code>c </code>。返回在字符串 <code>s</code> 中并且以 <code>c</code> 字符开头和结尾的<span data-keyword="substring-nonempty">非空子字符串</span>的总数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "abada", c = "a"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">6</span></p>

<p><strong>解释：</strong>以 <code>"a"</code> 开头和结尾的子字符串有： <code>"<strong><u>a</u></strong>bada"</code>、<code>"<u><strong>aba</strong></u>da"</code>、<code>"<u><strong>abada</strong></u>"</code>、<code>"ab<u><strong>a</strong></u>da"</code>、<code>"ab<u><strong>ada</strong></u>"</code>、<code>"abad<u><strong>a</strong></u>"</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "zzz", c = "z"</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">6</span></p>

<p><strong>解释：</strong>字符串 <code>s</code> 中总共有 <code>6</code> 个子字符串，并且它们都以 <code>"z"</code> 开头和结尾。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> 和 <code>c</code> 均由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们可以先统计字符串 $s$ 中字符 $c$ 的个数，记为 $cnt$。

每个 $c$ 字符可以单独作为一个子字符串，所以有 $cnt$ 个子字符串满足条件。每个 $c$ 字符可以和其他 $c$ 字符组成一个满足条件的子字符串，所以有 $\frac{cnt \times (cnt - 1)}{2}$ 个子字符串满足条件。

所以答案为 $cnt + \frac{cnt \times (cnt - 1)}{2}$。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        cnt = s.count(c)
        return cnt + cnt * (cnt - 1) // 2
```

#### Java

```java
class Solution {
    public long countSubstrings(String s, char c) {
        long cnt = s.chars().filter(ch -> ch == c).count();
        return cnt + cnt * (cnt - 1) / 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = ranges::count(s, c);
        return cnt + cnt * (cnt - 1) / 2;
    }
};
```

#### Go

```go
func countSubstrings(s string, c byte) int64 {
	cnt := int64(strings.Count(s, string(c)))
	return cnt + cnt*(cnt-1)/2
}
```

#### TypeScript

```ts
function countSubstrings(s: string, c: string): number {
    const cnt = s.split('').filter(ch => ch === c).length;
    return cnt + Math.floor((cnt * (cnt - 1)) / 2);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3085. 成为 K 特殊字符串需要删除的最少字符数](https://leetcode.cn/problems/minimum-deletions-to-make-string-k-special){#3085}

{{< tabs "3085" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        def f(v: int) -> int:
            ans = 0
            for x in nums:
                if x < v:
                    ans += x
                elif x > v + k:
                    ans += x - v - k
            return ans

        nums = Counter(word).values()
        return min(f(v) for v in range(len(word) + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<Integer> nums = new ArrayList<>();

    public int minimumDeletions(String word, int k) {
        int[] freq = new int[26];
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            ++freq[word.charAt(i) - 'a'];
        }
        for (int v : freq) {
            if (v > 0) {
                nums.add(v);
            }
        }
        int ans = n;
        for (int i = 0; i <= n; ++i) {
            ans = Math.min(ans, f(i, k));
        }
        return ans;
    }

    private int f(int v, int k) {
        int ans = 0;
        for (int x : nums) {
            if (x < v) {
                ans += x;
            } else if (x > v + k) {
                ans += x - v - k;
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
    int minimumDeletions(string word, int k) {
        int freq[26]{};
        for (char& c : word) {
            ++freq[c - 'a'];
        }
        vector<int> nums;
        for (int v : freq) {
            if (v) {
                nums.push_back(v);
            }
        }
        int n = word.size();
        int ans = n;
        auto f = [&](int v) {
            int ans = 0;
            for (int x : nums) {
                if (x < v) {
                    ans += x;
                } else if (x > v + k) {
                    ans += x - v - k;
                }
            }
            return ans;
        };
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, f(i));
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDeletions(word string, k int) int {
	freq := [26]int{}
	for _, c := range word {
		freq[c-'a']++
	}
	nums := []int{}
	for _, v := range freq {
		if v > 0 {
			nums = append(nums, v)
		}
	}
	f := func(v int) int {
		ans := 0
		for _, x := range nums {
			if x < v {
				ans += x
			} else if x > v+k {
				ans += x - v - k
			}
		}
		return ans
	}
	ans := len(word)
	for i := 0; i <= len(word); i++ {
		ans = min(ans, f(i))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDeletions(word: string, k: number): number {
    const freq: number[] = Array(26).fill(0);
    for (const ch of word) {
        ++freq[ch.charCodeAt(0) - 97];
    }
    const nums = freq.filter(x => x > 0);
    const f = (v: number): number => {
        let ans = 0;
        for (const x of nums) {
            if (x < v) {
                ans += x;
            } else if (x > v + k) {
                ans += x - v - k;
            }
        }
        return ans;
    };
    return Math.min(...Array.from({ length: word.length + 1 }, (_, i) => f(i)));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_deletions(word: String, k: i32) -> i32 {
        let mut freq = [0; 26];
        for c in word.chars() {
            freq[(c as u8 - b'a') as usize] += 1;
        }
        let mut nums = vec![];
        for &v in freq.iter() {
            if v > 0 {
                nums.push(v);
            }
        }
        let n = word.len() as i32;
        let mut ans = n;
        for i in 0..=n {
            let mut cur = 0;
            for &x in nums.iter() {
                if x < i {
                    cur += x;
                } else if x > i + k {
                    cur += x - i - k;
                }
            }
            ans = ans.min(cur);
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

<p>给你一个字符串 <code>word</code> 和一个整数 <code>k</code>。</p>

<p>如果&nbsp;<code>|freq(word[i]) - freq(word[j])| &lt;= k</code> 对于字符串中所有下标 <code>i</code> 和 <code>j</code>&nbsp; 都成立，则认为 <code>word</code> 是 <strong>k 特殊字符串</strong>。</p>

<p>此处，<code>freq(x)</code> 表示字符 <code>x</code> 在 <code>word</code> 中的<span data-keyword="frequency-letter">出现频率</span>，而 <code>|y|</code> 表示 <code>y</code> 的绝对值。</p>

<p>返回使 <code>word</code> 成为 <strong>k 特殊字符串</strong> 需要删除的字符的最小数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = "aabcaba", k = 0</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">3</span></p>

<p><strong>解释：</strong>可以删除 <code>2</code> 个 <code>"a"</code> 和 <code>1</code> 个 <code>"c"</code> 使 <code>word</code> 成为 <code>0</code> 特殊字符串。<code>word</code> 变为 <code>"baba"</code>，此时 <code>freq('a') == freq('b') == 2</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = "dabdcbdcdcd", k = 2</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">2</span></p>

<p><strong>解释：</strong>可以删除 <code>1</code> 个 <code>"a"</code> 和 <code>1</code> 个 <code>"d"</code> 使 <code>word</code> 成为 <code>2</code> 特殊字符串。<code>word</code> 变为 <code>"bdcbdcdcd"</code>，此时 <code>freq('b') == 2</code>，<code>freq('c') == 3</code>，<code>freq('d') == 4</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = "aaabaaa", k = 2</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">1</span></p>

<p><strong>解释：</strong>可以删除<strong> </strong>1 个 <code>"b"</code> 使 <code>word</code> 成为 <code>2</code>特殊字符串。因此，<code>word</code> 变为 <code>"aaaaaa"</code>，此时每个字母的频率都是 <code>6</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们可以先统计字符串中每个字符的出现次数，将所有次数放入数组 $nums$ 中，由于题目中字符串只包含小写字母，所以数组 $nums$ 的长度不会超过 $26$。

接下来，我们可以枚举在 $[0,..n]$ 的范围内枚举 $K$ 特殊字符串中的字符最小频率 $v$，然后用一个函数 $f(v)$ 来计算将所有字符的频率调整为 $v$ 的最小删除次数，最后取所有 $f(v)$ 的最小值即为答案。

函数 $f(v)$ 的计算方法如下：

遍历数组 $nums$ 中的每个元素 $x$，如果 $x \lt v$，则说明我们需要将出现次数为 $x$ 的字符全部删除，删除次数为 $x$；如果 $x \gt v + k$，则说明我们需要将出现次数为 $x$ 的字符全部调整为 $v + k$，删除次数为 $x - v - k$。累加所有删除次数即为 $f(v)$ 的值。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 为字符串长度；而 $|\Sigma|$ 为字符集大小，本题中 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        def f(v: int) -> int:
            ans = 0
            for x in nums:
                if x < v:
                    ans += x
                elif x > v + k:
                    ans += x - v - k
            return ans

        nums = Counter(word).values()
        return min(f(v) for v in range(len(word) + 1))
```

#### Java

```java
class Solution {
    private List<Integer> nums = new ArrayList<>();

    public int minimumDeletions(String word, int k) {
        int[] freq = new int[26];
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            ++freq[word.charAt(i) - 'a'];
        }
        for (int v : freq) {
            if (v > 0) {
                nums.add(v);
            }
        }
        int ans = n;
        for (int i = 0; i <= n; ++i) {
            ans = Math.min(ans, f(i, k));
        }
        return ans;
    }

    private int f(int v, int k) {
        int ans = 0;
        for (int x : nums) {
            if (x < v) {
                ans += x;
            } else if (x > v + k) {
                ans += x - v - k;
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
    int minimumDeletions(string word, int k) {
        int freq[26]{};
        for (char& c : word) {
            ++freq[c - 'a'];
        }
        vector<int> nums;
        for (int v : freq) {
            if (v) {
                nums.push_back(v);
            }
        }
        int n = word.size();
        int ans = n;
        auto f = [&](int v) {
            int ans = 0;
            for (int x : nums) {
                if (x < v) {
                    ans += x;
                } else if (x > v + k) {
                    ans += x - v - k;
                }
            }
            return ans;
        };
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, f(i));
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDeletions(word string, k int) int {
	freq := [26]int{}
	for _, c := range word {
		freq[c-'a']++
	}
	nums := []int{}
	for _, v := range freq {
		if v > 0 {
			nums = append(nums, v)
		}
	}
	f := func(v int) int {
		ans := 0
		for _, x := range nums {
			if x < v {
				ans += x
			} else if x > v+k {
				ans += x - v - k
			}
		}
		return ans
	}
	ans := len(word)
	for i := 0; i <= len(word); i++ {
		ans = min(ans, f(i))
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDeletions(word: string, k: number): number {
    const freq: number[] = Array(26).fill(0);
    for (const ch of word) {
        ++freq[ch.charCodeAt(0) - 97];
    }
    const nums = freq.filter(x => x > 0);
    const f = (v: number): number => {
        let ans = 0;
        for (const x of nums) {
            if (x < v) {
                ans += x;
            } else if (x > v + k) {
                ans += x - v - k;
            }
        }
        return ans;
    };
    return Math.min(...Array.from({ length: word.length + 1 }, (_, i) => f(i)));
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_deletions(word: String, k: i32) -> i32 {
        let mut freq = [0; 26];
        for c in word.chars() {
            freq[(c as u8 - b'a') as usize] += 1;
        }
        let mut nums = vec![];
        for &v in freq.iter() {
            if v > 0 {
                nums.push(v);
            }
        }
        let n = word.len() as i32;
        let mut ans = n;
        for i in 0..=n {
            let mut cur = 0;
            for &x in nums.iter() {
                if x < i {
                    cur += x;
                } else if x > i + k {
                    cur += x - i - k;
                }
            }
            ans = ans.min(cur);
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

# [3086. 拾起 K 个 1 需要的最少行动次数](https://leetcode.cn/problems/minimum-moves-to-pick-k-ones){#3086}

{{< tabs "3086" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumMoves(self, nums: List[int], k: int, maxChanges: int) -> int:
        n = len(nums)
        cnt = [0] * (n + 1)
        s = [0] * (n + 1)
        for i, x in enumerate(nums, 1):
            cnt[i] = cnt[i - 1] + x
            s[i] = s[i - 1] + i * x
        ans = inf
        max = lambda x, y: x if x > y else y
        min = lambda x, y: x if x < y else y
        for i, x in enumerate(nums, 1):
            t = 0
            need = k - x
            for j in (i - 1, i + 1):
                if need > 0 and 1 <= j <= n and nums[j - 1] == 1:
                    need -= 1
                    t += 1
            c = min(need, maxChanges)
            need -= c
            t += c * 2
            if need <= 0:
                ans = min(ans, t)
                continue
            l, r = 2, max(i - 1, n - i)
            while l <= r:
                mid = (l + r) >> 1
                l1, r1 = max(1, i - mid), max(0, i - 2)
                l2, r2 = min(n + 1, i + 2), min(n, i + mid)
                c1 = cnt[r1] - cnt[l1 - 1]
                c2 = cnt[r2] - cnt[l2 - 1]
                if c1 + c2 >= need:
                    t1 = c1 * i - (s[r1] - s[l1 - 1])
                    t2 = s[r2] - s[l2 - 1] - c2 * i
                    ans = min(ans, t + t1 + t2)
                    r = mid - 1
                else:
                    l = mid + 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimumMoves(int[] nums, int k, int maxChanges) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            cnt[i] = cnt[i - 1] + nums[i - 1];
            s[i] = s[i - 1] + i * nums[i - 1];
        }
        long ans = Long.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            long t = 0;
            int need = k - nums[i - 1];
            for (int j = i - 1; j <= i + 1; j += 2) {
                if (need > 0 && 1 <= j && j <= n && nums[j - 1] == 1) {
                    --need;
                    ++t;
                }
            }
            int c = Math.min(need, maxChanges);
            need -= c;
            t += c * 2;
            if (need <= 0) {
                ans = Math.min(ans, t);
                continue;
            }
            int l = 2, r = Math.max(i - 1, n - i);
            while (l <= r) {
                int mid = (l + r) >> 1;
                int l1 = Math.max(1, i - mid), r1 = Math.max(0, i - 2);
                int l2 = Math.min(n + 1, i + 2), r2 = Math.min(n, i + mid);
                int c1 = cnt[r1] - cnt[l1 - 1];
                int c2 = cnt[r2] - cnt[l2 - 1];
                if (c1 + c2 >= need) {
                    long t1 = 1L * c1 * i - (s[r1] - s[l1 - 1]);
                    long t2 = s[r2] - s[l2 - 1] - 1L * c2 * i;
                    ans = Math.min(ans, t + t1 + t2);
                    r = mid - 1;
                } else {
                    l = mid + 1;
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
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        vector<long long> s(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            cnt[i] = cnt[i - 1] + nums[i - 1];
            s[i] = s[i - 1] + 1LL * i * nums[i - 1];
        }

        long long ans = LLONG_MAX;

        for (int i = 1; i <= n; ++i) {
            long long t = 0;
            int need = k - nums[i - 1];

            for (int j = i - 1; j <= i + 1; j += 2) {
                if (need > 0 && 1 <= j && j <= n && nums[j - 1] == 1) {
                    --need;
                    ++t;
                }
            }

            int c = min(need, maxChanges);
            need -= c;
            t += c * 2;

            if (need <= 0) {
                ans = min(ans, t);
                continue;
            }

            int l = 2, r = max(i - 1, n - i);

            while (l <= r) {
                int mid = (l + r) / 2;
                int l1 = max(1, i - mid), r1 = max(0, i - 2);
                int l2 = min(n + 1, i + 2), r2 = min(n, i + mid);

                int c1 = cnt[r1] - cnt[l1 - 1];
                int c2 = cnt[r2] - cnt[l2 - 1];

                if (c1 + c2 >= need) {
                    long long t1 = 1LL * c1 * i - (s[r1] - s[l1 - 1]);
                    long long t2 = s[r2] - s[l2 - 1] - 1LL * c2 * i;
                    ans = min(ans, t + t1 + t2);
                    r = mid - 1;
                } else {
                    l = mid + 1;
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
func minimumMoves(nums []int, k int, maxChanges int) int64 {
	n := len(nums)
	cnt := make([]int, n+1)
	s := make([]int, n+1)

	for i := 1; i <= n; i++ {
		cnt[i] = cnt[i-1] + nums[i-1]
		s[i] = s[i-1] + i*nums[i-1]
	}

	ans := math.MaxInt64

	for i := 1; i <= n; i++ {
		t := 0
		need := k - nums[i-1]

		for _, j := range []int{i - 1, i + 1} {
			if need > 0 && 1 <= j && j <= n && nums[j-1] == 1 {
				need--
				t++
			}
		}

		c := min(need, maxChanges)
		need -= c
		t += c * 2

		if need <= 0 {
			ans = min(ans, t)
			continue
		}

		l, r := 2, max(i-1, n-i)

		for l <= r {
			mid := (l + r) >> 1
			l1, r1 := max(1, i-mid), max(0, i-2)
			l2, r2 := min(n+1, i+2), min(n, i+mid)

			c1 := cnt[r1] - cnt[l1-1]
			c2 := cnt[r2] - cnt[l2-1]

			if c1+c2 >= need {
				t1 := c1*i - (s[r1] - s[l1-1])
				t2 := s[r2] - s[l2-1] - c2*i
				ans = min(ans, t+t1+t2)
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
	}

	return int64(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumMoves(nums: number[], k: number, maxChanges: number): number {
    const n = nums.length;
    const cnt = Array(n + 1).fill(0);
    const s = Array(n + 1).fill(0);

    for (let i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + nums[i - 1];
        s[i] = s[i - 1] + i * nums[i - 1];
    }

    let ans = Infinity;
    for (let i = 1; i <= n; i++) {
        let t = 0;
        let need = k - nums[i - 1];

        for (let j of [i - 1, i + 1]) {
            if (need > 0 && 1 <= j && j <= n && nums[j - 1] === 1) {
                need--;
                t++;
            }
        }

        const c = Math.min(need, maxChanges);
        need -= c;
        t += c * 2;

        if (need <= 0) {
            ans = Math.min(ans, t);
            continue;
        }

        let l = 2,
            r = Math.max(i - 1, n - i);

        while (l <= r) {
            const mid = (l + r) >> 1;
            const [l1, r1] = [Math.max(1, i - mid), Math.max(0, i - 2)];
            const [l2, r2] = [Math.min(n + 1, i + 2), Math.min(n, i + mid)];

            const c1 = cnt[r1] - cnt[l1 - 1];
            const c2 = cnt[r2] - cnt[l2 - 1];

            if (c1 + c2 >= need) {
                const t1 = c1 * i - (s[r1] - s[l1 - 1]);
                const t2 = s[r2] - s[l2 - 1] - c2 * i;
                ans = Math.min(ans, t + t1 + t2);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
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

<p>给你一个下标从 <strong>0</strong> 开始的二进制数组 <code>nums</code>，其长度为 <code>n</code> ；另给你一个 <strong>正整数 </strong><code>k</code> 以及一个 <strong>非负整数 </strong><code>maxChanges</code> 。</p>

<p>Alice 在玩一个游戏，游戏的目标是让&nbsp;Alice 使用 <strong>最少 </strong>数量的 <strong>行动 </strong>次数从 <code>nums</code> 中拾起 <code>k</code> 个 1 。游戏开始时，Alice 可以选择数组 <code>[0, n - 1]</code> 范围内的任何索引&nbsp;<code>aliceIndex</code> 站立。如果 <code>nums[aliceIndex] == 1</code> ，Alice 会拾起一个 1 ，并且 <code>nums[aliceIndex]</code> 变成<code>0</code>（这<strong> 不算 </strong>作一次行动）。之后，Alice 可以执行 <strong>任意数量</strong> 的 <strong>行动</strong>（<strong>包括</strong><strong>零次</strong>），在每次行动中&nbsp;Alice 必须 <strong>恰好 </strong>执行以下动作之一：</p>

<ul>
	<li>选择任意一个下标 <code>j != aliceIndex</code> 且满足 <code>nums[j] == 0</code> ，然后将 <code>nums[j]</code> 设置为 <code>1</code> 。这个动作最多可以执行 <code>maxChanges</code> 次。</li>
	<li>选择任意两个相邻的下标 <code>x</code> 和 <code>y</code>（<code>|x - y| == 1</code>）且满足 <code>nums[x] == 1</code>, <code>nums[y] == 0</code> ，然后交换它们的值（将 <code>nums[y] = 1</code> 和 <code>nums[x] = 0</code>）。如果 <code>y == aliceIndex</code>，在这次行动后&nbsp;Alice 拾起一个 1 ，并且 <code>nums[y]</code> 变成 <code>0</code> 。</li>
</ul>

<p>返回&nbsp;Alice 拾起 <strong>恰好 </strong><code>k</code> 个 1 所需的 <strong>最少 </strong>行动次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">nums = [1,1,0,0,0,1,1,0,0,1], k = 3, maxChanges = 1</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">3</span></p>

<p><strong>解释：</strong>如果游戏开始时&nbsp;Alice 在 <code>aliceIndex == 1</code> 的位置上，按照以下步骤执行每个动作，他可以利用 <code>3</code> 次行动拾取 <code>3</code> 个 1 ：</p>

<ul>
	<li>游戏开始时&nbsp;Alice 拾取了一个 1 ，<code>nums[1]</code> 变成了 <code>0</code>。此时 <code>nums</code> 变为 <code>[1,<strong><u>0</u></strong>,0,0,0,1,1,0,0,1]</code> 。</li>
	<li>选择 <code>j == 2</code> 并执行第一种类型的动作。<code>nums</code> 变为 <code>[1,<strong><u>0</u></strong>,1,0,0,1,1,0,0,1]</code></li>
	<li>选择 <code>x == 2</code> 和 <code>y == 1</code> ，并执行第二种类型的动作。<code>nums</code> 变为 <code>[1,<strong><u>1</u></strong>,0,0,0,1,1,0,0,1]</code> 。由于 <code>y == aliceIndex</code>，Alice 拾取了一个 1 ，<code>nums</code> 变为&nbsp; <code>[1,<strong><u>0</u></strong>,0,0,0,1,1,0,0,1]</code> 。</li>
	<li>选择 <code>x == 0</code> 和 <code>y == 1</code> ，并执行第二种类型的动作。<code>nums</code> 变为 <code>[0,<strong><u>1</u></strong>,0,0,0,1,1,0,0,1]</code> 。由于 <code>y == aliceIndex</code>，Alice 拾取了一个 1 ，<code>nums</code> 变为&nbsp; <code>[0,<strong><u>0</u></strong>,0,0,0,1,1,0,0,1]</code> 。</li>
</ul>

<p>请注意，Alice 也可能执行其他的 <code>3</code> 次行动序列达成拾取 <code>3</code> 个 1 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;"><!-- 以下是示例内容的中文翻译，同时保留了原有的HTML格式和注释 -->
<p><strong>输入：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">nums = [0,0,0,0], k = 2, maxChanges = 3</span></p>

<p><strong>输出：</strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">4</span></p>

<p><strong>解释：</strong>如果游戏开始时&nbsp;Alice 在 <code>aliceIndex == 0</code> 的位置上，按照以下步骤执行每个动作，他可以利用 <code>4</code> 次行动拾取 <code>2</code> 个 1 ：</p>

<ul>
	<li>选择 <code>j == 1</code> 并执行第一种类型的动作。<code>nums</code> 变为 <code>[<strong><u>0</u></strong>,1,0,0]</code> 。</li>
	<li>选择 <code>x == 1</code> 和 <code>y == 0</code> ，并执行第二种类型的动作。<code>nums</code> 变为 <code>[<strong><u>1</u></strong>,0,0,0]</code> 。由于 <code>y == aliceIndex</code>，Alice 拾起了一个 1 ，<code>nums</code> 变为 <code>[<strong><u>0</u></strong>,0,0,0]</code> 。</li>
	<li>再次选择 <code>j == 1</code> 并执行第一种类型的动作。<code>nums</code> 变为 <code>[<strong><u>0</u></strong>,1,0,0]</code> 。</li>
	<li>再次选择 <code>x == 1</code> 和 <code>y == 0</code> ，并执行第二种类型的动作。<code>nums</code> 变为 <code>[<strong><u>1</u></strong>,0,0,0]</code> 。由于<code>y == aliceIndex</code>，Alice 拾起了一个 1 ，<code>nums</code> 变为 <code>[<strong><u>0</u></strong>,0,0,0]</code> 。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= maxChanges &lt;= 10<sup>5</sup></code></li>
	<li><code>maxChanges + sum(nums) &gt;= k</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 前缀和 + 二分查找

我们考虑枚举 Alice 的站立位置 $i$，对于每个 $i$，我们按照如下的策略进行操作：

-   首先，如果位置 $i$ 的数字为 $1$，我们可以直接拾取一个 $1$，不需要行动次数。
-   然后，我们对 $i$ 的左右两侧位置的数字 $1$ 进行拾取，执行的是行动 $2$，即把位置 $i-1$ 的 $1$ 移到位置 $i$，然后拾取；把位置 $i+1$ 的 $1$ 移到位置 $i$，然后拾取。每拾取一个 $1$，需要 $1$ 次行动。
-   接下来，我们最大限度地将 $i-1$ 或 $i+1$ 上的 $0$，利用行动 $1$，将其置为 $1$，然后利用行动 $2$，将其移动到位置 $i$，拾取。直到拾取的 $1$ 的数量达到 $k$ 或者行动 $1$ 的次数达到 $\textit{maxChanges}$。我们假设行动 $1$ 的次数为 $c$，那么总共需要 $2c$ 次行动。
-   利用完行动 $1$，如果拾取的 $1$ 的数量还没有达到 $k$，我们需要继续考虑在 $[1,..i-2]$ 和 $[i+2,..n]$ 的区间内，进行行动 $2$，将 $1$ 移动到位置 $i$，拾取。我们可以使用二分查找来确定这个区间的大小，使得拾取的 $1$ 的数量达到 $k$。具体地，我们二分枚举一个区间的大小 $d$，然后在区间 $[i-d,..i-2]$ 和 $[i+2,..i+d]$ 内，进行行动 $2$，将 $1$ 移动到位置 $i$，拾取。如果拾取的 $1$ 的数量达到 $k$，我们就更新答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumMoves(self, nums: List[int], k: int, maxChanges: int) -> int:
        n = len(nums)
        cnt = [0] * (n + 1)
        s = [0] * (n + 1)
        for i, x in enumerate(nums, 1):
            cnt[i] = cnt[i - 1] + x
            s[i] = s[i - 1] + i * x
        ans = inf
        max = lambda x, y: x if x > y else y
        min = lambda x, y: x if x < y else y
        for i, x in enumerate(nums, 1):
            t = 0
            need = k - x
            for j in (i - 1, i + 1):
                if need > 0 and 1 <= j <= n and nums[j - 1] == 1:
                    need -= 1
                    t += 1
            c = min(need, maxChanges)
            need -= c
            t += c * 2
            if need <= 0:
                ans = min(ans, t)
                continue
            l, r = 2, max(i - 1, n - i)
            while l <= r:
                mid = (l + r) >> 1
                l1, r1 = max(1, i - mid), max(0, i - 2)
                l2, r2 = min(n + 1, i + 2), min(n, i + mid)
                c1 = cnt[r1] - cnt[l1 - 1]
                c2 = cnt[r2] - cnt[l2 - 1]
                if c1 + c2 >= need:
                    t1 = c1 * i - (s[r1] - s[l1 - 1])
                    t2 = s[r2] - s[l2 - 1] - c2 * i
                    ans = min(ans, t + t1 + t2)
                    r = mid - 1
                else:
                    l = mid + 1
        return ans
```

#### Java

```java
class Solution {
    public long minimumMoves(int[] nums, int k, int maxChanges) {
        int n = nums.length;
        int[] cnt = new int[n + 1];
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; ++i) {
            cnt[i] = cnt[i - 1] + nums[i - 1];
            s[i] = s[i - 1] + i * nums[i - 1];
        }
        long ans = Long.MAX_VALUE;
        for (int i = 1; i <= n; ++i) {
            long t = 0;
            int need = k - nums[i - 1];
            for (int j = i - 1; j <= i + 1; j += 2) {
                if (need > 0 && 1 <= j && j <= n && nums[j - 1] == 1) {
                    --need;
                    ++t;
                }
            }
            int c = Math.min(need, maxChanges);
            need -= c;
            t += c * 2;
            if (need <= 0) {
                ans = Math.min(ans, t);
                continue;
            }
            int l = 2, r = Math.max(i - 1, n - i);
            while (l <= r) {
                int mid = (l + r) >> 1;
                int l1 = Math.max(1, i - mid), r1 = Math.max(0, i - 2);
                int l2 = Math.min(n + 1, i + 2), r2 = Math.min(n, i + mid);
                int c1 = cnt[r1] - cnt[l1 - 1];
                int c2 = cnt[r2] - cnt[l2 - 1];
                if (c1 + c2 >= need) {
                    long t1 = 1L * c1 * i - (s[r1] - s[l1 - 1]);
                    long t2 = s[r2] - s[l2 - 1] - 1L * c2 * i;
                    ans = Math.min(ans, t + t1 + t2);
                    r = mid - 1;
                } else {
                    l = mid + 1;
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
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        vector<long long> s(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            cnt[i] = cnt[i - 1] + nums[i - 1];
            s[i] = s[i - 1] + 1LL * i * nums[i - 1];
        }

        long long ans = LLONG_MAX;

        for (int i = 1; i <= n; ++i) {
            long long t = 0;
            int need = k - nums[i - 1];

            for (int j = i - 1; j <= i + 1; j += 2) {
                if (need > 0 && 1 <= j && j <= n && nums[j - 1] == 1) {
                    --need;
                    ++t;
                }
            }

            int c = min(need, maxChanges);
            need -= c;
            t += c * 2;

            if (need <= 0) {
                ans = min(ans, t);
                continue;
            }

            int l = 2, r = max(i - 1, n - i);

            while (l <= r) {
                int mid = (l + r) / 2;
                int l1 = max(1, i - mid), r1 = max(0, i - 2);
                int l2 = min(n + 1, i + 2), r2 = min(n, i + mid);

                int c1 = cnt[r1] - cnt[l1 - 1];
                int c2 = cnt[r2] - cnt[l2 - 1];

                if (c1 + c2 >= need) {
                    long long t1 = 1LL * c1 * i - (s[r1] - s[l1 - 1]);
                    long long t2 = s[r2] - s[l2 - 1] - 1LL * c2 * i;
                    ans = min(ans, t + t1 + t2);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return ans;
    }
};
```

#### Go

```go
func minimumMoves(nums []int, k int, maxChanges int) int64 {
	n := len(nums)
	cnt := make([]int, n+1)
	s := make([]int, n+1)

	for i := 1; i <= n; i++ {
		cnt[i] = cnt[i-1] + nums[i-1]
		s[i] = s[i-1] + i*nums[i-1]
	}

	ans := math.MaxInt64

	for i := 1; i <= n; i++ {
		t := 0
		need := k - nums[i-1]

		for _, j := range []int{i - 1, i + 1} {
			if need > 0 && 1 <= j && j <= n && nums[j-1] == 1 {
				need--
				t++
			}
		}

		c := min(need, maxChanges)
		need -= c
		t += c * 2

		if need <= 0 {
			ans = min(ans, t)
			continue
		}

		l, r := 2, max(i-1, n-i)

		for l <= r {
			mid := (l + r) >> 1
			l1, r1 := max(1, i-mid), max(0, i-2)
			l2, r2 := min(n+1, i+2), min(n, i+mid)

			c1 := cnt[r1] - cnt[l1-1]
			c2 := cnt[r2] - cnt[l2-1]

			if c1+c2 >= need {
				t1 := c1*i - (s[r1] - s[l1-1])
				t2 := s[r2] - s[l2-1] - c2*i
				ans = min(ans, t+t1+t2)
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
	}

	return int64(ans)
}
```

#### TypeScript

```ts
function minimumMoves(nums: number[], k: number, maxChanges: number): number {
    const n = nums.length;
    const cnt = Array(n + 1).fill(0);
    const s = Array(n + 1).fill(0);

    for (let i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + nums[i - 1];
        s[i] = s[i - 1] + i * nums[i - 1];
    }

    let ans = Infinity;
    for (let i = 1; i <= n; i++) {
        let t = 0;
        let need = k - nums[i - 1];

        for (let j of [i - 1, i + 1]) {
            if (need > 0 && 1 <= j && j <= n && nums[j - 1] === 1) {
                need--;
                t++;
            }
        }

        const c = Math.min(need, maxChanges);
        need -= c;
        t += c * 2;

        if (need <= 0) {
            ans = Math.min(ans, t);
            continue;
        }

        let l = 2,
            r = Math.max(i - 1, n - i);

        while (l <= r) {
            const mid = (l + r) >> 1;
            const [l1, r1] = [Math.max(1, i - mid), Math.max(0, i - 2)];
            const [l2, r2] = [Math.min(n + 1, i + 2), Math.min(n, i + mid)];

            const c1 = cnt[r1] - cnt[l1 - 1];
            const c2 = cnt[r2] - cnt[l2 - 1];

            if (c1 + c2 >= need) {
                const t1 = c1 * i - (s[r1] - s[l1 - 1]);
                const t2 = s[r2] - s[l2 - 1] - c2 * i;
                ans = Math.min(ans, t + t1 + t2);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
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

# [3087. 查找热门话题标签 🔒](https://leetcode.cn/problems/find-trending-hashtags){#3087}

{{< tabs "3087" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    CONCAT('#', SUBSTRING_INDEX(SUBSTRING_INDEX(tweet, '#', -1), ' ', 1)) AS hashtag,
    COUNT(1) AS hashtag_count
FROM Tweets
WHERE DATE_FORMAT(tweet_date, '%Y%m') = '202402'
GROUP BY 1
ORDER BY 2 DESC, 1 DESC
LIMIT 3;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_trending_hashtags(tweets: pd.DataFrame) -> pd.DataFrame:
    # 过滤数据框以获取特定日期的数据
    tweets = tweets[tweets["tweet_date"].dt.strftime("%Y%m") == "202402"]

    # 提取 Hashtag
    tweets["hashtag"] = "#" + tweets["tweet"].str.extract(r"#(\w+)")

    # 统计 Hashtag 出现次数
    hashtag_counts = tweets["hashtag"].value_counts().reset_index()
    hashtag_counts.columns = ["hashtag", "hashtag_count"]

    # 根据出现次数降序排序 Hashtag
    hashtag_counts = hashtag_counts.sort_values(
        by=["hashtag_count", "hashtag"], ascending=[False, False]
    )

    # 返回前三个热门 Hashtag
    top_3_hashtags = hashtag_counts.head(3)

    return top_3_hashtags
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Tweets</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| tweet_id    | int     |
| tweet_date  | date    |
| tweet       | varchar |
+-------------+---------+
tweet_id 是这张表的主键 (值互不相同的列)。
这张表的每一行都包含 user_id, tweet_id, tweet_date 和 tweet。
</pre>

<p>编写一个解决方案来找到&nbsp;<code>2024</code>&nbsp;年 <strong>二月&nbsp;</strong>的 <strong>前</strong>&nbsp;<code>3</code>&nbsp;热门话题 <strong>标签</strong>。每条推文只包含一个标签。</p>

<p>返回结果表，根据标签的数量和名称&nbsp;<strong>降序</strong> 排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<p><b>输入：</b></p>

<p>Tweets 表：</p>

<pre class="example-io">
+---------+----------+----------------------------------------------+------------+
| user_id | tweet_id | tweet                                        | tweet_date |
+---------+----------+----------------------------------------------+------------+
| 135     | 13       | Enjoying a great start to the day! #HappyDay | 2024-02-01 |
| 136     | 14       | Another #HappyDay with good vibes!           | 2024-02-03 |
| 137     | 15       | Productivity peaks! #WorkLife                | 2024-02-04 |
| 138     | 16       | Exploring new tech frontiers. #TechLife      | 2024-02-04 |
| 139     | 17       | Gratitude for today's moments. #HappyDay     | 2024-02-05 |
| 140     | 18       | Innovation drives us. #TechLife              | 2024-02-07 |
| 141     | 19       | Connecting with nature's serenity. #Nature   | 2024-02-09 |
+---------+----------+----------------------------------------------+------------+
 </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-----------+--------------+
| hashtag   | hashtag_count|
+-----------+--------------+
| #HappyDay | 3            |
| #TechLife | 2            |
| #WorkLife | 1            |
+-----------+--------------+

</pre>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>#HappyDay：</strong>在 ID 为 13，14，17 的推文中出现，总共提及&nbsp;3 次。</li>
	<li><strong>#TechLife：</strong>在 ID 为 16，18 的推文中出现，总共提及 2&nbsp;次。</li>
	<li><strong>#WorkLife：</strong>在 ID 为 15 的推文中出现，总共提及 1&nbsp;次。</li>
</ul>

<p><b>注意：</b>输出表分别按 hashtag_count 和 hashtag 降序排序。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：提取子串 + 分组

我们可以查询得到 2024 年 2 月的所有 tweet，利用 `SUBSTRING_INDEX` 函数提取 Hashtag，然后使用 `GROUP BY` 和 `COUNT` 函数统计每个 Hashtag 出现的次数，最后按照出现次数降序、Hashtag 降序排序，取前三个热门 Hashtag。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    CONCAT('#', SUBSTRING_INDEX(SUBSTRING_INDEX(tweet, '#', -1), ' ', 1)) AS hashtag,
    COUNT(1) AS hashtag_count
FROM Tweets
WHERE DATE_FORMAT(tweet_date, '%Y%m') = '202402'
GROUP BY 1
ORDER BY 2 DESC, 1 DESC
LIMIT 3;
```

#### Python3

```python
import pandas as pd


def find_trending_hashtags(tweets: pd.DataFrame) -> pd.DataFrame:
    # 过滤数据框以获取特定日期的数据
    tweets = tweets[tweets["tweet_date"].dt.strftime("%Y%m") == "202402"]

    # 提取 Hashtag
    tweets["hashtag"] = "#" + tweets["tweet"].str.extract(r"#(\w+)")

    # 统计 Hashtag 出现次数
    hashtag_counts = tweets["hashtag"].value_counts().reset_index()
    hashtag_counts.columns = ["hashtag", "hashtag_count"]

    # 根据出现次数降序排序 Hashtag
    hashtag_counts = hashtag_counts.sort_values(
        by=["hashtag_count", "hashtag"], ascending=[False, False]
    )

    # 返回前三个热门 Hashtag
    top_3_hashtags = hashtag_counts.head(3)

    return top_3_hashtags
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3088. 使字符串反回文 🔒](https://leetcode.cn/problems/make-string-anti-palindrome){#3088}

{{< tabs "3088" >}}

{{% tab "python" %}}
```python
class Solution:
    def makeAntiPalindrome(self, s: str) -> str:
        cs = sorted(s)
        n = len(cs)
        m = n // 2
        if cs[m] == cs[m - 1]:
            i = m
            while i < n and cs[i] == cs[i - 1]:
                i += 1
            j = m
            while j < n and cs[j] == cs[n - j - 1]:
                if i >= n:
                    return "-1"
                cs[i], cs[j] = cs[j], cs[i]
                i, j = i + 1, j + 1
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String makeAntiPalindrome(String s) {
        char[] cs = s.toCharArray();
        Arrays.sort(cs);
        int n = cs.length;
        int m = n / 2;
        if (cs[m] == cs[m - 1]) {
            int i = m;
            while (i < n && cs[i] == cs[i - 1]) {
                ++i;
            }
            for (int j = m; j < n && cs[j] == cs[n - j - 1]; ++i, ++j) {
                if (i >= n) {
                    return "-1";
                }
                char t = cs[i];
                cs[i] = cs[j];
                cs[j] = t;
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
    string makeAntiPalindrome(string s) {
        sort(s.begin(), s.end());
        int n = s.length();
        int m = n / 2;
        if (s[m] == s[m - 1]) {
            int i = m;
            while (i < n && s[i] == s[i - 1]) {
                ++i;
            }
            for (int j = m; j < n && s[j] == s[n - j - 1]; ++i, ++j) {
                if (i >= n) {
                    return "-1";
                }
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func makeAntiPalindrome(s string) string {
	cs := []byte(s)
	sort.Slice(cs, func(i, j int) bool { return cs[i] < cs[j] })
	n := len(cs)
	m := n / 2
	if cs[m] == cs[m-1] {
		i := m
		for i < n && cs[i] == cs[i-1] {
			i++
		}
		for j := m; j < n && cs[j] == cs[n-j-1]; i, j = i+1, j+1 {
			if i >= n {
				return "-1"
			}
			cs[i], cs[j] = cs[j], cs[i]
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makeAntiPalindrome(s: string): string {
    const cs: string[] = s.split('').sort();
    const n: number = cs.length;
    const m = n >> 1;
    if (cs[m] === cs[m - 1]) {
        let i = m;
        for (; i < n && cs[i] === cs[i - 1]; i++);
        for (let j = m; j < n && cs[j] === cs[n - j - 1]; ++i, ++j) {
            if (i >= n) {
                return '-1';
            }
            [cs[j], cs[i]] = [cs[i], cs[j]];
        }
    }
    return cs.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们称一个长度为偶数的字符串&nbsp;<code>s</code>&nbsp;为&nbsp;<strong>反回文</strong>&nbsp;的，如果对于每一个下标&nbsp;<code>0 &lt;= i &lt; n</code>&nbsp;，<code>s[i] != s[n - i - 1]</code>。</p>

<p>给定一个字符串&nbsp;<code>s</code>，你需要进行&nbsp;<strong>任意</strong> 次（包括 0）操作使&nbsp;<code>s</code>&nbsp;成为 <strong>反回文。</strong></p>

<p>在一次操作中，你可以选择&nbsp;<code>s</code>&nbsp;中的两个字符并且交换它们。</p>

<p>返回结果字符串。如果有多个字符串符合条件，返回 <span data-keyword="lexicographically-smaller-string">字典序最小</span> 的那个。如果它不能成为一个反回文，返回&nbsp;<code>"-1"</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "abca"</span></p>

<p><strong>输出：</strong><span class="example-io">"aabc"</span></p>

<p><strong>解释：</strong></p>

<p><code>"aabc"</code> 是一个反回文字符串，因为 <code>s[0] != s[3]</code> 并且&nbsp;<code>s[1] != s[2]</code>。同时，它也是 <code>"abca"</code>&nbsp;的一个重排。</p>
</div>

<p><strong class="example">示例 2:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "abba"</span></p>

<p><b>输出：</b><span class="example-io">"aabb"</span></p>

<p><b>解释：</b></p>

<p><code>"aabb"</code>&nbsp;是一个反回文字符串，因为&nbsp;<code>s[0] != s[3]</code>&nbsp;并且&nbsp;<code>s[1] != s[2]</code>。同时，它也是&nbsp;<code>"abba"</code>&nbsp;的一个重排。</p>
</div>

<p><strong class="example">示例 3:</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "cccd"</span></p>

<p><strong>输出：</strong><span class="example-io">"-1"</span></p>

<p><strong>解释：</strong></p>

<p>你可以发现无论你如何重排&nbsp;<code>"cccd"</code>&nbsp;的字符，都有&nbsp;<code>s[0] == s[3]</code>&nbsp;或&nbsp;<code>s[1] == s[2]</code>。所以它不能形成一个反回文字符串。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s.length % 2 == 0</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

题目要求我们将字符串 $s$ 变成字典序最小的反回文字符串，我们不妨先对字符串 $s$ 进行排序。

接下来，我们只需要比较中间的两个字符 $s[m]$ 和 $s[m-1]$ 是否相等，如果相等，我们就在后半部分找到第一个不等于 $s[m]$ 的字符 $s[i]$，用一个指针 $j$ 指向 $m$，然后交换 $s[i]$ 和 $s[j]$。如果找不到这样的字符 $s[i]$，说明字符串 $s$ 无法变成反回文字符串，返回 `"1"`。否则，执行交换操作，并向右移动 $i$ 和 $j$，比较 $s[j]$ 和 $s[n-j-1]$ 是否相等，如果相等，继续执行交换操作，直到 $i$ 超出字符串长度。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makeAntiPalindrome(self, s: str) -> str:
        cs = sorted(s)
        n = len(cs)
        m = n // 2
        if cs[m] == cs[m - 1]:
            i = m
            while i < n and cs[i] == cs[i - 1]:
                i += 1
            j = m
            while j < n and cs[j] == cs[n - j - 1]:
                if i >= n:
                    return "-1"
                cs[i], cs[j] = cs[j], cs[i]
                i, j = i + 1, j + 1
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String makeAntiPalindrome(String s) {
        char[] cs = s.toCharArray();
        Arrays.sort(cs);
        int n = cs.length;
        int m = n / 2;
        if (cs[m] == cs[m - 1]) {
            int i = m;
            while (i < n && cs[i] == cs[i - 1]) {
                ++i;
            }
            for (int j = m; j < n && cs[j] == cs[n - j - 1]; ++i, ++j) {
                if (i >= n) {
                    return "-1";
                }
                char t = cs[i];
                cs[i] = cs[j];
                cs[j] = t;
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
    string makeAntiPalindrome(string s) {
        sort(s.begin(), s.end());
        int n = s.length();
        int m = n / 2;
        if (s[m] == s[m - 1]) {
            int i = m;
            while (i < n && s[i] == s[i - 1]) {
                ++i;
            }
            for (int j = m; j < n && s[j] == s[n - j - 1]; ++i, ++j) {
                if (i >= n) {
                    return "-1";
                }
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};
```

#### Go

```go
func makeAntiPalindrome(s string) string {
	cs := []byte(s)
	sort.Slice(cs, func(i, j int) bool { return cs[i] < cs[j] })
	n := len(cs)
	m := n / 2
	if cs[m] == cs[m-1] {
		i := m
		for i < n && cs[i] == cs[i-1] {
			i++
		}
		for j := m; j < n && cs[j] == cs[n-j-1]; i, j = i+1, j+1 {
			if i >= n {
				return "-1"
			}
			cs[i], cs[j] = cs[j], cs[i]
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function makeAntiPalindrome(s: string): string {
    const cs: string[] = s.split('').sort();
    const n: number = cs.length;
    const m = n >> 1;
    if (cs[m] === cs[m - 1]) {
        let i = m;
        for (; i < n && cs[i] === cs[i - 1]; i++);
        for (let j = m; j < n && cs[j] === cs[n - j - 1]; ++i, ++j) {
            if (i >= n) {
                return '-1';
            }
            [cs[j], cs[i]] = [cs[i], cs[j]];
        }
    }
    return cs.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3089. 查找突发行为 🔒](https://leetcode.cn/problems/find-bursty-behavior){#3089}

{{< tabs "3089" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT p1.user_id AS user_id, COUNT(1) AS cnt
        FROM
            Posts AS p1
            JOIN Posts AS p2
                ON p1.user_id = p2.user_id
                AND p2.post_date BETWEEN p1.post_date AND DATE_ADD(p1.post_date, INTERVAL 6 DAY)
        GROUP BY p1.user_id, p1.post_id
    ),
    T AS (
        SELECT user_id, COUNT(1) / 4 AS avg_weekly_posts
        FROM Posts
        WHERE post_date BETWEEN '2024-02-01' AND '2024-02-28'
        GROUP BY 1
    )
SELECT user_id, MAX(cnt) AS max_7day_posts, avg_weekly_posts
FROM
    P
    JOIN T USING (user_id)
GROUP BY 1
HAVING max_7day_posts >= avg_weekly_posts * 2
ORDER BY 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def find_bursty_behavior(posts: pd.DataFrame) -> pd.DataFrame:
    # 子查询 P
    p1 = pd.merge(
        posts, posts, on="user_id", suffixes=("_1", "_2")
    )  # 合并帖子表自身，根据用户ID
    p1 = p1[
        p1["post_date_2"].between(
            p1["post_date_1"], p1["post_date_1"] + pd.Timedelta(days=6)
        )
    ]  # 筛选出相邻 7 天内的帖子
    p1 = (
        p1.groupby(["user_id", "post_id_1"]).size().reset_index(name="cnt")
    )  # 统计每个用户在相邻 7 天内的帖子数

    # 子查询 T
    t = posts[
        (posts["post_date"] >= "2024-02-01") & (posts["post_date"] <= "2024-02-28")
    ]  # 筛选出 2024 年 2 月份的帖子
    t = (
        t.groupby("user_id").size().div(4).reset_index(name="avg_weekly_posts")
    )  # 计算每个用户平均每周的帖子数

    # 连接 P 和 T
    merged_df = pd.merge(p1, t, on="user_id", how="inner")  # 内连接 P 和 T

    # 过滤
    filtered_df = merged_df[
        merged_df["cnt"] >= merged_df["avg_weekly_posts"] * 2
    ]  # 过滤出满足条件的行

    # 聚合
    result_df = (
        filtered_df.groupby("user_id")
        .agg({"cnt": "max", "avg_weekly_posts": "first"})
        .reset_index()
    )  # 对满足条件的行按用户ID聚合
    result_df.columns = ["user_id", "max_7day_posts", "avg_weekly_posts"]  # 重命名列名

    # 排序
    result_df.sort_values(by="user_id", inplace=True)  # 按用户ID排序

    return result_df
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Posts</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| post_id     | int     |
| user_id     | int     |
| post_date   | date    |
+-------------+---------+
post_id 是这张表的主键（有不同值的列）。
这张表的每一行包含 post_id，user_id 和 post_date。
</pre>

<p>编写一个解决方案来找到在 <code>2024</code> 年 2 月期间在发帖行为中表现出 <strong>突发行为</strong> 的用户。<strong>突发行为</strong>&nbsp;指用户在&nbsp;<code>2024</code> 年 2 月 <strong>存在一个</strong> <strong>连续 7 天</strong> 的时段中发帖频率是其 <strong>平均</strong> 每周发帖频率的 <strong>至少两倍</strong>。</p>

<p><strong>注意：</strong>&nbsp;在你的统计中只包含 2 月 <code>1</code> 日 到 2 月 <code>28</code> 日，也就是说你应该把 2 月记为正好 <code>4</code> 周。</p>

<p>返回结果表，以<em>&nbsp;</em><code>user_id</code><em> </em><strong>升序</strong><em>&nbsp;</em>排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>Posts 表：</p>

<pre class="example-io">
+---------+---------+------------+
| post_id | user_id | post_date  |
+---------+---------+------------+
| 1       | 1       | 2024-02-27 |
| 2       | 5       | 2024-02-06 |
| 3       | 3       | 2024-02-25 |
| 4       | 3       | 2024-02-14 |
| 5       | 3       | 2024-02-06 |
| 6       | 2       | 2024-02-25 |
+---------+---------+------------+
</pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+---------+----------------+------------------+
| user_id | max_7day_posts | avg_weekly_posts |
+---------+----------------+------------------+
| 1       | 1              | 0.2500           |
| 2       | 1              | 0.2500           |
| 5       | 1              | 0.2500           |
+---------+----------------+------------------+
</pre>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>用户 1：</strong>2 月份只发布了 1 个帖子，平均每周发布 0.25 个帖子，任何 7 天期间最多发布 1 个帖子。</li>
	<li><strong>用户 2：</strong>也只发了 1 个帖子，与用户 1 相同的平均和最大 7 天发帖频率。</li>
	<li><strong>用户 5：</strong>与用户 1 和用户 2 一样，用户 5 在整个 2 月份只发布了 1 篇文章，得到相同的平均和最大 7 天发帖频率。</li>
	<li><strong>用户 3：</strong>虽然用户 3 发布的帖子比其他用户多（3 篇），但他在连续 7 天期间中没有达到每周平均发帖频率的两倍，因此没有在输出中列出。</li>
</ul>

<p><b>注意：</b>&nbsp;输出表以 user_id 升序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接 + 分组统计

我们可以使用自连接，将表 `Posts` 与自身连接，连接条件是 `p1.user_id = p2.user_id` 且 `p2.post_date` 在 `p1.post_date` 和 `p1.post_date` 后 `6` 天之间，然后我们将连接结果按照 `p1.user_id` 和 `p1.post_id` 分组，即可统计出每个用户在每天的 7 天内的发帖数量，我们将这个结果保存在表 `P` 中。

接着我们统计出每个用户在 2024 年 2 月份的每周平均发帖数量，保存在表 `T` 中。注意，我们需要查找 `post_date` 在 `2024-02-01` 和 `2024-02-28` 之间的记录，将记录按照 `user_id` 分组，然后统计每个用户的发帖数量，最后除以 `4` 即可得到每周平均发帖数量，我们将这个结果保存在表 `T` 中。

最后，我们将表 `P` 和表 `T` 连接，连接条件是 `P.user_id = T.user_id`，然后按照 `user_id` 分组，统计出每个用户在 7 天内的最大发帖数量，最后筛选出满足条件 `max_7day_posts >= avg_weekly_posts * 2` 的记录，即可得到结果。注意，我们需要按照 `user_id` 升序排序。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    P AS (
        SELECT p1.user_id AS user_id, COUNT(1) AS cnt
        FROM
            Posts AS p1
            JOIN Posts AS p2
                ON p1.user_id = p2.user_id
                AND p2.post_date BETWEEN p1.post_date AND DATE_ADD(p1.post_date, INTERVAL 6 DAY)
        GROUP BY p1.user_id, p1.post_id
    ),
    T AS (
        SELECT user_id, COUNT(1) / 4 AS avg_weekly_posts
        FROM Posts
        WHERE post_date BETWEEN '2024-02-01' AND '2024-02-28'
        GROUP BY 1
    )
SELECT user_id, MAX(cnt) AS max_7day_posts, avg_weekly_posts
FROM
    P
    JOIN T USING (user_id)
GROUP BY 1
HAVING max_7day_posts >= avg_weekly_posts * 2
ORDER BY 1;
```

#### Python3

```python
import pandas as pd


def find_bursty_behavior(posts: pd.DataFrame) -> pd.DataFrame:
    # 子查询 P
    p1 = pd.merge(
        posts, posts, on="user_id", suffixes=("_1", "_2")
    )  # 合并帖子表自身，根据用户ID
    p1 = p1[
        p1["post_date_2"].between(
            p1["post_date_1"], p1["post_date_1"] + pd.Timedelta(days=6)
        )
    ]  # 筛选出相邻 7 天内的帖子
    p1 = (
        p1.groupby(["user_id", "post_id_1"]).size().reset_index(name="cnt")
    )  # 统计每个用户在相邻 7 天内的帖子数

    # 子查询 T
    t = posts[
        (posts["post_date"] >= "2024-02-01") & (posts["post_date"] <= "2024-02-28")
    ]  # 筛选出 2024 年 2 月份的帖子
    t = (
        t.groupby("user_id").size().div(4).reset_index(name="avg_weekly_posts")
    )  # 计算每个用户平均每周的帖子数

    # 连接 P 和 T
    merged_df = pd.merge(p1, t, on="user_id", how="inner")  # 内连接 P 和 T

    # 过滤
    filtered_df = merged_df[
        merged_df["cnt"] >= merged_df["avg_weekly_posts"] * 2
    ]  # 过滤出满足条件的行

    # 聚合
    result_df = (
        filtered_df.groupby("user_id")
        .agg({"cnt": "max", "avg_weekly_posts": "first"})
        .reset_index()
    )  # 对满足条件的行按用户ID聚合
    result_df.columns = ["user_id", "max_7day_posts", "avg_weekly_posts"]  # 重命名列名

    # 排序
    result_df.sort_values(by="user_id", inplace=True)  # 按用户ID排序

    return result_df
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
