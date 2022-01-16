#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
int bus_count = 0;

typedef struct bus_node *listptr;

class bus_node
{
public:
    char name[20];
    char destination[10];
    int bus_capacity;
    int bus_seats[100];
    struct bus_node *link;
};

listptr first = NULL;
listptr prev = NULL;

void add_bus()
{
    int i = 0;
    if (first == NULL)
    {
        listptr newnode = new bus_node();
        std::cout << "enter the bus name: ";
        std::cin >> newnode->name;
        std::cout << "enter the bus destination: ";
        std::cin >> newnode->destination;
        std::cout << "enter the bus capacity: ";
        std::cin >> newnode->bus_capacity;
        for (; i < newnode->bus_capacity; i++)
        {
            newnode->bus_seats[i] = 0;
        }
        newnode->bus_seats[i] = -1;
        newnode->link = prev;
        first = newnode;
        prev = newnode;
        bus_count++;
    }
    else
    {

        listptr newnode = new bus_node();
        std::cout << "enter the bus name: ";
        std::cin >> newnode->name;
        std::cout << "enter the bus destination: ";
        std::cin >> newnode->destination;
        std::cout << "enter the bus capacity: ";
        std::cin >> newnode->bus_capacity;
        for (; i < newnode->bus_capacity; i++)
        {
            newnode->bus_seats[i] = 0;
        }
        newnode->bus_seats[i] = -1;
        newnode->link = NULL;
        prev->link = newnode;
        prev = newnode;
        bus_count++;
    }
}

void display()
{
    listptr aux;
    if (first == NULL)
    {
        std::cout << "NO BUSES ARE AVAILABLE TO DISPLAY...\n";
        return;
    }
    int choice, i = 0, j = 0;
    std::cout << "THE BUSES AVAILABLE ARE:\n\n";
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        std::cout << "THE BUS " << i + 1 << " NAME IS: " << temp->name << std::endl;
        std::cout << "THE BUS " << i + 1 << " DESTINATION IS: " << temp->destination << std::endl;
        std::cout << "THE BUS " << i + 1 << " CAPACITY IS: " << temp->bus_capacity << std::endl
                  << std::endl;
        i++;
    }

    std::cout << "Press 1 for checking bus reservation of a bus: \nPress 2 for exit: ";
    std::cin >> choice;
    if (choice == 2)
    {
        return;
    }
    else if (choice != 1)
    {
        std::cout << "INVALID CHOICE....\n";
        return;
    }
    std::cout << "enter the bus number : ";
    std::cin >> choice;
    if (choice >= 0)
    {
        std::cout << "\n0 -> non reserved seats || 1 -> reserved seats :\n\n";
        listptr temp = first;
        for (; (temp->link != NULL && --choice > 0); temp = temp->link)
            ;
        for (i = 0; i < temp->bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (temp->bus_seats[(4 * i) + j] == -1)
                {
                    std::cout << "\n\n";
                    return;
                }
                printf("%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j]);
            }
            std::cout << "\n";
        }
    }
    std::cout << "\n\n";
}

void reserve()
{
    if (first == NULL)
    {
        std::cout << "NO BUSES ARE AVAILABLE TO RESERVE SEAT...\n";
        return;
    }
    int res, seat, j = 0, i = 0;
    std::cout << "THE BUSES AVAILABLE ARE:\n\n";
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        std::cout << "THE BUS " << i + 1 << " NAME IS: " << temp->name << std::endl;
        std::cout << "THE BUS " << i + 1 << " DESTINATION IS: " << temp->destination << std::endl;
        std::cout << "THE BUS " << i + 1 << " CAPACITY IS: " << temp->bus_capacity << std::endl
                  << std::endl;
        i++;
    }
    std::cout << "select the bus whose seat needs to be reserved: ";
    std::cin >> res;
    if (res <= bus_count && res > 0)
    {
        std::cout << "\n0 -> non reserved seats || 1 -> reserved seats :\n\n";
        listptr temp = first;
        for (; (temp->link != NULL && --res > 0); temp = temp->link)
            ;
        for (i = 0; i < temp->bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (temp->bus_seats[(4 * i) + j] == -1)
                {
                    std::cout << "\n\n";
                    break;
                }
                //std::cout<<"%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j];
                printf("%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j]);
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
        std::cout << "\nselect the seat to be reserved: ";
        std::cin >> seat;
        --seat;
        if (seat >= 0 && seat < temp->bus_capacity)
        {
            if (temp->bus_seats[seat] == 1)
            {
                std::cout << "ENTERED SEAT IS ALREADY RESERVED!!!...\n";
                return;
            }
            temp->bus_seats[seat] = 1;
            std::cout << "\nSEAT " << ++seat << " IS RESERVED IN BUS " << temp->name << "!!!\n";
            std::cout << "\n\n";
            return;
        }
        else
        {
            std::cout << "invalid seat number!!!\n";
            return;
        }
    }
    else
    {
        std::cout << "invalid bus number\n";
        return;
    }
}

void delete_reservation()
{
    if (first == NULL)
    {
        std::cout << "NO BUSES ARE AVAILABLE TO RESERVE SEAT...\n";
        return;
    }
    int res, seat, j = 0, i = 0;
    std::cout << "THE BUSES AVAILABLE ARE:\n\n";
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        std::cout << "THE BUS " << i + 1 << " NAME IS: " << temp->name << std::endl;
        std::cout << "THE BUS " << i + 1 << " DESTINATION IS: " << temp->destination << std::endl;
        std::cout << "THE BUS " << i + 1 << " CAPACITY IS: " << temp->bus_capacity << std::endl
                  << std::endl;
        i++;
    }
    std::cout << "select the bus whose seat needs to be reserved: ";
    std::cin >> res;
    if (res <= bus_count && res > 0)
    {
        std::cout << "\n0 -> non reserved seats || 1 -> reserved seats :\n\n";
        listptr temp = first;
        for (; (temp->link != NULL && --res > 0); temp = temp->link)
            ;
        for (i = 0; i < temp->bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (temp->bus_seats[(4 * i) + j] == -1)
                {
                    std::cout << "\n\n";
                    break;
                }
                printf("%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j]);
            }
            std::cout << std::endl;
        }
        std::cout << "\n\n";
        std::cout << "\nselect the seat : ";
        std::cin >> seat;
        --seat;
        if (seat >= 0 && seat < temp->bus_capacity)
        {
            if (temp->bus_seats[seat] == 0)
            {
                std::cout << "ENTERED SEAT IS ALREADY NOT RESERVED!!!...\n";
                return;
            }
            temp->bus_seats[seat] = 0;
            std::cout << "RESERVATION OF SEAT " << ++seat << " IS REMOVED FROM THE BUS " << temp->name << "!!!\n";
            return;
        }
        else
        {
            std::cout << "invalid seat number!!!\n";
            return;
        }
    }
    else
    {
        std::cout << "invalid bus number!!!\n";
    }
}

