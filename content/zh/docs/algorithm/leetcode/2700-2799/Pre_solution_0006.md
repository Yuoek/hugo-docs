---
title: "2750_将数组划分成若干好子数组的方式"
date: 2025-10-08T18:39:33+08:00
weight: 6
tags: [JavaScript, 动态规划, 排序, 数学, 数据库, 数组, 栈, 模拟]
---

{{< markmap >}}
### [2750_将数组划分成若干好子数组的方式](#2750)
#### [数组](#2750)
#### [数学](#2750)
#### [动态规划](#2750)
### [2751_机器人碰撞](#2751)
#### [栈](#2751)
#### [数组](#2751)
#### [排序](#2751)
#### [模拟](#2751)
### [2752_在连续天数上进行了最多交易次数的顾客 🔒](#2752)
#### [数据库](#2752)
### [2753_计算一个环形街道上的房屋数量 II 🔒](#2753)
### [2754_将函数绑定到上下文 🔒](#2754)
#### [JavaScript](#2754)
### [2755_深度合并两个对象 🔒](#2755)
#### [JavaScript](#2755)
### [2756_批处理查询 🔒](#2756)
#### [JavaScript](#2756)
### [2757_生成循环数组的值 🔒](#2757)
#### [JavaScript](#2757)
### [2758_下一天 🔒](#2758)
#### [JavaScript](#2758)
### [2759_将 JSON 字符串转换为对象 🔒](#2759)
#### [JavaScript](#2759)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2750_将数组划分成若干好子数组的方式
___
#### 数组
___
#### 数学
___
#### 动态规划
---
### 2751_机器人碰撞
___
#### 栈
___
#### 数组
___
#### 排序
___
#### 模拟
---
### 2752_在连续天数上进行了最多交易次数的顾客 🔒
___
#### 数据库
---
### 2753_计算一个环形街道上的房屋数量 II 🔒
---
### 2754_将函数绑定到上下文 🔒
___
#### JavaScript
---
### 2755_深度合并两个对象 🔒
___
#### JavaScript
---
### 2756_批处理查询 🔒
___
#### JavaScript
---
### 2757_生成循环数组的值 🔒
___
#### JavaScript
---
### 2758_下一天 🔒
___
#### JavaScript
---
### 2759_将 JSON 字符串转换为对象 🔒
___
#### JavaScript
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| JavaScript | 动态规划 | 排序 |
| 数学 | 数据库 | 数组 |
| 栈 | 模拟 |  |

# [2750. 将数组划分成若干好子数组的方式](https://leetcode.cn/problems/ways-to-split-array-into-good-subarrays){#2750}

