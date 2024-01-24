#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define   MAX_SEATS 100

struct sports
{
    char team1[20],team2[20],venue[20],date[20],time[10];
    int t_fare,av_tic,seat_numbers;
};
int retval;
char u_name[20]="maj",u_pwd[10]="123";

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


int search_ipl()
{
    struct sports ipl;
    char i_team1[20],i_team2[20];
    int n,c,tic_book,found=0,num=0,tot_fare,i_amt,i_a_s[MAX_SEATS];
    FILE *fp,*temp;

    hloop:
    fp=fopen("ipl_book.txt","r");
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
        fclose(fp);
        fclose(temp);
        return 1;
    }
    printf("\n\t\t\tEnter the team 2 name    :");
    scanf("%s",i_team2);
    if(strcmp(i_team2,"1")==0){
        return 1;
    }

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",ipl.team1,ipl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",ipl.venue);
        fscanf(fp,"\n Date         : %s",ipl.date);
        fscanf(fp,"\n Time         : %s",ipl.time);
        fscanf(fp,"\n Ticket fare  : %d",&ipl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&ipl.av_tic,&ipl.seat_numbers);
        fscanf(fp,"\n_________________________________");

        num++;
        if(strcmp(i_team1,ipl.team1)==0 && strcmp(i_team2,ipl.team2)==0 || strcmp(i_team1,ipl.team2)==0 && strcmp(i_team2,ipl.team1)==0){
            found=1;
            loop7:
            system("cls");
            printf("\n\t\t%d.        Match   %s vs %s",num,ipl.team1,ipl.team2);
            printf("\n\t\t\t  Venue            : %s stadium",ipl.venue);
            printf("\n\t\t\t  Date             : %s",ipl.date);
            printf("\n\t\t\t  Time             : %s",ipl.time);
            printf("\n\t\t\t  Ticket fare      : %d",ipl.t_fare);
            printf("\n\t\t\t Available Tickets : %d",ipl.av_tic);
            printf("\n\t\t______________________________________");

            printf("\n\t\t\tAre sure want to book this Match....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t____________________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&n);

            if(n==1){
                loop1:
                system("cls");
                printf("\n\t\t\t**====Match Ticket Booking====**\n");
                printf("\n\t\t\tEnter the number of Tickets   :");
                scanf("%d",&tic_book);

                    if(tic_book<=ipl.av_tic){
                        tot_fare=(tic_book*ipl.t_fare);
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

                                    if(i_amt==tot_fare){
                                        retval=load_user_balance(i_amt,tot_fare,ipl.t_fare);
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop1;
                                        }
                                        ipl.av_tic -= tic_book;
                                        ipl.seat_numbers++;
                                        for (int i = 0; i < tic_book; i++) {
                                            i_a_s[i] = ipl.seat_numbers;
                                            ipl.seat_numbers++;
                                        }
                                        ipl.seat_numbers--;
                                        system("cls");
                                        printf("\n\t\t\t**=======Ticket details=======**\n");
                                        printf("\n\t\t\tPayment successfull!!...");
                                        printf("\n\t\t_______________________________________________________         Available Balance : %d",retval);
                                        printf("\n\t\t| Name            :  %s", u_name);
                                        printf("\n\t\t| Match       %s vs %s", ipl.team1,ipl.team2);
                                        printf("\n\t\t| Venue           :  %s Stadium", ipl.venue);
                                        printf("\n\t\t| Date            :  %s", ipl.date);
                                        printf("\n\t\t| Timing          :  %s", ipl.time);
                                        printf("\n\t\t| Total tickets   :  %d", tic_book);
                                        printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tic_book; i++) {
                                                       printf("%d , ", i_a_s[i]);
                                                  }
                                        printf("\n\t\t| Total fare      :  %d", tot_fare);
                                        printf("\n\t\t|________________________________________________________");
                                        printf("\n\t\t\tHave a nice day......");
                                        getch();

                                        user_history("IPL_match",tic_book,tot_fare);

                                        fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
                                        fprintf(temp,"\n Venue        : %s",ipl.venue);
                                        fprintf(temp,"\n Date         : %s",ipl.date);
                                        fprintf(temp,"\n Time         : %s",ipl.time);
                                        fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
                                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
                                        fprintf(temp,"\n_________________________________");

                                    }else{
                                        printf("\n\t\t\tPlease Enter correct amount...");
                                        getch();
                                        goto loop2;
                                    }

                            }else{
                                printf("\n\t\t\tBooking cancelled....");
                                getch();

                                fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
                                fprintf(temp,"\n Venue        : %s",ipl.venue);
                                fprintf(temp,"\n Date         : %s",ipl.date);
                                fprintf(temp,"\n Time         : %s",ipl.time);
                                fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
                                fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
                                fprintf(temp,"\n_________________________________");
                            }
                        }else{
                            printf("\n\t\t\t %d tickets Not Available  (Available tickets %d)",tic_book,ipl.av_tic);
                            getch();
                            goto loop1;
                        }

            }else{
                printf("\n\t\t\tBooking cancelled....");
                getch();
                fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
                fprintf(temp,"\n Venue        : %s",ipl.venue);
                fprintf(temp,"\n Date         : %s",ipl.date);
                fprintf(temp,"\n Time         : %s",ipl.time);
                fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
                fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
                fprintf(temp,"\n_________________________________");
            }
        }else{
            fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
            fprintf(temp,"\n Venue        : %s",ipl.venue);
            fprintf(temp,"\n Date         : %s",ipl.date);
            fprintf(temp,"\n Time         : %s",ipl.time);
            fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
            fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
            fprintf(temp,"\n_________________________________");
        }
    }

    if(found==0){
        num=0;
        printf("\n\t\t\tNo Matches found between %s vs %s ",i_team1,i_team2);
        fclose(fp);
        fclose(temp);
        getch();
        goto hloop;
    }else{
        num=0;
        fclose(fp);
        fclose(temp);
        remove("ipl_book.txt");
        rename("temp_book.txt","ipl_book.txt");
        return 1;
    }
    return 0;
}


