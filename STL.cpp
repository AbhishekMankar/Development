#include<iostream>
using namespace std;


template<class T>
struct node
{
    T data;
    struct node *next;
};


template<class T>
struct node1
{
    T data;
    struct node1<T> *next;
    struct node1<T> *prev;
};

/////Singly Linear linked list


template<class T>
class SinglyLL
{
    private:
    struct node<T>* first;
    int size;
    
    public:
    SinglyLL();
    void Insertfirst(T);
    void Insertlast(T);
    void InsertAtPos(T,int);
    void Deletefirst();
    void Deletelast();
    void DeleteAtPos(int);
    void Display();
    int count();
    
};


    template<class T>
    SinglyLL<T>::SinglyLL()
    {
        first=NULL;
        size=0;
    }
    
    template<class T>
    void SinglyLL<T>::Insertfirst(T no)
    {
        struct node<T> * newn=new struct node<T>;
        newn->data=no;
        newn->next=NULL;
        
        if(first==NULL)
        {
            first=newn;
        }
        else
        {
            newn->next=first;
            first=newn;
        }
        size++;
    
    }
    
    
    template<class T>
    void SinglyLL<T>::Insertlast(T no)
    {
        struct node<T> * newn=new struct node<T>;
        newn->data=no;
        newn->next=NULL;
        
        if(first==NULL)
        {
            first=newn;
        }
        else
        {
            struct node<T> * temp=first;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newn;
        }
        size++;
    }
    
    
    template<class T>
    void SinglyLL<T>::InsertAtPos(T no,int pos)
    {
        if(pos<0 || pos>size+1)
        {
            cout<<"INVALID POSITION"<<"\n";
            return;
        }
        
        else if(pos==1)
        {
            Insertfirst(no);
        }
        
        else if(pos==size+1)
        {
            Insertlast(no);
        }
        
        else
        {
            struct node<T> * temp=first;
            
            struct node<T> * newn=new struct node<T>;
            newn->data=no;
            newn->next=NULL;
            
            int i=1;
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            newn->next=temp->next;
            temp->next=newn;
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::Deletefirst()
    {
        struct node<T> * temp=first;
        
        if(first!=NULL)          //here we can write if(size!=0);
        {
            first=first->next;
            delete(temp);
            size--;
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::Deletelast()
    {
        struct node<T> * temp=first;
        
        if(first==NULL)
        {
            return;
        }
        
        else if(first->next==NULL)
        {
            delete first;
            first=NULL;
            size--;
        }
        else
        {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
        size--;
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::DeleteAtPos(int pos)
    {
        
        if(pos<0 || pos>size+1)
        {
            cout<<"INVALID POSITION"<<"\n";
            return;
        }
        
        else if(pos==1)
        {
            Deletefirst();
        }
        
        else if(pos==size)
        {
            Deletelast();
        }
        
        else
        {
            int i=1;
            
            struct node<T> * temp=first;
            
            while(i<pos-1)
            {
                temp=temp->next;
                i++;
            }
        
            temp->next=temp->next->next;
            size--;
            
            
        }
    }
    
    
    template<class T>
    void SinglyLL<T>::Display()
    {
        struct node<T> * temp=first;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    
    
    template<class T>
    int SinglyLL<T>::count()
    {
       
       return size; 
    }




//singly circular linked list

template<class T>
class SinglyCL
{
  private:
  struct node<T> *first;
  struct node<T> *last;
  int size;
  
  public:
  SinglyCL();
  void Display();
  int count();
  void Insertfirst(T);
  void Insertlast(T);
  void InsertAtPos(T,int);
  void Deletefirst();
  void Deletelast();
  void DeleteAtPos(int);
  
};


  template<class T>
  SinglyCL<T>::SinglyCL()
  {
      first=NULL;
      last=NULL;
      size=0;
  }
  
  template<class T>
  void SinglyCL<T>::Display()
  {
      struct node <T>*temp=first;
      if(first==NULL && last==NULL)
      {
          return ;
      }
      do{
          cout<<temp->data<<" ";
          temp=temp->next;
      }while(temp != last->next);
      
  }
  
  
  template<class T>
  int SinglyCL<T>::count()
  {
      int icnt=0;
      
      struct node<T> *temp=first;
      if(first==NULL && last==NULL)
      {
          return 0;
      }
      do{
          icnt++;
          temp=temp->next;            // we can use for loop also bcoz we have size element
      }while(temp != last->next);
      
      return icnt;
  }
  
  
  
  template<class T>
  void SinglyCL<T>::Insertfirst(T no)
  {
      struct node<T> *newn=new struct node<T>;
      newn->data=no;
      newn->next=NULL;
      
      if(first==NULL && last==NULL)
      {
          first=newn;
          last=newn;
      }
      else
      {
          newn->next=first;
          first=newn;
      }
      last->next=first;
      size++;
  }
  
  
  template<class T>
  void SinglyCL<T>::Insertlast(T no)
  {
      struct node<T> *newn=new struct node<T>;
      newn->data=no;
      newn->next=NULL;
      
      if(first==NULL && last==NULL)
      {
          first=newn;
          last=newn;
      }
      else
      {
         last->next=newn;
         last=newn;
      }
      last->next=first;
      size++;
  }
  
  
  template<class T>
  void SinglyCL<T>::InsertAtPos(T no,int pos)
  {
      if(pos<1 || pos>size+1)
      {
          cout<<"\n INVALID POSITION";
          return;
      }
      
      else if(pos==1)
      {
          Insertfirst(no);
      }
      
      else if(pos==size+1)
      {
          Insertlast(no);
      }
      
      else
      {
          struct node<T> *newn=new struct node<T>;
          newn->data=no;
          newn->next=NULL;
          
          struct node<T> *temp=first;
          int i=1;
          while(i<pos-1)          // we can use for loop also
          {
              temp=temp->next;
              i++;
          }
          newn->next=temp->next;
          temp->next=newn;
          size++;               // inside bcoz other function have size++ in their function so they will do
      }
      
  }
  
  
  
  template<class T>
  void SinglyCL<T>::Deletefirst()
  {
      if(first==NULL && last==NULL)
      {
          return ;
      }
      
      else if(first==last)
      {
          delete first;
          first=NULL;
          last=NULL;
      }
      
      else
      {
          first=first->next;
          delete last->next;
          last->next=first;
      }
      size--;
  }
  
  
  
  template<class T>
  void SinglyCL<T>::Deletelast()
  {
      if(first==NULL && last==NULL)
      {
          return ;
      }
      
      else if(first==last)
      {
          delete first;
          first=NULL;
          last=NULL;
      }
      
      else
      {
          struct node<T> *temp=first;
          while(temp->next != last)
          {
              temp=temp->next;
          }
          delete last;
          last=temp;
          last->next=first;
          
      }
      size--;
  }
  
  
  
  template<class T>
  void SinglyCL<T>::DeleteAtPos(int pos)
  {
       if(pos<1 || pos>size)
      {
          cout<<"\n INVALID POSITION";
          return;
      }
      
      else if(pos==1)
      {
          Deletefirst();
      }
      
      else if(pos==size)
      {
          Deletelast();
      }
      
      else
      {
          struct node<T> *temp=first;
          int i=1;
          while(i<pos-1)          // we can use for loop also
          {
              temp=temp->next;
              i++;
          }
          struct node<T> *p=temp->next;
          temp->next=p->next;
          delete p;
          size--;
      }
  }


/// Doubly Linear linked list

template<class T>
class DoublyLL
{
    private:
    struct node1<T> *first;
    int size;
    
    public:
    DoublyLL();
    void Display();
    int count();
    void Insertfirst(T);
    void Insertlast(T);
    void Deletefirst();
    void Deletelast();
    void InsertAtPos(T no,int pos);
    void DeleteAtPos(int);
};




template<class T>
DoublyLL<T>::DoublyLL()
    {
        first=NULL;
        size=0;
    }
    


template<class T>
void DoublyLL<T>::Display()
{
  
  if(first==NULL)
  {
      return;
  }
  else
  {
      struct node1<T> *temp=first;
      while(temp!=NULL)
      {
          cout<<temp->data<<" ";
          temp=temp->next;
      }
  }
 
}



template<class T>
int DoublyLL<T>::count()
{
    return size;
}



template<class T>
void DoublyLL<T>::Insertfirst(T no)
{
    struct node1<T> *newn=new struct node1<T> ;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    
    if(first==NULL)
    {
        first=newn;
    }
    else
    {
        newn->next=first;
        first=newn;
        newn->next->prev=newn;
    }
    size++;
}



template<class T>
void DoublyLL<T>::Insertlast(T no)
{
    struct node1<T> *newn=new struct node1<T> ;
    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;
    
    if(first==NULL)
    {
        first=newn;
    }
    
    else
    {
        struct node1<T> *temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    size++;
}




template<class T>
void DoublyLL<T>::Deletefirst()
{
    
 struct node1<T> *temp=first;
  if(first==NULL)
  {
      cout<<"\n Linked list is empty";
      return;
  }
  
  else
  {
      first=first->next;
      first->prev=NULL;
      delete temp;
  }
  size--;
}




template<class T>
void DoublyLL<T>::Deletelast()
{
  if(first==NULL)
  {
      cout<<"\n Linked list is empty";
      return;
  }
  else if(first->next==NULL)
  {
      delete first;
      first=NULL;
  }
  else
  {
      struct node1<T> *temp=first;
      while(temp->next->next!=NULL)
      {
          temp=temp->next;
      }
      temp->next->prev=NULL;
      delete temp->next;
      temp->next=NULL;
      
  }
  size--;
}



template<class T>
void DoublyLL<T>::InsertAtPos(T no,int pos)
{
    int isize=count();
    if(pos<1 || pos>isize+1)
    {
        cout<<"\n INVALID POSITION \n";
        return;
    }
    else if(pos==1)
    {
        Insertfirst(no);
    }
    else if(pos==size+1)
    {
        Insertlast(no);
    }
    else
    {
        struct node1<T> *newn=new struct node1<T> ;
        newn->data=no;
        newn->next=NULL;
        newn->prev=NULL;
        
        struct node1<T> *temp=first;
        
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newn->next=temp->next;
        temp->next=newn;
        newn->prev=temp;
        newn->next->prev=newn;
        size++;
        
    }
    
}




template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    int isize=count();
    if(pos<1 || pos>isize)
    {
        cout<<"\n INVALID POSITION \n";
        return;
    }
    else if(pos==1)
    {
        Deletefirst();
    }
    else if(pos==size)
    {
        Deletelast();
    }
    else
    {
        struct node1<T> *temp=first;
        
        int i=1;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        struct node1<T> *p=temp->next;
        temp->next=p->next;
        p->next->prev=temp;
        delete p;
        size--;
    }
    
}


//Doubly circular linked list

template<class T>
class DoublyCL
{
private:
    struct node1<T> *first;
    struct node1<T> *last;
    int size;
    
public:
    DoublyCL();
    void Display();
    int Count();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no , int ipos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
};


template<class T>
DoublyCL<T>::DoublyCL()
    {
        first = NULL;
        last = NULL;
        size = 0;
    }


template<class T>
void DoublyCL<T>:: InsertFirst(T no)
{
    struct node1<T> *newn = new struct node1<T> ;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}


template<class T>
void DoublyCL<T>:: InsertLast(T no)
{
    struct node1<T> *newn = new struct node1<T> ;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    
    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = newn;
    }
    
    last->next = first;
    first->prev = last;
    size++;
}



template<class T>
void DoublyCL<T>:: Display()
{
    struct node1<T> *temp = first;
    
    for(int i = 1; i <= size; i++)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp->next;
    }
    cout<<"\n";
}




template<class T>
int DoublyCL<T>:: Count()
{
    return size;
}




template<class T>
void DoublyCL<T>:: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}




template<class T>
void DoublyCL<T>:: DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first  = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last->next;
        first->prev = last;
        last->next = first;
    }
    size--;
}


template<class T>
void DoublyCL<T>:: InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > size+1))
    {
        return;
    }
    
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        struct node1<T> *newn= new struct node1<T> ;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        
        struct node1<T> *temp = first;
        
        for(int i = 1; i < ipos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size ++;
    }
}




