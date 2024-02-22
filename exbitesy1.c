#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_SEATS 15

int login_details();
int user_details();
int my_profile(),user_last_book();
int load_user_balance(),user_history(char source[20],int ub_tic, int u_pay);
int train_tik_book();
int bus_tik_book();
int view_travel();
int tamil_movie_book(),holly_movie_book();
int view_tamil_movie(),view_holly_movie(),view_movie();
int Events_sports_book();
int search_isl(),search_ipl();
int view_isl(),view_ipl(),view_sports();
int admin();
int admin_seat_num();
int admin_train(),delete_train();
int admin_bus(),delete_bus();
int admin_hotel(),delete_hotel();
int admin_tamil_movie(),admin_holly_movie();
int admin_sports_event(),admin_isl(),admin_ipl();
int admin_ind_tour(),admin_tn_tour();
int tn_tour_book(),date_load();
char u_name[20]="admin",u_pwd[20]="123";
int retval;

struct travel
{
    char tp_name[20],depart_time[10],arrive_time[10],depart_place[20],arrive_place[20],tp_tm_dur[15];
    char st_place[20], st_name[20], st_ratings[10],st_class[10];
    int tp_no,tp_av_tic,tp_fare,seat_numbers;
    int st_rm_num, st_fare, st_av_rm;

};
struct movie
{
    char mov_name[20],mov_time[10],mov_date[10],mov_theater[20];
    int mov_t_fare,mov_av_tic,seat_numbers;
};
struct sports
{
    char team1[20],team2[20],venue[20],date[20],time[10];
    int t_fare,av_tic,seat_numbers;
};
struct tours
{
    char tour_place[20],hotel_name[20],pac_type[10];
    int pac_price ,rm_num,av_rms;
};


int load_user_balance(int i_amt,int t_fare,int s_fare)
{
    int u_balance,r_balance,found=0,sc_tic,sc_fare;
    char username[20],password[20],i_src[20];
    FILE *fp,*temp;
    fp = fopen("user.txt","r");
    temp = fopen("utemp.txt","w");

    while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
        fscanf(fp, "\n Balance   : %d",&u_balance);
        fscanf(fp, "\n book history   : %s",i_src);
        fscanf(fp, "\n Total tickets  : %d",&sc_tic);
        fscanf(fp, "\n Total fare     : %d",&sc_fare);
        fscanf(fp, "\n______________________________");

        if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
           if(s_fare<=u_balance){

              if(u_balance<t_fare){
                found=2;
                fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                fprintf(temp, "\n Balance   : %d",u_balance);
                fprintf(temp, "\n book history   : %s",i_src);
                fprintf(temp, "\n Total tickets  : %d",sc_tic);
                fprintf(temp, "\n Total fare     : %d",sc_fare);
                fprintf(temp, "\n______________________________");
                printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                getch();
              }else{
                  u_balance-=i_amt;
                  r_balance=u_balance;
                  fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                  fprintf(temp, "\n Balance   : %d",u_balance);
                  fprintf(temp, "\n book history   : %s",i_src);
                  fprintf(temp, "\n Total tickets  : %d",sc_tic);
                  fprintf(temp, "\n Total fare     : %d",sc_fare);
                  fprintf(temp, "\n______________________________");
              }

            }else{
                found=1;
                fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                fprintf(temp, "\n Balance   : %d",u_balance);
                fprintf(temp, "\n book history   : %s",i_src);
                fprintf(temp, "\n Total tickets  : %d",sc_tic);
                fprintf(temp, "\n Total fare     : %d",sc_fare);
                fprintf(temp, "\n______________________________");
                printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                getch();

            }

        }else{
            fprintf(temp, "\n username  : %s\n password  : %s", username, password);
            fprintf(temp, "\n Balance   : %d",u_balance);
            fprintf(temp, "\n book history   : %s",i_src);
            fprintf(temp, "\n Total tickets  : %d",sc_tic);
            fprintf(temp, "\n Total fare     : %d",sc_fare);
            fprintf(temp, "\n______________________________");
        }
    }
    fclose(fp);
    fclose(temp);
    remove("user.txt");
    rename("utemp.txt","user.txt");

    if(found==1){
        return 1;
    }else if(found==2){
        return 2;
    }else{
        return r_balance;
    }
}


int main()
{
    int n;
    loop:
    system("cls");
    printf("\t\t\t\t\tHotel..");
    getch();
    admin_hotel();
    goto loop;
}


