/*

Classes pedidas: Aluno, Professor, Disciplina, Turma, Notas, Curso

*/


// Implementado a partir de Models 

import 'Models/Entity.dart';
import 'Models/Course.dart';
import 'Models/Class.dart';
import 'Models/Grade.dart';

void main() {
  // Criando instâncias de Professor, Student, Course e Class
  Professor professor = Professor("Dr. Smith", "P001", "dr.smith", "Full-time");
  Student student1 = Student("Alice Johnson", "S001", "alice.johnson");
  Student student2 = Student("Bob Brown", "S002", "bob.brown");
  Course course1 = Course("Mathematics", "C001", "An introduction to mathematical concepts.");
  Course course2 = Course("Physics", "C002", "Fundamentals of physics and its applications.");
  Class class1 = Class("Class A", "CL001");

  // Atribuindo professor à turma
  print(class1.asssignProfessor(professor));
  print("\n");

  // Adicionando alunos à turma
  print(class1.addStudent(student1));
  print(class1.addStudent(student2));
  print("\n");

  // Listando alunos da turma
  class1.listStudents();
  print("\n");

  // Adicionando cursos à turma
  print(class1.addCourse(course1));
  print(class1.addCourse(course2));
  print("\n");

  // notas dos alunos por matéria
  student1.addGrade(Grade(course1, 85.0));
  student1.addGrade(Grade(course2, 90.0));
  student2.addGrade(Grade(course1, 78.0));

  // Listando notas dos alunos
  student1.listGrades();
  print("\n");
  student2.listGrades();
  print("\n");

  // Verificando professor da turma
  print(class1.verifyProfessor());
  print("\n");

  // Informações do professor
  print('Professor Name: ${professor.entityName}');
  print('Professor ID: ${professor.entityId}');
  print('Professor Email: ${professor.professorEmail}');
  print('professor Profit: ${professor.professorProfit}');
  print("\n");

  // Listando informações da turma
  print('Class Name: ${class1.className}');
  print('Class ID: ${class1.classId}');
  print('Professor: ${class1.professor?.entityName}');
  print("\n");
  
  print('Courses in class:');
  for (var course in class1.courses!) {
    print('- ${course.courseName} (${course.courseId})');
  }
  print("\n");

  // Listando todos os emails
  print('Emails:');
  print('Professor Email: ${professor.professorEmail}');
  print('Student 1 Email: ${student1.studentEmail}');
  print('Student 2 Email: ${student2.studentEmail}');
}
