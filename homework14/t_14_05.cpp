#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

struct Student {
    std::string surname;
    int course;
    std::string group;
    std::vector<int> grades;


    double averageGrade() const {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (int grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }
};


std::vector<Student> readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Не вдалося відкрити файл " << filename << std::endl;
        return students;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Student student;
        std::string grade;

        std::getline(iss, student.surname, ',');
        iss >> student.course;
        iss.ignore(1, ',');
        std::getline(iss, student.group, ',');


        while (std::getline(iss, grade, ',')) {
            student.grades.push_back(std::stoi(grade));
        }

        students.push_back(student);
    }

    return students;
}


Student findWorstStudent(const std::vector<Student>& students) {
    Student worstStudent;
    double lowestAverage = std::numeric_limits<double>::max();

    for (const Student& student : students) {
        double avg = student.averageGrade();
        if (avg < lowestAverage) {
            lowestAverage = avg;
            worstStudent = student;
        }
    }

    return worstStudent;
}

int main() {
    // Ім'я файлу, куди будемо записувати дані про студентів
    std::string filename = "/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework14/students.txt";


    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Ivanov,2,CS-01,90,85,78\n";
        file << "Petrov,3,CS-02,70,65,60\n";
        file << "Sidorov,1,CS-01,88,92,79\n";
        file.close();
    }


    std::vector<Student> students = readStudentsFromFile(filename);

    if (!students.empty()) {

        Student worstStudent = findWorstStudent(students);
        std::cout << "Студент з найгіршою середньою оцінкою: " << worstStudent.surname << std::endl;
    } else {
        std::cout << "Немає даних про студентів." << std::endl;
    }

    return 0;
}
