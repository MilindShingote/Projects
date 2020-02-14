#include<iostream>
#include<malloc.h>
#define FALSE 0
#define TRUE 1
typedef int BOOL;

using namespace std;

template<class T>
struct TNode
{
	T Data;
	struct TNode<T>*Lchild;
	struct TNode<T>*Rchild;
};

template<class T>
class Tree
{
	private:
		TNode<T>*Head;

	public:
		Tree();
		
		void Insert(T);
		void Inorder(TNode<T>*);
		void Preorder(TNode<T>*);
		void Postorder(TNode<T>*);
		int Count(TNode<T>*);
		BOOL Search(TNode<T>*,int);
};

template<class T>
Tree<T>::Tree()
{
	Head=NULL;
}

template<class T>		
void Tree<T>::Insert(T iNo)
{
	TNode<T>*Newn=NULL;
	Newn=new TNode<T>;
		
	Newn->Data=iNo;
	Newn->Lchild=NULL;
	Newn->Rchild=NULL;
		
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		TNode<T>*Temp=Head;
			
		while(1)
		{
			if(iNo>Temp->Data)
			{
				if(Temp->Rchild==NULL)
				{
					Temp->Rchild=Newn;
					break;
				}
				Temp=Temp->Rchild;
			}
			else if(iNo<Temp->Data)
			{
				if(Temp->Lchild==NULL)
				{
					Temp->Lchild=Newn;
					break;
				}
				Temp=Temp->Lchild;
			}
			else
			{
				free(Newn);
				break;
			}
		}
	}
}

template<class T>				
void Tree<T>::Inorder(TNode<T>*First)	
{
	static BOOL Flag=TRUE;
	if(Flag==TRUE)
	{
		First=Head;
		Flag=FALSE;
	}
	if(First!=NULL)	
	{
		Inorder(First->Lchild);
		cout<<First->Data<<"\t";
		Inorder(First->Rchild);
	}
}

template<class T>		
void Tree<T>::Preorder(TNode<T>*First)	
{
	static BOOL Flag=TRUE;
	if(Flag==TRUE)
	{
		First=Head;
		Flag=FALSE;
	}
	if(First!=NULL)	
	{
		cout<<First->Data<<"\t";
		Preorder(First->Lchild);
		Preorder(First->Rchild);
	}
}

template<class T>		
void Tree<T>::Postorder(TNode<T>*First)	
{
	static BOOL Flag=TRUE;
	if(Flag==TRUE)
	{
		First=Head;
		Flag=FALSE;
	}
	if(First!=NULL)	
	{
		Postorder(First->Lchild);
		Postorder(First->Rchild);
		cout<<First->Data<<"\t";
	}
}

template<class T>		
int Tree<T>::Count(TNode<T> *First)
{
	static BOOL Flag=TRUE;
	static int iCnt=0;
	if(Flag==TRUE)
	{
		First=Head;
		Flag=FALSE;
	}
	if(First!=NULL)	
	{
		iCnt++;
		Count(First->Lchild);
		Count(First->Rchild);
	}
	return iCnt;
}

template<class T>		
BOOL Tree<T>::Search(TNode<T> *First,int iNo)
		{
			static BOOL Flag=TRUE;
			if(Flag==TRUE)
			{
				First=Head;
				Flag=FALSE;
			}
			if(First!=NULL)	
			{
				if(First->Data==iNo)
				{
					return TRUE;
				}
				Count(First->Lchild);
				Count(First->Rchild);
			}
			return FALSE;
		}
/////////////////////////////////////////////////////

template<class T>
struct SNode
{
	T Data;
	struct SNode<T> *Next;
};

template<class T>
class Stack
{
	private:
	SNode<T>*Head;
	SNode<T>*Tail; 
	
	public:
		Stack();
		
		void InsertFirst(T);
		void Display();
		T DeleteLast();
};	

template<class T>
Stack<T>::Stack()
{
	Head=NULL;
}

template<class T>
void Stack<T>::InsertFirst(T No)
{
	SNode<T>*Newn=NULL;
	Newn=new SNode<T>;
	
	Newn->Data=No;
	Newn->Next=NULL;

	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
	}
}

