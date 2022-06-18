#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this =(LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
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
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* pNodo = NULL;
	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		pNodo = this->pFirstNode;//apunta a la locomotora
       for(i=0;i<nodeIndex;i++)// va a ir hasta uno antes del que busco
       {
         pNodo = pNodo->pNextNode;
       }
	}
    return pNodo;
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
    int returnAux = -1;
    Node* pNode = NULL;
    Node* auxNode = NULL;
    int len = ll_len(this);

    if(this != NULL && nodeIndex > -1 && nodeIndex <= len)
    {
    	pNode = (Node*) malloc(sizeof(Node));//newNodo pido espacio

    	if(pNode != NULL)
    	{
			if(nodeIndex == 0)// colocar al principio
			{

				pNode->pElement = pElement;
				pNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
				this->size++;
				returnAux = 0;

			}
			else // colocar al medio/final
			{
				auxNode = getNode(this, nodeIndex-1);

			    if(auxNode != NULL)
			    {
			    	pNode->pElement  = pElement;
			    	pNode->pNextNode = auxNode->pNextNode;
			    	auxNode->pNextNode = pNode;
			    	this->size++;
			    	returnAux = 0;
			    }
			    else
			    {
			    	free(pNode);
			    }
			}
    	}
    }
    return returnAux;
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
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lastNode = ll_len(this);//ultimo nodo

    if(this != NULL)
    {
       if(addNode(this, lastNode, pElement)==0)
       {
    	   returnAux = 0;
       }
    }

    return returnAux;
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
    void* returnAux = NULL;
    Node* pAuxNode = NULL;
    int len = ll_len(this);

    if(this !=  NULL && index > -1 && index < len)
    {
    	pAuxNode = getNode(this, index);//obtengo el nodo

    	if(pAuxNode != NULL)
    	{
    		returnAux = pAuxNode->pElement;
    	}
    }

    return returnAux;
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
    int returnAux = -1;
    int len = ll_len(this);
    Node* pAuxNode;

    if(this != NULL && index > -1 && index < len)
    {
    	pAuxNode = getNode(this, index);

    	if(pAuxNode != NULL)
    	{
    		pAuxNode->pElement = pElement;
    		returnAux = 0;
    	}
    }

    return returnAux;
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
    int returnAux = -1;
    int len = ll_len(this);
    Node* pNodeOne = NULL;// nodo posicion 0
    Node* pPreviousNode = NULL;//nodo anterior
    Node* pNode = NULL;//nodo en la posicion > 0

    if(this != NULL && index > -1 && index < len)
    {

    	if(index == 0)
    	{
    		pNodeOne = getNode(this,index);

    		if(pNodeOne != NULL)
    		{
    			if(len>1)
    			{
    				this->pFirstNode->pNextNode =  pNodeOne->pNextNode;
    				free(pNodeOne);
    				this->size--;
    				returnAux = 0;
    			}
    			else
    			{
    				free(pNodeOne);
    				this->size--;
    				free(this->pFirstNode);
    				this->pFirstNode = NULL;
    				returnAux = 0;
    			}
    		}
    	}
    	else
    	{
    		pPreviousNode = getNode(this, index-1);
    		pNode = getNode(this, index);

    		if(pPreviousNode != NULL && pNode != NULL)
    		{
    			pPreviousNode->pNextNode = pNode->pNextNode;
    			free(pNode);
    			this->size--;
    			returnAux = 0;
    		}
    	}
    }

    return returnAux;
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
    int returnAux = -1;
    int i;
    int len = ll_len(this);

    if(this != NULL && len > -1)
    {
    	for(i=0;i<len;i++)
    	{
           ll_remove(this, 0);
    	}
    	returnAux = 0;
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
    int returnAux = -1;

    if(this != NULL)
    {
      if(ll_clear(this)==0)
      {
    	  free(this);
    	  returnAux = 0;
      }
    }

    return returnAux;
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
    int returnAux = -1;
    int i;
    int len= ll_len(this);
    void* auxElement;

    if(this != NULL)
    {
    	for(i=0;i<len;i++)
    	{
    		auxElement = ll_get(this, i);//getnode

    		if(auxElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}

    	}
    }

    return returnAux;
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
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this))
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
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
	int returnAux = -1;
	int len = ll_len(this);


	if(this != NULL && index > -1 && index <= len)
	{
		if(addNode(this, index, pElement)==0)
		{
			returnAux = 0;
		}
	}
	return returnAux;
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
    void* returnAux = NULL;

    if(this != NULL && index > -1)
    {
        returnAux = ll_get(this, index);//retorna el puntero al elemento
        ll_remove(this, index);//elimina el nodo que lo contenia al elemento
    }

    return returnAux;
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

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement)==-1)
    	{
    		returnAux = 0;// no lo contiene
    	}
    	else
    	{
    		returnAux = 1;//si lo contiene
    	}
    }

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
    int i;
    int lenThis2 = ll_len(this2);
    void* pElement;
    int contador = 0;

    if(this != NULL && this2 != NULL)
    {
       for(i=0;i<lenThis2;i++)
       {
    	   pElement = ll_get(this2, i);//obtengo el elemento de la lista2 por cada posicion

    	   if(pElement != NULL)
    	   {
    		   if(ll_contains(this, pElement)==1)//verifico que este en la list 1
    		   {
                  contador++;//incrementa si da verdadero
    		   }
    	   }

       }

       if(lenThis2 == contador)
       {
    	   returnAux = 1;
       }
       else
       {
    	   returnAux = 0;
       }
    }

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
{                                     //desde      hasta
    LinkedList* cloneArray = NULL;
    int lenThis = ll_len(this);
    int i;
    void* pElement;


    if(this!=NULL && from > -1 && from <= lenThis && to > from && to <= lenThis && to > -1)
    {
        cloneArray = ll_newLinkedList();

        for(i=from;i<to;i++)
        {
        	pElement = ll_get(this, i);

        	if(ll_add(cloneArray, pElement)==-1)//agrega el elemento, pero si da error al cargar entonces libero y borro la cloneArray y dejo de copiar
        	{
        		ll_deleteLinkedList(cloneArray);//??
        		break;
        	}
        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int lenThis = ll_len(this);

    if(this != NULL)
    {
       cloneArray = ll_subList(this, 0, lenThis);
    }

    return cloneArray;
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
    void* pElement1;
    void* pElement2;
    int i;
    int j;
    int valor;
    int len= ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
       for(i=0;i<len-1;i++)
       {
    	   for(j=i+1;j<len;j++)
    	   {
    		   pElement1 = ll_get(this, i);
    		   pElement2 = ll_get(this, j);

    		   valor = pFunc(pElement1,pElement2);

    		   if(pElement1 != NULL && pElement2 != NULL)
    		   {

    			   if(order == 1)//ascendente
    			   {
    				   if(valor > 0)// 1 si el primero en mayor que el segundo
    				   {
    					   ll_set(this, i, pElement2);
    					   ll_set(this, j, pElement1);
    				   }
    			   }
    			   else if(order == 0)//descendente
    			   {
    				   if(valor < 0)// -1 si el primero es menor que el segundo
    				   {
    					   ll_set(this, i, pElement2);
    					   ll_set(this, j, pElement1);
    				   }
    			   }

    		   }
    	   }
       }
       returnAux = 0;
    }

    return returnAux;

}

