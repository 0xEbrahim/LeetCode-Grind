SELECT e.name, s.bonus 
FROM Employee e LEFT JOIN Bonus s
ON e.empID=s.empID 
WHERE s.bonus < 1000 OR s.bonus is NULL