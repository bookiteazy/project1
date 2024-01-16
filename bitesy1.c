#include <stdio.h>
#include <conio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int login_details();
int user_details();
int my_profile(),user_balance();
int train_tik_book();
int search_train(),view_trains();
int bus_tik_book();
int search_bus(),view_bus();
int Events_sports_book();
int search_isl(),view_isl();
int admin();
int admin_train(),delete_train();
int admin_bus(),delete_bus();
int admin_sports_event(),admin_isl();
char u_name[20],u_pwd[20];
int retval;

struct travel
{
    char tp_name[20],depart_time[10],arrive_time[10],depart_place[20],arrive_place[20];
    char tp_tm_dur[15];
    int tp_no,tp_av_tic,tp_fare;
};
struct sports
{
    char team1[20],team2[20],venue[20],date[20],time[10];
    int t_fare,av_tic;
};

int main()
{
                                                                                //Main function
    int ch,u,n,m;

    loop:
        system("cls");
        printf("\n\n\n\n\t\t\t**=======Bookiteazy=======**\n");
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
            getch();
            goto loop;
        }

        hloop:
        system("cls");
        printf("\n\t\t\t**=======Bookiteazy=======**\n");
        printf("\n\t\t\t\t1. Travel                                          11. My profile");
        printf("\n\t\t\t\t2. Movies");
        printf("\n\t\t\t\t3. Service");
        printf("\n\t\t\t\t4. Event");
        printf("\n\t\t\t\t5. Touristy");
        printf("\n\t\t\t\t6. Logout");
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
                eloop:
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
                        retval=Events_sports_book();
                        if(retval==1){
                            goto eloop;
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
                printf("\n\n\t\t\tAre sure want to logout....");
                printf("\n\t\t\t1. Yes");
                printf("\n\t\t\t2. No");
                printf("\n\t\t______________________________");
                printf("\n\n\t\t\tEnter the choice   :");
                scanf("%d",&n);
                if(n==1){
                    system("cls");
                    printf("\n\n\t\t\tLogout successfull....");
                    getch();
                    goto loop;
                }else{
                    goto hloop;
                }
                break;
            case 11:
                retval= my_profile();
                if(retval==1){
                    goto hloop;
                }
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
    int m,found=0,u_balance=0;
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

        while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
             fscanf(fp, "Balance   : %d",&u_balance);
             fscanf(fp, "\n______________________________\n");

            if (strcmp(username, i_username) == 0 && strcmp(password, i_password) == 0) {
                found=1;
                strcpy(u_name,username);
                strcpy(u_pwd,password);
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
        fprintf(fp, "Balance   : %d",u_balance);
        fprintf(fp, "\n______________________________\n");

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
    int n,m,c,found=0,u_balance,num=0;
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
            while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                fscanf(fp, "Balance   : %d",&u_balance);
                fscanf(fp, "\n______________________________\n");


                printf("\n\t\t\tUsername     : %s",username);
                printf("\n\t\t\tPassword     : %s",password);
                printf("\n\t\t\tBalance      : %d",u_balance);
                printf("\n\t\t___________________________________________");
            }
            printf("\n\t\tpress Enter to go back.......");
            getch();
            fclose(fp);
            goto loop;
            break;
        case 2:
            loop1:
            fp = fopen("user.txt", "r");
            temp = fopen("temp.txt", "w");
            if(fp==NULL || temp==NULL){
                printf("\n\t\t\terror openning the file");
                getch();
                goto loop;
            }
            system("cls");
            printf("\n\t\t\t**=======Delete User Info=======**\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter the username    :");
            scanf("%s",i_uname);

            if(strcmp(i_uname,"1")==0){
                fclose(fp);
                fclose(temp);
                goto loop;
            }
             while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                fscanf(fp, "Balance   : %d",&u_balance);
                fscanf(fp, "\n______________________________\n");

                num++;
                if(strcmp(username,i_uname)==0){
                    found=1;
                    system("cls");
                    printf("\n\t\t\t**=======Delete User Info=======**\n");
                    printf("\n\t\t%d.      Username     : %s",num,username);
                    printf("\n\t\t\tPassword     : %s",password);
                    printf("\n\t\t\tBalance      : %d",u_balance);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tAre you sure want to delete this info......");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\n\t\t\t3. Next");
                    printf("\n\t\t___________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==1){
                        printf("\n\t\t\tUser info deleted successfully...");
                        strcpy(i_uname,"dummy");
                        getch();
                    }else if(m==2){
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "Balance   : %d",u_balance);
                        fprintf(temp, "\n______________________________\n");
                        strcpy(i_uname,"dummy");
                    }else if(m==3){
                        found=3;
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "Balance   : %d",u_balance);
                        fprintf(temp, "\n______________________________\n");
                    }else {
                        fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(temp, "Balance   : %d",u_balance);
                        fprintf(temp, "\n______________________________\n");
                    }
                }else{
                    fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                    fprintf(temp, "Balance   : %d",u_balance);
                    fprintf(temp, "\n______________________________\n");
                }
            }
            if(found==0){
                num=0;
                printf("\n\t\t\tNo details available as %s : i_uname");
                getch();
            }else if(found==3){
                num=0;
                printf("\n\t\t\tNO Users Found Next....");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t____________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&c);

                if(c==1){
                    fclose(fp);
                    fclose(temp);
                    remove("user.txt");
                    rename("temp.txt","user.txt");
                    goto loop1;
                }
            }
            num=0;
            fclose(fp);
            fclose(temp);
            remove("user.txt");
            rename("temp.txt","user.txt");
            goto loop;
    }

    return 0;
}

