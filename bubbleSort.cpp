#include <iostream>
#include <cstdlib>

using namespace std;


class Lista{
  private:
    int array[50];
    int cont;
  public:

    Lista(){
      cont=0;
    }

    void addElements(){
      int cantidad, u;

      cout<<"\nCuantos elementos desea agregar?"<<endl;
      cin>>cantidad;

      for(int i=0; i<cantidad; i++){
        cout<<"\nIngrese valor para elemento en la posicion "<<cont<<endl;
        cin>>u;
        array[cont] = u;
        cont++;
      }

    }

    void bubbleSort(){
      int aux;

      for(int j=0; j<cont-1; j++){
        for(int i=cont-1; j<i; i--){
          if(array[i]<array[i-1]){
            aux = array[i];
            array[i] = array[i-1];
            array[i-1] = aux;
          }
        }
      }
    }

    void eliminar(int index){
      if(index>=0 && index<cont){
        for(int i=index; i<cont; i++){
          array[i] = array[i+1];
        }
        cont--;
      }else{
        std::cout << "\nIndice no valido" << '\n';
      }
    }

    void display(){
      cout << "\n"<<'\n';
      for(int i = 0; i<cont; i++){
        std::cout<<"Posicion "<<i<<": "<<array[i]<<endl;
      }
    }

};

int menu(){
  int opc;
  cout<<"\n 1.- Agregar elementos"

  "\n 2.- Ordenar"

  "\n 3.- Eliminar elemento por indice"

  "\n 4.- Mostrar Todo"

  "\n 5.- Salir"<<endl;
  cin>>opc;

  return opc;

}

int main(){
  Lista lista;
  int opc;

  do {
    opc = menu();

    switch (opc) {
      case 1:
      lista.addElements();
      break;

      case 2:
      lista.bubbleSort();
      break;

      case 3:{
        int pos;

        cout<<"\nIngrese el indice del elemento a eliminar"<<endl;
        cin>>pos;

        lista.eliminar(pos);
      }

      break;

      case 4:
      lista.display();
      break;

      case 5:
      std::cout << "\n Proceso Terminado" << '\n';
      break;

      default: std::cout << "\n Opcion no disponible" << '\n';
    }
  } while(opc!=5);

}
