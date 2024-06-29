SELECT product_id, year AS first_year , quantity , price
FROM  SALES
WHERE (product_id, year) IN (
    SELECT product_id, MIN(YEAR) as year FROM SALES GROUP BY product_id
)