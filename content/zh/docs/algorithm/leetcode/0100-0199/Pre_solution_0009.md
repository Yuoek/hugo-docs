---
title: "0180_连续出现的数字"
date: 2025-10-08T18:45:43+08:00
weight: 9
tags: [位运算, 动态规划, 双指针, 哈希函数, 哈希表, 字符串, 数学, 数据库, 数组, 滑动窗口, 滚动哈希]
---

{{< markmap >}}
### [0180_连续出现的数字](#180)
#### [数据库](#180)
### [0181_超过经理收入的员工](#181)
#### [数据库](#181)
### [0182_查找重复的电子邮箱](#182)
#### [数据库](#182)
### [0183_从不订购的客户](#183)
#### [数据库](#183)
### [0184_部门工资最高的员工](#184)
#### [数据库](#184)
### [0185_部门工资前三高的所有员工](#185)
#### [数据库](#185)
### [0186_反转字符串中的单词 II 🔒](#186)
#### [双指针](#186)
#### [字符串](#186)
### [0187_重复的DNA序列](#187)
#### [位运算](#187)
#### [哈希表](#187)
#### [字符串](#187)
#### [滑动窗口](#187)
#### [哈希函数](#187)
#### [滚动哈希](#187)
### [0188_买卖股票的最佳时机 IV](#188)
#### [数组](#188)
#### [动态规划](#188)
### [0189_轮转数组](#189)
#### [数组](#189)
#### [数学](#189)
#### [双指针](#189)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0180_连续出现的数字
___
#### 数据库
---
### 0181_超过经理收入的员工
___
#### 数据库
---
### 0182_查找重复的电子邮箱
___
#### 数据库
---
### 0183_从不订购的客户
___
#### 数据库
---
### 0184_部门工资最高的员工
___
#### 数据库
---
### 0185_部门工资前三高的所有员工
___
#### 数据库
---
### 0186_反转字符串中的单词 II 🔒
___
#### 双指针
___
#### 字符串
---
### 0187_重复的DNA序列
___
#### 位运算
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
___
#### 哈希函数
___
#### 滚动哈希
---
### 0188_买卖股票的最佳时机 IV
___
#### 数组
___
#### 动态规划
---
### 0189_轮转数组
___
#### 数组
___
#### 数学
___
#### 双指针
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 双指针 |
| 哈希函数 | 哈希表 | 字符串 |
| 数学 | 数据库 | 数组 |
| 滑动窗口 | 滚动哈希 |  |

# [180. 连续出现的数字](https://leetcode.cn/problems/consecutive-numbers){#180}

{{< tabs "180" >}}

{{% tab "python" %}}
```python
import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    all_the_same = lambda lst: lst.nunique() == 1
    logs["is_consecutive"] = (
        logs["num"].rolling(window=3, center=True, min_periods=3).apply(all_the_same)
    )
    return (
        logs.query("is_consecutive == 1.0")[["num"]]
        .drop_duplicates()
        .rename(columns={"num": "ConsecutiveNums"})
    )
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            IF(num = (LAG(num) OVER ()), 0, 1) AS st
        FROM Logs
    ),
    S AS (
        SELECT *, SUM(st) OVER (ORDER BY id) AS p
        FROM T
    )
SELECT DISTINCT num AS ConsecutiveNums
FROM S
GROUP BY p
HAVING COUNT(1) >= 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Logs</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
在 SQL 中，id 是该表的主键。
id 是一个自增列。</pre>

<p>&nbsp;</p>

<p>找出所有至少连续出现三次的数字。</p>

<p>返回的结果表中的数据可以按 <strong>任意顺序</strong> 排列。</p>

<p>结果格式如下面的例子所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Logs 表：
+----+-----+
| id | num |
+----+-----+
| 1  | 1   |
| 2  | 1   |
| 3  | 1   |
| 4  | 2   |
| 5  | 1   |
| 6  | 2   |
| 7  | 2   |
+----+-----+
<strong>输出：</strong>
Result 表：
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
<strong>解释：</strong>1 是唯一连续出现至少三次的数字。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：两次连接

我们可以使用两次连接来解决这个问题。

我们首先进行一次自连接，连接条件是 `l1.num = l2.num` 并且 `l1.id = l2.id - 1`，这样我们就可以找出所有至少连续出现两次的数字。然后，我们再进行一次自连接，连接条件是 `l2.num = l3.num` 并且 `l2.id = l3.id - 1`，这样我们就可以找出所有至少连续出现三次的数字。最后，我们只需要筛选出去重的 `l2.num` 即可。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    all_the_same = lambda lst: lst.nunique() == 1
    logs["is_consecutive"] = (
        logs["num"].rolling(window=3, center=True, min_periods=3).apply(all_the_same)
    )
    return (
        logs.query("is_consecutive == 1.0")[["num"]]
        .drop_duplicates()
        .rename(columns={"num": "ConsecutiveNums"})
    )
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT DISTINCT l2.num AS ConsecutiveNums
FROM
    Logs AS l1
    JOIN Logs AS l2 ON l1.id = l2.id - 1 AND l1.num = l2.num
    JOIN Logs AS l3 ON l2.id = l3.id - 1 AND l2.num = l3.num;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：窗口函数

我们可以使用窗口函数 `LAG` 和 `LEAD` 来获取上一行的 `num` 和下一行的 `num`，记录在字段 $a$ 和 $b$ 中。最后，我们只需要筛选出 $a =num$ 并且 $b = num$ 的行，这些行就是至少连续出现三次的数字。注意，我们需要使用 `DISTINCT` 关键字来对结果去重。

我们也可以对数字进行分组，具体做法是使用 `IF` 函数来判断当前行与前一行的 `num` 是否相等，如果相等则记为 $0$，否则记为 $1$，然后使用窗口函数 `SUM` 来计算前缀和，这样计算出的前缀和就是分组的标识。最后，我们只需要按照分组标识进行分组，然后筛选出每组中的行数大于等于 $3$ 的数字即可。同样，我们需要使用 `DISTINCT` 关键字来对结果去重。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            LAG(num) OVER () AS a,
            LEAD(num) OVER () AS b
        FROM Logs
    )
SELECT DISTINCT num AS ConsecutiveNums
FROM T
WHERE a = num AND b = num;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            IF(num = (LAG(num) OVER ()), 0, 1) AS st
        FROM Logs
    ),
    S AS (
        SELECT *, SUM(st) OVER (ORDER BY id) AS p
        FROM T
    )
SELECT DISTINCT num AS ConsecutiveNums
FROM S
GROUP BY p
HAVING COUNT(1) >= 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [181. 超过经理收入的员工](https://leetcode.cn/problems/employees-earning-more-than-their-managers){#181}

{{< tabs "181" >}}

{{% tab "python" %}}
```python
import pandas as pd


