#include<iostream>

void fun(){
    static int x = 0;
    x++;
    std::cout<<"x: "<<x<<std::endl;
}

int main(){
    fun(); //1
    fun(); //2
    fun(); //3
    //WHY so? is initialized ONCE only. Then persists entire program lifetime. 
    //DATA storage: stored in static/global data segment

    //Since c++11 Initialization is thread-safe.

    ////// static global variable /////////
    static int x = 10; //at file scope, meaning internal linkage

    // What is linkage?
    //Controls visibility across translation units (.cpp files).

    //without static, external linkage. meaning visible to other files via extern.
    //WITH static visible ONLY inside current .cpp file.

    ///////// static function(global) ////////
    // static void helper(){}  //function visible only inside current file. Again internal linkage
    //modern c++ prefer touse anonymous namespace instead.


    ///////// static class member variable /////////
    /*
        class A{
            public:
                int x;
                static int count;
        };

        Static member variable belongs to:
            class itself
        NOT individual objects.

        
        A a1;
        A a2;
        
        Memory:
        a1.x
        a2.x
        shared A::count

        //Static member variable is NOT stored inside object.

        //sizeof(A) does NOT include static members.

        //Defination required
        int A::count = 0; //MUST define outside
        WHY? Because storage must actually be allocated somewhere.

        //Since C++17, can use
        class A{
            public:
                inline static int count = 10;
        };
    */


   //////////// static member function ////////////
   /*
        class A{
            public:
                static int fun(){}
                //Static member function has: no hidden this pointer
                // Because function belongs to class itself. NOT object.
                //therefore this is INVALID inside static function

                //static void fun() {
                    std::cout << this; //compiler error
                }
        };
   */


    //////////// CONSEQUENCES///////////
    /*
    
        class A {
        int x;
        static int y;
        public:
            static void f() {
                y = 10; // OK
                x = 5;  // ERROR
            }
        };

        // WHY?
        No object exists.
        No hidden this.
        So compiler doesn't know WHICH object's x.
    */

   ////////////// STATIC OBJECTS ////////////
   /*
   
    static A obj;
    Lifetime:
        Entire program lifetime.
    Constructed:
        before main()
    Destroyed:
        after main()
   */




  ///////////// THREAD-SAFE STATIC LOCAL ///////////
  /*
    A& getInstance() {
        static A obj;
        return obj;
    }

    Since C++11
    Initialization guaranteed thread-safe.
  */

    ////////////////// FINAL TAKEAWAYS ////////////
    /*
        static local → persists entire program
        static global → file-only visibility
        static class member → shared across all objects
        static member function → no hidden this
        static members not stored inside objects
        static affects lifetime/linkage/ownership depending on context
    */
    return 0;
}