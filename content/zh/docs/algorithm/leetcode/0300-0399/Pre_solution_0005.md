---
title: "0340_至多包含 K 个不同字符的最长子串 🔒"
date: 2025-10-08T18:35:54+08:00
weight: 5
tags: [二分查找, 位运算, 分治, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字符串, 快速选择, 排序, 数学, 数据流, 数组, 栈, 树, 桶排序, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 计数, 设计, 迭代器, 递归, 队列]
---

{{< markmap >}}
### [0340_至多包含 K 个不同字符的最长子串 🔒](#340)
#### [哈希表](#340)
#### [字符串](#340)
#### [滑动窗口](#340)
### [0341_扁平化嵌套列表迭代器](#341)
#### [栈](#341)
#### [树](#341)
#### [深度优先搜索](#341)
#### [设计](#341)
#### [队列](#341)
#### [迭代器](#341)
### [0342_4的幂](#342)
#### [位运算](#342)
#### [递归](#342)
#### [数学](#342)
### [0343_整数拆分](#343)
#### [数学](#343)
#### [动态规划](#343)
### [0344_反转字符串](#344)
#### [双指针](#344)
#### [字符串](#344)
### [0345_反转字符串中的元音字母](#345)
#### [双指针](#345)
#### [字符串](#345)
### [0346_数据流中的移动平均值 🔒](#346)
#### [设计](#346)
#### [队列](#346)
#### [数组](#346)
#### [数据流](#346)
### [0347_前 K 个高频元素](#347)
#### [数组](#347)
#### [哈希表](#347)
#### [分治](#347)
#### [桶排序](#347)
#### [计数](#347)
#### [快速选择](#347)
#### [排序](#347)
#### [堆（优先队列）](#347)
### [0348_设计井字棋 🔒](#348)
#### [设计](#348)
#### [数组](#348)
#### [哈希表](#348)
#### [矩阵](#348)
#### [模拟](#348)
### [0349_两个数组的交集](#349)
#### [数组](#349)
#### [哈希表](#349)
#### [双指针](#349)
#### [二分查找](#349)
#### [排序](#349)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0340_至多包含 K 个不同字符的最长子串 🔒
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 0341_扁平化嵌套列表迭代器
___
#### 栈
___
#### 树
___
#### 深度优先搜索
___
#### 设计
___
#### 队列
___
#### 迭代器
---
### 0342_4的幂
___
#### 位运算
___
#### 递归
___
#### 数学
---
### 0343_整数拆分
___
#### 数学
___
#### 动态规划
---
### 0344_反转字符串
___
#### 双指针
___
#### 字符串
---
### 0345_反转字符串中的元音字母
___
#### 双指针
___
#### 字符串
---
### 0346_数据流中的移动平均值 🔒
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 数据流
---
### 0347_前 K 个高频元素
___
#### 数组
___
#### 哈希表
___
#### 分治
___
#### 桶排序
___
#### 计数
___
#### 快速选择
___
#### 排序
___
#### 堆（优先队列）
---
### 0348_设计井字棋 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 矩阵
___
#### 模拟
---
### 0349_两个数组的交集
___
#### 数组
___
#### 哈希表
___
#### 双指针
___
#### 二分查找
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 动态规划 | 双指针 | 哈希表 |
| 堆（优先队列） | 字符串 | 快速选择 |
| 排序 | 数学 | 数据流 |
| 数组 | 栈 | 树 |
| 桶排序 | 模拟 | 深度优先搜索 |
| 滑动窗口 | 矩阵 | 计数 |
| 设计 | 迭代器 | 递归 |
| 队列 |  |  |

# [340. 至多包含 K 个不同字符的最长子串 🔒](https://leetcode.cn/problems/longest-substring-with-at-most-k-distinct-characters){#340}

{{< tabs "340" >}}

{{% tab "python" %}}
```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        l = 0
        cnt = Counter()
        for c in s:
            cnt[c] += 1
            if len(cnt) > k:
                cnt[s[l]] -= 1
                if cnt[s[l]] == 0:
                    del cnt[s[l]]
                l += 1
        return len(s) - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> cnt = new HashMap<>();
        int l = 0;
        char[] cs = s.toCharArray();
        for (char c : cs) {
            cnt.merge(c, 1, Integer::sum);
            if (cnt.size() > k) {
                if (cnt.merge(cs[l], -1, Integer::sum) == 0) {
                    cnt.remove(cs[l]);
                }
                ++l;
            }
        }
        return cs.length - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
        int l = 0;
        for (char& c : s) {
            ++cnt[c];
            if (cnt.size() > k) {
                if (--cnt[s[l]] == 0) {
                    cnt.erase(s[l]);
                }
                ++l;
            }
        }
        return s.size() - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lengthOfLongestSubstringKDistinct(s string, k int) int {
	cnt := map[byte]int{}
	l := 0
	for _, c := range s {
		cnt[byte(c)]++
		if len(cnt) > k {
			cnt[s[l]]--
			if cnt[s[l]] == 0 {
				delete(cnt, s[l])
			}
			l++
		}
	}
	return len(s) - l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lengthOfLongestSubstringKDistinct(s: string, k: number): number {
    const cnt: Map<string, number> = new Map();
    let l = 0;
    for (const c of s) {
        cnt.set(c, (cnt.get(c) ?? 0) + 1);
        if (cnt.size > k) {
            cnt.set(s[l], cnt.get(s[l])! - 1);
            if (cnt.get(s[l]) === 0) {
                cnt.delete(s[l]);
            }
            l++;
        }
    }
    return s.length - l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个整数 <code>k</code> ，请你找出&nbsp;<strong>至多&nbsp;</strong>包含<em> <code>k</code></em> 个 <strong>不同</strong> 字符的最长<span data-keyword="substring-nonempty">子串</span>，并返回该子串的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "eceba", k = 2
<strong>输出：</strong>3
<strong>解释：</strong>满足题目要求的子串是 "ece" ，长度为 3 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aa", k = 1
<strong>输出：</strong>2
<strong>解释：</strong>满足题目要求的子串是 "aa" ，长度为 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= k &lt;= 50</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 哈希表

我们可以使用滑动窗口的思想，用一个哈希表 $\textit{cnt}$ 记录窗口中每个字符的出现次数，用 $\textit{l}$ 记录窗口的左边界。

遍历字符串，每次将右边界的字符加入哈希表，如果哈希表中不同字符的个数超过了 $k$，则将左边界的字符从哈希表中删除，然后更新左边界 $\textit{l}$。

最后返回字符串的长度减去左边界的长度即可。

时间复杂度 $O(n)$，空间复杂度 $O(k)$。其中 $n$ 为字符串的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lengthOfLongestSubstringKDistinct(self, s: str, k: int) -> int:
        l = 0
        cnt = Counter()
        for c in s:
            cnt[c] += 1
            if len(cnt) > k:
                cnt[s[l]] -= 1
                if cnt[s[l]] == 0:
                    del cnt[s[l]]
                l += 1
        return len(s) - l
```

#### Java

```java
class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        Map<Character, Integer> cnt = new HashMap<>();
        int l = 0;
        char[] cs = s.toCharArray();
        for (char c : cs) {
            cnt.merge(c, 1, Integer::sum);
            if (cnt.size() > k) {
                if (cnt.merge(cs[l], -1, Integer::sum) == 0) {
                    cnt.remove(cs[l]);
                }
                ++l;
            }
        }
        return cs.length - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
        int l = 0;
        for (char& c : s) {
            ++cnt[c];
            if (cnt.size() > k) {
                if (--cnt[s[l]] == 0) {
                    cnt.erase(s[l]);
                }
                ++l;
            }
        }
        return s.size() - l;
    }
};
```

#### Go

```go
func lengthOfLongestSubstringKDistinct(s string, k int) int {
	cnt := map[byte]int{}
	l := 0
	for _, c := range s {
		cnt[byte(c)]++
		if len(cnt) > k {
			cnt[s[l]]--
			if cnt[s[l]] == 0 {
				delete(cnt, s[l])
			}
			l++
		}
	}
	return len(s) - l
}
```

#### TypeScript

