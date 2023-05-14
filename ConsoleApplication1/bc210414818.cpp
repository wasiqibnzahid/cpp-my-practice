#include <iostream>
#include <cstring>

using namespace std;
class Student
{
public:
	string name;
	int age;
	int studentId;
	Student()
	{
		name = "";
		age = 0;
		studentId = 0;
	};
	Student(string name_, int age_, int studentId_)
	{
		name = name_;
		age = age_;
		studentId = studentId_;
	};

	Student(const Student& oldStudent)
		: name(oldStudent.name),
		age(oldStudent.age),
		studentId(oldStudent.studentId)
	{}
	void SetName(string &str)
	{
		name = str;
	};
	string GetName()
	{
		return name;
	};
	int GetAge()
	{
		return age;
	};
	int GetStudentId()
	{
		return studentId;
	};
	void SetAge(int &age)
	{
		this->age = age;
	};
	void setStudentId(int &studentId)
	{
		this->studentId = studentId;
	};
	Student &operator=(const Student &newStudent)
	{
		if (this != &newStudent)
		{
			name = newStudent.name;
			age = newStudent.age;
			studentId = newStudent.studentId;
		};
		return *this;
	}
};

int main()
{
	Student s1("John Doe", 20, 1234);
	Student s2 = Student(s1); // Shallow copy

	s2.age = 21; // Modify age in shallow copy

	cout << "s1 age: " << s1.age << endl; // Should print 21 because shallow copy modified s1's age variable
	cout << "s2 age: " << s2.age << endl; // Should print 21 because s2's age variable was modified

	return 0;
}

// #include <iostream>
// #include <string>
//
// class MyClass {
// public:
//     // Default constructor
//     MyClass() : str_(nullptr) {}
//
//     // Constructor that makes a deep copy of the input object
//     MyClass(const MyClass& other) {
//         if (other.str_ != nullptr) {
//             str_ = new std::string(*other.str_);
//         }
//         else {
//             str_ = nullptr;
//         }
//     }
//
//     // Constructor that makes a shallow copy of the input object
//     MyClass(MyClass* other_ptr) {
//         str_ = other_ptr->str_;
//     }
//
//     // Destructor
//     ~MyClass() {
//         delete str_;
//     }
//
//     // Setter function for the string
//     void SetString(const std::string& str) {
//         if (str_ != nullptr) {
//             *str_ = str;
//         }
//         else {
//             str_ = new std::string(str);
//         }
//     }
//
//     // Getter function for the string
//     std::string GetString() const {
//         return (str_ != nullptr) ? *str_ : "";
//     }
//
// private:
//     std::string* str_;
// };
//
// int main() {
//     // Create an object with a string
//     MyClass obj1;
//     obj1.SetString("Hello, world!");
//
//     // Create an object using the deep copy constructor
//     MyClass obj2(obj1);
//
//     // Create an object using the shallow copy constructor
//     MyClass obj3(&obj1);
//
//     // Print the strings stored in each object
//     std::cout << "obj1: " << obj1.GetString() << std::endl;
//     std::cout << "obj2: " << obj2.GetString() << std::endl;
//     std::cout << "obj3: " << obj3.GetString() << std::endl;
//
//     // Modify the string in obj1
//     obj1.SetString("Goodbye, world!");
//
//     // Print the strings stored in each object again
//     std::cout << "obj1: " << obj1.GetString() << std::endl;
//     std::cout << "obj2: " << obj2.GetString() << std::endl;
//     std::cout << "obj3: " << obj3.GetString() << std::endl;
//
//     return 0;
// }