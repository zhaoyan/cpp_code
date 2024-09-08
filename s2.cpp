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
  string str = "ab1234a";
  string fs = "abc";
  
  auto pos = str.find_first_not_of(fs);
  cout<<pos<<endl;
  cout<<str.substr(pos)<<endl;

  transform(fs.begin(), fs.end(), fs.begin(), ::toupper);
  cout<<fs<<endl;
  transform(fs.begin(), fs.end(), fs.begin(), ::tolower);
  cout<<fs<<endl;
  string fsn = "123";
  cout<<stoi(fsn)<<endl;

  vector<int> v {1, 2, 3, 4, 5, 6};

  string result = "";
  int count = 0;
  for(auto i = v.begin(); i!=v.end(); ++i){
    result.push_back(*i+'0');
    ++count;
    if(count%3 == 0 && i != std::prev(v.end())){
      result.push_back(',');
    }
  }
  cout<<result<<endl;
  string sss = "zhao  , Yan  , 13,";
  stringstream ss(sss);
  string part;
  while(getline(ss, part, ',')){
    cout<<part<<"***"<<endl;
  }

  cout<<"---"<<endl;
  string word = "  abc  ";
  auto vv = word|views::drop_while([](char c){return isspace(c);})|views::take_while([](char c){return !isspace(c);});
  //string result1 = vv|ranges::to<string>();
  auto vc = views::common(vv);
  string result1(vc.begin(), vc.end());
  cout<<"**"<<result1<<"**"<<endl;

}	