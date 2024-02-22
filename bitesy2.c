#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define MAX_SEATS 2000

int login_details();
int user_details();
int my_profile(),user_last_book();
int load_user_balance(),user_history(char source[20],int ub_tic, int u_pay),tour_date_load();
int train_tik_book(),bus_tik_book(),hotel_book();
int view_travel();
int tamil_movie_book(),holly_movie_book();
int view_movie();
int Events_sports_book();
int isl_tic_book(),ipl_tic_book();
int view_sports();
int india_tour_book();
int tn_tour_book();
int view_tours();
int admin();
int admin_seat_num();
int admin_train(),delete_train();
int admin_bus(),delete_bus();
int admin_hotel(),delete_hotel();
int admin_tamil_movie(),admin_holly_movie();
int admin_sports_event(),admin_isl(),admin_ipl();
int admin_ind_tour(),admin_tn_tour();
char u_name[20],u_pwd[20];
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
    int pac_price ,av_rms,rm_num;
};
void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor+bgColor*16);
}

int main()
{                                                                                                         //Main function
    int ch,u,n,m;

    loop:
        system("cls");
        printf("\t\t\t\t\tDATE :");printf(__DATE__);
        printf("\n\t\t\t\t\tTIME :");printf(__TIME__);
        printf("\n\n\n\n\t\t\t\t**=========Bookiteazy========**\n");
        printf("\n\n\t\t\t\t\t1 .LOGIN");
        printf("\n\t\t\t\t\t2. Create account");
        printf("\n\t\t\t\t\t3. Admin login");
        printf("\n\t\t\t\t_____________________________");
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
        printf("\n\t\t\t\t1. Travel                     11. My profile");
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
                printf("\n\t\t\t**=======Travel=======**\n");                                 //Travel page
                printf("\n\n\t\t\t1. Train Ticket");
                printf("\n\t\t\t2. Bus Ticket");
                printf("\n\t\t\t3. Flight Ticket");
                printf("\n\t\t\t4. Hotel Booking");
                printf("\n\t\t\t5. Vehicle Rental");
                printf("\n\t\t\t6.Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                switch (n){
                    case 1:
                        system("cls");
                        train_tik_book();
                        goto tloop;
                        break;
                    case 2:
                        system("cls");
                        bus_tik_book();
                        goto tloop;
                        break;
                    case 3:
                        system("cls");
                        printf("\n\n\n\t\t\tNo information added.....");
                        getch();
                        goto tloop;
                        break;
                    case 4:
                        system("cls");
                        hotel_book();
                        goto tloop;
                        break;
                    case 6:
                        goto hloop;
                        break;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPlease Enter a valid input...");setColor(15,0);
                        getch();
                        goto tloop;
                }
            case 2:
                mloop:
                system("cls");
                printf("\n\t\t\t**=======Movies=======**\n");                                               //Movie page
                printf("\n\t\t\t1. Tamil Movies");
                printf("\n\t\t\t2. Hindi Movies");
                printf("\n\t\t\t3. Hollywood Movies");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);

                if(n==4){
                    goto hloop;
                }
                switch(n){
                    case 1:
                        tamil_movie_book();
                        goto mloop;
                    case 3:
                        retval=holly_movie_book();
                        goto mloop;
                        break;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto mloop;
                }
                break;
            case 3:
                sloop:
                system("cls");
                printf("\n\t\t\t**=======Services=======**\n");                                                 //Services page
                printf("\n\t\t\t1.");
                printf("\n\t\t\t2.");
                printf("\n\t\t\t3.");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                if(n==4){
                    goto hloop;
                }else if(n==1 || n==2 || n==3){
                    printf("\n\t\t\tNo Information added....");
                    getch();
                    goto sloop;
                }
                switch(n){
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto sloop;
                }
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

                if(n==4){
                    goto hloop;
                }
                switch(n){
                    case 2:
                        system("cls");
                        Events_sports_book();
                        goto eloop;
                        break;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto eloop;
                }
                break;
            case 5:
                tyloop:
                system("cls");
                printf("\n\t\t\t**=======Touristry=======**\n");                                           //Touristry page
                printf("\n\t\t\t1. India");
                printf("\n\t\t\t2. Dubai");
                printf("\n\t\t\t3. Singapore");
                printf("\n\t\t\t4. Back");
                printf("\n\t\t\t___________________________");
                printf("\n\t\t\tEnter the choice :");
                scanf("%d", &n);
                if(n==4){
                    goto hloop;
                }else if(n==2 || n==3){
                    printf("\n\t\t\tNo Information added....");
                    getch();
                    goto tyloop;
                }
                switch(n){
                    case 1:
                        india_tour_book();
                        goto tyloop;
                    case 2:
                        goto tyloop;
                    default:
                        setColor(4,0);
                        printf("\n\t\t\tPleasse Enter a valid input....");setColor(15,0);
                        getch();
                        goto tyloop;
                }
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
                    setColor(2,0);
                    printf("\n\n\n\n\n\t\t\tLogout successfull....");setColor(15,0);
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
                setColor(4,0);
                printf("\n\t\t\tPlease Enter valid Input....");setColor(15,0);
                getch();
                goto hloop;
        }


    getch();
    return 0;
}

int login_details(int n)
{
    FILE *fp;
    char i_username[20], i_password[20], username[20], password[20],i_src[20],pwd[10];
    int m,found=0,u_balance=0,sc_tic,sc_fare;

    switch (n) {
    case 1:
        fp = fopen("user.txt", "r");

        loop:
        system("cls");
        setColor(12,15);
        printf("\n\t\t\t**=======LOGIN=======**");
        setColor(15,0);
        printf("\n\n\n\n\n\t\t\t1. Back");
        printf("\n\n\t\t\tEnter the user name  : ");
        scanf("%s", i_username);

        if (strcmp(i_username, "1") == 0) {
            fclose(fp);
            return 1;
        } else {
            printf("\n\t\t\tEnter the Password   : ");
            scanf("%s", i_password);
        }

        while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
            fscanf(fp, "\n Balance   : %d",&u_balance);
            fscanf(fp, "\n book history   : %s",i_src);
            fscanf(fp, "\n Total tickets  : %d",&sc_tic);
            fscanf(fp, "\n Total fare     : %d",&sc_fare);
            fscanf(fp, "\n______________________________");

            if (strcmp(username, i_username) == 0 && strcmp(password, i_password) == 0) {
                found=1;
                strcpy(u_name,username);
                strcpy(u_pwd,password);
                setColor(2,0);
                printf("\n\n\n\t\t\tLogin Successful........");
                fclose(fp);
                getch();
                setColor(15,0);
                return 2;
            }
        }

        if(found==0){
            setColor(4,0);
            printf("\n\n\t\t\tIncorrect Password or Username....");
            rewind(fp);
            getch();
            setColor(15,0);
            goto loop;
        }
        break;

    case 2:
        system("cls");
        printf("\n\t\t\t\tCreate account...\n");
        printf("\n\t1.Back                  Enter the user name  : ");
        scanf("%19s", username);
        if(strcmp(username,"1")==0){
            return 2;
        }
        printf("\n\t\t\t\tEnter the Password   : ");
        scanf("%19s", password);

        strcpy(i_src,"NILL");
        sc_tic=0;
        sc_fare=0;

        fp = fopen("user.txt", "a");

        fprintf(fp, "\n username  : %s\n password  : %s", username, password);
        fprintf(fp, "\n Balance   : %d",u_balance);
        fprintf(fp, "\n book history   : %s",i_src);
        fprintf(fp, "\n Total tickets  : %d",sc_tic);
        fprintf(fp, "\n Total fare     : %d",sc_fare);
        fprintf(fp, "\n______________________________");
        setColor(2,0);
        printf("\n\n\t\t\tAccount created successfully....");
        getch();
        fclose(fp);
        setColor(15,0);
        return 2;
    case 3:
        aloop:
        system("cls");
        strcpy(pwd,"asd");
        printf("\n\n\n\n\t\t\t**======Admin login======**\n");
        printf("\n\t\t\tEnter the password  :");
        scanf("%s",i_password);

        if(strcmp(i_password,pwd)==0){
            setColor(2,0);
            printf("\n\t\t\tLogin successfull...");
            getch();
            setColor(15,0);
            return 1;
        }else{
            setColor(4,0);
            printf("\n\n\t\t\tIncorrect password...");
            setColor(15,0);
            printf("\n\n\t\t\t1. Retry");
            printf("\n\t\t\t2. Back");
            printf("\n\t\t_________________________________");
            printf("\n\t\t\tEnter the choice   :");
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
    int n,m,c,found=0,u_balance,num=0,sc_tic,sc_fare;
    char i_uname[10],username[10],password[10],i_src[20];
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
            while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
                fscanf(fp, "\n Balance   : %d",&u_balance);
                fscanf(fp, "\n book history   : %s",i_src);
                fscanf(fp, "\n Total tickets  : %d",&sc_tic);
                fscanf(fp, "\n Total fare     : %d",&sc_fare);
                fscanf(fp, "\n______________________________");


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
             while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
                fscanf(fp, "\n Balance   : %d",&u_balance);
                fscanf(fp, "\n book history   : %s",i_src);
                fscanf(fp, "\n Total tickets  : %d",&sc_tic);
                fscanf(fp, "\n Total fare     : %d",&sc_fare);
                fscanf(fp, "\n______________________________");

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
                        fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                        fprintf(temp, "\n Balance   : %d",u_balance);
                        fprintf(temp, "\n book history   : %s",i_src);
                        fprintf(temp, "\n Total tickets  : %d",sc_tic);
                        fprintf(temp, "\n Total fare     : %d",sc_fare);
                        fprintf(temp, "\n______________________________");
                        strcpy(i_uname,"dummy");
                    }else if(m==3){
                        found=3;
                        fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                        fprintf(temp, "\n Balance   : %d",u_balance);
                        fprintf(temp, "\n book history   : %s",i_src);
                        fprintf(temp, "\n Total tickets  : %d",sc_tic);
                        fprintf(temp, "\n Total fare     : %d",sc_fare);
                        fprintf(temp, "\n______________________________");
                    }else {
                        fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                        fprintf(temp, "\n Balance   : %d",u_balance);
                        fprintf(temp, "\n book history   : %s",i_src);
                        fprintf(temp, "\n Total tickets  : %d",sc_tic);
                        fprintf(temp, "\n Total fare     : %d",sc_fare);
                        fprintf(temp, "\n______________________________");
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
    int n,m,i_amt,u_balance,sc_tic,sc_fare;
    char username[10],password[20],i_src[20];
    FILE *fp,*temp;

    hloop:
    system("cls");
    printf("\n\t\t\t**=======My Profile Info=======**\n");
    printf("\n\t\t\t\tUsername   : %s",u_name);
    printf("\n\t\t\t\tPasword    : %s",u_pwd);
    printf("\n\n\t\t\t\t1. My Balance");
    printf("\n\n\t\t\t\t2. My Last booking");
    printf("\n\n\t\t\t\t3. Back");
    printf("\n\t\t\t____________________________");
    printf("\n\n\t\t\t\tEnter the choice    :");
    scanf("%d",&m);

    if(m==1){
        loop:
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
            while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
                fscanf(fp, "\n Balance   : %d",&u_balance);
                fscanf(fp, "\n book history   : %s",i_src);
                fscanf(fp, "\n Total tickets  : %d",&sc_tic);
                fscanf(fp, "\n Total fare     : %d",&sc_fare);
                fscanf(fp, "\n______________________________");

                if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
                    printf("\n\t\t\tUsername   : %s",u_name);
                    printf("\n\t\t\tPasword    : %s",u_pwd);
                    printf("\n\n\t\t\tAdd Money  :");
                    scanf("%d",&i_amt);
                    u_balance += i_amt;

                    fprintf(temp, "\n username  : %s\n password  : %s", username, password);
                    fprintf(temp, "\n Balance   : %d",u_balance);
                    fprintf(temp, "\n book history   : %s",i_src);
                    fprintf(temp, "\n Total tickets  : %d",sc_tic);
                    fprintf(temp, "\n Total fare     : %d",sc_fare);
                    fprintf(temp, "\n______________________________");
                    setColor(2,0);
                    printf("\n\t\t\tMoney added successfully...     Available balance  : %d",u_balance);
                    setColor(15,0);
                    getch();

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
            rename("temp.txt","user.txt");
            goto loop;

        }else if(n==2){
            fp=fopen("user.txt","r");

            system("cls");
            printf("\n\t\t\t**=======My Balance=======**\n");
            while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
                fscanf(fp, "\n Balance   : %d",&u_balance);
                fscanf(fp, "\n book history   : %s",i_src);
                fscanf(fp, "\n Total tickets  : %d",&sc_tic);
                fscanf(fp, "\n Total fare     : %d",&sc_fare);
                fscanf(fp, "\n______________________________");

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
            goto loop;
        }else if(n==3){
            goto hloop;
        }else{
            printf("\n\t\t\tPlease Enter a valid input...");
            getch();
            goto loop;
        }
        goto hloop;

    }else if(m==2){
        user_last_book();
        goto hloop;
    }else{
        return 1;
    }

    return 1;
}

