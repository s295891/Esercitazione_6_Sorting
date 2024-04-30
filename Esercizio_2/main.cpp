#include <chrono>
#include <iostream>
#include <unistd.h>
#include <numeric>
#include <cstdlib> // Per la funzione atoi
#include <vector>
#include <algorithm>
#include "SortingAlgorithm.hpp"

using namespace std;

// Funzione per creare un vettore già ordinato
vector<int> createVector_ordinato(int dimv) {
    vector<int> v(dimv);
    int n = 0;
    generate(v.begin(), v.end(), [&n] () { return n++; });

    return v;
}


vector<int> createVector_ordinato_decrescente(int dimv) {
    vector<int> v(dimv);
    int n = dimv;
    generate(v.begin(), v.end(), [&n] () { return --n; });

    return v;
}


// Funzione che crea un vettore e gli fa una perturbazione su alcuni suoi numeri (in base alla dimensione si fanno le perturbazioni)

vector<int> createVector_perturbazioni(int dimv) {
    vector<int> v(dimv);
    int n = 0;
    generate(v.begin(), v.end(), [&n] () { return n++; });

    for(unsigned int i =0; i <800; i++)     // la perturbazione viene fatta sui primi i numeri (in base a come scegliamo i<?)
        v[i] = rand() %100; // fa una perturbazione


    return v;
}

// Funzione per creare un vettore randomico di dimensione specificata
vector<int> createRandomVector(int dimv) {

    vector<int> v(dimv);
    for (int i = 0; i < dimv; ++i) {
        // Genera un numero casuale compreso tra 1 e 100
        v[i] = rand() % 100 + 1;
    }
    return v;
}


double TimeMergeSort(vector<int>& v) {
    // Tempo di inizio
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    sleep(1);  // da usare quando i tempi sono piccoli per l'ordinamento
    //ordinamento con Merge Sort
    SortLibrary::MergeSort(v);

    // Tempo di fine
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

    // Calcolo del tempo trascorso
    return chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
}

double TimeBubbleSort(vector<int>& v) {
    // Tempo di inizio
    chrono::steady_clock::time_point t_begin = chrono::steady_clock::now();
    sleep(1);  // da usare quando i tempi sono piccoli per l'ordinamento
    //ordinamento con Merge Sort
    SortLibrary::MergeSort(v);

    // Tempo di fine
    chrono::steady_clock::time_point t_end = chrono::steady_clock::now();

    // Calcolo del tempo trascorso
    return chrono::duration_cast<chrono::microseconds>(t_end - t_begin).count();
}







int main(int argc, char ** argv)
{

    int dimv = atoi(argv[1]); // Converti la command line argument in un intero



            // consideriamo un vettore di dimensione 10 già ordinato e senza perturbazioni
    //vector<int> v = createVector_ordinato(dimv);
            // i risultati che otteniamo sono:   1.0075e+06 MergeSort
            //                                  1.00675e+06 BubbleSort




            // consideriamo un vettore di dimensioni 10 ordinato ma a cui vengono fatte 2 perturbazioni sui dati iniziali
    //vector<int> v = createVector_perturbazioni(dimv);
            // i risultati sono :   1.00444e+06 MergeSort
            //                      1.00713e+06 BubbleSort






            // consideriamo un vettore di dimensioni 10 ordinato ma a cui vengono fatte 8 perturbazioni sui dati iniziali
    //vector<int> v = createVector_perturbazioni(dimv);
            // i risultati sono :   1.01132e+06  MergeSort
            //                      1.00445e+06  BubbleSort



            // consideriamo un vettore completamente randomico di dimensioni 10
    //vector<int> v = createRandomVector(dimv);
            // i risultati sono:    1.00199e+06 MergeSort
            //                      1.00709e+06 BubbleSort





        //oss: in generale dovrebbe essere MergeSort il più veloce per vettori perturbati, tuttavai con vettori come questi
        // di piccole dimensioni i risultati differiscono di poco e alcune volte e si possono invertire le efficienze





// ORA ANDIAMO A FARE GLI STESSI PASSAGGI PER VETTORI DI GRANDI DIMENSIONI N = 100


            // consideriamo un vettore di dimensione 100 già ordinato e senza perturbazioni
    //vector<int> v = createVector_ordinato(dimv);
            // i risultati sono:   1.00255e+06 MergeSort
            //                     1.00064e+06 BubbleSort

        //oss: per vettori ordinati mi aspettavo (e così è) che il bubblesort fosse più veloce



            // consideriamo un vettore di dimensioni 100 ordinato ma a cui vengono fatte 20 perturbazioni sui dati iniziali
    //vector<int> v = createVector_perturbazioni(dimv);
            // i risultati sono :   1.00646e+06 MergeSort
            //                      1.0141e+06 BubbleSort



            // consideriamo un vettore di dimensioni 100 ordinato ma a cui vengono fatte 80 perturbazioni sui dati iniziali
    //vector<int> v = createVector_perturbazioni(dimv);
            // i risultati sono :   1.00648e+06    MergeSort
            //                      1.00638e+06    BubbleSort


            // consideriamo un vettore completamente randomico di dimensioni 10
    //vector<int> v = createRandomVector(dimv);
            // i risultati sono:    1.007e+06 MergeSort
            //                      1.01156e+06 BubbleSort



        //oss qui già i risultati iniziamo a farci preferire MergeSort per alcuni casi (quelli randomici o preturbati)





// ORA ANDIAMO A FARE GLI STESSI PASSAGGI PER VETTORI DI GRANDI DIMENSIONI N = 1000



            // consideriamo un vettore di dimensione 1000 già ordinato e senza perturbazioni
    //vector<int> v = createVector_ordinato(dimv);
            // i risultati sono:   1.01505e+06   MergeSort
            //                     1.01257e+06   BubbleSort



            // consideriamo un vettore di dimensioni 1000 ordinato ma a cui vengono fatte 200 perturbazioni sui dati iniziali
    //vector<int> v = createVector_perturbazioni(dimv);
            // i risultati sono :   1.01622e+06 MergeSort
            //                      1.00854e+06 BubbleSort


            // consideriamo un vettore di dimensioni 1000 ordinato ma a cui vengono fatte 800 perturbazioni sui dati iniziali
    //vector<int> v = createVector_perturbazioni(dimv);
            // i risultati sono :   1.00945e+06 MergeSort
            //                      1.00384e+06 BubbleSort


            // consideriamo un vettore completamente randomico di dimensioni 10
    //vector<int> v = createRandomVector(dimv);
            // i risultati sono:  1.00267e+06   MergeSort
            //                    1.00837e+06   BubbleSort



            // consideriamo un vettore ordinato di 1000 elementi, ordinato in modo decrescente
    //vector<int> v = createVector_ordinato_decrescente(dimv);
            // i risultati sono :    1.01401e+06 BubbleSort
            //                       1.00237e+06 MergeSort


    cout << "Before sorting: ";
    for(unsigned int i = 0; i < dimv; i++)
        cout << v[i] << " ";
    cout<<endl;

    double timeElapsed = TimeMergeSort(v);
    //double timeElapsed = TimeBubbleSort(v);


    cout << "After sorting: ";
    for (int i = 0; i < dimv; i++)
        cout << v[i] << " ";
    cout << endl;


    cout <<"time elapsed " << timeElapsed << endl;


    return 0;
}

