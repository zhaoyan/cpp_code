#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>
#include <iostream>
#include <array>
#include <stack>
#include <numeric>
#include <bitset>
#include <vector>
#include <print>
#include <random>
#include <map>
#include <string>
#include <type_traits>
#include <cctype>
#include <list>
#include <format>
#include <print>
#include <atomic>
#include <sstream>
#include <unordered_set>

using std::cout;
using std::endl;
using std::array;
using std::stack;
using std::accumulate;

using namespace std;

//use -std=c++23  -Wall -Wextra -Wdeprecated --stdlib=libc++ 
//support print container
  class Student{
  public:
  int id_;
  string name_;
  };

struct Sentinal{
    bool operator == (auto i) const{
      return (*i).id_ == 2;
    }
  };

template<typename T>
class Type;

int main() {
  array ar{1, 2, 3, 4, 5, 0};
  //insert at 1
  int i = ar.size();
  for(auto index = i-2; index >=1; --index){
    ar[index+1] = ar[index];
  }
  ar[1] = 100;
  println("{}", ar);

  // use shfit_right to achieve the same result.
  shift_right(ar.begin()+1, ar.end(), 1);
  println("{}", ar);

  //reverse
  array ar1{1, 2, 3, 100, 5, 6};
  size_t b = 0;
  size_t s = ar1.size();
  size_t e = s-1;
  for(; b<s/2; ++b, --e){
    swap(ar1[b], ar1[e]);
  }
  println("{}", ar1);
  
  nth_element(ar1.begin(), ar1.begin()+2, ar1.end() );
  println("{}", ar1);

  //two_sum, two points here:
  //1) unordered_set us{ar1.begin(), ar1.end()}; is not correct, it use init_list
  //2) ternary operator must inside ()
  //3) use contains here. 
  unordered_set us(ar1.begin(), ar1.end());
  cout<<us.size();

  int sum1 = 106;
  auto iter = find_if(ar1.begin(), ar1.end(), 
          [&](auto e){ return us.contains(sum1-e); });
  
  cout<< (iter!=ar1.end()? "found it" : "not found it" );

  //slide windows 
  array ar2{1, 2, 3, 100, 5, 6};
  size_t s_ar = ar2.size();
  size_t left = 0;
  size_t right = 0;
  int sum = 0;
  while(right<s_ar){
    
    sum+=ar2[right];
    if(sum<105)
      ++right;
    if(sum == 105){
      cout<<"find it--"<<left<<" "<<right<<endl;
      break;
    }

    while(sum>105){
      sum-=ar2[left];
      ++left;
    }
    if(sum == 105){
      cout<<"find it--"<<left<<" "<<right<<endl;
      break;
    }
  }

  //sliding windows to find the minimal windows. 
  string ss1 = "ADOBECODEBANC";
  string tt1 = "ABC";
  map<char, int> dict;
  size_t length = ss1.size();
  left = 0;
  right = 0;
  int min_dist = ss1.size();
  int min_left = 0;
  int min_right = 0;
  while(right<length){
    if(ss1[right] == 'A'||ss1[right] == 'B'||ss1[right] == 'C'){
      dict[ss1[right]]++;
    }
    ++right;
    while(dict.size()==3){
      cout<<"---"<<left<<" "<<right<<endl;

      if(ss1[left] == 'A'||ss1[left] == 'B'||ss1[left] == 'C'){
        --dict[ss1[left]];
        if(dict[ss1[left]] == 0){
          dict.erase(ss1[left]);
          if((right-left)< min_dist){
            min_dist = right-left;
            min_left = left;
            min_right = right;
          }
        }
      }
      ++left;
    }
  }
  cout<<"min"<<" "<<min_left<<" "<<min_right<<endl;


}	