//
//  main.cpp
//  ground-picking
//
//  Created by 정현민 on 2020/11/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> land_vec_vec;
vector<vector<int>> memo_vec_vec;
vector<int>::size_type row_size;
vector<int>::size_type col_size;


int getMax(int row, int col)
{
  if (row == row_size)
  {
    return 0;
  }
  if (memo_vec_vec[row][col] != 0)
  {
    return memo_vec_vec[row][col];
  }
  int max_temp = 0;
  for (int i = 0; i < col_size; i++)
  {
    if (i == col)
    {
      continue;
    }
    max_temp = max(max_temp, getMax(row + 1, i));
  }
  memo_vec_vec[row][col] = land_vec_vec[row][col] + max_temp;
  return memo_vec_vec[row][col];
}

int solution(vector<vector<int>> land_vec_vec_temp)
{
  land_vec_vec = land_vec_vec_temp;
  row_size = land_vec_vec.size();
  col_size = land_vec_vec[0].size();
  memo_vec_vec.resize(row_size, vector<int> (col_size));
  
  int output = 0;
  for (int i = 0; i < col_size; i++) // 각각의 열에서 출발
  {
    output = max(output, getMax(0, i));
  }
  return output;
}

int main(int argc, const char * argv[]) {
  vector<vector<int>> input_vec_vec;
  input_vec_vec = {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}};
  
  int output = solution(input_vec_vec);
  cout << output << endl;
  return 0;
}
