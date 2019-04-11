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

    bool vacia(){
      return(cont==0);
    }

    int menor(int n){
      int menor=n;
      if(!vacia()){
        for(int i=n; i<cont; i++){
          if(array[i]<array[menor]){
            menor=i;
          }
        }
        return menor;
      }
      return -1;
    }

    // void insertionSort(){
    //   int e2s;
    //   for(int i=1; i<cont; i++){
    //     e2s = array[i];
    //     for(int j=i; j>0; j--){
    //       if(e2s<array[j-1]){
    //         array[j] = array[j-1];
    //       }else{
    //         break;
    //       }
    //       array[j] = e2s;
    //     }
    //   }
    // }

    void insertionSort(){
      int aux, j;
      for(int i=1;i<=cont-1;i++){
        aux=array[i];
        j=i-1;
        while((aux<array[j])&&(j>=0))
        {
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=aux;
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
      lista.insertionSort();
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
