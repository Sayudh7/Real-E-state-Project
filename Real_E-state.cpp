#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include <windows.h>
#include<sstream>
#include<vector>

using namespace std;

//Class defination
class house {
protected:
    string owner_name, location;
    float area,price;

public:
    void getdata1() {
        cin.ignore();
        cout << "Enter owner name: ";
        getline(cin, owner_name);
        cout << "Enter house location: ";
        getline(cin, location);
        cout << "Enter house area: ";
        cin >> area;
        cout << "Enter price: ";
        cin >> price;
    }

    void write_data1(ofstream &file) const {
        file << owner_name << endl;
        file << location << endl;
        file << area << endl;
        file << price << endl;
    }

    void read_data1(ifstream &file) {
        getline(file, owner_name);
        getline(file, location);
        file >> area;
        file >> price;
        file.ignore();
    }

    string summary1() const {
        return "Owner: " + owner_name + ", Location: " + location + ", Area: " + to_string(area)+"Price :"+ to_string(price);
    }
};

class facility : public house {
protected:
    string model, drainage, sewage, parking, garden;

public:
    void getdata2() {
        cin.ignore();
        cout << "Enter house model: ";
        getline(cin, model);
        cout << "Is there drainage system? ";
        getline(cin, drainage);
        cout << "Is there sewage system? ";
        getline(cin, sewage);
        cout << "Is there parking? ";
        getline(cin, parking);
        cout << "Is there garden? ";
        getline(cin, garden);
    }

    void write_data2(ofstream &file) const {
        file << model << endl << drainage << endl << sewage << endl << parking << endl << garden << endl;
    }

    void read_data2(ifstream &file) {
        getline(file, model);
        getline(file, drainage);
        getline(file, sewage);
        getline(file, parking);
        getline(file, garden);
    }
};

class house_model : public facility {
private:
    int bedroom, kitchen, bathroom;
    string flooring;

public:
    void getdata3() {
        cout << "Enter no. of bedrooms: ";
        cin >> bedroom;
        cout << "Enter no. of kitchens: ";
        cin >> kitchen;
        cout << "Enter no. of bathrooms: ";
        cin >> bathroom;
        cin.ignore();
        cout << "Flooring type: ";
        getline(cin, flooring);
    }

    void write_data3(ofstream &file) const {
        file << bedroom << endl << kitchen << endl << bathroom << endl << flooring << endl;
    }

    void read_data3(ifstream &file) {
        file >> bedroom >> kitchen >> bathroom;
        file.ignore();
        getline(file, flooring);
    }

    void get_all_data() {
        getdata1();
        getdata2();
        getdata3();
    }

    void write_all_data(ofstream &file) const {
        write_data1(file);
        write_data2(file);
        write_data3(file);
        file << "===\n"; // delimiter
    }

    void read_all_data(ifstream &file) {
        read_data1(file);
        read_data2(file);
        read_data3(file);
    }

    string summary() const {
        return summary1() + ", Model: " + model + ", Bedrooms: " + to_string(bedroom);
    }
};

