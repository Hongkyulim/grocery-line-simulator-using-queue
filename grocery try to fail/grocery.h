#ifndef grocery_h
#define grocery_h


//----------Cashiers-------------//

class firstCashier{
private:
    int checkTime1, checkTimeLeft1;
    //checkTime1 is for the time alloted to cashier to transact, checkTimeLeft1 is the time left.
public:
    firstCashier(int);
    void startCheckingOut1();
    void oneSecond1();
    bool firstCBusy(); //checking if the line is running or not.
};

class secondCashier{
private:
    int checkTime2, checkTimeLeft2;
public:
    secondCashier(int);
    void startCheckingOut2();
    void oneSecond2();
    bool secondCBusy();
};

class thirdCashier{
private:
    int checkTime3, checkTimeLeft3;
public:
    thirdCashier(int);
    void startCheckingOut3();
    void oneSecond3();
    bool thirdCBusy();
};

class forthCashier{
private:
    int checkTime4, checkTimeLeft4;
public:
    forthCashier(int);
    void startCheckingOut4();
    void oneSecond4();
    bool forthCBusy();
};

class fifthCashier{
private:
    int checkTime5, checkTimeLeft5;
public:
    fifthCashier(int);
    void startCheckingOut5();
    void oneSecond5();
    bool fifthCBusy();
};
 


//---------------For next customers----------//

class TimeForC{
private:
    int customerSum;
    double checkingTime; //A random amount of time for transaction.
    
public:
    int getCustomer();
    double getCheckingTime();
    void nextCustomer(double); //double is for the wait time
};
 

//------Probability for the customers randomly checking out------//

class Probability{
private:
    int prob = rand();
    
public:
    int getProb();
    bool query(); // determines whether a customer will be present for checking out.
};


bool pickShorterLine(long int, long int, long int, long int, long int); //If the priorLine is shortest, it returns true.
   
int randomTime(int* x);
























#endif /* grocery_h */