template<class T>
void Stack<T>::Display()
{
	SNode<T>*Temp=Head;
	
	while(Temp!=NULL)
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Next;
	}
	cout<<"\n";
}

template<class T>
T Stack<T>::DeleteLast()
{
	T No=0;
	SNode<T>*Temp=Head;
	if(Head==NULL)
	{
		cout<<"Stack is Empty";
		return 0;
	}
	else
	{
		No=Head->Data;
		Head=Head->Next;
		delete Temp;
	}
	return No;
}
/////////////////////////////////////////////
template<class T>
class Queue
{
	private:
	SNode<T>*Head;
	SNode<T>*Tail; 
	
	public:
		Queue();
		void InsertLast(T);
		void Display();
		T DeleteFirst();
};

template<class T>
Queue<T>::Queue()
{
	Head=NULL;
	Tail=NULL;
}

template<class T>	
void Queue<T>::InsertLast(T No)
{
	SNode<T>*Newn=NULL;
	Newn=new SNode<T>;
	
	Newn->Data=No;
	Newn->Next=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Tail->Next=Newn;
		Tail=Tail->Next;
	}
}

template<class T>	
void Queue<T>::Display()
{
	SNode<T>*Temp=Head;
	
	while(Temp!=NULL)
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Next;
	}
	cout<<"\n";
}

template<class T>
T Queue<T>::DeleteFirst()
{
	T No=0;
	SNode<T>*Temp=Head;
	if(Head==NULL)
	{
		cout<<"Queue is Empty";
		return -1;
	}
	else if(Head==Tail)	
	{
		No=Head->Data;
		delete(Head);
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		No=Head->Data;
		Head=Head->Next;
		delete(Temp);
	}
	return No;
}
/////////////////////////////////////////////////

template<class T>
class SinglyLLL
{	
	private:
	SNode<T>* Head;
	int Size;
	
	public:
	SinglyLLL();
	~SinglyLLL();
	
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
	
};

template<class T>
SinglyLLL<T>::SinglyLLL()
{
	Head=NULL;
	Size=0;
}

template<class T>
void SinglyLLL<T>::InsertFirst(T iNo)
{
	SNode<T>*Newn=NULL;
	Newn=new SNode<T>;
		
	Newn->Data=iNo;
	Newn->Next=NULL;
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
	}
	Size++;
}

template<class T>
void SinglyLLL<T>::InsertLast(T iNo)
{
	SNode<T>*Temp=Head;
	SNode<T>*Newn=NULL;
	Newn=new SNode<T>;
	
	Newn->Data=iNo;
	Newn->Next=NULL;
	
	if(Head==NULL)
	{
		Newn->Next=Head;
		Head=Newn;
	}
	else
	{
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Newn;
	}
	Size++;
}

template<class T>
void SinglyLLL<T>::InsertAtPos(T iNo,int iPos)
{	
	int iSize=0;
	iSize=Count();
	
	if((iPos<1)||(iPos>iSize+1))
	{
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
		return;
	}
	else if(iPos==iSize+1)
	{
		InsertLast(iNo);
		return;
	}
	else
	{	
		SNode<T>* Newn=NULL;
		SNode<T>* Temp=Head;
		Newn=new SNode<T>;
		
		Newn->Data=iNo;
		Newn->Next=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next=Newn;
	}
	Size++;
}

template<class T>
void SinglyLLL<T>::DeleteFirst()
{
	SNode<T>* Temp=NULL;
	
	if(this->Head==NULL)
	{
		return;
	}
	else
	{
		Temp=Head;
		Head=Head->Next;
		free(Temp);
	}
	Size--;
}

template<class T>
void SinglyLLL<T>::DeleteLast()
{
	SNode<T>* Temp=Head;
	
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		free(Head);
		Head=NULL;
	}
	else
	{
		while(Temp->Next->Next!=NULL)	
		{
			Temp=Temp->Next;
		}
		free(Temp->Next);
		Temp->Next=NULL;
	}
	Size--;
}

