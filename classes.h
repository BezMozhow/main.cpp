//
// Created by Сергій on 3/30/2022.
//

#ifndef COURSWORK_SCHOLLE_CLASSES_H
#define COURSWORK_SCHOLLE_CLASSES_H


class SportsFacilities{
private:
    string name;
    string category;
    int area;
    int number_of_seats;
    string availability_of_buffets;
    string availability_of_toilets;
public:
/*Сетери*/
    void set_name (string name){this->name = name;}
    void set_category (string category){this->category = category;}
    void set_area (int area){this->area = area;}
    void set_number_of_seats (int number_of_seats){this->number_of_seats = number_of_seats;}
    void set_availability_of_buffets (string availability_of_buffets){this->availability_of_buffets = availability_of_buffets;}
    void set_availability_of_toilets (string availability_of_toilets){this->availability_of_toilets = availability_of_toilets;}

/*Гетери*/

    string get_name (){return name;}
    string get_category (){return category;}
    int get_area (){return area;}
    int get_number_of_seats (){return number_of_seats;}
    string get_availability_of_buffets (){return availability_of_buffets;}
    string get_availability_of_toilets (){return availability_of_toilets;}

    void output_info_about_sports_facilities(int num){


        cout << "------------------------- Споруда *" << num << "*-------------------------" << endl
                <<"Назва споруди: " << name << endl
                <<"Категорія: " << category << endl
                <<"Площа: " << area << endl
                <<"Кількість сидячих мість: " << number_of_seats << endl
                <<"Наявний буфет: " << availability_of_buffets << endl
                <<"Наявний туалет: " << availability_of_toilets << endl;

    }

    void default_values_for_input(){

        cout << "Введіть назву спортивної споруди" << endl;
        cin.ignore();
        getline(cin, name);

        cout << "Введіть площу спортивної споруди" << endl;
        cin >> area;

        cout << "Введіть кількість сидячих мість" << endl;
        cin >> number_of_seats;

        cout << "Чи наявний туaлет?(Yes або No)" << endl;
        cin >> availability_of_toilets;

        cout << "Чи наявний буфет?(Yes або No)" << endl;
        cin >> availability_of_buffets;

    }


};


class Pool : public SportsFacilities{

private:

    int number_of_springboards;
    int the_length_of_the_pool;
    int depth_of_the_pool;
    string the_presence_of_a_bath;


public:
/*Сетери*/
    void set_number_of_springboards (int number_of_springboards){this->number_of_springboards = number_of_springboards;}
    void set_the_length_of_the_pool (int the_length_of_the_pool){this->the_length_of_the_pool = the_length_of_the_pool;}
    void set_depth_of_the_pool (int depth_of_the_pool){this->depth_of_the_pool = depth_of_the_pool;}
    void set_the_presence_of_a_bath (string the_presence_of_a_bath){this->the_presence_of_a_bath = the_presence_of_a_bath;}

/*Гетери*/

    int get_number_of_springboards(){return number_of_springboards;}
    int get_the_length_of_the_pool(){return the_length_of_the_pool;}
    int get_depth_of_the_pool(){return depth_of_the_pool;}
    string get_the_presence_of_a_bath(){return the_presence_of_a_bath;}

    void output_info_about_pool(int num){

        output_info_about_sports_facilities(num);


        cout << "Довжина басейну: " << the_length_of_the_pool << endl
                << "Глюбина басейну: " << depth_of_the_pool << endl
                << "Наявні душові: " << the_presence_of_a_bath << endl
                << "Кількість трамплінів: " << number_of_springboards << endl;

    }

};


class TennisCourt : public SportsFacilities{
private:
    string coating;

public:
    /*Стери*/
    void set_coating(string coating){this->coating = coating;}

    /*Гетери*/
    string get_coating(){return coating;}

    void output_info_about_tennis_court(int num){


        output_info_about_sports_facilities(num);

        cout << "Покриття: " << coating << endl;


    }
};


