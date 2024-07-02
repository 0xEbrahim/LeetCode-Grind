WITH ct AS (
    SELECT * FROM Insurance 
)

SELECT  ROUND(SUM(i.tiv_2016), 2) AS tiv_2016 FROM Insurance i
WHERE (
    SELECT x FROM (
        SELECT COUNT(*) AS x FROM ct WHERE tiv_2015=i.tiv_2015 
    ) AS T1
) > 1
AND (
    SELECT x FROM (
        SELECT COUNT(*) AS x FROM ct 
        WHERE lat=i.lat AND lon=i.lon
    ) AS T2
) = 1
