#include <string>
#include <iostream>

struct Student {
private:
    std::string name;
    std::string group;
    int age;
    double *memory;

public:
    Student(std::string name, std::string group, int age) {
        this->name = name;
        this->group = group;
        this->age = age;

        memory = new double[100];
    }

    Student() {
        name = "Ivan";
        group = "ITB-15";
        age = 18;
    }

    ~Student() {
        std::cout << name << " Dismissed";

        delete[] memory;
    }

    void ageing() {
        ++age;
    }

    void print() const {
        std::cout << name << " " << group << " " << age << std::endl;
    }
};

int main() {
    Student student("Ivan", "ITB-15", 18);
    student.print();
    student.ageing();
    student.print();

//    delete student;
}