class ShootingGallery : public SportsFacilities{
private:

int number_of_weapons;
int weapon_rack;
int max_distance_to_targets;
int min_distance_to_targets;

public:
/*Сетери*/

    void set_number_of_weapons (int number_of_weapons){this->number_of_weapons = number_of_weapons;}
    void set_weapon_rack (int weapon_rack){this->weapon_rack = weapon_rack;}
    void set_max_distance_to_targets (int max_distance_to_targets){this->max_distance_to_targets = max_distance_to_targets;}
    void set_min_distance_to_targets (int min_distance_to_targets){this->min_distance_to_targets = min_distance_to_targets;}

/*Гетери*/
    int get_number_of_weapons (){return number_of_weapons;}
    int get_weapon_rack (){return weapon_rack;}
    int get_max_distance_to_targets (){return max_distance_to_targets;}
    int get_min_distance_to_targets (){return min_distance_to_targets;}

    void output_info_about_shooting_gallery (int num){

        output_info_about_sports_facilities(num);

        cout <<"Кількість зброї: " << number_of_weapons << endl
             <<"Кількість стійок для зброї: " << weapon_rack << endl
             <<"Максимальна дистанція до мішені: " << max_distance_to_targets << endl
             <<"Мінімальна дистанція до мішені: " << min_distance_to_targets << endl;

    }



};


class FootballField : public SportsFacilities{

private:
    string coating;
    int width;
    int length;
public:

    /*Стери*/
    void set_coating(string coating){this->coating = coating;}
    void set_width (int width){this->width = width;}
    void set_length (int length){this->length = length;}
    /*Гетери*/
    string get_coating(){return coating;}
    int get_width(){return width;}
    int get_length(){return length;}

    void output_info_about_football_field (int num){

        output_info_about_sports_facilities(num);

        cout <<"Покриття: " << coating << endl
             <<"Довжина поля: " << length << endl
             <<"Ширина поля: " << width << endl;

    }

};









class Sportsman {

private:
    string name, sport_club;

    vector<string> kinds_of_sport;
    vector<string> category;
    vector<string> coaches;
    vector<string> coach_categories;
    vector<string> competition;
    vector<tm> date_of_the_competition;


public:

    Sportsman(){

    }

    Sportsman(string name, string sport_club,  vector<string> kinds_of_sport, vector<string> category, vector<string> coaches, vector<string> coach_categories, vector<string> competition, vector<tm> date_of_the_competition){

        set_name_of_sportsman(name);
        set_sport_club(sport_club);

        for (int i = 0; i < kinds_of_sport.size(); ++i) {
            set_kinds_of_sport(kinds_of_sport[i]);
            set_category(category[i]);
            set_coaches(coaches[i]);
            set_coach_categories(coach_categories[i]);

        }

        for (int i = 0; i < competition.size(); ++i) {
            set_competition(competition[i]);
            set_date_of_the_competition(date_of_the_competition[i]);

        }


    }




/*Сетери*/
    void set_name_of_sportsman(string name){this->name = name;}
    void set_sport_club(string sport_club){this->sport_club = sport_club;}
    void set_kinds_of_sport(string kinds_of_sport){this->kinds_of_sport.push_back(kinds_of_sport);}
    void set_category( string category){this->category.push_back(category);}
    void set_coaches(string coaches){this->coaches.push_back(coaches);}
    void set_coach_categories(string coach_categories){this->coach_categories.push_back(coach_categories);}
    void set_competition(string competition){this->competition.push_back(competition);}
    void set_date_of_the_competition(tm date_of_the_competition){this->date_of_the_competition.push_back(date_of_the_competition);}


    /*Гетери*/

