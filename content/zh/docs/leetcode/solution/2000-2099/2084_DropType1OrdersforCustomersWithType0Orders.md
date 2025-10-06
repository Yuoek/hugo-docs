---
title: "2084_DropType1OrdersforCustomersWithType0Orders"
date: 2025-10-06T00:42:37+08:00
weight: 2084
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [2084. 为订单类型为 0 的客户删除类型为 1 的订单 🔒](https://leetcode.cn/problems/drop-type-1-orders-for-customers-with-type-0-orders)

[English Version](../en/2084-84/2084_DropType1OrdersforCustomersWithType0Orders)

## 题目描述

<!-- description:start -->

<p>活动表: <code>Orders</code></p>

<pre>+-------------+------+
| Column Name | Type |
+-------------+------+
| order_id    | int  | 
| customer_id | int  |
| order_type  | int  | 
+-------------+------+
order_id是此表的主键列。
此表的每一行都表示订单的ID、订购该订单的客户的ID以及订单类型。
订单可以是类型0或类型1。
</pre>

<p>&nbsp;</p>

<p>编写SQL查询以根据以下条件报告所有订单：</p>

<ul>
	<li>如果客户至少有一个类型为0的订单，则不要报告该客户的任何类型为1的订单。</li>
	<li>否则，报告客户的所有订单。</li>
</ul>

<p>按任意顺序返回结果表。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 
Orders table:
+----------+-------------+------------+
| order_id | customer_id | order_type |
+----------+-------------+------------+
| 1        | 1           | 0          |
| 2        | 1           | 0          |
| 11       | 2           | 0          |
| 12       | 2           | 1          |
| 21       | 3           | 1          |
| 22       | 3           | 0          |
| 31       | 4           | 1          |
| 32       | 4           | 1          |
+----------+-------------+------------+
<strong>输出:</strong> 
+----------+-------------+------------+
| order_id | customer_id | order_type |
+----------+-------------+------------+
| 31       | 4           | 1          |
| 32       | 4           | 1          |
| 1        | 1           | 0          |
| 2        | 1           | 0          |
| 11       | 2           | 0          |
| 22       | 3           | 0          |
+----------+-------------+------------+
<strong>解释:</strong> 
客户1有两个类型为0的订单。我们两个都返回。
客户2的订单类型为0，订单类型为1。我们只返回类型为0的订单。
客户3的订单类型为0，订单类型为1。我们只返回类型为0的订单。
客户4有两个类型1的订单。我们两个都返回。
</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "sql" %}}
```sql
SELECT DISTINCT
    a.order_id,
    a.customer_id,
    a.order_type
FROM
    Orders AS a
    LEFT JOIN Orders AS b ON a.customer_id = b.customer_id AND a.order_type != b.order_type
WHERE b.order_type IS NULL OR b.order_type = 1;
```
{{% /tab %}}
{{< /tabs>}}

