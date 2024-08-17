# Write your MySQL query statement below

SELECT name FROM Employee AS A 
LEFT JOIN 
(SELECT managerId,COUNT(managerId) FROM Employee WHERE Employee.managerId IS NOT NULL GROUP BY Employee.managerId HAVING COUNT(managerId) >= 5) AS B
ON A.id = B.managerId WHERE B.managerId IS NOT NULL;