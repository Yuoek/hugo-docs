---
title: "1438_LongestContinuousSubarrayWithAbsoluteDiffLessThanorEqualtoLimit"
date: 2025-10-06T00:42:37+08:00
weight: 1438
tags: [队列, 数组, 有序集合, 滑动窗口, 单调队列, 堆（优先队列）]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [1438. 绝对差不超过限制的最长连续子数组](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit)

[English Version](../en/1438-38/1438_LongestContinuousSubarrayWithAbsoluteDiffLessThanorEqualtoLimit)

## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，和一个表示限制的整数 <code>limit</code>，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 <code>limit</code><em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [8,2,4,7], limit = 4
<strong>输出：</strong>2 
<strong>解释：</strong>所有子数组如下：
[8] 最大绝对差 |8-8| = 0 &lt;= 4.
[8,2] 最大绝对差 |8-2| = 6 &gt; 4. 
[8,2,4] 最大绝对差 |8-2| = 6 &gt; 4.
[8,2,4,7] 最大绝对差 |8-2| = 6 &gt; 4.
[2] 最大绝对差 |2-2| = 0 &lt;= 4.
[2,4] 最大绝对差 |2-4| = 2 &lt;= 4.
[2,4,7] 最大绝对差 |2-7| = 5 &gt; 4.
[4] 最大绝对差 |4-4| = 0 &lt;= 4.
[4,7] 最大绝对差 |4-7| = 3 &lt;= 4.
[7] 最大绝对差 |7-7| = 0 &lt;= 4. 
因此，满足题意的最长子数组的长度为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,1,2,4,7,2], limit = 5
<strong>输出：</strong>4 
<strong>解释：</strong>满足题意的最长子数组是 [2,4,7,2]，其最大绝对差 |2-7| = 5 &lt;= 5 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [4,2,2,2,4,4,2,2], limit = 0
<strong>输出：</strong>3
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= limit &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：有序集合 + 滑动窗口

我们可以枚举每个位置作为子数组的右端点，找到其对应的最靠左的左端点，满足区间内中最大值与最小值的差值不超过 $limit$。过程中，我们用有序集合维护窗口内的最大值和最小值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 `nums` 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找 + 滑动窗口

我们注意到，如果一个长度为 $k$ 的子数组满足条件，那么长度 $k' < k$ 的子数组也满足条件，这存在着单调性，因此，我们可以使用二分查找，找到最长的满足条件的子数组。

我们定义二分查找的左边界 $l = 0$，右边界 $r = n$。对于每个 $mid = \frac{l + r + 1}{2}$，我们检查是否存在一个长度为 $mid$ 的子数组满足条件。如果存在，我们更新 $l = mid$，否则更新 $r = mid - 1$。那么问题转换为数组中是否存在一个长度为 $mid$ 的子数组满足条件，这其实是求滑动窗口中的最大值和最小值的差值不超过 $limit$。我们可以用两个单调队列分别维护窗口内的最大值和最小值。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：滑动窗口 + 双向队列

我们可以使用双向队列维护窗口内的最大值和最小值。我们维护两个双向队列，分别存储窗口内的最大值和最小值的下标。定义两个指针 $l$ 和 $r$ 分别指向窗口的左边界和右边界。

每次向右移动右边界 $r$，判断最大值队列的队尾下标对应的元素是否小于当前元素，如果小于，则将队尾元素出队，直到最大值队列的队尾元素对应的元素不小于当前元素。同理，判断最小值队列的队尾下标对应的元素是否大于当前元素，如果大于，则将队尾元素出队，直到最小值队列的队尾元素对应的元素不大于当前元素。然后，将当前元素的下标入队。

如果最大值队列的队首元素和最小值队列的队首元素的差值大于 $limit$，则向右移动左边界 $l$，然后如果最大值队列的队首元素小于 $l$，则将最大值队列的队首元素出队，如果最小值队列的队首元素小于 $l$，则将最小值队列的队首元素出队。

