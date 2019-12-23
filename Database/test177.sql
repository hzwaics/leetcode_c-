-- 解法一：create function 函数方式
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    select distinct t1.Salary
    from Employee t1
    where N = (
        select count(distinct t2.Salary)
        from Employee t2
        where t2.Salary >= t1.Salary
    )
  );
END

-- 解法二：当然直接用order by和limit也行。要注意的是，limit的偏移从0开始。第N个变成参数时，要改为N-1
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
  RETURN (  
      select distinct salary
      from Employee
      order by salary desc
      limit N,1
  );
END