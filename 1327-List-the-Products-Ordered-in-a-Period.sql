SELECT p.product_name, SUM(o.unit) AS unit
FROM Products p RIGHT JOIN Orders o
ON p.product_id=o.product_id
WHERE order_date >= "2020-02-01" AND order_date <= "2020-02-29"
GROUP BY o.product_id
HAVING SUM(unit) >= 100