class location
{
private:
    string road_access, landmark;
    char grade;


public:
    void location_detail()
    {
        system("cls");
        cout << "\t\t\tEnter road access(Highway/Urban road/ proposed / no road access ? ): ";
        // cin.ignore();
        getline(cin, road_access);
        cout << "\n\t\t\tEnter nearby landmarks: ";
        getline(cin, landmark);
        cout << "\n\t\t\tland category? (A=Prime, B=Residential, C=Semi-Urban, D=Rural): ";
        cin >> grade;
        grade = toupper(grade);
            while(1){
             if (grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D') {
                 break;
                } else cout << "\t\t\tInvalid choice! Please enter A, B, C, or D only.\n";
            }
    }
    string getR(){return road_access;}
    string getL() { return landmark; }
    char getG() { return grade; }
};
class facilities
{
private:
    string electricity;
    string water;
    string sewage;


public:
    void facilities_detail()
    {
        system("cls");
        cout << "\t\t\t(1/3) Do the land have access to an electricity line? (y/n) : ";
        getline(cin, electricity);
        cout << "\n\t\t\t(2/3) Does the land have access to a water pipeline? (y/n) : ";
        getline(cin, water);
        cout << "\n\t\t\t(3/3) Does the land have access to a sewage pipeline? (y/n) : ";
        getline(cin, sewage);
    }
    string getE() { return electricity; }
    string getW() { return water; }
    string getS() { return sewage; }
};
class land
{
private:
    string owner;
    string address;
    float area;
    string kitta_no;
    facilities fac;
    location loc;
    int selling_price;


public:
    land()
    {
        cout << "\n\t\t\tPlease enter the required information as per your land ownership documents..." << endl;
        Sleep(2000); // Wait for 2 seconds
        system("cls");
        cin.ignore();
        cout << "\t\t\tKindly enter the name of the Land owner: ";
        getline(cin, owner);
        cout << "\n\t\t\tKindly enter the address of the property: ";
        getline(cin, address);
        cout << "\n\t\t\tEnter the Kitta number associated with the property: ";
        getline(cin, kitta_no);
        land_measurement();
        // the newline left by cin confuses getline and thinks of the  end of input immediately
        // cin.ignore ignore removes the new line left by cin//
        cin.ignore();
        system("cls");
        fac.facilities_detail();
        loc.location_detail();
        system("cls");
        cout << "\t\t\twhat is selling price of property(land)? : Rs ";
        cin >> selling_price;
        system("cls");
        cout << "\t\t\tMr/Mrs " << owner << ", Thanks for entering the land's detail." << endl;
        Sleep(2000);
    }
    void land_measurement()
    {
        int choice;
        system("cls");
        cout << "\t\t\tMr/Mrs " << owner << ", which unit of land measure do you prefer? " << endl;
        cout << "\n\t\t\t1. Traditional Nepali Land Measurement (ROPANI, AANA, PAISA)" << endl;
        cout << "\n\t\t\t2. Square meters" << endl;
        cout << "\n\t\t\tEnter your choice : ";
        cin >> choice;
        cin.ignore();
        cout << "\n\t\t\tThanks for entering your choice" << endl;
        Sleep(1500);
        if (choice == 1)
        {
            system("cls");
            float ropani, aana, paisa, dam;
            cout << "\t\t\tEnter Ropani: ";
            cin >> ropani;
            cout << "\t\t\tEnter Aana: ";
            cin >> aana;
            cout << "\t\t\tEnter Paisa: ";
            cin >> paisa;
            cout << "\t\t\tEnter Dam: ";
            cin >> dam;
            display_land_detail(ropani, aana, paisa, dam);
        }
        else if (choice == 2)
        {
            system("cls");
            float sqmeter;
            cout << "\t\t\tEnter area in square meters: ";
            cin >> sqmeter;
            display_land_detail(sqmeter);
        }
        else
        {
            cout << "\t\t\tPlease enter the correct options(1 or 2)" << endl;
        }
    }
    void display_land_detail(float s)
    {
        cout << "\n\n\t\t\tArea entered: " << s << " sq.m" << endl;
        this->area = s;
        Sleep(2000);
    }


    void display_land_detail(float a, float b, float c, float d)
    {
        cout << "\n\n\t\t\tLand Area: " << a << " Ropani, " << b << " Aana, " << c << " Paisa, " << d << " Daam." << endl;
        float totalSqMeters = convertToSquareMeters(a, b, c, d);
        cout << "\n\n\t\t\tEquivalent area in square meters: " << totalSqMeters << " sq.m" << endl;
        this->area = totalSqMeters;
        Sleep(2000);
    }

