#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <unordered_map>
#include <STDLIB.h>
#include <conio.h>
#include <windows.h>
using namespace std;
class LoginSystem {
private:
    const string studentFile = "student_credentials.txt";
    const string facultyFile = "faculty_credentials.txt";

    unordered_map<string, string> studentCredentials;
    unordered_map<string, string> facultyCredentials;

    // Load existing credentials from files
    void loadCredentials(const string& file, unordered_map<string, string>& credentials) {
        ifstream infile(file);
        string username, password;

        while (infile >> username >> password) {
            credentials[username] = password;
        }

        infile.close();
    }
void gotoxy(int x, int y)
{
	static HANDLE h=NULL;
	if(!h)
	  h=GetStdHandle(STD_OUTPUT_HANDLE);
	  COORD c = { x, y };
	  SetConsoleCursorPosition(h,c);
}
    // Save new credentials to files
    void saveCredentials(const string& file, const unordered_map<string, string>& credentials) {
        ofstream outfile(file);

        for (const auto& entry : credentials) {
            outfile << entry.first << " " << entry.second << endl;
        }

        outfile.close();
    }

public:
    LoginSystem() {
        loadCredentials(studentFile, studentCredentials);
        loadCredentials(facultyFile, facultyCredentials);
    }

    void createAccount(	const string& username, const string& password, const string& role)
	 {
	 system("cls");
        unordered_map<string, string>& credentials = (role == "student") ? studentCredentials : facultyCredentials;

        auto it = credentials.find(username);
        if (it == credentials.end()) {
            credentials[username] = password;
            saveCredentials((role == "student") ? studentFile : facultyFile, credentials);
            gotoxy(80,1);
            cout << "Account created successfully for " << role << ": " << username << endl;
        } else {
            cout << "Username already exists. Choose a different username." << exit;
        }
    }

    bool login(
	const string& username, const string& password, const string& role)
	 {system("cls");
        unordered_map<string, string>& credentials = (role == "student") ? studentCredentials : facultyCredentials;

        auto it = credentials.find(username);
        if (it != credentials.end() && it->second == password) {
            cout << "Login successful! Welcome, " << role << ": " << username << endl;
            return true;
        } else {
            cout << "Login failed. Invalid username or password for " << role << "." << exit;
            return false;
        }
    }
};
void gotoxy(int x, int y)
{
	static HANDLE h=NULL;
	if(!h)
	  h=GetStdHandle(STD_OUTPUT_HANDLE);
	  COORD c = { x, y };
	  SetConsoleCursorPosition(h,c);
}
struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

struct BookAppointment {
    string bookTitle;
    string bookAuthor;
    string bookISBN;
    string pickupDate;
    string pickupTime;
    string dropDate;
    string dropTime;
};

vector<Book> books;
vector<BookAppointment> appointments;

