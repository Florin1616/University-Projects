
	USE CarPartsShop

	----------------------------------
	-- a) modify the type of a column 
	USE CarPartsShop
	----------------------------------
	GO
	CREATE OR ALTER PROCEDURE ModifyColumnType
	AS
		ALTER TABLE CarParts
		ALTER COLUMN PartName NVARCHAR(255);


	GO
	CREATE OR ALTER PROCEDURE RevertModifyColumnType
	AS
		ALTER TABLE CarParts
		ALTER COLUMN PartName VARCHAR(255);
	
	EXEC ModifyColumnType
	EXEC RevertModifyColumnType

	----------------------------
	-- b) add / remove a column 
	----------------------------
	GO
	CREATE OR ALTER PROCEDURE AddColumn
	AS
		ALTER TABLE CarParts
		ADD NewColumn INT;


	GO
	CREATE OR ALTER PROCEDURE RevertAddColumn
	AS
		ALTER TABLE CarParts
		DROP COLUMN NewColumn;

	EXEC AddColumn
	EXEC RevertAddColumn



	--------------------------------------
	-- c) add/remove a DEFAULT constraint
	--------------------------------------
	GO
	CREATE OR ALTER PROCEDURE AddDefaultConstraint
	AS
		ALTER TABLE Customer
		ADD CONSTRAINT DF_ContactInfo DEFAULT 'No Contact Info' FOR ContactInfo;

	GO
	CREATE OR ALTER PROCEDURE RevertAddDefaultConstraint
	AS
		ALTER TABLE Customer
		DROP CONSTRAINT DF_ContactInfo;


	EXEC AddDefaultConstraint
	EXEC RevertAddDefaultConstraint



	---------------------------------
	-- d) add / remove a primary key
	---------------------------------
	GO
	CREATE OR ALTER PROCEDURE AddPrimaryKey
	AS
	ALTER TABLE Employee
		DROP CONSTRAINT if exists EMPLOYEE_PRIMARY_KEY
	ALTER TABLE Employee
		ADD CONSTRAINT EMPLOYEE_PRIMARY_KEY PRIMARY KEY(first_name, salary)


	GO
	CREATE OR ALTER PROCEDURE RevertAddPrimaryKey
	AS
		ALTER TABLE Employee
		DROP CONSTRAINT EMPLOYEE_PRIMARY_KEY
	ALTER TABLE Employee
		ADD CONSTRAINT EMPLOYEE_PRIMARY_KEY PRIMARY KEY(employee_id)

	EXEC AddPrimaryKey
	EXEC RevertAddPrimaryKey

	-----------------------------------
	-- e) add / remove a candidate key
	-----------------------------------

	GO 
	CREATE OR ALTER PROCEDURE AddCandidateKey
	AS
		ALTER TABLE OrderItems
		ADD CONSTRAINT ORDER_ITEMS_CK UNIQUE (OrderItemID, OrderID, PartID);

	GO
	CREATE OR ALTER PROCEDURE RevertAddCandidateKey
	AS
		ALTER TABLE OrderItems
		DROP CONSTRAINT ORDER_ITEMS_CK;


	EXEC AddCandidateKey
	EXEC RevertAddCandidateKey


	---------------------------------
	-- f) add / remove a foreign key
	---------------------------------

	GO
	CREATE OR ALTER PROCEDURE AddForeignKey
	AS
		ALTER TABLE Inventory
		ADD CONSTRAINT FK_Inventory_CarModels_Part FOREIGN KEY (ModelId) REFERENCES CarModels(ModelID);

	GO
	CREATE OR ALTER PROCEDURE RevertAddForeignKey
	AS
		ALTER TABLE Inventory
		DROP CONSTRAINT FK_Inventory_CarModels_Part;

	EXEC AddForeignKey
	EXEC RevertAddForeignKey


	----------------------------
	-- g) create / drop a table
	----------------------------
	GO
	CREATE OR ALTER PROCEDURE CreateTable
	AS
		CREATE TABLE CustomerFeedback (
			FeedbackID INT PRIMARY KEY,
			CustomerID INT FOREIGN KEY REFERENCES Customer(CustomerID),
			FeedbackText VARCHAR(255) NOT NULL,
			FeedbackDate DATE
		);

	GO
	CREATE OR ALTER PROCEDURE RevertCreateTable
	AS
		DROP TABLE if exists CustomerFeedback




EXEC CreateTable

	/*
		a table that contains the current version of the database schema
	*/
	CREATE TABLE versionTable (
		version INT
	)

	INSERT INTO versionTable 
	VALUES
		(1) -- this is the initial version

	-- a table that contains the initial version, the version after the execution of the procedure 
	-- and the procedure that changes the table in this way
	CREATE TABLE procedureTable (
		initial_version INT,
		final_version INT,
		procedure_name VARCHAR(MAX),
		PRIMARY KEY (initial_version, final_version)
	)

	INSERT INTO procedureTable
	VALUES
		(1, 2, 'ModifyColumnType'),
		(2, 1, 'RevertModifyColumnType'),
		(2, 3, 'AddColumn'), 
		(3, 2, 'RevertAddColumn'),
		(3, 4, 'AddDefaultConstraint'),
		(4, 3, 'RevertAddDefaultConstraint'),
		(4, 5, 'AddPrimaryKey'),
		(5, 4, 'RevertAddPrimaryKey'),
		(5, 6, 'AddCandidateKey'),
		(6, 5, 'RevertAddCandidateKey'),
		(6, 7, 'AddForeignKey'),
		(7, 6, 'RevertAddForeignKey'),
		(7, 8, 'CreateTable'),
		(8, 7, 'RevertCreateTable')


	-- procedure to bring the database to the specified version
	GO
	CREATE OR ALTER PROCEDURE goToVersion(@newVersion INT) 
	AS
		DECLARE @curr INT
		DECLARE @var VARCHAR(MAX)
		SELECT @curr = version
		FROM versionTable

		IF @newVersion > (SELECT MAX(final_version)
						  FROM procedureTable)
			raiserror ('BAD VERSION', 10, 1)

		IF @newVersion < (SELECT MIN(final_version)
						  FROM procedureTable)
			raiserror ('BAD VERSION', 10, 1)

		WHILE @curr > @newVersion
			BEGIN
				SELECT @var=procedure_name FROM procedureTable WHERE initial_version=@curr AND final_version=@curr - 1
				EXEC (@var)
				SET @curr = @curr - 1
			END

		WHILE @curr < @newVersion
			BEGIN
				SELECT @var=procedure_name FROM procedureTable WHERE initial_version=@curr AND final_version=@curr + 1
				EXEC (@var)
				SET @curr = @curr + 1
			END

		UPDATE versionTable SET version = @newVersion

	EXEC RevertAddColumn
	EXEC RevertAddForeignKey

	EXEC goToVersion 1

	SELECT *
	FROM versionTable

	SELECT *
	FROM procedureTable