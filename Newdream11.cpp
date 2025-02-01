#include <bits/stdc++.h>
using namespace std;

class SportsLeague
{
public:
    string name;
    int type;

    SportsLeague(string n, int t) : name(n), type(t) {}

    virtual void display() = 0;
};

class cricketPlayer
{
public:
    string name;
    bool captain = 0, vice_captain, selected = 0;
    int type, p_no, points = 0;
    int runs = 0;
    float strike_rate = 120;
    int six = 1, four = 0;
    int Balls_faced = 0;
    int wickets = 0;
    int maiden_over = 1;
    int overs_bowled = 4;
    float Economy = 0;
    int total_runs = 28;
    int catches = 2;
    int run_out = 3;

    cricketPlayer() {}

    virtual void Calculatepoints() {}
};

class footballPlayer
{
public:
    string name;
    bool captain = 0, vice_captain, selected = 0;
    int type,p_no, points=0;
    int goals_scored = 0;
    int assists = 3;
    int shots_on_target = 5;
    int passes_completed = 2;
    int tackles = 0;

    footballPlayer() {}

    virtual void Calculatepoints() {}
};

class basketballPlayer
{
public:
    string name;
    bool captain = 0, vice_captain = 0, selected = 0;
    int type,p_no;
    int points = 0;
    int rebounds = 0;
    int assists = 0;
    int steals = 0;
    int blocks = 3;
    int three_pointers_made = 4;
    int turnovers = 1;
    int two_pointers_made = 2;
    int free_throws_made = 5;

    basketballPlayer() {}

    virtual void Calculatepoints() {}
};

class Striker : public footballPlayer
{
public:
    void Calculatepoints()
    {
        if (goals_scored >= 1 && goals_scored < 3)
        {
            points += 10 * goals_scored; // 10 points for each goal
        }

        else if (goals_scored >= 3)
        {
            points += 10 * goals_scored + 10; // Bonus 10 points for a hat-trick
        }

        if (assists >= 1)
        {
            points += 5 * assists; // 5 points for each assist
        }

        if (shots_on_target >= 1)
        {
            points += 2 * shots_on_target; // 2 points for each shot on target
        }

        if (passes_completed >= 20 && passes_completed < 50)
        {
            points += 5; // 5 points for completing 20-49 passes
        }
        else if (passes_completed >= 50)
        {
            points += 10; // 10 points for completing 50+ passes
        }

        // Subtract points for poor performance
        if (goals_scored == 0 && assists == 0 && shots_on_target < 2)
        {
            points -= 5; // Penalty for poor contribution
        }
    }
};

class Defender : public footballPlayer
{
public:
    void Calculatepoints()
    {
        if (goals_scored >= 1)
        {
            points += 15 * goals_scored; // 15 points per goal for a defender
        }

        // Points for assists
        if (assists >= 1)
        {
            points += 7 * assists; // 7 points per assist
        }

        // Points for shots on target
        if (shots_on_target >= 1)
        {
            points += 3 * shots_on_target; // 3 points per shot on target
        }

        // Points for passes completed
        if (passes_completed >= 20 && passes_completed < 50)
        {
            points += 5; // 5 points for completing 20-49 passes
        }
        else if (passes_completed >= 50)
        {
            points += 10; // 10 points for completing 50+ passes
        }

        // Points for tackles
        if (tackles >= 5 && tackles < 10)
        {
            points += 10; // 10 points for 5-9 tackles
        }
        else if (tackles >= 10)
        {
            points += 20; // 20 points for 10+ tackles
        }

        // Penalty for poor contribution (low tackles and no goals/assists)
        if (tackles < 3 && goals_scored == 0 && assists == 0)
        {
            points -= 5; // Deduct 5 points for poor performance
        }
    }
};

