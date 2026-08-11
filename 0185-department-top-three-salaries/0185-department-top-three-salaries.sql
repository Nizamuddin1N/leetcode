# Write your MySQL query statement below
WITH rankedSalaries AS (SELECT d.name AS Department, e.name AS Employee, e.salary AS salary, DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS dr FROM Employee e JOIN Department d ON e.departmentId = d.id)
SELECT Department, Employee, Salary FROM rankedSalaries WHERE dr <=3;