int my_profile()
{
    int n;
    hloop:
    system("cls");
    printf("\n\t\t**=======My Profile Info=======**\n");
    printf("\n\t\t\tUsername   : %s",u_name);
    printf("\n\t\t\tPasword    : %s",u_pwd);
    printf("\n\n\t\t\t1. My Balance");
    printf("\n\n\t\t\t2. Back");
    printf("\n\t\t____________________________");
    printf("\n\n\t\t\tEnter the choice    :");
    scanf("%d",&n);

    if(n==1){
        retval=user_balance();
        if(retval==1){
            goto hloop;
        }
    }else{
        return 1;
    }

    return 1;
}

int user_balance()
{
    int n,i_amt,u_balance;
    char username[10],password[20];
    FILE *fp,*temp;

    hloop:
    system("cls");
    printf("\n\t\t\t**=======My Balance=======**\n");
    printf("\n\t\t\t1. Add money");
    printf("\n\t\t\t2. Check Balance");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t_________________________________");
    printf("\n\t\t\tEnter the choice  :");
    scanf("%d",&n);

    if(n==1){
        fp=fopen("user.txt","r");
        temp=fopen("temp.txt","w");

        system("cls");
        printf("\n\t\t\t**=======My Balance=======**\n");
        while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
            fscanf(fp, "Balance   : %d",&u_balance);
            fscanf(fp, "\n______________________________\n");

            if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                 printf("\n\t\t\tUsername   : %s",u_name);
                 printf("\n\t\t\tPasword    : %s",u_pwd);
                 printf("\n\n\t\t\tAdd Money  :");
                 scanf("%d",&i_amt);
                 u_balance += i_amt;

                 fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                 fprintf(temp, "Balance   : %d",u_balance);
                 fprintf(temp, "\n______________________________\n");
                 printf("\n\t\t\t Money added successfully...     Available balance  : %d",u_balance);
                 getch();

            }else{
                fprintf(temp, "username  : %s\npassword  : %s\n", username, password);
                fprintf(temp, "Balance   : %d",u_balance);
                fprintf(temp, "\n______________________________\n");
            }
        }
        fclose(fp);
        fclose(temp);
        remove("user.txt");
        rename("temp.txt","user.txt");
        goto hloop;

    }else if(n==2){
        fp=fopen("user.txt","r");

        system("cls");
        printf("\n\t\t\t**=======My Balance=======**\n");
        while (fscanf(fp, "username  : %s\npassword  : %s\n", username, password)!=EOF){
            fscanf(fp, "Balance   : %d",&u_balance);
            fscanf(fp, "\n______________________________\n");

            if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                printf("\n\t\t\tUsername     : %s",username);
                printf("\n\t\t\tPassword     : %s",password);
                printf("\n\t\t\tBalance      : %d Rs",u_balance);
                printf("\n\t\t_________________________________________");
                printf("\n\n\t\t\tPress Enter to go back...");
                getch();
            }

         }
         fclose(fp);
    }else if(n==3){
        return 1;
    }else{
        printf("\n\t\t\tPlease Enter a valid input...");
        getch();
        goto hloop;
    }
    goto hloop;
    return 1;
}

