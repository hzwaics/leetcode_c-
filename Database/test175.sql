SELECT P.FirstName, P.LastName, A.City, A.State 
FROM Person AS P LEFT JOIN Address AS A on P.PersonId=A.PersonId;

-- join 用于把来自两个或多个表的行结合起来
-- INNER JOIN：如果表中有至少一个匹配，则返回行
-- LEFT JOIN：即使右表中没有匹配，也从左表返回所有的行
-- RIGHT JOIN：即使左表中没有匹配，也从右表返回所有的行
-- FULL JOIN：只要其中一个表中存在匹配，则返回行

-- on 条件是在生成临时表时使用的条件，它不管 on 中的条件是否为真，都会返回左边表中的记录。
-- where 条件是在临时表生成好后，再对临时表进行过滤的条件。这时已经没有 left join 的含义（必须返回左边表的记录）了，条件不为真的就全部过滤掉。