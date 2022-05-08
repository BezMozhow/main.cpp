#include "libraries.h"

#include "classes.h"

vector<Sportsman> athletes_database;
vector<Pool> pool_database;
vector<TennisCourt> tennis_court_database;
vector<ShootingGallery> shooting_gallery_database;
vector<FootballField> football_field_database;
vector<SkiResort> ski_resort_database;

#include "auxiliary_functions.h"
#include "functions.h"

int selected_number_in_menu=1;

void menu(){


    cout << endl << "Вибервіть яку дію ви хочете виконати " << endl
         << "1. Додати спортсмена" << endl
         << "2. Вивід спортсменів" << endl
         << "3. Пошук спортсмена" << endl
         << "4. Пошук спортсменів за видом спорту" << endl
         << "5. Пошук спортсменів за видом спорту і категорією" << endl
         << "6. Пошук спортсменів по тренеру" << endl
         << "7. Пошук спортсменів по категоріям тренера" << endl
         << "8. Пошук спортсменів які займаються декількома видами спорту" << endl
         << "9. Вивести тренерів спортсмена " << endl
         << "10. Вивести спортивні споруди " << endl
         << "11. Додати спортивну споруду " << endl
         << "0. Вийти " << endl;

    cin >> selected_number_in_menu;


    switch (selected_number_in_menu) {


        case 1:
            add_athletes();
            break;
        case 2:
            output_athletes_database();
            break;
        case 3:
            search_for_an_athlete();
            break;
        case 4:
            search_for_an_athletes_by_sport();
            break;
        case 5:
            search_for_an_athletes_by_sport_and_category();
            break;
        case 6:
            search_for_athletes_by_coaches();
            break;
        case 7:
            search_for_athletes_by_coach_categories();
            break;
        case 8:
            search_for_athletes_with_several_sports();
            break;
        case 9:
            output_list_of_athletes_coaches();
            break;
        case 10:
            output_sports_facilities();
            break;
        case 11:
            break;
        case 0:

            break;

        default:
            cout << "Некоректно введені дані!!!" << endl;
            break;
    }


}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    random_athletes();

    add_test_athletes();
    add_test_sports_facilities();
    while (selected_number_in_menu != 0){

        menu();

    }

}
