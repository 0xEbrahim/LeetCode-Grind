SELECT month,
 country,
  COUNT(*) AS trans_count,
   SUM(IF(state="approved",1,0)) AS approved_count ,
    SUM(amount) AS trans_total_amount ,
     SUM(IF(state="approved", amount, 0)) AS approved_total_amount 
FROM (
    SELECT country, state, amount, DATE_FORMAT(CAST(trans_date as DATE), "%Y-%m") as month
    FROM Transactions 
)T1
GROUP BY month, country