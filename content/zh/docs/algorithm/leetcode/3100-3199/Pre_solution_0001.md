---
title: "3100_换水问题 II"
date: 2025-10-08T18:40:09+08:00
weight: 1
tags: [二分查找, 位运算, 几何, 分治, 前缀和, 哈希表, 图, 字符串, 并查集, 归并排序, 排序, 数学, 数据库, 数组, 有序集合, 树状数组, 模拟, 线段树, 贪心]
---

{{< markmap >}}
### [3100_换水问题 II](#3100)
#### [数学](#3100)
#### [模拟](#3100)
### [3101_交替子数组计数](#3101)
#### [数组](#3101)
#### [数学](#3101)
### [3102_最小化曼哈顿距离](#3102)
#### [几何](#3102)
#### [数组](#3102)
#### [数学](#3102)
#### [有序集合](#3102)
#### [排序](#3102)
### [3103_查找热门话题标签 II 🔒](#3103)
#### [数据库](#3103)
### [3104_查找最长的自包含子串 🔒](#3104)
#### [哈希表](#3104)
#### [字符串](#3104)
#### [二分查找](#3104)
#### [前缀和](#3104)
### [3105_最长的严格递增或递减子数组](#3105)
#### [数组](#3105)
### [3106_满足距离约束且字典序最小的字符串](#3106)
#### [贪心](#3106)
#### [字符串](#3106)
### [3107_使数组中位数等于 K 的最少操作数](#3107)
#### [贪心](#3107)
#### [数组](#3107)
#### [排序](#3107)
### [3108_带权图里旅途的最小代价](#3108)
#### [位运算](#3108)
#### [并查集](#3108)
#### [图](#3108)
#### [数组](#3108)
### [3109_查找排列的下标 🔒](#3109)
#### [树状数组](#3109)
#### [线段树](#3109)
#### [数组](#3109)
#### [二分查找](#3109)
#### [分治](#3109)
#### [有序集合](#3109)
#### [归并排序](#3109)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3100_换水问题 II
___
#### 数学
___
#### 模拟
---
### 3101_交替子数组计数
___
#### 数组
___
#### 数学
---
### 3102_最小化曼哈顿距离
___
#### 几何
___
#### 数组
___
#### 数学
___
#### 有序集合
___
#### 排序
---
### 3103_查找热门话题标签 II 🔒
___
#### 数据库
---
### 3104_查找最长的自包含子串 🔒
___
#### 哈希表
___
#### 字符串
___
#### 二分查找
___
#### 前缀和
---
### 3105_最长的严格递增或递减子数组
___
#### 数组
---
### 3106_满足距离约束且字典序最小的字符串
___
#### 贪心
___
#### 字符串
---
### 3107_使数组中位数等于 K 的最少操作数
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 3108_带权图里旅途的最小代价
___
#### 位运算
___
#### 并查集
___
#### 图
___
#### 数组
---
### 3109_查找排列的下标 🔒
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 几何 |
| 分治 | 前缀和 | 哈希表 |
| 图 | 字符串 | 并查集 |
| 归并排序 | 排序 | 数学 |
| 数据库 | 数组 | 有序集合 |
| 树状数组 | 模拟 | 线段树 |
| 贪心 |  |  |

# [3100. 换水问题 II](https://leetcode.cn/problems/water-bottles-ii){#3100}

