SELECT (IF(COUNT(salary) = 0, null, salary)) AS SecondHighestSalary FROM (  
     SELECT salary , DENSE_RANK() OVER(
        ORDER BY salary DESC
        ) AS DR
        FROM Employee
) AS X

WHERE DR = 2