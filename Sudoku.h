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
    
    int incompleteSolution[9][9];
    
    std::set<int>possibleValues = {1,2,3,4,5,6,7,8,9};
    
//    vector<int>possibleValues ={1,2,3,4,5,6,7,8,9};
//
    Sudoku(int size){
    }
//
//    int square[order][order];
//    
    int getSquare(int row, int column) {
        cout<<"HEREEE"<<endl;
        cout<<incompleteSolution[row][column]<<endl;
        if(possibleValues.size()==1){
        
            cout<<"ITS ONE"<<endl;
        }
        return incompleteSolution[row][column];
    }
//
    bool setSquare(int rows,int cols,int value){
        for (int col=0; col < 9; col++){
          //  cout<<rows<<"ROW"<<endl;
         //  cout<<col<<"COL"<<endl;
            if (col != cols && incompleteSolution[rows][col] == incompleteSolution[rows][cols]){
              //  cout<<"TUK1"<<endl;
              //  return false;
            }
            else {
                incompleteSolution[rows][cols]=value;
                // possibleValues.push_back(value);
              //  cout<<"TUK2"<<endl;
                
              //  return true;
            }

                     //  cout<<col<<"COL"<<endl;
        }
        
        for (int row=0; row < 9; row++){
          //  cout<<row<<"ROW"<<endl;
           // cout<<rows<<"ROWS"<<endl;
            if (row != rows && incompleteSolution[row][cols] == incompleteSolution[rows][cols]){
          //      cout<<"TUK3"<<endl;
               // return false;
            }
            else {
                incompleteSolution[rows][cols]=value;
               // possibleValues.push_back(value);
          //      cout<<"TUK4"<<endl;
                //return true;
            }
        }

        // Check whether grid[i][j] is valid in the 3 by 3 box
        for (int row = (rows / 3) * 3; row < (rows / 3) * 3 + 3; row++)
            for (int col = (cols / 3) * 3; col < (cols / 3) * 3 + 3; col++)
                if (row != rows && col != cols && incompleteSolution[row][col] == incompleteSolution[rows][cols]){
              //        cout<<"TUK5"<<endl;
                 //   return false;
                }
        
                else {
                    incompleteSolution[rows][cols]=value;
                }
               //     cout<<value<<"VALUE"<<endl;
                    //possibleValues.push_back(value);
                 //       cout<<"TUK6"<<endl;
                 //   return true;}
        

        return true; // The current value at grid[i][j] is valid
    }
    

};

//        for(int i = 0; i<rows; i++)
//        {
//            for(int j = 0; j<cols; j++)
//            {
//                cout<<"Enter the number for Matrix 1"<<incompleteSolution[i][j]<<endl;
//            }
//        }
// return true;
//
//        for (int i = 0; i <9; i++)
//        {
//            i++;
//            for (int j = 0; j <9; j++)
//            {
//                j++;
//                if (square[i][j] == square[rows][cols] )
//                {
//                    //square[rows][cols]=value;
//                      cout<<"GOES"<<endl;
//                    if(value==0){
//                        cout<<"NULA"<<endl;
//           //             square[rows][cols]=value;
//                     //   possibleValues.push_back(value);
//                       // auto itr = possibleValues.begin();
//                        //square[rows][cols]=*itr;
//
//
//                    }
//                }
//            }
//        }
//    }
//                    else {cout<<"HERE"<<rows<<cols<<endl;}
//                 //   value=possibleValues;
//                    //possibleValues.push_back(value);
//
//                    return true;
//
//                }
//
//                else
//                {   cout<<"GOES2"<<endl;
//                  //  square[rows][cols]=possibleValues;
//                    return false;
//                }
//
//
//        return true;
//            }
//        }
//



#endif
