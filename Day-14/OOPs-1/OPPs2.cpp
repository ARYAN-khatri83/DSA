// ENCAPSULATION

/*
#include<iostream>
using namespace std;

class student{
    private:
    string name;
    int age;
    int height;
    
    public:
    int getAge(){
        return this->age;
    }
};

int main(){
    student first;

    cout << "ok" << endl ;
    return 0;

}

*/


// INHERITANCE

#include<iostream>
using namespace std;

/*
 Accessing public with public

class Human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }
    void setWeight(int w){
        this->weight = w;
    }
};

// child class
class Male:public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping";
    }
};

int main(){
    Male object1;
    cout<<object1.age<<endl;
    cout<<object1.height<<endl;

    object1.setWeight(83);
    cout << object1.weight << endl;
    object1.sleep();

    return 0;
}
*/

// Accessing PUBLIC WITH PROTECTED 

// IN THIS WE CAN ONLY ACCESS EITHER INSIDE THE CLASS OR THROUGHT A SETTER AND GETTER

/*
class Human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }
    void setWeight(int w){
        this->weight = w;
    }
};

// child class
class Male:protected Human{
    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping";
    }

    int getHeight(){
        return this->height;
    }
};

int main(){
    Male object1;
   cout << object1.getHeight() << endl;

    return 0;
}
*/

// ACCESSING PUBLIC WITH PRIVATE

/*
class Human{
    public:
    int height;
    int weight;
    
    private :
    int age;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

// child class
class Male:private Human{
    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping";
    }
    public:
    int getHeight(){
        return this->height;
    }
};

int main(){
    Male object1;
    cout<<object1.getHeight()<<endl;
    return 0;
}

*/

// MAIN CLASS IS PROTECTED AND INHERITS IN PUBLIC WAY

// in this if we try to do we get protected and and if protected protected then also we get protected and if protected privare then we get a private class
/*
class Human{
    protected:
    int height;
    public:
    int weight;
    
    private :
    int age;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

// child class
class Male:public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping";
    }
    public:
    int getHeight(){
        return this->height;
    }
};

int main(){
    Male object1;
    cout<<object1.getHeight()<<endl;
    return 0;
}
*/

// PRIVATE WITH PUBLIC , PROTECTED AND PRIVATE ALL WILL BE NOT ACCESSIBLE

// SINGLE INHERITANCE

/*

class Animal{
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"speaking"<< endl;
    }
};

class Dog : public Animal{

};

int main(){
    Dog d; // we created a object here through which we can access the attributes
    d.speak();
    cout<< d.age << endl;
}

*/

// MULTI-LEVEL INHERITANCE

/*

class Animal{
    public:
    int age;
    int weight;

    public:
    void speak(){
        cout<<"speaking"<< endl;
    }
};

class Dog : public Animal{

};

class Lebra : public Dog{

};

int main(){
    Lebra l;
    l.speak();
}

*/

// MULTIPLE INHERITANCE
/*
class Animal{
    public:
    int age;
    int weight;

    public:
    void bark(){
        cout<<"barking"<< endl;
    }
};

class Human{
    public:
    string color;

    public:
    void speak(){
        cout << "Speaking" << endl;
    }
};

// this is multiple inheritance
class Hybrid: public Animal , public Human{

};

int main(){
    Hybrid h;
    h.speak();
    h.bark();
}

*/


// HIERARICAL INHERITANCE

/*
class A{
    public:
    void func1(){
        cout << "Inside Function 1" << endl;
    }
};

class B:public A{
    public:
    void func2(){
        cout << "Inside Func 2" << endl;
    }
};

class C :public A{
    public:
    void func3(){
        cout << "Inside Func 3 " << endl;
    }
};

int main(){


    A obj1;
    obj1.func1();

    B obj2;
    obj2.func1();
    obj2.func2();

    C obj3;
    obj3.func1();
    // it wont inherit this cuz it is not related obj3.func2();
    obj3.func3();
}

*/

// INHERITANCE AMBIGUITY
/*
class A {
    public:

    void func() {
        cout << " I am a" << endl;
    }
};

class B {
    public:
    void func(){
        cout << " I am B" << endl;

    }
};

class C : public A ,public B{

};

int main(){
    C obj;
    // we cant call it like this as we same namefor the fun of each class and it will create a prblm
    // obj.fucn();

    // So we will use Scope resolution operator
    obj.A::func();
    obj.B::func();
}
*/

 // POLYMORPHISM
// COMPILE TIME
/*
 class A{ 
    public:
    void sayHello(){
        cout << "Hello" << endl;
    }

    int sayHello(char name){
        cout << " hello ulu" << endl;
        return 1;
    }

    void sayHello(string name){
        cout << "Hello" << name << endl;
    }
 };

int main(){
    A obj;
    obj.sayHello();

return 0;
}
 
// OPERATOR OVERLOADING

class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Love Babbar" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

};

class B {
    public:
    int a;
    int b;

    public: 
    int add() {
        return a+b;
    }

    void operator+ (B &obj) {
      int value1 = this -> a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
        
       cout << "Hello Babbar" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->a << endl;
    }

};

// RUNTIME POLYMORPHISAM - METHOD OVERRIDING
class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {

    public:
    void speak() {
        cout << "Barking " << endl;
    }


};



int main() {

    Dog obj;
    obj.speak();




/*
    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();




    A obj;
    obj.sayHello();
    


    return 0;
}
*/




