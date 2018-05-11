#include <iostream> //cin,cout
#include <fstream> //file handling
#include <stdlib.h> //rand(),srand()
#include <string.h> //string manipulation
#include <conio.h> //getch()
#include <ctype.h> //string manipulation
#include <time.h> //strdate,strtime,time()
#include <windows.h> //Sleep,system()

using namespace std;

int subcmp(char*,char*); //substring finder

class user
{
    char username[50];
    char pass[15];
    char watchlist[25][50];
    int flag,watch_length;
    int uid;
public:
    user()
    {
        flag=0;
        watch_length=0;
    }
    void list()
    {
        for(int i=0 ; i<watch_length ; i++)
        {
            cout << "\t\t\t\t# " << i+1 << "  " << watchlist[i] << endl << endl;
        }
    }
    int watch()
    {
        return watch_length;
    }
    int flagg()
    {
        return flag;
    }
    int uidd()
    {
        return uid;
    }
    void open_user()
    {
        flag=1;
    }
    void close_user()
    {
        flag=0;
    }
    void print_name(int &l)
    {
        flag=1;
        l = strlen(username);
        cout << username;
    }
    void builduser(char uname[],char upass[],int uuid)
    {
        strcpy(username,uname);
        strcpy(pass,upass);
        uid = uuid;
    }
    int check_username(char a[50])
    {
        return (!strcmp(username,a));
    }
    int check_pass(char a[50])
    {
        return (!strcmp(pass,a));
    }
    void set_watchlist(char a[],int &jj)
    {
        int check=0;
        for(int i=0 ; i<watch_length ; i++)
        {
            if(!strcmpi(watchlist[i],a))
                check++;
        }
        if(check)
        {
            cout << "\t\t\t\tMOVIE ALREADY IN LIST";
            jj=1;
        }
        else
        {
            strcpy(watchlist[watch_length++],a);
            jj=0;
        }
    }

} u,t,logged_in_user;

class movie
{
    char name[50],director[50],synopsis[300];
    int year;
    float rating;
public:
    void in()
    {
        fflush(stdin);
        cout << "\n\n\t\t\t\tEnter details of the Movie : \n";
        cout << "\n\t\t\tName : ";
        cin.getline(name,50);
        cout << "\n\t\t\tDirector : ";
        cin.getline(director,50);
        cout << "\n\t\t\tYear : ";
        cin >> year;
        cout << "\n\t\t\tRating : ";
        cin >> rating;
        float final;
        int t;
        t = rating/10;
        t++;
        t*=10;
        final = int((rating/t)*100);
        final = final/10;
        rating = final;
        fflush(stdin);
        cout << "\n\t\tSynopsis : ";
        cin.getline(synopsis,300);
    }
    void out_full()
    {
        cout << "\n\t\t\t\t  " << name << "  (" << year << ") " << endl << endl << endl;
        cout << "Director : " << director << endl << endl;
        cout << "Rating : " << rating << endl << endl;
        cout << "Synopsis : " << synopsis << endl << endl;
        cout << endl << endl;
    }
    void txt_full(char a[],int n)
    {
        ofstream out (a,ios::app);
        out << n << " . " << name << "  (" << year << ") " << endl;
        out << "Director : " << director << endl;
        out << "Rating : " << rating << endl;
        out << "Synopsis : " << synopsis << endl;
        out << endl << endl;
        out.close();
    }
    void out_name()
    {
        cout << name << " (" << year << ") " << "  [" << rating << "]" << endl << endl;
    }
    void set_name(char a[])
    {
        strcpy(name,a);
    }
    void set_director(char a[])
    {
        strcpy(director,a);
    }
    void set_year(int a)
    {
        year == a;
    }
    void set_synopsis(char a[])
    {
        strcpy(synopsis,a);
    }
    void set_rating(float a)
    {
        float final;
        int t;
        t = a/10;
        t++;
        t*=10;
        final = int((a/t)*100);
        final = final/10;
        rating = final;
    }
    int check_name(char NAME[])
    {
        return (subcmp(name,NAME));
    }
    int check_name_edit(char NAME[])
    {
        return (!strcmpi(name,NAME));
    }
    int check_name(movie temp)
    {
        return (!strcmpi(temp.name,name));
    }
    int check_director(char NAME[])
    {
        return (!strcmpi(NAME,director));
    }
    int check_year(int t)
    {
        if(t == year)
            return 1;
        else
            return 0;
    }
    float give_rating()
    {
        return rating;
    }

};

