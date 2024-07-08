#include <iostream>
#include <string>
#include <typeinfo>

enum DataType {
    INT,
    DOUBLE,
    CHAR,
    UNKNOWN
};

class PtrArray {
private:
    void** arr;
    DataType* types;
    int size;

public:
    PtrArray(int sz) : size(sz) {
        arr = new void*[size];
        types = new DataType[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = nullptr;
            types[i] = UNKNOWN;
        }
    }

    ~PtrArray() {
        for (int i = 0; i < size; ++i) {
            delElem(i);
        }
        delete[] arr;
        delete[] types;
    }

    template<typename T>
    void set(int idx, T val) {
        if (idx >= 0 && idx < size) {
            delElem(idx);
            arr[idx] = new T(val);
            types[idx] = getType<T>();
        }
    }

    template<typename T>
    T get(int idx) const {
        if (idx >= 0 && idx < size && types[idx] == getType<T>()) {
            return *(static_cast<T*>(arr[idx]));
        }
        throw std::runtime_error("Invalid index or type mismatch.");
    }

    int getSize() const {
        return size;
    }

    DataType getType(int idx) const {
        if (idx >= 0 && idx < size) {
            return types[idx];
        }
        return UNKNOWN;
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << "Index " << i << ": ";
            switch (types[i]) {
                case INT:
                    std::cout << "int, value: " << get<int>(i) << std::endl;
                    break;
                case DOUBLE:
                    std::cout << "double, value: " << get<double>(i) << std::endl;
                    break;
                case CHAR:
                    std::cout << "char, value: " << get<char>(i) << std::endl;
                    break;
                default:
                    std::cout << "unknown, value: nullptr" << std::endl;
                    break;
            }
        }
    }

private:
    void delElem(int idx) {
        if (idx >= 0 && idx < size && arr[idx] != nullptr) {
            switch (types[idx]) {
                case INT:
                    delete static_cast<int*>(arr[idx]);
                    break;
                case DOUBLE:
                    delete static_cast<double*>(arr[idx]);
                    break;
                case CHAR:
                    delete static_cast<char*>(arr[idx]);
                    break;
                default:
                    break;
            }
            arr[idx] = nullptr;
            types[idx] = UNKNOWN;
        }
    }

    template<typename T>
    DataType getType() const {
        if (typeid(T) == typeid(int)) return INT;
        if (typeid(T) == typeid(double)) return DOUBLE;
        if (typeid(T) == typeid(char)) return CHAR;
        return UNKNOWN;
    }
};

int main() {
    PtrArray pa(5);
    pa.set(0, 42);
    pa.set(1, 3.14);
    pa.set(2, 'a');
    pa.print();

    try {
        std::cout << "Value at index 0 (int): " << pa.get<int>(0) << std::endl;
        std::cout << "Value at index 1 (double): " << pa.get<double>(1) << std::endl;
        std::cout << "Value at index 2 (char): " << pa.get<char>(2) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}