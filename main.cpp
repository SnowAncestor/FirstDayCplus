#include<bits/stdc++.h>

using namespace std;

int main() {
//game
    default_random_engine lalo(time(nullptr));
    uniform_real_distribution<float> laloAttack(0.0f, 1.0f);
    string i = "";
    int lalohealth = 100;
    int snakehealth = 400;

    while(snakehealth > 0 && lalohealth > 0 && i != "no") {
        if (laloAttack(lalo) > 0.5) {
            cout << "You are close to killing the snake!" << endl;
            snakehealth -= 50;
        } else {
            lalohealth -= 20;
            cout << "You take damage from the snake." << endl;
        }
        cout << "Do you want to continue? If yes, write 'yes', if no, write 'no' \n if u want to see the health write elif snake of player: " << endl;
        cin >> i;
        transform(i.begin(), i.end(), i.begin(), [](unsigned char c) { return tolower(c); });
        if(i=="player"){
            cout<<"lalo health = " <<lalohealth<<endl;
            cout<<"Now print yes or no if u want to countine "<<endl;
            cin>>i;
        }
        else if(i=="snake"){
            cout<<"snake health = "<<snakehealth<<endl;
            cout<<"Now print yes or no if u want to countine "<<endl;
            cin>>i;
        }
        while(i != "yes" && i != "no") {
            cout << "Wrong input. Please write 'yes' or 'no': " << endl;
            cin >> i;
            transform(i.begin(), i.end(), i.begin(), [](unsigned char c) { return tolower(c); });
        }
    }

    if(lalohealth <= 0) {
        cout << "Lalo got killed." << endl;
    } else if(snakehealth <= 0) {
        cout << "Lalo wins!" << endl;
    } else {
        cout << "Game ended by the player." << endl;
    }

    return 0;
}
