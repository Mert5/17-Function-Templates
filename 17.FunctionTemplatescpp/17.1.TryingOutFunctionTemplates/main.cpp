#include <iostream>
#include <string>

// REFERENCE => freeCodeCamp.org

template <typename T>   // the syntax
/*int maximum(int a, int b){
    return (a > b)? a : b;
}*/

T maximum(T a, T b){    // compiler will change T's into 'int' because there is int in main
    return (a >b)? a : b;   // if you try to pass DIFFERENT type of parameters, it will give an ERROR.
}

template <typename T>   // you can write more than once
T multiply(T a, T b){
    return a * b;
}


int main(){

    int m{14};
    int n{16};
    auto result = maximum(m,n);
    
    std::cout << "Maximum of " << m << " and " << n << " is : " << result << std::endl;
    std::cout << "Address of m value : " << &m << " and address of n value : " << &n << std::endl;
    
    int *p1 {&m};
    int *p2 {&n};

    auto result2 = maximum(p1,p2);  // in this situation, it will compare the addresses.
                                // even if the value is lower, if the address value is bigger, it will be the maximum
                                // so this is bad. It may give you a wrong result when you work with pointers.
    std::cout << "Maximum is : " << result2 << " and the value is : " << *result2 << std::endl;
    
    auto res2 = multiply(m,n);

    std::cout << "Result is : " << res2 << std::endl;
    
    /*
    std::string word1{"Hello"};
    std::string word2{"World"};

    auto result3 = multiply(word1, word2);
    std::cout << "The result is : " << result3 << std::endl; //so this will give you error because you can't multiply two strings.
                                                        // arguments passed to a function template must support operations.
    */  
    return 0;
}