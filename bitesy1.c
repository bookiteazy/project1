#include <stdio.h>
#include <conio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int login_details();
int user_details();
int train_tik_book();
int search_train(),view_trains();
int bus_tik_book();
int search_bus(),view_bus();
int Events_book();
int view_sports();
int admin();
int admin_train(),delete_train();
int admin_bus(),delete_bus();
int admin_sports_event(),add_isl();

struct travel
{
    char tp_name[20],depart_time[10],arrive_time[10],depart_place[20],arrive_place[20];
    char tp_tm_dur[15];
    int tp_no,retval,tp_av_tic,tp_fare;
};

int main()
{
                                                                                //Main function
    int ch,u,n,m,retval;

    loop:
        system("cls");
        printf("\n\t\t\t**=======Bookiteazy=======**\n");
        printf("\n\n\t\t\t\t1 .LOGIN");
        printf("\n\t\t\t\t2. Create account");
        printf("\n\t\t\t\t3. Admin login");
        printf("\n\t\t\t_____________________________");
        printf("\n\t\t\t\tEnter the choice :");
        scanf("%d", &u);

        switch(u){
            case 1:
                retval=login_details(u);
                if(retval==2){
                    goto hloop;
                }else if(retval==1){
                    goto loop;
                }
                break;
            case 2:
                retval=login_details(u);
                if(retval==2){
                    goto loop;
                }
                break;
            case 3:
                retval=login_details(u);
                if(retval==1){
                    retval=admin();
                    if(retval==1){
                        goto loop;
                    }
                }else if(retval==2){
                    goto loop;
                }
            default:
            printf("\n\t\t\t\tPlease Enter valid input...");
            goto loop;
        }

        hloop:
        system("cls");
        printf("\n\t\t\t**=======Bookiteazy=======**\n");
        printf("\n\t\t\t\t1.Travel");
        printf("\n\t\t\t\t2.Movies");
        printf("\n\t\t\t\t3.Service");
        printf("\n\t\t\t\t4.Event");
        printf("\n\t\t\t\t5.Touristy");
        printf("\n\t\t\t\t6.Exit");
        printf("\n\t\t\t___________________________");
        printf("\n\t\t\tEnter the choice :");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                tloop:
                system("cls");
                printf("\n\t\t\t**=======Travel=======**\n");                                     //Travel page
                printf("\n\n\t\t\t1.Train Ticket");
                printf("\n\t\t\t2.Bus Ticket");
                printf("\n\t\t\t3.Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                switch (n){
                    case 1:
                        system("cls");
                        retval=train_tik_book();
                        if(retval==1){
                        goto tloop;
                        }
                        break;
                    case 2:
                        system("cls");
                        retval=bus_tik_book();
                        if(retval==1){
                            goto tloop;
                        }
                        break;
                    case 3:
                        goto loop;
                        break;
                    default:
                        printf("\n\t\t\tPlease Enter a valid input...");
                        getch();
                        goto tloop;
                }
            case 2:
                system("cls");
                printf("\n\t\t\t**=======Movies=======**\n");                                                  //Movie page
                printf("\n\t\t\t1. Tamil Movies");
                printf("\n\t\t\t2. Hindi Movies");
                printf("\n\t\t\t3. Hollywood Movies");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                break;
            case 3:
                system("cls");
                printf("\n\t\t\t**=======Services=======**\n");                                                 //Services page
                printf("\n\t\t\t1.");
                printf("\n\t\t\t2.");
                printf("\n\t\t\t3.");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                break;
            case 4:
                system("cls");
                printf("\n\t\t\t**=======Events=======**\n");
                printf("\n\n\t\t\t\t1. Marathon");
                printf("\n\t\t\t\t2. Sports");
                printf("\n\t\t\t\t3. Concerts");
                printf("\n\t\t\t\t4.Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d",&n);

                switch(n){
                    case 2:
                        system("cls");
                        retval=Events_book();
                        if(retval==1){
                            goto hloop;
                        }
                        break;
                    case 4:
                        goto hloop;
                        break;
                }
                break;
            case 5:
                system("cls");
                printf("\n\t\t\t**=======Touristry=======**\n");                                                 //Touristry page
                printf("\n\t\t\t1.");
                printf("\n\t\t\t2.");
                printf("\n\t\t\t3.");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                break;
            case 6:
                system("cls");
                printf("\n\n\t\t\t\tThank you, come again");
                getch();
                break;
            default:
                printf("\n\t\t\tPlease Enter valid Input....");
                getch();
                goto hloop;
        }


    getch();
    return 0;
}

