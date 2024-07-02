WITH ct1 AS (
    SELECT requester_id as id, COUNT(accepter_id) AS cnt
    FROM RequestAccepted 
    GROUP BY requester_id
),
ct2 AS (
    SELECT accepter_id as id, COUNT(requester_id) AS cnt
    FROM RequestAccepted 
    GROUP BY accepter_id
),
tot AS (
    SELECT * FROM ct1
    UNION ALL
    SELECT * FROM ct2
)

SELECT DISTINCT id, SUM(cnt) as num
FROM tot
GROUP BY id
HAVING SUM(cnt) = (
    SELECT MAX(x) FROM (
        SELECT SUM(cnt) as x FROM tot GROUP BY id
    ) AS xd
)