class Shooter: public basketballPlayer
{
public:
    void Calculatepoints()
    {
        points += three_pointers_made * 3;  // 3 points for each three-pointer
        points += two_pointers_made * 2;    // 2 points for each two-pointer
        points += free_throws_made;         // 1 point for each free throw

        // Additional points based on other statistics
        if (rebounds >= 10)
        {
            points += 5;  // Bonus points for double-digit rebounds
        }
        if (assists >= 10)
        {
            points += 5;  // Bonus points for double-digit assists
        }
        if (steals >= 5)
        {
            points += 5;  // Bonus points for 5 or more steals
        }
        if (blocks >= 5)
        {
            points += 5;  // Bonus points for 5 or more blocks
        }

        // Additional conditions for exceptional performance
        if (three_pointers_made >= 5)
        {
            points += 5;  // Bonus points for making 5 or more three-pointers
        }
        if (two_pointers_made >= 10)
        {
            points += 5;  // Bonus points for making 10 or more two-pointers
        }
        if (free_throws_made >= 10)
        {
            points += 5;  // Bonus points for making 10 or more free throws
        }
    }
};

class Guardians: public basketballPlayer
{
public:
    void Calculatepoints()
    {
        points += rebounds;          // 1 point per rebound
        points += assists;           // 1 point per assist
        points += steals * 2;        // 2 points per steal
        points += blocks * 2;        // 2 points per block

        // Deduct points for turnovers
        points -= turnovers;         // Deduct 1 point per turnover

        // Bonus points for exceptional defensive performance
        if (rebounds >= 10)
        {
            points += 5;  // Bonus points for double-digit rebounds
        }
        if (steals >= 5)
        {
            points += 5;  // Bonus points for 5 or more steals
        }
        if (blocks >= 5)
        {
            points += 5;  // Bonus points for 5 or more blocks
        }

        // Additional conditions for all-around performance
        if (assists >= 10)
        {
            points += 5;  // Bonus points for double-digit assists
        }
        if (turnovers <= 2)
        {
            points += 5;  // Bonus points for 2 or fewer turnovers
        }
    }
};

// Class for Batsman-specific behavior
class Batsman : public cricketPlayer
{
public:
    void Calculatepoints()
    {
        if (runs >= 30 && runs < 50)
        {
            points = points + 4 + 2 * six + four + runs;
        }
        else if (runs >= 50 && runs < 100)
        {
            points = points + 4 + 8 + 2 * six + four + runs;
        }
        else if (runs >= 100 && strike_rate >= 100)
        {
            points = points + 4 + 8 + 16 + 2 * six + four + runs + 6;
        }
        else if (runs >= 30 && runs < 50 && strike_rate >= 100)
        {
            points = points + 4 + 2 * six + four + runs + 6;
        }
        else if (runs >= 50 && runs < 100 && strike_rate >= 100)
        {
            points = points + 4 + 8 + 2 * six + four + runs + 6;
        }
        else if (runs == 0)
        {
            points = points - 2;
        }
        else
        {
            points = points + runs + four + 2 * six + 6;
        }
    }
};

