---
title: "0640_求解方程"
date: 2025-10-08T18:36:23+08:00
weight: 5
tags: [二分查找, 位运算, 前缀和, 动态规划, 双指针, 哈希表, 堆（优先队列）, 字典树, 字符串, 排序, 数学, 数据流, 数组, 模拟, 深度优先搜索, 滑动窗口, 设计, 贪心, 链表, 队列]
---

{{< markmap >}}
### [0640_求解方程](#640)
#### [数学](#640)
#### [字符串](#640)
#### [模拟](#640)
### [0641_设计循环双端队列](#641)
#### [设计](#641)
#### [队列](#641)
#### [数组](#641)
#### [链表](#641)
### [0642_设计搜索自动补全系统 🔒](#642)
#### [深度优先搜索](#642)
#### [设计](#642)
#### [字典树](#642)
#### [字符串](#642)
#### [数据流](#642)
#### [排序](#642)
#### [堆（优先队列）](#642)
### [0643_子数组最大平均数 I](#643)
#### [数组](#643)
#### [滑动窗口](#643)
### [0644_子数组最大平均数 II 🔒](#644)
#### [数组](#644)
#### [二分查找](#644)
#### [前缀和](#644)
### [0645_错误的集合](#645)
#### [位运算](#645)
#### [数组](#645)
#### [哈希表](#645)
#### [排序](#645)
### [0646_最长数对链](#646)
#### [贪心](#646)
#### [数组](#646)
#### [动态规划](#646)
#### [排序](#646)
### [0647_回文子串](#647)
#### [双指针](#647)
#### [字符串](#647)
#### [动态规划](#647)
### [0648_单词替换](#648)
#### [字典树](#648)
#### [数组](#648)
#### [哈希表](#648)
#### [字符串](#648)
### [0649_Dota2 参议院](#649)
#### [贪心](#649)
#### [队列](#649)
#### [字符串](#649)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0640_求解方程
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0641_设计循环双端队列
___
#### 设计
___
#### 队列
___
#### 数组
___
#### 链表
---
### 0642_设计搜索自动补全系统 🔒
___
#### 深度优先搜索
___
#### 设计
___
#### 字典树
___
#### 字符串
___
#### 数据流
___
#### 排序
___
#### 堆（优先队列）
---
### 0643_子数组最大平均数 I
___
#### 数组
___
#### 滑动窗口
---
### 0644_子数组最大平均数 II 🔒
___
#### 数组
___
#### 二分查找
___
#### 前缀和
---
### 0645_错误的集合
___
#### 位运算
___
#### 数组
___
#### 哈希表
___
#### 排序
---
### 0646_最长数对链
___
#### 贪心
___
#### 数组
___
#### 动态规划
___
#### 排序
---
### 0647_回文子串
___
#### 双指针
___
#### 字符串
___
#### 动态规划
---
### 0648_单词替换
___
#### 字典树
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0649_Dota2 参议院
___
#### 贪心
___
#### 队列
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 双指针 | 哈希表 |
| 堆（优先队列） | 字典树 | 字符串 |
| 排序 | 数学 | 数据流 |
| 数组 | 模拟 | 深度优先搜索 |
| 滑动窗口 | 设计 | 贪心 |
| 链表 | 队列 |  |

# [640. 求解方程](https://leetcode.cn/problems/solve-the-equation){#640}

{{< tabs "640" >}}

{{% tab "python" %}}
```python
class Solution:
    def solveEquation(self, equation: str) -> str:
        def f(s):
            x = y = 0
            if s[0] != '-':
                s = '+' + s
            i, n = 0, len(s)
            while i < n:
                sign = 1 if s[i] == '+' else -1
                i += 1
                j = i
                while j < n and s[j] not in '+-':
                    j += 1
                v = s[i:j]
                if v[-1] == 'x':
                    x += sign * (int(v[:-1]) if len(v) > 1 else 1)
                else:
                    y += sign * int(v)
                i = j
            return x, y

        a, b = equation.split('=')
        x1, y1 = f(a)
        x2, y2 = f(b)
        if x1 == x2:
            return 'Infinite solutions' if y1 == y2 else 'No solution'
        return f'x={(y2 - y1) // (x1 - x2)}'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String solveEquation(String equation) {
        String[] es = equation.split("=");
        int[] a = f(es[0]), b = f(es[1]);
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        if (x1 == x2) {
            return y1 == y2 ? "Infinite solutions" : "No solution";
        }
        return "x=" + (y2 - y1) / (x1 - x2);
    }

    private int[] f(String s) {
        int x = 0, y = 0;
        if (s.charAt(0) != '-') {
            s = "+" + s;
        }
        int i = 0, n = s.length();
        while (i < n) {
            int sign = s.charAt(i) == '+' ? 1 : -1;
            ++i;
            int j = i;
            while (j < n && s.charAt(j) != '+' && s.charAt(j) != '-') {
                ++j;
            }
            String v = s.substring(i, j);
            if (s.charAt(j - 1) == 'x') {
                x += sign * (v.length() > 1 ? Integer.parseInt(v.substring(0, v.length() - 1)) : 1);
            } else {
                y += sign * Integer.parseInt(v);
            }
            i = j;
        }
        return new int[] {x, y};
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
func solveEquation(equation string) string {
	f := func(s string) []int {
		x, y := 0, 0
		if s[0] != '-' {
			s = "+" + s
		}
		i, n := 0, len(s)
		for i < n {
			sign := 1
			if s[i] == '-' {
				sign = -1
			}
			i++
			j := i
			for j < n && s[j] != '+' && s[j] != '-' {
				j++
			}
			v := s[i:j]
			if s[j-1] == 'x' {
				a := 1
				if len(v) > 1 {
					a, _ = strconv.Atoi(v[:len(v)-1])
				}
				x += sign * a
			} else {
				a, _ := strconv.Atoi(v)
				y += sign * a
			}
			i = j
		}
		return []int{x, y}
	}

	es := strings.Split(equation, "=")
	a, b := f(es[0]), f(es[1])
	x1, y1 := a[0], a[1]
	x2, y2 := b[0], b[1]
	if x1 == x2 {
		if y1 == y2 {
			return "Infinite solutions"
		} else {
			return "No solution"
		}
	}
	return fmt.Sprintf("x=%d", (y2-y1)/(x1-x2))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function solveEquation(equation: string): string {
    const [left, right] = equation.split('=');
    const createExpr = (s: string) => {
        let x = 0;
        let n = 0;
        let i = 0;
        let sym = 1;
        let cur = 0;
        let isX = false;
        for (const c of s) {
            if (c === '+' || c === '-') {
                if (isX) {
                    if (i === 0 && cur === 0) {
                        cur = 1;
                    }
                    x += cur * sym;
                } else {
                    n += cur * sym;
                }
                isX = false;
                cur = 0;
                i = 0;
                if (c === '+') {
                    sym = 1;
                } else {
                    sym = -1;
                }
            } else if (c === 'x') {
                isX = true;
            } else {
                i++;
                cur *= 10;
                cur += Number(c);
            }
        }
        if (isX) {
            if (i === 0 && cur === 0) {
                cur = 1;
            }
            x += cur * sym;
        } else {
            n += cur * sym;
        }
        return [x, n];
    };
    const lExpr = createExpr(left);
    const rExpr = createExpr(right);
    if (lExpr[0] === rExpr[0]) {
        if (lExpr[1] !== rExpr[1]) {
            return 'No solution';
        }
        return 'Infinite solutions';
    }
    return `x=${(lExpr[1] - rExpr[1]) / (rExpr[0] - lExpr[0])}`;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>求解一个给定的方程，将<code>x</code>以字符串 <code>"x=#value"</code>&nbsp;的形式返回。该方程仅包含 <code>'+'</code> ， <code>'-'</code> 操作，变量&nbsp;<code>x</code>&nbsp;和其对应系数。</p>

<p>如果方程没有解或存在的解不为整数，请返回&nbsp;<code>"No solution"</code>&nbsp;。如果方程有无限解，则返回 <code>“Infinite solutions”</code> 。</p>

<p>题目保证，如果方程中只有一个解，则 <font color="#c7254e"><font face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size:12.6px"><span style="background-color:#f9f2f4">'x'</span></span></font></font> 的值是一个整数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> equation = "x+5-3+x=6+x-2"
<strong>输出:</strong> "x=2"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> equation = "x=x"
<strong>输出:</strong> "Infinite solutions"
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> equation = "2x=x"
<strong>输出:</strong> "x=0"
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= equation.length &lt;= 1000</code></li>
	<li><code>equation</code>&nbsp;只有一个&nbsp;<code>'='</code>.&nbsp;</li>
	<li>方程由绝对值在&nbsp;<code>[0, 100]</code>&nbsp; 范围内且无任何前导零的整数和变量 <code>'x'</code>&nbsp;组成。<span style="display:block"><span style="height:0px"><span style="position:absolute">​​​</span></span></span></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

将方程 $equation$ 按照等号 “=” 切分为左右两个式子，分别算出左右两个式子中 "x" 的系数 $x_i$，以及常数的值 $y_i$。

那么方程转换为等式 $x_1 \times x + y_1 = x_2 \times x + y_2$。

-   当 $x_1 = x_2$：若 $y_1 \neq y_2$，方程无解；若 $y_1=y_2$，方程有无限解。
-   当 $x_1 \neq x_2$：方程有唯一解 $x=\frac{y_2-y_1}{x_1-x_2}$。

相似题目：

-   [592. 分数加减运算](https://github.com/doocs/leetcode/blob/main/solution/0500-0599/0592.Fraction%20Addition%20and%20Subtraction/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def solveEquation(self, equation: str) -> str:
        def f(s):
            x = y = 0
            if s[0] != '-':
                s = '+' + s
            i, n = 0, len(s)
            while i < n:
                sign = 1 if s[i] == '+' else -1
                i += 1
                j = i
                while j < n and s[j] not in '+-':
                    j += 1
                v = s[i:j]
                if v[-1] == 'x':
                    x += sign * (int(v[:-1]) if len(v) > 1 else 1)
                else:
                    y += sign * int(v)
                i = j
            return x, y

        a, b = equation.split('=')
        x1, y1 = f(a)
        x2, y2 = f(b)
        if x1 == x2:
            return 'Infinite solutions' if y1 == y2 else 'No solution'
        return f'x={(y2 - y1) // (x1 - x2)}'
```

#### Java

```java
class Solution {
    public String solveEquation(String equation) {
        String[] es = equation.split("=");
        int[] a = f(es[0]), b = f(es[1]);
        int x1 = a[0], y1 = a[1];
        int x2 = b[0], y2 = b[1];
        if (x1 == x2) {
            return y1 == y2 ? "Infinite solutions" : "No solution";
        }
        return "x=" + (y2 - y1) / (x1 - x2);
    }

    private int[] f(String s) {
        int x = 0, y = 0;
        if (s.charAt(0) != '-') {
            s = "+" + s;
        }
        int i = 0, n = s.length();
        while (i < n) {
            int sign = s.charAt(i) == '+' ? 1 : -1;
            ++i;
            int j = i;
            while (j < n && s.charAt(j) != '+' && s.charAt(j) != '-') {
                ++j;
            }
            String v = s.substring(i, j);
            if (s.charAt(j - 1) == 'x') {
                x += sign * (v.length() > 1 ? Integer.parseInt(v.substring(0, v.length() - 1)) : 1);
            } else {
                y += sign * Integer.parseInt(v);
            }
            i = j;
        }
        return new int[] {x, y};
    }
}
```

#### Go

