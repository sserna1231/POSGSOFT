#include "sistema.h"

int main(){
    int opc;
    Sistema Javeriana;
    do{
        cout << "\n==========================================\n";
        cout << "BIENVENIDO AL SISTEMA DE ACTAS DE POSGRADO\n";
        cout << "==========================================\n";
        cout << "1. Crear nueva acta\n";
        cout << "2. Evaluar acta\n";
        cout << "3. Mostrar estado acta\n";
        cout << "4. Modificar acta\n";
        cout << "5. Abrir/Cerrar acta\n";
        cout << "6. Guardar acta en formato\n";
        cout << "7. Listar actas\n";
        cout << "8. Listar actas por diligencia\n";
        cout << "9. Listar actas trabajo aplicado\n";
        cout << "10. Listar actas trabajo investigativo\n";
        cout << "11. Consultar # trabajos dirigidos por colaborador\n";
        cout << "12. Consultar # trabajos evaluados por colaborador\n";
        cout << "13. Consultar trabajos evaluados por colaborador\n";
        cout << "14. Mostrar Colaboradores\n";
        cout << "15. Mostrar actas pendientes & reprobadas\n";
        cout << "16. Crear Colaborador\n";
        cout << "17. Crear Estudiante\n";
        cout << "18. Mostrar estudiantes\n";
        cout << "19. Mostrar jurados internos\n";
        cout << "20. Mostrar jurados externos\n";
        cout << "21. Mostrar criterios de evaluacion\n";
        cout << "22. Eliminar acta\n";
        cout << "23. Eliminar estudiante\n";
        cout << "24. Eliminar colaborador\n";
        cout << "25. Eliminar criterio\n";
        cout << "26. Modificar colaborador\n";
        cout << "27. Modificar Estudiante\n";
        cout << "28. Modificar Criterio\n";
        cout << "29. Crear criterios\n";
        cout << "0. Salir\n\n";
        cout << "> ";
        cin >> opc;
        cout << endl;

        Acta acta;
        Colaborador colab;
        Estudiante est;
        list<Acta>::iterator pActa;
        int id, op;
        list<Estudiante>::iterator estudiante;
        list<Colaborador>::iterator colaborador;
        list<Criterio>::iterator criterio;

        switch ( opc ){
            case 1:
                acta.setId( Javeriana.getActasCreadas() + 1 );
                acta.llenarActa();
                cout << "Ingrese id del autor: ";
                cin >> id;
                cout << endl;
                estudiante = Javeriana.buscarEstudiante( id );
                if( estudiante == Javeriana.getListEstudianteEnd() ){
                    cout << "Estudiante no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                acta.setEstudiante( *estudiante );
                do{
                    cout << "Desea anadir un colaborador?\n";
                    cout << "1. Si\n";
                    cout << "0. No\n";
                    cout << "> "; 
                    cin >> op;
                    cout << endl;
                    if( op == 1 ){
                        cout << "Ingrese el id del colaborador: ";
                        cin >> id;
                        cout << endl;
                        colaborador = Javeriana.buscarColab( id );
                        if( colaborador == Javeriana.getListColabEnd() ){
                            cout << "Colaborador no registrado\n";
                            cout << "Debe crearlo primero\n";
                            break;
                        }
                        acta.setColaborador( colaborador );
                    }
                }while( op != 0 );
                cout << "\nId: " << acta.getId() << endl;
                acta.initCriterios(Javeriana.getRefList());
                Javeriana.addActa( acta );
                break;
            case 2:
                cout << "Ingrese el id del acta: ";
                cin >> id;
                cout << endl;
                pActa = Javeriana.buscarActa( id );
                if( pActa == Javeriana.getListActasEnd() ){
                    cout << "Acta no registrado\n";
                    cout << "Debe crearla primero\n";
                    break;
                }
                pActa->evaluarActa();
                break;
            case 3:
                cout << "Ingrese el id del acta: ";
                cin >> id;
                cout << endl;
                pActa = Javeriana.buscarActa( id );
                if( pActa == Javeriana.getListActasEnd() ){
                    cout << "Acta no registrado\n";
                    cout << "Debe crearla primero\n";
                    break;
                }
                pActa->mostrarEstado();
                break;
            case 4:
                Javeriana.modificarActa();
                break;
            case 5:
                cout << "Ingrese el id del acta: ";
                cin >> id;
                cout << endl;
                pActa = Javeriana.buscarActa( id );
                if( pActa == Javeriana.getListActasEnd() ){
                    cout << "Acta no registrado\n";
                    cout << "Debe crearla primero\n";
                    break;
                }
                pActa->setDiligencia();
                break;
            case 6:
                cout << "Ingrese el id del acta: ";
                cin >> id;
                cout << endl;
                pActa = Javeriana.buscarActa( id );
                if( pActa == Javeriana.getListActasEnd() ){
                    cout << "Acta no registrado\n";
                    cout << "Debe crearla primero\n";
                    break;
                }
                Javeriana.guardarActa(pActa);
                break;
            case 7:
                Javeriana.mostrarActas();
                break;
            case 8:
                if( Javeriana.getListActasSize() == 0){
                    cout << "No hay actas en el sistema\n";
                    break;
                }
                do{
                    cout << "1. Mostrar actas abiertas\n";
                    cout << "2. Mostrar actas cerradas\n";
                    cout << "0. Salir\n" << "> ";
                    cin >> op;
                    if( op == 1 || op == 2 ){
                        for( list<Acta>::iterator it = Javeriana.getListActasBegin(); it != Javeriana.getListActasEnd(); it++ ){
                            if( op == 1 && it->getDiligencia() == Diligencia::Abierto ){
                                it->mostrarActa();
                            }
                            if( op == 2 && it->getDiligencia() == Diligencia::Cerrado ){
                                it->mostrarActa();
                            }
                            cout << endl;
                        }
                    }else if( op != 0 ){
                        cout << "Opcion no valida\n";
                    }
                }while( op != 0 );
                break;
            case 9:
            case 10:
                if( Javeriana.getListActasSize() == 0 ){
                    cout << "No hay actas en el sistema\n";
                    break;
                }
                for( list<Acta>::iterator it = Javeriana.getListActasBegin(); it != Javeriana.getListActasEnd(); it++ ){
                    if( opc == 9 && it->getTipo() == Tipo::Aplicado ){
                        it->mostrarActa();
                    }
                    if( op == 10 && it->getTipo() == Tipo::Investigacion ){
                        it->mostrarActa();
                    }
                    cout << endl;
                }
                break;
            case 11:
            case 12:
                cout << "Ingrese el id del colaborador: ";
                cin >> id;
                cout << endl;
                colaborador = Javeriana.buscarColab( id );
                if( colaborador == Javeriana.getListColabEnd() ){
                    cout << "Colaborador no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                cout << "\nNombre: " << colaborador->getNombre() << endl;
                if( opc == 11 ){
                    cout << "Trabajos dirigidos: " << colaborador->getDirigidos() << endl;
                }else{
                    cout << "Trabajos evaluados: " << colaborador->getEvaluados() << endl;
                }
                break;
            case 13:
                cout << "Ingrese el id del colaborador: ";
                cin >> id;
                cout << endl;
                colaborador = Javeriana.buscarColab( id );
                if( colaborador == Javeriana.getListColabEnd() ){
                    cout << "Colaborador no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                colaborador->mostrarTrabajosEval();
                break;
            case 14:
            case 19:
            case 20:
                for( list<Colaborador>::iterator it = Javeriana.getListColabBegin(); it != Javeriana.getListColabEnd(); it++ ){
                    if( opc == 14 ){
                        it->mostrarColaborador();
                    }else if( opc == 19 ){
                        if( it->getAfil() == afil_enum::INTERNO ){
                            it->mostrarColaborador();
                        }
                    }else{
                        if( it->getAfil() == afil_enum::EXTERNO ){
                            it->mostrarColaborador();
                        }
                    }
                    cout << endl;
                }
                cout << endl;
                break;
            case 15:
                for( list<Acta>::iterator it = Javeriana.getListActasBegin(); it != Javeriana.getListActasEnd(); it++ ){
                    if( it->getAprobacion() == Aprobacion::Pendiente || it->getAprobacion() == Aprobacion::Reprobado ){
                        it->mostrarActa();
                    }
                }
                cout << endl;
                break;
            case 16:
                colab.setId( Javeriana.getColabsCreados() + 1 );
                colab.llenarColaborador();
                Javeriana.addColab( colab );
                break;
            case 17:
                est.setId( Javeriana.getEstudiantesCreados() + 1 );
                est.llenarEstudiante();
                cout << "Id: " << est.getId() << endl;
                Javeriana.addEstudiante( est );
                break;
            case 18:
                Javeriana.mostrarEstudiantes();
                break;
            case 21:
                Javeriana.mostrarCriterios();
                break;
            case 22:
                cout << "Ingrese el id del acta: ";
                cin >> id;
                cout << endl;
                pActa = Javeriana.buscarActa( id );
                if( pActa == Javeriana.getListActasEnd() ){
                    cout << "Acta no registrada\n";
                    cout << "Debe crearla primero\n";
                    break;
                }
                Javeriana.eliminarActa( id );
                cout << "Eliminada con exito\n";
                break;
            case 23:
                cout << "Ingrese id del estudiante: ";
                cin >> id;
                cout << endl;
                estudiante = Javeriana.buscarEstudiante( id );
                if( estudiante == Javeriana.getListEstudianteEnd() ){
                    cout << "Estudiante no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                Javeriana.eliminarEstudiante( id );
                cout << "Eliminado con exito\n";
                break;
            case 24:
                cout << "Ingrese el id del colaborador: ";
                cin >> id;
                cout << endl;
                colaborador = Javeriana.buscarColab( id );
                if( colaborador == Javeriana.getListColabEnd() ){
                    cout << "Colaborador no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                Javeriana.eliminarColaborador( id );
                cout << "Eliminado con exito\n";
                break;
            case 25:    //ELIMINAR CRITERIO
                cout << "Ingrese el id del criterio: ";
                cin >> id;
                cout << endl;
                criterio = Javeriana.buscarCriterio( id );
                if( criterio == Javeriana.getListCriteriosEnd() ){
                    cout << "Criterio no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                Javeriana.eliminarCriterio( id );
                cout << "Eliminado con exito\n";
                break;
            case 26:
                cout << "Ingrese el id del colaborador: ";
                cin >> id;
                cout << endl;
                colaborador = Javeriana.buscarColab( id );
                if( colaborador == Javeriana.getListColabEnd() ){
                    cout << "Colaborador no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                colaborador->modificarColaborador();
                break;
            case 27:
                cout << "Ingrese id del estudiante: ";
                cin >> id;
                cout << endl;
                estudiante = Javeriana.buscarEstudiante( id );
                if( estudiante == Javeriana.getListEstudianteEnd() ){
                    cout << "Estudiante no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                estudiante->modificarEstudiante();
                break;
            case 28:
                cout << "Ingrese el id del criterio: ";
                cin >> id;
                cout << endl;
                criterio = Javeriana.buscarCriterio( id );
                if( criterio == Javeriana.getListCriteriosEnd() ){
                    cout << "Criterio no registrado\n";
                    cout << "Debe crearlo primero\n";
                    break;
                }
                criterio->modificarCriterio();
                break;
            case 29:
                Javeriana.addCriterio( Criterio( Javeriana.getCritCreados() + 1 ) );
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
    }while( opc != 0 );
    return 0;
}