template<class T>
void SinglyLLL<T>::DeleteAtPos(int iPos)
{
	int i=0,iSize=0;
	SNode<T>* Temp1=Head;
	SNode<T>* Temp2=NULL;
	iSize=Count();
	
	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
		
	if(iPos==1)
	{
		DeleteFirst();
		return;
	}
	else if(iPos==iSize)
	{
		DeleteLast();
		return;
	}
	else
	{
		for(i=1;i<iPos-1;i++)
		{
			Temp1=Temp1->Next;
		}
		Temp2=Temp1->Next;
		Temp1->Next=Temp2->Next;
		free(Temp2);
	}
	Size--;
}

template<class T>
int SinglyLLL<T>::Count()
{
	return Size;
}

template<class T>	
void SinglyLLL<T>::Display()
{
	SNode<T>* Temp=Head;
	cout<<"\n";
	while(Temp!=NULL)
	{
		printf("%d\t",Temp->Data);
		Temp=Temp->Next;
	}
}

template<class T>
SinglyLLL<T>::~SinglyLLL()
{
	SNode<T>* Temp=Head;

	while(Head!=NULL)
	{
		Temp=Head;
		Head=Head->Next;
		free(Temp);
	}
}

		
//////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCLL
{	
	private:
	SNode<T>* Head;
	SNode<T>* Tail;
	int Size;
	
	public:
	SinglyCLL();
	~SinglyCLL();
	
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Count();
	void Display();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
	Head=NULL;
	Tail=NULL;
	Size=0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T iNo)
{
	SNode<T>* Newn=NULL;
	Newn=new SNode<T>;
		
	Newn->Data=iNo;
	Newn->Next=NULL;
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
	}
	Tail->Next=Head;
	Size++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T iNo)
{
	SNode<T>* Temp=Head;
	SNode<T>* Newn=NULL;
	Newn=new SNode<T>;
		
	Newn->Data=iNo;
	Newn->Next=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Tail->Next=Newn;
		Tail=Tail->Next;
	}
	Tail->Next=Head;
	Size++;
}	

template<class T>
void SinglyCLL<T>::InsertAtPos(T iNo,int iPos)
{
	if((iPos<1)||(iPos>Size+1))
	{
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
		return;
	}
	else if(iPos==Size+1)
	{
		InsertLast(iNo);
		return;
	}
	else
	{
		SNode<T>* Temp=Head;
		SNode<T>* Newn=NULL;
		Newn=new SNode<T>;
		
		Newn->Data=iNo;
		Newn->Next=NULL;
	
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next=Newn;
	}
	Size++;
}

template<class T>		
void SinglyCLL<T>::DeleteFirst()
{
	SNode<T>* Temp=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		free(Head);
		Head=Tail=NULL;
	}
	else
	{
		Temp=Head;
		Head=Head->Next;
		free(Temp);
	}
	Tail->Next=Head;
	Size--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
	SNode<T>* Temp=Head;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		free(Head);	
		Head=Tail=NULL;
	}
	else
	{
		while(Temp->Next->Next!=Head)	
		{
				Temp=Temp->Next;
		}
		free(Temp->Next);
		Tail=Temp;
		Tail->Next=Head;
	}
	
	Size--;
}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
	int i=0,iSize=0;	
	SNode<T>* Temp1=Head;
	SNode<T>* Temp2=NULL;
	iSize=Count();

	if((iPos<1)||(iPos>iSize))
	{
		return;
	}
	
	if(iPos==1)
	{	
		DeleteFirst();
		return;
	}
	else if(iPos==iSize)
	{
		DeleteLast();
		return;
	}
	else
	{
		for(i=1;i<iPos-1;i++)
		{
			Temp1=Temp1->Next;
		}
		Temp2=Temp1->Next;
		Temp1->Next=Temp2->Next;
		free(Temp2);
	}
	Size--;
}

template<class T>	
void SinglyCLL<T>::Display()
{
	SNode<T>* Temp=Head;
	cout<<"\n";
	do
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Next;
	}while(Temp!=Tail->Next);
}

template<class T>
int SinglyCLL<T>::Count()
{
	return Size;
}

template<class T>
SinglyCLL<T>::~SinglyCLL()
{
	SNode<T>* Temp=Head;
	for(int i=1;i<=Size;i++)
	{
		Temp=Head;
		Head=Head->Next;
		free(Temp);
	}
}
////////////////////////////////////////////////////

template<class T>
struct DNode
{
	T Data;
	struct DNode<T> *Next;
	struct DNode<T> *Prev;
};