```ts
function lengthOfLongestSubstringKDistinct(s: string, k: number): number {
    const cnt: Map<string, number> = new Map();
    let l = 0;
    for (const c of s) {
        cnt.set(c, (cnt.get(c) ?? 0) + 1);
        if (cnt.size > k) {
            cnt.set(s[l], cnt.get(s[l])! - 1);
            if (cnt.get(s[l]) === 0) {
                cnt.delete(s[l]);
            }
            l++;
        }
    }
    return s.length - l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [341. 扁平化嵌套列表迭代器](https://leetcode.cn/problems/flatten-nested-list-iterator){#341}

{{< tabs "341" >}}

{{% tab "python" %}}
```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def dfs(ls):
            for x in ls:
                if x.isInteger():
                    self.nums.append(x.getInteger())
                else:
                    dfs(x.getList())

        self.nums = []
        self.i = -1
        dfs(nestedList)

    def next(self) -> int:
        self.i += 1
        return self.nums[self.i]

    def hasNext(self) -> bool:
        return self.i + 1 < len(self.nums)


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private List<Integer> nums = new ArrayList<>();
    private int i = -1;

    public NestedIterator(List<NestedInteger> nestedList) {
        dfs(nestedList);
    }

    @Override
    public Integer next() {
        return nums.get(++i);
    }

    @Override
    public boolean hasNext() {
        return i + 1 < nums.size();
    }

    private void dfs(List<NestedInteger> ls) {
        for (var x : ls) {
            if (x.isInteger()) {
                nums.add(x.getInteger());
            } else {
                dfs(x.getList());
            }
        }
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        auto dfs = [&](this auto&& dfs, vector<NestedInteger>& ls) -> void {
            for (auto& x : ls) {
                if (x.isInteger()) {
                    nums.push_back(x.getInteger());
                } else {
                    dfs(x.getList());
                }
            }
        };
        dfs(nestedList);
    }

    int next() {
        return nums[++i];
    }

    bool hasNext() {
        return i + 1 < nums.size();
    }

