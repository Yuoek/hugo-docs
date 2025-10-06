---
title: "3168_MinimumNumberofChairsinaWaitingRoom"
date: 2025-10-06T00:42:37+08:00
weight: 3168
tags: [字符串, 模拟]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [3168. 候诊室中的最少椅子数](https://leetcode.cn/problems/minimum-number-of-chairs-in-a-waiting-room)

[English Version](../en/3168-68/3168_MinimumNumberofChairsinaWaitingRoom)

## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code>，模拟每秒钟的事件 <code>i</code>：</p>

<ul>
	<li>如果 <code>s[i] == 'E'</code>，表示有一位顾客进入候诊室并占用一把椅子。</li>
	<li>如果 <code>s[i] == 'L'</code>，表示有一位顾客离开候诊室，从而释放一把椅子。</li>
</ul>

<p>返回保证每位进入候诊室的顾客都能有椅子坐的<strong> 最少 </strong>椅子数，假设候诊室最初是 <strong>空的 </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "EEEEEEE"</span></p>

<p><strong>输出：</strong><span class="example-io">7</span></p>

<p><strong>解释：</strong></p>

<p>每秒后都有一个顾客进入候诊室，没有人离开。因此，至少需要 7 把椅子。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "ELELEEL"</span></p>

<p><strong>输出：</strong><span class="example-io">2</span></p>

<p><strong>解释：</strong></p>

<p>假设候诊室里有 2 把椅子。下表显示了每秒钟等候室的状态。</p>
</div>
<table>
	<tbody>
		<tr>
			<th>秒</th>
			<th>事件</th>
			<th>候诊室的人数</th>
			<th>可用的椅子数</th>
		</tr>
		<tr>
			<td>0</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Leave</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Leave</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>5</td>
			<td>Enter</td>
			<td>2</td>
			<td>0</td>
		</tr>
		<tr>
			<td>6</td>
			<td>Leave</td>
			<td>1</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">s = "ELEELEELLL"</span></p>

<p><strong>输出：</strong><span class="example-io">3</span></p>

<p><strong>解释：</strong></p>

<p>假设候诊室里有 3 把椅子。下表显示了每秒钟等候室的状态。</p>
</div>
<table>
	<tbody>
		<tr>
			<th>秒</th>
			<th>事件</th>
			<th>候诊室的人数</th>
			<th>可用的椅子数</th>
		</tr>
		<tr>
			<td>0</td>
			<td>Enter</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Leave</td>
			<td>0</td>
			<td>3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Enter</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Enter</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Leave</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>5</td>
			<td>Enter</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>6</td>
			<td>Enter</td>
			<td>3</td>
			<td>0</td>
		</tr>
		<tr>
			<td>7</td>
			<td>Leave</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>8</td>
			<td>Leave</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>9</td>
			<td>Leave</td>
			<td>0</td>
			<td>3</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> 仅由字母 <code>'E'</code> 和 <code>'L'</code> 组成。</li>
	<li><code>s</code> 表示一个有效的进出序列。</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：模拟

我们用变量 $\textit{cnt}$ 来记录当前需要的椅子数，用变量 $\textit{left}$ 来记录当前剩余的空椅子数。遍历字符串 $\textit{s}$，如果当前字符是 'E'，那么如果有剩余的空椅子，就直接使用一个空椅子，否则需要增加一个椅子；如果当前字符是 'L'，那么剩余的空椅子数加一。

遍历结束后，返回 $\textit{cnt}$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $\textit{s}$ 的长度。空间复杂度 $O(1)$。

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
    def minimumChairs(self, s: str) -> int:
        cnt = left = 0
        for c in s:
            if c == "E":
                if left:
                    left -= 1
                else:
                    cnt += 1
            else:
                left += 1
        return cnt
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumChairs(String s) {
        int cnt = 0, left = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, left = 0;
        for (char& c : s) {
            if (c == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumChairs(s string) int {
	cnt, left := 0, 0
	for _, c := range s {
		if c == 'E' {
			if left > 0 {
				left--
			} else {
				cnt++
			}
		} else {
			left++
		}
	}
	return cnt
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumChairs(s: string): number {
    let [cnt, left] = [0, 0];
    for (const c of s) {
        if (c === 'E') {
            if (left > 0) {
                --left;
            } else {
                ++cnt;
            }
        } else {
            ++left;
        }
    }
    return cnt;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minimumChairs(self, s: str) -> int:
        cnt = left = 0
        for c in s:
            if c == "E":
                if left:
                    left -= 1
                else:
                    cnt += 1
            else:
                left += 1
        return cnt
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int minimumChairs(String s) {
        int cnt = 0, left = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
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
    int minimumChairs(string s) {
        int cnt = 0, left = 0;
        for (char& c : s) {
            if (c == 'E') {
                if (left > 0) {
                    --left;
                } else {
                    ++cnt;
                }
            } else {
                ++left;
            }
        }
        return cnt;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}