int user_last_book()
{
    int u_balance,sc_tic,sc_fare;
    char username[20],password[20],i_src[20];
    FILE *fp,*temp;
    fp = fopen("user.txt","r");

    system("cls");
    printf("\n\n\n\t\t\t**=======My Last Booking======**");
    while (fscanf(fp, "\n username  : %s\n password  : %s", username, password)!=EOF){
        fscanf(fp, "\n Balance   : %d",&u_balance);
        fscanf(fp, "\n book history   : %s",i_src);
        fscanf(fp, "\n Total tickets  : %d",&sc_tic);
        fscanf(fp, "\n Total fare     : %d",&sc_fare);
        fscanf(fp, "\n______________________________");

        if(strcmp(username,u_name)==0 && strcmp(password,u_pwd)==0){
            printf("\n\n\n\t\t\t %s Ticket Booked",i_src);
            printf("\n\n\t\t\t Total tickets : %d",sc_tic);
            printf("\n\n\t\t\t Total fare    : %d",sc_fare);
            printf("\n\t\t_______________________________________________");
            printf("\n\t\tPress Enter to back.....");
            getch();
        }
    }
    fclose(fp);
    return 1;
}

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

int tour_date_load(char str[11],int inc_day) {

    int ex_dd, ex_mm, ex_yy;

    ex_dd = atoi(str);
    ex_mm = atoi(str + 3);
    ex_yy = atoi(str + 6);

    ex_dd += inc_day;

    while (ex_dd > 28 && ex_mm == 2) {
        if ((ex_yy % 4 == 0 && ex_yy % 100 != 0) || ex_yy % 400 == 0) {
            ex_dd -= 29;
            ex_mm++;
        } else {
            ex_dd -= 28;
            ex_mm++;
        }
    }
    while ((ex_mm == 4 || ex_mm == 6 || ex_mm == 9 || ex_mm == 11) && ex_dd > 30) {
        ex_dd -= 30;
        ex_mm++;
    }
    while (ex_dd > 31) {
        ex_dd -= 31;
        ex_mm++;
    }

    if (ex_mm > 12) {
        ex_mm -= 12;
        ex_yy++;
    }

    printf("\n\t\t| Trip Ending date   : %d/%d/%d", ex_dd,ex_mm,ex_yy);

    return 0;
}


int train_tik_book()                                                                      //**********TRAIN TICKET BOOK***********
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

                                            user_history("Train",tickets_to_book,t_fare);

                                            fprintf(temp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                                            train.tp_name, train.tp_no, train.depart_time, train.arrive_time);
                                            fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                                            train.depart_place, train.arrive_place, train.tp_fare, train.tp_tm_dur, train.tp_av_tic,train.seat_numbers);
                                            fprintf(temp, "\n_______________________________________________________________________________________");
                                            strcpy(itr_dep,"dummy");

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
            view_travel(1,1);
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

int bus_tik_book()                                                                        //**********BUS TICKET BOOK***********
{
    FILE *fp, *temp,*ub, *utemp;
    struct travel bus;
    int found = 0, c, m,n, tickets_to_book,t_fare,next,i_amt,num=0,b_a_s[MAX_SEATS];
    char itr_dep[20], itr_arr[20];
    char dum_dep[20],dum_arr[20];

    tloop:
    system("cls");
    printf("\n\t\t\t**=======bus ticket bookings=======**\n");
    printf("\n\t\t\t1.Search bus ");
    printf("\n\t\t\t2.View bus");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop:
            system("cls");
            printf("\n\t\t\t**=======Search bus =======**\n");
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

            fp = fopen("bus_book.txt", "r");
            temp = fopen("temp_book.txt", "w");

            if (fp == NULL) {
                printf("Error opening file for reading.\n");
                getch();
                goto tloop;
            }

            while (fscanf(fp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                          bus.tp_name, &bus.tp_no, bus.depart_time, bus.arrive_time) != EOF) {
                fscanf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                       bus.depart_place, bus.arrive_place, &bus.tp_fare, bus.tp_tm_dur, &bus.tp_av_tic,&bus.seat_numbers);
                fscanf(fp, "\n_______________________________________________________________________________________");

                num++;
                if (strcmp(bus.depart_place, itr_dep) == 0 && strcmp(bus.arrive_place, itr_arr) == 0) {
                    found = 1;
                    loop7:
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
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {
                        loop5:
                            system("cls");
                            printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                            scanf("%d", &tickets_to_book);

                            if (tickets_to_book <= bus.tp_av_tic) {
                                t_fare=(tickets_to_book*bus.tp_fare);
                                printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                printf("\n\t\t\tAre you sure want to book this Bus...");
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
                                        retval=load_user_balance(i_amt,t_fare,bus.tp_fare);
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop5;
                                        }
                                        bus.tp_av_tic -= tickets_to_book;

                                        if(bus.seat_numbers>=60){
                                            bus.seat_numbers=0;
                                        }
                                        bus.seat_numbers++;
                                        for (int i = 0; i < tickets_to_book; i++) {
                                            b_a_s[i] = bus.seat_numbers;
                                            bus.seat_numbers++;
                                        }
                                        bus.seat_numbers--;
                                        system("cls");
                                        printf("\n\n\t\t\tbus tickets booked successfully for %d tickets!", tickets_to_book);
                                        printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                        printf("\n\t\t_______________________________________________________             Available Balance : %d",retval);
                                        printf("\n\t\t| Name            :  %s", u_name);
                                        printf("\n\t\t| %s Express        %s To %s", bus.tp_name, bus.depart_place, bus.arrive_place);
                                        printf("\n\t\t| Bus number      :  %d", bus.tp_no);
                                        printf("\n\t\t| Tickets booked  :  %d", tickets_to_book);
                                        printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", b_a_s[i]);
                                                  }
                                        printf("\n\t\t| Travel duration :  %s", bus.tp_tm_dur);
                                        printf("\n\t\t| Departure Time  :  %s", bus.depart_time);
                                        printf("\n\t\t| Arrival Time    :  %s", bus.arrive_time);
                                        printf("\n\t\t| Total price     :  %d", t_fare);
                                        printf("\n\t\t________________________________________________________");
                                        printf("\n\t\t Happy Journey.........");
                                        getch();

                                        user_history("Bus",tickets_to_book,t_fare);

                                        fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                                            bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                                        fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                                            bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                                        fprintf(temp, "\n_______________________________________________________________________________________");
                                        strcpy(itr_dep,"dummy");

                                    }else{
                                        printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                        getch();
                                        goto loop6;
                                    }

                            }else{
                                printf("\n\t\t\tNot enough tickets available. Available tickets: %d", bus.tp_av_tic);
                                getch();
                                goto loop5;
                            }
                } else if (c == 2) {
                    found=3;
                    strcpy(itr_dep,"dummy");
                    fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                    fprintf(temp, "\n_______________________________________________________________________________________");
                }else{
                    found=2;
                    next=1;
                    fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                    fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                    fprintf(temp, "\n_______________________________________________________________________________________");
                }
            }else{
                fprintf(temp, "\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                bus.tp_name, bus.tp_no, bus.depart_time, bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                bus.depart_place, bus.arrive_place, bus.tp_fare, bus.tp_tm_dur, bus.tp_av_tic,bus.seat_numbers);
                fprintf(temp, "\n_______________________________________________________________________________________");
             }

            }

            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Bus Avaiable Next from %s to %s",dum_dep,dum_arr);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\t\t3. Previous");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                       num=0;
                       found=4;
                       fclose(fp);
                       fclose(temp);
                       remove("bus_book.txt");
                       rename("temp_book.txt","bus_book.txt");
                       goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Bus name found from %s to %s",itr_dep,itr_arr);
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
                    remove("bus_book.txt");
                    rename("temp_book.txt","bus_book.txt");
                    goto loop;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("bus_book.txt");
                    rename("temp_book.txt","bus_book.txt");
                    goto tloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("bus_book.txt");
                rename("temp_book.txt","bus_book.txt");
                goto tloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("bus_book.txt");
                rename("temp_book.txt","bus_book.txt");
                goto tloop;
            }
            break;
        case 2:
            system("cls");
            view_travel(1,2);
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

