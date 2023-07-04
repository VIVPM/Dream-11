#include<bits/stdc++.h>
using namespace std;

class SportsLeague
{
public:
    string name;
    int type;

    SportsLeague(string n,int t):name(n),type(t) {}

    virtual void display() = 0;
};

class player
{
public:
    string name;
    bool captain=0,vice_captain,selected=0;
    int type,p_no,points;
    int runs = 0;
    float strike_rate = 120;
    int six = 1,four = 0;
    int Balls_faced = 0;
    int wickets=0;
    int maiden_over = 1;
    int overs_bowled = 4;
    float Economy = 0;
    int total_runs = 28;
    int catches = 2;
    int run_out = 3;

    player()
    {

    }

    virtual void Calculatepoints()
    {

    }
};

class Batsman:public player
{
public:
    void Calculatepoint()
    {
        if(runs >= 30 && runs < 50)
        {
            points = points + 4 + 2 * six + four + runs;
        }

        else if(runs >= 50 && runs < 100)
        {
            points = points + 4 + 8 + 2 * six + four + runs;
        }

        else if(runs >= 100 && strike_rate >= 100)
        {
            points = points + 4 + 8 + 16 + 2 * six + four + runs + 6;
        }

        else if(runs >= 30  && runs < 50 && strike_rate >= 100)
        {
            points = points + 4 + 2 * six + four + runs + 6;
        }

        else if(runs >= 50 && runs < 100 && strike_rate >= 100)
        {
            points = points + 4 + 8 + 2 * six + four + runs + 6;
        }

        else if(runs == 0)
        {
            points = points - 2;
        }

        else
        {
            points = points + runs + four + 2 * six + 6;
        }
    }
};

class Bowler:public player
{
public:
    void Calculatepoint()
    {
        Economy = total_runs/overs_bowled;
        if(wickets >= 1)
        {
            points = points + (wickets * 25);
        }

        else if(maiden_over > 0)
        {
            points = points + 12 * maiden_over;
        }

        else if(Economy <= 6)
        {
            points = points + 6;
        }

        else if(Economy > 6 && Economy <= 8)
        {
            points = points + 4;
        }

        else if(Economy > 8)
        {
            points = points - 2;
        }

        else if(wickets >= 1 && maiden_over > 0)
        {
            points = points + wickets * 25 + 12 * maiden_over;
        }

        else if(wickets >= 1 && Economy <= 6)
        {
            points = points + wickets * 25 + 6;
        }

        else if(wickets >= 1 && Economy > 6 && Economy <= 8)
        {
            points = points + wickets * 25 + 4;
        }

        else if(wickets >= 1 && Economy > 8)
        {
            points = points + wickets * 25 - 2;
        }

        else if(maiden_over > 0 && Economy <= 6)
        {
            points = points + maiden_over * 12 + 6;
        }

        else if(maiden_over > 0 && Economy > 6 && Economy <= 8)
        {
            points = points + maiden_over * 12 + 4;
        }

        else
        {
            points = points + maiden_over * 12 - 2;
        }

    }
};

class Fielder:public player
{
public:
    void Calculatepoints()
    {
        if(catches <= 3)
        {
            points = (catches * 8);
        }

        else if(catches >= 3)
        {
            points = (catches * 8) + 4;
        }

        else if(run_out >= 1)
        {
            points = (run_out * 12);
        }

        else if(run_out >= 1 && catches <= 3)
        {
            points = (run_out * 12) + (catches * 8);
        }

        else
        {
            points = (run_out * 12) + (catches * 8) + 4;
        }
    }
};

class team
{
public:
    Batsman bat[10];
    Bowler ball[10];
    string name;
    int id;
    static int count1;
    player p[15];
    team(string name)
    {
        this->name=name;
        id = ++count1;
    }

    team() {}

    void read_players(int k)
    {
        ifstream ifs;
        if(k==1)
        {
            ifs.open("rcb.txt");
        }
        else
        {
            ifs.open("csk.txt");
        }
        string n;
        int type_in_file,pno,r,w,f;
        for(int i=0; i<15; i++)
        {

            ifs>>pno;
            ifs>>n;
            ifs>>type_in_file;
            ifs>>r;
            ifs>>w;
            ifs>>f;
            p[i].four=f;
            p[i].name=n;
            p[i].type=type_in_file;
            p[i].p_no=pno;
            p[i].runs=r;
            p[i].wickets=w;
        }

        ifs.close();
    }