    float convertToSquareMeters(float ropani, float aana, float paisa, float dam)
    {
        float area = ropani * 508.74;
        area += aana * 31.80;
        area += paisa * 7.95;
        area += dam * 1.99;
        return area;
    }
    void display_Details()
    {
        system("cls");
        cout << "-------------------------Land Details-------------------------------" << endl;
        cout << "Owner's Name                                       : " << owner << endl;
        cout << "Property Address                                   : " << address << endl;
        cout << "Area of the Property                               : " << area << " sq.m " << endl;
        cout << "Kitta Number                                       : " << kitta_no << endl;
        cout << "Does the land have access to an electricity line?  : " << fac.getE() << endl;
        cout << "Does the land have access to a water pipeline?     : " << fac.getW() << endl;
        cout << "Does the land have access to a sewage pipeline?    : " << fac.getS() << endl;
        cout << "land category                                      : " << loc.getG() << endl;
        cout << "landmark                                           : " << loc.getL() << endl;
        cout << "Road access                                        : " << loc.getR() << endl;
        cout << "selling price                                      : " << selling_price << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
        system("cls");
    }
    void save_file()
    {
        ofstream fout("land's entry detail.txt", ios::app);
        fout << "-------------------------Land Details-------------------------------" << endl;
        fout << "Owner's Name                                       : " << owner << endl;
        fout << "Property Address                                   : " << address << endl;
        fout << "Area of the Property                               : " << area << " sq.m " << endl;
        fout << "Kitta Number                                       : " << kitta_no << endl;
        fout << "Does the land have access to an electricity line?  : " << fac.getE() << endl;
        fout << "Does the land have access to a water pipeline?     : " << fac.getW() << endl;
        fout << "Does the land have access to a sewage pipeline?    : " << fac.getS() << endl;
        fout << "land category                                      : " << loc.getG() << endl;
        fout << "landmark                                           : " << loc.getL() << endl;
        fout << "Road access                                        : " << loc.getR() << endl;
        fout << "selling price                                      : " << selling_price << endl;
        fout << "--------------------------------------------------------------------" << endl;
        fout.close();
    }
    void save_file_temp()
    {
        ofstream fout("temp.txt", ios::app);
        fout << owner;
        fout << "%" << address;
        fout << "%" << area;
        fout << "%" << kitta_no;
        fout << "%" << fac.getE();
        fout << "%" << fac.getW();
        fout << "%" << fac.getS();
        fout << "%" << loc.getG();
        fout << "%" << loc.getL();
        fout << "%" << loc.getR();
        fout << "%" << selling_price << "\n";
        fout.close();
    }
};

//Global Functions Declaration
void main_choice();
void choice_house();
void choice_land();
void house_purchase();
void house_selling();
void update_house_record();
void delete_house_record();
void list_all_records(vector<house_model> &records);
vector<house_model> load_records(const string &filename);
void save_records(const string &filename, const vector<house_model> &records);
void house_selling_add();
void land_purchase();
void land_selling();
void land_measurement();



//Global Functions Defination
void main_menu() {
    while (true) {
        system("cls");
        int n;
        cout << "\t\t\tWelcome to Real Estate Business Platform!!";
        cout << "\n\n\t\t\t 1. House Real Estate business ";
        cout << "\n\t\t\t 2. Land Real Estate business";
        cout << "\n\t\t\t 3. Exit";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;

        switch (n) {
            case 1:
                choice_house();
                break;
            case 2:
                choice_land();
                break;
            case 3:
                exit(0);
            default:
                cout << "\n\n\t\t\tInvalid Entry!!\n";
                Sleep(3000);
        }
    }
}

void choice_house() {
    while (true) {
        system("cls");
        int n;
        cout << "\t\t\tHouse Real Estate Menu";
        cout << "\n\n\t\t\t 1. House Purchase ";
        cout << "\n\t\t\t 2. House Selling";
        cout << "\n\t\t\t 3. <- Back";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;

        switch (n) {
            case 1:
                house_purchase();
                break;
            case 2:
                house_selling_add();
                break;
            case 3:
                return; // back to main menu
            default:
                cout << "\n\n\t\t\tInvalid Entry!!\n";
                system("pause");
        }
    }
}


