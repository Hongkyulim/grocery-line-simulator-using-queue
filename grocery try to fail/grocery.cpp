#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <string>
#include "grocery.h"

using namespace std;

//----------Cashiers-------------//

//1st cashier

firstCashier::firstCashier(int time): checkTime1(time), checkTimeLeft1(0){
}

//checkTime1 is for the time alloted to cashier to transact, checkTimeLeft1 is the time left.
void firstCashier::startCheckingOut1(){
    checkTimeLeft1 = checkTime1;
}

void firstCashier::oneSecond1(){
    if(firstCBusy())
        checkTimeLeft1--;
}

bool firstCashier::firstCBusy(){
    return firstCashier::checkTimeLeft1>0;
}

//2nd cashier
secondCashier::secondCashier(int time): checkTime2(time), checkTimeLeft2(0){
}


void secondCashier::startCheckingOut2(){
     checkTimeLeft2 = checkTime2;
}

void secondCashier::oneSecond2(){
    if(secondCBusy())
        checkTimeLeft2--;
}

bool secondCashier::secondCBusy(){
    return secondCashier::checkTimeLeft2>0;
}

//3rd cashier
thirdCashier::thirdCashier(int time): checkTime3(time), checkTimeLeft3(0){
}

void thirdCashier::startCheckingOut3(){
    checkTimeLeft3 = checkTime3;
}

void thirdCashier::oneSecond3(){
    if(thirdCBusy())
        checkTimeLeft3--;
}

bool thirdCashier::thirdCBusy(){
    return thirdCashier::checkTimeLeft3>0;
}

//4th cashier
forthCashier::forthCashier(int time): checkTime4(time), checkTimeLeft4(0){
}

void forthCashier::startCheckingOut4(){
    checkTimeLeft4 = checkTime4;
}

void forthCashier::oneSecond4(){
    if(forthCBusy())
        checkTimeLeft4--;
}

bool forthCashier::forthCBusy(){
    return forthCashier::checkTimeLeft4>0;
}

//5th cashier
fifthCashier::fifthCashier(int time): checkTime5(time), checkTimeLeft5(0){
}

void fifthCashier::startCheckingOut5(){
    checkTimeLeft5 = checkTime5;
}

void fifthCashier::oneSecond5(){
    if(fifthCBusy())
        checkTimeLeft5--;
}

bool fifthCashier::fifthCBusy(){
    return fifthCashier::checkTimeLeft5>0;
}

//-------TimeForC--------//

int TimeForC::getCustomer(){
    return customerSum;
}

double TimeForC::getCheckingTime(){
    return checkingTime;
}

void TimeForC::nextCustomer(double TimeForNext){
    customerSum++;
    checkingTime +=TimeForNext;
}
 

//--------Probability----------//

int Probability::getProb(){
    return prob;
}

//determine wheter the next customer will be presented for transaction.
bool Probability::query(){
    return rand()<prob*RAND_MAX;
}

//--picking the shorter line--//
bool pickShorterLine(long int standard, long int nextLine1, long int nextLine2, long int nextLine3, long int nextLine4){ //If the priorLine is shorter, it returns true.
    if(standard<=nextLine1){
        if(standard<= nextLine2){
            if(standard<=nextLine3){
                if(standard<=nextLine4){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

//To assign random Time to wholecustomerLine
int randomTime(int* x){
    *x=0 +rand()%30;
    return *x;
}

