int hotel_book()                                                                          //**********HOTEL BOOK***********
{
    int n;

    hloop:
    system("cls");
    printf("\n\t\t\t**=======Hotel bookings=======**\n");
    printf("\n\t\t\t1.Search Hotel ");
    printf("\n\t\t\t2.View Hotels");
    printf("\n\t\t\t3.Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice :");
    scanf("%d",&n);

    if(n==3){
        return 1;
    }
    switch(n)
    {
        case 2:
            view_travel(1,3);
            goto hloop;
        default:
            printf("\n\t\t\tPleae Enter a valid input....");
            getch();
            goto hloop;
    }
}

int view_travel(int n,int m)
{
    FILE *fp;
    struct travel train;
    struct travel bus;
    struct travel hotel;
    int num=0;

    switch(m){
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
                printf("\n\t\t\tTrain ID          : %d", num);
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
            return 0;

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
                printf("\n\t\t\tTrain ID          : %d", num);
                printf("\n\t\t\tbus name          : %s Travels", bus.tp_name);
                printf("\n\t\t\tbus number        : TN-%d", bus.tp_no);
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

int tamil_movie_book()                                                                     //**********TAMIL TICKET BOOK***********
{
    struct movie tamil;
    FILE *fp,*temp,*ub,*utemp;
    int n,c,m,tickets_to_book,t_fare,found=0,num=0,next=0,u_balance,i_amt,tm_a_s[MAX_SEATS];
    char i_mov_name[20],username[20],password[20],dum_mov[20];

    hloop:
    system("cls");
    printf("\n\t\t\t**=======Tamil Movies Booking=======**\n");
    printf("\n\t\t\t1. Search movies");
    printf("\n\t\t\t2. View movies");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t________________________________________");
    printf("\n\t\t\tEnter the choice  :");
    scanf("%d", &n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Search Tamil Movies=======**\n");
            printf("\n\t\t1. Back ");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                fclose(fp);
                fclose(temp);
                goto hloop;
            }

            dloop:
            strcpy(dum_mov,i_mov_name);
            if(found==4){
                strcpy(i_mov_name,dum_mov);
            }

            fp=fopen("tamil_movie.txt","r");
            temp=fopen("temp_book.txt","w");

            if(fp==NULL || temp==NULL){
                printf("\n\t\t\tError openning file....");
                getch();
                goto hloop;
            }

            system("cls");
            printf("\n\t\t\t**=======Tamil Movies=======**\n");
            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&tamil.mov_t_fare,&tamil.mov_av_tic,&tamil.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                num++;
                if(strcmp(i_mov_name,tamil.mov_name)==0){
                    found=1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**=======Tamil Movies=======**\n");
                    printf("\n\t\t%d.      Movie name         : %s",num,tamil.mov_name);
                    printf("\n\t\t\tTheater name       : %s",tamil.mov_theater);
                    printf("\n\t\t\tDate               : %s",tamil.mov_date);
                    printf("\n\t\t\tTiming             : %s",tamil.mov_time);
                    printf("\n\t\t\tTicket price       : %d",tamil.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",tamil.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\t1. Next");
                    printf("\t\t\t\t3. Book this movie");
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {
                            loop5:
                                system("cls");
                                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                                scanf("%d", &tickets_to_book);

                                if (tickets_to_book <= tamil.mov_av_tic) {
                                    t_fare=(tickets_to_book*tamil.mov_t_fare);
                                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                    printf("\n\t\t\tAre you sure want to book this movie...");
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
                                        retval=load_user_balance(i_amt,t_fare,tamil.mov_t_fare);
                                        system("cls");
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop5;
                                        }
                                          tamil.mov_av_tic -= tickets_to_book;

                                          tamil.seat_numbers++;
                                          for (int i = 0; i < tickets_to_book; i++) {
                                                tm_a_s[i] = tamil.seat_numbers;
                                                tamil.seat_numbers++;
                                          }
                                          tamil.seat_numbers--;
                                          printf("\n\n\t\t\tbus tickets booked successfully for %d tickets!", tickets_to_book);
                                          printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                          printf("\n\t\t_______________________________________________________             Available Balance : %d",retval);
                                          printf("\n\t\t| Name            : %s", u_name);
                                          printf("\n\t\t| Movie           : %s", tamil.mov_name);
                                          printf("\n\t\t| Theater name    : %s", tamil.mov_theater);
                                          printf("\n\t\t| Tickets booked  : %d", tickets_to_book);
                                          printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", tm_a_s[i]);
                                                  }
                                          printf("\n\t\t| Date            : %s", tamil.mov_date);
                                          printf("\n\t\t| Time            : %s", tamil.mov_time);
                                          printf("\n\t\t| Total fare      : %d", t_fare);
                                          printf("\n\t\t________________________________________________________");
                                          printf("\n\n\t\t Enjoy Your Movie.........");
                                          getch();

                                          user_history("Tamil_movie",tickets_to_book,t_fare);

                                          fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                                          fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                                          fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                                          fprintf(temp,"\n_____________________________________________________");
                                          strcpy(i_mov_name,"dummy");

                                       }else{
                                          printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                          getch();
                                          goto loop6;
                                      }
                                }else{
                                    printf("\n\t\t\tNot enough tickets available. Available tickets: %d", tamil.mov_av_tic);
                                    getch();
                                    goto loop5;
                                }

                    } else if (c == 2) {
                            found=3;
                            strcpy(i_mov_name,"dummy");
                            fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                            fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                            fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                            fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        next=1;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }

                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Movies Available Next as %s ",dum_mov);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\t\t3. Previuos");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                        num=0;
                        found=4;
                        fclose(fp);
                        fclose(temp);
                        remove("tamil_movie.txt");
                        rename("temp_book.txt","tamil_movie.txt");
                        goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Movies found as %s ",i_mov_name);
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
                    remove("tamil_movie.txt");
                    rename("temp_book.txt","tamil_movie.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp_book.txt","tamil_movie.txt");
                    goto hloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tamil_movie.txt");
                rename("temp_book.txt","tamil_movie.txt");
                goto hloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tamil_movie.txt");
                rename("temp_book.txt","tamil_movie.txt");
                goto hloop;
            }
            break;
        case 2:
            retval=view_movie(1,1);
            if(retval==1){
                goto hloop;
            }
        default:
            printf("\n\t\t\tplease Enter a valid input...");
            getch();
            goto hloop;
    }
    return 1;
}

int holly_movie_book()                                                                     //**********HOLLYWOOD TICKET BOOK***********
{
    struct movie holly;
    FILE *fp,*temp;
    int n,c,m,tickets_to_book,t_fare,found=0,num=0,next=0,i_amt,tm_a_s[MAX_SEATS];
    char i_mov_name[20],dum_mov[20];

    hloop:
    system("cls");
    printf("\n\t\t\t**=======Hollywood Movies Booking=======**\n");
    printf("\n\t\t\t1. Search movies");
    printf("\n\t\t\t2. View movies");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t________________________________________");
    printf("\n\t\t\tEnter the choice  :");
    scanf("%d", &n);

    if(n==3){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            system("cls");
            printf("\n\t\t\t**=======Search Hollywood Movies=======**\n");
            printf("\n\t\t1. Back ");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                fclose(fp);
                fclose(temp);
                goto hloop;
            }

            dloop:
            strcpy(dum_mov,i_mov_name);
            if(found==4){
                strcpy(i_mov_name,dum_mov);
            }

            fp=fopen("holly_movie.txt","r");
            temp=fopen("temp_book.txt","w");

            if(fp==NULL || temp==NULL){
                printf("\n\t\t\tError openning file....");
                getch();
                goto hloop;
            }

            system("cls");
            printf("\n\t\t\t**=======Hollywood Movies=======**\n");
            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&holly.mov_t_fare,&holly.mov_av_tic,&holly.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                num++;
                if(strcmp(i_mov_name,holly.mov_name)==0){
                    found=1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**=======Hollywood Movies=======**\n");
                    printf("\n\t\t%d.      Movie name         : %s",num,holly.mov_name);
                    printf("\n\t\t\tTheater name       : %s",holly.mov_theater);
                    printf("\n\t\t\tDate               : %s",holly.mov_date);
                    printf("\n\t\t\tTiming             : %s",holly.mov_time);
                    printf("\n\t\t\tTicket price       : %d",holly.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",holly.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\t1. Next");
                    printf("\t\t\t\t3. Book this movie");
                    printf("\n\t\t\t2. No");
                    printf("\n\n\t\t\tEnter the choice :");
                    scanf("%d", &c);

                    if (c == 3) {
                            loop5:
                                system("cls");
                                printf("\n\n\n\t\t\tEnter the number of tickets to book: ");
                                scanf("%d", &tickets_to_book);

                                if (tickets_to_book <= holly.mov_av_tic) {
                                    t_fare=(tickets_to_book*holly.mov_t_fare);
                                    printf("\n\t\t\t Total ticket price      : %d",t_fare);
                                    printf("\n\t\t\tAre you sure want to book this movie...");
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
                                        retval=load_user_balance(i_amt,t_fare,holly.mov_t_fare);
                                        system("cls");
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop5;
                                        }
                                          holly.mov_av_tic -= tickets_to_book;

                                          holly.seat_numbers++;
                                          for (int i = 0; i < tickets_to_book; i++) {
                                                tm_a_s[i] = holly.seat_numbers;
                                                holly.seat_numbers++;
                                          }
                                          holly.seat_numbers--;
                                          printf("\n\n\t\t\tMovie tickets booked successfully for %d tickets!", tickets_to_book);
                                          printf("\n\n\t\t\t**=======Ticket details=======**\n");
                                          printf("\n\t\t_______________________________________________________             Available Balance : %d",retval);
                                          printf("\n\t\t| Name            : %s", u_name);
                                          printf("\n\t\t| Movie           : %s", holly.mov_name);
                                          printf("\n\t\t| Theater name    : %s", holly.mov_theater);
                                          printf("\n\t\t| Tickets booked  : %d", tickets_to_book);
                                          printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tickets_to_book; i++) {
                                                       printf("%d , ", tm_a_s[i]);
                                                  }
                                          printf("\n\t\t| Date            : %s", holly.mov_date);
                                          printf("\n\t\t| Time            : %s", holly.mov_time);
                                          printf("\n\t\t| Total fare      : %d", t_fare);
                                          printf("\n\t\t________________________________________________________");
                                          printf("\n\n\t\t Enjoy Your Movie.........");
                                          getch();

                                          user_history("Hollywood_movie",tickets_to_book,t_fare);

                                          fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                                          fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                                          fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                                          fprintf(temp,"\n_____________________________________________________");
                                          strcpy(i_mov_name,"dummy");

                                       }else{
                                          printf("\n\t\t\tEntered amount does not match. Please enter the correct amount %d", t_fare);
                                          getch();
                                          goto loop6;
                                      }
                                }else{
                                    printf("\n\t\t\tNot enough tickets available. Available tickets: %d", holly.mov_av_tic);
                                    getch();
                                    goto loop5;
                                }
                    } else if (c == 2) {
                            found=3;
                            strcpy(i_mov_name,"dummy");
                            fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                            fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                            fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                            fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        next=1;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }

                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                if(next==1){
                    printf("\n\t\t\tNo Movies Available Next as %s ",dum_mov);
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\t1. Search again");
                    printf("\t\t3. Previuos");
                    printf("\n\t\t\t2. Back");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==3){
                        num=0;
                        found=4;
                        fclose(fp);
                        fclose(temp);
                        remove("holly_movie.txt");
                        rename("temp_book.txt","holly_movie.txt");
                        goto dloop;
                    }
                }else{
                    printf("\n\t\t\tNo Movies found as %s ",i_mov_name);
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
                    remove("holly_movie.txt");
                    rename("temp_book.txt","holly_movie.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp_book.txt","holly_movie.txt");
                    goto hloop;
                }
            }else if(found==3){
                printf("\n\t\t\tBooking cancelled......");
                getch();
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("holly_movie.txt");
                rename("temp_book.txt","holly_movie.txt");
                goto hloop;
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("holly_movie.txt");
                rename("temp_book.txt","holly_movie.txt");
                goto hloop;
            }
            break;
        case 2:
            retval=view_movie(1,2);
            if(retval==1){
                goto hloop;
            }
        default:
            printf("\n\t\t\tplease Enter a valid input...");
            getch();
            goto hloop;
    }
    return 1;
}