class Bowler : public cricketPlayer
{
public:
    void Calculatepoints()
    {
        // Calculate the bowler's economy rate
        Economy = total_runs / overs_bowled;

        // Points calculation based on wickets, maiden overs, and economy
        if (wickets >= 1)
        {
            points = points + (wickets * 25);
        }
        else if (maiden_over > 0)
        {
            points = points + 12 * maiden_over;
        }
        else if (Economy <= 6)
        {
            points = points + 6;
        }
        else if (Economy > 6 && Economy <= 8)
        {
            points = points + 4;
        }
        else if (Economy > 8)
        {
            points = points - 2;
        }
        else
        {
            points = points + maiden_over * 12 - 2;
        }

        if (catches <= 3)
        {
            points = (catches * 8);
        }
        else if (catches >= 3)
        {
            points = (catches * 8) + 4;
        }
        else if (run_out >= 1)
        {
            points = (run_out * 12);
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
    string name;
    string Cname;
    string Bname;
    int id;
    static int count1;
    vector<cricketPlayer*> p; // Store pointers to cricketPlayer objects
    vector<footballPlayer*>footPlayer;
    vector<basketballPlayer*>basketPlayer;

    team(string Cname,string name,string Bname)
    {
        this->name = name;
        this->Bname = Bname;
        this->Cname = Cname;
        id = ++count1;
    }

    team() {}

    void read_Players(const string &filename,const string &filename2,const string &filename3)
    {
        ifstream ifs(filename);
        string n;
        int type_in_file, pno, r, w, f;
        for (int i = 0; i < 15; i++)
        {
            ifs >> pno >> n >> type_in_file >> r >> w >> f;

            cricketPlayer *pl;
            if (type_in_file == 1)
            {
                pl = new Batsman(); // Create a Batsman object
            }
            else if (type_in_file == 2)
            {
                pl = new Bowler(); // Create a Bowler object
            }

            pl->p_no = pno;
            pl->name = n;
            pl->type = type_in_file;
            pl->runs = r;
            pl->wickets = w;
            pl->four = f;

            p.push_back(pl);
        }
        ifs.close();

        ifstream ifs1(filename2);
        int goals, tackles, assists;
        for (int i = 0; i < 15; i++)
        {
            ifs1 >> pno >> n >> type_in_file >> goals >> assists >> tackles;
            footballPlayer *f1;
            if(type_in_file==1)
            {
                f1 = new Striker();
            }
            else if(type_in_file==2)
            {
                f1 = new Defender();
            }

            f1->p_no=pno;
            f1->name = n;
            f1->type = type_in_file;
            f1->goals_scored = goals;
            f1->assists = assists;
            f1->tackles = tackles;

            footPlayer.push_back(f1);
        }

        ifs1.close();

        ifstream ifs2(filename3);
        int rebounds, steals;
        for (int i = 0; i < 15; i++)
        {
            ifs2 >> pno >> n >> type_in_file >> rebounds >> assists >> steals;
            basketballPlayer *b1;
            if(type_in_file==1)
            {
                b1 = new Shooter();
            }
            else if(type_in_file==2)
            {
                b1 = new Guardians();
            }

            b1->p_no=pno;
            b1->name = n;
            b1->type = type_in_file;
            b1->rebounds = rebounds;
            b1->assists = assists;
            b1->steals = steals;

            basketPlayer.push_back(b1);
        }

        ifs2.close();

    }


// Display cricketPlayers
    void show()
    {
        cout << "\nCricket Players in Team: " << name << endl;
        for (auto &pl : p)
        {
            cout << pl->p_no << "\t" << pl->name << endl;
        }
    }

    void showfootballPlayers()
    {
        cout << "\nFootball Players in Team: " << name << endl;
        for (auto &pl : footPlayer)
        {
            cout << pl->p_no << "\t" << pl->name << endl;
        }
    }
};


int team::count1 = 0; // Static member initialization

class User
{
public:
    string name;
    vector<cricketPlayer *> selected_cricketPlayers; // Store pointers to cricketPlayers
    vector<footballPlayer *> selected_footballPlayers;
    vector<basketballPlayer *>selected_basketballPlayers;
    int total_points = 0;

    User(string name)
    {
        this->name = name;
    }

    void displaycricketPlayerPool(vector<cricketPlayer *> &p, string team1, string team2)
    {
        cout << "Team 1: " << team1 << endl;
        cout << "Available Cricket Players:" << endl;
        cout << "Cricket Player No\tName\tType" << endl;
        for (int i = 0; i < p.size(); i++)
        {
            if (i < 15)
            {
                cout << p[i]->p_no << "\t\t" << p[i]->name << "\t"
                     << (p[i]->type == 1 ? "Batsman" : "Bowler") << endl;
                p[i]->selected = false;
            }
            else
                break;
        }

        cout << endl;
        cout << "Team 2: " << team2 << endl;
        cout << "Available Cricket Players:" << endl;
        for (int i = 15; i < p.size(); i++)
        {
            cout << p[i]->p_no << "\t\t" << p[i]->name << "\t"
                 << (p[i]->type == 1 ? "Batsman" : "Bowler") << endl;
            p[i]->selected = false;
        }
    }

    void displaybasketballPlayerPool(vector<basketballPlayer *> &p, string team1, string team2)
    {
        cout << "Team 1: " << team1 << endl;
        cout << "Available Basketball Players:" << endl;
        cout << "Basketball Player No\tName\tType" << endl;
        for (int i = 0; i < p.size(); i++)
        {
            if (i < 15)
            {
                cout << p[i]->p_no << "\t\t" << p[i]->name << "\t"
                     << (p[i]->type == 1 ? "Shooter" : "Guardian") << endl;
                p[i]->selected = false;
            }
            else
                break;
        }

        cout << endl;
        cout << "Team 2: " << team2 << endl;
        cout << "Available Basketball Players:" << endl;
        for (int i = 15; i < p.size(); i++)
        {
            cout << p[i]->p_no << "\t\t" << p[i]->name << "\t"
                 << (p[i]->type == 1 ? "Shooter" : "Guardian") << endl;
            p[i]->selected = false;
        }
    }

    void displayfootballPlayerPool(vector<footballPlayer *> &p, string team1, string team2)
    {
        cout << "Team 1: " << team1 << endl;
        cout << "Available Football Players:" << endl;
        cout << "Football Player No\tName\tType" << endl;
        for (int i = 0; i < p.size(); i++)
        {
            if (i < 15)
            {
                cout << p[i]->p_no << "\t\t" << p[i]->name << "\t"
                     << (p[i]->type == 1 ? "Striker" : "Defender") << endl;
                p[i]->selected = false;
            }
            else
                break;
        }

        cout << endl;
        cout << "Team 2: " << team2 << endl;
        cout << "Available Football Players:" << endl;
        for (int i = 15; i < p.size(); i++)
        {
            cout << p[i]->p_no << "\t\t" << p[i]->name << "\t"
                 << (p[i]->type == 1 ? "Striker" : "Defender") << endl;
            p[i]->selected = false;
        }
    }

    void selectbasketballPlayers(vector<basketballPlayer *> &basketballPlayer_pool, string team1, string team2)
    {
        displaybasketballPlayerPool(basketballPlayer_pool, team1, team2);
        int shooter_count = 0, defenders_count = 0;
        while (selected_basketballPlayers.size() < 6)
        {
            int basketballPlayer_no;
            cout << "Enter Basketball Player number to select: ";
            cin >> basketballPlayer_no;

            auto it = find_if(basketballPlayer_pool.begin(), basketballPlayer_pool.end(), [&](basketballPlayer *p)
            {
                return p->p_no == basketballPlayer_no;
            });

            if (it != basketballPlayer_pool.end() && !(*it)->selected)
            {
                if ((*it)->type == 1 && shooter_count < 3)
                {
                    shooter_count++;
                }
                else if ((*it)->type == 2 && defenders_count < 5)
                {
                    defenders_count++;
                }
                else
                {
                    cout << "Invalid selection. Check type limits." << endl << endl;
                    continue;
                }
                (*it)->selected = true;
                selected_basketballPlayers.push_back(*it);
                cout << "Basketball Player " << (*it)->name << " selected." << endl;
                if (shooter_count < 3 || defenders_count < 3)
                    cout << "Select " << (3 - shooter_count) << " more shooters and "
                         << (3 - defenders_count) << " more guardians from the pool." << endl << endl;
            }
            else
            {
                cout << "Basketball Player not found or already selected." << endl << endl;
            }
        }

        cout << endl << "Selected Basketball Players List:" << endl;
        int id1=-1,id2=-1;
        for(int i = 0;i < selected_basketballPlayers.size();i++)
        {
             cout << selected_basketballPlayers[i]->name << " " << selected_basketballPlayers[i]->p_no << endl;
        }

        cout << endl << "Choose a captain and vice captain from selected basketball players by selecting player id:" << endl;
        cin >> id1 >> id2;
        for(int i = 0;i < selected_basketballPlayers.size();i++)
        {
             if(selected_basketballPlayers[i]->p_no == id1)
             {
                 selected_basketballPlayers[i]->captain = 1;
             }

             else if(selected_basketballPlayers[i]->p_no == id2)
             {
                 selected_basketballPlayers[i]->vice_captain = 1;
             }

             if(id1 != -1 && id2 != -1)
             {
                 break;
             }
        }
    }

    void selectcricketPlayers(vector<cricketPlayer *> &cricketPlayer_pool, string team1, string team2)
    {
        displaycricketPlayerPool(cricketPlayer_pool, team1, team2);
        int batsmen_count = 0, bowlers_count = 0;
        while (selected_cricketPlayers.size() < 11)
        {
            int cricketPlayer_no;
            cout << "Enter Cricket Player number to select: ";
            cin >> cricketPlayer_no;

            auto it = find_if(cricketPlayer_pool.begin(), cricketPlayer_pool.end(), [&](cricketPlayer *p)
            {
                return p->p_no == cricketPlayer_no;
            });

            if (it != cricketPlayer_pool.end() && !(*it)->selected)
            {
                if ((*it)->type == 1 && batsmen_count < 6)
                {
                    batsmen_count++;
                }
                else if ((*it)->type == 2 && bowlers_count < 5)
                {
                    bowlers_count++;
                }
                else
                {
                    cout << "Invalid selection. Check type limits." << endl << endl;
                    continue;
                }
                (*it)->selected = true;
                selected_cricketPlayers.push_back(*it);
                cout << "Cricket Player " << (*it)->name << " selected." << endl;
                if (batsmen_count < 6 || bowlers_count < 5)
                    cout << "Select " << (6 - batsmen_count) << " more batsmen and "
                         << (5 - bowlers_count) << " more bowlers from the pool." << endl << endl;
            }
            else
            {
                cout << "Cricket Player not found or already selected." << endl << endl;
            }
        }

        cout << endl << "Selected Cricket Players List:" << endl;
        int id1=-1,id2=-1;
        for(int i = 0;i < selected_cricketPlayers.size();i++)
        {
             cout << selected_cricketPlayers[i]->name << " " << selected_cricketPlayers[i]->p_no << endl;
        }

        cout << endl << "Choose a captain and vice captain from selected cricket players by selecting player id:" << endl;
        cin >> id1 >> id2;
        for(int i = 0;i < selected_cricketPlayers.size();i++)
        {
             if(selected_cricketPlayers[i]->p_no == id1)
             {
                 selected_cricketPlayers[i]->captain = 1;
             }

             else if(selected_cricketPlayers[i]->p_no == id2)
             {
                 selected_cricketPlayers[i]->vice_captain = 1;
             }

             if(id1 != -1 && id2 != -1)
             {
                 break;
             }
        }
    }

    void selectfootballPlayers(vector<footballPlayer *> &footballPlayer_pool, string team1, string team2)
    {
        displayfootballPlayerPool(footballPlayer_pool, team1, team2);
        int striker_count = 0, defenders_count = 0;
        while (selected_footballPlayers.size() < 11)
        {
            int footballPlayer_no;
            cout << "Enter Football Player number to select: ";
            cin >> footballPlayer_no;

            auto it = find_if(footballPlayer_pool.begin(), footballPlayer_pool.end(), [&](footballPlayer *p)
            {
                return p->p_no == footballPlayer_no;
            });

            if (it != footballPlayer_pool.end() && !(*it)->selected)
            {
                if ((*it)->type == 1 && striker_count < 6)
                {
                    striker_count++;
                }
                else if ((*it)->type == 2 && defenders_count < 5)
                {
                    defenders_count++;
                }
                else
                {
                    cout << "Invalid selection. Check type limits." << endl << endl;
                    continue;
                }
                (*it)->selected = true;
                selected_footballPlayers.push_back(*it);
                cout << "Football Player " << (*it)->name << " selected." << endl;
                if (striker_count < 6 || defenders_count < 5)
                    cout << "Select " << (6 - striker_count) << " more strikers and "
                         << (5 - defenders_count) << " more defenders from the pool." << endl <<endl;
            }
            else
            {
                cout << "Football Player not found or already selected." << endl << endl;
            }
        }


        cout << endl << "Selected Football Players List:" << endl;
        int id1=-1,id2=-1;
        for(int i = 0;i < selected_footballPlayers.size();i++)
        {
             cout << selected_footballPlayers[i]->name << " " << selected_footballPlayers[i]->p_no << endl;
        }

        cout << endl << "Choose a captain and vice captain from selected football players by selecting player id:" << endl;
        cin >> id1 >> id2;
        for(int i = 0;i < selected_footballPlayers.size();i++)
        {
             if(selected_footballPlayers[i]->p_no == id1)
             {
                 selected_footballPlayers[i]->captain = 1;
             }

             else if(selected_footballPlayers[i]->p_no == id2)
             {
                 selected_footballPlayers[i]->vice_captain = 1;
             }

             if(id1 != -1 && id2 != -1)
             {
                 break;
             }
        }

    }

    void calculateTeamPoints(int flag)
    {
        if(flag==1)
        {
            for (auto &p : selected_cricketPlayers)
            {
                p->points=0;
                p->Calculatepoints(); // Call derived class method
                if(p->captain==1)
                    p->points*=2;
                else if(p->vice_captain==1)
                    p->points*=1.5;
                total_points += p->points;
            }

            for (auto &p : selected_cricketPlayers)
            {
                cout << p->name << " " << p->p_no << " " << p->points << endl;
            }
        }

        else if(flag==2)
        {
            for (auto &p : selected_basketballPlayers)
            {
                p->points=0;
                p->Calculatepoints(); // Call derived class method
                if(p->captain==1)
                    p->points*=2;
                else if(p->vice_captain==1)
                    p->points*=1.5;
                total_points += p->points;
            }

            for (auto &p : selected_basketballPlayers)
            {
                cout << p->name << " " << p->p_no << " " << p->points << endl;
            }
        }

        else if(flag==3)
        {
            for (auto &p : selected_footballPlayers)
            {
                p->points=0;
                p->Calculatepoints(); // Call derived class method
                if(p->captain==1)
                    p->points*=2;
                else if(p->vice_captain==1)
                    p->points*=1.5;
                total_points += p->points;
            }

            for (auto &p : selected_footballPlayers)
            {
                cout << p->name << " " << p->p_no << " " << p->points << endl;
            }
        }

    }
};


// Function to display menu and handle user input
void menu(vector<team> &teams)
{
    srand(time(0)); // Seed for random team selection
    int selection;
    while(true)
    {
        cout << "SELECT YOUR LEAGUE" << endl;
        cout << "1. FOOTBALL LEAGUE" << endl;
        cout << "2. BASKETBALL LEAGUE" << endl;
        cout << "3. IPL LEAGUE" << endl;
        cout << "4. EXIT" << endl;
        cin >> selection;
        if(selection == 1)
        {
            int team1_idx = rand() % teams.size();
            int team2_idx;
            do
            {
                team2_idx = rand() % teams.size();
            }
            while (team2_idx == team1_idx);

            team &team1 = teams[team1_idx];
            team &team2 = teams[team2_idx];

            cout << team1.name << " " << team2.name << endl;


            vector<footballPlayer*> footballPlayer_pool;
            footballPlayer_pool.insert(footballPlayer_pool.end(), begin(team1.footPlayer), end(team1.footPlayer));
            footballPlayer_pool.insert(footballPlayer_pool.end(), begin(team2.footPlayer), end(team2.footPlayer));

            User user1("User 1");
            User user2("User 2");

            cout << "Live Match Between: " << team1.name << " and " << team2.name << endl;

            cout << "User 1, select your Football Players:"<< endl;

            user1.selectfootballPlayers(footballPlayer_pool,team1.name,team2.name);

            cout << endl;
            cout << "User 2, select your team:" << endl;
            user2.selectfootballPlayers(footballPlayer_pool,team1.name,team2.name);

            cout << "User 1 team: " << endl;
            user1.calculateTeamPoints(3);
            cout << endl;
            cout << "User 2 team: " << endl;
            user2.calculateTeamPoints(3);

            cout << user1.name << " Total Points: " << user1.total_points << endl;
            cout << user2.name << " Total Points: " << user2.total_points << endl;

            if (user1.total_points > user2.total_points)
            {
                cout << user1.name << " Wins!" << endl;
            }
            else if (user1.total_points < user2.total_points)
            {
                cout << user2.name << " Wins!" << endl;
            }
            else
            {
                cout << "It's a Tie!" << endl;
            }

            //break;

            cout << endl;
        }


        if (selection == 2)
        {
            int team1_idx = rand() % teams.size();
            int team2_idx;
            do
            {
                team2_idx = rand() % teams.size();
            }
            while (team2_idx == team1_idx);

            team &team1 = teams[team1_idx];
            team &team2 = teams[team2_idx];

            cout << team1.Bname << " " << team2.Bname << endl;


            vector<basketballPlayer*> basketballPlayer_pool;
            basketballPlayer_pool.insert(basketballPlayer_pool.end(), begin(team1.basketPlayer), end(team1.basketPlayer));
            basketballPlayer_pool.insert(basketballPlayer_pool.end(), begin(team2.basketPlayer), end(team2.basketPlayer));

            User user1("User 1");
            User user2("User 2");

            cout << "Live Match Between: " << team1.Bname << " and " << team2.Bname << endl;

            cout << "User 1, select your Basketball Players:"<< endl;

            user1.selectbasketballPlayers(basketballPlayer_pool,team1.Bname,team2.Bname);

            cout << endl;
            cout << "User 2, select your team:" << endl;
            user2.selectbasketballPlayers(basketballPlayer_pool,team1.Bname,team2.Bname);

            cout << "User 1 team: " << endl;
            user1.calculateTeamPoints(2);
            cout << endl;
            cout << "User 2 team: " << endl;
            user2.calculateTeamPoints(2);

            cout << user1.name << " Total Points: " << user1.total_points << endl;
            cout << user2.name << " Total Points: " << user2.total_points << endl;

            if (user1.total_points > user2.total_points)
            {
                cout << user1.name << " Wins!" << endl;
            }
            else if (user1.total_points < user2.total_points)
            {
                cout << user2.name << " Wins!" << endl;
            }
            else
            {
                cout << "It's a Tie!" << endl;
            }

            //break;

            cout << endl;
        }

        else if (selection == 3)
        {
            int team1_idx = rand() % teams.size();
            int team2_idx;
            do
            {
                team2_idx = rand() % teams.size();
            }
            while (team2_idx == team1_idx);

            team &team1 = teams[team1_idx];
            team &team2 = teams[team2_idx];

            vector<cricketPlayer*> cricketPlayer_pool;
            cricketPlayer_pool.insert(cricketPlayer_pool.end(), begin(team1.p), end(team1.p));
            cricketPlayer_pool.insert(cricketPlayer_pool.end(), begin(team2.p), end(team2.p));

            User user1("User 1");
            User user2("User 2");

            cout << "Live Match Between: " << team1.Cname << " and " << team2.Cname << endl;

            cout << "User 1, select your Cricket Players:"<< endl;

            user1.selectcricketPlayers(cricketPlayer_pool,team1.Cname,team2.Cname);

            cout << endl;
            cout << "User 2, select your team:" << endl;
            user2.selectcricketPlayers(cricketPlayer_pool,team1.Cname,team2.Cname);

            cout << "User 1 team: " << endl;
            user1.calculateTeamPoints(1);
            cout << endl;
            cout << "User 2 team: " << endl;
            user2.calculateTeamPoints(1);

            cout << user1.name << " Total Points: " << user1.total_points << endl;
            cout << user2.name << " Total Points: " << user2.total_points << endl;

            if (user1.total_points > user2.total_points)
            {
                cout << user1.name << " Wins!" << endl;
            }
            else if (user1.total_points < user2.total_points)
            {
                cout << user2.name << " Wins!" << endl;
            }
            else
            {
                cout << "It's a Tie!" << endl;
            }

            cout << endl;

            //break;
        }
        else if (selection == 4)
        {
            exit(0); // Exit the program
        }
    }
}

int main()
{
    vector<team> teams;
    teams.push_back(team("RCB","Villarreal_CF","Bucks"));
    teams.push_back(team("CSK","Real_Sociedad","Bulls"));
    teams.push_back(team("MI","Atletico_Madrid","Celtics"));
    teams.push_back(team("KKR","Sevilla_FC","Lakers"));
    teams.push_back(team("DC","FC_Barcelona","Nets"));
    teams.push_back(team("PBKS","Real_Madrid","Warriors"));

    teams[0].read_Players("cricket/rcb.txt","football/Villarreal_CF.txt","basketball/Bucks.txt");
    teams[1].read_Players("cricket/csk.txt","football/Real_Sociedad.txt","basketball/Bulls.txt");
    teams[2].read_Players("cricket/mi.txt","football/Atletico_Madrid.txt","basketball/Celtics.txt");
    teams[3].read_Players("cricket/kkr.txt","football/Sevilla_FC.txt","basketball/Lakers.txt");
    teams[4].read_Players("cricket/dc.txt","football/FC_Barcelona.txt","basketball/Nets.txt");
    teams[5].read_Players("cricket/pbks.txt","football/Real_Madrid.txt","basketball/Warriors.txt");

    menu(teams);

    return 0;
}
