#include <iostream>
#include <regex>
#include <string>
#include <array>

using namespace std;

const int THICKNESS = 1;

double* determine_slopes(char connections[]);

int main() {

    char templateString[] = "3x3,3|0-8,6-8,0-6";
    const int TEMPLATE_LENGTH = sizeof(templateString)/sizeof(*templateString);

    for(int i = 0; i < TEMPLATE_LENGTH; i++) {
        if(templateString[i] == '\0') {
            cout << "THERE IS A NULL CHARACTER @ POS. " << i << endl;
        }
    }

    //char *ptr = templateString;
    /* for(char* i = &ptr[0]; i != &ptr[sizeof(&ptr)/sizeof(*ptr)]; i++) {
        std::cout << *i << endl;
    }*/


    /* Get the index of the pipe in the template, separating the grid sizing from the connections */
    int pipeIndex = -1;

    for(int i = 0; i < TEMPLATE_LENGTH; i++) {
        if(templateString[i] == '|') {
            pipeIndex = i;
            break;
        }
    }
    if(pipeIndex == -1) return 0; //stop program from running because invalid template


    //Split string into grid sizing properties and connections
    char gridProperties[pipeIndex + 1];
    char connections[TEMPLATE_LENGTH - pipeIndex];

    cout << TEMPLATE_LENGTH << endl;
    cout << sizeof(gridProperties)/sizeof(*gridProperties) << endl;
    cout << sizeof(connections)/sizeof(*connections) << endl;
    cout << pipeIndex << endl;

    for(int i = 0; i < pipeIndex; i++) {
        gridProperties[i] = templateString[i];
        cout << i << " ";
    }

    for(int i = 0, j = pipeIndex + 1; j < TEMPLATE_LENGTH; i++, j++) {
        connections[i] = templateString[j];
        cout << i << " ";
    }

    cout << endl << gridProperties << endl << connections << endl;


    regex re("\\d+x\\d+,\\d+");

    regex connectionRE("\\d+-\\d+");

    cout << "==========" << endl;
    for(cregex_iterator it = cregex_iterator(connections, connections + (sizeof(connections)/sizeof(*connections)), connectionRE); it != cregex_iterator(); it++) {
        cout << (*it).str() << endl;
    }
    cout << "==========" << endl;

    for(cregex_iterator iter = cregex_iterator(begin(templateString), end(templateString), connectionRE); iter != cregex_iterator(); iter++) {
        cout << (*iter).str() << ", position:" << (*iter).position() << endl;
    }

    const int spacing = 3;

    const int COLUMN_COUNT = 3;
    const int ROW_COUNT = 3;

    int points[COLUMN_COUNT * ROW_COUNT][2];

    //initialize where each point will be
    int iPoint = 0;
    for(int y = 0; y < ROW_COUNT; y++) {
        for(int x = 0; x < COLUMN_COUNT; x++) {
            points[iPoint][0] = x * spacing;
            points[iPoint][1] = y * spacing;
            iPoint++;
        }
    }

    /*for(auto & point : points) {
       cout << "(" << point[0] << "," << point[1] << ") | ";
    }*/


    //determine_slopes(templateString);

    /*
     * TEMPLATE FORMAT
     * EX. Triangle on 3x3 grid
     * 0-8,6-8,0-6
     *
     *  **    **
     *     **    **
     *       **    **
     *
     */



}

//SLOPE BETWEEN TWO POINTS (y2-y1)/(x2-x1)
/*
double* determine_slopes(char connections[]) {
    //split connections
    string connectionString(connections);
    regex test("testing");
    cregex_iterator start(connections, end(connections), test);
    auto end = cregex_iterator();
    for(cregex_iterator i = begin; i != end; i++) {

    }
}
 */