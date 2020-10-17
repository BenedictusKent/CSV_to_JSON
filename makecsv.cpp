#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdlib>
#include<string>
#include<ctime>
using namespace std;

int main() 
{
    int FILE_SIZE;
    string unit;
    string name;
    cout << "Input desired file size: ";
    cin >> FILE_SIZE >> unit;
    cout << "Input csv file name: ";
    cin >> name;
    
    transform(unit.begin(), unit.end(), unit.begin(), ::tolower);
    if(unit.compare("gb") == 0){
        FILE_SIZE *= 1000000000;
    }
    else if(unit.compare("gb") == 0){
        FILE_SIZE *= 1000000;
    }
    else if(unit.compare("kb") == 0){
        FILE_SIZE *= 1000;
    }
    else if(unit.compare("b") == 0){
        ;
    }

    ofstream outfile;
    outfile.open(name);

    const int MAX = 2147483647;
    int counter, random, sign, size=0;
    string text;

    srand(time(0));

    while(true)
    {
        counter = 0;
        while(counter != 20)
        {
            // randomizer
            random = rand() % MAX;
	        sign = rand() % 2;
            if(sign == 1)
                random *= -1;

            // append string
            text.append(to_string(random));
            if(counter < 19)
                text.append("|");

            // add counter
            ++counter;
        }

        size += text.length();
        if(size <= FILE_SIZE)
        {
            outfile << text << "\n";
            text.clear();
            size += 1;
        }
        else
        {
            outfile << text;
            cout << size << endl;
            break;
        }
    }
        
    outfile.close();

    return 0;
}
