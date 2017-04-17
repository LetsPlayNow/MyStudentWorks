ALTER PROC DeliveriesForCompany @CompanyNameFormat AS VARCHAR(20)
AS
	SELECT Name_company, Phone, INN
	FROM Deliveries
	WHERE Name_company LIKE @CompanyNameFormat
GO