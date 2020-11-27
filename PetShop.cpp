/***************************************
It's an easy pet shop system from swee.
***************************************/
#include <iostream>
#include <string>
#include "PetShop.h"
#include <stdlib.h>
using namespace std;

Shop QMPets;

void ClearScreen()
{
    if (system("CLS"))
        system("clear");
}

void SearchByType()
{
    cout << "\nPlease enter the type(Bird/Cat/Dog):" << endl;
    string type;
    cin >> type;
    while (type != "Bird" && type != "Cat" && type != "Dog")
    {
        cout << "\nNo such type,please retry:" << endl;
        cin >> type;
    }
    QMPets.SearchByType(type);
    system("Pause");
}

void SearchById()
{
    cout << "\nPlease enter the id:" << endl;
    string id;
    cin >> id;
    if (!QMPets.SearchById(id))
        cout << "There is no such pet." << endl;
    system("Pause");
}

void SearchByPrice()
{
    cout << "\nPlease enter the min:$" << endl;
    string min;
    cin >> min;
    cout << "\nPlease enter the max:$" << endl;
    string max;
    cin >> max;
    QMPets.SearchByPrice(min, max);
    system("Pause");
}

void SearchByDetails()
{
    cout << "\nPlease enter the type(Bird/Cat/Dog):" << endl;
    string type;
    cin >> type;
    while (type != "Bird" && type != "Cat" && type != "Dog")
    {
        cout << "\nNo such type,please retry:" << endl;
        cin >> type;
    }
    if (type == "Bird")
    {
        cout << "\nPlease enter that if they are licenced(yes/no):" << endl;
        string slicenced;
        cin >> slicenced;
        bool licenced;
        if (slicenced == "yes")
            licenced = true;
        else if (slicenced == "no")
            licenced = false;
        QMPets.SearchByDetail("Bird", licenced);
        system("Pause");
    }
    else
    {
        cout << "\nPlease enter that if they are neutered(yes/no):" << endl;
        bool neutered;
        string sneutered;
        cin >> sneutered;
        if (sneutered == "yes")
            neutered = true;
        else if (sneutered == "no")
            neutered = false;
        cout << "\nPlease enter that if they are vaccinated(yes/no):" << endl;
        bool vaccinated;
        string svaccinated;
        cin >> svaccinated;
        if (svaccinated == "yes")
            vaccinated = true;
        else if (svaccinated == "no")
            vaccinated = false;
        QMPets.SearchByDetail(type, neutered, vaccinated);
        system("Pause");
    }
}

void SearchPets()
{
    ClearScreen();
    cout << "-------------------------------------\n"
         << "           QM Pets        \n"
         << "-------------------------------------" << endl;
    cout << "      Option    Function         \n"
         << "-------------------------------------" << endl;
    cout << "      1         Search by type    " << endl;
    cout << "      2         Search by id       " << endl;
    cout << "      3         Search by price      " << endl;
    cout << "      4         Search by details    " << endl;
    cout << "-------------------------------------" << endl;
    cout << "Please enter the option:" << endl;
    string option;
    cin >> option;
    while (atoi(option.c_str()) < 1 || atoi(option.c_str()) > 4)
    {
        cout << "\nNo such option,please retry:" << endl;
        cin >> option;
    }
    switch (atoi(option.c_str()))
    {
    case 1:
        SearchByType();
        break;
    case 2:
        SearchById();
        break;
    case 3:
        SearchByPrice();
        break;
    case 4:
        SearchByDetails();
        break;
    }
}

void DisplayAll()
{
    ClearScreen();
    QMPets.DisplayAll();
    system("Pause");
}

