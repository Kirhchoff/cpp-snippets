#include <iostream>
#include <type_traits>
#include <optional>

// Primary template
template <typename T, typename U = int>
struct has_id : std::false_type { };

// Specialization for U = int
template <typename T>
struct has_id <T, decltype((void) T::id, 0)> : std::true_type { };


class TTT {
    public:
    int x;
};

    
using namespace std;
struct X { int id; };
struct Y { int foo; };

int main()
{
    cout << boolalpha;
    cout << has_id<X>::value << endl;
    cout << has_id<Y>::value << endl;
    if constexpr(has_id<Y>::value) std::cout << "asd";
    
    std::optional<TTT> t;
    t->x = 10;
}