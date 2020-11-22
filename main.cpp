//
//  main.cpp
//  ground-picking
//
//  Created by 정현민 on 2020/11/21.
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> land_vec_vec;
vector<int>::size_type row_size;
vector<int>::size_type col_size;

int getMax(int max, int row, int col)
{
  if (row == row_size)
  {
    return 0;
  }
  cout << row << " - " << col << " - " << max << endl;
  
  int max_temp = 0;
  for(int i = 0; i < col_size; i++)
  {
    if(i != col)
    {
      continue;
    }
    int temp = getMax(max + land_vec_vec[row][col], row + 1, i);
    if(max_temp < temp)
    {
      max_temp = temp;
    }

  }
  
  return max_temp;
}

int solution(vector<vector<int>> land_vec_vec_temp)
{
  land_vec_vec = land_vec_vec_temp;
  row_size = land_vec_vec.size();
  col_size = land_vec_vec[0].size();
  int output = getMax(0, 0, 0);
  
  return output;
}

int main(int argc, const char * argv[]) {
  vector<vector<int>> input_vec_vec;
  input_vec_vec = {{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}, {7, 6, 5, 4}};
  
  int output = solution(input_vec_vec);
  cout << output << endl;
  return 0;
}
