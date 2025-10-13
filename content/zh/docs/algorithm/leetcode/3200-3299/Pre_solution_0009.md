---
title: "3280_将日期转换为二进制表示"
date: 2025-10-08T18:40:15+08:00
weight: 9
tags: [二分查找, 位运算, 动态规划, 博弈, 双指针, 哈希表, 图, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 最短路, 状态压缩, 矩阵, 贪心]
---

{{< markmap >}}
### [3280_将日期转换为二进制表示](#3280)
#### [数学](#3280)
#### [字符串](#3280)
### [3281_范围内整数的最大得分](#3281)
#### [贪心](#3281)
#### [数组](#3281)
#### [二分查找](#3281)
#### [排序](#3281)
### [3282_到达数组末尾的最大得分](#3282)
#### [贪心](#3282)
#### [数组](#3282)
### [3283_吃掉所有兵需要的最多移动次数](#3283)
#### [位运算](#3283)
#### [广度优先搜索](#3283)
#### [数组](#3283)
#### [数学](#3283)
#### [状态压缩](#3283)
#### [博弈](#3283)
### [3284_连续子数组的和 🔒](#3284)
#### [数组](#3284)
#### [双指针](#3284)
#### [动态规划](#3284)
### [3285_找到稳定山的下标](#3285)
#### [数组](#3285)
### [3286_穿越网格图的安全路径](#3286)
#### [广度优先搜索](#3286)
#### [图](#3286)
#### [数组](#3286)
#### [矩阵](#3286)
#### [最短路](#3286)
#### [堆（优先队列）](#3286)
### [3287_求出数组中最大序列值](#3287)
#### [位运算](#3287)
#### [数组](#3287)
#### [动态规划](#3287)
### [3288_最长上升路径的长度](#3288)
#### [数组](#3288)
#### [二分查找](#3288)
#### [排序](#3288)
### [3289_数字小镇中的捣蛋鬼](#3289)
#### [数组](#3289)
#### [哈希表](#3289)
#### [数学](#3289)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3280_将日期转换为二进制表示
___
#### 数学
___
#### 字符串
---
### 3281_范围内整数的最大得分
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 3282_到达数组末尾的最大得分
___
#### 贪心
___
#### 数组
---
### 3283_吃掉所有兵需要的最多移动次数
___
#### 位运算
___
#### 广度优先搜索
___
#### 数组
___
#### 数学
___
#### 状态压缩
___
#### 博弈
---
### 3284_连续子数组的和 🔒
___
#### 数组
___
#### 双指针
___
#### 动态规划
---
### 3285_找到稳定山的下标
___
#### 数组
---
### 3286_穿越网格图的安全路径
___
#### 广度优先搜索
___
#### 图
___
#### 数组
___
#### 矩阵
___
#### 最短路
___
#### 堆（优先队列）
---
### 3287_求出数组中最大序列值
___
#### 位运算
___
#### 数组
___
#### 动态规划
---
### 3288_最长上升路径的长度
___
#### 数组
___
#### 二分查找
___
#### 排序
---
### 3289_数字小镇中的捣蛋鬼
___
#### 数组
___
#### 哈希表
___
#### 数学
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 博弈 | 双指针 | 哈希表 |
| 图 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 最短路 | 状态压缩 |
| 矩阵 | 贪心 |  |

# [3280. 将日期转换为二进制表示](https://leetcode.cn/problems/convert-date-to-binary){#3280}

{{< tabs "3280" >}}

{{% tab "python" %}}
```python
class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return "-".join(f"{int(s):b}" for s in date.split("-"))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String convertDateToBinary(String date) {
        List<String> ans = new ArrayList<>();
        for (var s : date.split("-")) {
            int x = Integer.parseInt(s);
            ans.add(Integer.toBinaryString(x));
        }
        return String.join("-", ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string convertDateToBinary(string date) {
        auto bin = [](string s) -> string {
            string t = bitset<32>(stoi(s)).to_string();
            return t.substr(t.find('1'));
        };
        return bin(date.substr(0, 4)) + "-" + bin(date.substr(5, 2)) + "-" + bin(date.substr(8, 2));
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func convertDateToBinary(date string) string {
	ans := []string{}
	for _, s := range strings.Split(date, "-") {
		x, _ := strconv.Atoi(s)
		ans = append(ans, strconv.FormatUint(uint64(x), 2))
	}
	return strings.Join(ans, "-")
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function convertDateToBinary(date: string): string {
    return date
        .split('-')
        .map(s => (+s).toString(2))
        .join('-');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>date</code>，它的格式为 <code>yyyy-mm-dd</code>，表示一个公历日期。</p>

<p><code>date</code> 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）并遵循 <code>year-month-day</code> 的格式。</p>

<p>返回 <code>date</code> 的 <strong>二进制</strong> 表示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">date = "2080-02-29"</span></p>

<p><strong>输出：</strong> <span class="example-io">"100000100000-10-11101"</span></p>

<p><strong>解释：</strong></p>

<p><span class="example-io">100000100000, 10 和 11101 分别是 2080, 02 和 29 的二进制表示。</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">date = "1900-01-01"</span></p>

<p><strong>输出：</strong> <span class="example-io">"11101101100-1-1"</span></p>

<p><strong>解释：</strong></p>

<p><span class="example-io">11101101100, 1 和 1 分别是 1900, 1 和 1 的二进制表示。</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>，其余的 <code>date[i]</code> 都是数字。</li>
	<li>输入保证 <code>date</code> 代表一个有效的公历日期，日期范围从 1900 年 1 月 1 日到 2100 年 12 月 31 日（包括这两天）。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先将字符串 $\textit{date}$ 按照 `-` 分割，然后将每个部分转换为二进制表示，最后将这三个部分用 `-` 连接起来即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{date}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def convertDateToBinary(self, date: str) -> str:
        return "-".join(f"{int(s):b}" for s in date.split("-"))
```

#### Java

```java
class Solution {
    public String convertDateToBinary(String date) {
        List<String> ans = new ArrayList<>();
        for (var s : date.split("-")) {
            int x = Integer.parseInt(s);
            ans.add(Integer.toBinaryString(x));
        }
        return String.join("-", ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string convertDateToBinary(string date) {
        auto bin = [](string s) -> string {
            string t = bitset<32>(stoi(s)).to_string();
            return t.substr(t.find('1'));
        };
        return bin(date.substr(0, 4)) + "-" + bin(date.substr(5, 2)) + "-" + bin(date.substr(8, 2));
    }
};
```

#### Go

```go
func convertDateToBinary(date string) string {
	ans := []string{}
	for _, s := range strings.Split(date, "-") {
		x, _ := strconv.Atoi(s)
		ans = append(ans, strconv.FormatUint(uint64(x), 2))
	}
	return strings.Join(ans, "-")
}
```

#### TypeScript

```ts
function convertDateToBinary(date: string): string {
    return date
        .split('-')
        .map(s => (+s).toString(2))
        .join('-');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3281. 范围内整数的最大得分](https://leetcode.cn/problems/maximize-score-of-numbers-in-ranges){#3281}

{{< tabs "3281" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        def check(mi: int) -> bool:
            last = -inf
            for st in start:
                if last + mi > st + d:
                    return False
                last = max(st, last + mi)
            return True

        start.sort()
        l, r = 0, start[-1] + d - start[0]
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] start;
    private int d;

    public int maxPossibleScore(int[] start, int d) {
        Arrays.sort(start);
        this.start = start;
        this.d = d;
        int n = start.length;
        int l = 0, r = start[n - 1] + d - start[0];
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int mi) {
        long last = Long.MIN_VALUE;
        for (int st : start) {
            if (last + mi > st + d) {
                return false;
            }
            last = Math.max(st, last + mi);
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
    int maxPossibleScore(vector<int>& start, int d) {
        ranges::sort(start);
        auto check = [&](int mi) -> bool {
            long long last = LLONG_MIN;
            for (int st : start) {
                if (last + mi > st + d) {
                    return false;
                }
                last = max((long long) st, last + mi);
            }
            return true;
        };
        int l = 0, r = start.back() + d - start[0];
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPossibleScore(start []int, d int) int {
	check := func(mi int) bool {
		last := math.MinInt64
		for _, st := range start {
			if last+mi > st+d {
				return false
			}
			last = max(st, last+mi)
		}
		return true
	}
	sort.Ints(start)
	l, r := 0, start[len(start)-1]+d-start[0]
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPossibleScore(start: number[], d: number): number {
    start.sort((a, b) => a - b);
    let [l, r] = [0, start.at(-1)! + d - start[0]];
    const check = (mi: number): boolean => {
        let last = -Infinity;
        for (const st of start) {
            if (last + mi > st + d) {
                return false;
            }
            last = Math.max(st, last + mi);
        }
        return true;
    };
    while (l < r) {
        const mid = l + ((r - l + 1) >> 1);
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>start</code> 和一个整数 <code>d</code>，代表 <code>n</code> 个区间 <code>[start[i], start[i] + d]</code>。</p>

<p>你需要选择 <code>n</code> 个整数，其中第 <code>i</code> 个整数必须属于第 <code>i</code> 个区间。所选整数的 <strong>得分</strong> 定义为所选整数两两之间的 <strong>最小 </strong>绝对差。</p>

<p>返回所选整数的 <strong>最大可能得分 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">start = [6,0,3], d = 2</span></p>

<p><strong>输出：</strong> <span class="example-io">4</span></p>

<p><strong>解释：</strong></p>

<p>可以选择整数 8, 0 和 4 获得最大可能得分，得分为 <code>min(|8 - 0|, |8 - 4|, |0 - 4|)</code>，等于 4。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">start = [2,6,13,13], d = 5</span></p>

<p><strong>输出：</strong> <span class="example-io">5</span></p>

<p><strong>解释：</strong></p>

<p>可以选择整数 2, 7, 13 和 18 获得最大可能得分，得分为 <code>min(|2 - 7|, |2 - 13|, |2 - 18|, |7 - 13|, |7 - 18|, |13 - 18|)</code>，等于 5。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= start.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= start[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= d &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 二分查找

我们不妨先对 $\textit{start}$ 数组进行排序，然后我们考虑从左到右选择整数，那么得分就等于我们选择的相邻两个整数的差值的最小值。

如果一个差值 $x$ 满足条件，那么对于任意 $x' \lt x$，也一定满足条件。因此我们可以使用二分查找的方法来找到最大的满足条件的差值。

我们定义二分查找的左边界 $l = 0$，右边界 $r = \textit{start}[-1] + d - \textit{start}[0]$，然后我们每次取中间值 $mid = \left\lfloor \frac{l + r + 1}{2} \right\rfloor$，然后判断是否满足条件。

我们定义一个函数 $\text{check}(mi)$ 来判断是否满足条件，具体实现如下：

-   我们定义一个变量 $\textit{last} = -\infty$，表示上一个选择的整数。
-   我们遍历 $\textit{start}$ 数组，如果 $\textit{last} + \textit{mi} > \textit{st} + d$，那么说明我们无法选择整数 $\textit{st}$，返回 $\text{false}$。否则，我们更新 $\textit{last} = \max(\textit{st}, \textit{last} + \textit{mi})$。
-   如果遍历完整个 $\textit{start}$ 数组都满足条件，那么返回 $\text{true}$。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是 $\textit{start}$ 数组的长度和最大值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        def check(mi: int) -> bool:
            last = -inf
            for st in start:
                if last + mi > st + d:
                    return False
                last = max(st, last + mi)
            return True

        start.sort()
        l, r = 0, start[-1] + d - start[0]
        while l < r:
            mid = (l + r + 1) >> 1
            if check(mid):
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    private int[] start;
    private int d;

    public int maxPossibleScore(int[] start, int d) {
        Arrays.sort(start);
        this.start = start;
        this.d = d;
        int n = start.length;
        int l = 0, r = start[n - 1] + d - start[0];
        while (l < r) {
            int mid = (l + r + 1) >>> 1;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    private boolean check(int mi) {
        long last = Long.MIN_VALUE;
        for (int st : start) {
            if (last + mi > st + d) {
                return false;
            }
            last = Math.max(st, last + mi);
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        ranges::sort(start);
        auto check = [&](int mi) -> bool {
            long long last = LLONG_MIN;
            for (int st : start) {
                if (last + mi > st + d) {
                    return false;
                }
                last = max((long long) st, last + mi);
            }
            return true;
        };
        int l = 0, r = start.back() + d - start[0];
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};
```