    void show(team t1,team t2)
    {
        int i;
        cout<<"\n\nBATSMEN ARE\n\n";
        for(i=0; i<15; i++)
        {
            if(t1.p[i].type==1)
            {
                cout<<t1.p[i].p_no<<"    \t"<<t1.p[i].name<<endl;
            }
            if(t2.p[i].type==1)
            {
                cout<<t2.p[i].p_no<<"    \t"<<t2.p[i].name<<endl;
            }

        }

        cout<<"\n\nBOWLERS ARE\n";
        for(i=0; i<11; i++)
        {
            if(t1.p[i].type==0)
            {
                cout<<t1.p[i].p_no<<"    \t"<<t1.p[i].name<<endl;
            }

            if(t2.p[i].type==0)
            {
                cout<<t2.p[i].p_no<<"    \t"<<t2.p[i].name<<endl;
            }

        }
    }
};

class IPL:public SportsLeague
{
public:

    IPL(string n,int t):SportsLeague(n,t)
    {

    }

    int getteam(int i)
    {
        return -1;
    }

    void display()
    {
        cout << "Name = \t" << name << endl;
        cout << "Type = \t" << type << endl;
    }
     team make_team(string);

};

team IPL::make_team(string n)
{
    team a1;
    a1.name=n;
    return a1;
}
class FootBallLeague:public SportsLeague
{
public:
    FootBallLeague(string n,int t):SportsLeague(n,t) {}

    void display()
    {
        cout << "Name = \t" << name << endl;
        cout << "Type = \t" << type << endl;
    }
};

class BasketBallLeague:public SportsLeague
{
public:
    BasketBallLeague(string n,int t):SportsLeague(n,t) {}

    void display()
    {
        cout << "Name = \t" << name << endl;
        cout << "Type = \t" << type << endl;
    }
};

class Exception
{
public:
    string msg;
    int id;

    Exception(string m,int i):msg(m),id(i) {}

    void show()
    {
        cout << "Message displayed : \t" <<  msg << endl;
        cout << "Message id : \t" << id << endl;
    }
};

class user
{
public:
    string name;
    team user_team;
    int bat_count=0,ball_count=0;
    user(string name)
    {
        this->name=name;
    }

    int s=0;
    team select_batsmen(team t1,team t2,int isbat)
    {
        int rep;
        if(isbat)
        {
            cout<<"ENTER PLAYER NUMBER TO SELECT TO YOUR BATTERS LIST.\nYOU HAVE TO SELECT EXACTLY 6 BATTERS"<<endl;
            rep=6;
        }
        else
        {
            cout<<"ENTER PLAYER NUMBER TO SELECT TO YOUR BOWLERS LIST.\nYOU HAVE TO SELECT EXACTLY 5 BOWLERS"<<endl;
            rep=5;
        }


        int pno;
        for(int j=0; j<rep; j++)
        {
            cin>>pno;
            for(int i=0; i<11; i++)
            {
                if(t1.p[i].p_no==pno)
                {
                    if(t1.p[i].selected==1)
                    {
                        cout<<"PLAYER ALREADY SELECTED. PLEASE SELECT DIFFERENT PLAYER.\n";
                        s--;
                        j--;
                    }
                    else
                    {
                        user_team.p[s]=t1.p[i];
                        if(isbat)
                        {
                            user_team.bat[bat_count].name=t1.p[i].name;
                            user_team.bat[bat_count].runs=t1.p[i].runs;
                            user_team.bat[bat_count].wickets=t1.p[i].wickets;
                            bat_count++;
                        }

                        else
                        {
                            user_team.ball[ball_count].name=t1.p[i].name;
                            user_team.ball[ball_count].runs=t1.p[i].runs;
                            user_team.ball[ball_count].wickets=t1.p[i].wickets;
                            ball_count++;
                        }
                        t1.p[i].selected=1;

                    }

                }
                else if(t2.p[i].p_no==pno)
                {
                    if(t2.p[i].selected==1)
                    {
                        cout<<"PLAYER ALREADY SELECTED. PLEASE SELECT DIFFERENT PLAYER.\n";
                        s--;
                        j--;
                    }
                    else
                    {
                        user_team.p[s]=t2.p[i];
                        if(isbat)
                        {
                            user_team.bat[bat_count].name=t2.p[i].name;
                            user_team.bat[bat_count].runs=t2.p[i].runs;
                            user_team.bat[bat_count].wickets=t2.p[i].wickets;
                            bat_count++;
                        }

                        else
                        {
                            user_team.ball[ball_count].name=t2.p[i].name;
                            user_team.ball[ball_count].runs=t2.p[i].runs;
                            user_team.ball[ball_count].wickets=t2.p[i].wickets;
                            ball_count++;
                        }
                        t1.p[i].selected=1;
                        t2.p[i].selected=1;
                    }
                }
            }

            s++;
        }


        return user_team;
    }
    void make_captain()
    {
         cout<<"ENTER PLAYER NUMBER TO WHOM YOU WANT TO MAKE AS CAPTAIN\n";
        int cap;
        cin>>cap;
        for(int i=0; i<11; i++)
        {
            if(user_team.p[i].p_no==cap)
            {
                user_team.p[i].captain=1;
            }
        }
    }
    void show()
    {
        cout<<"USER SELECTED TEAM IS \n"<<endl;
        for(int i=0; i<11; i++)
        {
            cout<<user_team.p[i].name<<endl;
        }
    }

};

