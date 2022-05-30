//
// Created by Сергій on 5/28/2022.
//

#ifndef MAIN_CPP_SPORT_FACILITIES_CLASS_FUNCTIONS_H
#define MAIN_CPP_SPORT_FACILITIES_CLASS_FUNCTIONS_H

void add_test_sports_facilities(){

    Pool building_pool;
    TennisCourt building_tennis_court;
    ShootingGallery building_shooting_gallery;
    FootballField building_football_field;

    building_pool.set_name("4th pool");
    building_pool.set_category("Pool");
    building_pool.set_area(4000);
    building_pool.set_number_of_seats(100);
    building_pool.set_availability_of_buffets("Yes");
    building_pool.set_availability_of_toilets("No");

    building_pool.set_number_of_springboards(3);
    building_pool.set_the_length_of_the_pool(70);
    building_pool.set_depth_of_the_pool(3);
    building_pool.set_the_presence_of_a_bath("No");

    pool_database.push_back(building_pool);

    /*-------------------------------*/

    building_tennis_court.set_name("4th tennis court");
    building_tennis_court.set_category("Tennis court");
    building_tennis_court.set_area(500);
    building_tennis_court.set_number_of_seats(129);
    building_tennis_court.set_availability_of_buffets("No");
    building_tennis_court.set_availability_of_toilets("Yes");

    building_tennis_court.set_coating("artificial");

    tennis_court_database.push_back(building_tennis_court);

    /*-------------------------------*/

    building_shooting_gallery.set_name("6ht Shooting Gallery");
    building_shooting_gallery.set_category("Shooting gallery");
    building_shooting_gallery.set_area(1000);
    building_shooting_gallery.set_number_of_seats(90);
    building_shooting_gallery.set_availability_of_buffets("No");
    building_shooting_gallery.set_availability_of_toilets("Yes");

    building_shooting_gallery.set_number_of_weapons(13);
    building_shooting_gallery.set_weapon_rack(5);
    building_shooting_gallery.set_max_distance_to_targets(500);
    building_shooting_gallery.set_min_distance_to_targets(40);

    shooting_gallery_database.push_back(building_shooting_gallery);

    /*--------------------------------*/

    building_football_field.set_name("1ht Football Field");
    building_football_field.set_category("Football Field");
    building_football_field.set_area(1200);
    building_football_field.set_number_of_seats(12000);
    building_football_field.set_availability_of_buffets("Yes");
    building_football_field.set_availability_of_toilets("Yes");

    building_football_field.set_coating("natural");
    building_football_field.set_length(90);
    building_football_field.set_width(45);

    football_field_database.push_back( building_football_field);

    /*----------------------------------*/


}

void output_sports_facilities(){

    int number=1;

    cout << "|*|*| Вивід всіх спортивних споруд |*|*|" << endl;

    for (int i = 0; i < pool_database.size(); ++i) {
        pool_database[i].output_info_about_pool(number);
        number++;
    }

    for (int i = 0; i < tennis_court_database.size(); ++i) {
        tennis_court_database[i].output_info_about_tennis_court(number);
        number++;
    }

    for (int i = 0; i < shooting_gallery_database.size(); ++i) {
        shooting_gallery_database[i].output_info_about_shooting_gallery(number);
        number++;
    }

    for (int i = 0; i < football_field_database.size(); ++i) {
        football_field_database[i].output_info_about_football_field(number);
        number++;
    }


    system("pause");

}

