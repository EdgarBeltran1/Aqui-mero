#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


void imprimirTablero(char matriz[][3]){
    cout<<"\n\t\t\t---------"<<endl;
    for(int fila=0;fila<3;fila++){
        cout << "\t\t\t";
        for(int columna=0;columna<3;columna++){
            cout << "|" << matriz[fila][columna]<<"|";// Se imprime en pantalla como va el tablero hasta el momento
        }
        cout << "\n";
        cout << "\t\t\t---------"<<endl;
    }
}

int elegirIniciador(int gano){//Metodo para decidir si el ganador ira primero o si ira segundo (Usara X u O)
    int iniciador=0;
    cout<<"\nGanador! Quiere empezar usted (Usar X), o ir segundo (Usar O) (Ingresar 1=Para empezar o 2=Ir segundos)"<<endl;
    int empezar; cin>>empezar;
    cin.ignore();
    if(empezar==1 && gano==1){
        iniciador=1;
    }
    if(empezar==1 && gano==2){
        iniciador=2;
    }
    if(empezar==2 && gano==1){
        iniciador=2;
    }
    if(empezar==2 && gano==2){
        iniciador=1;
    }
    return iniciador;
}

void mostrarMarcadores(string jugador1, string jugador2, int&jug1, int&jug2, int&empates){//Muestra los marcadores en pantalla
    cout <<"\nMarcadores" <<endl;
    cout <<"\n" << jugador1 <<" " << jug1 <<endl;
    cout << jugador2 << " " << jug2 <<endl;
    cout << "Empates "<< empates <<endl;
}
int numeroRandom(){
    int x;
    srand(time(NULL));
    x =(rand()%2) +1 ;//Metodo para generar un numero aletorio entre 1 y 2
    return x;
}

void limpiarTablero(char ocupado[][3]){//Funcion para limpiar las casillas de la matriz ocupado
    for(int fila=0;fila<3;fila++){
        for(int columna=0;columna<3;columna++){
            ocupado[fila][columna]='-';
        }
    }
}

int generarMenu(){//Menu de inicio para el juego
    int menu=0;
    cout<<"\n\t\t--------------------------------";
    cout<<"\n\t\t| Bienvenido al juego del gato |"<<endl;
    cout<<"\t\t--------------------------------";
    cout<<"\n\n\t\tIniciar Juego (Presione 1)"<<endl;
    cout<<"\t\tSalir (Presione 2)\n"<<endl;
    cin>>menu;
    cin.ignore();
    return menu;
}

int victoria(char matriz[][3]){//Verificador de si alguien gano de manera horizontal, vertical o diagonal
    if(matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X'){
        return 1;
    }
    if(matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X'){
        return 1;
    }
    if(matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O'){
        return 1;
    }
    if(matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O'){
        return 1;
    }
    if(matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X'){
        return 1;
    }
    if(matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X'){
        return 1;
    }
    if(matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O'){
        return 1;
    }
    if(matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O'){
        return 1;
    }
    if(matriz[2][0] == 'X' && matriz[2][1] == 'X'  && matriz[2][2] == 'X'){
        return 1;
    }
    if(matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X'){
        return 1;
    }
    if(matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O'){
        return 1;
    }
    if(matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O'){
        return 1;
    }
    if(matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O'){
        return 1;
    }
    if(matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X'){
        return 1;
    }
    if(matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X'){
        return 1;
    }
    if(matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O'){
        return 1;
    }
}

