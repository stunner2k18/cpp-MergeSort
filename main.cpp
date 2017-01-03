#include "istream/istream13.h"
#include "istream/istream2.h"
#include "istream/istream4.h"
#include "ostream/ostream13.h"
#include "ostream/ostream2.h"
#include <io.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Choose a method (1-4) in parameter 3";
        return 0;
    }

    static int B = 2;

    //-----------------FIRST METHOD-----------------

    if (argv[3][0] == '1') {
        cout << "First method" << endl;
        IStream13 reader1;
        OStream13 writer1;
        reader1.open(argv[1]);
        writer1.create(argv[2]);

        while (!reader1.end_of_stream()) {
            vector<int> res = reader1.read_next();

            writer1.write(res);
        }
        writer1.close();
    }

    //-----------------SECOND METHOD-----------------

    if (argv[3][0] == '2') {
        cout << endl << "Second method" << endl;
        IStream2 reader2;
        OStream2 writer2;
        reader2.open(argv[1]);
        writer2.create(argv[2]);

        while (!reader2.end_of_stream()) {
            int res = reader2.read_next();
            writer2.write(res);
            cout << res << endl;
        }
        writer2.close();
    }

    //-----------------THIRD METHOD-----------------

    if (argv[3][0] == '3') {
        cout << endl << "Third method" << endl;
        IStream13 reader3(B);
        OStream13 writer3;
        reader3.open(argv[1]);
        writer3.create(argv[2]);

        while (!reader3.end_of_stream()) {
            vector<int> res = reader3.read_next();
            writer3.write(res);
        }
        writer3.close();
    }

    //-----------------FOURTH METHOD-----------------

    if (argv[3][0] == '4') {
        cout << endl << "Fourth method" << endl;
        IStream4 reader4(B);
        //OStream4 writer4;
        reader4.open(argv[1]);
        //writer4.create(argv[2]);

        while (!reader4.end_of_stream())
            vector<int> res = reader4.read_next();
        //writer4.write(res);
        //writer4.close();
    }

    return 0;
}