#### Go

```go
func maxPossibleScore(start []int, d int) int {
	check := func(mi int) bool {
		last := math.MinInt64
		for _, st := range start {
			if last+mi > st+d {
				return false
			}
			last = max(st, last+mi)
		}
		return true
	}
	sort.Ints(start)
	l, r := 0, start[len(start)-1]+d-start[0]
	for l < r {
		mid := (l + r + 1) >> 1
		if check(mid) {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
```

#### TypeScript

```ts
function maxPossibleScore(start: number[], d: number): number {
    start.sort((a, b) => a - b);
    let [l, r] = [0, start.at(-1)! + d - start[0]];
    const check = (mi: number): boolean => {
        let last = -Infinity;
        for (const st of start) {
            if (last + mi > st + d) {
                return false;
            }
            last = Math.max(st, last + mi);
        }
        return true;
    };
    while (l < r) {
        const mid = l + ((r - l + 1) >> 1);
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3282. 到达数组末尾的最大得分](https://leetcode.cn/problems/reach-end-of-array-with-max-score){#3282}

{{< tabs "3282" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaximumScore(self, nums: List[int]) -> int:
        ans = mx = 0
        for x in nums[:-1]:
            mx = max(mx, x)
            ans += mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long findMaximumScore(List<Integer> nums) {
        long ans = 0;
        int mx = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            mx = Math.max(mx, nums.get(i));
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
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int mx = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            ans += mx;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaximumScore(nums []int) (ans int64) {
	mx := 0
	for _, x := range nums[:len(nums)-1] {
		mx = max(mx, x)
		ans += int64(mx)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaximumScore(nums: number[]): number {
    let [ans, mx]: [number, number] = [0, 0];
    for (const x of nums.slice(0, -1)) {
        mx = Math.max(mx, x);
        ans += mx;
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

<p>给你一个长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你的目标是从下标 <code>0</code>&nbsp;出发，到达下标 <code>n - 1</code>&nbsp;处。每次你只能移动到&nbsp;<strong>更大</strong>&nbsp;的下标处。</p>

<p>从下标 <code>i</code>&nbsp;跳到下标 <code>j</code>&nbsp;的得分为&nbsp;<code>(j - i) * nums[i]</code>&nbsp;。</p>

<p>请你返回你到达最后一个下标处能得到的 <strong>最大总得分</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,3,1,5]</span></p>

<p><b>输出：</b>7</p>

<p><b>解释：</b></p>

<p>一开始跳到下标 1 处，然后跳到最后一个下标处。总得分为&nbsp;<code>1 * 1 + 2 * 3 = 7</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [4,3,1,3,2]</span></p>

<p><b>输出：</b>16</p>

<p><strong>解释：</strong></p>

<p>直接跳到最后一个下标处。总得分为&nbsp;<code>4 * 4 = 16</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

假设我们从下标 $i$，跳到下标 $j$，那么得分为 $(j - i) \times \text{nums}[i]$。这相当于我们走了 $j - i$ 步，每一步都得到了 $\text{nums}[i]$ 的得分。然后我们从 $j$ 继续跳到下一个下标 $k$，得分为 $(k - j) \times \text{nums}[j]$，以此类推。如果 $nums[i] \gt nums[j]$，那么我们就不应该从 $i$ 跳到 $j$，因为这样得到的得分一定比从 $i$ 直接跳到 $k$ 得到的得分要少。因此，我们每一次应该跳到下一个比当前下标对应的值更大的下标。

我们可以维护一个变量 $mx$，表示当前为止，我们遇到的最大的 $\text{nums}[i]$ 的值。然后我们从左到右遍历数组，直到倒数第二个元素，每次更新 $mx$，并且累加得分。

遍历结束后，我们得到的就是最大的总得分。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\text{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaximumScore(self, nums: List[int]) -> int:
        ans = mx = 0
        for x in nums[:-1]:
            mx = max(mx, x)
            ans += mx
        return ans
```

#### Java

```java
class Solution {
    public long findMaximumScore(List<Integer> nums) {
        long ans = 0;
        int mx = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            mx = Math.max(mx, nums.get(i));
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
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int mx = 0;
        for (int i = 0; i + 1 < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            ans += mx;
        }
        return ans;
    }
};
```

#### Go

```go
func findMaximumScore(nums []int) (ans int64) {
	mx := 0
	for _, x := range nums[:len(nums)-1] {
		mx = max(mx, x)
		ans += int64(mx)
	}
	return
}
```

#### TypeScript

