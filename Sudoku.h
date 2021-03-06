#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

#include <vector>
#include <string>
#include <set>
#include <math.h>

using std::vector;
using std::string;
using std::set;
#include <iostream>

using std::cout;
using std::endl;
// TODO: Your Sudoku class goes here:
class Sudoku: public Searchable{
    
public:
    
    vector<vector<set<int>>> incomplete;
 //setting the board with the incomplete solution
    Sudoku(const int&size)
       : incomplete(size){
    
            int grid[size];
             int *sum = grid+size;
        set<int> block(grid, sum);
           
            for (int i = 0; i < incomplete.size(); ++i) {
                grid[i] = i + 1;
            }
           
         
           for (int k = 0; k < incomplete.size(); ++k){
               vector<set<int>>rowV(size);
               incomplete[k] =rowV;
               for (int j = 0; j < incomplete.size(); ++j){
                   incomplete[k][j].insert({1,2,3,4,5,6,7,8,9});}
               
           }
        }

//returning the vallue in the square if there is only one option and -1 if there are more
    int getSquare(const int r, const int c) const{
                set <int> block = incomplete[r][c];
                if (incomplete[r][c].size() == 1) {
        
                    return *block.begin();
                }
                else {
        
                    return -1;
                }

    }
    
    bool setSquare(int row,int col, int val){
        set<int>*block = &incomplete[row][col];
        block->clear();                         //clear for the new values
        incomplete[row][col].insert(val);
        
        int minus;
       int count;
        
        int n=0;
        int j=0;
      //infinite loop that goes through the board
        for(;;){
     
            count=minus;
            minus=0;

            for (n = 0; n < incomplete.size(); n++)
            {
                for (j = 0; j < incomplete[n].size(); j++)
                {
                    if (incomplete[n][j].size()==0)
                    {
                        return false;
                    }
                    
                   if (incomplete[n][j].size()==1){
                        rowC(n,j);
     
                        square(n,j);
                                           columnC(n,j);
                        
                    }
                    else {
                        
                        minus++;
                    }
                }
            }
            if (count==minus || minus==0){
                
                break;
            }
        }
        return true;
    }
    
    
    
    
    //done
    //Check whether grid[rows][cols] is valid in the 3 by 3 box
    
    bool square(int rows, int  cols){
                    set<int>*sq = &incomplete[rows][cols];
        for (int row = (rows / 3) * 3; row < (rows / 3) * 3 + 3; row++){
            
            for (int col = (cols / 3) * 3; col < (cols / 3) * 3 + 3; col++){
        
            if (row != rows && col != cols){
        if (incomplete[row][col].count(*sq->begin())==1) incomplete[row][col].erase(*sq->begin());
                if(incomplete[row][col].size()==0){
                    
                    return false;
                }
                }
            }
        }
        return true;
    }
    
        //Check whether grid[row][column] is valid by row
    bool rowC(int row, int column){
        
    set<int>*gr = &incomplete[row][column];
        for (int rows = 0; rows < 9; rows++){
            if (rows != column){
            if (row != rows && incomplete[row][column] == incomplete[rows][column]){ return false;
            }
                
                if (incomplete[row][rows].count(*gr->begin())==1) {
                    
                incomplete[row][rows].erase(*gr->begin());
                }
                
            
                }
        }
        return true;
        
    }
    
        //Check whether grid[row][col] is valid by column
    bool columnC(int  row, int  col){
        
             set<int>*bl = &incomplete[row][col];
        for (int j = 0; j < 9; j++){
            if (j != row){
                if (col != j && incomplete[row][col] == incomplete[row][j]){
                            return false;
                                              }
                
                if (incomplete[j][col].count(*bl->begin())==1) {
                    
                incomplete[j][col].erase(*bl->begin());
                }
            }
        }
        return true;
    }
    
    
    int heuristicValue() const  {
        
    //empty for now go back d part
    }
    
    //checks whether there is only one value in every square
    bool isSolution() const {
        int row =0;
        int col=0;
        for (row = 0; row < incomplete.size(); row++)
        {
            for (int col = 0; col < incomplete[row].size(); col++)
            {
                if (incomplete[row][col].size()>1) {
                    
                return false;
                }
                
                
            }
        }
        return true;
    }
    

  //printing the board
     void write(ostream & ostr) const  {
        for (int row = 0; row < incomplete.size(); row++)
        {
            for (int col = 0; col < incomplete[row].size(); col++)
            {
                if(getSquare(row,col)!=-1){
                    
                    std::cout<<getSquare(row,col)<<"  ";
                 }
            }
         
                
            }
     }
    
        vector<unique_ptr<Searchable> > successors() const  {
            //making an empty vector
            
            vector<unique_ptr<Searchable> > suc;
            suc.clear();
            int rows=0;
            int cols=0;
            std::set<int>option;
            
            for(int num=1;num<10;num++){
                
                option.insert(num);
            }
        
            
                        
        for (int row = 0; row < incomplete.size(); ++row)
                        {
    for (int col = 0; col<incomplete[row].size(); ++col)
                            {
                                if (incomplete[row][col].size()>1)  {
                                    cols=col;
                                    rows =row;
                                    option=incomplete[row][col];
                               
                                }
                            }
                        }
         
                        if (option.size()!=10){
                            auto itr = option;
                            for (itr:option){
                                //making a copy fof the current sudoku object
                                Sudoku * sudokuBoard = new Sudoku(*this);
                                if (sudokuBoard->setSquare(rows,cols,itr)){
                                    
                            suc.push_back(unique_ptr<Searchable>(sudokuBoard));
                                }
                                
                         
                            
                        
            if(option.size()==10){
                
                delete(sudokuBoard);
            }
                            }
                        }           return suc;
                        
                    }



};




#endif