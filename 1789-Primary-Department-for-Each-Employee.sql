SELECT e.employee_id , e.department_id 
FROM Employee e
WHERE e.primary_flag='Y' 
UNION
SELECT e.employee_id , e.department_id 
FROM Employee e
GROUP BY employee_id
HAVING COUNT(employee_id)=1