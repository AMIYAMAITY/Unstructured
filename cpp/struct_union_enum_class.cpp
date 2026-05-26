#include<iostream>

struct Struct
{
    double d; //start with divisible 8 address  and it takes 8 bytes, so it's: 8 bytes
    char c; //start with divisible 1 address and it takes 1 bytes, so it's 1 btypes BUT padding 3 more bite will add for next int types. so it's 4 byte in this case
    int a; // 4 bytes same for above
    //total 16 bytes
    //as it alignment with proper divisible address it called allignment and adding extra bytes it caled padding
};

struct Bad{
    char c1;//start with 0
    double d;//then start wil 8 divisible address to 15
    char c2; //placed at 16 but add trail paading whcih is max of alignment size which is 8
    //total taking 24 bytes
};

struct Good{
    double d;
    char c1;
    char c2;
    //total taking 16 bytes
};

#pragma pack(push, 1)
struct Pstruct{
    char c;
    int i;
    //total taking 5
    //but dangerous
    // Misaligned access:
    // slower
    // hardware penalties
    // possible crashes on some architectures
};
#pragma pack(pop)


//Manual alignment control
struct alignas(16) A {
    int x;
    //total: 16 bytes
};


/////////////////////////////////////////////////////////////////////////////////////////
//UNION

union U{
    int i;
    double d;
};

struct JsonValue
{
    enum Type{
        INT,
        FLOAT,
        BOOL
    }type;

    union{
        int i;
        float f;
        bool b;
    };
};

int main(){
    Struct a[3];
    std::cout<<"Struct size: "<<sizeof(Struct)<<std::endl;
    std::cout<<"Struct array size: "<<sizeof(a)<<std::endl;

    std::cout<<"Bad struct size: "<<sizeof(Bad)<<std::endl;
    std::cout<<"Good struct size: "<<sizeof(Good)<<std::endl;

    std::cout<<"Pstruct struct size: "<<sizeof(Pstruct)<<std::endl;

    std::cout<<"Astruct struct size: "<<sizeof(A)<<std::endl;

    /////////union////////
    U u;
    u.i = 10;
    u.d=77.4;

    std::cout<<"Union u i:"<<u.i<<" d:"<<u.d<<std::endl; //u.i give garbage vlaue because u.d overwrites

    JsonValue jv;

    jv.type = jv.Type::BOOL;
    jv.b = true;

    if(jv.type == jv.Type::BOOL){
        std::cout<<"jv bool: "<<jv.b<<std::endl;
    }

    jv.type = jv.Type::INT;
    jv.i = 13;

    if(jv.type == jv.Type::INT){
        std::cout<<"jv int: "<<jv.i<<std::endl;
    }


    jv.type = jv.Type::FLOAT;
    jv.f = 3.14;

    if(jv.type == jv.Type::FLOAT){
        std::cout<<"jv float: "<<jv.f<<std::endl;
    }

    //////////////////////////////////// ENUM /////////////////////////////
    // enum Color{
    //     Red,
    //     Green
    // };

    // enum TrafficLight{
    //     Red, //redefinition of enumerator 'Red'; This is happening Both inject names into same scope. we should use enum class
    //     Green
    // };
    

    enum class Color{
        Red,
        Green
    };

    enum class TrafficLight{
        Red, //now it's fine 
        Green
    };

    std::cout<<"enum size: "<<sizeof(Color)<<std::endl; //4

    enum class Test : uint8_t{
        Red, 
        Green
    };
    std::cout<<"enum size: "<<sizeof(Test)<<std::endl; //1

    //////////////////////////////// class ////////////////////////////////////
    class A{
        int x;
        public:
            void f();
    };

    //Object memory it stores only data member
    // like: [x] not [x][f]
    //WHY?
    //Functions exist once globally in code segment.
    //All objects share them.



    /////// hidden this pointer /////////
    /*
        a.f();

        Compiler roughly transforms into:
        A::f(&a);

        //Actual internal idea
        void f(A* this)
    */ 

   /////// Access Specifier /////////
   /*
        public
        private
        protected
   */

  ///////// CONSTRUCTORS //////
  /*
    Constructor purpose: Initialize object correctly.
    class A{
        int x;
        public:
            A(int v) : x(v) {}
    };
  
  */


 ////////// DESTRUCTORS ////////
 /*
    DESTRUCTORS purpose: Cleanup resources automatically.
    ~A() {}
 */

    //Empty class size is 1, WHY not 0? => Objects need unique addresses.


    /////// VIRTUAL FUNCTIONS/////////
    /*
        class A{
            int x;
            public:
                virtual void f();
        };

        Compiler adds hidden vptr inside object.
        Object layout
        [vptr][members]

        vptr points to:
        vtable

        vtable stores:
            > function addresses
            > RTTI info

        It enables runtime polymorphism
    */


   /////////// MEMORY COST OF VIRTUAL///////////
   /*
   Without virtual:
   class A{
        int x;
   };
   Likely: 4 bytes


   class A{
        virtual void f();
        int x;
   };
   16 bytes (64-bit systems)
   because:
        vptr = 8 bytes
        alignment padding
   */

  ///////// CLASS VS STRUCT/////////
  /*
  
    default access =>  struct: public      class: private
  */

    ////////// CLASS AS ABSTRACTION///////////
    /*
    Classes define:
        invariants
        ownership
        interfaces
        encapsulation
        polymorphism
    
    */




   ////////////// KEY TAKEWAYS ////////////
   /*
    ENUM
    Q1: Difference between enum and enum class?
    Q2: Why specify underlying type?
    Q3: Why enums useful for flags?

    CLASS
    Q4: Where are member functions stored?
    Q5: What is hidden this pointer?
    Q6: Why empty class size = 1?
    Q7: What virtual adds internally?




    At the deepest level:
        Feature	Really About
        enum	symbolic integral values
        enum class	stronger type system
        class	object memory + compiler transformations
        virtual	runtime dispatch mechanism
   */
    return 0;
}