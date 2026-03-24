# DataBase 基础语法

## 1.表的定义

eg1.1:创建学生表

```mysql
CREATE TABLES S//s是表名，可以替换
(Sno CHAR(5) NOT NULL UNIQUE primary key,//直接在约束条件处加主码标识
Sname char(20) unique,
Ssex char(1),default'男'//缺省值，默认是男
Sage int,
Sdept char(15)
);
```

#### 主码

创建表时已经展示一种了，另一种添加主码方式如下：

```mysql
CREATE TABLE SC
(
Sno CHAR(5) ,
Cno CHAR(3) , 
Grade INT,
Primary key (Sno, Cno)//单独拎出来，特别地，关键字是由多个属性构成，必须使用此方法
);
```

#### 外码

1）如果外部关键字只有一个属性，可以在它的属性名和类型后面直接用“REFERENCES”说明它参照了某个表的某些属性，其格式为：

```mysql
REFERENCES <表名>(<属性>)
```

表名是参照外部的表名，属性是两个表共有属性，靠此属性来联系两个表

eg1.2:为学生选课表创建外码

```mysql
CREATE TABLE SC
( Sno CHAR(5) REFERENCES S(Sno) ,
Cno CHAR(3) REFERENCES C(Cno),
Grade INT,
PRIMARY KEY (Sno,Cno));
```

2）在CREATE TABLE语句的属性列表后面增加一个或几个外部关键字说明，其格式为： 

```mysql
FOREIGN KEY (<属性>) REFERENCES <表名>(<属性>)
```

eg1.2另一种写法：

```mysql
CREATE TABLE SC
(SNO CHAR(8),
 CNO CHAR(4),
 GRADE SAMLLINT,
 PRIMARY KEY (SNO,CNO),
 FOREIGN KEY (SNO) REFERENCES S(SNO),
 FOREIGN KEY (CNO) REFERENCES C(CNO)
);
```

## 2.表的修改和删除

### 1.修改基本表

增删改列或者列的完整性约束条件

```mysql
ALTER TABLE <表名>
[ ADD <新列名> <数据类型> [ 完整性约束 ] ]
[ DROP <完整性约束名> ]
[ MODIFY <列名> <数据类型> ]；
```

ps：中括号的意思为`可选`

eg2.1:

```mysql
//向学生表增加“入学时间”列，其数据类型为日期型。
ALTER TABLE S ADD Scome DATE;
//将年龄的数据类型改为半字长整数。
 ALTER TABLE S MODIFY Sage SMALLINT；
//删除学生姓名必须取唯一值的约束。
 ALTER TABLE S DROP UNIQUE(Sname)；
```

++不论基本表中原来是否已有数据，新增加的列**一律为空值**。++修改原有的列定义可能会破坏已有数据。

### 2.删除基本表

`DROP TABLE <表名>;` 

## 3.索引的建立与删除

### 3.1聚簇索引

聚集索引根据数据行的键值在表或视图中排序和存储这些数据行。每个表**只能有一个**聚集索引。查询效率高。底层数据结构是**B+树**。

适用于：很少对表进行增删操作，很少对变长列进行修改

### 3.2非聚簇索引

非聚集索引具有独立于数据行的结构。非聚集索引包含非聚集索引键值，并且每个键值项都有指向包含该键值的数据行的指针。从非聚集索引中的索引行指向数据行的指针称为行定位器。

### 3.3索引的建立

`CREATE [UNIQUE] [CLUSTER] INDEX <索引名> ON <表名>(<列名>[<次序>][,<列名>[<次序>] ]…)；`

– 用<表名>指定要建索引的基本表名字

– 索引可以建立在该表的一列或多列上，各列名之间用逗号分隔

– 用<次序>指定索引值的排列次序，升序：ASC，降序：DESC。**缺省值：ASC**

– UNIQUE表明此索引的++每一个索引值只对应唯一的数据记录++,因此，像学生成绩这样的属性不可以加unique，因为会有重复。

– CLUSTER表示要建立的索引是聚集索引

```mysql
/*为学生-课程数据库中的S，C，SC三个表建立索引。其中S表按学号升序建唯一索引，C表按课程升序建唯一索引，SC表按学号升序和课程号降序建唯一索引。*/
CREATE UNIQUE INDEX Stusno ON S (Sno)；
CREATE UNIQUE INDEX Coucno ON C (Cno)；
CREATE UNIQUE INDEX SCno ON SC(Sno ASC，Cno DESC)；
```

### 3.4删除索引

`DROP INDEX <索引名>；`

## 4.单表查询

### 4.1选择表中的若干列（投影）

#### 语句格式：

```mysql
语句格式
SELECT [ALL|DISTINCT] <目标列表达式>
[，<目标列表达式>] …
FROM <表名或视图名>[, <表名或视图名> ] …
[ WHERE <条件表达式> ]
[ GROUP BY <列名1> ]
[ HAVING <条件表达式> ]
[ ORDER BY <列名2> [ ASC|DESC ] ]；
```

学生-课程数据库

• 学生表：S(Sno，Sname，Ssex，Sage，Sdept)

• 课程表：C(Cno，Cname，Cpno，Ccredit)

• 学生选课表：SC(Sno，Cno，Grade) 

```mysql
//查询全体学生的学号与姓名。
SELECT Sno,Sname FROM S;
//查询全体学生的详细记录。
SELECT * FROM S;
```

#### 查询经过计算的值