int login_details(int n) {
    FILE *fp;
    char i_username[20], i_password[20], username[20], password[20],pwd[10];
    int m,found=0;
    switch (n) {
    case 1:
        fp = fopen("user.txt", "r");

        loop:
        system("cls");
        printf("\n\t\t\t1. Back");
        printf("\n\n\t\t\tEnter the user name  : ");
        scanf("%s", i_username);

        if (strcmp(i_username, "1") == 0) {
            fclose(fp);
            return 1;
        } else {
            printf("\n\t\t\tEnter the Password   : ");
            scanf("%s", i_password);
        }

        while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password) !=EOF) {
            fscanf(fp, "______________________________\n");

            if (strcmp(username, i_username) == 0 && strcmp(password, i_password) == 0) {
                found=1;
                printf("\n\t\t\tLogin Successful");
                fclose(fp);
                getch();
                return 2;
            }
        }

        if(found==0){
            printf("\n\t\t\tIncorrect Password or Username....");
            rewind(fp);
            getch();
            goto loop;
        }
        break;

    case 2:
        system("cls");
        fp = fopen("user.txt", "a");

        printf("\n\t\t\tCreate account...\n");
        printf("\n\t\t\tEnter the user name  : ");
        scanf("%19s", username);
        printf("\n\t\t\tEnter the Password   : ");
        scanf("%19s", password);

        fprintf(fp, "username  : %s\npassword  : %s\n", username, password);
        fprintf(fp, "______________________________\n");

        printf("\n\n\t\t\tAccount created successfully....");
        getch();
        fclose(fp);
        return 2;
    case 3:
        aloop:
        system("cls");
        strcpy(pwd,"asd");
        printf("\n\t\t\t**======Admin login======**\n");
        printf("\n\t\t\tEnter the password  :");
        scanf("%s",i_password);

        if(strcmp(i_password,pwd)==0){
            printf("\n\t\t\tLogin successfull...");
            getch();
            return 1;
        }else{
            printf("\n\t\t\tIncorrect password...");
            printf("\n\t\t\t1. Retry");
            printf("\n\t\t\t2. Back");
            scanf("%d",&m);

            if(m==1){
                goto aloop;
            }else if(m==2){
                return 2;
            }
        }
    default:
        printf("\n\t\t\tPlease Enter valid input...");
        getch();
        break;
    }

    return 0;
}

int user_details()
{
    int n,m,found=0;
    char i_uname[10],username[10],password[10];
    FILE *fp,*temp;

    loop:
    system("cls");
    printf("\n\t\t\t**=======User details=======**\n");
    printf("\n\t\t\t1. User info");
    printf("\n\t\t\t2. Delete users");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t_________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }

    switch(n){
        case 1:
            fp = fopen("user.txt", "r");
            if(fp==NULL){
                printf("\n\t\t\terror openning the file");
                getch();
                goto loop;
            }
            system("cls");
            printf("\n\t\t\t**=======User Info=======**\n");
            while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!= EOF){
                fscanf(fp, "______________________________\n");

                printf("\n\t\t\tUsername     : %s",username);
                printf("\n\t\t\tPassword     : %s",password);
                printf("\n\t\t___________________________________________");
            }
            getch();
            fclose(fp);
            goto loop;
            break;
        case 2:
            fp = fopen("user.txt", "r");
            temp = fopen("temp.txt", "w");
            if(fp==NULL || temp==NULL){
                printf("\n\t\t\terror openning the file");
                getch();
                goto loop;
            }
            system("cls");
            printf("\n\t\t\t**=======Delete User Info=======**\n");
            printf("\n\t\t\tEnter the username    :");
            scanf("%s",i_uname);

             while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password) !=EOF) {
                fscanf(fp, "______________________________\n");

                if(strcmp(username,i_uname)==0){
                    found=1;
                    printf("\n\t\t\tUsername     : %s",username);
                    printf("\n\t\t\tPassword     : %s",password);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tAre you sure want to delete this info......");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    scanf("%d",&m);

                    if(m==1){
                        found=2;
                        printf("\n\t\t\tUser info deleted successfully...");
                        getch();
                    }else{
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "______________________________\n");
                        found=2;
                    }

                }else{
                    fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                    fprintf(temp, "______________________________\n");
                }
                if(found==2){
                    strcpy(i_uname,"dummy");
                }
            }
            if(found==0){
                printf("\n\t\t\tNo details available as %s : i_uname");
                getch();
            }
            fclose(fp);
            getch();
            remove("user.txt");
            rename("temp.txt","user.txt");
            goto loop;
    }

    return 0;
}

int train_tik_book()                                                                                          //Train tickect booking interface
{
    int m,st_retval;
    tloop:
    system("cls");
    printf("\n\t\t\t**=======Train ticket bookings=======**\n");
    printf("\n\t\t\t1.Search Train ");
    printf("\n\t\t\t2.View Trains");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&m);

    if(m==3){
        return 1;
    }
    switch(m){
        case 1:
            system("cls");
            st_retval=search_train();
            if(st_retval==1){
                goto tloop;
            }
            getch();
            goto tloop;
            break;
        case 2:
            system("cls");
            view_trains();
            getch();
            goto tloop;
            break;
        default:
            printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
            getch();
            goto tloop;
    }
    return 0;

}

