# Write your MySQL query statement below
SELECT DISTINCT customer_id FROM Customer
GROUP BY 1
HAVING count(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);