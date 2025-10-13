---
title: "0021_合并两个有序链表"
date: 2025-10-08T18:34:13+08:00
weight: 3
tags: [位运算, 分治, 动态规划, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 字符串匹配, 归并排序, 数学, 数组, 滑动窗口, 递归, 链表]
---

{{< markmap >}}
### [0021_合并两个有序链表](#21)
#### [递归](#21)
#### [链表](#21)
### [0022_括号生成](#22)
#### [字符串](#22)
#### [动态规划](#22)
#### [回溯](#22)
### [0023_合并 K 个升序链表](#23)
#### [链表](#23)
#### [分治](#23)
#### [堆（优先队列）](#23)
#### [归并排序](#23)
### [0024_两两交换链表中的节点](#24)
#### [递归](#24)
#### [链表](#24)
### [0025_K 个一组翻转链表](#25)
#### [递归](#25)
#### [链表](#25)
### [0026_删除有序数组中的重复项](#26)
#### [数组](#26)
#### [双指针](#26)
### [0027_移除元素](#27)
#### [数组](#27)
#### [双指针](#27)
### [0028_找出字符串中第一个匹配项的下标](#28)
#### [双指针](#28)
#### [字符串](#28)
#### [字符串匹配](#28)
### [0029_两数相除](#29)
#### [位运算](#29)
#### [数学](#29)
### [0030_串联所有单词的子串](#30)
#### [哈希表](#30)
#### [字符串](#30)
#### [滑动窗口](#30)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0021_合并两个有序链表
___
#### 递归
___
#### 链表
---
### 0022_括号生成
___
#### 字符串
___
#### 动态规划
___
#### 回溯
---
### 0023_合并 K 个升序链表
___
#### 链表
___
#### 分治
___
#### 堆（优先队列）
___
#### 归并排序
---
### 0024_两两交换链表中的节点
___
#### 递归
___
#### 链表
---
### 0025_K 个一组翻转链表
___
#### 递归
___
#### 链表
---
### 0026_删除有序数组中的重复项
___
#### 数组
___
#### 双指针
---
### 0027_移除元素
___
#### 数组
___
#### 双指针
---
### 0028_找出字符串中第一个匹配项的下标
___
#### 双指针
___
#### 字符串
___
#### 字符串匹配
---
### 0029_两数相除
___
#### 位运算
___
#### 数学
---
### 0030_串联所有单词的子串
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 分治 | 动态规划 |
| 双指针 | 哈希表 | 回溯 |
| 堆（优先队列） | 字符串 | 字符串匹配 |
| 归并排序 | 数学 | 数组 |
| 滑动窗口 | 递归 | 链表 |

# [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists){#21}

{{< tabs "21" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
        curr.next = list1 or list2
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        curr.next = list1 == null ? list2 : list1;
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	dummy := &ListNode{}
	curr := dummy
	for list1 != nil && list2 != nil {
		if list1.Val <= list2.Val {
			curr.Next = list1
			list1 = list1.Next
		} else {
			curr.Next = list2
			list2 = list2.Next
		}
		curr = curr.Next
	}
	if list1 != nil {
		curr.Next = list1
	} else {
		curr.Next = list2
	}
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    const dummy = new ListNode(0);
    let cur = dummy;
    while (list1 != null && list2 != null) {
        if (list1.val < list2.val) {
            cur.next = list1;
            list1 = list1.next;
        } else {
            cur.next = list2;
            list2 = list2.next;
        }
        cur = cur.next;
    }
    cur.next = list1 || list2;
    return dummy.next;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut new_list = ListNode::new(0);
        let mut cur = &mut new_list;
        while list1.is_some() && list2.is_some() {
            let (l1, l2) = (list1.as_deref_mut().unwrap(), list2.as_deref_mut().unwrap());
            if l1.val < l2.val {
                let next = l1.next.take();
                cur.next = list1.take();
                list1 = next;
            } else {
                let next = l2.next.take();
                cur.next = list2.take();
                list2 = next;
            }
            cur = cur.next.as_deref_mut().unwrap();
        }
        cur.next = list1.or(list2);
        new_list.next
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
    const dummy = new ListNode();
    let curr = dummy;
    while (list1 && list2) {
        if (list1.val <= list2.val) {
            curr.next = list1;
            list1 = list1.next;
        } else {
            curr.next = list2;
            list2 = list2.next;
        }
        curr = curr.next;
    }
    curr.next = list1 || list2;
    return dummy.next;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        curr.next = list1 == null ? list2 : list1;
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} list1
# @param {ListNode} list2
# @return {ListNode}
def merge_two_lists(list1, list2)
    dummy = ListNode.new()
    cur = dummy
    while list1 && list2
        if list1.val <= list2.val
            cur.next = list1
            list1 = list1.next
        else
            cur.next = list2
            list2 = list2.next
        end
        cur = cur.next
    end
    cur.next = list1 || list2
    dummy.next
end
```
{{% /tab %}}
{{% tab "php" %}}
```php
# Definition for singly-linked list.
# class ListNode {
#     public $val;
#     public $next;
#     public function __construct($val = 0, $next = null)
#     {
#         $this->val = $val;
#         $this->next = $next;
#     }
# }
class Solution {
    /**
     * @param ListNode $list1
     * @param ListNode $list2
     * @return ListNode
     */
    function mergeTwoLists($list1, $list2) {
        $dummy = new ListNode(0);
        $current = $dummy;
        while ($list1 != null && $list2 != null) {
            if ($list1->val <= $list2->val) {
                $current->next = $list1;
                $list1 = $list1->next;
            } else {
                $current->next = $list2;
                $list2 = $list2->next;
            }
            $current = $current->next;
        }
        if ($list1 != null) {
            $current->next = $list1;
        } elseif ($list2 != null) {
            $current->next = $list2;
        }
        return $dummy->next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>将两个升序链表合并为一个新的 <strong>升序</strong> 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 </p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0021.Merge%20Two%20Sorted%20Lists/images/merge_ex1.jpg" style="width: 662px; height: 302px;" />
<pre>
<strong>输入：</strong>l1 = [1,2,4], l2 = [1,3,4]
<strong>输出：</strong>[1,1,2,3,4,4]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>l1 = [], l2 = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>l1 = [], l2 = [0]
<strong>输出：</strong>[0]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>两个链表的节点数目范围是 <code>[0, 50]</code></li>
	<li><code>-100 <= Node.val <= 100</code></li>
	<li><code>l1</code> 和 <code>l2</code> 均按 <strong>非递减顺序</strong> 排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们先判断链表 $l_1$ 和 $l_2$ 是否为空，若其中一个为空，则返回另一个链表。否则，我们比较 $l_1$ 和 $l_2$ 的头节点：

-   若 $l_1$ 的头节点的值小于等于 $l_2$ 的头节点的值，则递归调用函数 $mergeTwoLists(l_1.next, l_2)$，并将 $l_1$ 的头节点与返回的链表头节点相连，返回 $l_1$ 的头节点。
-   否则，递归调用函数 $mergeTwoLists(l_1, l_2.next)$，并将 $l_2$ 的头节点与返回的链表头节点相连，返回 $l_2$ 的头节点。

时间复杂度 $O(m + n)$，空间复杂度 $O(m + n)$。其中 $m$ 和 $n$ 分别为两个链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        if list1 is None or list2 is None:
            return list1 or list2
        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        if (list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}
	if list1.Val <= list2.Val {
		list1.Next = mergeTwoLists(list1.Next, list2)
		return list1
	} else {
		list2.Next = mergeTwoLists(list1, list2.Next)
		return list2
	}
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    if (list1 == null || list2 == null) {
        return list1 || list2;
    }
    if (list1.val < list2.val) {
        list1.next = mergeTwoLists(list1.next, list2);
        return list1;
    } else {
        list2.next = mergeTwoLists(list1, list2.next);
        return list2;
    }
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        match (list1, list2) {
            (None, None) => None,
            (Some(list), None) => Some(list),
            (None, Some(list)) => Some(list),
            (Some(mut list1), Some(mut list2)) => {
                if list1.val < list2.val {
                    list1.next = Self::merge_two_lists(list1.next, Some(list2));
                    Some(list1)
                } else {
                    list2.next = Self::merge_two_lists(Some(list1), list2.next);
                    Some(list2)
                }
            }
        }
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
    if (!list1 || !list2) {
        return list1 || list2;
    }
    if (list1.val <= list2.val) {
        list1.next = mergeTwoLists(list1.next, list2);
        return list1;
    } else {
        list2.next = mergeTwoLists(list1, list2.next);
        return list2;
    }
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        if (list1.val <= list2.val) {
            list1.next = MergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = MergeTwoLists(list1, list2.next);
            return list2;
        }
    }
}
```

#### Ruby

```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} list1
# @param {ListNode} list2
# @return {ListNode}
def merge_two_lists(list1, list2)
    if list1.nil?
        return list2
    end
    if list2.nil?
        return list1
    end
    if list1.val <= list2.val
        list1.next = merge_two_lists(list1.next, list2)
        return list1
    else
        list2.next = merge_two_lists(list1, list2.next)
        return list2
    end
end
```

#### PHP

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $list1
     * @param ListNode $list2
     * @return ListNode
     */
    function mergeTwoLists($list1, $list2) {
        if (is_null($list1)) {
            return $list2;
        }
        if (is_null($list2)) {
            return $list1;
        }
        if ($list1->val <= $list2->val) {
            $list1->next = $this->mergeTwoLists($list1->next, $list2);
            return $list1;
        } else {
            $list2->next = $this->mergeTwoLists($list1, $list2->next);
            return $list2;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代

我们也可以用迭代的方式来实现两个排序链表的合并。

我们先定义一个虚拟头节点 $dummy$，然后循环遍历两个链表，比较两个链表的头节点，将较小的节点添加到 $dummy$ 的末尾，直到其中一个链表为空，然后将另一个链表的剩余部分添加到 $dummy$ 的末尾。

最后返回 $dummy.next$ 即可。

时间复杂度 $O(m + n)$，其中 $m$ 和 $n$ 分别为两个链表的长度。忽略答案链表的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()
        curr = dummy
        while list1 and list2:
            if list1.val <= list2.val:
                curr.next = list1
                list1 = list1.next
            else:
                curr.next = list2
                list2 = list2.next
            curr = curr.next
        curr.next = list1 or list2
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        curr.next = list1 == null ? list2 : list1;
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	dummy := &ListNode{}
	curr := dummy
	for list1 != nil && list2 != nil {
		if list1.Val <= list2.Val {
			curr.Next = list1
			list1 = list1.Next
		} else {
			curr.Next = list2
			list2 = list2.Next
		}
		curr = curr.Next
	}
	if list1 != nil {
		curr.Next = list1
	} else {
		curr.Next = list2
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
    const dummy = new ListNode(0);
    let cur = dummy;
    while (list1 != null && list2 != null) {
        if (list1.val < list2.val) {
            cur.next = list1;
            list1 = list1.next;
        } else {
            cur.next = list2;
            list2 = list2.next;
        }
        cur = cur.next;
    }
    cur.next = list1 || list2;
    return dummy.next;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn merge_two_lists(
        mut list1: Option<Box<ListNode>>,
        mut list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        let mut new_list = ListNode::new(0);
        let mut cur = &mut new_list;
        while list1.is_some() && list2.is_some() {
            let (l1, l2) = (list1.as_deref_mut().unwrap(), list2.as_deref_mut().unwrap());
            if l1.val < l2.val {
                let next = l1.next.take();
                cur.next = list1.take();
                list1 = next;
            } else {
                let next = l2.next.take();
                cur.next = list2.take();
                list2 = next;
            }
            cur = cur.next.as_deref_mut().unwrap();
        }
        cur.next = list1.or(list2);
        new_list.next
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
    const dummy = new ListNode();
    let curr = dummy;
    while (list1 && list2) {
        if (list1.val <= list2.val) {
            curr.next = list1;
            list1 = list1.next;
        } else {
            curr.next = list2;
            list2 = list2.next;
        }
        curr = curr.next;
    }
    curr.next = list1 || list2;
    return dummy.next;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        curr.next = list1 == null ? list2 : list1;
        return dummy.next;
    }
}
```

#### Ruby

