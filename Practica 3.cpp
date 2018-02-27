#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int generarAleatorio(int numAleatorio){
    srand(time(NULL));
    numAleatorio =(rand()%2) +1 ;//Metodo para generar un numero aletorio entre 1 y 2
    return numAleatorio;
}

void imprimirTablero(char matriz[][3]){
    for(int fila=0;fila<3;fila++){
        cout << "\t";
        for(int columna=0;columna<3;columna++){
            cout << matriz[fila][columna];// Se imprime en pantalla como va el tablero hasta el momento
        }
        cout << "\n";

    }
}

int ganador(char matriz[][3], int gano){
    if((matriz[0][0] == 'X') && (matriz[0][1] == 'X') && (matriz[0][2] == 'X')){
        gano=1;
    }else{
        gano=
    }
    if((matriz[0][0] == 'O') && (matriz[0][1] == 'O') && (matriz[0][2] == 'O')){
        gano=1;
    }
    if((matriz[1][0] == 'X') && (matriz[1][1] == 'X') && (matriz[1][2] == 'X')){
        gano=1;
    }
    if((matriz[1][0] == 'O') && (matriz[1][1] == 'O') && (matriz[1][2] == 'O')){
        gano=1;
    }
    if((matriz[2][0] == 'X') && (matriz[2][1] == 'X')  && (matriz[2][2] == 'X')){
        gano=1;
    }
    if((matriz[2][0] == 'O') && (matriz[2][1] == 'O') && (matriz[2][2] == 'O')){
        gano=1;
    }
    return gano;
}

int main(){
    string jugador1; //Se declaran las variables para guardar los nombres de los jugadores
    string jugador2;

    cout << "Ingrese el nombre del primer jugador" << endl; //Se pide el nombre del primer jugador
    getline(cin, jugador1);//Se guarda en la variable

    cout << "Ingrese el nombre del segundo jugador" << endl;//Se pide el nombre del segundo jugador
    getline(cin, jugador2);//Se guarda en la variable

    int decision = 1; //Variable para saber si se repetira el proceso varias veces
    int gano = 0;
    int cont1 = 0;//Se declaran los contadores que iran subiendo segun los numeros aleatorios vayan saliendo
    int cont2 = 0;
    while(decision == 1 && gano==0){

        char ocupado[3][3];//Se inicializa la matriz ocupado en blanco para que se vaya rellenando conforme las posiciones se acaban
        char matriz[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};//Se genera un tablero

        int numAleatorio;
        generarAleatorio(numAleatorio);

        if(numAleatorio==1){
            cont1++; //Se suma uno al contador del jugador aleatorio que se eligio
        }else{
            cont2++;
        }

        for(int k=0;k<=8;){ //Se repite el proceso hasta obtener las 9 casillas del gato
            int i=0;//Referencia la fila
            int j=0;//Referencia la columna

            if(numAleatorio == 1){//Si el numero aleatorio que salio fue 1 empieza el jugador1
                cout << jugador1 <<" elige"<< endl;
                do{cout << jugador1 <<" Ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                    cin>>i;
                }while(i>2 || i<0);
                do{cout << jugador1 << " Ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                    cin>>j;
                }while(j>2 || j<0);
                if(ocupado[i][j] == 'D'){
                    do{cout << "Ingrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                        cin>>i;
                        cout << "Ingrese la columna (0,1 o 2)"<< endl;
                        cin>>j;
                    }while(ocupado[i][j] == 'D'); //Se comprueba mediante este while si la casilla ya esta ocupada
                }
            }else{//Si fue diferente de 1 empieza el jugador2
                cout << jugador2 <<" elige"<< endl;
                do{cout << jugador2 <<" Ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                    cin>>i;
                }while(i>2 || i<0);
                do{cout << jugador2 << " Ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                    cin>>j;
                }while(j>2 || j<0);
                if(ocupado[i][j] == 'D'){
                    do{cout << "Ingrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                        cin>>i;
                        cout << "Ingrese la columna (0,1 o 2)"<< endl;
                        cin>>j;
                    }while(ocupado[i][j]=='D');
                }
            }

            matriz[i][j] = 'X'; //Se rellena la posicion con un X
            ocupado[i][j] = 'D';//Se agrega un D solo para rellenar esa casilla y compararla cuando se intente agrgar un movimiento
            k++;

            ganador(matriz, gano);
            cout<<gano<<endl;
            imprimirTablero(matriz);

            if(k==9){
                break;//Verificador de que solo se jueguen las 9 casillas del tablero
            }

            if(numAleatorio == 1){//Despues de ya haber jugado un jugador se da oportunidad de que juegue el siguente
                cout << jugador2 <<" elige"<< endl;
                do{cout << jugador2 <<" Ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                    cin>>i;
                }while(i>2 || i<0);
                do{cout << jugador2 << " Ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                    cin>>j;
                }while(j>2 || j<0);

                if(ocupado[i][j] == 'D'){//Si la casilla esta ocupada se pide al usuario que ingrese otra posicion
                    do{cout << "Ingrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                        cin>>i;
                        cout << "Ingrese la columna (0,1 o 2)"<< endl;
                        cin>>j;
                    }while(ocupado[i][j]=='D');//El proceso se repite hasta que ingrese una casilla valida
                }

            }else{
                cout << jugador1 <<" elige"<< endl;
                do{cout << jugador1 <<" Ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                    cin>>i;
                }while(i>2 || i<0);
                do{cout << jugador1 << " Ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                    cin>>j;
                }while(j>2 || j<0);
                if(ocupado[i][j] == 'D'){
                    do{cout << "Ingrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                        cin>>i;
                        cout << "Ingrese la columna (0,1 o 2)"<< endl;
                        cin>>j;
                    }while(ocupado[i][j]=='D');
                }
            }

            matriz[i][j] = 'O';//Se asigna una O Para el segundo en jugar
            ocupado[i][j] = 'D';//Se asigna una D para rellenar y comprobar que no se intente ingresar a esa casilla mas adelante
            k++;

            ganador(matriz, gano);
            cout<<gano<<endl;
            imprimirTablero(matriz);

        }

        cout << "Quiere volver a jugar? (Si=1, No=Presione cualquier tecla)" << endl;
        cin>>decision;//Se pregunta al usuario si quiere repetir el proceso y se guarda en la variable decision

        if(decision != 1){//Si decision es diferente de 1 el proceso del while se detiene y se muestran en pantalla los puntajes
            cout <<"Se termino el juego, gracias por jugar" <<endl;
            cout << "Puntaje de "<< jugador1 <<" es " << cont1 <<endl;
            cout << "Puntaje de "<< jugador2 <<" es " << cont2 <<endl;
        }
    }
}
