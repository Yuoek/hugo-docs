---
date: 2025-10-21T23:13:40+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
bookCollapseSection: true
---

{{< katex />}}

根据下面实验目的和实验原理以及实验内容写出 实验心得/实验总结
实验目的
熟悉SQL Server 的主要工具，掌握SQL Server 服务管理器、SQL Server Management Studio、SQL Server查询分析器的使用，并了解其他辅助工具或向导，掌握在Microsoft SQL Server Management Studio中和查询分析器中创建、修改、删除数据库；学会在设计器中实现基本表的创建、修改，表中数据的增加等操作。
实验原理
（1）创建数据库的基本语法为：
CREATE DATABASE <数据库名>
[ON [PRIMARY][(NAME = <逻辑数据文件名>，]
FILENAME= <操作数据文件路径和文件名>
[,SIZE= <文件长度>]
[, MAXSIZE= <最大长度>]
[, FILEGROWTH= <文件增长率>])[,…n]]
[LOG ON ([NAME=<逻辑日志文件名>,]
FILENAME= <操作日志文件路径和文件名> 
[,SIZE=<文件长度>]
[ , MAXSIZE= <最大长度>]
[, FILEGROWTH= <文件增长率>])[,…n]];
使用 sql 命令行
CREATE DATABASE student
ON 
PRIMARY 
(
    NAME = 'stu_1',
    FILENAME = 'd:\stu_1.mdf',
    SIZE = 10MB,
    MAXSIZE = 100MB,
    FILEGROWTH = 5%
)
LOG ON 
(
    NAME = 'stu_1_log',
    FILENAME = 'd:\stu_1_log.LDF',
    SIZE = 1MB,
    MAXSIZE = 30MB,
    FILEGROWTH = 1MB
);

ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MariaDB server version for the right syntax to use near 'ON                                                                                                         PRIMARY                                                                                                                             (                                                                                                                                       NAME = 'stu_1',                                                                                                                     FILENAME = 'd:\stu_1.mdf',                                                                                                          SIZE = ...' at line 2
MariaDB 
①数据库名为student。
②数据库中包含一个基本数据文件,逻辑文件名为stu_ 1,物理文件名为~/Yuoek/Yuoek/stu_1,文件初始容量为10MB,最大容量为100MB,文件容量递增值为5%。
③数据库中包含一个事务日志文件,逻辑文件名为stu _1_log,物理文件名为~/Yuoek/Yuoek/stu_1 log,文件初始容量为1MB,最大容量为30MB,文件增长速度为1MB。

（2）选择/使用数据库的基本语法
     USE <数据库名>
（3）删除数据库的基本语法
     DROP DATABASE<数据库名>
3. 实验内容
（1）使用SQL Server 的Microsoft SQL Server Management Studio,创建一个数据库，要求如下:
①数据库名为student。
②数据库中包含一个基本数据文件,逻辑文件名为stu_ 1,物理文件名为d:\stu_1. mdf,文件初始容量为10MB,最大容量为100MB,文件容量递增值为5%。
③数据库中包含一个事务日志文件,逻辑文件名为stu _1_log,物理文件名为d:\stu_1 log. LDF,文件初始容量为1MB,最大容量为30MB,文件增长速度为1MB。
（2）使用SQL Server 2005的Microsoft SQL Server Management Studio,对数据库作如下修改:
将日志文件stu_1_log的最大容量增加为50MB，递增值改为3MB。
（3）删除student数据库。
（4）在查询分析器中使用Create Database 命令创建数据库student，要求与实验内容（1）一样。
（5）在查询分析器中使用数据库student。
表1 学生表S的数据结构
字段名称
字段说明
数据类型
长度
是否为空
备注

SNO
学号
VARCHAR
10
NOT NULL
主键

SNAME
名字
VARCHAR
10
NOT NULL


SEX
性别
VARCHAR
2
NULL
‘男’或‘女’

AGE
年龄
INT
4
NULL
大于5岁

SDEPT
系别
VARCHAR
10
NULL


（6）通过表设计器在数据库student中创建学生表S，表结构如表1所示。
表2 课程表C的数据结构
字段名称
字段说明
数据类型
长度
是否为空
备注

CNO
课程号
VARCHAR
6
NOT NULL
主键

CNAME
课程名
VARCHAR
20
NOT NULL


PCNO
先修课程
VARCHAR
6
NULL


CREAT
学分
INT
4
NULL
默认4

（7）通过表设计器在数据库student中创建课程表C，表结构如表2所示。
表3 选修表SC的数据结构
字段名称
字段说明
数据类型
长度
是否为空
备注

CNO
课程号
VARCHAR
6
NOT NULL
主键为（SNO,CNO）

SNO
学号
VARCHAR
10
NOT NULL


GRADE
成绩
INT
4
NULL
在[0,100]

（8）通过表设计器在数据库student中创建选修表SC，表结构如表3所示。
（9）在表设计器中创建参照完整性。使SC表中的SNO参照S表中的SNO属性，SC表中的CNO参照C表中CNO属性。
（10）生成S，C，SC三个表的关系图。

4．实验代码和结果截图
（1）  在查询分析器中使用Create Database 命令创建数据库student，要求与实验内容（1）一样。
生成S，C，SC三个表的关系图。

5. 实验心得/实验总结


### 实验心得

通过本次实验，我深入学习了SQL Server的基本操作，掌握了数据库的创建、修改、删除以及数据表的建立与维护。以下是我在实验过程中的主要收获与体会：
通过实际操作，我掌握了SQL Server Management Studio（SSMS）的基本界面与功能，并能够根据要求设置数据文件和日志文件的逻辑名称、物理路径、初始大小、最大容量及增长率等参数。也能通过SQL语句使用数据库，例如创建、删除和使用数据库的命令。除此之外，我还学会表的使用,创建了学生表（S）、课程表（C）和选修表（SC），并按照要求设置了各字段的数据类型、长度、是否允许为空以及主键约束。然后设置外键约束，实现了SC表中的SNO参照S表中的SNO，CNO参照C表中的CNO。最后学会了使用关系的功能，生成了S、C、SC三个表之间的关系图，这样能能直观地展示了表之间的关联，加深了对数据库关系模型的理解。

不过在初次使用SQL语句创建数据库时，由于自己对语法细节还不够熟悉，出现了几次错误，例如少写了分号，通过回看实验原理要求命令才得以正确使用，究其原因是不能熟悉 sql 命令行语法。
其次是在在设置参照完整性时，需注意外键字段与主键字段的数据类型和长度必须一致，否则会导致约束创建失败。最后是只有设置好各个表的主键后才能创建各个表的关系图。

### 总结：
本次实验不仅让我掌握了SQL Server的基本操作 (使用图形化界面以及命令行)，还提高了我的动手能力和问题搜索和解决能力。通过理论与实践的结合，我对数据库的设计与管理有了更深入的认识，为后续的数据库学习打下了坚实的基础。


