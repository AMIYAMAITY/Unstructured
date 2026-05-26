#include<iostream>

int main(){
    ///////// AUTO /////////
    auto x = 10; //"Ask compiler to deduce the type from initializer."
    //internally 
    // int x = 10;

    // IMP: auto is NOT a type itself.
    //placeholder for deduced type

    ////////////// WHY AUTO EXISTS /////////////
    /*
        Before c++11:
        std::vector<std::pair<int, std::string>>::iterator it; //very verbose

        //After
        auto it = vec.begin();
    */


   // Basic auto ///
   /*
   auto z = "hello";
   IMP: const char* z = "hello"; NOT std::string
   */

  ////////////// AUTO REMOVES REFERENCES ///////////
  /*
    int a = 10;
    int& ref = a;

    auto z = ref;
    What is z?
        int NOT int&
  */


    //////////// AUTO + CONST ///////////
    /*
        const int x = 10;
        auto a = x;

        what us a?
            int only
            const removed.


        BUT

        const int* p;
        auto x = p;
        what is x?
            const int* //because pointee const preserved.


        //////// REFERENCES
        auto& x = p;
        now
            x is int& 

        
    VERY IMPORTANT
        You control deduction modifiers:
        auto
        auto&
        const auto&
        auto&&
    */


   //////////// AUTO AND COPIES //////////
    std::vector<int> v;
    for(auto x : v) //COPY OCCURS

    // Better
    // for(const auto& x : v) //no copy good omtimization
    



    /////////////////////////////// DECLTYPE //////////////////////
    /*
    decltype(expr)
    "Give me the EXACT type of expression."

    int x = 10;
    decltype(x) y = 19;
    => here y is int


    decltype preserves exact type information
    including:
        references
        const
        value category



    int& ref = p;
    decltype(ref) b = x;
    => b is int& BUT with auto it simply int
    */



   ///////// DECLTYPE RULES ///////////
   /*
    decltype(x)  // gives you the exact declared type

    decltype((x)) // int& because (x) is lvalue expression.

    IMP
    int x = 10;
    decltype(x) a = x;     // int
    decltype((x)) b = x;   // int&
   */


    //////////// DECLTYPE(AUTO) //////////
    /*
        decltype(auto) f(){
            return x;
        }

    Preserves:
        references
        const
        exact type

        Used in:
        generic libraries
        forwarding wrappers
    */


   ///////// REAL-WORLD USAGE ////////
   /*
    auto used for:
        iterators
        lambdas
        template-heavy code
        range loops

    decltype used for:
        template metaprogramming
        generic return types
        preserving exact types
   */


    //////////////////// INTERVIEW TRAPS ////////////////
    /*
    Trap 1
    auto x = ref;
    reference removed.

    Trap 2
    decltype((x))
    becomes reference.

    Trap 3
    auto x = {1,2,3};
    deduces:
    std::initializer_list<int>
    */

   //////////// Difference ///////////
   /*
    Feature	                   auto	    decltype
    removes refs	   usually yes	      no
    removes top const  usually yes	      no
    expression analysis	    limited	     exact
    preserves value category	no	      yes
   */

  
    return 0;
}