def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    merged = employee.merge(
        employee, left_on="managerId", right_on="id", suffixes=("", "_manager")
    )
    result = merged[merged["salary"] > merged["salary_manager"]][["name"]]
    result.columns = ["Employee"]
    return result
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT e1.name Employee
FROM
    Employee e1
    JOIN Employee e2 ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Employee</code>&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id 是该表的主键（具有唯一值的列）。
该表的每一行都表示雇员的ID、姓名、工资和经理的ID。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出收入比经理高的员工。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | Null      |
| 4  | Max   | 90000  | Null      |
+----+-------+--------+-----------+
<strong>输出:</strong> 
+----------+
| Employee |
+----------+
| Joe      |
+----------+
<strong>解释:</strong> Joe 是唯一挣得比经理多的雇员。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自连接 + 条件筛选

我们可以通过自连接 `Employee` 表，找出员工的工资以及其经理的工资，然后筛选出工资比经理高的员工。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def find_employees(employee: pd.DataFrame) -> pd.DataFrame:
    merged = employee.merge(
        employee, left_on="managerId", right_on="id", suffixes=("", "_manager")
    )
    result = merged[merged["salary"] > merged["salary_manager"]][["name"]]
    result.columns = ["Employee"]
    return result
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT e1.name Employee
FROM
    Employee e1
    JOIN Employee e2 ON e1.managerId = e2.id
