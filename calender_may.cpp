#include<iostream>
#include<cmath>
using namespace std;

int main ()
{
    int year = 2020, start_day, type = 1, n_days, month(1);
    cout << " The year  2020 " << endl;
    


    start_day = 4;

    bool flag = false;
    while (month <= 12)
    {
    switch (month)
    {
        case 1:
            //cout << "\n\nJanuary\n" << endl;
            n_days = 31;
            break;
        case 2:
            //cout << "\n\nFebruary\n" << endl;
            if (type = 1)
            {
                n_days = 29;
            }
            else
            {
                n_days = 28;
            }
            break;
        case 3:
            //cout << "\n\nMarch\n" << endl;
            n_days = 31;
            break;
        case 4:
            //cout << "\n\nApril\n" << endl;
            n_days = 30;
            break;
        case 5:
            cout << "\n\nMay\n" << endl;
            n_days = 31;
            flag = true;
            break;
        case 6:
            //cout << "\n\nJune\n" << endl;
            n_days = 30;
            break;
        case 7:
            //cout << "\n\nJuly\n" << endl;
            n_days = 31;
            break;
        case 8:
            //cout << "\n\nAugust\n" << endl;
            n_days = 31;
            break;
        case 9:
            //cout << "\n\nSeptember\n" << endl;
            n_days = 30;
            break;
        case 10:
            //cout << "\n\nOctober" << endl;
            n_days = 31;
            break;
        case 11:
            //cout << "\n\nNovember" << endl;
            n_days = 30;
            break;
        case 12:
            //cout << "\n\nDecember\n" << endl;
            n_days = 31;
            break;
        default:
            ;
    }
    
    if(flag) cout << endl << "Sun\tMon\tTue\tWed\tThr\tFri\tSat\n"; 
    for (int i = 1;flag && i < start_day; i++) 
    { 
        cout << " \t"; 
    } 
    for (int j = 1; flag && j <= n_days; j++) 
    { 
    if ( ((j + start_day - 2) % 7 == 0) && (j != 1)) 
        cout << endl; 
        cout << j  << "\t"; 
    } 

    start_day = (n_days + start_day - 1) % 7 + 1;

    if(flag)cout << endl << endl; 

    month++;
    if(flag) flag = false;

    }


    return 0;
}