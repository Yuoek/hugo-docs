---
title: "0390_消除游戏"
date: 2025-10-08T18:35:54+08:00
weight: 10
tags: [位运算, 几何, 分治, 动态规划, 双指针, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 扫描线, 数学, 数组, 最短路, 栈, 水塘抽样, 深度优先搜索, 滑动窗口, 记忆化搜索, 贪心, 递归, 随机化]
---

{{< markmap >}}
### [0390_消除游戏](#390)
#### [递归](#390)
#### [数学](#390)
### [0391_完美矩形](#391)
#### [几何](#391)
#### [数组](#391)
#### [哈希表](#391)
#### [数学](#391)
#### [扫描线](#391)
### [0392_判断子序列](#392)
#### [双指针](#392)
#### [字符串](#392)
#### [动态规划](#392)
### [0393_UTF-8 编码验证](#393)
#### [位运算](#393)
#### [数组](#393)
### [0394_字符串解码](#394)
#### [栈](#394)
#### [递归](#394)
#### [字符串](#394)
### [0395_至少有 K 个重复字符的最长子串](#395)
#### [哈希表](#395)
#### [字符串](#395)
#### [分治](#395)
#### [滑动窗口](#395)
### [0396_旋转函数](#396)
#### [数组](#396)
#### [数学](#396)
#### [动态规划](#396)
### [0397_整数替换](#397)
#### [贪心](#397)
#### [位运算](#397)
#### [记忆化搜索](#397)
#### [动态规划](#397)
### [0398_随机数索引](#398)
#### [水塘抽样](#398)
#### [哈希表](#398)
#### [数学](#398)
#### [随机化](#398)
### [0399_除法求值](#399)
#### [深度优先搜索](#399)
#### [广度优先搜索](#399)
#### [并查集](#399)
#### [图](#399)
#### [数组](#399)
#### [字符串](#399)
#### [最短路](#399)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0390_消除游戏
___
#### 递归
___
#### 数学
---
### 0391_完美矩形
___
#### 几何
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 扫描线
---
### 0392_判断子序列
___
#### 双指针
___
#### 字符串
___
#### 动态规划
---
### 0393_UTF-8 编码验证
___
#### 位运算
___
#### 数组
---
### 0394_字符串解码
___
#### 栈
___
#### 递归
___
#### 字符串
---
### 0395_至少有 K 个重复字符的最长子串
___
#### 哈希表
___
#### 字符串
___
#### 分治
___
#### 滑动窗口
---
### 0396_旋转函数
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 0397_整数替换
___
#### 贪心
___
#### 位运算
___
#### 记忆化搜索
___
#### 动态规划
---
### 0398_随机数索引
___
#### 水塘抽样
___
#### 哈希表
___
#### 数学
___
#### 随机化
---
### 0399_除法求值
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
___
#### 数组
___
#### 字符串
___
#### 最短路
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 分治 |
| 动态规划 | 双指针 | 哈希表 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 扫描线 | 数学 |
| 数组 | 最短路 | 栈 |
| 水塘抽样 | 深度优先搜索 | 滑动窗口 |
| 记忆化搜索 | 贪心 | 递归 |
| 随机化 |  |  |

# [390. 消除游戏](https://leetcode.cn/problems/elimination-game){#390}

{{< tabs "390" >}}

{{% tab "python" %}}
```python
class Solution:
    def lastRemaining(self, n: int) -> int:
        a1, an = 1, n
        i, step, cnt = 0, 1, n
        while cnt > 1:
            if i % 2:
                an -= step
                if cnt % 2:
                    a1 += step
            else:
                a1 += step
                if cnt % 2:
                    an -= step
            cnt >>= 1
            step <<= 1
            i += 1
        return a1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lastRemaining(int n) {
        int a1 = 1, an = n, step = 1;
        for (int i = 0, cnt = n; cnt > 1; cnt >>= 1, step <<= 1, ++i) {
            if (i % 2 == 1) {
                an -= step;
                if (cnt % 2 == 1) {
                    a1 += step;
                }
            } else {
                a1 += step;
                if (cnt % 2 == 1) {
                    an -= step;
                }
            }
        }
        return a1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lastRemaining(int n) {
        int a1 = 1, an = n, step = 1;
        for (int i = 0, cnt = n; cnt > 1; cnt >>= 1, step <<= 1, ++i) {
            if (i % 2) {
                an -= step;
                if (cnt % 2) a1 += step;
            } else {
                a1 += step;
                if (cnt % 2) an -= step;
            }
        }
        return a1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lastRemaining(n int) int {
	a1, an, step := 1, n, 1
	for i, cnt := 0, n; cnt > 1; cnt, step, i = cnt>>1, step<<1, i+1 {
		if i%2 == 1 {
			an -= step
			if cnt%2 == 1 {
				a1 += step
			}
		} else {
			a1 += step
			if cnt%2 == 1 {
				an -= step
			}
		}
	}
	return a1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>列表 <code>arr</code> 由在范围 <code>[1, n]</code> 中的所有整数组成，并按严格递增排序。请你对 <code>arr</code> 应用下述算法：</p>

<div class="original__bRMd">
<div>
<ul>
	<li>从左到右，删除第一个数字，然后每隔一个数字删除一个，直到到达列表末尾。</li>
	<li>重复上面的步骤，但这次是从右到左。也就是，删除最右侧的数字，然后剩下的数字每隔一个删除一个。</li>
	<li>不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。</li>
</ul>

<p>给你整数 <code>n</code> ，返回 <code>arr</code> 最后剩下的数字。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>6
<strong>解释：</strong>
arr = [<strong><em>1</em></strong>, 2, <em><strong>3</strong></em>, 4, <em><strong>5</strong></em>, 6, <em><strong>7</strong></em>, 8, <em><strong>9</strong></em>]
arr = [2, <em><strong>4</strong></em>, 6, <em><strong>8</strong></em>]
arr = [<em><strong>2</strong></em>, 6]
arr = [6]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
</div>

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
    def lastRemaining(self, n: int) -> int:
        a1, an = 1, n
        i, step, cnt = 0, 1, n
        while cnt > 1:
            if i % 2:
                an -= step
                if cnt % 2:
                    a1 += step
            else:
                a1 += step
                if cnt % 2:
                    an -= step
            cnt >>= 1
            step <<= 1
            i += 1
        return a1
```

#### Java

```java
class Solution {
    public int lastRemaining(int n) {
        int a1 = 1, an = n, step = 1;
        for (int i = 0, cnt = n; cnt > 1; cnt >>= 1, step <<= 1, ++i) {
            if (i % 2 == 1) {
                an -= step;
                if (cnt % 2 == 1) {
                    a1 += step;
                }
            } else {
                a1 += step;
                if (cnt % 2 == 1) {
                    an -= step;
                }
            }
        }
        return a1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lastRemaining(int n) {
        int a1 = 1, an = n, step = 1;
        for (int i = 0, cnt = n; cnt > 1; cnt >>= 1, step <<= 1, ++i) {
            if (i % 2) {
                an -= step;
                if (cnt % 2) a1 += step;
            } else {
                a1 += step;
                if (cnt % 2) an -= step;
            }
        }
        return a1;
    }
};
```

#### Go

