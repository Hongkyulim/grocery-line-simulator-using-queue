#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <string>
#include "grocery.h"

using namespace std;


int main(){
    
    srand(time_t(NULL));
    queue<int>wholecustomerLine;
    queue<int>Line1;
    queue<int>Line2;
    queue<int>Line3;
    queue<int>Line4;
    queue<int>Line5;
    int NoOfCustomers; //Time alloted to cashier to transact a customer
    int i; //to make randomTime fit into firstCashier
    int totalTimeInMinutes =0; //to show the total time in minutes for the procedure
   
    firstCashier F1(randomTime(&i));
    secondCashier F2(randomTime(&i));
    thirdCashier F3(randomTime(&i));
    forthCashier F4(randomTime(&i));
    fifthCashier F5(randomTime(&i));
       
    cout<<"How many customers are there? : ";
    cin>>NoOfCustomers;
    
    for( i = 1; i<=NoOfCustomers; i++){
        wholecustomerLine.push(randomTime(&i));
    }
    
    while(!wholecustomerLine.empty()){
        //--1 chashier
        if(pickShorterLine(Line1.size(), Line2.size(), Line3.size(), Line4.size(), Line5.size())){
            Line1.push(wholecustomerLine.front());
            wholecustomerLine.pop();
            
        LOOP1:
            if(!F1.firstCBusy()){
                F1.startCheckingOut1(); //time is assigned
                F1.oneSecond1();   //leftTime is consumed
                totalTimeInMinutes += Line1.front();
                Line1.pop();  //Customer finished is out from the Line1.
            }
            else{
                goto LOOP1;
            }
        }
        
        //--2 cashier
        else if(pickShorterLine(Line2.size(), Line1.size(), Line3.size(), Line4.size(), Line5.size())){
            Line2.push(wholecustomerLine.front());
            wholecustomerLine.pop();
        LOOP2:
            if(!F2.secondCBusy()){
                F2.startCheckingOut2();
                F2.oneSecond2();
                totalTimeInMinutes += Line2.front();
                Line2.pop();
            }
            else{
                goto LOOP2;
            }
        }
        
        else if(pickShorterLine(Line3.size(), Line1.size(), Line2.size(), Line4.size(), Line5.size())){
            Line3.push(wholecustomerLine.front());
            wholecustomerLine.pop();
        LOOP3:
            if(!F3.thirdCBusy()){
                
                F3.startCheckingOut3();
                F3.oneSecond3();
                totalTimeInMinutes += Line3.front();
                Line3.pop();
            }
            else{
                goto LOOP3;
            }
        }
        
        else if(pickShorterLine(Line4.size(), Line1.size(), Line2.size(), Line3.size(), Line5.size())){
            Line4.push(wholecustomerLine.front());
            wholecustomerLine.pop();
        LOOP4:
            if(!F4.forthCBusy()){
                F4.startCheckingOut4();
                F4.oneSecond4();
                totalTimeInMinutes += Line4.front();
                Line4.pop();
            }
            else{
                goto LOOP4;
            }
        }
        else if(pickShorterLine(Line5.size(), Line1.size(), Line2.size(), Line3.size(), Line4.size())){
            Line5.push(wholecustomerLine.front());
            wholecustomerLine.pop();
        LOOP5:
            if(!F5.fifthCBusy()){
                F5.startCheckingOut5();
                F5.oneSecond5();
                totalTimeInMinutes += Line5.front();
                Line5.pop();
            }
            else{
                goto LOOP5;
            }
        }
        else{
            cout<<"error------1"<<endl;
        }
    }
    
    cout<<"The time consumed for transaction of "<<NoOfCustomers<<" is "<<totalTimeInMinutes<<" minutes."<<endl;
    
    return 0;
}






