#include <iostream>
#include <iomanip>
# include <string>
using namespace std;

struct Node {

    int id;
    int sNumber;
    string Name;
    int contact;
    string email;
    string enquiry;
    string date;
    Node* nPtr;
};

struct node
{
    int id;
    int sNumber;
    string Name;
    int contact;
    string email;
    string enquiry;
    string date;
    node* nPtr;
};

// Stores the head of the Linked List
Node* head = new Node();
node* head2 = new node();

//validating
bool check(int x)
{
    // Base Case
    if (head == NULL)
        return false;
    Node* t = new Node;
    t = head; 
    while (t != NULL) {
        if (t->id == x)
            return true;
        t = t->nPtr;
    }

    return false;
}

bool check2(int x)
{
    // Base Case
    if (head2 == NULL)
        return false;

    node* h = new node();
    h = head2;

    
    while (h != NULL) {
        if (h->id == x)
            return true;
        h = h->nPtr;
    }

    return false;
}


//Inserting to Enquiry
void Insert_Record(int id, int sNumber, string Name, int contact, string email, string enquiry, string date)
{
    if (check(id)) {
        cout << "Enquiry ID "
            << "Already Exists\n";
        return;
    }
    // Creating Node to Insert Record
    Node* t = new Node();
    t->id = id;
    t->sNumber = sNumber;
    t->Name = Name;
    t->contact = contact;
    t->email = email;
    t->enquiry = enquiry;
    t->date = date;

    t->nPtr = NULL;

    if (head == NULL
        || (head->id >= t->id)) {
        t->nPtr = head;
        head = t;
    } else {
        Node* c = head;
        while (c->nPtr != NULL
            && c->nPtr->id < t->id) {
            c = c->nPtr;
        }
        t->nPtr = c->nPtr;
        c->nPtr = t;
    }

    cout << "Record Inserted "
        << "Successfully\n";
}
//updaating 


//Search
void Search(int id)
{
   
    if (!head) {
        cout << "No Record "
            << "Avialable it that ID\n";
        return;
    }

    
    else {

        cout << "Enquiy ID\tStu number\tName\tContact\t\tEmail\t\t\tEnquiry"
            << "\tDate\n";

        Node* Per = head;
        while (Per) {
            if (Per->id == id) {
                cout << Per->id << "    \t\t"
                    << Per->sNumber << "\t\t"
                    << Per->Name << "\t"
                    << Per->contact << "\t"
                    << Per->email << "\t"
                    << Per->enquiry << "\t"
                    << Per->date << endl;
                return;
            }
            Per = Per->nPtr;
        }

        if (Per == NULL)
            cout << "No such Record "
            << "Avialable\n";
    }
}
//All the Record 
void allRecord()
{
    Node* Per = head;
    if (Per == NULL) {
        cout << "No Record "
            << "Available\n";
    }
    else {
        cout << "ID\tno\tName\tContact_no\tEmail\tEnquiry"
            << "\tDate\n";

        // Until per is not NULL
        while (Per != NULL) {
            cout << Per->id << "    \t"
                << Per->sNumber << "\t"
                << Per->Name << "\t"
                << Per->contact << "\t"
                << Per->email << "\t"
                << Per->enquiry << "\t"
                << Per->date << endl;
            Per = Per->nPtr;
        }
    }
}

// delete record
int Delete(int id)
{
    Node* t = head;
    Node* p = NULL;

    //Begin
    if (t != NULL
        && t->id == id) {
        head = t->nPtr;
        delete t;

        cout << "Record Deleted "
            << "Successfully\n";
        return 0;
    }

    
    while (t != NULL && t->id != id) {
        p = t;
        t = t->nPtr;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        p->nPtr = t->nPtr;

        delete t;
        cout << "Record Deleted "
            << "Successfully\n";

        return 0;
    }
}




// Driver code
void Insert_to_delete(int id, int sNumber, string Name, int cnum, string email, string enquiry, string date);
void Show_delete_Record();

int main()
{
    head = NULL;
    string Name, email, enquiry, date;
    int id, id2, contact, sNumber;

    // Menu-driven program
    while (true) {

        cout << "\n\t\tStudent Service "
            "Information Desk\n\t\t_______________________________\n\n[1] = to "
            "Add new Enquiry\n[2] = to delete a "
            "student Enquiry\n[3] = to Search a Student "
            "Enquiry\n[4] = to view all students  "
            "Enquiries\n[5] = View deleted records\n"
            "[6] = To Update a Enquiry\n";
        cout << "\nEnter the Number:\n";
        int Choice;

        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Enquiry ID:\n";
            cin >> id;
            cout << "Enter Student no:\n";
            cin >> sNumber;
            cout << "Enter student name: \n";
            cin >> Name;
            cout << "Enter student contact number:\n";
            cin >> contact;
            cout << "Enter student email:\n";
            cin >> email;
            cout << "Enter Enquiry:\n";
            cin >> enquiry;
            cout << "Enter date:\n";
            cin >> date;
            Insert_Record(id, sNumber, Name, contact, email, enquiry, date);
        }
        else if (Choice == 2) {
            cout << "Enter ID of Student whose "
                "record is to be deleted\n";
            cin >> id2;


            if (!head) {
                cout << "No such Record "
                    << "Avialable\n";

            }

            // Otherwise
            else {
                Node* y = head;
                while (y) {
                    if (y->id == id2) {


                        Insert_to_delete(y->id, y->sNumber, y->Name, y->contact, y->email, y->enquiry, y->date);


                    }
                    y = y->nPtr;
                }

                if (y == NULL)
                    cout << "No such Record "
                    << "Avialable\n";
            }

            Delete(id2);

        }
        else if (Choice == 3) {
            cout << "Enter ID of Student whose "
                "record you want to Search\n";
            cin >> id;
            Search(id);
        }
        else if (Choice == 4) {
            allRecord();
        }
        else if (Choice == 5) {
            Show_delete_Record();
        }
        else {
            cout << "Invalid Choice "
                << "Try Again\n";
        }
    }
    return 0;
}

void Insert_to_delete(int id, int sNumber, string Name, int contact, string email, string enquiry, string date)
{
      // Create new Node to Insert Record
    node* ItD = new node();
    ItD->id = id;
    ItD->sNumber = sNumber;
    ItD->Name = Name;
    ItD->contact = contact;
    ItD->email = email;
    ItD->enquiry = enquiry;
    ItD->date = date;

    ItD->nPtr = NULL;

    // Begin
    if (head2 == NULL
        || (head2->id >= ItD->id)) {
        ItD->nPtr = head2;
        head2 = ItD;
    }

    //End
    else {
        node* A = head2;
        while (A->nPtr != NULL
            && A->nPtr->id < A->id) {
            A = A->nPtr;
        }
        ItD->nPtr = A->nPtr;
        A->nPtr = ItD;
    }

    
    cout << "Record Inserted "
        << "Successfully\n";
}

void Show_delete_Record()
{
    node* p = head2;
    if (p == NULL) {
        cout << "No Record "
            << "Available\n";
    }
    else {
        cout << "ID\tno\tName\tContact_no\tEmail\tEnquiry"
            << "\tDate\n";

        // Until p is not NULL
        while (p != NULL) {
            cout << p->id << "    \t"
                << p->sNumber << "\t"
                << p->Name << "\t"
                << p->contact << "\t"
                << p->email << "\t"
                << p->enquiry << "\t"
                << p->date << endl;
            p = p->nPtr;
        }
    }
}