int view_movie(int n,int m)                                                                 //**********VIEW MOVIE***********
{
    FILE *fp;
    struct movie tamil;
    struct movie holly;
    int num=0;

    switch(m){
        case 1:                                                         //case tamil
            fp=fopen("tamil_movie.txt","r");

            system("cls");
            printf("\n\t\t\t**=======Tamil Movies=======**\n");
            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&tamil.mov_t_fare,&tamil.mov_av_tic,&tamil.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                printf("\n\t\t\tMovie name         : %s",tamil.mov_name);
                printf("\n\t\t\tTheater name       : %s",tamil.mov_theater);
                printf("\n\t\t\tDate               : %s",tamil.mov_date);
                printf("\n\t\t\tTiming             : %s",tamil.mov_time);
                printf("\n\t\t\tTicket price       : %d",tamil.mov_t_fare);
                printf("\n\t\t\tAvailable tickets  : %d",tamil.mov_av_tic);
                if(n==2){
                    printf("\n\t\t\tSeats Booked      : %d", tamil.seat_numbers);
                }
                printf("\n\t\t_____________________________________________");
            }
            fclose(fp);
            printf("\n\t\t\tpress Enter to go back.....");
            getch();
            return 1;
        case 2:                                                                //case hollywood
            fp=fopen("holly_movie.txt","r");

            system("cls");
            printf("\n\t\t\t**=======Hollywood Movies=======**\n");
            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&holly.mov_t_fare,&holly.mov_av_tic,&holly.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                printf("\n\t\t\tMovie name         : %s",holly.mov_name);
                printf("\n\t\t\tTheater name       : %s",holly.mov_theater);
                printf("\n\t\t\tDate               : %s",holly.mov_date);
                printf("\n\t\t\tTiming             : %s",holly.mov_time);
                printf("\n\t\t\tTicket price       : %d",holly.mov_t_fare);
                printf("\n\t\t\tAvailable tickets  : %d",holly.mov_av_tic);
                if(n==2){
                    printf("\n\t\t\tSeats Booked      : %d", holly.seat_numbers);
                }
                printf("\n\t\t_____________________________________________");
            }
            fclose(fp);
            printf("\n\t\t\tpress Enter to go back.....");
            getch();
            return 1;
    }
}

int Events_sports_book()                                                                    //**********EVENT SPORTS BOOK***********
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
                    retval=isl_tic_book();
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 11:
                    retval=view_sports(1,1);
                    if(retval==1){
                        goto loop1;
                    }
                    break;
                case 2:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop1;
                    break;
                case 22:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop1;
                    break;
                default:
                    printf("\n\t\t\tPlease Enter a valid input...");
                    getch();
                    goto loop1;
            }
            break;
        case 2:
            loop2:
            system("cls");
            printf("\n\t\t\t**=======Sports Events=======**\n");
            printf("\n\t\t\t1. IPL league                   11. View Matches");
            printf("\n\t\t\t2. BBL league                   22. View Matches");
            printf("\n\t\t\t2. ICC Matches                  33. View Matches");
            printf("\n\t\t\t4. Back");
            printf("\n\t\t\t__________________________");
            printf("\n\t\t\tEnter the choice   :");
            scanf("%d",&m);
            if(m==4){
                goto hloop;
            }

            switch(m){
                case 1:
                    retval=ipl_tic_book();
                    goto loop2;
                    break;
                case 11:
                    retval=view_sports(1,2);
                    goto loop2;
                    break;
                case 2:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop2;
                    break;
                case 22:
                    system("cls");
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop2;
                    break;
                case 3:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop2;
                    break;
                case 33:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop2;
                    break;
                default:
                    printf("\n\t\t\tPlease Enter a valid input...");
                    getch();
                    goto loop2;
            }
            break;
        case 3:
            system("cls");
            printf("\n\t\t\tNo information....");
            getch();
            goto hloop;
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

int isl_tic_book()                                                                          //**********ISL TICKET BOOK***********
{
    struct sports isl;
    char i_team1[20],i_team2[20];
    int n,c,tic_book,found=0,num=0,tot_fare,i_amt,i_a_s[MAX_SEATS];
    FILE *fp,*temp;

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
    while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!=EOF){
        fscanf(fp,"\n Venue        : %s",isl.venue);
        fscanf(fp,"\n Date         : %s",isl.date);
        fscanf(fp,"\n Time         : %s",isl.time);
        fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
        fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&isl.av_tic,&isl.seat_numbers);
        fscanf(fp,"\n_________________________________");

        num++;
        if(strcmp(i_team1,isl.team1)==0 && strcmp(i_team2,isl.team2)==0 || strcmp(i_team1,isl.team2)==0 && strcmp(i_team2,isl.team1)==0){
            found=1;
            loop7:
            system("cls");
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

                                    if(i_amt==tot_fare){
                                        retval=load_user_balance(i_amt,tot_fare,isl.t_fare);
                                        if(retval==1){
                                           goto loop7;
                                        }else if(retval==2){
                                            goto loop1;
                                        }
                                        isl.av_tic -= tic_book;
                                        isl.seat_numbers++;
                                        for (int i = 0; i < tic_book; i++) {
                                            i_a_s[i] = isl.seat_numbers;
                                            isl.seat_numbers++;
                                        }
                                        isl.seat_numbers--;
                                        system("cls");
                                        printf("\n\t\t\t**=======Ticket details=======**\n");
                                        printf("\n\t\t\tPayment successfull!!...");
                                        printf("\n\t\t_______________________________________________________         Available Balance : %d",retval);
                                        printf("\n\t\t| Name            :  %s", u_name);
                                        printf("\n\t\t| Match       %s vs %s", isl.team1,isl.team2);
                                        printf("\n\t\t| Venue           :  %s Stadium", isl.venue);
                                        printf("\n\t\t| Date            :  %s", isl.date);
                                        printf("\n\t\t| Timing          :  %s", isl.time);
                                        printf("\n\t\t| Total tickets   :  %d", tic_book);
                                        printf("\n\t\t| Seat Numbers    :  ");
                                                  for (int i = 0; i < tic_book; i++) {
                                                       printf("%d , ", i_a_s[i]);
                                                  }
                                        printf("\n\t\t| Total fare      :  %d", tot_fare);
                                        printf("\n\t\t|________________________________________________________");
                                        printf("\n\t\t\tHave a nice day......");
                                        getch();

                                        user_history("Isl_match",tic_book,tot_fare);

                                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                                        fprintf(temp,"\n Venue        : %s",isl.venue);
                                        fprintf(temp,"\n Date         : %s",isl.date);
                                        fprintf(temp,"\n Time         : %s",isl.time);
                                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                                        fprintf(temp,"\n_________________________________");

                                    }else{
                                        printf("\n\t\t\tPlease Enter correct amount...");
                                        getch();
                                        goto loop2;
                                    }

                            }else{
                                printf("\n\t\t\tBooking cancelled....");
                                getch();

                                fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                                fprintf(temp,"\n Venue        : %s",isl.venue);
                                fprintf(temp,"\n Date         : %s",isl.date);
                                fprintf(temp,"\n Time         : %s",isl.time);
                                fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                                fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                                fprintf(temp,"\n_________________________________");
                            }
                        }else{
                            printf("\n\t\t\t %d tickets Not Available  (Available tickets %d)",tic_book,isl.av_tic);
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
                fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                fprintf(temp,"\n_________________________________");
            }
        }else{
            fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
            fprintf(temp,"\n Venue        : %s",isl.venue);
            fprintf(temp,"\n Date         : %s",isl.date);
            fprintf(temp,"\n Time         : %s",isl.time);
            fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
            fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
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

int ipl_tic_book()                                                                      //**********IPL TICKET BOOK***********
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

int view_sports(int n,int m)                                                             //**********VIEW SPORTS***********
{
    struct sports isl;
    struct sports ipl;
    int num=1,found=0,retval;
    FILE *fp;

    switch(m){
        case 1:                                                         //case Isl
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
                    fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&isl.av_tic,&isl.seat_numbers);
                    fscanf(fp,"\n_________________________________");
                    found=1;

                    printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
                    printf("\n\t\t\t  Venue            : %s stadium",isl.venue);
                    printf("\n\t\t\t  Date             : %s",isl.date);
                    printf("\n\t\t\t  Time             : %s",isl.time);
                    printf("\n\t\t\t  Ticket fare      : %d",isl.t_fare);
                    printf("\n\t\t\t Available Tickets : %d",isl.av_tic);
                    if(n==2){
                        printf("\n\t\t\t Seat Booked       : %d",isl.seat_numbers);
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

        case 2:                                                                //case Ipl
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
    }
}

int india_tour_book()                                                                   //**********INDIA TOUR BOOK***********
{
    int n;

    hloop:
    system("cls");
    printf("\n\t\t\t**======= India =======**\n");
    printf("\n\t\t\t1. Tamilnadu");
    printf("\n\t\t\t2. Kerala");
    printf("\n\t\t\t3. Goa");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t____________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);
    if(n==4){
        return 0;
    }
    switch(n)
    {
        case 1:
            tn_tour_book();
            goto hloop;
        default:
            printf("\n\t\t\tPlease Enter a valid input.....");
            goto hloop;
    }

}

