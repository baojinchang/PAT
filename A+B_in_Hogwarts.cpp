#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int time1_Galleon, time1_Sickle, time1_Knut;
    int time2_Galleon, time2_Sickle, time2_Knut;
    scanf("%d.%d.%d %d.%d.%d", &time1_Galleon, &time1_Sickle, &time1_Knut, &time2_Galleon, &time2_Sickle, &time2_Knut);
    int count = 0;
    int Galleon, Sickle, Knut;
    Knut = (time1_Knut + time2_Knut) % 29;
    count = (time1_Knut + time2_Knut) / 29;
    Sickle = (time1_Sickle + time2_Sickle + count) % 17;
    count = (time1_Sickle + time2_Sickle + count) / 17;
    Galleon = time1_Galleon + time2_Galleon + count;
    cout << Galleon << "." << Sickle << "." << Knut;

    return 0;
}