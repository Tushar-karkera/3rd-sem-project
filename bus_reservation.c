#include <stdio.h>
#include <string.h>
#include <conio.h>

int bus_count = 0;

struct bus_reservation
{
    char name[20];
    char destination[10];
    int bus_capacity;
    int bus_seats[100];
} bus[10];

void add_bus(struct bus_reservation *bus)
{
    int i;
    printf("enter the bus name: ");
    scanf("%s", bus->name);
    printf("enter the bus destination: ");
    scanf("%s", bus->destination);
    printf("enter the bus capacity: ");
    scanf("%d", &bus->bus_capacity);
    for (i = 0; i < bus->bus_capacity; i++)
    {
        bus->bus_seats[i] = 0;
    }
    bus->bus_seats[i] = -1;
    printf("\n\n");
    bus_count++;
}

void display()
{
    if (bus_count == 0)
    {
        printf("NO BUSES ARE AVAILABLE TO DISPLAY...\n");
        return;
    }
    int choice, i = 0, j = 0;
    printf("THE BUSES AVAILABLE ARE:\n\n");
    for (int i = 0; i < bus_count ; i++)
    {
        if( bus[i].bus_capacity ==-1)
        {
            continue;
        }
        printf("THE BUS %d NAME IS: %s\n", i + 1, bus[i].name);
        printf("THE BUS %d DESTINATION IS: %s\n", i + 1, bus[i].destination);
        printf("THE BUS %d CAPACITY IS: %d\n\n", i + 1, bus[i].bus_capacity);
    }
    printf("Press 1 for checking bus reservation of a bus: \nPress 2 for exit: ");
    scanf("%d", &choice);
    if (choice == 2)
    {
        return;
    }
    else if(choice !=1)
    {
        printf("INVALID CHOICE....\n");
        return;
    }
    printf("enter the bus number : ");
    scanf("%d", &choice);
    choice--;
    if (choice >= 0)
    {
        for (i = 0; i < bus[choice].bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (bus[choice].bus_seats[(4 * i) + j] == -1)
                {
                    printf("\n\n");
                    return;
                }
                printf("%2d.%2d   ", (4 * (i) + j + 1), bus[choice].bus_seats[(4 * i) + j]);
            }
            printf("\n");
        }
    }
    printf("\n\n");
}

void reserve()
{
    if (bus_count == 0)
    {
        printf("NO BUSES ARE AVAILABLE TO RESERVE SEAT...\n");
        return;
    }
    int res, seat, j = 0, i = 0;
    printf("THE AVAILABLE BUSES ARE: \n");
    for (int i = 0; i < bus_count ; i++)
    {
        if( bus[i].bus_capacity ==-1)
        {
            continue;
        }
        printf("%d. %s\n", i + 1, bus[i].name);
    }
    printf("select the bus whose seat needs to be reserved: ");
    scanf("%d", &res);
    --res;

    for (i = 0; i < bus[res].bus_capacity / 4 + 1; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (bus[res].bus_seats[(4 * i) + j] == -1)
            {
                break;
            }
            printf("%2d.%2d   ", (4 * (i) + j + 1), bus[res].bus_seats[(4 * i) + j]);
        }
        printf("\n");
    }
    printf("\nselect the seat to be reserved: ");
    scanf("%d", &seat);
    --seat;
    if (bus[res].bus_seats[seat] == 1)
    {
        printf("ENTERED SEAT IS ALREADY RESERVED!!!...\n");
        return;
    }
    bus[res].bus_seats[seat] = 1;
    printf("\nSEAT %d IS RESERVED IN BUS %s!!!\n", ++seat, bus[res].name);
    printf("\n\n");
}

void delete_reservation()
{
    if (bus_count == 0)
    {
        printf("NO BUSES ARE AVAILABLE TO DELETE RESERVATION...\n");
        return;
    }
    int res, seat, i, j;
    printf("THE AVAILABLE BUSES ARE: \n");
    for (int i = 0; i < bus_count ; i++)
    {
        if( bus[i].bus_capacity ==-1)
        {
            continue;
        }
        printf("%d. %s\n", i + 1, bus[i].name);
    }
    printf("select the bus whose reservation needs to be removed: ");
    scanf("%d", &res);
    --res;
    for (i = 0; i < bus[res].bus_capacity / 4 + 1; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (bus[res].bus_seats[(4 * i) + j] == -1)
            {
                break;
            }
            printf("%2d.%2d   ", (4 * (i) + j + 1), bus[res].bus_seats[(4 * i) + j]);
        }
        printf("\n");
    }
    printf("\nselect the seat to be removed from reservation: ");
    scanf("%d", &seat);
    --seat;
    if (bus[res].bus_seats[seat] == 0)
    {
        printf("ENTERED SEAT IS ALREADY NOT RESERVED!!!...\n");
        return;
    }
    bus[res].bus_seats[seat] = 0;
    printf("RESERVATION OF SEAT %d IS REMOVED FROM THE BUS %s!!!\n", ++seat, bus[res].name);
}

void delete_bus()
{
    if (bus_count == 0)
    {
        printf("NO BUSES ARE AVAILABLE TO DELETE...\n");
        return;
    }
    int choice;
    printf("THE AVAILABLE BUSES ARE: \n");
    for (int i = 0; i < bus_count ; i++)
    {
        if( bus[i].bus_capacity ==-1)
        {
            continue;
        }
        printf("%d. %s\n", i + 1, bus[i].name);
    }
    printf("select the bus to be deleted: ");
    scanf("%d", &choice);
    --choice;
    memset(bus[choice].name,'\0',20);
    memset(bus[choice].destination,'\0',20);
    for (int i = 0; i < bus[choice].bus_capacity; i++)
    {
        bus[choice].bus_seats[i] = -1;
    }
    bus[choice].bus_capacity = -1;
    printf("THE BUS NO. %d IS DELETED FROM THE DATABASE\n", ++choice);
}

int main()
{
    int ch, n;
    while (1)
    {
        printf("\n");
        printf("1.ENTER THE BUS DETAILS\n2.DISPLAY THE BUSES\n3.RESERVE A SEAT\n4.DELETE RESERVATION\n5.DELETE BUS DETAILS\n6.EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        printf("\n\n");
        switch (ch)
        {
        case 1:
            printf("enter the number of buses needed to be entered: ");
            scanf("%d", &n);
            printf("\n");
            for (int i = 0; i < n; i++)
            {
                add_bus(&bus[bus_count]);
            }
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            system("cls");
            break;
        case 2:
            display();
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            getch();
            system("cls");
            break;
        case 3:
            reserve();
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            getch();
            system("cls");
            break;
        case 4:
            delete_reservation();
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            getch();
            getch();
            system("cls");
            break;
        case 5:
            delete_bus();
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            getch();
            system("cls");
            break;
        case 6:
            printf("THANKS FOR USING MY BUS RESERVATION DATABASE......\n\n\n");
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            getch();
            system("cls");
            exit(0);
        default:
            printf("invalid choice....");
            for (int i = 0; i < 100; i++)
            {
                printf("*");
            }
            printf("\n");
            getch();
            system("cls");
            break;
        }
    }
    return 0;
}
