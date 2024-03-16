#include <iostream>
#include<malloc.h>

using namespace std;

struct temperatura{
    
    char fecha[30];
    float manana;
    float tarde;
    float noche;
    temperatura *siguiente;
};

 temperatura *cabeza = NULL, *aux1 = NULL, *aux2 = NULL;
 
void  registrar(){
    
    //aux1= new temperatura;
    aux1 = (struct temperatura *) malloc(sizeof(struct temperatura));
    
    cout<<"ingrese la fecha "<<endl;
    cin>>aux1->fecha;
    
    cout<<"ingrese la temp de la manana: "<<endl;
    cin>>aux1->manana;
    
    cout<<"ingrese la temp de la tarde: "<<endl;
    cin>>aux1->tarde;
    
    cout<<"ingrese la temp de la noche: "<<endl;
    cin>>aux1->noche;
    
    aux1->siguiente = NULL;
    
if(cabeza==NULL){
    cabeza = aux1;
  }else {
    aux2= cabeza;
    
    while(aux2->siguiente!= NULL ){
     aux2 = aux2->siguiente;
 }
   
   aux1->siguiente = NULL;
   aux2->siguiente = aux1;
   
    }
}

 void mostrar(){
     aux1= cabeza;
     
     while(aux1!= NULL){
     cout<<"fecha: "<<aux1->fecha<<endl;
     cout<<"manana: "<<aux1->manana<<endl;
     cout<<"tarde: "<<aux1->tarde<<endl;
     cout<<"noche: "<<aux1->noche<<endl;
     
      aux1 = aux1->siguiente;
      
     }
}

void temp_prom(){
    float suma_temp = 0.0;
    int contador =0;
    
    for(aux1 = cabeza; aux1 !=NULL; aux1= aux1->siguiente){
        suma_temp += aux1->manana + aux1->tarde +aux1->noche;
        contador +=3;
        
    }
    
    float prom_total = suma_temp/contador;
    cout<<"el promedio de la temperatura del dia es: "<<prom_total<<endl;
    
    }
    
void prom_dias(){
int contador_regis = 0;
float suma_tempe = 0.0;
   
   for(aux1 = cabeza; aux1!=NULL; aux1= aux1->siguiente){
       
       suma_tempe += aux1->manana + aux1->tarde + aux1->noche;
       contador_regis++;
   }
   
   float promedio = suma_tempe / (contador_regis * 3);
    
    cout<<"el promedio de los dias registrados es: "<<promedio<<endl;

} 


int main(){
    int op = 0;
    
  do{
        
    cout<<"MENU VRO ;) "<<endl;
    cout<<"1.Registre los datos: "<<endl;
    cout<<"2.Los datos ingresados son: "<<endl;
    cout<<"3.El promedio de temperatura del dia es:"<<endl;
    cout<<"4.El promedio de temperatura de todos los registros: "<<endl;
    cout<<"ingresa tu option, please: "<<endl;
    cin>>op;
    
       switch(op){
           
            case 1: 
                registrar();
            break;
           
            case 2:
                mostrar();
            break;
            
            case 3:
                temp_prom();
            break;
            
            case 4:
                prom_dias();
            break;
       
       }
       
    }while( op!=5);
    
    return 0;
}
