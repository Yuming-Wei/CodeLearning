//
//  ConnectedCellsInGrid.h
//  HiC++
//
//  Created by My AD on 8/25/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef ConnectedCellsInGrid_h
#define ConnectedCellsInGrid_h

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

static int cellCount = 0;
static vector<vector<int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

class ConnectedCellsInGridClass {
public:
    FILE *f;
    vector<string> gridStr;
    vector<vector<int>> gridInt;
    char str[1024*1000];
    string str1;
    int row, col;
    stack<pair<int,int>> posStk;
    
    void countConnectedCells_Recursive(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int row, int col) {
        // If out of bound, return
        if(x < 0 || x >= row || y < 0 || y >= col) return;
        // Not a cell or visited, return
        if(grid[x][y] == 0 || visited[x][y] == true) return;
        // Increment the cell
        cellCount++;
        // Set the lot as visited
        visited[x][y] = true;
        for(int i = 0; i < 8; ++i) {
            countConnectedCells_Recursive(grid, visited, x + direct[i][0], y + direct[i][1], row, col);
        }
    }
    
    int connectedCells_Recursive(vector<vector<int>>& grid) {
        int row, col, maxCount = 0;
        if((row = grid.size()) == 0) return 0;
        if((col = grid[0].size()) == 0) return 0;
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                countConnectedCells_Recursive(grid, visited, i, j, row, col);
                if(maxCount < cellCount) maxCount = cellCount;
                cellCount = 0;
            }
        }
        return maxCount;
    }
    
    int countConnectedCells_Iterative(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int row, int col) {
        // If out of bound, return
        if(x < 0 || x >= row || y < 0 || y >= col) return 0;
        // Not a cell or visited, return
        if(grid[x][y] == 0 || visited[x][y] == true) return 0;
        // Set the position as visited
        visited[x][y] = true;
        int xPosCircle, yPosCircle;
        for(int i = 0; i < 8; ++i) {
            xPosCircle = x + direct[i][0];
            yPosCircle = y + direct[i][1];
            if(xPosCircle >= 0 && xPosCircle < row && yPosCircle >=0 && yPosCircle < col) {
                if(gridInt[xPosCircle][yPosCircle] != 0) {
                    posStk.push(make_pair(xPosCircle, yPosCircle));
                }
            }
        }
        return 1;
    }
    
    int connectedCells_Iterative(vector<vector<int>>& grid) {
        int maxCount = 0;
        if(row == 0) return 0;
        if(col == 0) return 0;
        int xPos, yPos;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                posStk.push(make_pair(i, j));
                while(posStk.size() != 0) {
                    xPos = posStk.top().first;
                    yPos = posStk.top().second;
                    posStk.pop();
                    cellCount += countConnectedCells_Iterative(grid, visited, xPos, yPos, row, col);
                }
                if(maxCount < cellCount) maxCount = cellCount;
                cellCount = 0;
            }
        }
        return maxCount;
    }
    
    void run() {
        read();
//        cout << "Answer using iterative is " << endl << connectedCells_Iterative(gridInt) << endl;
//        cout << "Answer using recursive is " << connectedCells_Recursive(gridInt) << endl;
    }
    
    void read() {
        vector<int> line;
        f = fopen("resource/hard-test-case10x10.txt", "r");
        if(f == NULL) {
            cout << "No file open!" << endl;
            return;
        }
        
        while(fgets(str,10240,f) != NULL) {
            gridStr.push_back(str);
        }
        fclose(f);
        
        auto iter = gridStr.end();
        *iter += '\n';
        iter = gridStr.begin();
        row = stoi(*iter);
        iter++;
        col = stoi(*iter);
        
        for(auto it = gridStr.begin(); it != gridStr.end(); it++) {
            cout << *it << endl;
        }
        
        string number = "", lineStr;
        for(auto it = gridStr.begin() + 2; it != gridStr.end(); ++it) {
            for(int i = 0; i < (*it).length();++i) {
                if((*it)[i] != ' ' && (*it)[i] != '\n') {
                    number += (*it)[i];
                } else {
                    line.push_back(stoi(number));
                    number = "";
                }
                
            }
            gridInt.push_back(line);
            line.clear();
            lineStr = "";
        }
        
        for(int i = 0 ; i < gridInt.size(); ++i) {
            for(int j = 0; j < gridInt[0].size(); ++j) {
                cout << gridInt[i][j];
            }
            cout << endl;
        }
        
    }
    
    
};

#endif /* ConnectedCellsInGrid_h */
