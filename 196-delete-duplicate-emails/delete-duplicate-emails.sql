# Write your MySQL query statement below

-- DELETE FROM Person WHERE id IN(SELECT id FROM Person WHERE COUNT(email) > 1 GROUP BY email)

DELETE P1 FROM Person AS P1 INNER JOIN Person AS P2 ON 
P1.email = P2.email AND P1.id > P2.id;