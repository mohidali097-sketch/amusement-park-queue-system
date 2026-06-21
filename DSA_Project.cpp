#include <iostream>
#include <string>
using namespace std;

enum TicketType 
{
    
    VIP = 3,
    FASTPASS = 2,
    REGULAR = 1

};

class Customer 
{

public:

    int id;
    string name;
    int age;
    TicketType ticketType;

    Customer() 
    {

        id = 0;
        age = 0;
        ticketType = REGULAR;

    }

    Customer(int i, string n, int a, TicketType t) 
    {

        id = i;
        name = n;
        age = a;
        ticketType = t;

    }

    int getPriority() const 
    {

        return ticketType;

    }

    void display() const 
    {

        cout << "ID: " << id << " Name: " << name << " Age: " << age << " Ticket: ";
        if (ticketType == VIP) cout << "VIP";
        else if (ticketType == FASTPASS) cout << "FastPass";
        else cout << "Regular";
        cout << endl;

    }


};

struct Node 
{

    Customer data;
    int priority;
    Node* next;

};

class PriorityQueue 
{

    Node* front;

public:

    PriorityQueue() 
    {

        front = NULL;

    }

    bool isEmpty() 
    {

        return front == NULL;

    }

    void enqueue(Customer c) 
    {

        Node* n = new Node;
        n->data = c;
        n->priority = c.getPriority();
        n->next = NULL;

        if (!front || n->priority > front->priority) 
        {

            n->next = front;
            front = n;
            return;

        }


        Node* temp = front;
        while (temp->next && temp->next->priority >= n->priority)
            temp = temp->next;

        n->next = temp->next;
        temp->next = n;

    }

    Customer dequeue() 
    {

        if (!front) return Customer();
        Node* temp = front;
        Customer c = temp->data;
        front = front->next;
        delete temp;
        return c;

    }

    bool search(int id) 
    {

        Node* temp = front;
        while (temp) 
        {

            if (temp->data.id == id) 
            {

                temp->data.display();
                return true;

            }

            temp = temp->next;

        }

        return false;

    }

    bool remove(int id) 
    {

        if (!front) 
            return false;

        if (front->data.id == id) 
        {

            Node* temp = front;
            front = front->next;
            delete temp;
            return true;

        }

        Node* prev = front;
        Node* cur = front->next;

        while (cur) 
        {

            if (cur->data.id == id) 
            {

                prev->next = cur->next;
                delete cur;
                return true;

            }

            prev = cur;
            cur = cur->next;

        }

        return false;

    }

    void display() 
    {

        Node* temp = front;

        if (!temp) 
        {

            cout << "No customers\n";
            return;

        }

        while (temp) 
        {

            temp->data.display();
            temp = temp->next;

        }

    }

};

