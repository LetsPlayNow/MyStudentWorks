SELECT Books.Title_book, Publishing_house.Publish
FROM Books
JOIN Publishing_house ON Publishing_house.Code_publish = Books.Code_publish
WHERE Publishing_house.Publish IN ('Малыш', 'Альфа', 'Наука')