```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} list1
# @param {ListNode} list2
# @return {ListNode}
def merge_two_lists(list1, list2)
    dummy = ListNode.new()
    cur = dummy
    while list1 && list2
        if list1.val <= list2.val
            cur.next = list1
            list1 = list1.next
        else
            cur.next = list2
            list2 = list2.next
        end
        cur = cur.next
    end
    cur.next = list1 || list2
    dummy.next
end
```

#### PHP

```php
# Definition for singly-linked list.
# class ListNode {
#     public $val;
#     public $next;
#     public function __construct($val = 0, $next = null)
#     {
#         $this->val = $val;
#         $this->next = $next;
#     }
# }
class Solution {
    /**
     * @param ListNode $list1
     * @param ListNode $list2
     * @return ListNode
     */
    function mergeTwoLists($list1, $list2) {
        $dummy = new ListNode(0);
        $current = $dummy;
        while ($list1 != null && $list2 != null) {
            if ($list1->val <= $list2->val) {
                $current->next = $list1;
                $list1 = $list1->next;
            } else {
                $current->next = $list2;
                $list2 = $list2->next;
            }
            $current = $current->next;
        }
        if ($list1 != null) {
            $current->next = $list1;
        } elseif ($list2 != null) {
            $current->next = $list2;
        }
        return $dummy->next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [22. 括号生成](https://leetcode.cn/problems/generate-parentheses){#22}

{{< tabs "22" >}}

{{% tab "python" %}}
```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(l, r, t):
            if l > n or r > n or l < r:
                return
            if l == n and r == n:
                ans.append(t)
                return
            dfs(l + 1, r, t + '(')
            dfs(l, r + 1, t + ')')

        ans = []
        dfs(0, 0, '')
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private int n;

    public List<String> generateParenthesis(int n) {
        this.n = n;
        dfs(0, 0, "");
        return ans;
    }

    private void dfs(int l, int r, String t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.add(t);
            return;
        }
        dfs(l + 1, r, t + "(");
        dfs(l, r + 1, t + ")");
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int l, int r, string t) {
            if (l > n || r > n || l < r) return;
            if (l == n && r == n) {
                ans.push_back(t);
                return;
            }
            dfs(l + 1, r, t + "(");
            dfs(l, r + 1, t + ")");
        };
        dfs(0, 0, "");
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func generateParenthesis(n int) (ans []string) {
	var dfs func(int, int, string)
	dfs = func(l, r int, t string) {
		if l > n || r > n || l < r {
			return
		}
		if l == n && r == n {
			ans = append(ans, t)
			return
		}
		dfs(l+1, r, t+"(")
		dfs(l, r+1, t+")")
	}
	dfs(0, 0, "")
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function generateParenthesis(n: number): string[] {
    if (n === 1) return ['()'];

    return [
        ...new Set(
            generateParenthesis(n - 1).flatMap(s =>
                Array.from(s, (_, i) => s.slice(0, i) + '()' + s.slice(i)),
            ),
        ),
    ];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans = Vec::new();

        fn dfs(ans: &mut Vec<String>, l: i32, r: i32, t: String, n: i32) {
            if l > n || r > n || l < r {
                return;
            }
            if l == n && r == n {
                ans.push(t);
                return;
            }
            dfs(ans, l + 1, r, format!("{}(", t), n);
            dfs(ans, l, r + 1, format!("{})", t), n);
        }

        dfs(&mut ans, 0, 0, String::new(), n);
        ans
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
function generateParenthesis(n) {
    if (n === 1) return ['()'];

    return [
        ...new Set(
            generateParenthesis(n - 1).flatMap(s =>
                Array.from(s, (_, i) => s.slice(0, i) + '()' + s.slice(i)),
            ),
        ),
    ];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private List<string> ans = new List<string>();
    private int n;

    public List<string> GenerateParenthesis(int n) {
        this.n = n;
        Dfs(0, 0, "");
        return ans;
    }

    private void Dfs(int l, int r, string t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.Add(t);
            return;
        }
        Dfs(l + 1, r, t + "(");
        Dfs(l, r + 1, t + ")");
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        $ans = [];

        $dfs = function ($l, $r, $t) use ($n, &$ans, &$dfs) {
            if ($l > $n || $r > $n || $l < $r) {
                return;
            }
            if ($l == $n && $r == $n) {
                $ans[] = $t;
                return;
            }
            $dfs($l + 1, $r, $t . '(');
            $dfs($l, $r + 1, $t . ')');
        };

        $dfs(0, 0, '');
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>数字 <code>n</code>&nbsp;代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 <strong>有效的 </strong>括号组合。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>["((()))","(()())","(())()","()(())","()()()"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>["()"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS + 剪枝

题目中 $n$ 的范围为 $[1, 8]$，因此我们直接通过“暴力搜索 + 剪枝”的方式通过本题。

我们设计一个函数 $dfs(l, r, t)$，其中 $l$ 和 $r$ 分别表示左括号和右括号的数量，而 $t$ 表示当前的括号序列。那么我们可以得到如下的递归结构：

-   如果 $l \gt n$ 或者 $r \gt n$ 或者 $l \lt r$，那么当前括号组合 $t$ 不合法，直接返回；
-   如果 $l = n$ 且 $r = n$，那么当前括号组合 $t$ 合法，将其加入答案数组 `ans` 中，直接返回；
-   我们可以选择添加一个左括号，递归执行 `dfs(l + 1, r, t + "(")`；
-   我们也可以选择添加一个右括号，递归执行 `dfs(l, r + 1, t + ")")`。

时间复杂度 $O(2^{n\times 2} \times n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(l, r, t):
            if l > n or r > n or l < r:
                return
            if l == n and r == n:
                ans.append(t)
                return
            dfs(l + 1, r, t + '(')
            dfs(l, r + 1, t + ')')

        ans = []
        dfs(0, 0, '')
        return ans
```

#### Java

```java
class Solution {
    private List<String> ans = new ArrayList<>();
    private int n;

    public List<String> generateParenthesis(int n) {
        this.n = n;
        dfs(0, 0, "");
        return ans;
    }

    private void dfs(int l, int r, String t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.add(t);
            return;
        }
        dfs(l + 1, r, t + "(");
        dfs(l, r + 1, t + ")");
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int l, int r, string t) {
            if (l > n || r > n || l < r) return;
            if (l == n && r == n) {
                ans.push_back(t);
                return;
            }
            dfs(l + 1, r, t + "(");
            dfs(l, r + 1, t + ")");
        };
        dfs(0, 0, "");
        return ans;
    }
};
```

#### Go

```go
func generateParenthesis(n int) (ans []string) {
	var dfs func(int, int, string)
	dfs = func(l, r int, t string) {
		if l > n || r > n || l < r {
			return
		}
		if l == n && r == n {
			ans = append(ans, t)
			return
		}
		dfs(l+1, r, t+"(")
		dfs(l, r+1, t+")")
	}
	dfs(0, 0, "")
	return ans
}
```

#### TypeScript

```ts
function generateParenthesis(n: number): string[] {
    function dfs(l, r, t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.push(t);
            return;
        }
        dfs(l + 1, r, t + '(');
        dfs(l, r + 1, t + ')');
    }
    let ans = [];
    dfs(0, 0, '');
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut ans = Vec::new();

        fn dfs(ans: &mut Vec<String>, l: i32, r: i32, t: String, n: i32) {
            if l > n || r > n || l < r {
                return;
            }
            if l == n && r == n {
                ans.push(t);
                return;
            }
            dfs(ans, l + 1, r, format!("{}(", t), n);
            dfs(ans, l, r + 1, format!("{})", t), n);
        }

        dfs(&mut ans, 0, 0, String::new(), n);
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    function dfs(l, r, t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.push(t);
            return;
        }
        dfs(l + 1, r, t + '(');
        dfs(l, r + 1, t + ')');
    }
    let ans = [];
    dfs(0, 0, '');
    return ans;
};
```

#### C#

```cs
public class Solution {
    private List<string> ans = new List<string>();
    private int n;

    public List<string> GenerateParenthesis(int n) {
        this.n = n;
        Dfs(0, 0, "");
        return ans;
    }

    private void Dfs(int l, int r, string t) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.Add(t);
            return;
        }
        Dfs(l + 1, r, t + "(");
        Dfs(l, r + 1, t + ")");
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        $ans = [];

        $dfs = function ($l, $r, $t) use ($n, &$ans, &$dfs) {
            if ($l > $n || $r > $n || $l < $r) {
                return;
            }
            if ($l == $n && $r == $n) {
                $ans[] = $t;
                return;
            }
            $dfs($l + 1, $r, $t . '(');
            $dfs($l, $r + 1, $t . ')');
        };

        $dfs(0, 0, '');
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:start -->

### 方法二：递归

<!-- tabs:start -->

#### TypeScript

```ts
function generateParenthesis(n: number): string[] {
    if (n === 1) return ['()'];

    return [
        ...new Set(
            generateParenthesis(n - 1).flatMap(s =>
                Array.from(s, (_, i) => s.slice(0, i) + '()' + s.slice(i)),
            ),
        ),
    ];
}
```

#### JavaScript

```js
function generateParenthesis(n) {
    if (n === 1) return ['()'];

    return [
        ...new Set(
            generateParenthesis(n - 1).flatMap(s =>
                Array.from(s, (_, i) => s.slice(0, i) + '()' + s.slice(i)),
            ),
        ),
    ];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [23. 合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists){#23}

{{< tabs "23" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        setattr(ListNode, "__lt__", lambda a, b: a.val < b.val)
        pq = [head for head in lists if head]
        heapify(pq)
        dummy = cur = ListNode()
        while pq:
            node = heappop(pq)
            if node.next:
                heappush(pq, node.next)
            cur.next = node
            cur = cur.next
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (ListNode head : lists) {
            if (head != null) {
                pq.offer(head);
            }
        }
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            if (node.next != null) {
                pq.offer(node.next);
            }
            cur.next = node;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (auto head : lists) {
            if (head) {
                pq.push(head);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	pq := hp{}
	for _, head := range lists {
		if head != nil {
			pq = append(pq, head)
		}
	}
	heap.Init(&pq)
	dummy := &ListNode{}
	cur := dummy
	for len(pq) > 0 {
		cur.Next = heap.Pop(&pq).(*ListNode)
		cur = cur.Next
		if cur.Next != nil {
			heap.Push(&pq, cur.Next)
		}
	}
	return dummy.Next
}

type hp []*ListNode

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(*ListNode)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    const pq = new MinPriorityQueue({ priority: (node: ListNode) => node.val });
    lists.filter(head => head).forEach(head => pq.enqueue(head));
    const dummy: ListNode = new ListNode();
    let cur: ListNode = dummy;
    while (!pq.isEmpty()) {
        const node = pq.dequeue().element;
        cur.next = node;
        cur = cur.next;
        if (node.next) {
            pq.enqueue(node.next);
        }
    }
    return dummy.next;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::cmp::Ordering;
use std::collections::BinaryHeap;

impl PartialOrd for ListNode {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for ListNode {
    fn cmp(&self, other: &Self) -> Ordering {
        self.val.cmp(&other.val).reverse()
    }
}
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut pq = lists
            .into_iter()
            .filter_map(|head| head)
            .collect::<BinaryHeap<_>>();
        let mut head = None;
        let mut cur = &mut head;
        while let Some(node) = pq.pop() {
            cur = &mut cur.insert(Box::new(ListNode::new(node.val))).next;
            if let Some(next) = node.next {
                pq.push(next);
            }
        }
        head
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
    const pq = new MinPriorityQueue({ priority: node => node.val });
    lists.filter(head => head).forEach(head => pq.enqueue(head));
    const dummy = new ListNode();
    let cur = dummy;
    while (!pq.isEmpty()) {
        const node = pq.dequeue().element;
        cur.next = node;
        cur = cur.next;
        if (node.next) {
            pq.enqueue(node.next);
        }
    }
    return dummy.next;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode, int> pq = new PriorityQueue<ListNode, int>();
        foreach (var head in lists) {
            if (head != null) {
                pq.Enqueue(head, head.val);
            }
        }
        var dummy = new ListNode();
        var cur = dummy;
        while (pq.Count > 0) {
            var node = pq.Dequeue();
            cur.next = node;
            cur = cur.next;
            if (node.next != null) {
                pq.Enqueue(node.next, node.next.val);
            }
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
# Definition for singly-linked list.
class ListNode {
    public $val;
    public $next;
    public function __construct($val = 0, $next = null) {
        $this->val = $val;
        $this->next = $next;
    }
}

class Solution {
    /**
     * @param ListNode[] $lists
     * @return ListNode
     */

    function mergeKLists($lists) {
        $numLists = count($lists);

        if ($numLists === 0) {
            return null;
        }
        while ($numLists > 1) {
            $mid = intval($numLists / 2);
            for ($i = 0; $i < $mid; $i++) {
                $lists[$i] = $this->mergeTwoLists($lists[$i], $lists[$numLists - $i - 1]);
            }
            $numLists = intval(($numLists + 1) / 2);
        }
        return $lists[0];
    }

    function mergeTwoLists($list1, $list2) {
        $dummy = new ListNode(0);
        $current = $dummy;

        while ($list1 != null && $list2 != null) {
            if ($list1->val <= $list2->val) {
                $current->next = $list1;
                $list1 = $list1->next;
            } else {
                $current->next = $list2;
                $list2 = $list2->next;
            }
            $current = $current->next;
        }
        if ($list1 != null) {
            $current->next = $list1;
        } elseif ($list2 != null) {
            $current->next = $list2;
        }
        return $dummy->next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表数组，每个链表都已经按升序排列。</p>

<p>请你将所有链表合并到一个升序链表中，返回合并后的链表。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>lists = [[1,4,5],[1,3,4],[2,6]]
<strong>输出：</strong>[1,1,2,3,4,4,5,6]
<strong>解释：</strong>链表数组如下：
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
将它们合并到一个有序链表中得到。
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>lists = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>lists = [[]]
<strong>输出：</strong>[]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10^4</code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10^4 &lt;= lists[i][j] &lt;= 10^4</code></li>
	<li><code>lists[i]</code> 按 <strong>升序</strong> 排列</li>
	<li><code>lists[i].length</code> 的总和不超过 <code>10^4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们可以创建一个小根堆来 $pq$ 维护所有链表的头节点，每次从小根堆中取出值最小的节点，添加到结果链表的末尾，然后将该节点的下一个节点加入堆中，重复上述步骤直到堆为空。

时间复杂度 $O(n \times \log k)$，空间复杂度 $O(k)$。其中 $n$ 是所有链表节点数目的总和，而 $k$ 是题目给定的链表数目。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        setattr(ListNode, "__lt__", lambda a, b: a.val < b.val)
        pq = [head for head in lists if head]
        heapify(pq)
        dummy = cur = ListNode()
        while pq:
            node = heappop(pq)
            if node.next:
                heappush(pq, node.next)
            cur.next = node
            cur = cur.next
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        for (ListNode head : lists) {
            if (head != null) {
                pq.offer(head);
            }
        }
        ListNode dummy = new ListNode();
        ListNode cur = dummy;
        while (!pq.isEmpty()) {
            ListNode node = pq.poll();
            if (node.next != null) {
                pq.offer(node.next);
            }
            cur.next = node;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (auto head : lists) {
            if (head) {
                pq.push(head);
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	pq := hp{}
	for _, head := range lists {
		if head != nil {
			pq = append(pq, head)
		}
	}
	heap.Init(&pq)
	dummy := &ListNode{}
	cur := dummy
	for len(pq) > 0 {
		cur.Next = heap.Pop(&pq).(*ListNode)
		cur = cur.Next
		if cur.Next != nil {
			heap.Push(&pq, cur.Next)
		}
	}
	return dummy.Next
}

type hp []*ListNode

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(*ListNode)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    const pq = new MinPriorityQueue({ priority: (node: ListNode) => node.val });
    lists.filter(head => head).forEach(head => pq.enqueue(head));
    const dummy: ListNode = new ListNode();
    let cur: ListNode = dummy;
    while (!pq.isEmpty()) {
        const node = pq.dequeue().element;
        cur.next = node;
        cur = cur.next;
        if (node.next) {
            pq.enqueue(node.next);
        }
    }
    return dummy.next;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
use std::cmp::Ordering;
use std::collections::BinaryHeap;

impl PartialOrd for ListNode {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}
impl Ord for ListNode {
    fn cmp(&self, other: &Self) -> Ordering {
        self.val.cmp(&other.val).reverse()
    }
}
impl Solution {
    pub fn merge_k_lists(lists: Vec<Option<Box<ListNode>>>) -> Option<Box<ListNode>> {
        let mut pq = lists
            .into_iter()
            .filter_map(|head| head)
            .collect::<BinaryHeap<_>>();
        let mut head = None;
        let mut cur = &mut head;
        while let Some(node) = pq.pop() {
            cur = &mut cur.insert(Box::new(ListNode::new(node.val))).next;
            if let Some(next) = node.next {
                pq.push(next);
            }
        }
        head
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {
    const pq = new MinPriorityQueue({ priority: node => node.val });
    lists.filter(head => head).forEach(head => pq.enqueue(head));
    const dummy = new ListNode();
    let cur = dummy;
    while (!pq.isEmpty()) {
        const node = pq.dequeue().element;
        cur.next = node;
        cur = cur.next;
        if (node.next) {
            pq.enqueue(node.next);
        }
    }
    return dummy.next;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode, int> pq = new PriorityQueue<ListNode, int>();
        foreach (var head in lists) {
            if (head != null) {
                pq.Enqueue(head, head.val);
            }
        }
        var dummy = new ListNode();
        var cur = dummy;
        while (pq.Count > 0) {
            var node = pq.Dequeue();
            cur.next = node;
            cur = cur.next;
            if (node.next != null) {
                pq.Enqueue(node.next, node.next.val);
            }
        }
        return dummy.next;
    }
}
```

#### PHP

```php
# Definition for singly-linked list.
class ListNode {
    public $val;
    public $next;
    public function __construct($val = 0, $next = null) {
        $this->val = $val;
        $this->next = $next;
    }
}

class Solution {
    /**
     * @param ListNode[] $lists
     * @return ListNode
     */

    function mergeKLists($lists) {
        $numLists = count($lists);

        if ($numLists === 0) {
            return null;
        }
        while ($numLists > 1) {
            $mid = intval($numLists / 2);
            for ($i = 0; $i < $mid; $i++) {
                $lists[$i] = $this->mergeTwoLists($lists[$i], $lists[$numLists - $i - 1]);
            }
            $numLists = intval(($numLists + 1) / 2);
        }
        return $lists[0];
    }

    function mergeTwoLists($list1, $list2) {
        $dummy = new ListNode(0);
        $current = $dummy;

        while ($list1 != null && $list2 != null) {
            if ($list1->val <= $list2->val) {
                $current->next = $list1;
                $list1 = $list1->next;
            } else {
                $current->next = $list2;
                $list2 = $list2->next;
            }
            $current = $current->next;
        }
        if ($list1 != null) {
            $current->next = $list1;
        } elseif ($list2 != null) {
            $current->next = $list2;
        }
        return $dummy->next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs){#24}

{{< tabs "24" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        pre, cur = dummy, head
        while cur and cur.next:
            t = cur.next
            cur.next = t.next
            t.next = cur
            pre.next = t
            pre, cur = cur, cur.next
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            ListNode t = cur.next;
            cur.next = t.next;
            t.next = cur;
            pre.next = t;
            pre = cur;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = cur;
            pre->next = t;
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{Next: head}
	pre, cur := dummy, head
	for cur != nil && cur.Next != nil {
		t := cur.Next
		cur.Next = t.Next
		t.Next = cur
		pre.Next = t
		pre, cur = cur, cur.Next
	}
	return dummy.Next
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function swapPairs(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    let [pre, cur] = [dummy, head];
    while (cur && cur.next) {
        const t = cur.next;
        cur.next = t.next;
        t.next = cur;
        pre.next = t;
        [pre, cur] = [cur, cur.next];
    }
    return dummy.next;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut cur = dummy.as_mut().unwrap();
        while cur.next.is_some() && cur.next.as_ref().unwrap().next.is_some() {
            cur.next = {
                let mut b = cur.next.as_mut().unwrap().next.take();
                cur.next.as_mut().unwrap().next = b.as_mut().unwrap().next.take();
                let a = cur.next.take();
                b.as_mut().unwrap().next = a;
                b
            };
            cur = cur.next.as_mut().unwrap().next.as_mut().unwrap();
        }
        dummy.unwrap().next
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
    const dummy = new ListNode(0, head);
    let [pre, cur] = [dummy, head];
    while (cur && cur.next) {
        const t = cur.next;
        cur.next = t.next;
        t.next = cur;
        pre.next = t;
        [pre, cur] = [cur, cur.next];
    }
    return dummy.next;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur is not null && cur.next is not null) {
            ListNode t = cur.next;
            cur.next = t.next;
            t.next = cur;
            pre.next = t;
            pre = cur;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "rb" %}}
```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)
    dummy = ListNode.new(0, head)
    pre = dummy
    cur = head
    while !cur.nil? && !cur.next.nil?
        t = cur.next
        cur.next = t.next
        t.next = cur
        pre.next = t
        pre = cur
        cur = cur.next
    end
    dummy.next
end
```
{{% /tab %}}
{{% tab "php" %}}
```php
# Definition for singly-linked list.
# class ListNode {
#    public $val;
#    public $next;
#    public function __construct($val = 0, $next = null)
#    {
#        $this->val = $val;
#        $this->next = $next;
#    }
# }

class Solution {
    /**
     * @param ListNode $head
     * @return ListNode
     */

    function swapPairs($head) {
        $dummy = new ListNode(0);
        $dummy->next = $head;
        $prev = $dummy;

        while ($head !== null && $head->next !== null) {
            $first = $head;
            $second = $head->next;

            $first->next = $second->next;
            $second->next = $first;
            $prev->next = $second;

            $prev = $first;
            $head = $first->next;
        }

        return $dummy->next;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0024.Swap%20Nodes%20in%20Pairs/images/swap_ex1.jpg" style="width: 422px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4]
<strong>输出：</strong>[2,1,4,3]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>head = []
<strong>输出：</strong>[]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>head = [1]
<strong>输出：</strong>[1]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>链表中节点的数目在范围 <code>[0, 100]</code> 内</li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：递归

我们可以通过递归的方式实现两两交换链表中的节点。

递归的终止条件是链表中没有节点，或者链表中只有一个节点，此时无法进行交换，直接返回该节点。

否则，我们递归交换链表 $head.next.next$，记交换后的头节点为 $t$，然后我们记 $head$ 的下一个节点为 $p$，然后令 $p$ 指向 $head$，而 $head$ 指向 $t$，最后返回 $p$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 是链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        t = self.swapPairs(head.next.next)
        p = head.next
        p.next = head
        head.next = t
        return p
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode t = swapPairs(head.next.next);
        ListNode p = head.next;
        p.next = head;
        head.next = t;
        return p;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* t = swapPairs(head->next->next);
        ListNode* p = head->next;
        p->next = head;
        head->next = t;
        return p;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	t := swapPairs(head.Next.Next)
	p := head.Next
	p.Next = head
	head.Next = t
	return p
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function swapPairs(head: ListNode | null): ListNode | null {
    if (!head || !head.next) {
        return head;
    }
    const t = swapPairs(head.next.next);
    const p = head.next;
    p.next = head;
    head.next = t;
    return p;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn swap_pairs(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode { val: 0, next: head }));
        let mut cur = dummy.as_mut().unwrap();
        while cur.next.is_some() && cur.next.as_ref().unwrap().next.is_some() {
            cur.next = {
                let mut b = cur.next.as_mut().unwrap().next.take();
                cur.next.as_mut().unwrap().next = b.as_mut().unwrap().next.take();
                let a = cur.next.take();
                b.as_mut().unwrap().next = a;
                b
            };
            cur = cur.next.as_mut().unwrap().next.as_mut().unwrap();
        }
        dummy.unwrap().next
    }
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
    if (!head || !head.next) {
        return head;
    }
    const t = swapPairs(head.next.next);
    const p = head.next;
    p.next = head;
    head.next = t;
    return p;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        if (head is null || head.next is null) {
            return head;
        }
        ListNode t = SwapPairs(head.next.next);
        ListNode p = head.next;
        p.next = head;
        head.next = t;
        return p;
    }
}
```

#### Ruby

```rb
# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end
# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)
    dummy = ListNode.new(0, head)
    pre = dummy
    cur = head
    while !cur.nil? && !cur.next.nil?
        t = cur.next
        cur.next = t.next
        t.next = cur
        pre.next = t
        pre = cur
        cur = cur.next
    end
    dummy.next
