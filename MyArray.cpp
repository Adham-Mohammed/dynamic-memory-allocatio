#include "MyArray.h"
#include<iostream>
using namespace std;

template<class T>
MyArray<T>::MyArray() {
    size = 0;
    capacity = INITIAL_CAPACITY;
    data = new T[capacity];
}

template<class T>
MyArray<T>::MyArray(T *arr, int size) {
    this->size =size;
    capacity=INITIAL_CAPACITY;
    data = new T[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = arr[i];

    }
    if (size >= capacity){
        capacity *= 2;
        T *temp = new T[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data = temp;

    }
}

template<class T>
T MyArray<T>::get(int index) {
    return data[index];
}

template<class T>
void MyArray<T>::push(T element) {
    if (size == capacity){
        capacity *= 2;
        T *temp = new T[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data = temp;

    }

    data[size]=element;
    size++;
}

template<class T>
T MyArray<T>::pop() {
    T ret = data[size-1];
    if(size>0){
        size--;
        if(size<=capacity/4){
            capacity= capacity/2;
            T *temp = new T[capacity];
            for (int i = 0; i < size; ++i) {
                temp[i] = data[i];
            }
            delete []data;
            data = temp;

        }
    }
    else{
        return -1;
    }
    return ret;

}

template<class T>
void MyArray<T>::insert(int index, T element) {
    if(index==size){
        push(element);
    }
    else{
        for (int i = size-1; i>=index ; --i) {
            data[i+1]=data[i];
        }
        data[index]=element;
        ++size;
    };




}

template<class T>
T MyArray<T>::remove(int index) {
    T ret = data[index];
    if (index >=size || index < 0) {
        return -1;
    }
    else{
        for (int i = index; i < size-1; ++i) {
            data[i]=data[i+1];
        }
    }
    --size;
    if(size<=capacity/4){
        capacity= capacity/2;
        T *temp = new T[capacity];
        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete []data;
        data = temp;

    }
    return ret;


}

template<class T>
void MyArray<T>::print() {
    for (int i = 0; i < size; ++i) {
        cout<<data[i]<<' ';
    }
    cout<<endl;

}

template<class T>
int MyArray<T>::get_size() {
    return size;
}

template<class T>
 int MyArray<T>::get_capacity() {
    return capacity;
}

