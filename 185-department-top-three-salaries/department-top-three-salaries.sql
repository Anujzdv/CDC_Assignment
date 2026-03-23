select d.name as Department,
      e.name as Employee,
      e.salary as Salary
from (select *, 
    DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
        ) e 
join Department as d
on e.departmentId = d.id
where rnk <= 3;