```go
func lastRemaining(n int) int {
	a1, an, step := 1, n, 1
	for i, cnt := 0, n; cnt > 1; cnt, step, i = cnt>>1, step<<1, i+1 {
		if i%2 == 1 {
			an -= step
			if cnt%2 == 1 {
				a1 += step
			}
		} else {
			a1 += step
			if cnt%2 == 1 {
				an -= step
			}
		}
	}
	return a1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [391. 完美矩形](https://leetcode.cn/problems/perfect-rectangle){#391}

{{< tabs "391" >}}

{{% tab "python" %}}
```python
class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        area = 0
        minX, minY = rectangles[0][0], rectangles[0][1]
        maxX, maxY = rectangles[0][2], rectangles[0][3]
        cnt = defaultdict(int)

        for r in rectangles:
            area += (r[2] - r[0]) * (r[3] - r[1])

            minX = min(minX, r[0])
            minY = min(minY, r[1])
            maxX = max(maxX, r[2])
            maxY = max(maxY, r[3])

            cnt[(r[0], r[1])] += 1
            cnt[(r[0], r[3])] += 1
            cnt[(r[2], r[3])] += 1
            cnt[(r[2], r[1])] += 1

        if (
            area != (maxX - minX) * (maxY - minY)
            or cnt[(minX, minY)] != 1
            or cnt[(minX, maxY)] != 1
            or cnt[(maxX, maxY)] != 1
            or cnt[(maxX, minY)] != 1
        ):
            return False

        del cnt[(minX, minY)], cnt[(minX, maxY)], cnt[(maxX, maxY)], cnt[(maxX, minY)]

        return all(c == 2 or c == 4 for c in cnt.values())
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1];
        int maxX = rectangles[0][2], maxY = rectangles[0][3];
        Map<Pair, Integer> cnt = new HashMap<>();

        for (int[] r : rectangles) {
            area += (r[2] - r[0]) * (r[3] - r[1]);

            minX = Math.min(minX, r[0]);
            minY = Math.min(minY, r[1]);
            maxX = Math.max(maxX, r[2]);
            maxY = Math.max(maxY, r[3]);

            cnt.merge(new Pair(r[0], r[1]), 1, Integer::sum);
            cnt.merge(new Pair(r[0], r[3]), 1, Integer::sum);
            cnt.merge(new Pair(r[2], r[3]), 1, Integer::sum);
            cnt.merge(new Pair(r[2], r[1]), 1, Integer::sum);
        }

        if (area != (long) (maxX - minX) * (maxY - minY)
            || cnt.getOrDefault(new Pair(minX, minY), 0) != 1
            || cnt.getOrDefault(new Pair(minX, maxY), 0) != 1
            || cnt.getOrDefault(new Pair(maxX, maxY), 0) != 1
            || cnt.getOrDefault(new Pair(maxX, minY), 0) != 1) {
            return false;
        }

        cnt.remove(new Pair(minX, minY));
        cnt.remove(new Pair(minX, maxY));
        cnt.remove(new Pair(maxX, maxY));
        cnt.remove(new Pair(maxX, minY));

        return cnt.values().stream().allMatch(c -> c == 2 || c == 4);
    }

    private static class Pair {
        final int first;
        final int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair pair = (Pair) o;
            return first == pair.first && second == pair.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1];
        int maxX = rectangles[0][2], maxY = rectangles[0][3];

        using pii = pair<int, int>;
        map<pii, int> cnt;

        for (auto& r : rectangles) {
            area += (r[2] - r[0]) * (r[3] - r[1]);

            minX = min(minX, r[0]);
            minY = min(minY, r[1]);
            maxX = max(maxX, r[2]);
            maxY = max(maxY, r[3]);

            ++cnt[{r[0], r[1]}];
            ++cnt[{r[0], r[3]}];
            ++cnt[{r[2], r[3]}];
            ++cnt[{r[2], r[1]}];
        }

        if (area != (long long) (maxX - minX) * (maxY - minY) || cnt[{minX, minY}] != 1 || cnt[{minX, maxY}] != 1 || cnt[{maxX, maxY}] != 1 || cnt[{maxX, minY}] != 1) {
            return false;
        }

        cnt.erase({minX, minY});
        cnt.erase({minX, maxY});
        cnt.erase({maxX, maxY});
        cnt.erase({maxX, minY});

        return all_of(cnt.begin(), cnt.end(), [](pair<pii, int> e) {
            return e.second == 2 || e.second == 4;
        });
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type pair struct {
	first  int
	second int
}

func isRectangleCover(rectangles [][]int) bool {
	area := 0
	minX, minY := rectangles[0][0], rectangles[0][1]
	maxX, maxY := rectangles[0][2], rectangles[0][3]

	cnt := make(map[pair]int)
	for _, r := range rectangles {
		area += (r[2] - r[0]) * (r[3] - r[1])

		minX = min(minX, r[0])
		minY = min(minY, r[1])
		maxX = max(maxX, r[2])
		maxY = max(maxY, r[3])

		cnt[pair{r[0], r[1]}]++
		cnt[pair{r[0], r[3]}]++
		cnt[pair{r[2], r[3]}]++
		cnt[pair{r[2], r[1]}]++
	}

	if area != (maxX-minX)*(maxY-minY) ||
		cnt[pair{minX, minY}] != 1 ||
		cnt[pair{minX, maxY}] != 1 ||
		cnt[pair{maxX, maxY}] != 1 ||
		cnt[pair{maxX, minY}] != 1 {
		return false
	}

	delete(cnt, pair{minX, minY})
	delete(cnt, pair{minX, maxY})
	delete(cnt, pair{maxX, maxY})
	delete(cnt, pair{maxX, minY})

	for _, c := range cnt {
		if c != 2 && c != 4 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个数组 <code>rectangles</code> ，其中 <code>rectangles[i] = [x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub>]</code> 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> ，右上顶点是 <code>(a<sub>i</sub>, b<sub>i</sub>)</code> 。</p>

<p>如果所有矩形一起精确覆盖了某个矩形区域，则返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>
&nbsp;

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0391.Perfect%20Rectangle/images/perectrec1-plane.jpg" style="height: 294px; width: 300px;" />
<pre>
<strong>输入：</strong>rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
<strong>输出：</strong>true
<strong>解释：</strong>5 个矩形一起可以精确地覆盖一个矩形区域。 
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0391.Perfect%20Rectangle/images/perfectrec2-plane.jpg" style="height: 294px; width: 300px;" />
<pre>
<strong>输入：</strong>rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
<strong>输出：</strong>false
<strong>解释：</strong>两个矩形之间有间隔，无法覆盖成一个矩形。</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0391.Perfect%20Rectangle/images/perfecrrec4-plane.jpg" style="height: 294px; width: 300px;" />
<pre>
<strong>输入：</strong>rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
<strong>输出：</strong>false
<strong>解释：</strong>因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= rectangles.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>rectangles[i].length == 4</code></li>
	<li><code>-10<sup>5</sup> &lt;= x<sub>i</sub> &lt; a<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= y<sub>i</sub> &lt; b<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
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
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        area = 0
        minX, minY = rectangles[0][0], rectangles[0][1]
        maxX, maxY = rectangles[0][2], rectangles[0][3]
        cnt = defaultdict(int)

        for r in rectangles:
            area += (r[2] - r[0]) * (r[3] - r[1])

            minX = min(minX, r[0])
            minY = min(minY, r[1])
            maxX = max(maxX, r[2])
            maxY = max(maxY, r[3])

            cnt[(r[0], r[1])] += 1
            cnt[(r[0], r[3])] += 1
            cnt[(r[2], r[3])] += 1
            cnt[(r[2], r[1])] += 1

        if (
            area != (maxX - minX) * (maxY - minY)
            or cnt[(minX, minY)] != 1
            or cnt[(minX, maxY)] != 1
            or cnt[(maxX, maxY)] != 1
            or cnt[(maxX, minY)] != 1
        ):
            return False

        del cnt[(minX, minY)], cnt[(minX, maxY)], cnt[(maxX, maxY)], cnt[(maxX, minY)]

        return all(c == 2 or c == 4 for c in cnt.values())
```

#### Java

```java
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1];
        int maxX = rectangles[0][2], maxY = rectangles[0][3];
        Map<Pair, Integer> cnt = new HashMap<>();

        for (int[] r : rectangles) {
            area += (r[2] - r[0]) * (r[3] - r[1]);

            minX = Math.min(minX, r[0]);
            minY = Math.min(minY, r[1]);
            maxX = Math.max(maxX, r[2]);
            maxY = Math.max(maxY, r[3]);

            cnt.merge(new Pair(r[0], r[1]), 1, Integer::sum);
            cnt.merge(new Pair(r[0], r[3]), 1, Integer::sum);
            cnt.merge(new Pair(r[2], r[3]), 1, Integer::sum);
            cnt.merge(new Pair(r[2], r[1]), 1, Integer::sum);
        }

        if (area != (long) (maxX - minX) * (maxY - minY)
            || cnt.getOrDefault(new Pair(minX, minY), 0) != 1
            || cnt.getOrDefault(new Pair(minX, maxY), 0) != 1
            || cnt.getOrDefault(new Pair(maxX, maxY), 0) != 1
            || cnt.getOrDefault(new Pair(maxX, minY), 0) != 1) {
            return false;
        }

        cnt.remove(new Pair(minX, minY));
        cnt.remove(new Pair(minX, maxY));
        cnt.remove(new Pair(maxX, maxY));
        cnt.remove(new Pair(maxX, minY));

        return cnt.values().stream().allMatch(c -> c == 2 || c == 4);
    }

    private static class Pair {
        final int first;
        final int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            Pair pair = (Pair) o;
            return first == pair.first && second == pair.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }
}
```

#### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1];
        int maxX = rectangles[0][2], maxY = rectangles[0][3];

        using pii = pair<int, int>;
        map<pii, int> cnt;

        for (auto& r : rectangles) {
            area += (r[2] - r[0]) * (r[3] - r[1]);

            minX = min(minX, r[0]);
            minY = min(minY, r[1]);
            maxX = max(maxX, r[2]);
            maxY = max(maxY, r[3]);

            ++cnt[{r[0], r[1]}];
            ++cnt[{r[0], r[3]}];
            ++cnt[{r[2], r[3]}];
            ++cnt[{r[2], r[1]}];
        }

        if (area != (long long) (maxX - minX) * (maxY - minY) || cnt[{minX, minY}] != 1 || cnt[{minX, maxY}] != 1 || cnt[{maxX, maxY}] != 1 || cnt[{maxX, minY}] != 1) {
            return false;
        }

        cnt.erase({minX, minY});
        cnt.erase({minX, maxY});
        cnt.erase({maxX, maxY});
        cnt.erase({maxX, minY});

        return all_of(cnt.begin(), cnt.end(), [](pair<pii, int> e) {
            return e.second == 2 || e.second == 4;
        });
    }
};
```

