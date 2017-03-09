#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size, length;
    Type *data; 
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    void insert(int loc, int value) {
        if (loc < 0 || loc > length) {
            return;
        }
        if (length >= size) {
        //  return false;
        expand();
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return ;
    }
    void expand() {
        Type *old_data = data;
        size = size * 2;
        data = new Type[size];
        for (int i = 0; i < length; i++){
            data[i] = old_data[i];
        } 
        delete[] old_data; 
    }
	int pan (int x, int y){
        if(data[x] == y)
            return 1;
        else 
            return 0;
    }
};
int main() {
	Vector<int> a(5);
    int sum =0,n,x,y,flag =5;
    cin >> n;
    for (int i =0; i< n; i++){
        cin >> x >> y;
     	a.insert(x,y);
    	if(a.pan(x,y) )  
			sum ++;
        if (a.pan(x,y))
            cout << "success" << endl;
        else 
            cout << "failed" << endl;	
    	if (a.pan(x,y) && sum % flag == 0){
        	cout << "expand" <<endl;
			flag = flag * 2;
		}
    }    
    return 0;
}
