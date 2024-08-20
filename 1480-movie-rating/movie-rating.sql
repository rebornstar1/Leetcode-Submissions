# Write your MySQL query statement below

(SELECT name AS results FROM Users AS U 
LEFT JOIN MovieRating 
AS M ON U.user_id = M.user_id 
GROUP BY name ORDER BY COUNT(movie_id) DESC, U.name LIMIT 1)

UNION ALL

(SELECT title AS results FROM Movies AS MS LEFT JOIN MovieRating AS MR 
ON MS.movie_id = MR.movie_id WHERE MR.created_at BETWEEN '2020-02-01' AND '2020-02-29' GROUP BY title 
ORDER BY AVG(rating) DESC, title LIMIT 1);