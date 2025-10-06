---
title: "0202_HappyNumber"
date: 2025-10-06T00:42:37+08:00
weight: 0202
tags: [哈希表, 数学, 双指针]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [202. 快乐数](https://leetcode.cn/problems/happy-number)

[English Version](../en/0202-02/0202_HappyNumber)

## 题目描述

<!-- description:start -->

<p>编写一个算法来判断一个数 <code>n</code> 是不是快乐数。</p>

<p><strong>「快乐数」</strong>&nbsp;定义为：</p>

<ul>
	<li>对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。</li>
	<li>然后重复这个过程直到这个数变为 1，也可能是 <strong>无限循环</strong> 但始终变不到 1。</li>
	<li>如果这个过程 <strong>结果为</strong>&nbsp;1，那么这个数就是快乐数。</li>
</ul>

<p>如果 <code>n</code> 是 <em>快乐数</em> 就返回 <code>true</code> ；不是，则返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 19
<strong>输出：</strong>true
<strong>解释：
</strong>1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：哈希表 + 模拟

将每次转换后的数字存入哈希表，如果出现重复数字，说明进入了循环，不是快乐数。否则，如果转换后的数字为 $1$，说明是快乐数。

时间复杂度 $O(\log n)$，空间复杂度 $O(\log n)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：快慢指针

与判断链表是否存在环原理一致。如果 $n$ 是快乐数，那么快指针最终会与慢指针相遇，且相遇时的数字为 $1$；否则，快指针最终会与慢指针相遇，且相遇时的数字不为 $1$。

因此，最后判断快慢指针相遇时的数字是否为 $1$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def isHappy(self, n: int) -> bool:
        def next(x):
            y = 0
            while x:
                x, v = divmod(x, 10)
                y += v * v
            return y

        slow, fast = n, next(n)
        while slow != fast:
            slow, fast = next(slow), next(next(fast))
        return slow == 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }

    private int next(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y += (x % 10) * (x % 10);
        }
        return y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int x) {
            int y = 0;
            for (; x; x /= 10) {
                y += pow(x % 10, 2);
            }
            return y;
        };
        int slow = n, fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isHappy(n int) bool {
	next := func(x int) (y int) {
		for ; x > 0; x /= 10 {
			y += (x % 10) * (x % 10)
		}
		return
	}
	slow, fast := n, next(n)
	for slow != fast {
		slow = next(slow)
		fast = next(next(fast))
	}
	return slow == 1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isHappy(n: number): boolean {
    const getNext = (n: number) => {
        let res = 0;
        while (n !== 0) {
            res += (n % 10) ** 2;
            n = Math.floor(n / 10);
        }
        return res;
    };

    let slow = n;
    let fast = getNext(n);
    while (slow !== fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast === 1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let get_next = |mut n: i32| {
            let mut res = 0;
            while n != 0 {
                res += (n % 10).pow(2);
                n /= 10;
            }
            res
        };
        let mut slow = n;
        let mut fast = get_next(n);
        while slow != fast {
            slow = get_next(slow);
            fast = get_next(get_next(fast));
        }
        slow == 1
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
int getNext(int n) {
    int res = 0;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    while (slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def isHappy(self, n: int) -> bool:
        def next(x):
            y = 0
            while x:
                x, v = divmod(x, 10)
                y += v * v
            return y

        slow, fast = n, next(n)
        while slow != fast:
            slow, fast = next(slow), next(next(fast))
        return slow == 1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }

    private int next(int x) {
        int y = 0;
        for (; x > 0; x /= 10) {
            y += (x % 10) * (x % 10);
        }
        return y;
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
int getNext(int n) {
    int res = 0;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);
    while (slow != fast) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return fast == 1;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    bool isHappy(int n) {
        auto next = [](int x) {
            int y = 0;
            for (; x; x /= 10) {
                y += pow(x % 10, 2);
            }
            return y;
        };
        int slow = n, fast = next(n);
        while (slow != fast) {
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow == 1;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}