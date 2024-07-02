WITH ct1 AS (
    SELECT visited_on, amount
    FROM Customer
)

SELECT DISTINCT c1.visited_on, (
    SELECT SUM(amount) FROM (
        SELECT amount
        FROM ct1 
        WHERE DATEDIFF(c1.visited_on, visited_on) <= 6 AND c1.visited_on >= visited_on
    ) AS t1
) as amount ,(
SELECT ROUND(SUM(amount) / 7 , 2) FROM (
        SELECT amount
        FROM ct1 
        WHERE DATEDIFF(c1.visited_on, visited_on) <= 6 AND c1.visited_on >= visited_on
    ) AS t1
) as average_amount
FROM Customer c1 JOIN Customer c2
WHERE c1.visited_on - c2.visited_on >= 6
ORDER BY c1.visited_on ASC