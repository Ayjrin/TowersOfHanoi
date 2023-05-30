#include <iostream>
#include <stack>
using namespace std;

class Hanoi {
private:
    stack<int> towers[3];
    int numOfDisks;

public:
    Hanoi(int disks) : numOfDisks(disks) {
        for(int i = disks; i > 0; i--) {
            towers[0].push(i);
        }
    }


/*
my first thought was to put the towers next to each other, but the spacing turned out to be a nightmare in the console. 
I have been looking at the raylib library recently, and I think that might be the way to actually build it out.
That would require a whole lot of work though, and this output is really simple and conveys the towers simply enough. 
Just having the numbers print to the console made it impossible to solve, so I had to build this to make sure the rest of it worked.
*/
    void display() {
        for(int i = 0; i < 3; i++) {
            cout << "Stack " << i+1 << " : ";
            cout << "| Tower " << i+1 << endl;
            stack<int> temp2 = towers[i];
            while(!temp2.empty()) {
                cout << "| ";                               // makes the output more visually clear
                for(int j = 0; j < temp2.top(); j++) {      // rings
                    cout << "-";
                }
                cout << endl;
                temp2.pop();
            }
            cout << "|_____" << endl << endl;
            stack<int> temp = towers[i];
            while(!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl << endl << endl;
        }
    }

    bool moveDisk(int from, int to) {
        if(towers[from].empty()) {
            return false;
        }
        if(towers[to].empty() || towers[from].top() < towers[to].top()) {   // if the destination stack is empty, or the ring being moved is < the destination ring
            towers[to].push(towers[from].top());
            towers[from].pop();
            return true;
        } else {
            return false;
        }
    }

    bool checkVictory() {
        return towers[2].size() == numOfDisks;
    }


};

int main() {
    Hanoi hanoi(5);
    int moveCounter = 0;
    hanoi.display();

    while(!hanoi.checkVictory()) {
        cout << "\n\nMove a disk: \n";
        int source, destination;
        cout << "Enter source stack (1-3): ";
        cin >> source; source--;
        cout << "Enter destination stack (1-3): ";
        cin >> destination; destination--;

        if(hanoi.moveDisk(source, destination)) {
            cout << "Move successful!" << endl;
            hanoi.display();
            moveCounter++;
        } 
        
        else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    cout << "Congratulations! You solved the puzzle in " << moveCounter << " moves.";
    if (moveCounter > 31){
        cout << ".. but you could have done it in " << moveCounter - 31 << " fewer moves... just saying..." << endl; // https://www.mathsisfun.com/games/towerofhanoi.html
    } 

    else {cout << " You did it in the least possible number of turns too?!? What a smarty!";}

    return 0;
}
