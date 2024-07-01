SELECT product_id, IF(MAX(price)=-10,10,MAX(price)) AS price FROM (SELECT product_id, price 
FROM 
(
    SELECT product_id ,  new_price AS price, ROW_NUMBER() OVER(
    PARTITION BY product_id 
    ORDER BY change_date DESC
    ) AS RN
FROM products
WHERE change_date<="2019-08-16"
) T1
WHERE RN=1
UNION (
    SELECT product_id, -10 AS price
    FROM Products
    WHERE change_date > "2019-08-16"
)
) AS t2
GROUP BY product_id