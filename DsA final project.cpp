#include <iostream>
using namespace std;

class Adaptive {
private:
    string subject[5];
    int hours[5];
    int score[5];
    int risk[5];
    int F, R;
    string QA[5];

public:
    Adaptive() {
        F = -1;
        R = -1;
    }

    void input() {
        cout << "\n ENTER SUBJECT DATA \n";
        for(int i = 0; i < 5; i++) {
            cout << "\nSubject " << i+1 << endl;

            cout << "Name        : ";
            cin >> subject[i];

            cout << "Study Hours : ";
            cin >> hours[i];

            cout << "Test Score  : ";
            cin >> score[i];
        }
    }

    void calculateRisk() {
        for(int i = 0; i < 5; i++)
            risk[i] = 100 - score[i];

        cout << "\nRisk Calculated Successfully!\n";
    }

    void sortSubjects() {
        for(int u = 4; u >= 1; u--) {
            for(int i = 0; i < u; i++) {
                if(score[i] > score[i+1]) {
                    swap(score[i], score[i+1]);
                    swap(hours[i], hours[i+1]);
                    swap(risk[i], risk[i+1]);
                    swap(subject[i], subject[i+1]);
                }
            }
        }
        cout << "Subjects Sorted (Weak  Strong)\n";
    }

    void enqueueWeakSubjects() {
        for(int i = 0; i < 5; i++) {
            if(score[i] < 50) {
                if(R >= 4) {
                    cout << "Queue Full!\n";
                    return;
                }
                R++;
                QA[R] = subject[i];

                if(F == -1)
                    F = 0;
            }
        }
        cout << "Weak Subjects Added to Queue!\n";
    }

    void optimizeSubjects() {
        cout << "\n PRIORITY STUDY ORDER \n";

        if(F == -1) {
            cout << "No Weak Subjects Found!\n";
            return;
        }

        for(int i = F; i <= R; i++)
            cout << "- " << QA[i] << endl;
    }

    void display() {
        cout << "\n SUBJECT REPORT \n";

        for(int i = 0; i < 5; i++) {
            cout << "Subject : " << subject[i] << endl;
            cout << "Hours   : " << hours[i] << endl;
            cout << "Score   : " << score[i] << endl;
            cout << "Risk    : " << risk[i] << endl;
           
        }
    }
};

int main() {
    Adaptive a;

    a.input();
    a.calculateRisk();
    a.sortSubjects();
    a.enqueueWeakSubjects();
    a.display();
    a.optimizeSubjects();

    return 0;
}
