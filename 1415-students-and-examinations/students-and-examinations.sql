# Write your MySQL query statement below

-- First Count the Subjects in Total

SELECT A.student_id,A.student_name,A.subject_name,COUNT(Examinations.subject_name) AS attended_exams FROM 
(SELECT * FROM Students INNER JOIN Subjects ON true 
ORDER BY student_id,subject_name) AS A
LEFT JOIN Examinations ON (A.student_id = Examinations.student_id AND A.subject_name = Examinations.subject_name) 
GROUP BY A.subject_name,A.student_id,A.student_name ORDER BY A.student_id,A.subject_name;