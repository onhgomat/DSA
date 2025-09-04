WITH banned_users AS (
    SELECT users_id
    FROM Users
    WHERE banned = "Yes"
)

SELECT 
    request_at AS Day, 
    ROUND(SUM(IF(status != "completed", 1, 0)) / COUNT(*), 2) AS "Cancellation Rate"
FROM Trips
WHERE 
    request_at BETWEEN "2013-10-01" AND "2013-10-03"
    AND client_id NOT IN (SELECT * FROM banned_users)
    AND driver_id NOT IN (SELECT * FROM banned_users)
GROUP BY request_at;