```ts
function findMaximumScore(nums: number[]): number {
    let [ans, mx]: [number, number] = [0, 0];
    for (const x of nums.slice(0, -1)) {
        mx = Math.max(mx, x);
        ans += mx;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3283. 吃掉所有兵需要的最多移动次数](https://leetcode.cn/problems/maximum-number-of-moves-to-kill-all-pawns){#3283}

{{< tabs "3283" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:
        @cache
        def dfs(last: int, state: int, k: int) -> int:
            if state == 0:
                return 0
            if k:
                res = 0
                for i, (x, y) in enumerate(positions):
                    if state >> i & 1:
                        t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y]
                        if res < t:
                            res = t
                return res
            else:
                res = inf
                for i, (x, y) in enumerate(positions):
                    if state >> i & 1:
                        t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y]
                        if res > t:
                            res = t
                return res

        n = len(positions)
        m = 50
        dist = [[[-1] * m for _ in range(m)] for _ in range(n + 1)]
        dx = [1, 1, 2, 2, -1, -1, -2, -2]
        dy = [2, -2, 1, -1, 2, -2, 1, -1]
        positions.append([kx, ky])
        for i, (x, y) in enumerate(positions):
            dist[i][x][y] = 0
            q = deque([(x, y)])
            step = 0
            while q:
                step += 1
                for _ in range(len(q)):
                    x1, y1 = q.popleft()
                    for j in range(8):
                        x2, y2 = x1 + dx[j], y1 + dy[j]
                        if 0 <= x2 < m and 0 <= y2 < m and dist[i][x2][y2] == -1:
                            dist[i][x2][y2] = step
                            q.append((x2, y2))

        ans = dfs(n, (1 << n) - 1, 1)
        dfs.cache_clear()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Integer[][][] f;
    private Integer[][][] dist;
    private int[][] positions;
    private final int[] dx = {1, 1, 2, 2, -1, -1, -2, -2};
    private final int[] dy = {2, -2, 1, -1, 2, -2, 1, -1};

    public int maxMoves(int kx, int ky, int[][] positions) {
        int n = positions.length;
        final int m = 50;
        dist = new Integer[n + 1][m][m];
        this.positions = positions;
        for (int i = 0; i <= n; ++i) {
            int x = i < n ? positions[i][0] : kx;
            int y = i < n ? positions[i][1] : ky;
            Deque<int[]> q = new ArrayDeque<>();
            q.offer(new int[] {x, y});
            for (int step = 1; !q.isEmpty(); ++step) {
                for (int k = q.size(); k > 0; --k) {
                    var p = q.poll();
                    int x1 = p[0], y1 = p[1];
                    for (int j = 0; j < 8; ++j) {
                        int x2 = x1 + dx[j], y2 = y1 + dy[j];
                        if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && dist[i][x2][y2] == null) {
                            dist[i][x2][y2] = step;
                            q.offer(new int[] {x2, y2});
                        }
                    }
                }
            }
        }
        f = new Integer[n + 1][1 << n][2];
        return dfs(n, (1 << n) - 1, 1);
    }

    private int dfs(int last, int state, int k) {
        if (state == 0) {
            return 0;
        }
        if (f[last][state][k] != null) {
            return f[last][state][k];
        }
        int res = k == 1 ? 0 : Integer.MAX_VALUE;
        for (int i = 0; i < positions.length; ++i) {
            int x = positions[i][0], y = positions[i][1];
            if ((state >> i & 1) == 1) {
                int t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y];
                res = k == 1 ? Math.max(res, t) : Math.min(res, t);
            }
        }
        return f[last][state][k] = res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        const int m = 50;
        const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
        const int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
        int dist[n + 1][m][m];
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i <= n; ++i) {
            int x = (i < n) ? positions[i][0] : kx;
            int y = (i < n) ? positions[i][1] : ky;
            queue<pair<int, int>> q;
            q.push({x, y});
            dist[i][x][y] = 0;
            for (int step = 1; !q.empty(); ++step) {
                for (int k = q.size(); k > 0; --k) {
                    auto [x1, y1] = q.front();
                    q.pop();
                    for (int j = 0; j < 8; ++j) {
                        int x2 = x1 + dx[j], y2 = y1 + dy[j];
                        if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && dist[i][x2][y2] == -1) {
                            dist[i][x2][y2] = step;
                            q.push({x2, y2});
                        }
                    }
                }
            }
        }

        int f[n + 1][1 << n][2];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int last, int state, int k) -> int {
            if (state == 0) {
                return 0;
            }
            if (f[last][state][k] != -1) {
                return f[last][state][k];
            }
            int res = (k == 1) ? 0 : INT_MAX;

            for (int i = 0; i < positions.size(); ++i) {
                int x = positions[i][0], y = positions[i][1];
                if ((state >> i) & 1) {
                    int t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y];
                    if (k == 1) {
                        res = max(res, t);
                    } else {
                        res = min(res, t);
                    }
                }
            }
            return f[last][state][k] = res;
        };
        return dfs(n, (1 << n) - 1, 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxMoves(kx int, ky int, positions [][]int) int {
	n := len(positions)
	const m = 50
	dx := []int{1, 1, 2, 2, -1, -1, -2, -2}
	dy := []int{2, -2, 1, -1, 2, -2, 1, -1}
	dist := make([][][]int, n+1)
	for i := range dist {
		dist[i] = make([][]int, m)
		for j := range dist[i] {
			dist[i][j] = make([]int, m)
			for k := range dist[i][j] {
				dist[i][j][k] = -1
			}
		}
	}

	for i := 0; i <= n; i++ {
		x := kx
		y := ky
		if i < n {
			x = positions[i][0]
			y = positions[i][1]
		}
		q := [][2]int{[2]int{x, y}}
		dist[i][x][y] = 0

		for step := 1; len(q) > 0; step++ {
			for k := len(q); k > 0; k-- {
				p := q[0]
				q = q[1:]
				x1, y1 := p[0], p[1]
				for j := 0; j < 8; j++ {
					x2 := x1 + dx[j]
					y2 := y1 + dy[j]
					if x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && dist[i][x2][y2] == -1 {
						dist[i][x2][y2] = step
						q = append(q, [2]int{x2, y2})
					}
				}
			}
		}
	}
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, 1<<n)
		for j := range f[i] {
			f[i][j] = make([]int, 2)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	var dfs func(last, state, k int) int
	dfs = func(last, state, k int) int {
		if state == 0 {
			return 0
		}
		if f[last][state][k] != -1 {
			return f[last][state][k]
		}

		var res int
		if k == 0 {
			res = math.MaxInt32
		}

		for i, p := range positions {
			x, y := p[0], p[1]
			if (state>>i)&1 == 1 {
				t := dfs(i, state^(1<<i), k^1) + dist[last][x][y]
				if k == 1 {
					res = max(res, t)
				} else {
					res = min(res, t)
				}
			}
		}
		f[last][state][k] = res
		return res
	}

	return dfs(n, (1<<n)-1, 1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>50 x 50</code>&nbsp;的国际象棋棋盘，棋盘上有 <strong>一个</strong>&nbsp;马和一些兵。给你两个整数&nbsp;<code>kx</code> 和&nbsp;<code>ky</code>&nbsp;，其中&nbsp;<code>(kx, ky)</code>&nbsp;表示马所在的位置，同时还有一个二维数组&nbsp;<code>positions</code>&nbsp;，其中&nbsp;<code>positions[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示第 <code>i</code>&nbsp;个兵在棋盘上的位置。</p>

<p>Alice 和 Bob 玩一个回合制游戏，Alice 先手。玩家的一次操作中，可以执行以下操作：</p>

<ul>
	<li>玩家选择一个仍然在棋盘上的兵，然后移动马，通过 <strong>最少</strong>&nbsp;的 <strong>步数</strong> 吃掉这个兵。<strong>注意</strong>&nbsp;，玩家可以选择&nbsp;<strong>任意</strong>&nbsp;一个兵，<strong>不一定</strong>&nbsp;要选择从马的位置出发&nbsp;<strong>最少</strong>&nbsp;移动步数的兵。</li>
	<li><span>在马吃兵的过程中，马 <strong>可能</strong>&nbsp;会经过一些其他兵的位置，但这些兵 <strong>不会</strong>&nbsp;被吃掉。<strong>只有</strong>&nbsp;选中的兵在这个回合中被吃掉。</span></li>
</ul>

<p>Alice 的目标是 <strong>最大化</strong>&nbsp;两名玩家的 <strong>总</strong>&nbsp;移动次数，直到棋盘上不再存在兵，而 Bob 的目标是 <strong>最小化</strong>&nbsp;总移动次数。</p>

<p>假设两名玩家都采用 <strong>最优</strong>&nbsp;策略，请你返回可以达到的 <strong>最大</strong>&nbsp;总移动次数。</p>

<p>在一次&nbsp;<strong>移动</strong>&nbsp;中，如下图所示，马有 8 个可以移动到的位置，每个移动位置都是沿着坐标轴的一个方向前进 2 格，然后沿着垂直的方向前进 1 格。</p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3283.Maximum%20Number%20of%20Moves%20to%20Kill%20All%20Pawns/images/chess_knight.jpg" style="width: 275px; height: 273px;" /></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>kx = 1, ky = 1, positions = [[0,0]]</span></p>

<p><span class="example-io"><b>输出：</b>4</span></p>

<p><strong>解释：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3283.Maximum%20Number%20of%20Moves%20to%20Kill%20All%20Pawns/images/gif3.gif" style="width: 275px; height: 275px;" /></p>

<p>马需要移动 4 步吃掉&nbsp;<code>(0, 0)</code>&nbsp;处的兵。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]</span></p>

<p><span class="example-io"><b>输出：</b>8</span></p>

<p><strong>解释：</strong></p>

<p><strong><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3283.Maximum%20Number%20of%20Moves%20to%20Kill%20All%20Pawns/images/gif4.gif" style="width: 320px; height: 320px;" /></strong></p>

<ul>
	<li>Alice 选择&nbsp;<code>(2, 2)</code>&nbsp;处的兵，移动马吃掉它需要 2 步：<code>(0, 2) -&gt; (1, 4) -&gt; (2, 2)</code>&nbsp;。</li>
	<li>Bob 选择&nbsp;<code>(3, 3)</code>&nbsp;处的兵，移动马吃掉它需要 2 步：<code>(2, 2) -&gt; (4, 1) -&gt; (3, 3)</code>&nbsp;。</li>
	<li>Alice 选择&nbsp;<code>(1, 1)</code>&nbsp;处的兵，移动马吃掉它需要 4 步：<code>(3, 3) -&gt; (4, 1) -&gt; (2, 2) -&gt; (0, 3) -&gt; (1, 1)</code>&nbsp;。</li>
</ul>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>kx = 0, ky = 0, positions = [[1,2],[2,4]]</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>Alice 选择&nbsp;<code>(2, 4)</code>&nbsp;处的兵，移动马吃掉它需要 2 步：<code>(0, 0) -&gt; (1, 2) -&gt; (2, 4)</code>&nbsp;。注意，<code>(1, 2)</code>&nbsp;处的兵不会被吃掉。</li>
	<li>Bob 选择&nbsp;<code>(1, 2)</code>&nbsp;处的兵，移动马吃掉它需要 1 步：<code>(2, 4) -&gt; (1, 2)</code>&nbsp;。</li>
</ul>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= kx, ky &lt;= 49</code></li>
	<li><code>1 &lt;= positions.length &lt;= 15</code></li>
	<li><code>positions[i].length == 2</code></li>
	<li><code>0 &lt;= positions[i][0], positions[i][1] &lt;= 49</code></li>
	<li><code>positions[i]</code>&nbsp;两两互不相同。</li>
	<li>输入保证对于所有&nbsp;<code>0 &lt;= i &lt; positions.length</code>&nbsp;，都有&nbsp;<code>positions[i] != [kx, ky]</code>&nbsp;。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS + 状态压缩 + 记忆化搜索

我们首先预处理出每个兵到棋盘上任意一个位置的马的最短距离，记录在数组 $\textit{dist}$ 中，即 $\textit{dist}[i][x][y]$ 表示第 $i$ 个兵到 $(x, y)$ 位置的马的最短距离。

接下来，我们设计一个函数 $\text{dfs}(\textit{last}, \textit{state}, \textit{k})$，其中 $\textit{last}$ 表示上一个吃掉的兵的编号，而 $\textit{state}$ 表示当前还剩下的兵的状态，而 $\textit{k}$ 表示当前是 Alice 还是 Bob 的回合。函数的返回值表示当前回合的最大移动次数。那么答案为 $\text{dfs}(n, 2^n-1, 1)$。这里我们初始时上一个吃掉的兵的编号记为 $n$，这也是马所在的位置。

函数 $\text{dfs}$ 的具体实现如下：

-   如果 $\textit{state} = 0$，表示没有兵了，返回 $0$；
-   如果 $\textit{k} = 1$，表示当前是 Alice 的回合，我们需要找到一个兵，使得吃掉这个兵后的移动次数最大，即 $\text{dfs}(i, \textit{state} \oplus 2^i, \textit{k} \oplus 1) + \textit{dist}[\textit{last}][x][y]$；
-   如果 $\textit{k} = 0$，表示当前是 Bob 的回合，我们需要找到一个兵，使得吃掉这个兵后的移动次数最小，即 $\text{dfs}(i, \textit{state} \oplus 2^i, \textit{k} \oplus 1) + \textit{dist}[\textit{last}][x][y]$。

为了避免重复计算，我们使用记忆化搜索，即使用哈希表记录已经计算过的状态。

时间复杂度 $O(n \times m^2 + 2^n \times n^2)$，空间复杂度 $O(n \times m^2 + 2^n \times n)$。其中 $n$ 和 $m$ 分别为兵的数量和棋盘的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:
        @cache
        def dfs(last: int, state: int, k: int) -> int:
            if state == 0:
                return 0
            if k:
                res = 0
                for i, (x, y) in enumerate(positions):
                    if state >> i & 1:
                        t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y]
                        if res < t:
                            res = t
                return res
            else:
                res = inf
                for i, (x, y) in enumerate(positions):
                    if state >> i & 1:
                        t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y]
                        if res > t:
                            res = t
                return res

        n = len(positions)
        m = 50
        dist = [[[-1] * m for _ in range(m)] for _ in range(n + 1)]
        dx = [1, 1, 2, 2, -1, -1, -2, -2]
        dy = [2, -2, 1, -1, 2, -2, 1, -1]
        positions.append([kx, ky])
        for i, (x, y) in enumerate(positions):
            dist[i][x][y] = 0
            q = deque([(x, y)])
            step = 0
            while q:
                step += 1
                for _ in range(len(q)):
                    x1, y1 = q.popleft()
                    for j in range(8):
                        x2, y2 = x1 + dx[j], y1 + dy[j]
                        if 0 <= x2 < m and 0 <= y2 < m and dist[i][x2][y2] == -1:
                            dist[i][x2][y2] = step
                            q.append((x2, y2))

        ans = dfs(n, (1 << n) - 1, 1)
        dfs.cache_clear()
        return ans
```

