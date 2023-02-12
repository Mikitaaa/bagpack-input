//  Первая строка содержит количество предметов
//  и вместимость рюкзака.Каждая из следующих
//  n строк задаёт стоимость и объём предмета
//  Выведите максимальную стоимость частей предметов (от каждого предмета можно
//  отделитлюбую часть, стоимость и объём при этом пропорционально уменьшатся),
//  помещающихся в
//  данный рюкзак, с точностью не менее трёх знаков после запятой.

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Item final {
    double weight_;
    double value_;
};

double get_max_knapsack_value(int capacity, std::vector <Item> items) {
  double value = 0.0;

    std::sort(items.begin(),items.end(),[](Item &I1,Item &I2){
            return (I1.value_/I1.weight_)>=(I2.value_/I2.weight_);
        });
  // take items while there is empty space in knapsack
  for (auto &item:items) {
    if (capacity > item.weight_) {
      // can take full item and continue
      capacity -= item.weight_;
      value += item.value_;
    } else {
      value += item.value_ * (static_cast <double>(capacity) / item.weight_);
      break;
    }
  }

  return value;
}

int main(void) {
  int number_of_items;
  int knapsack_capacity;
  std::cin >> number_of_items >> knapsack_capacity;
  std::vector <Item> items(number_of_items);
  for (int i = 0; i < number_of_items; i++) {
    std::cin >> items[i].value_ >> items[i].weight_;
  }

  double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

  std::cout.precision(10);
    std::cout << std::fixed << std::setprecision(3) << max_knapsack_value << std::endl;
  return 0;
}
