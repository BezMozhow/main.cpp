//
// Created by Сергій on 3/30/2022.
//
#include "libraries.h"
#ifndef COURSWORK_SCHOLLE_FUNCTIONS_H
#define COURSWORK_SCHOLLE_FUNCTIONS_H

void random_athletes(){


    string r_name, r_lastname, r_surname, r_club;
    vector<string> r_vector_set_of_names, r_vector_set_of_lastnames, r_vector_set_of_surnames, r_vector_set_of_sports, r_vector_set_of_coaches;
    vector<string> r_sport, r_category, r_coaches, r_coaches_category ;

    int r_number=0, r_counter;

    cin >> r_counter;
    srand( time(NULL) );
    for (int i = 0; i < r_counter; ++i) {

        r_vector_set_of_names = {"Aleksandr","Aleksei","Anatolii","Andrei","Anton","Arsenij","Artem","Boris","Vadim","Evgenii","Nikolay"};
        r_vector_set_of_lastnames = {"Kozlov","Petrov","Ivanov","Sinitsyn","Karelin","Kuzmenko","Fedoruk","Pavlenko","Katrushin","Lesovay","Korolyov","Tatarchu"};
        r_vector_set_of_surnames = {"Pavlovich","Sergeevich","Konstantinovich","Grigorevich","Artemovich","Borisovich","Vadimovich"};

        r_vector_set_of_sports = {"Swimming","Canoe Sprint","Football","Golf","Judo","Rowing","Taekwondo","Weightlifting","Gymnastics",};
        r_vector_set_of_coaches = {"The first youth category","The second youth category","The third youth category","The first category","The second category","The third category","Candidate for Master of Sports of Ukraine", "Master of Sports of Ukraine"};
        /*Рандомне ім'я*/
        r_name = r_vector_set_of_names[rand() % r_vector_set_of_names.size()] + " " + r_vector_set_of_lastnames[rand() % r_vector_set_of_lastnames.size()] + " " + r_vector_set_of_surnames[rand() % r_vector_set_of_surnames.size()];

        /*Рандомі види спорту і категорії*/
        r_number = rand() % 2 + 1 ;
        for (int i = 0; i < r_number; ++i) {
            r_sport.push_back(r_vector_set_of_sports[rand() % r_vector_set_of_sports.size()]);
            r_category.push_back(r_vector_set_of_coaches[rand() % r_vector_set_of_coaches.size()]);

            r_coaches.push_back(r_vector_set_of_names[rand() % r_vector_set_of_names.size()] + " " + r_vector_set_of_lastnames[rand() % r_vector_set_of_lastnames.size()] + " " + r_vector_set_of_surnames[rand() % r_vector_set_of_surnames.size()]);

            r_coaches_category.push_back(r_vector_set_of_coaches[rand() % r_vector_set_of_coaches.size()]);

            if(category_number(r_coaches_category[i]) < category_number(r_category[i])){

                r_coaches_category[i] = {number_to_category(category_number(r_category[i]) + 1)};

            }

        }

        if (r_number == 2 && r_sport[1] == r_sport[2]){

            r_sport.erase(r_sport.begin() + i);
            r_category.erase(r_category.begin() + i);
            r_coaches.erase(r_coaches.begin() + i);
            r_coaches_category.erase(r_coaches_category.begin() + i);
        }

        if (r_sport[0] == "Swimming"){
            r_club = "Swimming club";
        }else if(r_sport[0] == "Canoe Sprint"){
            r_club = "Canoe Sprint club";
        }else if(r_sport[0] == "Football"){
            r_club = "Football club";
        }else if(r_sport[0] == "Golf"){
            r_club = "Golf club";
        }else if(r_sport[0] == "Judo"){
            r_club = "Judo club";
        }else if(r_sport[0] == "Rowing"){
            r_club = "Rowing club";
        }else if(r_sport[0] == "Taekwondo"){
            r_club = "Taekwondo club";
        }else if(r_sport[0] == "Weightlifting"){
            r_club = "Weightlifting club";
        }else if(r_sport[0] == "Gymnastics"){
            r_club = "Gymnastics club";
        }



        Sportsman athlete(r_name,r_club, r_sport, r_category, r_coaches, r_coaches_category);

        athletes_database.push_back(athlete);

        r_sport.clear();
        r_category.clear();
        r_coaches.clear();
        r_coaches_category.clear();

    }




}

void add_test_sports_facilities(){

    Pool building_pool;
    TennisCourt building_tennis_court;
    ShootingGallery building_shooting_gallery;
    FootballField building_football_field;
    SkiResort building_ski_resort;

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

    building_ski_resort.set_name("5ht Ski Resort");
    building_ski_resort.set_category("Ski Resort");
    building_ski_resort.set_area(2000);
    building_ski_resort.set_number_of_seats(110);
    building_ski_resort.set_availability_of_buffets("No");
    building_ski_resort.set_availability_of_toilets("No");

    building_ski_resort.set_max_descent_length(500);
    building_ski_resort.set_min_descent_length(50);
    building_ski_resort.set_number_of_lifts(2);

    ski_resort_database.push_back(building_ski_resort);

}