void add_sports_facilities(){
    int selected_category;

    Pool add_pool;
    TennisCourt add_tennisCourt;
    ShootingGallery add_shooting_gallery;
    FootballField add_football_field;

    string presence_of_a_bath, coating;
    cout << "|*|*|Додавання спортивної споруди|*|*|"<< endl;


    cout << "Наявні категорії спортивних споруд" << endl
         <<"1. Байсейн" << endl
         << "2. Тенісний корт" << endl
         << "3. Тир" << endl
         << "4. Футбольна площадка"<< endl
         << "0. Вийти"<< endl;;

    cout <<  endl << "Введіть категорію спортивної споруди(число)"<< endl;
    cin >> selected_category;

    switch (selected_category) {

        case 1:

            int number_of_springboards, length_of_the_pool, depth_of_the_pool;

            add_pool.default_values_for_input();

            add_pool.set_category("Pool");

            cout << "Введіть кількість трамплінів" << endl;
            cin >> number_of_springboards;
            add_pool.set_number_of_springboards(number_of_springboards);

            cout << "Введіть довжину басейну" << endl;
            cin >> length_of_the_pool;
            add_pool.set_the_length_of_the_pool(length_of_the_pool);

            cout << "Введіть глибину басейну" << endl;
            cin >> depth_of_the_pool;
            add_pool.set_depth_of_the_pool(depth_of_the_pool);

            cout << "Чи найвна ванна(Yes або No)" << endl;
            cin >> presence_of_a_bath;
            add_pool.set_the_presence_of_a_bath(presence_of_a_bath);

            cout << "!Спортивну споруду додано!" << endl;

            pool_database.push_back(add_pool);

            break;

        case 2:

            add_tennisCourt.default_values_for_input();

            add_tennisCourt.set_category("Tennis court");

            cout << "Введіть покриття" << endl;
            cin >> coating;
            add_tennisCourt.set_coating(coating);

            tennis_court_database.push_back(add_tennisCourt);

            cout << "!Спортивну споруду додано!" << endl;
            break;
        case 3:

            int number_of_weapons, weapon_rack, max_distance_to_targets, min_distance_to_targets;

            add_shooting_gallery.default_values_for_input();

            add_shooting_gallery.set_category("Shooting gallery");

            cout << "Введіть кількість зброї" << endl;
            cin >> number_of_weapons;
            add_shooting_gallery.set_number_of_weapons(number_of_weapons);

            cout << "Введіть кількість стійок для зброї" << endl;
            cin >> weapon_rack;
            add_shooting_gallery.set_weapon_rack(weapon_rack);

            cout << "Введіть кількість максимальну дистанцію до цілі" << endl;
            cin >> max_distance_to_targets;
            add_shooting_gallery.set_max_distance_to_targets(max_distance_to_targets);

            cout << "Введіть кількість мінімальну дистанцію до цілі" << endl;
            cin >> min_distance_to_targets;
            add_shooting_gallery.set_min_distance_to_targets(min_distance_to_targets);

            shooting_gallery_database.push_back(add_shooting_gallery);

            cout << "!Спортивну споруду додано!" << endl;

            break;


        case 4:

            int width, length;

            add_football_field.set_coating("Football field");

            add_football_field.default_values_for_input();

            cout << "Введіть покриття" << endl;
            cin >> coating;
            add_football_field.set_coating(coating);

            cout << "Введіть довжину поля" << endl;
            cin >> length;
            add_football_field.set_length(length);

            cout << "Введіть ширину поля" << endl;
            cin >> width;
            add_football_field.set_width(width);

            football_field_database.push_back(add_football_field);

            cout << "!Спортивну споруду додано!" << endl;

            break;


        case 0:
            break;

        default:
            break;

    }

    system("pause");

}