int search_train() {
    FILE *fp, *temp;
    struct travel train;
    int found = 0, c, m,tickets_to_book,t_fare,i_amt;
    char itr_dep[20], itr_arr[20];

    fp = fopen("train_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        getch();
        return 0;
    }

    loop:
    system("cls");
    printf("\n\t\t\t**=======Search Train =======**\n");
    printf("\n\t\t\t1. Back");
    printf("\n\n\t\t\t Enter the Departure place    :");
    scanf("%s", itr_dep);

    if (strcmp(itr_dep, "1") == 0) {
        fclose(fp);
        fclose(temp);
        return 1;
    }

    printf("\n\n\t\t\t Enter the Arrival place      :");
    scanf("%s", itr_arr);

    loop4:
    while (fscanf(fp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                  train.tp_name, &train.tp_no, train.depart_time, train.arrive_time) != EOF) {
        fscanf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
               train.depart_place, train.arrive_place, &train.tp_fare, train.tp_tm_dur, &train.tp_av_tic);
        fscanf(fp, "\n_______________________________________________________________________________________");

        if (strcmp(train.depart_place, itr_dep) == 0 && strcmp(train.arrive_place, itr_arr) == 0) {
            found = 1;
            printf("\n\t\t\t**=======Train Details =======**\n");
            printf("\n\n\t\t\tTrain name      : %s Express", train.tp_name);
            printf("\n\t\t\tTrain number      : %d", train.tp_no);
            printf("\n\t\t\tDeparture time    : %s", train.depart_time);
            printf("\n\t\t\tArrival time      : %s", train.arrive_time);
            printf("\n\t\t\tDeparture place   : %s", train.depart_place);
            printf("\n\t\t\tArrival place     : %s", train.arrive_place);
            printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
            printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
            printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\t1. Next");
            printf("\t\t\t\t3. Book this Train");
            printf("\n\t\t\t2. Previous");
            printf("\n\n\t\t\tEnter the choice :");
            scanf("%d", &c);

            if (c == 3) {
                loop5:
                system("cls");
                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                scanf("%d", &tickets_to_book);

                if (tickets_to_book <= train.tp_av_tic) {
                    train.tp_av_tic -= tickets_to_book;

                    t_fare=(tickets_to_book*train.tp_fare);
                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                    printf("\n\t\t\tAre you sure want to book this train...");
                    getch();

                    system("cls");
                    printf("\n\t\t\t**=======Payment=======**\n");
                    printf("\n\n\t\t\tEnter the amount  :");
                    scanf("%d", &i_amt);

                    if (i_amt == t_fare) {
                        system("cls");
                        printf("\n\t\t\tTrain tickets booked successfully for %d tickets!", tickets_to_book);
                        printf("\n\t\t\t**=======Ticket details=======**\n");
                        printf("\n\t\t_______________________________________________________");
                        printf("\n\t\t| %s Express           %s To %s", train.tp_name, train.depart_place, train.arrive_place);
                        printf("\n\t\t| Train number    :  TN-%d", train.tp_no);
                        printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                        printf("\n\t\t| Travel duration :  %s", train.tp_tm_dur);
                        printf("\n\t\t| Departure Time  :  %s", train.depart_time);
                        printf("\n\t\t| Arrival Time    :  %s", train.arrive_time);
                        printf("\n\t\t| Total price     :  %d", t_fare);
                        printf("\n\t\t________________________________________________________");
                        printf("\n\t\t Happy Journey.........");

                        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                                train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                                train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic);
                        fprintf(temp, "\n_______________________________________________________________________________________");

                    } else {
                        printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %s", train.tp_fare);
                        train.tp_av_tic += tickets_to_book;
                        getch();
                        goto loop5;
                    }
                    getch();
                } else {
                    printf("\n\t\t\tNot enough tickets available....(Available tickets: %d)", train.tp_av_tic);
                    getch();
                    goto loop5;
                }
            } else if (c == 2) {
                rewind(fp);
            }
        }else{
        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic);
        fprintf(temp, "\n_______________________________________________________________________________________");
        }

    }

    if (found == 0) {
        printf("\n\n\t\t_________________________________________________");
        printf("\n\t\t\tNo Trains Found From %s To %s ", itr_dep, itr_arr);
        printf("\n\t\t\t1. Search another");
        printf("\n\t\t\t2. Back");
        loop3:
        printf("\n\t\t\tEnter the choice  :");
        scanf("%d", &m);

        if (m == 1) {
            rewind(fp);
            goto loop;
        } else if (m == 2) {
            fclose(fp);
            fclose(temp);
            return 1;
        } else {
            printf("\n\t\t\tPlease enter a valid input....");
            getch();
            goto loop3;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("train_book.txt");
    rename("temp_book.txt", "train_book.txt");
    getch();

    return 1;
}


int view_trains()
{
    FILE *fp;
    struct travel train;

    fp = fopen("train_book.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        getch();
        return 0;
    }

    system("cls");
    printf("\n\t\t\t**=======Train Details=======**\n");

    while (fscanf(fp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",train.tp_name,&train.tp_no,train.depart_time,train.arrive_time) != EOF)
    {
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",train.depart_place,train.arrive_place,&train.tp_fare,train.tp_tm_dur,&train.tp_av_tic);
        fscanf(fp,"\n_______________________________________________________________________________________");

        printf("\n\t\t\tTrain name        : %s Express", train.tp_name);
        printf("\n\t\t\tTrain number      : %d", train.tp_no);
        printf("\n\t\t\tDeparture time    : %s", train.depart_time);
        printf("\n\t\t\tArrival time      : %s", train.arrive_time);
        printf("\n\t\t\tDeparture place   : %s", train.depart_place);
        printf("\n\t\t\tArrival place     : %s", train.arrive_place);
        printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
        printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
        printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
        printf("\n\t\t________________________________________________");
    }

    fclose(fp);
    printf("\n\t\tPress enter to Go back");
    getch();
    return 1;
}

int bus_tik_book()                                                                                          //Train tickect booking interface
{
    int m,sb_retval;
    tloop:
    system("cls");
    printf("\n\t\t\t**=======bus ticket bookings=======**\n");
    printf("\n\t\t\t1.Search bus ");
    printf("\n\t\t\t2.View bus");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&m);

    if(m==3){
        return 1;
    }
    switch(m){
        case 1:
            system("cls");
            sb_retval=search_bus();
            if(sb_retval==1){
                goto tloop;
            }
            getch();
            goto tloop;
            break;
        case 2:
            system("cls");
            view_bus();
            getch();
            goto tloop;
            break;
        default:
            printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
            getch();
            goto tloop;
    }
    return 0;

}


int search_bus() {
    FILE *fp, *temp;
    struct travel bus;
    int found = 0, c, m, tickets_to_book,t_fare, i_amt;
    char itr_dep[20], itr_arr[20];

    fp = fopen("bus_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        getch();
        return 0;
    }

    loop:
    system("cls");
    printf("\n\t\t\t**=======Search bus =======**\n");
    printf("\n\t\t\t1. Back");
    printf("\n\n\t\t\t Enter the Departure place    :");
    scanf("%s", itr_dep);

    if (strcmp(itr_dep, "1") == 0) {
        fclose(fp);
        fclose(temp);
        return 1;
    }

    printf("\n\n\t\t\t Enter the Arrival place      :");
    scanf("%s", itr_arr);

    loop4:
    while (fscanf(fp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                  bus.tp_name, &bus.tp_no, bus.depart_time, bus.arrive_time) != EOF) {
        fscanf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
               bus.depart_place, bus.arrive_place, &bus.tp_fare, bus.tp_tm_dur, &bus.tp_av_tic);
        fscanf(fp, "\n_______________________________________________________________________________________");

        if (strcmp(bus.depart_place, itr_dep) == 0 && strcmp(bus.arrive_place, itr_arr) == 0) {
            found = 1;
            printf("\n\t\t\t**=======Bus Details =======**\n");
            printf("\n\n\t\t\tbus name        : %s Express", bus.tp_name);
            printf("\n\t\t\tbus number        : TN-%d", bus.tp_no);
            printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
            printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
            printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
            printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
            printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
            printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
            printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\t1. Next");
            printf("\t\t\t\t3. Book this bus");
            printf("\n\t\t\t2. Previous");
            printf("\n\n\t\t\tEnter the choice :");
            scanf("%d", &c);

            if (c == 3) {
                loop5:
                system("cls");
                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                scanf("%d", &tickets_to_book);

                if (tickets_to_book <= bus.tp_av_tic) {
                    bus.tp_av_tic -= tickets_to_book;

                    t_fare=(tickets_to_book*bus.tp_fare);
                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                    printf("\n\t\t\tAre you sure want to book this train...");
                    getch();

                    system("cls");
                    printf("\n\t\t\t**=======Payment=======**\n");
                    printf("\n\n\t\t\tEnter the amount  :");
                    scanf("%d", &i_amt);

                    if (i_amt==t_fare) {
                        system("cls");
                        printf("\n\t\t\tbus tickets booked successfully for %d tickets!", tickets_to_book);
                        printf("\n\t\t\t**=======Ticket details=======**\n");
                        printf("\n\t\t_______________________________________________________");
                        printf("\n\t\t| %s Express           %s To %s", bus.tp_name, bus.depart_place, bus.arrive_place);
                        printf("\n\t\t| Bus number      :  %d", bus.tp_no);
                        printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                        printf("\n\t\t| Travel duration :  %s", bus.tp_tm_dur);
                        printf("\n\t\t| Departure Time  :  %s", bus.depart_time);
                        printf("\n\t\t| Arrival Time    :  %s", bus.arrive_time);
                        printf("\n\t\t| Total price     :  %d", t_fare);
                        printf("\n\t\t________________________________________________________");
                        printf("\n\t\t Happy Journey.........");

                        fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                                bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                                bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic);
                        fprintf(temp, "\n_______________________________________________________________________________________");

                    } else {
                        printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %s", bus.tp_fare);
                        bus.tp_av_tic += tickets_to_book;
                        getch();
                        goto loop5;
                    }
                } else {
                    printf("\n\t\t\tNot enough tickets available. Available tickets: %d", bus.tp_av_tic);
                    getch();
                    goto loop5;
                }
            } else if (c == 2) {
                rewind(fp);
            }
        }else{
        fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic);
        fprintf(temp, "\n_______________________________________________________________________________________");
        }

    }

    if (found == 0) {
        printf("\n\n\t\t_________________________________________________");
        printf("\n\t\t\tNo buses Found From %s To %s ", itr_dep, itr_arr);
        printf("\n\t\t\t1. Search another");
        printf("\n\t\t\t2. Back");
        loop3:
        printf("\n\t\t\tEnter the choice  :");
        scanf("%d", &m);

        if (m == 1) {
            rewind(fp);
            goto loop;
        } else if (m == 2) {
            fclose(fp);
            fclose(temp);
            return 1;
        } else {
            printf("\n\t\t\tPlease enter a valid input....");
            getch();
            goto loop3;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("bus_book.txt");
    rename("temp_book.txt", "bus_book.txt");
    getch();

    return 1;
}

int view_bus()                                                                                                           //view buses
{
    FILE *fp;
    struct travel bus;

    fp = fopen("bus_book.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file for reading.\n");
        getch();
        return 0;
    }

    system("cls");
    printf("\n\t\t\t**=======bus Details=======**\n");

    while (fscanf(fp,"\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",bus.tp_name,&bus.tp_no,bus.depart_time,bus.arrive_time) != EOF)
    {
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d \n Time duration  :%s\nAvailable tickets  :%d",bus.depart_place,bus.arrive_place,&bus.tp_fare,bus.tp_tm_dur,&bus.tp_av_tic);
        fscanf(fp,"\n_______________________________________________________________________________________");

        printf("\n\t\t\tbus name          : %s Travels", bus.tp_name);
        printf("\n\t\t\tbus number        : TN-%d", bus.tp_no);
        printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
        printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
        printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
        printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
        printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
        printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
        printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
        printf("\n\t\t________________________________________________");
    }

    fclose(fp);
    getch();
    printf("\n\t\tPress enter to exit");
    getch();
    return 0;
}