template<class T>
class DoublyLLL
{	
	private:
		DNode<T>*Head;
		int Size;
	public:
		DoublyLLL();
		~DoublyLLL();
	
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		int Count();
		void FDisplay();
		void BDisplay();
};

template<class T>
DoublyLLL<T>::DoublyLLL()
{
	this->Head=NULL;
	this->Size=0;
}

template<class T>
void DoublyLLL<T>::InsertFirst(T iNo)
{
	DNode<T>* Newn=NULL;
	Newn=new DNode<T>;
	
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head->Prev=Newn;
		Head=Newn;
	}
	Size++;
}	

template<class T>
void DoublyLLL<T>::InsertLast(T iNo)
{	
	DNode<T>* Temp=Head;
	DNode<T>* Newn=NULL;
	Newn=new DNode<T>;
		
	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->Prev=NULL;
		
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Newn;
		Newn->Prev=Temp;
	}
	Size++;
}

template<class T>
void DoublyLLL<T>::InsertAtPos(T iNo,int iPos)
{
	DNode<T>* Temp=Head;

	if((iPos<1)||(iPos>Size+1))
	{
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(iNo);
		return;
	}
	else if(iPos==Size+1)
	{
		InsertLast(iNo);
		return;
	}
	else
	{
		DNode<T>* Temp=Head;
		DNode<T>* Newn=NULL;
		Newn=new DNode<T>;
	
		Newn->Data=iNo;
		Newn->Next=NULL;
		Newn->Prev=NULL;

		for(int i=1;i<iPos-1;i++)	
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next->Prev=Newn;
		Temp->Next=Newn;
		Newn->Prev=Temp;
	}
	Size++;
}

template<class T>
void DoublyLLL<T>::DeleteFirst()
{
	if(Head==NULL)
	{	
		return;
	}	
	else if(Head->Next==NULL)
	{
		delete(Head);
		Head=NULL;
	}		
	else
	{
		Head=Head->Next;
		delete(Head->Prev);
		Head->Prev=NULL;
	}
	Size--;
}	

template<class T>
void DoublyLLL<T>::DeleteLast()
{
	if(Head==NULL)
	{	
		return;
	}
	else if(Head->Next==NULL)
	{
		delete(Head);
		Head=NULL;
	}
	else
	{
		DNode<T>* Temp=Head;
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Prev->Next=NULL;
		delete(Temp);
	}
	Size--;
}

template<class T>
void DoublyLLL<T>::DeleteAtPos(int iPos)
{
	DNode<T>* Temp1=Head;
	DNode<T>* Temp2=NULL;
	
	if((iPos<1)||(iPos>Size))
	{
		return;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
		return;
	}
	else if(iPos==Size)
	{
		DeleteLast();
		return;
	}	
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			Temp1=Temp1->Next;
		}
		Temp2=Temp1->Next;
		Temp1->Next=Temp2->Next;
		Temp1->Next->Prev=Temp1;
		delete(Temp2);
	}
	Size--;
}

template<class T>		
void DoublyLLL<T>::FDisplay()
{
	DNode<T>* Temp=Head;
	cout<<"\n";
	while(Temp!=NULL)
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Next;
	}
	
}

template<class T>		
void DoublyLLL<T>::BDisplay()
{	
	DNode<T>*Temp=Head;
	cout<<"\n";
	while(Temp->Next!=NULL)
	{
		Temp=Temp->Next;
	}
	while(Temp!=NULL)
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Prev;
	}
	
}

template<class T>
int DoublyLLL<T>::Count()
{
	return this->Size;
}	

template<class T>
DoublyLLL<T>::~DoublyLLL()
{
	DNode<T>* Temp=Head;
	
	while(Head!=NULL)
	{
		Temp=Head;
		Head=Head->Next;
		delete(Temp);
	}
}


//////////////////////////////////////////////////////////

template<class T>
class DoublyCLL
{
	private:
		DNode<T>* Head;
		DNode<T>* Tail;
		int Size;
	public:
		DoublyCLL();
		~DoublyCLL();
	
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		int Count();
		void FDisplay();
		void BDisplay();	
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
	Head=NULL;
	Tail=NULL;
	Size=0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T iNo)
{
	DNode<T>* Newn=NULL;
	Newn=new DNode<T>;

	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->Prev=NULL;
			
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head->Prev=Newn;	
		Head=Newn;
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	Size++;
}	

