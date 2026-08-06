# Write your MySQL query statement below
SELECT A.product_id , COALESCE(ROUND((SUM(A.price * B.units) / SUM(B.units)), 2),0) AS average_price
FROM Prices A
LEFT JOIN UnitsSold B
ON A.product_id = B.product_id AND B.purchase_date BETWEEN A.start_date AND A.end_date
GROUP BY A.product_id;