//
// Created by Сергій on 5/28/2022.
//

#ifndef MAIN_CPP_COMPETITION_CLASS_FUNCTION_H
#define MAIN_CPP_COMPETITION_CLASS_FUNCTION_H


void random_competition(){

    string r_name,r_name_of_event, kind_of_sport, r_name_of_organizer, r_kind_of_sport, r_venue, r_name_winner, r_name_participants;
    vector<string> r_vector_name_of_event, r_vector_set_venue, r_winners, r_participants,r_vector_set_of_names, r_vector_set_of_lastnames, r_vector_set_of_surnames, r_vector_set_of_sports;
    tm r_date_of_the_event;

    int r_number=0, r_counter = 100;;
    r_vector_set_of_names = {"Aleksandr","Aleksei","Anatolii","Andrei","Anton","Arsenij","Artem","Boris","Vadim","Evgenii","Nikolay"};
    r_vector_set_of_lastnames = {"Kozlov","Petrov","Ivanov","Sinitsyn","Karelin","Kuzmenko","Fedoruk","Pavlenko","Katrushin","Lesovay","Korolyov","Tatarchu"};
    r_vector_set_of_surnames = {"Pavlovich","Sergeevich","Konstantinovich","Grigorevich","Artemovich","Borisovich","Vadimovich"};

    r_vector_name_of_event = {"Health","For life","Against poverty","For the share","No obesity","Sports Olympiad","Ladybug"};

    r_vector_set_venue = {"Hoverla","PNU-Ivano-Frankivsk","Stanislaviv","Golden dragon","Hero","Ivano-Frankivsk City Basketball Federation","Ivano-Frankivsk City Federation of Olympic Taekwondo (WTF)"};

    r_vector_set_of_sports = {"Swimming","Canoe Sprint","Football","Golf","Judo","Rowing","Taekwondo","Weightlifting","Gymnastics",};

    srand( time(NULL) );
    for (int i = 0; i < r_counter; ++i) {


        /*Рандомні переможці*/

        r_number = 3;

        for (int j = 0; j < r_number; ++j) {
            r_name_winner = r_vector_set_of_names[rand() % r_vector_set_of_names.size()] + " " + r_vector_set_of_lastnames[rand() % r_vector_set_of_lastnames.size()] + " " + r_vector_set_of_surnames[rand() % r_vector_set_of_surnames.size()];
            r_winners.push_back(r_name_winner);
        }
        /*Рандомні учасники*/

        r_number = rand() % 20 +7 ;
        for (int j = 0; j < r_number; ++j) {

            r_name = r_vector_set_of_names[rand() % r_vector_set_of_names.size()] + " " + r_vector_set_of_lastnames[rand() % r_vector_set_of_lastnames.size()] + " " + r_vector_set_of_surnames[rand() % r_vector_set_of_surnames.size()];
            r_participants.push_back(r_name);

        }

        /*Рандомна подія*/
        r_name_of_event = r_vector_name_of_event[rand()%r_vector_name_of_event.size()];

        /*Рандомний організатор*/
        r_name_of_organizer = r_vector_set_of_names[rand() % r_vector_set_of_names.size()] + " " + r_vector_set_of_lastnames[rand() % r_vector_set_of_lastnames.size()] + " " + r_vector_set_of_surnames[rand() % r_vector_set_of_surnames.size()];

        /*Рандомний вид спорту*/
        r_kind_of_sport = r_vector_set_of_sports[rand() % r_vector_set_of_sports.size()];

        /*Рандомна дата проведення*/
        r_date_of_the_event.tm_mday = rand() % 30 + 1;
        r_date_of_the_event.tm_mon = rand() % 11;
        r_date_of_the_event.tm_year = rand() % 52 + 1970;

        /*Рандомне місце проведення*/
        r_venue = r_vector_set_venue[rand() % r_vector_set_venue.size()];

        Competition r_competition(r_name_of_event, r_venue, r_name_of_organizer, r_kind_of_sport, r_winners, r_participants, r_date_of_the_event);
        competition_database.push_back(r_competition);





        r_winners.clear();
        r_participants.clear();

    }







};

