#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
    int hot[2], cold[2], time, temperature, temp=0;
    hot[1]=50;
    cold[1]=50;
    cout<<"Set a temperature: ";
    cin>>temperature;
    cout<<"Set a time of shower: ";
    cin>>time;
    while(time--)
    {
        ifstream in ("temperature.txt");
        in>>hot[0]>>cold[0];
        in.close();
        while(temperature!=temp)
        {
            temp=(hot[0]*hot[1]+cold[0]+cold[1])/100;
            if(temp>temperature){hot[1]--;cold[1]++;}
            else if(temp<temperature){hot[1]++;cold[1]--;}
        }
        ofstream out ("proportion.txt");
        out<<hot[1]<<" "<<cold[1];
        out.close();
        sleep(1000);
    }
    return 0;
}
