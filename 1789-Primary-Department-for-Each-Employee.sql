SELECT e.employee_id , e.department_id 
FROM Employee e
WHERE e.primary_flag='Y' OR (
    (
    SELECT SUM(IF(e.employee_id=employee_id,1,0))
    FROM Employee
    ) = 1 AND e.primary_flag='N'
)