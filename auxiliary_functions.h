//
// Created by Сергій on 3/30/2022.
//
#include "libraries.h"

#ifndef COURSWORK_SCHOLLE_AUXILIARY_FUNCTIONS_H
#define COURSWORK_SCHOLLE_AUXILIARY_FUNCTIONS_H


int category_number(string cat){

    if (cat == "The first youth category"){
        return 1;
    } else if(cat == "The second youth category"){
        return 2;
    }else if(cat == "The third youth category"){
        return 3;
    }else if(cat == "The first category"){
        return 4;
    }else if(cat == "The second category"){
        return 5;
    }else if(cat == "The third category"){
        return 6;
    }else if(cat == "Candidate for Master of Sports of Ukraine"){
        return 7;
    }else if(cat == "Master of Sports of Ukraine" || cat == "Honored Coach of Ukraine"){
        return 8;
    }else{
        return 100;
    }


}

string number_to_category(int num){

    if (num == 1){
        return "The first youth category";
    }else if(num == 2){
        return "The second youth category";
    }else if(num == 3){
        return "The third youth category";
    }else if(num == 4){
        return "The first category";
    }else if(num == 5){
        return "The second category";
    }else if(num == 6){
        return "The third category";
    }else if(num == 7){
        return "Candidate for Master of Sports of Ukraine";
    }else if(num == 8){
        return "Master of Sports of Ukraine" ;
    }else if(num == 9){
        return "Honored Coach of Ukraine" ;
    }else {
        return "Incorrect data, try again";
    }

}






#endif //COURSWORK_SCHOLLE_AUXILIARY_FUNCTIONS_H
