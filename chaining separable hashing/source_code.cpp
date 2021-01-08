#include <iostream>
#include <fstream>
#include<string>
const int T_S = 3000;
using namespace std;
struct HashTableEntry {
   int  k;
   string v;
   HashTableEntry *n;
   HashTableEntry *p;
   HashTableEntry(int k,string v) 
   {
      this->k = k;
      this->v = v;
      this->n = NULL;
   }
};
class HashMapTable {
   public:
      HashTableEntry **ht, **top;
      
      HashMapTable() 
	  {
         ht = new HashTableEntry*[T_S];
         for (int i = 0; i < T_S; i++)
            ht[i] = NULL;
      }
      int HashFunc(int key) 
	  {
         return key % T_S;
      }
      void Insert(int k,string v) 
	  {
         int hash_v = HashFunc(k);
         HashTableEntry* p = NULL;
         HashTableEntry* temp = ht[hash_v];
         while (temp!= NULL) {
            p = temp;
            temp = temp->n;
         }
         if (temp == NULL) 
		 {
            temp = new HashTableEntry(k, v);
            if (p == NULL) {
               ht[hash_v] = temp;
            } else {
               p->n = temp;
            }
         } 
		 else 
		 {
            temp->v = v;
         }
      }
      void Remove(int k) 
	  {
         int hash_v = HashFunc(k);
         HashTableEntry* temp = ht[hash_v];
         HashTableEntry* p = NULL;
         if (temp == NULL || temp->k != k)
		  {
            cout<<"No Element found at key "<<k<<endl;
            return;
          }
         while (temp->n != NULL) 
		 {
            p = temp;
            temp = temp->n;
         }
         if (p != NULL) 
		 {
            p->n = temp->n;
         }
         delete temp;
         cout<<"Element Deleted"<<endl;
      }
      void SearchKey(int k) 
	  {
         int hash_v = HashFunc(k);
         bool flag = false;
         HashTableEntry* temp = ht[hash_v];
         if (temp != NULL) {
            while (temp != NULL) {
               if (temp->k == k) {
                  flag = true;
               }
               if (flag) {
                  cout<<"Element found at key "<<k<<": ";
                  cout<<temp->v<<endl;
               }
               temp = temp->n;
            }
         }
         if (!flag)
            cout<<"No Element found at key "<<k<<endl;
      }
     
	  ~HashMapTable() 
	  {
         delete [] ht;
      }
};
int main() {
   HashMapTable hash;
   int k, v;
   int c;
      string line;
  int i=0;
  int v1=0;
  ifstream myfile ("dict.txt");
	if(myfile.is_open())
    {

    	while(i<2900)
    	{	 getline (myfile,line);
      
	  		hash.Insert(v1, line);
	  		
	  		if(i%2!=0 && i<100)
	  		{
	  			v1++;
	  	    }
	  	    else if(i>100 && i<300)
	  	    {
	  	         if(i%3==0)
				   {
				   		v1++;	
				   }	
	  	    	
	  	    }
	  	    else if(i>=300)
	  	    {
	  	         if(i%4==0)
				   {
				   		v1++;	
				   }	
	  	    	
	  	    }
	  	    
	  	    
	  	    i++;
	  		
    	}	
	}

  
  myfile.close();
     
   while (1) {
      cout<<"Enter 1 Search element from the key"<<endl;
      cout<<"Enter 2 Delete element at a key"<<endl;
      cout<<"Enter 3 Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      
           
         
      
      switch(c) {
        
         case 1:
            cout<<"Enter key of the element for search : ";
            cin>>k;
            hash.SearchKey(k);
         break;
         case 2:
            cout<<"Enter key of the element for delete element : ";
            cin>>k;
            hash.Remove(k);
         break;
         case 3:
            exit(1);
         default:
            cout<<"\nEnter correct Choice\n";
      }
   }
   return 0;
}
