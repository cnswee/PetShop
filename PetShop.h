#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

class Pet
{
private:
    string storeId;
    string breed;
    string age;
    string colour;
    string origin;
    string price;
    string motherId = " ";

public:
    Pet() {}

    Pet(const string &storeId, const string &breed, const string &age, const string &colour, const string &origin, const string &price) : storeId(storeId), breed(breed), age(age), colour(colour), origin(origin), price(price)
    {
        // cout << "The pet is created" << endl;
    }

    virtual string Type()
    {
        return "Pet";
    }

    string GetStoreId()
    {
        return storeId;
    }

    string GetBreed()
    {
        return breed;
    }

    string GetAge()
    {
        return age;
    }

    string GetColour()
    {
        return colour;
    }

    string GetOrigin()
    {
        return origin;
    }

    string GetPrice()
    {
        return price;
    }

    void SetMotherId(string id)
    {
        motherId = id;
    }

    string GetMotherId()
    {
        return motherId;
    }

    virtual bool GetNeutered() {} //虚函数必须要实现，否则改为纯虚函数

    virtual bool GetVaccinaed() {}

    virtual bool GetLicenced() {}

    virtual void Show() {}
};

class Cat : public Pet
{
private:
    bool neutered;
    bool vaccinaed;

public:
    Cat(const string &storeId, const string &breed, const string &age, const string &colour, const string &origin, const string &price, bool neutered, bool vaccinaed) : Pet(storeId, breed, age, colour, origin, price), neutered(neutered), vaccinaed(vaccinaed)
    {
        cout << "The cat is created" << endl;
    }

    string Type()
    {
        return "Cat";
    }

    void Show()
    {
        cout << Type() << " "
             << "storeId:" << GetStoreId() << " "
             << "breed:" << GetBreed() << " "
             << "age:" << GetAge() << " "
             << "colour:" << GetColour() << " "
             << "price:" << GetPrice() << " "
             << "neutered:" << boolalpha << neutered << " "
             << "vaccinaed:" << boolalpha << vaccinaed << endl
             << endl;
    }

    bool GetNeutered()
    {
        return neutered;
    }

    bool GetVaccinaed()
    {
        return vaccinaed;
    }
};

class Dog : public Pet
{
private:
    bool neutered;
    bool vaccinaed;

public:
    Dog(const string &storeId, const string &breed, const string &age, const string &colour, const string &origin, const string &price, bool neutered, bool vaccinaed) : Pet(storeId, breed, age, colour, origin, price), neutered(neutered), vaccinaed(vaccinaed)
    {
        cout << "The dog is created" << endl;
    }

    string Type()
    {
        return "Dog";
    }

    void Show()
    {
        cout << Type() << " "
             << "storeId:" << GetStoreId() << " "
             << "breed:" << GetBreed() << " "
             << "age:" << GetAge() << " "
             << "colour:" << GetColour() << " "
             << "price:" << GetPrice() << " "
             << "neutered:" << boolalpha << neutered << " "
             << "vaccinaed:" << boolalpha << vaccinaed << endl
             << endl;
    }

    bool GetNeutered()
    {
        return neutered;
    }

    bool GetVaccinaed()
    {
        return vaccinaed;
    }
};

class Bird : public Pet
{
private:
    bool licenced;

public:
    Bird(const string &storeId, const string &breed, const string &age, const string &colour, const string &origin, const string &price, bool licenced) : Pet(storeId, breed, age, colour, origin, price), licenced(licenced)
    {
        cout << "The bird is created" << endl;
    }

    string Type()
    {
        return "Bird";
    }

    void Show()
    {
        cout << Type() << " "
             << "storeId:" << GetStoreId() << " "
             << "breed:" << GetBreed() << " "
             << "age:" << GetAge() << " "
             << "colour:" << GetColour() << " "
             << "price:" << GetPrice() << " "
             << "licenced:" << boolalpha << licenced << endl
             << endl;
    }

    bool GetLicenced()
    {
        return licenced;
    }
};

// struct TreeNode
// {
//     int Id;
//     TreeNode *lparent, *rparent;
// };

class Shop
{
private:
    vector<Pet *> pets;
    // vector<TreeNode *> family;

public:
    Shop(){};

    void AddPets(Pet *&p)
    {
        pets.push_back(p);
    }

