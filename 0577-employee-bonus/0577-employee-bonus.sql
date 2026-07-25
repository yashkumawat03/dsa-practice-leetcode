# Write your MySQL query statement below
SELECT name, bonus
FROM Employee AS A
LEFT JOIN Bonus AS B
ON A.empId = B.empId
WHERE bonus IS NULL OR bonus < 1000;