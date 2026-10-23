#include <iostream>
#include <string>

class Student{
    private:
       std::string studentName;
       int studentAge;
    public:
       
       //CONSTRUCTOR
       Student(std::string newName = "John Doe", int newAge=18){
        studentName = std::move(newName);
        studentAge = newAge;
        std::cout << "Constructor Called." <<std::endl;
       };

       //DECONSTRUCTOR
       ~Student(){
        std::cout << "Destructor Called." <<std::endl;
       }

       //COPY CONSTRUCTOR
       Student(const Student &copyStudent){
        std::cout <<"Copy Constructor Called." <<std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
       }

       //DISPLAY ATTRIBUTES
       void printDetails(){
        std::cout << this->studentName << " " << this->studentAge << std::endl;
       }
};

int main() {
const size_t j = 5;
Student studentList[j] = {};
std::string namesList[j] = {"Carlo", "Issa", "Sza", "Zimbabwe", "Cole"};
int ageList[j] = {15, 16, 18, 19, 16};
for(int i = 0; i < j; i++){ 

//loop A
Student *ptr = new Student(namesList[i], ageList[i]);
studentList[i] = *ptr;

}
for(int i = 0; i < j; i++){ 

//loop B
studentList[i].printDetails();
}
return 0;
}