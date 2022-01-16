#include <stdio.h>
#include <stdlib.h>
int bus_count = 0;

typedef struct bus_node *listptr;

struct bus_node
{
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
        listptr newnode = (listptr)malloc(sizeof(struct bus_node));
        printf("enter the bus name: ");
        scanf("%s", &newnode->name);
        printf("enter the bus destination: ");
        scanf("%s", &newnode->destination);
        printf("enter the bus capacity: ");
        scanf("%d", &newnode->bus_capacity);
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

        listptr newnode = (listptr)malloc(sizeof(struct bus_node));
        printf("enter the bus name: ");
        scanf("%s", &newnode->name);
        printf("enter the bus destination: ");
        scanf("%s", &newnode->destination);
        printf("enter the bus capacity: ");
        scanf("%d", &newnode->bus_capacity);
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
        printf("NO BUSES ARE AVAILABLE TO DISPLAY...\n");
        return;
    }
    int choice, i = 0, j = 0;
    printf("THE BUSES AVAILABLE ARE:\n\n");
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        printf("THE BUS %d NAME IS: %s\n", i + 1, temp->name);
        printf("THE BUS %d DESTINATION IS: %s\n", i + 1, temp->destination);
        printf("THE BUS %d CAPACITY IS: %d\n\n", i + 1, temp->bus_capacity);
        i++;
    }

    printf("Press 1 for checking bus reservation of a bus: \nPress 2 for exit: ");
    scanf("%d", &choice);
    if (choice == 2)
    {
        return;
    }
    else if (choice != 1)
    {
        printf("INVALID CHOICE....\n");
        return;
    }
    printf("enter the bus number : ");
    scanf("%d", &choice);
    if (choice >= 0)
    {
        printf("\033[0;33m");
        printf("\n0 -> non reserved seats || 1 -> reserved seats :\n\n");
        listptr temp = first;
        for (; (temp->link != NULL && --choice > 0); temp = temp->link)
            ;
        for (i = 0; i < temp->bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (temp->bus_seats[(4 * i) + j] == -1)
                {
                    printf("\n\n");
                    return;
                }
                printf("%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j]);
            }
            printf("\n");
        }
    }
    printf("\n\n");
}

void reserve()
{
    if (first == NULL)
    {
        printf("NO BUSES ARE AVAILABLE TO RESERVE SEAT...\n");
        return;
    }
    int res, seat, j = 0, i = 0;
    printf("THE BUSES AVAILABLE ARE:\n\n");
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        printf("THE BUS %d NAME IS: %s\n", i + 1, temp->name);
        printf("THE BUS %d DESTINATION IS: %s\n", i + 1, temp->destination);
        printf("THE BUS %d CAPACITY IS: %d\n\n", i + 1, temp->bus_capacity);
        i++;
    }
    printf("select the bus whose seat needs to be reserved: ");
    scanf("%d", &res);
    if (res <= bus_count && res > 0)
    {
        printf("\n0 -> non reserved seats || 1 -> reserved seats :\n\n");
        listptr temp = first;
        for (; (temp->link != NULL && --res > 0); temp = temp->link)
            ;
        for (i = 0; i < temp->bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (temp->bus_seats[(4 * i) + j] == -1)
                {
                    printf("\n\n");
                    break;
                }
                printf("%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j]);
            }
            printf("\n");
        }
        printf("\n\n");
        printf("\nselect the seat to be reserved: ");
        scanf("%d", &seat);
        --seat;
        if (seat >= 0 && seat < temp->bus_capacity)
        {
            if (temp->bus_seats[seat] == 1)
            {
                printf("ENTERED SEAT IS ALREADY RESERVED!!!...\n");
                return;
            }
            temp->bus_seats[seat] = 1;
            printf("\nSEAT %d IS RESERVED IN BUS %s!!!\n", ++seat, temp->name);
            printf("\n\n");
            return;
        }
        else
        {
            printf("invalid seat number!!!\n");
            return;
        }
    }
    else
    {
        printf("invalid bus number\n");
        return;
    }
}

