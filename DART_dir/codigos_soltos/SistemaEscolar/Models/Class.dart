import 'Entity.dart';
import 'Course.dart';

class Class {

  String? className;
  String? classId;
  Professor? professor;
  List<Student>? students = [];
  List<Course>? courses = [];
  
  Class(String? className, String? classId) {
    this.className = className;
    this.classId = classId;
  }

  // Método pra controle de alunos

  String addStudent(Student student) {
    students!.add(student);
    return 'Student ${student.entityName} added to class $className';
  }

  String removeStudent(Student student) {
    students!.remove(student);
    return 'Student ${student.entityName} removed from class $className';
  }

  void listStudents() {
    print('Students in class $className:');
    for (var student in students!) {
      print('- ${student.entityName} (${student.entityId})');
    }
  }

  // Método pra controle de professores

  String asssignProfessor(Professor professor) {
    this.professor = professor;
    return 'Professor ${professor.entityName} assigned to class $className';
  }

  String verifyProfessor() {
    if (professor != null) {
      return 'Professor ${professor!.entityName} is assigned to class $className';
    } else {
      return 'No professor assigned to class $className';
    }
  }

  // Método pra controle de matérias
  
  String addCourse(Course course) {
    courses!.add(course);
    return 'Course ${course.courseName} added to class $className';
  }

  String removeCourse(Course course) {
    courses!.remove(course);
    return 'Course ${course.courseName} removed from class $className';
  }

  void listCourses() {
    print('Courses in class $className:');
    for (var course in courses!) {
      print('- ${course.courseName} (${course.courseId})');
    }
  }

}


// ============================================== //
