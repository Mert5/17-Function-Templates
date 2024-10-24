#include <iostream>
#include <string>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

template <typename T> T maximum(T a, T b){  // a and b should be the same type
    return (a > b)? a : b;
}

int main(){

    int m{46};
    int n{57};
    double o{71.3};
    double q{19.4};
    std::string w1{"Oklahoma"};
    std::string w2{"Denver"}; 
    
    // auto result = maximum(m,q); // if you write like this, there will be compiler error because m and q diff. types

    // Explicit template arguments  // by using this, you can pass different type of arguments.

    auto max = maximum<double>(n,o);
    std::cout << "max : " << max << std::endl;

    return 0;
}