void ferrisWheelSimulation(PriorityQueue& q) 
{

    Customer wheel[6];
    int pause;

    cout << "\nFerris Wheel Simulation\n";

    while (!q.isEmpty()) 
    {

        for (int i = 5; i > 0; i--)
            wheel[i] = wheel[i - 1];
        wheel[0] = q.dequeue();


        cout << "    " << wheel[4].id << "       " << wheel[3].id << endl;
        cout << "      \\   /\n";
        cout << "       \\_/\n";
        cout << " " << wheel[5].id << "  __/   \\__" << wheel[2].id << endl;
        cout << "       \\_/\n";
        cout << "       /  \\\n";
        cout << "      /    \\\n";
        cout << "    " << wheel[0].id << "       " << wheel[1].id << endl;


        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

    while (true) 
    {

        bool any = false;
        for (int i = 0; i < 6; i++) if (wheel[i].id) any = true;
        if (!any) break;

        for (int i = 5; i > 0; i--)
            wheel[i] = wheel[i - 1];
        wheel[0] = Customer();


        cout << "    " << wheel[4].id << "       " << wheel[3].id << endl;
        cout << "      \\   /\n";
        cout << "       \\_/\n";
        cout << " " << wheel[5].id << "  __/   \\__" << wheel[2].id << endl;
        cout << "       \\_/\n";
        cout << "       /  \\\n";
        cout << "      /    \\\n";
        cout << "    " << wheel[0].id << "       " << wheel[1].id << endl;


        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

}

void merryGoRoundSimulation(PriorityQueue& q) 
{

    Customer seats[12];
    int pause;

    cout << "\nMerry Go Round Simulation\n";

    while (!q.isEmpty()) 
    {

        for (int i = 11; i > 0; i--)
            seats[i] = seats[i - 1];
        seats[0] = q.dequeue();


        cout << "        " << seats[3].id << "   " << seats[4].id << endl;
        cout << "    " << seats[2].id << "                 " << seats[5].id << endl;
        cout << seats[1].id << "                         " << seats[6].id << endl;
        cout << "    " << seats[0].id << "                 " << seats[7].id << endl;
        cout << "        " << seats[11].id << "   " << seats[8].id << endl;
        cout << "            " << seats[10].id << " " << seats[9].id << endl;


        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

    while (true) 
    {

        bool any = false;
        for (int i = 0; i < 12; i++) if (seats[i].id) any = true;
        if (!any) break;

        for (int i = 11; i > 0; i--)
            seats[i] = seats[i - 1];
        seats[0] = Customer();


        cout << "        " << seats[3].id << "   " << seats[4].id << endl;
        cout << "    " << seats[2].id << "                 " << seats[5].id << endl;
        cout << seats[1].id << "                         " << seats[6].id << endl;
        cout << "    " << seats[0].id << "                 " << seats[7].id << endl;
        cout << "        " << seats[11].id << "   " << seats[8].id << endl;
        cout << "            " << seats[10].id << " " << seats[9].id << endl;


        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

}

void rollerCoasterSimulation(PriorityQueue& q) 
{

    Customer cars[6];
    int pause;

    cout << "\nRoller Coaster Simulation\n";

    while (!q.isEmpty()) 
    {

        for (int i = 5; i > 0; i--)
            cars[i] = cars[i - 1];
        cars[0] = q.dequeue();


        cout << "[ ";
        for (int i = 0; i < 6; i++)
            cout << cars[i].id << " ]--";
        cout << ">\n";


        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

    while (true) 
    {

        bool any = false;
        for (int i = 0; i < 6; i++) if (cars[i].id) any = true;
        if (!any) break;

        for (int i = 5; i > 0; i--)
            cars[i] = cars[i - 1];
        cars[0] = Customer();

        cout << "[ ";
        for (int i = 0; i < 6; i++)
            cout << cars[i].id << " ]--";
        cout << ">\n";

        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

}

void dropTowerSimulation(PriorityQueue& q) 
{

    const int N = 5;
    Customer tower[N];
    int pause;


    for (int i = 0; i < N; i++)
        tower[i] = Customer();


    cout << "\nDrop Tower Simulation\n";

    int riders = 0;
    while (!q.isEmpty() && riders < N - 1) 
    {

        tower[riders] = q.dequeue();
        riders++;

    }

    int position = 0;  

    for (int i = N - 1; i >= 0; i--) 
    {

        cout << "| ";
        if (i >= position && i < position + riders)
            cout << tower[i - position].id;

        else
            cout << " ";
        cout << " |\n";

    }

    cout << "-----\n";

    cout << "\nPress any number to move the simulation: ";
    cin >> pause;
    system("cls");

    while (position + riders < N) 
    {

        position++;

        for (int i = N - 1; i >= 0; i--) 
        {

            cout << "| ";
            if (i >= position && i < position + riders)
                cout << tower[i - position].id;

            else
                cout << " ";
            cout << " |\n";

        }

        cout << "-----\n";

        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

    cout << "Reached Top...\n";
    for (int i = N - 1; i >= 0; i--) 
    {

        cout << "| ";
        if (i >= position && i < position + riders)
            cout << tower[i - position].id;

        else
            cout << " ";
        cout << " |\n";

    }

    cout << "-----\n";

    cout << "\nPress any number to move the simulation: ";
    cin >> pause;
    system("cls");

    while (position > 0) 
    {

        position--;

        for (int i = N - 1; i >= 0; i--) 
        {

            cout << "| ";
            if (i >= position && i < position + riders)
                cout << tower[i - position].id;

            else
                cout << " ";
            cout << " |\n";

        }

        cout << "-----\n";

        cout << "\nPress any number to move the simulation: ";
        cin >> pause;
        system("cls");

    }

}


int main() 
{

    PriorityQueue ferris, merry, roller, drop;
    int choice;

    do 
    {


        cout << "\n1 Add Customer\n2 Run Simulation\n3 Search Customer\n4 Delete Customer\n5 Display Queues\n6 Exit\n";


        cout << "Enter the choice : ";
        cin >> choice;


        if (choice == 1) 
        {


            int id, age, t, r;
            string name;


            cout << "Customer ID: ";
            cin >> id;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Age: ";
            cin >> age;
            cout << "Ticket 1 VIP 2 FastPass 3 Regular: ";
            cin >> t;
            cout << "Ride 1 Ferris 2 Merry 3 Roller 4 DropTower: ";
            cin >> r;


            Customer c(id, name, age, (TicketType)t);

            if (r == 1) ferris.enqueue(c);
            else if (r == 2) merry.enqueue(c);
            else if (r == 3) roller.enqueue(c);
            else if (r == 4) drop.enqueue(c);

        }

        else if (choice == 2) 
        {

            int r;
            cout << "Ride 1 Ferris 2 Merry 3 Roller 4 DropTower: ";
            cin >> r;

            if (r == 1) ferrisWheelSimulation(ferris);
            else if (r == 2) merryGoRoundSimulation(merry);
            else if (r == 3) rollerCoasterSimulation(roller);
            else if (r == 4) dropTowerSimulation(drop);

        }

        else if (choice == 3) 
        {

            int id;
            cout << "Enter the id  : ";
            cin >> id;

            if (!ferris.search(id) && !merry.search(id) && !roller.search(id) && !drop.search(id))
                cout << "Not found\n";

        }

        else if (choice == 4) 
        {

            int id;
            cout << "Enter the id :  ";
            cin >> id;

            if (ferris.remove(id) || merry.remove(id) || roller.remove(id) || drop.remove(id))
                cout << "Deleted\n";
            else
                cout << "Not found\n";

        }

        else if (choice == 5) 
        {

            cout << "\nFerris\n"; ferris.display();
            cout << "\nMerry\n"; merry.display();
            cout << "\nRoller\n"; roller.display();
            cout << "\nDropTower\n"; drop.display();

        }

    } while (choice != 6);

    return 0;

}
