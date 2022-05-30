//
// Created by Сергій on 5/28/2022.
//

#ifndef MAIN_CPP_ATHLETE_CLASS_FUNCTIONS_H
#define MAIN_CPP_ATHLETE_CLASS_FUNCTIONS_H

void random_athletes(){

    tm r_date;
    string r_name, r_club;
    vector<string> r_vector_set_of_names, r_vector_set_of_lastnames, r_vector_set_of_surnames, r_vector_set_of_sports, r_vector_set_of_coaches,  r_vector_name_of_event;
    vector<string> r_sport, r_category, r_coaches, r_coaches_category, r_competition ;
    vector<tm> r_date_of_the_competition;

    r_vector_set_of_names = {"Aleksandr","Aleksei","Anatolii","Andrei","Anton","Arsenij","Artem","Boris","Vadim","Evgenii","Nikolay"};
    r_vector_set_of_lastnames = {"Kozlov","Petrov","Ivanov","Sinitsyn","Karelin","Kuzmenko","Fedoruk","Pavlenko","Katrushin","Lesovay","Korolyov","Tatarchu"};
    r_vector_set_of_surnames = {"Pavlovich","Sergeevich","Konstantinovich","Grigorevich","Artemovich","Borisovich","Vadimovich"};


    r_vector_set_of_sports = {"Swimming","Canoe Sprint","Football","Golf","Judo","Rowing","Taekwondo","Weightlifting","Gymnastics",};
    r_vector_set_of_coaches = {"The first youth category","The second youth category","The third youth category","The first category","The second category","The third category","Candidate for Master of Sports of Ukraine", "Master of Sports of Ukraine"};

    r_vector_name_of_event = {"Health","For life","Against poverty","For the share","No obesity","Sports Olympiad","Ladybug"};

    int r_number=0, r_counter = 100;

    srand( time(NULL) );
    for (int i = 0; i < r_counter; ++i) {

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

        /*Рандомне змагання*/
        r_number = rand() % 5 + 1 ;

        for (int j = 0; j < r_number; ++j) {
            r_competition.push_back(r_vector_name_of_event[rand() % r_vector_name_of_event.size()]);

            r_date.tm_year = rand() % 52 + 1970;
            r_date.tm_mon = rand() % 11;
            r_date.tm_mday = rand() % 31;

            r_date_of_the_competition.push_back(r_date);

        }

        /*Рандомна дата проведення*/

        Sportsman athlete(r_name,r_club, r_sport, r_category, r_coaches, r_coaches_category, r_competition, r_date_of_the_competition);

        athletes_database.push_back(athlete);

        r_sport.clear();
        r_category.clear();
        r_coaches.clear();
        r_coaches_category.clear();
        r_competition.clear();
        r_date_of_the_competition.clear();

    }




}