template<class T>
void DoublyCLL<T>::InsertLast(T iNo)	
{	                                                                                                                                                                                               
	DNode<T>* Newn=NULL;
	Newn=new DNode<T>;

	Newn->Data=iNo;
	Newn->Next=NULL;
	Newn->Prev=NULL;
				
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Tail->Next=Newn;
		Newn->Prev=Tail;
		Tail=Tail->Next;
	}	
	Tail->Next=Head;
	Head->Prev=Tail;
	Size++;
}

template<class T>	
void DoublyCLL<T>::InsertAtPos(T iNo,int iPos)
{
	DNode<T>* Temp=Head;
	if((iPos<1)||(iPos>Size+1))
	{
		return;
	}
			
	if(iPos==1)
	{
		InsertFirst(iNo);
		return;
	}
	else if(iPos==Size+1)
	{
		InsertLast(iNo);
		return;
	}
	else
	{
		DNode<T>* Temp=Head;
		DNode<T>* Newn=NULL;
		Newn=new DNode<T>;
	
		Newn->Data=iNo;
		Newn->Next=NULL;
		Newn->Prev=NULL;
		
		for(int i=1;i<iPos-1;i++)	
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next->Prev=Newn;
		Temp->Next=Newn;
		Newn->Prev=Temp;
	}
	Size++;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{	
		return;
	}	
	else if(Head==Tail)
	{
		delete(Head);
		Head=Tail=NULL;
	}		
	else
	{
		Head=Head->Next;
		delete(Head->Prev);
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	Size--;
}	

template<class T>
void DoublyCLL<T>::DeleteLast()
{
	if((Head==NULL)&&(Tail==NULL))
	{	
		return;
	}
	else if(Head==Tail)
	{
		delete(Head);
		Head=Tail=NULL;
	}
	else
	{
		DNode<T>* Temp=Tail;
		Tail=Tail->Prev;
		delete(Temp);
	}
	Tail->Next=Head;
	Head->Prev=Tail;
	Size--;
}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
	DNode<T>* Temp1=Head;
	DNode<T>* Temp2=NULL;
		
	if((iPos<1)||(iPos>Size))
	{
		return;
	}
			
	if(iPos==1)
	{
		DeleteFirst();
		return;
	}
	else if(iPos==Size)
	{
		DeleteLast();
		return;
	}	
	else
	{
		for(int i=1;i<iPos-1;i++)
		{
			Temp1=Temp1->Next;
		}
		Temp2=Temp1->Next;
		Temp1->Next=Temp2->Next;
		Temp1->Next->Prev=Temp1;
		delete(Temp2);
	}
	Size--;
}

template<class T>		
void DoublyCLL<T>::FDisplay()
{
	DNode<T>* Temp=Head;
	cout<<"\n";
	do
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Next;
	}while(Temp!=Tail->Next);
		
}

template<class T>		
void DoublyCLL<T>::BDisplay()
{
	DNode<T>*Temp=Tail;
	cout<<"\n";
	do
	{
		cout<<Temp->Data<<"\t";
		Temp=Temp->Prev;
	}while(Temp!=Head->Prev);
			
}

template<class T>	
int DoublyCLL<T>::Count()
{
	return Size;
}

template<class T>
DoublyCLL<T>::~DoublyCLL()
{
	DNode<T>* Temp=Head;
	
	for(int i=1;i<=Size;i++)
	{
		Temp=Head;
		Head=Head->Next;
		delete(Temp);
	}
}