int tn_tour_book()                                                                        //**********TN TOUR BOOK***********
{
    struct tours tn;
    char i_place[20],st_date[15];
    int n,c,tic_book,found=0,num=0,tot_fare,trip_days,i_amt,i_a_s[MAX_SEATS];
    int f_rooms,rooms,ex_dd,ex_mm,ex_yy;
    FILE *fp,*temp;

    mloop:
    system("cls");
    printf("\n\t\t\t**======Tamilnadu tours=====**\n");
    printf("\n\t\t\t1. Search Places");
    printf("\n\t\t\t2. View Places");
    printf("\n\t\t\t3. Back");
    printf("\n\t\t_______________________________________");
    printf("\n\t\t\tEnter the choice  :");
    scanf("%d",&n);

    if(n==3){
        return 0;
    }
    switch(n)
    {
        case 1:
            hloop:
            fp=fopen("tn_tour.txt","r");
            temp=fopen("temp_book.txt","w");

            if(fp==NULL || temp == NULL){
                printf("error openning file...");
                getch();
                return 1;
            }
            system("cls");
            printf("\n\t\t\t**======Search Places=====**\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter the Place name    :");
            scanf("%s",i_place);

            if(strcmp(i_place,"1")==0){
                fclose(fp);
                fclose(temp);
                return 1;
            }

            system("cls");
            printf("\n\t\t\t**====Tour Details====**\n");
            while(fscanf(fp,"\n Place        : %s",tn.tour_place)!=EOF){
                fscanf(fp,"\n Hotel          : %s",tn.hotel_name);
                fscanf(fp,"\n Package type   : %s",tn.pac_type);
                fscanf(fp,"\n Package price  : %d",&tn.pac_price);
                fscanf(fp,"\n Available rooms: %d",&tn.av_rms);
                fscanf(fp,"\n Rooms booked   : %d",&tn.rm_num);
                fscanf(fp,"\n_______________________________");

                num++;
                if(strcmp(i_place,tn.tour_place)==0){
                    found=1;
                    loop7:
                    system("cls");
                    printf("\n\t\t\t**====Tour Details====**\n");
                    printf("\n\t\t\tPlace          : %s",tn.tour_place);
                    printf("\n\t\t\tHotel          : %s",tn.hotel_name);
                    printf("\n\t\t\tPackage type   : %s",tn.pac_type);
                    printf("\n\t\t\tPackage price  : %d",tn.pac_price);
                    printf("\n\t\t\tAvailable rooms: %d",tn.av_rms);
                    printf("\n\t\t____________________________________________\n");

                    printf("\n\t\t\tAre sure want to book this tour....");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\n\t\t____________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&n);

                    if(n==1){
                        loop1:
                        system("cls");
                        printf("\n\t\t\t**====Tour Booking====**\n");
                        printf("\n\t\t\tEnter the number of Person   :");
                        scanf("%d",&tic_book);

                        f_rooms = tic_book%2;
                        if(f_rooms==1){
                            rooms = (tic_book/2)+1;
                        }else{
                            rooms = tic_book/2;
                        }

                        system("cls");
                        printf("\n\t\t\t**====Tour Booking====**\n");
                        printf("\n\t\t\tEnter the number of Trip Days   :");
                        scanf("%d",&trip_days);

                        system("cls");
                        printf("\n\t\t\t**====Tour Booking====**\n");
                        printf("\n\t\t\tEnter the starting date (dd/mm/yyyy)  :");
                        scanf("%s",st_date);

                        ex_dd = atoi(st_date);
                        ex_mm = atoi(st_date + 3);
                        ex_yy = atoi(st_date + 6);


                       if(tic_book<=tn.av_rms){
                            tot_fare=(tic_book*tn.pac_price*trip_days);
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
                                printf("\n\t\t\t_________________________________");
                                printf("\n\t\t\t| Total ticket fare       : %d |",tot_fare);
                                printf("\n\t\t\t|________________________________|");
                                printf("\n\n\t\t\tEnter the amount  :");
                                scanf("%d",&i_amt);

                                if(i_amt==tot_fare){
                                    retval=load_user_balance(i_amt,tot_fare,tn.pac_price);
                                    if(retval==1){
                                        goto loop7;
                                    }else if(retval==2){
                                        goto loop1;
                                    }
                                    tn.av_rms -= rooms;
                                    tn.rm_num++;
                                    for (int i = 0; i < rooms; i++) {
                                        i_a_s[i] = tn.rm_num;
                                        tn.rm_num++;
                                    }
                                    tn.rm_num--;
                                    system("cls");
                                    printf("\n\t\t\t**=======Tour details=======**\n");
                                    printf("\n\t\t\tPayment successfull!!...");
                                    printf("\n\t\t_______________________________________________________         Available Balance : %d",retval);
                                    printf("\n\t\t| Name            :  %s", u_name);
                                    printf("\n\t\t| Tour Place      :  %s", tn.tour_place);
                                    printf("\n\t\t| Hotel name      :  %s", tn.hotel_name);
                                    printf("\n\t\t| package type    :  %s", tn.pac_type);
                                    printf("\n\t\t| Package price   :  RS.%d", tn.pac_price);
                                    printf("\n\t\t| Total peoples   :  %d", tic_book);
                                    printf("\n\t\t| Number of Rooms :  %d", rooms);
                                    printf("\n\t\t| Room Numbers    : ");
                                        for (int i = 0; i < rooms; i++) {
                                            printf("%d , ", i_a_s[i]);
                                        }
                                    printf("\n\t\t| Total fare      :  %d", tot_fare);
                                    printf("\n\t\t| Trip Days       :  %d", trip_days);
                                    printf("\n\t\t| Trip Starting date : %d/%d/%d", ex_dd,ex_mm,ex_yy);
                                    tour_date_load(st_date,trip_days);
                                    printf("\n\t\t|________________________________________________________");
                                    printf("\n\t\t\tHave a nice day......");
                                    getch();

                                    user_history("TN_Touristry",tic_book,tot_fare);

                                    fprintf(temp,"\n Place          : %s",tn.tour_place);
                                    fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                                    fprintf(temp,"\n Package type   : %s",tn.pac_type);
                                    fprintf(temp,"\n Package price  : %d",tn.pac_price);
                                    fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                                    fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                                    fprintf(temp,"\n_______________________________");

                                }else{
                                        printf("\n\t\t\tPlease Enter correct amount...");
                                        getch();
                                        goto loop2;
                                    }

                            }else{
                                printf("\n\t\t\tBooking cancelled....");
                                getch();

                                fprintf(temp,"\n Place          : %s",tn.tour_place);
                                fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                                fprintf(temp,"\n Package type   : %s",tn.pac_type);
                                fprintf(temp,"\n Package price  : %d",tn.pac_price);
                                fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                                fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                                fprintf(temp,"\n_______________________________");
                            }
                        }else{
                            printf("\n\t\t\t %d tickets Not Available  (Available tickets %d)",tic_book,tn.av_rms);
                            getch();
                            goto loop1;
                        }

                    }else{
                        printf("\n\t\t\tBooking cancelled....");
                        getch();
                        fprintf(temp,"\n Place          : %s",tn.tour_place);
                        fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                        fprintf(temp,"\n Package type   : %s",tn.pac_type);
                        fprintf(temp,"\n Package price  : %d",tn.pac_price);
                        fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                        fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                        fprintf(temp,"\n_______________________________");
                    }
                }else{
                    fprintf(temp,"\n Place          : %s",tn.tour_place);
                    fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                    fprintf(temp,"\n Package type   : %s",tn.pac_type);
                    fprintf(temp,"\n Package price  : %d",tn.pac_price);
                    fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                    fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                    fprintf(temp,"\n_______________________________");
                }
            }

            if(found==0){
                num=0;
                printf("\n\t\t\tNo Places found as %s For touristry",i_place);
                fclose(fp);
                fclose(temp);
                getch();
                goto hloop;
            }else{
                num=0;
                fclose(fp);
                fclose(temp);
                remove("tn_tour.txt");
                rename("temp_book.txt","tn_tour.txt");
                return 1;
            }
            goto mloop;
        case 2:
            view_tours(1);
            goto mloop;
        default:
            printf("\n\t\t\tplease Enter the valid choice....");
            goto mloop;

    }
}