void delete_bus()
{
    int pos;
    listptr aux;
    if (first == NULL)
    {
        std::cout << "NO BUSES ARE AVAILABLE TO DELETE...\n";
        return;
    }
    int choice, i = 0, j = 0;
    std::cout << "THE BUSES AVAILABLE ARE:\n\n";
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        std::cout << "THE BUS " << i + 1 << " NAME IS: " << temp->name << std::endl;
        std::cout << "THE BUS " << i + 1 << " DESTINATION IS: " << temp->destination << std::endl;
        std::cout << "THE BUS " << i + 1 << " CAPACITY IS: " << temp->bus_capacity << std::endl
                  << std::endl;
        i++;
    }
    std::cout << "\nEnter the bus number needed to be deleted: ";
    std::cin >> pos;
    if (pos > bus_count || pos < 0)
    {
        std::cout << "invalid bus number!!!\n";
        return;
    }
    listptr del = first;
    if (pos == 1 && del->link == NULL)
    {
        std::cout << "bus " << del->name << " is deleted from the database\n";
        delete del;
        first = NULL;
        bus_count--;
        return;
    }
    else if (pos == 1 && del->link != NULL)
    {
        std::cout << "bus " << del->name << " is deleted from the database\n";
        first = del->link;
        delete del;
        return;
    }
    else
    {
        for (; del != NULL && --pos > 0; del = del->link)
        {
            aux = del;
        }
        if (del->link == NULL)
        {
            std::cout << "bus " << del->name << " is deleted from the database\n";
            aux->link = NULL;
            delete del;
            bus_count--;
            return;
        }
        std::cout << "bus " << del->name << " is deleted from the database\n";
        aux->link = del->link;
        delete del;
        bus_count--;
    }
}

void receipt()
{
    
    std::ofstream MyFile("receipt.txt");

    listptr aux;
    if (first == NULL)
    {
        MyFile << "NO BUSES ARE AVAILABLE TO WRITE...\n";
        return;
    }
    int choice, i = 0, j = 0;
    MyFile << "THE BUSES AVAILABLE ARE:\n\n";
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        MyFile << "THE BUS " << i + 1 << " NAME IS: " << temp->name<<std::endl ;
        MyFile << "THE BUS " << i + 1 << " DESTINATION IS: " << temp->destination <<std::endl;
        MyFile << "THE BUS " << i + 1 << " CAPACITY IS: " << temp->bus_capacity <<std::endl;
        MyFile << "THE SEATS RESERVED ARE :";
        for (int k = 0; k <= temp->bus_capacity; k++)
        {
            if (temp->bus_seats[k] == 1)
            {
                MyFile << k + 1 << " ,";
            }
        }
        i++;
        MyFile << std::endl;
        MyFile << std::endl;
    }

    MyFile << std::endl;
    MyFile << std::endl;

    MyFile.close();
    std::cout<<"RECEIPT SAVED "<<std::endl;
}

int main()
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    int ch, n, pos;
    while (1)
    {
        SetConsoleTextAttribute(console_color, 15);
        std::cout << "\n";
        std::cout << "\n************** BUS RESERVATION DATABASE **************\n\n";
        std::cout << "\t\t1.ENTER THE BUS DETAILS\n\t\t2.DISPLAY THE BUSES\n\t\t3.RESERVE A SEAT\n\t\t4.DELETE RESERVATION\n\t\t5.DELETE BUS DETAILS\n\t\t6.RECEIPT\n\t\t7.EXIT\n";
        std::cout << "\t\tENTER YOUR CHOICE: ";
        std::cin >> ch;
        std::cout << "\n\n";
        switch (ch)
        {
        case 1:
            SetConsoleTextAttribute(console_color, 10);
            add_bus();
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            system("cls");
            break;
        case 2:
            SetConsoleTextAttribute(console_color, 11);
            display();
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            break;
        case 3:
            SetConsoleTextAttribute(console_color, 14);
            reserve();
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            break;
        case 4:
            SetConsoleTextAttribute(console_color, 9);
            delete_reservation();
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            break;
        case 5:
            SetConsoleTextAttribute(console_color, 12);
            delete_bus();
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            break;
        case 6:
            receipt();
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            break;
        case 7:
            std::cout << "THANKS FOR USING MY BUS RESERVATION DATABASE......\n\n\n";
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            exit(0);
        default:
            std::cout << "invalid choice....";
            for (int i = 0; i < 100; i++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
            getch();
            system("cls");
            break;
        }
    }
    return 0;
}
