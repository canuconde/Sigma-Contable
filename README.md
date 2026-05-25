# Libro--# Libro Contable - Aplicación de Escritorio en C++

Aplicación de escritorio desarrollada en C++ para la gestión de un libro contable simple y eficiente. El proyecto utiliza SQLite3 como motor de base de datos y está orientado a ofrecer una solución liviana, rápida y fácil de mantener para pequeños negocios, emprendimientos o uso personal.

## Características

* Gestión de ingresos y egresos.
* CRUD completo de registros contables.
* Almacenamiento local mediante SQLite3.
* Interfaz gráfica desarrollada con wxWidgets.
* Persistencia de datos rápida y liviana.
* Arquitectura organizada utilizando clases y DAO.
* Proyecto portable y de bajo consumo de recursos.

## Tecnologías utilizadas

* C++
* SQLite3
* wxWidgets
* Git / GitHub

## Objetivos del proyecto

Este proyecto fue creado con el objetivo de:

* Practicar desarrollo de aplicaciones de escritorio modernas en C++.
* Implementar persistencia de datos utilizando SQLite.
* Diseñar una interfaz simple y funcional.
* Explorar buenas prácticas de organización de código.

## Estado del proyecto

En desarrollo activo.

## Capturas de pantalla

*(Agregar imágenes de la aplicación aquí)*

## Compilación

### Requisitos

* Compilador compatible con C++17.
* SQLite3.
* wxWidgets.

### Linux

```bash
g++ main.cpp -o app `wx-config --cxxflags --libs` -lsqlite3
```

## Posibles mejoras futuras

* Exportación a PDF y Excel.
* Reportes automáticos.
* Soporte multiusuario.
* Sistema de copias de seguridad.
* Gráficos y estadísticas.
* Protección básica de licencia.

## Licencia

Proyecto desarrollado con fines educativos y personales.