private:
    vector<int> nums;
    int i = -1;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (this NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (this NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (this *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (this NestedInteger) GetList() []*NestedInteger {}
 */

type NestedIterator struct {
	nums []int
	i    int
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	var dfs func([]*NestedInteger)
	nums := []int{}
	i := -1
	dfs = func(ls []*NestedInteger) {
		for _, x := range ls {
			if x.IsInteger() {
				nums = append(nums, x.GetInteger())
			} else {
				dfs(x.GetList())
			}
		}
	}
	dfs(nestedList)
	return &NestedIterator{nums, i}
}

func (this *NestedIterator) Next() int {
	this.i++
	return this.nums[this.i]
}

func (this *NestedIterator) HasNext() bool {
	return this.i+1 < len(this.nums)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

class NestedIterator {
    private nums: number[] = [];
    private i = -1;
    constructor(nestedList: NestedInteger[]) {
        const dfs = (ls: NestedInteger[]) => {
            for (const x of ls) {
                if (x.isInteger()) {
                    this.nums.push(x.getInteger());
                } else {
                    dfs(x.getList());
                }
            }
        };
        dfs(nestedList);
    }

    hasNext(): boolean {
        return this.i + 1 < this.nums.length;
    }

    next(): number {
        return this.nums[++this.i];
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new NestedIterator(nestedList)
 * var a: number[] = []
 * while (obj.hasNext()) a.push(obj.next());
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// #[derive(Debug, PartialEq, Eq)]
// pub enum NestedInteger {
//   Int(i32),
//   List(Vec<NestedInteger>)
// }
struct NestedIterator {
    nums: Vec<i32>,
    i: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NestedIterator {
    fn new(nested_list: Vec<NestedInteger>) -> Self {
        let mut nums = Vec::new();
        Self::dfs(&nested_list, &mut nums);
        NestedIterator { nums, i: 0 }
    }

    fn next(&mut self) -> i32 {
        let result = self.nums[self.i];
        self.i += 1;
        result
    }

    fn has_next(&self) -> bool {
        self.i < self.nums.len()
    }

    fn dfs(nested_list: &Vec<NestedInteger>, nums: &mut Vec<i32>) {
        for ni in nested_list {
            match ni {
                NestedInteger::Int(x) => nums.push(*x),
                NestedInteger::List(list) => Self::dfs(list, nums),
            }
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

<p>给你一个嵌套的整数列表 <code>nestedList</code> 。每个元素要么是一个整数，要么是一个列表；该列表的元素也可能是整数或者是其他列表。请你实现一个迭代器将其扁平化，使之能够遍历这个列表中的所有整数。</p>

<p>实现扁平迭代器类 <code>NestedIterator</code> ：</p>

<ul>
	<li><code>NestedIterator(List&lt;NestedInteger&gt; nestedList)</code> 用嵌套列表 <code>nestedList</code> 初始化迭代器。</li>
	<li><code>int next()</code> 返回嵌套列表的下一个整数。</li>
	<li><code>boolean hasNext()</code> 如果仍然存在待迭代的整数，返回 <code>true</code> ；否则，返回 <code>false</code> 。</li>
</ul>

<p>你的代码将会用下述伪代码检测：</p>

<pre>
initialize iterator with nestedList
res = []
while iterator.hasNext()
    append iterator.next() to the end of res
return res</pre>

<p>如果 <code>res</code> 与预期的扁平化列表匹配，那么你的代码将会被判为正确。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nestedList = [[1,1],2,[1,1]]
<strong>输出：</strong>[1,1,2,1,1]
<strong>解释：</strong>通过重复调用&nbsp;<em>next </em>直到&nbsp;<em>hasNex</em>t 返回 false，<em>next&nbsp;</em>返回的元素的顺序应该是: <code>[1,1,2,1,1]</code>。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nestedList = [1,[4,[6]]]
<strong>输出：</strong>[1,4,6]
<strong>解释：</strong>通过重复调用&nbsp;<em>next&nbsp;</em>直到&nbsp;<em>hasNex</em>t 返回 false，<em>next&nbsp;</em>返回的元素的顺序应该是: <code>[1,4,6]</code>。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nestedList.length &lt;= 500</code></li>
	<li>嵌套列表中的整数值在范围 <code>[-10<sup>6</sup>, 10<sup>6</sup>]</code> 内</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

根据题意要求可以将 NestedInteger 数据结构视作一个 N 叉树，当元素为一个整数时，该节点是 N 叉树的叶子节点，当元素为一个整数数组时，该节点是 N 叉树的非叶子节点，数组中的每一个元素包含子树的所有节点。故直接递归遍历 N 叉树并记录所有的叶子节点即可。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """


class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        def dfs(ls):
            for x in ls:
                if x.isInteger():
                    self.nums.append(x.getInteger())
                else:
                    dfs(x.getList())

        self.nums = []
        self.i = -1
        dfs(nestedList)

    def next(self) -> int:
        self.i += 1
        return self.nums[self.i]

    def hasNext(self) -> bool:
        return self.i + 1 < len(self.nums)


# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
```

#### Java

```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private List<Integer> nums = new ArrayList<>();
    private int i = -1;

    public NestedIterator(List<NestedInteger> nestedList) {
        dfs(nestedList);
    }

    @Override
    public Integer next() {
        return nums.get(++i);
    }

    @Override
    public boolean hasNext() {
        return i + 1 < nums.size();
    }

    private void dfs(List<NestedInteger> ls) {
        for (var x : ls) {
            if (x.isInteger()) {
                nums.add(x.getInteger());
            } else {
                dfs(x.getList());
            }
        }
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
```

#### C++

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        auto dfs = [&](this auto&& dfs, vector<NestedInteger>& ls) -> void {
            for (auto& x : ls) {
                if (x.isInteger()) {
                    nums.push_back(x.getInteger());
                } else {
                    dfs(x.getList());
                }
            }
        };
        dfs(nestedList);
    }

    int next() {
        return nums[++i];
    }

    bool hasNext() {
        return i + 1 < nums.size();
    }

private:
    vector<int> nums;
    int i = -1;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```

#### Go

```go
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * type NestedInteger struct {
 * }
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * func (this NestedInteger) IsInteger() bool {}
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * // So before calling this method, you should have a check
 * func (this NestedInteger) GetInteger() int {}
 *
 * // Set this NestedInteger to hold a single integer.
 * func (n *NestedInteger) SetInteger(value int) {}
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 * func (this *NestedInteger) Add(elem NestedInteger) {}
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The list length is zero if this NestedInteger holds a single integer
 * // You can access NestedInteger's List element directly if you want to modify it
 * func (this NestedInteger) GetList() []*NestedInteger {}
 */

type NestedIterator struct {
	nums []int
	i    int
}

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	var dfs func([]*NestedInteger)
	nums := []int{}
	i := -1
	dfs = func(ls []*NestedInteger) {
		for _, x := range ls {
			if x.IsInteger() {
				nums = append(nums, x.GetInteger())
			} else {
				dfs(x.GetList())
			}
		}
	}
	dfs(nestedList)
	return &NestedIterator{nums, i}
}

func (this *NestedIterator) Next() int {
	this.i++
	return this.nums[this.i]
}

func (this *NestedIterator) HasNext() bool {
	return this.i+1 < len(this.nums)
}
```

#### TypeScript

```ts
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *     If value is provided, then it holds a single integer
 *     Otherwise it holds an empty nested list
 *     constructor(value?: number) {
 *         ...
 *     };
 *
 *     Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     isInteger(): boolean {
 *         ...
 *     };
 *
 *     Return the single integer that this NestedInteger holds, if it holds a single integer
 *     Return null if this NestedInteger holds a nested list
 *     getInteger(): number | null {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a single integer equal to value.
 *     setInteger(value: number) {
 *         ...
 *     };
 *
 *     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 *     add(elem: NestedInteger) {
 *         ...
 *     };
 *
 *     Return the nested list that this NestedInteger holds,
 *     or an empty list if this NestedInteger holds a single integer
 *     getList(): NestedInteger[] {
 *         ...
 *     };
 * };
 */

class NestedIterator {
    private nums: number[] = [];
    private i = -1;
    constructor(nestedList: NestedInteger[]) {
        const dfs = (ls: NestedInteger[]) => {
            for (const x of ls) {
                if (x.isInteger()) {
                    this.nums.push(x.getInteger());
                } else {
                    dfs(x.getList());
                }
            }
        };
        dfs(nestedList);
    }

    hasNext(): boolean {
        return this.i + 1 < this.nums.length;
    }

    next(): number {
        return this.nums[++this.i];
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * var obj = new NestedIterator(nestedList)
 * var a: number[] = []
 * while (obj.hasNext()) a.push(obj.next());
 */
```

#### Rust

```rust
// #[derive(Debug, PartialEq, Eq)]
// pub enum NestedInteger {
//   Int(i32),
//   List(Vec<NestedInteger>)
// }
struct NestedIterator {
    nums: Vec<i32>,
    i: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NestedIterator {
    fn new(nested_list: Vec<NestedInteger>) -> Self {
        let mut nums = Vec::new();
        Self::dfs(&nested_list, &mut nums);
        NestedIterator { nums, i: 0 }
    }

    fn next(&mut self) -> i32 {
        let result = self.nums[self.i];
        self.i += 1;
        result
    }

    fn has_next(&self) -> bool {
        self.i < self.nums.len()
    }

    fn dfs(nested_list: &Vec<NestedInteger>, nums: &mut Vec<i32>) {
        for ni in nested_list {
            match ni {
                NestedInteger::Int(x) => nums.push(*x),
                NestedInteger::List(list) => Self::dfs(list, nums),
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [342. 4的幂](https://leetcode.cn/problems/power-of-four){#342}

{{< tabs "342" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0 and (n & 0xAAAAAAAA) == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPowerOfFour(n int) bool {
	return n > 0 && (n&(n-1)) == 0 && (n&0xaaaaaaaa) == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPowerOfFour(n: number): boolean {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa_u32 as i32) == 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function (n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public bool IsPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>整数 <code>n</code> 是 4 的幂次方需满足：存在整数 <code>x</code> 使得 <code>n == 4<sup>x</sup></code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 16
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>true
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能不使用循环或者递归来完成本题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：位运算

如果一个数是 $4$ 的幂次方，那么这个数必须是大于 $0$ 的。不妨假设这个数是 $4^x$，即 $2^{2x}$，那么这个数的二进制表示中有且仅有一个 $1$，且这个 $1$ 出现在偶数位上。

因此，我们首先判断这个数是否大于 $0$，然后判断这个数是否是 $2^{2x}$，即 $n$ 与 $n-1$ 的按位与结果是否为 $0$，最后判断这个数的 $1$ 是否出现在偶数位上，即 $n$ 与 $\textit{0xAAAAAAAA}$ 的按位与结果是否为 $0$。如果这三个条件都满足，那么这个数就是 $4$ 的幂次方。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0 and (n & 0xAAAAAAAA) == 0
```

#### Java

```java
class Solution {
    public boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};
```

#### Go

```go
func isPowerOfFour(n int) bool {
	return n > 0 && (n&(n-1)) == 0 && (n&0xaaaaaaaa) == 0
}
```

#### TypeScript

```ts
function isPowerOfFour(n: number): boolean {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa_u32 as i32) == 0
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function (n) {
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
};
```

#### C#

```cs
public class Solution {
    public bool IsPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [343. 整数拆分](https://leetcode.cn/problems/integer-break){#343}

{{< tabs "343" >}}

{{% tab "python" %}}
```python
class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1
        if n % 3 == 0:
            return pow(3, n // 3)
        if n % 3 == 1:
            return pow(3, n // 3 - 1) * 4
        return pow(3, n // 3) * 2
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return (int) Math.pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return (int) Math.pow(3, n / 3 - 1) * 4;
        }
        return (int) Math.pow(3, n / 3) * 2;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return pow(3, n / 3 - 1) * 4;
        }
        return pow(3, n / 3) * 2;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func integerBreak(n int) int {
	if n < 4 {
		return n - 1
	}
	if n%3 == 0 {
		return int(math.Pow(3, float64(n/3)))
	}
	if n%3 == 1 {
		return int(math.Pow(3, float64(n/3-1))) * 4
	}
	return int(math.Pow(3, float64(n/3))) * 2
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function integerBreak(n: number): number {
    if (n < 4) {
        return n - 1;
    }
    const m = Math.floor(n / 3);
    if (n % 3 == 0) {
        return 3 ** m;
    }
    if (n % 3 == 1) {
        return 3 ** (m - 1) * 4;
    }
    return 3 ** m * 2;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        if n < 4 {
            return n - 1;
        }
        match n % 3 {
            0 => return (3 as i32).pow((n / 3) as u32),
            1 => return (3 as i32).pow((n / 3 - 1) as u32) * 4,
            _ => return (3 as i32).pow((n / 3) as u32) * 2,
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function (n) {
    if (n < 4) {
        return n - 1;
    }
    const m = Math.floor(n / 3);
    if (n % 3 == 0) {
        return 3 ** m;
    }
    if (n % 3 == 1) {
        return 3 ** (m - 1) * 4;
    }
    return 3 ** m * 2;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int IntegerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return (int)Math.Pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return (int)Math.Pow(3, n / 3 - 1) * 4;
        }
        return (int)Math.Pow(3, n / 3) * 2;
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int integerBreak(int n) {
    if (n < 4) {
        return n - 1;
    }
    if (n % 3 == 0) {
        return (int) pow(3, n / 3);
    }
    if (n % 3 == 1) {
        return (int) pow(3, n / 3 - 1) * 4;
    }
    return (int) pow(3, n / 3) * 2;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个正整数&nbsp;<code>n</code>&nbsp;，将其拆分为 <code>k</code> 个 <strong>正整数</strong> 的和（&nbsp;<code>k &gt;= 2</code>&nbsp;），并使这些整数的乘积最大化。</p>

<p>返回 <em>你可以获得的最大乘积</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong>n = 2
<strong>输出: </strong>1
<strong>解释: </strong>2 = 1 + 1, 1 × 1 = 1。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入: </strong>n = 10
<strong>输出: </strong>36
<strong>解释: </strong>10 = 3 + 3 + 4, 3 ×&nbsp;3 ×&nbsp;4 = 36。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 58</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示正整数 $i$ 拆分后能获得的最大乘积，初始时 $f[1] = 1$。答案即为 $f[n]$。

考虑 $i$ 最后拆分出的数字 $j$，其中 $j \in [1, i)$。对于 $i$ 拆分出的数字 $j$，有两种情况：

1. 将 $i$ 拆分成 $i - j$ 和 $j$ 的和，不继续拆分，此时乘积为 $(i - j) \times j$；
2. 将 $i$ 拆分成 $i - j$ 和 $j$ 的和，继续拆分，此时乘积为 $f[i - j] \times j$。

因此，我们可以得到状态转移方程：

$$
f[i] = \max(f[i], f[i - j] \times j, (i - j) \times j) \quad (j \in [0, i))
$$

最后返回 $f[n]$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为给定的正整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def integerBreak(self, n: int) -> int:
        f = [1] * (n + 1)
        for i in range(2, n + 1):
            for j in range(1, i):
                f[i] = max(f[i], f[i - j] * j, (i - j) * j)
        return f[n]
```

#### Java

```java
class Solution {
    public int integerBreak(int n) {
        int[] f = new int[n + 1];
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                f[i] = Math.max(Math.max(f[i], f[i - j] * j), (i - j) * j);
            }
        }
        return f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> f(n + 1);
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                f[i] = max({f[i], f[i - j] * j, (i - j) * j});
            }
        }
        return f[n];
    }
};
```

#### Go

```go
func integerBreak(n int) int {
	f := make([]int, n+1)
	f[1] = 1
	for i := 2; i <= n; i++ {
		for j := 1; j < i; j++ {
			f[i] = max(max(f[i], f[i-j]*j), (i-j)*j)
		}
	}
	return f[n]
}
```

#### TypeScript

```ts
function integerBreak(n: number): number {
    const f = Array(n + 1).fill(1);
    for (let i = 3; i <= n; i++) {
        for (let j = 1; j < i; j++) {
            f[i] = Math.max(f[i], j * (i - j), j * f[i - j]);
        }
    }
    return f[n];
}
```

#### Rust

```rust
impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        let n = n as usize;
        let mut f = vec![0; n + 1];
        f[1] = 1;
        for i in 2..=n {
            for j in 1..i {
                f[i] = f[i].max(f[i - j] * j).max((i - j) * j);
            }
        }
        f[n] as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function (n) {
    const f = Array(n + 1).fill(1);
    for (let i = 2; i <= n; ++i) {
        for (let j = 1; j < i; ++j) {
            f[i] = Math.max(f[i], f[i - j] * j, (i - j) * j);
        }
    }
    return f[n];
};
```

#### C#

```cs
public class Solution {
    public int IntegerBreak(int n) {
        int[] f = new int[n + 1];
        f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                f[i] = Math.Max(Math.Max(f[i], f[i - j] * j), (i - j) * j);
            }
        }
        return f[n];
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int integerBreak(int n) {
    int* f = (int*) malloc((n + 1) * sizeof(int));
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = 0;
        for (int j = 1; j < i; ++j) {
            f[i] = max(f[i], max(f[i - j] * j, (i - j) * j));
        }
    }
    return f[n];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

当 $n \lt 4$ 时，由于题目要求至少拆分成两个整数，因此 $n - 1$ 是最大乘积。当 $n \ge 4$ 时，我们尽可能多地拆分 $3$，当剩下的最后一段为 $4$ 时，我们将其拆分为 $2 + 2$，这样乘积最大。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1
        if n % 3 == 0:
            return pow(3, n // 3)
        if n % 3 == 1:
            return pow(3, n // 3 - 1) * 4
        return pow(3, n // 3) * 2
```

#### Java

```java
class Solution {
    public int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return (int) Math.pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return (int) Math.pow(3, n / 3 - 1) * 4;
        }
        return (int) Math.pow(3, n / 3) * 2;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return pow(3, n / 3 - 1) * 4;
        }
        return pow(3, n / 3) * 2;
    }
};
```

#### Go

```go
func integerBreak(n int) int {
	if n < 4 {
		return n - 1
	}
	if n%3 == 0 {
		return int(math.Pow(3, float64(n/3)))
	}
	if n%3 == 1 {
		return int(math.Pow(3, float64(n/3-1))) * 4
	}
	return int(math.Pow(3, float64(n/3))) * 2
}
```

#### TypeScript

```ts
function integerBreak(n: number): number {
    if (n < 4) {
        return n - 1;
    }
    const m = Math.floor(n / 3);
    if (n % 3 == 0) {
        return 3 ** m;
    }
    if (n % 3 == 1) {
        return 3 ** (m - 1) * 4;
    }
    return 3 ** m * 2;
}
```

#### Rust

```rust
impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        if n < 4 {
            return n - 1;
        }
        match n % 3 {
            0 => return (3 as i32).pow((n / 3) as u32),
            1 => return (3 as i32).pow((n / 3 - 1) as u32) * 4,
            _ => return (3 as i32).pow((n / 3) as u32) * 2,
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function (n) {
    if (n < 4) {
        return n - 1;
    }
    const m = Math.floor(n / 3);
    if (n % 3 == 0) {
        return 3 ** m;
    }
    if (n % 3 == 1) {
        return 3 ** (m - 1) * 4;
    }
    return 3 ** m * 2;
};
```

#### C#

```cs
public class Solution {
    public int IntegerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return (int)Math.Pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return (int)Math.Pow(3, n / 3 - 1) * 4;
        }
        return (int)Math.Pow(3, n / 3) * 2;
    }
}
```

#### C

```c
int integerBreak(int n) {
    if (n < 4) {
        return n - 1;
    }
    if (n % 3 == 0) {
        return (int) pow(3, n / 3);
    }
    if (n % 3 == 1) {
        return (int) pow(3, n / 3 - 1) * 4;
    }
    return (int) pow(3, n / 3) * 2;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [344. 反转字符串](https://leetcode.cn/problems/reverse-string){#344}

{{< tabs "344" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        i, j = 0, len(s) - 1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void reverseString(char[] s) {
        for (int i = 0, j = s.length - 1; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j;) {
            swap(s[i++], s[j--]);
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseString(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        [s[i], s[j]] = [s[j], s[i]];
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let mut i = 0;
        let mut j = s.len() - 1;
        while i < j {
            s.swap(i, j);
            i += 1;
            j -= 1;
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        [s[i], s[j]] = [s[j], s[i]];
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 <code>s</code> 的形式给出。</p>

<p>不要给另外的数组分配额外的空间，你必须<strong><a href="https://baike.baidu.com/item/原地算法" target="_blank">原地</a>修改输入数组</strong>、使用 O(1) 的额外空间解决这一问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = ["h","e","l","l","o"]
<strong>输出：</strong>["o","l","l","e","h"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = ["H","a","n","n","a","h"]
<strong>输出：</strong>["h","a","n","n","a","H"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 都是 <a href="https://baike.baidu.com/item/ASCII" target="_blank">ASCII</a> 码表中的可打印字符</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$，初始时分别指向数组的首尾，每次将 $i$ 和 $j$ 对应的元素交换，然后 $i$ 向后移动，$j$ 向前移动，直到 $i$ 和 $j$ 相遇。

时间复杂度 $O(n)$，其中 $n$ 是数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseString(self, s: List[str]) -> None:
        i, j = 0, len(s) - 1
        while i < j:
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
```

#### Java

```java
class Solution {
    public void reverseString(char[] s) {
        for (int i = 0, j = s.length - 1; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j;) {
            swap(s[i++], s[j--]);
        }
    }
};
```

#### Go

```go
func reverseString(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
```

#### TypeScript

```ts
/**
 Do not return anything, modify s in-place instead.
 */
function reverseString(s: string[]): void {
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        [s[i], s[j]] = [s[j], s[i]];
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let mut i = 0;
        let mut j = s.len() - 1;
        while i < j {
            s.swap(i, j);
            i += 1;
            j -= 1;
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
    for (let i = 0, j = s.length - 1; i < j; ++i, --j) {
        [s[i], s[j]] = [s[j], s[i]];
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [345. 反转字符串中的元音字母](https://leetcode.cn/problems/reverse-vowels-of-a-string){#345}

{{< tabs "345" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        i, j = 0, len(s) - 1
        cs = list(s)
        while i < j:
            while i < j and cs[i] not in vowels:
                i += 1
            while i < j and cs[j] not in vowels:
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
    public String reverseVowels(String s) {
        boolean[] vowels = new boolean[128];
        for (char c : "aeiouAEIOU".toCharArray()) {
            vowels[c] = true;
        }
        char[] cs = s.toCharArray();
        int i = 0, j = cs.length - 1;
        while (i < j) {
            while (i < j && !vowels[cs[i]]) {
                ++i;
            }
            while (i < j && !vowels[cs[j]]) {
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
        return String.valueOf(cs);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reverseVowels(string s) {
        bool vowels[128];
        memset(vowels, false, sizeof(vowels));
        for (char c : "aeiouAEIOU") {
            vowels[c] = true;
        }
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !vowels[s[i]]) {
                ++i;
            }
            while (i < j && !vowels[s[j]]) {
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
func reverseVowels(s string) string {
	vowels := [128]bool{}
	for _, c := range "aeiouAEIOU" {
		vowels[c] = true
	}
	cs := []byte(s)
	i, j := 0, len(cs)-1
	for i < j {
		for i < j && !vowels[cs[i]] {
			i++
		}
		for i < j && !vowels[cs[j]] {
			j--
		}
		if i < j {
			cs[i], cs[j] = cs[j], cs[i]
			i, j = i+1, j-1
		}
	}
	return string(cs)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reverseVowels(s: string): string {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const cs = s.split('');
    for (let i = 0, j = cs.length - 1; i < j; ++i, --j) {
        while (i < j && !vowels.has(cs[i].toLowerCase())) {
            ++i;
        }
        while (i < j && !vowels.has(cs[j].toLowerCase())) {
            --j;
        }
        [cs[i], cs[j]] = [cs[j], cs[i]];
    }
    return cs.join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let vowel = String::from("aeiouAEIOU");
        let mut data: Vec<char> = s.chars().collect();
        let (mut i, mut j) = (0, s.len() - 1);
        while i < j {
            while i < j && !vowel.contains(data[i]) {
                i += 1;
            }
            while i < j && !vowel.contains(data[j]) {
                j -= 1;
            }
            if i < j {
                data.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        data.iter().collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，仅反转字符串中的所有元音字母，并返回结果字符串。</p>

<p>元音字母包括 <code>'a'</code>、<code>'e'</code>、<code>'i'</code>、<code>'o'</code>、<code>'u'</code>，且可能以大小写两种形式出现不止一次。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "IceCreAm"</span></p>

<p><span class="example-io"><b>输出：</b>"AceCreIm"</span></p>

<p><strong>解释：</strong></p>

<p><code>s</code>&nbsp;中的元音是&nbsp;<code>['I', 'e', 'e', 'A']</code>。反转这些元音，<code>s</code> 变为&nbsp;<code>"AceCreIm"</code>.</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>s = "leetcode"</span></p>

<p><strong>输出：</strong><span class="example-io">"leotcede"</span></p>

<p>&nbsp;</p>
</div>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> 由 <strong>可打印的 ASCII</strong> 字符组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以用两个指针 $i$ 和 $j$，初始时分别指向字符串的首尾。

每次循环判断 $i$ 指向的字符是否是元音字母，如果不是则向后移动 $i$；同理，判断 $j$ 指向的字符是否是元音字母，如果不是则向前移动 $j$。如果此时 $i \lt j$，那么 $i$ 和 $j$ 指向的字符都是元音字母，交换这两个字符。然后向后移动 $i$，向前移动 $j$。继续上述操作，直到 $i \ge j$。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(|\Sigma|)$，其中 $\Sigma$ 是字符集的大小。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = "aeiouAEIOU"
        i, j = 0, len(s) - 1
        cs = list(s)
        while i < j:
            while i < j and cs[i] not in vowels:
                i += 1
            while i < j and cs[j] not in vowels:
                j -= 1
            if i < j:
                cs[i], cs[j] = cs[j], cs[i]
                i, j = i + 1, j - 1
        return "".join(cs)
```

#### Java

```java
class Solution {
    public String reverseVowels(String s) {
        boolean[] vowels = new boolean[128];
        for (char c : "aeiouAEIOU".toCharArray()) {
            vowels[c] = true;
        }
        char[] cs = s.toCharArray();
        int i = 0, j = cs.length - 1;
        while (i < j) {
            while (i < j && !vowels[cs[i]]) {
                ++i;
            }
            while (i < j && !vowels[cs[j]]) {
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
        return String.valueOf(cs);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reverseVowels(string s) {
        bool vowels[128];
        memset(vowels, false, sizeof(vowels));
        for (char c : "aeiouAEIOU") {
            vowels[c] = true;
        }
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !vowels[s[i]]) {
                ++i;
            }
            while (i < j && !vowels[s[j]]) {
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
func reverseVowels(s string) string {
	vowels := [128]bool{}
	for _, c := range "aeiouAEIOU" {
		vowels[c] = true
	}
	cs := []byte(s)
	i, j := 0, len(cs)-1
	for i < j {
		for i < j && !vowels[cs[i]] {
			i++
		}
		for i < j && !vowels[cs[j]] {
			j--
		}
		if i < j {
			cs[i], cs[j] = cs[j], cs[i]
			i, j = i+1, j-1
		}
	}
	return string(cs)
}
```

#### TypeScript

```ts
function reverseVowels(s: string): string {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    const cs = s.split('');
    for (let i = 0, j = cs.length - 1; i < j; ++i, --j) {
        while (i < j && !vowels.has(cs[i].toLowerCase())) {
            ++i;
        }
        while (i < j && !vowels.has(cs[j].toLowerCase())) {
            --j;
        }
        [cs[i], cs[j]] = [cs[j], cs[i]];
    }
    return cs.join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let vowel = String::from("aeiouAEIOU");
        let mut data: Vec<char> = s.chars().collect();
        let (mut i, mut j) = (0, s.len() - 1);
        while i < j {
            while i < j && !vowel.contains(data[i]) {
                i += 1;
            }
            while i < j && !vowel.contains(data[j]) {
                j -= 1;
            }
            if i < j {
                data.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        data.iter().collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [346. 数据流中的移动平均值 🔒](https://leetcode.cn/problems/moving-average-from-data-stream){#346}

{{< tabs "346" >}}

{{% tab "python" %}}
```python
class MovingAverage:
    def __init__(self, size: int):
        self.n = size
        self.s = 0
        self.q = deque()

    def next(self, val: int) -> float:
        if len(self.q) == self.n:
            self.s -= self.q.popleft()
        self.q.append(val)
        self.s += val
        return self.s / len(self.q)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MovingAverage {
    private Deque<Integer> q = new ArrayDeque<>();
    private int n;
    private int s;

    public MovingAverage(int size) {
        n = size;
    }

    public double next(int val) {
        if (q.size() == n) {
            s -= q.pollFirst();
        }
        q.offer(val);
        s += val;
        return s * 1.0 / q.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MovingAverage {
public:
    MovingAverage(int size) {
        n = size;
    }

    double next(int val) {
        if (q.size() == n) {
            s -= q.front();
            q.pop();
        }
        q.push(val);
        s += val;
        return (double) s / q.size();
    }

private:
    queue<int> q;
    int s = 0;
    int n;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MovingAverage struct {
	q []int
	s int
	n int
}

func Constructor(size int) MovingAverage {
	return MovingAverage{n: size}
}

func (this *MovingAverage) Next(val int) float64 {
	if len(this.q) == this.n {
		this.s -= this.q[0]
		this.q = this.q[1:]
	}
	this.q = append(this.q, val)
	this.s += val
	return float64(this.s) / float64(len(this.q))
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MovingAverage {
    private q: number[] = [];
    private s: number = 0;
    private n: number;

    constructor(size: number) {
        this.n = size;
    }

    next(val: number): number {
        if (this.q.length === this.n) {
            this.s -= this.q.shift()!;
        }
        this.q.push(val);
        this.s += val;
        return this.s / this.q.length;
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = new MovingAverage(size)
 * var param_1 = obj.next(val)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。</p>

<p>实现 <code>MovingAverage</code> 类：</p>

<ul>
	<li><code>MovingAverage(int size)</code> 用窗口大小 <code>size</code> 初始化对象。</li>
	<li><code>double next(int val)</code> 计算并返回数据流中最后 <code>size</code> 个值的移动平均值。</li>
</ul>

<p> </p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
<strong>输出：</strong>
[null, 1.0, 5.5, 4.66667, 6.0]

<strong>解释：</strong>
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // 返回 1.0 = 1 / 1
movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= size <= 1000</code></li>
	<li><code>-10<sup>5</sup> <= val <= 10<sup>5</sup></code></li>
	<li>最多调用 <code>next</code> 方法 <code>10<sup>4</sup></code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：循环数组

我们定义一个变量 $\textit{s}$，用于计算当前最后 $\textit{size}$ 个元素的和，用一个变量 $\textit{cnt}$ 记录当前元素的总数。另外，我们用一个长度为 $\textit{size}$ 的数组 $\textit{data}$ 记录每个位置的元素对应的值。

调用 $\textit{next}$ 函数时，我们先计算出 $\textit{val}$ 要存放的下标 $i$，然后我们更新元素和 $s$，并且将下标 $i$ 处的值设置为 $\textit{val}$，同时将元素的个数加一。最后，我们返回 $\frac{s}{\min(\textit{cnt}, \textit{size})}$ 的值即可。

时间复杂度 $O(1)$，空间复杂度 $O(n)$，其中 $n$ 是题目给定的整数 $\textit{size}$。

<!-- tabs:start -->

#### Python3

```python
class MovingAverage:

    def __init__(self, size: int):
        self.s = 0
        self.data = [0] * size
        self.cnt = 0

    def next(self, val: int) -> float:
        i = self.cnt % len(self.data)
        self.s += val - self.data[i]
        self.data[i] = val
        self.cnt += 1
        return self.s / min(self.cnt, len(self.data))


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```

#### Java

```java
class MovingAverage {
    private int s;
    private int cnt;
    private int[] data;

    public MovingAverage(int size) {
        data = new int[size];
    }

    public double next(int val) {
        int i = cnt % data.length;
        s += val - data[i];
        data[i] = val;
        ++cnt;
        return s * 1.0 / Math.min(cnt, data.length);
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```

#### C++

```cpp
class MovingAverage {
public:
    MovingAverage(int size) {
        data.resize(size);
    }

    double next(int val) {
        int i = cnt % data.size();
        s += val - data[i];
        data[i] = val;
        ++cnt;
        return s * 1.0 / min(cnt, (int) data.size());
    }

private:
    int s = 0;
    int cnt = 0;
    vector<int> data;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```

#### Go

```go
type MovingAverage struct {
	s    int
	cnt  int
	data []int
}

func Constructor(size int) MovingAverage {
	return MovingAverage{
		data: make([]int, size),
	}
}

func (this *MovingAverage) Next(val int) float64 {
	i := this.cnt % len(this.data)
	this.s += val - this.data[i]
	this.data[i] = val
	this.cnt++
	return float64(this.s) / float64(min(this.cnt, len(this.data)))
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */
```

#### TypeScript

```ts
class MovingAverage {
    private s: number = 0;
    private cnt: number = 0;
    private data: number[];

    constructor(size: number) {
        this.data = Array(size).fill(0);
    }

    next(val: number): number {
        const i = this.cnt % this.data.length;
        this.s += val - this.data[i];
        this.data[i] = val;
        this.cnt++;
        return this.s / Math.min(this.cnt, this.data.length);
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = new MovingAverage(size)
 * var param_1 = obj.next(val)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：队列

我们可以使用一个队列 $\textit{q}$ 来存储最后 $\textit{size}$ 个元素，同时用一个变量 $\textit{s}$ 来记录这 $\textit{size}$ 个元素的和。

在调用 $\textit{next}$ 函数时，我们首先判断队列 $\textit{q}$ 的长度是否等于 $\textit{size}$，如果等于 $\textit{size}$，则将队列 $\textit{q}$ 的头部元素出队，并且更新 $\textit{s}$ 的值。然后将 $\textit{val}$ 入队，并且更新 $\textit{s}$ 的值。最后返回 $\frac{s}{\text{len}(q)}$ 的值即可。

时间复杂度 $O(1)$，空间复杂度 $O(n)$，其中 $n$ 是题目给定的整数 $\textit{size}$。

<!-- tabs:start -->

#### Python3

```python
class MovingAverage:
    def __init__(self, size: int):
        self.n = size
        self.s = 0
        self.q = deque()

    def next(self, val: int) -> float:
        if len(self.q) == self.n:
            self.s -= self.q.popleft()
        self.q.append(val)
        self.s += val
        return self.s / len(self.q)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
```

#### Java

```java
class MovingAverage {
    private Deque<Integer> q = new ArrayDeque<>();
    private int n;
    private int s;

    public MovingAverage(int size) {
        n = size;
    }

    public double next(int val) {
        if (q.size() == n) {
            s -= q.pollFirst();
        }
        q.offer(val);
        s += val;
        return s * 1.0 / q.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
```

#### C++

```cpp
class MovingAverage {
public:
    MovingAverage(int size) {
        n = size;
    }

    double next(int val) {
        if (q.size() == n) {
            s -= q.front();
            q.pop();
        }
        q.push(val);
        s += val;
        return (double) s / q.size();
    }

private:
    queue<int> q;
    int s = 0;
    int n;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
```

#### Go

```go
type MovingAverage struct {
	q []int
	s int
	n int
}

func Constructor(size int) MovingAverage {
	return MovingAverage{n: size}
}

func (this *MovingAverage) Next(val int) float64 {
	if len(this.q) == this.n {
		this.s -= this.q[0]
		this.q = this.q[1:]
	}
	this.q = append(this.q, val)
	this.s += val
	return float64(this.s) / float64(len(this.q))
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * obj := Constructor(size);
 * param_1 := obj.Next(val);
 */
```

#### TypeScript

```ts
class MovingAverage {
    private q: number[] = [];
    private s: number = 0;
    private n: number;

    constructor(size: number) {
        this.n = size;
    }

    next(val: number): number {
        if (this.q.length === this.n) {
            this.s -= this.q.shift()!;
        }
        this.q.push(val);
        this.s += val;
        return this.s / this.q.length;
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * var obj = new MovingAverage(size)
 * var param_1 = obj.next(val)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [347. 前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements){#347}

{{< tabs "347" >}}

{{% tab "python" %}}
```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        return [x for x, _ in cnt.most_common(k)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq
            = new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue));
        for (var e : cnt.entrySet()) {
            pq.offer(e);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        return pq.stream().mapToInt(Map.Entry::getKey).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        using pii = pair<int, int>;
        for (int x : nums) {
            ++cnt[x];
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto& [x, c] : cnt) {
            pq.push({c, x});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func topKFrequent(nums []int, k int) []int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	pq := hp{}
	for x, c := range cnt {
		heap.Push(&pq, pair{x, c})
		if pq.Len() > k {
			heap.Pop(&pq)
		}
	}
	ans := make([]int, k)
	for i := 0; i < k; i++ {
		ans[i] = heap.Pop(&pq).(pair).v
	}
	return ans
}

type pair struct{ v, cnt int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].cnt < h[j].cnt }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function topKFrequent(nums: number[], k: number): number[] {
    const cnt = new Map<number, number>();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    const pq = new MinPriorityQueue();
    for (const [x, c] of cnt) {
        pq.enqueue(x, c);
        if (pq.size() > k) {
            pq.dequeue();
        }
    }
    return pq.toArray().map(x => x.element);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut cnt = HashMap::new();
        for x in nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        let mut pq = BinaryHeap::with_capacity(k as usize);
        for (&x, &c) in cnt.iter() {
            pq.push(Reverse((c, x)));
            if pq.len() > k as usize {
                pq.pop();
            }
        }
        pq.into_iter().map(|Reverse((_, x))| x).collect()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> ，请你返回其中出现频率前 <code>k</code> 高的元素。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,1,1,2,2,3], k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">[1,2]</span></p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1], k = 1</span></p>

<p><span class="example-io"><b>输出：</b>[1]</span></p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,2,1,2,1,2,3,1,3,2], k = 2</span></p>

<p><strong>输出：</strong><span class="example-io">[1,2]</span></p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>k</code> 的取值范围是 <code>[1, 数组中不相同的元素的个数]</code></li>
	<li>题目数据保证答案唯一，换句话说，数组中前 <code>k</code> 个高频元素的集合是唯一的</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你所设计算法的时间复杂度 <strong>必须</strong> 优于 <code>O(n log n)</code> ，其中 <code>n</code><em>&nbsp;</em>是数组大小。</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 优先队列（小根堆）

我们可以使用一个哈希表 $\textit{cnt}$ 统计每个元素出现的次数，然后使用一个小根堆（优先队列）来保存前 $k$ 个高频元素。

我们首先遍历一遍数组，统计每个元素出现的次数，然后遍历哈希表，将元素和出现次数存入小根堆中。如果小根堆的大小超过了 $k$，我们就将堆顶元素弹出，保证堆的大小始终为 $k$。

最后，我们将小根堆中的元素依次弹出，放入结果数组中即可。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(k)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = Counter(nums)
        return [x for x, _ in cnt.most_common(k)]
```

#### Java

```java
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq
            = new PriorityQueue<>(Comparator.comparingInt(Map.Entry::getValue));
        for (var e : cnt.entrySet()) {
            pq.offer(e);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        return pq.stream().mapToInt(Map.Entry::getKey).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        using pii = pair<int, int>;
        for (int x : nums) {
            ++cnt[x];
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto& [x, c] : cnt) {
            pq.push({c, x});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```

#### Go

```go
func topKFrequent(nums []int, k int) []int {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	pq := hp{}
	for x, c := range cnt {
		heap.Push(&pq, pair{x, c})
		if pq.Len() > k {
			heap.Pop(&pq)
		}
	}
	ans := make([]int, k)
	for i := 0; i < k; i++ {
		ans[i] = heap.Pop(&pq).(pair).v
	}
	return ans
}

type pair struct{ v, cnt int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].cnt < h[j].cnt }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
function topKFrequent(nums: number[], k: number): number[] {
    const cnt = new Map<number, number>();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) ?? 0) + 1);
    }
    const pq = new MinPriorityQueue();
    for (const [x, c] of cnt) {
        pq.enqueue(x, c);
        if (pq.size() > k) {
            pq.dequeue();
        }
    }
    return pq.toArray().map(x => x.element);
}
```

#### Rust

```rust
use std::cmp::Reverse;
use std::collections::{BinaryHeap, HashMap};

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut cnt = HashMap::new();
        for x in nums {
            *cnt.entry(x).or_insert(0) += 1;
        }
        let mut pq = BinaryHeap::with_capacity(k as usize);
        for (&x, &c) in cnt.iter() {
            pq.push(Reverse((c, x)));
            if pq.len() > k as usize {
                pq.pop();
            }
        }
        pq.into_iter().map(|Reverse((_, x))| x).collect()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [348. 设计井字棋 🔒](https://leetcode.cn/problems/design-tic-tac-toe){#348}

{{< tabs "348" >}}

{{% tab "python" %}}
```python
class TicTacToe:

    def __init__(self, n: int):
        self.n = n
        self.cnt = [defaultdict(int), defaultdict(int)]

    def move(self, row: int, col: int, player: int) -> int:
        cur = self.cnt[player - 1]
        n = self.n
        cur[row] += 1
        cur[n + col] += 1
        if row == col:
            cur[n << 1] += 1
        if row + col == n - 1:
            cur[n << 1 | 1] += 1
        if any(cur[i] == n for i in (row, n + col, n << 1, n << 1 | 1)):
            return player
        return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class TicTacToe {
    private int n;
    private int[][] cnt;

    public TicTacToe(int n) {
        this.n = n;
        cnt = new int[2][(n << 1) + 2];
    }

    public int move(int row, int col, int player) {
        int[] cur = cnt[player - 1];
        ++cur[row];
        ++cur[n + col];
        if (row == col) {
            ++cur[n << 1];
        }
        if (row + col == n - 1) {
            ++cur[n << 1 | 1];
        }
        if (cur[row] == n || cur[n + col] == n || cur[n << 1] == n || cur[n << 1 | 1] == n) {
            return player;
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class TicTacToe {
private:
    int n;
    vector<vector<int>> cnt;

public:
    TicTacToe(int n)
        : n(n)
        , cnt(2, vector<int>((n << 1) + 2, 0)) {
    }

    int move(int row, int col, int player) {
        vector<int>& cur = cnt[player - 1];
        ++cur[row];
        ++cur[n + col];
        if (row == col) {
            ++cur[n << 1];
        }
        if (row + col == n - 1) {
            ++cur[n << 1 | 1];
        }
        if (cur[row] == n || cur[n + col] == n || cur[n << 1] == n || cur[n << 1 | 1] == n) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type TicTacToe struct {
	n   int
	cnt [][]int
}

func Constructor(n int) TicTacToe {
	cnt := make([][]int, 2)
	for i := range cnt {
		cnt[i] = make([]int, (n<<1)+2)
	}
	return TicTacToe{n, cnt}
}

func (this *TicTacToe) Move(row int, col int, player int) int {
	cur := this.cnt[player-1]
	cur[row]++
	cur[this.n+col]++
	if row == col {
		cur[this.n<<1]++
	}
	if row+col == this.n-1 {
		cur[this.n<<1|1]++
	}
	if cur[row] == this.n || cur[this.n+col] == this.n || cur[this.n<<1] == this.n || cur[this.n<<1|1] == this.n {
		return player
	}
	return 0
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Move(row,col,player);
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class TicTacToe {
    private n: number;
    private cnt: number[][];

    constructor(n: number) {
        this.n = n;
        this.cnt = [Array((n << 1) + 2).fill(0), Array((n << 1) + 2).fill(0)];
    }

    move(row: number, col: number, player: number): number {
        const cur = this.cnt[player - 1];
        cur[row]++;
        cur[this.n + col]++;
        if (row === col) {
            cur[this.n << 1]++;
        }
        if (row + col === this.n - 1) {
            cur[(this.n << 1) | 1]++;
        }
        if (
            cur[row] === this.n ||
            cur[this.n + col] === this.n ||
            cur[this.n << 1] === this.n ||
            cur[(this.n << 1) | 1] === this.n
        ) {
            return player;
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * var obj = new TicTacToe(n)
 * var param_1 = obj.move(row,col,player)
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请在 n ×&nbsp;n 的棋盘上，实现一个判定井字棋（Tic-Tac-Toe）胜负的神器，判断每一次玩家落子后，是否有胜出的玩家。</p>

<p>在这个井字棋游戏中，会有 2 名玩家，他们将轮流在棋盘上放置自己的棋子。</p>

<p>在实现这个判定器的过程中，你可以假设以下这些规则一定成立：</p>

<p>&nbsp; &nbsp; &nbsp; 1. 每一步棋都是在棋盘内的，并且只能被放置在一个空的格子里；</p>

<p>&nbsp; &nbsp; &nbsp; 2. 一旦游戏中有一名玩家胜出的话，游戏将不能再继续；</p>

<p>&nbsp; &nbsp; &nbsp; 3. 一个玩家如果在同一行、同一列或者同一斜对角线上都放置了自己的棋子，那么他便获得胜利。</p>

<p><strong>示例:</strong></p>

<pre>
给定棋盘边长 <em>n</em> = 3, 玩家 1 的棋子符号是 "X"，玩家 2 的棋子符号是 "O"。

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -&gt; 函数返回 0 (此时，暂时没有玩家赢得这场对决)
|X| | |
| | | |    // 玩家 1 在 (0, 0) 落子。
| | | |

toe.move(0, 2, 2); -&gt; 函数返回 0 (暂时没有玩家赢得本场比赛)
|X| |O|
| | | |    // 玩家 2 在 (0, 2) 落子。
| | | |

toe.move(2, 2, 1); -&gt; 函数返回 0 (暂时没有玩家赢得比赛)
|X| |O|
| | | |    // 玩家 1 在 (2, 2) 落子。
| | |X|

toe.move(1, 1, 2); -&gt; 函数返回 0 (暂没有玩家赢得比赛)
|X| |O|
| |O| |    // 玩家 2 在 (1, 1) 落子。
| | |X|

toe.move(2, 0, 1); -&gt; 函数返回 0 (暂无玩家赢得比赛)
|X| |O|
| |O| |    // 玩家 1 在 (2, 0) 落子。
|X| |X|

toe.move(1, 0, 2); -&gt; 函数返回 0 (没有玩家赢得比赛)
|X| |O|
|O|O| |    // 玩家 2 在 (1, 0) 落子.
|X| |X|

toe.move(2, 1, 1); -&gt; 函数返回 1 (此时，玩家 1 赢得了该场比赛)
|X| |O|
|O|O| |    // 玩家 1 在 (2, 1) 落子。
|X|X|X|
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li>玩家是&nbsp;<code>1</code> 或&nbsp;<code>2</code>。</li>
	<li><code>0 &lt;= row, col &lt; n</code></li>
	<li>每次调用 <code>move</code>&nbsp;时&nbsp;<code>(row, col)</code>&nbsp;都是不同的。</li>
	<li>最多调用&nbsp;<code>move</code>&nbsp;&nbsp;<code>n<sup>2</sup></code>&nbsp;次。</li>
</ul>

<p><strong>进阶:</strong><br />
您有没有可能将每一步的&nbsp;<code>move()</code>&nbsp;操作优化到比&nbsp;O(<em>n</em><sup>2</sup>) 更快吗?</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们可以使用一个长度为 $n \times 2 + 2$ 的数组来记录每个玩家在每一行、每一列、两条对角线上的棋子数。我们需要两个这样的数组，分别记录两个玩家的棋子数。

当一个玩家在某一行、某一列、某一对角线上的棋子数等于 $n$ 时，该玩家获胜。

时间复杂度方面，每次落子的时间复杂度为 $O(1)$。空间复杂度为 $O(n)$，其中 $n$ 为棋盘的边长。

<!-- tabs:start -->

#### Python3

```python
class TicTacToe:

    def __init__(self, n: int):
        self.n = n
        self.cnt = [defaultdict(int), defaultdict(int)]

    def move(self, row: int, col: int, player: int) -> int:
        cur = self.cnt[player - 1]
        n = self.n
        cur[row] += 1
        cur[n + col] += 1
        if row == col:
            cur[n << 1] += 1
        if row + col == n - 1:
            cur[n << 1 | 1] += 1
        if any(cur[i] == n for i in (row, n + col, n << 1, n << 1 | 1)):
            return player
        return 0


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
```

#### Java

```java
class TicTacToe {
    private int n;
    private int[][] cnt;

    public TicTacToe(int n) {
        this.n = n;
        cnt = new int[2][(n << 1) + 2];
    }

    public int move(int row, int col, int player) {
        int[] cur = cnt[player - 1];
        ++cur[row];
        ++cur[n + col];
        if (row == col) {
            ++cur[n << 1];
        }
        if (row + col == n - 1) {
            ++cur[n << 1 | 1];
        }
        if (cur[row] == n || cur[n + col] == n || cur[n << 1] == n || cur[n << 1 | 1] == n) {
            return player;
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
```

#### C++

```cpp
class TicTacToe {
private:
    int n;
    vector<vector<int>> cnt;

public:
    TicTacToe(int n)
        : n(n)
        , cnt(2, vector<int>((n << 1) + 2, 0)) {
    }

    int move(int row, int col, int player) {
        vector<int>& cur = cnt[player - 1];
        ++cur[row];
        ++cur[n + col];
        if (row == col) {
            ++cur[n << 1];
        }
        if (row + col == n - 1) {
            ++cur[n << 1 | 1];
        }
        if (cur[row] == n || cur[n + col] == n || cur[n << 1] == n || cur[n << 1 | 1] == n) {
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
```

#### Go

```go
type TicTacToe struct {
	n   int
	cnt [][]int
}

func Constructor(n int) TicTacToe {
	cnt := make([][]int, 2)
	for i := range cnt {
		cnt[i] = make([]int, (n<<1)+2)
	}
	return TicTacToe{n, cnt}
}

func (this *TicTacToe) Move(row int, col int, player int) int {
	cur := this.cnt[player-1]
	cur[row]++
	cur[this.n+col]++
	if row == col {
		cur[this.n<<1]++
	}
	if row+col == this.n-1 {
		cur[this.n<<1|1]++
	}
	if cur[row] == this.n || cur[this.n+col] == this.n || cur[this.n<<1] == this.n || cur[this.n<<1|1] == this.n {
		return player
	}
	return 0
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Move(row,col,player);
 */
```

#### TypeScript

```ts
class TicTacToe {
    private n: number;
    private cnt: number[][];

    constructor(n: number) {
        this.n = n;
        this.cnt = [Array((n << 1) + 2).fill(0), Array((n << 1) + 2).fill(0)];
    }

    move(row: number, col: number, player: number): number {
        const cur = this.cnt[player - 1];
        cur[row]++;
        cur[this.n + col]++;
        if (row === col) {
            cur[this.n << 1]++;
        }
        if (row + col === this.n - 1) {
            cur[(this.n << 1) | 1]++;
        }
        if (
            cur[row] === this.n ||
            cur[this.n + col] === this.n ||
            cur[this.n << 1] === this.n ||
            cur[(this.n << 1) | 1] === this.n
        ) {
            return player;
        }
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * var obj = new TicTacToe(n)
 * var param_1 = obj.move(row,col,player)
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [349. 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays){#349}

{{< tabs "349" >}}

{{% tab "python" %}}
```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        boolean[] s = new boolean[1001];
        for (int x : nums1) {
            s[x] = true;
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : nums2) {
            if (s[x]) {
                ans.add(x);
                s[x] = false;
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool s[1001];
        memset(s, false, sizeof(s));
        for (int x : nums1) {
            s[x] = true;
        }
        vector<int> ans;
        for (int x : nums2) {
            if (s[x]) {
                ans.push_back(x);
                s[x] = false;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func intersection(nums1 []int, nums2 []int) (ans []int) {
	s := [1001]bool{}
	for _, x := range nums1 {
		s[x] = true
	}
	for _, x := range nums2 {
		if s[x] {
			ans = append(ans, x)
			s[x] = false
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function intersection(nums1: number[], nums2: number[]): number[] {
    const s = new Set(nums1);
    return [...new Set(nums2.filter(x => s.has(x)))];
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function (nums1, nums2) {
    const s = new Set(nums1);
    return [...new Set(nums2.filter(x => s.has(x)))];
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        HashSet<int> s1 = new HashSet<int>(nums1);
        HashSet<int> s2 = new HashSet<int>(nums2);
        s1.IntersectWith(s2);
        int[] ans = new int[s1.Count];
        s1.CopyTo(ans);
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {
        $s1 = array_unique($nums1);
        $s2 = array_unique($nums2);
        $ans = array_intersect($s1, $s2);
        return array_values($ans);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code> ，返回 <em>它们的 <span data-keyword="array-intersection">交集</span></em>&nbsp;。输出结果中的每个元素一定是 <strong>唯一</strong> 的。我们可以 <strong>不考虑输出结果的顺序</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [1,2,2,1], nums2 = [2,2]
<strong>输出：</strong>[2]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>输出：</strong>[9,4]
<strong>解释：</strong>[4,9] 也是可通过的
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们先用哈希表或者一个长度为 $1001$ 的数组 $s$ 记录数组 $nums1$ 中出现的元素，然后遍历数组 $nums2$ 中每个元素，如果元素 $x$ 在 $s$ 中，那么将 $x$ 加入答案，并且从 $s$ 中移除 $x$。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n+m)$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1) & set(nums2))
```

#### Java

```java
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        boolean[] s = new boolean[1001];
        for (int x : nums1) {
            s[x] = true;
        }
        List<Integer> ans = new ArrayList<>();
        for (int x : nums2) {
            if (s[x]) {
                ans.add(x);
                s[x] = false;
            }
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool s[1001];
        memset(s, false, sizeof(s));
        for (int x : nums1) {
            s[x] = true;
        }
        vector<int> ans;
        for (int x : nums2) {
            if (s[x]) {
                ans.push_back(x);
                s[x] = false;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func intersection(nums1 []int, nums2 []int) (ans []int) {
	s := [1001]bool{}
	for _, x := range nums1 {
		s[x] = true
	}
	for _, x := range nums2 {
		if s[x] {
			ans = append(ans, x)
			s[x] = false
		}
	}
	return
}
```

#### TypeScript

```ts
function intersection(nums1: number[], nums2: number[]): number[] {
    const s = new Set(nums1);
    return [...new Set(nums2.filter(x => s.has(x)))];
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function (nums1, nums2) {
    const s = new Set(nums1);
    return [...new Set(nums2.filter(x => s.has(x)))];
};
```

#### C#

```cs
public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        HashSet<int> s1 = new HashSet<int>(nums1);
        HashSet<int> s2 = new HashSet<int>(nums2);
        s1.IntersectWith(s2);
        int[] ans = new int[s1.Count];
        s1.CopyTo(ans);
        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    function intersection($nums1, $nums2) {
        $s1 = array_unique($nums1);
        $s2 = array_unique($nums2);
        $ans = array_intersect($s1, $s2);
        return array_values($ans);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
