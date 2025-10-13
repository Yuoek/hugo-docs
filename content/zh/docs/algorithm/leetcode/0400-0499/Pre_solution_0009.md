---
title: "0480_滑动窗口中位数"
date: 2025-10-08T18:36:10+08:00
weight: 9
tags: [二分查找, 交互, 动态规划, 博弈, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 数学, 数组, 栈, 滑动窗口, 记忆化搜索, 贪心, 递归]
---

{{< markmap >}}
### [0480_滑动窗口中位数](#480)
#### [数组](#480)
#### [哈希表](#480)
#### [滑动窗口](#480)
#### [堆（优先队列）](#480)
### [0481_神奇字符串](#481)
#### [双指针](#481)
#### [字符串](#481)
### [0482_密钥格式化](#482)
#### [字符串](#482)
### [0483_最小好进制](#483)
#### [数学](#483)
#### [二分查找](#483)
### [0484_寻找排列 🔒](#484)
#### [栈](#484)
#### [贪心](#484)
#### [数组](#484)
#### [字符串](#484)
### [0485_最大连续 1 的个数](#485)
#### [数组](#485)
### [0486_预测赢家](#486)
#### [递归](#486)
#### [数组](#486)
#### [数学](#486)
#### [动态规划](#486)
#### [博弈](#486)
### [0487_最大连续1的个数 II 🔒](#487)
#### [数组](#487)
#### [动态规划](#487)
#### [滑动窗口](#487)
### [0488_祖玛游戏](#488)
#### [栈](#488)
#### [广度优先搜索](#488)
#### [记忆化搜索](#488)
#### [字符串](#488)
#### [动态规划](#488)
### [0489_扫地机器人 🔒](#489)
#### [回溯](#489)
#### [交互](#489)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0480_滑动窗口中位数
___
#### 数组
___
#### 哈希表
___
#### 滑动窗口
___
#### 堆（优先队列）
---
### 0481_神奇字符串
___
#### 双指针
___
#### 字符串
---
### 0482_密钥格式化
___
#### 字符串
---
### 0483_最小好进制
___
#### 数学
___
#### 二分查找
---
### 0484_寻找排列 🔒
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 字符串
---
### 0485_最大连续 1 的个数
___
#### 数组
---
### 0486_预测赢家
___
#### 递归
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 博弈
---
### 0487_最大连续1的个数 II 🔒
___
#### 数组
___
#### 动态规划
___
#### 滑动窗口
---
### 0488_祖玛游戏
___
#### 栈
___
#### 广度优先搜索
___
#### 记忆化搜索
___
#### 字符串
___
#### 动态规划
---
### 0489_扫地机器人 🔒
___
#### 回溯
___
#### 交互
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 交互 | 动态规划 |
| 博弈 | 双指针 | 哈希表 |
| 回溯 | 堆（优先队列） | 字符串 |
| 广度优先搜索 | 数学 | 数组 |
| 栈 | 滑动窗口 | 记忆化搜索 |
| 贪心 | 递归 |  |

# [480. 滑动窗口中位数](https://leetcode.cn/problems/sliding-window-median){#480}

{{< tabs "480" >}}

{{% tab "python" %}}
```python
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        l = SortedList()
        r = SortedList()
        ans = []
        for i, x in enumerate(nums):
            r.add(x)
            l.add(r.pop(0))
            while len(l) - len(r) > 1:
                r.add(l.pop())
            j = i - k + 1
            if j >= 0:
                ans.append(l[-1] if k & 1 else (l[-1] + r[0]) / 2)
                if nums[j] in l:
                    l.remove(nums[j])
                else:
                    r.remove(nums[j])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        TreeMap<Integer, Integer> l = new TreeMap<>();
        TreeMap<Integer, Integer> r = new TreeMap<>();
        int n = nums.length;
        double[] ans = new double[n - k + 1];
        int lSize = 0, rSize = 0;
        for (int i = 0; i < n; ++i) {
            r.merge(nums[i], 1, Integer::sum);
            int x = r.firstKey();
            if (r.merge(x, -1, Integer::sum) == 0) {
                r.remove(x);
            }
            l.merge(x, 1, Integer::sum);
            ++lSize;
            while (lSize - rSize > 1) {
                x = l.lastKey();
                if (l.merge(x, -1, Integer::sum) == 0) {
                    l.remove(x);
                }
                r.merge(x, 1, Integer::sum);
                --lSize;
                ++rSize;
            }
            int j = i - k + 1;
            if (j >= 0) {
                ans[j] = k % 2 == 1 ? l.lastKey() : ((double) l.lastKey() + r.firstKey()) / 2;
                if (l.containsKey(nums[j])) {
                    if (l.merge(nums[j], -1, Integer::sum) == 0) {
                        l.remove(nums[j]);
                    }
                    --lSize;
                } else {
                    if (r.merge(nums[j], -1, Integer::sum) == 0) {
                        r.remove(nums[j]);
                    }
                    --rSize;
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
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> l, r;
        int n = nums.size();
        vector<double> ans;
        for (int i = 0; i < n; ++i) {
            r.insert(nums[i]);
            l.insert(*r.begin());
            r.erase(r.begin());
            while (l.size() - r.size() > 1) {
                r.insert(*l.rbegin());
                l.erase(prev(l.end()));
            }
            int j = i - k + 1;
            if (j >= 0) {
                ans.push_back(k % 2 ? *l.rbegin() : ((double) *l.rbegin() + *r.begin()) / 2);
                auto it = l.find(nums[j]);
                if (it != l.end()) {
                    l.erase(it);
                } else {
                    r.erase(r.find(nums[j]));
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
func medianSlidingWindow(nums []int, k int) (ans []float64) {
	l := redblacktree.New[int, int]()
	r := redblacktree.New[int, int]()
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}
	lSize, rSize := 0, 0
	for i, x := range nums {
		merge(r, x, 1)
		x = r.Left().Key
		merge(r, x, -1)
		merge(l, x, 1)
		lSize++
		for lSize-rSize > 1 {
			x = l.Right().Key
			merge(l, x, -1)
			merge(r, x, 1)
			lSize--
			rSize++
		}
		if j := i - k + 1; j >= 0 {
			if k%2 == 1 {
				ans = append(ans, float64(l.Right().Key))
			} else {
				ans = append(ans, float64(l.Right().Key+r.Left().Key)/2)
			}
			if x = nums[j]; x <= l.Right().Key {
				merge(l, x, -1)
				lSize--
			} else {
				merge(r, x, -1)
				rSize--
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function medianSlidingWindow(nums: number[], k: number): number[] {
    const l = new TreapMultiSet<number>((a, b) => a - b);
    const r = new TreapMultiSet<number>((a, b) => a - b);
    const n = nums.length;
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        r.add(nums[i]);
        l.add(r.shift()!);
        while (l.size - r.size > 1) {
            r.add(l.pop()!);
        }
        const j = i - k + 1;
        if (j >= 0) {
            ans[j] = k % 2 ? l.last()! : (l.last()! + r.first()!) / 2;
            if (nums[j] <= l.last()!) {
                l.delete(nums[j]);
            } else {
                r.delete(nums[j]);
            }
        }
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。</p>

<p>例如：</p>

<ul>
	<li><code>[2,3,4]</code>，中位数是 <code>3</code></li>
	<li><code>[2,3]</code>，中位数是 <code>(2 + 3) / 2 = 2.5</code></li>
</ul>

<p>给你一个数组 <em>nums</em>，有一个长度为 <em>k</em> 的窗口从最左端滑动到最右端。窗口中有 <em>k</em> 个数，每次窗口向右移动 <em>1</em> 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。</p>

<p> </p>

<p><strong>示例：</strong></p>

<p>给出 <em>nums</em> = <code>[1,3,-1,-3,5,3,6,7]</code>，以及 <em>k</em> = 3。</p>

<pre>
窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
</pre>

<p> 因此，返回该滑动窗口的中位数数组 <code>[1,-1,-1,3,5,6]</code>。</p>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li>你可以假设 <code>k</code> 始终有效，即：<code>k</code> 始终小于等于输入的非空数组的元素个数。</li>
	<li>与真实值误差在 <code>10 ^ -5</code> 以内的答案将被视作正确答案。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双优先队列（大小根堆） + 延迟删除

我们可以使用两个优先队列（大小根堆）维护当前窗口中的元素，其中一个优先队列存储当前窗口中较小的一半元素，另一个优先队列存储当前窗口中较大的一半元素。这样，当前窗口的中位数就是两个优先队列的堆顶元素的平均值或其中的一个。

我们设计一个类 $\textit{MedianFinder}$，用于维护当前窗口中的元素。该类包含以下方法：

-   `add_num(num)`：将 $\textit{num}$ 加入当前窗口中。
-   `find_median()`：返回当前窗口中元素的中位数。
-   `remove_num(num)`：将 $\textit{num}$ 从当前窗口中移除。
-   `prune(pq)`：如果堆顶元素在延迟删除字典 $\textit{delayed}$ 中，则将其从堆顶弹出，并从该元素的延迟删除次数中减一。如果该元素的延迟删除次数为零，则将其从延迟删除字典中删除。
-   `rebalance()`：如果较小的一半元素的数量比较大的一半元素的数量多 $2$ 个，则将较大的一半元素的堆顶元素加入较小的一半元素中；如果较小的一半元素的数量比较大的一半元素的数量少，则将较大的一半元素的堆顶元素加入较小的一半元素中。

在 `add_num(num)` 方法中，我们先考虑将 $\textit{num}$ 加入较小的一半元素中，如果 $\textit{num}$ 大于较大的一半元素的堆顶元素，则将 $\textit{num}$ 加入较大的一半元素中。然后我们调用 `rebalance()` 方法，使得两个优先队列的大小之差不超过 $1$。

在 `remove_num(num)` 方法中，我们将 $\textit{num}$ 的延迟删除次数加一。然后我们将 $\textit{num}$ 与较小的一半元素的堆顶元素进行比较，如果 $\textit{num}$ 小于等于较小的一半元素的堆顶元素，则更新较小的一半元素的大小，并且调用 `prune()` 方法，使得较小的一半元素的堆顶元素不在延迟删除字典中。否则，我们更新较大的一半元素的大小，并且调用 `prune()` 方法，使得较大的一半元素的堆顶元素不在延迟删除字典中。

在 `find_median()` 方法中，如果当前窗口的大小为奇数，则返回较小的一半元素的堆顶元素；否则，返回较小的一半元素的堆顶元素与较大的一半元素的堆顶元素的平均值。

在 `prune(pq)` 方法中，如果堆顶元素在延迟删除字典中，则将其从堆顶弹出，并从该元素的延迟删除次数中减一。如果该元素的延迟删除次数为零，则将其从延迟删除字典中删除。

在 `rebalance()` 方法中，如果较小的一半元素的数量比较大的一半元素的数量多 $2$ 个，则将较大的一半元素的堆顶元素加入较小的一半元素中；如果较小的一半元素的数量比较大的一半元素的数量少，则将较大的一半元素的堆顶元素加入较小的一半元素中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class MedianFinder:
    def __init__(self, k: int):
        self.k = k
        self.small = []
        self.large = []
        self.delayed = defaultdict(int)
        self.small_size = 0
        self.large_size = 0

    def add_num(self, num: int):
        if not self.small or num <= -self.small[0]:
            heappush(self.small, -num)
            self.small_size += 1
        else:
            heappush(self.large, num)
            self.large_size += 1
        self.rebalance()

    def find_median(self) -> float:
        return -self.small[0] if self.k & 1 else (-self.small[0] + self.large[0]) / 2

    def remove_num(self, num: int):
        self.delayed[num] += 1
        if num <= -self.small[0]:
            self.small_size -= 1
            if num == -self.small[0]:
                self.prune(self.small)
        else:
            self.large_size -= 1
            if num == self.large[0]:
                self.prune(self.large)
        self.rebalance()

    def prune(self, pq: List[int]):
        sign = -1 if pq is self.small else 1
        while pq and sign * pq[0] in self.delayed:
            self.delayed[sign * pq[0]] -= 1
            if self.delayed[sign * pq[0]] == 0:
                self.delayed.pop(sign * pq[0])
            heappop(pq)

    def rebalance(self):
        if self.small_size > self.large_size + 1:
            heappush(self.large, -heappop(self.small))
            self.small_size -= 1
            self.large_size += 1
            self.prune(self.small)
        elif self.small_size < self.large_size:
            heappush(self.small, -heappop(self.large))
            self.large_size -= 1
            self.small_size += 1
            self.prune(self.large)


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        finder = MedianFinder(k)
        for x in nums[:k]:
            finder.add_num(x)
        ans = [finder.find_median()]
        for i in range(k, len(nums)):
            finder.add_num(nums[i])
            finder.remove_num(nums[i - k])
            ans.append(finder.find_median())
        return ans
```

#### Java

