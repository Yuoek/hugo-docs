---
title: "2590_设计一个待办事项清单 🔒"
date: 2025-10-08T18:39:23+08:00
weight: 10
tags: [二分查找, 位运算, 动态规划, 双指针, 哈希表, 回溯, 堆（优先队列）, 字符串, 广度优先搜索, 排序, 数学, 数组, 模拟, 深度优先搜索, 矩阵, 组合数学, 设计, 贪心]
---

{{< markmap >}}
### [2590_设计一个待办事项清单 🔒](#2590)
#### [设计](#2590)
#### [数组](#2590)
#### [哈希表](#2590)
#### [字符串](#2590)
#### [排序](#2590)
### [2591_将钱分给最多的儿童](#2591)
#### [贪心](#2591)
#### [数学](#2591)
### [2592_最大化数组的伟大值](#2592)
#### [贪心](#2592)
#### [数组](#2592)
#### [双指针](#2592)
#### [排序](#2592)
### [2593_标记所有元素后数组的分数](#2593)
#### [数组](#2593)
#### [哈希表](#2593)
#### [排序](#2593)
#### [模拟](#2593)
#### [堆（优先队列）](#2593)
### [2594_修车的最少时间](#2594)
#### [数组](#2594)
#### [二分查找](#2594)
### [2595_奇偶位数](#2595)
#### [位运算](#2595)
### [2596_检查骑士巡视方案](#2596)
#### [深度优先搜索](#2596)
#### [广度优先搜索](#2596)
#### [数组](#2596)
#### [矩阵](#2596)
#### [模拟](#2596)
### [2597_美丽子集的数目](#2597)
#### [数组](#2597)
#### [哈希表](#2597)
#### [数学](#2597)
#### [动态规划](#2597)
#### [回溯](#2597)
#### [组合数学](#2597)
#### [排序](#2597)
### [2598_执行操作后的最大 MEX](#2598)
#### [贪心](#2598)
#### [数组](#2598)
#### [哈希表](#2598)
#### [数学](#2598)
### [2599_使前缀和数组非负 🔒](#2599)
#### [贪心](#2599)
#### [数组](#2599)
#### [堆（优先队列）](#2599)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2590_设计一个待办事项清单 🔒
___
#### 设计
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 2591_将钱分给最多的儿童
___
#### 贪心
___
#### 数学
---
### 2592_最大化数组的伟大值
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 排序
---
### 2593_标记所有元素后数组的分数
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 模拟
___
#### 堆（优先队列）
---
### 2594_修车的最少时间
___
#### 数组
___
#### 二分查找
---
### 2595_奇偶位数
___
#### 位运算
---
### 2596_检查骑士巡视方案
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
___
#### 模拟
---
### 2597_美丽子集的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 组合数学
___
#### 排序
---
### 2598_执行操作后的最大 MEX
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 数学
---
### 2599_使前缀和数组非负 🔒
___
#### 贪心
___
#### 数组
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 动态规划 |
| 双指针 | 哈希表 | 回溯 |
| 堆（优先队列） | 字符串 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 模拟 | 深度优先搜索 | 矩阵 |
| 组合数学 | 设计 | 贪心 |

# [2590. 设计一个待办事项清单 🔒](https://leetcode.cn/problems/design-a-todo-list){#2590}

{{< tabs "2590" >}}

{{% tab "python" %}}
```python
class TodoList:
    def __init__(self):
        self.i = 1
        self.tasks = defaultdict(SortedList)

    def addTask(
        self, userId: int, taskDescription: str, dueDate: int, tags: List[str]
    ) -> int:
        taskId = self.i
        self.i += 1
        self.tasks[userId].add([dueDate, taskDescription, set(tags), taskId, False])
        return taskId

    def getAllTasks(self, userId: int) -> List[str]:
        return [x[1] for x in self.tasks[userId] if not x[4]]

    def getTasksForTag(self, userId: int, tag: str) -> List[str]:
        return [x[1] for x in self.tasks[userId] if not x[4] and tag in x[2]]

    def completeTask(self, userId: int, taskId: int) -> None:
        for task in self.tasks[userId]:
            if task[3] == taskId:
                task[4] = True
                break


# Your TodoList object will be instantiated and called as such:
# obj = TodoList()
# param_1 = obj.addTask(userId,taskDescription,dueDate,tags)
# param_2 = obj.getAllTasks(userId)
# param_3 = obj.getTasksForTag(userId,tag)
# obj.completeTask(userId,taskId)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Task {
    int taskId;
    String taskName;
    int dueDate;
    Set<String> tags;
    boolean finish;

    public Task(int taskId, String taskName, int dueDate, Set<String> tags) {
        this.taskId = taskId;
        this.taskName = taskName;
        this.dueDate = dueDate;
        this.tags = tags;
    }
}

class TodoList {
    private int i = 1;
    private Map<Integer, TreeSet<Task>> tasks = new HashMap<>();

    public TodoList() {
    }

    public int addTask(int userId, String taskDescription, int dueDate, List<String> tags) {
        Task task = new Task(i++, taskDescription, dueDate, new HashSet<>(tags));
        tasks.computeIfAbsent(userId, k -> new TreeSet<>(Comparator.comparingInt(a -> a.dueDate)))
            .add(task);
        return task.taskId;
    }

    public List<String> getAllTasks(int userId) {
        List<String> ans = new ArrayList<>();
        if (tasks.containsKey(userId)) {
            for (Task task : tasks.get(userId)) {
                if (!task.finish) {
                    ans.add(task.taskName);
                }
            }
        }
        return ans;
    }

    public List<String> getTasksForTag(int userId, String tag) {
        List<String> ans = new ArrayList<>();
        if (tasks.containsKey(userId)) {
            for (Task task : tasks.get(userId)) {
                if (task.tags.contains(tag) && !task.finish) {
                    ans.add(task.taskName);
                }
            }
        }
        return ans;
    }

    public void completeTask(int userId, int taskId) {
        if (tasks.containsKey(userId)) {
            for (Task task : tasks.get(userId)) {
                if (task.taskId == taskId) {
                    task.finish = true;
                    break;
                }
            }
        }
    }
}

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList obj = new TodoList();
 * int param_1 = obj.addTask(userId,taskDescription,dueDate,tags);
 * List<String> param_2 = obj.getAllTasks(userId);
 * List<String> param_3 = obj.getTasksForTag(userId,tag);
 * obj.completeTask(userId,taskId);
 */
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::{HashMap, HashSet};

#[derive(Clone)]
struct Task {
    task_id: i32,
    description: String,
    tags: HashSet<String>,
    due_date: i32,
}

struct TodoList {
    /// The global task id
    id: i32,
    /// The mapping from `user_id` to `task`
    user_map: HashMap<i32, Vec<Task>>,
}

impl TodoList {
    fn new() -> Self {
        Self {
            id: 1,
            user_map: HashMap::new(),
        }
    }

    fn add_task(
        &mut self,
        user_id: i32,
        task_description: String,
        due_date: i32,
        tags: Vec<String>,
    ) -> i32 {
        if self.user_map.contains_key(&user_id) {
            // Just add the task
            self.user_map.get_mut(&user_id).unwrap().push(Task {
                task_id: self.id,
                description: task_description,
                tags: tags.into_iter().collect::<HashSet<String>>(),
                due_date,
            });
            // Increase the global id
            self.id += 1;
            return self.id - 1;
        }
        // Otherwise, create a new user
        self.user_map.insert(
            user_id,
            vec![Task {
                task_id: self.id,
                description: task_description,
                tags: tags.into_iter().collect::<HashSet<String>>(),
                due_date,
            }],
        );
        self.id += 1;
        self.id - 1
    }

    fn get_all_tasks(&self, user_id: i32) -> Vec<String> {
        if !self.user_map.contains_key(&user_id) || self.user_map.get(&user_id).unwrap().is_empty()
        {
            return vec![];
        }
        // Get the task vector
        let mut ret_vec = (*self.user_map.get(&user_id).unwrap()).clone();
        // Sort by due date
        ret_vec.sort_by(|lhs, rhs| lhs.due_date.cmp(&rhs.due_date));
        // Return the description vector
        ret_vec.into_iter().map(|x| x.description).collect()
    }

    fn get_tasks_for_tag(&self, user_id: i32, tag: String) -> Vec<String> {
        if !self.user_map.contains_key(&user_id) || self.user_map.get(&user_id).unwrap().is_empty()
        {
            return vec![];
        }
        // Get the task vector
        let mut ret_vec = (*self.user_map.get(&user_id).unwrap()).clone();
        // Sort by due date
        ret_vec.sort_by(|lhs, rhs| lhs.due_date.cmp(&rhs.due_date));
        // Return the description vector
        ret_vec
            .into_iter()
            .filter(|x| x.tags.contains(&tag))
            .map(|x| x.description)
            .collect()
    }

    fn complete_task(&mut self, user_id: i32, task_id: i32) {
        if !self.user_map.contains_key(&user_id) || self.user_map.get(&user_id).unwrap().is_empty()
        {
            return;
        }
        self.user_map
            .get_mut(&user_id)
            .unwrap()
            .retain(|x| (*x).task_id != task_id);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个待办事项清单，用户可以添加 <strong>任务</strong> ，标记任务为 <strong>完成状态</strong> ，或获取待办任务列表。用户还可以为任务添加 <strong>标签</strong> ，并可以按照特定标签筛选任务。</p>

<p>实现 <code>TodoList</code> 类：</p>

<ul>
	<li><code>TodoList()</code> 初始化对象。</li>
	<li><code>int addTask(int userId, String taskDescription, int dueDate, List&lt;String&gt; tags)</code> 为用户 ID 为 <code>userId</code> 的用户添加一个任务，该任务的到期日期为 <code>dueDate</code>&nbsp;，附带了一个标签列表 <code>tags</code>&nbsp;。返回值为任务的 ID 。该 ID 从 <code>1</code> 开始，<strong>依次</strong> 递增。即，第一个任务的ID应为 <code>1</code> ，第二个任务的 ID 应为 <code>2</code> ，以此类推。</li>
	<li><code>List&lt;String&gt; getAllTasks(int userId)</code> 返回未标记为完成状态的 ID 为 <code>userId</code> 的用户的所有任务列表，按照到期日期排序。如果用户没有未完成的任务，则应返回一个空列表。</li>
	<li><code>List&lt;String&gt; getTasksForTag(int userId, String tag)</code> 返回 ID 为 <code>userId</code> 的用户未标记为完成状态且具有 <code>tag</code> 标签之一的所有任务列表，按照到期日期排序。如果不存在此类任务，则返回一个空列表。</li>
	<li><code>void completeTask(int userId, int taskId)</code> 仅在任务存在且 ID 为 <code>userId</code> 的用户拥有此任务且它是未完成状态时，将 ID 为 <code>taskId</code> 的任务标记为已完成状态。</li>
</ul>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<strong>输入</strong>
["TodoList", "addTask", "addTask", "getAllTasks", "getAllTasks", "addTask", "getTasksForTag", "completeTask", "completeTask", "getTasksForTag", "getAllTasks"]
[[], [1, "Task1", 50, []], [1, "Task2", 100, ["P1"]], [1], [5], [1, "Task3", 30, ["P1"]], [1, "P1"], [5, 1], [1, 2], [1, "P1"], [1]]
<strong>输出</strong>
[null, 1, 2, ["Task1", "Task2"], [], 3, ["Task3", "Task2"], null, null, ["Task3"], ["Task3", "Task1"]]

<strong>解释</strong>
TodoList todoList = new TodoList(); 
todoList.addTask(1, "Task1", 50, []); // 返回1。为ID为1的用户添加一个新任务。 
todoList.addTask(1, "Task2", 100, ["P1"]); // 返回2。为ID为1的用户添加另一个任务，并给它添加标签“P1”。 
todoList.getAllTasks(1); // 返回["Task1", "Task2"]。用户1目前有两个未完成的任务。 
todoList.getAllTasks(5); // 返回[]。用户5目前没有任务。 
todoList.addTask(1, "Task3", 30, ["P1"]); // 返回3。为ID为1的用户添加另一个任务，并给它添加标签“P1”。 
todoList.getTasksForTag(1, "P1"); // 返回["Task3", "Task2"]。返回ID为1的用户未完成的带有“P1”标签的任务。 
todoList.completeTask(5, 1); // 不做任何操作，因为任务1不属于用户5。 
todoList.completeTask(1, 2); // 将任务2标记为已完成。 
todoList.getTasksForTag(1, "P1"); // 返回["Task3"]。返回ID为1的用户未完成的带有“P1”标签的任务。 
                                  // 注意，现在不包括 “Task2” ，因为它已经被标记为已完成。 
todoList.getAllTasks(1); // 返回["Task3", "Task1"]。用户1现在有两个未完成的任务。

</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= userId, taskId, dueDate &lt;= 100</code></li>
	<li><code>0 &lt;= tags.length &lt;= 100</code></li>
	<li><code>1 &lt;= taskDescription.length &lt;= 50</code></li>
	<li><code>1 &lt;= tags[i].length, tag.length &lt;= 20</code></li>
	<li>所有的&nbsp;<code>dueDate</code> 值都是唯一的。</li>
	<li>所有字符串都由小写和大写英文字母和数字组成。</li>
	<li>每个方法最多被调用 <code>100</code> 次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 有序集合

我们使用哈希表 $tasks$ 记录每个用户的任务集合，其中键为用户 ID，值为一个有序集合，按照任务的截止日期排序。另外用一个变量 $i$ 记录当前任务的 ID。

调用 `addTask` 方法时，我们将任务添加到对应用户的任务集合中，返回任务 ID。此操作的时间复杂度为 $O(\log n)$。

调用 `getAllTasks` 方法时，我们遍历对应用户的任务集合，将未完成的任务的描述添加到结果列表中，返回结果列表。此操作的时间复杂度为 $O(n)$。

调用 `getTasksForTag` 方法时，我们遍历对应用户的任务集合，将未完成的任务的描述添加到结果列表中，返回结果列表。此操作的时间复杂度为 $O(n)$。

调用 `completeTask` 方法时，我们遍历对应用户的任务集合，将任务 ID 为 $taskId$ 的任务标记为已完成。此操作的时间复杂度为 $(n)$。

空间复杂度 $O(n)$。其中 $n$ 为所有任务的数量。

<!-- tabs:start -->

#### Python3

```python
class TodoList:
    def __init__(self):
        self.i = 1
        self.tasks = defaultdict(SortedList)

    def addTask(
        self, userId: int, taskDescription: str, dueDate: int, tags: List[str]
    ) -> int:
        taskId = self.i
        self.i += 1
        self.tasks[userId].add([dueDate, taskDescription, set(tags), taskId, False])
        return taskId

    def getAllTasks(self, userId: int) -> List[str]:
        return [x[1] for x in self.tasks[userId] if not x[4]]

    def getTasksForTag(self, userId: int, tag: str) -> List[str]:
        return [x[1] for x in self.tasks[userId] if not x[4] and tag in x[2]]

    def completeTask(self, userId: int, taskId: int) -> None:
        for task in self.tasks[userId]:
            if task[3] == taskId:
                task[4] = True
                break


