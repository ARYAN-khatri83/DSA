#include<iostream>
using namespace std;

class Hero{
    // properties

    private:
    int health;

    public:
    char level;

    static int timeToComplete;
     Hero() {
        cout << " Constructor called " << endl;
    }
/*
    // Parameterized constructor
    Hero(int health){
       // health = health; // it means like if health ki value 3 h toh hamne vahi fir se isme dal di but we
        // want to put the value of health which is in line 8 so will use this pointer.
        this -> health = health;
    }
    */

   // parametrisez constructor
   Hero(int health){
    this -> health = health;
   }

   Hero(int health , char level){
    this -> level = level;
    this -> health = health;
   }

   // copy contructor
   Hero(Hero& temp){
    cout << "Copy constructor called " << endl;
    this -> health = temp.health;
    this -> level = temp.level;
   }
    
    void print(){
        cout << "health" << this->health << endl;
        cout << "level" << this->level << endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }
    
    // static function
    static int random(){
        return timeToComplete;
    }

    // Destructor
    ~Hero() {
        cout << " Destructor bhai called " << endl;
    }



};
// Static keyword
int Hero::timeToComplete = 5;

int main(){

// for static keyword
//    cout << Hero :: timeToComplete <<endl;
    
    // for static function
    cout << Hero :: random() << endl;



/*
    // static for destructor
    Hero a;

    // dyanmic for destructor
    Hero *b = new Hero();
    // manually destructor call
    delete b;

*/




    /*

    // object created statically
    Hero ramesh;

    // dynamically
    Hero *h = new Hero();
*/

/*
   // for paramterized constructor
   Hero ram(10);
   cout << "Address of ram" << &ram << endl;
   ram.getHealth(); // they contains the same address
   // this is pointer to the current object

*/

   // for copy contructor
/*
   Hero S(70,'c');
   S.print();

   // this one copies
    Hero R(S);
    R.print();

*/
    /*

    // create obj using static allocation 
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout << "level is " << a.level << endl;
    cout << " helath is " << a.getHealth() << endl;

    // create obj using dynamically allocation
    Hero *b = new Hero;
    b->setLevel('A');
    b->setHealth(70);
    cout << "level us " << (*b).level << endl;
    cout << " health is " << (*b).getHealth() << endl;

    cout << " level is " << b->level << endl;
    cout << " health is " << b->getHealth() << endl;

    // creation of object
    // Hero ramesh;
    // cout << " Size of ramesh is " << sizeof(ramesh) << endl;

    // cout << " ramesh health is " << ramesh.getHealth() << endl;

    // use setter
    // ramesh.setHealth(70);
    // ramesh.level = 'A';

    //cout << " health is : " << ramesh.getHealth() << endl;
    // cout << "Level is : " << ramesh.level << endl;

    // cout << " size : " << sizeof(h1) << endl;

*/
    return 0;
}
