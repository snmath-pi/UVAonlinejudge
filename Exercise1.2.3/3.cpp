#include<bits/stdc++.h>
using namespace std;

int century(int val) {
    if(val < 1800) {
        return 4;
    }
    else if(val < 1900) 
        return 2;
    else if(val < 2000) 
        return 0;
    else if(val < 2100) 
        return 6;
    else if(val < 2200) 
        return 4;
    else if(val < 2300) 
        return 2;
    else return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, y;
    string m;
    cin >> n >> m >> y;
    int yc = (y%10) + ((y/10)%10)*10;
    yc = (yc + yc/4)%7;
    map<string, int> mp;
    mp["January"] = 0;
    mp["February"] = 3;
    mp["March"] = 3;
    mp["April"] = 6;
    mp["May"] = 1;
    mp["June"] = 4;
    mp["July"] = 6;
    mp["August"] = 2;
    mp["September"] = 5;
    mp["October"] = 0;
    mp["November"] = 3;
    mp["December"] = 5;

    int mc = mp[m];

    int cc = century(y);

    int julian_date = (18 - (y/100))%7;
    int leap = (y % 4 == 0) ? 1 : 0;

    int value = (yc + mc + cc + julian_date - leap) % 7;

    auto day = [&](int val) {
        switch(val) {
        case 0:
            cout << "Sunday";
        case 1:
            cout << "Monday";
        case 2:
            cout << "Tuesday";
        case 3:
            cout << "Wednesday";
        case 4:
            cout << "Thurday";
        case 5:
            cout << "Friday";
        case 6:
            cout << "Saturday";
        }
    };
    cout << value << '\n';
    day(value);

    
}