void AddPets()
{
    ClearScreen();
    cout << "Please enter the type(Bird/Cat/Dog):" << endl;
    string type;
    cin >> type;
    while (type != "Bird" && type != "Cat" && type != "Dog")
    {
        cout << "\nNo such type,please retry:" << endl;
        cin >> type;
    }
    cout << "\nPlease enter the store id:" << endl;
    string id;
    cin >> id;
    while (QMPets.SearchById(id))
    {
        cout << "There is a same id.Please retry:" << endl;
        cin >> id;
    }
    cout << "\nPlease enter the breed:" << endl;
    string breed;
    cin >> breed;
    cout << "\nPlease enter the age:" << endl;
    string age;
    cin >> age;
    cout << "\nPlease enter the colour:" << endl;
    string colour;
    cin >> colour;
    cout << "\nPlease enter the origin:" << endl;
    string origin;
    cin >> origin;
    cout << "\nPlease enter the price($):" << endl;
    string price;
    cin >> price;
    if (type == "Bird")
    {
        cout << "\nPlease enter that if they are licenced(yes/no):" << endl;
        string slicenced;
        cin >> slicenced;
        bool licenced;
        if (slicenced == "yes")
            licenced = true;
        else if (slicenced == "no")
            licenced = false;
        Pet *p = new Bird(id, breed, age, colour, origin, price, licenced); //p will be push_back so can't be deleted here.
        QMPets.AddPets(p);
    }
    else if (type == "Cat")
    {
        cout << "\nPlease enter that if they are neutered(yes/no):" << endl;
        string sneutered;
        bool neutered;
        cin >> sneutered;
        if (sneutered == "yes")
            neutered = true;
        else if (sneutered == "no")
            neutered = false;
        cout << "\nPlease enter that if they are vaccinaed(yes/no):" << endl;
        bool vaccinaed;
        string svaccinaed;
        cin >> svaccinaed;
        if (svaccinaed == "yes")
            vaccinaed = true;
        else if (svaccinaed == "no")
            vaccinaed = false;
        Pet *p = new Cat(id, breed, age, colour, origin, price, neutered, vaccinaed);
        QMPets.AddPets(p);
    }
    else if (type == "Dog")
    {
        cout << "\nPlease enter that if they are neutered(yes/no):" << endl;
        string sneutered;
        bool neutered;
        cin >> sneutered;
        if (sneutered == "yes")
            neutered = true;
        else if (sneutered == "no")
            neutered = false;
        cout << "\nPlease enter that if they are vaccinaed(yes/no):" << endl;
        bool vaccinaed;
        string svaccinaed;
        cin >> svaccinaed;
        if (svaccinaed == "yes")
            vaccinaed = true;
        else if (svaccinaed == "no")
            vaccinaed = false;
        Pet *p = new Dog(id, breed, age, colour, origin, price, neutered, vaccinaed);
        QMPets.AddPets(p);
    }
    system("Pause");
}

void RemovePets()
{
    ClearScreen();
    cout << "Please enter the store id to be removed:" << endl;
    string id;
    cin >> id;
    if ((QMPets.RemovePets(id)) == 0)
    {
        cout << "There is no such pet." << endl;
    }
    system("Pause");
}

void ReadFile()
{
    ClearScreen();
    QMPets.ReadPets();
    cout << "Pets.dat is read." << endl;
    system("Pause");
}

void SaveExit()
{
    ClearScreen();
    QMPets.SavePets();
    cout << "All is saved as Pets.dat.Good bye~" << endl;
    system("Pause");
    exit(0);
}

void DispalyFamilymenu()
{
    cout << "           QM Pets        \n"
         << "-------------------------------------" << endl;
    cout << "      Option    Function         \n"
         << "-------------------------------------" << endl;
    cout << "      1         Add family    " << endl;
    cout << "      2         Show family      " << endl;
    cout << "      3         Save as file     " << endl;
    cout << "      4         Read from file    " << endl;
    cout << "      5         Search baby   " << endl;
    cout << "      6         Search mother   " << endl;
    cout << "-------------------------------------" << endl;
    cout << "Please enter the option:" << endl;
}

