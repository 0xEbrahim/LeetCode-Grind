SELECT MAX(num) as num
FROM (
    SELECT num, COUNT(num) as xx
    FROM MyNumbers 
    GROUP BY num
) AS x
WHERE xx = 1