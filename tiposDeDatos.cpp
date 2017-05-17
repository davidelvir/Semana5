//identificacion de tipos de datos
#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;

class Base{
  virtual void foo(){}
};

class Derivada:public Base{
  virtual void foo(){}
};

class DerivadaDos:public Derivada{
  virtual void foo(){}
};

int main(){

  Base base;
  Derivada derivada;
  DerivadaDos derivada2;
  
  //typeid.name devuelve el tipo de dato y cuantos char tiene el nombre
  cout<<"Clase Base: "<<typeid(base).name()<<endl;
  cout<<"Clase Derivada: "<<typeid(derivada).name()<<endl;
  cout<<"Clase Derivada2: "<<typeid(derivada2).name()<<endl;

  if(typeid(Base) == typeid(base)){
    cout<<"La variable es tipo Base."<<endl;
  }

  //apuntadores
  Base* variable = new Derivada();

  cout<<"EL tipo de la variable es: "<<typeid(*variable).name()<<endl;
  //si no hay polimorfismo me devuelve la clase padre 
  //si hubiera polimorfismo me devuelve la instancia

  if(typeid(Base)==typeid(*variable)){
    cout<<"Apuntador a Base"<<endl;
  }
  delete variable;

  //strings
  string cadena = "Hola mundo";
  cout<<typeid(cadena).name()<<endl;

  cout<<cadena[1]<<endl;//devuelve el char en esa posicion
  
  int val = cadena[1];
  cout<<val<<endl;

  cadena[1] = val + 1;

  cout<<cadena<<endl;
  
  cadena.push_back('s');

}