// Function to initialize the list of books
void initializeBooks() 
{ system("cls");

    books = {{"A Text Book Of Network Theory\t\t\t\t","Kaduskar R. G.\t\t\t\t", "0550" ,true},
             {"Data Structures And Algorithm Analysis In C\t\t","Weiss Mark Allen\t\t\t", "9912", true },
             {"Microsoft ADO.NET4\t\t\t\t\t", "Patrick\t\t\t\t", "8328", true},
             {"Discrete Mathematics\t\t\t\t\t","Lipschutz, Seymour/ Lipson, Marc Lars\t","0014", true},
             {"Theory Of Computation\t\t\t\t\t","Moret Bernard\t\t\t\t","6884", true},
             {"Object-Oriented Programming With C++\t\t\t","Sahay Sourav\t\t\t\t","3417", true},
             {"Windows Server 2012\t\t\t\t\t","Stanek William\t\t\t\t","8437", true},
             {"Android Application Development\t\t\t\t","Darcey Lauren\t\t\t\t","9187", true},
             {"Artificial Intelligence\t\t\t\t\t","Luger George\t\t\t\t","6176", true},
             {"Statistics\t\t\t\t\t\t","Spiegel M R / Larry J Stephens\t\t","0880", true},
             {"System Software\t\t\t\t\t\t","Beck Leyland L\t\t\t\t","4322", true},
             {"8051 Microcontroller And Embedded Systems\t\t","Rajiv Kapadia\t\t\t\t","0677", true},
             {"Management Information Systems\t\t\t\t","Obrien James\t\t\t\t","4538", true},
             {"Cloud Computing\t\t\t\t\t\t","Barrie Sosinsky\t\t\t","6685", true},
             {"Basic V & SI Design\t\t\t\t\t","Pucknell Douglas\t\t\t","3666", true},
             {"Data Structures : A Pseudo Code Approach With C\t\t","Gilberg richard F / Forouzan\t\t","9923", true},
             {"Managemnt Information System\t\t\t\t","Jawadekar Waman S\t\t\t","4544", true},
             {"An Integrated Apporach To Software Engineering\t\t","Jalote Pankaj\t\t\t\t","9890", true},
             {"Assembly Language Step By Step\t\t\t\t","Duntemann Jefff\t\t\t","9894", true},
             {"Project Management\t\t\t\t\t","Nagarajan K\t\t\t\t","3038", true},
             {"Operation Research\t\t\t\t\t","Taha Hamdy A\t\t\t\t","2602", true},
             {"Information Technology For Management\t\t\t","Turban Efraim\t\t\t\t","4673", true},
             {"Digital Systems Principles And Applications\t\t","Tocci, Ronald J\t\t\t","2599", true},
             {"Introduction To Data Mining\t\t\t\t","Tan Steinbach\t\t\t\t","0326", true},
             {"Data And Computer Communications\t\t\t\t","Stallings\t\t\t\t","8840", true},
             {"Operation Research\t\t\t\t\t","Taha H A\t\t\t\t","7783", true},
             {"Introduction To Design And Analysis Of Algorithms\t","Levitin\t\t\t\t","9007", true},
             {"Fundamental Of Computer Algorithms\t\t\t","Horowitz Ellis / Sahni Sartaj\t\t","9925", true},
             {"Operating System Concepts\t\t\t\t","Galvin Peter B\t\t\t\t","5049", true},
             {"Embedded Linux Primer\t\t\t\t\t","Hallinan Christopher\t\t\t","0051", true},
             {"Embedded System Design\t\t\t\t\t","Heath \t\t\t\t\t","0305", true},
             {"Wireless Sensor Networks\t\t\t\t\t","Sohraby Kazem / Minoli / Znati\t\t","0224", true},
             {"Modern Visi Design\t\t\t\t\t","Wolf Wayne\t\t\t\t","0201", true},
             {"Visual Basic 6 Programming Black Book + (CD)\t\t","Holzner Steven\t\t\t\t","4427", true},
             {"The 8086 / 8088 Family\t\t\t\t\t","Uffenbeck\t\t\t\t","5057", true},
             {"Data Structures Through C\t\t\t\t","Kanetkar Yeshvant\t\t\t","1316", true},
             {"Lex & Yacc\t\t\t\t\t\t","Levine John R\t\t\t\t","6703", true},
             {"Object Oriented Programming With C++\t\t\t","Balagurusamy E\t\t\t\t","0931", true},
             {"Mobile Computing\t\t\t\t\t\t","Kamal Raj\t\t\t\t","2781", true},
             {"VHDL Programming By Example\t\t\t\t","Perry Douglas\t\t\t\t","6357", true},
             {"Exploring C (2nd Edition)\t\t\t\t","Kanetkar Yeshvant\t\t\t","1310", true},
             {"Linear Programming And Theory Of Games\t\t\t","karak P M\t\t\t\t","0513", true},
             {"An Introduction to Database Systems\t\t\t","C J Date\t\t\t\t","9823", true},
             {"Computer Architecture And Organization\t\t\t","John Patrick Hayes\t\t\t","9903", true},
             {"Operation Research : Principal and Practice\t\t","Ravidram\t\t\t\t","9739", true},
             {"Software Design\t\t\t\t\t\t","Budgen David\t\t\t\t","0375", true},
             
			 
             // Add more books as needed
    };
}