{{< tabs "3100" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange:
            numBottles -= numExchange
            numExchange += 1
            ans += 1
            numBottles += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            ++numExchange;
            ++ans;
            ++numBottles;
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
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            ++numExchange;
            ++ans;
            ++numBottles;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxBottlesDrunk(numBottles int, numExchange int) int {
	ans := numBottles
	for numBottles >= numExchange {
		numBottles -= numExchange
		numExchange++
		ans++
		numBottles++
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxBottlesDrunk(numBottles: number, numExchange: number): number {
    let ans = numBottles;
    while (numBottles >= numExchange) {
        numBottles -= numExchange;
        ++numExchange;
        ++ans;
        ++numBottles;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_bottles_drunk(mut num_bottles: i32, mut num_exchange: i32) -> i32 {
        let mut ans = num_bottles;

        while num_bottles >= num_exchange {
            num_bottles -= num_exchange;
            num_exchange += 1;
            ans += 1;
            num_bottles += 1;
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

<p>给你两个整数 <code>numBottles</code> 和 <code>numExchange</code> 。</p>

<p><code>numBottles</code> 代表你最初拥有的满水瓶数量。在一次操作中，你可以执行以下操作之一：</p>

<ul>
	<li>喝掉任意数量的满水瓶，使它们变成空水瓶。</li>
	<li>用 <code>numExchange</code> 个空水瓶交换一个满水瓶。然后，将 <code>numExchange</code> 的值增加 1 。</li>
</ul>

<p>注意，你不能使用相同的 <code>numExchange</code> 值交换多批空水瓶。例如，如果 <code>numBottles == 3</code> 并且 <code>numExchange == 1</code> ，则不能用 <code>3</code> 个空水瓶交换成 <code>3</code> 个满水瓶。</p>

<p>返回你 <strong>最多</strong> 可以喝到多少瓶水。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3100.Water%20Bottles%20II/images/exampleone1.png" style="width: 948px; height: 482px; padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>numBottles = 13, numExchange = 6
<strong>输出：</strong>15
<strong>解释：</strong>上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶数量。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3100.Water%20Bottles%20II/images/example231.png" style="width: 990px; height: 642px; padding: 10px; background: #fff; border-radius: .5rem;" />
<pre>
<strong>输入：</strong>numBottles = 10, numExchange = 3
<strong>输出：</strong>13
<strong>解释：</strong>上表显示了满水瓶的数量、空水瓶的数量、numExchange 的值，以及累计喝掉的水瓶数量。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= numBottles &lt;= 100 </code></li>
	<li><code>1 &lt;= numExchange &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以在一开始就喝掉所有的满水瓶，因此初始时我们喝到的水数量为 `numBottles`。然后我们不断地进行以下操作：

-   如果当前有 `numExchange` 个空水瓶，我们就可以用它们换一瓶满水瓶，换完后，`numExchange` 的值增加 1。然后，我们喝掉这瓶水，喝到的水数量增加 $1$，空水瓶数量增加 $1$。
-   如果当前没有 `numExchange` 个空水瓶，那么我们就不能再换水了，此时我们就可以停止操作。

我们不断地进行上述操作，直到我们无法再换水为止。最终我们喝到的水的数量就是答案。

时间复杂度 $O(\sqrt{numBottles})$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        ans = numBottles
        while numBottles >= numExchange:
            numBottles -= numExchange
            numExchange += 1
            ans += 1
            numBottles += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            ++numExchange;
            ++ans;
            ++numBottles;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            ++numExchange;
            ++ans;
            ++numBottles;
        }
        return ans;
    }
};
```

#### Go

```go
func maxBottlesDrunk(numBottles int, numExchange int) int {
	ans := numBottles
	for numBottles >= numExchange {
		numBottles -= numExchange
		numExchange++
		ans++
		numBottles++
	}
	return ans
}
```

#### TypeScript

```ts
function maxBottlesDrunk(numBottles: number, numExchange: number): number {
    let ans = numBottles;
    while (numBottles >= numExchange) {
        numBottles -= numExchange;
        ++numExchange;
        ++ans;
        ++numBottles;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_bottles_drunk(mut num_bottles: i32, mut num_exchange: i32) -> i32 {
        let mut ans = num_bottles;

        while num_bottles >= num_exchange {
            num_bottles -= num_exchange;
            num_exchange += 1;
            ans += 1;
            num_bottles += 1;
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

# [3101. 交替子数组计数](https://leetcode.cn/problems/count-alternating-subarrays){#3101}

{{< tabs "3101" >}}

{{% tab "python" %}}
```python
class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        ans = s = 1
        for a, b in pairwise(nums):
            s = s + 1 if a != b else 1
            ans += s
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long ans = 1, s = 1;
        for (int i = 1; i < nums.length; ++i) {
            s = nums[i] != nums[i - 1] ? s + 1 : 1;
            ans += s;
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
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 1, s = 1;
        for (int i = 1; i < nums.size(); ++i) {
            s = nums[i] != nums[i - 1] ? s + 1 : 1;
            ans += s;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countAlternatingSubarrays(nums []int) int64 {
	ans, s := int64(1), int64(1)
	for i, x := range nums[1:] {
		if x != nums[i] {
			s++
		} else {
			s = 1
		}
		ans += s
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countAlternatingSubarrays(nums: number[]): number {
    let [ans, s] = [1, 1];
    for (let i = 1; i < nums.length; ++i) {
        s = nums[i] !== nums[i - 1] ? s + 1 : 1;
        ans += s;
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

<p>给你一个<span data-keyword="binary-array">二进制数组 </span><code>nums</code> 。</p>

<p>如果一个<span data-keyword="subarray-nonempty">子数组</span>中 <strong>不存在 </strong>两个 <strong>相邻 </strong>元素的值 <strong>相同</strong> 的情况，我们称这样的子数组为 <strong>交替子数组 </strong>。</p>

<p>返回数组 <code>nums</code> 中交替子数组的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,1,1,1]</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>
<!-- 解释示例1的交替子数组 -->

<p>以下子数组是交替子数组：<code>[0]</code> 、<code>[1]</code> 、<code>[1]</code> 、<code>[1]</code> 以及 <code>[0,1]</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [1,0,1,0]</span></p>

<p><strong>输出：</strong> <span class="example-io">10</span></p>

<p><strong>解释：</strong></p>
<!-- 解释示例2的交替子数组 -->

<p>数组的每个子数组都是交替子数组。可以统计在内的子数组共有 10 个。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 不是 <code>0</code> 就是 <code>1</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举以每个位置结尾的子数组，计算满足条件的子数组的数量，累加所有位置的满足条件的子数组的数量即可。

具体地，我们定义变量 $s$ 表示以元素 $nums[i]$ 结尾的满足条件的子数组的数量，初始时我们将 $s$ 置为 $1$，表示以第一个元素结尾的满足条件的子数组的数量为 $1$。

接下来，我们从第二个元素开始遍历数组，对于每个位置 $i$，我们根据 $nums[i]$ 和 $nums[i-1]$ 的关系更新 $s$ 的值：

-   如果 $nums[i] \neq nums[i-1]$，则 $s$ 的值增加 $1$，即 $s = s + 1$；
-   如果 $nums[i] = nums[i-1]$，则 $s$ 的值重置为 $1$，即 $s = 1$。

然后，我们将 $s$ 的值累加到答案中，继续遍历数组的下一个位置，直到遍历完整个数组。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        ans = s = 1
        for a, b in pairwise(nums):
            s = s + 1 if a != b else 1
            ans += s
        return ans
```

#### Java

```java
class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        long ans = 1, s = 1;
        for (int i = 1; i < nums.length; ++i) {
            s = nums[i] != nums[i - 1] ? s + 1 : 1;
            ans += s;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 1, s = 1;
        for (int i = 1; i < nums.size(); ++i) {
            s = nums[i] != nums[i - 1] ? s + 1 : 1;
            ans += s;
        }
        return ans;
    }
};
```

#### Go

```go
func countAlternatingSubarrays(nums []int) int64 {
	ans, s := int64(1), int64(1)
	for i, x := range nums[1:] {
		if x != nums[i] {
			s++
		} else {
			s = 1
		}
		ans += s
	}
	return ans
}
```

#### TypeScript

```ts
function countAlternatingSubarrays(nums: number[]): number {
    let [ans, s] = [1, 1];
    for (let i = 1; i < nums.length; ++i) {
        s = nums[i] !== nums[i - 1] ? s + 1 : 1;
        ans += s;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3102. 最小化曼哈顿距离](https://leetcode.cn/problems/minimize-manhattan-distances){#3102}

{{< tabs "3102" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        sl1 = SortedList()
        sl2 = SortedList()
        for x, y in points:
            sl1.add(x + y)
            sl2.add(x - y)
        ans = inf
        for x, y in points:
            sl1.remove(x + y)
            sl2.remove(x - y)
            ans = min(ans, max(sl1[-1] - sl1[0], sl2[-1] - sl2[0]))
            sl1.add(x + y)
            sl2.add(x - y)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumDistance(int[][] points) {
        TreeMap<Integer, Integer> tm1 = new TreeMap<>();
        TreeMap<Integer, Integer> tm2 = new TreeMap<>();
        for (int[] p : points) {
            int x = p[0], y = p[1];
            tm1.merge(x + y, 1, Integer::sum);
            tm2.merge(x - y, 1, Integer::sum);
        }
        int ans = Integer.MAX_VALUE;
        for (int[] p : points) {
            int x = p[0], y = p[1];
            if (tm1.merge(x + y, -1, Integer::sum) == 0) {
                tm1.remove(x + y);
            }
            if (tm2.merge(x - y, -1, Integer::sum) == 0) {
                tm2.remove(x - y);
            }
            ans = Math.min(
                ans, Math.max(tm1.lastKey() - tm1.firstKey(), tm2.lastKey() - tm2.firstKey()));
            tm1.merge(x + y, 1, Integer::sum);
            tm2.merge(x - y, 1, Integer::sum);
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
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> st1;
        multiset<int> st2;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            st1.insert(x + y);
            st2.insert(x - y);
        }
        int ans = INT_MAX;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            st1.erase(st1.find(x + y));
            st2.erase(st2.find(x - y));
            ans = min(ans, max(*st1.rbegin() - *st1.begin(), *st2.rbegin() - *st2.begin()));
            st1.insert(x + y);
            st2.insert(x - y);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumDistance(points [][]int) int {
	st1 := redblacktree.New[int, int]()
	st2 := redblacktree.New[int, int]()
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}
	for _, p := range points {
		x, y := p[0], p[1]
		merge(st1, x+y, 1)
		merge(st2, x-y, 1)
	}
	ans := math.MaxInt
	for _, p := range points {
		x, y := p[0], p[1]
		merge(st1, x+y, -1)
		merge(st2, x-y, -1)
		ans = min(ans, max(st1.Right().Key-st1.Left().Key, st2.Right().Key-st2.Left().Key))
		merge(st1, x+y, 1)
		merge(st2, x-y, 1)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumDistance(points: number[][]): number {
    const st1 = new TreapMultiSet<number>();
    const st2 = new TreapMultiSet<number>();
    for (const [x, y] of points) {
        st1.add(x + y);
        st2.add(x - y);
    }
    let ans = Infinity;
    for (const [x, y] of points) {
        st1.delete(x + y);
        st2.delete(x - y);
        ans = Math.min(ans, Math.max(st1.last() - st1.first(), st2.last() - st2.first()));
        st1.add(x + y);
        st2.add(x - y);
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的数组 <code>points</code> ，它表示二维平面上一些点的整数坐标，其中 <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> 。</p>

<p>两点之间的距离定义为它们的<span data-keyword="manhattan-distance">曼哈顿距离</span>。</p>

<p>请你恰好移除一个点，返回移除后任意两点之间的 <strong>最大 </strong>距离可能的 <strong>最小 </strong>值。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>points = [[3,10],[5,15],[10,2],[4,4]]
<strong>输出：</strong>12
<strong>解释：</strong>移除每个点后的最大距离如下所示：
- 移除第 0 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间，为 |5 - 10| + |15 - 2| = 18 。
- 移除第 1 个点后，最大距离在点 (3, 10) 和 (10, 2) 之间，为 |3 - 10| + |10 - 2| = 15 。
- 移除第 2 个点后，最大距离在点 (5, 15) 和 (4, 4) 之间，为 |5 - 4| + |15 - 4| = 12 。
- 移除第 3 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间的，为 |5 - 10| + |15 - 2| = 18 。
在恰好移除一个点后，任意两点之间的最大距离可能的最小值是 12 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>points = [[1,1],[1,1],[1,1]]
<strong>输出：</strong>0
<strong>解释：</strong>移除任一点后，任意两点之间的最大距离都是 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= points.length &lt;= 10<sup>5</sup></code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>1 &lt;= points[i][0], points[i][1] &lt;= 10<sup>8</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：有序集合

对于两个点 $(x_1, y_1)$ 和 $(x_2, y_2)$，它们的曼哈顿距离为 $|x_1 - x_2| + |y_1 - y_2|$。我们可以将其转化为 $\max(x_1 - x_2, x_2 - x_1) + \max(y_1 - y_2, y_2 - y_1)$，即：

$$
|x_1 - x_2| + |y_1 - y_2| = \max \begin{cases}
x_1 - x_2 + y_1 - y_2 \\
x_2 - x_1 + y_2 - y_1 \\
x_1 - x_2 + y_2 - y_1 \\
x_2 - x_1 + y_1 - y_2
\end{cases}
$$

整理可得：

$$
|x_1 - x_2| + |y_1 - y_2| = \max \begin{cases}
(x_1 + y_1) - (x_2 + y_2) \\
(x_2 + y_2) - (x_1 + y_1) \\
(x_1 - y_1) - (x_2 - y_2) \\
(x_2 - y_2) - (x_1 - y_1)
\end{cases}
$$

其中，前两项可以表示为 $\max(\max(x_1 + y_1, x_2 + y_2) - \min(x_1 + y_1, x_2 + y_2))$，后两项可以表示为 $\max(\max(x_1 - y_1, x_2 - y_2) - \min(x_1 - y_1, x_2 - y_2))$。

因此，我们可以将所有点按照 $x + y$ 和 $x - y$ 的值分别存入两个有序集合中，然后枚举每个点，移除该点后，更新有序集合中的值，计算最大值和最小值的差值，取最小值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为点的个数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        sl1 = SortedList()
        sl2 = SortedList()
        for x, y in points:
            sl1.add(x + y)
            sl2.add(x - y)
        ans = inf
        for x, y in points:
            sl1.remove(x + y)
            sl2.remove(x - y)
            ans = min(ans, max(sl1[-1] - sl1[0], sl2[-1] - sl2[0]))
            sl1.add(x + y)
            sl2.add(x - y)
        return ans
```

#### Java

```java
class Solution {
    public int minimumDistance(int[][] points) {
        TreeMap<Integer, Integer> tm1 = new TreeMap<>();
        TreeMap<Integer, Integer> tm2 = new TreeMap<>();
        for (int[] p : points) {
            int x = p[0], y = p[1];
            tm1.merge(x + y, 1, Integer::sum);
            tm2.merge(x - y, 1, Integer::sum);
        }
        int ans = Integer.MAX_VALUE;
        for (int[] p : points) {
            int x = p[0], y = p[1];
            if (tm1.merge(x + y, -1, Integer::sum) == 0) {
                tm1.remove(x + y);
            }
            if (tm2.merge(x - y, -1, Integer::sum) == 0) {
                tm2.remove(x - y);
            }
            ans = Math.min(
                ans, Math.max(tm1.lastKey() - tm1.firstKey(), tm2.lastKey() - tm2.firstKey()));
            tm1.merge(x + y, 1, Integer::sum);
            tm2.merge(x - y, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> st1;
        multiset<int> st2;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            st1.insert(x + y);
            st2.insert(x - y);
        }
        int ans = INT_MAX;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            st1.erase(st1.find(x + y));
            st2.erase(st2.find(x - y));
            ans = min(ans, max(*st1.rbegin() - *st1.begin(), *st2.rbegin() - *st2.begin()));
            st1.insert(x + y);
            st2.insert(x - y);
        }
        return ans;
    }
};
```

#### Go

```go
func minimumDistance(points [][]int) int {
	st1 := redblacktree.New[int, int]()
	st2 := redblacktree.New[int, int]()
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}
	for _, p := range points {
		x, y := p[0], p[1]
		merge(st1, x+y, 1)
		merge(st2, x-y, 1)
	}
	ans := math.MaxInt
	for _, p := range points {
		x, y := p[0], p[1]
		merge(st1, x+y, -1)
		merge(st2, x-y, -1)
		ans = min(ans, max(st1.Right().Key-st1.Left().Key, st2.Right().Key-st2.Left().Key))
		merge(st1, x+y, 1)
		merge(st2, x-y, 1)
	}
	return ans
}
```

#### TypeScript

```ts
function minimumDistance(points: number[][]): number {
    const st1 = new TreapMultiSet<number>();
    const st2 = new TreapMultiSet<number>();
    for (const [x, y] of points) {
        st1.add(x + y);
        st2.add(x - y);
    }
    let ans = Infinity;
    for (const [x, y] of points) {
        st1.delete(x + y);
        st2.delete(x - y);
        ans = Math.min(ans, Math.max(st1.last() - st1.first(), st2.last() - st2.first()));
        st1.add(x + y);
        st2.add(x - y);
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3103. 查找热门话题标签 II 🔒](https://leetcode.cn/problems/find-trending-hashtags-ii){#3103}

{{< tabs "3103" >}}

{{% tab "python" %}}
```python
import pandas as pd


def find_trending_hashtags(tweets: pd.DataFrame) -> pd.DataFrame:
    # Filter tweets for February 2024
    tweets_feb_2024 = tweets[tweets["tweet_date"].between("2024-02-01", "2024-02-29")]

    # Extract hashtags from tweets
    hashtags = tweets_feb_2024["tweet"].str.findall(r"#\w+")

    # Flatten list of hashtags
    all_hashtags = [tag for sublist in hashtags for tag in sublist]

    # Count occurrences of each hashtag
    hashtag_counts = pd.Series(all_hashtags).value_counts().reset_index()
    hashtag_counts.columns = ["hashtag", "count"]

    # Sort by count of hashtag in descending order
    hashtag_counts = hashtag_counts.sort_values(
        by=["count", "hashtag"], ascending=[False, False]
    )

    # Get top 3 trending hashtags
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
题目保证所有 tweet_date 都是 2024 年 2 月的合法日期。</pre>

<p>编写一个解决方案来找到&nbsp;<code>2024</code>&nbsp;年 <strong>二月&nbsp;</strong>的 <strong>前</strong>&nbsp;<code>3</code>&nbsp;热门话题 <strong>标签</strong>。一条推文可能含有 <strong>多个标签</strong>。</p>

<p>返回结果表，根据标签的数量和名称&nbsp;<strong>降序</strong> 排序。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong></p>

<p>Tweets 表：</p>

<pre class="example-io">
+---------+----------+------------------------------------------------------------+------------+
| user_id | tweet_id | tweet                                                      | tweet_date |
+---------+----------+------------------------------------------------------------+------------+
| 135     | 13       | Enjoying a great start to the day. #HappyDay #MorningVibes | 2024-02-01 |
| 136     | 14       | Another #HappyDay with good vibes! #FeelGood               | 2024-02-03 |
| 137     | 15       | Productivity peaks! #WorkLife #ProductiveDay               | 2024-02-04 |
| 138     | 16       | Exploring new tech frontiers. #TechLife #Innovation        | 2024-02-04 |
| 139     | 17       | Gratitude for today's moments. #HappyDay #Thankful         | 2024-02-05 |
| 140     | 18       | Innovation drives us. #TechLife #FutureTech                | 2024-02-07 |
| 141     | 19       | Connecting with nature's serenity. #Nature #Peaceful       | 2024-02-09 |
+---------+----------+------------------------------------------------------------+------------+
 </pre>

<p><strong>输出：</strong></p>

<pre class="example-io">
+-----------+-------+
| hashtag   | count |
+-----------+-------+
| #HappyDay | 3     |
| #TechLife | 2     |
| #WorkLife | 1     |
+-----------+-------+

</pre>

<p><strong>解释：</strong></p>

<ul>
	<li><strong>#HappyDay：</strong>在 ID 为 13，14，17 的推文中出现，总共提及&nbsp;3 次。</li>
	<li><strong>#TechLife：</strong>在 ID 为 16，18 的推文中出现，总共提及 2&nbsp;次。</li>
	<li><strong>#WorkLife：</strong>在 ID 为 15 的推文中出现，总共提及 1&nbsp;次。</li>
</ul>

<p><b>注意：</b>输出表分别按 count 和 hashtag 降序排序。</p>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：正则匹配

我们可以使用正则表达式来匹配每条推文中的所有标签，然后统计每个标签的出现次数。最后，我们可以按标签出现的次数降序排序，如果出现次数相同，则按标签名称降序排序，返回前三个标签。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def find_trending_hashtags(tweets: pd.DataFrame) -> pd.DataFrame:
    # Filter tweets for February 2024
    tweets_feb_2024 = tweets[tweets["tweet_date"].between("2024-02-01", "2024-02-29")]

    # Extract hashtags from tweets
    hashtags = tweets_feb_2024["tweet"].str.findall(r"#\w+")

    # Flatten list of hashtags
    all_hashtags = [tag for sublist in hashtags for tag in sublist]

    # Count occurrences of each hashtag
    hashtag_counts = pd.Series(all_hashtags).value_counts().reset_index()
    hashtag_counts.columns = ["hashtag", "count"]

    # Sort by count of hashtag in descending order
    hashtag_counts = hashtag_counts.sort_values(
        by=["count", "hashtag"], ascending=[False, False]
    )

    # Get top 3 trending hashtags
    top_3_hashtags = hashtag_counts.head(3)

    return top_3_hashtags
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3104. 查找最长的自包含子串 🔒](https://leetcode.cn/problems/find-longest-self-contained-substring){#3104}

{{< tabs "3104" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubstringLength(self, s: str) -> int:
        first, last = {}, {}
        for i, c in enumerate(s):
            if c not in first:
                first[c] = i
            last[c] = i
        ans, n = -1, len(s)
        for c, i in first.items():
            mx = last[c]
            for j in range(i, n):
                a, b = first[s[j]], last[s[j]]
                if a < i:
                    break
                mx = max(mx, b)
                if mx == j and j - i + 1 < n:
                    ans = max(ans, j - i + 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubstringLength(String s) {
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int j = s.charAt(i) - 'a';
            if (first[j] == -1) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = -1;
        for (int k = 0; k < 26; ++k) {
            int i = first[k];
            if (i == -1) {
                continue;
            }
            int mx = last[k];
            for (int j = i; j < n; ++j) {
                int a = first[s.charAt(j) - 'a'];
                int b = last[s.charAt(j) - 'a'];
                if (a < i) {
                    break;
                }
                mx = Math.max(mx, b);
                if (mx == j && j - i + 1 < n) {
                    ans = Math.max(ans, j - i + 1);
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
    int maxSubstringLength(string s) {
        vector<int> first(26, -1);
        vector<int> last(26);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            if (first[j] == -1) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = -1;
        for (int k = 0; k < 26; ++k) {
            int i = first[k];
            if (i == -1) {
                continue;
            }
            int mx = last[k];
            for (int j = i; j < n; ++j) {
                int a = first[s[j] - 'a'];
                int b = last[s[j] - 'a'];
                if (a < i) {
                    break;
                }
                mx = max(mx, b);
                if (mx == j && j - i + 1 < n) {
                    ans = max(ans, j - i + 1);
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
func maxSubstringLength(s string) int {
	first := [26]int{}
	last := [26]int{}
	for i := range first {
		first[i] = -1
	}
	n := len(s)
	for i, c := range s {
		j := int(c - 'a')
		if first[j] == -1 {
			first[j] = i
		}
		last[j] = i
	}
	ans := -1
	for k := 0; k < 26; k++ {
		i := first[k]
		if i == -1 {
			continue
		}
		mx := last[k]
		for j := i; j < n; j++ {
			a, b := first[s[j]-'a'], last[s[j]-'a']
			if a < i {
				break
			}
			mx = max(mx, b)
			if mx == j && j-i+1 < n {
				ans = max(ans, j-i+1)
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubstringLength(s: string): number {
    const first: number[] = Array(26).fill(-1);
    const last: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        const j = s.charCodeAt(i) - 97;
        if (first[j] === -1) {
            first[j] = i;
        }
        last[j] = i;
    }
    let ans = -1;
    for (let k = 0; k < 26; ++k) {
        const i = first[k];
        if (i === -1) {
            continue;
        }
        let mx = last[k];
        for (let j = i; j < n; ++j) {
            const a = first[s.charCodeAt(j) - 97];
            if (a < i) {
                break;
            }
            const b = last[s.charCodeAt(j) - 97];
            mx = Math.max(mx, b);
            if (mx === j && j - i + 1 < n) {
                ans = Math.max(ans, j - i + 1);
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

<p>给定字符串&nbsp;<code>s</code>，你需要找到&nbsp;<code>s</code>&nbsp;的 <strong>最长自包含</strong>&nbsp;<span data-keyword="substring-nonempty">子串</span>&nbsp;的长度。</p>

<p>如果 <code>s</code>&nbsp;的一个子串 <code>t</code>&nbsp;满足&nbsp;<code>t != s</code>&nbsp;且&nbsp;<code>t</code>&nbsp;中的每一个字符在&nbsp;<code>s</code>&nbsp;的剩余部分都不存在，则被称为是 <strong>自包含</strong>&nbsp;的。</p>

<p>如果存在&nbsp;&nbsp;<code>s</code>&nbsp;的最长自包含子串，返回它的长度，否则返回 -1。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "abba"</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong><br />
让我们检查子串&nbsp;<code>"bb"</code>。你可以发现子串外没有其它&nbsp;<code>"b"</code>。因此答案为 2。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">s = "abab"</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">-1</span></p>

<p><strong>解释：</strong><br />
我们选择的每一个子串都不满足描述的特点（子串内外包含有一些字母）。所以答案是&nbsp;-1。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">s = "abacd"</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">4</span></p>

<p><strong>解释：</strong><br />
让我们检查子串&nbsp;<code>"<span class="example-io">abac</span>"</code>。子串之外只有一个字母&nbsp;<code>"d"</code>。子串内没有&nbsp;<code>"d"</code>，所以它满足条件并且答案为 4。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们注意到，满足条件的子串的开头一定是某个字符第一次出现的位置。

因此，我们可以用两个数组或哈希表 `first` 和 `last` 分别记录每个字符第一次和最后一次出现的位置。

接下来，我们枚举每个字符 `c`，假设 `c` 第一次出现的位置是 $i$，最后一次出现的位置是 $mx$，那么我们可以从 $i$ 开始向后遍历，对于每个位置 $j$，我们找到 $s[j]$ 第一次出现的位置 $a$ 和最后一次出现的位置 $b$，如果 $a < i$，说明 $s[j]$ 在 $c$ 的左边，不符合枚举条件，我们可以直接退出循环。否则，我们更新 $mx = \max(mx, b)$。如果 $mx = j$ 且 $j - i + 1 < n$，我们更新答案为 $ans = \max(ans, j - i + 1)$。

最后返回答案即可。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(|\Sigma|)$。其中 $n$ 是字符串 $s$ 的长度；而 $|\Sigma|$ 是字符集的大小，本题中字符集为小写字母，所以 $|\Sigma| = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubstringLength(self, s: str) -> int:
        first, last = {}, {}
        for i, c in enumerate(s):
            if c not in first:
                first[c] = i
            last[c] = i
        ans, n = -1, len(s)
        for c, i in first.items():
            mx = last[c]
            for j in range(i, n):
                a, b = first[s[j]], last[s[j]]
                if a < i:
                    break
                mx = max(mx, b)
                if mx == j and j - i + 1 < n:
                    ans = max(ans, j - i + 1)
        return ans
```

#### Java

```java
class Solution {
    public int maxSubstringLength(String s) {
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int j = s.charAt(i) - 'a';
            if (first[j] == -1) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = -1;
        for (int k = 0; k < 26; ++k) {
            int i = first[k];
            if (i == -1) {
                continue;
            }
            int mx = last[k];
            for (int j = i; j < n; ++j) {
                int a = first[s.charAt(j) - 'a'];
                int b = last[s.charAt(j) - 'a'];
                if (a < i) {
                    break;
                }
                mx = Math.max(mx, b);
                if (mx == j && j - i + 1 < n) {
                    ans = Math.max(ans, j - i + 1);
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
    int maxSubstringLength(string s) {
        vector<int> first(26, -1);
        vector<int> last(26);
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int j = s[i] - 'a';
            if (first[j] == -1) {
                first[j] = i;
            }
            last[j] = i;
        }
        int ans = -1;
        for (int k = 0; k < 26; ++k) {
            int i = first[k];
            if (i == -1) {
                continue;
            }
            int mx = last[k];
            for (int j = i; j < n; ++j) {
                int a = first[s[j] - 'a'];
                int b = last[s[j] - 'a'];
                if (a < i) {
                    break;
                }
                mx = max(mx, b);
                if (mx == j && j - i + 1 < n) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSubstringLength(s string) int {
	first := [26]int{}
	last := [26]int{}
	for i := range first {
		first[i] = -1
	}
	n := len(s)
	for i, c := range s {
		j := int(c - 'a')
		if first[j] == -1 {
			first[j] = i
		}
		last[j] = i
	}
	ans := -1
	for k := 0; k < 26; k++ {
		i := first[k]
		if i == -1 {
			continue
		}
		mx := last[k]
		for j := i; j < n; j++ {
			a, b := first[s[j]-'a'], last[s[j]-'a']
			if a < i {
				break
			}
			mx = max(mx, b)
			if mx == j && j-i+1 < n {
				ans = max(ans, j-i+1)
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxSubstringLength(s: string): number {
    const first: number[] = Array(26).fill(-1);
    const last: number[] = Array(26).fill(0);
    const n = s.length;
    for (let i = 0; i < n; ++i) {
        const j = s.charCodeAt(i) - 97;
        if (first[j] === -1) {
            first[j] = i;
        }
        last[j] = i;
    }
    let ans = -1;
    for (let k = 0; k < 26; ++k) {
        const i = first[k];
        if (i === -1) {
            continue;
        }
        let mx = last[k];
        for (let j = i; j < n; ++j) {
            const a = first[s.charCodeAt(j) - 97];
            if (a < i) {
                break;
            }
            const b = last[s.charCodeAt(j) - 97];
            mx = Math.max(mx, b);
            if (mx === j && j - i + 1 < n) {
                ans = Math.max(ans, j - i + 1);
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

# [3105. 最长的严格递增或递减子数组](https://leetcode.cn/problems/longest-strictly-increasing-or-strictly-decreasing-subarray){#3105}

{{< tabs "3105" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans = t = 1
        for i, x in enumerate(nums[1:]):
            if nums[i] < x:
                t += 1
                ans = max(ans, t)
            else:
                t = 1
        t = 1
        for i, x in enumerate(nums[1:]):
            if nums[i] > x:
                t += 1
                ans = max(ans, t)
            else:
                t = 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int ans = 1;
        for (int i = 1, t = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
            }
        }
        for (int i = 1, t = 1; i < nums.length; ++i) {
            if (nums[i - 1] > nums[i]) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
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
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        for (int i = 1, t = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = max(ans, ++t);
            } else {
                t = 1;
            }
        }
        for (int i = 1, t = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                ans = max(ans, ++t);
            } else {
                t = 1;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestMonotonicSubarray(nums []int) int {
	ans := 1
	t := 1
	for i, x := range nums[1:] {
		if nums[i] < x {
			t++
			ans = max(ans, t)
		} else {
			t = 1
		}
	}
	t = 1
	for i, x := range nums[1:] {
		if nums[i] > x {
			t++
			ans = max(ans, t)
		} else {
			t = 1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestMonotonicSubarray(nums: number[]): number {
    const n = nums.length;
    let ans = 1;

    for (let i = 1, t1 = 1, t2 = 1; i < n; i++) {
        t1 = nums[i] > nums[i - 1] ? t1 + 1 : 1;
        t2 = nums[i] < nums[i - 1] ? t2 + 1 : 1;
        ans = Math.max(ans, t1, t2);
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function longestMonotonicSubarray(nums) {
    const n = nums.length;
    let ans = 1;

    for (let i = 1, t1 = 1, t2 = 1; i < n; i++) {
        t1 = nums[i] > nums[i - 1] ? t1 + 1 : 1;
        t2 = nums[i] < nums[i - 1] ? t2 + 1 : 1;
        ans = Math.max(ans, t1, t2);
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

<p>给你一个整数数组 <code>nums</code> 。</p>

<p>返回数组 <code>nums</code> 中 <strong><span data-keyword="strictly-increasing-array">严格递增</span></strong> 或 <strong><span data-keyword="strictly-decreasing-array">严格递减</span> </strong>的最长非空子数组的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,4,3,3,2]</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 中严格递增的子数组有<code>[1]</code>、<code>[2]</code>、<code>[3]</code>、<code>[3]</code>、<code>[4]</code> 以及 <code>[1,4]</code> 。</p>

<p><code>nums</code> 中严格递减的子数组有<code>[1]</code>、<code>[2]</code>、<code>[3]</code>、<code>[3]</code>、<code>[4]</code>、<code>[3,2]</code> 以及 <code>[4,3]</code> 。</p>

<p>因此，返回 <code>2</code> 。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,3,3,3]</span></p>

<p><strong>输出：</strong><span class="example-io">1</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 中严格递增的子数组有 <code>[3]</code>、<code>[3]</code>、<code>[3]</code> 以及 <code>[3]</code> 。</p>

<p><code>nums</code> 中严格递减的子数组有 <code>[3]</code>、<code>[3]</code>、<code>[3]</code> 以及 <code>[3]</code> 。</p>

<p>因此，返回 <code>1</code> 。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [3,2,1]</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p><code>nums</code> 中严格递增的子数组有 <code>[3]</code>、<code>[2]</code> 以及 <code>[1]</code> 。</p>

<p><code>nums</code> 中严格递减的子数组有 <code>[3]</code>、<code>[2]</code>、<code>[1]</code>、<code>[3,2]</code>、<code>[2,1]</code> 以及 <code>[3,2,1]</code> 。</p>

<p>因此，返回 <code>3</code> 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 50</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次遍历

我们先进行一次遍历，找出严格递增的最长子数组长度，更新答案。然后再进行一次遍历，找出严格递减的最长子数组长度，再次更新答案。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans = t = 1
        for i, x in enumerate(nums[1:]):
            if nums[i] < x:
                t += 1
                ans = max(ans, t)
            else:
                t = 1
        t = 1
        for i, x in enumerate(nums[1:]):
            if nums[i] > x:
                t += 1
                ans = max(ans, t)
            else:
                t = 1
        return ans
```

#### Java

```java
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int ans = 1;
        for (int i = 1, t = 1; i < nums.length; ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
            }
        }
        for (int i = 1, t = 1; i < nums.length; ++i) {
            if (nums[i - 1] > nums[i]) {
                ans = Math.max(ans, ++t);
            } else {
                t = 1;
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
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        for (int i = 1, t = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                ans = max(ans, ++t);
            } else {
                t = 1;
            }
        }
        for (int i = 1, t = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                ans = max(ans, ++t);
            } else {
                t = 1;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestMonotonicSubarray(nums []int) int {
	ans := 1
	t := 1
	for i, x := range nums[1:] {
		if nums[i] < x {
			t++
			ans = max(ans, t)
		} else {
			t = 1
		}
	}
	t = 1
	for i, x := range nums[1:] {
		if nums[i] > x {
			t++
			ans = max(ans, t)
		} else {
			t = 1
		}
	}
	return ans
}
```

#### TypeScript

```ts
function longestMonotonicSubarray(nums: number[]): number {
    const n = nums.length;
    let ans = 1;

    for (let i = 1, t1 = 1, t2 = 1; i < n; i++) {
        t1 = nums[i] > nums[i - 1] ? t1 + 1 : 1;
        t2 = nums[i] < nums[i - 1] ? t2 + 1 : 1;
        ans = Math.max(ans, t1, t2);
    }

    return ans;
}
```

#### JavaScript

```js
function longestMonotonicSubarray(nums) {
    const n = nums.length;
    let ans = 1;

    for (let i = 1, t1 = 1, t2 = 1; i < n; i++) {
        t1 = nums[i] > nums[i - 1] ? t1 + 1 : 1;
        t2 = nums[i] < nums[i - 1] ? t2 + 1 : 1;
        ans = Math.max(ans, t1, t2);
    }

    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3106. 满足距离约束且字典序最小的字符串](https://leetcode.cn/problems/lexicographically-smallest-string-after-operations-with-constraint){#3106}

{{< tabs "3106" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        cs = list(s)
        for i, c1 in enumerate(s):
            for c2 in ascii_lowercase:
                if c2 >= c1:
                    break
                d = min(ord(c1) - ord(c2), 26 - ord(c1) + ord(c2))
                if d <= k:
                    cs[i] = c2
                    k -= d
                    break
        return "".join(cs)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String getSmallestString(String s, int k) {
        char[] cs = s.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
            char c1 = cs[i];
            for (char c2 = 'a'; c2 < c1; ++c2) {
                int d = Math.min(c1 - c2, 26 - c1 + c2);
                if (d <= k) {
                    cs[i] = c2;
                    k -= d;
                    break;
                }
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
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            for (char c2 = 'a'; c2 < c1; ++c2) {
                int d = min(c1 - c2, 26 - c1 + c2);
                if (d <= k) {
                    s[i] = c2;
                    k -= d;
                    break;
                }
            }
        }
        return s;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSmallestString(s string, k int) string {
	cs := []byte(s)
	for i, c1 := range cs {
		for c2 := byte('a'); c2 < c1; c2++ {
			d := int(min(c1-c2, 26-c1+c2))
			if d <= k {
				cs[i] = c2
				k -= d
				break
			}
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getSmallestString(s: string, k: number): string {
    const cs: string[] = s.split('');
    for (let i = 0; i < s.length; ++i) {
        for (let j = 97; j < s[i].charCodeAt(0); ++j) {
            const d = Math.min(s[i].charCodeAt(0) - j, 26 - s[i].charCodeAt(0) + j);
            if (d <= k) {
                cs[i] = String.fromCharCode(j);
                k -= d;
                break;
            }
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

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> 。</p>

<p>定义函数 <code>distance(s<sub>1</sub>, s<sub>2</sub>)</code> ，用于衡量两个长度为 <code>n</code> 的字符串 <code>s<sub>1</sub></code> 和 <code>s<sub>2</sub></code> 之间的距离，即：</p>

<ul>
	<li>字符 <code>'a'</code> 到 <code>'z'</code> 按 <strong>循环 </strong>顺序排列，对于区间 <code>[0, n - 1]</code> 中的 <code>i</code> ，计算所有「 <code>s<sub>1</sub>[i]</code> 和 <code>s<sub>2</sub>[i]</code> 之间<strong> 最小距离</strong>」的 <strong>和 </strong>。</li>
</ul>

<p>例如，<code>distance("ab", "cd") == 4</code> ，且 <code>distance("a", "z") == 1</code> 。</p>

<p>你可以对字符串 <code>s</code> 执行<strong> 任意次 </strong>操作。在每次操作中，可以将 <code>s</code> 中的一个字母 <strong>改变 </strong>为<strong> 任意 </strong>其他小写英文字母。</p>

<p>返回一个字符串，表示在执行一些操作后你可以得到的 <strong>字典序最小</strong> 的字符串 <code>t</code> ，且满足 <code>distance(s, t) &lt;= k</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "zbbz", k = 3
<strong>输出：</strong>"aaaz"
<strong>解释：</strong>在这个例子中，可以执行以下操作：
将 s[0] 改为 'a' ，s 变为 "abbz" 。
将 s[1] 改为 'a' ，s 变为 "aabz" 。
将 s[2] 改为 'a' ，s 变为 "aaaz" 。
"zbbz" 和 "aaaz" 之间的距离等于 k = 3 。
可以证明 "aaaz" 是在任意次操作后能够得到的字典序最小的字符串。
因此，答案是 "aaaz" 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "xaxcd", k = 4
<strong>输出：</strong>"aawcd"
<strong>解释：</strong>在这个例子中，可以执行以下操作：
将 s[0] 改为 'a' ，s 变为 "aaxcd" 。
将 s[2] 改为 'w' ，s 变为 "aawcd" 。
"xaxcd" 和 "aawcd" 之间的距离等于 k = 4 。
可以证明 "aawcd" 是在任意次操作后能够得到的字典序最小的字符串。
因此，答案是 "aawcd" 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "lol", k = 0
<strong>输出：</strong>"lol"
<strong>解释：</strong>在这个例子中，k = 0，更改任何字符都会使得距离大于 0 。
因此，答案是 "lol" 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2000</code></li>
	<li><code>s</code> 只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以遍历字符串 $s$ 的每个位置，对于每个位置，我们枚举所有小于当前字符的字符，计算改变到这个字符的代价 $d$，如果 $d \leq k$，我们就将当前位置的字符改为这个字符，并将 $k$ 减去 $d$，然后结束枚举，继续遍历下一个位置。

遍历结束后，我们就得到了一个满足条件的字符串。

时间复杂度 $O(n \times |\Sigma|)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度；而 $|\Sigma|$ 是字符集的大小，本题中 $|\Sigma| \leq 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSmallestString(self, s: str, k: int) -> str:
        cs = list(s)
        for i, c1 in enumerate(s):
            for c2 in ascii_lowercase:
                if c2 >= c1:
                    break
                d = min(ord(c1) - ord(c2), 26 - ord(c1) + ord(c2))
                if d <= k:
                    cs[i] = c2
                    k -= d
                    break
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String getSmallestString(String s, int k) {
        char[] cs = s.toCharArray();
        for (int i = 0; i < cs.length; ++i) {
            char c1 = cs[i];
            for (char c2 = 'a'; c2 < c1; ++c2) {
                int d = Math.min(c1 - c2, 26 - c1 + c2);
                if (d <= k) {
                    cs[i] = c2;
                    k -= d;
                    break;
                }
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
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            for (char c2 = 'a'; c2 < c1; ++c2) {
                int d = min(c1 - c2, 26 - c1 + c2);
                if (d <= k) {
                    s[i] = c2;
                    k -= d;
                    break;
                }
            }
        }
        return s;
    }
};
```

#### Go

```go
func getSmallestString(s string, k int) string {
	cs := []byte(s)
	for i, c1 := range cs {
		for c2 := byte('a'); c2 < c1; c2++ {
			d := int(min(c1-c2, 26-c1+c2))
			if d <= k {
				cs[i] = c2
				k -= d
				break
			}
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function getSmallestString(s: string, k: number): string {
    const cs: string[] = s.split('');
    for (let i = 0; i < s.length; ++i) {
        for (let j = 97; j < s[i].charCodeAt(0); ++j) {
            const d = Math.min(s[i].charCodeAt(0) - j, 26 - s[i].charCodeAt(0) + j);
            if (d <= k) {
                cs[i] = String.fromCharCode(j);
                k -= d;
                break;
            }
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

# [3107. 使数组中位数等于 K 的最少操作数](https://leetcode.cn/problems/minimum-operations-to-make-median-of-array-equal-to-k){#3107}

{{< tabs "3107" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        m = n >> 1
        ans = abs(nums[m] - k)
        if nums[m] > k:
            for i in range(m - 1, -1, -1):
                if nums[i] <= k:
                    break
                ans += nums[i] - k
        else:
            for i in range(m + 1, n):
                if nums[i] >= k:
                    break
                ans += k - nums[i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int m = n >> 1;
        long ans = Math.abs(nums[m] - k);
        if (nums[m] > k) {
            for (int i = m - 1; i >= 0 && nums[i] > k; --i) {
                ans += nums[i] - k;
            }
        } else {
            for (int i = m + 1; i < n && nums[i] < k; ++i) {
                ans += k - nums[i];
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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n >> 1;
        long long ans = abs(nums[m] - k);
        if (nums[m] > k) {
            for (int i = m - 1; i >= 0 && nums[i] > k; --i) {
                ans += nums[i] - k;
            }
        } else {
            for (int i = m + 1; i < n && nums[i] < k; ++i) {
                ans += k - nums[i];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperationsToMakeMedianK(nums []int, k int) (ans int64) {
	sort.Ints(nums)
	n := len(nums)
	m := n >> 1
	ans = int64(abs(nums[m] - k))
	if nums[m] > k {
		for i := m - 1; i >= 0 && nums[i] > k; i-- {
			ans += int64(nums[i] - k)
		}
	} else {
		for i := m + 1; i < n && nums[i] < k; i++ {
			ans += int64(k - nums[i])
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
function minOperationsToMakeMedianK(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const m = n >> 1;
    let ans = Math.abs(nums[m] - k);
    if (nums[m] > k) {
        for (let i = m - 1; i >= 0 && nums[i] > k; --i) {
            ans += nums[i] - k;
        }
    } else {
        for (let i = m + 1; i < n && nums[i] < k; ++i) {
            ans += k - nums[i];
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>非负</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。一次操作中，你可以选择任一元素&nbsp;加&nbsp;<code>1</code>&nbsp;或者减&nbsp;<code>1</code>&nbsp;。</p>

<p>请你返回将 <code>nums</code>&nbsp;<strong>中位数</strong>&nbsp;变为 <code>k</code>&nbsp;所需要的 <strong>最少</strong>&nbsp;操作次数。</p>

<p>一个数组的中位数指的是数组按非递减顺序排序后最中间的元素。如果数组长度为偶数，我们选择中间两个数的较大值为中位数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,5,6,8,5], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b>我们将&nbsp;<code>nums[1]</code> 和&nbsp;<code>nums[4]</code>&nbsp;减 <code>1</code>&nbsp;得到&nbsp;<code>[2, 4, 6, 8, 4]</code>&nbsp;。现在数组的中位数等于&nbsp;<code>k</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,5,6,8,5], k = 7</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><b>解释：</b>我们将&nbsp;<code>nums[1]</code>&nbsp;增加 1 两次，并且将&nbsp;<code>nums[2]</code>&nbsp;增加 1 一次，得到&nbsp;<code>[2, 7, 7, 8, 5]</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3,4,5,6], k = 4</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><b>解释：</b>数组中位数已经等于 <code>k</code>&nbsp;了。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 排序

我们首先对数组 $nums$ 进行排序，然后找到中位数的位置 $m$，那么初始时我们需要的操作次数就是 $|nums[m] - k|$。

接下来，我们分情况讨论：

-   如果 $nums[m] \gt k$，那么 $m$ 右侧的元素都大于等于 $k$，我们只需要将 $m$ 左侧的元素中，大于 $k$ 的元素减小到 $k$ 即可。
-   如果 $nums[m] \le k$，那么 $m$ 左侧的元素都小于等于 $k$，我们只需要将 $m$ 右侧的元素中，小于 $k$ 的元素增大到 $k$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        m = n >> 1
        ans = abs(nums[m] - k)
        if nums[m] > k:
            for i in range(m - 1, -1, -1):
                if nums[i] <= k:
                    break
                ans += nums[i] - k
        else:
            for i in range(m + 1, n):
                if nums[i] >= k:
                    break
                ans += k - nums[i]
        return ans
```

#### Java

```java
class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int m = n >> 1;
        long ans = Math.abs(nums[m] - k);
        if (nums[m] > k) {
            for (int i = m - 1; i >= 0 && nums[i] > k; --i) {
                ans += nums[i] - k;
            }
        } else {
            for (int i = m + 1; i < n && nums[i] < k; ++i) {
                ans += k - nums[i];
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
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n >> 1;
        long long ans = abs(nums[m] - k);
        if (nums[m] > k) {
            for (int i = m - 1; i >= 0 && nums[i] > k; --i) {
                ans += nums[i] - k;
            }
        } else {
            for (int i = m + 1; i < n && nums[i] < k; ++i) {
                ans += k - nums[i];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minOperationsToMakeMedianK(nums []int, k int) (ans int64) {
	sort.Ints(nums)
	n := len(nums)
	m := n >> 1
	ans = int64(abs(nums[m] - k))
	if nums[m] > k {
		for i := m - 1; i >= 0 && nums[i] > k; i-- {
			ans += int64(nums[i] - k)
		}
	} else {
		for i := m + 1; i < n && nums[i] < k; i++ {
			ans += int64(k - nums[i])
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
function minOperationsToMakeMedianK(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const m = n >> 1;
    let ans = Math.abs(nums[m] - k);
    if (nums[m] > k) {
        for (let i = m - 1; i >= 0 && nums[i] > k; --i) {
            ans += nums[i] - k;
        }
    } else {
        for (let i = m + 1; i < n && nums[i] < k; ++i) {
            ans += k - nums[i];
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

# [3108. 带权图里旅途的最小代价](https://leetcode.cn/problems/minimum-cost-walk-in-weighted-graph){#3108}

{{< tabs "3108" >}}

{{% tab "python" %}}
```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def minimumCost(
        self, n: int, edges: List[List[int]], query: List[List[int]]
    ) -> List[int]:
        g = [-1] * n
        uf = UnionFind(n)
        for u, v, _ in edges:
            uf.union(u, v)
        for u, _, w in edges:
            root = uf.find(u)
            g[root] &= w

        def f(u: int, v: int) -> int:
            if u == v:
                return 0
            a, b = uf.find(u), uf.find(v)
            return g[a] if a == b else -1

        return [f(s, t) for s, t in query]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int x) {
        return size[find(x)];
    }
}

class Solution {
    private UnionFind uf;
    private int[] g;

    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        uf = new UnionFind(n);
        for (var e : edges) {
            uf.union(e[0], e[1]);
        }
        g = new int[n];
        Arrays.fill(g, -1);
        for (var e : edges) {
            int root = uf.find(e[0]);
            g[root] &= e[2];
        }
        int m = query.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int s = query[i][0], t = query[i][1];
            ans[i] = f(s, t);
        }
        return ans;
    }

    private int f(int u, int v) {
        if (u == v) {
            return 0;
        }
        int a = uf.find(u), b = uf.find(v);
        return a == b ? g[a] : -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int x) {
        return size[find(x)];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        g = vector<int>(n, -1);
        uf = new UnionFind(n);
        for (auto& e : edges) {
            uf->unite(e[0], e[1]);
        }
        for (auto& e : edges) {
            int root = uf->find(e[0]);
            g[root] &= e[2];
        }
        vector<int> ans;
        for (auto& q : query) {
            ans.push_back(f(q[0], q[1]));
        }
        return ans;
    }

private:
    UnionFind* uf;
    vector<int> g;

    int f(int u, int v) {
        if (u == v) {
            return 0;
        }
        int a = uf->find(u), b = uf->find(v);
        return a == b ? g[a] : -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(x int) int {
	return uf.size[uf.find(x)]
}

func minimumCost(n int, edges [][]int, query [][]int) (ans []int) {
	uf := newUnionFind(n)
	g := make([]int, n)
	for i := range g {
		g[i] = -1
	}
	for _, e := range edges {
		uf.union(e[0], e[1])
	}
	for _, e := range edges {
		root := uf.find(e[0])
		g[root] &= e[2]
	}
	f := func(u, v int) int {
		if u == v {
			return 0
		}
		a, b := uf.find(u), uf.find(v)
		if a == b {
			return g[a]
		}
		return -1
	}
	for _, q := range query {
		ans = append(ans, f(q[0], q[1]))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(x: number): number {
        return this.size[this.find(x)];
    }
}

function minimumCost(n: number, edges: number[][], query: number[][]): number[] {
    const uf = new UnionFind(n);
    const g: number[] = Array(n).fill(-1);
    for (const [u, v, _] of edges) {
        uf.union(u, v);
    }
    for (const [u, _, w] of edges) {
        const root = uf.find(u);
        g[root] &= w;
    }
    const f = (u: number, v: number): number => {
        if (u === v) {
            return 0;
        }
        const [a, b] = [uf.find(u), uf.find(v)];
        return a === b ? g[a] : -1;
    };
    return query.map(([u, v]) => f(u, v));
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>n</code>&nbsp;个节点的带权无向图，节点编号为 <code>0</code>&nbsp;到 <code>n - 1</code>&nbsp;。</p>

<p>给你一个整数 <code>n</code>&nbsp;和一个数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [u<sub>i</sub>, v<sub>i</sub>, w<sub>i</sub>]</code>&nbsp;表示节点&nbsp;<code>u<sub>i</sub></code> 和&nbsp;<code>v<sub>i</sub></code>&nbsp;之间有一条权值为&nbsp;<code>w<sub>i</sub></code>&nbsp;的无向边。</p>

<p>在图中，一趟旅途包含一系列节点和边。旅途开始和结束点都是图中的节点，且图中存在连接旅途中相邻节点的边。注意，一趟旅途可能访问同一条边或者同一个节点多次。</p>

<p>如果旅途开始于节点 <code>u</code>&nbsp;，结束于节点 <code>v</code>&nbsp;，我们定义这一趟旅途的 <strong>代价</strong>&nbsp;是经过的边权按位与 <code>AND</code>&nbsp;的结果。换句话说，如果经过的边对应的边权为&nbsp;<code>w<sub>0</sub>, w<sub>1</sub>, w<sub>2</sub>, ..., w<sub>k</sub></code>&nbsp;，那么代价为<code>w<sub>0</sub> &amp; w<sub>1</sub> &amp; w<sub>2</sub> &amp; ... &amp; w<sub>k</sub></code>&nbsp;，其中&nbsp;<code>&amp;</code>&nbsp;表示按位与&nbsp;<code>AND</code>&nbsp;操作。</p>

<p>给你一个二维数组&nbsp;<code>query</code>&nbsp;，其中&nbsp;<code>query[i] = [s<sub>i</sub>, t<sub>i</sub>]</code>&nbsp;。对于每一个查询，你需要找出从节点开始&nbsp;<code>s<sub>i</sub></code>&nbsp;，在节点&nbsp;<code>t<sub>i</sub></code>&nbsp;处结束的旅途的最小代价。如果不存在这样的旅途，答案为&nbsp;<code>-1</code>&nbsp;。</p>

<p>返回数组<em>&nbsp;</em><code>answer</code>&nbsp;，其中<em>&nbsp;</em><code>answer[i]</code><em>&nbsp;</em>表示对于查询 <code>i</code>&nbsp;的&nbsp;<strong>最小</strong>&nbsp;旅途代价。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]</span></p>

<p><span class="example-io"><b>输出：</b>[1,-1]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3108.Minimum%20Cost%20Walk%20in%20Weighted%20Graph/images/q4_example1-1.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 351px; height: 141px;" /></p>

<p>第一个查询想要得到代价为 1 的旅途，我们依次访问：<code>0-&gt;1</code>（边权为 7 ）<code>1-&gt;2</code>&nbsp;（边权为 1 ）<code>2-&gt;1</code>（边权为 1 ）<code>1-&gt;3</code>&nbsp;（边权为 7 ）。</p>

<p>第二个查询中，无法从节点 3 到节点 4 ，所以答案为 -1 。</p>

<p><strong class="example">示例 2：</strong></p>
</div>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]</span></p>

<p><span class="example-io"><b>输出：</b>[0]</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3100-3199/3108.Minimum%20Cost%20Walk%20in%20Weighted%20Graph/images/q4_example2e.png" style="padding: 10px; background: rgb(255, 255, 255); border-radius: 0.5rem; width: 211px; height: 181px;" /></p>

<p>第一个查询想要得到代价为 0 的旅途，我们依次访问：<code>1-&gt;2</code>（边权为 1 ），<code>2-&gt;1</code>（边权 为 6 ），<code>1-&gt;2</code>（边权为 1 ）。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= edges.length &lt;= 10<sup>5</sup></code></li>
	<li><code>edges[i].length == 3</code></li>
	<li><code>0 &lt;= u<sub>i</sub>, v<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>u<sub>i</sub> != v<sub>i</sub></code></li>
	<li><code>0 &lt;= w<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= query.length &lt;= 10<sup>5</sup></code></li>
	<li><code>query[i].length == 2</code></li>
	<li><code>0 &lt;= s<sub>i</sub>, t<sub>i</sub> &lt;= n - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 并查集

我们注意到，一个正整数与其他若干个正整数不断进行“按位与”运算，结果只会越来越小。因此，为了使得旅途的代价尽可能小，我们应该将处于同一个连通分量的所有边的权值进行“按位与”运算，然后再进行查询。

那么，问题转化为，如何找出同一个连通份量的所有边，然后进行“按位与”运算。

我们可以用并查集来维护连通分量。

具体地，我们遍历每一条边 $(u, v, w)$，将 $u$ 和 $v$ 进行合并。然后，我们再一次遍历每一条边 $(u, v, w)$，找到 $u$ 和 $v$ 所在的连通分量的根节点 $root$，用一个数组 $g$ 记录每个连通分量的所有边的权值进行“按位与”运算的结果。

最后，对于每一个查询 $(s, t)$，我们首先判断 $s$ 与 $t$ 是否相等，如果相等，那么答案为 $0$，否则，我们判断 $s$ 和 $t$ 是否在同一个连通分量中，如果在同一个连通分量中，那么答案为该查询的连通分量的根节点的 $g$ 值，否则，答案为 $-1$。

时间复杂度 $O((n + m + q) \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$, $m$ 和 $q$ 分别表示节点数、边数和查询数，而 $\alpha(n)$ 表示 Ackermann 函数的反函数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def minimumCost(
        self, n: int, edges: List[List[int]], query: List[List[int]]
    ) -> List[int]:
        g = [-1] * n
        uf = UnionFind(n)
        for u, v, _ in edges:
            uf.union(u, v)
        for u, _, w in edges:
            root = uf.find(u)
            g[root] &= w

        def f(u: int, v: int) -> int:
            if u == v:
                return 0
            a, b = uf.find(u), uf.find(v)
            return g[a] if a == b else -1

        return [f(s, t) for s, t in query]
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    public int size(int x) {
        return size[find(x)];
    }
}

class Solution {
    private UnionFind uf;
    private int[] g;

    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        uf = new UnionFind(n);
        for (var e : edges) {
            uf.union(e[0], e[1]);
        }
        g = new int[n];
        Arrays.fill(g, -1);
        for (var e : edges) {
            int root = uf.find(e[0]);
            g[root] &= e[2];
        }
        int m = query.length;
        int[] ans = new int[m];
        for (int i = 0; i < m; ++i) {
            int s = query[i][0], t = query[i][1];
            ans[i] = f(s, t);
        }
        return ans;
    }

    private int f(int u, int v) {
        if (u == v) {
            return 0;
        }
        int a = uf.find(u), b = uf.find(v);
        return a == b ? g[a] : -1;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int x) {
        return size[find(x)];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        g = vector<int>(n, -1);
        uf = new UnionFind(n);
        for (auto& e : edges) {
            uf->unite(e[0], e[1]);
        }
        for (auto& e : edges) {
            int root = uf->find(e[0]);
            g[root] &= e[2];
        }
        vector<int> ans;
        for (auto& q : query) {
            ans.push_back(f(q[0], q[1]));
        }
        return ans;
    }

private:
    UnionFind* uf;
    vector<int> g;

    int f(int u, int v) {
        if (u == v) {
            return 0;
        }
        int a = uf->find(u), b = uf->find(v);
        return a == b ? g[a] : -1;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func (uf *unionFind) getSize(x int) int {
	return uf.size[uf.find(x)]
}

func minimumCost(n int, edges [][]int, query [][]int) (ans []int) {
	uf := newUnionFind(n)
	g := make([]int, n)
	for i := range g {
		g[i] = -1
	}
	for _, e := range edges {
		uf.union(e[0], e[1])
	}
	for _, e := range edges {
		root := uf.find(e[0])
		g[root] &= e[2]
	}
	f := func(u, v int) int {
		if u == v {
			return 0
		}
		a, b := uf.find(u), uf.find(v)
		if a == b {
			return g[a]
		}
		return -1
	}
	for _, q := range query {
		ans = append(ans, f(q[0], q[1]))
	}
	return
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }

    getSize(x: number): number {
        return this.size[this.find(x)];
    }
}

function minimumCost(n: number, edges: number[][], query: number[][]): number[] {
    const uf = new UnionFind(n);
    const g: number[] = Array(n).fill(-1);
    for (const [u, v, _] of edges) {
        uf.union(u, v);
    }
    for (const [u, _, w] of edges) {
        const root = uf.find(u);
        g[root] &= w;
    }
    const f = (u: number, v: number): number => {
        if (u === v) {
            return 0;
        }
        const [a, b] = [uf.find(u), uf.find(v)];
        return a === b ? g[a] : -1;
    };
    return query.map(([u, v]) => f(u, v));
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3109. 查找排列的下标 🔒](https://leetcode.cn/problems/find-the-index-of-permutation){#3109}

{{< tabs "3109" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def getPermutationIndex(self, perm: List[int]) -> int:
        mod = 10**9 + 7
        ans, n = 0, len(perm)
        tree = BinaryIndexedTree(n + 1)
        f = [1] * n
        for i in range(1, n):
            f[i] = f[i - 1] * i % mod
        for i, x in enumerate(perm):
            cnt = x - 1 - tree.query(x)
            ans += cnt * f[n - i - 1] % mod
            tree.update(x, 1)
        return ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int getPermutationIndex(int[] perm) {
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        int n = perm.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(n + 1);
        long[] f = new long[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] * i % mod;
        }
        for (int i = 0; i < n; ++i) {
            int cnt = perm[i] - 1 - tree.query(perm[i]);
            ans = (ans + cnt * f[n - i - 1] % mod) % mod;
            tree.update(perm[i], 1);
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int getPermutationIndex(vector<int>& perm) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll ans = 0;
        int n = perm.size();
        BinaryIndexedTree tree(n + 1);
        ll f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] * i % mod;
        }
        for (int i = 0; i < n; ++i) {
            int cnt = perm[i] - 1 - tree.query(perm[i]);
            ans += cnt * f[n - i - 1] % mod;
            tree.update(perm[i], 1);
        }
        return ans % mod;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func getPermutationIndex(perm []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(perm)
	tree := NewBinaryIndexedTree(n + 1)
	f := make([]int, n)
	f[0] = 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
	}
	for i, x := range perm {
		cnt := x - 1 - tree.query(x)
		ans += cnt * f[n-1-i] % mod
		tree.update(x, 1)
	}
	return ans % mod
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function getPermutationIndex(perm: number[]): number {
    const mod = 1e9 + 7;
    const n = perm.length;
    const tree = new BinaryIndexedTree(n + 1);
    let ans = 0;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }
    for (let i = 0; i < n; ++i) {
        const cnt = perm[i] - 1 - tree.query(perm[i]);
        ans = (ans + cnt * f[n - i - 1]) % mod;
        tree.update(perm[i], 1);
    }
    return ans % mod;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为&nbsp;<code>n</code>&nbsp;的数组&nbsp;<code>perm</code>，它是&nbsp;<code>[1, 2, ..., n]</code>&nbsp;的一个排列，将&nbsp;<code>[1, 2, ..., n]</code>&nbsp;所有的排列放在数组中，并以&nbsp;<span data-keyword="lexicographically-sorted-array">字典序</span>&nbsp;排序，返回这个数组中&nbsp;<code>perm</code>&nbsp;的下标。</p>

<p>由于答案可能非常大，返回值对&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code>&nbsp;<strong>取模</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>perm = [1,2]</span></p>

<p><span class="example-io"><b>输出：</b>0</span></p>

<p><strong>解释：</strong></p>

<p>按以下顺序只有 2 种排列：</p>

<p><code>[1,2]</code>, <code>[2,1]</code><br />
<br />
并且&nbsp;<code>[1,2]</code>&nbsp;在下标 0。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>perm = [3,1,2]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p>按以下顺序只有 6 种排列：</p>

<p><code>[1,2,3]</code>, <code>[1,3,2]</code>, <code>[2,1,3]</code>, <code>[2,3,1]</code>, <code>[3,1,2]</code>, <code>[3,2,1]</code><br />
<br />
并且&nbsp;<code>[3,1,2]</code>&nbsp;在下标 4。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == perm.length &lt;= 10<sup>5</sup></code></li>
	<li><code>perm</code>&nbsp;是&nbsp;<code>[1, 2, ..., n]</code>&nbsp;的一个排列。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树状数组

根据题目要求，我们需要找出一共有多少个排列的字典序小于给定的排列。

我们考虑如何计算字典序小于给定排列的排列个数，一共有两种情况：

-   排列的第一个元素小于 $perm[0]$，一共有 $(perm[0] - 1) \times (n-1)!$ 种排列。
-   排列的第一个元素等于 $perm[0]$，我们需要继续考虑第二个元素，以此类推。
-   累加所有情况即可。

我们可以用树状数组维护遍历过的元素中，比当前元素小的元素个数，那么对于给定排列的第 $i$ 个元素，剩余的比它小的元素个数为 $perm[i] - 1 - tree.query(perm[i])$，排列种类数为 $(perm[i] - 1 - tree.query(perm[i])) \times (n-i-1)!$，累加到答案中。然后我们更新树状数组，将当前元素加入树状数组。继续遍历下一个元素，直到遍历完所有元素。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为排列的长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    __slots__ = "n", "c"

    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, delta: int) -> None:
        while x <= self.n:
            self.c[x] += delta
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def getPermutationIndex(self, perm: List[int]) -> int:
        mod = 10**9 + 7
        ans, n = 0, len(perm)
        tree = BinaryIndexedTree(n + 1)
        f = [1] * n
        for i in range(1, n):
            f[i] = f[i - 1] * i % mod
        for i, x in enumerate(perm):
            cnt = x - 1 - tree.query(x)
            ans += cnt * f[n - i - 1] % mod
            tree.update(x, 1)
        return ans % mod
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    public int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
}

class Solution {
    public int getPermutationIndex(int[] perm) {
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        int n = perm.length;
        BinaryIndexedTree tree = new BinaryIndexedTree(n + 1);
        long[] f = new long[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] * i % mod;
        }
        for (int i = 0; i < n; ++i) {
            int cnt = perm[i] - 1 - tree.query(perm[i]);
            ans = (ans + cnt * f[n - i - 1] % mod) % mod;
            tree.update(perm[i], 1);
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
private:
    int n;
    vector<int> c;

public:
    BinaryIndexedTree(int n)
        : n(n)
        , c(n + 1) {}

    void update(int x, int delta) {
        for (; x <= n; x += x & -x) {
            c[x] += delta;
        }
    }

    int query(int x) {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c[x];
        }
        return s;
    }
};

class Solution {
public:
    int getPermutationIndex(vector<int>& perm) {
        const int mod = 1e9 + 7;
        using ll = long long;
        ll ans = 0;
        int n = perm.size();
        BinaryIndexedTree tree(n + 1);
        ll f[n];
        f[0] = 1;
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] * i % mod;
        }
        for (int i = 0; i < n; ++i) {
            int cnt = perm[i] - 1 - tree.query(perm[i]);
            ans += cnt * f[n - i - 1] % mod;
            tree.update(perm[i], 1);
        }
        return ans % mod;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func NewBinaryIndexedTree(n int) *BinaryIndexedTree {
	return &BinaryIndexedTree{n: n, c: make([]int, n+1)}
}

func (bit *BinaryIndexedTree) update(x, delta int) {
	for ; x <= bit.n; x += x & -x {
		bit.c[x] += delta
	}
}

func (bit *BinaryIndexedTree) query(x int) int {
	s := 0
	for ; x > 0; x -= x & -x {
		s += bit.c[x]
	}
	return s
}

func getPermutationIndex(perm []int) (ans int) {
	const mod int = 1e9 + 7
	n := len(perm)
	tree := NewBinaryIndexedTree(n + 1)
	f := make([]int, n)
	f[0] = 1
	for i := 1; i < n; i++ {
		f[i] = f[i-1] * i % mod
	}
	for i, x := range perm {
		cnt := x - 1 - tree.query(x)
		ans += cnt * f[n-1-i] % mod
		tree.update(x, 1)
	}
	return ans % mod
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, delta: number): void {
        for (; x <= this.n; x += x & -x) {
            this.c[x] += delta;
        }
    }

    query(x: number): number {
        let s = 0;
        for (; x > 0; x -= x & -x) {
            s += this.c[x];
        }
        return s;
    }
}

function getPermutationIndex(perm: number[]): number {
    const mod = 1e9 + 7;
    const n = perm.length;
    const tree = new BinaryIndexedTree(n + 1);
    let ans = 0;
    const f: number[] = Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        f[i] = (f[i - 1] * i) % mod;
    }
    for (let i = 0; i < n; ++i) {
        const cnt = perm[i] - 1 - tree.query(perm[i]);
        ans = (ans + cnt * f[n - i - 1]) % mod;
        tree.update(perm[i], 1);
    }
    return ans % mod;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
