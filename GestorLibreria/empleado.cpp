# include<iostream>
#include "empleado.h"

void Empleado::setID(int id){
    _idEmpleado = id;
}

int Empleado::getID(){
    return _idEmpleado;
}

void Empleado::setFechaIncorporacion(Fecha fechaIncorporacion){
    _fechaIncorporacion = fechaIncorporacion;
}

Fecha Empleado::getFechaIncorporacion(){
    return _fechaIncorporacion;
}

void Empleado::setSueldo(float sueldo){
    _sueldo = sueldo;
}

float Empleado::getSueldo(){
    return _sueldo;
}

void Empleado::cargar(){

}

void Empleado::mostrar(){

}
