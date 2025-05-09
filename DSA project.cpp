#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>
using namespace std;

struct Medicine {
    int id;
    string name;
    float price;
    int stock;
    Medicine* next;
};

struct StackNode {
    int medicineId;
    StackNode* next;
};

struct QueueNode {
    int medicineId;
    int quantity;
    QueueNode* next;
};

Medicine* head = NULL;
StackNode* returnTop = NULL;
QueueNode* purchaseFront = NULL;
QueueNode* purchaseRear = NULL;

void displayCurrentDateTime() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char timeStr[100];
    strftime(timeStr, sizeof(timeStr), "%A, %B %d, %Y %I:%M:%S %p", localTime);
    cout << "\nCurrent Date and Time: " << timeStr << "\n";
}

void addMedicine(int id, string name, float price, int stock) {
    Medicine* newMed = new Medicine{id, name, price, stock, NULL};
    if (head == NULL) {
        head = newMed;
    } else {
        Medicine* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newMed;
    }
}

void displayMedicines() {
    Medicine* temp = head;
    cout << "\n---------------------------------------------------------\n";
    cout << "ID\tName\t\t\tPrice\t\tStock\n";
    cout << "---------------------------------------------------------\n";
    while (temp != NULL) {
        cout << left << temp->id << "\t"
             << setw(20) << temp->name << "\t"
             << fixed << setprecision(2) << temp->price << "\t"
             << "\t" << temp->stock << endl;
        temp = temp->next;
    }
    cout << "---------------------------------------------------------\n";
}

void purchaseMedicine(int id, int quantity) {
    QueueNode* newNode = new QueueNode{id, quantity, NULL};
    if (purchaseFront == NULL) {
        purchaseFront = purchaseRear = newNode;
    } else {
        purchaseRear->next = newNode;
        purchaseRear = newNode;
    }

    Medicine* med = head;
    while (med != NULL) {
        if (med->id == id) {
            if (med->stock >= quantity) {
                med->stock -= quantity;
                float total = med->price * quantity;
                cout << "\n--- Purchase Summary ---\n";
                cout << "Medicine: " << med->name << "\nQuantity: " << quantity << "\nTotal Bill: RS " << total << "\n";
            } else {
                cout << "Insufficient stock available!\n";
            }
            break;
        }
        med = med->next;
    }
    displayCurrentDateTime();
}

void returnMedicine(int id, int quantity) {
    Medicine* med = head;
    while (med != NULL) {
        if (med->id == id) {
            float refund = med->price * quantity;
            med->stock += quantity;

            for (int i = 0; i < quantity; i++) {
                StackNode* newNode = new StackNode{id, returnTop};
                returnTop = newNode;
            }

            cout << quantity << " medicine(s) with ID " << id << " returned successfully!\n";
            cout << "Refund Amount: RS " << fixed << setprecision(2) << refund << endl;
            displayCurrentDateTime();
            return;
        }
        med = med->next;
    }
    cout << "Medicine ID not found!\n";
}

void exchangeMedicine(int oldId, int newId, int quantity) {
    Medicine* oldMed = NULL;
    Medicine* newMed = NULL;
    Medicine* temp = head;

    while (temp != NULL) {
        if (temp->id == oldId) oldMed = temp;
        if (temp->id == newId) newMed = temp;
        temp = temp->next;
    }

    if (oldMed && newMed) {
        if (newMed->stock >= quantity && oldMed->stock >= quantity) {
            float oldTotal = oldMed->price * quantity;
            float newTotal = newMed->price * quantity;
            float difference = newTotal - oldTotal;

            oldMed->stock += quantity;
            newMed->stock -= quantity;

            for (int i = 0; i < quantity; i++) {
                StackNode* newNode = new StackNode{newId, returnTop};
                returnTop = newNode;
            }

            cout << "\n--- Exchange Summary ---\n";
            cout << "Exchanged " << quantity << " medicine(s).\n";
            cout << "Old Medicine: " << oldMed->name << " (RS " << oldMed->price << " each)\n";
            cout << "New Medicine: " << newMed->name << " (RS " << newMed->price << " each)\n";

            if (difference > 0) {
                cout << "Additional Charge: RS " << fixed << setprecision(2) << difference << endl;
            } else if (difference < 0) {
                cout << "Refund Amount: RS " << fixed << setprecision(2) << -difference << endl;
            } else {
                cout << "No price difference. Exchange successful.\n";
            }

            displayCurrentDateTime();
        } else {
            cout << "Insufficient stock for exchange!\n";
        }
    } else {
        cout << "Invalid medicine IDs!\n";
    }
}