void AddFamily()
{
    ClearScreen();
    cout << "Please enter the baby store id :" << endl;
    string id1;
    cin >> id1;
    while (!QMPets.SearchById(id1))
    {
        cout << "There is no such pet.Please retry:" << endl;
        cin >> id1;
    }
    while (QMPets.SearchMother(id1))
    {
        cout << "It has a mother.Please retry:" << endl;
        cin >> id1;
    }
    cout << "Please enter the mother store id :" << endl;
    string id2;
    cin >> id2;
    while (!QMPets.SearchById(id2))
    {
        cout << "There is no such pet.Please retry:" << endl;
        cin >> id2;
    }
    QMPets.AddFamily(id1, id2);
    cout << "Family added." << endl;
    system("Pause");
}

void ShowFamily()
{
    if (!QMPets.ShowFamily())
        cout << "No family yet." << endl;
    system("Pause");
}

void SaveFamily()
{
    QMPets.SaveFamily();
    cout << "Saved as family.dat." << endl;
    system("Pause");
}

void ReadFamily()
{
    QMPets.ReadFamily();
    cout << "Read family.dat." << endl;
    system("Pause");
}

void SearchBaby()
{
    cout << "Please enter the mother store id :" << endl;
    string id;
    cin >> id;
    while (!QMPets.SearchById(id))
    {
        cout << "There is no such pet.Please retry:" << endl;
        cin >> id;
    }
    if (!QMPets.SearchBaby(id))
    {
        cout << id << " has no baby." << endl;
    };
    system("Pause");
}

void SearchMother()
{
    cout << "Please enter the baby store id :" << endl;
    string id;
    cin >> id;
    while (!QMPets.SearchById(id))
    {
        cout << "There is no such pet.Please retry:" << endl;
        cin >> id;
    }
    if (!QMPets.SearchMother(id))
    {
        cout << id << " has no mother is this store." << endl;
    };
    system("Pause");
}

void FamilyFunction()
{
    ClearScreen();
    DispalyFamilymenu();
    string option;
    cin >> option;
    while (atoi(option.c_str()) < 1 || atoi(option.c_str()) > 7)
    {
        cout << "\nNo such option,please retry:" << endl;
        cin >> option;
    }
    switch (atoi(option.c_str()))
    {
    case 1:
        AddFamily();
        break; //No need for delete family.
    case 2:
        ShowFamily();
        break;
    case 3:
        SaveFamily();
        break;
    case 4:
        ReadFamily();
        break;
    case 5:
        SearchBaby();
        break;
    case 6:
        SearchMother();
        break;
    }
}

void DisplayMainmenu()
{
    cout << "-------------------------------------\n"
         << "           QM Pets        \n"
         << "-------------------------------------" << endl;
    cout << "      Option    Function         \n"
         << "-------------------------------------" << endl;
    cout << "      1         Search pets    " << endl;
    cout << "      2         Display all       " << endl;
    cout << "      3         Add pets      " << endl;
    cout << "      4         Remove pets    " << endl;
    cout << "      5         Read from file   " << endl;
    cout << "      6         Save and exit   " << endl;
    cout << "      7         More functions about family   " << endl;
    cout << "-------------------------------------" << endl;
    cout << "Please enter the option:" << endl;
}

int main()
{
    while (1)
    {
        ClearScreen();
        DisplayMainmenu();
        string option;
        cin >> option;
        while (atoi(option.c_str()) < 1 || atoi(option.c_str()) > 7)
        {
            cout << "\nNo such option,please retry:" << endl;
            cin >> option;
        }
        switch (atoi(option.c_str()))
        {
        case 1:
            SearchPets();
            break;
        case 2:
            DisplayAll();
            break;
        case 3:
            AddPets();
            break;
        case 4:
            RemovePets();
            break;
        case 5:
            ReadFile();
            break;
        case 6:
            SaveExit();
            break;
        case 7:
            FamilyFunction();
            break;
        }
    }
}