#### Go

```go
type pair struct {
	first  int
	second int
}

func isRectangleCover(rectangles [][]int) bool {
	area := 0
	minX, minY := rectangles[0][0], rectangles[0][1]
	maxX, maxY := rectangles[0][2], rectangles[0][3]

	cnt := make(map[pair]int)
	for _, r := range rectangles {
		area += (r[2] - r[0]) * (r[3] - r[1])

		minX = min(minX, r[0])
		minY = min(minY, r[1])
		maxX = max(maxX, r[2])
		maxY = max(maxY, r[3])

		cnt[pair{r[0], r[1]}]++
		cnt[pair{r[0], r[3]}]++
		cnt[pair{r[2], r[3]}]++
		cnt[pair{r[2], r[1]}]++
	}

	if area != (maxX-minX)*(maxY-minY) ||
		cnt[pair{minX, minY}] != 1 ||
		cnt[pair{minX, maxY}] != 1 ||
		cnt[pair{maxX, maxY}] != 1 ||
		cnt[pair{maxX, minY}] != 1 {
		return false
	}

	delete(cnt, pair{minX, minY})
	delete(cnt, pair{minX, maxY})
	delete(cnt, pair{maxX, maxY})
	delete(cnt, pair{maxX, minY})

	for _, c := range cnt {
		if c != 2 && c != 4 {
			return false
		}
	}
	return true
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [392. 判断子序列](https://leetcode.cn/problems/is-subsequence){#392}

{{< tabs "392" >}}

{{% tab "python" %}}
```python
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = j = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
            ++j;
        }
        return i == m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        for (; i < m && j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == m;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isSubsequence(s string, t string) bool {
	i, j, m, n := 0, 0, len(s), len(t)
	for i < m && j < n {
		if s[i] == t[j] {
			i++
		}
		j++
	}
	return i == m
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isSubsequence(s: string, t: string): boolean {
    const m = s.length;
    const n = t.length;
    let i = 0;
    for (let j = 0; i < m && j < n; ++j) {
        if (s[i] === t[j]) {
            ++i;
        }
    }
    return i === m;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let n = t.len();
        let mut i = 0;
        for &c in s.iter() {
            while i < n && t[i] != c {
                i += 1;
            }
            if i == n {
                return false;
            }
            i += 1;
        }
        true
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsSubsequence(string s, string t) {
        int m = s.Length, n = t.Length;
        int i = 0, j = 0;
        for (; i < m && j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == m;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
bool isSubsequence(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int i = 0;
    for (int j = 0; i < m && j < n; ++j) {
        if (s[i] == t[j]) {
            ++i;
        }
    }
    return i == m;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定字符串 <strong>s</strong> 和 <strong>t</strong> ，判断 <strong>s</strong> 是否为 <strong>t</strong> 的子序列。</p>

<p>字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，<code>"ace"</code>是<code>"abcde"</code>的一个子序列，而<code>"aec"</code>不是）。</p>

<p><strong>进阶：</strong></p>

<p>如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？</p>

<p><strong>致谢：</strong></p>

<p>特别感谢<strong> </strong><a href="https://leetcode.com/pbrother/">@pbrother </a>添加此问题并且创建所有测试用例。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", t = "ahbgdc"
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "axc", t = "ahbgdc"
<strong>输出：</strong>false
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 <= s.length <= 100</code></li>
	<li><code>0 <= t.length <= 10^4</code></li>
	<li>两个字符串都只由小写字符组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们定义两个指针 $i$ 和 $j$，分别指向字符串 $s$ 和 $t$ 的初始位置。每次我们比较两个指针指向的字符，如果相同，则两个指针同时右移；如果不同，则只有 $j$ 右移。当指针 $i$ 移动到字符串 $s$ 的末尾时，说明 $s$ 是 $t$ 的子序列。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别是字符串 $s$ 和 $t$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = j = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        return i == len(s)
```

#### Java

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s.charAt(i) == t.charAt(j)) {
                ++i;
            }
            ++j;
        }
        return i == m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        for (; i < m && j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == m;
    }
};
```

#### Go

```go
func isSubsequence(s string, t string) bool {
	i, j, m, n := 0, 0, len(s), len(t)
	for i < m && j < n {
		if s[i] == t[j] {
			i++
		}
		j++
	}
	return i == m
}
```

#### TypeScript

```ts
function isSubsequence(s: string, t: string): boolean {
    const m = s.length;
    const n = t.length;
    let i = 0;
    for (let j = 0; i < m && j < n; ++j) {
        if (s[i] === t[j]) {
            ++i;
        }
    }
    return i === m;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (s, t) = (s.as_bytes(), t.as_bytes());
        let n = t.len();
        let mut i = 0;
        for &c in s.iter() {
            while i < n && t[i] != c {
                i += 1;
            }
            if i == n {
                return false;
            }
            i += 1;
        }
        true
    }
}
```

#### C#

```cs
public class Solution {
    public bool IsSubsequence(string s, string t) {
        int m = s.Length, n = t.Length;
        int i = 0, j = 0;
        for (; i < m && j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == m;
    }
}
```

#### C

```c
bool isSubsequence(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);
    int i = 0;
    for (int j = 0; i < m && j < n; ++j) {
        if (s[i] == t[j]) {
            ++i;
        }
    }
    return i == m;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [393. UTF-8 编码验证](https://leetcode.cn/problems/utf-8-validation){#393}

{{< tabs "393" >}}

{{% tab "python" %}}
```python
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        cnt = 0
        for v in data:
            if cnt > 0:
                if v >> 6 != 0b10:
                    return False
                cnt -= 1
            elif v >> 7 == 0:
                cnt = 0
            elif v >> 5 == 0b110:
                cnt = 1
            elif v >> 4 == 0b1110:
                cnt = 2
            elif v >> 3 == 0b11110:
                cnt = 3
            else:
                return False
        return cnt == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean validUtf8(int[] data) {
        int cnt = 0;
        for (int v : data) {
            if (cnt > 0) {
                if (v >> 6 != 0b10) {
                    return false;
                }
                --cnt;
            } else if (v >> 7 == 0) {
                cnt = 0;
            } else if (v >> 5 == 0b110) {
                cnt = 1;
            } else if (v >> 4 == 0b1110) {
                cnt = 2;
            } else if (v >> 3 == 0b11110) {
                cnt = 3;
            } else {
                return false;
            }
        }
        return cnt == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int& v : data) {
            if (cnt > 0) {
                if (v >> 6 != 0b10) {
                    return false;
                }
                --cnt;
            } else if (v >> 7 == 0) {
                cnt = 0;
            } else if (v >> 5 == 0b110) {
                cnt = 1;
            } else if (v >> 4 == 0b1110) {
                cnt = 2;
            } else if (v >> 3 == 0b11110) {
                cnt = 3;
            } else {
                return false;
            }
        }
        return cnt == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func validUtf8(data []int) bool {
	cnt := 0
	for _, v := range data {
		if cnt > 0 {
			if v>>6 != 0b10 {
				return false
			}
			cnt--
		} else if v>>7 == 0 {
			cnt = 0
		} else if v>>5 == 0b110 {
			cnt = 1
		} else if v>>4 == 0b1110 {
			cnt = 2
		} else if v>>3 == 0b11110 {
			cnt = 3
		} else {
			return false
		}
	}
	return cnt == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function validUtf8(data: number[]): boolean {
    let cnt = 0;
    for (const v of data) {
        if (cnt > 0) {
            if (v >> 6 !== 0b10) {
                return false;
            }
            --cnt;
        } else if (v >> 7 === 0) {
            cnt = 0;
        } else if (v >> 5 === 0b110) {
            cnt = 1;
        } else if (v >> 4 === 0b1110) {
            cnt = 2;
        } else if (v >> 3 === 0b11110) {
            cnt = 3;
        } else {
            return false;
        }
    }
    return cnt === 0;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个表示数据的整数数组&nbsp;<code>data</code>&nbsp;，返回它是否为有效的 <strong>UTF-8</strong> 编码。</p>

<p><strong>UTF-8</strong> 中的一个字符可能的长度为 <strong>1 到 4 字节</strong>，遵循以下的规则：</p>

<ol>
	<li>对于 <strong>1 字节</strong>&nbsp;的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。</li>
	<li>对于 <strong>n 字节</strong>&nbsp;的字符 (n &gt; 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。</li>
</ol>

<p>这是 UTF-8 编码的工作方式：</p>

<pre>
<code>      </code>Number of Bytes<code>  |        UTF-8 octet sequence
                       |              (binary)
   --------------------+---------------------------------------------
            1          | 0xxxxxxx
            2          | 110xxxxx 10xxxxxx
            3          | 1110xxxx 10xxxxxx 10xxxxxx
            4          | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
</code></pre>

<p><code>x</code>&nbsp;表示二进制形式的一位，可以是 <code>0</code>&nbsp;或 <code>1</code>。</p>

<p><strong>注意：</strong>输入是整数数组。只有每个整数的 <strong>最低 8 个有效位</strong> 用来存储数据。这意味着每个整数只表示 1 字节的数据。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>data = [197,130,1]
<strong>输出：</strong>true
<strong>解释：</strong>数据表示字节序列:<strong>11000101 10000010 00000001</strong>。
这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>data = [235,140,4]
<strong>输出：</strong>false
<strong>解释：</strong>数据表示 8 位的序列: <strong>11101011 10001100 00000100</strong>.
前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
下一个字节是开头为 10 的延续字节，这是正确的。
但第二个延续字节不以 10 开头，所以是不符合规则的。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= data.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= data[i] &lt;= 255</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们用一个变量 $cnt$ 记录当前需要填充的以 $10$ 开头的字节的个数，初始时 $cnt = 0$。

遍历数组中的每个整数，对于每个整数 $v$：

-   如果 $cnt > 0$，则判断 $v$ 是否以 $10$ 开头，如果不是，则返回 `false`，否则 $cnt$ 减一。
-   如果 $v$ 的最高位为 $0$，则 $cnt = 0$。
-   如果 $v$ 的最高两位为 $110$，则 $cnt = 1$。
-   如果 $v$ 的最高三位为 $1110$，则 $cnt = 2$。
-   如果 $v$ 的最高四位为 $11110$，则 $cnt = 3$。
-   否则，返回 `false`。

最后，如果 $cnt = 0$，则返回 `true`，否则返回 `false`。

时间复杂度 $O(n)$，其中 $n$ 为数组 `data` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        cnt = 0
        for v in data:
            if cnt > 0:
                if v >> 6 != 0b10:
                    return False
                cnt -= 1
            elif v >> 7 == 0:
                cnt = 0
            elif v >> 5 == 0b110:
                cnt = 1
            elif v >> 4 == 0b1110:
                cnt = 2
            elif v >> 3 == 0b11110:
                cnt = 3
            else:
                return False
        return cnt == 0
```

#### Java

```java
class Solution {
    public boolean validUtf8(int[] data) {
        int cnt = 0;
        for (int v : data) {
            if (cnt > 0) {
                if (v >> 6 != 0b10) {
                    return false;
                }
                --cnt;
            } else if (v >> 7 == 0) {
                cnt = 0;
            } else if (v >> 5 == 0b110) {
                cnt = 1;
            } else if (v >> 4 == 0b1110) {
                cnt = 2;
            } else if (v >> 3 == 0b11110) {
                cnt = 3;
            } else {
                return false;
            }
        }
        return cnt == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (int& v : data) {
            if (cnt > 0) {
                if (v >> 6 != 0b10) {
                    return false;
                }
                --cnt;
            } else if (v >> 7 == 0) {
                cnt = 0;
            } else if (v >> 5 == 0b110) {
                cnt = 1;
            } else if (v >> 4 == 0b1110) {
                cnt = 2;
            } else if (v >> 3 == 0b11110) {
                cnt = 3;
            } else {
                return false;
            }
        }
        return cnt == 0;
    }
};
```

#### Go

```go
func validUtf8(data []int) bool {
	cnt := 0
	for _, v := range data {
		if cnt > 0 {
			if v>>6 != 0b10 {
				return false
			}
			cnt--
		} else if v>>7 == 0 {
			cnt = 0
		} else if v>>5 == 0b110 {
			cnt = 1
		} else if v>>4 == 0b1110 {
			cnt = 2
		} else if v>>3 == 0b11110 {
			cnt = 3
		} else {
			return false
		}
	}
	return cnt == 0
}
```

#### TypeScript

```ts
function validUtf8(data: number[]): boolean {
    let cnt = 0;
    for (const v of data) {
        if (cnt > 0) {
            if (v >> 6 !== 0b10) {
                return false;
            }
            --cnt;
        } else if (v >> 7 === 0) {
            cnt = 0;
        } else if (v >> 5 === 0b110) {
            cnt = 1;
        } else if (v >> 4 === 0b1110) {
            cnt = 2;
        } else if (v >> 3 === 0b11110) {
            cnt = 3;
        } else {
            return false;
        }
    }
    return cnt === 0;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [394. 字符串解码](https://leetcode.cn/problems/decode-string){#394}

{{< tabs "394" >}}

{{% tab "python" %}}
```python
class Solution:
    def decodeString(self, s: str) -> str:
        s1, s2 = [], []
        num, res = 0, ''
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                s1.append(num)
                s2.append(res)
                num, res = 0, ''
            elif c == ']':
                res = s2.pop() + res * s1.pop()
            else:
                res += c
        return res
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String decodeString(String s) {
        Deque<Integer> s1 = new ArrayDeque<>();
        Deque<String> s2 = new ArrayDeque<>();
        int num = 0;
        String res = "";
        for (char c : s.toCharArray()) {
            if ('0' <= c && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                s1.push(num);
                s2.push(res);
                num = 0;
                res = "";
            } else if (c == ']') {
                StringBuilder t = new StringBuilder();
                for (int i = 0, n = s1.pop(); i < n; ++i) {
                    t.append(res);
                }
                res = s2.pop() + t.toString();
            } else {
                res += String.valueOf(c);
            }
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function decodeString(s: string): string {
    let ans = '';
    let stack = [];
    let count = 0; // repeatCount
    for (let cur of s) {
        if (/[0-9]/.test(cur)) {
            count = count * 10 + Number(cur);
        } else if (/[a-z]/.test(cur)) {
            ans += cur;
        } else if ('[' == cur) {
            stack.push([ans, count]);
            // reset
            ans = '';
            count = 0;
        } else {
            // match ']'
            let [pre, count] = stack.pop();
            ans = pre + ans.repeat(count);
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

<p>给定一个经过编码的字符串，返回它解码后的字符串。</p>

<p>编码规则为: <code>k[encoded_string]</code>，表示其中方括号内部的 <code>encoded_string</code> 正好重复 <code>k</code> 次。注意 <code>k</code> 保证为正整数。</p>

<p>你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。</p>

<p>此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 <code>k</code> ，例如不会出现像&nbsp;<code>3a</code>&nbsp;或&nbsp;<code>2[4]</code>&nbsp;的输入。</p>

<p>测试用例保证输出的长度不会超过&nbsp;<code>10<sup>5</sup></code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "3[a]2[bc]"
<strong>输出：</strong>"aaabcbc"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "3[a2[c]]"
<strong>输出：</strong>"accaccacc"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "2[abc]3[cd]ef"
<strong>输出：</strong>"abcabccdcdcdef"
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "abc3[cd]xyz"
<strong>输出：</strong>"abccdcdcdxyz"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 30</code></li>
	<li><meta charset="UTF-8" /><code>s</code>&nbsp;由小写英文字母、数字和方括号<meta charset="UTF-8" />&nbsp;<code>'[]'</code> 组成</li>
	<li><code>s</code>&nbsp;保证是一个&nbsp;<strong>有效</strong>&nbsp;的输入。</li>
	<li><code>s</code>&nbsp;中所有整数的取值范围为<meta charset="UTF-8" />&nbsp;<code>[1, 300]</code>&nbsp;</li>
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
    def decodeString(self, s: str) -> str:
        s1, s2 = [], []
        num, res = 0, ''
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                s1.append(num)
                s2.append(res)
                num, res = 0, ''
            elif c == ']':
                res = s2.pop() + res * s1.pop()
            else:
                res += c
        return res
```

#### Java

```java
class Solution {
    public String decodeString(String s) {
        Deque<Integer> s1 = new ArrayDeque<>();
        Deque<String> s2 = new ArrayDeque<>();
        int num = 0;
        String res = "";
        for (char c : s.toCharArray()) {
            if ('0' <= c && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                s1.push(num);
                s2.push(res);
                num = 0;
                res = "";
            } else if (c == ']') {
                StringBuilder t = new StringBuilder();
                for (int i = 0, n = s1.pop(); i < n; ++i) {
                    t.append(res);
                }
                res = s2.pop() + t.toString();
            } else {
                res += String.valueOf(c);
            }
        }
        return res;
    }
}
```

#### TypeScript

```ts
function decodeString(s: string): string {
    let ans = '';
    let stack = [];
    let count = 0; // repeatCount
    for (let cur of s) {
        if (/[0-9]/.test(cur)) {
            count = count * 10 + Number(cur);
        } else if (/[a-z]/.test(cur)) {
            ans += cur;
        } else if ('[' == cur) {
            stack.push([ans, count]);
            // reset
            ans = '';
            count = 0;
        } else {
            // match ']'
            let [pre, count] = stack.pop();
            ans = pre + ans.repeat(count);
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

# [395. 至少有 K 个重复字符的最长子串](https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters){#395}

{{< tabs "395" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        def dfs(l, r):
            cnt = Counter(s[l : r + 1])
            split = next((c for c, v in cnt.items() if v < k), '')
            if not split:
                return r - l + 1
            i = l
            ans = 0
            while i <= r:
                while i <= r and s[i] == split:
                    i += 1
                if i >= r:
                    break
                j = i
                while j <= r and s[j] != split:
                    j += 1
                t = dfs(i, j - 1)
                ans = max(ans, t)
                i = j
            return ans

        return dfs(0, len(s) - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String s;
    private int k;

    public int longestSubstring(String s, int k) {
        this.s = s;
        this.k = k;
        return dfs(0, s.length() - 1);
    }

    private int dfs(int l, int r) {
        int[] cnt = new int[26];
        for (int i = l; i <= r; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        char split = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = (char) (i + 'a');
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }
        int i = l;
        int ans = 0;
        while (i <= r) {
            while (i <= r && s.charAt(i) == split) {
                ++i;
            }
            if (i > r) {
                break;
            }
            int j = i;
            while (j <= r && s.charAt(j) != split) {
                ++j;
            }
            int t = dfs(i, j - 1);
            ans = Math.max(ans, t);
            i = j;
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
    int longestSubstring(string s, int k) {
        function<int(int, int)> dfs = [&](int l, int r) -> int {
            int cnt[26] = {0};
            for (int i = l; i <= r; ++i) {
                cnt[s[i] - 'a']++;
            }
            char split = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0 && cnt[i] < k) {
                    split = 'a' + i;
                    break;
                }
            }
            if (split == 0) {
                return r - l + 1;
            }
            int i = l;
            int ans = 0;
            while (i <= r) {
                while (i <= r && s[i] == split) {
                    ++i;
                }
                if (i >= r) {
                    break;
                }
                int j = i;
                while (j <= r && s[j] != split) {
                    ++j;
                }
                int t = dfs(i, j - 1);
                ans = max(ans, t);
                i = j;
            }
            return ans;
        };
        return dfs(0, s.size() - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubstring(s string, k int) int {
	var dfs func(l, r int) int
	dfs = func(l, r int) int {
		cnt := [26]int{}
		for i := l; i <= r; i++ {
			cnt[s[i]-'a']++
		}
		var split byte
		for i, v := range cnt {
			if v > 0 && v < k {
				split = byte(i + 'a')
				break
			}
		}
		if split == 0 {
			return r - l + 1
		}
		i := l
		ans := 0
		for i <= r {
			for i <= r && s[i] == split {
				i++
			}
			if i > r {
				break
			}
			j := i
			for j <= r && s[j] != split {
				j++
			}
			t := dfs(i, j-1)
			ans = max(ans, t)
			i = j
		}
		return ans
	}
	return dfs(0, len(s)-1)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> ，请你找出 <code>s</code> 中的最长子串，&nbsp;要求该子串中的每一字符出现次数都不少于 <code>k</code> 。返回这一子串的长度。</p>

<p data-pm-slice="1 1 []">如果不存在这样的子字符串，则返回 0。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "aaabb", k = 3
<strong>输出：</strong>3
<strong>解释：</strong>最长子串为 "aaa" ，其中 'a' 重复了 3 次。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "ababbc", k = 2
<strong>输出：</strong>5
<strong>解释：</strong>最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分治

对于字符串 $s$，如果存在某个字符 $c$，其出现次数小于 $k$，则任何包含 $c$ 的子串都不可能满足题目要求。因此我们可以将 $s$ 按照每个不满足条件的字符 $c$ 进行分割，分割得到的每个子串都是原字符串的一个「子问题」，我们可以递归地求解每个子问题，最终的答案即为所有子问题的最大值。

时间复杂度 $O(n \times C)$，空间复杂度 $O(C^2)$。其中 $n$ 为字符串 $s$ 的长度，而 $C$ 为字符集的大小。本题中 $C \leq 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        def dfs(l, r):
            cnt = Counter(s[l : r + 1])
            split = next((c for c, v in cnt.items() if v < k), '')
            if not split:
                return r - l + 1
            i = l
            ans = 0
            while i <= r:
                while i <= r and s[i] == split:
                    i += 1
                if i >= r:
                    break
                j = i
                while j <= r and s[j] != split:
                    j += 1
                t = dfs(i, j - 1)
                ans = max(ans, t)
                i = j
            return ans

        return dfs(0, len(s) - 1)
```

#### Java

```java
class Solution {
    private String s;
    private int k;

    public int longestSubstring(String s, int k) {
        this.s = s;
        this.k = k;
        return dfs(0, s.length() - 1);
    }

    private int dfs(int l, int r) {
        int[] cnt = new int[26];
        for (int i = l; i <= r; ++i) {
            ++cnt[s.charAt(i) - 'a'];
        }
        char split = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = (char) (i + 'a');
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }
        int i = l;
        int ans = 0;
        while (i <= r) {
            while (i <= r && s.charAt(i) == split) {
                ++i;
            }
            if (i > r) {
                break;
            }
            int j = i;
            while (j <= r && s.charAt(j) != split) {
                ++j;
            }
            int t = dfs(i, j - 1);
            ans = Math.max(ans, t);
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        function<int(int, int)> dfs = [&](int l, int r) -> int {
            int cnt[26] = {0};
            for (int i = l; i <= r; ++i) {
                cnt[s[i] - 'a']++;
            }
            char split = 0;
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0 && cnt[i] < k) {
                    split = 'a' + i;
                    break;
                }
            }
            if (split == 0) {
                return r - l + 1;
            }
            int i = l;
            int ans = 0;
            while (i <= r) {
                while (i <= r && s[i] == split) {
                    ++i;
                }
                if (i >= r) {
                    break;
                }
                int j = i;
                while (j <= r && s[j] != split) {
                    ++j;
                }
                int t = dfs(i, j - 1);
                ans = max(ans, t);
                i = j;
            }
            return ans;
        };
        return dfs(0, s.size() - 1);
    }
};
```

#### Go

```go
func longestSubstring(s string, k int) int {
	var dfs func(l, r int) int
	dfs = func(l, r int) int {
		cnt := [26]int{}
		for i := l; i <= r; i++ {
			cnt[s[i]-'a']++
		}
		var split byte
		for i, v := range cnt {
			if v > 0 && v < k {
				split = byte(i + 'a')
				break
			}
		}
		if split == 0 {
			return r - l + 1
		}
		i := l
		ans := 0
		for i <= r {
			for i <= r && s[i] == split {
				i++
			}
			if i > r {
				break
			}
			j := i
			for j <= r && s[j] != split {
				j++
			}
			t := dfs(i, j-1)
			ans = max(ans, t)
			i = j
		}
		return ans
	}
	return dfs(0, len(s)-1)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [396. 旋转函数](https://leetcode.cn/problems/rotate-function){#396}

{{< tabs "396" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        f = sum(i * v for i, v in enumerate(nums))
        n, s = len(nums), sum(nums)
        ans = f
        for i in range(1, n):
            f = f + s - n * nums[n - i]
            ans = max(ans, f)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxRotateFunction(int[] nums) {
        int f = 0;
        int s = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = Math.max(ans, f);
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
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxRotateFunction(nums []int) int {
	f, s, n := 0, 0, len(nums)
	for i, v := range nums {
		f += i * v
		s += v
	}
	ans := f
	for i := 1; i < n; i++ {
		f = f + s - n*nums[n-i]
		if ans < f {
			ans = f
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxRotateFunction(nums: number[]): number {
    const n = nums.length;
    const sum = nums.reduce((r, v) => r + v);
    let res = nums.reduce((r, v, i) => r + v * i, 0);
    let pre = res;
    for (let i = 1; i < n; i++) {
        pre = pre - (sum - nums[i - 1]) + nums[i - 1] * (n - 1);
        res = Math.max(res, pre);
    }
    return res;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_rotate_function(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let sum: i32 = nums.iter().sum();
        let mut pre: i32 = nums.iter().enumerate().map(|(i, &v)| (i as i32) * v).sum();
        (0..n)
            .map(|i| {
                let res = pre;
                pre = pre - (sum - nums[i]) + nums[i] * ((n - 1) as i32);
                res
            })
            .max()
            .unwrap_or(0)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个长度为 <code>n</code> 的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>假设&nbsp;<code>arr<sub>k</sub></code>&nbsp;是数组&nbsp;<code>nums</code>&nbsp;顺时针旋转 <code>k</code> 个位置后的数组，我们定义&nbsp;<code>nums</code>&nbsp;的 <strong>旋转函数</strong>&nbsp;&nbsp;<code>F</code>&nbsp;为：</p>

<ul>
	<li><code>F(k) = 0 * arr<sub>k</sub>[0] + 1 * arr<sub>k</sub>[1] + ... + (n - 1) * arr<sub>k</sub>[n - 1]</code></li>
</ul>

<p>返回&nbsp;<em><code>F(0), F(1), ..., F(n-1)</code>中的最大值&nbsp;</em>。</p>

<p>生成的测试用例让答案符合&nbsp;<strong>32 位</strong> 整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,3,2,6]
<strong>输出:</strong> 26
<strong>解释:</strong>
F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
所以 F(0), F(1), F(2), F(3) 中的最大值是 F(3) = 26 。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [100]
<strong>输出:</strong> 0
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-100 &lt;= nums[i] &lt;= 100</code></li>
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
    def maxRotateFunction(self, nums: List[int]) -> int:
        f = sum(i * v for i, v in enumerate(nums))
        n, s = len(nums), sum(nums)
        ans = f
        for i in range(1, n):
            f = f + s - n * nums[n - i]
            ans = max(ans, f)
        return ans
```

#### Java

```java
class Solution {
    public int maxRotateFunction(int[] nums) {
        int f = 0;
        int s = 0;
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = Math.max(ans, f);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f = 0, s = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};
```

#### Go

```go
func maxRotateFunction(nums []int) int {
	f, s, n := 0, 0, len(nums)
	for i, v := range nums {
		f += i * v
		s += v
	}
	ans := f
	for i := 1; i < n; i++ {
		f = f + s - n*nums[n-i]
		if ans < f {
			ans = f
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxRotateFunction(nums: number[]): number {
    const n = nums.length;
    const sum = nums.reduce((r, v) => r + v);
    let res = nums.reduce((r, v, i) => r + v * i, 0);
    let pre = res;
    for (let i = 1; i < n; i++) {
        pre = pre - (sum - nums[i - 1]) + nums[i - 1] * (n - 1);
        res = Math.max(res, pre);
    }
    return res;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_rotate_function(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let sum: i32 = nums.iter().sum();
        let mut pre: i32 = nums.iter().enumerate().map(|(i, &v)| (i as i32) * v).sum();
        (0..n)
            .map(|i| {
                let res = pre;
                pre = pre - (sum - nums[i]) + nums[i] * ((n - 1) as i32);
                res
            })
            .max()
            .unwrap_or(0)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [397. 整数替换](https://leetcode.cn/problems/integer-replacement){#397}

{{< tabs "397" >}}

{{% tab "python" %}}
```python
class Solution:
    def integerReplacement(self, n: int) -> int:
        ans = 0
        while n != 1:
            if (n & 1) == 0:
                n >>= 1
            elif n != 3 and (n & 3) == 3:
                n += 1
            else:
                n -= 1
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int integerReplacement(int n) {
        int ans = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                n >>>= 1;
            } else if (n != 3 && (n & 3) == 3) {
                ++n;
            } else {
                --n;
            }
            ++ans;
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
    int integerReplacement(int N) {
        int ans = 0;
        long n = N;
        while (n != 1) {
            if ((n & 1) == 0)
                n >>= 1;
            else if (n != 3 && (n & 3) == 3)
                ++n;
            else
                --n;
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func integerReplacement(n int) int {
	ans := 0
	for n != 1 {
		if (n & 1) == 0 {
			n >>= 1
		} else if n != 3 && (n&3) == 3 {
			n++
		} else {
			n--
		}
		ans++
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数&nbsp;<code>n</code> ，你可以做如下操作：</p>

<ol>
	<li>如果&nbsp;<code>n</code><em>&nbsp;</em>是偶数，则用&nbsp;<code>n / 2</code>替换&nbsp;<code>n</code><em> </em>。</li>
	<li>如果&nbsp;<code>n</code><em>&nbsp;</em>是奇数，则可以用&nbsp;<code>n + 1</code>或<code>n - 1</code>替换&nbsp;<code>n</code> 。</li>
</ol>

<p>返回 <code>n</code><em>&nbsp;</em>变为 <code>1</code> 所需的 <em>最小替换次数</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 8
<strong>输出：</strong>3
<strong>解释：</strong>8 -&gt; 4 -&gt; 2 -&gt; 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 7
<strong>输出：</strong>4
<strong>解释：</strong>7 -&gt; 8 -&gt; 4 -&gt; 2 -&gt; 1
或 7 -&gt; 6 -&gt; 3 -&gt; 2 -&gt; 1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4
<strong>输出：</strong>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
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
    def integerReplacement(self, n: int) -> int:
        ans = 0
        while n != 1:
            if (n & 1) == 0:
                n >>= 1
            elif n != 3 and (n & 3) == 3:
                n += 1
            else:
                n -= 1
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int integerReplacement(int n) {
        int ans = 0;
        while (n != 1) {
            if ((n & 1) == 0) {
                n >>>= 1;
            } else if (n != 3 && (n & 3) == 3) {
                ++n;
            } else {
                --n;
            }
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int integerReplacement(int N) {
        int ans = 0;
        long n = N;
        while (n != 1) {
            if ((n & 1) == 0)
                n >>= 1;
            else if (n != 3 && (n & 3) == 3)
                ++n;
            else
                --n;
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func integerReplacement(n int) int {
	ans := 0
	for n != 1 {
		if (n & 1) == 0 {
			n >>= 1
		} else if n != 3 && (n&3) == 3 {
			n++
		} else {
			n--
		}
		ans++
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [398. 随机数索引](https://leetcode.cn/problems/random-pick-index){#398}

{{< tabs "398" >}}

{{% tab "python" %}}
```python
class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        n = ans = 0
        for i, v in enumerate(self.nums):
            if v == target:
                n += 1
                x = random.randint(1, n)
                if x == n:
                    ans = i
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private Random random = new Random();

    public Solution(int[] nums) {
        this.nums = nums;
    }

    public int pick(int target) {
        int n = 0, ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
                ++n;
                int x = 1 + random.nextInt(n);
                if (x == n) {
                    ans = i;
                }
            }
        }
        return ans;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++n;
                int x = 1 + rand() % n;
                if (n == x) ans = i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Solution struct {
	nums []int
}

func Constructor(nums []int) Solution {
	return Solution{nums}
}

func (this *Solution) Pick(target int) int {
	n, ans := 0, 0
	for i, v := range this.nums {
		if v == target {
			n++
			x := 1 + rand.Intn(n)
			if n == x {
				ans = i
			}
		}
	}
	return ans
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个可能含有 <strong>重复元素</strong> 的整数数组&nbsp;<code>nums</code> ，请你随机输出给定的目标数字&nbsp;<code>target</code> 的索引。你可以假设给定的数字一定存在于数组中。</p>

<p>实现 <code>Solution</code> 类：</p>

<ul>
	<li><code>Solution(int[] nums)</code> 用数组 <code>nums</code> 初始化对象。</li>
	<li><code>int pick(int target)</code> 从 <code>nums</code> 中选出一个满足 <code>nums[i] == target</code> 的随机索引 <code>i</code> 。如果存在多个有效的索引，则每个索引的返回概率应当相等。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入</strong>
["Solution", "pick", "pick", "pick"]
[[[1, 2, 3, 3, 3]], [3], [1], [3]]
<strong>输出</strong>
[null, 4, 0, 2]

<strong>解释</strong>
Solution solution = new Solution([1, 2, 3, 3, 3]);
solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
solution.pick(1); // 返回 0 。因为只有 nums[0] 等于 1 。
solution.pick(3); // 随机返回索引 2, 3 或者 4 之一。每个索引的返回概率应该相等。
</pre>

<p>&nbsp;</p>

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>target</code> 是 <code>nums</code> 中的一个整数</li>
	<li>最多调用 <code>pick</code> 函数 <code>10<sup>4</sup></code> 次</li>
</ul>
</div>
</div>
</div>

<div class="fullscreen-btn-layer__2kn7">&nbsp;</div>

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
    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        n = ans = 0
        for i, v in enumerate(self.nums):
            if v == target:
                n += 1
                x = random.randint(1, n)
                if x == n:
                    ans = i
        return ans


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
```

#### Java

```java
class Solution {
    private int[] nums;
    private Random random = new Random();

    public Solution(int[] nums) {
        this.nums = nums;
    }

    public int pick(int target) {
        int n = 0, ans = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == target) {
                ++n;
                int x = 1 + random.nextInt(n);
                if (x == n) {
                    ans = i;
                }
            }
        }
        return ans;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
```

#### C++

```cpp
class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                ++n;
                int x = 1 + rand() % n;
                if (n == x) ans = i;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
```

#### Go

```go
type Solution struct {
	nums []int
}

func Constructor(nums []int) Solution {
	return Solution{nums}
}

func (this *Solution) Pick(target int) int {
	n, ans := 0, 0
	for i, v := range this.nums {
		if v == target {
			n++
			x := 1 + rand.Intn(n)
			if n == x {
				ans = i
			}
		}
	}
	return ans
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.Pick(target);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [399. 除法求值](https://leetcode.cn/problems/evaluate-division){#399}

{{< tabs "399" >}}

{{% tab "python" %}}
```python
class Solution:
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        def find(x):
            if p[x] != x:
                origin = p[x]
                p[x] = find(p[x])
                w[x] *= w[origin]
            return p[x]

        w = defaultdict(lambda: 1)
        p = defaultdict()
        for a, b in equations:
            p[a], p[b] = a, b
        for i, v in enumerate(values):
            a, b = equations[i]
            pa, pb = find(a), find(b)
            if pa == pb:
                continue
            p[pa] = pb
            w[pa] = w[b] * v / w[a]
        return [
            -1 if c not in p or d not in p or find(c) != find(d) else w[c] / w[d]
            for c, d in queries
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<String, String> p;
    private Map<String, Double> w;

    public double[] calcEquation(
        List<List<String>> equations, double[] values, List<List<String>> queries) {
        int n = equations.size();
        p = new HashMap<>();
        w = new HashMap<>();
        for (List<String> e : equations) {
            p.put(e.get(0), e.get(0));
            p.put(e.get(1), e.get(1));
            w.put(e.get(0), 1.0);
            w.put(e.get(1), 1.0);
        }
        for (int i = 0; i < n; ++i) {
            List<String> e = equations.get(i);
            String a = e.get(0), b = e.get(1);
            String pa = find(a), pb = find(b);
            if (Objects.equals(pa, pb)) {
                continue;
            }
            p.put(pa, pb);
            w.put(pa, w.get(b) * values[i] / w.get(a));
        }
        int m = queries.size();
        double[] ans = new double[m];
        for (int i = 0; i < m; ++i) {
            String c = queries.get(i).get(0), d = queries.get(i).get(1);
            ans[i] = !p.containsKey(c) || !p.containsKey(d) || !Objects.equals(find(c), find(d))
                ? -1.0
                : w.get(c) / w.get(d);
        }
        return ans;
    }

    private String find(String x) {
        if (!Objects.equals(p.get(x), x)) {
            String origin = p.get(x);
            p.put(x, find(p.get(x)));
            w.put(x, w.get(x) * w.get(origin));
        }
        return p.get(x);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    unordered_map<string, string> p;
    unordered_map<string, double> w;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (auto e : equations) {
            p[e[0]] = e[0];
            p[e[1]] = e[1];
            w[e[0]] = 1.0;
            w[e[1]] = 1.0;
        }
        for (int i = 0; i < n; ++i) {
            vector<string> e = equations[i];
            string a = e[0], b = e[1];
            string pa = find(a), pb = find(b);
            if (pa == pb) continue;
            p[pa] = pb;
            w[pa] = w[b] * values[i] / w[a];
        }
        int m = queries.size();
        vector<double> ans(m);
        for (int i = 0; i < m; ++i) {
            string c = queries[i][0], d = queries[i][1];
            ans[i] = p.find(c) == p.end() || p.find(d) == p.end() || find(c) != find(d) ? -1.0 : w[c] / w[d];
        }
        return ans;
    }

    string find(string x) {
        if (p[x] != x) {
            string origin = p[x];
            p[x] = find(p[x]);
            w[x] *= w[origin];
        }
        return p[x];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	p := make(map[string]string)
	w := make(map[string]float64)
	for _, e := range equations {
		a, b := e[0], e[1]
		p[a], p[b] = a, b
		w[a], w[b] = 1.0, 1.0
	}

	var find func(x string) string
	find = func(x string) string {
		if p[x] != x {
			origin := p[x]
			p[x] = find(p[x])
			w[x] *= w[origin]
		}
		return p[x]
	}

	for i, v := range values {
		a, b := equations[i][0], equations[i][1]
		pa, pb := find(a), find(b)
		if pa == pb {
			continue
		}
		p[pa] = pb
		w[pa] = w[b] * v / w[a]
	}
	var ans []float64
	for _, e := range queries {
		c, d := e[0], e[1]
		if p[c] == "" || p[d] == "" || find(c) != find(d) {
			ans = append(ans, -1.0)
		} else {
			ans = append(ans, w[c]/w[d])
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

#[derive(Debug)]
pub struct DSUNode {
    parent: String,
    weight: f64,
}

pub struct DisjointSetUnion {
    nodes: HashMap<String, DSUNode>,
}

impl DisjointSetUnion {
    pub fn new(equations: &Vec<Vec<String>>) -> DisjointSetUnion {
        let mut nodes = HashMap::new();
        for equation in equations.iter() {
            for iter in equation.iter() {
                nodes.insert(
                    iter.clone(),
                    DSUNode {
                        parent: iter.clone(),
                        weight: 1.0,
                    },
                );
            }
        }
        DisjointSetUnion { nodes }
    }

    pub fn find(&mut self, v: &String) -> String {
        let origin = self.nodes[v].parent.clone();
        if origin == *v {
            return origin;
        }

        let root = self.find(&origin);
        self.nodes.get_mut(v).unwrap().parent = root.clone();
        self.nodes.get_mut(v).unwrap().weight *= self.nodes[&origin].weight;
        root
    }

    pub fn union(&mut self, a: &String, b: &String, v: f64) {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa == pb {
            return;
        }
        let (wa, wb) = (self.nodes[a].weight, self.nodes[b].weight);
        self.nodes.get_mut(&pa).unwrap().parent = pb;
        self.nodes.get_mut(&pa).unwrap().weight = (wb * v) / wa;
    }

    pub fn exist(&mut self, k: &String) -> bool {
        self.nodes.contains_key(k)
    }

    pub fn calc_value(&mut self, a: &String, b: &String) -> f64 {
        if !self.exist(a) || !self.exist(b) || self.find(a) != self.find(b) {
            -1.0
        } else {
            let wa = self.nodes[a].weight;
            let wb = self.nodes[b].weight;
            wa / wb
        }
    }
}

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let mut dsu = DisjointSetUnion::new(&equations);
        for (i, &v) in values.iter().enumerate() {
            let (a, b) = (&equations[i][0], &equations[i][1]);
            dsu.union(a, b, v);
        }

        let mut ans = vec![];
        for querie in queries {
            let (c, d) = (&querie[0], &querie[1]);
            ans.push(dsu.calc_value(c, d));
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function calcEquation(equations: string[][], values: number[], queries: string[][]): number[] {
    const g: Record<string, [string, number][]> = {};
    const ans = Array.from({ length: queries.length }, () => -1);

    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        (g[a] ??= []).push([b, values[i]]);
        (g[b] ??= []).push([a, 1 / values[i]]);
    }

    for (let i = 0; i < queries.length; i++) {
        const [c, d] = queries[i];
        const vis = new Set<string>();
        const q: [string, number][] = [[c, 1]];

        if (!g[c] || !g[d]) continue;
        if (c === d) {
            ans[i] = 1;
            continue;
        }

        for (const [current, v] of q) {
            if (vis.has(current)) continue;
            vis.add(current);

            for (const [intermediate, multiplier] of g[current]) {
                if (vis.has(intermediate)) continue;

                if (intermediate === d) {
                    ans[i] = v * multiplier;
                    break;
                }

                q.push([intermediate, v * multiplier]);
            }

            if (ans[i] !== -1) break;
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

<p>给你一个变量对数组 <code>equations</code> 和一个实数值数组 <code>values</code> 作为已知条件，其中 <code>equations[i] = [A<sub>i</sub>, B<sub>i</sub>]</code> 和 <code>values[i]</code> 共同表示等式 <code>A<sub>i</sub> / B<sub>i</sub> = values[i]</code> 。每个 <code>A<sub>i</sub></code> 或 <code>B<sub>i</sub></code> 是一个表示单个变量的字符串。</p>

<p>另有一些以数组 <code>queries</code> 表示的问题，其中 <code>queries[j] = [C<sub>j</sub>, D<sub>j</sub>]</code> 表示第 <code>j</code> 个问题，请你根据已知条件找出 <code>C<sub>j</sub> / D<sub>j</sub> = ?</code> 的结果作为答案。</p>

<p>返回 <strong>所有问题的答案</strong> 。如果存在某个无法确定的答案，则用 <code>-1.0</code> 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 <code>-1.0</code> 替代这个答案。</p>

<p><strong>注意：</strong>输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。</p>

<p><strong>注意：</strong>未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
<strong>输出：</strong>[6.00000,0.50000,-1.00000,1.00000,-1.00000]
<strong>解释：</strong>
条件：<em>a / b = 2.0</em>, <em>b / c = 3.0</em>
问题：<em>a / c = ?</em>, <em>b / a = ?</em>, <em>a / e = ?</em>, <em>a / a = ?</em>, <em>x / x = ?</em>
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
注意：x 是未定义的 =&gt; -1.0</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
<strong>输出：</strong>[3.75000,0.40000,5.00000,0.20000]
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
<strong>输出：</strong>[0.50000,2.00000,-1.00000,-1.00000]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= equations.length &lt;= 20</code></li>
	<li><code>equations[i].length == 2</code></li>
	<li><code>1 &lt;= A<sub>i</sub>.length, B<sub>i</sub>.length &lt;= 5</code></li>
	<li><code>values.length == equations.length</code></li>
	<li><code>0.0 &lt; values[i] &lt;= 20.0</code></li>
	<li><code>1 &lt;= queries.length &lt;= 20</code></li>
	<li><code>queries[i].length == 2</code></li>
	<li><code>1 &lt;= C<sub>j</sub>.length, D<sub>j</sub>.length &lt;= 5</code></li>
	<li><code>A<sub>i</sub>, B<sub>i</sub>, C<sub>j</sub>, D<sub>j</sub></code> 由小写英文字母与数字组成</li>
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
    def calcEquation(
        self, equations: List[List[str]], values: List[float], queries: List[List[str]]
    ) -> List[float]:
        def find(x):
            if p[x] != x:
                origin = p[x]
                p[x] = find(p[x])
                w[x] *= w[origin]
            return p[x]

        w = defaultdict(lambda: 1)
        p = defaultdict()
        for a, b in equations:
            p[a], p[b] = a, b
        for i, v in enumerate(values):
            a, b = equations[i]
            pa, pb = find(a), find(b)
            if pa == pb:
                continue
            p[pa] = pb
            w[pa] = w[b] * v / w[a]
        return [
            -1 if c not in p or d not in p or find(c) != find(d) else w[c] / w[d]
            for c, d in queries
        ]
```

#### Java

```java
class Solution {
    private Map<String, String> p;
    private Map<String, Double> w;

    public double[] calcEquation(
        List<List<String>> equations, double[] values, List<List<String>> queries) {
        int n = equations.size();
        p = new HashMap<>();
        w = new HashMap<>();
        for (List<String> e : equations) {
            p.put(e.get(0), e.get(0));
            p.put(e.get(1), e.get(1));
            w.put(e.get(0), 1.0);
            w.put(e.get(1), 1.0);
        }
        for (int i = 0; i < n; ++i) {
            List<String> e = equations.get(i);
            String a = e.get(0), b = e.get(1);
            String pa = find(a), pb = find(b);
            if (Objects.equals(pa, pb)) {
                continue;
            }
            p.put(pa, pb);
            w.put(pa, w.get(b) * values[i] / w.get(a));
        }
        int m = queries.size();
        double[] ans = new double[m];
        for (int i = 0; i < m; ++i) {
            String c = queries.get(i).get(0), d = queries.get(i).get(1);
            ans[i] = !p.containsKey(c) || !p.containsKey(d) || !Objects.equals(find(c), find(d))
                ? -1.0
                : w.get(c) / w.get(d);
        }
        return ans;
    }

    private String find(String x) {
        if (!Objects.equals(p.get(x), x)) {
            String origin = p.get(x);
            p.put(x, find(p.get(x)));
            w.put(x, w.get(x) * w.get(origin));
        }
        return p.get(x);
    }
}
```

#### C++

```cpp
class Solution {
public:
    unordered_map<string, string> p;
    unordered_map<string, double> w;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (auto e : equations) {
            p[e[0]] = e[0];
            p[e[1]] = e[1];
            w[e[0]] = 1.0;
            w[e[1]] = 1.0;
        }
        for (int i = 0; i < n; ++i) {
            vector<string> e = equations[i];
            string a = e[0], b = e[1];
            string pa = find(a), pb = find(b);
            if (pa == pb) continue;
            p[pa] = pb;
            w[pa] = w[b] * values[i] / w[a];
        }
        int m = queries.size();
        vector<double> ans(m);
        for (int i = 0; i < m; ++i) {
            string c = queries[i][0], d = queries[i][1];
            ans[i] = p.find(c) == p.end() || p.find(d) == p.end() || find(c) != find(d) ? -1.0 : w[c] / w[d];
        }
        return ans;
    }

    string find(string x) {
        if (p[x] != x) {
            string origin = p[x];
            p[x] = find(p[x]);
            w[x] *= w[origin];
        }
        return p[x];
    }
};
```

#### Go

```go
func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	p := make(map[string]string)
	w := make(map[string]float64)
	for _, e := range equations {
		a, b := e[0], e[1]
		p[a], p[b] = a, b
		w[a], w[b] = 1.0, 1.0
	}

	var find func(x string) string
	find = func(x string) string {
		if p[x] != x {
			origin := p[x]
			p[x] = find(p[x])
			w[x] *= w[origin]
		}
		return p[x]
	}

	for i, v := range values {
		a, b := equations[i][0], equations[i][1]
		pa, pb := find(a), find(b)
		if pa == pb {
			continue
		}
		p[pa] = pb
		w[pa] = w[b] * v / w[a]
	}
	var ans []float64
	for _, e := range queries {
		c, d := e[0], e[1]
		if p[c] == "" || p[d] == "" || find(c) != find(d) {
			ans = append(ans, -1.0)
		} else {
			ans = append(ans, w[c]/w[d])
		}
	}
	return ans
}
```

#### Rust

```rust
use std::collections::HashMap;

#[derive(Debug)]
pub struct DSUNode {
    parent: String,
    weight: f64,
}

pub struct DisjointSetUnion {
    nodes: HashMap<String, DSUNode>,
}

impl DisjointSetUnion {
    pub fn new(equations: &Vec<Vec<String>>) -> DisjointSetUnion {
        let mut nodes = HashMap::new();
        for equation in equations.iter() {
            for iter in equation.iter() {
                nodes.insert(
                    iter.clone(),
                    DSUNode {
                        parent: iter.clone(),
                        weight: 1.0,
                    },
                );
            }
        }
        DisjointSetUnion { nodes }
    }

    pub fn find(&mut self, v: &String) -> String {
        let origin = self.nodes[v].parent.clone();
        if origin == *v {
            return origin;
        }

        let root = self.find(&origin);
        self.nodes.get_mut(v).unwrap().parent = root.clone();
        self.nodes.get_mut(v).unwrap().weight *= self.nodes[&origin].weight;
        root
    }

    pub fn union(&mut self, a: &String, b: &String, v: f64) {
        let pa = self.find(a);
        let pb = self.find(b);
        if pa == pb {
            return;
        }
        let (wa, wb) = (self.nodes[a].weight, self.nodes[b].weight);
        self.nodes.get_mut(&pa).unwrap().parent = pb;
        self.nodes.get_mut(&pa).unwrap().weight = (wb * v) / wa;
    }

    pub fn exist(&mut self, k: &String) -> bool {
        self.nodes.contains_key(k)
    }

    pub fn calc_value(&mut self, a: &String, b: &String) -> f64 {
        if !self.exist(a) || !self.exist(b) || self.find(a) != self.find(b) {
            -1.0
        } else {
            let wa = self.nodes[a].weight;
            let wb = self.nodes[b].weight;
            wa / wb
        }
    }
}

impl Solution {
    pub fn calc_equation(
        equations: Vec<Vec<String>>,
        values: Vec<f64>,
        queries: Vec<Vec<String>>,
    ) -> Vec<f64> {
        let mut dsu = DisjointSetUnion::new(&equations);
        for (i, &v) in values.iter().enumerate() {
            let (a, b) = (&equations[i][0], &equations[i][1]);
            dsu.union(a, b, v);
        }

        let mut ans = vec![];
        for querie in queries {
            let (c, d) = (&querie[0], &querie[1]);
            ans.push(dsu.calc_value(c, d));
        }
        ans
    }
}
```

#### TypeScript

```ts
function calcEquation(equations: string[][], values: number[], queries: string[][]): number[] {
    const g: Record<string, [string, number][]> = {};
    const ans = Array.from({ length: queries.length }, () => -1);

    for (let i = 0; i < equations.length; i++) {
        const [a, b] = equations[i];
        (g[a] ??= []).push([b, values[i]]);
        (g[b] ??= []).push([a, 1 / values[i]]);
    }

    for (let i = 0; i < queries.length; i++) {
        const [c, d] = queries[i];
        const vis = new Set<string>();
        const q: [string, number][] = [[c, 1]];

        if (!g[c] || !g[d]) continue;
        if (c === d) {
            ans[i] = 1;
            continue;
        }

        for (const [current, v] of q) {
            if (vis.has(current)) continue;
            vis.add(current);

            for (const [intermediate, multiplier] of g[current]) {
                if (vis.has(intermediate)) continue;

                if (intermediate === d) {
                    ans[i] = v * multiplier;
                    break;
                }

                q.push([intermediate, v * multiplier]);
            }

            if (ans[i] !== -1) break;
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