void displayMenu() {system("cls");
gotoxy(60, 2);
	cout << "*********************************************************************************************\n";
	gotoxy(95, 5);
	cout << " MAIN MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(95, 15);
    cout << "1. Book Pickup\n";
    gotoxy(95, 18);
    cout << "2. Book Drop\n";
    gotoxy(90, 21);
    cout << "3. Display Book Availability\n";
    gotoxy(98, 24);
    cout << "4. Exit\n";
}

bool isBookAvailable(const string& isbn) {
    for (const auto& book : books) {
        if (book.isbn == isbn) {
            return book.isAvailable;
        }
    }
    return false;
}

void bookPickup() {system("cls");
gotoxy(60, 2);
cout << "*********************************************************************************************\n";
gotoxy(95, 5);
	cout << " BOOK PICKUP MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
    BookAppointment appointment;
gotoxy(90, 15);
    cout << "Enter Book ISBN : ";
    cin >> appointment.bookISBN;

    if (!isBookAvailable(appointment.bookISBN)) {
    	gotoxy(76,20);
        cout << "Sorry, the book is not available for pickup.\n";
        getch();
        return;
    }
gotoxy(76, 20);
    cout << "Enter Pickup Date and Time (Format DD/MM/YYYY HH:MM in 24 hrs ) : ";
    cin >> appointment.pickupTime>>appointment.pickupDate;

    // Update book availability status
    for (auto& book : books) {
        if (book.isbn == appointment.bookISBN) {
            book.isAvailable = false;
            break;
        }
    }

    appointments.push_back(appointment);
gotoxy(80, 25);
    cout << "Book Pickup Appointment successfully booked!\n";
    getch();
}

void bookDrop() {system("cls");
gotoxy(60, 2);
cout << "*********************************************************************************************\n";
gotoxy(95, 5);
	cout << "BOOK DROP MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
    string bookISBN;
    gotoxy(90, 15);
    cout << "Enter Book ISBN : ";
    cin >> bookISBN;

    for (auto& appointment : appointments) {
        if (appointment.bookISBN == bookISBN) {
        	gotoxy(76, 20);
            cout << "Enter Drop Date and Time (Format DD/MM/YYYY HH:MM in 24 hrs ) : ";
            cin >> appointment.dropTime>>appointment.dropDate;

            // Update book availability status
            for (auto& book : books) {
                if (book.isbn == appointment.bookISBN) {
                    book.isAvailable = true;
                    break;
                }
            }
gotoxy(76, 25);
            cout << "Book drop Appointment successfully booked!\n";
            getch();
            return;
            
        }
    }
gotoxy(70, 20);
    cout << "Book not found or not picked up. Please check the title or book status.\n";
    getch();
}
/*void gotoxy(int x, int y)
{
	static HANDLE h=NULL;
	if(!h)
	  h=GetStdHandle(STD_OUTPUT_HANDLE);
	  COORD c = { x, y };
	  SetConsoleCursorPosition(h,c);
}*/
void intro()
{   
    system("cls");
    gotoxy(50, 2);
    cout << "*********************************************************************************************\n";
    gotoxy(95, 5);
	cout << "WELCOME MENU \n";
	gotoxy(50, 7);
	cout << "*********************************************************************************************\n\n";
    gotoxy(95, 11);
    cout << "A PROJECT OF";
    gotoxy(92, 13);
    cout << "DEPARTMENTAL LIBRARY";
    gotoxy(92, 15);
    cout << "APPOINTMENT BOOKING";
    gotoxy(92, 17);
    cout << "& DETAILS OF BOOK";
    gotoxy(85, 22);
    cout << "MADE BY : CHAITANYA SALUNKHE \n \n \t\t\t\t\t\t\t\t\t\t\t\t SUJAL RANE \n \n \t\t\t\t\t\t\t\t\t\t\t\t ATHARVA RINGE \n \n \t\t\t\t\t\t\t\t\t\t\t\t SUMEDH JADHAV \n\n";
    gotoxy(85, 37);
    cout << "\t\t\t\t\t\t\t\t\t\tPROJECT GUIDE : PROF. SWAMI ASHVINI \n\n";
    gotoxy(80, 40);
    cout << "\t\t\t\t\t\t\t\t\tDEPARTMENT OF ARTIFICIAL INTELLIGENCE AND DATA SCIENCE \n \n ";
    gotoxy(80, 42);
    cout << "\t\t\t\t\t\t\t\t\tCOLLEGE : SHREE RAMCHANDRA COLLEGE OF ENGINEERING,PUNE.\n\n"<<endl;
    getch();
}

