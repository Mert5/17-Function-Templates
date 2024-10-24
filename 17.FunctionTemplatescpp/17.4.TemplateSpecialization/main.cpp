#include <iostream>
#include <cstring>

// Reference => https://www.youtube.com/watch?v=8jLOx1hD3_o
// (freeCodeCamp.org)

template <typename T> T maximum(T a, T b){  // when you use this to compare const* strings,
                                            // the one that has bigger address will be the result. But that's not true.
    return (a > b)? a : b;
}

template <>
const char * maximum <const char*>(const char* a, const char* b){   // to compare const* strings you should use this.
                                                                    // it gives the right alphabetic result
                                                                    // the later word will be the result
                                                                    // you can specify it according to your implementation
    return (std::strcmp(a,b) > 0)? a : b;
}

int main(){

    int m{7};
    int n{9};
    double o{8.3};
    double p{10.6};
    std::string w1{"Hello"};
    std::string w2{"World"};    

    auto max_int = maximum(m,n);             // int type deduced
    auto max_double = maximum(o,p);          // double type deduced
    auto max_str = maximum(w1,w2);   // string type deduced // which one comes later alphabetically, it is going to be greater

    std::cout << "max_int : " << max_int << std::endl;
    std::cout << "max_double : " << max_double << std::endl;
    std::cout << "max_str : " << max_str << std::endl;


    //
    const char* w3{"wild"};
    const char* w4{"pet"};

    // This WON'T do what you expect => BEWARE!!!
    std::cout << "max(const char*) : " << maximum(w3,w4) << std::endl;  

    return 0;
}