//Function Prototypes
void bottom_bar(); //prints the bottom bar
void swap(movie &a,movie &b); //swap two movies
void exits(int ff); //exit from the program and arrange movies according to rating
void loading(); // loading bar
void login(); //login window
void main_menu(); //main window
void user_menu(); //window after user logins
void createuser(); //sign up window
void no_login(); //unsuccessful login window
void exports(); //export movie database to txt file
void random_movie(); //takes to a random movie
void add_movie(); //new movie window
void search();  // search window
void watchlist(); //manage watchlists
void edit_movie(); //edit movie window
void splash(); //splash screen

int main()
{
    //thats small!!
    srand(time(0));
    splash();
}

int subcmp(char a[],char b[])
{
    int la = strlen(a),lb = strlen(b),flag=0,flag2=0;
    if(lb > la)
        return 0;
    for(int i=0 ; i<la ; i++)
    {
        if(la-lb<3)
            if(i<lb)
                if(a[i] == b[i])
                    flag2++;
        if(tolower(a[i]) == tolower(b[0]))
        {
            for(int j=1 ; j<lb ; j++)
            {
                if(tolower(a[i+j]) != tolower(b[j]))
                {
                    flag=0;
                    break;
                }
                else
                    flag=1;
            }
            if(flag == 1)
            {
                if(lb == la)
                    return 7;
                else
                    return flag;
            }
        }
    }
    if(flag2>5)
        return 1;
    else
        return flag;
}

void bottom_bar()
{
    char date[9];
    _strdate(date);
    char time[11];
    _strtime(time);
    time[5] = '\0';
    cout << char(218);
    for(int i=0 ; i<97 ; i++)
        cout << char(196);
    cout << char(191);
    cout << endl;
    cout << char(179);
    cout << date[3] << date[4] << date[2] << date[0] << date[1] << date[5] << date[6] << date[7];
    cout <<  "                                      CMDB                                          " << time << char(179);
    cout << endl;
    cout << char(192);
    for(int i=0 ; i<97 ; i++)
        cout << char(196);
    cout << char(217);
}

void swap(movie &a,movie &b)
{
    movie t;
    t=a;
    a=b;
    b=t;
}

void exits(int ff)
{
    ifstream fin("movies.dat",ios::binary);
    movie temp,a[500];
    int i=0;
    while(fin.read((char *)&a[i++],sizeof(a[i++])));
    fin.close();
    for(int j=0 ; j<i ; j++)
    {
        for(int k=0 ; k<i ; k++)
        {
            if(a[j].give_rating()>a[k].give_rating())
                swap(a[j],a[k]);
        }
    }
    ofstream fout("movies.dat",ios::binary);
    for(int j=0 ; j<i-1 ; j++)
    {
        fout.write((char *)&a[j],sizeof(a[j]));
    }
    fout.close();
    ofstream tt("temp.dat",ios::binary);
    tt << " ";
    tt.close();

    exit(0);
}

void loading()
{
    cout << "\t\t\t\t";
    int time = 35;
    for(int i=0 ; i<30 ; i++)
    {
        cout << char(220);
        Sleep(time);
    }
}

