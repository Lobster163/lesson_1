
#include <iostream>
#include <cassert>

class Stack {
    private: 
        int m_size;
        int* m_data;
        int position;
    public:
        Stack(int size){
            assert(size > 0);
            m_size = size;
            position = -1;
            m_data = new int[size];
        }
        ~Stack() {
            delete[] m_data;
        }

        bool push(int value){ 
            if (position >= m_size)
                return false;
            m_data[++position] = value;
            return true;
        }
        int pop(){ 
            if (position <= 0){
                std::cout << "Stack is null\n";
                return -1;
            }
            else{
                int result = m_data[position];
                m_data[position] = 0;
                position--;
                return result;
            }

        }
        void print() { 
            for (int i = 0; i < m_size; ++i)              
                std::cout << m_data[i] << " ";
            std::cout << "\n";
        }
        void reset() {
            for (int i = 0; i < m_size; ++i)
                m_data[i] = 0;
            position = -1;
        }

};

int main()
{
    Stack stack(10);
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

}