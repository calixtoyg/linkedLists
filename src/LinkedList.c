#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inc/Employee.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);
static Node* _createNode(Node *next, void *pElement);

static Node *ll_popFirstOfList(LinkedList *list);

static int ll_pushToFirst(LinkedList *pList, void *pVoid);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
*
*  \param void
*  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
*                      o el puntero al espacio reservado
*/
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    if (ll_isEmpty(this)) {
        printf("Lista vacia");
        return -1;
    } else
        return this->size;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    if (ll_isEmpty(this) || nodeIndex < 0 || nodeIndex >= this->size) {
        return NULL;
    }
    int i = 0;
    Node *currentNode = this->pFirstNode;
    if (nodeIndex == 0) {
        return this->pFirstNode;
    }
    for (i = 0; i < nodeIndex; i++) {
        if (currentNode == NULL) {
            printf("Index out of bound.\n");
            return NULL;
        }
        currentNode = currentNode->pNextNode;
    }
    return currentNode;
}

static Node *ll_popFirstOfList(LinkedList *this) {
    if (ll_isEmpty(this)) {
        return NULL;
    }
    void *returnData = NULL;
    Node *nextNode = NULL;
    nextNode = this->pFirstNode->pNextNode;
    returnData = this->pFirstNode->pElement;
    free(this->pFirstNode);
    this->pFirstNode = nextNode;
    this->size -= 1;
    return returnData;


}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* list, void* pElement)
{
    if (ll_isEmpty(list)) {
        return -1;
    }
    int i = 0;
    Node *currentNode = list->pFirstNode;
    if(list->pFirstNode == NULL){
        list->pFirstNode = malloc(sizeof(Node));
        list->pFirstNode->pElement = pElement;
        list->pFirstNode->pNextNode=NULL;
        list->size++;
        return 0;
    }
    Node *temporaryNode = malloc(sizeof(Node));
    for (i = 0; currentNode->pNextNode != NULL; i++) {

        currentNode = getNode(list,i)->pNextNode;
    }
    currentNode->pNextNode = temporaryNode;
    temporaryNode->pElement = pElement;
    temporaryNode->pNextNode = NULL;
    list->size++;
    return 0;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    int i = 0;
    if (ll_isEmpty(this) || index < 0 || index >= this->size) {
        return NULL;
    }
    Node *currentNode = this->pFirstNode;
    for (i = 0; i < index; i++) {
        currentNode = getNode(this,i)->pNextNode;
    }
    return currentNode->pElement;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    if (ll_isEmpty(this) || index < 0 || index >= this->size) {
        return -1;
    }
    Node *currentNode = this->pFirstNode;
    int i;
    if (index == 0) {
        currentNode->pElement = pElement;
        return 0;

    }
    for (i = 0; i < index - 1; i++) {
        currentNode = getNode(this,i)->pNextNode;
    }
    if (currentNode->pNextNode != NULL) {
        currentNode->pNextNode->pElement = pElement;
    }
    return 0;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int i = 0;
    Node *temporaryNode = NULL;
    if (ll_isEmpty(this) || index < 0 || index >= this->size) {
        return  -1;
    }
    Node *currentNode = this->pFirstNode;
    if (index == 0) {
        ll_popFirstOfList(this);
    }else{
    for (i = 0; i < index - 1; i++) {
        currentNode = getNode(this,i)->pNextNode;
    }
    temporaryNode = currentNode->pNextNode;
    currentNode->pNextNode = temporaryNode->pNextNode;
    free(temporaryNode);
    this->size -= 1;
    }
    return 0;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
//    void destroy(set_elem *head)
//    {
//        set_elem *current = head;
//        set_elem *next;
//
//        while (current != NULL)
//        {
//            next = current->next;
//            free(current);
//            current = next;
//        }
//        head = NULL;
//    }
    int returnAux = 0;
    Node *currentNode;
    Node *nextNode;
    if(ll_isEmpty(this)) {
        returnAux = -1;

    }
    else{
        currentNode = this->pFirstNode;

        while (currentNode != NULL)
        {
            nextNode = currentNode->pNextNode;
            free(currentNode);
            currentNode = nextNode;
        }
        this->pFirstNode = NULL;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    if(ll_isEmpty(this))
        return -1;
    else
        free(this);
    return 0;

}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{

//    if (ll_isEmpty(this)) {
//        return -1;
//    }
//    Node *currentNode = this->pFirstNode;
//    int index;
//    for (index = 0; currentNode != NULL; ++index) {
//        if (employee_equals(pElement, currentNode)) {
//            return index;
//
//        }
//        currentNode = currentNode->pNextNode;
//
//    }
//    printf("There is no element.\n");
//    return -1;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    if(this == NULL)
        return 1;
    else
        return 0;
}

static Node* _createNode(Node *next, void *pElement){
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("ERROR creating node. \n");
            return (Node *) -1;
        }
        newNode->pElement = pElement;
        newNode->pNextNode = next;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    if (ll_isEmpty(this) || index < 0 || index > this->size) {
        return -1;
    }
    Node *currentNode = this->pFirstNode;
    int i = 0;
    if (index == 0) {
        return ll_pushToFirst(this, pElement);
    }
    for (i = 0; i < index - 1; i++) {
        currentNode = getNode(this,i)->pNextNode;
    }
    Node *newNode = _createNode(currentNode->pNextNode, pElement);
    currentNode->pNextNode = newNode;
    this->size += 1;

    return 0;
}