void diagnoseDisease() {
    int choice;
    cout << "\nSelect your disease:\n";
    cout << "1. Fever\n2. Cold\n3. Headache\n4. Stomach Ache\n5. Allergy\n";
    cout << "6. Diabetes\n7. Blood Pressure\n8. Infection\n9. Cough\n10. Sore Throat\n";
    cout << "Enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 10) {
        cout << "Invalid input! Please enter a number between 1 and 10: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n--- Diagnosis Result ---\n";
    switch (choice) {
        case 1: cout << "Suggested: Crocin, Paracetamol\n"; break;
        case 2: cout << "Suggested: Cetirizine, Dolo Cold\n"; break;
        case 3: cout << "Suggested: Saridon, Headset\n"; break;
        case 4: cout << "Suggested: Eno, Digene\n"; break;
        case 5: cout << "Suggested: Allegra, Zyrtec\n"; break;
        case 6: cout << "Suggested: Metformin, Januvia\n"; break;
        case 7: cout << "Suggested: Amlodipine, Losartan\n"; break;
        case 8: cout << "Suggested: Antibiotics (Amoxicillin)\n"; break;
        case 9: cout << "Suggested: Cough Syrup, Benadryl\n"; break;
        case 10: cout << "Suggested: Strepsils, Vicks\n"; break;
        default: cout << "Invalid choice!\n";
    }
    displayCurrentDateTime();
}

Medicine* findMedicineById(int id) {
    Medicine* temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int getValidIntInput(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value) || value < 0) {
        cout << "Invalid input! Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

float getValidFloatInput(string prompt) {
    float value;
    cout << prompt;
    while (!(cin >> value) || value < 0.0f) {
        cout << "Invalid input! Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

int main() {
    int choice, id, newId, quantity, stock;
    string name;
    float price;

    addMedicine(101, "Crocin", 10.5, 50);
    addMedicine(102, "Paracetamol", 15.0, 60);
    addMedicine(103, "Cetirizine", 20.0, 40);
    addMedicine(104, "Saridon", 18.5, 30);
    addMedicine(105, "Eno", 12.0, 25);
    addMedicine(106, "Dolo650", 16.0, 50);
    addMedicine(107, "Amoxicillin", 22.5, 35);
    addMedicine(108, "Benadryl", 14.0, 45);
    addMedicine(109, "Digene", 11.5, 20);
    addMedicine(110, "Amlodipine", 19.0, 30);
    addMedicine(111, "Losartan", 25.0, 25);
    addMedicine(112, "Metformin", 30.0, 30);
    addMedicine(113, "Strepsils", 9.0, 60);
    addMedicine(114, "Vicks", 8.5, 50);

    cout << "\n===  CureCart Pharmacy  ===\n";

    while (true) {
        cout << "\n---------------------------------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Display Available Medicines\n";
        cout << "2. Add New Medicine\n";
        cout << "3. Purchase Medicine\n";
        cout << "4. Return Medicine\n";
        cout << "5. Exchange Medicine\n";
        cout << "6. Diagnose Disease\n";
        cout << "7. Exit\n";
        cout << "---------------------------------------------------------\n";

        while (true) {
            choice = getValidIntInput("Enter your choice: ");
            if (choice >= 1 && choice <= 7) {
                break;
            } else {
                cout << "Invalid choice! Please try again.\n";
            }
        }

        switch (choice) {
            case 1:
                displayMedicines();
                break;

            case 2:
                id = getValidIntInput("Enter new Medicine ID: ");
                if (findMedicineById(id)) {
                    cout << "Medicine ID already exists!\n";
                    break;
                }
                cout << "Enter Medicine Name: ";
                cin.ignore();
                getline(cin, name);
                price = getValidFloatInput("Enter Price: ");
                stock = getValidIntInput("Enter Stock: ");
                addMedicine(id, name, price, stock);
                cout << "Medicine added successfully!\n";
                break;

            case 3:
                displayMedicines();
                id = getValidIntInput("Enter Medicine ID to purchase: ");
                if (findMedicineById(id)) {
                    quantity = getValidIntInput("Enter quantity: ");
                    purchaseMedicine(id, quantity);
                } else {
                    cout << "Medicine ID not found!\n";
                }
                break;

            case 4:
                id = getValidIntInput("Enter Medicine ID to return: ");
                if (findMedicineById(id)) {
                    quantity = getValidIntInput("Enter quantity: ");
                    returnMedicine(id, quantity);
                } else {
                    cout << "Medicine ID not found!\n";
                }
                break;

            case 5:
                id = getValidIntInput("Enter Old Medicine ID to exchange: ");
                newId = getValidIntInput("Enter New Medicine ID to get: ");
                if (findMedicineById(id) && findMedicineById(newId)) {
                    quantity = getValidIntInput("Enter quantity: ");
                    exchangeMedicine(id, newId, quantity);
                } else {
                    cout << "Invalid Medicine IDs!\n";
                }
                break;

            case 6:
                diagnoseDisease();
                break;

            case 7:
                cout << "\nThank you for visiting CureCart Pharmacy!\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