void search_for_sports_facilities(){

    int selected_category, the_selected_search_type, s_area, s_number_of_seats;
    string  name;
    cout << "|*|*| Пошук спортивних споруд |*|*|" << endl;


    cout << "Наявні категорії спортивних споруд" << endl
         << "1. Байсейн" << endl
         << "2. Тенісний корт" << endl
         << "3. Тир" << endl
         << "4. Футбольна площадка"<< endl;

    cout <<  endl<< "Яку категорію спортивних споруд ви шукаєте?(введіть число)" << endl;
    cin >> selected_category;


    cout <<  endl<< "По чому ви хочете здійснити пошук?" << endl
         << "1. Назві" << endl
         << "2. Категорії" << endl
         << "3. Площі" << endl
         << "4. Кількісті сидячих мість" << endl;

    cin >> the_selected_search_type;

    switch (selected_category) {

        case 1:


            switch (the_selected_search_type) {
                case 1:
                    cout << "Введіть назву по якій хочете здійснити пошук" << endl;
                    cin.ignore();
                    getline(cin, name);

                    for (int i = 0; i < pool_database.size(); ++i) {
                        if (pool_database[i].get_name() == name){
                            pool_database[i].output_info_about_pool(i);
                        }
                    }
                    break;
                case 2:

                    for (int i = 0; i < pool_database.size(); ++i) {
                        if (pool_database[i].get_category() == "Pool"){
                            pool_database[i].output_info_about_pool(i);
                        }
                    }
                    break;
                case 3:
                    cout << "Введіть не менше якої площі має бути спортивна споруда" << endl;
                    cin >> s_area;

                    for (int i = 0; i < pool_database.size(); ++i) {
                        if (pool_database[i].get_area() >= s_area){
                            pool_database[i].output_info_about_pool(i);
                        }
                    }
                    break;
                case 4:
                    cout << "Введіть не менше якої кількості сидячих мість має бути в спортивній споруді" << endl;
                    cin >> s_number_of_seats;

                    for (int i = 0; i < pool_database.size(); ++i) {
                        if (pool_database[i].get_number_of_seats() >= s_number_of_seats){
                            pool_database[i].output_info_about_pool(i);
                        }
                    }
                    break;

            }

            break;

        case 2:

            switch (the_selected_search_type) {
                case 1:
                    cout << "Введіть назву по якій хочете здійснити пошук" << endl;
                    cin.ignore();
                    getline(cin, name);

                    for (int i = 0; i < tennis_court_database.size(); ++i) {
                        if (tennis_court_database[i].get_name() == name){
                            tennis_court_database[i].output_info_about_tennis_court(i);
                        }
                    }
                    break;
                case 2:

                    for (int i = 0; i < tennis_court_database.size(); ++i) {
                        if (tennis_court_database[i].get_category() == "Pool"){
                            tennis_court_database[i].output_info_about_tennis_court(i);
                        }
                    }
                    break;
                case 3:
                    cout << "Введіть не менше якої площі має бути спортивна споруда" << endl;
                    cin >> s_area;

                    for (int i = 0; i < tennis_court_database.size(); ++i) {
                        if (tennis_court_database[i].get_area() >= s_area){
                            tennis_court_database[i].output_info_about_tennis_court(i);
                        }
                    }
                    break;
                case 4:
                    cout << "Введіть не менше якої кількості сидячих мість має бути в спортивній споруді" << endl;
                    cin >> s_number_of_seats;

                    for (int i = 0; i < tennis_court_database.size(); ++i) {
                        if (tennis_court_database[i].get_number_of_seats() >= s_number_of_seats){
                            tennis_court_database[i].output_info_about_tennis_court(i);
                        }
                    }
                    break;
            }

            break;

        case 3:

            switch (the_selected_search_type) {
                case 1:
                    cout << "Введіть назву по якій хочете здійснити пошук" << endl;
                    cin.ignore();
                    getline(cin, name);

                    for (int i = 0; i < shooting_gallery_database.size(); ++i) {
                        if (shooting_gallery_database[i].get_name() == name){
                            shooting_gallery_database[i].output_info_about_shooting_gallery(i);
                        }
                    }
                    break;
                case 2:

                    for (int i = 0; i < shooting_gallery_database.size(); ++i) {
                        if (shooting_gallery_database[i].get_category() == "Pool"){
                            shooting_gallery_database[i].output_info_about_shooting_gallery(i);
                        }
                    }
                    break;
                case 3:
                    cout << "Введіть не менше якої площі має бути спортивна споруда" << endl;
                    cin >> s_area;

                    for (int i = 0; i < shooting_gallery_database.size(); ++i) {
                        if (shooting_gallery_database[i].get_area() >= s_area){
                            shooting_gallery_database[i].output_info_about_shooting_gallery(i);
                        }
                    }
                    break;
                case 4:
                    cout << "Введіть не менше якої кількості сидячих мість має бути в спортивній споруді" << endl;
                    cin >> s_number_of_seats;

                    for (int i = 0; i < shooting_gallery_database.size(); ++i) {
                        if (shooting_gallery_database[i].get_number_of_seats() >= s_number_of_seats){
                            shooting_gallery_database[i].output_info_about_shooting_gallery(i);
                        }
                    }
                    break;


            }
            break;

        case 4:
            switch (the_selected_search_type) {
                case 1:
                    cout << "Введіть назву по якій хочете здійснити пошук" << endl;
                    cin.ignore();
                    getline(cin, name);

                    for (int i = 0; i < football_field_database.size(); ++i) {
                        if (football_field_database[i].get_name() == name){
                            football_field_database[i].output_info_about_football_field(i);
                        }
                    }
                    break;
                case 2:

                    for (int i = 0; i < football_field_database.size(); ++i) {
                        if (football_field_database[i].get_category() == "Pool"){
                            football_field_database[i].output_info_about_football_field(i);
                        }
                    }
                    break;
                case 3:
                    cout << "Введіть не менше якої площі має бути спортивна споруда" << endl;
                    cin >> s_area;

                    for (int i = 0; i < football_field_database.size(); ++i) {
                        if (football_field_database[i].get_area() >= s_area){
                            football_field_database[i].output_info_about_football_field(i);
                        }
                    }
                    break;
                case 4:
                    cout << "Введіть не менше якої кількості сидячих мість має бути в спортивній споруді" << endl;
                    cin >> s_number_of_seats;

                    for (int i = 0; i < football_field_database.size(); ++i) {
                        if (football_field_database[i].get_number_of_seats() >= s_number_of_seats){
                            football_field_database[i].output_info_about_football_field(i);
                        }
                    }
                    break;
            }



            break;



    }
    system("pause");


}

