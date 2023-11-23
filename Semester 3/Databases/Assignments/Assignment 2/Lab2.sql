INSERT INTO CarMakes(CarMakeID, CarMakeName) VALUES (1, 'BMW')
INSERT INTO CarMakes(CarMakeID, CarMakeName) VALUES (1, 'Mercedes')
INSERT INTO CarMakes(CarMakeID, CarMakeName) VALUES (2, 'Honda')
INSERT INTO CarMakes(CarMakeID, CarMakeName) VALUES (3, 'Audi')
INSERT INTO CarMakes(CarMakeID, CarMakeName) VALUES (4, 'Skoda')
INSERT INTO CarMakes(CarMakeID, CarMakeName) VALUES (5, 'Mercedes')


INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (1, 'M4', 1);  
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (2, 'X3', 1);  
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (3, 'Civic', 2);  
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (4, 'Accord', 2);  
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (5, 'A3', 3);     
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (6, 'Q5', 3);     
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (7, 'Octavia', 4); 
INSERT INTO CarModels(ModelID, ModelName, CarMakeID) VALUES (7, 'Superb', 5); 


INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (1, 'Engine Components');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (2, 'Braking System');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (3, 'Transmission Parts');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (4, 'Electrical Components');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (5, 'Suspension and Steering');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (6, 'Exhaust System');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (7, 'Interior Accessories');
INSERT INTO CarPartsCategories (CarPartsCategoryID, CarpartsCategoryName) VALUES (8, 'Exterior Accessories');


INSERT INTO CarPartsManufacturers (ManufacturerID, ManufacturerName) VALUES (1, 'ACME Auto Parts');
INSERT INTO CarPartsManufacturers (ManufacturerID, ManufacturerName) VALUES (2, 'SuperDrive Motors');
INSERT INTO CarPartsManufacturers (ManufacturerID, ManufacturerName) VALUES (3, 'AutoTech Components');
INSERT INTO CarPartsManufacturers (ManufacturerID, ManufacturerName) VALUES (4, 'MegaParts Industries');
INSERT INTO CarPartsManufacturers (ManufacturerID, ManufacturerName) VALUES (5, 'Quality Auto Supplies');


INSERT INTO Customer (CustomerID, CustomerName, ContactInfo) VALUES (1,'John Doe', 'john.doe@email.com');
INSERT INTO Customer (CustomerID, CustomerName, ContactInfo) VALUES (2,'Jane Smith', 'jane.smith@email.com');
INSERT INTO Customer (CustomerID, CustomerName, ContactInfo) VALUES (3,'Bob Johnson', 'bob.johnson@email.com');
INSERT INTO Customer (CustomerID, CustomerName, ContactInfo) VALUES (4,'Marian Stancu', 'marian.stancu@email.com');
INSERT INTO Customer (CustomerID, CustomerName, ContactInfo) VALUES (5,'Catalin Stanciulescu', 'catalin.stanciulescu@email.com');


INSERT INTO CustomerOrders (OrderID, CustomerID, OrderDate, TotalPrice) VALUES (1,1, '2023-10-27', 500.00);
INSERT INTO CustomerOrders (OrderID, CustomerID, OrderDate, TotalPrice) VALUES (2,2, '2023-10-28', 750.00);
INSERT INTO CustomerOrders (OrderID, CustomerID, OrderDate, TotalPrice) VALUES (3,3, '2023-10-29', 600.00);
INSERT INTO CustomerOrders (OrderID, CustomerID, OrderDate, TotalPrice) VALUES (4,2, '2023-10-31', 300.00);
INSERT INTO CustomerOrders (OrderID, CustomerID, OrderDate, TotalPrice) VALUES (5,5, '2023-02-25', 250.00);


UPDATE CustomerOrders
SET TotalPrice = 750.00
WHERE OrderID = 2 AND CustomerID = 2;

--INSERT INTO CustomerOrders (OrderID, CustomerID, OrderDate, TotalPrice) VALUES (4,3, '2023-10-29', 300.00);

INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (1, 'AutoZone Components', 'contact@autopartsinc.com');
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (2, 'CarPro Parts', 'info@cartechcomponents.com');
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (3, 'AutoGears Ltd.', 'support@qualityautosupplies.com');
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (4, 'PartsRUs Corporation', 'sales@autotechindustries.com');
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (5, 'MotoParts Enterprises', 'info@megapartsenterprises.com');
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (6, 'Arinovis', 'info@arinovis.ro')
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (7, 'AutoTech Suppliers', 'contact@autotechsuppliers.com')
INSERT INTO Suppliers (SupplierID, SupplierName, ContactInfo) VALUES (8, 'CarTech Innovations', 'sales@cartechinnovations.com');


