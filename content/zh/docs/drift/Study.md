

### java 构造函数

```java 
public Book {
    public Book(String _name, double _price){
        name = _name;
        price = _price;
    }


}

```


{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="500" language="python" >}}
def Yu():
    print("hello")
Yu()
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}


{{< tabs id >}}
{{% tab "python" %}}
```python
print("hello")
```
{{% /tab %}}
{{% tab "c" %}}
```c 
#include <stdio.h> 
int main(){
    printf("Hello\n");
    return 0;
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)
  res = []
  nums.sort!

  for i in 0..(nums.length - 3)
    next if i > 0 && nums[i - 1] == nums[i]
    j = i + 1
    k = nums.length - 1
    while j < k do
      sum = nums[i] + nums[j] + nums[k]
      if sum < 0
        j += 1
      elsif sum > 0
        k -= 1
      else
        res += [[nums[i], nums[j], nums[k]]]
        j += 1
        k -= 1
        j += 1 while nums[j] == nums[j - 1]
        k -= 1 while nums[k] == nums[k + 1]
      end
    end
  end

  res
end
```
{{% /tab %}}
{{< /tabs>}}



{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="500" language="python" >}}
print("hello")
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}


{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="500" language="c" >}}
#include <stdio.h> 
int main(){
    printf("Hello\n");
    return 0;
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

<!-- problem:start -->

# [1. 两数之和](https://leetcode.cn/problems/two-sum)

[English Version](/solution/0000-0099/0001.Two%20Sum/README_EN.md)

## 题目描述

<!-- description:start -->

<p>给定一个整数数组 <code>nums</code>&nbsp;和一个整数目标值 <code>target</code>，请你在该数组中找出 <strong>和为目标值 </strong><em><code>target</code></em>&nbsp; 的那&nbsp;<strong>两个</strong>&nbsp;整数，并返回它们的数组下标。</p>

<p>你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。</p>

<p>你可以按任意顺序返回答案。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,7,11,15], target = 9
<strong>输出：</strong>[0,1]
<strong>解释：</strong>因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,4], target = 6
<strong>输出：</strong>[1,2]
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,3], target = 6
<strong>输出：</strong>[0,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>只会存在一个有效答案</strong></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以想出一个时间复杂度小于 <code>O(n<sup>2</sup>)</code> 的算法吗？</p>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以使用一个哈希表 $\textit{d}$ 来存储每个元素及其对应的索引。

遍历数组 $\textit{nums}$，对于当前元素 $\textit{nums}[i]$，我们首先判断 $\textit{target} - \textit{nums}[i]$ 是否在哈希表 $\textit{d}$ 中，如果在 $\textit{d}$ 中，说明 $\textit{target}$ 值已经找到，返回 $\textit{target} - \textit{nums}[i]$ 的索引和 $i$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(nums):
            if (y := target - x) in d:
                return [d[y], i]
            d[x] = i
```
{{% /tab %}}
{{< /tabs>}}


#### Java

{{< tabs id >}}
{{% tab "java" %}}
```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0;; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.containsKey(y)) {
                return new int[] {d.get(y), i};
            }
            d.put(x, i);
        }
    }
}
```
{{% /tab %}}
{{< /tabs>}}


#### C++

{{< tabs id >}}
{{% tab "c" %}}
{{< tabs id >}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        for (int i = 0;; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.contains(y)) {
                return {d[y], i};
            }
            d[x] = i;
        }
    }
};
```
{{% /tab %}}
{{< /tabs>}}

{{% /tab %}}
{{< /tabs>}}


#### Go

```go
func twoSum(nums []int, target int) []int {
	d := map[int]int{}
	for i := 0; ; i++ {
		x := nums[i]
		y := target - x
		if j, ok := d[y]; ok {
			return []int{j, i}
		}
		d[x] = i
	}
}
```

#### TypeScript

```ts
function twoSum(nums: number[], target: number): number[] {
    const d = new Map<number, number>();
    for (let i = 0; ; ++i) {
        const x = nums[i];
        const y = target - x;
        if (d.has(y)) {
            return [d.get(y)!, i];
        }
        d.set(x, i);
    }
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut d = HashMap::new();
        for (i, &x) in nums.iter().enumerate() {
            let y = target - x;
            if let Some(&j) = d.get(&y) {
                return vec![j as i32, i as i32];
            }
            d.insert(x, i);
        }
        vec![]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    const d = new Map();
    for (let i = 0; ; ++i) {
        const x = nums[i];
        const y = target - x;
        if (d.has(y)) {
            return [d.get(y), i];
        }
        d.set(x, i);
    }
};
```

