#include <iostream>
#include <cstdlib>

class Stack {

    private:
    int* stack;
    int size;
    int top;

    public:
    Stack(int size) {
        this->size = size;
        stack = (int*) malloc(this->size * sizeof(int));
        this->top = -1;
    }

    void push(int elm) {
        if(this->top < this->size - 1) {
            this->stack[++top] = elm;
        } else {
            std::cout << "Stack overflow! No more elements allowed \n";
        }
    }

    int pop() {
        if(this->top == -1) {
            std::cout << "Stack is empty!, Can't popped out an element \n";
            return 0;
        } else {
            int popedElm = this->stack[this->top--];
            return popedElm;
        }
    }

    void print() {
        std::cout << "Elements of stack, ";
        std::cout << "Top: " << this->stack[this->top] << "\n";
        for(int i=0; i <= this->top; i++) {
            std::cout << this->stack[i] << ", ";
        }
        std::cout << "\n";

    }

};

int main() {

    Stack stack(10);
    stack.push(2);
    stack.push(13);
    stack.print();

    std::cout << "POP: " << stack.pop() << "\n";
    stack.print();

    stack.push(5);
    stack.push(21);
    stack.push(17);
    stack.push(15);
    stack.push(3);
    stack.print();

    std::cout << "POP: " << stack.pop() << "\n";
    stack.print();

    stack.push(5);
    stack.push(11);
    stack.push(9);
    stack.push(19);
    stack.print();

    std::cout << "POP: " << stack.pop() << "\n";
    stack.print();

    stack.push(20);
    stack.print();
    std::cout << "\n\n\n\n\n\n\n\n\n";

}