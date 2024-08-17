# Write your MySQL query statement below

SELECT A.id AS Id FROM Weather AS A LEFT JOIN Weather AS B ON A.recordDate = DATE_ADD(B.recordDate, INTERVAL 1 DAY) WHERE A.temperature > B.temperature;