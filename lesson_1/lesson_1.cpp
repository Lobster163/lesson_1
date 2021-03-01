
#include <iostream>
#include <cassert>
#include <cstdint>

class Power
{
    private:
        float a = 3.14f;
        float b = 1.14f;
    public:
        void setValue(float A, float B) {
            a = A;
            b = B;
        }
        void calculate() {
            std::cout << pow(a, b) << "\n";
        }
};


class RGBA
{
    private:
        uint8_t m_red = 0;
        uint8_t m_green = 0;
        uint8_t m_blue = 0;
        uint8_t m_alpha = 255;
    public:
        RGBA() {};
        RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
        void print() {
            std::cout << "red = " << (int)m_red << "\n";
            std::cout << "green = " << (int)m_green << "\n";
            std::cout << "blue = " << (int)m_blue << "\n";
            std::cout << "alpha = " << (int)m_alpha << "\n";
        }
};

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
                m_data[position--] = 0;
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
    std::cout << "p1:\n";
    Power power;
    power.calculate();
    power.setValue(2, 3);
    power.calculate();

    std::cout << "\np2:\n";
    RGBA rgba;
    rgba.print();
    std::cout << "\n";
    RGBA rgba2(255,128,200,50);
    rgba2.print();

    std::cout << "\np3:\n";
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