# Your TodoList object will be instantiated and called as such:
# obj = TodoList()
# param_1 = obj.addTask(userId,taskDescription,dueDate,tags)
# param_2 = obj.getAllTasks(userId)
# param_3 = obj.getTasksForTag(userId,tag)
# obj.completeTask(userId,taskId)
```

#### Java

```java
class Task {
    int taskId;
    String taskName;
    int dueDate;
    Set<String> tags;
    boolean finish;

    public Task(int taskId, String taskName, int dueDate, Set<String> tags) {
        this.taskId = taskId;
        this.taskName = taskName;
        this.dueDate = dueDate;
        this.tags = tags;
    }
}

class TodoList {
    private int i = 1;
    private Map<Integer, TreeSet<Task>> tasks = new HashMap<>();

    public TodoList() {
    }

    public int addTask(int userId, String taskDescription, int dueDate, List<String> tags) {
        Task task = new Task(i++, taskDescription, dueDate, new HashSet<>(tags));
        tasks.computeIfAbsent(userId, k -> new TreeSet<>(Comparator.comparingInt(a -> a.dueDate)))
            .add(task);
        return task.taskId;
    }

    public List<String> getAllTasks(int userId) {
        List<String> ans = new ArrayList<>();
        if (tasks.containsKey(userId)) {
            for (Task task : tasks.get(userId)) {
                if (!task.finish) {
                    ans.add(task.taskName);
                }
            }
        }
        return ans;
    }

    public List<String> getTasksForTag(int userId, String tag) {
        List<String> ans = new ArrayList<>();
        if (tasks.containsKey(userId)) {
            for (Task task : tasks.get(userId)) {
                if (task.tags.contains(tag) && !task.finish) {
                    ans.add(task.taskName);
                }
            }
        }
        return ans;
    }

    public void completeTask(int userId, int taskId) {
        if (tasks.containsKey(userId)) {
            for (Task task : tasks.get(userId)) {
                if (task.taskId == taskId) {
                    task.finish = true;
                    break;
                }
            }
        }
    }
}

/**
 * Your TodoList object will be instantiated and called as such:
 * TodoList obj = new TodoList();
 * int param_1 = obj.addTask(userId,taskDescription,dueDate,tags);
 * List<String> param_2 = obj.getAllTasks(userId);
 * List<String> param_3 = obj.getTasksForTag(userId,tag);
 * obj.completeTask(userId,taskId);
 */
```

#### Rust

```rust
use std::collections::{HashMap, HashSet};

#[derive(Clone)]
struct Task {
    task_id: i32,
    description: String,
    tags: HashSet<String>,
    due_date: i32,
}

struct TodoList {
    /// The global task id
    id: i32,
    /// The mapping from `user_id` to `task`
    user_map: HashMap<i32, Vec<Task>>,
}

impl TodoList {
    fn new() -> Self {
        Self {
            id: 1,
            user_map: HashMap::new(),
        }
    }

    fn add_task(
        &mut self,
        user_id: i32,
        task_description: String,
        due_date: i32,
        tags: Vec<String>,
    ) -> i32 {
        if self.user_map.contains_key(&user_id) {
            // Just add the task
            self.user_map.get_mut(&user_id).unwrap().push(Task {
                task_id: self.id,
                description: task_description,
                tags: tags.into_iter().collect::<HashSet<String>>(),
                due_date,
            });
            // Increase the global id
            self.id += 1;
            return self.id - 1;
        }
        // Otherwise, create a new user
        self.user_map.insert(
            user_id,
            vec![Task {
                task_id: self.id,
                description: task_description,
                tags: tags.into_iter().collect::<HashSet<String>>(),
                due_date,
            }],
        );
        self.id += 1;
        self.id - 1
    }

