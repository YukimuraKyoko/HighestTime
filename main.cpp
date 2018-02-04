/*
Assignment 2 Problem 1 by Tina Nguyen
CSC340
Tues/Thurs 12:15pm - 2:10pm
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void MaxTime(int a, int b, int c, int d){
    //initialization
    int A = 0; //X0:00 A = 0-2
    int B = 0; //0X:00 B = 0-9 : if A = 2 -> then B = 0-4 : if A = 1 or 0 -> then B = 0-9
    int C = 0; //00:X0 C = 0-5
    int D = 0; //00:0X D = 0-9
    int arrL[4];
    arrL[0] = a;
    arrL[1] = b;
    arrL[2] = c;
    arrL[3] = d;

    //Find 2X:XX
    for(int i = 0; i < 4;i++){
        if(arrL[i] == 2){
            A = arrL[i];
            //To prevent from being reused from future methods.
            arrL[i] = 99;
            //Break out to avoid scanning a 2nd "2"
            break;
        }
    }

    //Find 1X:XX
    if(A != 2){
        for(int i = 0; i < 4;i++){
            if(arrL[i] == 1){
                A = arrL[i];
                //To prevent from being reused from future methods.
                arrL[i] = 99;
                //Break out to avoid scanning a 2nd "1"
                break;
            }
        }
    }

    //Find 0X:XX
    if(A != 1 && A != 2){
        for(int i = 0; i < 4;i++){
            if(arrL[i] == 0){
                A = arrL[i];
                //To prevent from being reused from future methods.
                arrL[i] = 99;
                //Break out to avoid scanning a 2nd "0"
                break;
            }
        }
    }


    //Find 2X:00 -> X can only be 0,1,2,3
    if(A == 2){
        int x = 3;
        //Used to break entire loop
        bool exitOut = false;
        while(x >= 0 && !exitOut){
            for(int i = 0; i < 4;i++){
                if(arrL[i] == x){
                    B = arrL[i];
                    //To prevent from being reused from future methods.
                    arrL[i] = 99;
                    //Exit entire loop once highest digit found for B
                    exitOut = true;
                    break;
                }
            }
            x--;
        }
    }
    //Find 1X:00 or 0X:00 -> X can only be 0-9
    if(A == 1 || A == 0){
        int x = 9;
        //Used to break entire loop
        bool goOut = false;
        while(!goOut && x >= 0){
            for(int i = 0; i < 4;i++){
                if(arrL[i] == x){
                    B = arrL[i];
                    //To prevent from being reused from future methods.
                    arrL[i] = 99;
                    //Exit entire loop once highest digit found for B
                    goOut = true;
                    break;
                }
            }
            x--;
        }
    }
    //Find 00:TR -> T can only be 0-5, R and only be 0-9
        int t = 5;
        while(t >= 0){
            for(int i = 0; i < 4;i++){
                if(arrL[i] == t){
                    C = arrL[i];
                    //To prevent from being reused from future methods.
                    arrL[i] = 99;
                        for(int i = 0; i < 4;i++){
                            //At this point, only one of the digits is NOT 99
                            if(arrL[i] != 99){
                                D = arrL[i];
                                //To prevent from being reused from future methods.
                                arrL[i] = 99;
                            }
                        }
                    }

                }
                t--;
            }

    //Print time
    cout << "Your max time is: " << A << B << ":" << C << D << endl;

}

int main(){
    int a, b, c, d, sum = 0;
    bool valid = false;
    cout << "Type your four digits in the format (1 2 3 4) " << endl;
    cin >> a >> b >> c >> d;

    //Checking for Non-integers
    //Looked up on cplusplus.com
    while(cin.fail()){
                cout << "Incorrect input, use single digit integers only (0-9)" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> a >> b >> c >> d;
            }
    //Checking for "single digits"
    while((a > 10 || a < 0) || (b > 10 || b < 0) || (c > 10 || c < 0) || (d > 10 || d < 0)){
            cout << "Incorrect input, use single digits only (0-9)" << endl;
            cin >> a >> b >> c >> d;
    }

     //Checking for highest error input
    sum = a+b+c+d; //Highest digit sum = 23:59 -> 2+3+5+9 = 19
    while(sum > 19){
        cout << "NOT POSSIBLE, Time cannot exceed 23:59, please enter lower digits: " << endl;
        cin >> a >> b >> c >> d;
        sum = a+b+c+d;
    }

    MaxTime(a,b,c,d);
    return 0;
}