int train_tik_book()                                                                                          //Train tickect booking interface
{
    int m;
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
            retval=search_train();
            if(retval==1){
                goto tloop;
            }
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

int search_train()
{
    FILE *fp, *temp, *ub, *utemp;
    struct travel train;
    int found = 0, c, m,tickets_to_book,t_fare,i_amt,num=0,u_balance;
    char itr_dep[20], itr_arr[20];
    char username[20],password[20];

    fp = fopen("train_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL || ub == NULL) {
        printf("Error opening file for reading.\n");
        getch();
        return 1;
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

        if(found==1){
            strcpy(itr_arr,"dummy");
        }
        num++;

        if (strcmp(train.depart_place, itr_dep) == 0 && strcmp(train.arrive_place, itr_arr) == 0) {
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Train Details =======**\n");
            printf("\n\n\t\t\tTrain ID        : %d", num);
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
                ub = fopen("user.txt","r");
                utemp = fopen("utemp.txt","w");
                while (fscanf(ub, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                    fscanf(ub, "Balance   : %d",&u_balance);
                    fscanf(ub, "\n______________________________\n");

                    if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                        loop5:
                        system("cls");
                        printf("\n\t\t\t**======Train Ticket Booking=======**\n");
                        printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                        scanf("%d", &tickets_to_book);

                        if (tickets_to_book <= train.tp_av_tic) {

                            t_fare=(tickets_to_book*train.tp_fare);
                            printf("\n\t\t\t Total ticket price      : %d",t_fare);
                            printf("\n\t\t\tAre you sure want to book this train...");
                            getch();

                            loop6:
                            system("cls");
                            printf("\n\t\t\t\t**=======Payment=======**\n");
                            printf("\n________________________________");
                            printf("\n| Total ticket price      : %d\t|",t_fare);
                            printf("\n|_______________________________|");
                            printf("\n\n\t\t\t\tEnter the amount  :");
                            scanf("%d", &i_amt);
                            if(i_amt<=u_balance){
                                if (i_amt == t_fare) {
                                    u_balance -=i_amt;
                                    train.tp_av_tic -= tickets_to_book;
                                    system("cls");
                                    printf("\n\n\t\t\tTrain tickets booked successfully for %d tickets!", tickets_to_book);
                                    printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                    printf("\n\t\t_______________________________________________________            Available Balance  : %d",u_balance);
                                    printf("\n\t\t| %s Express           %s To %s", train.tp_name, train.depart_place, train.arrive_place);
                                    printf("\n\t\t| Train number    :  %d", train.tp_no);
                                    printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                                    printf("\n\t\t| Travel duration :  %s", train.tp_tm_dur);
                                    printf("\n\t\t| Departure Time  :  %s", train.depart_time);
                                    printf("\n\t\t| Arrival Time    :  %s", train.arrive_time);
                                    printf("\n\t\t| Total price     :  %d", t_fare);
                                    printf("\n\t\t________________________________________________________");
                                    printf("\n\n\t\t Happy Journey.........");

                                    fprintf(utemp, "username  : %s\npassword  : %s\n", username, password);
                                    fprintf(utemp, "Balance   : %d",u_balance);
                                    fprintf(utemp, "\n______________________________\n");

                                    fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                                    train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                                    train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic);
                                    fprintf(temp, "\n_______________________________________________________________________________________");

                                }else{
                                    printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                    getch();
                                    goto loop6;
                                }
                                getch();
                            }else{
                               printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                               getch();
                               goto loop5;
                            }
                        }else{
                             printf("\n\t\t\tNot enough tickets available....(Available tickets: %d",train.tp_av_tic );
                             getch();
                             goto loop5;
                        }
                    }else{
                            fprintf(utemp, "username  : %s\npassword  : %s\n", username, password);
                            fprintf(utemp, "Balance   : %d",u_balance);
                            fprintf(utemp, "\n______________________________\n");
                    }
                }
                fclose(ub);
                fclose(utemp);
                remove("user.txt");
                rename("utemp.txt","user.txt");
            }else if(c == 2){
                rewind(fp);
            }else{
                found=0;
                fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                       train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                       train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }

        }else{
        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic);
        fprintf(temp, "\n_______________________________________________________________________________________");
        }

    }

    if (found == 0){
        num=0;
        printf("\n\n\t\t_________________________________________________");
        printf("\n\t\t\tNo Trains Found From %s To %s ", itr_dep, itr_arr);
        printf("\n\t\t\t1. Search another");
        printf("\n\t\t\t2. Back");
        loop3:
        printf("\n\t\t\tEnter the choice  :");
        scanf("%d", &m);

        if (m == 1){
            rewind(fp);
            goto loop;
        }else if (m == 2){
            fclose(fp);
            fclose(temp);
            return 1;
        }else{
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
    int num=0;

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

        num++;
        printf("\n\t\t\tTrain ID          : %d", num);
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
    int m;
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
            retval=search_bus();
            if(retval==1){
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
    FILE *fp, *temp,*ub, *utemp;
    struct travel bus;
    int found = 0, c, m, tickets_to_book,t_fare, i_amt,num=0,u_balance;
    char itr_dep[20], itr_arr[20],username[20],password[20];

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

        if(found==1){
            strcpy(itr_arr,"dummy");
        }

        num++;
        if (strcmp(bus.depart_place, itr_dep) == 0 && strcmp(bus.arrive_place, itr_arr) == 0) {
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Bus Details =======**\n");
            printf("\n\n\t\t\tBus ID           :%d", num);
            printf("\n\n\t\t\tBus name         : %s Express", bus.tp_name);
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
                ub = fopen("user.txt","r");
                utemp = fopen("utemp.txt","w");
                while (fscanf(ub, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                    fscanf(ub, "Balance   : %d",&u_balance);
                    fscanf(ub, "\n______________________________\n");

                    if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                    loop5:
                    system("cls");
                    printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                    scanf("%d", &tickets_to_book);

                    if (tickets_to_book <= bus.tp_av_tic) {
                        t_fare=(tickets_to_book*bus.tp_fare);
                        printf("\n\t\t\t Total ticket price      : %d",t_fare);
                        printf("\n\t\t\tAre you sure want to book this train...");
                        getch();

                        loop6:
                        system("cls");
                        printf("\n\t\t\t\t**=======Payment=======**\n");
                        printf("\n________________________________");
                        printf("\n| Total ticket price      : %d\t|",t_fare);
                        printf("\n|_______________________________|");
                        printf("\n\n\t\t\t\tEnter the amoun  :");
                        scanf("%d", &i_amt);

                        if(i_amt<=u_balance){

                            if (i_amt == t_fare) {
                                system("cls");
                                u_balance -=i_amt;
                                bus.tp_av_tic -= tickets_to_book;
                                printf("\n\n\t\t\tbus tickets booked successfully for %d tickets!", tickets_to_book);
                                printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                printf("\n\t\t_______________________________________________________             Available Balance : %d",u_balance);
                                printf("\n\t\t| %s Express           %s To %s", bus.tp_name, bus.depart_place, bus.arrive_place);
                                printf("\n\t\t| Bus number      :  %d", bus.tp_no);
                                printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                                printf("\n\t\t| Travel duration :  %s", bus.tp_tm_dur);
                                printf("\n\t\t| Departure Time  :  %s", bus.depart_time);
                                printf("\n\t\t| Arrival Time    :  %s", bus.arrive_time);
                                printf("\n\t\t| Total price     :  %d", t_fare);
                                printf("\n\t\t________________________________________________________");
                                printf("\n\t\t Happy Journey.........");

                                fprintf(utemp, "username  : %s\npassword  : %s\n", username, password);
                                fprintf(utemp, "Balance   : %d",u_balance);
                                fprintf(utemp, "\n______________________________\n");

                                fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                                bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                                bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic);
                                fprintf(temp, "\n_______________________________________________________________________________________");

                            }else{
                                printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                getch();
                                goto loop6;
                            }
                        }else{
                            printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                            getch();
                            goto loop5;
                        }
                    }else{
                        printf("\n\t\t\tNot enough tickets available. Available tickets: %d", bus.tp_av_tic);
                        getch();
                        goto loop5;
                    }
                }else{
                    fprintf(utemp, "username  : %s\npassword  : %s\n", username, password);
                    fprintf(utemp, "Balance   : %d",u_balance);
                    fprintf(utemp, "\n______________________________\n");
                }
            }
            fclose(ub);
            fclose(utemp);
            remove("user.txt");
            rename("utemp.txt","user.txt");
        } else if (c == 2) {
            rewind(fp);
        }else{
            found=0;
            fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d",
                        bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic);
                fprintf(temp, "\n_______________________________________________________________________________________");
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
        num=0;
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

int Events_sports_book()                                                                                  // EvenTs Page
{
    int n,m,num=1,found=0;
    char i_team1[20],i_team2[20],i_amt[20];

    FILE *fp,*temp;
    temp=fopen("temp.txt","w");

    hloop:
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
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Sports Events=======**\n");
            printf("\n\t\t\t1. ISL league                   11. View Matches");
            printf("\n\t\t\t2. Premier league               22. View Matches");
            printf("\n\t\t\t3. Back");
            printf("\n\t\t\t__________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&m);
            if(m==3){
                goto hloop;
            }

            switch(m){
                case 1:
                    retval=search_isl();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 11:
                    retval=view_isl();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 2:
                    //retval=search_premier();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 22:
                    //retval=view_premier();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                default:
                    printf("\n\t\t\tPlease Enter a valid input...");
                    getch();
                    goto loop1;
            }
            break;
        case 4:
            return 1;
            break;
        default:
            printf("\n\t\t\tPlease Enter a valid input...");
            getch();
            goto hloop;
    }

    return 1;
}

int search_isl()
{
    struct sports isl;
    char i_team1[20],i_team2[20],username[20], password[20];
    int n,c,tic_book,found=0,num=0,tot_fare,i_amt,u_balance;
    FILE *fp,*temp,*ub,*utemp;

    hloop:
    fp=fopen("isl_book.txt","r");
    temp=fopen("temp_book.txt","w");

    if(fp==NULL || temp == NULL){
        printf("error openning file...");
        getch();
        return 1;
    }
    system("cls");
    printf("\n\t\t\t**======Search Matches=====**\n");
    printf("\n\t\t1. Back");
    printf("\n\t\t\tEnter the team 1 name    :");
    scanf("%s",i_team1);

    if(strcmp(i_team1,"1")==0){
        return 1;
    }
    printf("\n\t\t\tEnter the team 2 name    :");
    scanf("%s",i_team2);
    if(strcmp(i_team2,"1")==0){
        return 1;
    }

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",isl.venue);
        fscanf(fp,"\n Date         : %s",isl.date);
        fscanf(fp,"\n Time         : %s",isl.time);
        fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d",&isl.av_tic);
        fscanf(fp,"\n_________________________________");

        num++;
        if(strcmp(i_team1,isl.team1)==0 && strcmp(i_team2,isl.team2)==0 || strcmp(i_team1,isl.team2)==0 && strcmp(i_team2,isl.team1)==0){
            found=1;
            printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
            printf("\n\t\t\t  Venue            : %s stadium",isl.venue);
            printf("\n\t\t\t  Date             : %s",isl.date);
            printf("\n\t\t\t  Time             : %s",isl.time);
            printf("\n\t\t\t  Ticket fare      : %d",isl.t_fare);
            printf("\n\t\t\t Available Tickets : %d",isl.av_tic);
            printf("\n\t\t______________________________________");

            printf("\n\t\t\tAre sure want to book this Match....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t____________________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&n);

            if(n==1){
                ub = fopen("user.txt","r");
                utemp = fopen("utemp.txt","w");
                while (fscanf(ub, "username  : %s\npassword  : %s\n", username, password)!=EOF){
                    fscanf(ub, "Balance   : %d",&u_balance);
                    fscanf(ub, "\n______________________________\n");

                    if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){

                        loop1:
                        system("cls");
                        printf("\n\t\t\t**====Match Ticket Booking====**\n");
                        printf("\n\t\t\tEnter the number of Tickets   :");
                        scanf("%d",&tic_book);

                        if(tic_book<=isl.av_tic){
                            tot_fare=(tic_book*isl.t_fare);
                            printf("\n\n\t\t\tTotal Fare   : %d\n",tot_fare);
                            printf("\n\t\t\t1. Proceed to payment");
                            printf("\n\t\t\t2. Cancel Booking");
                            printf("\n\t\t____________________________________");
                            printf("\n\t\t\tEnter the choice   :");
                            scanf("%d",&c);

                            if(c==1){
                                loop2:
                                system("cls");
                                printf("\n\t\t\t**====Payment====**\n");
                                printf("\n\t\t\t________________________________");
                                printf("\n\t\t\t| Total ticket fare       : %d  |",tot_fare);
                                printf("\n\t\t\t|_______________________________|");
                                printf("\n\n\t\t\tEnter the amount  :");
                                scanf("%d",&i_amt);

                                if(i_amt<=u_balance){
                                    if(i_amt==tot_fare){
                                        isl.av_tic -= tic_book;
                                        u_balance -= i_amt;
                                        system("cls");
                                        printf("\n\t\t\t**=======Ticket details=======**\n");
                                        printf("\n\t\t\tPayment successfull!!...");
                                        printf("\n\t\t_______________________________________________________         Available Balance : %d",u_balance);
                                        printf("\n\t\t| Match       %s vs %s", isl.team1,isl.team2);
                                        printf("\n\t\t| Venue           :  %s Stadium", isl.venue);
                                        printf("\n\t\t| Date            :  %s", isl.date);
                                        printf("\n\t\t| Timing          :  %s", isl.time);
                                        printf("\n\t\t| Total tickets   :  %d", tic_book);
                                        printf("\n\t\t| Total fare      :  %d", tot_fare);
                                        printf("\n\t\t________________________________________________________");
                                        printf("\n\t\t\tHave a nice day......");
                                        getch();

                                        fprintf(utemp, "username  : %s\npassword  : %s\n", username, password);
                                        fprintf(utemp, "Balance   : %d",u_balance);
                                        fprintf(utemp, "\n______________________________\n");

                                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                                        fprintf(temp,"\n Venue        : %s",isl.venue);
                                        fprintf(temp,"\n Date         : %s",isl.date);
                                        fprintf(temp,"\n Time         : %s",isl.time);
                                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                                        fprintf(temp,"\n Available Tickets  : %d",isl.av_tic);
                                        fprintf(temp,"\n_________________________________");

                                    }else{
                                        printf("\n\t\t\tPlease Enter correct amount...");
                                        getch();
                                        goto loop2;
                                    }
                                }else{
                                    printf("\n\t\t\tInsufficient Money......      Available money   : %d ",u_balance);
                                    getch();
                                    goto loop1;
                                }
                            }else{
                                printf("\n\t\t\tBooking cancelled....");
                                getch();
                                fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                                fprintf(temp,"\n Venue        : %s",isl.venue);
                                fprintf(temp,"\n Date         : %s",isl.date);
                                fprintf(temp,"\n Time         : %s",isl.time);
                                fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                                fprintf(temp,"\n Available Tickets  : %d",isl.av_tic);
                                fprintf(temp,"\n_________________________________");
                            }
                        }else{
                            printf("\n\t\t\t %d tickets Not Available  (Available tickets %d)",tic_book,isl.av_tic);
                            getch();
                            goto loop1;
                        }
                    }else{
                        fprintf(utemp, "username  : %s\npassword  : %s\n", username, password);
                        fprintf(utemp, "Balance   : %d",u_balance);
                        fprintf(utemp, "\n______________________________\n");
                    }
                }
                fclose(ub);
                fclose(utemp);
                remove("user.txt");
                rename("utemp.txt","user.txt");
            }else{
                printf("\n\t\t\tBooking cancelled....");
                getch();
                fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                fprintf(temp,"\n Venue        : %s",isl.venue);
                fprintf(temp,"\n Date         : %s",isl.date);
                fprintf(temp,"\n Time         : %s",isl.time);
                fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                fprintf(temp,"\n Available Tickets  : %d",isl.av_tic);
                fprintf(temp,"\n_________________________________");
            }
        }else{
            fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
            fprintf(temp,"\n Venue        : %s",isl.venue);
            fprintf(temp,"\n Date         : %s",isl.date);
            fprintf(temp,"\n Time         : %s",isl.time);
            fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
            fprintf(temp,"\n Available Tickets  : %d",isl.av_tic);
            fprintf(temp,"\n_________________________________");
        }
    }

    if(found==0){
        printf("\n\t\t\tNo Matches found between %s vs %s ",i_team1,i_team2);
        fclose(fp);
        fclose(temp);
        getch();
        goto hloop;
    }else{
        fclose(fp);
        fclose(temp);
        remove("isl_book.txt");
        rename("temp_book.txt","isl_book.txt");
        return 1;
    }
    return 0;
}

int view_isl()                                                                             //view sports
{
    struct sports isl;
    int num=1,found=0,n,retval;
    FILE *fp;
    fp=fopen("isl_book.txt","r");
    if(fp==NULL){
        printf("error open file");
        fclose(fp);
        return 1;
    }else{

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",isl.venue);
        fscanf(fp,"\n Date         : %s",isl.date);
        fscanf(fp,"\n Time         : %s",isl.time);
        fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d",&isl.av_tic);
        fscanf(fp,"\n_________________________________");
        found=1;

        printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
        printf("\n\t\t\t  Venue            : %s stadium",isl.venue);
        printf("\n\t\t\t  Date             : %s",isl.date);
        printf("\n\t\t\t  Time             : %s",isl.time);
        printf("\n\t\t\t  Ticket fare      : %d",isl.t_fare);
        printf("\n\t\t\t Available Tickets : %d",isl.av_tic);
        printf("\n\t\t______________________________________");
        num++;
    }
    }
    if(found==0){
        printf("\n\n\t\t\tNo information added");
        fclose(fp);
        getch();
        return 1;
    }else{
        fclose(fp);
        printf("\n\t\t\tPress Enter to Back....");
        getch();
        return 1;
    }

    return 1;
}