void add_test_athletes(){

    /*Категорії спортсменів
     * 1. The first youth category
     * 2. The second youth category
     * 3. The third youth category
     * 4. The first category
     * 5. The second category
     * 6. The third category
     * 7. Candidate for Master of Sports of Ukraine
     * 8. Master of Sports of Ukraine/ 8. Honored Coach of Ukraine
     * */

    Sportsman item;
    Sportsman item1;
    Sportsman item2;

    item.set_name_of_sportsman("Oleg Yurievich Vernyaev");
    item.set_kinds_of_sport("Gymnastics" );
    item.set_category("Master of Sports of Ukraine");
    item.set_coaches("Biryuk Olena Vasylivna");
    item.set_coach_categories("Honored Coach of Ukraine");
    athletes_database.push_back(item);



    item1.set_name_of_sportsman("Pishkov Dmitry Igorevich");
    item1.set_kinds_of_sport("Greco-Roman wrestling" );
    item1.set_category("Master of Sports of Ukraine");
    item1.set_coaches("Biryuk Olena Vasylivna");
    item1.set_coach_categories("Honored Coach of Ukraine");

    item1.set_kinds_of_sport("Gymnastics" );
    item1.set_category( "The second youth category");
    item1.set_coaches("Alekseevna Irina Leonidovna");
    item1.set_coach_categories("The second category");
    athletes_database.push_back(item1);



    item2.set_kinds_of_sport("Gymnastics" );
    item2.set_category( "The first youth category");
    item2.set_coaches("Ostryzhniuk Alla Volodymyrivna");
    item2.set_coach_categories("The third category");
    athletes_database.push_back(item2);

}




/*Спортсмени*/
void output_athletes_database(){

    if (athletes_database.size() != 0){
        for (int i = 0; i < athletes_database.size(); ++i) {

            athletes_database[i].output_info_about_sportsman(i);

        }
    } else{cout<< "!База даних пуста!"<<endl;}

    system("pause");
}

void add_athletes(){

    Sportsman sportsman;
    int repeat=0, number =0;

    string val;

    cout << "|*|*| Додавання спортсмена |*|*|" << endl;

    cout << "Введіть ім'я спортсмена" << endl;
    cin.ignore();
    getline(cin, val);
    sportsman.set_name_of_sportsman(val);

    cout << "Скількома видами спорту займається спортсмен" << endl;
    cin >> repeat;

    cin.ignore();
    for (int i = 0; i < repeat; ++i) {

        cout << "--------------------" << i + 1  << "--------------------" << endl;

        cout << "Вид спорту яким займається спортсмен" << endl;

        cin.ignore();
        getline(cin, val);
        sportsman.set_kinds_of_sport(val);

        cout << "-Наявні категорії-" << endl
             << "1. The first youth category" << endl
             << "2. The second youth category" << endl
             << "3. The third youth category" << endl
             << "4. The first category" << endl
             << "5. The second category" << endl
             << "6. The third category" << endl
             << "7. Candidate for Master of Sports of Ukraine" << endl
             << "8. Master of Sports of Ukraine"<<endl
             << "9. Honored Coach of Ukraine"<<endl;

        cout << "Категорія спортсмена у виді спорту" << endl;
        do{


            cin >> number;

            val = number_to_category(number);
            cout << val<< endl;
        } while (val == "Incorrect data, try again");

        sportsman.set_category(val);

        cout << "Тренер спортсмена" << endl;
        cin.ignore();
        getline(cin, val);
        sportsman.set_coaches(val);

        cout << "-Наявні категорії-" << endl
             << "1. The first youth category" << endl
             << "2. The second youth category" << endl
             << "3. The third youth category" << endl
             << "4. The first category" << endl
             << "5. The second category" << endl
             << "6. The third category" << endl
             << "7. Candidate for Master of Sports of Ukraine" << endl
             << "8. Master of Sports of Ukraine"<<endl
             << "9. Honored Coach of Ukraine"<<endl;
        do{



            cout << "Категорія тренера" << endl;
            cin >> number;

            val = number_to_category(number);

            cout << val<< endl;
        } while (val == "Incorrect data, try again");

        sportsman.set_coach_categories(val);



    }

    athletes_database.push_back(sportsman);

    cout <<endl<< "!Спортсмена успішно додано!"<<endl;
    system("pause");


}

void search_for_an_athlete(){

    string name;
    int coun=0;
    cout << "Введіть ім'я, прізвище і по батькові спортсмена якого ви хочете знайти" << endl;

    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < athletes_database.size(); ++i) {

        if (name == athletes_database[i].get_name()){

            athletes_database[i].output_info_about_sportsman(i);
            coun++;
        }

    }if (coun==0){cout<<"Немає такого спортсмена у базі" <<endl;}

    system("pause");

}
/*-----------------------------------------*/


