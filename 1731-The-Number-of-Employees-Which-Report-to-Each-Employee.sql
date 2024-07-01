SELECT s.employee_id, s.name, (SELECT SUM(IF(reports_to=s.employee_id AND employee_id != s.employee_id,1,0)) FROM Employees) AS reports_count,
(SELECT ROUND(SUM(IF(reports_to=s.employee_id AND employee_id != s.employee_id,age,0))/SUM(IF(reports_to=s.employee_id,1,0))) FROM Employees) as average_age 
FROM Employees s
WHERE (SELECT SUM(IF(reports_to=s.employee_id AND employee_id != s.employee_id,1,0)) FROM Employees) >= 1
ORDER BY s.employee_id