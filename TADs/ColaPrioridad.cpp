void encolar_prioridad(Cola &C,int prioridad,char codigo){
    Nodo *p;
    Elemento aux;
    aux.codigo=codigo;
    aux.prioridad=prioridad;
    p=crearNodo(aux,nullptr);
    if(esColaVacia(C)){
        C.lista.cabeza=p;
        if(prioridad==1)
            C.lista.prio1=p;
        else if(prioridad==2)
            C.lista.prio2=p;
           
        C.lista.cola=p;
    }else{
        if(prioridad==1){
            if(C.lista.prio1==nullptr){
                p->siguiente=C.lista.cabeza;
                C.lista.cabeza=p;
                C.lista.prio1=p;
            }else{
                p->siguiente=C.lista.prio1->siguiente;
                C.lista.prio1->siguiente=p;
                C.lista.prio1=p;
            }
        }else if(prioridad==2){
            if(C.lista.prio2==nullptr){
                if(C.lista.prio1!=nullptr){
                    p->siguiente=C.lista.prio1->siguiente;
                    C.lista.prio1->siguiente=p;
                }else{ 
                    p->siguiente=C.lista.cabeza;
                    C.lista.cabeza=p;
                }
                C.lista.prio2=p;
            }else{
                p->siguiente=C.lista.prio2->siguiente;
                C.lista.prio2->siguiente=p;
                C.lista.prio2=p;
            }
        }else if(prioridad==3){
            C.lista.cola->siguiente=p;
            C.lista.cola=p;
        }
    }
    C.lista.longitud++;
}