void createuser()
{
    system("cls");
    char uname[50];
    int flag=1,num;
    char pass[50];
    ifstream fin("login_data.dat",ios::binary);
    cout << "\n\n\t\t\t\tCreate New User : \n\n\n";
    cout << "\t\tEnter Desired Username(without_spaces) : ";
    cin >> uname;
    cout << "\n\n\t\tEnter Desired Password(without_spaces) : ";
    cin >> pass;
    while(fin.read((char *)&u,sizeof(u)))
    {
        if(u.check_username(uname))
        {
            flag=0;
            break;
        }
        num = u.uidd();
    }
    fin.close();
    cout << "\n\t\t\t\t\tCONNECTING\n\n";
    loading();
    ofstream fout("login_data.dat",ios::binary|ios::app);
    if(flag==1)
    {
        cout << "\n\n\t\t\t\tSuccess!!";
        num++;
        t.builduser(uname,pass,num);
        fout.write((char *)&t,sizeof(t));
    }
    else
    {
        cout << "\n\n\t\t\t\tUsername exists!!!" << endl;
    }
    fout.close();
    char ch;
    cout << "\n\n\n\t\t\tPress m for main menu.\n";
    cout << "\t\t\tPress any other key to exit.\n\t\t\t";
    ch = getch();
    ch = tolower(ch);
    if (ch == 'm')
        main_menu();
    else
        exits(0);

}

void no_login()
{
    char choice;
    system("cls");
    cout << "\n\n\t\t\t\tLogin Unsuccessful" << endl;
    char ch;
    cout << "\n\n\n\t\t\tPress m for main menu.\n";
    cout << "\t\t\tPress any other key to exit.\n\t\t\t";
    ch = getch();
    ch = tolower(ch);
    if(ch == 'm')
        main_menu();
    else
        exits(0);
}

void login()
{
    system("cls");
    int flag=0;
    char name[50],pas[15];
    ifstream fin("login_data.dat",ios::binary);
    cout << "\n\n\t\t\t\t\tLogin : \n\n\n";
    cout << "\n\n\t\t\t\tUsername : ";
    cin >> name;
    cout << "\n\n\t\t\t\tPassowrd : ";
    int i=0;
    do
    {
        pas[i] = getch();
        if(pas[i]=='\b' && i!=0)
        {
            cout << "\b \b";
            i--;
        }
        else if (pas[i++]!='\r')
            cout << "*";
        else
            break;
    }
    while(1);
    pas[i-1]='\0';
    cout << "\n\n\n\n\t\t\t\t\t CONNECTING\n\n";
    loading();
    while(fin.read((char *)&u,sizeof(u)))
    {
        if(u.check_username(name))
        {
            if(u.check_pass(pas))
                flag=1;
            else
                flag=0;
            break;
        }
        else
            flag=0;
    }
    fin.close();
    if(flag==0)
    {
        no_login();
    }
    else
    {
        cout << "Success" << endl;
        logged_in_user = u;
        logged_in_user.open_user();
        user_menu();
    }
}

void exports()
{
    system("cls");
    char a[200];
    char date[9];
    _strdate(date);
    char time[11];
    _strtime(time);
    cout << "\n\t   Enter name of Destination File : ";
    cin >> a;
    for(int i=0 ; a[i]!='\0' ; i++)
    {
        if(!(isalnum(a[i])))
            a[i]='0';
    }
    strcat(a,".txt");
    system("cls");
    ofstream t(a);
    t << "--Movies updated till " << time << "  " << date[3] << date[4] << date[2] << date[0] << date[1] << date[5] << date[6] << date[7] << "--" << endl << endl;
    t.close();
    ifstream in("movies.dat",ios::binary);
    movie m;
    int n=1;
    cout << "\n\n\t\t\t\t\tEXPORTING\n\n";
    loading();
    while(in.read((char *)&m,sizeof(m)))
    {
        m.txt_full(a,n++);
    }
    cout << "\n\n\n\t\t\tCheck for \" " << a << " \"\n";
    char ch;
    cout << "\n\n\t\t\tPress m for main menu.\n";
    do
    {
        ch = getch();
        ch = tolower(ch);
        if(ch == 's')
            search();
        else if(ch == 'm')
        {
            if(logged_in_user.flagg()==1)
                user_menu();
            else
                main_menu();
        }
    }
    while(1);
}

