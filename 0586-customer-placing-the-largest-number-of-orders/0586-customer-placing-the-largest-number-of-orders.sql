# Write your MySQL query statement below
SELECT customer_number FROM(
SELECT customer_number, count(*) as A
FROM Orders
GROUP BY customer_number
ORDER BY A DESC
LIMIT 1
)t;
