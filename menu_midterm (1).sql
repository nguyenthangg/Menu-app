drop database menu_project;
create database menu_project;
use  menu_project;
create table category(
ID int,
category_name varchar(40),
primary key (ID)
);

CREATE TABLE dishes (
    ID INT PRIMARY KEY,
    dishes_name VARCHAR(40),
    price NUMERIC(4, 2),
    available_time int,
    end_time int,
    CHECK (available_time >= 0 AND available_time <= 24),
	CHECK (end_time >= 0 AND end_time <= 24)
);

DELIMITER //
CREATE TRIGGER before_insert_dishes
BEFORE INSERT ON dishes
FOR EACH ROW
BEGIN
    IF NEW.end_time IS NOT NULL AND NEW.end_time <= NEW.available_time THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Invalid end_time value for dishes';
    END IF;
END;
//
DELIMITER ;


CREATE TABLE ingridient (
    ID INT PRIMARY KEY,
    ingridient_name VARCHAR(40),
    quantity INT check (quantity > 0),
    quantity_unit VARCHAR(40),
    import_date DATE,
    expired_date DATE
);

DELIMITER //
CREATE TRIGGER before_insert_ingridient
BEFORE INSERT ON ingridient
FOR EACH ROW
BEGIN
    IF NEW.expired_date <= NEW.import_date THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Invalid date range for ingridient';
    END IF;
END;
//
DELIMITER ;

CREATE TABLE origins (
    ID INT PRIMARY KEY,
    origins_name VARCHAR(40)
);

CREATE TABLE category_dishes (
    category_id INT,
    dishes_id INT,
    PRIMARY KEY (category_id, dishes_id),
    FOREIGN KEY (category_id) REFERENCES category (ID),
    FOREIGN KEY (dishes_id) REFERENCES dishes (ID)
);

CREATE TABLE dishes_ingridient (
    dishes_id INT,
    ingridient_id INT,
    PRIMARY KEY (dishes_id, ingridient_id),
    FOREIGN KEY (dishes_id) REFERENCES dishes (ID),
    FOREIGN KEY (ingridient_id) REFERENCES ingridient (ID)
);

CREATE TABLE dishes_origins (
    dishes_id INT,
    origins_id INT,
    PRIMARY KEY (dishes_id, origins_id),
    FOREIGN KEY (dishes_id) REFERENCES dishes (ID),
    FOREIGN KEY (origins_id) REFERENCES origins (ID)
);