void watchlist()
{
    system("cls");
    int flag;
    char ch,input[100];
    cout << "\n\t\t\t\t\t  WATCHLIST : \n\n";
    cout << "\t\t\t\t\t 1. Display" << endl << endl;
    cout << "\t\t\t\t\t 2. Add" << endl;
    char nam[50];
    char n;
    n = getch();
    movie t;
    switch(n)
    {
    case '1':
        cout << "\n";
        logged_in_user.list();
        break;
    case '2':
    {
        flag=0;
        int jj=0; //checks if movie is already in watch list
        ifstream fin("movies.dat",ios::binary);
        cout << "\n\t\t\t\tEnter name of movie to add : ";
        fflush(stdin);
        cin.getline(nam,50);
        cout << "\n\n\n\n\t\t\t\t\t   SEARCHING\n\n";
        loading();
        system("cls");
        while(fin.read((char *)&t,sizeof(t)))
        {
            if(t.check_name(nam))
            {
                flag++;
                nam[0] = toupper(nam[0]);
                for(int x=1 ; x<strlen(nam) ; x++)
                {
                    if(nam[x-1]==' ')
                        nam[x] = toupper(nam[x]);
                    else
                        nam[x] = tolower(nam[x]);
                }
                logged_in_user.set_watchlist(nam,jj);
                break;
            }
        }
        fin.close();
        if(flag==0)
            cout << "\n\n\t\t\t\tSorry No matches found\n";
        else if(jj==0)
        {
            cout << "\n\n\t\t\t\tSUCCESS\n";
            user temps;
            ifstream in("login_data.dat",ios::binary);
            ofstream out("temp.dat",ios::binary);
            while(in.read((char *)&temps,sizeof(temps)))
            {
                if(temps.uidd() == logged_in_user.uidd())
                {
                    out.write((char *)&logged_in_user,sizeof(logged_in_user));
                }
                else
                {
                    out.write((char *)&temps,sizeof(temps));
                }

            }
            out.close();
            in.close();
            ofstream out1("login_data.dat",ios::binary);
            ifstream in1("temp.dat",ios::binary);
            while(in1.read((char *)&temps,sizeof(temps)))
            {
                out1.write((char *)&temps,sizeof(temps));
            }
        }
        break;
    }
    default :
        cout << "\t\t\t\tINVALID\n";
    }
    cout << "\n\n\t\t\tPress w for watch list menu.\n";
    cout << "\t\t\tPress m for main menu.\n";
    do
    {
        ch = getch();
        ch = tolower(ch);
        if(ch == 'w')
            watchlist();
        else if(ch == 'm')
        {
            if(logged_in_user.flagg()==1)
                user_menu();
            else
                main_menu();
        }
    }
    while(1);
}

void random_movie()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\tRANDOMIZING\n\n\n";
    loading();
    system("cls");
    ifstream fin ("movies.dat",ios::binary);
    movie t;
    int len=1,random,i=0;
    while(fin.read((char *)&t,sizeof(t)))
    {
        len++;
    }
    fin.close();
    random = (rand()+rand())%len;
    fin.open ("movies.dat",ios::binary);
    while(fin.read((char *)&t,sizeof(t)))
    {
        i++;
        if(i == random)
        {
            t.out_full();
            break;
        }

    }
    fin.close();
    char ch;
    cout << "\n\n\t\t\tPress m for main menu.\n";
    do
    {
        ch = getch();
        ch = tolower(ch);
        if(ch == 'm')
        {
            if(logged_in_user.flagg()==1)
                user_menu();
            else
                main_menu();
        }
    }
    while(1);
}

void add_movie()
{
    system("cls");
    movie temp;
    char ch;
    temp.in();
    int flag=0;
    movie t;
    ifstream fin("movies.dat" , ios::binary);
    while(fin.read((char *)&t,sizeof(t)))
    {
        if(t.check_name(temp))
        {
            flag++;
        }
    }
    fin.close();
    if(flag==0)
    {
        ofstream fout("movies.dat",ios :: binary | ios :: app);
        fout.write((char *)&temp,sizeof(temp));
        cout << "\n\n\t\t\t\tSuccess!!" << endl;
        fout.close();
    }
    else
        cout << "\t\t\t\tA movie with the same name exists!!!" << endl;
    cout << "\n\n\t\t\tPress m for main menu.\n";
    do
    {
        ch = getch();
        ch = tolower(ch);
        if(ch == 'm')
            user_menu();
    }
    while(1);
}