void displayBookAvailability() {system("cls");
gotoxy(60, 2);
cout << "*********************************************************************************************\n";
gotoxy(95, 5);
	cout << " BOOK AVAILABILITY MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(90, 15);
    cout << "Book Availability Status:\n";
    for (const auto& book : books) 
	{
    	
        cout << "Title: " << book.title<<" Author: "<< book.author<<"  ISBN :"<<book.isbn << "  \tAvailable: " << (book.isAvailable ? "Yes" : "No") << "\n";            
    } 
	getch();
}

int main() { intro();
    LoginSystem loginSystem;

    string choice, role, username, password;
system("cls");
gotoxy(60, 2);
cout << "*********************************************************************************************\n";
gotoxy(95, 5);
	cout << " MAIN MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(90, 15);
        cout << "1. Create an account";
        gotoxy(97, 18);
		cout << "2. Login\n";
		gotoxy(90, 21);
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
        	system("cls");
        	gotoxy(60, 2);
        	cout << "*********************************************************************************************\n";
        	gotoxy(90, 5);
	cout << " CREATE AN ACCOUNT MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(85, 15);
            cout << "Enter role (student/faculty): ";
            cin >> role;
gotoxy(95, 18);
            cout << "Enter username: ";
            cin >> username;
gotoxy(95, 21);
            cout << "Enter password: ";
            cin >> password;

            loginSystem.createAccount(username, password, role);
            
            
			
		}else if (choice == "2") {
			system("cls");
			gotoxy(60, 2);
			cout << "*********************************************************************************************\n";
			gotoxy(95, 5);
	cout << " LOGIN MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(85, 15);
            cout << "Enter role (student/faculty): ";
            cin >> role;
gotoxy(95, 18);
            cout << "Enter username: ";
            cin >> username;
gotoxy(95, 21);
            cout << "Enter password: ";
            cin >> password;

            loginSystem.login(username, password, role);
            if(role =="student"){
	   
	string detail, name, rollNo, className, de, address, telephoneNo, emergencyNo;
	gotoxy(60, 2);
	cout << "*********************************************************************************************\n";
	gotoxy(90, 5);
	cout << " INFORMATION DETAIL MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
gotoxy(95, 15);
	cout << " Enter Details:\n";
    getline(cin, detail);
    // Get input from the user
    gotoxy(90, 18);
    cout << "Enter Student Name: ";
    getline(cin, name);
gotoxy(90, 21);
    cout << "Enter Roll Number: ";
    getline(cin, rollNo);
gotoxy(95, 24);
    cout << " Enter Class: ";
    getline(cin, className);
gotoxy(92, 27);
    cout << "Enter Department: ";
    getline(cin, de);
gotoxy(95, 30);
    cout << "Enter Address: ";
    getline(cin, address);
gotoxy(90, 33);
    cout << "Enter Telephone Number: ";
    getline(cin, telephoneNo);
gotoxy(90, 36);
    cout << "Enter Emergency Number: ";
    getline(cin, emergencyNo);

    //string name, rollNo, className, de, address, telephoneNo, emergencyNo;

	// Check if the department is "Ai ds"
	if (de == "Ai ds"||de =="Artificial Intelligence and Data Science"||de =="Artificial Intelligence & Data Science"||de =="AI & DS"||de =="aids"||de =="Aids"||de =="AIDS"||de =="AI DS"||de =="AI and DS") 
	{ system("cls");
        // Display the entered information
        gotoxy(60, 2);
        cout << "*********************************************************************************************\n";
        gotoxy(85, 5);
	cout << " ENTERED INFORMATION DETAILS MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(95, 15);
        cout << "Detail Information:\n";
        gotoxy(95, 18);
        cout << "Name: " << name << "\n";
        gotoxy(95, 21);
        cout << "Roll Number: " << rollNo << "\n";
        gotoxy(95, 24);
        cout << "Class: " << className << "\n";
        gotoxy(95, 27);
        cout << "Department: " << de << "\n";
        gotoxy(95, 30);
        cout << "Address: " << address << "\n";
        gotoxy(92, 33);
        cout << "Telephone Number: " << telephoneNo << "\n";
        gotoxy(92, 36);
        cout << "Emergency Number: " << emergencyNo << "\n";
    getch();
        initializeBooks();

    int choice;

    do {
        displayMenu();
        gotoxy(93, 28);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookPickup();
                break;
            case 2:
                bookDrop();
                break;
            case 3:
                displayBookAvailability();
                break;
            case 4:gotoxy(93, 30);
                cout << "Exiting program.\n";
                break;
            default:gotoxy(90, 32);
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);
    } 
	else {gotoxy(85, 34);
        cout << " Error!!! The department is not Ai & ds. Program terminated.\n";
    }
}
if(role=="faculty"){
	string detail, name, de, address, telephoneNo, emergencyNo;
	gotoxy(60, 2);
	cout << "*********************************************************************************************\n";
	gotoxy(90, 5);
	cout << " INFORMATION DETAILS MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(93, 15);
	cout << "Enter Your Details: \n";
    getline(cin, detail);
    gotoxy(93, 18);
	cout << "Enter Faculty Name: ";
    getline(cin, name);
    gotoxy(92, 21);
    cout << "Enter Department: ";
    getline(cin, de);
gotoxy(95, 24);
    cout << "Enter Address: ";
    getline(cin, address);
gotoxy(92, 27);
    cout << "Enter Telephone Number: ";
    getline(cin, telephoneNo);
gotoxy(92, 30);
    cout << "Enter Emergency Number: ";
    getline(cin, emergencyNo);
    
    	if (de == "Ai ds"||de =="Artificial Intelligence and Data Science"||de =="Artificial Intelligence & Data Science"||de =="AI & DS"||de =="aids"||de =="Aids"||de =="AIDS"||de =="AI DS"||de =="AI and DS") 
	{system("cls");
        // Display the entered information
        gotoxy(60, 2);
        cout << "\n\n*********************************************************************************************\n";
        gotoxy(95, 5);
	cout << "\t\t\t\t ENTERED INFORMATION DETAILS MENU \n";
	gotoxy(60, 7);
	cout << "*********************************************************************************************\n\n";
	gotoxy(90, 15);
        cout << "\nDetail Information:\n";
        gotoxy(95, 18);
        cout << "\nName: " << name << "\n";
        gotoxy(92, 21);
        cout << "\nDepartment: " << de << "\n";
        gotoxy(92, 24);
        cout << "\nAddress: " << address << "\n";
        gotoxy(92, 27);
        cout << "\nTelephone Number: " << telephoneNo << "\n";
        gotoxy(92, 30);
        cout << "\nEmergency Number: " << emergencyNo << "\n";
    getch();
        initializeBooks();

    int choice;

    do {
        displayMenu();
        gotoxy(93, 28);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bookPickup();
                break;
            case 2:
                bookDrop();
                break;
            case 3:
                displayBookAvailability();
                break;
            case 4:
            	gotoxy(93, 30);
                cout << "Exiting program.\n";
                break;
            default:
            	gotoxy(90, 32);
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);
    } 
	else {gotoxy(80, 34);
        cout << " Error!!! The department is not Ai & ds. Program terminated.\n";
        
        
        } 
}
}
    return 0;
}