int Events_book()                                                                                  // EvenTs Page
{
    int n,m,c,num=1,found=0,b,retval,pnr;
    char i_team[20],i_amt[20];
    char team1[20],team2[20],venue[20],date[20],time[20],price[20];
    FILE *fp,*temp;
    fp=fopen("e_sports_book.txt","r");
    temp=fopen("temp.txt","w");

    loop2:
    system("cls");
    printf("\n\t\t\t**=======Sports Events=======**\n");
    printf("\n\t\t\t1. Football");
    printf("\n\t\t\t2. Cricket");
    printf("\n\t\t\t3. Volleyball");
    printf("\n\t\t\t4. back");
    printf("\n\t\t\t__________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    switch(n){
        case 1:
            system("cls");
            printf("\n\t\t\t**=======Sports Events=======**\n");
            printf("\n\t\t\t1. ISL league");
            printf("\n\t\t\t2. Chennai league");
            printf("\n\t\t\t3. Premier league");
            printf("\n\t\t\t3. Back");
            printf("\n\t\t\t__________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&m);

            switch(m){
                case 1:
                    loop1:
                    system("cls");
                    printf("\n\t\t\t**=======Sports Events=======**\n");
                    printf("\n\t\t\t1. Search matches");
                    printf("\n\t\t\t2. View matches");
                    printf("\n\t\t\t3. Back");
                    printf("\n\t\t_________________________________");
                    printf("\n\t\t\tEnter the choice  :");
                    scanf("%d",&c);
                    break;
            }
    }

    return 0;
}

int view_sports()                                                                             //view sports
{
    int num=1;
    char team1[20],team2[20],venue[20],date[20],time[20],price[20];
    FILE *fp;
    fp=fopen("e_sports_book.txt","r");
    if(fp==NULL){
        printf("error open file");
        fclose(fp);
        return 1;
    }else{

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",team1,team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",venue);
        fscanf(fp,"\n Date         : %s",date);
        fscanf(fp,"\n Time         : %s",time);
        fscanf(fp,"\n Ticket fare  : %s",price);
        fscanf(fp,"\n_________________________________");

        printf("\n\t\t\t%d.Match   %s vs %s",num,team1,team2);
        printf("\n\t\t\t Venue       : %s stadium",venue);
        printf("\n\t\t\t Date        : %s",date);
        printf("\n\t\t\t Time        : %s",time);
        printf("\n\t\t\tTicket fare  :%s",price);
        printf("\n\t\t______________________________________");
        num++;
    }
    }
    printf("\n\t\t\tpress Enter to continue....");
    fclose(fp);
    getch();

    return 1;
}

