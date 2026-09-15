class DynamicArray {
public:

    int * MyArray= nullptr ; 
    int size =0 ; 
    int capacity = 0; 
    DynamicArray(int capacity) {
        if (capacity > 0){
            
            MyArray = new int [capacity]; 
            this -> capacity = capacity ;  

        }
    }

    int get(int i) {
        return MyArray[i] ; 

    }

    void set(int i, int n) {
        if(MyArray !=nullptr)
        MyArray[i] = n ; 

    }

    void pushback(int n) {
        if (capacity == size ){
            resize() ;  
        }
        MyArray [size] = n ; 
        ++size ; 

    }

    int popback() {
        size -- ; 
        return MyArray[size]; 
    }

    void resize() {
       int newCapacity = this->capacity * 2 ; 
       int *newArray  = new int [newCapacity]; 
        for (int i = 0 ; i < size ; i++ ){
            newArray[i] = MyArray[i]; 
        }
        delete[] MyArray ; 
        MyArray = newArray ;  
        this -> capacity = newCapacity ;
    }

    int getSize() {
        return size; 

    }

    int getCapacity() {
        return capacity ; 
    }
};