void remove_the_sport_facility(){

    int selected_category;
    string r_name;
    cout << "|*|*| Видалення спортивної споруди |*|*|" << endl;


    cout << "Наявні категорії спортивних споруд" << endl
         <<"1. Байсейн" << endl
         << "2. Тенісний корт" << endl
         << "3. Тир" << endl
         << "4. Футбольна площадка"<< endl
         << "0. Вийти"<< endl;

    cout <<  endl << "Введіть категорію спортивної споруди(число)"<< endl;
    cin >> selected_category;

    cout << "Введіть назву спортивної споруди яку ви хочете видалити"<< endl;
    cin.ignore();
    getline(cin, r_name);

    switch (selected_category) {

        case 1:
            for (int i = 0; i < pool_database.size(); ++i) {

                if (pool_database[i].get_name() == r_name){
                    pool_database.erase(pool_database.begin() + i);
                    cout << endl << "!Дію успішно виконано!" << endl;
                }
            }
            break;
        case 2:
            for (int i = 0; i < tennis_court_database.size(); ++i) {

                if (tennis_court_database[i].get_name() == r_name){
                    tennis_court_database.erase(tennis_court_database.begin() + i);
                    cout << endl << "!Дію успішно виконано!" << endl;
                }
            }
            break;
        case 3:
            for (int i = 0; i < shooting_gallery_database.size(); ++i) {

                if (shooting_gallery_database[i].get_name() == r_name){
                    shooting_gallery_database.erase(shooting_gallery_database.begin() + i);
                    cout << endl << "!Дію успішно виконано!" << endl;
                }
            }
            break;
        case 4:
            for (int i = 0; i < football_field_database.size(); ++i) {

                if (football_field_database[i].get_name() == r_name){
                    football_field_database.erase(football_field_database.begin() + i);
                    cout << endl << "!Дію успішно виконано!" << endl;
                }

            }
            break;

    }




}

#endif //MAIN_CPP_SPORT_FACILITIES_CLASS_FUNCTIONS_H