int main(){
    while(generarMenu()==1){//Mientras la persona quiera seguir jugando todo el proceso del juego se llevara a cabo

        string jugador1, jugador2; //Se declaran las variables para guardar los nombres de los jugadores

        cout << "\nIngrese el nombre del primer jugador" << endl; //Se pide el nombre del primer jugador
        getline(cin, jugador1);//Se guarda en la variable

        cout << "\nIngrese el nombre del segundo jugador" << endl;//Se pide el nombre del segundo jugador
        getline(cin, jugador2);//Se guarda en la variable

        int gano=0;//Variable para saber que jugador fue el que gano y determinar si quiere empezar el de nuevo o no
        int decision = 1; //Variable para saber si se repetira el proceso varias veces
        int numAleatorio=numeroRandom();
        int cont1=0, cont2=0, cont3=0;//Se declaran los contadores que iran subiendo segun se gane o se empate
        int &jug1=cont1, &jug2=cont2, &empates=cont3;//Cree las referencias para usarlas en una de las funciones antes declaradas
        while(decision == 1){

            char ocupado[3][3];//Se inicializa la matriz ocupado en blanco para que se vaya rellenando conforme las posiciones se acaban
            char matriz[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};//Se genera un tablero

            for(int k=0;k<=8;){ //Se repite el proceso hasta obtener las 9 casillas del gato
                int i=0;//Referencia la fila
                int j=0;//Referencia la columna

                if(numAleatorio == 1){//Si el numero aleatorio que salio fue 1 empieza el jugador1
                    cout << "\n\t\t\t" << jugador1 <<" elige"<< endl;
                    do{cout << jugador1 <<" ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                        cin>>i;
                    }while(i>2 || i<0);//Ciclo repetitivo para que no ingresen un numero incorrecto
                    do{cout << "\n" << jugador1 << " ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                        cin>>j;
                    }while(j>2 || j<0);//Ciclo repetitivo para que no ingresen un numero incorrecto
                    if(ocupado[i][j] == 'D'){//Ciclo por si la casilla ya estaba ocupada anteriormente
                        do{cout << "\nIngrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                            cin>>i;
                            cout << "\nIngrese la columna (0,1 o 2)"<< endl;
                            cin>>j;
                        }while(ocupado[i][j] == 'D');
                    }
                    matriz[i][j] = 'X';//Se asigna una O Para el segundo en jugar
                    ocupado[i][j] = 'D';//Se asigna una D para rellenar y comprobar que no se intente ingresar a esa casilla mas adelante
                    k++;//Se suma al contador para saber si las 9 casillas estan completas el juego termine en empate
                    imprimirTablero(matriz);
                    if(victoria(matriz)==1){//Si la funcion de victoria regresa un 1 entonces acaba de ganar el jugador que acaba de jugar
                        cout<<"\n\t\t\tGana "<<jugador1<<"!";
                        cont1++;//Se suma uno en el contador del jugador que acaba de ganar
                        gano=1;
                        break;
                    }
                }

                if(numAleatorio!=1){//Si fue diferente de 1 empieza el jugador2
                    cout << "\n\t\t\t"<< jugador2 <<" elige"<< endl;
                    do{cout << jugador2 <<" ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                        cin>>i;
                    }while(i>2 || i<0);
                    do{cout << "\n" << jugador2 << " ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                        cin>>j;
                    }while(j>2 || j<0);
                    if(ocupado[i][j] == 'D'){//Ciclo por si la casilla ya estaba ocupada anteriormente
                        do{cout << "\nIngrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                            cin>>i;
                            cout << "\nIngrese la columna (0,1 o 2)"<< endl;
                            cin>>j;
                        }while(ocupado[i][j]=='D');
                    }
                    matriz[i][j] = 'X';//Se asigna una O Para el segundo en jugar
                    ocupado[i][j] = 'D';//Se asigna una D para rellenar y comprobar que no se intente ingresar a esa casilla mas adelante
                    k++;
                    imprimirTablero(matriz);
                    if(victoria(matriz)==1){//Si la funcion de victoria regresa un 1 entonces acaba de ganar el jugador que acaba de jugar
                        cout<<"\n\t\t\tGana "<<jugador2<<"!";
                        cont2++;//Se suma uno en el contador del jugador que acaba de ganar
                        gano=2;
                        break;
                    }
                }

                if(k==9){
                    cont3++;
                    cout<<"\n\t\t\tEmpate";
                    break;//Verificador de que solo se jueguen las 9 casillas del tablero
                }

                if(numAleatorio == 1){//Despues de ya haber jugado un jugador se da oportunidad de que juegue el siguente
                    cout << "\n\t\t\t" << jugador2 <<" elige"<< endl;
                    do{cout << jugador2 <<" ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                        cin>>i;
                    }while(i>2 || i<0);
                    do{cout << "\n" << jugador2 << " ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                        cin>>j;
                    }while(j>2 || j<0);
                    if(ocupado[i][j] == 'D'){//Ciclo por si la casilla ya estaba ocupada anteriormente
                        do{cout << "\nIngrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                            cin>>i;
                            cout << "\nIngrese la columna (0,1 o 2)"<< endl;
                            cin>>j;
                        }while(ocupado[i][j]=='D');
                    }
                    matriz[i][j] = 'O';//Se asigna una O Para el segundo en jugar
                    ocupado[i][j] = 'D';//Se asigna una D para rellenar y comprobar que no se intente ingresar a esa casilla mas adelante
                    k++;
                    imprimirTablero(matriz);
                    if(victoria(matriz)==1){//Si la funcion de victoria regresa un 1 entonces acaba de ganar el jugador que acaba de jugar
                        cout<<"\n\t\t\tGana "<<jugador2<<"!";
                        cont2++;//Se suma uno en el contador del jugador que acaba de ganar
                        gano=2;
                        break;
                    }
                }

                if(numAleatorio!=1){
                    cout << "\n\t\t\t" << jugador1 <<" elige"<< endl;
                    do{cout << jugador1 <<" ingrese la fila donde quiere jugar (0,1 o 2)" <<endl;
                        cin>>i;
                    }while(i>2 || i<0);
                    do{cout << "\n" << jugador1 << " ingrese la columna donde quiere jugar (0, 1 o 2)" <<endl;
                        cin>>j;
                    }while(j>2 || j<0);
                    if(ocupado[i][j] == 'D'){//Ciclo por si la casilla ya estaba ocupada anteriormente
                        do{cout << "\nIngrese otra fila, esa casilla esta ocupada (0,1 o 2)" <<endl;
                            cin>>i;
                            cout << "\nIngrese la columna (0,1 o 2)"<< endl;
                            cin>>j;
                        }while(ocupado[i][j]=='D');
                    }
                    matriz[i][j] = 'O';//Se asigna una O Para el segundo en jugar
                    ocupado[i][j] = 'D';//Se asigna una D para rellenar y comprobar que no se intente ingresar a esa casilla mas adelante
                    k++;
                    imprimirTablero(matriz);
                    if(victoria(matriz)==1){//Si la funcion de victoria regresa un 1 entonces acaba de ganar el jugador que acaba de jugar
                        cout<<"\n\t\t\tGana "<<jugador1<<"!";
                        cont1++;//Se suma uno en el contador del jugador que acaba de ganar
                        gano=1;
                        break;
                    }
                }
            }

            mostrarMarcadores(jugador1, jugador2, jug1, jug2, empates);//Se muestran como van los marcadores hasta el momento
            limpiarTablero(ocupado);//Se limpian las casillas ocupadas para una nueva partida
            cout << "\nQuiere volver a jugar? (Si=1, No=Ingrese cualquier otro numero)" << endl;
            cin>>decision;//Se pregunta al usuario si quiere repetir el proceso y se guarda en la variable decision
            if(decision==1 && gano !=0){//Verifica si alguien gano y le da la opcion al ganador de elegir quien ira primero
                numAleatorio=elegirIniciador(gano);
            }
            gano=0;//Reseteo el numero por si en la siguiente partida hay empate no se llame al metodo elegirIniciador
        }
        cout<<"\t\tGracias por jugar!"<<endl;
    }
    cout<<"\t\tGracias por jugar!"<<endl;
}
