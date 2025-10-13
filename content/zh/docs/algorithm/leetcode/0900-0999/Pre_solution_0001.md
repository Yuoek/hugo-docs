---
title: "0900_RLE 迭代器"
date: 2025-10-08T18:36:43+08:00
weight: 1
tags: [二分查找, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 字符串, 广度优先搜索, 排序, 数学, 数据流, 数组, 枚举, 栈, 滑动窗口, 矩阵, 计数, 设计, 迭代器]
---

{{< markmap >}}
### [0900_RLE 迭代器](#900)
#### [设计](#900)
#### [数组](#900)
#### [计数](#900)
#### [迭代器](#900)
### [0901_股票价格跨度](#901)
#### [栈](#901)
#### [设计](#901)
#### [数据流](#901)
#### [单调栈](#901)
### [0902_最大为 N 的数字组合](#902)
#### [数组](#902)
#### [数学](#902)
#### [字符串](#902)
#### [二分查找](#902)
#### [动态规划](#902)
### [0903_DI 序列的有效排列](#903)
#### [字符串](#903)
#### [动态规划](#903)
#### [前缀和](#903)
### [0904_水果成篮](#904)
#### [数组](#904)
#### [哈希表](#904)
#### [滑动窗口](#904)
### [0905_按奇偶排序数组](#905)
#### [数组](#905)
#### [双指针](#905)
#### [排序](#905)
### [0906_超级回文数](#906)
#### [数学](#906)
#### [字符串](#906)
#### [枚举](#906)
### [0907_子数组的最小值之和](#907)
#### [栈](#907)
#### [数组](#907)
#### [动态规划](#907)
#### [单调栈](#907)
### [0908_最小差值 I](#908)
#### [数组](#908)
#### [数学](#908)
### [0909_蛇梯棋](#909)
#### [广度优先搜索](#909)
#### [数组](#909)
#### [矩阵](#909)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0900_RLE 迭代器
___
#### 设计
___
#### 数组
___
#### 计数
___
#### 迭代器
---
### 0901_股票价格跨度
___
#### 栈
___
#### 设计
___
#### 数据流
___
#### 单调栈
---
### 0902_最大为 N 的数字组合
___
#### 数组
___
#### 数学
___
#### 字符串
___
#### 二分查找
___
#### 动态规划
---
### 0903_DI 序列的有效排列
___
#### 字符串
___
#### 动态规划
___
#### 前缀和
---
### 0904_水果成篮
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
---
### 0905_按奇偶排序数组
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 0906_超级回文数
___
#### 数学
___
#### 字符串
___
#### 枚举
---
### 0907_子数组的最小值之和
___
#### 栈
___
#### 数组
___
#### 动态规划
___
#### 单调栈
---
### 0908_最小差值 I
___
#### 数组
___
#### 数学
---
### 0909_蛇梯棋
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 单调栈 | 双指针 | 哈希表 |
| 字符串 | 广度优先搜索 | 排序 |
| 数学 | 数据流 | 数组 |
| 枚举 | 栈 | 滑动窗口 |
| 矩阵 | 计数 | 设计 |
| 迭代器 |  |  |

# [900. RLE 迭代器](https://leetcode.cn/problems/rle-iterator){#900}

{{< tabs "900" >}}

{{% tab "python" %}}
```python
class RLEIterator:
    def __init__(self, encoding: List[int]):
        self.encoding = encoding
        self.i = 0
        self.j = 0

    def next(self, n: int) -> int:
        while self.i < len(self.encoding):
            if self.encoding[self.i] - self.j < n:
                n -= self.encoding[self.i] - self.j
                self.i += 2
                self.j = 0
            else:
                self.j += n
                return self.encoding[self.i + 1]
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class RLEIterator {
    private int[] encoding;
    private int i;
    private int j;

    public RLEIterator(int[] encoding) {
        this.encoding = encoding;
    }

    public int next(int n) {
        while (i < encoding.length) {
            if (encoding[i] - j < n) {
                n -= (encoding[i] - j);
                i += 2;
                j = 0;
            } else {
                j += n;
                return encoding[i + 1];
            }
        }
        return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(encoding);
 * int param_1 = obj.next(n);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
    }

    int next(int n) {
        while (i < encoding.size()) {
            if (encoding[i] - j < n) {
                n -= (encoding[i] - j);
                i += 2;
                j = 0;
            } else {
                j += n;
                return encoding[i + 1];
            }
        }
        return -1;
    }

private:
    vector<int> encoding;
    int i = 0;
    int j = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type RLEIterator struct {
	encoding []int
	i, j     int
}

func Constructor(encoding []int) RLEIterator {
	return RLEIterator{encoding, 0, 0}
}

func (this *RLEIterator) Next(n int) int {
	for this.i < len(this.encoding) {
		if this.encoding[this.i]-this.j < n {
			n -= (this.encoding[this.i] - this.j)
			this.i += 2
			this.j = 0
		} else {
			this.j += n
			return this.encoding[this.i+1]
		}
	}
	return -1
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * obj := Constructor(encoding);
 * param_1 := obj.Next(n);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class RLEIterator {
    private encoding: number[];
    private i: number;
    private j: number;

    constructor(encoding: number[]) {
        this.encoding = encoding;
        this.i = 0;
        this.j = 0;
    }

    next(n: number): number {
        while (this.i < this.encoding.length) {
            if (this.encoding[this.i] - this.j < n) {
                n -= this.encoding[this.i] - this.j;
                this.i += 2;
                this.j = 0;
            } else {
                this.j += n;
                return this.encoding[this.i + 1];
            }
        }
        return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * var obj = new RLEIterator(encoding)
 * var param_1 = obj.next(n)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们可以使用游程编码(即&nbsp;<strong>RLE&nbsp;</strong>)来编码一个整数序列。在偶数长度&nbsp;<code>encoding</code>&nbsp;( <strong>从 0 开始</strong> )的游程编码数组中，对于所有偶数 <code>i</code> ，<code>encoding[i]</code>&nbsp;告诉我们非负整数&nbsp;<code>encoding[i + 1]</code>&nbsp;在序列中重复的次数。</p>

<ul>
	<li>例如，序列&nbsp;<code>arr = [8,8,8,5,5]</code>&nbsp;可以被编码为 <code>encoding =[3,8,2,5]</code> 。<code>encoding =[3,8,0,9,2,5]</code>&nbsp;和 <code>encoding =[2,8,1,8,2,5]</code> 也是&nbsp;<code>arr</code> 有效的 <strong>RLE</strong> 。</li>
</ul>

<p>给定一个游程长度的编码数组，设计一个迭代器来遍历它。</p>

<p>实现 <code>RLEIterator</code> 类:</p>

<ul>
	<li><code>RLEIterator(int[] encoded)</code>&nbsp;用编码后的数组初始化对象。</li>
	<li><code>int next(int n)</code> 以这种方式耗尽后 <code>n</code> 个元素并返回最后一个耗尽的元素。如果没有剩余的元素要耗尽，则返回 <code>-1</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：
</strong>["RLEIterator","next","next","next","next"]
[[[3,8,0,9,2,5]],[2],[1],[1],[2]]
<strong>输出：
</strong>[null,8,8,5,-1]
<strong>解释：</strong>
RLEIterator rLEIterator = new RLEIterator([3, 8, 0, 9, 2, 5]); // 这映射到序列 [8,8,8,5,5]。
rLEIterator.next(2); // 耗去序列的 2 个项，返回 8。现在剩下的序列是 [8, 5, 5]。
rLEIterator.next(1); // 耗去序列的 1 个项，返回 8。现在剩下的序列是 [5, 5]。
rLEIterator.next(1); // 耗去序列的 1 个项，返回 5。现在剩下的序列是 [5]。
rLEIterator.next(2); // 耗去序列的 2 个项，返回 -1。 这是由于第一个被耗去的项是 5，
但第二个项并不存在。由于最后一个要耗去的项不存在，我们返回 -1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= encoding.length &lt;= 1000</code></li>
	<li><code>encoding.length</code>&nbsp;为偶</li>
	<li><code>0 &lt;= encoding[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
	<li>每个测试用例调用<code>next </code>不高于&nbsp;<code>1000</code>&nbsp;次&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：维护两个指针

我们定义两个指针 $i$ 和 $j$，其中指针 $i$ 指向当前读取的游程编码，指针 $j$ 指向当前读取的游程编码中的第几个字符。初始时 $i = 0$, $j = 0$。

每次调用 `next(n)` 时，我们判断当前游程编码中剩余的字符数 $encoding[i] - j$ 是否小于 $n$，若是，则将 $n$ 减去 $encoding[i] - j$，并将 $i$ 加 $2$，$j$ 置为 $0$，然后继续判断下一个游程编码；若不是，则将 $j$ 加 $n$，并返回 $encoding[i + 1]$。

若 $i$ 超出了游程编码的长度，依然没有返回值，则说明没有剩余的元素要耗尽，返回 $-1$。

时间复杂度 $O(n + q)$，空间复杂度 $O(n)$。其中 $n$ 是游程编码的长度，而 $q$ 是调用 `next(n)` 的次数。

<!-- tabs:start -->

#### Python3

```python
class RLEIterator:
    def __init__(self, encoding: List[int]):
        self.encoding = encoding
        self.i = 0
        self.j = 0

    def next(self, n: int) -> int:
        while self.i < len(self.encoding):
            if self.encoding[self.i] - self.j < n:
                n -= self.encoding[self.i] - self.j
                self.i += 2
                self.j = 0
            else:
                self.j += n
                return self.encoding[self.i + 1]
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)
```

#### Java

```java
class RLEIterator {
    private int[] encoding;
    private int i;
    private int j;

    public RLEIterator(int[] encoding) {
        this.encoding = encoding;
    }

    public int next(int n) {
        while (i < encoding.length) {
            if (encoding[i] - j < n) {
                n -= (encoding[i] - j);
                i += 2;
                j = 0;
            } else {
                j += n;
                return encoding[i + 1];
            }
        }
        return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(encoding);
 * int param_1 = obj.next(n);
 */
```

#### C++

```cpp
class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
    }