int team::count1 = 0;
void menu()
{
      int selection;
      SportsLeague *s[2] = {new FootBallLeague("UEFA",1),new BasketBallLeague("NBA",2)};

     try
    {
        for(int i=0;i<1;i++)
        {
            cout << "SELECT YOUR LEAGUE" << endl;
            cout<<"1. FOOTBALL LEAGUE"<<endl;
            cout<<"2. BASKET BALL"<<endl;
            cout<<"3. IPL LEAGUE"<<endl;
            cout<<endl;
            cin >> selection;
            if(selection == 1)
            {
                s[0]->display();
                i--;
                throw Exception("FOOTBALL GAME LEAGUE IS NOT CURRENTLY AVAILABLE",12);

            }

            else if(selection == 2)
            {
                s[1]->display();
                i--;
                throw Exception("BASKETBALL LEAGUE GAMES ARE NOT CURRENTLY AVAILABLE",13);
            }

            else if(selection == 3)
            {
                cout << "THE CONTEST IS AVAILABLE AND MATCH BETWEEN RCB AND CSK IS CURRENTLY AVAILABLE" << endl;
                cout << "MAK YOUR TEAM NOW!!\n" << endl;

            }
            else
            {
                cout<<"\nYOU HAVE ENTERED WRONG CHOICE. PLEASE ENTER CORRECT OPTION"<<endl;
                i--;
            }
        }
    }

    catch(Exception &e)
    {
        e.show();
        menu();
    }
}
int main()
{


    menu();
    IPL *i = new IPL("IPL",0);


    team t1("RCB");
    team t2("CSK");
    user u1("KRISH");
    user u2("RAVI");
    t1.read_players(1);
    t2.read_players(0);
    team dummy;
    dummy.show(t1,t2);
    team user_team1,user_team2;
    user_team1=u1.select_batsmen(t1,t2,1);
    user_team1=u1.select_batsmen(t1,t2,0);
    u1.make_captain();
    cout<<"TEAM OF USER 1 IS\n";
    u1.show();
    cout << endl << endl << endl;
    cout<<"SELECT YOUR TEAM NOW"<<endl;
    dummy.show(t1,t2);
    cout<<"ENTER TEAM OF USER 2"<<endl;
    user_team2=u2.select_batsmen(t1,t2,1);
    user_team2=u2.select_batsmen(t1,t2,0);
    u2.make_captain();
    cout<<"TEAM OF USER 2 IS\n";
    u2.show();





    int total1=0,total2=0;
    for(int i=0; i<6; i++)
    {
        user_team1.bat[i].Calculatepoint();
        total1=total1+user_team1.bat[i].points;
        user_team2.bat[i].Calculatepoint();
        total2=total2+user_team2.bat[i].points;
    }

    for(int i=0; i<5; i++)
    {
        user_team1.ball[i].Calculatepoint();
        total1=total1+user_team1.ball[i].points;
        user_team2.ball[i].Calculatepoint();
        total2=total2+user_team2.ball[i].points;
    }

    cout<<"POINTS SCORED BY USER 1 IS "<<total1<<endl<<"POINTS SCORED BY USER 2 IS "<<total2<<endl;

    if(total1>total2)
    {
        cout<<endl<<"USER 1 HAS WON THE GAME...  CONGRATULATIONS ..."<<endl;

    }

    else if(total2>total1)
    {
        cout<<endl<<"USER 2 HAS WON THE GAME...  CONGRATULATIONS..."<<endl;
    }

    else
    {
        cout<<endl<<"POINTS OF USER 1 AND USER 2 ARE SAME. GAME DRAW!!!!  "<<endl;
    }


    return 0;
}
