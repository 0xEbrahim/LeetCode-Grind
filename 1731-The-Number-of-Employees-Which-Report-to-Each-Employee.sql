SELECT employee_id, name, COUNT(employee_id) AS reports_count , ROUND(AVG(age)) AS average_age  FROM (
    SELECT e1.employee_id, e1.name,e2.age FROM Employees e1 RIGHT JOIN Employees e2
    ON e1.employee_id=e2.reports_to
) T1
WHERE employee_id IS NOT NULL
GROUP BY employee_id
ORDER BY employee_id