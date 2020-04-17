#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 template <typename T>
 class vector {
 public:
 typedef T* Iterator; //创建以T为类型的指针“当作数组”。
 Iterator iterator;
 size_t size;
 size_t capacity;
 
 vector() : iterator(NULL), size(0), capacity(0) {}
 
 vector(size_t _size, size_t _capacity, T _val) : capacity(_capacity), size(_size), iterator(new T[_size]){
 for(int i = 0; i < _size; ++i)
 this -> iterator[i] = _val;
 }
 
 vector(const vector& v) {
 this -> size = v.size;
 this -> iterator = new T[this -> size];
 this -> capacity = v.capacity;
 memcpy(this -> iterator, v.iterator, this -> size * sizeof(T));
 }
 
 ~vector(){
 if(iterator) delete[] iterator;
 }
 
 T& operator [](const int&);
 void operator =(const vector<T>&);
 void push_back(const T&);
 size_t vectorsize();
 };
 
 template <typename T>
 void vector<T>:: push_back(const T& data) {
 if(!iterator) {
 capacity = 66;
 size = 0;
 Iterator iterator = new T[capacity];
 }
 if(size == capacity) {
 Iterator new_iterator = new T[capacity * 2];
 memcpy(new_iterator, iterator, this -> size * sizeof(T));
 capacity = capacity * 2;
 delete[] iterator;
 iterator = new_iterator;
 }
 this -> iterator[size++] = data;
 }
 
 template <typename T>
 void vector<T>:: operator =(const vector<T>& v) {
 if(this -> iterator) {
 delete[] iterator;
 this -> capacity = 0;
 this -> size = 0;
 this -> iterator = NULL;
 }
 //把原来的信息统统删除！
 this -> capacity = v.capacity;
 this -> size = v.size;
 this -> iterator = new T[this -> capacity];
 memcpy(this -> iterator, v.iterator, this -> size * sizeof(T));
 }
 
 template <typename T>
 T& vector<T>:: operator [](const int& index) {
 return (index > 0 && index < size) ? iterator[index] : iterator[-1];
 }
 
 template <typename T>
 size_t vector<T>:: vectorsize() {return size;}
 */
template <typename T> //尝试两个快排版本，时间复杂度为O(nlogn)
void quicksort1(T data[], int left, int right) {
    if(left >= right) return;
    int i, j, pivot;
    i = left;
    j = right;
    pivot = data[left];
    while (i < j) {
        while (data[j] >= pivot && i < j) j--;
        while (data[i] <= pivot && i < j) i++;
        if (i < j) swap(data[i], data[j]);//找到了就swap掉。
    }
    data[left] = data[i];
    data[i] = pivot;
    quicksort1(data, left, i - 1);//递归左边
    quicksort1(data, i + 1, right);//递归右边
}