void search()
{
    system("cls");
    int yr;
    char ch,input[100];
    cout << "\n\t\t\t\t   SEARCH ON THE BASIS OF : \n\n\n";
    cout << "\t\t\t\t       1. Name" << endl << endl;
    cout << "\t\t\t\t       2. Director" << endl << endl;
    cout << "\t\t\t\t       3. Year" << endl << endl;
    cout << "\t\t\t\t       4. Rating" << endl << endl;
    cout << "\t\t\t\t       5. Exit To Main Menu" << endl << endl;
    char nam[50];
    char n;
    ifstream fin("movies.dat",ios :: binary);
    int flag =0;
    float rat;
    movie t;
    n = getch();
    switch(n)
    {
    case '1':
        flag=0;
        cout << "\n\t\t\t\tEnter name of movie : ";
        fflush(stdin);
        cin.getline(nam,50);
        cout << "\n\n\n\n\t\t\t\t\t   SEARCHING\n\n";
        loading();
        system("cls");
        cout << "\n\n";
        while(fin.read((char *)&t,sizeof(t)))
        {
            int x = t.check_name(nam);
            if(x)
            {
                flag++;
                if(x == 7)
                    t.out_full();
                else
                {
                    cout << flag << " >> ";
                    t.out_name();
                }
            }
        }
        if(flag==0)
            cout << "\n\n\t\t\t\tSorry No matches found\n";
        fin.close();
        break;

    case '2':
        flag=0;
        cout << "\n\t\t\t\tEnter name of director : ";
        fflush(stdin);
        cin.getline(nam,50);
        cout << "\n\n\n\n\t\t\t\t\t   SEARCHING\n\n";
        loading();
        system("cls");
        cout << "\n\n\t\t\tMovies matching the criteria are : " << endl << endl;
        while(fin.read((char *)&t,sizeof(t)))
        {
            if(t.check_director(nam))
            {
                flag++;
                cout << flag << " >> ";
                t.out_name();
            }
        }
        fin.close();
        if(flag==0)
            cout << "\n\n\t\t\t\tSorry No matches found\n";
        fin.close();
        break;

    case '3':
        flag=0;
        cout << "\n\t\t\t\tEnter year of the movie : ";
        fflush(stdin);
        cin >> yr;
        cout << "\n\n\n\n\t\t\t\t\t   SEARCHING\n\n";
        loading();
        system("cls");
        cout << "\n\n\t\t\tMovies matching the criteria are : " << endl << endl;
        while(fin.read((char *)&t,sizeof(t)))
        {
            if(t.check_year(yr))
            {
                flag++;
                cout << flag << " >> ";
                t.out_name();
            }
        }
        fin.close();
        if(flag==0)
            cout << "\n\n\t\t\t\tSorry No matches found\n";
        fin.close();
        break;

    case '4':
        flag=0;
        float u,l;
        cout << "\n\t\t\t\tEnter lower limit of rating : ";
        cin >> l;
        cout << "\n\t\t\t\tEnter upper limit of rating : ";
        cin >> u;
        cout << "\n\n\n\n\t\t\t\t\t   SEARCHING\n\n";
        loading();
        system("cls");
        cout << "\n\n\t\t\tMovies matching the criteria are : " << endl << endl;
        while(fin.read((char *)&t,sizeof(t)))
        {
            if(t.give_rating()>=l && t.give_rating()<=u)
            {
                flag++;
                cout << flag << " >> ";
                t.out_name();
            }
        }
        fin.close();
        if(flag==0)
            cout << "\n\n\t\t\t\tSorry No matches found\n";
        fin.close();
        break;

    case '5':
        if(logged_in_user.flagg()==1)
            user_menu();
        else
            main_menu();
        break;

    default:
        cout << "\n\n\t\t\t\tINVALID\n\n";
        break;
    }
    cout << "\n\n\t\t\tPress s for search menu.\n";
    cout << "\t\t\tPress m for main menu.\n";
    do
    {
        ch = getch();
        ch = tolower(ch);
        if(ch == 's')
            search();
        else if(ch == 'm')
        {
            if(logged_in_user.flagg()==1)
                user_menu();
            else
                main_menu();
        }
    }
    while(1);
}