end
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：迭代

我们设置一个虚拟头节点 $dummy$，初始时指向 $head$，然后设置两个指针 $pre$ 和 $cur$，初始时 $pre$ 指向 $dummy$，而 $cur$ 指向 $head$。

接下来，我们遍历链表，每次需要交换 $pre$ 后面的两个节点，因此我们先判断 $cur$ 和 $cur.next$ 是否为空，若不为空，则进行交换，否则终止循环。

时间复杂度 $O(n)$，空间复杂度 $O(1)$，其中 $n$ 是链表的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(next=head)
        pre, cur = dummy, head
        while cur and cur.next:
            t = cur.next
            cur.next = t.next
            t.next = cur
            pre.next = t
            pre, cur = cur, cur.next
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            ListNode t = cur.next;
            cur.next = t.next;
            t.next = cur;
            pre.next = t;
            pre = cur;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = cur;
            pre->next = t;
            pre = cur;
            cur = cur->next;
        }
        return dummy->next;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	dummy := &ListNode{Next: head}
	pre, cur := dummy, head
	for cur != nil && cur.Next != nil {
		t := cur.Next
		cur.Next = t.Next
		t.Next = cur
		pre.Next = t
		pre, cur = cur, cur.Next
	}
	return dummy.Next
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function swapPairs(head: ListNode | null): ListNode | null {
    const dummy = new ListNode(0, head);
    let [pre, cur] = [dummy, head];
    while (cur && cur.next) {
        const t = cur.next;
        cur.next = t.next;
        t.next = cur;
        pre.next = t;
        [pre, cur] = [cur, cur.next];
    }
    return dummy.next;
}
```

#### JavaScript

```js
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function (head) {
    const dummy = new ListNode(0, head);
    let [pre, cur] = [dummy, head];
    while (cur && cur.next) {
        const t = cur.next;
        cur.next = t.next;
        t.next = cur;
        pre.next = t;
        [pre, cur] = [cur, cur.next];
    }
    return dummy.next;
};
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode SwapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode pre = dummy;
        ListNode cur = head;
        while (cur is not null && cur.next is not null) {
            ListNode t = cur.next;
            cur.next = t.next;
            t.next = cur;
            pre.next = t;
            pre = cur;
            cur = cur.next;
        }
        return dummy.next;
    }
}
```

#### PHP

```php
# Definition for singly-linked list.
# class ListNode {
#    public $val;
#    public $next;
#    public function __construct($val = 0, $next = null)
#    {
#        $this->val = $val;
#        $this->next = $next;
#    }
# }