```java
class MedianFinder {
    private PriorityQueue<Integer> small = new PriorityQueue<>(Comparator.reverseOrder());
    private PriorityQueue<Integer> large = new PriorityQueue<>();
    private Map<Integer, Integer> delayed = new HashMap<>();
    private int smallSize;
    private int largeSize;
    private int k;

    public MedianFinder(int k) {
        this.k = k;
    }

    public void addNum(int num) {
        if (small.isEmpty() || num <= small.peek()) {
            small.offer(num);
            ++smallSize;
        } else {
            large.offer(num);
            ++largeSize;
        }
        rebalance();
    }

    public double findMedian() {
        return (k & 1) == 1 ? small.peek() : ((double) small.peek() + large.peek()) / 2;
    }

    public void removeNum(int num) {
        delayed.merge(num, 1, Integer::sum);
        if (num <= small.peek()) {
            --smallSize;
            if (num == small.peek()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.peek()) {
                prune(large);
            }
        }
        rebalance();
    }

    private void prune(PriorityQueue<Integer> pq) {
        while (!pq.isEmpty() && delayed.containsKey(pq.peek())) {
            if (delayed.merge(pq.peek(), -1, Integer::sum) == 0) {
                delayed.remove(pq.peek());
            }
            pq.poll();
        }
    }

    private void rebalance() {
        if (smallSize > largeSize + 1) {
            large.offer(small.poll());
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < largeSize) {
            small.offer(large.poll());
            --largeSize;
            ++smallSize;
            prune(large);
        }
    }
}

class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        MedianFinder finder = new MedianFinder(k);
        for (int i = 0; i < k; ++i) {
            finder.addNum(nums[i]);
        }
        int n = nums.length;
        double[] ans = new double[n - k + 1];
        ans[0] = finder.findMedian();
        for (int i = k; i < n; ++i) {
            finder.addNum(nums[i]);
            finder.removeNum(nums[i - k]);
            ans[i - k + 1] = finder.findMedian();
        }
        return ans;
    }
}
```

#### C++

```cpp
class MedianFinder {
public:
    MedianFinder(int k) {
        this->k = k;
    }

    void addNum(int num) {
        if (small.empty() || num <= small.top()) {
            small.push(num);
            ++smallSize;
        } else {
            large.push(num);
            ++largeSize;
        }
        reblance();
    }

    void removeNum(int num) {
        ++delayed[num];
        if (num <= small.top()) {
            --smallSize;
            if (num == small.top()) {
                prune(small);
            }
        } else {
            --largeSize;
            if (num == large.top()) {
                prune(large);
            }
        }
        reblance();
    }

    double findMedian() {
        return k & 1 ? small.top() : ((double) small.top() + large.top()) / 2.0;
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;
    int smallSize = 0;
    int largeSize = 0;
    int k;

    template <typename T>
    void prune(T& pq) {
        while (!pq.empty() && delayed[pq.top()]) {
            if (--delayed[pq.top()] == 0) {
                delayed.erase(pq.top());
            }
            pq.pop();
        }
    }

    void reblance() {
        if (smallSize > largeSize + 1) {
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        } else if (smallSize < largeSize) {
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            prune(large);
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianFinder finder(k);
        for (int i = 0; i < k; ++i) {
            finder.addNum(nums[i]);
        }
        vector<double> ans = {finder.findMedian()};
        for (int i = k; i < nums.size(); ++i) {
            finder.addNum(nums[i]);
            finder.removeNum(nums[i - k]);
            ans.push_back(finder.findMedian());
        }
        return ans;
    }
};
```

#### Go

```go
type MedianFinder struct {
	small                hp
	large                hp
	delayed              map[int]int
	smallSize, largeSize int
	k                    int
}

func Constructor(k int) MedianFinder {
	return MedianFinder{hp{}, hp{}, map[int]int{}, 0, 0, k}
}

func (this *MedianFinder) AddNum(num int) {
	if this.small.Len() == 0 || num <= -this.small.IntSlice[0] {
		heap.Push(&this.small, -num)
		this.smallSize++
	} else {
		heap.Push(&this.large, num)
		this.largeSize++
	}
	this.rebalance()
}

func (this *MedianFinder) FindMedian() float64 {
	if this.k&1 == 1 {
		return float64(-this.small.IntSlice[0])
	}
	return float64(-this.small.IntSlice[0]+this.large.IntSlice[0]) / 2
}

func (this *MedianFinder) removeNum(num int) {
	this.delayed[num]++
	if num <= -this.small.IntSlice[0] {
		this.smallSize--
		if num == -this.small.IntSlice[0] {
			this.prune(&this.small)
		}
	} else {
		this.largeSize--
		if num == this.large.IntSlice[0] {
			this.prune(&this.large)
		}
	}
	this.rebalance()
}

func (this *MedianFinder) prune(pq *hp) {
	sign := 1
	if pq == &this.small {
		sign = -1
	}
	for pq.Len() > 0 && this.delayed[sign*pq.IntSlice[0]] > 0 {
		this.delayed[sign*pq.IntSlice[0]]--
		if this.delayed[sign*pq.IntSlice[0]] == 0 {
			delete(this.delayed, sign*pq.IntSlice[0])
		}
		heap.Pop(pq)
	}
}

func (this *MedianFinder) rebalance() {
	if this.smallSize > this.largeSize+1 {
		heap.Push(&this.large, -heap.Pop(&this.small).(int))
		this.smallSize--
		this.largeSize++
		this.prune(&this.small)
	} else if this.smallSize < this.largeSize {
		heap.Push(&this.small, -heap.Pop(&this.large).(int))
		this.smallSize++
		this.largeSize--
		this.prune(&this.large)
	}
}

func medianSlidingWindow(nums []int, k int) []float64 {
	finder := Constructor(k)
	for _, num := range nums[:k] {
		finder.AddNum(num)
	}
	ans := []float64{finder.FindMedian()}
	for i := k; i < len(nums); i++ {
		finder.AddNum(nums[i])
		finder.removeNum(nums[i-k])
		ans = append(ans, finder.FindMedian())
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool { return h.IntSlice[i] < h.IntSlice[j] }
func (h *hp) Push(v any)        { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() any {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：有序集合

我们可以用两个有序集合来维护当前窗口中的元素，其中有序集合 $l$ 存储当前窗口中较小的一半元素，有序集合 $r$ 存储当前窗口中较大的一半元素。

遍历数组 $\textit{nums}$，对于每个元素 $x$，我们将其加入有序集合 $r$，然后将有序集合 $r$ 的最小值加入有序集合 $l$。如果有序集合 $l$ 的大小比有序集合 $r$ 的大小大于 $1$，我们将有序集合 $l$ 的最大值加入有序集合 $r$。

如果当前窗口元素总数为 $k$，大小为奇数，则有序集合 $l$ 的最大值就是中位数；如果当前窗口的大小为偶数，则有序集合 $l$ 的最大值和有序集合 $r$ 的最小值的平均值就是中位数。然后，我们将窗口的最左边元素移除，继续遍历数组。

时间复杂度 $O(n \log k)$，空间复杂度 $O(k)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        l = SortedList()
        r = SortedList()
        ans = []
        for i, x in enumerate(nums):
            r.add(x)
            l.add(r.pop(0))
            while len(l) - len(r) > 1:
                r.add(l.pop())
            j = i - k + 1
            if j >= 0:
                ans.append(l[-1] if k & 1 else (l[-1] + r[0]) / 2)
                if nums[j] in l:
                    l.remove(nums[j])
                else:
                    r.remove(nums[j])
        return ans
```

#### Java