    int next(int n) {
        while (i < encoding.size()) {
            if (encoding[i] - j < n) {
                n -= (encoding[i] - j);
                i += 2;
                j = 0;
            } else {
                j += n;
                return encoding[i + 1];
            }
        }
        return -1;
    }

private:
    vector<int> encoding;
    int i = 0;
    int j = 0;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
```

#### Go

```go
type RLEIterator struct {
	encoding []int
	i, j     int
}

func Constructor(encoding []int) RLEIterator {
	return RLEIterator{encoding, 0, 0}
}

func (this *RLEIterator) Next(n int) int {
	for this.i < len(this.encoding) {
		if this.encoding[this.i]-this.j < n {
			n -= (this.encoding[this.i] - this.j)
			this.i += 2
			this.j = 0
		} else {
			this.j += n
			return this.encoding[this.i+1]
		}
	}
	return -1
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * obj := Constructor(encoding);
 * param_1 := obj.Next(n);
 */
```

#### TypeScript

```ts
class RLEIterator {
    private encoding: number[];
    private i: number;
    private j: number;

    constructor(encoding: number[]) {
        this.encoding = encoding;
        this.i = 0;
        this.j = 0;
    }

    next(n: number): number {
        while (this.i < this.encoding.length) {
            if (this.encoding[this.i] - this.j < n) {
                n -= this.encoding[this.i] - this.j;
                this.i += 2;
                this.j = 0;
            } else {
                this.j += n;
                return this.encoding[this.i + 1];
            }
        }
        return -1;
    }
}

/**
 * Your RLEIterator object will be instantiated and called as such:
 * var obj = new RLEIterator(encoding)
 * var param_1 = obj.next(n)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [901. 股票价格跨度](https://leetcode.cn/problems/online-stock-span){#901}

{{< tabs "901" >}}

{{% tab "python" %}}
```python
class StockSpanner:
    def __init__(self):
        self.stk = []

    def next(self, price: int) -> int:
        cnt = 1
        while self.stk and self.stk[-1][0] <= price:
            cnt += self.stk.pop()[1]
        self.stk.append((price, cnt))
        return cnt


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class StockSpanner {
    private Deque<int[]> stk = new ArrayDeque<>();

    public StockSpanner() {
    }

    public int next(int price) {
        int cnt = 1;
        while (!stk.isEmpty() && stk.peek()[0] <= price) {
            cnt += stk.pop()[1];
        }
        stk.push(new int[] {price, cnt});
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price) {
        int cnt = 1;
        while (!stk.empty() && stk.top().first <= price) {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.emplace(price, cnt);
        return cnt;
    }

private:
    stack<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type StockSpanner struct {
	stk []pair
}

func Constructor() StockSpanner {
	return StockSpanner{[]pair{}}
}

func (this *StockSpanner) Next(price int) int {
	cnt := 1
	for len(this.stk) > 0 && this.stk[len(this.stk)-1].price <= price {
		cnt += this.stk[len(this.stk)-1].cnt
		this.stk = this.stk[:len(this.stk)-1]
	}
	this.stk = append(this.stk, pair{price, cnt})
	return cnt
}

type pair struct{ price, cnt int }

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class StockSpanner {
    private stk: number[][];

    constructor() {
        this.stk = [];
    }

    next(price: number): number {
        let cnt = 1;
        while (this.stk.length && this.stk.at(-1)[0] <= price) {
            cnt += this.stk.pop()[1];
        }
        this.stk.push([price, cnt]);
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;
struct StockSpanner {
    stk: VecDeque<(i32, i32)>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {
    fn new() -> Self {
        Self {
            stk: vec![(i32::MAX, -1)].into_iter().collect(),
        }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut cnt = 1;
        while self.stk.back().unwrap().0 <= price {
            cnt += self.stk.pop_back().unwrap().1;
        }
        self.stk.push_back((price, cnt));
        cnt
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 <strong>跨度</strong> 。</p>

<p>当日股票价格的 <strong>跨度</strong> 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。</p>

<ul>
	<li>
	<p>例如，如果未来 7 天股票的价格是 <code>[100,80,60,70,60,75,85]</code>，那么股票跨度将是 <code>[1,1,1,2,1,4,6]</code> 。</p>
	</li>
</ul>

<p>实现 <code>StockSpanner</code> 类：</p>

<ul>
	<li><code>StockSpanner()</code> 初始化类对象。</li>
	<li><code>int next(int price)</code> 给出今天的股价 <code>price</code> ，返回该股票当日价格的 <strong>跨度</strong> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例：</strong></p>

<pre>
<strong>输入</strong>：
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
<strong>输出</strong>：
[null, 1, 1, 1, 2, 1, 4, 6]

<strong>解释：</strong>
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // 返回 1
stockSpanner.next(80);  // 返回 1
stockSpanner.next(60);  // 返回 1
stockSpanner.next(70);  // 返回 2
stockSpanner.next(60);  // 返回 1
stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
stockSpanner.next(85);  // 返回 6
</pre>

&nbsp;

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= price &lt;= 10<sup>5</sup></code></li>
	<li>最多调用 <code>next</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

根据题目描述，我们可以知道，对于当日价格 $price$，从这个价格开始往前找，找到第一个比这个价格大的价格，这两个价格的下标差 $cnt$ 就是当日价格的跨度。

这实际上是经典的单调栈模型，找出左侧第一个比当前元素大的元素。

我们维护一个从栈底到栈顶价格单调递减的栈，栈中每个元素存放的是 $(price, cnt)$ 数据对，其中 $price$ 表示价格，而 $cnt$ 表示当前价格的跨度。

出现价格 $price$ 时，我们将其与栈顶元素进行比较，如果栈顶元素的价格小于等于 $price$，则将当日价格的跨度 $cnt$ 加上栈顶元素的跨度，然后将栈顶元素出栈，直到栈顶元素的价格大于 $price$，或者栈为空为止。

最后将 $(price, cnt)$ 入栈，返回 $cnt$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是调用 `next(price)` 的次数。

<!-- tabs:start -->

#### Python3

```python
class StockSpanner:
    def __init__(self):
        self.stk = []

    def next(self, price: int) -> int:
        cnt = 1
        while self.stk and self.stk[-1][0] <= price:
            cnt += self.stk.pop()[1]
        self.stk.append((price, cnt))
        return cnt


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
```

#### Java

```java
class StockSpanner {
    private Deque<int[]> stk = new ArrayDeque<>();

    public StockSpanner() {
    }

    public int next(int price) {
        int cnt = 1;
        while (!stk.isEmpty() && stk.peek()[0] <= price) {
            cnt += stk.pop()[1];
        }
        stk.push(new int[] {price, cnt});
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
```

#### C++

```cpp
class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price) {
        int cnt = 1;
        while (!stk.empty() && stk.top().first <= price) {
            cnt += stk.top().second;
            stk.pop();
        }
        stk.emplace(price, cnt);
        return cnt;
    }

private:
    stack<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```

#### Go

```go
type StockSpanner struct {
	stk []pair
}

func Constructor() StockSpanner {
	return StockSpanner{[]pair{}}
}

func (this *StockSpanner) Next(price int) int {
	cnt := 1
	for len(this.stk) > 0 && this.stk[len(this.stk)-1].price <= price {
		cnt += this.stk[len(this.stk)-1].cnt
		this.stk = this.stk[:len(this.stk)-1]
	}
	this.stk = append(this.stk, pair{price, cnt})
	return cnt
}

type pair struct{ price, cnt int }

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
```

#### TypeScript

```ts
class StockSpanner {
    private stk: number[][];

    constructor() {
        this.stk = [];
    }

    next(price: number): number {
        let cnt = 1;
        while (this.stk.length && this.stk.at(-1)[0] <= price) {
            cnt += this.stk.pop()[1];
        }
        this.stk.push([price, cnt]);
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * var obj = new StockSpanner()
 * var param_1 = obj.next(price)
 */
```

#### Rust

```rust
use std::collections::VecDeque;
struct StockSpanner {
    stk: VecDeque<(i32, i32)>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {
    fn new() -> Self {
        Self {
            stk: vec![(i32::MAX, -1)].into_iter().collect(),
        }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut cnt = 1;
        while self.stk.back().unwrap().0 <= price {
            cnt += self.stk.pop_back().unwrap().1;
        }
        self.stk.push_back((price, cnt));
        cnt
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [902. 最大为 N 的数字组合](https://leetcode.cn/problems/numbers-at-most-n-given-digit-set){#902}

{{< tabs "902" >}}

{{% tab "python" %}}
```python
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        @cache
        def dfs(i: int, lead: int, limit: bool) -> int:
            if i >= len(s):
                return lead ^ 1

            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if j == 0 and lead:
                    ans += dfs(i + 1, 1, limit and j == up)
                elif j in nums:
                    ans += dfs(i + 1, 0, limit and j == up)
            return ans

        s = str(n)
        nums = {int(x) for x in digits}
        return dfs(0, 1, True)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<Integer> nums = new HashSet<>();
    private char[] s;
    private Integer[] f;

    public int atMostNGivenDigitSet(String[] digits, int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length];
        for (var x : digits) {
            nums.add(Integer.parseInt(x));
        }
        return dfs(0, true, true);
    }

    private int dfs(int i, boolean lead, boolean limit) {
        if (i >= s.length) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i] != null) {
            return f[i];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (j == 0 && lead) {
                ans += dfs(i + 1, true, limit && j == up);
            } else if (nums.contains(j)) {
                ans += dfs(i + 1, false, limit && j == up);
            }
        }
        if (!lead && !limit) {
            f[i] = ans;
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
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        unordered_set<int> nums;
        for (auto& x : digits) {
            nums.insert(stoi(x));
        }
        int m = s.size();
        int f[m];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ? 0 : 1;
            }
            if (!lead && !limit && f[i] != -1) {
                return f[i];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j == 0 && lead) {
                    ans += dfs(i + 1, true, limit && j == up);
                } else if (nums.count(j)) {
                    ans += dfs(i + 1, false, limit && j == up);
                }
            }
            if (!lead && !limit) {
                f[i] = ans;
            }
            return ans;
        };
        return dfs(0, true, true);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func atMostNGivenDigitSet(digits []string, n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([]int, m)
	for i := range f {
		f[i] = -1
	}
	nums := map[int]bool{}
	for _, d := range digits {
		x, _ := strconv.Atoi(d)
		nums[x] = true
	}
	var dfs func(i int, lead, limit bool) int
	dfs = func(i int, lead, limit bool) int {
		if i >= m {
			if lead {
				return 0
			}
			return 1
		}
		if !lead && !limit && f[i] != -1 {
			return f[i]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if j == 0 && lead {
				ans += dfs(i+1, true, limit && j == up)
			} else if nums[j] {
				ans += dfs(i+1, false, limit && j == up)
			}
		}
		if !lead && !limit {
			f[i] = ans
		}
		return ans
	}
	return dfs(0, true, true)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function atMostNGivenDigitSet(digits: string[], n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[] = Array(m).fill(-1);
    const nums = new Set<number>(digits.map(d => parseInt(d)));
    const dfs = (i: number, lead: boolean, limit: boolean): number => {
        if (i >= m) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i] !== -1) {
            return f[i];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if (!j && lead) {
                ans += dfs(i + 1, true, limit && j === up);
            } else if (nums.has(j)) {
                ans += dfs(i + 1, false, limit && j === up);
            }
        }
        if (!lead && !limit) {
            f[i] = ans;
        }
        return ans;
    };
    return dfs(0, true, true);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个按&nbsp;<strong>非递减顺序</strong>&nbsp;排列的数字数组<meta charset="UTF-8" />&nbsp;<code>digits</code>&nbsp;。你可以用任意次数&nbsp;<code>digits[i]</code>&nbsp;来写的数字。例如，如果<meta charset="UTF-8" />&nbsp;<code>digits = ['1','3','5']</code>，我们可以写数字，如<meta charset="UTF-8" />&nbsp;<code>'13'</code>,&nbsp;<code>'551'</code>, 和&nbsp;<code>'1351315'</code>。</p>

<p>返回 <em>可以生成的小于或等于给定整数 <code>n</code> 的正整数的个数</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>digits = ["1","3","5","7"], n = 100
<strong>输出：</strong>20
<strong>解释：</strong>
可写出的 20 个数字是：
1, 3, 5, 7, 11, 13, 15, 17, 31, 33, 35, 37, 51, 53, 55, 57, 71, 73, 75, 77.
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>digits = ["1","4","9"], n = 1000000000
<strong>输出：</strong>29523
<strong>解释：</strong>
我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，
81 个四位数字，243 个五位数字，729 个六位数字，
2187 个七位数字，6561 个八位数字和 19683 个九位数字。
总共，可以使用D中的数字写出 29523 个整数。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>digits = ["7"], n = 8
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>
<meta charset="UTF-8" />

<ul>
	<li><code>1 &lt;= digits.length &lt;= 9</code></li>
	<li><code>digits[i].length == 1</code></li>
	<li><code>digits[i]</code>&nbsp;是从&nbsp;<code>'1'</code>&nbsp;到&nbsp;<code>'9'</code> 的数</li>
	<li><code>digits</code>&nbsp;中的所有值都 <strong>不同</strong>&nbsp;</li>
	<li><code>digits</code>&nbsp;按&nbsp;<strong>非递减顺序</strong>&nbsp;排列</li>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数位 DP

这道题实际上是求在给定区间 $[l,..r]$ 中，由 `digits` 中的数字生成的正整数的个数。个数与数的位数以及每一位上的数字有关。我们可以用数位 DP 的思路来解决这道题。数位 DP 中，数的大小对复杂度的影响很小。

对于区间 $[l,..r]$ 问题，我们一般会将其转化为 $[1,..r]$ 然后再减去 $[1,..l - 1]$ 的问题，即：

$$
ans = \sum_{i=1}^{r} ans_i -  \sum_{i=1}^{l-1} ans_i
$$

不过对于本题而言，我们只需要求出区间 $[1,..r]$ 的值即可。

这里我们用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

我们将数字 $n$ 转化为字符串 $s$，记字符串 $s$ 的长度为 $m$。

接下来，我们设计一个函数 $\textit{dfs}(i, \textit{lead}, \textit{limit})$，表示当前处理到字符串的第 $i$ 位，到最后一位的方案数。其中：

-   数字 $i$ 表示当前处理到字符串 $s$ 的第 $i$ 位；
-   布尔值 $\textit{lead}$ 表示是否只包含前导零；
-   布尔值 $\textit{limit}$ 表示当前位置是否受到上界的限制。

函数的执行过程如下：

如果 $i$ 大于等于 $m$，说明我们已经处理完了所有的位数，此时如果 $\textit{lead}$ 为真，说明当前的数字是前导零，我们应当返回 $0$；否则，我们应当返回 $1$。

否则，我们计算当前位置的上界 $\textit{up}$，如果 $\textit{limit}$ 为真，则 $up$ 为 $s[i]$ 对应的数字，否则 $up$ 为 $9$。

然后，我们在 $[0, \textit{up}]$ 的范围内枚举当前位置的数字 $j$，如果 $j$ 为 $0$ 且 $\textit{lead}$ 为真，我们递归计算 $\textit{dfs}(i + 1, \text{true}, \textit{limit} \wedge j = \textit{up})$；否则，如果 $j$ 在 $\textit{digits}$ 中，我们递归计算 $\textit{dfs}(i + 1, \text{false}, \textit{limit} \wedge j = \textit{up})$。累加所有的结果即为答案。

最后，我们返回 $\textit{dfs}(0, \text{true}, \text{true})$ 即可。

时间复杂度 $O(\log n \times D)$，空间复杂度 $O(\log n)$。其中 $D = 10$。

相似题目：

-   [233. 数字 1 的个数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0233.Number%20of%20Digit%20One/README.md)
-   [357. 统计各位数字都不同的数字个数](https://github.com/doocs/leetcode/blob/main/solution/0300-0399/0357.Count%20Numbers%20with%20Unique%20Digits/README.md)
-   [600. 不含连续 1 的非负整数](https://github.com/doocs/leetcode/blob/main/solution/0600-0699/0600.Non-negative%20Integers%20without%20Consecutive%20Ones/README.md)
-   [788. 旋转数字](https://github.com/doocs/leetcode/blob/main/solution/0700-0799/0788.Rotated%20Digits/README.md)
-   [1012. 至少有 1 位重复的数字](https://github.com/doocs/leetcode/blob/main/solution/1000-1099/1012.Numbers%20With%20Repeated%20Digits/README.md)
-   [2376. 统计特殊整数](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2376.Count%20Special%20Integers/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        @cache
        def dfs(i: int, lead: int, limit: bool) -> int:
            if i >= len(s):
                return lead ^ 1

            up = int(s[i]) if limit else 9
            ans = 0
            for j in range(up + 1):
                if j == 0 and lead:
                    ans += dfs(i + 1, 1, limit and j == up)
                elif j in nums:
                    ans += dfs(i + 1, 0, limit and j == up)
            return ans

        s = str(n)
        nums = {int(x) for x in digits}
        return dfs(0, 1, True)
```

#### Java

```java
class Solution {
    private Set<Integer> nums = new HashSet<>();
    private char[] s;
    private Integer[] f;

    public int atMostNGivenDigitSet(String[] digits, int n) {
        s = String.valueOf(n).toCharArray();
        f = new Integer[s.length];
        for (var x : digits) {
            nums.add(Integer.parseInt(x));
        }
        return dfs(0, true, true);
    }

    private int dfs(int i, boolean lead, boolean limit) {
        if (i >= s.length) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i] != null) {
            return f[i];
        }
        int up = limit ? s[i] - '0' : 9;
        int ans = 0;
        for (int j = 0; j <= up; ++j) {
            if (j == 0 && lead) {
                ans += dfs(i + 1, true, limit && j == up);
            } else if (nums.contains(j)) {
                ans += dfs(i + 1, false, limit && j == up);
            }
        }
        if (!lead && !limit) {
            f[i] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        unordered_set<int> nums;
        for (auto& x : digits) {
            nums.insert(stoi(x));
        }
        int m = s.size();
        int f[m];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int i, bool lead, bool limit) -> int {
            if (i >= m) {
                return lead ? 0 : 1;
            }
            if (!lead && !limit && f[i] != -1) {
                return f[i];
            }
            int up = limit ? s[i] - '0' : 9;
            int ans = 0;
            for (int j = 0; j <= up; ++j) {
                if (j == 0 && lead) {
                    ans += dfs(i + 1, true, limit && j == up);
                } else if (nums.count(j)) {
                    ans += dfs(i + 1, false, limit && j == up);
                }
            }
            if (!lead && !limit) {
                f[i] = ans;
            }
            return ans;
        };
        return dfs(0, true, true);
    }
};
```

#### Go

```go
func atMostNGivenDigitSet(digits []string, n int) int {
	s := strconv.Itoa(n)
	m := len(s)
	f := make([]int, m)
	for i := range f {
		f[i] = -1
	}
	nums := map[int]bool{}
	for _, d := range digits {
		x, _ := strconv.Atoi(d)
		nums[x] = true
	}
	var dfs func(i int, lead, limit bool) int
	dfs = func(i int, lead, limit bool) int {
		if i >= m {
			if lead {
				return 0
			}
			return 1
		}
		if !lead && !limit && f[i] != -1 {
			return f[i]
		}
		up := 9
		if limit {
			up = int(s[i] - '0')
		}
		ans := 0
		for j := 0; j <= up; j++ {
			if j == 0 && lead {
				ans += dfs(i+1, true, limit && j == up)
			} else if nums[j] {
				ans += dfs(i+1, false, limit && j == up)
			}
		}
		if !lead && !limit {
			f[i] = ans
		}
		return ans
	}
	return dfs(0, true, true)
}
```

#### TypeScript

```ts
function atMostNGivenDigitSet(digits: string[], n: number): number {
    const s = n.toString();
    const m = s.length;
    const f: number[] = Array(m).fill(-1);
    const nums = new Set<number>(digits.map(d => parseInt(d)));
    const dfs = (i: number, lead: boolean, limit: boolean): number => {
        if (i >= m) {
            return lead ? 0 : 1;
        }
        if (!lead && !limit && f[i] !== -1) {
            return f[i];
        }
        const up = limit ? +s[i] : 9;
        let ans = 0;
        for (let j = 0; j <= up; ++j) {
            if (!j && lead) {
                ans += dfs(i + 1, true, limit && j === up);
            } else if (nums.has(j)) {
                ans += dfs(i + 1, false, limit && j === up);
            }
        }
        if (!lead && !limit) {
            f[i] = ans;
        }
        return ans;
    };
    return dfs(0, true, true);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [903. DI 序列的有效排列](https://leetcode.cn/problems/valid-permutations-for-di-sequence){#903}

{{< tabs "903" >}}

{{% tab "python" %}}
```python
class Solution:
    def numPermsDISequence(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        f = [1] + [0] * n
        for i, c in enumerate(s, 1):
            pre = 0
            g = [0] * (n + 1)
            if c == "D":
                for j in range(i, -1, -1):
                    pre = (pre + f[j]) % mod
                    g[j] = pre
            else:
                for j in range(i + 1):
                    g[j] = pre
                    pre = (pre + f[j]) % mod
            f = g
        return sum(f) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numPermsDISequence(String s) {
        final int mod = (int) 1e9 + 7;
        int n = s.length();
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int pre = 0;
            int[] g = new int[n + 1];
            if (s.charAt(i - 1) == 'D') {
                for (int j = i; j >= 0; --j) {
                    pre = (pre + f[j]) % mod;
                    g[j] = pre;
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    g[j] = pre;
                    pre = (pre + f[j]) % mod;
                }
            }
            f = g;
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[j]) % mod;
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
    int numPermsDISequence(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int pre = 0;
            vector<int> g(n + 1);
            if (s[i - 1] == 'D') {
                for (int j = i; j >= 0; --j) {
                    pre = (pre + f[j]) % mod;
                    g[j] = pre;
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    g[j] = pre;
                    pre = (pre + f[j]) % mod;
                }
            }
            f = move(g);
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[j]) % mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numPermsDISequence(s string) (ans int) {
	const mod = 1e9 + 7
	n := len(s)
	f := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		pre := 0
		g := make([]int, n+1)
		if s[i-1] == 'D' {
			for j := i; j >= 0; j-- {
				pre = (pre + f[j]) % mod
				g[j] = pre
			}
		} else {
			for j := 0; j <= i; j++ {
				g[j] = pre
				pre = (pre + f[j]) % mod
			}
		}
		f = g
	}
	for j := 0; j <= n; j++ {
		ans = (ans + f[j]) % mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numPermsDISequence(s: string): number {
    const n = s.length;
    let f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    const mod = 10 ** 9 + 7;
    for (let i = 1; i <= n; ++i) {
        let pre = 0;
        const g: number[] = Array(n + 1).fill(0);
        if (s[i - 1] === 'D') {
            for (let j = i; j >= 0; --j) {
                pre = (pre + f[j]) % mod;
                g[j] = pre;
            }
        } else {
            for (let j = 0; j <= i; ++j) {
                g[j] = pre;
                pre = (pre + f[j]) % mod;
            }
        }
        f = g;
    }
    let ans = 0;
    for (let j = 0; j <= n; ++j) {
        ans = (ans + f[j]) % mod;
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

<p>给定一个长度为 <code>n</code> 的字符串 <code>s</code> ，其中 <code>s[i]</code> 是:</p>

<ul>
	<li><code>“D”</code> 意味着减少，或者</li>
	<li><code>“I”</code> 意味着增加</li>
</ul>

<p><strong>有效排列</strong>&nbsp;是对有&nbsp;<code>n + 1</code>&nbsp;个在&nbsp;<code>[0, n]</code>&nbsp; 范围内的整数的一个排列&nbsp;<code>perm</code>&nbsp;，使得对所有的&nbsp;<code>i</code>：</p>

<ul>
	<li>如果 <code>s[i] == 'D'</code>，那么&nbsp;<code>perm[i] &gt; perm[i+1]</code>，以及；</li>
	<li>如果 <code>s[i] == 'I'</code>，那么 <code>perm[i] &lt; perm[i+1]</code>。</li>
</ul>

<p>返回 <em><strong>有效排列 </strong>&nbsp;</em><code>perm</code><em>的数量 </em>。因为答案可能很大，所以请<strong>返回你的答案对</strong>&nbsp;<code>10<sup>9</sup>&nbsp;+ 7</code><strong>&nbsp;取余</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "DID"
<strong>输出：</strong>5
<strong>解释：</strong>
(0, 1, 2, 3) 的五个有效排列是：
(1, 0, 3, 2)
(2, 0, 3, 1)
(2, 1, 3, 0)
(3, 0, 2, 1)
(3, 1, 2, 0)
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> s = "D"
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>s[i]</code>&nbsp;不是&nbsp;<code>'I'</code>&nbsp;就是&nbsp;<code>'D'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示字符串的前 $i$ 个字符中，以数字 $j$ 结尾的满足题目要求的排列的数量。初始时 $f[0][0]=1$，其余 $f[0][j]=0$。答案为 $\sum_{j=0}^n f[n][j]$。

考虑 $f[i][j]$，其中 $j \in [0, i]$。

如果第 $i$ 个字符 $s[i-1]$ 是 `'D'`，那么 $f[i][j]$ 可以从 $f[i-1][k]$ 转移而来，其中 $k \in [j+1, i]$，而由于 $k-1$ 最大只能为 $i-1$，我们将 $k$ 向左移动一位，那么 $k \in [j, i-1]$，因此有 $f[i][j] = \sum_{k=j}^{i-1} f[i-1][k]$。

如果第 $i$ 个字符 $s[i-1]$ 是 `'I'`，那么 $f[i][j]$ 可以从 $f[i-1][k]$ 转移而来，其中 $k \in [0, j-1]$，因此有 $f[i][j] = \sum_{k=0}^{j-1} f[i-1][k]$。

最终的答案即为 $\sum_{j=0}^n f[n][j]$。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^2)$。其中 $n$ 是字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numPermsDISequence(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        f = [[0] * (n + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i, c in enumerate(s, 1):
            if c == "D":
                for j in range(i + 1):
                    for k in range(j, i):
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod
            else:
                for j in range(i + 1):
                    for k in range(j):
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod
        return sum(f[n][j] for j in range(n + 1)) % mod
```

#### Java

```java
class Solution {
    public int numPermsDISequence(String s) {
        final int mod = (int) 1e9 + 7;
        int n = s.length();
        int[][] f = new int[n + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s.charAt(i - 1) == 'D') {
                for (int j = 0; j <= i; ++j) {
                    for (int k = j; k < i; ++k) {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    for (int k = 0; k < j; ++k) {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[n][j]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numPermsDISequence(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'D') {
                for (int j = 0; j <= i; ++j) {
                    for (int k = j; k < i; ++k) {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    for (int k = 0; k < j; ++k) {
                        f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[n][j]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numPermsDISequence(s string) (ans int) {
	const mod = 1e9 + 7
	n := len(s)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		if s[i-1] == 'D' {
			for j := 0; j <= i; j++ {
				for k := j; k < i; k++ {
					f[i][j] = (f[i][j] + f[i-1][k]) % mod
				}
			}
		} else {
			for j := 0; j <= i; j++ {
				for k := 0; k < j; k++ {
					f[i][j] = (f[i][j] + f[i-1][k]) % mod
				}
			}
		}
	}
	for j := 0; j <= n; j++ {
		ans = (ans + f[n][j]) % mod
	}
	return
}
```

#### TypeScript

```ts
function numPermsDISequence(s: string): number {
    const n = s.length;
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    f[0][0] = 1;
    const mod = 10 ** 9 + 7;
    for (let i = 1; i <= n; ++i) {
        if (s[i - 1] === 'D') {
            for (let j = 0; j <= i; ++j) {
                for (let k = j; k < i; ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        } else {
            for (let j = 0; j <= i; ++j) {
                for (let k = 0; k < j; ++k) {
                    f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
                }
            }
        }
    }
    let ans = 0;
    for (let j = 0; j <= n; ++j) {
        ans = (ans + f[n][j]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

我们可以用前缀和优化时间复杂度，使得时间复杂度降低到 $O(n^2)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numPermsDISequence(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        f = [[0] * (n + 1) for _ in range(n + 1)]
        f[0][0] = 1
        for i, c in enumerate(s, 1):
            pre = 0
            if c == "D":
                for j in range(i, -1, -1):
                    pre = (pre + f[i - 1][j]) % mod
                    f[i][j] = pre
            else:
                for j in range(i + 1):
                    f[i][j] = pre
                    pre = (pre + f[i - 1][j]) % mod
        return sum(f[n][j] for j in range(n + 1)) % mod
```

#### Java

```java
class Solution {
    public int numPermsDISequence(String s) {
        final int mod = (int) 1e9 + 7;
        int n = s.length();
        int[][] f = new int[n + 1][n + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int pre = 0;
            if (s.charAt(i - 1) == 'D') {
                for (int j = i; j >= 0; --j) {
                    pre = (pre + f[i - 1][j]) % mod;
                    f[i][j] = pre;
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    f[i][j] = pre;
                    pre = (pre + f[i - 1][j]) % mod;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[n][j]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numPermsDISequence(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();
        int f[n + 1][n + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            int pre = 0;
            if (s[i - 1] == 'D') {
                for (int j = i; j >= 0; --j) {
                    pre = (pre + f[i - 1][j]) % mod;
                    f[i][j] = pre;
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    f[i][j] = pre;
                    pre = (pre + f[i - 1][j]) % mod;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[n][j]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numPermsDISequence(s string) (ans int) {
	const mod = 1e9 + 7
	n := len(s)
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, n+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		pre := 0
		if s[i-1] == 'D' {
			for j := i; j >= 0; j-- {
				pre = (pre + f[i-1][j]) % mod
				f[i][j] = pre
			}
		} else {
			for j := 0; j <= i; j++ {
				f[i][j] = pre
				pre = (pre + f[i-1][j]) % mod
			}
		}
	}
	for j := 0; j <= n; j++ {
		ans = (ans + f[n][j]) % mod
	}
	return
}
```

#### TypeScript

```ts
function numPermsDISequence(s: string): number {
    const n = s.length;
    const f: number[][] = Array(n + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(0));
    f[0][0] = 1;
    const mod = 10 ** 9 + 7;
    for (let i = 1; i <= n; ++i) {
        let pre = 0;
        if (s[i - 1] === 'D') {
            for (let j = i; j >= 0; --j) {
                pre = (pre + f[i - 1][j]) % mod;
                f[i][j] = pre;
            }
        } else {
            for (let j = 0; j <= i; ++j) {
                f[i][j] = pre;
                pre = (pre + f[i - 1][j]) % mod;
            }
        }
    }
    let ans = 0;
    for (let j = 0; j <= n; ++j) {
        ans = (ans + f[n][j]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

另外，我们也可以用滚动数组优化空间复杂度，使得空间复杂度降低到 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numPermsDISequence(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        f = [1] + [0] * n
        for i, c in enumerate(s, 1):
            pre = 0
            g = [0] * (n + 1)
            if c == "D":
                for j in range(i, -1, -1):
                    pre = (pre + f[j]) % mod
                    g[j] = pre
            else:
                for j in range(i + 1):
                    g[j] = pre
                    pre = (pre + f[j]) % mod
            f = g
        return sum(f) % mod
```

#### Java

```java
class Solution {
    public int numPermsDISequence(String s) {
        final int mod = (int) 1e9 + 7;
        int n = s.length();
        int[] f = new int[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int pre = 0;
            int[] g = new int[n + 1];
            if (s.charAt(i - 1) == 'D') {
                for (int j = i; j >= 0; --j) {
                    pre = (pre + f[j]) % mod;
                    g[j] = pre;
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    g[j] = pre;
                    pre = (pre + f[j]) % mod;
                }
            }
            f = g;
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[j]) % mod;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numPermsDISequence(string s) {
        const int mod = 1e9 + 7;
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int pre = 0;
            vector<int> g(n + 1);
            if (s[i - 1] == 'D') {
                for (int j = i; j >= 0; --j) {
                    pre = (pre + f[j]) % mod;
                    g[j] = pre;
                }
            } else {
                for (int j = 0; j <= i; ++j) {
                    g[j] = pre;
                    pre = (pre + f[j]) % mod;
                }
            }
            f = move(g);
        }
        int ans = 0;
        for (int j = 0; j <= n; ++j) {
            ans = (ans + f[j]) % mod;
        }
        return ans;
    }
};
```

#### Go

```go
func numPermsDISequence(s string) (ans int) {
	const mod = 1e9 + 7
	n := len(s)
	f := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		pre := 0
		g := make([]int, n+1)
		if s[i-1] == 'D' {
			for j := i; j >= 0; j-- {
				pre = (pre + f[j]) % mod
				g[j] = pre
			}
		} else {
			for j := 0; j <= i; j++ {
				g[j] = pre
				pre = (pre + f[j]) % mod
			}
		}
		f = g
	}
	for j := 0; j <= n; j++ {
		ans = (ans + f[j]) % mod
	}
	return
}
```

#### TypeScript

```ts
function numPermsDISequence(s: string): number {
    const n = s.length;
    let f: number[] = Array(n + 1).fill(0);
    f[0] = 1;
    const mod = 10 ** 9 + 7;
    for (let i = 1; i <= n; ++i) {
        let pre = 0;
        const g: number[] = Array(n + 1).fill(0);
        if (s[i - 1] === 'D') {
            for (let j = i; j >= 0; --j) {
                pre = (pre + f[j]) % mod;
                g[j] = pre;
            }
        } else {
            for (let j = 0; j <= i; ++j) {
                g[j] = pre;
                pre = (pre + f[j]) % mod;
            }
        }
        f = g;
    }
    let ans = 0;
    for (let j = 0; j <= n; ++j) {
        ans = (ans + f[j]) % mod;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [904. 水果成篮](https://leetcode.cn/problems/fruit-into-baskets){#904}

{{< tabs "904" >}}

{{% tab "python" %}}
```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cnt = Counter()
        j = 0
        for x in fruits:
            cnt[x] += 1
            if len(cnt) > 2:
                y = fruits[j]
                cnt[y] -= 1
                if cnt[y] == 0:
                    cnt.pop(y)
                j += 1
        return len(fruits) - j
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int j = 0, n = fruits.length;
        for (int x : fruits) {
            cnt.merge(x, 1, Integer::sum);
            if (cnt.size() > 2) {
                int y = fruits[j++];
                if (cnt.merge(y, -1, Integer::sum) == 0) {
                    cnt.remove(y);
                }
            }
        }
        return n - j;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int j = 0, n = fruits.size();
        for (int& x : fruits) {
            ++cnt[x];
            if (cnt.size() > 2) {
                int y = fruits[j++];
                if (--cnt[y] == 0) {
                    cnt.erase(y);
                }
            }
        }
        return n - j;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func totalFruit(fruits []int) int {
	cnt := map[int]int{}
	j := 0
	for _, x := range fruits {
		cnt[x]++
		if len(cnt) > 2 {
			y := fruits[j]
			cnt[y]--
			if cnt[y] == 0 {
				delete(cnt, y)
			}
			j++
		}
	}
	return len(fruits) - j
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function totalFruit(fruits: number[]): number {
    const n = fruits.length;
    const cnt: Map<number, number> = new Map();
    let j = 0;
    for (const x of fruits) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
        if (cnt.size > 2) {
            cnt.set(fruits[j], cnt.get(fruits[j])! - 1);
            if (!cnt.get(fruits[j])) {
                cnt.delete(fruits[j]);
            }
            ++j;
        }
    }
    return n - j;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        let mut j = 0;
        let n = fruits.len();

        for &x in &fruits {
            *cnt.entry(x).or_insert(0) += 1;
            if cnt.len() > 2 {
                let y = fruits[j];
                j += 1;
                *cnt.get_mut(&y).unwrap() -= 1;
                if cnt[&y] == 0 {
                    cnt.remove(&y);
                }
            }
        }

        (n - j) as i32
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int TotalFruit(int[] fruits) {
        var cnt = new Dictionary<int, int>();
        int j = 0, n = fruits.Length;
        foreach (int x in fruits) {
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }

            if (cnt.Count > 2) {
                int y = fruits[j++];
                if (cnt.ContainsKey(y)) {
                    cnt[y]--;
                    if (cnt[y] == 0) {
                        cnt.Remove(y);
                    }
                }
            }
        }
        return n - j;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 <code>fruits</code> 表示，其中 <code>fruits[i]</code> 是第 <code>i</code> 棵树上的水果 <strong>种类</strong> 。</p>

<p>你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：</p>

<ul>
	<li>你只有 <strong>两个</strong> 篮子，并且每个篮子只能装 <strong>单一类型</strong> 的水果。每个篮子能够装的水果总量没有限制。</li>
	<li>你可以选择任意一棵树开始采摘，你必须从 <strong>每棵</strong> 树（包括开始采摘的树）上 <strong>恰好摘一个水果</strong> 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。</li>
	<li>一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。</li>
</ul>

<p>给你一个整数数组 <code>fruits</code> ，返回你可以收集的水果的 <strong>最大</strong> 数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>fruits = [<em><strong>1,2,1</strong></em>]
<strong>输出：</strong>3
<strong>解释：</strong>可以采摘全部 3 棵树。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>fruits = [0,<em><strong>1,2,2</strong></em>]
<strong>输出：</strong>3
<strong>解释：</strong>可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>fruits = [1,<em><strong>2,3,2,2</strong></em>]
<strong>输出：</strong>4
<strong>解释：</strong>可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>fruits = [3,3,3,<em><strong>1,2,1,1,2</strong></em>,3,3,4]
<strong>输出：</strong>5
<strong>解释：</strong>可以采摘 [1,2,1,1,2] 这五棵树。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= fruits.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= fruits[i] &lt; fruits.length</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 滑动窗口

我们用哈希表 $\textit{cnt}$ 维护当前窗口内的水果种类以及对应的数量，用双指针 $j$ 和 $i$ 维护窗口的左右边界。

遍历数组 $\textit{fruits}$，将当前水果 $x$ 加入窗口，即 $\textit{cnt}[x]++$，然后判断当前窗口内的水果种类是否超过了 $2$ 种，如果超过了 $2$ 种，就需要将窗口的左边界 $j$ 右移，直到窗口内的水果种类不超过 $2$ 种为止。然后更新答案，即 $\textit{ans} = \max(\textit{ans}, i - j + 1)$。

遍历结束后，即可得到最终的答案。

```
1 2 3 2 2 1 4
^   ^
j   i


1 2 3 2 2 1 4
  ^ ^
  j i


1 2 3 2 2 1 4
  ^     ^
  j     i
```

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{fruits}$ 的长度。空间复杂度 $O(1)$，因为哈希表 $\textit{cnt}$ 中的键值对数量最多为 $2$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cnt = Counter()
        ans = j = 0
        for i, x in enumerate(fruits):
            cnt[x] += 1
            while len(cnt) > 2:
                y = fruits[j]
                cnt[y] -= 1
                if cnt[y] == 0:
                    cnt.pop(y)
                j += 1
            ans = max(ans, i - j + 1)
        return ans
```

#### Java

```java
class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int i = 0, j = 0; i < fruits.length; ++i) {
            int x = fruits[i];
            cnt.merge(x, 1, Integer::sum);
            while (cnt.size() > 2) {
                int y = fruits[j++];
                if (cnt.merge(y, -1, Integer::sum) == 0) {
                    cnt.remove(y);
                }
            }
            ans = Math.max(ans, i - j + 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0, j = 0; i < fruits.size(); ++i) {
            int x = fruits[i];
            ++cnt[x];
            while (cnt.size() > 2) {
                int y = fruits[j++];
                if (--cnt[y] == 0) {
                    cnt.erase(y);
                }
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```

#### Go

```go
func totalFruit(fruits []int) int {
	cnt := map[int]int{}
	ans, j := 0, 0
	for i, x := range fruits {
		cnt[x]++
		for ; len(cnt) > 2; j++ {
			y := fruits[j]
			cnt[y]--
			if cnt[y] == 0 {
				delete(cnt, y)
			}
		}
		ans = max(ans, i-j+1)
	}
	return ans
}
```

#### TypeScript

```ts
function totalFruit(fruits: number[]): number {
    const n = fruits.length;
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0, j = 0; i < n; ++i) {
        cnt.set(fruits[i], (cnt.get(fruits[i]) || 0) + 1);
        for (; cnt.size > 2; ++j) {
            cnt.set(fruits[j], cnt.get(fruits[j])! - 1);
            if (!cnt.get(fruits[j])) {
                cnt.delete(fruits[j]);
            }
        }
        ans = Math.max(ans, i - j + 1);
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        let mut ans = 0;
        let mut j = 0;

        for (i, &x) in fruits.iter().enumerate() {
            *cnt.entry(x).or_insert(0) += 1;

            while cnt.len() > 2 {
                let y = fruits[j];
                j += 1;
                *cnt.get_mut(&y).unwrap() -= 1;
                if cnt[&y] == 0 {
                    cnt.remove(&y);
                }
            }

            ans = ans.max(i - j + 1);
        }

        ans as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int TotalFruit(int[] fruits) {
        var cnt = new Dictionary<int, int>();
        int ans = 0;
        for (int i = 0, j = 0; i < fruits.Length; ++i) {
            int x = fruits[i];
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }
            while (cnt.Count > 2) {
                int y = fruits[j++];
                if (cnt.ContainsKey(y)) {
                    cnt[y]--;
                    if (cnt[y] == 0) {
                        cnt.Remove(y);
                    }
                }
            }
            ans = Math.Max(ans, i - j + 1);
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：单调变长滑动窗口

在方法一中，我们发现，窗口大小会时而变大，时而变小，这就需要我们每一次更新答案。

但本题实际上求的是水果的最大数目，也就是“最大”的窗口，我们没有必要缩小窗口，只需要让窗口单调增大。于是代码就少了每次更新答案的操作，只需要在遍历结束后将此时的窗口大小作为答案返回即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{fruits}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cnt = Counter()
        j = 0
        for x in fruits:
            cnt[x] += 1
            if len(cnt) > 2:
                y = fruits[j]
                cnt[y] -= 1
                if cnt[y] == 0:
                    cnt.pop(y)
                j += 1
        return len(fruits) - j
```

#### Java

```java
class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int j = 0, n = fruits.length;
        for (int x : fruits) {
            cnt.merge(x, 1, Integer::sum);
            if (cnt.size() > 2) {
                int y = fruits[j++];
                if (cnt.merge(y, -1, Integer::sum) == 0) {
                    cnt.remove(y);
                }
            }
        }
        return n - j;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int j = 0, n = fruits.size();
        for (int& x : fruits) {
            ++cnt[x];
            if (cnt.size() > 2) {
                int y = fruits[j++];
                if (--cnt[y] == 0) {
                    cnt.erase(y);
                }
            }
        }
        return n - j;
    }
};
```

#### Go

```go
func totalFruit(fruits []int) int {
	cnt := map[int]int{}
	j := 0
	for _, x := range fruits {
		cnt[x]++
		if len(cnt) > 2 {
			y := fruits[j]
			cnt[y]--
			if cnt[y] == 0 {
				delete(cnt, y)
			}
			j++
		}
	}
	return len(fruits) - j
}
```

#### TypeScript

```ts
function totalFruit(fruits: number[]): number {
    const n = fruits.length;
    const cnt: Map<number, number> = new Map();
    let j = 0;
    for (const x of fruits) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
        if (cnt.size > 2) {
            cnt.set(fruits[j], cnt.get(fruits[j])! - 1);
            if (!cnt.get(fruits[j])) {
                cnt.delete(fruits[j]);
            }
            ++j;
        }
    }
    return n - j;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut cnt = HashMap::new();
        let mut j = 0;
        let n = fruits.len();

        for &x in &fruits {
            *cnt.entry(x).or_insert(0) += 1;
            if cnt.len() > 2 {
                let y = fruits[j];
                j += 1;
                *cnt.get_mut(&y).unwrap() -= 1;
                if cnt[&y] == 0 {
                    cnt.remove(&y);
                }
            }
        }

        (n - j) as i32
    }
}
```

#### C#

```cs
public class Solution {
    public int TotalFruit(int[] fruits) {
        var cnt = new Dictionary<int, int>();
        int j = 0, n = fruits.Length;
        foreach (int x in fruits) {
            if (cnt.ContainsKey(x)) {
                cnt[x]++;
            } else {
                cnt[x] = 1;
            }

            if (cnt.Count > 2) {
                int y = fruits[j++];
                if (cnt.ContainsKey(y)) {
                    cnt[y]--;
                    if (cnt[y] == 0) {
                        cnt.Remove(y);
                    }
                }
            }
        }
        return n - j;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [905. 按奇偶排序数组](https://leetcode.cn/problems/sort-array-by-parity){#905}

{{< tabs "905" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            if nums[i] % 2 == 0:
                i += 1
            elif nums[j] % 2 == 1:
                j -= 1
            else:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1
        return nums
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int i = 0, j = nums.length - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                ++i;
            } else if (nums[j] % 2 == 1) {
                --j;
            } else {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                ++i;
                --j;
            }
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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                ++i;
            } else if (nums[j] % 2 == 1) {
                --j;
            } else {
                swap(nums[i++], nums[j--]);
            }
        }
        return nums;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortArrayByParity(nums []int) []int {
	for i, j := 0, len(nums)-1; i < j; {
		if nums[i]%2 == 0 {
			i++
		} else if nums[j]%2 == 1 {
			j--
		} else {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return nums
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortArrayByParity(nums: number[]): number[] {
    for (let i = 0, j = nums.length - 1; i < j; ) {
        if (nums[i] % 2 === 0) {
            ++i;
        } else if (nums[j] % 2 === 1) {
            --j;
        } else {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            ++i;
            --j;
        }
    }
    return nums;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_array_by_parity(mut nums: Vec<i32>) -> Vec<i32> {
        let (mut i, mut j) = (0, nums.len() - 1);
        while i < j {
            if nums[i] % 2 == 0 {
                i += 1;
            } else if nums[j] % 2 == 1 {
                j -= 1;
            } else {
                nums.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        nums
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function (nums) {
    for (let i = 0, j = nums.length - 1; i < j; ) {
        if (nums[i] % 2 === 0) {
            ++i;
        } else if (nums[j] % 2 === 1) {
            --j;
        } else {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            ++i;
            --j;
        }
    }
    return nums;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，将 <code>nums</code> 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。</p>

<p>返回满足此条件的 <strong>任一数组</strong> 作为答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,1,2,4]
<strong>输出：</strong>[2,4,3,1]
<strong>解释：</strong>[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0]
<strong>输出：</strong>[0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$ 分别指向数组的首尾，当 $i < j$ 时，执行以下操作。

-   如果 $nums[i]$ 为偶数，则 $i$ 自增 $1$。
-   如果 $nums[j]$ 为奇数，则 $j$ 自减 $1$。
-   如果 $nums[i]$ 为奇数，且 $nums[j]$ 为偶数，则交换 $nums[i]$ 和 $nums[j]$。然后 $i$ 自增 $1$，而 $j$ 自减 $1$。

最后返回数组 $nums$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            if nums[i] % 2 == 0:
                i += 1
            elif nums[j] % 2 == 1:
                j -= 1
            else:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1
        return nums
```

#### Java

```java
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int i = 0, j = nums.length - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                ++i;
            } else if (nums[j] % 2 == 1) {
                --j;
            } else {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                ++i;
                --j;
            }
        }
        return nums;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] % 2 == 0) {
                ++i;
            } else if (nums[j] % 2 == 1) {
                --j;
            } else {
                swap(nums[i++], nums[j--]);
            }
        }
        return nums;
    }
};
```

#### Go

```go
func sortArrayByParity(nums []int) []int {
	for i, j := 0, len(nums)-1; i < j; {
		if nums[i]%2 == 0 {
			i++
		} else if nums[j]%2 == 1 {
			j--
		} else {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	return nums
}
```

#### TypeScript

```ts
function sortArrayByParity(nums: number[]): number[] {
    for (let i = 0, j = nums.length - 1; i < j; ) {
        if (nums[i] % 2 === 0) {
            ++i;
        } else if (nums[j] % 2 === 1) {
            --j;
        } else {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            ++i;
            --j;
        }
    }
    return nums;
}
```

#### Rust

```rust
impl Solution {
    pub fn sort_array_by_parity(mut nums: Vec<i32>) -> Vec<i32> {
        let (mut i, mut j) = (0, nums.len() - 1);
        while i < j {
            if nums[i] % 2 == 0 {
                i += 1;
            } else if nums[j] % 2 == 1 {
                j -= 1;
            } else {
                nums.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        nums
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArrayByParity = function (nums) {
    for (let i = 0, j = nums.length - 1; i < j; ) {
        if (nums[i] % 2 === 0) {
            ++i;
        } else if (nums[j] % 2 === 1) {
            --j;
        } else {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            ++i;
            --j;
        }
    }
    return nums;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [906. 超级回文数](https://leetcode.cn/problems/super-palindromes){#906}

{{< tabs "906" >}}

{{% tab "python" %}}
```python
ps = []
for i in range(1, 10**5 + 1):
    s = str(i)
    t1 = s[::-1]
    t2 = s[:-1][::-1]
    ps.append(int(s + t1))
    ps.append(int(s + t2))


class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        def is_palindrome(x: int) -> bool:
            y, t = 0, x
            while t:
                y = y * 10 + t % 10
                t //= 10
            return x == y

        l, r = int(left), int(right)
        return sum(l <= x <= r and is_palindrome(x) for x in map(lambda x: x * x, ps))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static long[] ps;

    static {
        ps = new long[2 * (int) 1e5];
        for (int i = 1; i <= 1e5; i++) {
            String s = Integer.toString(i);
            String t1 = new StringBuilder(s).reverse().toString();
            String t2 = new StringBuilder(s.substring(0, s.length() - 1)).reverse().toString();
            ps[2 * i - 2] = Long.parseLong(s + t1);
            ps[2 * i - 1] = Long.parseLong(s + t2);
        }
    }

    public int superpalindromesInRange(String left, String right) {
        long l = Long.parseLong(left);
        long r = Long.parseLong(right);
        int ans = 0;
        for (long p : ps) {
            long x = p * p;
            if (x >= l && x <= r && isPalindrome(x)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean isPalindrome(long x) {
        long y = 0;
        for (long t = x; t > 0; t /= 10) {
            y = y * 10 + t % 10;
        }
        return x == y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = unsigned long long;

ll ps[2 * 100000];

int init = [] {
    for (int i = 1; i <= 100000; i++) {
        string s = to_string(i);
        string t1 = s;
        reverse(t1.begin(), t1.end());
        string t2 = s.substr(0, s.length() - 1);
        reverse(t2.begin(), t2.end());
        ps[2 * i - 2] = stoll(s + t1);
        ps[2 * i - 1] = stoll(s + t2);
    }
    return 0;
}();

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll l = stoll(left), r = stoll(right);
        int ans = 0;
        for (ll p : ps) {
            ll x = p * p;
            if (x >= l && x <= r && is_palindrome(x)) {
                ++ans;
            }
        }
        return ans;
    }

    bool is_palindrome(ll x) {
        ll y = 0;
        for (ll t = x; t; t /= 10) {
            y = y * 10 + t % 10;
        }
        return x == y;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
var ps [2 * 100000]int64

func init() {
	for i := 1; i <= 100000; i++ {
		s := strconv.Itoa(i)
		t1 := reverseString(s)
		t2 := reverseString(s[:len(s)-1])
		ps[2*i-2], _ = strconv.ParseInt(s+t1, 10, 64)
		ps[2*i-1], _ = strconv.ParseInt(s+t2, 10, 64)
	}
}

func reverseString(s string) string {
	cs := []rune(s)
	for i, j := 0, len(cs)-1; i < j; i, j = i+1, j-1 {
		cs[i], cs[j] = cs[j], cs[i]
	}
	return string(cs)
}

func superpalindromesInRange(left string, right string) (ans int) {
	l, _ := strconv.ParseInt(left, 10, 64)
	r, _ := strconv.ParseInt(right, 10, 64)
	isPalindrome := func(x int64) bool {
		var y int64
		for t := x; t > 0; t /= 10 {
			y = y*10 + int64(t%10)
		}
		return x == y
	}
	for _, p := range ps {
		x := p * p
		if x >= l && x <= r && isPalindrome(x) {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const ps = Array(2e5).fill(0);

const init = (() => {
    for (let i = 1; i <= 1e5; ++i) {
        const s: string = i.toString();
        const t1: string = s.split('').reverse().join('');
        const t2: string = s.slice(0, -1).split('').reverse().join('');
        ps[2 * i - 2] = parseInt(s + t1, 10);
        ps[2 * i - 1] = parseInt(s + t2, 10);
    }
})();

function superpalindromesInRange(left: string, right: string): number {
    const l = BigInt(left);
    const r = BigInt(right);
    const isPalindrome = (x: bigint): boolean => {
        const s: string = x.toString();
        return s === s.split('').reverse().join('');
    };
    let ans = 0;
    for (const p of ps) {
        const x = BigInt(p) * BigInt(p);
        if (x >= l && x <= r && isPalindrome(x)) {
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

<p>如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为 <strong>超级回文数</strong> 。</p>

<p>现在，给你两个以字符串形式表示的正整数 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="caret-color: rgb(199, 37, 78); font-size: 12.6px; background-color: rgb(249, 242, 244);">left</span></font>&nbsp;和 <font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="caret-color: rgb(199, 37, 78); font-size: 12.6px; background-color: rgb(249, 242, 244);">right</span></font>&nbsp; ，统计并返回区间&nbsp;<code>[left, right]</code> 中的 <strong>超级回文数</strong> 的数目。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>left = "4", right = "1000"
<b>输出：</b>4
<b>解释：</b>4、9、121 和 484 都是超级回文数。
注意 676 不是超级回文数：26 * 26 = 676 ，但是 26 不是回文数。
</pre>

<p><b>示例 2：</b></p>

<pre>
<b>输入：</b>left = "1", right = "2"
<b>输出：</b>1
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= left.length, right.length &lt;= 18</code></li>
	<li><code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;仅由数字（0 - 9）组成。</li>
	<li><code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;不含前导零。</li>
	<li><code>left</code>&nbsp;和&nbsp;<code>right</code>&nbsp;表示的整数在区间&nbsp;<code>[1, 10<sup>18</sup> - 1]</code> 内。</li>
	<li><code>left</code>&nbsp;小于等于&nbsp;<code>right</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 枚举

根据题目描述，我们假设超级回文数 $x = p^2 \in [1, 10^{18})$，其中 $p$ 是回文数，那么 $p \in [1, 10^9)$。我们可以枚举回文数 $p$ 的前半部分，然后将其翻转后拼接，得到所有的回文数，记录在数组 $ps$ 中。

接下来，我们遍历数组 $ps$，对于每个 $p$，我们计算 $p^2$，判断是否在区间 $[L, R]$ 中，同时判断 $p^2$ 是否是回文数，若是，答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(M^{\frac{1}{4}} \times \log M)$，空间复杂度 $O(M^{\frac{1}{4}})$。其中 $M$ 是 $L$ 和 $R$ 的上界，本题中 $M \leq 10^{18}$。

相似题目：

-   [2967. 使数组成为等数数组的最小代价](https://github.com/doocs/leetcode/blob/main/solution/2900-2999/2967.Minimum%20Cost%20to%20Make%20Array%20Equalindromic/README.md)

<!-- tabs:start -->

#### Python3

```python
ps = []
for i in range(1, 10**5 + 1):
    s = str(i)
    t1 = s[::-1]
    t2 = s[:-1][::-1]
    ps.append(int(s + t1))
    ps.append(int(s + t2))


class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        def is_palindrome(x: int) -> bool:
            y, t = 0, x
            while t:
                y = y * 10 + t % 10
                t //= 10
            return x == y

        l, r = int(left), int(right)
        return sum(l <= x <= r and is_palindrome(x) for x in map(lambda x: x * x, ps))
```

#### Java

```java
class Solution {
    private static long[] ps;

    static {
        ps = new long[2 * (int) 1e5];
        for (int i = 1; i <= 1e5; i++) {
            String s = Integer.toString(i);
            String t1 = new StringBuilder(s).reverse().toString();
            String t2 = new StringBuilder(s.substring(0, s.length() - 1)).reverse().toString();
            ps[2 * i - 2] = Long.parseLong(s + t1);
            ps[2 * i - 1] = Long.parseLong(s + t2);
        }
    }

    public int superpalindromesInRange(String left, String right) {
        long l = Long.parseLong(left);
        long r = Long.parseLong(right);
        int ans = 0;
        for (long p : ps) {
            long x = p * p;
            if (x >= l && x <= r && isPalindrome(x)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean isPalindrome(long x) {
        long y = 0;
        for (long t = x; t > 0; t /= 10) {
            y = y * 10 + t % 10;
        }
        return x == y;
    }
}
```

#### C++

```cpp
using ll = unsigned long long;

ll ps[2 * 100000];

int init = [] {
    for (int i = 1; i <= 100000; i++) {
        string s = to_string(i);
        string t1 = s;
        reverse(t1.begin(), t1.end());
        string t2 = s.substr(0, s.length() - 1);
        reverse(t2.begin(), t2.end());
        ps[2 * i - 2] = stoll(s + t1);
        ps[2 * i - 1] = stoll(s + t2);
    }
    return 0;
}();

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        ll l = stoll(left), r = stoll(right);
        int ans = 0;
        for (ll p : ps) {
            ll x = p * p;
            if (x >= l && x <= r && is_palindrome(x)) {
                ++ans;
            }
        }
        return ans;
    }

    bool is_palindrome(ll x) {
        ll y = 0;
        for (ll t = x; t; t /= 10) {
            y = y * 10 + t % 10;
        }
        return x == y;
    }
};
```

#### Go

```go
var ps [2 * 100000]int64

func init() {
	for i := 1; i <= 100000; i++ {
		s := strconv.Itoa(i)
		t1 := reverseString(s)
		t2 := reverseString(s[:len(s)-1])
		ps[2*i-2], _ = strconv.ParseInt(s+t1, 10, 64)
		ps[2*i-1], _ = strconv.ParseInt(s+t2, 10, 64)
	}
}

func reverseString(s string) string {
	cs := []rune(s)
	for i, j := 0, len(cs)-1; i < j; i, j = i+1, j-1 {
		cs[i], cs[j] = cs[j], cs[i]
	}
	return string(cs)
}

func superpalindromesInRange(left string, right string) (ans int) {
	l, _ := strconv.ParseInt(left, 10, 64)
	r, _ := strconv.ParseInt(right, 10, 64)
	isPalindrome := func(x int64) bool {
		var y int64
		for t := x; t > 0; t /= 10 {
			y = y*10 + int64(t%10)
		}
		return x == y
	}
	for _, p := range ps {
		x := p * p
		if x >= l && x <= r && isPalindrome(x) {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
const ps = Array(2e5).fill(0);

const init = (() => {
    for (let i = 1; i <= 1e5; ++i) {
        const s: string = i.toString();
        const t1: string = s.split('').reverse().join('');
        const t2: string = s.slice(0, -1).split('').reverse().join('');
        ps[2 * i - 2] = parseInt(s + t1, 10);
        ps[2 * i - 1] = parseInt(s + t2, 10);
    }
})();

function superpalindromesInRange(left: string, right: string): number {
    const l = BigInt(left);
    const r = BigInt(right);
    const isPalindrome = (x: bigint): boolean => {
        const s: string = x.toString();
        return s === s.split('').reverse().join('');
    };
    let ans = 0;
    for (const p of ps) {
        const x = BigInt(p) * BigInt(p);
        if (x >= l && x <= r && isPalindrome(x)) {
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

# [907. 子数组的最小值之和](https://leetcode.cn/problems/sum-of-subarray-minimums){#907}

{{< tabs "907" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(arr):
            while stk and arr[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)

        stk = []
        for i in range(n - 1, -1, -1):
            while stk and arr[stk[-1]] > arr[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        mod = 10**9 + 7
        return sum((i - left[i]) * (right[i] - i) * v for i, v in enumerate(arr)) % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && arr[stk.peek()] > arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long) (i - left[i]) * (right[i] - i) % mod * arr[i] % mod;
            ans %= mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumSubarrayMins(arr []int) (ans int) {
	n := len(arr)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, v := range arr {
		for len(stk) > 0 && arr[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && arr[stk[len(stk)-1]] > arr[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	const mod int = 1e9 + 7
	for i, v := range arr {
		ans += (i - left[i]) * (right[i] - i) * v % mod
		ans %= mod
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumSubarrayMins(arr: number[]): number {
    const n: number = arr.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length > 0 && arr[stk.at(-1)] >= arr[i]) {
            stk.pop();
        }
        if (stk.length > 0) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }

    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        while (stk.length > 0 && arr[stk.at(-1)] > arr[i]) {
            stk.pop();
        }
        if (stk.length > 0) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }

    const mod: number = 1e9 + 7;
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        ans += ((((i - left[i]) * (right[i] - i)) % mod) * arr[i]) % mod;
        ans %= mod;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::VecDeque;

impl Solution {
    pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut left = vec![-1; n];
        let mut right = vec![n as i32; n];
        let mut stk: VecDeque<usize> = VecDeque::new();

        for i in 0..n {
            while !stk.is_empty() && arr[*stk.back().unwrap()] >= arr[i] {
                stk.pop_back();
            }
            if let Some(&top) = stk.back() {
                left[i] = top as i32;
            }
            stk.push_back(i);
        }

        stk.clear();
        for i in (0..n).rev() {
            while !stk.is_empty() && arr[*stk.back().unwrap()] > arr[i] {
                stk.pop_back();
            }
            if let Some(&top) = stk.back() {
                right[i] = top as i32;
            }
            stk.push_back(i);
        }

        let MOD = 1_000_000_007;
        let mut ans: i64 = 0;
        for i in 0..n {
            ans += ((((right[i] - (i as i32)) * ((i as i32) - left[i])) as i64) * (arr[i] as i64))
                % MOD;
            ans %= MOD;
        }
        ans as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>arr</code>，找到 <code>min(b)</code> 的总和，其中 <code>b</code> 的范围为 <code>arr</code> 的每个（连续）子数组。</p>

<p>由于答案可能很大，因此<strong> 返回答案模 <code>10^9 + 7</code></strong> 。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>arr = [3,1,2,4]
<strong>输出：</strong>17
<strong>解释：
</strong>子数组为<strong> </strong>[3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>arr = [11,81,94,43,3]
<strong>输出：</strong>444
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= arr.length <= 3 * 10<sup>4</sup></code></li>
	<li><code>1 <= arr[i] <= 3 * 10<sup>4</sup></code></li>
</ul>

<p> </p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：单调栈

题目要求的是每个子数组的最小值之和，实际上相当于，对于每个元素 $arr[i]$，求以 $arr[i]$ 为最小值的子数组的个数，然后乘以 $arr[i]$，最后求和。

因此，题目的重点转换为：求以 $arr[i]$ 为最小值的子数组的个数。对于 $arr[i]$，我们找出其左边第一个小于 $arr[i]$ 的位置 $left[i]$，右侧第一个小于等于 $arr[i]$ 的位置 $right[i]$，则以 $arr[i]$ 为最小值的子数组的个数为 $(i - left[i]) \times (right[i] - i)$。

注意，这里为什么要求右侧第一个小于等于 $arr[i]$ 的位置 $right[i]$，而不是小于 $arr[i]$ 的位置呢？这是因为，如果是右侧第一个小于 $arr[i]$ 的位置 $right[i]$，则会导致重复计算。

我们可以举个例子来说明，对于以下数组：

下标为 $3$ 的元素大小为 $2$，左侧第一个小于 $2$ 的元素下标为 $0$，如果我们求右侧第一个小于 $2$ 的元素下标，可以得到下标为 $7$。也即是说，子数组区间为 $(0, 7)$。注意，这里是开区间。

```
0 4 3 2 5 3 2 1
*     ^       *
```

按照同样的方法，我们可以求出下标为 $6$ 的元素的子数组区间，可以发现，其子数组区间也为 $(0, 7)$，也即是说，下标为 $3$ 和下标为 $6$ 的元素的子数组区间是重复的。这样就造成了重复计算。

```
0 4 3 2 5 3 2 1
*           ^ *
```

如果我们求的是右侧第一个小于等于其值的下标，就不会有重复问题，因为下标为 $3$ 的子数组区间变为 $(0, 6)$，下标为 $6$ 的子数组区间为 $(0, 7)$，两者不重复。

回到这道题上，我们只需要遍历数组，对于每个元素 $arr[i]$，利用单调栈求出其左侧第一个小于 $arr[i]$ 的位置 $left[i]$，右侧第一个小于等于 $arr[i]$ 的位置 $right[i]$，则以 $arr[i]$ 为最小值的子数组的个数为 $(i - left[i]) \times (right[i] - i)$，然后乘以 $arr[i]$，最后求和即可。

注意数据的溢出以及取模操作。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $arr$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        left = [-1] * n
        right = [n] * n
        stk = []
        for i, v in enumerate(arr):
            while stk and arr[stk[-1]] >= v:
                stk.pop()
            if stk:
                left[i] = stk[-1]
            stk.append(i)

        stk = []
        for i in range(n - 1, -1, -1):
            while stk and arr[stk[-1]] > arr[i]:
                stk.pop()
            if stk:
                right[i] = stk[-1]
            stk.append(i)
        mod = 10**9 + 7
        return sum((i - left[i]) * (right[i] - i) * v for i, v in enumerate(arr)) % mod
```

#### Java

```java
class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.fill(left, -1);
        Arrays.fill(right, n);
        Deque<Integer> stk = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            while (!stk.isEmpty() && arr[stk.peek()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                left[i] = stk.peek();
            }
            stk.push(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.isEmpty() && arr[stk.peek()] > arr[i]) {
                stk.pop();
            }
            if (!stk.isEmpty()) {
                right[i] = stk.peek();
            }
            stk.push(i);
        }
        final int mod = (int) 1e9 + 7;
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long) (i - left[i]) * (right[i] - i) % mod * arr[i] % mod;
            ans %= mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return ans;
    }
};
```

#### Go

```go
func sumSubarrayMins(arr []int) (ans int) {
	n := len(arr)
	left := make([]int, n)
	right := make([]int, n)
	for i := range left {
		left[i] = -1
		right[i] = n
	}
	stk := []int{}
	for i, v := range arr {
		for len(stk) > 0 && arr[stk[len(stk)-1]] >= v {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			left[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	stk = []int{}
	for i := n - 1; i >= 0; i-- {
		for len(stk) > 0 && arr[stk[len(stk)-1]] > arr[i] {
			stk = stk[:len(stk)-1]
		}
		if len(stk) > 0 {
			right[i] = stk[len(stk)-1]
		}
		stk = append(stk, i)
	}
	const mod int = 1e9 + 7
	for i, v := range arr {
		ans += (i - left[i]) * (right[i] - i) * v % mod
		ans %= mod
	}
	return
}
```

#### TypeScript

```ts
function sumSubarrayMins(arr: number[]): number {
    const n: number = arr.length;
    const left: number[] = Array(n).fill(-1);
    const right: number[] = Array(n).fill(n);
    const stk: number[] = [];
    for (let i = 0; i < n; ++i) {
        while (stk.length > 0 && arr[stk.at(-1)] >= arr[i]) {
            stk.pop();
        }
        if (stk.length > 0) {
            left[i] = stk.at(-1);
        }
        stk.push(i);
    }

    stk.length = 0;
    for (let i = n - 1; ~i; --i) {
        while (stk.length > 0 && arr[stk.at(-1)] > arr[i]) {
            stk.pop();
        }
        if (stk.length > 0) {
            right[i] = stk.at(-1);
        }
        stk.push(i);
    }

    const mod: number = 1e9 + 7;
    let ans: number = 0;
    for (let i = 0; i < n; ++i) {
        ans += ((((i - left[i]) * (right[i] - i)) % mod) * arr[i]) % mod;
        ans %= mod;
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::VecDeque;

impl Solution {
    pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut left = vec![-1; n];
        let mut right = vec![n as i32; n];
        let mut stk: VecDeque<usize> = VecDeque::new();

        for i in 0..n {
            while !stk.is_empty() && arr[*stk.back().unwrap()] >= arr[i] {
                stk.pop_back();
            }
            if let Some(&top) = stk.back() {
                left[i] = top as i32;
            }
            stk.push_back(i);
        }

        stk.clear();
        for i in (0..n).rev() {
            while !stk.is_empty() && arr[*stk.back().unwrap()] > arr[i] {
                stk.pop_back();
            }
            if let Some(&top) = stk.back() {
                right[i] = top as i32;
            }
            stk.push_back(i);
        }

        let MOD = 1_000_000_007;
        let mut ans: i64 = 0;
        for i in 0..n {
            ans += ((((right[i] - (i as i32)) * ((i as i32) - left[i])) as i64) * (arr[i] as i64))
                % MOD;
            ans %= MOD;
        }
        ans as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [908. 最小差值 I](https://leetcode.cn/problems/smallest-range-i){#908}

{{< tabs "908" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        mx, mi = max(nums), min(nums)
        return max(0, mx - mi - k * 2)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int smallestRangeI(int[] nums, int k) {
        int mx = 0;
        int mi = 10000;
        for (int v : nums) {
            mx = Math.max(mx, v);
            mi = Math.min(mi, v);
        }
        return Math.max(0, mx - mi - k * 2);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto [mi, mx] = minmax_element(nums.begin(), nums.end());
        return max(0, *mx - *mi - k * 2);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func smallestRangeI(nums []int, k int) int {
	mi, mx := slices.Min(nums), slices.Max(nums)
	return max(0, mx-mi-k*2)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function smallestRangeI(nums: number[], k: number): number {
    const mx = Math.max(...nums);
    const mi = Math.min(...nums);
    return Math.max(mx - mi - k * 2, 0);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        let max = nums.iter().max().unwrap();
        let min = nums.iter().min().unwrap();
        (0).max(max - min - k * 2)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，和一个整数 <code>k</code> 。</p>

<p>在一个操作中，您可以选择 <code>0 &lt;= i &lt; nums.length</code> 的任何索引 <code>i</code> 。将 <code>nums[i]</code> 改为 <code>nums[i] + x</code> ，其中 <code>x</code> 是一个范围为 <code>[-k, k]</code> 的任意整数。对于每个索引 <code>i</code> ，最多 <strong>只能 </strong>应用 <strong>一次</strong> 此操作。</p>

<p><code>nums</code>&nbsp;的&nbsp;<strong>分数&nbsp;</strong>是&nbsp;<code>nums</code>&nbsp;中最大和最小元素的差值。&nbsp;</p>

<p><em>在对&nbsp; <code>nums</code> 中的每个索引最多应用一次上述操作后，返回&nbsp;<code>nums</code> 的最低 <strong>分数</strong></em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], k = 0
<strong>输出：</strong>0
<strong>解释：</strong>分数是 max(nums) - min(nums) = 1 - 1 = 0。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,10], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>将 nums 改为 [2,8]。分数是 max(nums) - min(nums) = 8 - 2 = 6。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,6], k = 3
<strong>输出：</strong>0
<strong>解释：</strong>将 nums 改为 [4,4,4]。分数是 max(nums) - min(nums) = 4 - 4 = 0。
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

### 方法一：数学

根据题目描述，我们可以将数组中的最大值减去 $k$，最小值加上 $k$，这样可以使得数组中的最大值和最小值之差变小。

因此，最终的答案就是 $\max(\textit{nums}) - \min(\textit{nums}) - 2 \times k$ 和 $0$ 之间的较大值。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        mx, mi = max(nums), min(nums)
        return max(0, mx - mi - k * 2)
```

#### Java

```java
class Solution {
    public int smallestRangeI(int[] nums, int k) {
        int mx = 0;
        int mi = 10000;
        for (int v : nums) {
            mx = Math.max(mx, v);
            mi = Math.min(mi, v);
        }
        return Math.max(0, mx - mi - k * 2);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        auto [mi, mx] = minmax_element(nums.begin(), nums.end());
        return max(0, *mx - *mi - k * 2);
    }
};
```

#### Go

```go
func smallestRangeI(nums []int, k int) int {
	mi, mx := slices.Min(nums), slices.Max(nums)
	return max(0, mx-mi-k*2)
}
```

#### TypeScript

```ts
function smallestRangeI(nums: number[], k: number): number {
    const mx = Math.max(...nums);
    const mi = Math.min(...nums);
    return Math.max(mx - mi - k * 2, 0);
}
```

#### Rust

```rust
impl Solution {
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        let max = nums.iter().max().unwrap();
        let min = nums.iter().min().unwrap();
        (0).max(max - min - k * 2)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [909. 蛇梯棋](https://leetcode.cn/problems/snakes-and-ladders){#909}

{{< tabs "909" >}}

{{% tab "python" %}}
```python
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        q = deque([1])
        vis = {1}
        ans = 0
        m = n * n
        while q:
            for _ in range(len(q)):
                x = q.popleft()
                if x == m:
                    return ans
                for y in range(x + 1, min(x + 6, m) + 1):
                    i, j = divmod(y - 1, n)
                    if i & 1:
                        j = n - j - 1
                    i = n - i - 1
                    z = y if board[i][j] == -1 else board[i][j]
                    if z not in vis:
                        vis.add(z)
                        q.append(z)
            ans += 1
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(1);
        int m = n * n;
        boolean[] vis = new boolean[m + 1];
        vis[1] = true;
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                int x = q.poll();
                if (x == m) {
                    return ans;
                }
                for (int y = x + 1; y <= Math.min(x + 6, m); ++y) {
                    int i = (y - 1) / n, j = (y - 1) % n;
                    if (i % 2 == 1) {
                        j = n - j - 1;
                    }
                    i = n - i - 1;
                    int z = board[i][j] == -1 ? y : board[i][j];
                    if (!vis[z]) {
                        vis[z] = true;
                        q.offer(z);
                    }
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
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q{{1}};
        int m = n * n;
        vector<bool> vis(m + 1);
        vis[1] = true;

        for (int ans = 0; !q.empty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                int x = q.front();
                q.pop();
                if (x == m) {
                    return ans;
                }
                for (int y = x + 1; y <= min(x + 6, m); ++y) {
                    int i = (y - 1) / n, j = (y - 1) % n;
                    if (i % 2 == 1) {
                        j = n - j - 1;
                    }
                    i = n - i - 1;
                    int z = board[i][j] == -1 ? y : board[i][j];
                    if (!vis[z]) {
                        vis[z] = true;
                        q.push(z);
                    }
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
func snakesAndLadders(board [][]int) int {
	n := len(board)
	q := []int{1}
	m := n * n
	vis := make([]bool, m+1)
	vis[1] = true

	for ans := 0; len(q) > 0; ans++ {
		for k := len(q); k > 0; k-- {
			x := q[0]
			q = q[1:]
			if x == m {
				return ans
			}
			for y := x + 1; y <= min(x+6, m); y++ {
				i, j := (y-1)/n, (y-1)%n
				if i%2 == 1 {
					j = n - j - 1
				}
				i = n - i - 1
				z := y
				if board[i][j] != -1 {
					z = board[i][j]
				}
				if !vis[z] {
					vis[z] = true
					q = append(q, z)
				}
			}
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function snakesAndLadders(board: number[][]): number {
    const n = board.length;
    const q: number[] = [1];
    const m = n * n;
    const vis: boolean[] = Array(m + 1).fill(false);
    vis[1] = true;

    for (let ans = 0; q.length > 0; ans++) {
        const nq: number[] = [];
        for (const x of q) {
            if (x === m) {
                return ans;
            }
            for (let y = x + 1; y <= Math.min(x + 6, m); y++) {
                let i = Math.floor((y - 1) / n);
                let j = (y - 1) % n;
                if (i % 2 === 1) {
                    j = n - j - 1;
                }
                i = n - i - 1;
                const z = board[i][j] === -1 ? y : board[i][j];
                if (!vis[z]) {
                    vis[z] = true;
                    nq.push(z);
                }
            }
        }
        q.length = 0;
        for (const x of nq) {
            q.push(x);
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let n = board.len();
        let m = (n * n) as i32;
        let mut q = VecDeque::new();
        q.push_back(1);
        let mut vis = HashSet::new();
        vis.insert(1);
        let mut ans = 0;

        while !q.is_empty() {
            for _ in 0..q.len() {
                let x = q.pop_front().unwrap();
                if x == m {
                    return ans;
                }
                for y in x + 1..=i32::min(x + 6, m) {
                    let (mut i, mut j) = ((y - 1) / n as i32, (y - 1) % n as i32);
                    if i % 2 == 1 {
                        j = (n as i32 - 1) - j;
                    }
                    i = (n as i32 - 1) - i;
                    let z = if board[i as usize][j as usize] == -1 {
                        y
                    } else {
                        board[i as usize][j as usize]
                    };
                    if !vis.contains(&z) {
                        vis.insert(z);
                        q.push_back(z);
                    }
                }
            }
            ans += 1;
        }

        -1
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>n x n</code> 的整数矩阵 <code>board</code> ，方格按从&nbsp;<code>1</code> 到 <code>n<sup>2</sup></code> 编号，编号遵循 <a href="https://baike.baidu.com/item/%E7%89%9B%E8%80%95%E5%BC%8F%E8%BD%AC%E8%A1%8C%E4%B9%A6%E5%86%99%E6%B3%95/17195786">转行交替方式</a><strong> </strong>，<strong>从左下角开始</strong>&nbsp;（即，从 <code>board[n - 1][0]</code> 开始）的每一行改变方向。</p>

<p>你一开始位于棋盘上的方格&nbsp; <code>1</code>。每一回合，玩家需要从当前方格 <code>curr</code> 开始出发，按下述要求前进：</p>

<ul>
	<li>选定目标方格 <code>next</code> ，目标方格的编号在范围&nbsp;<code>[curr + 1, min(curr + 6, n<sup>2</sup>)]</code> 。

    <ul>
    	<li>该选择模拟了掷 <strong>六面体骰子</strong> 的情景，无论棋盘大小如何，玩家最多只能有 6 个目的地。</li>
    </ul>
    </li>
    <li>传送玩家：如果目标方格 <code>next</code> 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地。否则，玩家传送到目标方格 <code>next</code> 。&nbsp;</li>
    <li>当玩家到达编号 <code>n<sup>2</sup></code> 的方格时，游戏结束。</li>

</ul>

<p>如果 <code>board[r][c] != -1</code>&nbsp;，位于&nbsp;<code>r</code> 行 <code>c</code> 列的棋盘格中可能存在 “蛇” 或 “梯子”。那个蛇或梯子的目的地将会是 <code>board[r][c]</code>。编号为 <code>1</code> 和 <code>n<sup>2</sup></code> 的方格不是任何蛇或梯子的起点。</p>

<p>注意，玩家在每次掷骰的前进过程中最多只能爬过蛇或梯子一次：就算目的地是另一条蛇或梯子的起点，玩家也 <strong>不能</strong> 继续移动。</p>

<ul>
	<li>举个例子，假设棋盘是 <code>[[-1,4],[-1,3]]</code> ，第一次移动，玩家的目标方格是 <code>2</code> 。那么这个玩家将会顺着梯子到达方格 <code>3</code> ，但 <strong>不能</strong> 顺着方格 <code>3</code> 上的梯子前往方格 <code>4</code> 。（简单来说，类似飞行棋，玩家掷出骰子点数后移动对应格数，遇到单向的路径（即梯子或蛇）可以直接跳到路径的终点，但如果多个路径首尾相连，也不能连续跳多个路径）</li>
</ul>

<p>返回达到编号为&nbsp;<code>n<sup>2</sup></code> 的方格所需的最少掷骰次数，如果不可能，则返回 <code>-1</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0900-0999/0909.Snakes%20and%20Ladders/images/snakes.png" style="width: 500px; height: 394px;" />
<pre>
<strong>输入：</strong>board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
<strong>输出：</strong>4
<strong>解释：</strong>
首先，从方格 1 [第 5 行，第 0 列] 开始。 
先决定移动到方格 2 ，并必须爬过梯子移动到到方格 15 。
然后决定移动到方格 17 [第 3 行，第 4 列]，必须爬过蛇到方格 13 。
接着决定移动到方格 14 ，且必须通过梯子移动到方格 35 。 
最后决定移动到方格 36 , 游戏结束。 
可以证明需要至少 4 次移动才能到达最后一个方格，所以答案是 4 。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = [[-1,-1],[-1,3]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == board.length == board[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 20</code></li>
	<li><code>board[i][j]</code> 的值是 <code>-1</code> 或在范围 <code>[1, n<sup>2</sup>]</code> 内</li>
	<li>编号为 <code>1</code> 和 <code>n<sup>2</sup></code> 的方格上没有蛇或梯子</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们可以使用广度优先搜索的方法，从起点开始，每次向前走 1 到 6 步，然后判断是否有蛇或梯子，如果有，就走到蛇或梯子的目的地，否则就走到下一个方格。

具体地，我们使用一个队列 $\textit{q}$ 来存储当前可以到达的方格编号，初始时将编号 $1$ 放入队列。同时我们使用一个集合 $\textit{vis}$ 来记录已经到达过的方格，避免重复访问，初始时将编号 $1$ 加入集合 $\textit{vis}$。

在每一次的操作中，我们取出队首的方格编号 $x$，如果 $x$ 是终点，那么我们就可以返回当前的步数。否则我们将 $x$ 向前走 $1$ 到 $6$ 步，设新的编号为 $y$，如果 $y$ 落在棋盘外，那么我们就直接跳过。否则，我们需要找到 $y$ 对应的行和列，由于行的编号是从下到上递减的，而列的编号与行的奇偶性有关，因此我们需要进行一些计算得到 $y$ 对应的行和列。

如果 $y$ 对应的方格上有蛇或梯子，那么我们需要额外走到蛇或梯子的目的地，设其为 $z$。如果 $z$ 没有被访问过，我们就将 $z$ 加入队列和集合中，这样我们就可以继续进行广度优先搜索。

如果我们最终无法到达终点，那么我们就返回 $-1$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是棋盘的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        q = deque([1])
        vis = {1}
        ans = 0
        m = n * n
        while q:
            for _ in range(len(q)):
                x = q.popleft()
                if x == m:
                    return ans
                for y in range(x + 1, min(x + 6, m) + 1):
                    i, j = divmod(y - 1, n)
                    if i & 1:
                        j = n - j - 1
                    i = n - i - 1
                    z = y if board[i][j] == -1 else board[i][j]
                    if z not in vis:
                        vis.add(z)
                        q.append(z)
            ans += 1
        return -1
```

#### Java

```java
class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(1);
        int m = n * n;
        boolean[] vis = new boolean[m + 1];
        vis[1] = true;
        for (int ans = 0; !q.isEmpty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                int x = q.poll();
                if (x == m) {
                    return ans;
                }
                for (int y = x + 1; y <= Math.min(x + 6, m); ++y) {
                    int i = (y - 1) / n, j = (y - 1) % n;
                    if (i % 2 == 1) {
                        j = n - j - 1;
                    }
                    i = n - i - 1;
                    int z = board[i][j] == -1 ? y : board[i][j];
                    if (!vis[z]) {
                        vis[z] = true;
                        q.offer(z);
                    }
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
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<int> q{{1}};
        int m = n * n;
        vector<bool> vis(m + 1);
        vis[1] = true;

        for (int ans = 0; !q.empty(); ++ans) {
            for (int k = q.size(); k > 0; --k) {
                int x = q.front();
                q.pop();
                if (x == m) {
                    return ans;
                }
                for (int y = x + 1; y <= min(x + 6, m); ++y) {
                    int i = (y - 1) / n, j = (y - 1) % n;
                    if (i % 2 == 1) {
                        j = n - j - 1;
                    }
                    i = n - i - 1;
                    int z = board[i][j] == -1 ? y : board[i][j];
                    if (!vis[z]) {
                        vis[z] = true;
                        q.push(z);
                    }
                }
            }
        }
        return -1;
    }
};
```

#### Go

```go
func snakesAndLadders(board [][]int) int {
	n := len(board)
	q := []int{1}
	m := n * n
	vis := make([]bool, m+1)
	vis[1] = true

	for ans := 0; len(q) > 0; ans++ {
		for k := len(q); k > 0; k-- {
			x := q[0]
			q = q[1:]
			if x == m {
				return ans
			}
			for y := x + 1; y <= min(x+6, m); y++ {
				i, j := (y-1)/n, (y-1)%n
				if i%2 == 1 {
					j = n - j - 1
				}
				i = n - i - 1
				z := y
				if board[i][j] != -1 {
					z = board[i][j]
				}
				if !vis[z] {
					vis[z] = true
					q = append(q, z)
				}
			}
		}
	}
	return -1
}
```

#### TypeScript

```ts
function snakesAndLadders(board: number[][]): number {
    const n = board.length;
    const q: number[] = [1];
    const m = n * n;
    const vis: boolean[] = Array(m + 1).fill(false);
    vis[1] = true;

    for (let ans = 0; q.length > 0; ans++) {
        const nq: number[] = [];
        for (const x of q) {
            if (x === m) {
                return ans;
            }
            for (let y = x + 1; y <= Math.min(x + 6, m); y++) {
                let i = Math.floor((y - 1) / n);
                let j = (y - 1) % n;
                if (i % 2 === 1) {
                    j = n - j - 1;
                }
                i = n - i - 1;
                const z = board[i][j] === -1 ? y : board[i][j];
                if (!vis[z]) {
                    vis[z] = true;
                    nq.push(z);
                }
            }
        }
        q.length = 0;
        for (const x of nq) {
            q.push(x);
        }
    }
    return -1;
}
```

#### Rust

```rust
use std::collections::{HashSet, VecDeque};

impl Solution {
    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let n = board.len();
        let m = (n * n) as i32;
        let mut q = VecDeque::new();
        q.push_back(1);
        let mut vis = HashSet::new();
        vis.insert(1);
        let mut ans = 0;

        while !q.is_empty() {
            for _ in 0..q.len() {
                let x = q.pop_front().unwrap();
                if x == m {
                    return ans;
                }
                for y in x + 1..=i32::min(x + 6, m) {
                    let (mut i, mut j) = ((y - 1) / n as i32, (y - 1) % n as i32);
                    if i % 2 == 1 {
                        j = (n as i32 - 1) - j;
                    }
                    i = (n as i32 - 1) - i;
                    let z = if board[i as usize][j as usize] == -1 {
                        y
                    } else {
                        board[i as usize][j as usize]
                    };
                    if !vis.contains(&z) {
                        vis.insert(z);
                        q.push_back(z);
                    }
                }
            }
            ans += 1;
        }

        -1
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
