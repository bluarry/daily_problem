/*******************************
����:ұӢ��
ѧ��:15030120022
********************************/

/*******************************
һ���������ݿ�Stuinfo
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
����������
********************************************/
--ѧ����
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
--�γ̱�
CREATE TABLE C(
	Cno CHAR(5)NOT NULL UNIQUE,
	Cname CHAR(30) NOT NULL,
	Ccredit INT CHECK(Ccredit >0),
	Cpno CHAR(5),
	PRIMARY KEY (Cno)
);

--ѡ�α�
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
��.���ݸ���
********************************************/
--S��
INSERT INTO S VALUES('95001','����','m',20,'CS');
INSERT INTO S VALUES('95002','����','f',19,'IS');
INSERT INTO S VALUES('95003','����','f',18,'MA');
INSERT INTO S VALUES('95004','����','m',19,'IS');
GO
--C��
INSERT INTO C VALUES('c1','���ݿ�',4,'c5');
INSERT INTO C VALUES('c2','�ߵ���ѧ',4,'');
INSERT INTO C VALUES('c3','��Ϣϵͳ',4,'c1');
INSERT INTO C VALUES('c4','����ϵͳ',4,'c6');
INSERT INTO C VALUES('c5','���ݽṹ',4,'c7');
INSERT INTO C VALUES('c6','���ݴ���',4,'');
INSERT INTO C VALUES('c7','PASCAL����',4,'c6');
GO
--SC ��
INSERT INTO SC VALUES ('95001','c1',92);
INSERT INTO SC VALUES ('95001','c2',65);
INSERT INTO SC VALUES ('95001','c4',88);
INSERT INTO SC VALUES ('95002','c2',90);
INSERT INTO SC VALUES ('95002','c5',73);
GO


/********************************************
�ġ���ѯ
********************************************/
--1.��ѯ����������20�����µ�ѧ������������
SELECT Sname,Sage
FROM S
WHERE Sage<20;
GO

--2.��ѯѡ���˿γ��������ݿ⡯��ѧ��ѧ�ź�����
--����һ��Ԫ�������ѯ
SELECT Sno,Sname
FROM S
WHERE Sno IN(
	SELECT Sno
	FROM SC
	WHERE Cno=(
		SELECT Cno
		FROM C
		WHERE Cname='���ݿ�'));
GO
--������: ��ϵ������ѯ
SELECT S.Sno,Sname
FROM S,SC,C
WHERE S.Sno=SC.Sno AND SC.Cno=C.Cno AND C.Cname='���ݿ�';
GO

--3.��ѯ����ϵ�б���ϢϵĳЩѧ������С��ѧ������������
SELECT Sname,Sage
From S
WHERE Sage < (
		SELECT MAX(Sage)
		FROM S
		WHERE Sdept='IS')
	AND Sdept <> 'IS';
GO
--4.��ѯ����ѡ����c1�ſγ̵�ѧ������
--����һ��Ԫ������
SELECT Sname
FROM S
WHERE EXISTS
		(	SELECT	*
			FROM SC
			WHERE Sno=S.Sno AND Cno='c1'
			);
GO
--����������ϵ����ʵ��
SELECT Sname
FROM S,SC
WHERE S.Sno=SC.Sno AND SC.Cno='c1';
GO

--5.��ѯû��ѡ����c1�ſγ̵�ѧ������
--����һ:Ԫ������
SELECT Sname
FROM S
WHERE NOT EXISTS(
		SELECT *
		FROM SC
		WHERE Sno=S.Sno AND Cno='c1'
);
GO
--����������ϵ����
SELECT Sname
FROM S
WHERE Sno NOT IN 
	(
		SELECT Sno
		FROM SC
		WHERE Cno='c1');
GO

--6.��ѯѡ����ȫ���γ̵�ѧ������
--����һ��Ԫ������
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
--������:��ϵ����
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
--7.��ѯ�����ϵ���䲻����21���ѧ��ѧ��
--����һ��
SELECT Sno
FROM S
WHERE Sdept='CS' AND Sage <=21;
GO
--��������
SELECT Sno
FROM S
WHERE Sdept='CS'
EXCEPT	--ע����sqlserver�в���MINUS
SELECT Sno
FROM S
WHERE Sage >21;
GO
--8.��ѯ'���ݿ�'�γ̳ɼ���ߵ�ѧ��ѧ��
SELECT Sno
FROM SC
WHERE Grade=
	(SELECT MAX(Grade)
	FROM SC
	WHERE Cno=(SELECT Cno
				FROM C
				WHERE Cname='���ݿ�'	)
	AND Cno=(SELECT Cno
				FROM C
				WHERE Cname='���ݿ�'	)
	);
GO
--9.��ѯѡ���˿γ�c1��c2��ѧ��ѧ��
SELECT SCX.Sno
FROM SC SCX
WHERE SCX.Cno='c1' AND 
	EXISTS (SELECT *
			FROM SC SCY
			WHERE SCX.Sno=SCY.Sno
				AND SCY.Cno='c2');
GO
--10.��ѯƽ���ɼ���ߵ�ѧ��ѧ��
SELECT Sno
FROM SC
GROUP BY Sno
	HAVING AVG(Grade) >=ALL
		(SELECT AVG(Grade)
		FROM SC
		GROUP BY Sno);
GO
