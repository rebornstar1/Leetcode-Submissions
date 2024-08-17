# Write your MySQL query statement below

SELECT A.name FROM Employee AS A 
LEFT JOIN 
Employee AS B ON A.id = B.managerId WHERE B.managerId IS NOT NULL GROUP BY B.managerId HAVING COUNT(B.managerId) >= 5;

-- This is a Nested Query Need to write this in a better way