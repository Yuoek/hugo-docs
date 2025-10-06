---
title: "2059_MinimumOperationstoConvertNumber"
date: 2025-10-06T00:42:37+08:00
weight: 2059
tags: [Breadth-First Search, Array]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [2059. Minimum Operations to Convert Number](https://leetcode.com/problems/minimum-operations-to-convert-number)

[中文文档](/solution/2000-2099/2059.Minimum%20Operations%20to%20Convert%20Number/README.md)

## Description

<!-- description:start -->

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> containing <strong>distinct</strong> numbers, an integer <code>start</code>, and an integer <code>goal</code>. There is an integer <code>x</code> that is initially set to <code>start</code>, and you want to perform operations on <code>x</code> such that it is converted to <code>goal</code>. You can perform the following operation repeatedly on the number <code>x</code>:</p>

<p>If <code>0 &lt;= x &lt;= 1000</code>, then for any index <code>i</code> in the array (<code>0 &lt;= i &lt; nums.length</code>), you can set <code>x</code> to any of the following:</p>

<ul>
	<li><code>x + nums[i]</code></li>
	<li><code>x - nums[i]</code></li>
	<li><code>x ^ nums[i]</code> (bitwise-XOR)</li>
</ul>

<p>Note that you can use each <code>nums[i]</code> any number of times in any order. Operations that set <code>x</code> to be out of the range <code>0 &lt;= x &lt;= 1000</code> are valid, but no more operations can be done afterward.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed to convert </em><code>x = start</code><em> into </em><code>goal</code><em>, and </em><code>-1</code><em> if it is not possible</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,4,12], start = 2, goal = 12
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can go from 2 &rarr; 14 &rarr; 12 with the following 2 operations.
- 2 + 12 = 14
- 14 - 2 = 12
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,5,7], start = 0, goal = -4
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can go from 0 &rarr; 3 &rarr; -4 with the following 2 operations. 
- 0 + 3 = 3
- 3 - 7 = -4
Note that the last operation sets x out of the range 0 &lt;= x &lt;= 1000, which is valid.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,8,16], start = 0, goal = 1
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no way to convert 0 into 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i], goal &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= start &lt;= 1000</code></li>
	<li><code>start != goal</code></li>
	<li>All the integers in <code>nums</code> are distinct.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        def next(x):
            res = []
            for num in nums:
                res.append(x + num)
                res.append(x - num)
                res.append(x ^ num)
            return res

        def extend(m1, m2, q):
            for _ in range(len(q)):
                x = q.popleft()
                step = m1[x]
                for y in next(x):
                    if y in m1:
                        continue
                    if y in m2:
                        return step + 1 + m2[y]
                    if 0 <= y <= 1000:
                        m1[y] = step + 1
                        q.append(y)
            return -1

        m1, m2 = {start: 0}, {goal: 0}
        q1, q2 = deque([start]), deque([goal])
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;

    public int minimumOperations(int[] nums, int start, int goal) {
        this.nums = nums;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        Deque<Integer> q1 = new ArrayDeque<>();
        Deque<Integer> q2 = new ArrayDeque<>();
        m1.put(start, 0);
        m2.put(goal, 0);
        q1.offer(start);
        q2.offer(goal);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<Integer, Integer> m1, Map<Integer, Integer> m2, Deque<Integer> q) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.poll();
            int step = m1.get(x);
            for (int y : next(x)) {
                if (m1.containsKey(y)) {
                    continue;
                }
                if (m2.containsKey(y)) {
                    return step + 1 + m2.get(y);
                }
                if (y >= 0 && y <= 1000) {
                    m1.put(y, step + 1);
                    q.offer(y);
                }
            }
        }
        return -1;
    }

    private List<Integer> next(int x) {
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            res.add(x + num);
            res.add(x - num);
            res.add(x ^ num);
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        m1[start] = 0;
        m2[goal] = 0;
        queue<int> q1{{start}};
        queue<int> q2{{goal}};
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1, nums) : extend(m2, m1, q2, nums);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<int, int>& m1, unordered_map<int, int>& m2, queue<int>& q, vector<int>& nums) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.front();
            int step = m1[x];
            q.pop();
            for (int y : next(nums, x)) {
                if (m1.count(y)) continue;
                if (m2.count(y)) return step + 1 + m2[y];
                if (y >= 0 && y <= 1000) {
                    m1[y] = step + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }

    vector<int> next(vector<int>& nums, int x) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(x + num);
            res.push_back(x - num);
            res.push_back(x ^ num);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumOperations(nums []int, start int, goal int) int {
	next := func(x int) []int {
		var res []int
		for _, num := range nums {
			res = append(res, []int{x + num, x - num, x ^ num}...)
		}
		return res
	}
	m1, m2 := map[int]int{start: 0}, map[int]int{goal: 0}
	q1, q2 := []int{start}, []int{goal}
	extend := func() int {
		for i := len(q1); i > 0; i-- {
			x := q1[0]
			q1 = q1[1:]
			step, _ := m1[x]
			for _, y := range next(x) {
				if _, ok := m1[y]; ok {
					continue
				}
				if v, ok := m2[y]; ok {
					return step + 1 + v
				}
				if y >= 0 && y <= 1000 {
					m1[y] = step + 1
					q1 = append(q1, y)
				}
			}
		}
		return -1
	}
	for len(q1) > 0 && len(q2) > 0 {
		if len(q1) > len(q2) {
			m1, m2 = m2, m1
			q1, q2 = q2, q1
		}
		t := extend()
		if t != -1 {
			return t
		}
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumOperations(nums: number[], start: number, goal: number): number {
    const n = nums.length;
    const op1 = function (x: number, y: number): number {
        return x + y;
    };
    const op2 = function (x: number, y: number): number {
        return x - y;
    };
    const op3 = function (x: number, y: number): number {
        return x ^ y;
    };
    const ops = [op1, op2, op3];
    let vis = new Array(1001).fill(false);
    let quenue: Array<Array<number>> = [[start, 0]];
    vis[start] = true;
    while (quenue.length) {
        let [x, step] = quenue.shift();
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < ops.length; j++) {
                const nx = ops[j](x, nums[i]);
                if (nx == goal) {
                    return step + 1;
                }
                if (nx >= 0 && nx <= 1000 && !vis[nx]) {
                    vis[nx] = true;
                    quenue.push([nx, step + 1]);
                }
            }
        }
    }
    return -1;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        def next(x):
            res = []
            for num in nums:
                res.append(x + num)
                res.append(x - num)
                res.append(x ^ num)
            return res

        def extend(m1, m2, q):
            for _ in range(len(q)):
                x = q.popleft()
                step = m1[x]
                for y in next(x):
                    if y in m1:
                        continue
                    if y in m2:
                        return step + 1 + m2[y]
                    if 0 <= y <= 1000:
                        m1[y] = step + 1
                        q.append(y)
            return -1

        m1, m2 = {start: 0}, {goal: 0}
        q1, q2 = deque([start]), deque([goal])
        while q1 and q2:
            t = extend(m1, m2, q1) if len(q1) <= len(q2) else extend(m2, m1, q2)
            if t != -1:
                return t
        return -1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private int[] nums;

    public int minimumOperations(int[] nums, int start, int goal) {
        this.nums = nums;
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        Deque<Integer> q1 = new ArrayDeque<>();
        Deque<Integer> q2 = new ArrayDeque<>();
        m1.put(start, 0);
        m2.put(goal, 0);
        q1.offer(start);
        q2.offer(goal);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1) : extend(m2, m1, q2);
            if (t != -1) {
                return t;
            }
        }
        return -1;
    }

    private int extend(Map<Integer, Integer> m1, Map<Integer, Integer> m2, Deque<Integer> q) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.poll();
            int step = m1.get(x);
            for (int y : next(x)) {
                if (m1.containsKey(y)) {
                    continue;
                }
                if (m2.containsKey(y)) {
                    return step + 1 + m2.get(y);
                }
                if (y >= 0 && y <= 1000) {
                    m1.put(y, step + 1);
                    q.offer(y);
                }
            }
        }
        return -1;
    }

    private List<Integer> next(int x) {
        List<Integer> res = new ArrayList<>();
        for (int num : nums) {
            res.add(x + num);
            res.add(x - num);
            res.add(x ^ num);
        }
        return res;
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
    int minimumOperations(vector<int>& nums, int start, int goal) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        m1[start] = 0;
        m2[goal] = 0;
        queue<int> q1{{start}};
        queue<int> q2{{goal}};
        while (!q1.empty() && !q2.empty()) {
            int t = q1.size() <= q2.size() ? extend(m1, m2, q1, nums) : extend(m2, m1, q2, nums);
            if (t != -1) return t;
        }
        return -1;
    }

    int extend(unordered_map<int, int>& m1, unordered_map<int, int>& m2, queue<int>& q, vector<int>& nums) {
        for (int i = q.size(); i > 0; --i) {
            int x = q.front();
            int step = m1[x];
            q.pop();
            for (int y : next(nums, x)) {
                if (m1.count(y)) continue;
                if (m2.count(y)) return step + 1 + m2[y];
                if (y >= 0 && y <= 1000) {
                    m1[y] = step + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }

    vector<int> next(vector<int>& nums, int x) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(x + num);
            res.push_back(x - num);
            res.push_back(x ^ num);
        }
        return res;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}