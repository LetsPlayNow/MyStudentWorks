ALTER PROC BooksNamesByPublishHouse @PublishHouseName AS VARCHAR(20)
AS
	SELECT Books.Title_book, Publishing_house.Publish
	FROM Books
	JOIN Publishing_house ON Publishing_house.Code_publish = Books.Code_publish
	WHERE Publishing_house.Publish = @PublishHouseName
GO