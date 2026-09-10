import 'Grade.dart';

class Entity {
  String? entityName;
  String? entityId;

  Entity(String? entityName, String? entityId) {
    this.entityName = entityName;
    this.entityId = entityId;
  }

  void displayEntityInfo() {
    print('Entity Name: $entityName');
    print('Entity ID: $entityId');
  }
}

// ============================================== //

class Professor extends Entity {
  String? professorEmail;
  String? professorProfit;

  Professor(String? entityName, String? entityId, String? professorEmail, String? professorProfit) : super(entityName, entityId) {
    this.professorEmail = professorEmail! + "@professor.ifpi.edu";
    this.professorProfit = professorProfit;
  }
}

class Student extends Entity {
  String? studentEmail;
  List<Grade>? studentGrade = [];

  Student(String? entityName, String? entityId, String? studentEmail) : super(entityName, entityId) {
    this.studentEmail = studentEmail! + "@student.ifpi.edu";
  }

  String addGrade(Grade grade) {
    studentGrade!.add(grade);
    return 'Grade ${grade.gradeValue} added for course ${grade.course?.courseName}';
  }

  void listGrades() {
    print('Grades for student $entityName:');
    for (var grade in studentGrade!) {
      print('- ${grade.course?.courseName}: ${grade.gradeValue}');
    }
  }
}
