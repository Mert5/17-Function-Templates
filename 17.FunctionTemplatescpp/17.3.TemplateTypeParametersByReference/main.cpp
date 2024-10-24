#include <iostream>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

template <typename T> T maximum(T a, T b);  // Declaration
template <typename T> const T& maximum2(const T& a, const T& b);  // Declaration
// If you used same function name, there would be compiler error! Use different name.

int main(){

    double a{13.6};
    double b{15.7};

    std::cout << "Outside -&a : " << &a << std::endl;       // 0x101abc(same)
    auto result = maximum(a,b); 
    std::cout << "Outside, and after call -&a : " << &a << std::endl;   // 0x101abc(same)
    
    std::cout << std::endl;
    
    std::cout << "Outside -&a : " << &a << std::endl;       // 0x101abc(same)
    auto result2 = maximum2(a,b); 
    std::cout << "Outside, and after call -&a : " << &a << std::endl;   // 0x101abc(same)
    

    return 0;
}

template <typename T> T maximum(T a, T b){  // Definition
    std::cout << "Inside -&a : " << &a << std::endl;        // 0x102bbc (different address - this means a copy - not original)
                                                            // because we are passing by value
    return (a > b)? a : b;  
}

template <typename T> const T& maximum2(const T& a, const T& b){  // Definition
    //a++; // you would take compiler error because you defined 'a' as 'const'
    std::cout << "Inside -&a : " << &a << std::endl;        // 0x101abc (same address - this means an original)
                                                            // because we are passing by reference
    return (a > b)? a : b;  
}