int admin()                                                                                  //admin page
{
    int n,t1,m;
    int tretval,bretval,fretval,eretval,retval;

    loop1:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\n\t\t\t\t1.Travel");
    printf("\n\t\t\t\t2.Movies");
    printf("\n\t\t\t\t3.Service");
    printf("\n\t\t\t\t4.Events");
    printf("\n\t\t\t\t5.Touristy");
    printf("\n\t\t\t\t6.Back");
    printf("\n\t\t\t\t7. User details");
    printf("\n\t\t\t___________________________");

    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    loop3:
    if(n == 6){
        system("cls");
        printf("\n\t\t\tAre sure want to logout from admin ?");
        printf("\n\t\t\t1. Yes");
        printf("\n\t\t\t2. No");
        printf("\n\t\t\tEnter the choice :");
        scanf("%d",&m);
        if(m==1){
            return 1;
        }else if(m==2){
            goto loop1;
        }else{
            printf("\n\t\t\tPlease Enter valid input.....");
            getch();
            goto loop3;
        }
    }
    switch(n){
        case 1:
        loop2:
        system("cls");
        printf("\n\t\t\t**=======ADMIN=======**\n");
        printf("\n\n\t\t\t\t1.Trains ticket");
        printf("\n\t\t\t\t2.Bus ticket");
        printf("\n\t\t\t\t3.Back");
        printf("\n\t\t\t___________________________");
        printf("\n\t\t\tEnter the choice :");
        scanf("%d",&t1);
        if(t1==3){
            goto loop1;
        }
        switch(t1)
        {
        case 1:
            system("cls");
            tretval=admin_train();
            if(tretval==1){
                    goto loop2;
            }
            break;
        case 2:
            system("cls");
            bretval=admin_bus();
            if(bretval==1){
                    goto loop2;
            }
        default:
            printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
            getch();
            goto loop2;
        }
        break;
    case 4:
        system("cls");
        printf("\n\t\t\t**=======ADMIN=======**\n");
        printf("\n\n\t\t\t\t1. Marathon");
        printf("\n\t\t\t\t2. Sports");
        printf("\n\t\t\t\t3. Concerts");
        printf("\n\t\t\t\t4.Back");
        printf("\n\t\t\t___________________________");
        printf("\n\t\t\tEnter the choice :");
        scanf("%d",&t1);

        switch(t1){
            case 2:
                system("cls");
                eretval=admin_sports_event();
                if(eretval==1){
                    goto loop1;
                }
                break;
            case 4:
                goto loop1;
                break;
        }
        break;
    case 7:
        retval=user_details();
        if(retval==1){
            goto loop1;
        }
    default:
        printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
        getch();
        goto loop1;

    }
    return 0;
}