void output_athletes_database(){

    system("cls");

    cout << endl << "|*|*|Вивід всіх спортсменів|*|*|" << endl << endl;

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

    cout << "Введіть ім'я, прізвище та по-батькові спортсмена" << endl;
    cin.ignore();
    getline(cin, val);
    sportsman.set_name_of_sportsman(val);

    cout << "Введіть спортивний клуб до якого належить спортсмен " << endl;
    getline(cin, val);
    sportsman.set_sport_club(val);

    cout << "Скількома видами спорту займається спортсмен" << endl;
    cin >> repeat;

    cin.ignore();
    for (int i = 0; i < repeat; ++i) {

        cout << "--------------------" << i + 1  << "--------------------" << endl;

        cout << "Вид спорту яким займається спортсмен" << endl;

        cin.ignore();
        getline(cin, val);
        sportsman.set_kinds_of_sport(val);

        available_categories();

        cout << "Категорія спортсмена у виді спорту(число)" << endl;
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

        available_categories();

        do{

            cout << "Категорія тренера(число)" << endl;
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

    cout << endl << "|*|*|Пошукс спортсмена за ім'ям|*|*|"  << endl << endl;

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

void change_athlete_data(){

    string name, c_name, c_kinds_of_sport, c_coaches, c_coach_categories, c_category, c_club, c_competition;
    int change_number = 0, submenu_number = 0, c_num_category;
    vector<int> num_of_athletes;
    tm c_date;
    cout << "|*|*|Зміна даних про спортсмена|*|*|" << endl;

    cout << "Введіть ім'я, прізвище та по батькові спортсмена" << endl;
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < athletes_database.size(); ++i) {

        if (athletes_database[i].get_name() == name){
            num_of_athletes.push_back(i);
        }

    }

    if (num_of_athletes.size() == 0){ cout << "Такого спортсмена неіснує" << endl; return;}

    for (int i = 0; i < num_of_athletes.size(); ++i) {
        athletes_database[num_of_athletes[i]].output_info_about_sportsman(i);
    }


    cout << "Якому саме спортсмену ви хочете змінити дані?(виберіть номер)"<< endl;
    cin >> change_number;
    change_number--;

    cout << "Що саме ви хочете зробити?" << endl
         << "1. Змінити ім'я" << endl
         << "2. Додати вид спорту" << endl
         << "3. Змінити категорію спортсмена у виді спорту" << endl
         << "4. Змінити тренера" << endl
         << "5. Змінити клуб спортсмена" << endl
         << "6. Додати змагання" << endl;

    cin >> submenu_number;

    switch (submenu_number) {
        case 1:
            cout << endl << "*Зміна імені*" << endl;
            cin.ignore();
            getline(cin, c_name);
            athletes_database[num_of_athletes[change_number]].set_name_of_sportsman(c_name);
            break;
        case 2:
            cout << endl << "*Додавання виду спорту*" << endl ;

            /*Вид спорту*/
            cout << "Вид спорту" << endl;
            cin.ignore();
            getline(cin, c_kinds_of_sport);
            athletes_database[num_of_athletes[change_number]].set_kinds_of_sport(c_kinds_of_sport);
            /*Категорі*/

            /*Наявні категорії*/
            available_categories();

            cout << "Категорія спортсмена у виді спорту(число)" << endl;
            do{
                cin >> c_num_category;

                c_category = number_to_category(c_num_category);
                cout << c_category<< endl;
                athletes_database[num_of_athletes[change_number]].set_category(c_category);
            } while (c_category == "Incorrect data, try again");

            /*Тренер*/
            cout << "Тренер" << endl;
            cin.ignore();
            getline(cin, c_coaches);
            athletes_database[num_of_athletes[change_number]].set_coaches(c_coaches);

            /*Наявні категорії*/
            available_categories();

            do{

                cout << "Категорія тренера(число)" << endl;
                cin >> c_num_category;

                c_coach_categories = number_to_category(c_num_category);

                cout << c_coach_categories<< endl;
                athletes_database[num_of_athletes[change_number]].set_coach_categories(c_coach_categories);
            } while (c_coach_categories == "Incorrect data, try again");

            break;

        case 3:

            cout << endl << "*Зміна категорії спортсмена у виді спорту*" << endl;

            cout << endl << "Категорію у якому виді спорту ви хочете змінити?" << endl;
            cin.ignore();
            getline(cin, c_kinds_of_sport);

            for (int i = 0; i < athletes_database[num_of_athletes[change_number]].get_kinds_of_sport().size(); ++i) {

                if (athletes_database[num_of_athletes[change_number]].get_kinds_of_sport()[i] == c_kinds_of_sport){

                    available_categories();
                    cout << "На яку категорію ви хочете змінити?" << endl;
                    do{
                        cin >> c_num_category;

                        c_category = number_to_category(c_num_category);
                        cout << c_category<< endl;
                        athletes_database[num_of_athletes[change_number]].change_category(c_category, i);
                    } while (c_category == "Incorrect data, try again");


                } else{
                    cout << "У даного спортсмена немає такого виду спорту!" << endl;
                }

            }


            break;

        case 4:

            cout << endl << "*Зміна тренера*" << endl;

            cout << endl << "Тренера у якому виді спорту ви хочете змінити?" << endl;
            cin.ignore();
            getline(cin, c_kinds_of_sport);

            for (int i = 0; i < athletes_database[num_of_athletes[change_number]].get_kinds_of_sport().size(); ++i) {

                if (athletes_database[num_of_athletes[change_number]].get_kinds_of_sport()[i] == c_kinds_of_sport){

                    cout << "Введіть ім'я, прізвище та по-батькові тренера" << endl;
                    cin.ignore();
                    getline(cin, c_coaches);

                    athletes_database[num_of_athletes[change_number]].change_coaches(c_coaches, i);

                } else{
                    cout << "У даного спортсмена немає ткого виду спорту!" << endl;
                }

            }

            break;

        case 5:
            cout << endl << "*Зміна клубу*" << endl;

            cout << endl << "Введіть назву клубу?" << endl;
            cin.ignore();
            getline(cin, c_club);

            athletes_database[num_of_athletes[change_number]].set_sport_club(c_club);



            break;
        case 6:

            int year, mon, day;

            cout << endl << "*Додавання змагання*" << endl;

            cout << endl << "Введіть назву змагання" << endl;

            cin.ignore();
            getline(cin, c_competition);

            athletes_database[num_of_athletes[change_number]].set_competition(c_competition);

            cout << "Введіть рік: "<< endl;
            cin >> year;

            cout << "Введіть місяць: " << endl;
            cin >> mon;

            cout << "Введіть день: "<< endl;
            cin >> day;

            c_date.tm_year = year;
            c_date.tm_mon = mon;
            c_date.tm_mday = day;

            athletes_database[num_of_athletes[change_number]].set_date_of_the_competition(c_date);

            cout << "!Змагання успішно додано!"<< endl;

            break;
        case 0:
            break;
    }
    system("pause");

}

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

    string sport, category;
    int counter=0, coun=0, num_category = 01;

    cout << "|*|*| Пошук спортсменів по виду спорту і категорії |*|*|" << endl;


    cout << "За яким видом спорту знайти спортсменів?" << endl;
    cin.ignore();
    getline(cin, sport);



    /*Наявні категорії*/
    available_categories();

    cout << "Не нище якої категорії мають бути спортсмени?(введіть число)" << endl;
    cin >> num_category;
    category = number_to_category(num_category);
    cout <<  category<< endl;

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
    int coun=0, num_category;

    cout << "|*|*|Пошук спортсмена по категорії тренера|*|*|" << endl;

/*Наявні категорії*/
    available_categories();

    cout << "Не нище якої категорії повинен бути тренер?" << endl;
    cin >> num_category;
    coach_categories = number_to_category(num_category);
    cout <<  coach_categories<< endl;


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

void search_for_athletes_with_several_sports(){

    int coun=0;

    cout << endl<<  "|*|*|Пошук спортсменів з декількома видами спорту|*|*|" << endl;

    for (int i = 0; i < athletes_database.size(); ++i) {


        if (athletes_database[i].get_kinds_of_sport().size() >= 2){
            athletes_database[i].output_info_about_sportsman(i);
            coun++;
        }

    }
    if (coun==0){cout<<"Немає спортсменів які займаються декількома видами спорту!" <<endl;}
    system("pause");

}

void search_for_athletes_who_did_not_participate_in_competitions(){

    tm start_date, end_date, s_date;
    int start_in_days, end_in_days, counter;
    vector<string> v_name;

    cout << "|*|*|Спортсмени які не брали участі у змаганнях протягом періоду часу|*|*|" << endl<< endl;

    cout<< endl  << "*|Введіть дату від якої має здійснюватися пошук|*" << endl;

    start_date = entering_the_date();

    cout<< endl  << "*|Введіть дату до якої має здійснюватися пошук|*" << endl;

    end_date = entering_the_date();

    start_in_days = date_in_days(start_date);
    end_in_days = date_in_days(end_date);

    cout << "Спортсмени які не брали участі в змаганнях" << endl;
    cout <<  "Між " << start_date.tm_mday <<"/"<< start_date.tm_mon <<"/"<< start_date.tm_year<< " i " << end_date.tm_mday <<"/"<< end_date.tm_mon <<"/"<< end_date.tm_year << endl << endl;

    for (int i = 0; i < athletes_database.size(); ++i) {


        for (int j = 0; j < athletes_database[i].get_competition().size(); ++j) {

            if (start_in_days <= date_in_days(athletes_database[i].get_date_of_the_competition()[j]) &&
                date_in_days(athletes_database[i].get_date_of_the_competition()[j]) <= end_in_days){
                counter = counter +2;
            }

        }

        if(counter == 0){
            cout << "--" << athletes_database[i].get_name() << endl;
        }

        counter = 0;
    }

    system("pause");



}

void search_for_athletes_who_participated_in_competitions(){
    tm start_date, end_date, s_date;
    int start_in_days, end_in_days, counter;
    vector<string> v_name, v_club;

    cout << "|*|*|Пошук спортсменів які брали участь у змаганнях протягом періоду часу|*|*|" << endl<< endl;

    cout<< endl  << "*|Введіть дату від якої має здійснюватися пошук|*" << endl;

    start_date = entering_the_date();

    cout<< endl  << "*|Введіть дату до якої має здійснюватися пошук|*" << endl;

    end_date = entering_the_date();

    start_in_days = date_in_days(start_date);
    end_in_days = date_in_days(end_date);

    cout << endl << "Спортсмени які брали участі в змаганнях" << endl;
    cout <<  "Між " << start_date.tm_mday <<"/"<< start_date.tm_mon <<"/"<< start_date.tm_year<< " i " << end_date.tm_mday <<"/"<< end_date.tm_mon <<"/"<< end_date.tm_year << endl << endl;


    for (int i = 0; i <  athletes_database.size(); ++i) {


        for (int j = 0; j < v_club.size(); ++j) {


            if (v_club.size() == 0){
                break;
            }
            if (athletes_database[i].get_sport_club() == v_club[j]) {
                counter = counter + 2;
                break;
            }

        }

        if (counter > 0) {
            counter = 0;
            continue;

        }
        v_club.push_back(athletes_database[i].get_sport_club());

        cout << endl << "---Клуб: " << v_club.back() << endl;
        for (int j = 0; j < athletes_database.size(); ++j) {

            for (int k = 0; k < athletes_database[j].get_date_of_the_competition().size(); ++k) {
                if (athletes_database[j].get_sport_club() == v_club.back() && start_in_days <= date_in_days(athletes_database[i].get_date_of_the_competition()[j]) &&
                    date_in_days(athletes_database[i].get_date_of_the_competition()[j]) <= end_in_days) {

                    cout << "-" << athletes_database[j].get_name() << endl;
                    break;

                }
            }

        }

        cout << "-----------------------------------------------"<<endl;

        counter = 0;
    }
    system("pause");

}

void search_for_coaches_by_sport(){

    string s_sport;
    vector<string> v_coaches;
    int counter;
    cout << "|*|*|Пошук тренера за видом спорту|*|*|" << endl<< endl;

    cout << "Введіть вид спорту"<< endl;
    cin.ignore();
    getline(cin, s_sport);


    for (int i = 0; i < athletes_database.size(); ++i) {

        for (int j = 0; j < v_coaches.size(); ++j) {

            if (athletes_database[i].get_coaches()[i] == v_coaches[j]){
                counter = counter +2;
                break;
            }

        }
        if (counter>0){counter =0; continue;}


        for (int j = 0; j < athletes_database[i].get_kinds_of_sport().size(); ++j) {

            if (athletes_database[i].get_kinds_of_sport()[j] == s_sport){

                v_coaches.push_back( athletes_database[i].get_coaches()[j]);

            }

        }


    }
    cout << "Вид спорту: " << s_sport << endl;
    cout << "Тренери" << endl;
    for (int i = 0; i < v_coaches.size(); ++i) {
        cout << "--" << v_coaches[i]<< endl;
    }
    system("pause");
}

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

void remove_the_athlete(){
    string r_name;
    vector<int> v_number_in_the_database;
    int number, r_counter=0;

    cout << "|*|*|Видалення спортсмена|*|*|" << endl<< endl;

    cout << "Введіть ім'я спортсмена якого ви хочете видалити" << endl;
    cin.ignore();
    getline(cin, r_name);


    for (int i = 0; i < athletes_database.size(); ++i) {

        if (athletes_database[i].get_name() == r_name){
            v_number_in_the_database.push_back(i);
        }

    }

    for (int i = 0; i < v_number_in_the_database.size(); ++i) {

        athletes_database[v_number_in_the_database[i]].output_info_about_sportsman(i);

    }




    while (r_counter==0){
        cout << endl << "Якого саме спортсмена ви хочете видалити?(введіть число)" << endl;
        cin >> number;

        if (number > v_number_in_the_database.size()){
            cout << "Ви ввели неправильне число" <<endl;
        } else{
            r_counter++;
        }

    }


    athletes_database.erase(athletes_database.begin() + v_number_in_the_database[number - 1]);

    cout << endl<<"!Дію успішно виконано!"<<endl;
    system("pause");

}

void menu_search_for_athletes(){
    int selected_number;
    cout << "Пошук спортсменів" << endl
            << "1. Пошукс спортсмена за ім'ям" << endl
            << "2. Пошук спортсменів по виду спорту" << endl
            << "3. Пошук спортсменів за тренером" << endl
            << "4. Пошук спортсменів по категорії тренера" << endl
            << "5. Пошук спортсменів з декількома видами спорту" << endl
            << "6. Пошук спортсменів за видом спорту і не нище перної категорії" << endl
            << "7. Пошук тренерів за видом спорту" << endl
            << "8. Пошук спортсменів які не брали участі в змаганнях протягом періоду часу" << endl
            << "9. Пошук спортсменів які брали участі в змаганнях протягом періоду часу" << endl
            << "0. Вийти" << endl;

    cout << "Введіть дію яку хочете виконати" << endl;
    cin>>selected_number;

    switch (selected_number) {
        case 1:
            search_for_an_athlete();
            break;
        case 2:
            search_for_an_athletes_by_sport();
            break;
        case 3:
            search_for_athletes_by_coaches();
            break;
        case 4:
            search_for_athletes_by_coach_categories();
            break;
        case 5:
            search_for_athletes_with_several_sports();
            break;
        case 6:
            search_for_an_athletes_by_sport_and_category();
            break;
        case 7:
            search_for_coaches_by_sport();
            break;
        case 8:
            search_for_athletes_who_did_not_participate_in_competitions();
            break;
        case 9:
            search_for_athletes_who_participated_in_competitions();
            break;
        case 0:
            break;
    }

}

#endif //MAIN_CPP_ATHLETE_CLASS_FUNCTIONS_H
