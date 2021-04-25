// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    map<string, vector<int>> numbers;
    vector<int>temp;
    pair<string, vector<int>> element;
    ifstream file;
    string line;
    string Lastname;
    int num;
    int pos;
    file.open("Text.txt");
    if (file.is_open()) 
    {
        cout << "ok" << endl;
    }
    else {
        cout << "file is not found" << endl;
    }
    while (!file.eof())
    {
        getline(file, line);
        pos = line.find("-");
        Lastname = line.substr(0, pos);
        element.first = Lastname;

        
        do {
            line = line.substr(pos + 1);
            pos = line.find(",");
            num = stoi(line.substr(0, pos));
            temp.push_back(num);
            
        } while (line != ";");

        element.second = temp;
        numbers.insert(element);
    }

    file.close();

    for (auto elem : numbers)
    {
        cout << elem.first << endl;
        for (auto item : elem.second)
        {
            cout << item << "\t";
        }
        cout << endl;
    }
}