int view_tours(int n)                                                                            //**********VIEW TOURS***********
{
    FILE *fp;
    int num=1,found=0;
    struct tours tn;
    fp=fopen("tn_tour.txt","r");

    if(fp==NULL){
        printf("error open file");
        fclose(fp);
        return 1;
    }else{

        system("cls");
        printf("\n\t\t\t**====View Tours=====**\n\n");
        while(fscanf(fp,"\n Place        : %s",tn.tour_place)!=EOF){
            fscanf(fp,"\n Hotel          : %s",tn.hotel_name);
            fscanf(fp,"\n Package type   : %s",tn.pac_type);
            fscanf(fp,"\n Package price  : %d",&tn.pac_price);
            fscanf(fp,"\n Available rooms: %d",&tn.av_rms);
            fscanf(fp,"\n Rooms booked   : %d",&tn.rm_num);
            fscanf(fp,"\n_______________________________");
            found=1;

            printf("\n\t\t\tPlace          : %s",tn.tour_place);
            printf("\n\t\t\tHotel          : %s",tn.hotel_name);
            printf("\n\t\t\tPackage type   : %s",tn.pac_type);
            printf("\n\t\t\tAvailable rooms: %d",tn.av_rms);
            printf("\n\t\t\tPackage price  : %d",tn.pac_price);
            if(n==2){
                printf("\n\t\t\tRooms booked   : %d",tn.rm_num);
            }
            printf("\n\t\t____________________________________________\n");

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


int admin()                                                                                  //**********ADMIN***********
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
            printf("\n\t\t\t**=======ADMIN Travel=======**\n");
            printf("\n\n\t\t\t\t1. Trains ticket");
            printf("\n\t\t\t\t2. Bus ticket");
            printf("\n\t\t\t\t3. Flight ticket");
            printf("\n\t\t\t\t4. Hotel Booking");
            printf("\n\t\t\t\t5. Vehicle Rental");
            printf("\n\t\t\t\t6. Back");
            printf("\n\t\t\t___________________________");
            printf("\n\t\t\tEnter the choice :");
            scanf("%d",&t1);

            if(t1==6){
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
                case 4:
                    system("cls");
                    retval=admin_hotel();
                    if(retval==1){
                        goto loop2;
                    }
                default:
                    printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
                    getch();
                    goto loop2;
            }
            break;
        case 2:
            mloop:
            system("cls");
            printf("\n\t\t\t**=======ADMIN Movies=======**\n");
            printf("\n\t\t\t1. Tamil Movies");
            printf("\n\t\t\t2. Hindi Movies");
            printf("\n\t\t\t3. Hollywood Movies");
            printf("\n\t\t\t4. Back");
            printf("\n\t\t\t___________________________");
            printf("\n\t\t\tEnter the choice :");
            scanf("%d", &m);

            if(m==4){
                goto loop1;
            }
            switch(m){
                case 1:
                    system("cls");
                    retval=admin_tamil_movie();
                    if(retval==1){
                        goto mloop;
                    }
                    break;
                case 2:
                    system("cls");
                    printf("\t\t\t\tNo Data Added........");
                    getch();
                    goto mloop;
                case 3:
                    system("cls");
                    retval=admin_holly_movie();
                    if(retval==1){
                        goto mloop;
                    }
                    break;
                default:
                    printf("\n\t\t\tPlease Enter a valid input...");
                    getch();
                    goto mloop;
            }
            break;
        case 4:
            eloop:
            system("cls");
            printf("\n\t\t\t**=======ADMIN Event=======**\n");
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
                    goto eloop;
                default:
                    printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
                    getch();
                    goto eloop;

            }
            break;
        case 5:
            tloop:
            system("cls");
            printf("\n\t\t\t**=======ADMIN Touristry=======**\n");
            printf("\n\n\t\t\t\t1. India");
            printf("\n\t\t\t\t2. Dubai");
            printf("\n\t\t\t\t3. Singapore");
            printf("\n\t\t\t\t4.Back");
            printf("\n\t\t\t___________________________");
            printf("\n\t\t\tEnter the choice :");
            scanf("%d",&m);

            if(t1==4){
                goto loop1;
            }

            switch(m){
                case 1:
                    admin_ind_tour();
                    goto tloop;
                default:
                    printf("\n\t\t\tPlease Enter valid input.....Enter to continue");
                    getch();
                    goto tloop;

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

int admin_train()                                                                             //**********ADMIN TRAIN***********
{
    int n,c;
    char tr_seat[10];
    struct travel train;
    FILE *fp,*temp;

    admin_train:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1. Add train");
    printf("\n\t\t\t\t2. View train details");
    printf("\n\t\t\t\t3. Delete train details");
    printf("\n\t\t\t\t4. Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("train_book.txt", "a");

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
        printf("\n\t\t\t\tSeats Booked       : ");
        scanf("%d", &train.seat_numbers);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                    train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
            fprintf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  : %d\nseat booked  :%d",
                    train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
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
        view_travel(2,1);
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
    case 101:
        strcpy(u_name,"admin");
        strcpy(u_pwd,"123");
        train_tik_book();
        goto admin_train;
    default:
        printf("Please enter valid input");
        goto admin_train;
    }

    return 0;
}

int delete_train()                                                                             //**********ADMIN DELETE TRAIN***********
{
    FILE *fp, *temp;
    struct travel train;
    int found = 0, c,m,num=0;
    char itr_name[20];

    loop1:
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

    fp = fopen("train_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL){
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    while (fscanf(fp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                  train.tp_name,&train.tp_no,train.depart_time,train.arrive_time) != EOF){
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
               train.depart_place,train.arrive_place,&train.tp_fare,train.tp_tm_dur,&train.tp_av_tic,&train.seat_numbers);
        fscanf(fp,"\n_______________________________________________________________________________________");

        num++;
        if (strcmp(train.tp_name, itr_name) == 0){
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Train Details to Delete=======**\n");
            printf("\n\n\t\t\tTrain Id         : %d", num);
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

            printf("\n\t\t\tAre you sure you want to delete this train?");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\t\t\t3. Next");
            printf("\n\t\t_______________________________________");
            printf("\n\t\t\t Enter the choice  :");
            scanf("%d", &c);

            if (c == 1){
                strcpy(itr_name,"dummy");
                printf("\n\t\t\tTrain details deleted successfully...");
                getch();
            }else if(c==2){
                strcpy(itr_name,"dummy");
                fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
                fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
                fprintf(temp,"\n_______________________________________________________________________________________");
            }else{
                found=2;
                fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                        train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
                fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
                fprintf(temp,"\n_______________________________________________________________________________________");
            }
        }else{
            fprintf(temp,"\n Train name     :%s\n Train number   :%d\n Departure time :%s\n Arrival time   :%s",
                    train.tp_name,train.tp_no,train.depart_time,train.arrive_time);
            fprintf(temp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    train.depart_place,train.arrive_place,train.tp_fare,train.tp_tm_dur,train.tp_av_tic,train.seat_numbers);
            fprintf(temp,"\n_______________________________________________________________________________________");
        }
    }

    if(found==0 || found==2){
        printf("\n\t\t\tNo Train name found as %s",itr_name);
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
            return 1;
        }
    }else{
        num=0;
        found=0;
        fclose(fp);
        fclose(temp);
        remove("train_book.txt");
        rename("temp_book.txt","train_book.txt");
        return 1;
    }

    return 0;
}

int admin_bus()                                                                                  //**********ADMIN BUS***********
{
    int n,c;
    struct travel bus;
    FILE *fp,*temp;

    admin_bus:
    system("cls");
    printf("\n\t\t\t**=======ADMIN=======**\n");
    printf("\n\t\t\t\t1. Add Bus");
    printf("\n\t\t\t\t2. View bus details");
    printf("\n\t\t\t\t3. Delete bus details");
    printf("\n\t\t\t\t4. Back");
    printf("\n\t\t\t___________________________");
    printf("\n\t\t\tEnter the choice: ");
    scanf("%d", &n);

    if (n == 4) {
        return 1;
    }

    switch (n) {
    case 1:

        fp = fopen("bus_book.txt", "a");

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
        printf("\n\t\t\t\tSeats Booked       : ");
        scanf("%d", &bus.seat_numbers);


        if (fp == NULL) {
            printf("Error opening file for appending.\n");
            getch();
            return 0;
        }else{
            fprintf(fp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
            fprintf(fp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
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
        view_travel(2,2);
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
    case 101:
        strcpy(u_name,"admin");
        strcpy(u_pwd,"123");
        bus_tik_book();
        goto admin_bus;
    default:
        printf("Please enter valid input");
        goto admin_bus;
    }

    return 0;
}

int delete_bus()                                                                            //**********ADMIN DELETE BUS***********
{
    FILE *fp, *temp;
    struct travel bus;
    int found = 0, c,m,num=0;
    char ibs_name[20];

    loop1:
    system("cls");
    printf("\n\t\t\t**=======Delete bus Details=======**\n");
    printf("\n\t1. Back");
    printf("\n\t\t\tEnter the bus name    :");
    scanf("%s", ibs_name);

    if (strcmp(ibs_name, "1") == 0)
    {
        return 1;
    }
    fp = fopen("bus_book.txt", "r");
    temp = fopen("temp_book.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file for appending.\n");
        getch();
        return 0;
    }

    while (fscanf(fp,"\n Bus name     :%s\n Bus number   :%d\n Departure time :%s\n Arrival time   :%s",
                  bus.tp_name,&bus.tp_no,bus.depart_time,bus.arrive_time) != EOF){
        fscanf(fp,"\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
               bus.depart_place,bus.arrive_place,&bus.tp_fare,bus.tp_tm_dur,&bus.tp_av_tic,&bus.seat_numbers);
        fscanf(fp,"\n_______________________________________________________________________________________");

        num++;
        if (strcmp(bus.tp_name, ibs_name) == 0)
        {
            found = 1;
            system("cls");
            printf("\n\t\t\t**=======Bus Details to Delete=======**\n");
            printf("\n\n\t\t\tBus Id           : %d", num);
            printf("\n\t\t\tBus name          : %s ", bus.tp_name);
            printf("\n\t\t\t Bus number       : %d", bus.tp_no);
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
            printf("\t\t\t3. Next");
            printf("\n\t\t_________________________________");
            printf("\n\n\t\t\tEnter the choice :");
            scanf("%d", &c);

            if (c == 1){
                strcpy(ibs_name,"dummy");
                printf("\n\t\t\t bus details deleted successfully...");
                getch();
            }else if(c==2){
                strcpy(ibs_name,"dummy");
                fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                        bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }else{
                found=2;
                fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                        bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
                fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                        bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
                fprintf(temp, "\n_______________________________________________________________________________________");
            }
        }
        else
        {
            fprintf(temp, "\n Bus name       :%s\n Bus number     :%d\n Departure time :%s\n Arrival time   :%s",
                    bus.tp_name,bus.tp_no,bus.depart_time,bus.arrive_time);
            fprintf(temp, "\n Departure place:%s\n Arrival place  :%s\n Ticket fare    :%d\n Time duration  :%s\nAvailable tickets  :%d\nseat booked  :%d",
                    bus.depart_place,bus.arrive_place,bus.tp_fare,bus.tp_tm_dur,bus.tp_av_tic,bus.seat_numbers);
            fprintf(temp, "\n_______________________________________________________________________________________");
        }
    }
    if(found==0 || found==2){
        printf("\n\t\t\tNo Buses name found as %s",ibs_name);
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
            remove("bus_book.txt");
            rename("temp_book.txt","bus_book.txt");
            goto loop1;
        }else{
            num=0;
            found=0;
            fclose(fp);
            fclose(temp);
            remove("bus_book.txt");
            rename("temp_book.txt","bus_book.txt");
            return 1;
        }
    }else{
        num=0;
        found=0;
        fclose(fp);
        fclose(temp);
        remove("bus_book.txt");
        rename("temp_book.txt","bus_book.txt");
        return 1;
    }

    return 0;
}

int admin_hotel()                                                                                   //**********ADMIN HOTEL***********
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

        fp = fopen("hotel_book.txt", "a");

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
        //hotel_book();
        goto admin_hotel;
    default:
        printf("Please enter valid input");
        goto admin_hotel;
    }

    return 0;
}

int delete_hotel()                                                                                      //**********ADMIN DELETE BUS***********
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

int admin_tamil_movie()                                                                            //**********ADMIN TAMIL MOVIE***********
{
    struct movie tamil;
    FILE *fp,*temp;
    int n,m,c,found=0;
    char i_mov_name[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====Admin Tamil Movies=====\n");
    printf("\n\t\t\t1. Add Movies");
    printf("\n\t\t\t2. View Movies");
    printf("\n\t\t\t3. Delete Movies");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==4){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            fp=fopen("tamil_movie.txt","a");

            system("cls");
            printf("\n\t\t\t=====Add Tamil Movies=====\n");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",tamil.mov_name);
            printf("\n\t\t\tTheater name : ");
            scanf("%s",tamil.mov_theater);
            printf("\n\t\t\tMovie Date   : ");
            scanf("%s",tamil.mov_date);
            printf("\n\t\t\tMovie Time   : ");
            scanf("%s",tamil.mov_time);
            printf("\n\t\t\tTicket price : ");
            scanf("%d",&tamil.mov_t_fare);
            printf("\n\t\t\tAvailable ticket : ");
            scanf("%d",&tamil.mov_av_tic);
            printf("\n\t\t\tSeats Booked : ");
            scanf("%d",&tamil.seat_numbers);

            fprintf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
            fprintf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
            fprintf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
            fprintf(fp,"\n_____________________________________________________");
            printf("\n\t\t\tMovie details added successfully....");
            getch();
            printf("\n\t\t\tDo you want to add another....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t________________________________");
            printf("\n\t\t\tEnter the choice  : ");
            scanf("%d",&m);

            if(m==1){
                fclose(fp);
                goto loop1;
            }else{
                fclose(fp);
                goto hloop;
            }
            break;
        case 2:
            retval=view_movie(2,1);
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
            loop2:
            system("cls");
            printf("\n\t\t\t=====Delete Tamil Movies=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter name of movie   :");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                goto hloop;
            }
            fp=fopen("tamil_movie.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&tamil.mov_t_fare,&tamil.mov_av_tic,&tamil.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete Tamil Movies=====\n");
                if(strcmp(tamil.mov_name,i_mov_name)==0){
                    found=1;
                    printf("\n\t\t\t**=======Tamil Movies=======**\n");
                    printf("\n\t\t\tMovie name         : %s",tamil.mov_name);
                    printf("\n\t\t\tTheater name       : %s",tamil.mov_theater);
                    printf("\n\t\t\tDate               : %s",tamil.mov_date);
                    printf("\n\t\t\tTiming             : %s",tamil.mov_time);
                    printf("\n\t\t\tTicket price       : %d",tamil.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",tamil.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\tAre sure want to Delete movie details");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\t\t\t3. Next");
                    printf("\n\t\t_____________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==1){
                        strcpy(i_mov_name,"dummy");
                        printf("\n\t\t\tMovie deleted successfully....");
                        getch();
                    }else if(m==2){
                        strcpy(i_mov_name,"dummy");
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }
                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",tamil.mov_name,tamil.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",tamil.mov_date,tamil.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",tamil.mov_t_fare,tamil.mov_av_tic,tamil.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                printf("\n\t\t\tNo movie name found as %s",i_mov_name);
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&c);

                if(c==1){
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp.txt","tamil_movie.txt");
                    goto loop2;
                }else{
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tamil_movie.txt");
                    rename("temp.txt","tamil_movie.txt");
                    goto hloop;
                }
            }else{
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tamil_movie.txt");
                rename("temp.txt","tamil_movie.txt");
                goto hloop;
            }
            break;
        case 101:
            strcpy(u_name,"admin");
            strcpy(u_pwd,"123");
            tamil_movie_book();
            goto hloop;
        default:
            printf("\n\t\t\tPlease Enter a valid input....");
            getch();
            goto hloop;
    }
    getch();

    return 1;
}

