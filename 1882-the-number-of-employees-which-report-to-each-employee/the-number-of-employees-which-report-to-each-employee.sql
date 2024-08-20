# Write your MySQL query statement below

SELECT A.employee_id,A.name,COUNT(B.reports_to) AS reports_count,ROUND(AVG(B.age),0) AS average_age FROM Employees AS A LEFT JOIN Employees AS B ON A.employee_id = B.reports_to GROUP BY B.reports_to 
HAVING COUNT(B.reports_to) != 0 ORDER BY A.employee_id ASC;