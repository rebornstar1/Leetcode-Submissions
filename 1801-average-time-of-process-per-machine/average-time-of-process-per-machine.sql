# Write your MySQL query statement below

SELECT A.machine_id
,ROUND(AVG(B.timestamp-A.timestamp),3) AS processing_time
FROM (SELECT * FROM Activity WHERE Activity.activity_type = "start")
AS A 
LEFT JOIN
(SELECT * FROM Activity WHERE Activity.activity_type = "end") 
AS B ON (A.process_id = B.process_id AND A.machine_id = B.machine_id) GROUP BY machine_id;