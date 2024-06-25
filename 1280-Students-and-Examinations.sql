SELECT s.student_id, s.student_name, sub.subject_name, COUNT(e.subject_name) AS attended_exams
FROM STUDENTS s JOIN SUBJECTS sub
LEFT JOIN EXAMINATIONS e
ON s.student_id=e.student_id AND e.subject_name=sub.subject_name
GROUP BY s.student_id, s.student_name, sub.subject_name
ORDER BY s.student_id ASC, sub.subject_name ASC