int user_history(char source[20],int ub_tic, int u_pay)
{
    char username[20],password[20],i_src[20];
    int u_balance,sc_tic,sc_fare;
    FILE *fp,*temp;
    fp = fopen("user.txt","r");
    temp = fopen("us.txt","w");

    while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
        fscanf(fp, "\n Balance   : %d",&u_balance);
        fscanf(fp, "\n book history   : %s",i_src);
        fscanf(fp, "\n Total tickets  : %d",&sc_tic);
        fscanf(fp, "\n Total fare     : %d",&sc_fare);
        fscanf(fp, "\n______________________________");


        if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
            fprintf(temp, "\n username  : %s\n password  : %s", username, password);
            fprintf(temp, "\n Balance   : %d",u_balance);
            fprintf(temp, "\n book history   : %s",source);
            fprintf(temp, "\n Total tickets  : %d",ub_tic);
            fprintf(temp, "\n Total fare     : %d",u_pay);
            fprintf(temp, "\n______________________________");
        }else{
            fprintf(temp, "\n username  : %s\n password  : %s", username, password);
            fprintf(temp, "\n Balance   : %d",u_balance);
            fprintf(temp, "\n book history   : %s",i_src);
            fprintf(temp, "\n Total tickets  : %d",sc_tic);
            fprintf(temp, "\n Total fare     : %d",sc_fare);
            fprintf(temp, "\n______________________________");
        }
    }

    fclose(fp);
    fclose(temp);
    remove("user.txt");
    rename("us.txt","user.txt");
}

int admin_hotel()
{
    int n,c;
    struct travel hotel;
    FILE *fp;

    admin_hotel:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1. Add Hotel");
    printf("\n\t\t\t\t2. View Hotel details");
    printf("\n\t\t\t\t3. Delete Hotel details");
    printf("\n\t\t\t\t4. Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("hotel_book.txt", "a");                                                                         //Admin bus ticket adding

        loop:
        system("cls");
        printf("\n\t\t\t**=======Hotel Details=======**\n");
        printf("\n\n\t\t\t\tHotel name         : ");
        scanf("%s", hotel.st_name);
        printf("\n\t\t\t\tPlace name         : ");
        scanf("%s", hotel.st_place);
        printf("\n\t\t\t\tHotel Ratings      : ");
        scanf("%s", hotel.st_ratings);
        printf("\n\t\t\t\tHotel class        : ");
        scanf("%s", hotel.st_class);
        printf("\n\t\t\t\tRoom Price         : ");
        scanf("%d", &hotel.st_fare);
        printf("\n\t\t\t\tAvailable rooms    : ");
        scanf("%d", &hotel.st_av_rm);
        printf("\n\t\t\t\tBooked rooms       : ");
        scanf("%d", &hotel.st_rm_num);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Hotel name      : %s\n Place name      : %s\n Ratings         : %s\n Hotel class     : %s",
                    hotel.st_name, hotel.st_place, hotel.st_ratings, hotel.st_class);
            fprintf(fp, "\n Room Price      : %d\n Available rooms : %d\n Booked rooms    : %d",
                    hotel.st_fare, hotel.st_av_rm, hotel.st_rm_num);
            fprintf(fp, "\n_______________________________________________________________________________________");
        }

        printf("\n\t\t\t__________________________________________");
        printf("\n\t\t\t\t Bus Details stored successfully");
        printf("\n\n\t\t\t\tDo you want to add another? ");
        printf("\n\t\t\t\t1. Yes");
        printf("\n\t\t\t\t2. back");
        printf("\n\t\t\t\tEnter the choice : ");
        scanf("%d",&c);
        if(c==1){
            goto loop;
        }else{
            fclose(fp);
           goto admin_hotel;
        }
        break;
    case 2:
        system("cls");
        view_travel(2,3);
        goto admin_hotel;
        break;
    case 3:
        system("cls");
        retval=delete_hotel();
        if(retval==1){
            goto admin_hotel;
        }else{
            getch();
            goto admin_hotel;
        }
        break;
    case 101:
        strcpy(u_name,"admin");
        strcpy(u_pwd,"123");
        hotel_book();
        goto admin_hotel;
    default:
        printf("Please enter valid input");
        goto admin_hotel;
    }

    return 0;
}

