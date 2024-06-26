SELECT p.product_id, IF(ROUND(SUM(p.price * u.units) / SUM(u.units) , 2) IS NULL , 0, ROUND(SUM(p.price * u.units) / SUM(u.units) , 2)) AS average_price 
FROM UnitsSold u RIGHT JOIN Prices p
ON u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date AND u.product_id = p.product_id
GROUP BY p.product_id