void output_competitions(){

    cout << endl <<"Вивід спортивних змагань" << endl << endl;

    for (int i = 0; i < competition_database.size(); ++i) {
        competition_database[i].output_info_about_competition(i);
    }
    system("pause");

}

void add_competition(){
    Competition competition;

    int a_c_num;
    string name, venue, organizer, winner,participants,kind_of_sport;
    tm date_of_the_event;

    cout << "|*|*|Додавання спортивної події|*|*|"<<endl;

    cout << "Введіть назву події: "<<endl;
    cin.ignore();
    getline(cin, name);
    competition.set_name(name);

    cout << "Введіть місце проведення : "<<endl;
    getline(cin, venue);
    competition.set_venue(venue);

    cout << "Вид спорту з якого проводилися змагання: "<<endl;
    getline(cin, kind_of_sport);
    competition.set_venue(kind_of_sport);

    cout << "Введіть організатора: "<<endl;
    getline(cin, organizer);
    competition.set_organizer(organizer);

    cout << "Скільки призерів змагання? "<<endl;
    cin>> a_c_num;

    cout << "Введіть імена, прізвища і по батькові призерів"<<endl;
    for (int i = 0; i < a_c_num; ++i) {
        cout << "Призер " << i << ": ";
        cin.ignore();
        getline(cin, winner);

        competition.set_winners(winner);

    }

    cout << "Скільки учасників змагання? "<<endl;
    cin >> a_c_num;
    cout << "Введіть імена, прізвища і по батькові спортсменів які брали учать у спортивні події"<<endl;
    for (int i = 0; i < a_c_num; ++i) {
        cout << "Учасник " << i << ": ";
        cin.ignore();
        getline(cin, participants);

        competition.set_participants(participants);

    }

    cout << "Введіть дату проведення події "<<endl;
    cout << "Рік: "<<endl;
    cin >> date_of_the_event.tm_year;

    cout << "Номер місяця "<<endl;
    cin >> date_of_the_event.tm_mon;

    cout << "День "<<endl;
    cin >> date_of_the_event.tm_mday;

    competition.set_date_of_the_event(date_of_the_event);

    competition_database.push_back(competition);

    cout << "Подію успішно додано" << endl;
    system("pause");

}

void search_for_organizer(){
    string s_organizer;
    cout << "|*|*|Пошук змагання за організатором|*|*|" << endl << endl;

    cout << "Введіть організатора за яким ви хочете здійснити пошук" << endl;

    cin.ignore();
    getline(cin, s_organizer);

    for (int i = 0; i < competition_database.size(); ++i) {

        if (competition_database[i].get_organizer() == s_organizer){

            competition_database[i].output_info_about_competition(i);

        }

    }
    system("pause");

}

void search_by_date(){

    cout << "|*|*|Пошук змагання в проміжку часу|*|*|" << endl << endl;

    struct tm start_date, end_date;
    int start_in_days, end_in_days;

    cout << "|*|*|Пошук по періоду часу(по рокам)|*|*|"  << endl << endl;

    cout << "*|Введіть дату від якої має вестися пошук|*" << endl;

    cout << "Введіть рік: " ;
    cin >> start_date.tm_year;

    cout << "Введіть місяць(число): " ;
    cin >> start_date.tm_mon;

    cout << "Введіть день місяця: " ;
    cin >> start_date.tm_mday;

    cout << endl << "*|Введіть дату до якої має здійснюватися пошук|*" << endl;

    cout << "Введіть рік: " ;
    cin >> end_date.tm_year;

    cout << "Введіть місяць(число): " ;
    cin >> end_date.tm_mon;

    cout << "Введіть день місяця: " ;
    cin >> end_date.tm_mday;

    start_in_days = date_in_days(start_date);
    end_in_days = date_in_days(end_date);

    cout << endl << "Дати між " << start_date.tm_mday <<"/"<< start_date.tm_mon <<"/"<< start_date.tm_year<< " i " << end_date.tm_mday <<"/"<< end_date.tm_mon <<"/"<< end_date.tm_year << endl;


    for (int i = 0; i < competition_database.size(); ++i) {
        if ( start_in_days <= date_in_days(competition_database[i].get_date_of_the_event()) &&
             date_in_days(competition_database[i].get_date_of_the_event()) <= end_in_days ){

            competition_database[i].output_info_about_competition(i);
        }
    }

    system("pause");
}