int view_travel(int n,int m)
{
    FILE *fp;
    struct travel train;
    struct travel bus;
    struct travel hotel;
    int num=0;

    switch(m)
    {
        case 1:                                                         //case train
            fp = fopen("train_book.txt", "r");

            if (fp == NULL){
                printf("Error opening file for reading.\n");
                getch();
                return 0;
            }

            system("cls");
            printf("\n\t\t\t**=======Train Details=======**\n");

            while (fscanf(fp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                train.tp_name,&train.tp_no,train.depart_time,train.arrive_time) != EOF){
                fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                train.depart_place,train.arrive_place,&train.tp_fare,train.tp_tm_dur,&train.tp_av_tic,&train.seat_numbers);
                fscanf(fp,"\n_______________________________________________________________________________________");

                num++;
                printf("\n\t\t\tHotel ID          : %d", num);
                printf("\n\t\t\tTrain name        : %s", train.tp_name);
                printf("\n\t\t\tTrain number      : %d", train.tp_no);
                printf("\n\t\t\tDeparture time    : %s", train.depart_time);
                printf("\n\t\t\tArrival time      : %s", train.arrive_time);
                printf("\n\t\t\tDeparture place   : %s", train.depart_place);
                printf("\n\t\t\tArrival place     : %s", train.arrive_place);
                printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
                printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
                printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
                if(n==2){
                    printf("\n\t\t\tSeats Booked      : %d", train.seat_numbers);
                }
                printf("\n\t\t________________________________________________");
            }

            fclose(fp);
            num=0;
            printf("\n\t\tPress enter to Go back");
            getch();
            return 1;


        case 2:                                                                //case buses
            fp = fopen("bus_book.txt", "r");

            if(fp == NULL){
                printf("Error opening file for reading.\n");
                getch();
                return 0;
            }

            system("cls");
            printf("\n\t\t\t**=======bus Details=======**\n");

            while (fscanf(fp,"\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                bus.tp_name,&bus.tp_no,bus.depart_time,bus.arrive_time) != EOF){
                fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d \n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                bus.depart_place,bus.arrive_place,&bus.tp_fare,bus.tp_tm_dur,&bus.tp_av_tic,&bus.seat_numbers);
                fscanf(fp,"\n_______________________________________________________________________________________");

                num++;
                printf("\n\t\t\tBus ID            : %d", num);
                printf("\n\t\t\tBus name          : %s Travels", bus.tp_name);
                printf("\n\t\t\tBus number        : TN-%d", bus.tp_no);
                printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
                printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
                printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
                printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
                printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
                printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
                printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
                if(n==2){
                    printf("\n\t\t\tSeats Booked      : %d", bus.seat_numbers);
                }
                printf("\n\t\t________________________________________________");
            }

            fclose(fp);
            num=0;
            printf("\n\t\tPress enter to exit");
            getch();
            return 0;

        case 3:                                                                //case Hotel
            fp = fopen("hotel_book.txt", "r");

            if(fp == NULL){
                printf("Error opening file for reading.\n");
                getch();
                return 0;
            }

            system("cls");
            printf("\n\t\t\t**=======Hotel Details=======**\n");

            while (fscanf(fp, "\n Hotel name      : %s\n Place name      : %s\n Ratings         : %s\n Hotel class     : %s",
                    hotel.st_name, hotel.st_place, hotel.st_ratings, hotel.st_class)!=EOF){
                fscanf(fp, "\n Room Price      : %d\n Available rooms : %d\n Booked rooms    : %d",
                    &hotel.st_fare, &hotel.st_av_rm, &hotel.st_rm_num);
                fscanf(fp, "\n_______________________________________________________________________________________");

                num++;
                printf("\n\t\t\tHotel ID          : %d", num);
                printf("\n\t\t\tHotel name        : %s", hotel.st_name);
                printf("\n\t\t\tPlace name        : %s", hotel.st_place);
                printf("\n\t\t\tRatings           : %s", hotel.st_ratings);
                printf("\n\t\t\tHotel class       : %s", hotel.st_class);
                printf("\n\t\t\tRoom Price        : %d", hotel.st_fare);
                printf("\n\t\t\tAvailable room    : %d", hotel.st_av_rm);
                if(n==2){
                    printf("\n\t\t\tBooked Rooms     : %d", hotel.st_rm_num);
                }
                printf("\n\t\t________________________________________________");
            }

            fclose(fp);
            num=0;
            printf("\n\t\tPress enter to exit");
            getch();
            return 0;

    }
}

