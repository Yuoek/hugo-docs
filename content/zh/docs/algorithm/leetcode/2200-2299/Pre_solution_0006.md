---
title: "2250_统计包含每个点的矩形数目"
date: 2025-10-08T18:39:07+08:00
weight: 6
tags: [二分查找, 前缀和, 哈希表, 字符串, 广度优先搜索, 排序, 数据库, 数组, 有序集合, 枚举, 栈, 树状数组, 模拟, 矩阵, 设计, 贪心]
---

{{< markmap >}}
### [2250_统计包含每个点的矩形数目](#2250)
#### [树状数组](#2250)
#### [数组](#2250)
#### [哈希表](#2250)
#### [二分查找](#2250)
#### [排序](#2250)
### [2251_花期内花的数目](#2251)
#### [数组](#2251)
#### [哈希表](#2251)
#### [二分查找](#2251)
#### [有序集合](#2251)
#### [前缀和](#2251)
#### [排序](#2251)
### [2252_表的动态旋转 🔒](#2252)
#### [数据库](#2252)
### [2253_动态取消表的旋转 🔒](#2253)
#### [数据库](#2253)
### [2254_设计视频共享平台 🔒](#2254)
#### [栈](#2254)
#### [设计](#2254)
#### [哈希表](#2254)
#### [有序集合](#2254)
### [2255_统计是给定字符串前缀的字符串数目](#2255)
#### [数组](#2255)
#### [字符串](#2255)
### [2256_最小平均差](#2256)
#### [数组](#2256)
#### [前缀和](#2256)
### [2257_统计网格图中没有被保卫的格子数](#2257)
#### [数组](#2257)
#### [矩阵](#2257)
#### [模拟](#2257)
### [2258_逃离火灾](#2258)
#### [广度优先搜索](#2258)
#### [数组](#2258)
#### [二分查找](#2258)
#### [矩阵](#2258)
### [2259_移除指定数字得到的最大结果](#2259)
#### [贪心](#2259)
#### [字符串](#2259)
#### [枚举](#2259)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2250_统计包含每个点的矩形数目
___
#### 树状数组
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 排序
---
### 2251_花期内花的数目
___
#### 数组
___
#### 哈希表
___
#### 二分查找
___
#### 有序集合
___
#### 前缀和
___
#### 排序
---
### 2252_表的动态旋转 🔒
___
#### 数据库
---
### 2253_动态取消表的旋转 🔒
___
#### 数据库
---
### 2254_设计视频共享平台 🔒
___
#### 栈
___
#### 设计
___
#### 哈希表
___
#### 有序集合
---
### 2255_统计是给定字符串前缀的字符串数目
___
#### 数组
___
#### 字符串
---
### 2256_最小平均差
___
#### 数组
___
#### 前缀和
---
### 2257_统计网格图中没有被保卫的格子数
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 2258_逃离火灾
___
#### 广度优先搜索
___
#### 数组
___
#### 二分查找
___
#### 矩阵
---
### 2259_移除指定数字得到的最大结果
___
#### 贪心
___
#### 字符串
___
#### 枚举
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 哈希表 |
| 字符串 | 广度优先搜索 | 排序 |
| 数据库 | 数组 | 有序集合 |
| 枚举 | 栈 | 树状数组 |
| 模拟 | 矩阵 | 设计 |
| 贪心 |  |  |

# [2250. 统计包含每个点的矩形数目](https://leetcode.cn/problems/count-number-of-rectangles-containing-each-point){#2250}

{{< tabs "2250" >}}

{{% tab "python" %}}
```python
class Solution:
    def countRectangles(
        self, rectangles: List[List[int]], points: List[List[int]]
    ) -> List[int]:
        d = defaultdict(list)
        for x, y in rectangles:
            d[y].append(x)
        for y in d.keys():
            d[y].sort()
        ans = []
        for x, y in points:
            cnt = 0
            for h in range(y, 101):
                xs = d[h]
                cnt += len(xs) - bisect_left(xs, x)
            ans.append(cnt)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] countRectangles(int[][] rectangles, int[][] points) {
        int n = 101;
        List<Integer>[] d = new List[n];
        Arrays.setAll(d, k -> new ArrayList<>());
        for (int[] r : rectangles) {
            d[r[1]].add(r[0]);
        }
        for (List<Integer> v : d) {
            Collections.sort(v);
        }
        int m = points.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int x = points[i][0], y = points[i][1];
            int cnt = 0;
            for (int h = y; h < n; ++h) {
                List<Integer> xs = d[h];
                int left = 0, right = xs.size();
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (xs.get(mid) >= x) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                cnt += xs.size() - left;
            }
            ans[i] = cnt;
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
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n = 101;
        vector<vector<int>> d(n);
        for (auto& r : rectangles) d[r[1]].push_back(r[0]);
        for (auto& v : d) sort(v.begin(), v.end());
        vector<int> ans;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            int cnt = 0;
            for (int h = y; h < n; ++h) {
                auto& xs = d[h];
                cnt += xs.size() - (lower_bound(xs.begin(), xs.end(), x) - xs.begin());
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countRectangles(rectangles [][]int, points [][]int) []int {
	n := 101
	d := make([][]int, 101)
	for _, r := range rectangles {
		d[r[1]] = append(d[r[1]], r[0])
	}
	for _, v := range d {
		sort.Ints(v)
	}
	var ans []int
	for _, p := range points {
		x, y := p[0], p[1]
		cnt := 0
		for h := y; h < n; h++ {
			xs := d[h]
			left, right := 0, len(xs)
			for left < right {
				mid := (left + right) >> 1
				if xs[mid] >= x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			cnt += len(xs) - left
		}
		ans = append(ans, cnt)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countRectangles(rectangles: number[][], points: number[][]): number[] {
    const n = 101;
    let ymap = Array.from({ length: n }, v => []);
    for (let [x, y] of rectangles) {
        ymap[y].push(x);
    }
    for (let nums of ymap) {
        nums.sort((a, b) => a - b);
    }
    let ans = [];
    for (let [x, y] of points) {
        let count = 0;
        for (let h = y; h < n; h++) {
            const nums = ymap[h];
            let left = 0,
                right = nums.length;
            while (left < right) {
                let mid = (left + right) >> 1;
                if (x > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            count += nums.length - right;
        }
        ans.push(count);
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

<p>给你一个二维整数数组&nbsp;<code>rectangles</code>&nbsp;，其中&nbsp;<code>rectangles[i] = [l<sub>i</sub>, h<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;个矩形长为&nbsp;<code>l<sub>i</sub></code>&nbsp;高为&nbsp;<code>h<sub>i</sub></code>&nbsp;。给你一个二维整数数组&nbsp;<code>points</code>&nbsp;，其中&nbsp;<code>points[j] = [x<sub>j</sub>, y<sub>j</sub>]</code>&nbsp;是坐标为&nbsp;<code>(x<sub>j</sub>, y<sub>j</sub>)</code>&nbsp;的一个点。</p>

<p>第&nbsp;<code>i</code>&nbsp;个矩形的 <strong>左下角</strong>&nbsp;在&nbsp;<code>(0, 0)</code>&nbsp;处，<strong>右上角</strong>&nbsp;在&nbsp;<code>(l<sub>i</sub>, h<sub>i</sub>)</code>&nbsp;。</p>

<p>请你返回一个整数数组<em>&nbsp;</em><code>count</code>&nbsp;，长度为&nbsp;<code>points.length</code>，其中<em>&nbsp;</em><code>count[j]</code>是 <strong>包含</strong> 第<em>&nbsp;</em><code>j</code>&nbsp;个点的矩形数目。</p>

<p>如果&nbsp;<code>0 &lt;= x<sub>j</sub> &lt;= l<sub>i</sub></code> 且&nbsp;<code>0 &lt;= y<sub>j</sub> &lt;= h<sub>i</sub></code>&nbsp;，那么我们说第&nbsp;<code>i</code>&nbsp;个矩形包含第&nbsp;<code>j</code>&nbsp;个点。如果一个点刚好在矩形的 <strong>边上</strong>&nbsp;，这个点也被视为被矩形包含。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2250.Count%20Number%20of%20Rectangles%20Containing%20Each%20Point/images/example1.png" style="width: 300px; height: 509px;"></p>

<pre><b>输入：</b>rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
<b>输出：</b>[2,1]
<b>解释：</b>
第一个矩形不包含任何点。
第二个矩形只包含一个点 (2, 1) 。
第三个矩形包含点 (2, 1) 和 (1, 4) 。
包含点 (2, 1) 的矩形数目为 2 。
包含点 (1, 4) 的矩形数目为 1 。
所以，我们返回 [2, 1] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2250.Count%20Number%20of%20Rectangles%20Containing%20Each%20Point/images/example2.png" style="width: 300px; height: 312px;"></p>

<pre><b>输入：</b>rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
<b>输出：</b>[1,3]
<strong>解释：
</strong>第一个矩形只包含点 (1, 1) 。
第二个矩形只包含点 (1, 1) 。
第三个矩形包含点 (1, 3) 和 (1, 1) 。
包含点 (1, 3) 的矩形数目为 1 。
包含点 (1, 1) 的矩形数目为 3 。
所以，我们返回 [1, 3] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rectangles.length, points.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>rectangles[i].length == points[j].length == 2</code></li>
	<li><code>1 &lt;= l<sub>i</sub>, x<sub>j</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= h<sub>i</sub>, y<sub>j</sub> &lt;= 100</code></li>
	<li>所有&nbsp;<code>rectangles</code>&nbsp;<strong>互不相同</strong>&nbsp;。</li>
	<li>所有&nbsp;<code>points</code> <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countRectangles(
        self, rectangles: List[List[int]], points: List[List[int]]
    ) -> List[int]:
        d = defaultdict(list)
        for x, y in rectangles:
            d[y].append(x)
        for y in d.keys():
            d[y].sort()
        ans = []
        for x, y in points:
            cnt = 0
            for h in range(y, 101):
                xs = d[h]
                cnt += len(xs) - bisect_left(xs, x)
            ans.append(cnt)
        return ans
```

#### Java

```java
class Solution {
    public int[] countRectangles(int[][] rectangles, int[][] points) {
        int n = 101;
        List<Integer>[] d = new List[n];
        Arrays.setAll(d, k -> new ArrayList<>());
        for (int[] r : rectangles) {
            d[r[1]].add(r[0]);
        }
        for (List<Integer> v : d) {
            Collections.sort(v);
        }
        int m = points.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int x = points[i][0], y = points[i][1];
            int cnt = 0;
            for (int h = y; h < n; ++h) {
                List<Integer> xs = d[h];
                int left = 0, right = xs.size();
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (xs.get(mid) >= x) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                cnt += xs.size() - left;
            }
            ans[i] = cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int n = 101;
        vector<vector<int>> d(n);
        for (auto& r : rectangles) d[r[1]].push_back(r[0]);
        for (auto& v : d) sort(v.begin(), v.end());
        vector<int> ans;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            int cnt = 0;
            for (int h = y; h < n; ++h) {
                auto& xs = d[h];
                cnt += xs.size() - (lower_bound(xs.begin(), xs.end(), x) - xs.begin());
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
```

#### Go