void search_of_winners_of_competition(){
    string s_name;

    cout << "|*|*|Пошук переможнів в змаганні|*|*|" << endl << endl;

    cout << "Введіть назву змагання" << endl;

    cin.ignore();
    getline(cin, s_name);

    for (int i = 0; i < competition_database.size(); ++i) {

        if (competition_database[i].get_name() == s_name){
            cout << "-----------------------------Змагання *"<< i + 1 << "*--------------------------------" << endl ;

            cout << "Назва змагання: "<<competition_database[i].get_name() << endl;
            cout << "-Дата проведення: " << competition_database[i].get_date_of_the_event().tm_mday << "/" <<competition_database[i].get_date_of_the_event().tm_mon + 1 << "/" << competition_database[i].get_date_of_the_event().tm_year <<endl ;
            cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout << "|Переможці|" << endl;
            for (int j = 0; j < competition_database[i].get_winners().size(); ++j) {
                cout <<"--" << j << ": " << competition_database[i].get_winners()[j] << endl;
            }
        }

    }
    system("pause");
}

void search_for_competitions_in_sports_facilities(){

    string s_venue;

    cout << "|*|*|Пошук змагання по спортивній споруді|*|*|" << endl << endl;

    cout << "Введіть спортивну споруду"<< endl;
    cin.ignore();
    getline(cin, s_venue);

    for (int i = 0; i < competition_database.size(); ++i) {

        if (competition_database[i].get_venue() == s_venue){
            competition_database[i].output_info_about_competition(i);
        }

    }
    system("pause");
}

void search_for_competitions_in_sports(){

    string s_sport;

    cout << "|*|*|Пошук змагання по виду спорту|*|*|" << endl<< endl;

    cout << "Введіть вид спорту" << endl;

    cin.ignore();
    getline(cin, s_sport);

    for (int i = 0; i < competition_database.size(); ++i) {

        if (competition_database[i].get_kind_of_sport() == s_sport){
            competition_database[i].output_info_about_competition(i);
        }

    }
    system("pause");
}

void organizers_and_number_of_competitions(){
    tm start_date, end_date;
    int start_in_days, end_in_days, counter;

    vector<string> v_organizers;
    vector<int> v_number;


    cout <<  "|*|*|Дізнатися список організаторів і кількість проведених ними змагань протягом періоду часу|*|*|" << endl<< endl;

    cout << "*|Введіть дату від якої має вестися пошук|*" << endl;

    start_date = entering_the_date();

    cout<< endl  << "*|Введіть дату до якої має здійснюватися пошук|*" << endl;

    end_date = entering_the_date();

    start_in_days = date_in_days(start_date);
    end_in_days = date_in_days(end_date);

    for (int i = 0; i < competition_database.size(); ++i) {

        if (start_in_days <= date_in_days(competition_database[i].get_date_of_the_event()) &&
            date_in_days(competition_database[i].get_date_of_the_event()) <= end_in_days){



            for (int j = 0; j < v_organizers.size(); ++j) {

                if (competition_database[i].get_organizer() == v_organizers[j]){
                    v_number[j]++;
                    counter++;
                    break;
                }

            }
            if (counter == 0 || v_organizers.size() == 0){
                v_organizers.push_back(competition_database[i].get_organizer());
                v_number.push_back(1);
                counter =0;
            }


        }
    }

    cout << endl << "Дати між " << start_date.tm_mday <<"/"<< start_date.tm_mon <<"/"<< start_date.tm_year<< " i " << end_date.tm_mday <<"/"<< end_date.tm_mon <<"/"<< end_date.tm_year << endl;

    for (int i = 0; i < v_organizers.size(); ++i) {

        cout <<"Ім'я орнагізатора: "<< v_organizers[i] << " -кількість проведених змагань: " << v_number[i] << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;


    }

    system("pause");
}

