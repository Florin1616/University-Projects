GO
USE CarPartsShop
GO 

CREATE TABLE Tables (
	Name VARCHAR(50)
)

INSERT INTO Tables VALUES
('Suppliers'),('CarParts'),('PartSuppliers')
GO

CREATE VIEW view_suppliers
AS
SELECT SupplierID, SupplierName, ContactInfo
FROM Suppliers
GO


CREATE VIEW view_suppliers_partid
AS
SELECT S.SupplierID, S.SupplierName, P.PartID
FROM Suppliers S
INNER JOIN PartSuppliers P on S.SupplierID = P.SupplierID
GO


CREATE VIEW view_partsuplliers_carparts
AS
SELECT C.CarPartsCategoryID, C.PartName, P.PartID
FROM CarParts C
INNER JOIN PartSuppliers P ON P.PartID = C.PartID
GROUP BY P.PartID, C.CarPartsCategoryID, C.PartName
GO

CREATE TABLE Views (
	Name VARCHAR(50)
)

INSERT INTO Views VALUES
('view_suppliers'), ('view_suppliers_partid'), ('view_partsuplliers_carparts')

CREATE TABLE Tests (
	Name VARCHAR(50)
)

insert into Tests values
('INSERT1'),('INSERT2'),('INSERT3'),('DELETE1'),('DELETE2'),('DELETE3'),('SELECT1'),
('SELECT2'),('SELECT3')

CREATE TABLE TestViews (
	TestID INT,
	ViewID INT,
)

INSERT INTO TestViews VALUES
(7, 1),
(8, 2),
(9, 3);

CREATE TABLE TestTables (
	TestID INT,
	TableID INT,
	NoOfRows INT,
	Position INT,
)

INSERT INTO TestTables VALUES
(1, 1, 100, 1),
(2, 2, 100, 2),
(3, 3, 100, 3),
(6, 3, 100, 1),
(5, 2, 100, 2),
(4, 1, 100, 3)
GO


create or alter procedure INSERT1
AS
BEGIN
	DECLARE @NoOFRows int
	DECLARE @n int
	DECLARE @SupplierID int
	DECLARE @SupplierName VARCHAR(255)
	DECLARE @ContactInfo VARCHAR(255)
	SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables WHERE TableID = 1 AND Position = 1
	SET @n=9
	WHILE @n<=@NoOfRows + 8
		BEGIN
		SET @SupplierID = @n
		SET @SupplierName = 'Marcel' + CONVERT(VARCHAR(5),@n)
		SET @ContactInfo = 'Email Marcel' + CONVERT(VARCHAR(5),@n)
		INSERT INTO Suppliers(SupplierID,SupplierName,ContactInfo) VALUES (@SupplierID,@SupplierName,@ContactInfo);
		SET @n=@n+1
		END
END;
GO


create or alter procedure INSERT2
AS
BEGIN
	DECLARE @NoOFRows int
	DECLARE @n int
	DECLARE @PartID int
	DECLARE @PartName VARCHAR(255)
	DECLARE @CarPartsCategoryID int
	DECLARE @ModelID int 
	DECLARE @ManufacturerID int 
	SELECT TOP 1 @NoOfRows = NoOfRows FROM dbo.TestTables WHERE TableID = 2 AND Position = 2
	SET @n=6
	WHILE @n<=@NoOfRows +5
		BEGIN
		SET @PartID = @n
		SET @PartName = 'PartName' +CONVERT(VARCHAR(5),@n)
		SELECT @CarPartsCategoryID = MIN(C.CarPartsCategoryID) FROM CarParts C 
		SELECT @ModelID = MIN(C.ModelID) FROM CarModels C 
		SELECT @ManufacturerID = MIN(C.ManufacturerID) FROM CarPartsManufacturers C
		INSERT INTO CarParts(PartID,PartName,CarPartsCategoryID,ModelID,ManufacturerID) 
		VALUES (@PartID,@PartName,@CarPartsCategoryID,@ModelID,@ManufacturerID)
		SET @n=@n+1
		END
END;
GO


create or alter procedure INSERT3
AS
BEGIN
	DECLARE @NoOfRows int
	DECLARE @n int
	DECLARE @PartID int
	DECLARE @SupplierID int
	
	SELECT TOP 1 @NoOFRows = NoOfRows FROM dbo.TestTables WHERE TableID = 3 AND Position = 3
	SET @n = 6
	SET @PartID = 6
	SET @SupplierID = 9
	
	WHILE @n <= @NoOFRows + 5
	BEGIN
		INSERT INTO PartSuppliers(PartID,SupplierID) VALUES (@PartID,@SupplierID)
		SET @PartID=@PartID+1
		SET @SupplierID=@SupplierID+1
		SET @n=@n+1
		END
