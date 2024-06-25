SELECT f.id
FROM Weather f JOIN Weather s
WHERE DATEDIFF(f.recordDate, s.recordDate)=1 AND f.temperature > s.temperature 