void delete_reservation()
{
    if (first == NULL)
    {
        printf("NO BUSES ARE AVAILABLE TO RESERVE SEAT...\n");
        return;
    }
    int res, seat, j = 0, i = 0;
    printf("THE BUSES AVAILABLE ARE:\n\n");
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        printf("THE BUS %d NAME IS: %s\n", i + 1, temp->name);
        printf("THE BUS %d DESTINATION IS: %s\n", i + 1, temp->destination);
        printf("THE BUS %d CAPACITY IS: %d\n\n", i + 1, temp->bus_capacity);
        i++;
    }
    printf("select the bus whose seat needs to be reserved: ");
    scanf("%d", &res);
    if (res <= bus_count && res > 0)
    {   
        printf("\n0 -> non reserved seats || 1 -> reserved seats :\n\n");
        listptr temp = first;
        for (; (temp->link != NULL && --res > 0); temp = temp->link)
            ;
        for (i = 0; i < temp->bus_capacity / 4 + 1; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (temp->bus_seats[(4 * i) + j] == -1)
                {
                    printf("\n\n");
                    break;
                }
                printf("%2d.%2d   ", (4 * (i) + j + 1), temp->bus_seats[(4 * i) + j]);
            }
            printf("\n");
        }
        printf("\n\n");
        printf("\nselect the seat : ");
        scanf("%d", &seat);
        --seat;
        if (seat >= 0 && seat < temp->bus_capacity)
        {
            if (temp->bus_seats[seat] == 0)
            {
                printf("ENTERED SEAT IS ALREADY NOT RESERVED!!!...\n");
                return;
            }
            temp->bus_seats[seat] = 0;
            printf("RESERVATION OF SEAT %d IS REMOVED FROM THE BUS %s!!!\n", ++seat, temp->name);
            return;
        }
        else
        {
            printf("invalid seat number!!!\n");
            return;
        }
    }
    else
    {
        printf("invalid bus number!!!\n");
    }
}

void delete_bus()
{
    int pos;
    listptr aux;
    if (first == NULL)
    {
        printf("NO BUSES ARE AVAILABLE TO DELETE...\n");
        return;
    }
    int choice, i = 0, j = 0;
    printf("THE BUSES AVAILABLE ARE:\n\n");
    for (listptr temp = first; temp != NULL; temp = temp->link)
    {
        printf("THE BUS %d NAME IS: %s\n", i + 1, temp->name);
        printf("THE BUS %d DESTINATION IS: %s\n", i + 1, temp->destination);
        printf("THE BUS %d CAPACITY IS: %d\n\n", i + 1, temp->bus_capacity);
        i++;
    }
    printf("\nEnter the bus number needed to be deleted: ");
    scanf("%d", &pos);
    if (pos > bus_count || pos < 0)
    {
        printf("invalid bus number!!!\n");
        return;
    }
    listptr del = first;
    if (pos == 1)
    {
        printf("bus %s is deleted from the database\n", del->name);
        free(del);
        first = NULL;
        bus_count--;
        return;
    }
    else
    {
        for (; del != NULL && --pos > 0; del = del->link)
        {
            aux = del;
        }
        printf("bus %s is deleted from the database\n", del->name);
        aux->link = del->link;
        free(del);
        bus_count--;
    }
}

int main()
{
    //printf("\033[0;33m");
    int ch, n, pos;
    while (1)
    {
        //printf("\033[0;33m");
        printf("\n");
        printf("\n************** BUS RESERVATION DATABASE **************\n\n");
        printf("\t\t1.ENTER THE BUS DETAILS\n\t\t2.DISPLAY THE BUSES\n\t\t3.RESERVE A SEAT\n\t\t4.DELETE RESERVATION\n\t\t5.DELETE BUS DETAILS\n\t\t6.EXIT\n");
        printf("\t\tENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        printf("\n\n");
        switch (ch)
        {
        case 1:
            //printf("\033[0;33m");
            add_bus();
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
