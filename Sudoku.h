#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;
using std::set;
#include <iostream>

using std::cout;
using std::endl;
// TODO: Your Sudoku class goes here:
class Sudoku{
    
public:

   vector<vector<set<int>>>  incomplete;
      Sudoku(int size)
   : incomplete(size){

        int options[size];
        for (int i = 0; i < size; ++i) {
            options[i] = i + 1;
        }
        set<int> block(options, options + size);
        for (int k = 0; k < size; ++k) {
            incomplete[k] = vector<set<int>>(size);
            for (int j = 0; j < size; ++j) {
                incomplete[k][j] = block;
            }
        }
    }
    
    
    int getSquare(int r, int c) {
        set <int> block = incomplete[r][c];
        if (block.size() == 1) {
            
            return *block.begin();
        }
        else {
            return -1;
        }
    }

    
    bool setSquare(int rows, int cols, int value) {

        set <int> * block = & incomplete[rows][cols];
        block->clear();

        for (int col=0; col < incomplete.size(); col++){
if (col != cols && incomplete[rows][col] == incomplete[rows][cols]){
                            return false;
                        }
                        else {
                            block->insert(value);
         set<int> *column = &incomplete[col][cols];
                    column->erase(value);
                            
                        }
         
                    }
            
                    for (int row=0; row < incomplete.size(); row++){

                    if (row != rows && incomplete[row][cols] == incomplete[rows][cols]){

                        }
                        else {
                    
                            block->insert(value);
                     set<int> *rowO = &incomplete[rows][row];
                                      rowO->erase(value);
  
                        }
                    }
            
                    // Check whether grid[i][j] is valid in the 3 by 3 box
            for (int row = (rows / 3) * 3; row < (rows / 3) * 3 + 3; row++)
                for (int col = (cols / 3) * 3; col < (cols / 3) * 3 + 3; col++)
                            if (row != rows && col != cols && incomplete[row][col] == incomplete[rows][cols]){
            
                                return false;
                            }
                    
                            else {
     
                                block->insert(value);
                       //     set <int> * box = &incomplete[rows][cols];
                                 incomplete[row][col].erase(value);
                            }

//        
//        for (int i = 0; i < 9; i++) {
//            for (int j = 0; j < 9; j++) {
//                if (!incomplete[rows][cols]) {     // if unsolved space, tries scanner
//                    
//                    cout<<"YES"<<"  "<<rows<<"  "<<cols<<endl;
//                }
//            }
//        }
                    return true; // The current value at grid[i][j] is valid
                }


    

    
};



#endif