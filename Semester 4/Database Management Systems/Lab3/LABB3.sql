use CarPartsShoppp


CREATE TABLE LogTable(
Lid INT IDENTITY PRIMARY KEY,
TypeOperation VARCHAR(50),
TableOperation VARCHAR(50),
ExecutionDate DATETIME)

select * from LogTable

CREATE FUNCTION validate_dealership_name (@name VARCHAR(255))
RETURNS BIT
AS
BEGIN
    DECLARE @return BIT;
    SET @return = 0;

    IF LEN(@name) > 0 AND LEN(@name) <= 255
        SET @return = 1;

    RETURN @return;
END;


CREATE FUNCTION validate_dealership_address (@address VARCHAR(255))
RETURNS BIT
AS
BEGIN
    DECLARE @return BIT;
    SET @return = 0;

    IF @address IN ('Brasov', 'Cluj', 'Bucuresti')
	            SET @return = 1;

    RETURN @return;
END;





CREATE FUNCTION validate_car_make_name (@name VARCHAR(255))
RETURNS BIT
AS
BEGIN
    DECLARE @return BIT;
    SET @return = 0;

    IF LEN(@name) > 0 AND LEN(@name) <= 255
        SET @return = 1;

    RETURN @return;
END;


CREATE FUNCTION validate_country (@country VARCHAR(100))
RETURNS BIT
AS
BEGIN
    DECLARE @return BIT;
    SET @return = 0;

    IF @country IN ('USA', 'Germany', 'Japan', 'Italy', 'France') 
        SET @return = 1

    RETURN @return;
END;



CREATE FUNCTION validate_founded_year (@year INT)
RETURNS BIT
AS
BEGIN
    DECLARE @return BIT;
    SET @return = 0;

    DECLARE @current_year INT = YEAR(GETDATE());

    IF @year <= @current_year
        SET @return = 1;

    RETURN @return;
END;


drop procedure AddCarMakeAndDealership
CREATE PROCEDURE AddCarMakeAndDealership 
    @carMakeName VARCHAR(255), 
    @country VARCHAR(100), 
    @foundedYear INT, 
    @dealershipName VARCHAR(255), 
    @dealershipAddress VARCHAR(255) 
AS
BEGIN
    BEGIN TRANSACTION;
    BEGIN TRY
        IF dbo.validate_car_make_name(@carMakeName) <> 1
        BEGIN 
            RAISERROR('Car make name is invalid.', 14, 1);
        END;

        IF dbo.validate_country(@country) <> 1
        BEGIN 
            RAISERROR('Country is invalid.', 14, 1);
        END;

        IF dbo.validate_founded_year(@foundedYear) <> 1
        BEGIN 
            RAISERROR('Founded year is invalid.', 14, 1);
        END;

        DECLARE @carMakeID INT;

        INSERT INTO CarMakes (CarMakeName, Country, FoundedYear)
        VALUES (@carMakeName, @country, @foundedYear);

        SET @carMakeID = SCOPE_IDENTITY();

        DECLARE @dealershipID INT;

        INSERT INTO Dealerships (DealershipName, DealershipAddress)
        VALUES (@dealershipName, @dealershipAddress);

        SET @dealershipID = SCOPE_IDENTITY();

        DECLARE @carMakeDealershipID INT;

        INSERT INTO CarMakeDealership (CarMakeID, DealershipID)
        VALUES (@carMakeID, @dealershipID);

        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('Insert', 'CarMakes, Dealerships, CarMakeDealership', GETDATE());

        COMMIT TRANSACTION;
        SELECT 'Transaction committed';
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('Insert Error', 'CarMakes, Dealerships, CarMakeDealership: ' + ERROR_MESSAGE(), GETDATE());

        SELECT 'Transaction rolled back';
    END CATCH;
END;




--bad example
EXEC AddCarMakeAndDealership 
@carMakeName = 'Toyota',
@country = 'USA',
@foundedYear = 2028,
@dealershipName = 'Motors',
@dealershipAddress = 'Cocorului';

--good example
EXEC AddCarMakeAndDealership 
@carMakeName = 'BMW',
@country = 'USA',
@foundedYear = 2020,
@dealershipName = 'Tiriac Auto',
@dealershipAddress = 'Bucuresti';


-- Check the LogTable and other tables to verify the output
SELECT * FROM LogTable;
SELECT * FROM CarMakes;
SELECT * FROM Dealerships;
SELECT * FROM CarMakeDealership;







drop procedure AddCarMakeAndDealership_SEPARATE
CREATE OR ALTER PROCEDURE AddCarMakeAndDealership_SEPARATE
    @carMakeName VARCHAR(255), 
    @country VARCHAR(100), 
    @foundedYear INT, 
    @dealershipName VARCHAR(255), 
    @dealershipAddress VARCHAR(255)
