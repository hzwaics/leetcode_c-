-- # 解法一 表自连接
-- # 用表的自连接，构造偏序关系。再找次序的最大值，就一定是第二高的薪水。
-- # 同时，max在没有元组输入时，还能返回NULL。比如在表中的元组少于2个时。
SELECT MAX(l1.salary) as SecondHighestSalary
FROM Employee as l1 JOIN Employee as l2 
WHERE l1.salary < l2.salary;


-- # 解法二 子查询
-- 子查询方法。用子查询找出最大值，再排除最大值的结果中，求最大值。一定要借助于MAX函数。
select max(salary) as SecondHighestSalary
from Employee
where salary !=(select max(salary) from Employee);

select max(E.Salary) as SecondHighestSalary
from Employee as E
where E.Salary < (select max(Salary) from Employee);

select max(E1.Salary) as SecondHighestSalary
from Employee as E1 
where 1 = (select count(*)	from Employee as E2	where E1.Salary < E2.Salary);

-- 不用MAX函数的方法也是有的，但显得有些麻烦。
SELECT DISTINCT Salary AS SecondHighestSalary FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1;