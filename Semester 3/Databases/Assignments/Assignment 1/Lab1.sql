Create database CarPartsShop
use CarPartsShop
go

CREATE TABLE Customer(
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(255) NOT NULL,
    ContactInfo VARCHAR(255)
);

CREATE TABLE CustomerOrders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    OrderDate DATE,
    TotalPrice DECIMAL(10, 2),
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID)

);

CREATE TABLE CarPartsCategories (
    CarPartsCategoryID INT PRIMARY KEY,
    CarpartsCategoryName VARCHAR(255) NOT NULL
);

CREATE TABLE CarMakes (
    CarMakeID INT PRIMARY KEY,
    CarMakeName VARCHAR(255) NOT NULL
);

CREATE TABLE CarModels (
    ModelID INT PRIMARY KEY,
    ModelName VARCHAR(255) NOT NULL,
    CarMakeID INT FOREIGN KEY REFERENCES CarMakes(CarMakeID)
);

CREATE TABLE CarPartsManufacturers (
    ManufacturerID INT PRIMARY KEY,
    ManufacturerName VARCHAR(255) NOT NULL
);


CREATE TABLE CarParts (
    PartID INT PRIMARY KEY,
    PartName VARCHAR(255) NOT NULL,
    CarPartsCategoryID INT FOREIGN KEY REFERENCES CarPartsCategories(CarPartsCategoryID), 
    ModelID INT FOREIGN KEY REFERENCES CarModels(ModelID),
	ManufacturerID INT FOREIGN KEY REFERENCES CarPartsManufacturers(ManufacturerID)
);

ALTER TABLE CarParts
DROP COLUMN PartCategoryID;

CREATE TABLE OrderItems (
    OrderItemID INT PRIMARY KEY,
    OrderID INT,
    PartID INT,
    Quantity INT CHECK (Quantity >= 0),
    UnitPrice DECIMAL(10, 2) CHECK (UnitPrice >= 0.00),
    FOREIGN KEY (PartID) REFERENCES CarParts(PartID)
);

CREATE TABLE CustomerOrderItems (

    OrderID INT FOREIGN KEY (OrderID) REFERENCES CustomerOrders(OrderID),
    OrderItemID INT FOREIGN KEY (OrderItemID) REFERENCES OrderItems(OrderItemID)
	CONSTRAINT pk_CustomerOrderItems PRIMARY KEY (OrderID, OrderItemID)

);

CREATE TABLE Suppliers (
    SupplierID INT PRIMARY KEY,
    SupplierName VARCHAR(255) NOT NULL UNIQUE,
    ContactInfo VARCHAR(255)
);

CREATE TABLE PartSuppliers (
    PartID INT FOREIGN KEY REFERENCES CarParts(PartID),
    SupplierID INT FOREIGN KEY REFERENCES Suppliers(SupplierID)
	CONSTRAINT pk_PartSuppliers PRIMARY KEY (PartID, SupplierID)
);


CREATE TABLE Inventory (
    InventoryID INT PRIMARY KEY,
    PartID INT,
    SupplierID INT,
    Quantity INT CHECK (Quantity >= 0),
    Price DECIMAL(10, 2) CHECK (Price >= 0.00),
    FOREIGN KEY (PartID) REFERENCES CarParts(PartID),
    FOREIGN KEY (SupplierID) REFERENCES Suppliers(SupplierID)
);