int admin_holly_movie()                                                                         //**********ADMIN HOLLYWOOD MOVIE***********
{
    struct movie holly;
    FILE *fp,*temp;
    int n,m,c,found=0;
    char i_mov_name[20];

    hloop:
    system("cls");
    printf("\n\t\t\t=====Admin Hollywood Movies=====\n");
    printf("\n\t\t\t1. Add Movies");
    printf("\n\t\t\t2. View Movies");
    printf("\n\t\t\t3. Delete Movies");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==4){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            fp=fopen("holly_movie.txt","a");

            system("cls");
            printf("\n\t\t\t=====Add Hollywood Movies=====\n");
            printf("\n\t\t\tMovie name   : ");
            scanf("%s",holly.mov_name);
            printf("\n\t\t\tTheater name : ");
            scanf("%s",holly.mov_theater);
            printf("\n\t\t\tMovie Date   : ");
            scanf("%s",holly.mov_date);
            printf("\n\t\t\tMovie Time   : ");
            scanf("%s",holly.mov_time);
            printf("\n\t\t\tTicket price : ");
            scanf("%d",&holly.mov_t_fare);
            printf("\n\t\t\tAvailable ticket : ");
            scanf("%d",&holly.mov_av_tic);
            printf("\n\t\t\tSeats Booked : ");
            scanf("%d",&holly.seat_numbers);

            fprintf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
            fprintf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
            fprintf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
            fprintf(fp,"\n_____________________________________________________");
            printf("\n\t\t\tMovie details added successfully....");
            getch();
            printf("\n\t\t\tDo you want to add another....");
            printf("\n\t\t\t1. Yes");
            printf("\n\t\t\t2. No");
            printf("\n\t\t________________________________");
            printf("\n\t\t\tEnter the choice  : ");
            scanf("%d",&m);

            if(m==1){
                fclose(fp);
                goto loop1;
            }else{
                fclose(fp);
                goto hloop;
            }
            break;
        case 2:
            retval=view_movie(2,2);
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
            loop2:
            system("cls");
            printf("\n\t\t\t=====Delete Hollywood Movies=====\n");
            printf("\n\t\t1. Back");
            printf("\n\t\t\tEnter name of movie   :");
            scanf("%s",i_mov_name);

            if(strcmp(i_mov_name,"1")==0){
                goto hloop;
            }
            fp=fopen("holly_movie.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater)!=EOF){
                fscanf(fp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                fscanf(fp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",&holly.mov_t_fare,&holly.mov_av_tic,&holly.seat_numbers);
                fscanf(fp,"\n_____________________________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete Hollywod Movies=====\n");
                if(strcmp(holly.mov_name,i_mov_name)==0){
                    found=1;
                    printf("\n\t\t\t**=======Hollywood Movies=======**\n");
                    printf("\n\t\t\tMovie name         : %s",holly.mov_name);
                    printf("\n\t\t\tTheater name       : %s",holly.mov_theater);
                    printf("\n\t\t\tDate               : %s",holly.mov_date);
                    printf("\n\t\t\tTiming             : %s",holly.mov_time);
                    printf("\n\t\t\tTicket price       : %d",holly.mov_t_fare);
                    printf("\n\t\t\tAvailable tickets  : %d",holly.mov_av_tic);
                    printf("\n\t\t_____________________________________________");

                    printf("\n\t\t\tAre sure want to Delete movie details");
                    printf("\n\t\t\t1. Yes");
                    printf("\n\t\t\t2. No");
                    printf("\t\t\t3. Next");
                    printf("\n\t\t_____________________________________________");
                    printf("\n\t\t\tEnter the choice   :");
                    scanf("%d",&m);

                    if(m==1){
                        strcpy(i_mov_name,"dummy");
                        printf("\n\t\t\tMovie deleted successfully....");
                        getch();
                    }else if(m==2){
                        strcpy(i_mov_name,"dummy");
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }else{
                        found=2;
                        fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                        fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                        fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                        fprintf(temp,"\n_____________________________________________________");
                    }
                }else{
                   fprintf(temp,"\n Movie name     : %s\n Theater name   : %s",holly.mov_name,holly.mov_theater);
                   fprintf(temp,"\n Date           : %s\n Time           : %s",holly.mov_date,holly.mov_time);
                   fprintf(temp,"\n Ticket fare    : %d\n Available tickets : %d\n seat booked  :%d",holly.mov_t_fare,holly.mov_av_tic,holly.seat_numbers);
                   fprintf(temp,"\n_____________________________________________________");
                }
            }
            if(found==0 || found==2){
                printf("\n\t\t\tNo movie name found as %s",i_mov_name);
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\t1. Search again");
                printf("\n\t\t\t2. Back");
                printf("\n\t\t_________________________________________");
                printf("\n\t\t\tEnter the choice   :");
                scanf("%d",&c);

                if(c==1){
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp.txt","holly_movie.txt");
                    goto loop2;
                }else{
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("holly_movie.txt");
                    rename("temp.txt","holly_movie.txt");
                    goto hloop;
                }
            }else{
                found=0;
                fclose(fp);
                fclose(temp);
                remove("holly_movie.txt");
                rename("temp.txt","holly_movie.txt");
                goto hloop;
            }
            break;
        case 101:
            strcpy(u_name,"admin");
            strcpy(u_pwd,"123");
            holly_movie_book();
            goto hloop;
        default:
            printf("\n\t\t\tPlease Enter a valid input....");
            getch();
            goto hloop;
    }
    getch();

    return 1;
}

int admin_sports_event()                                                                           //**********ADMIN SPORTS EVENT***********
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
                    goto loop;
                    break;
                case 2:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop;
                    break;
                case 3:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop;
                    break;
                case 4:
                    goto hloop;
                default:
                    printf("\n\t\t\tplease Enter a valid input....");
                    getch();
                    goto loop;
            }
            break;
        case 2:
            loop2:
            system("cls");
            printf("\n\t\t\t===== Cricket Sports=====\n");
            printf("\n\t\t1. IPL League");
            printf("\n\t\t2. BBL league");
            printf("\n\t\t3. ICC Matches");
            printf("\n\t\t4. Back");
            printf("\n\t\t_________________________________");
            printf("\n\t\tEnter the choice   :");
            scanf("%d",&m);
            switch(m){
                case 1:
                    retval=admin_ipl();
                    goto loop2;
                    break;
                case 2:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop2;
                    break;
                case 3:
                    printf("\n\t\t\tNo information....");
                    getch();
                    goto loop2;
                    break;
                case 4:
                    goto hloop;
                default:
                    printf("\n\t\t\tplease Enter a valid input....");
                    getch();
                    goto loop2;
            }
            break;
        default:
            printf("\n\t\t\tInvalid input....");
            getch();
            goto hloop;

    }
    return 0;
}