WHERE e1.salary > e2.salary;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [182. 查找重复的电子邮箱](https://leetcode.cn/problems/duplicate-emails){#182}

{{< tabs "182" >}}

{{% tab "python" %}}
```python
import pandas as pd


def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    results = pd.DataFrame()

    results = person.loc[person.duplicated(subset=["email"]), ["email"]]

    return results.drop_duplicates()
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
SELECT DISTINCT p1.email
FROM
    person AS p1,
    person AS p2
WHERE p1.id != p2.id AND p1.email = p2.email;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><meta charset="UTF-8" /></p>

<p>表:&nbsp;<code>Person</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id 是该表的主键（具有唯一值的列）。
此表的每一行都包含一封电子邮件。电子邮件不包含大写字母。
</pre>

<p>&nbsp;</p>

<p>编写解决方案来报告所有重复的电子邮件。 请注意，可以保证电子邮件字段不为 NULL。</p>

<p>以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>结果格式如下例。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1:</strong></p>

<pre>
<strong>输入:</strong> 
Person 表:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
<strong>输出:</strong> 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
<strong>解释:</strong> a@b.com 出现了两次。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组统计

我们可以使用 `GROUP BY` 语句，按照 `email` 字段进行分组，然后使用 `HAVING` 语句，筛选出现次数大于 $1$ 的 `email`。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    results = pd.DataFrame()

    results = person.loc[person.duplicated(subset=["email"]), ["email"]]

    return results.drop_duplicates()
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT email
FROM Person
GROUP BY 1
HAVING COUNT(1) > 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：自连接

我们可以使用自连接的方法，将 `Person` 表自身连接一次，然后筛选出 `id` 不同，但 `email` 相同的记录。

<!-- tabs:start -->

#### MySQL

```sql
SELECT DISTINCT p1.email
FROM
    person AS p1,
    person AS p2
WHERE p1.id != p2.id AND p1.email = p2.email;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [183. 从不订购的客户](https://leetcode.cn/problems/customers-who-never-order){#183}

{{< tabs "183" >}}

{{% tab "python" %}}
```python
import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Select the customers whose 'id' is not present in the orders DataFrame's 'customerId' column.
    df = customers[~customers["id"].isin(orders["customerId"])]

    # Build a DataFrame that only contains the 'name' column and rename it as 'Customers'.
    df = df[["name"]].rename(columns={"name": "Customers"})

    return df
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name AS Customers
FROM
    Customers AS c
    LEFT JOIN Orders AS o ON c.id = o.customerId
WHERE o.id IS NULL;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>Customers</code> 表：</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
在 SQL 中，id 是该表的主键。
该表的每一行都表示客户的 ID 和名称。</pre>

<p><code>Orders</code> 表：</p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
在 SQL 中，id 是该表的主键。
customerId 是 Customers 表中 ID 的外键( Pandas 中的连接键)。
该表的每一行都表示订单的 ID 和订购该订单的客户的 ID。</pre>

<p>&nbsp;</p>

<p>找出所有从不点任何东西的顾客。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
<b>输出：</b>
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：NOT IN

列举所有已存在订单的客户 ID，使用 `NOT IN` 找到不存在其中的客户。

<!-- tabs:start -->

#### Python3

```python
import pandas as pd


def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    # Select the customers whose 'id' is not present in the orders DataFrame's 'customerId' column.
    df = customers[~customers["id"].isin(orders["customerId"])]

    # Build a DataFrame that only contains the 'name' column and rename it as 'Customers'.
    df = df[["name"]].rename(columns={"name": "Customers"})

    return df
```

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
WHERE
    id NOT IN (
        SELECT customerId
        FROM Orders
    );
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：LEFT JOIN

使用 `LEFT JOIN` 连接表格，返回 `CustomerId` 为 `NULL` 的数据。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT name AS Customers
FROM
    Customers AS c
    LEFT JOIN Orders AS o ON c.id = o.customerId
WHERE o.id IS NULL;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [184. 部门工资最高的员工](https://leetcode.cn/problems/department-highest-salary){#184}

{{< tabs "184" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            d.name AS department,
            e.name AS employee,
            salary,
            RANK() OVER (
                PARTITION BY d.name
                ORDER BY salary DESC
            ) AS rk
        FROM
            Employee AS e
            JOIN Department AS d ON e.departmentId = d.id
    )
SELECT department, employee, salary
FROM T
WHERE rk = 1;
```
{{% /tab %}}
{{% tab "python" %}}
```python
import pandas as pd


def department_highest_salary(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    # Merge the two tables on departmentId and department id
    merged = employee.merge(department, left_on='departmentId', right_on='id')

    # Find the maximum salary for each department
    max_salaries = merged.groupby('departmentId')['salary'].transform('max')

    # Filter employees who have the highest salary in their department
    top_earners = merged[merged['salary'] == max_salaries]

    # Select required columns and rename them
    result = top_earners[['name_y', 'name_x', 'salary']].copy()
    result.columns = ['Department', 'Employee', 'Salary']

    return result
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Employee</code></p>

<pre>
+--------------+---------+
| 列名          | 类型    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
在 SQL 中，id是此表的主键。
departmentId 是 Department 表中 id 的外键（在 Pandas 中称为 join key）。
此表的每一行都表示员工的 id、姓名和工资。它还包含他们所在部门的 id。
</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Department</code></p>

<pre>
+-------------+---------+
| 列名         | 类型    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
在 SQL 中，id 是此表的主键列。
此表的每一行都表示一个部门的 id 及其名称。
</pre>

<p>&nbsp;</p>

<p>查找出每个部门中薪资最高的员工。<br />
按 <strong>任意顺序</strong> 返回结果表。<br />
查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<b>输入：</b>
Employee 表:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
Department 表:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
<b>输出：</b>
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
| IT         | Max      | 90000  |
+------------+----------+--------+
<strong>解释：</strong>Max 和 Jim 在 IT 部门的工资都是最高的，Henry 在销售部的工资最高。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：等值连接 + 子查询

我们可以使用等值连接，将 `Employee` 表和 `Department` 表连接起来，连接条件为 `Employee.departmentId = Department.id`，然后使用子查询来找到每个部门的最高工资，最后使用 `WHERE` 子句来筛选出每个部门中薪资最高的员工。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT d.name AS department, e.name AS employee, salary
FROM
    Employee AS e
    JOIN Department AS d ON e.departmentId = d.id
WHERE
    (d.id, salary) IN (
        SELECT departmentId, MAX(salary)
        FROM Employee
        GROUP BY 1
    );
```

### Pandas

```python
import pandas as pd


def department_highest_salary(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    # Merge the two tables on departmentId and department id
    merged = employee.merge(department, left_on='departmentId', right_on='id')

    # Find the maximum salary for each department
    max_salaries = merged.groupby('departmentId')['salary'].transform('max')

    # Filter employees who have the highest salary in their department
    top_earners = merged[merged['salary'] == max_salaries]

    # Select required columns and rename them
    result = top_earners[['name_y', 'name_x', 'salary']].copy()
    result.columns = ['Department', 'Employee', 'Salary']

    return result
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：等值连接 + 窗口函数

我们可以使用等值连接，将 `Employee` 表和 `Department` 表连接起来，连接条件为 `Employee.departmentId = Department.id`，然后使用窗口函数 `rank()`，它可以为每个部门的每个员工分配一个排名，然后我们可以选择排名为 $1$ 的行即可。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            d.name AS department,
            e.name AS employee,
            salary,
            RANK() OVER (
                PARTITION BY d.name
                ORDER BY salary DESC
            ) AS rk
        FROM
            Employee AS e
            JOIN Department AS d ON e.departmentId = d.id
    )
SELECT department, employee, salary
FROM T
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [185. 部门工资前三高的所有员工](https://leetcode.cn/problems/department-top-three-salaries){#185}

{{< tabs "185" >}}

{{% tab "python" %}}
```python
import pandas as pd


def top_three_salaries(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    salary_cutoff = (
        employee.drop_duplicates(["salary", "departmentId"])
        .groupby("departmentId")["salary"]
        .nlargest(3)
        .groupby("departmentId")
        .min()
    )
    employee["Department"] = department.set_index("id")["name"][
        employee["departmentId"]
    ].values
    employee["cutoff"] = salary_cutoff[employee["departmentId"]].values
    return employee[employee["salary"] >= employee["cutoff"]].rename(
        columns={"name": "Employee", "salary": "Salary"}
    )[["Department", "Employee", "Salary"]]
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            DENSE_RANK() OVER (
                PARTITION BY departmentId
                ORDER BY salary DESC
            ) AS rk
        FROM Employee
    )
SELECT d.name AS Department, t.name AS Employee, salary AS Salary
FROM
    T AS t
    JOIN Department AS d ON t.departmentId = d.id
WHERE rk <= 3;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Employee</code></p>

<pre>
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+
id 是该表的主键列(具有唯一值的列)。
departmentId 是 Department 表中 ID 的外键（reference 列）。
该表的每一行都表示员工的ID、姓名和工资。它还包含了他们部门的ID。
</pre>

<p>&nbsp;</p>

<p>表:&nbsp;<code>Department</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id 是该表的主键列(具有唯一值的列)。
该表的每一行表示部门ID和部门名。
</pre>

<p>&nbsp;</p>

<p>公司的主管们感兴趣的是公司每个部门中谁赚的钱最多。一个部门的 <strong>高收入者</strong> 是指一个员工的工资在该部门的 <strong>不同</strong> 工资中 <strong>排名前三</strong> 。</p>

<p>编写解决方案，找出每个部门中 <strong>收入高的员工</strong> 。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+----+-------+--------+--------------+
| id | name  | salary | departmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 85000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
| 5  | Janet | 69000  | 1            |
| 6  | Randy | 85000  | 1            |
| 7  | Will  | 70000  | 1            |
+----+-------+--------+--------------+
Department  表:
+----+-------+
| id | name  |
+----+-------+
| 1  | IT    |
| 2  | Sales |
+----+-------+
<strong>输出:</strong> 
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Joe      | 85000  |
| IT         | Randy    | 85000  |
| IT         | Will     | 70000  |
| Sales      | Henry    | 80000  |
| Sales      | Sam      | 60000  |
+------------+----------+--------+
<strong>解释:
</strong>在IT部门:
- Max的工资最高
- 兰迪和乔都赚取第二高的独特的薪水
- 威尔的薪水是第三高的

在销售部:
- 亨利的工资最高
- 山姆的薪水第二高
- 没有第三高的工资，因为只有两名员工</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>没有姓名、薪资和部门 <strong>完全</strong> 相同的员工。</li>
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
import pandas as pd


def top_three_salaries(
    employee: pd.DataFrame, department: pd.DataFrame
) -> pd.DataFrame:
    salary_cutoff = (
        employee.drop_duplicates(["salary", "departmentId"])
        .groupby("departmentId")["salary"]
        .nlargest(3)
        .groupby("departmentId")
        .min()
    )
    employee["Department"] = department.set_index("id")["name"][
        employee["departmentId"]
    ].values
    employee["cutoff"] = salary_cutoff[employee["departmentId"]].values
    return employee[employee["salary"] >= employee["cutoff"]].rename(
        columns={"name": "Employee", "salary": "Salary"}
    )[["Department", "Employee", "Salary"]]
```

#### MySQL

```sql
SELECT
    Department.NAME AS Department,
    Employee.NAME AS Employee,
    Salary
FROM
    Employee,
    Department
WHERE
    Employee.DepartmentId = Department.Id
    AND (
        SELECT
            COUNT(DISTINCT e2.Salary)
        FROM Employee AS e2
        WHERE e2.Salary > Employee.Salary AND Employee.DepartmentId = e2.DepartmentId
    ) < 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            DENSE_RANK() OVER (
                PARTITION BY departmentId
                ORDER BY salary DESC
            ) AS rk
        FROM Employee
    )
SELECT d.name AS Department, t.name AS Employee, salary AS Salary
FROM
    T AS t
    JOIN Department AS d ON t.departmentId = d.id
WHERE rk <= 3;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [186. 反转字符串中的单词 II 🔒](https://leetcode.cn/problems/reverse-words-in-a-string-ii){#186}

{{< tabs "186" >}}

{{% tab "python" %}}
```python
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1

        i, n = 0, len(s)
        for j, c in enumerate(s):
            if c == " ":
                reverse(i, j - 1)
                i = j + 1
            elif j == n - 1:
                reverse(i, j)
        reverse(0, n - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void reverseWords(char[] s) {
        int n = s.length;
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(s, i, j);
            }
        }
        reverse(s, 0, n - 1);
    }

    private void reverse(char[] s, int i, int j) {
        for (; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {
        auto reverse = [&](int i, int j) {
            for (; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
        };
        int n = s.size();
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(i, j);
            }
        }
        reverse(0, n - 1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reverseWords(s []byte) {
	reverse := func(i, j int) {
		for ; i < j; i, j = i+1, j-1 {
			s[i], s[j] = s[j], s[i]
		}
	}
	i, n := 0, len(s)
	for j, c := range s {
		if c == ' ' {
			reverse(i, j-1)
			i = j + 1
		} else if j == n-1 {
			reverse(i, j)
		}
	}
	reverse(0, n-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 Do not return anything, modify s in-place instead.
 */
function reverseWords(s: string[]): void {
    const n = s.length;
    const reverse = (i: number, j: number): void => {
        for (; i < j; ++i, --j) {
            [s[i], s[j]] = [s[j], s[i]];
        }
    };
    for (let i = 0, j = 0; j <= n; ++j) {
        if (s[j] === ' ') {
            reverse(i, j - 1);
            i = j + 1;
        } else if (j === n - 1) {
            reverse(i, j);
        }
    }
    reverse(0, n - 1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符数组 <code>s</code> ，反转其中 <strong>单词</strong> 的顺序。</p>

<p><strong>单词</strong> 的定义为：单词是一个由非空格字符组成的序列。<code>s</code> 中的单词将会由单个空格分隔。</p>

<div class="original__bRMd">
<div>
<p>必须设计并实现 <strong>原地</strong> 解法来解决此问题，即不分配额外的空间。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
<strong>输出：</strong>["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = ["a"]
<strong>输出：</strong>["a"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> 可以是一个英文字母（大写或小写）、数字、或是空格 <code>' '</code> 。</li>
	<li><code>s</code> 中至少存在一个单词</li>
	<li><code>s</code> 不含前导或尾随空格</li>
	<li>题目数据保证：<code>s</code> 中的每个单词都由单个空格分隔</li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以遍历字符数组 $s$，利用双指针 $i$ 和 $j$ 找到每个单词的起始位置和结束位置，然后反转每个单词，最后再反转整个字符数组。

时间复杂度 $O(n)$，其中 $n$ 为字符数组 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reverseWords(self, s: List[str]) -> None:
        def reverse(i: int, j: int):
            while i < j:
                s[i], s[j] = s[j], s[i]
                i, j = i + 1, j - 1

        i, n = 0, len(s)
        for j, c in enumerate(s):
            if c == " ":
                reverse(i, j - 1)
                i = j + 1
            elif j == n - 1:
                reverse(i, j)
        reverse(0, n - 1)
```

#### Java

```java
class Solution {
    public void reverseWords(char[] s) {
        int n = s.length;
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(s, i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(s, i, j);
            }
        }
        reverse(s, 0, n - 1);
    }

    private void reverse(char[] s, int i, int j) {
        for (; i < j; ++i, --j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {
        auto reverse = [&](int i, int j) {
            for (; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
        };
        int n = s.size();
        for (int i = 0, j = 0; j < n; ++j) {
            if (s[j] == ' ') {
                reverse(i, j - 1);
                i = j + 1;
            } else if (j == n - 1) {
                reverse(i, j);
            }
        }
        reverse(0, n - 1);
    }
};
```

#### Go

```go
func reverseWords(s []byte) {
	reverse := func(i, j int) {
		for ; i < j; i, j = i+1, j-1 {
			s[i], s[j] = s[j], s[i]
		}
	}
	i, n := 0, len(s)
	for j, c := range s {
		if c == ' ' {
			reverse(i, j-1)
			i = j + 1
		} else if j == n-1 {
			reverse(i, j)
		}
	}
	reverse(0, n-1)
}
```

#### TypeScript

```ts
/**
 Do not return anything, modify s in-place instead.
 */
function reverseWords(s: string[]): void {
    const n = s.length;
    const reverse = (i: number, j: number): void => {
        for (; i < j; ++i, --j) {
            [s[i], s[j]] = [s[j], s[i]];
        }
    };
    for (let i = 0, j = 0; j <= n; ++j) {
        if (s[j] === ' ') {
            reverse(i, j - 1);
            i = j + 1;
        } else if (j === n - 1) {
            reverse(i, j);
        }
    }
    reverse(0, n - 1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [187. 重复的DNA序列](https://leetcode.cn/problems/repeated-dna-sequences){#187}

{{< tabs "187" >}}

{{% tab "python" %}}
```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        cnt = Counter()
        ans = []
        for i in range(len(s) - 10 + 1):
            t = s[i : i + 10]
            cnt[t] += 1
            if cnt[t] == 2:
                ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> cnt = new HashMap<>();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length() - 10 + 1; ++i) {
            String t = s.substring(i, i + 10);
            if (cnt.merge(t, 1, Integer::sum) == 2) {
                ans.add(t);
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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for (int i = 0, n = s.size() - 10 + 1; i < n; ++i) {
            auto t = s.substr(i, 10);
            if (++cnt[t] == 2) {
                ans.emplace_back(t);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findRepeatedDnaSequences(s string) []string {
	hashCode := map[byte]int{'A': 0, 'C': 1, 'G': 2, 'T': 3}
	ans, cnt, left, right := []string{}, map[int]int{}, 0, 0

	sha, multi := 0, int(math.Pow(4, 9))
	for ; right < len(s); right++ {
		sha = sha*4 + hashCode[s[right]]
		if right-left+1 < 10 {
			continue
		}
		cnt[sha]++
		if cnt[sha] == 2 {
			ans = append(ans, s[left:right+1])
		}
		sha, left = sha-multi*hashCode[s[left]], left+1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findRepeatedDnaSequences(s: string): string[] {
    const n = s.length;
    const cnt: Map<string, number> = new Map();
    const ans: string[] = [];
    for (let i = 0; i <= n - 10; ++i) {
        const t = s.slice(i, i + 10);
        cnt.set(t, (cnt.get(t) ?? 0) + 1);
        if (cnt.get(t) === 2) {
            ans.push(t);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
        if s.len() < 10 {
            return vec![];
        }
        let mut cnt = HashMap::new();
        let mut ans = Vec::new();
        for i in 0..s.len() - 9 {
            let t = &s[i..i + 10];
            let count = cnt.entry(t).or_insert(0);
            *count += 1;
            if *count == 2 {
                ans.push(t.to_string());
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
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function (s) {
    const cnt = new Map();
    const ans = [];
    for (let i = 0; i < s.length - 10 + 1; ++i) {
        const t = s.slice(i, i + 10);
        cnt.set(t, (cnt.get(t) || 0) + 1);
        if (cnt.get(t) === 2) {
            ans.push(t);
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        var cnt = new Dictionary<string, int>();
        var ans = new List<string>();
        for (int i = 0; i < s.Length - 10 + 1; ++i) {
            var t = s.Substring(i, 10);
            if (!cnt.ContainsKey(t)) {
                cnt[t] = 0;
            }
            if (++cnt[t] == 2) {
                ans.Add(t);
            }
        }
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

<p><strong>DNA序列</strong>&nbsp;由一系列核苷酸组成，缩写为<meta charset="UTF-8" />&nbsp;<code>'A'</code>,&nbsp;<code>'C'</code>,&nbsp;<code>'G'</code>&nbsp;和<meta charset="UTF-8" />&nbsp;<code>'T'</code>.。</p>

<ul>
	<li>例如，<meta charset="UTF-8" /><code>"ACGAATTCCG"</code>&nbsp;是一个 <strong>DNA序列</strong> 。</li>
</ul>

<p>在研究 <strong>DNA</strong> 时，识别 DNA 中的重复序列非常有用。</p>

<p>给定一个表示 <strong>DNA序列</strong> 的字符串 <code>s</code> ，返回所有在 DNA 分子中出现不止一次的&nbsp;<strong>长度为&nbsp;<code>10</code></strong>&nbsp;的序列(子字符串)。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
<strong>输出：</strong>["AAAAACCCCC","CCCCCAAAAA"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AAAAAAAAAAAAA"
<strong>输出：</strong>["AAAAAAAAAA"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code><code>==</code><code>'A'</code>、<code>'C'</code>、<code>'G'</code>&nbsp;or&nbsp;<code>'T'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们定义一个哈希表 $cnt$，用于存储所有长度为 $10$ 的子字符串出现的次数。

遍历字符串 $s$ 的所有长度为 $10$ 的子字符串，对于当前子字符串 $t$，我们更新其在哈希表中对应的计数。如果 $t$ 的计数为 $2$，我们就将它加入答案。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n \times 10)$，空间复杂度 $O(n \times 10)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        cnt = Counter()
        ans = []
        for i in range(len(s) - 10 + 1):
            t = s[i : i + 10]
            cnt[t] += 1
            if cnt[t] == 2:
                ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> cnt = new HashMap<>();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < s.length() - 10 + 1; ++i) {
            String t = s.substring(i, i + 10);
            if (cnt.merge(t, 1, Integer::sum) == 2) {
                ans.add(t);
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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for (int i = 0, n = s.size() - 10 + 1; i < n; ++i) {
            auto t = s.substr(i, 10);
            if (++cnt[t] == 2) {
                ans.emplace_back(t);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findRepeatedDnaSequences(s string) (ans []string) {
	cnt := map[string]int{}
	for i := 0; i < len(s)-10+1; i++ {
		t := s[i : i+10]
		cnt[t]++
		if cnt[t] == 2 {
			ans = append(ans, t)
		}
	}
	return
}
```

#### TypeScript

```ts
function findRepeatedDnaSequences(s: string): string[] {
    const n = s.length;
    const cnt: Map<string, number> = new Map();
    const ans: string[] = [];
    for (let i = 0; i <= n - 10; ++i) {
        const t = s.slice(i, i + 10);
        cnt.set(t, (cnt.get(t) ?? 0) + 1);
        if (cnt.get(t) === 2) {
            ans.push(t);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String> {
        if s.len() < 10 {
            return vec![];
        }
        let mut cnt = HashMap::new();
        let mut ans = Vec::new();
        for i in 0..s.len() - 9 {
            let t = &s[i..i + 10];
            let count = cnt.entry(t).or_insert(0);
            *count += 1;
            if *count == 2 {
                ans.push(t.to_string());
            }
        }
        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function (s) {
    const cnt = new Map();
    const ans = [];
    for (let i = 0; i < s.length - 10 + 1; ++i) {
        const t = s.slice(i, i + 10);
        cnt.set(t, (cnt.get(t) || 0) + 1);
        if (cnt.get(t) === 2) {
            ans.push(t);
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        var cnt = new Dictionary<string, int>();
        var ans = new List<string>();
        for (int i = 0; i < s.Length - 10 + 1; ++i) {
            var t = s.Substring(i, 10);
            if (!cnt.ContainsKey(t)) {
                cnt[t] = 0;
            }
            if (++cnt[t] == 2) {
                ans.Add(t);
            }
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：Rabin-Karp 字符串匹配算法

本质上是滑动窗口和哈希的结合方法，和 [0028.找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/) 类似，本题可以借助哈希函数将子序列计数的时间复杂度降低到 $O(1)$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Go

```go
func findRepeatedDnaSequences(s string) []string {
	hashCode := map[byte]int{'A': 0, 'C': 1, 'G': 2, 'T': 3}
	ans, cnt, left, right := []string{}, map[int]int{}, 0, 0

	sha, multi := 0, int(math.Pow(4, 9))
	for ; right < len(s); right++ {
		sha = sha*4 + hashCode[s[right]]
		if right-left+1 < 10 {
			continue
		}
		cnt[sha]++
		if cnt[sha] == 2 {
			ans = append(ans, s[left:right+1])
		}
		sha, left = sha-multi*hashCode[s[left]], left+1
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [188. 买卖股票的最佳时机 IV](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv){#188}

{{< tabs "188" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        f = [[0] * 2 for _ in range(k + 1)]
        for j in range(1, k + 1):
            f[j][1] = -prices[0]
        for x in prices[1:]:
            for j in range(k, 0, -1):
                f[j][0] = max(f[j][1] + x, f[j][0])
                f[j][1] = max(f[j - 1][0] - x, f[j][1])
        return f[k][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][] f = new int[k + 1][2];
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j][0] = Math.max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = Math.max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[k + 1][2];
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j; --j) {
                f[j][0] = max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProfit(k int, prices []int) int {
	f := make([][2]int, k+1)
	for j := 1; j <= k; j++ {
		f[j][1] = -prices[0]
	}
	for _, x := range prices[1:] {
		for j := k; j > 0; j-- {
			f[j][0] = max(f[j][1]+x, f[j][0])
			f[j][1] = max(f[j-1][0]-x, f[j][1])
		}
	}
	return f[k][0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxProfit(k: number, prices: number[]): number {
    const f = Array.from({ length: k + 1 }, () => Array.from({ length: 2 }, () => 0));
    for (let j = 1; j <= k; ++j) {
        f[j][1] = -prices[0];
    }
    for (const x of prices.slice(1)) {
        for (let j = k; j; --j) {
            f[j][0] = Math.max(f[j][1] + x, f[j][0]);
            f[j][1] = Math.max(f[j - 1][0] - x, f[j][1]);
        }
    }
    return f[k][0];
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxProfit(int k, int[] prices) {
        int n = prices.Length;
        int[,] f = new int[k + 1, 2];
        for (int j = 1; j <= k; ++j) {
            f[j, 1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j, 0] = Math.Max(f[j, 1] + prices[i], f[j, 0]);
                f[j, 1] = Math.Max(f[j - 1, 0] - prices[i], f[j, 1]);
            }
        }
        return f[k, 0];
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组&nbsp;<code>prices</code> 和一个整数 <code>k</code> ，其中 <code>prices[i]</code> 是某支给定的股票在第 <code>i</code><em> </em>天的价格。</p>

<p>设计一个算法来计算你所能获取的最大利润。你最多可以完成 <code>k</code> 笔交易。也就是说，你最多可以买 <code>k</code> 次，卖 <code>k</code> 次。</p>

<p><strong>注意：</strong>你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>k = 2, prices = [2,4,1]
<strong>输出：</strong>2
<strong>解释：</strong>在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>k = 2, prices = [3,2,6,5,0,3]
<strong>输出：</strong>7
<strong>解释：</strong>在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>1 &lt;= prices.length &lt;= 1000</code></li>
	<li><code>0 &lt;= prices[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j, k)$，表示从第 $i$ 天开始，最多完成 $j$ 笔交易，以及当前持有股票的状态为 $k$（不持有股票用 $0$ 表示，持有股票用 $1$ 表示）时，所能获得的最大利润。答案即为 $dfs(0, k, 0)$。

函数 $dfs(i, j, k)$ 的执行逻辑如下：

-   如果 $i$ 大于等于 $n$，直接返回 $0$；
-   第 $i$ 天可以不进行任何操作，那么 $dfs(i, j, k) = dfs(i + 1, j, k)$；
-   如果 $k \gt 0$，那么第 $i$ 天可以选择卖出股票，那么 $dfs(i, j, k) = \max(dfs(i + 1, j - 1, 0) + prices[i], dfs(i + 1, j, k))$；
-   否则，如果 $j \gt 0$，那么第 $i$ 天可以选择买入股票，那么 $dfs(i, j, k) = \max(dfs(i + 1, j - 1, 1) - prices[i], dfs(i + 1, j, k))$。

取上述三种情况的最大值即为 $dfs(i, j, k)$ 的值。

过程中，我们可以使用记忆化搜索的方法，将每次计算的结果保存下来，避免重复计算。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别为数组 $prices$ 的长度和 $k$ 的值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        @cache
        def dfs(i: int, j: int, k: int) -> int:
            if i >= len(prices):
                return 0
            ans = dfs(i + 1, j, k)
            if k:
                ans = max(ans, prices[i] + dfs(i + 1, j, 0))
            elif j:
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1))
            return ans

        return dfs(0, k, 0)
```

#### Java

```java
class Solution {
    private Integer[][][] f;
    private int[] prices;
    private int n;

    public int maxProfit(int k, int[] prices) {
        n = prices.length;
        this.prices = prices;
        f = new Integer[n][k + 1][2];
        return dfs(0, k, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i >= n) {
            return 0;
        }
        if (f[i][j][k] != null) {
            return f[i][j][k];
        }
        int ans = dfs(i + 1, j, k);
        if (k > 0) {
            ans = Math.max(ans, prices[i] + dfs(i + 1, j, 0));
        } else if (j > 0) {
            ans = Math.max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
        }
        return f[i][j][k] = ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[n][k + 1][2];
        memset(f, -1, sizeof(f));
        function<int(int, int, int)> dfs = [&](int i, int j, int k) -> int {
            if (i >= n) {
                return 0;
            }
            if (f[i][j][k] != -1) {
                return f[i][j][k];
            }
            int ans = dfs(i + 1, j, k);
            if (k) {
                ans = max(ans, prices[i] + dfs(i + 1, j, 0));
            } else if (j) {
                ans = max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
            }
            return f[i][j][k] = ans;
        };
        return dfs(0, k, 0);
    }
};
```

#### Go

```go
func maxProfit(k int, prices []int) int {
	n := len(prices)
	f := make([][][2]int, n)
	for i := range f {
		f[i] = make([][2]int, k+1)
		for j := range f[i] {
			f[i][j] = [2]int{-1, -1}
		}
	}
	var dfs func(i, j, k int) int
	dfs = func(i, j, k int) int {
		if i >= n {
			return 0
		}
		if f[i][j][k] != -1 {
			return f[i][j][k]
		}
		ans := dfs(i+1, j, k)
		if k > 0 {
			ans = max(ans, prices[i]+dfs(i+1, j, 0))
		} else if j > 0 {
			ans = max(ans, -prices[i]+dfs(i+1, j-1, 1))
		}
		f[i][j][k] = ans
		return ans
	}
	return dfs(0, k, 0)
}
```

#### TypeScript

```ts
function maxProfit(k: number, prices: number[]): number {
    const n = prices.length;
    const f = Array.from({ length: n }, () =>
        Array.from({ length: k + 1 }, () => Array.from({ length: 2 }, () => -1)),
    );
    const dfs = (i: number, j: number, k: number): number => {
        if (i >= n) {
            return 0;
        }
        if (f[i][j][k] !== -1) {
            return f[i][j][k];
        }
        let ans = dfs(i + 1, j, k);
        if (k) {
            ans = Math.max(ans, prices[i] + dfs(i + 1, j, 0));
        } else if (j) {
            ans = Math.max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
        }
        return (f[i][j][k] = ans);
    };
    return dfs(0, k, 0);
}
```

#### C#

```cs
public class Solution {
    private int[,,] f;
    private int[] prices;
    private int n;

    public int MaxProfit(int k, int[] prices) {
        n = prices.Length;
        f = new int[n, k + 1, 2];
        this.prices = prices;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                f[i, j, 0] = -1;
                f[i, j, 1] = -1;
            }
        }
        return dfs(0, k, 0);
    }

    private int dfs(int i, int j, int k) {
        if (i >= n) {
            return 0;
        }
        if (f[i, j, k] != -1) {
            return f[i, j, k];
        }
        int ans = dfs(i + 1, j, k);
        if (k > 0) {
            ans = Math.Max(ans, prices[i] + dfs(i + 1, j, 0));
        }
        else if (j > 0) {
            ans = Math.Max(ans, -prices[i] + dfs(i + 1, j - 1, 1));
        }
        return f[i, j, k] = ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们也可以使用动态规划的方法，定义 $f[i][j][k]$ 表示到第 $i$ 天时，最多交易 $j$ 次（这里我们规定交易次数等于买入次数），且当前持有股票的状态为 $k$ 时，所能获得的最大利润。初始时 $f[i][j][k]=0$。答案即为 $f[n - 1][k][0]$。

当 $i = 0$ 时，股票价格为 $prices[0]$，那么对任意 $j \in [1, k]$，我们有 $f[0][j][1] = -prices[0]$，表示第 $0$ 天买入股票，此时利润为 $-prices[0]$。

当 $i \gt 0$ 时：

-   如果第 $i$ 天不持有股票，可能是第 $i-1$ 天持有股票并且在第 $i$ 天卖出；或者第 $i-1$ 天没持有股票并且第 $i$ 天不进行任何操作。因此 $f[i][j][0] = \max(f[i - 1][j][1] + prices[i], f[i - 1][j][0])$；
-   如果第 $i$ 天持有股票，可能是第 $i-1$ 天没持有股票并且在第 $i$ 天买入；或者第 $i-1$ 天持有股票并且第 $i$ 天不进行任何操作。因此 $f[i][j][1] = \max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1])$。

综上，当 $i \gt 0$ 时，我们可以得到状态转移方程：

$$
\begin{aligned}
f[i][j][0] &= \max(f[i - 1][j][1] + prices[i], f[i - 1][j][0]) \\
f[i][j][1] &= \max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1])
\end{aligned}
$$

最后答案即为 $f[n - 1][k][0]$。

时间复杂度 $O(n \times k)$，空间复杂度 $O(n \times k)$。其中 $n$ 和 $k$ 分别为数组 $prices$ 的长度和 $k$ 的值。

我们注意到，状态 $f[i][]$ 只与状态 $f[i - 1][]$ 有关，因此我们可以优化掉第一维的空间，将空间复杂度降至 $O(k)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        f = [[[0] * 2 for _ in range(k + 1)] for _ in range(n)]
        for j in range(1, k + 1):
            f[0][j][1] = -prices[0]
        for i, x in enumerate(prices[1:], 1):
            for j in range(1, k + 1):
                f[i][j][0] = max(f[i - 1][j][1] + x, f[i - 1][j][0])
                f[i][j][1] = max(f[i - 1][j - 1][0] - x, f[i - 1][j][1])
        return f[n - 1][k][0]
```

#### Java

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][][] f = new int[n][k + 1][2];
        for (int j = 1; j <= k; ++j) {
            f[0][j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j][0] = Math.max(f[i - 1][j][1] + prices[i], f[i - 1][j][0]);
                f[i][j][1] = Math.max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1]);
            }
        }
        return f[n - 1][k][0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[n][k + 1][2];
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= k; ++j) {
            f[0][j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j][0] = max(f[i - 1][j][1] + prices[i], f[i - 1][j][0]);
                f[i][j][1] = max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1]);
            }
        }
        return f[n - 1][k][0];
    }
};
```

#### Go

```go
func maxProfit(k int, prices []int) int {
	n := len(prices)
	f := make([][][2]int, n)
	for i := range f {
		f[i] = make([][2]int, k+1)
	}
	for j := 1; j <= k; j++ {
		f[0][j][1] = -prices[0]
	}
	for i := 1; i < n; i++ {
		for j := 1; j <= k; j++ {
			f[i][j][0] = max(f[i-1][j][1]+prices[i], f[i-1][j][0])
			f[i][j][1] = max(f[i-1][j-1][0]-prices[i], f[i-1][j][1])
		}
	}
	return f[n-1][k][0]
}
```

#### TypeScript

```ts
function maxProfit(k: number, prices: number[]): number {
    const n = prices.length;
    const f = Array.from({ length: n }, () =>
        Array.from({ length: k + 1 }, () => Array.from({ length: 2 }, () => 0)),
    );
    for (let j = 1; j <= k; ++j) {
        f[0][j][1] = -prices[0];
    }
    for (let i = 1; i < n; ++i) {
        for (let j = 1; j <= k; ++j) {
            f[i][j][0] = Math.max(f[i - 1][j][1] + prices[i], f[i - 1][j][0]);
            f[i][j][1] = Math.max(f[i - 1][j - 1][0] - prices[i], f[i - 1][j][1]);
        }
    }
    return f[n - 1][k][0];
}
```

#### C#

```cs
public class Solution {
    public int MaxProfit(int k, int[] prices) {
        int n = prices.Length;
        int[,,] f = new int[n, k + 1, 2];
        for (int j = 1; j <= k; ++j) {
            f[0, j, 1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i, j, 0] = Math.Max(f[i - 1, j, 1] + prices[i], f[i - 1, j, 0]);
                f[i, j, 1] = Math.Max(f[i - 1, j - 1, 0] - prices[i], f[i - 1, j, 1]);
            }
        }
        return f[n - 1, k, 0];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        f = [[0] * 2 for _ in range(k + 1)]
        for j in range(1, k + 1):
            f[j][1] = -prices[0]
        for x in prices[1:]:
            for j in range(k, 0, -1):
                f[j][0] = max(f[j][1] + x, f[j][0])
                f[j][1] = max(f[j - 1][0] - x, f[j][1])
        return f[k][0]
```

#### Java

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][] f = new int[k + 1][2];
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j][0] = Math.max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = Math.max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int f[k + 1][2];
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= k; ++j) {
            f[j][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j; --j) {
                f[j][0] = max(f[j][1] + prices[i], f[j][0]);
                f[j][1] = max(f[j - 1][0] - prices[i], f[j][1]);
            }
        }
        return f[k][0];
    }
};
```

#### Go

```go
func maxProfit(k int, prices []int) int {
	f := make([][2]int, k+1)
	for j := 1; j <= k; j++ {
		f[j][1] = -prices[0]
	}
	for _, x := range prices[1:] {
		for j := k; j > 0; j-- {
			f[j][0] = max(f[j][1]+x, f[j][0])
			f[j][1] = max(f[j-1][0]-x, f[j][1])
		}
	}
	return f[k][0]
}
```

#### TypeScript

```ts
function maxProfit(k: number, prices: number[]): number {
    const f = Array.from({ length: k + 1 }, () => Array.from({ length: 2 }, () => 0));
    for (let j = 1; j <= k; ++j) {
        f[j][1] = -prices[0];
    }
    for (const x of prices.slice(1)) {
        for (let j = k; j; --j) {
            f[j][0] = Math.max(f[j][1] + x, f[j][0]);
            f[j][1] = Math.max(f[j - 1][0] - x, f[j][1]);
        }
    }
    return f[k][0];
}
```

#### C#

```cs
public class Solution {
    public int MaxProfit(int k, int[] prices) {
        int n = prices.Length;
        int[,] f = new int[k + 1, 2];
        for (int j = 1; j <= k; ++j) {
            f[j, 1] = -prices[0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                f[j, 0] = Math.Max(f[j, 1] + prices[i], f[j, 0]);
                f[j, 1] = Math.Max(f[j - 1, 0] - prices[i], f[j, 1]);
            }
        }
        return f[k, 0];
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [189. 轮转数组](https://leetcode.cn/problems/rotate-array){#189}

{{< tabs "189" >}}

{{% tab "python" %}}
```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i: int, j: int):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1

        n = len(nums)
        k %= n
        reverse(0, n - 1)
        reverse(0, k - 1)
        reverse(k, n - 1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] nums;

    public void rotate(int[] nums, int k) {
        this.nums = nums;
        int n = nums.length;
        k %= n;
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    private void reverse(int i, int j) {
        for (; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func rotate(nums []int, k int) {
	n := len(nums)
	k %= n
	reverse := func(i, j int) {
		for ; i < j; i, j = i+1, j-1 {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	reverse(0, n-1)
	reverse(0, k-1)
	reverse(k, n-1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 Do not return anything, modify nums in-place instead.
 */
function rotate(nums: number[], k: number): void {
    const n: number = nums.length;
    k %= n;
    const reverse = (i: number, j: number): void => {
        for (; i < j; ++i, --j) {
            const t: number = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    };
    reverse(0, n - 1);
    reverse(0, k - 1);
    reverse(k, n - 1);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let n = nums.len();
        let k = (k as usize) % n;
        nums.reverse();
        nums[..k].reverse();
        nums[k..].reverse();
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    const n = nums.length;
    k %= n;
    const reverse = (i, j) => {
        for (; i < j; ++i, --j) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    };
    reverse(0, n - 1);
    reverse(0, k - 1);
    reverse(k, n - 1);
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int[] nums;

    public void Rotate(int[] nums, int k) {
        this.nums = nums;
        int n = nums.Length;
        k %= n;
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    private void reverse(int i, int j) {
        for (; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
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

<p>给定一个整数数组 <code>nums</code>，将数组中的元素向右轮转 <code>k</code><em>&nbsp;</em>个位置，其中&nbsp;<code>k</code><em>&nbsp;</em>是非负数。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5,6,7], k = 3
<strong>输出:</strong> <code>[5,6,7,1,2,3,4]</code>
<strong>解释:</strong>
向右轮转 1 步: <code>[7,1,2,3,4,5,6]</code>
向右轮转 2 步: <code>[6,7,1,2,3,4,5]
</code>向右轮转 3 步: <code>[5,6,7,1,2,3,4]</code>
</pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre>
<strong>输入：</strong>nums = [-1,-100,3,99], k = 2
<strong>输出：</strong>[3,99,-1,-100]
<strong>解释:</strong> 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong></p>

<ul>
	<li>尽可能想出更多的解决方案，至少有 <strong>三种</strong> 不同的方法可以解决这个问题。</li>
	<li>你可以使用空间复杂度为&nbsp;<code>O(1)</code> 的&nbsp;<strong>原地&nbsp;</strong>算法解决这个问题吗？</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：三次翻转

我们不妨记数组长度为 $n$，然后将 $k$ 对 $n$ 取模，得到实际需要旋转的步数 $k$。

接下来，我们进行三次翻转，即可得到最终结果：

1. 将整个数组翻转
2. 将前 $k$ 个元素翻转
3. 将后 $n - k$ 个元素翻转

举个例子，对于数组 $[1, 2, 3, 4, 5, 6, 7]$, $k = 3$, $n = 7$, $k \bmod n = 3$。

1. 第一次翻转，将整个数组翻转，得到 $[7, 6, 5, 4, 3, 2, 1]$。
2. 第二次翻转，将前 $k$ 个元素翻转，得到 $[5, 6, 7, 4, 3, 2, 1]$。
3. 第三次翻转，将后 $n - k$ 个元素翻转，得到 $[5, 6, 7, 1, 2, 3, 4]$，即为最终结果。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        def reverse(i: int, j: int):
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i, j = i + 1, j - 1

        n = len(nums)
        k %= n
        reverse(0, n - 1)
        reverse(0, k - 1)
        reverse(k, n - 1)
```

#### Java

```java
class Solution {
    private int[] nums;

    public void rotate(int[] nums, int k) {
        this.nums = nums;
        int n = nums.length;
        k %= n;
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    private void reverse(int i, int j) {
        for (; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
```

#### Go

```go
func rotate(nums []int, k int) {
	n := len(nums)
	k %= n
	reverse := func(i, j int) {
		for ; i < j; i, j = i+1, j-1 {
			nums[i], nums[j] = nums[j], nums[i]
		}
	}
	reverse(0, n-1)
	reverse(0, k-1)
	reverse(k, n-1)
}
```

#### TypeScript

```ts
/**
 Do not return anything, modify nums in-place instead.
 */
function rotate(nums: number[], k: number): void {
    const n: number = nums.length;
    k %= n;
    const reverse = (i: number, j: number): void => {
        for (; i < j; ++i, --j) {
            const t: number = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    };
    reverse(0, n - 1);
    reverse(0, k - 1);
    reverse(k, n - 1);
}
```

#### Rust

```rust
impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let n = nums.len();
        let k = (k as usize) % n;
        nums.reverse();
        nums[..k].reverse();
        nums[k..].reverse();
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    const n = nums.length;
    k %= n;
    const reverse = (i, j) => {
        for (; i < j; ++i, --j) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    };
    reverse(0, n - 1);
    reverse(0, k - 1);
    reverse(k, n - 1);
};
```

#### C#

```cs
public class Solution {
    private int[] nums;

    public void Rotate(int[] nums, int k) {
        this.nums = nums;
        int n = nums.Length;
        k %= n;
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }

    private void reverse(int i, int j) {
        for (; i < j; ++i, --j) {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