    int RemovePets(string id)
    {
        int flag = 0;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetStoreId() == id)
            {
                pets.erase(pets.begin() + i);
                flag = 1;
            }
        }
        return flag;
    }

    void SearchByType(string type)
    {
        int flag = 0;
        int count = 1;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).Type() == type)
            {
                cout << count++ << ". ";
                (*pets[i]).Show();
                flag = 1;
            }
        }
        if (!flag)
            cout << "There is no such pets.\n"
                 << endl;
    }

    int SearchById(string id)
    {
        int flag = 0;
        int count = 1;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetStoreId() == id)
            {
                cout << "\n"
                     << count++ << ". ";
                (*pets[i]).Show();
                flag = 1;
            }
        }
        return flag;
    }

    void SearchByPrice(string minprice, string maxprice)
    {
        int flag = 0;
        int count = 1;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetPrice() >= minprice && (*pets[i]).GetPrice() <= maxprice)
            {
                cout << count++ << ". ";
                (*pets[i]).Show();
                flag = 1;
            }
        }
        if (!flag)
            cout << "There is no such pets.\n"
                 << endl;
    }

    void SearchByDetail(string type, bool detail1, bool detail2)
    {
        int flag = 0;
        int count = 1;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).Type() == type && (*pets[i]).GetNeutered() == detail1 && (*pets[i]).GetVaccinaed() == detail2)
            {
                cout << count++ << ". ";
                (*pets[i]).Show();
                flag = 1;
            }
        }
        if (!flag)
            cout << "There is no such pets.\n"
                 << endl;
    }

    void SearchByDetail(string type, bool detail1)
    {
        int flag = 0;
        int count = 1;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).Type() == type && (*pets[i]).GetLicenced() == detail1)
            {
                cout << count++ << ". ";
                (*pets[i]).Show();
                flag = 1;
            }
        }
        if (!flag)
            cout << "There is no such pets.\n"
                 << endl;
    }

    void DisplayAll()
    {
        int flag = 0;
        int count = 1;
        for (int i = 0; i < pets.size(); i++)
        {
            cout << count++ << ": ";
            (*pets[i]).Show();
            flag = 1;
        }
        if (!flag)
            cout << "There is no pets.\n"
                 << endl;
    }

    void SavePets()
    {
        ofstream outfile;
        outfile.open("pets.dat");
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).Type() == "Bird")
            {
                outfile << "Bird" << ' ' << (*pets[i]).GetStoreId() << ' ' << (*pets[i]).GetBreed() << ' ' << (*pets[i]).GetAge() << ' ' << (*pets[i]).GetColour()
                        << ' ' << (*pets[i]).GetOrigin() << ' ' << (*pets[i]).GetPrice() << ' ' << (*pets[i]).GetLicenced() << endl;
            }
            else if ((*pets[i]).Type() == "Cat")
            {
                outfile << "Cat" << ' ' << (*pets[i]).GetStoreId() << ' ' << (*pets[i]).GetBreed() << ' ' << (*pets[i]).GetAge() << ' ' << (*pets[i]).GetColour()
                        << ' ' << (*pets[i]).GetOrigin() << ' ' << (*pets[i]).GetPrice() << ' ' << (*pets[i]).GetNeutered() << ' ' << (*pets[i]).GetVaccinaed() << endl;
            }
            else if ((*pets[i]).Type() == "Dog")
            {
                outfile << "Dog" << ' ' << (*pets[i]).GetStoreId() << ' ' << (*pets[i]).GetBreed() << ' ' << (*pets[i]).GetAge() << ' ' << (*pets[i]).GetColour()
                        << ' ' << (*pets[i]).GetOrigin() << ' ' << (*pets[i]).GetPrice() << ' ' << (*pets[i]).GetNeutered() << ' ' << (*pets[i]).GetVaccinaed() << endl;
            }
        }
        outfile.close();
    }

    void SplitString(const string &s, vector<string> &v, const string &c)
    {
        string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while (string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2 - pos1));

            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if (pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

    void ReadPets()
    {
        ifstream infile;
        infile.open("pets.dat");
        string line;
        vector<string> lines;
        if (infile)
        {
            while (getline(infile, line))
            {
                lines.push_back(line);
            }
        }
        else
            cout << "There is no such file." << endl;
        // cout<<lines[0];
        // cout<<lines[1];
        for (int i = 0; i < lines.size(); i++)
        {
            vector<string> p;
            SplitString(lines[i], p, " ");
            if (p[0] == "Cat")
            {
                Pet *temp = new Cat(p[1], p[2], p[3], p[4], p[5], p[6], atoi(p[7].c_str()), atoi(p[8].c_str()));
                AddPets(temp);
                // Can't delete here.
            }
            else if (p[0] == "Dog")
            {
                Pet *temp = new Dog(p[1], p[2], p[3], p[4], p[5], p[6], atoi(p[7].c_str()), atoi(p[8].c_str()));
                AddPets(temp);
            }
            else if (p[0] == "Bird")
            {
                Pet *temp = new Bird(p[1], p[2], p[3], p[4], p[5], p[6], atoi(p[7].c_str()));
                AddPets(temp);
            }
            // 需要保存的指针必须使用new来建立
            // 在if语句中直接创建的对象在if语句结束后即被释放（在栈中），首地址会在下一个对象创建时重复使用
        }
    }

    void AddFamily(string id1, string id2)
    {
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetStoreId() == id1)
            {
                (*pets[i]).SetMotherId(id2);
            }
        }
    }

    int ShowFamily()
    {
        int flag = 0;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetMotherId() != " ")
            {
                cout << (*pets[i]).GetStoreId() << "'s mother is " << (*pets[i]).GetMotherId() << "." << endl;
                flag = 1;
            }
        }
        return flag;
    }

    void SaveFamily()
    {
        ofstream outfile;
        outfile.open("family.dat");
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetMotherId() != " ")
                outfile << (*pets[i]).GetStoreId() << " " << (*pets[i]).GetMotherId() << endl;
        }
        outfile.close();
    }

    void ReadFamily()
    {
        ifstream infile;
        infile.open("family.dat");
        string line;
        vector<string> lines;
        if (infile)
        {
            while (getline(infile, line))
            {
                lines.push_back(line);
            }
        }
        else
            cout << "There is no such file." << endl;
        for (int i = 0; i < lines.size(); i++)
        {
            vector<string> p;
            SplitString(lines[i], p, " ");
            for (int j = 0; j < pets.size(); j++)
            {
                if ((*pets[j]).GetStoreId() == p[0])
                    (*pets[j]).SetMotherId(p[1]);
            }
        }
    }

    int SearchBaby(string id)
    {
        int flag = 0;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetMotherId() == id)
                cout << id << "'s baby is " << (*pets[i]).GetStoreId() << endl;
            flag = 1;
        }
        return flag;
    }

    int SearchMother(string id)
    {
        int flag = 0;
        for (int i = 0; i < pets.size(); i++)
        {
            if ((*pets[i]).GetStoreId() == id && (*pets[i]).GetMotherId() != " ")
            {
                cout << id << "'s mother is " << (*pets[i]).GetMotherId() << endl;
                flag = 1;
            }
        }
        return flag;
    }
};