int view_ipl(int n)                                                                             //view sports
{
    struct sports ipl;
    int num=1,found=0,retval;
    FILE *fp;
    fp=fopen("ipl_book.txt","r");
    if(fp==NULL){
        printf("error open file");
        fclose(fp);
        return 1;
    }else{

    system("cls");
    printf("\n\t\t\t**====Match Details====**\n");
    while(fscanf(fp,"\n Match  %s vs %s",ipl.team1,ipl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",ipl.venue);
        fscanf(fp,"\n Date         : %s",ipl.date);
        fscanf(fp,"\n Time         : %s",ipl.time);
        fscanf(fp,"\n Ticket fare  : %d",&ipl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&ipl.av_tic,&ipl.seat_numbers);
        fscanf(fp,"\n_________________________________");
        found=1;

        printf("\n\t\t%d.        Match   %s vs %s",num,ipl.team1,ipl.team2);
        printf("\n\t\t\t  Venue            : %s stadium",ipl.venue);
        printf("\n\t\t\t  Date             : %s",ipl.date);
        printf("\n\t\t\t  Time             : %s",ipl.time);
        printf("\n\t\t\t  Ticket fare      : %d",ipl.t_fare);
        printf("\n\t\t\t Available Tickets : %d",ipl.av_tic);
        if(n==2){
        printf("\n\t\t\t Seat Booked       : %d",ipl.seat_numbers);
        }
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

int admin_ipl()
{
    struct sports ipl;
    FILE *fp,*temp;
    int n,m,c,found=0,num=0;
    char i_team1[20],i_team2[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====IPL League=====\n");
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
    case 11:
        search_ipl();
        goto hloop;
        case 1:
            fp=fopen("ipl_book.txt","a");
            loop:
            system("cls");
            printf("\n\t\t\t=====Add IPL Matches=====\n");
            printf("\n\t\t\t1. Team 1        :");
            scanf("%s",ipl.team1);
            printf("\n\t\t\t2. Team 2        :");
            scanf("%s",ipl.team2);
            printf("\n\t\t\t3. Venue         :");
            scanf("%s",ipl.venue);
            printf("\n\t\t\t4. Date          :");
            scanf("%s",ipl.date);
            printf("\n\t\t\t5. Time          :");
            scanf("%s",ipl.time);
            printf("\n\t\t\t6. Ticket fare   :");
            scanf("%d",&ipl.t_fare);
            printf("\n\t\t\t7. Available Tickets :");
            scanf("%d",&ipl.av_tic);
            printf("\n\t\t\t8. Seats Booked :");
            scanf("%d",&ipl.seat_numbers);

            fprintf(fp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
            fprintf(fp,"\n Venue        : %s",ipl.venue);
            fprintf(fp,"\n Date         : %s",ipl.date);
            fprintf(fp,"\n Time         : %s",ipl.time);
            fprintf(fp,"\n Ticket fare  : %d",ipl.t_fare);
            fprintf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
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
            retval=view_ipl(2);
            goto hloop;
            break;
        case 3:
            loop1:
            system("cls");
            printf("\n\t\t\t=====Delete IPL Matches=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter team 1 name    :");
            scanf("%s",i_team1);

            if(strcmp(i_team1,"1")==0){
                goto hloop;
            }
            printf("\n\t\t\tEnter team 2 name    :");
            scanf("%s",i_team2);

            fp=fopen("ipl_book.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Match  %s vs %s",ipl.team1,ipl.team2)!= EOF){
                fscanf(fp,"\n Venue        : %s",ipl.venue);
                fscanf(fp,"\n Date         : %s",ipl.date);
                fscanf(fp,"\n Time         : %s",ipl.time);
                fscanf(fp,"\n Ticket fare  : %d",&ipl.t_fare);
                fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&ipl.av_tic,&ipl.seat_numbers);
                fscanf(fp,"\n_________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete IPL Matches=====\n");
                 num++;
                 if ((strcmp(i_team1, ipl.team1) == 0 && strcmp(i_team2, ipl.team2) == 0) || (strcmp(i_team1, ipl.team2) == 0 && strcmp(i_team2, ipl.team1) == 0)) {
                    found=1;
                    printf("\n\t\t%d.        Match   %s vs %s",num,ipl.team1,ipl.team2);
                    printf("\n\t\t\t  Venue       : %s stadium",ipl.venue);
                    printf("\n\t\t\t  Date        : %s",ipl.date);
                    printf("\n\t\t\t  Time        : %s",ipl.time);
                    printf("\n\t\t\t  Ticket fare  : %d",ipl.t_fare);
                    printf("\n\t\t______________________________________\n");

                    printf("\n\t\t\tAre you sure want to delete....");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\t\t\t3. Next");
                    printf("\n\t\t_______________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&n);

                    if(n==1){
                        strcpy(i_team1,"dummy");
                        printf("\n\t\t\t Match %s vs %s deleted successfully...",ipl.team1,ipl.team2);
                        getch();
                    }else if(n==2){
                        strcpy(i_team1,"dummy");
                        fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
                        fprintf(temp,"\n Venue        : %s",ipl.venue);
                        fprintf(temp,"\n Date         : %s",ipl.date);
                        fprintf(temp,"\n Time         : %s",ipl.time);
                        fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
                        fprintf(temp,"\n_________________________________");
                    }else{
                        fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
                        fprintf(temp,"\n Venue        : %s",ipl.venue);
                        fprintf(temp,"\n Date         : %s",ipl.date);
                        fprintf(temp,"\n Time         : %s",ipl.time);
                        fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
                        fprintf(temp,"\n_________________________________");
                        found=2;
                    }

                 }else{
                    fprintf(temp,"\n Match  %s vs %s",ipl.team1,ipl.team2);
                    fprintf(temp,"\n Venue        : %s",ipl.venue);
                    fprintf(temp,"\n Date         : %s",ipl.date);
                    fprintf(temp,"\n Time         : %s",ipl.time);
                    fprintf(temp,"\n Ticket fare  : %d",ipl.t_fare);
                    fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",ipl.av_tic,ipl.seat_numbers);
                    fprintf(temp,"\n_________________________________");
                }
            }

            if(found==0 || found==2){
                printf("\n\t\t\tNo Matches found as %s vs %s",i_team1,i_team2);
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
                    remove("ipl_book.txt");
                    rename("temp.txt","ipl_book.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("ipl_book.txt");
                    rename("temp.txt","ipl_book.txt");
                    goto hloop;
                }
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("ipl_book.txt");
                rename("temp.txt","ipl_book.txt");
                goto hloop;
            }
            break;
        default:
            printf("\n\t\t\tplease Enter a valid Input....");
            getch();
            goto hloop;
    }
    return 1;
}