void house_selling_add() {
    while (true) {
        system("cls");
        int n;
        cout << "\t\t\tHouse Real Estate Menu";
        cout << "\n\n\t\t\t 1. House Selling (Add)";
        cout << "\n\t\t\t 2. Update House Record";
        cout << "\n\t\t\t 3. Delete House Record";
        cout << "\n\t\t\t 4. <- Back";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;

        switch (n) {
            case 1:
                house_selling();
                break;
            case 2:
                update_house_record();
                break;
            case 3:
                delete_house_record();
                break;
            case 4:
                return;
            default:
                cout << "\n\n\t\t\tInvalid Entry!!\n";
                system("pause");
        }
    }
}

void house_selling() {
    system("cls");
    house_model h;
    h.get_all_data();

    ofstream file("house_record.txt", ios::app);
    if (!file) {
        cerr << "File opening failed.\n";
        return;
    }

    h.write_all_data(file);
    file.close();

    cout << "Record saved successfully.\n";
    system("pause");
}

void update_house_record() {
    system("cls");
    vector<house_model> records = load_records("house_record.txt");

    if (records.empty()) {
        cout << "No records found.\n";
        system("pause");
        return;
    }

    list_all_records(records);
    int index;
    cout << "Enter record number to update: ";
    cin >> index;

    if (index < 1 || index > records.size()) {
        cout << "Invalid index.\n";
        return;
    }

    records[index - 1].get_all_data();
    save_records("house_record.txt", records);

    cout << "Record updated.\n";
    system("pause");
}

void delete_house_record() {
    system("cls");
    vector<house_model> records = load_records("house_record.txt");

    if (records.empty()) {
        cout << "No records found.\n";
        system("pause");
        return;
    }

    list_all_records(records);
    int index;
    cout << "Enter record number to delete: ";
    cin >> index;

    if (index < 1 || index > records.size()) {
        cout << "Invalid index.\n";
        return;
    }

    records.erase(records.begin() + index - 1);
    save_records("house_record.txt", records);

    cout << "Record deleted.\n";
    system("pause");
}

void list_all_records(vector<house_model> &records) {
    int i = 1;
    for (const auto &r : records) {
        cout << i++ << ". " << r.summary() << endl;
    }
}

vector<house_model> load_records(const string &filename) {
    vector<house_model> records;
    ifstream file(filename);
    if (!file) return records;

    while (file.peek() != EOF) {
        house_model h;
        h.read_all_data(file);
        string delimiter;
        getline(file, delimiter); // read delimiter ===
        if (!file.fail()) {
            records.push_back(h);
        }
    }

    return records;
}

void save_records(const string &filename, const vector<house_model> &records) {
    ofstream file(filename, ios::trunc);
    for (const auto &r : records) {
        r.write_all_data(file);
    }
}
void house_purchase() {
    system("cls");
    vector<house_model> records = load_records("house_record.txt");

    if (records.empty()) {
        cout << "No houses available for purchase.\n";
        system("pause");
        return;
    }

    cout << "\t\tAvailable Houses for Purchase:\n";
    list_all_records(records);
    int index;
    cout << "\nEnter the record number of the house to purchase: ";
    cin >> index;
    if (index < 1 || index > records.size()) {
        cout << "Invalid index.\n";
        system("pause");
        return;
    }

    cout << "\nYou have purchased:\n" << records[index - 1].summary() << "\n";
    records.erase(records.begin() + index - 1); // Remove purchased house
    save_records("house_record.txt", records);

    cout << "\nPurchase successful!\n";
    system("pause");
}


//Function Defination for Land