INSERT INTO CarParts (PartID, PartName, CarPartsCategoryID, ModelID, ManufacturerID) VALUES (1, 'Engine Piston', 1, 1, 1);
INSERT INTO CarParts (PartID, PartName, CarPartsCategoryID, ModelID, ManufacturerID) VALUES (2, 'Brake Pads', 2, 3, 2);
INSERT INTO CarParts (PartID, PartName, CarPartsCategoryID, ModelID, ManufacturerID) VALUES (3, 'Transmission Gearbox', 3, 5, 3);
INSERT INTO CarParts (PartID, PartName, CarPartsCategoryID, ModelID, ManufacturerID) VALUES (4, 'Alternator', 4, 7, 4);
INSERT INTO CarParts (PartID, PartName, CarPartsCategoryID, ModelID, ManufacturerID) VALUES (5, 'Suspension Strut', 5, 2, 5);


INSERT INTO Inventory (InventoryID, PartID, SupplierID, Quantity, Price) VALUES (1, 1, 1, 50, 75.00);
INSERT INTO Inventory (InventoryID, PartID, SupplierID, Quantity, Price) VALUES (2, 2, 2, 100, 45.00);
INSERT INTO Inventory (InventoryID, PartID, SupplierID, Quantity, Price) VALUES (3, 3, 3, 30, 120.00);
INSERT INTO Inventory (InventoryID, PartID, SupplierID, Quantity, Price) VALUES (4, 4, 4, 20, 90.00);
INSERT INTO Inventory (InventoryID, PartID, SupplierID, Quantity, Price) VALUES (5, 5, 5, 75, 60.00);


INSERT INTO PartSuppliers (PartID, SupplierID) VALUES (1, 1);
INSERT INTO PartSuppliers (PartID, SupplierID) VALUES (2, 2);
INSERT INTO PartSuppliers (PartID, SupplierID) VALUES (3, 3);
INSERT INTO PartSuppliers (PartID, SupplierID) VALUES (4, 4);
INSERT INTO PartSuppliers (PartID, SupplierID) VALUES (5, 5);


INSERT INTO OrderItems (OrderItemID, OrderID, PartID, Quantity, UnitPrice) VALUES (1, 1, 1, 2, 75.00);
INSERT INTO OrderItems (OrderItemID, OrderID, PartID, Quantity, UnitPrice) VALUES (6, 1, 3, 2, 50.00);
INSERT INTO OrderItems (OrderItemID, OrderID, PartID, Quantity, UnitPrice) VALUES (2, 1, 2, 4, 45.00);
INSERT INTO OrderItems (OrderItemID, OrderID, PartID, Quantity, UnitPrice) VALUES (3, 2, 3, 1, 120.00);
INSERT INTO OrderItems (OrderItemID, OrderID, PartID, Quantity, UnitPrice) VALUES (4, 3, 4, 2, 90.00);
INSERT INTO OrderItems (OrderItemID, OrderID, PartID, Quantity, UnitPrice) VALUES (5, 3, 5, 3, 60.00);


INSERT INTO CustomerOrderItems (OrderID, OrderItemID) VALUES (1, 1);
INSERT INTO CustomerOrderItems (OrderID, OrderItemID) VALUES (1, 2);
INSERT INTO CustomerOrderItems (OrderID, OrderItemID) VALUES (2, 3);
INSERT INTO CustomerOrderItems (OrderID, OrderItemID) VALUES (3, 4);
INSERT INTO CustomerOrderItems (OrderID, OrderItemID) VALUES (3, 5);


--------------------------------------------------UPDATE------------------------------------------------------------
UPDATE Customer
SET ContactInfo = 'john.doe@email.com'
WHERE CustomerName = 'John Doe';


UPDATE CarParts
SET PartName = 'High-Performance Transmission Gearbox'
WHERE PartID = 3;



UPDATE CustomerOrders
SET OrderDate = '2023-11-01'
WHERE OrderDate BETWEEN '2023-10-25' AND '2023-10-28';


-----------------------------------------------DELETE------------------------------------------------------------

-- Delete customers whose names contain the word 'Doe'
DELETE FROM Customer
WHERE CustomerName LIKE '%Marian%';

DELETE FROM Suppliers
WHERE SupplierName LIKE 'Arinovis';



-----Subpoint a)

SELECT CarMakeName AS Make
FROM CarMakes
UNION ALL(
			SELECT ModelName AS Make
			FROM CarModels)