```java
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        TreeMap<Integer, Integer> l = new TreeMap<>();
        TreeMap<Integer, Integer> r = new TreeMap<>();
        int n = nums.length;
        double[] ans = new double[n - k + 1];
        int lSize = 0, rSize = 0;
        for (int i = 0; i < n; ++i) {
            r.merge(nums[i], 1, Integer::sum);
            int x = r.firstKey();
            if (r.merge(x, -1, Integer::sum) == 0) {
                r.remove(x);
            }
            l.merge(x, 1, Integer::sum);
            ++lSize;
            while (lSize - rSize > 1) {
                x = l.lastKey();
                if (l.merge(x, -1, Integer::sum) == 0) {
                    l.remove(x);
                }
                r.merge(x, 1, Integer::sum);
                --lSize;
                ++rSize;
            }
            int j = i - k + 1;
            if (j >= 0) {
                ans[j] = k % 2 == 1 ? l.lastKey() : ((double) l.lastKey() + r.firstKey()) / 2;
                if (l.containsKey(nums[j])) {
                    if (l.merge(nums[j], -1, Integer::sum) == 0) {
                        l.remove(nums[j]);
                    }
                    --lSize;
                } else {
                    if (r.merge(nums[j], -1, Integer::sum) == 0) {
                        r.remove(nums[j]);
                    }
                    --rSize;
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
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> l, r;
        int n = nums.size();
        vector<double> ans;
        for (int i = 0; i < n; ++i) {
            r.insert(nums[i]);
            l.insert(*r.begin());
            r.erase(r.begin());
            while (l.size() - r.size() > 1) {
                r.insert(*l.rbegin());
                l.erase(prev(l.end()));
            }
            int j = i - k + 1;
            if (j >= 0) {
                ans.push_back(k % 2 ? *l.rbegin() : ((double) *l.rbegin() + *r.begin()) / 2);
                auto it = l.find(nums[j]);
                if (it != l.end()) {
                    l.erase(it);
                } else {
                    r.erase(r.find(nums[j]));
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func medianSlidingWindow(nums []int, k int) (ans []float64) {
	l := redblacktree.New[int, int]()
	r := redblacktree.New[int, int]()
	merge := func(st *redblacktree.Tree[int, int], x, v int) {
		c, _ := st.Get(x)
		if c+v == 0 {
			st.Remove(x)
		} else {
			st.Put(x, c+v)
		}
	}
	lSize, rSize := 0, 0
	for i, x := range nums {
		merge(r, x, 1)
		x = r.Left().Key
		merge(r, x, -1)
		merge(l, x, 1)
		lSize++
		for lSize-rSize > 1 {
			x = l.Right().Key
			merge(l, x, -1)
			merge(r, x, 1)
			lSize--
			rSize++
		}
		if j := i - k + 1; j >= 0 {
			if k%2 == 1 {
				ans = append(ans, float64(l.Right().Key))
			} else {
				ans = append(ans, float64(l.Right().Key+r.Left().Key)/2)
			}
			if x = nums[j]; x <= l.Right().Key {
				merge(l, x, -1)
				lSize--
			} else {
				merge(r, x, -1)
				rSize--
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function medianSlidingWindow(nums: number[], k: number): number[] {
    const l = new TreapMultiSet<number>((a, b) => a - b);
    const r = new TreapMultiSet<number>((a, b) => a - b);
    const n = nums.length;
    const ans: number[] = [];
    for (let i = 0; i < n; ++i) {
        r.add(nums[i]);
        l.add(r.shift()!);
        while (l.size - r.size > 1) {
            r.add(l.pop()!);
        }
        const j = i - k + 1;
        if (j >= 0) {
            ans[j] = k % 2 ? l.last()! : (l.last()! + r.first()!) / 2;
            if (nums[j] <= l.last()!) {
                l.delete(nums[j]);
            } else {
                r.delete(nums[j]);
            }
        }
    }
    return ans;
}

type CompareFunction<T, R extends 'number' | 'boolean'> = (
    a: T,
    b: T,
) => R extends 'number' ? number : boolean;

interface ITreapMultiSet<T> extends Iterable<T> {
    add: (...value: T[]) => this;
    has: (value: T) => boolean;
    delete: (value: T) => void;

    bisectLeft: (value: T) => number;
    bisectRight: (value: T) => number;

    indexOf: (value: T) => number;
    lastIndexOf: (value: T) => number;

    at: (index: number) => T | undefined;
    first: () => T | undefined;
    last: () => T | undefined;

    lower: (value: T) => T | undefined;
    higher: (value: T) => T | undefined;
    floor: (value: T) => T | undefined;
    ceil: (value: T) => T | undefined;

    shift: () => T | undefined;
    pop: (index?: number) => T | undefined;

    count: (value: T) => number;

    keys: () => IterableIterator<T>;
    values: () => IterableIterator<T>;
    rvalues: () => IterableIterator<T>;
    entries: () => IterableIterator<[number, T]>;

    readonly size: number;
}

class TreapNode<T = number> {
    value: T;
    count: number;
    size: number;
    priority: number;
    left: TreapNode<T> | null;
    right: TreapNode<T> | null;

    constructor(value: T) {
        this.value = value;
        this.count = 1;
        this.size = 1;
        this.priority = Math.random();
        this.left = null;
        this.right = null;
    }

    static getSize(node: TreapNode<any> | null): number {
        return node?.size ?? 0;
    }

    static getFac(node: TreapNode<any> | null): number {
        return node?.priority ?? 0;
    }

    pushUp(): void {
        let tmp = this.count;
        tmp += TreapNode.getSize(this.left);
        tmp += TreapNode.getSize(this.right);
        this.size = tmp;
    }

    rotateRight(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const left = node.left;
        node.left = left?.right ?? null;
        left && (left.right = node);
        left && (node = left);
        node.right?.pushUp();
        node.pushUp();
        return node;
    }

    rotateLeft(): TreapNode<T> {
        // eslint-disable-next-line @typescript-eslint/no-this-alias
        let node: TreapNode<T> = this;
        const right = node.right;
        node.right = right?.left ?? null;
        right && (right.left = node);
        right && (node = right);
        node.left?.pushUp();
        node.pushUp();
        return node;
    }
}

class TreapMultiSet<T = number> implements ITreapMultiSet<T> {
    private readonly root: TreapNode<T>;
    private readonly compareFn: CompareFunction<T, 'number'>;
    private readonly leftBound: T;
    private readonly rightBound: T;

    constructor(compareFn?: CompareFunction<T, 'number'>);
    constructor(compareFn: CompareFunction<T, 'number'>, leftBound: T, rightBound: T);
    constructor(
        compareFn: CompareFunction<T, any> = (a: any, b: any) => a - b,
        leftBound: any = -Infinity,
        rightBound: any = Infinity,
    ) {
        this.root = new TreapNode<T>(rightBound);
        this.root.priority = Infinity;
        this.root.left = new TreapNode<T>(leftBound);
        this.root.left.priority = -Infinity;
        this.root.pushUp();

        this.leftBound = leftBound;
        this.rightBound = rightBound;
        this.compareFn = compareFn;
    }

    get size(): number {
        return this.root.size - 2;
    }

    get height(): number {
        const getHeight = (node: TreapNode<T> | null): number => {
            if (node == null) return 0;
            return 1 + Math.max(getHeight(node.left), getHeight(node.right));
        };

        return getHeight(this.root);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns true if value is a member.
     */
    has(value: T): boolean {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): boolean => {
            if (node == null) return false;
            if (compare(node.value, value) === 0) return true;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Add value to sorted set.
     */
    add(...values: T[]): this {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;
            if (compare(node.value, value) === 0) {
                node.count++;
                node.pushUp();
            } else if (compare(node.value, value) > 0) {
                if (node.left) {
                    dfs(node.left, value, node, 'left');
                } else {
                    node.left = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.left) > node.priority) {
                    parent[direction] = node.rotateRight();
                }
            } else if (compare(node.value, value) < 0) {
                if (node.right) {
                    dfs(node.right, value, node, 'right');
                } else {
                    node.right = new TreapNode(value);
                    node.pushUp();
                }

                if (TreapNode.getFac(node.right) > node.priority) {
                    parent[direction] = node.rotateLeft();
                }
            }
            parent.pushUp();
        };

        values.forEach(value => dfs(this.root.left, value, this.root, 'left'));
        return this;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Remove value from sorted set if it is a member.
     * If value is not a member, do nothing.
     */
    delete(value: T): void {
        const compare = this.compareFn;
        const dfs = (
            node: TreapNode<T> | null,
            value: T,
            parent: TreapNode<T>,
            direction: 'left' | 'right',
        ): void => {
            if (node == null) return;

            if (compare(node.value, value) === 0) {
                if (node.count > 1) {
                    node.count--;
                    node?.pushUp();
                } else if (node.left == null && node.right == null) {
                    parent[direction] = null;
                } else {
                    // 旋到根节点
                    if (
                        node.right == null ||
                        TreapNode.getFac(node.left) > TreapNode.getFac(node.right)
                    ) {
                        parent[direction] = node.rotateRight();
                        dfs(parent[direction]?.right ?? null, value, parent[direction]!, 'right');
                    } else {
                        parent[direction] = node.rotateLeft();
                        dfs(parent[direction]?.left ?? null, value, parent[direction]!, 'left');
                    }
                }
            } else if (compare(node.value, value) > 0) {
                dfs(node.left, value, node, 'left');
            } else if (compare(node.value, value) < 0) {
                dfs(node.right, value, node, 'right');
            }

            parent?.pushUp();
        };

        dfs(this.root.left, value, this.root, 'left');
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the left of) any existing values.
     */
    bisectLeft(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns an index to insert value in the sorted set.
     * If the value is already present, the insertion point will be before (to the right of) any existing values.
     */
    bisectRight(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                return TreapNode.getSize(node.left) + node.count;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        return dfs(this.root, value) - 1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the first occurrence of a value in the set, or -1 if it is not present.
     */
    indexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left);
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };
        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the index of the last occurrence of a value in the set, or -1 if it is not present.
     */
    lastIndexOf(value: T): number {
        const compare = this.compareFn;
        let isExist = false;

        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;

            if (compare(node.value, value) === 0) {
                isExist = true;
                return TreapNode.getSize(node.left) + node.count - 1;
            } else if (compare(node.value, value) > 0) {
                return dfs(node.left, value);
            } else if (compare(node.value, value) < 0) {
                return dfs(node.right, value) + TreapNode.getSize(node.left) + node.count;
            }

            return 0;
        };

        const res = dfs(this.root, value) - 1;
        return isExist ? res : -1;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Returns the item located at the specified index.
     * @param index The zero-based index of the desired code unit. A negative index will count back from the last item.
     */
    at(index: number): T | undefined {
        if (index < 0) index += this.size;
        if (index < 0 || index >= this.size) return undefined;

        const dfs = (node: TreapNode<T> | null, rank: number): T | undefined => {
            if (node == null) return undefined;

            if (TreapNode.getSize(node.left) >= rank) {
                return dfs(node.left, rank);
            } else if (TreapNode.getSize(node.left) + node.count >= rank) {
                return node.value;
            } else {
                return dfs(node.right, rank - TreapNode.getSize(node.left) - node.count);
            }
        };

        const res = dfs(this.root, index + 2);
        return ([this.leftBound, this.rightBound] as any[]).includes(res) ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than `val`, return `undefined` if no such element found.
     */
    lower(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than `val`, return `undefined` if no such element found.
     */
    higher(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element less than or equal to `val`, return `undefined` if no such element found.
     */
    floor(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) >= 0) return dfs(node.left, value);

            const tmp = dfs(node.right, value);
            if (tmp == null || compare(node.value, tmp) > 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.leftBound ? undefined : res;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description Find and return the element greater than or equal to `val`, return `undefined` if no such element found.
     */
    ceil(value: T): T | undefined {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): T | undefined => {
            if (node == null) return undefined;
            if (compare(node.value, value) === 0) return node.value;
            if (compare(node.value, value) <= 0) return dfs(node.right, value);

            const tmp = dfs(node.left, value);

            if (tmp == null || compare(node.value, tmp) < 0) {
                return node.value;
            } else {
                return tmp;
            }
        };

        const res = dfs(this.root, value) as any;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned.
     */
    first(): T | undefined {
        const iter = this.inOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.rightBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Returns the last element from set.
     * If the set is empty, undefined is returned .
     */
    last(): T | undefined {
        const iter = this.reverseInOrder();
        iter.next();
        const res = iter.next().value;
        return res === this.leftBound ? undefined : res;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the first element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    shift(): T | undefined {
        const first = this.first();
        if (first === undefined) return undefined;
        this.delete(first);
        return first;
    }

    /**
     * @complexity `O(logn)`
     * @description
     * Removes the last element from an set and returns it.
     * If the set is empty, undefined is returned and the set is not modified.
     */
    pop(index?: number): T | undefined {
        if (index == null) {
            const last = this.last();
            if (last === undefined) return undefined;
            this.delete(last);
            return last;
        }

        const toDelete = this.at(index);
        if (toDelete == null) return;
        this.delete(toDelete);
        return toDelete;
    }

    /**
     *
     * @complexity `O(logn)`
     * @description
     * Returns number of occurrences of value in the sorted set.
     */
    count(value: T): number {
        const compare = this.compareFn;
        const dfs = (node: TreapNode<T> | null, value: T): number => {
            if (node == null) return 0;
            if (compare(node.value, value) === 0) return node.count;
            if (compare(node.value, value) < 0) return dfs(node.right, value);
            return dfs(node.left, value);
        };

        return dfs(this.root, value);
    }

    *[Symbol.iterator](): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of keys in the set.
     */
    *keys(): Generator<T, any, any> {
        yield* this.values();
    }

    /**
     * @description
     * Returns an iterable of values in the set.
     */
    *values(): Generator<T, any, any> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns a generator for reversed order traversing the set.
     */
    *rvalues(): Generator<T, any, any> {
        const iter = this.reverseInOrder();
        iter.next();
        const steps = this.size;
        for (let _ = 0; _ < steps; _++) {
            yield iter.next().value;
        }
    }

    /**
     * @description
     * Returns an iterable of key, value pairs for every entry in the set.
     */
    *entries(): IterableIterator<[number, T]> {
        const iter = this.inOrder();
        iter.next();
        const steps = this.size;
        for (let i = 0; i < steps; i++) {
            yield [i, iter.next().value];
        }
    }

    private *inOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.inOrder(root.left);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.inOrder(root.right);
    }

    private *reverseInOrder(root: TreapNode<T> | null = this.root): Generator<T, any, any> {
        if (root == null) return;
        yield* this.reverseInOrder(root.right);
        const count = root.count;
        for (let _ = 0; _ < count; _++) {
            yield root.value;
        }
        yield* this.reverseInOrder(root.left);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [481. 神奇字符串](https://leetcode.cn/problems/magical-string){#481}

{{< tabs "481" >}}

{{% tab "python" %}}
```python
class Solution:
    def magicalString(self, n: int) -> int:
        s = [1, 2, 2]
        i = 2
        while len(s) < n:
            pre = s[-1]
            cur = 3 - pre
            # cur 表示这一组的数字，s[i] 表示这一组数字出现的次数
            s += [cur] * s[i]
            i += 1
        return s[:n].count(1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int magicalString(int n) {
        List<Integer> s = new ArrayList<>(List.of(1, 2, 2));
        for (int i = 2; s.size() < n; ++i) {
            int pre = s.get(s.size() - 1);
            int cur = 3 - pre;
            for (int j = 0; j < s.get(i); ++j) {
                s.add(cur);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s.get(i) == 1) {
                ++ans;
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
    int magicalString(int n) {
        vector<int> s = {1, 2, 2};
        for (int i = 2; s.size() < n; ++i) {
            int pre = s.back();
            int cur = 3 - pre;
            for (int j = 0; j < s[i]; ++j) {
                s.emplace_back(cur);
            }
        }
        return count(s.begin(), s.begin() + n, 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func magicalString(n int) (ans int) {
	s := []int{1, 2, 2}
	for i := 2; len(s) < n; i++ {
		pre := s[len(s)-1]
		cur := 3 - pre
		for j := 0; j < s[i]; j++ {
			s = append(s, cur)
		}
	}
	for _, c := range s[:n] {
		if c == 1 {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function magicalString(n: number): number {
    const s: number[] = [1, 2, 2];
    for (let i = 2; s.length < n; ++i) {
        let pre = s[s.length - 1];
        let cur = 3 - pre;
        for (let j = 0; j < s[i]; ++j) {
            s.push(cur);
        }
    }
    return s.slice(0, n).filter(x => x === 1).length;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn magical_string(n: i32) -> i32 {
        let mut s = vec![1, 2, 2];
        let mut i = 2;

        while s.len() < n as usize {
            let pre = s[s.len() - 1];
            let cur = 3 - pre;
            for _ in 0..s[i] {
                s.push(cur);
            }
            i += 1;
        }

        s.iter().take(n as usize).filter(|&&x| x == 1).count() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>神奇字符串 <code>s</code> 仅由 <code>'1'</code> 和 <code>'2'</code> 组成，并需要遵守下面的规则：</p>

<ul>
	<li>神奇字符串 s 的神奇之处在于，串联字符串中 <code>'1'</code> 和 <code>'2'</code> 的连续出现次数可以生成该字符串。</li>
</ul>

<p><code>s</code> 的前几个元素是 <code>s = "1221121221221121122……"</code> 。如果将 <code>s</code> 中连续的若干 <code>1</code> 和 <code>2</code> 进行分组，可以得到 <code>"1 22 11 2 1 22 1 22 11 2 11 22 ......"</code> 。每组中 <code>1</code> 或者 <code>2</code> 的出现次数分别是 <code>"1 2 2 1 1 2 1 2 2 1 2 2 ......"</code> 。上面的出现次数正是 <code>s</code> 自身。</p>

<p>给你一个整数 <code>n</code> ，返回在神奇字符串 <code>s</code> 的前 <code>n</code> 个数字中 <code>1</code> 的数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 6
<strong>输出：</strong>3
<strong>解释：</strong>神奇字符串 s 的前 6 个元素是 “<code>122112</code>”，它包含三个 1，因此返回 3 。 
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 1
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟构造过程

根据题目，我们得知，字符串 $s$ 的每一组数字都可以由字符串 $s$ 自身的数字得到。

字符串 $s$ 前两组数字为 $1$ 和 $22$，是由字符串 $s$ 的第一个数字 $1$ 和第二个数字 $2$ 得到的，并且第一组数字只包含 $1$，第二组数字只包含 $2$，第三组数字只包含 $1$，以此类推。

由于前两组数字已知，我们初始化字符串 $s$ 为 $122$，然后从第三组开始构造，第三组数字是由字符串 $s$ 的第三个数字（下标 $i=2$）得到，因此我们此时将指针 $i$ 指向字符串 $s$ 的第三个数字 $2$。

```
1 2 2
    ^
    i
```

指针 $i$ 指向的数字为 $2$，表示第三组的数字会出现两次，并且，由于前一组数字为 $2$，组之间数字交替出现，因此第三组数字为两个 $1$，即 $11$。构造后，指针 $i$ 移动到下一个位置，即指向字符串 $s$ 的第四个数字 $1$。

```
1 2 2 1 1
      ^
      i
```

这时候指针 $i$ 指向的数字为 $1$，表示第四组的数字会出现一次，并且，由于前一组数字为 $1$，组之间数字交替出现，因此第四组数字为一个 $2$，即 $2$。构造后，指针 $i$ 移动到下一个位置，即指向字符串 $s$ 的第五个数字 $1$。

```
1 2 2 1 1 2
        ^
        i
```

我们按照这个规则，依次模拟构造过程，直到字符串 $s$ 的长度大于等于 $n$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def magicalString(self, n: int) -> int:
        s = [1, 2, 2]
        i = 2
        while len(s) < n:
            pre = s[-1]
            cur = 3 - pre
            # cur 表示这一组的数字，s[i] 表示这一组数字出现的次数
            s += [cur] * s[i]
            i += 1
        return s[:n].count(1)
```

#### Java

```java
class Solution {
    public int magicalString(int n) {
        List<Integer> s = new ArrayList<>(List.of(1, 2, 2));
        for (int i = 2; s.size() < n; ++i) {
            int pre = s.get(s.size() - 1);
            int cur = 3 - pre;
            for (int j = 0; j < s.get(i); ++j) {
                s.add(cur);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s.get(i) == 1) {
                ++ans;
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
    int magicalString(int n) {
        vector<int> s = {1, 2, 2};
        for (int i = 2; s.size() < n; ++i) {
            int pre = s.back();
            int cur = 3 - pre;
            for (int j = 0; j < s[i]; ++j) {
                s.emplace_back(cur);
            }
        }
        return count(s.begin(), s.begin() + n, 1);
    }
};
```

#### Go

```go
func magicalString(n int) (ans int) {
	s := []int{1, 2, 2}
	for i := 2; len(s) < n; i++ {
		pre := s[len(s)-1]
		cur := 3 - pre
		for j := 0; j < s[i]; j++ {
			s = append(s, cur)
		}
	}
	for _, c := range s[:n] {
		if c == 1 {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function magicalString(n: number): number {
    const s: number[] = [1, 2, 2];
    for (let i = 2; s.length < n; ++i) {
        let pre = s[s.length - 1];
        let cur = 3 - pre;
        for (let j = 0; j < s[i]; ++j) {
            s.push(cur);
        }
    }
    return s.slice(0, n).filter(x => x === 1).length;
}
```

#### Rust

```rust
impl Solution {
    pub fn magical_string(n: i32) -> i32 {
        let mut s = vec![1, 2, 2];
        let mut i = 2;

        while s.len() < n as usize {
            let pre = s[s.len() - 1];
            let cur = 3 - pre;
            for _ in 0..s[i] {
                s.push(cur);
            }
            i += 1;
        }

        s.iter().take(n as usize).filter(|&&x| x == 1).count() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [482. 密钥格式化](https://leetcode.cn/problems/license-key-formatting){#482}

{{< tabs "482" >}}

{{% tab "python" %}}
```python
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        n = len(s)
        cnt = (n - s.count("-")) % k or k
        ans = []
        for i, c in enumerate(s):
            if c == "-":
                continue
            ans.append(c.upper())
            cnt -= 1
            if cnt == 0:
                cnt = k
                if i != n - 1:
                    ans.append("-")
        return "".join(ans).rstrip("-")
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int n = s.length();
        int cnt = (int) (n - s.chars().filter(ch -> ch == '-').count()) % k;
        if (cnt == 0) {
            cnt = k;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '-') {
                continue;
            }
            ans.append(Character.toUpperCase(c));
            --cnt;
            if (cnt == 0) {
                cnt = k;
                if (i != n - 1) {
                    ans.append('-');
                }
            }
        }
        if (ans.length() > 0 && ans.charAt(ans.length() - 1) == '-') {
            ans.deleteCharAt(ans.length() - 1);
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        int cnt = (n - count(s.begin(), s.end(), '-')) % k;
        if (cnt == 0) {
            cnt = k;
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '-') {
                continue;
            }
            ans += toupper(c);
            if (--cnt == 0) {
                cnt = k;
                if (i != n - 1) {
                    ans += '-';
                }
            }
        }
        if (!ans.empty() && ans.back() == '-') {
            ans.pop_back();
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func licenseKeyFormatting(s string, k int) string {
	n := len(s)
	cnt := (n - strings.Count(s, "-")) % k
	if cnt == 0 {
		cnt = k
	}

	var ans strings.Builder
	for i := 0; i < n; i++ {
		c := s[i]
		if c == '-' {
			continue
		}
		if cnt == 0 {
			cnt = k
			ans.WriteByte('-')
		}
		ans.WriteRune(unicode.ToUpper(rune(c)))
		cnt--
	}

	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function licenseKeyFormatting(s: string, k: number): string {
    const n = s.length;
    let cnt = (n - (s.match(/-/g) || []).length) % k || k;
    const ans: string[] = [];
    for (let i = 0; i < n; i++) {
        const c = s[i];
        if (c === '-') {
            continue;
        }
        ans.push(c.toUpperCase());
        if (--cnt === 0) {
            cnt = k;
            if (i !== n - 1) {
                ans.push('-');
            }
        }
    }
    while (ans.at(-1) === '-') {
        ans.pop();
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个许可密钥字符串 <code>s</code>，仅由字母、数字字符和破折号组成。字符串由 <code>n</code> 个破折号分成 <code>n + 1</code> 组。你也会得到一个整数 <code>k</code> 。</p>

<p>我们想要重新格式化字符串&nbsp;<code>s</code>，使每一组包含 <code>k</code> 个字符，除了第一组，它可以比 <code>k</code> 短，但仍然必须包含至少一个字符。此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。</p>

<p>返回 <em>重新格式化的许可密钥</em> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>S = "5F3Z-2e-9-w", k = 4
<strong>输出：</strong>"5F3Z-2E9W"
<strong>解释：</strong>字符串 S 被分成了两个部分，每部分 4 个字符；
&nbsp;    注意，两个额外的破折号需要删掉。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>S = "2-5g-3-J", k = 2
<strong>输出：</strong>"2-5G-3J"
<strong>解释：</strong>字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含字母、数字和破折号&nbsp;<code>'-'</code>.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先统计出字符串 $s$ 中除去破折号之外的字符个数，并对 $k$ 取模，得到第一组字符的个数。如果为 $0$，则第一组字符个数为 $k$，否则为取模的结果。

接着我们遍历字符串 $s$，对于每个字符，如果是破折号，则跳过；否则将其转换为大写字母，并将其加入答案字符串中。同时，我们维护一个计数器 $cnt$，表示当前组还剩余的字符个数，当 $cnt$ 减为 $0$ 时，我们需要更新 $cnt$ 为 $k$，并且如果当前字符不是最后一个字符，我们需要在答案字符串中加入一个破折号。

最后，我们移除答案字符串末尾的破折号，并返回答案字符串。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        n = len(s)
        cnt = (n - s.count("-")) % k or k
        ans = []
        for i, c in enumerate(s):
            if c == "-":
                continue
            ans.append(c.upper())
            cnt -= 1
            if cnt == 0:
                cnt = k
                if i != n - 1:
                    ans.append("-")
        return "".join(ans).rstrip("-")
```

#### Java

```java
class Solution {
    public String licenseKeyFormatting(String s, int k) {
        int n = s.length();
        int cnt = (int) (n - s.chars().filter(ch -> ch == '-').count()) % k;
        if (cnt == 0) {
            cnt = k;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '-') {
                continue;
            }
            ans.append(Character.toUpperCase(c));
            --cnt;
            if (cnt == 0) {
                cnt = k;
                if (i != n - 1) {
                    ans.append('-');
                }
            }
        }
        if (ans.length() > 0 && ans.charAt(ans.length() - 1) == '-') {
            ans.deleteCharAt(ans.length() - 1);
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        int cnt = (n - count(s.begin(), s.end(), '-')) % k;
        if (cnt == 0) {
            cnt = k;
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '-') {
                continue;
            }
            ans += toupper(c);
            if (--cnt == 0) {
                cnt = k;
                if (i != n - 1) {
                    ans += '-';
                }
            }
        }
        if (!ans.empty() && ans.back() == '-') {
            ans.pop_back();
        }
        return ans;
    }
};
```

#### Go

```go
func licenseKeyFormatting(s string, k int) string {
	n := len(s)
	cnt := (n - strings.Count(s, "-")) % k
	if cnt == 0 {
		cnt = k
	}

	var ans strings.Builder
	for i := 0; i < n; i++ {
		c := s[i]
		if c == '-' {
			continue
		}
		if cnt == 0 {
			cnt = k
			ans.WriteByte('-')
		}
		ans.WriteRune(unicode.ToUpper(rune(c)))
		cnt--
	}

	return ans.String()
}
```

#### TypeScript

```ts
function licenseKeyFormatting(s: string, k: number): string {
    const n = s.length;
    let cnt = (n - (s.match(/-/g) || []).length) % k || k;
    const ans: string[] = [];
    for (let i = 0; i < n; i++) {
        const c = s[i];
        if (c === '-') {
            continue;
        }
        ans.push(c.toUpperCase());
        if (--cnt === 0) {
            cnt = k;
            if (i !== n - 1) {
                ans.push('-');
            }
        }
    }
    while (ans.at(-1) === '-') {
        ans.pop();
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [483. 最小好进制](https://leetcode.cn/problems/smallest-good-base){#483}

{{< tabs "483" >}}

{{% tab "python" %}}
```python
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        def cal(k, m):
            p = s = 1
            for i in range(m):
                p *= k
                s += p
            return s

        num = int(n)
        for m in range(63, 1, -1):
            l, r = 2, num - 1
            while l < r:
                mid = (l + r) >> 1
                if cal(mid, m) >= num:
                    r = mid
                else:
                    l = mid + 1
            if cal(l, m) == num:
                return str(l)
        return str(num - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        for (int len = 63; len >= 2; --len) {
            long radix = getRadix(len, num);
            if (radix != -1) {
                return String.valueOf(radix);
            }
        }
        return String.valueOf(num - 1);
    }

    private long getRadix(int len, long num) {
        long l = 2, r = num - 1;
        while (l < r) {
            long mid = l + r >>> 1;
            if (calc(mid, len) >= num)
                r = mid;
            else
                l = mid + 1;
        }
        return calc(r, len) == num ? r : -1;
    }

    private long calc(long radix, int len) {
        long p = 1;
        long sum = 0;
        for (int i = 0; i < len; ++i) {
            if (Long.MAX_VALUE - sum < p) {
                return Long.MAX_VALUE;
            }
            sum += p;
            if (Long.MAX_VALUE / p < radix) {
                p = Long.MAX_VALUE;
            } else {
                p *= radix;
            }
        }
        return sum;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string smallestGoodBase(string n) {
        long v = stol(n);
        int mx = floor(log(v) / log(2));
        for (int m = mx; m > 1; --m) {
            int k = pow(v, 1.0 / m);
            long mul = 1, s = 1;
            for (int i = 0; i < m; ++i) {
                mul *= k;
                s += mul;
            }
            if (s == v) {
                return to_string(k);
            }
        }
        return to_string(v - 1);
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>以字符串的形式给出 <code>n</code>&nbsp;, 以字符串的形式返回<em> <code>n</code> 的最小 <strong>好进制</strong> </em>&nbsp;。</p>

<p>如果 <code>n</code> 的 &nbsp;<code>k(k&gt;=2)</code>&nbsp;进制数的所有数位全为1，则称&nbsp;<code>k(k&gt;=2)</code>&nbsp;是 <code>n</code> 的一个&nbsp;<strong>好进制&nbsp;</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = "13"
<strong>输出：</strong>"3"
<strong>解释：</strong>13 的 3 进制是 111。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = "4681"
<strong>输出：</strong>"8"
<strong>解释：</strong>4681 的 8 进制是 11111。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = "1000000000000000000"
<strong>输出：</strong>"999999999999999999"
<strong>解释：</strong>1000000000000000000 的 999999999999999999 进制是 11。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n</code> 的取值范围是&nbsp;<code>[3, 10<sup>18</sup>]</code></li>
	<li><code>n</code> 没有前导 0</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：数学

假设 $n$ 在 $k$ 进制下的所有位数均为 $1$，且位数为 $m+1$，那么有式子 ①：

$$
n=k^0+k^1+k^2+...+k^m
$$

当 $m=0$ 时，上式 $n=1$，而题目 $n$ 取值范围为 $[3, 10^{18}]$，因此 $m>0$。

当 $m=1$ 时，上式 $n=k^0+k^1=1+k$，即 $k=n-1>=2$。

我们来证明一般情况下的两个结论，以帮助解决本题。

**结论一：** $m<\log _{k} n$

注意到式子 ① 是个首项为 $1$，且公比为 $k$ 的等比数列。利用等比数列求和公式，我们可以得出：

$$
n=\frac{1-k^{m+1}}{1-k}
$$

变形得：

$$
k^{m+1}=k \times n-n+1 < k \times n
$$

移项得：

$$
m<\log _{k} n
$$

题目 $n$ 取值范围为 $[3, 10^{18}]$，又因为 $k>=2$，因此 $m<\log _{k} n<\log _{2} 10^{18}<60$。

**结论二：** $k=\left \lfloor \sqrt[m]{n} \right \rfloor $

$$
n=k^0+k^1+k^2+...+k^m>k^m
$$

根据二项式定理：

$$
(a+b)^{n}=\sum_{k=0}^{n}\left(\begin{array}{l}
n \\
k
\end{array}\right) a^{n-k} b^{k}
$$

整合，可得：

$$
(k+1)^{m}=\left(\begin{array}{c}
m \\
0
\end{array}\right) k^{0}+\left(\begin{array}{c}
m \\
1
\end{array}\right) k^{1}+\left(\begin{array}{c}
m \\
2
\end{array}\right) k^{2}+\cdots+\left(\begin{array}{c}
m \\
m
\end{array}\right) k^{m}
$$

当 $m>1$ 时，满足：

$$
\forall i \in[1, m-1],\left(\begin{array}{c}
m \\
i
\end{array}\right)>1
$$

所以有：

$$
\begin{aligned}
(k+1)^{m} &=\left(\begin{array}{c}
m \\
0
\end{array}\right) k^{0}+\left(\begin{array}{c}
m \\
1
\end{array}\right) k^{1}+\left(\begin{array}{c}
m \\
2
\end{array}\right) k^{2}+\cdots+\left(\begin{array}{c}
m \\
m
\end{array}\right) k^{m} \\
&>k^{0}+k^{1}+k^{2}+\cdots+k^{m}=n
\end{aligned}
$$

即：

$$
k < \sqrt[m]{n} < k+1
$$

由于 $k$ 是整数，因此 $k=\left \lfloor \sqrt[m]{n} \right \rfloor $。

综上，依据结论一，我们知道 $m$ 的取值范围为 $[1,log_{k}n)$，且 $m=1$ 时必然有解。随着 $m$ 的增大，进制 $k$ 不断减小。所以我们只需要从大到小检查每一个 $m$ 可能的取值，利用结论二快速算出对应的 $k$ 值，然后校验计算出的 $k$ 值是否有效即可。如果 $k$ 值有效，我们即可返回结果。

时间复杂度 $O(log^{2}n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        def cal(k, m):
            p = s = 1
            for i in range(m):
                p *= k
                s += p
            return s

        num = int(n)
        for m in range(63, 1, -1):
            l, r = 2, num - 1
            while l < r:
                mid = (l + r) >> 1
                if cal(mid, m) >= num:
                    r = mid
                else:
                    l = mid + 1
            if cal(l, m) == num:
                return str(l)
        return str(num - 1)
```

#### Java

```java
class Solution {
    public String smallestGoodBase(String n) {
        long num = Long.parseLong(n);
        for (int len = 63; len >= 2; --len) {
            long radix = getRadix(len, num);
            if (radix != -1) {
                return String.valueOf(radix);
            }
        }
        return String.valueOf(num - 1);
    }

    private long getRadix(int len, long num) {
        long l = 2, r = num - 1;
        while (l < r) {
            long mid = l + r >>> 1;
            if (calc(mid, len) >= num)
                r = mid;
            else
                l = mid + 1;
        }
        return calc(r, len) == num ? r : -1;
    }

    private long calc(long radix, int len) {
        long p = 1;
        long sum = 0;
        for (int i = 0; i < len; ++i) {
            if (Long.MAX_VALUE - sum < p) {
                return Long.MAX_VALUE;
            }
            sum += p;
            if (Long.MAX_VALUE / p < radix) {
                p = Long.MAX_VALUE;
            } else {
                p *= radix;
            }
        }
        return sum;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string smallestGoodBase(string n) {
        long v = stol(n);
        int mx = floor(log(v) / log(2));
        for (int m = mx; m > 1; --m) {
            int k = pow(v, 1.0 / m);
            long mul = 1, s = 1;
            for (int i = 0; i < m; ++i) {
                mul *= k;
                s += mul;
            }
            if (s == v) {
                return to_string(k);
            }
        }
        return to_string(v - 1);
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [484. 寻找排列 🔒](https://leetcode.cn/problems/find-permutation){#484}

{{< tabs "484" >}}

{{% tab "python" %}}
```python
class Solution:
    def findPermutation(self, s: str) -> List[int]:
        n = len(s)
        ans = list(range(1, n + 2))
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == 'D':
                j += 1
            ans[i : j + 1] = ans[i : j + 1][::-1]
            i = max(i + 1, j)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findPermutation(String s) {
        int n = s.length();
        int[] ans = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            ans[i] = i + 1;
        }
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == 'D') {
                ++j;
            }
            reverse(ans, i, j);
            i = Math.max(i + 1, j);
        }
        return ans;
    }

    private void reverse(int[] arr, int i, int j) {
        for (; i < j; ++i, --j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> ans(n + 1);
        iota(ans.begin(), ans.end(), 1);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == 'D') {
                ++j;
            }
            reverse(ans.begin() + i, ans.begin() + j + 1);
            i = max(i + 1, j);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findPermutation(s string) []int {
	n := len(s)
	ans := make([]int, n+1)
	for i := range ans {
		ans[i] = i + 1
	}
	i := 0
	for i < n {
		j := i
		for ; j < n && s[j] == 'D'; j++ {
		}
		reverse(ans, i, j)
		i = max(i+1, j)
	}
	return ans
}

func reverse(arr []int, i, j int) {
	for ; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>由范围 <code>[1,n]</code> 内所有整数组成的 <code>n</code> 个整数的排列&nbsp;<code>perm</code>&nbsp;可以表示为长度为 <code>n - 1</code> 的字符串 <code>s</code> ，其中:</p>

<ul>
	<li>如果 <code>perm[i] &lt; perm[i + 1]</code> ，那么 <code>s[i] == 'I'</code></li>
	<li>如果&nbsp;<code>perm[i] &gt; perm[i + 1]</code>&nbsp;，那么 <code>s[i] == 'D'</code>&nbsp;。</li>
</ul>

<p>给定一个字符串 <code>s</code> ，重构字典序上最小的排列&nbsp;<code>perm</code>&nbsp;并返回它。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong> s = "I"
<strong>输出：</strong> [1,2]
<strong>解释：</strong> [1,2] 是唯一合法的可以生成秘密签名 "I" 的特定串，数字 1 和 2 构成递增关系。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong> s = "DI"
<strong>输出：</strong> [2,1,3]
<strong>解释：</strong> [2,1,3] 和 [3,1,2] 可以生成秘密签名 "DI"，
但是由于我们要找字典序最小的排列，因此你需要输出 [2,1,3]。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code>&nbsp;只会包含字符 <code>'D'</code> 和 <code>'I'</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

先初始化结果数组 `ans` 为 `[1, 2, 3, ..., n+1]`。

假定某个连续 `D` 子数组区间为 `[i, j)`，那么只要翻转 `ans[i: j + 1]` 即可。

因此，遍历字符串 `s`，找出所有的连续 `D` 子数组区间，将其翻转。

时间复杂度 $O(n)$，其中 $n$ 表示字符串 `s` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findPermutation(self, s: str) -> List[int]:
        n = len(s)
        ans = list(range(1, n + 2))
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == 'D':
                j += 1
            ans[i : j + 1] = ans[i : j + 1][::-1]
            i = max(i + 1, j)
        return ans
```

#### Java

```java
class Solution {
    public int[] findPermutation(String s) {
        int n = s.length();
        int[] ans = new int[n + 1];
        for (int i = 0; i < n + 1; ++i) {
            ans[i] = i + 1;
        }
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == 'D') {
                ++j;
            }
            reverse(ans, i, j);
            i = Math.max(i + 1, j);
        }
        return ans;
    }

    private void reverse(int[] arr, int i, int j) {
        for (; i < j; ++i, --j) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size();
        vector<int> ans(n + 1);
        iota(ans.begin(), ans.end(), 1);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == 'D') {
                ++j;
            }
            reverse(ans.begin() + i, ans.begin() + j + 1);
            i = max(i + 1, j);
        }
        return ans;
    }
};
```

#### Go

```go
func findPermutation(s string) []int {
	n := len(s)
	ans := make([]int, n+1)
	for i := range ans {
		ans[i] = i + 1
	}
	i := 0
	for i < n {
		j := i
		for ; j < n && s[j] == 'D'; j++ {
		}
		reverse(ans, i, j)
		i = max(i+1, j)
	}
	return ans
}

func reverse(arr []int, i, j int) {
	for ; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [485. 最大连续 1 的个数](https://leetcode.cn/problems/max-consecutive-ones){#485}

{{< tabs "485" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = cnt = 0
        for x in nums:
            if x:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 0;
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxConsecutiveOnes(nums []int) (ans int) {
	cnt := 0
	for _, x := range nums {
		if x == 1 {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 0
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxConsecutiveOnes(nums: number[]): number {
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut cnt = 0;

        for &x in nums.iter() {
            if x == 1 {
                cnt += 1;
                ans = ans.max(cnt);
            } else {
                cnt = 0;
            }
        }

        ans
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
var findMaxConsecutiveOnes = function (nums) {
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        $ans = $cnt = 0;

        foreach ($nums as $x) {
            if ($x == 1) {
                $cnt += 1;
                $ans = max($ans, $cnt);
            } else {
                $cnt = 0;
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

<p>给定一个二进制数组 <code>nums</code> ， 计算其中最大连续 <code>1</code> 的个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,0,1,1,1]
<strong>输出：</strong>3
<strong>解释：</strong>开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>nums = [1,0,1,1,0,1]
<b>输出：</b>2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以遍历数组，用一个变量 $\textit{cnt}$ 记录当前连续的 1 的个数，用另一个变量 $\textit{ans}$ 记录最大连续 1 的个数。

当遍历到一个 1 时，将 $\textit{cnt}$ 加一，然后更新 $\textit{ans}$ 的值为 $\textit{cnt}$ 和 $\textit{ans}$ 本身的最大值，即 $\textit{ans} = \max(\textit{ans}, \textit{cnt})$。否则，将 $\textit{cnt}$ 重置为 0。

遍历结束后，返回 $\textit{ans}$ 的值即可。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = cnt = 0
        for x in nums:
            if x:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans
```

#### Java

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x == 1) {
                ans = Math.max(ans, ++cnt);
            } else {
                cnt = 0;
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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int x : nums) {
            if (x) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findMaxConsecutiveOnes(nums []int) (ans int) {
	cnt := 0
	for _, x := range nums {
		if x == 1 {
			cnt++
			ans = max(ans, cnt)
		} else {
			cnt = 0
		}
	}
	return
}
```

#### TypeScript

```ts
function findMaxConsecutiveOnes(nums: number[]): number {
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut cnt = 0;

        for &x in nums.iter() {
            if x == 1 {
                cnt += 1;
                ans = ans.max(cnt);
            } else {
                cnt = 0;
            }
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
    let [ans, cnt] = [0, 0];
    for (const x of nums) {
        if (x) {
            ans = Math.max(ans, ++cnt);
        } else {
            cnt = 0;
        }
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        $ans = $cnt = 0;

        foreach ($nums as $x) {
            if ($x == 1) {
                $cnt += 1;
                $ans = max($ans, $cnt);
            } else {
                $cnt = 0;
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

# [486. 预测赢家](https://leetcode.cn/problems/predict-the-winner){#486}

{{< tabs "486" >}}

{{% tab "python" %}}
```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        for i, x in enumerate(nums):
            f[i][i] = x
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1])
        return f[0][n - 1] >= 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = nums[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = Math.max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] >= 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][i] = nums[i];
        }
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] >= 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func predictTheWinner(nums []int) bool {
	n := len(nums)
	f := make([][]int, n)
	for i, x := range nums {
		f[i] = make([]int, n)
		f[i][i] = x
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = max(nums[i]-f[i+1][j], nums[j]-f[i][j-1])
		}
	}
	return f[0][n-1] >= 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function predictTheWinner(nums: number[]): boolean {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = nums[i];
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = Math.max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
        }
    }
    return f[0][n - 1] >= 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut f = vec![vec![0; n]; n];

        for i in 0..n {
            f[i][i] = nums[i];
        }

        for i in (0..n - 1).rev() {
            for j in i + 1..n {
                f[i][j] = std::cmp::max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }

        f[0][n - 1] >= 0
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 。玩家 1 和玩家 2 基于这个数组设计了一个游戏。</p>

<p>玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手。开始时，两个玩家的初始分值都是 <code>0</code> 。每一回合，玩家从数组的任意一端取一个数字（即，<code>nums[0]</code> 或 <code>nums[nums.length - 1]</code>），取到的数字将会从数组中移除（数组长度减 <code>1</code> ）。玩家选中的数字将会加到他的得分上。当数组中没有剩余数字可取时，游戏结束。</p>

<p>如果玩家 1 能成为赢家，返回 <code>true</code> 。如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 <code>true</code> 。你可以假设每个玩家的玩法都会使他的分数最大化。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,2]
<strong>输出：</strong>false
<strong>解释：</strong>一开始，玩家 1 可以从 1 和 2 中进行选择。
如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）可选。 
所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
因此，玩家 1 永远不会成为赢家，返回 false 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,233,7]
<strong>输出：</strong>true
<strong>解释：</strong>玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 true，表示玩家 1 可以成为赢家。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 20</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>7</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $\textit{dfs}(i, j)$，表示从第 $i$ 个数到第 $j$ 个数，当前玩家与另一个玩家的得分之差的最大值。那么答案就是 $\textit{dfs}(0, n - 1) \geq 0$。

函数 $\textit{dfs}(i, j)$ 的计算方法如下：

-   如果 $i > j$，说明当前没有数字了，所以当前玩家没有分数可以拿，差值为 $0$，即 $\textit{dfs}(i, j) = 0$。
-   否则，当前玩家有两种选择，如果选择第 $i$ 个数，那么当前玩家与另一个玩家的得分之差为 $\textit{nums}[i] - \textit{dfs}(i + 1, j)$；如果选择第 $j$ 个数，那么当前玩家与另一个玩家的得分之差为 $\textit{nums}[j] - \textit{dfs}(i, j - 1)$。当前玩家会选择两种情况中差值较大的情况，也就是说 $\textit{dfs}(i, j) = \max(\textit{nums}[i] - \textit{dfs}(i + 1, j), \textit{nums}[j] - \textit{dfs}(i, j - 1))$。

最后，我们只需要判断 $\textit{dfs}(0, n - 1) \geq 0$ 即可。

为了避免重复计算，我们可以使用记忆化搜索的方法，用一个数组 $f$ 记录所有的 $\textit{dfs}(i, j)$ 的值，当函数再次被调用到时，我们可以直接从 $f$ 中取出答案而不需要重新计算。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        @cache
        def dfs(i: int, j: int) -> int:
            if i > j:
                return 0
            return max(nums[i] - dfs(i + 1, j), nums[j] - dfs(i, j - 1))

        return dfs(0, len(nums) - 1) >= 0
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[][] f;

    public boolean predictTheWinner(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        f = new int[n][n];
        return dfs(0, n - 1) >= 0;
    }

    private int dfs(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (f[i][j] != 0) {
            return f[i][j];
        }
        return f[i][j] = Math.max(nums[i] - dfs(i + 1, j), nums[j] - dfs(i, j - 1));
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i > j) {
                return 0;
            }
            if (f[i][j]) {
                return f[i][j];
            }
            return f[i][j] = max(nums[i] - dfs(i + 1, j), nums[j] - dfs(i, j - 1));
        };
        return dfs(0, n - 1) >= 0;
    }
};
```

#### Go

```go
func predictTheWinner(nums []int) bool {
	n := len(nums)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
	}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if i > j {
			return 0
		}
		if f[i][j] == 0 {
			f[i][j] = max(nums[i]-dfs(i+1, j), nums[j]-dfs(i, j-1))
		}
		return f[i][j]
	}
	return dfs(0, n-1) >= 0
}
```

#### TypeScript

```ts
function predictTheWinner(nums: number[]): boolean {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    const dfs = (i: number, j: number): number => {
        if (i > j) {
            return 0;
        }
        if (f[i][j] === 0) {
            f[i][j] = Math.max(nums[i] - dfs(i + 1, j), nums[j] - dfs(i, j - 1));
        }
        return f[i][j];
    };
    return dfs(0, n - 1) >= 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut f = vec![vec![0; n]; n];
        Self::dfs(&nums, &mut f, 0, n - 1) >= 0
    }

    fn dfs(nums: &Vec<i32>, f: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        if i == j {
            return nums[i] as i32;
        }
        if f[i][j] != 0 {
            return f[i][j];
        }
        f[i][j] = std::cmp::max(
            nums[i] - Self::dfs(nums, f, i + 1, j),
            nums[j] - Self::dfs(nums, f, i, j - 1)
        );
        f[i][j]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以使用动态规划的方法，定义 $f[i][j]$ 表示当前玩家在 $\textit{nums}[i..j]$ 这些数字中能够获得的最大得分的差值。那么最后答案就是 $f[0][n - 1] \geq 0$。

初始时 $f[i][i]=\textit{nums}[i]$，因为只有一个数，所以当前玩家只能拿取这个数，得分差值为 $\textit{nums}[i]$。

考虑 $f[i][j]$，其中 $i < j$，有两种情况：

-   如果当前玩家拿走了 $\textit{nums}[i]$，那么剩下的数字为 $\textit{nums}[i + 1..j]$，此时轮到另一个玩家进行游戏，所以 $f[i][j] = \textit{nums}[i] - f[i + 1][j]$。
-   如果当前玩家拿走了 $\textit{nums}[j]$，那么剩下的数字为 $\textit{nums}[i..j - 1]$，此时轮到另一个玩家进行游戏，所以 $f[i][j] = \textit{nums}[j] - f[i][j - 1]$。

因此，最终的状态转移方程为 $f[i][j] = \max(\textit{nums}[i] - f[i + 1][j], \textit{nums}[j] - f[i][j - 1])$。

最后，我们只需要判断 $f[0][n - 1] \geq 0$ 即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

相似题目：

-   [877. 石子游戏](https://github.com/doocs/leetcode/blob/main/solution/0800-0899/0877.Stone%20Game/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        f = [[0] * n for _ in range(n)]
        for i, x in enumerate(nums):
            f[i][i] = x
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1])
        return f[0][n - 1] >= 0
```

#### Java

```java
class Solution {
    public boolean predictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] f = new int[n][n];
        for (int i = 0; i < n; ++i) {
            f[i][i] = nums[i];
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = Math.max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] >= 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int f[n][n];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            f[i][i] = nums[i];
        }
        for (int i = n - 2; ~i; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }
        return f[0][n - 1] >= 0;
    }
};
```

#### Go

```go
func predictTheWinner(nums []int) bool {
	n := len(nums)
	f := make([][]int, n)
	for i, x := range nums {
		f[i] = make([]int, n)
		f[i][i] = x
	}
	for i := n - 2; i >= 0; i-- {
		for j := i + 1; j < n; j++ {
			f[i][j] = max(nums[i]-f[i+1][j], nums[j]-f[i][j-1])
		}
	}
	return f[0][n-1] >= 0
}
```

#### TypeScript

```ts
function predictTheWinner(nums: number[]): boolean {
    const n = nums.length;
    const f: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (let i = 0; i < n; ++i) {
        f[i][i] = nums[i];
    }
    for (let i = n - 2; i >= 0; --i) {
        for (let j = i + 1; j < n; ++j) {
            f[i][j] = Math.max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
        }
    }
    return f[0][n - 1] >= 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn predict_the_winner(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut f = vec![vec![0; n]; n];

        for i in 0..n {
            f[i][i] = nums[i];
        }

        for i in (0..n - 1).rev() {
            for j in i + 1..n {
                f[i][j] = std::cmp::max(nums[i] - f[i + 1][j], nums[j] - f[i][j - 1]);
            }
        }

        f[0][n - 1] >= 0
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [487. 最大连续1的个数 II 🔒](https://leetcode.cn/problems/max-consecutive-ones-ii){#487}

{{< tabs "487" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        l = cnt = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > 1:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMaxConsecutiveOnes(nums []int) int {
	l, cnt := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > 1 {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMaxConsecutiveOnes(nums: number[]): number {
    let [l, cnt] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
    let [l, cnt] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个二进制数组 <code>nums</code> ，如果最多可以翻转一个 <code>0</code> ，则返回数组中连续 <code>1</code> 的最大个数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,0,1,1,0]
<strong>输出：</strong>4
<strong>解释：</strong>翻转第一个 0 可以得到最长的连续 1。
&nbsp;    当翻转以后，最大连续 1 的个数为 4。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<b>输入：</b>nums = [1,0,1,1,0,1]
<b>输出：</b>4
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;不是&nbsp;<code>0</code>&nbsp;就是&nbsp;<code>1</code>.</li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>如果输入的数字是作为<strong> 无限流 </strong>逐个输入如何处理？换句话说，内存不能存储下所有从流中输入的数字。您可以有效地解决吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们可以遍历数组，用一个变量 $\textit{cnt}$ 记录当前窗口中 0 的个数，当 $\textit{cnt} > 1$ 时，我们将窗口的左边界右移一位。

遍历结束后，窗口的长度即为最大连续 1 的个数。

注意，在上述过程中，我们不需要循环将窗口的左边界右移，而是直接将左边界右移一位，这是因为，题目求的是最大连续 1 的个数，因此，窗口的长度只会增加，不会减少，所以我们不需要循环右移左边界。

时间复杂度 $O(n)$，其中 $n$ 为数组的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        l = cnt = 0
        for x in nums:
            cnt += x ^ 1
            if cnt > 1:
                cnt -= nums[l] ^ 1
                l += 1
        return len(nums) - l
```

#### Java

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.length - l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, cnt = 0;
        for (int x : nums) {
            cnt += x ^ 1;
            if (cnt > 1) {
                cnt -= nums[l++] ^ 1;
            }
        }
        return nums.size() - l;
    }
};
```

#### Go

```go
func findMaxConsecutiveOnes(nums []int) int {
	l, cnt := 0, 0
	for _, x := range nums {
		cnt += x ^ 1
		if cnt > 1 {
			cnt -= nums[l] ^ 1
			l++
		}
	}
	return len(nums) - l
}
```

#### TypeScript

```ts
function findMaxConsecutiveOnes(nums: number[]): number {
    let [l, cnt] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
    let [l, cnt] = [0, 0];
    for (const x of nums) {
        cnt += x ^ 1;
        if (cnt > 1) {
            cnt -= nums[l++] ^ 1;
        }
    }
    return nums.length - l;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [488. 祖玛游戏](https://leetcode.cn/problems/zuma-game){#488}

{{< tabs "488" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        def remove(s):
            while len(s):
                next = re.sub(r'B{3,}|G{3,}|R{3,}|W{3,}|Y{3,}', '', s)
                if len(next) == len(s):
                    break
                s = next
            return s

        visited = set()
        q = deque([(board, hand)])
        while q:
            state, balls = q.popleft()
            if not state:
                return len(hand) - len(balls)
            for ball in set(balls):
                b = balls.replace(ball, '', 1)
                for i in range(1, len(state) + 1):
                    s = state[:i] + ball + state[i:]
                    s = remove(s)
                    if s not in visited:
                        visited.add(s)
                        q.append((s, b))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findMinStep(String board, String hand) {
        final Zuma zuma = Zuma.create(board, hand);
        final HashSet<Long> visited = new HashSet<>();
        final ArrayList<Zuma> init = new ArrayList<>();

        visited.add(zuma.board());
        init.add(zuma);
        return bfs(init, 0, visited);
    }

    private int bfs(ArrayList<Zuma> curr, int k, HashSet<Long> visited) {
        if (curr.isEmpty()) {
            return -1;
        }

        final ArrayList<Zuma> next = new ArrayList<>();

        for (Zuma zuma : curr) {
            ArrayList<Zuma> neib = zuma.getNextLevel(k, visited);
            if (neib == null) {
                return k + 1;
            }

            next.addAll(neib);
        }
        return bfs(next, k + 1, visited);
    }
}

record Zuma(long board, long hand) {
    public static Zuma create(String boardStr, String handStr) {
        return new Zuma(Zuma.encode(boardStr, false), Zuma.encode(handStr, true));
    }

    public ArrayList<Zuma> getNextLevel(int depth, HashSet<Long> visited) {
        final ArrayList<Zuma> next = new ArrayList<>();
        final ArrayList<long[]> handList = this.buildHandList();
        final long[] boardList = new long[32];
        final int size = this.buildBoardList(boardList);

        for (long[] pair : handList) {
            for (int i = 0; i < size; ++i) {
                final long rawBoard = pruningCheck(boardList[i], pair[0], i * 3, depth);
                if (rawBoard == -1) {
                    continue;
                }

                final long nextBoard = updateBoard(rawBoard);
                if (nextBoard == 0) {
                    return null;
                }

                if (pair[1] == 0 || visited.contains(nextBoard)) {
                    continue;
                }

                visited.add(nextBoard);
                next.add(new Zuma(nextBoard, pair[1]));
            }
        }
        return next;
    }

    private long pruningCheck(long insBoard, long ball, int pos, int depth) {
        final long L = (insBoard >> (pos + 3)) & 0x7;
        final long R = (insBoard >> (pos - 3)) & 0x7;

        if (depth == 0 && (ball != R) && (L != R) || depth > 0 && (ball != R)) {
            return -1;
        }
        return insBoard | (ball << pos);
    }

    private long updateBoard(long board) {
        long stack = 0;

        for (int i = 0; i < 64; i += 3) {
            final long curr = (board >> i) & 0x7;
            final long top = (stack) &0x7;

            // pop (if possible)
            if ((top > 0) && (curr != top) && (stack & 0x3F) == ((stack >> 3) & 0x3F)) {
                stack >>= 9;
                if ((stack & 0x7) == top) stack >>= 3;
            }

            if (curr == 0) {
                // done
                break;
            }
            // push and continue
            stack = (stack << 3) | curr;
        }
        return stack;
    }

    private ArrayList<long[]> buildHandList() {
        final ArrayList<long[]> handList = new ArrayList<>();
        long prevBall = 0;
        long ballMask = 0;

        for (int i = 0; i < 16; i += 3) {
            final long currBall = (this.hand >> i) & 0x7;
            if (currBall == 0) {
                break;
            }

            if (currBall != prevBall) {
                prevBall = currBall;
                handList.add(
                    new long[] {currBall, ((this.hand >> 3) & ~ballMask) | (this.hand & ballMask)});
            }
            ballMask = (ballMask << 3) | 0x7;
        }
        return handList;
    }

    private int buildBoardList(long[] buffer) {
        int ptr = 0;
        long ballMask = 0x7;
        long insBoard = this.board << 3;
        buffer[ptr++] = insBoard;

        while (true) {
            final long currBall = this.board & ballMask;
            if (currBall == 0) {
                break;
            }

            ballMask <<= 3;
            insBoard = (insBoard | currBall) & ~ballMask;
            buffer[ptr++] = insBoard;
        }
        return ptr;
    }

    private static long encode(String stateStr, boolean sortFlag) {
        final char[] stateChars = stateStr.toCharArray();
        if (sortFlag) {
            Arrays.sort(stateChars);
        }

        long stateBits = 0;
        for (char ch : stateChars) {
            stateBits = (stateBits << 3) | Zuma.encode(ch);
        }
        return stateBits;
    }

    private static long encode(char ch) {
        return switch (ch) {
            case 'R' -> 0x1;
            case 'G' -> 0x2;
            case 'B' -> 0x3;
            case 'W' -> 0x4;
            case 'Y' -> 0x5;
            case ' ' -> 0x0;
            default  ->
                throw new IllegalArgumentException("Invalid char: " + ch);
        };
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你正在参与祖玛游戏的一个变种。</p>

<p>在这个祖玛游戏变体中，桌面上有 <strong>一排</strong> 彩球，每个球的颜色可能是：红色 <code>'R'</code>、黄色 <code>'Y'</code>、蓝色 <code>'B'</code>、绿色 <code>'G'</code> 或白色 <code>'W'</code> 。你的手中也有一些彩球。</p>

<p>你的目标是 <strong>清空</strong> 桌面上所有的球。每一回合：</p>

<ul>
	<li>从你手上的彩球中选出 <strong>任意一颗</strong> ，然后将其插入桌面上那一排球中：两球之间或这一排球的任一端。</li>
	<li>接着，如果有出现 <strong>三个或者三个以上</strong> 且 <strong>颜色相同</strong> 的球相连的话，就把它们移除掉。
	<ul>
		<li>如果这种移除操作同样导致出现三个或者三个以上且颜色相同的球相连，则可以继续移除这些球，直到不再满足移除条件。</li>
	</ul>
	</li>
	<li>如果桌面上所有球都被移除，则认为你赢得本场游戏。</li>
	<li>重复这个过程，直到你赢了游戏或者手中没有更多的球。</li>
</ul>

<p>给你一个字符串 <code>board</code> ，表示桌面上最开始的那排球。另给你一个字符串 <code>hand</code> ，表示手里的彩球。请你按上述操作步骤移除掉桌上所有球，计算并返回所需的 <strong>最少</strong> 球数。如果不能移除桌上所有的球，返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>board = "WRRBBW", hand = "RB"
<strong>输出：</strong>-1
<strong>解释：</strong>无法移除桌面上的所有球。可以得到的最好局面是：
- 插入一个 'R' ，使桌面变为 WRR<em><strong>R</strong></em>BBW 。W<em><strong>RRR</strong></em>BBW -&gt; WBBW
- 插入一个 'B' ，使桌面变为 WBB<em><strong>B</strong></em>W 。W<em><strong>BBB</strong></em>W -&gt; WW
桌面上还剩着球，没有其他球可以插入。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = "WWRRBBWW", hand = "WRBRW"
<strong>输出：</strong>2
<strong>解释：</strong>要想清空桌面上的球，可以按下述步骤：
- 插入一个 'R' ，使桌面变为 WWRR<strong><em>R</em></strong>BBWW 。WW<em><strong>RRR</strong></em>BBWW -&gt; WWBBWW
- 插入一个 'B' ，使桌面变为 WWBB<em><strong>B</strong></em>WW 。WW<em><strong>BBB</strong></em>WW -&gt; <em><strong>WWWW</strong></em> -&gt; empty
只需从手中出 2 个球就可以清空桌面。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>board = "G", hand = "GGGGG"
<strong>输出：</strong>2
<strong>解释：</strong>要想清空桌面上的球，可以按下述步骤：
- 插入一个 'G' ，使桌面变为 G<em><strong>G</strong></em> 。
- 插入一个 'G' ，使桌面变为 GG<em><strong>G</strong></em> 。<em><strong>GGG</strong></em> -&gt; empty
只需从手中出 2 个球就可以清空桌面。
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>board = "RBYYBBRRB", hand = "YRBGB"
<strong>输出：</strong>3
<strong>解释：</strong>要想清空桌面上的球，可以按下述步骤：
- 插入一个 'Y' ，使桌面变为 RBYY<em><strong>Y</strong></em>BBRRB 。RB<em><strong>YYY</strong></em>BBRRB -&gt; R<em><strong>BBB</strong></em>RRB -&gt; <em><strong>RRR</strong></em>B -&gt; B
- 插入一个 'B' ，使桌面变为 B<em><strong>B</strong></em> 。
- 插入一个 'B' ，使桌面变为 BB<em><strong>B</strong></em> 。<em><strong>BBB</strong></em> -&gt; empty
只需从手中出 3 个球就可以清空桌面。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= board.length &lt;= 16</code></li>
	<li><code>1 &lt;= hand.length &lt;= 5</code></li>
	<li><code>board</code> 和 <code>hand</code> 由字符 <code>'R'</code>、<code>'Y'</code>、<code>'B'</code>、<code>'G'</code> 和 <code>'W'</code> 组成</li>
	<li>桌面上一开始的球中，不会有三个及三个以上颜色相同且连着的球</li>
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
    def findMinStep(self, board: str, hand: str) -> int:
        def remove(s):
            while len(s):
                next = re.sub(r'B{3,}|G{3,}|R{3,}|W{3,}|Y{3,}', '', s)
                if len(next) == len(s):
                    break
                s = next
            return s

        visited = set()
        q = deque([(board, hand)])
        while q:
            state, balls = q.popleft()
            if not state:
                return len(hand) - len(balls)
            for ball in set(balls):
                b = balls.replace(ball, '', 1)
                for i in range(1, len(state) + 1):
                    s = state[:i] + ball + state[i:]
                    s = remove(s)
                    if s not in visited:
                        visited.add(s)
                        q.append((s, b))
        return -1
```

#### Java

```java
class Solution {
    public int findMinStep(String board, String hand) {
        final Zuma zuma = Zuma.create(board, hand);
        final HashSet<Long> visited = new HashSet<>();
        final ArrayList<Zuma> init = new ArrayList<>();

        visited.add(zuma.board());
        init.add(zuma);
        return bfs(init, 0, visited);
    }

    private int bfs(ArrayList<Zuma> curr, int k, HashSet<Long> visited) {
        if (curr.isEmpty()) {
            return -1;
        }

        final ArrayList<Zuma> next = new ArrayList<>();

        for (Zuma zuma : curr) {
            ArrayList<Zuma> neib = zuma.getNextLevel(k, visited);
            if (neib == null) {
                return k + 1;
            }

            next.addAll(neib);
        }
        return bfs(next, k + 1, visited);
    }
}

record Zuma(long board, long hand) {
    public static Zuma create(String boardStr, String handStr) {
        return new Zuma(Zuma.encode(boardStr, false), Zuma.encode(handStr, true));
    }

    public ArrayList<Zuma> getNextLevel(int depth, HashSet<Long> visited) {
        final ArrayList<Zuma> next = new ArrayList<>();
        final ArrayList<long[]> handList = this.buildHandList();
        final long[] boardList = new long[32];
        final int size = this.buildBoardList(boardList);

        for (long[] pair : handList) {
            for (int i = 0; i < size; ++i) {
                final long rawBoard = pruningCheck(boardList[i], pair[0], i * 3, depth);
                if (rawBoard == -1) {
                    continue;
                }

                final long nextBoard = updateBoard(rawBoard);
                if (nextBoard == 0) {
                    return null;
                }

                if (pair[1] == 0 || visited.contains(nextBoard)) {
                    continue;
                }

                visited.add(nextBoard);
                next.add(new Zuma(nextBoard, pair[1]));
            }
        }
        return next;
    }

    private long pruningCheck(long insBoard, long ball, int pos, int depth) {
        final long L = (insBoard >> (pos + 3)) & 0x7;
        final long R = (insBoard >> (pos - 3)) & 0x7;

        if (depth == 0 && (ball != R) && (L != R) || depth > 0 && (ball != R)) {
            return -1;
        }
        return insBoard | (ball << pos);
    }

    private long updateBoard(long board) {
        long stack = 0;

        for (int i = 0; i < 64; i += 3) {
            final long curr = (board >> i) & 0x7;
            final long top = (stack) &0x7;

            // pop (if possible)
            if ((top > 0) && (curr != top) && (stack & 0x3F) == ((stack >> 3) & 0x3F)) {
                stack >>= 9;
                if ((stack & 0x7) == top) stack >>= 3;
            }

            if (curr == 0) {
                // done
                break;
            }
            // push and continue
            stack = (stack << 3) | curr;
        }
        return stack;
    }

    private ArrayList<long[]> buildHandList() {
        final ArrayList<long[]> handList = new ArrayList<>();
        long prevBall = 0;
        long ballMask = 0;

        for (int i = 0; i < 16; i += 3) {
            final long currBall = (this.hand >> i) & 0x7;
            if (currBall == 0) {
                break;
            }

            if (currBall != prevBall) {
                prevBall = currBall;
                handList.add(
                    new long[] {currBall, ((this.hand >> 3) & ~ballMask) | (this.hand & ballMask)});
            }
            ballMask = (ballMask << 3) | 0x7;
        }
        return handList;
    }

    private int buildBoardList(long[] buffer) {
        int ptr = 0;
        long ballMask = 0x7;
        long insBoard = this.board << 3;
        buffer[ptr++] = insBoard;

        while (true) {
            final long currBall = this.board & ballMask;
            if (currBall == 0) {
                break;
            }

            ballMask <<= 3;
            insBoard = (insBoard | currBall) & ~ballMask;
            buffer[ptr++] = insBoard;
        }
        return ptr;
    }

    private static long encode(String stateStr, boolean sortFlag) {
        final char[] stateChars = stateStr.toCharArray();
        if (sortFlag) {
            Arrays.sort(stateChars);
        }

        long stateBits = 0;
        for (char ch : stateChars) {
            stateBits = (stateBits << 3) | Zuma.encode(ch);
        }
        return stateBits;
    }

    private static long encode(char ch) {
        return switch (ch) {
            case 'R' -> 0x1;
            case 'G' -> 0x2;
            case 'B' -> 0x3;
            case 'W' -> 0x4;
            case 'Y' -> 0x5;
            case ' ' -> 0x0;
            default  ->
                throw new IllegalArgumentException("Invalid char: " + ch);
        };
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [489. 扫地机器人 🔒](https://leetcode.cn/problems/robot-room-cleaner){#489}

{{< tabs "489" >}}

{{% tab "python" %}}
```python
# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
# class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """


class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """

        def dfs(i, j, d):
            vis.add((i, j))
            robot.clean()
            for k in range(4):
                nd = (d + k) % 4
                x, y = i + dirs[nd], j + dirs[nd + 1]
                if (x, y) not in vis and robot.move():
                    dfs(x, y, nd)
                    robot.turnRight()
                    robot.turnRight()
                    robot.move()
                    robot.turnRight()
                    robot.turnRight()
                robot.turnRight()

        dirs = (-1, 0, 1, 0, -1)
        vis = set()
        dfs(0, 0, 0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * interface Robot {
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     public boolean move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     public void turnLeft();
 *     public void turnRight();
 *
 *     // Clean the current cell.
 *     public void clean();
 * }
 */

class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};
    private Set<List<Integer>> vis = new HashSet<>();
    private Robot robot;

    public void cleanRoom(Robot robot) {
        this.robot = robot;
        dfs(0, 0, 0);
    }

    private void dfs(int i, int j, int d) {
        robot.clean();
        vis.add(List.of(i, j));
        for (int k = 0; k < 4; ++k) {
            int nd = (d + k) % 4;
            int x = i + dirs[nd], y = j + dirs[nd + 1];
            if (!vis.contains(List.of(x, y)) && robot.move()) {
                dfs(x, y, nd);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        int dirs[5] = {-1, 0, 1, 0, -1};
        set<pair<int, int>> vis;
        function<void(int, int, int)> dfs = [&](int i, int j, int d) {
            robot.clean();
            vis.insert({i, j});
            for (int k = 0; k < 4; ++k) {
                int nd = (d + k) % 4;
                int x = i + dirs[nd], y = j + dirs[nd + 1];
                if (!vis.count({x, y}) && robot.move()) {
                    dfs(x, y, nd);
                    robot.turnRight();
                    robot.turnRight();
                    robot.move();
                    robot.turnRight();
                    robot.turnRight();
                }
                robot.turnRight();
            }
        };
        dfs(0, 0, 0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * type Robot struct {
 * }
 *
 * // Returns true if the cell in front is open and robot moves into the cell.
 * // Returns false if the cell in front is blocked and robot stays in the current cell.
 * func (robot *Robot) Move() bool {}
 *
 * // Robot will stay in the same cell after calling TurnLeft/TurnRight.
 * // Each turn will be 90 degrees.
 * func (robot *Robot) TurnLeft() {}
 * func (robot *Robot) TurnRight() {}
 *
 * // Clean the current cell.
 * func (robot *Robot) Clean() {}
 */

func cleanRoom(robot *Robot) {
	vis := map[[2]int]bool{}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(int, int, int)
	dfs = func(i, j, d int) {
		vis[[2]int{i, j}] = true
		robot.Clean()
		for k := 0; k < 4; k++ {
			nd := (d + k) % 4
			x, y := i+dirs[nd], j+dirs[nd+1]
			if !vis[[2]int{x, y}] && robot.Move() {
				dfs(x, y, nd)
				robot.TurnRight()
				robot.TurnRight()
				robot.Move()
				robot.TurnRight()
				robot.TurnRight()
			}
			robot.TurnRight()
		}
	}
	dfs(0, 0, 0)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * class Robot {
 *      // Returns true if the cell in front is open and robot moves into the cell.
 *      // Returns false if the cell in front is blocked and robot stays in the current cell.
 * 		move(): boolean {}
 *
 *      // Robot will stay in the same cell after calling turnLeft/turnRight.
 *      // Each turn will be 90 degrees.
 * 		turnRight() {}
 *
 *      // Robot will stay in the same cell after calling turnLeft/turnRight.
 *      // Each turn will be 90 degrees.
 * 		turnLeft() {}
 *
 * 		// Clean the current cell.
 * 		clean(): {}
 * }
 */

function cleanRoom(robot: Robot) {
    const dirs = [-1, 0, 1, 0, -1];
    const vis = new Set<string>();
    const dfs = (i: number, j: number, d: number) => {
        vis.add(`${i}-${j}`);
        robot.clean();
        for (let k = 0; k < 4; ++k) {
            const nd = (d + k) % 4;
            const [x, y] = [i + dirs[nd], j + dirs[nd + 1]];
            if (!vis.has(`${x}-${y}`) && robot.move()) {
                dfs(x, y, nd);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    };
    dfs(0, 0, 0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>房间中的某个位置上有一个机器人，你需要控制它清扫房间。房间被建模为一个 <code>m x n</code> 的二进制网格，其中 <code>0</code> 表示单元格中有障碍物，<code>1</code> 表示空单元格。</p>

<p>机器人从一个未知的空单元格开始出发，并且你无法访问网格，但你可以使用给定的 API <code>Robot</code> 控制机器人。</p>

<p>你的任务是使用机器人清扫整个房间（即清理房间中的每个空单元格）。机器人具有四个给定的API，可以前进、向左转或向右转。每次转弯 <code>90</code> 度。</p>

<p>当机器人试图移动到一个存在障碍物的单元格时，它的碰撞传感器会检测到障碍物，并停留在当前单元格。</p>

<p>设计一个算法，使用下述 API 清扫整个房间：</p>

<pre>
interface Robot {
&nbsp; // 若下一个单元格为空，则返回 true ，并移动至该单元格。
&nbsp; // 若下一个单元格为障碍物，则返回 false ，并停留在当前单元格。
&nbsp; boolean move();

  // 在调用 turnLeft/turnRight 后机器人会停留在当前单元格。
&nbsp; // 每次转弯 90 度。
&nbsp; void turnLeft();
&nbsp; void turnRight();

  // 清理当前单元格。
  void clean();
}
</pre>

<p><strong>注意</strong> 扫地机器人的初始方向向上。你可以假定网格的四周都被墙包围。</p>

<p>&nbsp;</p>

<p><strong>自定义测试：</strong></p>

<p>输入只用于初始化房间和机器人的位置。你需要「盲解」这个问题。换而言之，你必须在对房间和机器人位置一无所知的情况下，只使用 4 个给出的 API 解决问题。&nbsp;</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0489.Robot%20Room%20Cleaner/images/lc-grid.jpg" style="width: 500px; height: 314px;" />
<pre>
<strong>输入：</strong>room = [[1,1,1,1,1,0,1,1],[1,1,1,1,1,0,1,1],[1,0,1,1,1,1,1,1],[0,0,0,1,0,0,0,0],[1,1,1,1,1,1,1,1]], row = 1, col = 3
<strong>输出：</strong>Robot cleaned all rooms.
<strong>解释：</strong>
房间内的所有单元格用 0 或 1 填充。
0 表示障碍物，1 表示可以通过。 
机器人从 row=1, col=3 的初始位置出发。
在左上角的一行以下，三列以右。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>room = [[1]], row = 0, col = 0
<strong>输出：</strong>Robot cleaned all rooms.
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == room.length</code></li>
	<li><code>n == room[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>room[i][j]</code> 为 <code>0</code> 或 <code>1</code>.</li>
	<li><code>0 &lt;= row &lt;&nbsp;m</code></li>
	<li><code>0 &lt;= col &lt; n</code></li>
	<li><code>room[row][col] == 1</code></li>
	<li>所有空单元格都可以从起始位置出发访问到。</li>
</ul>

<ol>
</ol>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们不妨假设机器人的初始位置为 $(0, 0)$，方向为 $d=0$。我们将初始位置进行打扫，并标记为已访问。然后，我们依次选择上、右、下、左四个方向进行探索，每次探索前都先判断是否已经访问过，如果没有访问过，我们就朝着该方向前进一步，然后递归探索。如果已经访问过，我们就顺时针旋转 $90^\circ$，然后继续探索下一个方向。当我们探索完所有的方向后，我们需要回到上一个位置，这时我们只需要顺时针旋转 $180^\circ$，然后前进一步，再顺时针旋转 $180^\circ$ 即可。

时间复杂度 $O(4^{n-m})$，空间复杂度 $O(n-m)$。其中 $n$ 和 $m$ 分别是房间的数量以及障碍物的数量。

<!-- tabs:start -->

#### Python3

```python
# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
# class Robot:
#    def move(self):
#        """
#        Returns true if the cell in front is open and robot moves into the cell.
#        Returns false if the cell in front is blocked and robot stays in the current cell.
#        :rtype bool
#        """
#
#    def turnLeft(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def turnRight(self):
#        """
#        Robot will stay in the same cell after calling turnLeft/turnRight.
#        Each turn will be 90 degrees.
#        :rtype void
#        """
#
#    def clean(self):
#        """
#        Clean the current cell.
#        :rtype void
#        """


class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """

        def dfs(i, j, d):
            vis.add((i, j))
            robot.clean()
            for k in range(4):
                nd = (d + k) % 4
                x, y = i + dirs[nd], j + dirs[nd + 1]
                if (x, y) not in vis and robot.move():
                    dfs(x, y, nd)
                    robot.turnRight()
                    robot.turnRight()
                    robot.move()
                    robot.turnRight()
                    robot.turnRight()
                robot.turnRight()

        dirs = (-1, 0, 1, 0, -1)
        vis = set()
        dfs(0, 0, 0)
```

#### Java

```java
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * interface Robot {
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     public boolean move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     public void turnLeft();
 *     public void turnRight();
 *
 *     // Clean the current cell.
 *     public void clean();
 * }
 */

class Solution {
    private int[] dirs = {-1, 0, 1, 0, -1};
    private Set<List<Integer>> vis = new HashSet<>();
    private Robot robot;

    public void cleanRoom(Robot robot) {
        this.robot = robot;
        dfs(0, 0, 0);
    }

    private void dfs(int i, int j, int d) {
        robot.clean();
        vis.add(List.of(i, j));
        for (int k = 0; k < 4; ++k) {
            int nd = (d + k) % 4;
            int x = i + dirs[nd], y = j + dirs[nd + 1];
            if (!vis.contains(List.of(x, y)) && robot.move()) {
                dfs(x, y, nd);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
}
```

#### C++

```cpp
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        int dirs[5] = {-1, 0, 1, 0, -1};
        set<pair<int, int>> vis;
        function<void(int, int, int)> dfs = [&](int i, int j, int d) {
            robot.clean();
            vis.insert({i, j});
            for (int k = 0; k < 4; ++k) {
                int nd = (d + k) % 4;
                int x = i + dirs[nd], y = j + dirs[nd + 1];
                if (!vis.count({x, y}) && robot.move()) {
                    dfs(x, y, nd);
                    robot.turnRight();
                    robot.turnRight();
                    robot.move();
                    robot.turnRight();
                    robot.turnRight();
                }
                robot.turnRight();
            }
        };
        dfs(0, 0, 0);
    }
};
```

#### Go

```go
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * type Robot struct {
 * }
 *
 * // Returns true if the cell in front is open and robot moves into the cell.
 * // Returns false if the cell in front is blocked and robot stays in the current cell.
 * func (robot *Robot) Move() bool {}
 *
 * // Robot will stay in the same cell after calling TurnLeft/TurnRight.
 * // Each turn will be 90 degrees.
 * func (robot *Robot) TurnLeft() {}
 * func (robot *Robot) TurnRight() {}
 *
 * // Clean the current cell.
 * func (robot *Robot) Clean() {}
 */

func cleanRoom(robot *Robot) {
	vis := map[[2]int]bool{}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(int, int, int)
	dfs = func(i, j, d int) {
		vis[[2]int{i, j}] = true
		robot.Clean()
		for k := 0; k < 4; k++ {
			nd := (d + k) % 4
			x, y := i+dirs[nd], j+dirs[nd+1]
			if !vis[[2]int{x, y}] && robot.Move() {
				dfs(x, y, nd)
				robot.TurnRight()
				robot.TurnRight()
				robot.Move()
				robot.TurnRight()
				robot.TurnRight()
			}
			robot.TurnRight()
		}
	}
	dfs(0, 0, 0)
}
```

#### TypeScript

```ts
/**
 * class Robot {
 *      // Returns true if the cell in front is open and robot moves into the cell.
 *      // Returns false if the cell in front is blocked and robot stays in the current cell.
 * 		move(): boolean {}
 *
 *      // Robot will stay in the same cell after calling turnLeft/turnRight.
 *      // Each turn will be 90 degrees.
 * 		turnRight() {}
 *
 *      // Robot will stay in the same cell after calling turnLeft/turnRight.
 *      // Each turn will be 90 degrees.
 * 		turnLeft() {}
 *
 * 		// Clean the current cell.
 * 		clean(): {}
 * }
 */

function cleanRoom(robot: Robot) {
    const dirs = [-1, 0, 1, 0, -1];
    const vis = new Set<string>();
    const dfs = (i: number, j: number, d: number) => {
        vis.add(`${i}-${j}`);
        robot.clean();
        for (let k = 0; k < 4; ++k) {
            const nd = (d + k) % 4;
            const [x, y] = [i + dirs[nd], j + dirs[nd + 1]];
            if (!vis.has(`${x}-${y}`) && robot.move()) {
                dfs(x, y, nd);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    };
    dfs(0, 0, 0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
