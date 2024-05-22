use CarPartsShoppp


-- Dirty read part 2
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
BEGIN TRAN;
SELECT * FROM CarMakes;
WAITFOR DELAY '00:00:15';
SELECT * FROM CarMakes;
COMMIT TRAN;

-- Solution
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRAN;
SELECT * FROM CarMakes;
WAITFOR DELAY '00:00:15';
SELECT * FROM CarMakes;
COMMIT TRAN;



-- Non-repeatable read part 2
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRAN;
SELECT * FROM CarMakes;
WAITFOR DELAY '00:00:05';
SELECT * FROM CarMakes;
COMMIT TRAN;

-- Solution
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRAN;
SELECT * FROM CarMakes;
WAITFOR DELAY '00:00:05';
SELECT * FROM CarMakes;
COMMIT TRAN;



-- Phantom read part 2
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRAN;
SELECT * FROM CarMakes;
WAITFOR DELAY '00:00:05';
SELECT * FROM CarMakes;
COMMIT TRAN;

-- Solution
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRAN;
SELECT * FROM CarMakes;
WAITFOR DELAY '00:00:05';
SELECT * FROM CarMakes;
COMMIT TRAN;



-- Deadlock part 2
BEGIN TRANSACTION;
UPDATE Dealerships SET DealershipName = 'TEST DEALERSHIP TRANSACTION 2' WHERE DealershipID = 1;
WAITFOR DELAY '00:00:10';
UPDATE CarMakes SET CarMakeName = 'TEST CAR MAKE TRANSACTION 2' WHERE CarMakeID = 1;
COMMIT TRANSACTION;

-- Solution
SET DEADLOCK_PRIORITY HIGH;
BEGIN TRANSACTION;
UPDATE Dealerships SET DealershipName = 'TEST DEALERSHIP TRANSACTION 2' WHERE DealershipID = 1;
WAITFOR DELAY '00:00:10';
UPDATE CarMakes SET CarMakeName = 'TEST CAR MAKE TRANSACTION 2' WHERE CarMakeID = 1;
COMMIT TRANSACTION;


