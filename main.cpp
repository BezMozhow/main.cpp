#include "libraries.h"

#include "classes.h"

vector<Sportsman> athletes_database;
vector<Pool> pool_database;
vector<TennisCourt> tennis_court_database;
vector<ShootingGallery> shooting_gallery_database;
vector<FootballField> football_field_database;

vector<Competition> competition_database;

#include "auxiliary_functions.h"

#include "athlete_class_functions.h"
#include "competition_class_function.h"
#include "sport_facilities_class_functions.h"
#include "functions.h"


void menu_athletes(){

    cout << "|*|*|Спортсмени|*|*|" << endl
    << "1. Вивід всіх спортсменів" << endl
    << "2. Додавання спортсмена" << endl
    << "3. Зміна даних про спортсмена" << endl
    << "4. Пошук спортсменів" << endl
    << "5. Видалити спортсмена" << endl
    << "0. Вийти" << endl;

    int selected_number_in_menu_athletes = 1;
    cin >> selected_number_in_menu_athletes;

    switch (selected_number_in_menu_athletes) {

        case 1:
            output_athletes_database();
            break;
        case 2:
            add_athletes();
            break;
        case 3:
            change_athlete_data();
            break;

        case 4:
            menu_search_for_athletes();
            break;

        case 5:
            remove_the_athlete();
            break;

        case 0:
            break;

        default:
            cout << "Некоректно введені дані!!!" << endl;
            break;

    }


}


void menu_sports_facilities(){

    cout << "|*|*|Спортивні споруди|*|*|" << endl
         << "1. Вивід всіх спортивних споруд" << endl
         << "2. Додавання спортивної споруди"<< endl
         << "3. Пошук спортивних споруд" << endl
         << "4. Видалити спортивну споруду" << endl
         << "0. Вийти" << endl;

    int selected_number_in_sports_facilities = 1;
    cin >> selected_number_in_sports_facilities;

    switch (selected_number_in_sports_facilities) {

        case 1:
            output_sports_facilities();
            break;
        case 2:
            add_sports_facilities();
            break;
        case 3:
            search_for_sports_facilities();
            break;
        case 4:
            remove_the_sport_facility();
            break;

        case 0:
            break;

        default:
            cout << "Некоректно введені дані!!!" << endl;
            break;

    }


}

void menu_competition(){

    cout << "|*|*|Спортивні змагання|*|*|" << endl

         << "1. Вивід спортивних змагань" << endl
         << "2. Додавання спортивної події" << endl
         << "3. Пошук спортивних змагань" << endl
         << "0. Вийти" << endl;

    int selected_number_in_menu_competition = 1;
    cin >> selected_number_in_menu_competition;

    switch (selected_number_in_menu_competition) {

        case 1:
            output_competitions();
            break;
        case 2:
            add_competition();
            break;
        case 3:
            menu_search_for_sports_competitions();
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
    int selected_number_in_menu=1;

    random_athletes();
    random_competition();


    add_test_sports_facilities();
    while (selected_number_in_menu != 0){


        cout << endl << "Меню" << endl
             << "1. Спортсмени" << endl
             << "2. Спортивні споруди" << endl
             << "3. Спортивні події" << endl
             << "0. Вийти " << endl;

        cin >> selected_number_in_menu;

        switch (selected_number_in_menu) {


            case 1:
                menu_athletes();
                break;
            case 2:
                menu_sports_facilities();
                break;
            case 3:
                menu_competition();
                break;

            case 0:
                break;

            default:
                cout << "Некоректно введені дані!!!" << endl;
                break;
        }


    }

}
