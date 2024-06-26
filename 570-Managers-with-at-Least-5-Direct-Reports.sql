SELECT e.name
FROM EMPLOYEE e
WHERE e.id IN (
    SELECT m.managerId 
    FROM EMPLOYEE m
    GROUP BY m.managerId
    HAVING COUNT(m.managerId) >= 5
)