static int ll_pushToFirst(LinkedList *this, void *pElement) {
    if (ll_isEmpty(this)) {
        return -1;
    }
    Node *newNode;
    newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->pElement = pElement;
    newNode->pNextNode = this->pFirstNode;
    this->pFirstNode = newNode;
    this->size += 1;
    return 0;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    if (ll_isEmpty(this) || index < 0 || index >= ll_len(this)) {
        return NULL;
    }
    Node *currentNode = this->pFirstNode;
    void *returnData = NULL;
    int i = 0;
    Node *temporaryNode = NULL;
    if (index == 0) {
        return ll_popFirstOfList(this);
    }
    for (i = 0; i < index - 1; i++) {
        currentNode = getNode(this,i)->pNextNode;
    }
    temporaryNode = currentNode->pNextNode;
    returnData = temporaryNode->pElement;
    currentNode->pNextNode = temporaryNode->pNextNode;
    free(temporaryNode);
    this->size -= 1;
    return returnData;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
   LinkedList *cloneLinkedList = ll_clone(this);
    if (cloneLinkedList == NULL || from>to || to>this->size || ll_isEmpty(cloneLinkedList) || from < 0){
        return NULL;
    }
    Node *current = cloneLinkedList->pFirstNode;
    cloneLinkedList->pFirstNode = getNode(this,from);

    for (int i = from+1; i < to ; ++i) {
        current->pNextNode = getNode(this,i);
        current->pNextNode->pElement = getNode(this,i)->pElement;
        current = current->pNextNode;
    }

    current->pNextNode = NULL;
    return cloneLinkedList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    if (ll_isEmpty(this)) {
        return NULL;
    }
    Node *current = this->pFirstNode;
    LinkedList* newLinkedList = ll_newLinkedList();
    Node *newNode = newLinkedList->pFirstNode;
    Node* tail = NULL;
    while (current != NULL)
        {
            // special case for the first new Node
            if (newNode == NULL)
            {
                newNode = (Node *)malloc(sizeof(Node));
                newNode->pElement = current->pElement;
                newNode->pNextNode = NULL;
                tail = newNode;
                newLinkedList->size++;
            }
            else
            {
                tail->pNextNode = (Node*)malloc(sizeof(struct Node));
                tail = tail->pNextNode;
                tail->pElement = current->pElement;
                newLinkedList->size++;
                tail->pNextNode = NULL;
            }
            current = current->pNextNode;
        }
        newLinkedList->pFirstNode = newNode;

        return newLinkedList;



}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

int ll_print(LinkedList *list) {
    if (ll_isEmpty(list)) {
        return -1;
    }
    Node *temporary = list->pFirstNode;
    while (temporary != NULL) {
        printEmployee(temporary->pElement);
        temporary = temporary->pNextNode;
    }
    return 0;

}