int admin()                                                                                  //admin page
{
    int n,t1,m;

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

            switch(t1){
                case 1:
                    system("cls");
                    retval=admin_train();
                    if(retval==1){
                    goto loop2;
                    }
                    break;
                case 2:
                    system("cls");
                    retval=admin_bus();
                    if(retval==1){
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

            if(t1==4){
            goto loop1;
            }

            switch(t1){
            case 2:
                system("cls");
                retval=admin_sports_event();
                if(retval==1){
                    goto loop1;
                }
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
    int n,c;
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
        retval=delete_train();
        if(retval==1){
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
    int n,c;
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
        retval=delete_bus();
        if(retval==1){
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
    int n,m,c;
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
            loop:
            system("cls");
            printf("\n\t\t\t=====Football Sports=====\n");
            printf("\n\t\t1. ISL League");
            printf("\n\t\t2. Premier league");
            printf("\n\t\t3. chennai league");
            printf("\n\t\t4. Back");
            printf("\n\t\t_________________________________");
            printf("\n\t\tEnter the choice   :");
            scanf("%d",&m);
            switch(m){
                case 1:
                    retval=admin_isl();
                    if(retval==1){
                        goto loop;
                    }
                    break;
                case 2:
                    if(retval==1){
                        goto hloop;
                    }
                    break;
                case 3:
                    if(retval==1){
                        goto hloop;
                    }
                    break;
                case 4:
                    goto hloop;
                default:
                    printf("");
            }
            break;
        default:
            printf("\n\t\t\tInvalid input....");
            getch();
            goto hloop;

    }
    return 0;
}

int admin_isl()
{
    struct sports isl;
    FILE *fp,*temp;
    int n,m,c,found=0,num=0;
    char i_team1[20],i_team2[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====ISL League=====\n");
    printf("\n\t\t\t1. Add Matches ");
    printf("\n\t\t\t2. View Matches");
    printf("\n\t\t\t3. Delete Matches");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t_______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&m);

    if(m==4){
        return 1;
    }

    switch(m){
        case 1:
            fp=fopen("isl_book.txt","a");
            loop:
            system("cls");
            printf("\n\t\t\t=====Add ISL Matches=====\n");
            printf("\n\t\t\t1. Team 1        :");
            scanf("%s",isl.team1);
            printf("\n\t\t\t2. Team 2        :");
            scanf("%s",isl.team2);
            printf("\n\t\t\t3. Venue         :");
            scanf("%s",isl.venue);
            printf("\n\t\t\t4. Date          :");
            scanf("%s",isl.date);
            printf("\n\t\t\t5. Time          :");
            scanf("%s",isl.time);
            printf("\n\t\t\t6. Ticket fare   :");
            scanf("%d",&isl.t_fare);
            printf("\n\t\t\t7. Available Tickets :");
            scanf("%d",&isl.av_tic);

            fprintf(fp,"\n Match  %s vs %s",isl.team1,isl.team2);
            fprintf(fp,"\n Venue        : %s",isl.venue);
            fprintf(fp,"\n Date         : %s",isl.date);
            fprintf(fp,"\n Time         : %s",isl.time);
            fprintf(fp,"\n Ticket fare  : %d",isl.t_fare);
            fprintf(fp,"\n Available Tickets  : %d",isl.av_tic);
            fprintf(fp,"\n_________________________________");

            system("cls");
            printf("\n\t\t_________________________________________________");
            printf("\n\n\t\t\tDo you want to add another...");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t_______________________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&n);
            if(n==1){
                goto loop;
            }else{
                fclose(fp);
                goto hloop;
            }
            break;
        case 2:
            retval=view_isl();
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
            fp=fopen("isl_book.txt","r");
            temp=fopen("temp.txt","w");

            loop1:
            system("cls");
            printf("\n\t\t\t=====Delete ISL Matches=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter team 1 name    :");
            scanf("%s",i_team1);
            if(strcmp(i_team1,"1")==0){
                goto hloop;
            }
            printf("\n\t\t\tEnter team 2 name    :");
            scanf("%s",i_team2);

            while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!= EOF){
                fscanf(fp,"\n Venue        : %s",isl.venue);
                fscanf(fp,"\n Date         : %s",isl.date);
                fscanf(fp,"\n Time         : %s",isl.time);
                fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
                fscanf(fp,"\n Available Tickets  : %d",&isl.av_tic);
                fscanf(fp,"\n_________________________________");

                 num++;
                 if ((strcmp(i_team1, isl.team1) == 0 && strcmp(i_team2, isl.team2) == 0) || (strcmp(i_team1, isl.team2) == 0 && strcmp(i_team2, isl.team1) == 0)) {
                    found=1;
                    printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
                    printf("\n\t\t\t  Venue       : %s stadium",isl.venue);
                    printf("\n\t\t\t  Date        : %s",isl.date);
                    printf("\n\t\t\t  Time        : %s",isl.time);
                    printf("\n\t\t\t  Ticket fare  : %d",isl.t_fare);
                    printf("\n\t\t______________________________________\n");

                    num=0;
                    printf("\n\t\t\tAre you sure want to delete....");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\n\t\t_______________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&n);

                    if(n==1){
                        printf("\n\t\t\t Match %s vs %s deleted successfully...",isl.team1,isl.team2);
                        getch();
                    }else{
                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                        fprintf(temp,"\n Venue        : %s",isl.venue);
                        fprintf(temp,"\n Date         : %s",isl.date);
                        fprintf(temp,"\n Time         : %s",isl.time);
                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d",isl.av_tic);
                        fprintf(temp,"\n_________________________________");
                    }

                 }else{
                    fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                    fprintf(temp,"\n Venue        : %s",isl.venue);
                    fprintf(temp,"\n Date         : %s",isl.date);
                    fprintf(temp,"\n Time         : %s",isl.time);
                    fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                    fprintf(temp,"\n Available Tickets  : %d",isl.av_tic);
                    fprintf(temp,"\n_________________________________");
                }
            }

            if(found==0){
                num=0;
                printf("\n\t\t\t No Matches found for %s vs %s",i_team1,i_team2);
                printf("\n\t\t______________________________________________");
                printf("\n\t\t\t1. Search another");
                printf("\n\t\t\t2. Back");
                scanf("%d",&c);
                if(c==1){
                    goto loop1;
                }else{
                    goto hloop;
                }
                getch();

            }else{
                fclose(fp);
                fclose(temp);
                remove("isl_book.txt");
                rename("temp.txt","isl_book.txt");
                getch();
                goto hloop;
            }

    }

    getch();
    return 1;
}