int delete_hotel()
{
    FILE *fp, *temp;
    struct travel hotel;
    int found = 0, c,m,num=0;
    char ihot_name[20];

    loop1:
    system("cls");
    printf("\n\t\t\t**=======Delete Hotel Details=======**\n");
    printf("\n\t1. Back");
    printf("\t\tEnter the Hotel name    :");
    scanf("%s", ihot_name);

    if (strcmp(ihot_name, "1") == 0)
    {
        return 1;
    }
    fp = fopen("hotel_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    while (fscanf(fp, "\n Hotel name      : %s\n Place name      : %s\n Ratings         : %s\n Hotel class     : %s",
            hotel.st_name, hotel.st_place, hotel.st_ratings, hotel.st_class)!=EOF){
        fscanf(fp, "\n Room Price      : %d\n Available rooms : %d\n Booked rooms    : %d",
            &hotel.st_fare, &hotel.st_av_rm, &hotel.st_rm_num);
        fscanf(fp, "\n_______________________________________________________________________________________");

        num++;
        if (strcmp(hotel.st_name, ihot_name) == 0)
        {
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Hotel Details to Delete=======**\n");
            printf("\n\n\t\t\tHotel Id           : %d", num);
            printf("\n\t\t\tHotel name        : %s", hotel.st_name);
            printf("\n\t\t\tPlace name        : %s", hotel.st_place);
            printf("\n\t\t\tRatings           : %s", hotel.st_ratings);
            printf("\n\t\t\tHotel class       : %s", hotel.st_class);
            printf("\n\t\t\tRoom Price        : %d", hotel.st_fare);
            printf("\n\t\t\tAvailable room    : %d", hotel.st_av_rm);
            printf("\n\t\t\tBooked Rooms     : %d", hotel.st_rm_num);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\tAre you sure you want to delete this Hotel?");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\t\t\t3. Next");
            printf("\n\t\t_________________________________");
            printf("\n\n\t\t\tEnter the choice :");
            scanf("%d", &c);

            if (c == 1){
                strcpy(ihot_name,"dummy");
                printf("\n\t\t\t Hotel details deleted successfully...");
                getch();
            }else if(c==2){
                strcpy(ihot_name,"dummy");
                fprintf(temp, "\n Hotel name      : %s\n Place name      : %s\n Ratings         : %s\n Hotel class     : %s",
                    hotel.st_name, hotel.st_place, hotel.st_ratings, hotel.st_class);
                fprintf(temp, "\n Room Price      : %d\n Available rooms : %d\n Booked rooms    : %d",
                    hotel.st_fare, hotel.st_av_rm, hotel.st_rm_num);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }else{
                found=2;
                fprintf(temp, "\n Hotel name      : %s\n Place name      : %s\n Ratings         : %s\n Hotel class     : %s",
                    hotel.st_name, hotel.st_place, hotel.st_ratings, hotel.st_class);
                fprintf(temp, "\n Room Price      : %d\n Available rooms : %d\n Booked rooms    : %d",
                    hotel.st_fare, hotel.st_av_rm, hotel.st_rm_num);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }
        }
        else
        {
            fprintf(temp, "\n Hotel name      : %s\n Place name      : %s\n Ratings         : %s\n Hotel class     : %s",
                hotel.st_name, hotel.st_place, hotel.st_ratings, hotel.st_class);
            fprintf(temp, "\n Room Price      : %d\n Available rooms : %d\n Booked rooms    : %d",
                hotel.st_fare, hotel.st_av_rm, hotel.st_rm_num);
            fprintf(temp, "\n_______________________________________________________________________________________");
        }
    }
    if(found==0 || found==2){
        printf("\n\t\t\tNo Hotels found as %s",hotel.st_name);
        printf("\n\t\t_________________________________________");
        printf("\n\t\t\t1. Search again");
        printf("\n\t\t\t2. Back");
        printf("\n\t\t_________________________________________");
        printf("\n\t\t\tEnter the choice   :");
        scanf("%d",&m);

        if(m==1){
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("hotel_book.txt");
            rename("temp_book.txt","hotel_book.txt");
            goto loop1;
        }else{
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("hotel_book.txt");
            rename("temp_book.txt","hotel_book.txt");
            return 1;
        }
    }else{
        num=0;
        found=0;
        fclose(fp);
        fclose(temp);
        remove("hotel_book.txt");
        rename("temp_book.txt","hotel_book.txt");
        return 1;
    }

    return 0;
}