void edit_movie()
{
    system("cls");
    char nam[50];
    movie t;
    int flag=0;
    ifstream fin("movies.dat",ios :: binary);
    ofstream temp("temp.dat",ios :: binary);
    cout << "\n\n\t\tEnter name of the movie you want to edit : ";
    fflush(stdin);
    cin.getline(nam,50);
    cout << "\n\n\n\n\t\t\t\t\t   SEARCHING\n\n";
    loading();
    system("cls");
    cout << "\n\n\n\n";
    while(fin.read((char *)&t,sizeof(t)))
    {
        if(t.check_name_edit(nam))
        {
            flag++;
            do
            {
                char input[50];
                system("cls");
                cout << "\t\t\t\tEdit Menu for\n";
                t.out_full();
                cout << endl << endl;
                cout << "\t\t\tYou want to edit : " << endl;
                cout << "\t\t\t1. Name" << endl;
                cout << "\t\t\t2. Director" << endl;
                cout << "\t\t\t3. Year" << endl;
                cout << "\t\t\t4. Rating" << endl;
                cout << "\t\t\t5. Synopsis" << endl;
                cout << "\n\t\t\t";
                char n;
                n = getch();
                cout << endl;
                switch(n)
                {
                case '1':
                    char a[50];
                    cout << "New Name : ";
                    fflush(stdin);
                    cin.getline(a,50);
                    t.set_name(a);
                    break;
                case '2':
                    char b[50];
                    cout << "New Director : ";
                    fflush(stdin);
                    cin.getline(b,50);
                    t.set_director(b);
                    break;
                case '3':
                    int y;
                    cout << "New Year : ";
                    fflush(stdin);
                    cin >> y;
                    t.set_year(y);
                    break;
                case '4':
                    float r;
                    cout << "New Rating : ";
                    fflush(stdin);
                    cin >> r;
                    t.set_rating(r);
                    break;
                case '5':
                    char abc[300];
                    cout << "New Synopsis : ";
                    fflush(stdin);
                    cin.getline(abc,300);
                    t.set_synopsis(abc);
                    break;
                default:
                    cout << "\n\n\t\t\t\tINVALID\n\n";
                    break;
                }
                char ch;
                cout << "\n\n\t\t\tPress e to edit more.\n";
                cout << "\t\t\tPress any other key to save changes.\n\t\t\t";
                ch = getch();
                if(ch !='e' || ch!='E' || ch == '\r');
                break;
            }
            while(1);
        }
        temp.write((char *)&t,sizeof(t));
    }
    temp.close();
    fin.close();
    if(flag==0)
        cout << "\n\n\t\t\t\tSorry No matches found\n";
    else
    {
        movie f;
        ifstream in("temp.dat",ios::binary);
        ofstream out("movies.dat",ios::binary);
        while(in.read((char *)&f,sizeof(f)))
        {
            out.write((char *)&f,sizeof(f));
        }
        cout << "SUCCESSFULLY EDITED";
        in.close();
        out.close();
    }
    char ch;
    cout << "\n\n\t\t\tPress m for main menu.\n";
    do
    {
        ch = getch();
        ch = tolower(ch);
        if(ch == 'm')
            user_menu();
    }
    while(1);

}