```go
func countRectangles(rectangles [][]int, points [][]int) []int {
	n := 101
	d := make([][]int, 101)
	for _, r := range rectangles {
		d[r[1]] = append(d[r[1]], r[0])
	}
	for _, v := range d {
		sort.Ints(v)
	}
	var ans []int
	for _, p := range points {
		x, y := p[0], p[1]
		cnt := 0
		for h := y; h < n; h++ {
			xs := d[h]
			left, right := 0, len(xs)
			for left < right {
				mid := (left + right) >> 1
				if xs[mid] >= x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			cnt += len(xs) - left
		}
		ans = append(ans, cnt)
	}
	return ans
}
```

#### TypeScript

```ts
function countRectangles(rectangles: number[][], points: number[][]): number[] {
    const n = 101;
    let ymap = Array.from({ length: n }, v => []);
    for (let [x, y] of rectangles) {
        ymap[y].push(x);
    }
    for (let nums of ymap) {
        nums.sort((a, b) => a - b);
    }
    let ans = [];
    for (let [x, y] of points) {
        let count = 0;
        for (let h = y; h < n; h++) {
            const nums = ymap[h];
            let left = 0,
                right = nums.length;
            while (left < right) {
                let mid = (left + right) >> 1;
                if (x > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            count += nums.length - right;
        }
        ans.push(count);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2251. 花期内花的数目](https://leetcode.cn/problems/number-of-flowers-in-full-bloom){#2251}

{{< tabs "2251" >}}

{{% tab "python" %}}
```python
class Solution:
    def fullBloomFlowers(
        self, flowers: List[List[int]], people: List[int]
    ) -> List[int]:
        d = defaultdict(int)
        for st, ed in flowers:
            d[st] += 1
            d[ed + 1] -= 1
        ts = sorted(d)
        s = i = 0
        m = len(people)
        ans = [0] * m
        for t, j in sorted(zip(people, range(m))):
            while i < len(ts) and ts[i] <= t:
                s += d[ts[i]]
                i += 1
            ans[j] = s
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (int[] f : flowers) {
            d.merge(f[0], 1, Integer::sum);
            d.merge(f[1] + 1, -1, Integer::sum);
        }
        int s = 0;
        int m = people.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, Comparator.comparingInt(i -> people[i]));
        int[] ans = new int[m];
        for (int i : idx) {
            int t = people[i];
            while (!d.isEmpty() && d.firstKey() <= t) {
                s += d.pollFirstEntry().getValue();
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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> d;
        for (auto& f : flowers) {
            d[f[0]]++;
            d[f[1] + 1]--;
        }
        int m = people.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return people[i] < people[j];
        });
        vector<int> ans(m);
        int s = 0;
        for (int i : idx) {
            int t = people[i];
            while (!d.empty() && d.begin()->first <= t) {
                s += d.begin()->second;
                d.erase(d.begin());
            }
            ans[i] = s;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fullBloomFlowers(flowers [][]int, people []int) []int {
	d := map[int]int{}
	for _, f := range flowers {
		d[f[0]]++
		d[f[1]+1]--
	}
	ts := []int{}
	for t := range d {
		ts = append(ts, t)
	}
	sort.Ints(ts)
	m := len(people)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return people[idx[i]] < people[idx[j]] })
	ans := make([]int, m)
	s, i := 0, 0
	for _, j := range idx {
		t := people[j]
		for i < len(ts) && ts[i] <= t {
			s += d[ts[i]]
			i++
		}
		ans[j] = s
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function fullBloomFlowers(flowers: number[][], people: number[]): number[] {
    const d: Map<number, number> = new Map();
    for (const [st, ed] of flowers) {
        d.set(st, (d.get(st) || 0) + 1);
        d.set(ed + 1, (d.get(ed + 1) || 0) - 1);
    }
    const ts = [...d.keys()].sort((a, b) => a - b);
    let s = 0;
    let i = 0;
    const m = people.length;
    const idx: number[] = [...Array(m)].map((_, i) => i).sort((a, b) => people[a] - people[b]);
    const ans = Array(m).fill(0);
    for (const j of idx) {
        const t = people[j];
        while (i < ts.length && ts[i] <= t) {
            s += d.get(ts[i])!;
            ++i;
        }
        ans[j] = s;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::BTreeMap;

impl Solution {
    #[allow(dead_code)]
    pub fn full_bloom_flowers(flowers: Vec<Vec<i32>>, people: Vec<i32>) -> Vec<i32> {
        let n = people.len();

        // First sort the people vector based on the first item
        let mut people: Vec<(usize, i32)> = people.into_iter().enumerate().map(|x| x).collect();

        people.sort_by(|lhs, rhs| lhs.1.cmp(&rhs.1));

        // Initialize the difference vector
        let mut diff = BTreeMap::new();
        let mut ret = vec![0; n];

        for f in flowers {
            let (left, right) = (f[0], f[1]);
            diff.entry(left)
                .and_modify(|x| {
                    *x += 1;
                })
                .or_insert(1);

            diff.entry(right + 1)
                .and_modify(|x| {
                    *x -= 1;
                })
                .or_insert(-1);
        }

        let mut sum = 0;
        let mut i = 0;
        for (k, v) in diff {
            while i < n && people[i].1 < k {
                ret[people[i].0] += sum;
                i += 1;
            }
            sum += v;
        }

        ret
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的二维整数数组&nbsp;<code>flowers</code>&nbsp;，其中&nbsp;<code>flowers[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;表示第&nbsp;<code>i</code>&nbsp;朵花的 <strong>花期</strong>&nbsp;从&nbsp;<code>start<sub>i</sub></code>&nbsp;到&nbsp;<code>end<sub>i</sub></code>&nbsp;（都 <strong>包含</strong>）。同时给你一个下标从 <strong>0</strong>&nbsp;开始大小为 <code>n</code>&nbsp;的整数数组&nbsp;<code>people</code> ，<code>people[i]</code>&nbsp;是第&nbsp;<code>i</code>&nbsp;个人来看花的时间。</p>

<p>请你返回一个大小为 <code>n</code>&nbsp;的整数数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;个人到达时在花期内花的&nbsp;<strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2251.Number%20of%20Flowers%20in%20Full%20Bloom/images/ex1new.jpg" style="width: 550px; height: 216px;" /></p>

<pre>
<b>输入：</b>flowers = [[1,6],[3,7],[9,12],[4,13]], people = [2,3,7,11]
<b>输出：</b>[1,2,2,2]
<strong>解释：</strong>上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2251.Number%20of%20Flowers%20in%20Full%20Bloom/images/ex2new.jpg" style="width: 450px; height: 195px;" /></p>

<pre>
<b>输入：</b>flowers = [[1,10],[3,3]], people = [3,3,2]
<b>输出：</b>[2,2,1]
<b>解释：</b>上图展示了每朵花的花期时间，和每个人的到达时间。
对每个人，我们返回他们到达时在花期内花的数目。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= flowers.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>flowers[i].length == 2</code></li>
	<li><code>1 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们将花按照开始时间和结束时间分别排序，然后对于每个人，我们可以使用二分查找来找到他们到达时在花期内花的数目。就是说，找出在每个人到达时，已经开花的花的数目，减去在每个人到达时，已经凋谢的花的数目，即可得到答案。

时间复杂度 $O((m + n) \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $\textit{flowers}$ 和 $\textit{people}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fullBloomFlowers(
        self, flowers: List[List[int]], people: List[int]
    ) -> List[int]:
        start, end = sorted(a for a, _ in flowers), sorted(b for _, b in flowers)
        return [bisect_right(start, p) - bisect_left(end, p) for p in people]
```

#### Java

```java
class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        int n = flowers.length;
        int[] start = new int[n];
        int[] end = new int[n];
        for (int i = 0; i < n; ++i) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int m = people.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            ans[i] = search(start, people[i] + 1) - search(end, people[i]);
        }
        return ans;
    }

    private int search(int[] nums, int x) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start;
        vector<int> end;
        for (auto& f : flowers) {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        vector<int> ans;
        for (auto& p : people) {
            auto r = upper_bound(start.begin(), start.end(), p) - start.begin();
            auto l = lower_bound(end.begin(), end.end(), p) - end.begin();
            ans.push_back(r - l);
        }
        return ans;
    }
};
```

#### Go

```go
func fullBloomFlowers(flowers [][]int, people []int) (ans []int) {
	n := len(flowers)
	start := make([]int, n)
	end := make([]int, n)
	for i, f := range flowers {
		start[i] = f[0]
		end[i] = f[1]
	}
	sort.Ints(start)
	sort.Ints(end)
	for _, p := range people {
		r := sort.SearchInts(start, p+1)
		l := sort.SearchInts(end, p)
		ans = append(ans, r-l)
	}
	return
}
```

#### TypeScript

```ts
function fullBloomFlowers(flowers: number[][], people: number[]): number[] {
    const n = flowers.length;
    const start = new Array(n).fill(0);
    const end = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        start[i] = flowers[i][0];
        end[i] = flowers[i][1];
    }
    start.sort((a, b) => a - b);
    end.sort((a, b) => a - b);
    const ans: number[] = [];
    for (const p of people) {
        const r = search(start, p + 1);
        const l = search(end, p);
        ans.push(r - l);
    }
    return ans;
}

function search(nums: number[], x: number): number {
    let l = 0;
    let r = nums.length;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
```

#### Rust

```rust
use std::collections::BTreeMap;

impl Solution {
    #[allow(dead_code)]
    pub fn full_bloom_flowers(flowers: Vec<Vec<i32>>, people: Vec<i32>) -> Vec<i32> {
        let n = people.len();

        // First sort the people vector based on the first item
        let mut people: Vec<(usize, i32)> = people.into_iter().enumerate().map(|x| x).collect();

        people.sort_by(|lhs, rhs| lhs.1.cmp(&rhs.1));

        // Initialize the difference vector
        let mut diff = BTreeMap::new();
        let mut ret = vec![0; n];

        for f in flowers {
            let (left, right) = (f[0], f[1]);
            diff.entry(left)
                .and_modify(|x| {
                    *x += 1;
                })
                .or_insert(1);

            diff.entry(right + 1)
                .and_modify(|x| {
                    *x -= 1;
                })
                .or_insert(-1);
        }

        let mut sum = 0;
        let mut i = 0;
        for (k, v) in diff {
            while i < n && people[i].1 < k {
                ret[people[i].0] += sum;
                i += 1;
            }
            sum += v;
        }

        ret
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：差分 + 排序 + 离线查询

我们可以利用差分来维护每个时间点的花的数目。接下来，我们将 $people$ 按照到达时间从小到大排序，在每个人到达时，我们对差分数组进行前缀和运算，就可以得到答案。

时间复杂度 $O(m \times \log m + n \times \log n)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是数组 $\textit{flowers}$ 和 $\textit{people}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fullBloomFlowers(
        self, flowers: List[List[int]], people: List[int]
    ) -> List[int]:
        d = defaultdict(int)
        for st, ed in flowers:
            d[st] += 1
            d[ed + 1] -= 1
        ts = sorted(d)
        s = i = 0
        m = len(people)
        ans = [0] * m
        for t, j in sorted(zip(people, range(m))):
            while i < len(ts) and ts[i] <= t:
                s += d[ts[i]]
                i += 1
            ans[j] = s
        return ans
```

#### Java

```java
class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] people) {
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (int[] f : flowers) {
            d.merge(f[0], 1, Integer::sum);
            d.merge(f[1] + 1, -1, Integer::sum);
        }
        int s = 0;
        int m = people.length;
        Integer[] idx = new Integer[m];
        for (int i = 0; i < m; i++) {
            idx[i] = i;
        }
        Arrays.sort(idx, Comparator.comparingInt(i -> people[i]));
        int[] ans = new int[m];
        for (int i : idx) {
            int t = people[i];
            while (!d.isEmpty() && d.firstKey() <= t) {
                s += d.pollFirstEntry().getValue();
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
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> d;
        for (auto& f : flowers) {
            d[f[0]]++;
            d[f[1] + 1]--;
        }
        int m = people.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return people[i] < people[j];
        });
        vector<int> ans(m);
        int s = 0;
        for (int i : idx) {
            int t = people[i];
            while (!d.empty() && d.begin()->first <= t) {
                s += d.begin()->second;
                d.erase(d.begin());
            }
            ans[i] = s;
        }
        return ans;
    }
};
```

#### Go

```go
func fullBloomFlowers(flowers [][]int, people []int) []int {
	d := map[int]int{}
	for _, f := range flowers {
		d[f[0]]++
		d[f[1]+1]--
	}
	ts := []int{}
	for t := range d {
		ts = append(ts, t)
	}
	sort.Ints(ts)
	m := len(people)
	idx := make([]int, m)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool { return people[idx[i]] < people[idx[j]] })
	ans := make([]int, m)
	s, i := 0, 0
	for _, j := range idx {
		t := people[j]
		for i < len(ts) && ts[i] <= t {
			s += d[ts[i]]
			i++
		}
		ans[j] = s
	}
	return ans
}
```

#### TypeScript

```ts
function fullBloomFlowers(flowers: number[][], people: number[]): number[] {
    const d: Map<number, number> = new Map();
    for (const [st, ed] of flowers) {
        d.set(st, (d.get(st) || 0) + 1);
        d.set(ed + 1, (d.get(ed + 1) || 0) - 1);
    }
    const ts = [...d.keys()].sort((a, b) => a - b);
    let s = 0;
    let i = 0;
    const m = people.length;
    const idx: number[] = [...Array(m)].map((_, i) => i).sort((a, b) => people[a] - people[b]);
    const ans = Array(m).fill(0);
    for (const j of idx) {
        const t = people[j];
        while (i < ts.length && ts[i] <= t) {
            s += d.get(ts[i])!;
            ++i;
        }
        ans[j] = s;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2252. 表的动态旋转 🔒](https://leetcode.cn/problems/dynamic-pivoting-of-a-table){#2252}

{{< tabs "2252" >}}

{{% tab "sql" %}}
```sql
CREATE PROCEDURE PivotProducts()
BEGIN
	# Write your MySQL query statement below.
	SET group_concat_max_len = 5000;
    SELECT GROUP_CONCAT(DISTINCT 'MAX(CASE WHEN store = \'',
               store,
               '\' THEN price ELSE NULL END) AS ',
               store
               ORDER BY store) INTO @sql
    FROM Products;
    SET @sql =  CONCAT('SELECT product_id, ',
                    @sql,
                    ' FROM Products GROUP BY product_id');
    PREPARE stmt FROM @sql;
    EXECUTE stmt;
    DEALLOCATE PREPARE stmt;
END
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store       | varchar |
| price       | int     |
+-------------+---------+
(product_id, store) 是该表的主键（具有唯一值的列的组合）。
该表的每一行都表示商店中的 product_id 的价格。
表中最多有 30 个不同的商店 store。
price 就是这家店商品的价格。
</pre>

<p>&nbsp;</p>

<p><strong>重要提示：</strong>这个问题针对的是那些对 SQL 有丰富经验的人。如果你是初学者，我们建议你现在跳过它。</p>

<p>实现 <code>PivotProducts</code> 过程来重新组织 <code>Products</code> 表，以便每行都有一个商品的 id 及其在每个商店中的价格。如果商品不在商店出售，价格应为 <code>null</code>。表的列应该包含每个商店，并且它们应该按 <strong>字典顺序排序</strong>。</p>

<p>过程应该在重新组织表之后返回它。</p>

<p data-group="1-1">以 <strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Products 表:
+------------+----------+-------+
| product_id | store    | price |
+------------+----------+-------+
| 1          | Shop     | 110   |
| 1          | LC_Store | 100   |
| 2          | Nozama   | 200   |
| 2          | Souq     | 190   |
| 3          | Shop     | 1000  |
| 3          | Souq     | 1900  |
+------------+----------+-------+
<strong>输出:</strong> 
+------------+----------+--------+------+------+
| product_id | LC_Store | Nozama | Shop | Souq |
+------------+----------+--------+------+------+
| 1          | 100      | null   | 110  | null |
| 2          | null     | 200    | null | 190  |
| 3          | null     | null   | 1000 | 1900 |
+------------+----------+--------+------+------+
<strong>解释:</strong> 
有 4 个商店: Shop, LC_Store, Nozama, Souq。 我们首先按字典顺序排列: LC_Store, Nozama, Shop, Souq.
现在, 对于商品 1, LC_Store 的价格是 100，Shop 的价格是 110。另外两个商店没有该商品销售，因此我们将价格设置为 null。
同样, 商品 2 在 Nozama 中的价格是 200，Souq 中的价格是 190。其他两家店都不卖。
商品 3, Shop 中的价格是 1000,Souq 中的价格是1900。其他两家店都不卖。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
CREATE PROCEDURE PivotProducts()
BEGIN
	# Write your MySQL query statement below.
	SET group_concat_max_len = 5000;
    SELECT GROUP_CONCAT(DISTINCT 'MAX(CASE WHEN store = \'',
               store,
               '\' THEN price ELSE NULL END) AS ',
               store
               ORDER BY store) INTO @sql
    FROM Products;
    SET @sql =  CONCAT('SELECT product_id, ',
                    @sql,
                    ' FROM Products GROUP BY product_id');
    PREPARE stmt FROM @sql;
    EXECUTE stmt;
    DEALLOCATE PREPARE stmt;
END
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2253. 动态取消表的旋转 🔒](https://leetcode.cn/problems/dynamic-unpivoting-of-a-table){#2253}

{{< tabs "2253" >}}

{{% tab "sql" %}}
```sql
CREATE PROCEDURE UnpivotProducts()
BEGIN
    # Write your MySQL query statement below.
    SET group_concat_max_len = 5000;
    WITH
        t AS (
            SELECT column_name
            FROM information_schema.columns
            WHERE
                table_schema = DATABASE()
                AND table_name = 'Products'
                AND column_name != 'product_id'
        )
    SELECT
        GROUP_CONCAT(
            'SELECT product_id, \'',
            column_name,
            '\' store, ',
            column_name,
            ' price FROM Products WHERE ',
            column_name,
            ' IS NOT NULL' SEPARATOR ' UNION '
        ) INTO @sql from t;
    PREPARE stmt FROM @sql;
    EXECUTE stmt;
    DEALLOCATE PREPARE stmt;
END;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Products</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product_id  | int     |
| store_name<sub>1</sub> | int     |
| store_name<sub>2</sub> | int     |
|      :      | int     |
|      :      | int     |
|      :      | int     |
| store_name<sub>n</sub> | int     |
+-------------+---------+
product_id 是该表的主键。
该表中的每一行都表示该商品在 n 个不同商店中的价格。
如果商店中没有该商品，则该商店列中的价格将为 null。
不同测试用例的商店名称可能会不同。至少有1家店，最多30家店。
</pre>

<p>&nbsp;</p>

<p><strong>重要提示:</strong> 这个问题针对的是那些对 SQL 有丰富经验的人。如果你是初学者，我们建议你现在跳过它。</p>

<p>实现 <code>UnpivotProducts</code> 过程来重新组织 <code>Products</code> 表，使每一行都有一个产品的 id、销售该商品的商店名称以及该商品在该商店中的价格。如果某个商品在某个商店中不可用，则不要在结果表中包含该 <code>product_id</code> 和 <code>store</code> 组合的行。结果应该有三列:<code>product_id</code>、<code>store</code> 和 <code>price</code>。</p>

<p>过程应该在重新组织表之后返回它。</p>

<p data-group="1-1">以 <strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Products 表:
+------------+----------+--------+------+------+
| product_id | LC_Store | Nozama | Shop | Souq |
+------------+----------+--------+------+------+
| 1          | 100      | null   | 110  | null |
| 2          | null     | 200    | null | 190  |
| 3          | null     | null   | 1000 | 1900 |
+------------+----------+--------+------+------+
<strong>输出:</strong> 
+------------+----------+-------+
| product_id | store    | price |
+------------+----------+-------+
| 1          | LC_Store | 100   |
| 1          | Shop     | 110   |
| 2          | Nozama   | 200   |
| 2          | Souq     | 190   |
| 3          | Shop     | 1000  |
| 3          | Souq     | 1900  |
+------------+----------+-------+
<strong>解释:</strong> 
商品 1 在 LC_Store 和 Shop 销售，价格分别为 100 和 110。
商品 2 在 Nozama 和 Souq 销售，价格分别为 200 和 190。
商品 3 在 Shop 和 Souq 出售，价格分别为 1000 和 1900。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
CREATE PROCEDURE UnpivotProducts()
BEGIN
    # Write your MySQL query statement below.
    SET group_concat_max_len = 5000;
    WITH
        t AS (
            SELECT column_name
            FROM information_schema.columns
            WHERE
                table_schema = DATABASE()
                AND table_name = 'Products'
                AND column_name != 'product_id'
        )
    SELECT
        GROUP_CONCAT(
            'SELECT product_id, \'',
            column_name,
            '\' store, ',
            column_name,
            ' price FROM Products WHERE ',
            column_name,
            ' IS NOT NULL' SEPARATOR ' UNION '
        ) INTO @sql from t;
    PREPARE stmt FROM @sql;
    EXECUTE stmt;
    DEALLOCATE PREPARE stmt;
END;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2254. 设计视频共享平台 🔒](https://leetcode.cn/problems/design-video-sharing-platform){#2254}

{{< tabs "2254" >}}

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

<p>你有一个视频分享平台，用户可以上传和删除视频。每个 <code>video</code> 都是&nbsp;<strong>字符串&nbsp;</strong>类型的数字，其中字符串的第 <code>i</code> 位表示视频中第 <code>i</code> 分钟的内容。例如，第一个数字表示视频中第 <code>0</code> 分钟的内容，第二个数字表示视频中第 <code>1</code> 分钟的内容，以此类推。视频的观众也可以喜欢和不喜欢视频。该平台会跟踪每个视频的&nbsp;<strong>观看次数</strong>、<strong>点赞次数&nbsp;</strong>和 <strong>不喜欢次数</strong>。</p>

<p>当视频上传时，它与最小可用整数 <code>videoId</code> 相关联，<code>videoId</code> 从 <code>0</code> 开始的。一旦一个视频被删除，与该视频关联的 <code>videoId</code> 就可以用于另一个视频。</p>

<p>实现 <code>VideoSharingPlatform</code> 类:</p>

<ul>
	<li><code>VideoSharingPlatform()</code> 初始化对象。</li>
	<li><code>int upload(String video)</code> 用户上传一个 <code>video</code>. 返回与视频相关联的<code>videoId</code> 。</li>
	<li><code>void remove(int videoId)</code>&nbsp;如果存在与 <code>videoId</code> 相关联的视频，则删除该视频。</li>
	<li><code>String watch(int videoId, int startMinute, int endMinute)</code> 如果有一个视频与 <code>videoId</code>&nbsp;相关联，则将该视频的观看次数增加 <code>1</code>，并返回视频字符串的子字符串，从 <code>startMinute</code> 开始，以 <code>min(endMinute, video.length - 1</code><code>)</code>(含边界) 结束。否则，返回 <code>"-1"</code>。</li>
	<li><code>void like(int videoId)</code> 如果存在与 <code>videoId</code> 相关联的视频，则将与 <code>videoId</code> 相关联的视频的点赞数增加 <code>1</code>。</li>
	<li><code>void dislike(int videoId)</code> 如果存在与 <code>videoId</code> 相关联的视频，则将与 <code>videoId</code> 相关联的视频上的不喜欢次数增加 <code>1</code>。</li>
	<li><code>int[] getLikesAndDislikes(int videoId)</code> 返回一个长度为 <code>2</code> ，<strong>下标从 0 开始 </strong>的整型数组，其中 <code>values[0]</code>&nbsp;是与 <code>videoId</code>&nbsp;相关联的视频上的点赞数，<code>values[1]</code> 是不喜欢数。如果没有与&nbsp;<code>videoId</code> 相关联的视频，则返回 <code>[-1]</code>。</li>
	<li><code>int getViews(int videoId)</code> 返回与&nbsp;<code>videoId</code> 相关联的视频的观看次数，如果没有与 <code>videoId</code>&nbsp;相关联的视频，返回 <code>-1</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入</strong>
["VideoSharingPlatform", "upload", "upload", "remove", "remove", "upload", "watch", "watch", "like", "dislike", "dislike", "getLikesAndDislikes", "getViews"]
[[], ["123"], ["456"], [4], [0], ["789"], [1, 0, 5], [1, 0, 1], [1], [1], [1], [1], [1]]
<strong>输出</strong>
[null, 0, 1, null, null, 0, "456", "45", null, null, null, [1, 2], 2]

<strong>解释</strong>
VideoSharingPlatform videoSharingPlatform = new VideoSharingPlatform();
videoSharingPlatform.upload("123");          // 最小的可用 videoId 是 0，所以返回 0。
videoSharingPlatform.upload("456");          // 最小的可用 videoId 是 1，所以返回 1。
videoSharingPlatform.remove(4);              // 没有与 videoId 4 相关联的视频，所以什么都不做。
videoSharingPlatform.remove(0);              // 删除与 videoId 0 关联的视频。
videoSharingPlatform.upload("789");          // 由于与 videoId 0 相关联的视频被删除，
                                             // 0 是最小的可用 videoId，所以返回 0。
videoSharingPlatform.watch(1, 0, 5);         // 与 videoId 1 关联的视频为 "456"。
                                             // 从分钟 0 到分钟 min(5,3 - 1)= 2 的视频为 "456"，因此返回 "456"。
videoSharingPlatform.watch(1, 0, 1);         // 与 videoId 1 关联的视频为 "456"。
                                             // 从分钟 0 到分钟 min(1,3 - 1)= 1 的视频为 "45"，因此返回 "45"。
videoSharingPlatform.like(1);                // 增加与 videoId 1 相关的视频的点赞数。
videoSharingPlatform.dislike(1);             // 增加与 videoId 1 相关联的视频的不喜欢的数量。
videoSharingPlatform.dislike(1);             // 增加与 videoId 1 相关联的视频的不喜欢的数量。
videoSharingPlatform.getLikesAndDislikes(1); // 在与 videoId 1 相关的视频中有 1 个喜欢和 2 个不喜欢，因此返回[1,2]。
videoSharingPlatform.getViews(1);            // 与 videoId 1 相关联的视频有 2 个观看数，因此返回2。
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入</strong>
["VideoSharingPlatform", "remove", "watch", "like", "dislike", "getLikesAndDislikes", "getViews"]
[[], [0], [0, 0, 1], [0], [0], [0], [0]]
<strong>输出</strong>
[null, null, "-1", null, null, [-1], -1]

<strong>解释</strong>
VideoSharingPlatform videoSharingPlatform = new VideoSharingPlatform();
videoSharingPlatform.remove(0);              // 没有与 videoId 0 相关联的视频，所以什么都不做。
videoSharingPlatform.watch(0, 0, 1);         // 没有与 videoId 0 相关联的视频，因此返回 "-1"。
videoSharingPlatform.like(0);                // 没有与 videoId 0 相关联的视频，所以什么都不做。
videoSharingPlatform.dislike(0);             // 没有与 videoId 0 相关联的视频，所以什么都不做。
videoSharingPlatform.getLikesAndDislikes(0); // 没有与 videoId 0 相关联的视频，因此返回 [-1]。
videoSharingPlatform.getViews(0);            // 没有视频与 videoId 0 相关联，因此返回 -1。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= video.length &lt;= 10<sup>5</sup></code></li>
	<li>调用&nbsp;<code>upload</code>&nbsp;时所有&nbsp;<code>video.length</code>&nbsp;的总和不会超过&nbsp;<code>10<sup>5</sup></code></li>
	<li><code>video</code> 由数字组成</li>
	<li><code>0 &lt;= videoId &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= startMinute &lt; endMinute &lt; 10<sup>5</sup></code></li>
	<li><code>startMinute &lt; video.length</code></li>
	<li>调用&nbsp; <code>watch</code>&nbsp;时所有&nbsp;<code>endMinute - startMinute</code>&nbsp;的总和不会超过&nbsp;<code>10<sup>5</sup></code>。</li>
	<li>所有函数&nbsp;<strong>总共&nbsp;</strong>最多调用 <code>10<sup>5</sup></code> 次。</li>
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

# [2255. 统计是给定字符串前缀的字符串数目](https://leetcode.cn/problems/count-prefixes-of-a-given-string){#2255}

{{< tabs "2255" >}}

{{% tab "python" %}}
```python
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(s.startswith(w) for w in words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countPrefixes(String[] words, String s) {
        int ans = 0;
        for (String w : words) {
            if (s.startsWith(w)) {
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
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& w : words) {
            ans += s.starts_with(w);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countPrefixes(words []string, s string) (ans int) {
	for _, w := range words {
		if strings.HasPrefix(s, w) {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countPrefixes(words: string[], s: string): number {
    return words.filter(w => s.startsWith(w)).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_prefixes(words: Vec<String>, s: String) -> i32 {
        words.iter().filter(|w| s.starts_with(w.as_str())).count() as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountPrefixes(string[] words, string s) {
        return words.Count(w => s.StartsWith(w));
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串数组&nbsp;<code>words</code>&nbsp;和一个字符串&nbsp;<code>s</code>&nbsp;，其中&nbsp;<code>words[i]</code> 和&nbsp;<code>s</code>&nbsp;只包含 <strong>小写英文字母</strong>&nbsp;。</p>

<p>请你返回 <code>words</code>&nbsp;中是字符串 <code>s</code>&nbsp;<strong>前缀&nbsp;</strong>的 <strong>字符串数目</strong>&nbsp;。</p>

<p>一个字符串的 <strong>前缀</strong>&nbsp;是出现在字符串开头的子字符串。<strong>子字符串</strong>&nbsp;是一个字符串中的连续一段字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>words = ["a","b","c","ab","bc","abc"], s = "abc"
<b>输出：</b>3
<strong>解释：</strong>
words 中是 s = "abc" 前缀的字符串为：
"a" ，"ab" 和 "abc" 。
所以 words 中是字符串 s 前缀的字符串数目为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>words = ["a","a"], s = "aa"
<b>输出：</b>2
<strong>解释：
</strong>两个字符串都是 s 的前缀。
注意，相同的字符串可能在 words 中出现多次，它们应该被计数多次。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, s.length &lt;= 10</code></li>
	<li><code>words[i]</code> 和&nbsp;<code>s</code>&nbsp;<strong>只</strong>&nbsp;包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们直接遍历数组 $\textit{words}$，对于每个字符串 $w$，判断 $s$ 是否以 $w$ 为前缀，如果是则答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是数组 $\textit{words}$ 的长度和字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(s.startswith(w) for w in words)
```

#### Java

```java
class Solution {
    public int countPrefixes(String[] words, String s) {
        int ans = 0;
        for (String w : words) {
            if (s.startsWith(w)) {
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
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& w : words) {
            ans += s.starts_with(w);
        }
        return ans;
    }
};
```

#### Go

```go
func countPrefixes(words []string, s string) (ans int) {
	for _, w := range words {
		if strings.HasPrefix(s, w) {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countPrefixes(words: string[], s: string): number {
    return words.filter(w => s.startsWith(w)).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_prefixes(words: Vec<String>, s: String) -> i32 {
        words.iter().filter(|w| s.starts_with(w.as_str())).count() as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int CountPrefixes(string[] words, string s) {
        return words.Count(w => s.StartsWith(w));
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2256. 最小平均差](https://leetcode.cn/problems/minimum-average-difference){#2256}

{{< tabs "2256" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        pre, suf = 0, sum(nums)
        n = len(nums)
        ans, mi = 0, inf
        for i, x in enumerate(nums):
            pre += x
            suf -= x
            a = pre // (i + 1)
            b = 0 if n - i - 1 == 0 else suf // (n - i - 1)
            if (t := abs(a - b)) < mi:
                ans = i
                mi = t
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length;
        long pre = 0, suf = 0;
        for (int x : nums) {
            suf += x;
        }
        int ans = 0;
        long mi = Long.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            suf -= nums[i];
            long a = pre / (i + 1);
            long b = n - i - 1 == 0 ? 0 : suf / (n - i - 1);
            long t = Math.abs(a - b);
            if (t < mi) {
                ans = i;
                mi = t;
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
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        using ll = long long;
        ll pre = 0;
        ll suf = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        ll mi = suf;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            suf -= nums[i];
            ll a = pre / (i + 1);
            ll b = n - i - 1 == 0 ? 0 : suf / (n - i - 1);
            ll t = abs(a - b);
            if (t < mi) {
                ans = i;
                mi = t;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumAverageDifference(nums []int) (ans int) {
	n := len(nums)
	pre, suf := 0, 0
	for _, x := range nums {
		suf += x
	}
	mi := suf
	for i, x := range nums {
		pre += x
		suf -= x
		a := pre / (i + 1)
		b := 0
		if n-i-1 != 0 {
			b = suf / (n - i - 1)
		}
		if t := abs(a - b); t < mi {
			ans = i
			mi = t
		}
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
function minimumAverageDifference(nums: number[]): number {
    const n = nums.length;
    let pre = 0;
    let suf = nums.reduce((a, b) => a + b);
    let ans = 0;
    let mi = suf;
    for (let i = 0; i < n; ++i) {
        pre += nums[i];
        suf -= nums[i];
        const a = Math.floor(pre / (i + 1));
        const b = n - i - 1 === 0 ? 0 : Math.floor(suf / (n - i - 1));
        const t = Math.abs(a - b);
        if (t < mi) {
            ans = i;
            mi = t;
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>下标 <code>i</code>&nbsp;处的 <strong>平均差</strong>&nbsp;指的是 <code>nums</code>&nbsp;中 <strong>前</strong>&nbsp;<code>i + 1</code>&nbsp;个元素平均值和 <strong>后</strong>&nbsp;<code>n - i - 1</code>&nbsp;个元素平均值的 <strong>绝对差</strong>&nbsp;。两个平均值都需要 <strong>向下取整</strong>&nbsp;到最近的整数。</p>

<p>请你返回产生 <strong>最小平均差</strong>&nbsp;的下标。如果有多个下标最小平均差相等，请你返回 <strong>最小</strong>&nbsp;的一个下标。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>两个数的<strong>&nbsp;绝对差</strong>&nbsp;是两者差的绝对值。</li>
	<li>&nbsp;<code>n</code>&nbsp;个元素的平均值是 <code>n</code>&nbsp;个元素之 <strong>和</strong>&nbsp;除以（整数除法）&nbsp;<code>n</code>&nbsp;。</li>
	<li><code>0</code>&nbsp;个元素的平均值视为&nbsp;<code>0</code>&nbsp;。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [2,5,3,9,5,3]
<b>输出：</b>3
<strong>解释：</strong>
- 下标 0 处的平均差为：|2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3 。
- 下标 1 处的平均差为：|(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2 。
- 下标 2 处的平均差为：|(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2 。
- 下标 3 处的平均差为：|(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0 。 
- 下标 4 处的平均差为：|(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1 。
- 下标 5 处的平均差为：|(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4 。
下标 3 处的平均差为最小平均差，所以返回 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [0]
<b>输出：</b>0
<strong>解释：</strong>
唯一的下标是 0 ，所以我们返回 0 。
下标 0 处的平均差为：|0 / 1 - 0| = |0 - 0| = 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们直接遍历数组 $nums$，对于每个下标 $i$，维护前 $i + 1$ 个元素的和 $pre$ 和后 $n - i - 1$ 个元素的和 $suf$，计算平均差的绝对值 $t$，如果 $t$ 小于当前最小值 $mi$，则更新答案 $ans = i$ 和最小值 $mi = t$。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        pre, suf = 0, sum(nums)
        n = len(nums)
        ans, mi = 0, inf
        for i, x in enumerate(nums):
            pre += x
            suf -= x
            a = pre // (i + 1)
            b = 0 if n - i - 1 == 0 else suf // (n - i - 1)
            if (t := abs(a - b)) < mi:
                ans = i
                mi = t
        return ans
```

#### Java

```java
class Solution {
    public int minimumAverageDifference(int[] nums) {
        int n = nums.length;
        long pre = 0, suf = 0;
        for (int x : nums) {
            suf += x;
        }
        int ans = 0;
        long mi = Long.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            suf -= nums[i];
            long a = pre / (i + 1);
            long b = n - i - 1 == 0 ? 0 : suf / (n - i - 1);
            long t = Math.abs(a - b);
            if (t < mi) {
                ans = i;
                mi = t;
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
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        using ll = long long;
        ll pre = 0;
        ll suf = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        ll mi = suf;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            suf -= nums[i];
            ll a = pre / (i + 1);
            ll b = n - i - 1 == 0 ? 0 : suf / (n - i - 1);
            ll t = abs(a - b);
            if (t < mi) {
                ans = i;
                mi = t;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minimumAverageDifference(nums []int) (ans int) {
	n := len(nums)
	pre, suf := 0, 0
	for _, x := range nums {
		suf += x
	}
	mi := suf
	for i, x := range nums {
		pre += x
		suf -= x
		a := pre / (i + 1)
		b := 0
		if n-i-1 != 0 {
			b = suf / (n - i - 1)
		}
		if t := abs(a - b); t < mi {
			ans = i
			mi = t
		}
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
function minimumAverageDifference(nums: number[]): number {
    const n = nums.length;
    let pre = 0;
    let suf = nums.reduce((a, b) => a + b);
    let ans = 0;
    let mi = suf;
    for (let i = 0; i < n; ++i) {
        pre += nums[i];
        suf -= nums[i];
        const a = Math.floor(pre / (i + 1));
        const b = n - i - 1 === 0 ? 0 : Math.floor(suf / (n - i - 1));
        const t = Math.abs(a - b);
        if (t < mi) {
            ans = i;
            mi = t;
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

# [2257. 统计网格图中没有被保卫的格子数](https://leetcode.cn/problems/count-unguarded-cells-in-the-grid){#2257}

{{< tabs "2257" >}}

{{% tab "python" %}}
```python
class Solution:
    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        g = [[0] * n for _ in range(m)]
        for i, j in guards:
            g[i][j] = 2
        for i, j in walls:
            g[i][j] = 2
        dirs = (-1, 0, 1, 0, -1)
        for i, j in guards:
            for a, b in pairwise(dirs):
                x, y = i, j
                while 0 <= x + a < m and 0 <= y + b < n and g[x + a][y + b] < 2:
                    x, y = x + a, y + b
                    g[x][y] = 1
        return sum(v == 0 for row in g for v in row)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] g = new int[m][n];
        for (var e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (var e : walls) {
            g[e[0]][e[1]] = 2;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (var e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                    x += a;
                    y += b;
                    g[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (var row : g) {
            for (int v : row) {
                if (v == 0) {
                    ++ans;
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
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g[m][n];
        memset(g, 0, sizeof(g));
        for (auto& e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (auto& e : walls) {
            g[e[0]][e[1]] = 2;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (auto& e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                    x += a;
                    y += b;
                    g[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (auto& row : g) {
            ans += count(row, row + n, 0);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countUnguarded(m int, n int, guards [][]int, walls [][]int) (ans int) {
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
	}
	for _, e := range guards {
		g[e[0]][e[1]] = 2
	}
	for _, e := range walls {
		g[e[0]][e[1]] = 2
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for _, e := range guards {
		for k := 0; k < 4; k++ {
			x, y := e[0], e[1]
			a, b := dirs[k], dirs[k+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && g[x+a][y+b] < 2 {
				x, y = x+a, y+b
				g[x][y] = 1
			}
		}
	}
	for _, row := range g {
		for _, v := range row {
			if v == 0 {
				ans++
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    let c = 0;
    const mtx = Array.from({ length: m }, () => Array(n).fill(0));
    for (const [i, j] of guards) mtx[i][j] = 2;
    for (const [i, j] of walls) mtx[i][j] = 2;

    const dfs = (i: number, j: number, dx: number, dy: number) => {
        [i, j] = [i + dx, j + dy];

        if (i < 0 || m <= i || j < 0 || n <= j || mtx[i][j] === 2) return;

        if (mtx[i][j] === 0) {
            mtx[i][j] = 1;
            c++;
        }

        dfs(i, j, dx, dy);
    };

    const DIRS = [-1, 0, 1, 0, -1];
    for (const [i, j] of guards) {
        for (let k = 0; k < 4; k++) {
            const [dx, dy] = [DIRS[k], DIRS[k + 1]];
            dfs(i, j, dx, dy);
        }
    }

    return m * n - guards.length - walls.length - c;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function countUnguarded(m, n, guards, walls) {
    let c = 0;
    const mtx = Array.from({ length: m }, () => Array(n).fill(0));
    for (const [i, j] of guards) mtx[i][j] = 2;
    for (const [i, j] of walls) mtx[i][j] = 2;

    const dfs = (i, j, dx, dy) => {
        [i, j] = [i + dx, j + dy];

        if (i < 0 || m <= i || j < 0 || n <= j || mtx[i][j] === 2) return;

        if (mtx[i][j] === 0) {
            mtx[i][j] = 1;
            c++;
        }

        dfs(i, j, dx, dy);
    };

    const DIRS = [-1, 0, 1, 0, -1];
    for (const [i, j] of guards) {
        for (let k = 0; k < 4; k++) {
            const [dx, dy] = [DIRS[k], DIRS[k + 1]];
            dfs(i, j, dx, dy);
        }
    }

    return m * n - guards.length - walls.length - c;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数&nbsp;<code>m</code>&nbsp;和&nbsp;<code>n</code>&nbsp;表示一个下标从<strong>&nbsp;0</strong>&nbsp;开始的&nbsp;<code>m x n</code>&nbsp;网格图。同时给你两个二维整数数组&nbsp;<code>guards</code> 和&nbsp;<code>walls</code>&nbsp;，其中&nbsp;<code>guards[i] = [row<sub>i</sub>, col<sub>i</sub>]</code>&nbsp;且&nbsp;<code>walls[j] = [row<sub>j</sub>, col<sub>j</sub>]</code>&nbsp;，分别表示第 <code>i</code>&nbsp;个警卫和第 <code>j</code>&nbsp;座墙所在的位置。</p>

<p>一个警卫能看到 4 个坐标轴方向（即东、南、西、北）的 <strong>所有</strong>&nbsp;格子，除非他们被一座墙或者另外一个警卫 <strong>挡住</strong>&nbsp;了视线。如果一个格子能被 <strong>至少</strong>&nbsp;一个警卫看到，那么我们说这个格子被 <strong>保卫</strong>&nbsp;了。</p>

<p>请你返回空格子中，有多少个格子是 <strong>没被保卫</strong>&nbsp;的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2257.Count%20Unguarded%20Cells%20in%20the%20Grid/images/example1drawio2.png" style="width: 300px; height: 204px;"></p>

<pre><b>输入：</b>m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
<b>输出：</b>7
<strong>解释：</strong>上图中，被保卫和没有被保卫的格子分别用红色和绿色表示。
总共有 7 个没有被保卫的格子，所以我们返回 7 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2257.Count%20Unguarded%20Cells%20in%20the%20Grid/images/example2drawio.png" style="width: 200px; height: 201px;"></p>

<pre><b>输入：</b>m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
<b>输出：</b>4
<b>解释：</b>上图中，没有被保卫的格子用绿色表示。
总共有 4 个没有被保卫的格子，所以我们返回 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>2 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= guards.length, walls.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>2 &lt;= guards.length + walls.length &lt;= m * n</code></li>
	<li><code>guards[i].length == walls[j].length == 2</code></li>
	<li><code>0 &lt;= row<sub>i</sub>, row<sub>j</sub> &lt; m</code></li>
	<li><code>0 &lt;= col<sub>i</sub>, col<sub>j</sub> &lt; n</code></li>
	<li><code>guards</code>&nbsp;和&nbsp;<code>walls</code>&nbsp;中所有位置 <strong>互不相同</strong>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们创建一个 $m \times n$ 的二维数组 $g$，其中 $g[i][j]$ 表示第 $i$ 行第 $j$ 列的格子。初始时 $g[i][j]$ 的值为 $0$，表示该格子没有被保卫。

然后遍历所有的警卫和墙，将 $g[i][j]$ 的值置为 $2$，这些位置不能被访问。

接下来，我们遍历所有警卫的位置，从该位置出发，向四个方向进行模拟，直到遇到墙或警卫，或者越界。在模拟的过程中，将遇到的格子的值置为 $1$，表示该格子被保卫。

最后，我们遍历 $g$，统计值为 $0$ 的格子的个数，即为答案。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        g = [[0] * n for _ in range(m)]
        for i, j in guards:
            g[i][j] = 2
        for i, j in walls:
            g[i][j] = 2
        dirs = (-1, 0, 1, 0, -1)
        for i, j in guards:
            for a, b in pairwise(dirs):
                x, y = i, j
                while 0 <= x + a < m and 0 <= y + b < n and g[x + a][y + b] < 2:
                    x, y = x + a, y + b
                    g[x][y] = 1
        return sum(v == 0 for row in g for v in row)
```

#### Java

```java
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] g = new int[m][n];
        for (var e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (var e : walls) {
            g[e[0]][e[1]] = 2;
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (var e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                    x += a;
                    y += b;
                    g[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (var row : g) {
            for (int v : row) {
                if (v == 0) {
                    ++ans;
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
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g[m][n];
        memset(g, 0, sizeof(g));
        for (auto& e : guards) {
            g[e[0]][e[1]] = 2;
        }
        for (auto& e : walls) {
            g[e[0]][e[1]] = 2;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        for (auto& e : guards) {
            for (int k = 0; k < 4; ++k) {
                int x = e[0], y = e[1];
                int a = dirs[k], b = dirs[k + 1];
                while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                    x += a;
                    y += b;
                    g[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (auto& row : g) {
            ans += count(row, row + n, 0);
        }
        return ans;
    }
};
```

#### Go

```go
func countUnguarded(m int, n int, guards [][]int, walls [][]int) (ans int) {
	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
	}
	for _, e := range guards {
		g[e[0]][e[1]] = 2
	}
	for _, e := range walls {
		g[e[0]][e[1]] = 2
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	for _, e := range guards {
		for k := 0; k < 4; k++ {
			x, y := e[0], e[1]
			a, b := dirs[k], dirs[k+1]
			for x+a >= 0 && x+a < m && y+b >= 0 && y+b < n && g[x+a][y+b] < 2 {
				x, y = x+a, y+b
				g[x][y] = 1
			}
		}
	}
	for _, row := range g {
		for _, v := range row {
			if v == 0 {
				ans++
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    const g: number[][] = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (const [i, j] of guards) {
        g[i][j] = 2;
    }
    for (const [i, j] of walls) {
        g[i][j] = 2;
    }
    const dirs: number[] = [-1, 0, 1, 0, -1];
    for (const [i, j] of guards) {
        for (let k = 0; k < 4; ++k) {
            let [x, y] = [i, j];
            let [a, b] = [dirs[k], dirs[k + 1]];
            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                x += a;
                y += b;
                g[x][y] = 1;
            }
        }
    }
    let ans = 0;
    for (const row of g) {
        for (const v of row) {
            ans += v === 0 ? 1 : 0;
        }
    }
    return ans;
}
```

#### JavaScript

```js
function countUnguarded(m, n, guards, walls) {
    const g = Array.from({ length: m }, () => Array.from({ length: n }, () => 0));
    for (const [i, j] of guards) {
        g[i][j] = 2;
    }
    for (const [i, j] of walls) {
        g[i][j] = 2;
    }
    const dirs = [-1, 0, 1, 0, -1];
    for (const [i, j] of guards) {
        for (let k = 0; k < 4; ++k) {
            let [x, y] = [i, j];
            let [a, b] = [dirs[k], dirs[k + 1]];
            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2) {
                x += a;
                y += b;
                g[x][y] = 1;
            }
        }
    }
    let ans = 0;
    for (const row of g) {
        for (const v of row) {
            ans += v === 0 ? 1 : 0;
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS + 模拟

<!-- tabs:start -->

#### TypeScript

```ts
function countUnguarded(m: number, n: number, guards: number[][], walls: number[][]): number {
    let c = 0;
    const mtx = Array.from({ length: m }, () => Array(n).fill(0));
    for (const [i, j] of guards) mtx[i][j] = 2;
    for (const [i, j] of walls) mtx[i][j] = 2;

    const dfs = (i: number, j: number, dx: number, dy: number) => {
        [i, j] = [i + dx, j + dy];

        if (i < 0 || m <= i || j < 0 || n <= j || mtx[i][j] === 2) return;

        if (mtx[i][j] === 0) {
            mtx[i][j] = 1;
            c++;
        }

        dfs(i, j, dx, dy);
    };

    const DIRS = [-1, 0, 1, 0, -1];
    for (const [i, j] of guards) {
        for (let k = 0; k < 4; k++) {
            const [dx, dy] = [DIRS[k], DIRS[k + 1]];
            dfs(i, j, dx, dy);
        }
    }

    return m * n - guards.length - walls.length - c;
}
```

#### JavaScript

```js
function countUnguarded(m, n, guards, walls) {
    let c = 0;
    const mtx = Array.from({ length: m }, () => Array(n).fill(0));
    for (const [i, j] of guards) mtx[i][j] = 2;
    for (const [i, j] of walls) mtx[i][j] = 2;

    const dfs = (i, j, dx, dy) => {
        [i, j] = [i + dx, j + dy];

        if (i < 0 || m <= i || j < 0 || n <= j || mtx[i][j] === 2) return;

        if (mtx[i][j] === 0) {
            mtx[i][j] = 1;
            c++;
        }

        dfs(i, j, dx, dy);
    };

    const DIRS = [-1, 0, 1, 0, -1];
    for (const [i, j] of guards) {
        for (let k = 0; k < 4; k++) {
            const [dx, dy] = [DIRS[k], DIRS[k + 1]];
            dfs(i, j, dx, dy);
        }
    }

    return m * n - guards.length - walls.length - c;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2258. 逃离火灾](https://leetcode.cn/problems/escape-the-spreading-fire){#2258}

{{< tabs "2258" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        def spread(q: Deque[int]) -> Deque[int]:
            nq = deque()
            while q:
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and not fire[x][y] and grid[x][y] == 0:
                        fire[x][y] = True
                        nq.append((x, y))
            return nq

        def check(t: int) -> bool:
            for i in range(m):
                for j in range(n):
                    fire[i][j] = False
            q1 = deque()
            for i, row in enumerate(grid):
                for j, x in enumerate(row):
                    if x == 1:
                        fire[i][j] = True
                        q1.append((i, j))
            while t and q1:
                q1 = spread(q1)
                t -= 1
            if fire[0][0]:
                return False
            q2 = deque([(0, 0)])
            vis = [[False] * n for _ in range(m)]
            vis[0][0] = True
            while q2:
                for _ in range(len(q2)):
                    i, j = q2.popleft()
                    if fire[i][j]:
                        continue
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        if (
                            0 <= x < m
                            and 0 <= y < n
                            and not vis[x][y]
                            and not fire[x][y]
                            and grid[x][y] == 0
                        ):
                            if x == m - 1 and y == n - 1:
                                return True
                            vis[x][y] = True
                            q2.append((x, y))
                q1 = spread(q1)
            return False

        m, n = len(grid), len(grid[0])
        l, r = -1, m * n
        dirs = (-1, 0, 1, 0, -1)
        fire = [[False] * n for _ in range(m)]
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return int(1e9) if l == m * n else l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] grid;
    private boolean[][] fire;
    private boolean[][] vis;
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int m;
    private int n;

    public int maximumMinutes(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        fire = new boolean[m][n];
        vis = new boolean[m][n];
        int l = -1, r = m * n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == m * n ? 1000000000 : l;
    }

    private boolean check(int t) {
        for (int i = 0; i < m; ++i) {
            Arrays.fill(fire[i], false);
            Arrays.fill(vis[i], false);
        }
        Deque<int[]> q1 = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q1.offer(new int[] {i, j});
                    fire[i][j] = true;
                }
            }
        }
        for (; t > 0 && !q1.isEmpty(); --t) {
            q1 = spread(q1);
        }
        if (fire[0][0]) {
            return false;
        }
        Deque<int[]> q2 = new ArrayDeque<>();
        q2.offer(new int[] {0, 0});
        vis[0][0] = true;
        for (; !q2.isEmpty(); q1 = spread(q1)) {
            for (int d = q2.size(); d > 0; --d) {
                int[] p = q2.poll();
                if (fire[p[0]][p[1]]) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && !vis[x][y]
                        && grid[x][y] == 0) {
                        if (x == m - 1 && y == n - 1) {
                            return true;
                        }
                        vis[x][y] = true;
                        q2.offer(new int[] {x, y});
                    }
                }
            }
        }
        return false;
    }

    private Deque<int[]> spread(Deque<int[]> q) {
        Deque<int[]> nq = new ArrayDeque<>();
        while (!q.isEmpty()) {
            int[] p = q.poll();
            for (int k = 0; k < 4; ++k) {
                int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] == 0) {
                    fire[x][y] = true;
                    nq.offer(new int[] {x, y});
                }
            }
        }
        return nq;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n];
        bool fire[m][n];
        int dirs[5] = {-1, 0, 1, 0, -1};
        auto spread = [&](queue<pair<int, int>>& q) {
            queue<pair<int, int>> nq;
            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] == 0) {
                        fire[x][y] = true;
                        nq.emplace(x, y);
                    }
                }
            }
            return nq;
        };
        auto check = [&](int t) {
            memset(vis, false, sizeof(vis));
            memset(fire, false, sizeof(fire));
            queue<pair<int, int>> q1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        q1.emplace(i, j);
                        fire[i][j] = true;
                    }
                }
            }
            for (; t && q1.size(); --t) {
                q1 = spread(q1);
            }
            if (fire[0][0]) {
                return false;
            }
            queue<pair<int, int>> q2;
            q2.emplace(0, 0);
            vis[0][0] = true;
            for (; q2.size(); q1 = spread(q1)) {
                for (int d = q2.size(); d; --d) {
                    auto [i, j] = q2.front();
                    q2.pop();
                    if (fire[i][j]) {
                        continue;
                    }
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && !fire[x][y] && grid[x][y] == 0) {
                            if (x == m - 1 && y == n - 1) {
                                return true;
                            }
                            vis[x][y] = true;
                            q2.emplace(x, y);
                        }
                    }
                }
            }
            return false;
        };
        int l = -1, r = m * n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == m * n ? 1e9 : l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumMinutes(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	fire := make([][]bool, m)
	vis := make([][]bool, m)
	dirs := [5]int{-1, 0, 1, 0, -1}
	for i := range fire {
		fire[i] = make([]bool, n)
		vis[i] = make([]bool, n)
	}
	l, r := -1, m*n
	spread := func(q [][2]int) [][2]int {
		nq := [][2]int{}
		for len(q) > 0 {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p[0]+dirs[k], p[1]+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] == 0 {
					fire[x][y] = true
					nq = append(nq, [2]int{x, y})
				}
			}
		}
		return nq
	}
	check := func(t int) bool {
		for i := range fire {
			for j := range fire[i] {
				fire[i][j] = false
				vis[i][j] = false
			}
		}
		q1 := [][2]int{}
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 1 {
					q1 = append(q1, [2]int{i, j})
					fire[i][j] = true
				}
			}
		}
		for ; t > 0 && len(q1) > 0; t-- {
			q1 = spread(q1)
		}
		q2 := [][2]int{{0, 0}}
		vis[0][0] = true
		for ; len(q2) > 0; q1 = spread(q1) {
			for d := len(q2); d > 0; d-- {
				p := q2[0]
				q2 = q2[1:]
				if fire[p[0]][p[1]] {
					continue
				}
				for k := 0; k < 4; k++ {
					x, y := p[0]+dirs[k], p[1]+dirs[k+1]
					if x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && !vis[x][y] && grid[x][y] == 0 {
						if x == m-1 && y == n-1 {
							return true
						}
						vis[x][y] = true
						q2 = append(q2, [2]int{x, y})
					}
				}
			}
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == m*n {
		return int(1e9)
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumMinutes(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const fire = Array.from({ length: m }, () => Array.from({ length: n }, () => false));
    const vis = Array.from({ length: m }, () => Array.from({ length: n }, () => false));
    const dirs: number[] = [-1, 0, 1, 0, -1];
    let [l, r] = [-1, m * n];
    const spread = (q: number[][]): number[][] => {
        const nq: number[][] = [];
        while (q.length) {
            const [i, j] = q.shift()!;
            for (let k = 0; k < 4; ++k) {
                const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] === 0) {
                    fire[x][y] = true;
                    nq.push([x, y]);
                }
            }
        }
        return nq;
    };
    const check = (t: number): boolean => {
        for (let i = 0; i < m; ++i) {
            fire[i].fill(false);
            vis[i].fill(false);
        }
        let q1: number[][] = [];
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                if (grid[i][j] === 1) {
                    q1.push([i, j]);
                    fire[i][j] = true;
                }
            }
        }
        for (; t && q1.length; --t) {
            q1 = spread(q1);
        }
        if (fire[0][0]) {
            return false;
        }
        const q2: number[][] = [[0, 0]];
        vis[0][0] = true;
        for (; q2.length; q1 = spread(q1)) {
            for (let d = q2.length; d; --d) {
                const [i, j] = q2.shift()!;
                if (fire[i][j]) {
                    continue;
                }
                for (let k = 0; k < 4; ++k) {
                    const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                    if (
                        x >= 0 &&
                        x < m &&
                        y >= 0 &&
                        y < n &&
                        !vis[x][y] &&
                        !fire[x][y] &&
                        grid[x][y] === 0
                    ) {
                        if (x === m - 1 && y === n - 1) {
                            return true;
                        }
                        vis[x][y] = true;
                        q2.push([x, y]);
                    }
                }
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l === m * n ? 1e9 : l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始大小为 <code>m x n</code>&nbsp;的二维整数数组&nbsp;<code>grid</code>&nbsp;，它表示一个网格图。每个格子为下面 3 个值之一：</p>

<ul>
	<li><code>0</code> 表示草地。</li>
	<li><code>1</code> 表示着火的格子。</li>
	<li><code>2</code>&nbsp;表示一座墙，你跟火都不能通过这个格子。</li>
</ul>

<p>一开始你在最左上角的格子&nbsp;<code>(0, 0)</code>&nbsp;，你想要到达最右下角的安全屋格子&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。每一分钟，你可以移动到&nbsp;<strong>相邻</strong>&nbsp;的草地格子。每次你移动 <strong>之后</strong>&nbsp;，着火的格子会扩散到所有不是墙的 <strong>相邻</strong>&nbsp;格子。</p>

<p>请你返回你在初始位置可以停留的 <strong>最多 </strong>分钟数，且停留完这段时间后你还能安全到达安全屋。如果无法实现，请你返回 <code>-1</code>&nbsp;。如果不管你在初始位置停留多久，你 <strong>总是</strong>&nbsp;能到达安全屋，请你返回&nbsp;<code>10<sup>9</sup></code>&nbsp;。</p>

<p>注意，如果你到达安全屋后，火马上到了安全屋，这视为你能够安全到达安全屋。</p>

<p>如果两个格子有共同边，那么它们为 <strong>相邻</strong>&nbsp;格子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2258.Escape%20the%20Spreading%20Fire/images/ex1new.jpg" style="width: 650px; height: 404px;"></p>

<pre><b>输入：</b>grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
<b>输出：</b>3
<b>解释：</b>上图展示了你在初始位置停留 3 分钟后的情形。
你仍然可以安全到达安全屋。
停留超过 3 分钟会让你无法安全到达安全屋。</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2258.Escape%20the%20Spreading%20Fire/images/ex2new2.jpg" style="width: 515px; height: 150px;"></p>

<pre><b>输入：</b>grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
<b>输出：</b>-1
<b>解释：</b>上图展示了你马上开始朝安全屋移动的情形。
火会蔓延到你可以移动的所有格子，所以无法安全到达安全屋。
所以返回 -1 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2200-2299/2258.Escape%20the%20Spreading%20Fire/images/ex3new.jpg" style="width: 174px; height: 150px;"></p>

<pre><b>输入：</b>grid = [[0,0,0],[2,2,0],[1,2,0]]
<b>输出：</b>1000000000
<b>解释：</b>上图展示了初始网格图。
注意，由于火被墙围了起来，所以无论如何你都能安全到达安全屋。
所以返回 10<sup>9</sup> 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 300</code></li>
	<li><code>4 &lt;= m * n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>grid[i][j]</code>&nbsp;是&nbsp;<code>0</code>&nbsp;，<code>1</code>&nbsp;或者&nbsp;<code>2</code>&nbsp;。</li>
	<li><code>grid[0][0] == grid[m - 1][n - 1] == 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找 + BFS

我们注意到，如果一个停留时间 $t$ 满足条件，那么所有小于 $t$ 的时间也都满足条件。因此我们可以考虑使用二分查找的方法找到最大的满足条件的时间。

我们定义二分查找的左边界 $l=-1$，右边界 $r = m \times n$。每一次二分查找，我们都将 $l$ 和 $r$ 的中点 $mid$ 作为当前的停留时间，判断是否满足条件。如果满足条件，那么我们将 $l$ 更新为 $mid$，否则我们将 $r$ 更新为 $mid-1$。最后，如果 $l = m \times n$，那么说明不存在满足条件的停留时间，我们返回 $10^9$，否则我们返回 $l$。

问题的关键转化为如何判断一个停留时间 $t$ 是否满足条件。我们可以使用广度优先搜索的方法，在 $t$ 时间内，模拟火的蔓延过程。如果停留 $t$ 时间后，火蔓延到了起点位置，那么说明不满足条件，提前返回。否则，我们这时候再使用广度优先搜索，每一次从当前位置向四个方向进行搜索，每一轮结束后，我们还需要将火向四个方向蔓延一次。如果在这个过程中，我们找到了一条从起点到终点的路径，那么说明满足条件。

时间复杂度 $O(m \times n \times \log (m \times n))$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为网格的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        def spread(q: Deque[int]) -> Deque[int]:
            nq = deque()
            while q:
                i, j = q.popleft()
                for a, b in pairwise(dirs):
                    x, y = i + a, j + b
                    if 0 <= x < m and 0 <= y < n and not fire[x][y] and grid[x][y] == 0:
                        fire[x][y] = True
                        nq.append((x, y))
            return nq

        def check(t: int) -> bool:
            for i in range(m):
                for j in range(n):
                    fire[i][j] = False
            q1 = deque()
            for i, row in enumerate(grid):
                for j, x in enumerate(row):
                    if x == 1:
                        fire[i][j] = True
                        q1.append((i, j))
            while t and q1:
                q1 = spread(q1)
                t -= 1
            if fire[0][0]:
                return False
            q2 = deque([(0, 0)])
            vis = [[False] * n for _ in range(m)]
            vis[0][0] = True
            while q2:
                for _ in range(len(q2)):
                    i, j = q2.popleft()
                    if fire[i][j]:
                        continue
                    for a, b in pairwise(dirs):
                        x, y = i + a, j + b
                        if (
                            0 <= x < m
                            and 0 <= y < n
                            and not vis[x][y]
                            and not fire[x][y]
                            and grid[x][y] == 0
                        ):
                            if x == m - 1 and y == n - 1:
                                return True
                            vis[x][y] = True
                            q2.append((x, y))
                q1 = spread(q1)
            return False

        m, n = len(grid), len(grid[0])
        l, r = -1, m * n
        dirs = (-1, 0, 1, 0, -1)
        fire = [[False] * n for _ in range(m)]
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return int(1e9) if l == m * n else l
```

#### Java

```java
class Solution {
    private int[][] grid;
    private boolean[][] fire;
    private boolean[][] vis;
    private final int[] dirs = {-1, 0, 1, 0, -1};
    private int m;
    private int n;

    public int maximumMinutes(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        this.grid = grid;
        fire = new boolean[m][n];
        vis = new boolean[m][n];
        int l = -1, r = m * n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == m * n ? 1000000000 : l;
    }

    private boolean check(int t) {
        for (int i = 0; i < m; ++i) {
            Arrays.fill(fire[i], false);
            Arrays.fill(vis[i], false);
        }
        Deque<int[]> q1 = new ArrayDeque<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q1.offer(new int[] {i, j});
                    fire[i][j] = true;
                }
            }
        }
        for (; t > 0 && !q1.isEmpty(); --t) {
            q1 = spread(q1);
        }
        if (fire[0][0]) {
            return false;
        }
        Deque<int[]> q2 = new ArrayDeque<>();
        q2.offer(new int[] {0, 0});
        vis[0][0] = true;
        for (; !q2.isEmpty(); q1 = spread(q1)) {
            for (int d = q2.size(); d > 0; --d) {
                int[] p = q2.poll();
                if (fire[p[0]][p[1]]) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && !vis[x][y]
                        && grid[x][y] == 0) {
                        if (x == m - 1 && y == n - 1) {
                            return true;
                        }
                        vis[x][y] = true;
                        q2.offer(new int[] {x, y});
                    }
                }
            }
        }
        return false;
    }

    private Deque<int[]> spread(Deque<int[]> q) {
        Deque<int[]> nq = new ArrayDeque<>();
        while (!q.isEmpty()) {
            int[] p = q.poll();
            for (int k = 0; k < 4; ++k) {
                int x = p[0] + dirs[k], y = p[1] + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] == 0) {
                    fire[x][y] = true;
                    nq.offer(new int[] {x, y});
                }
            }
        }
        return nq;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        bool vis[m][n];
        bool fire[m][n];
        int dirs[5] = {-1, 0, 1, 0, -1};
        auto spread = [&](queue<pair<int, int>>& q) {
            queue<pair<int, int>> nq;
            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int x = i + dirs[k], y = j + dirs[k + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] == 0) {
                        fire[x][y] = true;
                        nq.emplace(x, y);
                    }
                }
            }
            return nq;
        };
        auto check = [&](int t) {
            memset(vis, false, sizeof(vis));
            memset(fire, false, sizeof(fire));
            queue<pair<int, int>> q1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        q1.emplace(i, j);
                        fire[i][j] = true;
                    }
                }
            }
            for (; t && q1.size(); --t) {
                q1 = spread(q1);
            }
            if (fire[0][0]) {
                return false;
            }
            queue<pair<int, int>> q2;
            q2.emplace(0, 0);
            vis[0][0] = true;
            for (; q2.size(); q1 = spread(q1)) {
                for (int d = q2.size(); d; --d) {
                    auto [i, j] = q2.front();
                    q2.pop();
                    if (fire[i][j]) {
                        continue;
                    }
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k + 1];
                        if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && !fire[x][y] && grid[x][y] == 0) {
                            if (x == m - 1 && y == n - 1) {
                                return true;
                            }
                            vis[x][y] = true;
                            q2.emplace(x, y);
                        }
                    }
                }
            }
            return false;
        };
        int l = -1, r = m * n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l == m * n ? 1e9 : l;
    }
};
```

#### Go

```go
func maximumMinutes(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	fire := make([][]bool, m)
	vis := make([][]bool, m)
	dirs := [5]int{-1, 0, 1, 0, -1}
	for i := range fire {
		fire[i] = make([]bool, n)
		vis[i] = make([]bool, n)
	}
	l, r := -1, m*n
	spread := func(q [][2]int) [][2]int {
		nq := [][2]int{}
		for len(q) > 0 {
			p := q[0]
			q = q[1:]
			for k := 0; k < 4; k++ {
				x, y := p[0]+dirs[k], p[1]+dirs[k+1]
				if x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] == 0 {
					fire[x][y] = true
					nq = append(nq, [2]int{x, y})
				}
			}
		}
		return nq
	}
	check := func(t int) bool {
		for i := range fire {
			for j := range fire[i] {
				fire[i][j] = false
				vis[i][j] = false
			}
		}
		q1 := [][2]int{}
		for i := 0; i < m; i++ {
			for j := 0; j < n; j++ {
				if grid[i][j] == 1 {
					q1 = append(q1, [2]int{i, j})
					fire[i][j] = true
				}
			}
		}
		for ; t > 0 && len(q1) > 0; t-- {
			q1 = spread(q1)
		}
		q2 := [][2]int{{0, 0}}
		vis[0][0] = true
		for ; len(q2) > 0; q1 = spread(q1) {
			for d := len(q2); d > 0; d-- {
				p := q2[0]
				q2 = q2[1:]
				if fire[p[0]][p[1]] {
					continue
				}
				for k := 0; k < 4; k++ {
					x, y := p[0]+dirs[k], p[1]+dirs[k+1]
					if x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && !vis[x][y] && grid[x][y] == 0 {
						if x == m-1 && y == n-1 {
							return true
						}
						vis[x][y] = true
						q2 = append(q2, [2]int{x, y})
					}
				}
			}
		}
		return false
	}
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == m*n {
		return int(1e9)
	}
	return l
}
```

#### TypeScript

```ts
function maximumMinutes(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const fire = Array.from({ length: m }, () => Array.from({ length: n }, () => false));
    const vis = Array.from({ length: m }, () => Array.from({ length: n }, () => false));
    const dirs: number[] = [-1, 0, 1, 0, -1];
    let [l, r] = [-1, m * n];
    const spread = (q: number[][]): number[][] => {
        const nq: number[][] = [];
        while (q.length) {
            const [i, j] = q.shift()!;
            for (let k = 0; k < 4; ++k) {
                const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                if (x >= 0 && x < m && y >= 0 && y < n && !fire[x][y] && grid[x][y] === 0) {
                    fire[x][y] = true;
                    nq.push([x, y]);
                }
            }
        }
        return nq;
    };
    const check = (t: number): boolean => {
        for (let i = 0; i < m; ++i) {
            fire[i].fill(false);
            vis[i].fill(false);
        }
        let q1: number[][] = [];
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                if (grid[i][j] === 1) {
                    q1.push([i, j]);
                    fire[i][j] = true;
                }
            }
        }
        for (; t && q1.length; --t) {
            q1 = spread(q1);
        }
        if (fire[0][0]) {
            return false;
        }
        const q2: number[][] = [[0, 0]];
        vis[0][0] = true;
        for (; q2.length; q1 = spread(q1)) {
            for (let d = q2.length; d; --d) {
                const [i, j] = q2.shift()!;
                if (fire[i][j]) {
                    continue;
                }
                for (let k = 0; k < 4; ++k) {
                    const [x, y] = [i + dirs[k], j + dirs[k + 1]];
                    if (
                        x >= 0 &&
                        x < m &&
                        y >= 0 &&
                        y < n &&
                        !vis[x][y] &&
                        !fire[x][y] &&
                        grid[x][y] === 0
                    ) {
                        if (x === m - 1 && y === n - 1) {
                            return true;
                        }
                        vis[x][y] = true;
                        q2.push([x, y]);
                    }
                }
            }
        }
        return false;
    };
    while (l < r) {
        const mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l === m * n ? 1e9 : l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2259. 移除指定数字得到的最大结果](https://leetcode.cn/problems/remove-digit-from-number-to-maximize-result){#2259}

{{< tabs "2259" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        last = -1
        n = len(number)
        for i, d in enumerate(number):
            if d == digit:
                last = i
                if i + 1 < n and d < number[i + 1]:
                    break
        return number[:last] + number[last + 1 :]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String removeDigit(String number, char digit) {
        int last = -1;
        int n = number.length();
        for (int i = 0; i < n; ++i) {
            char d = number.charAt(i);
            if (d == digit) {
                last = i;
                if (i + 1 < n && d < number.charAt(i + 1)) {
                    break;
                }
            }
        }
        return number.substring(0, last) + number.substring(last + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int last = -1;
        for (int i = 0; i < n; ++i) {
            char d = number[i];
            if (d == digit) {
                last = i;
                if (i + 1 < n && number[i] < number[i + 1]) {
                    break;
                }
            }
        }
        return number.substr(0, last) + number.substr(last + 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeDigit(number string, digit byte) string {
	last := -1
	n := len(number)
	for i := range number {
		if number[i] == digit {
			last = i
			if i+1 < n && number[i] < number[i+1] {
				break
			}
		}
	}
	return number[:last] + number[last+1:]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeDigit(number: string, digit: string): string {
    const n = number.length;
    let last = -1;
    for (let i = 0; i < n; ++i) {
        if (number[i] === digit) {
            last = i;
            if (i + 1 < n && number[i] < number[i + 1]) {
                break;
            }
        }
    }
    return number.substring(0, last) + number.substring(last + 1);
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $number
     * @param String $digit
     * @return String
     */
    function removeDigit($number, $digit) {
        $max = 0;
        for ($i = 0; $i < strlen($number); $i++) {
            if ($number[$i] == $digit) {
                $tmp = substr($number, 0, $i) . substr($number, $i + 1);
                if ($tmp > $max) {
                    $max = $tmp;
                }
            }
        }
        return $max;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个表示某个正整数的字符串 <code>number</code> 和一个字符 <code>digit</code> 。</p>

<p>从 <code>number</code> 中 <strong>恰好</strong> 移除 <strong>一个</strong> 等于&nbsp;<code>digit</code> 的字符后，找出并返回按 <strong>十进制</strong> 表示 <strong>最大</strong> 的结果字符串。生成的测试用例满足 <code>digit</code> 在 <code>number</code> 中出现至少一次。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>number = "123", digit = '3'
<strong>输出：</strong>"12"
<strong>解释：</strong>"123" 中只有一个 '3' ，在移除 '3' 之后，结果为 "12" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>number = "1231", digit = '1'
<strong>输出：</strong>"231"
<strong>解释：</strong>可以移除第一个 '1' 得到 "231" 或者移除第二个 '1' 得到 "123" 。
由于 231 &gt; 123 ，返回 "231" 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>number = "551", digit = '5'
<strong>输出：</strong>"51"
<strong>解释：</strong>可以从 "551" 中移除第一个或者第二个 '5' 。
两种方案的结果都是 "51" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= number.length &lt;= 100</code></li>
	<li><code>number</code> 由数字 <code>'1'</code> 到 <code>'9'</code> 组成</li>
	<li><code>digit</code> 是 <code>'1'</code> 到 <code>'9'</code> 中的一个数字</li>
	<li><code>digit</code> 在 <code>number</code> 中出现至少一次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：暴力枚举

我们可以枚举字符串 $\textit{number}$ 的所有位置 $\textit{i}$，如果 $\textit{number}[i] = \textit{digit}$，那么我们取 $\textit{number}$ 的前缀 $\textit{number}[0:i]$ 和后缀 $\textit{number}[i+1:]$ 拼接起来，即为移除 $\textit{number}[i]$ 后的结果。我们取所有可能的结果中最大的即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{number}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        return max(
            number[:i] + number[i + 1 :] for i, d in enumerate(number) if d == digit
        )
```

#### Java

```java
class Solution {
    public String removeDigit(String number, char digit) {
        String ans = "0";
        for (int i = 0, n = number.length(); i < n; ++i) {
            char d = number.charAt(i);
            if (d == digit) {
                String t = number.substring(0, i) + number.substring(i + 1);
                if (ans.compareTo(t) < 0) {
                    ans = t;
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
    string removeDigit(string number, char digit) {
        string ans = "0";
        for (int i = 0, n = number.size(); i < n; ++i) {
            char d = number[i];
            if (d == digit) {
                string t = number.substr(0, i) + number.substr(i + 1, n - i);
                if (ans < t) {
                    ans = t;
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func removeDigit(number string, digit byte) string {
	ans := "0"
	for i, d := range number {
		if d == rune(digit) {
			t := number[:i] + number[i+1:]
			if strings.Compare(ans, t) < 0 {
				ans = t
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function removeDigit(number: string, digit: string): string {
    const n = number.length;
    let last = -1;
    for (let i = 0; i < n; ++i) {
        if (number[i] === digit) {
            last = i;
            if (i + 1 < n && number[i] < number[i + 1]) {
                break;
            }
        }
    }
    return number.substring(0, last) + number.substring(last + 1);
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $number
     * @param String $digit
     * @return String
     */
    function removeDigit($number, $digit) {
        $max = 0;
        for ($i = 0; $i < strlen($number); $i++) {
            if ($number[$i] == $digit) {
                $tmp = substr($number, 0, $i) . substr($number, $i + 1);
                if ($tmp > $max) {
                    $max = $tmp;
                }
            }
        }
        return $max;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：贪心

我们可以枚举字符串 $\textit{number}$ 的所有位置 $\textit{i}$，如果 $\textit{number}[i] = \textit{digit}$，记录 $\textit{digit}$ 最后一次出现的位置 $\textit{last}$，并且如果 $\textit{i} + 1 < \textit{n}$ 且 $\textit{number}[i] < \textit{number}[i + 1]$，那么我们可以直接返回 $\textit{number}[0:i] + \textit{number}[i+1:]$，即为移除 $\textit{number}[i]$ 后的结果。这是因为如果 $\textit{number}[i] < \textit{number}[i + 1]$，那么移除 $\textit{number}[i]$ 后，结果一定会更大。

遍历结束，我们返回 $\textit{number}[0:\textit{last}] + \textit{number}[\textit{last}+1:]$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{number}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        last = -1
        n = len(number)
        for i, d in enumerate(number):
            if d == digit:
                last = i
                if i + 1 < n and d < number[i + 1]:
                    break
        return number[:last] + number[last + 1 :]
```

#### Java

```java
class Solution {
    public String removeDigit(String number, char digit) {
        int last = -1;
        int n = number.length();
        for (int i = 0; i < n; ++i) {
            char d = number.charAt(i);
            if (d == digit) {
                last = i;
                if (i + 1 < n && d < number.charAt(i + 1)) {
                    break;
                }
            }
        }
        return number.substring(0, last) + number.substring(last + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int last = -1;
        for (int i = 0; i < n; ++i) {
            char d = number[i];
            if (d == digit) {
                last = i;
                if (i + 1 < n && number[i] < number[i + 1]) {
                    break;
                }
            }
        }
        return number.substr(0, last) + number.substr(last + 1);
    }
};
```

#### Go

```go
func removeDigit(number string, digit byte) string {
	last := -1
	n := len(number)
	for i := range number {
		if number[i] == digit {
			last = i
			if i+1 < n && number[i] < number[i+1] {
				break
			}
		}
	}
	return number[:last] + number[last+1:]
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
