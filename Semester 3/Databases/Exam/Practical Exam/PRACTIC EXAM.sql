create database EXAMMM

use EXAMMM


CREATE TABLE Categories(
    CategoryID INT PRIMARY KEY,
    CategoryName VARCHAR(255) UNIQUE,
    CategoryDescription VARCHAR(255)
);

CREATE TABLE CareHistory(
    CareHistoryID INT PRIMARY KEY,
    CareDate DATE,
    CareTime TIME,
    CareActivity VARCHAR(255)
);

CREATE TABLE Locations(
    LocationsID INT PRIMARY KEY,
    LocationName VARCHAR(255) UNIQUE,
    LocationDescription VARCHAR(255)
);

CREATE TABLE Plants(
    PlantID INT PRIMARY KEY,
    PlantName VARCHAR(255) UNIQUE,
    PlantDescription VARCHAR(255),
    AcquisitionDate DATE,
    LastWateredDate DATE,
    LocationID INT,
    FOREIGN KEY (LocationID) REFERENCES Locations(LocationsID)
);

CREATE TABLE Images(
    ImageID INT PRIMARY KEY,
    ImagePath VARCHAR(255),
    ImageCaption VARCHAR(255),
    UploadDate DATE,
    PlantID INT,
    FOREIGN KEY (PlantID) REFERENCES Plants(PlantID)
);

CREATE TABLE PlantsCategories(
    PlantID INT,
    CategoryID INT,
    CONSTRAINT pk_PlantsCategories PRIMARY KEY (PlantID, CategoryID),
    FOREIGN KEY (PlantID) REFERENCES Plants(PlantID),
    FOREIGN KEY (CategoryID) REFERENCES Categories(CategoryID)
);

INSERT INTO Locations (LocationsID, LocationName, LocationDescription)
VALUES (1,'Brasov', 
INSERT INTO Plants (PlantID, PlantName, PlantDescription, AcquisitionDate, LastWateredDate, LocationID)
VALUES (1, 'Ficus', 'Frumoasa', '10-11-2024', @LastWateredDate, @LocationID);

CREATE VIEW LocationPlantSummary AS
SELECT 
    L.LocationsID,
    L.LocationName,
    COUNT(P.PlantID) AS TotalPlants,
    MAX(P.AcquisitionDate) AS LatestAcquisitionDate
FROM 
    Locations L
LEFT JOIN 
    Plants P ON L.LocationsID = P.LocationID
GROUP BY 
    L.LocationsID, L.LocationName;

SELECT * FROM LocationPlantSummary;


CREATE FUNCTION GetRecentCaredPlantWithMinImages(@X INT)
RETURNS INT
AS
BEGIN
    DECLARE @recentCaredPlantID INT;

    SELECT TOP 1 @recentCaredPlantID = P.PlantID
    FROM Plants P
    JOIN Images I ON P.PlantID = I.PlantID
    LEFT JOIN CareHistory CH ON P.PlantID = CH.CareHistoryID
    GROUP BY P.PlantID
    HAVING COUNT(I.ImageID) >= @X
    ORDER BY MAX(CH.CareDate) DESC;

    RETURN @recentCaredPlantID;
END;


SELECT dbo.GetRecentCaredPlantWithMinImages(3);



CREATE PROCEDURE AddOrUpdatePlant
    @PlantID INT,
    @PlantName VARCHAR(255),
    @PlantDescription VARCHAR(255),
    @AcquisitionDate DATE,
    @LastWateredDate DATE,
    @LocationID INT
AS
BEGIN
    IF EXISTS (SELECT 1 FROM Plants WHERE PlantName = @PlantName)
    BEGIN
        UPDATE Plants
        SET AcquisitionDate = @AcquisitionDate
        WHERE PlantName = @PlantName;
    END
    ELSE
    BEGIN
        INSERT INTO Plants (PlantID, PlantName, PlantDescription, AcquisitionDate, LastWateredDate, LocationID)
        VALUES (@PlantID, @PlantName, @PlantDescription, @AcquisitionDate, @LastWateredDate, @LocationID);
    END
END;



EXEC AddOrUpdatePlant 
    @PlantID = 1, 
    @PlantName = 'Aloe Vera', 
    @PlantDescription = 'A succulent plant species', 
    @AcquisitionDate = '2024-01-16', 
    @LastWateredDate = '2024-01-15', 
    @LocationID = 2;


