SELECT teacher_id, COUNT(*) AS cnt
FROM (
    SELECT DISTINCT teacher_id, subject_id FROM Teacher
    ) AS T1
GROUP BY teacher_id