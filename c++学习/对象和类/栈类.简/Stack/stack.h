#ifndef STACK_H
#define STACK_H
typedef struct customer{
    char fulname[31];
    double payment;
}Item;

class Stack
{
private:
    enum {MAX=100};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty()const;
    bool isfull() const;
    bool push (const Item & item);
    bool pop(Item & item);
};

#endif // STACK_H