```go
func solveEquation(equation string) string {
	f := func(s string) []int {
		x, y := 0, 0
		if s[0] != '-' {
			s = "+" + s
		}
		i, n := 0, len(s)
		for i < n {
			sign := 1
			if s[i] == '-' {
				sign = -1
			}
			i++
			j := i
			for j < n && s[j] != '+' && s[j] != '-' {
				j++
			}
			v := s[i:j]
			if s[j-1] == 'x' {
				a := 1
				if len(v) > 1 {
					a, _ = strconv.Atoi(v[:len(v)-1])
				}
				x += sign * a
			} else {
				a, _ := strconv.Atoi(v)
				y += sign * a
			}
			i = j
		}
		return []int{x, y}
	}

	es := strings.Split(equation, "=")
	a, b := f(es[0]), f(es[1])
	x1, y1 := a[0], a[1]
	x2, y2 := b[0], b[1]
	if x1 == x2 {
		if y1 == y2 {
			return "Infinite solutions"
		} else {
			return "No solution"
		}
	}
	return fmt.Sprintf("x=%d", (y2-y1)/(x1-x2))
}
```

#### TypeScript

```ts
function solveEquation(equation: string): string {
    const [left, right] = equation.split('=');
    const createExpr = (s: string) => {
        let x = 0;
        let n = 0;
        let i = 0;
        let sym = 1;
        let cur = 0;
        let isX = false;
        for (const c of s) {
            if (c === '+' || c === '-') {
                if (isX) {
                    if (i === 0 && cur === 0) {
                        cur = 1;
                    }
                    x += cur * sym;
                } else {
                    n += cur * sym;
                }
                isX = false;
                cur = 0;
                i = 0;
                if (c === '+') {
                    sym = 1;
                } else {
                    sym = -1;
                }
            } else if (c === 'x') {
                isX = true;
            } else {
                i++;
                cur *= 10;
                cur += Number(c);
            }
        }
        if (isX) {
            if (i === 0 && cur === 0) {
                cur = 1;
            }
            x += cur * sym;
        } else {
            n += cur * sym;
        }
        return [x, n];
    };
    const lExpr = createExpr(left);
    const rExpr = createExpr(right);
    if (lExpr[0] === rExpr[0]) {
        if (lExpr[1] !== rExpr[1]) {
            return 'No solution';
        }
        return 'Infinite solutions';
    }
    return `x=${(lExpr[1] - rExpr[1]) / (rExpr[0] - lExpr[0])}`;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [641. 设计循环双端队列](https://leetcode.cn/problems/design-circular-deque){#641}

{{< tabs "641" >}}

{{% tab "python" %}}
```python
class MyCircularDeque:
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.q = [0] * k
        self.front = 0
        self.size = 0
        self.capacity = k

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        if not self.isEmpty():
            self.front = (self.front - 1 + self.capacity) % self.capacity
        self.q[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        idx = (self.front + self.size) % self.capacity
        self.q[idx] = value
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.size -= 1
        return True

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.isEmpty():
            return -1
        return self.q[self.front]

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.isEmpty():
            return -1
        idx = (self.front + self.size - 1) % self.capacity
        return self.q[idx]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return self.size == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self.size == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
```
{{% /tab %}}
{{% tab "java" %}}
```java
class MyCircularDeque {
    private int[] q;
    private int front;
    private int size;
    private int capacity;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        q = new int[k];
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front = (front - 1 + capacity) % capacity;
        }
        q[front] = value;
        ++size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size;
        return true;
    }

    /** Get the front item from the deque. */
    public int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    /** Get the last item from the deque. */
    public int getRear() {
        if (isEmpty()) {
            return -1;
        }
        int idx = (front + size - 1) % capacity;
        return q[idx];
    }

    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return size == capacity;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class MyCircularDeque {
public:
    vector<int> q;
    int front = 0;
    int size = 0;
    int capacity = 0;

    MyCircularDeque(int k) {
        q.assign(k, 0);
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front = (front - 1 + capacity) % capacity;
        }
        q[front] = value;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : q[front];
    }

    int getRear() {
        return isEmpty() ? -1 : q[(front + size - 1) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type MyCircularDeque struct {
	q        []int
	size     int
	front    int
	capacity int
}

func Constructor(k int) MyCircularDeque {
	q := make([]int, k)
	return MyCircularDeque{q, 0, 0, k}
}

func (this *MyCircularDeque) InsertFront(value int) bool {
	if this.IsFull() {
		return false
	}
	if !this.IsEmpty() {
		this.front = (this.front - 1 + this.capacity) % this.capacity
	}
	this.q[this.front] = value
	this.size++
	return true
}

func (this *MyCircularDeque) InsertLast(value int) bool {
	if this.IsFull() {
		return false
	}
	idx := (this.front + this.size) % this.capacity
	this.q[idx] = value
	this.size++
	return true
}

func (this *MyCircularDeque) DeleteFront() bool {
	if this.IsEmpty() {
		return false
	}
	this.front = (this.front + 1) % this.capacity
	this.size -= 1
	return true
}

func (this *MyCircularDeque) DeleteLast() bool {
	if this.IsEmpty() {
		return false
	}
	this.size -= 1
	return true
}

func (this *MyCircularDeque) GetFront() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[this.front]
}

func (this *MyCircularDeque) GetRear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[(this.front+this.size-1)%this.capacity]
}

func (this *MyCircularDeque) IsEmpty() bool {
	return this.size == 0
}

