#include <iostream>
#include "calc.h"
#include "stddef.h"
#include <cmath>
using namespace std;

Calc::Calc(int values): storedExpressions(new string[values]),stored(0){
}
Calc::Calc(const Calc &rhs){
  if(storedExpressions != nullptr){
    storedExpressions = new string[rhs.stored];
  }
}
Calc::~Calc(){
  delete[] storedExpressions;
  storedExpressions = nullptr;
  stored =0;
}
const Calc &Calc:: operator=(const Calc & rhs){
  if(this != &rhs){
    Calc temp (rhs);
    swap(storedExpressions,temp.storedExpressions);
    swap(stored,temp.stored);
  }
  return *this;
}

double Calc::process(string userInput,double prevValue){
  string cleansedString = "";

  for(size_t i=0; i < userInput.size();++i){
    if(userInput[i] == '=' || userInput[i]== ' ' || userInput[i]=='(' || userInput[i]== ')'){ 
    }else{
      cleansedString += userInput[i];
    }
  }
  double value = stod(cleansedString.substr(1,cleansedString.length()-1));
  if(cleansedString[0]== '^'){
    return pow(prevValue,value);
  }
  else if(cleansedString[0]=='*' || cleansedString[0]=='/'){
    if(cleansedString[0]== '*'){
      return prevValue * value;
    }
    else{
      if(value==0){
        exit(0);
      }
      else{
        return prevValue/value;
      }
    }
  }
  else if(cleansedString[0]=='-' || cleansedString[0]=='+'){
    if(cleansedString[0]=='-'){
      return prevValue - value;
    }
    else{
      return prevValue+ value;
    }
  }
  else{
    cout<<"ERROR:Must start with operator"<<endl;
  }
}
void Calc::print(){
  cout<<"You have "<<stored<<"expressions stored:";
  for(size_t i =0;i<stored;++i){
    cout<<"Expression "<<i+1<<":\n";
    cout<<storedExpressions[i]<<endl;
  }
}
void Calc::setStored(size_t newStored){
  stored = newStored;
}
size_t Calc::getStored(){
   
}