    string get_name(){return name;}
    string get_sport_club(){return sport_club;}
    vector<string> get_kinds_of_sport(){return kinds_of_sport;}
    vector<string> get_category(){return category;}
    vector<string> get_coaches(){return coaches;}
    vector<string> get_coach_categories(){return coach_categories;}
    vector<string> get_competition(){return competition;}
    vector<tm> get_date_of_the_competition(){return date_of_the_competition;}

    void output_info_about_sportsman(int i=0){

        cout << "-----------------------------Спортсмен *"<< i + 1 << "*--------------------------------" << endl ;
        cout << "Ім'я спортсмена: " <<                        name << endl;
        cout << "Спортивний клуб: " << sport_club << endl;

        for (int j = 0; j < kinds_of_sport.size(); ++j) {

            cout << "--------"<< j + 1 << "--------"<< endl <<  "--Вид спорту: |" << kinds_of_sport[j]<<"|"<<endl
                 << "-Категорія спортсмена: " << category[j] << endl
                 << "--Тренер: " << coaches[j] << endl
                 << "-Категорія тренера : " << coach_categories[j] << endl;

        }


        for (int j = 0; j < competition.size(); ++j) {
            cout << "```````````````````````````````````````````````````````````````````````````" << endl;
            cout << "Змагання " << j + 1 << "   "<< competition[j] << ":           " << "дата проведення: "<< date_of_the_competition[j].tm_mday << "/" <<date_of_the_competition[j].tm_mon + 1 << "/" << date_of_the_competition[j].tm_year <<endl ;
       }
        cout << endl;
    }

    void change_category(string category, int index){this->category[index] = category;}
    void change_coaches(string coaches, int index){this->coaches[index] = coaches;}
};





class Competition{
private:

    string name, venue, organizer, kind_of_sport;
    vector<string> winners, participants;
    tm date_of_the_event;

public:

    Competition(){}

    Competition(string name, string venue, string organizer, string kind_of_sport, vector<string> winners, vector<string> participants, tm date_of_the_event){
        this-> name = name;
        this->venue = venue;
        this->organizer = organizer;
        this->kind_of_sport = kind_of_sport;
        this->winners = winners;
        this->participants = participants;
        this->date_of_the_event = date_of_the_event;
    }



    /*Сетери*/
    void set_name(string name){this->name = name;}
    void set_venue(string venue){this->venue = venue;}
    void set_organizer(string organizer){this->organizer = organizer;}
    void set_winners( string winners){this->winners.push_back(winners);}
    void set_participants(string participants){this->participants.push_back(participants);}
    void set_date_of_the_event(tm date_of_the_event){this->date_of_the_event = date_of_the_event;}

    /*Гетери*/

    string get_name(){return name;}
    string get_venue(){return venue;}
    string get_organizer(){return organizer;}
    string get_kind_of_sport(){return kind_of_sport;}
    vector<string> get_winners(){return winners;}
    vector<string> get_participants(){return participants;}
    tm get_date_of_the_event(){return date_of_the_event;}


    void output_info_about_competition(int i=0){
        cout << "-----------------------------Змагання *"<< i + 1 << "*--------------------------------" << endl ;
        cout << "-Назва події:" <<name << endl;
        cout << "~~Місце проведення: " << venue << endl;
        cout << "-Дата проведення: " << date_of_the_event.tm_mday << "/" <<date_of_the_event.tm_mon + 1 << "/" << date_of_the_event.tm_year <<endl ;
        cout << "~~Організатор: " << organizer << endl;
        cout << "-Вид спорут з якого проводилося змагання: " << kind_of_sport << endl;

        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "|Переможці|" << endl;
        for (int j = 0; j < winners.size(); ++j) {

            cout <<"--" << j << ": " << winners[j] << endl;
        }
        cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "|Учасники|" << endl;
        for (int j = 0; j < participants.size(); ++j) {

            cout <<"--" << j << ": " << participants[j] << endl;
        }




    };

};




















#endif //COURSWORK_SCHOLLE_CLASSES_H