func (this *MyCircularDeque) IsFull() bool {
	return this.size == this.capacity
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class MyCircularDeque {
    private vals: number[];
    private length: number;
    private size: number;
    private start: number;
    private end: number;

    constructor(k: number) {
        this.vals = new Array(k).fill(0);
        this.start = 0;
        this.end = 0;
        this.length = 0;
        this.size = k;
    }

    insertFront(value: number): boolean {
        if (this.isFull()) {
            return false;
        }

        if (this.start === 0) {
            this.start = this.size - 1;
        } else {
            this.start--;
        }
        this.vals[this.start] = value;
        this.length++;
        return true;
    }

    insertLast(value: number): boolean {
        if (this.isFull()) {
            return false;
        }

        this.vals[this.end] = value;
        this.length++;
        if (this.end + 1 === this.size) {
            this.end = 0;
        } else {
            this.end++;
        }
        return true;
    }

    deleteFront(): boolean {
        if (this.isEmpty()) {
            return false;
        }

        if (this.start + 1 === this.size) {
            this.start = 0;
        } else {
            this.start++;
        }
        this.length--;
        return true;
    }

    deleteLast(): boolean {
        if (this.isEmpty()) {
            return false;
        }

        if (this.end === 0) {
            this.end = this.size - 1;
        } else {
            this.end--;
        }
        this.length--;
        return true;
    }

    getFront(): number {
        if (this.isEmpty()) {
            return -1;
        }

        return this.vals[this.start];
    }

    getRear(): number {
        if (this.isEmpty()) {
            return -1;
        }

        if (this.end === 0) {
            return this.vals[this.size - 1];
        }
        return this.vals[this.end - 1];
    }

    isEmpty(): boolean {
        return this.length === 0;
    }

    isFull(): boolean {
        return this.length === this.size;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计实现双端队列。</p>

<p>实现 <code>MyCircularDeque</code> 类:</p>

<ul>
	<li><code>MyCircularDeque(int k)</code>&nbsp;：构造函数,双端队列最大为 <code>k</code> 。</li>
	<li><code>boolean insertFront()</code>：将一个元素添加到双端队列头部。 如果操作成功返回 <code>true</code>&nbsp;，否则返回 <code>false</code> 。</li>
	<li><code>boolean insertLast()</code>&nbsp;：将一个元素添加到双端队列尾部。如果操作成功返回 <code>true</code>&nbsp;，否则返回 <code>false</code> 。</li>
	<li><code>boolean deleteFront()</code>&nbsp;：从双端队列头部删除一个元素。 如果操作成功返回 <code>true</code>&nbsp;，否则返回 <code>false</code> 。</li>
	<li><code>boolean deleteLast()</code>&nbsp;：从双端队列尾部删除一个元素。如果操作成功返回 <code>true</code>&nbsp;，否则返回 <code>false</code> 。</li>
	<li><code>int getFront()</code>&nbsp;)：从双端队列头部获得一个元素。如果双端队列为空，返回 <code>-1</code>&nbsp;。</li>
	<li><code>int getRear()</code>&nbsp;：获得双端队列的最后一个元素。&nbsp;如果双端队列为空，返回 <code>-1</code> 。</li>
	<li><code>boolean isEmpty()</code>&nbsp;：若双端队列为空，则返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code> &nbsp;。</li>
	<li><code>boolean isFull()</code>&nbsp;：若双端队列满了，则返回&nbsp;<code>true</code>&nbsp;，否则返回 <code>false</code> 。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入</strong>
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
<strong>输出</strong>
[null, true, true, true, false, 2, true, true, true, 4]

<strong>解释</strong>
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
&nbsp;</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>0 &lt;= value &lt;= 1000</code></li>
	<li><code>insertFront</code>,&nbsp;<code>insertLast</code>,&nbsp;<code>deleteFront</code>,&nbsp;<code>deleteLast</code>,&nbsp;<code>getFront</code>,&nbsp;<code>getRear</code>,&nbsp;<code>isEmpty</code>,&nbsp;<code>isFull</code>&nbsp; 调用次数不大于&nbsp;<code>2000</code>&nbsp;次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数组

利用循环数组，实现循环双端队列。

基本元素有：

-   front：队头元素的下标
-   size：队列中元素的个数
-   capacity：队列的容量
-   q：循环数组，存储队列中的元素

时间复杂度 $O(1)$，空间复杂度 $O(k)$。其中 $k$ 是队列的容量。

<!-- tabs:start -->

#### Python3

```python
class MyCircularDeque:
    def __init__(self, k: int):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        """
        self.q = [0] * k
        self.front = 0
        self.size = 0
        self.capacity = k

    def insertFront(self, value: int) -> bool:
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        if not self.isEmpty():
            self.front = (self.front - 1 + self.capacity) % self.capacity
        self.q[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        """
        if self.isFull():
            return False
        idx = (self.front + self.size) % self.capacity
        self.q[idx] = value
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.capacity
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        self.size -= 1
        return True

    def getFront(self) -> int:
        """
        Get the front item from the deque.
        """
        if self.isEmpty():
            return -1
        return self.q[self.front]

    def getRear(self) -> int:
        """
        Get the last item from the deque.
        """
        if self.isEmpty():
            return -1
        idx = (self.front + self.size - 1) % self.capacity
        return self.q[idx]

    def isEmpty(self) -> bool:
        """
        Checks whether the circular deque is empty or not.
        """
        return self.size == 0

    def isFull(self) -> bool:
        """
        Checks whether the circular deque is full or not.
        """
        return self.size == self.capacity


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
```

#### Java

```java
class MyCircularDeque {
    private int[] q;
    private int front;
    private int size;
    private int capacity;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    public MyCircularDeque(int k) {
        q = new int[k];
        capacity = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front = (front - 1 + capacity) % capacity;
        }
        q[front] = value;
        ++size;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size;
        return true;
    }

    /** Get the front item from the deque. */
    public int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }

    /** Get the last item from the deque. */
    public int getRear() {
        if (isEmpty()) {
            return -1;
        }
        int idx = (front + size - 1) % capacity;
        return q[idx];
    }

    /** Checks whether the circular deque is empty or not. */
    public boolean isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    public boolean isFull() {
        return size == capacity;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
```

#### C++

```cpp
class MyCircularDeque {
public:
    vector<int> q;
    int front = 0;
    int size = 0;
    int capacity = 0;

    MyCircularDeque(int k) {
        q.assign(k, 0);
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front = (front - 1 + capacity) % capacity;
        }
        q[front] = value;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : q[front];
    }

    int getRear() {
        return isEmpty() ? -1 : q[(front + size - 1) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

#### Go

```go
type MyCircularDeque struct {
	q        []int
	size     int
	front    int
	capacity int
}

func Constructor(k int) MyCircularDeque {
	q := make([]int, k)
	return MyCircularDeque{q, 0, 0, k}
}

func (this *MyCircularDeque) InsertFront(value int) bool {
	if this.IsFull() {
		return false
	}
	if !this.IsEmpty() {
		this.front = (this.front - 1 + this.capacity) % this.capacity
	}
	this.q[this.front] = value
	this.size++
	return true
}

func (this *MyCircularDeque) InsertLast(value int) bool {
	if this.IsFull() {
		return false
	}
	idx := (this.front + this.size) % this.capacity
	this.q[idx] = value
	this.size++
	return true
}

func (this *MyCircularDeque) DeleteFront() bool {
	if this.IsEmpty() {
		return false
	}
	this.front = (this.front + 1) % this.capacity
	this.size -= 1
	return true
}

func (this *MyCircularDeque) DeleteLast() bool {
	if this.IsEmpty() {
		return false
	}
	this.size -= 1
	return true
}

func (this *MyCircularDeque) GetFront() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[this.front]
}

func (this *MyCircularDeque) GetRear() int {
	if this.IsEmpty() {
		return -1
	}
	return this.q[(this.front+this.size-1)%this.capacity]
}

func (this *MyCircularDeque) IsEmpty() bool {
	return this.size == 0
}

func (this *MyCircularDeque) IsFull() bool {
	return this.size == this.capacity
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * obj := Constructor(k);
 * param_1 := obj.InsertFront(value);
 * param_2 := obj.InsertLast(value);
 * param_3 := obj.DeleteFront();
 * param_4 := obj.DeleteLast();
 * param_5 := obj.GetFront();
 * param_6 := obj.GetRear();
 * param_7 := obj.IsEmpty();
 * param_8 := obj.IsFull();
 */
```

#### TypeScript

```ts
class MyCircularDeque {
    private vals: number[];
    private length: number;
    private size: number;
    private start: number;
    private end: number;

    constructor(k: number) {
        this.vals = new Array(k).fill(0);
        this.start = 0;
        this.end = 0;
        this.length = 0;
        this.size = k;
    }

    insertFront(value: number): boolean {
        if (this.isFull()) {
            return false;
        }

        if (this.start === 0) {
            this.start = this.size - 1;
        } else {
            this.start--;
        }
        this.vals[this.start] = value;
        this.length++;
        return true;
    }

    insertLast(value: number): boolean {
        if (this.isFull()) {
            return false;
        }

        this.vals[this.end] = value;
        this.length++;
        if (this.end + 1 === this.size) {
            this.end = 0;
        } else {
            this.end++;
        }
        return true;
    }

    deleteFront(): boolean {
        if (this.isEmpty()) {
            return false;
        }

        if (this.start + 1 === this.size) {
            this.start = 0;
        } else {
            this.start++;
        }
        this.length--;
        return true;
    }

    deleteLast(): boolean {
        if (this.isEmpty()) {
            return false;
        }

        if (this.end === 0) {
            this.end = this.size - 1;
        } else {
            this.end--;
        }
        this.length--;
        return true;
    }

    getFront(): number {
        if (this.isEmpty()) {
            return -1;
        }

        return this.vals[this.start];
    }

    getRear(): number {
        if (this.isEmpty()) {
            return -1;
        }

        if (this.end === 0) {
            return this.vals[this.size - 1];
        }
        return this.vals[this.end - 1];
    }

    isEmpty(): boolean {
        return this.length === 0;
    }

    isFull(): boolean {
        return this.length === this.size;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * var obj = new MyCircularDeque(k)
 * var param_1 = obj.insertFront(value)
 * var param_2 = obj.insertLast(value)
 * var param_3 = obj.deleteFront()
 * var param_4 = obj.deleteLast()
 * var param_5 = obj.getFront()
 * var param_6 = obj.getRear()
 * var param_7 = obj.isEmpty()
 * var param_8 = obj.isFull()
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [642. 设计搜索自动补全系统 🔒](https://leetcode.cn/problems/design-search-autocomplete-system){#642}

{{< tabs "642" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children = [None] * 27
        self.v = 0
        self.w = ''

    def insert(self, w, t):
        node = self
        for c in w:
            idx = 26 if c == ' ' else ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.v += t
        node.w = w

    def search(self, pref):
        node = self
        for c in pref:
            idx = 26 if c == ' ' else ord(c) - ord('a')
            if node.children[idx] is None:
                return None
            node = node.children[idx]
        return node


class AutocompleteSystem:
    def __init__(self, sentences: List[str], times: List[int]):
        self.trie = Trie()
        for a, b in zip(sentences, times):
            self.trie.insert(a, b)
        self.t = []

    def input(self, c: str) -> List[str]:
        def dfs(node):
            if node is None:
                return
            if node.v:
                res.append((node.v, node.w))
            for nxt in node.children:
                dfs(nxt)

        if c == '#':
            s = ''.join(self.t)
            self.trie.insert(s, 1)
            self.t = []
            return []

        res = []
        self.t.append(c)
        node = self.trie.search(''.join(self.t))
        if node is None:
            return res
        dfs(node)
        res.sort(key=lambda x: (-x[0], x[1]))
        return [v[1] for v in res[:3]]


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    Trie[] children = new Trie[27];
    int v;
    String w = "";

    void insert(String w, int t) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c == ' ' ? 26 : c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.v += t;
        node.w = w;
    }

    Trie search(String pref) {
        Trie node = this;
        for (char c : pref.toCharArray()) {
            int idx = c == ' ' ? 26 : c - 'a';
            if (node.children[idx] == null) {
                return null;
            }
            node = node.children[idx];
        }
        return node;
    }
}

class AutocompleteSystem {
    private Trie trie = new Trie();
    private StringBuilder t = new StringBuilder();

    public AutocompleteSystem(String[] sentences, int[] times) {
        int i = 0;
        for (String s : sentences) {
            trie.insert(s, times[i++]);
        }
    }

    public List<String> input(char c) {
        List<String> res = new ArrayList<>();
        if (c == '#') {
            trie.insert(t.toString(), 1);
            t = new StringBuilder();
            return res;
        }
        t.append(c);
        Trie node = trie.search(t.toString());
        if (node == null) {
            return res;
        }
        PriorityQueue<Trie> q
            = new PriorityQueue<>((a, b) -> a.v == b.v ? b.w.compareTo(a.w) : a.v - b.v);
        dfs(node, q);
        while (!q.isEmpty()) {
            res.add(0, q.poll().w);
        }
        return res;
    }

    private void dfs(Trie node, PriorityQueue q) {
        if (node == null) {
            return;
        }
        if (node.v > 0) {
            q.offer(node);
            if (q.size() > 3) {
                q.poll();
            }
        }
        for (Trie nxt : node.children) {
            dfs(nxt, q);
        }
    }
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>为搜索引擎设计一个搜索自动补全系统。用户会输入一条语句（最少包含一个字母，以特殊字符 <code>'#'</code> 结尾）。</p>

<p>给定一个字符串数组&nbsp;<code>sentences</code>&nbsp;和一个整数数组&nbsp;<code>times</code>&nbsp;，长度都为&nbsp;<code>n</code>&nbsp;，其中&nbsp;<code>sentences[i]</code>&nbsp;是之前输入的句子，&nbsp;<code>times[i]</code>&nbsp;是该句子输入的相应次数。对于除 <code>‘#’</code>&nbsp;以外的每个输入字符，返回前 <code>3</code> 个历史热门句子，这些句子的前缀与已经输入的句子的部分相同。</p>

<p>下面是详细规则：</p>

<ul>
	<li>一条句子的热度定义为历史上用户输入这个句子的总次数。</li>
	<li>返回前 <code>3</code> 的句子需要按照热度从高到低排序（第一个是最热门的）。如果有多条热度相同的句子，请按照 ASCII 码的顺序输出（ASCII 码越小排名越前）。</li>
	<li>如果满足条件的句子个数少于 <code>3</code>&nbsp;，将它们全部输出。</li>
	<li>如果输入了特殊字符，意味着句子结束了，请返回一个空集合。</li>
</ul>

<p>实现&nbsp;<code>AutocompleteSystem</code>&nbsp;类：</p>

<ul>
	<li><code>AutocompleteSystem(String[] sentences, int[] times):</code>&nbsp;使用数组<code>sentences</code>&nbsp;和&nbsp;<code>times</code>&nbsp;对对象进行初始化。</li>
	<li><code>List&lt;String&gt; input(char c)</code>&nbsp;表示用户输入了字符&nbsp;<code>c</code>&nbsp;。
	<ul>
		<li>如果&nbsp;<code>c == '#'</code>&nbsp;，则返回空数组&nbsp;<code>[]</code> ，并将输入的语句存储在系统中。</li>
		<li>返回前 <code>3</code> 个历史热门句子，这些句子的前缀与已经输入的句子的部分相同。如果少于 <code>3</code> 个匹配项，则全部返回。</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入</strong>
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
<b>输出</b>
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

<strong>解释</strong>
AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
obj.input("a"); // return []. There are no sentences that have prefix "i a".
obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n == sentences.length</code></li>
	<li><code>n == times.length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= sentences[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= times[i] &lt;= 50</code></li>
	<li><code>c</code>&nbsp;是小写英文字母，&nbsp;<code>'#'</code>, 或空格&nbsp;<code>' '</code></li>
	<li>每个被测试的句子将是一个以字符 <code>'#'</code>&nbsp;结尾的字符 <code>c</code> 序列。</li>
	<li>每个被测试的句子的长度范围为 <code>[1,200]</code>&nbsp;</li>
	<li>每个输入句子中的单词用单个空格隔开。</li>
	<li><code>input</code>&nbsp;最多被调用 <code>5000</code> 次</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树 + 排序/优先队列

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children = [None] * 27
        self.v = 0
        self.w = ''

    def insert(self, w, t):
        node = self
        for c in w:
            idx = 26 if c == ' ' else ord(c) - ord('a')
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.v += t
        node.w = w

    def search(self, pref):
        node = self
        for c in pref:
            idx = 26 if c == ' ' else ord(c) - ord('a')
            if node.children[idx] is None:
                return None
            node = node.children[idx]
        return node


class AutocompleteSystem:
    def __init__(self, sentences: List[str], times: List[int]):
        self.trie = Trie()
        for a, b in zip(sentences, times):
            self.trie.insert(a, b)
        self.t = []

    def input(self, c: str) -> List[str]:
        def dfs(node):
            if node is None:
                return
            if node.v:
                res.append((node.v, node.w))
            for nxt in node.children:
                dfs(nxt)

        if c == '#':
            s = ''.join(self.t)
            self.trie.insert(s, 1)
            self.t = []
            return []

        res = []
        self.t.append(c)
        node = self.trie.search(''.join(self.t))
        if node is None:
            return res
        dfs(node)
        res.sort(key=lambda x: (-x[0], x[1]))
        return [v[1] for v in res[:3]]


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
```

#### Java

```java
class Trie {
    Trie[] children = new Trie[27];
    int v;
    String w = "";

    void insert(String w, int t) {
        Trie node = this;
        for (char c : w.toCharArray()) {
            int idx = c == ' ' ? 26 : c - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.v += t;
        node.w = w;
    }

    Trie search(String pref) {
        Trie node = this;
        for (char c : pref.toCharArray()) {
            int idx = c == ' ' ? 26 : c - 'a';
            if (node.children[idx] == null) {
                return null;
            }
            node = node.children[idx];
        }
        return node;
    }
}

class AutocompleteSystem {
    private Trie trie = new Trie();
    private StringBuilder t = new StringBuilder();

    public AutocompleteSystem(String[] sentences, int[] times) {
        int i = 0;
        for (String s : sentences) {
            trie.insert(s, times[i++]);
        }
    }

    public List<String> input(char c) {
        List<String> res = new ArrayList<>();
        if (c == '#') {
            trie.insert(t.toString(), 1);
            t = new StringBuilder();
            return res;
        }
        t.append(c);
        Trie node = trie.search(t.toString());
        if (node == null) {
            return res;
        }
        PriorityQueue<Trie> q
            = new PriorityQueue<>((a, b) -> a.v == b.v ? b.w.compareTo(a.w) : a.v - b.v);
        dfs(node, q);
        while (!q.isEmpty()) {
            res.add(0, q.poll().w);
        }
        return res;
    }

    private void dfs(Trie node, PriorityQueue q) {
        if (node == null) {
            return;
        }
        if (node.v > 0) {
            q.offer(node);
            if (q.size() > 3) {
                q.poll();
            }
        }
        for (Trie nxt : node.children) {
            dfs(nxt, q);
        }
    }
}

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * List<String> param_1 = obj.input(c);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [643. 子数组最大平均数 I](https://leetcode.cn/problems/maximum-average-subarray-i){#643}

{{< tabs "643" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        ans = s = sum(nums[:k])
        for i in range(k, len(nums)):
            s += nums[i] - nums[i - k]
            ans = max(ans, s)
        return ans / k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i];
        }
        int ans = s;
        for (int i = k; i < nums.length; ++i) {
            s += (nums[i] - nums[i - k]);
            ans = Math.max(ans, s);
        }
        return ans * 1.0 / k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.begin() + k, 0);
        int ans = s;
        for (int i = k; i < nums.size(); ++i) {
            s += nums[i] - nums[i - k];
            ans = max(ans, s);
        }
        return static_cast<double>(ans) / k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxAverage(nums []int, k int) float64 {
	s := 0
	for _, x := range nums[:k] {
		s += x
	}
	ans := s
	for i := k; i < len(nums); i++ {
		s += nums[i] - nums[i-k]
		ans = max(ans, s)
	}
	return float64(ans) / float64(k)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxAverage(nums: number[], k: number): number {
    let s = 0;
    for (let i = 0; i < k; ++i) {
        s += nums[i];
    }
    let ans = s;
    for (let i = k; i < nums.length; ++i) {
        s += nums[i] - nums[i - k];
        ans = Math.max(ans, s);
    }
    return ans / k;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let k = k as usize;
        let n = nums.len();
        let mut s = nums.iter().take(k).sum::<i32>();
        let mut ans = s;
        for i in k..n {
            s += nums[i] - nums[i - k];
            ans = ans.max(s);
        }
        f64::from(ans) / f64::from(k as i32)
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Float
     */
    function findMaxAverage($nums, $k) {
        $s = 0;
        for ($i = 0; $i < $k; $i++) {
            $s += $nums[$i];
        }
        $ans = $s;
        for ($j = $k; $j < count($nums); $j++) {
            $s = $s - $nums[$j - $k] + $nums[$j];
            $ans = max($ans, $s);
        }
        return $ans / $k;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由 <code>n</code> 个元素组成的整数数组 <code>nums</code> 和一个整数 <code>k</code> 。</p>

<p>请你找出平均数最大且 <strong>长度为 <code>k</code></strong> 的连续子数组，并输出该最大平均数。</p>

<p>任何误差小于 <code>10<sup>-5</sup></code> 的答案都将被视为正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,12,-5,-6,50,3], k = 4
<strong>输出：</strong>12.75
<strong>解释：</strong>最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5], k = 1
<strong>输出：</strong>5.00000
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们维护一个长度为 $k$ 的滑动窗口，每次计算窗口内的和 $s$，取最大的和 $s$ 作为答案。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        ans = s = sum(nums[:k])
        for i in range(k, len(nums)):
            s += nums[i] - nums[i - k]
            ans = max(ans, s)
        return ans / k
```

#### Java

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i];
        }
        int ans = s;
        for (int i = k; i < nums.length; ++i) {
            s += (nums[i] - nums[i - k]);
            ans = Math.max(ans, s);
        }
        return ans * 1.0 / k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.begin() + k, 0);
        int ans = s;
        for (int i = k; i < nums.size(); ++i) {
            s += nums[i] - nums[i - k];
            ans = max(ans, s);
        }
        return static_cast<double>(ans) / k;
    }
};
```

#### Go

```go
func findMaxAverage(nums []int, k int) float64 {
	s := 0
	for _, x := range nums[:k] {
		s += x
	}
	ans := s
	for i := k; i < len(nums); i++ {
		s += nums[i] - nums[i-k]
		ans = max(ans, s)
	}
	return float64(ans) / float64(k)
}
```

#### TypeScript

```ts
function findMaxAverage(nums: number[], k: number): number {
    let s = 0;
    for (let i = 0; i < k; ++i) {
        s += nums[i];
    }
    let ans = s;
    for (let i = k; i < nums.length; ++i) {
        s += nums[i] - nums[i - k];
        ans = Math.max(ans, s);
    }
    return ans / k;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let k = k as usize;
        let n = nums.len();
        let mut s = nums.iter().take(k).sum::<i32>();
        let mut ans = s;
        for i in k..n {
            s += nums[i] - nums[i - k];
            ans = ans.max(s);
        }
        f64::from(ans) / f64::from(k as i32)
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Float
     */
    function findMaxAverage($nums, $k) {
        $s = 0;
        for ($i = 0; $i < $k; $i++) {
            $s += $nums[$i];
        }
        $ans = $s;
        for ($j = $k; $j < count($nums); $j++) {
            $s = $s - $nums[$j - $k] + $nums[$j];
            $ans = max($ans, $s);
        }
        return $ans / $k;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [644. 子数组最大平均数 II 🔒](https://leetcode.cn/problems/maximum-average-subarray-ii){#644}

{{< tabs "644" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        def check(v: float) -> bool:
            s = sum(nums[:k]) - k * v
            if s >= 0:
                return True
            t = mi = 0
            for i in range(k, len(nums)):
                s += nums[i] - v
                t += nums[i - k] - v
                mi = min(mi, t)
                if s >= mi:
                    return True
            return False

        eps = 1e-5
        l, r = min(nums), max(nums)
        while r - l >= eps:
            mid = (l + r) / 2
            if check(mid):
                l = mid
            else:
                r = mid
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double eps = 1e-5;
        double l = 1e10, r = -1e10;
        for (int x : nums) {
            l = Math.min(l, x);
            r = Math.max(r, x);
        }
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            if (check(nums, k, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private boolean check(int[] nums, int k, double v) {
        double s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i] - v;
        }
        if (s >= 0) {
            return true;
        }
        double t = 0;
        double mi = 0;
        for (int i = k; i < nums.length; ++i) {
            s += nums[i] - v;
            t += nums[i - k] - v;
            mi = Math.min(mi, t);
            if (s >= mi) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double eps = 1e-5;
        double l = *min_element(nums.begin(), nums.end());
        double r = *max_element(nums.begin(), nums.end());
        auto check = [&](double v) {
            double s = 0;
            for (int i = 0; i < k; ++i) {
                s += nums[i] - v;
            }
            if (s >= 0) {
                return true;
            }
            double t = 0;
            double mi = 0;
            for (int i = k; i < nums.size(); ++i) {
                s += nums[i] - v;
                t += nums[i - k] - v;
                mi = min(mi, t);
                if (s >= mi) {
                    return true;
                }
            }
            return false;
        };
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxAverage(nums []int, k int) float64 {
	eps := 1e-5
	l := float64(slices.Min(nums))
	r := float64(slices.Max(nums))
	check := func(v float64) bool {
		s := 0.0
		for _, x := range nums[:k] {
			s += float64(x) - v
		}
		if s >= 0 {
			return true
		}
		t := 0.0
		mi := 0.0
		for i := k; i < len(nums); i++ {
			s += float64(nums[i]) - v
			t += float64(nums[i-k]) - v
			mi = math.Min(mi, t)
			if s >= mi {
				return true
			}
		}
		return false
	}
	for r-l >= eps {
		mid := (l + r) / 2
		if check(mid) {
			l = mid
		} else {
			r = mid
		}
	}
	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxAverage(nums: number[], k: number): number {
    const eps = 1e-5;
    let l = Math.min(...nums);
    let r = Math.max(...nums);
    const check = (v: number): boolean => {
        let s = nums.slice(0, k).reduce((a, b) => a + b) - v * k;
        if (s >= 0) {
            return true;
        }
        let t = 0;
        let mi = 0;
        for (let i = k; i < nums.length; ++i) {
            s += nums[i] - v;
            t += nums[i - k] - v;
            mi = Math.min(mi, t);
            if (s >= mi) {
                return true;
            }
        }
        return false;
    };
    while (r - l >= eps) {
        const mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
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

<p>给你一个包含 <code>n</code> 个整数的数组 <code>nums</code> ，和一个整数 <code>k</code> 。</p>

<p>请你找出<strong> 长度大于等于</strong> <code>k</code> 且含最大平均值的连续子数组。并输出这个最大平均值。任何计算误差小于 <code>10<sup>-5</sup></code> 的结果都将被视为正确答案。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,12,-5,-6,50,3], k = 4
<strong>输出：</strong>12.75000
<strong>解释：
</strong>- 当长度为 4 的时候，连续子数组平均值分别为 [0.5, 12.75, 10.5] ，其中最大平均值是 12.75 。
- 当长度为 5 的时候，连续子数组平均值分别为 [10.4, 10.8] ，其中最大平均值是 10.8 。
- 当长度为 6 的时候，连续子数组平均值分别为 [9.16667] ，其中最大平均值是 9.16667 。
当取长度为 4 的子数组（即，子数组 [12, -5, -6, 50]）的时候，可以得到最大的连续子数组平均值 12.75 ，所以返回 12.75 。
根据题目要求，无需考虑长度小于 4 的子数组。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [5], k = 1
<strong>输出：</strong>5.00000
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 <= k <= n <= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，如果一个长度大于等于 $k$ 的子数组的平均值为 $v$，那么最大平均数一定大于等于 $v$，否则最大平均数一定小于 $v$。因此，我们可以使用二分查找的方法找出最大平均数。

我们考虑二分查找的左右边界分别是什么？左边界 $l$ 一定是数组中的最小值，而右边界 $r$ 则是数组中的最大值。接下来，我们二分查找中点 $mid$，判断是否存在长度大于等于 $k$ 的子数组的平均值大于等于 $mid$。如果存在，那么我们就将左边界 $l$ 更新为 $mid$，否则我们就将右边界 $r$ 更新为 $mid$。当左边界和右边界的差小于一个极小的非负数，即 $r - l < \epsilon$ 时，我们就可以得到最大平均数，其中 $\epsilon$ 表示一个极小的正数，可以取 $10^{-5}$。

问题的关键在于如何判断一个长度大于等于 $k$ 的子数组的平均值是否大于等于 $v$。

我们假设在数组 $nums$ 中，存在一个长度为 $j$ 的子数组，元素分别为 $a_1, a_2, \cdots, a_j$，满足其平均值大于等于 $v$，即：

$$
\frac{a_1 + a_2 + \cdots + a_j}{j} \geq v
$$

那么：

$$
a_1 + a_2 + \cdots + a_j \geq v \times j
$$

即：

$$
(a_1 - v) + (a_2 - v) + \cdots + (a_j - v) \geq 0
$$

可以发现，如果我们将数组 $nums$ 中的每个元素都减去 $v$，那么原问题就转换成了一个求长度大于等于 $k$ 的子数组的元素和是否大于等于 $0$ 的问题。我们可以使用滑动窗口来解决这个问题。

我们先计算得到数组前 $k$ 个元素与 $v$ 的差值之和 $s$，如果 $s \geq 0$，那么就说明存在长度大于等于 $k$ 的子数组的元素和大于等于 $0$。

否则，我们继续往后遍历元素 $nums[j]$，假设当前前 $j$ 项元素与 $v$ 的差值之和为 $s_j$，那么我们可以维护在 $[0,..j-k]$ 范围内元素的前缀和与 $v$ 的差值之和的最小值 $mi$，如果存在 $s_j \geq mi$，那么就说明存在长度大于等于 $k$ 的子数组的元素和大于等于 $0$，返回 $true$。

否则，我们继续往后遍历元素 $nums[j]$，直到遍历完整个数组。

时间复杂度 $O(n \times \log M)$，其中 $n$ 和 $M$ 分别是数组 $nums$ 的长度以及数组中的最大值和最小值的差值。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        def check(v: float) -> bool:
            s = sum(nums[:k]) - k * v
            if s >= 0:
                return True
            t = mi = 0
            for i in range(k, len(nums)):
                s += nums[i] - v
                t += nums[i - k] - v
                mi = min(mi, t)
                if s >= mi:
                    return True
            return False

        eps = 1e-5
        l, r = min(nums), max(nums)
        while r - l >= eps:
            mid = (l + r) / 2
            if check(mid):
                l = mid
            else:
                r = mid
        return l
```

#### Java

```java
class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double eps = 1e-5;
        double l = 1e10, r = -1e10;
        for (int x : nums) {
            l = Math.min(l, x);
            r = Math.max(r, x);
        }
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            if (check(nums, k, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }

    private boolean check(int[] nums, int k, double v) {
        double s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i] - v;
        }
        if (s >= 0) {
            return true;
        }
        double t = 0;
        double mi = 0;
        for (int i = k; i < nums.length; ++i) {
            s += nums[i] - v;
            t += nums[i - k] - v;
            mi = Math.min(mi, t);
            if (s >= mi) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double eps = 1e-5;
        double l = *min_element(nums.begin(), nums.end());
        double r = *max_element(nums.begin(), nums.end());
        auto check = [&](double v) {
            double s = 0;
            for (int i = 0; i < k; ++i) {
                s += nums[i] - v;
            }
            if (s >= 0) {
                return true;
            }
            double t = 0;
            double mi = 0;
            for (int i = k; i < nums.size(); ++i) {
                s += nums[i] - v;
                t += nums[i - k] - v;
                mi = min(mi, t);
                if (s >= mi) {
                    return true;
                }
            }
            return false;
        };
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
```

#### Go

```go
func findMaxAverage(nums []int, k int) float64 {
	eps := 1e-5
	l := float64(slices.Min(nums))
	r := float64(slices.Max(nums))
	check := func(v float64) bool {
		s := 0.0
		for _, x := range nums[:k] {
			s += float64(x) - v
		}
		if s >= 0 {
			return true
		}
		t := 0.0
		mi := 0.0
		for i := k; i < len(nums); i++ {
			s += float64(nums[i]) - v
			t += float64(nums[i-k]) - v
			mi = math.Min(mi, t)
			if s >= mi {
				return true
			}
		}
		return false
	}
	for r-l >= eps {
		mid := (l + r) / 2
		if check(mid) {
			l = mid
		} else {
			r = mid
		}
	}
	return l
}
```

#### TypeScript

```ts
function findMaxAverage(nums: number[], k: number): number {
    const eps = 1e-5;
    let l = Math.min(...nums);
    let r = Math.max(...nums);
    const check = (v: number): boolean => {
        let s = nums.slice(0, k).reduce((a, b) => a + b) - v * k;
        if (s >= 0) {
            return true;
        }
        let t = 0;
        let mi = 0;
        for (let i = k; i < nums.length; ++i) {
            s += nums[i] - v;
            t += nums[i - k] - v;
            mi = Math.min(mi, t);
            if (s >= mi) {
                return true;
            }
        }
        return false;
    };
    while (r - l >= eps) {
        const mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
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

# [645. 错误的集合](https://leetcode.cn/problems/set-mismatch){#645}

{{< tabs "645" >}}

{{% tab "python" %}}
```python
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        xs = 0
        for i, x in enumerate(nums, 1):
            xs ^= i ^ x
        a = 0
        lb = xs & -xs
        for i, x in enumerate(nums, 1):
            if i & lb:
                a ^= i
            if x & lb:
                a ^= x
        b = xs ^ a
        for x in nums:
            if x == a:
                return [a, b]
        return [b, a]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & lb) > 0) {
                a ^= i;
            }
            if ((nums[i - 1] & lb) > 0) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return new int[] {a, b};
            }
        }
        return new int[] {b, a};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & lb) {
                a ^= i;
            }
            if (nums[i - 1] & lb) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return {a, b};
            }
        }
        return {b, a};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findErrorNums(nums []int) []int {
	xs := 0
	for i, x := range nums {
		xs ^= x ^ (i + 1)
	}
	lb := xs & -xs
	a := 0
	for i, x := range nums {
		if (i+1)&lb != 0 {
			a ^= (i + 1)
		}
		if x&lb != 0 {
			a ^= x
		}
	}
	b := xs ^ a
	for _, x := range nums {
		if x == a {
			return []int{a, b}
		}
	}
	return []int{b, a}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findErrorNums(nums: number[]): number[] {
    const n = nums.length;
    let xs = 0;
    for (let i = 1; i <= n; ++i) {
        xs ^= i ^ nums[i - 1];
    }
    const lb = xs & -xs;
    let a = 0;
    for (let i = 1; i <= n; ++i) {
        if (i & lb) {
            a ^= i;
        }
        if (nums[i - 1] & lb) {
            a ^= nums[i - 1];
        }
    }
    const b = xs ^ a;
    return nums.includes(a) ? [a, b] : [b, a];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let mut xs = 0;
        for (i, x) in nums.iter().enumerate() {
            xs ^= ((i + 1) as i32) ^ x;
        }
        let mut a = 0;
        let lb = xs & -xs;
        for (i, x) in nums.iter().enumerate() {
            if (((i + 1) as i32) & lb) != 0 {
                a ^= (i + 1) as i32;
            }
            if (*x & lb) != 0 {
                a ^= *x;
            }
        }
        let b = xs ^ a;
        for x in nums.iter() {
            if *x == a {
                return vec![a, b];
            }
        }
        vec![b, a]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>集合 <code>s</code> 包含从 <code>1</code> 到 <code>n</code> 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 <strong>丢失了一个数字</strong> 并且 <strong>有一个数字重复</strong> 。</p>

<p>给定一个数组 <code>nums</code> 代表了集合 <code>S</code> 发生错误后的结果。</p>

<p>请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,2,4]
<strong>输出：</strong>[2,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>1 <= nums[i] <= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

我们用 $s_1$ 表示 $[1,..n]$ 所有数字的和，用 $s_2$ 表示数组 $nums$ 去重后的数字和，用 $s$ 表示数组 $nums$ 的数字和。

那么 $s - s_2$ 就是重复的数字，而 $s_1 - s_2$ 就是缺失的数字。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。需要额外的空间对数组去重。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        s1 = (1 + n) * n // 2
        s2 = sum(set(nums))
        s = sum(nums)
        return [s - s2, s1 - s2]
```

#### Java

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int s1 = (1 + n) * n / 2;
        int s2 = 0;
        Set<Integer> set = new HashSet<>();
        int s = 0;
        for (int x : nums) {
            if (set.add(x)) {
                s2 += x;
            }
            s += x;
        }
        return new int[] {s - s2, s1 - s2};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int s1 = (1 + n) * n / 2;
        int s2 = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (int x : set) {
            s2 += x;
        }
        int s = accumulate(nums.begin(), nums.end(), 0);
        return {s - s2, s1 - s2};
    }
};
```

#### Go

```go
func findErrorNums(nums []int) []int {
	n := len(nums)
	s1 := (1 + n) * n / 2
	s2, s := 0, 0
	set := map[int]bool{}
	for _, x := range nums {
		if !set[x] {
			set[x] = true
			s2 += x
		}
		s += x
	}
	return []int{s - s2, s1 - s2}
}
```

#### TypeScript

```ts
function findErrorNums(nums: number[]): number[] {
    const n = nums.length;
    const s1 = (n * (n + 1)) >> 1;
    const s2 = [...new Set(nums)].reduce((a, b) => a + b);
    const s = nums.reduce((a, b) => a + b);
    return [s - s2, s1 - s2];
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        let s1 = ((1 + n) * n) / 2;
        let s2 = nums
            .iter()
            .cloned()
            .collect::<HashSet<i32>>()
            .iter()
            .sum::<i32>();
        let s: i32 = nums.iter().sum();
        vec![s - s2, s1 - s2]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：哈希表

我们也可以一种更加直观的方法，直接用哈希表 $cnt$ 统计数组 $nums$ 中每个数字出现的次数。

接下来遍历 $x \in [1, n]$，如果 $cnt[x] = 2$，那么 $x$ 就是重复的数字，如果 $cnt[x] = 0$，那么 $x$ 就是缺失的数字。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        n = len(nums)
        ans = [0] * 2
        for x in range(1, n + 1):
            if cnt[x] == 2:
                ans[0] = x
            if cnt[x] == 0:
                ans[1] = x
        return ans
```

#### Java

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> cnt = new HashMap<>(n);
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        int[] ans = new int[2];
        for (int x = 1; x <= n; ++x) {
            int t = cnt.getOrDefault(x, 0);
            if (t == 2) {
                ans[0] = x;
            } else if (t == 0) {
                ans[1] = x;
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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[x];
        }
        vector<int> ans(2);
        for (int x = 1; x <= n; ++x) {
            if (cnt[x] == 2) {
                ans[0] = x;
            } else if (cnt[x] == 0) {
                ans[1] = x;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findErrorNums(nums []int) []int {
	n := len(nums)
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	ans := make([]int, 2)
	for x := 1; x <= n; x++ {
		if cnt[x] == 2 {
			ans[0] = x
		} else if cnt[x] == 0 {
			ans[1] = x
		}
	}
	return ans
}
```

#### TypeScript

```ts
function findErrorNums(nums: number[]): number[] {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    const ans: number[] = new Array(2).fill(0);
    for (let x = 1; x <= n; ++x) {
        const t = cnt.get(x) || 0;
        if (t === 2) {
            ans[0] = x;
        } else if (t === 0) {
            ans[1] = x;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_error_nums(nums: Vec<i32>) -> Vec<i32> {
        let mut xs = 0;
        for (i, x) in nums.iter().enumerate() {
            xs ^= ((i + 1) as i32) ^ x;
        }
        let mut a = 0;
        let lb = xs & -xs;
        for (i, x) in nums.iter().enumerate() {
            if (((i + 1) as i32) & lb) != 0 {
                a ^= (i + 1) as i32;
            }
            if (*x & lb) != 0 {
                a ^= *x;
            }
        }
        let b = xs ^ a;
        for x in nums.iter() {
            if *x == a {
                return vec![a, b];
            }
        }
        vec![b, a]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：位运算

根据异或运算的性质，对于整数 $x$，有 $x \oplus x = 0$ 以及 $x \oplus 0 = x$，因此我们对数组 $nums$ 中的所有元素以及 $i \in [1, n]$ 的所有数字进行异或运算，可以消除出现两次的数字，最终只留下缺失的数字和重复的数字的异或结果，即 $xs = a \oplus b$。

由于这两个数字不相等，因此异或结果中至少存在一位为 $1$。我们通过 $lowbit$ 运算找到异或结果中最低位的 $1$，然后将数组 $nums$ 中所有数字以及 $i \in [1, n]$ 的所有数字按照该位是否为 $1$ 分为两组，这样两个数字就被分到了不同的组中。其中一组数字的异或结果为 $a$，另一组数字的异或结果为 $b$。那么这两个数字就是我们要找的答案。

接下来我们只需要判断 $a$ 和 $b$ 哪个数字是重复的数字，哪个数字是缺失的数字即可。因此，遍历数组 $nums$，对于遍历到的数字 $x$，如果 $x=a$，那么 $a$ 就是重复的数字，返回 $[a, b]$，否则遍历结束，返回 $[b, a]$。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$，仅使用常数大小的额外空间。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        xs = 0
        for i, x in enumerate(nums, 1):
            xs ^= i ^ x
        a = 0
        lb = xs & -xs
        for i, x in enumerate(nums, 1):
            if i & lb:
                a ^= i
            if x & lb:
                a ^= x
        b = xs ^ a
        for x in nums:
            if x == a:
                return [a, b]
        return [b, a]
```

#### Java

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & lb) > 0) {
                a ^= i;
            }
            if ((nums[i - 1] & lb) > 0) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return new int[] {a, b};
            }
        }
        return new int[] {b, a};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xs = 0;
        for (int i = 1; i <= n; ++i) {
            xs ^= i ^ nums[i - 1];
        }
        int lb = xs & -xs;
        int a = 0;
        for (int i = 1; i <= n; ++i) {
            if (i & lb) {
                a ^= i;
            }
            if (nums[i - 1] & lb) {
                a ^= nums[i - 1];
            }
        }
        int b = xs ^ a;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == a) {
                return {a, b};
            }
        }
        return {b, a};
    }
};
```

#### Go

```go
func findErrorNums(nums []int) []int {
	xs := 0
	for i, x := range nums {
		xs ^= x ^ (i + 1)
	}
	lb := xs & -xs
	a := 0
	for i, x := range nums {
		if (i+1)&lb != 0 {
			a ^= (i + 1)
		}
		if x&lb != 0 {
			a ^= x
		}
	}
	b := xs ^ a
	for _, x := range nums {
		if x == a {
			return []int{a, b}
		}
	}
	return []int{b, a}
}
```

#### TypeScript

```ts
function findErrorNums(nums: number[]): number[] {
    const n = nums.length;
    let xs = 0;
    for (let i = 1; i <= n; ++i) {
        xs ^= i ^ nums[i - 1];
    }
    const lb = xs & -xs;
    let a = 0;
    for (let i = 1; i <= n; ++i) {
        if (i & lb) {
            a ^= i;
        }
        if (nums[i - 1] & lb) {
            a ^= nums[i - 1];
        }
    }
    const b = xs ^ a;
    return nums.includes(a) ? [a, b] : [b, a];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [646. 最长数对链](https://leetcode.cn/problems/maximum-length-of-pair-chain){#646}

{{< tabs "646" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[1])
        ans, pre = 0, -inf
        for a, b in pairs:
            if pre < a:
                ans += 1
                pre = b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));
        int ans = 0, pre = Integer.MIN_VALUE;
        for (var p : pairs) {
            if (pre < p[0]) {
                ++ans;
                pre = p[1];
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
    int findLongestChain(vector<vector<int>>& pairs) {
        ranges::sort(pairs, {}, [](const auto& p) { return p[1]; });
        int ans = 0, pre = INT_MIN;
        for (const auto& p : pairs) {
            if (pre < p[0]) {
                pre = p[1];
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLongestChain(pairs [][]int) (ans int) {
	sort.Slice(pairs, func(i, j int) bool { return pairs[i][1] < pairs[j][1] })
	pre := math.MinInt
	for _, p := range pairs {
		if pre < p[0] {
			ans++
			pre = p[1]
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLongestChain(pairs: number[][]): number {
    pairs.sort((a, b) => a[1] - b[1]);
    let [ans, pre] = [0, -Infinity];
    for (const [a, b] of pairs) {
        if (pre < a) {
            ++ans;
            pre = b;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_longest_chain(mut pairs: Vec<Vec<i32>>) -> i32 {
        pairs.sort_by_key(|pair| pair[1]);
        let mut ans = 0;
        let mut pre = i32::MIN;
        for pair in pairs {
            let (a, b) = (pair[0], pair[1]);
            if pre < a {
                ans += 1;
                pre = b;
            }
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

<p>给你一个由&nbsp;<code>n</code>&nbsp;个数对组成的数对数组&nbsp;<code>pairs</code>&nbsp;，其中&nbsp;<code>pairs[i] = [left<sub>i</sub>, right<sub>i</sub>]</code>&nbsp;且&nbsp;<code>left<sub>i</sub>&nbsp;&lt; right<sub>i</sub></code><sub> 。</sub></p>

<p>现在，我们定义一种 <strong>跟随</strong> 关系，当且仅当&nbsp;<code>b &lt; c</code>&nbsp;时，数对&nbsp;<code>p2 = [c, d]</code>&nbsp;才可以跟在&nbsp;<code>p1 = [a, b]</code>&nbsp;后面。我们用这种形式来构造 <strong>数对链</strong> 。</p>

<p>找出并返回能够形成的 <strong>最长数对链的长度</strong> 。</p>

<p>你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>pairs =&nbsp;[[1,2], [2,3], [3,4]]
<strong>输出：</strong>2
<strong>解释：</strong>最长的数对链是 [1,2] -&gt; [3,4] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>pairs = [[1,2],[7,8],[4,5]]
<b>输出：</b>3
<b>解释：</b>最长的数对链是 [1,2] -&gt; [4,5] -&gt; [7,8] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == pairs.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>-1000 &lt;= left<sub>i</sub>&nbsp;&lt; right<sub>i</sub>&nbsp;&lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心

我们将所有数对按照第二个数的升序排序，用一个变量 $\textit{pre}$ 维护已经选择的数对的第二个数的最大值。

遍历排序后的数对，如果当前数对的第一个数大于 $\textit{pre}$，那么我们可以贪心地选择当前数对，答案加一，并将 $\textit{pre}$ 更新为当前数对的第二个数。

遍历结束后，返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数对的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: x[1])
        ans, pre = 0, -inf
        for a, b in pairs:
            if pre < a:
                ans += 1
                pre = b
        return ans
```

#### Java

```java
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));
        int ans = 0, pre = Integer.MIN_VALUE;
        for (var p : pairs) {
            if (pre < p[0]) {
                ++ans;
                pre = p[1];
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
    int findLongestChain(vector<vector<int>>& pairs) {
        ranges::sort(pairs, {}, [](const auto& p) { return p[1]; });
        int ans = 0, pre = INT_MIN;
        for (const auto& p : pairs) {
            if (pre < p[0]) {
                pre = p[1];
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLongestChain(pairs [][]int) (ans int) {
	sort.Slice(pairs, func(i, j int) bool { return pairs[i][1] < pairs[j][1] })
	pre := math.MinInt
	for _, p := range pairs {
		if pre < p[0] {
			ans++
			pre = p[1]
		}
	}
	return
}
```

#### TypeScript

```ts
function findLongestChain(pairs: number[][]): number {
    pairs.sort((a, b) => a[1] - b[1]);
    let [ans, pre] = [0, -Infinity];
    for (const [a, b] of pairs) {
        if (pre < a) {
            ++ans;
            pre = b;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_longest_chain(mut pairs: Vec<Vec<i32>>) -> i32 {
        pairs.sort_by_key(|pair| pair[1]);
        let mut ans = 0;
        let mut pre = i32::MIN;
        for pair in pairs {
            let (a, b) = (pair[0], pair[1]);
            if pre < a {
                ans += 1;
                pre = b;
            }
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

# [647. 回文子串](https://leetcode.cn/problems/palindromic-substrings){#647}

{{< tabs "647" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubstrings(self, s: str) -> int:
        t = '^#' + '#'.join(s) + '#$'
        n = len(t)
        p = [0 for _ in range(n)]
        pos, maxRight = 0, 0
        ans = 0
        for i in range(1, n - 1):
            p[i] = min(maxRight - i, p[2 * pos - i]) if maxRight > i else 1
            while t[i - p[i]] == t[i + p[i]]:
                p[i] += 1
            if i + p[i] > maxRight:
                maxRight = i + p[i]
                pos = i
            ans += p[i] // 2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countSubstrings(String s) {
        StringBuilder sb = new StringBuilder("^#");
        for (char ch : s.toCharArray()) {
            sb.append(ch).append('#');
        }
        String t = sb.append('$').toString();
        int n = t.length();
        int[] p = new int[n];
        int pos = 0, maxRight = 0;
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            p[i] = maxRight > i ? Math.min(maxRight - i, p[2 * pos - i]) : 1;
            while (t.charAt(i - p[i]) == t.charAt(i + p[i])) {
                p[i]++;
            }
            if (i + p[i] > maxRight) {
                maxRight = i + p[i];
                pos = i;
            }
            ans += p[i] / 2;
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
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for (int k = 0; k < n * 2 - 1; ++k) {
            int i = k / 2, j = (k + 1) / 2;
            while (~i && j < n && s[i] == s[j]) {
                ++ans;
                --i;
                ++j;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubstrings(s string) int {
	ans, n := 0, len(s)
	for k := 0; k < n*2-1; k++ {
		i, j := k/2, (k+1)/2
		for i >= 0 && j < n && s[i] == s[j] {
			ans++
			i, j = i-1, j+1
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function (s) {
    let ans = 0;
    const n = s.length;
    for (let k = 0; k < n * 2 - 1; ++k) {
        let i = k >> 1;
        let j = (k + 1) >> 1;
        while (~i && j < n && s[i] == s[j]) {
            ++ans;
            --i;
            ++j;
        }
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，请你统计并返回这个字符串中 <strong>回文子串</strong> 的数目。</p>

<p><strong>回文字符串</strong> 是正着读和倒过来读一样的字符串。</p>

<p><strong>子字符串</strong> 是字符串中的由连续字符组成的一个序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abc"
<strong>输出：</strong>3
<strong>解释：</strong>三个回文子串: "a", "b", "c"
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "aaa"
<strong>输出：</strong>6
<strong>解释：</strong>6个回文子串: "a", "a", "a", "aa", "aa", "aaa"</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：从中心向两侧扩展回文串

时间复杂度 $O(n^2)$，其中 $n$ 是字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubstrings(self, s: str) -> int:
        ans, n = 0, len(s)
        for k in range(n * 2 - 1):
            i, j = k // 2, (k + 1) // 2
            while ~i and j < n and s[i] == s[j]:
                ans += 1
                i, j = i - 1, j + 1
        return ans
```

#### Java

```java
class Solution {
    public int countSubstrings(String s) {
        int ans = 0;
        int n = s.length();
        for (int k = 0; k < n * 2 - 1; ++k) {
            int i = k / 2, j = (k + 1) / 2;
            while (i >= 0 && j < n && s.charAt(i) == s.charAt(j)) {
                ++ans;
                --i;
                ++j;
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
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        for (int k = 0; k < n * 2 - 1; ++k) {
            int i = k / 2, j = (k + 1) / 2;
            while (~i && j < n && s[i] == s[j]) {
                ++ans;
                --i;
                ++j;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countSubstrings(s string) int {
	ans, n := 0, len(s)
	for k := 0; k < n*2-1; k++ {
		i, j := k/2, (k+1)/2
		for i >= 0 && j < n && s[i] == s[j] {
			ans++
			i, j = i-1, j+1
		}
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function (s) {
    let ans = 0;
    const n = s.length;
    for (let k = 0; k < n * 2 - 1; ++k) {
        let i = k >> 1;
        let j = (k + 1) >> 1;
        while (~i && j < n && s[i] == s[j]) {
            ++ans;
            --i;
            ++j;
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Manacher 算法

在 Manacher 算法的计算过程中，用 $p[i]-1$ 表示以第 $i$ 位为中心的最大回文长度，以第 $i$ 位为中心的回文串数量为 $\left \lceil \frac{p[i]-1}{2}  \right \rceil$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubstrings(self, s: str) -> int:
        t = '^#' + '#'.join(s) + '#$'
        n = len(t)
        p = [0 for _ in range(n)]
        pos, maxRight = 0, 0
        ans = 0
        for i in range(1, n - 1):
            p[i] = min(maxRight - i, p[2 * pos - i]) if maxRight > i else 1
            while t[i - p[i]] == t[i + p[i]]:
                p[i] += 1
            if i + p[i] > maxRight:
                maxRight = i + p[i]
                pos = i
            ans += p[i] // 2
        return ans
```

#### Java

```java
class Solution {
    public int countSubstrings(String s) {
        StringBuilder sb = new StringBuilder("^#");
        for (char ch : s.toCharArray()) {
            sb.append(ch).append('#');
        }
        String t = sb.append('$').toString();
        int n = t.length();
        int[] p = new int[n];
        int pos = 0, maxRight = 0;
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            p[i] = maxRight > i ? Math.min(maxRight - i, p[2 * pos - i]) : 1;
            while (t.charAt(i - p[i]) == t.charAt(i + p[i])) {
                p[i]++;
            }
            if (i + p[i] > maxRight) {
                maxRight = i + p[i];
                pos = i;
            }
            ans += p[i] / 2;
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [648. 单词替换](https://leetcode.cn/problems/replace-words){#648}

{{< tabs "648" >}}

{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.ref: int = -1

    def insert(self, w: str, i: int):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.ref = i

    def search(self, w: str) -> int:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return -1
            node = node.children[idx]
            if node.ref != -1:
                return node.ref
        return -1


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for i, w in enumerate(dictionary):
            trie.insert(w, i)
        ans = []
        for w in sentence.split():
            idx = trie.search(w)
            ans.append(dictionary[idx] if idx != -1 else w)
        return " ".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private int ref = -1;

    public void insert(String w, int i) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.ref = i;
    }

    public int search(String w) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                return -1;
            }
            node = node.children[idx];
            if (node.ref != -1) {
                return node.ref;
            }
        }
        return -1;
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie.insert(dictionary.get(i), i);
        }
        List<String> ans = new ArrayList<>();
        for (String w : sentence.split("\\s")) {
            int idx = trie.search(w);
            ans.add(idx == -1 ? w : dictionary.get(idx));
        }
        return String.join(" ", ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[26];
    int ref;

public:
    Trie()
        : ref(-1) {
        memset(children, 0, sizeof(children));
    }

    void insert(const string& w, int i) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->ref = i;
    }

    int search(const string& w) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return -1;
            }
            node = node->children[idx];
            if (node->ref != -1) {
                return node->ref;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie->insert(dictionary[i], i);
        }
        stringstream ss(sentence);
        string w;
        string ans;
        while (ss >> w) {
            int idx = trie->search(w);
            ans += (idx == -1 ? w : dictionary[idx]) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	ref      int
}

func newTrie() *Trie {
	return &Trie{ref: -1}
}

func (this *Trie) insert(w string, i int) {
	node := this
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.ref = i
}

func (this *Trie) search(w string) int {
	node := this
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			return -1
		}
		node = node.children[idx]
		if node.ref != -1 {
			return node.ref
		}
	}
	return -1
}

func replaceWords(dictionary []string, sentence string) string {
	trie := newTrie()
	for i, w := range dictionary {
		trie.insert(w, i)
	}
	ans := strings.Builder{}
	for _, w := range strings.Split(sentence, " ") {
		if idx := trie.search(w); idx != -1 {
			ans.WriteString(dictionary[idx])
		} else {
			ans.WriteString(w)
		}
		ans.WriteByte(' ')
	}
	return ans.String()[:ans.Len()-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function replaceWords(dictionary: string[], sentence: string): string {
    const words = sentence.split(' ');
    const trie: Trie = {};
    const TERMINAL_MARK = 'TERMINAL_MARK';

    for (const s of dictionary) {
        let t = trie;

        for (const ch of s) {
            t[ch] ??= {};
            t = t[ch] as Trie_;
        }
        t[TERMINAL_MARK] = TERMINAL_MARK;
    }

    for (let i = 0; i < words.length; i++) {
        const s = words[i];
        let t = trie;

        for (let j = 0; j < s.length; j++) {
            const ch = s[j];

            if (!t[ch]) break;

            if ((t[ch] as Trie_)[TERMINAL_MARK]) {
                words[i] = s.slice(0, j + 1);
                break;
            }
            t = t[ch] as Trie_;
        }
    }

    return words.join(' ');
}

// prettier-ignore
type Trie = { [key: string]: Trie} | string
type Trie_ = Exclude<Trie, string>;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>在英语中，我们有一个叫做&nbsp;<strong>词根</strong>(root) 的概念，可以词根&nbsp;<strong>后面&nbsp;</strong>添加其他一些词组成另一个较长的单词——我们称这个词为 <strong>衍生词</strong>&nbsp;(<strong>derivative</strong>)。例如，词根&nbsp;<code>help</code>，跟随着 <strong>继承</strong>词&nbsp;<code>"ful"</code>，可以形成新的单词&nbsp;<code>"helpful"</code>。</p>

<p>现在，给定一个由许多&nbsp;<strong>词根&nbsp;</strong>组成的词典 <code>dictionary</code> 和一个用空格分隔单词形成的句子 <code>sentence</code>。你需要将句子中的所有&nbsp;<strong>衍生词&nbsp;</strong>用&nbsp;<strong>词根&nbsp;</strong>替换掉。如果&nbsp;<strong>衍生词&nbsp;</strong>有许多可以形成它的&nbsp;<strong>词根</strong>，则用&nbsp;<strong>最短&nbsp;</strong>的 <strong>词根</strong> 替换它。</p>

<p>你需要输出替换之后的句子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
<strong>输出：</strong>"the cat was rat by the bat"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
<strong>输出：</strong>"a a b c"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= dictionary.length&nbsp;&lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 100</code></li>
	<li><code>dictionary[i]</code>&nbsp;仅由小写字母组成。</li>
	<li><code>1 &lt;= sentence.length &lt;= 10<sup>6</sup></code></li>
	<li><code>sentence</code>&nbsp;仅由小写字母和空格组成。</li>
	<li><code>sentence</code> 中单词的总量在范围 <code>[1, 1000]</code> 内。</li>
	<li><code>sentence</code> 中每个单词的长度在范围 <code>[1, 1000]</code> 内。</li>
	<li><code>sentence</code> 中单词之间由一个空格隔开。</li>
	<li><code>sentence</code>&nbsp;没有前导或尾随空格。</li>
</ul>

<p>&nbsp;</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀树

我们定义前缀树的节点数据结构如下：

-   `children`：子节点数组，长度为 $26$，每个元素为一个节点或 `None`
-   `ref`：如果当前节点是一个单词的结尾，则 `ref` 为该单词在 `dictionary` 中的索引，否则为 $-1$

我们首先将 `dictionary` 中的单词插入到前缀树中，然后遍历 `sentence` 中的每个单词，查找前缀树中是否存在该单词的前缀，如果存在，则将该单词替换为前缀。

时间复杂度为 $O(\sum_{w \in dictionary} |w| + |sentence|)$，空间复杂度为 $O(\sum_{w \in dictionary} |w|)$。其中 $|w|$ 表示单词 $w$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.ref: int = -1

    def insert(self, w: str, i: int):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.ref = i

    def search(self, w: str) -> int:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return -1
            node = node.children[idx]
            if node.ref != -1:
                return node.ref
        return -1


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for i, w in enumerate(dictionary):
            trie.insert(w, i)
        ans = []
        for w in sentence.split():
            idx = trie.search(w)
            ans.append(dictionary[idx] if idx != -1 else w)
        return " ".join(ans)
```

#### Java

```java
class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Set<String> s = new HashSet<>(dictionary);
        String[] words = sentence.split(" ");
        for (int i = 0; i < words.length; ++i) {
            String word = words[i];
            for (int j = 1; j <= word.length(); ++j) {
                String t = word.substring(0, j);
                if (s.contains(t)) {
                    words[i] = t;
                    break;
                }
            }
        }
        return String.join(" ", words);
    }
}
```

#### C++

```cpp
class Trie {
private:
    Trie* children[26];
    int ref;

public:
    Trie()
        : ref(-1) {
        memset(children, 0, sizeof(children));
    }

    void insert(const string& w, int i) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->ref = i;
    }

    int search(const string& w) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return -1;
            }
            node = node->children[idx];
            if (node->ref != -1) {
                return node->ref;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie->insert(dictionary[i], i);
        }
        stringstream ss(sentence);
        string w;
        string ans;
        while (ss >> w) {
            int idx = trie->search(w);
            ans += (idx == -1 ? w : dictionary[idx]) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
```

#### Go

```go
type Trie struct {
	children [26]*Trie
	ref      int
}

func newTrie() *Trie {
	return &Trie{ref: -1}
}

func (this *Trie) insert(w string, i int) {
	node := this
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.ref = i
}

func (this *Trie) search(w string) int {
	node := this
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			return -1
		}
		node = node.children[idx]
		if node.ref != -1 {
			return node.ref
		}
	}
	return -1
}

func replaceWords(dictionary []string, sentence string) string {
	trie := newTrie()
	for i, w := range dictionary {
		trie.insert(w, i)
	}
	ans := strings.Builder{}
	for _, w := range strings.Split(sentence, " ") {
		if idx := trie.search(w); idx != -1 {
			ans.WriteString(dictionary[idx])
		} else {
			ans.WriteString(w)
		}
		ans.WriteByte(' ')
	}
	return ans.String()[:ans.Len()-1]
}
```

#### TypeScript

```ts
class Trie {
    #children: Record<string, Trie> = {};
    #ref = -1;

    insert(w: string, i: number) {
        let node: Trie = this;
        for (const c of w) {
            node.#children[c] ??= new Trie();
            node = node.#children[c];
        }
        node.#ref = i;
    }

    search(w: string): number {
        let node: Trie = this;
        for (const c of w) {
            if (!node.#children[c]) {
                return -1;
            }
            node = node.#children[c];
            if (node.#ref !== -1) {
                return node.#ref;
            }
        }
        return -1;
    }
}

function replaceWords(dictionary: string[], sentence: string): string {
    const trie = new Trie();
    for (let i = 0; i < dictionary.length; i++) {
        trie.insert(dictionary[i], i);
    }
    return sentence
        .split(' ')
        .map(w => {
            const idx = trie.search(w);
            return idx !== -1 ? dictionary[idx] : w;
        })
        .join(' ');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Java

```java
class Trie {
    private Trie[] children = new Trie[26];
    private int ref = -1;

    public void insert(String w, int i) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.ref = i;
    }

    public int search(String w) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                return -1;
            }
            node = node.children[idx];
            if (node.ref != -1) {
                return node.ref;
            }
        }
        return -1;
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie.insert(dictionary.get(i), i);
        }
        List<String> ans = new ArrayList<>();
        for (String w : sentence.split("\\s")) {
            int idx = trie.search(w);
            ans.add(idx == -1 ? w : dictionary.get(idx));
        }
        return String.join(" ", ans);
    }
}
```

#### TypeScript

```ts
function replaceWords(dictionary: string[], sentence: string): string {
    const words = sentence.split(' ');
    const trie: Trie = {};
    const TERMINAL_MARK = 'TERMINAL_MARK';

    for (const s of dictionary) {
        let t = trie;

        for (const ch of s) {
            t[ch] ??= {};
            t = t[ch] as Trie_;
        }
        t[TERMINAL_MARK] = TERMINAL_MARK;
    }

    for (let i = 0; i < words.length; i++) {
        const s = words[i];
        let t = trie;

        for (let j = 0; j < s.length; j++) {
            const ch = s[j];

            if (!t[ch]) break;

            if ((t[ch] as Trie_)[TERMINAL_MARK]) {
                words[i] = s.slice(0, j + 1);
                break;
            }
            t = t[ch] as Trie_;
        }
    }

    return words.join(' ');
}

// prettier-ignore
type Trie = { [key: string]: Trie} | string
type Trie_ = Exclude<Trie, string>;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [649. Dota2 参议院](https://leetcode.cn/problems/dota2-senate){#649}

{{< tabs "649" >}}

{{% tab "python" %}}
```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        qr = deque()
        qd = deque()
        for i, c in enumerate(senate):
            if c == "R":
                qr.append(i)
            else:
                qd.append(i)
        n = len(senate)
        while qr and qd:
            if qr[0] < qd[0]:
                qr.append(qr[0] + n)
            else:
                qd.append(qd[0] + n)
            qr.popleft()
            qd.popleft()
        return "Radiant" if qr else "Dire"
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Deque<Integer> qr = new ArrayDeque<>();
        Deque<Integer> qd = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (senate.charAt(i) == 'R') {
                qr.offer(i);
            } else {
                qd.offer(i);
            }
        }
        while (!qr.isEmpty() && !qd.isEmpty()) {
            if (qr.peek() < qd.peek()) {
                qr.offer(qr.peek() + n);
            } else {
                qd.offer(qd.peek() + n);
            }
            qr.poll();
            qd.poll();
        }
        return qr.isEmpty() ? "Dire" : "Radiant";
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qr;
        queue<int> qd;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                qr.push(i);
            } else {
                qd.push(i);
            }
        }
        while (!qr.empty() && !qd.empty()) {
            int r = qr.front();
            int d = qd.front();
            qr.pop();
            qd.pop();
            if (r < d) {
                qr.push(r + n);
            } else {
                qd.push(d + n);
            }
        }
        return qr.empty() ? "Dire" : "Radiant";
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func predictPartyVictory(senate string) string {
	n := len(senate)
	qr := []int{}
	qd := []int{}
	for i, c := range senate {
		if c == 'R' {
			qr = append(qr, i)
		} else {
			qd = append(qd, i)
		}
	}
	for len(qr) > 0 && len(qd) > 0 {
		r, d := qr[0], qd[0]
		qr, qd = qr[1:], qd[1:]
		if r < d {
			qr = append(qr, r+n)
		} else {
			qd = append(qd, d+n)
		}
	}
	if len(qr) > 0 {
		return "Radiant"
	}
	return "Dire"
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function predictPartyVictory(senate: string): string {
    const n = senate.length;
    const qr: number[] = [];
    const qd: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (senate[i] === 'R') {
            qr.push(i);
        } else {
            qd.push(i);
        }
    }
    while (qr.length > 0 && qd.length > 0) {
        const r = qr.shift()!;
        const d = qd.shift()!;
        if (r < d) {
            qr.push(r + n);
        } else {
            qd.push(d + n);
        }
    }
    return qr.length > 0 ? 'Radiant' : 'Dire';
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let mut qr = std::collections::VecDeque::new();
        let mut qd = std::collections::VecDeque::new();
        let n = senate.len();
        for i in 0..n {
            if let Some(char) = senate.chars().nth(i) {
                if char == 'R' {
                    qr.push_back(i);
                } else {
                    qd.push_back(i);
                }
            }
        }

        while !qr.is_empty() && !qd.is_empty() {
            let front_qr = qr.pop_front().unwrap();
            let front_qd = qd.pop_front().unwrap();
            if front_qr < front_qd {
                qr.push_back(front_qr + n);
            } else {
                qd.push_back(front_qd + n);
            }
        }
        if qr.is_empty() {
            return "Dire".to_string();
        }
        "Radiant".to_string()
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>Dota2 的世界里有两个阵营：<code>Radiant</code>（天辉）和&nbsp;<code>Dire</code>（夜魇）</p>

<p>Dota2 参议院由来自两派的参议员组成。现在参议院希望对一个 Dota2 游戏里的改变作出决定。他们以一个基于轮为过程的投票进行。在每一轮中，每一位参议员都可以行使两项权利中的 <strong>一 </strong>项：</p>

<ul>
	<li><strong>禁止一名参议员的权利</strong>：参议员可以让另一位参议员在这一轮和随后的几轮中丧失<strong> 所有的权利 </strong>。</li>
	<li><strong>宣布胜利</strong>：如果参议员发现有权利投票的参议员都是 <strong>同一个阵营的</strong> ，他可以宣布胜利并决定在游戏中的有关变化。</li>
</ul>

<p>给你一个字符串&nbsp;<code>senate</code> 代表每个参议员的阵营。字母 <code>'R'</code> 和 <code>'D'</code>分别代表了&nbsp;<code>Radiant</code>（天辉）和&nbsp;<code>Dire</code>（夜魇）。然后，如果有 <code>n</code> 个参议员，给定字符串的大小将是&nbsp;<code>n</code>。</p>

<p>以轮为基础的过程从给定顺序的第一个参议员开始到最后一个参议员结束。这一过程将持续到投票结束。所有失去权利的参议员将在过程中被跳过。</p>

<p>假设每一位参议员都足够聪明，会为自己的政党做出最好的策略，你需要预测哪一方最终会宣布胜利并在 Dota2 游戏中决定改变。输出应该是&nbsp;<code>"Radiant"</code> 或 <code>"Dire"</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>senate = "RD"
<strong>输出：</strong>"Radiant"
<strong>解释：
</strong><code>第 1 轮时，第一个参议员来自 Radiant 阵营，他可以使用第一项权利让第二个参议员失去所有权利。
这一轮中，第二个参议员将会被跳过，因为他的权利被禁止了。
第 2 轮时，第一个参议员可以宣布胜利，因为他是唯一一个有投票权的人</code>。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>senate = "RDD"
<strong>输出：</strong>"Dire"
<strong>解释：</strong>
第 1 轮时，第一个<code>来自 Radiant 阵营的</code>参议员可以使用第一项权利禁止第二个参议员的权利。
<code>这一轮中，</code>第二个<code>来自 Dire 阵营的</code>参议员会将被跳过，因为他的权利被禁止了。
<code>这一轮中，</code>第三个<code>来自 Dire 阵营的</code>参议员可以使用他的第一项权利禁止第一个参议员的权利。
因此在第二轮只剩下第三个参议员拥有投票的权利,于是他可以宣布胜利
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == senate.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>senate[i]</code> 为 <code>'R'</code> 或 <code>'D'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：队列 + 模拟

我们创建两个队列 $qr$ 和 $qd$，分别记录天辉和夜魇阵营的参议员的下标。然后我们开始进行模拟，每一轮各从队首取出一位参议员，然后根据他的阵营进行不同的操作：

-   如果天辉阵营的参议员编号小于夜魇阵营的参议员编号，那么该天辉阵营的参议员就可以将夜魇阵营的参议员票权永久取消，我们将天辉阵营的参议员的下标加 $n$ 后重新放回队尾，表示该参议员会参与下一轮的投票。
-   如果夜魇阵营的参议员编号小于天辉阵营的参议员编号，那么该夜魇阵营的参议员就可以将天辉阵营的参议员票权永久取消，我们将夜魇阵营的参议员的下标加 $n$ 后重新放回队尾，表示该参议员会参与下一轮的投票。

最后当队列中只剩一种阵营的参议员时，该阵营的参议员获胜。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为参议员的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        qr = deque()
        qd = deque()
        for i, c in enumerate(senate):
            if c == "R":
                qr.append(i)
            else:
                qd.append(i)
        n = len(senate)
        while qr and qd:
            if qr[0] < qd[0]:
                qr.append(qr[0] + n)
            else:
                qd.append(qd[0] + n)
            qr.popleft()
            qd.popleft()
        return "Radiant" if qr else "Dire"
```

#### Java

```java
class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Deque<Integer> qr = new ArrayDeque<>();
        Deque<Integer> qd = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (senate.charAt(i) == 'R') {
                qr.offer(i);
            } else {
                qd.offer(i);
            }
        }
        while (!qr.isEmpty() && !qd.isEmpty()) {
            if (qr.peek() < qd.peek()) {
                qr.offer(qr.peek() + n);
            } else {
                qd.offer(qd.peek() + n);
            }
            qr.poll();
            qd.poll();
        }
        return qr.isEmpty() ? "Dire" : "Radiant";
    }
}
```

#### C++

```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qr;
        queue<int> qd;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                qr.push(i);
            } else {
                qd.push(i);
            }
        }
        while (!qr.empty() && !qd.empty()) {
            int r = qr.front();
            int d = qd.front();
            qr.pop();
            qd.pop();
            if (r < d) {
                qr.push(r + n);
            } else {
                qd.push(d + n);
            }
        }
        return qr.empty() ? "Dire" : "Radiant";
    }
};
```

#### Go

```go
func predictPartyVictory(senate string) string {
	n := len(senate)
	qr := []int{}
	qd := []int{}
	for i, c := range senate {
		if c == 'R' {
			qr = append(qr, i)
		} else {
			qd = append(qd, i)
		}
	}
	for len(qr) > 0 && len(qd) > 0 {
		r, d := qr[0], qd[0]
		qr, qd = qr[1:], qd[1:]
		if r < d {
			qr = append(qr, r+n)
		} else {
			qd = append(qd, d+n)
		}
	}
	if len(qr) > 0 {
		return "Radiant"
	}
	return "Dire"
}
```

#### TypeScript

```ts
function predictPartyVictory(senate: string): string {
    const n = senate.length;
    const qr: number[] = [];
    const qd: number[] = [];
    for (let i = 0; i < n; ++i) {
        if (senate[i] === 'R') {
            qr.push(i);
        } else {
            qd.push(i);
        }
    }
    while (qr.length > 0 && qd.length > 0) {
        const r = qr.shift()!;
        const d = qd.shift()!;
        if (r < d) {
            qr.push(r + n);
        } else {
            qd.push(d + n);
        }
    }
    return qr.length > 0 ? 'Radiant' : 'Dire';
}
```

#### Rust

```rust
impl Solution {
    pub fn predict_party_victory(senate: String) -> String {
        let mut qr = std::collections::VecDeque::new();
        let mut qd = std::collections::VecDeque::new();
        let n = senate.len();
        for i in 0..n {
            if let Some(char) = senate.chars().nth(i) {
                if char == 'R' {
                    qr.push_back(i);
                } else {
                    qd.push_back(i);
                }
            }
        }

        while !qr.is_empty() && !qd.is_empty() {
            let front_qr = qr.pop_front().unwrap();
            let front_qd = qd.pop_front().unwrap();
            if front_qr < front_qd {
                qr.push_back(front_qr + n);
            } else {
                qd.push_back(front_qd + n);
            }
        }
        if qr.is_empty() {
            return "Dire".to_string();
        }
        "Radiant".to_string()
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