SELECT CarMakeName
FROM CarMakes
WHERE CarMakeName = 'BMW'
UNION
		SELECT ModelName
		FROM CarModels
		WHERE ModelName = 'M4';

-----Subpoint b)
SELECT CustomerID
FROM Customer
INTERSECT
SELECT CustomerID
FROM CustomerOrders;


SELECT CarpartsCategoryName
FROM CarPartsCategories
WHERE CarPartsCategoryID IN (
    SELECT CarPartsCategoryID
    FROM CarParts
);


--------Subpoint c)

SELECT CarPartsCategoryID
FROM CarPartsCategories
EXCEPT
SELECT CarPartsCategoryID
FROM CarParts;




SELECT SupplierID
FROM Suppliers
WHERE SupplierID NOT IN (
    SELECT SupplierID
    FROM Inventory
);




-------------Subpoint d)

SELECT *
FROM CarParts C
RIGHT JOIN CarPartsCategories ON C.CarPartsCategoryID = CarPartsCategories.CarPartsCategoryID;


SELECT *
FROM CarModels C
LEFT JOIN CarParts ON C.ModelID = CarParts.ModelID;


SELECT *
FROM CarMakes C
INNER JOIN CarModels CM ON C.CarMakeID = CM.CarMakeID
INNER JOIN CarParts ON CM.ModelID = CarParts.ModelID;



SELECT
    P.PartName AS PartName,
    S.SupplierName AS SupplierName,
    I.Quantity AS Quantity,
    I.Price AS Price,
    O.OrderID AS OrderID,
    O.CustomerID AS CustomerID
FROM
    PartSuppliers PS
FULL JOIN Inventory I ON PS.PartID = I.PartID
FULL JOIN Suppliers S ON PS.SupplierID = S.SupplierID
FULL JOIN OrderItems OI ON I.PartID = OI.PartID
FULL JOIN CustomerOrderItems COI ON OI.OrderItemID = COI.OrderItemID
FULL JOIN CustomerOrders O ON COI.OrderID = O.OrderID
FULL JOIN CarParts P ON I.PartID = P.PartID
ORDER BY
    PartName;


-------Subpoint e)

SELECT CustomerName
FROM Customer
WHERE CustomerID IN (
    SELECT CustomerID
    FROM CustomerOrders
);



SELECT DISTINCT S.SupplierName
FROM Suppliers AS S
WHERE SupplierID IN (
    SELECT PS.SupplierID
    FROM PartSuppliers AS PS
    WHERE PS.PartID IN (
        SELECT I.PartID
        FROM Inventory AS I
    )
);


-------Subpoint f)
SELECT S.SupplierName
FROM Suppliers AS S
WHERE EXISTS ( SELECT SupplierID 
			   FROM Inventory AS I
				WHERE S.SupplierID = I.SupplierID AND I.Price > 80.00);


SELECT CM.CarMakeName
FROM CarMakes AS CM
WHERE EXISTS (  SELECT C.ModelName
				FROM CarModels as C
				WHERE CM.CarMakeID = C.CarMakeID AND C.ModelName LIKE '%v%');

--------Subpoint g)


---Find the TOP 2 customers, in DESC order with the highest order price average.
SELECT TOP 2 CustomerName, AvgTotalPrice
FROM (
    SELECT c.CustomerID, c.CustomerName, AVG(co.TotalPrice) AS AvgTotalPrice
    FROM Customer c
    JOIN CustomerOrders co ON c.CustomerID = co.CustomerID
    GROUP BY c.CustomerID, c.CustomerName
) AS CustomerAverage
ORDER BY AvgTotalPrice DESC;


-- Identify the two most popular car makes in orders.
SELECT TOP 2 CarMakeName
FROM (
    SELECT DISTINCT cm.CarMakeName, COUNT(*) AS MakeCount
    FROM CarMakes cm
    JOIN CarModels m ON cm.CarMakeID = m.CarMakeID
    JOIN CarParts p ON m.ModelID = p.ModelID
    JOIN OrderItems oi ON p.PartID = oi.PartID
    JOIN CustomerOrders co ON oi.OrderID = co.OrderID
    GROUP BY cm.CarMakeName
) AS MakeFrequency
ORDER BY MakeCount DESC;





--------Subpoint h)

--Calculate the total order value for each customer and filter customers with total orders greater than $50:
SELECT C.CustomerName, SUM(O.TotalPrice) AS TotalOrderValue
FROM Customer C
LEFT JOIN CustomerOrders O ON C.CustomerID = O.CustomerID
GROUP BY C.CustomerName
HAVING SUM(O.TotalPrice) > 50
ORDER BY TotalOrderValue ASC;


