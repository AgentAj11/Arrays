// important
/*
	Asterisk '*' takes you one layer deeper at a time.
	For example: in a 2D matrix-
						   matrix represents address of 1st row
							 *matrix represents address of 1st element
							 **matrix represents value of 1st element

	*** This idea of using asterisks can be used to access
			any value in a matrix or any multidimensional array.
*/

/*
	In a 2D matrix, matrix means row.
	matrix = matrix[0] = first row
	matrix[1] = 2nd row
	matrix[2] = 3rd row
				.
				.
				.
	matrix[n] = nth row
*/

#include <iostream>
using namespace std;


void matrix(){
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "matrix = " << matrix << endl;
    cout << "&matrix = " << &matrix << endl;
    cout << "&matrix[0] = " << &matrix[0] << endl;
    cout << "&matrix[0][0] = " << &matrix[0][0] << endl;

    cout << "*matrix = " << *matrix << endl << endl;

    cout << "Address of each matrix element\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << &matrix[i][j] << "\t";
        }   cout << endl;
    }

    cout << "\nAddress of each row\n";
    for(int i = 0; i < 3; i++){
        cout << &matrix[i] << endl;
    }

    cout << "(1st row) matrix = " << matrix << endl;
    cout << "*matrix = " << *matrix << endl;
    cout << "**matrix = " << **matrix << endl;

    cout << "\nAccessing matrix elements by pointer\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << *(*(matrix + i) + j) << "\t";
        }   cout << endl;
    }
}


int main(void){

    matrix();
    return 0;
}