int admin_isl()                                                                                      //**********ADMIN ISL***********
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
            printf("\n\t\t\t8. Seats Booked :");
            scanf("%d",&isl.seat_numbers);

            fprintf(fp,"\n Match  %s vs %s",isl.team1,isl.team2);
            fprintf(fp,"\n Venue        : %s",isl.venue);
            fprintf(fp,"\n Date         : %s",isl.date);
            fprintf(fp,"\n Time         : %s",isl.time);
            fprintf(fp,"\n Ticket fare  : %d",isl.t_fare);
            fprintf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
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
            retval=view_sports(2,1);
            if(retval==1){
                goto hloop;
            }
            break;
        case 3:
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

            fp=fopen("isl_book.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Match  %s vs %s",isl.team1,isl.team2)!= EOF){
                fscanf(fp,"\n Venue        : %s",isl.venue);
                fscanf(fp,"\n Date         : %s",isl.date);
                fscanf(fp,"\n Time         : %s",isl.time);
                fscanf(fp,"\n Ticket fare  : %d",&isl.t_fare);
                fscanf(fp,"\n Available Tickets  : %d\n Seats Booked  : %d",&isl.av_tic,&isl.seat_numbers);
                fscanf(fp,"\n_________________________________");

                system("cls");
                printf("\n\t\t\t=====Delete ISL Matches=====\n");
                 num++;
                 if ((strcmp(i_team1, isl.team1) == 0 && strcmp(i_team2, isl.team2) == 0) || (strcmp(i_team1, isl.team2) == 0 && strcmp(i_team2, isl.team1) == 0)) {
                    found=1;
                    printf("\n\t\t%d.        Match   %s vs %s",num,isl.team1,isl.team2);
                    printf("\n\t\t\t  Venue       : %s stadium",isl.venue);
                    printf("\n\t\t\t  Date        : %s",isl.date);
                    printf("\n\t\t\t  Time        : %s",isl.time);
                    printf("\n\t\t\t  Ticket fare  : %d",isl.t_fare);
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
                        printf("\n\t\t\t Match %s vs %s deleted successfully...",isl.team1,isl.team2);
                        getch();
                    }else if(n==2){
                        strcpy(i_team1,"dummy");
                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                        fprintf(temp,"\n Venue        : %s",isl.venue);
                        fprintf(temp,"\n Date         : %s",isl.date);
                        fprintf(temp,"\n Time         : %s",isl.time);
                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                        fprintf(temp,"\n_________________________________");
                    }else{
                        fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                        fprintf(temp,"\n Venue        : %s",isl.venue);
                        fprintf(temp,"\n Date         : %s",isl.date);
                        fprintf(temp,"\n Time         : %s",isl.time);
                        fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                        fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
                        fprintf(temp,"\n_________________________________");
                        found=2;
                    }

                 }else{
                    fprintf(temp,"\n Match  %s vs %s",isl.team1,isl.team2);
                    fprintf(temp,"\n Venue        : %s",isl.venue);
                    fprintf(temp,"\n Date         : %s",isl.date);
                    fprintf(temp,"\n Time         : %s",isl.time);
                    fprintf(temp,"\n Ticket fare  : %d",isl.t_fare);
                    fprintf(temp,"\n Available Tickets  : %d\n Seats Booked  : %d",isl.av_tic,isl.seat_numbers);
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
                    remove("isl_book.txt");
                    rename("temp.txt","isl_book.txt");
                    goto loop1;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("isl_book.txt");
                    rename("temp.txt","isl_book.txt");
                    goto hloop;
                }
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("isl_book.txt");
                rename("temp.txt","isl_book.txt");
                goto hloop;
            }
            break;
        case 101:
            strcpy(u_name,"admin");
            strcpy(u_pwd,"123");
            isl_tic_book();
            goto hloop;
        default:
            printf("\n\t\t\tplease Enter a valid Input....");
            getch();
            goto hloop;
    }
    return 1;
}

int admin_ipl()                                                                                  //**********ADMIN IPL***********
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
            retval=view_sports(2,2);
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
        case 101:
            strcpy(u_name,"admin");
            strcpy(u_pwd,"123");
            ipl_tic_book();
            goto hloop;
        default:
            printf("\n\t\t\tplease Enter a valid Input....");
            getch();
            goto hloop;
    }
    return 1;
}

int admin_ind_tour()                                                                               //**********ADMIN IND TOUR***********
{
    int n;

    loop:
    system("cls");
    printf("\n\t\t\t===== India tour=====\n");
    printf("\n\t\t\t1. Tamilnadu ");
    printf("\n\t\t\t2. Kerala");
    printf("\n\t\t\t3. Goa");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t_______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==4){
        return 1;
    }

    switch(n){
        case 1:
            admin_tn_tour();
            goto loop;
        default:
            printf("\n\t\t\tPlease Enter a valid input....");
            getch();
            goto loop;
    }

}

int admin_tn_tour()                                                                                       //**********ADMIN TN TOUR***********
{
    int n,m,found=0,num=0;
    char d_tour[20];
    FILE *fp,*temp;
    struct tours tn;
    loop:
    system("cls");
    printf("\n\t\t\t=====Tamilnadu tours=====\n");
    printf("\n\t\t\t1. Add tours ");
    printf("\n\t\t\t2. View tours");
    printf("\n\t\t\t3. Delete tours");
    printf("\n\t\t\t4. Back");
    printf("\n\t\t_______________________________________");
    printf("\n\t\t\tEnter the choice   :");
    scanf("%d",&n);

    if(n==4){
        return 1;
    }
    switch(n){
        case 1:
            loop1:
            fp = fopen("tn_tour.txt","a");
            system("cls");
            printf("\n\t\t\t=====Add tours=====\n");
            printf("\n\t\t\tEnter the place         :");
            scanf("%s",tn.tour_place);
            printf("\n\t\t\tEnter Hotel name        :");
            scanf("%s",tn.hotel_name);
            printf("\n\t\t\tEnter the package type  :");
            scanf("%s",tn.pac_type);
            printf("\n\t\t\tEnter the package price :");
            scanf("%d",&tn.pac_price);
            printf("\n\t\t\tEnter the Available rooms :");
            scanf("%d",&tn.av_rms);
            printf("\n\t\t\tEnter Room number booked:");
            scanf("%d",&tn.rm_num);
            printf("\n\t\t______________________________________________________");

            fprintf(fp,"\n Place          : %s",tn.tour_place);
            fprintf(fp,"\n Hotel          : %s",tn.hotel_name);
            fprintf(fp,"\n Package type   : %s",tn.pac_type);
            fprintf(fp,"\n Package price  : %d",tn.pac_price);
            fprintf(fp,"\n Available rooms: %d",tn.av_rms);
            fprintf(fp,"\n Rooms booked   : %d",tn.rm_num);
            fprintf(fp,"_______________________________");
            fclose(fp);

            printf("\n\t\t\tDetails added successfully......");
            printf("\n\t\t\tDo you want to add another.....");
            printf("\n\t\t_______________________________________________");
            printf("\n\n\t\t\t1. Yes                   2.No");
            printf("\n\t\t\tEnter the choice  :");
            scanf("%d",&m);
            if(m==1){
                goto loop1;
            }else{
                goto loop;
            }

            break;
        case 2:
            view_tours(2);
            goto loop;
        case 3:
            loop3:
            system("cls");
            printf("\n\t\t\t**======Delete tours=====**\n");
            printf("\n\t1.Back              Enter the place name   :");
            scanf("%s",d_tour);
            if(strcmp(d_tour,"1")==0){
                goto loop;
            }
            fp=fopen("tn_tour.txt","r");
            temp=fopen("temp.txt","w");

            while(fscanf(fp,"\n Place        : %s",tn.tour_place)!=EOF){
                fscanf(fp,"\n Hotel          : %s",tn.hotel_name);
                fscanf(fp,"\n Package type   : %s",tn.pac_type);
                fscanf(fp,"\n Package price  : %d",&tn.pac_price);
                fscanf(fp,"\n Available rooms: %d",&tn.av_rms);
                fscanf(fp,"\n Rooms booked   : %d",&tn.rm_num);
                fscanf(fp,"\n_______________________________");

                num++;
                system("cls");
                printf("\n\t\t\t**====Delete Tours=====**\n\n");
                if(strcmp(d_tour,tn.tour_place)==0){
                    found=1;
                    printf("\n\t\t%d       Place           : %s",num,tn.tour_place);
                    printf("\n\t\t\tHotel           : %s",tn.hotel_name);
                    printf("\n\t\t\tPackage type    : %s",tn.pac_type);
                    printf("\n\t\t\tPackage price   : %d",tn.pac_price);
                    printf("\n\t\t\tAvailable rooms : %d",tn.av_rms);
                    printf("\n\t\t\tRooms booked    : %d",tn.rm_num);
                    printf("\n\t\t____________________________________________\n");

                    printf("\n\t\t\tDo you want to delete this info....");
                    printf("\n\t\t\t1.Yes                       2.No");
                    printf("\n\t\t\t3.Next");
                    printf("\n\t\t_________________________________________");
                    printf("\n\t\t\tEnter the choice  :");
                    scanf("%d",&m);
                    if(m==1){
                        printf("\n\t\t\tTour details deleted successfully......");
                        getch();
                        strcpy(d_tour,"dummy");
                    }else if(m==3){
                        found=2;
                        fprintf(temp,"\n Place          : %s",tn.tour_place);
                        fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                        fprintf(temp,"\n Package type   : %s",tn.pac_type);
                        fprintf(temp,"\n Package price  : %d",tn.pac_price);
                        fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                        fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                        fprintf(temp,"_______________________________");
                    }else{
                        fprintf(temp,"\n Place          : %s",tn.tour_place);
                        fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                        fprintf(temp,"\n Package type   : %s",tn.pac_type);
                        fprintf(temp,"\n Package price  : %d",tn.pac_price);
                        fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                        fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                        fprintf(temp,"_______________________________");
                    }
                }else{
                    fprintf(temp,"\n Place          : %s",tn.tour_place);
                    fprintf(temp,"\n Hotel          : %s",tn.hotel_name);
                    fprintf(temp,"\n Package type   : %s",tn.pac_type);
                    fprintf(temp,"\n Package price  : %d",tn.pac_price);
                    fprintf(temp,"\n Available rooms: %d",tn.av_rms);
                    fprintf(temp,"\n Rooms booked   : %d",tn.rm_num);
                    fprintf(temp,"\n_______________________________");
                }
            }

            if(found==0 || found==2){
                printf("\n\t\t\tNo Tours found as %s",d_tour);
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
                    remove("tn_tour.txt");
                    rename("temp.txt","tn_tour.txt");
                    goto loop3;
                }else{
                    num=0;
                    found=0;
                    fclose(fp);
                    fclose(temp);
                    remove("tn_tour.txt");
                    rename("temp.txt","tn_tour.txt");
                    goto loop;
                }
            }else{
                num=0;
                found=0;
                fclose(fp);
                fclose(temp);
                remove("tn_tour.txt");
                rename("temp.txt","tn_tour.txt");
                goto loop;
            }

            break;
        case 101:
            strcpy(u_name,"admin");
            strcpy(u_pwd,"123");

            goto loop;
        default:
            printf("\n\t\t\tPlease Enter a Valid input....");
            getch();
            goto loop;
    }
}
