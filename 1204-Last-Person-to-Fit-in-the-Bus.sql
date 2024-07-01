SELECT q.person_name
FROM Queue q
HAVING (
    SELECT SUM(weight)
    FROM Queue
    where turn <= q.turn
) <= 1000
ORDER BY turn DESC
LIMIT 1