#### Java

```java
class Solution {
    private Integer[][][] f;
    private Integer[][][] dist;
    private int[][] positions;
    private final int[] dx = {1, 1, 2, 2, -1, -1, -2, -2};
    private final int[] dy = {2, -2, 1, -1, 2, -2, 1, -1};

    public int maxMoves(int kx, int ky, int[][] positions) {
        int n = positions.length;
        final int m = 50;
        dist = new Integer[n + 1][m][m];
        this.positions = positions;
        for (int i = 0; i <= n; ++i) {
            int x = i < n ? positions[i][0] : kx;
            int y = i < n ? positions[i][1] : ky;
            Deque<int[]> q = new ArrayDeque<>();
            q.offer(new int[] {x, y});
            for (int step = 1; !q.isEmpty(); ++step) {
                for (int k = q.size(); k > 0; --k) {
                    var p = q.poll();
                    int x1 = p[0], y1 = p[1];
                    for (int j = 0; j < 8; ++j) {
                        int x2 = x1 + dx[j], y2 = y1 + dy[j];
                        if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && dist[i][x2][y2] == null) {
                            dist[i][x2][y2] = step;
                            q.offer(new int[] {x2, y2});
                        }
                    }
                }
            }
        }
        f = new Integer[n + 1][1 << n][2];
        return dfs(n, (1 << n) - 1, 1);
    }

    private int dfs(int last, int state, int k) {
        if (state == 0) {
            return 0;
        }
        if (f[last][state][k] != null) {
            return f[last][state][k];
        }
        int res = k == 1 ? 0 : Integer.MAX_VALUE;
        for (int i = 0; i < positions.length; ++i) {
            int x = positions[i][0], y = positions[i][1];
            if ((state >> i & 1) == 1) {
                int t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y];
                res = k == 1 ? Math.max(res, t) : Math.min(res, t);
            }
        }
        return f[last][state][k] = res;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = positions.size();
        const int m = 50;
        const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
        const int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
        int dist[n + 1][m][m];
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i <= n; ++i) {
            int x = (i < n) ? positions[i][0] : kx;
            int y = (i < n) ? positions[i][1] : ky;
            queue<pair<int, int>> q;
            q.push({x, y});
            dist[i][x][y] = 0;
            for (int step = 1; !q.empty(); ++step) {
                for (int k = q.size(); k > 0; --k) {
                    auto [x1, y1] = q.front();
                    q.pop();
                    for (int j = 0; j < 8; ++j) {
                        int x2 = x1 + dx[j], y2 = y1 + dy[j];
                        if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && dist[i][x2][y2] == -1) {
                            dist[i][x2][y2] = step;
                            q.push({x2, y2});
                        }
                    }
                }
            }
        }

        int f[n + 1][1 << n][2];
        memset(f, -1, sizeof(f));
        auto dfs = [&](this auto&& dfs, int last, int state, int k) -> int {
            if (state == 0) {
                return 0;
            }
            if (f[last][state][k] != -1) {
                return f[last][state][k];
            }
            int res = (k == 1) ? 0 : INT_MAX;

            for (int i = 0; i < positions.size(); ++i) {
                int x = positions[i][0], y = positions[i][1];
                if ((state >> i) & 1) {
                    int t = dfs(i, state ^ (1 << i), k ^ 1) + dist[last][x][y];
                    if (k == 1) {
                        res = max(res, t);
                    } else {
                        res = min(res, t);
                    }
                }
            }
            return f[last][state][k] = res;
        };
        return dfs(n, (1 << n) - 1, 1);
    }
};
```

#### Go

```go
func maxMoves(kx int, ky int, positions [][]int) int {
	n := len(positions)
	const m = 50
	dx := []int{1, 1, 2, 2, -1, -1, -2, -2}
	dy := []int{2, -2, 1, -1, 2, -2, 1, -1}
	dist := make([][][]int, n+1)
	for i := range dist {
		dist[i] = make([][]int, m)
		for j := range dist[i] {
			dist[i][j] = make([]int, m)
			for k := range dist[i][j] {
				dist[i][j][k] = -1
			}
		}
	}

	for i := 0; i <= n; i++ {
		x := kx
		y := ky
		if i < n {
			x = positions[i][0]
			y = positions[i][1]
		}
		q := [][2]int{[2]int{x, y}}
		dist[i][x][y] = 0

		for step := 1; len(q) > 0; step++ {
			for k := len(q); k > 0; k-- {
				p := q[0]
				q = q[1:]
				x1, y1 := p[0], p[1]
				for j := 0; j < 8; j++ {
					x2 := x1 + dx[j]
					y2 := y1 + dy[j]
					if x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && dist[i][x2][y2] == -1 {
						dist[i][x2][y2] = step
						q = append(q, [2]int{x2, y2})
					}
				}
			}
		}
	}
	f := make([][][]int, n+1)
	for i := range f {
		f[i] = make([][]int, 1<<n)
		for j := range f[i] {
			f[i][j] = make([]int, 2)
			for k := range f[i][j] {
				f[i][j][k] = -1
			}
		}
	}
	var dfs func(last, state, k int) int
	dfs = func(last, state, k int) int {
		if state == 0 {
			return 0
		}
		if f[last][state][k] != -1 {
			return f[last][state][k]
		}

		var res int
		if k == 0 {
			res = math.MaxInt32
		}

		for i, p := range positions {
			x, y := p[0], p[1]
			if (state>>i)&1 == 1 {
				t := dfs(i, state^(1<<i), k^1) + dist[last][x][y]
				if k == 1 {
					res = max(res, t)
				} else {
					res = min(res, t)
				}
			}
		}
		f[last][state][k] = res
		return res
	}

	return dfs(n, (1<<n)-1, 1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3284. 连续子数组的和 🔒](https://leetcode.cn/problems/sum-of-consecutive-subarrays){#3284}

{{< tabs "3284" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSum(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        f = g = 1
        s = t = nums[0]
        ans = nums[0]
        for x, y in pairwise(nums):
            if y - x == 1:
                f += 1
                s += f * y
                ans = (ans + s) % mod
            else:
                f = 1
                s = y
            if y - x == -1:
                g += 1
                t += g * y
                ans = (ans + t) % mod
            else:
                g = 1
                t = y
            if abs(y - x) != 1:
                ans = (ans + y) % mod
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int getSum(int[] nums) {
        final int mod = (int) 1e9 + 7;
        long s = nums[0], t = nums[0], ans = nums[0];
        int f = 1, g = 1;
        for (int i = 1; i < nums.length; ++i) {
            int x = nums[i - 1], y = nums[i];
            if (y - x == 1) {
                ++f;
                s += 1L * f * y;
                ans = (ans + s) % mod;
            } else {
                f = 1;
                s = y;
            }
            if (y - x == -1) {
                ++g;
                t += 1L * g * y;
                ans = (ans + t) % mod;
            } else {
                g = 1;
                t = y;
            }
            if (Math.abs(y - x) != 1) {
                ans = (ans + y) % mod;
            }
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
    int getSum(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long s = nums[0], t = nums[0], ans = nums[0];
        int f = 1, g = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i - 1], y = nums[i];
            if (y - x == 1) {
                ++f;
                s += 1LL * f * y;
                ans = (ans + s) % mod;
            } else {
                f = 1;
                s = y;
            }
            if (y - x == -1) {
                ++g;
                t += 1LL * g * y;
                ans = (ans + t) % mod;
            } else {
                g = 1;
                t = y;
            }
            if (abs(y - x) != 1) {
                ans = (ans + y) % mod;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSum(nums []int) int {
	const mod int = 1e9 + 7
	f, g := 1, 1
	s, t := nums[0], nums[0]
	ans := nums[0]

	for i := 1; i < len(nums); i++ {
		x, y := nums[i-1], nums[i]

		if y-x == 1 {
			f++
			s += f * y
			ans = (ans + s) % mod
		} else {
			f = 1
			s = y
		}

		if y-x == -1 {
			g++
			t += g * y
			ans = (ans + t) % mod
		} else {
			g = 1
			t = y
		}

		if abs(y-x) != 1 {
			ans = (ans + y) % mod
		}
	}

	return ans
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
function getSum(nums: number[]): number {
    const mod = 10 ** 9 + 7;
    let f = 1,
        g = 1;
    let s = nums[0],
        t = nums[0];
    let ans = nums[0];

    for (let i = 1; i < nums.length; i++) {
        const x = nums[i - 1];
        const y = nums[i];

        if (y - x === 1) {
            f++;
            s += f * y;
            ans = (ans + s) % mod;
        } else {
            f = 1;
            s = y;
        }

        if (y - x === -1) {
            g++;
            t += g * y;
            ans = (ans + t) % mod;
        } else {
            g = 1;
            t = y;
        }

        if (Math.abs(y - x) !== 1) {
            ans = (ans + y) % mod;
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

<p>如果一个长度为&nbsp;<code>n</code>&nbsp;的数组&nbsp;<code>arr</code>&nbsp;符合下面其中一个条件，可以称它 <strong>连续</strong>：</p>

<ul>
	<li>对于所有的&nbsp;<code>1 &lt;= i &lt; n</code>，<code>arr[i] - arr[i - 1] == 1</code>。</li>
	<li>对于所有的&nbsp;<code>1 &lt;= i &lt; n</code>，<code>arr[i] - arr[i - 1] == -1</code>。</li>
</ul>

<p>数组的 <strong>值</strong> 是其元素的和。</p>

<p>例如，<code>[3, 4, 5]</code>&nbsp;是一个值为 12 的连续数组，并且&nbsp;<code>[9, 8]</code>&nbsp;是另一个值为 17 的连续数组。而&nbsp;<code>[3, 4, 3]</code> 和&nbsp;<code>[8, 6]</code>&nbsp;都不连续。</p>

<p>给定一个整数数组&nbsp;<code>nums</code>，返回所有 <strong>连续</strong> <span data-keyword="subarray-nonempty">子数组</span> 的 <strong>值</strong> 之和。</p>

<p>由于答案可能很大，返回它对&nbsp;<code>10<sup>9 </sup>+ 7</code>&nbsp;<strong>取模</strong>&nbsp;的值。</p>

<p><strong>注意</strong>&nbsp;长度为 1 的数组也被认为是连续的。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,3]</span></p>

<p><span class="example-io"><b>输出：</b>20</span></p>

<p><strong>解释：</strong></p>

<p>连续子数组为：<code>[1]</code>，<code>[2]</code>，<code>[3]</code>，<code>[1, 2]</code>，<code>[2, 3]</code>，<code>[1, 2, 3]</code>。<br />
它们的值之和为：<code>1 + 2 + 3 + 3 + 5 + 6 = 20</code>。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">nums = [1,3,5,7]</span></p>

<p><span class="example-io"><b>输出：</b>16</span></p>

<p><strong>解释：</strong></p>

<p>连续子数组为：<code>[1]</code>，<code>[3]</code>，<code>[5]</code>，<code>[7]</code>。<br />
它们的值之和为：<code>1 + 3 + 5 + 7 = 16</code>。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [7,6,1,2]</span></p>

<p><strong>输出：</strong><span class="example-io">32</span></p>

<p><strong>解释：</strong></p>

<p>连续子数组为：<code>[7]</code>，<code>[6]</code>，<code>[1]</code>，<code>[2]</code>，<code>[7, 6]</code>，<code>[1, 2]</code>。<br />
它们的值之和为&nbsp;<code>7 + 6 + 1 + 2 + 13 + 3 = 32</code>。</p>
</div>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递推

我们定义两个变量 $f$ 和 $g$，分别表示以当前元素结尾的递增子数组的长度和以当前元素结尾的递减子数组的长度，用另外两个变量 $s$ 和 $t$ 分别表示以当前元素结尾的递增子数组的和和以当前元素结尾的递减子数组的和。初始时 $f = g = 1$，而 $s = t = \textit{nums}[0]$。

接下来，我们从第二个元素开始遍历数组，对于当前元素 $\textit{nums}[i]$，我们分别考虑以 $\textit{nums}[i]$ 结尾的递增子数组和递减子数组。

如果 $\textit{nums}[i] - \textit{nums}[i - 1] = 1$，那么 $\textit{nums}[i]$ 可以加入到以 $\textit{nums}[i - 1]$ 结尾的递增子数组中，此时我们更新 $f$ 和 $s$，并将 $s$ 加到答案中；

如果 $\textit{nums}[i] - \textit{nums}[i - 1] = -1$，那么 $\textit{nums}[i]$ 可以加入到以 $\textit{nums}[i - 1]$ 结尾的递减子数组中，此时我们更新 $g$ 和 $t$，并将 $t$ 加到答案中。

否则，$\textit{nums}[i]$ 无法加入到以 $\textit{nums}[i - 1]$ 结尾的递增子数组或递减子数组中，我们将 $\textit{nums}[i]$ 加到答案中。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSum(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        f = g = 1
        s = t = nums[0]
        ans = nums[0]
        for x, y in pairwise(nums):
            if y - x == 1:
                f += 1
                s += f * y
                ans = (ans + s) % mod
            else:
                f = 1
                s = y
            if y - x == -1:
                g += 1
                t += g * y
                ans = (ans + t) % mod
            else:
                g = 1
                t = y
            if abs(y - x) != 1:
                ans = (ans + y) % mod
        return ans
```

