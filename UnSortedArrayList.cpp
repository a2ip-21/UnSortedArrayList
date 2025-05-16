#include <iostream>
using namespace std;

const int MAX_SIZE = 500;

template <class T>
class UnSortedArrayList {
    T items[MAX_SIZE];
    int length;
    int currentPos;
public:
    UnSortedArrayList() {
        length = 0;
        currentPos = -1;
    }

    bool IsFull() const {
        return length >= MAX_SIZE;
    }

    bool IsEmpty() {
        return length == 0;
    }

    void InsertItem(T item) {
        if (IsFull()) {
            cout << "List is full!!" << endl;
            return;
        }

        items[length++] = item;
    }

    void DeleteItem(T item){
        if (IsEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }

        int location = 0;
        while (location < length && items[location] != item) {
            location++;
        }

        if (location < length) {
            items[location] = items[--length];
        }
    }

    void RetrieveItem(T &item, bool &found){
        found = false;

        for (int i = 0; i < length; i++) {
            if (items[i] == item) {
                item = items[i];
                found = true;
                break;
            }
        }
    }

    void MakeEmpty() {
        length = 0;
    }

    bool IsLastItem() {
        return currentPos >= (length - 1);
    }

    void GetNextItem(T &item){
        if (IsLastItem()) {
            cout << "No more items left!" << endl;
            return;
        }

        item = items[++currentPos];
    }

    void ResetList() {
        currentPos = -1;
    }

        void Display() {
        ResetList();
        T item;
        cout << "[ ";
        while (!IsLastItem()) {
            GetNextItem(item);
            cout << item << " ";
        }
        cout << "]";
    }

    int Sum() {
        int result = 0;
        for (int i = 0; i < length; i++) {
            result += items[i];
        }
        return result;
    }

};

template <class T>
void MergeList(UnSortedArrayList<T> list1, UnSortedArrayList<T> list2, UnSortedArrayList<T> &result){
    list1.ResetList();
    T item;
    while (!list1.IsLastItem()) {
        list1.GetNextItem(item);
        result.InsertItem(item);
    }
    
    list2.ResetList();
    T item1;
    while (!list2.IsLastItem()) {
        list2.GetNextItem(item1);
        result.InsertItem(item1);
    }
}

template <class T>
void SplitLists (
    UnSortedArrayList<T> list, 
    UnSortedArrayList<T> &list1, 
    UnSortedArrayList<T> &list2, 
    T target 
    ){
    list.ResetList();
    T currentItem;
    while (!list.IsLastItem()) {
        list.GetNextItem(currentItem);
        if (currentItem <= target) {
            list1.InsertItem(currentItem);
        }
        else
            list2.InsertItem(currentItem);
    }
}

int main()
{
    UnSortedArrayList<int> myList;
    myList.InsertItem(5);
    myList.InsertItem(4);
    myList.InsertItem(8);
    myList.InsertItem(9);
    myList.InsertItem(10);
    myList.Display();
    cout << endl;
    cout << "Sum = " << myList.Sum();
    cout << endl;
    myList.DeleteItem(4);
    myList.Display();
    cout << endl;

    UnSortedArrayList<int> myList2;
    myList2.InsertItem(50);
    myList2.InsertItem(60);
    myList2.InsertItem(70);
    myList2.InsertItem(80);

    UnSortedArrayList<int> result;

    MergeList(myList, myList2, result);

    cout << endl;
    cout << "After merge: ";
    result.Display();

}