int admin_train()                                                                             //Admin train ticket details
{
    int n,c,d_retval;
    struct travel train;
    FILE *fp,*temp;

    admin_train:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1.Add train");
    printf("\n\t\t\t\t2.View train details");
    printf("\n\t\t\t\t3.Delete train details");
    printf("\n\t\t\t\t4.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("train_book.txt", "a");                                                    //Admin train ticket adding

        loop:
        system("cls");
        printf("\n\t\t\t**=======Train Details=======**\n");
        printf("\n\n\t\t\t\tTrain name        : ");
        scanf("%s", train.tp_name);
        printf("\n\t\t\t\tTrain number       : ");
        scanf("%d", &train.tp_no);
        printf("\n\t\t\t\tDeparture time     : ");
        scanf("%s", train.depart_time);
        printf("\n\t\t\t\tArrival time       : ");
        scanf("%s", train.arrive_time);
        printf("\n\t\t\t\tDeparture place    : ");
        scanf("%s", train.depart_place);
        printf("\n\t\t\t\tArrival place      : ");
        scanf("%s", train.arrive_place);
        printf("\n\t\t\t\tTicket fare        : ");
        scanf("%d", &train.tp_fare);
        printf("\n\t\t\t\tTravel duration    : ");
        scanf("%s", train.tp_tm_dur);
        printf("\n\t\t\t\tAvailable tickets  : ");
        scanf("%d", &train.tp_av_tic);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
            fprintf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  : %d",train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic);
            fprintf(fp, "\n_______________________________________________________________________________________");
        }

        printf("\n\t\t\t__________________________________________");
        printf("\n\t\t\t\tTrain Details stored successfully");
        printf("\n\n\t\t\t\tDo you want to add another? ");
        printf("\n\t\t\t\t1. Yes");
        printf("\n\t\t\t\t2. back");
        printf("\n\t\t\t\tEnter the choice: ");
        scanf("%d",&c);
        if(c==1){
            goto loop;
        }else{
            admin_train;
        }

        fclose(fp);
        goto admin_train;
        break;
    case 2:
        system("cls");
        view_trains();
        goto admin_train;
        break;
    case 3:
        system("cls");
        d_retval=delete_train();
        if(d_retval==1){
            goto admin_train;
        }else{
            getch();
            goto admin_train;
        }
        break;
    default:
        printf("Please enter valid input");
        goto admin_train;
    }

    return 0;
}