    fn get_all_tasks(&self, user_id: i32) -> Vec<String> {
        if !self.user_map.contains_key(&user_id) || self.user_map.get(&user_id).unwrap().is_empty()
        {
            return vec![];
        }
        // Get the task vector
        let mut ret_vec = (*self.user_map.get(&user_id).unwrap()).clone();
        // Sort by due date
        ret_vec.sort_by(|lhs, rhs| lhs.due_date.cmp(&rhs.due_date));
        // Return the description vector
        ret_vec.into_iter().map(|x| x.description).collect()
    }

    fn get_tasks_for_tag(&self, user_id: i32, tag: String) -> Vec<String> {
        if !self.user_map.contains_key(&user_id) || self.user_map.get(&user_id).unwrap().is_empty()
        {
            return vec![];
        }
        // Get the task vector
        let mut ret_vec = (*self.user_map.get(&user_id).unwrap()).clone();
        // Sort by due date
        ret_vec.sort_by(|lhs, rhs| lhs.due_date.cmp(&rhs.due_date));
        // Return the description vector
        ret_vec
            .into_iter()
            .filter(|x| x.tags.contains(&tag))
            .map(|x| x.description)
            .collect()
    }

    fn complete_task(&mut self, user_id: i32, task_id: i32) {
        if !self.user_map.contains_key(&user_id) || self.user_map.get(&user_id).unwrap().is_empty()
        {
            return;
        }
        self.user_map
            .get_mut(&user_id)
            .unwrap()
            .retain(|x| (*x).task_id != task_id);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2591. 将钱分给最多的儿童](https://leetcode.cn/problems/distribute-money-to-maximum-children){#2591}

{{< tabs "2591" >}}

{{% tab "python" %}}
```python
class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        if money > 8 * children:
            return children - 1
        if money == 8 * children - 4:
            return children - 2
        # money-8x >= children-x, x <= (money-children)/7
        return (money - children) // 7
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money > 8 * children) {
            return children - 1;
        }
        if (money == 8 * children - 4) {
            return children - 2;
        }
        // money-8x >= children-x, x <= (money-children)/7
        return (money - children) / 7;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money > 8 * children) {
            return children - 1;
        }
        if (money == 8 * children - 4) {
            return children - 2;
        }
        // money-8x >= children-x, x <= (money-children)/7
        return (money - children) / 7;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distMoney(money int, children int) int {
	if money < children {
		return -1
	}
	if money > 8*children {
		return children - 1
	}
	if money == 8*children-4 {
		return children - 2
	}
	// money-8x >= children-x, x <= (money-children)/7
	return (money - children) / 7
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distMoney(money: number, children: number): number {
    if (money < children) {
        return -1;
    }
    if (money > 8 * children) {
        return children - 1;
    }
    if (money === 8 * children - 4) {
        return children - 2;
    }
    return Math.floor((money - children) / 7);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn dist_money(money: i32, children: i32) -> i32 {
        if money < children {
            return -1;
        }

        if money > children * 8 {
            return children - 1;
        }

        if money == children * 8 - 4 {
            return children - 2;
        }

        (money - children) / 7
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数&nbsp;<code>money</code>&nbsp;，表示你总共有的钱数（单位为美元）和另一个整数&nbsp;<code>children</code>&nbsp;，表示你要将钱分配给多少个儿童。</p>

<p>你需要按照如下规则分配：</p>

<ul>
	<li>所有的钱都必须被分配。</li>
	<li>每个儿童至少获得&nbsp;<code>1</code>&nbsp;美元。</li>
	<li>没有人获得 <code>4</code>&nbsp;美元。</li>
</ul>

<p>请你按照上述规则分配金钱，并返回 <strong>最多</strong>&nbsp;有多少个儿童获得 <strong>恰好</strong><em>&nbsp;</em><code>8</code>&nbsp;美元。如果没有任何分配方案，返回&nbsp;<code>-1</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>money = 20, children = 3
<b>输出：</b>1
<b>解释：</b>
最多获得 8 美元的儿童数为 1 。一种分配方案为：
- 给第一个儿童分配 8 美元。
- 给第二个儿童分配 9 美元。
- 给第三个儿童分配 3 美元。
没有分配方案能让获得 8 美元的儿童数超过 1 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>money = 16, children = 2
<b>输出：</b>2
<b>解释：</b>每个儿童都可以获得 8 美元。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= money &lt;= 200</code></li>
	<li><code>2 &lt;= children &lt;= 30</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分类讨论

如果 $money \lt children$，那么一定存在儿童没有分到钱，返回 $-1$。

如果 $money \gt 8 \times children$，那么有 $children-1$ 个儿童获得了 $8$ 美元，剩下的一个儿童获得了 $money - 8 \times (children-1)$ 美元，返回 $children-1$。

如果 $money = 8 \times children - 4$，那么有 $children-2$ 个儿童获得了 $8$ 美元，剩下的两个儿童分摊剩下的 $12$ 美元（只要不是 $4$, $8$ 美元就行），返回 $children-2$。

如果，我们假设有 $x$ 个儿童获得了 $8$ 美元，那么剩下的钱为 $money- 8 \times x$，只要保证大于等于剩下的儿童数 $children-x$，就可以满足题意。因此，我们只需要求出 $x$ 的最大值，即为答案。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def distMoney(self, money: int, children: int) -> int:
        if money < children:
            return -1
        if money > 8 * children:
            return children - 1
        if money == 8 * children - 4:
            return children - 2
        # money-8x >= children-x, x <= (money-children)/7
        return (money - children) // 7
```

#### Java

```java
class Solution {
    public int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money > 8 * children) {
            return children - 1;
        }
        if (money == 8 * children - 4) {
            return children - 2;
        }
        // money-8x >= children-x, x <= (money-children)/7
        return (money - children) / 7;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if (money > 8 * children) {
            return children - 1;
        }
        if (money == 8 * children - 4) {
            return children - 2;
        }
        // money-8x >= children-x, x <= (money-children)/7
        return (money - children) / 7;
    }
};
```

#### Go

```go
func distMoney(money int, children int) int {
	if money < children {
		return -1
	}
	if money > 8*children {
		return children - 1
	}
	if money == 8*children-4 {
		return children - 2
	}
	// money-8x >= children-x, x <= (money-children)/7
	return (money - children) / 7
}
```

#### TypeScript

```ts
function distMoney(money: number, children: number): number {
    if (money < children) {
        return -1;
    }
    if (money > 8 * children) {
        return children - 1;
    }
    if (money === 8 * children - 4) {
        return children - 2;
    }
    return Math.floor((money - children) / 7);
}
```

#### Rust

```rust
impl Solution {
    pub fn dist_money(money: i32, children: i32) -> i32 {
        if money < children {
            return -1;
        }

        if money > children * 8 {
            return children - 1;
        }

        if money == children * 8 - 4 {
            return children - 2;
        }

        (money - children) / 7
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2592. 最大化数组的伟大值](https://leetcode.cn/problems/maximize-greatness-of-an-array){#2592}

{{< tabs "2592" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        i = 0
        for x in nums:
            i += x > nums[i]
        return i
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximizeGreatness(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        for (int x : nums) {
            if (x > nums[i]) {
                ++i;
            }
        }
        return i;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int x : nums) {
            i += x > nums[i];
        }
        return i;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximizeGreatness(nums []int) int {
	sort.Ints(nums)
	i := 0
	for _, x := range nums {
		if x > nums[i] {
			i++
		}
	}
	return i
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximizeGreatness(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let i = 0;
    for (const x of nums) {
        if (x > nums[i]) {
            i += 1;
        }
    }
    return i;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 0 开始的整数数组&nbsp;<code>nums</code>&nbsp;。你需要将&nbsp;<code>nums</code>&nbsp;重新排列成一个新的数组&nbsp;<code>perm</code>&nbsp;。</p>

<p>定义 <code>nums</code>&nbsp;的 <strong>伟大值</strong>&nbsp;为满足&nbsp;<code>0 &lt;= i &lt; nums.length</code>&nbsp;且&nbsp;<code>perm[i] &gt; nums[i]</code>&nbsp;的下标数目。</p>

<p>请你返回重新排列 <code>nums</code>&nbsp;后的 <strong>最大</strong>&nbsp;伟大值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,3,5,2,1,3,1]
<b>输出：</b>4
<b>解释：</b>一个最优安排方案为 perm = [2,5,1,3,3,1,1] 。
在下标为 0, 1, 3 和 4 处，都有 perm[i] &gt; nums[i] 。因此我们返回 4 。</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [1,2,3,4]
<b>输出：</b>3
<b>解释：</b>最优排列为 [2,3,4,1] 。
在下标为 0, 1 和 2 处，都有 perm[i] &gt; nums[i] 。因此我们返回 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们可以先将数组 $nums$ 进行排序。

接下来定义一个指针 $i$，初始时指向数组 $nums$ 的第一个元素。然后遍历数组 $nums$，对于遍历到的每个元素 $x$，如果 $x$ 大于 $nums[i]$，则将指针 $i$ 向右移动一位。

最后返回指针 $i$ 的值即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        i = 0
        for x in nums:
            i += x > nums[i]
        return i
```

#### Java

```java
class Solution {
    public int maximizeGreatness(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        for (int x : nums) {
            if (x > nums[i]) {
                ++i;
            }
        }
        return i;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int x : nums) {
            i += x > nums[i];
        }
        return i;
    }
};
```

#### Go

```go
func maximizeGreatness(nums []int) int {
	sort.Ints(nums)
	i := 0
	for _, x := range nums {
		if x > nums[i] {
			i++
		}
	}
	return i
}
```

#### TypeScript

```ts
function maximizeGreatness(nums: number[]): number {
    nums.sort((a, b) => a - b);
    let i = 0;
    for (const x of nums) {
        if (x > nums[i]) {
            i += 1;
        }
    }
    return i;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2593. 标记所有元素后数组的分数](https://leetcode.cn/problems/find-score-of-an-array-after-marking-all-elements){#2593}

{{< tabs "2593" >}}

{{% tab "python" %}}
```python
class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        vis = [False] * (n + 2)
        idx = sorted(range(n), key=lambda i: (nums[i], i))
        ans = 0
        for i in idx:
            if not vis[i + 1]:
                ans += nums[i]
                vis[i] = vis[i + 2] = True
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[n + 2];
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums[i] - nums[j]);
        long ans = 0;
        for (int i : idx) {
            if (!vis[i + 1]) {
                ans += nums[i];
                vis[i] = true;
                vis[i + 2] = true;
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
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j] || (nums[i] == nums[j] && i < j);
        });
        long long ans = 0;
        vector<bool> vis(n + 2);
        for (int i : idx) {
            if (!vis[i + 1]) {
                ans += nums[i];
                vis[i] = vis[i + 2] = true;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findScore(nums []int) (ans int64) {
	n := len(nums)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		i, j = idx[i], idx[j]
		return nums[i] < nums[j] || (nums[i] == nums[j] && i < j)
	})
	vis := make([]bool, n+2)
	for _, i := range idx {
		if !vis[i+1] {
			ans += int64(nums[i])
			vis[i], vis[i+2] = true, true
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findScore(nums: number[]): number {
    const n = nums.length;
    const idx: number[] = new Array(n);
    for (let i = 0; i < n; ++i) {
        idx[i] = i;
    }
    idx.sort((i, j) => (nums[i] == nums[j] ? i - j : nums[i] - nums[j]));
    const vis: boolean[] = new Array(n + 2).fill(false);
    let ans = 0;
    for (const i of idx) {
        if (!vis[i + 1]) {
            ans += nums[i];
            vis[i] = true;
            vis[i + 2] = true;
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

<p>给你一个数组&nbsp;<code>nums</code>&nbsp;，它包含若干正整数。</p>

<p>一开始分数&nbsp;<code>score = 0</code>&nbsp;，请你按照下面算法求出最后分数：</p>

<ul>
	<li>从数组中选择最小且没有被标记的整数。如果有相等元素，选择下标最小的一个。</li>
	<li>将选中的整数加到&nbsp;<code>score</code>&nbsp;中。</li>
	<li>标记 <strong>被选中元素</strong>，如果有相邻元素，则同时标记&nbsp;<strong>与它相邻的两个元素</strong>&nbsp;。</li>
	<li>重复此过程直到数组中所有元素都被标记。</li>
</ul>

<p>请你返回执行上述算法后最后的分数。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [2,1,3,4,5,2]
<b>输出：</b>7
<b>解释：</b>我们按照如下步骤标记元素：
- 1 是最小未标记元素，所以标记它和相邻两个元素：[<u><em><strong>2</strong></em></u>,<u><em><strong>1</strong></em></u>,<u><em><strong>3</strong></em></u>,4,5,2] 。
- 2 是最小未标记元素，所以标记它和左边相邻元素：[<u><em><strong>2</strong></em></u>,<u><em><strong>1</strong></em></u>,<u><em><strong>3</strong></em></u>,4,<u><em><strong>5</strong></em></u>,<u><em><strong>2</strong></em></u>] 。
- 4 是仅剩唯一未标记的元素，所以我们标记它：[<u><em><strong>2</strong></em></u>,<u><em><strong>1</strong></em></u>,<u><em><strong>3</strong></em></u>,<u><em><strong>4</strong></em></u>,<u><em><strong>5</strong></em></u>,<u><em><strong>2</strong></em></u>] 。
总得分为 1 + 2 + 4 = 7 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,5,1,3,2]
<b>输出：</b>5
<b>解释：</b>我们按照如下步骤标记元素：
- 1 是最小未标记元素，所以标记它和相邻两个元素：[2,3,<u><em><strong>5</strong></em></u>,<u><em><strong>1</strong></em></u>,<u><em><strong>3</strong></em></u>,2] 。
- 2 是最小未标记元素，由于有两个 2 ，我们选择最左边的一个 2 ，也就是下标为 0 处的 2 ，以及它右边相邻的元素：[<u><em><strong>2</strong></em></u>,<u><em><strong>3</strong></em></u>,<u><em><strong>5</strong></em></u>,<u><em><strong>1</strong></em></u>,<u><em><strong>3</strong></em></u>,2] 。
- 2 是仅剩唯一未标记的元素，所以我们标记它：[<u><em><strong>2</strong></em></u>,<u><em><strong>3</strong></em></u>,<u><em><strong>5</strong></em></u>,<u><em><strong>1</strong></em></u>,<u><em><strong>3</strong></em></u>,<u><em><strong>2</strong></em></u>] 。
总得分为 1 + 2 + 2 = 5 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：优先队列（小根堆）

我们用一个优先队列维护数组中未被标记的元素，队列中每一项为一个二元组 $(x, i)$，其中 $x$ 和 $i$ 分别表示数组中的元素值和下标，用一个数组 $vis$ 记录数组中的元素是否被标记。

每次从队列中取出最小的元素 $(x, i)$，我们将 $x$ 加入答案，然后标记 $i$ 位置的元素，以及 $i$ 位置的左右相邻元素，即 $i - 1$ 和 $i + 1$ 位置的元素。接下来判断堆顶元素是否被标记，如果被标记则弹出堆顶元素，直到堆顶元素未被标记，或者堆为空。

最后返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        vis = [False] * n
        q = [(x, i) for i, x in enumerate(nums)]
        heapify(q)
        ans = 0
        while q:
            x, i = heappop(q)
            ans += x
            vis[i] = True
            for j in (i - 1, i + 1):
                if 0 <= j < n:
                    vis[j] = True
            while q and vis[q[0][1]]:
                heappop(q)
        return ans
```

#### Java

```java
class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[n];
        PriorityQueue<int[]> q
            = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < n; ++i) {
            q.offer(new int[] {nums[i], i});
        }
        long ans = 0;
        while (!q.isEmpty()) {
            var p = q.poll();
            ans += p[0];
            vis[p[1]] = true;
            for (int j : List.of(p[1] - 1, p[1] + 1)) {
                if (j >= 0 && j < n) {
                    vis[j] = true;
                }
            }
            while (!q.isEmpty() && vis[q.peek()[1]]) {
                q.poll();
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
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n);
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int i = 0; i < n; ++i) {
            q.emplace(nums[i], i);
        }
        long long ans = 0;
        while (!q.empty()) {
            auto [x, i] = q.top();
            q.pop();
            ans += x;
            vis[i] = true;
            if (i + 1 < n) {
                vis[i + 1] = true;
            }
            if (i - 1 >= 0) {
                vis[i - 1] = true;
            }
            while (!q.empty() && vis[q.top().second]) {
                q.pop();
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findScore(nums []int) (ans int64) {
	h := hp{}
	for i, x := range nums {
		heap.Push(&h, pair{x, i})
	}
	n := len(nums)
	vis := make([]bool, n)
	for len(h) > 0 {
		p := heap.Pop(&h).(pair)
		x, i := p.x, p.i
		ans += int64(x)
		vis[i] = true
		for _, j := range []int{i - 1, i + 1} {
			if j >= 0 && j < n {
				vis[j] = true
			}
		}
		for len(h) > 0 && vis[h[0].i] {
			heap.Pop(&h)
		}
	}
	return
}

type pair struct{ x, i int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].x < h[j].x || (h[i].x == h[j].x && h[i].i < h[j].i) }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() any          { a := *h; v := a[len(a)-1]; *h = a[:len(a)-1]; return v }
```

#### TypeScript

```ts
interface pair {
    x: number;
    i: number;
}

function findScore(nums: number[]): number {
    const q = new PriorityQueue({
        compare: (a: pair, b: pair) => (a.x === b.x ? a.i - b.i : a.x - b.x),
    });
    const n = nums.length;
    const vis: boolean[] = new Array(n).fill(false);
    for (let i = 0; i < n; ++i) {
        q.enqueue({ x: nums[i], i });
    }
    let ans = 0;
    while (!q.isEmpty()) {
        const { x, i } = q.dequeue()!;
        if (vis[i]) {
            continue;
        }
        ans += x;
        vis[i] = true;
        if (i - 1 >= 0) {
            vis[i - 1] = true;
        }
        if (i + 1 < n) {
            vis[i + 1] = true;
        }
        while (!q.isEmpty() && vis[q.front()!.i]) {
            q.dequeue();
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：排序

我们可以创建一个下标数组 $idx$，其中 $idx[i]=i$，然后我们对数组 $idx$ 按照数组 $nums$ 中的元素值进行排序，如果元素值相同，则按照下标值进行排序。

接下来创建一个长度为 $n+2$ 的数组 $vis$，其中 $vis[i]=false$，表示数组中的元素是否被标记。

我们遍历下标数组 $idx$，对于数组中的每一个下标 $i$，如果 $vis[i + 1]$ 为 $false$，则表示 $i$ 位置的元素未被标记，我们将 $nums[i]$ 加入答案，然后标记 $i$ 位置的元素，以及 $i$ 位置的左右相邻元素，即 $i - 1$ 和 $i + 1$ 位置的元素。继续遍历下标数组 $idx$，直到遍历结束。

最后返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        vis = [False] * (n + 2)
        idx = sorted(range(n), key=lambda i: (nums[i], i))
        ans = 0
        for i in idx:
            if not vis[i + 1]:
                ans += nums[i]
                vis[i] = vis[i + 2] = True
        return ans
```

#### Java

```java
class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        boolean[] vis = new boolean[n + 2];
        Integer[] idx = new Integer[n];
        Arrays.setAll(idx, i -> i);
        Arrays.sort(idx, (i, j) -> nums[i] - nums[j]);
        long ans = 0;
        for (int i : idx) {
            if (!vis[i + 1]) {
                ans += nums[i];
                vis[i] = true;
                vis[i + 2] = true;
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
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j] || (nums[i] == nums[j] && i < j);
        });
        long long ans = 0;
        vector<bool> vis(n + 2);
        for (int i : idx) {
            if (!vis[i + 1]) {
                ans += nums[i];
                vis[i] = vis[i + 2] = true;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findScore(nums []int) (ans int64) {
	n := len(nums)
	idx := make([]int, n)
	for i := range idx {
		idx[i] = i
	}
	sort.Slice(idx, func(i, j int) bool {
		i, j = idx[i], idx[j]
		return nums[i] < nums[j] || (nums[i] == nums[j] && i < j)
	})
	vis := make([]bool, n+2)
	for _, i := range idx {
		if !vis[i+1] {
			ans += int64(nums[i])
			vis[i], vis[i+2] = true, true
		}
	}
	return
}
```

#### TypeScript

```ts
function findScore(nums: number[]): number {
    const n = nums.length;
    const idx: number[] = new Array(n);
    for (let i = 0; i < n; ++i) {
        idx[i] = i;
    }
    idx.sort((i, j) => (nums[i] == nums[j] ? i - j : nums[i] - nums[j]));
    const vis: boolean[] = new Array(n + 2).fill(false);
    let ans = 0;
    for (const i of idx) {
        if (!vis[i + 1]) {
            ans += nums[i];
            vis[i] = true;
            vis[i + 2] = true;
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

# [2594. 修车的最少时间](https://leetcode.cn/problems/minimum-time-to-repair-cars){#2594}

{{< tabs "2594" >}}

{{% tab "python" %}}
```python
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def check(t: int) -> bool:
            return sum(int(sqrt(t // r)) for r in ranks) >= cars

        return bisect_left(range(ranks[0] * cars * cars), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long repairCars(int[] ranks, int cars) {
        long left = 0, right = 1L * ranks[0] * cars * cars;
        while (left < right) {
            long mid = (left + right) >> 1;
            long cnt = 0;
            for (int r : ranks) {
                cnt += Math.sqrt(mid / r);
            }
            if (cnt >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = 1LL * ranks[0] * cars * cars;
        while (left < right) {
            long long mid = (left + right) >> 1;
            long long cnt = 0;
            for (int r : ranks) {
                cnt += sqrt(mid / r);
            }
            if (cnt >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func repairCars(ranks []int, cars int) int64 {
	return int64(sort.Search(ranks[0]*cars*cars, func(t int) bool {
		cnt := 0
		for _, r := range ranks {
			cnt += int(math.Sqrt(float64(t / r)))
		}
		return cnt >= cars
	}))
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function repairCars(ranks: number[], cars: number): number {
    let left = 0;
    let right = ranks[0] * cars * cars;
    while (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        let cnt = 0;
        for (const r of ranks) {
            cnt += Math.floor(Math.sqrt(mid / r));
        }
        if (cnt >= cars) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>ranks</code>&nbsp;，表示一些机械工的 <strong>能力值</strong>&nbsp;。<code>ranks<sub>i</sub></code> 是第 <code>i</code> 位机械工的能力值。能力值为&nbsp;<code>r</code>&nbsp;的机械工可以在&nbsp;<code>r * n<sup>2</sup></code>&nbsp;分钟内修好&nbsp;<code>n</code>&nbsp;辆车。</p>

<p>同时给你一个整数&nbsp;<code>cars</code>&nbsp;，表示总共需要修理的汽车数目。</p>

<p>请你返回修理所有汽车&nbsp;<strong>最少</strong>&nbsp;需要多少时间。</p>

<p><strong>注意：</strong>所有机械工可以同时修理汽车。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>ranks = [4,2,3,1], cars = 10
<b>输出：</b>16
<b>解释：</b>
- 第一位机械工修 2 辆车，需要 4 * 2 * 2 = 16 分钟。
- 第二位机械工修 2 辆车，需要 2 * 2 * 2 = 8 分钟。
- 第三位机械工修 2 辆车，需要 3 * 2 * 2 = 12 分钟。
- 第四位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
16 分钟是修理完所有车需要的最少时间。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>ranks = [5,1,8], cars = 6
<b>输出：</b>16
<b>解释：</b>
- 第一位机械工修 1 辆车，需要 5 * 1 * 1 = 5 分钟。
- 第二位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
- 第三位机械工修 1 辆车，需要 8 * 1 * 1 = 8 分钟。
16 分钟时修理完所有车需要的最少时间。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= ranks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= ranks[i] &lt;= 100</code></li>
	<li><code>1 &lt;= cars &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，修车时间越长，修理的汽车数目也越多。因此，我们可以将修车时间作为二分查找的目标，二分查找修车时间的最小值。

我们定义二分查找的左右边界分别为 $left=0$, $right=ranks[0] \times cars \times cars$。接下来二分枚举修车时间 $mid$，每个机械工可以修理的汽车数目为 $\lfloor \sqrt{\frac{mid}{r}} \rfloor$，其中 $\lfloor x \rfloor$ 表示向下取整。如果修理的汽车数目大于等于 $cars$，则说明修车时间 $mid$ 可行，我们将右边界缩小至 $mid$，否则将左边界增大至 $mid+1$。

最终，我们返回左边界即可。

时间复杂度 $(n \times \log M)$，空间复杂度 $O(1)$。其中 $n$ 为机械工的数量，而 $M$ 为二分查找的上界。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def check(t: int) -> bool:
            return sum(int(sqrt(t // r)) for r in ranks) >= cars

        return bisect_left(range(ranks[0] * cars * cars), True, key=check)
```

#### Java

```java
class Solution {
    public long repairCars(int[] ranks, int cars) {
        long left = 0, right = 1L * ranks[0] * cars * cars;
        while (left < right) {
            long mid = (left + right) >> 1;
            long cnt = 0;
            for (int r : ranks) {
                cnt += Math.sqrt(mid / r);
            }
            if (cnt >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = 1LL * ranks[0] * cars * cars;
        while (left < right) {
            long long mid = (left + right) >> 1;
            long long cnt = 0;
            for (int r : ranks) {
                cnt += sqrt(mid / r);
            }
            if (cnt >= cars) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func repairCars(ranks []int, cars int) int64 {
	return int64(sort.Search(ranks[0]*cars*cars, func(t int) bool {
		cnt := 0
		for _, r := range ranks {
			cnt += int(math.Sqrt(float64(t / r)))
		}
		return cnt >= cars
	}))
}
```

#### TypeScript

```ts
function repairCars(ranks: number[], cars: number): number {
    let left = 0;
    let right = ranks[0] * cars * cars;
    while (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        let cnt = 0;
        for (const r of ranks) {
            cnt += Math.floor(Math.sqrt(mid / r));
        }
        if (cnt >= cars) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2595. 奇偶位数](https://leetcode.cn/problems/number-of-even-and-odd-bits){#2595}

{{< tabs "2595" >}}

{{% tab "python" %}}
```python
class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        mask = 0x5555
        even = (n & mask).bit_count()
        odd = (n & ~mask).bit_count()
        return [even, odd]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] evenOddBit(int n) {
        int mask = 0x5555;
        int even = Integer.bitCount(n & mask);
        int odd = Integer.bitCount(n & ~mask);
        return new int[] {even, odd};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int mask = 0x5555;
        int even = __builtin_popcount(n & mask);
        int odd = __builtin_popcount(n & ~mask);
        return {even, odd};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func evenOddBit(n int) []int {
	mask := 0x5555
	even := bits.OnesCount32(uint32(n & mask))
	odd := bits.OnesCount32(uint32(n & ^mask))
	return []int{even, odd}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function evenOddBit(n: number): number[] {
    const mask = 0x5555;
    const even = bitCount(n & mask);
    const odd = bitCount(n & ~mask);
    return [even, odd];
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        let mask: i32 = 0x5555;
        let even = (n & mask).count_ones() as i32;
        let odd = (n & !mask).count_ones() as i32;
        vec![even, odd]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>正</strong> 整数 <code>n</code> 。</p>

<p>用 <code>even</code> 表示在 <code>n</code> 的二进制形式（下标从 <strong>0</strong> 开始）中值为 <code>1</code> 的偶数下标的个数。</p>

<p>用 <code>odd</code> 表示在 <code>n</code> 的二进制形式（下标从 <strong>0</strong> 开始）中值为 <code>1</code> 的奇数下标的个数。</p>

<p>请注意，在数字的二进制表示中，位下标的顺序&nbsp;<strong>从右到左</strong>。</p>

<p>返回整数数组<em> </em><code>answer</code><em> </em>，其中<em> </em><code>answer = [even, odd]</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>n = 50</span></p>

<p><span class="example-io"><b>输出：</b>[1,2]</span></p>

<p><strong>解释：</strong></p>

<p>50 的二进制表示是&nbsp;<code>110010</code>。</p>

<p>在下标 1，4，5 对应的值为&nbsp;1。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><strong>输入：</strong><span class="example-io">n = 2</span></p>

<p><span class="example-io"><b>输出：</b>[0,1]</span></p>

<p><strong>解释：</strong></p>

<p>2 的二进制表示是&nbsp;<code>10</code>。</p>

<p>只有下标 1 对应的值为&nbsp;1。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们根据题意，枚举 $n$ 的二进制表示中从低位到高位的每一位，如果该位为 $1$，则根据该位的下标是奇数还是偶数，将对应的计数器加 $1$ 即可。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        ans = [0, 0]
        i = 0
        while n:
            ans[i] += n & 1
            i ^= 1
            n >>= 1
        return ans
```

#### Java

```java
class Solution {
    public int[] evenOddBit(int n) {
        int[] ans = new int[2];
        for (int i = 0; n > 0; n >>= 1, i ^= 1) {
            ans[i] += n & 1;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2);
        for (int i = 0; n > 0; n >>= 1, i ^= 1) {
            ans[i] += n & 1;
        }
        return ans;
    }
};
```

#### Go

```go
func evenOddBit(n int) []int {
	ans := make([]int, 2)
	for i := 0; n != 0; n, i = n>>1, i^1 {
		ans[i] += n & 1
	}
	return ans
}
```

#### TypeScript

```ts
function evenOddBit(n: number): number[] {
    const ans = Array(2).fill(0);
    for (let i = 0; n > 0; n >>= 1, i ^= 1) {
        ans[i] += n & 1;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn even_odd_bit(mut n: i32) -> Vec<i32> {
        let mut ans = vec![0; 2];

        let mut i = 0;
        while n != 0 {
            ans[i] += n & 1;

            n >>= 1;
            i ^= 1;
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：位运算

我们可以定义一个掩码 $\textit{mask} = \text{0x5555}$，它的二进制表示为 $\text{0101 0101 0101 0101}_2$。那么 $n$ 与 $\textit{mask}$ 进行按位与运算，就可以得到 $n$ 的二进制表示中偶数下标的位，而 $n$ 与 $\textit{mask}$ 取反后再进行按位与运算，就可以得到 $n$ 的二进制表示中奇数下标的位。统计这两个结果中 $1$ 的个数即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。其中 $n$ 为给定的整数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        mask = 0x5555
        even = (n & mask).bit_count()
        odd = (n & ~mask).bit_count()
        return [even, odd]
```

#### Java

```java
class Solution {
    public int[] evenOddBit(int n) {
        int mask = 0x5555;
        int even = Integer.bitCount(n & mask);
        int odd = Integer.bitCount(n & ~mask);
        return new int[] {even, odd};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int mask = 0x5555;
        int even = __builtin_popcount(n & mask);
        int odd = __builtin_popcount(n & ~mask);
        return {even, odd};
    }
};
```

#### Go

```go
func evenOddBit(n int) []int {
	mask := 0x5555
	even := bits.OnesCount32(uint32(n & mask))
	odd := bits.OnesCount32(uint32(n & ^mask))
	return []int{even, odd}
}
```

#### TypeScript

```ts
function evenOddBit(n: number): number[] {
    const mask = 0x5555;
    const even = bitCount(n & mask);
    const odd = bitCount(n & ~mask);
    return [even, odd];
}

function bitCount(i: number): number {
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```

#### Rust

```rust
impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        let mask: i32 = 0x5555;
        let even = (n & mask).count_ones() as i32;
        let odd = (n & !mask).count_ones() as i32;
        vec![even, odd]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2596. 检查骑士巡视方案](https://leetcode.cn/problems/check-knight-tour-configuration){#2596}

{{< tabs "2596" >}}

{{% tab "python" %}}
```python
class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        if grid[0][0]:
            return False
        n = len(grid)
        pos = [None] * (n * n)
        for i in range(n):
            for j in range(n):
                pos[grid[i][j]] = (i, j)
        for (x1, y1), (x2, y2) in pairwise(pos):
            dx, dy = abs(x1 - x2), abs(y1 - y2)
            ok = (dx == 1 and dy == 2) or (dx == 2 and dy == 1)
            if not ok:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean checkValidGrid(int[][] grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.length;
        int[][] pos = new int[n * n][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = new int[] {i, j};
            }
        }
        for (int i = 1; i < n * n; ++i) {
            int[] p1 = pos[i - 1];
            int[] p2 = pos[i];
            int dx = Math.abs(p1[0] - p2[0]);
            int dy = Math.abs(p1[1] - p2[1]);
            boolean ok = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
            if (!ok) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = {i, j};
            }
        }
        for (int i = 1; i < n * n; ++i) {
            auto [x1, y1] = pos[i - 1];
            auto [x2, y2] = pos[i];
            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);
            bool ok = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
            if (!ok) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func checkValidGrid(grid [][]int) bool {
	if grid[0][0] != 0 {
		return false
	}
	n := len(grid)
	type pair struct{ x, y int }
	pos := make([]pair, n*n)
	for i, row := range grid {
		for j, x := range row {
			pos[x] = pair{i, j}
		}
	}
	for i := 1; i < n*n; i++ {
		p1, p2 := pos[i-1], pos[i]
		dx := abs(p1.x - p2.x)
		dy := abs(p1.y - p2.y)
		ok := (dx == 2 && dy == 1) || (dx == 1 && dy == 2)
		if !ok {
			return false
		}
	}
	return true
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function checkValidGrid(grid: number[][]): boolean {
    if (grid[0][0] !== 0) {
        return false;
    }
    const n = grid.length;
    const pos = Array.from(new Array(n * n), () => new Array(2).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            pos[grid[i][j]] = [i, j];
        }
    }
    for (let i = 1; i < n * n; ++i) {
        const p1 = pos[i - 1];
        const p2 = pos[i];
        const dx = Math.abs(p1[0] - p2[0]);
        const dy = Math.abs(p1[1] - p2[1]);
        const ok = (dx === 1 && dy === 2) || (dx === 2 && dy === 1);
        if (!ok) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>骑士在一张 <code>n x n</code> 的棋盘上巡视。在&nbsp;<strong>有效&nbsp;</strong>的巡视方案中，骑士会从棋盘的 <strong>左上角</strong> 出发，并且访问棋盘上的每个格子 <strong>恰好一次</strong> 。</p>

<p>给你一个 <code>n x n</code> 的整数矩阵 <code>grid</code> ，由范围 <code>[0, n * n - 1]</code> 内的不同整数组成，其中 <code>grid[row][col]</code> 表示单元格 <code>(row, col)</code> 是骑士访问的第 <code>grid[row][col]</code> 个单元格。骑士的行动是从下标 <strong>0</strong> 开始的。</p>

<p>如果 <code>grid</code> 表示了骑士的有效巡视方案，返回 <code>true</code>；否则返回 <code>false</code>。</p>

<p><strong>注意</strong>，骑士行动时可以垂直移动两个格子且水平移动一个格子，或水平移动两个格子且垂直移动一个格子。下图展示了骑士从某个格子出发可能的八种行动路线。<br />
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2596.Check%20Knight%20Tour%20Configuration/images/1694590028-CTMBQL-image.png" style="width: 350px; height: 350px;" /></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2596.Check%20Knight%20Tour%20Configuration/images/1694590044-AmhkRb-image.png" style="width: 251px; height: 251px;" />
<pre>
<strong>输入：</strong>grid = [[0,11,16,5,20],[17,4,19,10,15],[12,1,8,21,6],[3,18,23,14,9],[24,13,2,7,22]]
<strong>输出：</strong>true
<strong>解释：</strong>grid 如上图所示，可以证明这是一个有效的巡视方案。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2500-2599/2596.Check%20Knight%20Tour%20Configuration/images/1694590057-FIMBAG-image.png" style="width: 151px; height: 151px;" />
<pre>
<strong>输入：</strong>grid = [[0,3,6],[5,8,1],[2,7,4]]
<strong>输出：</strong>false
<strong>解释：</strong>grid 如上图所示，考虑到骑士第 7 次行动后的位置，第 8 次行动是无效的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>3 &lt;= n &lt;= 7</code></li>
	<li><code>0 &lt;= grid[row][col] &lt; n * n</code></li>
	<li><code>grid</code> 中的所有整数 <strong>互不相同</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们先用数组 $\textit{pos}$ 记录骑士访问的每个格子的坐标，然后遍历 $\textit{pos}$ 数组，检查相邻两个格子的坐标差是否为 $(1, 2)$ 或 $(2, 1)$ 即可。若不满足，则返回 $\textit{false}$。

否则遍历结束后，返回 $\textit{true}$

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 为棋盘的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        if grid[0][0]:
            return False
        n = len(grid)
        pos = [None] * (n * n)
        for i in range(n):
            for j in range(n):
                pos[grid[i][j]] = (i, j)
        for (x1, y1), (x2, y2) in pairwise(pos):
            dx, dy = abs(x1 - x2), abs(y1 - y2)
            ok = (dx == 1 and dy == 2) or (dx == 2 and dy == 1)
            if not ok:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean checkValidGrid(int[][] grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.length;
        int[][] pos = new int[n * n][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = new int[] {i, j};
            }
        }
        for (int i = 1; i < n * n; ++i) {
            int[] p1 = pos[i - 1];
            int[] p2 = pos[i];
            int dx = Math.abs(p1[0] - p2[0]);
            int dy = Math.abs(p1[1] - p2[1]);
            boolean ok = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
            if (!ok) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[grid[i][j]] = {i, j};
            }
        }
        for (int i = 1; i < n * n; ++i) {
            auto [x1, y1] = pos[i - 1];
            auto [x2, y2] = pos[i];
            int dx = abs(x1 - x2);
            int dy = abs(y1 - y2);
            bool ok = (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
            if (!ok) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func checkValidGrid(grid [][]int) bool {
	if grid[0][0] != 0 {
		return false
	}
	n := len(grid)
	type pair struct{ x, y int }
	pos := make([]pair, n*n)
	for i, row := range grid {
		for j, x := range row {
			pos[x] = pair{i, j}
		}
	}
	for i := 1; i < n*n; i++ {
		p1, p2 := pos[i-1], pos[i]
		dx := abs(p1.x - p2.x)
		dy := abs(p1.y - p2.y)
		ok := (dx == 2 && dy == 1) || (dx == 1 && dy == 2)
		if !ok {
			return false
		}
	}
	return true
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
function checkValidGrid(grid: number[][]): boolean {
    if (grid[0][0] !== 0) {
        return false;
    }
    const n = grid.length;
    const pos = Array.from(new Array(n * n), () => new Array(2).fill(0));
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            pos[grid[i][j]] = [i, j];
        }
    }
    for (let i = 1; i < n * n; ++i) {
        const p1 = pos[i - 1];
        const p2 = pos[i];
        const dx = Math.abs(p1[0] - p2[0]);
        const dy = Math.abs(p1[1] - p2[1]);
        const ok = (dx === 1 && dy === 2) || (dx === 2 && dy === 1);
        if (!ok) {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2597. 美丽子集的数目](https://leetcode.cn/problems/the-number-of-beautiful-subsets){#2597}

{{< tabs "2597" >}}

{{% tab "python" %}}
```python
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def dfs(i: int) -> None:
            nonlocal ans
            if i >= len(nums):
                ans += 1
                return
            dfs(i + 1)
            if cnt[nums[i] + k] == 0 and cnt[nums[i] - k] == 0:
                cnt[nums[i]] += 1
                dfs(i + 1)
                cnt[nums[i]] -= 1

        ans = -1
        cnt = Counter()
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;
    private int[] cnt = new int[1010];
    private int ans = -1;
    private int k;

    public int beautifulSubsets(int[] nums, int k) {
        this.k = k;
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= nums.length) {
            ++ans;
            return;
        }
        dfs(i + 1);
        boolean ok1 = nums[i] + k >= cnt.length || cnt[nums[i] + k] == 0;
        boolean ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;
        if (ok1 && ok2) {
            ++cnt[nums[i]];
            dfs(i + 1);
            --cnt[nums[i]];
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = -1;
        int cnt[1010]{};
        int n = nums.size();

        auto dfs = [&](this auto&& dfs, int i) {
            if (i >= n) {
                ++ans;
                return;
            }
            dfs(i + 1);
            bool ok1 = nums[i] + k >= 1010 || cnt[nums[i] + k] == 0;
            bool ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;
            if (ok1 && ok2) {
                ++cnt[nums[i]];
                dfs(i + 1);
                --cnt[nums[i]];
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func beautifulSubsets(nums []int, k int) int {
	ans := -1
	n := len(nums)
	cnt := [1010]int{}
	var dfs func(int)
	dfs = func(i int) {
		if i >= n {
			ans++
			return
		}
		dfs(i + 1)
		ok1 := nums[i]+k >= len(cnt) || cnt[nums[i]+k] == 0
		ok2 := nums[i]-k < 0 || cnt[nums[i]-k] == 0
		if ok1 && ok2 {
			cnt[nums[i]]++
			dfs(i + 1)
			cnt[nums[i]]--
		}
	}
	dfs(0)
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function beautifulSubsets(nums: number[], k: number): number {
    let ans: number = -1;
    const cnt: number[] = new Array(1010).fill(0);
    const n: number = nums.length;
    const dfs = (i: number) => {
        if (i >= n) {
            ++ans;
            return;
        }
        dfs(i + 1);
        const ok1: boolean = nums[i] + k >= 1010 || cnt[nums[i] + k] === 0;
        const ok2: boolean = nums[i] - k < 0 || cnt[nums[i] - k] === 0;
        if (ok1 && ok2) {
            ++cnt[nums[i]];
            dfs(i + 1);
            --cnt[nums[i]];
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int BeautifulSubsets(int[] nums, int k) {
        int ans = -1;
        int[] cnt = new int[1010];
        int n = nums.Length;

        void Dfs(int i) {
            if (i >= n) {
                ans++;
                return;
            }
            Dfs(i + 1);
            bool ok1 = nums[i] + k >= 1010 || cnt[nums[i] + k] == 0;
            bool ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;
            if (ok1 && ok2) {
                cnt[nums[i]]++;
                Dfs(i + 1);
                cnt[nums[i]]--;
            }
        }

        Dfs(0);
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个由正整数组成的数组 <code>nums</code> 和一个 <strong>正</strong> 整数 <code>k</code> 。</p>

<p>如果 <code>nums</code> 的子集中，任意两个整数的绝对差均不等于 <code>k</code> ，则认为该子数组是一个 <strong>美丽</strong> 子集。</p>

<p>返回数组 <code>nums</code> 中 <strong>非空</strong> 且 <strong>美丽</strong> 的子集数目。</p>

<p><code>nums</code> 的子集定义为：可以经由 <code>nums</code> 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,6], k = 2
<strong>输出：</strong>4
<strong>解释：</strong>数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1], k = 1
<strong>输出：</strong>1
<strong>解释：</strong>数组 nums 中的美丽数组有：[1] 。
可以证明数组 [1] 中只存在 1 个美丽子集。 
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 18</code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 回溯

我们用哈希表或数组 $\textit{cnt}$ 记录当前已经选择的数字以及它们的个数，用 $\textit{ans}$ 记录美丽子集的数目，初始时 $\textit{ans} = -1$，表示排除空集。

对于数组 $\textit{nums}$ 中的每个数字 $x$，我们有两种选择：

-   不选择 $x$，此时直接递归到下一个数字；
-   选择 $x$，此时需要判断 $x + k$ 和 $x - k$ 是否已经在 $\textit{cnt}$ 中出现过，如果都没有出现过，那么我们就可以选择 $x$，此时我们将 $x$ 的个数加一，然后递归到下一个数字，最后将 $x$ 的个数减一。

最后，我们返回 $\textit{ans}$ 即可。

时间复杂度 $O(2^n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def dfs(i: int) -> None:
            nonlocal ans
            if i >= len(nums):
                ans += 1
                return
            dfs(i + 1)
            if cnt[nums[i] + k] == 0 and cnt[nums[i] - k] == 0:
                cnt[nums[i]] += 1
                dfs(i + 1)
                cnt[nums[i]] -= 1

        ans = -1
        cnt = Counter()
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private int[] nums;
    private int[] cnt = new int[1010];
    private int ans = -1;
    private int k;

    public int beautifulSubsets(int[] nums, int k) {
        this.k = k;
        this.nums = nums;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (i >= nums.length) {
            ++ans;
            return;
        }
        dfs(i + 1);
        boolean ok1 = nums[i] + k >= cnt.length || cnt[nums[i] + k] == 0;
        boolean ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;
        if (ok1 && ok2) {
            ++cnt[nums[i]];
            dfs(i + 1);
            --cnt[nums[i]];
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = -1;
        int cnt[1010]{};
        int n = nums.size();

        auto dfs = [&](this auto&& dfs, int i) {
            if (i >= n) {
                ++ans;
                return;
            }
            dfs(i + 1);
            bool ok1 = nums[i] + k >= 1010 || cnt[nums[i] + k] == 0;
            bool ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;
            if (ok1 && ok2) {
                ++cnt[nums[i]];
                dfs(i + 1);
                --cnt[nums[i]];
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func beautifulSubsets(nums []int, k int) int {
	ans := -1
	n := len(nums)
	cnt := [1010]int{}
	var dfs func(int)
	dfs = func(i int) {
		if i >= n {
			ans++
			return
		}
		dfs(i + 1)
		ok1 := nums[i]+k >= len(cnt) || cnt[nums[i]+k] == 0
		ok2 := nums[i]-k < 0 || cnt[nums[i]-k] == 0
		if ok1 && ok2 {
			cnt[nums[i]]++
			dfs(i + 1)
			cnt[nums[i]]--
		}
	}
	dfs(0)
	return ans
}
```

#### TypeScript

```ts
function beautifulSubsets(nums: number[], k: number): number {
    let ans: number = -1;
    const cnt: number[] = new Array(1010).fill(0);
    const n: number = nums.length;
    const dfs = (i: number) => {
        if (i >= n) {
            ++ans;
            return;
        }
        dfs(i + 1);
        const ok1: boolean = nums[i] + k >= 1010 || cnt[nums[i] + k] === 0;
        const ok2: boolean = nums[i] - k < 0 || cnt[nums[i] - k] === 0;
        if (ok1 && ok2) {
            ++cnt[nums[i]];
            dfs(i + 1);
            --cnt[nums[i]];
        }
    };
    dfs(0);
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int BeautifulSubsets(int[] nums, int k) {
        int ans = -1;
        int[] cnt = new int[1010];
        int n = nums.Length;

        void Dfs(int i) {
            if (i >= n) {
                ans++;
                return;
            }
            Dfs(i + 1);
            bool ok1 = nums[i] + k >= 1010 || cnt[nums[i] + k] == 0;
            bool ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;
            if (ok1 && ok2) {
                cnt[nums[i]]++;
                Dfs(i + 1);
                cnt[nums[i]]--;
            }
        }

        Dfs(0);
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2598. 执行操作后的最大 MEX](https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations){#2598}

{{< tabs "2598" >}}

{{% tab "python" %}}
```python
class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        cnt = Counter(x % value for x in nums)
        for i in range(len(nums) + 1):
            if cnt[i % value] == 0:
                return i
            cnt[i % value] -= 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int[] cnt = new int[value];
        for (int x : nums) {
            ++cnt[(x % value + value) % value];
        }
        for (int i = 0;; ++i) {
            if (cnt[i % value]-- == 0) {
                return i;
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int cnt[value];
        memset(cnt, 0, sizeof(cnt));
        for (int x : nums) {
            ++cnt[(x % value + value) % value];
        }
        for (int i = 0;; ++i) {
            if (cnt[i % value]-- == 0) {
                return i;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findSmallestInteger(nums []int, value int) int {
	cnt := make([]int, value)
	for _, x := range nums {
		cnt[(x%value+value)%value]++
	}
	for i := 0; ; i++ {
		if cnt[i%value] == 0 {
			return i
		}
		cnt[i%value]--
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findSmallestInteger(nums: number[], value: number): number {
    const cnt: number[] = new Array(value).fill(0);
    for (const x of nums) {
        ++cnt[((x % value) + value) % value];
    }
    for (let i = 0; ; ++i) {
        if (cnt[i % value]-- === 0) {
            return i;
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

<p>给你一个下标从 <strong>0</strong> 开始的整数数组 <code>nums</code> 和一个整数 <code>value</code> 。</p>

<p>在一步操作中，你可以对 <code>nums</code> 中的任一元素加上或减去 <code>value</code> 。</p>

<ul>
	<li>例如，如果 <code>nums = [1,2,3]</code> 且 <code>value = 2</code> ，你可以选择 <code>nums[0]</code> 减去 <code>value</code> ，得到 <code>nums = [-1,2,3]</code> 。</li>
</ul>

<p>数组的 MEX (minimum excluded) 是指其中数组中缺失的最小非负整数。</p>

<ul>
	<li>例如，<code>[-1,2,3]</code> 的 MEX 是 <code>0</code> ，而 <code>[1,0,3]</code> 的 MEX 是 <code>2</code> 。</li>
</ul>

<p>返回在执行上述操作 <strong>任意次</strong> 后，<code>nums</code><em> </em>的最大 MEX <em>。</em></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,-10,7,13,6,8], value = 5
<strong>输出：</strong>4
<strong>解释：</strong>执行下述操作可以得到这一结果：
- nums[1] 加上 value 两次，nums = [1,<em><strong>0</strong></em>,7,13,6,8]
- nums[2] 减去 value 一次，nums = [1,0,<em><strong>2</strong></em>,13,6,8]
- nums[3] 减去 value 两次，nums = [1,0,2,<em><strong>3</strong></em>,6,8]
nums 的 MEX 是 4 。可以证明 4 是可以取到的最大 MEX 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,-10,7,13,6,8], value = 7
<strong>输出：</strong>2
<strong>解释：</strong>执行下述操作可以得到这一结果：
- nums[2] 减去 value 一次，nums = [1,-10,<em><strong>0</strong></em>,13,6,8]
nums 的 MEX 是 2 。可以证明 2 是可以取到的最大 MEX 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length, value &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们用哈希表或数组 $cnt$ 统计数组中每个数对 $value$ 取模后的余数的个数。

然后从 $0$ 开始遍历，对于当前遍历到的数 $i$，如果 $cnt[i \bmod value]$ 为 $0$，说明数组中不存在一个数对 $value$ 取模后的余数为 $i$，那么 $i$ 就是数组的 MEX，直接返回即可。否则，将 $cnt[i \bmod value]$ 减 $1$，继续遍历。

时间复杂度 $O(n)$，空间复杂度 $O(value)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        cnt = Counter(x % value for x in nums)
        for i in range(len(nums) + 1):
            if cnt[i % value] == 0:
                return i
            cnt[i % value] -= 1
```

#### Java

```java
class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int[] cnt = new int[value];
        for (int x : nums) {
            ++cnt[(x % value + value) % value];
        }
        for (int i = 0;; ++i) {
            if (cnt[i % value]-- == 0) {
                return i;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int cnt[value];
        memset(cnt, 0, sizeof(cnt));
        for (int x : nums) {
            ++cnt[(x % value + value) % value];
        }
        for (int i = 0;; ++i) {
            if (cnt[i % value]-- == 0) {
                return i;
            }
        }
    }
};
```

#### Go

```go
func findSmallestInteger(nums []int, value int) int {
	cnt := make([]int, value)
	for _, x := range nums {
		cnt[(x%value+value)%value]++
	}
	for i := 0; ; i++ {
		if cnt[i%value] == 0 {
			return i
		}
		cnt[i%value]--
	}
}
```

#### TypeScript

```ts
function findSmallestInteger(nums: number[], value: number): number {
    const cnt: number[] = new Array(value).fill(0);
    for (const x of nums) {
        ++cnt[((x % value) + value) % value];
    }
    for (let i = 0; ; ++i) {
        if (cnt[i % value]-- === 0) {
            return i;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2599. 使前缀和数组非负 🔒](https://leetcode.cn/problems/make-the-prefix-sum-non-negative){#2599}

{{< tabs "2599" >}}

{{% tab "python" %}}
```python
class Solution:
    def makePrefSumNonNegative(self, nums: List[int]) -> int:
        h = []
        ans = s = 0
        for x in nums:
            s += x
            if x < 0:
                heappush(h, x)
            while s < 0:
                s -= heappop(h)
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int makePrefSumNonNegative(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        long s = 0;
        for (int x : nums) {
            s += x;
            if (x < 0) {
                pq.offer(x);
            }
            while (s < 0) {
                s -= pq.poll();
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
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        long long s = 0;
        for (int& x : nums) {
            s += x;
            if (x < 0) {
                pq.push(x);
            }
            while (s < 0) {
                s -= pq.top();
                pq.pop();
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
func makePrefSumNonNegative(nums []int) (ans int) {
	pq := hp{}
	s := 0
	for _, x := range nums {
		s += x
		if x < 0 {
			heap.Push(&pq, x)
		}
		for s < 0 {
			s -= heap.Pop(&pq).(int)
			ans++
		}
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
{{% /tab %}}
{{% tab "ts" %}}
```ts
function makePrefSumNonNegative(nums: number[]): number {
    const pq = new MinPriorityQueue();
    let ans = 0;
    let s = 0;
    for (const x of nums) {
        s += x;
        if (x < 0) {
            pq.enqueue(x);
        }
        while (s < 0) {
            s -= pq.dequeue().element;
            ++ans;
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

<p>给定一个 <strong>下标从0开始</strong> 的整数数组 <code>nums</code> 。你可以任意多次执行以下操作：</p>

<ul>
	<li>从 <code>nums</code> 中选择任意一个元素，并将其放到 <code>nums</code> 的末尾。</li>
</ul>

<p><code>nums</code> 的前缀和数组是一个与 <code>nums</code> 长度相同的数组 <code>prefix</code> ，其中 <code>prefix[i]</code> 是所有整数 <code>nums[j]</code>（其中 <code>j</code> 在包括区间 <code>[0，i]</code> 内）的总和。</p>

<p>返回使前缀和数组不包含负整数的最小操作次数。测试用例的生成方式保证始终可以使前缀和数组非负。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1 ：</strong></p>

<pre>
<b>输入：</b>nums = [2,3,-5,4]
<b>输出：</b>0
<b>解释：</b>我们不需要执行任何操作。
给定数组为 [2, 3, -5, 4]，它的前缀和数组是 [2, 5, 0, 4]。
</pre>

<p><strong class="example">示例 2 ：</strong></p>

<pre>
<b>输入：</b>nums = [3,-5,-2,6]
<b>输出：</b>1
<b>解释：</b>我们可以对索引为1的元素执行一次操作。
操作后的数组为 [3, -2, 6, -5]，它的前缀和数组是 [3, 1, 7, 2]。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心 + 优先队列（小根堆）

我们用变量 $s$ 记录当前数组的前缀和。

遍历数组 $nums$，将当前元素 $x$ 加入前缀和 $s$ 中，如果 $x$ 为负数，则将 $x$ 加入小根堆中。如果此时 $s$ 为负数，我们贪心地取出最小的负数，将其从 $s$ 中减去，同时将答案加一。最终返回答案即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def makePrefSumNonNegative(self, nums: List[int]) -> int:
        h = []
        ans = s = 0
        for x in nums:
            s += x
            if x < 0:
                heappush(h, x)
            while s < 0:
                s -= heappop(h)
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int makePrefSumNonNegative(int[] nums) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        long s = 0;
        for (int x : nums) {
            s += x;
            if (x < 0) {
                pq.offer(x);
            }
            while (s < 0) {
                s -= pq.poll();
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
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        long long s = 0;
        for (int& x : nums) {
            s += x;
            if (x < 0) {
                pq.push(x);
            }
            while (s < 0) {
                s -= pq.top();
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func makePrefSumNonNegative(nums []int) (ans int) {
	pq := hp{}
	s := 0
	for _, x := range nums {
		s += x
		if x < 0 {
			heap.Push(&pq, x)
		}
		for s < 0 {
			s -= heap.Pop(&pq).(int)
			ans++
		}
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

#### TypeScript

```ts
function makePrefSumNonNegative(nums: number[]): number {
    const pq = new MinPriorityQueue();
    let ans = 0;
    let s = 0;
    for (const x of nums) {
        s += x;
        if (x < 0) {
            pq.enqueue(x);
        }
        while (s < 0) {
            s -= pq.dequeue().element;
            ++ans;
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