///////////////////////////////////////
int main()
{
	int iRet=0;
	float fRet=0.0;	
	BOOL bRet=FALSE;
	Tree<int>Tobj;
	
	Tobj.Insert(10);
	Tobj.Insert(20);			
	Tobj.Insert(5);
	Tobj.Insert(30);
	
	Tobj.Inorder(NULL);
	cout<<"\n";
	Tobj.Preorder(NULL);
	cout<<"\n";
	Tobj.Postorder(NULL);
	cout<<"\n";
	iRet=Tobj.Count(NULL);
	cout<<iRet;
	cout<<"\n";
	bRet=Tobj.Search(NULL,10);
	if(bRet==FALSE)
	{
		cout<<"Element Not Found";
	}
	else
	{
		cout<<"Element Found";
	}

	Stack <float>Sobj;	
	Sobj.InsertFirst(50.5);
	Sobj.InsertFirst(40.4);
	Sobj.InsertFirst(30.3);
	Sobj.InsertFirst(20.2);
	Sobj.InsertFirst(10.1);
	cout<<"\n";
	Sobj.Display();
	fRet=Sobj.DeleteLast();
	cout<<iRet<<"\t";
	fRet=Sobj.DeleteLast();
	cout<<iRet<<"\t";
	fRet=Sobj.DeleteLast();
	cout<<iRet<<"\t";
	fRet=Sobj.DeleteLast();
	cout<<iRet<<"\t";
	fRet=Sobj.DeleteLast();
	cout<<iRet<<"\t";
	fRet=Sobj.DeleteLast();
	cout<<"\n";
	
	Queue <int>Qobj;
	Qobj.InsertLast(50);
	Qobj.InsertLast(40);
	Qobj.InsertLast(30);
	Qobj.InsertLast(20);
	Qobj.InsertLast(10);
	cout<<"\n";
	Qobj.Display();
	iRet=Qobj.DeleteFirst();
	cout<<iRet<<"\t";
	iRet=Qobj.DeleteFirst();
	cout<<iRet<<"\t";
	iRet=Qobj.DeleteFirst();
	cout<<iRet<<"\t";
	iRet=Qobj.DeleteFirst();
	cout<<iRet<<"\t";
	iRet=Qobj.DeleteFirst();
	cout<<iRet<<"\t";
	iRet=Qobj.DeleteFirst();
	cout<<"\n";
	
	SinglyLLL <int>SLobj1;
	SLobj1.InsertFirst(40);
	SLobj1.InsertFirst(30);
	SLobj1.InsertFirst(10);
	SLobj1.InsertLast(50);
	SLobj1.InsertAtPos(20,2);
	SLobj1.Display();
	SLobj1.DeleteFirst();
	SLobj1.DeleteLast();
	SLobj1.DeleteAtPos(2);
	SLobj1.Display();
	iRet=SLobj1.Count();
	cout<<"\n"<<iRet;
	cout<<"\n";

	SinglyCLL <float>SCobj1;
	SCobj1.InsertFirst(40.4);
	SCobj1.InsertFirst(30.3);
	SCobj1.InsertFirst(10.1);
	SCobj1.InsertLast(50.5);
	SCobj1.InsertAtPos(20.2,2);
	SCobj1.Display();
	SCobj1.DeleteFirst();
	SCobj1.DeleteLast();
	SCobj1.DeleteAtPos(2);
	SCobj1.Display();
	fRet=SCobj1.Count();
	cout<<"\n"<<iRet;
	cout<<"\n";

	DoublyLLL <int>DLobj1;
	DLobj1.InsertFirst(50);
	DLobj1.InsertFirst(40);
	DLobj1.InsertFirst(30);
	DLobj1.InsertFirst(10);
	DLobj1.InsertLast(70);
	DLobj1.InsertAtPos(20,2);
	DLobj1.FDisplay();
	DLobj1.DeleteFirst();
	DLobj1.DeleteLast();
	DLobj1.DeleteAtPos(2);
	DLobj1.FDisplay();
	DLobj1.BDisplay();
	iRet=DLobj1.Count();
	cout<<"\n"<<iRet;
	cout<<"\n";	
	
	DoublyCLL <float>dobj1;
	dobj1.InsertFirst(60.6);
	dobj1.InsertFirst(50.5);
	dobj1.InsertFirst(40.4);
	dobj1.InsertFirst(30.3);
	dobj1.InsertFirst(10.1);
	dobj1.InsertLast(70.7);
	dobj1.InsertAtPos(20.2,2);
	dobj1.FDisplay();
	dobj1.DeleteFirst();
	dobj1.DeleteLast();
	dobj1.DeleteAtPos(5);
	dobj1.FDisplay();
	dobj1.BDisplay();
	fRet=dobj1.Count();	
	cout<<"\n"<<iRet;
	return 0;
}
