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
  vector v = {1, 2, 3, 4, 5, 6, 7};
  print("{}\n", v);
  //how to use erase and insert
  v.erase(next(v.begin()));
  print("{}\n", v);

  //advance doesn't return value.
  auto i = v.begin();
  advance(i, 1);
  v.insert(i, 2);
  print("{}\n", v);


  //remember rd and mt. 
  random_device rd;
  mt19937 mt{rd()};
  shuffle(v.begin(), v.end(), mt);
  print("{}\n", v);

  //insert sort
  for(auto i = v.begin(); i!=v.end(); ++i){
    std::rotate(std::upper_bound(v.begin(), i, *i), i, next(i));
  }
  print("{}\n", v);

  //selection sort
  shuffle(v.begin(), v.end(), mt);
  for(auto i = v.begin(); i!=v.end(); ++i){
    auto min = min_element(i, v.end());
    iter_swap(i , min); //not swap_iter
  }
  print("{}\n", v);

  auto l = [](const auto &e ){return e%2 == 0;};
  println("{}", ranges::all_of(v, l));
  println("{}", ranges::any_of(v, l));
  println("{}", ranges::none_of(v, l));

  vector<int> v1;
  v1.reserve(v.size());
  v1.resize(v.size());
  v1.assign(v.begin(), v.end());
  println("{}", v1);

  println("{}",ranges::equal(v, v1));
  println("{}",ranges::lexicographical_compare(v, v1));

  v1.insert(v1.begin(), 10);

  //auto& doesn't work here. 
  auto [i1, i2] = ranges::mismatch(v, v1);

  cout<<*i1<<" "<<*i2<<endl;

  //size empty swap max_size
  //begin, end, rbegin, rend, insert, erase clear
  //push_back, pop_back, front(), back(), resize
  //[], reserve, capacity 

  //ACCMFS 
  // how to use projection?

  vector<Student> vs{{3,"yan"}, {2, "zhao"}, {1, "aa"}};
  println("found {}", ranges::count(vs, "aab", &Student::name_));
  // how to use senital?
  //build sential type and overload == operator inside. 
  println("{}", ranges::count(vs.begin(), Sentinal{}, 3, &Student::id_));

  // how to use view and ranges::to
  auto vv = v1|views::transform([](auto e){return e*e;});
  for(const auto &e :  vv) {
    cout<<e<<" ";
  }
  auto vv1 = vv|ranges::to<vector<int> >();
  ranges::sort(vv1);
  println("{}",vv1);

  // tow questions below: 1) ranges::subrange. 
  //2) std::iota iterator and projection.
  vector<decltype(vs.begin())> vsi (vs.size());
  std::iota(vsi.begin(), vsi.end(), vs.begin());
  ranges::sort(vsi, {}, &Student::id_);
  for(auto e : vsi){
    cout<<e->id_ << " "<< e->name_ <<endl;
  }

}	