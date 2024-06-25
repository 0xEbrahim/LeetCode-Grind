SELECT tweet_id FROM (SELECT tweet_id , content
FROM Tweets t
HAVING LENGTH(CONTENT) > 15
)t1