/*Спортивні споруди*/

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

    for (int i = 0; i < ski_resort_database.size(); ++i) {

        ski_resort_database[i].output_info_about_ski_resort(number);
        number++;

    }
    system("pause");

}

void add_sports_facilities(){



}


/*-----------------------------------------*/


/*-------------------------1-------------------------*/



/*-------------------------2-------------------------*/

void search_for_an_athletes_by_sport(){
    cout << "|*|*| Пошук спортсменів по виду спорту |*|*|" << endl;

    int coun = 0;
    string sport;

    cout << "За яким видом спорту знайти спортсменів?" << endl;

    cin.ignore();
    getline(cin, sport);


    for (int i = 0; i < athletes_database.size(); ++i) {

        for (int j = 0; j < athletes_database[i].get_kinds_of_sport().size(); ++j) {

            if (sport == athletes_database[i].get_kinds_of_sport()[j]){

                athletes_database[i].output_info_about_sportsman(i);
                coun++;

            }

        }

    }
    if (coun==0){cout<<"Немає такого виду спорту у базі" <<endl;}
    system("pause");

}

void search_for_an_athletes_by_sport_and_category(){
    cout << "|*|*| Пошук спортсменів по виду спорту і категорії спортсмена |*|*|" << endl;


    string sport, category;
    int counter=0, coun=0;

    cout << "За яким видом спорту знайти спортсменів?" << endl;
    cin.ignore();
    getline(cin, sport);

    cout << "Не нище якої категорії мають бути спортсмени?" << endl;
    getline(cin, category);

    category_number(category);

    for (int i = 0; i < athletes_database.size(); ++i) {

        for (int j = 0; j < athletes_database[i].get_kinds_of_sport().size(); ++j) {

            if (athletes_database[i].get_kinds_of_sport()[j] == sport && category_number(athletes_database[i].get_category()[j]) >= category_number(category) ){

                counter++;
                break;

            }

            if (counter==1){break;}


        }
        if (counter == 1){

            athletes_database[i].output_info_about_sportsman(i);
            coun++;
            counter=0;
        }


    }
    if (coun==0){cout<<"!Немає такого виду спорту, категорії або спортсмена!" <<endl;}
    system("pause");

}

/*-------------------------3-------------------------*/

void search_for_athletes_by_coaches(){

    cout << "|*|*| Пошук спортсменів по тренеру |*|*|" << endl;

    int coun = 0;
    string coaches;

    cout << "Введіть прізвище, ім'я та по батькові тренера" << endl;

    cin.ignore();
    getline(cin, coaches);


    for (int i = 0; i < athletes_database.size(); ++i) {

        for (int j = 0; j < athletes_database[i].get_coaches().size(); ++j) {

            if (coaches == athletes_database[i].get_coaches()[j]){

                athletes_database[i].output_info_about_sportsman(i);
                coun++;

            }

        }

    }
    if (coun==0){cout<<"!Немає такого такого тренера у базі!" <<endl;}
    system("pause");


}

void search_for_athletes_by_coach_categories(){

    string coach_categories;
    int coun=0;
    cout << "Не нище якої категорії повинен бути тренер?" << endl;

    cin.ignore();
    getline(cin, coach_categories);



    for (int i = 0; i < athletes_database.size(); ++i) {

        for (int j = 0; j < athletes_database[i].get_coach_categories().size(); ++j) {
            if (category_number( coach_categories) <= category_number(athletes_database[i].get_coach_categories()[j]) ){

                athletes_database[i].output_info_about_sportsman(i);
                coun++;
                break;
            }
        }

    }


    if (coun==0){cout<<"Немає спортсменів з таким тренером" <<endl;}
    system("pause");

}

/*-------------------------4-------------------------*/

void search_for_athletes_with_several_sports(){

    int coun=0;

    for (int i = 0; i < athletes_database.size(); ++i) {


        if (athletes_database[i].get_kinds_of_sport().size() >= 2){
            athletes_database[i].output_info_about_sportsman();
            coun++;
        }

    }
    if (coun==0){cout<<"Немає спортсменів які займаються декількома видами спорту!" <<endl;}
    system("pause");

}

/*-------------------------5-------------------------*/

void output_list_of_athletes_coaches(){

    cout << "Тренерів якого спортсмена ви хочете дізнатися?" << endl;

    string name;

    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < athletes_database.size(); ++i) {

        if (name == athletes_database[i].get_name()){

            cout << "Спортсмет: " << athletes_database[i].get_name() << endl;

            for (int j = 0; j < athletes_database[i].get_coaches().size(); ++j) {

                cout << "Тренер " << j + 1 << ":" << athletes_database[i].get_coaches()[j] << endl;

            }

        }


    }

    system("pause");

}

#endif //COURSWORK_SCHOLLE_FUNCTIONS_H
