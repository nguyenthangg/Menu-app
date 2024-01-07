#include <iostream>
#include <mysql_driver.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "root";

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    vector<int> categoryID, dishesID, dishesAvailableTime, dishesEndTime, ingridientID, ingridientQuantity, originsID, categoryDishesCategoryID, categoryDishesDishesID, dishesIngridientDishesID, dishesIngridientIngridientID, dishesOriginsDishesID, dishesOriginsOriginsID;
    vector<string> categoryName, dishesName, ingridientName, ingridientQuantityUnit, ingridientImportDate, ingridientExpiredDate, originsName;
    vector<double> dishesPrice;
    
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(server, username, password);
        con->setSchema("menu_project");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM category");
        while (res->next()) {
            categoryID.push_back(res->getInt("ID"));
            categoryName.push_back(res->getString("category_name"));
        }

        res = stmt->executeQuery("SELECT * FROM dishes");
        while (res->next()) {
            dishesID.push_back(res->getInt("ID"));
            dishesName.push_back(res->getString("dishes_name"));
            dishesPrice.push_back(res->getDouble("price"));
            dishesAvailableTime.push_back(res->getInt("available_time"));
            dishesEndTime.push_back(res->getInt("end_time"));
        }

        res = stmt->executeQuery("SELECT * FROM ingridient");
        while (res->next()) {
            ingridientID.push_back(res->getInt("ID"));
            ingridientName.push_back(res->getString("ingridient_name"));
            ingridientQuantity.push_back(res->getInt("quantity"));
            ingridientQuantityUnit.push_back(res->getString("quantity_unit"));
            ingridientImportDate.push_back(res->getString("import_date"));
            ingridientExpiredDate.push_back(res->getString("expired_date"));
        }

        res = stmt->executeQuery("SELECT * FROM origins");
        while (res->next()) {
            originsID.push_back(res->getInt("ID"));
            originsName.push_back(res->getString("origins_name"));
        }

        res = stmt->executeQuery("SELECT * FROM category_dishes");
        while (res->next()) {
            categoryDishesCategoryID.push_back(res->getInt("category_id"));
            categoryDishesDishesID.push_back(res->getInt("dishes_id"));
        }

        res = stmt->executeQuery("SELECT * FROM dishes_ingridient");
        while (res->next()) {
            dishesIngridientDishesID.push_back(res->getInt("dishes_id"));
            dishesIngridientIngridientID.push_back(res->getInt("ingridient_id"));
        }

        res = stmt->executeQuery("SELECT * FROM dishes_origins");
        while (res->next()) {
            dishesOriginsDishesID.push_back(res->getInt("dishes_id"));
            dishesOriginsOriginsID.push_back(res->getInt("origins_id"));
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "SQLException: " << e.what() << endl;
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int time = rand() % 24;
    cout << "Time: " << time << endl;
    while (true) {
        cout << endl;
        cout << "How do you want to view menu?" << endl;
        cout << "1. By Category" << endl;
        cout << "2. By Origins" << endl;
        cout << "3. Exit" << endl;
        cout << "Your option: ";
        string userOption;
        int menuOption = 0;
        bool flag = true;
        getline(cin, userOption);
        while (true) {
            if (flag == false) {
                cout << "Invalid option! Please choose again: ";
                getline(cin, userOption);
            }
            flag = true;
            if (userOption == "") flag = false;
            for (int i = 0; i < userOption.size(); i++) {
                if (i == 0) {
                    if (userOption[0] < 49 || userOption[0] > 57) {
                        flag = false;
                        continue;
                    }
                }
                else {
                    if (userOption[i] < 48 || userOption[i] > 57) {
                        flag = false;
                        continue;
                    }
                }
            }
            if (flag == true) {
                for (int i = 0; i < 3; i++) {
                    if (stoi(userOption) == 1 || stoi(userOption) == 2 || stoi(userOption) == 3) {
                        menuOption = stoi(userOption);
                        break;
                    }
                }
                if (menuOption == 1 || menuOption == 2 || menuOption == 3) break;
                flag = false;
            }
        }
        switch (menuOption) {
        case 1:
            while (true) {
                cout << endl;
                cout << "-------- MENU --------" << endl;
                for (int i = 0; i < categoryID.size(); i++) {
                    cout << categoryID[i] << ". " << categoryName[i] << endl;
                }
                cout << categoryID.size() + 1 << ". Back to Menu Search" << endl;
                cout << "Your option: ";
                getline(cin, userOption);
                while (true) {
                    if (flag == false) {
                        cout << "Invalid option! Please choose again: ";
                        getline(cin, userOption);
                    }
                    flag = true;
                    if (userOption == "") flag = false;
                    for (int i = 0; i < userOption.size(); i++) {
                        if (i == 0) {
                            if (userOption[0] < 49 || userOption[0] > 57) {
                                flag = false;
                                continue;
                            }
                        }
                        else {
                            if (userOption[i] < 48 || userOption[i] > 57) {
                                flag = false;
                                continue;
                            }
                        }
                    }
                    if (flag == true) {
                        if(stoi(userOption) == categoryID.size() + 1) menuOption = stoi(userOption);
                        else {
                            for (int i = 0; i < categoryID.size(); i++) {
                                if (stoi(userOption) == categoryID[i]) {
                                    menuOption = stoi(userOption);
                                    break;
                                }
                            }
                        }
                        if (stoi(userOption) <= categoryID.size() + 1) break;
                        flag = false;
                    }
                }
                if(menuOption != (categoryID.size() + 1)){
                    while (true) {
                        cout << endl;
                        cout << "-------- MENU --------" << endl;
                        vector<int> dishes, availableDishes;
                        int position = 0;
                        for (int i = 0; i < categoryDishesCategoryID.size(); i++) {
                            if (menuOption == categoryDishesCategoryID[i]) dishes.push_back(categoryDishesDishesID[i]);
                        }
                        for (int i = 0; i < dishes.size(); i++) {
                            for (int k = 0; k < dishesID.size(); k++) {
                                if (dishes[i] == dishesID[k] && time >= dishesAvailableTime[k] && time <= dishesEndTime[k]) {
                                    availableDishes.push_back(dishesID[k]);
                                    for (int j = 0; j < dishesOriginsDishesID.size(); j++) {
                                        if (dishesID[k] == dishesOriginsDishesID[j])
                                            for (int l = 0; l < originsID.size(); l++) {
                                                if (dishesOriginsOriginsID[j] == originsID[l]) {
                                                    cout << ++position << ". " << left << setw(40) << dishesName[k] << left << setw(10) << dishesPrice[k] << originsName[l] << endl;
                                                }
                                            }
                                    }
                                }
                            }
                        }
                        int dishesOption = 0;
                        cout << ++position << ". Back to Menu" << endl;
                        cout << "Your option: ";
                        getline(cin, userOption);
                        while (true) {
                            if (flag == false) {
                                cout << "Invalid option! Please choose again: ";
                                getline(cin, userOption);
                            }
                            flag = true;
                            if (userOption == "") flag = false;
                            for (int i = 0; i < userOption.size(); i++) {
                                if (i == 0) {
                                    if (userOption[0] < 49 || userOption[0] > 57) {
                                        flag = false;
                                        continue;
                                    }
                                }
                                else {
                                    if (userOption[i] < 48 || userOption[i] > 57) {
                                        flag = false;
                                        continue;
                                    }
                                }
                            }
                            if (flag == true) {
                                dishesOption = stoi(userOption);
                                if (dishesOption <= availableDishes.size() + 1) break;
                                flag = false;
                            }
                        }
                        if (dishesOption != availableDishes.size() + 1) {
                            cout << endl;
                            cout << "-------- MENU --------" << endl;
                            for (int i = 0; i < dishesIngridientDishesID.size(); i++) {
                                if (availableDishes[dishesOption - 1] == dishesIngridientDishesID[i]) {
                                    for (int k = 0; k < ingridientID.size(); k++) {
                                        if (dishesIngridientIngridientID[i] == ingridientID[k])
                                            cout << "-  " << left << setw(25) << ingridientName[k] << left << setw(5) << ingridientQuantity[k] << " " << left << setw(20) << ingridientQuantityUnit[k] << "Import Date: " << left << setw(15) << ingridientImportDate[k] << "Expried Date: " << ingridientExpiredDate[k] << endl;
                                    }
                                }
                            }
                        }
                        else break;
                        system("pause");
                    }
                }
                else break;
            }
            break;
        case 2:
            while (true) {
                cout << endl;
                cout << "-------- MENU --------" << endl;
                for (int i = 0; i < originsID.size(); i++) {
                    cout << originsID[i] << ". " << originsName[i] << endl;
                }
                cout << originsID.size() + 1 << ". Back to Menu Search" << endl;
                cout << "Your option: ";
                getline(cin, userOption);
                while (true) {
                    if (flag == false) {
                        cout << "Invalid option! Please choose again: ";
                        getline(cin, userOption);
                    }
                    flag = true;
                    if (userOption == "") flag = false;
                    for (int i = 0; i < userOption.size(); i++) {
                        if (i == 0) {
                            if (userOption[0] < 49 || userOption[0] > 57) {
                                flag = false;
                                continue;
                            }
                        }
                        else {
                            if (userOption[i] < 48 || userOption[i] > 57) {
                                flag = false;
                                continue;
                            }
                        }
                    }
                    if (flag == true) {
                        if (stoi(userOption) == originsID.size() + 1) menuOption = stoi(userOption);
                        else {
                            for (int i = 0; i < originsID.size(); i++) {
                                if (stoi(userOption) == originsID[i]) {
                                    menuOption = stoi(userOption);
                                    break;
                                }
                            }
                        }
                        if (stoi(userOption) <= originsID.size() + 1) break;
                        flag = false;
                    }
                }
                if (menuOption != (originsID.size() + 1)) {
                    while (true) {
                        cout << endl;
                        cout << "-------- MENU --------" << endl;
                        vector<int> dishes, availableDishes;
                        int position = 0;
                        for (int i = 0; i < dishesOriginsOriginsID.size(); i++) {
                            if (menuOption == dishesOriginsOriginsID[i]) dishes.push_back(dishesOriginsDishesID[i]);
                        }
                        for (int i = 0; i < dishes.size(); i++) {
                            for (int k = 0; k < dishesID.size(); k++) {
                                if (dishes[i] == dishesID[k] && time >= dishesAvailableTime[k] && time <= dishesEndTime[k]) {
                                    availableDishes.push_back(dishesID[k]);
                                    for (int j = 0; j < dishesOriginsDishesID.size(); j++) {
                                        if (dishesID[k] == dishesOriginsDishesID[j])
                                            for (int l = 0; l < originsID.size(); l++) {
                                                if (dishesOriginsOriginsID[j] == originsID[l]) {
                                                    cout << ++position << ". " << left << setw(40) << dishesName[k] << left << setw(10) << dishesPrice[k] << originsName[l] << endl;
                                                }
                                            }
                                    }
                                }
                            }
                        }
                        int dishesOption = 0;
                        if (position == 0) cout << "Out of service!" << endl;
                        cout << ++position << ". Back to Menu" << endl;
                        cout << "Your option: ";
                        getline(cin, userOption);
                        while (true) {
                            if (flag == false) {
                                cout << "Invalid option! Please choose again: ";
                                getline(cin, userOption);
                            }
                            flag = true;
                            if (userOption == "") flag = false;
                            for (int i = 0; i < userOption.size(); i++) {
                                if (i == 0) {
                                    if (userOption[0] < 49 || userOption[0] > 57) {
                                        flag = false;
                                        continue;
                                    }
                                }
                                else {
                                    if (userOption[i] < 48 || userOption[i] > 57) {
                                        flag = false;
                                        continue;
                                    }
                                }
                            }
                            if (flag == true) {
                                dishesOption = stoi(userOption);
                                if (dishesOption <= availableDishes.size() + 1) break;
                                flag = false;
                            }
                        }
                        if (dishesOption != availableDishes.size() + 1) {
                            cout << endl;
                            cout << "-------- MENU --------" << endl;
                            for (int i = 0; i < dishesIngridientDishesID.size(); i++) {
                                if (availableDishes[dishesOption - 1] == dishesIngridientDishesID[i]) {
                                    for (int k = 0; k < ingridientID.size(); k++) {
                                        if (dishesIngridientIngridientID[i] == ingridientID[k])
                                            cout << "-  " << left << setw(25) << ingridientName[k] << left << setw(5) << ingridientQuantity[k] << " " << left << setw(20) << ingridientQuantityUnit[k] << "Import Date: " << left << setw(15) << ingridientImportDate[k] << "Expried Date: " << ingridientExpiredDate[k] << endl;
                                    }
                                }
                            }
                        }
                        else break;
                        system("pause");
                    }
                }
                else break;
            }
            break;
        case 3:
            exit(0);
        }
    }


    return 0;
}
