SELECT f.machine_id, ROUND(SUM(s.timestamp - f.timestamp)/COUNT(f.machine_id),3) as processing_time 
FROM Activity f JOIN Activity s
WHERE f.machine_id = s.machine_id  AND f.process_id=s.process_id AND f.activity_type="start" AND s.activity_type ="end"
GROUP BY f.machine_id