AS
BEGIN
    DECLARE @LastCarMakeID INT = -1;
    DECLARE @LastDealershipID INT = -1;

    BEGIN TRY
        BEGIN TRANSACTION;
            IF dbo.validate_car_make_name(@carMakeName) <> 1 
                OR dbo.validate_country(@country) <> 1 
                OR dbo.validate_founded_year(@foundedYear) <> 1
            BEGIN
                RAISERROR('Validation failed for car make details!', 16, 1);
            END

            INSERT INTO CarMakes (CarMakeName, Country, FoundedYear) 
            VALUES (@carMakeName, @country, @foundedYear);

            SET @LastCarMakeID = SCOPE_IDENTITY();
            COMMIT TRANSACTION;

            INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
            VALUES ('Insert', 'CarMakes', GETDATE());
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT ERROR', 'CarMakes: ' + ERROR_MESSAGE(), GETDATE());
    END CATCH;

    BEGIN TRY
        BEGIN TRANSACTION;
            IF dbo.validate_dealership_name(@dealershipName) <> 1 
                OR dbo.validate_dealership_address(@dealershipAddress) <> 1
            BEGIN
                RAISERROR('Validation failed for dealership details!', 16, 1);
            END

            INSERT INTO Dealerships (DealershipName, DealershipAddress) 
            VALUES (@dealershipName, @dealershipAddress);

            SET @LastDealershipID = SCOPE_IDENTITY();
            COMMIT TRANSACTION;

            INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
            VALUES ('Insert', 'Dealerships', GETDATE());
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT ERROR', 'Dealerships: ' + ERROR_MESSAGE(), GETDATE());
    END CATCH;

    BEGIN TRY
        BEGIN TRANSACTION;
            IF @LastCarMakeID = -1 OR @LastDealershipID = -1
            BEGIN
                RAISERROR('Failed to obtain IDs for car make or dealership!', 16, 1);
            END

            INSERT INTO CarMakeDealership (CarMakeID, DealershipID) 
            VALUES (@LastCarMakeID, @LastDealershipID);

            COMMIT TRANSACTION;

            INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
            VALUES ('Insert', 'CarMakeDealership', GETDATE());
    END TRY
    BEGIN CATCH
        ROLLBACK TRANSACTION;
        INSERT INTO LogTable (TypeOperation, TableOperation, ExecutionDate)
        VALUES ('INSERT ERROR', 'CarMakeDealership: ' + ERROR_MESSAGE(), GETDATE());
    END CATCH;
END;



EXEC AddCarMakeAndDealership_SEPARATE 
    @carMakeName = 'Aston Martin', 
    @country = 'USA', 
    @foundedYear = 2026, 
    @dealershipName = 'BMW', 
    @dealershipAddress = 'Brasov';


EXEC AddCarMakeAndDealership_SEPARATE 
    @carMakeName = 'Peugeot', 
    @country = 'Italy', 
    @foundedYear = 2023, 
    @dealershipName = 'Opel', 
    @dealershipAddress = 'Brasov';




SELECT * FROM CarMakes;
SELECT * FROM Dealerships;
SELECT * FROM CarMakeDealership;
SELECT * FROM LogTable;








-- 1) Dirty Reads

-- Part 1
SELECT * FROM CarMakes;

INSERT INTO CarMakes (CarMakeName, Country, FoundedYear) VALUES ('Test Car Make', 'Test Country', 2024);

-- Dirty read part 1
BEGIN TRANSACTION;
UPDATE CarMakes SET CarMakeName = 'Bad Car Make Name'
WHERE CarMakeID = 4;
WAITFOR DELAY '00:00:10';
ROLLBACK TRANSACTION;


SELECT * FROM CarMakes

DELETE CarMakes WHERE FoundedYear = 2020

-- 2) Non-Repeatable Reads

-- Part 1
INSERT INTO CarMakes (CarMakeName, Country, FoundedYear) VALUES ('Test Car Make Non-Repeatable', 'Test Country', 2024);

BEGIN TRANSACTION;
WAITFOR DELAY '00:00:05';
UPDATE CarMakes SET FoundedYear = 2000 WHERE CarMakeName = 'Test Car Make Non-Repeatable';
COMMIT TRANSACTION;

DELETE FROM CarMakes WHERE CarMakeName = 'Test Car Make Non-Repeatable';


---3) Phantom Reads

-- Part 1
BEGIN TRANSACTION;
WAITFOR DELAY '00:00:04';
INSERT INTO CarMakes (CarMakeName, Country, FoundedYear) VALUES ('Test Car Make Phantom', 'Test Country', 2024);
COMMIT TRANSACTION;

DELETE FROM CarMakes WHERE CarMakeName = 'Test Car Make Phantom';







-- 4) Deadlock

-- Part 1
SELECT * FROM CarMakes;
SELECT * FROM Dealerships;

INSERT INTO Dealerships (DealershipName, DealershipAddress) VALUES ('Test Dealership', 'Test Address');
INSERT INTO CarMakes (CarMakeName, Country, FoundedYear) VALUES ('Test Car Make DEADLOCK', 'Test Country', 2024);

BEGIN TRANSACTION;
UPDATE CarMakes SET CarMakeName = 'TEST CAR MAKE TRANSACTION 1' WHERE CarMakeID = 1;
WAITFOR DELAY '00:00:10';
UPDATE Dealerships SET DealershipName = 'TEST DEALERSHIP TRANSACTION 1' WHERE DealershipID = 1;
COMMIT TRANSACTION;

DELETE FROM Dealerships WHERE DealershipID = 1;
DELETE FROM CarMakes WHERE CarMakeID = 1;





