#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 2020-21 first semester Data Structures Class Week 1 Assigment 1

class circle{
public:
	int num;
	circle *next;
	circle *last;
public:
	circle();
	void showAll();
	void addElement(int number);
	int deleteElement(int number);
	~circle();
};

circle::circle(){
	next = NULL;
	last = this;
}

circle::~circle(){

}


void circle::addElement(int number){ //tum elemanlar ayni surece tabi
	circle *newElement = new circle() ;
	circle *current = last;
	current->next = newElement;
	newElement->num = number;
	newElement->next = next;
	last = newElement;
}

int circle::deleteElement(int number){
	if (next == NULL){
		cout<<"List is empty\n";
		return 0;
	}
	else{
		circle *current = next;
		if (next->num == number){
			if (next == current->next){
				int ans = current->num;
				delete current;
				last = NULL;
				next = NULL;
				return ans;

			}else{
				next = current->next;
				last->next = current->next;
				int ans = current->num;
				delete current;
				return ans;
			}
			
		}
		else{
			circle *current = next;
			circle *prev;
			while(current->num != number){
				prev = current;
				current = current->next;
			}
			if (current == last){
				last = prev;
			}
			prev->next = current->next;
			int ans = current->num;
			delete current;
			return ans;
		}
	}
}



void circle::showAll(){
	if (next == NULL){
		cout<<"list is empty\n";
	}
	else{
		circle *current = next;
		while(true){
			cout<<current->num<<" ";
			if (current == last){
				cout<<"\n";
				break;
			}
			current = current->next;			
		}
	}
}

void operate(circle c, int k, int m){
	circle *start = c.next;
	for (int i = 1; i < k; ++i){
		start = start->next;
	}
	int count = 0;
	while(c.next != NULL){
		for (int i = 1; i < m; ++i){
			start = start->next;
		}
		int number = start->num;
		start = start->next;
		int deletedNumber = c.deleteElement(number);
		count++;
		cout<<deletedNumber;
		if (c.next != NULL){
			if (count != 10){
				cout<<" ";}
			else{
				count = 0;
				cout<<"\n";
			}
		}
	}
}

void test(int n, int k, int m){

	if (n<1 || k<1 || m<1){
		cout<<"n,m,k must bigger than 0.\n";
	}
	else if(k>n){
		cout<<"k should not bigger than n.\n";
	}
	else{
		circle firstCircle;
		for (int i = 1; i <= n; ++i){
			firstCircle.addElement(i);
		}
		operate(firstCircle, k, m);
		cout<<"\n";
	}
}

int main(){
    string str;
    cin>>str;
  
    vector<int> v; 
  
    stringstream ss(str); 
  
    for (int i; ss >> i;) { 
        v.push_back(i); 
        if (ss.peek() == ',') 
            ss.ignore(); 
    } 
  
    int n = v[0];
    int k = v[1];
    int m = v[2];
        
	test(n, k, m);

	return 0;
    
}




