#include <iostream>
#include <string>
#include<string.h>
#include<stdio.h>

using namespace std;



struct node
{
    string data;
    node *next;
};	
struct sort_data{
private:
    node *name_root ;
public:
    void push(const char*name,int birthdate); // push data;
    void sort_by_birth(); // sort the birth linked list
    void sort_by_alphabet(); // sort the alphabet linked list
    void print_birth(); // print the data of the birth linked list
    void print_alph(); // print of the data of the alphabet linked list
};
class list
{
    private:
    node *head, *tail;
    public:
    list()
    {
      head=NULL;
      tail=NULL;
    }
    void ListisShekmna(string value)
    {
      node *temp=new node;
      temp->data=value;
      temp->next=NULL;
      if(head==NULL)
      {
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
    }
void display()
  {
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }
void insert_start(int value)
  {
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
  }
void insert_position(int pos, int value)
  {
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
      pre=cur;
      cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;	
    temp->next=cur;
  }
    void delete_first()
  {
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
  }
    void delete_last()
  {
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
      previous=current;
      current=current->next;	
    }
    tail=previous;
    previous->next=NULL;
    delete current;
  }
    void delete_position(int pos)
  {
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
	}
bool compare(string a, string b){ //comparing by characters
    for(int i = 0; i < 5; i++){
        if(a[i] > b[i]) return true;
    }

    return false;
}



};
  
int main(int argc, char** argv) {
	list obj;
        char str[5][20], t[20];
        int i, j;
        cout<<"\n Enter Any Five Names : \n\n";
        for(i=0; i<5; i++)
        {
                cout<<" ";
                cin>>str[i];
        }
        for(i=1; i<5; i++)
        {
                for(j=1; j<5; j++)
                {
                        if(strcmp(str[j-1], str[j])>0)
                        {
                                strcpy(t, str[j-1]);
                                strcpy(str[j-1], str[j]);
                                strcpy(str[j], t);
                               
                        }
                }
        }
        cout<<"\n Names Sorted in Alphabetical Order : \n\n";
        for(i=0; i<5; i++)
        {
                cout<<" ";
            	cout<<str[i]<<"\n";
                obj.display();
        }
        return 0;
}