class Solution {
    /**
     * @param ListNode $head
     * @return ListNode
     */

    function swapPairs($head) {
        $dummy = new ListNode(0);
        $dummy->next = $head;
        $prev = $dummy;

        while ($head !== null && $head->next !== null) {
            $first = $head;
            $second = $head->next;

            $first->next = $second->next;
            $second->next = $first;
            $prev->next = $second;

            $prev = $first;
            $head = $first->next;
        }

        return $dummy->next;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group){#25}

{{< tabs "25" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            cur = head
            while cur:
                nxt = cur.next
                cur.next = dummy.next
                dummy.next = cur
                cur = nxt
            return dummy.next

        dummy = pre = ListNode(next=head)
        while pre:
            cur = pre
            for _ in range(k):
                cur = cur.next
                if cur is None:
                    return dummy.next
            node = pre.next
            nxt = cur.next
            cur.next = None
            pre.next = reverse(node)
            node.next = nxt
            pre = node
        return dummy.next
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        dummy.next = head;
        ListNode pre = dummy;
        while (pre != null) {
            ListNode cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur.next;
                if (cur == null) {
                    return dummy.next;
                }
            }
            ListNode node = pre.next;
            ListNode nxt = cur.next;
            cur.next = null;
            pre.next = reverse(node);
            node.next = nxt;
            pre = node;
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode cur = head;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = nxt;
        }
        return dummy.next;
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	dummy := &ListNode{Next: head}
	pre := dummy

	for pre != nil {
		cur := pre
		for i := 0; i < k; i++ {
			cur = cur.Next
			if cur == nil {
				return dummy.Next
			}
		}

		node := pre.Next
		nxt := cur.Next
		cur.Next = nil
		pre.Next = reverse(node)
		node.Next = nxt
		pre = node
	}
	return dummy.Next
}

func reverse(head *ListNode) *ListNode {
	var dummy *ListNode
	cur := head
	for cur != nil {
		nxt := cur.Next
		cur.Next = dummy
		dummy = cur
		cur = nxt
	}
	return dummy
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    const dummy = new ListNode(0, head);
    let pre = dummy;
    while (pre !== null) {
        let cur: ListNode | null = pre;
        for (let i = 0; i < k; i++) {
            cur = cur?.next || null;
            if (cur === null) {
                return dummy.next;
            }
        }

        const node = pre.next;
        const nxt = cur?.next || null;
        cur!.next = null;
        pre.next = reverse(node);
        node!.next = nxt;
        pre = node!;
    }

    return dummy.next;
}

function reverse(head: ListNode | null): ListNode | null {
    let dummy: ListNode | null = null;
    let cur = head;

    while (cur !== null) {
        const nxt = cur.next;
        cur.next = dummy;
        dummy = cur;
        cur = nxt;
    }

    return dummy;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        fn reverse(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            let mut head = head;
            let mut pre = None;
            while let Some(mut node) = head {
                head = node.next.take();
                node.next = pre.take();
                pre = Some(node);
            }
            pre
        }

        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut pre = &mut dummy;
        let mut cur = head;
        while cur.is_some() {
            let mut q = &mut cur;
            for _ in 0..k - 1 {
                if q.is_none() {
                    break;
                }
                q = &mut q.as_mut().unwrap().next;
            }
            if q.is_none() {
                pre.as_mut().unwrap().next = cur;
                return dummy.unwrap().next;
            }

            let b = q.as_mut().unwrap().next.take();
            pre.as_mut().unwrap().next = reverse(cur);
            while pre.is_some() && pre.as_mut().unwrap().next.is_some() {
                pre = &mut pre.as_mut().unwrap().next;
            }
            cur = b;
        }
        dummy.unwrap().next
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val = 0, ListNode next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode ReverseKGroup(ListNode head, int k) {
        var dummy = new ListNode(0);
        dummy.next = head;
        var pre = dummy;

        while (pre != null) {
            var cur = pre;
            for (int i = 0; i < k; i++) {
                if (cur.next == null) {
                    return dummy.next;
                }
                cur = cur.next;
            }

            var node = pre.next;
            var nxt = cur.next;
            cur.next = null;
            pre.next = Reverse(node);
            node.next = nxt;
            pre = node;
        }

        return dummy.next;
    }

    private ListNode Reverse(ListNode head) {
        ListNode prev = null;
        var cur = head;
        while (cur != null) {
            var nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode
     */
    function reverseKGroup($head, $k) {
        $dummy = new ListNode(0);
        $dummy->next = $head;
        $pre = $dummy;

        while ($pre !== null) {
            $cur = $pre;
            for ($i = 0; $i < $k; $i++) {
                if ($cur->next === null) {
                    return $dummy->next;
                }
                $cur = $cur->next;
            }

            $node = $pre->next;
            $nxt = $cur->next;
            $cur->next = null;
            $pre->next = $this->reverse($node);
            $node->next = $nxt;
            $pre = $node;
        }

        return $dummy->next;
    }

    /**
     * Helper function to reverse a linked list.
     * @param ListNode $head
     * @return ListNode
     */
    function reverse($head) {
        $prev = null;
        $cur = $head;
        while ($cur !== null) {
            $nxt = $cur->next;
            $cur->next = $prev;
            $prev = $cur;
            $cur = $nxt;
        }
        return $prev;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你链表的头节点 <code>head</code> ，每&nbsp;<code>k</code><em>&nbsp;</em>个节点一组进行翻转，请你返回修改后的链表。</p>

<p><code>k</code> 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是&nbsp;<code>k</code><em>&nbsp;</em>的整数倍，那么请将最后剩余的节点保持原有顺序。</p>

<p>你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0025.Reverse%20Nodes%20in%20k-Group/images/reverse_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 2
<strong>输出：</strong>[2,1,4,3,5]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0000-0099/0025.Reverse%20Nodes%20in%20k-Group/images/reverse_ex2.jpg" style="width: 542px; height: 222px;" /></p>

<pre>
<strong>输入：</strong>head = [1,2,3,4,5], k = 3
<strong>输出：</strong>[3,2,1,4,5]
</pre>

<p>&nbsp;</p>
<strong>提示：</strong>

<ul>
	<li>链表中的节点数目为 <code>n</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以设计一个只用 <code>O(1)</code> 额外内存空间的算法解决此问题吗？</p>

<ul>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以根据题意，模拟整个翻转的过程。

首先，我们定义一个辅助函数 $\textit{reverse}$，用于翻转一个链表。然后，我们定义一个虚拟头结点 $\textit{dummy}$，并将其 $\textit{next}$ 指针指向 $\textit{head}$。

接着，我们遍历链表，每次遍历 $k$ 个节点，若剩余节点不足 $k$ 个，则不进行翻转。否则，我们将 $k$ 个节点取出，然后调用 $\textit{reverse}$ 函数翻转这 $k$ 个节点。然后将翻转后的链表与原链表连接起来。继续遍历下一个 $k$ 个节点，直到遍历完整个链表。

时间复杂度 $O(n)$，其中 $n$ 为链表的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(head: Optional[ListNode]) -> Optional[ListNode]:
            dummy = ListNode()
            cur = head
            while cur:
                nxt = cur.next
                cur.next = dummy.next
                dummy.next = cur
                cur = nxt
            return dummy.next

        dummy = pre = ListNode(next=head)
        while pre:
            cur = pre
            for _ in range(k):
                cur = cur.next
                if cur is None:
                    return dummy.next
            node = pre.next
            nxt = cur.next
            cur.next = None
            pre.next = reverse(node)
            node.next = nxt
            pre = node
        return dummy.next
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0, head);
        dummy.next = head;
        ListNode pre = dummy;
        while (pre != null) {
            ListNode cur = pre;
            for (int i = 0; i < k; i++) {
                cur = cur.next;
                if (cur == null) {
                    return dummy.next;
                }
            }
            ListNode node = pre.next;
            ListNode nxt = cur.next;
            cur.next = null;
            pre.next = reverse(node);
            node.next = nxt;
            pre = node;
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode cur = head;
        while (cur != null) {
            ListNode nxt = cur.next;
            cur.next = dummy.next;
            dummy.next = cur;
            cur = nxt;
        }
        return dummy.next;
    }
}
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	dummy := &ListNode{Next: head}
	pre := dummy

	for pre != nil {
		cur := pre
		for i := 0; i < k; i++ {
			cur = cur.Next
			if cur == nil {
				return dummy.Next
			}
		}

		node := pre.Next
		nxt := cur.Next
		cur.Next = nil
		pre.Next = reverse(node)
		node.Next = nxt
		pre = node
	}
	return dummy.Next
}

func reverse(head *ListNode) *ListNode {
	var dummy *ListNode
	cur := head
	for cur != nil {
		nxt := cur.Next
		cur.Next = dummy
		dummy = cur
		cur = nxt
	}
	return dummy
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
    const dummy = new ListNode(0, head);
    let pre = dummy;
    while (pre !== null) {
        let cur: ListNode | null = pre;
        for (let i = 0; i < k; i++) {
            cur = cur?.next || null;
            if (cur === null) {
                return dummy.next;
            }
        }

        const node = pre.next;
        const nxt = cur?.next || null;
        cur!.next = null;
        pre.next = reverse(node);
        node!.next = nxt;
        pre = node!;
    }

    return dummy.next;
}

function reverse(head: ListNode | null): ListNode | null {
    let dummy: ListNode | null = null;
    let cur = head;

    while (cur !== null) {
        const nxt = cur.next;
        cur.next = dummy;
        dummy = cur;
        cur = nxt;
    }

    return dummy;
}
```

#### Rust

```rust
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_k_group(head: Option<Box<ListNode>>, k: i32) -> Option<Box<ListNode>> {
        fn reverse(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
            let mut head = head;
            let mut pre = None;
            while let Some(mut node) = head {
                head = node.next.take();
                node.next = pre.take();
                pre = Some(node);
            }
            pre
        }

        let mut dummy = Some(Box::new(ListNode::new(0)));
        let mut pre = &mut dummy;
        let mut cur = head;
        while cur.is_some() {
            let mut q = &mut cur;
            for _ in 0..k - 1 {
                if q.is_none() {
                    break;
                }
                q = &mut q.as_mut().unwrap().next;
            }
            if q.is_none() {
                pre.as_mut().unwrap().next = cur;
                return dummy.unwrap().next;
            }

            let b = q.as_mut().unwrap().next.take();
            pre.as_mut().unwrap().next = reverse(cur);
            while pre.is_some() && pre.as_mut().unwrap().next.is_some() {
                pre = &mut pre.as_mut().unwrap().next;
            }
            cur = b;
        }
        dummy.unwrap().next
    }
}
```

#### C#

```cs
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val = 0, ListNode next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode ReverseKGroup(ListNode head, int k) {
        var dummy = new ListNode(0);
        dummy.next = head;
        var pre = dummy;

        while (pre != null) {
            var cur = pre;
            for (int i = 0; i < k; i++) {
                if (cur.next == null) {
                    return dummy.next;
                }
                cur = cur.next;
            }

            var node = pre.next;
            var nxt = cur.next;
            cur.next = null;
            pre.next = Reverse(node);
            node.next = nxt;
            pre = node;
        }

        return dummy.next;
    }

    private ListNode Reverse(ListNode head) {
        ListNode prev = null;
        var cur = head;
        while (cur != null) {
            var nxt = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
}
```

#### PHP

```php
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val = 0, $next = null) {
 *         $this->val = $val;
 *         $this->next = $next;
 *     }
 * }
 */
class Solution {
    /**
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode
     */
    function reverseKGroup($head, $k) {
        $dummy = new ListNode(0);
        $dummy->next = $head;
        $pre = $dummy;

        while ($pre !== null) {
            $cur = $pre;
            for ($i = 0; $i < $k; $i++) {
                if ($cur->next === null) {
                    return $dummy->next;
                }
                $cur = $cur->next;
            }

            $node = $pre->next;
            $nxt = $cur->next;
            $cur->next = null;
            $pre->next = $this->reverse($node);
            $node->next = $nxt;
            $pre = $node;
        }

        return $dummy->next;
    }

