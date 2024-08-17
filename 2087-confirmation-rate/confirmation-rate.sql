# Write your MySQL query statement below

-- SELECT KP.user_id,ROUND(IFNULL(IFNULL(End,0)/IFNULL(Start,0),0),2) As confirmation_rate FROM
-- (SELECT A.user_id,B.action,COUNT(B.action) AS Start FROM Signups AS A LEFT JOIN Confirmations AS B ON A.user_id = B.user_id GROUP BY A.user_id) AS KP
-- LEFT JOIN
-- (SELECT A.user_id,B.action,IFNULL(COUNT(B.action),0) AS End FROM Signups AS A LEFT JOIN Confirmations AS B ON A.user_id = B.user_id WHERE B.action = "confirmed" GROUP BY A.user_id) AS JP
-- ON KP.user_id = JP.user_id;

SELECT S.user_id,ROUND(
        IFNULL(
            IFNULL(SUM(CASE WHEN C.action = 'confirmed' THEN 1 ELSE 0 END), 0) / 
            IFNULL(COUNT(C.user_id), 0), 
        0), 
    2) AS confirmation_rate FROM Signups AS S LEFT JOIN Confirmations AS C ON S.user_id = C.user_id GROUP BY S.user_id;

-- Try All This in One Query
-- In which you can use Conditional Aggregation and Combined Queries instead of Nested Queries
