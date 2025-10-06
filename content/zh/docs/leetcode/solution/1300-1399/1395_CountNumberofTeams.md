---
title: "1395_CountNumberofTeams"
date: 2025-10-06T00:42:37+08:00
weight: 1395
tags: [树状数组, 线段树, 数组, 动态规划]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1395. 统计作战单位数](https://leetcode.cn/problems/count-number-of-teams)

[English Version](../en/1395-95/1395_CountNumberofTeams)

## 题目描述

<!-- description:start -->

<p>&nbsp;<code>n</code> 名士兵站成一排。每个士兵都有一个 <strong>独一无二</strong> 的评分 <code>rating</code> 。</p>

<p>从中选出 <strong>3</strong> 个士兵组成一个作战单位，规则如下：</p>

<ul>
	<li>从队伍中选出下标分别为 <code>i</code>、<code>j</code>、<code>k</code> 的 3 名士兵，他们的评分分别为 <code>rating[i]</code>、<code>rating[j]</code>、<code>rating[k]</code></li>
	<li>作战单位需满足： <code>rating[i] &lt; rating[j] &lt; rating[k]</code> 或者 <code>rating[i] &gt; rating[j] &gt; rating[k]</code> ，其中&nbsp; <code>0&nbsp;&lt;= i &lt;&nbsp;j &lt;&nbsp;k &lt;&nbsp;n</code></li>
</ul>

<p>请你返回按上述条件组建的作战单位的方案数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rating = [2,5,3,4,1]
<strong>输出：</strong>3
<strong>解释：</strong>我们可以组建三个作战单位 (2,3,4)、(5,4,1)、(5,3,1) 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rating = [2,1,3]
<strong>输出：</strong>0
<strong>解释：</strong>根据题目条件，我们无法组建作战单位。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rating = [1,2,3,4]
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == rating.length</code></li>
	<li><code>3 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= rating[i] &lt;= 10^5</code></li>
	<li><code>rating</code>&nbsp;中的元素都是唯一的</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：枚举中间元素

我们可以枚举数组 $rating$ 中每个元素 $rating[i]$ 作为中间元素，然后统计左边比它小的元素的个数 $l$，右边比它大的元素的个数 $r$，那么以该元素为中间元素的作战单位的个数为 $l \times r + (i - l) \times (n - i - 1 - r)$，累加到答案中即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $rating$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：树状数组

我们可以用两个树状数组分别维护数组 $rating$ 中每个元素的左边比它小的元素的个数 $l$，右边比它大的元素的个数 $r$，然后统计以该元素为中间元素的作战单位的个数为 $l \times r + (i - l) \times (n - i - 1 - r)$，累加到答案中即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $rating$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：记忆化搜索

<!-- tabs:start -->

#### TypeScript



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        nums = sorted(set(rating))
        m = len(nums)
        tree1 = BinaryIndexedTree(m)
        tree2 = BinaryIndexedTree(m)
        for v in rating:
            x = bisect_left(nums, v) + 1
            tree2.update(x, 1)
        n = len(rating)
        ans = 0
        for i, v in enumerate(rating):
            x = bisect_left(nums, v) + 1
            tree1.update(x, 1)
            tree2.update(x, -1)
            l = tree1.query(x - 1)
            r = n - i - 1 - tree2.query(x)
            ans += l * r
            ans += (i - l) * (n - i - 1 - r)
        return ans
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

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int[] nums = rating.clone();
        Arrays.sort(nums);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[m++] = nums[i];
            }
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m);
        for (int v : rating) {
            int x = search(nums, v);
            tree2.update(x, 1);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = search(nums, rating[i]);
            tree1.update(x, 1);
            tree2.update(x, -1);
            int l = tree1.query(x - 1);
            int r = n - i - 1 - tree2.query(x);
            ans += l * r;
            ans += (i - l) * (n - i - 1 - r);
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
        return l + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> nums = rating;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        BinaryIndexedTree tree1(m);
        BinaryIndexedTree tree2(m);
        for (int& v : rating) {
            int x = lower_bound(nums.begin(), nums.end(), v) - nums.begin() + 1;
            tree2.update(x, 1);
        }
        int ans = 0;
        int n = rating.size();
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(nums.begin(), nums.end(), rating[i]) - nums.begin() + 1;
            tree1.update(x, 1);
            tree2.update(x, -1);
            int l = tree1.query(x - 1);
            int r = n - i - 1 - tree2.query(x);
            ans += l * r;
            ans += (i - l) * (n - i - 1 - r);
        }
        return ans;
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

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func numTeams(rating []int) (ans int) {
	nums := make([]int, len(rating))
	copy(nums, rating)
	sort.Ints(nums)
	m := 0
	for i, x := range nums {
		if i == 0 || x != nums[i-1] {
			nums[m] = x
			m++
		}
	}
	nums = nums[:m]
	tree1 := newBinaryIndexedTree(m)
	tree2 := newBinaryIndexedTree(m)
	for _, x := range rating {
		tree2.update(sort.SearchInts(nums, x)+1, 1)
	}
	n := len(rating)
	for i, v := range rating {
		x := sort.SearchInts(nums, v) + 1
		tree1.update(x, 1)
		tree2.update(x, -1)
		l := tree1.query(x - 1)
		r := n - i - 1 - tree2.query(x)
		ans += l * r
		ans += (i - l) * (n - i - 1 - r)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numTeams(rating: number[]): number {
    const n = rating.length;
    const f: Record<Type, number[][]> = {
        asc: Array.from({ length: n }, () => Array(3).fill(-1)),
        desc: Array.from({ length: n }, () => Array(3).fill(-1)),
    };

    const fn = (i: number, available: number, type: Type) => {
        if (!available) {
            return 1;
        }
        if (f[type][i][available] !== -1) {
            return f[type][i][available];
        }

        let ans = 0;
        for (let j = i + 1; j < n; j++) {
            if (rating[j] > rating[i]) {
                if (type === 'asc') {
                    ans += fn(j, available - 1, 'asc');
                }
            } else {
                if (type === 'desc') {
                    ans += fn(j, available - 1, 'desc');
                }
            }
        }
        f[type][i][available] = ans;

        return ans;
    };

    let ans = 0;
    for (let i = 0; i < n; i++) {
        ans += fn(i, 2, 'asc') + fn(i, 2, 'desc');
    }

    return ans;
}

type Type = 'asc' | 'desc';
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} rating
 * @return {number}
 */
var numTeams = function (rating) {
    const n = rating.length;
    const f = {
        asc: Array.from({ length: n }, () => Array(3).fill(-1)),
        desc: Array.from({ length: n }, () => Array(3).fill(-1)),
    };

    const fn = (i, available, type) => {
        if (!available) {
            return 1;
        }
        if (f[type][i][available] !== -1) {
            return f[type][i][available];
        }

        let ans = 0;
        for (let j = i + 1; j < n; j++) {
            if (rating[j] > rating[i]) {
                if (type === 'asc') {
                    ans += fn(j, available - 1, 'asc');
                }
            } else {
                if (type === 'desc') {
                    ans += fn(j, available - 1, 'desc');
                }
            }
        }
        f[type][i][available] = ans;

        return ans;
    };

    let ans = 0;
    for (let i = 0; i < n; i++) {
        ans += fn(i, 2, 'asc') + fn(i, 2, 'desc');
    }

    return ans;
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class BinaryIndexedTree:
    def __init__(self, n: int):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x: int, v: int):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x: int) -> int:
        s = 0
        while x:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def numTeams(self, rating: List[int]) -> int:
        nums = sorted(set(rating))
        m = len(nums)
        tree1 = BinaryIndexedTree(m)
        tree2 = BinaryIndexedTree(m)
        for v in rating:
            x = bisect_left(nums, v) + 1
            tree2.update(x, 1)
        n = len(rating)
        ans = 0
        for i, v in enumerate(rating):
            x = bisect_left(nums, v) + 1
            tree1.update(x, 1)
            tree2.update(x, -1)
            l = tree1.query(x - 1)
            r = n - i - 1 - tree2.query(x)
            ans += l * r
            ans += (i - l) * (n - i - 1 - r)
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x > 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int[] nums = rating.clone();
        Arrays.sort(nums);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[m++] = nums[i];
            }
        }
        BinaryIndexedTree tree1 = new BinaryIndexedTree(m);
        BinaryIndexedTree tree2 = new BinaryIndexedTree(m);
        for (int v : rating) {
            int x = search(nums, v);
            tree2.update(x, 1);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x = search(nums, rating[i]);
            tree1.update(x, 1);
            tree2.update(x, -1);
            int l = tree1.query(x - 1);
            int r = n - i - 1 - tree2.query(x);
            ans += l * r;
            ans += (i - l) * (n - i - 1 - r);
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
        return l + 1;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int delta) {
        while (x <= n) {
            c[x] += delta;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> nums = rating;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size();
        BinaryIndexedTree tree1(m);
        BinaryIndexedTree tree2(m);
        for (int& v : rating) {
            int x = lower_bound(nums.begin(), nums.end(), v) - nums.begin() + 1;
            tree2.update(x, 1);
        }
        int ans = 0;
        int n = rating.size();
        for (int i = 0; i < n; ++i) {
            int x = lower_bound(nums.begin(), nums.end(), rating[i]) - nums.begin() + 1;
            tree1.update(x, 1);
            tree2.update(x, -1);
            int l = tree1.query(x - 1);
            int r = n - i - 1 - tree2.query(x);
            ans += l * r;
            ans += (i - l) * (n - i - 1 - r);
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}