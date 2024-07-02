SELECT d.name AS Department, T1.name AS Employee , T1.salary AS Salary 
FROM 
    Department d LEFT JOIN
        (
            SELECT *, DENSE_RANK() OVER(
            PARTITION BY departmentId 
            ORDER BY salary DESC
            ) AS DR
            FROM Employee 
        ) AS T1
ON d.id=T1.departmentId 
WHERE T1.DR <= 3