答案为 $n - l$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxq = deque()
        minq = deque()
        l, n = 0, len(nums)
        for r, x in enumerate(nums):
            while maxq and nums[maxq[-1]] < x:
                maxq.pop()
            while minq and nums[minq[-1]] > x:
                minq.pop()
            maxq.append(r)
            minq.append(r)
            if nums[maxq[0]] - nums[minq[0]] > limit:
                l += 1
                if maxq[0] < l:
                    maxq.popleft()
                if minq[0] < l:
                    minq.popleft()
        return n - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int n = nums.length;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[r]) {
                maxQ.pollLast();
            }
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[r]) {
                minQ.pollLast();
            }
            maxQ.offerLast(r);
            minQ.offerLast(r);
            if (nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > limit) {
                ++l;
                if (maxQ.peekFirst() < l) {
                    maxQ.pollFirst();
                }
                if (minQ.peekFirst() < l) {
                    minQ.pollFirst();
                }
            }
        }
        return n - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_q;
        deque<int> min_q;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (!max_q.empty() && nums[max_q.back()] < nums[r]) {
                max_q.pop_back();
            }
            while (!min_q.empty() && nums[min_q.back()] > nums[r]) {
                min_q.pop_back();
            }
            max_q.push_back(r);
            min_q.push_back(r);

            if (nums[max_q.front()] - nums[min_q.front()] > limit) {
                ++l;
                if (max_q.front() < l) {
                    max_q.pop_front();
                }
                if (min_q.front() < l) {
                    min_q.pop_front();
                }
            }
        }
        return n - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestSubarray(nums []int, limit int) int {
	var maxq, minq Deque
	n := len(nums)
	l := 0
	for r, x := range nums {
		for !maxq.Empty() && nums[maxq.Back()] < x {
			maxq.PopBack()
		}
		for !minq.Empty() && nums[minq.Back()] > x {
			minq.PopBack()
		}
		maxq.PushBack(r)
		minq.PushBack(r)

		if nums[maxq.Front()]-nums[minq.Front()] > limit {
			l++
			if maxq.Front() < l {
				maxq.PopFront()
			}
			if minq.Front() < l {
				minq.PopFront()
			}
		}
	}
	return n - l
}

type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestSubarray(nums: number[], limit: number): number {
    const n = nums.length;
    let [h1, t1] = [0, -1];
    let [h2, t2] = [0, -1];
    let l = 0;
    const maxq = Array(n);
    const minq = Array(n);
    for (let r = 0; r < n; ++r) {
        while (h1 <= t1 && nums[maxq[t1]] < nums[r]) {
            --t1;
        }
        while (h2 <= t2 && nums[minq[t2]] > nums[r]) {
            --t2;
        }
        maxq[++t1] = r;
        minq[++t2] = r;
        if (nums[maxq[h1]] - nums[minq[h2]] > limit) {
            ++l;
            if (maxq[h1] < l) {
                ++h1;
            }
            if (minq[h2] < l) {
                ++h2;
            }
        }
    }
    return n - l;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxq = deque()
        minq = deque()
        l, n = 0, len(nums)
        for r, x in enumerate(nums):
            while maxq and nums[maxq[-1]] < x:
                maxq.pop()
            while minq and nums[minq[-1]] > x:
                minq.pop()
            maxq.append(r)
            minq.append(r)
            if nums[maxq[0]] - nums[minq[0]] > limit:
                l += 1
                if maxq[0] < l:
                    maxq.popleft()
                if minq[0] < l:
                    minq.popleft()
        return n - l
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int longestSubarray(int[] nums, int limit) {
        Deque<Integer> maxQ = new ArrayDeque<>();
        Deque<Integer> minQ = new ArrayDeque<>();
        int n = nums.length;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] < nums[r]) {
                maxQ.pollLast();
            }
            while (!minQ.isEmpty() && nums[minQ.peekLast()] > nums[r]) {
                minQ.pollLast();
            }
            maxQ.offerLast(r);
            minQ.offerLast(r);
            if (nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > limit) {
                ++l;
                if (maxQ.peekFirst() < l) {
                    maxQ.pollFirst();
                }
                if (minQ.peekFirst() < l) {
                    minQ.pollFirst();
                }
            }
        }
        return n - l;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_q;
        deque<int> min_q;
        int n = nums.size();
        int l = 0;

        for (int r = 0; r < n; ++r) {
            while (!max_q.empty() && nums[max_q.back()] < nums[r]) {
                max_q.pop_back();
            }
            while (!min_q.empty() && nums[min_q.back()] > nums[r]) {
                min_q.pop_back();
            }
            max_q.push_back(r);
            min_q.push_back(r);

            if (nums[max_q.front()] - nums[min_q.front()] > limit) {
                ++l;
                if (max_q.front() < l) {
                    max_q.pop_front();
                }
                if (min_q.front() < l) {
                    min_q.pop_front();
                }
            }
        }
        return n - l;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}