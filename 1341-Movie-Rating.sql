WITH t1 AS (
    SELECT u.name AS  results , COUNT(m.movie_id) as cnt
        FROM MovieRating m RIGHT JOIN Users u
        ON m.user_id = u.user_id
        GROUP BY m.user_id
), t2 AS (
       SELECT m.title  AS results, AVG(r.rating) AS average
        FROM Movies m LEFT JOIN MovieRating r
        ON m.movie_id = r.movie_id
        WHERE r.created_at BETWEEN "2020-02-01" AND "2020-02-29"
        GROUP BY r.movie_id
)

(
    SELECT results FROM t1
    WHERE cnt = (
    SELECT MAX(cnt) FROM t1
    )
    ORDER BY results ASC
    LIMIT 1
)

UNION ALL

(
    SELECT results FROM t2
    WHERE average = (SELECT MAX(average) FROM t2 )
    ORDER BY results ASC
    LIMIT 1
)