```mysql
//查询全体学生的姓名及其出生年份。
SELECT Sname,year(now())-Sage FROM S;
```

使用列**别名**改变查询结果的列标题：

```mysql
SELECT Sname, year(now())-Sage as BirthYear FROM S；
```

输出的时候，计算的值的列名就是BirthYear

### 4.2选择表中的若干元组（选择）

#### 4.2.1消除取值重复的行

添加`DISTINCT短语`	

注意 ：DISTINCT短语的作用范围是**所有**目标列（所有目标属性完全一致则去重），故而我们只需要一个distinct

```mysql
SELECT DISTINCT Cno，Grade FROM SC;
```

要想不消除取值重复的行选择`ALL短语`即可。

#### 4.2.2查询满足条件的元组

使用`WHERE语句`

##### 1)比较大小

在WHERE子句的<比较条件>中使用比较运算符

• = ，>，<，>=，<=，!= 或 <>，!>，!<，

• 逻辑运算符NOT 与 比较运算符 结合

```mysql
//查询所有年龄在20岁以下的学生姓名及其年龄。
SELECT Sname,Sage
FROM S WHERE Sage<20;
```

##### 2)确定范围

• 使用谓词：  BETWEEN … AND …

​			NOT BETWEEN … AND …

```mysql
//查询年龄不在20~23岁之间的学生姓名、系别和年龄
SELECT Sname,Sdept,Sage
FROM S 
WHERE NOT BETWEEN 20 AND 23;
```

##### 3)确定集合

• 使用谓词：  IN <值表>, NOT IN <值表>

​			<值表>：用逗号分隔的一组取值

```mysql
//查询信息系（IS）、数学系（MA）和计算机科学系（CS）学生的姓名和性别
SELECT Sname,Ssex
FROM S
WHERE Sdept in('IS','MA','CS');
```

##### 4)字符匹配

• [NOT] LIKE ‘<匹配串>’ [ESCAPE ‘ <转义字符>’]

​			<匹配串>：指定匹配模板

a.%（百分号）代表任意长度，可以为0

b._（下横线）代表单个字符

c.`escape语句`:避免转义’%‘ 和 ’_‘

注意：如果要查的字符串是固定的，可以用=代替LIKE谓词，!=或者<>代替NOT LIKE谓词

```mysql
//查询以"DB_"开头，且倒数第3个字符为 i的课程的详细情况
SELECT *
FROM C
WHERE Cname like 'DB\_%I__'ESCAPE'\';
```

##### 5)空值查询

使用谓词`IS NULL`或者`IS NOT NULL`

​		或者`=NULL`

```mysql
//某些学生选修课程后没有参加考试，所以有选课记录，但没有考试成绩。查询缺少成绩的学生的学号和相应的课程号。
SELECT Sname,Cno
FROM SC
WHERE GRADE IS NULL;
```

##### 6)多重条件查询

用`AND`和`or`连接，前者优先级更高

### 4.3对查询结果排序

使用`ORDER BY`子句

即`ORDER BY <属性列> [DESC/ASC]`

升序：ASC；降序：DESC；缺省值为升序

含有空值的时候：（空值最大） ASC：排序列为空值的元组最后显示 ，DESC：排序列为空值的元组最先显示 

```mysql
//查询选修了3号课程的学生的学号及其成绩，查询结果按分数降序排列。
SELECT Sno,GRADE
FROM SC
WHERE Cno='3'
ORDER BY GRADE DESC;
//查询全体学生情况，查询结果按所在系的系号升序排列，同一系中的学生按年龄降序排列。
SELECT *
FROM S
ORDER BY Sdept,Sage DESC;
```

### 4.4使用集函数

**集函数放在select后面**

–计数 `COUNT（[DISTINCT|ALL] *） COUNT（[DISTINCT|ALL] <列名>） `

–计算总和` SUM（[DISTINCT|ALL] <列名>）`  

– 计算平均值 `AVG（[DISTINCT|ALL] <列名>）`

–求最大值` MAX（[DISTINCT|ALL] <列名> `

–求最小值` MIN（[DISTINCT|ALL] <列名> `

– DISTINCT短语：在计算时要取消指定列中的重复值 

– ALL短语：不取消重复值 – ALL为缺省值

```mysql
//计算1号课程的学生平均成绩。
SELECT AVG(Grade)
FROM SC
WHERE Cno='1';
//查询选修1号课程的学生最高分数。
SELECT MAX(Grade)
FROM SC
WHERE Cno='1';
```

### 4.5对查询结果分组

使用`GROUP BY`子句

注意集函数的作用对象：**未**对查询结果分组，集函数将作用于**整个查询结果** ；对查询结果分组后，集函数将**分别作用于每个组** 

```mysql
//求各个课程号及相应的选课人数。
SELECT Cno,COUNT(Sno)
FROM SC
GROUP BY Cno ;
```

输出的结果就是每个课程号的选课人数

**使用`HAVING`短语筛选最终输出结果**

```mysql
//查询选修了3门以上课程的学生学号。
SELECT Sno
FROM SC
GROUP BY Sno
HAVING COUNT(*)>3;//这里的count计算的是每个学生分组后，学习表中选课记录
//查询有3门以上课程是90分以上的学生的学号及（90分以上的）课程数
SELECT Sno,COUNT(*)
FROM SC
WHERE Grade>90
GROUP BY Sno
HAVING COUNT(Cno)>3;
```