int admin_bus()                                                                                                   //Admin bus
{
    int n,c,d_retval;
    struct travel bus;
    FILE *fp,*temp;

    admin_bus:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1.Add Bus");
    printf("\n\t\t\t\t2.View bus details");
    printf("\n\t\t\t\t3.Delete bus details");
    printf("\n\t\t\t\t4.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("bus_book.txt", "a");                                                                         //Admin bus ticket adding

        loop:
        system("cls");
        printf("\n\t\t\t**=======Train Details=======**\n");
        printf("\n\n\t\t\t\tBus name          : ");
        scanf("%s", bus.tp_name);
        printf("\n\t\t\t\tbus number         : ");
        scanf("%d", &bus.tp_no);
        printf("\n\t\t\t\tDeparture time     : ");
        scanf("%s", bus.depart_time);
        printf("\n\t\t\t\tArrival time       : ");
        scanf("%s", bus.arrive_time);
        printf("\n\t\t\t\tDeparture place    : ");
        scanf("%s", bus.depart_place);
        printf("\n\t\t\t\tArrival place      : ");
        scanf("%s", bus.arrive_place);
        printf("\n\t\t\t\tTicket fare        : ");
        scanf("%d", &bus.tp_fare);
        printf("\n\t\t\t\tTravel duration    : ");
        scanf("%s", bus.tp_tm_dur);
        printf("\n\t\t\t\tAvailable tickets  : ");
        scanf("%d", &bus.tp_av_tic);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
            fprintf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic);
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
           goto admin_bus;
        }
        break;
    case 2:
        system("cls");
        view_bus();
        goto admin_bus;
        break;
    case 3:
        system("cls");
        d_retval=delete_bus();
        if(d_retval==1){
            goto admin_bus;
        }else{
            getch();
            goto admin_bus;
        }
        break;
    default:
        printf("Please enter valid input");
        goto admin_bus;
    }

    return 0;
}


int delete_train()
{
    FILE *fp, *temp;
    struct travel train;
    int found = 0, c;
    char itr_name[20];

    fp = fopen("train_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    system("cls");
    printf("\n\t\t\t**=======Delete Train Details=======**\n");
    printf("\n\t1. Back");
    printf("\n\t\t\tEnter the train name    :");
    scanf(" %s", itr_name);

    if (strcmp(itr_name, "1") == 0)
    {
        fclose(fp);
        fclose(temp);
        return 1;
    }

    while (fscanf(fp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",train.tp_name,&train.tp_no,train.depart_time,train.arrive_time) != EOF)
    {
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",train.depart_place,train.arrive_place,&train.tp_fare,train.tp_tm_dur,&train.tp_av_tic);
        fscanf(fp,"\n_______________________________________________________________________________________");

        if (strcmp(train.tp_name, itr_name) == 0)
        {
            found = 1;
            printf("\n\t\t\t**=======Train Details to Delete=======**\n");
            printf("\n\n\t\t\tTrain name      : %s Express", train.tp_name);
            printf("\n\t\t\tTrain number      : %d", train.tp_no);
            printf("\n\t\t\tDeparture time    : %s", train.depart_time);
            printf("\n\t\t\tArrival time      : %s", train.arrive_time);
            printf("\n\t\t\tDeparture place   : %s", train.depart_place);
            printf("\n\t\t\tArrival place     : %s", train.arrive_place);
            printf("\n\t\t\tTicket fare       : %d", train.tp_fare);
            printf("\n\t\t\tTime duration     : %s", train.tp_tm_dur);
            printf("\n\t\t\tAvailable tickets : %d", train.tp_av_tic);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\tAre you sure you want to delete this train?");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t\t3. Enter thhe choice");
            scanf("%d", &c);

            if (c == 1)
            {
                printf("\n\t\t\tTrain details deleted successfully...");
                getch();
            }
            else
            {
                fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
                fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic);
                fprintf(temp,"\n_______________________________________________________________________________________");


            }
        }
        else
        {
            fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
            fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic);
            fprintf(temp,"\n_______________________________________________________________________________________");
        }
    }

    fclose(fp);
    fclose(temp);

    remove("train_book.txt");
    rename("temp_book.txt", "train_book.txt");

    if (found == 0)
    {
        printf("\n\t\t\tTrain name %s not found", itr_name);
        getch();
    }

    return 0;
}