void user_menu()
{
    system("cls");
    int l;
    char n;
    cout << endl;
    cout << "        ";
    cout << char(218);
    for(int i=0 ; i<84 ; i++)
        cout << char(196);
    cout << char(191);
    cout << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                               C++ MOVIE DATA BASE                                  " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                        >>>>>>>>> WELCOME ";
    logged_in_user.print_name(l);
    cout << " <<<<<<<<<";
    for(int i=0 ; i<32-l ; i++)
        cout << " ";
    cout << char(179) << endl;;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 1. Add Movie                                       " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 2. Search                                          " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 3. Edit Movie                                      " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 4. Watch List                                      " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 5. Random Movie                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 6. Export Movie Database to txt                    " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 7. Logout                                          " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 8. Exit                                            " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        ";
    cout << char(192);
    for(int i=0 ; i<84 ; i++)
        cout << char(196);
    cout << char(217);
    cout << endl << endl << endl << endl << endl ;
    bottom_bar();
    n = getch();
    switch(n)
    {
    case '1':
        add_movie();
        break;

    case '2':
        search();
        break;
    case '3':
        edit_movie();
        break;
    case '4':
        watchlist();
        break;
    case '5':
        random_movie();
        break;
    case '6':
        exports();
        break;
    case '7':
        logged_in_user.close_user();
        main_menu();
        break;
    case '8':
        exits(0);
    default:
        user_menu();
    }
}

void main_menu()
{
    system("cls");
    char n;
    cout << endl;
    cout << "        ";
    cout << char(218);
    for(int i=0 ; i<84 ; i++)
        cout << char(196);
    cout << char(191);
    cout << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                         >>>>>>>>> WELCOME TO CMDB <<<<<<<<<                        " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                               C++ MOVIE DATA BASE                                  " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 1. Search                                          " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 2. Create new User                                 " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 3. Login                                           " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 4. Random Movie                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 5. Export Movie Database to txt                    " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        " << char(179) << "                                 6. Exit                                            " << char(179) << endl;
    cout << "        " << char(179) << "                                                                                    " << char(179) << endl;
    cout << "        ";
    cout << char(192);
    for(int i=0 ; i<84 ; i++)
        cout << char(196);
    cout << char(217);
    cout << "\n\n\t\t\t\t\t    TOP 3\n\n";
    ifstream fin("movies.dat",ios::binary);
    movie temp;
    for(int i=1 ; i<=3 ; i++)
    {
        fin.read((char*)&temp,sizeof(temp));
        cout << "\t\t\t      # " << i << " ";
        temp.out_name();
    }
    fin.close();
    bottom_bar();
    n = getch();
    switch(n)
    {
    case '1':
        search();
        break;
    case '2':
        createuser();
        break;
    case '3':
        login();
        break;
    case '4':
        random_movie();
        break;
    case '5':
        exports();
        break;
    case '6':
        exits(0);
    default:
        main_menu();
    }
}

void splash()
{
    char a[][30] = {" Fetching Movies"," Fetching Directors","\tLoading menus"," Unleashing Magnificence","\t    Finishing"};
    for(int i=0 ; i<30 ; i++)
    {
        system("cls");
        cout << "\n\n\n\n";
        cout << "\t\t\t      _____     __  __     _____      ____  " << endl;
        cout << "\t\t\t     / ____|   |  \\/  |   |  __ \\    |  _ \\ " << endl;
        cout << "\t\t\t    | |        | \\  / |   | |  | |   | |_) |" << endl;
        cout << "\t\t\t    | |        | |\\/| |   | |  | |   |  _ < " << endl;
        cout << "\t\t\t    | |____    | |  | |   | |__| |   | |_) |" << endl;
        cout << "\t\t\t     \\_____|   |_|  |_|   |_____/    |____/ " << endl;
        cout << "\n\n\n\t\t\t\t\t\n\t\t\t\t\t   GUPTA & NAYYAR \n";
        //cout << "\n\t\t\t\t\t    LODAING\n\n\t\t\t\t  ";
        cout << "\n\n\t\t\t\t       " << a[i/6] << "\n\n\t\t\t\t  ";
		for(int j=0 ; j<i ; j++)
            cout << char(219);
        
        Sleep(80);
    }
    cout << "\n\n\t\t\t\t       Hit SpaceBar To Enter\n\n";
    char b = getch();
    if(b == ' ')
        main_menu();
    else
        exit(0);
}