template <typename T>
void quicksort2(T data[], int first, int last) {
    int lower = first + 1;
    int upper = last;
    swap(data[first], data[(first + last) / 2]);
    T bound = data[first];
    while (lower <= upper)
    {
        while (data[lower] > bound)
            lower++;
        while (data[upper] < bound)
            upper--;
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else lower++;
    }
    swap(data[upper], data[first]);
    if (first < upper - 1)
        quicksort2(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort2(data, upper + 1, last);
}

template <typename T>
void sort(T data[], bool f, int size) {
    f ? quicksort1(data, 0, size - 1) : quicksort2(data, 0, size - 1);
}

template <typename T>
T max(T data[], int size) {
    T ans = data[0];
    for(int i = 0; i < size; i++) ans = std::max(ans, data[i]);
    return ans;
}

template <typename T>
T min(T data[], int size) {
    T ans = data[0];
    for(int i = 0; i < size; i++) ans = std::min(ans, data[i]);
    return ans;
}

template <typename T>
void print(T data[], int size){
    for(int i = 0; i < size; i++) cout<<data[i]<<" ";
}

template <typename T>
class Node {
public:
    T val;
    Node* next;
    
    Node() : val(), next(NULL) {}
    Node(T _val) : val(_val), next(NULL) {}
    ~Node(){}
};

template <typename T>
void insert(Node<T>* head, T _val) {
    Node<T>* p = new Node<T>(0);
    p -> next = head;
    while(p) {
        if (p -> val <= _val && _val <= p -> next -> val) {
            Node<T>* tmp = new Node<T>(_val);
            tmp -> next = p -> next;
            p -> next = tmp;
        }
        if (_val > p -> next -> val) {
            Node<T>* tmp = new Node<T>(_val);
            p -> next -> next = tmp;
        }
        p = p -> next;
    }
}

template <typename T>
void remove(Node<T>* head, T _val) {
    Node<T>* p = new Node<T>;
    p -> next = head;
    while(p -> next) {
        if(p -> val == _val) {
            if(p -> next) {
                p -> next = p -> next -> next;
                break;
            } else {
                p -> next = NULL;
                break;
            }
        } 
        p = p -> next;
    }
    
}

template <typename T>
Node<T>* search(Node<T>*& head, T _val) {
    Node<T>* p = new Node<T>(0);
    p -> next = head;
    while(p) {
        if(p -> val == _val)
            return p;
        p = p -> next;
    }
}

template <typename T>
void print(Node<T>* head) {
    if(head -> val == 0) head = head -> next;
    while(head) {
        cout << head -> val << " ";
        head = head -> next;
    }
}

template <typename T>
class Stack {
public:
    int size;
    Node<T> *head;
    Stack() : size(0), head(new Node<T>) {}
    
    void push(T);
    void pop(void);
    T top(void);
    bool empty(void);
};

template<typename T>
void Stack<T> :: push(T val) {
    Node<T>* new_head = new Node<T>(val);
    new_head -> next = head -> next; //采取头插法。
    head -> next = new_head;
    size++;
}

template<typename T>
void Stack<T> :: pop(void) {
    if (head -> next) {
        delete head -> next;
        head -> next = head -> next -> next;
        size--;
    } else {
        cout << "No elements in stack" << endl;
    }
}

template <typename T>
T Stack<T> :: top(void) {
    return head -> next -> val;
}

template <typename T>
bool Stack<T> :: empty(void) {
    return size == 0;
}

int main(int argc, const char* argv[]) {
    int size;
    cin >> size;
    bool flag;
    cin >> flag;
    int testcase1[size];
    double testcase2[size];
    char testcase3[size];
    Stack<int> test1;
    Stack<double> test2;
    Stack<char> test3;
    srand(time(0));
    for(int i = 0; i < size; ++i) {
        int a = rand() % 100 + 1;
        double b = rand() % 100 + 1;
        char c = 'a' + rand() % 26 + 0;
        testcase1[i] = a;
        testcase2[i] = b;
        testcase3[i] = c;
        test1.push(a);
        test2.push(b);
        test3.push(c);
    }
    cout<<"第一个数组的最大值为："<<max(testcase1, size) << "，最小值为：" << min(testcase1, size)<<endl;
    cout<<"第二个数组的最大值为："<<max(testcase2, size) << "，最小值为：" << min(testcase2, size)<<endl;
    cout<<"第三个数组的最大值为："<<max(testcase3, size) << "，最小值为：" << min(testcase3, size)<<endl;
    cout << endl;
    cout<<"排序前："<<endl;
    print(testcase1, size);
    cout<<endl;
    print(testcase2, size);
    cout<<endl;
    print(testcase3, size);
    cout<<endl;
    sort(testcase1, flag, size);
    sort(testcase2, flag, size);
    sort(testcase3, flag, size);
    cout << endl;
    cout<<"排序后："<<endl;
    print(testcase1, size);
    cout<<endl;
    print(testcase2, size);
    cout<<endl;
    print(testcase3, size);
    cout<<endl;
    
    cout << endl;
    cout << "三个栈的内容如下：" << endl;
    print(test1.head);
    cout << endl;
    print(test2.head);
    cout << endl;
    print(test3.head);
    cout << endl;

    cout << endl;
    cout << "各删去一个元素：" << endl;
    remove(test1.head, testcase1[1]);
    remove(test2.head, testcase2[2]);
    remove(test3.head, testcase3[3]);
    print(test1.head);
    cout << endl;
    print(test2.head);
    cout << endl;
    print(test3.head);
    cout << endl;

    cout << "各弹出一个栈顶元素：" << endl;
    test1.pop();
    test2.pop();
    test3.pop();
    print(test1.head);
    cout << endl;
    print(test2.head);
    cout << endl;
    print(test3.head);
    cout << endl;

    cout << test1.top();
    return 0;
}