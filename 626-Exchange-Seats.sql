WITH ct1 AS
(
   ( SELECT * FROM Seat)
    UNION (
        SELECT id + 1 AS id , student FROM Seat
        ORDER BY id DESC
        LIMIT 1
    )
)


SELECT s.id,  CASE 
        WHEN (id % 2 = 1)
         THEN (
                SELECT student FROM ct1 WHERE id = (s.id + 1)
             )
        ELSE  (
                SELECT student FROM ct1 WHERE id = (s.id - 1)
            )
        END
        AS student                         
FROM Seat s