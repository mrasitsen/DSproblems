#include <iostream>
#include <string>
#include <map>

using namespace std;

// 2020-21 first semester Data Structures Class Week 1 Assigment 2

void operate(map<int, string> &LIST1, map<int, string> &LIST2){

	map<int, string> result;

	if (LIST2.empty()){
		cout<<"the LIST2 is NULL.\n";
	}
	else{

		for (auto const& elementL2 : LIST2){
			bool flag = false;
			for (auto const& elementL1 : LIST1){
				if (elementL2.first == elementL1.first && elementL1.second == elementL2.second){
					flag = true;
					break;
				}
			}
			if (!flag){
				result.insert(pair<int, string>(elementL2.first, elementL2.second));
			}
		}

		if (result.empty()){
		cout<<"the records of LIST2 are all in the LIST1.\n";
		}
		else{
			for(auto const& elementLeft : result){
				cout<<elementLeft.first<<" "
					<<elementLeft.second
					<<" is not in LIST1.\n";
			}
		}
		
	}
	
}

int main(){

	string name;
	int number;

	map<int, string> LIST1;
	map<int, string> LIST2;

	int l1, l2;

	cin>>l1;
	for (int i = 0; i < l1; ++i){ // geting input from user for LIST1
		cin>>number>>name;
		LIST1.insert(pair<int, string>(number, name));
	}

	cin>>l2;
	for (int i = 0; i < l2; ++i){ // geting input from user for LIST1
		cin>>number>>name;
		LIST2.insert(pair<int, string>(number, name));
	}

	operate(LIST1, LIST2);

	return 0;
}