    /**
     * Helper function to reverse a linked list.
     * @param ListNode $head
     * @return ListNode
     */
    function reverse($head) {
        $prev = null;
        $cur = $head;
        while ($cur !== null) {
            $nxt = $cur->next;
            $cur->next = $prev;
            $prev = $cur;
            $cur = $nxt;
        }
        return $prev;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array){#26}

{{< tabs "26" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if k == 0 or x != nums[k - 1]:
                nums[k] = x
                k += 1
        return k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeDuplicates(nums []int) int {
	k := 0
	for _, x := range nums {
		if k == 0 || x != nums[k-1] {
			nums[k] = x
			k++
		}
	}
	return k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeDuplicates(nums: number[]): number {
    let k: number = 0;
    for (const x of nums) {
        if (k === 0 || x !== nums[k - 1]) {
            nums[k++] = x;
        }
    }
    return k;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut k = 0;
        for i in 0..nums.len() {
            if k == 0 || nums[i] != nums[k - 1] {
                nums[k] = nums[i];
                k += 1;
            }
        }
        k as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let k = 0;
    for (const x of nums) {
        if (k === 0 || x !== nums[k - 1]) {
            nums[k++] = x;
        }
    }
    return k;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int k = 0;
        foreach (int x in nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $k = 0;
        foreach ($nums as $x) {
            if ($k == 0 || $x != $nums[$k - 1]) {
                $nums[$k++] = $x;
            }
        }
        return $k;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>非严格递增排列</strong> 的数组 <code>nums</code> ，请你<strong><a href="http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank"> 原地</a></strong> 删除重复出现的元素，使每个元素 <strong>只出现一次</strong> ，返回删除后数组的新长度。元素的 <strong>相对顺序</strong> 应该保持 <strong>一致</strong> 。然后返回 <code>nums</code> 中唯一元素的个数。</p>

<p>考虑 <code>nums</code> 的唯一元素的数量为 <code>k</code> ，你需要做以下事情确保你的题解可以被通过：</p>

<ul>
	<li>更改数组 <code>nums</code> ，使 <code>nums</code> 的前 <code>k</code> 个元素包含唯一元素，并按照它们最初在 <code>nums</code> 中出现的顺序排列。<code>nums</code>&nbsp;的其余元素与 <code>nums</code> 的大小不重要。</li>
	<li>返回 <code>k</code>&nbsp;。</li>
</ul>

<p><strong>判题标准:</strong></p>

<p>系统会用下面的代码来测试你的题解:</p>

<pre>
int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i &lt; k; i++) {
    assert nums[i] == expectedNums[i];
}</pre>

<p>如果所有断言都通过，那么您的题解将被 <strong>通过</strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,2]
<strong>输出：</strong>2, nums = [1,2,_]
<strong>解释：</strong>函数应该返回新的长度 <strong><code>2</code></strong> ，并且原数组 <em>nums </em>的前两个元素被修改为 <strong><code>1</code></strong>, <strong><code>2 </code></strong><code>。</code>不需要考虑数组中超出新长度后面的元素。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,0,1,1,1,2,2,3,3,4]
<strong>输出：</strong>5, nums = [0,1,2,3,4]
<strong>解释：</strong>函数应该返回新的长度 <strong><code>5</code></strong> ， 并且原数组 <em>nums </em>的前五个元素被修改为 <strong><code>0</code></strong>, <strong><code>1</code></strong>, <strong><code>2</code></strong>, <strong><code>3</code></strong>, <strong><code>4</code></strong> 。不需要考虑数组中超出新长度后面的元素。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>nums</code> 已按 <strong>非严格递增</strong>&nbsp;排列</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们用一个变量 $k$ 记录当前已经处理好的数组的长度，初始时 $k=0$，表示空数组。

然后我们从左到右遍历数组，对于遍历到的每个元素 $x$，如果 $k=0$ 或者 $x \neq nums[k-1]$，我们就将 $x$ 放到 $nums[k]$ 的位置，然后 $k$ 自增 $1$。否则，$x$ 与 $nums[k-1]$ 相同，我们直接跳过这个元素。继续遍历，直到遍历完整个数组。

这样，当遍历结束时，$nums$ 中前 $k$ 个元素就是我们要求的答案，且 $k$ 就是答案的长度。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组的长度。

补充：

原问题要求最多相同的数字最多出现 $1$ 次，我们可以扩展至相同的数字最多保留 $k$ 个。

-   由于相同的数字最多保留 $k$ 个，那么原数组的前 $k$ 个元素我们可以直接保留；
-   对于后面的数字，能够保留的前提是：当前数字 $x$ 与前面已保留的数字的倒数第 $k$ 个元素比较，不同则保留，相同则跳过。

相似题目：

-   [80. 删除有序数组中的重复项 II](https://github.com/doocs/leetcode/blob/main/solution/0000-0099/0080.Remove%20Duplicates%20from%20Sorted%20Array%20II/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k = 0
        for x in nums:
            if k == 0 or x != nums[k - 1]:
                nums[k] = x
                k += 1
        return k
```

#### Java

```java
class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
};
```

#### Go

```go
func removeDuplicates(nums []int) int {
	k := 0
	for _, x := range nums {
		if k == 0 || x != nums[k-1] {
			nums[k] = x
			k++
		}
	}
	return k
}
```

#### TypeScript

```ts
function removeDuplicates(nums: number[]): number {
    let k: number = 0;
    for (const x of nums) {
        if (k === 0 || x !== nums[k - 1]) {
            nums[k++] = x;
        }
    }
    return k;
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut k = 0;
        for i in 0..nums.len() {
            if k == 0 || nums[i] != nums[k - 1] {
                nums[k] = nums[i];
                k += 1;
            }
        }
        k as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let k = 0;
    for (const x of nums) {
        if (k === 0 || x !== nums[k - 1]) {
            nums[k++] = x;
        }
    }
    return k;
};
```

#### C#

```cs
public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int k = 0;
        foreach (int x in nums) {
            if (k == 0 || x != nums[k - 1]) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $k = 0;
        foreach ($nums as $x) {
            if ($k == 0 || $x != $nums[$k - 1]) {
                $nums[$k++] = $x;
            }
        }
        return $k;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [27. 移除元素](https://leetcode.cn/problems/remove-element){#27}

{{< tabs "27" >}}

{{% tab "python" %}}
```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for x in nums:
            if x != val:
                nums[k] = x
                k += 1
        return k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func removeElement(nums []int, val int) int {
	k := 0
	for _, x := range nums {
		if x != val {
			nums[k] = x
			k++
		}
	}
	return k
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function removeElement(nums: number[], val: number): number {
    let k: number = 0;
    for (const x of nums) {
        if (x !== val) {
            nums[k++] = x;
        }
    }
    return k;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut k = 0;
        for i in 0..nums.len() {
            if nums[i] != val {
                nums[k] = nums[i];
                k += 1;
            }
        }
        k as i32
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let k = 0;
    for (const x of nums) {
        if (x !== val) {
            nums[k++] = x;
        }
    }
    return k;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int k = 0;
        foreach (int x in nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        for ($i = count($nums) - 1; $i >= 0; $i--) {
            if ($nums[$i] == $val) {
                array_splice($nums, $i, 1);
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

<p>给你一个数组 <code>nums</code><em>&nbsp;</em>和一个值 <code>val</code>，你需要 <strong><a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95" target="_blank">原地</a></strong> 移除所有数值等于&nbsp;<code>val</code><em>&nbsp;</em>的元素。元素的顺序可能发生改变。然后返回&nbsp;<code>nums</code>&nbsp;中与&nbsp;<code>val</code>&nbsp;不同的元素的数量。</p>

<p>假设 <code>nums</code> 中不等于 <code>val</code> 的元素数量为 <code>k</code>，要通过此题，您需要执行以下操作：</p>

<ul>
	<li>更改 <code>nums</code> 数组，使 <code>nums</code> 的前 <code>k</code> 个元素包含不等于 <code>val</code> 的元素。<code>nums</code> 的其余元素和 <code>nums</code> 的大小并不重要。</li>
	<li>返回 <code>k</code>。</li>
</ul>

<p><strong>用户评测：</strong></p>

<p>评测机将使用以下代码测试您的解决方案：</p>

<pre>
int[] nums = [...]; // 输入数组
int val = ...; // 要移除的值
int[] expectedNums = [...]; // 长度正确的预期答案。
                            // 它以不等于 val 的值排序。

int k = removeElement(nums, val); // 调用你的实现

assert k == expectedNums.length;
sort(nums, 0, k); // 排序 nums 的前 k 个元素
for (int i = 0; i &lt; actualLength; i++) {
    assert nums[i] == expectedNums[i];
}</pre>

<p>如果所有的断言都通过，你的解决方案将会 <strong>通过</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [3,2,2,3], val = 3
<strong>输出：</strong>2, nums = [2,2,_,_]
<strong>解释：</strong>你的函数函数应该返回 k = 2, 并且 nums<em> </em>中的前两个元素均为 2。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0,1,2,2,3,0,4,2], val = 2
<strong>输出：</strong>5, nums = [0,1,4,0,3,_,_,_]
<strong>解释：</strong>你的函数应该返回 k = 5，并且 nums 中的前五个元素为 0,0,1,3,4。
注意这五个元素可以任意顺序返回。
你在返回的 k 个元素之外留下了什么并不重要（因此它们并不计入评测）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= val &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们用变量 $k$ 记录当前不等于 $val$ 的元素个数。

遍历数组 $nums$，如果当前元素 $x$ 不等于 $val$，则将 $x$ 赋值给 $nums[k]$，并将 $k$ 自增 $1$。

最后返回 $k$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for x in nums:
            if x != val:
                nums[k] = x
                k += 1
        return k
```

#### Java

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int x : nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
};
```

#### Go

```go
func removeElement(nums []int, val int) int {
	k := 0
	for _, x := range nums {
		if x != val {
			nums[k] = x
			k++
		}
	}
	return k
}
```

#### TypeScript

```ts
function removeElement(nums: number[], val: number): number {
    let k: number = 0;
    for (const x of nums) {
        if (x !== val) {
            nums[k++] = x;
        }
    }
    return k;
}
```

#### Rust

```rust
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut k = 0;
        for i in 0..nums.len() {
            if nums[i] != val {
                nums[k] = nums[i];
                k += 1;
            }
        }
        k as i32
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    let k = 0;
    for (const x of nums) {
        if (x !== val) {
            nums[k++] = x;
        }
    }
    return k;
};
```

#### C#

```cs
public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int k = 0;
        foreach (int x in nums) {
            if (x != val) {
                nums[k++] = x;
            }
        }
        return k;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        for ($i = count($nums) - 1; $i >= 0; $i--) {
            if ($nums[$i] == $val) {
                array_splice($nums, $i, 1);
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

# [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string){#28}

{{< tabs "28" >}}

{{% tab "python" %}}
```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i : i + m] == needle:
                return i
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int strStr(String haystack, String needle) {
        if ("".equals(needle)) {
            return 0;
        }

        int len1 = haystack.length();
        int len2 = needle.length();
        int p = 0;
        int q = 0;
        while (p < len1) {
            if (haystack.charAt(p) == needle.charAt(q)) {
                if (len2 == 1) {
                    return p;
                }
                ++p;
                ++q;
            } else {
                p -= q - 1;
                q = 0;
            }

            if (q == len2) {
                return p - q;
            }
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
private:
    vector<int> Next(string str) {
        vector<int> n(str.length());
        n[0] = -1;
        int i = 0, pre = -1;
        int len = str.length();
        while (i < len) {
            while (pre >= 0 && str[i] != str[pre])
                pre = n[pre];
            ++i, ++pre;
            if (i >= len)
                break;
            if (str[i] == str[pre])
                n[i] = n[pre];
            else
                n[i] = pre;
        }
        return n;
    }

public:
    int strStr(string haystack, string needle) {
        if (0 == needle.length())
            return 0;

        vector<int> n(Next(needle));

        int len = haystack.length() - needle.length() + 1;
        for (int i = 0; i < len; ++i) {
            int j = 0, k = i;
            while (j < needle.length() && k < haystack.length()) {
                if (haystack[k] != needle[j]) {
                    if (n[j] >= 0) {
                        j = n[j];
                        continue;
                    } else
                        break;
                }
                ++k, ++j;
            }
            if (j >= needle.length())
                return k - j;
        }

        return -1;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func strStr(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	sha, target, left, right, mod := 0, 0, 0, 0, 1<<31-1
	multi := 1
	for i := 0; i < m; i++ {
		target = (target*256%mod + int(needle[i])) % mod
	}
	for i := 1; i < m; i++ {
		multi = multi * 256 % mod
	}

	for ; right < n; right++ {
		sha = (sha*256%mod + int(haystack[right])) % mod
		if right-left+1 < m {
			continue
		}
		// 此时 left~right 的长度已经为 needle 的长度 m 了，只需要比对 sha 值与 target 是否一致即可
		// 为避免 hash 冲突，还需要确保 haystack[left:right+1] 与 needle 相同
		if sha == target && haystack[left:right+1] == needle {
			return left
		}
		// 未匹配成功，left 右移一位
		sha = (sha - (int(haystack[left])*multi)%mod + mod) % mod
		left++
	}
	return -1
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function strStr(haystack: string, needle: string): number {
    const m = haystack.length;
    const n = needle.length;
    const next = new Array(n).fill(0);
    let j = 0;
    for (let i = 1; i < n; i++) {
        while (j > 0 && needle[i] !== needle[j]) {
            j = next[j - 1];
        }
        if (needle[i] === needle[j]) {
            j++;
        }
        next[i] = j;
    }
    j = 0;
    for (let i = 0; i < m; i++) {
        while (j > 0 && haystack[i] !== needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] === needle[j]) {
            j++;
        }
        if (j === n) {
            return i - n + 1;
        }
    }
    return -1;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let haystack = haystack.as_bytes();
        let needle = needle.as_bytes();
        let m = haystack.len();
        let n = needle.len();
        let mut next = vec![0; n];
        let mut j = 0;
        for i in 1..n {
            while j > 0 && needle[i] != needle[j] {
                j = next[j - 1];
            }
            if needle[i] == needle[j] {
                j += 1;
            }
            next[i] = j;
        }
        j = 0;
        for i in 0..m {
            while j > 0 && haystack[i] != needle[j] {
                j = next[j - 1];
            }
            if haystack[i] == needle[j] {
                j += 1;
            }
            if j == n {
                return (i - n + 1) as i32;
            }
        }
        -1
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    const slen = haystack.length;
    const plen = needle.length;
    if (slen == plen) {
        return haystack == needle ? 0 : -1;
    }
    for (let i = 0; i <= slen - plen; i++) {
        let j;
        for (j = 0; j < plen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == plen) return i;
    }
    return -1;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int StrStr(string haystack, string needle) {
        for (var i = 0; i < haystack.Length - needle.Length + 1; ++i)
        {
            var j = 0;
            for (; j < needle.Length; ++j)
            {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == needle.Length) return i;
        }
        return -1;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        $strNew = str_replace($needle, '+', $haystack);
        $cnt = substr_count($strNew, '+');
        if ($cnt > 0) {
            for ($i = 0; $i < strlen($strNew); $i++) {
                if ($strNew[$i] == '+') {
                    return $i;
                }
            }
        } else {
            return -1;
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

<p>给你两个字符串&nbsp;<code>haystack</code> 和 <code>needle</code> ，请你在 <code>haystack</code> 字符串中找出 <code>needle</code> 字符串的第一个匹配项的下标（下标从 0 开始）。如果&nbsp;<code>needle</code> 不是 <code>haystack</code> 的一部分，则返回&nbsp; <code>-1</code><strong> </strong>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>haystack = "sadbutsad", needle = "sad"
<strong>输出：</strong>0
<strong>解释：</strong>"sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>haystack = "leetcode", needle = "leeto"
<strong>输出：</strong>-1
<strong>解释：</strong>"leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= haystack.length, needle.length &lt;= 10<sup>4</sup></code></li>
	<li><code>haystack</code> 和 <code>needle</code> 仅由小写英文字符组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

以字符串 `haystack` 的每一个字符为起点与字符串 `needle` 进行比较，若发现能够匹配的索引，直接返回即可。

假设字符串 `haystack` 长度为 $n$，字符串 `needle` 长度为 $m$，则时间复杂度为 $O((n-m) \times m)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n, m = len(haystack), len(needle)
        for i in range(n - m + 1):
            if haystack[i : i + m] == needle:
                return i
        return -1
```

#### Java

```java
class Solution {
    public int strStr(String haystack, String needle) {
        if ("".equals(needle)) {
            return 0;
        }

        int len1 = haystack.length();
        int len2 = needle.length();
        int p = 0;
        int q = 0;
        while (p < len1) {
            if (haystack.charAt(p) == needle.charAt(q)) {
                if (len2 == 1) {
                    return p;
                }
                ++p;
                ++q;
            } else {
                p -= q - 1;
                q = 0;
            }

            if (q == len2) {
                return p - q;
            }
        }
        return -1;
    }
}
```

#### C++

```cpp
class Solution {
private:
    vector<int> Next(string str) {
        vector<int> n(str.length());
        n[0] = -1;
        int i = 0, pre = -1;
        int len = str.length();
        while (i < len) {
            while (pre >= 0 && str[i] != str[pre])
                pre = n[pre];
            ++i, ++pre;
            if (i >= len)
                break;
            if (str[i] == str[pre])
                n[i] = n[pre];
            else
                n[i] = pre;
        }
        return n;
    }

public:
    int strStr(string haystack, string needle) {
        if (0 == needle.length())
            return 0;

        vector<int> n(Next(needle));

        int len = haystack.length() - needle.length() + 1;
        for (int i = 0; i < len; ++i) {
            int j = 0, k = i;
            while (j < needle.length() && k < haystack.length()) {
                if (haystack[k] != needle[j]) {
                    if (n[j] >= 0) {
                        j = n[j];
                        continue;
                    } else
                        break;
                }
                ++k, ++j;
            }
            if (j >= needle.length())
                return k - j;
        }

        return -1;
    }
};
```

#### Go

```go
func strStr(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	for i := 0; i <= n-m; i++ {
		if haystack[i:i+m] == needle {
			return i
		}
	}
	return -1
}
```

#### TypeScript

```ts
function strStr(haystack: string, needle: string): number {
    const m = haystack.length;
    const n = needle.length;
    for (let i = 0; i <= m - n; i++) {
        let isEqual = true;
        for (let j = 0; j < n; j++) {
            if (haystack[i + j] !== needle[j]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) {
            return i;
        }
    }
    return -1;
}
```

#### Rust

```rust
impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let haystack = haystack.as_bytes();
        let needle = needle.as_bytes();
        let m = haystack.len();
        let n = needle.len();
        let mut next = vec![0; n];
        let mut j = 0;
        for i in 1..n {
            while j > 0 && needle[i] != needle[j] {
                j = next[j - 1];
            }
            if needle[i] == needle[j] {
                j += 1;
            }
            next[i] = j;
        }
        j = 0;
        for i in 0..m {
            while j > 0 && haystack[i] != needle[j] {
                j = next[j - 1];
            }
            if haystack[i] == needle[j] {
                j += 1;
            }
            if j == n {
                return (i - n + 1) as i32;
            }
        }
        -1
    }
}
```

#### JavaScript

```js
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    const slen = haystack.length;
    const plen = needle.length;
    if (slen == plen) {
        return haystack == needle ? 0 : -1;
    }
    for (let i = 0; i <= slen - plen; i++) {
        let j;
        for (j = 0; j < plen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == plen) return i;
    }
    return -1;
};
```

#### C#

```cs
public class Solution {
    public int StrStr(string haystack, string needle) {
        for (var i = 0; i < haystack.Length - needle.Length + 1; ++i)
        {
            var j = 0;
            for (; j < needle.Length; ++j)
            {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == needle.Length) return i;
        }
        return -1;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $haystack
     * @param String $needle
     * @return Integer
     */
    function strStr($haystack, $needle) {
        $strNew = str_replace($needle, '+', $haystack);
        $cnt = substr_count($strNew, '+');
        if ($cnt > 0) {
            for ($i = 0; $i < strlen($strNew); $i++) {
                if ($strNew[$i] == '+') {
                    return $i;
                }
            }
        } else {
            return -1;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Rabin-Karp 字符串匹配算法

[Rabin-Karp 算法](https://zh.wikipedia.org/zh-hans/%E6%8B%89%E5%AE%BE-%E5%8D%A1%E6%99%AE%E7%AE%97%E6%B3%95)本质上是利用滑动窗口配合哈希函数对固定长度的字符串哈希之后进行比较，可以将比较两个字符串是否相同的时间复杂度降为 $O(1)$。

假设字符串 `haystack` 长度为 $n$，字符串 `needle` 长度为 $m$，则时间复杂度为 $O(n+m)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Go

```go
func strStr(haystack string, needle string) int {
	n, m := len(haystack), len(needle)
	sha, target, left, right, mod := 0, 0, 0, 0, 1<<31-1
	multi := 1
	for i := 0; i < m; i++ {
		target = (target*256%mod + int(needle[i])) % mod
	}
	for i := 1; i < m; i++ {
		multi = multi * 256 % mod
	}

	for ; right < n; right++ {
		sha = (sha*256%mod + int(haystack[right])) % mod
		if right-left+1 < m {
			continue
		}
		// 此时 left~right 的长度已经为 needle 的长度 m 了，只需要比对 sha 值与 target 是否一致即可
		// 为避免 hash 冲突，还需要确保 haystack[left:right+1] 与 needle 相同
		if sha == target && haystack[left:right+1] == needle {
			return left
		}
		// 未匹配成功，left 右移一位
		sha = (sha - (int(haystack[left])*multi)%mod + mod) % mod
		left++
	}
	return -1
}
```

#### TypeScript

```ts
function strStr(haystack: string, needle: string): number {
    const m = haystack.length;
    const n = needle.length;
    const next = new Array(n).fill(0);
    let j = 0;
    for (let i = 1; i < n; i++) {
        while (j > 0 && needle[i] !== needle[j]) {
            j = next[j - 1];
        }
        if (needle[i] === needle[j]) {
            j++;
        }
        next[i] = j;
    }
    j = 0;
    for (let i = 0; i < m; i++) {
        while (j > 0 && haystack[i] !== needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] === needle[j]) {
            j++;
        }
        if (j === n) {
            return i - n + 1;
        }
    }
    return -1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：KMP 字符串匹配算法

假设字符串 `haystack` 长度为 $n$，字符串 `needle` 长度为 $m$，则时间复杂度为 $O(n+m)$，空间复杂度 $O(m)$。

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [29. 两数相除](https://leetcode.cn/problems/divide-two-integers){#29}

{{< tabs "29" >}}

{{% tab "python" %}}
```python
class Solution:
    def divide(self, a: int, b: int) -> int:
        if b == 1:
            return a
        if a == -(2**31) and b == -1:
            return 2**31 - 1
        sign = (a > 0 and b > 0) or (a < 0 and b < 0)
        a = -a if a > 0 else a
        b = -b if b > 0 else b
        ans = 0
        while a <= b:
            x = b
            cnt = 1
            while x >= (-(2**30)) and a <= (x << 1):
                x <<= 1
                cnt <<= 1
            a -= x
            ans += cnt
        return ans if sign else -ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == Integer.MIN_VALUE && b == -1) {
            return Integer.MAX_VALUE;
        }
        boolean sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (Integer.MIN_VALUE >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divide(a int, b int) int {
	if b == 1 {
		return a
	}
	if a == math.MinInt32 && b == -1 {
		return math.MaxInt32
	}

	sign := (a > 0 && b > 0) || (a < 0 && b < 0)
	if a > 0 {
		a = -a
	}
	if b > 0 {
		b = -b
	}
	ans := 0

	for a <= b {
		x := b
		cnt := 1
		for x >= (math.MinInt32>>1) && a <= (x<<1) {
			x <<= 1
			cnt <<= 1
		}
		ans += cnt
		a -= x
	}

	if sign {
		return ans
	}
	return -ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divide(a: number, b: number): number {
    if (b === 1) {
        return a;
    }
    if (a === -(2 ** 31) && b === -1) {
        return 2 ** 31 - 1;
    }

    const sign: boolean = (a > 0 && b > 0) || (a < 0 && b < 0);
    a = a > 0 ? -a : a;
    b = b > 0 ? -b : b;
    let ans: number = 0;

    while (a <= b) {
        let x: number = b;
        let cnt: number = 1;

        while (x >= -(2 ** 30) && a <= x << 1) {
            x <<= 1;
            cnt <<= 1;
        }

        ans += cnt;
        a -= x;
    }

    return sign ? ans : -ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int Divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == int.MinValue && b == -1) {
            return int.MaxValue;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (int.MinValue >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param integer $a
     * @param integer $b
     * @return integer
     */

    function divide($a, $b) {
        if ($b == 0) {
            throw new Exception('Can not divide by 0');
        } elseif ($a == 0) {
            return 0;
        }
        if ($a == -2147483648 && $b == -1) {
            return 2147483647;
        }
        $sign = $a < 0 != $b < 0;

        $a = abs($a);
        $b = abs($b);
        $ans = 0;
        while ($a >= $b) {
            $x = $b;
            $cnt = 1;
            while ($a >= $x << 1) {
                $x <<= 1;
                $cnt <<= 1;
            }
            $a -= $x;
            $ans += $cnt;
        }

        return $sign ? -$ans : $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两个整数，被除数&nbsp;<code>dividend</code>&nbsp;和除数&nbsp;<code>divisor</code>。将两数相除，要求 <strong>不使用</strong> 乘法、除法和取余运算。</p>

<p>整数除法应该向零截断，也就是截去（<code>truncate</code>）其小数部分。例如，<code>8.345</code> 将被截断为 <code>8</code> ，<code>-2.7335</code> 将被截断至 <code>-2</code> 。</p>

<p>返回被除数&nbsp;<code>dividend</code>&nbsp;除以除数&nbsp;<code>divisor</code>&nbsp;得到的 <strong>商</strong> 。</p>

<p><strong>注意：</strong>假设我们的环境只能存储 <strong>32 位</strong> 有符号整数，其数值范围是 <code>[−2<sup>31</sup>,&nbsp; 2<sup>31&nbsp;</sup>− 1]</code> 。本题中，如果商 <strong>严格大于</strong> <code>2<sup>31&nbsp;</sup>− 1</code> ，则返回 <code>2<sup>31&nbsp;</sup>− 1</code> ；如果商 <strong>严格小于</strong> <code>-2<sup>31</sup></code> ，则返回 <code>-2<sup>31</sup></code><sup> </sup>。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> dividend = 10, divisor = 3
<strong>输出:</strong> 3
<strong>解释: </strong>10/3 = 3.33333.. ，向零截断后得到 3 。</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入:</strong> dividend = 7, divisor = -3
<strong>输出:</strong> -2
<strong>解释:</strong> 7/-3 = -2.33333.. ，向零截断后得到 -2 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= dividend, divisor &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>divisor != 0</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟 + 快速幂

除法本质上就是减法，题目要求我们计算出两个数相除之后的取整结果，其实就是计算被除数是多少个除数加上一个小于除数的数构成的。但是一次循环只能做一次减法，效率太低会导致超时，可借助快速幂的思想进行优化。

需要注意的是，由于题目明确要求最大只能使用 32 位有符号整数，所以需要将除数和被除数同时转换为负数进行计算。因为转换正数可能会导致溢出，如当被除数为 `INT32_MIN` 时，转换为正数时会大于 `INT32_MAX`。

假设被除数为 $a$，除数为 $b$，则时间复杂度为 $O(\log a \times \log b)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divide(self, a: int, b: int) -> int:
        if b == 1:
            return a
        if a == -(2**31) and b == -1:
            return 2**31 - 1
        sign = (a > 0 and b > 0) or (a < 0 and b < 0)
        a = -a if a > 0 else a
        b = -b if b > 0 else b
        ans = 0
        while a <= b:
            x = b
            cnt = 1
            while x >= (-(2**30)) and a <= (x << 1):
                x <<= 1
                cnt <<= 1
            a -= x
            ans += cnt
        return ans if sign else -ans
```

#### Java

```java
class Solution {
    public int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == Integer.MIN_VALUE && b == -1) {
            return Integer.MAX_VALUE;
        }
        boolean sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (Integer.MIN_VALUE >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
};
```

#### Go

```go
func divide(a int, b int) int {
	if b == 1 {
		return a
	}
	if a == math.MinInt32 && b == -1 {
		return math.MaxInt32
	}

	sign := (a > 0 && b > 0) || (a < 0 && b < 0)
	if a > 0 {
		a = -a
	}
	if b > 0 {
		b = -b
	}
	ans := 0

	for a <= b {
		x := b
		cnt := 1
		for x >= (math.MinInt32>>1) && a <= (x<<1) {
			x <<= 1
			cnt <<= 1
		}
		ans += cnt
		a -= x
	}

	if sign {
		return ans
	}
	return -ans
}
```

#### TypeScript

```ts
function divide(a: number, b: number): number {
    if (b === 1) {
        return a;
    }
    if (a === -(2 ** 31) && b === -1) {
        return 2 ** 31 - 1;
    }

    const sign: boolean = (a > 0 && b > 0) || (a < 0 && b < 0);
    a = a > 0 ? -a : a;
    b = b > 0 ? -b : b;
    let ans: number = 0;

    while (a <= b) {
        let x: number = b;
        let cnt: number = 1;

        while (x >= -(2 ** 30) && a <= x << 1) {
            x <<= 1;
            cnt <<= 1;
        }

        ans += cnt;
        a -= x;
    }

    return sign ? ans : -ans;
}
```

#### C#

```cs
public class Solution {
    public int Divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == int.MinValue && b == -1) {
            return int.MaxValue;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (int.MinValue >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param integer $a
     * @param integer $b
     * @return integer
     */

    function divide($a, $b) {
        if ($b == 0) {
            throw new Exception('Can not divide by 0');
        } elseif ($a == 0) {
            return 0;
        }
        if ($a == -2147483648 && $b == -1) {
            return 2147483647;
        }
        $sign = $a < 0 != $b < 0;

        $a = abs($a);
        $b = abs($b);
        $ans = 0;
        while ($a >= $b) {
            $x = $b;
            $cnt = 1;
            while ($a >= $x << 1) {
                $x <<= 1;
                $cnt <<= 1;
            }
            $a -= $x;
            $ans += $cnt;
        }

        return $sign ? -$ans : $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [30. 串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words){#30}

{{< tabs "30" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        cnt = Counter(words)
        m, n = len(s), len(words)
        k = len(words[0])
        ans = []
        for i in range(k):
            l = r = i
            cnt1 = Counter()
            while r + k <= m:
                t = s[r : r + k]
                r += k
                if cnt[t] == 0:
                    l = r
                    cnt1.clear()
                    continue
                cnt1[t] += 1
                while cnt1[t] > cnt[t]:
                    rem = s[l : l + k]
                    l += k
                    cnt1[rem] -= 1
                if r - l == n * k:
                    ans.append(l)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (var w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        int m = s.length(), n = words.length, k = words[0].length();
        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            Map<String, Integer> cnt1 = new HashMap<>();
            while (r + k <= m) {
                var t = s.substring(r, r + k);
                r += k;
                if (!cnt.containsKey(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }
                cnt1.merge(t, 1, Integer::sum);
                while (cnt1.get(t) > cnt.get(t)) {
                    String w = s.substring(l, l + k);
                    if (cnt1.merge(w, -1, Integer::sum) == 0) {
                        cnt1.remove(w);
                    }
                    l += k;
                }
                if (r - l == n * k) {
                    ans.add(l);
                }
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
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            cnt[w]++;
        }

        vector<int> ans;
        int m = s.length(), n = words.size(), k = words[0].length();

        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            unordered_map<string, int> cnt1;
            while (r + k <= m) {
                string t = s.substr(r, k);
                r += k;

                if (!cnt.contains(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }

                cnt1[t]++;

                while (cnt1[t] > cnt[t]) {
                    string w = s.substr(l, k);
                    if (--cnt1[w] == 0) {
                        cnt1.erase(w);
                    }
                    l += k;
                }

                if (r - l == n * k) {
                    ans.push_back(l);
                }
            }
        }

        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSubstring(s string, words []string) (ans []int) {
	cnt := make(map[string]int)
	for _, w := range words {
		cnt[w]++
	}
	m, n, k := len(s), len(words), len(words[0])
	for i := 0; i < k; i++ {
		l, r := i, i
		cnt1 := make(map[string]int)
		for r+k <= m {
			t := s[r : r+k]
			r += k

			if _, exists := cnt[t]; !exists {
				cnt1 = make(map[string]int)
				l = r
				continue
			}
			cnt1[t]++
			for cnt1[t] > cnt[t] {
				w := s[l : l+k]
				cnt1[w]--
				if cnt1[w] == 0 {
					delete(cnt1, w)
				}
				l += k
			}
			if r-l == n*k {
				ans = append(ans, l)
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSubstring(s: string, words: string[]): number[] {
    const cnt: Map<string, number> = new Map();
    for (const w of words) {
        cnt.set(w, (cnt.get(w) || 0) + 1);
    }
    const ans: number[] = [];
    const [m, n, k] = [s.length, words.length, words[0].length];
    for (let i = 0; i < k; i++) {
        let [l, r] = [i, i];
        const cnt1: Map<string, number> = new Map();
        while (r + k <= m) {
            const t = s.substring(r, r + k);
            r += k;
            if (!cnt.has(t)) {
                cnt1.clear();
                l = r;
                continue;
            }
            cnt1.set(t, (cnt1.get(t) || 0) + 1);
            while (cnt1.get(t)! > cnt.get(t)!) {
                const w = s.substring(l, l + k);
                cnt1.set(w, cnt1.get(w)! - 1);
                if (cnt1.get(w) === 0) {
                    cnt1.delete(w);
                }
                l += k;
            }
            if (r - l === n * k) {
                ans.push(l);
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<int> FindSubstring(string s, string[] words) {
        var cnt = new Dictionary<string, int>();
        foreach (var w in words) {
            if (cnt.ContainsKey(w)) {
                cnt[w]++;
            } else {
                cnt[w] = 1;
            }
        }

        var ans = new List<int>();
        int m = s.Length, n = words.Length, k = words[0].Length;

        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            var cnt1 = new Dictionary<string, int>();
            while (r + k <= m) {
                var t = s.Substring(r, k);
                r += k;

                if (!cnt.ContainsKey(t)) {
                    cnt1.Clear();
                    l = r;
                    continue;
                }

                if (cnt1.ContainsKey(t)) {
                    cnt1[t]++;
                } else {
                    cnt1[t] = 1;
                }

                while (cnt1[t] > cnt[t]) {
                    var w = s.Substring(l, k);
                    cnt1[w]--;
                    if (cnt1[w] == 0) {
                        cnt1.Remove(w);
                    }
                    l += k;
                }

                if (r - l == n * k) {
                    ans.Add(l);
                }
            }
        }

        return ans;
    }
}
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param String $s
     * @param String[] $words
     * @return Integer[]
     */
    function findSubstring($s, $words) {
        $cnt = [];
        foreach ($words as $w) {
            if (isset($cnt[$w])) {
                $cnt[$w]++;
            } else {
                $cnt[$w] = 1;
            }
        }

        $ans = [];
        $m = strlen($s);
        $n = count($words);
        $k = strlen($words[0]);

        for ($i = 0; $i < $k; $i++) {
            $l = $i;
            $r = $i;
            $cnt1 = [];
            while ($r + $k <= $m) {
                $t = substr($s, $r, $k);
                $r += $k;

                if (!isset($cnt[$t])) {
                    $cnt1 = [];
                    $l = $r;
                    continue;
                }

                if (isset($cnt1[$t])) {
                    $cnt1[$t]++;
                } else {
                    $cnt1[$t] = 1;
                }

                while ($cnt1[$t] > $cnt[$t]) {
                    $w = substr($s, $l, $k);
                    $cnt1[$w]--;
                    if ($cnt1[$w] == 0) {
                        unset($cnt1[$w]);
                    }
                    $l += $k;
                }

                if ($r - $l == $n * $k) {
                    $ans[] = $l;
                }
            }
        }

        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个字符串&nbsp;<code>s</code><strong>&nbsp;</strong>和一个字符串数组&nbsp;<code>words</code><strong>。</strong>&nbsp;<code>words</code>&nbsp;中所有字符串 <strong>长度相同</strong>。</p>

<p>&nbsp;<code>s</code><strong>&nbsp;</strong>中的 <strong>串联子串</strong> 是指一个包含&nbsp;&nbsp;<code>words</code>&nbsp;中所有字符串以任意顺序排列连接起来的子串。</p>

<ul>
	<li>例如，如果&nbsp;<code>words = ["ab","cd","ef"]</code>， 那么&nbsp;<code>"abcdef"</code>，&nbsp;<code>"abefcd"</code>，<code>"cdabef"</code>，&nbsp;<code>"cdefab"</code>，<code>"efabcd"</code>， 和&nbsp;<code>"efcdab"</code> 都是串联子串。&nbsp;<code>"acdbef"</code> 不是串联子串，因为他不是任何&nbsp;<code>words</code>&nbsp;排列的连接。</li>
</ul>

<p>返回所有串联子串在&nbsp;<code>s</code><strong>&nbsp;</strong>中的开始索引。你可以以 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "barfoothefoobarman", words = ["foo","bar"]
<strong>输出：</strong><code>[0,9]</code>
<strong>解释：</strong>因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
输出顺序无关紧要。返回 [9,0] 也是可以的。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
<code><strong>输出：</strong>[]</code>
<strong>解释：</strong>因为<strong> </strong>words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
所以我们返回一个空数组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
<strong>输出：</strong>[6,9,12]
<strong>解释：</strong>因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code>&nbsp;和&nbsp;<code>s</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 滑动窗口

我们用哈希表 $cnt$ 统计 $words$ 中每个单词出现的次数，用哈希表 $cnt1$ 统计当前滑动窗口中每个单词出现的次数。我们记字符串 $s$ 的长度为 $m$，字符串数组 $words$ 中单词的数量为 $n$，每个单词的长度为 $k$。

我们可以枚举滑动窗口的起点 $i$，其中 $0 \lt i \lt k$。对于每个起点，我们维护一个滑动窗口，左边界为 $l$，右边界为 $r$，滑动窗口中的单词个数为 $t$，另外用一个哈希表 $cnt1$ 统计滑动窗口中每个单词出现的次数。

每一次，我们提取字符串 $s[r:r+k]$，如果 $s[r:r+k]$ 不在哈希表 $cnt$ 中，说明当前滑动窗口中的单词不合法，我们将左边界 $l$ 更新为 $r$，同时将哈希表 $cnt1$ 清空，单词个数 $t$ 重置为 0。如果 $s[r:r+k]$ 在哈希表 $cnt$ 中，说明当前滑动窗口中的单词合法，我们将单词个数 $t$ 加 1，将哈希表 $cnt1$ 中 $s[r:r+k]$ 的次数加 1。如果 $cnt1[s[r:r+k]]$ 大于 $cnt[s[r:r+k]]$，说明当前滑动窗口中 $s[r:r+k]$ 出现的次数过多，我们需要将左边界 $l$ 右移，直到 $cnt1[s[r:r+k]] = cnt[s[r:r+k]]$。如果 $t = n$，说明当前滑动窗口中的单词正好合法，我们将左边界 $l$ 加入答案数组。

时间复杂度 $O(m \times k)$，空间复杂度 $O(n \times k)$。其中 $m$ 和 $n$ 分别是字符串 $s$ 和字符串数组 $words$ 的长度，而 $k$ 是字符串数组 $words$ 中单词的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        cnt = Counter(words)
        m, n = len(s), len(words)
        k = len(words[0])
        ans = []
        for i in range(k):
            l = r = i
            cnt1 = Counter()
            while r + k <= m:
                t = s[r : r + k]
                r += k
                if cnt[t] == 0:
                    l = r
                    cnt1.clear()
                    continue
                cnt1[t] += 1
                while cnt1[t] > cnt[t]:
                    rem = s[l : l + k]
                    l += k
                    cnt1[rem] -= 1
                if r - l == n * k:
                    ans.append(l)
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        Map<String, Integer> cnt = new HashMap<>();
        for (var w : words) {
            cnt.merge(w, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        int m = s.length(), n = words.length, k = words[0].length();
        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            Map<String, Integer> cnt1 = new HashMap<>();
            while (r + k <= m) {
                var t = s.substring(r, r + k);
                r += k;
                if (!cnt.containsKey(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }
                cnt1.merge(t, 1, Integer::sum);
                while (cnt1.get(t) > cnt.get(t)) {
                    String w = s.substring(l, l + k);
                    if (cnt1.merge(w, -1, Integer::sum) == 0) {
                        cnt1.remove(w);
                    }
                    l += k;
                }
                if (r - l == n * k) {
                    ans.add(l);
                }
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
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> cnt;
        for (const auto& w : words) {
            cnt[w]++;
        }

        vector<int> ans;
        int m = s.length(), n = words.size(), k = words[0].length();

        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            unordered_map<string, int> cnt1;
            while (r + k <= m) {
                string t = s.substr(r, k);
                r += k;

                if (!cnt.contains(t)) {
                    cnt1.clear();
                    l = r;
                    continue;
                }

                cnt1[t]++;

                while (cnt1[t] > cnt[t]) {
                    string w = s.substr(l, k);
                    if (--cnt1[w] == 0) {
                        cnt1.erase(w);
                    }
                    l += k;
                }

                if (r - l == n * k) {
                    ans.push_back(l);
                }
            }
        }

        return ans;
    }
};
```

#### Go

```go
func findSubstring(s string, words []string) (ans []int) {
	cnt := make(map[string]int)
	for _, w := range words {
		cnt[w]++
	}
	m, n, k := len(s), len(words), len(words[0])
	for i := 0; i < k; i++ {
		l, r := i, i
		cnt1 := make(map[string]int)
		for r+k <= m {
			t := s[r : r+k]
			r += k

			if _, exists := cnt[t]; !exists {
				cnt1 = make(map[string]int)
				l = r
				continue
			}
			cnt1[t]++
			for cnt1[t] > cnt[t] {
				w := s[l : l+k]
				cnt1[w]--
				if cnt1[w] == 0 {
					delete(cnt1, w)
				}
				l += k
			}
			if r-l == n*k {
				ans = append(ans, l)
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function findSubstring(s: string, words: string[]): number[] {
    const cnt: Map<string, number> = new Map();
    for (const w of words) {
        cnt.set(w, (cnt.get(w) || 0) + 1);
    }
    const ans: number[] = [];
    const [m, n, k] = [s.length, words.length, words[0].length];
    for (let i = 0; i < k; i++) {
        let [l, r] = [i, i];
        const cnt1: Map<string, number> = new Map();
        while (r + k <= m) {
            const t = s.substring(r, r + k);
            r += k;
            if (!cnt.has(t)) {
                cnt1.clear();
                l = r;
                continue;
            }
            cnt1.set(t, (cnt1.get(t) || 0) + 1);
            while (cnt1.get(t)! > cnt.get(t)!) {
                const w = s.substring(l, l + k);
                cnt1.set(w, cnt1.get(w)! - 1);
                if (cnt1.get(w) === 0) {
                    cnt1.delete(w);
                }
                l += k;
            }
            if (r - l === n * k) {
                ans.push(l);
            }
        }
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public IList<int> FindSubstring(string s, string[] words) {
        var cnt = new Dictionary<string, int>();
        foreach (var w in words) {
            if (cnt.ContainsKey(w)) {
                cnt[w]++;
            } else {
                cnt[w] = 1;
            }
        }

        var ans = new List<int>();
        int m = s.Length, n = words.Length, k = words[0].Length;

        for (int i = 0; i < k; ++i) {
            int l = i, r = i;
            var cnt1 = new Dictionary<string, int>();
            while (r + k <= m) {
                var t = s.Substring(r, k);
                r += k;

                if (!cnt.ContainsKey(t)) {
                    cnt1.Clear();
                    l = r;
                    continue;
                }

                if (cnt1.ContainsKey(t)) {
                    cnt1[t]++;
                } else {
                    cnt1[t] = 1;
                }

                while (cnt1[t] > cnt[t]) {
                    var w = s.Substring(l, k);
                    cnt1[w]--;
                    if (cnt1[w] == 0) {
                        cnt1.Remove(w);
                    }
                    l += k;
                }

                if (r - l == n * k) {
                    ans.Add(l);
                }
            }
        }

        return ans;
    }
}
```

#### PHP

```php
class Solution {
    /**
     * @param String $s
     * @param String[] $words
     * @return Integer[]
     */
    function findSubstring($s, $words) {
        $cnt = [];
        foreach ($words as $w) {
            if (isset($cnt[$w])) {
                $cnt[$w]++;
            } else {
                $cnt[$w] = 1;
            }
        }

        $ans = [];
        $m = strlen($s);
        $n = count($words);
        $k = strlen($words[0]);

        for ($i = 0; $i < $k; $i++) {
            $l = $i;
            $r = $i;
            $cnt1 = [];
            while ($r + $k <= $m) {
                $t = substr($s, $r, $k);
                $r += $k;

                if (!isset($cnt[$t])) {
                    $cnt1 = [];
                    $l = $r;
                    continue;
                }

                if (isset($cnt1[$t])) {
                    $cnt1[$t]++;
                } else {
                    $cnt1[$t] = 1;
                }

                while ($cnt1[$t] > $cnt[$t]) {
                    $w = substr($s, $l, $k);
                    $cnt1[$w]--;
                    if ($cnt1[$w] == 0) {
                        unset($cnt1[$w]);
                    }
                    $l += $k;
                }

                if ($r - $l == $n * $k) {
                    $ans[] = $l;
                }
            }
        }

        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
