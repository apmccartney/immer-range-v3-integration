#include <iostream>
#include <type_traits>

#include <range/v3/all.hpp>
#include <immer/vector.hpp>

int main(){
  auto five = ranges::view::iota(1) | ranges::view::take(5);
  
  static_assert(not std::is_same<decltype(five.begin()), 
		                 decltype(five.end())>::value);

  std::cout << five << std::endl;

  immer::vector<decltype(five.front())> v{five.begin(), five.end()};

  std::cout << '[';
  RANGES_FOR(const auto& entry, v | ranges::view::take(4)){ 
    std::cout << entry << ',';
  }
  std::cout << v.back() << ']' << std::endl;
}
