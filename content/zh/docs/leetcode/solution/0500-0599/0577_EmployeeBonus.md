---
title: "0577_EmployeeBonus"
date: 2025-10-06T00:42:37+08:00
weight: 0577
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [577. 员工奖金](https://leetcode.cn/problems/employee-bonus)

[English Version](../en/0577-77/0577_EmployeeBonus)

## 题目描述

<!-- description:start -->

<p>表：<code>Employee</code>&nbsp;</p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| empId       | int     |
| name        | varchar |
| supervisor  | int     |
| salary      | int     |
+-------------+---------+
empId 是该表中具有唯一值的列。
该表的每一行都表示员工的 id 和姓名，以及他们经理的 id 和他们的工资。
</pre>

<p>&nbsp;</p>

<p>表：<code>Bonus</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| empId       | int  |
| bonus       | int  |
+-------------+------+
empId 是该表具有唯一值的列。
empId 是 Employee 表中 empId 的外键(reference 列)。
该表的每一行都包含一个员工的 id 和他们各自的奖金。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，报告每个奖金 <strong>少于</strong> <code>1000</code> 的员工的姓名和奖金数额。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>
Employee table:
+-------+--------+------------+--------+
| empId | name   | supervisor | salary |
+-------+--------+------------+--------+
| 3     | Brad   | null       | 4000   |
| 1     | John   | 3          | 1000   |
| 2     | Dan    | 3          | 2000   |
| 4     | Thomas | 3          | 4000   |
+-------+--------+------------+--------+
Bonus table:
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
<b>输出：</b>
+------+-------+
| name | bonus |
+------+-------+
| Brad | null  |
| John | null  |
| Dan  | 500   |
+------+-------+</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：左连接

我们可以使用左连接，将 `Employee` 表和 `Bonus` 表按照 `empId` 进行连接，然后筛选出奖金小于 $1000$ 的员工。注意，连接后的表中，`bonus` 为 `NULL` 的员工也应该被筛选出来，因此我们需要使用 `IFNULL` 函数将 `NULL` 值转换为 $0$。

<!-- tabs:start -->

#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT name, bonus
FROM
    Employee
    LEFT JOIN Bonus USING (empId)
WHERE IFNULL(bonus, 0) < 1000;
```
{{% /tab %}}
{{< /tabs>}}

