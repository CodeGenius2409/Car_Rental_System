#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct car{
    char n[50];
    int ns;
    int rc;
    int s;
}c[50];

int a=0,b=0,bc,nod,na=0,ta,ch,ac;

void AddCar(){
    for(int i=a;i<=b-1;i++){
        printf("\nEnter Data of car %i:",a+1);
        printf("\nEnter name of car:");
        scanf("%s",c[a].n);
        printf("\nEnter number of seats in car:");
        scanf("%i",&c[a].ns);
        printf("\nEnter rent of car: Rs.");
        scanf("%i",&c[a].rc);
        printf("\nEnter status of car\nPress 1 for available\nPress 2 for not available ");
        scanf("%i",&c[a].s);

        while(c[a].s!=1&&c[a].s!=2){
            printf("Error, incorrect car status please enter status of car again");
            printf("\nEnter status of car:");
            scanf("%i",&c[a].s);
            }
        a++;
        
    }
        
    }


void Display(){
    printf("\n%-10s%-20s%-20s%-15s%-15s", "S.No", "Car Name", "Seats", "Rent (Rs.)", "Status");
    printf("\n%-10s%-20s%-20s%-15s%-15s", "----", "--------", "------", "----------", "------");
    
    for(int i=0;i<a;i++){
        printf("\n%-10i%-20s%-20i%-15i%-15s", i+1, c[i].n, c[i].ns, c[i].rc, (c[i].s==1)?"available":"not available");
    }
    printf("\n");
}

void bookCar(){
    printf("\nEnter serial number of car that you would like to book:");
    scanf("%i",&bc);

    if(c[bc-1].s==1){
        printf("\n\nEnter number of days:");
        scanf("%i",&nod);
        na=na+nod*c[bc-1].rc;
        printf("\n\nCar booked successfully\n\n ");
        c[bc-1].s=2;
    }
    else printf("\n\nCar not available, please try booking another car\n\n");
}

void GenerateBill() {
    ta=na+na*0.05;
    printf("\n\nGenerating Bill...\n");
    printf("%-20s%-15s%-15s%-15s%-15s\n", "Car Name", "Days Booked", "Rent/Day", "GST (%)", "Total");
    printf("%-20s%-15i%-15i%-15.2f%-15.2f\n", c[bc-1].n,nod,c[bc-1].rc,5.0,ta);
    printf("\nThank you for using our car rental service!\n");
}


int main(){
    while(1){
        printf("\nPress 1 to add cars\nPress 2 to display all cars\nPress 3 to book a car\nPress 4 to generate bill\nPress 5 to exit:");
        scanf("%i",&ch);

        if(ch>=1 && ch<=5){
            if(ch==1){
                printf("How many cars would you like to add:");
                scanf("%i",&ac);
                b=b+ac;
                AddCar();
            }

            if(a>=2){
                switch(ch){
                    case 2: Display(); break;
                    case 3: bookCar(); break;
                    case 4: GenerateBill(); break;
                    case 5: exit(0); break;
                }
            } else {
                printf("You have to add data of 3 cars before doing any other function");
            }
        } else {
            printf("Incorrect input\n");
        }
    }
}
