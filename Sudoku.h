#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

#include <vector>
#include <string>
#include <set>
#define order 9

using std::vector;
using std::string;

#include <iostream>

using std::cout;
using std::endl;
// TODO: Your Sudoku class goes here:
class Sudoku{
    
public:

    Sudoku(int size){
    }
    

    int square[order][order];
    
    int getSquare(int row, int column) {

        return square[row][column];
    }

    bool setSquare(int rows,int cols,int value){
        for (int i = 0; i <9; i++)
        {
            i++;
            for (int j = 0; j <9; j++)
            {
                j++;
                if (square[i][j] == square[rows][cols] )
                {
                      // cout<<"GOES"<<endl;
                    square[rows][cols]=value;
                    return true;

                }
                else
                {   cout<<"GOES2"<<endl;
                    return false;
                }
       
             
        return true;
            }
        }
            
        
        for (int row=0; row < 9; row++){
            cout<<row<<"ROW"<<endl;
            cout<<rows<<"ROWS"<<endl;
            if (row != rows && square[row][cols] == square[rows][cols]){
                cout<<"TUK2"<<endl;
                return false;}
            else {return true;  cout<<"TUK1"<<endl;}
        }

        // Check whether grid[i][j] is valid in the 3 by 3 box
        for (int row = (rows / 3) * 3; row < (rows / 3) * 3 + 3; row++)
            for (int col = (cols / 3) * 3; col < (cols / 3) * 3 + 3; col++)
                if (row != rows && col != cols && square[row][col] == square[rows][cols])
                      cout<<"TUK4"<<endl;
                    return false;
        
         //  else return true;
            cout<<"TUK5"<<endl;

       // return true; // The current value at grid[i][j] is valid
    }

};



#endif
