// Problem Link - https://www.interviewbit.com/problems/min-stack/
/* Problem solution 
          || 
          \/
vector<int> vecy;
vector<int> miny;
MinStack::MinStack() {
    vecy = vector<int>();
}

void MinStack::push(int x) {
    if(vecy.size() == 0) miny.push_back(x);
    else miny.push_back(miny[miny.size()-1]<x?miny[miny.size()-1]:x) ;
    vecy.push_back(x);
}
void MinStack::pop() {
    if(vecy.size() == 0) ;
    else{
        vecy.pop_back();
        miny.pop_back();
    }
}

int MinStack::top() {
    if(vecy.size() == 0) return -1;
    else return vecy[vecy.size()-1];

}

int MinStack::getMin() {
    if(vecy.size() == 0) return -1;
    else return miny[miny.size()-1];
}

*/