END;
GO

CREATE OR ALTER PROCEDURE SELECT1
AS
BEGIN
SELECT * FROM view_suppliers
END;
GO

CREATE OR ALTER PROCEDURE SELECT2
AS
BEGIN
SELECT * FROM view_suppliers_partid
END;
GO

CREATE OR ALTER PROCEDURE SELECT3
AS
BEGIN
SELECT * FROM view_partsuplliers_carparts
END;
GO




create or alter procedure DELETE3
as
begin
DECLARE @nr int
SELECT TOP 1 @nr = NoOfRows FROM dbo.TestTables WHERE TestID = 6 AND Position = 1
delete from PartSuppliers
where PartID in (select top (@nr) PartID from PartSuppliers order by PartID desc)
end;
go

create or alter procedure DELETE2
as
begin
DECLARE @nr int
SELECT TOP 1 @nr = NoOfRows FROM dbo.TestTables WHERE TestID = 5 AND Position = 2
delete from CarParts
where PartID in (select top (@nr) PartID from CarParts order by PartID desc)
end;
go

create or alter procedure DELETE1
as
begin
DECLARE @nr int
SELECT TOP 1 @nr = NoOfRows FROM dbo.TestTables WHERE TestID = 4 AND Position = 3
delete from Suppliers
where SupplierID in (select top (@nr) SupplierID from Suppliers order by SupplierID desc)
end;
go

USE CarPartsShop

--testarea procedurilor
SELECT * FROM Suppliers
SELECT * FROM CarParts
SELECT * FROM PartSuppliers

EXEC INSERT1
EXEC INSERT2
EXEC INSERT3

EXEC DELETE3
EXEC DELETE2
EXEC DELETE1
GO


CREATE TABLE [TestRunTables] (
	[TestRunID] [int] NOT NULL ,
	[TableID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRunViews] (
	[TestRunID] [int] NOT NULL ,
	[ViewID] [int] NOT NULL ,
	[StartAt] [datetime] NOT NULL ,
	[EndAt] [datetime] NOT NULL 
) ON [PRIMARY]
GO

CREATE TABLE [TestRuns] (
	[TestRunID] [int] IDENTITY (1, 1) NOT NULL ,
	[Description] [nvarchar] (2000) COLLATE SQL_Latin1_General_CP1_CI_AS NULL ,
	[StartAt] [datetime] NULL ,
	[EndAt] [datetime] NULL 
) ON [PRIMARY]
GO



create or alter procedure run @id int
as
begin

 IF (@id NOT IN (1, 2, 3))
BEGIN
		RAISERROR('PARAMETRUL POATE FI DOAR 1 2 SAU 3!',16,1)
		RETURN 1
END

DECLARE @nume_procedura VARCHAR(50)
DECLARE @ds DATETIME  --ds=data start
DECLARE @di DATETIME  --di=data intermediara
DECLARE @de DATETIME  --df=data finala
SET @ds = GETDATE()
-- insert into table
IF @id = 3
BEGIN
        SET @nume_procedura = 'INSERT1';
        EXEC @nume_procedura;

        SET @nume_procedura = 'INSERT2';
        EXEC @nume_procedura;
END
 SET @nume_procedura='INSERT'+CONVERT(VARCHAR, @id)
 EXEC @nume_procedura
-- delete from table
 SET @nume_procedura='DELETE'+CONVERT(VARCHAR, @id)
 EXEC @nume_procedura
SET @di=GETDATE()
-- evaluate (select from) view
 SET @nume_procedura='SELECT'+CONVERT(VARCHAR, @id)
 EXEC @nume_procedura
SET @de=GETDATE()

IF @id = 3
BEGIN
        SET @nume_procedura = 'DELETE1';
        EXEC @nume_procedura;

        SET @nume_procedura = 'DELETE2';
        EXEC @nume_procedura;
END


INSERT INTO TestRuns VALUES ('INSERT+DELETE+SELECT', @ds, @de); 
DECLARE @TEST_RUN_ID int =
		(select top 1 TestRunID from TestRuns order by TestRunID desc);
INSERT INTO TestRunTables VALUES (@TEST_RUN_ID,@id,@ds,@di);
INSERT INTO TestRunViews VALUES (@TEST_RUN_ID,@id,@di,@de);
end;
go

exec run 3

SELECT * FROM TestRuns
SELECT * FROM TestRunTables
SELECT * FROM TestRunViews

USE CarPartsShop