template<class T>
void DoublyCL<T>:: DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > size))
    {
        return;
    }
    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == size)
    {
        DeleteLast();
    }
    else
    {
        struct node1<T> *temp = first;
        
        for(int i = 1; i < ipos -1 ; i ++)
        {
            temp = temp -> next;
        }
       
        temp -> next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
        size--;
    }
}


int main()
{
    SinglyLL<int>obj1;
    int iret=0;
    
    obj1.Insertfirst(1);
    obj1.Insertlast(2);
    obj1.InsertAtPos(3,3);
    
    obj1.Display();
    iret=obj1.count();
    cout<<"\n count is : "<<iret;
    
    cout<<"\n";
    
    SinglyCL<int>obj2;
    int iret2=0;
    
    obj2.Insertfirst(1);
    obj2.Insertlast(2);
    obj2.InsertAtPos(3,3);
    
    obj2.Display();
    iret2=obj2.count();
    cout<<"\n count is : "<<iret2;
    
    cout<<"\n";
    
    DoublyLL<char>obj3;
    int iret3=0;
    
    obj3.Insertfirst('A');
    obj3.Insertlast('B');
    obj3.InsertAtPos('C',3);
    obj3.InsertAtPos('D',2);
    
    obj3.Display();
    iret3=obj3.count();
    cout<<"\n count is : "<<iret3;
    
    
    cout<<"\n";
    
    
    DoublyCL<double>obj4;
    int iret4=0;
    
    obj4.InsertFirst(1.1);
    obj4.InsertLast(2.2);
    obj4.InsertAtPos(3.3,3);
    obj4.InsertAtPos(4.4,2);
    
    obj4.Display();
    iret4=obj4.Count();
    cout<<"\n count is : "<<iret4;
    
    
    
    
    return 0;
}