#### Java

```java
class Solution {
    public int getSum(int[] nums) {
        final int mod = (int) 1e9 + 7;
        long s = nums[0], t = nums[0], ans = nums[0];
        int f = 1, g = 1;
        for (int i = 1; i < nums.length; ++i) {
            int x = nums[i - 1], y = nums[i];
            if (y - x == 1) {
                ++f;
                s += 1L * f * y;
                ans = (ans + s) % mod;
            } else {
                f = 1;
                s = y;
            }
            if (y - x == -1) {
                ++g;
                t += 1L * g * y;
                ans = (ans + t) % mod;
            } else {
                g = 1;
                t = y;
            }
            if (Math.abs(y - x) != 1) {
                ans = (ans + y) % mod;
            }
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int getSum(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long s = nums[0], t = nums[0], ans = nums[0];
        int f = 1, g = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int x = nums[i - 1], y = nums[i];
            if (y - x == 1) {
                ++f;
                s += 1LL * f * y;
                ans = (ans + s) % mod;
            } else {
                f = 1;
                s = y;
            }
            if (y - x == -1) {
                ++g;
                t += 1LL * g * y;
                ans = (ans + t) % mod;
            } else {
                g = 1;
                t = y;
            }
            if (abs(y - x) != 1) {
                ans = (ans + y) % mod;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getSum(nums []int) int {
	const mod int = 1e9 + 7
	f, g := 1, 1
	s, t := nums[0], nums[0]
	ans := nums[0]

	for i := 1; i < len(nums); i++ {
		x, y := nums[i-1], nums[i]

		if y-x == 1 {
			f++
			s += f * y
			ans = (ans + s) % mod
		} else {
			f = 1
			s = y
		}

		if y-x == -1 {
			g++
			t += g * y
			ans = (ans + t) % mod
		} else {
			g = 1
			t = y
		}

		if abs(y-x) != 1 {
			ans = (ans + y) % mod
		}
	}

	return ans
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
function getSum(nums: number[]): number {
    const mod = 10 ** 9 + 7;
    let f = 1,
        g = 1;
    let s = nums[0],
        t = nums[0];
    let ans = nums[0];

    for (let i = 1; i < nums.length; i++) {
        const x = nums[i - 1];
        const y = nums[i];

        if (y - x === 1) {
            f++;
            s += f * y;
            ans = (ans + s) % mod;
        } else {
            f = 1;
            s = y;
        }

        if (y - x === -1) {
            g++;
            t += g * y;
            ans = (ans + t) % mod;
        } else {
            g = 1;
            t = y;
        }

        if (Math.abs(y - x) !== 1) {
            ans = (ans + y) % mod;
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

# [3285. 找到稳定山的下标](https://leetcode.cn/problems/find-indices-of-stable-mountains){#3285}

{{< tabs "3285" >}}

{{% tab "python" %}}
```python
class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        return [i for i in range(1, len(height)) if height[i - 1] > threshold]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < height.length; ++i) {
            if (height[i - 1] > threshold) {
                ans.add(i);
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
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func stableMountains(height []int, threshold int) (ans []int) {
	for i := 1; i < len(height); i++ {
		if height[i-1] > threshold {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function stableMountains(height: number[], threshold: number): number[] {
    const ans: number[] = [];
    for (let i = 1; i < height.length; ++i) {
        if (height[i - 1] > threshold) {
            ans.push(i);
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

<p>有&nbsp;<code>n</code>&nbsp;座山排成一列，每座山都有一个高度。给你一个整数数组&nbsp;<code>height</code>&nbsp;，其中&nbsp;<code>height[i]</code>&nbsp;表示第 <code>i</code>&nbsp;座山的高度，再给你一个整数&nbsp;<code>threshold</code>&nbsp;。</p>

<p>对于下标不为 <code>0</code>&nbsp;的一座山，如果它左侧相邻的山的高度 <strong>严格</strong><strong>大于</strong>&nbsp;<code>threshold</code>&nbsp;，那么我们称它是 <strong>稳定</strong>&nbsp;的。我们定义下标为 <code>0</code>&nbsp;的山 <strong>不是</strong>&nbsp;稳定的。</p>

<p>请你返回一个数组，包含所有 <strong>稳定</strong>&nbsp;山的下标，你可以以 <strong>任意</strong>&nbsp;顺序返回下标数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>height = [1,2,3,4,5], threshold = 2</span></p>

<p><span class="example-io"><b>输出：</b>[3,4]</span></p>

<p><strong>解释：</strong></p>

<ul>
	<li>下标为 3 的山是稳定的，因为&nbsp;<code>height[2] == 3</code>&nbsp;大于&nbsp;<code>threshold == 2</code>&nbsp;。</li>
	<li>下标为 4 的山是稳定的，因为&nbsp;<code>height[3] == 4</code> 大于 <code>threshold == 2</code>.</li>
</ul>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>height = [10,1,10,1,10], threshold = 3</span></p>

<p><span class="example-io"><b>输出：</b>[1,3]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>height = [10,1,10,1,10], threshold = 10</span></p>

<p><span class="example-io"><b>输出：</b>[]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == height.length &lt;= 100</code></li>
	<li><code>1 &lt;= height[i] &lt;= 100</code></li>
	<li><code>1 &lt;= threshold &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们直接从下标为 $1$ 的山开始遍历，如果它左侧相邻的山的高度大于 $threshold$，那么我们就将它的下标加入到结果数组中。

遍历结束后，返回结果数组即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $\textit{height}$ 的长度。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        return [i for i in range(1, len(height)) if height[i - 1] > threshold]
```

#### Java

```java
class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < height.length; ++i) {
            if (height[i - 1] > threshold) {
                ans.add(i);
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
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> ans;
        for (int i = 1; i < height.size(); ++i) {
            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func stableMountains(height []int, threshold int) (ans []int) {
	for i := 1; i < len(height); i++ {
		if height[i-1] > threshold {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function stableMountains(height: number[], threshold: number): number[] {
    const ans: number[] = [];
    for (let i = 1; i < height.length; ++i) {
        if (height[i - 1] > threshold) {
            ans.push(i);
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

# [3286. 穿越网格图的安全路径](https://leetcode.cn/problems/find-a-safe-walk-through-a-grid){#3286}

{{< tabs "3286" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = grid[0][0]
        q = deque([(0, 0)])
        dirs = (-1, 0, 1, 0, -1)
        while q:
            x, y = q.popleft()
            for a, b in pairwise(dirs):
                nx, ny = x + a, y + b
                if (
                    0 <= nx < m
                    and 0 <= ny < n
                    and dist[nx][ny] > dist[x][y] + grid[nx][ny]
                ):
                    dist[nx][ny] = dist[x][y] + grid[nx][ny]
                    q.append((nx, ny))
        return dist[-1][-1] < health
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();
        int[][] dist = new int[m][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = grid.get(0).get(0);
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        final int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0], y = curr[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n
                    && dist[nx][ny] > dist[x][y] + grid.get(nx).get(ny)) {
                    dist[nx][ny] = dist[x][y] + grid.get(nx).get(ny);
                    q.offer(new int[] {nx, ny});
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + grid[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    q.emplace(nx, ny);
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSafeWalk(grid [][]int, health int) bool {
	m, n := len(grid), len(grid[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
		}
	}
	dist[0][0] = grid[0][0]
	q := [][2]int{{0, 0}}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		x, y := curr[0], curr[1]
		for i := 0; i < 4; i++ {
			nx, ny := x+dirs[i], y+dirs[i+1]
			if nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y]+grid[nx][ny] {
				dist[nx][ny] = dist[x][y] + grid[nx][ny]
				q = append(q, [2]int{nx, ny})
			}
		}
	}
	return dist[m-1][n-1] < health
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSafeWalk(grid: number[][], health: number): boolean {
    const m = grid.length;
    const n = grid[0].length;
    const dist: number[][] = Array.from({ length: m }, () => Array(n).fill(Infinity));
    dist[0][0] = grid[0][0];
    const q: [number, number][] = [[0, 0]];
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length > 0) {
        const [x, y] = q.shift()!;
        for (let i = 0; i < 4; i++) {
            const nx = x + dirs[i];
            const ny = y + dirs[i + 1];
            if (
                nx >= 0 &&
                nx < m &&
                ny >= 0 &&
                ny < n &&
                dist[nx][ny] > dist[x][y] + grid[nx][ny]
            ) {
                dist[nx][ny] = dist[x][y] + grid[nx][ny];
                q.push([nx, ny]);
            }
        }
    }
    return dist[m - 1][n - 1] < health;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个&nbsp;<code>m x n</code>&nbsp;的二进制矩形&nbsp;<code>grid</code>&nbsp;和一个整数&nbsp;<code>health</code>&nbsp;表示你的健康值。</p>

<p>你开始于矩形的左上角&nbsp;<code>(0, 0)</code>&nbsp;，你的目标是矩形的右下角&nbsp;<code>(m - 1, n - 1)</code>&nbsp;。</p>

<p>你可以在矩形中往上下左右相邻格子移动，但前提是你的健康值始终是 <b>正数</b>&nbsp;。</p>

<p>对于格子&nbsp;<code>(i, j)</code>&nbsp;，如果&nbsp;<code>grid[i][j] = 1</code>&nbsp;，那么这个格子视为 <strong>不安全</strong>&nbsp;的，会使你的健康值减少 1 。</p>

<p>如果你可以到达最终的格子，请你返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code>&nbsp;。</p>

<p><b>注意</b>&nbsp;，当你在最终格子的时候，你的健康值也必须为<strong>&nbsp;正数</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><b>解释：</b></p>

<p>沿着下图中灰色格子走，可以安全到达最终的格子。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3286.Find%20a%20Safe%20Walk%20Through%20a%20Grid/images/3868_examples_1drawio.png" style="width: 301px; height: 121px;" /></div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3</span></p>

<p><span class="example-io"><b>输出：</b>false</span></p>

<p><b>解释：</b></p>

<p>健康值最少为 4 才能安全到达最后的格子。</p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3286.Find%20a%20Safe%20Walk%20Through%20a%20Grid/images/3868_examples_2drawio.png" style="width: 361px; height: 161px;" /></div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5</span></p>

<p><span class="example-io"><b>输出：</b>true</span></p>

<p><b>解释：</b></p>

<p>沿着下图中灰色格子走，可以安全到达最终的格子。</p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3200-3299/3286.Find%20a%20Safe%20Walk%20Through%20a%20Grid/images/3868_examples_3drawio.png" style="width: 181px; height: 121px;" /></p>

<p>任何不经过格子&nbsp;<code>(1, 1)</code>&nbsp;的路径都是不安全的，因为你的健康值到达最终格子时，都会小于等于 0 。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
<li><code>2 <= m * n</code></li>
	<li><code>1 &lt;= health &lt;= m + n</code></li>
	<li><code>grid[i][j]</code>&nbsp;要么是 0 ，要么是 1 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们定义一个二维数组 $\textit{dist}$，其中 $\textit{dist}[i][j]$ 表示从左上角到达 $(i, j)$ 位置的最小健康值。初始时，我们将 $\textit{dist}[0][0]$ 设为 $\textit{grid}[0][0]$，并将 $(0, 0)$ 加入队列 $\textit{q}$ 中。

随后我们不断取出队列中的元素 $(x, y)$，并尝试向四个方向移动。如果移动到了一个合法的位置 $(nx, ny)$，且从 $(x, y)$ 移动到 $(nx, ny)$ 的健康值消耗更小，那么我们就可以更新 $\textit{dist}[nx][ny] = \textit{dist}[x][y] + \textit{grid}[nx][ny]$，并将 $(nx, ny)$ 加入队列 $\textit{q}$ 中。

最终，当队列为空时，我们就可以得到 $\textit{dist}[m-1][n-1]$，即从左上角到达右下角的最小健康值。如果这个值小于 $\textit{health}$，那么我们就可以到达右下角，否则我们无法到达。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩形的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m, n = len(grid), len(grid[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = grid[0][0]
        q = deque([(0, 0)])
        dirs = (-1, 0, 1, 0, -1)
        while q:
            x, y = q.popleft()
            for a, b in pairwise(dirs):
                nx, ny = x + a, y + b
                if (
                    0 <= nx < m
                    and 0 <= ny < n
                    and dist[nx][ny] > dist[x][y] + grid[nx][ny]
                ):
                    dist[nx][ny] = dist[x][y] + grid[nx][ny]
                    q.append((nx, ny))
        return dist[-1][-1] < health
```

#### Java

```java
class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();
        int[][] dist = new int[m][n];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = grid.get(0).get(0);
        Deque<int[]> q = new ArrayDeque<>();
        q.offer(new int[] {0, 0});
        final int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0], y = curr[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n
                    && dist[nx][ny] > dist[x][y] + grid.get(nx).get(ny)) {
                    dist[nx][ny] = dist[x][y] + grid.get(nx).get(ny);
                    q.offer(new int[] {nx, ny});
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + grid[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    q.emplace(nx, ny);
                }
            }
        }
        return dist[m - 1][n - 1] < health;
    }
};
```

#### Go

```go
func findSafeWalk(grid [][]int, health int) bool {
	m, n := len(grid), len(grid[0])
	dist := make([][]int, m)
	for i := range dist {
		dist[i] = make([]int, n)
		for j := range dist[i] {
			dist[i][j] = math.MaxInt32
		}
	}
	dist[0][0] = grid[0][0]
	q := [][2]int{{0, 0}}
	dirs := []int{-1, 0, 1, 0, -1}
	for len(q) > 0 {
		curr := q[0]
		q = q[1:]
		x, y := curr[0], curr[1]
		for i := 0; i < 4; i++ {
			nx, ny := x+dirs[i], y+dirs[i+1]
			if nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y]+grid[nx][ny] {
				dist[nx][ny] = dist[x][y] + grid[nx][ny]
				q = append(q, [2]int{nx, ny})
			}
		}
	}
	return dist[m-1][n-1] < health
}
```

#### TypeScript

```ts
function findSafeWalk(grid: number[][], health: number): boolean {
    const m = grid.length;
    const n = grid[0].length;
    const dist: number[][] = Array.from({ length: m }, () => Array(n).fill(Infinity));
    dist[0][0] = grid[0][0];
    const q: [number, number][] = [[0, 0]];
    const dirs = [-1, 0, 1, 0, -1];
    while (q.length > 0) {
        const [x, y] = q.shift()!;
        for (let i = 0; i < 4; i++) {
            const nx = x + dirs[i];
            const ny = y + dirs[i + 1];
            if (
                nx >= 0 &&
                nx < m &&
                ny >= 0 &&
                ny < n &&
                dist[nx][ny] > dist[x][y] + grid[nx][ny]
            ) {
                dist[nx][ny] = dist[x][y] + grid[nx][ny];
                q.push([nx, ny]);
            }
        }
    }
    return dist[m - 1][n - 1] < health;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3287. 求出数组中最大序列值](https://leetcode.cn/problems/find-the-maximum-sequence-value-of-array){#3287}

{{< tabs "3287" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxValue(self, nums: List[int], k: int) -> int:
        m = 1 << 7
        n = len(nums)
        f = [[[False] * m for _ in range(k + 2)] for _ in range(n + 1)]
        f[0][0][0] = True
        for i in range(n):
            for j in range(k + 1):
                for x in range(m):
                    f[i + 1][j][x] |= f[i][j][x]
                    f[i + 1][j + 1][x | nums[i]] |= f[i][j][x]

        g = [[[False] * m for _ in range(k + 2)] for _ in range(n + 1)]
        g[n][0][0] = True
        for i in range(n, 0, -1):
            for j in range(k + 1):
                for y in range(m):
                    g[i - 1][j][y] |= g[i][j][y]
                    g[i - 1][j + 1][y | nums[i - 1]] |= g[i][j][y]

        ans = 0
        for i in range(k, n - k + 1):
            for x in range(m):
                if f[i][k][x]:
                    for y in range(m):
                        if g[i][k][y]:
                            ans = max(ans, x ^ y)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxValue(int[] nums, int k) {
        int m = 1 << 7;
        int n = nums.length;
        boolean[][][] f = new boolean[n + 1][k + 2][m];
        f[0][0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < m; x++) {
                    if (f[i][j][x]) {
                        f[i + 1][j][x] = true;
                        f[i + 1][j + 1][x | nums[i]] = true;
                    }
                }
            }
        }

        boolean[][][] g = new boolean[n + 1][k + 2][m];
        g[n][0][0] = true;

        for (int i = n; i > 0; i--) {
            for (int j = 0; j <= k; j++) {
                for (int y = 0; y < m; y++) {
                    if (g[i][j][y]) {
                        g[i - 1][j][y] = true;
                        g[i - 1][j + 1][y | nums[i - 1]] = true;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = k; i <= n - k; i++) {
            for (int x = 0; x < m; x++) {
                if (f[i][k][x]) {
                    for (int y = 0; y < m; y++) {
                        if (g[i][k][y]) {
                            ans = Math.max(ans, x ^ y);
                        }
                    }
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
    int maxValue(vector<int>& nums, int k) {
        int m = 1 << 7;
        int n = nums.size();

        vector<vector<vector<bool>>> f(n + 1, vector<vector<bool>>(k + 2, vector<bool>(m, false)));
        f[0][0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < m; x++) {
                    if (f[i][j][x]) {
                        f[i + 1][j][x] = true;
                        f[i + 1][j + 1][x | nums[i]] = true;
                    }
                }
            }
        }

        vector<vector<vector<bool>>> g(n + 1, vector<vector<bool>>(k + 2, vector<bool>(m, false)));
        g[n][0][0] = true;

        for (int i = n; i > 0; i--) {
            for (int j = 0; j <= k; j++) {
                for (int y = 0; y < m; y++) {
                    if (g[i][j][y]) {
                        g[i - 1][j][y] = true;
                        g[i - 1][j + 1][y | nums[i - 1]] = true;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = k; i <= n - k; i++) {
            for (int x = 0; x < m; x++) {
                if (f[i][k][x]) {
                    for (int y = 0; y < m; y++) {
                        if (g[i][k][y]) {
                            ans = max(ans, x ^ y);
                        }
                    }
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
func maxValue(nums []int, k int) int {
	m := 1 << 7
	n := len(nums)

	f := make([][][]bool, n+1)
	for i := range f {
		f[i] = make([][]bool, k+2)
		for j := range f[i] {
			f[i][j] = make([]bool, m)
		}
	}
	f[0][0][0] = true

	for i := 0; i < n; i++ {
		for j := 0; j <= k; j++ {
			for x := 0; x < m; x++ {
				if f[i][j][x] {
					f[i+1][j][x] = true
					f[i+1][j+1][x|nums[i]] = true
				}
			}
		}
	}

	g := make([][][]bool, n+1)
	for i := range g {
		g[i] = make([][]bool, k+2)
		for j := range g[i] {
			g[i][j] = make([]bool, m)
		}
	}
	g[n][0][0] = true

	for i := n; i > 0; i-- {
		for j := 0; j <= k; j++ {
			for y := 0; y < m; y++ {
				if g[i][j][y] {
					g[i-1][j][y] = true
					g[i-1][j+1][y|nums[i-1]] = true
				}
			}
		}
	}

	ans := 0

	for i := k; i <= n-k; i++ {
		for x := 0; x < m; x++ {
			if f[i][k][x] {
				for y := 0; y < m; y++ {
					if g[i][k][y] {
						ans = max(ans, x^y)
					}
				}
			}
		}
	}

	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxValue(nums: number[], k: number): number {
    const m = 1 << 7;
    const n = nums.length;

    const f: boolean[][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 2 }, () => Array(m).fill(false)),
    );
    f[0][0][0] = true;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= k; j++) {
            for (let x = 0; x < m; x++) {
                if (f[i][j][x]) {
                    f[i + 1][j][x] = true;
                    f[i + 1][j + 1][x | nums[i]] = true;
                }
            }
        }
    }

    const g: boolean[][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 2 }, () => Array(m).fill(false)),
    );
    g[n][0][0] = true;

    for (let i = n; i > 0; i--) {
        for (let j = 0; j <= k; j++) {
            for (let y = 0; y < m; y++) {
                if (g[i][j][y]) {
                    g[i - 1][j][y] = true;
                    g[i - 1][j + 1][y | nums[i - 1]] = true;
                }
            }
        }
    }

    let ans = 0;

    for (let i = k; i <= n - k; i++) {
        for (let x = 0; x < m; x++) {
            if (f[i][k][x]) {
                for (let y = 0; y < m; y++) {
                    if (g[i][k][y]) {
                        ans = Math.max(ans, x ^ y);
                    }
                }
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>k</code>&nbsp;。</p>

<p>定义长度为 <code>2 * x</code>&nbsp;的序列 <code>seq</code>&nbsp;的 <strong>值</strong>&nbsp;为：</p>

<ul>
	<li><code>(seq[0] OR seq[1] OR ... OR seq[x - 1]) XOR (seq[x] OR seq[x + 1] OR ... OR seq[2 * x - 1])</code>.</li>
</ul>

<p>请你求出 <code>nums</code>&nbsp;中所有长度为 <code>2 * k</code>&nbsp;的 <span data-keyword="subsequence-array">子序列</span> 的 <strong>最大值</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [2,6,7], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>5</span></p>

<p><strong>解释：</strong></p>

<p>子序列&nbsp;<code>[2, 7]</code>&nbsp;的值最大，为&nbsp;<code>2 XOR 7 = 5</code>&nbsp;。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [4,2,5,6,7], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><strong>解释：</strong></p>

<p>子序列&nbsp;<code>[4, 5, 6, 7]</code>&nbsp;的值最大，为&nbsp;<code>(4 OR 5) XOR (6 OR 7) = 2</code>&nbsp;。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 400</code></li>
	<li><code>1 &lt;= nums[i] &lt; 2<sup>7</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length / 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划 + 前后缀分解 + 枚举

我们考虑将序列分成两部分，前 $k$ 个元素和后 $k$ 个元素，分别计算前后缀的所有可能的异或值。

定义 $f[i][j][x]$ 表示前 $i$ 个元素中取 $j$ 个元素，是否存在一个子集的异或值为 $x$，定义 $g[i][j][y]$ 表示从下标 $i$ 开始取 $j$ 个元素，是否存在一个子集的异或值为 $y$。

考虑 $f[i][j][x]$ 的转移方程，对于第 $i$ 个元素（从 $0$ 开始），我们可以选择不取，也可以选择取，因此有：

$$
f[i + 1][j][x] = f[i + 1][j][x] \lor f[i][j][x] \\
f[i + 1][j + 1][x \lor \text{nums}[i]] = f[i + 1][j + 1][x \lor \text{nums}[i]] \lor f[i][j][x]
$$

对于 $g[i][j][y]$ 的转移方程，同样对于第 $i$ 个元素（从 $n - 1$ 开始），我们可以选择不取，也可以选择取，因此有：

$$
g[i - 1][j][y] = g[i - 1][j][y] \lor g[i][j][y] \\
g[i - 1][j + 1][y \lor \text{nums}[i - 1]] = g[i - 1][j + 1][y \lor \text{nums}[i - 1]] \lor g[i][j][y]
$$

最后，我们在 $[k, n - k]$ 的范围内枚举 $i$，对于每一个 $i$，我们枚举 $x$ 和 $y$，其中 $0 \leq x, y < 2^7$，如果 $f[i][k][x]$ 和 $g[i][k][y]$ 均为真，那么我们更新答案 $\text{ans} = \max(\text{ans}, x \oplus y)$。

时间复杂度 $O(n \times m \times k)$，空间复杂度 $O(n \times m \times k)$，其中 $n$ 为数组长度，而 $m = 2^7$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxValue(self, nums: List[int], k: int) -> int:
        m = 1 << 7
        n = len(nums)
        f = [[[False] * m for _ in range(k + 2)] for _ in range(n + 1)]
        f[0][0][0] = True
        for i in range(n):
            for j in range(k + 1):
                for x in range(m):
                    f[i + 1][j][x] |= f[i][j][x]
                    f[i + 1][j + 1][x | nums[i]] |= f[i][j][x]

        g = [[[False] * m for _ in range(k + 2)] for _ in range(n + 1)]
        g[n][0][0] = True
        for i in range(n, 0, -1):
            for j in range(k + 1):
                for y in range(m):
                    g[i - 1][j][y] |= g[i][j][y]
                    g[i - 1][j + 1][y | nums[i - 1]] |= g[i][j][y]

        ans = 0
        for i in range(k, n - k + 1):
            for x in range(m):
                if f[i][k][x]:
                    for y in range(m):
                        if g[i][k][y]:
                            ans = max(ans, x ^ y)
        return ans
```

#### Java

```java
class Solution {
    public int maxValue(int[] nums, int k) {
        int m = 1 << 7;
        int n = nums.length;
        boolean[][][] f = new boolean[n + 1][k + 2][m];
        f[0][0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < m; x++) {
                    if (f[i][j][x]) {
                        f[i + 1][j][x] = true;
                        f[i + 1][j + 1][x | nums[i]] = true;
                    }
                }
            }
        }

        boolean[][][] g = new boolean[n + 1][k + 2][m];
        g[n][0][0] = true;

        for (int i = n; i > 0; i--) {
            for (int j = 0; j <= k; j++) {
                for (int y = 0; y < m; y++) {
                    if (g[i][j][y]) {
                        g[i - 1][j][y] = true;
                        g[i - 1][j + 1][y | nums[i - 1]] = true;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = k; i <= n - k; i++) {
            for (int x = 0; x < m; x++) {
                if (f[i][k][x]) {
                    for (int y = 0; y < m; y++) {
                        if (g[i][k][y]) {
                            ans = Math.max(ans, x ^ y);
                        }
                    }
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
    int maxValue(vector<int>& nums, int k) {
        int m = 1 << 7;
        int n = nums.size();

        vector<vector<vector<bool>>> f(n + 1, vector<vector<bool>>(k + 2, vector<bool>(m, false)));
        f[0][0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x < m; x++) {
                    if (f[i][j][x]) {
                        f[i + 1][j][x] = true;
                        f[i + 1][j + 1][x | nums[i]] = true;
                    }
                }
            }
        }

        vector<vector<vector<bool>>> g(n + 1, vector<vector<bool>>(k + 2, vector<bool>(m, false)));
        g[n][0][0] = true;

        for (int i = n; i > 0; i--) {
            for (int j = 0; j <= k; j++) {
                for (int y = 0; y < m; y++) {
                    if (g[i][j][y]) {
                        g[i - 1][j][y] = true;
                        g[i - 1][j + 1][y | nums[i - 1]] = true;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = k; i <= n - k; i++) {
            for (int x = 0; x < m; x++) {
                if (f[i][k][x]) {
                    for (int y = 0; y < m; y++) {
                        if (g[i][k][y]) {
                            ans = max(ans, x ^ y);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
```

#### Go

```go
func maxValue(nums []int, k int) int {
	m := 1 << 7
	n := len(nums)

	f := make([][][]bool, n+1)
	for i := range f {
		f[i] = make([][]bool, k+2)
		for j := range f[i] {
			f[i][j] = make([]bool, m)
		}
	}
	f[0][0][0] = true

	for i := 0; i < n; i++ {
		for j := 0; j <= k; j++ {
			for x := 0; x < m; x++ {
				if f[i][j][x] {
					f[i+1][j][x] = true
					f[i+1][j+1][x|nums[i]] = true
				}
			}
		}
	}

	g := make([][][]bool, n+1)
	for i := range g {
		g[i] = make([][]bool, k+2)
		for j := range g[i] {
			g[i][j] = make([]bool, m)
		}
	}
	g[n][0][0] = true

	for i := n; i > 0; i-- {
		for j := 0; j <= k; j++ {
			for y := 0; y < m; y++ {
				if g[i][j][y] {
					g[i-1][j][y] = true
					g[i-1][j+1][y|nums[i-1]] = true
				}
			}
		}
	}

	ans := 0

	for i := k; i <= n-k; i++ {
		for x := 0; x < m; x++ {
			if f[i][k][x] {
				for y := 0; y < m; y++ {
					if g[i][k][y] {
						ans = max(ans, x^y)
					}
				}
			}
		}
	}

	return ans
}
```

#### TypeScript

```ts
function maxValue(nums: number[], k: number): number {
    const m = 1 << 7;
    const n = nums.length;

    const f: boolean[][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 2 }, () => Array(m).fill(false)),
    );
    f[0][0][0] = true;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j <= k; j++) {
            for (let x = 0; x < m; x++) {
                if (f[i][j][x]) {
                    f[i + 1][j][x] = true;
                    f[i + 1][j + 1][x | nums[i]] = true;
                }
            }
        }
    }

    const g: boolean[][][] = Array.from({ length: n + 1 }, () =>
        Array.from({ length: k + 2 }, () => Array(m).fill(false)),
    );
    g[n][0][0] = true;

    for (let i = n; i > 0; i--) {
        for (let j = 0; j <= k; j++) {
            for (let y = 0; y < m; y++) {
                if (g[i][j][y]) {
                    g[i - 1][j][y] = true;
                    g[i - 1][j + 1][y | nums[i - 1]] = true;
                }
            }
        }
    }

    let ans = 0;

    for (let i = k; i <= n - k; i++) {
        for (let x = 0; x < m; x++) {
            if (f[i][k][x]) {
                for (let y = 0; y < m; y++) {
                    if (g[i][k][y]) {
                        ans = Math.max(ans, x ^ y);
                    }
                }
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

# [3288. 最长上升路径的长度](https://leetcode.cn/problems/length-of-the-longest-increasing-path){#3288}

{{< tabs "3288" >}}

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

<p>给你一个长度为 <code>n</code>&nbsp;的二维整数数组&nbsp;<code>coordinates</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;，其中&nbsp;<code>0 &lt;= k &lt; n</code>&nbsp;。</p>

<p><code>coordinates[i] = [x<sub>i</sub>, y<sub>i</sub>]</code>&nbsp;表示二维平面里一个点&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;。</p>

<p>如果一个点序列&nbsp;<code>(x<sub>1</sub>, y<sub>1</sub>)</code>, <code>(x<sub>2</sub>, y<sub>2</sub>)</code>, <code>(x<sub>3</sub>, y<sub>3</sub>)</code>, ..., <code>(x<sub>m</sub>, y<sub>m</sub>)</code>&nbsp;满足以下条件，那么我们称它是一个长度为 <code>m</code>&nbsp;的 <strong>上升序列</strong>&nbsp;：</p>

<ul>
	<li>对于所有满足&nbsp;<code>1 &lt;= i &lt; m</code> 的&nbsp;<code>i</code>&nbsp;都有&nbsp;<code>x<sub>i</sub> &lt; x<sub>i + 1</sub></code>&nbsp;且&nbsp;<code>y<sub>i</sub> &lt; y<sub>i + 1</sub></code>&nbsp;。</li>
	<li>对于所有&nbsp;<code>1 &lt;= i &lt;= m</code>&nbsp;的&nbsp;<code>i</code>&nbsp;对应的点&nbsp;<code>(x<sub>i</sub>, y<sub>i</sub>)</code>&nbsp;都在给定的坐标数组里。</li>
</ul>

<p>请你返回包含坐标 <code>coordinates[k]</code>&nbsp;的 <strong>最长上升路径</strong>&nbsp;的长度。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>coordinates = [[3,1],[2,2],[4,1],[0,0],[5,3]], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>3</span></p>

<p><strong>解释：</strong></p>

<p><code>(0, 0)</code>&nbsp;，<code>(2, 2)</code>&nbsp;，<code>(5, 3)</code><!-- notionvc: 082cee9e-4ce5-4ede-a09d-57001a72141d -->&nbsp;是包含坐标 <code>(2, 2)</code>&nbsp;的最长上升路径。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>coordinates = [[2,1],[7,0],[5,6]], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>2</span></p>

<p><b>解释：</b></p>

<p><code>(2, 1)</code>&nbsp;，<code>(5, 6)</code>&nbsp;是包含坐标 <code>(5, 6)</code>&nbsp;的最长上升路径。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == coordinates.length &lt;= 10<sup>5</sup></code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>0 &lt;= coordinates[i][0], coordinates[i][1] &lt;= 10<sup>9</sup></code></li>
	<li><code>coordinates</code>&nbsp;中的元素 <strong>互不相同</strong>&nbsp;。<!-- notionvc: 6e412fc2-f9dd-4ba2-b796-5e802a2b305a --><!-- notionvc: c2cf5618-fe99-4909-9b4c-e6b068be22a6 --></li>
	<li><code>0 &lt;= k &lt;= n - 1</code></li>
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

# [3289. 数字小镇中的捣蛋鬼](https://leetcode.cn/problems/the-two-sneaky-numbers-of-digitville){#3289}

{{< tabs "3289" >}}

{{% tab "python" %}}
```python
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return [x for x, v in cnt.items() if v == 2]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] ans = new int[2];
        int[] cnt = new int[100];
        int k = 0;
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans[k++] = x;
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
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int cnt[100]{};
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getSneakyNumbers(nums []int) (ans []int) {
	cnt := [100]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] == 2 {
			ans = append(ans, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getSneakyNumbers(nums: number[]): number[] {
    const ans: number[] = [];
    const cnt: number[] = Array(100).fill(0);
    for (const x of nums) {
        if (++cnt[x] > 1) {
            ans.push(x);
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

<p>数字小镇 Digitville 中，存在一个数字列表 <code>nums</code>，其中包含从 <code>0</code> 到 <code>n - 1</code> 的整数。每个数字本应 <strong>只出现一次</strong>，然而，有 <strong>两个 </strong>顽皮的数字额外多出现了一次，使得列表变得比正常情况下更长。</p>

<p>为了恢复 Digitville 的和平，作为小镇中的名侦探，请你找出这两个顽皮的数字。</p>

<p>返回一个长度为 2 的数组，包含这两个数字（顺序任意）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,1,1,0]</span></p>

<p><strong>输出：</strong> <span class="example-io">[0,1]</span></p>

<p><strong>解释：</strong></p>

<p>数字 0 和 1 分别在数组中出现了两次。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [0,3,2,1,3,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">[2,3]</span></p>

<p><strong>解释: </strong></p>

<p>数字 2 和 3 分别在数组中出现了两次。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong> <span class="example-io">nums = [7,1,5,4,3,4,6,0,9,5,8,2]</span></p>

<p><strong>输出：</strong> <span class="example-io">[4,5]</span></p>

<p><strong>解释: </strong></p>

<p>数字 4 和 5 分别在数组中出现了两次。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>nums.length == n + 2</code></li>
	<li><code>0 &lt;= nums[i] &lt; n</code></li>
	<li>输入保证 <code>nums</code> 中<strong> 恰好 </strong>包含两个重复的元素。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以用一个数组 $\textit{cnt}$ 记录每个数字出现的次数。

遍历数组 $\textit{nums}$，当某个数字出现次数为 $2$ 时，将其加入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return [x for x, v in cnt.items() if v == 2]
```

#### Java

```java
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] ans = new int[2];
        int[] cnt = new int[100];
        int k = 0;
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans[k++] = x;
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
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int cnt[100]{};
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getSneakyNumbers(nums []int) (ans []int) {
	cnt := [100]int{}
	for _, x := range nums {
		cnt[x]++
		if cnt[x] == 2 {
			ans = append(ans, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function getSneakyNumbers(nums: number[]): number[] {
    const ans: number[] = [];
    const cnt: number[] = Array(100).fill(0);
    for (const x of nums) {
        if (++cnt[x] > 1) {
            ans.push(x);
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
