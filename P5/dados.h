/**
 * @Archivo dados.h
 * @Contiene Clase Dados
 */
#ifndef __Dados__
#define __Dados__

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

/**
 * La clase Dados recoge todos los metodos necesarios para tirar dados
 * 
 */

class Dados{
    private:
        int d1_,d2_; /**< Valor de cada dado*/
        int l1_,l2_; /**< Nº de veces lanzado cada dado*/
        int t1_,t2_; /**< Valor total de la suma de todos los lanzamientos de los dados*/
        std::vector<int> v1_ , v2_; /**< Vectores destinados a recoger los ultimos valores
                                    * que tomó cualquiera de los dos dados
                                    */
    public: 
        /**
         * @function Dados()
         * Constructor de las clase Dados, no requiere de ningun parametro,
         * Inicializa todas las variables privadas y la semilla para generar
         * lanzamientos aleatorios.
         */
        Dados();
        
        friend std::ostream &operator<<(std::ostream &stream, Dados &d);
                
        friend std::istream &operator>>(std::istream &stream, Dados &d);

        /**
         * @function lanzamiento()
         * La funcion lanzamiento genera dos valores aleatorios para los dados
         * los cuales pasa mediante parametro de las funciones setDado
         * @see setDado1() & setDado2()
         */
        void lanzamiento();

        /**
         * Los siguientes dos pares funciones están dedicadas a definir y de 
         * devolver el valor de la variable privada d1_ y d2_ respectivamente.
         * 
         * @function setDado1() & setDado2() 
         * @param <int> n
         * Recibe un <int> n y comprueba si es valido (si esta entre 1 y 6)
         * y lo asigna a la variable d1_ o d2_ respectivamente. Incrementa 
         * el numero de lanzamientos realizados y actualiza tanto la suma
         * de los valores obtenidos con el dado como el vector de ultimos
         * lanzamientos.
         * 
         * @function getDado1() & getDado2() 
         * Nos retorna el valor constante de d1_ y d2_ respectivamente.
         * @return <int> d1_ || <int> d2_
         */
        bool setDado1(int n);
        bool setDado2(int n);
        inline int const getDado1(){return d1_;}
        inline int const getDado2(){return d2_;}
        
        /**
         * @function getSuma()
         * Retorna el valor constante de la suma de los valores actuales de
         * ambos dados.
         * @return <int> d1_+d2_ 
         */
        inline int getSuma()const {return d1_+d2_;}

        /**
         * @function getDiferencia()
         * Retorna el valor constante de la resta de los valores actuales de
         * ambos dados. Comprueba cual es el mayor para retornar el valor de
         * la diferencia como numero positivo.
         * @return <int> d1_-d2_|| <int> d2_-d1_ 
         */
        inline int getDiferencia()const {return (d1_>d2_? d1_-d2_ : d2_-d1_);}

        /**
         * @function getLanzamientos1() && getLanzamientos2()
         * Retorna el valor constante del numero de lanzamientos realizado 
         * en cada dado.
         * @return <int> l1_ || <int> l2_ 
         */
        inline int getLanzamientos1()const {return l1_;}
        inline int getLanzamientos2()const {return l2_;}

        /**
         * @function getMedia1() && getMedia2()
         * Retorna el valor medio de los lanzamientos de cada dado.
         * @return <float> 0 || <float>t1_/<float>l1_ || <float>t1_/<float>l1_ 
         */
        inline float getMedia1()const {return l1_==0 ? 0 : ( (float)t1_/(float)l1_ );}
        inline float getMedia2()const {return l2_==0 ? 0 : ( (float)t2_/(float)l2_ );}

        /**
         * @function getUltimos1() && getUltimos2()
         * @param <int *>v vector el cual recibira el vector de ultimos lanzamientos.
         * Copia el vector almacenado en v1_ y v2_ a un vector pasado por
         * parametro. 
         */
        void getUltimos1(int *v);
        void getUltimos2(int *v);
};


int selectMenu();
int MenuGetDado();
int MenuSetDado();
#endif