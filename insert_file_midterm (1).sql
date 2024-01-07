delete from category_dishes;
delete from dishes_ingridient;
delete from dishes_origins;
delete from category;
delete from dishes;
delete from ingridient;
delete from origins;

INSERT INTO category (ID, category_name) VALUES (1, 'Appetizers'), (2, 'Main Dishes'), (3, 'Desserts'), (4, 'Beverages'), (5, 'Salads'), (6, 'Soup'), (7, 'Seafood'), (8, 'Vegetarian');
INSERT INTO dishes (ID, dishes_name, price, available_time, end_time) VALUES 
(1, 'Mango Avocado Salsa', 9.99, 0, 24), (2, 'Caprese Skewers', 11.99, 10, 22),
(3, 'Shrimp Spring Rolls', 13.99, 11, 20), (4, 'Grilled Salmon with Lemon Dill Sauce', 19.99, 17, 23), 
(5, 'Pasta Carbonara', 16.99, 0, 24), (6, 'Margherita Pizza', 14.99, 10, 22), (7, 'Chocolate Mousse', 8.99, 0, 24),
(8, 'Tiramisu', 10.99, 0, 24), (9, 'Fruit Tart', 12.99, 8, 20), (10, 'Mango Lassi', 4.99, 0, 24), 
(11, 'Iced Coffee', 3.99, 0, 24), (12, 'Green Tea Mojito', 5.99, 10, 20), (13, 'Caesar Salad', 7.99, 8, 20), 
(14, 'Greek Salad', 8.99, 14, 20), (15, 'Caprese Salad', 9.99, 0, 24), (16, 'Tom Yum Soup', 12.99, 10, 20), 
(17, 'French Onion Soup', 14.99, 0, 24), (18, 'Tortilla Soup', 11.99, 16, 22), (19, 'Grilled Shrimp Skewers', 22.99, 10, 20), 
(20, 'Paella', 29.99, 0, 24), (21, 'Moroccan Spiced Salmon', 26.99, 11, 21), (22, 'Vegetable Biryani', 18.99, 0, 24), 
(23, 'Vegetarian Tacos', 15.99, 10, 22), (24, 'Falafel Wrap', 12.99, 0, 24);
INSERT INTO ingridient (ID, ingridient_name, quantity, quantity_unit, import_date, expired_date) VALUES 
(1, 'Mango', 100, 'grams', '2023-01-01', '2023-02-01'), (2, 'Avocado', 1, 'pieces', '2023-01-05', '2023-02-15'), 
(3, 'Cilantro', 50, 'grams', '2023-01-10', '2023-03-01'), (4, 'Tomato', 500, 'grams', '2023-01-01', '2023-02-01'),
(5, 'Mozzarella', 200, 'grams', '2023-01-05', '2023-02-15'), (6, 'Basil', 1, 'bunch', '2023-01-10', '2023-03-01'),
(7, 'Shrimp', 200, 'grams', '2023-01-01', '2023-02-01'), (8, 'Rice Paper', 10, 'sheets', '2023-01-05', '2023-02-15'),
(9, 'Lettuce', 2, 'heads', '2023-01-10', '2023-03-01'),(10, 'Salmon Fillet', 250, 'grams', '2023-01-01', '2023-02-01'),
(11, 'Heavy Cream', 150, 'milliliters', '2023-01-05', '2023-02-15'), (12, 'Lemon', 1, 'pieces', '2023-01-10', '2023-03-01'),
(13, 'Spaghetti', 300, 'grams', '2023-01-01', '2023-02-01'), (14, 'Pancetta', 100, 'grams', '2023-01-05', '2023-02-15'),
(15, 'Parmesan Cheese', 50, 'grams', '2023-01-10', '2023-03-01'), (16, 'Pizza Dough', 1, 'portion', '2023-01-01', '2023-02-01'),
(17, 'Tomato Sauce', 200, 'milliliters', '2023-01-05', '2023-02-15'), (18, 'Fresh Mozzarella', 150, 'grams', '2023-01-10', '2023-03-01'),
(19, 'Chocolate', 150, 'grams', '2023-01-01', '2023-02-01'), (20, 'Espresso', 50, 'milliliters', '2023-01-05', '2023-02-15'),
(21, 'Whipped Cream', 100, 'grams', '2023-01-10', '2023-03-01'), (22, 'Ladyfingers', 200, 'grams', '2023-01-01', '2023-02-01'),
(23, 'Mascarpone Cheese', 250, 'grams', '2023-01-05', '2023-02-15'), (24, 'Cocoa Powder', 20, 'grams', '2023-01-10', '2023-03-01'),
(25, 'Shortcrust Pastry', 1, 'portion', '2023-01-01', '2023-02-01'), (26, 'Mixed Fruits', 300, 'grams', '2023-01-05', '2023-02-15'),
(27, 'Pastry Cream', 150, 'grams', '2023-01-10', '2023-03-01'), (46, 'Mango Juice', 200, 'milliliters', '2023-01-01', '2023-02-01'),
(48, 'Mint Leaves', 10, 'pieces', '2023-01-10', '2023-03-01'),(49, 'Lemon Juice', 20, 'milliliters', '2023-01-01', '2023-02-01'), (50, 'Cold Brew Coffee', 250, 'milliliters', '2023-01-05', '2023-02-15'),
(51, 'Simple Syrup', 15, 'milliliters', '2023-01-10', '2023-03-01'), (52, 'Green Tea Bags', 2, 'pieces', '2023-01-01', '2023-02-01'),
(53, 'Soda Water', 150, 'milliliters', '2023-01-05', '2023-02-15'), (54, 'Cucumber Slices', 5, 'pieces', '2023-01-10', '2023-03-01'), (55, 'Romaine Lettuce', 150, 'grams', '2023-01-01', '2023-02-01'), (56, 'Chicken Breast', 200, 'grams', '2023-01-05', '2023-02-15'), (57, 'Croutons', 50, 'grams', '2023-01-10', '2023-03-01'), 
(59, 'Kalamata Olives', 50, 'grams', '2023-01-05', '2023-02-15'), 
(60, 'Feta Cheese', 100, 'grams', '2023-01-10', '2023-03-01'),
(63, 'Mozzarella Balls', 100, 'grams', '2023-01-10', '2023-03-01'), 
(64, 'Galangal', 30, 'grams', '2023-01-05', '2023-02-15'), (65, 'Lemongrass', 2, 'stalks', '2023-01-10', '2023-03-01'), 
(66, 'Kaffir Lime Leaves', 5, 'leaves', '2023-01-01', '2023-02-01'), (67, 'Gruyere Cheese', 100, 'grams', '2023-01-05', '2023-02-15'), 
(68, 'Baguette', 1, 'piece', '2023-01-10', '2023-03-01'), (69, 'White Wine', 100, 'milliliters', '2023-01-01', '2023-02-01'),
(70, 'Corn Tortillas', 6, 'pieces', '2023-01-05', '2023-02-15'), (71, 'Cheddar Cheese', 80, 'grams', '2023-01-10', '2023-03-01'), 
(74, 'Bell Peppers', 150, 'grams', '2023-01-10', '2023-03-01'), (75, 'Red Onion', 1, 'pieces', '2023-01-01', '2023-02-01'),
(76, 'Rice', 200, 'grams', '2023-01-05', '2023-02-15'), (77, 'Saffron', 1, 'pinch', '2023-01-10', '2023-03-01'), 
(78, 'Mussels', 200, 'grams', '2023-01-01', '2023-02-01'),
(80, 'Cumin', 10, 'grams', '2023-01-10', '2023-03-01'), (81, 'Coriander', 15, 'grams', '2023-01-01', '2023-02-01'),
(82, 'Basmati Rice', 200, 'grams', '2023-01-05', '2023-02-15'), (83, 'Mixed Vegetables', 300, 'grams', '2023-01-10', '2023-03-01'), 
(84, 'Biryani Masala', 15, 'grams', '2023-01-01', '2023-02-01'), (85, 'Black Beans', 200, 'grams', '2023-01-05', '2023-02-15'), 
(88, 'Chickpeas', 200, 'grams', '2023-01-05', '2023-02-15'), 
(89, 'Pita Bread', 2, 'pieces', '2023-01-10', '2023-03-01'), (90, 'Tahini Sauce', 50, 'grams', '2023-01-01', '2023-02-01');
INSERT INTO origins (ID, origins_name) VALUES (1, 'Mexico'), (2, 'Italy'), (3, 'Vietnam'), (4, 'Norway'),
(5, 'Spain'), (6, 'Australia'), (7, 'Switzerland'), (8, 'Brazil'), (9, 'New Zealand'),  (10, 'India'),
(11, 'Ethiopia'), (12, 'Japan'), (13, 'USA'), (14, 'Greece'), (15, 'Thailand'), 
(16, 'France'), (17, 'Indonesia'), (18, 'Peru'), (19, 'Lebanon');
INSERT INTO category_dishes (category_id, dishes_id) VALUES (1, 1), (1, 2), (1, 3), (2, 4), (2, 5), (2, 6),
(3, 7), (3, 8), (3, 9), (4, 10), (4, 11), (4, 12), (5, 13), (5, 14), (5, 15), (6, 16), (6, 17), (6, 18),
(7, 19), (7, 20), (7, 21), (8, 22), (8, 23), (8, 24);
INSERT INTO dishes_ingridient (dishes_id, ingridient_id) VALUES (1, 1), (1, 2), (1, 3), (2, 4), (2, 5), 
(2, 6), (3, 7), (3, 8), (3, 9), (4, 10), (4, 11), (4, 12), (5, 13), (5, 14), (5, 15), (6, 16), (6, 17), 
(6, 18), (7, 19), (7, 20), (7, 21), (8, 22), (8, 23), (8, 24), (9, 25), (9, 26), (9, 27), (10, 46), 
(10, 20), (10, 48), (11, 49), (11, 50), (11, 51), (12, 52), (12, 53), (12, 54), (13, 55), (13, 56), 
(13, 57), (14, 54), (14, 59), (14, 60), (15, 4), (15, 6), (15, 63), (16, 64), (16, 65), (16, 66),
(17, 67), (17, 68), (17, 69), (18, 70), (18, 71), (18, 3), (19, 7), (19, 74), (19, 75), (20, 76), 
(20, 77), (20, 78), (21, 10), (21, 80), (21, 81), (22, 82), (22, 83), (22, 84), (23, 85), (23, 70), 
(23, 2), (24, 88), (24, 89), (24, 90);
INSERT INTO dishes_origins (dishes_id, origins_id) VALUES (1, 1), (2, 2), (3, 3), (4, 4), (5, 5), (6, 6),
(7, 7), (8, 8), (9, 9), (10, 10), (11, 11), (12, 12), (13, 13), (14, 14), (15, 2), (16, 15), (17, 16), 
(18, 1), (19, 17), (20, 14), (21, 18), (22, 10), (23, 1), (24, 19);