int delete_bus()
{
    FILE *fp, *temp;
    struct travel bus;
    int found = 0, c;
    char ibs_name[20];

    fp = fopen("bus_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    system("cls");
    printf("\n\t\t\t**=======Delete bus Details=======**\n");
    printf("\n\t1. Back");
    printf("\n\t\t\tEnter the bus name    :");
    scanf("%s", ibs_name);

    if (strcmp(ibs_name, "1") == 0)
    {
        fclose(fp);
        fclose(temp);
        return 1;
    }

    while (fscanf(fp,"\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",bus.tp_name,&bus.tp_no,bus.depart_time,bus.arrive_time) != EOF)
    {
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",bus.depart_place,bus.arrive_place,&bus.tp_fare,bus.tp_tm_dur,&bus.tp_av_tic);
        fscanf(fp,"\n_______________________________________________________________________________________");

        if (strcmp(bus.tp_name, ibs_name) == 0)
        {
            found = 1;
            printf("\n\t\t\t**=======Bus Details to Delete=======**\n");
            printf("\n\n\t\t\t bus name       : %s ", bus.tp_name);
            printf("\n\t\t\t bus number       : %d", bus.tp_no);
            printf("\n\t\t\tDeparture time    : %s", bus.depart_time);
            printf("\n\t\t\tArrival time      : %s", bus.arrive_time);
            printf("\n\t\t\tDeparture place   : %s", bus.depart_place);
            printf("\n\t\t\tArrival place     : %s", bus.arrive_place);
            printf("\n\t\t\tTicket fare       : %d", bus.tp_fare);
            printf("\n\t\t\tTime duration     : %s", bus.tp_tm_dur);
            printf("\n\t\t\tAvailable tickets : %d", bus.tp_av_tic);
            printf("\n\t\t________________________________________________");

            printf("\n\t\t\tAre you sure you want to delete this bus?");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\n\t\t\tEnter thhe choice :");
            scanf("%d", &c);

            if (c == 1)
            {
                printf("\n\t\t\t bus details deleted successfully...");
                getch();
            }
            else
            {
                fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }
        }
        else
        {
            fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
            fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic);
            fprintf(temp, "\n_______________________________________________________________________________________");
        }
    }
    fclose(fp);
    fclose(temp);

    remove("bus_book.txt");
    rename("temp_book.txt", "bus_book.txt");

    if (found == 0)
    {
        printf("\n\t\t\t bus name %s not found", ibs_name);
    }

    return 0;
}

int admin_sports_event()
{
    int n,m,c,retval;
    char team1[20],team2[20],venue[20],date[20],time[10],price[10];

    hloop:
    system("cls");
    printf("\n\t\t\t=====Sports=====\n");
    printf("\n\t\t\t1. Football");
    printf("\n\t\t\t2. Cricket");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t\t_____________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);
    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            system("cls");
            printf("\n\t\t\t=====Football Sports=====\n");
            printf("\n\t\t1. ISL League                   5. Premier league               8. chennai league");
            printf("\n\t\t2. View match details           6. view match details           9. view match details");
            printf("\n\t\t3. Delete match details         7. Delete match details         10.Delete match details");
            printf("\n\t\t4. Back");
            printf("\n\t\t____________________________________________________________________________________________");
            printf("\n\t\tEnter the choice   :");
            scanf("%d",&m);
            switch(m){
                case 1:
                    //retval=add_isl();
                    if(retval==1){
                        goto hloop;
                    }
                    break;
                case 2:
                    retval=view_sports();
                    if(retval==1){
                        goto hloop;
                    }
                    break;
            }
            break;
        default:
            printf("\n\t\t\tInvalid input....");
            getch();
            goto hloop;

    }
    return 0;
}

/*int add_isl()
{
    printf("hi");
    getch();
    return 1;
}*/
