#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SEATS 50

char u_name[20]="maj",u_pwd[20]="123";
int retval;

struct travel
{
    char tp_name[20],depart_time[10],arrive_time[10],depart_place[20],arrive_place[20];
    char tp_tm_dur[15];
    int tp_no,tp_av_tic,tp_fare,seat_numbers;
};

int load_user_balance(int i_amt,int t_fare,int s_fare)
{
    int u_balance,r_balance,found=0,ub_tic,u_pay;
    char username[20],password[20],source[20];
    FILE *fp,*temp;
    fp = fopen("user.txt","r");
    temp = fopen("utemp.txt","w");

    while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
        fscanf(fp, "\n Balance   : %d",&u_balance);
        fscanf(fp, "\n book history   : %s",source);
        fscanf(fp, "\n Total tickets  : %d",&ub_tic);
        fscanf(fp, "\n Total fare     : %d",&u_pay);
        fscanf(fp, "\n______________________________");

        if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
           if(s_fare<=u_balance){

              if(u_balance<t_fare){
                found=2;
                fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                fprintf(temp, "\n Balance   : %d",u_balance);
                fprintf(temp, "\n book history   : %s",source);
                fprintf(temp, "\n Total tickets  : %d",ub_tic);
                fprintf(temp, "\n Total fare     : %d",u_pay);
                fprintf(temp, "\n______________________________");
                printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                getch();
              }else{
                  u_balance-=i_amt;
                  r_balance=u_balance;
                  fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                  fprintf(temp, "\n Balance   : %d",u_balance);
                  fprintf(temp, "\n book history   : %s",source);
                  fprintf(temp, "\n Total tickets  : %d",ub_tic);
                  fprintf(temp, "\n Total fare     : %d",u_pay);
                  fprintf(temp, "\n______________________________");
              }

            }else{
                found=1;
                fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                fprintf(temp, "\n Balance   : %d",u_balance);
                fprintf(temp, "\n book history   : %s",source);
                fprintf(temp, "\n Total tickets  : %d",ub_tic);
                fprintf(temp, "\n Total fare     : %d",u_pay);
                fprintf(temp, "\n______________________________");
                printf("\n\t\t\tInsufficient money....   Available balance  : %d",u_balance);
                getch();

            }

        }else{
            fprintf(temp, "\n username  : %s\n password  : %s", username, password);
            fprintf(temp, "\n Balance   : %d",u_balance);
            fprintf(temp, "\n book history   : %s",source);
            fprintf(temp, "\n Total tickets  : %d",ub_tic);
            fprintf(temp, "\n Total fare     : %d",u_pay);
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

int user_history(char source[20],int ub_tic, int u_pay)
{
    char username[20],password[20],i_src[20];
    int u_balance,sc_tic,sc_fare;
    FILE *fp,*temp;
    fp = fopen("user.txt","r");
    temp = fopen("us.txt","w");

    printf("%s",source);
    getch();
    while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
        fscanf(fp, "\n Balance   : %d",&u_balance);
        fscanf(fp, "\n book history   : %s",i_src);
        printf("\nhi 1st");
        getch();
        fscanf(fp, "\n Total tickets  : %d",&sc_tic);
        fscanf(fp, "\n Total fare     : %d",&sc_fare);
        fscanf(fp, "\n______________________________");


        if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                printf("\nhi 2nd");
        getch();
            fprintf(temp, "\n username  : %s\n password  : %s", username, password);
            fprintf(temp, "\n Balance   : %d",u_balance);
            fprintf(temp, "\n book history   : %s",source);
            fprintf(temp, "\n Total tickets  : %d",ub_tic);
            fprintf(temp, "\n Total fare     : %d",u_pay);
            fprintf(temp, "\n______________________________");
        }else{
            printf("\nhi last");
        getch();
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

int main()                                                                                          //Train tickect booking interface
{
    FILE *fp, *temp;
    struct travel train;
    int found = 0, c, n,m,next=0,tickets_to_book,t_fare,i_amt,num=0,u_balance,t_a_s[MAX_SEATS];
    char itr_dep[20], itr_arr[20],dum_dep[20],dum_arr[20];
    char username[20],password[20];


    tloop:
    system("cls");
    printf("\n\t\t\t**=======Train ticket bookings=======**\n");
    printf("\n\t\t\t1.Search Train ");
    printf("\n\t\t\t2.View Trains");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Search Train =======**\n");
            printf("\n\t\t\t1. Back");
            printf("\n\n\t\t\t Enter the Departure place    :");
            scanf("%s", itr_dep);

            if (strcmp(itr_dep, "1") == 0) {
                goto tloop;
            }

            printf("\n\n\t\t\t Enter the Arrival place      :");
            scanf("%s", itr_arr);

            if (strcmp(itr_arr, "1") == 0) {
                goto tloop;
            }

            strcpy(dum_dep,itr_dep);
            strcpy(dum_arr,itr_arr);

            dloop:
            if(found==4){
                strcpy(itr_dep,dum_dep);
                strcpy(itr_arr,dum_arr);
            }
            fp = fopen("train_book.txt", "r");
            temp = fopen("temp_book.txt", "w");

            if (fp == NULL || temp == NULL) {
                printf("Error opening file for reading.\n");
                getch();
                goto tloop;
            }

            while (fscanf(fp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                  train.tp_name, &train.tp_no, train.depart_time, train.arrive_time) != EOF) {
                  fscanf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                  train.depart_place, train.arrive_place, &train.tp_fare, train.tp_tm_dur, &train.tp_av_tic,&train.seat_numbers);
                  fscanf(fp, "\n_______________________________________________________________________________________");

                  num++;

                  if(strcmp(train.depart_place, itr_dep) == 0 && strcmp(train.arrive_place, itr_arr) == 0) {
                    found = 1;
                    loop7:
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
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {

                                loop5:
                                system("cls");
                                printf("\n\t\t\t**======Train Ticket Booking=======**\n");
                                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                                scanf("%d", &tickets_to_book);

                                if (tickets_to_book <= train.tp_av_tic) {

                                    t_fare=(tickets_to_book*train.tp_fare);
                                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                    printf("\n\t\t\tAre you sure want to book this bus...");
                                    getch();

                                    loop6:
                                    system("cls");
                                    printf("\n\t\t\t\t**=======Payment=======**\n");
                                    printf("\n________________________________");
                                    printf("\n| Total ticket price      : %d\t|",t_fare);
                                    printf("\n|_______________________________|");
                                    printf("\n\n\t\t\t\tEnter the amount  :");
                                    scanf("%d", &i_amt);

                                        if (i_amt == t_fare) {

                                            retval=load_user_balance(i_amt,t_fare,train.tp_fare);
                                            if(retval==1){
                                                goto loop7;
                                            }else if(retval==2){
                                                goto loop5;
                                            }
                                            train.tp_av_tic -= tickets_to_book;

                                            train.seat_numbers++;
                                            for (int i = 0; i < tickets_to_book; i++) {
                                                t_a_s[i] = train.seat_numbers;
                                                train.seat_numbers++;
                                            }
                                            train.seat_numbers--;

                                            system("cls");
                                            printf("\n\n\t\t\tTrain tickets booked successfully for %d tickets!", tickets_to_book);
                                            printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                            printf("\n\t\t_______________________________________________________            Available Balance  : %d",retval);
                                            printf("\n\t\t| Name            :  %s", u_name);
                                            printf("\n\t\t| %s Express        %s To %s", train.tp_name, train.depart_place, train.arrive_place);
                                            printf("\n\t\t| Train number    :  %d", train.tp_no);
                                            printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                                            printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", t_a_s[i]);
                                                  }
                                            printf("\n\t\t| Travel duration :  %s", train.tp_tm_dur);
                                            printf("\n\t\t| Departure Time  :  %s", train.depart_time);
                                            printf("\n\t\t| Arrival Time    :  %s", train.arrive_time);
                                            printf("\n\t\t| Total price     :  %d", t_fare);
                                            printf("\n\t\t________________________________________________________");
                                            printf("\n\n\t\t Happy Journey.........");
                                            getch();


                                            fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                                            train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                                            fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                                            train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                                            fprintf(temp, "\n_______________________________________________________________________________________");
                                            strcpy(itr_dep,"dummy");
                                            user_history("Bus",tickets_to_book,t_fare);

                                        }else{
                                            printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                            getch();
                                            goto loop6;
                                        }

                                }else{
                                    printf("\n\t\t\tNot enough tickets available....(Available tickets: %d",train.tp_av_tic );
                                    getch();
                                    goto loop5;
                                }
                    }else if(c == 2){
                        found=3;
                        strcpy(itr_dep,"dummy");
                        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                        fprintf(temp, "\n_______________________________________________________________________________________");
                    }else{
                        found=2;
                        next=1;
                        fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                        fprintf(temp, "\n_______________________________________________________________________________________");
                    }

                }else{
                    fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                            train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                            train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                    fprintf(temp, "\n_______________________________________________________________________________________");
                }

            }

            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Trains Available Next from %s to %s",dum_dep,dum_arr);
                    printf("\n\t\t_______________________________________________");
                    printf("\n\t\t\t1. Search Next Train");
                    printf("\t\t3. Previous");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_______________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                        num=0;
                        found=4;
                        fclose(fp);
                        fclose(temp);
                        remove("train_book.txt");
                        rename("temp_book.txt","train_book.txt");
                        goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Trains name found from %s to %s",itr_dep,itr_arr);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);
                }

                if(m==1){
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("train_book.txt");
                    rename("temp_book.txt","train_book.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("train_book.txt");
                    rename("temp_book.txt","train_book.txt");
                    goto tloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled.......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("train_book.txt");
                rename("temp_book.txt","train_book.txt");
                goto tloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("train_book.txt");
                rename("temp_book.txt","train_book.txt");
                goto tloop;
            }
            break;
        case 2:
            system("cls");
            //view_trains(1);
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
