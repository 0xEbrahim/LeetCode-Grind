SELECT id, movie, description, rating
FROM CINEMA 
WHERE id%2 = 1 AND description != \boring\
ORDER BY rating DESC