#### C#

{{< tabs id >}}
{{% tab "c" %}}
```cs
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var d = new Dictionary<int, int>();
        for (int i = 0, j; ; ++i) {
            int x = nums[i];
            int y = target - x;
            if (d.TryGetValue(y, out j)) {
                return new [] {j, i};
            }
            if (!d.ContainsKey(x)) {
                d.Add(x, i);
            }
        }
    }
}
```
{{% /tab %}}
{{< /tabs>}}


#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $d = [];
        foreach ($nums as $i => $x) {
            $y = $target - $x;
            if (isset($d[$y])) {
                return [$d[$y], $i];
            }
            $d[$x] = $i;
        }
    }
}
```

#### Scala

```scala
import scala.collection.mutable

object Solution {
    def twoSum(nums: Array[Int], target: Int): Array[Int] = {
        val d = mutable.Map[Int, Int]()
        var ans: Array[Int] = Array()
        for (i <- nums.indices if ans.isEmpty) {
            val x = nums(i)
            val y = target - x
            if (d.contains(y)) {
                ans = Array(d(y), i)
            } else {
                d(x) = i
            }
        }
        ans
    }
}
```

#### Swift

```swift
class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var d = [Int: Int]()
        for (i, x) in nums.enumerated() {
            let y = target - x
            if let j = d[y] {
                return [j, i]
            }
            d[x] = i
        }
        return []
    }
}
```

#### Ruby

```rb
# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    d = {}
    nums.each_with_index do |x, i|
      y = target - x
      if d.key?(y)
        return [d[y], i]
      end
      d[x] = i
    end
end
```

#### Kotlin

```kotlin
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val m = mutableMapOf<Int, Int>()
        nums.forEachIndexed { i, x ->
            val y = target - x
            val j = m.get(y)
            if (j != null) {
                return intArrayOf(j, i)
            }
            m[x] = i
        }
        return intArrayOf()
    }
}
```

#### Nim

```nim
import std/enumerate
import std/tables

proc twoSum(nums: seq[int], target: int): seq[int] =
  var d = initTable[int, int]()
  for i, x in nums.pairs():
    let y = target - x
    if d.hasKey(y):
      return @[d[y], i]
    d[x] = i
  return @[]
```

#### Cangjie

{{< tabs id >}}
{{% tab "c" %}}
```cj
class Solution {
    func twoSum(nums: Array<Int64>, target: Int64): Array<Int64> {
        let d = HashMap<Int64, Int64>()
        for (i in 0..nums.size) {
            if (d.contains(target - nums[i])) {
                return [d[target - nums[i]], i]
            }
            d[nums[i]] = i
        }
        []
    }
}
```
{{% /tab %}}
{{< /tabs>}}


#### C

{{< tabs id >}}
{{% tab "c" %}}
```c
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int capacity = 1;
    while (capacity < numsSize * 2) capacity <<= 1;
    int* keys = malloc(capacity * sizeof(int));
    int* vals = malloc(capacity * sizeof(int));
    char* used = calloc(capacity, sizeof(char));
    if (!keys || !vals || !used) {
        free(keys);
        free(vals);
        free(used);
        *returnSize = 0;
        return NULL;
    }
    for (int i = 0; i < numsSize; ++i) {
        int x = nums[i];
        int y = target - x;
        unsigned int h = (unsigned int) y & (capacity - 1);
        while (used[h]) {
            if (keys[h] == y) {
                int* res = malloc(2 * sizeof(int));
                res[0] = vals[h];
                res[1] = i;
                *returnSize = 2;
                free(keys);
                free(vals);
                free(used);
                return res;
            }
            h = (h + 1) & (capacity - 1);
        }
        unsigned int h2 = (unsigned int) x & (capacity - 1);
        while (used[h2]) h2 = (h2 + 1) & (capacity - 1);
        used[h2] = 1;
        keys[h2] = x;
        vals[h2] = i;
    }
    *returnSize = 0;
    free(keys);
    free(vals);
    free(used);
    return NULL;
}
```
{{% /tab %}}
{{< /tabs>}}


<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{% hint info %}
{% details "python 可视化" %}
{< pythontutor width="100%" height="500" language="python" >}
print("hello")
{< /pythontutor >}
{% /details %}
{% /hint %}