-- Identify manufacturers whose top inventory value is below the average  inventory value of all suppliers.
SELECT ManufacturerID, MAX(Price * Quantity) AS MaxInventoryValue
FROM Inventory
JOIN CarParts ON Inventory.PartID = CarParts.PartID
GROUP BY ManufacturerID
HAVING MAX(Price * Quantity) < (
    SELECT AVG(MaxInventory) FROM (
        SELECT MAX(Price * Quantity) AS MaxInventory
        FROM Inventory
        GROUP BY SupplierID
    ) AS SubQuery
);

---List car makes that have more models than the average across all makes.
SELECT CarMakeName, COUNT(ModelID) AS NumberOfModels
FROM CarMakes
JOIN CarModels ON CarMakes.CarMakeID = CarModels.CarMakeID
GROUP BY CarMakeName
HAVING COUNT(ModelID) > (
    SELECT AVG(ModelCount) FROM (
        SELECT COUNT(ModelID) AS ModelCount
        FROM CarModels
        GROUP BY CarMakeID
    ) AS ModelCounts
);

-- Find car models with over 1 order based on order item counts.

SELECT cm.ModelID, cm.ModelName, COUNT(oi.OrderItemID) AS NumberOfOrderItems
FROM CarModels cm
JOIN CarParts cp ON cm.ModelID = cp.ModelID
JOIN OrderItems oi ON cp.PartID = oi.PartID
GROUP BY cm.ModelID, cm.ModelName
HAVING COUNT(oi.OrderItemID) > 1;



-------Subpoint i)

------------------------------ANY-------------------------

--Find customers who have placed any order that has a TotalPrice greater than at least one order placed by 'John Doe':
SELECT *
FROM CustomerOrders
WHERE TotalPrice > ANY (SELECT TotalPrice FROM CustomerOrders WHERE CustomerID = (SELECT CustomerID FROM Customer WHERE CustomerName = 'John Doe'));


--Rewrite 
SELECT *
FROM CustomerOrders
WHERE TotalPrice > (SELECT MIN(TotalPrice) FROM CustomerOrders WHERE CustomerID = (SELECT CustomerID FROM Customer WHERE CustomerName = 'John Doe'));


--Find customers that have placed an order for a cart part that is not from manufacturer with id 1
SELECT DISTINCT c.CustomerID, c.CustomerName
FROM Customer c
JOIN CustomerOrders co ON c.CustomerID = co.CustomerID
JOIN OrderItems oi ON co.OrderID = oi.OrderID
JOIN CarParts cp ON oi.PartID = cp.PartID
WHERE cp.ManufacturerID <> ANY (SELECT ManufacturerID FROM CarPartsManufacturers WHERE ManufacturerID = 1);


--Rewrite 
SELECT DISTINCT c.CustomerID, c.CustomerName
FROM Customer c
JOIN CustomerOrders co ON c.CustomerID = co.CustomerID
JOIN OrderItems oi ON co.OrderID = oi.OrderID
JOIN CarParts cp ON oi.PartID = cp.PartID
WHERE cp.ManufacturerID NOT IN (SELECT ManufacturerID FROM CarPartsManufacturers WHERE ManufacturerID = 1);


-------------------------ALLL------------------


--Find customers who have placed orders with a TotalPrice less than the min price of all orders placed by 'Jane Smith':
SELECT *
FROM CustomerOrders
WHERE TotalPrice < ALL (SELECT TotalPrice 
						FROM CustomerOrders 
						WHERE CustomerID = (SELECT CustomerID 
											FROM Customer 
											WHERE CustomerName = 'Jane Smith'));

--Rewrite 
SELECT *
FROM CustomerOrders
WHERE TotalPrice < (SELECT MIN(TotalPrice) 
					FROM CustomerOrders 
					WHERE CustomerID = (SELECT CustomerID 
										FROM Customer 
										WHERE CustomerName = 'Jane Smith'));


--- Find all customers who have placed orders with a total price less than the maximum total price from all orders.

SELECT CustomerID, CustomerName
FROM Customer
WHERE CustomerID = ANY (
    SELECT CustomerID
    FROM CustomerOrders
    WHERE TotalPrice < ALL (
        SELECT MAX(TotalPrice)
        FROM CustomerOrders
    )
);

--Rewrite

SELECT CustomerID, CustomerName
FROM Customer
WHERE EXISTS (
    SELECT 1
    FROM CustomerOrders
    WHERE Customer.CustomerID = CustomerOrders.CustomerID
    AND TotalPrice < (
        SELECT MAX(TotalPrice)
        FROM CustomerOrders
    )
);


