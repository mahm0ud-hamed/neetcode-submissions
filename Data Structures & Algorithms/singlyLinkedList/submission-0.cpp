struct Node {
    int value;
    Node* next;
};
class LinkedList {
   private:
    Node* head;
    Node* tail;
    int size;

   public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int get(int index) {
        Node * current = head; 
        if( nullptr == head || index < 0 || index >= size ){
            return -1 ; 
        }
        for (int i =0 ; i < index ; i++){
            current = current -> next ; 
        }
        return current -> value ; 
    }

    void insertHead(int val) {
        Node * insert = new Node ; 
        insert -> value = val ; 
        insert -> next = head ;// if list empty = null , if not = old head ; 
        head = insert ;
        // list is not exist 
        if (0 == size) {
            tail = insert ; 
        }
        size ++ ; 
    }

    void insertTail(int val) {
        Node * insert = new Node ; 
        insert -> value = val; 
        if(0 == size){
            head = insert; 
            tail = insert ; 
        }else {
            tail -> next = insert ; 
            tail = insert ; 
        }
        size ++ ; 

    }

    bool remove(int index) {
        Node * remove = head ; 
        Node * removePrv = head ;
        if( 0 == size || index < 0 || index >=size){
            return false ; 
        }
        if (0 == index){
            head = head->next ; 
            delete remove ;  
            --size ; 
            if(0 == size ){
                tail = head ; 
            }
        }else {
            for (int i =0 ; i < index ; i++){
                removePrv = remove; 
                remove = remove -> next ; 
            }
            if(remove == tail){
                removePrv -> next = nullptr ; 
                delete tail ; 
                tail = removePrv ; 
            }else{
                removePrv -> next = remove -> next ; 
                delete remove ; 
            }
            --size ; 
        }   
        return true ;  
    }

    vector<int> getValues() {
        std::vector<int> toReturn; 
        Node * valueCollector = head ; 
        for (int i = 0 ; i < size ; i++){
            toReturn.push_back(valueCollector->value); 
            valueCollector = valueCollector -> next ; 
        }
        return toReturn ; 
    }
};