void search_for_sports_facilities_and_dates_of_competitions_on_them(){

    tm start_date, end_date;
    int start_in_days, end_in_days, counter;

    vector<string> v_venue;

    cout <<  "|*|*|Дізнатися спортивні споруди і дати проведення на них замагань протягом періоду часу|*|*|" << endl<< endl;

    cout << "*|Введіть дату від якої має вестися пошук|*" << endl;

    start_date = entering_the_date();

    cout << endl<< "*|Введіть дату до якої має здійснюватися пошук|*"  << endl;

    end_date = entering_the_date();

    start_in_days = date_in_days(start_date);
    end_in_days = date_in_days(end_date);

    cout << endl << "Дати між " << start_date.tm_mday <<"/"<< start_date.tm_mon <<"/"<< start_date.tm_year<< " i " << end_date.tm_mday <<"/"<< end_date.tm_mon <<"/"<< end_date.tm_year << endl;

    for (int i = 0; i < competition_database.size(); ++i) {

        for (int j = 0; j < v_venue.size(); ++j) {


            if (v_venue[j] == competition_database[i].get_venue()){
                counter = counter + 2;
                break;

            }
        }
        if (counter>0){counter =0;continue;}

        v_venue.push_back(competition_database[i].get_venue());

        cout << "Спортивна споруда: " << competition_database[i].get_venue() << endl;
        cout << "Дати проведення" << endl;

        for (int j = i; j < competition_database.size(); ++j) {


            if (competition_database[i].get_venue() == competition_database[j].get_venue() && start_in_days <= date_in_days(competition_database[j].get_date_of_the_event()) &&
                date_in_days(competition_database[j].get_date_of_the_event()) <= end_in_days) {

                cout << "--" << competition_database[j].get_date_of_the_event().tm_mday << "/" << competition_database[j].get_date_of_the_event().tm_mon << "/"<< competition_database[j].get_date_of_the_event().tm_year << endl;

            }

        }
        cout << "-----------------------------------------------"<<endl;


    }

    system("pause");

}

void menu_search_for_sports_competitions(){
    int selected_number;

    cout << "Пошук спортивних змагань" << endl
        << "1. Пошук змагання за організатором" << endl
        << "2. Пошук змагання в проміжку часу" << endl
        << "3. Пошук переможців у змаганні" << endl
        << "4. Пошук змагання по спортивній споруді" << endl
        << "5. Пошук змагання по виду спорту" << endl
        << "6. Дізнатися список організаторів і кількість проведених ними змагань протягом періоду часу" << endl
        << "7. Дізнатися спортивні споруди і дати проведення на них замагань протягом періоду часу" << endl
        << "0. Вийти" << endl;

    cout << "Введіть дію яку хочете виконати" << endl;
    cin >> selected_number;

    switch (selected_number) {
        case 1:
            search_for_organizer();
            break;
        case 2:
            search_by_date();
            break;
        case 3:
            search_of_winners_of_competition();
            break;
        case 4:
            search_for_competitions_in_sports_facilities();
            break;
        case 5:
            search_for_competitions_in_sports();
            break;
        case 6:
            organizers_and_number_of_competitions();
            break;
        case 7:
            search_for_sports_facilities_and_dates_of_competitions_on_them();
            break;
        case 0:
            break;
    }

}
#endif //MAIN_CPP_COMPETITION_CLASS_FUNCTION_H
