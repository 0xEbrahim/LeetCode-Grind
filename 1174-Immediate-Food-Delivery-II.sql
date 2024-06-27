SELECT ROUND(
    (SUM(
        IF(DATEDIFF(order_date,customer_pref_delivery_date) = 0 , 1 , 0)
        ) / COUNT(*)
      ) * 100, 2) AS immediate_percentage 
FROM
    (
    SELECT *, ROW_NUMBER() OVER(
    PARTITION BY customer_id
    ORDER BY order_date ASC
    ) AS RN
FROM Delivery 
) AS T1
WHERE RN=1