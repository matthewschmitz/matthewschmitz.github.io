//
//  MontyHallProblem.cpp
//  Monty Hall Problem
//
//  Created by Matt Schmitz on 2017-02-12.
//  Copyright © 2017 Matthew Schmitz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


/////////////////////////////////////
//   Global variable definitions   //
/////////////////////////////////////

int carDoor; // Which door the car is behind

int contestantSelection; // Which door the contestant originally selects

int doorRevealed; // Which door is revealed by Monty Hall

int doorToSwitch; // Which door the contestant would switch to, if they choose

int switchWin = 0; // How many times the contestant wins by switching

int switchLoss = 0; // How many times the contestant switched and lost

int nonSwitchWin = 0; // How many times the contestant didn't switch and won

int nonSwitchLoss = 0; // How many times the contestant didn't switch and lost


//////////////////////////////
//   Function definitions   //
//////////////////////////////

int randomNumber();

void assignDoors();

double switchRandom();

bool switchDoors();

void trial();


//////////////////////
//   Main program   //
//////////////////////

int main() {
    
    // Running one million trials of the Monty Hall scenario
    for ( int tests = 0; tests < 1000000; tests++ ) {
        
        trial();
        
    }
    
    int totalSwitches = switchWin + switchLoss; // Determining the total number of times the contestant switched doors
    
    int totalNonSwitches= nonSwitchWin + nonSwitchLoss; // Determining the total number of times the contestant didn't switch doors
    
    double percentSwitchWin = switchWin * 1.0 / totalSwitches * 100.0; // Determining the percentage of times the contestant won after switching
    
    double percentSwitchLoss = 100.0 - percentSwitchWin; // Determining the percentage of times the contestant lost after switching
    
    double percentNonSwitchWin = nonSwitchWin * 1.0 / totalNonSwitches * 100.0; // Determining the percentage of times the contestant won after keeping their door

    double percentNonSwitchLoss = 100.0 - percentNonSwitchWin; // Determining the percentage of times the contestant lost after keeping their door
    
    cout << "Of the one million trials, " << totalSwitches << " trials saw " << endl;
    cout << "the contestant switch doors..." << endl;
    cout << endl;
    cout << "Of these trials, the contestant won the car " << switchWin << " times," << endl;
    cout << "or " << percentSwitchWin << "% of the time." << endl;
    cout << endl;
    cout << "When the contestant switched doors, they lost " << switchLoss << " times," << endl;
    cout << "or " << percentSwitchLoss << "% of the time." << endl;
    cout << endl;
    cout << endl;
    cout << "Of the one million trials, " << totalNonSwitches << " trials saw " << endl;
    cout << "the contestant keep the same door..." << endl;
    cout << endl;
    cout << "Of these trials, the contestant won the car " << nonSwitchWin << " times," << endl;
    cout << "or " << percentNonSwitchWin << "% of the time." << endl;
    cout << endl;
    cout << "When the contestant didn't switch doors, they lost " << nonSwitchLoss << " times," << endl;
    cout << "or " << percentNonSwitchLoss << "% of the time." << endl;
    cout << endl;
    cout << endl;
    
    return 0;
    
}


//////////////////////////////////
//   Function implementations   //
//////////////////////////////////


// Returns a random number between 1 and 3, inclusive

int randomNumber() {
    
    int selection = rand() % 3;
    
    selection += 1;
    
    return selection;

}


// Assigns the doors to variables for which door contains the car and which is selected by the contestant

void assignDoors() {
    
    carDoor = randomNumber(); // Assigning the door behind which is the car
    
    contestantSelection = randomNumber(); // Assigning the contestant's guess
    
    for ( int i = 1; i <= 3; i++ ) {
        
        if ( i != carDoor && i != contestantSelection ) {
            
            doorRevealed = i; // Deciding what door Monty Hall reveals
            
            break;
            
        }
        
    }
    
    for ( int i = 1; i <= 3; i++ ) {
        
        if ( i != doorRevealed && i != contestantSelection ) {
            
            doorToSwitch = i; // Deciding which door the contestant would switch to, should they choose to
            
            break;
            
        }
        
    }
    
    return;
    
}


// Determines a random number, 0 < r < 1, to help decide if the contestant will switch doors

double switchRandom() {
    
    double switchRandom = ( ( double ) rand() / ( RAND_MAX ) );
    
    return switchRandom;
    
}


// Determines if the contestant switches doors

bool switchDoors() {
    
    if ( switchRandom() < 0.500 ) {
        
        return true;
    
    }

    else {
        
        return false;
        
    }
    
}


// Runs one trial of the experiment

void trial() {
    
    assignDoors(); // Assigning the doors
    
    if ( switchDoors() == true ) {
        
        contestantSelection = doorToSwitch; // Switching doors, if necessary
        
        if ( contestantSelection == carDoor ) {
            
            switchWin += 1; // Counting a switch win, if necessary
            
        }
        
        else {
            
            switchLoss += 1; // Counting a switch loss, if necessary
            
        }

    }
    
    else {
        
        if ( contestantSelection == carDoor ) {
            
            nonSwitchWin += 1; // Counting a non switch win, if necessary
            
        }
        
        else {
            
            nonSwitchLoss += 1; // Counting a non switch loss, if necessary
            
        }
        
    }
    
    return;
    
}