void choice_land()
{
    int n;
    while (true)
    {
        system("cls");
        cout << "\t\t\tWelcome to Real Estate Business Platform!!";
        cout << "\n\n\t\t\t 1.Land Purchase";
        cout << "\n\t\t\t 2.Land Selling";
        cout << "\n\t\t\t 3.<-Back";
        cout << "\n\t\t\t 4.Exit";
        cout << "\n\n\t\t\t Enter a choice: ";
        cin >> n;

        switch (n)
        {
        case 1:
            land_purchase();
            break;
        case 2:
            land_selling();
            break;
        case 3:
            return; // Back to main menu
        case 4:
            system("cls");
            cout << "\n\t\t\tThanks for using our service" << endl;
            exit(0);
        default:
            cout << "\n\n\t\t\tInvalid Entry!!";
            Sleep(2000);
        }
    }
}
void land_selling()
{
    land a;
    a.display_Details();
    a.save_file();
    a.save_file_temp();
}
void filter()
{
    cout << "\n\n\t\t\tThe order in file : owner,address,area,kitta no,status of(electricity,water,sewage),landmark,road and selling price" << endl;
    string line;
    string gradeb;
    float areab, budget;
    float area, selling_price;
    bool found = false;
    string address, owner, road, landmark, electricity, water, sewage, grade, kitta_no;

    cout << "\n\t\t\tWhat is your budget for property purchase?: ";
    cin >> budget;
    cout << "\n\t\t\tWhat is the area required?: ";
    cin >> areab;
    cout << "\n\t\t\tWhat is the grade of property? (A/B/C/D): ";
    cin >> gradeb;

    int a = 0, b = 0;
    ifstream fin("temp.txt");

    while (getline(fin, line))
    {
        a++;
        stringstream read(line);
        getline(read, owner, '%');
        getline(read, address, '%');
        read >> area;
        read.ignore();
        getline(read, kitta_no, '%');
        getline(read, electricity, '%');
        getline(read, water, '%');
        getline(read, sewage, '%');
        getline(read, grade, '%');
        getline(read, landmark, '%');
        getline(read, road, '%');
        read >> selling_price;

        if ((gradeb == grade) &&
            (selling_price >= 0.8 * budget && selling_price <= 1.2 * budget) &&
            (area >= 0.8 * areab && area <= 1.2 * areab))
        {
            b++;
            found = true;
            system("cls");
            cout << "\t\t\t" << b << " out of " << a << " matched" << endl;
            cout << "--------------------------- Matching Property ----------------------------" << endl;
            cout << "Owner's Name                                       : " << owner << endl;
            cout << "Property Address                                   : " << address << endl;
            cout << "Area of the Property                               : " << area << " sq.m " << endl;
            cout << "Kitta Number                                       : " << kitta_no << endl;
            cout << "Does the land have access to an electricity line?  : " << electricity << endl;
            cout << "Does the land have access to a water pipeline?     : " << water << endl;
            cout << "Does the land have access to a sewage pipeline?    : " << sewage << endl;
            cout << "Land category                                      : " << grade << endl;
            cout << "Landmark                                           : " << landmark << endl;
            cout << "Road access                                        : " << road << endl;
            cout << "Selling price                                      : " << selling_price << endl;
            cout << "---------------------------------------------------------------------------" << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    if (!found)
    {
        cout << "\n\n\t\t\tNo match found.\n";
        cout << "Press Enter to return...";
        cin.ignore();
        cin.get();
    }
}
void land_purchase()
{
    int choice;
    system("cls");
    cout << "\n\t\t\t 1. View all lands";
    cout << "\n\t\t\t 2. Filter land by preferences";
    cout << "\n\t\t\t Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        system("cls");
        ifstream fin("land's entry detail.txt");
        string read;
        if (fin.is_open())
        {
            while (getline(fin, read))
            {
                cout << read << endl;
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            fin.close();
        }
        else
        {
            cout << "\t\t\tFile doesn't exist" << endl;
        }
        break;
    }
    case 2:
    {
        system("cls");
        filter();
        break;
    }
    default:
    {
        cout << "\n\t\t\tInvalid choice. Try again.\n";
        break;
    }
    }
}


//Main Body
int main()
{
    system("cls");
    main_menu();
    return 0;
}