{{< tabs "2750" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        ans, j = 1, -1
        for i, x in enumerate(nums):
            if x == 0:
                continue
            if j > -1:
                ans = ans * (i - j) % mod
            j = i
        return 0 if j == -1 else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfGoodSubarraySplits(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int ans = 1, j = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (j > -1) {
                ans = (int) ((long) ans * (i - j) % mod);
            }
            j = i;
        }
        return j == -1 ? 0 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int ans = 1, j = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (j > -1) {
                ans = 1LL * ans * (i - j) % mod;
            }
            j = i;
        }
        return j == -1 ? 0 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfGoodSubarraySplits(nums []int) int {
	const mod int = 1e9 + 7
	ans, j := 1, -1
	for i, x := range nums {
		if x == 0 {
			continue
		}
		if j > -1 {
			ans = ans * (i - j) % mod
		}
		j = i
	}
	if j == -1 {
		return 0
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfGoodSubarraySplits(nums: number[]): number {
    let ans = 1;
    let j = -1;
    const mod = 10 ** 9 + 7;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (nums[i] === 0) {
            continue;
        }
        if (j > -1) {
            ans = (ans * (i - j)) % mod;
        }
        j = i;
    }
    return j === -1 ? 0 : ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int NumberOfGoodSubarraySplits(int[] nums) {
        long ans = 1, j = -1;
        int mod = 1000000007;
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (j > -1) {
                ans = ans * (i - j) % mod;
            }
            j = i;
        }
        return j == -1 ? 0 : (int) ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二元数组 <code>nums</code> 。</p>

<p>如果数组中的某个子数组 <strong>恰好</strong> 只存在 <strong>一</strong> 个值为 <code>1</code> 的元素，则认为该子数组是一个 <strong>好子数组</strong> 。</p>

<p>请你统计将数组 <code>nums</code> 划分成若干 <strong>好子数组</strong> 的方法数，并以整数形式返回。由于数字可能很大，返回其对 <code>10<sup>9</sup> + 7</code> <strong>取余 </strong>之后的结果。</p>

<p>子数组是数组中的一个连续 <strong>非空</strong> 元素序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,0,0,1]
<strong>输出：</strong>3
<strong>解释：</strong>存在 3 种可以将 nums 划分成若干好子数组的方式：
- [0,1] [0,0,1]
- [0,1,0] [0,1]
- [0,1,0,0] [1]
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,1,0]
<strong>输出：</strong>1
<strong>解释：</strong>存在 1 种可以将 nums 划分成若干好子数组的方式：
- [0,1,0]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：乘法原理

根据题目描述，我们可以在两个 $1$ 之间画一条分割线，假设两个 $1$ 之间的下标分别为 $j$ 和 $i$，那么可以画的不同分割线的数量为 $i - j$。我们找出所有满足条件的 $j$ 和 $i$，然后将所有的 $i - j$ 相乘即可。如果找不到两个 $1$ 之间的分割线，那么说明数组中不存在 $1$，此时答案为 $0$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfGoodSubarraySplits(self, nums: List[int]) -> int:
        mod = 10**9 + 7
        ans, j = 1, -1
        for i, x in enumerate(nums):
            if x == 0:
                continue
            if j > -1:
                ans = ans * (i - j) % mod
            j = i
        return 0 if j == -1 else ans
```

#### Java

```java
class Solution {
    public int numberOfGoodSubarraySplits(int[] nums) {
        final int mod = (int) 1e9 + 7;
        int ans = 1, j = -1;
        for (int i = 0; i < nums.length; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (j > -1) {
                ans = (int) ((long) ans * (i - j) % mod);
            }
            j = i;
        }
        return j == -1 ? 0 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int ans = 1, j = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (j > -1) {
                ans = 1LL * ans * (i - j) % mod;
            }
            j = i;
        }
        return j == -1 ? 0 : ans;
    }
};
```

#### Go

```go
func numberOfGoodSubarraySplits(nums []int) int {
	const mod int = 1e9 + 7
	ans, j := 1, -1
	for i, x := range nums {
		if x == 0 {
			continue
		}
		if j > -1 {
			ans = ans * (i - j) % mod
		}
		j = i
	}
	if j == -1 {
		return 0
	}
	return ans
}
```

#### TypeScript

```ts
function numberOfGoodSubarraySplits(nums: number[]): number {
    let ans = 1;
    let j = -1;
    const mod = 10 ** 9 + 7;
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        if (nums[i] === 0) {
            continue;
        }
        if (j > -1) {
            ans = (ans * (i - j)) % mod;
        }
        j = i;
    }
    return j === -1 ? 0 : ans;
}
```

#### C#

```cs
public class Solution {
    public int NumberOfGoodSubarraySplits(int[] nums) {
        long ans = 1, j = -1;
        int mod = 1000000007;
        int n = nums.Length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            if (j > -1) {
                ans = ans * (i - j) % mod;
            }
            j = i;
        }
        return j == -1 ? 0 : (int) ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2751. 机器人碰撞](https://leetcode.cn/problems/robot-collisions){#2751}

{{< tabs "2751" >}}

{{% tab "python" %}}
```python
class Solution:
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        n = len(positions)
        indices = list(range(n))
        stack = []

        indices.sort(key=lambda i: positions[i])

        for currentIndex in indices:
            if directions[currentIndex] == "R":
                stack.append(currentIndex)
            else:
                while stack and healths[currentIndex] > 0:
                    topIndex = stack.pop()

                    if healths[topIndex] > healths[currentIndex]:
                        healths[topIndex] -= 1
                        healths[currentIndex] = 0
                        stack.append(topIndex)
                    elif healths[topIndex] < healths[currentIndex]:
                        healths[currentIndex] -= 1
                        healths[topIndex] = 0
                    else:
                        healths[currentIndex] = 0
                        healths[topIndex] = 0

        result = [health for health in healths if health > 0]
        return result
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, (i, j) -> Integer.compare(positions[i], positions[j]));

        Stack<Integer> stack = new Stack<>();

        for (int currentIndex : indices) {
            if (directions.charAt(currentIndex) == 'R') {
                stack.push(currentIndex);
            } else {
                while (!stack.isEmpty() && healths[currentIndex] > 0) {
                    int topIndex = stack.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int health : healths) {
            if (health > 0) {
                result.add(health);
            }
        }

        return result;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);

        iota(indices.begin(), indices.end(), 0);
        stack<int> st;

        auto lambda = [&](int i, int j) { return positions[i] < positions[j]; };

        sort(begin(indices), end(indices), lambda);

        vector<int> result;
        for (int currentIndex : indices) {
            if (directions[currentIndex] == 'R') {
                st.push(currentIndex);
            } else {
                while (!st.empty() && healths[currentIndex] > 0) {
                    int topIndex = st.top();
                    st.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        st.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func survivedRobotsHealths(positions []int, healths []int, directions string) []int {
	n := len(positions)
	indices := make([]int, n)
	for i := range indices {
		indices[i] = i
	}

	sort.Slice(indices, func(i, j int) bool {
		return positions[indices[i]] < positions[indices[j]]
	})

	stack := []int{}

	for _, currentIndex := range indices {
		if directions[currentIndex] == 'R' {
			stack = append(stack, currentIndex)
		} else {
			for len(stack) > 0 && healths[currentIndex] > 0 {
				topIndex := stack[len(stack)-1]
				stack = stack[:len(stack)-1]

				if healths[topIndex] > healths[currentIndex] {
					healths[topIndex] -= 1
					healths[currentIndex] = 0
					stack = append(stack, topIndex)
				} else if healths[topIndex] < healths[currentIndex] {
					healths[currentIndex] -= 1
					healths[topIndex] = 0
				} else {
					healths[currentIndex] = 0
					healths[topIndex] = 0
				}
			}
		}
	}

	result := []int{}
	for _, health := range healths {
		if health > 0 {
			result = append(result, health)
		}
	}

	return result
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function survivedRobotsHealths(
    positions: number[],
    healths: number[],
    directions: string,
): number[] {
    const idx = Array.from({ length: positions.length }, (_, i) => i);
    const stk: number[] = [];

    idx.sort((a, b) => positions[a] - positions[b]);

    for (let iRight of idx) {
        while (stk.length) {
            const iLeft = stk.at(-1)!;
            const havePair = directions[iLeft] === 'R' && directions[iRight] === 'L';
            if (!havePair) break;

            if (healths[iLeft] === healths[iRight]) {
                healths[iLeft] = healths[iRight] = iRight = -1;
                stk.pop();
                break;
            }

            if (healths[iLeft] < healths[iRight]) {
                healths[iLeft] = -1;
                healths[iRight]--;
                stk.pop();
            } else {
                healths[iRight] = iRight = -1;
                healths[iLeft]--;
                break;
            }
        }

        if (iRight !== -1) stk.push(iRight);
    }

    return healths.filter(i => ~i);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} positions
 * @param {number[]} healths
 * @param {string} directions
 * @return {number[]}
 */
var survivedRobotsHealths = function (positions, healths, directions) {
    const idx = Array.from({ length: positions.length }, (_, i) => i);
    const stk = [];

    idx.sort((a, b) => positions[a] - positions[b]);

    for (let iRight of idx) {
        while (stk.length) {
            const iLeft = stk.at(-1);
            const havePair = directions[iLeft] === 'R' && directions[iRight] === 'L';
            if (!havePair) break;

            if (healths[iLeft] === healths[iRight]) {
                healths[iLeft] = healths[iRight] = iRight = -1;
                stk.pop();
                break;
            }

            if (healths[iLeft] < healths[iRight]) {
                healths[iLeft] = -1;
                healths[iRight]--;
                stk.pop();
            } else {
                healths[iRight] = iRight = -1;
                healths[iLeft]--;
                break;
            }
        }

        if (iRight !== -1) stk.push(iRight);
    }

    return healths.filter(i => ~i);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>现有 <code>n</code> 个机器人，编号从 <strong>1</strong> 开始，每个机器人包含在路线上的位置、健康度和移动方向。</p>

<p>给你下标从 <strong>0</strong> 开始的两个整数数组 <code>positions</code>、<code>healths</code> 和一个字符串 <code>directions</code>（<code>directions[i]</code> 为 <strong>'L'</strong> 表示 <strong>向左</strong> 或 <strong>'R'</strong> 表示 <strong>向右</strong>）。 <code>positions</code> 中的所有整数 <strong>互不相同</strong> 。</p>

<p>所有机器人以 <strong>相同速度</strong> <strong>同时</strong> 沿给定方向在路线上移动。如果两个机器人移动到相同位置，则会发生 <strong>碰撞</strong> 。</p>

<p>如果两个机器人发生碰撞，则将 <strong>健康度较低</strong> 的机器人从路线中 <strong>移除</strong> ，并且另一个机器人的健康度 <strong>减少 1</strong> 。幸存下来的机器人将会继续沿着与之前 <strong>相同</strong> 的方向前进。如果两个机器人的健康度相同，则将二者都从路线中移除。</p>

<p>请你确定全部碰撞后幸存下的所有机器人的 <strong>健康度</strong> ，并按照原来机器人编号的顺序排列。即机器人 1 （如果幸存）的最终健康度，机器人 2 （如果幸存）的最终健康度等。 如果不存在幸存的机器人，则返回空数组。</p>

<p>在不再发生任何碰撞后，请你以数组形式，返回所有剩余机器人的健康度（按机器人输入中的编号顺序）。</p>

<p><strong>注意：</strong>位置&nbsp; <code>positions</code> 可能是乱序的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img height="169" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2751.Robot%20Collisions/images/image-20230516011718-12.png" width="808" /></p>

<pre>
<strong>输入：</strong>positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
<strong>输出：</strong>[2,17,9,15,10]
<strong>解释：</strong>在本例中不存在碰撞，因为所有机器人向同一方向移动。所以，从第一个机器人开始依序返回健康度，[2, 17, 9, 15, 10] 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img height="176" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2751.Robot%20Collisions/images/image-20230516004433-7.png" width="717" /></p>

<pre>
<strong>输入：</strong>positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
<strong>输出：</strong>[14]
<strong>解释：</strong>本例中发生 2 次碰撞。首先，机器人 1 和机器人 2 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。接下来，机器人 3 和机器人 4 将会发生碰撞，由于机器人 4 的健康度更小，则它会被移除，而机器人 3 的健康度变为 15 - 1 = 14 。仅剩机器人 3 ，所以返回 [14] 。
</pre>

<p><strong>示例 3：</strong></p>

<p><img height="172" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2751.Robot%20Collisions/images/image-20230516005114-9.png" width="732" /></p>

<pre>
<strong>输入：</strong>positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
<strong>输出：</strong>[]
<strong>解释：</strong>机器人 1 和机器人 2 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。机器人 3 和机器人 4 将会碰撞，因为二者健康度相同，二者都将被从路线中移除。所以返回空数组 [] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= positions.length == healths.length == directions.length == n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= positions[i], healths[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>directions[i] == 'L'</code> 或 <code>directions[i] == 'R'</code></li>
	<li><code>positions</code> 中的所有值互不相同</li>
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
    def survivedRobotsHealths(
        self, positions: List[int], healths: List[int], directions: str
    ) -> List[int]:
        n = len(positions)
        indices = list(range(n))
        stack = []

        indices.sort(key=lambda i: positions[i])

        for currentIndex in indices:
            if directions[currentIndex] == "R":
                stack.append(currentIndex)
            else:
                while stack and healths[currentIndex] > 0:
                    topIndex = stack.pop()

                    if healths[topIndex] > healths[currentIndex]:
                        healths[topIndex] -= 1
                        healths[currentIndex] = 0
                        stack.append(topIndex)
                    elif healths[topIndex] < healths[currentIndex]:
                        healths[currentIndex] -= 1
                        healths[topIndex] = 0
                    else:
                        healths[currentIndex] = 0
                        healths[topIndex] = 0

        result = [health for health in healths if health > 0]
        return result

```

#### Java

```java
class Solution {
    public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
        int n = positions.length;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        Arrays.sort(indices, (i, j) -> Integer.compare(positions[i], positions[j]));

        Stack<Integer> stack = new Stack<>();

        for (int currentIndex : indices) {
            if (directions.charAt(currentIndex) == 'R') {
                stack.push(currentIndex);
            } else {
                while (!stack.isEmpty() && healths[currentIndex] > 0) {
                    int topIndex = stack.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int health : healths) {
            if (health > 0) {
                result.add(health);
            }
        }

        return result;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);

        iota(indices.begin(), indices.end(), 0);
        stack<int> st;

        auto lambda = [&](int i, int j) { return positions[i] < positions[j]; };

        sort(begin(indices), end(indices), lambda);

        vector<int> result;
        for (int currentIndex : indices) {
            if (directions[currentIndex] == 'R') {
                st.push(currentIndex);
            } else {
                while (!st.empty() && healths[currentIndex] > 0) {
                    int topIndex = st.top();
                    st.pop();

                    if (healths[topIndex] > healths[currentIndex]) {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        st.push(topIndex);
                    } else if (healths[topIndex] < healths[currentIndex]) {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    } else {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }
        return result;
    }
};
```

#### Go

```go
func survivedRobotsHealths(positions []int, healths []int, directions string) []int {
	n := len(positions)
	indices := make([]int, n)
	for i := range indices {
		indices[i] = i
	}

	sort.Slice(indices, func(i, j int) bool {
		return positions[indices[i]] < positions[indices[j]]
	})

	stack := []int{}

	for _, currentIndex := range indices {
		if directions[currentIndex] == 'R' {
			stack = append(stack, currentIndex)
		} else {
			for len(stack) > 0 && healths[currentIndex] > 0 {
				topIndex := stack[len(stack)-1]
				stack = stack[:len(stack)-1]

				if healths[topIndex] > healths[currentIndex] {
					healths[topIndex] -= 1
					healths[currentIndex] = 0
					stack = append(stack, topIndex)
				} else if healths[topIndex] < healths[currentIndex] {
					healths[currentIndex] -= 1
					healths[topIndex] = 0
				} else {
					healths[currentIndex] = 0
					healths[topIndex] = 0
				}
			}
		}
	}

	result := []int{}
	for _, health := range healths {
		if health > 0 {
			result = append(result, health)
		}
	}

	return result
}
```

#### TypeScript

```ts
function survivedRobotsHealths(
    positions: number[],
    healths: number[],
    directions: string,
): number[] {
    const idx = Array.from({ length: positions.length }, (_, i) => i);
    const stk: number[] = [];

    idx.sort((a, b) => positions[a] - positions[b]);

    for (let iRight of idx) {
        while (stk.length) {
            const iLeft = stk.at(-1)!;
            const havePair = directions[iLeft] === 'R' && directions[iRight] === 'L';
            if (!havePair) break;

            if (healths[iLeft] === healths[iRight]) {
                healths[iLeft] = healths[iRight] = iRight = -1;
                stk.pop();
                break;
            }

            if (healths[iLeft] < healths[iRight]) {
                healths[iLeft] = -1;
                healths[iRight]--;
                stk.pop();
            } else {
                healths[iRight] = iRight = -1;
                healths[iLeft]--;
                break;
            }
        }

        if (iRight !== -1) stk.push(iRight);
    }

    return healths.filter(i => ~i);
}
```

#### JavaScript

```js
/**
 * @param {number[]} positions
 * @param {number[]} healths
 * @param {string} directions
 * @return {number[]}
 */
var survivedRobotsHealths = function (positions, healths, directions) {
    const idx = Array.from({ length: positions.length }, (_, i) => i);
    const stk = [];

    idx.sort((a, b) => positions[a] - positions[b]);

    for (let iRight of idx) {
        while (stk.length) {
            const iLeft = stk.at(-1);
            const havePair = directions[iLeft] === 'R' && directions[iRight] === 'L';
            if (!havePair) break;

            if (healths[iLeft] === healths[iRight]) {
                healths[iLeft] = healths[iRight] = iRight = -1;
                stk.pop();
                break;
            }

            if (healths[iLeft] < healths[iRight]) {
                healths[iLeft] = -1;
                healths[iRight]--;
                stk.pop();
            } else {
                healths[iRight] = iRight = -1;
                healths[iLeft]--;
                break;
            }
        }

        if (iRight !== -1) stk.push(iRight);
    }

    return healths.filter(i => ~i);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2752. 在连续天数上进行了最多交易次数的顾客 🔒](https://leetcode.cn/problems/customers-with-maximum-number-of-transactions-on-consecutive-days){#2752}

{{< tabs "2752" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    s AS (
        SELECT
            customer_id,
            DATE_SUB(
                transaction_date,
                INTERVAL ROW_NUMBER() OVER (
                    PARTITION BY customer_id
                    ORDER BY transaction_date
                ) DAY
            ) AS transaction_date
        FROM Transactions
    ),
    t AS (
        SELECT customer_id, transaction_date, COUNT(1) AS cnt
        FROM s
        GROUP BY 1, 2
    )
SELECT customer_id
FROM t
WHERE cnt = (SELECT MAX(cnt) FROM t)
ORDER BY customer_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Transactions</code></p>

<pre>
+------------------+------+
| 列名             | 类型 |
+------------------+------+
| transaction_id   | int  |
| customer_id      | int  |
| transaction_date | date |
| amount           | int  |
+------------------+------+
transaction_id 是这个表的具有唯一值的列。 
每行包含有关交易的信息，包括唯一的（customer_id，transaction_date）以及相应的 customer_id 和 amount。
</pre>

<p>编写一个解决方案，找到连续天数上进行了最多交易的所有 <code>customer_id</code> 。</p>

<p>返回所有具有最大连续交易次数的 <code>customer_id</code> 。结果表按 <code>customer_id</code> 的 <strong>升序</strong> 排序。</p>

<p>结果的格式如下所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
Transactions 表:
+----------------+-------------+------------------+--------+
| transaction_id | customer_id | transaction_date | amount |
+----------------+-------------+------------------+--------+
| 1              | 101         | 2023-05-01       | 100    |
| 2              | 101         | 2023-05-02       | 150    |
| 3              | 101         | 2023-05-03       | 200    |
| 4              | 102         | 2023-05-01       | 50     |
| 5              | 102         | 2023-05-03       | 100    |
| 6              | 102         | 2023-05-04       | 200    |
| 7              | 105         | 2023-05-01       | 100    |
| 8              | 105         | 2023-05-02       | 150    |
| 9              | 105         | 2023-05-03       | 200    |
+----------------+-------------+------------------+--------+
<b>输出：</b>
+-------------+
| customer_id | 
+-------------+
| 101         | 
| 105         | 
+-------------+
<b>解释：</b>
- customer_id 为 101 共有 3 次交易，且全部是连续的。
- customer_id 为 102 共有 3 次交易，但只有其中 2 次是连续的。
- customer_id 为 105 共有 3 次交易，且全部是连续的。 
总的来说，最大连续交易次数为 3，由 customer_id 为 101 和 105 的完成。customer_id 按升序排序。</pre>

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
# Write your MySQL query statement below
WITH
    s AS (
        SELECT
            customer_id,
            DATE_SUB(
                transaction_date,
                INTERVAL ROW_NUMBER() OVER (
                    PARTITION BY customer_id
                    ORDER BY transaction_date
                ) DAY
            ) AS transaction_date
        FROM Transactions
    ),
    t AS (
        SELECT customer_id, transaction_date, COUNT(1) AS cnt
        FROM s
        GROUP BY 1, 2
    )
SELECT customer_id
FROM t
WHERE cnt = (SELECT MAX(cnt) FROM t)
ORDER BY customer_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2753. 计算一个环形街道上的房屋数量 II 🔒](https://leetcode.cn/problems/count-houses-in-a-circular-street-ii){#2753}

{{< tabs "2753" >}}

{{% tab "python" %}}
```python
# Definition for a street.
# class Street:
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
class Solution:
    def houseCount(self, street: Optional["Street"], k: int) -> int:
        while not street.isDoorOpen():
            street.moveRight()
        for i in range(1, k + 1):
            street.moveRight()
            if street.isDoorOpen():
                ans = i
                street.closeDoor()
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a street.
 * class Street {
 *     public Street(int[] doors);
 *     public void closeDoor();
 *     public boolean isDoorOpen();
 *     public void moveRight();
 * }
 */
class Solution {
    public int houseCount(Street street, int k) {
        while (!street.isDoorOpen()) {
            street.moveRight();
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            street.moveRight();
            if (street.isDoorOpen()) {
                ans = i;
                street.closeDoor();
            }
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        while (!street->isDoorOpen()) {
            street->moveRight();
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            street->moveRight();
            if (street->isDoorOpen()) {
                ans = i;
                street->closeDoor();
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a street.
 * type Street interface {
 *     CloseDoor()
 *     IsDoorOpen() bool
 *     MoveRight()
 * }
 */
func houseCount(street Street, k int) (ans int) {
	for !street.IsDoorOpen() {
		street.MoveRight()
	}
	for i := 1; i <= k; i++ {
		street.MoveRight()
		if street.IsDoorOpen() {
			ans = i
			street.CloseDoor()
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a street.
 * class Street {
 *     constructor(doors: number[]);
 *     public closeDoor(): void;
 *     public isDoorOpen(): boolean;
 *     public moveRight(): void;
 * }
 */
function houseCount(street: Street | null, k: number): number {
    while (!street.isDoorOpen()) {
        street.moveRight();
    }
    let ans = 0;
    for (let i = 1; i <= k; ++i) {
        street.moveRight();
        if (street.isDoorOpen()) {
            ans = i;
            street.closeDoor();
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

<p>给定一个代表&nbsp;<strong>环形&nbsp;</strong>街道的类&nbsp;<code>Street</code>&nbsp;的对象&nbsp;<code>street</code> 和一个正整数&nbsp;<code>k</code>，表示街道上房屋的最大数量（也就是说房屋数量不超过&nbsp;<code>k</code>）。每个房屋的门初始时可以是开着的也可以是关着的（至少有一个房屋的门是开着的）。</p>

<p>刚开始，你站在一座房子的门前。你的任务是计算街道上的房屋数量。</p>

<p><code>Street</code>&nbsp;类包含以下函数：</p>

<ul>
	<li><code>void closeDoor()</code>：关闭当前房屋的门。</li>
	<li><code>boolean isDoorOpen()</code>：如果当前房屋的门是开着的返回&nbsp;<code>true</code>，否则返回&nbsp;<code>false</code>。</li>
	<li><code>void moveRight()</code>：向右移动到下一座房屋。</li>
</ul>

<p><strong>注意：</strong>在<strong>&nbsp;环形&nbsp;</strong>街道内，如果将房屋从&nbsp;<code>1</code>&nbsp;到&nbsp;<code>n</code>&nbsp;编号，则当&nbsp;<code>i &lt; n</code>&nbsp;时&nbsp;<code>house<sub>i</sub></code>&nbsp;右边的房子是&nbsp;<code>house<sub>i+1</sub></code>，<code>house<sub>n</sub></code>&nbsp;右边的房子是&nbsp;<code>house<sub>1</sub></code>。</p>

<p>返回&nbsp;<code>ans</code>，它表示街道上的房屋数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>street = [1,1,1,1], k = 10
<b>输出：</b>4
<b>解释：</b>街道上有 4 座房屋，它们的门都是开着的。
房屋数量小于 k，即 10。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>street = [1,0,1,1,0], k = 5
<b>输出：</b>5
<strong>解释：</strong>街道上有 5 座房屋，向右移动时第 1、3 和 4 座房屋的门是开着的，其余的门都是关着的。
房屋数量等于 k，即 5。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n</code>&nbsp;是房屋数量</li>
	<li><code>1 &lt;= n &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>street</code>&nbsp;是环形的</li>
	<li>输入数据中至少有一扇门是开着的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：脑筋急转弯

我们注意到，题目中至少有一扇门是开着的，我们可以先找到其中一扇开着的门。

然后，我们跳过这扇开着的门，往右移动，每次移动时，计数器加一，如果遇到开着的门，就把门关上。那么答案就是最后一次遇到的开着的门时的计数器的值。

时间复杂度 $O(k)$，空间复杂度 $O(1)$。

相似题目：

-   [2728. 计算一个环形街道上的房屋数量](https://github.com/doocs/leetcode/blob/main/solution/2700-2799/2728.Count%20Houses%20in%20a%20Circular%20Street/README.md)

<!-- tabs:start -->

#### Python3

```python
# Definition for a street.
# class Street:
#     def closeDoor(self):
#         pass
#     def isDoorOpen(self):
#         pass
#     def moveRight(self):
#         pass
class Solution:
    def houseCount(self, street: Optional["Street"], k: int) -> int:
        while not street.isDoorOpen():
            street.moveRight()
        for i in range(1, k + 1):
            street.moveRight()
            if street.isDoorOpen():
                ans = i
                street.closeDoor()
        return ans
```

#### Java

```java
/**
 * Definition for a street.
 * class Street {
 *     public Street(int[] doors);
 *     public void closeDoor();
 *     public boolean isDoorOpen();
 *     public void moveRight();
 * }
 */
class Solution {
    public int houseCount(Street street, int k) {
        while (!street.isDoorOpen()) {
            street.moveRight();
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            street.moveRight();
            if (street.isDoorOpen()) {
                ans = i;
                street.closeDoor();
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
public:
    int houseCount(Street* street, int k) {
        while (!street->isDoorOpen()) {
            street->moveRight();
        }
        int ans = 0;
        for (int i = 1; i <= k; ++i) {
            street->moveRight();
            if (street->isDoorOpen()) {
                ans = i;
                street->closeDoor();
            }
        }
        return ans;
    }
};
```

#### Go

```go
/**
 * Definition for a street.
 * type Street interface {
 *     CloseDoor()
 *     IsDoorOpen() bool
 *     MoveRight()
 * }
 */
func houseCount(street Street, k int) (ans int) {
	for !street.IsDoorOpen() {
		street.MoveRight()
	}
	for i := 1; i <= k; i++ {
		street.MoveRight()
		if street.IsDoorOpen() {
			ans = i
			street.CloseDoor()
		}
	}
	return
}
```

#### TypeScript

```ts
/**
 * Definition for a street.
 * class Street {
 *     constructor(doors: number[]);
 *     public closeDoor(): void;
 *     public isDoorOpen(): boolean;
 *     public moveRight(): void;
 * }
 */
function houseCount(street: Street | null, k: number): number {
    while (!street.isDoorOpen()) {
        street.moveRight();
    }
    let ans = 0;
    for (let i = 1; i <= k; ++i) {
        street.moveRight();
        if (street.isDoorOpen()) {
            ans = i;
            street.closeDoor();
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

# [2754. 将函数绑定到上下文 🔒](https://leetcode.cn/problems/bind-function-to-context){#2754}

{{< tabs "2754" >}}

{{% tab "ts" %}}
```ts
type Fn = (...args) => any;

declare global {
    interface Function {
        bindPolyfill(obj: Record<any, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function (obj) {
    return (...args) => {
        return this.call(obj, ...args);
    };
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>编写一个所有函数都支持的方法&nbsp;<code>bindPolyfill</code> 。当 <code>bindPolyfill</code> 方法被调用并传递了一个对象 <code>obj</code> 时，该对象将成为函数的 <code>this</code> 上下文。</p>

<p>例如，如果你有以下代码：</p>

<pre>
function f() {
  console.log('My context is ' + this.ctx);
}
f();
</pre>

<p>&nbsp;它的输出是 <code>"My context is undefined"</code> 。然而，如果你绑定了该函数：</p>

<pre>
function f() {
  console.log('My context is ' + this.ctx);
}
const boundFunc = f.boundPolyfill({ "ctx": "My Object" })
boundFunc();
</pre>

<p>它的输出应为 <code>"My context is My Object"</code> 。</p>

<p>你可以假设传递给 <code>bindPolyfill</code> 方法的是一个非空对象。</p>

<p>请在不使用内置的 <code>Function.bind</code> 方法的情况下解决该问题。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>
fn = function f(multiplier) { 
&nbsp; return this.x * multiplier; 
}
obj = {"x": 10}
inputs = [5]
<b>输出：</b>50
<strong>解释：</strong>
const boundFunc = f.bindPolyfill({"x": 10});
boundFunc(5); // 50
传递了一个乘数 5 作为参数。 
上下文设置为 <code>{"x": 10}</code>。 
将这两个数字相乘得到 50。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>
fn = function speak() { 
&nbsp; return "My name is " + this.name; 
}
obj = {"name": "Kathy"}
inputs = []
<b>输出：</b>"My name is Kathy"
<strong>解释：</strong>
const boundFunc = f.bindPolyfill({"name": "Kathy"});
boundFunc(); // "My name is Kathy"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>obj</code> 是一个非空对象</li>
	<li><code>0 &lt;= inputs.length &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<b>你能在不使用任何内置方法的情况下解决这个问题吗？</b>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### TypeScript

```ts
type Fn = (...args) => any;

declare global {
    interface Function {
        bindPolyfill(obj: Record<any, any>): Fn;
    }
}

Function.prototype.bindPolyfill = function (obj) {
    return (...args) => {
        return this.call(obj, ...args);
    };
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2755. 深度合并两个对象 🔒](https://leetcode.cn/problems/deep-merge-of-two-objects){#2755}

{{< tabs "2755" >}}

{{% tab "ts" %}}
```ts
function deepMerge(obj1: any, obj2: any): any {
    const isObj = (obj: any) => obj && typeof obj === 'object';
    const isArr = (obj: any) => Array.isArray(obj);
    if (!isObj(obj1) || !isObj(obj2)) {
        return obj2;
    }
    if (isArr(obj1) !== isArr(obj2)) {
        return obj2;
    }
    for (const key in obj2) {
        obj1[key] = deepMerge(obj1[key], obj2[key]);
    }
    return obj1;
}

/**
 * let obj1 = {"a": 1, "c": 3}, obj2 = {"a": 2, "b": 2};
 * deepMerge(obj1, obj2); // {"a": 2, "c": 3, "b": 2}
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个值 <code>obj1</code> 和 <code>obj2</code>，返回一个 <strong>深度合并</strong> 的值。</p>

<p>你应该遵循以下规则进行值的 <strong>深度合并</strong>：</p>

<ul>
	<li>如果两个值都是对象，则结果对象应包含两个对象上存在的所有键。</li>
	<li>如果一个键同时存在于两个对象中，则 <strong>深度合并</strong> 两个关联的值。否则，将键值对添加到结果对象中。</li>
	<li>如果两个值都是数组，则结果数组的长度应与较长的数组相同。对于对象的合并逻辑，将索引视为键。</li>
	<li>否则，结果值为 <code>obj2</code>。</li>
</ul>

<p>你可以假设 <code>obj1</code> 和 <code>obj2</code> 是 <code>JSON.parse()</code> 的输出结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>obj1 = {"a": 1, "c": 3}, obj2 = {"a": 2, "b": 2}
<b>输出：</b>{"a": 2, "c": 3, "b": 2}
<b>解释：</b><code>obj1["a"]</code> 的值变为 2，因为如果两个对象具有相同的键且它们的值不是数组或对象，则将 <code>obj1</code> 的值更改为 <code>obj2</code> 的值。键 "b" 和其值被添加到 <code>obj1</code> 中，因为它在 <code>obj1</code> 中不存在。 
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>obj1 = [{}, 2, 3], obj2 = [[], 5]
<b>输出：</b>[[], 5, 3]
<b>解释：</b><code>result[0] = obj2[0]</code>，因为 <code>obj1[0]</code> 和 <code>obj2[0]</code> 类型不同。<code>result[2] = obj1[2]</code>，因为 <code>obj2[2]</code> 不存在。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>
obj1 = {"a": 1, "b": {"c": [1 , [2, 7], 5], "d": 2}}, 
obj2 = {"a": 1, "b": {"c": [6, [6], [9]], "e": 3}}
<b>输出：</b>{"a": 1, "b": {"c": [6, [6, 7], [9]], "d": 2, "e": 3}}
<b>解释：</b>
数组 <code>obj1["b"]["c"]</code> 和 <code>obj2["b"]["c"]</code> 已合并，如果 <code>obj2</code> 的值不是数组或对象，则深度覆盖 <code>obj1</code> 的值。 <code>obj2["b"]["c"]</code> 有键 "e"，而 <code>obj1</code> 中没有，所以将其添加到 <code>obj1</code> 中。
</pre>

<p><strong class="example">示例 4：</strong></p>

<pre>
<b>输入：</b>obj1 = true, obj2 = null
<b>输出：</b>null
</pre>

<p>&nbsp;</p>

<p><strong>解释：</strong></p>

<ul>
	<li><code>obj1</code> 和 <code>obj2</code> 都是有效的 JSON 值</li>
	<li><code>1 &lt;= JSON.stringify(obj1).length &lt;= 5&nbsp;* 10<sup>5</sup></code></li>
	<li><code>1 &lt;= JSON.stringify(obj2).length &lt;= 5&nbsp;* 10<sup>5</sup></code></li>
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

#### TypeScript

```ts
function deepMerge(obj1: any, obj2: any): any {
    const isObj = (obj: any) => obj && typeof obj === 'object';
    const isArr = (obj: any) => Array.isArray(obj);
    if (!isObj(obj1) || !isObj(obj2)) {
        return obj2;
    }
    if (isArr(obj1) !== isArr(obj2)) {
        return obj2;
    }
    for (const key in obj2) {
        obj1[key] = deepMerge(obj1[key], obj2[key]);
    }
    return obj1;
}

/**
 * let obj1 = {"a": 1, "c": 3}, obj2 = {"a": 2, "b": 2};
 * deepMerge(obj1, obj2); // {"a": 2, "c": 3, "b": 2}
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2756. 批处理查询 🔒](https://leetcode.cn/problems/query-batching){#2756}

{{< tabs "2756" >}}

{{% tab "ts" %}}
```ts

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>将多个小查询批处理为单个大查询可以是一种有用的优化。请编写一个名为&nbsp;<code>QueryBatcher</code>&nbsp;的类来实现这个功能。</p>

<p>它的构造函数应接受两个参数：</p>

<ul>
	<li>一个异步函数&nbsp;<code>queryMultiple</code>&nbsp;，它接受一个字符串键的数组作为输入。它将返回一个与输入数组长度相同的值数组。每个索引对应于与&nbsp;<code>input[i]</code>&nbsp;相关联的值。可以假设该异步函数永远不会被拒绝。</li>
	<li>一个以毫秒为单位的节流时间<code>t</code>。</li>
</ul>

<p>该类有一个方法：</p>

<ul>
	<li><code>async getValue(key)</code>：接受一个字符串键，并返回一个解析后的字符串值。传递给此函数的键值最终应传递给&nbsp;<code>queryMultiple</code>&nbsp;函数。在&nbsp;<code>t</code>&nbsp;毫秒内不应连续调用&nbsp;<code>queryMultiple</code>&nbsp;。第一次调用&nbsp;<code>getValue</code>&nbsp;时，应立即使用该单个键调用&nbsp;<code>queryMultiple</code>&nbsp;。如果在&nbsp;<code>t</code>&nbsp;毫秒后再次调用了&nbsp;<code>getValue</code>&nbsp;，则所有传递的键应传递给&nbsp;<code>queryMultiple</code>&nbsp;，并返回最终结果。可以假设传递给该方法的每个键都是唯一的。</li>
</ul>

<p>下图说明了节流算法的工作原理。每个矩形代表 100毫秒。节流时间为 400毫秒。</p>

<p><img alt="Throttle info" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2700-2799/2756.Query%20Batching/images/throttle.png" style="width: 622px; height: 200px;" /></p>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>
queryMultiple = async function(keys) { 
&nbsp; return keys.map(key =&gt; key + '!');
}
t = 100 
calls = [
&nbsp;{"key": "a", "time": 10}, 
&nbsp;{"key": "b", "time": 20}, 
&nbsp;{"key": "c", "time": 30}
]
<b>输出：</b>[
&nbsp;{"resolved": "a!", "time": 10},
&nbsp;{"resolved": "b!", "time": 110},
&nbsp;{"resolved": "c!", "time": 110}
]
<strong>解释：</strong>
const batcher = new QueryBatcher(queryMultiple, 100);
setTimeout(() =&gt; batcher.getValue('a'), 10); // "a!" at t=10ms
setTimeout(() =&gt; batcher.getValue('b'), 20); // "b!" at t=110ms
setTimeout(() =&gt; batcher.getValue('c'), 30); // "c!" at t=110ms

<code>queryMultiple </code>简单地给键添加了"!"。 
在 t=10ms 时，调用 <code>getValue('a')</code>，立即调用 <code>queryMultiple(['a']) </code>并立即返回结果。 
在 t=20ms 时，调用 <code>getValue('b')</code>，但查询需要等待。 
在 t=30ms 时，调用 <code>getValue('c')</code>，但查询需要等待。 
在 t=110ms 时，调用 <code>queryMultiple(['b', 'c']) </code>并立即返回结果。
</pre>

<p><strong class="example">示例 2；</strong></p>

<pre>
<b>输入：</b>
queryMultiple = async function(keys) {
&nbsp; await new Promise(res =&gt; setTimeout(res, 100));
&nbsp; return keys.map(key =&gt; key + '!');
}
t = 100
calls = [
&nbsp;{"key": "a", "time": 10},
&nbsp;{"key": "b", "time": 20},
&nbsp;{"key": "c", "time": 30}
]
<b>输出：</b>[
&nbsp; {"resolved": "a!", "time": 110},
&nbsp; {"resolved": "b!", "time": 210},
&nbsp; {"resolved": "c!", "time": 210}
]
<strong>解释：</strong>
这个例子与示例 1 相同，只是在 <code>queryMultiple </code>中有一个 100ms 的延迟。结果也相同，只是 promise 的解析时间延迟了 100ms。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>
queryMultiple = async function(keys) { 
&nbsp; await new Promise(res =&gt; setTimeout(res, keys.length * 100)); 
&nbsp; return keys.map(key =&gt; key + '!');
}
t = 100
calls = [
&nbsp; {"key": "a", "time": 10}, 
  {"key": "b", "time": 20}, 
&nbsp; {"key": "c", "time": 30}, 
  {"key": "d", "time": 40}, 
&nbsp; {"key": "e", "time": 250}
&nbsp; {"key": "f", "time": 300}
]
<b>输出：</b>[
&nbsp; {"resolved":"a!","time":110},
&nbsp; {"resolved":"e!","time":350},
&nbsp; {"resolved":"b!","time":410},
&nbsp; {"resolved":"c!","time":410},
&nbsp; {"resolved":"d!","time":410},
  {"resolved":"f!","time":450}
]
<strong>解释：
</strong>在 t=10ms 时，调用 <code>queryMultiple(['a']) </code>，在 t=110ms 时解析。 
在 t=110ms 时，调用 <code>queryMultiple(['b', 'c', 'd']) </code>，在 t=410ms 时解析。 
在 t=250ms 时，调用 <code>queryMultiple(['e']) </code>，在 t=350ms 时解析。 
在 t=350ms 时，调用 <code>queryMultiple(['f']) </code>，在 t=450ms 时解析。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= t &lt;= 1000</code></li>
	<li><code>0 &lt;= calls.length &lt;= 10</code></li>
	<li><code>1 &lt;= key.length&nbsp;&lt;= 100</code></li>
	<li>所有的键值都是唯一的</li>
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

#### TypeScript

```ts

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2757. 生成循环数组的值 🔒](https://leetcode.cn/problems/generate-circular-array-values){#2757}

{{< tabs "2757" >}}

{{% tab "ts" %}}
```ts
function* cycleGenerator(arr: number[], startIndex: number): Generator<number, void, number> {
    const n = arr.length;
    while (true) {
        const jump = yield arr[startIndex];
        startIndex = (((startIndex + jump) % n) + n) % n;
    }
}
/**
 *  const gen = cycleGenerator([1,2,3,4,5], 0);
 *  gen.next().value  // 1
 *  gen.next(1).value // 2
 *  gen.next(2).value // 4
 *  gen.next(6).value // 5
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定你一个 <strong>循环</strong> 数组 <code>arr</code> 和一个整数 <code>startIndex</code> ，返回一个生成器对象 <code>gen</code>&nbsp;，它从 <code>arr</code> 中生成值。第一次调用 <code>gen.next()</code> 时，它应该生成 <code>arr[startIndex]</code> 。每次调用 <code>gen.next()</code> 时，都会传入一个整数参数&nbsp;<code>jump</code>（例如：<code>gen.next(-3)</code> ）。</p>

<ul>
	<li>如果 <code>jump</code> 是正数，则索引应该增加该值，但如果当前索引是最后一个索引，则应跳转到第一个索引。</li>
	<li>如果 <code>jump</code> 是负数，则索引应减去该值的绝对值，但如果当前索引是第一个索引，则应跳转到最后一个索引。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>arr = [1,2,3,4,5], steps = [1,2,6], startIndex = 0
<b>输出：</b>[1,2,4,5]
<strong>解释：</strong> &nbsp;
&nbsp;const gen = cycleGenerator(arr, startIndex);
&nbsp;gen.next().value; &nbsp;// 1, index = startIndex = 0
&nbsp;gen.next(1).value; // 2, index = 1, 0 -&gt; 1
&nbsp;gen.next(2).value; // 4, index = 3, 1 -&gt; 2 -&gt; 3
&nbsp;gen.next(6).value; // 5, index = 4, 3 -&gt; 4 -&gt; 0 -&gt; 1 -&gt; 2 -&gt; 3 -&gt; 4
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>arr = [10,11,12,13,14,15], steps = [1,4,0,-1,-3], startIndex = 1
<b>输出：</b>[11,12,10,10,15,12]
<b>解释：</b>
&nbsp;const gen = cycleGenerator(arr, startIndex);
&nbsp;gen.next().value; &nbsp; // 11, index = 1
&nbsp;gen.next(1).value;  // 12, index = 2
&nbsp;gen.next(4).value;  // 10, index = 0
&nbsp;gen.next(0).value;  // 10, index = 0
&nbsp;gen.next(-1).value; // 15, index = 5
&nbsp;gen.next(-3).value; // 12, index = 2
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>arr = [2,4,6,7,8,10], steps = [-4,5,-3,10], startIndex = 3
<b>输出：</b>[7,10,8,4,10]
<b>解释：</b>
&nbsp;const gen = cycleGenerator(arr, startIndex);
&nbsp;gen.next().value &nbsp; // 7,  index = 3
&nbsp;gen.next(-4).value // 10, index = 5
&nbsp;gen.next(5).value  // 8,  index = 4
&nbsp;gen.next(-3).value // 4,  index = 1 &nbsp;
&nbsp;gen.next(10).value // 10, index = 5
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= steps.length &lt;= 100</code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= steps[i],&nbsp;arr[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= startIndex &lt;&nbsp;arr.length</code></li>
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

#### TypeScript

```ts
function* cycleGenerator(arr: number[], startIndex: number): Generator<number, void, number> {
    const n = arr.length;
    while (true) {
        const jump = yield arr[startIndex];
        startIndex = (((startIndex + jump) % n) + n) % n;
    }
}
/**
 *  const gen = cycleGenerator([1,2,3,4,5], 0);
 *  gen.next().value  // 1
 *  gen.next(1).value // 2
 *  gen.next(2).value // 4
 *  gen.next(6).value // 5
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2758. 下一天 🔒](https://leetcode.cn/problems/next-day){#2758}

{{< tabs "2758" >}}

{{% tab "ts" %}}
```ts
declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function () {
    const date = new Date(this.valueOf());
    date.setDate(date.getDate() + 1);
    return date.toISOString().slice(0, 10);
};

/**
 * const date = new Date("2014-06-20");
 * date.nextDay(); // "2014-06-21"
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>请你编写一个有关日期对象的方法，使得任何日期对象都可以调用 <code>date.nextDay()</code> 方法，然后返回调用日期对象的下一天，格式为 YYYY-MM-DD 。</p>

<p>&nbsp;</p>

<p><b>示例 1：</b></p>

<pre>
<b>输入：</b>date = "2014-06-20"
<b>输出：</b>"2014-06-21"
<b>解释：</b>
const date = new Date("2014-06-20");
date.nextDay(); // "2014-06-21"
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>date = "2017-10-31"
<strong>输出：</strong>"2017-11-01"
<b>解释：</b>日期 2017-10-31 的下一天是 2017-11-01.
</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>

<ul>
	<li><code>new Date(date)</code> 是一个有效的日期对象</li>
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

#### TypeScript

```ts
declare global {
    interface Date {
        nextDay(): string;
    }
}

Date.prototype.nextDay = function () {
    const date = new Date(this.valueOf());
    date.setDate(date.getDate() + 1);
    return date.toISOString().slice(0, 10);
};

/**
 * const date = new Date("2014-06-20");
 * date.nextDay(); // "2014-06-21"
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2759. 将 JSON 字符串转换为对象 🔒](https://leetcode.cn/problems/convert-json-string-to-object){#2759}

{{< tabs "2759" >}}

{{% tab "ts" %}}
```ts
function jsonParse(str: string): any {
    const n = str.length;
    let i = 0;

    const parseTrue = (): boolean => {
        i += 4;
        return true;
    };

    const parseFalse = (): boolean => {
        i += 5;
        return false;
    };

    const parseNull = (): null => {
        i += 4;
        return null;
    };

    const parseNumber = (): number => {
        let s = '';
        while (i < n) {
            const c = str[i];
            if (c === ',' || c === '}' || c === ']') {
                break;
            }
            s += c;
            i++;
        }
        return Number(s);
    };

    const parseArray = (): any[] => {
        const arr: any[] = [];
        i++;
        while (i < n) {
            const c = str[i];
            if (c === ']') {
                i++;
                break;
            }
            if (c === ',') {
                i++;
                continue;
            }
            const value = parseValue();
            arr.push(value);
        }
        return arr;
    };

    const parseString = (): string => {
        let s = '';
        i++;
        while (i < n) {
            const c = str[i];
            if (c === '"') {
                i++;
                break;
            }
            if (c === '\\') {
                i++;
                s += str[i];
            } else {
                s += c;
            }
            i++;
        }
        return s;
    };

    const parseObject = (): any => {
        const obj: any = {};
        i++;
        while (i < n) {
            const c = str[i];
            if (c === '}') {
                i++;
                break;
            }
            if (c === ',') {
                i++;
                continue;
            }
            const key = parseString();
            i++;
            const value = parseValue();
            obj[key] = value;
        }
        return obj;
    };
    const parseValue = (): any => {
        const c = str[i];
        if (c === '{') {
            return parseObject();
        }
        if (c === '[') {
            return parseArray();
        }
        if (c === '"') {
            return parseString();
        }
        if (c === 't') {
            return parseTrue();
        }
        if (c === 'f') {
            return parseFalse();
        }
        if (c === 'n') {
            return parseNull();
        }
        return parseNumber();
    };
    return parseValue();
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串 <code>str</code> ，返回 JSON 解析后的 <code>parsedStr</code> 。你可以假设 <code>str</code> 是一个有效的 JSON 字符串，因此它只包含字符串、数字、数组、对象、布尔值和 null。<code>str</code> 不会包含不可见字符和转义字符。</p>

<p>请在不使用内置的 <code>JSON.parse</code> 方法的情况下解决此问题。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>str = '{"a":2,"b":[1,2,3]}'
<b>输出：</b>{"a":2,"b":[1,2,3]}
<b>解释：</b>返回由 JSON 字符串表示的对象。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>str = 'true'
<b>输出：</b>true
<b>解释：</b>原始类型是有效的 JSON。</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<b>输入：</b>str = '[1,5,"false",{"a":2}]'
<b>输出：</b>[1,5,"false",{"a":2}]
<b>解释：</b>返回由 JSON 字符串表示的数组。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>str</code> 是一个有效的 JSON 字符串</li>
	<li><code>1 &lt;= str.length &lt;= 10<sup>5</sup></code></li>
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

#### TypeScript

```ts
function jsonParse(str: string): any {
    const n = str.length;
    let i = 0;

    const parseTrue = (): boolean => {
        i += 4;
        return true;
    };

    const parseFalse = (): boolean => {
        i += 5;
        return false;
    };

    const parseNull = (): null => {
        i += 4;
        return null;
    };

    const parseNumber = (): number => {
        let s = '';
        while (i < n) {
            const c = str[i];
            if (c === ',' || c === '}' || c === ']') {
                break;
            }
            s += c;
            i++;
        }
        return Number(s);
    };

    const parseArray = (): any[] => {
        const arr: any[] = [];
        i++;
        while (i < n) {
            const c = str[i];
            if (c === ']') {
                i++;
                break;
            }
            if (c === ',') {
                i++;
                continue;
            }
            const value = parseValue();
            arr.push(value);
        }
        return arr;
    };

    const parseString = (): string => {
        let s = '';
        i++;
        while (i < n) {
            const c = str[i];
            if (c === '"') {
                i++;
                break;
            }
            if (c === '\\') {
                i++;
                s += str[i];
            } else {
                s += c;
            }
            i++;
        }
        return s;
    };

    const parseObject = (): any => {
        const obj: any = {};
        i++;
        while (i < n) {
            const c = str[i];
            if (c === '}') {
                i++;
                break;
            }
            if (c === ',') {
                i++;
                continue;
            }
            const key = parseString();
            i++;
            const value = parseValue();
            obj[key] = value;
        }
        return obj;
    };
    const parseValue = (): any => {
        const c = str[i];
        if (c === '{') {
            return parseObject();
        }
        if (c === '[') {
            return parseArray();
        }
        if (c === '"') {
            return parseString();
        }
        if (c === 't') {
            return parseTrue();
        }
        if (c === 'f') {
            return parseFalse();
        }
        if (c === 'n') {
            return parseNull();
        }
        return parseNumber();
    };
    return parseValue();
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
