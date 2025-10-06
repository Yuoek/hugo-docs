---
title: "0570_ManagerswithatLeast5DirectReports"
date: 2025-10-06T00:42:37+08:00
weight: 0570
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [570. 至少有5名直接下属的经理](https://leetcode.cn/problems/managers-with-at-least-5-direct-reports)

[English Version](../en/0570-70/0570_ManagerswithatLeast5DirectReports)

## 题目描述

<!-- description:start -->

<p>表:&nbsp;<code>Employee</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| department  | varchar |
| managerId   | int     |
+-------------+---------+
id 是此表的主键（具有唯一值的列）。
该表的每一行表示雇员的名字、他们的部门和他们的经理的id。
如果managerId为空，则该员工没有经理。
没有员工会成为自己的管理者。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，找出至少有<strong>五个直接下属</strong>的经理。</p>

<p>以 <strong>任意顺序 </strong>返回结果表。</p>

<p>查询结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Employee 表:
+-----+-------+------------+-----------+
| id  | name  | department | managerId |
+-----+-------+------------+-----------+
| 101 | John  | A          | Null      |
| 102 | Dan   | A          | 101       |
| 103 | James | A          | 101       |
| 104 | Amy   | A          | 101       |
| 105 | Anne  | A          | 101       |
| 106 | Ron   | B          | 101       |
+-----+-------+------------+-----------+
<strong>输出:</strong> 
+------+
| name |
+------+
| John |
+------+</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：分组统计 + 连接

我们可以先统计每个经理的直接下属人数，然后再连接 `Employee` 表，找出直接下属人数大于等于 $5$ 的经理。

<!-- tabs:start -->

#### Python3



#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    # Group the employees by managerId and count the number of direct reports
    manager_report_count = (
        employee.groupby("managerId").size().reset_index(name="directReports")
    )

    # Filter managers with at least five direct reports
    result = manager_report_count[manager_report_count["directReports"] >= 5]

    # Merge with the Employee table to get the names of these managers
    result = result.merge(
        employee[["id", "name"]], left_on="managerId", right_on="id", how="inner"
    )

    # Select only the 'name' column and drop the 'id' and 'directReports' columns
    result = result[["name"]]

    return result
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name
FROM
    Employee
    JOIN (
        SELECT managerId AS id, COUNT(1) AS cnt
        FROM Employee
        GROUP BY 1
        HAVING cnt >= 5
    ) AS t
        USING (id);
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
import pandas as pd


def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    # Group the employees by managerId and count the number of direct reports
    manager_report_count = (
        employee.groupby("managerId").size().reset_index(name="directReports")
    )

    # Filter managers with at least five direct reports
    result = manager_report_count[manager_report_count["directReports"] >= 5]

    # Merge with the Employee table to get the names of these managers
    result = result.merge(
        employee[["id", "name"]], left_on="managerId", right_on="id", how="inner"
    )

    # Select only the 'name' column and drop the 'id' and 'directReports' columns
    result = result[["name"]]

    return result
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}