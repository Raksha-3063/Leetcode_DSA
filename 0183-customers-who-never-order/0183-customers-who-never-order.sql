# Write your MySQL query statement below
SELECT c.name AS Customers FROM Customers c
WHERE  NOT EXISTS(SELECT o.id FROM Orders o
                WHERE c.id = o.customerId
);