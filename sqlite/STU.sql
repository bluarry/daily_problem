/*******************************
姓名:冶英杰
学号:15030120022
********************************/

/*******************************
一。创建数据库Stuinfo
********************************/
USE master;
GO
CREATE DATABASE Stuinfo 
ON
PRIMARY  
    (NAME = Arch1,
    FILENAME = 'D:\database\Stu\studat1.mdf',
    SIZE = 100MB,
    MAXSIZE = 200,
    FILEGROWTH = 20)
LOG ON 
   (NAME = Archlog1,
    FILENAME = 'D:\database\Stu\stulog1.ldf',
    SIZE = 100MB,
    MAXSIZE = 200,
    FILEGROWTH = 20);
GO


/********************************************
二、创建表
********************************************/
--学生表
use Stuinfo;
GO
CREATE TABLE S(	
	Sno CHAR(20)NOT NULL UNIQUE,
	Sname CHAR(20)NOT NULL,
	Sex CHAR(4) CHECK(Sex IN ('m','f')),
	Sage INT CHECK(Sage > 0 AND Sage < 150),
	Sdept CHAR(10),
	PRIMARY KEY (Sno)
);
--课程表
CREATE TABLE C(
	Cno CHAR(5)NOT NULL UNIQUE,
	Cname CHAR(30) NOT NULL,
	Ccredit INT CHECK(Ccredit >0),
	Cpno CHAR(5),
	PRIMARY KEY (Cno)
);

--选课表
CREATE TABLE SC(
	Sno CHAR(20),
	Cno CHAR(5),
	Grade INT CHECK(Grade>=0 AND Grade <=100),
	PRIMARY KEY(Sno,Cno),
	FOREIGN KEY (Sno) REFERENCES S(Sno),
	FOREIGN KEY (Cno) REFERENCES C(Cno)
);
GO


/********************************************
三.数据更新
********************************************/
--S表
INSERT INTO S VALUES('95001','李勇','m',20,'CS');
INSERT INTO S VALUES('95002','刘晨','f',19,'IS');
INSERT INTO S VALUES('95003','王敏','f',18,'MA');
INSERT INTO S VALUES('95004','张立','m',19,'IS');
GO
--C表
INSERT INTO C VALUES('c1','数据库',4,'c5');
INSERT INTO C VALUES('c2','高等数学',4,'');
INSERT INTO C VALUES('c3','信息系统',4,'c1');
INSERT INTO C VALUES('c4','操作系统',4,'c6');
INSERT INTO C VALUES('c5','数据结构',4,'c7');
INSERT INTO C VALUES('c6','数据处理',4,'');
INSERT INTO C VALUES('c7','PASCAL语言',4,'c6');
GO
--SC 表
INSERT INTO SC VALUES ('95001','c1',92);
INSERT INTO SC VALUES ('95001','c2',65);
INSERT INTO SC VALUES ('95001','c4',88);
INSERT INTO SC VALUES ('95002','c2',90);
INSERT INTO SC VALUES ('95002','c5',73);
GO


/********************************************
四、查询
********************************************/
--1.查询所有年龄在20岁以下的学生姓名及年龄
SELECT Sname,Sage
FROM S
WHERE Sage<20;
GO

--2.查询选修了课程名‘数据库’的学生学号和姓名
--方法一：元组演算查询
SELECT Sno,Sname
FROM S
WHERE Sno IN(
	SELECT Sno
	FROM SC
	WHERE Cno=(
		SELECT Cno
		FROM C
		WHERE Cname='数据库'));
GO
--方法二: 关系代数查询
SELECT S.Sno,Sname
FROM S,SC,C
WHERE S.Sno=SC.Sno AND SC.Cno=C.Cno AND C.Cname='数据库';
GO

--3.查询其他系中比信息系某些学生年龄小的学生姓名和年龄
SELECT Sname,Sage
From S
WHERE Sage < (
		SELECT MAX(Sage)
		FROM S
		WHERE Sdept='IS')
	AND Sdept <> 'IS';
GO
--4.查询所有选修了c1号课程的学生姓名
--方法一：元组演算
SELECT Sname
FROM S
WHERE EXISTS
		(	SELECT	*
			FROM SC
			WHERE Sno=S.Sno AND Cno='c1'
			);
GO
--方法二：关系代数实现
SELECT Sname
FROM S,SC
WHERE S.Sno=SC.Sno AND SC.Cno='c1';
GO

--5.查询没有选修了c1号课程的学生姓名
--方法一:元组演算
SELECT Sname
FROM S
WHERE NOT EXISTS(
		SELECT *
		FROM SC
		WHERE Sno=S.Sno AND Cno='c1'
);
GO
--方法二：关系代数
SELECT Sname
FROM S
WHERE Sno NOT IN 
	(
		SELECT Sno
		FROM SC
		WHERE Cno='c1');
GO

--6.查询选修了全部课程的学生姓名
--方法一：元组演算
SELECT Sname
FROM S
WHERE NOT EXISTS
	(SELECT *
	FROM C
	WHERE NOT EXISTS
		(SELECT *
		FROM SC
		WHERE Sno=S.Sno AND Cno=C.Cno
		));
GO
--方法二:关系代数
SELECT Sname 
FROM S
WHERE Sno NOT IN
	(SELECT Sno
	FROM (
		SELECT Sno,Cno
		FROM S,C
		EXCEPT
		SELECT Sno,Cno
		FROM SC
		) AS SU
	);
GO
--7.查询计算机系年龄不大于21岁的学生学号
--方法一：
SELECT Sno
FROM S
WHERE Sdept='CS' AND Sage <=21;
GO
--方法二：
SELECT Sno
FROM S
WHERE Sdept='CS'
EXCEPT	--注意在sqlserver中不是MINUS
SELECT Sno
FROM S
WHERE Sage >21;
GO
--8.查询'数据库'课程成绩最高的学生学号
SELECT Sno
FROM SC
WHERE Grade=
	(SELECT MAX(Grade)
	FROM SC
	WHERE Cno=(SELECT Cno
				FROM C
				WHERE Cname='数据库'	)
	AND Cno=(SELECT Cno
				FROM C
				WHERE Cname='数据库'	)
	);
GO
--9.查询选修了课程c1和c2的学生学号
SELECT SCX.Sno
FROM SC SCX
WHERE SCX.Cno='c1' AND 
	EXISTS (SELECT *
			FROM SC SCY
			WHERE SCX.Sno=SCY.Sno
				AND SCY.Cno='c2');
GO
--10.查询平均成绩最高的学生学号
SELECT Sno
FROM SC
GROUP BY Sno
	HAVING AVG(Grade) >=ALL
		(SELECT AVG(Grade)
		FROM SC
		GROUP BY Sno);
GO
