// g++ "list of prime numbers.cpp" -std=c++2a

// https://www.codewars.com/kata/521ef596c106a935c0000519

#include <iostream>
#include <vector>

// ---------------------
// 0  Вариант.
// Это Тривиальное решение, которое приходит на ум, при прочтении мельком статьи на википедии о "Решето Эротосфена".
std::vector<unsigned> prime(unsigned n)
{
  if (n < 2)
    return {};
  
  std::vector<unsigned> v(n-1);
  
  for (int i = 0; i < v.size(); i++)
    v[i] = i+2;
  
  for (int i = 0; i < v.size(); i++)
    for (int j = i+1; j < v.size(); j++)
       if ( v[j] % v[i] == 0 )
         v.erase(v.begin()+j);
         // Но, Удаление из вектора - дорогая операция, по этому перепишем программу следеющем образом. См. Варианты ниже!
            // I  Вариант : Будем не удалять, а просто пемечать индекс false'ом (где индекс это само число которое проверяем на простоту).
            // II Вариант : Будем использовать контейнер, у которого удаление быстрее чем у Вектора.
    
  return v;
}

// ---------------------
// I  Вариант
std::vector<unsigned> prime_2(unsigned n)
{
  if (n < 2)
    return {};
  
  std::vector<bool> v(n-1, true);

  int prime_num = n-1;
  
  for (int i = 2; i <= n; i++)
    for (int j = i+1; j <= n; j++)
       if ( j % i == 0 )
       {
         v[j-2] = false;
         
         prime_num--;
         break;
       }
  
  std::vector<unsigned> res;
  res.reserve(prime_num); // since C++20 reserve() is constexpr // Но, Чтобы не происходило перевыделение под новый вектор, когда делаем push_back(), нужно сразу назначить ему размер. по этому исполльзуем РЕЗЕРВ // Или можно еще просто юзать другой контейнер у которого вставка быстрее чем у Вектора, Да?
  
  for (int i = 0; i < v.size(); i++)
    if (v[i])
    {
      res.push_back(i+2); // либо юзать ’res[j++] = i+2;’ Но нужно создавать новую переменную счетчик j. И делать не reserve, а создавать сразу вектор иниц-ый размером prime_num.
      
      // std::cout << res.capacity() << std::endl; // Тут всегда должно быть prime_num
    }
    
  return res;
}
// ---------------------
// ...

// ---------------------
int main()
{
  std::vector<unsigned> expected = {2,3,5,7,11,13,17,19,23};
  std::vector<unsigned> real     = prime_2(23);
  
  // assert_eq(real, expected);

  for (const auto &i : real)
  {
    std::cout << i << ", ";
  }

  return 0;
}